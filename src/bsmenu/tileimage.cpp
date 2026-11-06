// bsmenu/tileimage.cpp: TileImage, FileFinder, BGSTextureSet, NiNode and more (7 functions)

#include "../../include/AutoMemContext.h"
#include "../../include/GO.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiObject.h"
#include "../../include/NiTexture.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/Setting.h"
#include "../../include/NiGeometry.h"
#include "../../include/BGSTextureSet.h"
#include "../../include/BSShaderTextureSet.h"
#include "../../include/BSTextureSet.h"
#include "../../include/ExtraDataList.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiTriShape.h"
#include "../../include/NiExtraData.h"
#include "../../include/MemoryManager.h"
#include "../../include/Tile.h"
#include "../../include/TileImage.h"
#include "../../include/TileShaderProperty.h"


inline void NiTexture::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiTexture::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiNode::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiNode::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}
template <class T> __forceinline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

extern Setting g_011d33f0;
typedef char tileimage_size_check[sizeof(TileImage) == 0x48 ? 1 : -1];
typedef char tileimage_flags_check[offsetof(Tile, uiFlags) == 0x30 ? 1 : -1];
typedef char tileimage_texture_check[offsetof(TileImage, spTexture) == 0x3c ? 1 : -1];
class TextureReceiver
{
  public:
    void FUN_004bc320();
};
class GlobalObject_00633c90
{
  public:
    char data[4];
};
extern GlobalObject_00633c90 g_011ded3c;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
    static int AppendStringToBuffer(char*, unsigned int, const char*);
};


// @fnv 0x00a20580
Tile* TileImage::SetTraitValue(int trait, float value, const char* text)
{
    if ((trait == 0xfa1 || trait == 0xfa2) && !(uiFlags & 1))
        SetImageFlags(1);
    else if ((trait == 0xfb1 || trait == 0xfb0) && !(uiFlags & 16))
        SetImageFlags(16);
    else if (trait == 0xfcc && GetValue(0xff9))
        SetImageFlags(16);
    return 0;
}

// @fnv 0x0078cdf0
void TileImage::UpdateTileImage()
{
    ((ExtraDataList*)&g_011ded3c)->GetStartingAngle(0)->FUN_004bc320();
}

// @fnv 0x00a1f6e0
void TileImage::Init(Tile* parent, const char* name, Tile* root)
{
    int unused[2];
    Tile::Init(parent, name, root);
    Set(0xff5, 255.0f, true);
    Set(0xfb2, 255.0f, true);
    Set(0xfb3, 255.0f, true);
    Set(0xfb4, 255.0f, true);
    Set(0xfa9, 255.0f, true);
    Set(0xfad, 1.0f, true);
    Set(0xfa3, 1.0f, true);
    SetTileType(3);
    fScale = 1.0f;
    spTexture = (NiTexture*)0;
    m_bTextureLoaded = false;
}

// Allocates a BSShaderTextureSet and copies each non-empty texture path from textures into it, prefixed with Data\Textures\.
// @fnv 0x00592d20
BSShaderTextureSet* BGSTextureSet::BuildShaderTextureSet()
{
    BSShaderTextureSet* result = new BSShaderTextureSet;
    for (int i = 0; i < 6; ++i)
    {
        const char* path = GetTexture((BSShaderProperty::TextureTypeEnum)i);
        if (path && *path)
        {
            char szFullPath[260];
            TaskQueueInterface::CopyStringToBuffer(szFullPath, 260, "Data\\Textures\\");
            TaskQueueInterface::AppendStringToBuffer(szFullPath, 260, path);
            result->SetTexture((BSShaderProperty::TextureTypeEnum)i, szFullPath);
        }
    }
    return result;
}

