
// src/gamebryo2.2/corelibs/nianimation/niblendinterpolator_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/niblendinterpolator.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/MemoryManager.h"
#include "niblendinterpolator_types_NiBlendInterpolator.h"
#include "niblendinterpolator_types_NiBlendInterpolator__InterpArrayItem.h"
#include "niblendinterpolator_types_NiCloningProcess.h"

extern MemoryManager g_memoryManager;

void* operator new[](size_t size)
{
    return g_memoryManager.Allocate(size);
}

struct CloneInterpItem
{
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    char unk0d, unk0e, unk0f;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;

    CloneInterpItem();
    ~CloneInterpItem();
};

struct BlendCopy : NiBlendInterpolator
{
    void NiCollisionObject_CopyMembers(NiBlendInterpolator* destination, CloningProcess* process);
    void NiBlendInterpolator_CopyMembers(NiBlendInterpolator* destination, CloningProcess* process);
};

// @fnv 0x00a37510
// src: XBOX_PDB 0x00a37510
void BlendCopy::NiBlendInterpolator_CopyMembers(NiBlendInterpolator* destination, CloningProcess* process)
{
    NiCollisionObject_CopyMembers(destination, process);
    destination->m_uiObjectFlags = m_uiObjectFlags;
    destination->m_ucArraySize = m_ucArraySize;
    destination->m_pInterpArray = (NiBlendInterpolator__InterpArrayItem*)new CloneInterpItem[m_ucArraySize];
    destination->m_fWeightThreshold = m_fWeightThreshold;

    if ((m_uiObjectFlags & 1) == 0)
    {
        for (unsigned char i = 0; i < m_ucArraySize; ++i)
        {
            CloneInterpItem& sourceItem = ((CloneInterpItem*)m_pInterpArray)[i];
            CloneInterpItem& destinationItem = ((CloneInterpItem*)destination->m_pInterpArray)[i];
            if (sourceItem.m_spControllerInterpolator)
            {
                NiInterpolator* cloned =
                    static_cast<NiInterpolator*>(sourceItem.m_spControllerInterpolator->MakeClone(*process));
                if (destinationItem.m_spControllerInterpolator != cloned)
                {
                    if (destinationItem.m_spControllerInterpolator)
                        destinationItem.m_spControllerInterpolator->DecRefCount();
                    destinationItem.m_spControllerInterpolator = cloned;
                    if (cloned)
                        cloned->IncRefCount();
                }
            }
            destinationItem.m_fWeight = sourceItem.m_fWeight;
            destinationItem.m_fNormalizedWeight = sourceItem.m_fNormalizedWeight;
            destinationItem.m_cPriority = sourceItem.m_cPriority;
            destinationItem.m_fEaseSpinner = sourceItem.m_fEaseSpinner;
            destinationItem.m_fLastEvaluationTime = sourceItem.m_fLastEvaluationTime;
        }

        destination->m_ucInterpCount = m_ucInterpCount;
        destination->m_ucSingleIdx = m_ucSingleIdx;
        destination->m_fSingleInterpolatorTime = m_fSingleInterpolatorTime;
        destination->m_cHighPriority = m_cHighPriority;
        destination->m_cNextHighPriority = m_cNextHighPriority;
    }
}

extern unsigned char DAT_011a83ff;

extern MemoryManager _g_memoryManager;

class FUN_00a370a0 : public NiBlendInterpolator__InterpArrayItem
{
  public:
    __declspec(nothrow) FUN_00a370a0();
    static void* operator new[](unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete[](void* pvMem)
    {
        _g_memoryManager.Deallocate(pvMem);
    }
};

class NiBlendInterpolatorW : public NiBlendInterpolator
{
  public:
    bool NiBlendInterpolator_ReallocateArrays();
};

// @fnv 0x00a37690
// src: XBOX_PDB 0x00a37690
bool NiBlendInterpolatorW::NiBlendInterpolator_ReallocateArrays()
{
    if (DAT_011a83ff == 0)
        return false;

    unsigned char ucNewArraySize = m_ucArraySize + DAT_011a83ff;
    if (ucNewArraySize < 4)
        ucNewArraySize = 4;

    FUN_00a370a0* pkNewInterpArray = new FUN_00a370a0[ucNewArraySize];
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        *(NiBlendInterpolator__InterpArrayItem*)&pkNewInterpArray[uc] = m_pInterpArray[uc];
    }
    delete[] (FUN_00a370a0*)m_pInterpArray;

