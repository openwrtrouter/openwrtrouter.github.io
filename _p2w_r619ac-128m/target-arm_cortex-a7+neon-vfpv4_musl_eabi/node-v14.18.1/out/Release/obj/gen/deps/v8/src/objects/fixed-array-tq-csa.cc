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

void StoreFixedDoubleArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<UintPtrT> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_a, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp8 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp7});
    ca_.Branch(tmp8, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<HeapObject> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Float64T> tmp14;
  TNode<BoolT> tmp15;
  TNode<Float64T> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    tmp10 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp9});
    tmp11 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp10});
    std::tie(tmp12, tmp13) = NewReference_float64_or_hole_0(state_, TNode<HeapObject>{p_a}, TNode<IntPtrT>{tmp11}).Flatten();
    tmp14 = Convert_float64_Number_0(state_, TNode<Number>{p_v});
    std::tie(tmp15, tmp16) = Convert_float64_or_hole_float64_0(state_, TNode<Float64T>{tmp14}).Flatten();
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp13}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp15}, TNode<Float64T>{tmp16}});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

void StoreFixedArrayDirect_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_a, TNode<Smi> p_i, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<UintPtrT> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_a, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp8 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp7});
    ca_.Branch(tmp8, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<HeapObject> tmp12;
  TNode<IntPtrT> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp10 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp9});
    tmp11 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp10});
    std::tie(tmp12, tmp13) = NewReference_Object_0(state_, TNode<HeapObject>{p_a}, TNode<IntPtrT>{tmp11}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp12, tmp13}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<FixedArray> ExtractFixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<UintPtrT> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_source, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_first}, TNode<IntPtrT>{p_count});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp8 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp7});
    ca_.Branch(tmp8, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  TNode<UintPtrT> tmp9;
  TNode<UintPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_first});
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp11 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
    ca_.Goto(&block7, tmp11);
  }

  TNode<BoolT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp12);
  }

  TNode<BoolT> phi_bb7_16;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_16);
    ca_.Branch(phi_bb7_16, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<uintptr>(endIndex) <= Convert<uintptr>(this.length) && Convert<uintptr>(startIndex) <= Convert<uintptr>(endIndex)' failed", "../../deps/v8/src/builtins/torque-internal.tq", 68);
  }

  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<Oddball> tmp19;
  TNode<Oddball> tmp20;
  TNode<HeapObject> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Oddball> tmp24;
  TNode<FixedArray> tmp25;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp14 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_first}, TNode<IntPtrT>{tmp13});
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp17 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp16});
    tmp18 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp17});
    tmp19 = TheHole_0(state_);
    std::tie(tmp20) = ConstantIterator_TheHole_0(state_, TNode<Oddball>{tmp19}).Flatten();
    std::tie(tmp21, tmp22, tmp23, tmp24) = IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(state_, TorqueStructSliceIterator_Object_0{TNode<HeapObject>{p_source}, TNode<IntPtrT>{tmp15}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp20}}).Flatten();
    tmp25 = NewFixedArray_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(state_, TNode<IntPtrT>{p_capacity}, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0{TorqueStructSliceIterator_Object_0{TNode<HeapObject>{tmp21}, TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp24}}});
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<FixedArray>{tmp25};
}

