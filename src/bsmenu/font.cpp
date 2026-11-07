#include "../../include/NiRect.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/BSStringT.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShaderManager.h"
#include "../../include/Bound.h"
#include "../../include/Font.h"
#include "../../include/FontData.h"
#include "../../include/FontManager.h"
#include "../../include/GO.h"
#include "../../include/MapEntryCount.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiColorA.h"
#include "../../include/NiCriticalSection.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiGlobalStringTable.h"
// NiMemObjectAllocation_font: local type (was include/NiMemObjectAllocation.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiMemObjectAllocation_font
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer);
    static void operator delete(void* pointer, unsigned int size);
};
#include "../../include/NiPoint2.h"
#include "../../include/NiPropertyState.h"
#include "../../include/NiTPointerAllocator_unsigned_int_.h"
#include "../../include/NiTriBasedGeom.h"
#include "../../include/NiTriBasedGeomData.h"
#include "../../include/NiTriShape.h"
#include "../../include/NiTriShapeData.h"
#include "../../include/StrMem.h"
#include "../../include/NiPoint3.h"
inline NiColorA::NiColorA(float fR, float fG, float fB, float fA)
{
    r = fR; g = fG; b = fB; a = fA;
}
inline NiPoint2::NiPoint2(float fX, float fY) { x = fX; y = fY; }

// bsmenu/font.cpp: Font, FontManager, OwnQ, SBox and more (57 functions)

// bsmenu/font_types.h: declares ::NiRect<float>, ButtonIcon, Font, FontManager

#include <stddef.h>
class NiTexturingProperty;
struct FontPoint3 { float x, y, z; };

unsigned int __cdecl strlen(const char*);
inline unsigned int FontStringRuntimeLength(const char* text) { return strlen(text); }

template <class T> inline BSStringT<T>::~BSStringT() { Set(0, 0); }
template <class T> __forceinline const T* BSStringT<T>::String() const { return pString; }
template <class T> __forceinline unsigned int BSStringT<T>::Length() const
{
    return sLen == 0xffff ? FontStringRuntimeLength(pString) : sLen;
}
template <class T> inline unsigned int BSStringT<T>::MaxLength() { return sMaxLen; }
template <class T> inline void BSStringT<T>::SetLength(unsigned int n)
{
    sLen = n <= 0xffff ? (unsigned short)n : 0xffff;
}
inline char& FontStringCharacter(BSStringT<char>& text, unsigned int index)
{
    return text.pString[text.pString ? index : 0];
}



class ButtonIcon
{
  public:
    float m_fGlyphWidthInPixels;
    float m_fHorizontalOffset;
    float m_fGlyphVerticalOffset;
    float m_fHorizontalSpacing;
    ::NiRect<float> m_kTextureCoordinates;
};

typedef BSSimpleArray<ButtonIcon, 1024> FontButtonIconArray;

void Font::MapCharacter(unsigned char& character)
{
    switch (character)
    {
    case 0x91:
    case 0x92:
        character = '\'';
        break;
    case 0x93:
    case 0x94:
        character = '"';
        break;
    }
}

inline NiGeometryData* NiGeometry::GetModelData() { return m_spModelData.m_pObject; }

inline Font* FontManager::GetFont(int index) { return pFont[index]; }

// @fnv 0x00a1b3a0
float FontManager::GetFontPadding(int font)
{
    float padding = 0.0f;
    switch (font)
    {
    case 3:
        padding = 6.0f;
        break;
    case 7:
        padding = 2.0f;
        break;
    case 2:
    case 6:
        padding = 4.0f;
        break;
    }
    return padding;
}

// @fnv 0x005bd5b0
FontManager* FontManager::Instance()
{
    return pInstance;
}

// corrected to the evidenced PC layouts. See EVIDENCE.md. No helper bodies.

class NiNode;
class NiCollisionObject;
class FourComponentFloatVector;
class NiProperty;
class NiTimeController;
class NiExtraData;
class NiAdditionalGeometryData;
class NiGeometryData__RendererData;
class NiSkinInstance;
class NiShader;
class NiTriShapeData__SharedNormalArray;
class NiTriShapeData__SNAMemBlock;
class NiTListItem_NiPointer_NiProperty___;

class FontCharacterInfo
{
  public:
    int m_iCharacterCode;           // +0x0, 4 bytes
    NiPoint2 pMapping[4];  // +0x4, 32 bytes
    float m_fGlyphWidthInPixels;                   // +0x24, 4 bytes
    float m_fGlyphExtent;                  // +0x28, 4 bytes
    float m_fHorizontalAdvance;     // +0x2C, 4 bytes
    float m_fHorizontalSpacing;     // +0x30, 4 bytes
    float m_fVerticalOffset;        // +0x34, 4 bytes
};

// Complete compiled WIP for Font::AddCharacterToShape at 00a142d0; see NOTES.md.
// The shared Font declaration still requires the legacy color pointer type.
// Coordinate records contain genuine glyph coordinates, never frame storage.
void Font::AddCharacterToShape(FontCharacterInfo* letter, int index, NiTriShape* shape,
                   NiPoint3& position, const NiColorA* color)
{
    position.x += letter->m_fHorizontalAdvance;
    int baseVertex = index * 4;
    NiGeometryData* vertexData = shape->m_spModelData.m_pObject;
    FontPoint3* vertexArray = (FontPoint3*)vertexData->m_pkVertex;
    FontPoint3* vertices = vertexArray + baseVertex;

    struct GlyphCornerCoordinates { float x; float y; float z; };
    GlyphCornerCoordinates topLeftCoordinates;
    topLeftCoordinates.x = position.x;
    topLeftCoordinates.y = position.y;
    topLeftCoordinates.z = letter->m_fVerticalOffset + position.z;
    FontPoint3 topLeft;
    topLeft.x = topLeftCoordinates.x;
    topLeft.y = topLeftCoordinates.y;
    topLeft.z = topLeftCoordinates.z;
    vertices[0] = topLeft;

    GlyphCornerCoordinates bottomLeftCoordinates;
    bottomLeftCoordinates.x = position.x;
    bottomLeftCoordinates.y = position.y;
    bottomLeftCoordinates.z = (letter->m_fVerticalOffset + position.z) - letter->m_fGlyphExtent;
    FontPoint3 bottomLeft;
    bottomLeft.x = bottomLeftCoordinates.x;
    bottomLeft.y = bottomLeftCoordinates.y;
    bottomLeft.z = bottomLeftCoordinates.z;
    vertices[1] = bottomLeft;

    GlyphCornerCoordinates topRightCoordinates;
    topRightCoordinates.x = letter->m_fGlyphWidthInPixels + position.x;
    topRightCoordinates.y = position.y;
    topRightCoordinates.z = letter->m_fVerticalOffset + position.z;
    FontPoint3 topRight;
    topRight.x = topRightCoordinates.x;
    topRight.y = topRightCoordinates.y;
    topRight.z = topRightCoordinates.z;
    vertices[2] = topRight;

    GlyphCornerCoordinates bottomRightCoordinates;
    bottomRightCoordinates.x = letter->m_fGlyphWidthInPixels + position.x;
    bottomRightCoordinates.y = position.y;
    bottomRightCoordinates.z = (letter->m_fVerticalOffset + position.z) - letter->m_fGlyphExtent;
    FontPoint3 bottomRight;
    bottomRight.x = bottomRightCoordinates.x;
    bottomRight.y = bottomRightCoordinates.y;
    bottomRight.z = bottomRightCoordinates.z;
    vertices[3] = bottomRight;

    NiGeometryData* textureData = shape->m_spModelData.m_pObject;
    NiPoint2* textureArray = textureData->m_pkTexture;
    NiPoint2* textureCoordinates = (NiPoint2*)(textureArray + baseVertex);

    NiPoint2 topLeftUV;
    topLeftUV.x = letter->pMapping[0].x;
    topLeftUV.y = letter->pMapping[0].y;
    NiPoint2 topLeftTexture;
    topLeftTexture.x = topLeftUV.x;
    topLeftTexture.y = topLeftUV.y;
    textureCoordinates[0] = topLeftTexture;

    NiPoint2 bottomLeftUV;
    bottomLeftUV.x = letter->pMapping[2].x;
    bottomLeftUV.y = letter->pMapping[2].y;
    NiPoint2 bottomLeftTexture;
    bottomLeftTexture.x = bottomLeftUV.x;
    bottomLeftTexture.y = bottomLeftUV.y;
    textureCoordinates[1] = bottomLeftTexture;

    NiPoint2 topRightUV;
    topRightUV.x = letter->pMapping[1].x;
    topRightUV.y = letter->pMapping[1].y;
    NiPoint2 topRightTexture;
    topRightTexture.x = topRightUV.x;
    topRightTexture.y = topRightUV.y;
    textureCoordinates[2] = topRightTexture;

    NiPoint2 bottomRightUV;
    bottomRightUV.x = letter->pMapping[3].x;
    bottomRightUV.y = letter->pMapping[3].y;
    NiPoint2 bottomRightTexture;
    bottomRightTexture.x = bottomRightUV.x;
    bottomRightTexture.y = bottomRightUV.y;
    textureCoordinates[3] = bottomRightTexture;

    NiTriShapeData* triangleData =
        static_cast<NiTriShapeData*>(shape->m_spModelData.m_pObject);
    unsigned short* triangles = triangleData->GetTriangleList() + index * 6;
    triangles[0] = static_cast<unsigned short>(baseVertex);
    triangles[1] = static_cast<unsigned short>(baseVertex + 1);
    triangles[2] = static_cast<unsigned short>(baseVertex + 2);
    triangles[3] = static_cast<unsigned short>(baseVertex + 2);
    triangles[4] = static_cast<unsigned short>(baseVertex + 1);
    triangles[5] = static_cast<unsigned short>(baseVertex + 3);

    position.x += letter->m_fGlyphWidthInPixels + (letter->m_fGlyphWidthInPixels > 0.0 ? letter->m_fHorizontalSpacing : 0.0f);
}

// Replaces smart single and double quote bytes with plain apostrophe and double quote characters in place.
// @fnv 0x00a122b0
void __cdecl NormalizeSmartQuotes(unsigned char* acChar)
{
    switch (*acChar)
    {
    case 0x91:
    case 0x92:
        *acChar = '\'';
        break;
    case 0x93:
    case 0x94:
        *acChar = '"';
        break;
    }
}

extern char str_010a435c[];

unsigned int __cdecl strlen(const char*);
int __cdecl _stricmp(const char*, const char*);
int __cdecl _strnicmp(const char*, const char*, unsigned int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);

// Builds dst from src: prefixes "Trees" when src ends in "spt", prefixes str_010a435c unless src starts with "meshes\", else copies src.
// @fnv 0x00af4250
void __cdecl BuildAssetPath(const char* pcSourcePath, char* pcDestPath, unsigned int uiDestSize)
{
    unsigned int len = strlen(pcSourcePath);
    if (len > 3 && _stricmp(pcSourcePath + len - 3, "spt") == 0) {
        strcpy_s(pcDestPath, uiDestSize, "Trees");
        strcat_s(pcDestPath, uiDestSize, pcSourcePath);
    } else if (_strnicmp(pcSourcePath, "meshes\\", 7) != 0) {
        strcpy_s(pcDestPath, uiDestSize, str_010a435c);
        strcat_s(pcDestPath, uiDestSize, pcSourcePath);
    } else {
        strcpy_s(pcDestPath, uiDestSize, pcSourcePath);
    }
}

void __cdecl BuildAssetPath(int, char*, int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
struct FUN_00c3d090_shell2 {
    char pad[0x28];
    char* p;
    void QueuedFileEntry_GetLookupFileName(int flag, char* dst);
};
// @fnv 0x00c3d090
// src: XBOX_PDB 0x00c3d090
void FUN_00c3d090_shell2::QueuedFileEntry_GetLookupFileName(int flag, char* dst)
{
    if (flag == 0) {
        BuildAssetPath((int)p, dst, 0x104);
    } else {
        char* src = p;
        strcpy_s(dst, 0x104, src);
    }
}

extern MemoryManager g_memoryManager;
inline void* NiPoint2::operator new[](size_t size) { return g_memoryManager.Allocate(size); }
// Shared FontManager has no constructor or allocation declarations.
struct fnv_00a168b0 {
    char data[0x24];
    fnv_00a168b0();
    static __forceinline void* operator new(unsigned int s) { return g_memoryManager.Allocate(s); }
    static __forceinline void operator delete(void*) {}
};

// Allocates a new FontManager instance and stores it in FontManager::pInstance if none exists.
// @fnv 0x00a167c0
void FontManager::Init()
{
    if (!FontManager::pInstance)
        FontManager::pInstance = (FontManager*)new fnv_00a168b0;
}

// Font does not declare these reference-count accessors.
struct FontReferenceAccess : Font {
    unsigned short Get() { return iRefCount; }
    unsigned short Dec() { --iRefCount; return iRefCount; }
};
// @fnv 0x00a152d0
// src: COMMUNITY 0x00a152d0
void Font::Unload_00a152d0()
{
    if (((FontReferenceAccess*)this)->Get()) {
        if (!((FontReferenceAccess*)this)->Dec())
            ClearArray();
    }
}

namespace fnv_00a16850 {
extern MemoryManager g_memoryManager;
// Shared FontManager has no destructor declaration.
struct FUN_00a16850_shell {
    void ProcessEntries_00a16d20();
// Calls FUN_00a16d20, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a16850
    FUN_00a16850_shell* Destroy(unsigned int flags)
    {
        ProcessEntries_00a16d20();
        if (flags & 1)
            g_memoryManager.Deallocate(this);
        return this;
    }
};
}

void FontManager::Free()
{
    using namespace fnv_00a16850;
    if (FontManager::pInstance) {
        FontManager* fm = FontManager::pInstance;
        FUN_00a16850_shell* p = reinterpret_cast<FUN_00a16850_shell*>(fm);
        p ? p->Destroy(1) : 0;
        FontManager::pInstance = 0;
    }
}

namespace fnv_00a16d20 {
extern MemoryManager g_memoryManager;
// Font has no deleting-destructor helper declaration.
struct FontDeletion : Font {
// Calls FUN_00a121e0, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a16d20
    FontDeletion* Destroy(unsigned int flags)
    {
        FUN_00a121e0();
        if (flags & 1)
            g_memoryManager.Deallocate(this);
        return this;
    }
};
struct FUN_00a16d20_shell {
    FontDeletion* pFont[8];
    void ProcessEntries_00a16d20();
};
// src: GUESS 0x00a16d20 (confidence: low)
void FUN_00a16d20_shell::ProcessEntries_00a16d20()
{
    for (int i = 0; i < 8; ++i) {
        FontDeletion* f = pFont[i];
        FontDeletion* p = f;
        p ? p->Destroy(1) : 0;
        pFont[i] = 0;
    }
}
}  // namespace fnv_00a16d20

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_00a1b410_shell { char* p; void ClearPointer(); };
// Sets p to null, then if p is non-null increments the counter at p+4 via InterlockedIncrement.
// @fnv 0x00a1b410
void FUN_00a1b410_shell::ClearPointer()
{
    p = 0;
    if (p) {
        char* q = p;
        InterlockedIncrement((long*)(q + 4));
    }
}

struct FUN_00a1b940 {
    int a;
    int b;
    int c;
    FUN_00a1b940();
};
// Initializes the three integer members a, b and c to zero.
// @fnv 0x00a1b940
FUN_00a1b940::FUN_00a1b940()
{
    c = 0;
    a = 0;
    b = 0;
}

struct FUN_00a1b970_t {
    char pad[0x1c];
    BSStringT<char> str;
    void ClearString();
};
// @fnv 0x00a1b970
void FUN_00a1b970_t::ClearString()
{
    double d0, d1, d2, d3;
    str.Set(0, 0);
}

inline void* operator new(unsigned int, void* p) { return p; }
struct FUN_00a1c1f0_vec { float a, b, c, d; FUN_00a1c1f0_vec() { a = 0.0f; b = 0.0f; c = 0.0f; d = 0.0f; } };
struct FUN_00a1c1f0_elem { int pad[4]; FUN_00a1c1f0_vec v; };
struct FUN_00a1c1f0_shell {
    void ConstructElements(FUN_00a1c1f0_elem* apFirstAddr, unsigned int aiCount);
};
// Default-constructs aiCount FUN_00a1c1f0_elem objects in place starting at apFirstAddr.
// @fnv 0x00a1c1f0
void FUN_00a1c1f0_shell::ConstructElements(FUN_00a1c1f0_elem* apFirstAddr, unsigned int aiCount)
{
    unsigned int i;
    FUN_00a1c1f0_elem* item;
    for (i = 0; i < aiCount; ++i)
        item = new (&apFirstAddr[i]) FUN_00a1c1f0_elem;
}

struct FUN_00a1c270_node {
    FUN_00a1c270_node* next;
    FUN_00a1c270_node* prev;
};
struct FUN_00a1c270_shell {
    FUN_00a1c270_node* head;
    FUN_00a1c270_node* tail;
    int count;
    void NiTListBase_AddNodeHead_1(FUN_00a1c270_node* node);
};
// Inserts node at the head of the doubly linked list, fixing up prev/next links, tail when empty, and incrementing count.
// @fnv 0x00a1c270
// src: COMMUNITY 0x00a1c270
void FUN_00a1c270_shell::NiTListBase_AddNodeHead_1(FUN_00a1c270_node* node)
{
    node->prev = 0;
    node->next = head;
    if (head)
        head->prev = node;
    else
        tail = node;
    head = node;
    count = count + 1;
}

namespace fnv_00a1c2d0 {
extern MemoryManager g_memoryManager;
struct FUN_00a1c2d0_node {
    FUN_00a1c2d0_node* next;
    int pad;
    int data;
};
struct FUN_00a1c2d0_shell {
    FUN_00a1c2d0_node* head;
    FUN_00a1c2d0_node* tail;
    int count;
    void ClearLinkedNodes();
};
// Walks the linked list from head, zeroes each node's data, deallocates every node, then resets count, head and tail.
// @fnv 0x00a1c2d0
// src: GUESS 0x00a1c2d0 (confidence: medium)
void FUN_00a1c2d0_shell::ClearLinkedNodes()
{
    FUN_00a1c2d0_node* cur = head;
    while (cur) {
        FUN_00a1c2d0_node* pNode = cur;
        cur = cur->next;
        pNode->data = 0;
        {
            void* p = pNode;
            g_memoryManager.Deallocate(p);
        }
    }
    count = 0;
    head = 0;
    tail = 0;
}
}  // namespace fnv_00a1c2d0

void* __cdecl FUN_00ec7230(void*, const void*, unsigned int);
struct FUN_00a1c400_elem { char b[32]; };
struct FUN_00a1c400_shell {
    void CopyElements(FUN_00a1c400_elem* apDestAddr, FUN_00a1c400_elem* apSrcAddr, unsigned int aiCount);
};
// Copies aiCount elements from apSrcAddr to apDestAddr, iterating forward or backward depending on their relative order.
// @fnv 0x00a1c400
void FUN_00a1c400_shell::CopyElements(FUN_00a1c400_elem* apDestAddr, FUN_00a1c400_elem* apSrcAddr, unsigned int aiCount)
{
    if (aiCount <= 0)
        return;
    if (apDestAddr < apSrcAddr) {
        for (unsigned int i = 0; i < aiCount; ++i)
            FUN_00ec7230(&apDestAddr[i], &apSrcAddr[i], sizeof(FUN_00a1c400_elem));
    } else if (apDestAddr > apSrcAddr) {
        for (int i = aiCount - 1; i >= 0; --i)
            FUN_00ec7230(&apDestAddr[i], &apSrcAddr[i], sizeof(FUN_00a1c400_elem));
    }
}

template <class T> class FontPointerList {
public:
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    FontPointerList() { m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    ~FontPointerList();
};

struct TextItem;

struct FUN_00a19f70_t {
    void WrapLine(void* apSource, unsigned int auiStart);
};

struct FUN_00a1bd40 {
    FontPointerList<TextItem*> kItemList;
    unsigned int uiNumItems;
    unsigned int uiStart;
    unsigned int uiEnd;
    unsigned int uiLength;
    unsigned int uiFlags;
    unsigned int uiFontNum;
    unsigned int uiMaxWidth;
    unsigned int uiLineNum;
    void* pOwner;
    FUN_00a1bd40(void* apOwner, void* apSource, unsigned int auiFlags, unsigned int auiMaxWidth);
};

// @fnv 0x00a1bd40
FUN_00a1bd40::FUN_00a1bd40(void* apOwner, void* apSource, unsigned int auiFlags, unsigned int auiMaxWidth) {
    uiNumItems = 0;
    uiFontNum = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(apSource) + 0x18);
    uiMaxWidth = auiMaxWidth;
    pOwner = apOwner;
    uiStart = 0;
    uiEnd = 0;
    uiLength = 0;
    uiFlags = auiFlags;
    reinterpret_cast<FUN_00a19f70_t*>(this)->WrapLine(apSource, 0);
}

namespace fnv_00a1c340 {
struct FUN_00a1c400_elem;
struct FUN_00a1c400_shell {
    void CopyElements(FUN_00a1c400_elem*, FUN_00a1c400_elem*, unsigned int);
};

struct FUN_00a1c340_shell {
    virtual void v0() = 0;
    virtual void* Allocate(unsigned int size) = 0;
    virtual void Free(void* p) = 0;
    virtual void* Reallocate(void* p, unsigned int size) = 0;

    void* pBuffer; // +0x04
    unsigned int iSize; // +0x08
    unsigned int SimpleArrayStorage; // +0x0c

    void ResizeBuffer(unsigned int aiNewSize, unsigned int aiCopyCount);
};

// @fnv 0x00a1c340
void FUN_00a1c340_shell::ResizeBuffer(unsigned int aiNewSize, unsigned int aiCopyCount)
{
    void* pnewBuffer;
    void* pUnused1;
    void* p2;

    if (pBuffer)
    {
        if (aiCopyCount == SimpleArrayStorage)
        {
            pBuffer = Reallocate(pBuffer, aiNewSize);
        }
        else
        {
            pnewBuffer = Allocate(aiNewSize);
            ((FUN_00a1c400_shell*)this)->CopyElements((FUN_00a1c400_elem*)pnewBuffer, (FUN_00a1c400_elem*)pBuffer, aiCopyCount);
            Free(pBuffer);
            pBuffer = 0;
            pBuffer = pnewBuffer;
        }
    }
    else
    {
        pBuffer = Allocate(aiNewSize);
        SimpleArrayStorage = aiNewSize;
    }
}
}  // namespace fnv_00a1c340

namespace fnv_00a121e0 {

struct MM {
    void _DeallocateAlias(void*);
};
extern MM _g_memoryManager;

extern void* DAT_011f33fc;
extern int DAT_011f3400;

struct Member_44 {
    void Reset();
    ~Member_44() {
        Reset();
    }
};

// Font has opaque arrays instead of these nontrivial member subobjects.
struct FontDestruction {
    void* field_0;
    void* field_4;
    void* field_8;
    GO field_C[8];
    char pad_2C[0x10];
    BSStringT<char> field_3C;
    Member_44 field_44;

    FontDestruction();
    ~FontDestruction();
};

// @fnv 0x00a121e0
FontDestruction::~FontDestruction()
{
    void* pBuffer;
    void* pData = DAT_011f33fc;
    void* apFonts[8];
    _g_memoryManager._DeallocateAlias(pData);
    DAT_011f3400 = 0;
    DAT_011f33fc = 0;
    ((Font*)this)->ClearArray();
    pBuffer = field_4;
    _g_memoryManager._DeallocateAlias(pBuffer);
}
}  // namespace fnv_00a121e0

class BSShaderAccumulator;
class BSShaderProperty;
class NiProperty;
class NiShadeProperty;
struct NiStream;
class NiTexture;
class NiUpdateData;
namespace fnv_00a14a20 {
struct CloningProcess;
struct TileShaderProperty_00a14a20;
struct blob16 { char b[16]; };
struct FUN_00a14a20_shell : public Font {
    NiTriShape* CreateTextShape(int, void*, bool);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct P03MM { void* Allocate(unsigned int); };
extern P03MM g_memoryManager;
void* NiMalloc(unsigned int);
void __cdecl AttachFaceGenAnimationData(NiAVObject*);


struct AttachWrap {
    void AttachProperty(NiObject* p) {
        int a, b, c, d, e;
        ((NiAVObject*)this)->AttachProperty(p);
    }
};

// Unit-local view of TileShaderProperty for 0x00a14a20 (namespace fnv_00a14a20): built on the shared TileShaderProperty, that code does not compile or does not match.
struct TileShaderProperty_00a14a20 {
    static void* operator new(unsigned int n) { return BSFadeNode::operator new(n); }
    char pad[0xb0];
    TileShaderProperty_00a14a20(bool);
    void SetTextureImage(NiTexture*);
};
namespace L {

struct GeomPtr { NiGeometryData* m_pObject; operator NiGeometryData*() const { return m_pObject; } NiGeometryData* operator->() const { return m_pObject; } };

struct FontPoint3 {
    float x, y, z;
    FontPoint3() {}
    static void* operator new[](unsigned int n) { return g_memoryManager.Allocate(n); }
};
struct TexMap { char pad[8]; NiTexture* m_pkTexture; NiTexture* GetTexture() { return m_pkTexture; } };
struct TexProp {
    char pad[0x20];
    TexMap** m_pBase;
    TexMap* GetAt(unsigned int i) const { return m_pBase[i]; }
    NiTexture* GetBaseTexture() {
        TexMap* pMap = GetAt(0);
        if (pMap) return pMap->GetTexture();
        else return 0;
    }
};
struct TexPtr { TexProp* m_pObject; operator TexProp*() const { return m_pObject; } };
// Shared NiTriShape lacks the 13-argument constructor used at this call site.
struct FUN_00c5cf30 : NiAVObject {
    char pad[0x1c];
    GeomPtr m_spGeometryData;
    NiGeometryData* GetModelData() const { return m_spGeometryData; }
    char pad2[0x18];
    FUN_00c5cf30(unsigned short, FontPoint3*, FontPoint3*, NiColorA*, NiPoint2*, unsigned short, int,
        unsigned short, unsigned short*, int, int, int, int);
};
}

// Builds a NiTriShape with vertex, texture and index buffers, attaches a TileShaderProperty_00a14a20, copies the color, and optionally prepares the object.
// @fnv 0x00a14a20
NiTriShape* FUN_00a14a20_shell::CreateTextShape(int aiChars, void* axColor, bool abPrepareObject)
{
    unsigned short* pvert_order;
    TileShaderProperty_00a14a20* ptsp;
    L::FontPoint3* pvertices;
    L::FUN_00c5cf30* pshape;
    int iverts;
    NiPoint2* ptextures;
    NiGeometryData* pd;

    iverts = aiChars * 4;
    pvertices = new L::FontPoint3[iverts];
    ptextures = new NiPoint2[iverts];
    pvert_order = (unsigned short*)NiMalloc(aiChars * 6 * sizeof(unsigned short));
    pshape = new L::FUN_00c5cf30(iverts, pvertices, 0, 0, ptextures, 1, 0, aiChars * 2, pvert_order, 0, 0, 0, 0);
    pd = pshape->GetModelData();
    pd->m_ucKeepFlags = 0;
    pd->m_ucCompressFlags = 1;
    pshape->SetName(NiFixedString("Interface: Text"));
    pshape->GetModelData()->SetDataConsistency(0x4000);
    ptsp = new TileShaderProperty_00a14a20(false);
    ((AttachWrap*)pshape)->AttachProperty((NiObject*)ptsp);
    *(NiColorA*)((char*)ptsp + 0x68) = *(const NiColorA*)axColor;
    if (abPrepareObject)
        BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject*)pshape, false, false);
    ptsp->SetTextureImage(((L::TexProp*)((L::TexPtr*)((char*)this + 0xc))[0])->GetBaseTexture());
    pshape->UpdateSceneObject();
    AttachFaceGenAnimationData((::NiAVObject*)pshape);
    return (NiTriShape*)pshape;
}
}  // namespace fnv_00a14a20

