#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_PROMISE_ANY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_PROMISE_ANY_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);
TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);
TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementErrorsArraySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);
TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o);
TNode<Context> CreatePromiseAnyRejectElementContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseCapability> p_capability, TNode<NativeContext> p_nativeContext);
TNode<JSFunction> CreatePromiseAnyRejectElementFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_rejectElementContext, TNode<Smi> p_index, TNode<NativeContext> p_nativeContext);
TNode<Object> PerformPromiseAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iteratorRecord, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_resultCapability, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0);
TNode<JSObject> ConstructAggregateError_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_errorsArray);
TNode<BoolT> Is_JSPromise_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<BoolT> Is_Constructor_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_PROMISE_ANY_TQ_H_
