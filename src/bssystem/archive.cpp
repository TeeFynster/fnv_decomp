#include "../../include/BSSimpleList.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#undef FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/ARCHIVE_TYPE.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiFile.h"
#include "../../include/NiRefObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/MobileObject.h"
#include "../../include/BSFileCache.h"
#include "../../include/MemoryManager.h"
#include "../../include/PatrolActorPackageData.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/Archive.h"
#include "../../include/BSArchive.h"
#include "../../include/BSFile.h"
#include "../../include/BSFileEntry.h"
#include "../../include/CompressedArchiveFile.h"

__forceinline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int length, unsigned int* sizes, unsigned int number)
{
    unsigned int uiRead = m_pfnRead(this, buffer, length, sizes, number);
    m_uiAbsoluteCurrentPos += uiRead;
    return uiRead;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline NiRefObject::NiRefObject()
{
    m_uiRefCount = 0;
    InterlockedIncrement(reinterpret_cast<volatile long*>(&ms_lObjectCount));
}
__forceinline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}
inline void NiRefObject::IncrementReferenceCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecrementReferenceCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

// NiPointer has no raw-pointer operator!=; keep the original inline comparison locally.
inline bool ArchivePointerNotEqual(const NiPointer<Archive>& pointer, Archive* object)
{
    return pointer.m_pObject != object;
}

// bssystem/archive.cpp: archive management and file streams (114 functions).

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
extern "C" int __cdecl _strlwr_s(char*, unsigned int);
extern "C" const char kDataPrefix[];
extern "C" const char kTexturePrefix[];

// Skips a drive letter, leading backslash, the data prefix and optionally the textures prefix, returning the offset into path where the remainder starts.
// @fnv 0x00af4170
unsigned int __cdecl GetPathHash(const char* pcPath, bool includeTextures)
{
    const char* current = pcPath;
    if (current[1] == ':')
        current += 3;
    if (*current == '\\')
        ++current;
    if (_strnicmp(current, kDataPrefix, 5) == 0)
        current += 5;
    if (includeTextures && _strnicmp(current, kTexturePrefix, 9) == 0)
        current += 9;
    return (unsigned int)(current - pcPath);
}

// @fnv 0x00af4200
bool __cdecl CleanPath(const char* path, char* output, unsigned int outputSize)
{
    bool result = true;
    output[0] = 0;
    {
        unsigned int offset = GetPathHash(path, false);
        strcat_s(output, outputSize, path + offset);
    }
    _strlwr_s(output, outputSize);
    return result;
}

// Shared PC file-stream hierarchy.

typedef char _sizecheck_NiFile[sizeof(NiFile) == 0x30 ? 1 : -1];
typedef char _sizecheck_BSFile[sizeof(BSFile) == 0x158 ? 1 : -1];
typedef char _sizecheck_ArchiveFile[sizeof(ArchiveFile) == 0x160 ? 1 : -1];
typedef char _sizecheck_CompressedArchiveFile[sizeof(CompressedArchiveFile) == 0x178 ? 1 : -1];

// @fnv 0x00afbfa0
void ArchiveFile::SetEndianSwap(bool doSwap)
{
    if (doSwap)
    {
        BSFile::SetEndianSwap(doSwap);
    }
    else
    {
        (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08)) = reinterpret_cast<void*>(0x00afbf80);
        (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x0c)) = reinterpret_cast<void*>(0x00aff9f0);
    }
}

// Enables endian swap via BSFile when doSwap is set, otherwise assigns the read and write function pointers.
// @fnv 0x00afc620
void CompressedArchiveFile::SetEndianSwap(bool doSwap)
{
    if (doSwap)
    {
        BSFile::SetEndianSwap(doSwap);
    }
    else
    {
        (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08)) = reinterpret_cast<void*>(0x00afc660);
        (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x0c)) = reinterpret_cast<void*>(0x00aff9f0);
    }
}

// @fnv 0x00afc080
void CompressedArchiveFile::Seek(int offset, int mode)
{
    ReadRawData(0, offset);
}

// @fnv 0x0043c030
// src: COMMUNITY 0x0043c030
unsigned int __fastcall Archive_GetRuntimeID(const char* pThis)
{
    return *(const unsigned int*)(pThis + 0x1c8);
}

class bhkCharacterController;

int __fastcall bhkCharacterController_GetState(bhkCharacterController*);
float __fastcall GetSettingFloat(bhkCharacterController*);
float __cdecl HK2NI(float);
bool __fastcall bhkCharacterListener_QQuadruped(void*);
int __cdecl LengthCheck_004b5470(const NiPoint3&, float);

extern double gModifierZero;
extern double DAT_0101db88;

// @fnv 0x008b2f90
// src: COMMUNITY 0x008b2f90
bool MobileObject::Actor_IsAtPoint(const NiPoint3& targetPos, float radius, bool addCharRadius, bool check3D)
{
    bhkCharacterController* charCtrl;
    {
        NiPoint3 selfPos;
        selfPos = *static_cast<const MobileObject*>(this)->GetPos();
        charCtrl = GetPhysicsCharacterController();
        {
            NiPoint3 diff = selfPos - targetPos;
            if (!check3D && charCtrl && bhkCharacterController_GetState(charCtrl))
            {
                diff.z = 0.0f;
            }
            else
            {
                float height = GetActorHeight();
                if (height == gModifierZero)
                {
                    height = 128.0f;
                }
                {
                    float zMin = selfPos.z - DAT_0101db88;
                    {
                        float zMax = selfPos.z + height + DAT_0101db88;
                        if (targetPos.z > zMin && targetPos.z < zMax)
                        {
                            diff.z = 0.0f;
                        }
                    }
                }
            }
            if (addCharRadius)
            {
                float charRadius;
                if (charCtrl)
                {
                    charRadius = HK2NI(GetSettingFloat(charCtrl));
                    if (bhkCharacterListener_QQuadruped((char*)charCtrl + 0x410))
                    {
                        charRadius *= 2.0f;
                    }
                    if (charRadius < 32.0)
                    {
                        charRadius = 32.0f;
                    }
                }
                else
                {
                    charRadius = 32.0f;
                }
                radius = radius + charRadius;
            }
            return LengthCheck_004b5470(diff, radius) <= 0;
        }
    }
}

class NavMesh;
class Actor;
class TESPackage;
class NavMeshEdgeSegment;

class TESObjectREFRHelper
{
  public:
    void SetTargetingState(bool);
};

bool __cdecl Actor_AreReferencedValuesEqual(NavMesh* const&, NavMesh* const&);

// @fnv 0x009f2da0
bool __fastcall BuildLinkedRefChain(char* _this)
{
    bool bLoop;
    TESObjectREFR* pRef =
        PatrolActorPackageData::GetPatrolReference(*(Actor**)(_this + 0x10), *(TESPackage**)(_this + 0x14));
    *(bool*)(_this + 0x2c) = false;
    ((BSSimpleArray<unsigned int, 1024>*)(_this + 0x1c))->SetSize(0, true);
    bLoop =
        *(PatrolActorPackageData**)(_this + 0x18) ? (*(PatrolActorPackageData**)(_this + 0x18))->IsPatrolling() : false;

    while (pRef != 0)
    {
        ((TESObjectREFRHelper*)pRef)->SetTargetingState(true);
        ((BSSimpleArray<void*, 1024>*)(_this + 0x1c))->Add(*(void* const*)&pRef);
        pRef = pRef->GetLinkedRef();
        if (pRef == 0)
            break;

        unsigned int idx = ((BSSimpleArray<NavMesh*, 1024>*)(_this + 0x1c))->Find(*(NavMesh**)&pRef, 0, Actor_AreReferencedValuesEqual);
        if (idx != (unsigned int)-1)
        {
            if (!bLoop)
            {
                ((BSSimpleArray<void*, 1024>*)(_this + 0x1c))->Add(*(void* const*)&pRef);
            }
            else
            {
                *(bool*)(_this + 0x2c) = true;
                *(unsigned int*)(_this + 0x30) = idx;
            }
            break;
        }
    }

    return !((BSSimpleArray<NavMeshEdgeSegment, 1024>*)(_this + 0x1c))->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
}

extern int DAT_011acdfc;
extern int DAT_011ace00;
extern int DAT_011ace04;

// @fnv 0x00af4470
// src: COMMUNITY 0x00af4470
void __cdecl SetRetainStringAndOffsetTables(int aiDirString, int aiFileString, int aiFileOffset)
{
    DAT_011acdfc = aiDirString;
    DAT_011ace00 = aiFileString;
    DAT_011ace04 = aiFileOffset;
}

struct LNode
{
    Archive* item;
    LNode* next;
};
extern LNode* DAT_011f8160;
// If the global node list is non-empty, sets the cache state to 2 when it is 1, calls LoadNames on each node's Archive, then restores state 2 to 1.
// @fnv 0x00af59f0
void __cdecl ProcessArcList()
{
    bool b;
    LNode* pCurrentElementNext;
    if (DAT_011f8160)
    {
        BSFileCache* c1 = &BSFileCache::GetRandomGenerator();
        b = c1->m_eCacheState == 2 || c1->m_eCacheState == 3;
        if (!b)
        {
            BSFileCache* c2 = &BSFileCache::GetRandomGenerator();
            if (c2->m_eCacheState == 1)
                c2->m_eCacheState = FILE_CACHING_PAUSED;
        }
        pCurrentElementNext = DAT_011f8160;
        while (pCurrentElementNext)
        {
            Archive* a = pCurrentElementNext->item;
            a->LoadNames();
            pCurrentElementNext = pCurrentElementNext->next;
        }
        if (!b)
        {
            BSFileCache* c3 = &BSFileCache::GetRandomGenerator();
            if (c3->m_eCacheState == 2)
                c3->m_eCacheState = FILE_CACHING_IN_PROGRESS;
        }
    }
}

int __cdecl FindArchiveForFile(int a1, int a2);

// @fnv 0x00af6320
// src: COMMUNITY 0x00af6320
bool __cdecl ArchiveManager_FindFile(int a1, int a2)
{
    return FindArchiveForFile(a1, a2);
}

unsigned int __cdecl _strlen(const char*);
int __cdecl LookupExtensionType(const char*);

// Computes the string length, then passes a pointer to its last three characters to LookupExtensionType and returns that result.
// @fnv 0x00af7d80
// src: COMMUNITY 0x00af7d80
int __cdecl ArchiveManager_GetArchiveTypeFromFileName(const char* pcString)
{
    unsigned int len = _strlen(pcString);
    return LookupExtensionType(pcString + len - 3);
}

// 0x00af9c50/0x00af9bf0: Archive.h lacks FindHashEntry and FUN_00afa120; local methods use the shared layout.
struct ArchiveHashLookup : public Archive
{
    bool FindHashEntry(int, int*, int);
    bool Archive_FindFileInDirectory(int, int, int, int, int);
};
// Returns true if FindHashEntry(a, c, e) succeeds and FUN_00afa120 then succeeds on *c with b, d, e and 0.
// @fnv 0x00af9bf0
// src: COMMUNITY 0x00af9bf0
bool Archive::FindFile_00af9bf0(int a, int b, int* c, int d, int e)
{
    if (reinterpret_cast<ArchiveHashLookup*>(this)->FindHashEntry(a, c, e) &&
        reinterpret_cast<ArchiveHashLookup*>(this)->Archive_FindFileInDirectory(*c, b, d, e, 0))
        return true;
    return false;
}

// 0x00afa6e0: Archive.h lacks FindHashEntry and FUN_00afa120; local methods use the shared layout.

// @fnv 0x00afa6e0
// src: COMMUNITY 0x00afa6e0
int Archive::GetFileEntryForFile(int a, int b, int c)
{
    int index1;
    int index2;
    if (reinterpret_cast<ArchiveHashLookup*>(this)->FindHashEntry(a, &index1, c) &&
        reinterpret_cast<ArchiveHashLookup*>(this)->Archive_FindFileInDirectory(index1, b, (int)&index2, c, 1))
    {
        return (int)pEntries[index1].m_pFiles + index2 * 16;
    }
    return 0;
}

struct FUN_00afb170_Args
{
    bool param_1;
    int param_2;
};

// @fnv 0x00afb170
// src: COMMUNITY 0x00afb170
bool __fastcall Archive_CheckRetain(void* pThis, FUN_00afb170_Args args)
{
    if (args.param_2 == 1)
        return args.param_1;
    return args.param_2;
}

struct FUN_00afb670_shell : public ArchiveFile
{
    void ArchiveFile_Seek(int, int);
};

// Adjusts the archive file position at offset 0x150 according to the seek mode, then advances m_uiPos by the delta and flushes if the buffer is exhausted.
// @fnv 0x00afb670
// src: XBOX_PDB 0x00afb670
void FUN_00afb670_shell::ArchiveFile_Seek(int aiByteCount, int aiSeekFlags)
{
    unsigned int ioldFilePos = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150);

    switch (aiSeekFlags)
    {
    case 1:
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) += aiByteCount;
        if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) >
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154))
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) =
                *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154);
        break;
    case 2:
        if (aiByteCount < 0)
            aiByteCount = -aiByteCount;
        if ((unsigned int)aiByteCount > *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154))
        {
            unsigned int tmp = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154);
            aiByteCount = tmp;
        }
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) =
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154) - aiByteCount;
        break;
    default:
        if ((unsigned int)aiByteCount > *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154))
        {
            unsigned int tmp = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x154);
            aiByteCount = tmp;
        }
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) = aiByteCount;
        break;
    }

    (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18)) += *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x150) - ioldFilePos;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18)) >= (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x14)))
        Flush();
}

struct S_afbb
{
    char pad[0x150];
    unsigned int pos;
    unsigned int size;
    int ArchiveFile_ReadFromBuffer(void*, unsigned int);
    int ArchiveFile_ReadF(void*, unsigned int);
};
// Clamps count to the remaining bytes (size - pos), reads via FUN_00b01800, advances pos by the bytes read and returns that count.
// @fnv 0x00afbbf0
// src: XBOX_PDB 0x00afbbf0
int S_afbb::ArchiveFile_ReadF(void* pBuffer, unsigned int count)
{
    int r;
    unsigned int sz = size;
    if (count + pos > sz)
    {
        unsigned int sz2 = size;
        count = sz2 - pos;
    }
    r = ArchiveFile_ReadFromBuffer(pBuffer, count);
    pos += r;
    return r;
}

struct Dummy_00afbbf0
{
    int ArchiveFile_ReadF(int, int);
};

// @fnv 0x00afbf80
// src: COMMUNITY 0x00afbf80
int __cdecl ArchiveFile_ReadNoSwap(Dummy_00afbbf0* pTarget, int b, int c)
{
    return pTarget->ArchiveFile_ReadF(b, c);
}

struct ZlibStreamPeer;
struct ZlibStream
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned long m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
    unsigned long m_ulTotalOutputBytes;
    char* msg;
    ZlibStreamPeer* state;
    int* m_pAllocateCallback;
    int* m_pFreeCallback;
    void* opaque;
    int data_type;
    unsigned long m_ulAdler32Checksum;
    unsigned long reserved;
};
typedef char _sizecheck_z_stream_s[sizeof(ZlibStream) == 56 ? 1 : -1];
struct FUN_00afbfe0_shell : public CompressedArchiveFile
{
    void DestroyCompressedArchiveFile();
};

extern MemoryManager g_memoryManager;
extern int DAT_010a464c;
int __cdecl _inflateEnd(ZlibStream* kReadStream);
void __fastcall FUN_00afb520(void* pThis);

// Sets the vtable, ends and frees the zlib stream at offset 0x160, frees the buffer at 0x164, then calls FUN_00afb520.
// @fnv 0x00afbfe0
void FUN_00afbfe0_shell::DestroyCompressedArchiveFile()
{
    ZlibStream* pzstream;
    *(int**)this = &DAT_010a464c;
    if (*(ZlibStream**)((char*)this + 0x160) != 0)
    {
        pzstream = *(ZlibStream**)((char*)this + 0x160);
        _inflateEnd(pzstream);
        void* p1 = pzstream;
        g_memoryManager._DeallocateAlias(p1);
    }
    if (*(void**)((char*)this + 0x164) != 0)
    {
        void* p2 = *(void**)((char*)this + 0x164);
        g_memoryManager._DeallocateAlias(p2);
    }
    ::FUN_00afb520(this);
}

struct FUN_00afc060_shell2 : public CompressedArchiveFile
{
    bool AttachFileStream(bool, bool);
    bool CompressedArchiveFile_Open(bool a1, bool a2);
};

// @fnv 0x00afc060
// src: XBOX_PDB 0x00afc060
bool FUN_00afc060_shell2::CompressedArchiveFile_Open(bool a1, bool a2)
{
    return AttachFileStream(a1, a2);
}

struct S
{
    void __thiscall CompressedArchiveFile_ReadF(int, int);
};

// @fnv 0x00afc660
// src: COMMUNITY 0x00afc660
void __cdecl CompressedArchiveFile_ReadNoSwap(void* pObject, int b, int c)
{
    (*(S*)pObject).CompressedArchiveFile_ReadF(b, c);
}

