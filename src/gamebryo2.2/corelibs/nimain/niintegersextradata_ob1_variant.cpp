
// src/gamebryo2.2/corelibs/nimain/niintegersextradata_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/gamebryo2.2/corelibs/nimain/niintegersextradata.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiIntegerStreamArray.h"
#include "../../../../include/NiIntegersExtraData.h"

// Default colors leave their components uninitialized.
inline NiColor::NiColor()
{}

extern NiFixedString* DAT_012031c0;
extern int g_012031c4;
struct MM
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM g_memoryManager;

struct FUN_00c54b70_cls
{
    unsigned int unk00[2];
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void AllocateStorage_00c54850(unsigned int n);
    void FUN_00c54a30(unsigned int idx, NiIntegerStreamEntry& e);
    unsigned int NiTArray_FurnitureMark_NiTNewInterface_FurnitureMark_Add(NiIntegerStreamEntry& e);
};
struct FUN_00c54cc0_cls
{
    float m_00;
    float m_04;
    float m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    bool __thiscall HasEqualFields(FUN_00c54cc0_cls* other);
};

inline void NiFixedString::operator delete(void* pvMem)
{
    g_memoryManager._DeallocateAlias(pvMem);
}

// @fnv 0x00c54760
// src: GUESS 0x00c54760 (confidence: low)
void Object_UpdateFields_00c54760()
{
    delete DAT_012031c0;
    DAT_012031c0 = 0;
}

struct ElemZ
{
    int a, b, c;
    unsigned short m_usD;
    unsigned char m_ucE;
    ElemZ()
    {
        m_usD = 0;
        m_ucE = 0;
    }
    bool HasEqualFields(const ElemZ& kOther) const;
    bool operator!=(const ElemZ& kOther) const
    {
        return !HasEqualFields(kOther);
    }
};
struct FUN_00c54a30
{
    void* m_pv0;
    ElemZ* m_pUserData;
    unsigned short m_us8;
    unsigned short m_usSize;
    unsigned short m_usUsed;
    void SetAt(unsigned int uiIndex, const ElemZ& kElem);
};
// @fnv 0x00c54a30
void FUN_00c54a30::SetAt(unsigned int uiIndex, const ElemZ& kElem)
{
    static ElemZ s_kEmpty;
    if (uiIndex >= m_usSize)
    {
        m_usSize = uiIndex + 1;
        if (kElem != s_kEmpty)
            m_usUsed++;
    }
    else if (kElem != s_kEmpty)
    {
        if (m_pUserData[uiIndex].HasEqualFields(s_kEmpty))
            m_usUsed++;
    }
    else
    {
        ElemZ* pkCur = &m_pUserData[uiIndex];
        if (*pkCur != s_kEmpty)
            m_usUsed--;
    }
    m_pUserData[uiIndex] = kElem;
}

inline const NiRTTI* NiRTTI::GetBaseRTTI() const
{
    return m_pBaseRTTI;
}

inline bool NiObject::IsKindOfType(const NiRTTI* pkRTTI) const
{
    const NiRTTI* pkTmp = GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->GetBaseRTTI();
    }
    return false;
}

// @fnv 0x00c54400
// src: XBOX_PDB 0x00c54400
NiObject* __cdecl BSFurnitureMarker_Find(NiAVObject* pkOwner)
{
    NiObject* pkResult = 0;
    if (pkOwner)
    {
        const NiFixedString& kName = *DAT_012031c0;
        NiObject* pkTarget = (NiObject*)pkOwner->FUN_00a5bdd0(kName);
        if (!pkTarget)
            pkResult = 0;
        else
            pkResult = pkTarget->IsKindOfType((const NiRTTI*)&g_012031c4) ? pkTarget : 0;
    }
    return pkResult;
}

struct NiIntegerStreamEntryData
{
    NiColor m_kFogTint;
    unsigned short m_usValue;
    unsigned char m_ucFlag;