TNode<FixedArrayBase> ExtractFixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_source, TNode<IntPtrT> p_first, TNode<IntPtrT> p_count, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<UintPtrT> tmp7;
  TNode<BoolT> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_source, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_first}, TNode<IntPtrT>{p_count});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp8 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp6}, TNode<UintPtrT>{tmp7});
    ca_.Branch(tmp8, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  TNode<UintPtrT> tmp9;
  TNode<UintPtrT> tmp10;
  TNode<BoolT> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_first});
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp11 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
    ca_.Goto(&block7, tmp11);
  }

  TNode<BoolT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp12);
  }

  TNode<BoolT> phi_bb7_16;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_16);
    ca_.Branch(phi_bb7_16, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<uintptr>(endIndex) <= Convert<uintptr>(this.length) && Convert<uintptr>(startIndex) <= Convert<uintptr>(endIndex)' failed", "../../deps/v8/src/builtins/torque-internal.tq", 68);
  }

  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<BoolT> tmp19;
  TNode<Float64T> tmp20;
  TNode<BoolT> tmp21;
  TNode<Float64T> tmp22;
  TNode<HeapObject> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<BoolT> tmp26;
  TNode<Float64T> tmp27;
  TNode<FixedArrayBase> tmp28;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    tmp14 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_first}, TNode<IntPtrT>{tmp13});
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp14});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    tmp17 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp16});
    tmp18 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp17});
    std::tie(tmp19, tmp20) = kDoubleHole_0(state_).Flatten();
    std::tie(tmp21, tmp22) = ConstantIterator_float64_or_hole_0(state_, TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp19}, TNode<Float64T>{tmp20}}).Flatten();
    std::tie(tmp23, tmp24, tmp25, tmp26, tmp27) = IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(state_, TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{p_source}, TNode<IntPtrT>{tmp15}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp21}, TNode<Float64T>{tmp22}}}).Flatten();
    tmp28 = NewFixedDoubleArray_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(state_, TNode<IntPtrT>{p_capacity}, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0{TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{tmp23}, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp25}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{tmp26}, TNode<Float64T>{tmp27}}}});
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<FixedArrayBase>{tmp28};
}

TNode<Smi> LoadFixedArrayBaseLength_0(compiler::CodeAssemblerState* state_, TNode<FixedArrayBase> p_o) {
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

TNode<Object> LoadFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Object> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Object_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Object>{tmp13};
}

void StoreFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Object_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp11, tmp12}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadByteArrayBytes_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Uint8T> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp13};
}

void StoreByteArrayBytes_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp11, tmp12}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Smi> LoadWeakFixedArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o) {
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

TNode<MaybeObject> LoadWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<MaybeObject> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_MaybeObject_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<MaybeObject>{tmp13};
}

void StoreWeakFixedArrayObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakFixedArray> p_o, TNode<IntPtrT> p_i, TNode<MaybeObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_MaybeObject_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference{tmp11, tmp12}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Smi> LoadWeakArrayListCapacity_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o) {
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

TNode<Smi> LoadWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreWeakArrayListLength_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<MaybeObject> LoadWeakArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<MaybeObject> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_MaybeObject_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<MaybeObject>{tmp13};
}

void StoreWeakArrayListObjects_0(compiler::CodeAssemblerState* state_, TNode<WeakArrayList> p_o, TNode<IntPtrT> p_i, TNode<MaybeObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_MaybeObject_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference{tmp11, tmp12}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TorqueStructConstantIterator_TheHole_0 ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{p_value}};
}

TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_Object_0 p_first, TorqueStructConstantIterator_TheHole_0 p_second) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0{TorqueStructSliceIterator_Object_0{TNode<HeapObject>{p_first.object}, TNode<IntPtrT>{p_first.start}, TNode<IntPtrT>{p_first.end}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{p_second.value}}};
}

TNode<FixedArray> NewFixedArray_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 p_it) {
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
    InitializeFieldsFromIterator_Object_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp11}, TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0{TorqueStructSliceIterator_Object_0{TNode<HeapObject>{p_it.first.object}, TNode<IntPtrT>{p_it.first.start}, TNode<IntPtrT>{p_it.first.end}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{p_it.second.value}}});
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

TorqueStructConstantIterator_float64_or_hole_0 ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructfloat64_or_hole_0 p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{p_value.is_hole}, TNode<Float64T>{p_value.value}}};
}

TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructSliceIterator_float64_or_hole_0 p_first, TorqueStructConstantIterator_float64_or_hole_0 p_second) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0{TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{p_first.object}, TNode<IntPtrT>{p_first.start}, TNode<IntPtrT>{p_first.end}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{p_second.value.is_hole}, TNode<Float64T>{p_second.value.value}}}};
}

