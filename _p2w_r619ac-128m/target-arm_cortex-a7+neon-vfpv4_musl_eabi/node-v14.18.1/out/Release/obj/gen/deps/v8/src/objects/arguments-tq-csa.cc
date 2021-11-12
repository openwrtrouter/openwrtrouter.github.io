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

TNode<BoolT> IsJSArgumentsObjectWithLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Is_JSArgumentsObjectWithLength_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{p_o});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BoolT>{tmp0};
}

TNode<JSArgumentsObject> NewJSStrictArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<FixedArray> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<JSArgumentsObject> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetStrictArgumentsMap_0(state_, TNode<Context>{p_context});
    tmp1 = kEmptyFixedArray_0(state_);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_elements, tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp0});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp0);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp1);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp5, tmp8}, p_elements);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp9}, tmp3);
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArgumentsObject>{tmp10};
}

TNode<JSArgumentsObject> NewJSSloppyArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<JSFunction> p_callee) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<FixedArray> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<JSArgumentsObject> tmp11;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetSloppyArgumentsMap_0(state_, TNode<Context>{p_context});
    tmp1 = kEmptyFixedArray_0(state_);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_elements, tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp0});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp0);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp1);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp5, tmp8}, p_elements);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp9}, tmp3);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp10}, p_callee);
    tmp11 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArgumentsObject>{tmp11};
}

TNode<JSArgumentsObject> NewJSFastAliasedArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<Smi> p_length, TNode<JSFunction> p_callee) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<FixedArray> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<HeapObject> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<JSArgumentsObject> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetFastAliasedArgumentsMap_0(state_, TNode<Context>{p_context});
    tmp1 = kEmptyFixedArray_0(state_);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp3 = Allocate_0(state_, TNode<IntPtrT>{tmp2}, TNode<Map>{tmp0});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp3, tmp4}, tmp0);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp3, tmp5}, tmp1);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp3, tmp6}, p_elements);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp3, tmp7}, p_length);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp3, tmp8}, p_callee);
    tmp9 = TORQUE_CAST(TNode<HeapObject>{tmp3});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArgumentsObject>{tmp9};
}

TorqueStructParameterMapIterator_0 NewParameterMapIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_elements, TNode<IntPtrT> p_formalParameterCount, TNode<IntPtrT> p_mappedCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<ScopeInfo> tmp1;
  TNode<Uint32T> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<ScopeInfo>(CodeStubAssembler::Reference{p_context, tmp0});
    tmp2 = LoadScopeInfoFlags_0(state_, TNode<Context>{p_context}, TNode<ScopeInfo>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, Context::MIN_CONTEXT_SLOTS);
    tmp4 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 26, 1, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp2)));
    ca_.Branch(tmp4, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{tmp3});
  }

  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp5});
    ca_.Goto(&block3, tmp6);
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{p_formalParameterCount});
    tmp8 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{p_mappedCount});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TorqueStructParameterMapIterator_0{TNode<Context>{p_context}, TNode<FixedArray>{p_elements}, TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9}};
}

TorqueStructParameterValueIterator_0 NewParameterValueIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_mappedCount, TorqueStructArguments p_arguments) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructParameterValueIterator_0{TNode<IntPtrT>{p_mappedCount}, TorqueStructArguments{TNode<RawPtrT>{p_arguments.frame}, TNode<RawPtrT>{p_arguments.base}, TNode<IntPtrT>{p_arguments.length}}, TNode<IntPtrT>{p_mappedCount}};
}

TNode<JSArray> NewAllArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_frame, TNode<IntPtrT> p_argumentCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<RawPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<FixedArray> tmp5;
  TNode<JSArray> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{p_context});
    std::tie(tmp1, tmp2, tmp3) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{p_frame}, TNode<IntPtrT>{p_argumentCount}).Flatten();
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp5 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{p_argumentCount}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp1}, TNode<RawPtrT>{tmp2}, TNode<IntPtrT>{tmp3}}, TNode<IntPtrT>{tmp4}});
    tmp6 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp0}, TNode<FixedArrayBase>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArray>{tmp6};
}

TNode<JSArray> NewRestArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_bint_0(state_, TNode<BInt>{p_info.argument_count});
    tmp1 = Convert_intptr_bint_0(state_, TNode<BInt>{p_info.formal_parameter_count});
    tmp2 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{p_context});
    tmp3 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp4);
  }

  TNode<IntPtrT> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp5 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block4, tmp5);
  }

  TNode<IntPtrT> phi_bb4_7;
  TNode<RawPtrT> tmp6;
  TNode<RawPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<FixedArray> tmp9;
  TNode<JSArray> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_7);
    std::tie(tmp6, tmp7, tmp8) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{p_info.frame}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp9 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{phi_bb4_7}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp6}, TNode<RawPtrT>{tmp7}, TNode<IntPtrT>{tmp8}}, TNode<IntPtrT>{tmp1}});
    tmp10 = NewJSArray_0(state_, TNode<Context>{p_context}, TNode<Map>{tmp2}, TNode<FixedArrayBase>{tmp9});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<JSArray>{tmp10};
}

