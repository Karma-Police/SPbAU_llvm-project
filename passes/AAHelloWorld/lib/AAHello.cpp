#include "AAHello.h"
#include <llvm/Analysis/TargetLibraryInfo.h>

using namespace std;

AliasResult AAHelloResult::alias(const MemoryLocation & , const MemoryLocation & ) {
    return MayAlias;
}


AAHelloResultWrapper::AAHelloResultWrapper() : ImmutablePass(ID) { }

AAHelloResultWrapper::~AAHelloResultWrapper() { }

const AAHelloResult & AAHelloResultWrapper::getResult() const {
    return *result;
}

AAHelloResult & AAHelloResultWrapper::getResult() {
    return *result;
}


bool AAHelloResultWrapper::doInitialization(Module &) {
    auto& tli = getAnalysis<TargetLibraryInfoWrapperPass>().getTLI();
    result.reset(new AAHelloResult(tli));
    return false;
}

bool AAHelloResultWrapper::doFinalization(Module &) {
    result.reset();
    return false;
}

void AAHelloResultWrapper::getAnalysisUsage(AnalysisUsage& au) const {
    au.addRequired<TargetLibraryInfoWrapperPass>();
    au.setPreservesAll();
}

char AAHelloResultWrapper::ID = 0;

static RegisterPass<AAHelloResultWrapper> aaHello("aaHello", "HelloWorld aa pass", false, true);

ImmutablePass * createAAHelloResultWrapper() {
    return new AAHelloResultWrapper();
}
