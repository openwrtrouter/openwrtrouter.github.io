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

TNode<BoolT> PromiseHasHandler_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise>{p_promise});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp0};
}

void PromiseInit_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Int32T> tmp3;
  TNode<Uint32T> tmp4;
  TNode<Uint32T> tmp5;
  TNode<Int32T> tmp6;
  TNode<Uint32T> tmp7;
  TNode<BoolT> tmp8;
  TNode<Uint32T> tmp9;
  TNode<BoolT> tmp10;
  TNode<Uint32T> tmp11;
  TNode<Int32T> tmp12;
  TNode<Uint32T> tmp13;
  TNode<Smi> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = kZero_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_promise, tmp0}, tmp1);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp3 = FromConstexpr_int32_constexpr_int32_0(state_, 0);
    tmp4 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp3});
    tmp5 = (TNode<Uint32T>{tmp4});
    tmp6 = FromConstexpr_PromiseState_constexpr_kPending_0(state_, Promise::PromiseState::kPending);
    tmp7 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<Promise::PromiseState, 0, 2, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp5), ca_.UncheckedCast<Uint32T>(tmp6), true));
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp9 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 2, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp7), ca_.UncheckedCast<Uint32T>(tmp8), true));
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp11 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 3, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp9), ca_.UncheckedCast<Uint32T>(tmp10), true));
    tmp12 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    tmp13 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<int32_t, 4, 22, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp11), ca_.UncheckedCast<Uint32T>(tmp12), true));
    tmp14 = SmiTag_JSPromiseFlags_0(state_, TNode<Uint32T>{tmp13});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_promise, tmp2}, tmp14);
    PromiseBuiltinsAssembler(state_).ZeroOutEmbedderOffsets(TNode<JSPromise>{p_promise});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<JSPromise> InnerNewJSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<JSFunction> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<Map> tmp6;
  TNode<HeapObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<JSPromise> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<FixedArray> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<FixedArray> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Smi> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<Int32T> tmp19;
  TNode<Uint32T> tmp20;
  TNode<Uint32T> tmp21;
  TNode<Int32T> tmp22;
  TNode<Uint32T> tmp23;
  TNode<BoolT> tmp24;
  TNode<Uint32T> tmp25;
  TNode<BoolT> tmp26;
  TNode<Uint32T> tmp27;
  TNode<Int32T> tmp28;
  TNode<Uint32T> tmp29;
  TNode<Smi> tmp30;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    tmp2 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp1});
    tmp3 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp4});
    tmp6 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp5});
    tmp7 = PromiseBuiltinsAssembler(state_).AllocateJSPromise(TNode<Context>{p_context});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    std::tie(tmp9, tmp10) = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0{TNode<HeapObject>{tmp7}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}).Flatten();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp6);
    tmp11 = UnsafeCast_JSPromise_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp7});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp11, tmp12}, tmp13);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp15 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp11, tmp14}, tmp15);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp17 = kZero_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp11, tmp16}, tmp17);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp19 = FromConstexpr_int32_constexpr_int32_0(state_, 0);
    tmp20 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp19});
    tmp21 = (TNode<Uint32T>{tmp20});
    tmp22 = FromConstexpr_PromiseState_constexpr_kPending_0(state_, Promise::PromiseState::kPending);
    tmp23 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<Promise::PromiseState, 0, 2, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp21), ca_.UncheckedCast<Uint32T>(tmp22), true));
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp25 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 2, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp23), ca_.UncheckedCast<Uint32T>(tmp24), true));
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp27 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 3, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp25), ca_.UncheckedCast<Uint32T>(tmp26), true));
    tmp28 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    tmp29 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<int32_t, 4, 22, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp27), ca_.UncheckedCast<Uint32T>(tmp28), true));
    tmp30 = SmiTag_JSPromiseFlags_0(state_, TNode<Uint32T>{tmp29});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp18}, tmp30);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<JSPromise>{tmp11};
}

TNode<PromiseFulfillReactionJobTask> NewPromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_handlerContext, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Map> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<PromiseFulfillReactionJobTask> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_handlerContext});
    tmp1 = CodeStubAssembler(state_).PromiseFulfillReactionJobTaskMapConstant();
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX_0(state_, Context::Field::CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp7}, p_argument);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp5, tmp8}, p_handlerContext);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp9}, p_handler);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp10}, p_promiseOrCapability);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp11}, tmp3);
    tmp12 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<PromiseFulfillReactionJobTask>{tmp12};
}

