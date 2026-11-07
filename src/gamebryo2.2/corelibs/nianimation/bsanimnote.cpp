#include "../../../../include/BSAnimNote.h"
#include "../../../../include/BSAnimNotes.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/bsanimnote.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsanimnote.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f00;

// @fnv 0x00a44920
// src: COMMUNITY 0x00a44920
void* __cdecl BSAnimNotes_GetRTTI()
{
    return &g_011f3f00;
}

struct TimedTextEntry
{
    float m_fTime;
};

// @fnv 0x00a44930
bool __thiscall BSAnimNote::vf35(const TimedTextEntry* apTextKey)
{
    fTime = apTextKey->m_fTime;
    return true;
}

extern int DAT_01097dd4;
inline void* operator new(unsigned int, void* storage) { return storage; }

// Allocates a 0x10-byte BSFadeNode, calls Init on it, sets its vtable to DAT_01097dd4, and returns the pointer or 0.
// @fnv 0x00a44940
// src: EXE 0x00a44940
void* __cdecl BSAnimNotes_CreateObject()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        ::new (p) NiObject;
        *(void**)(p) = &DAT_01097dd4;
        return p;
    }
    return 0;
}

bool __stdcall IsSameAs(NiObject*);

// Returns true if apObject passes IsSameAs and its eType and fTime equal this object's eType and fTime.
// @fnv 0x00a44880
bool __fastcall AnimNoteMatches(BSAnimNote* self, void*, NiObject* apObject)
{
    if (IsSameAs(apObject))
    {
        if (*(int*)self->unk08 == *(int*)((BSAnimNote*)apObject)->unk08)
        {
            if (self->fTime == ((BSAnimNote*)apObject)->fTime)
                return true;
        }
    }
    return false;
}

// @fnv 0x00a448c0
bool __thiscall BSAnimNotes::RegisterStreamables(NiStream& arStream)
{
    bool bret = true;
    int i;
    if (!NiObject::RegisterStreamables(arStream))
        bret = false;
    for (i = 0; i < m_usNumAnimNotes && bret; i++)
        bret = m_ppNotes[i]->RegisterStreamables(arStream);
    return bret;
}

extern MemoryManager g_memoryManager;

// Releases the stored object array: deletes each NiRefObject element, deallocates the array, then destroys the base NiRefObject.
// @fnv 0x00a44970
void BSAnimNotes::Destroy()
{
    *(void**)this = (void*)&DAT_01097dd4;
    for (unsigned int i = 0; i < m_usNumAnimNotes; ++i)
    {
        NiRefObject* p = m_ppNotes[i];
        if (p)
            delete p;
    }
    g_memoryManager.Deallocate(m_ppNotes);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}

void __cdecl _delete(void*, unsigned int);
// Calls Destroy, then deletes this with size 0x10 when bit 0 of a1 is set, and returns this.
// @fnv 0x00a44a10
void* BSAnimNotes::DestroyIfFlagged(unsigned int auiFlags)
{
    Destroy();
    if (auiFlags & 1)
        _delete(this, 0x10);
    return this;
}

// FUN_00a84c70 - forwards its single argument to the helper and reports the
// helper's byte sized result as a bool.
//
// Original body (18 bytes):
//   mov eax, dword ptr [esp + 4]
//   push eax
//   call  <helper>
//   test al, al
//   setne al
//   ret 4
//
// The helper is declared here with a byte sized result because the original
// only inspects AL.

extern "C" unsigned char __stdcall MyHelper00a5d2f0(void* pObject);

// @fnv 0x00a84c70
// src: XBOX_PDB 0x00a84c70
bool __stdcall BSAnimNote_RegisterStreamables(void* pObject)
{
    return MyHelper00a5d2f0(pObject);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);

// Links the base object from the stream, then fills self->m_ppNotes with objects from the stream and increments each one's ref count.
// @fnv 0x00a449c0
void __fastcall LinkAnimNotes(BSAnimNotes* self, void*, NiStream& kStream)
{
    self->NiObject::LinkObject(kStream);
    for (int i = 0; i < self->m_usNumAnimNotes; i++)
    {
        self->m_ppNotes[i] = kStream.GetLoadedObject();
        InterlockedIncrement((volatile long*)&self->m_ppNotes[i]->m_uiRefCount);
    }
}