// Exe 0x00a1f7d0: unit-local TileimageInterfaceView view used by this matched implementation.
struct TileimageInterfaceView
{
    static float __cdecl GetInterfaceFloat();
};
struct FileFinder;
extern FileFinder* g_fileFinder;
struct FileFinder
{
    int GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return g_fileFinder;
    }
};
extern char* EmptyFS;
int _strcpy_s(char*, unsigned int, const char*);
int _strcat_s(char*, unsigned int, const char*);
inline NiFixedString& NiFixedString::operator=(const char* pc)
{
    if (m_kHandle != pc)
    {
        char* kHandle = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(pc);
        NiGlobalStringTable::DecRefCount(kHandle);
    }
    return *this;
}
inline const char* Setting::GetString()
{
    const char* r;
    if (this)
        r = *(const char**)&uValue;
    else
        r = 0;
    return r;
}
inline GO& GO::operator=(void* pObject)
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            ((NiTexture*)m_pObject)->DecRefCount();
        m_pObject = pObject;
        if (m_pObject)
            ((NiTexture*)m_pObject)->IncRefCount();
    }
    return *this;
}

namespace L {
struct NiTexturePtr
{
    NiTexture* m_pObject;
    NiTexturePtr(NiTexture* p = 0)
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiTexturePtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    bool operator==(const NiTexture* p) const
    {
        return m_pObject == p;
    }
};
}
bool fnv_NiStreamGetTexture(char*, L::NiTexturePtr*);

// Builds a Data\Textures\ path from apFilename, looks up the texture, and falls back to a default setting string if not found.
// @fnv 0x00a1f7d0
void ResolveTexturePath(const char* apFilename, float* afScale, float afZoom, char* axOut)
{
    if (!apFilename || !*apFilename || *apFilename == ' ')
        return;
    float aspect = TileimageInterfaceView::GetInterfaceFloat();
    *afScale = 1.0f;
    _strcpy_s(axOut, 260, "Data\\Textures\\");
    _strcat_s(axOut, 260, apFilename);
    L::NiTexturePtr sptex;
    NiFixedString path((const char*)axOut);
    fnv_NiStreamGetTexture(path.m_kHandle, &sptex);
    if (sptex == 0)
    {
        if (!FileFinder::GetSingleton()->GetFileLocation(axOut, axOut, 6, 0xffffffff))
        {
            if (*afScale != 1.0)
            {
                _strcpy_s(axOut, 260, "Data\\Textures\\");
                _strcat_s(axOut, 260, apFilename);
                if (FileFinder::GetSingleton()->GetFileLocation(axOut, 0, 6, 0xffffffff))
                    *afScale = 1.0f;
                else
                    _strcpy_s(axOut, 260, g_011d33f0.GetString());
            }
            else
            {
                _strcpy_s(axOut, 260, g_011d33f0.GetString());
            }
        }
    }
}

namespace fnv_00a1fa20 {
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 4 ? 1 : -1];

extern __declspec(thread) int OM06_tlsMemContext;
class BSFileEntry;
struct TextureFileEntrySetter
{
    static void __cdecl SetTexture(NiTexture*, const BSFileEntry*);
};
// Exe 0x00a1fa20: unit-local TileimageInterfaceView view used by this matched implementation.
struct TileimageInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*, ...);
};
class FileFinder;
extern FileFinder* g_fileFinder;
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FL_NONE
    };
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return g_fileFinder;
    }
};
extern NiTexture::TextureFormatPreferences DAT_011a9598;
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
void __cdecl ResolveTexturePath(const char*, float&, float, char*);
char* __cdecl FUN_00ec7750(const char*, const char*);
void __cdecl fnv_NiStreamGetTexture(const char*, NiPointer<NiTexture>&);
static inline int GetCurrentMemoryContext()
{
    return OM06_tlsMemContext;
}
static inline void SetCurrentMemoryContext(int context)
{
    OM06_tlsMemContext = context;
}
}  // namespace fnv_00a1fa20
inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = (MEM_CONTEXT)fnv_00a1fa20::GetCurrentMemoryContext();
    fnv_00a1fa20::SetCurrentMemoryContext(context);
}
inline AutoMemContext::~AutoMemContext()
{
    fnv_00a1fa20::SetCurrentMemoryContext(m_eMemoryContext);
}
namespace fnv_00a1fa20 {
// @fnv 0x00a1fa20
void __cdecl LoadTextureForFile(const char* apFilename, float& afScale, NiPointer<NiTexture>& aspTexture, float afZoom,
                                NiPointer<NiTexture> apDataImage)
{
    if (!apDataImage)
    {
        char acTexturePath[1024];
        acTexturePath[0] = 0;
        _fnv_zlib_memset(acTexturePath + 1, 0, 0x3ff);
        ResolveTexturePath(apFilename, afScale, afZoom, acTexturePath);
        if (acTexturePath[0])
        {
            NiFixedString path((const char*)acTexturePath);
            fnv_NiStreamGetTexture(path.m_kHandle, aspTexture);
            if (!aspTexture && FileFinder::GetSingleton()->GetFileLocation(acTexturePath, 0, 0, 0xffffffff))
            {
                path = (const char*)acTexturePath;
                AutoMemContext tempMemContext(0xd);
                ((GO*)&aspTexture)->operator=(NiSourceTexture::Create(path, DAT_011a9598, true, false));
                if (aspTexture)
                {
                    if (!FUN_00ec7750(acTexturePath, "oading\\load_"))
                        TextureFileEntrySetter::SetTexture((NiTexture*)aspTexture, 0);
                }
                else
                {
                    TileimageInterfaceView::PrintDebugMessage("*** ERROR: Could not create ptexture '%s'!", acTexturePath);
                }
            }
        }
    }
    else
    {
        aspTexture = apDataImage;
    }
    return;
}
}  // namespace fnv_00a1fa20