TNode<PromiseRejectReactionJobTask> NewPromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_handlerContext, TNode<Object> p_argument, TNode<HeapObject> p_handler, TNode<HeapObject> p_promiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Map> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<PromiseRejectReactionJobTask> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_handlerContext});
    tmp1 = CodeStubAssembler(state_).PromiseRejectReactionJobTaskMapConstant();
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX_0(state_, Context::Field::CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp7}, p_argument);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp5, tmp8}, p_handlerContext);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp9}, p_handler);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp10}, p_promiseOrCapability);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp11}, tmp3);
    tmp12 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<PromiseRejectReactionJobTask>{tmp12};
}

void RunContextPromiseHookInit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_parent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_INIT_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_INIT_FUNCTION_INDEX);
    tmp2 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp1});
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp2}, &label4);
    ca_.Goto(&block4);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp5 = Is_JSPromise_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_parent});
    ca_.Branch(tmp5, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<JSPromise> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_JSPromise_1(state_, TNode<Context>{p_context}, TNode<Object>{p_parent}, &label7);
    ca_.Goto(&block12);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block13);
    }
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block8, tmp6);
  }

  TNode<Oddball> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp8 = Undefined_0(state_);
    ca_.Goto(&block8, tmp8);
  }

  TNode<HeapObject> phi_bb8_5;
  TNode<Oddball> tmp9;
  TNode<Object> tmp10;
      TNode<Object> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_5);
    tmp9 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch11__label);
    tmp10 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp3}, TNode<Object>{tmp9}, TNode<Object>{p_promise}, TNode<Object>{phi_bb8_5});
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      ca_.Bind(&catch11__label, &tmp12);
      ca_.Goto(&block16);
      ca_.Bind(&catch11_skip);
    }
    ca_.Goto(&block14);
  }

  TNode<Object> tmp13;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp13 = CodeStubAssembler(state_).CallRuntime(Runtime::kReportMessageFromMicrotask, p_context, tmp12); 
    ca_.Goto(&block14);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block17);
  }

    ca_.Bind(&block17);
}

void RunContextPromiseHookResolve_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).PromiseHookFlags();
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_RESOLVE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_RESOLVE_FUNCTION_INDEX);
    RunContextPromiseHook_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp1}, TNode<HeapObject>{p_promise}, TNode<Uint32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void RunContextPromiseHookResolve_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Uint32T> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_RESOLVE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_RESOLVE_FUNCTION_INDEX);
    RunContextPromiseHook_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}, TNode<HeapObject>{p_promise}, TNode<Uint32T>{p_flags});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void RunContextPromiseHookBefore_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).PromiseHookFlags();
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_BEFORE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_BEFORE_FUNCTION_INDEX);
    RunContextPromiseHook_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp1}, TNode<HeapObject>{p_promiseOrCapability}, TNode<Uint32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void RunContextPromiseHookBefore_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Uint32T> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_BEFORE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_BEFORE_FUNCTION_INDEX);
    RunContextPromiseHook_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}, TNode<HeapObject>{p_promiseOrCapability}, TNode<Uint32T>{p_flags});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void RunContextPromiseHookAfter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).PromiseHookFlags();
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_AFTER_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_AFTER_FUNCTION_INDEX);
    RunContextPromiseHook_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp1}, TNode<HeapObject>{p_promiseOrCapability}, TNode<Uint32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void RunContextPromiseHookAfter_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_promiseOrCapability, TNode<Uint32T> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_HOOK_AFTER_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_AFTER_FUNCTION_INDEX);
    RunContextPromiseHook_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}, TNode<HeapObject>{p_promiseOrCapability}, TNode<Uint32T>{p_flags});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void RunContextPromiseHook_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_slot, TNode<HeapObject> p_promiseOrCapability, TNode<Uint32T> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise, JSPromise> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSPromise> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).IsContextPromiseHookEnabled(TNode<Uint32T>{p_flags});
    tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1);
  }

  TNode<NativeContext> tmp2;
  TNode<Object> tmp3;
  TNode<JSReceiver> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{p_slot});
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp3}, &label5);
    ca_.Goto(&block6);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block7);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block1);
  }

  TNode<JSPromise> tmp6;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_JSPromise_0(state_, TNode<HeapObject>{p_promiseOrCapability}, &label7);
    ca_.Goto(&block10);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block11);
    }
  }

  TNode<PromiseCapability> tmp8;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_PromiseCapability_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_promiseOrCapability)}, &label9);
    ca_.Goto(&block14);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block15);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block8, tmp6);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<JSPromise> tmp12;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp11 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp8, tmp10});
    compiler::CodeAssemblerLabel label13(&ca_);
    tmp12 = Cast_JSPromise_0(state_, TNode<HeapObject>{tmp11}, &label13);
    ca_.Goto(&block18);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block19);
    }
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block1);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block8, tmp12);
  }

  TNode<JSPromise> phi_bb8_6;
  TNode<Oddball> tmp14;
  TNode<Object> tmp15;
      TNode<Object> tmp17;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_6);
    tmp14 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp4}, TNode<Object>{tmp14}, TNode<Object>{phi_bb8_6});
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block22, phi_bb8_6, phi_bb8_6);
      ca_.Bind(&catch16_skip);
    }
    ca_.Goto(&block20, phi_bb8_6);
  }

  TNode<JSPromise> phi_bb22_6;
  TNode<JSPromise> phi_bb22_10;
  TNode<Object> tmp18;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_6, &phi_bb22_10);
    tmp18 = CodeStubAssembler(state_).CallRuntime(Runtime::kReportMessageFromMicrotask, p_context, tmp17); 
    ca_.Goto(&block20, phi_bb22_6);
  }

  TNode<JSPromise> phi_bb20_6;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_6);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block23);
  }

    ca_.Bind(&block23);
}

