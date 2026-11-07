// bsmain/queuedfiles.cpp: QueuedFile, ObjectC3 (10 functions)

#include "../../include/MemoryManager.h"
#include "../../include/QueuedFileEntry.h"
#include "../../include/QueuedChildren.h"

// @fnv 0x0043bde0
void QueuedFile::HandleChildCompletion(QueuedFile* apChild)
{
    pChildren->AddFinishedChild();
    OnChildCompletion();
}

// Stores apParent as this object's parent and, if non-null, registers this object as a child of that parent.
// @fnv 0x00443aa0
void QueuedFile::SetParent(QueuedFile* apParent)
{
    m_pParent = apParent;
    if (m_pParent)
        ((QueuedFile*)m_pParent)->AddChild(this);
}

extern MemoryManager g_memoryManager;
unsigned int __cdecl _strlen(const char*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
// Copies apName into a newly allocated buffer stored in pFileName, using strlen(apName)+1 bytes.
// @fnv 0x00c3cee0
// src: XBOX_PDB 0x00c3cee0
void QueuedFileEntry::SetFileName_00c3cee0(const char* apName)
{
    unsigned int uiLen;
    if (apName)
    {
        char* p;
        char* dst;
        uiLen = _strlen(apName) + 1;
        p = (char*)g_memoryManager.Allocate(uiLen);
        pFileName = p;
        dst = pFileName;
        _strcpy_s(dst, uiLen, apName);
    }
}

namespace fnv_00c3cf60 {
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
struct ArchiveManager
{
    static BSFileEntry* __cdecl FindFileEntry(int, FileNameHash&, FileNameHash&, const char*);
};
}  // namespace fnv_00c3cf60

// Builds the lookup file name for aeArchive, hashes it into directory and file hashes, queries ArchiveManager and stores the resulting BSFileEntry.
// @fnv 0x00c3cf60
void QueuedFileEntry::LookupFileEntryByArchive(int aeArchive)
{
    using namespace fnv_00c3cf60;
    if (pFileName)
    {
        char acName[0x104];
        FileNameHash dirHash;
        FileNameHash fileHash;
        BSFileEntry* pEntry;
        GetLookupFileName(aeArchive, acName);
        FileNameHash::CreateDirectoryAndFileHashes(acName, &dirHash, &fileHash);
        pEntry = ArchiveManager::FindFileEntry(aeArchive, dirHash, fileHash, acName);
        SetFileEntry(pEntry);
    }
}
// @fnv 0x00c3ce60
QueuedFileEntry::QueuedFileEntry(int aePriority) : QueuedFile(aePriority)
{
    pFileName = 0;
    m_pFileEntry = 0;
}

struct FUN_00905ba0 : QueuedFileEntry
{
    int f30;
    int f34;
    int f38;
    FUN_00905ba0(int a, int b, const char* name);
};
// @fnv 0x00905ba0
FUN_00905ba0::FUN_00905ba0(int a, int b, const char* name) : QueuedFileEntry(0)
{
    f30 = b;
    f34 = 0;
    f38 = a;
    SetFileName_00c3cee0(name);
    LookupFileEntryByArchive(4);
}

static __forceinline void DeallocateFileName(void* pointer) throw()
{
    g_memoryManager.Deallocate(pointer);
}

// Frees the file name buffer through the memory manager.
// @fnv 0x00c3cea0
QueuedFileEntry::~QueuedFileEntry()
{
    char* name = pFileName;
    DeallocateFileName(name);
}
#include <windows.h>
struct PoolHolder
{
    void* Allocate(unsigned int sz);
};
extern PoolHolder DAT_011f6238;

struct RefRelease
{
    void BSTask_int64_DecRefCount();
};

struct QueuedFileRef
{
    QueuedFile* m_pObject;

    QueuedFileRef(QueuedFile* p)
    {
        m_pObject = p;
        if (m_pObject != 0)
        {
            QueuedFile* t = m_pObject;
            InterlockedIncrement((LONG*)((char*)t + 8));
        }
    }

    ~QueuedFileRef()
    {
        if (m_pObject != 0)
        {
            reinterpret_cast<RefRelease*>(m_pObject)->BSTask_int64_DecRefCount();
        }
    }
};

struct ChildrenOps
{
    void* m_ppVirtualMethodTable;
    QueuedFileRef* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int unk10;

    unsigned int QueuedChildren_GetAppendIndex();

// src: COMMUNITY 0x00c3d4f0
    void QueuedChildren_Append(const QueuedFileRef& pRef)
    {
        unsigned int iIndex;
        unsigned int iCount;
        unsigned int iReserved;
        unsigned int iGrow;
        unsigned int iNewReserved;
        unsigned int iBytes;
        unsigned int iOldCount;
        unsigned int i;
        QueuedFileRef* pOldBuffer;
        QueuedFileRef* pNewBuffer;
        QueuedFileRef* pBase;
        QueuedFileRef* pSlot;
        QueuedFile* pTmp;
        void* pRaw;

        iIndex = QueuedChildren_GetAppendIndex();
        iCount = iSize;
        iOldCount = iCount;
        iReserved = SimpleArrayStorage;
        iGrow = 1024;
        iNewReserved = iReserved;
        pNewBuffer = 0;
        pOldBuffer = pBuffer;
        pRaw = 0;
        pBase = pOldBuffer + iIndex;
        for (i = 0; i < 1; i++)
        {
            pSlot = pBase + i;
            if (pSlot != 0)
            {
                pSlot->m_pObject = 0;
                pTmp = pSlot->m_pObject;
                if (pTmp != 0)
                {
                    InterlockedIncrement((LONG*)((char*)pTmp + 8));
                }
            }
        }
        if (iCount >= iReserved)
        {
            iNewReserved = iReserved + iGrow;
            iBytes = iNewReserved * 4;
            pNewBuffer = (QueuedFileRef*)pRaw;
        }
        iSize = iIndex + 1;
    }
};

struct FUN_00c3c4e0
{
    void* m_ppVirtualMethodTable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;

    FUN_00c3c4e0();
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.Allocate(size);
    }
};