namespace fnv_00afc6c0 {

extern MemoryManager g_memoryManager;
void __fastcall DestroyCompressedArchiveFile(void* pThis);

struct FUN_00afc6c0_shell2 : public CompressedArchiveFile
{
    void* FUN_00afc6c0(unsigned int flags);
};

// Calls DestroyCompressedArchiveFile on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00afc6c0
void* FUN_00afc6c0_shell2::FUN_00afc6c0(unsigned int flags)
{
    fnv_00afc6c0::DestroyCompressedArchiveFile(this);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00afc6c0

namespace fnv_00afc6f0 {

extern MemoryManager g_memoryManager;
void __fastcall DestroyCompressedArchiveFile(void* pThis);

struct FUN_00afc6f0_shell2 : public CompressedArchiveFile
{
    void* FUN_00afc6f0(unsigned int flags);
};

// @fnv 0x00afc6f0
void* FUN_00afc6f0_shell2::FUN_00afc6f0(unsigned int flags)
{
    fnv_00afc6f0::DestroyCompressedArchiveFile(this);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00afc6f0

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObj
{
    virtual void v0();
    virtual void v1();
    long refs;
};

template <> inline NiPointer<Archive>::NiPointer(Archive* pObject) : m_pObject(pObject)
{
    if (m_pObject)
        m_pObject->IncRefCount();
}

template <> inline NiPointer<Archive>::NiPointer()
{
    m_pObject = 0;
    RefObj* pRef;
    if (m_pObject)
    {
        RefObj* ref = reinterpret_cast<RefObj*>(reinterpret_cast<char*>(m_pObject) + sizeof(BSFile));
        InterlockedIncrement(&ref->refs);
    }
}

// Assigns the pointee, releasing the old reference and acquiring the new one.
// @fnv 0x00afc770
template <> inline NiPointer<Archive>& NiPointer<Archive>::operator=(const NiPointer<Archive>& ptr)
{
    if (m_pObject != ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}

// Counts the high bits of bytes 0, 1 and 3 of pThis, weighted 2, 1 and 4 respectively, and returns their sum.
// @fnv 0x00afcfe0
// src: COMMUNITY 0x00afcfe0
int __fastcall BSHash_ExtensionIndex(unsigned char* pucData)
{
    return ((pucData[3] & 0x80) >> 5) + ((pucData[0] & 0x80) >> 6) + ((pucData[1] & 0x80) >> 7);
}

// Replaces the stored Archive pointer, releasing the old reference and acquiring the new one.
// @fnv 0x00afd1b0
template <> inline NiPointer<Archive>& NiPointer<Archive>::operator=(Archive* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            m_pObject->DecRefCount();
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    return *this;
}

// These callers originally saw only an outlined assignment declaration; preserve their inline stack frames.
inline void AssignArchivePointer(NiPointer<Archive>& pointer, Archive* object)
{
#pragma inline_depth(0)
    pointer = object;
#pragma inline_depth()
}

extern void(__stdcall* DAT_00fdf1c0)(int);

// @fnv 0x00afd230
// src: COMMUNITY 0x00afd230
void __fastcall ArchivePtr_ArchivePtr(int* piValue)
{
    *piValue = 0;
    if (*piValue)
    {
        int v = *piValue + 0x158;
        DAT_00fdf1c0(v + 4);
    }
}

struct FileNameHash
{
    void GetAll(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned int*);
    unsigned char Length();
    unsigned char First();
    unsigned char Last();
    unsigned char Last2();
    unsigned int CRC();
    void* Hash();
    unsigned char ExtensionIndex();
    int Compare(FileNameHash*);
    int WildCardCompare(FileNameHash*);
    static void Create(char*, char*, FileNameHash*);
    static void CreateDirectoryAndFileHashes(char*, FileNameHash*, FileNameHash*);
    void MakeHashString(char*);
    void Endian();
    void Reverse();
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
typedef char _sizecheck_BSHash[sizeof(FileNameHash) == 8 ? 1 : -1];

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl ComputeNameHash(char*, char*, FileNameHash*);

// Splits a path into drive, directory, file and extension, hashes the file name with its extension and the directory path into the two output hashes.
// @fnv 0x00afd270
void __cdecl HashPathComponents(const char* apString, FileNameHash* arDirHash, FileNameHash* arFileHash)
{
    char pfile[260];
    char pdrive[16];
    unsigned int ilength;
    char pdir[260];
    char pext[16];

    pdrive[0] = '\0';
    pdir[0] = '\0';
    pfile[0] = '\0';
    pext[0] = '\0';

    _splitpath_s(apString, pdrive, 16, pdir, 260, pfile, 260, pext, 16);
    ComputeNameHash(pfile, pext, arFileHash);

    strcpy_s(pfile, 260, pdrive);
    strcat_s(pfile, 260, pdir);

    if (pfile[0] == '\0')
    {
        pfile[0] = '.';
        pfile[1] = '\0';
    }

    ilength = strlen(pfile);
    if (pfile[ilength - 1] == '\\')
    {
        pfile[ilength - 1] = '\0';
    }

    ComputeNameHash(pfile, 0, arDirHash);
}

extern "C" int __cdecl _splitpath_s(const char*, char*, unsigned int, char*, unsigned int, char*, unsigned int, char*,
                                    unsigned int);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl ComputeNameHash(const char*, const char*, void*);

struct FUN_00afd390_class
{
    void* UpdateState_00afd390(const char* path, int mode);
};

// @fnv 0x00afd390
// src: GUESS 0x00afd390 (confidence: low)
void* FUN_00afd390_class::UpdateState_00afd390(const char* path, int mode)
{
    const char* pExt = 0;
    if (mode != 2)
    {
        char ext[16];
        {
            char dir[260];
            {
                char drive[16];
                {
                    char fname[260];

                    drive[0] = '\0';
                    dir[0] = '\0';
                    fname[0] = '\0';
                    ext[0] = '\0';
                    _splitpath_s(path, drive, 16, dir, 260, fname, 260, ext, 16);
                    if (mode == 0)
                    {
                        pExt = ext;
                        path = fname;
                    }
                    else
                    {
                        strcpy_s(fname, 260, drive);
                        strcat_s(fname, 260, dir);
                        if (fname[0] == '\0')
                        {
                            fname[0] = '.';
                            fname[1] = '\0';
                        }
                        unsigned int len = strlen(fname);
                        if (fname[len - 1] == '\\')
                        {
                            fname[len - 1] = '\0';
                        }
                        path = fname;
                    }
                }
            }
        }
    }
    ComputeNameHash(path, pExt, this);
    return this;
}

extern bool DAT_011acdf9;
extern char* DAT_011f8158;
int __cdecl _strcpy_s(char*, unsigned int, const char*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
// Stores abInvalidate in DAT_011acdf9 and, when apInvalidationFile is non-null, allocates a copy of it into DAT_011f8158.
// @fnv 0x00af4490
// src: COMMUNITY 0x00af4490
void __cdecl ArchiveManager_SetInvalidation(bool abInvalidate, const char* apInvalidationFile)
{
    DAT_011acdf9 = abInvalidate;
    if (apInvalidationFile)
    {
        unsigned int ilistSize = _strlen(apInvalidationFile) + 1;
        {
            char* pBuf = (char*)reinterpret_cast<MemoryManagerAllocHelper*>(&g_memoryManager)->Allocate(ilistSize);
            DAT_011f8158 = pBuf;
        }
        {
            char* pDst = DAT_011f8158;
            _strcpy_s(pDst, ilistSize, apInvalidationFile);
        }
    }
}

struct ArchiveFileEntryStand
{
    char pad[0xc];
    unsigned int uiSize;
};
// 0x00afb2a0: Archive.h lacks IsFileEntryValid; retain only its local method declaration.
struct ArchiveEntryValidation : public Archive
{
    bool IsFileEntryValid(ArchiveFileEntryStand* apFile, bool abIgnore);
};
// Checks a file entry's size flag against the archive's compression bit unless ignored, and rejects entries with zero size.
// @fnv 0x00afb2a0
bool ArchiveEntryValidation::IsFileEntryValid(ArchiveFileEntryStand* apFile, bool abIgnore)
{
    if (!abIgnore)
    {
        bool bCompressed = (apFile->uiSize & 0x80000000) ? true : false;
        if (bCompressed != ((m_ucStatus & 8) ? true : false))
            return false;
    }
    if (!(apFile->uiSize & 0x7fffffff))
        return false;
    return true;
}

namespace fnv_00afc430 {
extern MemoryManager g_memoryManager;
int __cdecl _inflateInit_(void*, const char*, int);
int __cdecl _inflateEnd(void*);
extern int DAT_010a464c;
extern unsigned int DAT_011f8164;
struct S_afbb
{
    int ArchiveFile_ReadF(void*, unsigned int);
};
struct P03Z
{
    void* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    char pad08[0x14];
    void* state;
    void* m_pAllocateCallback;
    void* m_pFreeCallback;
    void* opaque;
};
struct P03CAF
{
    char pad[0x160];
    P03Z* pStream;
    void* pBuffer;
    unsigned int uiBufSize;
    unsigned int uiCap;
    int f170;
    int f174;
};
struct FUN_00afb300
{
    FUN_00afb300(int, int, int, int, int);
    ~FUN_00afb300();
};
struct FUN_00afc430 : public FUN_00afb300
{
    FUN_00afc430(int, int, int, int, int);
};
// @fnv 0x00afc430
FUN_00afc430::FUN_00afc430(int a, int b, int c, int d, int e) : FUN_00afb300(a, b, c, d, e)
{
    *(int**)this = &DAT_010a464c;
    ((CompressedArchiveFile*)this)->CompressedArchiveFile::SetEndianSwap(false);
    ((S_afbb*)this)->ArchiveFile_ReadF((char*)this + 0x168, 4);
    char* pStream;
    int pTmp;
    void* err = g_memoryManager.Allocate(0x1be0);
    pStream = (char*)err;
    ((P03CAF*)this)->pStream = (P03Z*)pStream;
    ((P03CAF*)this)->pStream->m_pAllocateCallback = 0;
    ((P03CAF*)this)->pStream->m_pFreeCallback = 0;
    ((P03CAF*)this)->pStream->opaque = 0;
    ((P03CAF*)this)->pStream->m_uiAvailableInputBytes = 0;
    ((P03CAF*)this)->pStream->m_pNextInputByte = 0;
    ((P03CAF*)this)->pStream->state = pStream + 0x38;
    pTmp = _inflateInit_(((P03CAF*)this)->pStream, "1.2.1", 0x38);
    if (pTmp)
    {
        _inflateEnd(((P03CAF*)this)->pStream);
        void* pFree = ((P03CAF*)this)->pStream;
        g_memoryManager._DeallocateAlias(pFree);
        ((P03CAF*)this)->pStream = 0;
    }
    else
    {
        ((P03CAF*)this)->uiCap = ((P03CAF*)this)->uiBufSize < DAT_011f8164 ? ((P03CAF*)this)->uiBufSize : DAT_011f8164;
        unsigned int pBuf = ((P03CAF*)this)->uiCap;
        void* uiSize = g_memoryManager.Allocate(pBuf);
        ((P03CAF*)this)->pBuffer = uiSize;
        ((P03CAF*)this)->f170 = 0;
        ((P03CAF*)this)->f174 = 0;
    }
}
}  // namespace fnv_00afc430

struct FUN_00afcde0_shell
{
    unsigned int* data;
    unsigned int size;
    unsigned int alloc;
    virtual void* v0();
    virtual unsigned int* v1(unsigned int);
    void InitArray(unsigned int, unsigned int);
};
// Initializes the array to empty, reserves aiReserveSize elements via v1, and sets size to aiInitialSize.
// @fnv 0x00afcde0
void FUN_00afcde0_shell::InitArray(unsigned int aiReserveSize, unsigned int aiInitialSize)
{
    data = 0;
    size = 0;
    alloc = 0;
    if (aiInitialSize > aiReserveSize)
        aiReserveSize = aiInitialSize;
    if (aiReserveSize > 0)
    {
        data = v1(aiReserveSize);
        alloc = aiReserveSize;
    }
    if (aiInitialSize > 0)
    {
        for (unsigned int i = 0; i < aiInitialSize; i++)
        {
            unsigned int* p = &data[i];
        }
        size = aiInitialSize;
    }
}

struct FUN_00afce90_S
{
    unsigned __int64 value;
    int BSHash_Compare(const unsigned __int64& other);
};
// Compares value with other and returns -1 if less, 1 if greater, or 0 if equal.
// @fnv 0x00afce90
// src: COMMUNITY 0x00afce90
int FUN_00afce90_S::BSHash_Compare(const unsigned __int64& aullValue)
{
    if (value < aullValue)
        return -1;
    else if (value > aullValue)
        return 1;
    return 0;
}

extern bool DAT_011acdf9;
extern bool DAT_011f8154;
extern int DAT_011acdfc;
extern int DAT_011ace00;
extern int DAT_011ace04;
struct ArgPair
{
    char c0, c1, c2;
    bool b;
    int i;
};

extern MemoryManager g_memoryManager;
struct P03MM
{
    void* Allocate(unsigned int);
};
unsigned int __cdecl _strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
extern bool DAT_011acdf8;
extern char DAT_011f8050[];
extern const char DAT_010a433a[];
extern char* DAT_011f815c;
extern unsigned int DAT_011f8164;
// Stores the archive flag, copies the archive list and master file path into globals, and sets the file buffer size.
// @fnv 0x00af43a0
// src: COMMUNITY 0x00af43a0
void __cdecl ArchiveManager_Init(bool abUseArchives, char* apMasterFilePath, char* apArchiveList,
                          unsigned int aiFileBufferSize)
{
    int ilistSize;
    char* pEmpty;
    char* pNew;
    DAT_011acdf8 = abUseArchives;
    if (apArchiveList)
    {
        ilistSize = _strlen(apArchiveList) + 1;
        pEmpty = (char*)((P03MM*)&g_memoryManager)->Allocate(ilistSize);
        DAT_011f815c = pEmpty;
        {
            {
                char* pDest = DAT_011f815c;
                _strcpy_s(pDest, ilistSize, apArchiveList);
            }
        }
    }
    else
    {
        pNew = (char*)((P03MM*)&g_memoryManager)->Allocate(0);
        DAT_011f815c = pNew;
        *DAT_011f815c = 0;
    }
    if (apMasterFilePath)
        _strcpy_s(DAT_011f8050, 0x104, apMasterFilePath);
    else
        _strcpy_s(DAT_011f8050, 0x104, DAT_010a433a);
    DAT_011f8164 = aiFileBufferSize;
}

namespace fnv_00af7db0 {
int __cdecl _stricmp(const char*, const char*);
struct ExtEntry_00af7db0
{
    char acExt[4];
    unsigned int uiType;
};
struct ExtType_00af7db0
{
    unsigned int uiType;
    char acPad[4];
};
extern ExtEntry_00af7db0 str_011ace08[];
extern ExtType_00af7db0 DAT_011ace0c[];
// @fnv 0x00af7db0
unsigned int __cdecl LookupExtensionType(const char* apExt)
{
    unsigned int iCmp = 0;
    unsigned int uiStep = 0x1a;
    unsigned int uiHigh = 0;
    unsigned int uiMid = 1;
    int uiLow = 0;
    if (*apExt == '.')
        apExt++;
    else if (apExt[1] == '.')
        apExt += 2;
    while (uiMid)
    {
        uiMid = (uiStep - iCmp) >> 1;
        uiHigh = iCmp + uiMid;
        uiLow = _stricmp(apExt, str_011ace08[uiHigh].acExt);
        if (uiLow > 0)
            iCmp = uiHigh;
        else if (uiLow < 0)
            uiStep = uiHigh;
        else
            break;
    }
    if (uiLow == 0)
        return DAT_011ace0c[uiHigh].uiType;
    return 0x100;
}
}  // namespace fnv_00af7db0

namespace fnv_00af6340 {
struct ArchiveManager
{
    static Archive* __cdecl FindArchiveForFileEntry(BSFileEntry*, ARCHIVE_TYPE);
};

// @fnv 0x00af6340
// src: XBOX_PDB 0x00af6340
ArchiveFile* __cdecl ArchiveManager_GetFileByFileEntry(int aeArchiveTypeIndex, BSFileEntry* apFileEntry, unsigned int aiBufferSize,
                                  unsigned int apFileName)
{
    ArchiveFile* pfile = 0;
    bool binSecondaryArchive = (apFileEntry->flags & 0x80000000) == 0 ? false : true;
    NiPointer<Archive> sparchive(ArchiveManager::FindArchiveForFileEntry(apFileEntry, (ARCHIVE_TYPE)0xffff));
    if (sparchive.m_pObject)
    {
        pfile = sparchive->CreateArchiveFile(apFileEntry, aiBufferSize, apFileName);
    }
    return pfile;
}
}  // namespace fnv_00af6340

extern bool DAT_011f8154;

// @fnv 0x00af4460
// src: COMMUNITY 0x00af4460
void ArchiveManager_SetCheckRuntimeCollisions(bool abCheckRuntimeCollisions)
{
    DAT_011f8154 = abCheckRuntimeCollisions;
}

namespace fnv_00af44f0 {
extern char* DAT_011f8158;
extern char* DAT_011f815c;
extern "C" void __cdecl _DeallocateAlias(void* ptr);
extern MemoryManager g_memoryManager;

// @fnv 0x00af44f0
// src: GUESS 0x00af44f0 (confidence: low)
void Archive_UpdateState_00af44f0()
{
    char* ptr0;
    char* ptr1;
    if (DAT_011f8158)
    {
        ptr0 = DAT_011f8158;
        g_memoryManager._DeallocateAlias(ptr0);
    }
    if (DAT_011f815c)
    {
        ptr1 = DAT_011f815c;
        g_memoryManager._DeallocateAlias(ptr1);
    }
}
}  // namespace fnv_00af44f0

extern unsigned int DAT_011f8164;

// @fnv 0x00af4540
// src: COMMUNITY 0x00af4540
void ArchiveManager_SetStartupFinished()
{
    DAT_011f8164 = 0x20000;
}

namespace fnv_00af56d0 {
extern "C" int __cdecl RemoveArchiveFile(int);
extern "C" int DAT_011f8160;

// Returns false if DAT_011f8160 or arg is zero; otherwise calls RemoveArchiveFile with arg and returns true.
// @fnv 0x00af56d0
// src: GUESS 0x00af56d0 (confidence: medium)
bool __cdecl Archive_RemoveArchiveFileIfAvailable(int aiValue)
{
    if (DAT_011f8160 == 0 || aiValue == 0)
        return false;
    RemoveArchiveFile(aiValue);
    return true;
}
}  // namespace fnv_00af56d0

struct Entry16
{
    int a;
    int b;
    int c;
    unsigned int d;
};
// 0x00af9b60: Archive.h lacks this entry-position method; use the shared folder array.
struct ArchiveEntryPosition : public Archive
{
    unsigned int Archive_GetFileIndexForFileEntryFromDirectory(unsigned int index, unsigned int value);
};
// Computes the difference between value and the entry's d field at index, shifted right by 4.
// @fnv 0x00af9b60
// src: COMMUNITY 0x00af9b60
unsigned int ArchiveEntryPosition::Archive_GetFileIndexForFileEntryFromDirectory(unsigned int index, unsigned int value)
{
    unsigned int tmp;
    unsigned int start;
    unsigned int endPos;
    Entry16* pEntry;
    pEntry = reinterpret_cast<Entry16*>(pEntries) + index;
    tmp = value;
    endPos = pEntry->d;
    start = endPos;
    return (tmp - start) >> 4;
}

// 0x00af9ba0: Archive.h lacks FindEntryIndex and the integer-key name lookup overload.
struct ArchiveNameLookup : public Archive
{
    int FindEntryIndex(unsigned int key);
    unsigned int Archive_GetFileIndexForFileEntryFromDirectory(unsigned int index, unsigned int value);
    int Archive_GetFileNameForFileEntry(unsigned int key);
};
// @fnv 0x00af9ba0
// src: COMMUNITY 0x00af9ba0
int ArchiveNameLookup::Archive_GetFileNameForFileEntry(unsigned int key)
{
    int index = FindEntryIndex(key);
    if (index == -1)
        return 0;
    unsigned int result = Archive_GetFileIndexForFileEntryFromDirectory(index, key);
    return Archive_GetFileString(index, result);
}

namespace fnv_00afac20 {
struct FUN_00afac20_entry
{
    int a;
    int b;
    int c;
    unsigned int bits;
    inline void SetSize(unsigned int v)
    {
        bits = (v & 0x7fffffff) | (bits & 0x80000000);
    }
};
struct FUN_00afac20_group
{
    int a;
    int b;
    int c;
    FUN_00afac20_entry* entries;
};
// 0x00afac20: Archive.h lacks this size-reset method; use the shared hash lookup declaration.
struct ArchiveEntrySizeReset : public Archive
{
    bool Archive_InvalidateFile(int a, int b, int c);
};
// Looks up an entry via FUN_00af9bf0 and, if found, sets its size to 0 and returns true; otherwise returns false.
// @fnv 0x00afac20
// src: COMMUNITY 0x00afac20
bool ArchiveEntrySizeReset::Archive_InvalidateFile(int a, int b, int c)
{
    int iGroupIndex;
    int idx;
    if (FindFile_00af9bf0(a, b, &iGroupIndex, (int)&idx, 0))
    {
        FUN_00afac20_entry* e =
            (FUN_00afac20_entry*)((char*)((FUN_00afac20_group*)*(char**)((char*)this + 0x184) + iGroupIndex)->entries +
                                  idx * 16);
        e->SetSize(0);
        return true;
    }
    return false;
}
}  // namespace fnv_00afac20

namespace fnv_00afac90 {
struct FUN_00afac90_entry
{
    int a;
    int b;
    int c;
    unsigned int bits;
    inline void SetSize(unsigned int v)
    {
        bits = (v & 0x7fffffff) | (bits & 0x80000000);
    }
};
struct FUN_00afac90_group
{
    int a;
    int b;
    int c;
    FUN_00afac90_entry* entries;
};
// 0x00afac90: Archive.h lacks this size-reset method and FUN_00afa120.
struct ArchiveFolderSizeReset : public Archive
{
    bool Archive_FindFileInDirectory(int, int, int*, int, int);
    bool Archive_InvalidateFile_(int a, int b, int c);
};
// @fnv 0x00afac90
// src: COMMUNITY 0x00afac90
bool ArchiveFolderSizeReset::Archive_InvalidateFile_(int aiGroupIndex, int b, int aiUnused)
{
    int idx;
    if (Archive_FindFileInDirectory(aiGroupIndex, b, &idx, 0, 0))
    {
        FUN_00afac90_entry* e =
            (FUN_00afac90_entry*)((char*)((FUN_00afac90_group*)*(char**)((char*)this + 0x184) + aiGroupIndex)->entries +
                                  idx * 16);
        e->SetSize(0);
        return true;
    }
    return false;
}
}  // namespace fnv_00afac90

struct FUN_00afbf50_shell
{
    unsigned int ArchiveFile_WriteF(void* a, unsigned int b);
};
// @fnv 0x00afbf50
// src: COMMUNITY 0x00afbf50
unsigned int FUN_00afbf50_shell::ArchiveFile_WriteF(void* a, unsigned int b)
{
    return 0;
}

struct FUN_00afc3e0_shell
{
    unsigned int CompressedArchiveFile_ReadStringAlt(void* a, unsigned int b);
};
// @fnv 0x00afc3e0
// src: COMMUNITY 0x00afc3e0
unsigned int FUN_00afc3e0_shell::CompressedArchiveFile_ReadStringAlt(void* a, unsigned int b)
{
    return 0;
}

struct FUN_00afc3f0_shell
{
    unsigned int CompressedArchiveFile_ReadString(void* a, unsigned int b);
};
// @fnv 0x00afc3f0
// src: COMMUNITY 0x00afc3f0
unsigned int FUN_00afc3f0_shell::CompressedArchiveFile_ReadString(void* a, unsigned int b)
{
    return 0;
}

struct FUN_00afc400_shell
{
    int CompressedArchiveFile_DoWrite(int a, int b);
};
// @fnv 0x00afc400
// src: COMMUNITY 0x00afc400
int FUN_00afc400_shell::CompressedArchiveFile_DoWrite(int a, int b)
{
    return 0;
}

struct Inner
{
    virtual void Slot0();
    virtual void Slot1();
    int field;
};

struct FUN_00afc720_shell
{
    Archive* owner;
    void EnterInnerCriticalSection();
};
// If owner is set, tries to enter the critical section in owner->inner and calls Slot1 when that fails.
// @fnv 0x00afc720
void FUN_00afc720_shell::EnterInnerCriticalSection()
{
    if (owner)
    {
        Inner* p = reinterpret_cast<Inner*>(reinterpret_cast<char*>(owner) + sizeof(BSFile));
        if (!TryEnterCriticalSection((CRITICAL_SECTION*)&p->field))
            p->Slot1();
    }
}

namespace fnv_00afcd10 {
extern MemoryManager g_memoryManager;
struct FUN_00afcd10_shell
{
    void* BSSimpleArray_DebugText_sPrintData_1024_Allocate(unsigned int count);
};
// Allocates count << 2 bytes via g_memoryManager.Allocate and returns the resulting pointer.
// @fnv 0x00afcd10
// src: COMMUNITY 0x00afcd10
void* FUN_00afcd10_shell::BSSimpleArray_DebugText_sPrintData_1024_Allocate(unsigned int count)
{
    void* result = g_memoryManager.Allocate(count << 2);
    return result;
}
}  // namespace fnv_00afcd10

namespace fnv_00afcd40 {
extern MemoryManager g_memoryManager;
struct FUN_00afcd40_shell
{
    void BSSimpleArray_DebugText_sPrintData_1024_Deallocate(void* ptr);
};
// @fnv 0x00afcd40
// src: COMMUNITY 0x00afcd40
void FUN_00afcd40_shell::BSSimpleArray_DebugText_sPrintData_1024_Deallocate(void* pMemory)
{
    g_memoryManager._DeallocateAlias(pMemory);
}
}  // namespace fnv_00afcd40

namespace fnv_00afcd60 {
extern MemoryManager g_memoryManager;
struct FUN_00afcd60_shell
{
    void* BSSimpleArray_DebugText_sPrintData_1024_Reallocate(void* p, unsigned int count);
};
// @fnv 0x00afcd60
// src: COMMUNITY 0x00afcd60
void* FUN_00afcd60_shell::BSSimpleArray_DebugText_sPrintData_1024_Reallocate(void* p, unsigned int count)
{
    return g_memoryManager.Reallocate(p, count << 2);
}
}  // namespace fnv_00afcd60

extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);

// Skips a leading backslash and, if the path starts with "Data\" or "data\", advances past that prefix; returns the resulting path pointer.
// @fnv 0x00b014b0
const char* __cdecl SkipDataPrefix(const char* path)
{
    if (*path == '\\')
        ++path;
    if (FUN_00ec8a19(path, "Data\\", 5) == 0 || FUN_00ec8a19(path, "data\\", 5) == 0)
        path += 5;
    return path;
}

namespace fnv_00af5700 {
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
int __cdecl _stricmp(const char*, const char*);
struct FileFinder
{
    int GetFileLocation(char* apFileName, char* apPath, unsigned int auiArchiveType, unsigned int auiFlags);
};
extern FileFinder* g_fileFinder;
struct ArchiveListNode
{
    BSFile* pArchive;
    ArchiveListNode* pNext;
};
extern ArchiveListNode* DAT_011f8160;
void __cdecl RemoveArchiveFile(BSFile* apArchive);

// @fnv 0x00af5700
// src: COMMUNITY 0x00af5700
bool __cdecl ArchiveManager_CloseArchive(char* apFileName)
{
    char acPath[260];
    if (!DAT_011f8160)
        return false;
    strcpy_s(acPath, 260, apFileName);
    if (!(g_fileFinder ? g_fileFinder->GetFileLocation(apFileName, acPath, 1, 0xffffffff) : 0))
        return false;
    ArchiveListNode* pnode = DAT_011f8160;
    while (pnode)
    {
        BSFile* parchive = pnode->pArchive;
        if (parchive)
        {
            const char* pArchiveName = parchive->FileName();
            if (!_stricmp(pArchiveName, acPath))
            {
                RemoveArchiveFile(parchive);
                return true;
            }
        }
        pnode = pnode->pNext;
    }
    return false;
}
}  // namespace fnv_00af5700

namespace fnv_00af5fa0 {
int __cdecl ArchiveManager_GetArchiveTypeFromFileName(const char* apFileName);
const char* __cdecl SkipDataPrefix(const char* apFileName);

struct FileNameHash
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDirHash,
                                                     FileNameHash& arFileHash);
};


extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
// @fnv 0x00af5fa0
void* LoadFileFromArchives(const char* apFileName, unsigned int auiBufferSize, unsigned int aeArchiveTypeFlags)
{
    unsigned int uiFolderIndex = 0;
    unsigned int uiFileIndex = 0;
    FileNameHash kFileNameHash;
    FileNameHash kDirectoryNameHash;
    apFileName = SkipDataPrefix(apFileName);
    if (aeArchiveTypeFlags == 0xffff)
        aeArchiveTypeFlags = ArchiveManager_GetArchiveTypeFromFileName(apFileName);
    FileNameHash::CreateDirectoryAndFileHashes(apFileName, kDirectoryNameHash, kFileNameHash);
    BSSimpleList<NiPointer<Archive> >* pCurrentElementNext = DAT_011f8160;
    while (pCurrentElementNext)
    {
        NiPointer<Archive> sparchive(pCurrentElementNext->m_item);
        if (sparchive && sparchive->HasArchiveTypeFlags(aeArchiveTypeFlags) &&
            sparchive->FindFile_00af9bf0((int)&kDirectoryNameHash, (int)&kFileNameHash, (int*)&uiFolderIndex,
                                    (int)&uiFileIndex, (int)apFileName))
        {
            return sparchive->OpenFile(uiFolderIndex, uiFileIndex, auiBufferSize, apFileName);
        }
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    return 0;
}
}  // namespace fnv_00af5fa0

namespace fnv_00af6160 {
int __cdecl ArchiveManager_GetArchiveTypeFromFileName(const char* apFileName);
const char* __cdecl SkipDataPrefix(const char* apFileName);

struct FileNameHash
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDirHash,
                                                     FileNameHash& arFileHash);
};


extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
extern CRITICAL_SECTION DAT_011f8170;
// @fnv 0x00af6160
Archive* FindArchiveForFile(const char* apFileName, unsigned int aeArchiveTypeFlags)
{
    if (!DAT_011f8160)
        return 0;
    unsigned int uiFolderIndex;
    unsigned int uiFileIndex;
    FileNameHash kFileNameHash;
    FileNameHash kDirectoryNameHash;
    apFileName = SkipDataPrefix(apFileName);
    if (aeArchiveTypeFlags == 0xffff)
        aeArchiveTypeFlags = ArchiveManager_GetArchiveTypeFromFileName(apFileName);
    FileNameHash::CreateDirectoryAndFileHashes(apFileName, kDirectoryNameHash, kFileNameHash);
    EnterCriticalSection(&DAT_011f8170);
    BSSimpleList<NiPointer<Archive> >* pCurrentElementNext = DAT_011f8160;
    while (pCurrentElementNext)
    {
        NiPointer<Archive> sparchive(pCurrentElementNext->m_item);
        if (sparchive && sparchive->HasArchiveTypeFlags(aeArchiveTypeFlags) &&
            sparchive->FindFile_00af9bf0((int)&kDirectoryNameHash, (int)&kFileNameHash, (int*)&uiFolderIndex,
                                    (int)&uiFileIndex, (int)apFileName))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return sparchive;
        }
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    LeaveCriticalSection(&DAT_011f8170);
    return 0;
}
}  // namespace fnv_00af6160

namespace fnv_00af7e80 {
struct FUN_00afd390_class
{
    void* v;
    void* __thiscall UpdateState_00afd390(const char*, int);
};

struct FUN_00afcf00_class
{
    int __thiscall BSHash_WildCardCompare(void*);
};

struct Local28
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    FUN_00afd390_class obj;
    void* f;
};

// @fnv 0x00af7e80
// src: COMMUNITY 0x00af7e80
bool __cdecl ArchiveManager_WildCardMatch(const char* path, FUN_00afcf00_class* obj)
{
    Local28 l;
    l.obj.UpdateState_00afd390(path, 0);
    if (obj->BSHash_WildCardCompare(&l.obj) == 0)
        return true;
    return false;
}
}  // namespace fnv_00af7e80

namespace fnv_00afcce0 {
extern int DAT_010a469c;

struct FUN_00afcde0_shell
{
    void* vptr;
    void InitArray(unsigned int, unsigned int);
    void* InitializeFields_00afcce0();
};

// Sets the vtable pointer to DAT_010a469c, calls InitArray with 0 and 0, and returns this.
// @fnv 0x00afcce0
// src: GUESS 0x00afcce0 (confidence: low)
void* FUN_00afcde0_shell::InitializeFields_00afcce0()
{
    int a;
    int b;
    vptr = &DAT_010a469c;
    InitArray(0, 0);
    return this;
}
}  // namespace fnv_00afcce0

// 0x00af8e60 calls these three cleanup methods, which Archive.h does not yet declare.
struct ArchiveCleanupMethods : Archive
{
    void ReleaseOwnedMemory();
    void FreeNames(int);
    void FreeEntries();
};
inline NiRefObject::~NiRefObject()
{
    InterlockedDecrement(reinterpret_cast<volatile long*>(&ms_lObjectCount));
}
inline FUN_0044fae0_CriticalSection::~FUN_0044fae0_CriticalSection()
{
    DeleteCriticalSection(&m_kCriticalSection);
}
// @fnv 0x00af8e60
Archive::~Archive()
{
    reinterpret_cast<ArchiveCleanupMethods*>(this)->ReleaseOwnedMemory();
    reinterpret_cast<ArchiveCleanupMethods*>(this)->FreeNames(0);
    reinterpret_cast<ArchiveCleanupMethods*>(this)->FreeEntries();
}

namespace fnv_00af9230 {
extern MemoryManager g_memoryManager;
// 0x00af9230: Archive.h lacks ReleaseOwnedMemory; storage comes entirely from Archive.
struct ArchiveDirectoryNamesRelease : public Archive
{
    inline bool IsStatic()
    {
        return m_ucStatus & 4;
    }
    inline void SetOwned(bool b)
    {
        if (b)
            m_ucStatus |= 0x10;
        else
            m_ucStatus &= ~0x10;
    }
    void ReleaseOwnedMemory();
};
// If the object is not static, deallocates m_pDirectoryNames and m_puiDirectoryNameOffsets, nulls both pointers, then clears the owned flag.
// @fnv 0x00af9230
void ArchiveDirectoryNamesRelease::ReleaseOwnedMemory()
{
    if (!IsStatic())
    {
        if (m_pDirectoryNames)
        {
            void* p = m_pDirectoryNames;
            g_memoryManager._DeallocateAlias(p);
        }
        if (m_puiDirectoryNameOffsets)
        {
            void* pExtra = m_puiDirectoryNameOffsets;
            g_memoryManager._DeallocateAlias(pExtra);
        }
        m_pDirectoryNames = 0;
        m_puiDirectoryNameOffsets = 0;
    }
    SetOwned(0);
}
}  // namespace fnv_00af9230

namespace fnv_00af9410 {
extern MemoryManager g_memoryManager;
struct FUN_00af9410_entry
{
    int a;
    int b;
    int c;
    void* mem;
};
// 0x00af9410: Archive.h lacks FreeEntries; storage comes entirely from Archive.
struct ArchiveEntriesRelease : public Archive
{
    inline unsigned int GetCount()
    {
        return m_uiDirectoryCount;
    }
    inline bool IsStatic()
    {
        return m_ucStatus & 4;
    }
    void FreeEntries();
};
// If the object is not static, deallocates each entry's mem and the reinterpret_cast<FUN_00af9410_entry*>(this->pEntries) array, then clears reinterpret_cast<FUN_00af9410_entry*>(this->pEntries).
// @fnv 0x00af9410
void ArchiveEntriesRelease::FreeEntries()
{
    if (!IsStatic())
    {
        if (reinterpret_cast<FUN_00af9410_entry*>(this->pEntries))
        {
            void* i;
            unsigned int p;
            void* pEntries;
            for (p = 0; p < GetCount(); p++)
            {
                i = reinterpret_cast<FUN_00af9410_entry*>(this->pEntries)[p].mem;
                g_memoryManager._DeallocateAlias(i);
            }
            pEntries = reinterpret_cast<FUN_00af9410_entry*>(this->pEntries);
            g_memoryManager._DeallocateAlias(pEntries);
        }
        this->pEntries = 0;
    }
}
}  // namespace fnv_00af9410

namespace fnv_00af9ad0 {
struct FUN_00af9ad0_entry
{
    int a;
    int b;
    unsigned int size;
    void* base;
    inline unsigned int GetSize()
    {
        return size;
    }
    inline void* GetBase()
    {
        return base;
    }
};
// 0x00af9ad0: Archive.h lacks FindEntryIndex; storage comes entirely from Archive.
struct ArchiveEntryIndexLookup : public Archive
{
    inline unsigned int GetCount()
    {
        return m_uiDirectoryCount;
    }
    int FindEntryIndex(unsigned int addr);
};
// Scans the reinterpret_cast<FUN_00af9ad0_entry*>(pEntries) array and returns the index whose base..base+size<<4 range contains addr, or -1 if none does.
// @fnv 0x00af9ad0
int ArchiveEntryIndexLookup::FindEntryIndex(unsigned int uiAddress)
{
    for (unsigned int i = 0; i < GetCount(); i++)
    {
        FUN_00af9ad0_entry* a = reinterpret_cast<FUN_00af9ad0_entry*>(pEntries) + i;
        unsigned int base = uiAddress;
        unsigned int e = (unsigned int)a->GetBase();
        unsigned int size = a->GetSize() << 4;
        if (base >= e && base < e + size)
            return i;
    }
    return -1;
}
}  // namespace fnv_00af9ad0

extern int DAT_010a469c;

struct _BSAHelper
{
    void Clear(bool b);
};

struct FUN_00afcdc0_StandIn
{
    void* vptr;
    void ResetVirtualTableAndClear_00afcdc0();
};

// Sets the object's vtable pointer to DAT_010a469c and calls Clear(true) on it.
// @fnv 0x00afcdc0
// src: GUESS 0x00afcdc0 (confidence: medium)
void FUN_00afcdc0_StandIn::ResetVirtualTableAndClear_00afcdc0()
{
    int _t;
    *(void**)this = &DAT_010a469c;
    ((_BSAHelper*)this)->Clear(true);
}

namespace fnv_00af5320 {
int __stricmp(const char*, const char*);

inline const char* GetArchiveName(const NiPointer<Archive>& m_pArchive)
{
    return m_pArchive->FileName();
}
struct ArchiveListNode
{
    NiPointer<Archive> spItem;
    ArchiveListNode* pNext;
};
extern ArchiveListNode* _DAT_011f8160;
extern CRITICAL_SECTION DAT_011f8170;

// Searches the archive list under the critical section for an entry whose file name matches apName case-insensitively and returns it, else 0.
// @fnv 0x00af5320
Archive* __cdecl FindArchiveByName(const char* apName)
{
    if (!_DAT_011f8160)
        return 0;
    EnterCriticalSection(&DAT_011f8170);
    ArchiveListNode* pNode = _DAT_011f8160;
    while (pNode)
    {
        NiPointer<Archive> m_pArchive(pNode->spItem);
        if (m_pArchive && !__stricmp(GetArchiveName(m_pArchive), apName))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return m_pArchive;
        }
        pNode = pNode->pNext;
    }
    LeaveCriticalSection(&DAT_011f8170);
    return 0;
}
}  // namespace fnv_00af5320

namespace fnv_00afa550 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;
struct ArchiveFileEntryStand
{
    unsigned int iNameHash;
    unsigned int iDirHash;
    unsigned int iSize;
    unsigned int iOffset;
    unsigned int GetSize() const
    {
        return iSize & 0x3fffffff;
    }
    bool IsCompressed() const
    {
        return iSize & 0x40000000;
    }
};
struct ArchiveFolderEntryStand
{
    unsigned int iHash;
    unsigned int iCount;
    unsigned int iOffset;
    ArchiveFileEntryStand* pFiles;
};
struct ArchiveFileOpen;
struct FUN_00afb300 : public ArchiveFile
{
    FUN_00afb300(const char*, ArchiveFileOpen*, unsigned int, unsigned int, int);
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* p);
};
struct FUN_00afc430 : public CompressedArchiveFile
{
    FUN_00afc430(const char*, ArchiveFileOpen*, unsigned int, unsigned int, int);
    static void* operator new(unsigned int uiSize)
    {
        return _g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* p);
};
// 0x00afa550: Archive.h lacks IsFileEntryValid and this OpenFile signature.
struct ArchiveFileOpen : public Archive
{
    bool GetArchiveFlag(unsigned int uiFlag) const
    {
        return !!(m_uiArchiveFlags & uiFlag);
    }
    bool IsFileEntryValid(ArchiveFileEntryStand*, bool);
    ArchiveFile* OpenFile(int iFolder, int iFile, int iMode, const char* pName);
};