void RunAnyPromiseHookInit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_parent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).PromiseHookFlags();
    tmp1 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp0}, TNode<Uint32T>{tmp1});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = PromiseBuiltinsAssembler(state_).IsContextPromiseHookEnabled(TNode<Uint32T>{tmp0});
    ca_.Branch(tmp3, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    RunContextPromiseHookInit_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{p_promise}, TNode<Object>{p_parent});
    ca_.Goto(&block5);
  }

  TNode<BoolT> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp4 = PromiseBuiltinsAssembler(state_).IsIsolatePromiseHookEnabledOrHasAsyncEventDelegate(TNode<Uint32T>{tmp0});
    ca_.Branch(tmp4, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<Object> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp5 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseHookInit, p_context, p_promise, p_parent); 
    ca_.Goto(&block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

TNode<JSPromise> NewJSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_parent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = InnerNewJSPromise_0(state_, TNode<Context>{p_context});
    PromiseInit_0(state_, TNode<JSPromise>{tmp0});
    RunAnyPromiseHookInit_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{tmp0}, TNode<Object>{p_parent});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSPromise>{tmp0};
}

TNode<JSPromise> NewJSPromise_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<JSPromise> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    tmp1 = NewJSPromise_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSPromise>{tmp1};
}

TNode<JSPromise> NewJSPromise_2(compiler::CodeAssemblerState* state_, TNode<Context> p_context, Promise::PromiseState p_status, TNode<Object> p_result) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Oddball> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = InnerNewJSPromise_0(state_, TNode<Context>{p_context});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1}, p_result);
    Method_JSPromise_SetStatus_0(state_, TNode<JSPromise>{tmp0}, p_status);
    PromiseBuiltinsAssembler(state_).ZeroOutEmbedderOffsets(TNode<JSPromise>{tmp0});
    tmp2 = Undefined_0(state_);
    RunAnyPromiseHookInit_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{tmp0}, TNode<Object>{tmp2});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<JSPromise>{tmp0};
}

TNode<PromiseReaction> NewPromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_handlerContext, TNode<Object> p_next, TNode<HeapObject> p_promiseOrCapability, TNode<HeapObject> p_fulfillHandler, TNode<HeapObject> p_rejectHandler) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Map> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<PromiseReaction> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_handlerContext});
    tmp1 = CodeStubAssembler(state_).PromiseReactionMapConstant();
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX_0(state_, Context::Field::CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp7}, p_next);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp8}, p_rejectHandler);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp9}, p_fulfillHandler);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp10}, p_promiseOrCapability);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp11}, tmp3);
    tmp12 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<PromiseReaction>{tmp12};
}

