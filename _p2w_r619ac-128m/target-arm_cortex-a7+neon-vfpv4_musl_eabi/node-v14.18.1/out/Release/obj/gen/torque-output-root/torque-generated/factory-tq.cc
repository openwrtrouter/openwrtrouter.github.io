#include "src/heap/factory.h"
#include "src/heap/factory-inl.h"
#include "src/heap/heap.h"
#include "src/heap/heap-inl.h"
#include "src/execution/isolate.h"

#include "torque-generated/internal-class-definitions-tq-inl.h"

#include "torque-generated/exported-class-definitions-tq-inl.h"

namespace v8 {
namespace internal {

Handle<ExportedSubClassBase> Factory::NewExportedSubClassBase(Handle<HeapObject> a, Handle<HeapObject> b, AllocationType allocation_type) {
 int size = TorqueGeneratedExportedSubClassBase<ExportedSubClassBase, HeapObject>::SizeFor();
  ReadOnlyRoots roots(isolate());
  HeapObject result =
    isolate()->heap()->AllocateRawWith<Heap::kRetryOrFail>(size, allocation_type);
  result.set_map_after_allocation(roots.exported_sub_class_base_map(), SKIP_WRITE_BARRIER);
  Handle<ExportedSubClassBase> result_handle(ExportedSubClassBase::cast(result), isolate());
  result_handle->set_a(*a, SKIP_WRITE_BARRIER);
  result_handle->set_b(*b, SKIP_WRITE_BARRIER);
  return result_handle;
}

Handle<ExportedSubClass> Factory::NewExportedSubClass(Handle<HeapObject> a, Handle<HeapObject> b, int32_t c_field, int32_t d_field, int e_field, AllocationType allocation_type) {
 int size = TorqueGeneratedExportedSubClass<ExportedSubClass, ExportedSubClassBase>::SizeFor();
  ReadOnlyRoots roots(isolate());
  HeapObject result =
    isolate()->heap()->AllocateRawWith<Heap::kRetryOrFail>(size, allocation_type);
  result.set_map_after_allocation(roots.exported_sub_class_map(), SKIP_WRITE_BARRIER);
  Handle<ExportedSubClass> result_handle(ExportedSubClass::cast(result), isolate());
  result_handle->set_a(*a, SKIP_WRITE_BARRIER);
  result_handle->set_b(*b, SKIP_WRITE_BARRIER);
  result_handle->set_c_field(c_field);
  result_handle->set_d_field(d_field);
  result_handle->set_e_field(e_field);
  return result_handle;
}

}  // namespace internal
}  // namespace v8