TNode<FixedArrayBase> NewFixedDoubleArray_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 p_it) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, FixedDoubleArray::kMaxLength);
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
  TNode<FixedDoubleArray> tmp15;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp6 = kFixedDoubleArrayMap_0(state_);
    tmp7 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{p_length});
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp8}, kDoubleSize);
    tmp11 = Allocate_0(state_, TNode<IntPtrT>{tmp10}, TNode<Map>{tmp6});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp11, tmp12}, tmp6);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp13}, tmp7);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_float64_or_hole_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(state_, TorqueStructSlice_float64_or_hole_0{TNode<HeapObject>{tmp11}, TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp8}, TorqueStructUnsafe_0{}}, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0{TorqueStructSliceIterator_float64_or_hole_0{TNode<HeapObject>{p_it.first.object}, TNode<IntPtrT>{p_it.first.start}, TNode<IntPtrT>{p_it.first.end}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_float64_or_hole_0{TorqueStructfloat64_or_hole_0{TNode<BoolT>{p_it.second.value.is_hole}, TNode<Float64T>{p_it.second.value.value}}}});
    tmp15 = TORQUE_CAST(TNode<HeapObject>{tmp11});
    ca_.Goto(&block1, tmp15);
  }

  TNode<FixedArrayBase> phi_bb1_6;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_6);
    ca_.Goto(&block6, phi_bb1_6);
  }

  TNode<FixedArrayBase> phi_bb6_6;
    ca_.Bind(&block6, &phi_bb6_6);
  return TNode<FixedArrayBase>{phi_bb6_6};
}

void InitializeFieldsFromIterator_Object_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructArgumentsIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset, p_originIterator.current);
  }

  TNode<IntPtrT> phi_bb5_8;
  TNode<IntPtrT> phi_bb5_13;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_13);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_8, phi_bb5_13}, &block4, std::vector<Node*>{phi_bb5_8, phi_bb5_13});
  }

  TNode<IntPtrT> phi_bb3_8;
  TNode<IntPtrT> phi_bb3_13;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_8, &phi_bb3_13);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_8}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_8, phi_bb3_13}, &block10, std::vector<Node*>{phi_bb3_8, phi_bb3_13});
  }

  TNode<IntPtrT> phi_bb9_8;
  TNode<IntPtrT> phi_bb9_13;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_13);
    ca_.Goto(&block4, phi_bb9_8, phi_bb9_13);
  }

  TNode<IntPtrT> phi_bb10_8;
  TNode<IntPtrT> phi_bb10_13;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<BoolT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_8, &phi_bb10_13);
    std::tie(tmp5, tmp6) = NewReference_Object_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_8}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_8}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb10_13}, TNode<IntPtrT>{p_originIterator.arguments.length});
    ca_.Branch(tmp9, &block16, std::vector<Node*>{phi_bb10_13}, &block17, std::vector<Node*>{phi_bb10_13});
  }

  TNode<IntPtrT> phi_bb16_13;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_13);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb17_13;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_13);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp11 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb17_13}, TNode<IntPtrT>{tmp10});
    tmp12 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_originIterator.arguments.frame}, TNode<RawPtrT>{p_originIterator.arguments.base}, TNode<IntPtrT>{p_originIterator.arguments.length}}, TNode<IntPtrT>{phi_bb17_13});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp12);
    ca_.Goto(&block5, tmp8, tmp11);
  }

  TNode<IntPtrT> phi_bb4_8;
  TNode<IntPtrT> phi_bb4_13;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_8, &phi_bb4_13);
    ca_.Goto(&block18);
  }

    ca_.Bind(&block18);
}

