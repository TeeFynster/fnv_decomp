// gamebryo2.2/corelibs/nianimation/nisequence.cpp: AHSeqOwner (5 functions)

#include <windows.h>
// src/gamebryo2.2/corelibs/nianimation/nisequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nisequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f48;

// @fnv 0x00a47a10
// src: COMMUNITY 0x00a47a10
void* __cdecl NiSequence_GetRTTI()
{
    return &g_011f3f48;
}

struct S
{
    void __thiscall FUN_00a478f0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a478f0, then if bit 0 of flag is set deletes this with size 0x34, and returns this.
// @fnv 0x00a47cc0
void* __thiscall S::DestroyIfFlagged(unsigned int uiFlags)
{
    FUN_00a478f0();
    if (uiFlags & 1)
        _delete(this, 0x34);
    return this;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct S_00a47ae0_Rc
{
    virtual void vf0();
    virtual void vf1();
    volatile long m_ref;
};
struct S_00a47ae0_Ptr
{
    S_00a47ae0_Rc* p;
    S_00a47ae0_Ptr(S_00a47ae0_Rc* q) throw() : p(q)
    {
        if (p)
            InterlockedIncrement(&p->m_ref);
    }
    ~S_00a47ae0_Ptr() throw()
    {
        if (p && !InterlockedDecrement(&p->m_ref))
            p->vf1();
    }
    S_00a47ae0_Ptr& operator=(S_00a47ae0_Rc* q) throw()
    {
        S_00a47ae0_Rc* old = p;
        if (old != q)
        {
            if (old && !InterlockedDecrement(&old->m_ref))
                old->vf1();
            p = q;
            if (q)
                InterlockedIncrement(&q->m_ref);
        }
        return *this;
    }
};
struct S_00a47ae0_Src
{
    S_00a47ae0_Rc* FUN_00a63430() throw();
};
struct S_00a47ae0_Arr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00a47770(unsigned int n) throw();
    void SetItem(unsigned int i, S_00a47ae0_Rc* const* p) throw();
};
struct S_00a47ae0_Base
{
    void nullsub_3(S_00a47ae0_Src* s) throw();
};
struct S_00a47ae0_Obj : S_00a47ae0_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    short unk14;
    unsigned short count;
    int unk18;
    S_00a47ae0_Arr arr;
    S_00a47ae0_Ptr ptr;
    void CopyFromSource(S_00a47ae0_Src* src) throw();
};
// @fnv 0x00a47ae0
void S_00a47ae0_Obj::CopyFromSource(S_00a47ae0_Src* pSource) throw()
{
    nullsub_3(pSource);
    ptr = pSource->FUN_00a63430();
    unsigned int n = count;
    arr.FUN_00a47770(n);
    for (unsigned int i = 0; i < n; i++)
    {
        S_00a47ae0_Rc* pObject = pSource->FUN_00a63430();
        S_00a47ae0_Rc* slot = pObject;
        if (pObject)
            InterlockedIncrement(&pObject->m_ref);
        arr.SetItem(i, &slot);
        if (pObject && !InterlockedDecrement(&pObject->m_ref))
            pObject->vf1();
    }
}

extern "C" unsigned int DAT_011f3f44;
extern "C" void* DAT_011f3f40;

void __cdecl FUN_00ec658f(void(__cdecl* apFunc)());
void __cdecl FUN_00fdae10();

struct RefObject
{
    virtual void v00();
    virtual void Destroy();
    LONG m_lRefCount;
};

struct FUN_00a47470_cls
{
    int unk00;
    RefObject** m_ppItems;
    unsigned short unk08;
    unsigned short m_uCount;
    unsigned short m_uSentinelCount;

    void SetItem(unsigned int aiIndex, RefObject** appValue);
};

// Sets the RefObject at aiIndex in m_ppItems, adjusting m_uCount and m_uSentinelCount, and ref-counts the old and new values.
// @fnv 0x00a47470
void FUN_00a47470_cls::SetItem(unsigned int aiIndex, RefObject** appValue)
{
    if ((DAT_011f3f44 & 1) == 0)
    {
        DAT_011f3f44 |= 1;
        DAT_011f3f40 = 0;
        FUN_00ec658f(FUN_00fdae10);
    }

    if (aiIndex >= m_uCount)
    {
        m_uCount = (unsigned short)(aiIndex + 1);
        if (*appValue != (RefObject*)DAT_011f3f40)
        {
            m_uSentinelCount++;
        }
    }
    else
    {
        if (*appValue != (RefObject*)DAT_011f3f40)
        {
            if (m_ppItems[aiIndex] == (RefObject*)DAT_011f3f40)
            {
                m_uSentinelCount++;
            }
        }
        else
        {
            if (m_ppItems[aiIndex] != (RefObject*)DAT_011f3f40)
            {
                m_uSentinelCount--;
            }
        }
    }

    RefObject* pOld = m_ppItems[aiIndex];
    RefObject** ppSlot = &m_ppItems[aiIndex];
    if (pOld != *appValue)
    {
        if (pOld != 0)
        {
            if (InterlockedDecrement(&pOld->m_lRefCount) == 0)
            {
                pOld->Destroy();
            }
        }
        RefObject* pNew = *appValue;
        *ppSlot = pNew;
        if (pNew != 0)
        {
            InterlockedIncrement(&pNew->m_lRefCount);
        }
    }
}

void* __cdecl _NiMalloc_00aa1070(unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

struct AHNameArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int uiMaxSize) throw();
    __declspec(noinline) void FUN_0096ae90(unsigned int uiIndex, char* const& element) throw()
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, char* const& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        FUN_0096ae90(uiIndex, element);
        return uiIndex;
    }
};

struct AHSeqArray
{
    void* m_vtbl;
    S_00a47ae0_Ptr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_00a47770(unsigned int uiMaxSize) throw();
    __declspec(noinline) void SetItem(unsigned int uiIndex, const S_00a47ae0_Ptr& element) throw()
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element.p)
                m_usESize++;
        }
        m_pBase[uiIndex] = element.p;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const S_00a47ae0_Ptr& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00a47770(uiIndex + m_usGrowBy);
        SetItem(uiIndex, element);
        return uiIndex;
    }
};

struct AHSeqOwner
{
    int unk00;
    int unk04;
    int unk08;
    AHNameArray m_kNames;
    AHSeqArray m_kSeqs;
    unsigned int AddSeq(const char* pcName, S_00a47ae0_Rc* pkSeq);
};

// Copies pcName into m_kNames, stores pkSeq at the same index in m_kSeqs, and returns that index.
// @fnv 0x00a47a20
unsigned int AHSeqOwner::AddSeq(const char* pcName, S_00a47ae0_Rc* pkSeq)
{
    unsigned int uiIndex = m_kNames.GetSize();
    unsigned int uiLen = strlen(pcName) + 1;
    char* pcCopy = (char*)_NiMalloc_00aa1070(uiLen);
    strcpy_s(pcCopy, uiLen, pcName);
    m_kNames.SetAtGrow(uiIndex, (char*)pcCopy);
    m_kSeqs.SetAtGrow(uiIndex, pkSeq);
    return uiIndex;
}
