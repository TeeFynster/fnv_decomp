// gamebryo2.2/corelibs/nimain/nitrishapedata.cpp (17 functions)

#include "nitrishapedata_decls.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTriBasedGeomData.h"
#include "../../../../include/NiTriShapeData.h"
#include "../../../../include/StrArr.h"

void __fastcall FUN_00a7b8c0(void*);

#include "../../../../include/NiMemObject.h"

// Calls FUN_00a7b8c0 on pThis, then frees pThis with NiMemObject::operator delete when flags has bit 1 set, and returns pThis.
// @fnv 0x00a7b920
void* __fastcall FUN_00a7b920(void* pThis, int, unsigned int flags)
{
    FUN_00a7b8c0(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, 0x58);
    return pThis;
}

void __cdecl _NiFreeAlias(void*);

// Replaces the triangle list and updates the triangle and index counts.
// @fnv 0x00a7b6c0
// src: COMMUNITY 0x00a7b6c0
void __fastcall NiTriShapeData_Replace(NiTriShapeData* self, int, unsigned short ausValue, unsigned short* apusBuffer)
{
    if (apusBuffer != self->m_pusTriList && self->m_pusTriList)
        _NiFreeAlias(self->m_pusTriList);
    self->m_usTriangles = ausValue;
    self->m_pusTriList = apusBuffer;
    self->m_uiTriListLength = ausValue * 3;
}

// @fnv 0x00a7b700
// src: COMMUNITY 0x00a7b700
void __fastcall NiTriShapeData_SetData(NiTriShapeData* self, int, unsigned short ausValue, unsigned short* apusBuffer)
{
    self->m_usTriangles = ausValue;
    self->m_uiTriListLength = ausValue * 3;
    self->m_pusTriList = apusBuffer;
}

// Reads three consecutive unsigned shorts from self->m_pusTriList at offset i*3 and writes them to the three output pointers.
// @fnv 0x00a7b720
// src: XBOX_PDB 0x00a7b720
void __fastcall NiTriShapeData_GetTriangleIndices(NiTriShapeData* self, int, unsigned short i, unsigned short* i0, unsigned short* i1,
                             unsigned short* i2)
{
    unsigned int j = i * 3;
    *i0 = self->m_pusTriList[j];
    *i1 = self->m_pusTriList[j + 1];
    *i2 = self->m_pusTriList[j + 2];
}

// @fnv 0x00a7b760
// src: XBOX_PDB 0x00a7b760
void __fastcall NiTriShapeData_GetStripData(NiTriShapeData* self, int, unsigned short* p1, unsigned int* p2, unsigned short** p3,
                             unsigned int* p4)
{
    *p1 = self->m_usTriangles;
    *p2 = 0;
    *p3 = self->m_pusTriList;
    *p4 = self->m_usTriangles * 3;
}

extern const char* const g_011f5af4_arg1;

// @fnv 0x00a7b860
// src: COMMUNITY 0x00a7b860
const char* const* __fastcall NiTriShapeData_GetRTTI(void* self, int)
{
    return &g_011f5af4_arg1;
}

struct FUN_00a7b870_T
{
    short a;
    int b;
};

// @fnv 0x00a7b870
// src: GUESS 0x00a7b870 (confidence: medium)
FUN_00a7b870_T* __fastcall NiTriShapeData_ClearFields(FUN_00a7b870_T* self, int)
{
    self->a = 0;
    self->b = 0;
    return self;
}

void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;

