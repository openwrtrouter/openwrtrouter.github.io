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

TNode<Context> CreatePromiseAllResolveElementContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseCapability> p_capability, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Map> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Smi> tmp4;
  TNode<JSArray> tmp5;
  TNode<Context> tmp6;
  TNode<Smi> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_NativeContextSlot_constexpr_JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_, Context::Field::JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    tmp3 = CodeStubAssembler(state_).IntPtrConstant(0);
    tmp4 = CodeStubAssembler(state_).SmiConstant(0);
    tmp5 = CodeStubAssembler(state_).AllocateJSArray(ElementsKind::PACKED_ELEMENTS, TNode<Map>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<Smi>{tmp4});
    tmp6 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength);
    tmp7 = CodeStubAssembler(state_).SmiConstant(1);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp6}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp7});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp6}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot, TNode<Object>{p_capability});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp6}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot, TNode<Object>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Context>{tmp6};
}

TNode<JSFunction> CreatePromiseAllResolveElementFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_resolveElementContext, TNode<Smi> p_index, TNode<NativeContext> p_nativeContext, TNode<SharedFunctionInfo> p_resolveFunction) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Map> tmp2;
  TNode<JSFunction> tmp3;
  TNode<IntPtrT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp1});
    tmp3 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp2}, TNode<SharedFunctionInfo>{p_resolveFunction}, TNode<Context>{p_resolveElementContext});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp3, tmp4}, p_index);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TNode<JSFunction>{tmp3};
}

TNode<Context> CreatePromiseResolvingFunctionsContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_debugEvent, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Oddball> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::kPromiseContextLength);
    tmp1 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kPromiseSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<Object>{p_promise});
    tmp2 = False_0(state_);
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp3}, TNode<Object>{tmp2});
    tmp4 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kDebugEventSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp4}, TNode<Object>{p_debugEvent});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Context>{tmp0};
}

TNode<BoolT> IsPromiseThenLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Map> p_receiverMap) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{p_receiverMap});
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp4);
  }

  TNode<IntPtrT> tmp5;
  TNode<HeapObject> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<BoolT> tmp9;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_receiverMap, tmp5});
    tmp7 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp6}, TNode<Object>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp10);
  }

  TNode<BoolT> tmp11;
  TNode<BoolT> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp11 = CodeStubAssembler(state_).IsPromiseThenProtectorCellInvalid();
    tmp12 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp11});
    ca_.Goto(&block1, tmp12);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block8, phi_bb1_3);
  }

  TNode<BoolT> phi_bb8_3;
    ca_.Bind(&block8, &phi_bb8_3);
  return TNode<BoolT>{phi_bb8_3};
}

TF_BUILTIN(PromiseAll, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kIterable));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GeneratePromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<Object>{parameter2}, TorqueStructPromiseAllResolveElementFunctor_0{}, TorqueStructPromiseAllRejectElementFunctor_0{});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(PromiseAllSettled, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kIterable));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GeneratePromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, TNode<Object>{parameter2}, TorqueStructPromiseAllSettledResolveElementFunctor_0{}, TorqueStructPromiseAllSettledRejectElementFunctor_0{});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TNode<Object> GeneratePromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_iterable, TorqueStructPromiseAllResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllRejectElementFunctor_0 p_createRejectElementFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledOnNonObject, "Promise.all");
  }

  TNode<Oddball> tmp2;
  TNode<PromiseCapability> tmp3;
  TNode<JSReceiver> tmp4;
  TNode<Object> tmp5;
      TNode<Object> tmp7;
  TNode<Object> tmp8;
    compiler::TypedCodeAssemblerVariable<Object> tmp10(&ca_);
      TNode<Object> tmp12;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = False_0(state_);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, p_context, tmp0, tmp2));
    compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
    std::tie(tmp4, tmp5) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{p_context}, TNode<Object>{p_iterable}).Flatten();
    }
    if (catch6__label.is_used()) {
      compiler::CodeAssemblerLabel catch6_skip(&ca_);
      ca_.Goto(&catch6_skip);
      ca_.Bind(&catch6__label, &tmp7);
      ca_.Goto(&block10);
      ca_.Bind(&catch6_skip);
    }
    compiler::CodeAssemblerLabel label9(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch11__label);
    tmp8 = PerformPromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{tmp0}, TNode<PromiseCapability>{tmp3}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, TorqueStructPromiseAllResolveElementFunctor_0{}, TorqueStructPromiseAllRejectElementFunctor_0{}, &label9, &tmp10);
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      ca_.Bind(&catch11__label, &tmp12);
      ca_.Goto(&block13);
      ca_.Bind(&catch11_skip);
    }
    ca_.Goto(&block11);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block12);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block9, tmp7);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block9, tmp12);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block7, tmp10.value());
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1, tmp8);
  }

  TNode<Object> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.Goto(&block7, phi_bb9_5);
  }

  TNode<Object> phi_bb7_5;
  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Object> tmp15;
  TNode<Object> tmp16;
  TNode<Oddball> tmp17;
  TNode<Object> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<HeapObject> tmp20;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    tmp13 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb7_5});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp15 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp3, tmp14});
    tmp16 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp15});
    tmp17 = Undefined_0(state_);
    tmp18 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp16}, TNode<Object>{tmp17}, TNode<Object>{tmp13});
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp20 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp19});
    ca_.Goto(&block1, tmp20);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TNode<Object>{phi_bb1_3};
}

TNode<Object> GeneratePromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_iterable, TorqueStructPromiseAllSettledResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllSettledRejectElementFunctor_0 p_createRejectElementFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledOnNonObject, "Promise.all");
  }

  TNode<Oddball> tmp2;
  TNode<PromiseCapability> tmp3;
  TNode<JSReceiver> tmp4;
  TNode<Object> tmp5;
      TNode<Object> tmp7;
  TNode<Object> tmp8;
    compiler::TypedCodeAssemblerVariable<Object> tmp10(&ca_);
      TNode<Object> tmp12;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = False_0(state_);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, p_context, tmp0, tmp2));
    compiler::CodeAssemblerExceptionHandlerLabel catch6__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch6__label);
    std::tie(tmp4, tmp5) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{p_context}, TNode<Object>{p_iterable}).Flatten();
    }
    if (catch6__label.is_used()) {
      compiler::CodeAssemblerLabel catch6_skip(&ca_);
      ca_.Goto(&catch6_skip);
      ca_.Bind(&catch6__label, &tmp7);
      ca_.Goto(&block10);
      ca_.Bind(&catch6_skip);
    }
    compiler::CodeAssemblerLabel label9(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch11__label);
    tmp8 = PerformPromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{tmp0}, TNode<PromiseCapability>{tmp3}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, TorqueStructPromiseAllSettledResolveElementFunctor_0{}, TorqueStructPromiseAllSettledRejectElementFunctor_0{}, &label9, &tmp10);
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      ca_.Bind(&catch11__label, &tmp12);
      ca_.Goto(&block13);
      ca_.Bind(&catch11_skip);
    }
    ca_.Goto(&block11);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block12);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block9, tmp7);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block9, tmp12);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block7, tmp10.value());
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1, tmp8);
  }

  TNode<Object> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.Goto(&block7, phi_bb9_5);
  }

  TNode<Object> phi_bb7_5;
  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Object> tmp15;
  TNode<Object> tmp16;
  TNode<Oddball> tmp17;
  TNode<Object> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<HeapObject> tmp20;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    tmp13 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb7_5});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp15 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp3, tmp14});
    tmp16 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp15});
    tmp17 = Undefined_0(state_);
    tmp18 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp16}, TNode<Object>{tmp17}, TNode<Object>{tmp13});
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp20 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp19});
    ca_.Goto(&block1, tmp20);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
  return TNode<Object>{phi_bb1_3};
}

