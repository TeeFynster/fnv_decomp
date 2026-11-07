// Exe 0x00c215d0: nothrow smart-pointer inlines preserve the original EH cleanup.
#define FNV64_NIPOINTER_EXCEPTION_SPEC throw()
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../../include/NiPointer.h"
// src/gamebryo2.2/corelibs/niparticle/nipsysmeshupdatemodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysmeshupdatemodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysMeshUpdateModifier.h"
#include "../../../../include/NiTObjectArray.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

// Gamebryo inline bodies (NiTArray.inl / NiTCollection.h) this unit's original inlines:
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{
    return m_usSize;
}

template <class T, class TAlloc> inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = TAlloc::Allocate(m_usMaxSize);
    else
        m_pBase = 0;
}
template <class T> inline T* NiTNewInterface<T>::Allocate(unsigned int uiNumElements)
{
    return new T[uiNumElements];
}
template <class T>
inline NiTObjectArray<T>::NiTObjectArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTArray<T, NiTNewInterface<T> >(uiMaxSize, uiGrowBy)
{
}


extern "C" void* g_01202530;

// @fnv 0x00c21720
// src: COMMUNITY 0x00c21720
void* __cdecl NiPSysMeshUpdateModifier_GetRTTI()
{
    return &g_01202530;
}

// Calls the base modifier's ProcessClone, then clones each non-null mesh in m_kSceneObjects.
// @fnv 0x00c20f30
// src: XBOX_PDB 0x00c20f30
void NiPSysMeshUpdateModifier::ProcessClone_00c20f30(CloningProcess& kCloning)
{
    NiPSysModifier::ProcessClone(kCloning);
    unsigned int ui;
    NiAVObject* pkMesh;
    for (ui = 0; ui < m_kSceneObjects.m_usSize; ui++)
    {
        pkMesh = m_kSceneObjects.m_pBase[ui].m_pObject;
        if (pkMesh)
            pkMesh->ProcessClone(kCloning);
    }
}

namespace fnv_00c20f80 {
struct Holder31670
{
    bool FUN_00c31670(NiStream&);
};
}  // namespace fnv_00c20f80
// @fnv 0x00c20f80
// src: XBOX_PDB 0x00c20f80
bool NiPSysMeshUpdateModifier::RegisterStreamables_00c20f80(NiStream& kStream)
{
    if (!((fnv_00c20f80::Holder31670*)this)->FUN_00c31670(kStream))
        return false;
    unsigned int ui;
    NiAVObject* pkMesh;
    for (ui = 0; ui < m_kSceneObjects.m_usSize; ui++)
    {
        pkMesh = m_kSceneObjects.m_pBase[ui].m_pObject;
        if (pkMesh)
            pkMesh->RegisterStreamables(kStream);
    }
    return true;
}

extern int DAT_0101fbcc;
void __cdecl j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(void*);
struct Holder31750
{
    void FUN_00c31750();
};
void __cdecl _delete(void*, unsigned int);
struct Unk21730
{
    char _0[0x18];
    void* a;
    void* b;
    char _1[8];
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00c21730
void* Unk21730::DestroyIfFlagged(unsigned int auiFlags)
{
    void* tmp = b;
    a = &DAT_0101fbcc;
    j_Deallocate_NiTNewInterface_V_NiPointer_VNiAVObject_SAXPAV_NiPointer_VNiAVObject_Z(tmp);
    ((Holder31750*)this)->FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x28);
    return this;
}

