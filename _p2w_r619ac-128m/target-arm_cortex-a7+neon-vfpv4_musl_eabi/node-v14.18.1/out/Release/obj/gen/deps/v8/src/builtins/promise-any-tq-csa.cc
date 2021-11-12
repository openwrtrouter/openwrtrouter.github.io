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

TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o) {
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

TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o) {
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

TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementErrorsArraySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o) {
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

TNode<Int32T> FromConstexpr_PromiseAnyRejectElementContextSlots_constexpr_kPromiseAnyRejectElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAnyRejectElementContextSlots p_o) {
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

TNode<Context> CreatePromiseAnyRejectElementContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseCapability> p_capability, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<Smi> tmp1;
  TNode<Oddball> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementLength);
    tmp1 = CodeStubAssembler(state_).SmiConstant(1);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot, TNode<Object>{tmp1});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementCapabilitySlot, TNode<Object>{p_capability});
    tmp2 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementErrorsArraySlot, TNode<Object>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Context>{tmp0};
}

TNode<JSFunction> CreatePromiseAnyRejectElementFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_rejectElementContext, TNode<Smi> p_index, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Map> tmp2;
  TNode<SharedFunctionInfo> tmp3;
  TNode<JSFunction> tmp4;
  TNode<IntPtrT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    tmp3 = CodeStubAssembler(state_).PromiseAnyRejectElementSharedFunConstant();
    tmp4 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp2}, TNode<SharedFunctionInfo>{tmp3}, TNode<Context>{p_rejectElementContext});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp4, tmp5}, p_index);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TNode<JSFunction>{tmp4};
}

TF_BUILTIN(PromiseAnyRejectElementClosure, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{parameter0});
    ca_.Branch(tmp0, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp1 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{parameter2, tmp3}, tmp2);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{parameter2}, &label5);
    ca_.Goto(&block13);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block14);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<Oddball> tmp9;
  TNode<BoolT> tmp10;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp6});
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementErrorsArraySlot);
    tmp9 = Undefined_0(state_);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block19, std::vector<Node*>{}, &block20, std::vector<Node*>{});
  }

  TNode<Oddball> tmp11;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp11 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp11);
  }

  TNode<Object> tmp12;
  TNode<FixedArray> tmp13;
  TNode<Object> tmp14;
  TNode<Smi> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<Smi> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<UintPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<BoolT> tmp23;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp12 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementErrorsArraySlot);
    tmp13 = UnsafeCast_FixedArray_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp12});
    tmp14 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot);
    tmp15 = UnsafeCast_Smi_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp19 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp13, tmp18});
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp19});
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp20});
    tmp23 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{tmp22});
    ca_.Branch(tmp23, &block25, std::vector<Node*>{}, &block26, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<HeapObject> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<Smi> tmp29;
  TNode<Smi> tmp30;
  TNode<Smi> tmp31;
  TNode<BoolT> tmp32;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp25 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp24});
    tmp26 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp25});
    std::tie(tmp27, tmp28) = NewReference_Object_0(state_, TNode<HeapObject>{tmp13}, TNode<IntPtrT>{tmp26}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp27, tmp28}, parameter3);
    tmp29 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp30 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp15}, TNode<Smi>{tmp29});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{parameter0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot, TNode<Object>{tmp30});
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp32 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp31});
    ca_.Branch(tmp32, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<JSObject> tmp33;
  TNode<Object> tmp34;
  TNode<PromiseCapability> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<Object> tmp37;
  TNode<JSReceiver> tmp38;
  TNode<Oddball> tmp39;
  TNode<Object> tmp40;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp33 = ConstructAggregateError_0(state_, TNode<Context>{parameter0}, TNode<FixedArray>{tmp13});
    tmp34 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementCapabilitySlot);
    tmp35 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp34});
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp37 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp35, tmp36});
    tmp38 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp37});
    tmp39 = Undefined_0(state_);
    tmp40 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp38}, TNode<Object>{tmp39}, TNode<Object>{tmp33});
    ca_.Goto(&block29);
  }

  TNode<Oddball> tmp41;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp41 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp41);
  }
}

