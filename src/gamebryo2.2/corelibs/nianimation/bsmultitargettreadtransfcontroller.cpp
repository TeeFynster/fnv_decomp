// gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller.cpp: Holder, BSMultiTargetTreadTransfController, TreadController (20 functions)

#include "bsmultitargettreadtransfcontroller_decls.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiQuatTransform.h"
#include <string.h>
#include "../../../../include/NiInterpController.h"
// @fnv 0x00a358a0
NiInterpolator* BSMultiTargetTreadTransfController::GetInterpolator(unsigned short index) const
{
    return reinterpret_cast<NiInterpolator*>(&entries[index]);
}
// Increments DAT_011f36a0 and, when the previous value was zero, calls FUN_00aa2080 with DAT_00a2d8a0 and DAT_00a2de70.
// @fnv 0x00a2e180
GlobalObject_00a2e180::GlobalObject_00a2e180()
{
    if (DAT_011f36a0++ == 0)
        NiStaticDataManager_AddLibrary(&DAT_00a2d8a0, &DAT_00a2de70);
}

struct FUN_00a35950_shell : public BSMultiTargetTreadTransfController
{
    void* BSMultiTargetTreadTransfController_GetRTTI();
};

extern int g_011f36e4;

// @fnv 0x00a35950
// src: COMMUNITY 0x00a35950
void* FUN_00a35950_shell::BSMultiTargetTreadTransfController_GetRTTI()
{
    return &g_011f36e4;
}

struct FUN_00a35e90_shell : public BSMultiTargetTreadTransfController
{
    char* BSMultiTargetTreadTransfController_GetInterpolatorID(unsigned short);
};

// @fnv 0x00a35e90
// src: XBOX_PDB 0x00a35e90
char* FUN_00a35e90_shell::BSMultiTargetTreadTransfController_GetInterpolatorID(unsigned short ausIndex)
{
    char** arr = *(char***)((char*)this + 0x3c);
    char* p = arr[ausIndex];
    char** q = *(char***)((char*)p + 4);
    return q[2];
}

struct FUN_00a35fc0_shell
{
    void __thiscall SetSlotValue(unsigned short idx, void* val);
};

// Stores val into the slot at idx in the array at this+0x3c and, if val is non-null, sets bit 0x80 in val's field at 0x30.
// @fnv 0x00a35fc0
void __thiscall FUN_00a35fc0_shell::SetSlotValue(unsigned short usIndex, void* pValue)
{
    void* arr = *(void**)((char*)this + 0x3c);
    void* slot = *(void**)((char*)arr + usIndex * 4);
    *(void**)((char*)slot + 4) = pValue;
    if (pValue)
        *(int*)((char*)pValue + 0x30) |= 0x80;
}

struct FUN_00a35910_shell
{
    unsigned short __thiscall FindIndexByValue(unsigned short a);
};

// Scans the array at this+0x3c for an entry whose field at offset 4 equals a, returning its index or INVALID_INDEX.
// @fnv 0x00a35910
unsigned short __thiscall FUN_00a35910_shell::FindIndexByValue(unsigned short a)
{
    unsigned short i = 0;
    unsigned short n = *(unsigned short*)((char*)this + 0x40);
    if (i < n)
    {
        unsigned int* arr = *(unsigned int**)((char*)this + 0x3c);
        do
        {
            if (*(unsigned int*)(arr[i] + 4) == *(unsigned int*)&a)
                return i;
            ++i;
        } while (i < n);
    }
    return NiInterpController::INVALID_INDEX;
}

struct Inner_00a35f30
{
    char _pad[8];
    void* h;
};
struct Link_00a35f30
{
    char _pad2[4];
    Inner_00a35f30* p;
};
struct Arg_00a35f30
{
    void* h;
};
struct This_00a35f30
{
    char _pad[0x38];
    unsigned short num;
    Link_00a35f30** links;
};
struct Holder_00a35f30
{
    unsigned short FindLinkIndex(const Arg_00a35f30& arName);
};
// @fnv 0x00a35f30
unsigned short Holder_00a35f30::FindLinkIndex(const Arg_00a35f30& arName)
{
    unsigned short us;
    for (us = 0; us < ((This_00a35f30*)this)->num; ++us)
    {
        Inner_00a35f30* inner = ((This_00a35f30*)this)->links[us]->p;
        if (inner && inner->h == arName.h)
            return us;
    }
    return NiInterpController::INVALID_INDEX;
}