namespace fnv_00c21840 {
char* __cdecl _FUN_00a7d330(void*);

struct BaseMod
{
    void FUN_00c319e0(StrArr*);
};
}  // namespace fnv_00c21840
// Calls the base handler, then appends the string returned by _FUN_00a7d330(g_01202530) to pkStrings, growing it if full.
// @fnv 0x00c21840
void NiPSysMeshUpdateModifier::AppendString(StrArr* pkStrings)
{
    reinterpret_cast<fnv_00c21840::BaseMod*>(this)->FUN_00c319e0(pkStrings);
    char* pcStr = fnv_00c21840::_FUN_00a7d330(g_01202530);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pcStr);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefHandle
{
    NiRefObject* ptr;
    explicit RefHandle(NiRefObject* p) : ptr(p)
    {
        if (p)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
            if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)))
                p->DeleteThis();
        }
    }
};
struct RefArray
{
    void* unk00;
    NiRefObject** entries;
    unsigned short capacity;
    unsigned short size;
    unsigned short count;
    RefHandle PopBack();
};

// Removes and returns the last entry of the array, decrementing the count and releasing the slot's reference.
// @fnv 0x00c20fd0
RefHandle RefArray::PopBack()
{
    if (!size)
        return RefHandle(0);
    NiRefObject* object = entries[--size];
    if (object)
        InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    NiRefObject** slot = entries + size;
    NiRefObject* old = *slot;
    if (old)
    {
        if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)))
            old->DeleteThis();
        *slot = 0;
    }
    const bool& x = object != 0;
    if (x)
        --count;
    return RefHandle(object);
}


class FUN_00c212b0_item
{
  public:
    char unk00[8];
    unsigned short m_usElementCount;
    void FUN_004b0310(unsigned int, void**);
};

class FUN_00c212b0_cls
{
  public:
    char unk00[0x8c];
    FUN_00c212b0_item** m_ppItems;
    char unk90[2];
    unsigned short m_usNumMeshes;
    void NiMeshPSysData_FillPool(unsigned int a1, NiAVObject* a2);
};

// @fnv 0x00c212b0
// src: XBOX_PDB 0x00c212b0
void FUN_00c212b0_cls::NiMeshPSysData_FillPool(unsigned int uiIndex, NiAVObject* pSource)
{
    if (uiIndex < m_usNumMeshes && m_ppItems[uiIndex] != 0)
    {
        FUN_00c212b0_item* item = m_ppItems[uiIndex];
        unsigned int i = 0;
        if (i < item->m_usElementCount)
        {
            do
            {
                NiRefObject* p = (NiRefObject*)pSource->Clone();
                void* out = p;
                if (p != 0)
                {
                    InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
                }
                item->FUN_004b0310(i, &out);
                if (p != 0)
                {
                    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
                    {
                        p->DeleteThis();
                    }
                }
                ++i;
            } while (i < item->m_usElementCount);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct CloneHandle;
struct MeshObject
{
    CloneHandle __thiscall PopBack() throw();
};
struct CloneHandle
{
    NiRefObject* pointer;
    ~CloneHandle() throw()
    {
        if (pointer)
        {
            NiRefObject* oldObject = pointer;
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&oldObject->m_uiRefCount)) == 0)
            {
                oldObject->DeleteThis();
            }
        }
    }
    void Clear()
    {
        if (pointer)
        {
            NiRefObject* oldObject = pointer;
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&oldObject->m_uiRefCount)) == 0)
            {
                oldObject->DeleteThis();
            }
            pointer = 0;
        }
    }
    CloneHandle& __thiscall FUN_006e5cc0(const CloneHandle& other) throw();
};
struct MeshLookup
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    MeshObject** meshes;
    unsigned short unk90;
    unsigned short meshCount;
    void __thiscall GetMeshHandle(unsigned int index, CloneHandle* result);
};
// If index is within meshCount and meshes[index] is non-null, assigns a clone handle of that mesh to result; otherwise clears result.
// @fnv 0x00c21340
void MeshLookup::GetMeshHandle(unsigned int index, CloneHandle* result)
{
    if (index >= meshCount)
    {
        result->Clear();
        return;
    }
    if (meshes[index] == 0)
    {
        result->Clear();
        return;
    }
    result->FUN_006e5cc0(meshes[index]->PopBack());
}

// NiPSysMeshUpdateModifier's constructor is inline: NiPSysModifier::NiPSysModifier (0x00c31720), the vftable,
// then m_kSceneObjects as NiTObjectArray(0, 1).
inline NiPSysMeshUpdateModifier::NiPSysMeshUpdateModifier() throw()
{
}

