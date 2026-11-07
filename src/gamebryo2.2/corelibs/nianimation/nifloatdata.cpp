// gamebryo2.2/corelibs/nianimation/nifloatdata.cpp: NiFloatData (10 functions)

#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"
#include "nifloatdata_decls.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00a3cdc0
void NiFloatData::SetColorKeys(TimedAnimationKey* keys, unsigned int count, NiAnimationKey::KeyType eKeyType)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && count && eKeyType)
    {
        m_ucKeyDataSize = DAT_011f3758[eKeyType];
        m_pKeyArray = keys;
        m_uiNumKeys = count;
        m_eRequestType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_ucKeyDataSize = 0;
        m_eRequestType = NiAnimationKey::NOINTERP;
    }
}

extern const void* vftable_NiFloatData[];

// The unused EDX parameter preserves the original member functions' stack arguments.
// @fnv 0x00a3cc80
void __fastcall DestroyFloatData(NiFloatData* self, void*)
{
    *(const void***)self = vftable_NiFloatData;
    if (self->m_pKeyArray)
    {
        DAT_011f38a0[self->m_eRequestType](self->m_pKeyArray);
    }
    self->NiObject::FUN_00a5d3d0();
}

void __cdecl UpdateSlotStates(int, int, void*, void*, float, float);
// Calls UpdateSlotStates with the key count, key pointer and two floats, then stores the updated key pointer back.
// @fnv 0x00a3cc40
void __fastcall SetFloatDataRange(NiFloatData* self, void*, float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = self->m_pKeyArray;
    UpdateSlotStates(0, self->m_eRequestType, &pkKeys, &self->m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    self->m_pKeyArray = static_cast<TimedAnimationKey*>(pkKeys);
}

extern unsigned char DAT_41890871[];
// Stores the keys pointer, key count and type, caching DAT_41890871[type] as a byte; clears all fields when any argument is null or zero.
// @fnv 0x00a3ccb0
void __fastcall SetFloatDataKeys(NiFloatData* self, void*, TimedAnimationKey* keys, unsigned int numKeys, NiAnimationKey::KeyType type)
{
    if (keys && numKeys && type)
    {
        self->m_ucKeyDataSize = DAT_41890871[type];
        self->m_pKeyArray = keys;
        self->m_uiNumKeys = numKeys;
        self->m_eRequestType = type;
    }
    else
    {
        self->m_uiNumKeys = 0;
        self->m_pKeyArray = 0;
        self->m_eRequestType = NiAnimationKey::NOINTERP;
        self->m_ucKeyDataSize = 0;
    }
}

namespace fnv_00a3cd00 {

void __fastcall _Call_a5d3a0(void* object);

extern const char vftable_NiFloatData[];

// @fnv 0x00a3cd00
NiFloatData* CreateNiFloatData()
{
    NiFloatData* object = static_cast<NiFloatData*>(NiObject::operator new(0x18));

    if (object)
    {
        _Call_a5d3a0(object);

        object->m_uiNumKeys = 0;
        object->m_pKeyArray = 0;
        object->m_eRequestType = NiAnimationKey::NOINTERP;
        object->m_ucKeyDataSize = 0;

        *reinterpret_cast<void**>(object) = const_cast<void*>(static_cast<const void*>(vftable_NiFloatData));
        return object;
    }

    return 0;
}
}  // namespace fnv_00a3cd00

struct GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610* g_011f3748;

void __stdcall AppendCameraPathEntries(StrArr* strings);
char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);
char* __cdecl NiGetViewerString_00a7d510(char const* name, unsigned int value);

// @fnv 0x00a3d050
void __fastcall GetFloatDataViewerStrings(NiFloatData* self, void*, StrArr* strings)
{
    AppendCameraPathEntries(strings);

    char* value = _FUN_00a7d330(g_011f3748);
    unsigned int index = strings->m_usSize;
    unsigned int capacity = strings->m_usMaxSize;

    if (index >= capacity)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d510("m_uiNumKeys", self->m_uiNumKeys);
    index = strings->m_usSize;
    capacity = strings->m_usMaxSize;

    if (index >= capacity)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);
}