// @fnv 0x00afa550
ArchiveFile* ArchiveFileOpen::OpenFile(int iFolder, int iFile, int iMode, const char* pName)
{
    ArchiveFile* pArchiveFile = 0;
    ArchiveFileEntryStand* pEntry = &reinterpret_cast<ArchiveFolderEntryStand*>(pEntries)[iFolder].pFiles[iFile];
    if (pEntry && IsFileEntryValid(pEntry, false))
    {
        unsigned int iOffset = pEntry->iOffset & 0x7fffffff;
        if (GetArchiveFlag(4) == pEntry->IsCompressed())
        {
            pArchiveFile = new FUN_00afb300(pName, this, iOffset, pEntry->GetSize(), iMode);
        }
        else
        {
            pArchiveFile = new FUN_00afc430(pName, this, iOffset, pEntry->GetSize(), iMode);
        }
    }
    return pArchiveFile;
}
}  // namespace fnv_00afa550

namespace fnv_00afa750 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct ArchiveFileEntryStand
{
    unsigned int hash[2];
    unsigned int size;
    unsigned int offset;
    __forceinline bool IsCompressionToggled()
    {
        return size & 0x40000000;
    }
    __forceinline unsigned int GetSize()
    {
        return size & 0x3fffffff;
    }
    __forceinline unsigned int GetOffset()
    {
        return offset & 0x7fffffff;
    }
};
struct ArchiveFileCreate;
struct FUN_00afb300 : ArchiveFile
{
    FUN_00afb300(unsigned int, ArchiveFileCreate*, unsigned int, unsigned int, unsigned int);
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
struct FUN_00afc430 : CompressedArchiveFile
{
    FUN_00afc430(unsigned int, ArchiveFileCreate*, unsigned int, unsigned int, unsigned int);
    __forceinline static void* operator new(unsigned int s)
    {
        return g_memoryManager.Allocate(s);
    }
};
// 0x00afa750: Archive.h lacks IsFileEntryValid and the ArchiveFileEntryStand overload.
struct ArchiveFileCreate : public Archive
{
    __forceinline bool IsCompressed()
    {
        return (m_uiArchiveFlags & 4) != 0;
    }
    bool IsFileEntryValid(ArchiveFileEntryStand*, bool);
    ArchiveFile* CreateArchiveFile(ArchiveFileEntryStand*, unsigned int, unsigned int);
};
// If entry is valid and passes IsFileEntryValid, allocates a compressed or uncompressed archive file matching the archive's compression state and returns it.
// @fnv 0x00afa750
ArchiveFile* ArchiveFileCreate::CreateArchiveFile(ArchiveFileEntryStand* entry, unsigned int a, unsigned int auiUnk)
{
    ArchiveFile* file = 0;
    if (entry)
    {
        if (IsFileEntryValid(entry, false))
        {
            if (IsCompressed() == entry->IsCompressionToggled())
                file = new FUN_00afb300(auiUnk, this, entry->GetOffset(), entry->GetSize(), a);
            else
                file = new FUN_00afc430(auiUnk, this, entry->GetOffset(), entry->GetSize(), a);
        }
    }
    return file;
}
}  // namespace fnv_00afa750

namespace fnv_00afc7f0 {

struct FUN_00afc7f0
{
    NiPointer<Archive> m_spArchive;

    ~FUN_00afc7f0();
    void ReleaseStorage_00afcaf0();
};

// Destructor that calls FUN_00afcaf0 and releases the held Archive through the NiPointer member.
// @fnv 0x00afc7f0
FUN_00afc7f0::~FUN_00afc7f0()
{
    int l1, l2, l3, l4, l5, l6, l7, l8;
    ReleaseStorage_00afcaf0();
}
}  // namespace fnv_00afc7f0

namespace fnv_00afc880 {

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

struct NP_afc
{
    NiPointer<Archive> m_spArchive;
    NP_afc* m_pkNext;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }

    NP_afc(NP_afc* other) : m_spArchive(other->m_spArchive), m_pkNext(0)
    {}

// src: COMMUNITY 0x00afc770
    NP_afc* BSSimpleList_SetItem(NP_afc* other)
    {
        if (m_spArchive.m_pObject != other->m_spArchive.m_pObject)
        {
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->DecrementReferenceCount();
            }
            m_spArchive.m_pObject = other->m_spArchive.m_pObject;
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->IncrementReferenceCount();
            }
        }
        return this;
    }

    void PushArchive(NP_afc*);
};

// @fnv 0x00afc880
void NP_afc::PushArchive(NP_afc* other)
{
    if (other->m_spArchive == 0)
        return;

    if (ArchivePointerNotEqual(m_spArchive, 0))
    {
        NP_afc* pNode = new NP_afc(this);
        pNode->m_pkNext = m_pkNext;
        m_pkNext = pNode;
        BSSimpleList_SetItem(other);
    }
    else
    {
        BSSimpleList_SetItem(other);
    }
}
}  // namespace fnv_00afc880

namespace fnv_00afcc10 {

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM _g_memoryManager;

struct NP_afc
{
    NiPointer<Archive> m_spArchive;
    NP_afc* m_pkNext;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }

    NP_afc(NP_afc* other) : m_spArchive(other->m_spArchive), m_pkNext(0)
    {}

// src: COMMUNITY 0x00afc770
    NP_afc* BSSimpleList_SetItem(NP_afc* other)
    {
        if (m_spArchive.m_pObject != other->m_spArchive.m_pObject)
        {
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->DecrementReferenceCount();
            }
            m_spArchive.m_pObject = other->m_spArchive.m_pObject;
            if (m_spArchive.m_pObject)
            {
                m_spArchive.m_pObject->IncrementReferenceCount();
            }
        }
        return this;
    }

    void AppendArchive(NP_afc*);
};

// Appends a copy of other's archive to the end of the list, or assigns it to the tail node if that node has no archive.
// @fnv 0x00afcc10
void NP_afc::AppendArchive(NP_afc* other)
{
    if (other->m_spArchive == 0)
        return;

    NP_afc* cur = this;
    while (cur->m_pkNext != 0)
    {
        cur = cur->m_pkNext;
    }

    if (ArchivePointerNotEqual(cur->m_spArchive, 0))
    {
        cur->m_pkNext = new NP_afc(other);
    }
    else
    {
        cur->BSSimpleList_SetItem(other);
    }
}
}  // namespace fnv_00afcc10