struct FUN_00c3c700_cls : public QueuedFile
{
    void QueuedFile_AddChild(QueuedFile* apChild);
};

// @fnv 0x00c3c700
// src: COMMUNITY 0x00c3c700
void FUN_00c3c700_cls::QueuedFile_AddChild(QueuedFile* apChild)
{
    if (pChildren == 0)
    {
        pChildren = reinterpret_cast<QueuedChildren*>(new FUN_00c3c4e0);
    }
    reinterpret_cast<ChildrenOps*>(pChildren)->QueuedChildren_Append(apChild);
}

static __forceinline void DeadQ1()
{
    int dq[1];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ4()
{
    int dq[4];
}
static __forceinline void DeadQ5()
{
    int dq[5];
}
static __forceinline void DeadQ6()
{
    int dq[6];
}
static __forceinline void DeadQ7()
{
    int dq[7];
}
static __forceinline void DeadQ8()
{
    int dq[8];
}
static __forceinline void DeadQ9()
{
    int dq[9];
}
static __forceinline void DeadQ10()
{
    int dq[10];
}
static __forceinline void DeadQ11()
{
    int dq[11];
}

struct ObjectC3;
struct PointerC3
{
    ObjectC3* value;
    operator ObjectC3*() const
    {
        return value;
    }
    ObjectC3* operator->() const
    {
        return value;
    }
    PointerC3& operator=(ObjectC3*);
};
struct ArrayC3
{
    virtual ~ArrayC3();
    PointerC3* data;
    unsigned int size;
    unsigned int reserved;
    volatile unsigned int finished;
    unsigned int GetSize()
    {
        return size;
    }
    unsigned int GetFinished()
    {
        return finished;
    }
    PointerC3& GetAt(unsigned int i)
    {
        return data[i];
    }
};
struct ObjectC3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void notify(ObjectC3*);
    int unk4;
    long refs;
    int state;
    int unk10, unk14, unk18;
    PointerC3 parent;
    ArrayC3* children;
    ArrayC3* parents;
    bool IsFinished()
    {
        return state >= 4;
    }
    bool AllFinished()
    {
        return children ? children->GetSize() == children->finished : true;
    }
    void BSTask_int64_DecRefCount();
    void AcquireReference()
    {
        InterlockedIncrement(&refs);
    }
    void NotifyParents();
};
inline PointerC3& PointerC3::operator=(ObjectC3* rhs)
{
    if (value != rhs)
    {
        if (value)
            value->BSTask_int64_DecRefCount();
        value = rhs;
        if (value)
            value->AcquireReference();
    }
    return *this;
}
// When a parent pointer exists and this object and its children are finished, notifies the parent pointers, deletes the parents array, then calls FUN_0044dd60().
// @fnv 0x00c3c930
void ObjectC3::NotifyParents()
{
    if ((parent || parents) && IsFinished() && AllFinished())
    {
        AcquireReference();
        if (parent)
        {
            parent->notify(this);
            DeadQ3();
            parent = 0;
        }
        if (parents)
        {
            for (unsigned int i = 0; i < parents->GetSize(); i++)
            {
                ObjectC3* obj = parents->GetAt(i);
                obj->notify(this);
                DeadQ3();
            }
            delete parents;
            parents = 0;
        }
        BSTask_int64_DecRefCount();
    }
}

extern long DAT_01202d9c;

struct FUN_00c3d440_src
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_flags0c;
};

struct IdParts
{
    unsigned char unk0;
    unsigned char b;
    unsigned short word;
};

struct FUN_00c3d440_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual unsigned char GetFlagByte();

    int unk04x;
    __int64 m_uiFilterValue;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    FUN_00c3d440_src* m_pSrc;

    void FUN_0043db70();
    void QueuedFileEntry_GenerateKey();
};

// @fnv 0x00c3d440
// src: XBOX_PDB 0x00c3d440
void FUN_00c3d440_cls::QueuedFileEntry_GenerateKey()
{
    if (m_pSrc != 0)
    {
        IdParts id;
        id.word = (unsigned short)InterlockedIncrement(&DAT_01202d9c);
        id.b = (unsigned char)(m_uiFilterValue >> 0x10);
        unsigned int flags = m_pSrc->m_flags0c & 0x7fffffffu;
        signed char sb = (signed char)GetFlagByte();
        unsigned int tmp;
        unsigned int tmp2;
        m_uiFilterValue = ((__int64)sb << 0x38) | ((__int64)flags << 0x18) | ((__int64)id.b << 0x10) | (__int64)id.word;
    }
    else
    {
        FUN_0043db70();
    }
}
