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

TNode<Symbol> kPromiseForwardingHandlerSymbol_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Symbol> tmp0;
    tmp0 = CodeStubAssembler(state_).PromiseForwardingHandlerSymbolConstant();
  return TNode<Symbol>{tmp0};
}

TNode<Symbol> kPromiseHandledBySymbol_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Symbol> tmp0;
    tmp0 = CodeStubAssembler(state_).PromiseHandledBySymbolConstant();
  return TNode<Symbol>{tmp0};
}

TNode<String> kResolveString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<String> tmp0;
    tmp0 = CodeStubAssembler(state_).ResolveStringConstant();
  return TNode<String>{tmp0};
}

TNode<BoolT> IsPromiseResolveLookupChainIntact_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_constructor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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

  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<JSFunction> tmp4;
  TNode<BoolT> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp2});
    tmp4 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp4}, TNode<HeapObject>{p_constructor});
    ca_.Branch(tmp5, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = CodeStubAssembler(state_).IsPromiseResolveProtectorCellInvalid();
    tmp7 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp6});
    ca_.Goto(&block6, tmp7);
  }

  TNode<BoolT> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp8);
  }

  TNode<BoolT> phi_bb6_5;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    ca_.Goto(&block1, phi_bb6_5);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block7, phi_bb1_3);
  }

  TNode<BoolT> phi_bb7_3;
    ca_.Bind(&block7, &phi_bb7_3);
  return TNode<BoolT>{phi_bb7_3};
}

