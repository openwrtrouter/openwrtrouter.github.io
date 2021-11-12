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

TNode<NativeContext> LoadContextFromFrame_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<NativeContext> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<NativeContext>{tmp1};
}

TF_BUILTIN(WasmInt32ToHeapNumber, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Int32T> parameter0 = UncheckedCast<Int32T>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<HeapNumber> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_float64_int32_0(state_, TNode<Int32T>{parameter0});
    tmp1 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp0});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(WasmTaggedNonSmiToInt32, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<HeapObject> parameter1 = UncheckedCast<HeapObject>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).ChangeTaggedNonSmiToInt32(TNode<Context>{parameter0}, TNode<HeapObject>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(WasmTaggedToFloat64, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).ChangeTaggedToFloat64(TNode<Context>{parameter0}, TNode<Object>{parameter1});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(WasmMemoryGrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Int32T> parameter0 = UncheckedCast<Int32T>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter0});
    tmp1 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    ca_.Branch(tmp2, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  TNode<Int32T> tmp3;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp3 = CodeStubAssembler(state_).Int32Constant(-1);
    CodeStubAssembler(state_).Return(tmp3);
  }

  TNode<WasmInstanceObject> tmp4;
  TNode<NativeContext> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Int32T> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    tmp5 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp4});
    tmp6 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T>{parameter0});
    tmp7 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmMemoryGrow, tmp5, tmp4, tmp6)); 
    tmp8 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp7});
    CodeStubAssembler(state_).Return(tmp8);
  }
}

TF_BUILTIN(WasmTableGet, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedCast<IntPtrT>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedCast<Int32T>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter1});
    tmp2 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp1});
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp4;
  TNode<Object> tmp5;
  TNode<WasmTableObject> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp4 = WasmBuiltinsAssembler(state_).LoadTablesFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp5 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp4}, TNode<IntPtrT>{parameter0});
    tmp6 = TORQUE_CAST(TNode<Object>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp7});
    tmp9 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp9});
    ca_.Branch(tmp10, &block11, std::vector<Node*>{}, &block12, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp11;
  TNode<FixedArray> tmp12;
  TNode<Object> tmp13;
  TNode<HeapObject> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp12 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp6, tmp11});
    tmp13 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp12}, TNode<IntPtrT>{tmp1});
    compiler::CodeAssemblerLabel label15(&ca_);
    tmp14 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp13}, &label15);
    ca_.Goto(&block15);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block14);
  }

  TNode<IntPtrT> tmp16;
  TNode<Map> tmp17;
  TNode<BoolT> tmp18;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp17 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp14, tmp16});
    tmp18 = CodeStubAssembler(state_).IsTuple2Map(TNode<Map>{tmp17});
    ca_.Branch(tmp18, &block17, std::vector<Node*>{}, &block18, std::vector<Node*>{});
  }

  TNode<NativeContext> tmp19;
  TNode<Smi> tmp20;
  TNode<Smi> tmp21;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp19 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp20 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{parameter0});
    tmp21 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{tmp1});
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableGet, tmp19, tmp0, tmp20, tmp21);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block14);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    CodeStubAssembler(state_).Return(tmp13);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmTableSet, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<IntPtrT> parameter0 = UncheckedCast<IntPtrT>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  TNode<Int32T> parameter1 = UncheckedCast<Int32T>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    tmp1 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T>{parameter1});
    tmp2 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT>{tmp1});
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<FixedArray> tmp4;
  TNode<Object> tmp5;
  TNode<WasmTableObject> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp4 = WasmBuiltinsAssembler(state_).LoadTablesFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp5 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp4}, TNode<IntPtrT>{parameter0});
    tmp6 = TORQUE_CAST(TNode<Object>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp7});
    tmp9 = CodeStubAssembler(state_).SmiConstant(wasm::ValueType::Kind::kFuncRef);
    tmp10 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp8}, TNode<Smi>{tmp9});
    ca_.Branch(tmp10, &block11, std::vector<Node*>{}, &block12, std::vector<Node*>{});
  }

  TNode<NativeContext> tmp11;
  TNode<Smi> tmp12;
  TNode<Smi> tmp13;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp11 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp12 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{parameter0});
    tmp13 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT>{tmp1});
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableSet, tmp11, tmp0, tmp12, tmp13, parameter2);
  }

  TNode<IntPtrT> tmp14;
  TNode<Smi> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<BoolT> tmp17;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp15 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp14});
    tmp16 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp16});
    ca_.Branch(tmp17, &block13, std::vector<Node*>{}, &block14, std::vector<Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block2);
  }

  TNode<IntPtrT> tmp18;
  TNode<FixedArray> tmp19;
  TNode<Oddball> tmp20;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp19 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp6, tmp18});
    CodeStubAssembler(state_).StoreFixedArrayElement(TNode<FixedArray>{tmp19}, TNode<IntPtrT>{tmp1}, TNode<Object>{parameter2});
    tmp20 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp20);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
  }
}