TNode<Object> PerformPromiseAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_iteratorRecord, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_resultCapability, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object, Object> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object, Smi, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block67(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi> block68(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block69(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block70(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block72(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block73(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block74(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block75(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block76(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block77(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi, Smi> block78(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi> block79(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block82(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block86(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block87(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, BoolT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block80(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block88(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block89(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block90(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi, Object> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi> block105(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, Smi> block106(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block107(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<FixedArray> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Context> tmp4;
  TNode<Smi> tmp5;
  TNode<Oddball> tmp6;
  TNode<BoolT> tmp7;
      TNode<Object> tmp9;
  TNode<BoolT> tmp10;
      TNode<Object> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2, tmp3) = NewGrowableFixedArray_0(state_).Flatten();
    tmp4 = CreatePromiseAnyRejectElementContext_0(state_, TNode<Context>{p_context}, TNode<PromiseCapability>{p_resultCapability}, TNode<NativeContext>{tmp0});
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp6 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch8__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch8__label);
    tmp7 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{tmp0}, TNode<JSReceiver>{p_constructor});
    }
    if (catch8__label.is_used()) {
      compiler::CodeAssemblerLabel catch8_skip(&ca_);
      ca_.Goto(&catch8_skip);
      ca_.Bind(&catch8__label, &tmp9);
      ca_.Goto(&block9);
      ca_.Bind(&catch8_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch11__label);
    tmp10 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp7});
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      ca_.Bind(&catch11__label, &tmp12);
      ca_.Goto(&block10);
      ca_.Bind(&catch11_skip);
    }
    ca_.Branch(tmp10, &block7, std::vector<Node*>{}, &block8, std::vector<Node*>{tmp6});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp9);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp12);
  }

  TNode<String> tmp13;
  TNode<Object> tmp14;
      TNode<Object> tmp16;
  TNode<JSReceiver> tmp17;
      TNode<Object> tmp20;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp13 = kResolveString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
    tmp14 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_constructor}, TNode<Object>{tmp13});
    }
    if (catch15__label.is_used()) {
      compiler::CodeAssemblerLabel catch15_skip(&ca_);
      ca_.Goto(&catch15_skip);
      ca_.Bind(&catch15__label, &tmp16);
      ca_.Goto(&block11);
      ca_.Bind(&catch15_skip);
    }
    compiler::CodeAssemblerLabel label18(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch19__label);
    tmp17 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp14}, &label18);
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      ca_.Bind(&catch19__label, &tmp20);
      ca_.Goto(&block16);
      ca_.Bind(&catch19_skip);
    }
    ca_.Goto(&block14);
    if (label18.is_used()) {
      ca_.Bind(&label18);
      ca_.Goto(&block15);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp16);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp20);
  }

      TNode<Object> tmp22;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch21__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledNonCallable, "resolve");
    }
    if (catch21__label.is_used()) {
      compiler::CodeAssemblerLabel catch21_skip(&ca_);
      ca_.Bind(&catch21__label, &tmp22);
      ca_.Goto(&block17);
    }
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block8, tmp17);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp22);
  }

  TNode<Object> phi_bb8_11;
  TNode<IntPtrT> tmp23;
      TNode<Object> tmp25;
  TNode<Object> tmp26;
      TNode<Object> tmp28;
  TNode<Map> tmp29;
      TNode<Object> tmp31;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch24__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch24__label);
    tmp23 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    }
    if (catch24__label.is_used()) {
      compiler::CodeAssemblerLabel catch24_skip(&ca_);
      ca_.Goto(&catch24_skip);
      ca_.Bind(&catch24__label, &tmp25);
      ca_.Goto(&block18, phi_bb8_11);
      ca_.Bind(&catch24_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch27__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch27__label);
    tmp26 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp23});
    }
    if (catch27__label.is_used()) {
      compiler::CodeAssemblerLabel catch27_skip(&ca_);
      ca_.Goto(&catch27_skip);
      ca_.Bind(&catch27__label, &tmp28);
      ca_.Goto(&block19, phi_bb8_11);
      ca_.Bind(&catch27_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch30__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch30__label);
    tmp29 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp26});
    }
    if (catch30__label.is_used()) {
      compiler::CodeAssemblerLabel catch30_skip(&ca_);
      ca_.Goto(&catch30_skip);
      ca_.Bind(&catch30__label, &tmp31);
      ca_.Goto(&block20, phi_bb8_11);
      ca_.Bind(&catch30_skip);
    }
    ca_.Goto(&block23, tmp1, tmp2, tmp3, tmp5, phi_bb8_11);
  }

  TNode<Object> phi_bb18_11;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_11);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp25);
  }

  TNode<Object> phi_bb19_11;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_11);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp28);
  }

  TNode<Object> phi_bb20_11;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11);
    ca_.Goto(&block6, tmp1, tmp2, tmp3, tmp5, tmp31);
  }

  TNode<FixedArray> phi_bb23_6;
  TNode<IntPtrT> phi_bb23_7;
  TNode<IntPtrT> phi_bb23_8;
  TNode<Smi> phi_bb23_10;
  TNode<Object> phi_bb23_11;
  TNode<BoolT> tmp32;
      TNode<Object> tmp34;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_6, &phi_bb23_7, &phi_bb23_8, &phi_bb23_10, &phi_bb23_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch33__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch33__label);
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch33__label.is_used()) {
      compiler::CodeAssemblerLabel catch33_skip(&ca_);
      ca_.Goto(&catch33_skip);
      ca_.Bind(&catch33__label, &tmp34);
      ca_.Goto(&block24, phi_bb23_6, phi_bb23_7, phi_bb23_8, phi_bb23_10, phi_bb23_11);
      ca_.Bind(&catch33_skip);
    }
    ca_.Branch(tmp32, &block21, std::vector<Node*>{phi_bb23_6, phi_bb23_7, phi_bb23_8, phi_bb23_10, phi_bb23_11}, &block22, std::vector<Node*>{phi_bb23_6, phi_bb23_7, phi_bb23_8, phi_bb23_10, phi_bb23_11});
  }

  TNode<FixedArray> phi_bb24_6;
  TNode<IntPtrT> phi_bb24_7;
  TNode<IntPtrT> phi_bb24_8;
  TNode<Smi> phi_bb24_10;
  TNode<Object> phi_bb24_11;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_6, &phi_bb24_7, &phi_bb24_8, &phi_bb24_10, &phi_bb24_11);
    ca_.Goto(&block6, phi_bb24_6, phi_bb24_7, phi_bb24_8, phi_bb24_10, tmp34);
  }

  TNode<FixedArray> phi_bb21_6;
  TNode<IntPtrT> phi_bb21_7;
  TNode<IntPtrT> phi_bb21_8;
  TNode<Smi> phi_bb21_10;
  TNode<Object> phi_bb21_11;
  TNode<JSReceiver> tmp35;
      TNode<Object> tmp38;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_6, &phi_bb21_7, &phi_bb21_8, &phi_bb21_10, &phi_bb21_11);
    compiler::CodeAssemblerLabel label36(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
    tmp35 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{p_iteratorRecord.object}, TNode<Object>{p_iteratorRecord.next}}, TNode<Map>{tmp29}, &label36);
    }
    if (catch37__label.is_used()) {
      compiler::CodeAssemblerLabel catch37_skip(&ca_);
      ca_.Goto(&catch37_skip);
      ca_.Bind(&catch37__label, &tmp38);
      ca_.Goto(&block31, phi_bb21_6, phi_bb21_7, phi_bb21_8, phi_bb21_10, phi_bb21_11);
      ca_.Bind(&catch37_skip);
    }
    ca_.Goto(&block29, phi_bb21_6, phi_bb21_7, phi_bb21_8, phi_bb21_10, phi_bb21_11);
    if (label36.is_used()) {
      ca_.Bind(&label36);
      ca_.Goto(&block30, phi_bb21_6, phi_bb21_7, phi_bb21_8, phi_bb21_10, phi_bb21_11);
    }
  }

  TNode<FixedArray> phi_bb31_6;
  TNode<IntPtrT> phi_bb31_7;
  TNode<IntPtrT> phi_bb31_8;
  TNode<Smi> phi_bb31_10;
  TNode<Object> phi_bb31_11;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_6, &phi_bb31_7, &phi_bb31_8, &phi_bb31_10, &phi_bb31_11);
    ca_.Goto(&block26, phi_bb31_6, phi_bb31_7, phi_bb31_8, phi_bb31_10, phi_bb31_11, tmp38);
  }

  TNode<FixedArray> phi_bb30_6;
  TNode<IntPtrT> phi_bb30_7;
  TNode<IntPtrT> phi_bb30_8;
  TNode<Smi> phi_bb30_10;
  TNode<Object> phi_bb30_11;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_6, &phi_bb30_7, &phi_bb30_8, &phi_bb30_10, &phi_bb30_11);
    ca_.Goto(&block3, phi_bb30_6, phi_bb30_7, phi_bb30_8, phi_bb30_10);
  }

  TNode<FixedArray> phi_bb29_6;
  TNode<IntPtrT> phi_bb29_7;
  TNode<IntPtrT> phi_bb29_8;
  TNode<Smi> phi_bb29_10;
  TNode<Object> phi_bb29_11;
  TNode<Object> tmp39;
      TNode<Object> tmp41;
  TNode<Smi> tmp42;
      TNode<Object> tmp44;
  TNode<BoolT> tmp45;
      TNode<Object> tmp47;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_6, &phi_bb29_7, &phi_bb29_8, &phi_bb29_10, &phi_bb29_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp39 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{p_context}, TNode<JSReceiver>{tmp35}, TNode<Map>{tmp29});
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block32, phi_bb29_6, phi_bb29_7, phi_bb29_8, phi_bb29_10, phi_bb29_11);
      ca_.Bind(&catch40_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch43__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch43__label);
    tmp42 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyArray::HashField::kMax);
    }
    if (catch43__label.is_used()) {
      compiler::CodeAssemblerLabel catch43_skip(&ca_);
      ca_.Goto(&catch43_skip);
      ca_.Bind(&catch43__label, &tmp44);
      ca_.Goto(&block35, phi_bb29_6, phi_bb29_7, phi_bb29_8, phi_bb29_10, phi_bb29_11, phi_bb29_10, phi_bb29_10);
      ca_.Bind(&catch43_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch46__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch46__label);
    tmp45 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb29_10}, TNode<Smi>{tmp42});
    }
    if (catch46__label.is_used()) {
      compiler::CodeAssemblerLabel catch46_skip(&ca_);
      ca_.Goto(&catch46_skip);
      ca_.Bind(&catch46__label, &tmp47);
      ca_.Goto(&block36, phi_bb29_6, phi_bb29_7, phi_bb29_8, phi_bb29_10, phi_bb29_11, phi_bb29_10);
      ca_.Bind(&catch46_skip);
    }
    ca_.Branch(tmp45, &block33, std::vector<Node*>{phi_bb29_6, phi_bb29_7, phi_bb29_8, phi_bb29_10, phi_bb29_11}, &block34, std::vector<Node*>{phi_bb29_6, phi_bb29_7, phi_bb29_8, phi_bb29_10, phi_bb29_11});
  }

  TNode<FixedArray> phi_bb32_6;
  TNode<IntPtrT> phi_bb32_7;
  TNode<IntPtrT> phi_bb32_8;
  TNode<Smi> phi_bb32_10;
  TNode<Object> phi_bb32_11;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_6, &phi_bb32_7, &phi_bb32_8, &phi_bb32_10, &phi_bb32_11);
    ca_.Goto(&block26, phi_bb32_6, phi_bb32_7, phi_bb32_8, phi_bb32_10, phi_bb32_11, tmp41);
  }

  TNode<FixedArray> phi_bb26_6;
  TNode<IntPtrT> phi_bb26_7;
  TNode<IntPtrT> phi_bb26_8;
  TNode<Smi> phi_bb26_10;
  TNode<Object> phi_bb26_11;
  TNode<Object> phi_bb26_14;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_6, &phi_bb26_7, &phi_bb26_8, &phi_bb26_10, &phi_bb26_11, &phi_bb26_14);
    ca_.Goto(&block1, phi_bb26_14);
  }

  TNode<FixedArray> phi_bb35_6;
  TNode<IntPtrT> phi_bb35_7;
  TNode<IntPtrT> phi_bb35_8;
  TNode<Smi> phi_bb35_10;
  TNode<Object> phi_bb35_11;
  TNode<Smi> phi_bb35_14;
  TNode<Smi> phi_bb35_15;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_6, &phi_bb35_7, &phi_bb35_8, &phi_bb35_10, &phi_bb35_11, &phi_bb35_14, &phi_bb35_15);
    ca_.Goto(&block6, phi_bb35_6, phi_bb35_7, phi_bb35_8, phi_bb35_10, tmp44);
  }

  TNode<FixedArray> phi_bb36_6;
  TNode<IntPtrT> phi_bb36_7;
  TNode<IntPtrT> phi_bb36_8;
  TNode<Smi> phi_bb36_10;
  TNode<Object> phi_bb36_11;
  TNode<Smi> phi_bb36_14;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_6, &phi_bb36_7, &phi_bb36_8, &phi_bb36_10, &phi_bb36_11, &phi_bb36_14);
    ca_.Goto(&block6, phi_bb36_6, phi_bb36_7, phi_bb36_8, phi_bb36_10, tmp47);
  }

  TNode<FixedArray> phi_bb33_6;
  TNode<IntPtrT> phi_bb33_7;
  TNode<IntPtrT> phi_bb33_8;
  TNode<Smi> phi_bb33_10;
  TNode<Object> phi_bb33_11;
  TNode<Object> tmp48;
      TNode<Object> tmp50;
      TNode<Object> tmp52;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_6, &phi_bb33_7, &phi_bb33_8, &phi_bb33_10, &phi_bb33_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch49__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch49__label);
    tmp48 = FromConstexpr_Object_constexpr_string_0(state_, "any");
    }
    if (catch49__label.is_used()) {
      compiler::CodeAssemblerLabel catch49_skip(&ca_);
      ca_.Goto(&catch49_skip);
      ca_.Bind(&catch49__label, &tmp50);
      ca_.Goto(&block37, phi_bb33_6, phi_bb33_7, phi_bb33_8, phi_bb33_10, phi_bb33_11);
      ca_.Bind(&catch49_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch51__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch51__label);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kTooManyElementsInPromiseCombinator, TNode<Object>{tmp48});
    }
    if (catch51__label.is_used()) {
      compiler::CodeAssemblerLabel catch51_skip(&ca_);
      ca_.Bind(&catch51__label, &tmp52);
      ca_.Goto(&block38, phi_bb33_6, phi_bb33_7, phi_bb33_8, phi_bb33_10, phi_bb33_11);
    }
  }

  TNode<FixedArray> phi_bb37_6;
  TNode<IntPtrT> phi_bb37_7;
  TNode<IntPtrT> phi_bb37_8;
  TNode<Smi> phi_bb37_10;
  TNode<Object> phi_bb37_11;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_6, &phi_bb37_7, &phi_bb37_8, &phi_bb37_10, &phi_bb37_11);
    ca_.Goto(&block6, phi_bb37_6, phi_bb37_7, phi_bb37_8, phi_bb37_10, tmp50);
  }

  TNode<FixedArray> phi_bb38_6;
  TNode<IntPtrT> phi_bb38_7;
  TNode<IntPtrT> phi_bb38_8;
  TNode<Smi> phi_bb38_10;
  TNode<Object> phi_bb38_11;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_6, &phi_bb38_7, &phi_bb38_8, &phi_bb38_10, &phi_bb38_11);
    ca_.Goto(&block6, phi_bb38_6, phi_bb38_7, phi_bb38_8, phi_bb38_10, tmp52);
  }

  TNode<FixedArray> phi_bb34_6;
  TNode<IntPtrT> phi_bb34_7;
  TNode<IntPtrT> phi_bb34_8;
  TNode<Smi> phi_bb34_10;
  TNode<Object> phi_bb34_11;
  TNode<Oddball> tmp53;
  TNode<BoolT> tmp54;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_6, &phi_bb34_7, &phi_bb34_8, &phi_bb34_10, &phi_bb34_11);
    tmp53 = Undefined_0(state_);
    tmp54 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb34_7}, TNode<IntPtrT>{phi_bb34_8});
    ca_.Branch(tmp54, &block45, std::vector<Node*>{phi_bb34_6, phi_bb34_7, phi_bb34_8, phi_bb34_10, phi_bb34_11}, &block46, std::vector<Node*>{phi_bb34_6, phi_bb34_7, phi_bb34_8, phi_bb34_10, phi_bb34_11});
  }

  TNode<FixedArray> phi_bb45_6;
  TNode<IntPtrT> phi_bb45_7;
  TNode<IntPtrT> phi_bb45_8;
  TNode<Smi> phi_bb45_10;
  TNode<Object> phi_bb45_11;
  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<IntPtrT> tmp60;
  TNode<FixedArray> tmp61;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_6, &phi_bb45_7, &phi_bb45_8, &phi_bb45_10, &phi_bb45_11);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp56 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{phi_bb45_7}, TNode<IntPtrT>{tmp55});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb45_7}, TNode<IntPtrT>{tmp56});
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp59 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp57}, TNode<IntPtrT>{tmp58});
    tmp60 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp61 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb45_6}, TNode<IntPtrT>{tmp60}, TNode<IntPtrT>{phi_bb45_8}, TNode<IntPtrT>{tmp59});
    ca_.Goto(&block46, tmp61, tmp59, phi_bb45_8, phi_bb45_10, phi_bb45_11);
  }

  TNode<FixedArray> phi_bb46_6;
  TNode<IntPtrT> phi_bb46_7;
  TNode<IntPtrT> phi_bb46_8;
  TNode<Smi> phi_bb46_10;
  TNode<Object> phi_bb46_11;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<Smi> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<UintPtrT> tmp69;
  TNode<UintPtrT> tmp70;
  TNode<BoolT> tmp71;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_6, &phi_bb46_7, &phi_bb46_8, &phi_bb46_10, &phi_bb46_11);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp65 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{phi_bb46_6, tmp64});
    tmp66 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp65});
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp68 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb46_8}, TNode<IntPtrT>{tmp67});
    tmp69 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb46_8});
    tmp70 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp66});
    tmp71 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp69}, TNode<UintPtrT>{tmp70});
    ca_.Branch(tmp71, &block64, std::vector<Node*>{phi_bb46_10, phi_bb46_11, phi_bb46_8, phi_bb46_8, phi_bb46_8, phi_bb46_8}, &block65, std::vector<Node*>{phi_bb46_10, phi_bb46_11, phi_bb46_8, phi_bb46_8, phi_bb46_8, phi_bb46_8});
  }

  TNode<Smi> phi_bb64_10;
  TNode<Object> phi_bb64_11;
  TNode<IntPtrT> phi_bb64_20;
  TNode<IntPtrT> phi_bb64_21;
  TNode<IntPtrT> phi_bb64_25;
  TNode<IntPtrT> phi_bb64_26;
  TNode<IntPtrT> tmp72;
  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<HeapObject> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Object> tmp77;
      TNode<Object> tmp79;
  TNode<JSFunction> tmp80;
      TNode<Object> tmp82;
  TNode<Object> tmp83;
      TNode<Object> tmp85;
  TNode<Smi> tmp86;
      TNode<Object> tmp88;
  TNode<Smi> tmp89;
      TNode<Object> tmp91;
  TNode<Smi> tmp92;
      TNode<Object> tmp94;
      TNode<Object> tmp96;
  TNode<String> tmp97;
  TNode<Object> tmp98;
      TNode<Object> tmp100;
  TNode<IntPtrT> tmp101;
      TNode<Object> tmp103;
  TNode<Object> tmp104;
  TNode<Object> tmp105;
      TNode<Object> tmp107;
  TNode<Object> tmp108;
      TNode<Object> tmp110;
  TNode<Smi> tmp111;
      TNode<Object> tmp113;
  TNode<Smi> tmp114;
      TNode<Object> tmp116;
  TNode<BoolT> tmp117;
      TNode<Object> tmp119;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_10, &phi_bb64_11, &phi_bb64_20, &phi_bb64_21, &phi_bb64_25, &phi_bb64_26);
    tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp73 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{phi_bb64_26}, TNode<IntPtrT>{tmp72});
    tmp74 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp62}, TNode<IntPtrT>{tmp73});
    std::tie(tmp75, tmp76) = NewReference_Object_0(state_, TNode<HeapObject>{phi_bb46_6}, TNode<IntPtrT>{tmp74}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp75, tmp76}, tmp53);
    compiler::CodeAssemblerExceptionHandlerLabel catch78__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch78__label);
    tmp77 = CallResolve_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_constructor}, TNode<Object>{phi_bb64_11}, TNode<Object>{tmp39});
    }
    if (catch78__label.is_used()) {
      compiler::CodeAssemblerLabel catch78_skip(&ca_);
      ca_.Goto(&catch78_skip);
      ca_.Bind(&catch78__label, &tmp79);
      ca_.Goto(&block67, phi_bb64_10, phi_bb64_11, phi_bb64_11);
      ca_.Bind(&catch78_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch81__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch81__label);
    tmp80 = CreatePromiseAnyRejectElementFunction_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp4}, TNode<Smi>{phi_bb64_10}, TNode<NativeContext>{tmp0});
    }
    if (catch81__label.is_used()) {
      compiler::CodeAssemblerLabel catch81_skip(&ca_);
      ca_.Goto(&catch81_skip);
      ca_.Bind(&catch81__label, &tmp82);
      ca_.Goto(&block68, phi_bb64_10, phi_bb64_11, phi_bb64_10);
      ca_.Bind(&catch81_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch84__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch84__label);
    tmp83 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp4}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot);
    }
    if (catch84__label.is_used()) {
      compiler::CodeAssemblerLabel catch84_skip(&ca_);
      ca_.Goto(&catch84_skip);
      ca_.Bind(&catch84__label, &tmp85);
      ca_.Goto(&block69, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch84_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch87__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch87__label);
    tmp86 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp83});
    }
    if (catch87__label.is_used()) {
      compiler::CodeAssemblerLabel catch87_skip(&ca_);
      ca_.Goto(&catch87_skip);
      ca_.Bind(&catch87__label, &tmp88);
      ca_.Goto(&block70, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch87_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch90__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch90__label);
    tmp89 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    }
    if (catch90__label.is_used()) {
      compiler::CodeAssemblerLabel catch90_skip(&ca_);
      ca_.Goto(&catch90_skip);
      ca_.Bind(&catch90__label, &tmp91);
      ca_.Goto(&block71, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch90_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch93__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch93__label);
    tmp92 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp86}, TNode<Smi>{tmp89});
    }
    if (catch93__label.is_used()) {
      compiler::CodeAssemblerLabel catch93_skip(&ca_);
      ca_.Goto(&catch93_skip);
      ca_.Bind(&catch93__label, &tmp94);
      ca_.Goto(&block72, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch93_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch95__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch95__label);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot, TNode<Object>{tmp92});
    }
    if (catch95__label.is_used()) {
      compiler::CodeAssemblerLabel catch95_skip(&ca_);
      ca_.Goto(&catch95_skip);
      ca_.Bind(&catch95__label, &tmp96);
      ca_.Goto(&block73, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch95_skip);
    }
    tmp97 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch99__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch99__label);
    tmp98 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp77}, TNode<Object>{tmp97});
    }
    if (catch99__label.is_used()) {
      compiler::CodeAssemblerLabel catch99_skip(&ca_);
      ca_.Goto(&catch99_skip);
      ca_.Bind(&catch99__label, &tmp100);
      ca_.Goto(&block74, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch99_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch102__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch102__label);
    tmp101 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    }
    if (catch102__label.is_used()) {
      compiler::CodeAssemblerLabel catch102_skip(&ca_);
      ca_.Goto(&catch102_skip);
      ca_.Bind(&catch102__label, &tmp103);
      ca_.Goto(&block75, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch102_skip);
    }
    tmp104 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_resultCapability, tmp101});
    compiler::CodeAssemblerExceptionHandlerLabel catch106__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch106__label);
    tmp105 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp104});
    }
    if (catch106__label.is_used()) {
      compiler::CodeAssemblerLabel catch106_skip(&ca_);
      ca_.Goto(&catch106_skip);
      ca_.Bind(&catch106__label, &tmp107);
      ca_.Goto(&block76, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch106_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch109__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch109__label);
    tmp108 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp98}, TNode<Object>{tmp77}, TNode<Object>{tmp105}, TNode<Object>{tmp80});
    }
    if (catch109__label.is_used()) {
      compiler::CodeAssemblerLabel catch109_skip(&ca_);
      ca_.Goto(&catch109_skip);
      ca_.Bind(&catch109__label, &tmp110);
      ca_.Goto(&block77, phi_bb64_10, phi_bb64_11);
      ca_.Bind(&catch109_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch112__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch112__label);
    tmp111 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    }
    if (catch112__label.is_used()) {
      compiler::CodeAssemblerLabel catch112_skip(&ca_);
      ca_.Goto(&catch112_skip);
      ca_.Bind(&catch112__label, &tmp113);
      ca_.Goto(&block78, phi_bb64_10, phi_bb64_11, phi_bb64_10, phi_bb64_10);
      ca_.Bind(&catch112_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch115__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch115__label);
    tmp114 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb64_10}, TNode<Smi>{tmp111});
    }
    if (catch115__label.is_used()) {
      compiler::CodeAssemblerLabel catch115_skip(&ca_);
      ca_.Goto(&catch115_skip);
      ca_.Bind(&catch115__label, &tmp116);
      ca_.Goto(&block79, phi_bb64_10, phi_bb64_11, phi_bb64_10);
      ca_.Bind(&catch115_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch118__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch118__label);
    tmp117 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch118__label.is_used()) {
      compiler::CodeAssemblerLabel catch118_skip(&ca_);
      ca_.Goto(&catch118_skip);
      ca_.Bind(&catch118__label, &tmp119);
      ca_.Goto(&block82, phi_bb64_11);
      ca_.Bind(&catch118_skip);
    }
    ca_.Branch(tmp117, &block83, std::vector<Node*>{phi_bb64_11}, &block84, std::vector<Node*>{phi_bb64_11});
  }

  TNode<Smi> phi_bb65_10;
  TNode<Object> phi_bb65_11;
  TNode<IntPtrT> phi_bb65_20;
  TNode<IntPtrT> phi_bb65_21;
  TNode<IntPtrT> phi_bb65_25;
  TNode<IntPtrT> phi_bb65_26;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_10, &phi_bb65_11, &phi_bb65_20, &phi_bb65_21, &phi_bb65_25, &phi_bb65_26);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb67_10;
  TNode<Object> phi_bb67_11;
  TNode<Object> phi_bb67_16;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_10, &phi_bb67_11, &phi_bb67_16);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb67_10, tmp79);
  }

  TNode<Smi> phi_bb68_10;
  TNode<Object> phi_bb68_11;
  TNode<Smi> phi_bb68_16;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_10, &phi_bb68_11, &phi_bb68_16);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb68_10, tmp82);
  }

  TNode<Smi> phi_bb69_10;
  TNode<Object> phi_bb69_11;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_10, &phi_bb69_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb69_10, tmp85);
  }

  TNode<Smi> phi_bb70_10;
  TNode<Object> phi_bb70_11;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_10, &phi_bb70_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb70_10, tmp88);
  }

  TNode<Smi> phi_bb71_10;
  TNode<Object> phi_bb71_11;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_10, &phi_bb71_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb71_10, tmp91);
  }

  TNode<Smi> phi_bb72_10;
  TNode<Object> phi_bb72_11;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_10, &phi_bb72_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb72_10, tmp94);
  }

  TNode<Smi> phi_bb73_10;
  TNode<Object> phi_bb73_11;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_10, &phi_bb73_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb73_10, tmp96);
  }

  TNode<Smi> phi_bb74_10;
  TNode<Object> phi_bb74_11;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_10, &phi_bb74_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb74_10, tmp100);
  }

  TNode<Smi> phi_bb75_10;
  TNode<Object> phi_bb75_11;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_10, &phi_bb75_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb75_10, tmp103);
  }

  TNode<Smi> phi_bb76_10;
  TNode<Object> phi_bb76_11;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_10, &phi_bb76_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb76_10, tmp107);
  }

  TNode<Smi> phi_bb77_10;
  TNode<Object> phi_bb77_11;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_10, &phi_bb77_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb77_10, tmp110);
  }

  TNode<Smi> phi_bb78_10;
  TNode<Object> phi_bb78_11;
  TNode<Smi> phi_bb78_19;
  TNode<Smi> phi_bb78_20;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_10, &phi_bb78_11, &phi_bb78_19, &phi_bb78_20);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb78_10, tmp113);
  }

  TNode<Smi> phi_bb79_10;
  TNode<Object> phi_bb79_11;
  TNode<Smi> phi_bb79_19;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_10, &phi_bb79_11, &phi_bb79_19);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, phi_bb79_10, tmp116);
  }

  TNode<Object> phi_bb82_11;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, tmp114, tmp119);
  }

  TNode<Object> phi_bb83_11;
  TNode<BoolT> tmp120;
      TNode<Object> tmp122;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch121__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch121__label);
    tmp120 = Is_JSPromise_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp108});
    }
    if (catch121__label.is_used()) {
      compiler::CodeAssemblerLabel catch121_skip(&ca_);
      ca_.Goto(&catch121_skip);
      ca_.Bind(&catch121__label, &tmp122);
      ca_.Goto(&block86, phi_bb83_11);
      ca_.Bind(&catch121_skip);
    }
    ca_.Goto(&block85, phi_bb83_11, tmp120);
  }

  TNode<Object> phi_bb86_11;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, tmp114, tmp122);
  }

  TNode<Object> phi_bb84_11;
  TNode<BoolT> tmp123;
      TNode<Object> tmp125;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch124__label);
    tmp123 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch124__label.is_used()) {
      compiler::CodeAssemblerLabel catch124_skip(&ca_);
      ca_.Goto(&catch124_skip);
      ca_.Bind(&catch124__label, &tmp125);
      ca_.Goto(&block87, phi_bb84_11);
      ca_.Bind(&catch124_skip);
    }
    ca_.Goto(&block85, phi_bb84_11, tmp123);
  }

  TNode<Object> phi_bb87_11;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, tmp114, tmp125);
  }

  TNode<Object> phi_bb85_11;
  TNode<BoolT> phi_bb85_20;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_11, &phi_bb85_20);
    ca_.Branch(phi_bb85_20, &block80, std::vector<Node*>{phi_bb85_11}, &block81, std::vector<Node*>{phi_bb85_11});
  }

  TNode<Object> phi_bb80_11;
  TNode<Symbol> tmp126;
  TNode<IntPtrT> tmp127;
      TNode<Object> tmp129;
  TNode<HeapObject> tmp130;
  TNode<Object> tmp131;
      TNode<Object> tmp133;
  TNode<Symbol> tmp134;
  TNode<Oddball> tmp135;
  TNode<Object> tmp136;
      TNode<Object> tmp138;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_11);
    tmp126 = kPromiseHandledBySymbol_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch128__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch128__label);
    tmp127 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    }
    if (catch128__label.is_used()) {
      compiler::CodeAssemblerLabel catch128_skip(&ca_);
      ca_.Goto(&catch128_skip);
      ca_.Bind(&catch128__label, &tmp129);
      ca_.Goto(&block88, phi_bb80_11);
      ca_.Bind(&catch128_skip);
    }
    tmp130 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_resultCapability, tmp127});
    compiler::CodeAssemblerExceptionHandlerLabel catch132__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch132__label);
    tmp131 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{p_context}, TNode<Object>{tmp108}, TNode<Object>{tmp126}, TNode<Object>{tmp130});
    }
    if (catch132__label.is_used()) {
      compiler::CodeAssemblerLabel catch132_skip(&ca_);
      ca_.Goto(&catch132_skip);
      ca_.Bind(&catch132__label, &tmp133);
      ca_.Goto(&block89, phi_bb80_11);
      ca_.Bind(&catch132_skip);
    }
    tmp134 = kPromiseForwardingHandlerSymbol_0(state_);
    tmp135 = True_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch137__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch137__label);
    tmp136 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{p_context}, TNode<Object>{tmp80}, TNode<Object>{tmp134}, TNode<Object>{tmp135});
    }
    if (catch137__label.is_used()) {
      compiler::CodeAssemblerLabel catch137_skip(&ca_);
      ca_.Goto(&catch137_skip);
      ca_.Bind(&catch137__label, &tmp138);
      ca_.Goto(&block90, phi_bb80_11);
      ca_.Bind(&catch137_skip);
    }
    ca_.Goto(&block81, phi_bb80_11);
  }

  TNode<Object> phi_bb88_11;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, tmp114, tmp129);
  }

  TNode<Object> phi_bb89_11;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, tmp114, tmp133);
  }

  TNode<Object> phi_bb90_11;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_11);
    ca_.Goto(&block6, phi_bb46_6, phi_bb46_7, tmp68, tmp114, tmp138);
  }

  TNode<Object> phi_bb81_11;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_11);
    ca_.Goto(&block23, phi_bb46_6, phi_bb46_7, tmp68, tmp114, phi_bb81_11);
  }

  TNode<FixedArray> phi_bb22_6;
  TNode<IntPtrT> phi_bb22_7;
  TNode<IntPtrT> phi_bb22_8;
  TNode<Smi> phi_bb22_10;
  TNode<Object> phi_bb22_11;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_6, &phi_bb22_7, &phi_bb22_8, &phi_bb22_10, &phi_bb22_11);
    ca_.Goto(&block3, phi_bb22_6, phi_bb22_7, phi_bb22_8, phi_bb22_10);
  }

  TNode<FixedArray> phi_bb6_6;
  TNode<IntPtrT> phi_bb6_7;
  TNode<IntPtrT> phi_bb6_8;
  TNode<Smi> phi_bb6_10;
  TNode<Object> phi_bb6_11;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6, &phi_bb6_7, &phi_bb6_8, &phi_bb6_10, &phi_bb6_11);
    IteratorCloseOnException_0(state_, TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{p_iteratorRecord.object}, TNode<Object>{p_iteratorRecord.next}});
    ca_.Goto(&block1, phi_bb6_11);
  }

  TNode<FixedArray> phi_bb3_6;
  TNode<IntPtrT> phi_bb3_7;
  TNode<IntPtrT> phi_bb3_8;
  TNode<Smi> phi_bb3_10;
  TNode<Object> tmp139;
  TNode<Smi> tmp140;
  TNode<Smi> tmp141;
  TNode<Smi> tmp142;
  TNode<IntPtrT> tmp143;
  TNode<FixedArray> tmp144;
  TNode<Smi> tmp145;
  TNode<BoolT> tmp146;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6, &phi_bb3_7, &phi_bb3_8, &phi_bb3_10);
    tmp139 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp4}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot);
    tmp140 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp139});
    tmp141 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp142 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp140}, TNode<Smi>{tmp141});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot, TNode<Object>{tmp142});
    tmp143 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp144 = ExtractFixedArray_0(state_, TNode<FixedArray>{phi_bb3_6}, TNode<IntPtrT>{tmp143}, TNode<IntPtrT>{phi_bb3_8}, TNode<IntPtrT>{phi_bb3_8});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp4}, PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementErrorsArraySlot, TNode<Object>{tmp144});
    tmp145 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp146 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp142}, TNode<Smi>{tmp145});
    ca_.Branch(tmp146, &block105, std::vector<Node*>{phi_bb3_6, phi_bb3_7, phi_bb3_8, phi_bb3_10}, &block106, std::vector<Node*>{phi_bb3_6, phi_bb3_7, phi_bb3_8, phi_bb3_10});
  }

  TNode<FixedArray> phi_bb105_6;
  TNode<IntPtrT> phi_bb105_7;
  TNode<IntPtrT> phi_bb105_8;
  TNode<Smi> phi_bb105_10;
  TNode<JSObject> tmp147;
  if (block105.is_used()) {
    ca_.Bind(&block105, &phi_bb105_6, &phi_bb105_7, &phi_bb105_8, &phi_bb105_10);
    tmp147 = ConstructAggregateError_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp144});
    ca_.Goto(&block1, tmp147);
  }

  TNode<FixedArray> phi_bb106_6;
  TNode<IntPtrT> phi_bb106_7;
  TNode<IntPtrT> phi_bb106_8;
  TNode<Smi> phi_bb106_10;
  TNode<IntPtrT> tmp148;
  TNode<HeapObject> tmp149;
  if (block106.is_used()) {
    ca_.Bind(&block106, &phi_bb106_6, &phi_bb106_7, &phi_bb106_8, &phi_bb106_10);
    tmp148 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp149 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_resultCapability, tmp148});
    ca_.Goto(&block107);
  }

  TNode<Object> phi_bb1_0;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0);
    *label_Reject_parameter_0 = phi_bb1_0;
    ca_.Goto(label_Reject);
  }

    ca_.Bind(&block107);
  return TNode<Object>{tmp149};
}

