// gamebryo2.2/corelibs/nimain/nishaderfactory.cpp: NiShaderFactory, NiRefObject (11 functions)

#include "layout_support.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiShaderFactory.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/NiGPUProgram.h"
#include "../../../../include/NiFile.h"

inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement(reinterpret_cast<volatile long*>(&ms_lObjectCount));
}

// @fnv 0x00a9fff0
NiShaderFactory* __cdecl NiShaderFactory::GetInstance()
{
    return ms_pShaderFactory;
}

void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
// @fnv 0x00aa06c0
NiShaderFactory* __fastcall DestroyShaderFactory(NiShaderFactory* pkFactory, void*, unsigned int flags)
{
    pkFactory->NiShaderFactory::~NiShaderFactory();
    if (flags & 1)
        __Dummy_00b6fef0(pkFactory, 0x24);
    return pkFactory;
}

extern char const* const g_0126f9ac_arg1;
// @fnv 0x00e89830
const NiRTTI* NiD3DShaderProgram::GetRTTI() const
{
    return (const NiRTTI*)&g_0126f9ac_arg1;
}

int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
// @fnv 0x00aa19e0
// src: GAMEBRYO_LIB 0x00aa19e0
unsigned int __cdecl NiFile_ReadAndSwap(NiFile* apFile, void* apBuffer, unsigned int auiSize, void* apArg4, void* apArg5)
{
    if (auiSize <= 0)
        return 0;
    unsigned int r = apFile->FileRead(apBuffer, auiSize);
    SwapBufferBySizes(apBuffer, auiSize, apArg4, apArg5);
    return r;
}

extern char* _EmptyFS;

struct ShaderConstantMap : NiTFixedStringMap<NiGlobalConstantEntry*>
{
    void SetAt(NiFixedString* pkKey, NiGlobalConstantEntry* pkValue);
};

struct ShaderFactorySlot : NiShaderFactory
{
    static NiShaderFactory*& Get()
    {
        return ms_pShaderFactory;
    }
};

// Constructor 0x00aa00d0 and deleting destructor 0x00aa0190 identify this 24-byte NiRefObject; no shared header exists yet.
class NiGlobalConstantEntry : public NiRefObject
{
public:
    NiGlobalConstantEntry(const char* pcName, unsigned int uiValue, unsigned int uiSize, const void* pvData) throw();
    void* Destroy(int flag);

    NiFixedString m_kName;
    unsigned int m_uiCurrentValue;
    unsigned int m_uiSize;
    void* m_pResource;
};

void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);

// The bare handle of an NiFixedString whose constructor and destructor these functions spell out inline (NiMain
// has no exception frames; a real NiFixedString local would add one to this /EHsc unit).
struct FixedStringHandle
{
    char* m_kHandle;
};