void InitializeFieldsFromIterator_Object_ParameterValueIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructParameterValueIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset, p_originIterator.mapped_count, p_originIterator.current);
  }

  TNode<IntPtrT> phi_bb5_9;
  TNode<IntPtrT> phi_bb5_11;
  TNode<IntPtrT> phi_bb5_15;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_9, &phi_bb5_11, &phi_bb5_15);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_9, phi_bb5_11, phi_bb5_15}, &block4, std::vector<Node*>{phi_bb5_9, phi_bb5_11, phi_bb5_15});
  }

  TNode<IntPtrT> phi_bb3_9;
  TNode<IntPtrT> phi_bb3_11;
  TNode<IntPtrT> phi_bb3_15;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_9, &phi_bb3_11, &phi_bb3_15);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_9}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_9, phi_bb3_11, phi_bb3_15}, &block10, std::vector<Node*>{phi_bb3_9, phi_bb3_11, phi_bb3_15});
  }

  TNode<IntPtrT> phi_bb9_9;
  TNode<IntPtrT> phi_bb9_11;
  TNode<IntPtrT> phi_bb9_15;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_9, &phi_bb9_11, &phi_bb9_15);
    ca_.Goto(&block4, phi_bb9_9, phi_bb9_11, phi_bb9_15);
  }

  TNode<IntPtrT> phi_bb10_9;
  TNode<IntPtrT> phi_bb10_11;
  TNode<IntPtrT> phi_bb10_15;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_9, &phi_bb10_11, &phi_bb10_15);
    std::tie(tmp5, tmp6) = NewReference_Object_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_9}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_9}, TNode<IntPtrT>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp10 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb10_11}, TNode<IntPtrT>{tmp9});
    ca_.Branch(tmp10, &block16, std::vector<Node*>{phi_bb10_11, phi_bb10_15}, &block17, std::vector<Node*>{phi_bb10_11, phi_bb10_15});
  }

  TNode<IntPtrT> phi_bb16_11;
  TNode<IntPtrT> phi_bb16_15;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Oddball> tmp13;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_11, &phi_bb16_15);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp12 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb16_11}, TNode<IntPtrT>{tmp11});
    tmp13 = TheHole_0(state_);
    ca_.Goto(&block15, tmp12, phi_bb16_15, tmp13);
  }

  TNode<IntPtrT> phi_bb17_11;
  TNode<IntPtrT> phi_bb17_15;
  TNode<BoolT> tmp14;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_11, &phi_bb17_15);
    tmp14 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb17_15}, TNode<IntPtrT>{p_originIterator.arguments.length});
    ca_.Branch(tmp14, &block18, std::vector<Node*>{phi_bb17_11, phi_bb17_15}, &block19, std::vector<Node*>{phi_bb17_11, phi_bb17_15});
  }

  TNode<IntPtrT> phi_bb18_11;
  TNode<IntPtrT> phi_bb18_15;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_11, &phi_bb18_15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb19_11;
  TNode<IntPtrT> phi_bb19_15;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_11, &phi_bb19_15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp16 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_15}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_originIterator.arguments.frame}, TNode<RawPtrT>{p_originIterator.arguments.base}, TNode<IntPtrT>{p_originIterator.arguments.length}}, TNode<IntPtrT>{phi_bb19_15});
    ca_.Goto(&block15, phi_bb19_11, tmp16, tmp17);
  }

  TNode<IntPtrT> phi_bb15_11;
  TNode<IntPtrT> phi_bb15_15;
  TNode<Object> phi_bb15_20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_11, &phi_bb15_15, &phi_bb15_20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, phi_bb15_20);
    ca_.Goto(&block5, tmp8, phi_bb15_11, phi_bb15_15);
  }

  TNode<IntPtrT> phi_bb4_9;
  TNode<IntPtrT> phi_bb4_11;
  TNode<IntPtrT> phi_bb4_15;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_9, &phi_bb4_11, &phi_bb4_15);
    ca_.Goto(&block20);
  }

    ca_.Bind(&block20);
}

void InitializeFieldsFromIterator_Object_IteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructIteratorSequence_Object_SliceIterator_Object_ConstantIterator_TheHole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset, p_originIterator.first.start);
  }

  TNode<IntPtrT> phi_bb5_8;
  TNode<IntPtrT> phi_bb5_11;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_11);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_8, phi_bb5_11}, &block4, std::vector<Node*>{phi_bb5_8, phi_bb5_11});
  }

  TNode<IntPtrT> phi_bb3_8;
  TNode<IntPtrT> phi_bb3_11;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_8, &phi_bb3_11);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_8}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_8, phi_bb3_11}, &block10, std::vector<Node*>{phi_bb3_8, phi_bb3_11});
  }

  TNode<IntPtrT> phi_bb9_8;
  TNode<IntPtrT> phi_bb9_11;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_11);
    ca_.Goto(&block4, phi_bb9_8, phi_bb9_11);
  }

  TNode<IntPtrT> phi_bb10_8;
  TNode<IntPtrT> phi_bb10_11;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<BoolT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_8, &phi_bb10_11);
    std::tie(tmp5, tmp6) = NewReference_Object_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_8}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_8}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb10_11}, TNode<IntPtrT>{p_originIterator.first.end});
    ca_.Branch(tmp9, &block20, std::vector<Node*>{phi_bb10_11}, &block21, std::vector<Node*>{phi_bb10_11});
  }

  TNode<IntPtrT> phi_bb20_11;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_11);
    ca_.Goto(&block15, phi_bb20_11, p_originIterator.second.value);
  }

  TNode<IntPtrT> phi_bb21_11;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Object> tmp14;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_11);
    std::tie(tmp10, tmp11) = NewReference_Object_0(state_, TNode<HeapObject>{p_originIterator.first.object}, TNode<IntPtrT>{phi_bb21_11}).Flatten();
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb21_11}, TNode<IntPtrT>{tmp12});
    tmp14 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp10, tmp11});
    ca_.Goto(&block15, tmp13, tmp14);
  }

  TNode<IntPtrT> phi_bb15_11;
  TNode<Object> phi_bb15_18;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_11, &phi_bb15_18);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, phi_bb15_18);
    ca_.Goto(&block5, tmp8, phi_bb15_11);
  }

  TNode<IntPtrT> phi_bb4_8;
  TNode<IntPtrT> phi_bb4_11;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_8, &phi_bb4_11);
    ca_.Goto(&block25);
  }

    ca_.Bind(&block25);
}