struct Blk
{
    void* data;
    char pad[0xc];
    Blk* next;
    Blk* FreeBlock(unsigned int flags);
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

// Frees data, recursively frees the next block, and deletes this block when flags has bit 0 set; returns this.
// @fnv 0x00a7b880
Blk* Blk::FreeBlock(unsigned int flags)
{
    _NiFreeAlias(data);
    if (next)
        next->FreeBlock(1);
    if (flags & 1)
        delete this;
    return this;
}

namespace fnv_00a7b8c0 {
void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern void* DAT_0109dac4[];

struct Blk
{
    void* data;
    char pad[0xc];
    Blk* next;
    Blk* FreeBlock(unsigned int flags);
    ~Blk()
    {
        _NiFreeAlias(data);
        if (next)
            next->FreeBlock(1);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

// Explicit cleanup preserves this entry point without adding C++ destructor unwind code.
void __fastcall DestroyTriBasedGeomData(NiTriBasedGeomData*);

// Releases triangle data and shared-normal storage, then destroys the base geometry data.
// @fnv 0x00a7b8c0
void __fastcall DestroyTriShapeData(NiTriShapeData* self)
{
    *(void**)self = DAT_0109dac4;
    if (self->m_pusTriList)
        _NiFreeAlias(self->m_pusTriList);
    if (self->m_pkSNAMemoryBlocks)
        delete reinterpret_cast<Blk*>(self->m_pkSNAMemoryBlocks);
    g_memoryManager.Deallocate(self->m_pkSharedNormals);
    DestroyTriBasedGeomData(self);
}
}  // namespace fnv_00a7b8c0

extern const char* const g_011f5af4_arg1;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);

inline void StrArr::AppendInline(char* e)
{
    unsigned int i = m_usSize;
    if (i >= m_usMaxSize)
        SetSize(i + m_usGrowBy);
    SetAt(i, e);
}

void __cdecl AppendTrianglesInfo();

// Appends the base entry, a formatted m_uiTriListLength value and a formatted m_pusTriList pointer to the StrArr.
// @fnv 0x00a7bd60
void __fastcall AppendTriListInfo(NiTriShapeData* self, int, StrArr* pStrArr)
{
    reinterpret_cast<void (__thiscall*)(NiTriBasedGeomData*, StrArr*)>(AppendTrianglesInfo)(self, pStrArr);
    pStrArr->AppendInline(NiViewerStrings_NiGetViewerString_Title(g_011f5af4_arg1));
    pStrArr->AppendInline(NiGetViewerString_00a7d510("m_uiTriListLength", self->m_uiTriListLength));
    pStrArr->AppendInline(NiGetViewerString_00a7d5a0("m_pusTriList", self->m_pusTriList));
}

inline void NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                        unsigned int uiComponentSize)
{
    m_uiAbsoluteCurrentPos += m_pfnWrite(this, pvBuffer, uiTotalBytes, &uiComponentSize, 1);
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void SaveBinS(NiStream* pkStream, const T& value)
{
    NiBinaryStream* pkOstr = pkStream->m_pkOstr;
    pkOstr->BinaryWrite(&value, sizeof(T), sizeof(T));
}

template <class T> inline void SaveBinArrS(NiStream* pkStream, const T* pValue, unsigned int ItemUpdateArray)
{
    unsigned int uiBytes = ItemUpdateArray * sizeof(T);
    NiBinaryStream* pkOstr = pkStream->m_pkOstr;
    pkOstr->BinaryWrite(pValue, uiBytes, sizeof(T));
}

struct SharedNormalArrayS
{
    unsigned short m_usSize;
    unsigned short* m_pusArray;
};

// Saves the triangle list length, its presence flag and data, then the shared-normal array sizes and entries to the stream.
// @fnv 0x00a7bbe0
void NiTriShapeData::SaveBinary(NiStream& stream)
{
    NiStream* kStream = &stream;
    NiTriBasedGeomData::SaveBinary(*kStream);
    unsigned int& uiTriListLength = m_uiTriListLength;
    unsigned short*& pusTriList = m_pusTriList;
    SharedNormalArrayS*& pkSharedNormals = reinterpret_cast<SharedNormalArrayS*&>(m_pkSharedNormals);
    unsigned short& usSharedSize = m_usSharedNormalsArraySize;

    SaveBinS(kStream, uiTriListLength);
    unsigned char bHasList = (pusTriList != 0);
    SaveBinS(kStream, bHasList);
    if (bHasList)
        SaveBinArrS(kStream, pusTriList, uiTriListLength);
    SaveBinS(kStream, usSharedSize);
    for (unsigned short usI = 0; usI < usSharedSize; usI++)
    {
        unsigned short m_usPassCountLocal = pkSharedNormals[usI].m_usSize;
        SaveBinS(kStream, m_usPassCountLocal);
        if (m_usPassCountLocal)
            SaveBinArrS(kStream, pkSharedNormals[usI].m_pusArray, m_usPassCountLocal);
    }
}

namespace fnv_00a7b940 {
void* NiMalloc(unsigned int) throw();
extern MemoryManager g_memoryManager;

struct FUN_00a7b870
{
    unsigned short m_usElementCount;
    unsigned short* m_pusArray;
    FUN_00a7b870() throw();
    static void* operator new[](unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    void SetArray(unsigned short m_usPassCountLocal, unsigned short* pusArray)
    {
        if (m_usPassCountLocal && pusArray)
        {
            m_usElementCount = m_usPassCountLocal;
            m_pusArray = pusArray;
        }
        else
        {
            m_usElementCount = 0;
            m_pusArray = 0;
        }
    }
};

struct IndexBufferBlock
{
    unsigned short* m_pIndices;
    unsigned short* m_pCurrentIndex;
    unsigned int m_uiIndexCapacity;
    unsigned int m_uiUsedIndexCount;
    IndexBufferBlock* m_pkNext;
    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    IndexBufferBlock(unsigned int uiSize)
    {
        m_pIndices = (unsigned short*)NiMalloc(uiSize * 2);
        m_pCurrentIndex = m_pIndices;
        m_uiIndexCapacity = uiSize;
        m_uiUsedIndexCount = uiSize;
        m_pkNext = 0;
    }
};

static inline NiBinaryStream* GetIstr(NiStream* kStream)
{
    return kStream->m_pkIstr;
}

template <class T> inline void ReadBinaryValue(NiBinaryStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, sizeof(T), &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

}  // namespace fnv_00a7b940

// Loads triangle data, then the shared-normal arrays allocated from a block pool.
// @fnv 0x00a7b940
void NiTriShapeData::LoadBinary(NiStream& stream)
{

    using namespace fnv_00a7b940;
    NiStream* kStream = &stream;
    NiTriBasedGeomData::LoadBinary(*kStream);

    ReadBinaryValue(*GetIstr(kStream), m_uiTriListLength);

    unsigned char bHasList;
    if (kStream->m_uiNifFileVersion >= 0x0A000111)
        ReadBinaryValue(*GetIstr(kStream), bHasList);
    else
        bHasList = 1;

    if (bHasList && m_uiTriListLength > 0)
    {
        m_pusTriList = (unsigned short*)fnv_00a7b940::NiMalloc(m_uiTriListLength * 2);
        ReadBinaryValue(*GetIstr(kStream), m_pusTriList, m_uiTriListLength);
    }

    ReadBinaryValue(*GetIstr(kStream), m_usSharedNormalsArraySize);
    if (m_usSharedNormalsArraySize)
    {
        reinterpret_cast<fnv_00a7b940::FUN_00a7b870*&>(m_pkSharedNormals) = new fnv_00a7b940::FUN_00a7b870[m_usSharedNormalsArraySize];
        reinterpret_cast<IndexBufferBlock*&>(m_pkSNAMemoryBlocks) = new IndexBufferBlock(m_usSharedNormalsArraySize);

        for (unsigned short usI = 0; usI < m_usSharedNormalsArraySize; usI++)
        {
            unsigned short m_usPassCountLocal;
            unsigned short* pusArray = 0;
            ReadBinaryValue(*GetIstr(kStream), m_usPassCountLocal);
            if (m_usPassCountLocal)
            {
                IndexBufferBlock* pkBlock = reinterpret_cast<IndexBufferBlock*&>(m_pkSNAMemoryBlocks);
                while (pkBlock)
                {
                    if (m_usPassCountLocal <= pkBlock->m_uiUsedIndexCount)
                        break;
                    pkBlock = pkBlock->m_pkNext;
                }
                if (!pkBlock)
                {
                    pkBlock = new IndexBufferBlock(reinterpret_cast<IndexBufferBlock*&>(m_pkSNAMemoryBlocks)->m_uiIndexCapacity * 2);
                    pkBlock->m_pkNext = reinterpret_cast<IndexBufferBlock*&>(m_pkSNAMemoryBlocks);
                    reinterpret_cast<IndexBufferBlock*&>(m_pkSNAMemoryBlocks) = pkBlock;
                }
                pusArray = pkBlock->m_pCurrentIndex;
                pkBlock->m_uiUsedIndexCount -= m_usPassCountLocal;
                pkBlock->m_pCurrentIndex += m_usPassCountLocal;
                ReadBinaryValue(*GetIstr(kStream), pusArray, m_usPassCountLocal);
            }
            reinterpret_cast<fnv_00a7b940::FUN_00a7b870*&>(m_pkSharedNormals)[usI].SetArray(m_usPassCountLocal, pusArray);
        }
    }
}

// Constructs the base geometry data, sets the triangle list length to 3*m_usTriangles, stores pusTriList and zeroes three members.
// @fnv 0x00a7b630
NiTriShapeData::NiTriShapeData(unsigned short usVertices, NiPoint3* pkVertex, NiPoint3* pkNormal,
                           NiColorA* pkColor, NiPoint2* pkTexture, unsigned short usNumTextureSets,
                           NiGeometryData__DataFlags eNBTMethod, unsigned short usTriangles, unsigned short* pusTriList) throw()
    : NiTriBasedGeomData(usVertices, pkVertex, pkNormal, pkColor, pkTexture, usNumTextureSets, eNBTMethod,
                             usTriangles)
{
    m_uiTriListLength = 3 * m_usTriangles;
    m_pusTriList = pusTriList;
    m_pkSharedNormals = 0;
    m_usSharedNormalsArraySize = 0;
    m_pkSNAMemoryBlocks = 0;
}

// The shared headers omit the default constructors; keep their entry points as typed helpers.
NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData*);
extern void* g_triShapeDataVtable[];

// Initializes the object's pointer fields and the unsigned short field to zero.
// @fnv 0x00a7b690
NiTriShapeData* __fastcall InitializeTriShapeData(NiTriShapeData* self)
{
    InitializeTriBasedGeomData(self);
    *(void**)self = g_triShapeDataVtable;
    self->m_uiTriListLength = 0;
    self->m_pusTriList = 0;
    self->m_pkSharedNormals = 0;
    self->m_usSharedNormalsArraySize = 0;
    self->m_pkSNAMemoryBlocks = 0;
    return self;
}

bool __cdecl MatchesTriangleCount();

// @fnv 0x00a7b7e0
// src: XBOX_PDB 0x00a7b7e0
bool NiTriShapeData::IsEqual_00a7b7e0(const NiTriShapeData* pkOther)
{
    if (!reinterpret_cast<bool (__thiscall*)(NiTriBasedGeomData*, const NiTriShapeData*)>(MatchesTriangleCount)(this, pkOther))
        return false;
    if (m_uiTriListLength != pkOther->m_uiTriListLength)
        return false;
    unsigned int uiBytes = m_uiTriListLength * 2;
    unsigned int* pB = (unsigned int*)pkOther->m_pusTriList;
    unsigned int* pA = (unsigned int*)m_pusTriList;
    while (uiBytes >= 4)
    {
        if (*pA != *pB)
            return false;
        uiBytes -= 4;
        pB++;
        pA++;
    }
    if (uiBytes != 0)
    {
        char* cA = (char*)pA;
        char* pcB = (char*)pB;
        if (pcB[0] != cA[0])
            return false;
        if (uiBytes > 1)
        {
            if (pcB[1] != cA[1])
                return false;
            if (uiBytes > 2 && pcB[2] != cA[2])
                return false;
        }
    }
    return true;
}

namespace fnv_00ba3d30 {
extern "C" char DAT_010b7fe4;

void __cdecl _NiFree_00aa10f0(void*);

extern "C" MemoryManager DAT_011f6238;

class HolderA
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usUnknown0A;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    virtual ~HolderA();
};

HolderA::~HolderA()
{
    void* memory = m_pData;
    _NiFree_00aa10f0(memory);
}

class HolderB
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usUnknown0A;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    virtual ~HolderB();
};

HolderB::~HolderB()
{
    void* memory = m_pData;
    _NiFree_00aa10f0(memory);
}

class HolderC
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usUnknown0A;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    virtual ~HolderC();
};

HolderC::~HolderC()
{
    void* memory = m_pData;
    _NiFree_00aa10f0(memory);
}

class HolderArray
{
  public:
    void* m_pData;
    unsigned short m_usUnknown08;
    unsigned short m_usElementCount;
    unsigned short m_usUnknown0C;
    unsigned short m_usUnknown0E;

