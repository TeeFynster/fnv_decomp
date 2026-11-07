// gamebryo2.2/corelibs/nimain/niscreenelementsdata.cpp: NiScreenElementsData (10 functions)

#include "PointStorage.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiPoint2.h"
#include "../../../../include/NiScreenElementsData.h"
#include "../../../../include/NiTriBasedGeomData.h"
#include "../../../../include/NiTriShapeData.h"
#include "niscreenelementsdata_decls.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"

// The shared class declares these methods; retain their inline stream operations here.
inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 0x8))(
        this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x4) += uiBytesRead;
    return uiBytesRead;
}

inline unsigned int NiBinaryStream::Write(const void* pvBuffer, unsigned int uiBytes,
                                          unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiWritten = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 0xc))(
        this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x4) += uiWritten;
    return uiWritten;
}

inline NiPoint3* NiGeometryData::GetVertices()
{
    return m_pkVertex;
}

// @fnv 0x00a88020
bool NiScreenElementsData::SetRectangle(int iPolygon, float fLeft, float fTop, float afWidth, float afHeight)
{
    if (iPolygon < 0 || iPolygon >= m_usMaxPQuantity)
        return false;
    unsigned short usIndex = m_ausPIndexer[iPolygon];
    if (usIndex == 0xFFFF)
        return false;
    NiScreenElementsData__Polygon& kPolygon = m_akPolygon[usIndex];
    if (kPolygon.m_usVertexCount != 4)
        return false;
    unsigned int i = kPolygon.m_usVertexOffset;
    float fRight = fLeft + afWidth;
    float fBottom = fTop + afHeight;
    GetVertices()[i].x = fLeft;
    GetVertices()[i].y = fTop;
    GetVertices()[i].z = 0.0f;
    ++i;
    GetVertices()[i].x = fLeft;
    GetVertices()[i].y = fBottom;
    GetVertices()[i].z = 0.0f;
    ++i;
    GetVertices()[i].x = fRight;
    GetVertices()[i].y = fBottom;
    GetVertices()[i].z = 0.0f;
    ++i;
    GetVertices()[i].x = fRight;
    GetVertices()[i].y = fTop;
    GetVertices()[i].z = 0.0f;
    SetDirtyFlags(1);
    m_bGeometryInitialized = true;
    return true;
}

// @fnv 0x00a88130
bool NiScreenElementsData::SetRectangleBounds(int iPolygonIndex, unsigned short usTextureSetIndex, float fLeft,
                                              float fTop, float fRight, float fBottom)
{
    if (m_pkTexture && iPolygonIndex >= 0 && iPolygonIndex < m_usMaxPQuantity)
    {
        unsigned short usIndex = m_ausPIndexer[iPolygonIndex];
        if (usIndex != 0xFFFF)
        {
            NiScreenElementsData__Polygon& kPolygon = m_akPolygon[usIndex];
            if (kPolygon.m_usVertexCount == 4 && usTextureSetIndex < (unsigned short)(m_usDataFlags & 1))
            {
                NiPoint2* pkTexture = NiGeometryData_GetTextureSet(usTextureSetIndex) + kPolygon.m_usVertexOffset;
                pkTexture[0].x = fLeft;
                pkTexture[0].y = fTop;
                pkTexture[1].x = fLeft;
                pkTexture[1].y = fBottom;
                pkTexture[2].x = fRight;
                pkTexture[2].y = fBottom;
                pkTexture[3].x = fRight;
                pkTexture[3].y = fTop;
                SetDirtyFlags(8);
                return true;
            }
        }
    }
    return false;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5b50;

// @fnv 0x00a87a90
// src: COMMUNITY 0x00a87a90
GlobalObjectO2_00a7b610* __cdecl NiScreenElementsData_GetRTTI()
{
    return &g_011f5b50;
}

void __fastcall FUN_00a7b8c0(void*);
void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109ea94;
// Scalar-deleting entry point: the shared layout supplies the members and object size.
// An unused EDX argument preserves the original ECX object and stack-argument ABI.
// @fnv 0x00a87aa0
void* __fastcall DestroyScreenElementsData(NiScreenElementsData* data, void*, unsigned int auiFlags)
{
    void* p = data->m_akPolygon;
    *reinterpret_cast<void**>(data) = &DAT_0109ea94;
    _NiFreeAlias(p);
    _NiFreeAlias(data->m_ausPIndexer);
    FUN_00a7b8c0(data);
    if (auiFlags & 1)
        _delete(data, sizeof(NiScreenElementsData));
    return data;
}

// The shared NiTriShapeData declaration lacks its viewer-string override.
// This member-only adapter supplies that call without duplicating its layout.
struct TriShapeViewerStrings : NiTriShapeData
{
    void AppendViewerStrings(NiViewerStringsArray*);
};

char* __cdecl _FUN_00a7d330(void*);
char* __cdecl NiGetViewerString_00a7d490(char const*, unsigned short);
char* __cdecl NiGetViewerString_00a7d5a0(char const*, void*);

// Appends the object's member names and values to the string array, growing it as needed via SetSize and SetAt.
// @fnv 0x00a886f0
void NiScreenElementsData::GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    StrArr* strings = reinterpret_cast<StrArr*>(pkStrings);
    char* value;
    unsigned int index;

    static_cast<TriShapeViewerStrings*>(static_cast<NiTriShapeData*>(this))->AppendViewerStrings(pkStrings);

    value = _FUN_00a7d330(*reinterpret_cast<void**>(&g_011f5b50));
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d5a0("m_akPolygon", this->m_akPolygon);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d5a0("m_ausPIndexer", this->m_ausPIndexer);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usMaxPQuantity", this->m_usMaxPQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usPGrowBy", this->m_usPGrowBy);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usPQuantity", this->m_usPQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usMaxVQuantity", this->m_usMaxVQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usVGrowBy", this->m_usVGrowBy);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usMaxIQuantity", this->m_usMaxIQuantity);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d490("m_usIGrowBy", this->m_usIGrowBy);
    index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);
}