TF_BUILTIN(PromiseAny, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kIterable));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Promise.any");
  }

  TNode<Oddball> tmp2;
  TNode<PromiseCapability> tmp3;
  TNode<JSReceiver> tmp4;
  TNode<JSReceiver> tmp5;
  TNode<Object> tmp6;
      TNode<Object> tmp8;
  TNode<Object> tmp9;
    compiler::TypedCodeAssemblerVariable<Object> tmp11(&ca_);
      TNode<Object> tmp13;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = False_0(state_);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, parameter0, tmp0, tmp2));
    tmp4 = UnsafeCast_Constructor_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp0});
    compiler::CodeAssemblerExceptionHandlerLabel catch7__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch7__label);
    std::tie(tmp5, tmp6) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{parameter0}, TNode<Object>{parameter2}).Flatten();
    }
    if (catch7__label.is_used()) {
      compiler::CodeAssemblerLabel catch7_skip(&ca_);
      ca_.Goto(&catch7_skip);
      ca_.Bind(&catch7__label, &tmp8);
      ca_.Goto(&block13);
      ca_.Bind(&catch7_skip);
    }
    compiler::CodeAssemblerLabel label10(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch12__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch12__label);
    tmp9 = PerformPromiseAny_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp5}, TNode<Object>{tmp6}}, TNode<JSReceiver>{tmp4}, TNode<PromiseCapability>{tmp3}, &label10, &tmp11);
    }
    if (catch12__label.is_used()) {
      compiler::CodeAssemblerLabel catch12_skip(&ca_);
      ca_.Goto(&catch12_skip);
      ca_.Bind(&catch12__label, &tmp13);
      ca_.Goto(&block16);
      ca_.Bind(&catch12_skip);
    }
    ca_.Goto(&block14);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block15);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block12, ca_.Uninitialized<JSReceiver>(), ca_.Uninitialized<Object>(), tmp8);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block12, tmp5, tmp6, tmp13);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block10, tmp11.value());
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    CodeStubAssembler(state_).Return(tmp9);
  }

  TNode<JSReceiver> phi_bb12_6;
  TNode<Object> phi_bb12_7;
  TNode<Object> phi_bb12_8;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_6, &phi_bb12_7, &phi_bb12_8);
    ca_.Goto(&block10, phi_bb12_8);
  }

  TNode<Object> phi_bb10_6;
  TNode<IntPtrT> tmp14;
  TNode<Object> tmp15;
  TNode<JSReceiver> tmp16;
  TNode<Oddball> tmp17;
  TNode<Object> tmp18;
  TNode<Object> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<HeapObject> tmp21;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp15 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp3, tmp14});
    tmp16 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp15});
    tmp17 = Undefined_0(state_);
    tmp18 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{phi_bb10_6});
    tmp19 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp16}, TNode<Object>{tmp17}, TNode<Object>{tmp18});
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp20});
    CodeStubAssembler(state_).Return(tmp21);
  }
}

TNode<JSObject> ConstructAggregateError_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_errorsArray) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<JSAggregateError> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kAllPromisesRejected);
    tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kConstructInternalAggregateErrorHelper, p_context, tmp0)); 
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp1, tmp2}, p_errorsArray);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSObject>{tmp1};
}

TNode<BoolT> Is_JSPromise_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSPromise_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

TNode<BoolT> Is_Constructor_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Constructor_0(state_, TNode<HeapObject>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

}  // namespace internal
}  // namespace v8