struct FUN_00a35f70_struct
{
    void __thiscall SetSlotEntry(unsigned short, void*, unsigned short, void*);
};
// @fnv 0x00a35f70
void __thiscall FUN_00a35f70_struct::SetSlotEntry(unsigned short usIndex, void* a2, unsigned short a3, void* a4)
{
    int iOffset = usIndex * 4;
    *(void**)(*(char**)((char*)*(char***)((char*)this + 0x3c) + iOffset) + 4) = a2;
    *(void**)(*(char**)((char*)*(char***)((char*)this + 0x3c) + iOffset) + 8) = a4;
    *(unsigned short*)*(char**)((char*)*(char***)((char*)this + 0x3c) + iOffset) = a3;
    if (a2)
        *(int*)((char*)a2 + 0x30) |= 0x80;
}

struct S_00a36050
{
    void __thiscall ProcessEntries_00a35960();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a36050
void* __thiscall S_00a36050::DestroyIfFlagged(unsigned int uiFlags)
{
    ProcessEntries_00a35960();
    if (uiFlags & 1)
        _delete(this, 0x44);
    return this;
}

struct Interp00a358b0
{
    virtual void D00() = 0;
    virtual void D01() = 0;
    virtual void D02() = 0;
    virtual void D03() = 0;
    virtual void D04() = 0;
    virtual void D05() = 0;
    virtual void D06() = 0;
    virtual void D07() = 0;
    virtual void D08() = 0;
    virtual void D09() = 0;
    virtual void D10() = 0;
    virtual void D11() = 0;
    virtual void D12() = 0;
    virtual void D13() = 0;
    virtual void D14() = 0;
    virtual void D15() = 0;
    virtual void D16() = 0;
    virtual void D17() = 0;
    virtual void D18() = 0;
    virtual void D19() = 0;
    virtual void D20() = 0;
    virtual void D21() = 0;
    virtual void D22() = 0;
    virtual void D23() = 0;
    virtual void D24() = 0;
    virtual void D25() = 0;
    virtual void D26() = 0;
    virtual void D27() = 0;
    virtual void D28() = 0;
    virtual void D29() = 0;
    virtual void D30() = 0;
    virtual void D31() = 0;
    virtual void D32() = 0;
    virtual void D33() = 0;
    virtual void D34() = 0;
    virtual void D35() = 0;
    virtual void D36() = 0;
    virtual void D37() = 0;
    virtual void D38() = 0;
    virtual void D39() = 0;
    virtual void D40() = 0;
    virtual void D41() = 0;
    virtual void D42() = 0;
    virtual void D43() = 0;
    virtual void D44() = 0;
    virtual void D45() = 0;
    virtual void D46() = 0;
    virtual void D47() = 0;
    virtual void D48() = 0;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime) = 0;
    char _pad[48];
};
struct Ctrl00a358b0
{
    char _0[52];
    Interp00a358b0* m_base;
    unsigned short m_num;
    void __thiscall BSMultiTargetTreadTransfController_GuaranteeTimeRange(float afStartTime, float afEndTime);
};
// @fnv 0x00a358b0
// src: XBOX_PDB 0x00a358b0
void __thiscall Ctrl00a358b0::BSMultiTargetTreadTransfController_GuaranteeTimeRange(float afStartTime, float afEndTime)
{
    unsigned short us = 0;
    if (us < m_num)
    {
        do
        {
            m_base[us].SetActiveTimeRange(afStartTime, afEndTime);
            ++us;
        } while (us < m_num);
    }
}

// Stand-in for NiInterpolator: the virtual used at vtable offset 0xB8 (index 46)
// takes no stack arguments (this-> in ecx only).
struct InterpStub_00a2fac0
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual bool IsCorrectType() = 0;  // +0xB8
};

// @fnv 0x00a2fac0
// src: COMMUNITY 0x00a2fac0
bool __stdcall NiMultiTargetTransformController_InterpolatorIsCorrectType(InterpStub_00a2fac0* apInterpolator, unsigned short ausIndex)
{
    return apInterpolator->IsCorrectType();
}

// FUN_00a35900 : BSMultiTargetTreadTransfController entry getter.
// Returns &m_pEntries[usIndex]; the stride is sizeof(TreadEntry) = 0x34.
struct FUN_00a35900_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    TreadEntry* m_pEntries;
    TreadEntry* BSMultiTargetTreadTransfController_GetBlendInterpolator(unsigned short usIndex, int aParam1, int aParam2, int aParam3, int aParam4);
};

