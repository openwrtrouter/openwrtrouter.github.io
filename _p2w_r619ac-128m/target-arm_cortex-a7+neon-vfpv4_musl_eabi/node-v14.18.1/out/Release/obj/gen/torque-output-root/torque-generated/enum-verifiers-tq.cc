#include "src/compiler/code-assembler.h"
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

namespace v8 {
namespace internal {
namespace  {
class EnumVerifier {
  // UnicodeEncoding (../../deps/v8/src/builtins/base.tq:188:1)
  void VerifyEnum_UnicodeEncoding(UnicodeEncoding x) {
    switch(x) {
      case UnicodeEncoding::UTF16: break;
      case UnicodeEncoding::UTF32: break;
    }
  }

  // PromiseState (../../deps/v8/src/builtins/base.tq:191:1)
  void VerifyEnum_PromiseState(Promise::PromiseState x) {
    switch(x) {
      case Promise::PromiseState::kPending: break;
      case Promise::PromiseState::kFulfilled: break;
      case Promise::PromiseState::kRejected: break;
    }
  }

  // ElementsKind (../../deps/v8/src/builtins/base.tq:209:1)
  void VerifyEnum_ElementsKind(ElementsKind x) {
    switch(x) {
      case ElementsKind::NO_ELEMENTS: break;
      case ElementsKind::PACKED_SMI_ELEMENTS: break;
      case ElementsKind::HOLEY_SMI_ELEMENTS: break;
      case ElementsKind::PACKED_ELEMENTS: break;
      case ElementsKind::HOLEY_ELEMENTS: break;
      case ElementsKind::PACKED_DOUBLE_ELEMENTS: break;
      case ElementsKind::HOLEY_DOUBLE_ELEMENTS: break;
      case ElementsKind::LAST_ANY_NONEXTENSIBLE_ELEMENTS_KIND: break;
      case ElementsKind::DICTIONARY_ELEMENTS: break;
      case ElementsKind::UINT8_ELEMENTS: break;
      case ElementsKind::INT8_ELEMENTS: break;
      case ElementsKind::UINT16_ELEMENTS: break;
      case ElementsKind::INT16_ELEMENTS: break;
      case ElementsKind::UINT32_ELEMENTS: break;
      case ElementsKind::INT32_ELEMENTS: break;
      case ElementsKind::FLOAT32_ELEMENTS: break;
      case ElementsKind::FLOAT64_ELEMENTS: break;
      case ElementsKind::UINT8_CLAMPED_ELEMENTS: break;
      case ElementsKind::BIGUINT64_ELEMENTS: break;
      case ElementsKind::BIGINT64_ELEMENTS: break;
      default: break;
    }
  }

  // AllocationFlag (../../deps/v8/src/builtins/base.tq:235:1)
  void VerifyEnum_AllocationFlag(CodeStubAssembler::AllocationFlag x) {
    switch(x) {
      case CodeStubAssembler::AllocationFlag::kNone: break;
      case CodeStubAssembler::AllocationFlag::kDoubleAlignment: break;
      case CodeStubAssembler::AllocationFlag::kPretenured: break;
      case CodeStubAssembler::AllocationFlag::kAllowLargeObjectAllocation: break;
    }
  }

  // SlackTrackingMode (../../deps/v8/src/builtins/base.tq:242:1)
  void VerifyEnum_SlackTrackingMode(CodeStubAssembler::SlackTrackingMode x) {
    switch(x) {
      case CodeStubAssembler::SlackTrackingMode::kWithSlackTracking: break;
      case CodeStubAssembler::SlackTrackingMode::kNoSlackTracking: break;
    }
  }

  // ExtractFixedArrayFlag (../../deps/v8/src/builtins/base.tq:248:1)
  void VerifyEnum_ExtractFixedArrayFlag(CodeStubAssembler::ExtractFixedArrayFlag x) {
    switch(x) {
      case CodeStubAssembler::ExtractFixedArrayFlag::kFixedDoubleArrays: break;
      case CodeStubAssembler::ExtractFixedArrayFlag::kAllFixedArrays: break;
      case CodeStubAssembler::ExtractFixedArrayFlag::kFixedArrays: break;
      default: break;
    }
  }