namespace fnv_00af6540 {
struct FileNameHash;

struct FileNameHash
{
    unsigned char cLast;
    unsigned int uiCRC;
};


extern BSSimpleList<NiPointer<Archive> >* DAT_011f8160;
// @fnv 0x00af6540
BSFileEntry* FindFileEntryInArchives(int aeArchiveTypeIndex, FileNameHash& arDirectoryHash,
                                     FileNameHash& arFileNameHash, const char* apFileName)
{
    BSSimpleList<NiPointer<Archive> >* pCurrentElementNext = DAT_011f8160;
    while (pCurrentElementNext)
    {
        NiPointer<Archive> sparchive(pCurrentElementNext->m_item);
        BSFileEntry* pReturn;
        if (sparchive && sparchive->HasArchiveType(aeArchiveTypeIndex))
        {
            pReturn =
                (BSFileEntry*)sparchive->GetFileEntryForFile((int)&arDirectoryHash, (int)&arFileNameHash, (int)apFileName);
            if (pReturn)
                return pReturn;
        }
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    return 0;
}
}  // namespace fnv_00af6540

struct MemMgr_00affd80
{
    void* Allocate(unsigned int);
};
struct DeallocMM_00affd80
{
    void _DeallocateAlias(void*);
};
extern MemMgr_00affd80 _g_memoryManager;
extern int DAT_010a2480;
extern unsigned int DAT_011acff8;
extern __declspec(thread) int DAT_tls_memctx;
__forceinline void* operator new[](unsigned int auiSize)
{
    return _g_memoryManager.Allocate(auiSize);
}
__forceinline void operator delete[](void* apMem)
{
    ((DeallocMM_00affd80*)&_g_memoryManager)->_DeallocateAlias(apMem);
}
__forceinline int GetMemCtx_00affd80()
{
    return DAT_tls_memctx;
}
__forceinline void SetMemCtx_00affd80(int aiCtx)
{
    DAT_tls_memctx = aiCtx;
}
struct MemCtxScope_00affd80
{
    int iOld;
    __forceinline MemCtxScope_00affd80(int aiCtx)
    {
        iOld = GetMemCtx_00affd80();
        DAT_tls_memctx = aiCtx;
    }
    __forceinline ~MemCtxScope_00affd80()
    {
        SetMemCtx_00affd80(iOld);
    }
};

// @fnv 0x00affd80
bool BSFile::SetBufferSize(unsigned int auiSize)
{
    bool bResult = true;
    unsigned int uiFileSize = GetSize();
    unsigned int uiMax2 = uiFileSize < 0x4000 ? 0x4000 : uiFileSize;
    if (auiSize > uiMax2)
        auiSize = uiMax2;
    if (auiSize == m_uiBufferAllocSize)
        return bResult;
    MemCtxScope_00affd80 kCtx3(0x17);
    NiFile::Seek(0, DAT_010a2480);
    Flush();
    delete[] m_pBuffer;
    m_uiBufferAllocSize = auiSize;
    m_pBuffer = new char[m_uiBufferAllocSize];
    if (!m_pBuffer)
    {
        m_uiBufferAllocSize = DAT_011acff8;
        m_pBuffer = new char[m_uiBufferAllocSize];
        bResult = false;
    }
    m_uiBufferSize = 0;
    return bResult;
}

namespace fnv_00af96d0 {
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

struct MemMgrStand
{
    void* Allocate(unsigned int auiSize);
    void Deallocate(void* apMem);
};
extern MemMgrStand g_arcMemMgr;
extern int DAT_011ace04;
extern int DAT_010a2480;

inline void* operator new[](unsigned int auiSize)
{
    return g_arcMemMgr.Allocate(auiSize);
}
inline void operator delete[](void* apMem)
{
    g_arcMemMgr.Deallocate(apMem);
}

inline unsigned int ArcLoadChars(NiBinaryStream& arStream, char* apBuffer, unsigned int auiCount)
{
    unsigned int uiCompSize = 1;
    unsigned int uiRet = arStream.BinaryRead(apBuffer, auiCount, &uiCompSize, 1);
    return uiRet;
}

// 0x00af96d0 returns char* with unsigned folder index; Archive.h declares int with signed index.
struct ArchiveFileNameLookup : public Archive
{
    inline bool HasFileNames()
    {
        return (m_uiArchiveFlags & 2) != 0;
    }
    inline bool HasFlag20()
    {
        return (m_uiArchiveFlags & 0x20) != 0;
    }
    inline bool CheckCache(bool abFlag, int aiVal)
    {
        return Archive_CheckRetain(abFlag, aiVal);
    }
    static inline int GetCacheVal()
    {
        return DAT_011ace04;
    }
    inline unsigned int GetFolderFileCount(unsigned int auiFolder)
    {
        return pEntries[auiFolder].m_uiCount;
    }
    inline void CopyName(char* apDest, const char* apSrc)
    {
        strcpy_s(apDest, 0x100, apSrc);
    }
    char* Archive_GetFileString(unsigned int auiFolder, unsigned int auiFile);
};

// @fnv 0x00af96d0
// src: COMMUNITY 0x00af96d0
char* ArchiveFileNameLookup::Archive_GetFileString(unsigned int auiFolder, unsigned int auiFile)
{
    if (HasNameTable())
    {
        return m_ppuiFileNameOffsets[auiFolder][auiFile] + m_pFileNames;
    }
    else if (HasFileNames())
    {
        if (m_pFileNames)
        {
            delete[] m_pFileNames;
            m_pFileNames = 0;
        }
        unsigned int uiPos = 0;
        m_pFileNames = new char[0x100];
        if (CheckCache(HasFlag20(), GetCacheVal()))
        {
            unsigned int uiNameOffset = m_uiFileNamesOffset + m_ppuiFileNameOffsets[auiFolder][auiFile];
            Seek(uiNameOffset, DAT_010a2480);
            ArcLoadChars(*this, m_pFileNames + uiPos, 1);
            while (m_pFileNames[uiPos++])
            {
                ArcLoadChars(*this, m_pFileNames + uiPos, 1);
            }
            return m_pFileNames;
        }
        else
        {
            char* pNamesBlock = new char[m_uiFileNamesLength + 1];
            Seek(m_uiFileNamesOffset, DAT_010a2480);
            ArcLoadChars(*this, pNamesBlock, m_uiFileNamesLength);
            pNamesBlock[m_uiFileNamesLength] = 0;
            char* pCurName = pNamesBlock;
            for (unsigned int i = 0; i < auiFolder; i++)
            {
                for (unsigned int j = 0; j < GetFolderFileCount(i); j++)
                {
                    pCurName += strlen(pCurName) + 1;
                    if (pCurName >= pNamesBlock + m_uiFileNamesLength)
                    {
                        *m_pFileNames = 0;
                        delete[] pNamesBlock;
                        return m_pFileNames;
                    }
                }
            }
            for (unsigned int k = 0; k < auiFile; k++)
            {
                pCurName += strlen(pCurName) + 1;
                if (pCurName >= pNamesBlock + m_uiFileNamesLength)
                {
                    *m_pFileNames = 0;
                    delete[] pNamesBlock;
                    return m_pFileNames;
                }
            }
            CopyName(m_pFileNames, pCurName);
            delete[] pNamesBlock;
            return m_pFileNames;
        }
    }
    return 0;
}
}  // namespace fnv_00af96d0

inline void Archive::Lock()
{
    EnterCriticalSection(&m_kLock.m_kCriticalSection);
}
inline void Archive::Unlock()
{
    LeaveCriticalSection(&m_kLock.m_kCriticalSection);
}

inline void ArchiveFile::LockArchive(char* name)
{
    if (GetArchive())
        GetArchive()->Lock();
}
inline void ArchiveFile::UnlockArchive()
{
    if (GetArchive())
        GetArchive()->Unlock();
}
inline unsigned int ArchiveFile::GetTruePos()
{
    return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
}

// @fnv 0x00afbc70
unsigned int ArchiveFile::ReadFromArchive(void* apBuffer, unsigned int auiSize)
{
    unsigned int uiRead = 0;
    LockArchive(GetArchive()->FileName());
    unsigned int uiPos = m_uiFileIndex + GetTruePos();
    if (GetArchive()->GetTruePosition() != uiPos)
        GetArchive()->Seek(uiPos, 0);
    uiRead = GetArchive()->Read(*reinterpret_cast<BSStringT<wchar_t>*>(apBuffer), m_uiValueId);
    m_uiBufferSize += uiRead;
    if (GetArchive())
        GetArchive()->Unlock();
    return uiRead;
}

namespace fnv_00afbde0 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

// 0x00afbde0 uses this ArchiveFile-local pointer wrapper; all stream storage is shared BSFile.
struct ArchiveFileReadMethods : BSFile
{
    NiPointer<Archive> m_pArchive;
    unsigned int m_uiFileIndex;
    unsigned int GetPos() const
    {
        return m_iBufferSize != -1 ? m_iBufferSize : m_uiBufferSize;
    }
    void LockArc(const char* apName)
    {
        if (m_pArchive)
            EnterCriticalSection(&m_pArchive->m_kLock.m_kCriticalSection);
    }
    unsigned int ArchiveFile_Read(void* buf, unsigned int size);
};

// @fnv 0x00afbde0
// src: XBOX_PDB 0x00afbde0
unsigned int ArchiveFileReadMethods::ArchiveFile_Read(void* apBuffer, unsigned int size)
{
    unsigned int uiRead = 0;
    LockArc(m_pArchive->FileName());
    unsigned int uiPos = m_uiFileIndex + GetPos();
    if (m_pArchive->GetTruePosition() != uiPos)
        m_pArchive->Seek(uiPos, 0);
    uiRead = m_pArchive->Read(*reinterpret_cast<BSStringT<char>*>(apBuffer), m_uiValueId);
    m_uiBufferSize += uiRead;
    if (m_pArchive)
        LeaveCriticalSection(&m_pArchive->m_kLock.m_kCriticalSection);
    return uiRead;
}
}  // namespace fnv_00afbde0

struct ArchiveEntryBuf
{
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct ArchiveArray
{
    ArchiveEntryBuf** data;
    unsigned int size;
    unsigned int alloc;
    virtual ~ArchiveArray();
    unsigned int GetSize() const
    {
        return size;
    }
    ArchiveEntryBuf* GetAt(unsigned int idx) const
    {
        return data[idx];
    }
};

struct ArchiveList
{
    NiPointer<Archive> m_item;
    ArchiveList* m_pkNext;
    ~ArchiveList();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            ArchiveList* pNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            ArchiveList* pDel = m_pkNext;
            delete pDel;
            m_pkNext = pNext;
        }
        m_item = NiPointer<Archive>(0);
    }
};

extern ArchiveArray* DAT_011f8168;
extern ArchiveArray* DAT_011f816c;
extern NiPointer<Archive> DAT_011f8190[2][9];
inline NiPointer<Archive>& GetArchivePtr(int aiType, unsigned int auiIndex)
{
    return DAT_011f8190[aiType][auiIndex];
}

// Frees the archive list and both archive arrays, then clears the two rows of archive pointers.
// @fnv 0x00af5820
void __cdecl ClearArchiveTables()
{
    unsigned int i;
    unsigned int uiIndex2;
    unsigned int k;

    if (DAT_011f8160)
    {
        reinterpret_cast<ArchiveList*>(DAT_011f8160)->RemoveAll();
        delete reinterpret_cast<ArchiveList*>(DAT_011f8160);
        DAT_011f8160 = 0;
    }
    if (DAT_011f8168)
    {
        for (i = 0; i < DAT_011f8168->GetSize(); i++)
        {
            delete DAT_011f8168->GetAt(i);
        }
        delete DAT_011f8168;
    }
    if (DAT_011f816c)
    {
        for (uiIndex2 = 0; uiIndex2 < DAT_011f816c->GetSize(); uiIndex2++)
        {
            delete DAT_011f816c->GetAt(uiIndex2);
        }
        delete DAT_011f816c;
    }
    for (k = 0; k < 9; k++)
    {
        GetArchivePtr(0, k) = 0;
        GetArchivePtr(1, k) = 0;
    }
}

// 0x00af5e40: Archive.h lacks HasFile; the reference-counted storage is shared.
struct ArchiveFilePresence : public Archive
{
    bool HasFile(FileNameHash* apDirHash, FileNameHash* apFileHash, const char* apName);
};

struct ArcNode_af5
{
    ArchiveFilePresence* item;
    ArcNode_af5* next;
};

// Normalizes apName, hashes it into directory and file hashes, then walks the archive list and returns true if any archive contains the file.
// @fnv 0x00af5e40
bool __cdecl HasFileInArchives(const char* apName)
{
    if (!DAT_011f8160)
        return false;
    apName = SkipDataPrefix(apName);
    FileNameHash kDirHash6;
    FileNameHash kFileHash;
    HashPathComponents(apName, &kDirHash6, &kFileHash);
    ArcNode_af5* pNode = (ArcNode_af5*)DAT_011f8160;
    while (pNode)
    {
        NiPointer<ArchiveFilePresence> spArchive3(*(const NiPointer<ArchiveFilePresence>*)&pNode->item);
        if (spArchive3 && spArchive3->HasFile(&kDirHash6, &kFileHash, apName))
            return true;
        pNode = pNode->next;
    }
    return false;
}

namespace fnv_00af6690 {

struct ArchiveNode
{
    NiPointer<Archive> spItem;
    ArchiveNode* next;
};
extern ArchiveNode* g_pArchiveList;

// Walks the archive list and returns the first FindEntry result from an archive whose types match auiTypes, or 0.
// @fnv 0x00af6690
int __cdecl FindEntryInArchives(unsigned int auiTypes, int aiArg1, int aiArg2, int aiArg3)
{
    ArchiveNode* pNode = g_pArchiveList;
    while (pNode)
    {
        NiPointer<Archive> m_pArchive(pNode->spItem);
        if (m_pArchive && m_pArchive->HasArchiveTypeFlags(auiTypes))
        {
            int iResult = m_pArchive->GetFileEntryForFile(aiArg1, aiArg2, aiArg3);
            if (iResult)
                return iResult;
        }
        pNode = pNode->next;
    }
    return 0;
}
}  // namespace fnv_00af6690

extern CRITICAL_SECTION DAT_011f8170;
// 0x00af6910 calls 0x00afdc00 on the +0x160 header; BSArchiveHeader.h lacks that lookup method.
struct ArchiveDirectoryIndex : BSArchiveHeader
{
    bool BSArchive_IsFileEntryInArchive(const FileNameHash* key);
};
struct LookupArchive : Archive
{
    unsigned int GetTypes() const
    {
        const LookupArchive* archive = this;
        return archive->m_usFlags;
    }
    bool Contains(const FileNameHash* key)
    {
        return reinterpret_cast<ArchiveDirectoryIndex*>(reinterpret_cast<char*>(this) + sizeof(BSFile) + sizeof(NiRefObject))->BSArchive_IsFileEntryInArchive(key);
    }
};
__forceinline void AddArchiveReference(RefObj* reference)
{
    InterlockedIncrement(&reference->refs);
}
__forceinline void ReleaseArchiveReference(RefObj* reference)
{
    if (!InterlockedDecrement(&reference->refs))
        reference->v1();
}

// Searches the archive list under a critical section for an archive whose types match and that contains key, falling back to a type-mismatched match.
// @fnv 0x00af6910
LookupArchive* __cdecl FindArchiveByKey(const FileNameHash* key, unsigned int types)
{
    EnterCriticalSection(&DAT_011f8170);
    LNode* node = DAT_011f8160;
    while (node)
    {
        NiPointer<LookupArchive> archive(*(const NiPointer<LookupArchive>*)&node->item);
        if (archive.m_pObject && ((unsigned short)(archive.m_pObject->GetTypes() & types) || types == 0xffff) &&
            archive.m_pObject->Contains(key))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return archive.m_pObject;
        }
        node = node->next;
    }
    if (types == 0xffff)
        return 0;
    node = DAT_011f8160;
    while (node)
    {
        NiPointer<LookupArchive> archive(*(const NiPointer<LookupArchive>*)&node->item);
        if (archive.m_pObject && !(unsigned short)(archive.m_pObject->GetTypes() & types) && archive.m_pObject->Contains(key))
        {
            LeaveCriticalSection(&DAT_011f8170);
            return archive.m_pObject;
        }
        node = node->next;
    }
    LeaveCriticalSection(&DAT_011f8170);
    return 0;
}

// The NiRefObject subobject follows BSFile; use its non-null subobject address for the inline refcount operations.

__forceinline unsigned int CountEntries(LNode* input)
{
    unsigned int node = 0;
    LNode* entry = input;
    while (entry)
    {
        if (entry->item)
            ++node;
        entry = entry->next;
    }
    return node;
}
void** __cdecl ArchiveManager_AddArchiveToFileList(Archive*, unsigned int, void**, FileNameHash*, FileNameHash*, LNode*, const char*);
// @fnv 0x00af6ba0
// src: COMMUNITY 0x00af6ba0
void __cdecl ArchiveManager_AddToFileList(LNode* entries, const char* path, const char* directory, unsigned int types)
{
    if (!DAT_011f8160)
        return;
    path = SkipDataPrefix(path);
    char buffer[260];
    strcpy_s(buffer, 260, directory);
    char* last = strrchr(buffer, '\\');
    if (last)
        last[1] = 0;
    if (types == 0xffff)
        types = ArchiveManager_GetArchiveTypeFromFileName(path);
    void** value = 0;
    FileNameHash bound, n;
    HashPathComponents(path, &bound, &n);
    unsigned int count_2 = CountEntries(entries);
    for (LNode* archive = DAT_011f8160; archive;)
    {
        NiPointer<Archive> owner(*(const NiPointer<Archive>*)&archive->item);
        if (owner && (unsigned short)(owner->GetFlags() & types))
            value = ArchiveManager_AddArchiveToFileList(owner, count_2, value, &bound, &n, entries, buffer);
        archive = archive->next;
    }
    if (value)
    {
        for (unsigned int i = 0; i < count_2; ++i)
        {
            delete[] (char*)value[i];
        }
        delete[] value;
    }
}

struct SortKey
{
    unsigned __int64 value;
};
__forceinline int CompareSortKeys(SortKey* current, SortKey* other)
{
    if (current->value < other->value)
        return -1;
    else if (current->value > other->value)
        return 1;
    return 0;
}

// Partitions entries around a pivot key and recurses to sort the range by SortKey value.
// @fnv 0x00af6e50
void __cdecl QuickSortSortKeys(SortKey** entries, int left, int right)
{
    int e = left;
    int l = right;
    int c = left;
    SortKey* j = entries[c];
    while (left < right)
    {
        {
            int p;
            SortKey* pCurrent;
            while ((pCurrent = entries[right], p = CompareSortKeys(pCurrent, j)) >= 0 && left < right)
                --right;
        }
        if (left != right)
        {
            entries[left] = entries[right];
            ++left;
        }
        {
            int p;
            SortKey* pCurrent;
            while ((pCurrent = entries[left], p = CompareSortKeys(pCurrent, j)) <= 0 && left < right)
                ++left;
        }
        if (left != right)
        {
            entries[right] = entries[left];
            --right;
        }
    }
    entries[left] = j;
    c = left;
    left = e;
    right = l;
    if (left < c)
        QuickSortSortKeys(entries, left, c - 1);
    if (right > c)
        QuickSortSortKeys(entries, c + 1, right);
}

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

// 0x00af7c40 calls 0x00afac20, absent from Archive.h; keep only local methods, using the shared layout.
struct ArchiveFilesByType : public Archive
{

    void ProcessFiles_afac20(int a, int b, int c);
};

struct ArchiveNode_af7
{
    ArchiveFilesByType* pItem;
    ArchiveNode_af7* pNext;
    bool IsEmpty() const
    {
        return !pNext && (bool)(int)(pItem == 0);
    }
};

extern ArchiveNode_af7* g_pArchiveList_af7;
extern long g_ArchiveListLock_af7;

// Locks the archive list, calls ProcessFiles_afac20 on every archive whose file types match auiType, then unlocks.
// @fnv 0x00af7c40
void __cdecl ProcessFilesByType(int aiArg1, int aiArg2, unsigned int auiType)
{
    EnterCriticalSection(&g_ArchiveListLock_af7);
    ArchiveNode_af7* pNode = g_pArchiveList_af7;
    while (pNode && !pNode->IsEmpty())
    {
        NiPointer<ArchiveFilesByType> m_pArchive(*(const NiPointer<ArchiveFilesByType>*)&pNode->pItem);
        if (m_pArchive->HasArchiveTypeFlags(auiType))
            m_pArchive->ProcessFiles_afac20(aiArg1, aiArg2, 0);
        pNode = pNode->pNext;
    }
    LeaveCriticalSection(&g_ArchiveListLock_af7);
}

__forceinline unsigned int ArchiveNameFileCount(Archive* archive) { return archive->m_uiFileCount; }
__forceinline unsigned int ArchiveNameBytes(Archive* archive) { return archive->m_uiFileNamesLength; }
__forceinline unsigned int ArchiveReadNames(Archive* archive, void* buffer, unsigned int size, unsigned int* unitSize)
{
    unsigned int result = archive->m_pfnRead(archive, buffer, size, unitSize, 1);
    archive->m_uiAbsoluteCurrentPos += result;
    return result;
}
__forceinline unsigned int ArchiveReadBytes(Archive* archive, void* buffer, unsigned int size)
{
    unsigned int unitSize = 1;
    unsigned int bytesReturned = ArchiveReadNames(archive, buffer, size, &unitSize);
    return bytesReturned;
}
__forceinline unsigned int ArchiveNameLength(Archive* archive, const char* name) { return strlen(name); }
// @fnv 0x00af8f10
void Archive::LoadNames()
{
    if (!ArchiveNameFileCount(this) || (m_pFileNames && m_ppuiFileNameOffsets))
        return;
    SetStatus<0x20>(false);
    if (m_ppuiFileNameOffsets)
    {
        for (unsigned int i = 0; i < GetDirectoryCount(); i++)
            delete[] m_ppuiFileNameOffsets[i];
        delete[] m_ppuiFileNameOffsets;
    }
    delete[] m_pFileNames;
    m_pFileNames = new char[ArchiveNameBytes(this)];
    m_ppuiFileNameOffsets = new unsigned int*[GetDirectoryCount()];
    if (HasArchiveFlag(2))
    {
        Seek(m_uiFileNamesOffset, DAT_010a2480);
        ArchiveReadBytes(this, m_pFileNames, ArchiveNameBytes(this));
        unsigned int offset = 0;
        for (unsigned int directory = 0; directory < GetDirectoryCount(); directory++)
        {
            m_ppuiFileNameOffsets[directory] = new unsigned int[GetFileCount(directory)];
            for (unsigned int file = 0; file < GetFileCount(directory); file++)
            {
                m_ppuiFileNameOffsets[directory][file] = offset;
                offset += ArchiveNameLength(this, m_pFileNames + offset) + 1;
            }
        }
    }
    SetStatus<0x20>(true);
}