struct WriteStream
{
    void* data00;
    unsigned int position04;
    unsigned int unk08;
    unsigned int(__cdecl* write0c)(WriteStream*, const void*, unsigned int, unsigned int*, int);
    __forceinline void Write(const void* data)
    {
        unsigned int size = 4;
        position04 += write0c(this, data, 4, &size, 1);
    }
};
inline WriteStream* NiStream::GetWriter()
{
    return *reinterpret_cast<WriteStream**>((char*)this + 0x250);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>((char*)this + 0x24c);
}
extern void(__cdecl* DAT_011f3a50[])(NiStream*, TimedAnimationKey*, unsigned int);
// @fnv 0x00a3cfd0
void __fastcall SaveFloatDataBinary(NiFloatData* self, void*, NiStream* stream)
{
    self->NiObject::SaveBinary(*stream);
    stream->GetWriter()->Write(&self->m_uiNumKeys);
    if (self->m_uiNumKeys > 0)
    {
        stream->GetWriter()->Write(&self->m_eRequestType);
        DAT_011f3a50[self->m_eRequestType](stream, self->m_pKeyArray, self->m_uiNumKeys);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* Addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* Addend);

inline void NiRefObject::AcquireReference()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiRefObject::DecRef()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

extern void __cdecl NiAnimationKey_CopySequence(int, int, TimedAnimationKey*, unsigned int, float, float, TimedAnimationKey**,
                                 unsigned int*);

// @fnv 0x00a3ce20
void __fastcall CloneFloatDataRange(NiFloatData* self, void*, float m_fStartTime, float m_fMaximumDistance, NiFloatData** ppResult)
{
    NiFloatData* pData = 0;
    self->ResolveObjectPointer(*reinterpret_cast<NiPointer<NiObject>*>(&pData));
    NiFloatData* pCur = pData;
    if (pCur != 0)
        pCur->AcquireReference();
    if (self->m_uiNumKeys > 0)
    {
        TimedAnimationKey* pKeys = 0;
        unsigned int uiNumKeys = 0;
        NiAnimationKey_CopySequence(0, (int)self->m_eRequestType, self->m_pKeyArray, self->m_uiNumKeys, m_fStartTime, m_fMaximumDistance, &pKeys,
                     &uiNumKeys);
        pCur->SetColorKeys(pKeys, uiNumKeys, self->m_eRequestType);
    }
    NiFloatData* pOld = *ppResult;
    if (pOld != pCur)
    {
        if (pOld != 0)
            pOld->DecRef();
        *ppResult = pCur;
        if (pCur != 0)
            pCur->AcquireReference();
    }
    if (pCur != 0)
        pCur->DecRef();
    if (pData != 0)
        pData->DecRef();
}

typedef bool(__cdecl* FUN_00a3cd40_KeyCmp)(void*, void*);
extern FUN_00a3cd40_KeyCmp DAT_011f3ae0[];

// Compares this NiFloatData with another by checking key count, request type, key data size, and each key via a type-specific comparator.
// @fnv 0x00a3cd40
bool __fastcall IsFloatDataEqual(NiFloatData* self, void*, NiFloatData* other)
{
    if (!self->NiObject::IsSameAs(other))
    {
        return false;
    }
    if (self->m_uiNumKeys != other->m_uiNumKeys)
    {
        return false;
    }
    if (self->m_eRequestType != other->m_eRequestType)
    {
        return false;
    }
    if (self->m_ucKeyDataSize != other->m_ucKeyDataSize)
    {
        return false;
    }
    FUN_00a3cd40_KeyCmp cmp = DAT_011f3ae0[self->m_eRequestType];
    unsigned int iKeyIndex = 0;
    if (self->m_uiNumKeys > 0)
    {
        do
        {
            void* a = (char*)other->m_pKeyArray + (unsigned int)self->m_ucKeyDataSize * iKeyIndex;
            void* n = (char*)self->m_pKeyArray + (unsigned int)self->m_ucKeyDataSize * iKeyIndex;
            if (!cmp(n, a))
            {
                return false;
            }
            ++iKeyIndex;
        } while (iKeyIndex < self->m_uiNumKeys);
    }
    return true;
}

typedef TimedAnimationKey*(__cdecl* CreateFn_cf)(NiStream&, unsigned int);
typedef void(__cdecl* FillFn_cf)(TimedAnimationKey*, unsigned int, unsigned char);
extern CreateFn_cf DAT_011f3db0[];
extern FillFn_cf DAT_011f3780[];

struct StreamBinView_cf
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(StreamBinView_cf* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

template <class T> inline void LoadEnum(StreamBinView_cf* istr, T& v)
{
    unsigned int u;
    istr->Load(&u);
    v = (T)u;
}

// Loads animation key data from a NiStream, reading key count, type, and key values, then stores them via SetColorKeys.
// @fnv 0x00a3cf10
void NiFloatData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int numKeys;

    reinterpret_cast<StreamBinView_cf*>(stream.GetBinaryStream())->Load(&numKeys);
    if (numKeys > 0)
    {
        NiAnimationKey::KeyType keyType;
        LoadEnum(reinterpret_cast<StreamBinView_cf*>(stream.GetBinaryStream()), keyType);
        m_ucKeyDataSize = DAT_011f3758[keyType];
        CreateFn_cf pCreateFn = DAT_011f3db0[keyType];
        TimedAnimationKey* keys = pCreateFn(stream, numKeys);
        FillFn_cf pFillFn = DAT_011f3780[keyType];
        pFillFn(keys, numKeys, m_ucKeyDataSize);
        SetColorKeys(keys, numKeys, keyType);
    }
}
