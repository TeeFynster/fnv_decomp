// Text key cloning and loading, compiled without /EHsc.
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiStringsExtraData.h"
#include "../../../../include/NiTextKeyExtraData.h"

extern void* g_011f3f28;

struct DynamicMemoryAllocator
{
    void* __thiscall Allocate(unsigned int uiSize);
};
extern "C" DynamicMemoryAllocator g_allocator;

class TimedTextEntry
{
  public:
    float m_fTime;
    NiFixedString m_kText;
    TimedTextEntry() throw();
    ~TimedTextEntry() {}
    static void* operator new[](unsigned int uiSize) throw()
    {
        return g_allocator.Allocate(uiSize);
    }
    static void operator delete[](void* p);
    const NiFixedString& GetText() const
    {
        return m_kText;
    }
    void SetText(const NiFixedString& kText);
    void __thiscall FUN_00a578d0(NiStream& stream);
};

inline bool IsExactTextKeyKind(const NiRTTI* pkRTTI, const NiExtraData* pkObject)
{
    if (!pkObject)
        return false;
    return pkObject->GetRTTI() == pkRTTI;
}

// These operations are not yet declared by the shared NiTextKeyExtraData header.
// @fnv 0x00a46c20
void __fastcall CopyTextKeys(NiTextKeyExtraData* self, void*, NiTextKeyExtraData* pkDest, CloningProcess* kCloning)
{
    self->NiExtraData::CopyMembers_00a7b330(pkDest, kCloning);
    pkDest->m_uiNumKeys = self->m_uiNumKeys;
    if (self->m_uiNumKeys > 0 && IsExactTextKeyKind((const NiRTTI*)&g_011f3f28, self))
    {
        pkDest->m_pKeys = new TimedTextEntry[self->m_uiNumKeys];
        for (unsigned int i = 0; i < self->m_uiNumKeys; i++)
        {
            pkDest->m_pKeys[i].m_fTime = self->m_pKeys[i].m_fTime;
            pkDest->m_pKeys[i].SetText(self->m_pKeys[i].GetText());
        }
    }
    else
    {
        pkDest->m_pKeys = 0;
    }
}

struct BsStream
{
    unsigned int unk00;
    unsigned int m_uiPosition;
    unsigned int(__cdecl* m_pfnRead)(BsStream* pSelf, unsigned int* pCount, unsigned int uiSize, unsigned int* pSize,
                                     unsigned int uiFlags);
};

// @fnv 0x00a46e00
void __fastcall LoadTextKeys(NiTextKeyExtraData* self, void*, NiStream& stream)
{
    self->NiExtraData::LoadBinary(stream);

    BsStream* pStream = reinterpret_cast<BsStream*&>(stream.m_pkIstr);
    unsigned int uiNumKeys;
    {
        unsigned int uiSize = 4;
        pStream->m_uiPosition += pStream->m_pfnRead(pStream, &uiNumKeys, 4, &uiSize, 1);
    }

    if (uiNumKeys > 0)
    {
        TimedTextEntry* keys = new TimedTextEntry[uiNumKeys];
        for (unsigned int i = 0; i < uiNumKeys; i++)
        {
            keys[i].FUN_00a578d0(stream);
        }
        self->m_uiNumKeys = uiNumKeys;
        self->m_pKeys = keys;
    }
}