// @fnv 0x00a35900
// src: XBOX_PDB 0x00a35900
TreadEntry* FUN_00a35900_cls::BSMultiTargetTreadTransfController_GetBlendInterpolator(unsigned short usIndex, int aParam1, int aParam2, int aParam3, int aParam4)
{
    return &m_pEntries[usIndex];
}

extern char DAT_01096694;
void* __cdecl Object_DispatchCommandFour(unsigned int size) throw();

void* __fastcall NiInterpController_NiInterpController(void* controller) throw();

struct TreadInterpolator : NiInterpController
{
    unsigned int unk34;
    unsigned short unk38;
    unsigned short unk3a;
    unsigned int unk3c;
    unsigned short unk40;
    unsigned short unk42;
};

struct TreadController
{
    TreadInterpolator* __thiscall CreateInterpolator(unsigned int index);
    void __thiscall BSMultiTargetTreadTransfController_CopyMembers(TreadInterpolator* interp, unsigned int index);
};

// @fnv 0x00a35a10
TreadInterpolator* TreadController::CreateInterpolator(unsigned int index)
{
    TreadInterpolator* interp;
    TreadInterpolator* storage = static_cast<TreadInterpolator*>(Object_DispatchCommandFour(sizeof(TreadInterpolator)));
    if (storage)
    {
        // The shared base has no declaration for the original constructor yet.
        NiInterpController_NiInterpController(storage);
        *reinterpret_cast<void**>(storage) = &DAT_01096694;
        storage->unk34 = 0;
        storage->unk38 = 0;
        storage->unk40 = 0;
        storage->unk3c = 0;
        interp = storage;
    }
    else
    {
        interp = 0;
    }
    BSMultiTargetTreadTransfController_CopyMembers(interp, index);
    return interp;
}

struct TreadElem_00a35b90
{
    char unk00[0x34];
    void __thiscall Dtor();
};

void __cdecl FreeArr_00a35b90(void* apMemory, unsigned int aiSize);
void __cdecl FreeObj_00a35b90(void* apMemory, unsigned int aiSize);

struct FUN_00a35b90_cls
{
    char unk00[0x34];

    void* Destroy(unsigned int acFlags);
};

// Destroys the object or, when acFlags has bit 2 set, destroys each of the count elements in the array and optionally frees the memory.
// @fnv 0x00a35b90
void* FUN_00a35b90_cls::Destroy(unsigned int acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        char* p = (char*)this + i * 0x34;
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = p - 0x34;
                ((TreadElem_00a35b90*)p)->Dtor();
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            FreeArr_00a35b90(base, 0x34);
        }
        return base;
    }

    ((TreadElem_00a35b90*)this)->Dtor();
    if (acFlags & 1)
    {
        FreeObj_00a35b90(this, 0x34);
    }
    return this;
}

struct Entry_00a35fe0
{
    unsigned short unk00;
    void* unk04;
    void* unk08;
};

struct Target_00a35fe0
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
    unsigned int unk30;
};

struct FUN_00a35fe0_shell
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
    Entry_00a35fe0** unk3C;
    unsigned short unk40;

    unsigned short __thiscall BSMultiTargetTreadTransfController_AddInterpolatorTarget(Target_00a35fe0* target, unsigned short id, void* value);
};

extern unsigned short DAT_01096320;

