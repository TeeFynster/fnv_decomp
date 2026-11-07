#define FNV64_BSSIMPLELIST_CUSTOM_DELETE
#include "../../include/BSSimpleList.h"
#include "../../include/NiTListItem.h"
// bsmenu/menu.cpp: Menu (27 functions)

#include <string.h>
#include "../../include/BSStringT.h"
#include "../../include/IMemoryHeap.h"
#include "../../include/NiPoint3.h"
#include "../../include/MemoryManager.h"
extern MemoryManager g_memoryManager;
template <class T> inline BSSimpleList<T>::BSSimpleList() : m_item(0), m_pkNext(0) {}
template <class T> inline BSSimpleList<T>::~BSSimpleList() { RemoveAll(); }
template <class T> inline void BSSimpleList<T>::RemoveAll()
{
    while (m_pkNext)
    {
        BSSimpleList<T>* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        delete m_pkNext;
        m_pkNext = next;
    }
    m_item = 0;
}
template <class T> inline void BSSimpleList<T>::operator delete(void* p) { ::g_memoryManager.Deallocate(p); }
// This unit supplies the inline behavior of the container support types.
#include "../../include/BSSimpleList.h"

#include "../../include/BSFile.h"
#include "../../include/MemoryPool.h"
#include "../../include/Menu.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiFixedString.h"
#include "../../include/OSGlobals.h"
#include "../../include/Tile.h"
// TileChildList_menu: local type (was include/TileChildList.h, which had no evidence of one real class); its methods are 0x00559450 NiPointer<PathingSolution>::operator->, 0x0057cbe0 NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::GetNext, 0x00683520 NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::GetPrev
class Tile;
class TileChildNode;
class InterfaceLocalTile;

class TileChildList_menu
{
public:
    TileChildNode* m_pkHead;
    TileChildNode* m_pkTail;
    unsigned int m_uiCount;

    void* GetHeadPos();
    TileChildNode* GetHeadPos() const { return m_pkHead; }
    Tile*& GetNext(void*& rkPos);
    Tile*& GetNext(void*& kPos) const;
    Tile*& GetNext(TileChildNode*& kPos) const;
    InterfaceLocalTile*& GetPrev(void*& pos);
};
#include "../../include/TileMenu.h"

// Stream callback and status fields are opaque in the shared stream headers.
inline bool BSFile::Good() const { return *((const bool*)this + 0x2c); }
inline bool BSFile::IsGood() { return *((bool*)this + 0x2c); }
inline unsigned int BSFile::BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int result = (*(NiBinaryStream::ReadFunction*)((char*)this + 8))(this, buffer, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += result;
    return result;
}
inline unsigned int ReadFileData(BSFile* file, void* buffer, unsigned int bytes)
{
    unsigned int size = 1;
    unsigned int result = file->BinaryRead(buffer, bytes, &size, 1);
    return result;
}
inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int result = (*(WriteFunction*)((char*)this + 12))(this, buffer, bytes, sizes, count);
    *(unsigned int*)((char*)this + 4) += result;
    return result;
}
inline unsigned int NiBinaryStream::Write(const void* buffer, unsigned int bytes)
{
    unsigned int size = 1;
    unsigned int result = BinaryWrite(buffer, bytes, &size, 1);
    return result;
}
inline void* BSFile::operator new(size_t size) { return g_memoryManager.Allocate(size); }

void ClearInterfaceState(Tile*);
class InputManager
{
  public:
    int Controls_GetUserAction(int, int);
    void SetFlag(unsigned short flag)
    {
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x1b92) |= flag;
    }
};

// Operations whose declarations are not yet part of the shared Menu interface.
class MenuOperations : public Menu
{
public:
    void FinishShow();
    void FinishHide();
    void AddTileTemplate(Tile__TileTemplate*);
    void* DeleteThis(unsigned int);
};

class MenuClassArray
{
  public:
    void SetAt(unsigned int auIndex, Tile*& apTile);
};

extern BSStringT<char> g_menuParsedXML;
extern MenuClassArray g_menuByClassArray;
extern unsigned short g_menuByClassCount;

// @fnv 0x00a1c4a0
Menu::Menu()
{
    pMenu = 0;
    m_pMenuTile = 0;
    m_iModalMenuId = 0;
    m_eFadeState = Interface::FADE_HIDDEN;
    m_bVisible = true;
    m_iSecondaryValue = 0;
    m_bIsSpecial = false;
}

// Returns the file name portion of apPath after the last backslash, or apPath itself if there is none.
// @fnv 0x00a1c970
const char* Menu::GetMenuPath(const char* apPath)
{
    const char* pRequestedMenuPath = apPath;
    const char* pBaseName = pRequestedMenuPath;
    const char* pLastSlash = strrchr(pRequestedMenuPath, '\\');
    if (pLastSlash)
        pBaseName = pLastSlash + 1;
    return pBaseName;
}

// @fnv 0x00483080
void Menu::ParseMenuXML(const char* apXML)
{
    g_menuParsedXML.Set(apXML, 0);
}

// Stores apTile in g_menuByClassArray at index aiClass - 0x3E9 when that index is within g_menuByClassCount.
// @fnv 0x00a1e130
void Menu::SetMenuRootTile(int aiClass, Tile* apTile)
{
    int iIndex = aiClass - 0x3E9;
    if (iIndex >= 0 && iIndex < g_menuByClassCount)
        g_menuByClassArray.SetAt(iIndex, apTile);
}

// @fnv 0x00a1dc20
void Menu::SetMenuVisibility(bool abVisible)
{
    TileMenu* pTileMenu = pMenu;
    pTileMenu->Set(0xFA3, 0.0f, true);
    if (!abVisible)
        UnloadMenuData();
    ClearInterfaceState(0);
    (void)GetMenuScale();
}


