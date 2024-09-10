//
//  main.cpp
//  cppProject
//
//  Created by erica chen on 9/4/24.
//

#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

int main() {
    LLVMContext Context;
    Module *M = new Module("my cool jit", Context);

    // Create a function type and a function
    FunctionType *FT = FunctionType::get(Type::getInt32Ty(Context), false);
    Function *F = Function::Create(FT, Function::ExternalLinkage, "foo", M);

    // Verify the module
    std::string ErrStr;
    if (verifyModule(*M, &errs())) {
        errs() << "Module verification failed!\n";
        return 1;
    }

    // Print the module to stdout
    M->print(outs(), nullptr);
    return 0;
}