TF_BUILTIN(PromiseRace, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block39(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block43(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block44(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block53(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block54(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block55(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, BoolT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Promise.race");
  }

  TNode<Oddball> tmp2;
  TNode<PromiseCapability> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<BoolT> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = False_0(state_);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewPromiseCapability, parameter0, tmp0, tmp2));
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp3, tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp3, tmp6});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp9 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp8});
    tmp10 = CodeStubAssembler(state_).IsDebugActive();
    ca_.Branch(tmp10, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  TNode<Symbol> tmp11;
  TNode<Oddball> tmp12;
  TNode<Object> tmp13;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp11 = kPromiseForwardingHandlerSymbol_0(state_);
    tmp12 = True_0(state_);
    tmp13 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{parameter0}, TNode<Object>{tmp7}, TNode<Object>{tmp11}, TNode<Object>{tmp12});
    ca_.Goto(&block6);
  }

  TNode<JSReceiver> tmp14;
  TNode<Object> tmp15;
      TNode<Object> tmp17;
  TNode<NativeContext> tmp18;
      TNode<Object> tmp20;
  TNode<Oddball> tmp21;
  TNode<BoolT> tmp22;
      TNode<Object> tmp24;
  TNode<BoolT> tmp25;
      TNode<Object> tmp27;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    std::tie(tmp14, tmp15) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{parameter0}, TNode<Object>{parameter2}).Flatten();
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block11);
      ca_.Bind(&catch16_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch19__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch19__label);
    tmp18 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    }
    if (catch19__label.is_used()) {
      compiler::CodeAssemblerLabel catch19_skip(&ca_);
      ca_.Goto(&catch19_skip);
      ca_.Bind(&catch19__label, &tmp20);
      ca_.Goto(&block14);
      ca_.Bind(&catch19_skip);
    }
    tmp21 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch23__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch23__label);
    tmp22 = IsPromiseResolveLookupChainIntact_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp18}, TNode<JSReceiver>{tmp0});
    }
    if (catch23__label.is_used()) {
      compiler::CodeAssemblerLabel catch23_skip(&ca_);
      ca_.Goto(&catch23_skip);
      ca_.Bind(&catch23__label, &tmp24);
      ca_.Goto(&block17);
      ca_.Bind(&catch23_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp25 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp22});
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block18);
      ca_.Bind(&catch26_skip);
    }
    ca_.Branch(tmp25, &block15, std::vector<Node*>{}, &block16, std::vector<Node*>{tmp21});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block8, tmp17);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block13, tmp20);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block13, tmp24);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block13, tmp27);
  }

  TNode<String> tmp28;
  TNode<Object> tmp29;
      TNode<Object> tmp31;
  TNode<JSReceiver> tmp32;
      TNode<Object> tmp35;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp28 = kResolveString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch30__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch30__label);
    tmp29 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{tmp0}, TNode<Object>{tmp28});
    }
    if (catch30__label.is_used()) {
      compiler::CodeAssemblerLabel catch30_skip(&ca_);
      ca_.Goto(&catch30_skip);
      ca_.Bind(&catch30__label, &tmp31);
      ca_.Goto(&block19);
      ca_.Bind(&catch30_skip);
    }
    compiler::CodeAssemblerLabel label33(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch34__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch34__label);
    tmp32 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{tmp29}, &label33);
    }
    if (catch34__label.is_used()) {
      compiler::CodeAssemblerLabel catch34_skip(&ca_);
      ca_.Goto(&catch34_skip);
      ca_.Bind(&catch34__label, &tmp35);
      ca_.Goto(&block24);
      ca_.Bind(&catch34_skip);
    }
    ca_.Goto(&block22);
    if (label33.is_used()) {
      ca_.Bind(&label33);
      ca_.Goto(&block23);
    }
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block13, tmp31);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block13, tmp35);
  }

      TNode<Object> tmp37;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    compiler::CodeAssemblerExceptionHandlerLabel catch36__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch36__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledNonCallable, "resolve");
    }
    if (catch36__label.is_used()) {
      compiler::CodeAssemblerLabel catch36_skip(&ca_);
      ca_.Bind(&catch36__label, &tmp37);
      ca_.Goto(&block25);
    }
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block16, tmp32);
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.Goto(&block13, tmp37);
  }

  TNode<Object> phi_bb16_11;
  TNode<IntPtrT> tmp38;
      TNode<Object> tmp40;
  TNode<Object> tmp41;
      TNode<Object> tmp43;
  TNode<Map> tmp44;
      TNode<Object> tmp46;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch39__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch39__label);
    tmp38 = FromConstexpr_NativeContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
    }
    if (catch39__label.is_used()) {
      compiler::CodeAssemblerLabel catch39_skip(&ca_);
      ca_.Goto(&catch39_skip);
      ca_.Bind(&catch39__label, &tmp40);
      ca_.Goto(&block26, phi_bb16_11);
      ca_.Bind(&catch39_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch42__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch42__label);
    tmp41 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp18}, TNode<IntPtrT>{tmp38});
    }
    if (catch42__label.is_used()) {
      compiler::CodeAssemblerLabel catch42_skip(&ca_);
      ca_.Goto(&catch42_skip);
      ca_.Bind(&catch42__label, &tmp43);
      ca_.Goto(&block27, phi_bb16_11);
      ca_.Bind(&catch42_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch45__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch45__label);
    tmp44 = UnsafeCast_Map_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp41});
    }
    if (catch45__label.is_used()) {
      compiler::CodeAssemblerLabel catch45_skip(&ca_);
      ca_.Goto(&catch45_skip);
      ca_.Bind(&catch45__label, &tmp46);
      ca_.Goto(&block28, phi_bb16_11);
      ca_.Bind(&catch45_skip);
    }
    ca_.Goto(&block31, phi_bb16_11);
  }

  TNode<Object> phi_bb26_11;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_11);
    ca_.Goto(&block13, tmp40);
  }

  TNode<Object> phi_bb27_11;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_11);
    ca_.Goto(&block13, tmp43);
  }

  TNode<Object> phi_bb28_11;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_11);
    ca_.Goto(&block13, tmp46);
  }

  TNode<Object> phi_bb31_11;
  TNode<BoolT> tmp47;
      TNode<Object> tmp49;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch48__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch48__label);
    tmp47 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch48__label.is_used()) {
      compiler::CodeAssemblerLabel catch48_skip(&ca_);
      ca_.Goto(&catch48_skip);
      ca_.Bind(&catch48__label, &tmp49);
      ca_.Goto(&block32, phi_bb31_11);
      ca_.Bind(&catch48_skip);
    }
    ca_.Branch(tmp47, &block29, std::vector<Node*>{phi_bb31_11}, &block30, std::vector<Node*>{phi_bb31_11});
  }

  TNode<Object> phi_bb32_11;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_11);
    ca_.Goto(&block13, tmp49);
  }

  TNode<Object> phi_bb29_11;
  TNode<JSReceiver> tmp50;
      TNode<Object> tmp53;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_11);
    compiler::CodeAssemblerLabel label51(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch52__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch52__label);
    tmp50 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp14}, TNode<Object>{tmp15}}, TNode<Map>{tmp44}, &label51);
    }
    if (catch52__label.is_used()) {
      compiler::CodeAssemblerLabel catch52_skip(&ca_);
      ca_.Goto(&catch52_skip);
      ca_.Bind(&catch52__label, &tmp53);
      ca_.Goto(&block39, phi_bb29_11);
      ca_.Bind(&catch52_skip);
    }
    ca_.Goto(&block37, phi_bb29_11);
    if (label51.is_used()) {
      ca_.Bind(&label51);
      ca_.Goto(&block38, phi_bb29_11);
    }
  }

  TNode<Object> phi_bb39_11;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_11);
    ca_.Goto(&block34, phi_bb39_11, tmp53);
  }

  TNode<Object> phi_bb38_11;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_11);
    CodeStubAssembler(state_).Return(tmp9);
  }

  TNode<Object> phi_bb37_11;
  TNode<Object> tmp54;
      TNode<Object> tmp56;
  TNode<JSReceiver> tmp57;
      TNode<Object> tmp59;
  TNode<Object> tmp60;
      TNode<Object> tmp62;
  TNode<String> tmp63;
  TNode<Object> tmp64;
      TNode<Object> tmp66;
  TNode<Object> tmp67;
      TNode<Object> tmp69;
  TNode<Object> tmp70;
      TNode<Object> tmp72;
  TNode<Object> tmp73;
      TNode<Object> tmp75;
  TNode<BoolT> tmp76;
      TNode<Object> tmp78;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch55__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch55__label);
    tmp54 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp50}, TNode<Map>{tmp44});
    }
    if (catch55__label.is_used()) {
      compiler::CodeAssemblerLabel catch55_skip(&ca_);
      ca_.Goto(&catch55_skip);
      ca_.Bind(&catch55__label, &tmp56);
      ca_.Goto(&block40, phi_bb37_11);
      ca_.Bind(&catch55_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch58__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch58__label);
    tmp57 = UnsafeCast_Constructor_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp0});
    }
    if (catch58__label.is_used()) {
      compiler::CodeAssemblerLabel catch58_skip(&ca_);
      ca_.Goto(&catch58_skip);
      ca_.Bind(&catch58__label, &tmp59);
      ca_.Goto(&block41, phi_bb37_11);
      ca_.Bind(&catch58_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch61__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch61__label);
    tmp60 = CallResolve_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp57}, TNode<Object>{phi_bb37_11}, TNode<Object>{tmp54});
    }
    if (catch61__label.is_used()) {
      compiler::CodeAssemblerLabel catch61_skip(&ca_);
      ca_.Goto(&catch61_skip);
      ca_.Bind(&catch61__label, &tmp62);
      ca_.Goto(&block42, phi_bb37_11, phi_bb37_11);
      ca_.Bind(&catch61_skip);
    }
    tmp63 = kThenString_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch65__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch65__label);
    tmp64 = CodeStubAssembler(state_).GetProperty(TNode<Context>{parameter0}, TNode<Object>{tmp60}, TNode<Object>{tmp63});
    }
    if (catch65__label.is_used()) {
      compiler::CodeAssemblerLabel catch65_skip(&ca_);
      ca_.Goto(&catch65_skip);
      ca_.Bind(&catch65__label, &tmp66);
      ca_.Goto(&block43, phi_bb37_11);
      ca_.Bind(&catch65_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch68__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch68__label);
    tmp67 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp5});
    }
    if (catch68__label.is_used()) {
      compiler::CodeAssemblerLabel catch68_skip(&ca_);
      ca_.Goto(&catch68_skip);
      ca_.Bind(&catch68__label, &tmp69);
      ca_.Goto(&block44, phi_bb37_11);
      ca_.Bind(&catch68_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch71__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch71__label);
    tmp70 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7});
    }
    if (catch71__label.is_used()) {
      compiler::CodeAssemblerLabel catch71_skip(&ca_);
      ca_.Goto(&catch71_skip);
      ca_.Bind(&catch71__label, &tmp72);
      ca_.Goto(&block45, phi_bb37_11);
      ca_.Bind(&catch71_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch74__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch74__label);
    tmp73 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp64}, TNode<Object>{tmp60}, TNode<Object>{tmp67}, TNode<Object>{tmp70});
    }
    if (catch74__label.is_used()) {
      compiler::CodeAssemblerLabel catch74_skip(&ca_);
      ca_.Goto(&catch74_skip);
      ca_.Bind(&catch74__label, &tmp75);
      ca_.Goto(&block46, phi_bb37_11);
      ca_.Bind(&catch74_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch77__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch77__label);
    tmp76 = CodeStubAssembler(state_).IsDebugActive();
    }
    if (catch77__label.is_used()) {
      compiler::CodeAssemblerLabel catch77_skip(&ca_);
      ca_.Goto(&catch77_skip);
      ca_.Bind(&catch77__label, &tmp78);
      ca_.Goto(&block49, phi_bb37_11);
      ca_.Bind(&catch77_skip);
    }
    ca_.Branch(tmp76, &block50, std::vector<Node*>{phi_bb37_11}, &block51, std::vector<Node*>{phi_bb37_11});
  }

  TNode<Object> phi_bb40_11;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_11);
    ca_.Goto(&block34, phi_bb40_11, tmp56);
  }

  TNode<Object> phi_bb34_11;
  TNode<Object> phi_bb34_14;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_11, &phi_bb34_14);
    ca_.Goto(&block8, phi_bb34_14);
  }

  TNode<Object> phi_bb41_11;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_11);
    ca_.Goto(&block13, tmp59);
  }

  TNode<Object> phi_bb42_11;
  TNode<Object> phi_bb42_15;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_11, &phi_bb42_15);
    ca_.Goto(&block13, tmp62);
  }

  TNode<Object> phi_bb43_11;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_11);
    ca_.Goto(&block13, tmp66);
  }

  TNode<Object> phi_bb44_11;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_11);
    ca_.Goto(&block13, tmp69);
  }

  TNode<Object> phi_bb45_11;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_11);
    ca_.Goto(&block13, tmp72);
  }

  TNode<Object> phi_bb46_11;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_11);
    ca_.Goto(&block13, tmp75);
  }

  TNode<Object> phi_bb49_11;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_11);
    ca_.Goto(&block13, tmp78);
  }

  TNode<Object> phi_bb50_11;
  TNode<BoolT> tmp79;
      TNode<Object> tmp81;
  TNode<BoolT> tmp82;
      TNode<Object> tmp84;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch80__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch80__label);
    tmp79 = Is_JSPromise_JSReceiver_OR_Undefined_0(state_, TNode<Context>{parameter0}, TNode<HeapObject>{tmp9});
    }
    if (catch80__label.is_used()) {
      compiler::CodeAssemblerLabel catch80_skip(&ca_);
      ca_.Goto(&catch80_skip);
      ca_.Bind(&catch80__label, &tmp81);
      ca_.Goto(&block53, phi_bb50_11);
      ca_.Bind(&catch80_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch83__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch83__label);
    tmp82 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp79});
    }
    if (catch83__label.is_used()) {
      compiler::CodeAssemblerLabel catch83_skip(&ca_);
      ca_.Goto(&catch83_skip);
      ca_.Bind(&catch83__label, &tmp84);
      ca_.Goto(&block54, phi_bb50_11);
      ca_.Bind(&catch83_skip);
    }
    ca_.Goto(&block52, phi_bb50_11, tmp82);
  }

  TNode<Object> phi_bb53_11;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_11);
    ca_.Goto(&block13, tmp81);
  }

  TNode<Object> phi_bb54_11;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_11);
    ca_.Goto(&block13, tmp84);
  }

  TNode<Object> phi_bb51_11;
  TNode<BoolT> tmp85;
      TNode<Object> tmp87;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_11);
    compiler::CodeAssemblerExceptionHandlerLabel catch86__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch86__label);
    tmp85 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    }
    if (catch86__label.is_used()) {
      compiler::CodeAssemblerLabel catch86_skip(&ca_);
      ca_.Goto(&catch86_skip);
      ca_.Bind(&catch86__label, &tmp87);
      ca_.Goto(&block55, phi_bb51_11);
      ca_.Bind(&catch86_skip);
    }
    ca_.Goto(&block52, phi_bb51_11, tmp85);
  }

  TNode<Object> phi_bb55_11;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_11);
    ca_.Goto(&block13, tmp87);
  }

  TNode<Object> phi_bb52_11;
  TNode<BoolT> phi_bb52_18;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_11, &phi_bb52_18);
    ca_.Branch(phi_bb52_18, &block47, std::vector<Node*>{phi_bb52_11}, &block48, std::vector<Node*>{phi_bb52_11});
  }

  TNode<Object> phi_bb47_11;
  TNode<Symbol> tmp88;
  TNode<Object> tmp89;
      TNode<Object> tmp91;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_11);
    tmp88 = kPromiseHandledBySymbol_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch90__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch90__label);
    tmp89 = CodeStubAssembler(state_).SetPropertyStrict(TNode<Context>{parameter0}, TNode<Object>{tmp73}, TNode<Object>{tmp88}, TNode<Object>{tmp9});
    }
    if (catch90__label.is_used()) {
      compiler::CodeAssemblerLabel catch90_skip(&ca_);
      ca_.Goto(&catch90_skip);
      ca_.Bind(&catch90__label, &tmp91);
      ca_.Goto(&block56, phi_bb47_11);
      ca_.Bind(&catch90_skip);
    }
    ca_.Goto(&block48, phi_bb47_11);
  }

  TNode<Object> phi_bb56_11;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_11);
    ca_.Goto(&block13, tmp91);
  }

  TNode<Object> phi_bb48_11;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_11);
    ca_.Goto(&block31, phi_bb48_11);
  }

  TNode<Object> phi_bb30_11;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_11);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb13_10;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_10);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp14}, TNode<Object>{tmp15}});
    ca_.Goto(&block8, phi_bb13_10);
  }

  TNode<Object> phi_bb8_8;
  TNode<Object> tmp92;
  TNode<Oddball> tmp93;
  TNode<Object> tmp94;
  TNode<Object> tmp95;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_8);
    tmp92 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp7});
    tmp93 = Undefined_0(state_);
    tmp94 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{phi_bb8_8});
    tmp95 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp92}, TNode<Object>{tmp93}, TNode<Object>{tmp94});
    CodeStubAssembler(state_).Return(tmp9);
  }
}

TNode<BoolT> Is_JSPromise_JSReceiver_OR_Undefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
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
    tmp0 = Cast_JSPromise_0(state_, TNode<HeapObject>{p_o}, &label1);
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