// Maps a character to a flag value: 0x20 for NUL, 1 for '<'/'{', 2 for '>'/'}', 8 for quotes, 0x10 for '=', 4 for chars <= 0x20, else 0.
// @fnv 0x00a16da0
int FontManager::GetCharType(char acChar)
{
    switch (acChar)
    {
    case 0:
        return 0x20;
    case '<':
    case '{':
        return 1;
    case '>':
    case '}':
        return 2;
    case '\"':
    case '\'':
        return 8;
    case '=':
        return 0x10;
    default:
        if (acChar <= 0x20)
            return 4;
        return 0;
    }
}

namespace fnv_00a19c00 {
struct P03MM { void* Allocate(unsigned int); };
extern P03MM _g_memoryManager;

struct FUN_00a1bd40 {
    char m_data[0x30];
    FUN_00a1bd40(void*, void*, unsigned int, unsigned int);
    static __forceinline void* operator new(unsigned int s) { return _g_memoryManager.Allocate(s); }
    static void operator delete(void*);
};
struct FUN_00a1be10 {
    char m_data[0x44];
    FUN_00a1be10(void*, void*, unsigned int, unsigned int);
    static __forceinline void* operator new(unsigned int s) { return _g_memoryManager.Allocate(s); }
    static void operator delete(void*);
};
struct FUN_00a19f70_t { void* WrapLine(void*, unsigned int); };
struct FUN_00ae8bf0_t {
    void* m_pFirstNode;
    void* m_pTail;
    void AddItem(const void* item)
    {
        void* pNode = m_pFirstNode;
        void* pPrev = m_pTail;
        void* pItem = (void*)item;
        void* pNext = 0;
        if (pNode) pNode = pPrev;
        if (pItem) pNext = pNode;
        m_pTail = pNext;
        if (pNext == item) AddItem(pPrev);
    }
};

struct SStr {
    char* pString;
    __forceinline char* Get() { return pString; }
    __forceinline const char& At(unsigned int i) { return pString[pString ? i : 0]; }
};
struct SItem {
    int m_iType;
    unsigned char cChar;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    SStr kText;
    __forceinline bool TextEmpty() { return !(kText.Get() && kText.At(0)); }
};
struct FontTextureInfo { unsigned int uiTextureID; char acFileName[32]; };
typedef FontManager SFontMgr;

__forceinline SFontMgr* FontMgrInstance() { return (SFontMgr*)FontManager::pInstance; }

struct SNode {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    int m_14;
    unsigned int unk18;
    int m_1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    void* m_2c;
};
struct SHolder {
    int m_iWordAt00; int m_iWordAt04; void* m_8;
    __forceinline void*& GetP8() { return m_8; }
};
struct SBox {
    void* vtbl;
    SHolder* m_iWordAt04;
    void* m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_counts[8];
    void* m_40;
    __forceinline void* GetM8() { return m_8; }
    SBox* ProcessEntries_00a19c00(SItem* pItem, int aiIndex);
};

// @fnv 0x00a19c00
// src: GUESS 0x00a19c00 (confidence: low)
SBox* SBox::ProcessEntries_00a19c00(SItem* pItem, int aiIndex)
{
    int iOffset;
    {
    SNode* pNew = 0;
    iOffset = 0;
    while (aiIndex > 1) {
        iOffset += m_1c;
        --aiIndex;
    }
    if (GetM8() && aiIndex == 0) {
        pNew = (SNode*)((FUN_00a19f70_t*)m_iWordAt04->GetP8())->WrapLine(pItem, 0);
    } else {
        pNew = (SNode*)new FUN_00a1bd40(this, pItem, iOffset, m_14);
        aiIndex = 0;
    }
    if (pItem && pItem->TextEmpty()) {
        FontCharacterInfo* pLetter = &((FontCharacterInfo*)FontMgrInstance()->GetFont(pItem->m_iType)->pFontData->pFontLetters)[pItem->cChar];
        m_1c = (int)FontMgrInstance()->GetFont(pItem->m_iType)->pFontData->fBaseLine + (int)(pLetter->m_fGlyphExtent - pLetter->m_fVerticalOffset);
    }
    if (pNew) {
        SBox* pRet = this;
        if (m_10 + pNew->m_14 + pNew->m_1c > m_18) {
            pNew->m_1c = 0;
            pRet = (SBox*)new FUN_00a1be10(m_40, pNew, m_14, m_18);
            pRet->m_10 = pNew->m_14;
            pNew->m_2c = pRet;
        } else {
            ((FUN_00ae8bf0_t*)this)->AddItem(&pNew);
            m_10 += pNew->m_14 + pNew->m_1c;
        }
        if (pItem->TextEmpty())
            pRet->m_counts[pItem->m_iType]++;
        if (pRet != this)
            return pRet;
    } else if (pItem && pItem->TextEmpty()) {
        m_counts[pItem->m_iType]++;
    }
    return 0;
    }
}
}  // namespace fnv_00a19c00

namespace fnv_00a1b020 {
extern "C" double __cdecl fmod(double, double);

void __cdecl NormalizeSmartQuotes(unsigned char*);
unsigned int __cdecl _strlen(const char*);
extern double gModifierZero;
extern double DAT_010731a8;
extern FontPoint3 NiPoint3_ZERO;

const float TAB_WIDTH = 75.0f;

// The shared return type has a nontrivial copy constructor; this path needs a trivial 12-byte return.
struct FontDimensions : public FontManager {
    FontPoint3 GetStringDimensions(const char* strText, int aiFont, float afWrapwidth, int aiStartIndex);
};

// Measures wrapped text for a font: accumulates per-glyph widths, breaks lines at wrap points, and returns max line width, total height and line count.
// @fnv 0x00a1b020
FontPoint3 FontDimensions::GetStringDimensions(const char* strText, int aiFont, float afWrapwidth, int aiStartIndex)
{
    float fprevLetterWidth;
    int inumLines;
    bool bsoftHyphen;
    FontPoint3 returnDims;
    float fwrapPointWidth;
    float fcurrLineWidth;
    int uistrLength;
    FontCharacterInfo* plettersA;
    float flinePadding;

    if (aiFont < 1 || aiFont > 8 || strText == 0)
        return NiPoint3_ZERO;

    returnDims = NiPoint3_ZERO;
    uistrLength = _strlen(strText);
    plettersA = (FontCharacterInfo*)(*(char**)((char*)pFont[aiFont - 1] + 0x38) + 0x128);
    fwrapPointWidth = 0;
    fcurrLineWidth = 0;
    flinePadding = GetFontPadding(aiFont);
    fprevLetterWidth = 0;
    bsoftHyphen = false;
    inumLines = 1;
    returnDims.y = *(float*)((char*)plettersA + 0x728);
    for (int iletterCt = aiStartIndex; iletterCt < uistrLength; iletterCt++) {
        unsigned char cletter = strText[iletterCt];
        float fcurrLetterWidth = 0;
        NormalizeSmartQuotes(&cletter);
        fcurrLetterWidth = plettersA[cletter].m_fHorizontalAdvance + plettersA[cletter].m_fGlyphWidthInPixels + plettersA[cletter].m_fHorizontalSpacing;
        switch (cletter) {
        case '\n':
        case ' ':
            fwrapPointWidth = fcurrLineWidth;
            bsoftHyphen = false;
            break;
        case '~':
            fwrapPointWidth = fcurrLineWidth + plettersA['-'].m_fHorizontalAdvance + plettersA['-'].m_fGlyphWidthInPixels + plettersA['-'].m_fHorizontalSpacing;
            bsoftHyphen = true;
            break;
        case '\t':
            fcurrLetterWidth = DAT_010731a8 - (float)fmod((double)fcurrLineWidth, (double)TAB_WIDTH);
            break;
        }
        if (cletter != '~' || cletter == '\n')
            fcurrLineWidth += fcurrLetterWidth;
        if (fcurrLineWidth > afWrapwidth || cletter == '\n') {
            if (fwrapPointWidth > gModifierZero) {
                fcurrLineWidth -= fwrapPointWidth;
                if (!bsoftHyphen) {
                    if (cletter == '\n')
                        fcurrLineWidth = 0;
                    else
                        fcurrLineWidth -= plettersA[' '].m_fHorizontalAdvance + plettersA[' '].m_fGlyphWidthInPixels + plettersA[' '].m_fHorizontalSpacing;
                }
            } else {
                fwrapPointWidth = fcurrLineWidth - fcurrLetterWidth - fprevLetterWidth + plettersA['-'].m_fHorizontalAdvance + plettersA['-'].m_fGlyphWidthInPixels + plettersA['-'].m_fHorizontalSpacing;
                fcurrLineWidth = fcurrLetterWidth + fprevLetterWidth;
            }
            returnDims.x = returnDims.x > fwrapPointWidth ? returnDims.x : fwrapPointWidth;
            returnDims.y = flinePadding + **(float**)((char*)pFont[aiFont - 1] + 0x38) + returnDims.y;
            fwrapPointWidth = 0;
            inumLines++;
        }
        fprevLetterWidth = fcurrLetterWidth;
    }
    returnDims.x = returnDims.x > fcurrLineWidth ? returnDims.x : fcurrLineWidth;
    returnDims.z = (float)inumLines;
    return returnDims;
}
}  // namespace fnv_00a1b020

struct FUN_00a14170_out {
    float fX;
    float fY;
    float fZ;
    float fW;
};

struct FUN_00a14170_shell {
    int unk00;
    int unk04;
    int iType;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    float fValue2C;
    void GetGlyphMetricsByName(FUN_00a14170_out* apOut, const char* apName);
};

// @fnv 0x00a14170
// src: GUESS 0x00a14170 (confidence: medium)
void FUN_00a14170_shell::GetGlyphMetricsByName(FUN_00a14170_out* apOut, const char* apName) {
    apOut->fX = 60.0f;
    apOut->fZ = fValue2C;
    if (apName[0] == 'a' || apName[0] == 'b' || apName[0] == 'x' || apName[0] == 'y') {
        apOut->fY = -15.0f;
        apOut->fW = -30.0f;
    } else if ((apName[0] == 'l' || apName[0] == 'r') && (apName[1] == 's' || apName[1] == 't')) {
        apOut->fY = -12.5f;
        apOut->fW = -25.0f;
    } else {
        apOut->fY = -10.0f;
        apOut->fW = -20.0f;
    }
    switch (iType) {
    case 1:
        apOut->fY -= 2.5;
        apOut->fZ -= 3.0;
        apOut->fW -= 5.0;
        break;
    case 7:
        apOut->fY += 2.5;
        apOut->fZ -= 10.0;
        apOut->fW -= 5.0;
        break;
    }
}

struct FUN_004037f0_target {
    void FUN_004037f0(char* text, int flag);
};

struct FUN_00a16700_cls {
    int unk00;
    void SplitAndProcessToken(char* text, FUN_004037f0_target* target, int maxCount, char delim);
};

// @fnv 0x00a16700
void FUN_00a16700_cls::SplitAndProcessToken(char* text, FUN_004037f0_target* target, int maxCount, char delim) {
    unsigned int pad[8];
    char* last = text;
    int count = 0;
    int i6 = 0;
    while (text[i6] != 0 && count != maxCount) {
        if (text[i6] == delim) {
            last = text + i6;
            count = count + 1;
        }
        i6 = i6 + 1;
    }
    while (text[i6] != 0 && text[i6] != delim) {
        i6 = i6 + 1;
    }
    text[i6] = 0;
    target->FUN_004037f0(last, 0);
    text[i6] = delim;
}

struct FUN_00a18ff0_node {
    FUN_00a18ff0_node* next;
    int unk04;
    int value;
};

struct FUN_00a18ff0_cls {
    FUN_00a18ff0_node* head;
    int unk04;
    void* m_08;
    int unk0c;
    int unk10;
    unsigned int m_14;
    int GetValueAtCount();
};

// Walks the linked list from head for m_14 steps and returns the node's value, or 0 if m_08 is null or the list ends early.
// @fnv 0x00a18ff0
int FUN_00a18ff0_cls::GetValueAtCount() {
    unsigned int count;
    FUN_00a18ff0_node* cur;
    void* first4;
    FUN_00a18ff0_node* h4;
    first4 = m_08;
    if (first4 != 0) {
        count = m_14;
        h4 = head;
        cur = h4;
        while (cur != 0 && count-- != 0) {
            int* p3 = &cur->value;
            cur = cur->next;
        }
        if (cur != 0) {
            return cur->value;
        }
    }
    return 0;
}

extern float DAT_01095268;
extern float DAT_01095264;
extern float DAT_01095260;

struct FUN_00a1b770_vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct FUN_00a1b770_sub
{
    unsigned int unk00;
    void Init(int a, int b);
};

struct FUN_00a1b770_scratch
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

struct FUN_00a1b770_scratch2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
};

struct FUN_00a1b770_cls
{
    unsigned int m_u00;
    unsigned int unk04;
    FUN_00a1b770_vec4 m_v08;
    unsigned int m_u18;
    FUN_00a1b770_sub m_s1c;

    void FontManager_CharData_SetChar(int size);
    void InitializeCharacterData();
};

// Initialises the object: zeroes m_u00, sets m_v08 from three globals with w=1, sets m_u18 to 1, inits m_s1c and calls FUN_00a1b7f0(0x20).
// @fnv 0x00a1b770
// src: GUESS 0x00a1b770 (confidence: medium)
void FUN_00a1b770_cls::InitializeCharacterData()
{
    FUN_00a1b770_vec4 vec;
    FUN_00a1b770_scratch scratch;
    FUN_00a1b770_scratch2 scratch2;
    m_u00 = 0;
    vec.x = DAT_01095268;
    vec.y = DAT_01095264;
    vec.z = DAT_01095260;
    vec.w = 1.0f;
    m_v08 = vec;
    m_u18 = 1;
    FUN_00a1b770_sub* sub = &m_s1c;
    sub->Init(0, 0);
    FontManager_CharData_SetChar(0x20);
}