inline void* NiFixedString::operator new(size_t size) { return g_memoryManager.Allocate(size); }
inline void NiFixedString::operator delete(void* memory) { g_memoryManager.Deallocate(memory); }

extern NiFixedString* DAT_011f34cc;

// Allocates a NiFixedString from the literal "Tileptr" and stores it in DAT_011f34cc.
// @fnv 0x00a1c6f0
// src: COMMUNITY 0x00a1c6f0
void __cdecl Menu_InitSDM()
{
    DAT_011f34cc = new NiFixedString("Tileptr");
}

struct MenuValueDescriptor
{
    void* __vecDelDtor(unsigned int);
    unsigned int m_uiValueId;
    char* m_pName;
};
typedef char _sizecheck_XMLStorage[sizeof(MenuValueDescriptor) == 8 ? 1 : -1];

class ScrapHeapBuffer;
struct EmptyStruct
{
};
template <class K, class V> class BSMapBase
{
  public:
    bool GetAt(K, V&);
};

extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f34e0;
MenuValueDescriptor* __cdecl LoadCompressedXML(const char*, int);
void __fastcall NiTStringPointerMap_XMLStorage_SetAt(void*, const char*, MenuValueDescriptor*);

// Looks up an XML file by name in DAT_011f34e0; if missing, loads it via LoadCompressedXML and optionally inserts it into the map.
// @fnv 0x00a1c9b0
MenuValueDescriptor* __cdecl GetOrLoadXML(const char* apFilename, bool abAdd)
{
    const char* pfilename = Menu::GetMenuPath(apFilename);
    MenuValueDescriptor* foundXML = 0;
    int pad[12];
    DAT_011f34e0.GetAt((unsigned long)pfilename, (ScrapHeapBuffer*&)foundXML);
    if (foundXML == 0)
    {
        foundXML = LoadCompressedXML(apFilename, 0);
        if (abAdd)
        {
            ((void(__thiscall*)(void*, const char*, MenuValueDescriptor*)) & NiTStringPointerMap_XMLStorage_SetAt)(&DAT_011f34e0, pfilename,
                                                                                           foundXML);
        }
    }
    return foundXML;
}

extern double _gModifierZero;
void __cdecl Interface_NewTimer(Menu* m, float f);
void __cdecl Interface_PopFromEnterStack(int a, int b);
void __cdecl Interface_UpdateAllTimers();
// @fnv 0x00a1d910
void Menu::LoadMenuData()
{
    Tile* t = pMenu;
    float ffade;
    if (!t->ContainsTrait(0xfa3))
        return;
    ffade = pMenu->GetFloat(0xfc1);
    if (ffade == _gModifierZero)
        ffade = pMenu->GetFloat(0xfc2);
    Interface_NewTimer(this, ffade);
    m_eFadeState = Interface::FADING_OUT;
    if (m_iModalMenuId)
    {
        Tile* t2 = pMenu;
        if (t2->ContainsTrait(0x1772))
        {
            Interface_PopFromEnterStack(m_iModalMenuId, 0);
            ClearInterfaceState(0);
        }
    }
    Interface_UpdateAllTimers();
}

void __cdecl Interface_NewTimer(Menu* apMenu, float afFade);
void __cdecl Interface_UpdateAllTimers();

// @fnv 0x00a1db20
void Menu::UnloadMenuData()
{
    float ffade = pMenu ? pMenu->GetFloat(0xfc1) : 0.25f;
    if (ffade == 0.0)
        ffade = pMenu->GetFloat(0xfc2);
    Interface_NewTimer(this, ffade);
    m_eFadeState = Interface::FADING_IN;
    Interface_UpdateAllTimers();
}

// @fnv 0x00a1dd80
void MenuOperations::AddTileTemplate(Tile__TileTemplate* apTemplate)
{
    int u1;
    int u2;
    int u3;
    if (apTemplate != 0)
    {
        m_kTileTemplateList.AddHead(apTemplate);
    }
}

namespace fnv_00a1ca20 {
namespace fnv_00a0be10 {
struct MenuValueDescriptor;
// 0x00a0be10 deletes the 8-byte XML buffer (length +0, data +4); no shared XMLStorage header exists yet.
struct XMLStorage
{
    MenuValueDescriptor* FUN_00a0be10(unsigned int);
};
}
struct MapX_00a1e240
{
    void FUN_00a1e240(const char*);
};
class ScrapHeapBuffer;
template <class K, class V> class BSMapBase
{
  public:
    bool GetAt(K key, V& value);
};
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f34e0;
extern BSMapBase<unsigned long, ScrapHeapBuffer*> DAT_011f34f4;

extern MemoryManager g_memoryManager;
struct BuildStorageX
{
    char pad[0x10];
    bool bFlag;
    void FUN_00a0ad40();
    void* DeleteThis(unsigned int flags)
    {
        FUN_00a0ad40();
        if (flags & 1)
            g_memoryManager.Deallocate(this);
        return this;
    }
};
// @fnv 0x00a1ca20
void RemoveMenuEntries(const char* apFilename, Menu* apMenu)
{
    ScrapHeapBuffer* pXmlStorage;
    {
        ScrapHeapBuffer* pBuildStorage;
        {
            const char* pFilename;
            pFilename = Menu::GetMenuPath(apFilename);
            pXmlStorage = 0;
            DAT_011f34e0.GetAt((unsigned long)pFilename, pXmlStorage);
            if (pXmlStorage)
            {
                fnv_00a0be10::XMLStorage* t2;
                {
                    fnv_00a0be10::XMLStorage* t1;
                    t1 = (fnv_00a0be10::XMLStorage*)pXmlStorage;
                    t2 = t1;
                    t2 ? t2->FUN_00a0be10(1) : 0;
                }
                pXmlStorage = 0;
            }
            ((MapX_00a1e240*)&DAT_011f34e0)->FUN_00a1e240(pFilename);
            pBuildStorage = 0;
            DAT_011f34f4.GetAt((unsigned long)pFilename, pBuildStorage);
            if (pBuildStorage)
            {
                if (apMenu && ((BuildStorageX*)pBuildStorage)->bFlag)
                {
                    ((BuildStorageX*)pBuildStorage)->bFlag = false;
                    apMenu->m_bVisible = true;
                }
                BuildStorageX* t4;
                {
                    BuildStorageX* t3;
                    t3 = (BuildStorageX*)pBuildStorage;
                    t4 = t3;
                    {
                        int pad[13];
                        t4 ? t4->DeleteThis(1) : 0;
                    }
                }
                pBuildStorage = 0;
            }
            ((MapX_00a1e240*)&DAT_011f34f4)->FUN_00a1e240(pFilename);
        }
    }
}
}  // namespace fnv_00a1ca20