inline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR;
    g = fG;
    b = fB;
    a = fA;
}

extern void* __cdecl _NiMalloc_00aa1070(unsigned int);
extern void __cdecl _NiFree_00aa10f0(void*);
extern void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
extern void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct NiMemorySystem
{
    void* Game_DoHeapAlloc(unsigned int);
    void MemoryManager_Deallocate(void*);
};
extern NiMemorySystem g_011f6238;

inline void* __cdecl operator new[](unsigned int n)
{
    return g_011f6238.Game_DoHeapAlloc(n);
}
inline void* NiPoint2::operator new[](size_t n)
{
    return g_011f6238.Game_DoHeapAlloc(n);
}
inline void __cdecl operator delete[](void* p)
{
    g_011f6238.MemoryManager_Deallocate(p);
}

extern const NiPoint3 DAT_011a9484;


// The shared insertion declaration uses a different parameter and return signature.
struct ScreenPolygonInsertion : NiScreenElementsData
{
    unsigned int InsertPolygon(unsigned short, unsigned short, const unsigned short*);
};

// @fnv 0x00a87ae0
unsigned int ScreenPolygonInsertion::InsertPolygon(unsigned short usVertexCount, unsigned short usTriangleCount,
                                                   const unsigned short* pusTriangleList)
{
    if (usVertexCount < 3)
        return 0xffffffff;

    if (usTriangleCount > 0)
    {
        if (!pusTriangleList)
            return 0xffffffff;
    }
    if (usTriangleCount == 0)
    {
        usTriangleCount = usVertexCount - 2;
    }

    unsigned short usPolygonIndex;
    usPolygonIndex = m_usPQuantity++;
    if (m_usPQuantity > m_usMaxPQuantity)
    {
        unsigned short usNewMaxPolygons = m_usMaxPQuantity + m_usPGrowBy;
        NiScreenElementsData__Polygon* pkNewPolygons =
            (NiScreenElementsData__Polygon*)_NiMalloc_00aa1070(usNewMaxPolygons * sizeof(NiScreenElementsData__Polygon));
        FUN_00ec44d0(pkNewPolygons, m_akPolygon, m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon));
        _NiFree_00aa10f0(m_akPolygon);
        m_akPolygon = pkNewPolygons;

        unsigned short* pusNewIndexer = (unsigned short*)_NiMalloc_00aa1070(usNewMaxPolygons * sizeof(unsigned short));
        FUN_00ec44d0(pusNewIndexer, m_ausPIndexer, m_usMaxPQuantity * sizeof(unsigned short));
        FUN_00ec61c0(pusNewIndexer + m_usMaxPQuantity, 0xff,
                     (usNewMaxPolygons - m_usMaxPQuantity) * sizeof(unsigned short));
        _NiFree_00aa10f0(m_ausPIndexer);
        m_ausPIndexer = pusNewIndexer;
        m_usMaxPQuantity = usNewMaxPolygons;
    }

    NiScreenElementsData__Polygon* pkPolygon = &m_akPolygon[usPolygonIndex];
    pkPolygon->m_usVertexCount = usVertexCount;
    pkPolygon->m_usVertexOffset = m_usVertices;
    pkPolygon->m_usTriangleCount = usTriangleCount;
    pkPolygon->m_usTriangleIndexOffset = 3 * m_usTriangles;

    for (unsigned short i = 0; i < m_usPQuantity; i++)
    {
        if (m_ausPIndexer[i] == 0xffff)
        {
            m_ausPIndexer[i] = usPolygonIndex;
            usPolygonIndex = i;
            break;
        }
    }

    m_usVertices += pkPolygon->m_usVertexCount;
    int iVertexExcess = m_usVertices - m_usMaxVQuantity;
    if (iVertexExcess > 0)
    {
        float z;
        z = (float)iVertexExcess / (float)m_usVGrowBy;
        unsigned short usGrowCount = (unsigned short)(z + 0.5);
        unsigned short usNewMaxVertices = (usGrowCount + 1) * m_usVGrowBy + m_usMaxVQuantity;

        NiPoint3* akNewPolygon = reinterpret_cast<NiPoint3*>(new PointStorage[usNewMaxVertices]);
        unsigned int uiVertexBytes = m_usMaxVQuantity * sizeof(NiPoint3);
        FUN_00ec44d0(akNewPolygon, m_pkVertex, uiVertexBytes);
        delete[] m_pkVertex;
        m_pkVertex = akNewPolygon;

        if (m_pkNormal)
        {
            NiPoint3* y = reinterpret_cast<NiPoint3*>(new PointStorage[usNewMaxVertices]);
            FUN_00ec44d0(y, m_pkNormal, uiVertexBytes);
            delete[] m_pkNormal;
            m_pkNormal = y;
            for (unsigned short i = m_usMaxVQuantity; i < usNewMaxVertices; i++)
            {
                PointStorage a;
                a.x = -DAT_011a9484.x;
                a.y = -DAT_011a9484.y;
                a.z = -DAT_011a9484.z;
                m_pkNormal[i] = reinterpret_cast<NiPoint3&>(a);
            }
        }

        if (m_pkColor)
        {
            NiColorA* pkNewColors;
            pkNewColors = new NiColorA[usNewMaxVertices];
            FUN_00ec44d0(pkNewColors, m_pkColor, m_usMaxVQuantity * sizeof(NiColorA));
            delete[] m_pkColor;
            m_pkColor = pkNewColors;
        }

        unsigned short usTextureSetCount = m_usDataFlags & 1;
        if (usTextureSetCount > 0)
        {
            NiPoint2* newTextures = new NiPoint2[usTextureSetCount * usNewMaxVertices];
            unsigned int uiTextureBytes = m_usMaxVQuantity * sizeof(NiPoint2);
            for (unsigned short i = 0; i < usTextureSetCount; i++)
            {
                FUN_00ec44d0(newTextures + i * m_usVertices, m_pkTexture + i * m_usVertices, uiTextureBytes);
            }
            delete[] m_pkTexture;
            m_pkTexture = newTextures;
        }

        m_usMaxVQuantity = usNewMaxVertices;
    }

    m_usTriangles += usTriangleCount;
    m_uiTriListLength += 3 * usTriangleCount;
    int idx;
    idx = 3 * m_usTriangles - m_usMaxIQuantity;
    if (idx > 0)
    {
        float fIndexGrowCount = (float)idx / (float)m_usIGrowBy;
        unsigned short usIndexGrowCount = (unsigned short)(fIndexGrowCount + 0.5);
        unsigned short usNewMaxIndices = (usIndexGrowCount + 1) * m_usIGrowBy + m_usMaxIQuantity;

        unsigned short* pusNewTriList = (unsigned short*)_NiMalloc_00aa1070(usNewMaxIndices * sizeof(unsigned short));
        FUN_00ec44d0(pusNewTriList, m_pusTriList, m_usMaxIQuantity * sizeof(unsigned short));
        _NiFree_00aa10f0(m_pusTriList);
        m_pusTriList = pusNewTriList;
        m_usMaxIQuantity = usNewMaxIndices;
    }

    unsigned short* pusTriListOut = &m_pusTriList[pkPolygon->m_usTriangleIndexOffset];
    if (pusTriangleList)
    {
        FUN_00ec44d0(pusTriListOut, pusTriangleList, 3 * (unsigned int)usTriangleCount * sizeof(unsigned short));
        for (unsigned int i = 0; i < 3 * (unsigned int)usTriangleCount; i++)
        {
            pusTriListOut[i] = pusTriangleList[i] + pkPolygon->m_usVertexOffset;
        }
    }
    else
    {
        for (unsigned short i = 0; i < usTriangleCount; i++)
        {
            *pusTriListOut++ = pkPolygon->m_usVertexOffset;
            *pusTriListOut++ = pkPolygon->m_usVertexOffset + i + 1;
            *pusTriListOut++ = i + pkPolygon->m_usVertexOffset + 2;
        }
    }

    SetDirtyFlags(1);
    return usPolygonIndex;
}