namespace fnv_00af92f0 {
inline void BSFreeMem(void* apMem)
{
    g_memoryManager._DeallocateAlias(apMem);
}

// 0x00af92f0: Archive.h lacks FreeNames(bool); storage comes entirely from Archive.
struct ArchiveFileNamesRelease : public Archive
{

    bool IsRetainingNames()
    {
        return (m_ucStatus & 4) ? true : false;
    }
    void SetNamesFreed(bool abSet)
    {
        if (abSet)
            m_ucStatus |= 0x20;
        else
            m_ucStatus &= ~0x20;
    }

    void FreeNames(bool abKeepFileNames);
};

// Frees the directory strings buffer and, unless names are retained or kept, the file name strings, then clears the names-freed flag.
// @fnv 0x00af92f0
void ArchiveFileNamesRelease::FreeNames(bool abKeepFileNames)
{
    unsigned int i;
    if (!IsRetainingNames())
    {
        if (m_pFileNames)
        {
            char* pBuf = m_pFileNames;
            g_memoryManager._DeallocateAlias(pBuf);
        }
        m_pFileNames = 0;
        if (m_ppuiFileNameOffsets && !abKeepFileNames)
        {
            for (i = 0; i < GetDirectoryCount(); i++)
            {
                unsigned int* pName = m_ppuiFileNameOffsets[i];
                g_memoryManager._DeallocateAlias(pName);
            }
            {
                unsigned int** ppNames = m_ppuiFileNameOffsets;
                g_memoryManager._DeallocateAlias(ppNames);
            }
            m_ppuiFileNameOffsets = 0;
        }
    }
    SetNamesFreed(false);
}
}  // namespace fnv_00af92f0

extern "C" void __cdecl FUN_00ecbc5b(char*, unsigned int);
extern int __cdecl _stricmp(const char*, const char*);
void __cdecl FNV_Warning(const char*, ...);
extern const char DAT_010a4518[];
struct MemoryManagerDealloc
{
    void Deallocate(void*);
};
// 0x00af9c50 calls GetString (0x00af94c0), absent from Archive.h; all storage is inherited.
struct ArchiveSearch : Archive
{
    bool Disabled()
    {
        return (m_ucStatus & 1) ? true : false;
    }
    bool HasNames()
    {
        return (m_uiArchiveFlags & 1) != 0;
    }
    unsigned int Count()
    {
        return m_uiDirectoryCount;
    }
    FileNameHash* GetHash(unsigned int i)
    {
        return (FileNameHash*)(((Entry16*)pEntries) + i);
    }
    const char* GetString(unsigned int);
};
inline int FileNameHash::Compare(FileNameHash* rhs)
{
    if (*(unsigned __int64*)this < *(unsigned __int64*)rhs)
        return -1;
    else if (*(unsigned __int64*)this > *(unsigned __int64*)rhs)
        return 1;
    return 0;
}
inline unsigned int TextLength(const char* text)
{
    return _strlen(text);
}
inline void CopyText(char* dst, unsigned int size, const char* src)
{
    _strcpy_s(dst, size, src);
}
inline void LowerText(char* dst, unsigned int size)
{
    FUN_00ecbc5b(dst, size);
}
// @fnv 0x00af9c50
bool ArchiveHashLookup::FindHashEntry(int pKey, int* piIndex, int pPath)
{
    if (((ArchiveSearch*)this)->Disabled())
        return false;
    bool result = false;
    unsigned int index = ((ArchiveSearch*)this)->m_uiCacheIndex;
    if (index < ((ArchiveSearch*)this)->Count())
    {
        if (((FileNameHash*)pKey)->Compare(((ArchiveSearch*)this)->GetHash(index)) == 0)
        {
            *piIndex = index;
            result = true;
        }
    }
    if (!result)
    {
        ((ArchiveSearch*)this)->m_uiCacheOffset = -1;
        if (((ArchiveSearch*)this)->Count())
        {
            unsigned int value = 0;
            unsigned int i = ((ArchiveSearch*)this)->Count();
            unsigned int x = 0;
            unsigned int f = 1;
            int s = 0;
            while (f)
            {
                f = (i - value) >> 1;
                x = value + f;
                s = ((FileNameHash*)pKey)->Compare(((ArchiveSearch*)this)->GetHash(x));
                if (s > 0)
                    value = x;
                else if (s < 0)
                    i = x;
                else
                    break;
            }
            if (s == 0)
            {
                *piIndex = x;
                ((ArchiveSearch*)this)->m_uiCacheIndex = x;
                result = true;
                if (pPath && DAT_011f8154 && ((ArchiveSearch*)this)->HasNames())
                {
                    char path[260];
                    _splitpath_s((const char*)pPath, 0, 0, path, 260, 0, 0, 0, 0);
                    const char* y = ((ArchiveSearch*)this)->GetString(x);
                    char* w = new char[TextLength(y) + 1];
                    char* v = new char[TextLength(path) + 1];
                    CopyText(w, _strlen(y) + 1, y);
                    CopyText(v, _strlen(path) + 1, path);
                    v[_strlen(v) - 1] = 0;
                    LowerText(w, _strlen(w) + 1);
                    LowerText(v, _strlen(v) + 1);
                    if (_stricmp(w, v))
                    {
                        FNV_Warning(DAT_010a4518, y, path);
                        result = false;
                    }
                    delete[] w;
                    delete[] v;
                }
            }
        }
    }
    return result;
}

namespace fnv_00afa120 {
struct Entry97
{
    unsigned int hash0, hash1;
    unsigned int size, offset;
};
struct Group97
{
    unsigned int hash0, hash1;
    unsigned int count;
    Entry97* entries;
    unsigned int Size() const
    {
        return count;
    }
};
struct Hash97
{
    int BSHash_Compare(const Entry97&);
};
struct MM97
{
    void* Game_DoHeapAlloc(unsigned int);
    void MemoryManager_Deallocate(void*);
};
extern MM97 DAT_011f6238;
extern char DAT_010a454c[];
inline void Copy97(char* d, unsigned int n, const char* s)
{
    strcpy_s(d, n, s);
}
void __cdecl FUN_00ecbc5b(char*, unsigned int);
inline void Lower97(char* d, unsigned int n)
{
    FUN_00ecbc5b(d, n);
}
inline unsigned int Length97(const char* s)
{
    return strlen(s);
}
extern "C" char* __cdecl strtok_s(char*, const char*, char**);
extern "C" int __cdecl _stricmp(const char*, const char*);
void __cdecl Warning_005b5e40(const char*, ...);
// 0x00afa120: Archive.h lacks FUN_00afa120, FUN_00afb190 and IsFileEntryValid.
struct ArchiveFileHashLookup : public Archive
{
    bool IsFileEntryValid(Entry97*, bool);
    bool Archive_CheckInvalidateFile(Entry97*, const char*);
    const char* Archive_GetFileString(unsigned int, unsigned int);
    bool Archive_FindFileInDirectory(unsigned int, Hash97*, unsigned int*, const char*, bool);
};
// Looks up an entry in a group by hash, checking the m_uiCacheOffset index first then binary-searching, and writes the found index to output.
// @fnv 0x00afa120
// src: COMMUNITY 0x00afa120
bool ArchiveFileHashLookup::Archive_FindFileInDirectory(unsigned int group, Hash97* hash, unsigned int* puiOutput, const char* path, bool ignore)
{
    if ((m_ucStatus & 1) ? true : false)
        return false;
    bool found5 = false;
    Group97* files31 = &reinterpret_cast<Group97*>(pEntries)[group];
    unsigned int last9 = m_uiCacheOffset;
    if (last9 < files31->Size())
    {
        Entry97* entry = &files31->entries[last9];
        if (IsFileEntryValid(entry, ignore) && hash->BSHash_Compare(*entry) == 0)
        {
            if (!Archive_CheckInvalidateFile(entry, path))
            {
                *puiOutput = last9;
                found5 = true;
            }
            else
                return false;
        }
    }
    if (!found5 && files31->Size())
    {
        Entry97* candidate26 = 0;
        unsigned int low10 = 0;
        unsigned int high27 = files31->count;
        unsigned int middle91 = 0;
        unsigned int step13 = 1;
        int comparison20 = 0;
        while (step13)
        {
            step13 = (high27 - low10) >> 1;
            middle91 = low10 + step13;
            candidate26 = &files31->entries[middle91];
            comparison20 = hash->BSHash_Compare(*candidate26);
            if (comparison20 > 0)
                low10 = middle91;
            else if (comparison20 < 0)
                high27 = middle91;
            else
                break;
        }
        if (comparison20 == 0 && IsFileEntryValid(candidate26, ignore) && !Archive_CheckInvalidateFile(candidate26, path))
        {
            *puiOutput = middle91;
            m_uiCacheOffset = middle91;
            found5 = true;
            if (path && DAT_011f8154 && (unsigned char)((m_uiArchiveFlags & 2) ? 1 : 0))
            {
                char filename4[260];
                _splitpath_s(path, 0, 0, 0, 0, filename4, 260, 0, 0);
                const char* original27 = Archive_GetFileString(group, middle91);
                char* left22 = new char[Length97(original27) + 1];
                char* right19 = new char[Length97(filename4) + 1];
                Copy97(left22, Length97(original27) + 1, original27);
                Copy97(right19, Length97(filename4) + 1, filename4);
                char* context20;
                strtok_s(left22, ".", &context20);
                strtok_s(right19, DAT_010a454c, &context20);
                Lower97(left22, Length97(left22) + 1);
                Lower97(right19, Length97(right19) + 1);
                if (_stricmp(left22, right19))
                {
                    Warning_005b5e40("DEFAULT: HashMap Collision between %s and %s", original27, filename4);
                    found5 = false;
                }
                delete[] left22;
                delete[] right19;
            }
        }
    }
    return found5;
}
}  // namespace fnv_00afa120

namespace fnv_00afad00 {
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
template <unsigned int N> inline int strcat_s(char (&dest)[N], const char* src)
{
    return strcat_s(dest, N, src);
}
int __cdecl FUN_00ecbf05(const char*, int);
extern const char DAT_010a4580[];
extern char DAT_011f8050[];
extern const char DAT_010a4346[];
struct BSHashA
{
    unsigned char cLast;
    unsigned char cSecondToLast;
    unsigned char cLength;
    unsigned char cFirst;
    unsigned int uiCRC;
};
inline unsigned int ZeroAD()
{
    return 0;
}
struct SubAD
{
    unsigned int lo;
    unsigned int hi;
    unsigned int pad8;
    unsigned int flags;
    void ClearLowAD()
    {
        flags = (ZeroAD() & 0x7fffffff) | (flags & 0x80000000);
    }
};
struct EntryAD
{
    unsigned int lo;
    unsigned int hi;
    unsigned int count;
    SubAD* subs;
    unsigned int GetCount() const
    {
        return count;
    }
    SubAD* GetSub(int idx)
    {
        return subs + idx;
    }
};
struct Hash64
{
    unsigned __int64 v;
};
inline int HashCompareAD(const Hash64& a, const Hash64& b)
{
    if (a.v < b.v)
        return -1;
    else if (a.v > b.v)
        return 1;
    return 0;
}
struct ListAD1
{
    int pad0;
    FUN_00afce90_S** items;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
    FUN_00afce90_S** GetItems()
    {
        return items;
    }
    FUN_00afce90_S* GetItemAt(int idx)
    {
        return items[idx];
    }
};
struct ListAD2
{
    int pad0;
    Hash64** items;
    unsigned int count;
    unsigned int GetCount() const
    {
        return count;
    }
    Hash64** GetItems()
    {
        return items;
    }
    Hash64* GetItemAt(int idx)
    {
        return items[idx];
    }
};
extern ListAD1* DAT_011f816c;
extern ListAD2* DAT_011f8168;
inline ListAD1* List1Ptr()
{
    return DAT_011f816c;
}
inline ListAD2* List2Ptr()
{
    return DAT_011f8168;
}
// 0x00afad00 returns a count and calls missing GetString/FUN_00b01510/FUN_00b01590; shared ClearMatchedEntries returns void.
struct ArchiveMatchedEntries : public Archive
{
    unsigned int GetCount170() const
    {
        return m_uiDirectoryCount;
    }
    bool CheckFlagAD(unsigned int bit) const
    {
        return (this->m_uiArchiveFlags & bit) != 0;
    }
    const char* GetString(int);
    void Archive_PlatformGetLastWriteTime(BSHashA*);
    int Archive_InvalidateOlderFilesByPath(char*, const char*, BSHashA*);
    int ClearMatchedEntries();
};
// @fnv 0x00afad00
int ArchiveMatchedEntries::ClearMatchedEntries()
{
    int count = 0;
    int i;
    EntryAD* entry;
    int handle;
    {
        char buf[260];
        if (DAT_011f816c == 0 && DAT_011f8168 == 0)
            return 0;
        if (this->CheckFlagAD(1) && this->CheckFlagAD(2))
        {
            for (i = 0; i < this->GetCount170(); i++)
            {
                entry = reinterpret_cast<EntryAD*>(this->pEntries) + i;
                if (DAT_011f816c != 0)
                {
                    bool found = false;
                    int j;
                    for (j = 0; j < List1Ptr()->GetCount(); j++)
                    {
                        FUN_00afce90_S* item = List1Ptr()->GetItemAt(j);
                        if (item->BSHash_Compare(*(unsigned __int64*)entry) == 0)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (found)
                    {
                        int k;
                        for (k = 0; k < entry->GetCount(); k++)
                        {
                            entry->GetSub(k)->ClearLowAD();
                        }
                        count += entry->GetCount();
                        continue;
                    }
                }
                strcpy_s(buf, 260, DAT_010a4580);
                strcat_s(buf, this->GetString(i));
                handle = FUN_00ecbf05(buf, 0);
                if (handle != -1)
                {
                    SubAD* sub;
                    int mm;
                    for (mm = 0; mm < entry->GetCount(); mm++)
                    {
                        bool found2;
                        sub = entry->subs + mm;
                        if (DAT_011f8168 != 0)
                        {
                            found2 = false;
                            int n;
                            for (n = 0; n < List2Ptr()->GetCount(); n++)
                            {
                                Hash64* item2 = List2Ptr()->GetItemAt(n);
                                if (HashCompareAD(*item2, *(Hash64*)sub) == 0)
                                {
                                    found2 = true;
                                    break;
                                }
                            }
                            if (found2)
                            {
                                sub->ClearLowAD();
                                count += 1;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            BSHashA hash;
            this->Archive_PlatformGetLastWriteTime(&hash);
            count = this->Archive_InvalidateOlderFilesByPath(DAT_011f8050, DAT_010a4346, &hash);
        }
        return count;
    }
}
}  // namespace fnv_00afad00

extern "C" int __cdecl _strnicmp(const char*, const char*, unsigned int);

struct FUN_00afb520_mm
{
    void MemoryManager_Deallocate(void* p);
};
extern FUN_00afb520_mm DAT_011f6238;

struct FUN_00afb520_sub
{
    virtual void Slot0();
    virtual void Slot1();
    int unk08;
};

// @fnv 0x00afb520
ArchiveFile::~ArchiveFile()
{
    if (m_pBuffer != 0)
    {
        void* buf = m_pBuffer;
        DAT_011f6238.MemoryManager_Deallocate(buf);
    }
    m_pBuffer = 0;
    m_bGood = 0;
    {
        FUN_00afb520_sub* sub;
        {
            int* pSp = reinterpret_cast<int*>(&m_pArchive);
            if (*pSp != 0)
            {
                sub = (FUN_00afb520_sub*)((char*)(*pSp) + 0x158);
                if (TryEnterCriticalSection((CRITICAL_SECTION*)&sub->unk08) == 0)
                {
                    sub->Slot1();
                }
            }
        }
    }
}

extern int DAT_010a2484;
void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);
__forceinline void RenderCopyData(void* dest, const void* source, unsigned int size)
{
    FUN_00ec44d0(dest, source, size);
}
// 0x00afb7a0: the three low-level NiFile calls below lack shared declarations; use the shared Archive storage.
struct ArchiveRead : Archive
{
    char* NiFile_GetBuffer();
    void NiFile_Seek(int, int);
    unsigned int FUN_00aa1570(void*, unsigned int);
    int GetCurrentPos()
    {
        int value = m_uiFilePos;
        return value;
    }
    int GetReadSize()
    {
        int value = m_uiBufferReadSize;
        return value;
    }
    unsigned int GetBufferSize()
    {
        unsigned int value = m_uiBufferAllocSize;
        return value;
    }
    unsigned int GetLength()
    {
        unsigned int value = m_uiValueId;
        return value;
    }
    void SetPos(int pos)
    {
        m_uiPos = pos;
    }
    void SetReadSize(int size)
    {
        m_uiBufferReadSize = size;
    }
    void SetTruePos(int pos)
    {
        m_uiBufferSize = pos;
    }
};
// @fnv 0x00afb7a0
unsigned int ArchiveFile::ReadAtOffset(char* output, unsigned int size, unsigned int offset)
{
    int end;
    int start = 0;
    int position = m_uiFileIndex + m_uiBufferSize + offset;
    LockArchive(reinterpret_cast<ArchiveRead*>(GetArchive())->FileName());
    int difference = reinterpret_cast<ArchiveRead*>(GetArchive())->GetCurrentPos();
    int read = difference - reinterpret_cast<ArchiveRead*>(GetArchive())->GetReadSize();
    if (read <= position && difference > position)
    {
        int bufferOffset = position - read;
        int available = reinterpret_cast<ArchiveRead*>(GetArchive())->GetReadSize() - bufferOffset;
        if (available > (int)size)
            available = size;
        RenderCopyData(output, reinterpret_cast<ArchiveRead*>(GetArchive())->NiFile_GetBuffer() + bufferOffset, available);
        output += available;
        if (size == available)
        {
            UnlockArchive();
            return size;
        }
        size -= available;
        position += available;
        start = available;
    }
    reinterpret_cast<ArchiveRead*>(GetArchive())->SetPos(0);
    reinterpret_cast<ArchiveRead*>(GetArchive())->SetReadSize(0);
    if (end = position - difference)
    {
        reinterpret_cast<ArchiveRead*>(GetArchive())->NiFile_Seek(end, DAT_010a2484);
        reinterpret_cast<ArchiveRead*>(GetArchive())->SetTruePos(position);
    }
    if (m_uiBufferSize + size + offset > m_uiValueId)
        size = m_uiValueId - (m_uiBufferSize + offset);
    unsigned int copied = 0;
    unsigned int result = 0;
    if ((unsigned int)position < reinterpret_cast<ArchiveRead*>(GetArchive())->GetLength())
    {
        if (size < reinterpret_cast<ArchiveRead*>(GetArchive())->GetBufferSize())
        {
            result = reinterpret_cast<ArchiveRead*>(GetArchive())->FUN_00aa1570(reinterpret_cast<ArchiveRead*>(GetArchive())->NiFile_GetBuffer(), size);
            reinterpret_cast<ArchiveRead*>(GetArchive())->SetPos(result);
            reinterpret_cast<ArchiveRead*>(GetArchive())->SetReadSize(result);
            copied = result < size ? result : size;
            RenderCopyData(output, reinterpret_cast<ArchiveRead*>(GetArchive())->NiFile_GetBuffer(), copied);
        }
        else
        {
            result = reinterpret_cast<ArchiveRead*>(GetArchive())->FUN_00aa1570(output, size);
            copied = result;
        }
    }
    else
    {
        result = 0;
    }
    reinterpret_cast<ArchiveRead*>(GetArchive())->SetTruePos(position + result);
    UnlockArchive();
    return copied + start;
}

struct ArchiveObjectList
{
    NiPointer<Archive> m_item;
    ArchiveObjectList* m_pkNext;
    ~ArchiveObjectList()
    {
        RemoveAll();
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            ArchiveObjectList* pkNext = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = pkNext;
        }
        m_item = NiPointer<Archive>(0);
    }
    static void operator delete(void* pvMem)
    {
        g_memoryManager._DeallocateAlias(pvMem);
    }
    bool IsEmpty() const
    {
        return m_pkNext == 0 && m_item == 0;
    }
    void RemoveItem(const NiPointer<Archive>& item);
};

// Removes the node whose item equals the given NiPointer<Archive> from the list, unlinking it and deleting it, or clearing the head item if it is the only node.
// @fnv 0x00afc960
void ArchiveObjectList::RemoveItem(const NiPointer<Archive>& item)
{
    if (item == 0 || IsEmpty())
        return;
    ArchiveObjectList* pkCur = this;
    ArchiveObjectList* pkPrev = this;
    while (pkCur && pkCur->m_item != item)
    {
        pkPrev = pkCur;
        pkCur = pkCur->m_pkNext;
    }
    if (pkCur)
    {
        if (pkCur == this)
        {
            if (m_pkNext)
            {
                pkPrev = m_pkNext;
                m_pkNext = pkPrev->m_pkNext;
                m_item = pkPrev->m_item;
                pkPrev->m_pkNext = 0;
                delete pkPrev;
            }
            else
            {
                m_item = 0;
            }
        }
        else
        {
            pkPrev->m_pkNext = pkCur->m_pkNext;
            pkCur->m_pkNext = 0;
            delete pkCur;
        }
    }
}

struct ListItem
{
    unsigned int value;
    ListItem* next;
    ~ListItem();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};

struct OwnerList
{
    Archive* object;
    ListItem* head;
// src: COMMUNITY 0x00afc770
    OwnerList* BSSimpleList_SetItem(const NiPointer<Archive>& rhs)
    {
        RefObj* r0 = 0;
        RefObj* r1 = 0;
        if (object != rhs.m_pObject)
        {
            if (object)
            {
                r0 = reinterpret_cast<RefObj*>(reinterpret_cast<char*>(object) + sizeof(BSFile));
                if (!InterlockedDecrement(&r0->refs))
                    r0->v1();
            }
            object = rhs.m_pObject;
            if (object)
            {
                r1 = reinterpret_cast<RefObj*>(reinterpret_cast<char*>(object) + sizeof(BSFile));
                InterlockedIncrement(&r1->refs);
            }
        }
        return this;
    }
    void ReleaseStorage_00afcaf0();
};

// Deletes every node in the head list, resetting each node's next pointer, then releases the object reference via FUN_00afc770 with a null reference.
// @fnv 0x00afcaf0
// src: GUESS 0x00afcaf0 (confidence: low)
void OwnerList::ReleaseStorage_00afcaf0()
{
    while (head)
    {
        ListItem* next = head->next;
        head->next = 0;
        delete head;
        head = next;
    }
    BSSimpleList_SetItem(NiPointer<Archive>());
}

namespace fnv_00af5480 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* lpcs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* lpcs);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plong);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plong);

extern MemoryManager g_memoryManager_af5480;

struct LNode_af5480
{
    Archive* m_pObject;
    LNode_af5480* m_pNext;
    void AddTail(NiPointer<Archive>& sp)
    {
        if (!sp.m_pObject)
            return;
        LNode_af5480* pNode = this;
        while (pNode->m_pNext)
            pNode = pNode->m_pNext;
        if (pNode->m_pObject)
        {
            LNode_af5480* pNew = (LNode_af5480*)g_memoryManager_af5480.Allocate(8);
            LNode_af5480* pInsert;
            if (pNew)
            {
                Archive* pkObject = sp.m_pObject;
                pNew->m_pObject = pkObject;
                if (pkObject)
                    pkObject->IncRefCount();
                pNew->m_pNext = 0;
                pInsert = pNew;
            }
            else
            {
                pInsert = 0;
            }
            pNode->m_pNext = pInsert;
        }
        else
        {
            NiPointer<Archive>* pOther = (NiPointer<Archive>*)pNode;
            NiPointer<Archive>* pSp = &sp;
            // The original list helper calls the outlined smart-pointer assignment.
#pragma inline_depth(0)
            *pOther = *pSp;
#pragma inline_depth()
        }
    }
};

extern LNode_af5480* g_pNode_11f8160;
extern char g_kCS_11f8170[];

// Locks g_kCS_11f8170, appends pkObj to the list at g_pNode_11f8160 via AddTail, then unlocks.
// @fnv 0x00af5480
void __cdecl AddObjectToList(Archive* pkObj)
{
    EnterCriticalSection(g_kCS_11f8170);
    if (g_pNode_11f8160)
    {
        NiPointer<Archive> sp(pkObj);
        g_pNode_11f8160->AddTail(sp);
    }
    LeaveCriticalSection(g_kCS_11f8170);
}
}  // namespace fnv_00af5480