void Interface_AddToEnterStack(int, int);
Tile* InterfaceManager_GetOverTileTarget();
void Interface_SetOverTileTarget(Tile*);
Menu* GetFieldD0();
void Interface_SetOverTileMenu(Menu*);

// @fnv 0x00a1dc70
void Menu::SetTileMenu(TileMenu* apMenu, bool abDontAddToStack)
{
    pMenu = apMenu;
    if (apMenu)
    {
        if (apMenu->GetFloat(0xfa7) == 102.0 || apMenu->GetFloat(0xfa7) == 6006.0 ||
            apMenu->GetFloat(0xfa7) == 103.0 || apMenu->GetFloat(0xfa7) == 6007.0)
        {
            m_iModalMenuId = GetClass();
            if (!abDontAddToStack)
                Interface_AddToEnterStack(GetClass(), 0);
            if (GetFieldD0() != this)
            {
                if (InterfaceManager_GetOverTileTarget())
                {
                    Tile* pTile = InterfaceManager_GetOverTileTarget();
                    pTile->Set(0xfc3, 0.0f, true);
                }
                Interface_SetOverTileTarget(0);
                Interface_SetOverTileMenu(0);
            }
        }
    }
}

struct SaveContentDescriptor;
struct blob16
{
    char b[16];
};
struct blob308
{
    char b[308];
};

extern MemoryManager g_memoryManager;

inline void* operator new(size_t auSize)
{
    return g_memoryManager.Allocate(auSize);
}
inline void* operator new[](size_t auSize)
{
    return g_memoryManager.Allocate(auSize);
}
inline void operator delete(void* apMem)
{
    g_memoryManager._DeallocateAlias(apMem);
}
inline void operator delete[](void* apMem)
{
    g_memoryManager._DeallocateAlias(apMem);
}
struct FileFinder
{
    static NiFile* __cdecl GetFile(const char* apName, int aeMode, unsigned int auiBufferSize, unsigned int auiUnk);
};

struct CompressedXML
{
    int iSize;
    char* pData;
    CompressedXML(int aiSize, char* apData) : iSize(aiSize), pData(apData)
    {}
};
// @fnv 0x00a1ce70
CompressedXML* LoadCompressedXML(const char* apFilename, const char* apFileData)
{
    char* pbuf = 0;
    char* pfileData = 0;
    bool bdeletefiledata = false;
    unsigned int ifileSize = 0;
    if (!apFileData)
    {
        BSFile* pfile = (BSFile*)FileFinder::GetFile(apFilename, 0, 0x4000, 0x100);
        if (!pfile || !pfile->IsGood())
        {
            delete pfile;
            return 0;
        }
        ifileSize = pfile->GetSize();
        pfileData = new char[ifileSize];
        bdeletefiledata = true;
        ReadFileData(pfile, pfileData, ifileSize);
        delete pfile;
    }
    else
    {
        pfileData = (char*)apFileData;
        ifileSize = strlen(pfileData);
    }
    pbuf = new char[ifileSize];
    unsigned int ilinelen = 0;
    bool bnewline = false;
    bool bnewline_now = false;
    bool bcomment = false;
    int ipos = 0;
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    for (unsigned int a = 0; a < ifileSize && pfileData[a]; a++)
    {
        if (pfileData[a] == '\t' || pfileData[a] == '\n' || pfileData[a] == '\r')
            continue;
        if (bcomment)
        {
            if (c2 == '-' && c1 == '-' && pfileData[a] == '>')
                bcomment = false;
            c3 = c2;
            c2 = c1;
            c1 = pfileData[a];
            continue;
        }
        if (pfileData[a] == ' ')
        {
            if (c1 == ' ' || c1 == '>')
                continue;
        }
        else if (c1 == ' ' && (pfileData[a] == '<' || pfileData[a] == '>'))
        {
            ipos--;
        }
        else if (c2 == ' ' && c1 == '/' && pfileData[a] == '>')
        {
            ipos--;
            pbuf[ipos - 1] = '/';
        }
        else if (c3 == '<' && c2 == '!' && c1 == '-' && pfileData[a] == '-')
        {
            c3 = c2 = c1 = 0;
            ipos -= 3;
            bcomment = true;
            continue;
        }
        if (ilinelen > 100000)
        {
            if (bnewline && pfileData[a] == '>')
                bnewline_now = true;
            else if (c1 == '<' && pfileData[a] == '/')
                bnewline = true;
        }
        pbuf[ipos] = pfileData[a];
        ipos++;
        c3 = c2;
        c2 = c1;
        c1 = pfileData[a];
        ilinelen++;
        if (bnewline_now)
        {
            bnewline = false;
            bnewline_now = false;
            pbuf[ipos] = '\n';
            ipos++;
            ilinelen = 0;
        }
    }
    pbuf[ipos] = 0;
    if (bdeletefiledata)
        delete[] pfileData;
    return new CompressedXML(ipos, pbuf);
}

