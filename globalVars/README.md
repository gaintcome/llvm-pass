## usage
	clang-6.0 -c globals.c -emit-llvm 
	opt-6.0 -load LLVMglobalvars.so -globalvars < globals.bc > /dev/null