namespace fnv_00af5550 {
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct LNode
{
    NiPointer<Archive> item;
    LNode* next;

    void DeleteNode(LNode* n);
    LNode* BSSimpleList_SetItem(LNode* a2);

    void Remove(NiPointer<Archive>& target)
    {
        LNode* head = (LNode*)0;
        LNode* tail = (LNode*)0;
        LNode* pNext = (LNode*)0;
        LNode* pPrev = (LNode*)0;
        if (!target.m_pObject)
            return;
        if (!next && !item.m_pObject)
            return;
        LNode* curr = this;
        LNode* prev = this;
        while (curr && curr->item.m_pObject != target.m_pObject)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
            return;
        if (curr == this)
        {
            if (next)
            {
                prev = next;
                next = prev->next;
                BSSimpleList_SetItem(prev);
                prev->next = (LNode*)0;
                DeleteNode(prev);
            }
            else
            {
                item = (Archive*)0;
            }
        }
        else
        {
            prev->next = curr->next;
            curr->next = (LNode*)0;
            DeleteNode(curr);
        }
    }
};

extern LNode* g_pLNode;
struct _RTL_CRITICAL_SECTION;
extern _RTL_CRITICAL_SECTION g_cs;
extern NiPointer<Archive> g_activeFile;
extern NiPointer<Archive> g_files[2][9];

inline NiPointer<Archive>& GetFile(int j, unsigned int i)
{
    return g_files[j][i];
}

// @fnv 0x00af5550
bool __cdecl RemoveArchiveFile(Archive* apFile)
{
    if (!g_pLNode || !apFile)
        return false;

    EnterCriticalSection(&g_cs);

    unsigned int i;
    {
        NiPointer<Archive> sp(apFile);
        g_pLNode->Remove(sp);
    }

    for (i = 0; i < 9; ++i)
    {
        if (static_cast<Archive*>(GetFile(0, i)) == apFile)
            GetFile(0, i) = (Archive*)0;
        if (static_cast<Archive*>(GetFile(1, i)) == apFile)
            GetFile(1, i) = (Archive*)0;
    }

    if ((bool)(int)(static_cast<Archive*>(g_activeFile) == apFile))
        g_activeFile = (Archive*)0;

    LeaveCriticalSection(&g_cs);
    return true;
}
}  // namespace fnv_00af5550

// The buffer size (+0x10, an NiFile field) that 0x00af4550 compares with the per-type minimum.
inline unsigned long Archive::BufferSize()
{
    return (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x10));
}

namespace fnv_00af4550 {
extern const char DAT_010a4398[];
extern const char DAT_010a43a8[];
extern unsigned char DAT_011acdf8;
extern const char* DAT_011f8158;
extern const char* DAT_011f815c;
extern const char DAT_010a433a[];
extern "C" int __cdecl _access(const char*, int);
inline Archive* GetForAssignment(const NiPointer<Archive>& archive)
{
    Archive* previous;
    unsigned long previousCount;
    return archive.m_pObject;
}
struct ArchiveName
{
    char name[8];
};
extern ArchiveName DAT_011ace08[26];
inline unsigned int MainArchiveGroup()
{
    return 0;
}
extern NiPointer<Archive> DAT_011f8190[2][9];
extern unsigned int DAT_011aced8[9];
struct ArchiveMemory
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern ArchiveMemory DAT_011f6238;
void __cdecl ArchiveManager_LoadInvalidationFile(const char*);
void* __cdecl LoadBSAFileHook(const char*, int, int);
inline char* AllocationResult(char* const& result)
{
    return result;
}
inline void ArchiveFree(void* const& data)
{
    DAT_011f6238.Deallocate(data);
}
inline int CopyPath(char* dest, unsigned int size, const char* source)
{
    return strcpy_s(dest, size, source);
}
inline int AppendPath(char* dest, unsigned int size, const char* source)
{
    return strcat_s(dest, size, source);
}
inline unsigned long TextLength(const char* text)
{
    return strlen(text);
}
// Builds a comma-separated list of .bsa files from Plugins.txt, loads each archive and registers it by type, returning false if any archive fails to load.
// @fnv 0x00af4550
// src: COMMUNITY 0x00af4550
bool __cdecl ArchiveManager_OpenMasterArchives()
{
    _iobuf* flags;
    char extra[260];
    unsigned int kSound;
    char* time;
    char* pItem;
    {
        bool pForm = true;
        {
            char pInfo[260];
            {
                char pResponse[260];
                {
                    unsigned long zz;
                    {
                        char* zz2;
                        if (!DAT_011acdf8)
                            return pForm;
                        ArchiveManager_LoadInvalidationFile(DAT_011f8158);
                        for (unsigned int i = 0; i < 25; i++)
                        {
                            unsigned int minimum = i;
                            for (unsigned int j = i + 1; j < 26; j++)
                            {
                                if (_stricmp(DAT_011ace08[j].name, DAT_011ace08[minimum].name) < 0)
                                    minimum = j;
                            }
                            if (i != minimum)
                            {
                                ArchiveName temp = DAT_011ace08[i];
                                DAT_011ace08[i] = DAT_011ace08[minimum];
                                DAT_011ace08[minimum] = temp;
                            }
                        }
                        zz = GetTickCount();
                        kSound = 32768;
                        zz2 = AllocationResult((char*)DAT_011f6238.Allocate(kSound));
                        CopyPath(zz2, kSound, DAT_011f815c);
                        sprintf_s(pResponse, 260, "%sPlugins.txt", DAT_010a433a + 1);
                        flags = 0;
                        fopen_s(&flags, pResponse, "r");
                        if (flags)
                        {
                            while (!feof(flags))
                            {
                                fgets(extra, 260, flags);
                                if (extra[0] != '#' && extra[0] && extra[0] != '\n')
                                {
                                    char* ext = strstr(extra, ".esp");
                                    if (!ext)
                                        ext = strstr(extra, ".esm");
                                    if (ext)
                                    {
                                        strcpy_s(ext, 260 - (ext - extra), ".bsa");
                                        strcpy_s(pInfo, 260, DAT_010a4398);
                                        strcat_s(pInfo, 260, extra);
                                        if (_access(pInfo, 0) != -1)
                                        {
                                            if (zz2[TextLength(zz2) - 2] == '\n')
                                                zz2[TextLength(zz2) - 2] = 0;
                                            AppendPath(zz2, 260, ", ");
                                            AppendPath(zz2, 260, extra);
                                        }
                                    }
                                }
                            }
                        }
                        pItem = zz2;
                        time = zz2;
                        strtok_s(time, ",", &zz2);
                        while (*time)
                        {
                            while (*time == ' ' || *time == '\t' || *time == '\n')
                                time++;
                            NiPointer<Archive> archive = (Archive*)LoadBSAFileHook(time, 0, 0);
                            if (archive)
                            {
                                for (unsigned int kind = 0; kind < 9; kind++)
                                {
                                    if (archive->HasType(kind))
                                    {
                                        if (!DAT_011f8190[MainArchiveGroup()][kind])
                                        {
                                            AssignArchivePointer(DAT_011f8190[MainArchiveGroup()][kind],
                                                                 GetForAssignment(archive));
                                            if (DAT_011aced8[kind] > archive->BufferSize())
                                                archive->SetBufferSize(DAT_011aced8[kind]);
                                        }
                                    }
                                }
                            }
                            else
                                pForm = false;
                            time = zz2;
                            strtok_s(time, DAT_010a43a8, &zz2);
                        }
                        ArchiveFree((void*)pItem);
                        zz = GetTickCount() - zz;
                        return pForm;
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00af4550

// @fnv 0x00af59e0
// src: COMMUNITY 0x00af59e0
void __cdecl nullsub_330()
{}

namespace fnv_00afd4e0 {
struct FileNameHash
{
    unsigned char unk00, unk01, unk02, unk03;
    unsigned int unk04;
};
int __cdecl FUN_00ec67aa(int);
extern char DAT_011acfbc[6][10];
// Hashes a name (and optional extension) into out's bytes and hash field, using FUN_00ec67aa per character and matching the extension against DAT_011acfbc.
// @fnv 0x00afd4e0
void __cdecl ComputeNameHash(const unsigned char* name, const unsigned char* extension, FileNameHash* out)
{
    const unsigned char* p;
    unsigned int hash4;
    int c3;
    out->unk03 = (unsigned char)FUN_00ec67aa(name[0]);
    out->unk04 = 0;
    hash4 = 0;
    if (!out->unk03)
    {
        out->unk02 = 0;
        out->unk01 = 0;
        out->unk00 = 0;
        return;
    }
    p = name + 1;
    if (p[0] && p[1] && p[2] && p[3] && false)
    {
        unsigned int count8 = 5;
        const unsigned char* endVal = p + 4;
        out->unk03 = (unsigned char)FUN_00ec67aa(p[2]);
        while (*endVal)
        {
            c3 = FUN_00ec67aa(*p);
            hash4 = c3 + (hash4 << 6) + (hash4 << 16) - hash4;
            ++count8;
            ++p;
            ++endVal;
        }
        out->unk02 = (unsigned char)count8;
        out->unk04 = hash4;
        out->unk01 = (unsigned char)FUN_00ec67aa(p[0]);
        out->unk00 = (unsigned char)FUN_00ec67aa(p[1]);
    }
    else if (p[0] && p[1])
    {
        unsigned int count4 = 3;
        const unsigned char* aEnd2 = p + 2;
        while (*aEnd2)
        {
            c3 = FUN_00ec67aa(*p);
            hash4 = c3 + (hash4 << 6) + (hash4 << 16) - hash4;
            ++count4;
            ++p;
            ++aEnd2;
        }
        out->unk02 = (unsigned char)count4;
        out->unk04 = hash4;
        out->unk01 = (unsigned char)FUN_00ec67aa(p[0]);
        out->unk00 = (unsigned char)FUN_00ec67aa(p[1]);
    }
    else
    {
        if (p[0])
        {
            out->unk00 = (unsigned char)FUN_00ec67aa(p[0]);
            out->unk02 = 2;
        }
        else
        {
            out->unk02 = 1;
            out->unk00 = out->unk03;
        }
        out->unk01 = 0;
    }
    if (extension)
    {
        char ext[16];
        char* dest6 = ext;
        p = extension;
        hash4 = 0;
        while (*p)
        {
            c3 = FUN_00ec67aa(*p);
            *dest6 = (char)c3;
            ++dest6;
            hash4 = c3 + (hash4 << 6) + (hash4 << 16) - hash4;
            ++p;
        }
        *dest6 = 0;
        out->unk04 += hash4;
        unsigned int code7 = *(unsigned int*)ext;
        for (unsigned int i4 = 0; i4 < 6; ++i4)
        {
            unsigned int test3 = *(unsigned int*)DAT_011acfbc[i4];
            if (test3 == code7)
            {
                out->unk03 = out->unk03 + (unsigned char)((i4 << 5) & 0x80);
                out->unk00 = out->unk00 + (unsigned char)((i4 << 6) & 0x80);
                out->unk01 = out->unk01 + (unsigned char)((i4 << 7) & 0x80);
                break;
            }
        }
    }
}
}  // namespace fnv_00afd4e0

namespace fnv_00af4be0 {
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
extern MemoryManagerAllocHelper g_memoryManager;
struct LNode;
extern LNode* DAT_011f8160;
static const char emptyPathWarning[] = "Loading a user created or misnamed BSA";
extern const char DAT_010a4454[];
extern const char DAT_010a444c[];
extern const char DAT_010a4444[];
extern const char DAT_010a443c[];
extern const char DAT_010a4434[];
extern const char DAT_010a442c[];
extern bool DAT_011acdf8;
int __cdecl strcpy_s(char*, unsigned int, const char*);
unsigned int __cdecl strlen(const char*);
const char* __cdecl FUN_00ec7750(const char*, const char*);
void __cdecl FNV_Warning(const char*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct OpenRef
{
    virtual void v0();
    virtual void Destroy();
    long refs;
    void Inc()
    {
        InterlockedIncrement(&refs);
    }
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            Destroy();
    }
};
inline bool ArchiveIsBad(Archive* archive)
{
    return (archive->m_ucStatus & 1) != 0 ? true : false;
}
inline const char* ArchiveName(Archive* archive)
{
    return archive->pFileName;
}
struct OpenPtr
{
    Archive* p;
    OpenPtr(Archive* a) throw() : p(a)
    {
        if (p)
            reinterpret_cast<OpenRef*>(reinterpret_cast<char*>(p) + sizeof(BSFile))->Inc();
    }
    ~OpenPtr()
    {
        if (p)
            reinterpret_cast<OpenRef*>(reinterpret_cast<char*>(p) + sizeof(BSFile))->Dec();
    }
    operator Archive*() const
    {
        return p;
    }
    OpenPtr& operator=(const OpenPtr&);
    OpenPtr(const OpenPtr& a) throw() : p(a.p)
    {
        if (p)
            reinterpret_cast<OpenRef*>(reinterpret_cast<char*>(p) + sizeof(BSFile))->Inc();
    }
};

struct OpenNode
{
    OpenPtr item;
    OpenNode* next;
    static void* operator new(unsigned int size)
    {
        return ((MemoryManagerAllocHelper*)&g_memoryManager)->Allocate(size);
    }
    OpenNode() throw() : item(0), next(0)
    {}
    OpenNode(const OpenPtr& p) throw() : item(p), next(0)
    {}
    static OpenNode* Create(const OpenPtr& value)
    {
        OpenNode* result = new OpenNode(value);
        return result;
    }
    static OpenNode* CreateDirect(const OpenPtr& value)
    {
        return new OpenNode(value);
    }
    void InsertCurrent(const OpenPtr& value)
    {
        if (!value.p)
            return;
        if (item.p)
        {
            OpenNode* insertedNode = CreateDirect(item);
            insertedNode->next = next;
            next = insertedNode;
            item = value;
        }
        else
            item = value;
    }
    void PushArchive(const OpenPtr& value)
    {
        if (!value.p)
            return;
        if (item.p)
        {
            OpenNode* allocatedNode = Create(item);
            OpenNode* insertedNode = allocatedNode;
            insertedNode->next = next;
            next = insertedNode;
            item = value;
        }
        else
            item = value;
    }
    void AppendArchive(const OpenPtr& value)
    {
        if (!value.p)
            return;
        OpenNode* tail = this;
        while (tail->next)
            tail = tail->next;
        if (tail->item.p)
        {
            OpenNode* allocated = Create(value);
            OpenNode* created = allocated;
            tail->next = created;
        }
        else
            tail->item = value;
    }
};

struct OpenFinder
{
    int Find(const char*, char*, int, int);
};
extern OpenFinder* g_fileFinder;
struct OpenPaths
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Resolve(const char*, char*);
    bool Check(int);
};
OpenPaths* __cdecl GetOpenPaths();
__forceinline void SetOpenNode(OpenNode* const& p)
{
    DAT_011f8160 = (LNode*)p;
}
// Opens a BSA archive by path, determines its load rank, and inserts it into the global archive list at the correct priority position.
// @fnv 0x00af4be0
// src: COMMUNITY 0x00af4be0
Archive* __cdecl LoadBSAFileHook(const char* path, unsigned short types, bool option)
{
    if (!DAT_011acdf8)
        return 0;
    char found3[260];
    char resolved2[260];
    strcpy_s(found3, 260, path);
    if (!(g_fileFinder ? g_fileFinder->Find(path, found3, 1, -1) : 0))
        return 0;
    if (GetOpenPaths()->Check((int)found3))
        GetOpenPaths()->Resolve(found3, resolved2);
    else
        strcpy_s(resolved2, 260, found3);
    Archive* archive5 = new Archive(resolved2, 0x40000, 0, option);
    if (!archive5 || !archive5->IsFileGood() || ArchiveIsBad(archive5))
    {
        delete archive5;
        return 0;
    }
    if (!DAT_011f8160)
        SetOpenNode(new OpenNode);
    int rank4 = 0;
    if (path && strlen(path) > 0)
    {
        if (FUN_00ec7750(path, "Fallo"))
            rank4 = 0;
        else if (FUN_00ec7750(path, "DeadM"))
            rank4 = 1;
        else if (FUN_00ec7750(path, "Hones"))
            rank4 = 2;
        else if (FUN_00ec7750(path, "Lones"))
            rank4 = 3;
        else if (FUN_00ec7750(path, "OldWo"))
            rank4 = 4;
        else if (FUN_00ec7750(path, "Updat"))
            rank4 = 5;
        else
        {
            FNV_Warning("Loading a user created or misnamed BSA");
            rank4 = 6;
        }
    }
    else
    {
        FNV_Warning(emptyPathWarning);
        rank4 = 6;
    }
    if (rank4 > 0)
    {
        OpenNode* node5 = (OpenNode*)DAT_011f8160;
        bool inserted7 = false;
        while (node5 && (Archive*)node5->item)
        {
            const char* existing3 = ArchiveName((Archive*)node5->item);
            if (existing3 && strlen(existing3) > 0)
            {
                if (FUN_00ec7750(existing3, DAT_010a442c))
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a4434))
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a443c) && rank4 > 1)
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a4444) && rank4 > 2)
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a444c) && rank4 > 3)
                    inserted7 = true;
                else if (FUN_00ec7750(existing3, DAT_010a4454) && rank4 > 3)
                    inserted7 = true;
            }
            if (inserted7)
            {
                node5->InsertCurrent(archive5);
                break;
            }
            node5 = node5->next;
        }
        if (!inserted7)
            ((OpenNode*)DAT_011f8160)->PushArchive(archive5);
    }
    else
        ((OpenNode*)DAT_011f8160)->AppendArchive(archive5);
    if (types)
        archive5->m_usFlags = types;
    return archive5;
}
}  // namespace fnv_00af4be0

// A BSA file record (0x10): name hash, directory hash, offset, size (bit 31 = compressed).
class ArchiveFileEntry
{
  public:
    unsigned int uiNameHash;
    unsigned int uiDirHash;
    unsigned int uiReserved;
    unsigned int uiSize;
};
namespace fnv_00af67d0 {

static __forceinline void AcquireReference(NiRefObject* o)
{
    o->IncRefCount();
}

extern Archive* DAT_011f8190[2][9];

static __forceinline Archive* GetArc(bool c, unsigned int i)
{
    return DAT_011f8190[c ? 1 : 0][i];
}
// Looks up the file path for an archive entry by index and compressed flag, copying it into pcOutput and returning whether a path was found.
// @fnv 0x00af67d0
// src: COMMUNITY 0x00af67d0
bool __cdecl ArchiveManager_GetFileNameForFileEntry(unsigned int uiIndex, ArchiveFileEntry* pkEntry, char* pcOutput)
{
    bool bHasPath = false;
    bool bIsCompressed = (pkEntry->uiSize & 0x80000000);
    NiPointer<Archive> spCurrent = GetArc(bIsCompressed, uiIndex);
    if (spCurrent)
    {
        spCurrent->Lock();
        const char* pcSource = spCurrent->Archive_GetFileNameForFileEntry(pkEntry);
        if (pcSource)
        {
            strcpy_s(pcOutput, 260, pcSource);
            bHasPath = true;
        }
        spCurrent->Unlock();
    }
    return bHasPath;
}
}  // namespace fnv_00af67d0

