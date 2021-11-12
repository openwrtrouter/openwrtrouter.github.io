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

TF_BUILTIN(PromiseValueThunkFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Object> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(PromiseThrowerFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Object> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrow, parameter0, tmp2);
    CodeStubAssembler(state_).Unreachable();
  }
}

TNode<JSFunction> CreateThrowerFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_reason) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<Map> tmp4;
  TNode<SharedFunctionInfo> tmp5;
  TNode<JSFunction> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::kPromiseValueThunkOrReasonContextLength);
    tmp1 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<Object>{p_reason});
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp2});
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    tmp5 = CodeStubAssembler(state_).PromiseThrowerFinallySharedFunConstant();
    tmp6 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp4}, TNode<SharedFunctionInfo>{tmp5}, TNode<Context>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSFunction>{tmp6};
}

TF_BUILTIN(PromiseCatchFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kReason));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<Oddball> tmp3;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<JSFunction> tmp7;
  TNode<Object> tmp8;
  TNode<NativeContext> tmp9;
  TNode<JSFunction> tmp10;
  TNode<Object> tmp11;
  TNode<Object> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kOnFinallySlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    tmp3 = Undefined_0(state_);
    tmp4 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{tmp3});
    tmp5 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kConstructorSlot);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp5});
    tmp7 = UnsafeCast_JSFunction_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp6});
    tmp8 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, parameter0, tmp7, tmp4);
    tmp9 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp10 = CreateThrowerFunction_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp9}, TNode<Object>{parameter2});
    tmp11 = InvokeThen_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp9}, TNode<Object>{tmp8}, TNode<Object>{tmp10});
    tmp12 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp11});
    CodeStubAssembler(state_).Return(tmp12);
  }
}

TNode<JSFunction> CreateValueThunkFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<Map> tmp4;
  TNode<SharedFunctionInfo> tmp5;
  TNode<JSFunction> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::kPromiseValueThunkOrReasonContextLength);
    tmp1 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kValueSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<Object>{p_value});
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp2});
    tmp4 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    tmp5 = CodeStubAssembler(state_).PromiseValueThunkFinallySharedFunConstant();
    tmp6 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp4}, TNode<SharedFunctionInfo>{tmp5}, TNode<Context>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSFunction>{tmp6};
}

TF_BUILTIN(PromiseThenFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<Oddball> tmp3;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<JSFunction> tmp7;
  TNode<Object> tmp8;
  TNode<NativeContext> tmp9;
  TNode<JSFunction> tmp10;
  TNode<Object> tmp11;
  TNode<Object> tmp12;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kOnFinallySlot);
    tmp1 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp0});
    tmp2 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp1});
    tmp3 = Undefined_0(state_);
    tmp4 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp2}, TNode<Object>{tmp3});
    tmp5 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kConstructorSlot);
    tmp6 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{parameter0}, TNode<IntPtrT>{tmp5});
    tmp7 = UnsafeCast_JSFunction_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp6});
    tmp8 = CodeStubAssembler(state_).CallBuiltin(Builtins::kPromiseResolve, parameter0, tmp7, tmp4);
    tmp9 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp10 = CreateValueThunkFunction_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp9}, TNode<Object>{parameter2});
    tmp11 = InvokeThen_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp9}, TNode<Object>{tmp8}, TNode<Object>{tmp10});
    tmp12 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp11});
    CodeStubAssembler(state_).Return(tmp12);
  }
}

TorqueStructPromiseFinallyFunctions_0 CreatePromiseFinallyFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<JSReceiver> p_onFinally, TNode<JSReceiver> p_constructor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<Map> tmp5;
  TNode<SharedFunctionInfo> tmp6;
  TNode<JSFunction> tmp7;
  TNode<SharedFunctionInfo> tmp8;
  TNode<JSFunction> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).AllocateSyntheticFunctionContext(TNode<NativeContext>{p_nativeContext}, PromiseBuiltins::kPromiseFinallyContextLength);
    tmp1 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kOnFinallySlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<Object>{p_onFinally});
    tmp2 = FromConstexpr_ContextSlot_constexpr_ContextSlot_0(state_, PromiseBuiltins::kConstructorSlot);
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{tmp0}, TNode<IntPtrT>{tmp2}, TNode<Object>{p_constructor});
    tmp3 = FromConstexpr_NativeContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp3});
    tmp5 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    tmp6 = CodeStubAssembler(state_).PromiseThenFinallySharedFunConstant();
    tmp7 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp5}, TNode<SharedFunctionInfo>{tmp6}, TNode<Context>{tmp0});
    tmp8 = CodeStubAssembler(state_).PromiseCatchFinallySharedFunConstant();
    tmp9 = CodeStubAssembler(state_).AllocateFunctionWithMapAndContext(TNode<Map>{tmp5}, TNode<SharedFunctionInfo>{tmp8}, TNode<Context>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructPromiseFinallyFunctions_0{TNode<JSFunction>{tmp7}, TNode<JSFunction>{tmp9}};
}

TF_BUILTIN(PromisePrototypeFinally, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kOnFinally));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Promise.prototype.finally");
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Object> tmp4;
  TNode<JSReceiver> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Map> tmp7;
  TNode<BoolT> tmp8;
  TNode<BoolT> tmp9;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{parameter0});
    tmp3 = FromConstexpr_NativeContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
    tmp4 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp3});
    tmp5 = UnsafeCast_Callable_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp7 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp6});
    tmp8 = CodeStubAssembler(state_).IsJSPromiseMap(TNode<Map>{tmp7});
    tmp9 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp8});
    ca_.Branch(tmp9, &block7, std::vector<Node*>{}, &block8, std::vector<Node*>{});
  }

  TNode<BoolT> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp10);
  }

  TNode<BoolT> tmp11;
  TNode<BoolT> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp11 = IsPromiseSpeciesLookupChainIntact_0(state_, TNode<NativeContext>{tmp2}, TNode<Map>{tmp7});
    tmp12 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp11});
    ca_.Goto(&block9, tmp12);
  }

  TNode<BoolT> phi_bb9_9;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_9);
    ca_.Branch(phi_bb9_9, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{tmp5});
  }

  TNode<JSReceiver> tmp13;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp13 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{parameter0}, TNode<Object>{tmp0}, TNode<JSReceiver>{tmp5});
    ca_.Goto(&block6, tmp13);
  }

  TNode<JSReceiver> phi_bb6_6;
  TNode<JSReceiver> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6);
    compiler::CodeAssemblerLabel label15(&ca_);
    tmp14 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label15);
    ca_.Goto(&block16);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block17);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block14, parameter2, parameter2);
  }

  TNode<JSFunction> tmp16;
  TNode<JSFunction> tmp17;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    std::tie(tmp16, tmp17) = CreatePromiseFinallyFunctions_0(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp2}, TNode<JSReceiver>{tmp14}, TNode<JSReceiver>{phi_bb6_6}).Flatten();
    ca_.Goto(&block14, tmp16, tmp17);
  }

  TNode<Object> phi_bb14_8;
  TNode<Object> phi_bb14_9;
  TNode<Object> tmp18;
  TNode<Object> tmp19;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_8, &phi_bb14_9);
    tmp18 = InvokeThen_1(state_, TNode<Context>{parameter0}, TNode<NativeContext>{tmp2}, TNode<Object>{parameter1}, TNode<Object>{phi_bb14_8}, TNode<Object>{phi_bb14_9});
    tmp19 = UnsafeCast_JSAny_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp18});
    CodeStubAssembler(state_).Return(tmp19);
  }
}

}  // namespace internal
}  // namespace v8

