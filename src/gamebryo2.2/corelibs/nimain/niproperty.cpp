// gamebryo2.2/corelibs/nimain/niproperty.cpp: NiProperty (3 functions)

#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"

// The shared declaration does not expose the stream position or callbacks.
template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, &value, sizeof(T), &size, 1);
}

// Accessors for the stream's opaque fields retain the original layout.
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline void NiStream::SetLastNiTimeControllerFlags(unsigned short flags)
{
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x288) = flags;
}

// @fnv 0x00a5d7f0
void NiProperty::LoadBinary(NiStream& stream)
{
    NiObjectNET::LoadBinary(stream);

    if (stream.GetFileVersion() < 0x0a000102)
    {
        // Pre-10.0.1.2 files carry the block's property flags in the stream.
        unsigned short usPropertyFlags;
        stream.GetBinaryStream()->Read(usPropertyFlags);
        stream.SetLastNiTimeControllerFlags(usPropertyFlags);
    }
}

struct PropHack00a5d7c0
{
    char _pad[12];
    NiTimeController* m_pControllers;
    void UpdateControllerChain(NiUpdateData& UpdateData);
};
// @fnv 0x00a5d7c0
void PropHack00a5d7c0::UpdateControllerChain(NiUpdateData& UpdateData)
{
    NiTimeController* pkControl = m_pControllers;
    while (pkControl)
    {
        pkControl->Update(UpdateData);
        pkControl = pkControl->m_spNextController.m_pObject;
    }
}

inline unsigned short StrArr::GetSize() const
{
    return m_usSize;
}
inline unsigned short StrArr::GetMaxSize() const
{
    return m_usMaxSize;
}
inline unsigned short StrArr::GetGrowBy() const
{
    return m_usGrowBy;
}
struct FUN_00a62a40_this
{
    void NiObjectNET_GetViewerStrings(StrArr*);
    void AppendString(StrArr*);
};
extern char const* const g_011f4408_arg1;
char* __cdecl _FUN_00a7d330(char const*);
// Appends the string returned by _FUN_00a7d330(g_011f4408_arg1) to pkStrings, growing the array if it is full.
// @fnv 0x00a5d850
void FUN_00a62a40_this::AppendString(StrArr* pkStrings)
{
    NiObjectNET_GetViewerStrings(pkStrings);
    char* pcStr = _FUN_00a7d330(g_011f4408_arg1);
    unsigned int uiSize = static_cast<const StrArr*>(pkStrings)->GetSize();
    if (uiSize >= pkStrings->GetMaxSize())
        pkStrings->SetSize(uiSize + pkStrings->GetGrowBy());
    pkStrings->SetAt(uiSize, pcStr);
}
