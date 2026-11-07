
// src/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nitextkeyextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiStream.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiStringsExtraData.h"
#include "../../../../include/NiTextKeyExtraData.h"
#include "../../../../include/BSFadeNode.h"

extern void* g_011f3f28;

// Returns the address of the global pointer g_011f3f28.
// @fnv 0x00a46b60
// src: COMMUNITY 0x00a46b60
void* __cdecl NiTextKeyExtraData_GetRTTI()
{
    return &g_011f3f28;
}

extern void* DAT_0109827c;

// @fnv 0x00a46b70
// src: EXE 0x00a46b70
void* __cdecl NiTextKeyExtraData_CreateObject()
{
    NiTextKeyExtraData* p = static_cast<NiTextKeyExtraData*>(BSFadeNode::operator new(sizeof(NiTextKeyExtraData)));
    if (p)
    {
        p->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_0109827c;
        p->m_uiNumKeys = 0;
        p->m_pKeys = 0;
        return p;
    }
    return 0;
}

void __fastcall DestroyTextKeyList(NiTextKeyExtraData* self, void*);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

// @fnv 0x00a46ed0
void* __fastcall DeleteTextKeyExtraData(NiTextKeyExtraData* self, void*, unsigned int flags)
{
    reinterpret_cast<void (__thiscall*)(NiTextKeyExtraData*)>(&DestroyTextKeyList)(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x14);
    return self;
}

class TimedTextEntry
{
  public:
    float m_fTime;
    const char* m_kText;
    void __thiscall RegisterStreamables(NiStream*);
    void __thiscall ReadBinary(NiStream&);
    void __thiscall ReleaseString();
    float GetTime() const { return m_fTime; }
    const char* GetText() const { return m_kText; }
};

// Keep unavailable base entry points local without duplicating the shared class.
bool __cdecl RegisterExtraData();

// Registers the base extra data and each text key with the stream.
// @fnv 0x00a46b10
bool __fastcall LoadFromStream(NiTextKeyExtraData* _this, void* _edx, NiStream* stream)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiExtraData*, NiStream*)>(&RegisterExtraData)(_this, stream))
        return false;
    unsigned int uiI;
    for (uiI = 0; uiI < _this->m_uiNumKeys; ++uiI)
        _this->m_pKeys[uiI].RegisterStreamables(stream);
    return true;
}

// Checks that pkObject is non-null, base-equal, has the same key count, and that every key's time and value match; returns true if so.
// @fnv 0x00a46bb0
bool __fastcall IsTextKeyExtraDataEqual(NiTextKeyExtraData* self, void*, NiObject* pkObject)
{
    if (!pkObject)
        return false;
    if (!self->NiObject::IsEqual(pkObject))
        return false;
    NiTextKeyExtraData* pkOther = (NiTextKeyExtraData*)pkObject;
    if (self->m_uiNumKeys != pkOther->m_uiNumKeys)
        return false;
    for (unsigned int i = 0; i < self->m_uiNumKeys; i++)
    {
        if (self->m_pKeys[i].m_fTime != pkOther->m_pKeys[i].m_fTime ||
            self->m_pKeys[i].m_kText != pkOther->m_pKeys[i].m_kText)
            return false;
    }
    return true;
}

struct MM
{
    void __thiscall Deallocate(void*);
};
extern MM g_memoryManager;
// @fnv 0x00a46d50
void __fastcall DestroyTextKeyList(NiTextKeyExtraData* self, void*)
{
    *(void**)self = &DAT_0109827c;
    void* keys = self->m_pKeys;
    if (keys)
    {
        int count = ((int*)keys)[-1];
        char* current = (char*)keys + count * 8;
        --count;
        if (count >= 0)
        {
            do
            {
                current -= 8;
                ((TimedTextEntry*)current)->ReleaseString();
                --count;
            } while (count >= 0);
        }
        g_memoryManager.Deallocate((char*)keys - 4);
    }
    self->NiExtraData::DestroyFields_00a7b300();
}

extern int DAT_0109b220;

// @fnv 0x00a46b50
NiTextKeyExtraData* __fastcall InitializeTextKeyRefCount(NiTextKeyExtraData* self, void*)
{
    self->m_uiRefCount = DAT_0109b220;
    return self;
}