// Allocates and returns a new NiPSysMeshUpdateModifier (the stream factory).
// @fnv 0x00c217f0
NiObject* NiPSysMeshUpdateModifier::CreateModifier()
{
    return new NiPSysMeshUpdateModifier;
}

// Clones the modifier: a new NiPSysMeshUpdateModifier whose members CopyMemberData (0x00c21770) fills.
// @fnv 0x00c21890
NiObject* NiPSysMeshUpdateModifier::MakeClone(CloningProcess& kCloning)
{
    NiPSysMeshUpdateModifier* pkClone = new NiPSysMeshUpdateModifier;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedIncrement(volatile long* p);
__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedDecrement(volatile long* p);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

inline void NiAVObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}

inline void NiAVObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}



typedef NiPointer<NiAVObject> MyMeshObjPtr;

// local form of NiTArray: 0x00c215d0 needs nothrow inline helpers (shared trial is 399 bytes, exe 329).
class MyMeshPtrArray
{
  public:
    virtual ~MyMeshPtrArray() throw();
    MyMeshObjPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() const throw()
    {
        return m_usSize;
    }
    const MyMeshObjPtr& GetAt(unsigned int i) const throw()
    {
        return m_pBase[i];
    }
    __declspec(nothrow) void SetAt(unsigned int i, const MyMeshObjPtr& e) throw()
    {
        static const MyMeshObjPtr nil;
        if (i >= m_usSize)
        {
            m_usSize = (unsigned short)(i + 1);
            if (e != nil)
                ++m_usESize;
        }
        else if (e != nil)
        {
            if (m_pBase[i] == nil)
                ++m_usESize;
        }
        else
        {
            if (m_pBase[i] != nil)
                --m_usESize;
        }
        m_pBase[i] = e;
    }
    __declspec(nothrow) void SetSize(unsigned int n) throw();
    unsigned int SetAtGrow(unsigned int i, const MyMeshObjPtr& e) throw()
    {
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, e);
        return i;
    }
};

class MyMeshUpdateMod
{
  public:
    virtual ~MyMeshUpdateMod() throw();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MyMeshPtrArray m_kSceneObjects;
    void SetMeshAt(unsigned int uiIndex, NiAVObject* pkMesh, MyMeshObjPtr& spOld);
};

// Stores pkMesh at uiIndex in the mesh pointer array, returning the previous entry in spOld (or null when growing).
// @fnv 0x00c215d0
void MyMeshUpdateMod::SetMeshAt(unsigned int uiIndex, NiAVObject* pkMesh, MyMeshObjPtr& spOld)
{
    if (uiIndex < m_kSceneObjects.GetSize())
    {
        MyMeshObjPtr spPrev = m_kSceneObjects.GetAt(uiIndex);
        m_kSceneObjects.SetAt(uiIndex, pkMesh);
        spOld = spPrev;
    }
    else
    {
        m_kSceneObjects.SetAtGrow(uiIndex, pkMesh);
        spOld = 0;
    }
}

struct BinaryStream
{
    void* unk00;
    unsigned int offset;
    void* unk08;
    unsigned int(__cdecl* write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    __forceinline unsigned int WriteData(const void* data, unsigned int size)
    {
        unsigned int elementSize = 4;
        return write(this, data, size, &elementSize, 1);
    }
};
// Keep the original inline access while using the shared stream declaration.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return reinterpret_cast<NiBinaryStream*&>(m_pkOstr);
}

inline unsigned int NiStream::GetFileVersion() const
{
    return m_uiNifFileVersion;
}

