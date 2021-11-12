#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-aggregate-error.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/torque/runtime-support.h"
#include "torque-generated/../../deps/v8/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-every-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-find-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-from-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-join-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-map-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-some-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/base-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/bigint-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/boolean-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/collections-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/cast-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/convert-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/console-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/data-view-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/finalization-registry-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/frames-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/ic-callable-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/ic-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/math-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/number-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-any-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-finally-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-race-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-reaction-job-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-then-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-jobs-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/reflect-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-html-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/symbol-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/wasm-tq-csa.h"
#include "torque-generated/../../deps/v8/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/arguments-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/cell-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/code-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/contexts-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/data-handler-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/foreign-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/free-space-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/heap-number-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/heap-object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-aggregate-error-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-collection-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-generator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-promise-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/map-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/microtask-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/module-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/name-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/oddball-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/promise-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/property-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/property-cell-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/property-descriptor-object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/scope-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/script-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/string-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/struct-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/template-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/template-tq-csa.h"
#include "torque-generated/../../deps/v8/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/test/torque/test-torque-tq-csa.h"
#include "torque-generated/../../deps/v8/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesArraySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TF_BUILTIN(PromiseAllResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0{}, false);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(PromiseAllSettledResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0{}, true);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(PromiseAllSettledRejectElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0{}, true);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor, bool p_hasResolveAndRejectClosures) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{p_context});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block1, tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp3}, tmp2);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{p_function}, &label5);
    ca_.Goto(&block14);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block15);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<JSArray> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<FixedArrayBase> tmp11;
  TNode<FixedArray> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Number> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp6});
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp9 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp14 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp9, tmp13});
    tmp15 = Convert_intptr_Number_0(state_, TNode<Number>{tmp14});
    tmp16 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block20, std::vector<Node*>{}, &block21, std::vector<Node*>{});
  }

  TNode<BoolT> tmp17;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp17, &block23, std::vector<Node*>{}, &block24, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<UintPtrT> tmp24;
  TNode<BoolT> tmp25;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp20});
    tmp22 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp21});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp24 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp22});
    tmp25 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp24});
    ca_.Branch(tmp25, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<HeapObject> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<Object> tmp31;
  TNode<Oddball> tmp32;
  TNode<BoolT> tmp33;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp27 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp26});
    tmp28 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp27});
    std::tie(tmp29, tmp30) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp28}).Flatten();
    tmp31 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp29, tmp30});
    tmp32 = TheHole_0(state_);
    tmp33 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp31}, TNode<HeapObject>{tmp32});
    ca_.Branch(tmp33, &block25, std::vector<Node*>{}, &block26, std::vector<Node*>{});
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp34;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp34 = Undefined_0(state_);
    ca_.Goto(&block1, tmp34);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.Goto(&block24);
  }

  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<Smi> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<UintPtrT> tmp40;
  TNode<UintPtrT> tmp41;
  TNode<BoolT> tmp42;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp38 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp37});
    tmp39 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp38});
    tmp40 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp41 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp39});
    tmp42 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp40}, TNode<UintPtrT>{tmp41});
    ca_.Branch(tmp42, &block39, std::vector<Node*>{}, &block40, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<HeapObject> tmp46;
  TNode<IntPtrT> tmp47;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp44 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp43});
    tmp45 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp44});
    std::tie(tmp46, tmp47) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp45}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp46, tmp47}, p_value);
    ca_.Goto(&block22);
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<BoolT> tmp51;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp49 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp48});
    tmp50 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp12});
    tmp51 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp50});
    ca_.Branch(tmp51, &block43, std::vector<Node*>{}, &block44, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp52;
  TNode<Smi> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<Smi> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<UintPtrT> tmp59;
  TNode<UintPtrT> tmp60;
  TNode<BoolT> tmp61;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp53 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp49});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp52}, tmp53);
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp57 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp56});
    tmp58 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp57});
    tmp59 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp60 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp58});
    tmp61 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp59}, TNode<UintPtrT>{tmp60});
    ca_.Branch(tmp61, &block50, std::vector<Node*>{}, &block51, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<HeapObject> tmp65;
  TNode<IntPtrT> tmp66;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp63 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp62});
    tmp64 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp54}, TNode<IntPtrT>{tmp63});
    std::tie(tmp65, tmp66) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp64}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp65, tmp66}, p_value);
    ca_.Goto(&block45);
  }

  if (block51.is_used()) {
    ca_.Bind(&block51);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<IntPtrT> tmp70;
  TNode<FixedArray> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<Smi> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<UintPtrT> tmp77;
  TNode<UintPtrT> tmp78;
  TNode<BoolT> tmp79;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    tmp67 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp49});
    tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    tmp69 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp67}, TNode<IntPtrT>{tmp68});
    tmp70 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp71 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp12}, TNode<IntPtrT>{tmp70}, TNode<IntPtrT>{tmp50}, TNode<IntPtrT>{tmp69});
    tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp73 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp74 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp75 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp71, tmp74});
    tmp76 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp75});
    tmp77 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp78 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp76});
    tmp79 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp77}, TNode<UintPtrT>{tmp78});
    ca_.Branch(tmp79, &block65, std::vector<Node*>{}, &block66, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp80;
  TNode<IntPtrT> tmp81;
  TNode<IntPtrT> tmp82;
  TNode<HeapObject> tmp83;
  TNode<IntPtrT> tmp84;
  TNode<IntPtrT> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<Smi> tmp87;
  if (block65.is_used()) {
    ca_.Bind(&block65);
    tmp80 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp81 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp80});
    tmp82 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp72}, TNode<IntPtrT>{tmp81});
    std::tie(tmp83, tmp84) = NewReference_Object_0(state_, TNode<HeapObject>{tmp71}, TNode<IntPtrT>{tmp82}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp83, tmp84}, p_value);
    tmp85 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp85}, tmp71);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp87 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp49});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp86}, tmp87);
    ca_.Goto(&block45);
  }

  if (block66.is_used()) {
    ca_.Bind(&block66);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block45.is_used()) {
    ca_.Bind(&block45);
    ca_.Goto(&block22);
  }

  TNode<Object> tmp88;
  TNode<Smi> tmp89;
  TNode<Smi> tmp90;
  TNode<Smi> tmp91;
  TNode<Smi> tmp92;
  TNode<BoolT> tmp93;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp88 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp89 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp88});
    tmp90 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp91 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp89}, TNode<Smi>{tmp90});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp91});
    tmp92 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp93 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp91}, TNode<Smi>{tmp92});
    ca_.Branch(tmp93, &block68, std::vector<Node*>{}, &block69, std::vector<Node*>{});
  }

  TNode<Object> tmp94;
  TNode<PromiseCapability> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<Object> tmp97;
  TNode<Object> tmp98;
  TNode<Oddball> tmp99;
  TNode<Object> tmp100;
  if (block68.is_used()) {
    ca_.Bind(&block68);
    tmp94 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    tmp95 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp94});
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp97 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp95, tmp96});
    tmp98 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp97});
    tmp99 = Undefined_0(state_);
    tmp100 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp98}, TNode<Object>{tmp99}, TNode<Object>{tmp9});
    ca_.Goto(&block69);
  }

  TNode<Oddball> tmp101;
  if (block69.is_used()) {
    ca_.Bind(&block69);
    tmp101 = Undefined_0(state_);
    ca_.Goto(&block1, tmp101);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block70, phi_bb1_3);
  }

  TNode<Object> phi_bb70_3;
    ca_.Bind(&block70, &phi_bb70_3);
  return TNode<Object>{phi_bb70_3};
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor, bool p_hasResolveAndRejectClosures) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{p_context});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block1, tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp3}, tmp2);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{p_function}, &label5);
    ca_.Goto(&block14);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block15);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<JSArray> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<FixedArrayBase> tmp11;
  TNode<FixedArray> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Number> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp6});
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp9 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp14 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp9, tmp13});
    tmp15 = Convert_intptr_Number_0(state_, TNode<Number>{tmp14});
    tmp16 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block20, std::vector<Node*>{}, &block21, std::vector<Node*>{});
  }

  TNode<BoolT> tmp17;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp17, &block23, std::vector<Node*>{}, &block24, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<UintPtrT> tmp24;
  TNode<BoolT> tmp25;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp20});
    tmp22 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp21});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp24 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp22});
    tmp25 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp24});
    ca_.Branch(tmp25, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<HeapObject> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<Object> tmp31;
  TNode<Oddball> tmp32;
  TNode<BoolT> tmp33;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp27 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp26});
    tmp28 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp27});
    std::tie(tmp29, tmp30) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp28}).Flatten();
    tmp31 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp29, tmp30});
    tmp32 = TheHole_0(state_);
    tmp33 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp31}, TNode<HeapObject>{tmp32});
    ca_.Branch(tmp33, &block25, std::vector<Node*>{}, &block26, std::vector<Node*>{});
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp34;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp34 = Undefined_0(state_);
    ca_.Goto(&block1, tmp34);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.Goto(&block24);
  }

  TNode<IntPtrT> tmp35;
  TNode<Object> tmp36;
  TNode<JSFunction> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<HeapObject> tmp39;
  TNode<Map> tmp40;
  TNode<JSObject> tmp41;
  TNode<String> tmp42;
  TNode<String> tmp43;
  TNode<Object> tmp44;
  TNode<String> tmp45;
  TNode<Object> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<Smi> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<UintPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<BoolT> tmp54;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp35 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    tmp36 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp35});
    tmp37 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp36});
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp39 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp37, tmp38});
    tmp40 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp39});
    tmp41 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp40});
    tmp42 = CodeStubAssembler(state_).StringConstant("status");
    tmp43 = CodeStubAssembler(state_).StringConstant("fulfilled");
    tmp44 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp41, tmp42, tmp43);
    tmp45 = CodeStubAssembler(state_).StringConstant("value");
    tmp46 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp41, tmp45, p_value);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp50 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp49});
    tmp51 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp50});
    tmp52 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp51});
    tmp54 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp52}, TNode<UintPtrT>{tmp53});
    ca_.Branch(tmp54, &block39, std::vector<Node*>{}, &block40, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<HeapObject> tmp58;
  TNode<IntPtrT> tmp59;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp56 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp55});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp47}, TNode<IntPtrT>{tmp56});
    std::tie(tmp58, tmp59) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp57}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp58, tmp59}, tmp41);
    ca_.Goto(&block22);
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp60;
  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<Object> tmp64;
  TNode<JSFunction> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<HeapObject> tmp67;
  TNode<Map> tmp68;
  TNode<JSObject> tmp69;
  TNode<String> tmp70;
  TNode<String> tmp71;
  TNode<Object> tmp72;
  TNode<String> tmp73;
  TNode<Object> tmp74;
  TNode<BoolT> tmp75;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp61 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp60});
    tmp62 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp12});
    tmp63 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    tmp64 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp63});
    tmp65 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp64});
    tmp66 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp67 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp65, tmp66});
    tmp68 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp67});
    tmp69 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp68});
    tmp70 = CodeStubAssembler(state_).StringConstant("status");
    tmp71 = CodeStubAssembler(state_).StringConstant("fulfilled");
    tmp72 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp69, tmp70, tmp71);
    tmp73 = CodeStubAssembler(state_).StringConstant("value");
    tmp74 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp69, tmp73, p_value);
    tmp75 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp62});
    ca_.Branch(tmp75, &block43, std::vector<Node*>{}, &block44, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp76;
  TNode<Smi> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<IntPtrT> tmp80;
  TNode<Smi> tmp81;
  TNode<IntPtrT> tmp82;
  TNode<UintPtrT> tmp83;
  TNode<UintPtrT> tmp84;
  TNode<BoolT> tmp85;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    tmp76 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp77 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp61});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp76}, tmp77);
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp80 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp81 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp80});
    tmp82 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp81});
    tmp83 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp84 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp82});
    tmp85 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp83}, TNode<UintPtrT>{tmp84});
    ca_.Branch(tmp85, &block50, std::vector<Node*>{}, &block51, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp86;
  TNode<IntPtrT> tmp87;
  TNode<IntPtrT> tmp88;
  TNode<HeapObject> tmp89;
  TNode<IntPtrT> tmp90;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp87 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp86});
    tmp88 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp78}, TNode<IntPtrT>{tmp87});
    std::tie(tmp89, tmp90) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp88}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp89, tmp90}, tmp69);
    ca_.Goto(&block45);
  }

  if (block51.is_used()) {
    ca_.Bind(&block51);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp91;
  TNode<IntPtrT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<IntPtrT> tmp94;
  TNode<FixedArray> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<IntPtrT> tmp98;
  TNode<Smi> tmp99;
  TNode<IntPtrT> tmp100;
  TNode<UintPtrT> tmp101;
  TNode<UintPtrT> tmp102;
  TNode<BoolT> tmp103;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    tmp91 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp61});
    tmp92 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    tmp93 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp91}, TNode<IntPtrT>{tmp92});
    tmp94 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp95 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp12}, TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp62}, TNode<IntPtrT>{tmp93});
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp97 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp98 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp99 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp95, tmp98});
    tmp100 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp99});
    tmp101 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp102 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp100});
    tmp103 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp101}, TNode<UintPtrT>{tmp102});
    ca_.Branch(tmp103, &block65, std::vector<Node*>{}, &block66, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<IntPtrT> tmp106;
  TNode<HeapObject> tmp107;
  TNode<IntPtrT> tmp108;
  TNode<IntPtrT> tmp109;
  TNode<IntPtrT> tmp110;
  TNode<Smi> tmp111;
  if (block65.is_used()) {
    ca_.Bind(&block65);
    tmp104 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp105 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp104});
    tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp96}, TNode<IntPtrT>{tmp105});
    std::tie(tmp107, tmp108) = NewReference_Object_0(state_, TNode<HeapObject>{tmp95}, TNode<IntPtrT>{tmp106}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp107, tmp108}, tmp69);
    tmp109 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp109}, tmp95);
    tmp110 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp111 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp61});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp110}, tmp111);
    ca_.Goto(&block45);
  }

  if (block66.is_used()) {
    ca_.Bind(&block66);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block45.is_used()) {
    ca_.Bind(&block45);
    ca_.Goto(&block22);
  }

  TNode<Object> tmp112;
  TNode<Smi> tmp113;
  TNode<Smi> tmp114;
  TNode<Smi> tmp115;
  TNode<Smi> tmp116;
  TNode<BoolT> tmp117;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp112 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp113 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp112});
    tmp114 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp115 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp113}, TNode<Smi>{tmp114});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp115});
    tmp116 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp117 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp115}, TNode<Smi>{tmp116});
    ca_.Branch(tmp117, &block68, std::vector<Node*>{}, &block69, std::vector<Node*>{});
  }

  TNode<Object> tmp118;
  TNode<PromiseCapability> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<Object> tmp121;
  TNode<Object> tmp122;
  TNode<Oddball> tmp123;
  TNode<Object> tmp124;
  if (block68.is_used()) {
    ca_.Bind(&block68);
    tmp118 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    tmp119 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp118});
    tmp120 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp121 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp119, tmp120});
    tmp122 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp121});
    tmp123 = Undefined_0(state_);
    tmp124 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp122}, TNode<Object>{tmp123}, TNode<Object>{tmp9});
    ca_.Goto(&block69);
  }

  TNode<Oddball> tmp125;
  if (block69.is_used()) {
    ca_.Bind(&block69);
    tmp125 = Undefined_0(state_);
    ca_.Goto(&block1, tmp125);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block70, phi_bb1_3);
  }

  TNode<Object> phi_bb70_3;
    ca_.Bind(&block70, &phi_bb70_3);
  return TNode<Object>{phi_bb70_3};
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 p_wrapResultFunctor, bool p_hasResolveAndRejectClosures) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{p_context});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block1, tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp3}, tmp2);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{p_function}, &label5);
    ca_.Goto(&block14);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block15);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<JSArray> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<FixedArrayBase> tmp11;
  TNode<FixedArray> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Number> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp6});
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp9 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp14 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp9, tmp13});
    tmp15 = Convert_intptr_Number_0(state_, TNode<Number>{tmp14});
    tmp16 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block20, std::vector<Node*>{}, &block21, std::vector<Node*>{});
  }

  TNode<BoolT> tmp17;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, p_hasResolveAndRejectClosures);
    ca_.Branch(tmp17, &block23, std::vector<Node*>{}, &block24, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<UintPtrT> tmp24;
  TNode<BoolT> tmp25;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp20});
    tmp22 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp21});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp24 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp22});
    tmp25 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp23}, TNode<UintPtrT>{tmp24});
    ca_.Branch(tmp25, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<HeapObject> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<Object> tmp31;
  TNode<Oddball> tmp32;
  TNode<BoolT> tmp33;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp27 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp26});
    tmp28 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp18}, TNode<IntPtrT>{tmp27});
    std::tie(tmp29, tmp30) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp28}).Flatten();
    tmp31 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp29, tmp30});
    tmp32 = TheHole_0(state_);
    tmp33 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp31}, TNode<HeapObject>{tmp32});
    ca_.Branch(tmp33, &block25, std::vector<Node*>{}, &block26, std::vector<Node*>{});
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp34;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp34 = Undefined_0(state_);
    ca_.Goto(&block1, tmp34);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    ca_.Goto(&block24);
  }

  TNode<IntPtrT> tmp35;
  TNode<Object> tmp36;
  TNode<JSFunction> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<HeapObject> tmp39;
  TNode<Map> tmp40;
  TNode<JSObject> tmp41;
  TNode<String> tmp42;
  TNode<String> tmp43;
  TNode<Object> tmp44;
  TNode<String> tmp45;
  TNode<Object> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<Smi> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<UintPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<BoolT> tmp54;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp35 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    tmp36 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp35});
    tmp37 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp36});
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp39 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp37, tmp38});
    tmp40 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp39});
    tmp41 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp40});
    tmp42 = CodeStubAssembler(state_).StringConstant("status");
    tmp43 = CodeStubAssembler(state_).StringConstant("rejected");
    tmp44 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp41, tmp42, tmp43);
    tmp45 = CodeStubAssembler(state_).StringConstant("reason");
    tmp46 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp41, tmp45, p_value);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp50 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp49});
    tmp51 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp50});
    tmp52 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp51});
    tmp54 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp52}, TNode<UintPtrT>{tmp53});
    ca_.Branch(tmp54, &block39, std::vector<Node*>{}, &block40, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<HeapObject> tmp58;
  TNode<IntPtrT> tmp59;
  if (block39.is_used()) {
    ca_.Bind(&block39);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp56 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp55});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp47}, TNode<IntPtrT>{tmp56});
    std::tie(tmp58, tmp59) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp57}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp58, tmp59}, tmp41);
    ca_.Goto(&block22);
  }

  if (block40.is_used()) {
    ca_.Bind(&block40);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp60;
  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<Object> tmp64;
  TNode<JSFunction> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<HeapObject> tmp67;
  TNode<Map> tmp68;
  TNode<JSObject> tmp69;
  TNode<String> tmp70;
  TNode<String> tmp71;
  TNode<Object> tmp72;
  TNode<String> tmp73;
  TNode<Object> tmp74;
  TNode<BoolT> tmp75;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp61 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp60});
    tmp62 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp12});
    tmp63 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    tmp64 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp63});
    tmp65 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp64});
    tmp66 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp67 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp65, tmp66});
    tmp68 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp67});
    tmp69 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp68});
    tmp70 = CodeStubAssembler(state_).StringConstant("status");
    tmp71 = CodeStubAssembler(state_).StringConstant("rejected");
    tmp72 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp69, tmp70, tmp71);
    tmp73 = CodeStubAssembler(state_).StringConstant("reason");
    tmp74 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp69, tmp73, p_value);
    tmp75 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp62});
    ca_.Branch(tmp75, &block43, std::vector<Node*>{}, &block44, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp76;
  TNode<Smi> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<IntPtrT> tmp80;
  TNode<Smi> tmp81;
  TNode<IntPtrT> tmp82;
  TNode<UintPtrT> tmp83;
  TNode<UintPtrT> tmp84;
  TNode<BoolT> tmp85;
  if (block43.is_used()) {
    ca_.Bind(&block43);
    tmp76 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp77 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp61});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp76}, tmp77);
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp80 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp81 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp80});
    tmp82 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp81});
    tmp83 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp84 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp82});
    tmp85 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp83}, TNode<UintPtrT>{tmp84});
    ca_.Branch(tmp85, &block50, std::vector<Node*>{}, &block51, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp86;
  TNode<IntPtrT> tmp87;
  TNode<IntPtrT> tmp88;
  TNode<HeapObject> tmp89;
  TNode<IntPtrT> tmp90;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp87 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp86});
    tmp88 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp78}, TNode<IntPtrT>{tmp87});
    std::tie(tmp89, tmp90) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp88}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp89, tmp90}, tmp69);
    ca_.Goto(&block45);
  }

  if (block51.is_used()) {
    ca_.Bind(&block51);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp91;
  TNode<IntPtrT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<IntPtrT> tmp94;
  TNode<FixedArray> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<IntPtrT> tmp98;
  TNode<Smi> tmp99;
  TNode<IntPtrT> tmp100;
  TNode<UintPtrT> tmp101;
  TNode<UintPtrT> tmp102;
  TNode<BoolT> tmp103;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    tmp91 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp61});
    tmp92 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    tmp93 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp91}, TNode<IntPtrT>{tmp92});
    tmp94 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp95 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp12}, TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp62}, TNode<IntPtrT>{tmp93});
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp97 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp98 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp99 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp95, tmp98});
    tmp100 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp99});
    tmp101 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp102 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp100});
    tmp103 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp101}, TNode<UintPtrT>{tmp102});
    ca_.Branch(tmp103, &block65, std::vector<Node*>{}, &block66, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<IntPtrT> tmp106;
  TNode<HeapObject> tmp107;
  TNode<IntPtrT> tmp108;
  TNode<IntPtrT> tmp109;
  TNode<IntPtrT> tmp110;
  TNode<Smi> tmp111;
  if (block65.is_used()) {
    ca_.Bind(&block65);
    tmp104 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp105 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp104});
    tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp96}, TNode<IntPtrT>{tmp105});
    std::tie(tmp107, tmp108) = NewReference_Object_0(state_, TNode<HeapObject>{tmp95}, TNode<IntPtrT>{tmp106}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp107, tmp108}, tmp69);
    tmp109 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp109}, tmp95);
    tmp110 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp111 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp61});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp110}, tmp111);
    ca_.Goto(&block45);
  }

  if (block66.is_used()) {
    ca_.Bind(&block66);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block45.is_used()) {
    ca_.Bind(&block45);
    ca_.Goto(&block22);
  }

  TNode<Object> tmp112;
  TNode<Smi> tmp113;
  TNode<Smi> tmp114;
  TNode<Smi> tmp115;
  TNode<Smi> tmp116;
  TNode<BoolT> tmp117;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp112 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp113 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp112});
    tmp114 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp115 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp113}, TNode<Smi>{tmp114});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp115});
    tmp116 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp117 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp115}, TNode<Smi>{tmp116});
    ca_.Branch(tmp117, &block68, std::vector<Node*>{}, &block69, std::vector<Node*>{});
  }

  TNode<Object> tmp118;
  TNode<PromiseCapability> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<Object> tmp121;
  TNode<Object> tmp122;
  TNode<Oddball> tmp123;
  TNode<Object> tmp124;
  if (block68.is_used()) {
    ca_.Bind(&block68);
    tmp118 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    tmp119 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp118});
    tmp120 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp121 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp119, tmp120});
    tmp122 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp121});
    tmp123 = Undefined_0(state_);
    tmp124 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp122}, TNode<Object>{tmp123}, TNode<Object>{tmp9});
    ca_.Goto(&block69);
  }

  TNode<Oddball> tmp125;
  if (block69.is_used()) {
    ca_.Bind(&block69);
    tmp125 = Undefined_0(state_);
    ca_.Goto(&block1, tmp125);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block70, phi_bb1_3);
  }

  TNode<Object> phi_bb70_3;
    ca_.Bind(&block70, &phi_bb70_3);
  return TNode<Object>{phi_bb70_3};
}

}  // namespace internal
}  // namespace v8