unsigned int __cdecl strlen(const char*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
extern MemoryManager g_memoryManager;
extern __declspec(thread) int g_tlsMode;

inline void CopyFont(char* dst, unsigned int size, const char* file) { strcpy_s(dst, size, file); }
struct FontTexSlot {
    int* p;
    FontTexSlot();
    ~FontTexSlot();
};
// local form of BSStringT<char>: 0x00a12020 needs the inline zeroing ctor and out-of-line destructor; shared replacement changes bytes.
struct FontStr {
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    static unsigned short Clamp(unsigned int n) { return n <= 0xffff ? (unsigned short)n : 0xffff; }
    FontStr() {
        pString = 0;
        sLen = Clamp(0);
        sMaxLen = Clamp(0);
    }
    ~FontStr();
};
struct FontIconArray {
    virtual ~FontIconArray();
    virtual void* Allocate(unsigned int);
    void* buffer;
    unsigned int size;
    unsigned int capacity;
    FontIconArray() { unsigned int count = 0; buffer = 0; size = 0; capacity = 0; if (count < size) count = size; if (count > capacity) { buffer = Allocate(count); capacity = count; } }
};
struct TlsModeGuard {
    int saved;
    static int GetMode() { return g_tlsMode; }
    static void SetMode(int mode) { g_tlsMode = mode; }
    TlsModeGuard() {
        saved = GetMode();
        SetMode(12);
    }
    ~TlsModeGuard() {
        SetMode(saved);
    }
};

// Font's opaque byte arrays cannot provide the original member constructors and
// exception cleanup for texture slots, the atlas string and the icon array.
struct FontConstruction {
    unsigned short iRefCount;
    char* pFontFile;
    int iFontNum;
    FontTexSlot m_kTextureSlots[8];
    float fFontHeight;
    float fMaxDrop;
    int _unverified_iLineOverlap;
    int pFontData;
    FontStr iconName;
    FontIconArray icons;
    FontConstruction(int fontNum, const char* file, bool load);
    void Load();
};

// @fnv 0x00a12020
FontConstruction::FontConstruction(int fontNum, const char* file, bool load)
{
    TlsModeGuard guard;
    pFontFile = 0;
    iRefCount = 0;
    pFontData = 0;
    if (file) {
        unsigned int len = strlen(file);
        if (len) {
            char* pBuffer = (char*)g_memoryManager.Allocate(len + 1);
            pFontFile = pBuffer;
            CopyFont(pFontFile, len + 1, file);
        }
        iFontNum = fontNum;
        if (load)
            Load();
    }
}

struct GQPoint3 {
    float x;
    float y;
    float z;

    GQPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

struct GQGeometryData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    GQPoint3* m_pkVertex;
    int unk24;
    int unk28;
    NiPoint2* m_pkTexture;

    GQPoint3* GetVertices() { return m_pkVertex; }
    NiPoint2* GetTextures() { return m_pkTexture; }
    unsigned short* GetTriangleList();
    unsigned short* GetTriangle(unsigned int uiIndex) { return GetTriangleList() + uiIndex; }
};


struct GQGlyph {
    int unk00;
    float fU0;
    float fV0;
    float fU1;
    float fV1;
    float fU2;
    float fV2;
    float fU3;
    float fV3;
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    float m_fGlyphMetric;
    float m_fHorizontalSpacing;
    float fTop;
};

struct GQFont {
    void BuildGlyphQuad(GQGlyph* apGlyph, unsigned int auiIndex, NiGeometry* apGeom, GQPoint3* apPos, int aiUnused);
};

// @fnv 0x00a142d0
void GQFont::BuildGlyphQuad(GQGlyph* apGlyph, unsigned int auiIndex, NiGeometry* apGeom, GQPoint3* apPos, int aiUnused)
{
    apPos->x += apGlyph->m_fGlyphMetric;
    unsigned int uiVert = auiIndex * 4;

    GQPoint3* pVerts3 = ((GQGeometryData*)apGeom->GetModelData())->GetVertices() + uiVert;
    pVerts3[0] = GQPoint3(apPos->x, apPos->y, apPos->z + apGlyph->fTop);
    pVerts3[1] = GQPoint3(apPos->x, apPos->y, apPos->z + apGlyph->fTop - apGlyph->m_fGlyphExtent);
    pVerts3[2] = GQPoint3(apPos->x + apGlyph->m_fGlyphWidthInPixels, apPos->y, apPos->z + apGlyph->fTop);
    pVerts3[3] = GQPoint3(apPos->x + apGlyph->m_fGlyphWidthInPixels, apPos->y, apPos->z + apGlyph->fTop - apGlyph->m_fGlyphExtent);

    NiPoint2* pUVsA = ((GQGeometryData*)apGeom->GetModelData())->GetTextures() + uiVert;
    pUVsA[0] = NiPoint2(apGlyph->fU0, apGlyph->fV0);
    pUVsA[1] = NiPoint2(apGlyph->fU2, apGlyph->fV2);
    pUVsA[2] = NiPoint2(apGlyph->fU1, apGlyph->fV1);
    pUVsA[3] = NiPoint2(apGlyph->fU3, apGlyph->fV3);

    unsigned short* pTris = ((GQGeometryData*)apGeom->GetModelData())->GetTriangle(auiIndex * 6);
    pTris[0] = uiVert;
    pTris[1] = uiVert + 1;
    pTris[2] = uiVert + 2;
    pTris[3] = uiVert + 2;
    pTris[4] = uiVert + 1;
    pTris[5] = uiVert + 3;

    apPos->x += apGlyph->m_fGlyphWidthInPixels + ((apGlyph->m_fGlyphWidthInPixels > 0.0) ? apGlyph->m_fHorizontalSpacing : 0.0f);
}

struct AtlasVertex { float x,y,z;AtlasVertex() {} static void* operator new[](unsigned n) { return g_memoryManager.Allocate(n); } };
struct AtlasData {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 bool keep;bool dynamic;
 void FUN_00a67050(unsigned);
};
struct AtlasColor { float r,g,b,a; };
extern AtlasColor DAT_011a9be0;
struct AtlasShader : NiMemObjectAllocation_font {
 virtual void Unknown0();
 virtual void Unknown1();
 virtual void Unknown2();
 virtual void Unknown3();
 virtual void Unknown4();
 virtual void Unknown5();
 virtual void Unknown6();
 virtual void Unknown7();
 virtual void Unknown8();
 virtual void Unknown9();
 virtual void Unknown10();
 virtual void Unknown11();
 virtual void Unknown12();
 virtual void Unknown13();
 virtual void Unknown14();
 virtual void Unknown15();
 virtual void Unknown16();
 virtual void Unknown17();
 virtual void Unknown18();
 virtual void Unknown19();
 virtual void Unknown20();
 virtual void Unknown21();
 virtual void Unknown22();
 virtual void Unknown23();
 virtual void Unknown24();
 virtual void Unknown25();
 virtual void Unknown26();
 virtual void Unknown27();
 virtual void Unknown28();
 virtual void Unknown29();
 virtual void Unknown30();
 virtual void Unknown31();
 virtual void Unknown32();
 virtual void Unknown33();
 virtual void Unknown34();
 virtual int GetPropertyType();
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 AtlasColor color;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 unsigned unkac;
 AtlasShader(bool);void SetTileTexture(void*);
};
struct AtlasPropertyPointer { AtlasShader* pointer;AtlasPropertyPointer(AtlasShader*);~AtlasPropertyPointer();AtlasPropertyPointer& FUN_006e5cc0(const AtlasPropertyPointer&); };
struct AtlasPropertyNode { AtlasPropertyNode* next;AtlasPropertyNode* previous;AtlasPropertyPointer value; };
struct AtlasPoolLock {void BSSpinLock_Lock(bool);void BSSpinLock_Unlock();};
extern AtlasPoolLock DAT_011c5f80;
extern AtlasPropertyNode* DAT_011c5f58;
void NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();
struct AtlasNodeAllocator { unsigned count;AtlasPropertyNode* Allocate() { DAT_011c5f80.BSSpinLock_Lock(false);if(!DAT_011c5f58)NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();AtlasPropertyNode* node=DAT_011c5f58;DAT_011c5f58=DAT_011c5f58->next;node->value.pointer=0;node->next=0;node->previous=0;DAT_011c5f80.BSSpinLock_Unlock();return node;} };
struct AtlasPropertyList { AtlasPropertyNode* head;AtlasPropertyNode* tail;AtlasNodeAllocator allocator;
 AtlasPropertyNode* NewNode(){return allocator.Allocate();}
 void NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(AtlasPropertyNode*);
// src: XBOX_PDB 0x00439fd0
 void NiAVObject_AttachProperty_00439fd0(const AtlasPropertyPointer& property) {AtlasPropertyNode* node=NewNode();node->value.FUN_006e5cc0(property);NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(node);}
};
struct AtlasGeometry : NiMemObjectAllocation_font {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 AtlasPropertyList properties;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 unsigned unka0;
 unsigned unka4;
 unsigned unka8;
 unsigned unkac;
 unsigned unkb0;
 unsigned unkb4;
 AtlasData* data;
 unsigned unkbc;
 unsigned unkc0;
 unsigned unkc4;
 unsigned unkc8;
 unsigned unkcc;
 unsigned unkd0;
 AtlasGeometry(unsigned short,AtlasVertex*,unsigned,void*,NiPoint2*,unsigned,unsigned,unsigned short,unsigned short*,void*,void*,void*,void*);
 AtlasData* GetData() { AtlasData* result=data;return result; }
 void AssignFixedString(const NiFixedString&);
// src: XBOX_PDB 0x00439410
 void NiAVObject_AttachProperty(AtlasShader* shader) { if(shader->GetPropertyType()<7) { AtlasPropertyPointer property(shader);properties.NiAVObject_AttachProperty_00439fd0(property); } }
 void UpdateProperties();
};
void* _NiMalloc_00aa1070(unsigned);
void FUN_00b57e30(AtlasGeometry*,unsigned,unsigned);
void FUN_00ec8d5f(char*,unsigned,const char*,unsigned);
int BSsprintf(char*,unsigned,const char*,...);
extern char sheetGeometryName[];
extern unsigned DAT_011a9598;
void* FUN_00a5fd70(const NiFixedString&,unsigned&,bool,bool);
void AttachFaceGenAnimationData(AtlasGeometry*);
inline void CopyAtlasPath(char* dest,const char* source,unsigned limit) { FUN_00ec8d5f(dest,limit+1,source,limit); }
// Font has no atlas accessors with these declarations.
struct FontAtlasAccess : Font {
 unsigned GetCount() { return ((FontButtonIconArray*)ButtonIcons)->iSize; }
 const char* GetTextureResourceName() { return *(const char**)IconAtlasTextureName; }
};
// @fnv 0x00a14da0
// src: COMMUNITY 0x00a14da0
PageMeshes::Shape* Font::MakeButton() {
 unsigned vertices7=((FontAtlasAccess*)this)->GetCount()*4;
 AtlasVertex* positions=new AtlasVertex[vertices7];
 NiPoint2* uvs5=new NiPoint2[vertices7];
 unsigned short* indicesVal=(unsigned short*)_NiMalloc_00aa1070(((FontAtlasAccess*)this)->GetCount()*6*sizeof(unsigned short));
 AtlasGeometry* geometry_=new AtlasGeometry((unsigned short)vertices7,positions,0,0,uvs5,1,0,(unsigned short)(((FontAtlasAccess*)this)->GetCount()*2), indicesVal,0,0,0,0);
 AtlasData* dataB=geometry_->GetData();
 dataB->keep=false;
 dataB->dynamic=true;
 geometry_->AssignFixedString(NiFixedString((const char*)sheetGeometryName));
 geometry_->GetData()->FUN_00a67050(0x4000);
 AtlasShader* shader3=new AtlasShader(false);
 geometry_->NiAVObject_AttachProperty(shader3);
 shader3->color=DAT_011a9be0;
 FUN_00b57e30(geometry_,0,0);
 char sourceName7[260];
 CopyAtlasPath(sourceName7,((FontAtlasAccess*)this)->GetTextureResourceName(),259);
 char texturePath[260];
 BSsprintf(texturePath,260,"Data\\Textures\\%s",sourceName7);
 shader3->SetTileTexture(FUN_00a5fd70(NiFixedString((const char*)texturePath),DAT_011a9598,true,false));
 geometry_->UpdateProperties();
 AttachFaceGenAnimationData(geometry_);
 return (PageMeshes::Shape*)geometry_;}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct ThreadState {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
int unk12c;
int unk130;
int unk134;
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
int unk260;
int unk264;
int unk268;
int unk26c;
int unk270;
int unk274;
int unk278;
int unk27c;
int unk280;
int unk284;
int unk288;
int unk28c;
int unk290;
int unk294;
int unk298;
int unk29c;
int unk2a0;
int unk2a4;
int unk2a8;
int unk2ac;
int unk2b0;
unsigned int context; };
extern __declspec(thread) ThreadState gThread;
inline unsigned int GetContext() { return gThread.context; }
inline void SetContext(unsigned int v) { gThread.context=v; }
struct ContextScope { unsigned int old; ContextScope(unsigned int v) { old=GetContext(); SetContext(v); } ~ContextScope() { SetContext(old); } };
struct LoaderFile {
virtual ~LoaderFile();
virtual void V04()=0; virtual void V08()=0; virtual void V0c()=0; virtual void V10()=0; virtual void V14()=0; virtual void V18()=0; virtual void V1c()=0; virtual void V20()=0; virtual void V24()=0;
virtual unsigned int Size()=0;
unsigned int position;
unsigned int (__cdecl *reader)(LoaderFile*,void*,unsigned int,unsigned int*,unsigned int);
int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; bool good;
bool IsGood() { return good; }
unsigned int Read(void* dst,unsigned int size) { unsigned int one3=1; unsigned int count3=reader(this,dst,size,&one3,1); position+=count3; unsigned int result3=count3; return result3; }
};
struct FileFinder { static LoaderFile* GetFile(const char*,int,unsigned int,unsigned int); };
inline void Close(LoaderFile* f) { delete f; }
extern void __cdecl FNV_Warning(const char*,...);
extern int __cdecl _sprintf_s(char*,unsigned int,const char*,...);

struct Glyph { int texture; float u0,v0,u1,v1,u2,v2,u3,v3; float width,height,leading,spacing,top; };
struct GlyphData {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
Glyph letters[256]; };

struct TexName { int id; char name[32]; };
struct Names { int unk00; int count; TexName textures[8]; };
struct PixelFormat { int value; }; extern PixelFormat DAT_011aa2a0;
struct PixelData {
int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
unsigned char* pixels; int unk54; int unk58; unsigned int* offsets; unsigned int levels; int unk64; int unk68; int unk6c; bool changed;
PixelData(unsigned int,unsigned int,const PixelFormat&,unsigned int,unsigned int);
static void* __cdecl operator new(unsigned int);
static void __cdecl operator delete(void*);
__forceinline unsigned char* GetPixels(unsigned int level=0,unsigned int face=0) { return pixels+face*offsets[levels]+offsets[level]; }
};
struct Preferences { int layout; int alpha; int mip; };
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
inline long DecrementRef(long volatile* value) { return InterlockedDecrement(value); }
inline long IncrementRef(long volatile* value) { return InterlockedIncrement(value); }
struct TextureMap { int unk00; int unk04; int unk08; int unk0c; TextureMap(); void SetFilter(int); };
struct TextureMaps { int unk00; int unk04; int unk08; int unk0c; int unk10; TextureMap*& At(unsigned int); void SetAt(unsigned int,TextureMap*&); };
struct Texture { virtual void V00(); virtual void Destroy(); long unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; TextureMaps maps;
Texture(PixelData*,const NiFixedString&,const Preferences&);
static void* __cdecl operator new(unsigned int); static void __cdecl operator delete(void*);
void FUN_0060aeb0(int mode) { TextureMap* map=maps.At(0); if(!map) { TextureMap* created=new TextureMap; map=created; maps.SetAt(0,map); } map->SetFilter(mode); } void Release() { if(DecrementRef(&unk04)==0) Destroy(); } long Retain() { return IncrementRef(&unk04); }
};
struct TexturePtr { Texture* value; TexturePtr& operator=(Texture* incoming) { if(value!=incoming) { if(value) value->Release(); value=incoming; if(value) value->Retain(); } return *this; } };
inline float FontMax(float a,float b) { return b>a?b:a; }
inline float FontMin(float a,float b) { return a<b?a:b; }
inline void* FontData::operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
// These accessors preserve the loader's out-of-line calls; Font has no equivalents.
struct FontLoaderAccess : Font {
    unsigned short RefCount() { return iRefCount; }
    const char* Path() { return pFontFile; }
};
// Loads the font file and its textures, computes glyph height/drop metrics, fills FontData, and increments the loader's ref count.
// @fnv 0x00a15320
void Font::LoadFont() {
ContextScope scope(12);
float maxHeight;
    { LoaderFile* file; float swap;
    { char filename[256];
    {
int letter5;
float extent;
int index3;
PixelData* pixels5;
Texture* texture5;
LoaderFile* kTextureFile;
Preferences prefs4;
unsigned int dimensions2[2];
if(((FontLoaderAccess*)this)->RefCount()==0 && pFontFile) {
file=FileFinder::GetFile(pFontFile,0,0x4000,2);
if(!file || !file->IsGood()) { FNV_Warning("DEFAULT: Font file not found: %s. \n",((FontLoaderAccess*)this)->Path()); if(file) delete file; return; }
pFontData=new FontData;
file->Read(pFontData,file->Size()); delete file; file=0;
fFontHeight=0.0f; maxHeight=0.0f; fMaxDrop=0.0f;
for(letter5=0;letter5<256;letter5++) {
extent=pFontData->fBaseLine-((GlyphData*)pFontData)->letters[letter5].spacing;
extent+=((GlyphData*)pFontData)->letters[letter5].width;
fFontHeight=FontMax(extent,fFontHeight);
maxHeight=FontMax(((GlyphData*)pFontData)->letters[letter5].width,maxHeight);
fMaxDrop=FontMin(fMaxDrop,((GlyphData*)pFontData)->letters[letter5].spacing-((GlyphData*)pFontData)->letters[letter5].width);
}
swap=pFontData->pFontLetters[32].fWidth; pFontData->pFontLetters[32].fWidth=pFontData->pFontLetters[32].fSpacing; pFontData->pFontLetters[32].fSpacing=swap;
pFontData->pFontLetters[32].fHeight=maxHeight; pFontData->pFontLetters[32].fTopEdge=fMaxDrop+maxHeight;
pFontData->pFontLetters[160].fWidth=pFontData->pFontLetters[32].fWidth; pFontData->pFontLetters[160].fSpacing=pFontData->pFontLetters[32].fSpacing; pFontData->pFontLetters[160].fHeight=pFontData->pFontLetters[32].fHeight; pFontData->pFontLetters[160].fTopEdge=pFontData->pFontLetters[32].fTopEdge;
pFontData->pFontLetters[127].fWidth=pFontData->pFontLetters[124].fWidth; pFontData->pFontLetters[127].fLeadingEdge=pFontData->pFontLetters[124].fLeadingEdge; pFontData->pFontLetters[127].fSpacing=pFontData->pFontLetters[124].fSpacing; pFontData->pFontLetters[127].fHeight=pFontData->pFontLetters[124].fHeight; pFontData->pFontLetters[127].fTopEdge=pFontData->pFontLetters[124].fTopEdge;
pFontData->pFontLetters[0].fWidth=0.0f; pFontData->pFontLetters[0].fSpacing=0.0f; pFontData->pFontLetters[0].fHeight=maxHeight; pFontData->pFontLetters[0].fTopEdge=fMaxDrop+maxHeight;
pFontData->pFontLetters[0].pMapping[0].fU=0.0f; pFontData->pFontLetters[0].pMapping[1].fU=0.0f; pFontData->pFontLetters[0].pMapping[2].fU=0.0f; pFontData->pFontLetters[0].pMapping[3].fU=0.0f;
pFontData->pFontLetters[0].pMapping[0].fV=0.0f; pFontData->pFontLetters[0].pMapping[1].fV=0.0f; pFontData->pFontLetters[0].pMapping[2].fV=0.0f; pFontData->pFontLetters[0].pMapping[3].fV=0.0f;
if(pFontData->iTextureCount>8) { FNV_Warning("TEXTURES: Too many font textures for %s.\nMax textures is %d yours has %d.\n",((FontLoaderAccess*)this)->Path(),8,pFontData->iTextureCount); return; }
for(index3=0;index3<pFontData->iTextureCount;index3++) {
_sprintf_s(filename,256,"TEXTURES\\FONTS\\%s.TEX",((Names*)pFontData)->textures[index3].name);
kTextureFile=FileFinder::GetFile(filename,0,0x4000,2);
if(!kTextureFile || !kTextureFile->IsGood()) { FNV_Warning("DEFAULT: Font file not found: %S. \n",filename); if(kTextureFile) delete kTextureFile; return; }
kTextureFile->Read(dimensions2,8);
prefs4.layout=6; prefs4.alpha=3; prefs4.mip=2;
pixels5=new PixelData(dimensions2[0],dimensions2[1],DAT_011aa2a0,1,1);
kTextureFile->Read(pixels5->GetPixels(),dimensions2[0]*dimensions2[1]*4);
pixels5->changed=true;
texture5=new Texture(pixels5,NiFixedString(((FontLoaderAccess*)this)->Path()),prefs4);
delete kTextureFile; kTextureFile=0; texture5->FUN_0060aeb0(1); ((TexturePtr*)pTextureData)[index3]=texture5;
}
}
    }
    }
    }
++iRefCount;}

namespace fnv_00a19f70 {
struct LayoutMemory { void Deallocate(void*); };
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
void* LayoutCopy(void*,const void*,unsigned int);
// local form of BSStringT<char>: 0x00a19f70 needs inline ctor/Set/destruction; the shared split changes bytes.
struct LayoutString {
    char* text; unsigned short length, capacity;
    LayoutString() { text=0; SetLength(0); SetMaxLength(0); }
    LayoutString& operator=(const char* source) { Set(source,0); return *this; }
    ~LayoutString() { Set(0,0); }
    unsigned int MaxLength() const { return capacity; }
    void SetMaxLength(unsigned int n) { capacity=n<=0xffff?(unsigned short)n:0xffff; }
    void SetLength(unsigned int n) { length=n<=0xffff?(unsigned short)n:0xffff; }
    bool Set(const char* source, unsigned int minimum) {
        unsigned int size=source?LayoutLength(source):0;
        unsigned int maximum=LayoutCapacity(size,minimum);
        if(maximum<=MaxLength()) {
            if(maximum) { if(source) LayoutCopy(text,source,size+1); else text[0]=0; }
            else {
                if(text) { char* old=text; operator delete(old); }
                text=0; maximum=0; SetMaxLength(maximum);
            }
        } else {
            char* old=text;
            void* allocated=operator new(maximum+1);
            text=(char*)allocated;
            if(source) LayoutCopy(text,source,size+1); else text[0]=0;
            if(old) { char* discarded=old; operator delete(discarded); }
            SetMaxLength(maximum);
        }
        SetLength(size);
        return size!=0;
    }
    char& operator[](unsigned int index) const { return text[text ? index : 0]; }
    char* Get() const { return text; }
    bool Empty() const { return !Get() || !(*this)[0]; }
};
struct LayoutColor { float r,g,b,a; LayoutColor() : r(0),g(0),b(0),a(0) {} LayoutColor(const float& x,const float& y,const float& z,float w) : r(x),g(y),b(z),a(w) {} };
struct LayoutItem {
    int font; unsigned char character; unsigned char unk05; unsigned short unk06;
    LayoutColor color; int unk18;
    LayoutString string;
    int width,height,depth,offset,position;
    LayoutItem(int fontIndex, int value, LayoutColor newColor, int flags) {
        int limited=fontIndex<8?fontIndex:8;
        font=limited<0?0:limited;
        character=(unsigned char)value;
        color=newColor;
        unk18=flags;
        string=0;
        FontManager* manager=FontManager::pInstance;
        Font* selected=manager->pFont[font];
        FontCharacterInfo* letter=&((FontCharacterInfo*)(selected->pFontData)->pFontLetters)[character];
        width=(int)(letter->m_fGlyphWidthInPixels+letter->m_fGlyphWidthInPixels>0.0?letter->m_fHorizontalAdvance+letter->m_fHorizontalSpacing:0.0);
        FontManager* manager2=FontManager::pInstance;
        Font* selected2=manager2->pFont[font];
        height=(int)(selected2->pFontData)->fBaseLine;
        depth=(int)(letter->m_fGlyphExtent-letter->m_fVerticalOffset);
        offset=0;
        position=0;
    }
// src: COMMUNITY 0x00a1b7f0
    void FontManager_CharData_SetChar(unsigned char value) {
        character=value;
        if(!string.Get() || !string[0]) {
            FontManager* manager=FontManager::pInstance;
            Font* selected=manager->pFont[font];

            FontCharacterInfo* letter=&((FontCharacterInfo*)(selected->pFontData)->pFontLetters)[character];
            width=(int)(letter->m_fGlyphWidthInPixels+(letter->m_fGlyphWidthInPixels>0.0?letter->m_fHorizontalSpacing+letter->m_fHorizontalAdvance:0.0));
            FontManager* manager2=FontManager::pInstance; Font* selected2=manager2->pFont[font];
            height=(int)(selected2->pFontData)->fBaseLine;
            FontManager* manager3=FontManager::pInstance; Font* selected3=manager3->pFont[font];
            float drop=selected3->fMaxDrop; depth=(int)-drop;
            offset=0;
        }
        position=0;
    }
    bool Empty() const { return !string.Get() || !string[0]; }
    ~LayoutItem() {}
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
};
struct LayoutNode { LayoutNode* next; LayoutNode* prev; LayoutItem* item; };
unsigned int LayoutCurrentThread();
long LayoutCompareExchange(volatile long*,long,long);
void LayoutYield(unsigned long);
void LayoutMemoryBarrier();
struct LayoutPoolLock {
    unsigned int owner, recursion;
    void Lock(const char*) {
        unsigned int thread=LayoutCurrentThread();
        if(owner==thread) ++recursion;
        else {
            unsigned int spins=0;
            while(LayoutCompareExchange((volatile long*)&owner,thread,0)) {
                ++spins;
                if(spins>10000) LayoutYield(1); else LayoutYield(0);
            }
            LayoutMemoryBarrier();
            recursion=1;
        }
    }
    void Unlock();
};
extern LayoutPoolLock LayoutNodeLock;
extern LayoutNode* LayoutNodeFreeList;
void LayoutRefillNodes();
struct LayoutOwner { int unk00,unk04,unk08,width; };
extern int LayoutFontHeights[];
struct LayoutLine {
    LayoutNode* head; LayoutNode* tail; int count,width,unk10,height,depth,unk1c,unk20,maxWidth,unk28;
    LayoutOwner* owner;
    LayoutLine(LayoutOwner*,LayoutItem*,int,int);
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
    LayoutItem* RemoveTail() {
        LayoutItem* value=0;
        LayoutNode* node=tail;
        if(node) {
            value=node->item;
            tail=node->prev;
            if(tail) tail->next=0; else head=0;
            --count;
            ((LayoutMemory*)&g_memoryManager)->Deallocate(node);
        }
        return value;
    }
    int Count() const { return count; }
    LayoutNode* Tail() const { return tail; }
    LayoutNode* Head() const { return head; }
    LayoutItem*& Previous(LayoutNode*& node) const { LayoutItem** item=&node->item; node=node->prev; return *item; }
    LayoutItem*& Next(LayoutNode*& node) const { LayoutItem** item=&node->item; node=node->next; return *item; }
    LayoutItem* First() const { LayoutItem* item=0; if(Count()) item=head->item; return item; }
    LayoutItem* Last() const { LayoutItem* item=0; if(Count()) item=tail->item; return item; }
    LayoutNode* AllocateNode() {
        LayoutNodeLock.Lock(0);
        if(!LayoutNodeFreeList) LayoutRefillNodes();
        LayoutNode* node=LayoutNodeFreeList;
        LayoutNodeFreeList=LayoutNodeFreeList->next;
        node->item=0; node->next=0; node->prev=0;
        LayoutNodeLock.Unlock();
        return node;
    }
// src: COMMUNITY 0x00a0c9f0
    void _NiTListBase_AddHead(LayoutItem* const& value) {
        LayoutNode* node=AllocateNode(); node->item=value; node->prev=0; node->next=head;
        if(head) head->prev=node; else tail=node;
        head=node; ++count;
    }
    void LinkTail(LayoutNode* node) {
        node->next=0; node->prev=tail;
        if(tail) tail->next=node; else head=node;
        tail=node; ++count;
    }
    void AddItem(LayoutItem* const& value) { LayoutNode* node=AllocateNode(); node->item=value; LinkTail(node); }
    LayoutLine* WrapLine(LayoutItem* source, bool start);
};
inline int LayoutMax(int a,int b) { return a>b?a:b; }
// @fnv 0x00a19f70
LayoutLine* LayoutLine::WrapLine(LayoutItem* apItem, bool start) {
    LayoutLine* first6=0;
    if(width+apItem->width>maxWidth) {
        if(apItem->character!=0x20) {
            LayoutNode* b=Tail();
            while(b && b->item->character!=0x20) Previous(b);
            if(b) {
                first6=new LayoutLine(owner,apItem,0,maxWidth);
                first6->height=LayoutFontHeights[apItem->font];
                LayoutItem* last4=RemoveTail();
                while(Count() && last4->character!=0x20) {
                    first6->WrapLine(last4,true);
                    last4=RemoveTail();
                    width-=last4->width;
                }
                if(last4) delete last4;
            } else {
                first6=new LayoutLine(owner,apItem,0,maxWidth);
                first6->height=LayoutFontHeights[apItem->font];
                LayoutItem* result2=new LayoutItem(0,0x2d,LayoutColor(DAT_01095268,DAT_01095264,DAT_01095260,1.0f),1);
                long c=0;
                LayoutItem* last4=0;
                while(Count() && width-c+result2->width>maxWidth) {
                    last4=RemoveTail();
                    first6->WrapLine(last4,true);
                    c+=last4->width;
                }
                width-=c;
                WrapLine(result2,false);
            }
        } else {
            apItem->FontManager_CharData_SetChar(0);
            first6=new LayoutLine(owner,apItem,0,maxWidth);
            first6->height=LayoutFontHeights[apItem->font];
        }
    } else {
        if(apItem->Empty()) {
            bool node=false;
            if(!Count()) height=LayoutFontHeights[apItem->font];
            if(start) {
                LayoutItem* changed2=0;
                if(Count()) changed2=head->item;
                if(changed2 && apItem->font!=changed2->font) node=true;
                apItem->position=apItem->offset;
                width=apItem->width;
                LayoutNode* b;
                b = Head();
                while(b) {
                    LayoutItem* last4=Next(b);
                    last4->position=width+last4->offset;
                    width+=last4->width;
                }
            } else {
                LayoutItem* removed=0;
                if(Count()) removed=tail->item;
                if(removed && apItem->font!=removed->font) node=true;
                apItem->position=width+apItem->offset;
                width+=apItem->width;
            }
            if(node) height=LayoutMax(height,apItem->height);
            depth=LayoutMax(depth,apItem->depth);
        } else {
            if(start) {
                apItem->position=0;
                width=apItem->width;
                LayoutNode* b;
                b = Head();
                while(b) {
                    LayoutItem* last4=Next(b);
                    last4->position=width+last4->offset;
                    width+=last4->width;
                }
            } else {
                apItem->position=width;
                width+=apItem->width;
            }
            height=LayoutMax(height,apItem->height);
            depth=LayoutMax(depth,apItem->depth);
        }
        if(start) _NiTListBase_AddHead(apItem); else AddItem(apItem);
        owner->width=LayoutMax(owner->width,width);
    }
    return first6;
}
}  // namespace fnv_00a19f70

namespace fnv_00a1aee0 {
struct IconRect {
    float left, right, top, bottom;
    IconRect() { left = 0.0f; right = 0.0f; top = 0.0f; bottom = 0.0f; }
};
struct IconData {
    float width, m_fVerticalExtent, zOffset, spacing;
    IconRect uv;
};
struct IconSetting {
    void* vtable;
    const char* value;
    const char* Get() { return this ? value : 0; }
};
extern IconSetting g_011f3368;
void __cdecl Tile_GetTextureAtlasInfo(const char*, const char*, BSStringT<char>*, IconRect*);
void* operator new(unsigned int, void* address) { return address; }
struct IconArray {
    void** vtable;
    IconData* data;
    unsigned int size, capacity;
    unsigned int FUN_00a1c130();
    void ConstructElements(IconData* first, unsigned int count) {
        for (unsigned int i = 0; i < count; ++i) { IconData* element = new (first + i) IconData; }
    }
    void Append(const IconData& icon) {
        unsigned int index = FUN_00a1c130();
        ConstructElements(data + index, 1);
        data[index] = icon;
    }
};
struct FUN_00a1aee0_shell : Font {
    void GetGlyphMetricsByName(IconData*, const char*);
    void LoadIconFromPath(const char* path);
};
// Parses the icon suffix from the path after the last underscore, builds an IconData via FUN_00a06dd0 and FUN_00a14170, then appends it to the icon array.
// @fnv 0x00a1aee0
void FUN_00a1aee0_shell::LoadIconFromPath(const char* path) {
    IconData icon6;
    Tile_GetTextureAtlasInfo(g_011f3368.Get(), path, (BSStringT<char>*)IconAtlasTextureName, &icon6.uv);
    int offset = strlen(path) - 1;
    int count7 = 0;
    while (path[offset] != '_') --offset;
    char suffix[4];
    for (count7 = 0; count7 < 3 && path[offset + count7 + 1] != '.'; ++count7) {
        suffix[count7] = path[offset + count7 + 1];
    }
    suffix[count7] = 0;
    GetGlyphMetricsByName(&icon6, suffix);
    reinterpret_cast<IconArray*>(&ButtonIcons)->Append(icon6);
}
}  // namespace fnv_00a1aee0



inline unsigned short FontTextClampLength(unsigned int auiLength)
{
    return auiLength <= 0xFFFF ? (unsigned short)auiLength : 0xFFFF;
}

// local form of BSStringT<char>: 0x00a1b660 needs its inline ctor/assignment and out-of-line destructor; shared replacement changes bytes.
struct FontTextString
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    FontTextString()
    {
        pString = 0;
        sLen = FontTextClampLength(0);
        sMaxLen = FontTextClampLength(0);
    }
    ~FontTextString();
    bool Set(const char* apString, unsigned int auiLength);
    bool Set(const FontTextString& src);
    FontTextString& operator=(const FontTextString& src) { Set(src); return *this; }
    FontTextString& Clear() { Set(0, 0); return *this; }
};