    void __thiscall FUN_00ba3aa0(unsigned int index, void*& value);

    virtual ~HolderArray();
};

HolderArray::~HolderArray()
{
    void* memory = m_pData;
    _NiFree_00aa10f0(memory);
}

extern int DAT_010b9d24;
struct PlainHolder
{
    void* vtable;
    void* m_pData;
    unsigned short capacity, count, used, growth;
    void Release()
    {
        void* memory = m_pData;
        vtable = &DAT_010b9d24;
        _NiFree_00aa10f0(memory);
    }
};

class FUN_00ba3d30
{
  public:
    unsigned int unknown04;
    HolderA m_holder08;
    HolderB m_holder18;
    HolderC m_holder28;
    HolderArray m_holder38;
    PlainHolder m_holder48;

    virtual ~FUN_00ba3d30();
};

// Frees each non-null element of m_holder38 via DAT_011f6238, clears it, then releases m_holder48.
// @fnv 0x00ba3d30
FUN_00ba3d30::~FUN_00ba3d30()
{

    for (unsigned int index = 0; index < m_holder38.m_usElementCount; ++index)
    {
        if (((void**)m_holder38.m_pData)[index])
        {
            void* element = ((void**)m_holder38.m_pData)[index];
            DAT_011f6238.Deallocate(element);
            void* cleared = 0;
            m_holder38.FUN_00ba3aa0(index, cleared);
        }
    }
    m_holder48.Release();
}
}  // namespace fnv_00ba3d30

// @fnv 0x00a7b850
unsigned short* NiTriShapeData::GetTriangleList()
{
    return m_pusTriList;
}