static inline NiPoint3 NegatePoint(const NiPoint3& p)
{
    NiPoint3 r;
    r.x = -p.x;
    r.y = -p.y;
    r.z = -p.z;
    return r;
}

// The shared base declares no default constructor; call the original base entry point.
void __fastcall InitializeTriShapeData(NiTriShapeData*);

// Allocates the screen-element arrays and clears their counts using the shared layout.
// The unused EDX argument preserves the original constructor calling convention.
// @fnv 0x00a881e0
NiScreenElementsData* __fastcall InitializeScreenElementsData(
    NiScreenElementsData* data, void*, bool bWantNormals, bool bWantColors, unsigned short usNumTextureSets,
    int iMaxPQuantity, int iPGrowBy, int iMaxVQuantity, int iVGrowBy, int iMaxTQuantity, int iTGrowBy)
{
    InitializeTriShapeData(data);
    *reinterpret_cast<void**>(data) = &DAT_0109ea94;

    data->m_usMaxPQuantity = (unsigned short)(iMaxPQuantity > 0 ? iMaxPQuantity : 1);
    data->m_usPGrowBy = (unsigned short)(iPGrowBy > 0 ? iPGrowBy : 1);
    data->m_usPQuantity = 0;
    data->m_akPolygon =
        (NiScreenElementsData__Polygon*)_NiMalloc_00aa1070(data->m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon));
    data->m_ausPIndexer = (unsigned short*)_NiMalloc_00aa1070(data->m_usMaxPQuantity * sizeof(unsigned short));
    FUN_00ec61c0(data->m_ausPIndexer, 0xff, data->m_usMaxPQuantity * sizeof(unsigned short));

    data->m_usMaxVQuantity = (unsigned short)(iMaxVQuantity > 0 ? iMaxVQuantity : 1);
    data->m_usVGrowBy = (unsigned short)(iVGrowBy > 0 ? iVGrowBy : 1);
    data->m_usVertices = 0;
    data->m_pkVertex = new NiPoint3[data->m_usMaxVQuantity];

    if (bWantNormals)
    {
        data->m_pkNormal = new NiPoint3[data->m_usMaxVQuantity];
        for (unsigned short i = 0; i < data->m_usMaxVQuantity; i++)
            data->m_pkNormal[i] = NegatePoint(DAT_011a9484);
    }
    else
    {
        data->m_pkNormal = 0;
    }

    data->m_pkColor = bWantColors ? new NiColorA[data->m_usMaxVQuantity] : 0;

    if (usNumTextureSets > 0)
    {
        data->m_pkTexture = new NiPoint2[data->m_usMaxVQuantity * usNumTextureSets];
        data->m_usDataFlags = (data->m_usDataFlags & ~1) | (usNumTextureSets & 1);
    }
    else
    {
        data->m_pkTexture = 0;
    }

    data->m_usMaxIQuantity = (unsigned short)(iMaxTQuantity > 0 ? 3 * iMaxTQuantity : 3);
    data->m_usIGrowBy = (unsigned short)(iTGrowBy > 0 ? 3 * iTGrowBy : 3);
    data->m_usTriangles = 0;
    data->m_uiTriListLength = 0;
    data->m_pusTriList = (unsigned short*)_NiMalloc_00aa1070(data->m_usMaxIQuantity * sizeof(unsigned short));
    data->m_bGeometryInitialized = false;
    return data;
}

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pkValue, unsigned int ItemUpdateArray)
{
    unsigned int uiSize = sizeof(T);
    pkStream->BinaryRead(pkValue, ItemUpdateArray * uiSize, &uiSize, 1);
}
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}
template <class T> inline void NiStreamLoadBinary(NiStream& kStream, T& kValue)
{
    NiBinaryStreamLoad(kStream.GetBinaryStream(), &kValue, 1);
}
template <class T> inline void NiStreamLoadBinary(NiStream& kStream, T* pkValue, unsigned int ItemUpdateArray)
{
    NiBinaryStreamLoad(kStream.GetBinaryStream(), pkValue, ItemUpdateArray);
}
void* __cdecl _NiMalloc_00aa1070(unsigned int bytes);
// @fnv 0x00a88410
void NiScreenElementsData::LoadBinary(NiStream& kStream)
{
    NiTriShapeData::LoadBinary(kStream);
    NiStreamLoadBinary(kStream, m_usMaxPQuantity);
    m_akPolygon = static_cast<NiScreenElementsData__Polygon*>(
        _NiMalloc_00aa1070(m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon)));
    m_ausPIndexer = static_cast<unsigned short*>(_NiMalloc_00aa1070(m_usMaxPQuantity * sizeof(unsigned short)));

    unsigned int uiPolygonCount = m_usMaxPQuantity;
    NiStreamLoadBinary(kStream, m_akPolygon, uiPolygonCount);
    NiStreamLoadBinary(kStream, m_ausPIndexer, uiPolygonCount);
    NiStreamLoadBinary(kStream, m_usPGrowBy);
    NiStreamLoadBinary(kStream, m_usPQuantity);
    NiStreamLoadBinary(kStream, m_usMaxVQuantity);
    NiStreamLoadBinary(kStream, m_usVGrowBy);
    NiStreamLoadBinary(kStream, m_usMaxIQuantity);
    NiStreamLoadBinary(kStream, m_usIGrowBy);
}