TNode<JSArgumentsObject> NewStrictArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<RawPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<FixedArray> tmp5;
  TNode<JSArgumentsObject> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_bint_0(state_, TNode<BInt>{p_info.argument_count});
    std::tie(tmp1, tmp2, tmp3) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{p_info.frame}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp5 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp0}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp1}, TNode<RawPtrT>{tmp2}, TNode<IntPtrT>{tmp3}}, TNode<IntPtrT>{tmp4}});
    tmp6 = NewJSStrictArgumentsObject_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArgumentsObject>{tmp6};
}

TNode<JSArgumentsObject> NewSloppyArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructFrameWithArgumentsInfo_0 p_info, TNode<JSFunction> p_callee) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSArgumentsObject> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<RawPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_bint_0(state_, TNode<BInt>{p_info.argument_count});
    std::tie(tmp1, tmp2, tmp3) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{p_info.frame}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp4 = Convert_intptr_bint_0(state_, TNode<BInt>{p_info.formal_parameter_count});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<FixedArray> tmp8;
  TNode<JSArgumentsObject> tmp9;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp8 = NewFixedArray_ArgumentsIterator_0(state_, TNode<IntPtrT>{tmp0}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{tmp1}, TNode<RawPtrT>{tmp2}, TNode<IntPtrT>{tmp3}}, TNode<IntPtrT>{tmp7}});
    tmp9 = NewJSSloppyArgumentsObject_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp8}, TNode<JSFunction>{p_callee});
    ca_.Goto(&block1, tmp9);
  }

  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<RawPtrT> tmp12;
  TNode<RawPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<FixedArray> tmp16;
  TNode<Context> tmp17;
  TNode<FixedArray> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Smi> tmp24;
  TNode<Map> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<HeapObject> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<FixedArray> tmp33;
  TNode<Smi> tmp34;
  TNode<JSArgumentsObject> tmp35;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp10 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp0});
    std::tie(tmp11, tmp12, tmp13, tmp14, tmp15) = NewParameterValueIterator_0(state_, TNode<IntPtrT>{tmp10}, TorqueStructArguments{TNode<RawPtrT>{tmp1}, TNode<RawPtrT>{tmp2}, TNode<IntPtrT>{tmp3}}).Flatten();
    tmp16 = NewFixedArray_ParameterValueIterator_0(state_, TNode<IntPtrT>{tmp0}, TorqueStructParameterValueIterator_0{TNode<IntPtrT>{tmp11}, TorqueStructArguments{TNode<RawPtrT>{tmp12}, TNode<RawPtrT>{tmp13}, TNode<IntPtrT>{tmp14}}, TNode<IntPtrT>{tmp15}});
    std::tie(tmp17, tmp18, tmp19, tmp20, tmp21) = NewParameterMapIterator_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp16}, TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, SloppyArgumentsElements::kParameterMapStart);
    tmp23 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp22});
    tmp24 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp23});
    tmp25 = kSloppyArgumentsElementsMap_0(state_);
    tmp26 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp24});
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp28 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp26}, kTaggedSize);
    tmp29 = Allocate_0(state_, TNode<IntPtrT>{tmp28}, TNode<Map>{tmp25});
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp29, tmp30}, tmp25);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp29, tmp31}, tmp24);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ParameterMapIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp32}, TNode<IntPtrT>{tmp26}, TorqueStructUnsafe_0{}}, TorqueStructParameterMapIterator_0{TNode<Context>{tmp17}, TNode<FixedArray>{tmp18}, TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21}});
    tmp33 = TORQUE_CAST(TNode<HeapObject>{tmp29});
    tmp34 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp0});
    tmp35 = NewJSFastAliasedArgumentsObject_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp33}, TNode<Smi>{tmp34}, TNode<JSFunction>{p_callee});
    ca_.Goto(&block1, tmp35);
  }

  TNode<JSArgumentsObject> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
  return TNode<JSArgumentsObject>{phi_bb1_5};
}

TNode<JSArray> EmitFastNewAllArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_frame, TNode<IntPtrT> p_argc) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = NewAllArguments_0(state_, TNode<Context>{p_context}, TNode<RawPtrT>{p_frame}, TNode<IntPtrT>{p_argc});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArray>{tmp0};
}

TNode<JSArray> EmitFastNewRestArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p__f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<BInt> tmp1;
  TNode<BInt> tmp2;
  TNode<JSArray> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = GetFrameWithArgumentsInfo_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = NewRestArguments_0(state_, TNode<Context>{p_context}, TorqueStructFrameWithArgumentsInfo_0{TNode<RawPtrT>{tmp0}, TNode<BInt>{tmp1}, TNode<BInt>{tmp2}});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArray>{tmp3};
}