namespace fnv_00af7060 {
extern MemoryManager _g_memoryManager;
inline void* __cdecl operator new[](unsigned int n)
{
    return _g_memoryManager.Allocate(n);
}
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct HashKey
{
    unsigned int low, high;
    const unsigned __int64& Value() const
    {
        return *(const unsigned __int64*)this;
    }
    int Compare(const HashKey* rhs) const
    {
        if (Value() < rhs->Value())
            return -1;
        else if (Value() > rhs->Value())
            return 1;
        return 0;
    }
    int CompareTo(const HashKey* rhs) const
    {
        int order = Compare(rhs);
        return order;
    }
    HashKey(const char*, int);
    void* operator new(unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
};
inline unsigned int CombinedLength(const char* prefix, const char* name)
{
    unsigned int prefixLength = strlen(prefix);
    return prefixLength + strlen(name) + 1;
}
inline void CopyPath(char* dest, unsigned int size, const char* src)
{
    strcpy_s(dest, size, src);
}
inline void AppendPath(char* dest, unsigned int size, const char* src)
{
    strcat_s(dest, size, src);
}
void* __cdecl operator new(unsigned int);
// ArchivePathList: unit-local list node of path strings (item +0, next +4; BSSimpleList<const char*> shape), not the
// shared PathNode (NavMesh* at +0): 0x00af7060 walks it; its insert is 0x005ae3d0
struct ArchivePathList
{
    const char* path;
    ArchivePathList* next;
    ArchivePathList(const ArchivePathList*);
    void FUN_005ae3d0(char* const& value)
    {
        if (!value)
            return;
        if (path)
        {
            ArchivePathList* node = new ArchivePathList(this);
            node->next = next;
            next = node;
            path = value;
        }
        else
        {
            path = value;
        }
    }
};
struct FileRecord
{
    HashKey key;
    unsigned int size, offset;
};
struct DirectoryRecord
{
    unsigned int low, high, count;
    FileRecord* files;
    unsigned int Count()
    {
        return count;
    }
};
struct Filter
{
    int BSHash_WildCardCompare(FileRecord*);
};
// 0x00af7060: Archive.h lacks FindHashEntry/IsFileEntryValid and this filename lookup signature.
struct ArchivePathSearch : public Archive
{
    bool FindHashEntry(int, int*, int);
    bool IsFileEntryValid(FileRecord*, bool);
    const char* Archive_GetFileString(int, unsigned int);
};
void QuickSortSortKeys(HashKey**, unsigned int, unsigned int);
// @fnv 0x00af7060
// src: COMMUNITY 0x00af7060
HashKey** __cdecl ArchiveManager_AddArchiveToFileList(ArchivePathSearch* archive, unsigned int count, HashKey** keys, int directory,
                               Filter* filter, ArchivePathList* paths, const char* prefix)
{
    EnterCriticalSection(&archive->m_kLock.m_kCriticalSection);
    int directoryIndex;
    DirectoryRecord* dir;
    if (archive->FindHashEntry(directory, &directoryIndex, 0))
    {
        if (keys == 0 && count > 0)
        {
            keys = new HashKey*[count];
            ArchivePathList* node = paths;
            for (unsigned int keyIndex = 0; keyIndex < count; ++keyIndex)
            {
                const char* path = node->path;
                keys[keyIndex] = new HashKey(path, 0);
                node = node->next;
            }
            QuickSortSortKeys(keys, 0, count - 1);
        }
        dir = &reinterpret_cast<DirectoryRecord*>(archive->pEntries)[directoryIndex];
        for (unsigned int fileIndex = 0; fileIndex < dir->Count(); ++fileIndex)
        {
            FileRecord* file = &dir->files[fileIndex];
            if (archive->IsFileEntryValid(file, false))
            {
                int result = filter->BSHash_WildCardCompare(file);
                if (result == 0)
                {
                    bool found = false;
                    if (count != 0)
                    {
                        unsigned int lower3 = 0;
                        unsigned int upper8 = count;
                        unsigned int middle7 = 0;
                        unsigned int step2 = 1;
                        int compare3 = 0;
                        while (step2 != 0)
                        {
                            step2 = (upper8 - lower3) >> 1;
                            middle7 = lower3 + step2;
                            compare3 = file->key.CompareTo(keys[middle7]);
                            if (compare3 > 0)
                                lower3 = middle7;
                            else if (compare3 < 0)
                                upper8 = middle7;
                            else
                            {
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found)
                    {
                        const char* name = archive->Archive_GetFileString(directoryIndex, fileIndex);
                        unsigned int length = CombinedLength(prefix, name);
                        char* full = new char[length];
                        CopyPath(full, length, prefix);
                        AppendPath(full, length, name);
                        paths->FUN_005ae3d0(full);
                    }
                }
                else if (result < 0)
                    break;
            }
        }
    }
    LeaveCriticalSection(&archive->m_kLock.m_kCriticalSection);
    return keys;
}
}  // namespace fnv_00af7060

namespace fnv_00af7eb0 {
extern unsigned int DAT_011f81d8;
extern volatile long DAT_011f4400;
extern unsigned char DAT_011acdf9;
extern bool DAT_011f8154;
extern int DAT_011acdfc, DAT_011ace00, DAT_011ace04;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
struct FileStat077
{
    unsigned int dev;
    unsigned short inode, mode, links, uid, gid, alignment;
    unsigned int rdev, size;
    unsigned __int64 atime, mtime, ctime;
};
int __cdecl FUN_00ec923c(const char*, FileStat077*);
void __cdecl ProcessFilesByType(ArchiveEntry*, ArchiveEntry*, unsigned int);
inline unsigned int ArcLoadChars(BSFile& stream, void* buffer, unsigned int length)
{
    unsigned int uiCompSize = 1;
    unsigned int uiRet = stream.NiBinaryStream::BinaryRead(buffer, length, &uiCompSize, 1);
    return uiRet;
}
inline unsigned int ArcStringLength(const char* value)
{
    return strlen(value);
}
inline void ArcReadEntries(Archive& archive, ArchiveEntry* buffer, unsigned int count)
{
    ArcLoadChars(archive, buffer, count * sizeof(ArchiveEntry));
}
inline int CacheMode0()
{
    return DAT_011acdfc;
}
inline int CacheMode1()
{
    return DAT_011ace00;
}
inline int CacheMode2()
{
    return DAT_011ace04;
}
}  // namespace fnv_00af7eb0

// Archive::FUN_00afd020 is an inline function: the constructor below does not expand it (/Ob1) but keeps the
// frame slots of its inlinees at each of its four calls; its out-of-line copy is 0x00afd020.
// @fnv 0x00afd020
// src: COMMUNITY 0x00afd020
inline bool Archive::GetLoadStrings()
{
    ArgPair p[5];
    return (DAT_011acdf9 || DAT_011f8154 || (unsigned char)+((m_uiArchiveFlags & 0x80) != 0) ||
            (p[4].i = DAT_011acdfc, p[4].b = (m_uiArchiveFlags & 8) != 0, Archive_CheckRetain(p[4].b, p[4].i)) ||
            (p[3].i = DAT_011ace00, p[3].b = (m_uiArchiveFlags & 0x10) != 0, Archive_CheckRetain(p[3].b, p[3].i)) ||
            (p[2].i = DAT_011ace04, p[2].b = (m_uiArchiveFlags & 0x20) != 0, Archive_CheckRetain(p[2].b, p[2].i))) &&
           (!(unsigned short)(m_usFlags & 0x10) ||
            (p[1].i = DAT_011ace00, p[1].b = (m_uiArchiveFlags & 0x10) != 0, Archive_CheckRetain(p[1].b, p[1].i)) ||
            (p[0].i = DAT_011ace04, p[0].b = (m_uiArchiveFlags & 0x20) != 0, Archive_CheckRetain(p[0].b, p[0].i)));
}

using fnv_00af7eb0::ArcLoadChars;
using fnv_00af7eb0::ArcReadEntries;
using fnv_00af7eb0::ArcStringLength;
using fnv_00af7eb0::FileStat077;
// Opens a BSA archive, reads its header and entries, optionally caches directory and file names, and prepares file lists by type.
// @fnv 0x00af7eb0
Archive::Archive(const char* apPath, int aiMode, bool abHeaderOnly, bool abPrepare)
    : BSFile(apPath, 0, aiMode, false)
{
    m_uiID = fnv_00af7eb0::DAT_011f81d8++;
    m_uiCacheIndex = -1;
    m_uiCacheOffset = -1;
    pEntries = 0;
    m_pDirectoryNames = 0;
    m_puiDirectoryNameOffsets = 0;
    m_pFileNames = 0;
    m_ppuiFileNameOffsets = 0;
    m_ucStatus = 0;
    m_uiFileNamesOffset = 0;
    BSFile::Open(false, false);
    if (!IsFileGood())
        return;
    if (abHeaderOnly)
        SetStatus<8>(true);
    BSFile::SetEndianSwap(false);
    BSArchive* header = this;
    ArcLoadChars(*this, header, 0x24);
    if (!IsValid() || !IsVersionSupported())
    {
        SetStatus<1>(true);
        return;
    }
    if (GetVersion() < 0x68)
        ClearVersionFlag();
    if (!HasStatus(8))
    {
        unsigned int elapsedTmp = fnv_00af7eb0::GetTickCount();
        delete[] pEntries;
        pEntries = new ArchiveEntry[GetDirectoryCount()];
        ArcReadEntries(*this, pEntries, GetDirectoryCount());
        if (HasArchiveFlag(1) && GetLoadStrings())
        {
            SetStatus<0x10>(true);
            delete[] m_pDirectoryNames;
            delete[] m_puiDirectoryNameOffsets;
            m_pDirectoryNames = new char[GetDirectoryNamesLength()];
            m_puiDirectoryNameOffsets = new unsigned int[GetDirectoryCount()];
        }
        if (HasArchiveFlag(2) && GetLoadStrings())
        {
            SetStatus<0x20>(true);
            delete[] m_pFileNames;
            if (m_ppuiFileNameOffsets)
            {
                for (unsigned int i = 0; i < GetDirectoryCount(); ++i)
                    delete[] m_ppuiFileNameOffsets[i];
                delete[] m_ppuiFileNameOffsets;
            }
            m_pFileNames = new char[GetFileNamesLength()];
            m_ppuiFileNameOffsets = new unsigned int*[GetDirectoryCount()];
        }
        unsigned int dirOffset = 0;
        for (unsigned int i = 0; i < GetDirectoryCount(); ++i)
        {
            if (HasArchiveFlag(1))
            {
                unsigned char length;
                ArcLoadChars(*this, &length, 1);
                if (GetLoadStrings())
                {
                    ArcLoadChars(*this, m_pDirectoryNames + dirOffset, length);
                    m_puiDirectoryNameOffsets[i] = dirOffset;
                    dirOffset += length;
                }
                else
                {
                    char name[256];
                    ArcLoadChars(*this, name, length);
                }
            }
            ArchiveEntry* files = new ArchiveEntry[GetFileCount(i)];
            ArcReadEntries(*this, files, GetFileCount(i));
            SetFiles(i, files);
        }
        unsigned int fileOffset = 0;
        if (HasArchiveFlag(2))
        {
            m_uiFileNamesOffset = GetTruePosition();
            if (GetLoadStrings())
            {
                ArcLoadChars(*this, m_pFileNames, GetFileNamesLength());
                for (unsigned int i = 0; i < GetDirectoryCount(); ++i)
                {
                    m_ppuiFileNameOffsets[i] = new unsigned int[GetFileCount(i)];
                    for (unsigned int j = 0; j < GetFileCount(i); ++j)
                    {
                        m_ppuiFileNameOffsets[i][j] = fileOffset;
                        fileOffset += ArcStringLength(m_pFileNames + fileOffset) + 1;
                    }
                }
            }
        }
        elapsedTmp = fnv_00af7eb0::GetTickCount() - elapsedTmp;
    }
    FileStat077 stat;
    int statResultVal = fnv_00af7eb0::FUN_00ec923c(pFileName, &stat);
    m_kTimeStamp = *(TimeStamp*)&stat.mtime;
    if (!HasStatus(8))
    {
        if (fnv_00af7eb0::DAT_011acdf9)
        {
            unsigned int uiElapsedTime = fnv_00af7eb0::GetTickCount();
            ClearMatchedEntries();
            uiElapsedTime = fnv_00af7eb0::GetTickCount() - uiElapsedTime;
        }
        if (abPrepare)
        {
            for (unsigned int i = 0; i < GetDirectoryCount(); ++i)
            {
                for (unsigned int j = 0; j < GetFileCount(i); ++j)
                    fnv_00af7eb0::ProcessFilesByType(pEntries + i, pEntries[i].m_pFiles + j, m_usFlags);
            }
        }
    }
    SetBufferSize(0x4000);
    ((BSFile*)this)->GetSize();
}

namespace fnv_00af94c0 {
extern int DAT_010a2480;
extern int DAT_010a2484;
struct ArcMemMgr
{
    void MemoryManager_Deallocate(void* p);
    void* Game_DoHeapAlloc(unsigned int uiSize);
};
extern ArcMemMgr DAT_011f6238;
inline void ArcFree(void* p)
{
    DAT_011f6238.MemoryManager_Deallocate(p);
}
inline void* ArcAlloc(unsigned int uiSize)
{
    return DAT_011f6238.Game_DoHeapAlloc(uiSize);
}
struct ArcEntry
{
    unsigned int a;
    unsigned int b;
    unsigned int uiIndex;
    unsigned int c;
};
// 0x00af94c0: Archive.h lacks GetString; use its shared directory-name storage.
struct ArchiveDirectoryStringLookup : public Archive
{
  public:

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiComponentSize = 1;
        unsigned int uiBytesRead;
        unsigned int d;
        uiBytesRead = m_pfnRead(this, pvBuffer, uiBytes, &uiComponentSize, 1);
        m_uiAbsoluteCurrentPos += uiBytesRead;
        d = uiBytesRead;
        return d;
    }
    bool IsLoaded() const
    {
        return (m_ucStatus & 0x10) ? true : false;
    }
    bool HasStrings() const
    {
        return (m_uiArchiveFlags & 1) != 0;
    }
    unsigned int LookupSequenceByKey(unsigned int i) const
    {
        return reinterpret_cast<ArcEntry*>(pEntries)[i].uiIndex;
    }
    char* GetString(unsigned int uiIndex);
};

// Returns the string at uiIndex, either from the loaded data block or by seeking and reading it from the stream.
// @fnv 0x00af94c0
char* ArchiveDirectoryStringLookup::GetString(unsigned int uiIndex)
{
    if (IsLoaded())
    {
        return m_pDirectoryNames + m_puiDirectoryNameOffsets[uiIndex];
    }
    else if (HasStrings())
    {
        unsigned char ucLen;
        unsigned int i;
        char* pcOld2;
        char* pcNew2;
        unsigned int ItemUpdateArray = m_uiDirectoryCount;
        Seek(ItemUpdateArray * 16 + 0x24, DAT_010a2480);
        for (i = 0; i < uiIndex; i++)
        {
            Read(&ucLen, 1);
            Seek(ucLen + LookupSequenceByKey(i) * 16, DAT_010a2484);
        }
        Read(&ucLen, 1);
        if (m_pDirectoryNames)
        {
            pcOld2 = m_pDirectoryNames;
            DAT_011f6238.MemoryManager_Deallocate(pcOld2);
            m_pDirectoryNames = 0;
        }
        pcNew2 = (char*)ArcAlloc(ucLen);
        m_pDirectoryNames = pcNew2;
        Read(m_pDirectoryNames, ucLen);
        return m_pDirectoryNames;
    }
    return 0;
}
}  // namespace fnv_00af94c0

namespace fnv_00afa8e0 {
struct PoolY
{
    void* Game_DoHeapAlloc(unsigned int uiSize);
    void MemoryManager_Deallocate(void* p);
};
extern PoolY DAT_011f6238;
extern bool DAT_011f8154;
extern "C" int __cdecl FUN_00ec7f1e(const char* path, char* drive, unsigned int drvsz, char* dir, unsigned int dirsz,
                                    char* fname, unsigned int fnsz, char* ext, unsigned int extsz);
extern "C" unsigned int __cdecl FUN_00ec6130(const char* s);
extern "C" int __cdecl FUN_00ec65a6(char* dst, unsigned int sz, const char* src);
extern "C" int __cdecl FUN_00ecbc5b(char* s, unsigned int sz);
extern "C" char* __cdecl FUN_00ec68e4(const char* a, const char* b);
inline void* AllocNY(unsigned int n)
{
    return DAT_011f6238.Game_DoHeapAlloc(n + 1);
}
inline void CopyStrY(char* d, unsigned int n, const char* s)
{
    FUN_00ec65a6(d, n, s);
}
inline void LowerY(char* s, unsigned int n)
{
    FUN_00ecbc5b(s, n);
}
// 0x00afa8e0: Archive.h lacks GetPathComponent/GetString and this filename lookup signature.
struct ArchivePathComponent : public Archive
{
    bool Flag1() const
    {
        return (m_uiArchiveFlags & 1) != 0;
    }
    bool Flag2() const
    {
        return (m_uiArchiveFlags & 2) != 0;
    }
    const char* GetString(int a);
    const char* Archive_GetFileString(int a, int b);
    const char* GetPathComponent(int a1, int a2, const char* pPath);
};
// Splits pPath into directory and file, resolves a1/a2 via FUN_00af9bf0, and returns the matching directory or file name after case-insensitive comparison.
// @fnv 0x00afa8e0
const char* ArchivePathComponent::GetPathComponent(int a1, int a2, const char* pPath)
{
    if (DAT_011f8154 && Flag1() && Flag2())
    {
        char szDirX[0x104];
        char szFile7[0x104];
        FUN_00ec7f1e(pPath, 0, 0, szDirX, 0x104, szFile7, 0x104, 0, 0);
        int iA4, iB3;
        if (FindFile_00af9bf0(a1, a2, &iA4, (int)&iB3, 0))
        {
            char* pDirCopyX_lvyahv;
            char* pFileCopyTmp_lun;
            const char* pDirName_mcmb;
            const char* pFileName_zpqwby;
            char* t_elydin;
            char* t_szknnb;
            void* q_pddrt;
            void* q_cyqb;
            void* q_u;
            void* q_ewlv;
            pDirName_mcmb = GetString(iA4);
            pFileName_zpqwby = Archive_GetFileString(iA4, iB3);
            t_elydin = (char*)AllocNY(FUN_00ec6130(pDirName_mcmb));
            pDirCopyX_lvyahv = t_elydin;
            t_szknnb = (char*)AllocNY(FUN_00ec6130(pFileName_zpqwby));
            pFileCopyTmp_lun = t_szknnb;
            CopyStrY(pDirCopyX_lvyahv, FUN_00ec6130(pDirName_mcmb), pDirName_mcmb);
            CopyStrY(pFileCopyTmp_lun, FUN_00ec6130(pFileName_zpqwby), pFileName_zpqwby);
            LowerY(pDirCopyX_lvyahv, FUN_00ec6130(pDirCopyX_lvyahv));
            LowerY(pFileCopyTmp_lun, FUN_00ec6130(pFileCopyTmp_lun));
            LowerY(szDirX, FUN_00ec6130(szDirX));
            LowerY(szFile7, FUN_00ec6130(szFile7));
            if (FUN_00ec68e4(pDirCopyX_lvyahv, szDirX))
            {
                q_pddrt = pDirCopyX_lvyahv;
                DAT_011f6238.MemoryManager_Deallocate(q_pddrt);
                q_cyqb = pFileCopyTmp_lun;
                DAT_011f6238.MemoryManager_Deallocate(q_cyqb);
                return pDirName_mcmb;
            }
            if (FUN_00ec68e4(pFileCopyTmp_lun, szFile7))
            {
                q_u = pDirCopyX_lvyahv;
                DAT_011f6238.MemoryManager_Deallocate(q_u);
                q_ewlv = pFileCopyTmp_lun;
                DAT_011f6238.MemoryManager_Deallocate(q_ewlv);
                return pFileName_zpqwby;
            }
        }
    }
    return 0;
}
}  // namespace fnv_00afa8e0

// Archive flag 0x100 (+0x16c): file names are embedded before each file's data.
inline bool Archive::IsFlag()
{
    return (m_uiArchiveFlags & 0x100) != 0;
}

namespace fnv_00afb300 {
void __cdecl FUN_00ec65a6(char* d, unsigned int n, const char* s);
void __cdecl FUN_00ec44d0(void* d, const void* s, unsigned int n);
extern unsigned int DAT_011f8164;

// 0x00afb300 calls the default BSFile constructor at 0x00aff180, which BSFile.h does not declare.
struct ArchiveFileBufferInit : BSFile
{
    ArchiveFileBufferInit();
    void FUN_00afbfa0(int);
    void FUN_00afb5f0(int, int);
    unsigned int ReadAtOffset(char*, unsigned int, int);
    void DebugCheck()
    {
        const char* pName;
        const char* pBuffer;
    }  // compiled-out debug check (locals only)
    char* Cur()
    {
        char* r = m_pBuffer + m_uiPos + 1;
        return r;
    }
};
struct FUN_00afb300 : ArchiveFileBufferInit
{
    NiPointer<Archive> m_pArchive;
    unsigned int m_uiFileIndex;
    virtual ~FUN_00afb300();
    FUN_00afb300(const char* name, Archive* arch, unsigned int off, unsigned int size, int mode);
};
// Initializes the archive-backed object and buffer, then may read bytes and copy a length-prefixed name from the buffer.
// @fnv 0x00afb300
FUN_00afb300::FUN_00afb300(const char* name, Archive* arch, unsigned int off, unsigned int size, int mode)
    : m_pArchive((Archive*)0)
{
    DebugCheck();
    if (name)
        FUN_00ec65a6(pFileName, 0x104, name);
    m_pBuffer = 0;
    AssignArchivePointer(m_pArchive, arch);
    m_uiFileIndex = off;
    m_uiValueId = size;
    FUN_00afbfa0(0);
    m_uiBufferAllocSize = (size > DAT_011f8164 && mode != -1) ? DAT_011f8164 : size;
    FUN_00afb5f0(0, 0);
    if (mode == -1 || m_pArchive->IsFlag())
    {
        int x = 0;
        m_uiBufferReadSize = ReadAtOffset(m_pBuffer, m_uiBufferAllocSize, x);
        if (m_pArchive->IsFlag())
        {
            unsigned char len = m_pBuffer[m_uiPos];
            FUN_00ec44d0(pFileName, Cur(), len);
            pFileName[len] = 0;
            m_uiPos = len + m_uiPos + 1;
            m_uiBufferSize = len + 1;
        }
    }
}
}  // namespace fnv_00afb300

inline ArchiveEntry* Archive::GetEntry(int index)
{
    return &pEntries[index];
}

namespace fnv_00af7400 {
const char* __cdecl SkipDataPrefix(const char*);
int __cdecl ArchiveManager_GetArchiveTypeFromFileName(const char*);

class FUN_00afd390_class
{
  public:
    int unk00;
    int unk04;
    void* UpdateState_00afd390(const char*, int);
};

// 0x00af7400 calls FindHashEntry (0x00af9c50), absent from Archive.h.
class ArchiveDirectoryLookup : public Archive
{
  public:
    bool FindHashEntry(int, int*, int);
};

struct LNode
{
    NiPointer<Archive> item;
    LNode* next;
};
extern LNode* DAT_011f8160;

class FUN_00aa5140
{
  public:
    FUN_00aa5140();
    const char* FUN_00aa5230(int);
};

__forceinline const char* ResolveNameInline(ArchiveEntry& entry, NiPointer<Archive>& archive, int& index)
{
    int id = entry.m_uiCount;
    static FUN_00aa5140 s_obj;
    const char* name = s_obj.FUN_00aa5230(id);
    return (const char*)((Archive*)(Archive*)archive)->Archive_GetFileString(index, (unsigned int)name);
}

// Resolves a data path to an archive entry name, copying the result into dest and returning success.
// @fnv 0x00af7400
bool __cdecl ResolveArchivePath(const char* path, char* dest, unsigned int flags)
{
    int index = 0;
    path = SkipDataPrefix(path);
    unsigned int len5 = strlen(path);
    if (flags == 0xffff && (signed char)path[len5 - 1] != '\\')
    {
        flags = ArchiveManager_GetArchiveTypeFromFileName(path);
    }
    FUN_00afd390_class key;
    key.UpdateState_00afd390(path, 1);

    ArchiveEntry* spFoundArchive2 = 0;
    NiPointer<Archive> pEntry = 0;

    if (!pEntry)
    {
        LNode* pNode = DAT_011f8160;
        while (pNode)
        {
            NiPointer<Archive> spArchiveB = pNode->item;
            if (spArchiveB && (unsigned short)(((Archive*)spArchiveB)->GetFlags() & flags) &&
                ((ArchiveDirectoryLookup*)(Archive*)spArchiveB)->FindHashEntry((int)&key, &index, 0))
            {
                pEntry = spArchiveB;
                spFoundArchive2 = ((Archive*)pEntry)->GetEntry(index);
                break;
            }
            pNode = pNode->next;
        }
    }

    if (pEntry && spFoundArchive2 && spFoundArchive2->GetNameID())
    {
        bool bLocked3 = true;
        if (((Archive*)pEntry)->HasNameTable())
        {
            bLocked3 = false;
        }
        if (bLocked3)
        {
            ((Archive*)pEntry)->Lock();
        }

        const char* resolvedName4 = ResolveNameInline(*spFoundArchive2, pEntry, index);

        strcpy_s(dest, 260, path);
        char* pSlash_ = strrchr(dest, '\\');
        if (pSlash_)
        {
            strcpy_s(pSlash_ + 1, 260 - (pSlash_ - dest) - 1, resolvedName4);
        }
        else
        {
            return false;
        }

        if (bLocked3)
        {
            ((Archive*)pEntry)->Unlock();
        }
        return true;
    }
    return false;
}
}  // namespace fnv_00af7400

void* __cdecl FUN_00ec7230(void* dst, const void* src, unsigned int size);

struct S_00afea20_Arr
{
    int unk00;
    unsigned int* m_pBuffer;
    unsigned int m_uiSize;

    void FUN_0042fb60(unsigned int* pDst, unsigned int* pSrc, unsigned int ItemUpdateArray)
    {
        if (ItemUpdateArray <= 0)
            return;
        if (pDst < pSrc)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(unsigned int));
        }
        else if (pDst > pSrc)
        {
            for (int i = ItemUpdateArray - 1; i >= 0; i--)
                FUN_00ec7230(&pDst[i], &pSrc[i], sizeof(unsigned int));
        }
    }