  // MessageTemplate (../../deps/v8/src/builtins/base.tq:258:1)
  void VerifyEnum_MessageTemplate(MessageTemplate x) {
    switch(x) {
      case MessageTemplate::kAllPromisesRejected: break;
      case MessageTemplate::kInvalidArrayBufferLength: break;
      case MessageTemplate::kInvalidArrayLength: break;
      case MessageTemplate::kInvalidIndex: break;
      case MessageTemplate::kNotConstructor: break;
      case MessageTemplate::kNotGeneric: break;
      case MessageTemplate::kCalledNonCallable: break;
      case MessageTemplate::kCalledOnNullOrUndefined: break;
      case MessageTemplate::kProtoObjectOrNull: break;
      case MessageTemplate::kInvalidOffset: break;
      case MessageTemplate::kInvalidTypedArrayLength: break;
      case MessageTemplate::kIteratorSymbolNonCallable: break;
      case MessageTemplate::kIteratorValueNotAnObject: break;
      case MessageTemplate::kNotIterable: break;
      case MessageTemplate::kReduceNoInitial: break;
      case MessageTemplate::kFirstArgumentNotRegExp: break;
      case MessageTemplate::kBigIntMixedTypes: break;
      case MessageTemplate::kTypedArrayTooShort: break;
      case MessageTemplate::kInvalidCountValue: break;
      case MessageTemplate::kConstructorNotFunction: break;
      case MessageTemplate::kSymbolToString: break;
      case MessageTemplate::kPropertyNotFunction: break;
      case MessageTemplate::kBigIntTooBig: break;
      case MessageTemplate::kNotTypedArray: break;
      case MessageTemplate::kDetachedOperation: break;
      case MessageTemplate::kBadSortComparisonFunction: break;
      case MessageTemplate::kIncompatibleMethodReceiver: break;
      case MessageTemplate::kInvalidDataViewAccessorOffset: break;
      case MessageTemplate::kTypedArraySetOffsetOutOfBounds: break;
      case MessageTemplate::kInvalidArgument: break;
      case MessageTemplate::kInvalidRegExpExecResult: break;
      case MessageTemplate::kRegExpNonRegExp: break;
      case MessageTemplate::kRegExpNonObject: break;
      case MessageTemplate::kPromiseNonCallable: break;
      case MessageTemplate::kNotAPromise: break;
      case MessageTemplate::kResolverNotAFunction: break;
      case MessageTemplate::kTooManyElementsInPromiseCombinator: break;
      case MessageTemplate::kToRadixFormatRange: break;
      case MessageTemplate::kCalledOnNonObject: break;
      case MessageTemplate::kRegExpGlobalInvokedOnNonGlobal: break;
      case MessageTemplate::kProxyNonObject: break;
      case MessageTemplate::kProxyRevoked: break;
      case MessageTemplate::kProxyTrapReturnedFalsishFor: break;
      case MessageTemplate::kProxyPrivate: break;
      case MessageTemplate::kProxyIsExtensibleInconsistent: break;
      case MessageTemplate::kProxyPreventExtensionsExtensible: break;
      case MessageTemplate::kProxyTrapReturnedFalsish: break;
      case MessageTemplate::kProxyGetPrototypeOfInvalid: break;
      case MessageTemplate::kProxyGetPrototypeOfNonExtensible: break;
      case MessageTemplate::kProxySetPrototypeOfNonExtensible: break;
      case MessageTemplate::kProxyDeletePropertyNonExtensible: break;
      case MessageTemplate::kWeakRefsCleanupMustBeCallable: break;
      case MessageTemplate::kWasmTrapUnreachable: break;
      case MessageTemplate::kWasmTrapMemOutOfBounds: break;
      case MessageTemplate::kWasmTrapUnalignedAccess: break;
      case MessageTemplate::kWasmTrapDivByZero: break;
      case MessageTemplate::kWasmTrapDivUnrepresentable: break;
      case MessageTemplate::kWasmTrapRemByZero: break;
      case MessageTemplate::kWasmTrapFloatUnrepresentable: break;
      case MessageTemplate::kWasmTrapFuncInvalid: break;
      case MessageTemplate::kWasmTrapFuncSigMismatch: break;
      case MessageTemplate::kWasmTrapDataSegmentDropped: break;
      case MessageTemplate::kWasmTrapElemSegmentDropped: break;
      case MessageTemplate::kWasmTrapTableOutOfBounds: break;
      case MessageTemplate::kWasmTrapBrOnExnNullRef: break;
      case MessageTemplate::kWasmTrapRethrowNullRef: break;
      case MessageTemplate::kWasmTrapNullDereference: break;
      case MessageTemplate::kWasmTrapIllegalCast: break;
      case MessageTemplate::kWasmTrapArrayOutOfBounds: break;
      default: break;
    }
  }

  // PrimitiveType (../../deps/v8/src/builtins/base.tq:374:1)
  void VerifyEnum_PrimitiveType(PrimitiveType x) {
    switch(x) {
      case PrimitiveType::kString: break;
      case PrimitiveType::kBoolean: break;
      case PrimitiveType::kSymbol: break;
      case PrimitiveType::kNumber: break;
    }
  }

