// Unit-private decal record and declarations missing from the shared header.
#ifndef FNV_EXTRADATAOBJECTS_ADDITIONS_H
#define FNV_EXTRADATAOBJECTS_ADDITIONS_H

class ReferenceIntersectionData
{
  public:
    TESObjectREFR* m_pHitReference;  // +0x0, 4 bytes
    NiPoint3 Intersect;              // +0x4, 12 bytes
    NiPoint3 Normal;                 // +0x10, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(ReferenceIntersectionData) == 28);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, m_pHitReference) == 0);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, Intersect) == 4);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, Normal) == 16);


FNV_STATIC_ASSERT(sizeof(ExtraDecalRefs) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraDecalRefs, m_kDecalReferences) == 12);


void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* pointer);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

#endif
