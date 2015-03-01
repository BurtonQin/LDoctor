#ifndef _H_SONGLH_LOOP
#define _H_SONGLH_LOOP


#include <string>
#include <set>
#include <map>

#include "llvm/Pass.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Support/PredIteratorCache.h"
#include "llvm/Transforms/Utils/SSAUpdater.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Analysis/Dominators.h"



using namespace llvm;
using namespace std;

namespace llvm_Commons {

bool blockDominatesAnExit(BasicBlock * BB, DominatorTree & DT, set<BasicBlock *> & setExitBlocks);

bool isExitBlock(BasicBlock *BB, const SmallVectorImpl<BasicBlock*> &ExitBlocks);

bool ProcessInstruction(Instruction *Inst, const SmallVectorImpl<BasicBlock*> &ExitBlocks, DominatorTree * DT, Loop * L, PredIteratorCache & PredCache);

BasicBlock * RewriteLoopExitBlock(Loop *L, BasicBlock *Exit, Pass * P);

void LoopSimplify(Loop * pLoop, Pass * P);

void ProcessPHICondition(PHINode * pPHI, set<Instruction *> & setInputInst);

void CollectExitCondition(Loop * pLoop, set<Instruction *> & setExitCond);

void CollectAllUsesInsideLoop(Value * pValue, Loop * pLoop, set<PHINode *> & UseOne, set<Instruction *> & UseOther);

bool UsedInsideLoop(Value * pValue, Loop * pLoop);

bool OnlyControlInLoop(Value * pValue, Loop * pLoop);

bool OnlyCompWithInteger(Value * pValue, Loop * pLoop);

}

#endif


