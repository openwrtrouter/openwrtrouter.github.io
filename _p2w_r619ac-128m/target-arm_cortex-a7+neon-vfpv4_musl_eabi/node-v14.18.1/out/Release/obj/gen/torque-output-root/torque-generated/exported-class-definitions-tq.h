#ifndef V8_GEN_TORQUE_GENERATED_EXPORTED_CLASS_DEFINITIONS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_EXPORTED_CLASS_DEFINITIONS_TQ_H_

#include "src/objects/fixed-array.h"
#include "torque-generated/class-definitions-tq.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"
namespace v8 {
namespace internal {
template <class D, class P>
class TorqueGeneratedExportedSubClassBase : public P {
  static_assert(std::is_same<ExportedSubClassBase, D>::value,
    "Use this class as direct base for ExportedSubClassBase.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedExportedSubClassBase.");
 public: 
  using Super = P;

  inline HeapObject a() const;
  inline HeapObject a(const Isolate* isolates) const;
  inline void set_a(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject b() const;
  inline HeapObject b(const Isolate* isolates) const;
  inline void set_b(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(ExportedSubClassBase)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ExportedSubClassBaseVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kAOffset = P::kHeaderSize;
  static constexpr int kAOffsetEnd = kAOffset + kTaggedSize - 1;
  static constexpr int kBOffset = kAOffsetEnd + 1;
  static constexpr int kBOffsetEnd = kBOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kHeaderSize = kBOffsetEnd + 1;
  static constexpr int kSize = kBOffsetEnd + 1;

  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  V8_INLINE int32_t AllocatedSize() {
    return SizeFor();
  }

  friend class Factory;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedExportedSubClassBase() : P() {
    static_assert(std::is_base_of<TorqueGeneratedExportedSubClassBase, 
      DAlias>::value,
      "class TorqueGeneratedExportedSubClassBase should be used as direct base for ExportedSubClassBase.");
  }
protected:
  inline explicit TorqueGeneratedExportedSubClassBase(Address ptr);
  // Special-purpose constructor for subclasses that have fast paths where
  // their ptr() is a Smi.
  inline explicit TorqueGeneratedExportedSubClassBase(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi);
};

class ExportedSubClassBase : public TorqueGeneratedExportedSubClassBase<ExportedSubClassBase, HeapObject> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(ExportedSubClassBase)
};

template <class D, class P>
class TorqueGeneratedExportedSubClass : public P {
  static_assert(std::is_same<ExportedSubClass, D>::value,
    "Use this class as direct base for ExportedSubClass.");
  static_assert(std::is_same<ExportedSubClassBase, P>::value,
    "Pass in ExportedSubClassBase as second template parameter for TorqueGeneratedExportedSubClass.");
 public: 
  using Super = P;

  inline int32_t c_field() const;
  inline void set_c_field(int32_t value);

  inline int32_t d_field() const;
  inline void set_d_field(int32_t value);

  inline int e_field() const;
  inline void set_e_field(int value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(ExportedSubClass)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ExportedSubClassVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kCFieldOffset = P::kHeaderSize;
  static constexpr int kCFieldOffsetEnd = kCFieldOffset + kInt32Size - 1;
  static constexpr int kDFieldOffset = kCFieldOffsetEnd + 1;
  static constexpr int kDFieldOffsetEnd = kDFieldOffset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kDFieldOffsetEnd + 1;
  static constexpr int kEFieldOffset = kDFieldOffsetEnd + 1;
  static constexpr int kEFieldOffsetEnd = kEFieldOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEFieldOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEFieldOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEFieldOffsetEnd + 1;
  static constexpr int kHeaderSize = kEFieldOffsetEnd + 1;
  static constexpr int kSize = kEFieldOffsetEnd + 1;

  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  V8_INLINE int32_t AllocatedSize() {
    return SizeFor();
  }

  friend class Factory;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedExportedSubClass() : P() {
    static_assert(std::is_base_of<TorqueGeneratedExportedSubClass, 
      DAlias>::value,
      "class TorqueGeneratedExportedSubClass should be used as direct base for ExportedSubClass.");
  }
protected:
  inline explicit TorqueGeneratedExportedSubClass(Address ptr);
  // Special-purpose constructor for subclasses that have fast paths where
  // their ptr() is a Smi.
  inline explicit TorqueGeneratedExportedSubClass(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi);
};

class ExportedSubClass : public TorqueGeneratedExportedSubClass<ExportedSubClass, ExportedSubClassBase> {
 public:
  class BodyDescriptor;
  TQ_OBJECT_CONSTRUCTORS(ExportedSubClass)
};

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"
#endif  // V8_GEN_TORQUE_GENERATED_EXPORTED_CLASS_DEFINITIONS_TQ_H_