extern "C" unsigned int __cdecl strlen(const char*);
struct StrArray
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        FUN_0096ae90(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int AddInline(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != 0)
                m_usESize++;
        }
        else
        {
            if (element != 0)
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
        m_pBase[uiIndex] = element;
        return uiIndex;
    }
};

char* NiViewerStrings_NiGetViewerString_Title(const char* s);
char* NiGetViewerString_00a7d510(const char* s, unsigned int v);
char* NiGetViewerString_00a7d550(const char* s, float v);
char* NiGetViewerString_00a7d5e0(const char* s, const char* v);
void* NiMalloc(unsigned int size);
void NiFree(void* p);
int NiSprintf(char* buf, unsigned int size, const char* fmt, ...);

void __cdecl GetExtraDataViewerStrings();

// Appends the base strings, the key count, and one formatted "Time : Text" entry per text key to pkStrings.
// @fnv 0x00a46ef0
void __fastcall WriteTextKeyStrings(NiTextKeyExtraData* self, void*, StrArray* pkStrings)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, StrArray*)>(&GetExtraDataViewerStrings)(self, pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title((const char*)g_011f3f28));
    pkStrings->Add(NiGetViewerString_00a7d510("m_uiNumKeys", self->m_uiNumKeys));

    for (unsigned int i = 0; i < self->m_uiNumKeys; i++)
    {
        char* pcTimeString = NiGetViewerString_00a7d550("Time", self->m_pKeys[i].GetTime());
        char* pcTextString = NiGetViewerString_00a7d5e0("Text", self->m_pKeys[i].GetText());
        unsigned int uiBufferSize = strlen(pcTimeString) + strlen(pcTextString) + 4;
        char* pcString = (char*)NiMalloc(uiBufferSize);
        NiSprintf(pcString, uiBufferSize, "%s : %s", pcTimeString, pcTextString);
        char* pcEntryString = NiGetViewerString_00a7d5e0("TextKey", pcString);
        pkStrings->AddInline(pcEntryString);
        NiFree(pcTimeString);
        NiFree(pcTextString);
        NiFree(pcString);
    }
}

void __cdecl CopyTextKeyMemberData();

__forceinline NiTextKeyExtraData* __fastcall InitializeTextKeyExtraData(NiTextKeyExtraData* self) throw()
{
    self->FUN_00a7b2e0();
    *reinterpret_cast<void**>(self) = &DAT_0109827c;
    self->m_uiNumKeys = 0;
    self->m_pKeys = 0;
    return self;
}

// @fnv 0x00a46da0
NiExtraData* __fastcall CloneTextKeyExtraData(NiTextKeyExtraData* self, void*, void* pvProcess)
{
    // The shared class has no constructor for this original initialization path.
    void* memory = BSFadeNode::operator new(sizeof(NiTextKeyExtraData));
    NiTextKeyExtraData* pkClone = memory ? InitializeTextKeyExtraData(static_cast<NiTextKeyExtraData*>(memory)) : 0;
    reinterpret_cast<void (__thiscall*)(NiTextKeyExtraData*, NiTextKeyExtraData*, void*)>(&CopyTextKeyMemberData)(self, pkClone, pvProcess);
    return pkClone;
}

class S00a46cf0_BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int m_unk08;
    unsigned int(__cdecl* m_pfnRead)(S00a46cf0_BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};

template <class T> inline void NiBinaryStreamLoad(S00a46cf0_BinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

template <class T> inline void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(reinterpret_cast<S00a46cf0_BinaryStream*>(kStream.GetBinaryStream()), &value, 1);
}

void __cdecl LoadExtraDataBinary();

// Loads the base extra data, the key count, and each text key from the stream.
// @fnv 0x00a46cf0
void __fastcall LoadTextKeyBinary(NiTextKeyExtraData* self, void*, NiStream& kStream)
{
    reinterpret_cast<void (__thiscall*)(NiExtraData*, NiStream&)>(&LoadExtraDataBinary)(self, kStream);
    ReadBinaryValue(kStream, self->m_uiNumKeys);
    for (unsigned int i = 0; i < self->m_uiNumKeys; i++)
        self->m_pKeys[i].ReadBinary(kStream);
}