// @fnv 0x00aa0400
bool __cdecl AcquireGlobalConstantEntry(const NiFixedString* pkName, unsigned int a2, unsigned int a3, unsigned int a4)
{
    if (ShaderFactorySlot::Get() == 0)
        return false;
    NiShaderFactory* pkFactory = ShaderFactorySlot::Get();
    FixedStringHandle kLocal;
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>* pkItem =
        pkFactory->m_kGlobalConstantEntryMap
            .m_ppkHashTable[(unsigned int)pkName->m_kHandle % pkFactory->m_kGlobalConstantEntryMap.m_uiHashSize];
    while (pkItem != 0)
    {
        if ((unsigned int)pkName->m_kHandle == (unsigned int)pkItem->m_key.m_kHandle)
        {
            NiGlobalConstantEntry* pkEntry = pkItem->m_val;
            if (pkEntry == 0)
                break;
            if (pkEntry->m_uiCurrentValue != a2)
                return false;
            InterlockedIncrement((long*)&pkEntry->m_uiRefCount);
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }

    void* pvMem = Object_DispatchCommandFour(0x18);
    if (pvMem == 0)
        return false;
    const char* pcName = pkName->m_kHandle;
    NiGlobalConstantEntry* pkNew = new (pvMem) NiGlobalConstantEntry(pcName, a2, a3, (const void*)a4);
    if (pkNew == 0)
        return false;

    InterlockedIncrement((long*)&pkNew->m_uiRefCount);
    if (pkName->m_kHandle != _EmptyFS)
        InterlockedIncrement((long*)(pkName->m_kHandle - 8));

    char* pcHandle = pkName->m_kHandle;
    NiShaderFactory* pkMapOwner = ShaderFactorySlot::Get();
    kLocal.m_kHandle = pcHandle;
    ((ShaderConstantMap*)&pkMapOwner->m_kGlobalConstantEntryMap)->SetAt(reinterpret_cast<NiFixedString*>(&kLocal), pkNew);

    if (pcHandle != _EmptyFS)
        InterlockedDecrement((long*)(pcHandle - 8));
    return true;
}

struct SpawnedArgBase : public NiRefObject
{
    int m_iArg08;
    SpawnedArgBase(int a2) throw()
    {
        m_iArg08 = a2;
    }
};

struct FUN_00e897d0 : public SpawnedArgBase
{
    virtual ~FUN_00e897d0() throw();
    virtual void DeleteThis();
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    FUN_00e897d0(int a1, int a2) throw();
    void Init(int a1);
};

// Constructs the object from a base argument and a1, zeroes eight fields, then calls Init(a1).
// @fnv 0x00e897d0
FUN_00e897d0::FUN_00e897d0(int a1, int aiArg) throw() : SpawnedArgBase(aiArg)
{
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    Init(a1);
}

inline NiRefObject::~NiRefObject()
{
    InterlockedDecrement(reinterpret_cast<volatile long*>(&ms_lObjectCount));
}

void NiFree(void* p) throw();

extern char* g_pcEmptyFixedString;

struct FixedStr
{
    char* m_kHandle;
    FixedStr()
    {
        m_kHandle = g_pcEmptyFixedString;
    }
    ~FixedStr()
    {
        if (m_kHandle != g_pcEmptyFixedString)
            InterlockedDecrement((volatile long*)(m_kHandle - 8));
    }
};

// These operations are not yet declared by the shared map headers.
struct GlobalConstantMapOperations : NiTFixedStringMap<NiGlobalConstantEntry*>
{
    void GetNext(void*& rkPos, FixedStr& rkKey, NiGlobalConstantEntry*& rkVal) const throw();
    void* GetFirstPos() const
    {
        unsigned int uiHashSize = m_uiHashSize;
        for (unsigned int i = 0; i < uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
};

// The member map's two destructor stages, inlined into ~NiShaderFactory: NiTFixedStringMap<NiGlobalConstantEntry *>
// (vftable 0x010a2154), then NiTFixedStringMapBase (vftable 0x010a2138), which also frees the table.
template <>
__forceinline NiTFixedStringMap<NiGlobalConstantEntry*>::~NiTFixedStringMap()
{
    RemoveAll();
}
template <>
__forceinline NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, NiGlobalConstantEntry*> >, NiGlobalConstantEntry*>::~NiTFixedStringMapBase()
{
    RemoveAll();
    NiFree(m_ppkHashTable);
}

void __cdecl RemoveGlobalConstant(char** pkName) throw();

// @fnv 0x00aa05a0
NiShaderFactory::~NiShaderFactory() throw()
{
    if (ms_pShaderFactory)
        ms_pShaderFactory->v8();
    if (ms_pShaderFactory)
        ms_pShaderFactory->v13();

    GlobalConstantMapOperations& kMap = static_cast<GlobalConstantMapOperations&>(m_kGlobalConstantEntryMap);
    void* pos = kMap.GetFirstPos();
    while (pos)
    {
        FixedStr kName;
        NiGlobalConstantEntry* pkEntry = 0;
        kMap.GetNext(pos, kName, pkEntry);
        if (pkEntry)
            RemoveGlobalConstant(&kName.m_kHandle);
    }

    if (ms_pShaderFactory == this)
        ms_pShaderFactory = 0;

}

// @fnv 0x00a38de0
// src: COMMUNITY 0x00a38de0
int __stdcall _return0(int unk08)
{
    return 0;
}

extern int DAT_010a2148;
extern int DAT_0101dce4;
extern void* DAT_0109b220;
extern int DAT_011f4400;

typedef int(__stdcall* FUN_00aa0190_Decrement)(void*);
extern FUN_00aa0190_Decrement DAT_00fdf1c4;

void __cdecl _NiFree_00aa10f0(void* p);
void __cdecl FUN_00aa1460(void* p, unsigned int size);

// @fnv 0x00aa0190
void* __thiscall NiGlobalConstantEntry::Destroy(int aiFlags)
{
    void* saved = m_pResource;
    *(int**)this = &DAT_010a2148;
    _NiFree_00aa10f0(saved);

    void* head = m_kName.m_kHandle;
    FUN_00aa0190_Decrement decrement = DAT_00fdf1c4;
    if (head != DAT_0109b220)
    {
        decrement(static_cast<char*>(head) - 8);
    }

    *(int**)this = &DAT_0101dce4;
    decrement(&DAT_011f4400);

    if ((aiFlags & 1) != 0)
    {
        FUN_00aa1460(this, 0x18);
    }

    return this;
}

// Returns 0 regardless of its three arguments.
// @fnv 0x00b57fc0
// src: COMMUNITY 0x00b57fc0
int __stdcall NiShaderFactory_Func000(int arg0, int arg1, int arg2)
{
    return 0;
}

extern char* _EmptyFS;

struct Stub
{
    __declspec(noalias) void NiTStringPointerMap_NiAVObject_RemoveAt(NiFixedString* kKey);
};

// Finds the global constant entry for pkName in the shader factory, decrements its ref count, and deletes it when it reaches zero.
// @fnv 0x00aa04e0
bool RemoveGlobalConstant(const NiFixedString* pkName)
{
    NiShaderFactory* pkFactory = ShaderFactorySlot::Get();
    if (pkFactory == 0)
        return false;

    unsigned int uiKey = (unsigned int)pkName->m_kHandle;
    ShaderConstantMap* pkMap = (ShaderConstantMap*)&pkFactory->m_kGlobalConstantEntryMap;
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>* pkItem = pkMap->m_ppkHashTable[uiKey % pkMap->m_uiHashSize];
    NiRefObject* pkEntry = 0;
    while (pkItem != 0)
    {
        if (uiKey == (unsigned int)pkItem->m_key.m_kHandle)
        {
            pkEntry = (NiRefObject*)pkItem->m_val;
            break;
        }
        pkItem = pkItem->m_pkNext;
    }
    if (pkEntry == 0)
        return false;

    if (pkName->m_kHandle != _EmptyFS)
        InterlockedIncrement((long*)(pkName->m_kHandle - 8));
    pkFactory = ShaderFactorySlot::Get();

    FixedStringHandle kLocal;
    char* pcHandle = pkName->m_kHandle;
    kLocal.m_kHandle = pcHandle;
    if (pkEntry->m_uiRefCount == 1)
    {
        ((Stub*)&pkFactory->m_kGlobalConstantEntryMap)->NiTStringPointerMap_NiAVObject_RemoveAt(reinterpret_cast<NiFixedString*>(&kLocal));
        if (InterlockedDecrement((long*)&pkEntry->m_uiRefCount) == 0)
            pkEntry->DeleteThis();
    }
    else
    {
        if (InterlockedDecrement((long*)&pkEntry->m_uiRefCount) == 0)
            pkEntry->DeleteThis();
    }

    if (pcHandle != _EmptyFS)
        InterlockedDecrement((long*)(pcHandle - 8));
    return true;
}
