#ifndef AAHELLO_H
#define AAHELLO_H

#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Pass.h"
#include <memory.h>

using namespace llvm;

class AAHelloResult : public AAResultBase<AAHelloResult> {
    friend AAResultBase<AAHelloResult>;
public:
    AAHelloResult(const TargetLibraryInfo & tli) : AAResultBase(tli) { }
    AAHelloResult(const AAHelloResult &) = default;
    AAHelloResult(AAHelloResult &&) = default;

    bool invalidate(Function &, const PreservedAnalyses &) { return false; }
    AliasResult alias(const MemoryLocation & a, const MemoryLocation & b);
};

class AAHelloResultWrapper : public ImmutablePass {
    std::unique_ptr<AAHelloResult> result;
public:
    static char ID;

    AAHelloResultWrapper();
    ~AAHelloResultWrapper();

    const AAHelloResult & getResult() const;
    AAHelloResult & getResult();
    
    virtual bool doInitialization(Module& m) override;
    virtual bool doFinalization(Module& m) override;
    virtual void getAnalysisUsage(AnalysisUsage& au) const override;
};

ImmutablePass * createAAHelloResultWrapper();

#endif
