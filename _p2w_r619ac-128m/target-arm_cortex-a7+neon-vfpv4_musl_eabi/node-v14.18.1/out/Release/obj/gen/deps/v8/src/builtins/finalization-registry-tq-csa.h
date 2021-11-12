#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_FINALIZATION_REGISTRY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_FINALIZATION_REGISTRY_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<HeapObject> SplitOffTail_0(compiler::CodeAssemblerState* state_, TNode<WeakCell> p_weakCell);
TNode<HeapObject> PopClearedCell_0(compiler::CodeAssemblerState* state_, TNode<JSFinalizationRegistry> p_finalizationRegistry);
void FinalizationRegistryCleanupLoop_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFinalizationRegistry> p_finalizationRegistry, TNode<JSReceiver> p_callback);
TNode<JSFinalizationRegistry> Cast_JSFinalizationRegistry_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_FINALIZATION_REGISTRY_TQ_H_