    void RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray);
};

// @fnv 0x00afea20
void S_00afea20_Arr::RemoveRange(unsigned int uiIndex, unsigned int ItemUpdateArray)
{
    unsigned int uiMove;
    unsigned int uiTail = m_uiSize - uiIndex - ItemUpdateArray;
    uiMove = uiTail < ItemUpdateArray ? uiTail : ItemUpdateArray;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
    }
    FUN_0042fb60(m_pBuffer + uiIndex, m_pBuffer + m_uiSize - uiMove, uiMove);
    m_uiSize -= ItemUpdateArray;
}

extern MemoryManager g_memoryManager;
struct FUN_00afcdc0
{
    ~FUN_00afcdc0();
};
struct FUN_00afcd90 : FUN_00afcdc0
{
    virtual ~FUN_00afcd90();
    static void operator delete(void* p)
    {
        g_memoryManager._DeallocateAlias(p);
    }
};
// Empty virtual destructor for FUN_00afcd90, allowing polymorphic deletion through its base class.
// @fnv 0x00afcd90
FUN_00afcd90::~FUN_00afcd90()
{}

struct ArchiveStreamBase : public BSFile
{
    ArchiveStreamBase();
    virtual void* FUN_00afce80(unsigned int flags);
};
struct StreamSecondary
{
    virtual void* FUN_00afce80(unsigned int flags);
};
struct ArchiveStreamFile : public ArchiveStreamBase, public StreamSecondary
{
    ArchiveStreamFile();
// @fnv 0x00afce80
    virtual void* FUN_00afce80(unsigned int flags);
};
ArchiveStreamFile::ArchiveStreamFile()
{}

unsigned char __fastcall BSHash_ExtensionIndex(void*);

struct FUN_00afcf00_t
{
    char pad_0[2];
    unsigned char field_2;
    unsigned char field_3;
    unsigned int field_4;

    int BSHash_WildCardCompare(FUN_00afcf00_t* other);
};

// Compares two FUN_00afcf00_t objects by field_4, field_2, and FUN_00afcfe0 result, returning -1, 0, or 1.
// @fnv 0x00afcf00
// src: COMMUNITY 0x00afcf00
int FUN_00afcf00_t::BSHash_WildCardCompare(FUN_00afcf00_t* other)
{
    if ((unsigned char)(field_3 & 0x7f) == 0x2a)
    {
        if (BSHash_ExtensionIndex(this) == BSHash_ExtensionIndex(other))
        {
            return 0;
        }
        return 1;
    }

    unsigned int a;
    unsigned int b;
    a = field_4;
    b = other->field_4;
    if (a < b)
    {
        return -1;
    }
    else
    {
        unsigned int a;
        unsigned int b;
        a = field_4;
        b = other->field_4;
        if (a > b)
        {
            return 1;
        }
    }

    {
        unsigned char c2;
        unsigned char c1;
        c1 = field_2;
        c2 = other->field_2;
        if (c1 != c2)
        {
            return 1;
        }
    }

    if (BSHash_ExtensionIndex(this) != BSHash_ExtensionIndex(other))
    {
        return 1;
    }

    return 0;
}

namespace fnv_00af7800 {
struct RecursiveMutex
{
    unsigned debug, lockCount, recursionCount, owner, semaphore, spin;
};

__declspec(dllimport) void __stdcall EnterCriticalSection(void*);

__declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" char* __cdecl strrchr(const char*, int);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
int __cdecl ArchiveManager_GetArchiveTypeFromFileName(const char*);
struct LNode;
extern LNode* DAT_011f8160;

struct ArchiveDirectoryKey
{
    unsigned low, high;
    ArchiveDirectoryKey(const char*, int);
};

struct ArchiveFileMeta
{
    unsigned hashLow, hashHigh;
    unsigned offset, size;
    unsigned Offset()
    {
        return offset & 0x3fffffff;
    }
};

struct ArchiveDirectory
{
    unsigned hashLow, hashHigh, count;
    ArchiveFileMeta* files;
    unsigned Count()
    {
        return count;
    }
    ArchiveFileMeta* File(unsigned i)
    {
        return files + i;
    }
};

struct ArchiveRefBlock
{
    virtual void Unknown();
    virtual void DeleteThis();
    volatile long count;
    void Acquire()
    {
        InterlockedIncrement(&count);
    }
    void Release()
    {
        if (!InterlockedDecrement(&count))
            DeleteThis();
    }
};

// 0x00af7800: Archive.h lacks the directory-key FindHashEntry overload and this filename lookup signature.
struct ArchivePathLookup : public Archive
{

    ArchiveRefBlock* Ref()
    {
        return reinterpret_cast<ArchiveRefBlock*>(reinterpret_cast<char*>(this) + sizeof(BSFile));
    }

    unsigned Types()
    {
        return m_usFlags;
    }

    bool FindHashEntry(ArchiveDirectoryKey*, unsigned*, bool);

    ArchiveDirectory* Directory(unsigned i)
    {
        return reinterpret_cast<ArchiveDirectory*>(pEntries) + i;
    }

    bool IsConcurrent()
    {
        return (m_ucStatus & 32) ? true : false;
    }

    RecursiveMutex* Lock()
    {
        return reinterpret_cast<RecursiveMutex*>(&m_kLock.m_kCriticalSection);
    }

    const char* Archive_GetFileString(unsigned, unsigned);
};

struct PathArchiveNode
{
    NiPointer<ArchivePathLookup> value;
    PathArchiveNode* next;
};

const char* SkipDataPrefix(const char*);

// Finds the archive entry matching path and mask, picks the lowest-offset file, and writes its resolved name into output.
// @fnv 0x00af7800
// src: COMMUNITY 0x00af7800
bool ArchiveManager_GetFileNameForSmallestFileInDirectory(const char* path, char* output, unsigned mask)
{

    unsigned directoryIndex = 0;

    path = SkipDataPrefix(path);

    unsigned length2 = strlen(path);

    if (mask == 65535 && path[length2 - 1] != '\\')
        mask = ArchiveManager_GetArchiveTypeFromFileName(path);

    ArchiveDirectoryKey key(path, 1);

    ArchiveDirectory* directory4 = 0;

    NiPointer<ArchivePathLookup> archiveTmp(0);

    PathArchiveNode* node9;

    if (!archiveTmp)
    {

        for (node9 = (PathArchiveNode*)DAT_011f8160; node9;)
        {

            NiPointer<ArchivePathLookup> entry3(node9->value);

            if (entry3 && (unsigned short)(entry3->Types() & mask) &&
                entry3->FindHashEntry(&key, &directoryIndex, false))
            {

                archiveTmp = entry3;

                directory4 = archiveTmp->Directory(directoryIndex);

                break;
            }

            node9 = node9->next;
        }
    }

    if (archiveTmp && directory4 && directory4->Count())
    {

        bool kLocked = true;

        if (archiveTmp->IsConcurrent())
            kLocked = false;

        if (kLocked)
            EnterCriticalSection(archiveTmp->Lock());

        unsigned aBestA = 0;

        unsigned minimum3 = ~0u;

        for (unsigned _i2 = 0; _i2 < directory4->Count(); ++_i2)
        {

            unsigned value7 = directory4->File(_i2)->Offset();

            if (value7 < minimum3)
            {
                minimum3 = value7;
                aBestA = _i2;
            }
        }

        const char* replacementVal = archiveTmp->Archive_GetFileString(directoryIndex, aBestA);

        strcpy_s(output, 260, path);

        char* slash3 = strrchr(output, '\\');

        if (slash3)
            strcpy_s(slash3 + 1, 260 - (slash3 - output) - 1, replacementVal);

        else
            return false;

        if (kLocked)
            LeaveCriticalSection(archiveTmp->Lock());

        return true;
    }

    return false;
}
}  // namespace fnv_00af7800

__if_not_exists(MemMgrStand)
{
    struct MemMgrStand
    {
        void* Allocate(unsigned int auiSize);
        void Deallocate(void* apMem);
    };
}
extern MemMgrStand g_arcMemMgr;
struct ArchiveArray;
inline void* operator new(unsigned int, void* memory)
{
    return memory;
}
extern const char DAT_010a445c[];
BSFile* __cdecl FileFinder_GetFile_(const char*, int, unsigned int);
struct FUN_00afd390
{
    unsigned int low;
    unsigned int high;
    FUN_00afd390(const char*, int);
    inline void* operator new(unsigned int size)
    {
        return g_arcMemMgr.Allocate(size);
    }
    inline void operator delete(void* memory)
    {
        g_arcMemMgr.Deallocate(memory);
    }
};
struct FUN_00afcce0
{
    virtual ~FUN_00afcce0();
    virtual FUN_00afd390** Allocate(unsigned int);
    FUN_00afd390** entries;
    unsigned int count;
    unsigned int capacity;
    FUN_00afcce0();
    inline void* operator new(unsigned int size)
    {
        return g_arcMemMgr.Allocate(size);
    }
    inline void operator delete(void* memory)
    {
        g_arcMemMgr.Deallocate(memory);
    }
    void InitArray(unsigned int allocated, unsigned int size)
    {
        entries = 0;
        count = 0;
        capacity = 0;
        if (size > allocated)
            allocated = size;
        if (allocated > 0)
        {
            entries = Allocate(allocated);
            capacity = allocated;
        }
        if (size > 0)
        {
            for (unsigned int i = 0; i < size; ++i)
                new (&entries[i]) FUN_00afd390*;
            count = size;
        }
    }
    void UpdateFields_00a0d0c0(unsigned int, unsigned int);
// src: COMMUNITY 0x00a11ee0
    unsigned int BSSimpleArray_AddUninitialized_0()
    {
        if (count == capacity)
        {
            if (capacity == 0)
            {
                unsigned int initialCapacity = 4;
                entries = Allocate(initialCapacity);
                capacity = initialCapacity;
            }
            else
            {
                unsigned int newCapacity = capacity > 1024 ? capacity + 1024 : capacity * 2;
                UpdateFields_00a0d0c0(newCapacity, count);
                capacity = newCapacity;
            }
        }
        ++count;
        return count - 1;
    }
// src: COMMUNITY 0x00a11d20
    unsigned int BSSimpleArray_Add(FUN_00afd390* const& value)
    {
        unsigned int index = BSSimpleArray_AddUninitialized_0();
        for (unsigned int i = 0; i < 1; ++i)
            new (&entries[index + i]) FUN_00afd390*;
        entries[index] = value;
        return index;
    }
};
extern ArchiveArray* DAT_011f816c;
extern ArchiveArray* DAT_011f8168;
inline unsigned int BSFile::Read(void* buffer, unsigned int bytes)
{
    unsigned int componentSize = 1;
    unsigned int bytesRead = BinaryRead(buffer, bytes, &componentSize, 1);
    return bytesRead;
}
inline unsigned int BSFile::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int result = m_pfnRead(this, buffer, bytes, sizes, count);
    m_uiAbsoluteCurrentPos += result;
    return result;
}
// Opens an archive list file, reads each line, and adds entries to DAT_011f816c or DAT_011f8168 based on a substring check.
// @fnv 0x00af5ab0
// src: COMMUNITY 0x00af5ab0
void __cdecl ArchiveManager_LoadInvalidationFile(const char* path)
{
    BSFile* file;
    if (path)
    {
        file = (BSFile*)FileFinder_GetFile_(path, 0, 0x4000);
        if (!file || !file->Open(false, false))
        {
            delete file;
            return;
        }
        char lineBuffer[260];
        char separator;
        char* entryPath;
        while (file->GetLine(lineBuffer, 260, 13))
        {
            file->Read(&separator, 1);
            if (strstr(lineBuffer, DAT_010a445c))
            {
                if (!DAT_011f816c)
                    DAT_011f816c = reinterpret_cast<ArchiveArray*>(new FUN_00afcce0);
                entryPath = lineBuffer;
                if (lineBuffer[0] == '\\')
                    entryPath++;
                reinterpret_cast<FUN_00afcce0*>(DAT_011f816c)->BSSimpleArray_Add(new FUN_00afd390(entryPath, 1));
            }
            else
            {
                if (!DAT_011f8168)
                    DAT_011f8168 = reinterpret_cast<ArchiveArray*>(new FUN_00afcce0);
                reinterpret_cast<FUN_00afcce0*>(DAT_011f8168)->BSSimpleArray_Add(new FUN_00afd390(lineBuffer, 0));
            }
        }
        delete file;
    }
}

struct ArcInflateReadState
{
    unsigned char* m_pNextInputByte;
    unsigned int m_uiAvailableInputBytes;
    unsigned int m_ulTotalInputBytes;
    unsigned char* m_pNextOutputByte;
    unsigned int m_uiAvailableOutputBytes;
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
int __cdecl FUN_00b44000(ArcInflateReadState* state, int flush);
int __cdecl FUN_00b45db0(ArcInflateReadState* state);
struct DecompReadFile : public CompressedArchiveFile
{
    void FUN_00aa15a0();
    unsigned int ReadAtOffset(void* buffer, unsigned int size, int mode);
    unsigned int CompressedArchiveFile_ReadF(char* buffer, unsigned int size);
};
// Reads up to size bytes of decompressed data into buffer, refilling the compressed input buffer as needed, and returns the number of bytes read.
// @fnv 0x00afc0e0
// src: XBOX_PDB 0x00afc0e0
unsigned int DecompReadFile::CompressedArchiveFile_ReadF(char* buffer, unsigned int size)
{
    unsigned int bytesToRead = size;
    unsigned int nRead = 0;
    ArcInflateReadState* state = (ArcInflateReadState*)m_pArchiveStream;
    unsigned int available = m_uiUncompressedPosition - m_uiCompressedPosition;

    if (bytesToRead > available)
    {
        if (available > 0)
        {
            if (buffer != 0)
            {
                char* copyFrom = m_pCompressedBuffer + m_uiCompressedPosition;
                memcpy(buffer, copyFrom, available);
                buffer += available;
            }
            bytesToRead -= available;
            nRead = available;
        }
        m_uiCompressedPosition = 0;
        m_uiUncompressedPosition = 0;

        int status;
        while (bytesToRead > 0)
        {
            state->m_uiAvailableOutputBytes = m_uiUncompressedSize;
            state->m_pNextOutputByte = (unsigned char*)m_pCompressedBuffer;

            while (state->m_uiAvailableOutputBytes != 0)
            {
                available = (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x14)) - (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18));
                state->m_uiAvailableInputBytes = available;
                state->m_pNextInputByte = (unsigned char*)((*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x20)) + (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18)));

                if (available != 0)
                {
                    status = FUN_00b44000(state, 2);
                    if (status == -2 || status == 2 || status == -3 || status == -4)
                    {
                        FUN_00b45db0(state);
                        bytesToRead = 0;
                        break;
                    }
                    if (status == 1)
                        break;
                }
                (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18)) += available - state->m_uiAvailableInputBytes;
                m_uiBufferSize += available - state->m_uiAvailableInputBytes;
                if (state->m_uiAvailableInputBytes == 0)
                {
                    FUN_00aa15a0();
                    (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x14)) = ReadAtOffset((*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 0x20)), (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x10)), 0);
                }
            }

            m_uiUncompressedPosition = m_uiUncompressedSize - state->m_uiAvailableOutputBytes;
            if (m_uiUncompressedPosition == 0)
            {
                break;
            }
            else
            {
                if (bytesToRead > m_uiUncompressedPosition)
                {
                    bytesToRead -= m_uiUncompressedPosition;
                    nRead += m_uiUncompressedPosition;
                    if (buffer != 0)
                    {
                        unsigned int amount = m_uiUncompressedPosition;
                        char* copyFrom = m_pCompressedBuffer;
                        memcpy(buffer, copyFrom, amount);
                        buffer += m_uiUncompressedPosition;
                    }
                }
                else
                {
                    if (buffer != 0)
                    {
                        char* copyFrom = m_pCompressedBuffer;
                        memcpy(buffer, copyFrom, bytesToRead);
                    }
                    m_uiCompressedPosition += bytesToRead;
                    nRead += bytesToRead;
                    bytesToRead = 0;
                }
            }
        }
    }
    else
    {
        if (buffer != 0)
        {
            char* copyFrom = m_pCompressedBuffer + m_uiCompressedPosition;
            memcpy(buffer, copyFrom, bytesToRead);
        }
        m_uiCompressedPosition += bytesToRead;
        nRead += bytesToRead;
    }
    return nRead;
}

namespace archive_master_lookup {

extern NiPointer<Archive> DAT_011f8190[9];
extern NiPointer<Archive> DAT_011f81b4[9];
inline Archive* SelectMaster(int index)
{
    return static_cast<Archive*>(DAT_011f8190[index] ? DAT_011f8190[index] : DAT_011f81b4[index]);
}
// Selects an archive using kind and calls its FUN_00afa6e0 method with directory, file, and name.
// @fnv 0x00af6430
// src: COMMUNITY 0x00af6430
int __cdecl ArchiveManager_GetFileEntryForFile_0(int aiMasterIndex, int directory, int file, int name)
{
    int result = 0;
    NiPointer<Archive> archive(SelectMaster(aiMasterIndex));
    if (archive)
        result = archive->GetFileEntryForFile(directory, file, name);
    return result;
}
}
