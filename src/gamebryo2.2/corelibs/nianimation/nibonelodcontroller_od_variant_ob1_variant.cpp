#include "../../../../include/NiMemObject.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBSBoneLODController.h"
#include "../../../../include/NiControllerManager.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller_od_variant_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_0109a2a4;
struct FUN_00a543f0_shell
{
    void* m_kPointA;
    void* m_ptr;
    void ReleaseStorage_00a543f0();
};
struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f405c;
GlobalObjectO2_00a7b610* __cdecl NiBoneLODController_GetRTTI();
struct Unknown_00c536a0
{
    bool NiTimeController_RegisterStreamables(int);
    bool NiBSBoneLODController_RegisterStreamables(int);
};
extern GlobalObjectO2_00a7b610 g_012031b8;
struct FUN_00c53e00_shell
{
    GlobalObjectO2_00a7b610* __thiscall NiBSBoneLODController_GetRTTI();
};
class CloningProcess
{
};
class CloneableObj
{
  public:
    char _pad[0x34];
    int m34;
    int m38;
    void FUN_00a6cfe0(NiBSBoneLODController*, CloningProcess*);
    void NiBSBoneLODController_CopyMembers(NiBSBoneLODController*, CloningProcess*);
};
void operator delete(void*, unsigned int);
struct S_00c53e10
{
    void FUN_00c53e40();
    void* FUN_00c53e10(unsigned int);
};
struct Inner_00c53ed0
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int F3();
};
struct S_00c53ed0
{
    char _pad[0x2C];
    Inner_00c53ed0* m_ptr;
    bool NiBSBoneLODController_TargetIsRequiredType();
};
extern "C" void __cdecl CallAnimCallback(void*, const void*);
extern "C" void __cdecl NiStreamSaveBinary_unsigned_int(void*, const void*);
struct ObjectWriter
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void WriteObjectWithClass(void*);
};
struct BoneEntryGroup
{
    void** objects;
    int unk04;
    unsigned int count;
};
struct BoneLODControllerSave : NiBSBoneLODController
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void* m_34field;
    void* m_38field;
    int unk3c;
    BoneEntryGroup** groupArray;
    unsigned short unk44;
    unsigned short groupCount;
    void __thiscall FUN_00a6d730(NiStream*);
    void __thiscall NiBSBoneLODController_SaveBinary(NiStream*);
};
struct RefList
{
    unsigned int* elements;
    unsigned int unk04;
    unsigned int count;
};
struct BinaryStream
{
    unsigned int FUN_00a63430();
};
struct ControllerObject
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
    RefList** lists;
    unsigned short unk44;
    unsigned short listCount;
    void FUN_00a6d500(BinaryStream*);
    void NiBSBoneLODController_LinkObject(BinaryStream*);
};
struct S_00c53cf0_Arr
{
    void** unk00;
    int unk04;
    unsigned int unk08;
};
struct S_00c53cf0_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00c53cf0_Arr** unk40;
    short unk44;
    unsigned short unk46;
    bool ProcessEntries_00c53cf0();
};

class FUN_00a6d220
{
  public:
    FUN_00a6d220();
    virtual ~FUN_00a6d220();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
};