class MeshUpdateStreamWriter : public NiPSysMeshUpdateModifier
{
  public:
    void FUN_00c31950(NiStream*);
    void WriteMeshUpdate(NiStream*);
};
// Writes the mesh count to the stream, then registers each mesh object with the stream.
// @fnv 0x00c211c0
void MeshUpdateStreamWriter::WriteMeshUpdate(NiStream* stream)
{
    FUN_00c31950(stream);
    unsigned int meshCount = m_kSceneObjects.m_usSize;
    BinaryStream* binary = reinterpret_cast<BinaryStream*>(stream->GetBinaryStream());
    binary->offset += binary->WriteData(&meshCount, 4);
    for (unsigned int i = 0; i < meshCount; ++i)
        stream->SaveLinkID(reinterpret_cast<const NiObject*>(m_kSceneObjects.m_pBase[i].m_pObject));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ReferenceArray
{
    void FUN_0060bef0(unsigned int count);
    void FUN_004b0310(unsigned int index, NiRefObject** pointer);
};
struct ReferenceContainer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ReferenceArray array;
    void FUN_00c31650(NiStream* source);
    void CopyReferencesFromSource(NiStream* source);
};
// Resizes the array to the source's count, then copies each referenced object into the array while adjusting its reference count.
// @fnv 0x00c214c0
void ReferenceContainer::CopyReferencesFromSource(NiStream* source)
{
    FUN_00c31650(source);
    unsigned int count = source->GetLinkID();
    ReferenceArray* array = &this->array;
    array->FUN_0060bef0(count);
    for (unsigned int index = 0; index < count; ++index)
    {
        NiRefObject* object = source->FUN_00a63430();
        NiRefObject* handle = object;
        if (object != 0)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
        array->FUN_004b0310(index, &handle);
        if (object != 0 && InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
            object->DeleteThis();
    }
}


// Compares m_kSceneObjects with pkObject's m_kSceneObjects, returning true only if both arrays have the same size and each element is equal.
// @fnv 0x00c21230
bool NiPSysMeshUpdateModifier::IsEqual(NiObject* pkObject) const
{
    if (!NiPSysModifier::IsEqual(reinterpret_cast<NiObject*>(pkObject)))
    {
        return false;
    }

    NiPSysMeshUpdateModifier* pkDest = (NiPSysMeshUpdateModifier*)pkObject;

    if (m_kSceneObjects.GetSize() != pkDest->m_kSceneObjects.GetSize())
    {
        return false;
    }

    for (unsigned int ui = 0; ui < m_kSceneObjects.GetSize(); ui++)
    {
        NiAVObject* pkMesh = m_kSceneObjects.m_pBase[ui].m_pObject;
        NiAVObject* pkDestMesh = (ui < pkDest->m_kSceneObjects.GetSize()) ? pkDest->m_kSceneObjects.m_pBase[ui].m_pObject : 0;
        if ((pkMesh && !pkDestMesh) || (!pkMesh && pkDestMesh) ||
            (pkMesh && pkDestMesh && !pkMesh->IsEqual(pkDestMesh)))
        {
            return false;
        }
    }

    return true;
}

#include <math.h>
struct MeshNiPoint3
{
    float x;
    float y;
    float z;
};
struct MeshNiMatrix3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    void MakeAxisAngleRotation(float fAngleDifference, float x, float y, float z);
};
struct MeshUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool byte06;
    bool bUpdateGeomorphs;
    bool bUpdateShadowScene;
};
struct MeshParticleInfo
{
    int unk00;
    int unk04;
    int unk08;
    float m_fXValue;
    int unk10;
    int unk14;
    int unk18;
};
struct MeshSystem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    NiAVObject** m_ppkMeshes;
};
struct MeshPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    MeshNiPoint3* m_pkVertex;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    float* m_pfRadii;
    unsigned short m_usActiveVertices;
    unsigned short unk52;
    float* m_pfSizes;
    int unk58;
    float* m_pfRotationAngles;
    MeshNiPoint3* m_pkRotationAxes;
    int unk64;
    int unk68;
    int unk6C;
    MeshParticleInfo* m_pkParticleInfo;
    int unk74;
    int unk78;
    MeshSystem* m_pkSystem;
};