// Finds the first free entry slot, stores the value, id and target in it, sets bit 0x80 on the target, and returns the slot index or DAT_01096320 if none is free.
// @fnv 0x00a35fe0
// src: XBOX_PDB 0x00a35fe0
unsigned short __thiscall FUN_00a35fe0_shell::BSMultiTargetTreadTransfController_AddInterpolatorTarget(Target_00a35fe0* target, unsigned short id, void* value)
{
    for (unsigned short index = 0; index < unk40; ++index)
    {
        Entry_00a35fe0* entry = unk3C[index];

        if (entry->unk04 == 0)
        {
            unk3C[index]->unk08 = value;
            unk3C[index]->unk00 = id;
            unk3C[index]->unk04 = target;
            target->unk30 |= 0x80;
            return index;
        }
    }

    return DAT_01096320;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
inline unsigned int NiAtomicIncrement(unsigned int& v)
{
    return InterlockedIncrement((long*)&v);
}
inline unsigned int NiAtomicSubtract(unsigned int& v)
{
    return InterlockedDecrement((long*)&v);
}

class RefObj
{
  public:
    virtual ~RefObj();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrement(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!NiAtomicSubtract(m_uiRefCount))
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};

template <class T> class SmartPtr
{
  public:
    SmartPtr(T* p = 0) throw() : m_pObject(p)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SmartPtr() throw()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    SmartPtr& operator=(const SmartPtr& ptr) throw()
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

struct Entry
{
    RefObj* m_p;
    int m_04, m_08, m_0c;
    void Clear() throw();
};
struct Entry2
{
    int m_00, m_04, m_08, m_0c, m_10;
    void Clear() throw();
};
struct Holder
{
    int m_00, m_04, m_08, m_0c, m_10;
    Entry* m_14;
    Entry2* m_18;
    void AssignInterpolatorRef(unsigned int idx, SmartPtr<RefObj>& out) throw();
    void NiControllerSequence_RemoveInterpolator_0(unsigned int idx);
};

void Holder::AssignInterpolatorRef(unsigned int idx, SmartPtr<RefObj>& out) throw()
{
    SmartPtr<RefObj> sp = m_14[idx].m_p;
    m_14[idx].Clear();
    m_18[idx].Clear();
    out = sp;
}

// Clears the entry at idx by moving its RefObj into a temporary SmartPtr, which releases it when the pointer goes out of scope.
// @fnv 0x00a32b80
// src: COMMUNITY 0x00a32b80
void Holder::NiControllerSequence_RemoveInterpolator_0(unsigned int uiIndex)
{
    SmartPtr<RefObj> sp;
    AssignInterpolatorRef(uiIndex, sp);
}

struct NiStream;

extern void __cdecl LoadBinary(NiStream*);

// @fnv 0x00a35840
// src: XBOX_PDB 0x00a35840
void __cdecl BSMultiTargetTreadTransfController_LoadBinary(NiStream* stream)
{
    return LoadBinary(stream);
}

struct Vec112
{
    float x, y, z;
    Vec112()
    {}
    Vec112(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec112 operator*(const float& s) const
    {
        return Vec112(x * s, y * s, z * s);
    }
    Vec112 operator+(const Vec112& b) const
    {
        return Vec112(x + b.x, y + b.y, z + b.z);
    }
};
struct Mat112
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
extern Vec112 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;
// This unit inlines the invalid-value constructor; keep its definition here because the shared header only declares it.
inline NiQuatTransform::NiQuatTransform()
{
    *reinterpret_cast<Vec112*>(&x) = DAT_011a8400;
    memcpy(&qx, &DAT_011f3704, sizeof(DAT_011f3704));
    scale = DAT_01096b8c;
}
struct Blend112
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool Update(float, void*, NiQuatTransform&);
    int field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28, field2c;
    float weight;
};
struct Node112
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28, field2c;
    unsigned flags;
    unsigned char Active() const
    {
        return flags >> 1;
    }
    Mat112 matrix;
    Vec112 position;
};
// Two endpoint poses occupy 0x3C bytes (second translation at 0x20); include/Data.h is a 0x10-byte skill/category record.
struct TreadEndpointPoses
{
    Vec112 position0;
    NiQuaternion rotation0;
    float scale0;
    Vec112 position1;
    NiQuaternion rotation1;
};
struct Link112
{
    unsigned short index;
    Node112* node;
    TreadEndpointPoses* data;
};
struct Controller112
{
    int field00, field04;
    unsigned short flags;
    unsigned char Active() const
    {
        return flags >> 3;
    }
    unsigned short field0a;
    int field0c, field10, field14, field18, field1c, field20, field24, field28, field2c, field30;
    Blend112* blends;
    unsigned short count, field3a;
    Link112** links;
    unsigned short linkCount;
    void BSMultiTargetTreadTransfController_Update(float* time);
};

// @fnv 0x00a35c00
// src: XBOX_PDB 0x00a35c00
void Controller112::BSMultiTargetTreadTransfController_Update(float* time)
{
    if (Active() & 1)
    {
        NiQuatTransform value;
        for (int i = 0; i < count; ++i)
        {
            if (blends[i].Update(*time, 0, value))
            {
                float weight = blends[i].weight;
                for (unsigned short j = 0; j < linkCount; ++j)
                {
                    Link112* link = links[j];
                    if (i == link->index && link->node && (link->node->Active() & 1))
                    {
                        Vec112 position0 = link->data->position0;
                        Vec112 position1 = link->data->position1;
                        NiQuaternion rotation0 = link->data->rotation0;
                        Vec112 weighted = position1 * weight;
                        NiQuaternion rotation1 = links[j]->data->rotation1;
                        float complement = 1.0f - weight;
                        Vec112 position = position0 * complement + weighted;
                        // Slerp fills the quaternion without calling its default constructor.
                        float rotationStorage[4];
                        NiQuaternion& rotation = *reinterpret_cast<NiQuaternion*>(rotationStorage);
                        rotation.Slerp(1.0f - weight, rotation1, rotation0);
                        links[j]->node->position = position;
                        rotation.NiQuaternion_ToRotation(&links[j]->node->matrix);
                    }
                }
            }
        }
    }
}

extern char DAT_01096694;
extern char DAT_011f6238;
void __cdecl _NiFree_00aa10f0(void* p);

struct S00a35960_Heap
{
    void __thiscall MemoryManager_Deallocate(void* p);
};

struct S00a35960_Obj
{
    virtual void __thiscall Dtor(unsigned int flags);
};

struct S00a35960_Cls : NiInterpController
{
    S00a35960_Obj* m34;
    unsigned short m38;
    unsigned short m3a;
    void** m3c;
    unsigned short m40;
    unsigned short m42;
    void ProcessEntries_00a35960();
    void FUN_00a6d290();
};

// Sets the vtable, disposes of m34 and m3c storage, then calls FUN_00a6d290.
// @fnv 0x00a35960
// src: GUESS 0x00a35960 (confidence: low)
void S00a35960_Cls::ProcessEntries_00a35960()
{
    S00a35960_Obj* pObj = m34;
    *reinterpret_cast<void**>(this) = &DAT_01096694;
    if (pObj != 0)
    {
        int* h = (int*)pObj - 1;
        if (*h != 0)
        {
            pObj->Dtor(3);
        }
        else
        {
            ((S00a35960_Heap*)&DAT_011f6238)->MemoryManager_Deallocate(h);
        }
    }
    for (unsigned short i = 0; i < m40; i++)
    {
        ((S00a35960_Heap*)&DAT_011f6238)->MemoryManager_Deallocate(m3c[i]);
    }
    _NiFree_00aa10f0(m3c);
    FUN_00a6d290();
}

#include <string.h>
extern unsigned short DAT_01096320;

struct Interp_00a35eb0
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    const char* unk08;
};