class FUN_00a54190
{
  public:
    FUN_00a54190(unsigned int uiMaxSize, unsigned int uiGrowBy);
    virtual ~FUN_00a54190();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class PrimitiveArray475 : public FUN_00a54190
{
  public:
    __forceinline PrimitiveArray475() : FUN_00a54190(0, 1)
    {
        int q;
    }
    virtual ~PrimitiveArray475();
};

class FUN_00c53d70 : public FUN_00a6d220
{
  public:
    FUN_00c53d70();
    virtual ~FUN_00c53d70();
    int m_iIndex;
    int m_iArrayLength;
    PrimitiveArray475 m_kArray;
};

// @fnv 0x00c53d70
FUN_00c53d70::FUN_00c53d70() : m_iIndex(-1), m_iArrayLength(0)
{}

struct ControllerBase
{
    virtual void vf();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    ~ControllerBase();
};

struct GroupArray
{
    virtual void vf();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usGrowBy;
    ~GroupArray()
    {
        void* data = m_pBase;
        _NiFreeAlias(data);
    }
};

class FUN_00c53e40 : public ControllerBase
{
  public:
    int unk34;
    int unk38;
    GroupArray m_groups;
    void ClearGroups();
    ~FUN_00c53e40();
};

// @fnv 0x00c53e40
FUN_00c53e40::~FUN_00c53e40()
{
    ClearGroups();
}

extern MemoryManager DAT_011f6238;
void* _NiMalloc_00aa1070(unsigned int n);
struct ArrW
{
    void** m_pBase;
    unsigned int m_uiMax;
    unsigned int m_uiSize;
    static void* operator new(unsigned int n)
    {
        int aiD[2];
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
    ArrW(unsigned int uiMax = 0)
    {
        if (uiMax > 0)
            m_pBase = (void**)_NiMalloc_00aa1070(sizeof(void*) * uiMax);
        else
            m_pBase = 0;
        m_uiMax = 0;
        m_uiSize = 0;
    }
    unsigned int GetSize()
    {
        unsigned int n = m_uiSize;
        int aiD[14];
        return n;
    }
    void AppendLinkID(void* const& p);
};
struct TArrW
{
    void* m0;
    void* m4;
    unsigned short m_us8;
    unsigned short m_usA;
    unsigned short m_usC;
    unsigned short m_usGrow;
    void FUN_00a90180(unsigned int n);
    void FUN_00ba3aa0(unsigned int i, ArrW* const& p);
    void SetAtGrow(unsigned int i, ArrW* const& p)
    {
        if (i >= m_us8)
            FUN_00a90180(i + m_usGrow);
        FUN_00ba3aa0(i, p);
    }
};
struct TargetW
{
    char pad[0x34];
    int m_i34;
    char pad2[0x3c - 0x38];
    TArrW m_kArr;
    void NiBSBoneLODController_SetBoneLOD(int i);
};
struct ObjW;
struct MapW
{
    bool FUN_00a53c30(void* k, void* pv);
};
struct StreamW
{
    MapW* m_pTaskMap;
};
class SelfW
{
  public:
    char pad[0x40];
    ArrW** m_ppkArr;
    unsigned short m44;
    unsigned short m_usElementCount;
    void FUN_00a6d0c0(StreamW* p);
    void NiBSBoneLODController_ProcessClone(StreamW* pkStream);
};
// @fnv 0x00c53430
// src: XBOX_PDB 0x00c53430
void SelfW::NiBSBoneLODController_ProcessClone(StreamW* pkStream)
{
    int iSaved;
    {
        unsigned int i;
        FUN_00a6d0c0(pkStream);
        {
            TargetW* pkTarget = 0;
            pkStream->m_pTaskMap->FUN_00a53c30(this, &pkTarget);
            for (i = 0; i < m_usElementCount; i++)
            {
                ArrW* pkSrc = m_ppkArr[i];
                if (pkSrc)
                {
                    ArrW* pkNew = new ArrW;
                    pkTarget->m_kArr.SetAtGrow(i, pkNew);
                    for (unsigned int j = 0; j < pkSrc->GetSize(); j++)
                    {
                        void* pkObj = pkSrc->m_pBase[j];
                        if (pkObj)
                        {
                            void* pkLinked = 0;
                            bool bFound = pkStream->m_pTaskMap->FUN_00a53c30(pkObj, &pkLinked);
                            if (bFound)
                                pkNew->AppendLinkID(pkLinked);
                            else
                                pkNew->AppendLinkID(0);
                        }
                        else
                        {
                            pkNew->AppendLinkID(0);
                        }
                    }
                }
                else
                {
                    pkTarget->m_kArr.SetAtGrow(i, 0);
                }
            }
            iSaved = pkTarget->m_i34;
            pkTarget->m_i34 = -1;
            pkTarget->NiBSBoneLODController_SetBoneLOD(iSaved);
        }
    }
}

struct ObjX
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22();
    virtual bool IsEqual(ObjX* pkObj);
};
struct ListX
{
    ObjX** m_pBase;
    unsigned int m_uiMax;
    unsigned int m_uiSize;
    unsigned int GetSize() const
    {
        unsigned int n = m_uiSize;
        return n;
    }
    ObjX*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct FUN_00c53af0
{
    char pad[0x34];
    int m_i34;
    int m_i38;
    char pad3c[4];
    ListX** m_ppkLists;
    char pad44[2];
    unsigned short m_usElementCount;
    unsigned int GetCount() const
    {
        unsigned int n = m_usElementCount;
        return n;
    }
    bool NiTimeController_IsEqual(FUN_00c53af0* pkObj);
    bool IsEqual(FUN_00c53af0* pkObj);
};
// @fnv 0x00c53af0
bool FUN_00c53af0::IsEqual(FUN_00c53af0* pkObj)
{
    unsigned int i;
    if (!NiTimeController_IsEqual(pkObj))
        return false;
    FUN_00c53af0* pkOther = pkObj;
    if (m_i34 != pkOther->m_i34 || m_i38 != pkOther->m_i38 || GetCount() != pkOther->m_usElementCount)
        return false;
    for (i = 0; i < m_usElementCount; i++)
    {
        ListX* pkA = m_ppkLists[i];
        ListX* pkB_fuj = pkOther->m_ppkLists[i];
        if ((pkA && !pkB_fuj) || (!pkA && pkB_fuj))
            return false;
        if (pkA && pkB_fuj)
        {
            if (pkA->GetSize() != pkB_fuj->GetSize())
                return false;
            for (unsigned int j = 0; j < pkA->GetSize(); j++)
            {
                if (!pkA->GetAt(j)->IsEqual(pkB_fuj->GetAt(j)))
                    return false;
            }
        }
    }
    return true;
}

void* __cdecl NiMalloc(unsigned int uiSize);
void __cdecl NiFree(void* pvMem);

extern MemoryManager g_kMemoryManager;


template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct LinkIDSet
{
    void NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int uiNewSize);
    unsigned int Add(const unsigned int& uiElement)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(m_uiElementCount > 0 ? (2 * m_uiElementCount) : 1);
        m_pBase[m_uiAllocatedCapacity] = uiElement;
        return m_uiAllocatedCapacity++;
    }