// For each active vertex, copies position and scale to its mesh, optionally sets rotation, then calls UpdateDownwardPass.
// @fnv 0x00c21080
// src: XBOX_PDB 0x00c21080
void __stdcall NiPSysMeshUpdateModifier_Update(float fTime, MeshPSysData* pkData)
{
    float* pfRotationAngles = pkData->m_pfRotationAngles;
    MeshNiPoint3* pkRotationAxes = pkData->m_pkRotationAxes;
    for (unsigned short i = 0; i < pkData->m_usActiveVertices; i++)
    {
        MeshParticleInfo* pkInfo = &pkData->m_pkParticleInfo[i];
        NiAVObject* pkMesh = pkData->m_pkSystem->m_ppkMeshes[i];
        pkMesh->m_kLocal.m_Translate = reinterpret_cast<const NiPoint3&>(pkData->m_pkVertex[i]);
        if (pfRotationAngles && pkRotationAxes)
        {
            MeshNiMatrix3 kRot;
            kRot.MakeAxisAngleRotation(pfRotationAngles[i], pkRotationAxes[i].x, pkRotationAxes[i].y,
                                       pkRotationAxes[i].z);
            pkMesh->m_kLocal.m_Rotate = reinterpret_cast<const NiMatrix3&>(kRot);
        }
        float fSize = pkData->m_pfSizes[i];
        pkMesh->m_kLocal.m_fScale = (float)fabs(fSize * pkData->m_pfRadii[i]);
        MeshUpdateData kUpdate;
        kUpdate.fTime = pkInfo->m_fXValue;
        kUpdate.m_bUpdateEnabled = true;
        kUpdate.bIsMultiThreaded = false;
        kUpdate.byte06 = false;
        kUpdate.bUpdateGeomorphs = false;
        kUpdate.bUpdateShadowScene = false;
        pkMesh->UpdateDownwardPass(reinterpret_cast<NiUpdateData&>(kUpdate), 0);
    }
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);



class Sink_c21
{
  public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s3a();
    virtual void s3b();
    virtual void s3c();
    virtual void s3d();
    virtual void Attach(unsigned int uiIndex, NiAVObject* pkMesh);
};

struct Entry_c21
{
    int m_00, m_04, m_08, m_0c, m_10, m_14;
    unsigned short m_usIndex;
    unsigned short m_1a;
};

void __cdecl StartControllersRecursive(NiAVObject* pkMesh, float fTime);

struct Lk2_c21
{
    __declspec(noalias) void GetMeshHandle(unsigned int index, CloneHandle* result);
};
class FUN_00c21400_cls
{
  public:
    int m_00, m_04, m_08, m_0c;
    char* m_10;
    int m_14, m_18;
    NiAVObject** m_1c;
    unsigned short m_20;
    unsigned short m_usElementCount;
    void AttachMesh(MeshLookup* pkLookup, unsigned short usIndex);
};

// Looks up or clones a mesh by usIndex, sets its m_uiValue1 flag, starts controllers, attaches it to the sink, and releases the reference.
// @fnv 0x00c21400
void FUN_00c21400_cls::AttachMesh(MeshLookup* pkLookup, unsigned short usIndex)
{
    unsigned short usMesh = ((Entry_c21*)pkLookup->unk70)[usIndex].m_usIndex;
    if (usMesh >= m_usElementCount)
        usMesh = m_usElementCount - 1;
    NiAVObject* pkOut = 0;
    ((Lk2_c21*)pkLookup)->GetMeshHandle(usMesh, (CloneHandle*)&pkOut);
    if (!pkOut)
    {
        NiAVObject* pkClone = m_1c[usMesh]->Clone();
        if (pkClone)
        {
            pkOut = pkClone;
            DAT_00fdf1c0((void*)&pkClone->m_uiRefCount);
        }
    }
    NiAVObject* pkMesh = pkOut;
    pkMesh->m_uFlags |= 1;
    StartControllersRecursive(pkMesh, 0.0f);
    ((Sink_c21*)pkLookup->unk7c)->Attach(usIndex, pkMesh);
    pkMesh->UpdatePropertiesDownwardPass(reinterpret_cast<NiPropertyState*>(m_10 + 0x9c));
    if (DAT_00fdf1c4((void*)&pkMesh->m_uiRefCount) == 0)
        pkMesh->DeleteThis();
}

