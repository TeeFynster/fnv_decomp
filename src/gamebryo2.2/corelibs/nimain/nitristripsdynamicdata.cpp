#include "../../../../include/NiTArray.h"

// src/gamebryo2.2/corelibs/nimain/nitristripsdynamicdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nitristripsdynamicdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiTriStripsData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiRTTI.h"

inline void* operator new(unsigned int, void* pointer)
{
    return pointer;
}

struct NiTriStripsDynamicData : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void GetStripData_00a923c0(unsigned short& usStrips, const unsigned short*& pusStripLengths,
                      const unsigned short*& pusTriList, unsigned int& uiStripLengthSum);
};

// @fnv 0x00a923c0
// src: XBOX_PDB 0x00a923c0
void NiTriStripsDynamicData::GetStripData_00a923c0(unsigned short& usStrips, const unsigned short*& pusStripLengths,
                                          const unsigned short*& pusTriList, unsigned int& uiStripLengthSum)
{
    usStrips = 1;
    pusStripLengths = m_pusStripLengths;
    pusTriList = m_pusStripLists;
    uiStripLengthSum = m_usActiveTriangles + 2;
}

namespace fnv_00a92430 {
struct NiTriStripsDynamicData : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    bool IsEqualDynamic(NiObject* pkObject);
};

// Compares this dynamic strips data with pkObject: true if IsEqual and both active vertex and triangle counts match.
// @fnv 0x00a92430
bool NiTriStripsDynamicData::IsEqualDynamic(NiObject* pkObject)
{
    NiTriStripsDynamicData* pkData = (NiTriStripsDynamicData*)pkObject;
    if (NiTriStripsData::IsEqual(pkData))
    {
        if (m_usActiveVertices == pkData->m_usActiveVertices && m_usActiveTriangles == pkData->m_usActiveTriangles)
            return true;
    }
    return false;
}
}  // namespace fnv_00a92430

extern "C" void* g_011f5e8c;

// @fnv 0x00a92470
// src: COMMUNITY 0x00a92470
void* __cdecl NiTriStripsDynamicData_GetRTTI()
{
    return &g_011f5e8c;
}

struct FUN_00a92480_shell : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void __thiscall NiTriStripsDynamicData_SetActiveVertexCount(short value);
};

// @fnv 0x00a92480
// src: XBOX_PDB 0x00a92480
void __thiscall FUN_00a92480_shell::NiTriStripsDynamicData_SetActiveVertexCount(short value)
{
    m_usActiveVertices = value;
}

extern int DAT_0109fc54;

// Allocates the dynamic strips data, constructs its shared base, initializes the active counts and vtable, and returns it or null.
// @fnv 0x00a923f0
// src: EXE 0x00a923f0
void* __cdecl NiTriStripsDynamicData_CreateObject()
{
    void* pNode = BSFadeNode::operator new(0x54);
    if (pNode)
    {
        char* pBytes = (char*)pNode;
        ::new (pBytes) NiTriStripsData;
        *(unsigned short*)(pBytes + 0x50) = 0;
        *(int*)pBytes = (int)&DAT_0109fc54;
        *(unsigned short*)(pBytes + 0x52) = 0;
        return pNode;
    }
    return 0;
}

struct FUN_00a92490_shell : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void __thiscall SetShortValue(short value);
};

// @fnv 0x00a92490
void __thiscall FUN_00a92490_shell::SetShortValue(short value)
{
    m_usActiveTriangles = value;
    if (m_usStrips)
        m_pusStripLengths[0] = value;
}

struct FUN_00a92340 : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    FUN_00a92340(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6,
                 unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10, unsigned int a11,
                 unsigned short a12, unsigned short a13);
};
// Initializes the base class with the given arguments and stores the active vertex and triangle counts.
// @fnv 0x00a92340
FUN_00a92340::FUN_00a92340(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5,
                           unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9, unsigned int a10,
                           unsigned int a11, unsigned short ausActiveVertices, unsigned short ausActiveTriangles)
    : NiTriStripsData(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11), m_usActiveVertices(ausActiveVertices)
{
    m_usActiveTriangles = ausActiveTriangles;
}