struct FUN_00a0c900_shell
{
    void __thiscall NiTStringPointerMap_XMLStorage_SetAt(const char*, int);
};

extern int DAT_011f34f4;

// @fnv 0x00a1cb60
// src: COMMUNITY 0x00a1cb60
void __cdecl Menu_SetParsedXML(char const* a1, int aiValue)
{
    int v4[10];
    ((FUN_00a0c900_shell*)&DAT_011f34f4)->NiTStringPointerMap_XMLStorage_SetAt(a1, aiValue);
}

void Interface_ClearTimer(Menu* apMenu);
void Interface_RecursiveFade(void* apTile, float a, float b);
void __cdecl Interface_PopFromEnterStack(int a, int b);

// @fnv 0x00a1d9e0
// src: XBOX_PDB 0x00a1d9e0
void Menu::InstantFadeOut()
{
    if (m_eFadeState != 4)
    {
        TileMenu* pTile_d;
        TileMenu* pTile_a;
        TileMenu* pTile_b;
        TileMenu* pTile_c;
        pTile_c = pMenu;
        pTile_c->Set(0xfa3, 0.0f, true);
        pTile_b = pMenu;
        pTile_a = (TileMenu*)pTile_b->m_pRenderedNodeEntry.m_pObject;
        Interface_RecursiveFade(pTile_a, 1.0f, 0.0f);
        m_eFadeState = Interface::FADING_OUT;
        if (m_iModalMenuId)
        {
            pTile_d = pMenu;
            if (pTile_d->ContainsTrait(0x1772))
            {
                Interface_PopFromEnterStack(m_iModalMenuId, 0);
                ClearInterfaceState(0);
            }
        }
        Interface_ClearTimer(this);
    }
}

void Interface_ClearTimer(Menu* apMenu);
void Interface_RecursiveFade(void* apTile_c, float a, float b);

// @fnv 0x00a1daa0
void MenuOperations::FinishShow()
{
    if (m_eFadeState == 2)
    {
        void* pTile_a;
        TileMenu* pTile_b;
        TileMenu* pTile_c;
        pTile_c = pMenu;
        pTile_c->Set(0xfa3, 1.0f, true);
        pTile_b = pMenu;
        pTile_a = pTile_b->m_pRenderedNodeEntry.m_pObject;
        Interface_RecursiveFade(pTile_a, 1.0f, 0.0f);
        m_eFadeState = Interface::FADE_SHOWN;
        Interface_ClearTimer(this);
    }
}

void Interface_ClearTimer(Menu* apMenu);
void Interface_RecursiveFade(void* apTile_c, float a, float b);

// @fnv 0x00a1dba0
void MenuOperations::FinishHide()
{
    if (m_eFadeState == 8)
    {
        void* pTile_a;
        TileMenu* pTile_b;
        TileMenu* pTile_c;
        pTile_c = pMenu;
        pTile_c->Set(0xfa3, 0.0f, true);
        pTile_b = pMenu;
        pTile_a = pTile_b->m_pRenderedNodeEntry.m_pObject;
        Interface_RecursiveFade(pTile_a, 1.0f, 0.0f);
        m_eFadeState = Interface::FADE_HIDDEN;
        Interface_ClearTimer(this);
    }
}

extern MemoryManager g_memoryManager;

// Destructs Menu and, if flags has bit 0 set, deallocates this object, then returns this.
// @fnv 0x00a1e170
void* MenuOperations::DeleteThis(unsigned int flags)
{
    this->Menu::~Menu();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct FUN_00a1e4d0_shell
{
    unsigned char pad[8];
    unsigned short m_usMaxSize;
    unsigned char pad2[4];
    unsigned short m_usGrowBy;
    void Resize(unsigned int);
    unsigned int SetAtWithGrowth(unsigned int uiIndex, Tile*& element);
};
// Grows the array if uiIndex is beyond m_usMaxSize, stores element at uiIndex via SetAt, and returns uiIndex.
// @fnv 0x00a1e4d0
// src: GUESS 0x00a1e4d0 (confidence: high)
unsigned int FUN_00a1e4d0_shell::SetAtWithGrowth(unsigned int uiIndex, Tile*& element)
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    if (uiIndex >= m_usMaxSize)
        Resize(m_usGrowBy + uiIndex);
    ((MenuClassArray*)this)->SetAt(uiIndex, element);
    return uiIndex;
}

namespace fnv_00a1cb30 {
class ScrapHeapBuffer;
template <class K, class V> class BSMapBase
{
  public:
    bool GetAt(K a, V& b);
};
extern int DAT_011f34f4;
// Looks up auKey in the map at DAT_011f34f4 and returns the stored pointer, or null if not found.
// @fnv 0x00a1cb30
ScrapHeapBuffer* LookupByKey(unsigned long auKey)
{
    int iPad1;
    int iPad2;
    ScrapHeapBuffer* pkHeap = 0;
    ((BSMapBase<unsigned long, ScrapHeapBuffer*>*)&DAT_011f34f4)->GetAt(auKey, pkHeap);
    return pkHeap;
}
}  // namespace fnv_00a1cb30