TNode<Object> PerformPromiseAll_PromiseAllResolveElementFunctor_PromiseAllRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_capability, TorqueStructIteratorRecord p_iter, TorqueStructPromiseAllResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllRejectElementFunctor_0 p_createRejectElementFunctor, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block50(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block59(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block60(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block64(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block65(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block69(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block70(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block72(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block73(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block75(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block76(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block77(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block78(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block81(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block85(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block86(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block79(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block87(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block88(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block89(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi, Smi> block90(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi> block91(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block93(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_capability, tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_capability, tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_capability, tmp5});
    tmp7 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp7, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  TNode<Symbol> tmp8;
  TNode<Oddball> tmp9;
  TNode<Object> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp8 = kPromiseForwardingHandlerSymbol_0(state_);
    tmp9 = True_0(state_);
    tmp10 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{p_context}, TNode<Object>{tmp6}, TNode<Object>{tmp8}, TNode<Object>{tmp9});
    ca_.Goto(&block4);
  }

  TNode<Context> tmp11;
  TNode<Smi> tmp12;
  TNode<Oddball> tmp13;
  TNode<BoolT> tmp14;
      TNode<Object> tmp16;
  TNode<BoolT> tmp17;
      TNode<Object> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp11 = CreatePromiseAllResolveElementContext_0(state_, TNode<Context>{p_context}, TNode<PromiseCapability>{p_capability}, TNode<NativeContext>{tmp0});
    tmp12 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp13 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
    tmp14 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{tmp0}, TNode<JSReceiver>{p_constructor});
    }
    if (catch15__label.is_used()) {
      compiler::CodeAssemblerLabel catch15_skip(&ca_);
      ca_.Goto(&catch15_skip);
      ca_.Bind(&catch15__label, &tmp16);
      ca_.Goto(&block11);
      ca_.Bind(&catch15_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch18__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch18__label);
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp14});
    }
    if (catch18__label.is_used()) {
      compiler::CodeAssemblerLabel catch18_skip(&ca_);
      ca_.Goto(&catch18_skip);
      ca_.Bind(&catch18__label, &tmp19);
      ca_.Goto(&block12);
      ca_.Bind(&catch18_skip);
    }
    ca_.Branch(tmp17, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{tmp13});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block8, tmp12, tmp13, tmp16);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block8, tmp12, tmp13, tmp19);
  }

  TNode<String> tmp20;
  TNode<Object> tmp21;
      TNode<Object> tmp23;
  TNode<JSReceiver> tmp24;
      TNode<Object> tmp27;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp20 = kResolveString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_constructor}, TNode<Object>{tmp20});
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      ca_.Bind(&catch22__label, &tmp23);
      ca_.Goto(&block13);
      ca_.Bind(&catch22_skip);
    }
    compiler::CodeAssemblerLabel label25(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp24 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp21}, &label25);
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block18);
      ca_.Bind(&catch26_skip);
    }
    ca_.Goto(&block16);
    if (label25.is_used()) {
      ca_.Bind(&label25);
      ca_.Goto(&block17);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block8, tmp12, tmp13, tmp23);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block8, tmp12, tmp13, tmp27);
  }

      TNode<Object> tmp29;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledNonCallable, "resolve");
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block19);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block10, tmp24);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block8, tmp12, tmp13, tmp29);
  }

  TNode<Object> phi_bb10_11;
  TNode<IntPtrT> tmp30;
      TNode<Object> tmp32;
  TNode<Object> tmp33;
      TNode<Object> tmp35;
  TNode<Map> tmp36;
      TNode<Object> tmp38;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch31__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch31__label);
    tmp30 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    }
    if (catch31__label.is_used()) {
      compiler::CodeAssemblerLabel catch31_skip(&ca_);
      ca_.Goto(&catch31_skip);
      ca_.Bind(&catch31__label, &tmp32);
      ca_.Goto(&block20, phi_bb10_11);
      ca_.Bind(&catch31_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch34__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch34__label);
    tmp33 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp30});
    }
    if (catch34__label.is_used()) {
      compiler::CodeAssemblerLabel catch34_skip(&ca_);
      ca_.Goto(&catch34_skip);
      ca_.Bind(&catch34__label, &tmp35);
      ca_.Goto(&block21, phi_bb10_11);
      ca_.Bind(&catch34_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
    tmp36 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp33});
    }
    if (catch37__label.is_used()) {
      compiler::CodeAssemblerLabel catch37_skip(&ca_);
      ca_.Goto(&catch37_skip);
      ca_.Bind(&catch37__label, &tmp38);
      ca_.Goto(&block22, phi_bb10_11);
      ca_.Bind(&catch37_skip);
    }
    ca_.Goto(&block25, tmp12, phi_bb10_11);
  }

  TNode<Object> phi_bb20_11;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11);
    ca_.Goto(&block8, tmp12, phi_bb20_11, tmp32);
  }

  TNode<Object> phi_bb21_11;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_11);
    ca_.Goto(&block8, tmp12, phi_bb21_11, tmp35);
  }

  TNode<Object> phi_bb22_11;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_11);
    ca_.Goto(&block8, tmp12, phi_bb22_11, tmp38);
  }

  TNode<Smi> phi_bb25_10;
  TNode<Object> phi_bb25_11;
  TNode<BoolT> tmp39;
      TNode<Object> tmp41;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_10, &phi_bb25_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp39 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block26, phi_bb25_10, phi_bb25_11);
      ca_.Bind(&catch40_skip);
    }
    ca_.Branch(tmp39, &block23, std::vector<Node*>{phi_bb25_10, phi_bb25_11}, &block24, std::vector<Node*>{phi_bb25_10, phi_bb25_11});
  }

  TNode<Smi> phi_bb26_10;
  TNode<Object> phi_bb26_11;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_10, &phi_bb26_11);
    ca_.Goto(&block8, phi_bb26_10, phi_bb26_11, tmp41);
  }

  TNode<Smi> phi_bb23_10;
  TNode<Object> phi_bb23_11;
  TNode<JSReceiver> tmp42;
      TNode<Object> tmp45;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_10, &phi_bb23_11);
    compiler::CodeAssemblerLabel label43(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch44__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch44__label);
    tmp42 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{p_iter.object}, TNode<Object>{p_iter.next}}, TNode<Map>{tmp36}, &label43);
    }
    if (catch44__label.is_used()) {
      compiler::CodeAssemblerLabel catch44_skip(&ca_);
      ca_.Goto(&catch44_skip);
      ca_.Bind(&catch44__label, &tmp45);
      ca_.Goto(&block33, phi_bb23_10, phi_bb23_11);
      ca_.Bind(&catch44_skip);
    }
    ca_.Goto(&block31, phi_bb23_10, phi_bb23_11);
    if (label43.is_used()) {
      ca_.Bind(&label43);
      ca_.Goto(&block32, phi_bb23_10, phi_bb23_11);
    }
  }

  TNode<Smi> phi_bb33_10;
  TNode<Object> phi_bb33_11;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_10, &phi_bb33_11);
    ca_.Goto(&block28, phi_bb33_10, phi_bb33_11, tmp45);
  }

  TNode<Smi> phi_bb32_10;
  TNode<Object> phi_bb32_11;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_10, &phi_bb32_11);
    ca_.Goto(&block5, phi_bb32_10, phi_bb32_11);
  }

  TNode<Smi> phi_bb31_10;
  TNode<Object> phi_bb31_11;
  TNode<Object> tmp46;
      TNode<Object> tmp48;
  TNode<Smi> tmp49;
      TNode<Object> tmp51;
  TNode<BoolT> tmp52;
      TNode<Object> tmp54;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_10, &phi_bb31_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch47__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch47__label);
    tmp46 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{p_context}, TNode<JSReceiver>{tmp42}, TNode<Map>{tmp36});
    }
    if (catch47__label.is_used()) {
      compiler::CodeAssemblerLabel catch47_skip(&ca_);
      ca_.Goto(&catch47_skip);
      ca_.Bind(&catch47__label, &tmp48);
      ca_.Goto(&block34, phi_bb31_10, phi_bb31_11);
      ca_.Bind(&catch47_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch50__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch50__label);
    tmp49 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyArray::HashField::kMax);
    }
    if (catch50__label.is_used()) {
      compiler::CodeAssemblerLabel catch50_skip(&ca_);
      ca_.Goto(&catch50_skip);
      ca_.Bind(&catch50__label, &tmp51);
      ca_.Goto(&block37, phi_bb31_10, phi_bb31_11, phi_bb31_10, phi_bb31_10);
      ca_.Bind(&catch50_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch53__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch53__label);
    tmp52 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb31_10}, TNode<Smi>{tmp49});
    }
    if (catch53__label.is_used()) {
      compiler::CodeAssemblerLabel catch53_skip(&ca_);
      ca_.Goto(&catch53_skip);
      ca_.Bind(&catch53__label, &tmp54);
      ca_.Goto(&block38, phi_bb31_10, phi_bb31_11, phi_bb31_10);
      ca_.Bind(&catch53_skip);
    }
    ca_.Branch(tmp52, &block35, std::vector<Node*>{phi_bb31_10, phi_bb31_11}, &block36, std::vector<Node*>{phi_bb31_10, phi_bb31_11});
  }

  TNode<Smi> phi_bb34_10;
  TNode<Object> phi_bb34_11;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_10, &phi_bb34_11);
    ca_.Goto(&block28, phi_bb34_10, phi_bb34_11, tmp48);
  }

  TNode<Smi> phi_bb28_10;
  TNode<Object> phi_bb28_11;
  TNode<Object> phi_bb28_14;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_10, &phi_bb28_11, &phi_bb28_14);
    ca_.Goto(&block1, phi_bb28_14);
  }

  TNode<Smi> phi_bb37_10;
  TNode<Object> phi_bb37_11;
  TNode<Smi> phi_bb37_14;
  TNode<Smi> phi_bb37_15;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_10, &phi_bb37_11, &phi_bb37_14, &phi_bb37_15);
    ca_.Goto(&block8, phi_bb37_10, phi_bb37_11, tmp51);
  }

  TNode<Smi> phi_bb38_10;
  TNode<Object> phi_bb38_11;
  TNode<Smi> phi_bb38_14;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_10, &phi_bb38_11, &phi_bb38_14);
    ca_.Goto(&block8, phi_bb38_10, phi_bb38_11, tmp54);
  }

  TNode<Smi> phi_bb35_10;
  TNode<Object> phi_bb35_11;
  TNode<Object> tmp55;
      TNode<Object> tmp57;
      TNode<Object> tmp59;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_10, &phi_bb35_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch56__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch56__label);
    tmp55 = FromConstexpr_Object_constexpr_string_0(state_, "all");
    }
    if (catch56__label.is_used()) {
      compiler::CodeAssemblerLabel catch56_skip(&ca_);
      ca_.Goto(&catch56_skip);
      ca_.Bind(&catch56__label, &tmp57);
      ca_.Goto(&block39, phi_bb35_10, phi_bb35_11);
      ca_.Bind(&catch56_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch58__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch58__label);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kTooManyElementsInPromiseCombinator, TNode<Object>{tmp55});
    }
    if (catch58__label.is_used()) {
      compiler::CodeAssemblerLabel catch58_skip(&ca_);
      ca_.Bind(&catch58__label, &tmp59);
      ca_.Goto(&block40, phi_bb35_10, phi_bb35_11);
    }
  }

  TNode<Smi> phi_bb39_10;
  TNode<Object> phi_bb39_11;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_10, &phi_bb39_11);
    ca_.Goto(&block8, phi_bb39_10, phi_bb39_11, tmp57);
  }

  TNode<Smi> phi_bb40_10;
  TNode<Object> phi_bb40_11;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_10, &phi_bb40_11);
    ca_.Goto(&block8, phi_bb40_10, phi_bb40_11, tmp59);
  }

  TNode<Smi> phi_bb36_10;
  TNode<Object> phi_bb36_11;
  TNode<Object> tmp60;
      TNode<Object> tmp62;
  TNode<Smi> tmp63;
      TNode<Object> tmp65;
  TNode<Smi> tmp66;
      TNode<Object> tmp68;
  TNode<Smi> tmp69;
      TNode<Object> tmp71;
      TNode<Object> tmp73;
  TNode<SharedFunctionInfo> tmp74;
  TNode<JSFunction> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Object> tmp77;
  TNode<JSReceiver> tmp78;
  TNode<Oddball> tmp79;
  TNode<BoolT> tmp80;
      TNode<Object> tmp82;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_10, &phi_bb36_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch61__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch61__label);
    tmp60 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    }
    if (catch61__label.is_used()) {
      compiler::CodeAssemblerLabel catch61_skip(&ca_);
      ca_.Goto(&catch61_skip);
      ca_.Bind(&catch61__label, &tmp62);
      ca_.Goto(&block41, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch61_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch64__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch64__label);
    tmp63 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp60});
    }
    if (catch64__label.is_used()) {
      compiler::CodeAssemblerLabel catch64_skip(&ca_);
      ca_.Goto(&catch64_skip);
      ca_.Bind(&catch64__label, &tmp65);
      ca_.Goto(&block42, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch64_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch67__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch67__label);
    tmp66 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    }
    if (catch67__label.is_used()) {
      compiler::CodeAssemblerLabel catch67_skip(&ca_);
      ca_.Goto(&catch67_skip);
      ca_.Bind(&catch67__label, &tmp68);
      ca_.Goto(&block43, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch67_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch70__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch70__label);
    tmp69 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp63}, TNode<Smi>{tmp66});
    }
    if (catch70__label.is_used()) {
      compiler::CodeAssemblerLabel catch70_skip(&ca_);
      ca_.Goto(&catch70_skip);
      ca_.Bind(&catch70__label, &tmp71);
      ca_.Goto(&block44, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch70_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch72__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch72__label);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp69});
    }
    if (catch72__label.is_used()) {
      compiler::CodeAssemblerLabel catch72_skip(&ca_);
      ca_.Goto(&catch72_skip);
      ca_.Bind(&catch72__label, &tmp73);
      ca_.Goto(&block45, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch72_skip);
    }
    tmp74 = CodeStubAssembler(state_).PromiseAllResolveElementSharedFunConstant();
    tmp75 = CreatePromiseAllResolveElementFunction_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp11}, TNode<Smi>{phi_bb36_10}, TNode<NativeContext>{tmp0}, TNode<SharedFunctionInfo>{tmp74});
    tmp76 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp77 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_capability, tmp76});
    tmp78 = UnsafeCast_Callable_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp77});
    tmp79 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch81__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch81__label);
    tmp80 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{phi_bb36_11}, TNode<HeapObject>{tmp79});
    }
    if (catch81__label.is_used()) {
      compiler::CodeAssemblerLabel catch81_skip(&ca_);
      ca_.Goto(&catch81_skip);
      ca_.Bind(&catch81__label, &tmp82);
      ca_.Goto(&block50, phi_bb36_10, phi_bb36_11, phi_bb36_11);
      ca_.Bind(&catch81_skip);
    }
    ca_.Branch(tmp80, &block51, std::vector<Node*>{phi_bb36_10, phi_bb36_11}, &block52, std::vector<Node*>{phi_bb36_10, phi_bb36_11});
  }

  TNode<Smi> phi_bb41_10;
  TNode<Object> phi_bb41_11;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_10, &phi_bb41_11);
    ca_.Goto(&block8, phi_bb41_10, phi_bb41_11, tmp62);
  }

  TNode<Smi> phi_bb42_10;
  TNode<Object> phi_bb42_11;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_10, &phi_bb42_11);
    ca_.Goto(&block8, phi_bb42_10, phi_bb42_11, tmp65);
  }

  TNode<Smi> phi_bb43_10;
  TNode<Object> phi_bb43_11;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_10, &phi_bb43_11);
    ca_.Goto(&block8, phi_bb43_10, phi_bb43_11, tmp68);
  }

  TNode<Smi> phi_bb44_10;
  TNode<Object> phi_bb44_11;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_10, &phi_bb44_11);
    ca_.Goto(&block8, phi_bb44_10, phi_bb44_11, tmp71);
  }

  TNode<Smi> phi_bb45_10;
  TNode<Object> phi_bb45_11;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_10, &phi_bb45_11);
    ca_.Goto(&block8, phi_bb45_10, phi_bb45_11, tmp73);
  }

  TNode<Smi> phi_bb50_10;
  TNode<Object> phi_bb50_11;
  TNode<Object> phi_bb50_17;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_10, &phi_bb50_11, &phi_bb50_17);
    ca_.Goto(&block8, phi_bb50_10, phi_bb50_11, tmp82);
  }

  TNode<Smi> phi_bb51_10;
  TNode<Object> phi_bb51_11;
  TNode<BoolT> tmp83;
      TNode<Object> tmp85;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_10, &phi_bb51_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch84__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch84__label);
    tmp83 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch84__label.is_used()) {
      compiler::CodeAssemblerLabel catch84_skip(&ca_);
      ca_.Goto(&catch84_skip);
      ca_.Bind(&catch84__label, &tmp85);
      ca_.Goto(&block54, phi_bb51_10, phi_bb51_11);
      ca_.Bind(&catch84_skip);
    }
    ca_.Goto(&block53, phi_bb51_10, phi_bb51_11, tmp83);
  }

  TNode<Smi> phi_bb54_10;
  TNode<Object> phi_bb54_11;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_10, &phi_bb54_11);
    ca_.Goto(&block8, phi_bb54_10, phi_bb54_11, tmp85);
  }

  TNode<Smi> phi_bb52_10;
  TNode<Object> phi_bb52_11;
  TNode<BoolT> tmp86;
      TNode<Object> tmp88;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_10, &phi_bb52_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch87__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch87__label);
    tmp86 = CodeStubAssembler(state_).NeedsAnyPromiseHooks();
    }
    if (catch87__label.is_used()) {
      compiler::CodeAssemblerLabel catch87_skip(&ca_);
      ca_.Goto(&catch87_skip);
      ca_.Bind(&catch87__label, &tmp88);
      ca_.Goto(&block55, phi_bb52_10, phi_bb52_11);
      ca_.Bind(&catch87_skip);
    }
    ca_.Goto(&block53, phi_bb52_10, phi_bb52_11, tmp86);
  }

  TNode<Smi> phi_bb55_10;
  TNode<Object> phi_bb55_11;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_10, &phi_bb55_11);
    ca_.Goto(&block8, phi_bb55_10, phi_bb55_11, tmp88);
  }

  TNode<Smi> phi_bb53_10;
  TNode<Object> phi_bb53_11;
  TNode<BoolT> phi_bb53_18;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_10, &phi_bb53_11, &phi_bb53_18);
    ca_.Branch(phi_bb53_18, &block56, std::vector<Node*>{phi_bb53_10, phi_bb53_11}, &block57, std::vector<Node*>{phi_bb53_10, phi_bb53_11});
  }

  TNode<Smi> phi_bb56_10;
  TNode<Object> phi_bb56_11;
  TNode<BoolT> tmp89;
      TNode<Object> tmp91;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_10, &phi_bb56_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch90__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch90__label);
    tmp89 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch90__label.is_used()) {
      compiler::CodeAssemblerLabel catch90_skip(&ca_);
      ca_.Goto(&catch90_skip);
      ca_.Bind(&catch90__label, &tmp91);
      ca_.Goto(&block59, phi_bb56_10, phi_bb56_11);
      ca_.Bind(&catch90_skip);
    }
    ca_.Goto(&block58, phi_bb56_10, phi_bb56_11, tmp89);
  }

  TNode<Smi> phi_bb59_10;
  TNode<Object> phi_bb59_11;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_10, &phi_bb59_11);
    ca_.Goto(&block8, phi_bb59_10, phi_bb59_11, tmp91);
  }

  TNode<Smi> phi_bb57_10;
  TNode<Object> phi_bb57_11;
  TNode<BoolT> tmp92;
      TNode<Object> tmp94;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_10, &phi_bb57_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch93__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch93__label);
    tmp92 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    }
    if (catch93__label.is_used()) {
      compiler::CodeAssemblerLabel catch93_skip(&ca_);
      ca_.Goto(&catch93_skip);
      ca_.Bind(&catch93__label, &tmp94);
      ca_.Goto(&block60, phi_bb57_10, phi_bb57_11);
      ca_.Bind(&catch93_skip);
    }
    ca_.Goto(&block58, phi_bb57_10, phi_bb57_11, tmp92);
  }

  TNode<Smi> phi_bb60_10;
  TNode<Object> phi_bb60_11;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_10, &phi_bb60_11);
    ca_.Goto(&block8, phi_bb60_10, phi_bb60_11, tmp94);
  }

  TNode<Smi> phi_bb58_10;
  TNode<Object> phi_bb58_11;
  TNode<BoolT> phi_bb58_18;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_10, &phi_bb58_11, &phi_bb58_18);
    ca_.Branch(phi_bb58_18, &block61, std::vector<Node*>{phi_bb58_10, phi_bb58_11}, &block62, std::vector<Node*>{phi_bb58_10, phi_bb58_11});
  }

  TNode<Smi> phi_bb61_10;
  TNode<Object> phi_bb61_11;
  TNode<BoolT> tmp95;
      TNode<Object> tmp97;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_10, &phi_bb61_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch96__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch96__label);
    tmp95 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch96__label.is_used()) {
      compiler::CodeAssemblerLabel catch96_skip(&ca_);
      ca_.Goto(&catch96_skip);
      ca_.Bind(&catch96__label, &tmp97);
      ca_.Goto(&block64, phi_bb61_10, phi_bb61_11);
      ca_.Bind(&catch96_skip);
    }
    ca_.Goto(&block63, phi_bb61_10, phi_bb61_11, tmp95);
  }

  TNode<Smi> phi_bb64_10;
  TNode<Object> phi_bb64_11;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_10, &phi_bb64_11);
    ca_.Goto(&block8, phi_bb64_10, phi_bb64_11, tmp97);
  }

  TNode<Smi> phi_bb62_10;
  TNode<Object> phi_bb62_11;
  TNode<BoolT> tmp98;
      TNode<Object> tmp100;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_10, &phi_bb62_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch99__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch99__label);
    tmp98 = Is_Smi_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp46});
    }
    if (catch99__label.is_used()) {
      compiler::CodeAssemblerLabel catch99_skip(&ca_);
      ca_.Goto(&catch99_skip);
      ca_.Bind(&catch99__label, &tmp100);
      ca_.Goto(&block65, phi_bb62_10, phi_bb62_11);
      ca_.Bind(&catch99_skip);
    }
    ca_.Goto(&block63, phi_bb62_10, phi_bb62_11, tmp98);
  }

  TNode<Smi> phi_bb65_10;
  TNode<Object> phi_bb65_11;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_10, &phi_bb65_11);
    ca_.Goto(&block8, phi_bb65_10, phi_bb65_11, tmp100);
  }

  TNode<Smi> phi_bb63_10;
  TNode<Object> phi_bb63_11;
  TNode<BoolT> phi_bb63_18;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_10, &phi_bb63_11, &phi_bb63_18);
    ca_.Branch(phi_bb63_18, &block66, std::vector<Node*>{phi_bb63_10, phi_bb63_11}, &block67, std::vector<Node*>{phi_bb63_10, phi_bb63_11});
  }

  TNode<Smi> phi_bb66_10;
  TNode<Object> phi_bb66_11;
  TNode<BoolT> tmp101;
      TNode<Object> tmp103;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_10, &phi_bb66_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch102__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch102__label);
    tmp101 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch102__label.is_used()) {
      compiler::CodeAssemblerLabel catch102_skip(&ca_);
      ca_.Goto(&catch102_skip);
      ca_.Bind(&catch102__label, &tmp103);
      ca_.Goto(&block69, phi_bb66_10, phi_bb66_11);
      ca_.Bind(&catch102_skip);
    }
    ca_.Goto(&block68, phi_bb66_10, phi_bb66_11, tmp101);
  }

  TNode<Smi> phi_bb69_10;
  TNode<Object> phi_bb69_11;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_10, &phi_bb69_11);
    ca_.Goto(&block8, phi_bb69_10, phi_bb69_11, tmp103);
  }

  TNode<Smi> phi_bb67_10;
  TNode<Object> phi_bb67_11;
  TNode<HeapObject> tmp104;
      TNode<Object> tmp106;
  TNode<IntPtrT> tmp107;
      TNode<Object> tmp109;
  TNode<Map> tmp110;
  TNode<BoolT> tmp111;
      TNode<Object> tmp113;
  TNode<BoolT> tmp114;
      TNode<Object> tmp116;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_10, &phi_bb67_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch105__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch105__label);
    tmp104 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp46});
    }
    if (catch105__label.is_used()) {
      compiler::CodeAssemblerLabel catch105_skip(&ca_);
      ca_.Goto(&catch105_skip);
      ca_.Bind(&catch105__label, &tmp106);
      ca_.Goto(&block70, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch105_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch108__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch108__label);
    tmp107 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    }
    if (catch108__label.is_used()) {
      compiler::CodeAssemblerLabel catch108_skip(&ca_);
      ca_.Goto(&catch108_skip);
      ca_.Bind(&catch108__label, &tmp109);
      ca_.Goto(&block71, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch108_skip);
    }
    tmp110 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp104, tmp107});
    compiler::CodeAssemblerExceptionHandlerLabel catch112__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch112__label);
    tmp111 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{tmp0}, TNode<Map>{tmp110});
    }
    if (catch112__label.is_used()) {
      compiler::CodeAssemblerLabel catch112_skip(&ca_);
      ca_.Goto(&catch112_skip);
      ca_.Bind(&catch112__label, &tmp113);
      ca_.Goto(&block72, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch112_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch115__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch115__label);
    tmp114 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp111});
    }
    if (catch115__label.is_used()) {
      compiler::CodeAssemblerLabel catch115_skip(&ca_);
      ca_.Goto(&catch115_skip);
      ca_.Bind(&catch115__label, &tmp116);
      ca_.Goto(&block73, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch115_skip);
    }
    ca_.Goto(&block68, phi_bb67_10, phi_bb67_11, tmp114);
  }

  TNode<Smi> phi_bb70_10;
  TNode<Object> phi_bb70_11;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_10, &phi_bb70_11);
    ca_.Goto(&block8, phi_bb70_10, phi_bb70_11, tmp106);
  }

  TNode<Smi> phi_bb71_10;
  TNode<Object> phi_bb71_11;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_10, &phi_bb71_11);
    ca_.Goto(&block8, phi_bb71_10, phi_bb71_11, tmp109);
  }

  TNode<Smi> phi_bb72_10;
  TNode<Object> phi_bb72_11;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_10, &phi_bb72_11);
    ca_.Goto(&block8, phi_bb72_10, phi_bb72_11, tmp113);
  }

  TNode<Smi> phi_bb73_10;
  TNode<Object> phi_bb73_11;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_10, &phi_bb73_11);
    ca_.Goto(&block8, phi_bb73_10, phi_bb73_11, tmp116);
  }

  TNode<Smi> phi_bb68_10;
  TNode<Object> phi_bb68_11;
  TNode<BoolT> phi_bb68_18;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_10, &phi_bb68_11, &phi_bb68_18);
    ca_.Branch(phi_bb68_18, &block48, std::vector<Node*>{phi_bb68_10, phi_bb68_11}, &block49, std::vector<Node*>{phi_bb68_10, phi_bb68_11});
  }

  TNode<Smi> phi_bb48_10;
  TNode<Object> phi_bb48_11;
  TNode<JSReceiver> tmp117;
      TNode<Object> tmp119;
  TNode<Object> tmp120;
      TNode<Object> tmp122;
  TNode<String> tmp123;
  TNode<Object> tmp124;
      TNode<Object> tmp126;
  TNode<Object> tmp127;
      TNode<Object> tmp129;
  TNode<BoolT> tmp130;
      TNode<Object> tmp132;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_10, &phi_bb48_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch118__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch118__label);
    tmp117 = UnsafeCast_Constructor_0(state_, TNode<Context>{p_context}, TNode<Object>{p_constructor});
    }
    if (catch118__label.is_used()) {
      compiler::CodeAssemblerLabel catch118_skip(&ca_);
      ca_.Goto(&catch118_skip);
      ca_.Bind(&catch118__label, &tmp119);
      ca_.Goto(&block75, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch118_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch121__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch121__label);
    tmp120 = CallResolve_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{tmp117}, TNode<Object>{phi_bb48_11}, TNode<Object>{tmp46});
    }
    if (catch121__label.is_used()) {
      compiler::CodeAssemblerLabel catch121_skip(&ca_);
      ca_.Goto(&catch121_skip);
      ca_.Bind(&catch121__label, &tmp122);
      ca_.Goto(&block76, phi_bb48_10, phi_bb48_11, phi_bb48_11);
      ca_.Bind(&catch121_skip);
    }
    tmp123 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch125__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch125__label);
    tmp124 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp120}, TNode<Object>{tmp123});
    }
    if (catch125__label.is_used()) {
      compiler::CodeAssemblerLabel catch125_skip(&ca_);
      ca_.Goto(&catch125_skip);
      ca_.Bind(&catch125__label, &tmp126);
      ca_.Goto(&block77, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch125_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch128__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch128__label);
    tmp127 = CodeStubAssembler(state_).Call(TNode<Context>{tmp0}, TNode<Object>{tmp124}, TNode<Object>{tmp120}, TNode<Object>{tmp75}, TNode<Object>{tmp78});
    }
    if (catch128__label.is_used()) {
      compiler::CodeAssemblerLabel catch128_skip(&ca_);
      ca_.Goto(&catch128_skip);
      ca_.Bind(&catch128__label, &tmp129);
      ca_.Goto(&block78, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch128_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch131__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch131__label);
    tmp130 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch131__label.is_used()) {
      compiler::CodeAssemblerLabel catch131_skip(&ca_);
      ca_.Goto(&catch131_skip);
      ca_.Bind(&catch131__label, &tmp132);
      ca_.Goto(&block81, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch131_skip);
    }
    ca_.Branch(tmp130, &block82, std::vector<Node*>{phi_bb48_10, phi_bb48_11}, &block83, std::vector<Node*>{phi_bb48_10, phi_bb48_11});
  }

  TNode<Smi> phi_bb75_10;
  TNode<Object> phi_bb75_11;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_10, &phi_bb75_11);
    ca_.Goto(&block8, phi_bb75_10, phi_bb75_11, tmp119);
  }

  TNode<Smi> phi_bb76_10;
  TNode<Object> phi_bb76_11;
  TNode<Object> phi_bb76_18;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_10, &phi_bb76_11, &phi_bb76_18);
    ca_.Goto(&block8, phi_bb76_10, phi_bb76_11, tmp122);
  }

  TNode<Smi> phi_bb77_10;
  TNode<Object> phi_bb77_11;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_10, &phi_bb77_11);
    ca_.Goto(&block8, phi_bb77_10, phi_bb77_11, tmp126);
  }

  TNode<Smi> phi_bb78_10;
  TNode<Object> phi_bb78_11;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_10, &phi_bb78_11);
    ca_.Goto(&block8, phi_bb78_10, phi_bb78_11, tmp129);
  }

  TNode<Smi> phi_bb81_10;
  TNode<Object> phi_bb81_11;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_10, &phi_bb81_11);
    ca_.Goto(&block8, phi_bb81_10, phi_bb81_11, tmp132);
  }

  TNode<Smi> phi_bb82_10;
  TNode<Object> phi_bb82_11;
  TNode<BoolT> tmp133;
      TNode<Object> tmp135;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_10, &phi_bb82_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch134__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch134__label);
    tmp133 = Is_JSPromise_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp127});
    }
    if (catch134__label.is_used()) {
      compiler::CodeAssemblerLabel catch134_skip(&ca_);
      ca_.Goto(&catch134_skip);
      ca_.Bind(&catch134__label, &tmp135);
      ca_.Goto(&block85, phi_bb82_10, phi_bb82_11);
      ca_.Bind(&catch134_skip);
    }
    ca_.Goto(&block84, phi_bb82_10, phi_bb82_11, tmp133);
  }

  TNode<Smi> phi_bb85_10;
  TNode<Object> phi_bb85_11;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_10, &phi_bb85_11);
    ca_.Goto(&block8, phi_bb85_10, phi_bb85_11, tmp135);
  }

  TNode<Smi> phi_bb83_10;
  TNode<Object> phi_bb83_11;
  TNode<BoolT> tmp136;
      TNode<Object> tmp138;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_10, &phi_bb83_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch137__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch137__label);
    tmp136 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch137__label.is_used()) {
      compiler::CodeAssemblerLabel catch137_skip(&ca_);
      ca_.Goto(&catch137_skip);
      ca_.Bind(&catch137__label, &tmp138);
      ca_.Goto(&block86, phi_bb83_10, phi_bb83_11);
      ca_.Bind(&catch137_skip);
    }
    ca_.Goto(&block84, phi_bb83_10, phi_bb83_11, tmp136);
  }

  TNode<Smi> phi_bb86_10;
  TNode<Object> phi_bb86_11;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_10, &phi_bb86_11);
    ca_.Goto(&block8, phi_bb86_10, phi_bb86_11, tmp138);
  }

  TNode<Smi> phi_bb84_10;
  TNode<Object> phi_bb84_11;
  TNode<BoolT> phi_bb84_21;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_10, &phi_bb84_11, &phi_bb84_21);
    ca_.Branch(phi_bb84_21, &block79, std::vector<Node*>{phi_bb84_10, phi_bb84_11}, &block80, std::vector<Node*>{phi_bb84_10, phi_bb84_11});
  }

  TNode<Smi> phi_bb79_10;
  TNode<Object> phi_bb79_11;
  TNode<Symbol> tmp139;
  TNode<Object> tmp140;
      TNode<Object> tmp142;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_10, &phi_bb79_11);
    tmp139 = kPromiseHandledBySymbol_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch141__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch141__label);
    tmp140 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{p_context}, TNode<Object>{tmp127}, TNode<Object>{tmp139}, TNode<Object>{tmp2});
    }
    if (catch141__label.is_used()) {
      compiler::CodeAssemblerLabel catch141_skip(&ca_);
      ca_.Goto(&catch141_skip);
      ca_.Bind(&catch141__label, &tmp142);
      ca_.Goto(&block87, phi_bb79_10, phi_bb79_11);
      ca_.Bind(&catch141_skip);
    }
    ca_.Goto(&block80, phi_bb79_10, phi_bb79_11);
  }

  TNode<Smi> phi_bb87_10;
  TNode<Object> phi_bb87_11;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_10, &phi_bb87_11);
    ca_.Goto(&block8, phi_bb87_10, phi_bb87_11, tmp142);
  }

  TNode<Smi> phi_bb80_10;
  TNode<Object> phi_bb80_11;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_10, &phi_bb80_11);
    ca_.Goto(&block74, phi_bb80_10, phi_bb80_11);
  }

  TNode<Smi> phi_bb49_10;
  TNode<Object> phi_bb49_11;
  TNode<JSPromise> tmp143;
      TNode<Object> tmp145;
  TNode<Oddball> tmp146;
      TNode<Object> tmp148;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_10, &phi_bb49_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch144__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch144__label);
    tmp143 = UnsafeCast_JSPromise_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp46});
    }
    if (catch144__label.is_used()) {
      compiler::CodeAssemblerLabel catch144_skip(&ca_);
      ca_.Goto(&catch144_skip);
      ca_.Bind(&catch144__label, &tmp145);
      ca_.Goto(&block88, phi_bb49_10, phi_bb49_11);
      ca_.Bind(&catch144_skip);
    }
    tmp146 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch147__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch147__label);
    PerformPromiseThenImpl_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{tmp143}, TNode<HeapObject>{tmp75}, TNode<HeapObject>{tmp78}, TNode<HeapObject>{tmp146});
    }
    if (catch147__label.is_used()) {
      compiler::CodeAssemblerLabel catch147_skip(&ca_);
      ca_.Goto(&catch147_skip);
      ca_.Bind(&catch147__label, &tmp148);
      ca_.Goto(&block89, phi_bb49_10, phi_bb49_11);
      ca_.Bind(&catch147_skip);
    }
    ca_.Goto(&block74, phi_bb49_10, phi_bb49_11);
  }

  TNode<Smi> phi_bb88_10;
  TNode<Object> phi_bb88_11;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_10, &phi_bb88_11);
    ca_.Goto(&block8, phi_bb88_10, phi_bb88_11, tmp145);
  }

  TNode<Smi> phi_bb89_10;
  TNode<Object> phi_bb89_11;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_10, &phi_bb89_11);
    ca_.Goto(&block8, phi_bb89_10, phi_bb89_11, tmp148);
  }

  TNode<Smi> phi_bb74_10;
  TNode<Object> phi_bb74_11;
  TNode<Smi> tmp149;
      TNode<Object> tmp151;
  TNode<Smi> tmp152;
      TNode<Object> tmp154;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_10, &phi_bb74_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch150__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch150__label);
    tmp149 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    }
    if (catch150__label.is_used()) {
      compiler::CodeAssemblerLabel catch150_skip(&ca_);
      ca_.Goto(&catch150_skip);
      ca_.Bind(&catch150__label, &tmp151);
      ca_.Goto(&block90, phi_bb74_10, phi_bb74_11, phi_bb74_10, phi_bb74_10);
      ca_.Bind(&catch150_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch153__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch153__label);
    tmp152 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb74_10}, TNode<Smi>{tmp149});
    }
    if (catch153__label.is_used()) {
      compiler::CodeAssemblerLabel catch153_skip(&ca_);
      ca_.Goto(&catch153_skip);
      ca_.Bind(&catch153__label, &tmp154);
      ca_.Goto(&block91, phi_bb74_10, phi_bb74_11, phi_bb74_10);
      ca_.Bind(&catch153_skip);
    }
    ca_.Goto(&block25, tmp152, phi_bb74_11);
  }

  TNode<Smi> phi_bb90_10;
  TNode<Object> phi_bb90_11;
  TNode<Smi> phi_bb90_17;
  TNode<Smi> phi_bb90_18;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_10, &phi_bb90_11, &phi_bb90_17, &phi_bb90_18);
    ca_.Goto(&block8, phi_bb90_10, phi_bb90_11, tmp151);
  }

  TNode<Smi> phi_bb91_10;
  TNode<Object> phi_bb91_11;
  TNode<Smi> phi_bb91_17;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_10, &phi_bb91_11, &phi_bb91_17);
    ca_.Goto(&block8, phi_bb91_10, phi_bb91_11, tmp154);
  }

  TNode<Smi> phi_bb24_10;
  TNode<Object> phi_bb24_11;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_10, &phi_bb24_11);
    ca_.Goto(&block5, phi_bb24_10, phi_bb24_11);
  }

  TNode<Smi> phi_bb8_10;
  TNode<Object> phi_bb8_11;
  TNode<Object> phi_bb8_12;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_10, &phi_bb8_11, &phi_bb8_12);
    IteratorCloseOnException_0(state_, TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{p_iter.object}, TNode<Object>{p_iter.next}});
    ca_.Goto(&block1, phi_bb8_12);
  }

  TNode<Smi> phi_bb5_10;
  TNode<Object> phi_bb5_11;
  TNode<Object> tmp155;
  TNode<Smi> tmp156;
  TNode<Smi> tmp157;
  TNode<Smi> tmp158;
  TNode<Smi> tmp159;
  TNode<BoolT> tmp160;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_10, &phi_bb5_11);
    tmp155 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp156 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp155});
    tmp157 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp158 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp156}, TNode<Smi>{tmp157});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp158});
    tmp159 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp160 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp158}, TNode<Smi>{tmp159});
    ca_.Branch(tmp160, &block92, std::vector<Node*>{phi_bb5_10, phi_bb5_11}, &block93, std::vector<Node*>{phi_bb5_10, phi_bb5_11});
  }

  TNode<Smi> phi_bb92_10;
  TNode<Object> phi_bb92_11;
  TNode<Object> tmp161;
  TNode<JSArray> tmp162;
  TNode<IntPtrT> tmp163;
  TNode<FixedArrayBase> tmp164;
  TNode<FixedArray> tmp165;
  TNode<IntPtrT> tmp166;
  TNode<IntPtrT> tmp167;
  TNode<BoolT> tmp168;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_10, &phi_bb92_11);
    tmp161 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp162 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp161});
    tmp163 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp164 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp162, tmp163});
    tmp165 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp164});
    tmp166 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp165});
    tmp167 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{phi_bb92_10});
    tmp168 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp166}, TNode<IntPtrT>{tmp167});
    ca_.Branch(tmp168, &block95, std::vector<Node*>{phi_bb92_10, phi_bb92_11}, &block96, std::vector<Node*>{phi_bb92_10, phi_bb92_11});
  }

  TNode<Smi> phi_bb95_10;
  TNode<Object> phi_bb95_11;
  TNode<IntPtrT> tmp169;
  TNode<IntPtrT> tmp170;
  TNode<FixedArray> tmp171;
  if (block95.is_used()) {
    ca_.Bind(&block95, &phi_bb95_10, &phi_bb95_11);
    tmp169 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp170 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp171 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp165}, TNode<IntPtrT>{tmp170}, TNode<IntPtrT>{tmp166}, TNode<IntPtrT>{tmp167});
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp162, tmp169}, tmp171);
    ca_.Goto(&block96, phi_bb95_10, phi_bb95_11);
  }

  TNode<Smi> phi_bb96_10;
  TNode<Object> phi_bb96_11;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_10, &phi_bb96_11);
    ca_.Goto(&block94, phi_bb96_10, phi_bb96_11);
  }

  TNode<Smi> phi_bb93_10;
  TNode<Object> phi_bb93_11;
  TNode<Object> tmp172;
  TNode<Object> tmp173;
  TNode<Object> tmp174;
  TNode<Oddball> tmp175;
  TNode<Object> tmp176;
  if (block93.is_used()) {
    ca_.Bind(&block93, &phi_bb93_10, &phi_bb93_11);
    tmp172 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp173 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp172});
    tmp174 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    tmp175 = Undefined_0(state_);
    tmp176 = CodeStubAssembler(state_).Call(TNode<Context>{tmp0}, TNode<Object>{tmp174}, TNode<Object>{tmp175}, TNode<Object>{tmp173});
    ca_.Goto(&block94, phi_bb93_10, phi_bb93_11);
  }

  TNode<Smi> phi_bb94_10;
  TNode<Object> phi_bb94_11;
  if (block94.is_used()) {
    ca_.Bind(&block94, &phi_bb94_10, &phi_bb94_11);
    ca_.Goto(&block101);
  }

  TNode<Object> phi_bb1_0;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0);
    *label_Reject_parameter_0 = phi_bb1_0;
    ca_.Goto(label_Reject);
  }

    ca_.Bind(&block101);
  return TNode<Object>{tmp2};
}

