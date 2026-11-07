#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/nianimation/nikeyframemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nikeyframemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../../../include/NiTimeController.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"

extern "C" void* g_011f3fb4;

// @fnv 0x00a4da80
// src: COMMUNITY 0x00a4da80
void* __cdecl NiKeyframeManager_GetRTTI()
{
    return &g_011f3fb4;
}

struct Map_00a4da90
{
    void FUN_00a4d660();
};
void __cdecl _delete(void*, unsigned int);
struct Holder_00a4da90
{
    char _pad[0x34];
    Map_00a4da90 _map;
    void FUN_00a6d290();
    void* FUN_00a4da90(unsigned int);
};
// @fnv 0x00a4da90
void* Holder_00a4da90::FUN_00a4da90(unsigned int flags)
{
    _map.FUN_00a4d660();
    FUN_00a6d290();
    if (flags & 1)
        _delete(this, 0x48);
    return this;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int byteCount);
struct AllocatedAnimationController
{
    void* __thiscall FUN_00a4da20();
};
// @fnv 0x00a4db60
// src: EXE 0x00a4db60
void* __cdecl NiKeyframeManager_CreateObject()
{
    void* storage = Object_DispatchCommandFour(0x48);
    if (storage != 0)
        return static_cast<AllocatedAnimationController*>(storage)->FUN_00a4da20();
    return 0;
}

// The shared declaration has no inline body or stream-state members yet.
inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 0x08))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x04) += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void ReadBinaryValue(NiBinaryStream* pkStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(&value, sizeof(T), &uiSize, 1);
}

extern MemoryManager _g_memoryManager;

void __cdecl NiFree(void* p);

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }

template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else if (m_pBase[uiIndex] != 0)
        {
            m_usESize--;
        }
        m_pBase[uiIndex] = element;
    }


struct SequenceData
{
    NiTArray<unsigned int, NiTMallocInterface<unsigned int> > m_kArr0;
    NiTArray<char*, NiTMallocInterface<char*> > m_kArr1;
    NiTArray<unsigned int, NiTMallocInterface<unsigned int> > m_kArr2;
    NiTArray<char*, NiTMallocInterface<char*> > m_kArr3;
    SequenceData() throw();
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
};

extern SequenceData* g_011f3fb0;

struct NiStreamR
{
    void ReadStreamString(char*& pc);
    void ResetStreamState();
    void SetNumLinks(unsigned int ui);
    int Version()
    {
        return *(int*)((char*)this + 0xd8);
    }
    NiBinaryStream* Istr()
    {
        return *(NiBinaryStream**)((char*)this + 0x24c);
    }
};

struct SeqController : NiTimeController
{
    void NiKeyframeManager_Add(char* p1, char* p2, unsigned int ui);
    void NiKeyframeManager_LoadBinary(NiStreamR& kStream);
};