    NiIntegerStreamEntryData(int iValue)
    {
        m_usValue = (unsigned short)iValue;
        m_ucFlag = 0;
    }

    bool operator==(const NiIntegerStreamEntryData& kOther) const
    {
        return ((FUN_00c54cc0_cls*)this)->HasEqualFields((FUN_00c54cc0_cls*)&kOther);
    }
    bool operator!=(const NiIntegerStreamEntryData& kOther) const
    {
        return !(*this == kOther);
    }
    bool IsLess(const NiIntegerStreamEntryData& kOther) const
    {
        return m_ucFlag < kOther.m_ucFlag;
    }
};

class NiIntegerStreamEntryArray
{
  public:
    void* m_pvVtbl;
    NiIntegerStreamEntryData* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned int GetEffectiveSize() const
    {
        return m_usESize;
    }
    NiIntegerStreamEntryData& GetAt(unsigned int uiIndex)
    {
        return m_pBase[uiIndex];
    }
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const NiIntegerStreamEntryData& element)
    {
        static NiIntegerStreamEntryData s_kZero(0);
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != s_kZero)
                m_usESize++;
        }
        else
        {
            if (element != s_kZero)
            {
                if (m_pBase[uiIndex] == s_kZero)
                    m_usESize++;
            }
            else
            {
                NiIntegerStreamEntryData& kOld = m_pBase[uiIndex];
                if (kOld != s_kZero)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int Add(const NiIntegerStreamEntryData& element);
};

class NiIntegerStreamExtraData : public NiExtraData
{
  public:
    NiIntegerStreamEntryArray m_kEntries;
    void BSFurnitureMarker_Add(const NiIntegerStreamEntryData& kEntry);
};

// @fnv 0x00c54490
// src: COMMUNITY 0x00c54490
void NiIntegerStreamExtraData::BSFurnitureMarker_Add(const NiIntegerStreamEntryData& kEntry)
{
    unsigned int uiSize = m_kEntries.GetEffectiveSize();
    unsigned int i;
    for (i = 0; i < uiSize; i++)
    {
        NiIntegerStreamEntryData& kElem = m_kEntries.GetAt(i);
        if (kEntry.IsLess(kElem))
            break;
    }

    m_kEntries.Add(kEntry);

    if (i < uiSize)
    {
        while (uiSize > i)
        {
            m_kEntries.SetAt(uiSize, m_kEntries.GetAt(uiSize - 1));
            uiSize--;
        }
        m_kEntries.SetAt(i, kEntry);
    }
}

struct StreamHeap
{
    void* Alloc(unsigned int size);
};
extern StreamHeap DAT_011f6238;

inline void* operator new[](unsigned int size)
{
    return DAT_011f6238.Alloc(size);
}

struct StreamEntry
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned short m_0c;
    unsigned char m_0e;
    unsigned char m_0f;
    StreamEntry()
    {
        m_0c = 0;
        m_0e = 0xff;
    }
};

// @fnv 0x00c54bc0
// src: GUESS 0x00c54bc0 (confidence: low)
void* Object_GetIndexedValue_00c54bc0(unsigned int count)
{
    return new StreamEntry[count];
}

struct ExtraDataBase
{
    ExtraDataBase();
    virtual ~ExtraDataBase();

    unsigned int m_04;
    unsigned int m_08;
};

struct MemoryManagerShell
{
    void* Allocate(unsigned int size);
};
extern MemoryManagerShell g_memoryManagerShell;

struct IntegerEntry
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned short m_0c;
    unsigned char m_0e;

    IntegerEntry()
    {
        m_0c = 0;
        m_0e = 0xff;
    }
    static void* operator new[](unsigned int size)
    {
        return g_memoryManagerShell.Allocate(size);
    }
};