TNode<Object> PerformPromiseAll_PromiseAllSettledResolveElementFunctor_PromiseAllSettledRejectElementFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<PromiseCapability> p_capability, TorqueStructIteratorRecord p_iter, TorqueStructPromiseAllSettledResolveElementFunctor_0 p_createResolveElementFunctor, TorqueStructPromiseAllSettledRejectElementFunctor_0 p_createRejectElementFunctor, compiler::CodeAssemblerLabel* label_Reject, compiler::TypedCodeAssemblerVariable<Object>* label_Reject_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block34(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi> block38(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block50(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block59(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block60(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block64(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block65(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block69(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block70(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block71(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block72(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block73(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block75(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block76(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block77(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block78(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block81(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block85(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block86(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, BoolT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block79(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block87(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block88(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block89(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi, Smi> block90(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Smi> block91(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block93(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_capability, tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_capability, tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_capability, tmp5});
    tmp7 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp7, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  TNode<Symbol> tmp8;
  TNode<Oddball> tmp9;
  TNode<Object> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp8 = kPromiseForwardingHandlerSymbol_0(state_);
    tmp9 = True_0(state_);
    tmp10 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{p_context}, TNode<Object>{tmp6}, TNode<Object>{tmp8}, TNode<Object>{tmp9});
    ca_.Goto(&block4);
  }

  TNode<Context> tmp11;
  TNode<Smi> tmp12;
  TNode<Oddball> tmp13;
  TNode<BoolT> tmp14;
      TNode<Object> tmp16;
  TNode<BoolT> tmp17;
      TNode<Object> tmp19;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp11 = CreatePromiseAllResolveElementContext_0(state_, TNode<Context>{p_context}, TNode<PromiseCapability>{p_capability}, TNode<NativeContext>{tmp0});
    tmp12 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp13 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
    tmp14 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{tmp0}, TNode<JSReceiver>{p_constructor});
    }
    if (catch15__label.is_used()) {
      compiler::CodeAssemblerLabel catch15_skip(&ca_);
      ca_.Goto(&catch15_skip);
      ca_.Bind(&catch15__label, &tmp16);
      ca_.Goto(&block11);
      ca_.Bind(&catch15_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch18__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch18__label);
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp14});
    }
    if (catch18__label.is_used()) {
      compiler::CodeAssemblerLabel catch18_skip(&ca_);
      ca_.Goto(&catch18_skip);
      ca_.Bind(&catch18__label, &tmp19);
      ca_.Goto(&block12);
      ca_.Bind(&catch18_skip);
    }
    ca_.Branch(tmp17, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{tmp13});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block8, tmp12, tmp13, tmp16);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block8, tmp12, tmp13, tmp19);
  }

  TNode<String> tmp20;
  TNode<Object> tmp21;
      TNode<Object> tmp23;
  TNode<JSReceiver> tmp24;
      TNode<Object> tmp27;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp20 = kResolveString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch22__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch22__label);
    tmp21 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_constructor}, TNode<Object>{tmp20});
    }
    if (catch22__label.is_used()) {
      compiler::CodeAssemblerLabel catch22_skip(&ca_);
      ca_.Goto(&catch22_skip);
      ca_.Bind(&catch22__label, &tmp23);
      ca_.Goto(&block13);
      ca_.Bind(&catch22_skip);
    }
    compiler::CodeAssemblerLabel label25(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp24 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp21}, &label25);
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block18);
      ca_.Bind(&catch26_skip);
    }
    ca_.Goto(&block16);
    if (label25.is_used()) {
      ca_.Bind(&label25);
      ca_.Goto(&block17);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block8, tmp12, tmp13, tmp23);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block8, tmp12, tmp13, tmp27);
  }

      TNode<Object> tmp29;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    compiler::CodeAssemblerExceptionHandlerLabel catch28__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch28__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledNonCallable, "resolve");
    }
    if (catch28__label.is_used()) {
      compiler::CodeAssemblerLabel catch28_skip(&ca_);
      ca_.Bind(&catch28__label, &tmp29);
      ca_.Goto(&block19);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block10, tmp24);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block8, tmp12, tmp13, tmp29);
  }

  TNode<Object> phi_bb10_11;
  TNode<IntPtrT> tmp30;
      TNode<Object> tmp32;
  TNode<Object> tmp33;
      TNode<Object> tmp35;
  TNode<Map> tmp36;
      TNode<Object> tmp38;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch31__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch31__label);
    tmp30 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    }
    if (catch31__label.is_used()) {
      compiler::CodeAssemblerLabel catch31_skip(&ca_);
      ca_.Goto(&catch31_skip);
      ca_.Bind(&catch31__label, &tmp32);
      ca_.Goto(&block20, phi_bb10_11);
      ca_.Bind(&catch31_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch34__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch34__label);
    tmp33 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp30});
    }
    if (catch34__label.is_used()) {
      compiler::CodeAssemblerLabel catch34_skip(&ca_);
      ca_.Goto(&catch34_skip);
      ca_.Bind(&catch34__label, &tmp35);
      ca_.Goto(&block21, phi_bb10_11);
      ca_.Bind(&catch34_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch37__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch37__label);
    tmp36 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp33});
    }
    if (catch37__label.is_used()) {
      compiler::CodeAssemblerLabel catch37_skip(&ca_);
      ca_.Goto(&catch37_skip);
      ca_.Bind(&catch37__label, &tmp38);
      ca_.Goto(&block22, phi_bb10_11);
      ca_.Bind(&catch37_skip);
    }
    ca_.Goto(&block25, tmp12, phi_bb10_11);
  }

  TNode<Object> phi_bb20_11;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11);
    ca_.Goto(&block8, tmp12, phi_bb20_11, tmp32);
  }

  TNode<Object> phi_bb21_11;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_11);
    ca_.Goto(&block8, tmp12, phi_bb21_11, tmp35);
  }

  TNode<Object> phi_bb22_11;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_11);
    ca_.Goto(&block8, tmp12, phi_bb22_11, tmp38);
  }

  TNode<Smi> phi_bb25_10;
  TNode<Object> phi_bb25_11;
  TNode<BoolT> tmp39;
      TNode<Object> tmp41;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_10, &phi_bb25_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch40__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch40__label);
    tmp39 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch40__label.is_used()) {
      compiler::CodeAssemblerLabel catch40_skip(&ca_);
      ca_.Goto(&catch40_skip);
      ca_.Bind(&catch40__label, &tmp41);
      ca_.Goto(&block26, phi_bb25_10, phi_bb25_11);
      ca_.Bind(&catch40_skip);
    }
    ca_.Branch(tmp39, &block23, std::vector<Node*>{phi_bb25_10, phi_bb25_11}, &block24, std::vector<Node*>{phi_bb25_10, phi_bb25_11});
  }

  TNode<Smi> phi_bb26_10;
  TNode<Object> phi_bb26_11;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_10, &phi_bb26_11);
    ca_.Goto(&block8, phi_bb26_10, phi_bb26_11, tmp41);
  }

  TNode<Smi> phi_bb23_10;
  TNode<Object> phi_bb23_11;
  TNode<JSReceiver> tmp42;
      TNode<Object> tmp45;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_10, &phi_bb23_11);
    compiler::CodeAssemblerLabel label43(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch44__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch44__label);
    tmp42 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{p_iter.object}, TNode<Object>{p_iter.next}}, TNode<Map>{tmp36}, &label43);
    }
    if (catch44__label.is_used()) {
      compiler::CodeAssemblerLabel catch44_skip(&ca_);
      ca_.Goto(&catch44_skip);
      ca_.Bind(&catch44__label, &tmp45);
      ca_.Goto(&block33, phi_bb23_10, phi_bb23_11);
      ca_.Bind(&catch44_skip);
    }
    ca_.Goto(&block31, phi_bb23_10, phi_bb23_11);
    if (label43.is_used()) {
      ca_.Bind(&label43);
      ca_.Goto(&block32, phi_bb23_10, phi_bb23_11);
    }
  }

  TNode<Smi> phi_bb33_10;
  TNode<Object> phi_bb33_11;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_10, &phi_bb33_11);
    ca_.Goto(&block28, phi_bb33_10, phi_bb33_11, tmp45);
  }

  TNode<Smi> phi_bb32_10;
  TNode<Object> phi_bb32_11;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_10, &phi_bb32_11);
    ca_.Goto(&block5, phi_bb32_10, phi_bb32_11);
  }

  TNode<Smi> phi_bb31_10;
  TNode<Object> phi_bb31_11;
  TNode<Object> tmp46;
      TNode<Object> tmp48;
  TNode<Smi> tmp49;
      TNode<Object> tmp51;
  TNode<BoolT> tmp52;
      TNode<Object> tmp54;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_10, &phi_bb31_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch47__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch47__label);
    tmp46 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{p_context}, TNode<JSReceiver>{tmp42}, TNode<Map>{tmp36});
    }
    if (catch47__label.is_used()) {
      compiler::CodeAssemblerLabel catch47_skip(&ca_);
      ca_.Goto(&catch47_skip);
      ca_.Bind(&catch47__label, &tmp48);
      ca_.Goto(&block34, phi_bb31_10, phi_bb31_11);
      ca_.Bind(&catch47_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch50__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch50__label);
    tmp49 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyArray::HashField::kMax);
    }
    if (catch50__label.is_used()) {
      compiler::CodeAssemblerLabel catch50_skip(&ca_);
      ca_.Goto(&catch50_skip);
      ca_.Bind(&catch50__label, &tmp51);
      ca_.Goto(&block37, phi_bb31_10, phi_bb31_11, phi_bb31_10, phi_bb31_10);
      ca_.Bind(&catch50_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch53__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch53__label);
    tmp52 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb31_10}, TNode<Smi>{tmp49});
    }
    if (catch53__label.is_used()) {
      compiler::CodeAssemblerLabel catch53_skip(&ca_);
      ca_.Goto(&catch53_skip);
      ca_.Bind(&catch53__label, &tmp54);
      ca_.Goto(&block38, phi_bb31_10, phi_bb31_11, phi_bb31_10);
      ca_.Bind(&catch53_skip);
    }
    ca_.Branch(tmp52, &block35, std::vector<Node*>{phi_bb31_10, phi_bb31_11}, &block36, std::vector<Node*>{phi_bb31_10, phi_bb31_11});
  }

  TNode<Smi> phi_bb34_10;
  TNode<Object> phi_bb34_11;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_10, &phi_bb34_11);
    ca_.Goto(&block28, phi_bb34_10, phi_bb34_11, tmp48);
  }

  TNode<Smi> phi_bb28_10;
  TNode<Object> phi_bb28_11;
  TNode<Object> phi_bb28_14;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_10, &phi_bb28_11, &phi_bb28_14);
    ca_.Goto(&block1, phi_bb28_14);
  }

  TNode<Smi> phi_bb37_10;
  TNode<Object> phi_bb37_11;
  TNode<Smi> phi_bb37_14;
  TNode<Smi> phi_bb37_15;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_10, &phi_bb37_11, &phi_bb37_14, &phi_bb37_15);
    ca_.Goto(&block8, phi_bb37_10, phi_bb37_11, tmp51);
  }

  TNode<Smi> phi_bb38_10;
  TNode<Object> phi_bb38_11;
  TNode<Smi> phi_bb38_14;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_10, &phi_bb38_11, &phi_bb38_14);
    ca_.Goto(&block8, phi_bb38_10, phi_bb38_11, tmp54);
  }

  TNode<Smi> phi_bb35_10;
  TNode<Object> phi_bb35_11;
  TNode<Object> tmp55;
      TNode<Object> tmp57;
      TNode<Object> tmp59;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_10, &phi_bb35_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch56__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch56__label);
    tmp55 = FromConstexpr_Object_constexpr_string_0(state_, "all");
    }
    if (catch56__label.is_used()) {
      compiler::CodeAssemblerLabel catch56_skip(&ca_);
      ca_.Goto(&catch56_skip);
      ca_.Bind(&catch56__label, &tmp57);
      ca_.Goto(&block39, phi_bb35_10, phi_bb35_11);
      ca_.Bind(&catch56_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch58__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch58__label);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{p_context}, MessageTemplate::kTooManyElementsInPromiseCombinator, TNode<Object>{tmp55});
    }
    if (catch58__label.is_used()) {
      compiler::CodeAssemblerLabel catch58_skip(&ca_);
      ca_.Bind(&catch58__label, &tmp59);
      ca_.Goto(&block40, phi_bb35_10, phi_bb35_11);
    }
  }

  TNode<Smi> phi_bb39_10;
  TNode<Object> phi_bb39_11;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_10, &phi_bb39_11);
    ca_.Goto(&block8, phi_bb39_10, phi_bb39_11, tmp57);
  }

  TNode<Smi> phi_bb40_10;
  TNode<Object> phi_bb40_11;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_10, &phi_bb40_11);
    ca_.Goto(&block8, phi_bb40_10, phi_bb40_11, tmp59);
  }

  TNode<Smi> phi_bb36_10;
  TNode<Object> phi_bb36_11;
  TNode<Object> tmp60;
      TNode<Object> tmp62;
  TNode<Smi> tmp63;
      TNode<Object> tmp65;
  TNode<Smi> tmp66;
      TNode<Object> tmp68;
  TNode<Smi> tmp69;
      TNode<Object> tmp71;
      TNode<Object> tmp73;
  TNode<SharedFunctionInfo> tmp74;
  TNode<JSFunction> tmp75;
  TNode<SharedFunctionInfo> tmp76;
  TNode<JSFunction> tmp77;
  TNode<Oddball> tmp78;
  TNode<BoolT> tmp79;
      TNode<Object> tmp81;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_10, &phi_bb36_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch61__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch61__label);
    tmp60 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    }
    if (catch61__label.is_used()) {
      compiler::CodeAssemblerLabel catch61_skip(&ca_);
      ca_.Goto(&catch61_skip);
      ca_.Bind(&catch61__label, &tmp62);
      ca_.Goto(&block41, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch61_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch64__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch64__label);
    tmp63 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp60});
    }
    if (catch64__label.is_used()) {
      compiler::CodeAssemblerLabel catch64_skip(&ca_);
      ca_.Goto(&catch64_skip);
      ca_.Bind(&catch64__label, &tmp65);
      ca_.Goto(&block42, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch64_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch67__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch67__label);
    tmp66 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    }
    if (catch67__label.is_used()) {
      compiler::CodeAssemblerLabel catch67_skip(&ca_);
      ca_.Goto(&catch67_skip);
      ca_.Bind(&catch67__label, &tmp68);
      ca_.Goto(&block43, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch67_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch70__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch70__label);
    tmp69 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp63}, TNode<Smi>{tmp66});
    }
    if (catch70__label.is_used()) {
      compiler::CodeAssemblerLabel catch70_skip(&ca_);
      ca_.Goto(&catch70_skip);
      ca_.Bind(&catch70__label, &tmp71);
      ca_.Goto(&block44, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch70_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch72__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch72__label);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp69});
    }
    if (catch72__label.is_used()) {
      compiler::CodeAssemblerLabel catch72_skip(&ca_);
      ca_.Goto(&catch72_skip);
      ca_.Bind(&catch72__label, &tmp73);
      ca_.Goto(&block45, phi_bb36_10, phi_bb36_11);
      ca_.Bind(&catch72_skip);
    }
    tmp74 = CodeStubAssembler(state_).PromiseAllSettledResolveElementSharedFunConstant();
    tmp75 = CreatePromiseAllResolveElementFunction_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp11}, TNode<Smi>{phi_bb36_10}, TNode<NativeContext>{tmp0}, TNode<SharedFunctionInfo>{tmp74});
    tmp76 = CodeStubAssembler(state_).PromiseAllSettledRejectElementSharedFunConstant();
    tmp77 = CreatePromiseAllResolveElementFunction_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp11}, TNode<Smi>{phi_bb36_10}, TNode<NativeContext>{tmp0}, TNode<SharedFunctionInfo>{tmp76});
    tmp78 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch80__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch80__label);
    tmp79 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{phi_bb36_11}, TNode<HeapObject>{tmp78});
    }
    if (catch80__label.is_used()) {
      compiler::CodeAssemblerLabel catch80_skip(&ca_);
      ca_.Goto(&catch80_skip);
      ca_.Bind(&catch80__label, &tmp81);
      ca_.Goto(&block50, phi_bb36_10, phi_bb36_11, phi_bb36_11);
      ca_.Bind(&catch80_skip);
    }
    ca_.Branch(tmp79, &block51, std::vector<Node*>{phi_bb36_10, phi_bb36_11}, &block52, std::vector<Node*>{phi_bb36_10, phi_bb36_11});
  }

  TNode<Smi> phi_bb41_10;
  TNode<Object> phi_bb41_11;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_10, &phi_bb41_11);
    ca_.Goto(&block8, phi_bb41_10, phi_bb41_11, tmp62);
  }

  TNode<Smi> phi_bb42_10;
  TNode<Object> phi_bb42_11;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_10, &phi_bb42_11);
    ca_.Goto(&block8, phi_bb42_10, phi_bb42_11, tmp65);
  }

  TNode<Smi> phi_bb43_10;
  TNode<Object> phi_bb43_11;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_10, &phi_bb43_11);
    ca_.Goto(&block8, phi_bb43_10, phi_bb43_11, tmp68);
  }

  TNode<Smi> phi_bb44_10;
  TNode<Object> phi_bb44_11;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_10, &phi_bb44_11);
    ca_.Goto(&block8, phi_bb44_10, phi_bb44_11, tmp71);
  }

  TNode<Smi> phi_bb45_10;
  TNode<Object> phi_bb45_11;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_10, &phi_bb45_11);
    ca_.Goto(&block8, phi_bb45_10, phi_bb45_11, tmp73);
  }

  TNode<Smi> phi_bb50_10;
  TNode<Object> phi_bb50_11;
  TNode<Object> phi_bb50_17;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_10, &phi_bb50_11, &phi_bb50_17);
    ca_.Goto(&block8, phi_bb50_10, phi_bb50_11, tmp81);
  }

  TNode<Smi> phi_bb51_10;
  TNode<Object> phi_bb51_11;
  TNode<BoolT> tmp82;
      TNode<Object> tmp84;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_10, &phi_bb51_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch83__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch83__label);
    tmp82 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch83__label.is_used()) {
      compiler::CodeAssemblerLabel catch83_skip(&ca_);
      ca_.Goto(&catch83_skip);
      ca_.Bind(&catch83__label, &tmp84);
      ca_.Goto(&block54, phi_bb51_10, phi_bb51_11);
      ca_.Bind(&catch83_skip);
    }
    ca_.Goto(&block53, phi_bb51_10, phi_bb51_11, tmp82);
  }

  TNode<Smi> phi_bb54_10;
  TNode<Object> phi_bb54_11;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_10, &phi_bb54_11);
    ca_.Goto(&block8, phi_bb54_10, phi_bb54_11, tmp84);
  }

  TNode<Smi> phi_bb52_10;
  TNode<Object> phi_bb52_11;
  TNode<BoolT> tmp85;
      TNode<Object> tmp87;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_10, &phi_bb52_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch86__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch86__label);
    tmp85 = CodeStubAssembler(state_).NeedsAnyPromiseHooks();
    }
    if (catch86__label.is_used()) {
      compiler::CodeAssemblerLabel catch86_skip(&ca_);
      ca_.Goto(&catch86_skip);
      ca_.Bind(&catch86__label, &tmp87);
      ca_.Goto(&block55, phi_bb52_10, phi_bb52_11);
      ca_.Bind(&catch86_skip);
    }
    ca_.Goto(&block53, phi_bb52_10, phi_bb52_11, tmp85);
  }

  TNode<Smi> phi_bb55_10;
  TNode<Object> phi_bb55_11;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_10, &phi_bb55_11);
    ca_.Goto(&block8, phi_bb55_10, phi_bb55_11, tmp87);
  }

  TNode<Smi> phi_bb53_10;
  TNode<Object> phi_bb53_11;
  TNode<BoolT> phi_bb53_18;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_10, &phi_bb53_11, &phi_bb53_18);
    ca_.Branch(phi_bb53_18, &block56, std::vector<Node*>{phi_bb53_10, phi_bb53_11}, &block57, std::vector<Node*>{phi_bb53_10, phi_bb53_11});
  }

  TNode<Smi> phi_bb56_10;
  TNode<Object> phi_bb56_11;
  TNode<BoolT> tmp88;
      TNode<Object> tmp90;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_10, &phi_bb56_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch89__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch89__label);
    tmp88 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch89__label.is_used()) {
      compiler::CodeAssemblerLabel catch89_skip(&ca_);
      ca_.Goto(&catch89_skip);
      ca_.Bind(&catch89__label, &tmp90);
      ca_.Goto(&block59, phi_bb56_10, phi_bb56_11);
      ca_.Bind(&catch89_skip);
    }
    ca_.Goto(&block58, phi_bb56_10, phi_bb56_11, tmp88);
  }

  TNode<Smi> phi_bb59_10;
  TNode<Object> phi_bb59_11;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_10, &phi_bb59_11);
    ca_.Goto(&block8, phi_bb59_10, phi_bb59_11, tmp90);
  }

  TNode<Smi> phi_bb57_10;
  TNode<Object> phi_bb57_11;
  TNode<BoolT> tmp91;
      TNode<Object> tmp93;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_10, &phi_bb57_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch92__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch92__label);
    tmp91 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    }
    if (catch92__label.is_used()) {
      compiler::CodeAssemblerLabel catch92_skip(&ca_);
      ca_.Goto(&catch92_skip);
      ca_.Bind(&catch92__label, &tmp93);
      ca_.Goto(&block60, phi_bb57_10, phi_bb57_11);
      ca_.Bind(&catch92_skip);
    }
    ca_.Goto(&block58, phi_bb57_10, phi_bb57_11, tmp91);
  }

  TNode<Smi> phi_bb60_10;
  TNode<Object> phi_bb60_11;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_10, &phi_bb60_11);
    ca_.Goto(&block8, phi_bb60_10, phi_bb60_11, tmp93);
  }

  TNode<Smi> phi_bb58_10;
  TNode<Object> phi_bb58_11;
  TNode<BoolT> phi_bb58_18;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_10, &phi_bb58_11, &phi_bb58_18);
    ca_.Branch(phi_bb58_18, &block61, std::vector<Node*>{phi_bb58_10, phi_bb58_11}, &block62, std::vector<Node*>{phi_bb58_10, phi_bb58_11});
  }

  TNode<Smi> phi_bb61_10;
  TNode<Object> phi_bb61_11;
  TNode<BoolT> tmp94;
      TNode<Object> tmp96;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_10, &phi_bb61_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch95__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch95__label);
    tmp94 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch95__label.is_used()) {
      compiler::CodeAssemblerLabel catch95_skip(&ca_);
      ca_.Goto(&catch95_skip);
      ca_.Bind(&catch95__label, &tmp96);
      ca_.Goto(&block64, phi_bb61_10, phi_bb61_11);
      ca_.Bind(&catch95_skip);
    }
    ca_.Goto(&block63, phi_bb61_10, phi_bb61_11, tmp94);
  }

  TNode<Smi> phi_bb64_10;
  TNode<Object> phi_bb64_11;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_10, &phi_bb64_11);
    ca_.Goto(&block8, phi_bb64_10, phi_bb64_11, tmp96);
  }

  TNode<Smi> phi_bb62_10;
  TNode<Object> phi_bb62_11;
  TNode<BoolT> tmp97;
      TNode<Object> tmp99;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_10, &phi_bb62_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch98__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch98__label);
    tmp97 = Is_Smi_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp46});
    }
    if (catch98__label.is_used()) {
      compiler::CodeAssemblerLabel catch98_skip(&ca_);
      ca_.Goto(&catch98_skip);
      ca_.Bind(&catch98__label, &tmp99);
      ca_.Goto(&block65, phi_bb62_10, phi_bb62_11);
      ca_.Bind(&catch98_skip);
    }
    ca_.Goto(&block63, phi_bb62_10, phi_bb62_11, tmp97);
  }

  TNode<Smi> phi_bb65_10;
  TNode<Object> phi_bb65_11;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_10, &phi_bb65_11);
    ca_.Goto(&block8, phi_bb65_10, phi_bb65_11, tmp99);
  }

  TNode<Smi> phi_bb63_10;
  TNode<Object> phi_bb63_11;
  TNode<BoolT> phi_bb63_18;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_10, &phi_bb63_11, &phi_bb63_18);
    ca_.Branch(phi_bb63_18, &block66, std::vector<Node*>{phi_bb63_10, phi_bb63_11}, &block67, std::vector<Node*>{phi_bb63_10, phi_bb63_11});
  }

  TNode<Smi> phi_bb66_10;
  TNode<Object> phi_bb66_11;
  TNode<BoolT> tmp100;
      TNode<Object> tmp102;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_10, &phi_bb66_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch101__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch101__label);
    tmp100 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch101__label.is_used()) {
      compiler::CodeAssemblerLabel catch101_skip(&ca_);
      ca_.Goto(&catch101_skip);
      ca_.Bind(&catch101__label, &tmp102);
      ca_.Goto(&block69, phi_bb66_10, phi_bb66_11);
      ca_.Bind(&catch101_skip);
    }
    ca_.Goto(&block68, phi_bb66_10, phi_bb66_11, tmp100);
  }

  TNode<Smi> phi_bb69_10;
  TNode<Object> phi_bb69_11;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_10, &phi_bb69_11);
    ca_.Goto(&block8, phi_bb69_10, phi_bb69_11, tmp102);
  }

  TNode<Smi> phi_bb67_10;
  TNode<Object> phi_bb67_11;
  TNode<HeapObject> tmp103;
      TNode<Object> tmp105;
  TNode<IntPtrT> tmp106;
      TNode<Object> tmp108;
  TNode<Map> tmp109;
  TNode<BoolT> tmp110;
      TNode<Object> tmp112;
  TNode<BoolT> tmp113;
      TNode<Object> tmp115;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_10, &phi_bb67_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch104__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch104__label);
    tmp103 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp46});
    }
    if (catch104__label.is_used()) {
      compiler::CodeAssemblerLabel catch104_skip(&ca_);
      ca_.Goto(&catch104_skip);
      ca_.Bind(&catch104__label, &tmp105);
      ca_.Goto(&block70, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch104_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch107__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch107__label);
    tmp106 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    }
    if (catch107__label.is_used()) {
      compiler::CodeAssemblerLabel catch107_skip(&ca_);
      ca_.Goto(&catch107_skip);
      ca_.Bind(&catch107__label, &tmp108);
      ca_.Goto(&block71, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch107_skip);
    }
    tmp109 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp103, tmp106});
    compiler::CodeAssemblerExceptionHandlerLabel catch111__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch111__label);
    tmp110 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{tmp0}, TNode<Map>{tmp109});
    }
    if (catch111__label.is_used()) {
      compiler::CodeAssemblerLabel catch111_skip(&ca_);
      ca_.Goto(&catch111_skip);
      ca_.Bind(&catch111__label, &tmp112);
      ca_.Goto(&block72, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch111_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch114__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch114__label);
    tmp113 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp110});
    }
    if (catch114__label.is_used()) {
      compiler::CodeAssemblerLabel catch114_skip(&ca_);
      ca_.Goto(&catch114_skip);
      ca_.Bind(&catch114__label, &tmp115);
      ca_.Goto(&block73, phi_bb67_10, phi_bb67_11);
      ca_.Bind(&catch114_skip);
    }
    ca_.Goto(&block68, phi_bb67_10, phi_bb67_11, tmp113);
  }

  TNode<Smi> phi_bb70_10;
  TNode<Object> phi_bb70_11;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_10, &phi_bb70_11);
    ca_.Goto(&block8, phi_bb70_10, phi_bb70_11, tmp105);
  }

  TNode<Smi> phi_bb71_10;
  TNode<Object> phi_bb71_11;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_10, &phi_bb71_11);
    ca_.Goto(&block8, phi_bb71_10, phi_bb71_11, tmp108);
  }

  TNode<Smi> phi_bb72_10;
  TNode<Object> phi_bb72_11;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_10, &phi_bb72_11);
    ca_.Goto(&block8, phi_bb72_10, phi_bb72_11, tmp112);
  }

  TNode<Smi> phi_bb73_10;
  TNode<Object> phi_bb73_11;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_10, &phi_bb73_11);
    ca_.Goto(&block8, phi_bb73_10, phi_bb73_11, tmp115);
  }

  TNode<Smi> phi_bb68_10;
  TNode<Object> phi_bb68_11;
  TNode<BoolT> phi_bb68_18;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_10, &phi_bb68_11, &phi_bb68_18);
    ca_.Branch(phi_bb68_18, &block48, std::vector<Node*>{phi_bb68_10, phi_bb68_11}, &block49, std::vector<Node*>{phi_bb68_10, phi_bb68_11});
  }

  TNode<Smi> phi_bb48_10;
  TNode<Object> phi_bb48_11;
  TNode<JSReceiver> tmp116;
      TNode<Object> tmp118;
  TNode<Object> tmp119;
      TNode<Object> tmp121;
  TNode<String> tmp122;
  TNode<Object> tmp123;
      TNode<Object> tmp125;
  TNode<Object> tmp126;
      TNode<Object> tmp128;
  TNode<BoolT> tmp129;
      TNode<Object> tmp131;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_10, &phi_bb48_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch117__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch117__label);
    tmp116 = UnsafeCast_Constructor_0(state_, TNode<Context>{p_context}, TNode<Object>{p_constructor});
    }
    if (catch117__label.is_used()) {
      compiler::CodeAssemblerLabel catch117_skip(&ca_);
      ca_.Goto(&catch117_skip);
      ca_.Bind(&catch117__label, &tmp118);
      ca_.Goto(&block75, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch117_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch120__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch120__label);
    tmp119 = CallResolve_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{tmp116}, TNode<Object>{phi_bb48_11}, TNode<Object>{tmp46});
    }
    if (catch120__label.is_used()) {
      compiler::CodeAssemblerLabel catch120_skip(&ca_);
      ca_.Goto(&catch120_skip);
      ca_.Bind(&catch120__label, &tmp121);
      ca_.Goto(&block76, phi_bb48_10, phi_bb48_11, phi_bb48_11);
      ca_.Bind(&catch120_skip);
    }
    tmp122 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch124__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch124__label);
    tmp123 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{tmp119}, TNode<Object>{tmp122});
    }
    if (catch124__label.is_used()) {
      compiler::CodeAssemblerLabel catch124_skip(&ca_);
      ca_.Goto(&catch124_skip);
      ca_.Bind(&catch124__label, &tmp125);
      ca_.Goto(&block77, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch124_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch127__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch127__label);
    tmp126 = CodeStubAssembler(state_).Call(TNode<Context>{tmp0}, TNode<Object>{tmp123}, TNode<Object>{tmp119}, TNode<Object>{tmp75}, TNode<Object>{tmp77});
    }
    if (catch127__label.is_used()) {
      compiler::CodeAssemblerLabel catch127_skip(&ca_);
      ca_.Goto(&catch127_skip);
      ca_.Bind(&catch127__label, &tmp128);
      ca_.Goto(&block78, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch127_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch130__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch130__label);
    tmp129 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch130__label.is_used()) {
      compiler::CodeAssemblerLabel catch130_skip(&ca_);
      ca_.Goto(&catch130_skip);
      ca_.Bind(&catch130__label, &tmp131);
      ca_.Goto(&block81, phi_bb48_10, phi_bb48_11);
      ca_.Bind(&catch130_skip);
    }
    ca_.Branch(tmp129, &block82, std::vector<Node*>{phi_bb48_10, phi_bb48_11}, &block83, std::vector<Node*>{phi_bb48_10, phi_bb48_11});
  }

  TNode<Smi> phi_bb75_10;
  TNode<Object> phi_bb75_11;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_10, &phi_bb75_11);
    ca_.Goto(&block8, phi_bb75_10, phi_bb75_11, tmp118);
  }

  TNode<Smi> phi_bb76_10;
  TNode<Object> phi_bb76_11;
  TNode<Object> phi_bb76_18;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_10, &phi_bb76_11, &phi_bb76_18);
    ca_.Goto(&block8, phi_bb76_10, phi_bb76_11, tmp121);
  }

  TNode<Smi> phi_bb77_10;
  TNode<Object> phi_bb77_11;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_10, &phi_bb77_11);
    ca_.Goto(&block8, phi_bb77_10, phi_bb77_11, tmp125);
  }

  TNode<Smi> phi_bb78_10;
  TNode<Object> phi_bb78_11;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_10, &phi_bb78_11);
    ca_.Goto(&block8, phi_bb78_10, phi_bb78_11, tmp128);
  }

  TNode<Smi> phi_bb81_10;
  TNode<Object> phi_bb81_11;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_10, &phi_bb81_11);
    ca_.Goto(&block8, phi_bb81_10, phi_bb81_11, tmp131);
  }

  TNode<Smi> phi_bb82_10;
  TNode<Object> phi_bb82_11;
  TNode<BoolT> tmp132;
      TNode<Object> tmp134;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_10, &phi_bb82_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch133__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch133__label);
    tmp132 = Is_JSPromise_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp126});
    }
    if (catch133__label.is_used()) {
      compiler::CodeAssemblerLabel catch133_skip(&ca_);
      ca_.Goto(&catch133_skip);
      ca_.Bind(&catch133__label, &tmp134);
      ca_.Goto(&block85, phi_bb82_10, phi_bb82_11);
      ca_.Bind(&catch133_skip);
    }
    ca_.Goto(&block84, phi_bb82_10, phi_bb82_11, tmp132);
  }

  TNode<Smi> phi_bb85_10;
  TNode<Object> phi_bb85_11;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_10, &phi_bb85_11);
    ca_.Goto(&block8, phi_bb85_10, phi_bb85_11, tmp134);
  }

  TNode<Smi> phi_bb83_10;
  TNode<Object> phi_bb83_11;
  TNode<BoolT> tmp135;
      TNode<Object> tmp137;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_10, &phi_bb83_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch136__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch136__label);
    tmp135 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch136__label.is_used()) {
      compiler::CodeAssemblerLabel catch136_skip(&ca_);
      ca_.Goto(&catch136_skip);
      ca_.Bind(&catch136__label, &tmp137);
      ca_.Goto(&block86, phi_bb83_10, phi_bb83_11);
      ca_.Bind(&catch136_skip);
    }
    ca_.Goto(&block84, phi_bb83_10, phi_bb83_11, tmp135);
  }

  TNode<Smi> phi_bb86_10;
  TNode<Object> phi_bb86_11;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_10, &phi_bb86_11);
    ca_.Goto(&block8, phi_bb86_10, phi_bb86_11, tmp137);
  }

  TNode<Smi> phi_bb84_10;
  TNode<Object> phi_bb84_11;
  TNode<BoolT> phi_bb84_21;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_10, &phi_bb84_11, &phi_bb84_21);
    ca_.Branch(phi_bb84_21, &block79, std::vector<Node*>{phi_bb84_10, phi_bb84_11}, &block80, std::vector<Node*>{phi_bb84_10, phi_bb84_11});
  }

  TNode<Smi> phi_bb79_10;
  TNode<Object> phi_bb79_11;
  TNode<Symbol> tmp138;
  TNode<Object> tmp139;
      TNode<Object> tmp141;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_10, &phi_bb79_11);
    tmp138 = kPromiseHandledBySymbol_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch140__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch140__label);
    tmp139 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{p_context}, TNode<Object>{tmp126}, TNode<Object>{tmp138}, TNode<Object>{tmp2});
    }
    if (catch140__label.is_used()) {
      compiler::CodeAssemblerLabel catch140_skip(&ca_);
      ca_.Goto(&catch140_skip);
      ca_.Bind(&catch140__label, &tmp141);
      ca_.Goto(&block87, phi_bb79_10, phi_bb79_11);
      ca_.Bind(&catch140_skip);
    }
    ca_.Goto(&block80, phi_bb79_10, phi_bb79_11);
  }

  TNode<Smi> phi_bb87_10;
  TNode<Object> phi_bb87_11;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_10, &phi_bb87_11);
    ca_.Goto(&block8, phi_bb87_10, phi_bb87_11, tmp141);
  }

  TNode<Smi> phi_bb80_10;
  TNode<Object> phi_bb80_11;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_10, &phi_bb80_11);
    ca_.Goto(&block74, phi_bb80_10, phi_bb80_11);
  }

  TNode<Smi> phi_bb49_10;
  TNode<Object> phi_bb49_11;
  TNode<JSPromise> tmp142;
      TNode<Object> tmp144;
  TNode<Oddball> tmp145;
      TNode<Object> tmp147;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_10, &phi_bb49_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch143__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch143__label);
    tmp142 = UnsafeCast_JSPromise_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp46});
    }
    if (catch143__label.is_used()) {
      compiler::CodeAssemblerLabel catch143_skip(&ca_);
      ca_.Goto(&catch143_skip);
      ca_.Bind(&catch143__label, &tmp144);
      ca_.Goto(&block88, phi_bb49_10, phi_bb49_11);
      ca_.Bind(&catch143_skip);
    }
    tmp145 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch146__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch146__label);
    PerformPromiseThenImpl_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{tmp142}, TNode<HeapObject>{tmp75}, TNode<HeapObject>{tmp77}, TNode<HeapObject>{tmp145});
    }
    if (catch146__label.is_used()) {
      compiler::CodeAssemblerLabel catch146_skip(&ca_);
      ca_.Goto(&catch146_skip);
      ca_.Bind(&catch146__label, &tmp147);
      ca_.Goto(&block89, phi_bb49_10, phi_bb49_11);
      ca_.Bind(&catch146_skip);
    }
    ca_.Goto(&block74, phi_bb49_10, phi_bb49_11);
  }

  TNode<Smi> phi_bb88_10;
  TNode<Object> phi_bb88_11;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_10, &phi_bb88_11);
    ca_.Goto(&block8, phi_bb88_10, phi_bb88_11, tmp144);
  }

  TNode<Smi> phi_bb89_10;
  TNode<Object> phi_bb89_11;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_10, &phi_bb89_11);
    ca_.Goto(&block8, phi_bb89_10, phi_bb89_11, tmp147);
  }

  TNode<Smi> phi_bb74_10;
  TNode<Object> phi_bb74_11;
  TNode<Smi> tmp148;
      TNode<Object> tmp150;
  TNode<Smi> tmp151;
      TNode<Object> tmp153;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_10, &phi_bb74_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch149__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch149__label);
    tmp148 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    }
    if (catch149__label.is_used()) {
      compiler::CodeAssemblerLabel catch149_skip(&ca_);
      ca_.Goto(&catch149_skip);
      ca_.Bind(&catch149__label, &tmp150);
      ca_.Goto(&block90, phi_bb74_10, phi_bb74_11, phi_bb74_10, phi_bb74_10);
      ca_.Bind(&catch149_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch152__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch152__label);
    tmp151 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb74_10}, TNode<Smi>{tmp148});
    }
    if (catch152__label.is_used()) {
      compiler::CodeAssemblerLabel catch152_skip(&ca_);
      ca_.Goto(&catch152_skip);
      ca_.Bind(&catch152__label, &tmp153);
      ca_.Goto(&block91, phi_bb74_10, phi_bb74_11, phi_bb74_10);
      ca_.Bind(&catch152_skip);
    }
    ca_.Goto(&block25, tmp151, phi_bb74_11);
  }

  TNode<Smi> phi_bb90_10;
  TNode<Object> phi_bb90_11;
  TNode<Smi> phi_bb90_17;
  TNode<Smi> phi_bb90_18;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_10, &phi_bb90_11, &phi_bb90_17, &phi_bb90_18);
    ca_.Goto(&block8, phi_bb90_10, phi_bb90_11, tmp150);
  }

  TNode<Smi> phi_bb91_10;
  TNode<Object> phi_bb91_11;
  TNode<Smi> phi_bb91_17;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_10, &phi_bb91_11, &phi_bb91_17);
    ca_.Goto(&block8, phi_bb91_10, phi_bb91_11, tmp153);
  }

  TNode<Smi> phi_bb24_10;
  TNode<Object> phi_bb24_11;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_10, &phi_bb24_11);
    ca_.Goto(&block5, phi_bb24_10, phi_bb24_11);
  }

  TNode<Smi> phi_bb8_10;
  TNode<Object> phi_bb8_11;
  TNode<Object> phi_bb8_12;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_10, &phi_bb8_11, &phi_bb8_12);
    IteratorCloseOnException_0(state_, TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{p_iter.object}, TNode<Object>{p_iter.next}});
    ca_.Goto(&block1, phi_bb8_12);
  }

  TNode<Smi> phi_bb5_10;
  TNode<Object> phi_bb5_11;
  TNode<Object> tmp154;
  TNode<Smi> tmp155;
  TNode<Smi> tmp156;
  TNode<Smi> tmp157;
  TNode<Smi> tmp158;
  TNode<BoolT> tmp159;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_10, &phi_bb5_11);
    tmp154 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp155 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp154});
    tmp156 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp157 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp155}, TNode<Smi>{tmp156});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp157});
    tmp158 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp159 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp157}, TNode<Smi>{tmp158});
    ca_.Branch(tmp159, &block92, std::vector<Node*>{phi_bb5_10, phi_bb5_11}, &block93, std::vector<Node*>{phi_bb5_10, phi_bb5_11});
  }

  TNode<Smi> phi_bb92_10;
  TNode<Object> phi_bb92_11;
  TNode<Object> tmp160;
  TNode<JSArray> tmp161;
  TNode<IntPtrT> tmp162;
  TNode<FixedArrayBase> tmp163;
  TNode<FixedArray> tmp164;
  TNode<IntPtrT> tmp165;
  TNode<IntPtrT> tmp166;
  TNode<BoolT> tmp167;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_10, &phi_bb92_11);
    tmp160 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp161 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp160});
    tmp162 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp163 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp161, tmp162});
    tmp164 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp163});
    tmp165 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp164});
    tmp166 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{phi_bb92_10});
    tmp167 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp165}, TNode<IntPtrT>{tmp166});
    ca_.Branch(tmp167, &block95, std::vector<Node*>{phi_bb92_10, phi_bb92_11}, &block96, std::vector<Node*>{phi_bb92_10, phi_bb92_11});
  }

  TNode<Smi> phi_bb95_10;
  TNode<Object> phi_bb95_11;
  TNode<IntPtrT> tmp168;
  TNode<IntPtrT> tmp169;
  TNode<FixedArray> tmp170;
  if (block95.is_used()) {
    ca_.Bind(&block95, &phi_bb95_10, &phi_bb95_11);
    tmp168 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp169 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp170 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp164}, TNode<IntPtrT>{tmp169}, TNode<IntPtrT>{tmp165}, TNode<IntPtrT>{tmp166});
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp161, tmp168}, tmp170);
    ca_.Goto(&block96, phi_bb95_10, phi_bb95_11);
  }

  TNode<Smi> phi_bb96_10;
  TNode<Object> phi_bb96_11;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_10, &phi_bb96_11);
    ca_.Goto(&block94, phi_bb96_10, phi_bb96_11);
  }

  TNode<Smi> phi_bb93_10;
  TNode<Object> phi_bb93_11;
  TNode<Object> tmp171;
  TNode<Object> tmp172;
  TNode<Object> tmp173;
  TNode<Oddball> tmp174;
  TNode<Object> tmp175;
  if (block93.is_used()) {
    ca_.Bind(&block93, &phi_bb93_10, &phi_bb93_11);
    tmp171 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{tmp11}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp172 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp171});
    tmp173 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    tmp174 = Undefined_0(state_);
    tmp175 = CodeStubAssembler(state_).Call(TNode<Context>{tmp0}, TNode<Object>{tmp173}, TNode<Object>{tmp174}, TNode<Object>{tmp172});
    ca_.Goto(&block94, phi_bb93_10, phi_bb93_11);
  }

  TNode<Smi> phi_bb94_10;
  TNode<Object> phi_bb94_11;
  if (block94.is_used()) {
    ca_.Bind(&block94, &phi_bb94_10, &phi_bb94_11);
    ca_.Goto(&block101);
  }

  TNode<Object> phi_bb1_0;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0);
    *label_Reject_parameter_0 = phi_bb1_0;
    ca_.Goto(label_Reject);
  }

    ca_.Bind(&block101);
  return TNode<Object>{tmp2};
}

}  // namespace internal
}  // namespace v8