// @fnv 0x00a4db80
// src: XBOX_PDB 0x00a4db80
void SeqController::NiKeyframeManager_LoadBinary(NiStreamR& kStream)
{
    NiTimeController::LoadBinary(reinterpret_cast<NiStream&>(kStream));
    unsigned int uiCountB;
    if ((unsigned int)kStream.Version() < 0x4010003)
    {
        unsigned int ItemUpdateArray;
        ReadBinaryValue(kStream.Istr(), ItemUpdateArray);
        while (ItemUpdateArray)
        {
            ItemUpdateArray--;
            bool bFlag;
            ReadBinaryValue(kStream.Istr(), bFlag);
            char* pcName = 0;
            kStream.ReadStreamString(pcName);
            if (bFlag)
            {
                char* pcName2 = 0;
                kStream.ReadStreamString(pcName2);
                unsigned int uiValue;
                ReadBinaryValue(kStream.Istr(), uiValue);
                NiKeyframeManager_Add(pcName2, pcName, uiValue);
                NiFree(pcName2);
                NiFree(pcName);
            }
            else
            {
                g_011f3fb0 = new SequenceData;
                g_011f3fb0->m_kArr1.Add(pcName);
                unsigned int uiValue;
                ReadBinaryValue(kStream.Istr(), uiValue);
                g_011f3fb0->m_kArr0.Add(uiValue);
                kStream.ResetStreamState();
                unsigned int uiElementCount;
                ReadBinaryValue(kStream.Istr(), uiElementCount);
                g_011f3fb0->m_kArr2.Add(uiElementCount);
                while (uiElementCount--)
                {
                    char* pc = 0;
                    kStream.ReadStreamString(pc);
                    g_011f3fb0->m_kArr3.Add(pc);
                    kStream.ResetStreamState();
                }
            }
        }
    }
    else
    {
        unsigned int uiLinks = 0;
        ReadBinaryValue(kStream.Istr(), uiCountB);
        while (uiCountB--)
        {
            bool bFlag;
            ReadBinaryValue(kStream.Istr(), bFlag);
            if (bFlag)
            {
                char* pcName = 0;
                kStream.ReadStreamString(pcName);
                char* pcName2 = 0;
                kStream.ReadStreamString(pcName2);
                unsigned int uiValue;
                ReadBinaryValue(kStream.Istr(), uiValue);
                NiKeyframeManager_Add(pcName2, pcName, uiValue);
                NiFree(pcName);
                NiFree(pcName2);
            }
            else
            {
                kStream.ResetStreamState();
                uiLinks++;
            }
        }
        kStream.SetNumLinks(uiLinks);
    }
}

template <class T, class TAlloc> inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = new T[m_usMaxSize];
        else
            m_pBase = 0;
    }

template <class T> class CA4D780PrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    CA4D780PrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
    {}
    virtual ~CA4D780PrimitiveArray();
};

class CA4D780Object;

class FUN_00a4d780
{
  public:
    FUN_00a4d780() throw();

    CA4D780PrimitiveArray<unsigned int> m_kFirstIDs;
    CA4D780PrimitiveArray<CA4D780Object*> m_kFirstObjects;
    CA4D780PrimitiveArray<unsigned int> m_kSecondIDs;
    CA4D780PrimitiveArray<CA4D780Object*> m_kSecondObjects;
};

