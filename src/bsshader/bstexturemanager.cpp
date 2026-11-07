#include "../../include/NiTListItem.h"
class NiParticles;
#include "../../include/NiTArray.h"
// bsshader/bstexturemanager.cpp: free functions (3 functions)

#include "NiObject.h"
#include "../../include/MapEntryCount.h"
// WaterTintRecord_bstexturemanager: local type (was include/WaterTintRecord.h, which had no evidence of one real class); no method of it is bound to a named game function
struct WaterTintRecord_bstexturemanager
{
    float r;
    float g;
    float b;
    float a;

    WaterTintRecord_bstexturemanager(float fR, float fG, float fB, float fA)
        : r(fR), g(fG), b(fB), a(fA)
    {}
};

extern WaterTintRecord_bstexturemanager g_waterTintRecords[];

// Stores the given tint record into the global water tint record array at the specified index.
// @fnv 0x004e20c0
void SetWaterTintRecord(int index, WaterTintRecord_bstexturemanager tint)
{
    g_waterTintRecords[index] = tint;
}

// FUN_004a0dd0: thiscall, one stack arg; calls a flag lookup, then virtual slot 100 with the arg.
class FUN_004a0dd0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    virtual void vfn_78();
    virtual void vfn_79();
    virtual void vfn_80();
    virtual void vfn_81();
    virtual void vfn_82();
    virtual void vfn_83();
    virtual void vfn_84();
    virtual void vfn_85();
    virtual void vfn_86();
    virtual void vfn_87();
    virtual void vfn_88();
    virtual void vfn_89();
    virtual void vfn_90();
    virtual void vfn_91();
    virtual void vfn_92();
    virtual void vfn_93();
    virtual void vfn_94();
    virtual void vfn_95();
    virtual void vfn_96();
    virtual void vfn_97();
    virtual void vfn_98();
    virtual void vfn_99();
    virtual void vfn_100(int a);
    bool LookupFlag(const char* name, int flag);
    void NiRenderer_SetScreenSpaceCameraData(int a1);
};

// If the "SetScreenSpaceCameraData" flag is set, forwards a1 to vfn_100; otherwise does nothing.
// @fnv 0x004a0dd0
// src: COMMUNITY 0x004a0dd0
void FUN_004a0dd0_cls::NiRenderer_SetScreenSpaceCameraData(int a1)
{
    if (LookupFlag("SetScreenSpaceCameraData", 1) == 0)
    {
    }
    else
    {
        vfn_100(a1);
    }
}

void NiFree(void* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

template <class T> struct StubMallocIf
{
    static void Deallocate(T* p)
    {
        NiFree(p);
    }
};

inline unsigned int StubAtomicInc(unsigned int& value)
{
    return InterlockedIncrement(reinterpret_cast<volatile long*>(&value));
}
inline unsigned int StubAtomicDec(unsigned int& value)
{
    return InterlockedDecrement(reinterpret_cast<volatile long*>(&value));
}

class StubRefObj
{
  public:
    unsigned int m_uiRefCount;
    virtual ~StubRefObj();
    virtual void DeleteThis();
    void IncRefCount()
    {
        StubAtomicInc(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (StubAtomicDec(m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class StubPtr
{
  public:
    T* m_pObject;
    StubPtr<T>& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

unsigned int StubGetThreadId();
int StubCmpXchg(volatile long* dst, long xchg, long cmp);
void StubSleep(unsigned long ms);

class StubCritSec
{
  public:
    unsigned int m_uiOwningThread;
    unsigned int m_uiLockCount;
    void Lock(const char* name)
    {
        unsigned int uiThreadID = StubGetThreadId();
        if (m_uiOwningThread == uiThreadID)
        {
            m_uiLockCount++;
        }
        else
        {
            unsigned int uiSpin = 0;
            while (StubCmpXchg((volatile long*)&m_uiOwningThread, uiThreadID, 0))
            {
                if (++uiSpin > 10000)
                    StubSleep(1);
                else
                    StubSleep(0);
            }
            m_uiLockCount = 1;
        }
    }
    void Unlock()
    {
        if (--m_uiLockCount == 0)
            m_uiOwningThread = 0;
    }
};



template <class T> class StubPoolAlloc
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pFreeList;
    static StubCritSec ms_kPoolLock;
};

template <class T> class StubPtrAlloc : public StubPoolAlloc<T>
{
  public:
    void Deallocate(void* p)
    {
        StubPoolAlloc<T>::ms_kPoolLock.Lock(0);
        typename StubPoolAlloc<T>::LinkedListEntry* pkDel = (typename StubPoolAlloc<T>::LinkedListEntry*)p;
        pkDel->m_pUserData = 0;
        pkDel->m_pkNext = StubPoolAlloc<T>::ms_pFreeList;
        StubPoolAlloc<T>::ms_pFreeList = pkDel;
        StubPoolAlloc<T>::ms_kPoolLock.Unlock();
    }
};

template <class A, class T> class StubListBaseBase : public A
{
  public:
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    MapEntryCount m_kItemCount;
    ~StubListBaseBase()
    {}
};
template <class A, class T> class StubPtrListBase : public StubListBaseBase<A, T>
{
  public:
    void DeleteItem(NiTListItem<T>* pkItem)
    {
        pkItem->m_element = 0;
        this->Deallocate(pkItem);
    }
    void RemoveAll()
    {
        NiTListItem<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }
};
template <class T> class StubPtrList : public StubPtrListBase<StubPtrAlloc<unsigned int>, StubPtr<T> >
{
  public:
    ~StubPtrList()
    {
        this->RemoveAll();
    }
};

template <class T, class TAlloc> inline NiTArray<T, TAlloc>::~NiTArray()
{
        StubMallocIf<T>::Deallocate(m_pBase);
    }
template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::RemoveAll()
{
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }

class StubBaseC5DB90
{
  public:
    virtual ~StubBaseC5DB90();
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
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
};

class FUN_00c5db90 : public StubBaseC5DB90
{
  public:
    StubPtrList<StubRefObj> m_kList;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    NiTArray<NiParticles*, NiTMallocInterface<NiParticles*> > m_kArray;
    virtual ~FUN_00c5db90();
};

// Resets unkc0 to 0, then removes all items from m_kList and clears m_kArray.
// @fnv 0x00c5db90
FUN_00c5db90::~FUN_00c5db90()
{
    unkc0 = 0;
    m_kList.RemoveAll();
    m_kArray.RemoveAll();
}
