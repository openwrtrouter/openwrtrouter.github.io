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

TNode<Context> ExtractHandlerContextInternal_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler, compiler::CodeAssemblerLabel* label_NotFound) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block5, p_handler);
  }

  TNode<Object> phi_bb5_2;
  TNode<BoolT> tmp0;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_2);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp0, &block3, std::vector<Node*>{phi_bb5_2}, &block4, std::vector<Node*>{phi_bb5_2});
  }

  TNode<Object> phi_bb3_2;
  TNode<JSBoundFunction> tmp1;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2);
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_JSBoundFunction_1(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb3_2}, &label2);
    ca_.Goto(&block8, phi_bb3_2, phi_bb3_2, phi_bb3_2);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block9, phi_bb3_2, phi_bb3_2, phi_bb3_2);
    }
  }

  TNode<Object> phi_bb9_2;
  TNode<Object> phi_bb9_3;
  TNode<Object> phi_bb9_4;
  TNode<JSProxy> tmp3;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_2, &phi_bb9_3, &phi_bb9_4);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSProxy_1(state_, TNode<Context>{p_context}, TNode<Object>{ca_.UncheckedCast<Object>(phi_bb9_3)}, &label4);
    ca_.Goto(&block12, phi_bb9_2, phi_bb9_3);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block13, phi_bb9_2, phi_bb9_3);
    }
  }

  TNode<Object> phi_bb8_2;
  TNode<Object> phi_bb8_3;
  TNode<Object> phi_bb8_4;
  TNode<IntPtrT> tmp5;
  TNode<JSReceiver> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_2, &phi_bb8_3, &phi_bb8_4);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp6 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp1, tmp5});
    ca_.Goto(&block6, tmp6, phi_bb8_3);
  }

  TNode<Object> phi_bb13_2;
  TNode<Object> phi_bb13_3;
  TNode<JSFunction> tmp7;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_3);
    compiler::CodeAssemblerLabel label8(&ca_);
    tmp7 = Cast_JSFunction_1(state_, TNode<Context>{p_context}, TNode<Object>{ca_.UncheckedCast<Object>(phi_bb13_3)}, &label8);
    ca_.Goto(&block16, phi_bb13_2, phi_bb13_3);
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block17, phi_bb13_2, phi_bb13_3);
    }
  }

  TNode<Object> phi_bb12_2;
  TNode<Object> phi_bb12_3;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_3);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp9});
    ca_.Goto(&block6, tmp10, phi_bb12_3);
  }

  TNode<Object> phi_bb17_2;
  TNode<Object> phi_bb17_3;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_2, &phi_bb17_3);
    ca_.Goto(&block4, phi_bb17_2);
  }

  TNode<Object> phi_bb16_2;
  TNode<Object> phi_bb16_3;
  TNode<IntPtrT> tmp11;
  TNode<Context> tmp12;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_2, &phi_bb16_3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp12 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp7, tmp11});
    ca_.Goto(&block18);
  }

  TNode<Object> phi_bb6_2;
  TNode<Object> phi_bb6_3;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_2, &phi_bb6_3);
    ca_.Goto(&block5, phi_bb6_2);
  }

  TNode<Object> phi_bb4_2;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    ca_.Goto(label_NotFound);
  }

    ca_.Bind(&block18);
  return TNode<Context>{tmp12};
}

TNode<Context> ExtractHandlerContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = ExtractHandlerContextInternal_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_handler}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1, p_context);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1, tmp0);
  }

  TNode<Context> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Context>{phi_bb1_2};
}

TNode<Context> ExtractHandlerContext_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_primary, TNode<HeapObject> p_secondary) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = ExtractHandlerContextInternal_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_primary}, &label1);
    ca_.Goto(&block6);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7);
    }
  }

  TNode<Context> tmp2;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = ExtractHandlerContextInternal_0(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_secondary}, &label3);
    ca_.Goto(&block8);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1, tmp0);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block1, p_context);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block1, tmp2);
  }

  TNode<Context> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TNode<Context>{phi_bb1_3};
}

void MorphAndEnqueuePromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseReaction> p_promiseReaction, TNode<Object> p_argument, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, HeapObject> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<HeapObject> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_promiseReaction, tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp3 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_promiseReaction, tmp2});
    ca_.Goto(&block4, tmp1, tmp3);
  }

  TNode<BoolT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<HeapObject> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<HeapObject> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp4});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_promiseReaction, tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_promiseReaction, tmp7});
    ca_.Goto(&block4, tmp6, tmp8);
  }

  TNode<HeapObject> phi_bb4_3;
  TNode<HeapObject> phi_bb4_4;
  TNode<Context> tmp9;
  TNode<BoolT> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
    tmp9 = ExtractHandlerContext_1(state_, TNode<Context>{p_context}, TNode<HeapObject>{phi_bb4_3}, TNode<HeapObject>{phi_bb4_4});
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kSize, PromiseReactionJobTask::kSizeOfAllPromiseReactionJobTasks)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp10});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kFulfill)))) {
      ca_.Goto(&block5);
    } else {
      ca_.Goto(&block6);
    }
  }

  TNode<IntPtrT> tmp11;
  TNode<HeapObject> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Map> tmp14;
  TNode<PromiseFulfillReactionJobTask> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Oddball> tmp18;
  TNode<BoolT> tmp19;
  TNode<BoolT> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    std::tie(tmp12, tmp13) = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0{TNode<HeapObject>{p_promiseReaction}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}}).Flatten();
    tmp14 = CodeStubAssembler(state_).PromiseFulfillReactionJobTaskMapConstant();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp12, tmp13}, tmp14);
    tmp15 = UnsafeCast_PromiseFulfillReactionJobTask_0(state_, TNode<Context>{p_context}, TNode<Object>{p_promiseReaction});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp15, tmp16}, p_argument);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp15, tmp17}, tmp9);
    tmp18 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp9, tmp15));
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kFulfillHandlerOffset, PromiseReactionJobTask::kHandlerOffset)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp19});
    tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kPromiseOrCapabilityOffset, PromiseReactionJobTask::kPromiseOrCapabilityOffset)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp20});
    ca_.Goto(&block7);
  }

  TNode<BoolT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<HeapObject> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Map> tmp25;
  TNode<PromiseRejectReactionJobTask> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Oddball> tmp30;
  TNode<BoolT> tmp31;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_reactionType, PromiseReaction::kReject)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp21});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    std::tie(tmp23, tmp24) = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0{TNode<HeapObject>{p_promiseReaction}, TNode<IntPtrT>{tmp22}, TorqueStructUnsafe_0{}}).Flatten();
    tmp25 = CodeStubAssembler(state_).PromiseRejectReactionJobTaskMapConstant();
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp23, tmp24}, tmp25);
    tmp26 = UnsafeCast_PromiseRejectReactionJobTask_0(state_, TNode<Context>{p_context}, TNode<Object>{p_promiseReaction});
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp26, tmp27}, p_argument);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp26, tmp28}, tmp9);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp26, tmp29}, phi_bb4_3);
    tmp30 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp9, tmp26));
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(PromiseReaction::kPromiseOrCapabilityOffset, PromiseReactionJobTask::kPromiseOrCapabilityOffset)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp31});
    ca_.Goto(&block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TriggerPromiseReactions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_reactions, TNode<Object> p_argument, PromiseReaction::Type p_reactionType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kZero_0(state_);
    ca_.Goto(&block4, p_reactions, tmp0);
  }

  TNode<Object> phi_bb4_3;
  TNode<Object> phi_bb4_4;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp1, &block2, std::vector<Node*>{phi_bb4_3, phi_bb4_4}, &block3, std::vector<Node*>{phi_bb4_3, phi_bb4_4});
  }

  TNode<Object> phi_bb2_3;
  TNode<Object> phi_bb2_4;
  TNode<Smi> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_3, &phi_bb2_4);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Zero_0(state_, TNode<Object>{phi_bb2_3}, &label3);
    ca_.Goto(&block7, phi_bb2_3, phi_bb2_4, phi_bb2_3, phi_bb2_3);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8, phi_bb2_3, phi_bb2_4, phi_bb2_3, phi_bb2_3);
    }
  }

  TNode<Object> phi_bb8_3;
  TNode<Object> phi_bb8_4;
  TNode<Object> phi_bb8_5;
  TNode<Object> phi_bb8_6;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_3, &phi_bb8_4, &phi_bb8_5, &phi_bb8_6);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<PromiseReaction>(phi_bb8_5), tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<PromiseReaction>(phi_bb8_5), tmp6}, phi_bb8_4);
    ca_.Goto(&block4, tmp5, ca_.UncheckedCast<PromiseReaction>(phi_bb8_5));
  }

  TNode<Object> phi_bb7_3;
  TNode<Object> phi_bb7_4;
  TNode<Object> phi_bb7_5;
  TNode<Object> phi_bb7_6;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3, &phi_bb7_4, &phi_bb7_5, &phi_bb7_6);
    ca_.Goto(&block3, phi_bb7_3, phi_bb7_4);
  }

  TNode<Object> phi_bb3_3;
  TNode<Object> phi_bb3_4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
    ca_.Goto(&block11, phi_bb3_4, phi_bb3_4);
  }

  TNode<Object> phi_bb11_3;
  TNode<Object> phi_bb11_4;
  TNode<BoolT> tmp7;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_3, &phi_bb11_4);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp7, &block9, std::vector<Node*>{phi_bb11_3, phi_bb11_4}, &block10, std::vector<Node*>{phi_bb11_3, phi_bb11_4});
  }

  TNode<Object> phi_bb9_3;
  TNode<Object> phi_bb9_4;
  TNode<Smi> tmp8;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_3, &phi_bb9_4);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_Zero_0(state_, TNode<Object>{phi_bb9_3}, &label9);
    ca_.Goto(&block14, phi_bb9_3, phi_bb9_4, phi_bb9_3, phi_bb9_3);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block15, phi_bb9_3, phi_bb9_4, phi_bb9_3, phi_bb9_3);
    }
  }

  TNode<Object> phi_bb15_3;
  TNode<Object> phi_bb15_4;
  TNode<Object> phi_bb15_5;
  TNode<Object> phi_bb15_6;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_4, &phi_bb15_5, &phi_bb15_6);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{ca_.UncheckedCast<PromiseReaction>(phi_bb15_5), tmp10});
    MorphAndEnqueuePromiseReaction_0(state_, TNode<Context>{p_context}, TNode<PromiseReaction>{ca_.UncheckedCast<PromiseReaction>(phi_bb15_5)}, TNode<Object>{p_argument}, p_reactionType);
    ca_.Goto(&block11, tmp11, phi_bb15_4);
  }

  TNode<Object> phi_bb14_3;
  TNode<Object> phi_bb14_4;
  TNode<Object> phi_bb14_5;
  TNode<Object> phi_bb14_6;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_3, &phi_bb14_4, &phi_bb14_5, &phi_bb14_6);
    ca_.Goto(&block10, phi_bb14_3, phi_bb14_4);
  }

  TNode<Object> phi_bb10_3;
  TNode<Object> phi_bb10_4;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_3, &phi_bb10_4);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