// @fnv 0x00a4d780
FUN_00a4d780::FUN_00a4d780() throw()
{}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(nothrow) void __cdecl NiFree(void*);
struct MemShellD810
{
    void MemoryManager_Deallocate(void* p);
};
extern int DAT_0102102c;
extern int DAT_0101a3a4;
extern int str_0101a3a4;
extern int PTR_0102102c;
struct RefD810
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    int id;
};
struct SmartD810
{
    RefD810* ptr;
    SmartD810(RefD810* p) : ptr(p)
    {
        if (ptr)
            InterlockedIncrement(&ptr->refs);
    }
};
struct StreamD810
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc,
        unkc0, unkc4, unkc8, unkcc, unkd0, unkd4;
    unsigned int version;
    RefD810* FUN_00a63430();
    unsigned int FUN_00a63460();
};
struct FUN_00a47bd0 : RefD810
{
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    RefD810* object;
    unsigned int unk30;
    static __declspec(nothrow) void* __cdecl operator new(unsigned int);
    __declspec(nothrow) FUN_00a47bd0(void*, int, int);
    void AddSeq(void*, RefD810*);
    void SetObject(RefD810* p)
    {
        if (object != p)
        {
            RefD810* pvOld = object;
            if (pvOld && !InterlockedDecrement(&pvOld->refs))
                pvOld->DeleteThis();
            object = p;
            if (p)
                InterlockedIncrement(&p->refs);
        }
    }
};
struct MapD810
{
    void NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(int, SmartD810);
};
template <class T, int* VTBL> struct ArrD810
{
    int* vtbl;
    T* data;
    unsigned short capacity, size;
    int unk0c;
    ~ArrD810()
    {
        vtbl = VTBL;
        NiFree(data);
    }
};
struct LegacyD810
{
    ArrD810<unsigned int, &str_0101a3a4> values;
    ArrD810<void*, &PTR_0102102c> names;
    ArrD810<unsigned int, &DAT_0101a3a4> counts;
    ArrD810<void*, &DAT_0102102c> linkNames;
    ~LegacyD810()
    {}
    static void __cdecl operator delete(void* p)
    {
        ((MemShellD810*)&_g_memoryManager)->MemoryManager_Deallocate(p);
    }
};
extern LegacyD810* DAT_011f3fb0;
struct TargetD810
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    MapD810 map;
    void FUN_00a6d500(StreamD810&);
    void NiKeyframeManager_LinkObject(StreamD810& akStream);
};
// @fnv 0x00a4d810
// src: XBOX_PDB 0x00a4d810
void TargetD810::NiKeyframeManager_LinkObject(StreamD810& akStream)
{
    FUN_00a6d500(akStream);
    if (akStream.version < 0x4010003)
    {
        unsigned int ItemUpdateArray = DAT_011f3fb0->counts.size;
        unsigned int uiLink = 0;
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            void* pvName = DAT_011f3fb0->names.data[i];
            FUN_00a47bd0* pkItem = new FUN_00a47bd0(pvName, 12, 12);
            NiFree(pvName);
            pkItem->unk30 = DAT_011f3fb0->values.data[i];
            pkItem->SetObject(akStream.FUN_00a63430());
            unsigned int uiEntries = DAT_011f3fb0->counts.data[i];
            while (uiEntries)
            {
                void* pvLink = DAT_011f3fb0->linkNames.data[uiLink];
                --uiEntries;
                ++uiLink;
                RefD810* pkObj = akStream.FUN_00a63430();
                pkItem->AddSeq(pvLink, pkObj);
                NiFree(pvLink);
            }
            int id = pkItem->id;
            map.NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(id, pkItem);
        }
        delete DAT_011f3fb0;
        DAT_011f3fb0 = 0;
    }
    else
    {
        unsigned int ItemUpdateArray = akStream.FUN_00a63460();
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            RefD810* pkItem = akStream.FUN_00a63430();
            int id = pkItem->id;
            map.NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(id, pkItem);
        }
    }
}

struct S_00a4dac0_Obj
{
    virtual void unk_dtor() throw();
    virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
    const char* m_name;
    void __thiscall SetString(const char* name) throw();
    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct S_00a4dac0_Ptr
{
    S_00a4dac0_Obj* m_p;
    S_00a4dac0_Ptr() : m_p(0)
    {}
    S_00a4dac0_Ptr(const S_00a4dac0_Ptr& o) : m_p(o.m_p)
    {
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00a4dac0_Ptr() throw()
    {
        if (m_p)
            m_p->DecRefCount();
    }
};
struct S_00a4dac0_Arg
{
    S_00a4dac0_Obj* m_p;
    S_00a4dac0_Arg(S_00a4dac0_Obj* const& o) throw() : m_p(o)
    {
        if (m_p)
            m_p->IncRefCount();
    }
};
struct S_00a4dac0_Map
{
    int unk00;
    void __thiscall NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(const char* key, S_00a4dac0_Arg value) throw();
};
void __cdecl CreateOrReleaseRef(int a, int b, S_00a4dac0_Obj** out, const char* name) throw();
struct S_00a4dac0
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
    S_00a4dac0_Map map34;
    bool __thiscall NiKeyframeManager_Add(int a, const char* name, int b) throw();
};
// @fnv 0x00a4dac0
// src: COMMUNITY 0x00a4dac0
bool __thiscall S_00a4dac0::NiKeyframeManager_Add(int a, const char* name, int b) throw()
{
    S_00a4dac0_Obj* obj = 0;
    CreateOrReleaseRef(a, b, &obj, name);
    if (!obj)
        return false;
    if (name)
        obj->SetString(name);
    const char* key = obj->m_name;
    map34.NiTStringTemplateMap_NiTPointerMap_char_const_NiPointer_NiSequence_NiPointer_NiSequence_SetAt(key, obj);
    if (obj)
        obj->DecRefCount();
    return true;
}