    m_pInterpArray = pkNewInterpArray;
    m_ucArraySize = ucNewArraySize;

    return true;
}

namespace fnv_00a37980 {
struct Stream100;
extern MemoryManager DAT_011f6238;

struct FUN_00a370a0
{
    void* interpolator;
    float weight, normalizedWeight;
    char priority, unk0d, unk0e, unk0f;
    float easeSpinner, updateTime;
    __declspec(nothrow) FUN_00a370a0();
    ~FUN_00a370a0()
    {}
    static void* operator new[](unsigned int n) throw()
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
    void LoadFromStream(Stream100&);
};

typedef struct FUN_00a370a0 Item100;

struct Binary100
{
    void* vtbl;
    unsigned int pos;
    unsigned int(__cdecl* read)(Binary100*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* d, unsigned int n)
    {
        unsigned int component = n;
        pos += read(this, d, n, &component, 1);
    }
};

struct Stream100
{

    unsigned int unk000;

    unsigned int unk004;

    unsigned int unk008;

    unsigned int unk00c;

    unsigned int unk010;

    unsigned int unk014;

    unsigned int unk018;

    unsigned int unk01c;

    unsigned int unk020;

    unsigned int unk024;

    unsigned int unk028;

    unsigned int unk02c;

    unsigned int unk030;

    unsigned int unk034;

    unsigned int unk038;

    unsigned int unk03c;

    unsigned int unk040;

    unsigned int unk044;

    unsigned int unk048;

    unsigned int unk04c;

    unsigned int unk050;

    unsigned int unk054;

    unsigned int unk058;

    unsigned int unk05c;

    unsigned int unk060;

    unsigned int unk064;

    unsigned int unk068;

    unsigned int unk06c;

    unsigned int unk070;

    unsigned int unk074;

    unsigned int unk078;

    unsigned int unk07c;

    unsigned int unk080;

    unsigned int unk084;

    unsigned int unk088;

    unsigned int unk08c;

    unsigned int unk090;

    unsigned int unk094;

    unsigned int unk098;

    unsigned int unk09c;

    unsigned int unk0a0;

    unsigned int unk0a4;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    unsigned int unk0b8;

    unsigned int unk0bc;

    unsigned int unk0c0;

    unsigned int unk0c4;

    unsigned int unk0c8;

    unsigned int unk0cc;

    unsigned int unk0d0;

    unsigned int unk0d4;

    unsigned int version;

    unsigned int unk0dc;

    unsigned int unk0e0;

    unsigned int unk0e4;

    unsigned int unk0e8;

    unsigned int unk0ec;

    unsigned int unk0f0;

    unsigned int unk0f4;

    unsigned int unk0f8;

    unsigned int unk0fc;

    unsigned int unk100;

    unsigned int unk104;

    unsigned int unk108;

    unsigned int unk10c;

    unsigned int unk110;

    unsigned int unk114;

    unsigned int unk118;

    unsigned int unk11c;

    unsigned int unk120;

    unsigned int unk124;

    unsigned int unk128;

    unsigned int unk12c;

    unsigned int unk130;

    unsigned int unk134;

    unsigned int unk138;

    unsigned int unk13c;

    unsigned int unk140;

    unsigned int unk144;

    unsigned int unk148;

    unsigned int unk14c;

    unsigned int unk150;

    unsigned int unk154;

    unsigned int unk158;

    unsigned int unk15c;

    unsigned int unk160;

    unsigned int unk164;

    unsigned int unk168;

    unsigned int unk16c;

    unsigned int unk170;

    unsigned int unk174;

    unsigned int unk178;

    unsigned int unk17c;

    unsigned int unk180;

    unsigned int unk184;

    unsigned int unk188;

    unsigned int unk18c;

    unsigned int unk190;

    unsigned int unk194;

    unsigned int unk198;

    unsigned int unk19c;

    unsigned int unk1a0;

    unsigned int unk1a4;

    unsigned int unk1a8;

    unsigned int unk1ac;

    unsigned int unk1b0;

    unsigned int unk1b4;

    unsigned int unk1b8;

    unsigned int unk1bc;

    unsigned int unk1c0;

    unsigned int unk1c4;

    unsigned int unk1c8;