TF_BUILTIN(FulfillPromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Oddball> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    RunContextPromiseHookResolve_0(state_, TNode<Context>{parameter0}, TNode<JSPromise>{parameter1});
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp0});
    tmp2 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{parameter1, tmp3}, parameter2);
    Method_JSPromise_SetStatus_0(state_, TNode<JSPromise>{parameter1}, Promise::PromiseState::kFulfilled);
    TriggerPromiseReactions_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{parameter2}, PromiseReaction::kFulfill);
    tmp4 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(RejectPromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Oddball> parameter3 = UncheckedCast<Oddball>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).PromiseHookFlags();
    tmp1 = PromiseBuiltinsAssembler(state_).IsIsolatePromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate(TNode<Uint32T>{tmp0});
    ca_.Branch(tmp1, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp2);
  }

  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise>{parameter1});
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Goto(&block5, tmp4);
  }

  TNode<BoolT> phi_bb5_6;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_6);
    ca_.Branch(phi_bb5_6, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  TNode<Object> tmp5;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp5 = CodeStubAssembler(state_).CallRuntime(Runtime::kRejectPromise, parameter0, parameter1, parameter2, parameter3); 
    CodeStubAssembler(state_).Return(tmp5);
  }

  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Oddball> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    RunContextPromiseHookResolve_1(state_, TNode<Context>{parameter0}, TNode<JSPromise>{parameter1}, TNode<Uint32T>{tmp0});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp6});
    tmp8 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{parameter1, tmp9}, parameter2);
    Method_JSPromise_SetStatus_0(state_, TNode<JSPromise>{parameter1}, Promise::PromiseState::kRejected);
    TriggerPromiseReactions_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp8}, TNode<Object>{parameter2}, PromiseReaction::kReject);
    tmp10 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp10);
  }
}