  // LanguageMode (../../deps/v8/src/builtins/base.tq:421:1)
  void VerifyEnum_LanguageMode(LanguageMode x) {
    switch(x) {
      case LanguageMode::kStrict: break;
      case LanguageMode::kSloppy: break;
    }
  }

  // PromiseAllResolveElementContextSlots (../../deps/v8/src/builtins/promise-all-element-closure.tq:65:1)
  void VerifyEnum_PromiseAllResolveElementContextSlots(PromiseBuiltins::PromiseAllResolveElementContextSlots x) {
    switch(x) {
      case PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot: break;
      case PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot: break;
      case PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot: break;
      case PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementLength: break;
    }
  }

  // PromiseAnyRejectElementContextSlots (../../deps/v8/src/builtins/promise-any.tq:8:1)
  void VerifyEnum_PromiseAnyRejectElementContextSlots(PromiseBuiltins::PromiseAnyRejectElementContextSlots x) {
    switch(x) {
      case PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementRemainingSlot: break;
      case PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementCapabilitySlot: break;
      case PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementErrorsArraySlot: break;
      case PromiseBuiltins::PromiseAnyRejectElementContextSlots::kPromiseAnyRejectElementLength: break;
    }
  }

  // Flag (../../deps/v8/src/builtins/regexp.tq:182:1)
  void VerifyEnum_Flag(JSRegExp::Flag x) {
    switch(x) {
      case JSRegExp::Flag::kNone: break;
      case JSRegExp::Flag::kGlobal: break;
      case JSRegExp::Flag::kIgnoreCase: break;
      case JSRegExp::Flag::kMultiline: break;
      case JSRegExp::Flag::kSticky: break;
      case JSRegExp::Flag::kUnicode: break;
      case JSRegExp::Flag::kDotAll: break;
      case JSRegExp::Flag::kInvalid: break;
    }
  }

  // NativeContextSlot (../../deps/v8/src/objects/contexts.tq:26:1)
  void VerifyEnum_NativeContextSlot(Context::Field x) {
    switch(x) {
      case Context::Field::AGGREGATE_ERROR_FUNCTION_INDEX: break;
      case Context::Field::ARRAY_BUFFER_FUN_INDEX: break;
      case Context::Field::ARRAY_BUFFER_NOINIT_FUN_INDEX: break;
      case Context::Field::ARRAY_BUFFER_MAP_INDEX: break;
      case Context::Field::ARRAY_FUNCTION_INDEX: break;
      case Context::Field::ARRAY_JOIN_STACK_INDEX: break;
      case Context::Field::OBJECT_FUNCTION_INDEX: break;
      case Context::Field::ITERATOR_RESULT_MAP_INDEX: break;
      case Context::Field::JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX: break;
      case Context::Field::JS_ARRAY_PACKED_SMI_ELEMENTS_MAP_INDEX: break;
      case Context::Field::MATH_RANDOM_CACHE_INDEX: break;
      case Context::Field::MATH_RANDOM_INDEX_INDEX: break;
      case Context::Field::PROXY_REVOCABLE_RESULT_MAP_INDEX: break;
      case Context::Field::REFLECT_APPLY_INDEX: break;
      case Context::Field::REGEXP_FUNCTION_INDEX: break;
      case Context::Field::REGEXP_LAST_MATCH_INFO_INDEX: break;
      case Context::Field::INITIAL_STRING_ITERATOR_MAP_INDEX: break;
      case Context::Field::SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP: break;
      case Context::Field::STRICT_ARGUMENTS_MAP_INDEX: break;
      case Context::Field::SLOPPY_ARGUMENTS_MAP_INDEX: break;
      case Context::Field::FAST_ALIASED_ARGUMENTS_MAP_INDEX: break;
      case Context::Field::PROMISE_FUNCTION_INDEX: break;
      case Context::Field::PROMISE_THEN_INDEX: break;
      case Context::Field::PROMISE_PROTOTYPE_INDEX: break;
      case Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX: break;
      case Context::Field::PROMISE_HOOK_INIT_FUNCTION_INDEX: break;
      case Context::Field::PROMISE_HOOK_BEFORE_FUNCTION_INDEX: break;
      case Context::Field::PROMISE_HOOK_AFTER_FUNCTION_INDEX: break;
      case Context::Field::PROMISE_HOOK_RESOLVE_FUNCTION_INDEX: break;
      case Context::Field::CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX: break;
      default: break;
    }
  }

};
}  // namespace 
}  // namespace internal
}  // namespace v8
