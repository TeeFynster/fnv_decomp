// gamebryo2.2/corelibs/nimain/bstexturepalette_decls.h: declares FileNameHash, ArchiveManager, TextureFileEntrySetter and more
#ifndef FNV_BSTEXTUREPALETTE_DECLS_H
#define FNV_BSTEXTUREPALETTE_DECLS_H

#include "layout_support.h"
#include "../../../../include/ARCHIVE_TYPE_INDEX.h"

#include "../../../../include/NiTexture.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/RecursiveSpinLock.h"

class BSFileEntry;

class FileNameHash
{
  public:
    unsigned char cLast, cSecondToLast, cLength, cFirst;
    unsigned int uiCRC;
    static void __cdecl CreateDirectoryAndFileHashes(const char*, FileNameHash&, FileNameHash&);
};
FNV_STATIC_ASSERT(sizeof(FileNameHash) == 8);

// Archive type one is the texture archive group.
class ArchiveManager
{
  public:
    static BSFileEntry* __cdecl FindFileEntry(ARCHIVE_TYPE_INDEX, FileNameHash&, FileNameHash&, const char*);
};

class TextureFileEntrySetter
{
  public:
    static BSFileEntry* __cdecl FindEntryForTexture(const NiTexture*);
    static void __cdecl SetTexture(NiTexture*, const BSFileEntry*);
};
bool __cdecl CleanPath(const char*, char*, unsigned int);

// Shared BSTexMapItem.h is not available yet; retain one definition for the 0x10-byte cache node.
class BSTexMapItem
{
  public:
    NiTexture* spTexture;
    BSFileEntry* m_pFileEntry;
    BSTexMapItem* pNext;
    unsigned short m_usTextureSizeLevel;
    short m_sTextureCacheValue;

    void* operator new(size_t size);

    BSTexMapItem(NiTexture* tex, BSTexMapItem* next)
    {
        spTexture = tex;
        InterlockedIncrement((volatile long*)&tex->m_uiRefCount);
        m_pFileEntry = 0;
        pNext = next;
        m_usTextureSizeLevel = 0;
        m_sTextureCacheValue = 0;
    }
};

FNV_STATIC_ASSERT(sizeof(BSTexMapItem) == 16);
class TextureCacheMap
{
  public:
    BSTexMapItem* pElement[713];
    unsigned int iCount;
    BSTexMapItem* FindOrInsertTexture(NiTexture*);
};
FNV_STATIC_ASSERT(sizeof(TextureCacheMap) == 0xb28);
class BSFileEntryMap
{
  public:
    void SetAt(const BSFileEntry*, BSTexMapItem*);
};
extern RecursiveSpinLock g_spinLock;
extern TextureCacheMap* DAT_011f4464;
extern BSFileEntryMap* DAT_011f4468;
unsigned int __cdecl GetTextureSizeLevel(NiTexture*);
#endif