template <class T> inline T FontTextMin(T a, T b) { return a < b ? a : b; }
template <class T> inline T FontTextMax(T a, T b) { return a < b ? b : a; }

struct FontTextManager
{
    Font* pFont[8];
    static FontTextManager* pInstance;
    static FontTextManager* Instance()
    {
        FontTextManager* manager = pInstance;
        return manager;
    }
    Font* GetFont(int i) { return pFont[i]; }
};

struct FontTextParams
{
    int m_iType;
    bool bFlag;
    NiColorA kColor;
    int iAlignment;
    FontTextString kText;
    int iLineHeight;
    int iHeight;
    int m_iDrop;
    int unk30;
    int unk34;

    FontTextParams(int aiFont, bool abFlag, NiColorA akColor, int aiAlignment)
    {
        m_iType = FontTextMax(FontTextMin(aiFont, 8), 0);
        bFlag = abFlag;
        kColor = akColor;
        iAlignment = aiAlignment;
        kText.Clear();
        FontCharacterInfo* pLetter = &((FontCharacterInfo*)FontTextManager::Instance()->GetFont(m_iType)->pFontData->pFontLetters)[bFlag];
        float width = pLetter->m_fGlyphWidthInPixels;
        float doubledWidth = width + width;
        float leading = pLetter->m_fHorizontalAdvance;
        float spacing = pLetter->m_fHorizontalSpacing;
        iLineHeight = (int)(doubledWidth != 0.0 ? leading + spacing : 0.0);
        FontTextManager* heightManager = FontTextManager::Instance();
        Font* heightFont = heightManager->GetFont(m_iType);
        FontData* heightData = heightFont->pFontData;
        float lineHeight = heightData->fBaseLine;
        iHeight = (int)lineHeight;
        float glyphHeight = pLetter->m_fGlyphExtent;
        float topEdge = pLetter->m_fVerticalOffset;
        float drop = glyphHeight - topEdge;
        m_iDrop = (int)drop;
        unk30 = 0;
        unk34 = 0;
    }
    // end ctor
    static __forceinline void* operator new(unsigned int s) { return g_memoryManager.Allocate(s); }
    static __forceinline void operator delete(void*) {}

    FontTextParams* Clone();
};

// Allocates a copy of this FontTextParams, copies the text and metrics, resets unk30 to 0 and returns the new object.
// @fnv 0x00a1b660
FontTextParams* FontTextParams::Clone()
{
    FontTextParams* pCopy = new FontTextParams(m_iType, bFlag, kColor, iAlignment);
    pCopy->kText = kText;
    pCopy->iLineHeight = iLineHeight;
    pCopy->iHeight = iHeight;
    pCopy->m_iDrop = m_iDrop;
    pCopy->unk34 = unk34;
    pCopy->unk30 = 0;
    return pCopy;
}

struct S_00a12300_Arr {
    int unk00;
    int count;
};

struct S_00a12300_Elem {
    int unk00;
    void FUN_0066b0d0(int a);
};

struct S_00a12300_Glob {
    int unk00;
    void MemoryManager_Deallocate(S_00a12300_Arr* p);
};

extern S_00a12300_Glob DAT_011f6238;

struct S_00a12300_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    S_00a12300_Arr* m_aiIndexedValues;
    void ClearArray();
};

// @fnv 0x00a12300
void S_00a12300_Obj::ClearArray() {
    int unusedOne;
    int unusedTwo;
    int index;
    int array;

    for (unusedOne = 0; m_aiIndexedValues != 0 && unusedOne < m_aiIndexedValues->count; unusedOne++) {
        ((S_00a12300_Elem*)((char*)this + 0xc + unusedOne * 4))->FUN_0066b0d0(0);
    }

    index = (int)m_aiIndexedValues;
    DAT_011f6238.MemoryManager_Deallocate((S_00a12300_Arr*)index);
    m_aiIndexedValues = 0;
}

namespace fnv_00a16ea0 {
extern "C" char DAT_011f6238;

struct SStr {
    char* pString;
    unsigned short iLen;
    unsigned short sMaxLen;
    SStr(unsigned int n = 0) {
        pString = 0;
        iLen = (unsigned short)(n <= 0xFFFF ? (unsigned short)n : 0xFFFF);
        sMaxLen = (unsigned short)(n <= 0xFFFF ? (unsigned short)n : 0xFFFF);
    }
    SStr(const SStr&);
    SStr& operator+=(const char*);
    void AssignFromString(const SStr&);
    bool Set(const char*, unsigned int);
    ~SStr() { Set(0, 0); }
};

struct Hole { int a[42]; };
inline void Pad168() { Hole hole; (void)&hole; }

struct MM { void* Game_DoHeapAlloc(unsigned int); void MemoryManager_Deallocate(void*); };

struct TexNode { void LoadIconFromPath(char*); };

struct FontC {
    TexNode* m_apNode[8];
    int GetCharType(char);
    TexNode* GetNode(unsigned i) { return m_apNode[i]; }
    SStr Font_CollectTo(const char* text, int* pos, unsigned mask, unsigned mask2,
                      int* value, char* pch, bool flag);
};

void __cdecl Warning_005b5e40(int, const char*, int);
void __cdecl FUN_00ec8d5f(char*, int, const char*, int);
void __cdecl Interface_FindTextReplacementString(char*, char*, int, int);
void __cdecl FUN_00ec61c0(void*, int, unsigned int);
void __cdecl FUN_00ec7c66(char*, int, const char*, int);

inline void CopyName(char* d, int sz, const char* s, int n) { FUN_00ec8d5f(d, sz, s, n); }

// Scans text from *pos until a stop character or mask match, expanding '&...;' settings into _buf, and returns the accumulated SStr.
// @fnv 0x00a16ea0
// src: EXE 0x00a16ea0
SStr FontC::Font_CollectTo(const char* text, int* apiPos, unsigned mask, unsigned mask2,
                         int* apiValue, char* apCh, bool abExpandSettings)
{
    SStr str3;
    char _buf[0x800];
    int count2 = 0;
    int other7 = 0;
    FUN_00ec61c0(_buf, 0, 0x800);
    while (true) {
        *apCh = text[*apiPos];
        int r6 = this->GetCharType((unsigned char)*apCh);
        if (r6 & 0x20) {
            *apiValue = 0x20;
            break;
        } else if (r6 & mask) {
            *apiValue = r6;
            (*apiPos)++;
            break;
        } else if (mask2 != 0 && (r6 & mask2) == 0) {
            *apCh = text[*apiPos];
            *apiValue = this->GetCharType((unsigned char)*apCh);
            break;
        } else if (*apCh == '\n' || *apCh == '\r') {
            (*apiPos)++;
            continue;
        } else if (abExpandSettings) {
            if (text[*apiPos] == '&') {
                int n5 = 1;
                while (!this->GetCharType((unsigned char)text[*apiPos + n5]) &&
                       text[*apiPos + n5 - 1] != ';')
                    n5++;
                if (text[*apiPos + n5 - 1] != ';') {
                    Warning_005b5e40(0x12, "Font::CollectTo() -- Found GameSetting w/o ending ; in HTML text.", 0);
                } else {
                    int iLen;
                    void* lenB = ((MM*)&DAT_011f6238)->Game_DoHeapAlloc(n5 + 1);
                    char* p2 = (char*)lenB;
                    CopyName(p2, n5 + 1, &text[*apiPos], n5);
                    p2[n5] = 0;
                    char kNamebuf[0x104];
                    kNamebuf[0] = 0;
                    Interface_FindTextReplacementString(p2, kNamebuf, 0x104, 0);
                    if (kNamebuf[0] == '\\') {
                        kNamebuf[strlen(kNamebuf) - 1] = 0;
                        GetNode(0)->LoadIconFromPath(&kNamebuf[1]);
                        _buf[count2] = 1;
                        count2++;
                    } else if (kNamebuf[0] != 0) {
                        iLen = (int)strlen(kNamebuf);
                        FUN_00ec7c66(&_buf[count2], iLen, kNamebuf, iLen);
                        count2 += iLen;
                    } else if (n5 != 0) {
                        FUN_00ec7c66(&_buf[count2], n5, p2, n5);
                        count2 += n5;
                    }
                    *apiPos = n5 + *apiPos - 1;
                    void* aTmp = p2;
                    ((MM*)&DAT_011f6238)->MemoryManager_Deallocate(aTmp);
                }
            } else {
                _buf[count2] = text[*apiPos];
                count2++;
                if (count2 > 0x7d0) {
                    str3 += _buf;
                    count2 = 0;
                }
            }
        }
        (*apiPos)++;
    }
    Pad168();
    str3 += _buf;
    return str3;
}
}  // namespace fnv_00a16ea0

namespace fnv_00a18a30 {
extern "C" char DAT_011f6238;
extern "C" float DAT_01095260, DAT_01095264, DAT_01095268;

void __cdecl NormalizeSmartQuotes(unsigned char& character);

}

// local form of BSStringT<char>: 0x00a18a30 needs POD lifetime and its inline length/accessor split; shared replacement changes bytes.
struct SStr {
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    char* GetString() { return pString; }
    unsigned int GetLen() { return sLen == 0xffff ? (unsigned int)strlen(GetString()) : (unsigned int)sLen; }
    bool Set(const char*, unsigned int);
    bool Set(const SStr&);
};

struct Info_ {
    int m_iType;
    int iHeight;
    NiColorA color;
    char cBreak;
    int iStart;
    int iEnd;
    int iLeading;
    int iUnused;
    int oFirst;
    int oLast;
    char bFlag;
    SStr str;
    int GetFont() { return m_iType; }
    int GetHeight() { return iHeight; }
    NiColorA GetColor() { return color; }
    int GetStart() { return iStart; }
    int GetEnd() { return iEnd; }
    int GetLeading() { return iLeading; }
};

namespace fnv_00a18a30 {
struct Pool { void* Game_DoHeapAlloc(unsigned int); };

inline void SetName(Info_* info, SStr* src) {
    SStr* p = &info->str;
    p->Set(*src);
}


struct ColA {
    float r, g, b, a;
    ColA() { r = DAT_01095268; g = DAT_01095264; b = DAT_01095260; a = 1.0f; }
};

inline int Max(int a, int b) { return a > b ? a : b; }

struct Hole38 { int a[14]; };
struct Hole20 { int a[8]; };
inline void Pad38() { Hole38 h; }
inline void Pad20() { Hole20 h; }

struct Entry {
    int v00, v04, v08, v0c, v10, v14, v18, v1c, v20;
    int GetV0c() { return v0c; }
};
// Exe 0x00a18a30: unit-local ListNode view; declarations and layout are preserved.
struct FontListNodeView { FontListNodeView* next; FontListNodeView* prev; Entry* item; };
struct ListObj {
    FontListNodeView* head;
    int f4;
    void* f8;
    int fC, f10, f14, f18, f1c;
    Entry* GetHead() { return (Entry*)head; }
    void* GetX8() { return f8; }
};

__forceinline Entry* TakeNext(FontListNodeView*& node) {
    Entry** pp = &node->item;
    node = node->next;
    return *pp;
}

struct TextRun {
    int m_iType;
    unsigned char cChar;
    NiColorA color;
    int iExtra;
    SStr str;
    int a24, a28, a2c, a30, a34;
    TextRun(int, unsigned char, ColA, int);
    void InitializeCharacterData();
    void FontManager_CharData_SetChar(unsigned char);
    TextRun* Clone(int, int);
    ~TextRun() { str.Set(0, 0); }
};

}

struct RunNodeBase { void* b0; void* b4; void* b8; RunNodeBase(); };
struct RunNode : RunNodeBase {
    int c, d, e;
    RunNode(int a, int b, int cc) : RunNodeBase() { this->c = a; this->d = b; this->e = cc; }
    static void* operator new(unsigned int n) { return ((fnv_00a18a30::Pool*)&fnv_00a18a30::DAT_011f6238)->Game_DoHeapAlloc(n); }
    fnv_00a18a30::ListObj* GetList();
    void FontManager_TextDoc_AddChar(fnv_00a18a30::TextRun*);
    void* GetB8() { return b8; }
};