void InitializeFieldsFromIterator_float64_or_hole_IteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_float64_or_hole_0 p_target, TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_ConstantIterator_float64_or_hole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, BoolT, Float64T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset, p_originIterator.first.start);
  }

  TNode<IntPtrT> phi_bb5_9;
  TNode<IntPtrT> phi_bb5_12;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_9, &phi_bb5_12);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_9, phi_bb5_12}, &block4, std::vector<Node*>{phi_bb5_9, phi_bb5_12});
  }

  TNode<IntPtrT> phi_bb3_9;
  TNode<IntPtrT> phi_bb3_12;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_9, &phi_bb3_12);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_9}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_9, phi_bb3_12}, &block10, std::vector<Node*>{phi_bb3_9, phi_bb3_12});
  }

  TNode<IntPtrT> phi_bb9_9;
  TNode<IntPtrT> phi_bb9_12;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_9, &phi_bb9_12);
    ca_.Goto(&block4, phi_bb9_9, phi_bb9_12);
  }

  TNode<IntPtrT> phi_bb10_9;
  TNode<IntPtrT> phi_bb10_12;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<BoolT> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_9, &phi_bb10_12);
    std::tie(tmp5, tmp6) = NewReference_float64_or_hole_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_9}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_9}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb10_12}, TNode<IntPtrT>{p_originIterator.first.end});
    ca_.Branch(tmp9, &block20, std::vector<Node*>{phi_bb10_12}, &block21, std::vector<Node*>{phi_bb10_12});
  }

  TNode<IntPtrT> phi_bb20_12;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_12);
    ca_.Goto(&block15, phi_bb20_12, p_originIterator.second.value.is_hole, p_originIterator.second.value.value);
  }

  TNode<IntPtrT> phi_bb21_12;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<BoolT> tmp14;
  TNode<Float64T> tmp15;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_12);
    std::tie(tmp10, tmp11) = NewReference_float64_or_hole_0(state_, TNode<HeapObject>{p_originIterator.first.object}, TNode<IntPtrT>{phi_bb21_12}).Flatten();
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, kDoubleSize);
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb21_12}, TNode<IntPtrT>{tmp12});
    std::tie(tmp14, tmp15) = LoadFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block15, tmp13, tmp14, tmp15);
  }

  TNode<IntPtrT> phi_bb15_12;
  TNode<BoolT> phi_bb15_20;
  TNode<Float64T> phi_bb15_21;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_12, &phi_bb15_20, &phi_bb15_21);
    StoreFloat64OrHole_0(state_, TorqueStructReference_float64_or_hole_0{TNode<HeapObject>{tmp5}, TNode<IntPtrT>{tmp6}, TorqueStructUnsafe_0{}}, TorqueStructfloat64_or_hole_0{TNode<BoolT>{phi_bb15_20}, TNode<Float64T>{phi_bb15_21}});
    ca_.Goto(&block5, tmp8, phi_bb15_12);
  }

  TNode<IntPtrT> phi_bb4_9;
  TNode<IntPtrT> phi_bb4_12;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_9, &phi_bb4_12);
    ca_.Goto(&block25);
  }

    ca_.Bind(&block25);
}

}  // namespace internal
}  // namespace v8