TF_BUILTIN(WasmRefFunc, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Uint32T> parameter0 = UncheckedCast<Uint32T>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<WasmInstanceObject> tmp0;
  TNode<FixedArray> tmp1;
  TNode<Oddball> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceFromFrame();
    tmp1 = WasmBuiltinsAssembler(state_).LoadExternalFunctionsFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp2 = Undefined_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block2);
  }

  TNode<UintPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<Oddball> tmp7;
  TNode<BoolT> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = CodeStubAssembler(state_).ChangeUint32ToWord(TNode<Uint32T>{parameter0});
    tmp5 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray>{tmp1}, TNode<IntPtrT>{tmp5});
    tmp7 = Undefined_0(state_);
    tmp8 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp6}, TNode<HeapObject>{tmp7});
    ca_.Branch(tmp8, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block2);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<NativeContext> tmp9;
  TNode<Smi> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp9 = WasmBuiltinsAssembler(state_).LoadContextFromInstance(TNode<WasmInstanceObject>{tmp0});
    tmp10 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T>{parameter0});
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmRefFunc, tmp9, tmp0, tmp10);
  }
}

TF_BUILTIN(WasmThrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrow, tmp0, parameter0);
  }
}

TF_BUILTIN(WasmRethrow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Null_0(state_);
    tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{parameter0}, TNode<HeapObject>{tmp0});
    ca_.Branch(tmp1, &block1, std::vector<Node*>{}, &block2, std::vector<Node*>{});
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kThrowWasmTrapRethrowNullRef, TNode<Object>());
  }

  TNode<NativeContext> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kReThrow, tmp2, parameter0);
  }
}

TF_BUILTIN(WasmStackGuard, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStackGuard, tmp0);
  }
}

TF_BUILTIN(WasmStackOverflow, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrowWasmStackOverflow, tmp0);
  }
}

TF_BUILTIN(WasmTraceMemory, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceMemory, tmp0, parameter0);
  }
}

TF_BUILTIN(WasmAllocateJSArray, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<JSArray> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{parameter0});
    tmp1 = CodeStubAssembler(state_).AllocateJSArray(ElementsKind::PACKED_ELEMENTS, TNode<Map>{tmp0}, TNode<Smi>{parameter1}, TNode<Smi>{parameter1});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(WasmGetOwnProperty, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Name> parameter2 = UncheckedCast<Name>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block4);
  }

  TNode<JSReceiver> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSReceiver_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp4;
  TNode<Map> tmp5;
  TNode<Uint16T> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp2, tmp4});
    tmp6 = CodeStubAssembler(state_).LoadInstanceType(TNode<HeapObject>{tmp2});
    compiler::CodeAssemblerLabel label7(&ca_);
    compiler::CodeAssemblerLabel label8(&ca_);
    compiler::CodeAssemblerLabel label9(&ca_);
    CodeStubAssembler(state_).TryHasOwnProperty(TNode<HeapObject>{tmp2}, TNode<Map>{tmp5}, TNode<Uint16T>{tmp6}, TNode<Name>{parameter2}, &label7, &label8, &label9);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block11);
    }
    if (label8.is_used()) {
      ca_.Bind(&label8);
      ca_.Goto(&block12);
    }
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block13);
    }
  }

  TNode<Smi> tmp10;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp10 = CodeStubAssembler(state_).SmiConstant(OnNonExistent::kReturnUndefined);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kGetPropertyWithReceiver, parameter0, tmp2, parameter2, tmp2, tmp10);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block4);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp11 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp11);
  }
}

TF_BUILTIN(WasmTrap, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadContextFromFrame_0(state_);
    CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrowWasmError, tmp0, parameter0);
  }
}

TF_BUILTIN(ThrowWasmTrapUnreachable, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapUnreachable);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapMemOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapMemOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapUnalignedAccess, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapUnalignedAccess);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapDivByZero, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDivByZero);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapDivUnrepresentable, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDivUnrepresentable);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapRemByZero, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapRemByZero);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapFloatUnrepresentable, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFloatUnrepresentable);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapFuncInvalid, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFuncInvalid);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapFuncSigMismatch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFuncSigMismatch);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapDataSegmentDropped, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDataSegmentDropped);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapElemSegmentDropped, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapElemSegmentDropped);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapTableOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapTableOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapBrOnExnNullRef, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapBrOnExnNullRef);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapRethrowNullRef, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapRethrowNullRef);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapNullDereference, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapNullDereference);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapIllegalCast, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapIllegalCast);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

TF_BUILTIN(ThrowWasmTrapArrayOutOfBounds, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kWasmTrap, TNode<Object>(), tmp0);
  }
}

}  // namespace internal
}  // namespace v8