inline WriteStream* NiStream::GetWriter()
{
    return *reinterpret_cast<WriteStream**>(reinterpret_cast<char*>(this) + 0x250);
}
template <class T> inline void WriteBinaryArray(NiBinaryStream& kBinStream, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.Write(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T& kValue)
{
    WriteBinaryArray(*reinterpret_cast<NiBinaryStream*>(kStream.GetWriter()), &kValue, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T* pValue, unsigned int uiNumEls)
{
    WriteBinaryArray(*reinterpret_cast<NiBinaryStream*>(kStream.GetWriter()), pValue, uiNumEls);
}
// Writes the base screen elements data and the polygon, indexer and quantity fields to the binary stream.
// @fnv 0x00a88590
void NiScreenElementsData::SaveBinary(NiStream& kStream)
{
    NiTriShapeData::SaveBinary(kStream);
    SerializeValue(kStream, m_usMaxPQuantity);
    unsigned int uiPolygonCount = m_usMaxPQuantity;
    SerializeValue(kStream, m_akPolygon, uiPolygonCount);
    SerializeValue(kStream, m_ausPIndexer, uiPolygonCount);
    SerializeValue(kStream, m_usPGrowBy);
    SerializeValue(kStream, m_usPQuantity);
    SerializeValue(kStream, m_usMaxVQuantity);
    SerializeValue(kStream, m_usVGrowBy);
    SerializeValue(kStream, m_usMaxIQuantity);
    SerializeValue(kStream, m_usIGrowBy);
}

#include <string.h>
// Compares this NiScreenElementsData with pkOther, checking base equality, quantity fields, polygon data, and polygon index arrays.
// @fnv 0x00a87980
bool NiScreenElementsData::IsEqual(NiObject* object) const
{
    const NiScreenElementsData* pkOther = static_cast<const NiScreenElementsData*>(object);
    if (!const_cast<NiScreenElementsData*>(this)->NiTriShapeData::IsEqual_00a7b7e0(pkOther))
        return false;

    if (m_usMaxPQuantity != pkOther->m_usMaxPQuantity || m_usPGrowBy != pkOther->m_usPGrowBy ||
        m_usPQuantity != pkOther->m_usPQuantity || m_usMaxVQuantity != pkOther->m_usMaxVQuantity ||
        m_usVGrowBy != pkOther->m_usVGrowBy || m_usMaxIQuantity != pkOther->m_usMaxIQuantity ||
        m_usIGrowBy != pkOther->m_usIGrowBy)
        return false;

    if (memcmp(m_akPolygon, pkOther->m_akPolygon, m_usMaxPQuantity * sizeof(NiScreenElementsData__Polygon)) != 0)
        return false;

    if (memcmp(m_ausPIndexer, pkOther->m_ausPIndexer, m_usMaxPQuantity * sizeof(unsigned short)) != 0)
        return false;

    return true;
}