inline void NiNode::SetExtraBuffer(void* buffer)
{
    ((NiGeometry*)this)->m_spShader = (NiShader*)buffer;
}

namespace ImageNodeBuild {
extern void* __cdecl FUN_00aa13e0(unsigned int);
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

namespace ImageNodeBuild {
struct PropertyList
{
    void* head;
    void* tail;
    unsigned int count;
    void FUN_00439fd0(const NiPointer<NiNode>&);
};
}  // namespace ImageNodeBuild
inline void NiNode::FUN_00439410(NiNode* property)
{
    NiProperty* typedProperty = (NiProperty*)property;
    if (typedProperty->GetType() < 7)
    {
        NiPointer<NiNode> heldProperty(property);
        ((ImageNodeBuild::PropertyList*)&m_kPropertyList)->FUN_00439fd0(heldProperty);
    }
}
namespace ImageNodeBuild {
extern MemoryManager g_GameAllocator;
}  // namespace ImageNodeBuild

inline NiPoint3::NiPoint3(float vx, float vy, float vz) : x(vx), y(vy), z(vz)
{}

__forceinline void* __cdecl operator new[](size_t n)
{
    return ImageNodeBuild::g_GameAllocator.FUN_00aa3e40((unsigned)n);
}

inline NiPoint2::NiPoint2(float vx, float vy) : x(vx), y(vy)
{}

__forceinline void* NiPoint2::operator new[](size_t n)
{
    return ImageNodeBuild::g_GameAllocator.FUN_00aa3e40((unsigned)n);
}

namespace ImageNodeBuild {
extern void* __cdecl FUN_00aa1070(unsigned int);
extern void* __cdecl FUN_00aa13e0(unsigned int);
extern void* __cdecl FUN_00b55560(unsigned int);
extern void* __cdecl FUN_00706d30();
extern void* __cdecl FUN_00706df0();
extern void* __cdecl AttachFaceGenAnimationData(void*);
extern void __stdcall FUN_00706e00(unsigned int);
extern void __cdecl FUN_00707930(int);
extern unsigned int __cdecl FUN_00ec62c0();
extern void __cdecl FUN_00a5b690_(const char*);
struct FUN_00c5cf30
{
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0xd4);
    }
    FUN_00c5cf30(int, NiPoint3*, NiPoint3*, int, NiPoint2*, int, int, int, unsigned short*, int, int, unsigned int);
};
static __forceinline unsigned int GeometryTime()
{
    FUN_00706df0();
    FUN_00706e00(FUN_00ec62c0());
    return FUN_00ec62c0();
}
extern char DAT_010954cc[];
struct FUN_00a1f610 : NiExtraData
{
    void* tile;
    NiNode* node;
    static __forceinline void* operator new(size_t)
    {
        return FUN_00aa13e0(0x14);
    }
    FUN_00a1f610(void* owner, NiNode* model) : tile(owner), node(model)
    {
        SetName(NiFixedString((const char*)DAT_010954cc));
    }
};
extern void* __cdecl FUN_00a5b690(const char*);
extern char kGeometryName[];
static __forceinline void GD(NiNode* n)
{
    ((NiGeometry*)n)->m_spModelData->FUN_00a67050(0);
}
static __forceinline NiNode* AsN(NiNode* p)
{
    return p;
}

}  // namespace ImageNodeBuild