TNode<JSArgumentsObject> EmitFastNewStrictArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p__f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<BInt> tmp1;
  TNode<BInt> tmp2;
  TNode<JSArgumentsObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = GetFrameWithArgumentsInfo_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = NewStrictArguments_0(state_, TNode<Context>{p_context}, TorqueStructFrameWithArgumentsInfo_0{TNode<RawPtrT>{tmp0}, TNode<BInt>{tmp1}, TNode<BInt>{tmp2}});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArgumentsObject>{tmp3};
}

TNode<JSArgumentsObject> EmitFastNewSloppyArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_f) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<BInt> tmp1;
  TNode<BInt> tmp2;
  TNode<JSArgumentsObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = GetFrameWithArgumentsInfo_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = NewSloppyArguments_0(state_, TNode<Context>{p_context}, TorqueStructFrameWithArgumentsInfo_0{TNode<RawPtrT>{tmp0}, TNode<BInt>{tmp1}, TNode<BInt>{tmp2}}, TNode<JSFunction>{p_f});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSArgumentsObject>{tmp3};
}

TNode<Object> LoadJSStrictArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

void StoreJSStrictArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Object> LoadJSSloppyArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

void StoreJSSloppyArgumentsObjectLength_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Object> LoadJSSloppyArgumentsObjectCallee_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

void StoreJSSloppyArgumentsObjectCallee_0(compiler::CodeAssemblerState* state_, TNode<JSArgumentsObject> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadAliasedArgumentsEntryAliasedContextSlot_0(compiler::CodeAssemblerState* state_, TNode<AliasedArgumentsEntry> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreAliasedArgumentsEntryAliasedContextSlot_0(compiler::CodeAssemblerState* state_, TNode<AliasedArgumentsEntry> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<BoolT> Is_JSArgumentsObjectWithLength_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArgumentsObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSArgumentsObjectWithLength_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
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

TNode<FixedArray> NewFixedArray_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructArgumentsIterator_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{p_length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<FixedArray> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, FixedArray::kMaxLength);
    tmp4 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{p_length}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<Smi> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp5 = kNoContext_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kFatalProcessOutOfMemoryInvalidArrayLength, tmp5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Map> tmp6;
  TNode<Smi> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<FixedArray> tmp15;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = kFixedArrayMap_0(state_);
    tmp7 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{p_length});
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp8}, kTaggedSize);
    tmp11 = Allocate_0(state_, TNode<IntPtrT>{tmp10}, TNode<Map>{tmp6});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp11, tmp12}, tmp6);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp13}, tmp7);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ArgumentsIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp11}, TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}, TorqueStructArgumentsIterator_0{TorqueStructArguments{TNode<RawPtrT>{p_it.arguments.frame}, TNode<RawPtrT>{p_it.arguments.base}, TNode<IntPtrT>{p_it.arguments.length}}, TNode<IntPtrT>{p_it.current}});
    tmp15 = TORQUE_CAST(TNode<HeapObject>{tmp11});
    ca_.Goto(&block1, tmp15);
  }

  TNode<FixedArray> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.Goto(&block6, phi_bb1_5);
  }

  TNode<FixedArray> phi_bb6_5;
    ca_.Bind(&block6, &phi_bb6_5);
  return TNode<FixedArray>{phi_bb6_5};
}

TNode<FixedArray> NewFixedArray_ParameterValueIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructParameterValueIterator_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{p_length}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<FixedArray> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = kEmptyFixedArray_0(state_);
    ca_.Goto(&block1, tmp2);
  }

  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, FixedArray::kMaxLength);
    tmp4 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{p_length}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<Smi> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp5 = kNoContext_0(state_);
    CodeStubAssembler(state_).CallRuntime(Runtime::kFatalProcessOutOfMemoryInvalidArrayLength, tmp5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Map> tmp6;
  TNode<Smi> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<FixedArray> tmp15;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = kFixedArrayMap_0(state_);
    tmp7 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{p_length});
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp8}, kTaggedSize);
    tmp11 = Allocate_0(state_, TNode<IntPtrT>{tmp10}, TNode<Map>{tmp6});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp11, tmp12}, tmp6);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp13}, tmp7);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ParameterValueIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp11}, TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}, TorqueStructParameterValueIterator_0{TNode<IntPtrT>{p_it.mapped_count}, TorqueStructArguments{TNode<RawPtrT>{p_it.arguments.frame}, TNode<RawPtrT>{p_it.arguments.base}, TNode<IntPtrT>{p_it.arguments.length}}, TNode<IntPtrT>{p_it.current}});
    tmp15 = TORQUE_CAST(TNode<HeapObject>{tmp11});
    ca_.Goto(&block1, tmp15);
  }

  TNode<FixedArray> phi_bb1_6;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_6);
    ca_.Goto(&block6, phi_bb1_6);
  }

  TNode<FixedArray> phi_bb6_6;
    ca_.Bind(&block6, &phi_bb6_6);
  return TNode<FixedArray>{phi_bb6_6};
}