struct IntegerStreamArrayBase
{
    IntegerStreamArrayBase(unsigned short maxSize, unsigned short growBy)
    {
        m_usMaxSize = maxSize;
        m_usGrowBy = growBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~IntegerStreamArrayBase();

    static IntegerEntry* Allocate(unsigned int n)
    {
        return new IntegerEntry[n];
    }

    IntegerEntry* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

struct IntegerStreamArray : IntegerStreamArrayBase
{
    IntegerStreamArray() : IntegerStreamArrayBase(0, 1)
    {}
    virtual ~IntegerStreamArray();
};

struct IntegersExtraData : ExtraDataBase
{
    IntegerStreamArray m_entries;

    IntegersExtraData();
    virtual ~IntegersExtraData();
    void BSFurnitureMarker_SetName();
};

// @fnv 0x00c53f10
IntegersExtraData::IntegersExtraData()
{
    BSFurnitureMarker_SetName();
}


__forceinline void* NiFixedString::operator new(size_t size)
{
    return DAT_011f6238.Alloc(size);
}


namespace fnv_00c546c0 {
// @fnv 0x00c546c0
// src: COMMUNITY 0x00c546c0
void __cdecl BSFurnitureMarker_InitSDM()
{
    DAT_012031c0 = new NiFixedString((const char*)"FRN");
}
}  // namespace fnv_00c546c0

struct NiIntStreamMemoryC
{
    void* __thiscall Allocate(unsigned int stSize);
};
struct NiIntStreamEntryC
{
    NiColor m_kFogTint;
    unsigned short m_usValue;
    unsigned char m_ucFlag;

    NiIntStreamEntryC()
    {
        m_usValue = 0;
        m_ucFlag = 0xff;
    }
    NiIntStreamEntryC(int iValue)
    {
        m_usValue = (unsigned short)iValue;
        m_ucFlag = 0;
    }

    bool operator!=(NiIntStreamEntryC& kOther)
    {
        return !((FUN_00c54cc0_cls*)this)->HasEqualFields((FUN_00c54cc0_cls*)&kOther);
    }
    static void* operator new[](unsigned int stSize)
    {
        return ((NiIntStreamMemoryC*)&g_memoryManager)->Allocate(stSize);
    }
    static void operator delete[](void* pvMem)
    {
        g_memoryManager._DeallocateAlias(pvMem);
    }
};
struct NiIntStreamAllocatorC
{
    static NiIntStreamEntryC* Allocate(unsigned int auiCount)
    {
        return new NiIntStreamEntryC[auiCount];
    }
    static void Deallocate(NiIntStreamEntryC* pArray)
    {
        delete[] pArray;
    }
};

// @fnv 0x00c54850
// src: GUESS 0x00c54850 (confidence: low)
void FUN_00c54b70_cls::AllocateStorage_00c54850(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_08)
        return;

    unsigned short i;
    if (uiMaxSize < m_0a)
    {
        for (i = (unsigned short)uiMaxSize; i < m_0a; i++)
        {
            if (((NiIntStreamEntryC*)unk00[1])[i] != NiIntStreamEntryC(0))
            {
                ((NiIntStreamEntryC*)unk00[1])[i] = NiIntStreamEntryC(0);
                unk0c--;
            }
        }
        m_0a = (unsigned short)uiMaxSize;
    }

    NiIntStreamEntryC* pSaveBase = (NiIntStreamEntryC*)unk00[1];
    m_08 = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        unk00[1] = (unsigned int)NiIntStreamAllocatorC::Allocate(m_08);

        for (i = 0; i < m_0a; i++)
            ((NiIntStreamEntryC*)unk00[1])[i] = pSaveBase[i];

        for (i = m_0a; i < m_08; i++)
            ((NiIntStreamEntryC*)unk00[1])[i] = NiIntStreamEntryC(0);
    }
    else
    {
        unk00[1] = 0;
    }

    NiIntStreamAllocatorC::Deallocate(pSaveBase);
}