namespace fnv_00a1d280 {

extern MemoryManager g_memoryManager;
inline void* operator new[](size_t stSize)
{
    return g_memoryManager.Allocate(stSize);
}
inline void operator delete[](void* pvMem)
{
    g_memoryManager.Deallocate(pvMem);
}

struct XMLHeader
{
    unsigned int uiVersion;
    unsigned int ItemUpdateArray;
    unsigned int uiSize;
};
struct XMLEntry
{
    char acName[128];
    unsigned int uiLength;
    char acData[1];
    unsigned int GetLength() const
    {
        return uiLength;
    }
};
BSFile* __cdecl FileFinder_GetFile_(const char* apPath, int a, int b);
int __cdecl Tile_ParseFile(const char* apName, const char* apData, unsigned int auLength);
void __cdecl Menu_SetParsedXML(const char* apName, int aiValue);
void __cdecl Tile_DeleteGlobalItems();

// @fnv 0x00a1d280
// src: COMMUNITY 0x00a1d280
bool Menu_LoadFinalMasterXML()
{
    bool bSuccess = false;
    BSFile* pkFile = FileFinder_GetFile_("DATA\\FINAL_MASTER_XML.DAT", 0, 0);
    if (pkFile)
    {
        pkFile->Open(false, false);
        unsigned int uiBytesRead;
        XMLHeader kHeader;
        uiBytesRead = pkFile->Read(&kHeader, sizeof(kHeader));
        if (uiBytesRead == sizeof(kHeader) && kHeader.uiVersion == 100)
        {
            char* pBuffer = new char[kHeader.uiSize];
            uiBytesRead = pkFile->Read(pBuffer, kHeader.uiSize);
            if (uiBytesRead == kHeader.uiSize)
            {
                bSuccess = true;
                char* pCurrent = pBuffer;
                for (unsigned int i = 0; i < kHeader.ItemUpdateArray; i++)
                {
                    XMLEntry* pEntry = (XMLEntry*)pCurrent;
                    int iTemplate = Tile_ParseFile(pEntry->acName, pEntry->acData, pEntry->GetLength());
                    Menu_SetParsedXML(pEntry->acName, iTemplate);
                    pCurrent += pEntry->GetLength() + 0x84;
                }
                Tile_DeleteGlobalItems();
                delete[] pBuffer;
            }
            else
            {
                delete[] pBuffer;
                pBuffer = 0;
            }
        }
        delete pkFile;
    }
    return bSuccess;
}
}  // namespace fnv_00a1d280

struct blob12
{
    char b[12];
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

typedef NiTListItem<Tile* > TileListItem;
inline void* TileChildList_menu::GetHeadPos()
{
    return m_pkHead;
}
inline Tile*& TileChildList_menu::GetNext(void*& kPos) const
{
    Tile*& element = ((TileListItem*)kPos)->m_element;
    kPos = ((TileListItem*)kPos)->m_pkNext;
    return element;
}
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
struct InterfaceRoot
{
    static Tile* __cdecl GetPrimaryInterfaceTile();
};

Tile* __cdecl GetNextTile();
inline int GetMenuThickness(Menu* menu) { return menu->m_iSecondaryValue; }
inline void SetTileMenuOwner(TileMenu* tile, Menu* owner) { tile->pMenu = owner; }
inline float NiMaxF(float a, float b)
{
    return a > b ? a : b;
}
extern double g_d100;
extern double DAT_0106f290;

// @fnv 0x00a1dfb0
// src: XBOX_PDB 0x00a1dfb0
float Menu_GetMaxDepth()
{
    void* xelem;
    float fmaxdepth = 0.0f;
    float z;
    Tile* proot = InterfaceRoot::GetPrimaryInterfaceTile();

    xelem = ((TileChildList_menu*)((char*)proot + 4))->GetHeadPos();
    while (xelem)
    {
        Tile* ptile = ((const TileChildList_menu*)((char*)proot + 4))->GetNext(xelem);
        if (ptile && ptile->GetMenu())
        {
            float fdepth =
                GetMenuThickness(ptile->GetMenu()) + ptile->GetFloat(4013);
            fmaxdepth = (fmaxdepth > fdepth) ? fmaxdepth : fdepth;
        }
    }
    z = NiMaxF(10.0f, (float)(int)fmaxdepth) + g_d100;
    if (GetNextTile())
    {
        GetNextTile()->Set(4013, z, true);
        NiPoint3 xyz;
        Tile* pcursor = GetNextTile();
        // Preserve the original trivial copies independently of NiPoint3 copy operators.
        *(blob12*)&xyz = *(blob12*)((char*)pcursor->m_pRenderedNodeEntry.operator->() + 0x58);
        xyz.y = z * DAT_0106f290;
        *(blob12*)((char*)pcursor->m_pRenderedNodeEntry.operator->() + 0x58) = *(blob12*)&xyz;
    }
    return fmaxdepth + 2.0;
}

typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];


int __cdecl FUN_00ec6da0(char const*, char const*);

inline bool NiFixedString::Equals(char* p)
{
    if (m_kHandle == p) return true;
    if (!p || !m_kHandle) return false;
    return !FUN_00ec6da0(m_kHandle, p);
}


extern MemoryManager _g_memoryManager;

class Tile__TileTemplate
{
  public:
    char* name;
};

struct Tile__BuildStorage
{
    void SetTileTemplate(Tile__TileTemplate*);
};

struct FUN_00a0ad40
{
    Tile__TileTemplate* pTemplate;
    int data[4];
    ~FUN_00a0ad40();
};

struct FUN_00a0ac80 : public FUN_00a0ad40
{
    void Init(int*, int);
    FUN_00a0ac80()
    {
        int* pkItem = data;
        int iIndex = 0;
        int iCount = 4;
        int* pkEnd = data + 4;
        pTemplate = 0;
        while (pkItem != pkEnd && iIndex < iCount)
        {
            Init(pkItem, iIndex);
            ++pkItem;
            ++iIndex;
        }
    }
    static void* operator new(unsigned int auSize)
    {
        return _g_memoryManager.Allocate(auSize);
    }
    static void operator delete(void* apMem)
    {
        _g_memoryManager._DeallocateAlias(apMem);
    }
};