void InitializeFieldsFromIterator_Object_ParameterMapIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructParameterMapIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset, p_originIterator.currentIndex, p_originIterator.currentMapSlot);
  }

  TNode<IntPtrT> phi_bb5_9;
  TNode<IntPtrT> phi_bb5_13;
  TNode<IntPtrT> phi_bb5_15;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_9, &phi_bb5_13, &phi_bb5_15);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_9, phi_bb5_13, phi_bb5_15}, &block4, std::vector<Node*>{phi_bb5_9, phi_bb5_13, phi_bb5_15});
  }

  TNode<IntPtrT> phi_bb3_9;
  TNode<IntPtrT> phi_bb3_13;
  TNode<IntPtrT> phi_bb3_15;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_9, &phi_bb3_13, &phi_bb3_15);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_9}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_9, phi_bb3_13, phi_bb3_15}, &block10, std::vector<Node*>{phi_bb3_9, phi_bb3_13, phi_bb3_15});
  }

  TNode<IntPtrT> phi_bb9_9;
  TNode<IntPtrT> phi_bb9_13;
  TNode<IntPtrT> phi_bb9_15;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_9, &phi_bb9_13, &phi_bb9_15);
    ca_.Goto(&block4, phi_bb9_9, phi_bb9_13, phi_bb9_15);
  }

  TNode<IntPtrT> phi_bb10_9;
  TNode<IntPtrT> phi_bb10_13;
  TNode<IntPtrT> phi_bb10_15;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_9, &phi_bb10_13, &phi_bb10_15);
    std::tie(tmp5, tmp6) = NewReference_Object_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_9}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_9}, TNode<IntPtrT>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_15}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp12 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb10_15}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp12, &block16, std::vector<Node*>{phi_bb10_13, phi_bb10_15}, &block17, std::vector<Node*>{phi_bb10_13, phi_bb10_15});
  }

  TNode<IntPtrT> phi_bb16_13;
  TNode<IntPtrT> phi_bb16_20;
  TNode<BoolT> tmp13;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_13, &phi_bb16_20);
    tmp13 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb16_13}, TNode<IntPtrT>{p_originIterator.endInterationIndex});
    ca_.Branch(tmp13, &block19, std::vector<Node*>{phi_bb16_13, phi_bb16_20}, &block20, std::vector<Node*>{phi_bb16_13, phi_bb16_20});
  }

  TNode<IntPtrT> phi_bb19_13;
  TNode<IntPtrT> phi_bb19_20;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_13, &phi_bb19_20);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb20_13;
  TNode<IntPtrT> phi_bb20_20;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Smi> tmp16;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_13, &phi_bb20_20);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp15 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb20_13}, TNode<IntPtrT>{tmp14});
    tmp16 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp15});
    ca_.Goto(&block15, tmp15, tmp16);
  }

  TNode<IntPtrT> phi_bb17_13;
  TNode<IntPtrT> phi_bb17_20;
  TNode<IntPtrT> tmp17;
  TNode<BoolT> tmp18;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_13, &phi_bb17_20);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp18 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb17_20}, TNode<IntPtrT>{tmp17});
    ca_.Branch(tmp18, &block21, std::vector<Node*>{phi_bb17_13, phi_bb17_20}, &block22, std::vector<Node*>{phi_bb17_13, phi_bb17_20});
  }

  TNode<IntPtrT> phi_bb21_13;
  TNode<IntPtrT> phi_bb21_20;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_13, &phi_bb21_20);
    ca_.Goto(&block15, phi_bb21_13, p_originIterator.context);
  }

  TNode<IntPtrT> phi_bb22_13;
  TNode<IntPtrT> phi_bb22_20;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_13, &phi_bb22_20);
    ca_.Goto(&block15, phi_bb22_13, p_originIterator.elements);
  }

  TNode<IntPtrT> phi_bb15_13;
  TNode<Object> phi_bb15_20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_13, &phi_bb15_20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, phi_bb15_20);
    ca_.Goto(&block5, tmp8, phi_bb15_13, tmp10);
  }

  TNode<IntPtrT> phi_bb4_9;
  TNode<IntPtrT> phi_bb4_13;
  TNode<IntPtrT> phi_bb4_15;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_9, &phi_bb4_13, &phi_bb4_15);
    ca_.Goto(&block28);
  }

    ca_.Bind(&block28);
}

}  // namespace internal
}  // namespace v8

