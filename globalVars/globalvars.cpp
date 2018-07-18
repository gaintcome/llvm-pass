#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Module.h"

using namespace llvm;

namespace {
  struct Globalvars : public ModulePass {
    static char ID;
    Globalvars() : ModulePass(ID) {}

    virtual bool runOnModule(Module &M) override {
	errs() << "In a Module called " << M.getName() << "!\n";
	  for (llvm::Module::global_iterator ii = M.global_begin(); ii != M.global_end(); ++ii) {
            if(ii->hasPrivateLinkage()){
	  	  errs() << "private global variable ::: " << ii->getName() << "\n";
		  continue;
	    }
	    if(ii->hasLocalLinkage()){
		errs() << "static global variable ::: " << ii->getName() << "\n";
		continue;
	    }
   	    errs() << "Global variable ::: " << ii->getName() << "\n";
	   } 
	return false;

    }// end of runOnModule
  }; // end of ModulePass
}

char Globalvars::ID = 0;
static RegisterPass<Globalvars> X("globalvars", "Get the list of global variables");