struct Standin00a761a0 : NiTriStripsData
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Destroys the strips base, optionally frees this, and returns this.
// @fnv 0x00a924b0
void* __thiscall Standin00a761a0::DestroyIfFlagged(unsigned int auiFlags)
{
    NiTriStripsData::~NiTriStripsData();
    if (auiFlags & 1)
        _delete(this, 0x54);
    return this;
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int totalBytes,
                                                unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = (*(NIBINARYSTREAM_READFN*)((char*)this + 8))(
        this, buffer, totalBytes, componentSizes, componentCount);
    *(unsigned int*)((char*)this + 4) += bytesRead;
    return bytesRead;
}

template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int size = sizeof(T);
    BinaryRead(&value, sizeof(T), &size, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStream* input = *(NiBinaryStream**)((char*)&stream + 0x24c);
    input->Read(value);
}

struct DynStripsData : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void NiTriStripsDynamicData_LoadBinary(NiStream& stream);
};

// Loads the base NiTriStripsData from the stream, then reads the active vertex and triangle counts.
// @fnv 0x00a924d0
// src: XBOX_PDB 0x00a924d0
void DynStripsData::NiTriStripsDynamicData_LoadBinary(NiStream& stream)
{
    NiTriStripsData::LoadBinary(stream);
    ReadBinaryValue(stream, m_usActiveVertices);
    ReadBinaryValue(stream, m_usActiveTriangles);
}

inline const char* NiRTTI::GetName() const
{
    return m_pcName;
}

template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > A92590StringArray;

extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcText);
char* __cdecl NiGetViewerString_00a7d490(const char* pcPrefix, unsigned short usValue);

struct A92590TriShapeData : NiTriStripsData
{
    static const NiRTTI ms_kRTTI;

    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;

    // The shared base has no viewer overload for this local string-array type.
    void GetBaseViewerStrings(A92590StringArray* pkStrings);
    void NiTriStripsDynamicData_GetViewerStrings(A92590StringArray* pkStrings);
};

// Appends the RTTI name and the active vertex and triangle counts to the viewer string array.
// @fnv 0x00a92590
// src: XBOX_PDB 0x00a92590
void A92590TriShapeData::NiTriStripsDynamicData_GetViewerStrings(A92590StringArray* pkStrings)
{
    GetBaseViewerStrings(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(ms_kRTTI.GetName());
    pkStrings->Add(pcString);
    pcString = NiGetViewerString_00a7d490("m_usActiveVertices", m_usActiveVertices);
    pkStrings->Add(pcString);
    pcString = NiGetViewerString_00a7d490("m_usActiveTriangles", m_usActiveTriangles);
    pkStrings->Add(pcString);
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int totalBytes,
                                                 unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesWritten = (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0xc))(
        this, buffer, totalBytes, componentSizes, componentCount);
    *(unsigned int*)((char*)this + 4) += bytesWritten;
    return bytesWritten;
}

// Dynamic strip data: base SaveBinary is 0x00a76340, active counts are at +0x50/+0x52; NiTriStrips derives NiTriBasedGeom.
struct DynamicStripCountWriter : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    void __thiscall NiTriStripsDynamicData_SaveBinary(void*);
};

// @fnv 0x00a92530
// src: XBOX_PDB 0x00a92530
void __thiscall DynamicStripCountWriter::NiTriStripsDynamicData_SaveBinary(void* stream)
{
    NiTriStripsData::SaveBinary(*(NiStream*)stream);
    NiBinaryStream* pBuffer = *(NiBinaryStream**)((char*)stream + 0x250);
    {
        // The by-value parameter's stack slot is dead here, so MSVC reuses it
        // for this address-taken local - that is where the original's
        // "mov dword ptr [esp+0x24], 2" lands.
        unsigned int count = 2;
        pBuffer->BinaryWrite(&m_usActiveVertices, 2, &count, 1);
    }
    pBuffer = *(NiBinaryStream**)((char*)stream + 0x250);
    {
        unsigned int count = 2;
        pBuffer->BinaryWrite(&m_usActiveTriangles, 2, &count, 1);
    }
}

struct TriStrips_A923B0 : NiTriStripsData
{
    unsigned short m_usActiveVertices;
    unsigned short m_usActiveTriangles;
    unsigned short NiTriStripsDynamicData_GetActiveTriangleCount() const;
};
// @fnv 0x00a923b0
// src: XBOX_PDB 0x00a923b0
unsigned short TriStrips_A923B0::NiTriStripsDynamicData_GetActiveTriangleCount() const
{
    return m_usActiveTriangles;
}
