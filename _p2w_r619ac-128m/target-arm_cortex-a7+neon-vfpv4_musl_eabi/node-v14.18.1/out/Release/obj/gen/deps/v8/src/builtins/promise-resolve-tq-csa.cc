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

TNode<String> kConstructorString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<String> tmp0;
    tmp0 = CodeStubAssembler(state_).ConstructorStringConstant();
  return TNode<String>{tmp0};
}

TF_BUILTIN(PromiseResolveTrampoline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "PromiseResolve");
  }

  TNode<Object> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, parameter0, tmp0, parameter2);
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(PromiseResolve, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSReceiver> parameter1 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<JSPromise> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp1 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    tmp2 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp1});
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = Cast_JSPromise_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label4);
    ca_.Goto(&block5);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Map> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<BoolT> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp8 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp3, tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp10 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp8, tmp9});
    tmp11 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp10}, TNode<Object>{tmp6});
    ca_.Branch(tmp11, &block7, std::vector<Node*>{}, &block8, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp12 = CodeStubAssembler(state_).IsPromiseSpeciesProtectorCellInvalid();
    ca_.Branch(tmp12, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp13;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp13 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp2}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp13, &block11, std::vector<Node*>{}, &block12, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block4);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<String> tmp14;
  TNode<Object> tmp15;
  TNode<BoolT> tmp16;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp14 = kConstructorString_0(state_);
    tmp15 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{parameter2}, TNode<Object>{tmp14});
    tmp16 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp15}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp16, &block13, std::vector<Node*>{}, &block14, std::vector<Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block2);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    CodeStubAssembler(state_).Return(parameter2);
  }

  TNode<BoolT> tmp17;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp17 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{parameter1});
    ca_.Branch(tmp17, &block15, std::vector<Node*>{}, &block16, std::vector<Node*>{});
  }

  TNode<JSPromise> tmp18;
  TNode<Object> tmp19;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp18 = NewJSPromise_1(state_, TNode<Context>{parameter0});
    tmp19 = CodeStubAssembler(state_).CallBuiltin(Builtins::kResolvePromise, parameter0, tmp18, parameter2);
    CodeStubAssembler(state_).Return(tmp18);
  }

  TNode<Oddball> tmp20;
  TNode<PromiseCapability> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<Object> tmp23;
  TNode<JSReceiver> tmp24;
  TNode<Oddball> tmp25;
  TNode<Object> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp20 = True_0(state_);
    tmp21 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, parameter0, parameter1, tmp20));
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp23 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp21, tmp22});
    tmp24 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp23});
    tmp25 = Undefined_0(state_);
    tmp26 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp24}, TNode<Object>{tmp25}, TNode<Object>{parameter2});
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp28 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp21, tmp27});
    CodeStubAssembler(state_).Return(tmp28);
  }
}

TNode<String> kThenString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<String> tmp0;
    tmp0 = CodeStubAssembler(state_).ThenStringConstant();
  return TNode<String>{tmp0};
}

