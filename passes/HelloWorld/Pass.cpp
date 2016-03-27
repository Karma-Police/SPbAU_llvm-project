#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    struct Hello : FunctionPass {
        static char ID;
        Hello() : FunctionPass(ID) { }
        
        bool runOnFunction(Function &F) override {
            errs() << "Hello :";
            errs().write_escaped(F.getName()) << "\n";
            return false;
        }
    }; // End of struct Hello
} // End of namespace

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