TNode<PromiseResolveThenableJobTask> NewPromiseResolveThenableJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promiseToResolve, TNode<JSReceiver> p_thenable, TNode<JSReceiver> p_then) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<NativeContext> tmp1;
  TNode<Map> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<HeapObject> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<PromiseResolveThenableJobTask> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ExtractHandlerContext_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_then});
    tmp1 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    tmp2 = CodeStubAssembler(state_).PromiseResolveThenableJobTaskMapConstant();
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp4 = Allocate_0(state_, TNode<IntPtrT>{tmp3}, TNode<Map>{tmp2});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp4, tmp5}, tmp2);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp4, tmp6}, tmp1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<JSPromise>(CodeStubAssembler::Reference{tmp4, tmp7}, p_promiseToResolve);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp4, tmp8}, p_thenable);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp4, tmp9}, p_then);
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<PromiseResolveThenableJobTask>{tmp10};
}

TNode<Object> InvokeThen_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    tmp1 = InvokeThen_InvokeThenOneArgFunctor_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{p_nativeContext}, TNode<Object>{p_receiver}, TNode<Object>{p_arg}, TNode<Object>{tmp0}, TorqueStructInvokeThenOneArgFunctor_0{});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

TNode<Object> InvokeThen_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = InvokeThen_InvokeThenTwoArgFunctor_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{p_nativeContext}, TNode<Object>{p_receiver}, TNode<Object>{p_arg1}, TNode<Object>{p_arg2}, TorqueStructInvokeThenTwoArgFunctor_0{});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp0};
}

void BranchIfAccessCheckFailed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_promiseConstructor, TNode<Object> p_executor, compiler::CodeAssemblerLabel* label_IfNoAccess) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block9, p_executor);
  }

  TNode<Object> phi_bb9_4;
  TNode<BoolT> tmp0;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_4);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp0, &block7, std::vector<Node*>{phi_bb9_4}, &block8, std::vector<Node*>{phi_bb9_4});
  }

  TNode<Object> phi_bb7_4;
  TNode<JSFunction> tmp1;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_4);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_JSFunction_1(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb7_4}, &label2);
    ca_.Goto(&block12, phi_bb7_4, phi_bb7_4, phi_bb7_4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block13, phi_bb7_4, phi_bb7_4, phi_bb7_4);
    }
  }

  TNode<Object> phi_bb13_4;
  TNode<Object> phi_bb13_5;
  TNode<Object> phi_bb13_6;
  TNode<JSBoundFunction> tmp3;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_4, &phi_bb13_5, &phi_bb13_6);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSBoundFunction_1(state_, TNode<Context>{p_context}, TNode<Object>{ca_.UncheckedCast<Object>(phi_bb13_5)}, &label4);
    ca_.Goto(&block19, phi_bb13_4, phi_bb13_5);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block20, phi_bb13_4, phi_bb13_5);
    }
  }

  TNode<Object> phi_bb12_4;
  TNode<Object> phi_bb12_5;
  TNode<Object> phi_bb12_6;
  TNode<IntPtrT> tmp5;
  TNode<Context> tmp6;
  TNode<NativeContext> tmp7;
  TNode<BoolT> tmp8;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_4, &phi_bb12_5, &phi_bb12_6);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp6 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp1, tmp5});
    tmp7 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp6});
    tmp8 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{p_nativeContext}, TNode<HeapObject>{tmp7});
    ca_.Branch(tmp8, &block14, std::vector<Node*>{phi_bb12_4, phi_bb12_5}, &block15, std::vector<Node*>{phi_bb12_4, phi_bb12_5});
  }

  TNode<Object> phi_bb14_4;
  TNode<Object> phi_bb14_5;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_4, &phi_bb14_5);
    ca_.Goto(&block3);
  }

  TNode<Object> phi_bb15_4;
  TNode<Object> phi_bb15_5;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_4, &phi_bb15_5);
    ca_.Goto(&block6);
  }

  TNode<Object> phi_bb20_4;
  TNode<Object> phi_bb20_5;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_4, &phi_bb20_5);
    ca_.Goto(&block6);
  }

  TNode<Object> phi_bb19_4;
  TNode<Object> phi_bb19_5;
  TNode<IntPtrT> tmp9;
  TNode<JSReceiver> tmp10;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_4, &phi_bb19_5);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp10 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp3, tmp9});
    ca_.Goto(&block9, tmp10);
  }

  TNode<Object> phi_bb8_4;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    ca_.Goto(&block5);
  }

  TNode<Object> tmp11;
  TNode<Oddball> tmp12;
  TNode<BoolT> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp11 = CodeStubAssembler(state_).CallRuntime(Runtime::kAllowDynamicFunction, p_context, p_promiseConstructor); 
    tmp12 = True_0(state_);
    tmp13 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp11}, TNode<HeapObject>{tmp12});
    ca_.Branch(tmp13, &block21, std::vector<Node*>{}, &block22, std::vector<Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(label_IfNoAccess);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block23);
  }

    ca_.Bind(&block23);
}

