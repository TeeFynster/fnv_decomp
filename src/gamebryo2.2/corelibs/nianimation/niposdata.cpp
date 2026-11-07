// gamebryo2.2/corelibs/nianimation/niposdata.cpp: NiPosData (10 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPosData.h"
#include "../../../../include/NiStream.h"
#include <windows.h>

extern unsigned char DAT_011f375e[];
extern void (*DAT_011f38b8[])(PositionKeyInterpolator*);
// The shared stream declaration does not yet name its transfer storage.
inline unsigned int NiBinaryStream::Read(void* data, unsigned int bytes)
{
    unsigned int size = 4;
    unsigned int transferred = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))
        (this, data, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* data, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))
        (this, data, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

inline unsigned int NiBinaryStream::Write(const void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    return BinaryWrite(data, bytes, &size, 1);
}
// The shared stream stores its input/output pointers in the opaque layout.
inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline unsigned int NiStream::ReadUnsignedInteger()
{
    unsigned int raw;
    Istr().Read(&raw, 4);
    return raw;
}
extern PositionKeyInterpolator* (*DAT_011f3dc8[])(NiStream&, unsigned int);
extern void (*DAT_011f3798[])(PositionKeyInterpolator*, unsigned int, unsigned char);
inline unsigned char GetPosKeySize(NiAnimationKey::KeyType type)
{
    return DAT_011f375e[type];
}
typedef PositionKeyInterpolator* (*CreatePosKeys)(NiStream&, unsigned int);
typedef void (*FillPosKeys)(PositionKeyInterpolator*, unsigned int, unsigned char);
inline CreatePosKeys GetCreatePosKeys(NiAnimationKey::KeyType type)
{
    return DAT_011f3dc8[type];
}
inline FillPosKeys GetFillPosKeys(NiAnimationKey::KeyType type)
{
    return DAT_011f3798[type];
}

struct FUN_0096ad30_param;

// Methods not yet declared by NiPosData; all storage comes from the shared class.
class NiPosDataOperations : public NiPosData
{
  public:
    void UpdateKeyRange(float, float);
    void DestroyPosData();
    void SetKeys(void*, unsigned int, int);
    bool Equals(const NiPosDataOperations*);
    void SaveToStream(NiStream&);
    void nullsub_3(NiStream&);
    void AppendCameraPathEntries(FUN_0096ad30_param*);
    void AddViewerEntries(FUN_0096ad30_param*);
    void FUN_00a5d510(NiPosDataOperations**);
    void CopyKeyRange(float, float, NiPosDataOperations**);

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

// @fnv 0x00a490e0
void NiPosData::SetColorKeys(PositionKeyInterpolator* keys, unsigned int count, NiAnimationKey::KeyType eKeyType)
{
    if (m_pKeyArray)
        DAT_011f38b8[m_eRequestType](m_pKeyArray);
    if (keys && count)
    {
        m_ucKeyDataSize = GetPosKeySize(eKeyType);
        m_pKeyArray = keys;
        m_uiNumKeys = count;
        m_eRequestType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = NiAnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

// @fnv 0x00a49240
void NiPosData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int count;
    stream.Istr().Read(&count, 4);
    if (count > 0)
    {
        NiAnimationKey::KeyType type = (NiAnimationKey::KeyType)stream.ReadUnsignedInteger();
        m_ucKeyDataSize = GetPosKeySize(type);
        PositionKeyInterpolator* keys = GetCreatePosKeys(type)(stream, count);
        GetFillPosKeys(type)(keys, count, m_ucKeyDataSize);
        SetColorKeys(keys, count, type);
    }
}

extern int DAT_0109717c;
struct BaseUnk
{
    void _Call_a5d3a0();
    void* vtable;
    int _04;
};
// @fnv 0x00a49020
// src: EXE 0x00a49020
NiPosData* NiPosData_CreateObject()
{
    NiPosData* p = (NiPosData*)BSFadeNode::operator new(sizeof(NiPosData));
    if (p)
    {
        reinterpret_cast<BaseUnk*>(p)->_Call_a5d3a0();
        p->m_uiNumKeys = 0;
        p->m_pKeyArray = 0;
        p->m_eRequestType = NiAnimationKey::NOINTERP;
        p->m_ucKeyDataSize = 0;
        *(void**)p = (void*)&DAT_0109717c;
        return p;
    }
    return 0;
}

void __cdecl UpdateSlotStates(int, int, void*, void*, float, float);
// Calls UpdateSlotStates with the key count and key pointer, then stores the updated key pointer back.
// @fnv 0x00a48f70
void NiPosDataOperations::UpdateKeyRange(float afArg1, float afArg2)
{
    void* pkKeys = m_pKeyArray;
    UpdateSlotStates(1, m_eRequestType, &pkKeys, &m_uiNumKeys, afArg1, afArg2);
    m_pKeyArray = (PositionKeyInterpolator*)pkKeys;
}

// Restores the vtable, calls the stored callback on the pointer at _0C if set, then destroys the NiRefObject base.
// @fnv 0x00a48fb0
void NiPosDataOperations::DestroyPosData()
{
    PositionKeyInterpolator* p = m_pKeyArray;
    *(int*)this = (int)&DAT_0109717c;
    if (p)
        DAT_011f38b8[m_eRequestType](p);
    this->NiRefObject::~NiRefObject();
}

// Stores the key array, key count and type, setting a byte from DAT_011f375e indexed by type; clears all fields when keys or numKeys is null/zero.
// @fnv 0x00a48fe0
void NiPosDataOperations::SetKeys(void* keys, unsigned int numKeys, int type)
{
    if (keys && numKeys)
    {
        m_ucKeyDataSize = DAT_011f375e[type];
        m_pKeyArray = (PositionKeyInterpolator*)keys;
        m_uiNumKeys = numKeys;
        m_eRequestType = (NiAnimationKey::KeyType)type;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_ucKeyDataSize = 0;
        m_eRequestType = NiAnimationKey::NOINTERP;
    }
}

typedef bool(__cdecl* KeyEqual)(const void*, const void*);
extern KeyEqual DAT_011f3af8[];

// @fnv 0x00a49060
bool NiPosDataOperations::Equals(const NiPosDataOperations* other)
{
    if (!IsSameAs(const_cast<NiPosDataOperations*>(other)))
        return false;

    if (m_uiNumKeys != other->m_uiNumKeys || m_eRequestType != other->m_eRequestType ||
        m_ucKeyDataSize != other->m_ucKeyDataSize)
        return false;

    KeyEqual pfnEqualKeys = DAT_011f3af8[m_eRequestType];
    for (unsigned int i = 0; i < m_uiNumKeys; ++i)
    {
        unsigned int offset = i * m_ucKeyDataSize;
        const unsigned char* otherKey = (const unsigned char*)other->m_pKeyArray + offset;
        const unsigned char* currentKey = (const unsigned char*)m_pKeyArray + offset;
        if (!pfnEqualKeys(currentKey, otherKey))
            return false;
    }
    return true;
}

typedef void (*SavePosKeys)(NiStream& kStream, void* pvData, unsigned int ItemUpdateArray);
extern SavePosKeys g_apfnSavePosKeys[];


// SaveBinary
// @fnv 0x00a49300
void NiPosDataOperations::SaveToStream(NiStream& kStream)
{
    nullsub_3(kStream);
    kStream.GetBinaryStream()->Write((const void*)&m_uiNumKeys, 4);
    if (m_uiNumKeys > 0)
    {
        kStream.GetBinaryStream()->Write((const void*)&m_eRequestType, 4);
        g_apfnSavePosKeys[m_eRequestType](kStream, m_pKeyArray, m_uiNumKeys);
    }
}

extern char str_01097164[];
extern int DAT_011f3f68;
extern int __cdecl NiViewerStrings_NiGetViewerString_Title(int);
extern int __cdecl NiGetViewerString_00a7d510(char*, int);

struct FUN_0096ad30_param
{
    void* vtable;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, unsigned int*);
};


// @fnv 0x00a49380
void NiPosDataOperations::AddViewerEntries(FUN_0096ad30_param* param)
{
    unsigned int value;
    unsigned int index;

    AppendCameraPathEntries(param);
    value = NiViewerStrings_NiGetViewerString_Title(DAT_011f3f68);
    index = param->unk0A;
    if (index >= (unsigned int)param->unk08)
    {
        param->FUN_0096ad30((unsigned int)param->unk0E + index);
    }
    param->FUN_0096ae90(index, &value);
    value = NiGetViewerString_00a7d510(str_01097164, m_uiNumKeys);
    index = param->unk0A;
    if (index >= (unsigned int)param->unk08)
    {
        param->FUN_0096ad30((unsigned int)param->unk0E + index);
    }
    param->FUN_0096ae90(index, &value);
}


void NiAnimationKey_CopySequence(int, int, int, int, float, float, unsigned int*, unsigned int*);


// @fnv 0x00a49140
void NiPosDataOperations::CopyKeyRange(float a1, float a2, NiPosDataOperations** apObj)
{
    NiPosDataOperations* tmp;
    unsigned int uiOut2;
    unsigned int uiOut1;
    tmp = 0;
    FUN_00a5d510(&tmp);
    NiPosDataOperations* p = tmp;
    if (p != 0)
    {
        p->IncRefCount();
    }
    if (m_uiNumKeys > 0)
    {
        uiOut1 = 0;
        uiOut2 = 0;
        NiAnimationKey_CopySequence(1, m_eRequestType, (int)m_pKeyArray, (int)m_uiNumKeys, a1, a2, &uiOut1, &uiOut2);
        p->SetColorKeys((PositionKeyInterpolator*)uiOut1, uiOut2, m_eRequestType);
    }
    NiPosDataOperations* old = *apObj;
    if (old != p)
    {
        if (old != 0)
        {
            old->DecRefCount();
        }
        *apObj = p;
        if (p != 0)
        {
            p->IncRefCount();
        }
    }
    if (p != 0)
    {
        p->DecRefCount();
    }
    if (tmp != 0)
    {
        tmp->DecRefCount();
    }
}