extern FUN_00a0ac80* DAT_011f32d0;

Tile* __fastcall CreateMenuTiles(Tile*, void*);

void __fastcall ApplyTileTemplate(Tile*, Tile__TileTemplate*);

// Looks up a tile template by name in a linked list, builds a tile from it under apParent, and returns the new tile or null.
// @fnv 0x00a1ddb0
Tile* Menu::CreateTileFromTemplate(Tile* apParent, const char* axName, Tile* apLast)
{
    Tile* preturn_val = 0;
    if (apLast)
        m_pMenuTile = apLast;
    Tile__TileTemplate* ptemplate = 0;
    BSSimpleList<Tile__TileTemplate*>* pCurrentElementNext = &m_kTileTemplateList;
    NiFixedString nm(axName);
    while (pCurrentElementNext)
    {
        ptemplate = pCurrentElementNext->m_item;
        if (ptemplate && nm.Equals(ptemplate->name))
            break;
        pCurrentElementNext = pCurrentElementNext->m_pkNext;
    }
    if (ptemplate)
    {
        FUN_00a0ac80* pbuild = DAT_011f32d0;
        DAT_011f32d0 = new FUN_00a0ac80;
        ((Tile__BuildStorage*)DAT_011f32d0)->SetTileTemplate(ptemplate);
        preturn_val = ((Tile*(__thiscall*)(Tile*, void*)) &CreateMenuTiles)(apParent, ptemplate);
        ((void(__thiscall*)(Tile*, Tile__TileTemplate*)) &ApplyTileTemplate)(preturn_val, ptemplate);
        DAT_011f32d0->pTemplate = 0;
        delete DAT_011f32d0;
        DAT_011f32d0 = pbuild;
    }
    return preturn_val;
}

void* g_pTileItemFreeList;

void LockTileItemPool();
void UnlockTileItemPool();

template <class T> class TileItemAllocator
{
  public:
    void Deallocate(void* apMem)
    {
        void* pFree = apMem;
        LockTileItemPool();
        void* pOld = g_pTileItemFreeList;
        ((void**)pFree)[1] = 0;
        ((void**)pFree)[0] = pOld;
        g_pTileItemFreeList = pFree;
        UnlockTileItemPool();
    }
};

class TileElement
{
  public:
    TileElement* m_pkNext;
    TileElement* m_pkPrev;
    Tile* m_pkElement;
};

template <class TAlloc, class T, class TItem> class TileItemPointerListBase
{
  public:
    TItem* m_pkHead;
    TItem* m_pkTail;
    TAlloc m_kItemCount;

    void RemoveAll()
    {
        TItem* pItem = m_pkHead;
        while (pItem)
        {
            TItem* pNext = pItem->m_pkNext;
            TItem* pDelete = pItem;
            pDelete->m_pkElement = 0;
            m_kItemCount.Deallocate(pDelete);
            pItem = pNext;
        }
        m_pkHead = 0;
        m_pkTail = 0;
    }
};

struct TileItemListBase_00a1bbd0
{
    ~TileItemListBase_00a1bbd0()
    {}
};

struct FUN_00a1bbd0 : TileItemListBase_00a1bbd0,
                      TileItemPointerListBase<TileItemAllocator<unsigned int>, Tile*, TileElement>
{
    ~FUN_00a1bbd0();
};

// Destructor that removes all items from the tile pointer list by calling RemoveAll().
// @fnv 0x00a1bbd0
FUN_00a1bbd0::~FUN_00a1bbd0()
{
    RemoveAll();
}

namespace fnv_00a1cb80 {
extern "C" void* __cdecl fnv_zlib_memset(void* dst, int val, unsigned int size);

extern MemoryPool* DAT_011f63b8[256];
}  // namespace fnv_00a1cb80

