#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_JS_AGGREGATE_ERROR_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_JS_AGGREGATE_ERROR_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<HeapObject> LoadJSAggregateErrorErrors_0(compiler::CodeAssemblerState* state_, TNode<JSAggregateError> p_o);
void StoreJSAggregateErrorErrors_0(compiler::CodeAssemblerState* state_, TNode<JSAggregateError> p_o, TNode<HeapObject> p_v);
TNode<JSAggregateError> Cast_JSAggregateError_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_JS_AGGREGATE_ERROR_TQ_H_