TNode<Context> CreatePromiseCapabilitiesExecutorContext_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, TNode<PromiseCapability> p_capability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::kCapabilitiesContextLength);
    tmp1 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kCapabilitySlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<Object>{p_capability});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Context>{tmp0};
}

TNode<PromiseCapability> CreatePromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_promise, TNode<HeapObject> p_resolve, TNode<HeapObject> p_reject) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<PromiseCapability> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kPromiseCapabilityMap_0(state_);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp2 = Allocate_0(state_, TNode<IntPtrT>{tmp1}, TNode<Map>{tmp0});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp0);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp2, tmp4}, p_promise);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp2, tmp5}, p_resolve);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp2, tmp6}, p_reject);
    tmp7 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<PromiseCapability>{tmp7};
}

TorqueStructPromiseResolvingFunctions CreatePromiseResolvingFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_debugEvent, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<Map> tmp3;
  TNode<SharedFunctionInfo> tmp4;
  TNode<JSFunction> tmp5;
  TNode<SharedFunctionInfo> tmp6;
  TNode<JSFunction> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CreatePromiseResolvingFunctionsContext_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{p_promise}, TNode<Object>{p_debugEvent}, TNode<NativeContext>{p_nativeContext});
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp2 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp1});
    tmp3 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp2});
    tmp4 = CodeStubAssembler(state_).PromiseCapabilityDefaultResolveSharedFunConstant();
    tmp5 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp3}, TNode<SharedFunctionInfo>{tmp4}, TNode<Context>{tmp0});
    tmp6 = CodeStubAssembler(state_).PromiseCapabilityDefaultRejectSharedFunConstant();
    tmp7 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp3}, TNode<SharedFunctionInfo>{tmp6}, TNode<Context>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructPromiseResolvingFunctions{TNode<JSFunction>{tmp5}, TNode<JSFunction>{tmp7}};
}

TNode<PromiseCapability> InnerNewPromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_constructor, TNode<Object> p_debugEvent) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PromiseCapability> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PromiseCapability> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    tmp2 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp1});
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{p_constructor}, TNode<MaybeObject>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<JSPromise> tmp4;
  TNode<JSFunction> tmp5;
  TNode<JSFunction> tmp6;
  TNode<PromiseCapability> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = NewJSPromise_1(state_, TNode<Context>{p_context});
    std::tie(tmp5, tmp6) = CreatePromiseResolvingFunctions_0(state_, TNode<Context>{p_context}, TNode<JSPromise>{tmp4}, TNode<Object>{p_debugEvent}, TNode<NativeContext>{tmp0}).Flatten();
    tmp7 = CreatePromiseCapability_0(state_, TNode<HeapObject>{tmp4}, TNode<HeapObject>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Goto(&block1, tmp7);
  }

  TNode<Oddball> tmp8;
  TNode<Oddball> tmp9;
  TNode<Oddball> tmp10;
  TNode<PromiseCapability> tmp11;
  TNode<Context> tmp12;
  TNode<SharedFunctionInfo> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Object> tmp15;
  TNode<Map> tmp16;
  TNode<JSFunction> tmp17;
  TNode<JSReceiver> tmp18;
  TNode<JSReceiver> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Object> tmp22;
  TNode<BoolT> tmp23;
  TNode<BoolT> tmp24;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp8 = Undefined_0(state_);
    tmp9 = Undefined_0(state_);
    tmp10 = Undefined_0(state_);
    tmp11 = CreatePromiseCapability_0(state_, TNode<HeapObject>{tmp8}, TNode<HeapObject>{tmp9}, TNode<HeapObject>{tmp10});
    tmp12 = CreatePromiseCapabilitiesExecutorContext_0(state_, TNode<NativeContext>{tmp0}, TNode<PromiseCapability>{tmp11});
    tmp13 = CodeStubAssembler(state_).PromiseGetCapabilitiesExecutorSharedFunConstant();
    tmp14 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp15 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp14});
    tmp16 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp15});
    tmp17 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp16}, TNode<SharedFunctionInfo>{tmp13}, TNode<Context>{tmp12});
    tmp18 = UnsafeCast_Constructor_0(state_, TNode<Context>{p_context}, TNode<Object>{p_constructor});
    tmp19 = CodeStubAssembler(state_).Construct(TNode<Context>{p_context}, TNode<JSReceiver>{tmp18}, TNode<Object>{tmp17});
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp11, tmp20}, tmp19);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp22 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp11, tmp21});
    tmp23 = Is_Callable_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp22});
    tmp24 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp23});
    ca_.Branch(tmp24, &block7, std::vector<Node*>{}, &block8, std::vector<Node*>{});
  }

  TNode<BoolT> tmp25;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp25);
  }

  TNode<IntPtrT> tmp26;
  TNode<Object> tmp27;
  TNode<BoolT> tmp28;
  TNode<BoolT> tmp29;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp27 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp11, tmp26});
    tmp28 = Is_Callable_Object_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp27});
    tmp29 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp28});
    ca_.Goto(&block9, tmp29);
  }

  TNode<BoolT> phi_bb9_12;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_12);
    ca_.Branch(phi_bb9_12, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kPromiseNonCallable);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1, tmp11);
  }

  TNode<PromiseCapability> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block10, phi_bb1_3);
  }

  TNode<PromiseCapability> phi_bb10_3;
    ca_.Bind(&block10, &phi_bb10_3);
  return TNode<PromiseCapability>{phi_bb10_3};
}

