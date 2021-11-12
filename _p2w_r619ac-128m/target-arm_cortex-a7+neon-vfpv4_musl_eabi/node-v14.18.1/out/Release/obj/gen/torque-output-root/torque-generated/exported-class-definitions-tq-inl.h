#ifndef V8_GEN_TORQUE_GENERATED_EXPORTED_CLASS_DEFINITIONS_TQ_INL_H_
#define V8_GEN_TORQUE_GENERATED_EXPORTED_CLASS_DEFINITIONS_TQ_INL_H_

#include "torque-generated/exported-class-definitions-tq.h"
#include "src/objects/fixed-array-inl.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"
namespace v8 {
namespace internal {
template <class D, class P>
HeapObject TorqueGeneratedExportedSubClassBase<D, P>::a() const {
  const Isolate* isolate = GetIsolateForPtrCompr(*this);
  return TorqueGeneratedExportedSubClassBase::a(isolate);
}
template <class D, class P>
HeapObject TorqueGeneratedExportedSubClassBase<D, P>::a(const Isolate* isolate) const {
  auto value = TaggedField<HeapObject, kAOffset>::load(isolate, *this);
  DCHECK(value.IsHeapObject());
  return value;
}
template <class D, class P>
void TorqueGeneratedExportedSubClassBase<D, P>::set_a(HeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsHeapObject());
  RELAXED_WRITE_FIELD(*this, kAOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kAOffset, value, mode);
}

template <class D, class P>
HeapObject TorqueGeneratedExportedSubClassBase<D, P>::b() const {
  const Isolate* isolate = GetIsolateForPtrCompr(*this);
  return TorqueGeneratedExportedSubClassBase::b(isolate);
}
template <class D, class P>
HeapObject TorqueGeneratedExportedSubClassBase<D, P>::b(const Isolate* isolate) const {
  auto value = TaggedField<HeapObject, kBOffset>::load(isolate, *this);
  DCHECK(value.IsHeapObject());
  return value;
}
template <class D, class P>
void TorqueGeneratedExportedSubClassBase<D, P>::set_b(HeapObject value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsHeapObject());
  RELAXED_WRITE_FIELD(*this, kBOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedExportedSubClassBase<D, P>::TorqueGeneratedExportedSubClassBase(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(this->IsExportedSubClassBase());
}
template<class D, class P>
inline TorqueGeneratedExportedSubClassBase<D, P>::TorqueGeneratedExportedSubClassBase(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || this->IsExportedSubClassBase());
}
TQ_OBJECT_CONSTRUCTORS_IMPL(ExportedSubClassBase)
template <class D, class P>
int32_t TorqueGeneratedExportedSubClass<D, P>::c_field() const {
  return this->template ReadField<int32_t>(kCFieldOffset);
}
template <class D, class P>
void TorqueGeneratedExportedSubClass<D, P>::set_c_field(int32_t value) {
  this->template WriteField<int32_t>(kCFieldOffset, value);
}

template <class D, class P>
int32_t TorqueGeneratedExportedSubClass<D, P>::d_field() const {
  return this->template ReadField<int32_t>(kDFieldOffset);
}
template <class D, class P>
void TorqueGeneratedExportedSubClass<D, P>::set_d_field(int32_t value) {
  this->template WriteField<int32_t>(kDFieldOffset, value);
}

template <class D, class P>
int TorqueGeneratedExportedSubClass<D, P>::e_field() const {
  return TaggedField<Smi, kEFieldOffset>::load(*this).value();
}
template <class D, class P>
void TorqueGeneratedExportedSubClass<D, P>::set_e_field(int value) {
  WRITE_FIELD(*this, kEFieldOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedExportedSubClass<D, P>::TorqueGeneratedExportedSubClass(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(this->IsExportedSubClass());
}
template<class D, class P>
inline TorqueGeneratedExportedSubClass<D, P>::TorqueGeneratedExportedSubClass(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || this->IsExportedSubClass());
}
TQ_OBJECT_CONSTRUCTORS_IMPL(ExportedSubClass)
}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"
#endif  // V8_GEN_TORQUE_GENERATED_EXPORTED_CLASS_DEFINITIONS_TQ_INL_H_