    unsigned int unk1cc;

    unsigned int unk1d0;

    unsigned int unk1d4;

    unsigned int unk1d8;

    unsigned int unk1dc;

    unsigned int unk1e0;

    unsigned int unk1e4;

    unsigned int unk1e8;

    unsigned int unk1ec;

    unsigned int unk1f0;

    unsigned int unk1f4;

    unsigned int unk1f8;

    unsigned int unk1fc;

    unsigned int unk200;

    unsigned int unk204;

    unsigned int unk208;

    unsigned int unk20c;

    unsigned int unk210;

    unsigned int unk214;

    unsigned int unk218;

    unsigned int unk21c;

    unsigned int unk220;

    unsigned int unk224;

    unsigned int unk228;

    unsigned int unk22c;

    unsigned int unk230;

    unsigned int unk234;

    unsigned int unk238;

    unsigned int unk23c;

    unsigned int unk240;

    unsigned int unk244;

    unsigned int unk248;

    Binary100* binary;
    void* FUN_00a64620();
};

struct Blend100
{
    int unk00, unk04, unk08;
    unsigned char flags, size, count, single;
    signed char high, next;
    short unk12;
    Item100* array;
    void* singleInterpolator;
    float weightThreshold, singleTime, highSum, nextSum, highEase;
    void BSTextureSet_LoadBinary(Stream100&);
    void NiBlendInterpolator_LoadBinary(Stream100&);
};

// @fnv 0x00a37980
// src: XBOX_PDB 0x00a37980
void Blend100::NiBlendInterpolator_LoadBinary(Stream100& stream)
{

    BSTextureSet_LoadBinary(stream);

    if (stream.version >= 0x0a010070)
    {
        stream.binary->Read(&flags, 1);
        flags &= ~4;
    }

    if (stream.version < 0x0a01006e)
    {
        unsigned short oldSize, oldCount;
        stream.binary->Read(&oldSize, 2);
        size = oldSize;
        stream.binary->Read(&oldCount, 2);
    }

    else
        stream.binary->Read(&size, 1);

    array = new Item100[size];

    if (stream.version < 0x0a010070)
    {

        for (unsigned char i = 0; i < size; ++i)
            array[i].LoadFromStream(stream);

        bool managerControlled;
        stream.binary->Read(&managerControlled, 1);
        if (managerControlled)
            flags |= 1;
        else
            flags &= ~1;

        stream.binary->Read(&weightThreshold, 4);

        bool onlyHighest;
        stream.binary->Read(&onlyHighest, 1);
        if (onlyHighest)
            flags |= 2;
        else
            flags &= ~2;

        if (stream.version < 0x0a01006e)
        {
            unsigned short oldCount, oldSingle;
            stream.binary->Read(&oldCount, 2);
            count = oldCount;
            stream.binary->Read(&oldSingle, 2);
            single = oldSingle;
        }

        else
        {
            stream.binary->Read(&count, 1);
            stream.binary->Read(&single, 1);
        }

        if (stream.version >= 0x0a01006c)
        {
            singleInterpolator = stream.FUN_00a64620();
            stream.binary->Read(&singleTime, 4);
        }

        if (stream.version < 0x0a01006e)
        {
            int oldHigh, oldNext;
            stream.binary->Read(&oldHigh, 4);
            if (oldHigh == (-2147483647 - 1))
                high = -128;
            else
                high = oldHigh;
            stream.binary->Read(&oldNext, 4);
            if (oldNext == (-2147483647 - 1))
                next = -128;
            else
                next = oldNext;
        }

        else
        {
            stream.binary->Read(&high, 1);
            stream.binary->Read(&next, 1);
        }
    }
    else
    {

        stream.binary->Read(&weightThreshold, 4);

        if (!(flags & 1))
        {
            stream.binary->Read(&count, 1);
            stream.binary->Read(&single, 1);
            stream.binary->Read(&high, 1);
            stream.binary->Read(&next, 1);
            stream.binary->Read(&singleTime, 4);
            stream.binary->Read(&highSum, 4);
            stream.binary->Read(&nextSum, 4);
            stream.binary->Read(&highEase, 4);

            for (unsigned char i = 0; i < size; ++i)
                array[i].LoadFromStream(stream);

            singleInterpolator = stream.FUN_00a64620();
        }
    }
}
}  // namespace fnv_00a37980