TNode<Smi> SmiTag_JSPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{p_value});
    tmp1 = (TNode<Smi>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

TNode<BoolT> Is_JSPromise_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
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

TNode<JSPromise> Cast_JSPromise_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<JSPromise> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSPromise_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSPromise>{tmp2};
}

TNode<Object> InvokeThen_InvokeThenOneArgFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2, TorqueStructInvokeThenOneArgFunctor_0 p_callFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Is_Smi_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver});
    tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    ca_.Branch(tmp1, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Map> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp4 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp2, tmp3});
    tmp5 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{p_nativeContext}, TNode<Map>{tmp4});
    ca_.Goto(&block6, tmp5);
  }

  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp6);
  }

  TNode<BoolT> phi_bb6_6;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6);
    ca_.Branch(phi_bb6_6, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<Object> tmp9;
  TNode<Object> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp7});
    tmp9 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = CodeStubAssembler(state_).Call(TNode<Context>{p_nativeContext}, TNode<Object>{tmp9}, TNode<Object>{p_receiver}, TNode<Object>{p_arg1});
    ca_.Goto(&block1, tmp10);
  }

  TNode<String> tmp11;
  TNode<Object> tmp12;
  TNode<Object> tmp13;
  TNode<Object> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp11 = kThenString_0(state_);
    tmp12 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_receiver}, TNode<Object>{tmp11});
    tmp13 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp12});
    tmp14 = CodeStubAssembler(state_).Call(TNode<Context>{p_nativeContext}, TNode<Object>{tmp13}, TNode<Object>{p_receiver}, TNode<Object>{p_arg1});
    ca_.Goto(&block1, tmp14);
  }

  TNode<Object> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TNode<Object>{phi_bb1_5};
}

TNode<Object> InvokeThen_InvokeThenTwoArgFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_arg1, TNode<Object> p_arg2, TorqueStructInvokeThenTwoArgFunctor_0 p_callFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Is_Smi_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver});
    tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    ca_.Branch(tmp1, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Map> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{p_receiver});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp4 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp2, tmp3});
    tmp5 = IsPromiseThenLookupChainIntact_0(state_, TNode<Context>{p_context}, TNode<NativeContext>{p_nativeContext}, TNode<Map>{tmp4});
    ca_.Goto(&block6, tmp5);
  }

  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp6);
  }

  TNode<BoolT> phi_bb6_6;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6);
    ca_.Branch(phi_bb6_6, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<Object> tmp9;
  TNode<Object> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp7});
    tmp9 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = CodeStubAssembler(state_).Call(TNode<Context>{p_nativeContext}, TNode<Object>{tmp9}, TNode<Object>{p_receiver}, TNode<Object>{p_arg1}, TNode<Object>{p_arg2});
    ca_.Goto(&block1, tmp10);
  }

  TNode<String> tmp11;
  TNode<Object> tmp12;
  TNode<Object> tmp13;
  TNode<Object> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp11 = kThenString_0(state_);
    tmp12 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_receiver}, TNode<Object>{tmp11});
    tmp13 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp12});
    tmp14 = CodeStubAssembler(state_).Call(TNode<Context>{p_nativeContext}, TNode<Object>{tmp13}, TNode<Object>{p_receiver}, TNode<Object>{p_arg1}, TNode<Object>{p_arg2});
    ca_.Goto(&block1, tmp14);
  }

  TNode<Object> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TNode<Object>{phi_bb1_5};
}

TNode<BoolT> Is_Smi_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_o}, &label1);
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