struct Entry_00a35eb0
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    Interp_00a35eb0* unk04;
};

struct FUN_00a35eb0_shell
{
    char unk00;
    char unk01;
    char unk02;
    char unk03;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    char unk08;
    char unk09;
    char unk0A;
    char unk0B;
    char unk0C;
    char unk0D;
    char unk0E;
    char unk0F;
    char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char unk1A;
    char unk1B;
    char unk1C;
    char unk1D;
    char unk1E;
    char unk1F;
    char unk20;
    char unk21;
    char unk22;
    char unk23;
    char unk24;
    char unk25;
    char unk26;
    char unk27;
    char unk28;
    char unk29;
    char unk2A;
    char unk2B;
    char unk2C;
    char unk2D;
    char unk2E;
    char unk2F;
    char unk30;
    char unk31;
    char unk32;
    char unk33;
    char unk34;
    char unk35;
    char unk36;
    char unk37;
    char unk38;
    char unk39;
    Entry_00a35eb0** unk3C;
    unsigned short unk40;

    unsigned short __thiscall FindByName(const char* name);
};

// Searches the entry array for an interpolator whose name matches name and returns its index, or DAT_01096320 if not found.
// @fnv 0x00a35eb0
unsigned short __thiscall FUN_00a35eb0_shell::FindByName(const char* name)
{
    if (name == 0)
        return DAT_01096320;

    unsigned short count = unk40;

    for (unsigned short index = 0; index < count; ++index)
    {
        Entry_00a35eb0* entry = unk3C[index];
        Interp_00a35eb0* interpolator = entry->unk04;

        if (interpolator != 0)
        {
            if (strcmp(interpolator->unk08, name) == 0)
                return index;
        }
    }

    return DAT_01096320;
}
