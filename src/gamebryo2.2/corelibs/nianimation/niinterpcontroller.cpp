// gamebryo2.2/corelibs/nianimation/niinterpcontroller.cpp: NiInterpController and controller helpers (5 functions)

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiInterpController.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTimeController.h"
#include "niinterpcontroller_decls.h"
#include "../../../../include/StrArr.h"

inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes)
{
    unsigned int size = 1;
    unsigned int count = m_pfnRead(this, buffer, bytes, &size, 1);
    m_uiAbsoluteCurrentPos += count;
    return count;
}

// @fnv 0x00a2f910
void NiInterpController::LoadBinary(NiStream& stream)
{
    NiTimeController::LoadBinary(stream);
    if (stream.m_uiNifFileVersion >= 0x0a010068 && stream.m_uiNifFileVersion < 0x0a01006d)
    {
        bool value;
        stream.m_pkIstr->Read(&value, 1);
        if (value)
            m_uiObjectFlags |= 0x20;
        else
            m_uiObjectFlags &= ~0x20;
    }
}
// @fnv 0x00c9a6b0
void NiInterpController::LinkObject(NiStream& stream)
{
    NiTimeController::LinkObject(stream);
}
// @fnv 0x00c9a6c0
void NiInterpControllerTriple::ResetTriple()
{
    f0 = -1.0f;
    float v = 0.0f / g_d100;
    f1 = v;
    f2 = v;
}

class NiInterpControllerFlagCheck : public NiInterpController
{
  public:
    void ResetIfFlagClear();
};

// @fnv 0x00a2f8f0
void NiInterpControllerFlagCheck::ResetIfFlagClear()
{
    unsigned char value = (unsigned char)m_uiObjectFlags;
    for (int i = 0; i < 5; ++i)
        value = (unsigned char)(value >> 1);
    if (!(value & 1))
    {
        m_fLoKeyTime = 0.0f;
        m_fHiKeyTime = 0.0f;
    }
}

// The shared controller headers do not declare these viewer-string helpers.
// Inherit their storage from the shared controller instead of duplicating it.
struct NiTimeControllerViewerStrings : NiTimeController
{
    void WriteControllerStrings(StrArr*);
};
extern const char* g_011f36bc_arg1;
extern char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
extern "C" char* __cdecl NiGetViewerString(const char*, int);
struct NiInterpControllerViewerStrings : NiTimeControllerViewerStrings
{
    void WriteManagerControlledFlag(StrArr*);
};
// Calls the base writer, then appends a string and an "IsManagerControlled" entry derived from bit 5 of flags to the stream.
// @fnv 0x00a2f980
void NiInterpControllerViewerStrings::WriteManagerControlledFlag(StrArr* stream)
{
    WriteControllerStrings(stream);
    char* value = NiViewerStrings_NiGetViewerString_Title(g_011f36bc_arg1);
    unsigned int index = stream->m_usSize;
    if (index >= stream->m_usMaxSize)
    {
        stream->SetSize(stream->m_usGrowBy + index);
    }
    stream->SetAt(index, &value);
    *(unsigned char*)&value = (m_uiObjectFlags >> 5) & 1;
    value = NiGetViewerString("IsManagerControlled", *(int*)&value);
    index = stream->m_usSize;
    if (index >= stream->m_usMaxSize)
    {
        stream->SetSize(stream->m_usGrowBy + index);
    }
    stream->SetAt(index, &value);
}