inline void MemoryManager::DeallocateAlias(void* pvBuffer)
{
    if (!pvBuffer) return;
    if (!bInitialized)
    {
        FreePointer(pvBuffer, 0);
        return;
    }
    IMemoryHeap* heap = pHeapsByContextA[65];
    if (!heap)
    {
        FreePointer(pvBuffer, 0);
        return;
    }
    MemoryPool* pool = fnv_00a1cb80::DAT_011f63b8[(unsigned int)pvBuffer >> 24];
    if (pool && (unsigned int)pvBuffer >= (unsigned int)pool->m_pPoolBase &&
        (unsigned int)pvBuffer < (unsigned int)pool->m_pPoolBase + pool->m_uiPoolSize)
    {
        pool->Free(pvBuffer);
        return;
    }
    IMemoryHeap* owner = GetHeapForPointer((const void*)pvBuffer);
    if (owner) owner->Deallocate(pvBuffer, false);
    else FreePointer(pvBuffer, 0);
}
namespace fnv_00a1cb80 {

extern MemoryManager _g_memoryManager;

class FileFinder
{
  public:
    static BSFile* GetFile(const char* apPath, int aiMode, unsigned int auiBufferSize, unsigned int auiAccess);
};

struct CompressedXML;
CompressedXML* LoadCompressedXML(const char* apPath, const char* apXML);

struct WeightedMapNode
{
    WeightedMapNode* unk00;
    const char* unk04;
    int unk08;
};
struct MapAllocator
{
    WeightedMapNode* NiGeometry_AddProperty();
};
struct FUN_00a0c900_shell
{
    virtual void Unk00();
    virtual unsigned int Hash(const char*);
    virtual bool Equal(const char*, const char*);
    virtual void Set(WeightedMapNode*, const char*, int);
    unsigned int unk04;
    WeightedMapNode** unk08;
    unsigned int unk0C;
    bool unk10;
// src: COMMUNITY 0x00a0c900
    void NiTStringPointerMap_XMLStorage_SetAt(const char* apPath, int apXML)
    {
        unsigned int bucket = Hash(apPath);
        WeightedMapNode* node = unk08[bucket];
        unsigned int count = 0;
        while (node)
        {
            ++count;
            if (Equal(apPath, node->unk04))
            {
                if (!unk10)
                    node->unk04 = apPath;
                node->unk08 = apXML;
                return;
            }
            node = node->unk00;
        }
        node = ((MapAllocator*)&unk0C)->NiGeometry_AddProperty();
        Set(node, apPath, apXML);
        node->unk00 = unk08[bucket];
        unk08[bucket] = node;
        ++unk0C;
    }
};
extern FUN_00a0c900_shell DAT_011f34e0;

// Reads Data\Menus\master_menu_file.txt, parses each @#$%-separated entry into a path and XML, registers them in DAT_011f34e0, and returns the entry count.
// @fnv 0x00a1cb80
int LoadMasterMenuFiles()
{
    BSFile* pFile7 = FileFinder::GetFile("Data\\Menus\\master_menu_file.txt", 0, 0x4000, 4);
    if (!pFile7 || !pFile7->Good())
    {
        return 0;
    }

    char pathBuffer6[256];
    char* _cur_ptr;
    int kBufSize;
    char* found9;
    int size3;
    char* buffer3;
    int count7;
    const char* stripped2;
    int lengthX;
    char* endPtr;
    char* xml2;
    CompressedXML* pXML2;

    size3 = pFile7->GetSize() + 1;
    buffer3 = (char*)_g_memoryManager.Allocate(size3);
    count7 = 0;

    size3 = ReadFileData(pFile7, buffer3, size3);

    delete pFile7;

    _cur_ptr = buffer3;
    found9 = strstr(_cur_ptr, "@#$%");
    kBufSize = 256;

    while (found9)
    {
        fnv_zlib_memset(pathBuffer6, 0, kBufSize);

        xml2 = strstr(_cur_ptr, ".xml");
        endPtr = xml2 + 4;
        do
        {
            xml2--;
        } while (*xml2 != ' ' && *xml2 != '-');
        xml2++;

        lengthX = endPtr - xml2;
        memcpy(pathBuffer6, xml2, lengthX);
        *found9 = 0;

        pXML2 = LoadCompressedXML(pathBuffer6, _cur_ptr);
        stripped2 = Menu::GetMenuPath(pathBuffer6);
        DAT_011f34e0.NiTStringPointerMap_XMLStorage_SetAt(stripped2, (int)pXML2);

        count7++;
        _cur_ptr = found9 + 4;
        found9 = 0;
        if (_cur_ptr - buffer3 < size3)
        {
            found9 = strstr(_cur_ptr, "@#$%");
        }
    }

    _g_memoryManager.DeallocateAlias(buffer3);
    return count7;
}
}  // namespace fnv_00a1cb80