// LoadBinary: read the child count, allocate the child pointer array, and read one link id per child.

extern MemoryManager g_kA4AF0MemoryManager;

inline void* __cdecl operator new[](unsigned int uiSize)
{
    return g_kA4AF0MemoryManager.Allocate(uiSize);
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void A4AF0LoadBinary(NiBinaryStream& kStream, T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&rValue, sizeof(T), &uiSize, 1);
}

// @fnv 0x00a44af0
void __fastcall LoadAnimNotes(BSAnimNotes* self, void*, NiStream& kStream)
{
    self->NiObject::LoadBinary(kStream);

    A4AF0LoadBinary(*kStream.m_pkIstr, self->m_usNumAnimNotes);
    if (self->m_usNumAnimNotes > 0)
        self->m_ppNotes = new NiObject*[self->m_usNumAnimNotes];

    for (int i = 0; i < self->m_usNumAnimNotes; i++)
        kStream.ResetStreamState();
}

// GetViewerStrings for an animation note: base strings, the time, and the note type.

class C4BF0StringArray
{
  public:
    virtual ~C4BF0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl C4BF0GetViewerString(const char* pcPrefix, float fValue);
char* __cdecl C4BF0GetViewerString(const char* pcPrefix, const char* pcValue);

// @fnv 0x00a44bf0
void BSAnimNote::GetViewerStrings(NiViewerStringsArray* apStrings)
{
    C4BF0StringArray* pkStrings = reinterpret_cast<C4BF0StringArray*>(apStrings);
    BaseGetViewerStrings(apStrings);
    pkStrings->Add(C4BF0GetViewerString("Time", fTime));
    switch (*(int*)unk08)
    {
    case 1:
        pkStrings->Add(C4BF0GetViewerString("Type", "GrabIK"));
        break;
    }
    pkStrings->Add(C4BF0GetViewerString("Type", "AnimNote"));
}

void __cdecl AppendCameraPathEntries();

// @fnv 0x00a44910
// src: XBOX_PDB 0x00a44910
void __cdecl BSAnimNotes_GetViewerStrings()
{
    AppendCameraPathEntries();
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesWritten;
    return uiBytesWritten;
}

template <class T> inline void NiBinaryStreamSave(NiBinaryStream& os, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    os.BinaryWrite(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> inline void WriteBinaryValue(NiStream& kStream, const T& value)
{
    NiBinaryStreamSave(*kStream.m_pkOstr, &value, 1);
}

// Calls the base routine, then writes the note type and time to the output stream.
// @fnv 0x00a44a90
void __fastcall LinkAnimNote(BSAnimNote* self, void*, NiStream& kStream)
{
    self->NiObject::LinkObject(kStream);
    WriteBinaryValue(kStream, *(int*)self->unk08);
    WriteBinaryValue(kStream, self->fTime);
}

template <class T> inline void B80SaveBinary(NiBinaryStream& kStream, const T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&rValue, sizeof(T), &uiSize, 1);
}

// Saves the B80Notes object by calling the base B80Object save, writing self->m_usNumAnimNotes, and saving each NiObject link ID in self->m_ppNotes.
// @fnv 0x00a44b80
void __fastcall SaveAnimNotes(BSAnimNotes* self, void*, NiStream& kStream)
{
    self->NiObject::LinkObject(kStream);
    B80SaveBinary(*kStream.m_pkOstr, self->m_usNumAnimNotes);
    for (unsigned int i = 0; i < self->m_usNumAnimNotes; i++)
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(self->m_ppNotes[i]));
}

template <class T> inline void StreamLoadBinary(NiBinaryStream& bs, T& val)
{
    unsigned int uiSize = sizeof(T);
    bs.BinaryRead(&val, sizeof(T), &uiSize, 1);
}

// Reads a group from the load stream, then binary-reads two unsigned int fields (unk08, unk0C) into the object.
// @fnv 0x00a44a30
void __fastcall LoadAnimNote(BSAnimNote* self, void*, NiStream* apLoadStream)
{
    self->NiObject::LoadBinary(*apLoadStream);
    StreamLoadBinary(*apLoadStream->m_pkIstr, *(unsigned int*)self->unk08);
    StreamLoadBinary(*apLoadStream->m_pkIstr, self->fTime);
}