    unsigned int* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

struct NiStreamLoader
{
    void ResetStreamState()
    {
        unsigned int uiLinkID;
        NiBinaryStreamLoad(*m_pUnderlyingStream, &uiLinkID, 1);
        m_kSecondFollowingStreamField.Add(uiLinkID);
    }

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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_pUnderlyingStream;
    int m_iUnk250;
    LinkIDSet m_kSecondFollowingStreamField;
};

void __cdecl NiStreamLoadBinary_float(NiStreamLoader* pkStream, void* pvValue);

class BoneLODController;

#include "../../../../include/NiMemObject.h"

class BoneLODControllerArray : public NiMemObject
{
  public:
    // 0x00c53870 allocates the set with an inline call to the memory manager (0x00aa3e40), not through
    // NiMemObject::operator new (0x00aa13e0), so the class keeps its own inline allocator.
    static void* operator new(unsigned int uiSize)
    {
        return g_kMemoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager.Deallocate(pvMem);
    }
    BoneLODControllerArray(unsigned int uiInitialSize = 0)
    {
        if (uiInitialSize > 0)
            m_pBase = (BoneLODController**)NiMalloc(uiInitialSize * sizeof(BoneLODController*));
        else
            m_pBase = 0;
        m_uiElementCount = uiInitialSize;
        m_uiAllocatedCapacity = 0;
    }
    void AppendLinkID(BoneLODController* const& pkElement);

    BoneLODController** m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

class BoneSetArray
{
  public:
    void FUN_00a90180(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;

        unsigned int i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }

        BoneLODControllerArray** pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = (BoneLODControllerArray**)NiMalloc(m_usMaxSize * sizeof(BoneLODControllerArray*));
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        NiFree(pSaveBase);
    }
    void FUN_00ba3aa0(unsigned int uiIndex, BoneLODControllerArray* const& pkElement)
    {
        if (uiIndex >= m_usMaxSize)
            return;
        BoneLODControllerArray* pkOld = m_pBase[uiIndex];
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (pkElement != 0)
                m_usESize++;
        }
        else
        {
            if (pkElement != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = pkElement;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, BoneLODControllerArray* const& pkElement)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00a90180(uiIndex + m_usGrowBy);
        FUN_00ba3aa0(uiIndex, pkElement);
        return uiIndex;
    }

    void* m_pvVtbl;
    BoneLODControllerArray** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class TimeController
{
  public:
    void FUN_00a6d5e0(NiStreamLoader& kStream);
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
};

class BoneLODController : public TimeController
{
  public:
    void NiBSBoneLODController_LoadBinary(NiStreamLoader& kStream);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    BoneSetArray m_kBoneSetArray;
};

// @fnv 0x00c53870
// src: XBOX_PDB 0x00c53870
void BoneLODController::NiBSBoneLODController_LoadBinary(NiStreamLoader& kStream)
{
    TimeController::FUN_00a6d5e0(kStream);

    NiStreamLoadBinary_float(&kStream, &m_iLOD);
    NiStreamLoadBinary_float(&kStream, &m_uiNumLODs);

    unsigned int i;
    unsigned int uiNumLODs5 = 0;
    NiStreamLoadBinary_float(&kStream, &uiNumLODs5);

    for (i = 0; i < uiNumLODs5; i++)
    {
        BoneLODControllerArray* pkSet = new BoneLODControllerArray;
        m_kBoneSetArray.SetAtGrow(i, pkSet);

        unsigned int uiNumBones4 = 0;
        NiStreamLoadBinary_float(&kStream, &uiNumBones4);
        for (unsigned int j = 0; j < uiNumBones4; j++)
        {
            pkSet->AppendLinkID(this);
            kStream.ResetStreamState();
        }
    }
}

namespace fnv_00c53360 {
struct Allocator_c53360
{
    virtual void slot0();
    virtual void* Allocate(unsigned int& size, unsigned int& alignment, int eventType, bool accurate, const char* file,
                           int line, const char* function);
};
struct Manager_c53360
{
    Allocator_c53360* allocator;
};
extern Manager_c53360* DAT_011f6080;
class FUN_00c53d70 : public NiBSBoneLODController
{
  public:
    // NiMemObject::operator new (0x00aa13e0) as an inline-declared body: 0x00c53360 calls it out of line but its
    // frame keeps the slots of the inline candidate's two locals.
    static void* operator new(unsigned int size)
    {
        unsigned int requested = size ? size : 1;
        unsigned int alignment = 4;
        return DAT_011f6080->allocator->Allocate(requested, alignment, 1, true, 0, -1, 0);
    }
    FUN_00c53d70();
};
class CloneOwner_c53360 : public CloneableObj
{
  public:
    NiBSBoneLODController* NiBSBoneLODController_CreateClone(CloningProcess* process);
};
// @fnv 0x00c53360
// src: XBOX_PDB 0x00c53360
NiBSBoneLODController* CloneOwner_c53360::NiBSBoneLODController_CreateClone(CloningProcess* process)
{
    NiBSBoneLODController* result = new FUN_00c53d70;
    this->NiBSBoneLODController_CopyMembers(result, process);
    return result;
}
}  // namespace fnv_00c53360

namespace fnv_00c537f0 {
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00c53d70
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
    static void* operator new(unsigned int size)
    {
        int unused[2];
        (void)unused;
        return Object_DispatchCommandFour(size);
    }
    FUN_00c53d70();
};
// @fnv 0x00c537f0
// src: EXE 0x00c537f0
FUN_00c53d70* __cdecl NiBSBoneLODController_CreateObject()
{
    return new FUN_00c53d70;
}
}  // namespace fnv_00c537f0