TF_BUILTIN(NewPromiseCapability, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = CodeStubAssembler(state_).IsConstructor(TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(parameter1)});
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kNotConstructor, TNode<Object>{parameter1});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kNotConstructor, TNode<Object>{parameter1});
  }

  TNode<PromiseCapability> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp4 = InnerNewPromiseCapability_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(parameter1)}, TNode<Object>{parameter2});
    CodeStubAssembler(state_).Return(tmp4);
  }
}

TF_BUILTIN(PromiseCapabilityDefaultReject, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kReason));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<JSPromise> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<Oddball> tmp5;
  TNode<Oddball> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kPromiseSlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_JSPromise_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp3});
    tmp5 = UnsafeCast_Boolean_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp4});
    tmp6 = True_0(state_);
    tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  TNode<Object> tmp8;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp8 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRejectAfterResolved, parameter0, tmp2, parameter2); 
    CodeStubAssembler(state_).Return(tmp8);
  }

  TNode<Oddball> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Object> tmp12;
  TNode<Oddball> tmp13;
  TNode<Object> tmp14;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp9 = True_0(state_);
    tmp10 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp10}, TNode<Object>{tmp9});
    tmp11 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kDebugEventSlot);
    tmp12 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp11});
    tmp13 = UnsafeCast_Boolean_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp12});
    tmp14 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRejectPromise, parameter0, tmp2, parameter2, tmp13);
    CodeStubAssembler(state_).Return(tmp14);
  }
}

TF_BUILTIN(PromiseCapabilityDefaultResolve, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kResolution));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<JSPromise> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<Oddball> tmp5;
  TNode<Oddball> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kPromiseSlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_JSPromise_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    tmp3 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp3});
    tmp5 = UnsafeCast_Boolean_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp4});
    tmp6 = True_0(state_);
    tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  TNode<Object> tmp8;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp8 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseResolveAfterResolved, parameter0, tmp2, parameter2); 
    CodeStubAssembler(state_).Return(tmp8);
  }

  TNode<Oddball> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp9 = True_0(state_);
    tmp10 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kAlreadyResolvedSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp10}, TNode<Object>{tmp9});
    tmp11 = CodeStubAssembler(state_).CallBuiltin(Builtins::kResolvePromise, parameter0, tmp2, parameter2);
    CodeStubAssembler(state_).Return(tmp11);
  }
}

void PerformPromiseThenImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<HeapObject> p_onFulfilled, TNode<HeapObject> p_onRejected, TNode<HeapObject> p_resultPromiseOrCapability) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<PromiseReactionJobTask, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Method_JSPromise_Status_0(state_, TNode<JSPromise>{p_promise});
    tmp1 = FromConstexpr_PromiseState_constexpr_kPending_0(state_, Promise::PromiseState::kPending);
    tmp2 = PromiseStateEquals_0(state_, TNode<Int32T>{tmp0}, TNode<Int32T>{tmp1});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Context> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<Object> tmp6;
  TNode<PromiseReaction> tmp7;
  TNode<IntPtrT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = ExtractHandlerContext_1(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_onFulfilled}, TNode<HeapObject>{p_onRejected});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_promise, tmp4});
    tmp6 = UnsafeCast_Zero_OR_PromiseReaction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp5});
    tmp7 = NewPromiseReaction_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp3}, TNode<Object>{tmp6}, TNode<HeapObject>{p_resultPromiseOrCapability}, TNode<HeapObject>{p_onFulfilled}, TNode<HeapObject>{p_onRejected});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_promise, tmp8}, tmp7);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<Int32T> tmp11;
  TNode<Int32T> tmp12;
  TNode<BoolT> tmp13;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_promise, tmp9});
    tmp11 = Method_JSPromise_Status_0(state_, TNode<JSPromise>{p_promise});
    tmp12 = FromConstexpr_PromiseState_constexpr_kFulfilled_0(state_, Promise::PromiseState::kFulfilled);
    tmp13 = PromiseStateEquals_0(state_, TNode<Int32T>{tmp11}, TNode<Int32T>{tmp12});
    ca_.Branch(tmp13, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  TNode<Context> tmp14;
  TNode<PromiseFulfillReactionJobTask> tmp15;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp14 = ExtractHandlerContext_1(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_onFulfilled}, TNode<HeapObject>{p_onRejected});
    tmp15 = NewPromiseFulfillReactionJobTask_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp14}, TNode<Object>{tmp10}, TNode<HeapObject>{p_onFulfilled}, TNode<HeapObject>{p_resultPromiseOrCapability});
    ca_.Goto(&block7, tmp15, tmp14);
  }

  TNode<Context> tmp16;
  TNode<PromiseRejectReactionJobTask> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp16 = ExtractHandlerContext_1(state_, TNode<Context>{p_context}, TNode<HeapObject>{p_onRejected}, TNode<HeapObject>{p_onFulfilled});
    tmp17 = NewPromiseRejectReactionJobTask_0(state_, TNode<Context>{p_context}, TNode<Context>{tmp16}, TNode<Object>{tmp10}, TNode<HeapObject>{p_onRejected}, TNode<HeapObject>{p_resultPromiseOrCapability});
    tmp18 = Method_JSPromise_HasHandler_0(state_, TNode<JSPromise>{p_promise});
    tmp19 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp18});
    ca_.Branch(tmp19, &block12, std::vector<Node*>{}, &block13, std::vector<Node*>{});
  }

  TNode<Object> tmp20;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp20 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRevokeReject, p_context, p_promise); 
    ca_.Goto(&block13);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block7, tmp17, tmp16);
  }

  TNode<PromiseReactionJobTask> phi_bb7_6;
  TNode<Context> phi_bb7_7;
  TNode<Oddball> tmp21;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_6, &phi_bb7_7);
    tmp21 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, phi_bb7_7, phi_bb7_6));
    ca_.Goto(&block4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    Method_JSPromise_SetHasHandler_0(state_, TNode<JSPromise>{p_promise});
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

TF_BUILTIN(PerformPromiseThen, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<HeapObject> parameter2 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<HeapObject> parameter3 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<HeapObject> parameter4 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    PerformPromiseThenImpl_0(state_, TNode<Context>{parameter0}, TNode<JSPromise>{parameter1}, TNode<HeapObject>{parameter2}, TNode<HeapObject>{parameter3}, TNode<HeapObject>{parameter4});
    CodeStubAssembler(state_).Return(parameter4);
  }
}