// Builds a RunNode for the given text and Info_, splitting text into TextRuns by break char and updating the Info_ start/end/first/last fields.
// @fnv 0x00a18a30
RunNode* FontData::CreateTextRunNode(SStr* text, Info_* info) {
    using namespace fnv_00a18a30;
    if (text->GetString() == 0) return 0;
    if (info->GetStart() < 2) info->iStart = 0x7fffffff;
    if (info->GetEnd() < 2) info->iEnd = 0x7fffffff;
    RunNode* pNode = 0;
    pNode = ParseLayout(text, info);
    if (pNode) return pNode;
    pNode = new RunNode(info->GetStart(), info->GetEnd(), info->GetLeading());
    Pad38();
    TextRun textRun(0, ' ', ColA(), 1);
    textRun.InitializeCharacterData();
    textRun.m_iType = info->GetFont();
    textRun.color = info->GetColor();
    textRun.iExtra = info->GetHeight();
    if (text->GetLen() <= 0) text->Set(" ", 0);
    SetName(info, text);
    int w = 0;
    for (unsigned int i = 0; i < text->GetLen(); i++) {
        unsigned char c = *(text->pString + (text->pString ? i : 0));
        fnv_00a18a30::NormalizeSmartQuotes(c);
        if (c == info->cBreak) w++;
        else if (c == 9 || c >= 0x20) {
            textRun.FontManager_CharData_SetChar(c);
            pNode->FontManager_TextDoc_AddChar(textRun.Clone(w, 0));
            w = 0;
        }
    }
    Pad38();
    info->bFlag = 0;
    info->oFirst = 0;
    info->iStart = 0;
    info->iEnd = 0;
    info->oLast = 0;
    if (pNode) {
        info->oFirst = (int)pNode->GetB8();
        ListObj* list = pNode->GetList();
        if (list) {
            info->iEnd = 0;
            info->iStart = 0;
            FontListNodeView* node = (FontListNodeView*)list->GetHead();
            while (node) {
                Entry* e = TakeNext(node);
                info->iEnd += e->v14 + e->v1c;
                info->iStart = Max(info->iStart, e->v0c);
            }
            info->oLast = (int)list->GetX8();
        }
    }
    Pad20();
    return pNode;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

namespace fnv_00a12880 {
void __cdecl NormalizeSmartQuotes(unsigned char*);
extern float DAT_0102f0f8;
extern double DAT_010731a8;
double __cdecl FUN_00ec9130(double, double);
extern char DAT_01011584[];
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
inline void* LayoutCopy(void* destination,const void* source,unsigned int size) { return memcpy(destination,source,size); }
struct LayoutText {
    char* data; unsigned short length,capacity;
    void Init();
    unsigned int MaxLength() const { return capacity; }
    void SetLength(unsigned int n) { length=n<=0xffff?(unsigned short)n:0xffff; }
    void SetMaxLength(unsigned int n) { capacity=n<=0xffff?(unsigned short)n:0xffff; }
    bool Set(const char* source,unsigned int minimum) {
        unsigned int size=source?LayoutLength(source):0;
        unsigned int maximum=LayoutCapacity(size,minimum);
        if(maximum<=MaxLength()) {
            if(maximum) {
                if(source) LayoutCopy(data,source,size+1);
                else data[0]=0;
            } else {
                if(data) delete data;
                data=0; maximum=0; SetMaxLength(maximum);
            }
        } else {
            char* old=data;
            data=new char[maximum+1];
            if(source) LayoutCopy(data,source,size+1);
            else data[0]=0;
            if(old) delete old;
            SetMaxLength(maximum);
        }
        SetLength(size);
        return size!=0;
    }
    LayoutText() { Init(); }
    ~LayoutText() { Set(0,0); }
    LayoutText& operator=(const char* source) { Set(source,0); return *this; }
};
struct CharacterPosition {
    int offset; CharacterPosition* next;
    CharacterPosition() { offset=0; next=0; }
    void RemoveAll() {
        while(next) {
            CharacterPosition* following=next->next;
            next->next=0;
            delete next;
            next=following;
        }
        offset=0;
    }
    ~CharacterPosition() { RemoveAll(); }
};
struct FUN_00759330 {
    LayoutText text; int width; int height;
    int startOffset; int layoutVersion; int geometryKey; int layoutFlags;
    CharacterPosition firstPosition;
    FUN_00759330(int newWidth,int newHeight,int newCount,int newLimit,unsigned char separator) {
        text=DAT_01011584;
        width=newWidth; height=newHeight; startOffset=newCount; layoutVersion=newLimit;
        geometryKey=0; layoutFlags=separator;
    }
    ~FUN_00759330() { firstPosition.RemoveAll(); }
    int GetCharacterOffset(int index) {
        CharacterPosition* node = &firstPosition;
        int current=0;
        while(current<index && node) { node=node->next; ++current; }
        if(node) return node->offset;
        else return -1;
    }
    char& operator[](unsigned int index) { return text.data[text.data ? index : 0]; }
    int GetWidth() { return width; }
    int GetHeight() { return height; }
    int GetGeometryKey() { return geometryKey; }
};
struct GlyphData { int texture; NiPoint2 mapping[4]; float width,height,leading,spacing,top; };

struct GeometryView {
    int unk00,unk04; unsigned short vertices,id; int unk0c;
    Bound bound; int active;
    unsigned short GetVertices() { return vertices; }
    int GetActive() { int result=active; return result; }
    void FUN_00a67050(int);
};
struct ShapeView {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    FontPoint3 position6;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    GeometryView* geometry;
    void SetPosition(const FontPoint3& point) { position6=point; }
    GeometryView* GetGeometry() { return geometry; }
};
struct FinalizerView {
    virtual void* Allocate(unsigned int);
    virtual void* Reallocate(void*,unsigned int);
    virtual void Free(void*);
    ButtonIcon* buffer; unsigned int count,capacity;
    void FUN_00a1bfa0(bool release) {
        if(buffer) {
            for(unsigned int index=0; index<count; ++index) {}
            if(release) { Free(buffer); buffer=0; buffer=0; capacity=0; }
            count=0;
        }
    }
};
// Font lacks the overloads using this renderer's local parameter types.
struct FontRenderer : Font {
    bool HasNoIcons() { return ((FinalizerView*)ButtonIcons)->count==0; }
    unsigned int GetIconCount() { return ((FinalizerView*)ButtonIcons)->count; }
    void Font_CreateText(int*,int*,int*,int,int,int,char,int,ShapeView**,ShapeView**);
    void CheckForVariablesInText(int,FUN_00759330*);
    ShapeView* CreateTextShape(int,int,int);
    ShapeView* MakeButton();
    void UpdateIconGeometry(int,ShapeView*,FontPoint3&);
    void BuildGlyphQuad(GlyphData*,int,ShapeView*,FontPoint3&,int);
};
__forceinline int Maximum(int advance,int oldWidth) { return advance>oldWidth ? advance : oldWidth; }
__forceinline int SourceValue(int* source) { return *source; }
__forceinline void MarkGeometry(ShapeView* shape) { GeometryView* geometry=shape->GetGeometry(); geometry->FUN_00a67050(0x4000); }
struct InlineManager : FontManager {
    __declspec(noinline) float LinePadding(int font) {
        float padding=0.0f;
        switch(font) {
        case 3: padding=6.0f; break;
        case 7: padding=2.0f; break;
        case 2: case 6: padding=4.0f; break;
        }
        return padding;
    }
};
inline InlineManager* Manager() { return (InlineManager*)FontManager::pInstance; }
__forceinline double TabMod(const float& value) { return (float)FUN_00ec9130((double)value,(double)DAT_0102f0f8); }
__forceinline void TabAdvance(float& value) { float tabPosition=value; float tabMultiple=(float)TabMod(tabPosition); value=DAT_010731a8-tabMultiple+value; }
// @fnv 0x00a12880
// src: COMMUNITY 0x00a12880
void FontRenderer::Font_CreateText(int* source,int* width,int* height,int count,int limit,int mode,char separator,int flags,ShapeView** primary,ShapeView** secondary) {
    if(*height==0) *height=0x7fffffff;
    if(!limit) limit=0x7fffffff;
    unsigned char letter9;
    int letterCode7;
    GlyphData* glyph;
    int secondaryActive_2;
    float lineB=Manager()->LinePadding(iFontNum);
    FUN_00759330 layoutX(*width,*height,count,limit,separator);
    CheckForVariablesInText(SourceValue(source),&layoutX);
    *width=layoutX.GetWidth();
    *height=layoutX.GetHeight();
    int linePosition_2=0;
    int linePositionTmp=0;
    if(mode==4) linePositionTmp=-layoutX.GetCharacterOffset(linePosition_2);
    else if(mode==2) linePositionTmp=-(layoutX.GetCharacterOffset(linePosition_2)/2);
    FontPoint3 position6;
    position6.x=(float)linePositionTmp;
    position6.z=(pFontData->fBaseLine-fFontHeight)*2.0f;
    position6.y=0.0f;
    *primary=CreateTextShape(layoutX.GetGeometryKey(),flags,1);
    FontPoint3 kIter;
    kIter.x=0.0f; kIter.y=position6.y; kIter.z=position6.z;
    (*primary)->SetPosition(kIter);
    if(!HasNoIcons()) {
        *secondary=MakeButton();
        (*secondary)->SetPosition(kIter);
        MarkGeometry(*secondary);
    }
    float originXVal;
    originXVal = position6.x;
    int drawnCount=0;
    int specialCount_2;
    specialCount_2 = 0;
    unsigned int cur5=0;
    while(layoutX[cur5]) {
        if(layoutX[cur5]==separator) {
            ++linePosition_2;
            position6.x=0.0f;
            if(4 == mode) position6.x=(float)-layoutX.GetCharacterOffset(linePosition_2);
            else if(mode == 2) position6.x=(float)-(layoutX.GetCharacterOffset(linePosition_2)/2);
            position6.z-=pFontData->fBaseLine+lineB;
        } else if(layoutX[cur5]=='\t') {
            TabAdvance(position6.x);
        }
        letter9=layoutX[cur5];
        NormalizeSmartQuotes(&letter9);
        letterCode7=letter9;
        if(letterCode7>256) letter9=0;
        if(letter9==1) {
            if(GetIconCount()>0) {
                UpdateIconGeometry(specialCount_2++,*secondary,position6);
            }
        } else {
            glyph=&((GlyphData*)pFontData->pFontLetters)[letter9];
            BuildGlyphQuad(glyph,drawnCount,*primary,position6,flags);
            ++drawnCount;
        }
        *width=Maximum((int)(position6.x-originXVal),*width);
        ++cur5;
    }
    int res=(*primary)->GetGeometry()->GetActive();
    (*primary)->GetGeometry()->bound.ComputeBoundingSphere((*primary)->GetGeometry()->GetVertices(),(NiPoint3*)res);
    if(*secondary) {
        secondaryActive_2=(*secondary)->GetGeometry()->GetActive();
        (*secondary)->GetGeometry()->bound.ComputeBoundingSphere((*secondary)->GetGeometry()->GetVertices(),(NiPoint3*)secondaryActive_2);
    }
    ((FinalizerView*)ButtonIcons)->FUN_00a1bfa0(1);
}
}  // namespace fnv_00a12880

struct Pt3_a14650 {
    float x;
    float y;
    float z;
    Pt3_a14650(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};

inline NiGeometryData* Geo_a14650(NiTriShape* shape) { return shape->m_spModelData.m_pObject; }
inline FontPoint3* Verts_a14650(NiGeometryData* data) { return (FontPoint3*)data->m_pkVertex; }
inline NiPoint2* Tex_a14650(NiGeometryData* data) { return data->m_pkTexture; }
inline unsigned short* Tris_a14650(NiGeometryData* data) { return static_cast<NiTriShapeData*>(data)->GetTriangleList(); }

struct FontIcons_a14650 : public Font {
    ButtonIcon& Icon(int index) { return ((FontButtonIconArray*)ButtonIcons)->pBuffer[index]; }
    void UpdateIconGeometry(int index, NiTriShape* shape, FontPoint3& position);
};

// Writes vertex positions, texture coordinates, and triangle indices for a button icon into the shape's geometry data, then advances position.x.
// @fnv 0x00a14650
void FontIcons_a14650::UpdateIconGeometry(int aiIconIndex, NiTriShape* shape, FontPoint3& position)
{
    int baseVertex3 = aiIconIndex * 4;
    float width6 = ((FontButtonIconArray*)ButtonIcons)->pBuffer[aiIconIndex].m_fGlyphWidthInPixels;
    float zPos7 = position.z + ((FontButtonIconArray*)ButtonIcons)->pBuffer[aiIconIndex].m_fGlyphVerticalOffset;
    float xPos = position.x + ((FontButtonIconArray*)ButtonIcons)->pBuffer[aiIconIndex].m_fHorizontalOffset;

    Pt3_a14650* vertices5 = (Pt3_a14650*)(Verts_a14650(Geo_a14650(shape)) + baseVertex3);
    vertices5[0] = Pt3_a14650(xPos, position.y, zPos7);
    vertices5[1] = Pt3_a14650(xPos, position.y, zPos7 - width6);
    vertices5[2] = Pt3_a14650(xPos + width6, position.y, zPos7);
    vertices5[3] = Pt3_a14650(xPos + width6, position.y, zPos7 - width6);

    NiPoint2* texCoords2 = (NiPoint2*)(Tex_a14650(Geo_a14650(shape)) + baseVertex3);
    texCoords2[0] = NiPoint2(Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumV);
    texCoords2[1] = NiPoint2(Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumV);
    texCoords2[2] = NiPoint2(Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMinimumV);
    texCoords2[3] = NiPoint2(Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumU, Icon(aiIconIndex).m_kTextureCoordinates.m_fMaximumV);

    unsigned short* triangles = Tris_a14650(Geo_a14650(shape)) + aiIconIndex * 6;
    triangles[0] = (unsigned short)baseVertex3;
    triangles[1] = (unsigned short)(baseVertex3 + 1);
    triangles[2] = (unsigned short)(baseVertex3 + 2);
    triangles[3] = (unsigned short)(baseVertex3 + 2);
    triangles[4] = (unsigned short)(baseVertex3 + 1);
    triangles[5] = (unsigned short)(baseVertex3 + 3);

    position.x += width6 + ((FontButtonIconArray*)ButtonIcons)->pBuffer[aiIconIndex].m_fHorizontalSpacing;
}

namespace fnv_00a15ee0 {
inline void DeadQ1(){int a[1];}
inline void DeadQ2(){int a[2];}
inline void DeadQ3(){int a[3];}
inline void DeadQ4(){int a[4];}
inline void DeadQ5(){int a[5];}
inline void DeadQ6(){int a[6];}
inline void DeadQ7(){int a[7];}
inline void DeadQ8(){int a[8];}
inline void DeadQ9(){int a[9];}
inline void DeadQ10(){int a[10];}
inline void DeadQ11(){int a[11];}
inline void DeadQ12(){int a[12];}
inline void DeadQ13(){int a[13];}
inline void DeadQ14(){int a[14];}
inline void DeadQ15(){int a[15];}
inline void DeadQ16(){int a[16];}
inline void DeadQ17(){int a[17];}
unsigned int __cdecl strlen(const char*);
void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern MemoryManager g_memoryManager;
__forceinline char* AllocZ(unsigned int count) { unsigned int sz = 1; sz = count * sz; char* p = (char*)g_memoryManager.Allocate(sz); fnv_zlib_memset(p, 0, sz); return p; }
inline void FreeQ(char* p) { g_memoryManager.Deallocate(p); }
struct TxtQ {
    void ExtractLine(BSStringT<char>* str, int line);
};
// Copies the text of the given 1-based line from a BSStringT<char> into a new buffer, replacing the original string with that line's content.
// @fnv 0x00a15ee0
void TxtQ::ExtractLine(BSStringT<char>* str, int line)
{
    int cur = 1;
    int start3 = -1;
    int _end = -1;
    unsigned int len = str->Length();
    unsigned int i;
    for (i = 0; i < len; i++) {
        if (!FontStringCharacter(*str, i)) break;
        if (cur == line && start3 == -1) start3 = i;
        if (FontStringCharacter(*str, i) == '\n') cur++;
        if (cur == line + 1 && _end == -1) { _end = i; break; }
    }
    if (start3 == 0 && _end == -1) return;
    if (start3 == -1) { str->Set(" ", 0); return; }
    if (_end == -1) _end = len;
    unsigned int cnt4 = _end - start3;
    char* buf3 = AllocZ(cnt4 + 1);
 DeadQ16();     for (i = 0; i < cnt4; i++) buf3[i] = FontStringCharacter(*str, i + start3);
    buf3[i] = 0;
    str->Set(" ", 0);
    str->Set(buf3, 0);
    char* del = buf3; g_memoryManager.Deallocate(del);
}
}  // namespace fnv_00a15ee0

namespace fnv_00a17390 {
extern MemoryManager g_memoryManager;
struct LayoutMemory { void Deallocate(void*); };
extern float DAT_01095268;
extern float DAT_01095264;
extern float DAT_01095260;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
inline void* LayoutCopy(void* destination,const void* source,unsigned int size) { return memcpy(destination,source,size); }
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*,const char*);
extern "C" int __cdecl toupper(int);
extern "C" int __cdecl _stricmp(const char*,const char*);
int __cdecl BSstrcmp(const char*,const char*);
long __cdecl FUN_00eca6d3(const char*);
extern "C" int __cdecl sscanf(const char*,const char*,...);
extern "C" void* __cdecl fnv_zlib_memset(void*,int,unsigned int);
// local form of BSStringT<char>: 0x00a17390 needs inline ctor/Set/append operations; the shared split changes bytes.
struct LayoutString {
    char* text; unsigned short length, capacity;
    LayoutString() { text=0; SetLength(0); SetMaxLength(0); }
    LayoutString& operator=(const char* source) { Set(source,0); return *this; }
    LayoutString& operator=(const LayoutString& other) { Set(other); return *this; }
    ~LayoutString() { Set(0,0); }
    LayoutString& Clear() { Set(0,0); return *this; }
    unsigned int MaxLength() const { return capacity; }
    void SetMaxLength(unsigned int n) { capacity=n<=0xffff?(unsigned short)n:0xffff; }
    void SetLength(unsigned int n) { length=n<=0xffff?(unsigned short)n:0xffff; }
    bool Set(const char* source, unsigned int minimum) {
        unsigned int size=source?LayoutLength(source):0;
        unsigned int maximum=LayoutCapacity(size,minimum);
        if(maximum<=MaxLength()) {
            if(maximum) { if(source) LayoutCopy(text,source,size+1); else text[0]=0; }
            else {
                if(text) delete text;
                text=0; maximum=0; SetMaxLength(maximum);
            }
        } else {
            char* old=text;
            text=new char[maximum+1];
            if(source) LayoutCopy(text,source,size+1); else text[0]=0;
            if(old) delete old;
            SetMaxLength(maximum);
        }
        SetLength(size);
        return size!=0;
    }
    bool Set(const LayoutString& other) {
        unsigned int size=other.Length();
        if(size<=MaxLength()) {
            if(size) LayoutCopy(text,other.Get(),size+1);
            else {
                if(text) delete text;
                text=0; size=0; SetMaxLength(size);
            }
        } else {
            char* old=text;
            text=new char[size+1];
            LayoutCopy(text,other.Get(),size+1);
            if(old) delete old;
            SetMaxLength(size);
        }
        SetLength(size);
        return size!=0;
    }
    char& operator[](unsigned int index) const { return text[text ? index : 0]; }
    char* Get() const { return text; }
    bool Empty() const { return !Get() || !(*this)[0]; }
    unsigned int Length() const { return length==0xffff ? strlen(Get()) : length; }
    unsigned int Size() const { return Length()+1; }
    int StrCmp(const char* other, bool ignoreCase) const {
        int result;
        if(other && Get()) result=ignoreCase ? _stricmp(Get(),other) : BSstrcmp(Get(),other);
        else if(!other && !Get()) result=0;
        else result=(other==0)*2-1;
        return result;
    }
    bool operator==(const char* other) const { return !StrCmp(other,true); }
    LayoutString& operator+=(const LayoutString& other) {
        if(other.Get()) {
            if(Get()) {
                unsigned int total=Length()+other.Length();
                if(total>MaxLength()) Set(Get(),total);
                LayoutCopy(text+Length(),other.Get(),other.Size());
                SetLength(total);
            } else Set(other);
        }
        return *this;
    }
};
struct LayoutColor { float r,g,b,a; LayoutColor() : r(0),g(0),b(0),a(0) {} LayoutColor(const float& x,const float& y,const float& z,float w) : r(x),g(y),b(z),a(w) {} LayoutColor(int red,int green,int blue) : r(red/255.0),g(green/255.0),b(blue/255.0),a(1.0f) {} };
struct LayoutFont : Font {
    float GetDrop() { return fMaxDrop; }
};
struct LayoutFonts : FontManager {
    static LayoutFonts* Instance() { return (LayoutFonts*)pInstance; }
    LayoutFont* GetFont(int index) { return (LayoutFont*)pFont[index]; }
};
template<class T> inline T LayoutLower(T a,T b) { return a<b?a:b; }
template<class T> inline T LayoutUpper(T a,T b) { return a<b?b:a; }
struct LayoutItem {
    int font; unsigned char character; unsigned char unk05; unsigned short unk06;
    LayoutColor color; int unk18;
    LayoutString string;
    int width,height,depth,offset,position;
    LayoutItem(int fontIndex, unsigned char value, LayoutColor newColor, int flags) {
        font=LayoutUpper(LayoutLower(fontIndex,8),0);
        character=value;
        color=newColor;
        unk18=flags;
        string.Set(0,0);
        FontCharacterInfo* letter=&((FontCharacterInfo*)(LayoutFonts::Instance()->GetFont(font)->pFontData)->pFontLetters)[character];
        width=(int)(letter->m_fGlyphWidthInPixels+letter->m_fGlyphWidthInPixels!=0.0?letter->m_fHorizontalAdvance+letter->m_fHorizontalSpacing:0.0);
        height=(int)(LayoutFonts::Instance()->GetFont(font)->pFontData)->fBaseLine;
        depth=(int)(letter->m_fGlyphExtent-letter->m_fVerticalOffset);
        offset=0;
        position=0;
    }
// src: COMMUNITY 0x00a1b7f0
    void FontManager_CharData_SetChar(unsigned char value) {
        character=value;
        if(Empty()) {
            FontCharacterInfo* letter=&((FontCharacterInfo*)(LayoutFonts::Instance()->GetFont(font)->pFontData)->pFontLetters)[character];
            width=(int)(letter->m_fGlyphWidthInPixels+(letter->m_fGlyphWidthInPixels!=0.0?letter->m_fHorizontalSpacing+letter->m_fHorizontalAdvance:0.0));
            height=(int)(LayoutFonts::Instance()->GetFont(font)->pFontData)->fBaseLine;
            depth=(int)-LayoutFonts::Instance()->GetFont(font)->GetDrop();
            offset=0;
        }
        position=0;
    }
    void SetFont(int index) { font=index; FontManager_CharData_SetChar(character); }
    LayoutItem* Clone() {
        LayoutItem* item=new LayoutItem(font,character,color,unk18);
        item->string=string;
        item->width=width;
        item->height=height;
        item->depth=depth;
        item->position=position;
        item->offset=0;
        return item;
    }
// src: GUESS 0x00a1b770 (confidence: medium)
    void InitializeCharacterData() {
        font=0;
        color=LayoutColor(DAT_01095268,DAT_01095264,DAT_01095260,1.0f);
        unk18=1;
        string.Clear();
        FontManager_CharData_SetChar(0x20);
    }
    bool Empty() const { return !string.Get() || !string[0]; }
    ~LayoutItem() {}
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
};
struct LayoutLine { void* head; void* tail; int count,width,unk10,height,depth,unk1c; };
struct LayoutLineNode { LayoutLineNode* next; LayoutLineNode* prev; LayoutLine* line; };
struct LayoutPage {
    LayoutLineNode* head; LayoutLineNode* tail; int count;
    int Count() const { return count; }
    LayoutLineNode* Head() const { return head; }
    LayoutLine*& Next(LayoutLineNode*& node) const { LayoutLine** line=&node->line; node=node->next; return *line; }
};
struct FUN_00a1b940 {
    void* head; void* tail; int count;
    FUN_00a1b940();
    int Count() const { return count; }
};
struct LayoutBlock : FUN_00a1b940 {
    int width,height,unk14;
    LayoutBlock(int newWidth,int newHeight,int newUnk14) { width=newWidth; height=newHeight; unk14=newUnk14; }
    static void* operator new(unsigned int size) { return g_memoryManager.Allocate(size); }
    static void operator delete(void* p) { ((LayoutMemory*)&g_memoryManager)->Deallocate(p); }
    void FontManager_TextDoc_AddChar(LayoutItem*,int,bool);
    LayoutPage* GetValueAtCount();
};
struct LayoutResult {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18;
    int width,height,unk24,unk28,pages,lines;
    bool hasLayout;
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    int GetUnk24() const { return unk24; }
};
inline int LayoutMax(int a,int b) { return a>b?a:b; }
inline int LayoutMin(int a,int b) { return a<b?a:b; }
__forceinline char* AllocateText(unsigned int count) {
    unsigned int size=1;
    size*=count;
    char* text=(char*)g_memoryManager.Allocate(size);
    fnv_zlib_memset(text,0,size);
    return text;
}
// Shared FontManager lacks these parser overloads.
struct FUN_00a17390_shell : FontManager {
    Font* GetFont(unsigned int number) { return pFont[number]; }
    const char* GetFontFile(unsigned int number) { return GetFont(number)->pFontFile; }
    LayoutString Font_CollectTo(const char* input, int* index, unsigned int stopMask, unsigned int allowedMask, unsigned int* outFlags, char* currentChar, bool parseEntities);
    LayoutBlock* ParseLayout(LayoutString& source, LayoutResult* result);
};
inline ButtonIcon& GetIcon(Font* font, unsigned int index) { return ((FontButtonIconArray*)font->ButtonIcons)->pBuffer[index]; }
// Parses HTML-like markup from source into a LayoutBlock, tracking font, color, alignment, and image attributes, then updates result dimensions.
// @fnv 0x00a17390
LayoutBlock* FUN_00a17390_shell::ParseLayout(LayoutString& source, LayoutResult* result) {
    bool layout=false;
    char* input=AllocateText(source.Length()+1);
    strcpy(input,source.Get());
    int parsePos=0;
    unsigned int mask=0;
    char character=0;
    LayoutString word;
    LayoutString tagText;
    LayoutString paramName;
    LayoutString attributeValue;
    LayoutString output;
    LayoutItem format(0,' ',LayoutColor(DAT_01095268,DAT_01095264,DAT_01095260,1.0f),1);
    bool img=false;
    int lines=0;
    bool lineRule=false;
    LayoutBlock* block=0;
    unsigned int iconNum=0;
    Font_CollectTo(input,&parsePos,0,4,&mask,&character,false);
    if(mask==1) {
        block=new LayoutBlock(result->GetWidth(),result->GetHeight(),result->GetUnk24());
        layout=true;
        parsePos=0;
        while(true) {
            word=Font_CollectTo(input,&parsePos,1,0,&mask,&character,true);
            if(word.Get()) {
                if(img) {
                    img=false;
                    format.character=0;
                    block->FontManager_TextDoc_AddChar(format.Clone(),lines,lineRule);
                    lines=0;
                    lineRule=false;
                    format.string="";
                }
                output+=word;
                for(unsigned int i=0;i<word.Length();++i) {
                    format.FontManager_CharData_SetChar(word[i]);
                    if(format.character==1) {
                        format.width=(int)(GetIcon(GetFont(0),iconNum).m_fGlyphWidthInPixels+((FontButtonIconArray*)GetFont(0)->ButtonIcons)->pBuffer[iconNum].m_fHorizontalSpacing);
                        ++iconNum;
                    }
                    block->FontManager_TextDoc_AddChar(format.Clone(),lines,lineRule);
                    lines=0;
                    lineRule=false;
                }
            }
            if(mask&0x20) break;
            tagText=Font_CollectTo(input,&parsePos,6,0,&mask,&character,true);
            for(unsigned int i=0;i<tagText.Length();++i) tagText[i]=toupper(tagText[i]);
            if(mask&0x20) break;
            if(mask&4) {
                while(true) {
                    Font_CollectTo(input,&parsePos,0,4,&mask,&character,false);
                    if(mask&0x20 || mask&2) break;
                    paramName=Font_CollectTo(input,&parsePos,0x16,0,&mask,&character,true);
                    for(unsigned int i=0;i<paramName.Length();++i) paramName[i]=toupper(paramName[i]);
                    if(mask&0x20 || mask&2) break;
                    if(mask&4) attributeValue="true";
                    else {
                        Font_CollectTo(input,&parsePos,0,4,&mask,&character,false);
                        if(mask&0x20 || mask&2) break;
                        if(mask==8) {
                            ++parsePos;
                            attributeValue=Font_CollectTo(input,&parsePos,0xa,0,&mask,&character,true);
                            character=input[parsePos];
                            ++parsePos;
                            mask=GetCharType(character);
                        } else {
                            attributeValue=Font_CollectTo(input,&parsePos,6,0,&mask,&character,true);
                            for(unsigned int i=0;i<attributeValue.Length();++i) attributeValue[i]=toupper(attributeValue[i]);
                        }
                    }
                    if(tagText=="IMG") {
                        img=true;
                        if(paramName=="SRC") format.string=attributeValue;
                        else if(paramName=="WIDTH") sscanf(attributeValue.Get(),"%i",&format.width);
                        else if(paramName=="HEIGHT") { sscanf(attributeValue.Get(),"%i",&format.height); format.depth=0; }
                    } else if(img) {
                        img=false;
                        format.character=0;
                        block->FontManager_TextDoc_AddChar(format.Clone(),lines,lineRule);
                        lines=0;
                        lineRule=false;
                        format.string="";
                    }
                    if(tagText=="DIV") {
                        ++lines;
                        if(paramName=="ALIGN") {
                            if(attributeValue=="LEFT") format.unk18=1;
                            else if(attributeValue=="CENTER") format.unk18=2;
                            else if(attributeValue=="RIGHT") format.unk18=4;
                        }
                    } else if(tagText=="FONT") {
                        if(paramName=="FACE") {
                            for(int number=0;number<8;++number) {
                                bool found=false;
                                if(!_stricmp(attributeValue.Get(),GetFontFile(number))) found=true;
                                else if(number+1==FUN_00eca6d3(attributeValue.Get())) found=true;
                                if(found) {
                                    format.SetFont(number);
                                    break;
                                }
                            }
                        }
                        if(paramName=="COLOR" && attributeValue.Length()==6) {
                            LayoutColor color;
                            int r=(toupper(attributeValue[0])>='A'?toupper(attributeValue[0])-('A'-10):toupper(attributeValue[0])-'0')<<4;
                            r+=toupper(attributeValue[1])>='A'?toupper(attributeValue[1])-('A'-10):toupper(attributeValue[1])-'0';
                            r=LayoutMin(LayoutMax(r,0),255);
                            int g=(toupper(attributeValue[2])>='A'?toupper(attributeValue[2])-('A'-10):toupper(attributeValue[2])-'0')<<4;
                            g+=toupper(attributeValue[3])>='A'?toupper(attributeValue[3])-('A'-10):toupper(attributeValue[3])-'0';
                            g=LayoutMin(LayoutMax(g,0),255);
                            int b=(toupper(attributeValue[4])>='A'?toupper(attributeValue[4])-('A'-10):toupper(attributeValue[4])-'0')<<4;
                            b+=toupper(attributeValue[5])>='A'?toupper(attributeValue[5])-('A'-10):toupper(attributeValue[5])-'0';
                            b=LayoutMin(LayoutMax(b,0),255);
                            color=LayoutColor(r,g,b);
                            format.color=color;
                        }
                    }
                    if(mask&0x20 || mask&2) break;
                }
            }
            if(tagText=="BR") ++lines;
            else if(tagText=="P") lines+=2;
            else if(tagText=="HR") {
                if(result->height==0x7fffffff) lines+=2;
                else { lineRule=true; lines=0; }
            } else if(tagText=="/FONT") format.InitializeCharacterData();
        }
        source=output;
    }
    ((LayoutMemory*)&g_memoryManager)->Deallocate(input);
    if(block) {
        result->hasLayout=true;
        result->pages=block->Count();
        LayoutPage* page=block->GetValueAtCount();
        if(page) {
            result->height=0;
            result->width=0;
            LayoutLineNode* node=page->Head();
            while(node) {
                LayoutLine* line=page->Next(node);
                result->height+=line->height+line->unk1c;
                result->width=LayoutMax(result->width,line->width);
            }
            result->lines=page->Count();
        }
    }
    return block;
}
}  // namespace fnv_00a17390

namespace fnv_00a18f00 {
struct PoolQ { void MemoryManager_Deallocate(void* p); };
extern PoolQ DAT_011f6238;
struct StrQ {
  char* p; unsigned short l, m;
  StrQ(const StrQ& o) { AssignFromString(o); }
  void AssignFromString(const StrQ& o);
  void FUN_004037f0(const char* s, unsigned short n);
  ~StrQ() { FUN_004037f0(0, 0); }
};
struct FUN_00a1b990 {
  ~FUN_00a1b990();
  void BuildPage(int a, int b);
  void operator delete(void* p) { int aiD[21]; DAT_011f6238.MemoryManager_Deallocate(p); }
};
struct OwnQ {
  FUN_00a1b990* CreateTextRunNode(StrQ* s, int a);
  bool CreateTextRun(StrQ s, int a, int b);
};
// Creates a text run node from the string s and parameter a, applies b and a via BuildPage, then deletes the node and returns true.
// @fnv 0x00a18f00
bool OwnQ::CreateTextRun(StrQ asText, int a, int b) {
  FUN_00a1b990* pNode;
  StrQ kName_ydzun(asText);
  pNode = CreateTextRunNode(&kName_ydzun, a);
  if (pNode) pNode->BuildPage(b, a);
  delete pNode;
  return true;
}
}  // namespace fnv_00a18f00

namespace fnv_00a19a10 {
struct PoolQ { void* Game_DoHeapAlloc(unsigned int n); };
extern PoolQ DAT_011f6238;
struct OwnQ;
struct EntQ {
  int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
  EntQ* ProcessEntries_00a19c00(int a, int b);
  void* operator new(unsigned int n) { int aiD[9]; return DAT_011f6238.Game_DoHeapAlloc(n); }
  void operator delete(void* p);
};
struct FUN_00a1bc70 : EntQ { FUN_00a1bc70(OwnQ* pOwner, int a, int c, int d); };
struct HeadQ { int unk00, unk04; EntQ* pEnt; };
struct OwnQ {
  int unk00; HeadQ* pHead; unsigned int ItemUpdateArray; int unk0c, unk10;
  unsigned int GetCount() { return ItemUpdateArray; }
  EntQ*& First() { return pHead->pEnt; }
  void AddItem(EntQ** ppEnt);
  void FontManager_TextDoc_AddChar(int a, int b, bool bForce);
};
// Calls FUN_00a19c00 on First() when the count is nonzero and bForce is false; otherwise allocates FUN_00a1bc70, then passes a non-null result to AddItem.
// @fnv 0x00a19a10
// src: COMMUNITY 0x00a19a10
void OwnQ::FontManager_TextDoc_AddChar(int aiParam1, int aiParam2, bool bForce) {
  EntQ* pEnt = 0;
  if (GetCount() && !bForce)
    pEnt = First()->ProcessEntries_00a19c00(aiParam1, aiParam2);
  else
    pEnt = new FUN_00a1bc70(this, aiParam1, unk0c, unk10);
  if (pEnt) AddItem(&pEnt);
}
}  // namespace fnv_00a19a10

struct StrQ {
  char* m_p;
  char* Get() { return m_p; }
  char& At(unsigned int i) { return m_p[m_p ? i : 0]; }
};
struct ObjQ { int iKey; int unk04, unk08, unk0c, unk10, unk14, unk18; StrQ kName;
  bool NameEmpty() { return !kName.Get() || !kName.At(0); } };
template <class T> struct NodQ { NodQ* pNext; int unk04; T kData; };
template <class T> struct LstQ {
  NodQ<T>* pHead;
  NodQ<T>* Head() { return pHead; }
};
template <class T> inline T& NextQ(NodQ<T>*& pNode) { T& r = pNode->kData; pNode = pNode->pNext; return r; }
struct BktQ { LstQ<ObjQ*> kList; };
struct MapQ {
  LstQ<BktQ*> kBuckets;
  int CountEmptyNameEntries(int iKey);
};
// Counts ObjQ entries with empty names and matching iKey across all buckets in kBuckets.
// @fnv 0x00a19b00
int MapQ::CountEmptyNameEntries(int iKey) {
  int iCount_sia = 0;
  NodQ<BktQ*>* pOuter_bk = kBuckets.Head();
  while (pOuter_bk) {
    BktQ* pBkt = NextQ(pOuter_bk);
    if (pBkt) {
      NodQ<ObjQ*>* pInner = pBkt->kList.Head();
      while (pInner) {
        ObjQ* pObj = NextQ(pInner);
        if (pObj && pObj->NameEmpty() && pObj->iKey == iKey)
          iCount_sia++;
      }
    }
  }
  return iCount_sia;
}

// 0x00a1b450  /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1
// thiscall, 7 stack args (ret 0x1c): constructor.
extern "C" void** DAT_011f33f8;

struct Rec00a1b450 {
    int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
};

// The glyph-record constructor at 0x00a1b450 takes NiColorA at +0x08, not a vector.

inline StrMem::StrMem(unsigned int v) { text = 0; length = (v <= 0xffff ? (unsigned short)v : 0xffff); capacity = (v <= 0xffff ? (unsigned short)v : 0xffff); }

inline bool Empty00a1b450(StrMem* target) { StrMem* text = target; return text->Set(0,0); }
inline Font* GetFont00a1b450(int index) { void** mgr = DAT_011f33f8; Font* blob = (Font*)mgr[index]; return blob; }
inline int GetHeight00a1b450(int index) { void** mgr = DAT_011f33f8; Font* blob = (Font*)mgr[index]; return (int)*(float*)blob->pFontData; }

inline int LowerBound00a1b450(int t, int lower) { return t < lower ? lower : t; }

struct FUN_00a1b450 {
    int m0;
    unsigned char m4;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    NiColorA m8;
    int m18;
    StrMem m1c;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;

    FUN_00a1b450(int a, unsigned char flag, NiColorA value, int extra);
};

// Initialises a glyph record from a font index and flag, computing advance, height and offset from the font blob data.
// @fnv 0x00a1b450
FUN_00a1b450::FUN_00a1b450(int aiFontIndex, unsigned char flag, NiColorA av4Value, int extra)
    : m8(), m1c(0u) {
    m0 = LowerBound00a1b450(aiFontIndex < 8 ? aiFontIndex : 8, 0);

    m4 = flag;

    m8 = av4Value;
    m18 = extra;

    Empty00a1b450(&m1c);

    Rec00a1b450* pGlyphRecord = (Rec00a1b450*)((char*)GetFont00a1b450(m0)->pFontData + 0x128) + m4;

    m24 = (int)(((pGlyphRecord->f24 + pGlyphRecord->f24) != 0.0) ? (double)(pGlyphRecord->f2c + pGlyphRecord->f30) : 0.0);

    m28 = (int)GetHeight00a1b450(m0);

    m2c = (int)(pGlyphRecord->f28 - pGlyphRecord->f34);

    m30 = 0;
    m34 = 0;
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
unsigned int LayoutLength(const char*);
unsigned int LayoutCapacity(unsigned int,unsigned int);
extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
inline void* LayoutCopy(void* destination,const void* source,unsigned int size) {return memcpy(destination,source,size);}
namespace TextLayout {
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" char* __cdecl strcpy(char*,const char*);
extern "C" int __cdecl FUN_00ec65a6(char*,unsigned int,const char*);
extern "C" int __cdecl sprintf(char*,const char*,...);
extern "C" void* __cdecl FUN_00ec61c0(void*,int,unsigned int);
extern "C" void* __cdecl FUN_00ec7230(void*,const void*,unsigned int);
bool __cdecl Interface_FindTextReplacementString(const char*,char*,unsigned int,bool);
bool __cdecl ResolveSettingString(const char*,char*);
void __cdecl BSsprintf(char*,unsigned int,const char*,...);
void __cdecl NormalizeSmartQuotes(unsigned char*);
extern char DAT_01019f08[],DAT_010950a8[];
struct Memory {
 void* Game_DoHeapAlloc(unsigned int);
 void* FUN_00aa4150(void*,unsigned int);
 void MemoryManager_Deallocate(void*);
};
extern Memory DAT_011f6238;
__forceinline char* AllocateText(unsigned int count) {
 unsigned int size=1;
 size*=count;
 char* text=(char*)DAT_011f6238.Game_DoHeapAlloc(size);
 FUN_00ec61c0(text,0,size);
 return text;
}
typedef FontManager Manager;
extern Manager* DAT_011f33f8;
inline Manager* GetDebrisManager() { return DAT_011f33f8; }
struct Glyph {
 int texture;
 float uv[4][2];
 float width,height,leading,spacing,top;
};

struct Rect {
 float left,right,top,bottom;
 Rect(){left=0.0f;right=0.0f;top=0.0f;bottom=0.0f;}
};
struct Icon { float width,m_fVerticalExtent,zOffset,spacing; Rect uv; };
// Exe 0x00a12fb0: unit-local ListNode view; declarations and layout are preserved.
struct FontListNodeView {
 int value;
 FontListNodeView* next;
 FontListNodeView(const int& item) : value(item), next(0) {}
 static void* operator new(unsigned int size) { return DAT_011f6238.Game_DoHeapAlloc(size); }
 void FUN_00af25b0(int* item) {
  if (!*item) return;
  FontListNodeView* tail = this;
  while (tail->next) tail = tail->next;
  if (tail->value) {
   tail->next = new FontListNodeView(*item);
  } else tail->value = *item;
 }
};
struct Layout {
 char* text;
 unsigned short length,capacity;
 int width,height;
 unsigned int firstLine;
 int maxLines;
 unsigned int characters;
 char newline;
 FontListNodeView lines;
 unsigned int MaxLength() const {return capacity;}
 void SetMaxLength(unsigned int n) {capacity=n<=0xffff?(unsigned short)n:0xffff;}
 void SetLength(unsigned int n) {length=n<=0xffff?(unsigned short)n:0xffff;}
 bool FUN_004037f0(const char* source,unsigned int minimum) {
  unsigned int size=source?LayoutLength(source):0;
  unsigned int maximum=LayoutCapacity(size,minimum);
  if(maximum<=MaxLength()) {
   if(maximum) {if(source) LayoutCopy(text,source,size+1);else text[0]=0;}
   else {if(text) delete text; text=0;maximum=0;SetMaxLength(maximum);}
  } else {
   char* old=text;
   text=new char[maximum+1];
   if(source) LayoutCopy(text,source,size+1); else text[0]=0;
   if(old) delete old;
   SetMaxLength(maximum);
  }
  SetLength(size);
  return size!=0;
 }
};
} // namespace TextLayout

inline unsigned int Font::GetIconCount() { return ((FontButtonIconArray*)ButtonIcons)->iSize; }

// @fnv 0x00a12fb0
// src: COMMUNITY 0x00a12fb0
void Font::CheckForVariablesInText(const char* input,TextLayout::Layout* layout) {
 using namespace TextLayout;
 if(!input) return;
 if(layout->width<=0) layout->width=0x7fffffff;
 if(layout->height<=0) layout->height=0x7fffffff;
 if(layout->maxLines<=0) layout->maxLines=0x7fffffff;
 float paddingSlot16=TextLayout::GetDebrisManager()->GetFontPadding(iFontNum);
 int breakOffsetSlot0=0;
 int breakWidthSlot43=0;
 int wordWidthSlot2=0;
 int widthSlot1=0;
 int maxWidthSlot29=0;
 float heightSlot31=((TextLayout::Glyph*)pFontData->pFontLetters)[32].height;
 int lineCountSlot0=1;
 unsigned int length=TextLayout::strlen(input);
 int maxLinesSlot10=layout->maxLines;
 char* workSlot77=TextLayout::AllocateText(length+4);
 char* outputSlot60=TextLayout::AllocateText(length+4);
 TextLayout::sprintf(workSlot77,TextLayout::DAT_01019f08,input);
 unsigned int outputLengthSlot0=0;
 unsigned int capacity=length+4;
 int insertedSlot12=0;
 bool hyphenSlot42=false;
 char replacementSlot0[1024];replacementSlot0[0]=0;
 bool replacedSlot17=false;
 for(unsigned int scan=0;scan<length;++scan) {
  if(workSlot77[scan]=='&') {
   char entitySlot1[128];
   int countSlot0=0;
   int prefixSlot10=1;
   bool positiveSlot0=true;
   if(workSlot77[scan+1]=='-') { positiveSlot0=false;prefixSlot10=2; }
   while(workSlot77[scan+countSlot0+prefixSlot10] && countSlot0<127 && workSlot77[scan+countSlot0]!=';' && workSlot77[scan+countSlot0]!='\n' && workSlot77[scan+countSlot0]!=layout->newline) {
    entitySlot1[countSlot0]=workSlot77[scan+countSlot0+prefixSlot10];++countSlot0;
   }
   entitySlot1[countSlot0?countSlot0-prefixSlot10:countSlot0]=0;
   unsigned int consumed=TextLayout::strlen(entitySlot1)+1;
   if(workSlot77[scan+countSlot0]==';') consumed+=prefixSlot10;
   if(TextLayout::Interface_FindTextReplacementString(entitySlot1,replacementSlot0,1024,positiveSlot0) || TextLayout::ResolveSettingString(entitySlot1,replacementSlot0)) {
    unsigned int replacementLengthSlot18=TextLayout::strlen(replacementSlot0);
    int deltaSlot0=replacementLengthSlot18-consumed;
    if(replacementSlot0[replacementLengthSlot18-1]=='\\') {
     TextLayout::Icon rectSlot1;
     int slashSlot0=0;
     while(replacementSlot0[slashSlot0]!='\\') ++slashSlot0;
     char pathSlot13[260];pathSlot13[0]=0;
     TextLayout::strcpy(pathSlot13,&replacementSlot0[slashSlot0+1]);
     pathSlot13[TextLayout::strlen(pathSlot13)-1]=0;
     if(iFontNum==7) {
      char originalPath[260];
      TextLayout::FUN_00ec65a6(originalPath,260,pathSlot13);
      TextLayout::BSsprintf(pathSlot13,260,TextLayout::DAT_010950a8,originalPath);
     }
     LoadIconFromPath(pathSlot13);
     replacementSlot0[slashSlot0]=1;replacementSlot0[slashSlot0+1]=0;
     replacementLengthSlot18=TextLayout::strlen(replacementSlot0);
     deltaSlot0=replacementLengthSlot18-consumed;
    }
    if(deltaSlot0>0) {capacity+=deltaSlot0;outputSlot60=(char*)TextLayout::DAT_011f6238.FUN_00aa4150(outputSlot60,capacity);}
    for(unsigned int copyIndex=0;copyIndex<replacementLengthSlot18;++copyIndex) {
     outputSlot60[outputLengthSlot0]=replacementSlot0[copyIndex];++outputLengthSlot0;
    }
    scan=scan+consumed-1;
   } else { outputSlot60[outputLengthSlot0]=workSlot77[scan];++outputLengthSlot0; }
   replacedSlot17=true;
  } else { outputSlot60[outputLengthSlot0]=workSlot77[scan];++outputLengthSlot0; }
 }
 outputSlot60[outputLengthSlot0]=0;
 if(replacedSlot17) {
  length=outputLengthSlot0;
  workSlot77=(char*)TextLayout::DAT_011f6238.FUN_00aa4150(workSlot77,length+4);
  TextLayout::strcpy(workSlot77,outputSlot60);
 }
 outputSlot60[0]=0;outputLengthSlot0=0;
 unsigned int imageIndexSlot13=0;
 for(unsigned int index=0;index<length;++index) {
  if(!workSlot77[index]) { break; }
  else if(workSlot77[index]==layout->newline) {
   outputSlot60[outputLengthSlot0]=layout->newline;++outputLengthSlot0;
   if(outputLengthSlot0>=capacity) {outputSlot60=(char*)TextLayout::DAT_011f6238.FUN_00aa4150(outputSlot60,outputLengthSlot0+4);capacity=outputLengthSlot0+4;}
   heightSlot31=pFontData->fBaseLine+paddingSlot16+heightSlot31;
   layout->lines.FUN_00af25b0(&widthSlot1);
   maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
   widthSlot1=0;breakOffsetSlot0=0;++lineCountSlot0;
  } else if(workSlot77[index]=='\t') {
   widthSlot1+=75-widthSlot1%75;continue;
  } else {
   unsigned char characterSlot0=workSlot77[index];
   TextLayout::NormalizeSmartQuotes(&characterSlot0);
   TextLayout::Glyph* glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[characterSlot0];
   if(characterSlot0==1) {
    if(imageIndexSlot13<GetIconCount()) {
     glyphSlot1->width=((TextLayout::Icon*)((FontButtonIconArray*)ButtonIcons)->pBuffer)[imageIndexSlot13].width;
     glyphSlot1->spacing=((TextLayout::Icon*)((FontButtonIconArray*)ButtonIcons)->pBuffer)[imageIndexSlot13].spacing;
    }
    ++imageIndexSlot13;
   }
   widthSlot1+=(int)(glyphSlot1->width+glyphSlot1->spacing);
   if(characterSlot0==' ') {
    breakOffsetSlot0=outputLengthSlot0;
    breakWidthSlot43=widthSlot1-(int)(glyphSlot1->width+glyphSlot1->spacing);
    wordWidthSlot2=widthSlot1;hyphenSlot42=false;
   } else if(characterSlot0=='~') {
    breakOffsetSlot0=outputLengthSlot0;breakWidthSlot43=widthSlot1;wordWidthSlot2=widthSlot1;hyphenSlot42=true;
    widthSlot1-=(int)(glyphSlot1->width+glyphSlot1->spacing);
   }
   if(widthSlot1>layout->width) {
    if(breakOffsetSlot0) {
     if(hyphenSlot42) {
      hyphenSlot42=false;
      capacity+=4;outputSlot60=(char*)TextLayout::DAT_011f6238.FUN_00aa4150(outputSlot60,capacity);
      TextLayout::FUN_00ec7230(&outputSlot60[breakOffsetSlot0+2],&outputSlot60[breakOffsetSlot0],outputLengthSlot0-breakOffsetSlot0);
      outputSlot60[breakOffsetSlot0+1]='\n';outputSlot60[breakOffsetSlot0]='-';
      outputLengthSlot0+=2;insertedSlot12+=2;
      glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[45];
      heightSlot31=pFontData->fBaseLine+paddingSlot16+heightSlot31;
      widthSlot1-=(int)(glyphSlot1->width+glyphSlot1->spacing);
      layout->lines.FUN_00af25b0(&widthSlot1);
      maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
      breakOffsetSlot0=0;++lineCountSlot0;
      glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[outputSlot60[breakOffsetSlot0-1]];
      widthSlot1=(int)(glyphSlot1->width+glyphSlot1->spacing);
      glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[characterSlot0];
      widthSlot1+=(int)(glyphSlot1->width+glyphSlot1->spacing);
     } else {
      if(breakOffsetSlot0==outputLengthSlot0) characterSlot0=layout->newline;
      else outputSlot60[breakOffsetSlot0]=layout->newline;
      heightSlot31=pFontData->fBaseLine+paddingSlot16+heightSlot31;
      layout->lines.FUN_00af25b0(&breakWidthSlot43);
      maxWidthSlot29=maxWidthSlot29>breakWidthSlot43?maxWidthSlot29:breakWidthSlot43;
      breakOffsetSlot0=0;++lineCountSlot0;widthSlot1-=wordWidthSlot2;
     }
    } else {
     if(outputLengthSlot0+3>=capacity) {outputSlot60=(char*)TextLayout::DAT_011f6238.FUN_00aa4150(outputSlot60,outputLengthSlot0+6);capacity=outputLengthSlot0+6;}
     outputSlot60[outputLengthSlot0+2]=outputSlot60[outputLengthSlot0];
     outputSlot60[outputLengthSlot0+1]=outputSlot60[outputLengthSlot0-1];
     outputSlot60[outputLengthSlot0]='\n';outputSlot60[outputLengthSlot0-1]='-';
     outputLengthSlot0+=2;insertedSlot12+=2;
     glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[45];
     heightSlot31=pFontData->fBaseLine+paddingSlot16+heightSlot31;
     widthSlot1-=(int)(glyphSlot1->width+glyphSlot1->spacing);
     layout->lines.FUN_00af25b0(&widthSlot1);
     maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
     breakOffsetSlot0=0;++lineCountSlot0;
     glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[outputSlot60[outputLengthSlot0-1]];
     widthSlot1=(int)(glyphSlot1->width+glyphSlot1->spacing);
     glyphSlot1=&((TextLayout::Glyph*)pFontData->pFontLetters)[characterSlot0];
     widthSlot1+=(int)(glyphSlot1->width+glyphSlot1->spacing);
    }
   }
   if(characterSlot0!='~') {outputSlot60[outputLengthSlot0]=characterSlot0;++outputLengthSlot0;}
   if(outputLengthSlot0>=capacity) {outputSlot60=(char*)TextLayout::DAT_011f6238.FUN_00aa4150(outputSlot60,outputLengthSlot0+4);capacity=outputLengthSlot0+4;}
  }
  if(maxLinesSlot10>0 && lineCountSlot0>maxLinesSlot10 && outputLengthSlot0>0) {
   while(outputSlot60[outputLengthSlot0]!=layout->newline) --outputLengthSlot0;
   outputSlot60[outputLengthSlot0]=0;
   heightSlot31-=pFontData->fBaseLine+paddingSlot16;break;
  }
 }
 if(outputSlot60[0] && layout->firstLine) {
  unsigned int copiedSlot1=0;
  unsigned int index=0;
  unsigned int lineSlot0=0;
  for(index=0;index<outputLengthSlot0;++index) {
   if(lineSlot0>=layout->firstLine && lineSlot0<(unsigned int)layout->maxLines) {
    outputSlot60[copiedSlot1]=outputSlot60[index];++copiedSlot1;
   }
   if(outputSlot60[index]=='\n')++lineSlot0;
  }
  outputSlot60[copiedSlot1]=0;outputLengthSlot0=copiedSlot1;
 }
 if(!outputSlot60[0]) {
  outputSlot60[0]=' ';outputSlot60[1]=0;outputLengthSlot0=1;lineCountSlot0=1;
  heightSlot31=((TextLayout::Glyph*)pFontData->pFontLetters)[32].height;
  widthSlot1=(int)((TextLayout::Glyph*)pFontData->pFontLetters)[32].width;
 }
 layout->lines.FUN_00af25b0(&widthSlot1);
 maxWidthSlot29=maxWidthSlot29>widthSlot1?maxWidthSlot29:widthSlot1;
 outputSlot60[outputLengthSlot0]=0;
 layout->FUN_004037f0(outputSlot60,0);
 layout->width=maxWidthSlot29;
 layout->height=fnv_FloatToInt(heightSlot31);
 layout->firstLine=0;
 layout->maxLines=lineCountSlot0;
 layout->characters=outputLengthSlot0;
 TextLayout::DAT_011f6238.MemoryManager_Deallocate(workSlot77);
 TextLayout::DAT_011f6238.MemoryManager_Deallocate(outputSlot60);
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
namespace PageMeshes {

struct Color {float r,g,b,a;Color(float R,float G,float B,float A){r=R;g=G;b=B;a=A;}};extern NiPoint3 DAT_011f426c;extern float DAT_01095274,DAT_01095270,DAT_0109526c;

struct Update {float time;bool controllers,multithreaded,unk6,unk7,unk8;Update(){time=0.0f;controllers=false;multithreaded=false;unk6=false;unk7=false;unk8=false;}};

struct GeometryData {int unk0,unk4;unsigned short count,unkA;int unkC;Bound bound;NiPoint3* vertices;NiPoint3* GetVertices(){NiPoint3* result=vertices;return result;}unsigned short GetCount(){return count;}Bound& GetBound(){return bound;}};

struct Shape {virtual void Destroy();unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3c;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4c;unsigned int unk50;unsigned int unk54;NiPoint3 position;unsigned int unk64;unsigned int unk68;unsigned int unk6c;unsigned int unk70;unsigned int unk74;unsigned int unk78;unsigned int unk7c;unsigned int unk80;unsigned int unk84;unsigned int unk88;unsigned int unk8c;unsigned int unk90;unsigned int unk94;unsigned int unk98;unsigned int unk9c;unsigned int unka0;unsigned int unka4;unsigned int unka8;unsigned int unkac;unsigned int unkb0;unsigned int unkb4;GeometryData* data;void SetPosition(const NiPoint3& v){position=v;}void SetPositionThroughShape(const NiPoint3& v){Shape* current=this;current->position=v;}GeometryData* GetData(){return data;}void UpdateProperties();void NiAVObject_Update(const Update&);};

struct Node {virtual void v0();virtual void v4();virtual void v8();virtual void vc();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void v60();virtual void v64();virtual void v68();virtual void v6c();virtual void v70();virtual void v74();virtual void v78();virtual void v7c();virtual void v80();virtual void v84();virtual void v88();virtual void v8c();virtual void v90();virtual void v94();virtual void v98();virtual void v9c();virtual void va0();virtual void va4();virtual void va8();virtual void vac();virtual void vb0();virtual void vb4();virtual void vb8();virtual void vbc();virtual void vc0();virtual void vc4();virtual void vc8();virtual void vcc();virtual void vd0();virtual void vd4();virtual void vd8();virtual void Attach(Shape*,bool);};

struct Heap {void* Game_DoHeapAlloc(unsigned int);void MemoryManager_Deallocate(void*);};extern Heap DAT_011f6238;

template<class T> struct Link {Link* next;Link* previous;T value;};

template<class T> struct ListBase {Link<T>* head;Link<T>* tail;unsigned int count;~ListBase(){}Link<T>* Head(){return head;}T& Next(Link<T>*& p){T& value=p->value;p=p->next;return value;}unsigned int Count(){return count;}void NiTListBase_AddNodeHead_1(Link<T>*);
// src: GUESS 0x00a1c2d0 (confidence: medium)
void ClearLinkedNodes(){Link<T>* pNode=head;while(pNode){Link<T>* pDelete=pNode;pNode=pNode->next;pDelete->value=0;Link<T>* pFree=pDelete;DAT_011f6238.MemoryManager_Deallocate(pFree);}count=0;head=0;tail=0;}T PopFront(){Link<T>* pNode=head;head=head->next;if(head)head->previous=0;else tail=0;T element=pNode->value;pNode->value=0;Link<T>* pFree=pNode;DAT_011f6238.MemoryManager_Deallocate(pFree);--count;return element;}void FUN_00a11db0(Link<T>* item){item->next=0;item->previous=tail;if(tail)tail->next=item;else head=item;tail=item;++count;}
// src: COMMUNITY 0x00a11c00
void NiTList_AddTail(const T& value){Link<T>* item=NewNode();item->value=value;FUN_00a11db0(item);}Link<T>* NewNode(){Link<T>* node=(Link<T>*)DAT_011f6238.Game_DoHeapAlloc(sizeof(Link<T>));return node;}void Add(T value){Link<T>* p=NewNode();p->value=value;NiTListBase_AddNodeHead_1(p);}};
template<class T> struct PointerListBase : ListBase<T> {~PointerListBase(){this->ClearLinkedNodes();}};
template<class T> struct List : PointerListBase<T> {List(){this->count=0;this->head=0;this->tail=0;} ~List(){}};

unsigned int TextLength(const char*);unsigned int TextCapacity(unsigned int,unsigned int);void* TextCopy(void*,const void*,unsigned int);
struct Text {char* p;unsigned short length,capacity;Text(const Text& value){Init();Set(value.Get(),0);}~Text();void Init(){p=0;SetLength(0);SetMaxLength(0);}unsigned int MaxLength() const {return capacity;}
void SetLength(unsigned int n){length=n<=0xffff?(unsigned short)n:0xffff;}
void SetMaxLength(unsigned int n){capacity=n<=0xffff?(unsigned short)n:0xffff;}
bool Set(const char* source,unsigned int minimum){unsigned int size=source?TextLength(source):0;unsigned int maximum=TextCapacity(size,minimum);if(maximum<=MaxLength()){if(maximum){if(source)TextCopy(p,source,size+1);else p[0]=0;}else{if(p)delete p;p=0;maximum=0;SetMaxLength(maximum);}}else{char* old=p;p=new char[maximum+1];if(source)TextCopy(p,source,size+1);else p[0]=0;if(old)delete old;SetMaxLength(maximum);}SetLength(size);return size!=0;}
char* Get() const {return p;}char& operator[](unsigned int i) const {return p[p?i:0];}};

struct Run {int font;unsigned char letter,unk5,unk6,unk7;Color color;int unk18;Text text;int width,height,padding,unk30,offset;};

struct Line {List<Run*> runs;int width,unk10,height,unk18,padding,align;};

struct Page {List<Line*> lines;int CountEmptyNameEntries(unsigned int);};

struct Letter {float leading,top,width,height;unsigned int unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34;};

struct Icons {virtual void v0();virtual void v4();virtual void Free(void*);int unk4,count,unkC;bool Empty(){return count==0;}void FUN_00a1bfa0(bool abFree){if(unk4){for(unsigned int i=0;i<(unsigned int)count;++i){}if(abFree){Free((void*)unk4);unk4=0;unk4=0;unkC=0;}count=0;}}};


struct Manager {Font* fonts[8];Font* GetFont(unsigned int i){return fonts[i];}Shape* FontManager_MakeImage(Text,NiPoint3,int,int);};extern Manager* DAT_011f33f8;inline Manager* GetDebrisManager(){return DAT_011f33f8;}

struct Layout {unsigned int unk0;unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;int height;unsigned int unk2c;unsigned int unk30;bool useWidth;unsigned char unk35,unk36,unk37;int Height(){return height;}bool UseWidth(){return useWidth;}};

struct Builder {List<Page*> pages;int width;int unk10;int index;void BuildPage(Node*,Layout*);};

// Builds text and image shapes for a page, computes their bounds, and attaches them to a node.
// @fnv 0x00a19060
void Builder::BuildPage(Node* node,Layout* layout){

Page* pageSlot35=0;int remainingSlot28=index;int iconIndexSlot11=0;Shape* shapesSlot32[8];int indices[8];Link<Page*>* cursorSlot10=pages.Head();while(cursorSlot10&&remainingSlot28--)pages.Next(cursorSlot10);if(cursorSlot10)pageSlot35=cursorSlot10->value;else return;

for(unsigned int fontIndex=0;fontIndex<8;fontIndex++){indices[fontIndex]=0;shapesSlot32[fontIndex]=0;int count=pageSlot35->CountEmptyNameEntries(fontIndex);if(count>0){shapesSlot32[fontIndex]=GetDebrisManager()->GetFont(fontIndex)->CreateTextShape(count,&Color(117.0f/255.0f,59.0f/255.0f,33.0f/255.0f,1.0f),true);shapesSlot32[fontIndex]->SetPosition(DAT_011f426c);}}

List<Shape*> imagesSlot52;Shape* iconsSlot17=0;if(!((Icons*)GetDebrisManager()->GetFont(0)->ButtonIcons)->Empty()){iconsSlot17=GetDebrisManager()->GetFont(0)->MakeButton();iconsSlot17->SetPositionThroughShape(DAT_011f426c);imagesSlot52.Add(iconsSlot17);}

if(pageSlot35){int lineIndexSlot43=0;NiPoint3 position=DAT_011f426c;Link<Line*>* lineCursorSlot0=pageSlot35->lines.Head();while(lineCursorSlot0&&lineIndexSlot43<layout->Height()){Line* lineSlot0=pageSlot35->lines.Next(lineCursorSlot0);position.x=0.0f;int lineWidthSlot23=0;if(layout->UseWidth())lineWidthSlot23=width;if(lineSlot0->align==4)position.x=float(lineWidthSlot23-lineSlot0->width);if(lineSlot0->align==2)position.x=float((lineWidthSlot23-lineSlot0->width)/2);position.y=0.0f;position.z-=lineSlot0->height+lineSlot0->padding;

Link<Run*>* runCursorSlot19=lineSlot0->runs.Head();while(runCursorSlot19){Run* runSlot0=lineSlot0->runs.Next(runCursorSlot19);Font* fontSlot0=GetDebrisManager()->GetFont(runSlot0->font);if((unsigned char)((!runSlot0->text.Get()||!runSlot0->text[0])?1:0)){

NiPoint3 glyphPosition=position;glyphPosition.x+=runSlot0->offset;if(runSlot0->letter==1){GetDebrisManager()->GetFont(0)->UpdateIconGeometry(iconIndexSlot11++,iconsSlot17,glyphPosition);}else fontSlot0->BuildGlyphQuad(&((Letter*)fontSlot0->pFontData->pFontLetters)[runSlot0->letter],indices[runSlot0->font]++,shapesSlot32[runSlot0->font],glyphPosition,&runSlot0->color);

}else{NiPoint3 imagePosition=position;imagePosition.x+=runSlot0->offset;Shape* image=GetDebrisManager()->FontManager_MakeImage(runSlot0->text,imagePosition,runSlot0->width,runSlot0->height+runSlot0->padding);if(image)imagesSlot52.NiTList_AddTail(image);}}

}

bool attachedSlot0=false;for(unsigned int finishIndex=0;finishIndex<8;finishIndex++){if(shapesSlot32[finishIndex]){NiPoint3* vertices=shapesSlot32[finishIndex]->GetData()->GetVertices();shapesSlot32[finishIndex]->GetData()->GetBound().ComputeBoundingSphere(shapesSlot32[finishIndex]->GetData()->GetCount(),(::NiPoint3*)vertices);shapesSlot32[finishIndex]->SetPosition(DAT_011f426c);shapesSlot32[finishIndex]->UpdateProperties();Update update;shapesSlot32[finishIndex]->NiAVObject_Update(update);node->Attach(shapesSlot32[finishIndex],true);attachedSlot0=true;}}

while(imagesSlot52.Count()){Shape* finishedImageSlot0=imagesSlot52.PopFront();NiPoint3* imageVerticesSlot0=finishedImageSlot0->GetData()->GetVertices();finishedImageSlot0->GetData()->GetBound().ComputeBoundingSphere(finishedImageSlot0->GetData()->GetCount(),(::NiPoint3*)imageVerticesSlot0);finishedImageSlot0->position=DAT_011f426c;finishedImageSlot0->UpdateProperties();Update imageUpdateSlot0;finishedImageSlot0->NiAVObject_Update(imageUpdateSlot0);node->Attach(finishedImageSlot0,true);}}

((Icons*)GetDebrisManager()->GetFont(0)->ButtonIcons)->FUN_00a1bfa0(true);

}}

typedef BSSimpleArray<ButtonIcon, 1024> ButtonIconArray;
template <> inline void BSSimpleArray<ButtonIcon, 1024>::UpdateEntryValue(ButtonIcon* apDestAddr, ButtonIcon* apSrcAddr, unsigned int aiCount)
{
        if (aiCount <= 0) {
            return;
        }
        if (apDestAddr < apSrcAddr) {
            for (unsigned int i = 0; i < aiCount; ++i) {
                memcpy(&apDestAddr[i], &apSrcAddr[i], sizeof(ButtonIcon));
            }
        } else if (apDestAddr > apSrcAddr) {
            for (int i = aiCount - 1; i >= 0; --i) {
                memcpy(&apDestAddr[i], &apSrcAddr[i], sizeof(ButtonIcon));
            }
        }
    }
// src: XBOX_PDB 0x0076b610
template <> inline bool BSSimpleArray<ButtonIcon, 1024>::NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const
{
        if (iSize == SimpleArrayStorage) {
            return true;
        }
        return false;
    }
template <> inline void BSSimpleArray<ButtonIcon, 1024>::ReallocateStorage(unsigned int aiNewSize, unsigned int aiCopyCount)
{
        if (pBuffer) {
            if (aiCopyCount == SimpleArrayStorage) {
                pBuffer = _Reallocate(pBuffer, aiNewSize);
            } else {
                ButtonIcon* pnewBuffer = _Allocate(aiNewSize);
                UpdateEntryValue(pnewBuffer, pBuffer, aiCopyCount);
                _Deallocate(pBuffer);
                pBuffer = 0;
                pBuffer = pnewBuffer;
            }
        } else {
            pBuffer = _Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }


// Grows the buffer when full, increments iSize, and returns the index of the newly added slot.
// @fnv 0x00a1c130
template <> unsigned int BSSimpleArray<ButtonIcon, 1024>::ReserveIndex() {
    if (NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty()) {
        if (SimpleArrayStorage == 0) {
            unsigned int inewSize = 4;
            pBuffer = _Allocate(inewSize);
            SimpleArrayStorage = inewSize;
        } else {
            unsigned int inewSize = SimpleArrayStorage > 1024 ? SimpleArrayStorage + 1024 : SimpleArrayStorage * 2;
            ReallocateStorage(inewSize, iSize);
            SimpleArrayStorage = inewSize;
        }
    }
    iSize++;
    return iSize - 1;
}

unsigned long GetCurrentThreadIdWrapper();
long InterlockedCompareExchangeWrapper(volatile long* plDest, long lExchange, long lComparand);
void SleepWrapper(int iMS);

inline void NiCriticalSection::Lock(const char* pcFile)
{
    unsigned long ulThreadID = GetCurrentThreadIdWrapper();
    if (*reinterpret_cast<volatile long*>(&m_ulThreadOwner) == (long)ulThreadID)
    {
        m_uiLockCount++;
        return;
    }
    unsigned int uiSpin = 0;
    while (InterlockedCompareExchangeWrapper(reinterpret_cast<volatile long*>(&m_ulThreadOwner), ulThreadID, 0))
    {
        uiSpin++;
        if (uiSpin > 10000)
            ::SleepWrapper(1);
        else
            ::SleepWrapper(0);
    }
    m_uiLockCount = 1;
}

namespace fnv_00a1b990 {
extern MemoryManager g_memoryManager;


// Unit-local view of NiTListItem for 0x00a1b990 (namespace fnv_00a1b990): built on the shared NiTListItem, that code does not compile or does not match.
template<class T> struct NiTListItem_00a1b990 {
    NiTListItem_00a1b990* m_pkNext;
    NiTListItem_00a1b990* m_pkPrev;
    T m_element;
};

template<class T> class PoolAllocatorBase {
public:
    struct LinkedListEntry {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pAllocationList;
    static NiCriticalSection ms_kPoolLock;
};

// Unit-local view of NiTPointerAllocator for 0x00a1b990 (namespace fnv_00a1b990): built on the shared NiTPointerAllocator, that code does not compile or does not match.
template<class T> class NiTPointerAllocator_00a1b990 : public PoolAllocatorBase<T> {
public:
    void Deallocate(void* p)
    {
        PoolAllocatorBase<T>::ms_kPoolLock.Lock();
        typename PoolAllocatorBase<T>::LinkedListEntry* pDel =
            (typename PoolAllocatorBase<T>::LinkedListEntry*)p;
        pDel->m_pUserData = 0;
        pDel->m_pkNext = PoolAllocatorBase<T>::ms_pAllocationList;
        PoolAllocatorBase<T>::ms_pAllocationList = pDel;
        PoolAllocatorBase<T>::ms_kPoolLock.Unlock();
    }
};

// Unit-local view of NiTListBase for 0x00a1b990 (namespace fnv_00a1b990): built on the shared NiTListBase, that code does not compile or does not match.
template<class TheAllocator, class T> class NiTListBase_00a1b990 {
public:
    ~NiTListBase_00a1b990() { }
    unsigned int GetSize() const { return m_kItemCount.m_uiCount; }

    NiTListItem_00a1b990<T>* m_pkHead;
    NiTListItem_00a1b990<T>* m_pkTail;
    MapEntryCount m_kItemCount;
};

// Unit-local view of NiTPointerListBase for 0x00a1b990 (namespace fnv_00a1b990): built on the shared NiTPointerListBase, that code does not compile or does not match.
template<class TheAllocator, class T> class NiTPointerListBase_00a1b990 : public NiTListBase_00a1b990<TheAllocator, T> {
public:
    ~NiTPointerListBase_00a1b990() { RemoveAll(); }

    void DeleteItem(NiTListItem_00a1b990<T>* pkItem)
    {
        pkItem->m_element = 0;
        reinterpret_cast<TheAllocator*>(&this->m_kItemCount)->Deallocate(pkItem);
    }

    void RemoveAll()
    {
        NiTListItem_00a1b990<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem_00a1b990<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }

    T RemoveHead()
    {
        NiTListItem_00a1b990<T>* pkNode = this->m_pkHead;
        this->m_pkHead = this->m_pkHead->m_pkNext;
        if (this->m_pkHead)
            this->m_pkHead->m_pkPrev = 0;
        else
            this->m_pkTail = 0;
        T element = pkNode->m_element;
        DeleteItem(pkNode);
        this->m_kItemCount.m_uiCount--;
        return element;
    }
};

template<class T> class FontPointerList : public NiTPointerListBase_00a1b990<NiTPointerAllocator_00a1b990<unsigned int>, T> {
};

class TileValue {
public:
    ~TileValue();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};

class TileElement {
public:
    ~TileElement()
    {
        while (m_kValues.GetSize())
            delete m_kValues.RemoveHead();
    }
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    FontPointerList<TileValue*> m_kValues;
};

class TileCollection {
public:
    ~TileCollection();
    FontPointerList<TileElement*> m_kUnsortedGeometryList;
};

// Deletes each TileElement* in m_kUnsortedGeometryList by removing the head until the list is empty.
// @fnv 0x00a1b990
TileCollection::~TileCollection()
{
    while (m_kUnsortedGeometryList.GetSize())
        delete m_kUnsortedGeometryList.RemoveHead();
}
}  // namespace fnv_00a1b990

namespace fnv_00a1ba50 {
extern MemoryManager g_memoryManager;


// Unit-local view of NiTListItem for 0x00a1ba50 (namespace fnv_00a1ba50): built on the shared NiTListItem, that code does not compile or does not match.
template<class T> struct NiTListItem_00a1ba50 {
    NiTListItem_00a1ba50* m_pkNext;
    NiTListItem_00a1ba50* m_pkPrev;
    T m_element;
};

template<class T> class PoolAllocatorBase {
public:
    struct LinkedListEntry {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pAllocationList;
    static NiCriticalSection ms_kPoolLock;
};

// Unit-local view of NiTPointerAllocator for 0x00a1ba50 (namespace fnv_00a1ba50): built on the shared NiTPointerAllocator, that code does not compile or does not match.
template<class T> class NiTPointerAllocator_00a1ba50 : public PoolAllocatorBase<T> {
public:
    void Deallocate(void* p)
    {
        PoolAllocatorBase<T>::ms_kPoolLock.Lock();
        typename PoolAllocatorBase<T>::LinkedListEntry* pDel =
            (typename PoolAllocatorBase<T>::LinkedListEntry*)p;
        pDel->m_pUserData = 0;
        pDel->m_pkNext = PoolAllocatorBase<T>::ms_pAllocationList;
        PoolAllocatorBase<T>::ms_pAllocationList = pDel;
        PoolAllocatorBase<T>::ms_kPoolLock.Unlock();
    }
};

// Unit-local view of NiTListBase for 0x00a1ba50 (namespace fnv_00a1ba50): built on the shared NiTListBase, that code does not compile or does not match.
template<class TheAllocator, class T> class NiTListBase_00a1ba50 {
public:
    ~NiTListBase_00a1ba50() { }
    unsigned int GetSize() const { return m_kItemCount.m_uiCount; }

    NiTListItem_00a1ba50<T>* m_pkHead;
    NiTListItem_00a1ba50<T>* m_pkTail;
    MapEntryCount m_kItemCount;
};

// Unit-local view of NiTPointerListBase for 0x00a1ba50 (namespace fnv_00a1ba50): built on the shared NiTPointerListBase, that code does not compile or does not match.
template<class TheAllocator, class T> class NiTPointerListBase_00a1ba50 : public NiTListBase_00a1ba50<TheAllocator, T> {
public:
    ~NiTPointerListBase_00a1ba50() { RemoveAll(); }

    void DeleteItem(NiTListItem_00a1ba50<T>* pkItem)
    {
        pkItem->m_element = 0;
        reinterpret_cast<TheAllocator*>(&this->m_kItemCount)->Deallocate(pkItem);
    }

    void RemoveAll()
    {
        NiTListItem_00a1ba50<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem_00a1ba50<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }

    T RemoveHead()
    {
        NiTListItem_00a1ba50<T>* pkNode = this->m_pkHead;
        this->m_pkHead = this->m_pkHead->m_pkNext;
        if (this->m_pkHead)
            this->m_pkHead->m_pkPrev = 0;
        else
            this->m_pkTail = 0;
        T element = pkNode->m_element;
        DeleteItem(pkNode);
        this->m_kItemCount.m_uiCount--;
        return element;
    }
};

template<class T> class FontPointerList : public NiTPointerListBase_00a1ba50<NiTPointerAllocator_00a1ba50<unsigned int>, T> {
};

class TileValueAction {
public:
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    BSStringT<char> m_kString;
};

class TileValue {
public:
    ~TileValue()
    {
        while (m_kActions.GetSize())
            delete m_kActions.RemoveHead();
    }
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    FontPointerList<TileValueAction*> m_kActions;
};

class TileElement {
public:
    ~TileElement();
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    FontPointerList<TileValue*> m_kValues;
};

// Deletes all TileValue* elements in m_kValues by repeatedly removing and deleting the head of the list until it is empty.
// @fnv 0x00a1ba50
TileElement::~TileElement()
{
    while (m_kValues.GetSize())
        delete m_kValues.RemoveHead();
}
}  // namespace fnv_00a1ba50

namespace fnv_00a1bb10 {
extern MemoryManager g_memoryManager;


// Unit-local view of NiTListItem for 0x00a1bb10 (namespace fnv_00a1bb10): built on the shared NiTListItem, that code does not compile or does not match.
template<class T> struct NiTListItem_00a1bb10 {
    NiTListItem_00a1bb10* m_pkNext;
    NiTListItem_00a1bb10* m_pkPrev;
    T m_element;
};

template<class T> class PoolAllocatorBase {
public:
    struct LinkedListEntry {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pAllocationList;
    static NiCriticalSection ms_kPoolLock;
};

// Unit-local view of NiTPointerAllocator for 0x00a1bb10 (namespace fnv_00a1bb10): built on the shared NiTPointerAllocator, that code does not compile or does not match.
template<class T> class NiTPointerAllocator_00a1bb10 : public PoolAllocatorBase<T> {
public:
    void Deallocate(void* p)
    {
        PoolAllocatorBase<T>::ms_kPoolLock.Lock();
        typename PoolAllocatorBase<T>::LinkedListEntry* pDel =
            (typename PoolAllocatorBase<T>::LinkedListEntry*)p;
        pDel->m_pUserData = 0;
        pDel->m_pkNext = PoolAllocatorBase<T>::ms_pAllocationList;
        PoolAllocatorBase<T>::ms_pAllocationList = pDel;
        PoolAllocatorBase<T>::ms_kPoolLock.Unlock();
    }
};

// Unit-local view of NiTListBase for 0x00a1bb10 (namespace fnv_00a1bb10): built on the shared NiTListBase, that code does not compile or does not match.
template<class TheAllocator, class T> class NiTListBase_00a1bb10 {
public:
    ~NiTListBase_00a1bb10() { }
    unsigned int GetSize() const { return m_kItemCount.m_uiCount; }

    NiTListItem_00a1bb10<T>* m_pkHead;
    NiTListItem_00a1bb10<T>* m_pkTail;
    MapEntryCount m_kItemCount;
};

// Unit-local view of NiTPointerListBase for 0x00a1bb10 (namespace fnv_00a1bb10): built on the shared NiTPointerListBase, that code does not compile or does not match.
template<class TheAllocator, class T> class NiTPointerListBase_00a1bb10 : public NiTListBase_00a1bb10<TheAllocator, T> {
public:
    ~NiTPointerListBase_00a1bb10() { RemoveAll(); }

    void DeleteItem(NiTListItem_00a1bb10<T>* pkItem)
    {
        pkItem->m_element = 0;
        reinterpret_cast<TheAllocator*>(&this->m_kItemCount)->Deallocate(pkItem);
    }

    void RemoveAll()
    {
        NiTListItem_00a1bb10<T>* pkCurr = this->m_pkHead;
        while (pkCurr)
        {
            NiTListItem_00a1bb10<T>* pkDel = pkCurr;
            pkCurr = pkCurr->m_pkNext;
            DeleteItem(pkDel);
        }
        this->m_kItemCount.m_uiCount = 0;
        this->m_pkHead = 0;
        this->m_pkTail = 0;
    }

    T RemoveHead()
    {
        NiTListItem_00a1bb10<T>* pkNode = this->m_pkHead;
        this->m_pkHead = this->m_pkHead->m_pkNext;
        if (this->m_pkHead)
            this->m_pkHead->m_pkPrev = 0;
        else
            this->m_pkTail = 0;
        T element = pkNode->m_element;
        DeleteItem(pkNode);
        this->m_kItemCount.m_uiCount--;
        return element;
    }
};

template<class T> class FontPointerList : public NiTPointerListBase_00a1bb10<NiTPointerAllocator_00a1bb10<unsigned int>, T> {
};



class StringItem {
public:
    static void operator delete(void* p) { g_memoryManager.Deallocate(p); }

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ::BSStringT<char> m_kString;
};

class StringItemList {
public:
    ~StringItemList();
    FontPointerList<StringItem*> m_kUnsortedGeometryList;
};

// Deletes all StringItem elements from m_kUnsortedGeometryList by repeatedly removing and deleting the head node until the list is empty.
// @fnv 0x00a1bb10
StringItemList::~StringItemList()
{
    while (m_kUnsortedGeometryList.GetSize())
        delete m_kUnsortedGeometryList.RemoveHead();
}
}  // namespace fnv_00a1bb10

double __cdecl FUN_00ec9130(double, double);
extern "C" float DAT_0102f0f8;

inline NiGeometryData* GetData(NiTriShape* s) { return s->m_spModelData.m_pObject; }
inline FontPoint3* GetVerts(NiGeometryData* d) { FontPoint3* p = (FontPoint3*)d->m_pkVertex; return p; }
inline unsigned short GetCount(NiGeometryData* d) { return d->m_usVertices; }

inline int Max(int a, int b) { return a > b ? a : b; }
extern "C" double DAT_010731a8;
__forceinline double FMod75(const float& f) { return (float)FUN_00ec9130(f, DAT_0102f0f8); }
__forceinline void TabAdvance(float& x) { float remainder = x; float input = (float)FMod75(remainder); x = DAT_010731a8 - input + x; }

// Font methods at 0x00a12460, 0x00a12370 and 0x00a14a20; Font.h lacks these declarations.
struct StringShapeBuilder : public Font {
    NiTriShape* Font_MakeString(float fX, float fY, float fZ, SStr* text, int* piX,
                             int iFlags, void* pUnk, bool bShift, bool bSkip);
    void Font_GetLineOffsets(char* str, float* pSize, float* pOut, int iFlags, int iStart);
    NiTriShape* CreateTextShape(int count, void* p, bool b);
};

// Builds a NiTriShape for a text string by mapping each character to glyph geometry, handling newlines and tabs, and updating the output x-offset.
// @fnv 0x00a12460
// src: COMMUNITY 0x00a12460
NiTriShape* StringShapeBuilder::Font_MakeString(float fX, float fY, float fZ, SStr* text, int* piX,
                                int iFlags, void* pUnk, bool bShift, bool bSkip)
{
    if (text->GetLen() == 0 || this->pFontData == 0)
        return 0;

    float kPos2 = (float)*piX;
    float fOut1;
    this->Font_GetLineOffsets(text->GetString(), &kPos2, &fOut1, iFlags, 0);

    FontPoint3 kVertexPositionLocal;
    kVertexPositionLocal.x = fX + kPos2;
    kVertexPositionLocal.z = fY;
    kVertexPositionLocal.y = fZ;

    if (bShift)
        kVertexPositionLocal.z = kVertexPositionLocal.z - (((FontCharacterInfo*)(this->pFontData)->pFontLetters)[32].m_fGlyphExtent - (this->pFontData)->fBaseLine) * 2.0f;

    unsigned int kColor = 0;
    while (kColor < text->GetLen() &&
           *(text->pString + (text->pString ? kColor : 0)) != 0)
        kColor++;
    if (kColor == 0)
        return 0;

    NiTriShape* kPos = this->CreateTextShape((int)kColor, pUnk, bSkip);

    FontPoint3 kOrigin2;
    kOrigin2.x = fX;
    kOrigin2.y = kVertexPositionLocal.y;
    kOrigin2.z = kVertexPositionLocal.z;
    *(FontPoint3*)&kPos->m_kLocal.m_Translate = kOrigin2;

    NiColorA* fSize = 0;
    NiColorA iCount2(0.0f, 0.0f, 1.0f, 1.0f);

    *piX = 0;

    float fStartX3 = kVertexPositionLocal.x;
    int iIndex6 = 0;
    int i6 = 0;
    while (*(text->pString + (text->pString ? i6 : 0)) != 0)
    {
        if (*(text->pString + (text->pString ? i6 : 0)) == 3)
            fSize = 0;

        switch (*(text->pString + (text->pString ? i6 : 0)))
        {
        case '\n':
            {
                float fNewSize = (float)*piX;
                float fOut2;
                this->Font_GetLineOffsets(text->GetString(), &fNewSize, &fOut2, iFlags, i6 + 1);
                kVertexPositionLocal.x = fNewSize;
                kVertexPositionLocal.z = kVertexPositionLocal.z - (this->pFontData)->fBaseLine;
            }
            break;
        case '\t':
            {
                TabAdvance(kVertexPositionLocal.x);
            }
            break;
        }

        unsigned char cChar = *(text->pString + (text->pString ? i6 : 0));
        MapCharacter(cChar);
        int iLetter = cChar;
        if (iLetter > 0x100)
            cChar = 0;
        FontCharacterInfo* kLetter = &((FontCharacterInfo*)(this->pFontData)->pFontLetters)[cChar];
        AddCharacterToShape(kLetter, iIndex6, kPos, *(NiPoint3*)&kVertexPositionLocal, reinterpret_cast<const NiColorA*>(fSize));
        iIndex6++;
        *piX = Max((int)(kVertexPositionLocal.x - fStartX3), *piX);
        if (*(text->pString + (text->pString ? i6 : 0)) == 2)
            fSize = &iCount2;
        i6++;
    }

    FontPoint3* pVerts3 = GetVerts(GetData(kPos));
    ((Bound*)&GetData(kPos)->m_kBound)->ComputeBoundingSphere(GetCount(GetData(kPos)), (NiPoint3*)pVerts3);
    return kPos;
}

void __cdecl NormalizeSmartQuotes(unsigned char*);

unsigned int LayoutLength(const char*);

template <class T> inline BSStringT<T>& BSStringT<T>::operator+=(const T* str) {
    if (str) {
        if (String()) {
            unsigned int appendLength = str ? LayoutLength(str) : 0;
            unsigned int totalLength = Length() + appendLength;
            if (totalLength > MaxLength()) Set(String(), totalLength);
            memcpy((char*)String() + Length(), str, appendLength + 1);
            SetLength(totalLength);
        } else Set(str, 0);
    }
    return *this;
}

inline int max_val(int a, int b) {
    return a > b ? a : b;
}

struct TextWrapper : Font {
    int Font_LineBreakText(BSStringT<char>* text, int* maxWidth, int* totalHeight, int lineLimit, char separator);
};

// Wraps text to fit maxWidth by inserting separators, returns line count and updates totalHeight.
// @fnv 0x00a160c0
// src: COMMUNITY 0x00a160c0
int TextWrapper::Font_LineBreakText(BSStringT<char>* text, int* piMaxWidth, int* piTotalHeight, int lineLimit, char separator)
{
    int p; // maxLines (bucket 15) -> -0x4
    unsigned int h; // index (bucket 14) -> -0x8
    int a; // lineCount (bucket 13) -> -0xc
    int i; // totalPixels (bucket 12) -> -0x10
    int s; // trailingSpaceWidth (bucket 11) -> -0x14
    int f; // longestWidth (bucket 10) -> -0x18
    int eb; // spaceWidth (bucket 9) -> -0x1c
    int cf; // currentWidth (bucket 8) -> -0x20
    unsigned int q; // length (bucket 7) -> -0x24
    FontCharacterInfo* b; // glyph (bucket 6) -> -0x28
    unsigned char ba; // mapped (bucket 5) -> -0x29
    unsigned int k; // cursor (bucket 4) -> -0x30
    char* l; // textData (bucket 3) -> -0x34

    l = text->pString;
    if (!l || !pFontData) return 0;
    eb = 0;
    s = 0;
    cf = 0;
    f = 0;
    i = (int)((FontCharacterInfo*)(pFontData)->pFontLetters)[32].m_fGlyphExtent;
    a = 0;
    q = text->Length();
    p = *piTotalHeight;
    if (*piMaxWidth == 0) *piMaxWidth = 999999;
    h = 0;
    for (; h < q; ++h) {
        if (!FontStringCharacter(*text, h)) break;
        switch (FontStringCharacter(*text, h)) {
        case '\n':
            FontStringCharacter(*text, h) = separator;
            i += (int)(pFontData)->fBaseLine;
            f = f > cf ? f : cf;
            cf = 0;
            eb = 0;
            ++a;
            break;
        case '\t':
            cf += 75 - cf % 75;
            break;
        case ' ':
            eb = h;
        default:
            ba = (unsigned char)FontStringCharacter(*text, h);
            NormalizeSmartQuotes(&ba);
            b = &((FontCharacterInfo*)(pFontData)->pFontLetters)[ba];
            cf += (int)(b->m_fGlyphWidthInPixels + b->m_fHorizontalSpacing);
            if (eb == h) s = cf;
            if (cf > *piMaxWidth) {
                if (eb) {
                    FontStringCharacter(*text, eb) = separator;
                    i += (int)(pFontData)->fBaseLine;
                    f = f > s ? f : s;
                    eb = 0;
                    ++a;
                    cf -= s;
                } else {
                    if (text->Length() >= text->sMaxLen) {
                        if (text->Length() + 1 >= text->sMaxLen) {
                            *text += "\n\n";
                            FontStringCharacter(*text, text->Length() - 1) = 0;
                            FontStringCharacter(*text, text->Length() - 2) = 0;
                        } else {
                            *text += "\n";
                            FontStringCharacter(*text, text->Length() - 1) = 0;
                        }
                    }
                    for (k = q + 2; k > h; --k)
                        FontStringCharacter(*text, k) = FontStringCharacter(*text, k - 2);
                    FontStringCharacter(*text, h - 1) = '-';
                    FontStringCharacter(*text, h) = separator;
                    i += (int)(pFontData)->fBaseLine;
                    f = max_val(f, cf - (int)(b->m_fGlyphWidthInPixels + b->m_fHorizontalSpacing));
                    eb = 0;
                    ++a;
                    cf = 0;
                }
            }
        }
        if (p > 0 && a >= p) {
            while (FontStringCharacter(*text, h) != separator) --h;
            FontStringCharacter(*text, h) = 0;
            i -= (int)(pFontData)->fBaseLine;
            break;
        }
    }
    if (FontStringCharacter(*text, 0) && h >= q) ++a;
    f = f > cf ? f : cf;
    *piMaxWidth = f;
    *piTotalHeight = i;
    return a;
}

class Setting_01017720_011f96a0
{ public:
    unsigned int metadata;
    const char* filename;
    unsigned int options;
    __forceinline const char* c_str() const {
        const char* result; if (this != 0) result = filename; else result = 0; return result;
    }
};
extern Setting_01017720_011f96a0 g_011f3414;
extern Setting_01017720_011f96a0 g_011f3420;
extern Setting_01017720_011f96a0 g_011f342c;
extern Setting_01017720_011f96a0 g_011f3438;
extern Setting_01017720_011f96a0 g_011f3444;
extern Setting_01017720_011f96a0 g_011f3450;
extern Setting_01017720_011f96a0 g_011f345c;
extern Setting_01017720_011f96a0 g_011f3468;
extern __declspec(thread) int g_tlsMemContext;
extern char DAT_0109518c;
void __cdecl ProgramFlow(const char*);
namespace FontManagerInitialization {
struct Memory { void* Game_DoHeapAlloc(unsigned int); };
extern Memory DAT_011f6238;
// Font lacks class-specific allocation and exception cleanup declarations.
struct FontAllocation : Font {
    FontAllocation(int index, const char* name, int enabled);
    static __forceinline void* operator new(unsigned int n) { return DAT_011f6238.Game_DoHeapAlloc(n); }
    static __forceinline void operator delete(void*) {}
};
}
struct AllocatorScope { int previous; inline AllocatorScope(int value) { int saved = g_tlsMemContext; previous = saved; g_tlsMemContext = value; } inline ~AllocatorScope() { int saved = previous; g_tlsMemContext = saved; } };
struct FUN_00a168b0 : public FontManager {
    FUN_00a168b0();
};
// @fnv 0x00a168b0
FUN_00a168b0::FUN_00a168b0() {
    AllocatorScope scope(12);
    pFont[0] = new FontManagerInitialization::FontAllocation(1, g_011f3414.c_str(), 1);
    pFont[1] = new FontManagerInitialization::FontAllocation(2, g_011f3420.c_str(), 1);
    pFont[2] = new FontManagerInitialization::FontAllocation(3, g_011f342c.c_str(), 1);
    pFont[3] = new FontManagerInitialization::FontAllocation(4, g_011f3438.c_str(), 1);
    pFont[4] = new FontManagerInitialization::FontAllocation(5, g_011f3444.c_str(), 1);
    pFont[5] = new FontManagerInitialization::FontAllocation(6, g_011f3450.c_str(), 1);
    pFont[6] = new FontManagerInitialization::FontAllocation(7, g_011f345c.c_str(), 1);
    pFont[7] = new FontManagerInitialization::FontAllocation(8, g_011f3468.c_str(), 1);
    bUseNewFonts = false;
    bool loaded = false;
    for (int i=0;i<8;i++) {
      if (pFont[i]->pFontData != 0) {
        loaded = true;
        break;
      }
    }
    if (!loaded) ProgramFlow(&DAT_0109518c);

}

namespace fnv_00a1a800 {
extern "C" unsigned int __cdecl strlen(const char*);
unsigned int __cdecl BSStringLength(const char*);
unsigned int __cdecl BSStringCapacityMaximum(unsigned int, unsigned int);
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct TQMemoryAllocator {
    void* Game_DoHeapAlloc(unsigned int);
    void MemoryManager_Deallocate(void*);
};
extern TQMemoryAllocator DAT_011f6238;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* __cdecl NiMalloc(unsigned int uiSize);

struct TQPoint3 {
    float x;
    float y;
    float z;

    TQPoint3() {}
    TQPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
    static void* operator new[](unsigned int uiSize) { return DAT_011f6238.Game_DoHeapAlloc(uiSize); }
};

struct TQStr {
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMaxLen;

    TQStr(const TQStr& arOther);
    ~TQStr() { Set(0, 0); }
    unsigned int MaxLength() const { return m_usMaxLen; }
    void SetLength(unsigned int length) { m_usLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF; }
    void SetMaxLength(unsigned int length) { m_usMaxLen = length <= 0xFFFF ? (unsigned short)length : 0xFFFF; }
    bool Set(const char* apString, unsigned int auiLength) {
        unsigned int length = apString ? BSStringLength(apString) : 0;
        unsigned int capacity = BSStringCapacityMaximum(length, auiLength);
        if (capacity <= MaxLength()) {
            if (capacity) {
                if (apString) __memcpy(m_pString, apString, length + 1);
                else m_pString[0] = 0;
            } else {
                if (m_pString) delete[] m_pString;
                m_pString = 0;
                capacity = 0;
                SetMaxLength(capacity);
            }
        } else {
            char* oldString = m_pString;
            m_pString = new char[capacity + 1];
            if (apString) __memcpy(m_pString, apString, length + 1);
            else m_pString[0] = 0;
            if (oldString) delete[] oldString;
            SetMaxLength(capacity);
        }
        SetLength(length);
        return length != 0;
    }
    const char* CStr() const { return m_pString; }
    unsigned int Length() const { return (m_usLen == 0xFFFF) ? strlen(CStr()) : m_usLen; }
    char& operator[](unsigned int i) { return m_pString[m_pString ? i : 0]; }
};

class TQTexture {
public:
    unsigned int m_uiRefCount;

    virtual ~TQTexture();
    virtual void DeleteThis();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual unsigned int GetWidth();
    virtual unsigned int GetHeight();

    void IncRefCount() { InterlockedIncrement((long*)&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement((long*)&m_uiRefCount) == 0) DeleteThis(); }
};

class TQExtra {
public:
    unsigned int m_uiRefCount;

    virtual ~TQExtra();
    virtual void DeleteThis();

    void IncRefCount() { InterlockedIncrement((long*)&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement((long*)&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T> class TQPtr {
public:
    T* m_pObject;

    TQPtr(T* apObject = 0) { m_pObject = apObject; if (m_pObject != 0) m_pObject->IncRefCount(); }
    ~TQPtr() { if (m_pObject != 0) m_pObject->DecRefCount(); }
    operator T*() const { return m_pObject; }
    TQPtr& operator=(T* object) {
        if (m_pObject != object) {
            if (m_pObject != 0) m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject != 0) m_pObject->IncRefCount();
        }
        return *this;
    }
};

bool __cdecl TQLoadTexture(const char* apPath, float* apfScale, TQPtr<TQTexture>& arspTexture, float afUnk,
                           TQPtr<TQExtra> aspExtra);

struct TQProperty;
struct TQPropertyList {
    void* head;
    void* tail;
    unsigned int count;
    void AddHead(const TQPtr<TQProperty>&);
};
struct TQZBuffer;
TQZBuffer* __cdecl TQCreateZBuffer(int aiFlags);

struct TQPropertyState {
    TQPtr<TQProperty> properties[7];
    TQPropertyState();
    ~TQPropertyState();
    static void* operator new(unsigned int size) { return DAT_011f6238.Game_DoHeapAlloc(size); }
    static void operator delete(void* memory) { DAT_011f6238.MemoryManager_Deallocate(memory); }
};
struct TQPropertyLock {
    unsigned int owner;
    unsigned int count;
    void Lock(const char*);
    void Unlock() { if (--count == 0) owner = 0; }
};
extern TQPropertyLock DAT_011f42a0;

class TQShape {
public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void UpdatePropertiesDownwardPass(TQPropertyState*);
int unk004;
int unk008;
int unk00C;
int unk010;
int unk014;
TQShape* m_pParentNode;
int unk01C;
int unk020;
TQPropertyList SceneGraphObject;
int unk030;
int unk034;
int unk038;
int unk03C;
int unk040;
int unk044;
int unk048;
int unk04C;
int unk050;
int unk054;
int unk058;
int unk05C;
int unk060;
int unk064;
int unk068;
int unk06C;
int unk070;
int unk074;
int unk078;
int unk07C;
int unk080;
int unk084;
int unk088;
int unk08C;
int unk090;
int unk094;
int unk098;
int unk09C;
int unk0A0;
int unk0A4;
int unk0A8;
int unk0AC;
int unk0B0;
int unk0B4;
int unk0B8;
int unk0BC;
    TQZBuffer* m_pkZBuffer;
    int unk0C4;
int unk0C8;
int unk0CC;
int unk0D0;

    static void* __cdecl operator new(unsigned int uiSize);
    TQShape(unsigned short usVertices, TQPoint3* pkVertex, TQPoint3* pkNormal, void* pkColor, NiPoint2* pkTexture,
            unsigned short usNumTextureSets, int eNBTMethod, unsigned short usTriangles, unsigned short* pusTriList,
            int iUnk1, int iUnk2, int iUnk3, int iUnk4);
    void AttachProperty(TQProperty* apProperty);
    void SetZBuffer(TQZBuffer* apZBuffer) { m_pkZBuffer = apZBuffer; }
    void GetPropertyState(TQPropertyState*& state);
    void UpdateSceneObject() {
        TQPropertyState* state = 0;
        DAT_011f42a0.Lock(0);
        if (m_pParentNode) m_pParentNode->GetPropertyState(state);
        else state = new TQPropertyState;
        UpdatePropertiesDownwardPass(state);
        delete state;
        DAT_011f42a0.Unlock();
    }
};

struct TQProperty : TQExtra {
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual int GetType();
int unk08;
int unk0C;
int unk10;
int unk14;
int unk18;
int unk1C;
int unk20;
int unk24;
int unk28;
int unk2C;
int unk30;
int unk34;
int unk38;
int unk3C;
int unk40;
int unk44;
int unk48;
int unk4C;
int unk50;
int unk54;
int unk58;
int unk5C;
TQTexture* m_pkTexture;
int unk64;
int unk68;
int unk6C;
int unk70;
int unk74;
int unk78;
int unk7C;
int unk80;
int unk84;
int unk88;
int unk8C;
int unk90;
int unk94;
int unk98;
int unk9C;
int unkA0;
int unkA4;
int unkA8;
int unkAC;

    static void* __cdecl operator new(unsigned int uiSize);
    TQProperty(bool abFlag);
    void SetTexture(TQTexture* apTexture);
};

inline void TQShape::AttachProperty(TQProperty* apProperty) {
    if (apProperty->GetType() < 7)
        SceneGraphObject.AddHead(apProperty);
}

struct TQOwner {
    TQShape* FontManager_MakeImage(TQStr kPath, float fX, float fY, float fZ, int iWidth, int iHeight);
};

// Builds a textured quad TQShape from a path and dimensions, attaches a texture property, and assigns a new z-buffer.
// @fnv 0x00a1a800
// src: COMMUNITY 0x00a1a800
TQShape* TQOwner::FontManager_MakeImage(TQStr kPath, float fX, float fY, float fZ, int iWidth, int iHeight)
{
    TQPoint3* pkVerts = new TQPoint3[4];
    NiPoint2* pkUVs5 = new NiPoint2[4];
    unsigned short* pusTris = (unsigned short*)NiMalloc(6 * sizeof(unsigned short));

    pkVerts[0] = TQPoint3(fX, fY, fZ + iHeight);
    pkVerts[1] = TQPoint3(fX, fY, fZ);
    pkVerts[2] = TQPoint3(fX + iWidth, fY, fZ + iHeight);
    pkVerts[3] = TQPoint3(fX + iWidth, fY, fZ);

    pkUVs5[0] = NiPoint2(0.0f, 0.0f);
    pkUVs5[1] = NiPoint2(0.0f, 1.0f);
    pkUVs5[2] = NiPoint2(1.0f, 0.0f);
    pkUVs5[3] = NiPoint2(1.0f, 1.0f);

    for (unsigned int i4 = 0; i4 < kPath.Length(); i4++) {
        if (kPath[i4] == '/')
            kPath[i4] = '\\';
    }

    float fScale = 1.0f;
    TQTexture* pkTexture3 = 0;
    if (kPath.m_pString && kPath[0]) {
        TQPtr<TQTexture> spTexture4 = 0;
        TQLoadTexture(kPath.CStr(), &fScale, spTexture4, 0.0f, 0);
        pkTexture3 = spTexture4;
    }

    if (pkTexture3) {
        pkUVs5[0] = NiPoint2(0.0f, 0.0f);
        pkUVs5[1] = NiPoint2(0.0f, (iHeight * fScale) / pkTexture3->GetHeight());
        pkUVs5[2] = NiPoint2((iWidth * fScale) / pkTexture3->GetWidth(), 0.0f);
        pkUVs5[3] = NiPoint2((iWidth * fScale) / pkTexture3->GetWidth(), (iHeight * fScale) / pkTexture3->GetHeight());
    }

    pusTris[0] = 0;
    pusTris[1] = 1;
    pusTris[2] = 2;
    pusTris[3] = 2;
    pusTris[4] = 1;
    pusTris[5] = 3;

    TQShape* pkShape = new TQShape(4, pkVerts, 0, 0, pkUVs5, 1, 0, 2, pusTris, 0, 0, 0, 0);
    TQProperty* pkProperty3 = new TQProperty(false);
    pkProperty3->SetTexture(pkTexture3);
    pkShape->AttachProperty(pkProperty3);
    TQZBuffer* pkNewZBuffer2 = TQCreateZBuffer(0x20);
    TQZBuffer* pkZBuffer9 = pkNewZBuffer2;
    pkShape->m_pkZBuffer = pkZBuffer9;
    pkShape->UpdateSceneObject();
    return pkShape;
}
}  // namespace fnv_00a1a800

extern double _gModifierZero;
inline FontManager* FontAlignmentInstance() { return FontManager::pInstance; }

struct FUN_00a12370_shell : Font {
    void Font_GetLineOffsets(const char* apTextString, float& afX, float& afY, int aiFlags, unsigned int aiStart);
};

// For flag values 2 and 4, calls FUN_00a1b020 and sets afX to negative half or full returned x; otherwise sets afX to zero.
// @fnv 0x00a12370
// src: COMMUNITY 0x00a12370
void FUN_00a12370_shell::Font_GetLineOffsets(const char* apTextString, float& afX, float& afY, int aiFlags, unsigned int aiStart)
{
    FontPoint3 stringDims;
    float fwrapWidth = (afX > _gModifierZero) ? afX : 3.4028234663852886e+38f;

    switch (aiFlags & 0xf)
    {
    case 2:
        stringDims = ((fnv_00a1b020::FontDimensions*)FontAlignmentInstance())->GetStringDimensions(apTextString, iFontNum, fwrapWidth, aiStart);
        afX = -stringDims.x / 2.0;
        break;
    case 4:
        stringDims = ((fnv_00a1b020::FontDimensions*)FontAlignmentInstance())->GetStringDimensions(apTextString, iFontNum, fwrapWidth, aiStart);
        afX = -stringDims.x;
        break;
    default:
        afX = 0.0f;
        break;
    }
}

inline Font* S00a1b7f0_MetricFont(unsigned int index) {

 FontManager* manager = FontManager::pInstance;

 Font* font = manager->pFont[index];

 return font;

}

inline float S00a1b7f0_MetricDrop(unsigned int index) {

 FontManager* manager = FontManager::pInstance;

 Font* selectedFont = manager->pFont[index];

 float c = selectedFont->fMaxDrop;

 return c;

}

struct S00a1b7f0_GlyphMetric {

 unsigned int font;

 unsigned char character; unsigned char unk05; unsigned char unk06; unsigned char unk07;

 int unk08; int unk0c; int unk10; int unk14; int unk18;

 BSStringT<char> icon;

 int width,height,drop,unk30,unk34;

 void FontManager_CharData_SetChar(unsigned char);

};

// Stores the character, conditionally computes width, height, and drop when the icon is empty, and resets fields.
// @fnv 0x00a1b7f0
// src: COMMUNITY 0x00a1b7f0
void S00a1b7f0_GlyphMetric::FontManager_CharData_SetChar(unsigned char auiCharacter) {

 character = auiCharacter;

 FontCharacterInfo* letter5;

 char* text = icon.pString;

 if ((unsigned char)(int)(!text || !FontStringCharacter(icon, 0))) {

  letter5 = &((FontCharacterInfo*)(S00a1b7f0_MetricFont(font)->pFontData)->pFontLetters)[character];

  width = (int)(letter5->m_fGlyphWidthInPixels + (letter5->m_fGlyphWidthInPixels != 0.0 ? letter5->m_fHorizontalSpacing + letter5->m_fHorizontalAdvance : 0.0));

  height = (int)(S00a1b7f0_MetricFont(font)->pFontData)->fBaseLine;

  drop = (int)-S00a1b7f0_MetricDrop(font);

  unk30 = 0;

 }

 unk34 = 0;

}