extern "C" void _ReadWriteBarrier();

struct S_c21770_Slot
{
    NiAVObject* m_pObject;
};
struct OldSlot
{
    NiAVObject* m_pObject;
    OldSlot() : m_pObject(0)
    {}
    ~OldSlot()
    {
        NiAVObject* p = *(NiAVObject* volatile*)&m_pObject;
        if (p)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
                p->DeleteThis();
        }
    }
};
class S_c21770_Mod
{
  public:
    virtual ~S_c21770_Mod() throw();
    int unk04, unk08, unk0C, unk10, unk14;
    MyMeshPtrArray m_kSceneObjects;
    void FUN_00c31780(S_c21770_Mod* pkDest, CloningProcess& kCloning) throw();
    void SetMeshAt(unsigned int uiIndex, NiAVObject* pkMesh, OldSlot& spOld) throw();
    void CloneInto(S_c21770_Mod* pkDest, CloningProcess& kCloning);
};
// Calls FUN_00c31780 on pkDest, then clones each non-null entry of m_kSceneObjects via MakeClone and stores it in pkDest with SetMeshAt.
// @fnv 0x00c21770
void S_c21770_Mod::CloneInto(S_c21770_Mod* pkDest, CloningProcess& kCloning)
{
    FUN_00c31780(pkDest, kCloning);
    for (unsigned int ui = 0; ui < m_kSceneObjects.GetSize(); ui++)
    {
        NiAVObject* pkMesh = m_kSceneObjects.GetAt(ui).m_pObject;
        if (pkMesh)
        {
            NiAVObject* pkClone = static_cast<NiAVObject*>(pkMesh->MakeClone(kCloning));
            OldSlot spOld;
            (*(S_c21770_Mod* volatile*)&pkDest)->SetMeshAt(ui, pkClone, spOld);
        }
    }
}

struct C21550LinkBase
{
    void nullsub_3(NiStream& stream);
};

struct C21550PoolData : MeshPSysData
{
    unsigned char fillPoolsOnLoad;
    unsigned int unk84, unk88, unk8C;
    unsigned short unk90;
    unsigned short generationCount;
    void ResizeChildren(unsigned int count);
};

struct C21550ParticleSystem : MeshSystem
{
    unsigned int unkA4, unkA8, unkAC, unkB0, unkB4;
    C21550PoolData* modelData;
};

// @fnv 0x00c21550
void NiPSysMeshUpdateModifier::PostLinkObject(NiStream& stream)
{
    reinterpret_cast<C21550LinkBase*>(this)->nullsub_3(stream);
    if (stream.GetFileVersion() <= 0x0A010000)
    {
        unsigned int count = m_kSceneObjects.m_usSize;
        C21550PoolData* data = reinterpret_cast<C21550ParticleSystem*>(m_pkTarget)->modelData;
        data->ResizeChildren(count);
        return;
    }
    C21550PoolData* data = reinterpret_cast<C21550ParticleSystem*>(m_pkTarget)->modelData;
    if (data->fillPoolsOnLoad == 0)
        return;
    unsigned int index = 0;
    if (0 < data->generationCount)
    {
        do
        {
            if (index < m_kSceneObjects.m_usMaxSize)
            {
                NiAVObject* mesh = m_kSceneObjects.m_pBase[index].m_pObject;
                if (mesh != 0)
                {
                    reinterpret_cast<FUN_00c212b0_cls*>(data)->NiMeshPSysData_FillPool(index,
                                                                            reinterpret_cast<NiAVObject*>(mesh));
                }
            }
            index++;
        } while (index < data->generationCount);
    }
}

