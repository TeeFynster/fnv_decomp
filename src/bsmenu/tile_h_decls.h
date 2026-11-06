// bsmenu/tile_h_decls.h: declares NiFixedString, Tile, Tile__MenuStringMap, Tile__TileTemplate, Tile__BuildStorage and more
#ifndef FNV_TILE_H_DECLS_H
#define FNV_TILE_H_DECLS_H

#include "MemoryManager.h"
#include "../../include/NiExtraData.h"
#include "../../include/Tile.h"

extern float DAT_01094c4c;
extern const char DAT_01093f80[];
extern "C" int __cdecl _stricmp(const char*, const char*);
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
extern "C" int __cdecl tolower(int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern NiFixedString EmptyFS;
extern MemoryManager g_memoryManager;
extern "C" void __cdecl TileTemplateDisposeAlias();
extern "C" void __cdecl DeallocateAlias(void*);


class Tile__MenuStringMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int uiHashTableSize;
    bool IsKeysEqual(const char* left, const char* right);
    unsigned int KeyToHashIndex(const char* key);
};

class NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___
{
  public:
    unsigned int m_data[3];
    void RemoveAll();
};

class Tile__TileTemplate
{
  public:
    NiFixedString StringProvider;
    void* pParent;
    NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___ xList;
    void Clear();
    ~Tile__TileTemplate();
};

class Tile__BuildStorage
{
  public:
    Tile__TileTemplate* pTemplate;
    void SetTileTemplate(Tile__TileTemplate* newTemplate);
};

extern void FUN_00f1d2eb();
extern void FUN_00f1e4f0();
extern "C" unsigned int __security_cookie;
extern void* DAT_01094cfc;
extern const char DAT_010954cc[];
class NiNode;
class Tile__Extra : public NiExtraData
{
  public:
    Tile* pTile;
    NiNode* pNode;
    Tile__Extra(Tile*, NiNode*);
};
#endif
