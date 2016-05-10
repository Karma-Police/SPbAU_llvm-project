#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    struct Hello : FunctionPass {
        static char ID;
        int functionCount = 0;

        Hello() : FunctionPass(ID) { }

        bool doInitialization(Module &) override {
            errs() << "In doInitialization function!" << "\n";
            return false;
        }

        bool runOnFunction(Function &F) override {
            ++functionCount;
            errs() << "Hello :";
            errs().write_escaped(F.getName()) << "\n";
            return false;
        }

        bool doFinalization(Module &) override {
            errs() << "In doFinalisation function!" << "\n";
            return false;
        }

        void print(raw_ostream & O, const Module *) const {
            O << "Just saying hello to each function. Already said " << functionCount << " times\n";
        }
    }; // End of struct Hello
} // End of namespace

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