TF_BUILTIN(PromiseReject, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kReason));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "PromiseReject");
  }

  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp2});
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp3}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp4, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  TNode<JSPromise> tmp5;
  TNode<Object> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = NewJSPromise_2(state_, TNode<Context>{parameter0}, Promise::PromiseState::kRejected, TNode<Object>{parameter2});
    tmp6 = CodeStubAssembler(state_).CallRuntime(Runtime::kPromiseRejectEventFromStack, parameter0, tmp5, parameter2); 
    CodeStubAssembler(state_).Return(tmp5);
  }

  TNode<Oddball> tmp7;
  TNode<PromiseCapability> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<JSReceiver> tmp11;
  TNode<Oddball> tmp12;
  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<HeapObject> tmp15;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = True_0(state_);
    tmp8 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, parameter0, tmp0, tmp7));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9});
    tmp11 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp10});
    tmp12 = Undefined_0(state_);
    tmp13 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp11}, TNode<Object>{tmp12}, TNode<Object>{parameter2});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp15 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp8, tmp14});
    CodeStubAssembler(state_).Return(tmp15);
  }
}

TF_BUILTIN(PromiseGetCapabilitiesExecutor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kResolve));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kReject));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<PromiseCapability> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<Oddball> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kCapabilitySlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp3});
    tmp5 = Undefined_0(state_);
    tmp6 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp4}, TNode<HeapObject>{tmp5});
    ca_.Branch(tmp6, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  TNode<BoolT> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp7);
  }

  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<Oddball> tmp10;
  TNode<BoolT> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp2, tmp8});
    tmp10 = Undefined_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp9}, TNode<HeapObject>{tmp10});
    ca_.Goto(&block5, tmp11);
  }

  TNode<BoolT> phi_bb5_6;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_6);
    ca_.Branch(phi_bb5_6, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kPromiseExecutorAlreadyInvoked);
  }

  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Oddball> tmp14;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp2, tmp12}, parameter2);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp2, tmp13}, parameter3);
    tmp14 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp14);
  }
}

TNode<Object> CallResolve_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Object> p_resolve, TNode<Object> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_resolve}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Object> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, p_context, p_constructor, p_value);
    ca_.Goto(&block1, tmp2);
  }

  TNode<JSReceiver> tmp3;
  TNode<Object> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = UnsafeCast_Callable_0(state_, TNode<Context>{p_context}, TNode<Object>{p_resolve});
    tmp4 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp3}, TNode<Object>{p_constructor}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp4);
  }

  TNode<Object> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<Object>{phi_bb1_4};
}

TF_BUILTIN(PromiseConstructorLazyDeoptContinuation, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kPromise));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kReject));
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedCast<Object>(Parameter(Descriptor::kException));
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedCast<Object>(Parameter(Descriptor::kResult));
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_TheHole_0(state_, TNode<Object>{parameter4}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<Oddball> tmp2;
  TNode<Object> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = Undefined_0(state_);
    tmp3 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<Object>{tmp2}, TNode<Object>{ca_.UncheckedCast<Object>(parameter4)});
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    CodeStubAssembler(state_).Return(parameter2);
  }
}

TNode<JSBoundFunction> Cast_JSBoundFunction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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

  TNode<JSBoundFunction> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSBoundFunction_0(state_, TNode<HeapObject>{tmp0}, &label3);
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
  return TNode<JSBoundFunction>{tmp2};
}

TorqueStructReference_Map_0 UnsafeConstCast_Map_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Map_0 p_r) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_Map_0{TNode<HeapObject>{p_r.object}, TNode<IntPtrT>{p_r.offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Map_0{TNode<HeapObject>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

TNode<PromiseFulfillReactionJobTask> UnsafeCast_PromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<PromiseFulfillReactionJobTask> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<PromiseFulfillReactionJobTask>{tmp0};
}

TNode<PromiseRejectReactionJobTask> UnsafeCast_PromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<PromiseRejectReactionJobTask> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<PromiseRejectReactionJobTask>{tmp0};
}

TNode<Object> UnsafeCast_Zero_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = (TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Object>{tmp0};
}

TNode<BoolT> Is_Callable_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
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
    tmp0 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
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

TNode<JSPromise> UnsafeCast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSPromise> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<JSPromise>{tmp0};
}

TNode<PromiseCapability> UnsafeCast_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<PromiseCapability> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<PromiseCapability>{tmp0};
}

}  // namespace internal
}  // namespace v8