TF_BUILTIN(ResolvePromise, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSPromise> parameter1 = UncheckedCast<JSPromise>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseBuiltinsAssembler(state_).IsIsolatePromiseHookEnabledOrDebugIsActiveOrHasAsyncEventDelegate();
    ca_.Branch(tmp0, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block5, tmp1);
  }

  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{parameter1}, TNode<Object>{parameter2});
    ca_.Goto(&block5, tmp2);
  }

  TNode<BoolT> phi_bb5_4;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_4);
    ca_.Branch(phi_bb5_4, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  TNode<Object> tmp3;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp3 = CodeStubAssembler(state_).CallRuntime(Runtime::kResolvePromise, parameter0, parameter1, parameter2); 
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<Oddball> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = Undefined_0(state_);
    tmp5 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{parameter2});
    ca_.Branch(tmp5, &block10, std::vector<Node*>{}, &block11, std::vector<Node*>{});
  }

  TNode<Oddball> tmp6;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp6 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, parameter0, parameter1, parameter2));
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<HeapObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Map> tmp9;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp7 = UnsafeCast_HeapObject_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8});
    tmp10 = CodeStubAssembler(state_).IsJSReceiverMap(TNode<Map>{tmp9});
    tmp11 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block12, std::vector<Node*>{}, &block13, std::vector<Node*>{});
  }

  TNode<Oddball> tmp12;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp12 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, parameter0, parameter1, parameter2));
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<BoolT> tmp13;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp13 = IsForceSlowPath_0(state_);
    ca_.Branch(tmp13, &block14, std::vector<Node*>{}, &block15, std::vector<Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block9);
  }

  TNode<BoolT> tmp14;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp14 = CodeStubAssembler(state_).IsPromiseThenProtectorCellInvalid();
    ca_.Branch(tmp14, &block16, std::vector<Node*>{}, &block17, std::vector<Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block9);
  }

  TNode<NativeContext> tmp15;
  TNode<BoolT> tmp16;
  TNode<BoolT> tmp17;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp15 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp16 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp9});
    tmp17 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp16});
    ca_.Branch(tmp17, &block18, std::vector<Node*>{}, &block19, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<Object> tmp19;
  TNode<BoolT> tmp20;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp18 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    tmp19 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp18});
    tmp20 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp9}, TNode<Object>{tmp19});
    ca_.Branch(tmp20, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  TNode<Oddball> tmp21;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp21 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, parameter0, parameter1, parameter2));
    CodeStubAssembler(state_).Return(tmp21);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.Goto(&block9);
  }

  TNode<IntPtrT> tmp22;
  TNode<Object> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<HeapObject> tmp25;
  TNode<BoolT> tmp26;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp22 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
    tmp23 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp22});
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp25 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp9, tmp24});
    tmp26 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp25}, TNode<Object>{tmp23});
    ca_.Branch(tmp26, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp27;
  TNode<Object> tmp28;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp27 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
    tmp28 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp15}, TNode<IntPtrT>{tmp27});
    ca_.Goto(&block7, tmp28);
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.Goto(&block9);
  }

  TNode<String> tmp29;
  TNode<Object> tmp30;
      TNode<Object> tmp32;
  TNode<BoolT> tmp33;
  TNode<BoolT> tmp34;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp29 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch31__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch31__label);
    tmp30 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{parameter2}, TNode<Object>{tmp29});
    }
    if (catch31__label.is_used()) {
      compiler::CodeAssemblerLabel catch31_skip(&ca_);
      ca_.Goto(&catch31_skip);
      ca_.Bind(&catch31__label, &tmp32);
      ca_.Goto(&block35);
      ca_.Bind(&catch31_skip);
    }
    tmp33 = Is_Callable_Object_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp30});
    tmp34 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp33});
    ca_.Branch(tmp34, &block36, std::vector<Node*>{}, &block37, std::vector<Node*>{});
  }

  TNode<Oddball> tmp35;
  TNode<Object> tmp36;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    tmp35 = False_0(state_);
    tmp36 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRejectPromise, parameter0, parameter1, tmp32, tmp35);
    CodeStubAssembler(state_).Return(tmp36);
  }

  TNode<Oddball> tmp37;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    tmp37 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kFulfillPromise, parameter0, parameter1, parameter2));
    CodeStubAssembler(state_).Return(tmp37);
  }

  if (block37.is_used()) {
    ca_.Bind(&block37);
    ca_.Goto(&block7, tmp30);
  }

  TNode<Object> phi_bb7_3;
  TNode<JSReceiver> tmp38;
  TNode<JSReceiver> tmp39;
  TNode<PromiseResolveThenableJobTask> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<Context> tmp42;
  TNode<Oddball> tmp43;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_3);
    tmp38 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp39 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{phi_bb7_3});
    tmp40 = NewPromiseResolveThenableJobTask_0(state_, TNode<Context>{parameter0}, TNode<JSPromise>{parameter1}, TNode<JSReceiver>{tmp38}, TNode<JSReceiver>{tmp39});
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp42 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp40, tmp41});
    tmp43 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kEnqueueMicrotask, tmp42, tmp40));
    CodeStubAssembler(state_).Return(tmp43);
  }
}

}  // namespace internal
}  // namespace v8