namespace fnv_00a1d410 {
// Writes every registered compressed entry to "final_master_xml.dat": a 12-byte header, then for each
// entry a 128-byte name, the 4-byte length and the payload. Returns false if any write came up short.
struct CompressedEntry
{
    unsigned int m_uiCharacterCount;
    unsigned char* m_pCompressedData;
};
extern int DAT_01095574;
extern int DAT_01095524;
extern int DAT_0103d420;
extern int DAT_0103d418;
extern const char DAT_01095548[];
extern const char DAT_01095528[];
void __cdecl Tile_InsertIncludedFiles(CompressedEntry* apEntry);
void __cdecl BSsprintf(char* apBuffer, unsigned int auiSize, const char* apFormat, const char* apName,
                          unsigned int auiLength);
void __cdecl ProgramFlow(const char* apText);
void __cdecl _NiFree_00aa10f0(void* apMem);
void* __cdecl FUN_00ec61c0(void* apDst, int aiValue, unsigned int auiSize);
int __cdecl FUN_00ec65a6(char* apDst, unsigned int auiSize, const char* apSrc);

struct MapItem
{
    MapItem* m_pkNext;
    const char* m_pcKey;
    CompressedEntry* m_pkVal;
};
struct EntryMap
{
    unsigned int m_uiHashSize;
    unsigned int* m_ppkHashTable;
    unsigned int GetFirstPos()
    {
        for (unsigned int i = 0; i < m_uiHashSize; ++i)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    virtual void v00();
    virtual unsigned int KeyToHashIndex(const char* pcKey);
    void GetNext(unsigned int& kPos, const char*& pcName, CompressedEntry*& pkEntry)
    {
        MapItem* pkItem = (MapItem*)kPos;
        pcName = pkItem->m_pcKey;
        pkEntry = pkItem->m_pkVal;
        if (pkItem->m_pkNext)
        {
            kPos = (unsigned int)pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(pkItem->m_pcKey);
        unsigned int nextBucket = i + 1;
        for (; nextBucket < m_uiHashSize; ++nextBucket)
        {
            pkItem = (MapItem*)m_ppkHashTable[nextBucket];
            if (pkItem)
            {
                kPos = (unsigned int)pkItem;
                return;
            }
        }
        kPos = 0;
    }
};
extern EntryMap DAT_011f34e0;

extern MemoryManager DAT_011f6238;

struct EntryArray
{
    int* m_vtbl;
    CompressedEntry** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned int m_uiGrowBy;
    void FUN_00a1e450(unsigned int auiMax, unsigned int auiGrowBy);
    unsigned int SetAtGrow(unsigned int auiIndex, CompressedEntry*& apEntry);
    CompressedEntry* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    static void Deallocate(void* apMem)
    {
        _NiFree_00aa10f0(apMem);
    }
    EntryArray()
    {
        FUN_00a1e450(0, 1);
        m_vtbl = &DAT_01095574;
    }
    ~EntryArray()
    {
        m_vtbl = &DAT_01095524;
        Deallocate(m_pBase);
    }
};
struct NameArray
{
    int* m_vtbl;
    const char** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    void NiTArray_char_const_NiTMallocInterface_char_const_Init(unsigned int auiMax, unsigned int auiGrowBy);
    void Add(const char*& apName);
    const char* GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    static void Deallocate(void* apMem)
    {
        _NiFree_00aa10f0(apMem);
    }
    NameArray()
    {
        NiTArray_char_const_NiTMallocInterface_char_const_Init(0, 1);
        m_vtbl = &DAT_0103d420;
    }
    ~NameArray()
    {
        m_vtbl = &DAT_0103d418;
        Deallocate(m_pBase);
    }
};

struct FileHeader
{
    unsigned int m_uiFormatVersion;
    unsigned int m_uiCount;
    unsigned int m_uiTotal;
};

// @fnv 0x00a1d410
bool WriteCompressedEntryArchive()
{
    unsigned int a;
    {
        bool f = true;
        {
            FileHeader g;
            g.m_uiFormatVersion = 100;
            g.m_uiTotal = 0;
            g.m_uiCount = 0;
            {
                BSFile* b;
                {
                    EntryArray records;
                    NameArray names;
                    unsigned int e = DAT_011f34e0.GetFirstPos();
                    while (e != 0)
                    {
                        char debug[260];
                        {
                            CompressedEntry* entry;
                            {
                                const char* index;
                                DAT_011f34e0.GetNext(e, index, entry);
                                Tile_InsertIncludedFiles(entry);
                                records.SetAtGrow(records.m_usSize, entry);
                                names.Add(index);
                                BSsprintf(debug, 0x104, DAT_01095548, index, entry->m_uiCharacterCount);
                                ProgramFlow(debug);
                                g.m_uiTotal += 0x84 + entry->m_uiCharacterCount;
                                ++g.m_uiCount;
                            }
                        }
                    }
                    b = new BSFile(DAT_01095528, 1, 0x4000, false);
                    a = b->NiBinaryStream::Write((const void*)&g, 12);
                    if (a == 12)
                    {
                        for (unsigned int i = 0; i < g.m_uiCount; ++i)
                        {
                            CompressedEntry* element = records.GetAt(i);
                            {
                                char filename[128];
                                {
                                    const char* name = names.GetAt(i);
                                    FUN_00ec61c0(filename, 0, 128);
                                    FUN_00ec65a6(filename, 128, name);
                                    a = b->NiBinaryStream::Write((const void*)filename, 128);
                                    if (a != 128)
                                        f = false;
                                    a = b->NiBinaryStream::Write((const void*)element, 4);
                                    if (a != 4)
                                        f = false;
                                    a = b->NiBinaryStream::Write((const void*)element->m_pCompressedData, element->m_uiCharacterCount);
                                    if (a != element->m_uiCharacterCount)
                                        f = false;
                                    if (!f)
                                        break;
                                }
                            }
                        }
                    }
                    else
                    {
                        f = false;
                    }
                    delete b;
                    return f;
                }
            }
        }
    }
}
}  // namespace fnv_00a1d410

namespace fnv_00a1c520 {
extern bool DAT_011f308f[];
int Interface_PopFromEnterStack(int, bool);
void FUN_00a1e130(int, Tile*);
int Interface_GetTopMenuID();

extern MemoryManager g_memoryManager;

extern OSGlobals* g_osGlobals;
struct TemplateItemNode
{
    void* m_item;
    TemplateItemNode* m_pkNext;
    ~TemplateItemNode()
    {}
};
struct TemplateItemList : TemplateItemNode
{
    void RemoveAll();
    ~TemplateItemList()
    {
        RemoveAll();
    }
};
class TileCollection
{
  public:
    NiFixedString kName;
    int unk04;
    TemplateItemList kItems;
    void Destroy();
    ~TileCollection()
    {
        Destroy();
    }
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

inline void ClearMenuClass(int menuClass)
{
    if (menuClass >= 1001 && menuClass <= 1084)
        DAT_011f308f[menuClass] = false;
}
}  // namespace fnv_00a1c520
using fnv_00a1c520::ClearMenuClass;
using fnv_00a1c520::Interface_PopFromEnterStack;
using fnv_00a1c520::FUN_00a1e130;
using fnv_00a1c520::TileCollection;
using fnv_00a1c520::Interface_GetTopMenuID;
using fnv_00a1c520::g_osGlobals;
// Clears the menu class, deletes its tiles, and removes template-list nodes.
// @fnv 0x00a1c520
Menu::~Menu()
{
    ClearMenuClass(m_iMenuId);
    if (m_iModalMenuId)
        Interface_PopFromEnterStack(m_iModalMenuId, 1);
    FUN_00a1e130(m_iMenuId, 0);
    if (pMenu)
    {
        SetTileMenuOwner(pMenu, 0);
        delete pMenu;
    }
    pMenu = 0;
    if (m_bVisible)
    {
        BSSimpleList<Tile__TileTemplate*>* item = &m_kTileTemplateList;
        while (item)
        {
            TileCollection* value = (TileCollection*)item->m_item;
            if (value)
                delete value;
            item = item->m_pkNext;
        }
    }
    m_kTileTemplateList.RemoveAll();
    if (!Interface_GetTopMenuID() && g_osGlobals->Main_GetControls()->Controls_GetUserAction(14, 0))
        g_osGlobals->Main_GetControls()->SetFlag(8);
}