// Builds a quad geometry object, attaches it beneath a node returned by FUN_00a089c0() or a fallback, and returns the containing node.
// @fnv 0x00a1fd50
NiNode* TileImage::CalculateNode()
{
    using namespace ImageNodeBuild;
    NiNode* cnt_lgft;
    cnt_lgft = GetNiNode();
    NiPointer<NiNode> ptr_k;

    NiPoint3* vertices_nriq;
    vertices_nriq = new NiPoint3[4];
    void* s_xx;
    s_xx = 0;
    NiPoint2* extraBuffer_tjnslw;
    extraBuffer_tjnslw = new NiPoint2[4];
    unsigned short* indices_tyg;
    indices_tyg = static_cast<unsigned short*>(FUN_00aa1070(6 * sizeof(unsigned short)));
    NiPoint3* previous_zphzqj;
    previous_zphzqj = 0;

    vertices_nriq[0] = NiPoint3(0.0f, 0.0f, 0.0f);
    vertices_nriq[1] = NiPoint3(0.0f, 0.0f, -1.0f);
    vertices_nriq[2] = NiPoint3(1.0f, 0.0f, 0.0f);
    vertices_nriq[3] = NiPoint3(1.0f, 0.0f, -1.0f);
    indices_tyg[0] = 0;
    indices_tyg[1] = 1;
    indices_tyg[2] = 2;
    indices_tyg[3] = 2;
    indices_tyg[4] = 1;
    indices_tyg[5] = 3;

    extraBuffer_tjnslw[0] = NiPoint2(0.0f, 0.0f);
    extraBuffer_tjnslw[1] = NiPoint2(0.0f, 1.0f);
    extraBuffer_tjnslw[2] = NiPoint2(1.0f, 0.0f);
    extraBuffer_tjnslw[3] = NiPoint2(1.0f, 1.0f);

    if (IsTraitNonZero(0xfae))
    {
        ((GO*)&ptr_k)->operator=(
            (NiNode*)new FUN_00c5cf30(4, vertices_nriq, previous_zphzqj, 0, extraBuffer_tjnslw, 1, 0, 2, indices_tyg, 0,
                                      0, (FUN_00706df0(), FUN_00706e00(FUN_00ec62c0()), FUN_00ec62c0())));
        m_bTextureLoaded = true;
    }
    else
    {
        ((GO*)&ptr_k)->operator=(
            (NiNode*)new NiTriShape(4, vertices_nriq, previous_zphzqj, 0, extraBuffer_tjnslw, 1, 0, 2, indices_tyg));
        m_bTextureLoaded = false;
    }

    ptr_k->SetName(NiFixedString((const char*)kGeometryName));
    GD(ptr_k);

    ((GO*)&m_spShaderProperty)->operator=(
        new TileShaderProperty(false));
    ptr_k->FUN_00439410((NiNode*)(TileShaderProperty*)m_spShaderProperty);

    void* v_r;
    void* kIter_bw;
    kIter_bw = FUN_00b55560(0x20);
    v_r = kIter_bw;
    ptr_k->SetExtraBuffer(v_r);

    ((GO*)&m_pRenderedNodeEntry)->operator=(new NiNode(0));
    m_pRenderedNodeEntry->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)ptr_k, true);
    if (0 == cnt_lgft)
        cnt_lgft = (NiNode*)FUN_00706d30();
    cnt_lgft->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)m_pRenderedNodeEntry, true);

    m_pRenderedNodeEntry->SetName(NiFixedString((const char*)StringProvider.pString));
    AttachFaceGenAnimationData(ptr_k);
    m_pRenderedNodeEntry->FUN_00a5a040();
    FUN_00707930(1);

    m_pRenderedNodeEntry->SetExtraDataName(new FUN_00a1f610(this, (NiNode*)m_pRenderedNodeEntry));

    FUN_00a037e0(0xfad, FUN_00a011b0(0xfad, 0));
    if (IsTraitNonZero(0xfae))
        SetChangeFlag(0x100);
    SetChangeFlag(0x3d);
    return (NiNode*)m_pRenderedNodeEntry;
}
