#include "../../../../include/NiTListItem.h"
#include "../../../../include/NiTArray.h"
// gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderer.cpp: NiDX9Renderer, Renderer, GraphicsRenderer, NiTMapBaseStub and more (204 functions)

class NiRenderTargetGroup;
#include "niconsolerenderer_packet.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiVBSet.h"
#include "../../../../include/_D3DPRIMITIVETYPE.h"
#include "../../../../include/NiD3DDefaultShader.h"
#include "../../../../include/BSFaceGenModel.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/Bound.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/RecursiveSpinLock.h"
#include "../../../../include/NiAlphaProperty.h"
#include "../../../../include/NiVertexColorProperty.h"
#include "../../../../include/NiD3DHLSLVertexShader.h"
#include "../../../../include/NiD3DShaderInterface.h"
#include "../../../../include/NiDX9ShaderDeclaration.h"
#include "../../../../include/NiDX9Renderer.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiPixelData.h"
#include "../../../../include/NiPixelFormat.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiFrustum.h"
#include "../../../../include/NiPropertyState.h"
#include "../../../../include/NiShaderFactory.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTMap.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/_D3DFORMAT.h"
// RTTI at 0x010eda24 / 0x010edafc identifies the pre-pack map as
// NiTMapBase<NiTPointerAllocator<unsigned int>, NiVBBlock*, NiDX9Renderer::PrePackObject*>
// and NiTPointerMap<NiVBBlock*, NiDX9Renderer::PrePackObject*> respectively (7 slots).
// NiDX9Renderer.h must declare the nested PrePackObject before these can use the shared templates.
#include "../../../../include/NiTMapBaseStub.h"
class NiRenderedTexture;
class NiRenderedCubeMap;
class NiDynamicTexture;
class NiDX9RenderedTextureData;
class NiDX9RenderedCubeMapData;
class NiDX9DynamicTextureData;
struct HWND__;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, HWND__*, NiPointer<NiRenderTargetGroup> > RenderTargetMapBase;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, NiRenderedTexture*, NiDX9RenderedTextureData*> RenderedTextureMapBase;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, NiRenderedCubeMap*, NiDX9RenderedCubeMapData*> RenderedCubeMapBase;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, NiDynamicTexture*, NiDX9DynamicTextureData*> DynamicTextureMapBase;
typedef NiTMapBase<DFALL<NiTMapItem<_D3DFORMAT, NiPixelFormat*> >, _D3DFORMAT, NiPixelFormat*> PixelFormatMapBase;
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiDX9AdditionalDepthStencilBufferData.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiStream.h"
// These allocations have no constructor-failure cleanup in the original code.
enum PixelDataAllocationTag { AllocatePixelData };
__forceinline void* operator new(unsigned int size, PixelDataAllocationTag) { return NiPixelData::operator new(size); }
enum AlphaPropertyAllocationTag { AllocateAlphaProperty };
__forceinline void* operator new(unsigned int size, AlphaPropertyAllocationTag) { return NiAlphaProperty::operator new(size); }
// Preserve the original aggregate copy of the point's storage.
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)
__forceinline void CopyPoint3Storage(NiPoint3& dest, const NiPoint3& source)
{
    memcpy(&dest, &source, sizeof(NiPoint3));
}

#include "../../../../include/_D3DFORMAT.h"
struct RendererPacketEntry { unsigned int pad[2]; void* resource; };
#include "../../../../include/NiMemObject.h"
// NiPoint3_Custom_niconsolerenderer: local type (was include/NiPoint3_Custom.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiPoint3_Custom_niconsolerenderer
{
public:
    float x;
    float y;
    float z;

    NiPoint3_Custom_niconsolerenderer() {}
    NiPoint3_Custom_niconsolerenderer(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};
// NiRectF_niconsolerenderer: local type (was include/NiRectF.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiRectF_niconsolerenderer
{
public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
// NiRect_Custom_niconsolerenderer: local type (was include/NiRect_Custom.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiRect_Custom_niconsolerenderer
{
public:
    float m_fMinimumU;
    float m_fMaximumU;
    float m_fMinimumV;
    float m_fMaximumV;
};
// NiWorldToSkin_niconsolerenderer: local type (was include/NiWorldToSkin.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiWorldToSkin_niconsolerenderer
{
public:
    float r00;
    float r10;
    float r20;
    float tx;
    float r01;
    float r11;
    float r21;
    float ty;
    float r02;
    float r12;
    float r22;
    float tz;
    float pad[3];
    float scale;
};
class GraphicsRenderer : public NiMemObject {
public:
 virtual ~GraphicsRenderer() throw();
 GraphicsRenderer() throw();
 unsigned int pad[7]; unsigned int count; unsigned int pad24; RendererPacketEntry** entries;
 __declspec(noinline) bool HasPendingPackets();
 static const char* GetD3DFormatName(_D3DFORMAT);
 char remaining[0xb80-44];
 static GraphicsRenderer* Create(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
 bool Create(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
};
template<class T> class PoolAllocatorBase {
public:
 struct LinkedListEntry { LinkedListEntry* next; LinkedListEntry* prev; char* data; };
 static LinkedListEntry* ms_pFreeList;
 static RecursiveSpinLock ms_kPoolState;
};
extern unsigned int DAT_011c5f84;
template<class T> class ConsolePointerAllocator {};
template<class Alloc, class T> class ConsolePointerListBase {
public:
 typedef PoolAllocatorBase<unsigned int>::LinkedListEntry Node;
 Node* head; Node* tail; unsigned int count;
 T RemoveTail();
};

class ShaderPassRenderer { public: static unsigned int Create(unsigned int); };
extern "C" int fnv_CopyFilePath(char*,unsigned int,const char*,unsigned int);
extern char DAT_011f4648[256];
NiObject* NiPersistentSrcTextureRendererDataLoader();

extern const char DAT_010ee6c8[];
extern const char DAT_010ee688[];
extern const char DAT_0109f0a0[];

extern const char DAT_01015890[];
extern const char DAT_010ee8a4[];
extern const char DAT_010ee8b0[];
extern const char DAT_010ee8c4[];
extern const char DAT_010ee8d0[];
extern const char DAT_010ee8e4[];
extern const char DAT_010ee8f0[];
extern const char DAT_010ee8fc[];
extern const char DAT_010ee908[];
extern const char DAT_010ee914[];
extern const char DAT_010ee920[];
extern const char DAT_010ee934[];
extern const char DAT_010ee944[];
extern const char DAT_010ee95c[];
extern const char DAT_010ee96c[];
extern const char DAT_010ee978[];
extern const char DAT_010ee990[];
extern const char DAT_010ee9a0[];
extern const char DAT_010ee9ac[];
extern const char DAT_010ee9c0[];
extern const char DAT_010ee9d0[];
extern const char DAT_010ee9e0[];
extern const char DAT_010ee9f4[];
extern const char DAT_010eea00[];
extern const char DAT_010eea10[];
extern const char DAT_010eea28[];
extern const char DAT_010eea34[];
extern const char DAT_010eea44[];
extern const char DAT_010eea54[];
extern const char DAT_010eea64[];
extern const char DAT_010eea74[];
extern const char DAT_010eea80[];
extern const char DAT_010eea94[];
extern const char DAT_010eeaa8[];
extern const char DAT_010eeab8[];
extern const char DAT_010eeac8[];
extern const char DAT_010eead8[];
extern const char DAT_010eeae8[];
extern const char DAT_010eeaf4[];
extern const char DAT_010eeb00[];
extern const char DAT_010eeb0c[];
extern const char DAT_010eeb18[];
extern const char DAT_010eeb24[];
extern const char DAT_010eeb30[];
extern const char DAT_010eeb44[];
extern const char DAT_010eeb58[];
extern const char DAT_010eeb68[];
extern const char DAT_010eeb78[];
extern const char DAT_010eeb88[];
extern const char DAT_010eeb9c[];
extern const char DAT_010eebac[];
extern const char DAT_010eebbc[];
extern const char DAT_010eebc8[];
extern const char DAT_010eebd8[];
extern const char DAT_010eebe8[];
extern const char DAT_010eebf8[];
extern const char DAT_010eec08[];
extern const char DAT_010eec18[];
extern const char DAT_010eec28[];
extern const char DAT_010eec38[];

// Returns false if count is zero or any entry or its resource is null; otherwise returns true.
// @fnv 0x00e8eeb0
bool GraphicsRenderer::HasPendingPackets() {
 unsigned int n = count;
 if (!n) return false;
 for (unsigned int i = 0; i < n; ++i) {
  if (!entries[i] || !entries[i]->resource) return false;
 }
 return true;
}
// Removes the tail node from the list, unlinks it, clears its data, returns the stored pointer, and decrements the count.
// Removes the last node from the list, returns its data pointer, and recycles the node into the allocator's free list.
// @fnv 0x00e7d5b0
template<>
char* ConsolePointerListBase<ConsolePointerAllocator<unsigned int>,char*>::RemoveTail() {
 Node* node = tail;
 tail = node->prev;
 if (tail) tail->next = 0;
 else head = 0;
 char* result = node->data;
 node->data = 0;
 PoolAllocatorBase<unsigned int>::ms_kPoolState.Lock(0);
 node->prev = 0;
 node->next = PoolAllocatorBase<unsigned int>::ms_pFreeList;
 PoolAllocatorBase<unsigned int>::ms_pFreeList = node;
 if (--DAT_011c5f84 == 0) PoolAllocatorBase<unsigned int>::ms_kPoolState.m_uiOwningThreadID = 0;
 --count;
 return result;
}

// @fnv 0x00e76210
GraphicsRenderer* GraphicsRenderer::Create(unsigned int auiArg1,unsigned int auiArg2,unsigned int auiArg3,unsigned int auiArg4,unsigned int auiArg5,unsigned int auiArg6,unsigned int auiArg7,unsigned int auiArg8,unsigned int auiArg9,unsigned int auiArg10,unsigned int auiArg11,unsigned int auiArg12,unsigned int auiArg13,unsigned int auiArg14,unsigned int auiArg15) {
 if (ShaderPassRenderer::Create(auiArg15) == ~0u) {
  fnv_CopyFilePath(DAT_011f4648,256,DAT_010ee6c8,255);
  NiD3DDefaultShader::SetShaderName(DAT_010ee688);
  return 0;
 }
 GraphicsRenderer* renderer = new GraphicsRenderer;
 if (!renderer->Create(auiArg1,auiArg2,auiArg3,auiArg4,auiArg5,auiArg6,auiArg7,auiArg8,auiArg9,auiArg10,auiArg11,auiArg12,auiArg13,auiArg14)) {
  delete renderer;
  renderer = 0;
 } else {
 NiStream::UnregisterObjectLoader(DAT_0109f0a0);
 NiStream::RegisterObjectLoader(DAT_0109f0a0,NiPersistentSrcTextureRendererDataLoader);
 }
 return renderer;
}

// @fnv 0x00e7a9a0
const char* GraphicsRenderer::GetD3DFormatName(_D3DFORMAT format) {
 switch (format) {
 case 0x14: return DAT_010eec38;
 case 0x15: return DAT_010eec28;
 case 0x16: return DAT_010eec18;
 case 0x17: return DAT_010eec08;
 case 0x18: return DAT_010eebf8;
 case 0x19: return DAT_010eebe8;
 case 0x1a: return DAT_010eebd8;
 case 0x1b: return DAT_010eebc8;
 case 0x1c: return DAT_010eebbc;
 case 0x1d: return DAT_010eebac;
 case 0x1e: return DAT_010eeb9c;
 case 0x1f: return DAT_010eeb88;
 case 0x20: return DAT_010eeb78;
 case 0x21: return DAT_010eeb68;
 case 0x22: return DAT_010eeb58;
 case 0x23: return DAT_010eeb44;
 case 0x24: return DAT_010eeb30;
 case 0x28: return DAT_010eeb24;
 case 0x29: return DAT_010eeb18;
 case 0x32: return DAT_010eeb0c;
 case 0x33: return DAT_010eeb00;
 case 0x34: return DAT_010eeaf4;
 case 0x3c: return DAT_010eeae8;
 case 0x3d: return DAT_010eead8;
 case 0x3e: return DAT_010eeac8;
 case 0x3f: return DAT_010eeab8;
 case 0x40: return DAT_010eeaa8;
 case 0x43: return DAT_010eea94;
 case 0x46: return DAT_010eea80;
 case 0x47: return DAT_010eea74;
 case 0x49: return DAT_010eea64;
 case 0x4b: return DAT_010eea54;
 case 0x4d: return DAT_010eea44;
 case 0x4f: return DAT_010eea34;
 case 0x50: return DAT_010eea28;
 case 0x52: return DAT_010eea10;
 case 0x53: return DAT_010eea00;
 case 0x51: return DAT_010ee9f4;
 case 0x64: return DAT_010ee9e0;
 case 0x65: return DAT_010ee9d0;
 case 0x66: return DAT_010ee9c0;
 case 0x6e: return DAT_010ee9ac;
 case 0x6f: return DAT_010ee9a0;
 case 0x70: return DAT_010ee990;
 case 0x71: return DAT_010ee978;
 case 0x72: return DAT_010ee96c;
 case 0x73: return DAT_010ee95c;
 case 0x74: return DAT_010ee944;
 case 0x75: return DAT_010ee934;
 case 0x3154454d: return DAT_010ee920;
 case 0x31545844: return DAT_010ee908;
 case 0x32545844: return DAT_010ee914;
 case 0x32595559: return DAT_010ee8fc;
 case 0x33545844: return DAT_010ee8f0;
 case 0x34545844: return DAT_010ee8e4;
 case 0x35545844: return DAT_010ee8c4;
 case 0x42475247: return DAT_010ee8d0;
 case 0x47424752: return DAT_010ee8b0;
 case 0x59565955: return DAT_010ee8a4;
 default: return DAT_01015890;
 }
}

extern "C" void* g_011f4430;

// @fnv 0x00a5f200
// src: COMMUNITY 0x00a5f200
void* __cdecl NiVertexColorProperty_GetRTTI()
{
    return &g_011f4430;
}

extern "C" int g_011f443c;

// @fnv 0x00a5f4f0
// src: COMMUNITY 0x00a5f4f0
int __cdecl NiZBufferProperty_GetRTTI()
{
    return (int)&g_011f443c;
}

// @fnv 0x00a5f500
// src: COMMUNITY 0x00a5f500
int __cdecl NiZBufferProperty_GetType_0()
{
    return 0xb;
}

// @fnv 0x00dc9e60
// src: GUESS 0x00dc9e60 (confidence: low)
int __cdecl Object_ComputeValue_00dc9e60()
{
    return 10;
}


// @fnv 0x00e695e0
// src: COMMUNITY 0x00e695e0
unsigned int __fastcall NiDX9Renderer_GetMaxBuffersPerRenderTargetGroup(NiDX9Renderer* self, void*)
{
    return self->uiMaxBuffersPerRenderTargetGroup;
}

struct FUN_00e695f0_shell {
    char pad[0x8a4];
    unsigned char flag;
    unsigned char NiDX9Renderer_GetIndependentBufferBitDepths();
};

// @fnv 0x00e695f0
// src: COMMUNITY 0x00e695f0
unsigned char FUN_00e695f0_shell::NiDX9Renderer_GetIndependentBufferBitDepths()
{
    return flag;
}

struct FUN_00e69600_shell
{
    unsigned int __thiscall NiDX9Renderer_GetDefaultRenderTargetGroup();
};

// @fnv 0x00e69600
// src: COMMUNITY 0x00e69600
unsigned int __thiscall FUN_00e69600_shell::NiDX9Renderer_GetDefaultRenderTargetGroup()
{
    return reinterpret_cast<unsigned int*>(this)[0x221];
}

struct FUN_00e69900_shell {
    void SetTwoValues(unsigned int a, unsigned int b);
};

// @fnv 0x00e69900
void FUN_00e69900_shell::SetTwoValues(unsigned int uiFirst, unsigned int uiSecond)
{
    *(unsigned int*)((char*)this + 0x628) = uiFirst;
    *(unsigned int*)((char*)this + 0x62C) = uiSecond;
}

// Copies path into the global file path buffer (max 0xff chars) when path is non-null, otherwise clears the first byte.
// @fnv 0x00e69ad0
// src: COMMUNITY 0x00e69ad0
void NiDX9Renderer_SetLastErrorString(const char* path)
{
    if (path)
    {
        fnv_CopyFilePath((char*)DAT_011f4648, 0x100, path, 0xff);
    }
    else
    {
        DAT_011f4648[0] = 0;
    }
}

struct FUN_00e69b40_shell {
    unsigned int pad[8];
    unsigned int count;
    unsigned int pad24;
    unsigned int* entries;
    unsigned int GetEntry(unsigned int index);
};

// @fnv 0x00e69b40
unsigned int FUN_00e69b40_shell::GetEntry(unsigned int index)
{
    if (index < count)
        return entries[index];
    return 0;
}

// Maps an index to a constant value via a switch, returning 0 for unmapped or default cases.
// @fnv 0x00e69c90
unsigned int GetValueForIndex(unsigned int uiIndex)
{
    switch (uiIndex) {
    case 0: return 0;
    case 1: return 0x14;
    case 2: case 3: return 0x16;
    case 4: return 0x17;
    case 5: case 6: return 0x18;
    case 7: case 0xb: return 0x1e;
    case 8: return 0x1b;
    case 9: case 0xa: return 0;
    default: return 0;
    }
}


extern NiPoint3 DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f4754;





// @fnv 0x00e6b8f0
void __cdecl BuildWorldToSkinTransform(NiWorldToSkin_niconsolerenderer* out, const NiTransform* kWorldToRootParent, const NiPoint3* apTranslation, float fScale) {
    out->r00 = kWorldToRootParent->m_Rotate.m_pEntry[0][0] * fScale;
    out->r10 = kWorldToRootParent->m_Rotate.m_pEntry[0][1] * fScale;
    out->r20 = kWorldToRootParent->m_Rotate.m_pEntry[0][2] * fScale;
    out->tx = apTranslation->x;
    out->r01 = kWorldToRootParent->m_Rotate.m_pEntry[1][0] * fScale;
    out->r11 = kWorldToRootParent->m_Rotate.m_pEntry[1][1] * fScale;
    out->r21 = kWorldToRootParent->m_Rotate.m_pEntry[1][2] * fScale;
    out->ty = apTranslation->y;
    out->r02 = kWorldToRootParent->m_Rotate.m_pEntry[2][0] * fScale;
    out->r12 = kWorldToRootParent->m_Rotate.m_pEntry[2][1] * fScale;
    out->r22 = kWorldToRootParent->m_Rotate.m_pEntry[2][2] * fScale;
    out->tz = apTranslation->z;
    out->tx = apTranslation->x - DAT_011f474c.x;
    out->ty = apTranslation->y - DAT_011f4750;
    out->tz = apTranslation->z - DAT_011f4754;
    out->scale = 1.0f;
}

extern int DAT_0126efc0;

// @fnv 0x00e6c760
// src: COMMUNITY 0x00e6c760
bool __stdcall NiDX9Renderer_SetMipmapSkipLevel(int value)
{
    DAT_0126efc0 = value;
    return true;
}

namespace fnv_00e6c770 {
extern unsigned int DAT_0126efc0;

// @fnv 0x00e6c770
// src: COMMUNITY 0x00e6c770
unsigned int __cdecl NiDX9Renderer_GetMipmapSkipLevel()
{
    return DAT_0126efc0;
}
}  // namespace fnv_00e6c770

void __cdecl _NiAlignedFree(void*);

// @fnv 0x00e6d740
// src: COMMUNITY 0x00e6d740
void __stdcall NiDX9Renderer_PurgeSkinInstance(void* apObject)
{
    void* p = *(void**)((char*)apObject + 0x28);
    _NiAlignedFree(p);
    *(void**)((char*)apObject + 0x28) = 0;
    *(void**)((char*)apObject + 0x24) = 0;
}

extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;

struct LinkedListEntry { LinkedListEntry* next; LinkedListEntry* prev; char* data; };

// @fnv 0x00e6e8a0
// src: COMMUNITY 0x00e6e8a0
void __stdcall NiTPointerListBase_DeleteItem(LinkedListEntry* pNode)
{
    pNode->data = 0;
    g_011c5f80.Lock(0);
    pNode->prev = 0;
    pNode->next = (LinkedListEntry*)PoolAllocatorBase<unsigned int>::ms_pFreeList;
    --DAT_011c5f84;
    PoolAllocatorBase<unsigned int>::ms_pFreeList = (PoolAllocatorBase<unsigned int>::LinkedListEntry*)pNode;
    if (!DAT_011c5f84)
        g_011c5f80.m_uiOwningThreadID = 0;
}



extern "C" void __cdecl _NiFreeAlias(void*);
extern "C" void* __cdecl _DeallocateAlias(void*);
extern int DAT_010eda84;
extern int DAT_010edb5c;
extern MemoryManager g_memoryManager;



// @fnv 0x00e6eab0
int __fastcall DestroyMap(NiTPointerMap<NiRenderedCubeMap*, NiDX9RenderedCubeMapData*>* self, void*, int aiFlags)
{
    *(int*)self = (int)&DAT_010edb5c;
    self->RemoveAll();
    *(int*)self = (int)&DAT_010eda84;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (aiFlags & 1)
        g_memoryManager.Deallocate(self);
    return (int)self;
}

struct NodePoolView {
    void* AddHead();
};

// The pointer-map instantiations share this allocator thunk in the game.
// @fnv 0x00e72e50
template<>
NiTMapItem<NiDynamicTexture*, NiDX9DynamicTextureData*>*
NiTPointerMap<NiDynamicTexture*, NiDX9DynamicTextureData*>::NewItem() {
    return static_cast<NiTMapItem<NiDynamicTexture*, NiDX9DynamicTextureData*>*>(m_kItemCount.Allocate());
}

extern "C" void* g_0126f0f0;

// @fnv 0x00e757b0
// src: COMMUNITY 0x00e757b0
void* __cdecl NiDX9Renderer_GetRTTI()
{
    return &g_0126f0f0;
}

struct FUN_00e757c0_shell {
    unsigned char* data;
    unsigned char NiDX9Renderer_IsVerticalDisplay();
};

// @fnv 0x00e757c0
// src: COMMUNITY 0x00e757c0
unsigned char __thiscall FUN_00e757c0_shell::NiDX9Renderer_IsVerticalDisplay()
{
    return *(reinterpret_cast<unsigned char*>(this) + 0xad0);
}

namespace fnv_00e757d0 {


// @fnv 0x00e757d0
// src: COMMUNITY 0x00e757d0
unsigned int __fastcall NiDX9Renderer_GetFlags(NiDX9Renderer* self, void*)
{
    return self->uiFlags;
}
}  // namespace fnv_00e757d0

namespace fnv_00e75810 {


// @fnv 0x00e75810
// src: COMMUNITY 0x00e75810
void* __fastcall NiDX9Renderer_GetCurrentRenderTargetGroup(NiDX9Renderer* self, void*)
{
    return self->pCurrentRenderTargetGroup;
}
}  // namespace fnv_00e75810

namespace fnv_00e75820 {


// @fnv 0x00e75820
// src: COMMUNITY 0x00e75820
void __fastcall NiDX9Renderer_SetDepthClear(NiDX9Renderer* self, void*, float fValue)
{
    self->fDepthClear = fValue;
}
}  // namespace fnv_00e75820

struct FUN_00e75830_shell : GraphicsRenderer {
    float GetSomeFloat();
};

// @fnv 0x00e75830
float FUN_00e75830_shell::GetSomeFloat()
{
    return *(float*)((char*)this + 0x5e4);
}

struct FUN_00e75840_shell {
    unsigned int pad[0x5e0/4];
    unsigned int color;
    void NiDX9Renderer_SetBackgroundColor(float* param);
};

// @fnv 0x00e75840
// src: COMMUNITY 0x00e75840
void __thiscall FUN_00e75840_shell::NiDX9Renderer_SetBackgroundColor(float* afColor)
{
    double f = (double)afColor[0];
    double r = f * 255.0;
    unsigned int r1 = (unsigned int)(unsigned char)r;

    double g = (double)afColor[1];
    double fGreenScaled = g * 255.0;
    unsigned int r2 = (unsigned int)(unsigned char)fGreenScaled;

    double b = (double)afColor[2];
    double fBlueScaled = b * 255.0;
    unsigned int r3 = (unsigned int)(unsigned char)fBlueScaled;

    unsigned int color = ((r1 | 0xffffff00u) << 8 | r2) << 8 | r3;
    this->color = color;
}

namespace fnv_00e75a20 {


// @fnv 0x00e75a20
// src: COMMUNITY 0x00e75a20
void __fastcall NiDX9Renderer_SetStencilClear(NiDX9Renderer* self, void*, unsigned int value)
{
    self->uiStencilClear = value;
}
}  // namespace fnv_00e75a20

namespace fnv_00e75a30 {


// @fnv 0x00e75a30
// src: COMMUNITY 0x00e75a30
unsigned int __fastcall NiDX9Renderer_GetStencilClear(NiDX9Renderer* self, void*)
{
    return self->uiStencilClear;
}
}  // namespace fnv_00e75a30

extern "C" void* g_01270900;

// @fnv 0x00e766f0
// src: COMMUNITY 0x00e766f0
void* __cdecl NiShaderDeclaration_GetRTTI()
{
    return &g_01270900;
}

struct FUN_00e758f0_shell {
    void PackColorToUInt(float* floats);
};

// Converts four floats scaled by 255 into bytes and packs them into a single unsigned int stored at this+0x5e0.
// @fnv 0x00e758f0
void FUN_00e758f0_shell::PackColorToUInt(float* afComponents)
{
    unsigned int result = 0;
    result = (unsigned char)(afComponents[3] * 255.0f);
    result = (result << 8) | (unsigned char)(afComponents[0] * 255.0f);
    result = (result << 8) | (unsigned char)(afComponents[1] * 255.0f);
    result = (result << 8) | (unsigned char)(afComponents[2] * 255.0f);
    *(unsigned int*)((unsigned char*)this + 0x5e0) = result;
}

extern int DAT_0126f580[];

// If param2 is non-zero and its entry in DAT_0126f580 is set, calls the object's vtable slot 0x25 with (param1, param2, 0) and clears the entry.
// @fnv 0x00e7cc50
// src: GAMEBRYO_LIB 0x00e7cc50
void __cdecl NiDX92DBufferData_ClearRenderTarget(int* pObject, int iIndex)
{
    if (iIndex != 0 && DAT_0126f580[iIndex] != 0)
    {
        void* obj = *reinterpret_cast<void**>(pObject);
        void (__stdcall* func)(int*, int, int) = reinterpret_cast<void (__stdcall*)(int*, int, int)>(
            reinterpret_cast<void**>(obj)[0x25]);
        func(pObject, iIndex, 0);
        DAT_0126f580[iIndex] = 0;
    }
}

extern "C" void __cdecl ReleaseShaderNodes(void*);
struct FUN_00e69650_shell {
    bool __thiscall NiDX9Renderer_PurgeAllTextures(int);
};
// @fnv 0x00e69650
// src: GAMEBRYO_LIB 0x00e69650
bool __thiscall FUN_00e69650_shell::NiDX9Renderer_PurgeAllTextures(int)
{
    ReleaseShaderNodes(this);
    return true;
}

struct IDev
{
    virtual int __stdcall f00() = 0;
    virtual int __stdcall f01() = 0;
    virtual int __stdcall f02() = 0;
    virtual int __stdcall f03() = 0;
    virtual int __stdcall f04() = 0;
    virtual int __stdcall f05() = 0;
    virtual int __stdcall f06() = 0;
    virtual int __stdcall f07() = 0;
    virtual int __stdcall f08() = 0;
    virtual int __stdcall f09() = 0;
    virtual int __stdcall f10() = 0;
    virtual int __stdcall f11() = 0;
    virtual int __stdcall f12() = 0;
    virtual int __stdcall f13() = 0;
    virtual int __stdcall f14() = 0;
    virtual int __stdcall f15() = 0;
    virtual int __stdcall f16() = 0;
    virtual int __stdcall f17() = 0;
    virtual int __stdcall f18() = 0;
    virtual int __stdcall f19() = 0;
    virtual int __stdcall f20() = 0;
    virtual int __stdcall f21() = 0;
    virtual int __stdcall f22() = 0;
    virtual int __stdcall f23() = 0;
    virtual int __stdcall f24() = 0;
    virtual int __stdcall f25() = 0;
    virtual int __stdcall f26() = 0;
    virtual int __stdcall f27() = 0;
    virtual int __stdcall f28() = 0;
    virtual int __stdcall f29() = 0;
    virtual int __stdcall f30() = 0;
    virtual int __stdcall f31() = 0;
    virtual int __stdcall f32() = 0;
    virtual int __stdcall f33() = 0;
    virtual int __stdcall f34() = 0;
    virtual int __stdcall f35() = 0;
    virtual int __stdcall f36() = 0;
    virtual int __stdcall f37() = 0;
    virtual int __stdcall f38() = 0;
    virtual int __stdcall f39() = 0;
    virtual int __stdcall f40() = 0;
    virtual int __stdcall f41() = 0;
    virtual int __stdcall EndScene() = 0;
};
struct FUN_00e8bf80_shell { void __thiscall NiDX9VertexBufferManager_EndFrame(); };
struct FUN_00e69660_shell
{
    char _p0[0x288];
    IDev* dev;
    char _p1[0x470];
    unsigned char f6fc;
    char _p2[0x1BF];
    FUN_00e8bf80_shell* h8bc;
    bool __thiscall EndSceneIfNeeded();
};
// If f6fc is zero, calls dev->EndScene() and returns false when it fails, otherwise calls h8bc->FUN_00e8bf80(); returns true.
// @fnv 0x00e69660
bool __thiscall FUN_00e69660_shell::EndSceneIfNeeded()
{
    if (f6fc == 0) {
        if (dev->EndScene() < 0)
            return false;
        h8bc->NiDX9VertexBufferManager_EndFrame();
    }
    return true;
}

struct Dev
{
 virtual void __stdcall f0();
 virtual void __stdcall f1();
 virtual void __stdcall f2();
 virtual void __stdcall f3();
 virtual void __stdcall f4();
 virtual void __stdcall f5();
 virtual void __stdcall f6();
 virtual void __stdcall f7();
 virtual void __stdcall f8();
 virtual void __stdcall f9();
 virtual void __stdcall f10();
 virtual void __stdcall f11();
 virtual void __stdcall f12();
 virtual void __stdcall f13();
 virtual void __stdcall f14();
 virtual void __stdcall f15();
 virtual void __stdcall f16();
 virtual void __stdcall f17();
 virtual void __stdcall f18();
 virtual void __stdcall f19();
 virtual void __stdcall f20();
 virtual void __stdcall f21();
 virtual void __stdcall f22();
 virtual void __stdcall f23();
 virtual void __stdcall f24();
 virtual void __stdcall f25();
 virtual void __stdcall f26();
 virtual void __stdcall f27();
 virtual void __stdcall f28();
 virtual void __stdcall f29();
 virtual void __stdcall f30();
 virtual void __stdcall f31();
 virtual void __stdcall f32();
 virtual void __stdcall f33();
 virtual void __stdcall f34();
 virtual void __stdcall f35();
 virtual void __stdcall f36();
 virtual void __stdcall f37();
 virtual void __stdcall f38();
 virtual void __stdcall f39();
 virtual void __stdcall f40();
 virtual void __stdcall f41();
 virtual void __stdcall f42();
 virtual void __stdcall f43();
 virtual void __stdcall f44();
 virtual void __stdcall f45();
 virtual void __stdcall f46();
 virtual void __stdcall f47();
 virtual void __stdcall f48();
 virtual void __stdcall f49();
 virtual void __stdcall f50();
 virtual void __stdcall f51();
 virtual void __stdcall f52();
 virtual void __stdcall f53();
 virtual void __stdcall f54();
 virtual void __stdcall f55();
 virtual void __stdcall f56();
 virtual void __stdcall f57();
 virtual void __stdcall f58();
 virtual void __stdcall f59();
 virtual void __stdcall f60();
 virtual void __stdcall f61();
 virtual void __stdcall f62();
 virtual void __stdcall f63();
 virtual void __stdcall f64();
 virtual void __stdcall f65();
 virtual void __stdcall f66();
 virtual void __stdcall f67();
 virtual void __stdcall f68();
 virtual void __stdcall f69();
 virtual void __stdcall f70();
 virtual void __stdcall f71();
 virtual void __stdcall f72();
 virtual void __stdcall f73();
 virtual void __stdcall f74();
 virtual void __stdcall f75();
 virtual void __stdcall f76();
 virtual void __stdcall f77();
 virtual void __stdcall f78();
 virtual void __stdcall f79();
 virtual void __stdcall f80();
 virtual void __stdcall f81();
 virtual int __stdcall DrawIndexedPrimitive(int a1, int a2, int a3, int a4, int a5, int a6);
};
struct RendererHolder
{
 int __thiscall NiDX9Renderer_DrawIndexedPrimitive_TRIANGLELIST(int a1, int a2, int a3, int a4);
};
// Forwards the four arguments to the Dev at offset 0x288, calling DrawIndexedPrimitive with primitive type 4 and returns its result.
// @fnv 0x00e698a0
// src: COMMUNITY 0x00e698a0
int __thiscall RendererHolder::NiDX9Renderer_DrawIndexedPrimitive_TRIANGLELIST(int a1, int aiVertexCount, int a3, int aiPrimitiveCount)
{
 Dev* dev = *(Dev**)((char*)this + 0x288);
 return dev->DrawIndexedPrimitive(4, a1, 0, aiVertexCount, a3, aiPrimitiveCount);
}

struct FUN_00e698d0_shell { char _pad[0x288]; void* m_pDirectInputDevice; void DispatchToVTableSlot82(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4); };
// @fnv 0x00e698d0
void FUN_00e698d0_shell::DispatchToVTableSlot82(unsigned int auiArg1, unsigned int auiArg2, unsigned int auiArg3, unsigned int auiArg4)
{
	((int (__stdcall *)(void*, int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))((void**)*(void**)m_pDirectInputDevice)[82])(m_pDirectInputDevice, 5, auiArg1, 0, auiArg2, auiArg3, auiArg4);
}

struct FUN_00e69970_shell { void ClearShader(void* pkShader); };
// @fnv 0x00e69970
void FUN_00e69970_shell::ClearShader(void* pkShader)
{
	typedef void (__thiscall *MgrFn)(void*, int, int);
	typedef void* (__thiscall *GetFn)(void*);
	typedef unsigned long (__stdcall *RelFn)(void*);
	typedef void (__thiscall *SetFn)(void*, int);
	void* pMgr = *(void**)((char*)this + 0x8b8);
	((MgrFn)(*(void***)pMgr)[35])(pMgr, 0, 0);
	void* pkShaderHandle = ((GetFn)(*(void***)pkShader)[33])(pkShader);
	if (pkShaderHandle)
		((RelFn)(*(void***)pkShaderHandle)[2])(pkShaderHandle);
	((SetFn)(*(void***)pkShader)[34])(pkShader, 0);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
int __cdecl NiDX9SourceTextureData_Create(void*, void*);
struct StandIn_e6dc40 { bool NiDX9Renderer_CreateSourceTexture(void*); };
// Locks the critical section at this+0x180, reads the int at a1+0x24, computes it via FUN_00e68ef0 if zero, unlocks, and returns it.
// @fnv 0x00e6dc40
// src: COMMUNITY 0x00e6dc40
bool StandIn_e6dc40::NiDX9Renderer_CreateSourceTexture(void* a1)
{
	EnterCriticalSection((void*)((char*)this + 0x180));
	int v = *(int*)((char*)a1 + 0x24);
	if (!v)
		v = NiDX9SourceTextureData_Create(a1, this);
	LeaveCriticalSection((void*)((char*)this + 0x180));
	return v;
}

int __cdecl CreateRenderedTextureData(void*, void*, unsigned int);
struct Param_00e6dc80 { unsigned int pad[9]; unsigned int flag; };
struct Stand_00e6dc80 { char pad[0x8cc]; NiVBSet vb; bool CreateVertexBufferIfNeeded(Param_00e6dc80*, unsigned int); };
// @fnv 0x00e6dc80
bool Stand_00e6dc80::CreateVertexBufferIfNeeded(Param_00e6dc80* pParam, unsigned int a2)
{
    if (pParam->flag == 0) {
        int r = CreateRenderedTextureData(pParam, this, a2);
        if (!r)
            return false;
        vb.Create((unsigned int)pParam, (void*)r);
    }
    return true;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
int __cdecl NiDX9SourceCubeMapData_Create(void*, void*);
struct FUN_00e6dcc0_shell { bool __thiscall NiDX9Renderer_CreateSourceCubeMap(void*); };
// Locks the critical section at this+0x180, returns true if a1+0x24 is nonzero, otherwise calls FUN_00e8abf0(a1, this) and unlocks before returning its result.
// @fnv 0x00e6dcc0
// src: COMMUNITY 0x00e6dcc0
bool __thiscall FUN_00e6dcc0_shell::NiDX9Renderer_CreateSourceCubeMap(void* a1)
{
	EnterCriticalSection((void*)((char*)this + 0x180));
	if (*(int*)((char*)a1 + 0x24) != 0)
		return true;
	int r = NiDX9SourceCubeMapData_Create(a1, this);
	LeaveCriticalSection((void*)((char*)this + 0x180));
	return r;
}

namespace fnv_00e6dd00 {
void* __cdecl NiDX9RenderedCubeMapData_Create(void*, void*);
struct ProxyRenderer { bool __thiscall EnsureVertexBufferSet(void*); };
// @fnv 0x00e6dd00
bool __thiscall ProxyRenderer::EnsureVertexBufferSet(void* a1)
{
    if (*(unsigned int*)((char*)a1 + 0x24) == 0) {
        void* v = NiDX9RenderedCubeMapData_Create(a1, this);
        if (!v)
            return false;
        ((NiVBSet*)((char*)this + 0x8dc))->Create((unsigned int)a1, v);
    }
    return true;
}
}  // namespace fnv_00e6dd00

namespace fnv_00e6dd40 {
struct Inner {
 virtual int f0(); virtual int f1(); virtual int f2(); virtual int f3(); virtual int f4();
 virtual int f5(); virtual int f6(); virtual int f7(); virtual int f8(); virtual int f9();
 virtual int f10(); virtual int f11(); virtual int f12(); virtual int f13(); virtual int f14();
 virtual int f15(); virtual int f16(); virtual int f17(); virtual int f18(); virtual int f19();
 virtual int f20(); virtual int f21(); virtual int f22(); virtual int f23(); virtual int f24();
 virtual int f25(); virtual int f26(); virtual int f27(); virtual int f28(); virtual int f29();
 virtual int f30(); virtual int f31(); virtual int f32(); virtual int f33(); virtual int f34();
 virtual int f35(); virtual int f36(); virtual int f37(); virtual int f38(); virtual int f39();
 virtual int f40(); virtual int f41(); virtual int f42(); virtual int IsReady();
};
struct Prm { char pad[0x24]; Inner* ptr; };
void* __cdecl CreateDynamicTexture(Prm*);
struct FUN_00e6dd40_shell { char pad[0x8ec]; NiVBSet vb; bool __thiscall EnsureVertexBufferReady(Prm*); };
// Checks whether the Prm's Inner is ready; if not, obtains a buffer via CreateDynamicTexture and creates the vertex buffer set from it, returning success.
// @fnv 0x00e6dd40
bool __thiscall FUN_00e6dd40_shell::EnsureVertexBufferReady(Prm* pPrm)
{
 Inner* b = pPrm->ptr;
 if (b && b->IsReady())
  return true;
 void* c = CreateDynamicTexture(pPrm);
 if (!c)
  return false;
 vb.Create((unsigned int)pPrm, c);
 return true;
}
}  // namespace fnv_00e6dd40


extern int DAT_010eda24;
extern MemoryManager g_memoryManager;

// Initializes f00 to DAT_010eda24, clears the map, frees f08, and deallocates this when flag bit 0 is set.
// @fnv 0x00e6e8f0
void* __fastcall FUN_00e6e8f0(NiTMapBaseStub* self, void*, unsigned int uiFlags)
{
    *(void**)self = (void*)&DAT_010eda24;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (uiFlags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

namespace fnv_00e6e930 {
extern int DAT_010eda24;
extern int DAT_010edafc;


// Resets two vtables, clears two maps, frees unk8, and frees the object when flags has bit 0 set; returns this.
// @fnv 0x00e6e930
void* __fastcall DestroyOwner(NiTMapBaseStub* self, void*, unsigned int flags)
{
	*(void**)self = (void*)&DAT_010edafc;
	self->RemoveAll();
	*(void**)self = (void*)&DAT_010eda24;
	self->RemoveAll();
	_NiFreeAlias(self->m_ppkHashTable);
	if (flags & 1)
		g_memoryManager.Deallocate(self);
	return self;
}
}  // namespace fnv_00e6e930



extern int DAT_010eda44;
extern MemoryManager g_memoryManager;
// @fnv 0x00e6e970
void* __fastcall DestroyRenderTargetMap(RenderTargetMapBase* self, void*, unsigned int auiFlags)
{
	*(void**)self = (void*)&DAT_010eda44;
	self->RemoveAll();
	_NiFreeAlias(self->m_ppkHashTable);
	if (auiFlags & 1)
		g_memoryManager.Deallocate(self);
	return self;
}


namespace fnv_00e6e9b0 {

extern int DAT_010eda44;
extern int DAT_010edb1c;
extern MemoryManager g_memoryManager;

// @fnv 0x00e6e9b0
void* __fastcall FUN_00e6e9b0(NiTPointerMap<HWND__*, NiPointer<NiRenderTargetGroup> >* self, void*, unsigned int auiFlags)
{
    *(void**)self = &DAT_010edb1c;
    self->RemoveAll();
    *(void**)self = &DAT_010eda44;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e6e9b0

namespace fnv_00e6e9f0 {
extern int DAT_010eda64;

extern MemoryManager g_memoryManager;
// @fnv 0x00e6e9f0
void* __fastcall FUN_00e6e9f0(RenderedTextureMapBase* self, void*, unsigned int auiFlags)
{
	*(void**)self = (void*)&DAT_010eda64;
	self->RemoveAll();
	_NiFreeAlias(self->m_ppkHashTable);
	if (auiFlags & 1)
		g_memoryManager.Deallocate(self);
	return self;
}
}  // namespace fnv_00e6e9f0

namespace fnv_00e6ea30 {

extern int DAT_010eda64;
extern int DAT_010edb3c;
extern MemoryManager g_memoryManager;

// @fnv 0x00e6ea30
void* __fastcall FUN_00e6ea30(NiTPointerMap<NiRenderedTexture*, NiDX9RenderedTextureData*>* self, void*, unsigned int auiFlags)
{
    *(void**)self = &DAT_010edb3c;
    self->RemoveAll();
    *(void**)self = &DAT_010eda64;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e6ea30

namespace fnv_00e6eb30 {

extern MemoryManager g_memoryManager;
extern int DAT_010edaa4;
extern int DAT_010edb7c;

// @fnv 0x00e6eb30
void* __fastcall FUN_00e6eb30(NiTPointerMap<NiDynamicTexture*, NiDX9DynamicTextureData*>* self, void*, unsigned int auiFlags)
{
    *(void**)self = (void*)&DAT_010edb7c;
    self->RemoveAll();
    *(void**)self = (void*)&DAT_010edaa4;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e6eb30

namespace fnv_00e6eba0 {

extern int DAT_010edac4;
extern MemoryManager g_memoryManager;

// @fnv 0x00e6eba0
void* __fastcall FUN_00e6eba0(PixelFormatMapBase* self, void*, unsigned int auiFlags)
{
 *(void**)self = &DAT_010edac4;
 self->RemoveAll();
 _NiFreeAlias(self->m_ppkHashTable);
 if (auiFlags & 1)
  g_memoryManager.Deallocate(self);
 return self;
}
}  // namespace fnv_00e6eba0

namespace fnv_00e6ebe0 {

extern int DAT_010edac4;
extern int DAT_010edb9c;
extern MemoryManager g_memoryManager;

// @fnv 0x00e6ebe0
void* __fastcall FUN_00e6ebe0(NiTMap<_D3DFORMAT, NiPixelFormat*>* self, void*, unsigned int auiFlags)
{
    *(void**)self = (void*)&DAT_010edb9c;
    self->RemoveAll();
    *(void**)self = (void*)&DAT_010edac4;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}  // namespace fnv_00e6ebe0

namespace fnv_00e71cc0 {

void __cdecl DeactivateActiveItem(void*);
extern const char* const g_011f4a68_arg1;
struct FUN_00e71cc0_shell {
    void* pad[0x8c8/4];
    void* __thiscall DeactivateActiveItem(void*);
    void __thiscall NiDX9Renderer_PurgeEffect(void* a1);
};
// If a1 is non-null, dynamic-casts it to the target type and, when the cast succeeds, passes the result to DeactivateActiveItem on the object at this+0x8c8.
// @fnv 0x00e71cc0
// src: COMMUNITY 0x00e71cc0
void __thiscall FUN_00e71cc0_shell::NiDX9Renderer_PurgeEffect(void* pObject)
{
    if (pObject) {
        void* casted = ((NiObject*)pObject)->DynamicCast(&g_011f4a68_arg1);
        if (casted)
            ((FUN_00e71cc0_shell*)*(void**)((char*)this + 0x8c8))->DeactivateActiveItem(casted);
    }
}
}  // namespace fnv_00e71cc0

extern int DAT_010edaf4;
extern MemoryManager g_memoryManager;
struct S00e72e20 { void *vf; void *ptr; void *__thiscall FUN_00e72e20(unsigned int); };
// Frees the stored pointer, sets the vtable to DAT_010edaf4, and deallocates this when f has bit 0 set.
// @fnv 0x00e72e20
void *__thiscall S00e72e20::FUN_00e72e20(unsigned int auiFlags)
{
    void *tmp = ptr;
    vf = (void *)&DAT_010edaf4;
    _NiFreeAlias(tmp);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct BSBatchRenderer__GeometryGroup;
struct BSBatchRenderer__AlphaList {
    BSBatchRenderer__GeometryGroup* __thiscall Remove(BSBatchRenderer__GeometryGroup*&);
};

struct NiConsoleRenderer_shellEx : GraphicsRenderer {
    void __thiscall NiDX9Renderer_ReleaseD3DShader(NiD3DShaderInterface* shader);
};
// @fnv 0x00e75310
// src: COMMUNITY 0x00e75310
void __thiscall NiConsoleRenderer_shellEx::NiDX9Renderer_ReleaseD3DShader(NiD3DShaderInterface* shader)
{
    shader->SetShaderObject(0);
    ((BSBatchRenderer__AlphaList*)((char*)this + 0x90c))->Remove((BSBatchRenderer__GeometryGroup*&)shader);
}

void _delete(void*, unsigned int);
struct S { void __thiscall FUN_00e75a70(); void* __thiscall FUN_00e762f0(unsigned int); };
// Calls FUN_00e75a70, then if bit 0 of flags is set frees this with size 0xb80, and returns this.
// @fnv 0x00e762f0
void* __thiscall S::FUN_00e762f0(unsigned int flags)
{
    FUN_00e75a70();
    if (flags & 1)
        _delete(this, 0xb80);
    return this;
}

struct FUN_00e76320
{
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    FUN_00e76320();
};
// @fnv 0x00e76320
FUN_00e76320::FUN_00e76320()
{
    f0 = 0;
    f4 = 0;
    f8 = 0xffffffff;
    fC = 0x11;
    f10 = 0;
    f14 = 0;
    f18 = 0;
}


// Writes V45() to *a and the dword at this+0x20 to *b, returning whether *a is non-zero.
// @fnv 0x00e76630
bool NiDX9ShaderDeclaration::GenerateVertexParameters(IDirect3DVertexDeclaration9** a, unsigned int* b)
{
 *a = (IDirect3DVertexDeclaration9*)GetD3DDeclaration();
 *b = m_uiRegisterStreamCount;
 return *a != 0;
}

extern void* DAT_0126f550;
extern const void* DAT_010ee898;
void __cdecl Object_ProcessEntries_00e7a760();
// @fnv 0x00e7a860
// src: COMMUNITY 0x00e7a860
void __cdecl NiD3DShaderDeclaration__SDMInit()
{
    void* p = g_memoryManager.Allocate(0x10);
    if (p) {
        ((unsigned short*)p)[4] = 0;
        ((unsigned short*)p)[7] = 1;
        ((unsigned short*)p)[5] = 0;
        ((unsigned short*)p)[6] = 0;
        ((unsigned int*)p)[1] = 0;
        ((unsigned int*)p)[0] = (unsigned int)&DAT_010ee898;
        DAT_0126f550 = p;
    } else {
        DAT_0126f550 = 0;
    }
    Object_ProcessEntries_00e7a760();
}

extern int DAT_0126f0ec;

struct FUN_00e69920_shell {
    void ClearList();
};

// @fnv 0x00e69920
void __thiscall FUN_00e69920_shell::ClearList()
{
    struct Obj {
        unsigned int pad[0x620 / 4];
        unsigned int head;
        unsigned int tail;
    };
    Obj* p = (Obj*)this;
    unsigned int node = p->head;
    while (node)
    {
        unsigned int next = *(unsigned int*)(node + 0xc);
        unsigned int cur = *(unsigned int*)&DAT_0126f0ec;
        *(unsigned int*)&DAT_0126f0ec = node;
        *(unsigned int*)(node + 0xc) = cur;
        node = next;
    }
    p->head = 0;
    p->tail = 0;
}

struct FakeHandle {
	virtual void __stdcall h00();
	virtual void __stdcall h01();
	virtual unsigned long __stdcall Release();
};
struct V31 {
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30();
};
struct FakeMgr : V31 { virtual void Clear(int, int); };
struct FakeShader : V31 { virtual FakeHandle* GetHandle(); virtual void Purge(int); };
struct FakeRenderer {
	char _pad[0x8b8];
	FakeMgr* mgr;
	void PurgeShader(FakeShader* pkShader);
};
// Clears the manager, releases the shader's handle if present, then purges the shader.
// @fnv 0x00e699c0
void FakeRenderer::PurgeShader(FakeShader* pkShader)
{
	mgr->Clear(0, 0);
	FakeHandle* pkShaderHandle = pkShader->GetHandle();
	if (pkShaderHandle)
		pkShaderHandle->Release();
	pkShader->Purge(0);
}

struct DepthDevice;
struct Ni2DBuffer;
struct S_00e69a20
{
	char pad[0x288];
	DepthDevice* dev;
	bool __thiscall CreateDepthStencilBuffer(Ni2DBuffer* a, NiPixelFormat const* b, unsigned int c);
};
// Returns false if the buffer is null, otherwise creates a depth-stencil buffer via NiDX9AdditionalDepthStencilBufferData::Create using dev.
// @fnv 0x00e69a20
bool __thiscall S_00e69a20::CreateDepthStencilBuffer(Ni2DBuffer* apBuffer, NiPixelFormat const* apPixelFormat, unsigned int c)
{
	if (!apBuffer)
		return false;
	return NiDX9AdditionalDepthStencilBufferData::Create(dev, &apBuffer, apPixelFormat, c);
}

extern "C" char* __cdecl strcat_s(char* dest, unsigned int size, const char* src);
struct FUN_00e69c00_shell {
    char pad[0x5cc];
    unsigned int flags;
    char pad2[0x5f0-0x5d0];
    char result[0x20];
    const char* __thiscall GetVertexProcessingFlagsString();
};
// Builds a string in result from flags bits, appending PURE, MT, HWVP, MIXVP and SWVP tags, and returns it.
// @fnv 0x00e69c00
const char* __thiscall FUN_00e69c00_shell::GetVertexProcessingFlagsString()
{
    result[0] = 0;
    if (flags & 0x10) strcat_s(result, 0x20, "PURE");
    if (flags & 4) strcat_s(result, 0x20, " MT");
    if (flags & 0x40) strcat_s(result, 0x20, " HWVP");
    if (flags & 0x80) strcat_s(result, 0x20, " MIXVP");
    if (flags & 0x20) strcat_s(result, 0x20, " SWVP");
    return result;
}

struct FUN_00e6d710_shell {
    char pad[0x8ac];
    void* m_8ac;
    void __thiscall NiDX9Renderer_PurgeScreenTexture(void* a);
};

struct FUN_00e6d710_target {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(void* a);
};

// If a is non-null and its field at offset 0x1c is non-zero, calls m6 on m_8ac with a.
// @fnv 0x00e6d710
// src: COMMUNITY 0x00e6d710
void __thiscall FUN_00e6d710_shell::NiDX9Renderer_PurgeScreenTexture(void* a) {
    if (a && *(unsigned int*)((char*)a + 0x1c)) {
        ((FUN_00e6d710_target*)m_8ac)->m6(a);
    }
}

struct FUN_00e6df80_shell {
    char pad[0x8cc];
    RenderedTextureMapBase& NiconsolerendererMapView() { return *reinterpret_cast<RenderedTextureMapBase*>(reinterpret_cast<char*>(this) + 0x8cc); }
    void RemoveKeyAndClearField(const char* key);
};

// @fnv 0x00e6df80
void FUN_00e6df80_shell::RemoveKeyAndClearField(const char* key)
{
    *(unsigned int*)((char*)key + 0x24) = 0;
    NiconsolerendererMapView().RemoveAt(reinterpret_cast<NiRenderedTexture*>(const_cast<char*>(key)));
}

namespace fnv_00e6dfa0 {
struct DynamicTextureOwner {
    unsigned int pad[0x24 / 4];
    unsigned int count;
    bool __thiscall NiDX9Renderer_RemoveDynamicTextureData(NiDynamicTexture* texture);
};
// @fnv 0x00e6dfa0
// src: COMMUNITY 0x00e6dfa0
bool __thiscall DynamicTextureOwner::NiDX9Renderer_RemoveDynamicTextureData(NiDynamicTexture* texture)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(texture) + 0x24) = 0;
    return reinterpret_cast<DynamicTextureMapBase*>(reinterpret_cast<char*>(this) + 0x8ec)->RemoveAt(texture);
}
}  // namespace fnv_00e6dfa0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct RefObject
{
	virtual void Unk00();
	virtual void Unk04();
	unsigned int m_uiRefCount;
	void IncRefCount() { InterlockedIncrement((long volatile*)&m_uiRefCount); }
	void DecRefCount() { if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0) Unk04(); }
};
struct FUN_00e6e6e0_shell
{
	char _pad[0x14];
	RefObject* m_sp;
	void AssignRefObject(RefObject* pkObj);
};
// @fnv 0x00e6e6e0
void FUN_00e6e6e0_shell::AssignRefObject(RefObject* pkObj)
{
	if (pkObj)
	{
		if (m_sp != pkObj)
		{
			if (m_sp)
				m_sp->DecRefCount();
			m_sp = pkObj;
			m_sp->IncRefCount();
		}
	}
}

struct FUN_00e752b0_shell {
    char _pad[0x90c];
    struct Node { Node* next; Node* prev; void* data; } *m_Head, *m_Tail;
    NodePoolView m_Pool;
    void NiXenonRenderer_RegisterD3DShader(void* pkD3DShader);
};
// Allocates a node from the pool, stores pkD3DShader in it, and links it at the head of the list, updating the tail when the list was empty.
// @fnv 0x00e752b0
// src: XBOX_PDB 0x00e752b0
void FUN_00e752b0_shell::NiXenonRenderer_RegisterD3DShader(void* pkD3DShader)
{
    Node* pkNode = (Node*)m_Pool.AddHead();
    pkNode->data = pkD3DShader;
    pkNode->prev = 0;
    pkNode->next = m_Head;
    if (m_Head) {
        m_Head->prev = pkNode;
        ++*(unsigned int*)&m_Pool;
        m_Head = pkNode;
    } else {
        ++*(unsigned int*)&m_Pool;
        m_Tail = pkNode;
        m_Head = pkNode;
    }
}

struct VBase765 {
	virtual void f00() = 0;
	virtual void f01() = 0;
	virtual void f02() = 0;
	virtual void f03() = 0;
	virtual void f04() = 0;
	virtual void f05() = 0;
	virtual void f06() = 0;
	virtual void f07() = 0;
	virtual void f08() = 0;
	virtual void f09() = 0;
	virtual void f10() = 0;
	virtual void f11() = 0;
	virtual void f12() = 0;
	virtual void f13() = 0;
	virtual void f14() = 0;
	virtual void f15() = 0;
	virtual void f16() = 0;
	virtual void f17() = 0;
	virtual void f18() = 0;
	virtual void f19() = 0;
	virtual void f20() = 0;
	virtual void f21() = 0;
	virtual void f22() = 0;
	virtual void f23() = 0;
	virtual void f24() = 0;
	virtual void f25() = 0;
	virtual void f26() = 0;
	virtual void f27() = 0;
	virtual void f28() = 0;
	virtual void f29() = 0;
	virtual void f30() = 0;
	virtual void f31() = 0;
	virtual void f32() = 0;
	virtual void f33() = 0;
	virtual void f34() = 0;
	virtual void f35() = 0;
	virtual void f36() = 0;
	virtual void f37() = 0;
	virtual void f38() = 0;
	virtual void f39() = 0;
	virtual void f40() = 0;
	virtual void f41() = 0;
	virtual void f42() = 0;
	virtual void f43() = 0;
	virtual void f44() = 0;
	virtual void Touch() = 0;
};
struct Group765 : VBase765 {
	char pad[28];
	unsigned int count;
	struct Entry { unsigned int a; unsigned int b; unsigned int c; void* r; };
	Entry* entries;
	void* NiDX9ShaderDeclaration_GetVertexStride(unsigned int index);
};
// Returns entries[index].r when index is below count, otherwise returns 0; calls Touch() before the lookup.
// @fnv 0x00e765e0
// src: COMMUNITY 0x00e765e0
void* Group765::NiDX9ShaderDeclaration_GetVertexStride(unsigned int index)
{
	if (index >= count)
		return 0;
	Touch();
	return entries[index].r;
}

struct FUN_00e76610_shell {
    unsigned int pad[0x34/4];
    void __thiscall SetFlag(bool value);
};

// @fnv 0x00e76610
void __thiscall FUN_00e76610_shell::SetFlag(bool value)
{
    ((unsigned char*)((unsigned char*)this + 0x34))[0] = value;
}

extern int DAT_010ee70c;
extern MemoryManager g_memoryManager;
void __cdecl _delete(void*, unsigned int);
struct ICom78510 { virtual int __stdcall Q(); virtual int __stdcall A(); virtual int __stdcall R(); };
struct H78510 { void __thiscall ProcessEntries_00e78be0(); };
struct S78510 { char pad[0x2c]; void* p1; ICom78510* p2; char tail[4]; void* __thiscall FUN_00e78510(unsigned int); };
// @fnv 0x00e78510
void* __thiscall S78510::FUN_00e78510(unsigned int auiFlags)
{
    void* v1 = p1;
    *(int**)this = &DAT_010ee70c;
    g_memoryManager.Deallocate(v1);
    if (p2) {
        p2->R();
        p2 = 0;
    }
    ((H78510*)this)->ProcessEntries_00e78be0();
    if (auiFlags & 1) {
        _delete(this, 0x38);
    }
    return this;
}

extern "C" void __cdecl FUN_00ee88b0();
extern const char DAT_010ee7cc[];

struct FUN_00e78840_shell {
    void* vtable;
    unsigned int pad4;
    unsigned int pad[8];
    unsigned char flag;
    FUN_00e78840_shell* __thiscall Construct();
};

// Calls FUN_00ee88b0, zeroes the pad array and flag, sets the vtable to DAT_010ee7cc, and returns this.
// @fnv 0x00e78840
FUN_00e78840_shell* __thiscall FUN_00e78840_shell::Construct()
{
    FUN_00ee88b0();
    pad[0] = 0;
    pad[1] = 0;
    pad[2] = 0;
    pad[3] = 0;
    pad[4] = 0;
    pad[5] = 0;
    pad[6] = 0;
    pad[7] = 0;
    flag = 0;
    vtable = (void*)DAT_010ee7cc;
    return this;
}

struct CpSurf;
struct CpRECT { int left, top, right, bottom; };
struct CpDevice {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33();
    virtual long __stdcall StretchRect(CpSurf*, const CpRECT*, CpSurf*, const CpRECT*, int);
};
char* __cdecl GetHRESULTText(unsigned int);
struct CopyRendererData { char pad[0x14]; CpSurf* surface; };
struct RenderCopyData { char pad[8]; unsigned int width; unsigned int height; CopyRendererData* data; };
struct CpRectNi { int left, right, top, bottom; };
typedef void (__cdecl *CopyMsgFn)(const char*, ...);
struct FUN_00e6f840_shell {
    bool CopySurface(RenderCopyData* src, RenderCopyData* dst, CpRectNi* srcRect, CpRectNi* dstRect, int filter);
};
// Copies a source surface to a destination surface via StretchRect, using explicit or full-surface rects, logging and returning false on failure.
// @fnv 0x00e6f840
bool FUN_00e6f840_shell::CopySurface(RenderCopyData* pSource, RenderCopyData* pDest, CpRectNi* srcRect, CpRectNi* dstRect, int filter)
{
    if (*((char*)this + 0x6fc))
        return false;
    CopyRendererData* dstData = pDest->data;
    CopyRendererData* srcData = pSource->data;
    if (!srcData || !dstData) {
        ((CopyMsgFn)&NiD3DDefaultShader::SetShaderName)("NiDX9Renderer::Copy> Failed - %s", "No RendererData found");
        return false;
    }
    CpSurf* srcSurf = srcData->surface;
    CpSurf* dstSurf = dstData->surface;
    if (!srcSurf || !dstSurf) {
        ((CopyMsgFn)&NiD3DDefaultShader::SetShaderName)("NiDX9Renderer::Copy> Failed - %s", "NULL Surface found");
        return false;
    }
    CpRECT s;
    if (srcRect) {
        s.left = srcRect->left; s.right = srcRect->right; s.top = srcRect->top; s.bottom = srcRect->bottom;
    } else {
        s.left = 0; s.right = pSource->width; s.top = 0; s.bottom = pSource->height;
    }
    CpRECT d;
    if (dstRect) {
        d.left = dstRect->left; d.right = dstRect->right; d.top = dstRect->top; d.bottom = dstRect->bottom;
    } else {
        d.left = 0; d.right = pDest->width; d.top = 0; d.bottom = pDest->height;
    }
    int f;
    switch (filter) {
    case 1: f = 1; break;
    case 2: f = 2; break;
    default: f = 0; break;
    }
    CpDevice* dev = *(CpDevice**)((char*)this + 0x288);
    long hr = dev->StretchRect(srcSurf, &s, dstSurf, &d, f);
    if (hr < 0) {
        ((CopyMsgFn)&NiD3DDefaultShader::SetShaderName)("NiDX9Renderer::Copy> Failed StretchRect - %s", GetHRESULTText(hr));
        return false;
    }
    return true;
}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

struct FUN_00e76c30_Info {
    int eType;                     // +0x00
    unsigned short usComps;        // +0x04
    unsigned short pad06;
    unsigned short usVerts;        // +0x08
    unsigned short pad0a;
    unsigned short* pusRemap;      // +0x0c
    float* pfSrc;                  // +0x10
    unsigned int pad14;
    unsigned int uiSrcStride;      // +0x18
    unsigned int uiDestSize;       // +0x1c
    unsigned int uiDestStride;     // +0x20
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;        // +0x2c
};

// @fnv 0x00e76c30
// src: COMMUNITY 0x00e76c30
unsigned int NiD3DShaderDeclaration_Pack_FloatToShort(FUN_00e76c30_Info* pkInfo)
{
    unsigned int uiTotal = 0;
    float* pfSrc = pkInfo->pfSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;

    if (!pfSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
        return uiTotal;
    }

    unsigned short usComps = pkInfo->usComps;
    unsigned short usMax = (pkInfo->eType == 6) ? 2 : 4;
    unsigned short m_usPassCountLocal = (usComps > usMax) ? usMax : usComps;

    if (pusRemap)
    {
        unsigned short usIndex = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            float* pfIn = (float*)((unsigned char*)pfSrc + pusRemap[usIndex++] * pkInfo->uiSrcStride);
            short* psOut = (short*)pucDest;
            unsigned short j = 0;
            for (; j < m_usPassCountLocal; j++)
                *psOut++ = (short)*pfIn++;
            for (; j < usMax; j++)
                *psOut++ = 0;
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            float* pfIn = pfSrc;
            short* psOut = (short*)pucDest;
            unsigned short j = 0;
            for (; j < m_usPassCountLocal; j++)
                *psOut++ = (short)*pfIn++;
            for (; j < usMax; j++)
                *psOut++ = 0;
            uiTotal += pkInfo->uiDestSize;
            pfSrc = (float*)((unsigned char*)pfSrc + pkInfo->uiSrcStride);
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiTotal;
}

void* _fnv_zlib_memset(void*, int, unsigned int);

struct FUN_00e79f40_Stream {
    unsigned int pad0;
    unsigned short type;
    unsigned short pad6;
    unsigned short count;
    unsigned short padA;
    unsigned short* indices;
    char* src;
    unsigned int pad14;
    unsigned int srcStride;
    unsigned int elemSize;
    unsigned int dstStride;
    unsigned int pad24;
    unsigned int pad28;
    char* dst;
};

// Converts s->count elements from src (via optional indices) into packed 32-bit values at dst, or fills dst with 0xff when src is null; returns total bytes.
// @fnv 0x00e79f40
// src: COMMUNITY 0x00e79f40
int NiD3DShaderDeclaration_Pack_ByteToUByteColor(FUN_00e79f40_Stream* pStream)
{
    char* src = pStream->src;
    unsigned short* indices = pStream->indices;
    int total = 0;
    char* dst = pStream->dst;
    if (src == 0) {
        for (unsigned short i = 0; i < pStream->count; i++) {
            _fnv_zlib_memset(dst, 0xff, pStream->elemSize);
            dst += pStream->dstStride;
            total += pStream->elemSize;
        }
        return total;
    }
    unsigned short comps = pStream->type - 0x14;
    if (indices) {
        unsigned short idx = 0;
        for (unsigned short i = 0; i < pStream->count; i++) {
            char* p = src + indices[idx++] * pStream->srcStride;
            char a = (comps == 3) ? (char)0xff : p[3];
            *(unsigned int*)dst = ((unsigned int)((((a) & 0xff) << 24) | (((p[0]) & 0xff) << 16) | (((p[1]) & 0xff) << 8) | ((p[2]) & 0xff)));
            dst += pStream->dstStride;
            total += pStream->elemSize;
        }
    } else {
        for (unsigned short i = 0; i < pStream->count; i++) {
            char a = (comps == 3) ? (char)0xff : src[3];
            *(unsigned int*)dst = ((unsigned int)((((a) & 0xff) << 24) | (((src[0]) & 0xff) << 16) | (((src[1]) & 0xff) << 8) | ((src[2]) & 0xff)));
            src += pStream->srcStride;
            dst += pStream->dstStride;
            total += pStream->elemSize;
        }
    }
    return total;
}

struct FUN_00e78bd0_shell {
    bool flag;          // +0x00
    void* field_04;     // +0x04
    void* field_08;     // +0x08
    void* field_0c;     // +0x0c
    FUN_00e78bd0_shell();
};

// @fnv 0x00e78bd0
FUN_00e78bd0_shell::FUN_00e78bd0_shell()
{
    flag = false;
    field_04 = 0;
    field_08 = 0;
    field_0c = 0;
}

struct DepthDeviceTable;

typedef int (__stdcall *DepthDeviceFunction)(void*, unsigned int, unsigned int, char*);

struct DepthDevice
{
    DepthDeviceTable* table;
};

struct DepthDeviceTable
{
    void* slots[5];
    DepthDeviceFunction function;
};

struct FUN_00e6c690_shell
{
    char* GetDepthDeviceDescription();
};

extern DepthDevice* DAT_0126f0d8;

int __cdecl _NiSprintf(char*, unsigned int, const char*, int, const char*, ...);
void* _fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00e6c690
char* __thiscall FUN_00e6c690_shell::GetDepthDeviceDescription()
{
    char buffer[0x44c];
    char* output = reinterpret_cast<char*>(this) + 0x3c4;
    unsigned int* width = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x5c4);
    unsigned int* value = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x5c8);

    output[0] = 0;
    _fnv_zlib_memset(buffer, 0, sizeof(buffer));

    DepthDevice* device = DAT_0126f0d8;
    DepthDeviceTable* table = device->table;

    if (table->function(device, *width, 0, buffer) >= 0)
    {
        const char* type;
        switch (*value)
        {
        case 1:
            type = "HAL";
            break;
        case 2:
            type = "REF";
            break;
        case 3:
            type = "SW";
            break;
        default:
            type = "???";
            break;
        }

        const char* name = reinterpret_cast<FUN_00e69c00_shell*>(this)->GetVertexProcessingFlagsString();
        _NiSprintf(
            output,
            0x200,
            "%s (%s-%s)",
            reinterpret_cast<int>(buffer + 0x200),
            type,
            name);
    }

    return output;
}

extern void* DAT_011c5f58;

// Releases the object's referenced node via a decrement-and-destroy, then resets its fields and pushes it onto the DAT_011c5f58 list under a lock.
// @fnv 0x00e6e830
void __stdcall ReleaseRefCountedNode(void* param_1)
{
    void** p = (void**)param_1;
    void* node = p[2];
    if (node)
    {
        void** obj = (void**)node;
        if (InterlockedDecrement((long*)((char*)node + 4)) == 0)
        {
            void** vt = (void**)*obj;
            ((void (__thiscall*)(void*))vt[1])(node);
        }
        p[2] = 0;
    }
    g_011c5f80.Lock(0);
    p[1] = 0;
    p[0] = DAT_011c5f58;
    DAT_011c5f58 = param_1;
    if (--DAT_011c5f84 == 0)
        g_011c5f80.m_uiOwningThreadID = 0;
}

struct FUN_00e76500_shell
{
    unsigned int pad[7];
    unsigned int f1c;
    unsigned int f20;
    unsigned int* f24;
    unsigned char f28;
    unsigned int pad29[1];
    void* f30;
    bool NiDX9ShaderDeclaration_RemoveEntry(unsigned int a, unsigned int b);
};

// @fnv 0x00e76500
// src: COMMUNITY 0x00e76500
bool FUN_00e76500_shell::NiDX9ShaderDeclaration_RemoveEntry(unsigned int a, unsigned int b)
{
    if (a >= f1c)
        return false;
    if (b >= f20)
        return false;
    unsigned int* entry = *(unsigned int**)((char*)(f24 + b * 4) + 8);
    unsigned int* p = (unsigned int*)((char*)entry + a * 28);
    p[2] = 0xffffffff;
    p[3] = 0x11;
    void* obj = f30;
    f28 = 1;
    if (obj)
    {
        void** vt = *(void***)obj;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[2];
        fn(obj);
        f30 = 0;
    }
    return true;
}

namespace fnv_00aa1110 {
class AA1110Allocator {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void Deallocate(void* pvMem, int aiAllocationType, unsigned int uiSizeInBytes);
};

struct AA1110MemManager {
    AA1110Allocator* m_pHeapAllocator;
};

extern AA1110MemManager* g_pkAA1110MemManager;

// NiFree
// @fnv 0x00aa1110
// src: GAMEBRYO_LIB 0x00aa1110
void _NiAlignedFree(void* pvMem)
{
    if (pvMem)
        g_pkAA1110MemManager->m_pHeapAllocator->Deallocate(pvMem, 10, (unsigned int)-1);
}
}  // namespace fnv_00aa1110

// FUN_00e69640 - 13-byte thiscall forwarder.
// this+0x8c4 holds a pointer to a polymorphic object; the call is forwarded as a
// tail jump to that object's vtable slot +0x10 (the 5th virtual, index 4).
class FUN_00e69640_target
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Forward(int a);
};

class FUN_00e69640_cls
{
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    FUN_00e69640_target* m_8c4;
    void NiDX9Renderer_PrecacheTexture(int a);
};

// @fnv 0x00e69640
// src: COMMUNITY 0x00e69640
void FUN_00e69640_cls::NiDX9Renderer_PrecacheTexture(int a)
{
    m_8c4->Forward(a);
}

struct VertexDeclarationElement { unsigned short stream,offset; unsigned char type,method,usage,m_ucUsageIndex; };
struct VertexDeclarationDevice : Dev { virtual long __stdcall DrawPrimitiveUP(); virtual long __stdcall DrawIndexedPrimitiveUP(); virtual long __stdcall ProcessVertices(); virtual long __stdcall CreateVertexDeclaration(const VertexDeclarationElement*, void**); };
struct RendererDeclarationOwner { unsigned int m_rendererFields[0xa0]; void* m_vertexDeclaration; unsigned int m_declarationState; VertexDeclarationDevice* m_device; void* __thiscall NiDX9Renderer_GetDecl_ParticlesSubTexture(); };
// Creates the vertex declaration from a fixed element array on first use and returns it, or null if creation fails.
// @fnv 0x00e696a0
// src: COMMUNITY 0x00e696a0
void* RendererDeclarationOwner::NiDX9Renderer_GetDecl_ParticlesSubTexture() {
 if (!m_vertexDeclaration) {
    VertexDeclarationElement elements[5] = { {0,0,2,0,0,0}, {0,12,2,0,3,0}, {0,24,4,0,10,0}, {0,28,1,0,5,0}, {255,0,17,0,0,0} };
    if (m_device->CreateVertexDeclaration(elements, &m_vertexDeclaration) < 0) m_vertexDeclaration = 0;
 }
 return m_vertexDeclaration;
}

// FUN_00e69960 - 13-byte thiscall forwarder: loads the object at this+0x8b8,
// reads its vtable slot +0x54 (index 21) and tail-jumps to it.
class FUN_00e69960_target
{
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void Forward(int a);
};

class FUN_00e69960_cls
{
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    FUN_00e69960_target* m_8b8;
    void NiDX9Renderer_PurgeMaterial(int a);
};

// @fnv 0x00e69960
// src: COMMUNITY 0x00e69960
void FUN_00e69960_cls::NiDX9Renderer_PurgeMaterial(int a)
{
    m_8b8->Forward(a);
}

struct RenderBufferAllocation {
    RenderBufferAllocation* FUN_00e8db90(void* parameters);
};

// @fnv 0x00e69a00
RenderBufferAllocation* __stdcall CreateRenderBufferAllocation(void* parameters)
{
    RenderBufferAllocation* buffer = static_cast<RenderBufferAllocation*>(NiMemObject::operator new(84));
    if (buffer)
        return buffer->FUN_00e8db90(parameters);
    return 0;
}

struct FUN_00e69a60_obj20 {
    virtual void v0();
    virtual void v1();
    virtual void __stdcall v2();
};

struct FUN_00e69a60_obj14 {
    void* __thiscall FUN_00e7bc90(FUN_00e69a60_obj20* a, void* b);
};

extern "C" void* g_0126f0e8;
extern "C" void* (__stdcall* g_0126f0dc)(unsigned int);
extern "C" unsigned int DAT_0126f0f8;

bool __cdecl InitD3D9CreateFunctions();
void* __cdecl Object_DispatchCommandFour(unsigned int size);

// Returns the cached global pointer, creating it via a factory call and helper object when unset and InitD3D9CreateFunctions succeeds.
// @fnv 0x00e69a60
// src: COMMUNITY 0x00e69a60
void* __cdecl NiDX9SystemDesc_Get()
{
    if (g_0126f0e8 != 0) {
        return g_0126f0e8;
    }
    if (!InitD3D9CreateFunctions()) {
        return g_0126f0e8;
    }
    FUN_00e69a60_obj20* obj = (FUN_00e69a60_obj20*)g_0126f0dc(0x20);
    if (obj != 0) {
        FUN_00e69a60_obj14* helper = (FUN_00e69a60_obj14*)Object_DispatchCommandFour(0x14);
        if (helper != 0) {
            g_0126f0e8 = helper->FUN_00e7bc90(obj, &DAT_0126f0f8);
        } else {
            g_0126f0e8 = 0;
        }
        obj->v2();
    }
    return g_0126f0e8;
}

struct RendererListNode
{
    void* m_pListObject;
    RendererListNode* m_pNext;
};

struct FUN_00e69b00_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual RendererListNode* GetListHead();
    unsigned int ContainsNode(RendererListNode* pTarget);
};
// @fnv 0x00e69b00
unsigned int FUN_00e69b00_cls::ContainsNode(RendererListNode* pTarget)
{
    RendererListNode* node = GetListHead();
    bool found;
    if (node != 0)
    {
        while (node != 0)
        {
            if (node == pTarget)
                goto found_label;
            node = node->m_pNext;
        }
    }
    found = false;
    goto done;
found_label:
    found = true;
done:
    return (found ? -1 : 0) & (unsigned int)this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
__forceinline void NiRefObject::IncRefCount() { InterlockedIncrement((long volatile*)&m_uiRefCount); }
__forceinline void NiRefObject::DecRefCount() { if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0) DeleteThis(); }
__forceinline unsigned char* NiPixelData::GetPixels() { return m_pucPixels + m_puiOffsetInBytes[0]; }


template<class T> class ConsolePointer {
public:
    T* m_pObject;
    ConsolePointer& operator=(T* p) {
        if (m_pObject != p) {
            if (m_pObject != 0) m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject != 0) m_pObject->IncRefCount();
        }
        return *this;
    }
    T* operator->() const { return m_pObject; }
};
struct FmtObj { int unk00; int unk04; int unk08; int unk0c; int unk10; };
void* _fnv_zlib_memset(void* dst, int val, unsigned int size);
void ApplySettings(FmtObj*);
struct Holder {
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    FmtObj* m_apkSources[4][22];
    FmtObj* m_apkFormat[4];
    ConsolePointer<NiPixelData> m_aspPixelData[4];
    int m_unk880;
    bool InitFormats();
};
// Picks the first non-null source per slot in a fixed order, allocates a 4x4 NiPixelData filled with 0xff, and returns false if slot 0 is empty.
// @fnv 0x00e6c550
bool Holder::InitFormats() {
    unsigned int auiPriorityOrder[6] = { 1, 0, 2, 4, 3, 5 };
    for (unsigned int i = 0; i < 4; i++) {
        m_apkFormat[i] = 0;
        for (unsigned int j = 0; j < 6; j++) {
            unsigned int k = auiPriorityOrder[j];
            if (m_apkSources[i][k]) {
                m_apkFormat[i] = m_apkSources[i][k];
                break;
            }
        }
        if (m_apkFormat[i]) {
            m_aspPixelData[i] = ::new (AllocatePixelData) NiPixelData(4, 4, *(const NiPixelFormat*)m_apkFormat[i], 1, 1);
            _fnv_zlib_memset(m_aspPixelData[i]->GetPixels(), 0xff, m_aspPixelData[i]->m_uiPixelStride * 16);
        }
    }
    if (!m_apkFormat[0]) return false;
    ApplySettings(m_apkFormat[0]);
    m_unk880 = m_apkFormat[0]->unk10;
    return true;
}


struct E6D310Device {
    virtual void unk000(); virtual void unk004(); virtual void unk008(); virtual void unk00C();
    virtual void unk010(); virtual void unk014(); virtual void unk018(); virtual void unk01C();
    virtual void unk020(); virtual void unk024(); virtual void unk028(); virtual void unk02C();
    virtual void unk030(); virtual void unk034(); virtual void unk038(); virtual void unk03C();
    virtual void unk040(); virtual void unk044(); virtual void unk048(); virtual void unk04C();
    virtual void unk050(); virtual void unk054(); virtual void unk058(); virtual void unk05C();
    virtual void unk060(); virtual void unk064(); virtual void unk068(); virtual void unk06C();
    virtual void unk070(); virtual void unk074(); virtual void unk078(); virtual void unk07C();
    virtual void unk080(); virtual void unk084(); virtual void unk088(); virtual void unk08C();
    virtual void unk090(); virtual void unk094(); virtual void unk098(); virtual void unk09C();
    virtual void unk0A0(); virtual void unk0A4(); virtual void unk0A8(); virtual void unk0AC();
    virtual void unk0B0(); virtual void unk0B4(); virtual void unk0B8(); virtual void unk0BC();
    virtual void unk0C0(); virtual void unk0C4(); virtual void unk0C8(); virtual void unk0CC();
    virtual void unk0D0(); virtual void unk0D4(); virtual void unk0D8(); virtual void unk0DC();
    virtual void unk0E0(); virtual void unk0E4(); virtual void unk0E8(); virtual void unk0EC();
    virtual void unk0F0(); virtual void unk0F4(); virtual void unk0F8(); virtual void unk0FC();
    virtual void unk100(); virtual void unk104(); virtual void unk108(); virtual void unk10C();
    virtual void unk110(); virtual void unk114(); virtual void unk118(); virtual void unk11C();
    virtual void unk120(); virtual void unk124(); virtual void unk128(); virtual void unk12C();
    virtual void unk130(); virtual void unk134(); virtual void unk138(); virtual void unk13C();
    virtual void unk140(); virtual void unk144();
    virtual long __stdcall DrawIndexedPrimitive(_D3DPRIMITIVETYPE primitiveType, int baseVertexIndex, unsigned int minVertexIndex,
                                                unsigned int numVertices, unsigned int startIndex, unsigned int primCount);
};

struct E6D310StripSet {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
    int m_baseVertex;
    int unk3C;
    unsigned int m_uiTriangleCount;
    int unk44;
    unsigned int m_stripCount;
    unsigned short* m_pStripIndices;
};

struct E6D310Geometry {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    unsigned short m_kVertices;
    unsigned short unk1E;
    unsigned short unk20;
    unsigned short m_strips;
};

struct E6D310Renderer {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    E6D310Device* m_device;

    void NiDX9Renderer_Do_DrawPartition(E6D310StripSet* set, E6D310Geometry* geometry, int unused);
};

// For each strip, computes the primitive count and issues a DrawIndexedPrimitive call, advancing the index start offset.
// @fnv 0x00e6d310
// src: COMMUNITY 0x00e6d310
void E6D310Renderer::NiDX9Renderer_Do_DrawPartition(E6D310StripSet* stripSet, E6D310Geometry* geometry, int unused)
{
    unsigned int start = 0;
    for (unsigned int i = 0; i < stripSet->m_stripCount; i++) {
        unsigned int primCount;
        if (stripSet->m_pStripIndices)
            primCount = stripSet->m_pStripIndices[i] - 2;
        else
            primCount = stripSet->m_uiTriangleCount;
        if (geometry->m_strips)
            m_device->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, stripSet->m_baseVertex, 0, geometry->m_kVertices, start, primCount);
        else
            m_device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, stripSet->m_baseVertex, 0, geometry->m_kVertices, start, primCount);
        start += primCount + 2;
    }
}

extern void* DAT_0126f108[];

class PacketEntry {
public:
    virtual int slot00();
    virtual int slot01();
    virtual int slot02();
    virtual int slot03();
    virtual int slot04();
    virtual int slot05();
    virtual int slot06();
    virtual int slot07();
    virtual int slot08();
    virtual int slot09();
    virtual int slot10();
    virtual int slot11();
    virtual int slot12();
    virtual int slot13();
    virtual int slot14();
    virtual int slot15();
    virtual int slot16();
    virtual int slot17();
    virtual int slot18();
    virtual int slot19();
    virtual int slot20();
    virtual int slot21();
    virtual int slot22();
    virtual int slot23();
    virtual int slot24();
    virtual int slot25();
    virtual int slot26();
    virtual int slot27();
    virtual int slot28();
    virtual int slot29();
    virtual int slot30();
    virtual int slot31();
    virtual int slot32();
    virtual int slot33();
    virtual int slot34();
    virtual int slot35();
    virtual int slot36();
    virtual int slot37();
    virtual int slot38();
    virtual int slot39();
    virtual int slot40();
    virtual int slot41();
    virtual int slot42();
    virtual int slot43();
    virtual int slot44();
    virtual int slot45();
};

// @fnv 0x00e6d760
int __stdcall GetPacketSlot45(int index)
{
    if (index == 0) {
        return 0;
    } else {
        return ((PacketEntry*)DAT_0126f108[index])->slot45();
    }
}

struct GeomData_e6da60
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual unsigned int GetStreamValue(unsigned int uiIndex);
    virtual void vf41();
    virtual bool GetFlagValue();
    virtual void vf43();
    virtual bool GetCachedStreams(unsigned int* puiOut, unsigned int* puiCount);
};

struct Packet_e6da60;

struct PacketOwner_e6da60
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void ReleaseStream(Packet_e6da60* pkPacket, unsigned int uiIndex);
};

struct Packet_e6da60
{
    unsigned int unk00;
    unsigned int m_uiValue1;
    PacketOwner_e6da60* m_pkOwnerManager;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char m_ucFlag;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int m_uiCount;
    unsigned int* m_puiStreams;
    void ResizeStreams(unsigned int ItemUpdateArray);
    void SetSingleStream(unsigned int uiValue);
    void SetStreams(unsigned int uiValue);
};



// The packer at 0x00e8c120 reads a skin-weight count at 0x20; shared Data instead describes skill/category fields.
struct SkinWeightPackingSource
{
    unsigned int unk0000; unsigned int unk0004; unsigned int unk0008; unsigned int unk000C; unsigned int unk0010; unsigned int unk0014; unsigned int unk0018; unsigned int unk001C;
    unsigned short m_usType;
};

struct VBManager_e6da60
{
    void Pack(NiGeometryData* pkModel, SkinWeightPackingSource* pkData, unsigned int* puiA,
        unsigned int* puiB, unsigned int* puiC, unsigned int* puiD,
        unsigned int* puiE, unsigned int* puiF, unsigned int* puiG);
    bool CreateStream(Packet_e6da60* pkPacket, unsigned int uiIndex);
};

extern int DAT_011bf558;

// NiDX9Renderer stream-packing view: manager at 0x8bc; its shared header lacks BuildPacket (0x00e6da60).
struct ShaderStreamPacketBuilder
{
    unsigned int unk0000; unsigned int unk0004; unsigned int unk0008; unsigned int unk000C; unsigned int unk0010; unsigned int unk0014; unsigned int unk0018; unsigned int unk001C;
    unsigned int unk0020; unsigned int unk0024; unsigned int unk0028; unsigned int unk002C; unsigned int unk0030; unsigned int unk0034; unsigned int unk0038; unsigned int unk003C;
    unsigned int unk0040; unsigned int unk0044; unsigned int unk0048; unsigned int unk004C; unsigned int unk0050; unsigned int unk0054; unsigned int unk0058; unsigned int unk005C;
    unsigned int unk0060; unsigned int unk0064; unsigned int unk0068; unsigned int unk006C; unsigned int unk0070; unsigned int unk0074; unsigned int unk0078; unsigned int unk007C;
    unsigned int unk0080; unsigned int unk0084; unsigned int unk0088; unsigned int unk008C; unsigned int unk0090; unsigned int unk0094; unsigned int unk0098; unsigned int unk009C;
    unsigned int unk00A0; unsigned int unk00A4; unsigned int unk00A8; unsigned int unk00AC; unsigned int unk00B0; unsigned int unk00B4; unsigned int unk00B8; unsigned int unk00BC;
    unsigned int unk00C0; unsigned int unk00C4; unsigned int unk00C8; unsigned int unk00CC; unsigned int unk00D0; unsigned int unk00D4; unsigned int unk00D8; unsigned int unk00DC;
    unsigned int unk00E0; unsigned int unk00E4; unsigned int unk00E8; unsigned int unk00EC; unsigned int unk00F0; unsigned int unk00F4; unsigned int unk00F8; unsigned int unk00FC;
    unsigned int unk0100; unsigned int unk0104; unsigned int unk0108; unsigned int unk010C; unsigned int unk0110; unsigned int unk0114; unsigned int unk0118; unsigned int unk011C;
    unsigned int unk0120; unsigned int unk0124; unsigned int unk0128; unsigned int unk012C; unsigned int unk0130; unsigned int unk0134; unsigned int unk0138; unsigned int unk013C;
    unsigned int unk0140; unsigned int unk0144; unsigned int unk0148; unsigned int unk014C; unsigned int unk0150; unsigned int unk0154; unsigned int unk0158; unsigned int unk015C;
    unsigned int unk0160; unsigned int unk0164; unsigned int unk0168; unsigned int unk016C; unsigned int unk0170; unsigned int unk0174; unsigned int unk0178; unsigned int unk017C;
    unsigned int unk0180; unsigned int unk0184; unsigned int unk0188; unsigned int unk018C; unsigned int unk0190; unsigned int unk0194; unsigned int unk0198; unsigned int unk019C;
    unsigned int unk01A0; unsigned int unk01A4; unsigned int unk01A8; unsigned int unk01AC; unsigned int unk01B0; unsigned int unk01B4; unsigned int unk01B8; unsigned int unk01BC;
    unsigned int unk01C0; unsigned int unk01C4; unsigned int unk01C8; unsigned int unk01CC; unsigned int unk01D0; unsigned int unk01D4; unsigned int unk01D8; unsigned int unk01DC;
    unsigned int unk01E0; unsigned int unk01E4; unsigned int unk01E8; unsigned int unk01EC; unsigned int unk01F0; unsigned int unk01F4; unsigned int unk01F8; unsigned int unk01FC;
    unsigned int unk0200; unsigned int unk0204; unsigned int unk0208; unsigned int unk020C; unsigned int unk0210; unsigned int unk0214; unsigned int unk0218; unsigned int unk021C;
    unsigned int unk0220; unsigned int unk0224; unsigned int unk0228; unsigned int unk022C; unsigned int unk0230; unsigned int unk0234; unsigned int unk0238; unsigned int unk023C;
    unsigned int unk0240; unsigned int unk0244; unsigned int unk0248; unsigned int unk024C; unsigned int unk0250; unsigned int unk0254; unsigned int unk0258; unsigned int unk025C;
    unsigned int unk0260; unsigned int unk0264; unsigned int unk0268; unsigned int unk026C; unsigned int unk0270; unsigned int unk0274; unsigned int unk0278; unsigned int unk027C;
    unsigned int unk0280; unsigned int unk0284; unsigned int unk0288; unsigned int unk028C; unsigned int unk0290; unsigned int unk0294; unsigned int unk0298; unsigned int unk029C;
    unsigned int unk02A0; unsigned int unk02A4; unsigned int unk02A8; unsigned int unk02AC; unsigned int unk02B0; unsigned int unk02B4; unsigned int unk02B8; unsigned int unk02BC;
    unsigned int unk02C0; unsigned int unk02C4; unsigned int unk02C8; unsigned int unk02CC; unsigned int unk02D0; unsigned int unk02D4; unsigned int unk02D8; unsigned int unk02DC;
    unsigned int unk02E0; unsigned int unk02E4; unsigned int unk02E8; unsigned int unk02EC; unsigned int unk02F0; unsigned int unk02F4; unsigned int unk02F8; unsigned int unk02FC;
    unsigned int unk0300; unsigned int unk0304; unsigned int unk0308; unsigned int unk030C; unsigned int unk0310; unsigned int unk0314; unsigned int unk0318; unsigned int unk031C;
    unsigned int unk0320; unsigned int unk0324; unsigned int unk0328; unsigned int unk032C; unsigned int unk0330; unsigned int unk0334; unsigned int unk0338; unsigned int unk033C;
    unsigned int unk0340; unsigned int unk0344; unsigned int unk0348; unsigned int unk034C; unsigned int unk0350; unsigned int unk0354; unsigned int unk0358; unsigned int unk035C;
    unsigned int unk0360; unsigned int unk0364; unsigned int unk0368; unsigned int unk036C; unsigned int unk0370; unsigned int unk0374; unsigned int unk0378; unsigned int unk037C;
    unsigned int unk0380; unsigned int unk0384; unsigned int unk0388; unsigned int unk038C; unsigned int unk0390; unsigned int unk0394; unsigned int unk0398; unsigned int unk039C;
    unsigned int unk03A0; unsigned int unk03A4; unsigned int unk03A8; unsigned int unk03AC; unsigned int unk03B0; unsigned int unk03B4; unsigned int unk03B8; unsigned int unk03BC;
    unsigned int unk03C0; unsigned int unk03C4; unsigned int unk03C8; unsigned int unk03CC; unsigned int unk03D0; unsigned int unk03D4; unsigned int unk03D8; unsigned int unk03DC;
    unsigned int unk03E0; unsigned int unk03E4; unsigned int unk03E8; unsigned int unk03EC; unsigned int unk03F0; unsigned int unk03F4; unsigned int unk03F8; unsigned int unk03FC;
    unsigned int unk0400; unsigned int unk0404; unsigned int unk0408; unsigned int unk040C; unsigned int unk0410; unsigned int unk0414; unsigned int unk0418; unsigned int unk041C;
    unsigned int unk0420; unsigned int unk0424; unsigned int unk0428; unsigned int unk042C; unsigned int unk0430; unsigned int unk0434; unsigned int unk0438; unsigned int unk043C;
    unsigned int unk0440; unsigned int unk0444; unsigned int unk0448; unsigned int unk044C; unsigned int unk0450; unsigned int unk0454; unsigned int unk0458; unsigned int unk045C;
    unsigned int unk0460; unsigned int unk0464; unsigned int unk0468; unsigned int unk046C; unsigned int unk0470; unsigned int unk0474; unsigned int unk0478; unsigned int unk047C;
    unsigned int unk0480; unsigned int unk0484; unsigned int unk0488; unsigned int unk048C; unsigned int unk0490; unsigned int unk0494; unsigned int unk0498; unsigned int unk049C;
    unsigned int unk04A0; unsigned int unk04A4; unsigned int unk04A8; unsigned int unk04AC; unsigned int unk04B0; unsigned int unk04B4; unsigned int unk04B8; unsigned int unk04BC;
    unsigned int unk04C0; unsigned int unk04C4; unsigned int unk04C8; unsigned int unk04CC; unsigned int unk04D0; unsigned int unk04D4; unsigned int unk04D8; unsigned int unk04DC;
    unsigned int unk04E0; unsigned int unk04E4; unsigned int unk04E8; unsigned int unk04EC; unsigned int unk04F0; unsigned int unk04F4; unsigned int unk04F8; unsigned int unk04FC;
    unsigned int unk0500; unsigned int unk0504; unsigned int unk0508; unsigned int unk050C; unsigned int unk0510; unsigned int unk0514; unsigned int unk0518; unsigned int unk051C;
    unsigned int unk0520; unsigned int unk0524; unsigned int unk0528; unsigned int unk052C; unsigned int unk0530; unsigned int unk0534; unsigned int unk0538; unsigned int unk053C;
    unsigned int unk0540; unsigned int unk0544; unsigned int unk0548; unsigned int unk054C; unsigned int unk0550; unsigned int unk0554; unsigned int unk0558; unsigned int unk055C;
    unsigned int unk0560; unsigned int unk0564; unsigned int unk0568; unsigned int unk056C; unsigned int unk0570; unsigned int unk0574; unsigned int unk0578; unsigned int unk057C;
    unsigned int unk0580; unsigned int unk0584; unsigned int unk0588; unsigned int unk058C; unsigned int unk0590; unsigned int unk0594; unsigned int unk0598; unsigned int unk059C;
    unsigned int unk05A0; unsigned int unk05A4; unsigned int unk05A8; unsigned int unk05AC; unsigned int unk05B0; unsigned int unk05B4; unsigned int unk05B8; unsigned int unk05BC;
    unsigned int unk05C0; unsigned int unk05C4; unsigned int unk05C8; unsigned int unk05CC; unsigned int unk05D0;
    bool m_bFlag5D4;
    unsigned char unk5D5;
    unsigned char unk5D6;
    unsigned char unk5D7;
    unsigned int unk05D8; unsigned int unk05DC; unsigned int unk05E0; unsigned int unk05E4; unsigned int unk05E8; unsigned int unk05EC; unsigned int unk05F0; unsigned int unk05F4;
    unsigned int unk05F8; unsigned int unk05FC; unsigned int unk0600; unsigned int unk0604; unsigned int unk0608; unsigned int unk060C; unsigned int unk0610; unsigned int unk0614;
    unsigned int unk0618; unsigned int unk061C; unsigned int unk0620; unsigned int unk0624; unsigned int unk0628; unsigned int unk062C; unsigned int unk0630; unsigned int unk0634;
    unsigned int unk0638; unsigned int unk063C; unsigned int unk0640; unsigned int unk0644; unsigned int unk0648; unsigned int unk064C; unsigned int unk0650; unsigned int unk0654;
    unsigned int unk0658; unsigned int unk065C; unsigned int unk0660; unsigned int unk0664; unsigned int unk0668; unsigned int unk066C; unsigned int unk0670; unsigned int unk0674;
    unsigned int unk0678; unsigned int unk067C; unsigned int unk0680; unsigned int unk0684; unsigned int unk0688; unsigned int unk068C; unsigned int unk0690; unsigned int unk0694;
    unsigned int unk0698; unsigned int unk069C; unsigned int unk06A0; unsigned int unk06A4; unsigned int unk06A8; unsigned int unk06AC; unsigned int unk06B0; unsigned int unk06B4;
    unsigned int unk06B8; unsigned int unk06BC; unsigned int unk06C0; unsigned int unk06C4; unsigned int unk06C8; unsigned int unk06CC; unsigned int unk06D0; unsigned int unk06D4;
    unsigned int unk06D8; unsigned int unk06DC; unsigned int unk06E0; unsigned int unk06E4; unsigned int unk06E8; unsigned int unk06EC; unsigned int unk06F0; unsigned int unk06F4;
    unsigned int unk06F8; unsigned int unk06FC; unsigned int unk0700; unsigned int unk0704; unsigned int unk0708; unsigned int unk070C; unsigned int unk0710; unsigned int unk0714;
    unsigned int unk0718; unsigned int unk071C; unsigned int unk0720; unsigned int unk0724; unsigned int unk0728; unsigned int unk072C; unsigned int unk0730; unsigned int unk0734;
    unsigned int unk0738; unsigned int unk073C; unsigned int unk0740; unsigned int unk0744; unsigned int unk0748; unsigned int unk074C; unsigned int unk0750; unsigned int unk0754;
    unsigned int unk0758; unsigned int unk075C; unsigned int unk0760; unsigned int unk0764; unsigned int unk0768; unsigned int unk076C; unsigned int unk0770; unsigned int unk0774;
    unsigned int unk0778; unsigned int unk077C; unsigned int unk0780; unsigned int unk0784; unsigned int unk0788; unsigned int unk078C; unsigned int unk0790; unsigned int unk0794;
    unsigned int unk0798; unsigned int unk079C; unsigned int unk07A0; unsigned int unk07A4; unsigned int unk07A8; unsigned int unk07AC; unsigned int unk07B0; unsigned int unk07B4;
    unsigned int unk07B8; unsigned int unk07BC; unsigned int unk07C0; unsigned int unk07C4; unsigned int unk07C8; unsigned int unk07CC; unsigned int unk07D0; unsigned int unk07D4;
    unsigned int unk07D8; unsigned int unk07DC; unsigned int unk07E0; unsigned int unk07E4; unsigned int unk07E8; unsigned int unk07EC; unsigned int unk07F0; unsigned int unk07F4;
    unsigned int unk07F8; unsigned int unk07FC; unsigned int unk0800; unsigned int unk0804; unsigned int unk0808; unsigned int unk080C; unsigned int unk0810; unsigned int unk0814;
    unsigned int unk0818; unsigned int unk081C; unsigned int unk0820; unsigned int unk0824; unsigned int unk0828; unsigned int unk082C; unsigned int unk0830; unsigned int unk0834;
    unsigned int unk0838; unsigned int unk083C; unsigned int unk0840; unsigned int unk0844; unsigned int unk0848; unsigned int unk084C; unsigned int unk0850; unsigned int unk0854;
    unsigned int unk0858; unsigned int unk085C; unsigned int unk0860; unsigned int unk0864; unsigned int unk0868; unsigned int unk086C; unsigned int unk0870; unsigned int unk0874;
    unsigned int unk0878; unsigned int unk087C; unsigned int unk0880; unsigned int unk0884; unsigned int unk0888; unsigned int unk088C; unsigned int unk0890; unsigned int unk0894;
    unsigned int unk0898; unsigned int unk089C; unsigned int unk08A0; unsigned int unk08A4; unsigned int unk08A8; unsigned int unk08AC; unsigned int unk08B0; unsigned int unk08B4;
    unsigned int unk08B8;
    VBManager_e6da60* m_pShaderStreamInfo;
    bool BuildPacket(Packet_e6da60* pkPacket, NiGeometryData* pkModel,
        SkinWeightPackingSource* pkData, GeomData_e6da60* pkGeom);
};

// Fills pkPacket's stream count and values from pkGeom or by packing pkModel/pkData, sets flags, creates streams and releases them on failure.
// @fnv 0x00e6da60
bool ShaderStreamPacketBuilder::BuildPacket(Packet_e6da60* pkPacket, NiGeometryData* pkModel,
    SkinWeightPackingSource* pkData, GeomData_e6da60* pkGeom)
{
    unsigned int uiStreams = 0;
    unsigned int uiSingle = 0;
    unsigned int ItemUpdateArray = 0;
    unsigned int uiSingleValue = 0;
    unsigned int uiOutC, uiOutD, uiOutE, uiOutF, uiOutG;

    if (!pkGeom || !pkGeom->GetCachedStreams(&uiSingle, &ItemUpdateArray))
    {
        if (pkData && pkData->m_usType > 4)
            return false;
        ItemUpdateArray = 1;
        m_pShaderStreamInfo->Pack(pkModel, pkData, &uiStreams, &uiSingleValue,
            &uiOutC, &uiOutD, &uiOutE, &uiOutF, &uiOutG);
    }

    pkPacket->ResizeStreams(ItemUpdateArray);
    if (uiStreams)
    {
        pkPacket->SetSingleStream(uiStreams);
        if (pkPacket->m_uiCount > 0)
            pkPacket->m_puiStreams[0] = uiSingleValue;
    }
    else
    {
        pkPacket->SetStreams(uiSingle);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            unsigned int uiValue = pkGeom->GetStreamValue(i);
            if (i < pkPacket->m_uiCount)
                pkPacket->m_puiStreams[i] = uiValue;
        }
    }

    bool bHas28 = pkModel->m_pkColor != 0;
    bool bHas24 = pkModel->m_pkNormal != 0;
    bool bF000 = bHas24 && (pkModel->m_usDataFlags & 0xF000);
    unsigned int uiFlagBits = pkModel->m_usDataFlags & 1;
    if (uiFlagBits > DAT_011bf558)
        uiFlagBits = DAT_011bf558;
    unsigned int uiFlags = 0;
    if (bHas28)
        uiFlags = 0x400000;
    if (bHas24)
        uiFlags |= 0x800000;
    if (bF000)
        uiFlags |= 0x200000;
    pkPacket->m_uiValue1 = (uiFlagBits << 24) | uiFlags;

    if (pkGeom && m_bFlag5D4)
        pkPacket->m_ucFlag = pkGeom->GetFlagValue();

    unsigned int j;
    for (j = 0; j < ItemUpdateArray; j++)
    {
        if (!m_pShaderStreamInfo->CreateStream(pkPacket, j))
        {
            for (; j > 0; j--)
                pkPacket->m_pkOwnerManager->ReleaseStream(pkPacket, j);
            return false;
        }
    }
    return true;
}

struct LockedRect {
    int pitch;
    void* bits;
};
struct Texture {
    virtual void Unused00();
    virtual void Unused01();
    virtual void Unused02();
    virtual void Unused03();
    virtual void Unused04();
    virtual void Unused05();
    virtual void Unused06();
    virtual void Unused07();
    virtual void Unused08();
    virtual void Unused09();
    virtual void Unused10();
    virtual void Unused11();
    virtual void Unused12();
    virtual void Unused13();
    virtual void Unused14();
    virtual void Unused15();
    virtual void Unused16();
    virtual void Unused17();
    virtual void Unused18();
    virtual long __stdcall LockRect(unsigned int level, LockedRect* rectangle, const void* area, unsigned int flags);
};
struct RenderSource {
    virtual void Unused00();
    virtual void Unused01();
    virtual void Unused02();
    virtual void Unused03();
    virtual void Unused04();
    virtual void Unused05();
    virtual void Unused06();
    virtual void Unused07();
    virtual void Unused08();
    virtual void Unused09();
    virtual void Unused10();
    virtual void Unused11();
    virtual void Unused12();
    virtual void Unused13();
    virtual void Unused14();
    virtual void Unused15();
    virtual void Unused16();
    virtual void Unused17();
    virtual void Unused18();
    virtual void Unused19();
    virtual void Unused20();
    virtual void Unused21();
    virtual void Unused22();
    virtual void Unused23();
    virtual void Unused24();
    virtual void Unused25();
    virtual void Unused26();
    virtual void Unused27();
    virtual void Unused28();
    virtual void Unused29();
    virtual void Unused30();
    virtual void Unused31();
    virtual void Unused32();
    virtual void Unused33();
    virtual void Unused34();
    virtual void Unused35();
    virtual void Unused36();
    virtual void Unused37();
    virtual void Unused38();
    virtual Texture* GetDiscardTexture();
    virtual void Unused39();
    virtual void Unused40();
    virtual void Unused41();
    virtual void Unused42();
    virtual void Unused43();
    virtual Texture* GetRegularTexture();
    virtual bool IsLocked();
    virtual void SetLocked(bool locked);
};
struct SourceManager {
    virtual void Unused00();
    virtual void Unused01();
    virtual void Unused02();
    virtual void Unused03();
    virtual void Unused04();
    virtual void Unused05();
    virtual void Unused06();
    virtual void Unused07();
    virtual void Unused08();
    virtual void Unused09();
    virtual void Unused10();
    virtual void Unused11();
    virtual void Unused12();
    virtual void Unused13();
    virtual void Unused14();
    virtual void Unused15();
    virtual void Unused16();
    virtual void Unused17();
    virtual void Unused18();
    virtual void Unused19();
    virtual void Unused20();
    virtual void Unused21();
    virtual void Unused22();
    virtual void Unused23();
    virtual void Unused24();
    virtual void Unused25();
    virtual void Unused26();
    virtual void Unused27();
    virtual void Unused28();
    virtual void Unused29();
    virtual void Unused30();
    virtual void Unused31();
    virtual void Unused32();
    virtual void Unused33();
    virtual void Unused34();
    virtual void Unused35();
    virtual void Unused36();
    virtual void Unused37();
    virtual void Unused38();
    virtual void Unused39();
    virtual void Unused40();
    virtual void Unused41();
    virtual void Unused42();
    virtual RenderSource* GetRenderSource();
};
extern const char DAT_010ed96c[];
char* __cdecl GetHRESULTText(unsigned int status);
void __cdecl Object_DoNothing(const char* format, const char* message);
struct Renderer {
    void* __thiscall LockRenderSource(SourceManager* manager, int* pitch);
};
// Locks the manager's render source texture (discard or regular based on a flag) and returns its bits, storing the pitch; logs on failure.
// @fnv 0x00e6dd90
void* Renderer::LockRenderSource(SourceManager* manager, int* piPitch)
{
    *piPitch = 0;
    if (!manager) return 0;
    RenderSource* source = manager->GetRenderSource();
    if (!source) return 0;
    if (source->IsLocked()) return 0;
    unsigned int lockFlags = 0;
    Texture* texture;
    if (reinterpret_cast<const unsigned char*>(this)[0x6f5]) {
        texture = source->GetDiscardTexture();
        lockFlags = 0x2000;
    } else {
        texture = source->GetRegularTexture();
    }
    if (texture) {
        LockedRect lockedRect;
        long result = texture->LockRect(0, &lockedRect, 0, lockFlags);
        if (result < 0) {
            Object_DoNothing(DAT_010ed96c, GetHRESULTText(result));
        } else {
            void* bits = lockedRect.bits;
            *piPitch = lockedRect.pitch;
            source->SetLocked(true);
            return bits;
        }
    }
    return 0;
}

class FUN_00e6de70_B;
class FUN_00e6de70_C;
class FUN_00e6de70_D;
class FUN_00e6de70_A {
public:
virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3(); virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7(); virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18(); virtual void pad19(); virtual void pad20(); virtual void pad21(); virtual void pad22(); virtual void pad23(); virtual void pad24(); virtual void pad25(); virtual void pad26(); virtual void pad27(); virtual void pad28(); virtual void pad29(); virtual void pad30(); virtual void pad31(); virtual void pad32(); virtual void pad33(); virtual void pad34(); virtual void pad35(); virtual void pad36(); virtual void pad37(); virtual void pad38(); virtual void pad39(); virtual void pad40(); virtual void pad41(); virtual void pad42();
 virtual FUN_00e6de70_B* v43();
};
class FUN_00e6de70_B {
public:
virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3(); virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7(); virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18(); virtual void pad19(); virtual void pad20(); virtual void pad21(); virtual void pad22(); virtual void pad23(); virtual void pad24(); virtual void pad25(); virtual void pad26(); virtual void pad27(); virtual void pad28(); virtual void pad29(); virtual void pad30(); virtual void pad31(); virtual void pad32(); virtual void pad33(); virtual void pad34(); virtual void pad35(); virtual void pad36(); virtual void pad37(); virtual void pad38();
 virtual FUN_00e6de70_C* v39();
virtual void pad40(); virtual void pad41(); virtual void pad42(); virtual void pad43(); virtual void pad44();
 virtual FUN_00e6de70_C* v45();
 virtual bool v46();
 virtual void v47(unsigned int);
};
class FUN_00e6de70_C {
public:
virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3(); virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7(); virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18(); virtual void pad19();
 virtual int __stdcall v20(unsigned int);
};
class FUN_00e6de70_D {
public:
virtual void pad0(); virtual void pad1(); virtual void pad2(); virtual void pad3(); virtual void pad4(); virtual void pad5(); virtual void pad6(); virtual void pad7(); virtual void pad8(); virtual void pad9(); virtual void pad10(); virtual void pad11(); virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15(); virtual void pad16(); virtual void pad17(); virtual void pad18(); virtual void pad19(); virtual void pad20(); virtual void pad21(); virtual void pad22(); virtual void pad23(); virtual void pad24(); virtual void pad25(); virtual void pad26(); virtual void pad27(); virtual void pad28(); virtual void pad29(); virtual void pad30();
 virtual int __stdcall v31(FUN_00e6de70_C*, unsigned int);
};

class FUN_00e6de70_cls {
public:
    char unk0000[0x288];
    FUN_00e6de70_D* m_288;
    char unk028c[0x6f5 - 0x28c];
    unsigned char m_6f5;
    bool __thiscall NiDX9Renderer_UnLockDynamicTexture(FUN_00e6de70_A* a1);
};

const char* __cdecl GetHResultName(int code);
void __cdecl Object_DoNothing(const char* fmt, const char* text);

// @fnv 0x00e6de70
// src: EXE 0x00e6de70
bool __thiscall FUN_00e6de70_cls::NiDX9Renderer_UnLockDynamicTexture(FUN_00e6de70_A* a1)
{
    if (a1 == 0) {
        return false;
    }
    FUN_00e6de70_B* b = a1->v43();
    if (b == 0) {
        return false;
    }
    if (!b->v46()) {
        return false;
    }
    FUN_00e6de70_C* c;
    if (m_6f5 != 0) {
        c = b->v39();
    } else {
        c = b->v45();
    }
    if (c == 0) {
        return false;
    }
    int r = c->v20(0);
    if (r < 0) {
        Object_DoNothing("NiDX9Renderer::UnLockDynamicTexture Failed> UnlockRect - %s", GetHResultName(r));
        return false;
    }
    if (m_6f5 == 0) {
        unsigned int r2 = (unsigned int)b->v39();
        if (r2 == 0) {
            return false;
        }
        int r3 = m_288->v31(c, r2);
        if (r3 < 0) {
            Object_DoNothing("NiDX9Renderer::UnLockDynamicTexture Failed> UpdateTexture - %s", GetHResultName(r3));
            return false;
        }
    }
    b->v47(0);
    return true;
}



// @fnv 0x00e6df60
bool __fastcall RemoveRendererResource(NiDX9Renderer* self, void*, Param_00e6dc80* resource)
{
    resource->flag = 0;
    return ((RenderedCubeMapBase*)((char*)self + 0x8dc))->RemoveAt(reinterpret_cast<NiRenderedCubeMap*>(resource));
}

struct S_00e6e730_Arr {
    unsigned int* m_pBase;
    unsigned short unk4;
    unsigned short m_iElementCount;
    unsigned short m_last;
    unsigned short unka;
    unsigned int unkc;
    void RemoveAll() {
        for (unsigned short i = 0; i < m_iElementCount; i++)
            m_pBase[i] = 0;
        m_iElementCount = 0;
        m_last = 0;
    }
};
struct S_00e6e730_Cls {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    unsigned int unk980;
    unsigned int unk984;
    unsigned int unk988;
    unsigned int unk98c;
    unsigned int unk990;
    unsigned int unk994;
    unsigned int unk998;
    unsigned int unk99c;
    unsigned int unk9a0;
    unsigned int unk9a4;
    unsigned int unk9a8;
    unsigned int unk9ac;
    unsigned int unk9b0;
    unsigned int unk9b4;
    unsigned int unk9b8;
    unsigned int unk9bc;
    unsigned int unk9c0;
    unsigned int unk9c4;
    unsigned int unk9c8;
    unsigned int unk9cc;
    unsigned int unk9d0;
    unsigned int unk9d4;
    unsigned int unk9d8;
    unsigned int unk9dc;
    unsigned int unk9e0;
    unsigned int unk9e4;
    unsigned int unk9e8;
    unsigned int unk9ec;
    unsigned int unk9f0;
    unsigned int unk9f4;
    unsigned int unk9f8;
    unsigned int unk9fc;
    unsigned int unka00;
    unsigned int unka04;
    unsigned int unka08;
    unsigned int unka0c;
    unsigned int unka10;
    unsigned int unka14;
    unsigned int unka18;
    unsigned int unka1c;
    unsigned int unka20;
    unsigned int unka24;
    unsigned int unka28;
    unsigned int unka2c;
    unsigned int unka30;
    unsigned int unka34;
    unsigned int unka38;
    unsigned int unka3c;
    unsigned int unka40;
    unsigned int unka44;
    unsigned int unka48;
    unsigned int unka4c;
    unsigned int unka50;
    unsigned int unka54;
    unsigned int unka58;
    unsigned int unka5c;
    unsigned int unka60;
    unsigned int unka64;
    unsigned int unka68;
    unsigned int unka6c;
    unsigned int unka70;
    unsigned int unka74;
    unsigned int unka78;
    unsigned int unka7c;
    unsigned int unka80;
    unsigned int unka84;
    unsigned int unka88;
    unsigned int unka8c;
    unsigned int unka90;
    unsigned int unka94;
    unsigned int unka98;
    unsigned int unka9c;
    unsigned int unkaa0;
    unsigned int unkaa4;
    unsigned int unkaa8;
    unsigned int unkaac;
    unsigned int unkab0;
    unsigned int unkab4;
    unsigned int unkab8;
    unsigned int unkabc;
    unsigned int unkac0;
    unsigned int unkac4;
    unsigned int unkac8;
    unsigned int unkacc;
    unsigned int unkad0;
    unsigned int unkad4;
    S_00e6e730_Arr a;
    S_00e6e730_Arr b;
    void ClearArrays();
};
// Removes all elements from both arrays a and b.
// @fnv 0x00e6e730
void S_00e6e730_Cls::ClearArrays() {
    a.RemoveAll();
    b.RemoveAll();
}

struct RendererPool {
    unsigned int* slots;
    unsigned short flags;
    unsigned short count;
    unsigned short active;
    unsigned short extra;
    unsigned int reserved;

    void Reset() {
        for (unsigned short index = 0; index < count; ++index)
            slots[index] = 0;
        count = 0;
        active = 0;
    }
};
struct RendererPoolView : GraphicsRenderer { void ResetPools(); };
// Resets the two RendererPool objects located at offset 0xaf8 from this.
// @fnv 0x00e6e7b0
void RendererPoolView::ResetPools()
{
    RendererPool* pools =
        reinterpret_cast<RendererPool*>(reinterpret_cast<char*>(this) + 0xaf8);
    pools[0].Reset();
    pools[1].Reset();
}

extern int DAT_010eda84;
void __cdecl NiFree(void*);

extern MemoryManager _g_memoryManager;

// Resets the vtable, removes all entries, frees the hash table, and optionally deallocates the object when flags has bit 0 set.
// @fnv 0x00e6ea70
void* __fastcall DestroyRenderedCubeMap(RenderedCubeMapBase* self, void*, unsigned int flags) {
    *(void**)self = &DAT_010eda84;
    self->RemoveAll();
    NiFree(self->m_ppkHashTable);
    if (flags & 1) {
        _g_memoryManager.Deallocate(self);
    }
    return self;
}

extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);

class E6EC20Device {
public:
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class E6EC20Cache {
public:
    ~E6EC20Cache();

    static void operator delete(void* pvMem, unsigned int uiSize) { operator_delete_sized(pvMem, uiSize); }

    int unk00; int unk04; int unk08; int unk0C; int unk10;
};

class E6EC20List {
public:
    void RemoveAll();
};

extern E6EC20Device* g_pkE6EC20Device;
extern E6EC20Cache* g_pkE6EC20Cache;
extern void* g_hE6EC20Module;
extern void* (__stdcall* g_pfnE6EC20Create)(unsigned int uiVersion);
extern int (__stdcall* g_pfnE6EC20FreeLibrary)(void* hModule);
extern E6EC20List g_kE6EC20List;

// Releases the E6EC20 device, deletes the cache, frees the module, clears the create function pointer and empties the list.
// @fnv 0x00e6ec20
void ShutdownE6EC20()
{
    if (g_pkE6EC20Device) {
        g_pkE6EC20Device->Release();
        g_pkE6EC20Device = 0;
    }
    delete g_pkE6EC20Cache;
    g_pkE6EC20Cache = 0;
    if (g_hE6EC20Module)
        g_pfnE6EC20FreeLibrary(g_hE6EC20Module);
    g_pfnE6EC20Create = 0;
    g_kE6EC20List.RemoveAll();
}

// Renderer resource setup: original C++ reconstructed from InitializeRendererResources.
struct RendererStateSlot;
struct ResourceDescriptor { unsigned char unknown00; unsigned char format; };
struct RenderResource : RefObject {
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C;
    unsigned int dataOffset;
    unsigned int unk54, unk58;
    unsigned char** dataBase;
    RenderResource* FUN_00a7c190(int a, int b, ResourceDescriptor* d, int c, int e);
};
struct ResourceParameters {
    unsigned int count;
    unsigned int unk04;
    unsigned int unk08;
};
extern const char DAT_010edbb8[];
extern const char* DAT_0109b220;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
const char* __cdecl FUN_00a5b690(const char* name);
RefObject* __cdecl NiSourceTexture_Create(RenderResource* resource, const char* name, ResourceParameters* parameters);
struct RendererBridge {
    RendererStateSlot* State(unsigned int idx) {
        return reinterpret_cast<RendererStateSlot*>(reinterpret_cast<char*>(this) + 0x700 + 0x58 * idx);
    }
    ResourceDescriptor* Source() {
        return *reinterpret_cast<ResourceDescriptor**>(reinterpret_cast<char*>(this) + 0x860);
    }
    RefObject*& Target() {
        return *reinterpret_cast<RefObject**>(reinterpret_cast<char*>(this) + 0x8fc);
    }
    void CreateFormats(RendererStateSlot* state, unsigned int type, unsigned int flags);
    void InitFormats();
    bool InitializeRendererResources();
};
// Configures four renderer states, builds a render resource from the source descriptor, writes pixel data by format, and swaps the selected target resource.
// @fnv 0x00e6ec90
bool RendererBridge::InitializeRendererResources() {
    CreateFormats(State(0), 0, 3);
    CreateFormats(State(1), 1, 3);
    CreateFormats(State(2), 0, 5);
    CreateFormats(State(3), 1, 5);
    InitFormats();

    ResourceDescriptor* source = Source();
    void* storage = Object_DispatchCommandFour(0x74);
    RenderResource* resource;
    if (storage != 0) resource = static_cast<RenderResource*>(storage)->FUN_00a7c190(2, 1, source, 1, 1);
    else resource = 0;
    if (resource) resource->IncRefCount();

    unsigned char* pixels = *resource->dataBase + resource->dataOffset;
    if (source->format == 16) {
        pixels[3] = 0xff;
        pixels[2] = 0xff;
        pixels[1] = 0;
        pixels[0] = 0;
    } else if (source->format == 32) {
        pixels[3] = 0;
        pixels[2] = 0;
        pixels[7] = 0xff;
        pixels[6] = 0xff;
        pixels[5] = 0xff;
        pixels[4] = 0xff;
        pixels[1] = 0;
        pixels[0] = 0;
    }

    ResourceParameters resourceParams;
    resourceParams.count = 6;
    resourceParams.unk08 = 0;
    resourceParams.unk04 = 0;
    const char* name = FUN_00a5b690(DAT_010edbb8);
    RefObject* selected = NiSourceTexture_Create(resource, name, &resourceParams);
    if (Target() != selected) {
        if (Target()) Target()->DecRefCount();
        Target() = selected;
        if (selected) selected->IncRefCount();
    }
    if (name != DAT_0109b220) {
        InterlockedDecrement(reinterpret_cast<volatile long*>(const_cast<char*>(name) - 8));
    }
    resource->DecRefCount();
    return true;
}

extern "C" __declspec(dllimport) long __stdcall fnv_InterlockedDecrement(long volatile*);
extern char g_sentinel_012708e4;

class PktRefCounted {
public:
    virtual void unk00();
    virtual void Release();
    long refCount;
};

struct PktNode {
    unsigned int unk00;
    PktNode* next;
};

struct PktItem {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    PktRefCounted* m_10;
};

class PktHolder {
public:
    virtual ~PktHolder() {}
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual int GetFlag();
};

class PktOwner {
public:
    virtual void p00();
    virtual void p01();
    virtual PktNode* GetHead();
    virtual void p03();
    virtual void p04();
    virtual void p05();
    virtual void p06();
    virtual void p07();
    virtual void p08();
    virtual void p09();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual PktItem* GetItem();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    PktHolder* m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    PktItem* m_4c[6];
};

static inline void PktReleaseItem(PktItem* item)
{
    PktRefCounted*& ref = item->m_10;
    PktRefCounted* obj = ref;
    if (obj != 0) {
        if (fnv_InterlockedDecrement(&obj->refCount) == 0) {
            obj->Release();
        }
        ref = 0;
    }
}

// @fnv 0x00e6f9b0
bool __stdcall ReleaseOwnerItems(PktOwner* pOwner)
{
    PktHolder* holder = pOwner->m_24;
    if (holder != 0) {
        if (holder->GetFlag() != 0) {
            PktNode* n = pOwner->GetHead();
            if (n != 0) {
                do {
                    if ((void*)n == (void*)&g_sentinel_012708e4) {
                        goto found;
                    }
                    n = n->next;
                } while (n != 0);
            }
            {
                PktItem* item = pOwner->GetItem();
                PktReleaseItem(item);
            }
            goto done;
found:
            {
                PktItem** slot = pOwner->m_4c;
                for (int i = 6; i != 0; --i) {
                    PktReleaseItem(*slot);
                    ++slot;
                }
            }
        }
done:
        pOwner->m_24 = 0;
        delete holder;
    }
    return true;
}

namespace fnv_00e6fda0 {
struct TransformManager {
virtual void __thiscall slot0() = 0;
virtual void __thiscall slot1() = 0;
virtual void __thiscall slot2() = 0;
virtual void __thiscall slot3() = 0;
virtual void __thiscall slot4() = 0;
virtual void __thiscall slot5() = 0;
virtual void __thiscall slot6() = 0;
virtual void __thiscall slot7() = 0;
virtual void __thiscall slot8() = 0;
virtual void __thiscall slot9() = 0;
virtual void __thiscall slot10() = 0;
virtual void __thiscall slot11() = 0;
virtual void __thiscall UpdateGeometry(void* geometry) = 0;
};
struct Direct3DDeviceInterface {
virtual int __stdcall slot0() = 0;
virtual int __stdcall slot1() = 0;
virtual int __stdcall slot2() = 0;
virtual int __stdcall slot3() = 0;
virtual int __stdcall slot4() = 0;
virtual int __stdcall slot5() = 0;
virtual int __stdcall slot6() = 0;
virtual int __stdcall slot7() = 0;
virtual int __stdcall slot8() = 0;
virtual int __stdcall slot9() = 0;
virtual int __stdcall slot10() = 0;
virtual int __stdcall slot11() = 0;
virtual int __stdcall slot12() = 0;
virtual int __stdcall slot13() = 0;
virtual int __stdcall slot14() = 0;
virtual int __stdcall slot15() = 0;
virtual int __stdcall slot16() = 0;
virtual int __stdcall slot17() = 0;
virtual int __stdcall slot18() = 0;
virtual int __stdcall slot19() = 0;
virtual int __stdcall slot20() = 0;
virtual int __stdcall slot21() = 0;
virtual int __stdcall slot22() = 0;
virtual int __stdcall slot23() = 0;
virtual int __stdcall slot24() = 0;
virtual int __stdcall slot25() = 0;
virtual int __stdcall slot26() = 0;
virtual int __stdcall slot27() = 0;
virtual int __stdcall slot28() = 0;
virtual int __stdcall slot29() = 0;
virtual int __stdcall slot30() = 0;
virtual int __stdcall slot31() = 0;
virtual int __stdcall slot32() = 0;
virtual int __stdcall slot33() = 0;
virtual int __stdcall slot34() = 0;
virtual int __stdcall slot35() = 0;
virtual int __stdcall slot36() = 0;
virtual int __stdcall slot37() = 0;
virtual int __stdcall slot38() = 0;
virtual int __stdcall slot39() = 0;
virtual int __stdcall slot40() = 0;
virtual int __stdcall slot41() = 0;
virtual int __stdcall slot42() = 0;
virtual int __stdcall slot43() = 0;
virtual int __stdcall SetTransform(unsigned int state, const void* matrix) = 0;
};
extern "C" void __cdecl FUN_00b71a40(void* state, void* geometry, void* input, float weight);
struct Renderer {
    Direct3DDeviceInterface* GetDevice() { return *reinterpret_cast<Direct3DDeviceInterface**>(reinterpret_cast<char*>(this) + 0x288); }
    TransformManager* GetDebrisManager() { return *reinterpret_cast<TransformManager**>(reinterpret_cast<char*>(this) + 0x8b8); }
    void* GetState() { return reinterpret_cast<char*>(this) + 0x940; }
    void ApplyGeometryTransforms(void* frame, void* mapping, void* geometry);
};
// @fnv 0x00e6fda0
void Renderer::ApplyGeometryTransforms(void* frame, void* mapping, void* geometry) {
    GetDebrisManager()->UpdateGeometry(geometry);
    const float weight = *reinterpret_cast<float*>(reinterpret_cast<char*>(geometry) + 0x30);
    FUN_00b71a40(GetState(), geometry, reinterpret_cast<char*>(geometry) + 0x24, weight);
    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mapping) + 0x20) <= 4) {
        const char* const matrixBase = *reinterpret_cast<const char**>(reinterpret_cast<char*>(frame) + 0x28);
        for (unsigned int i = 0; i < 4; ++i) {
            GetDevice()->SetTransform(0x100 + i, matrixBase + 64 * (*reinterpret_cast<unsigned short**>(reinterpret_cast<char*>(mapping) + 4))[i]);
        }
    }
}
}  // namespace fnv_00e6fda0

class Ifc {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual unsigned char v40();
    virtual void v41();
    virtual unsigned char v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual Ifc* v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual unsigned char v53();
};

struct W { char unk0000[0x28]; int f28; };
struct Z { char unk0000[0xc]; W* w; };
struct Y { char unk0000[0xc]; Z* z; };
struct X { char unk0000[0x34]; int f34; };

struct Arg1 {
    char unk0000[0xb8];
    X* pB8;
    Y* pBc;
    Ifc* pC0;
};

class FUN_00e72c20_cls : public Ifc {
public:
    bool NiDX9Renderer_IsHardwareSkinned(Arg1* a1, Ifc* a2);
    char unk0004[0x5d1];
    unsigned char f5d5;
    char unk05d6[0x6f0 - 0x5d6];
    unsigned int f6f0;
};

// @fnv 0x00e72c20
// src: COMMUNITY 0x00e72c20
bool FUN_00e72c20_cls::NiDX9Renderer_IsHardwareSkinned(Arg1* a1, Ifc* pObj) {
    X* x = a1->pB8;
    if (x->f34 != 0) {
        return false;
    }
    Y* y = a1->pBc;
    if (y == 0) {
        return false;
    }
    Z* z = y->z;
    if (z == 0) {
        return false;
    }
    W* w = z->w;
    if (w->f28 != 0) {
        return true;
    }
    if (this->v40() & 2) {
        return true;
    }
    Ifc* obj = pObj;
    if (obj == 0) {
        obj = a1->pC0;
    }
    if (this->f6f0 > 0xfffe0000u && obj != 0 && obj->v53()) {
        return true;
    }
    if (this->f5d5 != 0 && obj != 0 && obj->v47() != 0) {
        Ifc* t = obj->v47();
        if (t->v42()) {
            return true;
        }
    }
    return false;
}

struct FUN_00e744b0_Blk52 { unsigned int d[13]; };
struct FUN_00e744b0_Blk16 { unsigned int d[4]; };
struct FUN_00e744b0_VObj {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual short Test36();
};
struct FUN_00e744b0_Src {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    FUN_00e744b0_Blk52 m_68;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    FUN_00e744b0_VObj* m_b8;
    unsigned int m_bc;
};
struct FUN_00e744b0_obj { void ProcessCollector(unsigned int a, unsigned int b, unsigned int c, unsigned int d, int e, int f); };
struct FUN_00e744b0_cls {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned char m_6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int m_8ac;
    unsigned int m_8b0;
    bool __thiscall NiDX9Renderer_IsHardwareSkinned(FUN_00e744b0_Src* p, int z);
    void __thiscall DrawStrip(FUN_00e744b0_Src* p, unsigned int b, unsigned int c, FUN_00e744b0_Blk52* B, FUN_00e744b0_Blk16* A);
    void __thiscall DrawMesh(FUN_00e744b0_Src* p, unsigned int b, unsigned int c, FUN_00e744b0_Blk52* B, FUN_00e744b0_Blk16* A, unsigned int f);
    void ProcessVObj(FUN_00e744b0_Src* ebx);
};
extern char DAT_011f4288[16];

// @fnv 0x00e744b0
void FUN_00e744b0_cls::ProcessVObj(FUN_00e744b0_Src* apSrc)
{
    if (m_6fc == 0) {
        FUN_00e744b0_VObj* vo = apSrc->m_b8;
        if (vo->Test36() != 0) {
            unsigned int bc = apSrc->m_bc;
            FUN_00e744b0_Blk52 B = apSrc->m_68;
            unsigned int* p20 = (unsigned int*)apSrc->m_20;
            unsigned int* src = (p20 != 0) ? p20 : (unsigned int*)DAT_011f4288;
            FUN_00e744b0_Blk16 A;
            A.d[0] = src[0]; A.d[1] = src[1]; A.d[2] = src[2]; A.d[3] = src[3];
            unsigned int esi = (unsigned int)vo;
            unsigned int edi = bc;
            bool r = NiDX9Renderer_IsHardwareSkinned(apSrc, 0);
            ((FUN_00e744b0_obj*)m_8ac)->ProcessCollector(m_8b0, esi, edi, *(unsigned int*)&r, 0, 0);
            if (r) {
                DrawStrip(apSrc, esi, edi, &B, &A);
            } else {
                DrawMesh(apSrc, esi, edi, &B, &A, *(unsigned int*)(esi + 0x34));
            }
        }
    }
}

struct RefObj_e75 {
    virtual void v0();
    virtual void vDelete();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void Process();
    long m_04;
};

struct PoolNode_e75 {
    PoolNode_e75* m_00;
    PoolNode_e75* m_04;
    RefObj_e75* m_08;
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class FUN_00e75000_cls {
public:
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int unk02B4;
    unsigned int unk02B8;
    unsigned int unk02BC;
    unsigned int unk02C0;
    unsigned int unk02C4;
    unsigned int unk02C8;
    unsigned int unk02CC;
    unsigned int unk02D0;
    unsigned int unk02D4;
    unsigned int unk02D8;
    unsigned int unk02DC;
    unsigned int unk02E0;
    unsigned int unk02E4;
    unsigned int unk02E8;
    unsigned int unk02EC;
    unsigned int unk02F0;
    unsigned int unk02F4;
    unsigned int unk02F8;
    unsigned int unk02FC;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030C;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031C;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032C;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033C;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034C;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035C;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036C;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037C;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038C;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039C;
    unsigned int unk03A0;
    unsigned int unk03A4;
    unsigned int unk03A8;
    unsigned int unk03AC;
    unsigned int unk03B0;
    unsigned int unk03B4;
    unsigned int unk03B8;
    unsigned int unk03BC;
    unsigned int unk03C0;
    unsigned int unk03C4;
    unsigned int unk03C8;
    unsigned int unk03CC;
    unsigned int unk03D0;
    unsigned int unk03D4;
    unsigned int unk03D8;
    unsigned int unk03DC;
    unsigned int unk03E0;
    unsigned int unk03E4;
    unsigned int unk03E8;
    unsigned int unk03EC;
    unsigned int unk03F0;
    unsigned int unk03F4;
    unsigned int unk03F8;
    unsigned int unk03FC;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040C;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041C;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042C;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043C;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044C;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045C;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046C;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047C;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048C;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049C;
    unsigned int unk04A0;
    unsigned int unk04A4;
    unsigned int unk04A8;
    unsigned int unk04AC;
    unsigned int unk04B0;
    unsigned int unk04B4;
    unsigned int unk04B8;
    unsigned int unk04BC;
    unsigned int unk04C0;
    unsigned int unk04C4;
    unsigned int unk04C8;
    unsigned int unk04CC;
    unsigned int unk04D0;
    unsigned int unk04D4;
    unsigned int unk04D8;
    unsigned int unk04DC;
    unsigned int unk04E0;
    unsigned int unk04E4;
    unsigned int unk04E8;
    unsigned int unk04EC;
    unsigned int unk04F0;
    unsigned int unk04F4;
    unsigned int unk04F8;
    unsigned int unk04FC;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050C;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051C;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052C;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053C;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054C;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055C;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056C;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057C;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058C;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059C;
    unsigned int unk05A0;
    unsigned int unk05A4;
    unsigned int unk05A8;
    unsigned int unk05AC;
    unsigned int unk05B0;
    unsigned int unk05B4;
    unsigned int unk05B8;
    unsigned int unk05BC;
    unsigned int unk05C0;
    unsigned int unk05C4;
    unsigned int unk05C8;
    unsigned int unk05CC;
    unsigned int unk05D0;
    unsigned int unk05D4;
    unsigned int unk05D8;
    unsigned int unk05DC;
    unsigned int unk05E0;
    unsigned int unk05E4;
    unsigned int unk05E8;
    unsigned int unk05EC;
    unsigned int unk05F0;
    unsigned int unk05F4;
    unsigned int unk05F8;
    unsigned int unk05FC;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060C;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061C;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062C;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063C;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064C;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065C;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066C;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067C;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068C;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069C;
    unsigned int unk06A0;
    unsigned int unk06A4;
    unsigned int unk06A8;
    unsigned int unk06AC;
    unsigned int unk06B0;
    unsigned int unk06B4;
    unsigned int unk06B8;
    unsigned int unk06BC;
    unsigned int unk06C0;
    unsigned int unk06C4;
    unsigned int unk06C8;
    unsigned int unk06CC;
    unsigned int unk06D0;
    unsigned int unk06D4;
    unsigned int unk06D8;
    unsigned int unk06DC;
    unsigned int unk06E0;
    unsigned int unk06E4;
    unsigned int unk06E8;
    unsigned int unk06EC;
    unsigned int unk06F0;
    unsigned int unk06F4;
    unsigned int unk06F8;
    unsigned char m_06FC;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070C;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071C;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072C;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073C;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074C;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075C;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076C;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077C;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078C;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079C;
    unsigned int unk07A0;
    unsigned int unk07A4;
    unsigned int unk07A8;
    unsigned int unk07AC;
    unsigned int unk07B0;
    unsigned int unk07B4;
    unsigned int unk07B8;
    unsigned int unk07BC;
    unsigned int unk07C0;
    unsigned int unk07C4;
    unsigned int unk07C8;
    unsigned int unk07CC;
    unsigned int unk07D0;
    unsigned int unk07D4;
    unsigned int unk07D8;
    unsigned int unk07DC;
    unsigned int unk07E0;
    unsigned int unk07E4;
    unsigned int unk07E8;
    unsigned int unk07EC;
    unsigned int unk07F0;
    unsigned int unk07F4;
    unsigned int unk07F8;
    unsigned int unk07FC;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080C;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081C;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082C;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083C;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084C;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085C;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086C;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087C;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088C;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089C;
    unsigned int unk08A0;
    unsigned int unk08A4;
    unsigned int unk08A8;
    unsigned int unk08AC;
    unsigned int unk08B0;
    unsigned int unk08B4;
    unsigned int unk08B8;
    unsigned int unk08BC;
    unsigned int unk08C0;
    unsigned int unk08C4;
    unsigned int unk08C8;
    unsigned int unk08CC;
    unsigned int unk08D0;
    unsigned int unk08D4;
    unsigned int unk08D8;
    unsigned int unk08DC;
    unsigned int unk08E0;
    unsigned int unk08E4;
    unsigned int unk08E8;
    unsigned int unk08EC;
    unsigned int unk08F0;
    unsigned int unk08F4;
    unsigned int unk08F8;
    unsigned int unk08FC;
    PoolNode_e75* m_0900;
    PoolNode_e75* m_0904;
    unsigned int m_0908;

    bool ProcessPendingNodes();
};

// While m_06FC is zero, pops each node from the m_0900 list, releases its m_08 object, returns the node to the pool, and processes the object.
// @fnv 0x00e75000
bool FUN_00e75000_cls::ProcessPendingNodes() {
    if (m_06FC == 0 && m_0908 != 0) {
        do {
            PoolNode_e75* node = m_0900;
            PoolNode_e75* next = node->m_00;
            m_0900 = next;
            if (next != 0) {
                next->m_04 = 0;
            } else {
                m_0904 = 0;
            }
            RefObj_e75* obj = node->m_08;
            if (obj != 0) {
                InterlockedIncrement(&obj->m_04);
            }
            RefObj_e75* held = node->m_08;
            if (held != 0) {
                if (InterlockedDecrement(&held->m_04) == 0) {
                    held->vDelete();
                }
                node->m_08 = 0;
            }
            g_011c5f80.Lock(0);
            node->m_04 = 0;
            node->m_00 = (PoolNode_e75*)DAT_011c5f58;
            DAT_011c5f84 -= 1;
            DAT_011c5f58 = node;
            if (DAT_011c5f84 == 0) {
                g_011c5f80.m_uiOwningThreadID = 0;
            }
            m_0908 -= 1;
            obj->Process();
            if (InterlockedDecrement(&obj->m_04) == 0) {
                obj->vDelete();
            }
        } while (m_0908 != 0);
    }
    return true;
}

__forceinline void* NiPropertyState::operator new(unsigned int amount) { return g_memoryManager.Allocate(amount); }

namespace fnv_00e750e0 {
struct Property : NiMemObject { int unk00,unk04,unk08,unk0c,unk10,unk14; unsigned short flags,unk1a; };
// The default render properties RenderInput builds: their constructors store vftables 0x0109b72c and 0x0109b7fc,
// which RTTI names NiVertexColorProperty and NiZBufferProperty.

struct NiZBufferProperty : Property { NiZBufferProperty() throw(); };

struct Input { int unk00,unk04,unk08,unk0c; void* content; Property* property; int unk18; void* extra; };
struct Manager { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void Set(unsigned,Input*); };
extern const NiMatrix3 identityMatrix;
extern const NiPoint3 NiPoint3_ZERO;
// Copy the matrix storage without invoking a default constructor before the overwrite.
struct LocalTransform { unsigned int rotationStorage[sizeof(NiMatrix3) / sizeof(unsigned int)]; NiPoint3 translation; float scale; __forceinline LocalTransform() { *reinterpret_cast<NiMatrix3*>(rotationStorage)=identityMatrix;CopyPoint3Storage(translation, NiPoint3_ZERO);scale=1.0f; } };
extern Property* lastProperty;
struct Renderer {
 int unk000;
 int unk004;
 int unk008;
 NiPropertyState* state;
 int mode;
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
 int unk2b4;
 int unk2b8;
 int unk2bc;
 int unk2c0;
 int unk2c4;
 int unk2c8;
 int unk2cc;
 int unk2d0;
 int unk2d4;
 int unk2d8;
 int unk2dc;
 int unk2e0;
 int unk2e4;
 int unk2e8;
 int unk2ec;
 int unk2f0;
 int unk2f4;
 int unk2f8;
 int unk2fc;
 int unk300;
 int unk304;
 int unk308;
 int unk30c;
 int unk310;
 int unk314;
 int unk318;
 int unk31c;
 int unk320;
 int unk324;
 int unk328;
 int unk32c;
 int unk330;
 int unk334;
 int unk338;
 int unk33c;
 int unk340;
 int unk344;
 int unk348;
 int unk34c;
 int unk350;
 int unk354;
 int unk358;
 int unk35c;
 int unk360;
 int unk364;
 int unk368;
 int unk36c;
 int unk370;
 int unk374;
 int unk378;
 int unk37c;
 int unk380;
 int unk384;
 int unk388;
 int unk38c;
 int unk390;
 int unk394;
 int unk398;
 int unk39c;
 int unk3a0;
 int unk3a4;
 int unk3a8;
 int unk3ac;
 int unk3b0;
 int unk3b4;
 int unk3b8;
 int unk3bc;
 int unk3c0;
 int unk3c4;
 int unk3c8;
 int unk3cc;
 int unk3d0;
 int unk3d4;
 int unk3d8;
 int unk3dc;
 int unk3e0;
 int unk3e4;
 int unk3e8;
 int unk3ec;
 int unk3f0;
 int unk3f4;
 int unk3f8;
 int unk3fc;
 int unk400;
 int unk404;
 int unk408;
 int unk40c;
 int unk410;
 int unk414;
 int unk418;
 int unk41c;
 int unk420;
 int unk424;
 int unk428;
 int unk42c;
 int unk430;
 int unk434;
 int unk438;
 int unk43c;
 int unk440;
 int unk444;
 int unk448;
 int unk44c;
 int unk450;
 int unk454;
 int unk458;
 int unk45c;
 int unk460;
 int unk464;
 int unk468;
 int unk46c;
 int unk470;
 int unk474;
 int unk478;
 int unk47c;
 int unk480;
 int unk484;
 int unk488;
 int unk48c;
 int unk490;
 int unk494;
 int unk498;
 int unk49c;
 int unk4a0;
 int unk4a4;
 int unk4a8;
 int unk4ac;
 int unk4b0;
 int unk4b4;
 int unk4b8;
 int unk4bc;
 int unk4c0;
 int unk4c4;
 int unk4c8;
 int unk4cc;
 int unk4d0;
 int unk4d4;
 int unk4d8;
 int unk4dc;
 int unk4e0;
 int unk4e4;
 int unk4e8;
 int unk4ec;
 int unk4f0;
 int unk4f4;
 int unk4f8;
 int unk4fc;
 int unk500;
 int unk504;
 int unk508;
 int unk50c;
 int unk510;
 int unk514;
 int unk518;
 int unk51c;
 int unk520;
 int unk524;
 int unk528;
 int unk52c;
 int unk530;
 int unk534;
 int unk538;
 int unk53c;
 int unk540;
 int unk544;
 int unk548;
 int unk54c;
 int unk550;
 int unk554;
 int unk558;
 int unk55c;
 int unk560;
 int unk564;
 int unk568;
 int unk56c;
 int unk570;
 int unk574;
 int unk578;
 int unk57c;
 int unk580;
 int unk584;
 int unk588;
 int unk58c;
 int unk590;
 int unk594;
 int unk598;
 int unk59c;
 int unk5a0;
 int unk5a4;
 int unk5a8;
 int unk5ac;
 int unk5b0;
 int unk5b4;
 int unk5b8;
 int unk5bc;
 int unk5c0;
 int unk5c4;
 int unk5c8;
 int unk5cc;
 int unk5d0;
 int unk5d4;
 int unk5d8;
 int unk5dc;
 int unk5e0;
 int unk5e4;
 int unk5e8;
 int unk5ec;
 int unk5f0;
 int unk5f4;
 int unk5f8;
 int unk5fc;
 int unk600;
 int unk604;
 int unk608;
 int unk60c;
 int unk610;
 int unk614;
 int unk618;
 int unk61c;
 int unk620;
 int unk624;
 int unk628;
 int unk62c;
 int unk630;
 int unk634;
 int unk638;
 int unk63c;
 int unk640;
 int unk644;
 int unk648;
 int unk64c;
 int unk650;
 int unk654;
 int unk658;
 int unk65c;
 int unk660;
 int unk664;
 int unk668;
 int unk66c;
 int unk670;
 int unk674;
 int unk678;
 int unk67c;
 int unk680;
 int unk684;
 int unk688;
 int unk68c;
 int unk690;
 int unk694;
 int unk698;
 int unk69c;
 int unk6a0;
 int unk6a4;
 int unk6a8;
 int unk6ac;
 int unk6b0;
 int unk6b4;
 int unk6b8;
 int unk6bc;
 int unk6c0;
 int unk6c4;
 int unk6c8;
 int unk6cc;
 int unk6d0;
 int unk6d4;
 int unk6d8;
 int unk6dc;
 int unk6e0;
 int unk6e4;
 int unk6e8;
 int unk6ec;
 int unk6f0;
 int unk6f4;
 int unk6f8;
 bool active; unsigned char unk6fd,unk6fe,unk6ff;
 int unk700;
 int unk704;
 int unk708;
 int unk70c;
 int unk710;
 int unk714;
 int unk718;
 int unk71c;
 int unk720;
 int unk724;
 int unk728;
 int unk72c;
 int unk730;
 int unk734;
 int unk738;
 int unk73c;
 int unk740;
 int unk744;
 int unk748;
 int unk74c;
 int unk750;
 int unk754;
 int unk758;
 int unk75c;
 int unk760;
 int unk764;
 int unk768;
 int unk76c;
 int unk770;
 int unk774;
 int unk778;
 int unk77c;
 int unk780;
 int unk784;
 int unk788;
 int unk78c;
 int unk790;
 int unk794;
 int unk798;
 int unk79c;
 int unk7a0;
 int unk7a4;
 int unk7a8;
 int unk7ac;
 int unk7b0;
 int unk7b4;
 int unk7b8;
 int unk7bc;
 int unk7c0;
 int unk7c4;
 int unk7c8;
 int unk7cc;
 int unk7d0;
 int unk7d4;
 int unk7d8;
 int unk7dc;
 int unk7e0;
 int unk7e4;
 int unk7e8;
 int unk7ec;
 int unk7f0;
 int unk7f4;
 int unk7f8;
 int unk7fc;
 int unk800;
 int unk804;
 int unk808;
 int unk80c;
 int unk810;
 int unk814;
 int unk818;
 int unk81c;
 int unk820;
 int unk824;
 int unk828;
 int unk82c;
 int unk830;
 int unk834;
 int unk838;
 int unk83c;
 int unk840;
 int unk844;
 int unk848;
 int unk84c;
 int unk850;
 int unk854;
 int unk858;
 int unk85c;
 int unk860;
 int unk864;
 int unk868;
 int unk86c;
 int unk870;
 int unk874;
 int unk878;
 int unk87c;
 int unk880;
 int unk884;
 int unk888;
 int unk88c;
 int unk890;
 int unk894;
 int unk898;
 int unk89c;
 int unk8a0;
 int unk8a4;
 NiPropertyState* properties;
 Manager* manager;
 unsigned handle;
 void RenderInput(Input*);
 void NiDX9Renderer_PackScreenTextureGeomBuffer(Input*);
 void DrawMesh(int,int,int,LocalTransform*,Bound*,void*);
};
// If not active and input has content, builds default properties when missing, sets state/mode, passes input to manager, renders it, then restores state and mode.
// @fnv 0x00e750e0
void Renderer::RenderInput(Input* input) {
 if(active) return;
 if(!input || !input->content) return;
 NiPropertyState* oldState=state;
 int oldMode=mode;
 if(!properties) {
  properties=new NiPropertyState;
  // The original allocation includes tail padding beyond the shared property layout.
  NiVertexColorProperty* p1=new (NiMemObject::operator new(0x1c)) NiVertexColorProperty;
  p1->m_uiObjectFlags=(p1->m_uiObjectFlags & 0xffd7)|0x10;
  properties->SetSlot((::Property*)p1);
  NiAlphaProperty* p2=::new (AllocateAlphaProperty) NiAlphaProperty;
  p2->m_usAlphaArg=(p2->m_usAlphaArg & 0xfeed)|0xed;
  properties->SetSlot((::Property*)p2);
  NiZBufferProperty* p3=new NiZBufferProperty;
  p3->flags&=0xfffc;
  properties->SetSlot((::Property*)p3);
 }
 properties->SetSlot((::Property*)input->property);
 state=properties;mode=0;
 manager->Set(handle,input);
 NiDX9Renderer_PackScreenTextureGeomBuffer(input);
 LocalTransform transform;
 // DrawMesh fills this scratch bound; leave its storage uninitialized.
 unsigned __int64 bound[sizeof(Bound) / sizeof(unsigned __int64)];
 DrawMesh(0,0,0,&transform,reinterpret_cast<Bound*>(bound),input->extra);
 properties->SetSlot((::Property*)lastProperty);
 state=oldState;mode=oldMode;
}
}  // namespace fnv_00e750e0

struct ShaderList : ConsolePointerListBase<ConsolePointerAllocator<unsigned int>, char*> {
    static void FreeNode(Node* pkNode) {
        pkNode->data = 0;
        g_011c5f80.Lock(0);
        pkNode->prev = 0;
        pkNode->next = (Node*)DAT_011c5f58;
        DAT_011c5f58 = pkNode;
        if (--DAT_011c5f84 == 0)
            g_011c5f80.m_uiOwningThreadID = 0;
    }
    char*& GetNext(Node*& pkPos) {
        char*& element = pkPos->data;
        pkPos = pkPos->next;
        return element;
    }
    Node* FindPos(char* element) {
        Node* pkStart = head;
        while (pkStart) {
            Node* pkPos = pkStart;
            if (element == GetNext(pkStart))
                return pkPos;
        }
        return 0;
    }
    char* RemoveHead() {
        Node* pkNode = head;
        char* element = pkNode->data;
        head = pkNode->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        FreeNode(pkNode);
        count--;
        return element;
    }
    char* RemovePos(Node* pkNode) {
        if (pkNode == head)
            return RemoveHead();
        if (pkNode == tail)
            return RemoveTail();
        char* element = pkNode->data;
        Node* pkPrev = pkNode->prev;
        Node* pkNext = pkNode->next;
        if (pkPrev)
            pkPrev->next = pkNext;
        if (pkNext)
            pkNext->prev = pkPrev;
        FreeNode(pkNode);
        count--;
        return element;
    }
    char* Remove(char* element) {
        Node* pkPos = FindPos(element);
        return pkPos ? RemovePos(pkPos) : 0;
    }
};

struct D3DShaderStub {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50();
    virtual void UnloadShader();
    void SetShaderObject(void* pkRenderer);
};

struct ConsoleRendererShaders {
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    ShaderList m_kShaderList;
    void NiDX9Renderer_PurgeAllD3DShaders();
};

// @fnv 0x00e75380
// src: COMMUNITY 0x00e75380
void ConsoleRendererShaders::NiDX9Renderer_PurgeAllD3DShaders() {
    while (m_kShaderList.count != 0) {
        D3DShaderStub* pkShader = (D3DShaderStub*)m_kShaderList.head->data;
        pkShader->UnloadShader();
        pkShader->SetShaderObject(0);
        m_kShaderList.Remove((char*)pkShader);
    }
}

class E757E0Renderer {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void Flush();
};

class E757E0Owner {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    E757E0Renderer* m_pOwnerShader;

    void NiDX9Renderer_GetLeftRightSwap();
};

// @fnv 0x00e757e0
// src: COMMUNITY 0x00e757e0
void E757E0Owner::NiDX9Renderer_GetLeftRightSwap() {
    m_pOwnerShader->Flush();
}

class E757F0Target {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void Notify(void* p);
};

class E757F0Owner {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    E757F0Target* m_pkTarget;

    bool NotifyTarget(void* p);
};

// @fnv 0x00e757f0
bool E757F0Owner::NotifyTarget(void* p)
{
    m_pkTarget->Notify(p);
    return true;
}

struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void Tail();
};

struct FUN_00e75a40_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    Target* m_8b8;
    void NiDX9Renderer_GetMaxFogValue();
};

// @fnv 0x00e75a40
// src: COMMUNITY 0x00e75a40
void FUN_00e75a40_cls::NiDX9Renderer_GetMaxFogValue()
{
    m_8b8->Tail();
}

struct P00 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P01 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P02 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P03 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P04 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P05 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P06 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P07 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P08 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P09 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P10 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P11 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P12 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P13 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P14 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P15 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P16 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P17 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P18 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P19 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P20 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P21 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P22 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P23 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P24 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P25 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P26 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P27 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P28 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P29 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P30 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P31 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P32 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P33 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P34 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P35 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P36 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P37 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P38 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P39 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P40 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P41 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P42 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P43 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P44 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P45 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P46 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P47 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P48 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P49 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P50 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P51 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P52 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P53 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P54 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7,f8,f9; };
struct P55 { unsigned int f0,f1,f2,f3,f4,f5,f6,f7; };

struct FUN_00e75a50_Interface
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16(float value);
};

struct FUN_00e75a50_owner :
    P00, P01, P02, P03, P04, P05, P06, P07,
    P08, P09, P10, P11, P12, P13, P14, P15,
    P16, P17, P18, P19, P20, P21, P22, P23,
    P24, P25, P26, P27, P28, P29, P30, P31,
    P32, P33, P34, P35, P36, P37, P38, P39,
    P40, P41, P42, P43, P44, P45, P46, P47,
    P48, P49, P50, P51, P52, P53, P54, P55
{
    FUN_00e75a50_Interface* unk8b8;
    void __thiscall NiDX9Renderer_SetMaxFogValue(float value);
};

// @fnv 0x00e75a50
// src: COMMUNITY 0x00e75a50
void __thiscall FUN_00e75a50_owner::NiDX9Renderer_SetMaxFogValue(float value)
{
    unk8b8->f16(value);
}

struct FUN_00e76570_item {
    unsigned int unk00;
    unsigned int unk04;
    char* data;
    unsigned int unk0c;
};

struct FUN_00e76570_ent {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct FUN_00e76570_obj {
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p);
};

class FUN_00e76570_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int m_20;
    FUN_00e76570_item* m_24;
    unsigned char m_28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned int unk2c;
    FUN_00e76570_obj* m_30;

    bool NiDX9ShaderDeclaration_ClearAllEntries(unsigned int index);
};

// If index is below m_20, resets each of m_1c entries in the item at m_24+index, sets m_28, and calls vtable slot 2 on m_30 before clearing it.
// @fnv 0x00e76570
// src: COMMUNITY 0x00e76570
bool FUN_00e76570_cls::NiDX9ShaderDeclaration_ClearAllEntries(unsigned int index)
{
    if (index >= m_20) {
        return false;
    }
    FUN_00e76570_item* item = m_24 + index;
    unsigned int i = 0;
    if (i < m_1c) {
        unsigned int off = 0;
        do {
            FUN_00e76570_ent* e = (FUN_00e76570_ent*)(item->data + off);
            i++;
            e->m_08 = 0xffffffff;
            e->m_0c = 0x11;
            off += 0x1c;
        } while (i < m_1c);
    }
    FUN_00e76570_obj* obj = m_30;
    m_28 = 1;
    if (obj != 0) {
        void** vt = *(void***)obj;
        ((void (__stdcall*)(void*))vt[2])(obj);
        m_30 = 0;
    }
    return true;
}

// AddEntry - NiDX9ShaderDeclaration helper.
//
// Appends one 8-byte vertex-declaration entry to the declaration's entry
//
//   entry.f00 = flags                     (the caller's second argument)
//   entry.f02 = desc->f04                 (a 16-bit slot of the descriptor)
//   entry.f04 = usage table 1 [desc->f0c]
//   entry.f05 = usage table 2 [desc->f10]
//   entry.f06 = usage table 3 [desc->f14]
//   entry.f07 = desc->f18
//
// The three usage tables are 4-byte-stride tables whose first byte carries
// the value; the return value comes from a fourth table indexed by the same
// descriptor word f0c, but only when f0c is below the table's size (0x12).

// A four-byte table cell; only the first byte is used by the caller.
struct FUN_00e76660_UsageCell {
    unsigned char value;
    unsigned char unused1;
    unsigned char unused2;
    unsigned char FlushUsageData;
};

extern FUN_00e76660_UsageCell DAT_011bee68[];
extern FUN_00e76660_UsageCell DAT_011beeb0[];
extern FUN_00e76660_UsageCell DAT_011beecc[];
extern unsigned int DAT_0126f508[];

// The per-attribute descriptor handed in by the caller.
struct FUN_00e76660_Descriptor {
    unsigned int unk00;
    unsigned short f04;
    unsigned short unk06;
    unsigned int unk08;
    int f0c;
    int f10;
    int f14;
    unsigned char f18;
};

// One 8-byte entry of the declaration's entry array.
struct FUN_00e76660_Entry {
    unsigned short f00;
    unsigned short f02;
    unsigned char f04;
    unsigned char f05;
    unsigned char f06;
    unsigned char f07;
};

// The declaration object itself.
struct FUN_00e76660_Declaration {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_uiItemCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    FUN_00e76660_Entry* m_entries;

    int AddEntry(FUN_00e76660_Descriptor* pDescriptor, unsigned short flags);
};

// Stores flags and descriptor fields into the next entry, advances the entry index, and returns a table value indexed by f0c unless f0c is at least 0x12.
// @fnv 0x00e76660
int FUN_00e76660_Declaration::AddEntry(FUN_00e76660_Descriptor* pDescriptor, unsigned short flags)
{
    m_entries[m_uiItemCount].f00 = flags;
    m_entries[m_uiItemCount].f02 = pDescriptor->f04;
    m_entries[m_uiItemCount].f04 = DAT_011bee68[pDescriptor->f0c].value;
    m_entries[m_uiItemCount].f05 = DAT_011beeb0[pDescriptor->f10].value;
    m_entries[m_uiItemCount].f06 = DAT_011beecc[pDescriptor->f14].value;
    m_entries[m_uiItemCount].f07 = pDescriptor->f18;
    m_uiItemCount++;
    if (pDescriptor->f0c >= 0x12)
        return 0;
    return DAT_0126f508[pDescriptor->f0c];
}

struct ShaderVertexDecl {
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct ShaderVertexElement;
struct ShaderD3DDevice {
    virtual void __stdcall dv00();
    virtual void __stdcall dv01();
    virtual void __stdcall dv02();
    virtual void __stdcall dv03();
    virtual void __stdcall dv04();
    virtual void __stdcall dv05();
    virtual void __stdcall dv06();
    virtual void __stdcall dv07();
    virtual void __stdcall dv08();
    virtual void __stdcall dv09();
    virtual void __stdcall dv10();
    virtual void __stdcall dv11();
    virtual void __stdcall dv12();
    virtual void __stdcall dv13();
    virtual void __stdcall dv14();
    virtual void __stdcall dv15();
    virtual void __stdcall dv16();
    virtual void __stdcall dv17();
    virtual void __stdcall dv18();
    virtual void __stdcall dv19();
    virtual void __stdcall dv20();
    virtual void __stdcall dv21();
    virtual void __stdcall dv22();
    virtual void __stdcall dv23();
    virtual void __stdcall dv24();
    virtual void __stdcall dv25();
    virtual void __stdcall dv26();
    virtual void __stdcall dv27();
    virtual void __stdcall dv28();
    virtual void __stdcall dv29();
    virtual void __stdcall dv30();
    virtual void __stdcall dv31();
    virtual void __stdcall dv32();
    virtual void __stdcall dv33();
    virtual void __stdcall dv34();
    virtual void __stdcall dv35();
    virtual void __stdcall dv36();
    virtual void __stdcall dv37();
    virtual void __stdcall dv38();
    virtual void __stdcall dv39();
    virtual void __stdcall dv40();
    virtual void __stdcall dv41();
    virtual void __stdcall dv42();
    virtual void __stdcall dv43();
    virtual void __stdcall dv44();
    virtual void __stdcall dv45();
    virtual void __stdcall dv46();
    virtual void __stdcall dv47();
    virtual void __stdcall dv48();
    virtual void __stdcall dv49();
    virtual void __stdcall dv50();
    virtual void __stdcall dv51();
    virtual void __stdcall dv52();
    virtual void __stdcall dv53();
    virtual void __stdcall dv54();
    virtual void __stdcall dv55();
    virtual void __stdcall dv56();
    virtual void __stdcall dv57();
    virtual void __stdcall dv58();
    virtual void __stdcall dv59();
    virtual void __stdcall dv60();
    virtual void __stdcall dv61();
    virtual void __stdcall dv62();
    virtual void __stdcall dv63();
    virtual void __stdcall dv64();
    virtual void __stdcall dv65();
    virtual void __stdcall dv66();
    virtual void __stdcall dv67();
    virtual void __stdcall dv68();
    virtual void __stdcall dv69();
    virtual void __stdcall dv70();
    virtual void __stdcall dv71();
    virtual void __stdcall dv72();
    virtual void __stdcall dv73();
    virtual void __stdcall dv74();
    virtual void __stdcall dv75();
    virtual void __stdcall dv76();
    virtual void __stdcall dv77();
    virtual void __stdcall dv78();
    virtual void __stdcall dv79();
    virtual void __stdcall dv80();
    virtual void __stdcall dv81();
    virtual void __stdcall dv82();
    virtual void __stdcall dv83();
    virtual void __stdcall dv84();
    virtual void __stdcall dv85();
    virtual long __stdcall CreateVertexDeclaration(const ShaderVertexElement*, ShaderVertexDecl**);
};

struct ShaderMemMgr {
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern ShaderMemMgr g_shaderMemMgr;

inline void* operator new[](unsigned int size) { return g_shaderMemMgr.Allocate(size); }
inline void operator delete[](void* p) { g_shaderMemMgr.Deallocate(p); }

struct ShaderVertexElement {
    unsigned short Stream;
    unsigned short Offset;
    unsigned char Type;
    unsigned char Method;
    unsigned char Usage;
    unsigned char UsageIndex;

};

struct ShaderStreamMapping {
    unsigned int m_uiPreferredStream;
    unsigned int m_uiValue2;
    unsigned int m_uiValue3;
    unsigned int m_eRequestType;
    unsigned int m_uiValue5;
    unsigned int m_uiValue6;
    unsigned int m_uiValue7;
};

struct ShaderStreamInfo {
    bool m_bStreamFlag;
    unsigned int m_uiStreamIndex;
    ShaderStreamMapping* m_pkEntryArray;
    unsigned int m_uiStride;
};

class NiDX9ShaderDeclStub {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ShaderD3DDevice* m_pD3DDevice;
    unsigned int m_uiVertexElementCount;
    unsigned int m_uiBufferStride;
    unsigned int m_uiShaderRegisterCount;
    unsigned int m_uiRegisterStreamCount;
    ShaderStreamInfo* m_pShaderRegisterStream;
    bool m_bHasChanges;
    ShaderVertexElement* m_pkVertexElements;
    ShaderVertexDecl* m_pkD3DVertexDeclaration;

    unsigned int SetEntryAlias(ShaderStreamMapping* pkEntry, unsigned int uiStream);
    ShaderVertexDecl* BuildVertexDeclaration();
};

// Rebuilds the D3D vertex declaration from the stream entries, counting active elements, reallocating the element array, and calling CreateVertexDeclaration.
// @fnv 0x00e76a80
ShaderVertexDecl* NiDX9ShaderDeclStub::BuildVertexDeclaration()
{
    unsigned int ItemUpdateArray = 0;
    ShaderVertexDecl* hDecl = m_pkD3DVertexDeclaration;
    if (m_bHasChanges)
    {
    if (hDecl)
    {
        hDecl->Release();
        m_pkD3DVertexDeclaration = 0;
    }

    for (unsigned int i = 0; i < m_uiRegisterStreamCount; i++)
    {
        ShaderStreamInfo* pkStream = &m_pShaderRegisterStream[i];
        if (pkStream)
        {
            pkStream->m_bStreamFlag = false;
            for (unsigned int j = 0; j < m_uiShaderRegisterCount; j++)
            {
                ShaderStreamMapping* pkEntry = &pkStream->m_pkEntryArray[j];
                if (pkEntry->m_uiValue3 != 0xffffffff && pkEntry->m_eRequestType != 0x11)
                {
                    ItemUpdateArray++;
                    pkStream->m_bStreamFlag = true;
                }
            }
        }
    }
    if (ItemUpdateArray > 0)
        ItemUpdateArray++;

    if (m_uiVertexElementCount < ItemUpdateArray)
    {
        delete[] m_pkVertexElements;
        m_pkVertexElements = 0;
    }

    if (ItemUpdateArray == 0)
    {
        m_uiVertexElementCount = 0;
        return 0;
    }

    if (m_pkVertexElements == 0)
    {
        m_uiVertexElementCount = ItemUpdateArray;
        m_pkVertexElements = new ShaderVertexElement[m_uiVertexElementCount];
    }

    m_uiBufferStride = 0;
    for (unsigned int i = 0; i < m_uiRegisterStreamCount; i++)
    {
        ShaderStreamInfo* pkStream = &m_pShaderRegisterStream[i];
        if (pkStream->m_bStreamFlag)
        {
            unsigned int uiElapsedMilliseconds = 0;
            for (unsigned int j = 0; j < m_uiShaderRegisterCount; j++)
            {
                ShaderStreamMapping* pkEntry = &pkStream->m_pkEntryArray[j];
                if (pkEntry->m_uiValue3 != 0xffffffff && pkEntry->m_eRequestType != 0x11)
                {
                    pkEntry->m_uiValue2 = uiElapsedMilliseconds;
                    uiElapsedMilliseconds += SetEntryAlias(pkEntry, i);
                }
            }
            pkStream->m_uiStride = uiElapsedMilliseconds;
        }
    }

    m_pkVertexElements[m_uiBufferStride].Stream = 0xff;
    m_pkVertexElements[m_uiBufferStride].Offset = 0;
    m_pkVertexElements[m_uiBufferStride].Type = 0x11;
    m_pkVertexElements[m_uiBufferStride].Method = 0;
    m_pkVertexElements[m_uiBufferStride].Usage = 0;
    m_pkVertexElements[m_uiBufferStride].UsageIndex = 0;

    long hr = m_pD3DDevice->CreateVertexDeclaration(m_pkVertexElements, &m_pkD3DVertexDeclaration);
    if (hr < 0)
        return 0;
    m_bHasChanges = false;
    return m_pkD3DVertexDeclaration;
    }
    return hDecl;
}

struct StreamCopyInfo {
    unsigned int format;
    unsigned short inputBytes;
    unsigned short unk06;
    unsigned short vertexCount;
    unsigned short unk0A;
    unsigned short* indices;
    unsigned char* source;
    unsigned int unk14;
    unsigned int sourceStride;
    unsigned int bytesPerVertex;
    unsigned int outputStride;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char* destination;
};
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00e77010
unsigned int __cdecl CopyVertexStream(StreamCopyInfo* stream)
{
    unsigned int bytesWritten = 0;
    const unsigned char* source = stream->source;
    unsigned char* destination = stream->destination;
    const unsigned short* indices = stream->indices;

    if (!source) {
        for (unsigned short vertex = 0; vertex < stream->vertexCount; ++vertex) {
            _fnv_zlib_memset(destination, 0, stream->bytesPerVertex);
            destination += stream->outputStride;
            bytesWritten += stream->bytesPerVertex;
        }
        return bytesWritten;
    }

    unsigned short availableComponents = stream->inputBytes - 8;
    unsigned short outputComponents = stream->format == 6 ? 2 : 4;
    unsigned short components = availableComponents > outputComponents
        ? outputComponents : availableComponents;

    if (indices) {
        unsigned short indexPosition = 0;
        for (unsigned short vertex = 0; vertex < stream->vertexCount; ++vertex) {
            const unsigned char* input = source + indices[indexPosition++] * stream->sourceStride;
            unsigned short* output = (unsigned short*)destination;
            unsigned short copied = 0;
            for (; copied < components; ++copied) {
                *output++ = *(const unsigned short*)input;
                input += 4;
            }
            for (; copied < outputComponents; ++copied)
                *output++ = 0;
            destination += stream->outputStride;
            bytesWritten += stream->bytesPerVertex;
        }
        return bytesWritten;
    }

    for (unsigned short vertex = 0; vertex < stream->vertexCount; ++vertex) {
        const unsigned char* input = source;
        unsigned short* output = (unsigned short*)destination;
        unsigned short copied = 0;
            for (; copied < components; ++copied) {
            *output++ = *(const unsigned short*)input;
            input += 4;
        }
        for (; copied < outputComponents; ++copied)
                *output++ = 0;
        source += stream->sourceStride;
        destination += stream->outputStride;
        bytesWritten += stream->bytesPerVertex;
    }
    return bytesWritten;
}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

struct PackShortInfo {
    int eType;
    unsigned short usComps;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    unsigned char* pucSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e773b0
unsigned int PackShortVertexData(PackShortInfo* pkInfo)
{
    unsigned int uiSize = 0;
    unsigned char* pucDest = pkInfo->pucDest;
    unsigned char* pucSrc = pkInfo->pucSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;

    if (!pucSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiSize += pkInfo->uiDestSize;
        }
        return uiSize;
    }

    unsigned short usComps = pkInfo->usComps - 16;
    unsigned short usMax = (pkInfo->eType != 6) ? 4 : 2;
    unsigned short usCopy = (usComps > usMax) ? usMax : usComps;

    if (pusRemap)
    {
        unsigned short usIdx = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            short* pSrc = (short*)(pucSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride);
            short* pDst = (short*)pucDest;
            unsigned short j;
            for (j = 0; j < usCopy; j++)
                *pDst++ = *pSrc++;
            for (; j < usMax; j++)
                *pDst++ = 0;
            uiSize += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            short* pSrc = (short*)pucSrc;
            short* pDst = (short*)pucDest;
            unsigned short j;
            for (j = 0; j < usCopy; j++)
                *pDst++ = *pSrc++;
            for (; j < usMax; j++)
                *pDst++ = 0;
            uiSize += pkInfo->uiDestSize;
            pucSrc += pkInfo->uiSrcStride;
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiSize;
}

void* _fnv_zlib_memset(void*, int, unsigned int);

struct FUN_00e77590_Info {
    int eType;
    unsigned short usComps;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    signed char* pcSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e77590
// src: COMMUNITY 0x00e77590
unsigned int NiD3DShaderDeclaration_Pack_ByteToShort(FUN_00e77590_Info* pkInfo)
{
    unsigned int uiTotal = 0;
    signed char* pcSrc = pkInfo->pcSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;

    if (!pcSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
        return uiTotal;
    }

    unsigned short usSrcComps = pkInfo->usComps - 0x14;
    unsigned short usDestComps = (pkInfo->eType != 6) ? 4 : 2;
    unsigned short usCopy = (usSrcComps > usDestComps) ? usDestComps : usSrcComps;

    if (pusRemap)
    {
        unsigned short usIdx = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            signed char* pcIn = pcSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride;
            short* psOut = (short*)pucDest;
            unsigned short j;
            for (j = 0; j < usCopy; j++)
                *psOut++ = *pcIn++;
            for (; j < usDestComps; j++)
                *psOut++ = 0;
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            signed char* pcIn = pcSrc;
            short* psOut = (short*)pucDest;
            unsigned short j;
            for (j = 0; j < usCopy; j++)
                *psOut++ = *pcIn++;
            for (; j < usDestComps; j++)
                *psOut++ = 0;
            uiTotal += pkInfo->uiDestSize;
            pcSrc += pkInfo->uiSrcStride;
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiTotal;
}

void* _fnv_zlib_memset(void*, int, unsigned int);

struct FUN_00e77950_Info {
    int eType;
    unsigned short usComps;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    float* pfSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e77950
// src: COMMUNITY 0x00e77950
unsigned int NiD3DShaderDeclaration_Pack_FloatToUnsignedByte(FUN_00e77950_Info* pkInfo)
{
    unsigned int uiTotal = 0;
    unsigned char* pucDest = pkInfo->pucDest;
    float* pfSrc = pkInfo->pfSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;

    if (!pfSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
        return uiTotal;
    }

    unsigned short usComps = pkInfo->usComps > 4 ? 4 : pkInfo->usComps;

    if (pusRemap)
    {
        unsigned short k = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            float* pfIn = (float*)((char*)pfSrc + pusRemap[k++] * pkInfo->uiSrcStride);
            unsigned char* pucOut = pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pucOut++ = (unsigned char)*pfIn++;
            if (j < 4)
                _fnv_zlib_memset(pucOut, 0, (unsigned short)(4 - j));
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            float* pfIn = pfSrc;
            unsigned char* pucOut = pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pucOut++ = (unsigned char)*pfIn++;
            if (j < 4)
                _fnv_zlib_memset(pucOut, 0, (unsigned short)(4 - j));
            pfSrc = (float*)((char*)pfSrc + pkInfo->uiSrcStride);
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
    }
    return uiTotal;
}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

struct FUN_00e77eb0_Info {
    int eType;
    unsigned short usComps;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    unsigned short* psSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e77eb0
// src: COMMUNITY 0x00e77eb0
unsigned int NiD3DShaderDeclaration_Pack_ShortToUnsignedByte(FUN_00e77eb0_Info* pkInfo)
{
    unsigned int uiSize = 0;
    unsigned short* psSrc = pkInfo->psSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;

    if (!psSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiSize += pkInfo->uiDestSize;
        }
        return uiSize;
    }

    unsigned short usCompCount = pkInfo->usComps - 12;
    unsigned short usComps = (usCompCount > 4) ? 4 : usCompCount;

    if (pusRemap)
    {
        unsigned short usIdx = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned short* psIn = (unsigned short*)((char*)psSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride);
            unsigned char* pucOut = pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pucOut++ = (unsigned char)*psIn++;
            if (j < 4)
                _fnv_zlib_memset(pucOut, 0, (unsigned short)(4 - j));
            uiSize += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned short* psIn = psSrc;
            unsigned char* pucOut = pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pucOut++ = (unsigned char)*psIn++;
            if (j < 4)
                _fnv_zlib_memset(pucOut, 0, (unsigned short)(4 - j));
            uiSize += pkInfo->uiDestSize;
            psSrc = (unsigned short*)((char*)psSrc + pkInfo->uiSrcStride);
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiSize;
}

// @fnv 0x00e78060
int __cdecl CopyStreamElements(FUN_00e79f40_Stream* pkInfo)
{
    int totalSize = 0;
    unsigned char* pucSource = (unsigned char*)pkInfo->src;
    unsigned short* pusIndices = pkInfo->indices;
    unsigned char* pucDest = (unsigned char*)pkInfo->dst;

    if (pucSource == 0) {
        unsigned short i = 0;
        if (i < pkInfo->count) {
            do {
                _fnv_zlib_memset(pucDest, 0, pkInfo->elemSize);
                totalSize += pkInfo->elemSize;
                pucDest += pkInfo->dstStride;
                ++i;
            } while (i < pkInfo->count);
        }
        return totalSize;
    }

    unsigned short count = (unsigned short)(pkInfo->type - 16);
    unsigned int uiCopyCount = count > 4 ? 4 : count;

    if (pusIndices) {
        unsigned short i = 0;
        unsigned short index = 0;
        if (i < pkInfo->count) {
            do {
                unsigned char* pRead = pucSource + pusIndices[index] * pkInfo->srcStride;
                ++index;
                unsigned char* pWrite = pucDest;
                unsigned short copied = 0;
                unsigned int remain = 0;
                if ((unsigned short)remain < (unsigned short)uiCopyCount) {
                    remain = (unsigned short)uiCopyCount;
                    copied = (unsigned short)remain;
                    do {
                        *pWrite = *pRead;
                        ++pWrite;
                        pRead += 2;
                    } while (--remain != 0);
                }
                if (copied < 4)
                    _fnv_zlib_memset(pWrite, 0, (unsigned short)(4 - copied));
                totalSize += pkInfo->elemSize;
                pucDest += pkInfo->dstStride;
                ++i;
            } while (i < pkInfo->count);
        }
    } else {
        unsigned short i = 0;
        if (i < pkInfo->count) {
            do {
                unsigned char* pRead = pucSource;
                unsigned char* pWrite = pucDest;
                unsigned short copied = 0;
                unsigned int remain = 0;
                if ((unsigned short)remain < (unsigned short)uiCopyCount) {
                    remain = (unsigned short)uiCopyCount;
                    copied = (unsigned short)remain;
                    do {
                        *pWrite = *pRead;
                        ++pWrite;
                        pRead += 2;
                    } while (--remain != 0);
                }
                if (copied < 4)
                    _fnv_zlib_memset(pWrite, 0, (unsigned short)(4 - copied));
                totalSize += pkInfo->elemSize;
                pucSource += pkInfo->srcStride;
                pucDest += pkInfo->dstStride;
                ++i;
            } while (i < pkInfo->count);
        }
    }
    return totalSize;
}

struct Stream_e78910 {
    unsigned int unk00;
    unsigned short type;
    unsigned short unk06;
    unsigned short count;
    unsigned short unk0A;
    unsigned short* indices;
    char* src;
    unsigned int unk14;
    unsigned int srcStride;
    unsigned int elemSize;
    unsigned int dstStride;
    unsigned int unk24;
    unsigned int unk28;
    char* dst;
};

static inline unsigned int PackColor_e78910(const short* v, unsigned short comps)
{
    int a;
    if (comps == 3)
        a = -1;
    else
        a = (unsigned short)v[3];
    return (((short)a & 0xff00) << 16) | ((v[0] & 0xff00) << 8) | (v[1] & 0xff00) | ((v[2] >> 8) & 0xff);
}

// @fnv 0x00e78910
int PackVertexColors(Stream_e78910* aStream)
{
    unsigned short* indices = aStream->indices;
    unsigned int* dst = (unsigned int*)aStream->dst;
    char* src = aStream->src;
    int size = 0;
    if (src == 0) {
        for (unsigned short i = 0; i < aStream->count; i++) {
            *dst = 0xffffffff;
            dst = (unsigned int*)((char*)dst + aStream->dstStride);
            size += aStream->elemSize;
        }
        return size;
    }
    unsigned short comps = aStream->type - 12;
    if (indices) {
        unsigned short j = 0;
        for (unsigned short i = 0; i < aStream->count; i++) {
            const short* v = (const short*)(src + indices[j++] * aStream->srcStride);
            *dst = PackColor_e78910(v, comps);
            dst = (unsigned int*)((char*)dst + aStream->dstStride);
            size += aStream->elemSize;
        }
    } else {
        for (unsigned short i = 0; i < aStream->count; i++) {
            *dst = PackColor_e78910((const short*)src, comps);
            src += aStream->srcStride;
            dst = (unsigned int*)((char*)dst + aStream->dstStride);
            size += aStream->elemSize;
        }
    }
    return size;
}

extern const char DAT_010ee7cc[];
void __cdecl NiMemObject_ReleaseStorage_00aa1490(void* apMemory, unsigned int auiSize);

struct FUN_00e78be0_cls {
    void* m_vptr00;
    unsigned int unk04;
    unsigned int m_u08;
    unsigned int unk0c;
    void* m_p10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int m_uCount20;
    char* m_pArr24;

    void BaseTeardown();
    void ProcessEntries_00e78be0() throw();
};

// Sets the vtable, frees each 16-byte array element's 0x1c-byte payload and the array, releases m_p10 via its vtable slot 2, then calls BaseTeardown.
// @fnv 0x00e78be0
// src: GUESS 0x00e78be0 (confidence: low)
void FUN_00e78be0_cls::ProcessEntries_00e78be0() throw()
{
    m_vptr00 = (void*)DAT_010ee7cc;
    if (m_pArr24 != 0) {
        unsigned int i = 0;
        if (m_uCount20 > 0) {
            unsigned int off = 0;
            do {
                char* e = m_pArr24 + off;
                if (e != 0) {
                    NiMemObject_ReleaseStorage_00aa1490(*(void**)(e + 8), 0x1c);
                }
                i++;
                off += 16;
            } while (i < m_uCount20);
        }
        NiMemObject_ReleaseStorage_00aa1490(m_pArr24, 0x10);
    }
    void* obj = m_p10;
    m_pArr24 = 0;
    m_u08 = 0;
    void** vt = *(void***)obj;
    ((void (__stdcall*)(void*))vt[2])(obj);
    m_p10 = 0;
    BaseTeardown();
}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

struct FUN_00e79370_Info {
    unsigned short usDestComps;
    unsigned short pad02;
    unsigned short usSrcType;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    unsigned char* pucSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e79370
// src: COMMUNITY 0x00e79370
unsigned int NiD3DShaderDeclaration_Pack_UnsignedLongToFloat(FUN_00e79370_Info* pkInfo)
{
    unsigned int uiTotal = 0;
    unsigned char* pucSrc = pkInfo->pucSrc;
    unsigned char* pucDest = pkInfo->pucDest;
    unsigned short* pusRemap = pkInfo->pusRemap;

    if (!pucSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
        return uiTotal;
    }

    unsigned short usSrcComps = pkInfo->usSrcType - 8;
    unsigned short usDestComps = pkInfo->usDestComps + 1;
    unsigned short usComps = (usSrcComps > usDestComps) ? usDestComps : usSrcComps;

    if (pusRemap)
    {
        unsigned short usIdx = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned int* puiSrc = (unsigned int*)(pucSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride);
            float* pfDest = (float*)pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pfDest++ = (float)*puiSrc++ * (1.0 / 4294967296.0);
            for (; j < usDestComps; j++)
                *pfDest++ = 0.0f;
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned int* puiSrc = (unsigned int*)pucSrc;
            float* pfDest = (float*)pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++)
                *pfDest++ = (float)*puiSrc++ * (1.0 / 4294967296.0);
            for (; j < usDestComps; j++)
                *pfDest++ = 0.0f;
            uiTotal += pkInfo->uiDestSize;
            pucSrc += pkInfo->uiSrcStride;
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiTotal;
}

struct NormalizedStream {
    unsigned short lastComponent, unk02;
    unsigned short type, unk06;
    unsigned short vertices, unk0a;
    unsigned short* indices;
    unsigned char* source;
    unsigned unk14, sourceStride, elementSize, destStride, unk24, unk28;
    unsigned char* dest;
};
// @fnv 0x00e79b40
unsigned __cdecl NormalizeVertexStream(NormalizedStream* pStream) {
    unsigned a = 0;
    unsigned char* src = pStream->source;
    unsigned short* indices = pStream->indices;
    unsigned char* dst = pStream->dest;
    if (!src) {
        for (unsigned short i = 0; i < pStream->vertices; ++i) {
            _fnv_zlib_memset(dst, 0, pStream->elementSize);
            dst += pStream->destStride;
            a += pStream->elementSize;
        }
        return a;
    }
    unsigned short srcComponents = pStream->type - 24;
    unsigned short components = pStream->lastComponent + 1;
    unsigned short b = srcComponents > components ? components : srcComponents;
    if (indices) {
        unsigned short remapIndex = 0;
        for (unsigned short i = 0; i < pStream->vertices; ++i) {
            unsigned char* in = src + indices[remapIndex++] * pStream->sourceStride;
            float* out = (float*)dst;
            unsigned short j = 0;
            for (; j < b; ++j) *out++ = *in++ / 255.0;
            for (; j < components; ++j) *out++ = 0.0f;
            a += pStream->elementSize;
            dst += pStream->destStride;
        }
    } else {
        for (unsigned short i = 0; i < pStream->vertices; ++i) {
            unsigned char* in = src;
            float* out = (float*)dst;
            unsigned short j = 0;
            for (; j < b; ++j) *out++ = *in++ / 255.0;
            for (; j < components; ++j) *out++ = 0.0f;
            a += pStream->elementSize;
            src += pStream->sourceStride;
            dst += pStream->destStride;
        }
    }
    return a;
}

extern "C" const char DAT_010ee8a0[];

struct FUN_00e7a640 {
    unsigned int m_00;
    const char* m_04;
    unsigned int* m_08;
    unsigned short m_0c;
    unsigned short m_0e;
    unsigned short m_10;
    unsigned short m_12;
    FUN_00e7a640();
};

// @fnv 0x00e7a640
FUN_00e7a640::FUN_00e7a640()
{
    m_0c = 0;
    m_12 = 1;
    m_0e = 0;
    m_10 = 0;
    m_08 = 0;
    m_04 = DAT_010ee8a0;
    m_00 = 0x11;
    unsigned short i = 0;
    unsigned short* pn = &m_0e;
    if (0 < *pn) {
        do {
            m_08[i] = 0;
            ++i;
        } while (i < *pn);
    }
    m_0e = 0;
    m_10 = 0;
}

extern "C" void __cdecl _NiFreeAlias(void*);
extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);

template <class T, class TAlloc> inline T& NiTArray<T, TAlloc>::GetAt(unsigned int i) { return m_pBase[i]; }
template <class T, class TAlloc> __forceinline NiTArray<T, TAlloc>::~NiTArray()
{ _NiFreeAlias(m_pBase); }
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::GetSize() const
{ return m_usSize; }
template <class T, class TAlloc> inline const T& NiTArray<T, TAlloc>::GetAt(unsigned int uiIndex) const
{ return m_pBase[uiIndex]; }
template <class T, class TAlloc> __forceinline void NiTArray<T, TAlloc>::RemoveAll()
{
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }

struct E7A6A0Entry;

class E7A6A0Bucket {
public:
    __forceinline ~E7A6A0Bucket() { m_kEntries.RemoveAll(); }

    static void operator delete(void* pvMem, unsigned int uiSize) { operator_delete_sized(pvMem, uiSize); }

    int m_iKey;
    NiTArray<E7A6A0Entry*, NiTMallocInterface<E7A6A0Entry*> > m_kEntries;
};

extern void* DAT_0126f550;

inline NiTArray<E7A6A0Bucket*, NiTMallocInterface<E7A6A0Bucket*> >* E7A6A0GetBuckets()
{
    return static_cast<NiTArray<E7A6A0Bucket*, NiTMallocInterface<E7A6A0Bucket*> >*>(DAT_0126f550);
}

// Deletes every bucket in the global bucket array, clears the array, then deletes the array itself.
// @fnv 0x00e7a6a0
void __cdecl DestroyBucketTable()
{
    for (unsigned int i = 0; i < E7A6A0GetBuckets()->GetSize(); i++) {
        E7A6A0Bucket* pkBucket = E7A6A0GetBuckets()->GetAt(i);
        if (pkBucket)
            delete pkBucket;
    }
    E7A6A0GetBuckets()->RemoveAll();
    delete E7A6A0GetBuckets();
}

class NiBaseObject {
public:
    virtual void unkBaseSlot0();
    unsigned int unk04;
    unsigned int unk08;
    char unk0c[0x08];
    unsigned int unk14;
    char unk18[0x68];
    char unk80[0x80];
    char unk100[0x80];
    char unk180[0x80];
    unsigned int unk200;
    unsigned int unk204;
    unsigned char unk208;
    unsigned char unk209;

    NiBaseObject() throw();
};

struct FUN_00a62af0_cls : NiBaseObject {
    virtual void unkVtableSlot0();

    FUN_00a62af0_cls() throw();
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);
extern FUN_00a62af0_cls* DAT_011f4748;

// @fnv 0x00a62af0
FUN_00a62af0_cls::FUN_00a62af0_cls() throw()
{
    unsigned int zero = 0;
    *(volatile unsigned int*)&unk08 = zero;
    *(volatile unsigned int*)&unk14 = zero;
    InitializeCriticalSection(&unk80);
    InitializeCriticalSection(&unk100);
    InitializeCriticalSection(&unk180);
    unk200 = zero;
    unk204 = zero;
    unk208 = (unsigned char)zero;
    unk209 = (unsigned char)zero;
    DAT_011f4748 = this;
}

struct VertexElement_e69790 { unsigned short Stream, Offset; unsigned char Type, Method, Usage, UsageIndex; };
struct Declaration_e69790;
struct Device_e69790 {
    virtual void __stdcall v0();
    virtual void __stdcall v1();
    virtual void __stdcall v2();
    virtual void __stdcall v3();
    virtual void __stdcall v4();
    virtual void __stdcall v5();
    virtual void __stdcall v6();
    virtual void __stdcall v7();
    virtual void __stdcall v8();
    virtual void __stdcall v9();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43();
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47();
    virtual void __stdcall v48();
    virtual void __stdcall v49();
    virtual void __stdcall v50();
    virtual void __stdcall v51();
    virtual void __stdcall v52();
    virtual void __stdcall v53();
    virtual void __stdcall v54();
    virtual void __stdcall v55();
    virtual void __stdcall v56();
    virtual void __stdcall v57();
    virtual void __stdcall v58();
    virtual void __stdcall v59();
    virtual void __stdcall v60();
    virtual void __stdcall v61();
    virtual void __stdcall v62();
    virtual void __stdcall v63();
    virtual void __stdcall v64();
    virtual void __stdcall v65();
    virtual void __stdcall v66();
    virtual void __stdcall v67();
    virtual void __stdcall v68();
    virtual void __stdcall v69();
    virtual void __stdcall v70();
    virtual void __stdcall v71();
    virtual void __stdcall v72();
    virtual void __stdcall v73();
    virtual void __stdcall v74();
    virtual void __stdcall v75();
    virtual void __stdcall v76();
    virtual void __stdcall v77();
    virtual void __stdcall v78();
    virtual void __stdcall v79();
    virtual void __stdcall v80();
    virtual void __stdcall v81();
    virtual void __stdcall v82();
    virtual void __stdcall v83();
    virtual void __stdcall v84();
    virtual void __stdcall v85();
    virtual long __stdcall CreateVertexDeclaration(const VertexElement_e69790*, Declaration_e69790**);
};
struct FUN_00e69790_shell {
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
    Declaration_e69790* declaration;
    Device_e69790* device;
    Declaration_e69790* NiDX9Renderer_GetDecl_Particles();
};
// Creates the vertex declaration from a fixed element array via device->CreateVertexDeclaration if not yet created, and returns it.
// @fnv 0x00e69790
// src: COMMUNITY 0x00e69790
Declaration_e69790* FUN_00e69790_shell::NiDX9Renderer_GetDecl_Particles() {
    if (!declaration) {
        VertexElement_e69790 elements[6] = {
            {0, 0, 2, 0, 0, 0},
            {0, 12, 2, 0, 3, 0},
            {0, 24, 4, 0, 10, 0},
            {0, 28, 1, 0, 5, 0},
            {0, 36, 0, 0, 5, 1},
            {255, 0, 17, 0, 0, 0}
        };
        if (device->CreateVertexDeclaration(elements, &declaration) < 0) {
            declaration = 0;
        }
    }
    return declaration;
}



struct VertexE69 {
    NiPoint3 m_kPos;
    NiPoint3 m_kPlaneNormal;
    unsigned int m_uiColor;
    float m_fU;
    float m_fV;
};

struct VertexWE69 {
    NiPoint3 m_kPos;
    NiPoint3 m_kPlaneNormal;
    unsigned int m_uiColor;
    float m_fU;
    float m_fV;
    float m_fVectorX;
};

// Writes position, normal, color and UVs into the next vertex; if fW is non-negative it uses the wider vertex layout and also stores fW.
// @fnv 0x00e69b60
float* __stdcall WriteVertex(float* pVertexBuffer, const NiPoint3& kPos, const NiPoint3& kNormal,
    unsigned int uiColor, float fTextureCoordinateU, float fV, float fW)
{
    if (fW >= 0.0f) {
        pVertexBuffer = (float*)((VertexWE69*)pVertexBuffer + 1);
        VertexWE69* pkVertex = (VertexWE69*)pVertexBuffer - 1;
        pkVertex->m_kPos.x = kPos.x;
        pkVertex->m_kPos.y = kPos.y;
        pkVertex->m_kPos.z = kPos.z;
        pkVertex->m_kPlaneNormal.x = kNormal.x;
        pkVertex->m_kPlaneNormal.y = kNormal.y;
        pkVertex->m_kPlaneNormal.z = kNormal.z;
        pkVertex->m_uiColor = uiColor;
        pkVertex->m_fU = fTextureCoordinateU;
        pkVertex->m_fV = fV;
        pkVertex->m_fVectorX = fW;
    } else {
        pVertexBuffer = (float*)((VertexE69*)pVertexBuffer + 1);
        VertexE69* pkVertex = (VertexE69*)pVertexBuffer - 1;
        pkVertex->m_kPos.x = kPos.x;
        pkVertex->m_kPos.y = kPos.y;
        pkVertex->m_kPos.z = kPos.z;
        pkVertex->m_kPlaneNormal.x = kNormal.x;
        pkVertex->m_kPlaneNormal.y = kNormal.y;
        pkVertex->m_kPlaneNormal.z = kNormal.z;
        pkVertex->m_uiColor = uiColor;
        pkVertex->m_fU = fTextureCoordinateU;
        pkVertex->m_fV = fV;
    }
    return pVertexBuffer;
}

// Maps a code to a small index via a switch, returning 0 for code 0 and any unmapped code.
// @fnv 0x00e69d00
unsigned int __cdecl MapCodeToIndex(unsigned int code)
{
    switch (code) {
    case 20: return 1;
    case 21: return 2;
    case 22: return 3;
    case 23: return 4;
    case 24: return 5;
    case 25: return 6;
    case 26: return 7;
    case 27: return 8;
    case 28: return 9;
    case 29: return 10;
    case 30: return 11;
    case 111: return 12;
    case 112: return 13;
    case 36: return 14;
    case 113: return 15;
    case 114: return 16;
    case 115: return 17;
    case 116: return 18;
    case 0: return 0;
    default: return 0;
    }
}

struct PackingPacket;
struct PackingOwner {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void ReleaseStream(PackingPacket*, unsigned int);
};
struct PackingPacket {
    unsigned int unk00, flags;
    PackingOwner* owner;
    unsigned int unk0c, unk10;
    bool dynamic;
    unsigned int vertexCount, activeVertexCount, streamCount, unk24;
    void** streams;
    unsigned int indexCount;
    void* indexData;
    void* indexBuffer;
    unsigned int cache, unk3c, primitiveCount, activePrimitiveCount, stripCount;
    void* vertexData;
    void* stripLengths;
    bool FUN_00e8eeb0();
    void NiGeometryBufferData_SetStreamCount(unsigned int);
    void FUN_00e8eee0();
};
struct PackingData {
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    void* stripLengths;
    void* vertexData;
    unsigned short vertexCount, primitiveCount, unk20, stripCount;
};
struct PackingGeometry {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual unsigned int Pack(NiGeometryData*, void*, PackingData*, unsigned short,
        void*, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int streamCount;
};
struct PackingVertexManager {
    unsigned int NiDX9VertexBufferManager_PackSkinnedVB(NiGeometryData*, void*, PackingData*, unsigned short, void*, unsigned int);
};
struct PackingIndexManager {
    void* FUN_00e8f200(void*, unsigned int, unsigned int, void*, void**, unsigned int, unsigned int);
};
extern bool DAT_0126f0d0;
struct PackingRenderer : ShaderStreamPacketBuilder {
    PackingIndexManager* indexManager;
    bool UpdatePackingPacket(PackingPacket*, NiGeometryData*, void*, PackingData*, PackingGeometry*, bool);
};
// Rebuilds the packet's flags, counts and streams from the model and data, repacking vertex streams and index buffers when dirty bits require it.
// @fnv 0x00e6d780
bool PackingRenderer::UpdatePackingPacket(PackingPacket* packet, NiGeometryData* model,
    void* geometryData, PackingData* data, PackingGeometry* geometry, bool force)
{
    if (!packet || !model)
        return false;
    bool cached = packet->FUN_00e8eeb0();
    if (!force && cached && (model->m_usDirtyFlags & 0x7000) == 0x4000)
        return true;
    bool has28 = model->m_pkColor != 0;
    bool has24 = model->m_pkNormal != 0;
    bool extra = has24 && (model->m_usDataFlags & 0xf000) != 0;
    unsigned int mode = model->m_usDataFlags & 1;
    if (mode > (unsigned int)DAT_011bf558)
        mode = DAT_011bf558;
    unsigned int flags = 0;
    if (has28) flags = 0x400000;
    if (has24) flags |= 0x800000;
    if (extra) flags |= 0x200000;
    packet->flags = flags | (mode << 24);
    unsigned short vertices = data->vertexCount;
    void* lengths = data->stripLengths;
    unsigned short primitives = data->primitiveCount;
    void* vertexData = data->vertexData;
    unsigned short strips = data->stripCount;
    unsigned int indices;
    if (!strips) {
        indices = primitives * 3;
        strips = 1;
    } else {
        indices = primitives + strips * 2;
    }
    unsigned int streamCount;
    if (geometry) streamCount = geometry->streamCount;
    else streamCount = 1;
    unsigned short dirty = model->m_usDirtyFlags & 0xfff;
    if (force) dirty = 0xfff;
    if (cached) {
        if (streamCount != packet->streamCount) {
            packet->NiGeometryBufferData_SetStreamCount(streamCount);
            dirty = 0xfff;
        }
    } else {
        PackingOwner* owner = packet->owner;
        for (unsigned int i = 0; i < streamCount; ++i)
            owner->ReleaseStream(packet, i);
        packet->NiGeometryBufferData_SetStreamCount(streamCount);
        packet->cache = 0;
        dirty = 0xfff;
    }
    packet->vertexCount = vertices;
    packet->activeVertexCount = vertices;
    packet->stripLengths = lengths;
    packet->vertexData = vertexData;
    packet->primitiveCount = primitives;
    packet->activePrimitiveCount = primitives;
    packet->stripCount = strips;
    if (dirty & ~0x10) {
        for (unsigned int i = 0; i < streamCount; ++i) {
            void* stream = i < packet->streamCount ? packet->streams[i] : 0;
            unsigned int packed = 0;
            if (geometry) packed = geometry->Pack(model, geometryData, data, dirty, stream, i, 0, 0, 0);
            if (!packed) {
                if (streamCount != 1 || !((PackingVertexManager*)m_pShaderStreamInfo)->NiDX9VertexBufferManager_PackSkinnedVB(
                    model, geometryData, data, dirty, stream, 0))
                    return false;
            }
        }
    }
    if (dirty & 0x30) {
        void* indexData = packet->indexData;
        void* oldBuffer = packet->indexBuffer;
        void* buffer = indexManager->FUN_00e8f200(lengths, indices, indices,
            oldBuffer, &indexData, !DAT_0126f0d0, packet->dynamic ? 0x10 : 0);
        if (!buffer) return false;
        if (oldBuffer != buffer) {
            packet->FUN_00e8eee0();
            packet->indexBuffer = buffer;
            packet->indexCount = indices;
            packet->indexData = indexData;
        }
    }
    return true;
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f5d8;

struct Src_e6e
{
    int unk;
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
};

struct Obj_e6e
{
    Src_e6e* ContainsNode(GlobalObjectO2_00a7b610* pkList);
};

struct Device_e6e
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual Obj_e6e* v050(int iIndex);
};

struct Mgr_e6e
{
    unsigned int NiDX9SystemDesc_GetNearestDepthStencilFormat(int iA, int iFormat, int iB, int iC);
};

struct Map_e6e
{
    bool FUN_00a53c30(unsigned int uiKey, void*& rp);
    void InsertOrUpdate(unsigned int uiKey, void* pVal);
};

int __cdecl FUN_00e7bd20(int iFormat);
void* __cdecl CreatePixelFormat(unsigned int uiKey);

struct FUN_00e6ee00_cls
{
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk00c;
    int uTmpnk;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    Mgr_e6e* m_5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    Device_e6e* m_884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka;
    int unkaCur;
    int unkaValue;
    int unka0c;
    int uNewnka;
    int uTmpnka;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa;
    int unkaaCur;
    int unkaaValue;
    int unkaac;
    int unkab;
    int unkabCur;
    int unkabValue;
    int unkabc;
    int unkac;
    int unkacCur;
    int unkacValue;
    int unkacc;
    int unkad;
    int unkadCur;
    int unkadValue;
    int unkadc;
    int unkae;
    int unkaeCur;
    int unkaeValue;
    int unkaec;
    int unkaf;
    int unkafCur;
    int unkafValue;
    int unkafc;
    int unkb;
    int unkbCur;
    int unkbValue;
    int unkb0c;
    int uNewnkb;
    NiTMap<_D3DFORMAT, NiPixelFormat*> m_kFormatEntries;
    void* GetOrCreateFormatEntry(int iFormat, int iB, int iC);
};

// @fnv 0x00e6ee00
void* FUN_00e6ee00_cls::GetOrCreateFormatEntry(int iFormat, int iB, int iC)
{
    Obj_e6e* pObj = m_884->v050(0);
    Src_e6e* pSrc;
    if (!pObj)
        pSrc = 0;
    else
        pSrc = pObj->ContainsNode(&g_0126f5d8);
    int iFmt = FUN_00e7bd20(iFormat);
    unsigned int uiKey = m_5dc->NiDX9SystemDesc_GetNearestDepthStencilFormat(pSrc->unk28, iFmt, iB, iC);
    {
        NiPixelFormat* pVal = 0;
        if (m_kFormatEntries.GetAt(static_cast<_D3DFORMAT>(uiKey), pVal) && pVal)
            return pVal;
    }
    void* pNew = CreatePixelFormat(uiKey);
    m_kFormatEntries.SetAt(static_cast<_D3DFORMAT>(uiKey), static_cast<NiPixelFormat*>(pNew));
    return pNew;
}

extern const NiRTTI g_0126f5ac;
extern const unsigned char DAT_0126efd8[];

struct SurfDesc { unsigned int Format; unsigned int Type; unsigned int Usage; unsigned int Pool;
    unsigned int MultiSampleType; unsigned int MultiSampleQuality; unsigned int Width; unsigned int Height; };

struct DX9Surface {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual long __stdcall GetDesc(SurfDesc* pDesc);
};
struct BufSize { int unk00; int unk04; unsigned int m_uiImageWidth; unsigned int m_uiImageHeight; };
struct BufFormat { unsigned char unk00; unsigned char m_ucBitsPerPixel; };
struct BufData {
    int unk00; int unk04;
    BufSize* m_pkSize;
    BufFormat* m_pkFormat;
    int unk10;
    DX9Surface* m_pkSurface;
};
struct DepthBuffer {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual const NiRTTI* GetRTTI() const;
    int unk04; int unk08; int unk0c; int unk10;
    void* m_pRendererData;
};
struct TargetGroup {
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t40();
    virtual unsigned int GetBufferCount() const;
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void u6();
    virtual void u7();
    virtual BufData* GetBuffer(unsigned int ui) const;
    virtual DepthBuffer* GetDepthSurface() const;
};

static inline unsigned char GetBitsPerPixel(unsigned int eFormat)
{
    if (eFormat >= 0x76)
        return 0;
    return DAT_0126efd8[eFormat];
}

static inline bool IsKindOfType(const NiRTTI* pkTarget, const DepthBuffer* pkObj)
{
    const NiRTTI* pkRTTI = pkObj->GetRTTI();
    while (pkRTTI)
    {
        if (pkRTTI == pkTarget)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    }
    return false;
}

class DX9RendererStandIn {
public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual unsigned int GetMaxBuffersPerRenderTargetGroup() const;
    virtual bool GetIndependentBufferBitDepths() const;
    bool ValidateRenderTargetGroup(TargetGroup* pkTarget);
};

// @fnv 0x00e6f100
bool DX9RendererStandIn::ValidateRenderTargetGroup(TargetGroup* pkTarget)
{
    unsigned int uiBufferCount = pkTarget->GetBufferCount();
    if (uiBufferCount > GetMaxBuffersPerRenderTargetGroup())
        return false;

    for (unsigned int ui = 0; ui < uiBufferCount; ui++)
    {
        BufData* pkBuffer = pkTarget->GetBuffer(ui);
        if (!pkBuffer || !pkBuffer->m_pkSurface)
            return false;

        for (unsigned int uiPrevIndex = 0; uiPrevIndex < ui; uiPrevIndex++)
        {
            SurfDesc kDesc;
            DX9Surface* pkSurf = pkTarget->GetBuffer(uiPrevIndex)->m_pkSurface;
            if (pkSurf->GetDesc(&kDesc) < 0)
                return false;
            if (kDesc.MultiSampleType != 0)
                return false;
            if (pkBuffer->m_pkSize->m_uiImageWidth != kDesc.Width ||
                pkBuffer->m_pkSize->m_uiImageHeight != kDesc.Height)
                return false;
            if (!GetIndependentBufferBitDepths() &&
                GetBitsPerPixel(kDesc.Format) != pkBuffer->m_pkFormat->m_ucBitsPerPixel)
                return false;
        }
    }

    DepthBuffer* pkDepth = pkTarget->GetDepthSurface();
    if (pkDepth)
    {
        DepthBuffer* pkDS = IsKindOfType(&g_0126f5ac, pkDepth) ? pkDepth : 0;
        if (pkDS && !pkDS->m_pRendererData)
            return false;
    }
    return true;
}

struct E6F260SurfaceDesc {
    int Format;
    int Type;
    unsigned int Usage;
    int Pool;
    int MultiSampleType;
    unsigned int MultiSampleQuality;
    unsigned int Width;
    unsigned int Height;
};

class E6F260Surface {
public:
    virtual void __stdcall Fn00();
    virtual void __stdcall Fn04();
    virtual void __stdcall Fn08();
    virtual void __stdcall Fn0C();
    virtual void __stdcall Fn10();
    virtual void __stdcall Fn14();
    virtual void __stdcall Fn18();
    virtual void __stdcall Fn1C();
    virtual void __stdcall Fn20();
    virtual void __stdcall Fn24();
    virtual void __stdcall Fn28();
    virtual void __stdcall Fn2C();
    virtual long __stdcall GetDesc(E6F260SurfaceDesc* pDesc);
};

class E6F260Direct3D {
public:
    virtual void __stdcall Fn00();
    virtual void __stdcall Fn04();
    virtual void __stdcall Fn08();
    virtual void __stdcall Fn0C();
    virtual void __stdcall Fn10();
    virtual void __stdcall Fn14();
    virtual void __stdcall Fn18();
    virtual void __stdcall Fn1C();
    virtual void __stdcall Fn20();
    virtual void __stdcall Fn24();
    virtual void __stdcall Fn28();
    virtual void __stdcall Fn2C();
    virtual long __stdcall CheckDepthStencilMatch(unsigned int Adapter, int DeviceType, int AdapterFormat,
        int RenderTargetFormat, int DepthStencilFormat);
};

extern E6F260Direct3D* g_pkE6F260Direct3D;

struct E6F260SurfaceData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    E6F260Surface* m_pkSurface;
};

struct E6F260Buffer {
    int unk00;
    int unk04;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    E6F260SurfaceData* m_pUserData;
};

class E6F260Renderer {
public:
    bool IsDepthStencilCompatible(E6F260Buffer* pkRenderTarget, E6F260Buffer* pkDepthStencil);
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    unsigned int m_uiAdapter;
    int m_eDeviceType;
    int unk5CC;
    int m_eAdapterFormat;
};

// @fnv 0x00e6f260
bool E6F260Renderer::IsDepthStencilCompatible(E6F260Buffer* pkRenderTarget, E6F260Buffer* pkDepthStencil)
{
    if (pkRenderTarget->m_uiImageWidth > pkDepthStencil->m_uiImageWidth || pkRenderTarget->m_uiImageHeight > pkDepthStencil->m_uiImageHeight)
        return false;

    E6F260SurfaceData* pkRenderTargetData = pkRenderTarget->m_pUserData;
    E6F260SurfaceData* pkDepthStencilData = pkDepthStencil->m_pUserData;

    E6F260SurfaceDesc kRenderTargetDesc;
    E6F260SurfaceDesc kDepthStencilDesc;
    pkRenderTargetData->m_pkSurface->GetDesc(&kRenderTargetDesc);
    pkDepthStencilData->m_pkSurface->GetDesc(&kDepthStencilDesc);

    if (kRenderTargetDesc.MultiSampleQuality != kDepthStencilDesc.MultiSampleQuality ||
        kRenderTargetDesc.MultiSampleType != kDepthStencilDesc.MultiSampleType)
        return false;

    int eDeviceType = m_eDeviceType;
    unsigned int uiAdapter = m_uiAdapter;
    int eAdapterFormat = m_eAdapterFormat;
    if (g_pkE6F260Direct3D->CheckDepthStencilMatch(uiAdapter, eDeviceType, eAdapterFormat,
        kRenderTargetDesc.Format, kDepthStencilDesc.Format) < 0)
        return false;
    return true;
}

class NiGeometryGroup;
class NiSkinInstance;
namespace fnv_00e73f60 {

extern NiRTTI g_011f5b70;
extern NiRTTI g_011f4a40;
extern NiRTTI g_011f4a20;

bool __cdecl NiObject_IsKindOf(const NiRTTI* pkRTTI, NiAVObject* pkObject);
void __cdecl Object_DoNothing(const char* format, const char* message);
struct PG_Preparer { bool Prepare(NiGeometryGroup* c, NiGeometryData* d, NiSkinInstance* e, bool f, unsigned int g, unsigned int h); };

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct PG_Data {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41();
    virtual unsigned short GetActiveVertexQuantity();
    unsigned int unk04; unsigned int unk08; unsigned int unk0c;
    unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2c;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3c;
    unsigned short m_usVertices;
    unsigned short unk42;
    unsigned short m_us44;
    unsigned short unk46;
    void* m_p48;
    void* FUN_00a7b850_s();
    void* FUN_00a75f10_s();
};

struct PG_Prop {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46();
    virtual unsigned int GetDefaultTechnique();
};

struct PG_Geom {
    virtual void v0(); virtual void v1();
    virtual const NiRTTI* GetRTTI() const;
    unsigned int unk04;
    const char* m_pcName;
};

inline bool PG_IsKindOf(const NiRTTI& kRTTI, PG_Geom* p)
{
    if (!p)
        return false;
    for (const NiRTTI* r = p->GetRTTI(); r; r = r->m_pBaseRTTI)
        if (r == &kRTTI)
            return true;
    return false;
}

struct PG_GeomFull : PG_Geom {
    unsigned int unk0c;
    unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2c;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3c;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4c;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5c;
    unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6c;
    unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7c;
    unsigned int unk80; unsigned int unk84; unsigned int unk88; unsigned int unk8c;
    unsigned int unk90; unsigned int unk94; unsigned int unk98; unsigned int unk9c;
    unsigned int unka0; unsigned int unka4; unsigned int unka8; unsigned int unkac;
    unsigned int unkb0; unsigned int unkb4;
    PG_Data* m_spGeometryData;
    NiSkinInstance* m_spSkinningInstance;
    PG_Prop* m_pShaderHandle;
};

struct PG_CS { unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; };

struct PG_Renderer {
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c;
    unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c;
    unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c;
    unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c;
    PG_CS m_kCS80;
    unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4;
    unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4;
    unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4;
    unsigned int unk0f8; unsigned int unk0fc;
    PG_CS m_kCS100;
    unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134;
    unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154;
    unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c; unsigned int unk170; unsigned int unk174;
    unsigned int unk178; unsigned int unk17c; unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18c; unsigned int unk190; unsigned int unk194;
    unsigned int unk198; unsigned int unk19c; unsigned int unk1a0; unsigned int unk1a4; unsigned int unk1a8; unsigned int unk1ac; unsigned int unk1b0; unsigned int unk1b4;
    unsigned int unk1b8; unsigned int unk1bc; unsigned int unk1c0; unsigned int unk1c4; unsigned int unk1c8; unsigned int unk1cc; unsigned int unk1d0; unsigned int unk1d4;
    unsigned int unk1d8; unsigned int unk1dc; unsigned int unk1e0; unsigned int unk1e4; unsigned int unk1e8; unsigned int unk1ec; unsigned int unk1f0; unsigned int unk1f4;
    unsigned int unk1f8; unsigned int unk1fc; unsigned int unk200; unsigned int unk204; unsigned int unk208; unsigned int unk20c; unsigned int unk210; unsigned int unk214;
    unsigned int unk218; unsigned int unk21c; unsigned int unk220; unsigned int unk224; unsigned int unk228; unsigned int unk22c; unsigned int unk230; unsigned int unk234;
    unsigned int unk238; unsigned int unk23c; unsigned int unk240; unsigned int unk244; unsigned int unk248; unsigned int unk24c; unsigned int unk250; unsigned int unk254;
    unsigned int unk258; unsigned int unk25c; unsigned int unk260; unsigned int unk264; unsigned int unk268; unsigned int unk26c; unsigned int unk270; unsigned int unk274;
    unsigned int unk278; unsigned int unk27c; unsigned int unk280; unsigned int unk284; unsigned int unk288; unsigned int unk28c; unsigned int unk290; unsigned int unk294;
    unsigned int unk298; unsigned int unk29c; unsigned int unk2a0; unsigned int unk2a4; unsigned int unk2a8; unsigned int unk2ac; unsigned int unk2b0; unsigned int unk2b4;
    unsigned int unk2b8; unsigned int unk2bc; unsigned int unk2c0; unsigned int unk2c4; unsigned int unk2c8; unsigned int unk2cc; unsigned int unk2d0; unsigned int unk2d4;
    unsigned int unk2d8; unsigned int unk2dc; unsigned int unk2e0; unsigned int unk2e4; unsigned int unk2e8; unsigned int unk2ec; unsigned int unk2f0; unsigned int unk2f4;
    unsigned int unk2f8; unsigned int unk2fc; unsigned int unk300; unsigned int unk304; unsigned int unk308; unsigned int unk30c; unsigned int unk310; unsigned int unk314;
    unsigned int unk318; unsigned int unk31c; unsigned int unk320; unsigned int unk324; unsigned int unk328; unsigned int unk32c; unsigned int unk330; unsigned int unk334;
    unsigned int unk338; unsigned int unk33c; unsigned int unk340; unsigned int unk344; unsigned int unk348; unsigned int unk34c; unsigned int unk350; unsigned int unk354;
    unsigned int unk358; unsigned int unk35c; unsigned int unk360; unsigned int unk364; unsigned int unk368; unsigned int unk36c; unsigned int unk370; unsigned int unk374;
    unsigned int unk378; unsigned int unk37c; unsigned int unk380; unsigned int unk384; unsigned int unk388; unsigned int unk38c; unsigned int unk390; unsigned int unk394;
    unsigned int unk398; unsigned int unk39c; unsigned int unk3a0; unsigned int unk3a4; unsigned int unk3a8; unsigned int unk3ac; unsigned int unk3b0; unsigned int unk3b4;
    unsigned int unk3b8; unsigned int unk3bc; unsigned int unk3c0; unsigned int unk3c4; unsigned int unk3c8; unsigned int unk3cc; unsigned int unk3d0; unsigned int unk3d4;
    unsigned int unk3d8; unsigned int unk3dc; unsigned int unk3e0; unsigned int unk3e4; unsigned int unk3e8; unsigned int unk3ec; unsigned int unk3f0; unsigned int unk3f4;
    unsigned int unk3f8; unsigned int unk3fc; unsigned int unk400; unsigned int unk404; unsigned int unk408; unsigned int unk40c; unsigned int unk410; unsigned int unk414;
    unsigned int unk418; unsigned int unk41c; unsigned int unk420; unsigned int unk424; unsigned int unk428; unsigned int unk42c; unsigned int unk430; unsigned int unk434;
    unsigned int unk438; unsigned int unk43c; unsigned int unk440; unsigned int unk444; unsigned int unk448; unsigned int unk44c; unsigned int unk450; unsigned int unk454;
    unsigned int unk458; unsigned int unk45c; unsigned int unk460; unsigned int unk464; unsigned int unk468; unsigned int unk46c; unsigned int unk470; unsigned int unk474;
    unsigned int unk478; unsigned int unk47c; unsigned int unk480; unsigned int unk484; unsigned int unk488; unsigned int unk48c; unsigned int unk490; unsigned int unk494;
    unsigned int unk498; unsigned int unk49c; unsigned int unk4a0; unsigned int unk4a4; unsigned int unk4a8; unsigned int unk4ac; unsigned int unk4b0; unsigned int unk4b4;
    unsigned int unk4b8; unsigned int unk4bc; unsigned int unk4c0; unsigned int unk4c4; unsigned int unk4c8; unsigned int unk4cc; unsigned int unk4d0; unsigned int unk4d4;
    unsigned int unk4d8; unsigned int unk4dc; unsigned int unk4e0; unsigned int unk4e4; unsigned int unk4e8; unsigned int unk4ec; unsigned int unk4f0; unsigned int unk4f4;
    unsigned int unk4f8; unsigned int unk4fc; unsigned int unk500; unsigned int unk504; unsigned int unk508; unsigned int unk50c; unsigned int unk510; unsigned int unk514;
    unsigned int unk518; unsigned int unk51c; unsigned int unk520; unsigned int unk524; unsigned int unk528; unsigned int unk52c; unsigned int unk530; unsigned int unk534;
    unsigned int unk538; unsigned int unk53c; unsigned int unk540; unsigned int unk544; unsigned int unk548; unsigned int unk54c; unsigned int unk550; unsigned int unk554;
    unsigned int unk558; unsigned int unk55c; unsigned int unk560; unsigned int unk564; unsigned int unk568; unsigned int unk56c; unsigned int unk570; unsigned int unk574;
    unsigned int unk578; unsigned int unk57c; unsigned int unk580; unsigned int unk584; unsigned int unk588; unsigned int unk58c; unsigned int unk590; unsigned int unk594;
    unsigned int unk598; unsigned int unk59c; unsigned int unk5a0; unsigned int unk5a4; unsigned int unk5a8; unsigned int unk5ac; unsigned int unk5b0; unsigned int unk5b4;
    unsigned int unk5b8; unsigned int unk5bc; unsigned int unk5c0; unsigned int unk5c4; unsigned int unk5c8; unsigned int unk5cc; unsigned int unk5d0; unsigned int unk5d4;
    unsigned int unk5d8; unsigned int unk5dc; unsigned int unk5e0; unsigned int unk5e4; unsigned int unk5e8; unsigned int unk5ec; unsigned int unk5f0; unsigned int unk5f4;
    unsigned int unk5f8; unsigned int unk5fc; unsigned int unk600; unsigned int unk604; unsigned int unk608; unsigned int unk60c; unsigned int unk610; unsigned int unk614;
    unsigned int unk618; unsigned int unk61c; unsigned int unk620; unsigned int unk624; unsigned int unk628; unsigned int unk62c; unsigned int unk630; unsigned int unk634;
    unsigned int unk638; unsigned int unk63c; unsigned int unk640; unsigned int unk644; unsigned int unk648; unsigned int unk64c; unsigned int unk650; unsigned int unk654;
    unsigned int unk658; unsigned int unk65c; unsigned int unk660; unsigned int unk664; unsigned int unk668; unsigned int unk66c; unsigned int unk670; unsigned int unk674;
    unsigned int unk678; unsigned int unk67c; unsigned int unk680; unsigned int unk684; unsigned int unk688; unsigned int unk68c; unsigned int unk690; unsigned int unk694;
    unsigned int unk698; unsigned int unk69c; unsigned int unk6a0; unsigned int unk6a4; unsigned int unk6a8; unsigned int unk6ac; unsigned int unk6b0; unsigned int unk6b4;
    unsigned int unk6b8; unsigned int unk6bc; unsigned int unk6c0; unsigned int unk6c4; unsigned int unk6c8; unsigned int unk6cc; unsigned int unk6d0; unsigned int unk6d4;
    unsigned int unk6d8; unsigned int unk6dc; unsigned int unk6e0; unsigned int unk6e4; unsigned int unk6e8; unsigned int unk6ec; unsigned int unk6f0; unsigned int unk6f4;
    unsigned int unk6f8; unsigned int unk6fc; unsigned int unk700; unsigned int unk704; unsigned int unk708; unsigned int unk70c; unsigned int unk710; unsigned int unk714;
    unsigned int unk718; unsigned int unk71c; unsigned int unk720; unsigned int unk724; unsigned int unk728; unsigned int unk72c; unsigned int unk730; unsigned int unk734;
    unsigned int unk738; unsigned int unk73c; unsigned int unk740; unsigned int unk744; unsigned int unk748; unsigned int unk74c; unsigned int unk750; unsigned int unk754;
    unsigned int unk758; unsigned int unk75c; unsigned int unk760; unsigned int unk764; unsigned int unk768; unsigned int unk76c; unsigned int unk770; unsigned int unk774;
    unsigned int unk778; unsigned int unk77c; unsigned int unk780; unsigned int unk784; unsigned int unk788; unsigned int unk78c; unsigned int unk790; unsigned int unk794;
    unsigned int unk798; unsigned int unk79c; unsigned int unk7a0; unsigned int unk7a4; unsigned int unk7a8; unsigned int unk7ac; unsigned int unk7b0; unsigned int unk7b4;
    unsigned int unk7b8; unsigned int unk7bc; unsigned int unk7c0; unsigned int unk7c4; unsigned int unk7c8; unsigned int unk7cc; unsigned int unk7d0; unsigned int unk7d4;
    unsigned int unk7d8; unsigned int unk7dc; unsigned int unk7e0; unsigned int unk7e4; unsigned int unk7e8; unsigned int unk7ec; unsigned int unk7f0; unsigned int unk7f4;
    unsigned int unk7f8; unsigned int unk7fc; unsigned int unk800; unsigned int unk804; unsigned int unk808; unsigned int unk80c; unsigned int unk810; unsigned int unk814;
    unsigned int unk818; unsigned int unk81c; unsigned int unk820; unsigned int unk824; unsigned int unk828; unsigned int unk82c; unsigned int unk830; unsigned int unk834;
    unsigned int unk838; unsigned int unk83c; unsigned int unk840; unsigned int unk844; unsigned int unk848; unsigned int unk84c; unsigned int unk850; unsigned int unk854;
    unsigned int unk858; unsigned int unk85c; unsigned int unk860; unsigned int unk864; unsigned int unk868; unsigned int unk86c; unsigned int unk870; unsigned int unk874;
    unsigned int unk878; unsigned int unk87c; unsigned int unk880; unsigned int unk884; unsigned int unk888; unsigned int unk88c; unsigned int unk890; unsigned int unk894;
    unsigned int unk898; unsigned int unk89c; unsigned int unk8a0; unsigned int unk8a4; unsigned int unk8a8;
    void* m_p8ac;
    NiGeometryGroup* m_p8b0;
    bool FUN_00e72c20_s(PG_GeomFull* p, int z);
    bool FUN_00e72aa0_s(PG_GeomFull* p, PG_Data* d, NiSkinInstance* s, unsigned int t, unsigned int a, unsigned int b);
    bool FUN_00e72980_s(PG_GeomFull* p, PG_Data* d, unsigned int n, unsigned int v, void* q, void* r, unsigned int c, unsigned int t);
    bool NiDX9Renderer_PrecacheGeometry(PG_GeomFull* p, unsigned int a2, unsigned int a3, unsigned int a4);
};

// @fnv 0x00e73f60
// src: COMMUNITY 0x00e73f60
bool PG_Renderer::NiDX9Renderer_PrecacheGeometry(PG_GeomFull* p, unsigned int a2, unsigned int a3, unsigned int auiTechnique)
{
    if (!PG_IsKindOf(g_011f5b70, p))
        return false;

    NiSkinInstance* pSkinInstance = p->m_spSkinningInstance;
    PG_Prop* pShader = p->m_pShaderHandle;
    PG_Data* pData = p->m_spGeometryData;
    if (!pShader) {
        Object_DoNothing("PrecacheGeometry> No shader found for object %s!\n", p->m_pcName);
        return false;
    }

    bool bPrecached = FUN_00e72c20_s(p, 0);
    EnterCriticalSection(&m_kCS80);
    EnterCriticalSection(&m_kCS100);
    unsigned int uiTech = auiTechnique;
    if (!uiTech)
        uiTech = pShader->GetDefaultTechnique();
    ((PG_Preparer*)m_p8ac)->Prepare(m_p8b0, (NiGeometryData*)pData, pSkinInstance, bPrecached, a2, a3);
    bool bResult = false;
    if (bPrecached) {
        bResult = FUN_00e72aa0_s(p, pData, pSkinInstance, uiTech, a2, a3);
    } else if (NiObject_IsKindOf(&g_011f4a40, (NiAVObject*)p)) {
        unsigned int usActive = pData->GetActiveVertexQuantity();
        unsigned int usVerts = pData->m_usVertices;
        void* m_pkDeltas = pData->FUN_00a7b850_s();
        bResult = FUN_00e72980_s(p, pData, usActive, usVerts, m_pkDeltas, 0, 1, uiTech);
    } else if (NiObject_IsKindOf(&g_011f4a20, (NiAVObject*)p)) {
        unsigned int usActive = pData->GetActiveVertexQuantity();
        unsigned int usVerts = pData->m_usVertices;
        void* m_pkDeltas = pData->FUN_00a75f10_s();
        void* pIdx = pData->m_p48;
        unsigned int uiIdx = pData->m_us44;
        bResult = FUN_00e72980_s(p, pData, usActive, usVerts, m_pkDeltas, pIdx, uiIdx, uiTech);
    }
    LeaveCriticalSection(&m_kCS100);
    LeaveCriticalSection(&m_kCS80);
    return bResult;
}
}  // namespace fnv_00e73f60

namespace fnv_00e74840 {

extern NiBound DAT_011f4288;

struct D3DDev {
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    virtual void __stdcall v07();
    virtual void __stdcall v08();
    virtual void __stdcall v09();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual void __stdcall v43();
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual void __stdcall v47();
    virtual void __stdcall v48();
    virtual void __stdcall v49();
    virtual void __stdcall v50();
    virtual void __stdcall v51();
    virtual void __stdcall v52();
    virtual void __stdcall v53();
    virtual void __stdcall v54();
    virtual void __stdcall v55();
    virtual void __stdcall v56();
    virtual void __stdcall v57();
    virtual void __stdcall v58();
    virtual void __stdcall v59();
    virtual void __stdcall v60();
    virtual void __stdcall v61();
    virtual void __stdcall v62();
    virtual void __stdcall v63();
    virtual void __stdcall v64();
    virtual void __stdcall v65();
    virtual void __stdcall v66();
    virtual void __stdcall v67();
    virtual void __stdcall v68();
    virtual void __stdcall v69();
    virtual void __stdcall v70();
    virtual void __stdcall v71();
    virtual void __stdcall v72();
    virtual void __stdcall v73();
    virtual void __stdcall v74();
    virtual void __stdcall v75();
    virtual void __stdcall v76();
    virtual void __stdcall v77();
    virtual void __stdcall v78();
    virtual void __stdcall v79();
    virtual void __stdcall v80();
    virtual long __stdcall DrawPrimitive(int type, unsigned int startVertex, unsigned int primCount);
    virtual long __stdcall DrawIndexedPrimitive(int type, int baseVertex, unsigned int minIndex, unsigned int numVertices, unsigned int startIndex, unsigned int primCount);
};

struct GeomBuffData {
    int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014;
    unsigned int m_uiVertexCount;
    int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30;
    void* m_pkIndexBuffer;
    int m_uiBufferSize;
    int m_eRequestType;
    unsigned int m_uiTriangles;
    int unk44;
    unsigned int m_uiMaximumIndex;
    unsigned short* m_pusIndexData;
};

struct VObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual unsigned short GetActiveVertexQuantity();
};

struct GeomData : VObj {
    int unk04; int unk08; unsigned short unk0C; unsigned short m_usDirtyFlags;
    int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30;
    GeomBuffData* m_pkGeometryRendererData;
};

struct SkinPartitionEntry {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    unsigned short m_usVertices; unsigned short m_usTriangles; unsigned short m_usBoneCount; unsigned short m_usStrips;
    unsigned short m_usWeightsPerVertex; unsigned short unk26;
    GeomBuffData* m_pkGeometryRendererData;
};

struct SkinPartition {
    int unk00; int unk04;
    unsigned int m_uiPartitionCount;
    SkinPartitionEntry* m_pPartitions;
};

struct SkinInstance {
    int unk00; int unk04; int unk08;
    SkinPartition* m_pkSkinMeshPartition;
};

struct Geom {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    NiBound* m_pkBound;
    int unk0024; int unk0028; int unk002C; int unk0030; int unk0034; int unk0038; int unk003C; int unk0040;
    int unk0044; int unk0048; int unk004C; int unk0050; int unk0054; int unk0058; int unk005C; int unk0060;
    int unk0064; int unk0068; int unk006C; int unk0070; int unk0074; int unk0078; int unk007C; int unk0080;
    int unk0084; int unk0088; int unk008C; int unk0090; int unk0094; int unk0098; int unk009C; int unk00A0;
    int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4;
    GeomData* m_spGeometryData;
    SkinInstance* m_spSkinningInstance;
    VObj* m_pGeometryShader;
};

struct Renderer {
    int unk0000; int unk0004; int unk0008; int unk000C; int unk0010; int unk0014; int unk0018; int unk001C;
    int unk0020; int unk0024; int unk0028; int unk002C; int unk0030; int unk0034; int unk0038; int unk003C;
    int unk0040; int unk0044; int unk0048; int unk004C; int unk0050; int unk0054; int unk0058; int unk005C;
    int unk0060; int unk0064; int unk0068; int unk006C; int unk0070; int unk0074; int unk0078; int unk007C;
    int unk0080; int unk0084; int unk0088; int unk008C; int unk0090; int unk0094; int unk0098; int unk009C;
    int unk00A0; int unk00A4; int unk00A8; int unk00AC; int unk00B0; int unk00B4; int unk00B8; int unk00BC;
    int unk00C0; int unk00C4; int unk00C8; int unk00CC; int unk00D0; int unk00D4; int unk00D8; int unk00DC;
    int unk00E0; int unk00E4; int unk00E8; int unk00EC; int unk00F0; int unk00F4; int unk00F8; int unk00FC;
    int unk0100; int unk0104; int unk0108; int unk010C; int unk0110; int unk0114; int unk0118; int unk011C;
    int unk0120; int unk0124; int unk0128; int unk012C; int unk0130; int unk0134; int unk0138; int unk013C;
    int unk0140; int unk0144; int unk0148; int unk014C; int unk0150; int unk0154; int unk0158; int unk015C;
    int unk0160; int unk0164; int unk0168; int unk016C; int unk0170; int unk0174; int unk0178; int unk017C;
    int unk0180; int unk0184; int unk0188; int unk018C; int unk0190; int unk0194; int unk0198; int unk019C;
    int unk01A0; int unk01A4; int unk01A8; int unk01AC; int unk01B0; int unk01B4; int unk01B8; int unk01BC;
    int unk01C0; int unk01C4; int unk01C8; int unk01CC; int unk01D0; int unk01D4; int unk01D8; int unk01DC;
    int unk01E0; int unk01E4; int unk01E8; int unk01EC; int unk01F0; int unk01F4; int unk01F8; int unk01FC;
    int unk0200; int unk0204; int unk0208; int unk020C; int unk0210; int unk0214; int unk0218; int unk021C;
    int unk0220; int unk0224; int unk0228; int unk022C; int unk0230; int unk0234; int unk0238; int unk023C;
    int unk0240; int unk0244; int unk0248; int unk024C; int unk0250; int unk0254; int unk0258; int unk025C;
    int unk0260; int unk0264; int unk0268; int unk026C; int unk0270; int unk0274; int unk0278; int unk027C;
    int unk0280; int unk0284;
    D3DDev* m_pD3DDevice;
    int unk028C; int unk0290; int unk0294; int unk0298; int unk029C; int unk02A0; int unk02A4; int unk02A8;
    int unk02AC; int unk02B0; int unk02B4; int unk02B8; int unk02BC; int unk02C0; int unk02C4; int unk02C8;
    int unk02CC; int unk02D0; int unk02D4; int unk02D8; int unk02DC; int unk02E0; int unk02E4; int unk02E8;
    int unk02EC; int unk02F0; int unk02F4; int unk02F8; int unk02FC; int unk0300; int unk0304; int unk0308;
    int unk030C; int unk0310; int unk0314; int unk0318; int unk031C; int unk0320; int unk0324; int unk0328;
    int unk032C; int unk0330; int unk0334; int unk0338; int unk033C; int unk0340; int unk0344; int unk0348;
    int unk034C; int unk0350; int unk0354; int unk0358; int unk035C; int unk0360; int unk0364; int unk0368;
    int unk036C; int unk0370; int unk0374; int unk0378; int unk037C; int unk0380; int unk0384; int unk0388;
    int unk038C; int unk0390; int unk0394; int unk0398; int unk039C; int unk03A0; int unk03A4; int unk03A8;
    int unk03AC; int unk03B0; int unk03B4; int unk03B8; int unk03BC; int unk03C0; int unk03C4; int unk03C8;
    int unk03CC; int unk03D0; int unk03D4; int unk03D8; int unk03DC; int unk03E0; int unk03E4; int unk03E8;
    int unk03EC; int unk03F0; int unk03F4; int unk03F8; int unk03FC; int unk0400; int unk0404; int unk0408;
    int unk040C; int unk0410; int unk0414; int unk0418; int unk041C; int unk0420; int unk0424; int unk0428;
    int unk042C; int unk0430; int unk0434; int unk0438; int unk043C; int unk0440; int unk0444; int unk0448;
    int unk044C; int unk0450; int unk0454; int unk0458; int unk045C; int unk0460; int unk0464; int unk0468;
    int unk046C; int unk0470; int unk0474; int unk0478; int unk047C; int unk0480; int unk0484; int unk0488;
    int unk048C; int unk0490; int unk0494; int unk0498; int unk049C; int unk04A0; int unk04A4; int unk04A8;
    int unk04AC; int unk04B0; int unk04B4; int unk04B8; int unk04BC; int unk04C0; int unk04C4; int unk04C8;
    int unk04CC; int unk04D0; int unk04D4; int unk04D8; int unk04DC; int unk04E0; int unk04E4; int unk04E8;
    int unk04EC; int unk04F0; int unk04F4; int unk04F8; int unk04FC; int unk0500; int unk0504; int unk0508;
    int unk050C; int unk0510; int unk0514; int unk0518; int unk051C; int unk0520; int unk0524; int unk0528;
    int unk052C; int unk0530; int unk0534; int unk0538; int unk053C; int unk0540; int unk0544; int unk0548;
    int unk054C; int unk0550; int unk0554; int unk0558; int unk055C; int unk0560; int unk0564; int unk0568;
    int unk056C; int unk0570; int unk0574; int unk0578; int unk057C; int unk0580; int unk0584; int unk0588;
    int unk058C; int unk0590; int unk0594; int unk0598; int unk059C; int unk05A0; int unk05A4; int unk05A8;
    int unk05AC; int unk05B0; int unk05B4; int unk05B8; int unk05BC; int unk05C0; int unk05C4; int unk05C8;
    int unk05CC; int unk05D0; int unk05D4; int unk05D8; int unk05DC; int unk05E0; int unk05E4; int unk05E8;
    int unk05EC; int unk05F0; int unk05F4; int unk05F8; int unk05FC; int unk0600; int unk0604; int unk0608;
    int unk060C; int unk0610; int unk0614; int unk0618; int unk061C; int unk0620; int unk0624; int unk0628;
    int unk062C; int unk0630; int unk0634; int unk0638; int unk063C; int unk0640; int unk0644; int unk0648;
    int unk064C; int unk0650; int unk0654; int unk0658; int unk065C; int unk0660;
    NiBound m_kBound;
    int unk0674; int unk0678; int unk067C; int unk0680; int unk0684; int unk0688; int unk068C; int unk0690;
    int unk0694; int unk0698; int unk069C; int unk06A0; int unk06A4; int unk06A8; int unk06AC; int unk06B0;
    int unk06B4; int unk06B8; int unk06BC; int unk06C0; int unk06C4; int unk06C8; int unk06CC; int unk06D0;
    int unk06D4; int unk06D8; int unk06DC; int unk06E0; int unk06E4; int unk06E8; int unk06EC; int unk06F0;
    int unk06F4; int unk06F8;
    bool m_bDeviceLost;
    bool NiDX9Renderer_IsHardwareSkinned(Geom* geom, int flag);
    void DrawGeometry(Geom* geom);
};

// @fnv 0x00e74840
void Renderer::DrawGeometry(Geom* geom)
{
    if (m_bDeviceLost)
        return;
    GeomData* data = geom->m_spGeometryData;
    if (data->GetActiveVertexQuantity() == 0)
        return;
    SkinInstance* skin = geom->m_spSkinningInstance;
    const NiBound& rkBound = geom->m_pkBound ? *geom->m_pkBound : DAT_011f4288;
    // The original copies the bound storage without running a constructor.
    unsigned int boundStorage[sizeof(NiBound) / sizeof(unsigned int)];
    NiBound& kBound = *reinterpret_cast<NiBound*>(boundStorage);
    memcpy(&kBound, &rkBound, sizeof(kBound));
    bool bHasPartitions = NiDX9Renderer_IsHardwareSkinned(geom, 0);
    GeomBuffData* pBuffData = geom->m_spGeometryData->m_pkGeometryRendererData;
    geom->m_pGeometryShader->GetActiveVertexQuantity();
    CopyPoint3Storage(m_kBound.m_kCenter, kBound.m_kCenter);
    m_kBound.m_fBoundRadius = kBound.m_fBoundRadius;
    if (bHasPartitions)
    {
        SkinPartition* pSkinPartition = skin->m_pkSkinMeshPartition;
        unsigned int uiPartitionCount = pSkinPartition->m_uiPartitionCount;
        SkinPartitionEntry* pPartition = pSkinPartition->m_pPartitions;
        int type = (pPartition->m_usStrips != 0) + 4;
        for (unsigned int i = 0; i < uiPartitionCount; i++, pPartition++)
        {
            GeomBuffData* pPartBuffData = pPartition->m_pkGeometryRendererData;
            unsigned int start = 0;
            for (unsigned int j = 0; j < pPartBuffData->m_uiMaximumIndex; j++)
            {
                unsigned int count;
                if (pPartBuffData->m_pusIndexData)
                    count = pPartBuffData->m_pusIndexData[j] - 2;
                else
                    count = pPartBuffData->m_uiTriangles;
                m_pD3DDevice->DrawIndexedPrimitive(type, pPartBuffData->m_uiBufferSize, 0, pPartition->m_usVertices, start, count);
                start += count + 2;
            }
        }
    }
    else if (pBuffData->m_pkIndexBuffer)
    {
        unsigned int start = 0;
        for (unsigned int j = 0; j < pBuffData->m_uiMaximumIndex; j++)
        {
            unsigned int count;
            if (pBuffData->m_pusIndexData)
                count = pBuffData->m_pusIndexData[j] - 2;
            else
                count = pBuffData->m_uiTriangles;
            m_pD3DDevice->DrawIndexedPrimitive(pBuffData->m_eRequestType, pBuffData->m_uiBufferSize, 0, pBuffData->m_uiVertexCount, start, count);
            start += count + 2;
        }
    }
    else
    {
        m_pD3DDevice->DrawPrimitive(pBuffData->m_eRequestType, pBuffData->m_uiBufferSize, pBuffData->m_uiTriangles);
    }
    data->m_usDirtyFlags &= 0xf000;
}
}  // namespace fnv_00e74840

class GlobalObjectO2_00a7b610 { public: const char* name; GlobalObjectO2_00a7b610* base; };
// The type FUN_00e74dc0 checks with IsKindOf is NiDX92DBufferData's NiRTTI (0x0126f59c, built by 0x00fc7320
// with the name "NiDX92DBufferData").
__forceinline bool IsKindOfType(NiDX92DBufferData* p, const NiRTTI* type) {
 const NiRTTI* r=p->GetRTTI();
 while(r) {if(r==type)return true;r=r->m_pBaseRTTI;}return false;
}
inline NiDX92DBufferData* CastBound(NiDX92DBufferData* p) {
 if(p==0)return 0;
 bool kind=IsKindOfType(p,&NiDX92DBufferData::ms_RTTI);
 return kind ? p : 0;
}
struct BoundNode { BoundNode* next; BoundNode* prev; NiDX92DBufferData* item;
 static NiDX92DBufferData*& Advance(BoundNode*& n) {NiDX92DBufferData*& value=n->item;n=n->next;return value;}
};
struct BoundCache : ConsolePointerListBase<ConsolePointerAllocator<unsigned int>, NiDX92DBufferData*> {
 void AddTail(NiDX92DBufferData* const&) throw();
};
struct BoundCollection {
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
 virtual void v2c();
 virtual void v30();
 virtual void v34();
 virtual void v38();
 virtual void v3c();
 virtual void v40();
 virtual void v44();
 virtual void v48();
 virtual void v4c();
 virtual void v50();
 virtual void v54();
 virtual void v58();
 virtual void v5c();
 virtual void v60();
 virtual void v64();
 virtual void v68();
 virtual void v6c();
 virtual void v70();
 virtual void v74();
 virtual void v78();
 virtual void v7c();
 virtual void v80();
 virtual void v84();
 virtual void v88();
 virtual void v8c();
 virtual void v90();
 virtual void v94();
 virtual void v98();
 virtual void v9c();
 virtual void va0();
 virtual unsigned int Count();
 virtual void va8();
 virtual void vac();
 virtual void vb0();
 virtual void vb4();
 virtual void vb8();
 virtual void vbc();
 virtual void vc0();
 virtual void vc4();
 virtual NiDX92DBufferData* Get(unsigned int);
};
struct ResolveDevice {
 virtual void d00();
 virtual void d04();
 virtual void d08();
 virtual void d0c();
 virtual void d10();
 virtual void d14();
 virtual void d18();
 virtual void d1c();
 virtual void d20();
 virtual void d24();
 virtual void d28();
 virtual void d2c();
 virtual void d30();
 virtual void d34();
 virtual void d38();
 virtual void d3c();
 virtual void d40();
 virtual void d44();
 virtual void d48();
 virtual void d4c();
 virtual void d50();
 virtual void d54();
 virtual void d58();
 virtual void d5c();
 virtual void d60();
 virtual void d64();
 virtual void d68();
 virtual void d6c();
 virtual void d70();
 virtual void d74();
 virtual void d78();
 virtual void d7c();
 virtual void d80();
 virtual void d84();
 virtual int __stdcall Copy(void*,void*,void*,void*,int);
};
struct ResolveRenderer {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 unsigned int unk07c;
 unsigned int unk080;
 unsigned int unk084;
 unsigned int unk088;
 unsigned int unk08c;
 unsigned int unk090;
 unsigned int unk094;
 unsigned int unk098;
 unsigned int unk09c;
 unsigned int unk0a0;
 unsigned int unk0a4;
 unsigned int unk0a8;
 unsigned int unk0ac;
 unsigned int unk0b0;
 unsigned int unk0b4;
 unsigned int unk0b8;
 unsigned int unk0bc;
 unsigned int unk0c0;
 unsigned int unk0c4;
 unsigned int unk0c8;
 unsigned int unk0cc;
 unsigned int unk0d0;
 unsigned int unk0d4;
 unsigned int unk0d8;
 unsigned int unk0dc;
 unsigned int unk0e0;
 unsigned int unk0e4;
 unsigned int unk0e8;
 unsigned int unk0ec;
 unsigned int unk0f0;
 unsigned int unk0f4;
 unsigned int unk0f8;
 unsigned int unk0fc;
 unsigned int unk100;
 unsigned int unk104;
 unsigned int unk108;
 unsigned int unk10c;
 unsigned int unk110;
 unsigned int unk114;
 unsigned int unk118;
 unsigned int unk11c;
 unsigned int unk120;
 unsigned int unk124;
 unsigned int unk128;
 unsigned int unk12c;
 unsigned int unk130;
 unsigned int unk134;
 unsigned int unk138;
 unsigned int unk13c;
 unsigned int unk140;
 unsigned int unk144;
 unsigned int unk148;
 unsigned int unk14c;
 unsigned int unk150;
 unsigned int unk154;
 unsigned int unk158;
 unsigned int unk15c;
 unsigned int unk160;
 unsigned int unk164;
 unsigned int unk168;
 unsigned int unk16c;
 unsigned int unk170;
 unsigned int unk174;
 unsigned int unk178;
 unsigned int unk17c;
 unsigned int unk180;
 unsigned int unk184;
 unsigned int unk188;
 unsigned int unk18c;
 unsigned int unk190;
 unsigned int unk194;
 unsigned int unk198;
 unsigned int unk19c;
 unsigned int unk1a0;
 unsigned int unk1a4;
 unsigned int unk1a8;
 unsigned int unk1ac;
 unsigned int unk1b0;
 unsigned int unk1b4;
 unsigned int unk1b8;
 unsigned int unk1bc;
 unsigned int unk1c0;
 unsigned int unk1c4;
 unsigned int unk1c8;
 unsigned int unk1cc;
 unsigned int unk1d0;
 unsigned int unk1d4;
 unsigned int unk1d8;
 unsigned int unk1dc;
 unsigned int unk1e0;
 unsigned int unk1e4;
 unsigned int unk1e8;
 unsigned int unk1ec;
 unsigned int unk1f0;
 unsigned int unk1f4;
 unsigned int unk1f8;
 unsigned int unk1fc;
 unsigned int unk200;
 unsigned int unk204;
 unsigned int unk208;
 unsigned int unk20c;
 unsigned int unk210;
 unsigned int unk214;
 unsigned int unk218;
 unsigned int unk21c;
 unsigned int unk220;
 unsigned int unk224;
 unsigned int unk228;
 unsigned int unk22c;
 unsigned int unk230;
 unsigned int unk234;
 unsigned int unk238;
 unsigned int unk23c;
 unsigned int unk240;
 unsigned int unk244;
 unsigned int unk248;
 unsigned int unk24c;
 unsigned int unk250;
 unsigned int unk254;
 unsigned int unk258;
 unsigned int unk25c;
 unsigned int unk260;
 unsigned int unk264;
 unsigned int unk268;
 unsigned int unk26c;
 unsigned int unk270;
 unsigned int unk274;
 unsigned int unk278;
 unsigned int unk27c;
 unsigned int unk280;
 unsigned int unk284;
 ResolveDevice* device;
 unsigned int unk28c;
 unsigned int unk290;
 unsigned int unk294;
 unsigned int unk298;
 unsigned int unk29c;
 unsigned int unk2a0;
 unsigned int unk2a4;
 unsigned int unk2a8;
 unsigned int unk2ac;
 unsigned int unk2b0;
 unsigned int unk2b4;
 unsigned int unk2b8;
 unsigned int unk2bc;
 unsigned int unk2c0;
 unsigned int unk2c4;
 unsigned int unk2c8;
 unsigned int unk2cc;
 unsigned int unk2d0;
 unsigned int unk2d4;
 unsigned int unk2d8;
 unsigned int unk2dc;
 unsigned int unk2e0;
 unsigned int unk2e4;
 unsigned int unk2e8;
 unsigned int unk2ec;
 unsigned int unk2f0;
 unsigned int unk2f4;
 unsigned int unk2f8;
 unsigned int unk2fc;
 unsigned int unk300;
 unsigned int unk304;
 unsigned int unk308;
 unsigned int unk30c;
 unsigned int unk310;
 unsigned int unk314;
 unsigned int unk318;
 unsigned int unk31c;
 unsigned int unk320;
 unsigned int unk324;
 unsigned int unk328;
 unsigned int unk32c;
 unsigned int unk330;
 unsigned int unk334;
 unsigned int unk338;
 unsigned int unk33c;
 unsigned int unk340;
 unsigned int unk344;
 unsigned int unk348;
 unsigned int unk34c;
 unsigned int unk350;
 unsigned int unk354;
 unsigned int unk358;
 unsigned int unk35c;
 unsigned int unk360;
 unsigned int unk364;
 unsigned int unk368;
 unsigned int unk36c;
 unsigned int unk370;
 unsigned int unk374;
 unsigned int unk378;
 unsigned int unk37c;
 unsigned int unk380;
 unsigned int unk384;
 unsigned int unk388;
 unsigned int unk38c;
 unsigned int unk390;
 unsigned int unk394;
 unsigned int unk398;
 unsigned int unk39c;
 unsigned int unk3a0;
 unsigned int unk3a4;
 unsigned int unk3a8;
 unsigned int unk3ac;
 unsigned int unk3b0;
 unsigned int unk3b4;
 unsigned int unk3b8;
 unsigned int unk3bc;
 unsigned int unk3c0;
 unsigned int unk3c4;
 unsigned int unk3c8;
 unsigned int unk3cc;
 unsigned int unk3d0;
 unsigned int unk3d4;
 unsigned int unk3d8;
 unsigned int unk3dc;
 unsigned int unk3e0;
 unsigned int unk3e4;
 unsigned int unk3e8;
 unsigned int unk3ec;
 unsigned int unk3f0;
 unsigned int unk3f4;
 unsigned int unk3f8;
 unsigned int unk3fc;
 unsigned int unk400;
 unsigned int unk404;
 unsigned int unk408;
 unsigned int unk40c;
 unsigned int unk410;
 unsigned int unk414;
 unsigned int unk418;
 unsigned int unk41c;
 unsigned int unk420;
 unsigned int unk424;
 unsigned int unk428;
 unsigned int unk42c;
 unsigned int unk430;
 unsigned int unk434;
 unsigned int unk438;
 unsigned int unk43c;
 unsigned int unk440;
 unsigned int unk444;
 unsigned int unk448;
 unsigned int unk44c;
 unsigned int unk450;
 unsigned int unk454;
 unsigned int unk458;
 unsigned int unk45c;
 unsigned int unk460;
 unsigned int unk464;
 unsigned int unk468;
 unsigned int unk46c;
 unsigned int unk470;
 unsigned int unk474;
 unsigned int unk478;
 unsigned int unk47c;
 unsigned int unk480;
 unsigned int unk484;
 unsigned int unk488;
 unsigned int unk48c;
 unsigned int unk490;
 unsigned int unk494;
 unsigned int unk498;
 unsigned int unk49c;
 unsigned int unk4a0;
 unsigned int unk4a4;
 unsigned int unk4a8;
 unsigned int unk4ac;
 unsigned int unk4b0;
 unsigned int unk4b4;
 unsigned int unk4b8;
 unsigned int unk4bc;
 unsigned int unk4c0;
 unsigned int unk4c4;
 unsigned int unk4c8;
 unsigned int unk4cc;
 unsigned int unk4d0;
 unsigned int unk4d4;
 unsigned int unk4d8;
 unsigned int unk4dc;
 unsigned int unk4e0;
 unsigned int unk4e4;
 unsigned int unk4e8;
 unsigned int unk4ec;
 unsigned int unk4f0;
 unsigned int unk4f4;
 unsigned int unk4f8;
 unsigned int unk4fc;
 unsigned int unk500;
 unsigned int unk504;
 unsigned int unk508;
 unsigned int unk50c;
 unsigned int unk510;
 unsigned int unk514;
 unsigned int unk518;
 unsigned int unk51c;
 unsigned int unk520;
 unsigned int unk524;
 unsigned int unk528;
 unsigned int unk52c;
 unsigned int unk530;
 unsigned int unk534;
 unsigned int unk538;
 unsigned int unk53c;
 unsigned int unk540;
 unsigned int unk544;
 unsigned int unk548;
 unsigned int unk54c;
 unsigned int unk550;
 unsigned int unk554;
 unsigned int unk558;
 unsigned int unk55c;
 unsigned int unk560;
 unsigned int unk564;
 unsigned int unk568;
 unsigned int unk56c;
 unsigned int unk570;
 unsigned int unk574;
 unsigned int unk578;
 unsigned int unk57c;
 unsigned int unk580;
 unsigned int unk584;
 unsigned int unk588;
 unsigned int unk58c;
 unsigned int unk590;
 unsigned int unk594;
 unsigned int unk598;
 unsigned int unk59c;
 unsigned int unk5a0;
 unsigned int unk5a4;
 unsigned int unk5a8;
 unsigned int unk5ac;
 unsigned int unk5b0;
 unsigned int unk5b4;
 unsigned int unk5b8;
 unsigned int unk5bc;
 unsigned int unk5c0;
 unsigned int unk5c4;
 unsigned int unk5c8;
 unsigned int unk5cc;
 unsigned int unk5d0;
 unsigned int unk5d4;
 unsigned int unk5d8;
 unsigned int unk5dc;
 unsigned int unk5e0;
 unsigned int unk5e4;
 unsigned int unk5e8;
 unsigned int unk5ec;
 unsigned int unk5f0;
 unsigned int unk5f4;
 unsigned int unk5f8;
 unsigned int unk5fc;
 unsigned int unk600;
 unsigned int unk604;
 unsigned int unk608;
 unsigned int unk60c;
 unsigned int unk610;
 unsigned int unk614;
 unsigned int unk618;
 unsigned int unk61c;
 unsigned int unk620;
 unsigned int unk624;
 unsigned int unk628;
 unsigned int unk62c;
 unsigned int unk630;
 unsigned int unk634;
 unsigned int unk638;
 unsigned int unk63c;
 unsigned int unk640;
 unsigned int unk644;
 unsigned int unk648;
 unsigned int unk64c;
 unsigned int unk650;
 unsigned int unk654;
 unsigned int unk658;
 unsigned int unk65c;
 unsigned int unk660;
 unsigned int unk664;
 unsigned int unk668;
 unsigned int unk66c;
 unsigned int unk670;
 unsigned int unk674;
 unsigned int unk678;
 unsigned int unk67c;
 unsigned int unk680;
 unsigned int unk684;
 unsigned int unk688;
 unsigned int unk68c;
 unsigned int unk690;
 unsigned int unk694;
 unsigned int unk698;
 unsigned int unk69c;
 unsigned int unk6a0;
 unsigned int unk6a4;
 unsigned int unk6a8;
 unsigned int unk6ac;
 unsigned int unk6b0;
 unsigned int unk6b4;
 unsigned int unk6b8;
 unsigned int unk6bc;
 unsigned int unk6c0;
 unsigned int unk6c4;
 unsigned int unk6c8;
 unsigned int unk6cc;
 unsigned int unk6d0;
 unsigned int unk6d4;
 unsigned int unk6d8;
 unsigned int unk6dc;
 unsigned int unk6e0;
 unsigned int unk6e4;
 unsigned int unk6e8;
 unsigned int unk6ec;
 unsigned int unk6f0;
 unsigned int unk6f4;
 unsigned int unk6f8;
 bool disabled;
 unsigned int unk700;
 unsigned int unk704;
 unsigned int unk708;
 unsigned int unk70c;
 unsigned int unk710;
 unsigned int unk714;
 unsigned int unk718;
 unsigned int unk71c;
 unsigned int unk720;
 unsigned int unk724;
 unsigned int unk728;
 unsigned int unk72c;
 unsigned int unk730;
 unsigned int unk734;
 unsigned int unk738;
 unsigned int unk73c;
 unsigned int unk740;
 unsigned int unk744;
 unsigned int unk748;
 unsigned int unk74c;
 unsigned int unk750;
 unsigned int unk754;
 unsigned int unk758;
 unsigned int unk75c;
 unsigned int unk760;
 unsigned int unk764;
 unsigned int unk768;
 unsigned int unk76c;
 unsigned int unk770;
 unsigned int unk774;
 unsigned int unk778;
 unsigned int unk77c;
 unsigned int unk780;
 unsigned int unk784;
 unsigned int unk788;
 unsigned int unk78c;
 unsigned int unk790;
 unsigned int unk794;
 unsigned int unk798;
 unsigned int unk79c;
 unsigned int unk7a0;
 unsigned int unk7a4;
 unsigned int unk7a8;
 unsigned int unk7ac;
 unsigned int unk7b0;
 unsigned int unk7b4;
 unsigned int unk7b8;
 unsigned int unk7bc;
 unsigned int unk7c0;
 unsigned int unk7c4;
 unsigned int unk7c8;
 unsigned int unk7cc;
 unsigned int unk7d0;
 unsigned int unk7d4;
 unsigned int unk7d8;
 unsigned int unk7dc;
 unsigned int unk7e0;
 unsigned int unk7e4;
 unsigned int unk7e8;
 unsigned int unk7ec;
 unsigned int unk7f0;
 unsigned int unk7f4;
 unsigned int unk7f8;
 unsigned int unk7fc;
 unsigned int unk800;
 unsigned int unk804;
 unsigned int unk808;
 unsigned int unk80c;
 unsigned int unk810;
 unsigned int unk814;
 unsigned int unk818;
 unsigned int unk81c;
 unsigned int unk820;
 unsigned int unk824;
 unsigned int unk828;
 unsigned int unk82c;
 unsigned int unk830;
 unsigned int unk834;
 unsigned int unk838;
 unsigned int unk83c;
 unsigned int unk840;
 unsigned int unk844;
 unsigned int unk848;
 unsigned int unk84c;
 unsigned int unk850;
 unsigned int unk854;
 unsigned int unk858;
 unsigned int unk85c;
 unsigned int unk860;
 unsigned int unk864;
 unsigned int unk868;
 unsigned int unk86c;
 unsigned int unk870;
 unsigned int unk874;
 unsigned int unk878;
 unsigned int unk87c;
 unsigned int unk880;
 unsigned int unk884;
 BoundCollection* collection;
 unsigned int collectionCount;
 unsigned int unk890;
 unsigned int unk894;
 unsigned int unk898;
 unsigned int unk89c;
 unsigned int unk8a0;
 unsigned int unk8a4;
 unsigned int unk8a8;
 unsigned int unk8ac;
 unsigned int unk8b0;
 unsigned int unk8b4;
 unsigned int unk8b8;
 unsigned int unk8bc;
 unsigned int unk8c0;
 unsigned int unk8c4;
 unsigned int unk8c8;
 unsigned int unk8cc;
 unsigned int unk8d0;
 unsigned int unk8d4;
 unsigned int unk8d8;
 unsigned int unk8dc;
 unsigned int unk8e0;
 unsigned int unk8e4;
 unsigned int unk8e8;
 unsigned int unk8ec;
 unsigned int unk8f0;
 unsigned int unk8f4;
 unsigned int unk8f8;
 unsigned int unk8fc;
 BoundCache cache;
 bool NiDX9Renderer_EndUsingRenderTargetGroup();
};
// For each bound in the collection, copies surface data to the device and adds cache-enabled bounds to the cache list, then clears the collection.
// @fnv 0x00e74dc0
// src: COMMUNITY 0x00e74dc0
bool ResolveRenderer::NiDX9Renderer_EndUsingRenderTargetGroup() {
 if(!disabled) {
  for(unsigned int uiIndex=0;uiIndex<collection->Count();++uiIndex) {
   NiDX92DBufferData* object=collection->Get(uiIndex);
   NiDX92DBufferData* bound=CastBound(object);
   if(bound->GetMSAAType()) device->Copy(bound->m_pkMSAASurface,0,bound->m_pkSurface,0,0);
   if(bound->CanDisplayFrame()) {
    InterlockedIncrement((long volatile*)&bound->m_uiRefCount);
    BoundNode* found;
    BoundNode* node=(BoundNode*)cache.head;
    if(node) do {BoundNode* old=node;NiDX92DBufferData*& value=BoundNode::Advance(node);if(bound==value){found=old;goto searched;}} while(node);
    found=0;
    searched:
    bool missing=(found==0);
    if(InterlockedDecrement((long volatile*)&bound->m_uiRefCount)==0) bound->DeleteThis();
    if(missing) {
     NiDX92DBufferData* pMultiBound=bound;
     InterlockedIncrement((long volatile*)&bound->m_uiRefCount);
     cache.AddTail(pMultiBound);
     if(InterlockedDecrement((long volatile*)&bound->m_uiRefCount)==0) bound->DeleteThis();
    }
   }
  }
  collection=0;collectionCount=0;
 }
 return true;
}

// @fnv 0x00e76e30
unsigned int ConvertVertexComponents(FUN_00e76c30_Info* info)
{
    unsigned int total = 0;
    unsigned char* source = reinterpret_cast<unsigned char*>(info->pfSrc);
    unsigned char* output = info->pucDest;
    unsigned short* indices = info->pusRemap;
    if (!source) {
        for (unsigned short row = 0; row < info->usVerts; ++row) {
            _fnv_zlib_memset(output, 0, info->uiDestSize);
            total += info->uiDestSize;
            output += info->uiDestStride;
        }
        return total;
    }
    unsigned short available = info->usComps - 4;
    unsigned short width = info->eType == 6 ? 2 : 4;
    unsigned short copied = available > width ? width : available;
    if (indices) {
        unsigned short mapped = 0;
        for (unsigned short row = 0; row < info->usVerts; ++row) {
            const unsigned short* pusValues = reinterpret_cast<const unsigned short*>(
                source + indices[mapped++] * info->uiSrcStride);
            unsigned short* destination = reinterpret_cast<unsigned short*>(output);
            unsigned short component = 0;
            for (; component < copied; ++component) {
                *destination++ = *pusValues;
                pusValues += 2;
            }
            for (; component < width; ++component)
                *destination++ = 0;
            total += info->uiDestSize;
            output += info->uiDestStride;
        }
    } else {
        for (unsigned short row = 0; row < info->usVerts; ++row) {
            const unsigned short* pusValues = reinterpret_cast<const unsigned short*>(source);
            unsigned short* destination = reinterpret_cast<unsigned short*>(output);
            unsigned short component = 0;
            for (; component < copied; ++component) {
                *destination++ = *pusValues;
                pusValues += 2;
            }
            for (; component < width; ++component)
                *destination++ = 0;
            total += info->uiDestSize;
            source += info->uiSrcStride;
            output += info->uiDestStride;
        }
    }
    return total;
}

extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);

struct ByteVertexConversion {

    unsigned int format;

    unsigned short sourceType;

    unsigned short unk06;

    unsigned short count;

    unsigned short unk0A;

    const unsigned short* indices;

    const unsigned char* source;

    unsigned int unk14;

    unsigned int sourceStride;

    unsigned int destinationSize;

    unsigned int destinationStride;

    unsigned int unk24;

    unsigned int unk28;

    unsigned char* destination;

};

// Converts info->count vertices from source to destination, zero-filling missing components and optionally indexing the source; returns bytes written.
// @fnv 0x00e77770
unsigned int __cdecl ConvertVertexFormat(ByteVertexConversion* info) {

    unsigned int written = 0;

    const unsigned char* source = info->source;

    const unsigned short* indices = info->indices;

    unsigned char* destination = info->destination;

    if (!source) {

        for (unsigned short i = 0; i < info->count; i++) {

            FUN_00ec61c0(destination, 0, info->destinationSize);

            destination += info->destinationStride;

            written += info->destinationSize;

        }

        return written;

    }

    unsigned short supplied = info->sourceType - 24;

    unsigned short components = info->format == 6 ? 2 : 4;

    unsigned short copied = supplied > components ? components : supplied;

    if (indices) {

        unsigned short index = 0;

        for (unsigned short i = 0; i < info->count; i++) {

            const unsigned char* input = source + indices[index++] * info->sourceStride;

            unsigned short* output = reinterpret_cast<unsigned short*>(destination);

            unsigned short j;

            for (j = 0; j < copied; j++) *output++ = *input++;

            for (; j < components; j++) *output++ = 0;

            written += info->destinationSize;

            destination += info->destinationStride;

        }

    } else {

        for (unsigned short i = 0; i < info->count; i++) {

            const unsigned char* input = source;

            unsigned short* output = reinterpret_cast<unsigned short*>(destination);

            unsigned short j;

            for (j = 0; j < copied; j++) *output++ = *input++;

            for (; j < components; j++) *output++ = 0;

            written += info->destinationSize;

            source += info->sourceStride;

            destination += info->destinationStride;

        }

    }

    return written;

}

void* _fnv_zlib_memset(void* dst, int val, unsigned int size);

struct FUN_00e77b50_Info {
    int eType;
    unsigned short usComps;
    unsigned short pad06;
    unsigned short usVerts;
    unsigned short pad0a;
    unsigned short* pusRemap;
    unsigned char* pucSrc;
    unsigned int pad14;
    unsigned int uiSrcStride;
    unsigned int uiDestSize;
    unsigned int uiDestStride;
    unsigned int pad24;
    unsigned int pad28;
    unsigned char* pucDest;
};

// @fnv 0x00e77b50
// src: COMMUNITY 0x00e77b50
unsigned int NiD3DShaderDeclaration_Pack_LongToUnsignedByte(FUN_00e77b50_Info* pkInfo)
{
    unsigned int uiTotal = 0;
    unsigned char* pucSrc = pkInfo->pucSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;

    if (!pucSrc)
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
        return uiTotal;
    }

    unsigned short usExtra = pkInfo->usComps - 4;
    unsigned short ItemUpdateArray = usExtra > 4 ? 4 : usExtra;

    if (pusRemap)
    {
        unsigned short k = 0;
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned char* s = pucSrc + pusRemap[k++] * pkInfo->uiSrcStride;
            unsigned char* d = pucDest;
            unsigned short j;
            for (j = 0; j < (unsigned short)ItemUpdateArray; j++)
            {
                *d++ = *s;
                s += 4;
            }
            if (j < 4)
                _fnv_zlib_memset(d, 0, (unsigned short)(4 - j));
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkInfo->usVerts; i++)
        {
            unsigned char* s = pucSrc;
            unsigned char* d = pucDest;
            unsigned short j;
            for (j = 0; j < (unsigned short)ItemUpdateArray; j++)
            {
                *d++ = *s;
                s += 4;
            }
            if (j < 4)
                _fnv_zlib_memset(d, 0, (unsigned short)(4 - j));
            uiTotal += pkInfo->uiDestSize;
            pucSrc += pkInfo->uiSrcStride;
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiTotal;
}

struct PackByteInfo {
    unsigned int field00;
    unsigned short type, field06;
    unsigned short count, field0a;
    unsigned short* indices;
    unsigned int* source;
    unsigned int field14, sourceStride, elementSize, destStride, field24, field28;
    unsigned char* dest;
};
// @fnv 0x00e77d00
unsigned int __cdecl PackByteElements(PackByteInfo* pInfo) {
    unsigned int size=0;
    unsigned int* src=pInfo->source;
    unsigned short* indices=pInfo->indices;
    unsigned char* dst=pInfo->dest;
    if (!src) {
        for(unsigned short i=0;i<pInfo->count;i++) {
            _fnv_zlib_memset(dst,0,pInfo->elementSize);
            dst+=pInfo->destStride;
            size+=pInfo->elementSize;
        }
        return size;
    }
    unsigned int type=(unsigned short)(pInfo->type-8);
    unsigned short comps=(unsigned short)type>4 ? 4 : (unsigned short)type;
    if(indices) {
        unsigned short index=0;
        for(unsigned short i=0;i<pInfo->count;i++) {
            unsigned int* in=(unsigned int*)((unsigned char*)src+indices[index++]*pInfo->sourceStride);
            unsigned char* out=dst;
            unsigned short j;
            for(j=0;j<comps;j++) *out++=(unsigned char)*in++;
            if(j<4) _fnv_zlib_memset(out,0,(unsigned short)(4-j));
            size+=pInfo->elementSize;
            dst+=pInfo->destStride;
        }
    } else {
        for(unsigned short i=0;i<pInfo->count;i++) {
            unsigned int* in=src;
            unsigned char* out=dst;
            unsigned short j;
            for(j=0;j<comps;j++) *out++=(unsigned char)*in++;
            if(j<4) _fnv_zlib_memset(out,0,(unsigned short)(4-j));
            size+=pInfo->elementSize;
            src=(unsigned int*)((unsigned char*)src+pInfo->sourceStride);
            dst+=pInfo->destStride;
        }
    }
    return size;
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
inline unsigned short minimum(unsigned short a, unsigned short b) { return a > b ? b : a; }
struct ByteFloatStream {
 unsigned short lastComponent, unk02, type, unk06, vertices, unk0a;
 unsigned short* indices;
 signed char* source;
 unsigned unk14, sourceStride, elementSize, destStride, unk24, unk28;
 unsigned char* dest;
};
// Converts each vertex's signed-byte components to floats divided by 127 (clamped at -1), zero-fills the rest, and returns the total bytes written.
// @fnv 0x00e79920
unsigned __cdecl ConvertByteFloatStream(ByteFloatStream* pStream) {
 unsigned total = 0;
 signed char* source = pStream->source;
 unsigned short* indices = pStream->indices;
 unsigned char* dest = pStream->dest;
 if (!source) {
  for (unsigned short i=0; i<pStream->vertices; ++i) {
   fnv_zlib_memset(dest,0,pStream->elementSize);
   dest += pStream->destStride;
   total += pStream->elementSize;
  }
  return total;
 }
 {
  unsigned short available = pStream->type - 20;
  unsigned short components = pStream->lastComponent + 1;
  unsigned short count = minimum(available, components);
  if (indices) {
   unsigned short remap=0;
   for (unsigned short i=0; i<pStream->vertices; ++i) {
    signed char* input = source + indices[remap++]*pStream->sourceStride;
    float* output = (float*)dest;
    unsigned short j=0;
    for (;j<count;++j) {
     float value = (float)(*input / 127.0);
     *output++ = value < -1.0f ? -1.0f : value;
     ++input;
    }
    for (;j<components;++j) *output++ = 0;
    dest += pStream->destStride;
    total += pStream->elementSize;
   }
  } else {
   for (unsigned short i=0; i<pStream->vertices; ++i) {
    signed char* input = source;
    float* output = (float*)dest;
    unsigned short j=0;
    for (;j<count;++j) {
     float value = (float)(*input / 127.0);
     *output++ = value < -1.0f ? -1.0f : value;
     ++input;
    }
    for (;j<components;++j) *output++ = 0;
    source += pStream->sourceStride;
    dest += pStream->destStride;
    total += pStream->elementSize;
   }
  }
 }
 return total;
}

struct ColorStream {
    unsigned int unk00;
    unsigned short type, unk06, count, unk0a;
    unsigned short* indices;
    unsigned char* src;
    unsigned int unk14, srcStride, elemSize, dstStride, unk24, unk28;
    unsigned char* dst;
};

void* _fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00e7a0a0
unsigned int ConvertColorStream(ColorStream* pStream) {
    unsigned char* src = pStream->src;
    unsigned short* indices = pStream->indices;
    unsigned char* dst = pStream->dst;
    unsigned short i = 0;
    unsigned int written = 0;
    if (!src) {
        for (i = 0; i < pStream->count; i++) {
            _fnv_zlib_memset(dst, 255, pStream->elemSize);
            dst += pStream->dstStride;
            written += pStream->elemSize;
        }
        return written;
    } else {
        unsigned short components = pStream->type - 24;
        unsigned char alpha;
        if (indices) {
            unsigned short index = 0;
            for (unsigned short i = 0; i < pStream->count; i++) {
                unsigned char* pixel = src + indices[index++] * pStream->srcStride;
                alpha = components == 3 ? 255 : pixel[3];
                *(unsigned int*)dst = (((alpha << 8) | pixel[0]) << 8 | pixel[1]) << 8 | pixel[2];
                dst += pStream->dstStride;
                written += pStream->elemSize;
            }
            return written;
        } else {
            for (unsigned short i = 0; i < pStream->count; i++) {
                alpha = components == 3 ? 255 : src[3];
                *(unsigned int*)dst = (((alpha << 8) | src[0]) << 8 | src[1]) << 8 | src[2];
                src += pStream->srcStride;
                dst += pStream->dstStride;
                written += pStream->elemSize;
            }
        }
    }
    return written;
}

struct D3DMATRIX_Custom {
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};

struct D3DVIEWPORT9_Custom {
    unsigned long X;
    unsigned long Y;
    unsigned long Width;
    unsigned long Height;
    float MinZ;
    float MaxZ;
};



struct IDirect3DDevice9_Custom {
    virtual void pad00(); virtual void pad01(); virtual void pad02(); virtual void pad03();
    virtual void pad04(); virtual void pad05(); virtual void pad06(); virtual void pad07();
    virtual void pad08(); virtual void pad09(); virtual void pad10(); virtual void pad11();
    virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15();
    virtual void pad16(); virtual void pad17(); virtual void pad18(); virtual void pad19();
    virtual void pad20(); virtual void pad21(); virtual void pad22(); virtual void pad23();
    virtual void pad24(); virtual void pad25(); virtual void pad26(); virtual void pad27();
    virtual void pad28(); virtual void pad29(); virtual void pad30(); virtual void pad31();
    virtual void pad32(); virtual void pad33(); virtual void pad34(); virtual void pad35();
    virtual void pad36(); virtual void pad37(); virtual void pad38(); virtual void pad39();
    virtual void pad40(); virtual void pad41(); virtual void pad42(); virtual void pad43();
    virtual int __stdcall SetTransform(unsigned int State, const D3DMATRIX_Custom* pMatrix);
    virtual void pad45();
    virtual void pad46();
    virtual int __stdcall SetViewport(const D3DVIEWPORT9_Custom* pViewport);
};

struct StandIn_Mgr {
    virtual void pad00(); virtual void pad01(); virtual void pad02(); virtual void pad03();
    virtual void pad04(); virtual void pad05(); virtual void pad06(); virtual void pad07();
    virtual void pad08(); virtual void pad09(); virtual void pad10(); virtual void pad11();
    virtual void pad12(); virtual void pad13(); virtual void pad14(); virtual void pad15();
    virtual void pad16(); virtual void pad17();
    virtual void SetCameraRange(float fNear, float fFar);
};

struct StandIn_Renderer {
    int unk_000; int unk_004; int unk_008; int unk_00c; int unk_010; int unk_014; int unk_018; int unk_01c;
    int unk_020; int unk_024; int unk_028; int unk_02c; int unk_030; int unk_034; int unk_038; int unk_03c;
    int unk_040; int unk_044; int unk_048; int unk_04c; int unk_050; int unk_054; int unk_058; int unk_05c;
    int unk_060; int unk_064; int unk_068; int unk_06c; int unk_070; int unk_074; int unk_078; int unk_07c;
    int unk_080; int unk_084; int unk_088; int unk_08c; int unk_090; int unk_094; int unk_098; int unk_09c;
    int unk_0a0; int unk_0a4; int unk_0a8; int unk_0ac; int unk_0b0; int unk_0b4; int unk_0b8; int unk_0bc;
    int unk_0c0; int unk_0c4; int unk_0c8; int unk_0cc; int unk_0d0; int unk_0d4; int unk_0d8; int unk_0dc;
    int unk_0e0; int unk_0e4; int unk_0e8; int unk_0ec; int unk_0f0; int unk_0f4; int unk_0f8; int unk_0fc;
    int unk_100; int unk_104; int unk_108; int unk_10c; int unk_110; int unk_114; int unk_118; int unk_11c;
    int unk_120; int unk_124; int unk_128; int unk_12c; int unk_130; int unk_134; int unk_138; int unk_13c;
    int unk_140; int unk_144; int unk_148; int unk_14c; int unk_150; int unk_154; int unk_158; int unk_15c;
    int unk_160; int unk_164; int unk_168; int unk_16c; int unk_170; int unk_174; int unk_178; int unk_17c;
    int unk_180; int unk_184; int unk_188; int unk_18c; int unk_190; int unk_194; int unk_198; int unk_19c;
    int unk_1a0; int unk_1a4; int unk_1a8; int unk_1ac; int unk_1b0; int unk_1b4; int unk_1b8; int unk_1bc;
    int unk_1c0; int unk_1c4; int unk_1c8; int unk_1cc; int unk_1d0; int unk_1d4; int unk_1d8; int unk_1dc;
    int unk_1e0; int unk_1e4; int unk_1e8; int unk_1ec; int unk_1f0; int unk_1f4; int unk_1f8; int unk_1fc;
    int unk_200; int unk_204; int unk_208; int unk_20c; int unk_210; int unk_214; int unk_218; int unk_21c;
    int unk_220; int unk_224; int unk_228; int unk_22c; int unk_230; int unk_234; int unk_238; int unk_23c;
    int unk_240; int unk_244; int unk_248; int unk_24c; int unk_250; int unk_254; int unk_258; int unk_25c;
    int unk_260; int unk_264; int unk_268; int unk_26c; int unk_270; int unk_274; int unk_278; int unk_27c;
    int unk_280; int unk_284;
    IDirect3DDevice9_Custom* m_pDirectInputDevice;
    int unk_28c; int unk_290; int unk_294; int unk_298; int unk_29c; int unk_2a0; int unk_2a4; int unk_2a8;
    int unk_2ac; int unk_2b0; int unk_2b4; int unk_2b8; int unk_2bc; int unk_2c0; int unk_2c4; int unk_2c8;
    int unk_2cc; int unk_2d0; int unk_2d4; int unk_2d8; int unk_2dc; int unk_2e0; int unk_2e4; int unk_2e8;
    int unk_2ec; int unk_2f0; int unk_2f4; int unk_2f8; int unk_2fc; int unk_300; int unk_304; int unk_308;
    int unk_30c; int unk_310; int unk_314; int unk_318; int unk_31c; int unk_320; int unk_324; int unk_328;
    int unk_32c; int unk_330; int unk_334; int unk_338; int unk_33c; int unk_340; int unk_344; int unk_348;
    int unk_34c; int unk_350; int unk_354; int unk_358; int unk_35c; int unk_360; int unk_364; int unk_368;
    int unk_36c; int unk_370; int unk_374; int unk_378; int unk_37c; int unk_380; int unk_384; int unk_388;
    int unk_38c; int unk_390; int unk_394; int unk_398; int unk_39c; int unk_3a0; int unk_3a4; int unk_3a8;
    int unk_3ac; int unk_3b0; int unk_3b4; int unk_3b8; int unk_3bc; int unk_3c0; int unk_3c4; int unk_3c8;
    int unk_3cc; int unk_3d0; int unk_3d4; int unk_3d8; int unk_3dc; int unk_3e0; int unk_3e4; int unk_3e8;
    int unk_3ec; int unk_3f0; int unk_3f4; int unk_3f8; int unk_3fc; int unk_400; int unk_404; int unk_408;
    int unk_40c; int unk_410; int unk_414; int unk_418; int unk_41c; int unk_420; int unk_424; int unk_428;
    int unk_42c; int unk_430; int unk_434; int unk_438; int unk_43c; int unk_440; int unk_444; int unk_448;
    int unk_44c; int unk_450; int unk_454; int unk_458; int unk_45c; int unk_460; int unk_464; int unk_468;
    int unk_46c; int unk_470; int unk_474; int unk_478; int unk_47c; int unk_480; int unk_484; int unk_488;
    int unk_48c; int unk_490; int unk_494; int unk_498; int unk_49c; int unk_4a0; int unk_4a4; int unk_4a8;
    int unk_4ac; int unk_4b0; int unk_4b4; int unk_4b8; int unk_4bc; int unk_4c0; int unk_4c4; int unk_4c8;
    int unk_4cc; int unk_4d0; int unk_4d4; int unk_4d8; int unk_4dc; int unk_4e0; int unk_4e4; int unk_4e8;
    int unk_4ec; int unk_4f0; int unk_4f4; int unk_4f8; int unk_4fc; int unk_500; int unk_504; int unk_508;
    int unk_50c; int unk_510; int unk_514; int unk_518; int unk_51c; int unk_520; int unk_524; int unk_528;
    int unk_52c; int unk_530; int unk_534; int unk_538; int unk_53c; int unk_540; int unk_544; int unk_548;
    int unk_54c; int unk_550; int unk_554; int unk_558; int unk_55c; int unk_560; int unk_564; int unk_568;
    int unk_56c; int unk_570; int unk_574; int unk_578; int unk_57c; int unk_580; int unk_584; int unk_588;
    int unk_58c; int unk_590; int unk_594; int unk_598; int unk_59c; int unk_5a0; int unk_5a4; int unk_5a8;
    int unk_5ac; int unk_5b0; int unk_5b4; int unk_5b8; int unk_5bc; int unk_5c0; int unk_5c4; int unk_5c8;
    int unk_5cc; int unk_5d0; int unk_5d4; int unk_5d8; int unk_5dc; int unk_5e0; int unk_5e4; int unk_5e8;
    int unk_5ec; int unk_5f0; int unk_5f4; int unk_5f8; int unk_5fc; int unk_600; int unk_604; int unk_608;
    int unk_60c; int unk_610; int unk_614; int unk_618; int unk_61c; int unk_620; int unk_624; int unk_628;
    int unk_62c; int unk_630;
    NiPoint3_Custom_niconsolerenderer m_kCameraPosition;
    NiPoint3_Custom_niconsolerenderer m_kCameraDirection;
    NiPoint3_Custom_niconsolerenderer m_kScreenRight;
    NiPoint3_Custom_niconsolerenderer m_kScreenUp;
    int unk_664; int unk_668; int unk_66c; int unk_670; int unk_674; int unk_678; int unk_67c; int unk_680;
    float m_684;
    float m_688;
    int unk_68c; int unk_690; int unk_694; int unk_698; int unk_69c; int unk_6a0; int unk_6a4; int unk_6a8;
    int unk_6ac; int unk_6b0; int unk_6b4; int unk_6b8; int unk_6bc; int unk_6c0; int unk_6c4; int unk_6c8;
    int unk_6cc; int unk_6d0; int unk_6d4; int unk_6d8; int unk_6dc; int unk_6e0; int unk_6e4; int unk_6e8;
    int unk_6ec; int unk_6f0; int unk_6f4; int unk_6f8;
    unsigned char m_bDeviceLost;
    char unk_6fd; char unk_6fe; char unk_6ff; int unk_700; int unk_704; int unk_708; int unk_70c; int unk_710;
    int unk_714; int unk_718; int unk_71c; int unk_720; int unk_724; int unk_728; int unk_72c; int unk_730;
    int unk_734; int unk_738; int unk_73c; int unk_740; int unk_744; int unk_748; int unk_74c; int unk_750;
    int unk_754; int unk_758; int unk_75c; int unk_760; int unk_764; int unk_768; int unk_76c; int unk_770;
    int unk_774; int unk_778; int unk_77c; int unk_780; int unk_784; int unk_788; int unk_78c; int unk_790;
    int unk_794; int unk_798; int unk_79c; int unk_7a0; int unk_7a4; int unk_7a8; int unk_7ac; int unk_7b0;
    int unk_7b4; int unk_7b8; int unk_7bc; int unk_7c0; int unk_7c4; int unk_7c8; int unk_7cc; int unk_7d0;
    int unk_7d4; int unk_7d8; int unk_7dc; int unk_7e0; int unk_7e4; int unk_7e8; int unk_7ec; int unk_7f0;
    int unk_7f4; int unk_7f8; int unk_7fc; int unk_800; int unk_804; int unk_808; int unk_80c; int unk_810;
    int unk_814; int unk_818; int unk_81c; int unk_820; int unk_824; int unk_828; int unk_82c; int unk_830;
    int unk_834; int unk_838; int unk_83c; int unk_840; int unk_844; int unk_848; int unk_84c; int unk_850;
    int unk_854; int unk_858; int unk_85c; int unk_860; int unk_864; int unk_868; int unk_86c; int unk_870;
    int unk_874; int unk_878; int unk_87c; int unk_880; int unk_884;
    NiConsoleRendererPacketGroup* m_pGroup;
    int unk_88c; int unk_890; int unk_894; int unk_898; int unk_89c; int unk_8a0; int unk_8a4; int unk_8a8;
    int unk_8ac; int unk_8b0; int unk_8b4;
    StandIn_Mgr* m_pMgr;
    int unk_8bc; int unk_8c0; int unk_8c4; int unk_8c8; int unk_8cc; int unk_8d0; int unk_8d4; int unk_8d8;
    int unk_8dc; int unk_8e0; int unk_8e4; int unk_8e8; int unk_8ec; int unk_8f0; int unk_8f4; int unk_8f8;
    int unk_8fc; int unk_900; int unk_904; int unk_908; int unk_90c; int unk_910; int unk_914; int unk_918;
    int unk_91c; int unk_920; int unk_924; int unk_928; int unk_92c; int unk_930; int unk_934; int unk_938;
    int unk_93c; int unk_940; int unk_944; int unk_948; int unk_94c; int unk_950; int unk_954; int unk_958;
    int unk_95c; int unk_960; int unk_964; int unk_968; int unk_96c; int unk_970; int unk_974; int unk_978;
    int unk_97c;
    D3DMATRIX_Custom m_kView;
    D3DMATRIX_Custom m_kProj;
    int unk_a00; int unk_a04; int unk_a08; int unk_a0c; int unk_a10; int unk_a14; int unk_a18; int unk_a1c;
    int unk_a20; int unk_a24; int unk_a28; int unk_a2c; int unk_a30; int unk_a34; int unk_a38; int unk_a3c;
    D3DMATRIX_Custom m_kScreen;

    void SetScreenRect(const NiRect_Custom_niconsolerenderer* pkRect);
};

// Builds view, screen and projection matrices and a viewport from pkRect (or the full render target), then applies them to the device and sets the camera range.
// @fnv 0x00e6cf40
void StandIn_Renderer::SetScreenRect(const NiRect_Custom_niconsolerenderer* pkRect)
{
    if (m_bDeviceLost)
        return;

    unsigned int uiWidth = m_pGroup->GetWidth(0);
    unsigned int uiHeight = m_pGroup->GetHeight(0);

    float m_fGlyphWidthInPixels = (float)uiWidth;
    float m_fGlyphExtent = (float)uiHeight;

    m_kView._11 = 1.0f;
    m_kView._12 = 0.0f;
    m_kView._13 = 0.0f;
    m_kView._14 = 0.0f;
    m_kView._21 = 0.0f;
    m_kView._22 = -1.0f;
    m_kView._23 = 0.0f;
    m_kView._24 = 0.0f;
    m_kView._31 = 0.0f;
    m_kView._32 = 0.0f;
    m_kView._33 = 1.0f;
    m_kView._34 = 0.0f;
    m_kView._41 = -0.5f;
    m_kView._42 = 0.5f;
    m_kView._43 = 1.0f;
    m_kView._44 = 1.0f;

    m_kScreen._11 = 1.0f;
    m_kScreen._12 = 0.0f;
    m_kScreen._13 = 0.0f;
    m_kScreen._14 = 0.0f;
    m_kScreen._21 = 0.0f;
    m_kScreen._22 = -1.0f;
    m_kScreen._23 = 0.0f;
    m_kScreen._24 = 0.0f;
    m_kScreen._31 = 0.0f;
    m_kScreen._32 = 0.0f;
    m_kScreen._33 = 1.0f;
    m_kScreen._34 = 0.0f;
    m_kScreen._41 = 0.5f;
    m_kScreen._42 = 0.5f;
    m_kScreen._43 = -1.0f;
    m_kScreen._44 = 1.0f;

    m_pDirectInputDevice->SetTransform(2, &m_kView);

    NiPoint3_Custom_niconsolerenderer kPt(1.0f, 0.0f, 0.0f);
    m_kScreenRight = kPt;
    m_kCameraPosition = kPt;

    kPt = NiPoint3_Custom_niconsolerenderer(0.0f, -1.0f, 0.0f);
    m_kScreenUp = kPt;
    m_kCameraDirection = kPt;

    m_684 = 1.0f;
    m_688 = 9999.0f;

    m_kProj._11 = 2.0f;
    m_kProj._21 = 0.0f;
    m_kProj._31 = 0.0f;
    m_kProj._41 = -1.0 / m_fGlyphWidthInPixels;

    m_kProj._12 = 0.0f;
    m_kProj._32 = 0.0f;
    m_kProj._22 = 2.0f;
    m_kProj._42 = 1.0f / m_fGlyphExtent;

    m_kProj._13 = 0.0f;
    m_kProj._23 = 0.0f;
    m_kProj._33 = 1.0f / 9999.0f;
    m_kProj._43 = -1.0f / 9999.0f;

    m_kProj._14 = 0.0f;
    m_kProj._24 = 0.0f;
    m_kProj._34 = 0.0f;
    m_kProj._44 = 1.0f;

    m_pDirectInputDevice->SetTransform(3, &m_kProj);

    D3DVIEWPORT9_Custom kVP;
    if (pkRect)
    {
        kVP.X = (unsigned long)(pkRect->m_fMinimumU * m_fGlyphWidthInPixels);
        kVP.Y = (unsigned long)((1.0f - pkRect->m_fMinimumV) * m_fGlyphExtent);
        kVP.Width = (unsigned long)((pkRect->m_fMaximumU - pkRect->m_fMinimumU) * m_fGlyphWidthInPixels);
        kVP.Height = (unsigned long)((pkRect->m_fMinimumV - pkRect->m_fMaximumV) * m_fGlyphExtent);
    }
    else
    {
        kVP.X = 0;
        kVP.Y = 0;
        kVP.Width = uiWidth;
        kVP.Height = uiHeight;
    }
    kVP.MinZ = 0.0f;
    kVP.MaxZ = 1.0f;
    m_pDirectInputDevice->SetViewport(&kVP);

    m_pMgr->SetCameraRange(1.0f, 10000.0f);
}

extern "C" __declspec(dllimport) void __stdcall fnv_EnterCriticalSection(void*);

extern "C" __declspec(dllimport) void __stdcall fnv_LeaveCriticalSection(void*);

extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);



struct Item;

struct Node;

struct ArrayObj;



struct TargetObj {

    bool Invoke(FUN_00e744b0_Src* p);

};



// Exe 0x00e71e40: unit-local Map view; declarations and layout are preserved.
struct NiconsolerendererMapView {

    bool Get(void* key, Node*& outVal);

    void Set(void* key, Node* val);

    bool Remove(void* key);

};



struct E71E40 {

    unsigned int unk_000; unsigned int unk_004; unsigned int unk_008; unsigned int unk_00c; unsigned int unk_010; unsigned int unk_014; unsigned int unk_018; unsigned int unk_01c;

    unsigned int unk_020; unsigned int unk_024; unsigned int unk_028; unsigned int unk_02c; unsigned int unk_030; unsigned int unk_034; unsigned int unk_038; unsigned int unk_03c;

    unsigned int unk_040; unsigned int unk_044; unsigned int unk_048; unsigned int unk_04c; unsigned int unk_050; unsigned int unk_054; unsigned int unk_058; unsigned int unk_05c;

    unsigned int unk_060; unsigned int unk_064; unsigned int unk_068; unsigned int unk_06c; unsigned int unk_070; unsigned int unk_074; unsigned int unk_078; unsigned int unk_07c;

    unsigned int cs1_080; unsigned int cs1_084; unsigned int cs1_088; unsigned int cs1_08c; unsigned int cs1_090; unsigned int cs1_094; unsigned int cs1_098; unsigned int cs1_09c;

    unsigned int cs1_0a0; unsigned int cs1_0a4; unsigned int cs1_0a8; unsigned int cs1_0ac; unsigned int cs1_0b0; unsigned int cs1_0b4; unsigned int cs1_0b8; unsigned int cs1_0bc;

    unsigned int cs1_0c0; unsigned int cs1_0c4; unsigned int cs1_0c8; unsigned int cs1_0cc; unsigned int cs1_0d0; unsigned int cs1_0d4; unsigned int cs1_0d8; unsigned int cs1_0dc;

    unsigned int cs1_0e0; unsigned int cs1_0e4; unsigned int cs1_0e8; unsigned int cs1_0ec; unsigned int cs1_0f0; unsigned int cs1_0f4; unsigned int cs1_0f8; unsigned int cs1_0fc;

    unsigned int cs2_100; unsigned int cs2_104; unsigned int cs2_108; unsigned int cs2_10c; unsigned int cs2_110; unsigned int cs2_114; unsigned int cs2_118; unsigned int cs2_11c;

    unsigned int cs2_120; unsigned int cs2_124; unsigned int cs2_128; unsigned int cs2_12c; unsigned int cs2_130; unsigned int cs2_134; unsigned int cs2_138; unsigned int cs2_13c;

    unsigned int cs2_140; unsigned int cs2_144; unsigned int cs2_148; unsigned int cs2_14c; unsigned int cs2_150; unsigned int cs2_154; unsigned int cs2_158; unsigned int cs2_15c;

    unsigned int cs2_160; unsigned int cs2_164; unsigned int cs2_168; unsigned int cs2_16c; unsigned int cs2_170; unsigned int cs2_174; unsigned int cs2_178; unsigned int cs2_17c;

    unsigned int cs2_180; unsigned int cs2_184; unsigned int cs2_188; unsigned int cs2_18c; unsigned int cs2_190; unsigned int cs2_194; unsigned int cs2_198; unsigned int cs2_19c;

    unsigned int cs2_1a0; unsigned int cs2_1a4; unsigned int cs2_1a8; unsigned int cs2_1ac; unsigned int cs2_1b0; unsigned int cs2_1b4; unsigned int cs2_1b8; unsigned int cs2_1bc;

    unsigned int cs2_1c0; unsigned int cs2_1c4; unsigned int cs2_1c8; unsigned int cs2_1cc; unsigned int cs2_1d0; unsigned int cs2_1d4; unsigned int cs2_1d8; unsigned int cs2_1dc;

    unsigned int cs2_1e0; unsigned int cs2_1e4; unsigned int cs2_1e8; unsigned int cs2_1ec; unsigned int cs2_1f0; unsigned int cs2_1f4; unsigned int cs2_1f8; unsigned int cs2_1fc;

    unsigned int cs2_200; unsigned int cs2_204; unsigned int cs2_208; unsigned int cs2_20c; unsigned int cs2_210; unsigned int cs2_214; unsigned int cs2_218; unsigned int cs2_21c;

    unsigned int cs2_220; unsigned int cs2_224; unsigned int cs2_228; unsigned int cs2_22c; unsigned int cs2_230; unsigned int cs2_234; unsigned int cs2_238; unsigned int cs2_23c;

    unsigned int cs2_240; unsigned int cs2_244; unsigned int cs2_248; unsigned int cs2_24c; unsigned int cs2_250; unsigned int cs2_254; unsigned int cs2_258; unsigned int cs2_25c;

    unsigned int cs2_260; unsigned int cs2_264; unsigned int cs2_268; unsigned int cs2_26c; unsigned int cs2_270; unsigned int cs2_274; unsigned int cs2_278; unsigned int cs2_27c;

    unsigned int cs2_280; unsigned int cs2_284; unsigned int cs2_288; unsigned int cs2_28c; unsigned int cs2_290; unsigned int cs2_294; unsigned int cs2_298; unsigned int cs2_29c;

    unsigned int cs2_2a0; unsigned int cs2_2a4; unsigned int cs2_2a8; unsigned int cs2_2ac; unsigned int cs2_2b0; unsigned int cs2_2b4; unsigned int cs2_2b8; unsigned int cs2_2bc;

    unsigned int cs2_2c0; unsigned int cs2_2c4; unsigned int cs2_2c8; unsigned int cs2_2cc; unsigned int cs2_2d0; unsigned int cs2_2d4; unsigned int cs2_2d8; unsigned int cs2_2dc;

    unsigned int cs2_2e0; unsigned int cs2_2e4; unsigned int cs2_2e8; unsigned int cs2_2ec; unsigned int cs2_2f0; unsigned int cs2_2f4; unsigned int cs2_2f8; unsigned int cs2_2fc;

    unsigned int cs2_300; unsigned int cs2_304; unsigned int cs2_308; unsigned int cs2_30c; unsigned int cs2_310; unsigned int cs2_314; unsigned int cs2_318; unsigned int cs2_31c;

    unsigned int cs2_320; unsigned int cs2_324; unsigned int cs2_328; unsigned int cs2_32c; unsigned int cs2_330; unsigned int cs2_334; unsigned int cs2_338; unsigned int cs2_33c;

    unsigned int cs2_340; unsigned int cs2_344; unsigned int cs2_348; unsigned int cs2_34c; unsigned int cs2_350; unsigned int cs2_354; unsigned int cs2_358; unsigned int cs2_35c;

    unsigned int cs2_360; unsigned int cs2_364; unsigned int cs2_368; unsigned int cs2_36c; unsigned int cs2_370; unsigned int cs2_374; unsigned int cs2_378; unsigned int cs2_37c;

    unsigned int cs2_380; unsigned int cs2_384; unsigned int cs2_388; unsigned int cs2_38c; unsigned int cs2_390; unsigned int cs2_394; unsigned int cs2_398; unsigned int cs2_39c;

    unsigned int cs2_3a0; unsigned int cs2_3a4; unsigned int cs2_3a8; unsigned int cs2_3ac; unsigned int cs2_3b0; unsigned int cs2_3b4; unsigned int cs2_3b8; unsigned int cs2_3bc;

    unsigned int cs2_3c0; unsigned int cs2_3c4; unsigned int cs2_3c8; unsigned int cs2_3cc; unsigned int cs2_3d0; unsigned int cs2_3d4; unsigned int cs2_3d8; unsigned int cs2_3dc;

    unsigned int cs2_3e0; unsigned int cs2_3e4; unsigned int cs2_3e8; unsigned int cs2_3ec; unsigned int cs2_3f0; unsigned int cs2_3f4; unsigned int cs2_3f8; unsigned int cs2_3fc;

    unsigned int cs2_400; unsigned int cs2_404; unsigned int cs2_408; unsigned int cs2_40c; unsigned int cs2_410; unsigned int cs2_414; unsigned int cs2_418; unsigned int cs2_41c;

    unsigned int cs2_420; unsigned int cs2_424; unsigned int cs2_428; unsigned int cs2_42c; unsigned int cs2_430; unsigned int cs2_434; unsigned int cs2_438; unsigned int cs2_43c;

    unsigned int cs2_440; unsigned int cs2_444; unsigned int cs2_448; unsigned int cs2_44c; unsigned int cs2_450; unsigned int cs2_454; unsigned int cs2_458; unsigned int cs2_45c;

    unsigned int cs2_460; unsigned int cs2_464; unsigned int cs2_468; unsigned int cs2_46c; unsigned int cs2_470; unsigned int cs2_474; unsigned int cs2_478; unsigned int cs2_47c;

    unsigned int cs2_480; unsigned int cs2_484; unsigned int cs2_488; unsigned int cs2_48c; unsigned int cs2_490; unsigned int cs2_494; unsigned int cs2_498; unsigned int cs2_49c;

    unsigned int cs2_4a0; unsigned int cs2_4a4; unsigned int cs2_4a8; unsigned int cs2_4ac; unsigned int cs2_4b0; unsigned int cs2_4b4; unsigned int cs2_4b8; unsigned int cs2_4bc;

    unsigned int cs2_4c0; unsigned int cs2_4c4; unsigned int cs2_4c8; unsigned int cs2_4cc; unsigned int cs2_4d0; unsigned int cs2_4d4; unsigned int cs2_4d8; unsigned int cs2_4dc;

    unsigned int cs2_4e0; unsigned int cs2_4e4; unsigned int cs2_4e8; unsigned int cs2_4ec; unsigned int cs2_4f0; unsigned int cs2_4f4; unsigned int cs2_4f8; unsigned int cs2_4fc;

    unsigned int cs2_500; unsigned int cs2_504; unsigned int cs2_508; unsigned int cs2_50c; unsigned int cs2_510; unsigned int cs2_514; unsigned int cs2_518; unsigned int cs2_51c;

    unsigned int cs2_520; unsigned int cs2_524; unsigned int cs2_528; unsigned int cs2_52c; unsigned int cs2_530; unsigned int cs2_534; unsigned int cs2_538; unsigned int cs2_53c;

    unsigned int cs2_540; unsigned int cs2_544; unsigned int cs2_548; unsigned int cs2_54c; unsigned int cs2_550; unsigned int cs2_554; unsigned int cs2_558; unsigned int cs2_55c;

    unsigned int cs2_560; unsigned int cs2_564; unsigned int cs2_568; unsigned int cs2_56c; unsigned int cs2_570; unsigned int cs2_574; unsigned int cs2_578; unsigned int cs2_57c;

    unsigned int cs2_580; unsigned int cs2_584; unsigned int cs2_588; unsigned int cs2_58c; unsigned int cs2_590; unsigned int cs2_594; unsigned int cs2_598; unsigned int cs2_59c;

    unsigned int cs2_5a0; unsigned int cs2_5a4; unsigned int cs2_5a8; unsigned int cs2_5ac; unsigned int cs2_5b0; unsigned int cs2_5b4; unsigned int cs2_5b8; unsigned int cs2_5bc;

    unsigned int cs2_5c0; unsigned int cs2_5c4; unsigned int cs2_5c8; unsigned int cs2_5cc; unsigned int cs2_5d0; unsigned int cs2_5d4; unsigned int cs2_5d8; unsigned int cs2_5dc;

    unsigned int cs2_5e0; unsigned int cs2_5e4; unsigned int cs2_5e8; unsigned int cs2_5ec; unsigned int cs2_5f0; unsigned int cs2_5f4; unsigned int cs2_5f8; unsigned int cs2_5fc;

    unsigned int cs2_600; unsigned int cs2_604; unsigned int cs2_608; unsigned int cs2_60c;

    NiconsolerendererMapView m_map;

    unsigned int after_map_614; unsigned int after_map_618; unsigned int after_map_61c; unsigned int after_map_620; unsigned int after_map_624; unsigned int after_map_628; unsigned int after_map_62c; unsigned int after_map_630;

    unsigned int after_map_634; unsigned int after_map_638; unsigned int after_map_63c; unsigned int after_map_640; unsigned int after_map_644; unsigned int after_map_648; unsigned int after_map_64c; unsigned int after_map_650;

    unsigned int after_map_654; unsigned int after_map_658; unsigned int after_map_65c; unsigned int after_map_660; unsigned int after_map_664; unsigned int after_map_668; unsigned int after_map_66c; unsigned int after_map_670;

    unsigned int after_map_674; unsigned int after_map_678; unsigned int after_map_67c; unsigned int after_map_680; unsigned int after_map_684; unsigned int after_map_688; unsigned int after_map_68c; unsigned int after_map_690;

    unsigned int after_map_694; unsigned int after_map_698; unsigned int after_map_69c; unsigned int after_map_6a0; unsigned int after_map_6a4; unsigned int after_map_6a8; unsigned int after_map_6ac; unsigned int after_map_6b0;

    unsigned int after_map_6b4; unsigned int after_map_6b8; unsigned int after_map_6bc; unsigned int after_map_6c0; unsigned int after_map_6c4; unsigned int after_map_6c8; unsigned int after_map_6cc; unsigned int after_map_6d0;

    unsigned int after_map_6d4; unsigned int after_map_6d8; unsigned int after_map_6dc; unsigned int after_map_6e0; unsigned int after_map_6e4; unsigned int after_map_6e8; unsigned int after_map_6ec; unsigned int after_map_6f0;

    unsigned int after_map_6f4; unsigned int after_map_6f8; unsigned int after_map_6fc; unsigned int after_map_700; unsigned int after_map_704; unsigned int after_map_708; unsigned int after_map_70c; unsigned int after_map_710;

    unsigned int after_map_714; unsigned int after_map_718; unsigned int after_map_71c; unsigned int after_map_720; unsigned int after_map_724; unsigned int after_map_728; unsigned int after_map_72c; unsigned int after_map_730;

    unsigned int after_map_734; unsigned int after_map_738; unsigned int after_map_73c; unsigned int after_map_740; unsigned int after_map_744; unsigned int after_map_748; unsigned int after_map_74c; unsigned int after_map_750;

    unsigned int after_map_754; unsigned int after_map_758; unsigned int after_map_75c; unsigned int after_map_760; unsigned int after_map_764; unsigned int after_map_768; unsigned int after_map_76c; unsigned int after_map_770;

    unsigned int after_map_774; unsigned int after_map_778; unsigned int after_map_77c; unsigned int after_map_780; unsigned int after_map_784; unsigned int after_map_788; unsigned int after_map_78c; unsigned int after_map_790;

    unsigned int after_map_794; unsigned int after_map_798; unsigned int after_map_79c; unsigned int after_map_7a0; unsigned int after_map_7a4; unsigned int after_map_7a8; unsigned int after_map_7ac; unsigned int after_map_7b0;

    unsigned int after_map_7b4; unsigned int after_map_7b8; unsigned int after_map_7bc; unsigned int after_map_7c0; unsigned int after_map_7c4; unsigned int after_map_7c8; unsigned int after_map_7cc; unsigned int after_map_7d0;

    unsigned int after_map_7d4; unsigned int after_map_7d8; unsigned int after_map_7dc; unsigned int after_map_7e0; unsigned int after_map_7e4; unsigned int after_map_7e8; unsigned int after_map_7ec; unsigned int after_map_7f0;

    unsigned int after_map_7f4; unsigned int after_map_7f8; unsigned int after_map_7fc; unsigned int after_map_800; unsigned int after_map_804; unsigned int after_map_808; unsigned int after_map_80c; unsigned int after_map_810;

    unsigned int after_map_814; unsigned int after_map_818; unsigned int after_map_81c; unsigned int after_map_820; unsigned int after_map_824; unsigned int after_map_828; unsigned int after_map_82c; unsigned int after_map_830;

    unsigned int after_map_834; unsigned int after_map_838; unsigned int after_map_83c; unsigned int after_map_840; unsigned int after_map_844; unsigned int after_map_848; unsigned int after_map_84c; unsigned int after_map_850;

    unsigned int after_map_854; unsigned int after_map_858; unsigned int after_map_85c; unsigned int after_map_860; unsigned int after_map_864; unsigned int after_map_868; unsigned int after_map_86c; unsigned int after_map_870;

    unsigned int after_map_874; unsigned int after_map_878; unsigned int after_map_87c; unsigned int after_map_880; unsigned int after_map_884; unsigned int after_map_888; unsigned int after_map_88c; unsigned int after_map_890;

    unsigned int after_map_894; unsigned int after_map_898; unsigned int after_map_89c; unsigned int after_map_8a0; unsigned int after_map_8a4; unsigned int after_map_8a8;

    TargetObj* m_target;



    void RemoveItemsFromMap(FUN_00e744b0_Src* p);

};



struct ArrayEntry {

    unsigned int unk00;

    void* m_key;

};



struct ArrayObj {

    unsigned int arr_unk_000; unsigned int arr_unk_004; unsigned int arr_unk_008; unsigned int arr_unk_00c; unsigned int arr_unk_010; unsigned int arr_unk_014; unsigned int arr_unk_018; unsigned int arr_unk_01c;

    unsigned int m_iElementCount;

    unsigned int arr_unk_24;

    ArrayEntry** m_pBase;



    ArrayEntry* GetAt(unsigned int i) const {

        if (i < m_iElementCount)

            return m_pBase[i];

        return 0;

    }

};



struct Item {

    unsigned int item_unk_000; unsigned int item_unk_004; unsigned int item_unk_008; unsigned int item_unk_00c; unsigned int item_unk_010; unsigned int item_unk_014; unsigned int item_unk_018; unsigned int item_unk_01c;

    unsigned int item_unk_020; unsigned int item_unk_024;

    ArrayObj* m_ppData;

};



struct Node {

    unsigned int node_unk_000; unsigned int node_unk_004;

    Item* m_item;

    unsigned int node_mid_00c; unsigned int node_mid_010; unsigned int node_mid_014; unsigned int node_mid_018; unsigned int node_mid_01c;

    Node* m_next;



    static void operator delete(void* pvMem, unsigned int uiSize) {

        operator_delete_sized(pvMem, uiSize);

    }

};



// For each of p->unk08 items, removes nodes referencing it from m_map under critical sections, then calls m_target->Invoke(p).
// @fnv 0x00e71e40
void E71E40::RemoveItemsFromMap(FUN_00e744b0_Src* p) {

    if (!p) return;

    Item* items = (Item*)p->unk0c;

    if (!items || !items->m_ppData) return;

    if (p->unk08 > 0) {

        Item* item = items;

        unsigned int count = p->unk08;

        do {

            ArrayObj* pArray = item->m_ppData;

            if (pArray->m_iElementCount <= 0 || pArray->m_pBase[0] == 0) {

            } else {

                fnv_EnterCriticalSection(&cs1_080);

                fnv_EnterCriticalSection(&cs2_100);



                for (unsigned int i = 0; i < pArray->m_iElementCount; ++i) {

                    void* key = pArray->GetAt(i)->m_key;

                    Node* outNode = 0;

                    if (m_map.Get(key, outNode)) {

                        Node* curr = outNode;

                        Node* prev = 0;

                        while (curr) {

                            if (curr->m_item == item) {

                                Node* next = 0;

                                if (prev) {

                                    prev->m_next = curr->m_next;

                                    next = curr->m_next;

                                } else if (curr->m_next) {

                                    m_map.Set(key, static_cast<Node* const volatile&>(curr->m_next));

                                    next = curr->m_next;

                                } else {

                                    m_map.Remove(key);

                                }

                                curr->m_next = 0;

                                delete curr;

                                curr = next;

                            } else {

                                prev = curr;

                                curr = curr->m_next;

                            }

                        }

                    }

                }



                fnv_LeaveCriticalSection(&cs2_100);

                fnv_LeaveCriticalSection(&cs1_080);

            }

            item++;

        } while (--count);

    }



    m_target->Invoke(p);

}

extern "C" void* __cdecl memset(void*,int,unsigned int);

void* NiMalloc(unsigned int);
struct RendererBase {
 virtual void BaseVirtual();
 RendererBase() throw();
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 unsigned int unk07c;
 unsigned int unk080;
 unsigned int unk084;
 unsigned int unk088;
 unsigned int unk08c;
 unsigned int unk090;
 unsigned int unk094;
 unsigned int unk098;
 unsigned int unk09c;
 unsigned int unk0a0;
 unsigned int unk0a4;
 unsigned int unk0a8;
 unsigned int unk0ac;
 unsigned int unk0b0;
 unsigned int unk0b4;
 unsigned int unk0b8;
 unsigned int unk0bc;
 unsigned int unk0c0;
 unsigned int unk0c4;
 unsigned int unk0c8;
 unsigned int unk0cc;
 unsigned int unk0d0;
 unsigned int unk0d4;
 unsigned int unk0d8;
 unsigned int unk0dc;
 unsigned int unk0e0;
 unsigned int unk0e4;
 unsigned int unk0e8;
 unsigned int unk0ec;
 unsigned int unk0f0;
 unsigned int unk0f4;
 unsigned int unk0f8;
 unsigned int unk0fc;
 unsigned int unk100;
 unsigned int unk104;
 unsigned int unk108;
 unsigned int unk10c;
 unsigned int unk110;
 unsigned int unk114;
 unsigned int unk118;
 unsigned int unk11c;
 unsigned int unk120;
 unsigned int unk124;
 unsigned int unk128;
 unsigned int unk12c;
 unsigned int unk130;
 unsigned int unk134;
 unsigned int unk138;
 unsigned int unk13c;
 unsigned int unk140;
 unsigned int unk144;
 unsigned int unk148;
 unsigned int unk14c;
 unsigned int unk150;
 unsigned int unk154;
 unsigned int unk158;
 unsigned int unk15c;
 unsigned int unk160;
 unsigned int unk164;
 unsigned int unk168;
 unsigned int unk16c;
 unsigned int unk170;
 unsigned int unk174;
 unsigned int unk178;
 unsigned int unk17c;
 unsigned int unk180;
 unsigned int unk184;
 unsigned int unk188;
 unsigned int unk18c;
 unsigned int unk190;
 unsigned int unk194;
 unsigned int unk198;
 unsigned int unk19c;
 unsigned int unk1a0;
 unsigned int unk1a4;
 unsigned int unk1a8;
 unsigned int unk1ac;
 unsigned int unk1b0;
 unsigned int unk1b4;
 unsigned int unk1b8;
 unsigned int unk1bc;
 unsigned int unk1c0;
 unsigned int unk1c4;
 unsigned int unk1c8;
 unsigned int unk1cc;
 unsigned int unk1d0;
 unsigned int unk1d4;
 unsigned int unk1d8;
 unsigned int unk1dc;
 unsigned int unk1e0;
 unsigned int unk1e4;
 unsigned int unk1e8;
 unsigned int unk1ec;
 unsigned int unk1f0;
 unsigned int unk1f4;
 unsigned int unk1f8;
 unsigned int unk1fc;
 unsigned int unk200;
 unsigned int unk204;
 unsigned int unk208;
 unsigned int unk20c;
 unsigned int unk210;
 unsigned int unk214;
 unsigned int unk218;
 unsigned int unk21c;
 unsigned int unk220;
 unsigned int unk224;
 unsigned int unk228;
 unsigned int unk22c;
 unsigned int unk230;
 unsigned int unk234;
 unsigned int unk238;
 unsigned int unk23c;
 unsigned int unk240;
 unsigned int unk244;
 unsigned int unk248;
 unsigned int unk24c;
 unsigned int unk250;
 unsigned int unk254;
 unsigned int unk258;
 unsigned int unk25c;
 unsigned int unk260;
 unsigned int unk264;
 unsigned int unk268;
 unsigned int unk26c;
 unsigned int unk270;
 unsigned int unk274;
 unsigned int unk278;
 unsigned int unk27c;
 unsigned int unk280;
 unsigned int unk284;
 unsigned int unk288;
 unsigned int unk28c;
 unsigned int unk290;
 unsigned int unk294;
 unsigned int unk298;
 unsigned int unk29c;
 unsigned int unk2a0;
 unsigned int unk2a4;
 unsigned int unk2a8;
 unsigned int unk2ac;
 unsigned int unk2b0;
 unsigned int unk2b4;
 unsigned int unk2b8;
 unsigned int unk2bc;
 unsigned int unk2c0;
 unsigned int unk2c4;
 unsigned int unk2c8;
 unsigned int unk2cc;
 unsigned int unk2d0;
 unsigned int unk2d4;
 unsigned int unk2d8;
 unsigned int unk2dc;
 unsigned int unk2e0;
 unsigned int unk2e4;
 unsigned int unk2e8;
 unsigned int unk2ec;
 unsigned int unk2f0;
 unsigned int unk2f4;
 unsigned int unk2f8;
 unsigned int unk2fc;
 unsigned int unk300;
 unsigned int unk304;
 unsigned int unk308;
 unsigned int unk30c;
 unsigned int unk310;
 unsigned int unk314;
 unsigned int unk318;
 unsigned int unk31c;
 unsigned int unk320;
 unsigned int unk324;
 unsigned int unk328;
 unsigned int unk32c;
 unsigned int unk330;
 unsigned int unk334;
 unsigned int unk338;
 unsigned int unk33c;
 unsigned int unk340;
 unsigned int unk344;
 unsigned int unk348;
 unsigned int unk34c;
 unsigned int unk350;
 unsigned int unk354;
 unsigned int unk358;
 unsigned int unk35c;
 unsigned int unk360;
 unsigned int unk364;
 unsigned int unk368;
 unsigned int unk36c;
 unsigned int unk370;
 unsigned int unk374;
 unsigned int unk378;
 unsigned int unk37c;
 unsigned int unk380;
 unsigned int unk384;
 unsigned int unk388;
 unsigned int unk38c;
 unsigned int unk390;
 unsigned int unk394;
 unsigned int unk398;
 unsigned int unk39c;
 unsigned int unk3a0;
 unsigned int unk3a4;
 unsigned int unk3a8;
 unsigned int unk3ac;
 unsigned int unk3b0;
 unsigned int unk3b4;
 unsigned int unk3b8;
 unsigned int unk3bc;
 unsigned int unk3c0;
 unsigned int unk3c4;
 unsigned int unk3c8;
 unsigned int unk3cc;
 unsigned int unk3d0;
 unsigned int unk3d4;
 unsigned int unk3d8;
 unsigned int unk3dc;
 unsigned int unk3e0;
 unsigned int unk3e4;
 unsigned int unk3e8;
 unsigned int unk3ec;
 unsigned int unk3f0;
 unsigned int unk3f4;
 unsigned int unk3f8;
 unsigned int unk3fc;
 unsigned int unk400;
 unsigned int unk404;
 unsigned int unk408;
 unsigned int unk40c;
 unsigned int unk410;
 unsigned int unk414;
 unsigned int unk418;
 unsigned int unk41c;
 unsigned int unk420;
 unsigned int unk424;
 unsigned int unk428;
 unsigned int unk42c;
 unsigned int unk430;
 unsigned int unk434;
 unsigned int unk438;
 unsigned int unk43c;
 unsigned int unk440;
 unsigned int unk444;
 unsigned int unk448;
 unsigned int unk44c;
 unsigned int unk450;
 unsigned int unk454;
 unsigned int unk458;
 unsigned int unk45c;
 unsigned int unk460;
 unsigned int unk464;
 unsigned int unk468;
 unsigned int unk46c;
 unsigned int unk470;
 unsigned int unk474;
 unsigned int unk478;
 unsigned int unk47c;
 unsigned int unk480;
 unsigned int unk484;
 unsigned int unk488;
 unsigned int unk48c;
 unsigned int unk490;
 unsigned int unk494;
 unsigned int unk498;
 unsigned int unk49c;
 unsigned int unk4a0;
 unsigned int unk4a4;
 unsigned int unk4a8;
 unsigned int unk4ac;
 unsigned int unk4b0;
 unsigned int unk4b4;
 unsigned int unk4b8;
 unsigned int unk4bc;
 unsigned int unk4c0;
 unsigned int unk4c4;
 unsigned int unk4c8;
 unsigned int unk4cc;
 unsigned int unk4d0;
 unsigned int unk4d4;
 unsigned int unk4d8;
 unsigned int unk4dc;
 unsigned int unk4e0;
 unsigned int unk4e4;
 unsigned int unk4e8;
 unsigned int unk4ec;
 unsigned int unk4f0;
 unsigned int unk4f4;
 unsigned int unk4f8;
 unsigned int unk4fc;
 unsigned int unk500;
 unsigned int unk504;
 unsigned int unk508;
 unsigned int unk50c;
 unsigned int unk510;
 unsigned int unk514;
 unsigned int unk518;
 unsigned int unk51c;
 unsigned int unk520;
 unsigned int unk524;
 unsigned int unk528;
 unsigned int unk52c;
 unsigned int unk530;
 unsigned int unk534;
 unsigned int unk538;
 unsigned int unk53c;
 unsigned int unk540;
 unsigned int unk544;
 unsigned int unk548;
 unsigned int unk54c;
 unsigned int unk550;
 unsigned int unk554;
 unsigned int unk558;
 unsigned int unk55c;
 unsigned int unk560;
 unsigned int unk564;
 unsigned int unk568;
 unsigned int unk56c;
 unsigned int unk570;
 unsigned int unk574;
 unsigned int unk578;
 unsigned int unk57c;
 unsigned int unk580;
 unsigned int unk584;
 unsigned int unk588;
 unsigned int unk58c;
 unsigned int unk590;
 unsigned int unk594;
 unsigned int unk598;
 unsigned int unk59c;
 unsigned int unk5a0;
 unsigned int unk5a4;
 unsigned int unk5a8;
 unsigned int unk5ac;
 unsigned int unk5b0;
 unsigned int unk5b4;
 unsigned int unk5b8;
 unsigned int unk5bc;
 unsigned int unk5c0;
 unsigned int unk5c4;
 unsigned int unk5c8;
 unsigned int unk5cc;
 unsigned int unk5d0;
 unsigned int unk5d4;
 unsigned int unk5d8;
 unsigned int unk5dc;
 unsigned int unk5e0;
 unsigned int unk5e4;
 unsigned int unk5e8;
 unsigned int unk5ec;
 unsigned int unk5f0;
 unsigned int unk5f4;
 unsigned int unk5f8;
 unsigned int unk5fc;
 unsigned int unk600;
 unsigned int unk604;
 unsigned int unk608;
 unsigned int unk60c;
};
// The pre-pack map still needs NiDX9Renderer::PrePackObject from the shared renderer header.
struct PrePackMapBase {
 virtual void MapVirtual();
 unsigned int bucketCount; void* buckets; unsigned int itemCount;
 PrePackMapBase(unsigned int n) throw() : bucketCount(n), itemCount(0) {
  buckets=NiMalloc(n*4);
  _fnv_zlib_memset(buckets,0,bucketCount*4);
 }
};
struct PrePackMap : PrePackMapBase {
 virtual void MapVirtual();
 PrePackMap(unsigned int n=37) throw() : PrePackMapBase(n) {}
};

template<class Alloc, class Key, class Value>
inline NiTMapBase<Alloc, Key, Value>::NiTMapBase(unsigned int n)
    : m_uiHashSize(n)
{
 m_kItemCount.m_uiCount = 0;
 m_ppkHashTable = static_cast<NiTMapItem<Key, Value>**>(NiMalloc(n * 4));
 _fnv_zlib_memset(m_ppkHashTable, 0, m_uiHashSize * 4);
}
template<class Key, class Value>
inline NiTPointerMap<Key, Value>::NiTPointerMap(unsigned int n)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, Key, Value>(n) {}
template<class Key, class Value>
inline NiTMap<Key, Value>::NiTMap(unsigned int n)
    : NiTMapBase<DFALL<NiTMapItem<Key, Value> >, Key, Value>(n) {}
struct FourZeros { unsigned int a,b,c,d; FourZeros() throw() { memset(this,0,sizeof(*this)); } };
struct ListRegion {
 unsigned int unk8fc;
 unsigned int unk900;
 unsigned int unk904;
 unsigned int unk908;
 unsigned int unk90c;
 unsigned int unk910;
 unsigned int unk914;
 unsigned int unk918;
 unsigned int unk91c;
 unsigned int unk920;
 unsigned int unk924;
 unsigned int unk928;
 unsigned int unk92c;
 unsigned int unk930;
 unsigned int unk934;
 unsigned int unk938;
 unsigned int unk93c;
 ListRegion() throw() {
  unk8fc=0;
  unk908=0;
  unk900=0;
  unk904=0;
  unk914=0;
  unk90c=0;
  unk910=0;
  unk918=0;
  unk91c=0;
  unk920=0;
  unk924=0;
  unk928=0;
  unk92c=0;
  unk930=0;
  unk934=0;
  unk938=0;
  unk93c=0;
 }
};
template<int Tag> struct RendererArrayBase {
 virtual void ArrayVirtual();
 void* data; unsigned short capacity,effective,size,grow;
 RendererArrayBase(unsigned short initial=0,unsigned short increment=1) throw() : capacity(initial),grow(increment) { effective=0; size=0; data=0; }
};
template<int Tag> struct RendererArray : RendererArrayBase<Tag> {
 virtual void ArrayVirtual();
 RendererArray(unsigned short initial=0,unsigned short increment=1) throw() : RendererArrayBase<Tag>(initial,increment) {  }
};
struct FUN_00e754a0 : RendererBase {
 virtual void BaseVirtual();
 PrePackMap map610;
 unsigned int unk620;
 unsigned int unk624;
 unsigned int unk628;
 unsigned int unk62c;
 unsigned int unk630;
 unsigned int unk634;
 unsigned int unk638;
 unsigned int unk63c;
 unsigned int unk640;
 unsigned int unk644;
 unsigned int unk648;
 unsigned int unk64c;
 unsigned int unk650;
 unsigned int unk654;
 unsigned int unk658;
 unsigned int unk65c;
 unsigned int unk660;
 unsigned int unk664;
 unsigned int unk668;
 unsigned int unk66c;
 unsigned int unk670;
 unsigned int unk674;
 unsigned int unk678;
 unsigned int unk67c;
 unsigned int unk680;
 unsigned int unk684;
 unsigned int unk688;
 unsigned int unk68c;
 unsigned int unk690;
 unsigned int unk694;
 unsigned int unk698;
 unsigned int unk69c;
 unsigned int unk6a0;
 unsigned int unk6a4;
 unsigned int unk6a8;
 unsigned int unk6ac;
 unsigned int unk6b0;
 unsigned int unk6b4;
 unsigned int unk6b8;
 unsigned int unk6bc;
 unsigned int unk6c0;
 unsigned int unk6c4;
 unsigned int unk6c8;
 unsigned int unk6cc;
 unsigned int unk6d0;
 unsigned int unk6d4;
 unsigned int unk6d8;
 unsigned int unk6dc;
 unsigned int unk6e0;
 unsigned int unk6e4;
 unsigned int unk6e8;
 unsigned int unk6ec;
 unsigned int unk6f0;
 unsigned int unk6f4;
 unsigned int unk6f8;
 unsigned int unk6fc;
 unsigned int unk700;
 unsigned int unk704;
 unsigned int unk708;
 unsigned int unk70c;
 unsigned int unk710;
 unsigned int unk714;
 unsigned int unk718;
 unsigned int unk71c;
 unsigned int unk720;
 unsigned int unk724;
 unsigned int unk728;
 unsigned int unk72c;
 unsigned int unk730;
 unsigned int unk734;
 unsigned int unk738;
 unsigned int unk73c;
 unsigned int unk740;
 unsigned int unk744;
 unsigned int unk748;
 unsigned int unk74c;
 unsigned int unk750;
 unsigned int unk754;
 unsigned int unk758;
 unsigned int unk75c;
 unsigned int unk760;
 unsigned int unk764;
 unsigned int unk768;
 unsigned int unk76c;
 unsigned int unk770;
 unsigned int unk774;
 unsigned int unk778;
 unsigned int unk77c;
 unsigned int unk780;
 unsigned int unk784;
 unsigned int unk788;
 unsigned int unk78c;
 unsigned int unk790;
 unsigned int unk794;
 unsigned int unk798;
 unsigned int unk79c;
 unsigned int unk7a0;
 unsigned int unk7a4;
 unsigned int unk7a8;
 unsigned int unk7ac;
 unsigned int unk7b0;
 unsigned int unk7b4;
 unsigned int unk7b8;
 unsigned int unk7bc;
 unsigned int unk7c0;
 unsigned int unk7c4;
 unsigned int unk7c8;
 unsigned int unk7cc;
 unsigned int unk7d0;
 unsigned int unk7d4;
 unsigned int unk7d8;
 unsigned int unk7dc;
 unsigned int unk7e0;
 unsigned int unk7e4;
 unsigned int unk7e8;
 unsigned int unk7ec;
 unsigned int unk7f0;
 unsigned int unk7f4;
 unsigned int unk7f8;
 unsigned int unk7fc;
 unsigned int unk800;
 unsigned int unk804;
 unsigned int unk808;
 unsigned int unk80c;
 unsigned int unk810;
 unsigned int unk814;
 unsigned int unk818;
 unsigned int unk81c;
 unsigned int unk820;
 unsigned int unk824;
 unsigned int unk828;
 unsigned int unk82c;
 unsigned int unk830;
 unsigned int unk834;
 unsigned int unk838;
 unsigned int unk83c;
 unsigned int unk840;
 unsigned int unk844;
 unsigned int unk848;
 unsigned int unk84c;
 unsigned int unk850;
 unsigned int unk854;
 unsigned int unk858;
 unsigned int unk85c;
 unsigned int unk860;
 unsigned int unk864;
 unsigned int unk868;
 unsigned int unk86c;
 FourZeros zeros870;
 unsigned int unk880;
 unsigned int unk884;
 unsigned int unk888;
 unsigned int unk88c;
 NiTPointerMap<HWND__*, NiPointer<NiRenderTargetGroup> > map890;
 unsigned int unk8a0;
 unsigned int unk8a4;
 unsigned int unk8a8;
 unsigned int unk8ac;
 unsigned int unk8b0;
 unsigned int unk8b4;
 unsigned int unk8b8;
 unsigned int unk8bc;
 unsigned int unk8c0;
 unsigned int unk8c4;
 unsigned int unk8c8;
 NiTPointerMap<NiRenderedTexture*, NiDX9RenderedTextureData*> map8cc;
 NiTPointerMap<NiRenderedCubeMap*, NiDX9RenderedCubeMapData*> map8dc;
 NiTPointerMap<NiDynamicTexture*, NiDX9DynamicTextureData*> map8ec;
 ListRegion lists;
 unsigned int unk940;
 unsigned int unk944;
 unsigned int unk948;
 unsigned int unk94c;
 unsigned int unk950;
 unsigned int unk954;
 unsigned int unk958;
 unsigned int unk95c;
 unsigned int unk960;
 unsigned int unk964;
 unsigned int unk968;
 unsigned int unk96c;
 unsigned int unk970;
 unsigned int unk974;
 unsigned int unk978;
 unsigned int unk97c;
 unsigned int unk980;
 unsigned int unk984;
 unsigned int unk988;
 unsigned int unk98c;
 unsigned int unk990;
 unsigned int unk994;
 unsigned int unk998;
 unsigned int unk99c;
 unsigned int unk9a0;
 unsigned int unk9a4;
 unsigned int unk9a8;
 unsigned int unk9ac;
 unsigned int unk9b0;
 unsigned int unk9b4;
 unsigned int unk9b8;
 unsigned int unk9bc;
 unsigned int unk9c0;
 unsigned int unk9c4;
 unsigned int unk9c8;
 unsigned int unk9cc;
 unsigned int unk9d0;
 unsigned int unk9d4;
 unsigned int unk9d8;
 unsigned int unk9dc;
 unsigned int unk9e0;
 unsigned int unk9e4;
 unsigned int unk9e8;
 unsigned int unk9ec;
 unsigned int unk9f0;
 unsigned int unk9f4;
 unsigned int unk9f8;
 unsigned int unk9fc;
 unsigned int unka00;
 unsigned int unka04;
 unsigned int unka08;
 unsigned int unka0c;
 unsigned int unka10;
 unsigned int unka14;
 unsigned int unka18;
 unsigned int unka1c;
 unsigned int unka20;
 unsigned int unka24;
 unsigned int unka28;
 unsigned int unka2c;
 unsigned int unka30;
 unsigned int unka34;
 unsigned int unka38;
 unsigned int unka3c;
 unsigned int unka40;
 unsigned int unka44;
 unsigned int unka48;
 unsigned int unka4c;
 unsigned int unka50;
 unsigned int unka54;
 unsigned int unka58;
 unsigned int unka5c;
 unsigned int unka60;
 unsigned int unka64;
 unsigned int unka68;
 unsigned int unka6c;
 unsigned int unka70;
 unsigned int unka74;
 unsigned int unka78;
 unsigned int unka7c;
 unsigned int unka80;
 unsigned int unka84;
 unsigned int unka88;
 unsigned int unka8c;
 unsigned int unka90;
 unsigned int unka94;
 unsigned int unka98;
 unsigned int unka9c;
 unsigned int unkaa0;
 unsigned int unkaa4;
 unsigned int unkaa8;
 unsigned int unkaac;
 unsigned int unkab0;
 unsigned int unkab4;
 unsigned int unkab8;
 unsigned int unkabc;
 unsigned int unkac0;
 unsigned int unkac4;
 unsigned int unkac8;
 unsigned int unkacc;
 unsigned int unkad0;
 RendererArray<0> arrayad4;
 RendererArray<1> arrayae4;
 RendererArray<2> arrayaf4;
 RendererArray<1> arrayb04;
 NiTMap<_D3DFORMAT, NiPixelFormat*> mapb14;
 void NiXenonRenderer_InitToDefault();
 FUN_00e754a0() throw();
};
// @fnv 0x00e754a0
FUN_00e754a0::FUN_00e754a0() throw() : unk630(0), mapb14(7) {
 NiXenonRenderer_InitToDefault();
}

extern double DAT_010231e8;
struct FUN_00e759c0_cls {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned char unk5e0;
    unsigned char unk5e1;
    unsigned char unk5e2;
    unsigned char unk5e3;
    void NiDX9Renderer_GetBackgroundColor(float* out);
};
// @fnv 0x00e759c0
// src: COMMUNITY 0x00e759c0
void FUN_00e759c0_cls::NiDX9Renderer_GetBackgroundColor(float* out) {
    double k = 1.0f / 255.0f;
    out[3] = (float)(k * unk5e3);
    out[0] = (float)(k * unk5e2);
    out[1] = (float)(k * unk5e1);
    int blue=unk5e0; const int& value=blue; out[2]=(float)(k*value);
}

// @fnv 0x00e79540
unsigned int __cdecl ConvertNormalizedShortsToFloats(NormalizedStream* pStream)
{
    unsigned int uiBytesWritten = 0;
    unsigned char* pucSrc = pStream->source;
    unsigned short* pusRemap = pStream->indices;
    unsigned char* pucDest = pStream->dest;
    if (!pucSrc) {
        for (unsigned short i = 0; i < pStream->vertices; i++) {
            _fnv_zlib_memset(pucDest, 0, pStream->elementSize);
            pucDest += pStream->destStride;
            uiBytesWritten += pStream->elementSize;
        }
        return uiBytesWritten;
    }
    unsigned short usSrcComps = pStream->type - 12;
    unsigned short usDestComps = pStream->lastComponent + 1;
    unsigned short usComps = (usSrcComps > usDestComps) ? usDestComps : usSrcComps;
    if (pusRemap) {
        unsigned short usIndex = 0;
        for (unsigned short i = 0; i < pStream->vertices; i++) {
            const short* psSrc = (const short*)(pucSrc + pusRemap[usIndex++] * pStream->sourceStride);
            float* pfDest = (float*)pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++) {
                float f = (float)(*psSrc / 32767.0);
                *pfDest++ = (f < -1.0f) ? -1.0f : f;
                psSrc++;
            }
            for (; j < usDestComps; j++)
                *pfDest++ = 0.0f;
            pucDest += pStream->destStride;
            uiBytesWritten += pStream->elementSize;
        }
    } else {
        for (unsigned short i = 0; i < pStream->vertices; i++) {
            const short* psSrc = (const short*)pucSrc;
            float* pfDest = (float*)pucDest;
            unsigned short j;
            for (j = 0; j < usComps; j++) {
                float f = (float)(*psSrc / 32767.0);
                *pfDest++ = (f < -1.0f) ? -1.0f : f;
                psSrc++;
            }
            for (; j < usDestComps; j++)
                *pfDest++ = 0.0f;
            pucSrc += pStream->sourceStride;
            pucDest += pStream->destStride;
            uiBytesWritten += pStream->elementSize;
        }
    }
    return uiBytesWritten;
}

struct E6F310Rect {
    int x1;
    int y1;
    int x2;
    int y2;
};
struct FUN_00e7cdf0_shell {
    unsigned char NiDX9DepthStencilBufferData_HasValidDepthBuffer();
    unsigned char NiDX9DepthStencilBufferData_HasValidStencilBuffer();
};
struct E6F310Info {
    FUN_00e7cdf0_shell* ContainsNode(const NiRTTI* pkList);
};
struct E6F310Target {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual unsigned int GetWidth(unsigned int);
    virtual unsigned int GetHeight(unsigned int);
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual E6F310Info* GetInfo();
};
struct E6F310Device {
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
    virtual void __stdcall v03();
    virtual void __stdcall v04();
    virtual void __stdcall v05();
    virtual void __stdcall v06();
    virtual void __stdcall v07();
    virtual void __stdcall v08();
    virtual void __stdcall v09();
    virtual void __stdcall v10();
    virtual void __stdcall v11();
    virtual void __stdcall v12();
    virtual void __stdcall v13();
    virtual void __stdcall v14();
    virtual void __stdcall v15();
    virtual void __stdcall v16();
    virtual void __stdcall v17();
    virtual void __stdcall v18();
    virtual void __stdcall v19();
    virtual void __stdcall v20();
    virtual void __stdcall v21();
    virtual void __stdcall v22();
    virtual void __stdcall v23();
    virtual void __stdcall v24();
    virtual void __stdcall v25();
    virtual void __stdcall v26();
    virtual void __stdcall v27();
    virtual void __stdcall v28();
    virtual void __stdcall v29();
    virtual void __stdcall v30();
    virtual void __stdcall v31();
    virtual void __stdcall v32();
    virtual void __stdcall v33();
    virtual void __stdcall v34();
    virtual void __stdcall v35();
    virtual void __stdcall v36();
    virtual void __stdcall v37();
    virtual void __stdcall v38();
    virtual void __stdcall v39();
    virtual void __stdcall v40();
    virtual void __stdcall v41();
    virtual void __stdcall v42();
    virtual long __stdcall Clear(unsigned long, const E6F310Rect*, unsigned long, unsigned long, float, unsigned long);
    virtual void __stdcall v44();
    virtual void __stdcall v45();
    virtual void __stdcall v46();
    virtual long __stdcall SetViewport(const void*);
};
struct E6F310Renderer {
    void NiDX9Renderer_Clear(NiRectF_niconsolerenderer* pkRect, unsigned int uiFlags);
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    E6F310Device* m_pkDevice;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    unsigned long m_ulClearColor;
    float m_fClearDepth;
    unsigned long m_ulClearStencil;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    unsigned int m_uiVpWidth;
    unsigned int m_uiVpHeight;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    unsigned char m_bSkip;
    unsigned char unk6FD;
    unsigned char unk6FE;
    unsigned char unk6FF;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    E6F310Target* m_pkTarget;
};
// @fnv 0x00e6f310
// src: COMMUNITY 0x00e6f310
void E6F310Renderer::NiDX9Renderer_Clear(NiRectF_niconsolerenderer* pkRect, unsigned int uiFlags)
{
    if (!uiFlags || m_bSkip || !m_pkTarget)
        return;
    unsigned int uiWidth = m_pkTarget->GetWidth(0);
    unsigned int uiHeight = m_pkTarget->GetHeight(0);
    E6F310Rect pDataToSerialize;
    if (pkRect) {
        float m_fGlyphWidthInPixels = (float)uiWidth;
        float m_fGlyphExtent = (float)uiHeight;
        pDataToSerialize.x1 = (int)(pkRect->m_fMinimumU * m_fGlyphWidthInPixels);
        pDataToSerialize.y1 = (int)((1.0f - pkRect->m_fMinimumV) * m_fGlyphExtent);
        pDataToSerialize.x2 = (int)(pkRect->m_fMaximumU * m_fGlyphWidthInPixels);
        pDataToSerialize.y2 = (int)((1.0f - pkRect->m_fMaximumV) * m_fGlyphExtent);
    } else {
        pDataToSerialize.x1 = 0;
        pDataToSerialize.y1 = 0;
        pDataToSerialize.x2 = uiWidth;
        pDataToSerialize.y2 = uiHeight;
    }
    unsigned long ulClearFlags = uiFlags & 1;
    E6F310Info* pkInfo = m_pkTarget->GetInfo();
    if (pkInfo) {
        FUN_00e7cdf0_shell* pkCaps = pkInfo->ContainsNode(&g_0126f5ac);
        if (pkCaps) {
            ulClearFlags |= ((uiFlags & 4) && pkCaps->NiDX9DepthStencilBufferData_HasValidDepthBuffer()) ? 2 : 0;
            ulClearFlags |= ((uiFlags & 2) && pkCaps->NiDX9DepthStencilBufferData_HasValidStencilBuffer()) ? 4 : 0;
        }
    }
    m_uiVpWidth = m_pkTarget->GetWidth(0);
    m_uiVpHeight = m_pkTarget->GetHeight(0);
    m_pkDevice->SetViewport(&unk6CC);
    m_pkDevice->Clear(1, &pDataToSerialize, ulClearFlags, m_ulClearColor, m_fClearDepth, m_ulClearStencil);
}

class NiRTTI;
bool __cdecl NiObject_IsKindOf(const NiRTTI* type, NiAVObject* obj);
extern const NiRTTI g_011f4a88;
extern const NiRTTI g_011f4a70;

struct PacketTarget { int unk00; int unk04; void* unk08; void Release(); };

struct PacketObj {
    int unk00; int unk04;
    unsigned short unk08; unsigned short unk0a; unsigned short unk0c; unsigned short unk0e;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34;
    unsigned char flags38; unsigned char unk39; unsigned char unk3a; unsigned char unk3b;
    int unk3c;
    unsigned short unk40; unsigned short unk42;
    unsigned short unk44; unsigned short unk46;
    int unk48;
    void SetPacket(unsigned int, int, int, int, int, int, unsigned int);
    void SetA(unsigned short, unsigned short*);
    void SetB(unsigned short, int, int);
};

// @fnv 0x00e6fa90
void __stdcall ApplyPacketUpdate(PacketObj* pPacketObj, PacketTarget* target, int bRelease)
{
    if (!pPacketObj || (pPacketObj->unk0e & 0x7000) != 0x4000)
        return;
    unsigned int id = pPacketObj->unk08;
    unsigned int mask = pPacketObj->flags38;
    if (!mask) {
        pPacketObj->SetPacket(id, 0, 0, 0, 0, 0, pPacketObj->unk0c & 0xf000);
    } else {
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        if (mask & 1) a = pPacketObj->unk20;
        if (mask & 2) b = pPacketObj->unk24;
        if (mask & 4) c = pPacketObj->unk28;
        if (mask & 8) {
            e = pPacketObj->unk0c & 1;
            d = pPacketObj->unk2c;
        }
        pPacketObj->SetPacket(id, a, b, c, d, e, pPacketObj->unk0c & 0xf000);
    }
    if (bRelease) {
        if (!(mask & 0x20))
            ((PacketTarget*)target->unk08)->Release();
    } else if (!(mask & 0x10)) {
        if (NiObject_IsKindOf(&g_011f4a88, (NiAVObject*)pPacketObj))
            pPacketObj->SetA(pPacketObj->unk40, 0);
        else if (NiObject_IsKindOf(&g_011f4a70, (NiAVObject*)pPacketObj))
            pPacketObj->SetB(pPacketObj->unk44, pPacketObj->unk48, 0);
    }
}

struct GeomGroupEntry;

struct GeomGroupLink {
    GeomGroupEntry* pkEntry;
};

struct GeomGroupEntry {
    void* pkGeometry;
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    GeomGroupLink kNext;
};

struct GeomGroupMap {
    int unk00;
    bool Lookup(unsigned int key, GeomGroupEntry*& val) const;
    void Assign(unsigned int key, GeomGroupLink val);
    bool Remove(unsigned int key);
};

struct GeomPartition {
    int unk00;
    unsigned int uiKey;
};

struct GeomPartitionArray {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    unsigned int uiSize;
    int unk24;
    GeomPartition** ppkArray;

    GeomPartition* Get(unsigned int i) const { return i < uiSize ? ppkArray[i] : 0; }
};

struct GeomData {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30;
    GeomPartitionArray* pkPartitions;
};

struct GeomListener {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void Release(GeomData* pkGeom, int iFlag);
};

struct RendererLock { int unk00; };

void __cdecl NiFreeSized(void* p, unsigned int size);

struct GeomGroupOwner {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    RendererLock kLockA;
    int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0;
    int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0;
    int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0;
    int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    RendererLock kLockB;
    int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120;
    int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140;
    int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160;
    int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180;
    int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0;
    int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0;
    int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0;
    int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200;
    int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c; int unk220;
    int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c; int unk240;
    int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c; int unk260;
    int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c; int unk280;
    int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c; int unk2a0;
    int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc; int unk2c0;
    int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc; int unk2e0;
    int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc; int unk300;
    int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c; int unk320;
    int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c; int unk340;
    int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c; int unk360;
    int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c; int unk380;
    int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c; int unk3a0;
    int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc; int unk3c0;
    int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc; int unk3e0;
    int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc; int unk400;
    int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c; int unk420;
    int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c; int unk440;
    int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c; int unk460;
    int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c; int unk480;
    int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c; int unk4a0;
    int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc; int unk4c0;
    int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc; int unk4e0;
    int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc; int unk500;
    int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c; int unk520;
    int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c; int unk540;
    int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c; int unk560;
    int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c; int unk580;
    int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c; int unk5a0;
    int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc; int unk5c0;
    int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc; int unk5e0;
    int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc; int unk600;
    int unk604; int unk608; int unk60c;
    GeomGroupMap kGroups;
    int unk614; int unk618; int unk61c; int unk620; int unk624; int unk628; int unk62c; int unk630;
    int unk634; int unk638; int unk63c; int unk640; int unk644; int unk648; int unk64c; int unk650;
    int unk654; int unk658; int unk65c; int unk660; int unk664; int unk668; int unk66c; int unk670;
    int unk674; int unk678; int unk67c; int unk680; int unk684; int unk688; int unk68c; int unk690;
    int unk694; int unk698; int unk69c; int unk6a0; int unk6a4; int unk6a8; int unk6ac; int unk6b0;
    int unk6b4; int unk6b8; int unk6bc; int unk6c0; int unk6c4; int unk6c8; int unk6cc; int unk6d0;
    int unk6d4; int unk6d8; int unk6dc; int unk6e0; int unk6e4; int unk6e8; int unk6ec; int unk6f0;
    int unk6f4; int unk6f8; int unk6fc; int unk700; int unk704; int unk708; int unk70c; int unk710;
    int unk714; int unk718; int unk71c; int unk720; int unk724; int unk728; int unk72c; int unk730;
    int unk734; int unk738; int unk73c; int unk740; int unk744; int unk748; int unk74c; int unk750;
    int unk754; int unk758; int unk75c; int unk760; int unk764; int unk768; int unk76c; int unk770;
    int unk774; int unk778; int unk77c; int unk780; int unk784; int unk788; int unk78c; int unk790;
    int unk794; int unk798; int unk79c; int unk7a0; int unk7a4; int unk7a8; int unk7ac; int unk7b0;
    int unk7b4; int unk7b8; int unk7bc; int unk7c0; int unk7c4; int unk7c8; int unk7cc; int unk7d0;
    int unk7d4; int unk7d8; int unk7dc; int unk7e0; int unk7e4; int unk7e8; int unk7ec; int unk7f0;
    int unk7f4; int unk7f8; int unk7fc; int unk800; int unk804; int unk808; int unk80c; int unk810;
    int unk814; int unk818; int unk81c; int unk820; int unk824; int unk828; int unk82c; int unk830;
    int unk834; int unk838; int unk83c; int unk840; int unk844; int unk848; int unk84c; int unk850;
    int unk854; int unk858; int unk85c; int unk860; int unk864; int unk868; int unk86c; int unk870;
    int unk874; int unk878; int unk87c; int unk880; int unk884; int unk888; int unk88c; int unk890;
    int unk894; int unk898; int unk89c; int unk8a0; int unk8a4; int unk8a8;
    GeomListener* pkListener;

    void RemoveGeomFromGroups(GeomData* pkGeom);
};

// Removes every group entry referencing pkGeom from the group map under both locks, then calls the listener's Release on pkGeom.
// @fnv 0x00e71cf0
void GeomGroupOwner::RemoveGeomFromGroups(GeomData* pkGeom)
{
    if (!pkGeom)
        return;
    GeomPartitionArray* pkParts = pkGeom->pkPartitions;
    if (!pkParts)
        return;
    if (pkParts->Get(0)) {
        fnv_EnterCriticalSection(&kLockA);
        fnv_EnterCriticalSection(&kLockB);
        for (unsigned int i = 0; i < pkParts->uiSize; i++) {
            unsigned int uiKey = pkParts->Get(i)->uiKey;
            GeomGroupEntry* pkHead = 0;
            if (kGroups.Lookup(uiKey, pkHead)) {
                GeomGroupEntry* pkPrev = 0;
                GeomGroupEntry* pkEntry = pkHead;
                while (pkEntry) {
                    if (pkEntry->pkGeometry == pkGeom) {
                        GeomGroupEntry* pkNext = 0;
                        if (pkPrev) {
                            pkPrev->kNext.pkEntry = pkEntry->kNext.pkEntry;
                            pkNext = pkEntry->kNext.pkEntry;
                        } else if (pkEntry->kNext.pkEntry) {
                            kGroups.Assign(uiKey, pkEntry->kNext);
                            pkNext = pkEntry->kNext.pkEntry;
                        } else {
                            kGroups.Remove(uiKey);
                        }
                        pkEntry->kNext.pkEntry = 0;
                        NiFreeSized(pkEntry, sizeof(GeomGroupEntry));
                        pkEntry = pkNext;
                    } else {
                        pkPrev = pkEntry;
                        pkEntry = pkEntry->kNext.pkEntry;
                    }
                }
            }
        }
        fnv_LeaveCriticalSection(&kLockB);
        fnv_LeaveCriticalSection(&kLockA);
    }
    pkListener->Release(pkGeom, 0);
}

extern "C" const NiRTTI DAT_011f4a70;
extern const char g_011f5af4_arg1[];
struct Geo108; struct Packet108;
// Not NiAVObject: a view of the geometry data PrepareGeometryPacket packs (vertex count at 0x08, triangle count
// at 0x40, strip count at 0x44); the source is tested against NiTriStripsData's NiRTTI (0x011f4a70, built by
// 0x00fb5c20 with the name "NiTriStripsData").
namespace fnv_00e71fe0 {
class FUN_00e71fe0_GeometryData {
public:
virtual void v0();
virtual void v1();
virtual const NiRTTI* GetRTTI();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual void v21();
virtual void v22();
virtual void v23();
virtual void v24();
virtual void v25();
virtual void v26();
virtual void v27();
virtual void v28();
virtual void v29();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual unsigned short GetActiveVertexQuantity();
virtual void v37();
virtual void v38();
virtual void v39();
virtual void v40();
virtual void v41();
virtual unsigned short GetNumberOfVertices();
virtual void* Pack(FUN_00e71fe0_GeometryData*,Geo108*,int,unsigned short,void*,unsigned int,int,int,int);
unsigned int unk04;
unsigned short vertices; unsigned short unk0a; unsigned short flags; unsigned short dirty;
unsigned int unk10,unk14,unk18,unk1c,unk20; void* colors; void* normals;
unsigned int unk2c,unk30,unk34,unk38,unk3c;
unsigned short triangles,unk42,strips,unk46; void* activeTriangles;
void* FUN_00a75f10(); void* FUN_00a7b850();
 __forceinline bool IsKindOfType(const NiRTTI* type) {const NiRTTI* r = GetRTTI(); while(r) {if(r==type) return true;r=r->m_pBaseRTTI;} return false;}

};
} // namespace fnv_00e71fe0
bool NiObject_IsKindOf(const NiRTTI*,NiAVObject*);
struct Owner108 {
virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void ReleaseStream(Packet108*,unsigned int);
};
struct Packet108 {
unsigned int unk00, flags; Owner108* owner; unsigned int unk0c,unk10; bool dynamic; unsigned char unk15; unsigned short unk16;
unsigned int activeVertices,vertices,streamCount,unk24; void** streams; unsigned int indexCount,indexOffset; void* indexBuffer; unsigned int unk38,unk3c,stripLengths,triangles,stripCount;void* activeTriangles;void* indices;
__forceinline void SetVertexCounts(unsigned short av,unsigned short v) { activeVertices=av; vertices=v; }
__forceinline void SetTriangleCounts(unsigned short at,unsigned short t,void* lens,unsigned short strips,void* idx) { stripLengths=at; triangles=t; activeTriangles=lens; indices=idx; stripCount=strips; }
bool FUN_00e8eeb0(); void NiGeometryBufferData_SetStreamCount(unsigned int); void FUN_00e8eee0();
};
struct Geo108 {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,revision;};

struct VB108 { unsigned int FUN_00e8bf90(); void* NiDX9VertexBufferManager_PackUntransformedVB(fnv_00e71fe0::FUN_00e71fe0_GeometryData*,Geo108*,unsigned short,void*,int);};
struct IB108 { void* FUN_00e8f200(void*,unsigned int,unsigned int,void*,unsigned int*,unsigned int,unsigned int);};
extern bool DAT_0126f0d0;
// NiDX9Renderer packet-building view: managers at 0x8bc/0x8c0; its shared header lacks PrepareGeometryPacket (0x00e71fe0).
struct GeometryPacketBuilder {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
unsigned int unk210;
unsigned int unk214;
unsigned int unk218;
unsigned int unk21c;
unsigned int unk220;
unsigned int unk224;
unsigned int unk228;
unsigned int unk22c;
unsigned int unk230;
unsigned int unk234;
unsigned int unk238;
unsigned int unk23c;
unsigned int unk240;
unsigned int unk244;
unsigned int unk248;
unsigned int unk24c;
unsigned int unk250;
unsigned int unk254;
unsigned int unk258;
unsigned int unk25c;
unsigned int unk260;
unsigned int unk264;
unsigned int unk268;
unsigned int unk26c;
unsigned int unk270;
unsigned int unk274;
unsigned int unk278;
unsigned int unk27c;
unsigned int unk280;
unsigned int unk284;
unsigned int unk288;
unsigned int unk28c;
unsigned int unk290;
unsigned int unk294;
unsigned int unk298;
unsigned int unk29c;
unsigned int unk2a0;
unsigned int unk2a4;
unsigned int unk2a8;
unsigned int unk2ac;
unsigned int unk2b0;
unsigned int unk2b4;
unsigned int unk2b8;
unsigned int unk2bc;
unsigned int unk2c0;
unsigned int unk2c4;
unsigned int unk2c8;
unsigned int unk2cc;
unsigned int unk2d0;
unsigned int unk2d4;
unsigned int unk2d8;
unsigned int unk2dc;
unsigned int unk2e0;
unsigned int unk2e4;
unsigned int unk2e8;
unsigned int unk2ec;
unsigned int unk2f0;
unsigned int unk2f4;
unsigned int unk2f8;
unsigned int unk2fc;
unsigned int unk300;
unsigned int unk304;
unsigned int unk308;
unsigned int unk30c;
unsigned int unk310;
unsigned int unk314;
unsigned int unk318;
unsigned int unk31c;
unsigned int unk320;
unsigned int unk324;
unsigned int unk328;
unsigned int unk32c;
unsigned int unk330;
unsigned int unk334;
unsigned int unk338;
unsigned int unk33c;
unsigned int unk340;
unsigned int unk344;
unsigned int unk348;
unsigned int unk34c;
unsigned int unk350;
unsigned int unk354;
unsigned int unk358;
unsigned int unk35c;
unsigned int unk360;
unsigned int unk364;
unsigned int unk368;
unsigned int unk36c;
unsigned int unk370;
unsigned int unk374;
unsigned int unk378;
unsigned int unk37c;
unsigned int unk380;
unsigned int unk384;
unsigned int unk388;
unsigned int unk38c;
unsigned int unk390;
unsigned int unk394;
unsigned int unk398;
unsigned int unk39c;
unsigned int unk3a0;
unsigned int unk3a4;
unsigned int unk3a8;
unsigned int unk3ac;
unsigned int unk3b0;
unsigned int unk3b4;
unsigned int unk3b8;
unsigned int unk3bc;
unsigned int unk3c0;
unsigned int unk3c4;
unsigned int unk3c8;
unsigned int unk3cc;
unsigned int unk3d0;
unsigned int unk3d4;
unsigned int unk3d8;
unsigned int unk3dc;
unsigned int unk3e0;
unsigned int unk3e4;
unsigned int unk3e8;
unsigned int unk3ec;
unsigned int unk3f0;
unsigned int unk3f4;
unsigned int unk3f8;
unsigned int unk3fc;
unsigned int unk400;
unsigned int unk404;
unsigned int unk408;
unsigned int unk40c;
unsigned int unk410;
unsigned int unk414;
unsigned int unk418;
unsigned int unk41c;
unsigned int unk420;
unsigned int unk424;
unsigned int unk428;
unsigned int unk42c;
unsigned int unk430;
unsigned int unk434;
unsigned int unk438;
unsigned int unk43c;
unsigned int unk440;
unsigned int unk444;
unsigned int unk448;
unsigned int unk44c;
unsigned int unk450;
unsigned int unk454;
unsigned int unk458;
unsigned int unk45c;
unsigned int unk460;
unsigned int unk464;
unsigned int unk468;
unsigned int unk46c;
unsigned int unk470;
unsigned int unk474;
unsigned int unk478;
unsigned int unk47c;
unsigned int unk480;
unsigned int unk484;
unsigned int unk488;
unsigned int unk48c;
unsigned int unk490;
unsigned int unk494;
unsigned int unk498;
unsigned int unk49c;
unsigned int unk4a0;
unsigned int unk4a4;
unsigned int unk4a8;
unsigned int unk4ac;
unsigned int unk4b0;
unsigned int unk4b4;
unsigned int unk4b8;
unsigned int unk4bc;
unsigned int unk4c0;
unsigned int unk4c4;
unsigned int unk4c8;
unsigned int unk4cc;
unsigned int unk4d0;
unsigned int unk4d4;
unsigned int unk4d8;
unsigned int unk4dc;
unsigned int unk4e0;
unsigned int unk4e4;
unsigned int unk4e8;
unsigned int unk4ec;
unsigned int unk4f0;
unsigned int unk4f4;
unsigned int unk4f8;
unsigned int unk4fc;
unsigned int unk500;
unsigned int unk504;
unsigned int unk508;
unsigned int unk50c;
unsigned int unk510;
unsigned int unk514;
unsigned int unk518;
unsigned int unk51c;
unsigned int unk520;
unsigned int unk524;
unsigned int unk528;
unsigned int unk52c;
unsigned int unk530;
unsigned int unk534;
unsigned int unk538;
unsigned int unk53c;
unsigned int unk540;
unsigned int unk544;
unsigned int unk548;
unsigned int unk54c;
unsigned int unk550;
unsigned int unk554;
unsigned int unk558;
unsigned int unk55c;
unsigned int unk560;
unsigned int unk564;
unsigned int unk568;
unsigned int unk56c;
unsigned int unk570;
unsigned int unk574;
unsigned int unk578;
unsigned int unk57c;
unsigned int unk580;
unsigned int unk584;
unsigned int unk588;
unsigned int unk58c;
unsigned int unk590;
unsigned int unk594;
unsigned int unk598;
unsigned int unk59c;
unsigned int unk5a0;
unsigned int unk5a4;
unsigned int unk5a8;
unsigned int unk5ac;
unsigned int unk5b0;
unsigned int unk5b4;
unsigned int unk5b8;
unsigned int unk5bc;
unsigned int unk5c0;
unsigned int unk5c4;
unsigned int unk5c8;
unsigned int unk5cc;
unsigned int unk5d0;
unsigned int unk5d4;
unsigned int unk5d8;
unsigned int unk5dc;
unsigned int unk5e0;
unsigned int unk5e4;
unsigned int unk5e8;
unsigned int unk5ec;
unsigned int unk5f0;
unsigned int unk5f4;
unsigned int unk5f8;
unsigned int unk5fc;
unsigned int unk600;
unsigned int unk604;
unsigned int unk608;
unsigned int unk60c;
unsigned int unk610;
unsigned int unk614;
unsigned int unk618;
unsigned int unk61c;
unsigned int unk620;
unsigned int unk624;
unsigned int unk628;
unsigned int unk62c;
unsigned int unk630;
unsigned int unk634;
unsigned int unk638;
unsigned int unk63c;
unsigned int unk640;
unsigned int unk644;
unsigned int unk648;
unsigned int unk64c;
unsigned int unk650;
unsigned int unk654;
unsigned int unk658;
unsigned int unk65c;
unsigned int unk660;
unsigned int unk664;
unsigned int unk668;
unsigned int unk66c;
unsigned int unk670;
unsigned int unk674;
unsigned int unk678;
unsigned int unk67c;
unsigned int unk680;
unsigned int unk684;
unsigned int unk688;
unsigned int unk68c;
unsigned int unk690;
unsigned int unk694;
unsigned int unk698;
unsigned int unk69c;
unsigned int unk6a0;
unsigned int unk6a4;
unsigned int unk6a8;
unsigned int unk6ac;
unsigned int unk6b0;
unsigned int unk6b4;
unsigned int unk6b8;
unsigned int unk6bc;
unsigned int unk6c0;
unsigned int unk6c4;
unsigned int unk6c8;
unsigned int unk6cc;
unsigned int unk6d0;
unsigned int unk6d4;
unsigned int unk6d8;
unsigned int unk6dc;
unsigned int unk6e0;
unsigned int unk6e4;
unsigned int unk6e8;
unsigned int unk6ec;
unsigned int unk6f0;
unsigned int unk6f4;
unsigned int unk6f8;
unsigned int unk6fc;
unsigned int unk700;
unsigned int unk704;
unsigned int unk708;
unsigned int unk70c;
unsigned int unk710;
unsigned int unk714;
unsigned int unk718;
unsigned int unk71c;
unsigned int unk720;
unsigned int unk724;
unsigned int unk728;
unsigned int unk72c;
unsigned int unk730;
unsigned int unk734;
unsigned int unk738;
unsigned int unk73c;
unsigned int unk740;
unsigned int unk744;
unsigned int unk748;
unsigned int unk74c;
unsigned int unk750;
unsigned int unk754;
unsigned int unk758;
unsigned int unk75c;
unsigned int unk760;
unsigned int unk764;
unsigned int unk768;
unsigned int unk76c;
unsigned int unk770;
unsigned int unk774;
unsigned int unk778;
unsigned int unk77c;
unsigned int unk780;
unsigned int unk784;
unsigned int unk788;
unsigned int unk78c;
unsigned int unk790;
unsigned int unk794;
unsigned int unk798;
unsigned int unk79c;
unsigned int unk7a0;
unsigned int unk7a4;
unsigned int unk7a8;
unsigned int unk7ac;
unsigned int unk7b0;
unsigned int unk7b4;
unsigned int unk7b8;
unsigned int unk7bc;
unsigned int unk7c0;
unsigned int unk7c4;
unsigned int unk7c8;
unsigned int unk7cc;
unsigned int unk7d0;
unsigned int unk7d4;
unsigned int unk7d8;
unsigned int unk7dc;
unsigned int unk7e0;
unsigned int unk7e4;
unsigned int unk7e8;
unsigned int unk7ec;
unsigned int unk7f0;
unsigned int unk7f4;
unsigned int unk7f8;
unsigned int unk7fc;
unsigned int unk800;
unsigned int unk804;
unsigned int unk808;
unsigned int unk80c;
unsigned int unk810;
unsigned int unk814;
unsigned int unk818;
unsigned int unk81c;
unsigned int unk820;
unsigned int unk824;
unsigned int unk828;
unsigned int unk82c;
unsigned int unk830;
unsigned int unk834;
unsigned int unk838;
unsigned int unk83c;
unsigned int unk840;
unsigned int unk844;
unsigned int unk848;
unsigned int unk84c;
unsigned int unk850;
unsigned int unk854;
unsigned int unk858;
unsigned int unk85c;
unsigned int unk860;
unsigned int unk864;
unsigned int unk868;
unsigned int unk86c;
unsigned int unk870;
unsigned int unk874;
unsigned int unk878;
unsigned int unk87c;
unsigned int unk880;
unsigned int unk884;
unsigned int unk888;
unsigned int unk88c;
unsigned int unk890;
unsigned int unk894;
unsigned int unk898;
unsigned int unk89c;
unsigned int unk8a0;
unsigned int unk8a4;
unsigned int unk8a8;
unsigned int unk8ac;
unsigned int unk8b0;
unsigned int unk8b4;
unsigned int unk8b8;
VB108* vb; IB108* ib;
bool PrepareGeometryPacket(Packet108*,fnv_00e71fe0::FUN_00e71fe0_GeometryData*,Geo108*,fnv_00e71fe0::FUN_00e71fe0_GeometryData*,bool);
};
// @fnv 0x00e71fe0
bool GeometryPacketBuilder::PrepareGeometryPacket(Packet108* packet, fnv_00e71fe0::FUN_00e71fe0_GeometryData* source, Geo108* geometry, fnv_00e71fe0::FUN_00e71fe0_GeometryData* shader, bool force)
{
 if (!packet || !source) return false;
 bool cached = packet->FUN_00e8eeb0();
 if (!force && cached && (source->dirty & 0x7000) == 0x4000) return true;
 bool normals = source->normals != 0;
 bool colors = source->colors != 0;
 bool extra = colors && (source->flags & 0xf000);
 unsigned int tex = source->flags & 1;
 if (tex > (unsigned int)DAT_011bf558) tex = DAT_011bf558;
 unsigned int flags = 0;
 if (normals) flags = 0x400000;
 if (colors) flags |= 0x800000;
 if (extra) flags |= 0x200000;
 packet->flags = (tex << 24) | flags;
 unsigned short activeVertices = source->GetActiveVertexQuantity();
 unsigned short vertices = source->vertices;
 unsigned short stripLengths = 0;
 unsigned short triangles = 0;
 unsigned int indexCount = 0;
 void* indices = 0;
 void* activeTriangles = 0;
 unsigned short stripCount = 0;
 if (source->IsKindOfType(reinterpret_cast<const NiRTTI*>(g_011f5af4_arg1))) {
  stripLengths = source->GetNumberOfVertices();
  triangles = source->triangles;
  indices = source->FUN_00a7b850();
  activeTriangles = 0;
  stripCount = 1;
  indexCount = (unsigned short)triangles * 3;
 } else if (NiObject_IsKindOf(&DAT_011f4a70,reinterpret_cast<NiAVObject*>(source))) {
  stripLengths = source->GetNumberOfVertices();
  triangles = source->triangles;
  indices = source->FUN_00a75f10();
  activeTriangles = source->activeTriangles;
  stripCount = source->strips;
  indexCount = (unsigned short)triangles + (unsigned short)stripCount * 2;
 }
 unsigned int streams = shader ? shader->unk20 : 1;
 unsigned short dirty = source->dirty & 0xfff;
 if (geometry) {
  unsigned int oldRevision = geometry->revision;
  if (oldRevision != vb->FUN_00e8bf90()) {
   dirty |= 3;
   geometry->revision = vb->FUN_00e8bf90();
  }
 }
 if (force) dirty = 0xfff;
 if (cached) {
  if (streams != packet->streamCount) {
   packet->NiGeometryBufferData_SetStreamCount(streams);
   dirty = 0xfff;
  }
 } else {
  Owner108* owner = packet->owner;
  for (unsigned int i=0;i<streams;i++) owner->ReleaseStream(packet,i);
  packet->NiGeometryBufferData_SetStreamCount(streams);
  packet->unk38 = 0;
  dirty = 0xfff;
 }
 packet->SetVertexCounts(activeVertices,vertices);
 packet->SetTriangleCounts(stripLengths,triangles,activeTriangles,stripCount,indices);
 if (dirty & ~0x10) {
  for (unsigned int i=0; i<streams; i++) {
   void* stream = i < packet->streamCount ? packet->streams[i] : 0;
   if (!shader || !shader->Pack(source,geometry,0,dirty,stream,i,0,0,0)) {
    if (streams != 1 || !vb->NiDX9VertexBufferManager_PackUntransformedVB(source,geometry,dirty,stream,0)) return false;
   }
  }
 }
 
 if (indices && (dirty & 0x30)) {

  unsigned int offset = packet->indexOffset;
  void* oldBuffer = packet->indexBuffer;
  void* buffer = ib->FUN_00e8f200(indices,indexCount,indexCount,oldBuffer,&offset,!DAT_0126f0d0,packet->dynamic ? 0x10 : 0);
  if (!buffer) return false;
  if (oldBuffer != buffer) {
   packet->FUN_00e8eee0();
   packet->indexBuffer = buffer;
   packet->indexCount = indexCount;
   packet->indexOffset = offset;
  }

 }
 source->dirty &= ~0xfff;
 return true;
}

__declspec(noreturn) void __cdecl AddGeometryToBatch();

// @fnv 0x00e752a0
// src: COMMUNITY 0x00e752a0
void __cdecl NiDX9Renderer_BatchRenderShape() {
    AddGeometryToBatch();
}

extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct StridedDataTransfer {
    int unk00;
    unsigned short usType;
    unsigned short pad06;
    unsigned short m_usPassCountLocal;
    unsigned short pad0a;
    unsigned short* pusIndex;
    unsigned char* pucSrc;
    int unk14;
    unsigned int uiSrcStride;
    unsigned int uiSize;
    unsigned int uiDstStride;
    int unk24;
    int unk28;
    unsigned char* pucDst;
};
// Copies up to 4 bytes per row from source (indexed or sequential) into destination, zero-filling the remainder, and returns the total bytes processed.
// @fnv 0x00e78210
unsigned int CopyIndexedRows(StridedDataTransfer* pkData)
{
    unsigned int uiTotal = 0;
    unsigned char* pucSrc = pkData->pucSrc;
    unsigned short* pusIndex = pkData->pusIndex;
    unsigned char* pucDst = pkData->pucDst;
    if (!pucSrc)
    {
        for (unsigned short i = 0; i < pkData->m_usPassCountLocal; i++)
        {
            FUN_00ec61c0(pucDst, 0, pkData->uiSize);
            pucDst += pkData->uiDstStride;
            uiTotal += pkData->uiSize;
        }
        return uiTotal;
    }
    unsigned short usTypeOffset = pkData->usType - 0x14; unsigned short usCopyLen = (usTypeOffset > 4) ? 4 : usTypeOffset;
    if (pusIndex)
    {
        unsigned short j = 0;
        for (unsigned short i = 0; i < pkData->m_usPassCountLocal; i++)
        {
            unsigned char* s = pucSrc + pusIndex[j++] * pkData->uiSrcStride;
            unsigned char* d = pucDst;
            unsigned short k;
            for (k = 0; k < usCopyLen; k++) *d++ = *s++;
            if (k < 4) FUN_00ec61c0(d, 0, (unsigned short)(4 - k));
            uiTotal += pkData->uiSize;
            pucDst += pkData->uiDstStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < pkData->m_usPassCountLocal; i++)
        {
            unsigned char* s = pucSrc;
            unsigned char* d = pucDst;
            unsigned short k;
            for (k = 0; k < usCopyLen; k++) *d++ = *s++;
            if (k < 4) FUN_00ec61c0(d, 0, (unsigned short)(4 - k));
            uiTotal += pkData->uiSize;
            pucSrc += pkData->uiSrcStride;
            pucDst += pkData->uiDstStride;
        }
    }
    return uiTotal;
}

// Returns true unconditionally, ignoring all three pointer arguments.
// @fnv 0x00e78870
bool __stdcall IsAlwaysTrue(void* a1, void* a2, void* a3)
{
    return true;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

namespace fnv_00e6eea0 {
extern char DAT_0126f59c, DAT_0126f5ac, DAT_0126f5d8;
void __cdecl NiDX92DBufferData_ClearRenderTarget(int* param1, int param2);
void __cdecl Object_DoNothing(const char* fmt, const char* text);
struct RTTIX { const char* name; const RTTIX* parent; };
struct DevX;
class ObjX {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual const RTTIX* GetRTTI() const;
};
class BufDataX : public ObjX {
public:
    virtual void w04(),w05(),w06(),w07(),w08(),w09(),w0a(),w0b(),w0c(),w0d(),w0e(),w0f(),w10(),w11(),w12(),w13(),w14(),w15(),w16();
    virtual bool SetRenderTarget(DevX* pkDev, unsigned int uiTarget);
    virtual bool SetDepthTarget(DevX* pkDev);
};
class TargetX {
public:
    virtual void u00(),u01(),u02(),u03(),u04(),u05(),u06(),u07(),u08(),u09(),u0a(),u0b(),u0c(),u0d(),u0e(),u0f(),
        u10(),u11(),u12(),u13(),u14(),u15(),u16(),u17(),u18(),u19(),u1a(),u1b(),u1c(),u1d(),u1e(),u1f(),
        u20(),u21(),u22(),u23(),u24(),u25(),u26(),u27(),u28();
    virtual unsigned int GetBufferCount() const;
    virtual void u2a(),u2b(),u2c(),u2d(),u2e(),u2f(),u30(),u31();
    virtual ObjX* GetRenderTargetBuffer(unsigned int ui) const;
    virtual ObjX* GetDepthAttachment() const;
};
bool __cdecl NiDX9DepthStencilBufferData_SetNULLDepthStencilTarget(DevX* pkDev);
inline bool IsKindOfX2(const ObjX* p, const void* r) {
    for (const RTTIX* t = p->GetRTTI(); t; t = t->parent)
        if (t == r) return true;
    return false;
}
inline BufDataX* DynCastX(ObjX* p, const void* r) { if (!p) return 0; return IsKindOfX2(p, r) ? (BufDataX*)p : 0; }
class RendX {
public:
    virtual void r00(),r01(),r02(),r03(),r04(),r05(),r06(),r07(),r08(),r09(),r0a(),r0b(),r0c(),r0d(),r0e(),r0f(),
        r10(),r11(),r12(),r13(),r14(),r15(),r16(),r17(),r18(),r19(),r1a(),r1b(),r1c(),r1d(),r1e(),r1f(),
        r20(),r21(),r22(),r23(),r24(),r25(),r26(),r27(),r28(),r29(),r2a(),r2b(),r2c(),r2d(),r2e(),r2f(),
        r30(),r31(),r32(),r33(),r34(),r35(),r36(),r37(),r38(),r39(),r3a(),r3b(),r3c(),r3d(),r3e(),r3f(),
        r40(),r41(),r42(),r43(),r44(),r45(),r46(),r47(),r48(),r49(),r4a(),r4b(),r4c(),r4d(),r4e(),r4f(),
        r50(),r51(),r52(),r53(),r54(),r55(),r56(),r57(),r58(),r59(),r5a(),r5b(),r5c(),r5d(),r5e(),r5f(),r60(),r61();
    virtual void ClearBuffer(const void* pkR, unsigned int uiMode);
    virtual void r63(),r64();
    virtual bool BeginUsingRenderTargetGroup(TargetX* pkTarget, unsigned int uiClearMode);
    char pad[0x288 - 4];
    DevX* m_pDirect3DDevice;
    char pad2[0x6fc - 0x28c];
    bool m_bDeviceLost;
    char pad3[0x884 - 0x6fd];
    TargetX* m_pDefaultRenderTargetGroup;
    TargetX* m_pCurrentRenderTargetGroup;
    TargetX* m_pkCurrOnscreenRenderTargetGroup;
    bool NiDX9Renderer_BeginUsingRenderTargetGroup(TargetX* pkTarget, unsigned int uiClearMode);
};
// @fnv 0x00e6eea0
// src: EXE 0x00e6eea0
bool RendX::NiDX9Renderer_BeginUsingRenderTargetGroup(TargetX* pkTarget, unsigned int uiClearMode)
{
    if (!m_bDeviceLost) {
    NiDX92DBufferData_ClearRenderTarget((int*)m_pDirect3DDevice, 1);
    NiDX92DBufferData_ClearRenderTarget((int*)m_pDirect3DDevice, 2);
    NiDX92DBufferData_ClearRenderTarget((int*)m_pDirect3DDevice, 3);
    for (unsigned int ui = 0; ui < pkTarget->GetBufferCount(); ui++) {
        ObjX* pkObj = pkTarget->GetRenderTargetBuffer(ui);
        BufDataX* pkBuffData = DynCastX(pkObj, &DAT_0126f59c);
        if (pkBuffData && !pkBuffData->SetRenderTarget(m_pDirect3DDevice, ui)) {
            BeginUsingRenderTargetGroup(m_pDefaultRenderTargetGroup, uiClearMode);
            Object_DoNothing("NiDX9Renderer::BeginUsingRenderTargetGroup> Failed - %s",
                "Setting an output target failed. Resetting to default target.");
            return false;
        }
    }
    ObjX* pkObj = pkTarget->GetDepthAttachment();
    BufDataX* pkDepth = DynCastX(pkObj, &DAT_0126f5ac);
    if (pkDepth) {
        if (!pkDepth->SetDepthTarget(m_pDirect3DDevice)) {
            BeginUsingRenderTargetGroup(m_pDefaultRenderTargetGroup, uiClearMode);
            Object_DoNothing("NiDX9Renderer::BeginUsingRenderTargetGroup> Failed - %s",
                "Setting the depth/stencil buffer failed. Resetting to default target.");
            return false;
        }
    } else if (!NiDX9DepthStencilBufferData_SetNULLDepthStencilTarget(m_pDirect3DDevice)) {
        BeginUsingRenderTargetGroup(m_pDefaultRenderTargetGroup, uiClearMode);
        Object_DoNothing("NiDX9Renderer::BeginUsingRenderTargetGroup> Failed - %s",
            "Setting the depth/stencil buffer to NULL failed. Resetting to default target.");
        return false;
    }
    BufDataX* pkOn = DynCastX(pkTarget->GetRenderTargetBuffer(0), &DAT_0126f5d8);
    m_pCurrentRenderTargetGroup = pkTarget;
    if (pkOn)
        m_pkCurrOnscreenRenderTargetGroup = pkTarget;
    ClearBuffer(0, uiClearMode);
    }
    return true;
}
}  // namespace fnv_00e6eea0

// Win32 tagRECT layout (four LONGs, 16 bytes); include/tagRECT.h is not available yet.
struct SurfaceCopyRectangle { long left; long top; long right; long bottom; };
struct PixFmtX { bool FUN_00a765c0(const PixFmtX* o) const; };
struct SurfX;
struct DevX;
struct DevVT {
    void* f[34];
    long (__stdcall* StretchRect)(DevX* self, SurfX* src, const SurfaceCopyRectangle* srect, SurfX* dst, const SurfaceCopyRectangle* drect, int filter);
};
struct DevX { DevVT* vt; };
struct BufDataX { char pad[0xc]; PixFmtX* m_pkRenderPixelFormat; int m_10; SurfX* m_pkSurface; };
struct BufX { char pad[0x10]; BufDataX* m_pRendererData; };
struct RectUX { unsigned int m_fMinimumU, m_fMaximumU, m_fMinimumV, m_fMaximumV; };
void Object_DoNothing(const char* fmt, ...);
const char* GetHResultName(long hr);
class RendX {
public:
    char pad[0x288];
    DevX* m_pDirect3DDevice;
    char pad2[0x6fc - 0x28c];
    bool m_bDeviceLost;
    bool NiDX9Renderer_FastCopy(const BufX* pkSrc, BufX* pkDest, const RectUX* pkSrcRect, unsigned int uiDestX, unsigned int uiDestY);
};
// Copies a source surface to a destination surface via StretchRect, validating device, renderer data, pixel formats, and surfaces.
// @fnv 0x00e6f6e0
// src: EXE 0x00e6f6e0
bool RendX::NiDX9Renderer_FastCopy(const BufX* pkSrc, BufX* pkDest, const RectUX* pkSrcRect, unsigned int uiDestX, unsigned int uiDestY)
{
    if (m_bDeviceLost)
        return false;
    BufDataX* pkSrcData = pkSrc->m_pRendererData;
    BufDataX* pkDestData = pkDest->m_pRendererData;
    if (!pkSrcData || !pkDestData) {
        Object_DoNothing("NiDX9Renderer::FastCopy> Failed - %s", "No RendererData found");
        return false;
    }
    if (pkSrcData->m_pkRenderPixelFormat->FUN_00a765c0(pkDestData->m_pkRenderPixelFormat)) {
        Object_DoNothing("NiDX9Renderer::FastCopy> Failed - %s", "Pixel formats do not match");
        return false;
    }
    SurfX* pkSrcSurf = pkSrcData->m_pkSurface;
    SurfX* pkDestSurf = pkDestData->m_pkSurface;
    if (!pkSrcSurf || !pkDestSurf) {
        Object_DoNothing("NiDX9Renderer::FastCopy> Failed - %s", "NULL Surface found");
        return false;
    }
    long hr;
    if (pkSrcRect) {
        SurfaceCopyRectangle kSrc; SurfaceCopyRectangle kDest;
        kSrc.left = pkSrcRect->m_fMinimumU;
        kSrc.right = pkSrcRect->m_fMaximumU;
        kSrc.top = pkSrcRect->m_fMinimumV;
        kSrc.bottom = pkSrcRect->m_fMaximumV;
        kDest.left = uiDestX;
        kDest.right = uiDestX + kSrc.right - kSrc.left;
        kDest.top = uiDestY;
        kDest.bottom = uiDestY + kSrc.bottom - kSrc.top;
        hr = m_pDirect3DDevice->vt->StretchRect(m_pDirect3DDevice, pkSrcSurf, &kSrc, pkDestSurf, &kDest, 0);
    } else {
        hr = m_pDirect3DDevice->vt->StretchRect(m_pDirect3DDevice, pkSrcSurf, 0, pkDestSurf, 0, 0);
    }
    if (hr < 0) {
        Object_DoNothing("NiDX9Renderer::FastCopy> Failed StretchRect - %s", GetHResultName(hr));
        return false;
    }
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct S00e711e0_Sub {
    int unk00; int unk04; int unk08;
    unsigned short unk0c;
    unsigned short flags;
};

struct S00e711e0_Obj {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    void* m20;
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
    int m68;
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
    S00e711e0_Sub* mb8;
    unsigned int mbc;
};

struct S00e711e0_Entry {
    S00e711e0_Obj* obj;
    unsigned int a4;
    unsigned int a8;
    S00e711e0_Entry* next;
};

struct S00e711e0_E {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    unsigned int m18;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3c;
    unsigned int m40;
    int unk044;
    unsigned int m48;
    unsigned short* m4c;
};

class S00e711e0_P {
public:
    virtual void pv00();
    virtual void Release();
    virtual void pv02();
    virtual void pv03();
    virtual void pv04();
    virtual void pv05();
    virtual void pv06();
    virtual void pv07();
    virtual void pv08();
    virtual void pv09();
    virtual void pv10();
    virtual void pv11();
    virtual void pv12();
    virtual void pv13();
    virtual void pv14();
    virtual void pv15();
    virtual void pv16();
    virtual void pv17();
    virtual void pv18();
    virtual void pv19();
    virtual void pv20();
    virtual int v21(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual void v22(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual void v23(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual void v24(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual void pv25();
    virtual void v26(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual unsigned int v27(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int);
    virtual void v28(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual void v29(S00e711e0_Obj*, unsigned int, unsigned int, unsigned int, unsigned int, void*, void*);
    virtual void pv30();
    virtual void pv31();
    virtual void pv32();
    virtual void pv33();
    virtual void pv34();
    virtual void pv35();
    virtual int v36();
    virtual int v37();
    long m_ref;
};

class S00e711e0_Dev {
public:
    virtual void dv00();
    virtual void dv01();
    virtual void dv02();
    virtual void dv03();
    virtual void dv04();
    virtual void dv05();
    virtual void dv06();
    virtual void dv07();
    virtual void dv08();
    virtual void dv09();
    virtual void dv10();
    virtual void dv11();
    virtual void dv12();
    virtual void dv13();
    virtual void dv14();
    virtual void dv15();
    virtual void dv16();
    virtual void dv17();
    virtual void dv18();
    virtual void dv19();
    virtual void dv20();
    virtual void dv21();
    virtual void dv22();
    virtual void dv23();
    virtual void dv24();
    virtual void dv25();
    virtual void dv26();
    virtual void dv27();
    virtual void dv28();
    virtual void dv29();
    virtual void dv30();
    virtual void dv31();
    virtual void dv32();
    virtual void dv33();
    virtual void dv34();
    virtual void dv35();
    virtual void dv36();
    virtual void dv37();
    virtual void dv38();
    virtual void dv39();
    virtual void dv40();
    virtual void dv41();
    virtual void dv42();
    virtual void dv43();
    virtual void dv44();
    virtual void dv45();
    virtual void dv46();
    virtual void dv47();
    virtual void dv48();
    virtual void dv49();
    virtual void dv50();
    virtual void dv51();
    virtual void dv52();
    virtual void dv53();
    virtual void dv54();
    virtual void dv55();
    virtual void dv56();
    virtual void dv57();
    virtual void dv58();
    virtual void dv59();
    virtual void dv60();
    virtual void dv61();
    virtual void dv62();
    virtual void dv63();
    virtual void dv64();
    virtual void dv65();
    virtual void dv66();
    virtual void dv67();
    virtual void dv68();
    virtual void dv69();
    virtual void dv70();
    virtual void dv71();
    virtual void dv72();
    virtual void dv73();
    virtual void dv74();
    virtual void dv75();
    virtual void dv76();
    virtual void dv77();
    virtual void dv78();
    virtual void dv79();
    virtual void dv80();
    virtual long __stdcall v81(unsigned int, unsigned int, unsigned int);
    virtual long __stdcall v82(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

class S00e711e0_Mgr {
public:
    virtual void mv00();
    virtual void mv01();
    virtual void mv02();
    virtual void mv03();
    virtual void mv04();
    virtual void mv05();
    virtual void mv06();
    virtual void mv07();
    virtual void mv08();
    virtual void mv09();
    virtual void mv10();
    virtual void mv11();
    virtual void mv12();
    virtual void mv13();
    virtual void mv14();
    virtual void mv15();
    virtual void mv16();
    virtual void mv17();
    virtual void mv18();
    virtual void mv19();
    virtual void mv20();
    virtual void mv21();
    virtual void mv22();
    virtual void mv23();
    virtual void mv24();
    virtual void mv25();
    virtual void mv26();
    virtual void mv27();
    virtual void mv28();
    virtual void mv29();
    virtual void mv30();
    virtual void mv31();
    virtual void mv32();
    virtual void mv33();
    virtual void mv34();
    virtual void mv35();
    virtual void mv36();
    virtual void mv37();
    virtual void mv38();
    virtual void mv39();
    virtual void mv40();
    virtual void mv41();
    virtual void mv42();
    virtual void mv43();
    virtual void mv44();
    virtual void mv45();
    virtual void mv46();
    virtual void mv47();
    virtual void mv48();
    virtual void mv49();
    virtual void mv50();
    virtual void mv51();
    virtual void mv52();
    virtual void mv53();
    virtual void mv54();
    virtual void mv55();
    virtual void mv56();
    virtual void mv57();
    virtual void mv58();
    virtual void mv59();
    virtual void mv60();
    virtual void mv61();
    virtual void v62(unsigned int);
};

class S00e711e0_Owner {
public:
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
    S00e711e0_Dev* m_288;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    S00e711e0_Entry* m_620;
    unsigned int m_624;
    unsigned int m_628;
    unsigned int m_62c;
    S00e711e0_P* m_630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    unsigned char m_6fc; unsigned char unk6fd; unsigned short unk6fe;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    S00e711e0_Mgr* m_8b8;
    void ClearList();
    __forceinline void ReleaseP()
    {
        S00e711e0_P* p = m_630;
        if (p != 0) {
            if (InterlockedDecrement(&p->m_ref) == 0) p->Release();
            m_630 = 0;
        }
    }
    void NiDX9Renderer_EndBatch();
};

// Calls callbacks for entries in the list, masks object flags, releases the shader, and clears the list.
// @fnv 0x00e711e0
// src: COMMUNITY 0x00e711e0
void S00e711e0_Owner::NiDX9Renderer_EndBatch()
{
    S00e711e0_Entry* head = m_620;
    if (head == 0 || m_6fc != 0) goto L_end;
    {
    unsigned int last = head->a8;
    S00e711e0_Obj* obj = head->obj;
    unsigned int bc = obj->mbc;
    void* p68 = &obj->m68;
    void* hd = obj->m20 ? obj->m20 : (void*)DAT_011f4288;
    void* d = hd;
    if (m_630->v21(obj, bc, last, m_628, m_62c, p68, hd)) {
        ReleaseP();
        m_628 = 0;
        m_62c = 0;
        ClearList();
        return;
    }
    m_630->v22(obj, bc, last, m_628, m_62c, &obj->m68, hd);
    if (m_630->v36()) {
        do {
            S00e711e0_Entry* cur = m_620;
            S00e711e0_Obj* o = cur->obj;
            unsigned int oa8 = cur->a8;
            unsigned int obc = o->mbc;
            void* od = o->m20 ? o->m20 : (void*)DAT_011f4288;
            m_630->v23(o, obc, oa8, m_628, m_62c, &o->m68, od);
            do {
                obj = cur->obj;
                last = cur->a8;
                unsigned int a4 = cur->a4;
                bc = obj->mbc;
                void* dd = obj->m20 ? obj->m20 : (void*)DAT_011f4288;
                d = dd;
                m_630->v24(obj, bc, a4, last, m_628, m_62c, &obj->m68, dd);
                last = m_630->v27(obj, a4, last, m_628);
                S00e711e0_E* e = (S00e711e0_E*)last;
                m_630->v26(obj, bc, a4, last, m_628, m_62c, &obj->m68, dd);
                if (e->m34 != 0) {
                    unsigned int acc = 0;
                    for (unsigned int i = 0; i < e->m48; ++i) {
                        unsigned int len;
                        if (e->m4c != 0) len = e->m4c[i] - 2;
                        else len = e->m40;
                        m_288->v82(e->m3c, e->m38, 0, e->m18, acc, len);
                        acc = acc + len + 2;
                    }
                } else {
                    m_288->v81(e->m3c, e->m38, e->m40);
                }
                m_630->v28(obj, bc, a4, last, m_628, m_62c, &obj->m68, dd);
                cur = cur->next;
            } while (cur != 0);
        } while (m_630->v37());
    }
    for (S00e711e0_Entry* c = m_620; c != 0; c = c->next) {
        c->obj->mb8->flags &= 0xf000;
    }
    S00e711e0_P* shader = m_630;
    void* bound = *(void* volatile*)&d;
    shader->v29(obj, bc, last, m_628, m_62c, &obj->m68, bound);
    ReleaseP();
    m_628 = 0;
    m_62c = 0;
    ClearList();
    m_8b8->v62(0);
    return;
    }
L_end:
    ReleaseP();
    m_628 = 0;
    m_62c = 0;
    ClearList();
}

struct Mesh; struct Batch; struct Shader; struct Skin;
struct Piece { unsigned int unk00,unk04,unk08,unk0c; unsigned char unk10; };
struct Mesh {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual Skin* skin();
virtual Mesh* geometry();
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
Mesh* unkb8; unsigned int unkbc; Shader* unkc0; unsigned int unkc4; unsigned int unkc8; unsigned char unkcc, unkcd;
};
struct Skin { unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; Mesh* unkb8; unsigned int unkbc; unsigned int unkc0; Piece* unkc4; unsigned int unkc8; unsigned char unkcc,unkcd;
unsigned int GetCount() { return unkcd ? 1 : unkc8; }
Piece* GetPiece(unsigned int j) { return j+unkc4; }
unsigned int GetNum(Piece* piece) { return unkcd ? (unsigned short)unkb8->unk040 : piece->unk0c; }
unsigned int GetStart(Piece* piece) { return unkcd ? 0 : piece->unk00; }
};
struct Batch { unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014; unsigned int unk18; unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030; unsigned int unk34; unsigned int unk38; unsigned int unk3c; unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned short* unk4c; };
struct Shader {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual int step21(Mesh*,unsigned int,unsigned int,unsigned int,unsigned int,void*,void*);
virtual int step22(Mesh*,unsigned int,unsigned int,unsigned int,unsigned int,void*,void*);
virtual int step23(Mesh*,unsigned int,unsigned int,unsigned int,unsigned int,void*,void*);
virtual int step24(Mesh*,unsigned int,unsigned int,Batch*,unsigned int,unsigned int,void*,void*);
virtual void v25();
virtual int step26(Mesh*,unsigned int,unsigned int,Batch*,unsigned int,unsigned int,void*,void*);
virtual Batch* batch(Mesh*,unsigned int,unsigned int,unsigned int);
virtual int step28(Mesh*,unsigned int,unsigned int,Batch*,unsigned int,unsigned int,void*,void*);
virtual int step29(Mesh*,unsigned int,unsigned int,unsigned int,unsigned int,void*,void*);
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual int step36();
virtual int step37();
};
struct Device {
virtual void __stdcall v0();
virtual void __stdcall v1();
virtual void __stdcall v2();
virtual void __stdcall v3();
virtual void __stdcall v4();
virtual void __stdcall v5();
virtual void __stdcall v6();
virtual void __stdcall v7();
virtual void __stdcall v8();
virtual void __stdcall v9();
virtual void __stdcall v10();
virtual void __stdcall v11();
virtual void __stdcall v12();
virtual void __stdcall v13();
virtual void __stdcall v14();
virtual void __stdcall v15();
virtual void __stdcall v16();
virtual void __stdcall v17();
virtual void __stdcall v18();
virtual void __stdcall v19();
virtual void __stdcall v20();
virtual void __stdcall v21();
virtual void __stdcall v22();
virtual void __stdcall v23();
virtual void __stdcall v24();
virtual void __stdcall v25();
virtual void __stdcall v26();
virtual void __stdcall v27();
virtual void __stdcall v28();
virtual void __stdcall v29();
virtual void __stdcall v30();
virtual void __stdcall v31();
virtual void __stdcall v32();
virtual void __stdcall v33();
virtual void __stdcall v34();
virtual void __stdcall v35();
virtual void __stdcall v36();
virtual void __stdcall v37();
virtual void __stdcall v38();
virtual void __stdcall v39();
virtual void __stdcall v40();
virtual void __stdcall v41();
virtual void __stdcall v42();
virtual void __stdcall v43();
virtual void __stdcall v44();
virtual void __stdcall v45();
virtual void __stdcall v46();
virtual void __stdcall v47();
virtual void __stdcall v48();
virtual void __stdcall v49();
virtual void __stdcall v50();
virtual void __stdcall v51();
virtual void __stdcall v52();
virtual void __stdcall v53();
virtual void __stdcall v54();
virtual void __stdcall v55();
virtual void __stdcall v56();
virtual void __stdcall v57();
virtual void __stdcall v58();
virtual void __stdcall v59();
virtual void __stdcall v60();
virtual void __stdcall v61();
virtual void __stdcall v62();
virtual void __stdcall v63();
virtual void __stdcall v64();
virtual void __stdcall v65();
virtual void __stdcall v66();
virtual void __stdcall v67();
virtual void __stdcall v68();
virtual void __stdcall v69();
virtual void __stdcall v70();
virtual void __stdcall v71();
virtual void __stdcall v72();
virtual void __stdcall v73();
virtual void __stdcall v74();
virtual void __stdcall v75();
virtual void __stdcall v76();
virtual void __stdcall v77();
virtual void __stdcall v78();
virtual void __stdcall v79();
virtual void __stdcall v80();
virtual int __stdcall plain(unsigned int,unsigned int,unsigned int);
virtual int __stdcall indexed(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
};
struct State {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual void v21();
virtual void v22();
virtual void v23();
virtual void v24();
virtual void v25();
virtual void v26();
virtual void v27();
virtual void v28();
virtual void v29();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual void v36();
virtual void v37();
virtual void v38();
virtual void v39();
virtual void v40();
virtual void v41();
virtual void v42();
virtual void v43();
virtual void v44();
virtual void v45();
virtual void v46();
virtual void v47();
virtual void v48();
virtual void v49();
virtual void v50();
virtual void v51();
virtual void v52();
virtual void v53();
virtual void v54();
virtual void v55();
virtual void v56();
virtual void v57();
virtual void v58();
virtual void v59();
virtual void v60();
virtual void v61();
virtual void finish(unsigned int);
};
struct DrawOwner715 { unsigned int unk000;
unsigned int unk004;
unsigned int unk008; unsigned int unk00c,unk010; unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
unsigned int unk210;
unsigned int unk214;
unsigned int unk218;
unsigned int unk21c;
unsigned int unk220;
unsigned int unk224;
unsigned int unk228;
unsigned int unk22c;
unsigned int unk230;
unsigned int unk234;
unsigned int unk238;
unsigned int unk23c;
unsigned int unk240;
unsigned int unk244;
unsigned int unk248;
unsigned int unk24c;
unsigned int unk250;
unsigned int unk254;
unsigned int unk258;
unsigned int unk25c;
unsigned int unk260;
unsigned int unk264;
unsigned int unk268;
unsigned int unk26c;
unsigned int unk270;
unsigned int unk274;
unsigned int unk278;
unsigned int unk27c;
unsigned int unk280;
unsigned int unk284; Device* unk288; unsigned int unk28c;
unsigned int unk290;
unsigned int unk294;
unsigned int unk298;
unsigned int unk29c;
unsigned int unk2a0;
unsigned int unk2a4;
unsigned int unk2a8;
unsigned int unk2ac;
unsigned int unk2b0;
unsigned int unk2b4;
unsigned int unk2b8;
unsigned int unk2bc;
unsigned int unk2c0;
unsigned int unk2c4;
unsigned int unk2c8;
unsigned int unk2cc;
unsigned int unk2d0;
unsigned int unk2d4;
unsigned int unk2d8;
unsigned int unk2dc;
unsigned int unk2e0;
unsigned int unk2e4;
unsigned int unk2e8;
unsigned int unk2ec;
unsigned int unk2f0;
unsigned int unk2f4;
unsigned int unk2f8;
unsigned int unk2fc;
unsigned int unk300;
unsigned int unk304;
unsigned int unk308;
unsigned int unk30c;
unsigned int unk310;
unsigned int unk314;
unsigned int unk318;
unsigned int unk31c;
unsigned int unk320;
unsigned int unk324;
unsigned int unk328;
unsigned int unk32c;
unsigned int unk330;
unsigned int unk334;
unsigned int unk338;
unsigned int unk33c;
unsigned int unk340;
unsigned int unk344;
unsigned int unk348;
unsigned int unk34c;
unsigned int unk350;
unsigned int unk354;
unsigned int unk358;
unsigned int unk35c;
unsigned int unk360;
unsigned int unk364;
unsigned int unk368;
unsigned int unk36c;
unsigned int unk370;
unsigned int unk374;
unsigned int unk378;
unsigned int unk37c;
unsigned int unk380;
unsigned int unk384;
unsigned int unk388;
unsigned int unk38c;
unsigned int unk390;
unsigned int unk394;
unsigned int unk398;
unsigned int unk39c;
unsigned int unk3a0;
unsigned int unk3a4;
unsigned int unk3a8;
unsigned int unk3ac;
unsigned int unk3b0;
unsigned int unk3b4;
unsigned int unk3b8;
unsigned int unk3bc;
unsigned int unk3c0;
unsigned int unk3c4;
unsigned int unk3c8;
unsigned int unk3cc;
unsigned int unk3d0;
unsigned int unk3d4;
unsigned int unk3d8;
unsigned int unk3dc;
unsigned int unk3e0;
unsigned int unk3e4;
unsigned int unk3e8;
unsigned int unk3ec;
unsigned int unk3f0;
unsigned int unk3f4;
unsigned int unk3f8;
unsigned int unk3fc;
unsigned int unk400;
unsigned int unk404;
unsigned int unk408;
unsigned int unk40c;
unsigned int unk410;
unsigned int unk414;
unsigned int unk418;
unsigned int unk41c;
unsigned int unk420;
unsigned int unk424;
unsigned int unk428;
unsigned int unk42c;
unsigned int unk430;
unsigned int unk434;
unsigned int unk438;
unsigned int unk43c;
unsigned int unk440;
unsigned int unk444;
unsigned int unk448;
unsigned int unk44c;
unsigned int unk450;
unsigned int unk454;
unsigned int unk458;
unsigned int unk45c;
unsigned int unk460;
unsigned int unk464;
unsigned int unk468;
unsigned int unk46c;
unsigned int unk470;
unsigned int unk474;
unsigned int unk478;
unsigned int unk47c;
unsigned int unk480;
unsigned int unk484;
unsigned int unk488;
unsigned int unk48c;
unsigned int unk490;
unsigned int unk494;
unsigned int unk498;
unsigned int unk49c;
unsigned int unk4a0;
unsigned int unk4a4;
unsigned int unk4a8;
unsigned int unk4ac;
unsigned int unk4b0;
unsigned int unk4b4;
unsigned int unk4b8;
unsigned int unk4bc;
unsigned int unk4c0;
unsigned int unk4c4;
unsigned int unk4c8;
unsigned int unk4cc;
unsigned int unk4d0;
unsigned int unk4d4;
unsigned int unk4d8;
unsigned int unk4dc;
unsigned int unk4e0;
unsigned int unk4e4;
unsigned int unk4e8;
unsigned int unk4ec;
unsigned int unk4f0;
unsigned int unk4f4;
unsigned int unk4f8;
unsigned int unk4fc;
unsigned int unk500;
unsigned int unk504;
unsigned int unk508;
unsigned int unk50c;
unsigned int unk510;
unsigned int unk514;
unsigned int unk518;
unsigned int unk51c;
unsigned int unk520;
unsigned int unk524;
unsigned int unk528;
unsigned int unk52c;
unsigned int unk530;
unsigned int unk534;
unsigned int unk538;
unsigned int unk53c;
unsigned int unk540;
unsigned int unk544;
unsigned int unk548;
unsigned int unk54c;
unsigned int unk550;
unsigned int unk554;
unsigned int unk558;
unsigned int unk55c;
unsigned int unk560;
unsigned int unk564;
unsigned int unk568;
unsigned int unk56c;
unsigned int unk570;
unsigned int unk574;
unsigned int unk578;
unsigned int unk57c;
unsigned int unk580;
unsigned int unk584;
unsigned int unk588;
unsigned int unk58c;
unsigned int unk590;
unsigned int unk594;
unsigned int unk598;
unsigned int unk59c;
unsigned int unk5a0;
unsigned int unk5a4;
unsigned int unk5a8;
unsigned int unk5ac;
unsigned int unk5b0;
unsigned int unk5b4;
unsigned int unk5b8;
unsigned int unk5bc;
unsigned int unk5c0;
unsigned int unk5c4;
unsigned int unk5c8;
unsigned int unk5cc;
unsigned int unk5d0;
unsigned int unk5d4;
unsigned int unk5d8;
unsigned int unk5dc;
unsigned int unk5e0;
unsigned int unk5e4;
unsigned int unk5e8;
unsigned int unk5ec;
unsigned int unk5f0;
unsigned int unk5f4;
unsigned int unk5f8;
unsigned int unk5fc;
unsigned int unk600;
unsigned int unk604;
unsigned int unk608;
unsigned int unk60c;
unsigned int unk610;
unsigned int unk614;
unsigned int unk618;
unsigned int unk61c;
unsigned int unk620;
unsigned int unk624;
unsigned int unk628;
unsigned int unk62c;
unsigned int unk630;
unsigned int unk634;
unsigned int unk638;
unsigned int unk63c;
unsigned int unk640;
unsigned int unk644;
unsigned int unk648;
unsigned int unk64c;
unsigned int unk650;
unsigned int unk654;
unsigned int unk658;
unsigned int unk65c;
unsigned int unk660;
unsigned int unk664;
unsigned int unk668;
unsigned int unk66c;
unsigned int unk670;
unsigned int unk674;
unsigned int unk678;
unsigned int unk67c;
unsigned int unk680;
unsigned int unk684;
unsigned int unk688;
unsigned int unk68c;
unsigned int unk690;
unsigned int unk694;
unsigned int unk698;
unsigned int unk69c;
unsigned int unk6a0;
unsigned int unk6a4;
unsigned int unk6a8;
unsigned int unk6ac;
unsigned int unk6b0;
unsigned int unk6b4;
unsigned int unk6b8;
unsigned int unk6bc;
unsigned int unk6c0;
unsigned int unk6c4;
unsigned int unk6c8;
unsigned int unk6cc;
unsigned int unk6d0;
unsigned int unk6d4;
unsigned int unk6d8;
unsigned int unk6dc;
unsigned int unk6e0;
unsigned int unk6e4;
unsigned int unk6e8;
unsigned int unk6ec;
unsigned int unk6f0;
unsigned int unk6f4;
unsigned int unk6f8;
unsigned int unk6fc;
unsigned int unk700;
unsigned int unk704;
unsigned int unk708;
unsigned int unk70c;
unsigned int unk710;
unsigned int unk714;
unsigned int unk718;
unsigned int unk71c;
unsigned int unk720;
unsigned int unk724;
unsigned int unk728;
unsigned int unk72c;
unsigned int unk730;
unsigned int unk734;
unsigned int unk738;
unsigned int unk73c;
unsigned int unk740;
unsigned int unk744;
unsigned int unk748;
unsigned int unk74c;
unsigned int unk750;
unsigned int unk754;
unsigned int unk758;
unsigned int unk75c;
unsigned int unk760;
unsigned int unk764;
unsigned int unk768;
unsigned int unk76c;
unsigned int unk770;
unsigned int unk774;
unsigned int unk778;
unsigned int unk77c;
unsigned int unk780;
unsigned int unk784;
unsigned int unk788;
unsigned int unk78c;
unsigned int unk790;
unsigned int unk794;
unsigned int unk798;
unsigned int unk79c;
unsigned int unk7a0;
unsigned int unk7a4;
unsigned int unk7a8;
unsigned int unk7ac;
unsigned int unk7b0;
unsigned int unk7b4;
unsigned int unk7b8;
unsigned int unk7bc;
unsigned int unk7c0;
unsigned int unk7c4;
unsigned int unk7c8;
unsigned int unk7cc;
unsigned int unk7d0;
unsigned int unk7d4;
unsigned int unk7d8;
unsigned int unk7dc;
unsigned int unk7e0;
unsigned int unk7e4;
unsigned int unk7e8;
unsigned int unk7ec;
unsigned int unk7f0;
unsigned int unk7f4;
unsigned int unk7f8;
unsigned int unk7fc;
unsigned int unk800;
unsigned int unk804;
unsigned int unk808;
unsigned int unk80c;
unsigned int unk810;
unsigned int unk814;
unsigned int unk818;
unsigned int unk81c;
unsigned int unk820;
unsigned int unk824;
unsigned int unk828;
unsigned int unk82c;
unsigned int unk830;
unsigned int unk834;
unsigned int unk838;
unsigned int unk83c;
unsigned int unk840;
unsigned int unk844;
unsigned int unk848;
unsigned int unk84c;
unsigned int unk850;
unsigned int unk854;
unsigned int unk858;
unsigned int unk85c;
unsigned int unk860;
unsigned int unk864;
unsigned int unk868;
unsigned int unk86c;
unsigned int unk870;
unsigned int unk874;
unsigned int unk878;
unsigned int unk87c;
unsigned int unk880;
unsigned int unk884;
unsigned int unk888;
unsigned int unk88c;
unsigned int unk890;
unsigned int unk894;
unsigned int unk898;
unsigned int unk89c;
unsigned int unk8a0;
unsigned int unk8a4;
unsigned int unk8a8;
unsigned int unk8ac;
unsigned int unk8b0;
unsigned int unk8b4; State* unk8b8; void DrawMesh(Mesh*,unsigned int,unsigned int,void*,void*,Batch*); };
// Draws a mesh by iterating shader steps and submitting indexed or plain batches via unk288, handling skinned geometry per strip.
// @fnv 0x00e715a0
void DrawOwner715::DrawMesh(Mesh* mesh,unsigned int b,unsigned int c,void* B,void* A,Batch* batch) {
 Shader* shader=0;
 if(mesh) shader=mesh->unkc0;

 if(shader->step21(mesh,c,(unsigned int)batch,unk00c,unk010,B,A)) return;
 shader->step22(mesh,c,(unsigned int)batch,unk00c,unk010,B,A);
 if(shader->step36()) do {
 shader->step23(mesh,c,(unsigned int)batch,unk00c,unk010,B,A);
 shader->step24(mesh,c,0,batch,unk00c,unk010,B,A);
 batch=shader->batch(mesh,0,(unsigned int)batch,unk00c);
 shader->step26(mesh,c,0,batch,unk00c,unk010,B,A);
 if(batch->unk34) {
 unsigned int start=0;
 for(unsigned int strip=0;strip<batch->unk48;++strip) {
 unsigned int count;
 if(batch->unk4c) count=batch->unk4c[strip]-2;
 else { count=batch->unk40; if(mesh->geometry()) count=mesh->geometry()->unkc4; }
 if(mesh->skin()) {
 Skin* skin=mesh->skin();
 unsigned int n=skin->GetCount();
 
 if(n) for(unsigned int j=0;j<n;++j) {
 if(skin->GetPiece(j)->unk10) {
 Piece* piece=skin->GetPiece(j);
 unk288->indexed(batch->unk3c,batch->unk38,0,batch->unk18,skin->GetStart(piece),skin->GetNum(piece));
 }
 }
 } else unk288->indexed(batch->unk3c,batch->unk38,0,batch->unk18,start,count);
 start+=count+2;
 }
 } else unk288->plain(batch->unk3c,batch->unk38,batch->unk40);
 shader->step28(mesh,c,0,batch,unk00c,unk010,B,A);
 } while(shader->step37());
 shader->step29(mesh,c,(unsigned int)batch,unk00c,unk010,B,A);
 unk8b8->finish(0);
}

// This implementation incorporates earlier contributors' hash-map identification (2026-10-25).
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ReferenceObject { virtual void Unknown(); virtual void DeleteThis(); volatile long referenceCount; };
struct ReferencePtr {
    ReferenceObject* object;
    ReferencePtr(const ReferencePtr& other) : object(other.object) {
        if(object) InterlockedIncrement(&object->referenceCount);
    }
};
struct MapEntry { MapEntry* next; unsigned int key; ReferencePtr resource; };
class RendererPacketMap {
public:
    virtual void unknown0();
    virtual unsigned int Bucket(unsigned int key);
    virtual bool Equal(unsigned int a,unsigned int b);
    virtual void Assign(MapEntry* entry,unsigned int key,ReferencePtr value);
    virtual void unknown4();
    virtual MapEntry* CreateEntry();
    unsigned int unknown4_field;
    MapEntry** entries;
    unsigned int count;
    void SetMapEntryWithReferenceCounting(unsigned int key, ReferencePtr value);
};
// Inserts or updates a key/value pair in the hash map, managing reference counts on the stored object.
// @fnv 0x00e72cf0
// src: GUESS 0x00e72cf0 (confidence: high)
void RendererPacketMap::SetMapEntryWithReferenceCounting(unsigned int key, ReferencePtr value) {
    unsigned int bucket = Bucket(key);
    MapEntry* entry = entries[bucket];
    for (; entry; entry=entry->next) {
        if (!Equal(key, entry->key)) continue;
        ReferenceObject* previous = entry->resource.object;
        long (__stdcall *pDecrement)(volatile long*) = &InterlockedDecrement;
        if (previous != value.object) {
            if (previous && !pDecrement(&previous->referenceCount))
                previous->DeleteThis();
            entry->resource.object = value.object;
            if (value.object)
                InterlockedIncrement(&value.object->referenceCount);
        }
        if (value.object) {
            ReferenceObject* ptr = value.object;
            if (!pDecrement(&ptr->referenceCount)) ptr->DeleteThis();
        }
        return;
    }
    entry = CreateEntry();
    Assign(entry, key, value);
    entry->next = entries[bucket];
    entries[bucket] = entry;
    ++count;
    if (value.object) {
        ReferenceObject* ptr = value.object;
        if (!InterlockedDecrement(&ptr->referenceCount)) ptr->DeleteThis();
    }
}

namespace fnv_00e73eb0 {
extern "C" void* __cdecl memmove(void* pvDst, const void* pvSrc, unsigned int uiSize);

void __cdecl Object_DoNothing(const char* pcMessage);

struct PresentParamsE73E {
    unsigned int m_uiBackBufferWidth;
    unsigned int m_uiBackBufferHeight;
    unsigned int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34;
};

struct DeviceDescE73E {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    PresentParamsE73E m_kPresentParams;
};

class AdapterE73E {
public:
    DeviceDescE73E* ContainsNode(GlobalObjectO2_00a7b610* pkKey);
};

struct AdapterSlotE73E {
    unsigned int unk00, unk04, unk08, unk0C;
    AdapterE73E* m_pkAdapter;
};

class AdapterListE73E {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual AdapterSlotE73E* GetSlot(int iIndex);
};

class DX9RendererE73E {
public:
    unsigned char unk000[0x884];
    AdapterListE73E* m_pkAdapterList;

    bool RendererRecreateHook();
    int NiDX9Renderer_Recreate_(unsigned int uiWidth, unsigned int uiHeight);
};

// Saves current present params, sets new back buffer size, calls FUN_00e736b0, and restores params on failure.
// @fnv 0x00e73eb0
// src: COMMUNITY 0x00e73eb0
int DX9RendererE73E::NiDX9Renderer_Recreate_(unsigned int uiWidth, unsigned int uiHeight)
{
    AdapterSlotE73E* pkSlot = m_pkAdapterList->GetSlot(0);
    DeviceDescE73E* pkDesc = !pkSlot->m_pkAdapter ? 0 : pkSlot->m_pkAdapter->ContainsNode(&g_0126f5d8);
    PresentParamsE73E* pkParams = &pkDesc->m_kPresentParams;
    PresentParamsE73E kSaved;
    memmove(&kSaved, pkParams, sizeof(PresentParamsE73E));
    pkParams->m_uiBackBufferWidth = uiWidth;
    pkParams->m_uiBackBufferHeight = uiHeight;
    if (!RendererRecreateHook()) {
        Object_DoNothing("NiDX9Renderer::Recreate> Could not reset device to desired parameters - trying to recover original values\n");
        memmove(pkParams, &kSaved, sizeof(PresentParamsE73E));
        if (!RendererRecreateHook()) {
            Object_DoNothing("NiDX9Renderer::Recreate> Could not recover original presentation parameters\n");
            return 0;
        }
        return 1;
    }
    return 2;
}
}  // namespace fnv_00e73eb0

struct S00e76450_Entry { int unk00; int unk04; int b; int c; int f; int d; int e; };
struct S00e76450_Row { int unk00; int unk04; S00e76450_Entry* entries; int unk0c; };
struct S00e76450_Callback { virtual void v0(); virtual void v1(); virtual void v2(); };
struct S00e76450_Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18;
    unsigned int count;
    unsigned int dim;
    S00e76450_Row* rows;
    unsigned char flag;
    int unk2c;
    S00e76450_Callback* callback;
    bool NiDX9ShaderDeclaration_SetEntryAlt(unsigned int x, unsigned int y, int a, int b, int c, int d, int e, int f);
};

// @fnv 0x00e76450
// src: COMMUNITY 0x00e76450
bool S00e76450_Obj::NiDX9ShaderDeclaration_SetEntryAlt(unsigned int x, unsigned int y, int aiUnused, int b, int c, int d, int e, int f)
{
    if (y >= count) return false;
    if (x >= dim) return false;
    S00e76450_Entry* entry = rows[x].entries + y;
    if (entry->b != b || entry->c != c || entry->d != d || entry->e != e || entry->f != f) {
        entry->b = b;
        entry->c = c;
        entry->d = d;
        entry->e = e;
        entry->f = f;
        if (b == 1 && c != 0x10) entry->c = 2;
        flag = 1;
        if (callback) {
            void (__stdcall* fn)(S00e76450_Callback*) = (void (__stdcall*)(S00e76450_Callback*))((void**)*(void**)callback)[2];
            fn(callback);
            callback = 0;
        }
    }
    return true;
}

void* __cdecl FUN_00ec44d0(void*, const void*, unsigned int);

// Copies or zeroes count destination elements using strides and optional indices, then returns the accumulated element sizes.
// @fnv 0x00e78f80
// src: COMMUNITY 0x00e78f80
unsigned int __cdecl NiD3DShaderDeclaration_Pack_FloatToFloat(Stream_e78910* apStream)
{
    unsigned int total = 0;
    unsigned short* indices = apStream->indices;
    char* dest = apStream->dst;
    char* source = apStream->src;
    if (source == 0)
    {
        for (unsigned short i = 0; i < apStream->count; ++i)
        {
            FUN_00ec61c0(dest, 0, apStream->elemSize);
            dest += apStream->dstStride;
            total += apStream->elemSize;
        }
    }
    else if (indices != 0)
    {
        for (unsigned short i = 0; i < apStream->count;)
        {
            const char* p = source + indices[i] * apStream->srcStride;
            ++i;
            FUN_00ec44d0(dest, p, apStream->unk14);
            dest += apStream->dstStride;
            total += apStream->elemSize;
        }
    }
    else
    {
    unsigned int srcStride = apStream->srcStride;
    unsigned int dstStride = apStream->dstStride;
    unsigned int elemSize = apStream->elemSize;
    unsigned int count = apStream->count;
    unsigned int size = apStream->unk14;
    unsigned int i;
    switch (size)
    {
    case 8:
        for (i = 0; i < count; ++i)
        {
            ((unsigned int*)dest)[0] = ((unsigned int*)source)[0];
            ((unsigned int*)dest)[1] = ((unsigned int*)source)[1];
            source += srcStride;
            dest += dstStride;
            total += elemSize;
        }
        break;
    case 12:
        for (i = 0; i < count; ++i)
        {
            ((unsigned int*)dest)[0] = ((unsigned int*)source)[0];
            ((unsigned int*)dest)[1] = ((unsigned int*)source)[1];
            ((unsigned int*)dest)[2] = ((unsigned int*)source)[2];
            source += srcStride;
            dest += dstStride;
            total += elemSize;
        }
        break;
    case 16:
        for (i = 0; i < count; ++i)
        {
            ((unsigned int*)dest)[0] = ((unsigned int*)source)[0];
            ((unsigned int*)dest)[1] = ((unsigned int*)source)[1];
            ((unsigned int*)dest)[2] = ((unsigned int*)source)[2];
            ((unsigned int*)dest)[3] = ((unsigned int*)source)[3];
            source += srcStride;
            dest += dstStride;
            total += elemSize;
        }
        break;
    default:
        for (i = 0; i < apStream->count; ++i)
        {
            FUN_00ec44d0(dest, source, apStream->unk14);
            dest += dstStride;
            total += elemSize;
            source += srcStride;
        }
        break;
    }
    }
    return total;
}

struct PixRow_00e79760 {
  unsigned short m_w0;        // +0x00
  unsigned short m_w2;        // +0x02
  unsigned short m_w4;        // +0x04
  unsigned short m_w6;        // +0x06
  unsigned short m_uiItemCount;     // +0x08
  unsigned short m_w0a;       // +0x0a
  unsigned short* m_uiEdgeIndex;    // +0x0c
  unsigned int m_srcBase;     // +0x10
  unsigned int m_unk14;       // +0x14
  unsigned int m_srcStride;   // +0x18
  unsigned int m_rowSize;     // +0x1c
  unsigned int m_dstStride;   // +0x20
  unsigned int m_unk24;       // +0x24
  unsigned int m_unk28;       // +0x28
  char* m_dst;                // +0x2c
};

// Converts available 16-bit values to floats, zero-fills remaining output values, and returns the accumulated row sizes.
// @fnv 0x00e79760
// src: COMMUNITY 0x00e79760
unsigned int NiD3DShaderDeclaration_Pack_UnsignedShortToFloat(PixRow_00e79760* r)
{
  unsigned int total = 0;
  unsigned int base = r->m_srcBase;
  unsigned short* index = r->m_uiEdgeIndex;
  char* dst = r->m_dst;

  if (base == 0) {
    for (unsigned short i = 0; i < r->m_uiItemCount; i++) {
      FUN_00ec61c0(dst, 0, r->m_rowSize);
      dst += r->m_dstStride;
      total += r->m_rowSize;
    }
    return total;
  }

  unsigned short uiAvailWidth = r->m_w4 - 16;
  unsigned short width = r->m_w0 + 1;
  unsigned short n = uiAvailWidth > width ? width : uiAvailWidth;

  if (index != 0) {
    unsigned short idx = 0;
    for (unsigned short i = 0; i < r->m_uiItemCount; i++) {
      unsigned short* p = (unsigned short*)(index[idx++] * r->m_srcStride + base);
      float* d = (float*)dst;
      unsigned short j = 0;
      for (; j < n; j++)
        *d++ = (float)(*p++ / 65535.0);
      for (; j < width; j++)
        *d++ = 0.0f;
      total += r->m_rowSize;
      dst += r->m_dstStride;
    }
  } else {
    for (unsigned short i = 0; i < r->m_uiItemCount; i++) {
      unsigned short* p = (unsigned short*)base;
      float* d = (float*)dst;
      unsigned short j = 0;
      for (; j < n; j++)
        *d++ = (float)(*p++ / 65535.0);
      for (; j < width; j++)
        *d++ = 0.0f;
      total += r->m_rowSize;
      base += r->m_srcStride;
      dst += r->m_dstStride;
    }
  }
  return total;
}

// @fnv 0x00e79d00
// src: COMMUNITY 0x00e79d00
unsigned int NiD3DShaderDeclaration_Pack_FloatToUByteColor(NormalizedStream* s)
{
    unsigned char* source = s->source;
    unsigned short* indices = s->indices;
    unsigned char* dest = s->dest;
    unsigned int size = 0;
    if (!source) {
        unsigned short i = 0;
        if (i < s->vertices) {
            float a = 255.0f, r = 255.0f, g = 255.0f, b = 255.0f;
            do {
                *(unsigned int*)dest = ((((unsigned int)fnv_FloatToInt(a) << 8) | (unsigned int)fnv_FloatToInt(r)) << 8 | (unsigned int)fnv_FloatToInt(g)) << 8 | (unsigned int)fnv_FloatToInt(b);
                dest += s->destStride;
                size += s->elementSize;
            } while (++i < s->vertices);
        }
    } else {
        unsigned short components = s->type;
        if (indices) {
            unsigned short index = 0;
            for (unsigned short i = 0; i < s->vertices; ++i) {
                const float* v = (const float*)(source + indices[index++] * s->sourceStride);
                float a = components == 3 ? 1.0f : v[3];
                *(unsigned int*)dest = ((((unsigned int)fnv_FloatToInt((float)(a * 255.0)) << 8) | (unsigned int)fnv_FloatToInt((float)(v[0] * 255.0))) << 8 | (unsigned int)fnv_FloatToInt((float)(v[1] * 255.0))) << 8 | (unsigned int)fnv_FloatToInt((float)(v[2] * 255.0));
                dest += s->destStride;
                size += s->elementSize;
            }
        } else {
            for (unsigned short i = 0; i < s->vertices; ++i) {
                const float* v = (const float*)source;
                float a = components == 3 ? 1.0f : v[3];
                *(unsigned int*)dest = ((((unsigned int)fnv_FloatToInt((float)(a * 255.0)) << 8) | (unsigned int)fnv_FloatToInt((float)(v[0] * 255.0))) << 8 | (unsigned int)fnv_FloatToInt((float)(v[1] * 255.0))) << 8 | (unsigned int)fnv_FloatToInt((float)(v[2] * 255.0));
                source += s->sourceStride;
                dest += s->destStride;
                size += s->elementSize;
            }
        }
    }
    return size;
}

class DepthStencilE7B {
public:
    unsigned int m_uiKey;
    void* FindBestFullscreenFormat(unsigned int uiFormat, unsigned int uiDepthBits, unsigned int uiStencilBits);
};



template <class T>
class PointerListE7B {
public:
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* GetHeadPos() const { return m_pkHead; }
    T& GetNext(NiTListItem<T>*& kPos) const
    {
        T& element = kPos->m_element;
        kPos = kPos->m_pkNext;
        return element;
    }
};

// Format lookup at 0x00e7b0f0 walks a list at 0x134; Xbox Renderer is an unrelated one-byte class.
class DepthStencilFormatRegistry {
public:
    int unk000[0x134 / 4];
    PointerListE7B<DepthStencilE7B*> m_kBuffers;

    void* NiDX9SystemDesc_GetNearestDepthStencilFormat(unsigned int uiKey, unsigned int uiFormat, unsigned int uiDepthBits,
        unsigned int uiStencilBits);
};

// Searches m_kBuffers for a matching key, adjusts the bit-count arguments under conditions, and returns FindBestFullscreenFormat's result.
// @fnv 0x00e7b0f0
// src: COMMUNITY 0x00e7b0f0
void* DepthStencilFormatRegistry::NiDX9SystemDesc_GetNearestDepthStencilFormat(unsigned int uiBufferKey, unsigned int uiFormat, unsigned int uiDepthBits,
    unsigned int uiStencilBits)
{
    NiTListItem<DepthStencilE7B*>* kPos = m_kBuffers.GetHeadPos();
    while (kPos) {
        DepthStencilE7B* pkBuffer = m_kBuffers.GetNext(kPos);
        if (pkBuffer->m_uiKey == uiBufferKey) {
            if (uiStencilBits) {
                if (uiDepthBits > 16) {
                    uiDepthBits = 24;
                    if (uiStencilBits != 1)
                        uiStencilBits = 8;
                } else if (uiStencilBits != 1) {
                    uiDepthBits = 24;
                    uiStencilBits = 8;
                } else {
                    uiDepthBits = 15;
                    uiStencilBits = 1;
                }
            }
            return pkBuffer->FindBestFullscreenFormat(uiFormat, uiDepthBits, uiStencilBits);
        }
    }
    return 0;
}

struct FUN_00e69610_Packet {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
};
struct FUN_00e69610_Obj {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
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
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    FUN_00e69610_Packet* m_pAssociatedPacket;
    void NiDX9Renderer_GetDefaultDepthStencilBuffer();
};
// @fnv 0x00e69610
// src: COMMUNITY 0x00e69610
void FUN_00e69610_Obj::NiDX9Renderer_GetDefaultDepthStencilBuffer()
{
    m_pAssociatedPacket->v45();
}

// @fnv 0x00e69e50
// src: GAMEBRYO_LIB 0x00e69e50
unsigned int NiDX9Renderer_GetPresentInterval(int format)
{
    switch (format)
    {
    case 0: return 0x80000000u;
    case 1: return 1;
    case 2: return 2;
    case 3: return 4;
    case 4: return 8;
    default: return 0;
    }
}

struct StripRecord {
    int unk00, unk04, unk08, unk0c;
    int count;
    unsigned short start;
    unsigned short unk16;
    int unk18, unk1c;

    int Wrap(int i)
    {
        int r = i % count;
        if (r < 0)
            r += count;
        return r;
    }
};

struct ColorF {
    float r, g, b, a;
};

struct SrcObj {
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    unsigned short rows;
    unsigned short unk52;
    int unk54, unk58, unk5C, unk60;
    const unsigned char* alphas;
    int unk68, unk6C, unk70, unk74, unk78;
    StripRecord* strips;

    StripRecord* GetStrip(int i) { return &strips[i]; }

    unsigned short BSStripPSysData_GetPointCount(unsigned short row);
    unsigned short BSStripPSysData_GetMaxPointCount();
    float BSStripPSysData_GetTexCoordDelta(unsigned short row);
    const NiPoint3* GetElementField(unsigned short row, unsigned short col);
    const NiPoint3* BSStripPSysData_GetPointNorms(unsigned short row, unsigned short col);
    const ColorF* GetParticleColor(unsigned short row, unsigned short col);
};

static inline int WrapIndex(int i, int n)
{
    int r = i % n;
    if (r < 0)
        r += n;
    return r;
}

struct MeshGenerator {
    float* WriteVertex(float* pDest, const NiPoint3& kPos, const NiPoint3& kNormal, unsigned int uiColor, float fTextureCoordinateU, float fV, float fW);
    void NiDX9Renderer_PackParticleStrips(float* pDest, unsigned short* pIndex, SrcObj* pSrc, unsigned int* puiVerts, unsigned int* puiIndices);
};

// @fnv 0x00e6d3a0
// src: COMMUNITY 0x00e6d3a0
void MeshGenerator::NiDX9Renderer_PackParticleStrips(float* pDest, unsigned short* pIndex, SrcObj* pSrc, unsigned int* puiVerts, unsigned int* puiIndices)
{
    const unsigned char* pAlpha = pSrc->alphas;
    unsigned int uiVerts = 0;
    unsigned int uiExtra = 0;
    unsigned short usRows = pSrc->rows;
    unsigned int uiIndex = 0;
    bool bEffectFlag = false;

    for (unsigned short usRow = 0; usRow < usRows; usRow++) {
        unsigned short m_usPassCountLocal = pSrc->BSStripPSysData_GetPointCount(usRow);
        if (m_usPassCountLocal >= 2) {
            if (bEffectFlag) {
                *pIndex++ = (unsigned short)(uiIndex - 1);
                *pIndex++ = (unsigned short)uiIndex;
                uiExtra += 2;
            } else {
                bEffectFlag = true;
            }

            pSrc->BSStripPSysData_GetMaxPointCount();
            pSrc->BSStripPSysData_GetTexCoordDelta(usRow);
            float fV = 0.0f;
            float fStep = pSrc->BSStripPSysData_GetTexCoordDelta(usRow);

            unsigned short usBase = (unsigned short)(uiIndex + 2);
            unsigned short usCol = pSrc->strips[usRow].start;

            for (unsigned short i = 0; i < m_usPassCountLocal; i++) {
                uiVerts += 4;
                const NiPoint3* pPos = pSrc->GetElementField(usRow, usCol);
                const NiPoint3* pNorm = pSrc->BSStripPSysData_GetPointNorms(usRow, usCol);

                unsigned int uiColor = (((fnv_FloatToInt(pSrc->GetParticleColor(usRow, usCol)->a * 255.0) << 8 | fnv_FloatToInt(pSrc->GetParticleColor(usRow, usCol)->r * 255.0)) << 8 | fnv_FloatToInt(pSrc->GetParticleColor(usRow, usCol)->g * 255.0)) << 8) | fnv_FloatToInt(pSrc->GetParticleColor(usRow, usCol)->b * 255.0);

                float fW = pAlpha ? (float)pAlpha[usRow] : -1.0f;

                pDest = WriteVertex(pDest, pPos[0], pNorm[0], uiColor, fV, 0.0f, fW);
                pDest = WriteVertex(pDest, pPos[1], pNorm[0], uiColor, fV, 1.0f, fW);
                pDest = WriteVertex(pDest, pPos[2], pNorm[1], uiColor, fV, 0.0f, fW);
                pDest = WriteVertex(pDest, pPos[3], pNorm[1], uiColor, fV, 1.0f, fW);
                fV += fStep;

                *pIndex++ = (unsigned short)uiIndex++;
                *pIndex++ = (unsigned short)uiIndex;
                uiIndex += 3;

                usCol = (unsigned short)pSrc->strips[usRow].Wrap(usCol + 1);
            }

            uiExtra += 2;
            *pIndex++ = (unsigned short)(uiIndex - 3);
            *pIndex++ = usBase;
            for (unsigned short j = 0; j < m_usPassCountLocal; j++) {
                *pIndex++ = usBase;
                *pIndex++ = (unsigned short)(usBase + 1);
                usBase += 4;
            }
        }
    }

    *puiVerts = uiVerts;
    *puiIndices = uiExtra + uiVerts;
}

struct XPoint3 {
    float x, y, z;
    XPoint3() {}
    XPoint3(float fX, float fY, float fZ) { x = fX; y = fY; z = fZ; }
};
struct XMatrix3 {
    float m[3][3];
    XMatrix3 operator*(float fScalar) const
    {
        XMatrix3 result;
        result.m[0][0] = m[0][0] * fScalar;
        result.m[0][1] = m[0][1] * fScalar;
        result.m[0][2] = m[0][2] * fScalar;
        result.m[1][0] = m[1][0] * fScalar;
        result.m[1][1] = m[1][1] * fScalar;
        result.m[1][2] = m[1][2] * fScalar;
        result.m[2][0] = m[2][0] * fScalar;
        result.m[2][1] = m[2][1] * fScalar;
        result.m[2][2] = m[2][2] * fScalar;
        return result;
    }
};
struct XTransform {
    XMatrix3 m_kOrientation;
    XPoint3 m_kTranslation;
    float m_fScale;
};

inline XPoint3 operator*(const XPoint3& pt, const XMatrix3& mat)
{
    return XPoint3(
        pt.x * mat.m[0][0] + pt.y * mat.m[1][0] + pt.z * mat.m[2][0],
        pt.x * mat.m[0][1] + pt.y * mat.m[1][1] + pt.z * mat.m[2][1],
        pt.x * mat.m[0][2] + pt.y * mat.m[1][2] + pt.z * mat.m[2][2]);
}
struct XD3DMatrix { float f00; };

void __cdecl ConvertNiToD3D(XD3DMatrix* out, const XMatrix3* rot, const XPoint3* trans, float scale);

struct XDevice {
    virtual void __stdcall d00(); virtual void __stdcall d01(); virtual void __stdcall d02(); virtual void __stdcall d03();
    virtual void __stdcall d04(); virtual void __stdcall d05(); virtual void __stdcall d06(); virtual void __stdcall d07();
    virtual void __stdcall d08(); virtual void __stdcall d09(); virtual void __stdcall d10(); virtual void __stdcall d11();
    virtual void __stdcall d12(); virtual void __stdcall d13(); virtual void __stdcall d14(); virtual void __stdcall d15();
    virtual void __stdcall d16(); virtual void __stdcall d17(); virtual void __stdcall d18(); virtual void __stdcall d19();
    virtual void __stdcall d20(); virtual void __stdcall d21(); virtual void __stdcall d22(); virtual void __stdcall d23();
    virtual void __stdcall d24(); virtual void __stdcall d25(); virtual void __stdcall d26(); virtual void __stdcall d27();
    virtual void __stdcall d28(); virtual void __stdcall d29(); virtual void __stdcall d30(); virtual void __stdcall d31();
    virtual void __stdcall d32(); virtual void __stdcall d33(); virtual void __stdcall d34(); virtual void __stdcall d35();
    virtual void __stdcall d36(); virtual void __stdcall d37(); virtual void __stdcall d38(); virtual void __stdcall d39();
    virtual void __stdcall d40(); virtual void __stdcall d41(); virtual void __stdcall d42(); virtual void __stdcall d43();
    virtual long __stdcall SetTransform(unsigned int state, const XD3DMatrix* mat);
};

struct XRenderState {
    virtual void r00(); virtual void r01(); virtual void r02(); virtual void r03();
    virtual void r04(); virtual void r05(); virtual void r06(); virtual void r07();
    virtual void r08(); virtual void r09(); virtual void r10(); virtual void r11();
    virtual void ApplyObjectTransform(const XTransform& kXform);
};
struct XRenderer {
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
    XDevice* m_pDirect3DDevice;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    XPoint3 m_kCameraPosition;
    XPoint3 m_kCameraDirection;
    XPoint3 m_kCameraUp;
    XPoint3 m_kCameraRight;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    XRenderState* m_pCurrentRenderState;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    XD3DMatrix m_kFirstShadowMatrix;
    void NiDX9Renderer_SetModelTransform(const XTransform& kXform, bool bPush);
};

// Converts kXform to m_kFirstShadowMatrix, optionally pushes it to the D3D device, applies it to the render state, and updates m_kCameraUp and m_kCameraRight.
// @fnv 0x00e6fbb0
// src: COMMUNITY 0x00e6fbb0
void XRenderer::NiDX9Renderer_SetModelTransform(const XTransform& kXform, bool bPush)
{
    ConvertNiToD3D(&m_kFirstShadowMatrix, &kXform.m_kOrientation, &kXform.m_kTranslation, kXform.m_fScale);
    if (bPush)
        m_pDirect3DDevice->SetTransform(0x100, &m_kFirstShadowMatrix);
    m_pCurrentRenderState->ApplyObjectTransform(kXform);

    XMatrix3 kRotScale = kXform.m_kOrientation * kXform.m_fScale;
    m_kCameraUp = m_kCameraPosition * kRotScale;
    m_kCameraRight = m_kCameraDirection * kRotScale;
}

struct Rgb {unsigned int r,g,b;};
struct Geometry;struct Shape;struct StripMesh;struct RenderData;struct Color { unsigned int r,g,b;float a; };
struct StripShader {
 virtual void v0();
 virtual void v4();
 virtual void v8();
 virtual void vc();
 virtual void v10();
 virtual void v14();
 virtual void v18();
 virtual void v1c();
 virtual void v20();
 virtual void v24();
 virtual void v28();
 virtual void v2c();
 virtual void v30();
 virtual void v34();
 virtual void v38();
 virtual void v3c();
 virtual void v40();
 virtual void v44();
 virtual void v48();
 virtual void v4c();
 virtual void v50();
 virtual unsigned int v54(Geometry*,Shape*,RenderData*,void*,void*,void*,Color*);
 virtual void v58(Geometry*,Shape*,RenderData*,void*,void*,void*,Color*);
 virtual void v5c(Geometry*,Shape*,RenderData*,void*,void*,void*,Color*);
 virtual void v60(Geometry*,Shape*,StripMesh*,RenderData*,void*,void*,void*,Color*);
 virtual void v64(Geometry*,Shape*,StripMesh*,RenderData*,void*,void*,void*,Color*);
 virtual void v68(Geometry*,Shape*,StripMesh*,RenderData*,void*,void*,void*,Color*);
 virtual RenderData* v6c(Geometry*,StripMesh*,RenderData*,void*);
 virtual void v70(Geometry*,Shape*,StripMesh*,RenderData*,void*,void*,void*,Color*);
 virtual void v74(Geometry*,Shape*,RenderData*,void*,void*,void*,Color*);
 virtual void v78();
 virtual void v7c();
 virtual void v80();
 virtual void v84();
 virtual void v88();
 virtual void v8c();
 virtual unsigned int v90();
 virtual unsigned int v94();
};
struct RenderData {
 unsigned int unk0;
 unsigned int unk4;
 unsigned int unk8;
 unsigned int unkc;
 unsigned int unk10;
 unsigned int unk14;
 unsigned int unk18;
 unsigned int unk1c;
 unsigned int unk20;
 unsigned int unk24;
 unsigned int unk28;
 unsigned int unk2c;
 unsigned int unk30;
 unsigned int unk34;
 unsigned int unk38;
 unsigned int unk3c;
 unsigned int unk40;
 unsigned int unk44;
 unsigned int unk48;
 unsigned short* unk4c;
};
struct Geometry {
 int unk0;
 int unk4;
 int unk8;
 int unkc;
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
 int unk58;
 int unk5c;
 int unk60;
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
 int unkb8;
 int unkbc;
 StripShader* shader; };
struct StripMesh {
 int unk0;
 int unk4;
 int unk8;
 int unkc;
 int unk10;
 int unk14;
 int unk18;
 unsigned short vertices,unk1e;
 unsigned short unk20,strip;
 int unk24;
 RenderData* unk28; RenderData* GetData(){return unk28;}
};
struct Block { int unk0,unk4;unsigned int count;StripMesh* meshes; };
struct Vis { unsigned char active,nextState,unk2,unk3; };
extern int DAT_011f49d8;
struct Shape {virtual void v0();virtual void v4();virtual void* GetRTTI();int unk4,unk8;Block* block;int unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34;Vis* visibility; bool IsKind(); };
bool IsExact(void* type,Shape* p) { if(p) return p->GetRTTI()==type; return false; }
struct Flags {int unk0,unk4,unk8;unsigned short unkc,flags;};
struct StripState {
 virtual void v0();
 virtual void v4();
 virtual void v8();
 virtual void vc();
 virtual void v10();
 virtual void v14();
 virtual void v18();
 virtual void v1c();
 virtual void v20();
 virtual void v24();
 virtual void v28();
 virtual void v2c();
 virtual void v30();
 virtual void v34();
 virtual void v38();
 virtual void v3c();
 virtual void v40();
 virtual void v44();
 virtual void v48();
 virtual void v4c();
 virtual void v50();
 virtual void v54();
 virtual void v58();
 virtual void v5c();
 virtual void v60();
 virtual void v64();
 virtual void v68();
 virtual void v6c();
 virtual void v70();
 virtual void v74();
 virtual void v78();
 virtual void v7c();
 virtual void v80();
 virtual void v84();
 virtual void v88();
 virtual void v8c();
 virtual void v90();
 virtual void v94();
 virtual void v98();
 virtual void v9c();
 virtual void va0();
 virtual void va4();
 virtual void va8();
 virtual void vac();
 virtual void vb0();
 virtual void vb4();
 virtual void vb8();
 virtual void vbc();
 virtual void vc0();
 virtual void vc4();
 virtual void vc8();
 virtual void vcc();
 virtual void vd0();
 virtual void vd4();
 virtual void vd8();
 virtual void vdc();
 virtual void ve0();
 virtual void ve4();
 virtual void ve8();
 virtual void vec();
 virtual void vf0();
 virtual void vf4();
 virtual void vf8(int);
};
struct StripTarget { 
 unsigned int unk0;
 unsigned int unk4;
 unsigned int unk8;
 void* unkc;
 void* unk10;
 unsigned int unk14;
 unsigned int unk18;
 unsigned int unk1c;
 unsigned int unk20;
 unsigned int unk24;
 unsigned int unk28;
 unsigned int unk2c;
 unsigned int unk30;
 unsigned int unk34;
 unsigned int unk38;
 unsigned int unk3c;
 unsigned int unk40;
 unsigned int unk44;
 unsigned int unk48;
 unsigned int unk4c;
 unsigned int unk50;
 unsigned int unk54;
 unsigned int unk58;
 unsigned int unk5c;
 unsigned int unk60;
 unsigned int unk64;
 unsigned int unk68;
 unsigned int unk6c;
 unsigned int unk70;
 unsigned int unk74;
 unsigned int unk78;
 unsigned int unk7c;
 unsigned int unk80;
 unsigned int unk84;
 unsigned int unk88;
 unsigned int unk8c;
 unsigned int unk90;
 unsigned int unk94;
 unsigned int unk98;
 unsigned int unk9c;
 unsigned int unka0;
 unsigned int unka4;
 unsigned int unka8;
 unsigned int unkac;
 unsigned int unkb0;
 unsigned int unkb4;
 unsigned int unkb8;
 unsigned int unkbc;
 unsigned int unkc0;
 unsigned int unkc4;
 unsigned int unkc8;
 unsigned int unkcc;
 unsigned int unkd0;
 unsigned int unkd4;
 unsigned int unkd8;
 unsigned int unkdc;
 unsigned int unke0;
 unsigned int unke4;
 unsigned int unke8;
 unsigned int unkec;
 unsigned int unkf0;
 unsigned int unkf4;
 unsigned int unkf8;
 unsigned int unkfc;
 unsigned int unk100;
 unsigned int unk104;
 unsigned int unk108;
 unsigned int unk10c;
 unsigned int unk110;
 unsigned int unk114;
 unsigned int unk118;
 unsigned int unk11c;
 unsigned int unk120;
 unsigned int unk124;
 unsigned int unk128;
 unsigned int unk12c;
 unsigned int unk130;
 unsigned int unk134;
 unsigned int unk138;
 unsigned int unk13c;
 unsigned int unk140;
 unsigned int unk144;
 unsigned int unk148;
 unsigned int unk14c;
 unsigned int unk150;
 unsigned int unk154;
 unsigned int unk158;
 unsigned int unk15c;
 unsigned int unk160;
 unsigned int unk164;
 unsigned int unk168;
 unsigned int unk16c;
 unsigned int unk170;
 unsigned int unk174;
 unsigned int unk178;
 unsigned int unk17c;
 unsigned int unk180;
 unsigned int unk184;
 unsigned int unk188;
 unsigned int unk18c;
 unsigned int unk190;
 unsigned int unk194;
 unsigned int unk198;
 unsigned int unk19c;
 unsigned int unk1a0;
 unsigned int unk1a4;
 unsigned int unk1a8;
 unsigned int unk1ac;
 unsigned int unk1b0;
 unsigned int unk1b4;
 unsigned int unk1b8;
 unsigned int unk1bc;
 unsigned int unk1c0;
 unsigned int unk1c4;
 unsigned int unk1c8;
 unsigned int unk1cc;
 unsigned int unk1d0;
 unsigned int unk1d4;
 unsigned int unk1d8;
 unsigned int unk1dc;
 unsigned int unk1e0;
 unsigned int unk1e4;
 unsigned int unk1e8;
 unsigned int unk1ec;
 unsigned int unk1f0;
 unsigned int unk1f4;
 unsigned int unk1f8;
 unsigned int unk1fc;
 unsigned int unk200;
 unsigned int unk204;
 unsigned int unk208;
 unsigned int unk20c;
 unsigned int unk210;
 unsigned int unk214;
 unsigned int unk218;
 unsigned int unk21c;
 unsigned int unk220;
 unsigned int unk224;
 unsigned int unk228;
 unsigned int unk22c;
 unsigned int unk230;
 unsigned int unk234;
 unsigned int unk238;
 unsigned int unk23c;
 unsigned int unk240;
 unsigned int unk244;
 unsigned int unk248;
 unsigned int unk24c;
 unsigned int unk250;
 unsigned int unk254;
 unsigned int unk258;
 unsigned int unk25c;
 unsigned int unk260;
 unsigned int unk264;
 unsigned int unk268;
 unsigned int unk26c;
 unsigned int unk270;
 unsigned int unk274;
 unsigned int unk278;
 unsigned int unk27c;
 unsigned int unk280;
 unsigned int unk284;
 Dev* unk288;
 unsigned int unk28c;
 unsigned int unk290;
 unsigned int unk294;
 unsigned int unk298;
 unsigned int unk29c;
 unsigned int unk2a0;
 unsigned int unk2a4;
 unsigned int unk2a8;
 unsigned int unk2ac;
 unsigned int unk2b0;
 unsigned int unk2b4;
 unsigned int unk2b8;
 unsigned int unk2bc;
 unsigned int unk2c0;
 unsigned int unk2c4;
 unsigned int unk2c8;
 unsigned int unk2cc;
 unsigned int unk2d0;
 unsigned int unk2d4;
 unsigned int unk2d8;
 unsigned int unk2dc;
 unsigned int unk2e0;
 unsigned int unk2e4;
 unsigned int unk2e8;
 unsigned int unk2ec;
 unsigned int unk2f0;
 unsigned int unk2f4;
 unsigned int unk2f8;
 unsigned int unk2fc;
 unsigned int unk300;
 unsigned int unk304;
 unsigned int unk308;
 unsigned int unk30c;
 unsigned int unk310;
 unsigned int unk314;
 unsigned int unk318;
 unsigned int unk31c;
 unsigned int unk320;
 unsigned int unk324;
 unsigned int unk328;
 unsigned int unk32c;
 unsigned int unk330;
 unsigned int unk334;
 unsigned int unk338;
 unsigned int unk33c;
 unsigned int unk340;
 unsigned int unk344;
 unsigned int unk348;
 unsigned int unk34c;
 unsigned int unk350;
 unsigned int unk354;
 unsigned int unk358;
 unsigned int unk35c;
 unsigned int unk360;
 unsigned int unk364;
 unsigned int unk368;
 unsigned int unk36c;
 unsigned int unk370;
 unsigned int unk374;
 unsigned int unk378;
 unsigned int unk37c;
 unsigned int unk380;
 unsigned int unk384;
 unsigned int unk388;
 unsigned int unk38c;
 unsigned int unk390;
 unsigned int unk394;
 unsigned int unk398;
 unsigned int unk39c;
 unsigned int unk3a0;
 unsigned int unk3a4;
 unsigned int unk3a8;
 unsigned int unk3ac;
 unsigned int unk3b0;
 unsigned int unk3b4;
 unsigned int unk3b8;
 unsigned int unk3bc;
 unsigned int unk3c0;
 unsigned int unk3c4;
 unsigned int unk3c8;
 unsigned int unk3cc;
 unsigned int unk3d0;
 unsigned int unk3d4;
 unsigned int unk3d8;
 unsigned int unk3dc;
 unsigned int unk3e0;
 unsigned int unk3e4;
 unsigned int unk3e8;
 unsigned int unk3ec;
 unsigned int unk3f0;
 unsigned int unk3f4;
 unsigned int unk3f8;
 unsigned int unk3fc;
 unsigned int unk400;
 unsigned int unk404;
 unsigned int unk408;
 unsigned int unk40c;
 unsigned int unk410;
 unsigned int unk414;
 unsigned int unk418;
 unsigned int unk41c;
 unsigned int unk420;
 unsigned int unk424;
 unsigned int unk428;
 unsigned int unk42c;
 unsigned int unk430;
 unsigned int unk434;
 unsigned int unk438;
 unsigned int unk43c;
 unsigned int unk440;
 unsigned int unk444;
 unsigned int unk448;
 unsigned int unk44c;
 unsigned int unk450;
 unsigned int unk454;
 unsigned int unk458;
 unsigned int unk45c;
 unsigned int unk460;
 unsigned int unk464;
 unsigned int unk468;
 unsigned int unk46c;
 unsigned int unk470;
 unsigned int unk474;
 unsigned int unk478;
 unsigned int unk47c;
 unsigned int unk480;
 unsigned int unk484;
 unsigned int unk488;
 unsigned int unk48c;
 unsigned int unk490;
 unsigned int unk494;
 unsigned int unk498;
 unsigned int unk49c;
 unsigned int unk4a0;
 unsigned int unk4a4;
 unsigned int unk4a8;
 unsigned int unk4ac;
 unsigned int unk4b0;
 unsigned int unk4b4;
 unsigned int unk4b8;
 unsigned int unk4bc;
 unsigned int unk4c0;
 unsigned int unk4c4;
 unsigned int unk4c8;
 unsigned int unk4cc;
 unsigned int unk4d0;
 unsigned int unk4d4;
 unsigned int unk4d8;
 unsigned int unk4dc;
 unsigned int unk4e0;
 unsigned int unk4e4;
 unsigned int unk4e8;
 unsigned int unk4ec;
 unsigned int unk4f0;
 unsigned int unk4f4;
 unsigned int unk4f8;
 unsigned int unk4fc;
 unsigned int unk500;
 unsigned int unk504;
 unsigned int unk508;
 unsigned int unk50c;
 unsigned int unk510;
 unsigned int unk514;
 unsigned int unk518;
 unsigned int unk51c;
 unsigned int unk520;
 unsigned int unk524;
 unsigned int unk528;
 unsigned int unk52c;
 unsigned int unk530;
 unsigned int unk534;
 unsigned int unk538;
 unsigned int unk53c;
 unsigned int unk540;
 unsigned int unk544;
 unsigned int unk548;
 unsigned int unk54c;
 unsigned int unk550;
 unsigned int unk554;
 unsigned int unk558;
 unsigned int unk55c;
 unsigned int unk560;
 unsigned int unk564;
 unsigned int unk568;
 unsigned int unk56c;
 unsigned int unk570;
 unsigned int unk574;
 unsigned int unk578;
 unsigned int unk57c;
 unsigned int unk580;
 unsigned int unk584;
 unsigned int unk588;
 unsigned int unk58c;
 unsigned int unk590;
 unsigned int unk594;
 unsigned int unk598;
 unsigned int unk59c;
 unsigned int unk5a0;
 unsigned int unk5a4;
 unsigned int unk5a8;
 unsigned int unk5ac;
 unsigned int unk5b0;
 unsigned int unk5b4;
 unsigned int unk5b8;
 unsigned int unk5bc;
 unsigned int unk5c0;
 unsigned int unk5c4;
 unsigned int unk5c8;
 unsigned int unk5cc;
 unsigned int unk5d0;
 unsigned int unk5d4;
 unsigned int unk5d8;
 unsigned int unk5dc;
 unsigned int unk5e0;
 unsigned int unk5e4;
 unsigned int unk5e8;
 unsigned int unk5ec;
 unsigned int unk5f0;
 unsigned int unk5f4;
 unsigned int unk5f8;
 unsigned int unk5fc;
 unsigned int unk600;
 unsigned int unk604;
 unsigned int unk608;
 unsigned int unk60c;
 unsigned int unk610;
 unsigned int unk614;
 unsigned int unk618;
 unsigned int unk61c;
 unsigned int unk620;
 unsigned int unk624;
 unsigned int unk628;
 unsigned int unk62c;
 unsigned int unk630;
 unsigned int unk634;
 unsigned int unk638;
 unsigned int unk63c;
 unsigned int unk640;
 unsigned int unk644;
 unsigned int unk648;
 unsigned int unk64c;
 unsigned int unk650;
 unsigned int unk654;
 unsigned int unk658;
 unsigned int unk65c;
 unsigned int unk660;
 unsigned int unk664;
 unsigned int unk668;
 unsigned int unk66c;
 float unk670;
 unsigned int unk674;
 unsigned int unk678;
 unsigned int unk67c;
 unsigned int unk680;
 unsigned int unk684;
 unsigned int unk688;
 unsigned int unk68c;
 unsigned int unk690;
 unsigned int unk694;
 unsigned int unk698;
 unsigned int unk69c;
 unsigned int unk6a0;
 unsigned int unk6a4;
 unsigned int unk6a8;
 unsigned int unk6ac;
 unsigned int unk6b0;
 unsigned int unk6b4;
 unsigned int unk6b8;
 unsigned int unk6bc;
 unsigned int unk6c0;
 unsigned int unk6c4;
 unsigned int unk6c8;
 unsigned int unk6cc;
 unsigned int unk6d0;
 unsigned int unk6d4;
 unsigned int unk6d8;
 unsigned int unk6dc;
 unsigned int unk6e0;
 unsigned int unk6e4;
 unsigned int unk6e8;
 unsigned int unk6ec;
 unsigned int unk6f0;
 unsigned int unk6f4;
 unsigned int unk6f8;
 unsigned int unk6fc;
 unsigned int unk700;
 unsigned int unk704;
 unsigned int unk708;
 unsigned int unk70c;
 unsigned int unk710;
 unsigned int unk714;
 unsigned int unk718;
 unsigned int unk71c;
 unsigned int unk720;
 unsigned int unk724;
 unsigned int unk728;
 unsigned int unk72c;
 unsigned int unk730;
 unsigned int unk734;
 unsigned int unk738;
 unsigned int unk73c;
 unsigned int unk740;
 unsigned int unk744;
 unsigned int unk748;
 unsigned int unk74c;
 unsigned int unk750;
 unsigned int unk754;
 unsigned int unk758;
 unsigned int unk75c;
 unsigned int unk760;
 unsigned int unk764;
 unsigned int unk768;
 unsigned int unk76c;
 unsigned int unk770;
 unsigned int unk774;
 unsigned int unk778;
 unsigned int unk77c;
 unsigned int unk780;
 unsigned int unk784;
 unsigned int unk788;
 unsigned int unk78c;
 unsigned int unk790;
 unsigned int unk794;
 unsigned int unk798;
 unsigned int unk79c;
 unsigned int unk7a0;
 unsigned int unk7a4;
 unsigned int unk7a8;
 unsigned int unk7ac;
 unsigned int unk7b0;
 unsigned int unk7b4;
 unsigned int unk7b8;
 unsigned int unk7bc;
 unsigned int unk7c0;
 unsigned int unk7c4;
 unsigned int unk7c8;
 unsigned int unk7cc;
 unsigned int unk7d0;
 unsigned int unk7d4;
 unsigned int unk7d8;
 unsigned int unk7dc;
 unsigned int unk7e0;
 unsigned int unk7e4;
 unsigned int unk7e8;
 unsigned int unk7ec;
 unsigned int unk7f0;
 unsigned int unk7f4;
 unsigned int unk7f8;
 unsigned int unk7fc;
 unsigned int unk800;
 unsigned int unk804;
 unsigned int unk808;
 unsigned int unk80c;
 unsigned int unk810;
 unsigned int unk814;
 unsigned int unk818;
 unsigned int unk81c;
 unsigned int unk820;
 unsigned int unk824;
 unsigned int unk828;
 unsigned int unk82c;
 unsigned int unk830;
 unsigned int unk834;
 unsigned int unk838;
 unsigned int unk83c;
 unsigned int unk840;
 unsigned int unk844;
 unsigned int unk848;
 unsigned int unk84c;
 unsigned int unk850;
 unsigned int unk854;
 unsigned int unk858;
 unsigned int unk85c;
 unsigned int unk860;
 unsigned int unk864;
 unsigned int unk868;
 unsigned int unk86c;
 unsigned int unk870;
 unsigned int unk874;
 unsigned int unk878;
 unsigned int unk87c;
 unsigned int unk880;
 unsigned int unk884;
 unsigned int unk888;
 unsigned int unk88c;
 unsigned int unk890;
 unsigned int unk894;
 unsigned int unk898;
 unsigned int unk89c;
 unsigned int unk8a0;
 unsigned int unk8a4;
 unsigned int unk8a8;
 unsigned int unk8ac;
 unsigned int unk8b0;
 unsigned int unk8b4;
 StripState* unk8b8;
 void SetColor(const Rgb& c,float alpha) {*(Rgb*)&unk664=c;unk670=alpha;}
 void DrawStrip(Geometry*,Flags*,Shape*,void*,Color*);
};
// Renders mesh data across shader passes, skips inactive visibility entries, and issues indexed primitive draws.
// @fnv 0x00e718a0
void StripTarget::DrawStrip(Geometry* geometry,Flags* flags,Shape* shape,void* context,Color* color) {
 if(!shape)return;
 Block* block=shape->block;StripMesh* meshes=block->meshes;int type=meshes->strip ? 5:4;
 StripShader* shader=0;if(geometry)shader=geometry->shader;
 RenderData* data=meshes->unk28;
 if(shader->v54(geometry,shape,data,unkc,unk10,context,color))return;
 shader->v58(geometry,shape,data,unkc,unk10,context,color);
 unsigned int count=block->count;unsigned int passes=shader->v90();unsigned int draws=0;
 Vis* visibility=0;if(IsExact(&DAT_011f49d8,shape))visibility=shape->visibility;
 if(passes) {
  do {
   shader->v5c(geometry,shape,data,unkc,unk10,context,color);
   SetColor(*(Rgb*)color,color->a);
   bool first=true;
   Color* loopColor=color;
   for(unsigned int i=0;i<count;++i) {
    if(visibility && !visibility[i].active)continue;
    StripMesh* mesh=&meshes[i];data=meshes[i].unk28;
    if(first) {
     first=false;shader->v60(geometry,shape,mesh,data,unkc,unk10,context,loopColor);
     data=shader->v6c(geometry,mesh,data,unkc);if(!data)return;
     shader->v68(geometry,shape,mesh,data,unkc,unk10,context,color);
    }else {
     data=shader->v6c(geometry,mesh,data,unkc);if(!data)return;
     shader->v64(geometry,shape,mesh,data,unkc,unk10,context,color);
    }
    unsigned int start=0;
    for(unsigned int j=0;j<data->unk48;++j) {
     unsigned int primitives=data->unk4c ? data->unk4c[j]-2:data->unk40;
     unk288->DrawIndexedPrimitive(type,data->unk38,0,mesh->vertices,start,primitives);
     ++draws;start+=primitives+2;
    }
    if(visibility && i+1<count) {
     unsigned int next=i+1;
     StripMesh* nextMesh=mesh;
     do {
      if(visibility[i+1].nextState) break;
      ++next;++i;++nextMesh;
      if(visibility[i].active) {
       mesh=nextMesh;
       data=shader->v6c(geometry,mesh,mesh->GetData(),unkc);if(!data)return;
       unsigned int start=0;
       for(unsigned int j=0;j<data->unk48;++j) {
        unsigned int primitives=data->unk4c ? data->unk4c[j]-2:data->unk40;
        unk288->DrawIndexedPrimitive(type,data->unk38,0,nextMesh->vertices,start,primitives);
        ++draws;start+=primitives+2;
       }
      }
     } while(next<count);
    }
    shader->v70(geometry,shape,mesh,data,unkc,unk10,context,color);loopColor=(Color* volatile&)color;
   }
   flags->flags &= 0xf000;
  }while(shader->v94());
 }
 shader->v74(geometry,shape,data,unkc,unk10,context,color);
 unk8b8->vf8(0);
}

struct QuadPoint { float x,y; };
struct FUN_004a7800 { float r,g,b,a; FUN_004a7800() throw(); };
struct QuadData { short top,left; unsigned short width,height,u,v; FUN_004a7800 color; };
struct QuadTex {
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual void v8();
 virtual void v9();
 virtual void v10();
 virtual void v11();
 virtual void v12();
 virtual void v13();
 virtual void v14();
 virtual void v15();
 virtual void v16();
 virtual void v17();
 virtual void v18();
 virtual void v19();
 virtual void v20();
 virtual void v21();
 virtual void v22();
 virtual void v23();
 virtual void v24();
 virtual void v25();
 virtual void v26();
 virtual void v27();
 virtual void v28();
 virtual void v29();
 virtual void v30();
 virtual void v31();
 virtual void v32();
 virtual void v33();
 virtual void v34();
 virtual unsigned int Width(unsigned int);
 virtual unsigned int Height(unsigned int);
 virtual unsigned short TexWidth();
 virtual unsigned short TexHeight();
};
struct QuadNode { unsigned int unk00,unk04; QuadTex* texture; };
struct QuadLink { QuadNode* node; QuadTex* GetTexture() { QuadNode* p=node; return p ? p->texture : 0; } };
struct QuadSource { unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c; QuadLink* link; };
struct QuadBuffer { unsigned int unk00,unk04,unk08,unk0c,unk10; unsigned int bytes; };
struct QuadGeometry {
 unsigned int unk00,unk04,unk08,unk0c,unk10;
 unsigned char flag; unsigned char unk15,unk16,unk17;
 unsigned int vertices,activeVertices,count; unsigned int* strides; QuadBuffer** buffers;
 unsigned int indices,handle,resource,unk38,unk3c,triangles,activeTriangles,one,zero1,zero2;
 void FUN_00e8eee0();
 QuadBuffer* GetBuffer() { return count>0 ? buffers[0] : 0; }
 unsigned int GetStride() { return count>0 ? strides[0] : 0; }
};
struct QuadInput { unsigned int unk00,unk04; QuadData* data; unsigned int unk0c; unsigned short count,unk12; QuadSource* source; unsigned int unk18; QuadGeometry* geometry; };
struct QuadUploader { unsigned int NiDX9VertexBufferManager_PackTransformedVB(QuadGeometry*,unsigned short,QuadPoint*,FUN_004a7800*,QuadPoint*,unsigned short,QuadBuffer*,unsigned int); };
struct QuadIndexUploader { unsigned int FUN_00e8f200(unsigned short*,unsigned int,unsigned int,unsigned int,unsigned int*,unsigned int,unsigned int); };
extern bool DAT_0126f0d0;
void* _NiMalloc_00aa1070(unsigned int);
struct QuadRenderer {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 unsigned int unk07c;
 unsigned int unk080;
 unsigned int unk084;
 unsigned int unk088;
 unsigned int unk08c;
 unsigned int unk090;
 unsigned int unk094;
 unsigned int unk098;
 unsigned int unk09c;
 unsigned int unk0a0;
 unsigned int unk0a4;
 unsigned int unk0a8;
 unsigned int unk0ac;
 unsigned int unk0b0;
 unsigned int unk0b4;
 unsigned int unk0b8;
 unsigned int unk0bc;
 unsigned int unk0c0;
 unsigned int unk0c4;
 unsigned int unk0c8;
 unsigned int unk0cc;
 unsigned int unk0d0;
 unsigned int unk0d4;
 unsigned int unk0d8;
 unsigned int unk0dc;
 unsigned int unk0e0;
 unsigned int unk0e4;
 unsigned int unk0e8;
 unsigned int unk0ec;
 unsigned int unk0f0;
 unsigned int unk0f4;
 unsigned int unk0f8;
 unsigned int unk0fc;
 unsigned int unk100;
 unsigned int unk104;
 unsigned int unk108;
 unsigned int unk10c;
 unsigned int unk110;
 unsigned int unk114;
 unsigned int unk118;
 unsigned int unk11c;
 unsigned int unk120;
 unsigned int unk124;
 unsigned int unk128;
 unsigned int unk12c;
 unsigned int unk130;
 unsigned int unk134;
 unsigned int unk138;
 unsigned int unk13c;
 unsigned int unk140;
 unsigned int unk144;
 unsigned int unk148;
 unsigned int unk14c;
 unsigned int unk150;
 unsigned int unk154;
 unsigned int unk158;
 unsigned int unk15c;
 unsigned int unk160;
 unsigned int unk164;
 unsigned int unk168;
 unsigned int unk16c;
 unsigned int unk170;
 unsigned int unk174;
 unsigned int unk178;
 unsigned int unk17c;
 unsigned int unk180;
 unsigned int unk184;
 unsigned int unk188;
 unsigned int unk18c;
 unsigned int unk190;
 unsigned int unk194;
 unsigned int unk198;
 unsigned int unk19c;
 unsigned int unk1a0;
 unsigned int unk1a4;
 unsigned int unk1a8;
 unsigned int unk1ac;
 unsigned int unk1b0;
 unsigned int unk1b4;
 unsigned int unk1b8;
 unsigned int unk1bc;
 unsigned int unk1c0;
 unsigned int unk1c4;
 unsigned int unk1c8;
 unsigned int unk1cc;
 unsigned int unk1d0;
 unsigned int unk1d4;
 unsigned int unk1d8;
 unsigned int unk1dc;
 unsigned int unk1e0;
 unsigned int unk1e4;
 unsigned int unk1e8;
 unsigned int unk1ec;
 unsigned int unk1f0;
 unsigned int unk1f4;
 unsigned int unk1f8;
 unsigned int unk1fc;
 unsigned int unk200;
 unsigned int unk204;
 unsigned int unk208;
 unsigned int unk20c;
 unsigned int unk210;
 unsigned int unk214;
 unsigned int unk218;
 unsigned int unk21c;
 unsigned int unk220;
 unsigned int unk224;
 unsigned int unk228;
 unsigned int unk22c;
 unsigned int unk230;
 unsigned int unk234;
 unsigned int unk238;
 unsigned int unk23c;
 unsigned int unk240;
 unsigned int unk244;
 unsigned int unk248;
 unsigned int unk24c;
 unsigned int unk250;
 unsigned int unk254;
 unsigned int unk258;
 unsigned int unk25c;
 unsigned int unk260;
 unsigned int unk264;
 unsigned int unk268;
 unsigned int unk26c;
 unsigned int unk270;
 unsigned int unk274;
 unsigned int unk278;
 unsigned int unk27c;
 unsigned int unk280;
 unsigned int unk284;
 unsigned int unk288;
 unsigned int unk28c;
 unsigned int unk290;
 unsigned int unk294;
 unsigned int unk298;
 unsigned int unk29c;
 unsigned int unk2a0;
 unsigned int unk2a4;
 unsigned int unk2a8;
 unsigned int unk2ac;
 unsigned int unk2b0;
 unsigned int unk2b4;
 unsigned int unk2b8;
 unsigned int unk2bc;
 unsigned int unk2c0;
 unsigned int unk2c4;
 unsigned int unk2c8;
 unsigned int unk2cc;
 unsigned int unk2d0;
 unsigned int unk2d4;
 unsigned int unk2d8;
 unsigned int unk2dc;
 unsigned int unk2e0;
 unsigned int unk2e4;
 unsigned int unk2e8;
 unsigned int unk2ec;
 unsigned int unk2f0;
 unsigned int unk2f4;
 unsigned int unk2f8;
 unsigned int unk2fc;
 unsigned int unk300;
 unsigned int unk304;
 unsigned int unk308;
 unsigned int unk30c;
 unsigned int unk310;
 unsigned int unk314;
 unsigned int unk318;
 unsigned int unk31c;
 unsigned int unk320;
 unsigned int unk324;
 unsigned int unk328;
 unsigned int unk32c;
 unsigned int unk330;
 unsigned int unk334;
 unsigned int unk338;
 unsigned int unk33c;
 unsigned int unk340;
 unsigned int unk344;
 unsigned int unk348;
 unsigned int unk34c;
 unsigned int unk350;
 unsigned int unk354;
 unsigned int unk358;
 unsigned int unk35c;
 unsigned int unk360;
 unsigned int unk364;
 unsigned int unk368;
 unsigned int unk36c;
 unsigned int unk370;
 unsigned int unk374;
 unsigned int unk378;
 unsigned int unk37c;
 unsigned int unk380;
 unsigned int unk384;
 unsigned int unk388;
 unsigned int unk38c;
 unsigned int unk390;
 unsigned int unk394;
 unsigned int unk398;
 unsigned int unk39c;
 unsigned int unk3a0;
 unsigned int unk3a4;
 unsigned int unk3a8;
 unsigned int unk3ac;
 unsigned int unk3b0;
 unsigned int unk3b4;
 unsigned int unk3b8;
 unsigned int unk3bc;
 unsigned int unk3c0;
 unsigned int unk3c4;
 unsigned int unk3c8;
 unsigned int unk3cc;
 unsigned int unk3d0;
 unsigned int unk3d4;
 unsigned int unk3d8;
 unsigned int unk3dc;
 unsigned int unk3e0;
 unsigned int unk3e4;
 unsigned int unk3e8;
 unsigned int unk3ec;
 unsigned int unk3f0;
 unsigned int unk3f4;
 unsigned int unk3f8;
 unsigned int unk3fc;
 unsigned int unk400;
 unsigned int unk404;
 unsigned int unk408;
 unsigned int unk40c;
 unsigned int unk410;
 unsigned int unk414;
 unsigned int unk418;
 unsigned int unk41c;
 unsigned int unk420;
 unsigned int unk424;
 unsigned int unk428;
 unsigned int unk42c;
 unsigned int unk430;
 unsigned int unk434;
 unsigned int unk438;
 unsigned int unk43c;
 unsigned int unk440;
 unsigned int unk444;
 unsigned int unk448;
 unsigned int unk44c;
 unsigned int unk450;
 unsigned int unk454;
 unsigned int unk458;
 unsigned int unk45c;
 unsigned int unk460;
 unsigned int unk464;
 unsigned int unk468;
 unsigned int unk46c;
 unsigned int unk470;
 unsigned int unk474;
 unsigned int unk478;
 unsigned int unk47c;
 unsigned int unk480;
 unsigned int unk484;
 unsigned int unk488;
 unsigned int unk48c;
 unsigned int unk490;
 unsigned int unk494;
 unsigned int unk498;
 unsigned int unk49c;
 unsigned int unk4a0;
 unsigned int unk4a4;
 unsigned int unk4a8;
 unsigned int unk4ac;
 unsigned int unk4b0;
 unsigned int unk4b4;
 unsigned int unk4b8;
 unsigned int unk4bc;
 unsigned int unk4c0;
 unsigned int unk4c4;
 unsigned int unk4c8;
 unsigned int unk4cc;
 unsigned int unk4d0;
 unsigned int unk4d4;
 unsigned int unk4d8;
 unsigned int unk4dc;
 unsigned int unk4e0;
 unsigned int unk4e4;
 unsigned int unk4e8;
 unsigned int unk4ec;
 unsigned int unk4f0;
 unsigned int unk4f4;
 unsigned int unk4f8;
 unsigned int unk4fc;
 unsigned int unk500;
 unsigned int unk504;
 unsigned int unk508;
 unsigned int unk50c;
 unsigned int unk510;
 unsigned int unk514;
 unsigned int unk518;
 unsigned int unk51c;
 unsigned int unk520;
 unsigned int unk524;
 unsigned int unk528;
 unsigned int unk52c;
 unsigned int unk530;
 unsigned int unk534;
 unsigned int unk538;
 unsigned int unk53c;
 unsigned int unk540;
 unsigned int unk544;
 unsigned int unk548;
 unsigned int unk54c;
 unsigned int unk550;
 unsigned int unk554;
 unsigned int unk558;
 unsigned int unk55c;
 unsigned int unk560;
 unsigned int unk564;
 unsigned int unk568;
 unsigned int unk56c;
 unsigned int unk570;
 unsigned int unk574;
 unsigned int unk578;
 unsigned int unk57c;
 unsigned int unk580;
 unsigned int unk584;
 unsigned int unk588;
 unsigned int unk58c;
 unsigned int unk590;
 unsigned int unk594;
 unsigned int unk598;
 unsigned int unk59c;
 unsigned int unk5a0;
 unsigned int unk5a4;
 unsigned int unk5a8;
 unsigned int unk5ac;
 unsigned int unk5b0;
 unsigned int unk5b4;
 unsigned int unk5b8;
 unsigned int unk5bc;
 unsigned int unk5c0;
 unsigned int unk5c4;
 unsigned int unk5c8;
 unsigned int unk5cc;
 unsigned int unk5d0;
 unsigned int unk5d4;
 unsigned int unk5d8;
 unsigned int unk5dc;
 unsigned int unk5e0;
 unsigned int unk5e4;
 unsigned int unk5e8;
 unsigned int unk5ec;
 unsigned int unk5f0;
 unsigned int unk5f4;
 unsigned int unk5f8;
 unsigned int unk5fc;
 unsigned int unk600;
 unsigned int unk604;
 unsigned int unk608;
 unsigned int unk60c;
 unsigned int unk610;
 unsigned int unk614;
 unsigned int unk618;
 unsigned int unk61c;
 unsigned int unk620;
 unsigned int unk624;
 unsigned int unk628;
 unsigned int unk62c;
 unsigned int unk630;
 unsigned int unk634;
 unsigned int unk638;
 unsigned int unk63c;
 unsigned int unk640;
 unsigned int unk644;
 unsigned int unk648;
 unsigned int unk64c;
 unsigned int unk650;
 unsigned int unk654;
 unsigned int unk658;
 unsigned int unk65c;
 unsigned int unk660;
 unsigned int unk664;
 unsigned int unk668;
 unsigned int unk66c;
 unsigned int unk670;
 unsigned int unk674;
 unsigned int unk678;
 unsigned int unk67c;
 unsigned int unk680;
 unsigned int unk684;
 unsigned int unk688;
 unsigned int unk68c;
 unsigned int unk690;
 unsigned int unk694;
 unsigned int unk698;
 unsigned int unk69c;
 unsigned int unk6a0;
 unsigned int unk6a4;
 unsigned int unk6a8;
 unsigned int unk6ac;
 unsigned int unk6b0;
 unsigned int unk6b4;
 unsigned int unk6b8;
 unsigned int unk6bc;
 unsigned int unk6c0;
 unsigned int unk6c4;
 unsigned int unk6c8;
 unsigned int unk6cc;
 unsigned int unk6d0;
 unsigned int unk6d4;
 unsigned int unk6d8;
 unsigned int unk6dc;
 unsigned int unk6e0;
 unsigned int unk6e4;
 unsigned int unk6e8;
 unsigned int unk6ec;
 unsigned int unk6f0;
 unsigned int unk6f4;
 unsigned int unk6f8;
 unsigned int unk6fc;
 unsigned int unk700;
 unsigned int unk704;
 unsigned int unk708;
 unsigned int unk70c;
 unsigned int unk710;
 unsigned int unk714;
 unsigned int unk718;
 unsigned int unk71c;
 unsigned int unk720;
 unsigned int unk724;
 unsigned int unk728;
 unsigned int unk72c;
 unsigned int unk730;
 unsigned int unk734;
 unsigned int unk738;
 unsigned int unk73c;
 unsigned int unk740;
 unsigned int unk744;
 unsigned int unk748;
 unsigned int unk74c;
 unsigned int unk750;
 unsigned int unk754;
 unsigned int unk758;
 unsigned int unk75c;
 unsigned int unk760;
 unsigned int unk764;
 unsigned int unk768;
 unsigned int unk76c;
 unsigned int unk770;
 unsigned int unk774;
 unsigned int unk778;
 unsigned int unk77c;
 unsigned int unk780;
 unsigned int unk784;
 unsigned int unk788;
 unsigned int unk78c;
 unsigned int unk790;
 unsigned int unk794;
 unsigned int unk798;
 unsigned int unk79c;
 unsigned int unk7a0;
 unsigned int unk7a4;
 unsigned int unk7a8;
 unsigned int unk7ac;
 unsigned int unk7b0;
 unsigned int unk7b4;
 unsigned int unk7b8;
 unsigned int unk7bc;
 unsigned int unk7c0;
 unsigned int unk7c4;
 unsigned int unk7c8;
 unsigned int unk7cc;
 unsigned int unk7d0;
 unsigned int unk7d4;
 unsigned int unk7d8;
 unsigned int unk7dc;
 unsigned int unk7e0;
 unsigned int unk7e4;
 unsigned int unk7e8;
 unsigned int unk7ec;
 unsigned int unk7f0;
 unsigned int unk7f4;
 unsigned int unk7f8;
 unsigned int unk7fc;
 unsigned int unk800;
 unsigned int unk804;
 unsigned int unk808;
 unsigned int unk80c;
 unsigned int unk810;
 unsigned int unk814;
 unsigned int unk818;
 unsigned int unk81c;
 unsigned int unk820;
 unsigned int unk824;
 unsigned int unk828;
 unsigned int unk82c;
 unsigned int unk830;
 unsigned int unk834;
 unsigned int unk838;
 unsigned int unk83c;
 unsigned int unk840;
 unsigned int unk844;
 unsigned int unk848;
 unsigned int unk84c;
 unsigned int unk850;
 unsigned int unk854;
 unsigned int unk858;
 unsigned int unk85c;
 unsigned int unk860;
 unsigned int unk864;
 unsigned int unk868;
 unsigned int unk86c;
 unsigned int unk870;
 unsigned int unk874;
 unsigned int unk878;
 unsigned int unk87c;
 unsigned int unk880;
 unsigned int unk884;
 QuadTex* texture;
 unsigned int unk88c;
 unsigned int unk890;
 unsigned int unk894;
 unsigned int unk898;
 unsigned int unk89c;
 unsigned int unk8a0;
 unsigned int unk8a4;
 unsigned int unk8a8;
 unsigned int unk8ac;
 unsigned int unk8b0;
 unsigned int unk8b4;
 unsigned int unk8b8;
 QuadUploader* uploader;
 QuadIndexUploader* indexUploader;
 unsigned int unk8c4;
 unsigned int unk8c8;
 unsigned int unk8cc;
 unsigned int unk8d0;
 unsigned int unk8d4;
 unsigned int unk8d8;
 unsigned int unk8dc;
 unsigned int unk8e0;
 unsigned int unk8e4;
 unsigned int unk8e8;
 unsigned int unk8ec;
 unsigned int unk8f0;
 unsigned int unk8f4;
 unsigned int unk8f8;
 unsigned int unk8fc;
 unsigned int unk900;
 unsigned int unk904;
 unsigned int unk908;
 unsigned int unk90c;
 unsigned int unk910;
 unsigned int unk914;
 unsigned int unk918;
 unsigned int unk91c;
 unsigned int unk920;
 unsigned int unk924;
 unsigned int unk928;
 unsigned int unk92c;
 unsigned int unk930;
 unsigned int unk934;
 unsigned int unk938;
 unsigned int unk93c;
 unsigned int unk940;
 unsigned int unk944;
 unsigned int unk948;
 unsigned int unk94c;
 unsigned int unk950;
 unsigned int unk954;
 unsigned int unk958;
 unsigned int unk95c;
 unsigned int unk960;
 unsigned int unk964;
 unsigned int unk968;
 unsigned int unk96c;
 unsigned int unk970;
 unsigned int unk974;
 unsigned int unk978;
 unsigned int unk97c;
 unsigned int unk980;
 unsigned int unk984;
 unsigned int unk988;
 unsigned int unk98c;
 unsigned int unk990;
 unsigned int unk994;
 unsigned int unk998;
 unsigned int unk99c;
 unsigned int unk9a0;
 unsigned int unk9a4;
 unsigned int unk9a8;
 unsigned int unk9ac;
 unsigned int unk9b0;
 unsigned int unk9b4;
 unsigned int unk9b8;
 unsigned int unk9bc;
 unsigned int unk9c0;
 unsigned int unk9c4;
 unsigned int unk9c8;
 unsigned int unk9cc;
 unsigned int unk9d0;
 unsigned int unk9d4;
 unsigned int unk9d8;
 unsigned int unk9dc;
 unsigned int unk9e0;
 unsigned int unk9e4;
 unsigned int unk9e8;
 unsigned int unk9ec;
 unsigned int unk9f0;
 unsigned int unk9f4;
 unsigned int unk9f8;
 unsigned int unk9fc;
 unsigned int unka00;
 unsigned int unka04;
 unsigned int unka08;
 unsigned int unka0c;
 unsigned int unka10;
 unsigned int unka14;
 unsigned int unka18;
 unsigned int unka1c;
 unsigned int unka20;
 unsigned int unka24;
 unsigned int unka28;
 unsigned int unka2c;
 unsigned int unka30;
 unsigned int unka34;
 unsigned int unka38;
 unsigned int unka3c;
 unsigned int unka40;
 unsigned int unka44;
 unsigned int unka48;
 unsigned int unka4c;
 unsigned int unka50;
 unsigned int unka54;
 unsigned int unka58;
 unsigned int unka5c;
 unsigned int unka60;
 unsigned int unka64;
 unsigned int unka68;
 unsigned int unka6c;
 unsigned int unka70;
 unsigned int unka74;
 unsigned int unka78;
 unsigned int unka7c;
 QuadPoint* points;
 FUN_004a7800* colors;
 QuadPoint* texcoords;
 unsigned short capacity,unkA8E;
 unsigned short* indices;
 unsigned int indexCapacity;
 void UploadQuads(QuadInput*,unsigned short);
};

__forceinline int SetupQuads(QuadInput* input,unsigned short flags,unsigned short& count,QuadGeometry*& geometry,unsigned short& vertices,unsigned int& nvertices,bool& dynamic,QuadBuffer*& buffer)
{
 geometry=input->geometry;
 count=input->count;
 vertices=count*4;
 nvertices=vertices;
 int nindices=(int)nvertices*3/2;
 dynamic=(flags>>3)&1;
 geometry->triangles=count*2;
 geometry->activeTriangles=count*2;
 geometry->vertices=nvertices;
 geometry->activeVertices=nvertices;
 geometry->zero2=0;
 geometry->zero1=0;
 geometry->one=1;
 buffer=geometry->GetBuffer();
 return nindices;
}
// @fnv 0x00e723a0
void QuadRenderer::UploadQuads(QuadInput* input,unsigned short flags)
{
 unsigned short count;
 QuadGeometry* geometry;
 unsigned short vertices;
 unsigned int nvertices;
 bool dynamic;
 QuadBuffer* buffer;
 int nindices=SetupQuads(input,flags,count,geometry,vertices,nvertices,dynamic,buffer);
 if(dynamic) {
   if(vertices>capacity) {
      g_memoryManager.Deallocate(points);
      g_memoryManager.Deallocate(colors);
      g_memoryManager.Deallocate(texcoords);
      points=new QuadPoint[nvertices];
      colors=new FUN_004a7800[nvertices];
      texcoords=new QuadPoint[nvertices];
      capacity=vertices;
   }
   if(buffer) {
      unsigned int byteCount=buffer->bytes;
      unsigned int stride=geometry->GetStride();
      if(nvertices>byteCount/stride) flags=15;
   }
 }
 if((flags | ~8)!=0) {
    unsigned int width=texture->Width(0);
    unsigned int height=texture->Height(0);
    QuadTex* tex=input->source->link->GetTexture();
    unsigned short texWidth=tex->TexWidth();
    tex=input->source->link->GetTexture();
    float invWidth=1.0f/texWidth;
    unsigned short texHeight=tex->TexHeight();
    float invHeight=1.0f/texHeight;
    for(unsigned short i=0;i<count;i++) {
       QuadData* q=&input->data[i];
       short left=q->left;
       while(left<0) left+=width;
       while(left>=(int)width) left-=width;
       short top=q->top;
       while(top<0) top+=height;
       while(top>=(int)height) top-=height;
       float x=left-0.5;
       float y=top-0.5;
       float right=x+q->width;
       float bottom=y+q->height;
       float v=q->v*invWidth;
       float u=q->u*invHeight;
       float uright=q->width*invWidth+v;
       float vbottom=q->height*invHeight+u;
       unsigned short vertex=i*4;
       for(unsigned short j=0;j<4;j++,vertex++) {
          points[vertex].x=(j>>1)==0 ? x : right;
          points[vertex].y=(j%2)==0 ? y : bottom;
          colors[vertex]=q->color;
          texcoords[vertex].x=(j>>1)==0 ? v : uright;
          texcoords[vertex].y=(j%2)==0 ? u : vbottom;
       }
    }
    if(!uploader->NiDX9VertexBufferManager_PackTransformedVB(geometry,vertices,points,colors,texcoords,flags,buffer,0)) return;
 }
 if(dynamic) {
    if((unsigned int)nindices>indexCapacity) {
       _NiFreeAlias(indices);
       indices=(unsigned short*)_NiMalloc_00aa1070(nindices*2);
       indexCapacity=nindices;
       unsigned short k=0;
       for(unsigned int v=0;v<nvertices;v+=4) {
          indices[k++]=(unsigned short)v;
          indices[k++]=(unsigned short)(v+1);
          indices[k++]=(unsigned short)(v+2);
          indices[k++]=(unsigned short)(v+2);
          indices[k++]=(unsigned short)(v+1);
          indices[k++]=(unsigned short)(v+3);
       }
    }
    unsigned int handle=geometry->handle;
    unsigned int old=geometry->resource;
    unsigned int result=indexUploader->FUN_00e8f200(indices,nindices,nindices,old,&handle,!DAT_0126f0d0,geometry->flag ? 16:0);
    if(old!=result) {
       geometry->FUN_00e8eee0();
       geometry->resource=result;
       geometry->indices=nindices;
       geometry->handle=handle;
    }
 }
}

struct S72_Item
{
    unsigned int unk00;
    unsigned int unk04;
};

struct S72_Pkt
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int m_uiCount;
    unsigned int unk24;
    S72_Item** m_ppItems;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    bool FUN_00e8eeb0();
    void SetVertexCounts(unsigned short av, unsigned short v) { unk18 = av; unk1C = v; }
    void SetTriangleCounts(unsigned short at, unsigned short t, unsigned int lens, unsigned short strips, unsigned int idx)
    { unk40 = at; unk44 = t; unk50 = lens; unk4C = idx; unk48 = strips; }
    S72_Item* GetAt(unsigned int i) { return i < m_uiCount ? m_ppItems[i] : 0; }
};

struct S72_Node
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* unk0C;
    unsigned int unk10;
    unsigned int unk14;
    S72_Pkt* unk18;
    unsigned int unk1C;
    void* unk20;
};

struct S72_Model
{
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf30(); virtual void vf31();
    virtual void vf32(); virtual void vf33(); virtual void vf34(); virtual void vf35();
    virtual unsigned short vf36();
    unsigned int unk04;
    unsigned short m_usFlags;
    unsigned short unk0A;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    S72_Pkt* m_pkPkt;
};

struct S72_Renderer : ShaderStreamPacketBuilder
{
    bool BuildAndRegisterNodes(unsigned int uiUnused, S72_Model* pkModel, unsigned short usB, unsigned short usC,
        unsigned int uiD, unsigned int uiE, unsigned short usF, void* pvG);
};

// Builds a packet from the model and geometry data, then allocates and registers a node for each item in the packet's item array.
// @fnv 0x00e72980
bool S72_Renderer::BuildAndRegisterNodes(unsigned int uiUnused, S72_Model* pkModel, unsigned short usTriangleCount, unsigned short usTriangleCount2,
    unsigned int uiTriangleLengths, unsigned int uiIndexCount, unsigned short usStripCount, void* pvGeomData)
{
    S72_Pkt* pkPkt = pkModel->m_pkPkt;
    if (pkPkt->FUN_00e8eeb0())
        return true;
    unsigned short usActive = pkModel->vf36();
    pkPkt->SetVertexCounts(usActive, pkModel->m_usFlags);
    pkPkt->SetTriangleCounts(usTriangleCount, usTriangleCount2, uiTriangleLengths, usStripCount, uiIndexCount);
    bool bOk = BuildPacket((Packet_e6da60*)pkPkt, (NiGeometryData*)pkModel, 0, (GeomData_e6da60*)pvGeomData);
    if (bOk)
    {
        unsigned int ItemUpdateArray = pkPkt->m_uiCount;
        for (unsigned int i = 0; i < ItemUpdateArray; ++i)
        {
            unsigned int uiId = pkPkt->GetAt(i)->unk04;
            S72_Node* pNode = (S72_Node*)Object_DispatchCommandFour(0x24);
            pNode->unk00 = pkModel;
            pNode->unk04 = 0;
            pNode->unk08 = 0;
            pNode->unk0C = pvGeomData;
            pNode->unk10 = 0;
            pNode->unk14 = 0;
            pNode->unk18 = pkPkt;
            pNode->unk1C = i;
            void* pv;
            pNode->unk20 = ((Map_e6e*)((char*)this + 0x610))->FUN_00a53c30(uiId, pv) ? pv : 0;
            ((Map_e6e*)((char*)this + 0x610))->InsertOrUpdate(uiId, pNode);
        }
    }
    return bOk;
}

extern void* DAT_01400000;
struct PackingOwner_cc0 : PackingOwner {
    virtual bool NeedsUpdate();
};

struct PackingEntry_cc0 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short flags;
    unsigned short unk1a;
    PackingPacket* packet;
};

struct PackingManager_cc0 {
    void UploadQuads(PackingEntry_cc0* entry, unsigned short flags);
    void NiDX9Renderer_PackScreenTextureGeomBuffer(PackingEntry_cc0* entry);
};

// For a nonnull entry, releases a stale packet stream, sets update flags to 15 when needed, conditionally calls UploadQuads, and clears entry flags.
// @fnv 0x00e74cc0
// src: COMMUNITY 0x00e74cc0
void PackingManager_cc0::NiDX9Renderer_PackScreenTextureGeomBuffer(PackingEntry_cc0* entry)
{
    if (entry) {
        PackingPacket* packet = entry->packet;
        bool current = packet->FUN_00e8eeb0();
        packet->flags = (unsigned int)&DAT_01400000;
        packet->NiGeometryBufferData_SetStreamCount(1);
        unsigned short flags = entry->flags;

        if (!current) {
            packet->owner->ReleaseStream(packet, 0);
            packet->cache = 0;
            flags = 15;
        } else if (static_cast<PackingOwner_cc0*>(packet->owner)->NeedsUpdate()) {
            flags = 15;
        }

        if (flags)
            UploadQuads(entry, flags);
        entry->flags = 0;
    }
}

class RObj74 { public:
    virtual ~RObj74();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};
class RPtr74 { public:
    RObj74* m_p;
    RPtr74(const RPtr74& o) : m_p(o.m_p) { if (m_p) m_p->IncRefCount(); }
    ~RPtr74() { if (m_p) m_p->DecRefCount(); }
};
struct Node74 { Node74* next; Node74* prev; RPtr74 elem; };
struct List74 {
    Node74* head; Node74* tail; unsigned int count;
    void ReleaseRefCountedNode(Node74* p) throw();
    void RemoveHead() {
        Node74* n = head;
        head = n->next;
        if (head) head->prev = 0; else tail = 0;
        RPtr74 e = n->elem;
        ReleaseRefCountedNode(n);
        count--;
    }
    bool IsEmpty() const { return count == 0; }
    unsigned int GetSize() const { return count; }
};
struct Dev74 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual long __stdcall BeginScene(); };
struct Sub74 { void FUN_00e8b560(); };
class Rend74 { public:
    char pad0[0x288]; Dev74* m_pDirect3DDevice; char pad1[0x8c8-0x28c]; Sub74* m_8c8; char pad2[0x900-0x8cc]; List74 m_kList;
    bool HandleDeviceLost(); void NiDX9Renderer_PerformPrecache();
    bool NiDX9Renderer_BeginScene();
};
// If HandleDeviceLost is true, calls recovery methods and BeginScene; on success it empties m_kList, then returns true.
// @fnv 0x00e74f40
// src: COMMUNITY 0x00e74f40
bool Rend74::NiDX9Renderer_BeginScene()
{
    if (HandleDeviceLost()) {
        NiDX9Renderer_PerformPrecache();
        m_8c8->FUN_00e8b560();
        if (m_pDirect3DDevice->BeginScene() < 0) return false;
        unsigned int remaining = reinterpret_cast<const volatile List74&>(m_kList).count;
        while (remaining) { m_kList.RemoveHead(); remaining = m_kList.count; }
    }
    return true;
}

struct S00e75340_Group {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void PrepareForRemoval();
    void FUN_00e818d0(int);
};
struct S00e75340_Alpha {
    void NiTPointerListBase_Remove(S00e75340_Group** pp);
};
struct S00e75340_Renderer {
    void __thiscall NiXenonRenderer_PurgeD3DShader(S00e75340_Group* volatile group);
};

// Calls PrepareForRemoval and FUN_00e818d0(0), then passes the address of the group parameter to the function at offset 0x90c.
// @fnv 0x00e75340
// src: XBOX_PDB 0x00e75340
void S00e75340_Renderer::NiXenonRenderer_PurgeD3DShader(S00e75340_Group* volatile group)
{
    S00e75340_Group* g = group;
    g->PrepareForRemoval();
    g->FUN_00e818d0(0);
    S00e75340_Renderer* r = this;
    reinterpret_cast<S00e75340_Alpha*>(reinterpret_cast<char*>(r) + 0x90c)->NiTPointerListBase_Remove((S00e75340_Group**)&group);
}

struct ShaderDeclStandIn
{
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03(); virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07(); virtual void V08(); virtual void V09(); virtual void V10(); virtual void V11(); virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15(); virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19(); virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23(); virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27(); virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31(); virtual void V32(); virtual void V33(); virtual void V34(); virtual void V35(); virtual void V36();
    virtual bool SetEntryFull(unsigned int uiStream, unsigned int uiEntry, unsigned int uiRegister, unsigned int eInput, unsigned int eType, unsigned int eUsage, unsigned int uiUsageIndex, unsigned int eTess);
    bool SetEntry(unsigned int uiEntry, unsigned int uiRegister, unsigned int eInput, unsigned int eType, unsigned int uiStream);
};

// Maps eInput to usage/index values and passes them to SetEntryFull.
// @fnv 0x00e76350
bool ShaderDeclStandIn::SetEntry(unsigned int uiEntry, unsigned int uiRegister, unsigned int eInput, unsigned int eType, unsigned int uiStream)
{
    unsigned int usage;
    unsigned int index = 0;
    switch (eInput)
    {
    case 0: usage = 0; break;
    case 1: usage = 1; break;
    case 2: usage = 2; break;
    case 3: usage = 3; break;
    case 4: usage = 10; break;
    case 5: usage = 5; break;
    case 6: usage = 5; index = 1; break;
    case 7: usage = 5; index = 2; break;
    case 8: usage = 5; index = 3; break;
    case 9: usage = 5; index = 4; break;
    case 10: usage = 5; index = 5; break;
    case 11: usage = 5; index = 6; break;
    case 12: usage = 5; index = 7; break;
    case 13: usage = 6; break;
    case 14: usage = 7; break;
    default: return false;
    }
    return SetEntryFull(uiStream, uiEntry, uiRegister, eInput, eType, usage, index, 0);
}

void* __cdecl _memmove(void*, const void*, unsigned int);
void* _fnv_zlib_memset(void*, int, unsigned int);

// Copies component data into pucDest, zero-fills remaining components, and returns the accumulated destination size.
// @fnv 0x00e771f0
unsigned int CopyPackedVerts(PackShortInfo* pkInfo)
{
    unsigned int uiTotal = 0;
    unsigned char* pucSrc = pkInfo->pucSrc;
    unsigned short* pusRemap = pkInfo->pusRemap;
    unsigned char* pucDest = pkInfo->pucDest;
    unsigned short v;
    unsigned short c;
    unsigned short* pusFill;
    unsigned short usIdx;

    if (!pucSrc) {
        for (v = 0; v < pkInfo->usVerts; v++) {
            _fnv_zlib_memset(pucDest, 0, pkInfo->uiDestSize);
            pucDest += pkInfo->uiDestStride;
            uiTotal += pkInfo->uiDestSize;
        }
        return uiTotal;
    }

    unsigned short usComps = pkInfo->usComps - 12;
    unsigned short usMaxComps = (pkInfo->eType == 6) ? 2 : 4;
    unsigned short usMinComps = (usComps > usMaxComps) ? usMaxComps : usComps;

    v = 0;
    if (pusRemap) {
        usIdx = 0;
        for (; v < pkInfo->usVerts; v++) {
            const unsigned char* pucVert = pucSrc + pusRemap[usIdx++] * pkInfo->uiSrcStride;
            _memmove(pucDest, pucVert, usMinComps * 2);
            pusFill = (unsigned short*)(pucDest + usMinComps * 2);
            for (c = usMinComps; c < usMaxComps; c++)
                *pusFill++ = 0;
            uiTotal += pkInfo->uiDestSize;
            pucDest += pkInfo->uiDestStride;
        }
    } else {
        for (; v < pkInfo->usVerts; v++) {
            _memmove(pucDest, pucSrc, usMinComps * 2);
            pusFill = (unsigned short*)(pucDest + usMinComps * 2);
            for (c = usMinComps; c < usMaxComps; c++)
                *pusFill++ = 0;
            uiTotal += pkInfo->uiDestSize;
            pucSrc += pkInfo->uiSrcStride;
            pucDest += pkInfo->uiDestStride;
        }
    }
    return uiTotal;
}

void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
void* __cdecl _memmove(void*, const void*, unsigned int);

static inline void S00e783b0_Pad(unsigned char* pucPad, unsigned short usCopy)
{
    for (unsigned short k = usCopy; k < 4; k++) {
        *pucPad++ = 0;
    }
}

// Copies vertex data from source to destination with optional index remapping and padding, returning total bytes written.
// @fnv 0x00e783b0
// src: COMMUNITY 0x00e783b0
unsigned int __cdecl NiD3DShaderDeclaration_Pack_UnsignedByteToUnsignedByte(StreamCopyInfo* pkInfo)
{
    unsigned int uiBytesWritten = 0;
    unsigned short* pusRemap = pkInfo->indices;
    unsigned char* pucSrc = pkInfo->source;
    unsigned char* pucDest = pkInfo->destination;

    if (pucSrc == 0) {
        for (unsigned short k = 0; k < pkInfo->vertexCount; k++) {
            _fnv_zlib_memset(pucDest, 0, pkInfo->bytesPerVertex);
            pucDest += pkInfo->outputStride;
            uiBytesWritten += pkInfo->bytesPerVertex;
        }
        return uiBytesWritten;
    }

    unsigned short usSize = pkInfo->inputBytes - 24;
    unsigned short usCopyBytes;
    if (usSize > 4) {
        usCopyBytes = 4;
    } else {
        usCopyBytes = usSize;
    }

    unsigned short i = 0;
    if (pusRemap != 0) {
        unsigned short j = 0;
        for (; i < pkInfo->vertexCount; i++) {
            unsigned char* pucIn = pucSrc + pusRemap[j] * pkInfo->sourceStride;
            j++;
            _memmove(pucDest, pucIn, usCopyBytes);
            S00e783b0_Pad(pucDest + usCopyBytes, usCopyBytes);
            uiBytesWritten += pkInfo->bytesPerVertex;
            pucDest += pkInfo->outputStride;
        }
        return uiBytesWritten;
    }

    for (; i < pkInfo->vertexCount; i++) {
        _memmove(pucDest, pucSrc, usCopyBytes);
        S00e783b0_Pad(pucDest + usCopyBytes, usCopyBytes);
        pucSrc += pkInfo->sourceStride;
        pucDest += pkInfo->outputStride;
        uiBytesWritten += pkInfo->bytesPerVertex;
    }
    return uiBytesWritten;
}

// @fnv 0x00e78a70
// src: COMMUNITY 0x00e78a70
unsigned int NiD3DShaderDeclaration_Pack_UnsignedShortToUByteColor(Stream_e78910* apStream)
{
    unsigned short* indices = apStream->indices;
    char* dst = apStream->dst;
    char* src = apStream->src;

    unsigned int uiBytesWritten = 0;

    if (!src) {
        for (unsigned short i = 0; i < apStream->count; ++i) {
            *(unsigned int*)dst = 0xffffffff;
            dst += apStream->dstStride;
            uiBytesWritten += apStream->elemSize;
        }
        return uiBytesWritten;
    }

    unsigned short comps = apStream->type - 0x10;
    if (indices) {
        unsigned short index = 0;
        for (unsigned short i = 0; i < apStream->count; ++i) {
            const unsigned short* v = (const unsigned short*)(src + indices[index++] * apStream->srcStride);
            unsigned short a = 0xffff;
            if (comps != 3)
                a = v[3];
            *(unsigned int*)dst = ((a & 0xff00) << 16) | ((v[0] & 0xff00) << 8) | (v[1] & 0xff00) | (v[2] >> 8);
            dst += apStream->dstStride;
            uiBytesWritten += apStream->elemSize;
        }
    } else {
        for (unsigned short i = 0; i < apStream->count; ++i) {
            const unsigned short* v = (const unsigned short*)src;
            unsigned short a = 0xffff;
            if (comps != 3)
                a = v[3];
            *(unsigned int*)dst = ((a & 0xff00) << 16) | ((v[0] & 0xff00) << 8) | (v[1] & 0xff00) | (v[2] >> 8);
            src += apStream->srcStride;
            dst += apStream->dstStride;
            uiBytesWritten += apStream->elemSize;
        }
    }
    return uiBytesWritten;
}

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);
struct Stream78 {
 unsigned short type, unk02;
 unsigned short components, unk06;
 unsigned short vertices, unk0a;
 unsigned short* pusRemap;
 char* pucSrc;
 unsigned int copySize;
 unsigned int sourceStride;
 unsigned int elementSize;
 unsigned int destStride;
 unsigned int unk24,unk28;
 char* pucDest;
};
// With a source, copies bytes and zeroes following words; without one, zeroes each element, then returns accumulated element sizes.
// @fnv 0x00e78e30
// src: COMMUNITY 0x00e78e30
unsigned int NiD3DShaderDeclaration_Pack_Float_ExtraOutsToZero(Stream78* pkInfo) {
 unsigned int uiTotalBytes=0;
 char* pucSrc=pkInfo->pucSrc;
 unsigned short* pusRemap=pkInfo->pusRemap;
 char* pucDest=pkInfo->pucDest;
 unsigned short usPadding=pkInfo->type-pkInfo->components+1;
 unsigned short usVert;
 if(!pucSrc) {
  for(usVert=0;usVert<pkInfo->vertices;usVert++) {
   _fnv_zlib_memset(pucDest,0,pkInfo->elementSize);
   uiTotalBytes+=pkInfo->elementSize;
   pucDest+=pkInfo->destStride;
  }
 } else if(pusRemap) {
  unsigned short usIndex=0;
  for(usVert=0;usVert<pkInfo->vertices;usVert++) {
   unsigned int uiElapsedMilliseconds=pusRemap[usIndex++]*pkInfo->sourceStride;
   memcpy(pucDest,pucSrc+uiElapsedMilliseconds,pkInfo->copySize);
   unsigned int* puiDest=(unsigned int*)(pucDest+pkInfo->copySize);
   for(unsigned short usComp=0;usComp<usPadding;++usComp) puiDest[usComp]=0;
   uiTotalBytes+=pkInfo->elementSize;
   pucDest+=pkInfo->destStride;
  }
  return uiTotalBytes;
 } else {
  for(usVert=0;usVert<pkInfo->vertices;usVert++) {
   memcpy(pucDest,pucSrc,pkInfo->copySize);
   unsigned int* puiDest=(unsigned int*)(pucDest+pkInfo->copySize);
   for(unsigned short usComp=0;usComp<usPadding;++usComp) puiDest[usComp]=0;
   uiTotalBytes+=pkInfo->elementSize;
   pucSrc+=pkInfo->sourceStride;
   pucDest+=pkInfo->destStride;
  }
 }
 return uiTotalBytes;
}

// Decodes vertex data from a NormalizedStream, scaling int values to floats and writing them to the destination buffer.
// @fnv 0x00e79160
unsigned int __cdecl DecodeVertexData(NormalizedStream* apStream)
{
    unsigned int bytes = 0;
    unsigned char* dest = apStream->dest;
    unsigned char* source = apStream->source;
    unsigned short* indices = apStream->indices;
    unsigned short j;

    if (!source)
    {
        for (unsigned short i = 0; i < apStream->vertices; ++i)
        {
            _fnv_zlib_memset(dest, 0, apStream->elementSize);
            dest += apStream->destStride;
            bytes += apStream->elementSize;
        }
        return bytes;
    }

    unsigned short available = apStream->type - 4;
    unsigned short components = apStream->lastComponent + 1;
    unsigned short count = available > components ? components : available;

    if (indices)
    {
        unsigned short k = 0;
        for (unsigned short i = 0; i < apStream->vertices; ++i)
        {
            int* input = (int*)(source + indices[k++] * apStream->sourceStride);
            float* output = (float*)dest;
            for (j = 0; j < count; ++j)
            {
                float value = *input * 4.656612873077393e-10;
                *output++ = value < -1.0f ? -1.0f : value;
                input++;
            }
            for (; j < components; ++j)
                *output++ = 0.0f;
            bytes += apStream->elementSize;
            dest += apStream->destStride;
        }
    }
    else
    {
        for (unsigned short i = 0; i < apStream->vertices; ++i)
        {
            int* input = (int*)source;
            float* output = (float*)dest;
            for (j = 0; j < count; ++j)
            {
                float value = *input * 4.656612873077393e-10;
                *output++ = value < -1.0f ? -1.0f : value;
                input++;
            }
            for (; j < components; ++j)
                *output++ = 0.0f;
            bytes += apStream->elementSize;
            source += apStream->sourceStride;
            dest += apStream->destStride;
        }
    }
    return bytes;
}

struct E7Context {
    unsigned int destFormat, sourceFormat;
    unsigned short count;
    unsigned short reserved0a;
    void* indices;
    void* source;
    unsigned int sourceStride, elementSize, semantic, destStride, extra;
    bool flag;
    void* dest;
};
typedef unsigned int (__cdecl *E7Converter)(E7Context*);
struct E7Bucket { unsigned int key, unk04; E7Converter* converters; };
struct E7Registry { void* vtable; E7Bucket** buckets; };
struct E7Descriptor { unsigned int unk00, unk04; int semantic; unsigned int format; };
struct E7Skin { unsigned int unk00, unk04; void* weights; void* indices; void* packed; unsigned int unk14, unk18, unk1c, unk20; unsigned short components; };
struct NiPoint2;

// Fills an E7Context from geometry, skin and descriptor, then runs the matching E7Converter to convert the data into the destination buffer.
// @fnv 0x00e7a200
unsigned int __stdcall ConvertGeometryData(unsigned short count, NiGeometryData* geometry, unsigned int unused, E7Skin* skin, E7Descriptor* desc, unsigned int destStride, void* dest, bool flag, unsigned int extra)
{
    E7Context info;
    info.count=count;
    info.destStride=destStride;
    info.dest=dest;
    info.flag=flag;
    if(desc->format!=17) {
    unsigned int format=desc->format;
    if(format==4 && desc->semantic==2) format=5;
    info.semantic=DAT_0126f508[format];
    E7Bucket* bucket=static_cast<E7Registry*>(DAT_0126f550)->buckets[format];
    if(!bucket) return 0;
    unsigned int sourceFormat;
    unsigned int stride;
    BSFaceGenModel* model=reinterpret_cast<BSFaceGenModel*>(geometry->m_spAdditionalGeomData.m_pObject);
    switch(desc->semantic) {
    case -1: return 0;
    case 0: info.source=geometry->m_pkVertex; stride=12; sourceFormat=3; goto setStrides;
    case 3: info.source=geometry->m_pkNormal; stride=12; sourceFormat=3; goto setStrides;
    case 1:
        if(!skin) return 0;
        switch(skin->components) {
        case 1: sourceFormat=1; info.elementSize=info.sourceStride=4; break;
        case 2: sourceFormat=2; info.elementSize=info.sourceStride=8; break;
        case 3: sourceFormat=3; info.elementSize=info.sourceStride=12; break;
        case 4: sourceFormat=3; info.sourceStride=12; info.elementSize=16; break;
        }
        info.source=skin->weights; break;
    case 2:
        if(!skin || !skin->packed) return 0;
        switch(skin->components) {
        case 1: sourceFormat=25; info.elementSize=info.sourceStride=1; break;
        case 2: sourceFormat=26; info.elementSize=info.sourceStride=2; break;
        case 3: sourceFormat=27; info.elementSize=info.sourceStride=3; break;
        case 4: sourceFormat=28; info.elementSize=info.sourceStride=4; break;
        }
        info.source=skin->packed; break;
    case 4: info.source=geometry->m_pkColor; stride=16; sourceFormat=4; goto setStrides;
    case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
        info.source=geometry->NiGeometryData_GetTextureSet((unsigned short)(desc->semantic-5)); stride=8; sourceFormat=2; goto setStrides;
    case 14: {
        NiPoint3* normals=geometry->m_pkNormal;
        if(normals && (geometry->m_usDataFlags&0xf000)) {
            info.source=normals+geometry->m_usVertices;
            stride=12; sourceFormat=3; goto setStrides;
        }
        info.source=0; stride=12; sourceFormat=3; goto setStrides;
    }
    case 13: {
        NiPoint3* normals=geometry->m_pkNormal;
        info.source=normals && (geometry->m_usDataFlags&0xf000) ? normals+geometry->m_usVertices*2 : 0;
        info.elementSize=info.sourceStride=12; sourceFormat=3;
        break;
    }
    default:
        if(desc->semantic&0x80000000) {
            int channel=desc->semantic&0x7fffffff;
            if(model->NiAdditionalGeometryData_GetDataStream(channel, &dest, &sourceFormat, &flag, &geometry, &info.sourceStride, &info.elementSize)) info.source=dest;
            else { info.source=0; sourceFormat=0; stride=0; goto setStrides; }
        }
        break;
    }
    goto convert;
setStrides:
    info.elementSize=stride;
    info.sourceStride=stride;
convert:
    E7Converter converter=bucket->converters[sourceFormat];
    if(!converter) return 0;
    if(skin && desc->semantic!=1 && desc->semantic!=2) info.indices=skin->indices;
    else info.indices=0;
    info.destFormat=format;
    info.sourceFormat=sourceFormat;
    info.extra=extra;
    if(!info.source) return 0;
    return converter(&info);
    }
    return 0;
}

// Maps key to two output values, writing each through its pointer and setting both to zero for unrecognized keys.
// @fnv 0x00e7a8b0
// src: GAMEBRYO_LIB 0x00e7a8b0
void NiDX9DeviceDesc_DisplayFormatInfo_GetDepthStencilBPPFromFormat(int key, int* outA, int* outB)
{
    switch (key)
    {
    case 0x46:
        *outA = 0x10;
        *outB = 0;
        return;
    case 0x4b:
        *outA = 0x18;
        *outB = 8;
        return;
    case 0x47:
        *outA = 0x20;
        *outB = 0;
        return;
    case 0x49:
        *outA = 0xf;
        *outB = 1;
        return;
    case 0x50:
        *outA = 0x10;
        *outB = 0;
        return;
    case 0x4d:
        *outA = 0x18;
        *outB = 0;
        return;
    case 0x4f:
        *outA = 0x18;
        *outB = 4;
        return;
    default:
        *outA = 0;
        *outB = 0;
        return;
    }
}

extern MemoryManager g_memoryManager;
extern int DAT_010edaa4;
// @fnv 0x00e6eaf0
void* __fastcall DestroyDynamicTextureMap(DynamicTextureMapBase* self, void*, unsigned int flags)
{
    *(void**)self = &DAT_010edaa4;
    self->RemoveAll();
    _NiFreeAlias(self->m_ppkHashTable);
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}

extern MemoryManager g_memoryManager;
struct FUN_00e6eb70 {
 void* m_04;
 virtual ~FUN_00e6eb70();
 static void operator delete(void* p) { g_memoryManager.Deallocate(p); }
};
// Destructor that releases the alias held in m_04 by calling _NiFreeAlias.
// @fnv 0x00e6eb70
FUN_00e6eb70::~FUN_00e6eb70()
{
 _NiFreeAlias(m_04);
}

extern MemoryManager g_memoryManager;
struct FUN_00e72df0 { void* m_04; virtual ~FUN_00e72df0(); static void operator delete(void*); };
// @fnv 0x00e72df0
FUN_00e72df0::~FUN_00e72df0() { _NiFreeAlias(m_04); }
void FUN_00e72df0::operator delete(void* p) { g_memoryManager.Deallocate(p); }

extern MemoryManager g_memoryManager;
struct FUN_00e7a610 {
 void* m_ptr;
 virtual ~FUN_00e7a610();
 static void operator delete(void* p);
};
// Calls _NiFreeAlias with m_ptr.
// @fnv 0x00e7a610
FUN_00e7a610::~FUN_00e7a610()
{
 _NiFreeAlias(m_ptr);
}
void FUN_00e7a610::operator delete(void* p)
{
 g_memoryManager.Deallocate(p);
}

struct D3DCapsStandIn;
class IDevice {
public:
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall TestCooperativeLevel();
    virtual unsigned int __stdcall GetAvailableTextureMem();
    virtual long __stdcall EvictManagedResources();
    virtual long __stdcall GetDirect3D(void**);
    virtual long __stdcall GetDeviceCaps(D3DCapsStandIn*);
};
extern "C" int fnv_CopyFilePath(char*,unsigned int,const char*,unsigned int);
extern char DAT_011f4648[256];
void __cdecl NiOutputDebugString_stub(const char*);
void __cdecl NiD3DPass_SetMaxTextureBlendStages(int);
void __cdecl NiD3DPass_SetMaxSimultaneousTextures(int);
void __cdecl NiD3DPass_SetMaxSamplers(int);
extern bool DAT_0126f0d1;
extern bool DAT_0126f0d2;
extern unsigned int DAT_0126f050;
extern unsigned int DAT_0126f054;
extern unsigned int DAT_0126f058;
extern unsigned int DAT_0126f05c;
extern unsigned int DAT_0126f060;
extern unsigned int DAT_0126f064;
extern unsigned int DAT_0126f068;
extern unsigned int DAT_0126f06c;
extern unsigned int DAT_0126f070;
extern unsigned int DAT_0126f074;
extern unsigned int DAT_0126f078;
extern unsigned int DAT_0126f07c;
extern unsigned int DAT_0126f080;
extern unsigned int DAT_0126f084;
extern unsigned int DAT_0126f088;
extern unsigned int DAT_0126f08c;
extern unsigned int DAT_0126f090;
extern unsigned int DAT_0126f094;
extern unsigned int DAT_0126f098;
extern unsigned int DAT_0126f09c;
extern unsigned int DAT_0126f0a0;
extern unsigned int DAT_0126f0a4;
extern unsigned int DAT_0126f0a8;
extern unsigned int DAT_0126f0ac;
extern unsigned int DAT_0126f0b0;
extern unsigned int DAT_0126f0b4;
extern unsigned int DAT_0126f0b8;
extern unsigned int DAT_0126f0bc;
extern unsigned int DAT_0126f0c0;
extern unsigned int DAT_0126f0c4;
extern unsigned int DAT_0126f0c8;
extern unsigned int DAT_0126f0cc;
extern unsigned int DAT_0126f0e4;
struct D3DCapsStandIn {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int Caps2;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int PrimitiveMiscCaps;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int TextureCaps;
    unsigned int TextureFilterCaps;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int MaxTextureBlendStages;
    unsigned int MaxSimultaneousTextures;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int MaxVertexBlendMatrices;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int MaxStreams;
    unsigned int unkc0;
    unsigned int VertexShaderVersion;
    unsigned int unkc8;
    unsigned int PixelShaderVersion;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int NumSimultaneousRTs;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
};
// NiDX9Renderer capability view: GetDeviceCaps populates state; its shared header lacks FUN_00e6c240 and capability members.
class DeviceCapabilityState {
public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    IDevice* m_pDirect3DDevice;
    D3DCapsStandIn m_kDeviceCapabilities;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    bool m_bSWVertexProcessing;
    bool m_bMixedVertexProcessing;
    unsigned char unk5d6;
    unsigned char unk5d7;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int m_uiIntegerAfterPrePackValue;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int m_uiMaxNumBlendMatrices;
    unsigned int m_uiFirstRendererStateValue;
    unsigned int m_uiSecondRendererStateValue;
    unsigned int m_uiThirdRendererStateValue;
    bool m_bFlagAt6F4;
    bool m_bFlagAt6F5;
    unsigned char unk6f6;
    unsigned char unk6f7;
    unsigned int unk6f8;
    unsigned int unk6fc;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int m_uiNumSimultaneousRTs;
    bool m_bFlagAt8A4;
    bool m_bFlagAt8A5;
    unsigned char unk8a6;
    unsigned char unk8a7;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    unsigned int unk8b8;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int m_auiShaderVer0;
    unsigned int m_auiShaderVer1;
    unsigned int m_auiShaderVer2;
    unsigned int m_auiShaderVer3;
    unsigned int m_auiShaderVer4;
    unsigned int m_auiShaderVer5;
    unsigned int m_auiShaderVer6;
    unsigned int m_auiShaderVer7;
    unsigned int m_auiShaderVer8;
    unsigned int m_auiShaderVer9;
    bool NiDX9Renderer_InitializeDeviceCaps(void* pkDevice);
    __forceinline void InitSamplerGlobals()
    {
    bool bAniso = (m_kDeviceCapabilities.TextureFilterCaps & 0x400) != 0;
    DAT_0126f0d1 = bAniso;
    bool bAnisoMag = (m_kDeviceCapabilities.TextureFilterCaps & 0x4000000) != 0;
    DAT_0126f0d2 = bAnisoMag;


    DAT_0126f0c4 = 3;
    DAT_0126f058 = 0;
    DAT_0126f064 = 0;
    DAT_0126f0ac = 0;
    DAT_0126f0b8 = 3;
    DAT_0126f0b0 = 3;
    DAT_0126f0b4 = 3;
    DAT_0126f0a4 = 3;
    DAT_0126f09c = DAT_0126f0d2 ? 3 : 2;
    DAT_0126f0c8 = 1;
    DAT_0126f0cc = 1;
    DAT_0126f0c0 = 1;
    DAT_0126f0bc = 1;
    DAT_0126f054 = 1;
    DAT_0126f050 = 1;
    DAT_0126f060 = 2;
    DAT_0126f05c = 2;
    DAT_0126f06c = 2;
    DAT_0126f068 = 2;
    DAT_0126f070 = 2;
    DAT_0126f078 = 1;
    DAT_0126f074 = 1;
    DAT_0126f07c = 1;
    DAT_0126f084 = 1;
    DAT_0126f080 = 1;
    DAT_0126f088 = 2;
    DAT_0126f090 = 2;
    DAT_0126f08c = 2;
    DAT_0126f094 = 1;
    DAT_0126f0a8 = 2;
    DAT_0126f0a0 = 2;
    DAT_0126f098 = DAT_0126f0d1 ? 3 : 2;
    DAT_0126f0e4 = (m_kDeviceCapabilities.TextureCaps & 0x400) ? 0x103 : 2;
    }
};

// Queries device caps, validates multi-texture support, stores capability flags and shader versions, then initializes sampler globals.
// @fnv 0x00e6c240
// src: COMMUNITY 0x00e6c240
bool DeviceCapabilityState::NiDX9Renderer_InitializeDeviceCaps(void* pkDevice)
{
    if (m_pDirect3DDevice->GetDeviceCaps(&m_kDeviceCapabilities) < 0)
    {
        fnv_CopyFilePath(DAT_011f4648, 0x100, "Creation failed: Could not query device caps", 0xff);
        NiOutputDebugString_stub("NiDX9Renderer::Initialize> Could not query device caps - FAILING\n");
        return false;
    }
    if (m_kDeviceCapabilities.MaxTextureBlendStages < 2 || m_kDeviceCapabilities.MaxSimultaneousTextures < 2)
    {
        fnv_CopyFilePath(DAT_011f4648, 0x100, "Creation failed: Device does not support single-pass multi-texture", 0xff);
        NiOutputDebugString_stub("NiDX9Renderer::Initialize> Device does not support single-pass multi-texture - FAILING\n");
        return false;
    }

    m_uiIntegerAfterPrePackValue = 0;
    if ((m_kDeviceCapabilities.TextureCaps & 2) == 0)
        m_uiIntegerAfterPrePackValue = 8;
    else if (m_kDeviceCapabilities.TextureCaps & 0x100)
        m_uiIntegerAfterPrePackValue = 4;

    m_uiMaxNumBlendMatrices = m_kDeviceCapabilities.MaxVertexBlendMatrices;
    if (m_bSWVertexProcessing && !m_bMixedVertexProcessing)
        m_uiMaxNumBlendMatrices = 4;
    if (m_uiMaxNumBlendMatrices >= 4)
        m_uiIntegerAfterPrePackValue |= 2;

    m_uiFirstRendererStateValue = m_kDeviceCapabilities.MaxStreams;
    m_uiSecondRendererStateValue = m_kDeviceCapabilities.PixelShaderVersion;
    m_uiThirdRendererStateValue = m_kDeviceCapabilities.VertexShaderVersion;

    m_bFlagAt6F4 = (m_kDeviceCapabilities.TextureCaps & 0x10000) != 0;
    m_bFlagAt6F5 = (m_kDeviceCapabilities.Caps2 & 0x20000000) != 0;
    m_uiNumSimultaneousRTs = m_kDeviceCapabilities.NumSimultaneousRTs;
    m_bFlagAt8A4 = (m_kDeviceCapabilities.PrimitiveMiscCaps & 0x40000) != 0;
    m_bFlagAt8A5 = (m_kDeviceCapabilities.PrimitiveMiscCaps & 0x80000) != 0;

    m_auiShaderVer0 = m_uiSecondRendererStateValue;
    m_auiShaderVer1 = 0xffff0000;
    m_auiShaderVer2 = m_uiSecondRendererStateValue;
    m_auiShaderVer3 = m_uiThirdRendererStateValue;
    m_auiShaderVer4 = 0xfffe0000;
    m_auiShaderVer5 = m_uiThirdRendererStateValue;
    m_auiShaderVer6 = 0xfffe0000;
    m_auiShaderVer7 = 0xfffe0000;
    m_auiShaderVer8 = 0xfffe0000;
    m_auiShaderVer9 = 2;

    NiD3DPass_SetMaxTextureBlendStages(m_kDeviceCapabilities.MaxTextureBlendStages);
    NiD3DPass_SetMaxSimultaneousTextures(m_kDeviceCapabilities.MaxSimultaneousTextures);
    if (m_uiSecondRendererStateValue >= 0xffff0200)
        NiD3DPass_SetMaxSamplers(16);
    else
        NiD3DPass_SetMaxSamplers(m_kDeviceCapabilities.MaxTextureBlendStages);

    InitSamplerGlobals();
    return true;
}

extern unsigned char DAT_0126efd1;
extern unsigned char DAT_011a9604;
extern NiPoint3 NiPoint3_ZERO;
extern float DAT_0126efd4;
extern const double DAT_0106d4c8;
extern const float DAT_01012054;
struct CameraVector18 { float x,y,z,w; };
inline float clipDotView(const CameraVector18& a, const CameraVector18& b) { return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w; }
inline CameraVector18 clipScaleView(const CameraVector18& a, float s) { __declspec(align(16)) CameraVector18 r; r.x=a.x*s; r.y=a.y*s; r.z=a.z*s; r.w=a.w*s; return r; }
struct CameraMgrView {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void SetRange(float, float);
    virtual bool IsLeftHanded();
};
NiPoint3* __stdcall D3DXVec4Transform_0(NiPoint3*, const NiPoint3*, const D3DMATRIX_Custom*);
NiPoint3* __stdcall D3DXVec3Normalize_00ee6dec(NiPoint3*, const NiPoint3*);
NiPoint3* __stdcall D3DXVec3TransformCoord_00ee6df8(NiPoint3*, const NiPoint3*, const D3DMATRIX_Custom*);
void __stdcall D3DXMatrixMultiply_00ee6de0(D3DMATRIX_Custom*, const D3DMATRIX_Custom*, const D3DMATRIX_Custom*);
inline float dotView(const NiPoint3& a, const NiPoint3& b) { return a.x*b.x+a.y*b.y+a.z*b.z; }
struct CameraRenderer18 {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    IDirect3DDevice9_Custom* device;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    NiPoint3 camRight;
    NiPoint3 camUp;
    NiPoint3 screenRight;
    NiPoint3 screenUp;
    unsigned int unk664;
    unsigned int unk668;
    unsigned int unk66c;
    unsigned int unk670;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    float nearPlane;
    float depthRange;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    unsigned char disabled; unsigned char unk6fd; unsigned short unk6fe;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    NiConsoleRendererPacketGroup* group;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    unsigned int unk8ac;
    unsigned int unk8b0;
    unsigned int unk8b4;
    CameraMgrView* manager;
    unsigned int unk8bc;
    unsigned int unk8c0;
    unsigned int unk8c4;
    unsigned int unk8c8;
    unsigned int unk8cc;
    unsigned int unk8d0;
    unsigned int unk8d4;
    unsigned int unk8d8;
    unsigned int unk8dc;
    unsigned int unk8e0;
    unsigned int unk8e4;
    unsigned int unk8e8;
    unsigned int unk8ec;
    unsigned int unk8f0;
    unsigned int unk8f4;
    unsigned int unk8f8;
    unsigned int unk8fc;
    unsigned int unk900;
    unsigned int unk904;
    unsigned int unk908;
    unsigned int unk90c;
    unsigned int unk910;
    unsigned int unk914;
    unsigned int unk918;
    unsigned int unk91c;
    unsigned int unk920;
    unsigned int unk924;
    unsigned int unk928;
    unsigned int unk92c;
    unsigned int unk930;
    unsigned int unk934;
    unsigned int unk938;
    unsigned int unk93c;
    unsigned int unk940;
    unsigned int unk944;
    unsigned int unk948;
    unsigned int unk94c;
    unsigned int unk950;
    unsigned int unk954;
    unsigned int unk958;
    unsigned int unk95c;
    unsigned int unk960;
    unsigned int unk964;
    unsigned int unk968;
    unsigned int unk96c;
    unsigned int unk970;
    unsigned int unk974;
    unsigned int unk978;
    unsigned int unk97c;
    float view[4][4];
    float proj[4][4];
    D3DMATRIX_Custom viewProj;
    float inverse[4][4];
    void NiDX9Renderer_SetupCamera(const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiPoint3*, const NiFrustum*, const NiRect_Custom_niconsolerenderer*);
};
// @fnv 0x00e6c780
// src: COMMUNITY 0x00e6c780
void CameraRenderer18::NiDX9Renderer_SetupCamera(const NiPoint3* position, const NiPoint3* direction, const NiPoint3* up, const NiPoint3* right, const NiFrustum* frustum, const NiRect_Custom_niconsolerenderer* viewport)
{
    if (disabled) return;const NiFrustum* f=frustum;

    NiPoint3 translation;
    if (DAT_0126efd1 && DAT_011a9604) {
        CopyPoint3Storage(DAT_011f474c, NiPoint3_ZERO);
        CopyPoint3Storage(translation, *position);
    } else {
        CopyPoint3Storage(DAT_011f474c, *position);
        CopyPoint3Storage(translation, NiPoint3_ZERO);
    }
    view[0][0] = right->x;
    view[0][1] = up->x;
    view[0][2] = direction->x;
    view[0][3] = 0.0f;
    view[1][0] = right->y;
    view[1][1] = up->y;
    view[1][2] = direction->y;
    view[1][3] = 0.0f;
    view[2][0] = right->z;
    view[2][1] = up->z;
    view[2][2] = direction->z;
    view[2][3] = 0.0f;
    view[3][0] = -dotView(*right, translation);
    view[3][1] = -dotView(*up, translation);
    view[3][2] = -dotView(*direction, translation);
    view[3][3] = 1.0f;

    inverse[0][0]=right->x; inverse[0][1]=right->y; inverse[0][2]=right->z; inverse[0][3]=0.0f;
    inverse[1][0]=up->x; inverse[1][1]=up->y; inverse[1][2]=up->z; inverse[1][3]=0.0f;
    inverse[2][0]=direction->x; inverse[2][1]=direction->y; inverse[2][2]=direction->z; inverse[2][3]=0.0f;
    inverse[3][0]=translation.x; inverse[3][1]=translation.y; inverse[3][2]=translation.z; inverse[3][3]=1.0f;
    device->SetTransform(2, (const D3DMATRIX_Custom*)view);
    CopyPoint3Storage(screenRight, *right); CopyPoint3Storage(camRight, *right); CopyPoint3Storage(screenUp, *up); CopyPoint3Storage(camUp, *up);
    const float& leftSide=frustum->left; const float& rightSide=frustum->right;nearPlane=f->nearPlane;
    depthRange=f->farPlane-f->nearPlane;
    float width=rightSide-leftSide;
    float sumX=rightSide+leftSide;
    float height=frustum->top-frustum->bottom;
    float sumY=frustum->bottom+frustum->top;
    float invDepth=1.0f/depthRange;
    if(frustum->ortho) {
        if(manager->IsLeftHanded()) {
            proj[0][0]=float(DAT_0106d4c8/width); proj[1][0]=0; proj[2][0]=0; proj[3][0]=sumX/width;
        } else {
            proj[0][0]=float(2.0/width); proj[1][0]=0; proj[2][0]=0; proj[3][0]=-sumX/width;
        }
        proj[0][1]=0; proj[1][1]=float(2.0/height); proj[2][1]=0; proj[3][1]=-sumY/height;
        proj[0][2]=0; proj[1][2]=0; proj[2][2]=invDepth; proj[3][2]=-(invDepth*f->nearPlane);
        proj[0][3]=0; proj[1][3]=0; proj[2][3]=0; proj[3][3]=1;
    } else {
        if(manager->IsLeftHanded()) {
            proj[0][0]=float(DAT_0106d4c8/width); proj[1][0]=0; proj[2][0]=sumX/width;
        } else {
            proj[0][0]=float(2.0/width); proj[1][0]=0; proj[2][0]=-sumX/width;
        }
        proj[3][0]=0; proj[0][1]=0; proj[1][1]=float(2.0/height); proj[2][1]=-sumY/height; proj[3][1]=0;
        proj[0][2]=0; proj[1][2]=0; proj[2][2]=invDepth*f->farPlane; proj[3][2]=-(f->farPlane*f->nearPlane*invDepth);
        proj[0][3]=0; proj[1][3]=0; proj[2][3]=1; proj[3][3]=0;
    }
    if(DAT_0126efd1) {
        NiPoint3 clipOrigin18;
        NiPoint3 clipPosition18;
        CameraVector18 clipNormal18;
        CameraVector18 worldNormal18;
        CameraVector18 corner18, clipPlane18;
        worldNormal18.x=0; worldNormal18.y=0; worldNormal18.w=0; worldNormal18.z=1;
        clipOrigin18.x=0; clipOrigin18.y=0; clipOrigin18.z=DAT_0126efd4;
        D3DXVec4Transform_0((NiPoint3*)&clipNormal18,(const NiPoint3*)&worldNormal18,(const D3DMATRIX_Custom*)view);
        D3DXVec3Normalize_00ee6dec((NiPoint3*)&clipNormal18,(const NiPoint3*)&clipNormal18);
        D3DXVec3TransformCoord_00ee6df8((NiPoint3*)&clipPosition18,(const NiPoint3*)&clipOrigin18,(const D3DMATRIX_Custom*)view);
        clipPlane18.x=clipNormal18.x; clipPlane18.y=clipNormal18.y; clipPlane18.z=clipNormal18.z;
        clipPlane18.w=-dotView(*(NiPoint3*)&clipPosition18,*(NiPoint3*)&clipNormal18);
        corner18.x=(clipPlane18.x>0?1.0f:clipPlane18.x<0?DAT_01012054:0.0f)/proj[0][0];
        corner18.y=(clipPlane18.y>0?1.0f:clipPlane18.y<0?DAT_01012054:0.0f)/proj[1][1];
        corner18.z=1;
        corner18.w=(1.0f-proj[2][2])/proj[3][2];
        CameraVector18 scaledPlane18=clipScaleView(clipPlane18, 1.0f/clipDotView(clipPlane18,corner18));
        proj[0][2]=scaledPlane18.x; proj[1][2]=scaledPlane18.y; proj[2][2]=scaledPlane18.z; proj[3][2]=scaledPlane18.w;
    }
    device->SetTransform(3,(const D3DMATRIX_Custom*)proj);
    float screenWidth=(float)group->GetWidth(0);
    float screenHeight=(float)group->GetHeight(0);
    D3DVIEWPORT9_Custom vp;
    vp.X=(unsigned long)(screenWidth*viewport->m_fMinimumU);
    vp.Y=(unsigned long)(screenHeight*(1.0f-viewport->m_fMinimumV));
    vp.Width=(unsigned long)(screenWidth*(viewport->m_fMaximumU-viewport->m_fMinimumU));
    vp.Height=(unsigned long)(screenHeight*(viewport->m_fMinimumV-viewport->m_fMaximumV));
    vp.MinZ=0; vp.MaxZ=1;
    device->SetViewport(&vp);
    D3DXMatrixMultiply_00ee6de0(&viewProj,(const D3DMATRIX_Custom*)view,(const D3DMATRIX_Custom*)proj);
    manager->SetRange(f->nearPlane,f->farPlane);
}


struct RendererStateSlot {
    NiPixelFormat* m_pkFormat;
};

struct BridgeFields {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    unsigned int m_ui5cc;
    unsigned int m_ui5d0;
};



struct NPFNew : NiPixelFormat {
    static void* operator new(unsigned int size) { return g_memoryManager.Game_DoHeapAlloc(size); }
    NPFNew(const NiPixelFormat& o) : NiPixelFormat(o) {}
};

class DeviceE6DF {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual int __stdcall CreateTexture(unsigned int a, unsigned int b, unsigned int c,
                                        unsigned int d, unsigned int e, unsigned int f);
};

extern const NiPixelFormat DAT_011aa888;
extern const NiPixelFormat DAT_011aa8d0;
extern const NiPixelFormat DAT_011aa960;
extern const NiPixelFormat DAT_011aa9f0;
extern const NiPixelFormat DAT_011aaac8;
extern const NiPixelFormat DAT_011aa498;
extern const NiPixelFormat DAT_011aa4e0;
extern const NiPixelFormat DAT_011aa528;
extern const NiPixelFormat DAT_011aa408;
extern const NiPixelFormat DAT_011aad08;
extern const NiPixelFormat DAT_011aa450;
extern const NiPixelFormat DAT_011aab58;
extern const NiPixelFormat DAT_011aa720;
extern const NiPixelFormat DAT_011aa768;
extern const NiPixelFormat DAT_011aa6d8;
extern const NiPixelFormat DAT_011aa648;
extern const NiPixelFormat DAT_011aa5b8;
extern const NiPixelFormat DAT_011aa600;
extern const NiPixelFormat DAT_011aa690;
extern const NiPixelFormat DAT_011aa570;

// For non-null slots, creates a NiPixelFormat, sets its renderer hint, attempts texture creation, and stores the resulting pointer.
// @fnv 0x00e6dfc0
void RendererBridge::CreateFormats(RendererStateSlot* state, unsigned int type, unsigned int flags)
{
    for (unsigned int i = 0; i < 0x16; ++i) {
        NiPixelFormat* p;
        switch (i) {
    case 0:
        p = new NPFNew(DAT_011aa888);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 1:
        p = new NPFNew(DAT_011aa8d0);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 3:
        p = new NPFNew(DAT_011aa960);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 4:
        p = new NPFNew(DAT_011aa9f0);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 5:
        p = new NPFNew(DAT_011aaac8);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 6:
    case 7:
        p = 0;
        break;
    case 8:
        p = new NPFNew(DAT_011aa498);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 9:
        p = new NPFNew(DAT_011aa4e0);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 10:
        p = new NPFNew(DAT_011aa528);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 11:
        p = new NPFNew(DAT_011aa408);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 12:
        p = new NPFNew(DAT_011aad08);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 13:
        p = new NPFNew(DAT_011aa450);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 2:
    case 22:
        p = new NPFNew(DAT_011aab58);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 14:
        p = new NPFNew(DAT_011aa720);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 15:
        p = new NPFNew(DAT_011aa768);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 16:
        p = new NPFNew(DAT_011aa6d8);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 17:
        p = new NPFNew(DAT_011aa648);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 18:
        p = new NPFNew(DAT_011aa5b8);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 19:
        p = new NPFNew(DAT_011aa600);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 20:
        p = new NPFNew(DAT_011aa690);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
    case 21:
        p = new NPFNew(DAT_011aa570);
        p->unk0c = FUN_00e7bd20((int)p);
        p->unk10 = i;
        break;
        }
        if (p) {
            g_memoryManager.Deallocate(state[i].m_pkFormat);
            unsigned int hint = p->unk0c;
            if (((DeviceE6DF*)DAT_0126f0d8)->CreateTexture(((BridgeFields*)this)->m_uiImageWidth, ((BridgeFields*)this)->m_uiImageHeight, ((BridgeFields*)this)->m_ui5d0, 0, flags, hint)) {
                g_memoryManager.Deallocate(p);
                p = 0;
            }
            state[i].m_pkFormat = p;
        }
    }
}

struct Packet;
struct Inner {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int count;
    struct Entry* entries;
};
struct Arg3 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Inner* inner;
};
struct EntryTail {
    unsigned short w1c;
    unsigned short w1e;
    unsigned short w20;
    unsigned short w22;
    unsigned int unk24;
    Packet* packet;
};
struct Entry {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int f14;
    unsigned int f18;
    EntryTail tail;
};
struct StreamObj {
    unsigned int unk00;
    unsigned int key;
};
struct Packet {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int count;
    unsigned int unk24;
    StreamObj** streams;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int f40;
    unsigned int f44;
    unsigned int f48;
    unsigned int f4c;
    unsigned int f50;
    bool __thiscall FUN_00e8eeb0();
    StreamObj* GetStream(unsigned int uiIndex) {
        return uiIndex < count ? streams[uiIndex] : 0;
    }
};
struct NewObj {
    void* f00;
    void* f04;
    Entry* f08;
    void* f0c;
    void* f10;
    void* f14;
    Packet* f18;
    unsigned int f1c;
    unsigned int f20;
    void Init(void* a, void* b, Entry* c, void* d, void* e, void* f, Packet* g, unsigned int h) {
        f00 = a; f04 = b; f08 = c; f0c = d; f10 = e; f14 = f; f20 = 0; f18 = g; f1c = h;
    }
};
struct Map610 {
    bool __thiscall FUN_00a53c30(unsigned int uiKey, unsigned int* puiOut);
    void __thiscall InsertOrUpdate(unsigned int uiKey, void* pkObj);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct ThisObj {
    unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
unsigned int unk160;
unsigned int unk164;
unsigned int unk168;
unsigned int unk16c;
unsigned int unk170;
unsigned int unk174;
unsigned int unk178;
unsigned int unk17c;
unsigned int unk180;
unsigned int unk184;
unsigned int unk188;
unsigned int unk18c;
unsigned int unk190;
unsigned int unk194;
unsigned int unk198;
unsigned int unk19c;
unsigned int unk1a0;
unsigned int unk1a4;
unsigned int unk1a8;
unsigned int unk1ac;
unsigned int unk1b0;
unsigned int unk1b4;
unsigned int unk1b8;
unsigned int unk1bc;
unsigned int unk1c0;
unsigned int unk1c4;
unsigned int unk1c8;
unsigned int unk1cc;
unsigned int unk1d0;
unsigned int unk1d4;
unsigned int unk1d8;
unsigned int unk1dc;
unsigned int unk1e0;
unsigned int unk1e4;
unsigned int unk1e8;
unsigned int unk1ec;
unsigned int unk1f0;
unsigned int unk1f4;
unsigned int unk1f8;
unsigned int unk1fc;
unsigned int unk200;
unsigned int unk204;
unsigned int unk208;
unsigned int unk20c;
unsigned int unk210;
unsigned int unk214;
unsigned int unk218;
unsigned int unk21c;
unsigned int unk220;
unsigned int unk224;
unsigned int unk228;
unsigned int unk22c;
unsigned int unk230;
unsigned int unk234;
unsigned int unk238;
unsigned int unk23c;
unsigned int unk240;
unsigned int unk244;
unsigned int unk248;
unsigned int unk24c;
unsigned int unk250;
unsigned int unk254;
unsigned int unk258;
unsigned int unk25c;
unsigned int unk260;
unsigned int unk264;
unsigned int unk268;
unsigned int unk26c;
unsigned int unk270;
unsigned int unk274;
unsigned int unk278;
unsigned int unk27c;
unsigned int unk280;
unsigned int unk284;
unsigned int unk288;
unsigned int unk28c;
unsigned int unk290;
unsigned int unk294;
unsigned int unk298;
unsigned int unk29c;
unsigned int unk2a0;
unsigned int unk2a4;
unsigned int unk2a8;
unsigned int unk2ac;
unsigned int unk2b0;
unsigned int unk2b4;
unsigned int unk2b8;
unsigned int unk2bc;
unsigned int unk2c0;
unsigned int unk2c4;
unsigned int unk2c8;
unsigned int unk2cc;
unsigned int unk2d0;
unsigned int unk2d4;
unsigned int unk2d8;
unsigned int unk2dc;
unsigned int unk2e0;
unsigned int unk2e4;
unsigned int unk2e8;
unsigned int unk2ec;
unsigned int unk2f0;
unsigned int unk2f4;
unsigned int unk2f8;
unsigned int unk2fc;
unsigned int unk300;
unsigned int unk304;
unsigned int unk308;
unsigned int unk30c;
unsigned int unk310;
unsigned int unk314;
unsigned int unk318;
unsigned int unk31c;
unsigned int unk320;
unsigned int unk324;
unsigned int unk328;
unsigned int unk32c;
unsigned int unk330;
unsigned int unk334;
unsigned int unk338;
unsigned int unk33c;
unsigned int unk340;
unsigned int unk344;
unsigned int unk348;
unsigned int unk34c;
unsigned int unk350;
unsigned int unk354;
unsigned int unk358;
unsigned int unk35c;
unsigned int unk360;
unsigned int unk364;
unsigned int unk368;
unsigned int unk36c;
unsigned int unk370;
unsigned int unk374;
unsigned int unk378;
unsigned int unk37c;
unsigned int unk380;
unsigned int unk384;
unsigned int unk388;
unsigned int unk38c;
unsigned int unk390;
unsigned int unk394;
unsigned int unk398;
unsigned int unk39c;
unsigned int unk3a0;
unsigned int unk3a4;
unsigned int unk3a8;
unsigned int unk3ac;
unsigned int unk3b0;
unsigned int unk3b4;
unsigned int unk3b8;
unsigned int unk3bc;
unsigned int unk3c0;
unsigned int unk3c4;
unsigned int unk3c8;
unsigned int unk3cc;
unsigned int unk3d0;
unsigned int unk3d4;
unsigned int unk3d8;
unsigned int unk3dc;
unsigned int unk3e0;
unsigned int unk3e4;
unsigned int unk3e8;
unsigned int unk3ec;
unsigned int unk3f0;
unsigned int unk3f4;
unsigned int unk3f8;
unsigned int unk3fc;
unsigned int unk400;
unsigned int unk404;
unsigned int unk408;
unsigned int unk40c;
unsigned int unk410;
unsigned int unk414;
unsigned int unk418;
unsigned int unk41c;
unsigned int unk420;
unsigned int unk424;
unsigned int unk428;
unsigned int unk42c;
unsigned int unk430;
unsigned int unk434;
unsigned int unk438;
unsigned int unk43c;
unsigned int unk440;
unsigned int unk444;
unsigned int unk448;
unsigned int unk44c;
unsigned int unk450;
unsigned int unk454;
unsigned int unk458;
unsigned int unk45c;
unsigned int unk460;
unsigned int unk464;
unsigned int unk468;
unsigned int unk46c;
unsigned int unk470;
unsigned int unk474;
unsigned int unk478;
unsigned int unk47c;
unsigned int unk480;
unsigned int unk484;
unsigned int unk488;
unsigned int unk48c;
unsigned int unk490;
unsigned int unk494;
unsigned int unk498;
unsigned int unk49c;
unsigned int unk4a0;
unsigned int unk4a4;
unsigned int unk4a8;
unsigned int unk4ac;
unsigned int unk4b0;
unsigned int unk4b4;
unsigned int unk4b8;
unsigned int unk4bc;
unsigned int unk4c0;
unsigned int unk4c4;
unsigned int unk4c8;
unsigned int unk4cc;
unsigned int unk4d0;
unsigned int unk4d4;
unsigned int unk4d8;
unsigned int unk4dc;
unsigned int unk4e0;
unsigned int unk4e4;
unsigned int unk4e8;
unsigned int unk4ec;
unsigned int unk4f0;
unsigned int unk4f4;
unsigned int unk4f8;
unsigned int unk4fc;
unsigned int unk500;
unsigned int unk504;
unsigned int unk508;
unsigned int unk50c;
unsigned int unk510;
unsigned int unk514;
unsigned int unk518;
unsigned int unk51c;
unsigned int unk520;
unsigned int unk524;
unsigned int unk528;
unsigned int unk52c;
unsigned int unk530;
unsigned int unk534;
unsigned int unk538;
unsigned int unk53c;
unsigned int unk540;
unsigned int unk544;
unsigned int unk548;
unsigned int unk54c;
unsigned int unk550;
unsigned int unk554;
unsigned int unk558;
unsigned int unk55c;
unsigned int unk560;
unsigned int unk564;
unsigned int unk568;
unsigned int unk56c;
unsigned int unk570;
unsigned int unk574;
unsigned int unk578;
unsigned int unk57c;
unsigned int unk580;
unsigned int unk584;
unsigned int unk588;
unsigned int unk58c;
unsigned int unk590;
unsigned int unk594;
unsigned int unk598;
unsigned int unk59c;
unsigned int unk5a0;
unsigned int unk5a4;
unsigned int unk5a8;
unsigned int unk5ac;
unsigned int unk5b0;
unsigned int unk5b4;
unsigned int unk5b8;
unsigned int unk5bc;
unsigned int unk5c0;
unsigned int unk5c4;
unsigned int unk5c8;
unsigned int unk5cc;
unsigned int unk5d0;
unsigned int unk5d4;
unsigned int unk5d8;
unsigned int unk5dc;
unsigned int unk5e0;
unsigned int unk5e4;
unsigned int unk5e8;
unsigned int unk5ec;
unsigned int unk5f0;
unsigned int unk5f4;
unsigned int unk5f8;
unsigned int unk5fc;
unsigned int unk600;
unsigned int unk604;
unsigned int unk608;
unsigned int unk60c;
    Map610 map;
    bool __thiscall BuildPacket(Packet* pkPacket, void* pkModel, Entry* pkEntry, void* pkGeom);
    bool __thiscall BuildPacketEntries(void* a1, void* pkModel, Arg3* pkArg3, void* pkGeom, void* a5, void* a6);
};

// Iterates over pkArg3 entries, builds packets via BuildPacket, and inserts resulting stream objects into map keyed by stream key.
// @fnv 0x00e72aa0
bool __thiscall ThisObj::BuildPacketEntries(void* a1, void* pkModel, Arg3* pkArg3, void* pkGeom, void* a5, void* a6)
{
    Entry* pkEntries = pkArg3->inner->entries;
    unsigned int ItemUpdateArray = pkArg3->inner->count;
    bool bResult = true;
    for (unsigned int n = 0; n < ItemUpdateArray; n++) {
        {
            Packet* pkPacket = pkEntries[n].tail.packet;
            if (!pkPacket->FUN_00e8eeb0()) {
                unsigned short us1c = pkEntries[n].tail.w1c;
                unsigned short us22 = pkEntries[n].tail.w22;
                unsigned short us1e = pkEntries[n].tail.w1e;
                unsigned int uiF14 = pkEntries[n].f14;
                unsigned int uiF18 = pkEntries[n].f18;
                pkPacket->f18 = us1c;
                
                unsigned int ui22; if (!us22) {ui22=1;pkPacket->f1c = us1c;} else {ui22=us22;pkPacket->f1c = us1c;} pkPacket->f48=ui22;
                pkPacket->f40 = us1e;
                pkPacket->f44 = us1e;
                pkPacket->f50 = uiF14;
                pkPacket->f4c = uiF18;
                if (BuildPacket(pkPacket, pkModel, &pkEntries[n], pkGeom)) {
                    unsigned int uiStreamCount = pkPacket->count;
                    {
                        for (unsigned int i = 0; i < uiStreamCount; i++) {
                            StreamObj* pkStream = pkPacket->GetStream(i);
                            unsigned int uiKey = pkStream->key;
                            NewObj* pkObj = (NewObj*)Object_DispatchCommandFour(0x24);
                            pkObj->Init(pkModel, pkArg3, &pkEntries[n], pkGeom, a5, a6, pkPacket, i);
                            unsigned int uiOut;
                            pkObj->f20 = map.FUN_00a53c30(uiKey, &uiOut) ? uiOut : 0;
                            map.InsertOrUpdate(uiKey, pkObj);
                        }
                    }
                } else {
                    bResult = false;
                }
            }
        }
    }
    return bResult;
}

extern "C" void* __cdecl memset(void*,int,unsigned int);
extern "C" void* __cdecl FUN_00ec61c0(void*,int,unsigned int);
struct InitAdapterList;
extern InitAdapterList* DAT_0126f0e8;
struct InitRenderer;
struct InitPresent {
 unsigned width, height, format, backBufferCount, multiSampleType, multiSampleQuality, swapEffect;
 void* deviceWindow;
 int windowed, enableAutoDepthStencil;
 unsigned autoDepthStencilFormat, flags, refreshRate, interval;
};
struct InitDisplay { unsigned size, width, height, refreshRate, format, scanLineOrdering; };
struct InitDevice;
struct InitD3DTable {

 void* slot0;
 void* slot1;
 void* slot2;
 void* slot3;
 void* slot4;
 void* slot5;
 void* slot6;
 void* slot7;
 void* slot8;
 void* slot9;
 void* slot10;
 void* slot11;
 void* slot12;
 void* slot13;
 void* slot14;
 void* slot15;
 int (__stdcall *CreateDevice)(void*,unsigned,unsigned,unsigned,unsigned,InitPresent*,InitDevice**);
 void* slot17;
 void* slot18;
 void* slot19;
 int (__stdcall *CreateDeviceEx)(void*,unsigned,unsigned,unsigned,unsigned,InitPresent*,InitDisplay*,InitDevice**);
};
struct InitD3D { InitD3DTable* table; };
struct InitFormat { unsigned field0,field4,field8,format; };
struct InitState {

 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual InitFormat* GetFormat(unsigned);
 virtual void slot40();
 virtual void slot41();
 virtual void SetColor(void*, unsigned);
 virtual void SetDepth(void*);
};
struct InitSmartState { InitState* pointer; __forceinline InitSmartState(InitState* p) { FUN_00b6aed0(p); } InitSmartState(const InitSmartState&); void FUN_00b6aed0(InitState*); };
struct InitStateMap { void SetMapEntryWithReferenceCounting(unsigned, InitSmartState); };
struct InitDevice { void* table; };
struct InitBuffer { unsigned field0, valid; static InitBuffer* Valid(InitBuffer* b) { return b->valid ? b : 0; } static InitBuffer* Valid2(InitBuffer* b) { if(b->valid) return b; return 0; } };
struct InitAdapter {

 unsigned field000;
 unsigned field004;
 unsigned field008;
 unsigned field00c;
 unsigned field010;
 unsigned field014;
 unsigned field018;
 unsigned field01c;
 unsigned field020;
 unsigned field024;
 unsigned field028;
 unsigned field02c;
 unsigned field030;
 unsigned field034;
 unsigned field038;
 unsigned field03c;
 unsigned field040;
 unsigned field044;
 unsigned field048;
 unsigned field04c;
 unsigned field050;
 unsigned field054;
 unsigned field058;
 unsigned field05c;
 unsigned field060;
 unsigned field064;
 unsigned field068;
 unsigned field06c;
 unsigned field070;
 unsigned field074;
 unsigned field078;
 unsigned field07c;
 unsigned field080;
 unsigned field084;
 unsigned field088;
 unsigned field08c;
 unsigned field090;
 unsigned field094;
 unsigned field098;
 unsigned field09c;
 unsigned field0a0;
 unsigned field0a4;
 unsigned field0a8;
 unsigned field0ac;
 unsigned field0b0;
 unsigned field0b4;
 unsigned field0b8;
 unsigned field0bc;
 unsigned field0c0;
 unsigned field0c4;
 unsigned field0c8;
 unsigned field0cc;
 unsigned field0d0;
 unsigned field0d4;
 unsigned field0d8;
 unsigned field0dc;
 unsigned field0e0;
 unsigned field0e4;
 unsigned field0e8;
 unsigned field0ec;
 unsigned field0f0;
 unsigned field0f4;
 unsigned field0f8;
 unsigned field0fc;
 unsigned field100;
 unsigned field104;
 unsigned field108;
 unsigned field10c;
 unsigned field110;
 unsigned field114;
 unsigned field118;
 unsigned field11c;
 unsigned field120;
 unsigned field124;
 unsigned field128;
 unsigned field12c;
 unsigned field130;
 unsigned field134;
 unsigned field138;
 unsigned field13c;
 unsigned field140;
 unsigned field144;
 unsigned field148;
 unsigned field14c;
 unsigned field150;
 unsigned field154;
 unsigned field158;
 unsigned field15c;
 unsigned field160;
 unsigned field164;
 unsigned field168;
 unsigned field16c;
 unsigned field170;
 unsigned field174;
 unsigned field178;
 unsigned field17c;
 unsigned field180;
 unsigned field184;
 unsigned field188;
 unsigned field18c;
 unsigned field190;
 unsigned field194;
 unsigned field198;
 unsigned field19c;
 unsigned field1a0;
 unsigned field1a4;
 unsigned field1a8;
 unsigned field1ac;
 unsigned field1b0;
 unsigned field1b4;
 unsigned field1b8;
 unsigned field1bc;
 unsigned field1c0;
 unsigned field1c4;
 unsigned field1c8;
 unsigned field1cc;
 unsigned field1d0;
 unsigned field1d4;
 unsigned field1d8;
 unsigned field1dc;
 unsigned field1e0;
 unsigned field1e4;
 unsigned field1e8;
 unsigned field1ec;
 unsigned field1f0;
 unsigned field1f4;
 unsigned field1f8;
 unsigned field1fc;
 unsigned field200;
 unsigned field204;
 unsigned field208;
 unsigned field20c;
 unsigned field210;
 unsigned field214;
 unsigned field218;
 unsigned field21c;
 unsigned field220;
 unsigned field224;
 unsigned field228;
 unsigned field22c;
 unsigned field230;
 unsigned field234;
 unsigned field238;
 unsigned field23c;
 unsigned field240;
 unsigned field244;
 unsigned field248;
 unsigned field24c;
 unsigned field250;
 unsigned field254;
 unsigned field258;
 unsigned field25c;
 unsigned field260;
 unsigned field264;
 unsigned field268;
 unsigned field26c;
 unsigned field270;
 unsigned field274;
 unsigned field278;
 unsigned field27c;
 unsigned field280;
 unsigned field284;
 unsigned field288;
 unsigned field28c;
 unsigned field290;
 unsigned field294;
 unsigned field298;
 unsigned field29c;
 unsigned field2a0;
 unsigned field2a4;
 unsigned field2a8;
 unsigned field2ac;
 unsigned field2b0;
 unsigned field2b4;
 unsigned field2b8;
 unsigned field2bc;
 unsigned field2c0;
 unsigned field2c4;
 unsigned field2c8;
 unsigned field2cc;
 unsigned field2d0;
 unsigned field2d4;
 unsigned field2d8;
 unsigned field2dc;
 unsigned field2e0;
 unsigned field2e4;
 unsigned field2e8;
 unsigned field2ec;
 unsigned field2f0;
 unsigned field2f4;
 unsigned field2f8;
 unsigned field2fc;
 unsigned field300;
 unsigned field304;
 unsigned field308;
 unsigned field30c;
 unsigned field310;
 unsigned field314;
 unsigned field318;
 unsigned field31c;
 unsigned field320;
 unsigned field324;
 unsigned field328;
 unsigned field32c;
 unsigned field330;
 unsigned field334;
 unsigned field338;
 unsigned field33c;
 unsigned field340;
 unsigned field344;
 unsigned field348;
 unsigned field34c;
 unsigned field350;
 unsigned field354;
 unsigned field358;
 unsigned field35c;
 unsigned field360;
 unsigned field364;
 unsigned field368;
 unsigned field36c;
 unsigned field370;
 unsigned field374;
 unsigned field378;
 unsigned field37c;
 unsigned field380;
 unsigned field384;
 unsigned field388;
 unsigned field38c;
 unsigned field390;
 unsigned field394;
 unsigned field398;
 unsigned field39c;
 unsigned field3a0;
 unsigned field3a4;
 unsigned field3a8;
 unsigned field3ac;
 unsigned field3b0;
 unsigned field3b4;
 unsigned field3b8;
 unsigned field3bc;
 unsigned field3c0;
 unsigned field3c4;
 unsigned field3c8;
 unsigned field3cc;
 unsigned field3d0;
 unsigned field3d4;
 unsigned field3d8;
 unsigned field3dc;
 unsigned field3e0;
 unsigned field3e4;
 unsigned field3e8;
 unsigned field3ec;
 unsigned field3f0;
 unsigned field3f4;
 unsigned field3f8;
 unsigned field3fc;
 unsigned field400;
 unsigned field404;
 unsigned field408;
 unsigned field40c;
 unsigned field410;
 unsigned field414;
 unsigned field418;
 unsigned field41c;
 unsigned field420;
 unsigned field424;
 unsigned field428;
 unsigned field42c;
 unsigned field430;
 unsigned field434;
 unsigned field438;
 unsigned field43c;
 unsigned field440;
 unsigned field444;
 unsigned field448;
 unsigned field44c;
 unsigned field450;
 unsigned field454;
 unsigned field458;
 unsigned field45c;
 InitBuffer* hardware;
 InitBuffer* software;
 InitBuffer* GetBuffer(unsigned type) { return type==1 ? InitBuffer::Valid(hardware) : InitBuffer::Valid(software); }
 InitBuffer* GetBuffer2(unsigned type) { return type==1 ? InitBuffer::Valid2(hardware) : InitBuffer::Valid2(software); }
};
struct InitAdapterList { unsigned field0,field4; InitAdapter** data; unsigned short fieldc,count; InitAdapter* GetAt(unsigned i) { return i < count ? data[i] : 0; } };
struct InitCaps {

 unsigned field00;
 unsigned field04;
 unsigned field08;
 unsigned field0c;
 unsigned field10;
 unsigned field14;
 unsigned field18;
 unsigned field1c;
 unsigned field20;
 unsigned field24;
 unsigned field28;
 unsigned field2c;
 unsigned field30;
};
struct InitManager {
 virtual void slot0(); virtual unsigned GetBuffer(unsigned);
 void FUN_00e88c20(bool);
};
struct InitVertexManager { void* table; };
struct InitVertexTable {

 void* slot0;
 void* slot1;
 void* slot2;
 void* slot3;
 void* slot4;
 void* slot5;
 void* slot6;
 void* slot7;
 void* slot8;
 void* slot9;
 void* slot10;
 void* slot11;
 void* slot12;
 void (__thiscall *Enable)(void*,unsigned);
};
struct InitTextureManager { InitTextureManager* FUN_00e8d0e0(InitDevice*); };
struct InitLightManager { InitLightManager* FUN_00e8fb20(InitDevice*); };
struct InitGeometryManager { InitGeometryManager* NiDX9TextureManager_NiDX9TextureManager(InitRenderer*); };
struct InitShaderManager { InitShaderManager* NiDX9LightManager_NiDX9LightManager(InitVertexManager*, InitDevice*); };
struct InitObject {

 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void Initialize();
 InitObject* NiDX9ErrorShader_NiDX9ErrorShader();
};

struct InitPoint { float x,y,z; };
struct InitViewport { float left,right,top,bottom; };
extern InitPoint DAT_011a9484, DAT_011a9478, DAT_011a946c, DAT_011f426c;
extern float DAT_0126efd4;
extern unsigned char DAT_0126efd1;
bool __cdecl SetModeFlags(unsigned,unsigned*,unsigned*);
unsigned __cdecl MapCodeToIndex(unsigned);
InitCaps* __cdecl FUN_00e7d6b0(InitDevice*,InitPresent*,void**);
void __cdecl FUN_00e7d850(InitDevice*,void**);
InitState* __cdecl CreateShaderLevel(unsigned,InitRenderer*);
InitVertexManager* __cdecl CreateRenderer(InitRenderer*,void*,unsigned);
void __cdecl FUN_00e81940(InitRenderer*);
InitManager* __cdecl FUN_00e88eb0(InitDevice*,InitTextureManager*);

extern const char DAT_010ee20c[];
extern const char DAT_010ee1c8[];
extern const char DAT_010ee1a0[];
extern const char DAT_010ee160[];
extern const char DAT_010ee118[];
extern const char DAT_010ee0e8[];
extern const char DAT_010ee0ac[];
extern const char DAT_010ee048[];
extern const char DAT_010edfe0[];
extern const char DAT_010edfac[];
extern const char DAT_010edf60[];
extern const char DAT_010edf10[];
extern const char DAT_010ededc[];
extern const char DAT_010ede88[];
extern const char DAT_010ede30[];
struct InitRenderer {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void slot39();
 virtual unsigned GetFlags();
 virtual void slot41();
 virtual void slot42();
 virtual void slot43();
 virtual void slot44();
 virtual void slot45();
 virtual void slot46();
 virtual void slot47();
 virtual void slot48();
 virtual void slot49();
 virtual void slot50();
 virtual void slot51();
 virtual void slot52();
 virtual void slot53();
 virtual void slot54();
 virtual void slot55();
 virtual void slot56();
 virtual void slot57();
 virtual void slot58();
 virtual void slot59();
 virtual void slot60();
 virtual void slot61();
 virtual void slot62();
 virtual void slot63();
 virtual void slot64();
 virtual void slot65();
 virtual void slot66();
 virtual void slot67();
 virtual void slot68();
 virtual void slot69();
 virtual void slot70();
 virtual void slot71();
 virtual void slot72();
 virtual void slot73();
 virtual void slot74();
 virtual void slot75();
 virtual void slot76();
 virtual void slot77();
 virtual void slot78();
 virtual void slot79();
 virtual void slot80();
 virtual void slot81();
 virtual void slot82();
 virtual void slot83();
 virtual void slot84();
 virtual void slot85();
 virtual void slot86();
 virtual void slot87();
 virtual void slot88();
 virtual void slot89();
 virtual void slot90();
 virtual void slot91();
 virtual void slot92();
 virtual void slot93();
 virtual void slot94();
 virtual void slot95();
 virtual void slot96();
 virtual void slot97();
 virtual void slot98();
 virtual void SetCamera(InitPoint*,InitPoint*,InitPoint*,InitPoint*,NiFrustum*,InitViewport*);
 unsigned field004;
 unsigned field008;
 unsigned field00c;
 unsigned field010;
 unsigned field014;
 unsigned field018;
 unsigned field01c;
 unsigned field020;
 unsigned field024;
 unsigned field028;
 unsigned field02c;
 unsigned field030;
 unsigned field034;
 unsigned field038;
 unsigned field03c;
 unsigned field040;
 unsigned field044;
 unsigned field048;
 unsigned field04c;
 unsigned field050;
 unsigned field054;
 unsigned field058;
 unsigned field05c;
 unsigned field060;
 unsigned field064;
 unsigned field068;
 unsigned field06c;
 unsigned field070;
 unsigned field074;
 unsigned field078;
 unsigned field07c;
 unsigned field080;
 unsigned field084;
 unsigned field088;
 unsigned field08c;
 unsigned field090;
 unsigned field094;
 unsigned field098;
 unsigned field09c;
 unsigned field0a0;
 unsigned field0a4;
 unsigned field0a8;
 unsigned field0ac;
 unsigned field0b0;
 unsigned field0b4;
 unsigned field0b8;
 unsigned field0bc;
 unsigned field0c0;
 unsigned field0c4;
 unsigned field0c8;
 unsigned field0cc;
 unsigned field0d0;
 unsigned field0d4;
 unsigned field0d8;
 unsigned field0dc;
 unsigned field0e0;
 unsigned field0e4;
 unsigned field0e8;
 unsigned field0ec;
 unsigned field0f0;
 unsigned field0f4;
 unsigned field0f8;
 unsigned field0fc;
 unsigned field100;
 unsigned field104;
 unsigned field108;
 unsigned field10c;
 unsigned field110;
 unsigned field114;
 unsigned field118;
 unsigned field11c;
 unsigned field120;
 unsigned field124;
 unsigned field128;
 unsigned field12c;
 unsigned field130;
 unsigned field134;
 unsigned field138;
 unsigned field13c;
 unsigned field140;
 unsigned field144;
 unsigned field148;
 unsigned field14c;
 unsigned field150;
 unsigned field154;
 unsigned field158;
 unsigned field15c;
 unsigned field160;
 unsigned field164;
 unsigned field168;
 unsigned field16c;
 unsigned field170;
 unsigned field174;
 unsigned field178;
 unsigned field17c;
 unsigned field180;
 unsigned field184;
 unsigned field188;
 unsigned field18c;
 unsigned field190;
 unsigned field194;
 unsigned field198;
 unsigned field19c;
 unsigned field1a0;
 unsigned field1a4;
 unsigned field1a8;
 unsigned field1ac;
 unsigned field1b0;
 unsigned field1b4;
 unsigned field1b8;
 unsigned field1bc;
 unsigned field1c0;
 unsigned field1c4;
 unsigned field1c8;
 unsigned field1cc;
 unsigned field1d0;
 unsigned field1d4;
 unsigned field1d8;
 unsigned field1dc;
 unsigned field1e0;
 unsigned field1e4;
 unsigned field1e8;
 unsigned field1ec;
 unsigned field1f0;
 unsigned field1f4;
 unsigned field1f8;
 unsigned field1fc;
 unsigned field200;
 unsigned field204;
 unsigned field208;
 unsigned field20c;
 unsigned field210;
 unsigned field214;
 unsigned field218;
 unsigned field21c;
 unsigned field220;
 unsigned field224;
 unsigned field228;
 unsigned field22c;
 unsigned field230;
 unsigned field234;
 unsigned field238;
 unsigned field23c;
 unsigned field240;
 unsigned field244;
 unsigned field248;
 unsigned field24c;
 unsigned field250;
 unsigned field254;
 unsigned field258;
 unsigned field25c;
 unsigned field260;
 unsigned field264;
 unsigned field268;
 unsigned field26c;
 unsigned field270;
 unsigned field274;
 unsigned field278;
 unsigned field27c;
 unsigned field280;
 unsigned field284;
 InitDevice* device;
 unsigned field28c;
 unsigned field290;
 unsigned field294;
 unsigned field298;
 unsigned field29c;
 unsigned field2a0;
 unsigned field2a4;
 unsigned field2a8;
 unsigned field2ac;
 unsigned field2b0;
 unsigned field2b4;
 unsigned field2b8;
 unsigned field2bc;
 unsigned field2c0;
 unsigned field2c4;
 unsigned field2c8;
 unsigned field2cc;
 unsigned field2d0;
 unsigned field2d4;
 unsigned field2d8;
 unsigned field2dc;
 unsigned field2e0;
 unsigned field2e4;
 unsigned field2e8;
 unsigned field2ec;
 unsigned field2f0;
 unsigned field2f4;
 unsigned field2f8;
 unsigned field2fc;
 unsigned field300;
 unsigned field304;
 unsigned field308;
 unsigned field30c;
 unsigned field310;
 unsigned field314;
 unsigned field318;
 unsigned field31c;
 unsigned field320;
 unsigned field324;
 unsigned field328;
 unsigned field32c;
 unsigned field330;
 unsigned field334;
 unsigned field338;
 unsigned field33c;
 unsigned field340;
 unsigned field344;
 unsigned field348;
 unsigned field34c;
 unsigned field350;
 unsigned field354;
 unsigned field358;
 unsigned field35c;
 unsigned field360;
 unsigned field364;
 unsigned field368;
 unsigned field36c;
 unsigned field370;
 unsigned field374;
 unsigned field378;
 unsigned field37c;
 unsigned field380;
 unsigned field384;
 unsigned field388;
 unsigned field38c;
 unsigned field390;
 unsigned field394;
 unsigned field398;
 unsigned field39c;
 unsigned field3a0;
 unsigned field3a4;
 unsigned field3a8;
 unsigned field3ac;
 unsigned field3b0;
 unsigned field3b4;
 unsigned field3b8;
 unsigned field3bc;
 unsigned field3c0;
 unsigned field3c4;
 unsigned field3c8;
 unsigned field3cc;
 unsigned field3d0;
 unsigned field3d4;
 unsigned field3d8;
 unsigned field3dc;
 unsigned field3e0;
 unsigned field3e4;
 unsigned field3e8;
 unsigned field3ec;
 unsigned field3f0;
 unsigned field3f4;
 unsigned field3f8;
 unsigned field3fc;
 unsigned field400;
 unsigned field404;
 unsigned field408;
 unsigned field40c;
 unsigned field410;
 unsigned field414;
 unsigned field418;
 unsigned field41c;
 unsigned field420;
 unsigned field424;
 unsigned field428;
 unsigned field42c;
 unsigned field430;
 unsigned field434;
 unsigned field438;
 unsigned field43c;
 unsigned field440;
 unsigned field444;
 unsigned field448;
 unsigned field44c;
 unsigned field450;
 unsigned field454;
 unsigned field458;
 unsigned field45c;
 unsigned field460;
 unsigned field464;
 unsigned field468;
 unsigned field46c;
 unsigned field470;
 unsigned field474;
 unsigned field478;
 unsigned field47c;
 unsigned field480;
 unsigned field484;
 unsigned field488;
 unsigned field48c;
 unsigned field490;
 unsigned field494;
 unsigned field498;
 unsigned field49c;
 unsigned field4a0;
 unsigned field4a4;
 unsigned field4a8;
 unsigned field4ac;
 unsigned field4b0;
 unsigned field4b4;
 unsigned field4b8;
 unsigned field4bc;
 unsigned field4c0;
 unsigned field4c4;
 unsigned field4c8;
 unsigned field4cc;
 unsigned field4d0;
 unsigned field4d4;
 unsigned field4d8;
 unsigned field4dc;
 unsigned field4e0;
 unsigned field4e4;
 unsigned field4e8;
 unsigned field4ec;
 unsigned field4f0;
 unsigned field4f4;
 unsigned field4f8;
 unsigned field4fc;
 unsigned field500;
 unsigned field504;
 unsigned field508;
 unsigned field50c;
 unsigned field510;
 unsigned field514;
 unsigned field518;
 unsigned field51c;
 unsigned field520;
 unsigned field524;
 unsigned field528;
 unsigned field52c;
 unsigned field530;
 unsigned field534;
 unsigned field538;
 unsigned field53c;
 unsigned field540;
 unsigned field544;
 unsigned field548;
 unsigned field54c;
 unsigned field550;
 unsigned field554;
 unsigned field558;
 unsigned field55c;
 unsigned field560;
 unsigned field564;
 unsigned field568;
 unsigned field56c;
 unsigned field570;
 unsigned field574;
 unsigned field578;
 unsigned field57c;
 unsigned field580;
 unsigned field584;
 unsigned field588;
 unsigned field58c;
 unsigned field590;
 unsigned field594;
 unsigned field598;
 unsigned field59c;
 unsigned field5a0;
 unsigned field5a4;
 unsigned field5a8;
 unsigned field5ac;
 unsigned field5b0;
 unsigned field5b4;
 unsigned field5b8;
 unsigned field5bc;
 unsigned field5c0;
 unsigned field5c4;
 unsigned field5c8;
 unsigned field5cc;
 unsigned field5d0;
 unsigned char flag5d4,flag5d5,field5d6,field5d7;
 InitAdapter* adapter;
 InitBuffer* buffer;
 unsigned field5e0;
 unsigned field5e4;
 unsigned field5e8;
 unsigned field5ec;
 unsigned field5f0;
 unsigned field5f4;
 unsigned field5f8;
 unsigned field5fc;
 unsigned field600;
 unsigned field604;
 unsigned field608;
 unsigned field60c;
 unsigned field610;
 unsigned field614;
 unsigned field618;
 unsigned field61c;
 unsigned field620;
 unsigned field624;
 unsigned field628;
 unsigned field62c;
 unsigned field630;
 unsigned field634;
 unsigned field638;
 unsigned field63c;
 unsigned field640;
 unsigned field644;
 unsigned field648;
 unsigned field64c;
 unsigned field650;
 unsigned field654;
 unsigned field658;
 unsigned field65c;
 unsigned field660;
 unsigned field664;
 unsigned field668;
 unsigned field66c;
 unsigned field670;
 unsigned field674;
 unsigned field678;
 unsigned field67c;
 unsigned field680;
 unsigned field684;
 unsigned field688;
 unsigned field68c;
 unsigned field690;
 unsigned field694;
 unsigned field698;
 unsigned field69c;
 unsigned field6a0;
 unsigned field6a4;
 unsigned field6a8;
 unsigned field6ac;
 unsigned field6b0;
 unsigned field6b4;
 unsigned field6b8;
 unsigned field6bc;
 unsigned field6c0;
 unsigned field6c4;
 unsigned field6c8;
 unsigned field6cc;
 unsigned field6d0;
 unsigned field6d4;
 unsigned field6d8;
 unsigned field6dc;
 unsigned field6e0;
 unsigned field6e4;
 unsigned field6e8;
 unsigned field6ec;
 unsigned field6f0;
 unsigned field6f4;
 unsigned field6f8;
 unsigned char flag6fc,field6fd,field6fe,field6ff;
 unsigned field700;
 unsigned field704;
 unsigned field708;
 unsigned field70c;
 unsigned field710;
 unsigned field714;
 unsigned field718;
 unsigned field71c;
 unsigned field720;
 unsigned field724;
 unsigned field728;
 unsigned field72c;
 unsigned field730;
 unsigned field734;
 unsigned field738;
 unsigned field73c;
 unsigned field740;
 unsigned field744;
 unsigned field748;
 unsigned field74c;
 unsigned field750;
 unsigned field754;
 unsigned field758;
 unsigned field75c;
 unsigned field760;
 unsigned field764;
 unsigned field768;
 unsigned field76c;
 unsigned field770;
 unsigned field774;
 unsigned field778;
 unsigned field77c;
 unsigned field780;
 unsigned field784;
 unsigned field788;
 unsigned field78c;
 unsigned field790;
 unsigned field794;
 unsigned field798;
 unsigned field79c;
 unsigned field7a0;
 unsigned field7a4;
 unsigned field7a8;
 unsigned field7ac;
 unsigned field7b0;
 unsigned field7b4;
 unsigned field7b8;
 unsigned field7bc;
 unsigned field7c0;
 unsigned field7c4;
 unsigned field7c8;
 unsigned field7cc;
 unsigned field7d0;
 unsigned field7d4;
 unsigned field7d8;
 unsigned field7dc;
 unsigned field7e0;
 unsigned field7e4;
 unsigned field7e8;
 unsigned field7ec;
 unsigned field7f0;
 unsigned field7f4;
 unsigned field7f8;
 unsigned field7fc;
 unsigned field800;
 unsigned field804;
 unsigned field808;
 unsigned field80c;
 unsigned field810;
 unsigned field814;
 unsigned field818;
 unsigned field81c;
 unsigned field820;
 unsigned field824;
 unsigned field828;
 unsigned field82c;
 unsigned field830;
 unsigned field834;
 unsigned field838;
 unsigned field83c;
 unsigned field840;
 unsigned field844;
 unsigned field848;
 unsigned field84c;
 unsigned field850;
 unsigned field854;
 unsigned field858;
 unsigned field85c;
 unsigned field860;
 unsigned field864;
 unsigned field868;
 unsigned field86c;
 unsigned field870;
 unsigned field874;
 unsigned field878;
 unsigned field87c;
 unsigned field880;
 InitState* state;
 InitState* currentState;
 unsigned activeState;
 InitStateMap stateMap;
 unsigned field894;
 unsigned field898;
 unsigned field89c;
 unsigned field8a0;
 unsigned field8a4;
 unsigned field8a8;
 InitManager* buffers;
 unsigned field8b0;
 unsigned field8b4;
 InitVertexManager* vertices;
 InitTextureManager* textures;
 InitLightManager* lights;
 InitGeometryManager* geometry;
 InitShaderManager* shaders;
 unsigned field8cc;
 unsigned field8d0;
 unsigned field8d4;
 unsigned field8d8;
 unsigned field8dc;
 unsigned field8e0;
 unsigned field8e4;
 unsigned field8e8;
 unsigned field8ec;
 unsigned field8f0;
 unsigned field8f4;
 unsigned field8f8;
 unsigned field8fc;
 unsigned field900;
 unsigned field904;
 unsigned field908;
 unsigned field90c;
 unsigned field910;
 unsigned field914;
 unsigned field918;
 unsigned field91c;
 unsigned field920;
 unsigned field924;
 unsigned field928;
 unsigned field92c;
 unsigned field930;
 unsigned field934;
 unsigned field938;
 unsigned field93c;
 unsigned field940;
 unsigned field944;
 unsigned field948;
 unsigned field94c;
 unsigned field950;
 unsigned field954;
 unsigned field958;
 unsigned field95c;
 unsigned field960;
 unsigned field964;
 unsigned field968;
 unsigned field96c;
 unsigned field970;
 unsigned field974;
 unsigned field978;
 unsigned field97c;
 unsigned field980;
 unsigned field984;
 unsigned field988;
 unsigned field98c;
 unsigned field990;
 unsigned field994;
 unsigned field998;
 unsigned field99c;
 unsigned field9a0;
 unsigned field9a4;
 unsigned field9a8;
 unsigned field9ac;
 unsigned field9b0;
 unsigned field9b4;
 unsigned field9b8;
 unsigned field9bc;
 unsigned field9c0;
 unsigned field9c4;
 unsigned field9c8;
 unsigned field9cc;
 unsigned field9d0;
 unsigned field9d4;
 unsigned field9d8;
 unsigned field9dc;
 unsigned field9e0;
 unsigned field9e4;
 unsigned field9e8;
 unsigned field9ec;
 unsigned field9f0;
 unsigned field9f4;
 unsigned field9f8;
 unsigned field9fc;
 unsigned fielda00;
 unsigned fielda04;
 unsigned fielda08;
 unsigned fielda0c;
 unsigned fielda10;
 unsigned fielda14;
 unsigned fielda18;
 unsigned fielda1c;
 unsigned fielda20;
 unsigned fielda24;
 unsigned fielda28;
 unsigned fielda2c;
 unsigned fielda30;
 unsigned fielda34;
 unsigned fielda38;
 unsigned fielda3c;
 unsigned fielda40;
 unsigned fielda44;
 unsigned fielda48;
 unsigned fielda4c;
 unsigned fielda50;
 unsigned fielda54;
 unsigned fielda58;
 unsigned fielda5c;
 unsigned fielda60;
 unsigned fielda64;
 unsigned fielda68;
 unsigned fielda6c;
 unsigned fielda70;
 unsigned fielda74;
 unsigned fielda78;
 unsigned fielda7c;
 unsigned fielda80;
 unsigned fielda84;
 unsigned fielda88;
 unsigned fielda8c;
 unsigned fielda90;
 unsigned fielda94;
 unsigned fielda98;
 unsigned fielda9c;
 unsigned fieldaa0;
 unsigned fieldaa4;
 unsigned fieldaa8;
 unsigned fieldaac;
 unsigned fieldab0;
 unsigned fieldab4;
 unsigned fieldab8;
 unsigned fieldabc;
 unsigned fieldac0;
 unsigned fieldac4;
 unsigned fieldac8;
 unsigned fieldacc;
 bool tall;
 bool NiDX9Renderer_InitializePresentParams(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,InitPresent*);
 bool NiDX9Renderer_InitializeDeviceCaps(InitPresent*);
 bool InitializeRendererResources();
 void AssignRefObject(InitObject*);
 bool NiXenonRenderer_Create(unsigned width,unsigned height,unsigned options,unsigned deviceWindow,unsigned focusWindow,unsigned adapterIndex,unsigned deviceChoice,unsigned p8,unsigned p9,unsigned p10,unsigned p11,unsigned p12,unsigned p13,unsigned p14);
};
// @fnv 0x00e72e60
// src: XBOX_PDB 0x00e72e60
bool InitRenderer::NiXenonRenderer_Create(unsigned width,unsigned height,unsigned options,unsigned deviceWindow,unsigned focusWindow,unsigned adapterIndex,unsigned deviceChoice,unsigned p8,unsigned p9,unsigned p10,unsigned p11,unsigned p12,unsigned aiBackBufferCountOut,unsigned p14)
{
 fielda98=width; fielda9c=height; fieldaa0=options; fieldaa4=deviceWindow; fieldaa8=focusWindow; fieldaac=adapterIndex;
 fieldab0=deviceChoice; fieldab4=p8; fieldab8=p9; fieldabc=p10; fieldac0=p11; fieldac4=p12; fieldac8=aiBackBufferCountOut; fieldacc=p14;
 DAT_0126efd4=0.0f; DAT_0126efd1=0;
 NiDX9SystemDesc_Get();
 field5c4=adapterIndex; field3bc=deviceWindow; field3c0=focusWindow;
 if (!SetModeFlags(deviceChoice,&field5c8,&field5cc)) {
  fnv_CopyFilePath(DAT_011f4648,256,DAT_010ee20c,255); Object_DoNothing(DAT_010ee1c8); return false;
 }
 if(options&0x40) field5cc|=2;
 if(options&0x20) field5cc|=4;
 adapter=DAT_0126f0e8->GetAt(field5c4);
 if(!adapter) { fnv_CopyFilePath(DAT_011f4648,256,DAT_010ee1a0,255); Object_DoNothing(DAT_010ee160); return false; }
 buffer=adapter->GetBuffer(field5c8);
 if(!buffer) { fnv_CopyFilePath(DAT_011f4648,256,DAT_010ee20c,255); Object_DoNothing(DAT_010ee1c8); return false; }
 InitPresent present;
 void* color;
 void* depth;
 FUN_00ec61c0(&present,0,sizeof(present));
 while(true) {
  Object_DoNothing(DAT_010ee118);
  InitBuffer* pBuffer=DAT_0126f0e8->GetAt(field5c4)->GetBuffer2(field5c8);
  if(!pBuffer) {
   fnv_CopyFilePath(DAT_011f4648,256,DAT_010ee0e8,255); Object_DoNothing(DAT_010ee0ac);
  } else if(NiDX9Renderer_InitializePresentParams(field3bc,width,height,options,p12,p8,p9,aiBackBufferCountOut,p11,p14,p10,&present)) {
   aiBackBufferCountOut=present.backBufferCount;
   InitDisplay displayMode;
   memset(&displayMode,0,sizeof(displayMode));
   displayMode.size=24; displayMode.height=height; displayMode.width=width; displayMode.refreshRate=p14; displayMode.scanLineOrdering=1; displayMode.format=present.format;
   int result;
   if(DAT_0126f0d0) {
    InitDevice* pCreatedDevice;
    result=((InitD3D*)DAT_0126f0d8)->table->CreateDeviceEx(DAT_0126f0d8,field5c4,field5c8,field3c0,field5cc,&present,present.windowed ? 0 : &displayMode,&pCreatedDevice);
    device=pCreatedDevice;
   } else {
    result=((InitD3D*)DAT_0126f0d8)->table->CreateDevice(DAT_0126f0d8,field5c4,field5c8,field3c0,field5cc,&present,&device);
   }
   tall=(float(present.height)/float(present.width)>=0.75) ? false : true;
   if(result>=0) break;
   flag6fc=0;
   if(aiBackBufferCountOut!=present.backBufferCount) {
    Object_DoNothing(DAT_010ee048);
    if(DAT_0126f0d0) {
     InitDevice* pCreatedDevice;
     result=((InitD3D*)DAT_0126f0d8)->table->CreateDeviceEx(DAT_0126f0d8,field5c4,field5c8,field3c0,field5cc,&present,present.windowed ? 0 : &displayMode,&pCreatedDevice);
     device=pCreatedDevice;
    } else {
     result=((InitD3D*)DAT_0126f0d8)->table->CreateDevice(DAT_0126f0d8,field5c4,field5c8,field3c0,field5cc,&present,&device);
    }
    if(result>=0) break;
   }
  }
  if(deviceChoice==4) { NiDX9Renderer_SetLastErrorString(DAT_010ededc); Object_DoNothing(DAT_010ede88); return false; }
  ++deviceChoice;
  if(deviceChoice==4) { Object_DoNothing(DAT_010ede30); return false; }
  Object_DoNothing(DAT_010edfe0);
  if(!SetModeFlags(deviceChoice,&field5c8,&field5cc)) { NiDX9Renderer_SetLastErrorString(DAT_010ee20c); Object_DoNothing(DAT_010ee1c8); return false; }
 }
 {
 if(!device) { NiDX9Renderer_SetLastErrorString(DAT_010edfac); Object_DoNothing(DAT_010edf60); return false; }
 if(!NiDX9Renderer_InitializeDeviceCaps(&present)) return false;
 flag5d4=(field5cc&0x40)==0;
 flag5d5=(field5cc&0x80)!=0;
 color=0; depth=0;
 InitCaps* caps=FUN_00e7d6b0(device,&present,&color);
 if(present.enableAutoDepthStencil) FUN_00e7d850(device,&depth);
 state=CreateShaderLevel(1,this);
 state->SetColor(color,0);
 state->SetDepth(depth);
 stateMap.SetMapEntryWithReferenceCounting(deviceWindow,InitSmartState(state));
 field5d0=GetValueForIndex(MapCodeToIndex(state->GetFormat(0)->format));
 if(!InitializeRendererResources()) { Object_DoNothing(DAT_010edf10); return false; }
 vertices=CreateRenderer(this,&field28c,1);
 FUN_00e81940(this);
 InitTextureManager* textureMem=(InitTextureManager*)Object_DispatchCommandFour(0x100);
 textures=textureMem ? textureMem->FUN_00e8d0e0(device) : 0;
 InitLightManager* lightMem=(InitLightManager*)Object_DispatchCommandFour(0x4c);
 lights=lightMem ? lightMem->FUN_00e8fb20(device) : 0;
 InitGeometryManager* geomMem=(InitGeometryManager*)Object_DispatchCommandFour(0x10);
 geometry=geomMem ? geomMem->NiDX9TextureManager_NiDX9TextureManager(this) : 0;
 buffers=FUN_00e88eb0(device,textures);
 buffers->FUN_00e88c20((GetFlags()&2)!=0);
 field8b0=buffers->GetBuffer(1);
 field8b4=buffers->GetBuffer(2);
 InitShaderManager* shaderMem=(InitShaderManager*)Object_DispatchCommandFour(0x23c);
 shaders=shaderMem ? shaderMem->NiDX9LightManager_NiDX9LightManager(vertices,device) : 0;
 if(caps->field30) ((InitVertexTable*)vertices->table)->Enable(vertices,1);
 currentState=state;
 NiFrustum frustum;
    frustum.Init(false);
 frustum.left=frustum.bottom=-1.0f;
 frustum.right=frustum.top=1.0f;
 frustum.nearPlane=0.1f;
 frustum.farPlane=1.0f;
 InitViewport viewport;
 viewport.bottom=viewport.left=0.0f;
 viewport.top=viewport.right=1.0f;
 SetCamera(&DAT_011f426c,&DAT_011a946c,&DAT_011a9478,&DAT_011a9484,&frustum,&viewport);
 currentState=0; activeState=0;
 NiShaderFactory::GetInstance();
 InitObject* objectMem=(InitObject*)Object_DispatchCommandFour(0x40);
 InitObject* object=objectMem ? objectMem->NiDX9ErrorShader_NiDX9ErrorShader() : 0;
 object->Initialize();
 AssignRefObject(object);
 return true;
 }
}

typedef void (__cdecl *Callback)();
void __cdecl cb_e76c30();
void __cdecl cb_e76e30();
void __cdecl cb_e77010();
void __cdecl cb_e771f0();
void __cdecl cb_e773b0();
void __cdecl cb_e77590();
void __cdecl cb_e77770();
void __cdecl cb_e77950();
void __cdecl cb_e77b50();
void __cdecl cb_e77d00();
void __cdecl cb_e77eb0();
void __cdecl cb_e78060();
void __cdecl cb_e78210();
void __cdecl cb_e783b0();
void __cdecl cb_e78880();
void __cdecl cb_e78880_other();
void __cdecl cb_e78910();
void __cdecl cb_e78a70();
void __cdecl cb_e78d50();
void __cdecl cb_e78e30();
void __cdecl cb_e78f80();
void __cdecl cb_e79160();
void __cdecl cb_e79370();
void __cdecl cb_e79540();
void __cdecl cb_e79760();
void __cdecl cb_e79920();
void __cdecl cb_e79b40();
void __cdecl cb_e79d00();
void __cdecl cb_e79f40();
void __cdecl cb_e7a0a0();
void __cdecl cb_e7cd40();
struct CallbackArray { void* vtable; int* data; unsigned short capacity,size,used,grow; __declspec(noinline) void SetAt(unsigned int, int&); };
void CallbackArray::SetAt(unsigned int index,int& value) {
 if(index>=size) {size=(unsigned short)(index+1);if(value!=0)++used;}
 else if(value!=0) {if(data[index]==0)++used;}
 else if(data[index]!=0)--used;
 data[index]=value;
}
struct CallbackBucket { int key; CallbackArray callbacks; };
struct CallbackRegistry { int unk00; CallbackBucket** buckets; };
extern void* DAT_0126f550;
// Selects a callback by type and mode, then stores it in the CallbackRegistry bucket for that type.
// @fnv 0x00e78560
// src: COMMUNITY 0x00e78560
void __cdecl NiD3DShaderDeclaration_SetDefaultPackingFunction(unsigned int type, unsigned int mode) {
 CallbackBucket* bucket = static_cast<CallbackRegistry*>(DAT_0126f550)->buckets[type];
 int callback = 0;
 if (!mode) { callback=reinterpret_cast<int>(cb_e7cd40); bucket->callbacks.SetAt(0,callback); return; }
 if(type<=3) {
 switch(mode) {
 case 1: case 2: case 3: case 4: if(mode-1==type) callback=reinterpret_cast<int>(cb_e78f80); else if(mode-1<type) goto sameFormat; else callback=reinterpret_cast<int>(cb_e78d50); break;
 case 5: case 6: case 7: case 8: callback=reinterpret_cast<int>(cb_e79160); break;
 case 9: case 10: case 11: case 12: callback=reinterpret_cast<int>(cb_e79370); break;
 case 13: case 14: case 15: case 16: callback=reinterpret_cast<int>(cb_e79540); break;
 case 17: case 18: case 19: case 20: callback=reinterpret_cast<int>(cb_e79760); break;
 case 21: case 22: case 23: case 24: callback=reinterpret_cast<int>(cb_e79920); break;
 case 25: case 26: case 27: case 28: callback=reinterpret_cast<int>(cb_e79b40); break;
 case 29: case 30: case 31: case 32: sameFormat: callback=reinterpret_cast<int>(cb_e78e30); break;
 default: break;
 }
 if(callback) bucket->callbacks.SetAt(mode,callback);
 } else if(type==4) {
 switch(mode) {
 case 1: case 2: case 6: case 7: case 8: case 10: case 11: case 12: case 13: case 14: case 15: case 17: case 18: case 19: callback=reinterpret_cast<int>(cb_e7cd40); break;
 case 3: case 4: goto packedFormat;
 case 5: callback=reinterpret_cast<int>(cb_e78880); break;
 case 9: callback=reinterpret_cast<int>(cb_e78880_other); break;
 case 16: callback=reinterpret_cast<int>(cb_e78910); break;
 case 20: callback=reinterpret_cast<int>(cb_e78a70); break;
 case 21: case 22: case 23: case 24: callback=reinterpret_cast<int>(cb_e79f40); break;
 case 25: case 26: case 27: case 28: callback=reinterpret_cast<int>(cb_e7a0a0); break;
 case 29: case 30: case 31: case 32: packedFormat: callback=reinterpret_cast<int>(cb_e79d00); break;
 default: break;
 }
 if(callback) bucket->callbacks.SetAt(mode,callback);
 } else if(type!=6 && type!=7) {
 if(type!=5) return;
 switch(mode) {
 case 1: case 2: case 3: case 4: callback=reinterpret_cast<int>(cb_e77950); break;
 case 5: case 6: case 7: case 8: callback=reinterpret_cast<int>(cb_e77b50); break;
 case 9: case 10: case 11: case 12: callback=reinterpret_cast<int>(cb_e77d00); break;
 case 13: case 14: case 15: case 16: callback=reinterpret_cast<int>(cb_e77eb0); break;
 case 17: case 18: case 19: case 20: callback=reinterpret_cast<int>(cb_e78060); break;
 case 21: case 22: case 23: case 24: callback=reinterpret_cast<int>(cb_e78210); break;
 case 25: case 26: case 27: case 28: callback=reinterpret_cast<int>(cb_e783b0); break;
 case 29: case 30: case 31: case 32: callback=reinterpret_cast<int>(cb_e7cd40); break;
 default: break;
 }
 if(callback) bucket->callbacks.SetAt(mode,callback);
 } else {
 switch(mode) {
 case 1: case 2: case 3: case 4: callback=reinterpret_cast<int>(cb_e76c30); break;
 case 5: case 6: case 7: case 8: callback=reinterpret_cast<int>(cb_e76e30); break;
 case 9: case 10: case 11: case 12: callback=reinterpret_cast<int>(cb_e77010); break;
 case 13: case 14: case 15: case 16: callback=reinterpret_cast<int>(cb_e771f0); break;
 case 17: case 18: case 19: case 20: callback=reinterpret_cast<int>(cb_e773b0); break;
 case 21: case 22: case 23: case 24: callback=reinterpret_cast<int>(cb_e77590); break;
 case 25: case 26: case 27: case 28: callback=reinterpret_cast<int>(cb_e77770); break;
 case 29: case 30: case 31: case 32: callback=reinterpret_cast<int>(cb_e7cd40); break;
 default: break;
 }
 if(callback) bucket->callbacks.SetAt(mode,callback);
 }
 
}

struct StreamE788 {
    int unk00;
    int unk04;
    unsigned short m_usElementCount;
    unsigned short unk0A;
    unsigned short* m_pusIndices;
    char* m_pcSrc;
    int unk14;
    int m_iSrcStride;
    int m_uiLogicalSize;
    int m_iDstStride;
    int unk24;
    int unk28;
    char* m_pcDst;
};
// Copies one 32-bit value per element, using optional indices or writing -1 when the source is null; returns an accumulated count.
// @fnv 0x00e78880
// src: COMMUNITY 0x00e78880
int __cdecl NiD3DShaderDeclaration_Pack_UnsignedLongToUByteColor(StreamE788* pkStream)
{
    char* pcDst = pkStream->m_pcDst;
    unsigned short* pusIndices = pkStream->m_pusIndices;
    char* pcSrc = pkStream->m_pcSrc;
    int iTotal = 0;

    if (!pcSrc) {
        for (unsigned short i = 0; i < pkStream->m_usElementCount; i++) {
            *(int*)pcDst = -1;
            pcDst += pkStream->m_iDstStride;
            iTotal += pkStream->m_uiLogicalSize;
        }
        return iTotal;
    }
    unsigned short j;
    if (pusIndices) {
        j=0;
        for (; j < pkStream->m_usElementCount; ++j) {

            int* color = (int*)(pcSrc + pusIndices[j] * pkStream->m_iSrcStride);
            for (int k=0;k<1;k++) ((int*)pcDst)[k] = color[k];
            pcDst += pkStream->m_iDstStride;
            iTotal += pkStream->m_uiLogicalSize;
        }
    } else {
        for (unsigned short i = 0; i < pkStream->m_usElementCount; i++) {
            for (int k=0;k<1;k++) ((int*)pcDst)[k] = ((int*)pcSrc)[k];
            pcSrc += pkStream->m_iSrcStride;
            pcDst += pkStream->m_iDstStride;
            iTotal += pkStream->m_uiLogicalSize;
        }
    }
    return iTotal;
}

struct CopyFill { int value; };
void* __cdecl FUN_00ec61c0(void* destination, int value, unsigned int count);
void* __cdecl FUN_00ec44d0(void* destination, const void* source, unsigned int count);

struct CopyStreamData {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short* unk0C;
    char* unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    char* unk2C;
};

// @fnv 0x00e78d50
// src: COMMUNITY 0x00e78d50
int __cdecl NiD3DShaderDeclaration_Pack_Float_DropIns(CopyStreamData* apStreamData) {
    CopyFill zero = {};
    int total=zero.value;
    char* destination = apStreamData->unk2C;
    char* source = apStreamData->unk10;
    unsigned short* indices = apStreamData->unk0C;

    if (source == (char*)zero.value) {
        for (unsigned short index = 0; index < apStreamData->unk08; ++index) {
            FUN_00ec61c0(destination, zero.value, apStreamData->unk1C);
            destination += apStreamData->unk20;
            total += apStreamData->unk1C;
        }
        return total;
    } else if (indices != (unsigned short*)zero.value) {
        if (0 < apStreamData->unk08) {
            unsigned int index=zero.value;
            do {
            char* input = source + indices[(unsigned short)index++] * apStreamData->unk18;
            FUN_00ec44d0(destination, input, apStreamData->unk1C);
            destination += apStreamData->unk20;
            total += apStreamData->unk1C;
            } while ((unsigned short)index < apStreamData->unk08);
        }
        return total;
    } else {
        if (0 < apStreamData->unk08) {
            unsigned int index=zero.value;
            do {
            FUN_00ec44d0(destination, source, apStreamData->unk1C);
            source += apStreamData->unk18;
            destination += apStreamData->unk20;
            total += apStreamData->unk1C;
            ++index;
            } while ((unsigned short)index < apStreamData->unk08);
        }
    }
    return total;
}

struct ParticlePoint {
 float x,y,z;
 ParticlePoint() {}
 ParticlePoint(float a,float b,float c):x(a),y(b),z(c) {}
 ParticlePoint& operator=(const ParticlePoint& q) { x=q.x; y=q.y; z=q.z; return *this; }
 ParticlePoint Cross(const ParticlePoint& b) const { return ParticlePoint(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x); }
 ParticlePoint operator+(const ParticlePoint& b) const { ParticlePoint result(x+b.x,y+b.y,z+b.z); return result; }
 ParticlePoint operator-(const ParticlePoint& b) const { return ParticlePoint(x-b.x,y-b.y,z-b.z); }
 ParticlePoint operator*(float b) const { return ParticlePoint(x*b,y*b,z*b); }
};
inline ParticlePoint operator*(float a,const ParticlePoint& b) { return ParticlePoint(a*b.x,a*b.y,a*b.z); }

struct ColorA {
    float r, g, b, a;
};
struct ParticleVertex {
    ParticlePoint pos;
    ParticlePoint normal;
    unsigned int color;
    float u;
    float v;
    float subTexture;
};
struct ParticleRenderer {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c; int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c; int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c; int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c; int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c; int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac; int unk2b0; int unk2b4; int unk2b8; int unk2bc;
    int unk2c0; int unk2c4; int unk2c8; int unk2cc; int unk2d0; int unk2d4; int unk2d8; int unk2dc;
    int unk2e0; int unk2e4; int unk2e8; int unk2ec; int unk2f0; int unk2f4; int unk2f8; int unk2fc;
    int unk300; int unk304; int unk308; int unk30c; int unk310; int unk314; int unk318; int unk31c;
    int unk320; int unk324; int unk328; int unk32c; int unk330; int unk334; int unk338; int unk33c;
    int unk340; int unk344; int unk348; int unk34c; int unk350; int unk354; int unk358; int unk35c;
    int unk360; int unk364; int unk368; int unk36c; int unk370; int unk374; int unk378; int unk37c;
    int unk380; int unk384; int unk388; int unk38c; int unk390; int unk394; int unk398; int unk39c;
    int unk3a0; int unk3a4; int unk3a8; int unk3ac; int unk3b0; int unk3b4; int unk3b8; int unk3bc;
    int unk3c0; int unk3c4; int unk3c8; int unk3cc; int unk3d0; int unk3d4; int unk3d8; int unk3dc;
    int unk3e0; int unk3e4; int unk3e8; int unk3ec; int unk3f0; int unk3f4; int unk3f8; int unk3fc;
    int unk400; int unk404; int unk408; int unk40c; int unk410; int unk414; int unk418; int unk41c;
    int unk420; int unk424; int unk428; int unk42c; int unk430; int unk434; int unk438; int unk43c;
    int unk440; int unk444; int unk448; int unk44c; int unk450; int unk454; int unk458; int unk45c;
    int unk460; int unk464; int unk468; int unk46c; int unk470; int unk474; int unk478; int unk47c;
    int unk480; int unk484; int unk488; int unk48c; int unk490; int unk494; int unk498; int unk49c;
    int unk4a0; int unk4a4; int unk4a8; int unk4ac; int unk4b0; int unk4b4; int unk4b8; int unk4bc;
    int unk4c0; int unk4c4; int unk4c8; int unk4cc; int unk4d0; int unk4d4; int unk4d8; int unk4dc;
    int unk4e0; int unk4e4; int unk4e8; int unk4ec; int unk4f0; int unk4f4; int unk4f8; int unk4fc;
    int unk500; int unk504; int unk508; int unk50c; int unk510; int unk514; int unk518; int unk51c;
    int unk520; int unk524; int unk528; int unk52c; int unk530; int unk534; int unk538; int unk53c;
    int unk540; int unk544; int unk548; int unk54c; int unk550; int unk554; int unk558; int unk55c;
    int unk560; int unk564; int unk568; int unk56c; int unk570; int unk574; int unk578; int unk57c;
    int unk580; int unk584; int unk588; int unk58c; int unk590; int unk594; int unk598; int unk59c;
    int unk5a0; int unk5a4; int unk5a8; int unk5ac; int unk5b0; int unk5b4; int unk5b8; int unk5bc;
    int unk5c0; int unk5c4; int unk5c8; int unk5cc; int unk5d0; int unk5d4; int unk5d8; int unk5dc;
    int unk5e0; int unk5e4; int unk5e8; int unk5ec; int unk5f0; int unk5f4; int unk5f8; int unk5fc;
    int unk600; int unk604; int unk608; int unk60c; int unk610; int unk614; int unk618; int unk61c;
    int unk620; int unk624; int unk628; int unk62c; int unk630; int unk634; int unk638; int unk63c;
    int unk640; int unk644; int unk648;
    ParticlePoint m_kU;
    ParticlePoint m_kV;
    void NiDX9Renderer_PackPoints(
        ParticleVertex* pDestVertices,
        const ParticlePoint* pPositions,
        const ColorA* pColors,
        const float* pSizes,
        const float* pScales,
        const float* pRotAngles,
        const unsigned char* pSubTextures,
        unsigned short usNumParticles
    );
};
// @fnv 0x00e6ab40
// src: COMMUNITY 0x00e6ab40
void ParticleRenderer::NiDX9Renderer_PackPoints(
    ParticleVertex* pDestVertices,
    const ParticlePoint* pPositions,
    const ColorA* pColors,
    const float* pSizes,
    const float* pScales,
    const float* pRotAngles,
    const unsigned char* pSubTextures,
    unsigned short usNumParticles
) {
    unsigned int count = usNumParticles;
    ParticlePoint normal;
    normal.x = m_kV.z * m_kU.y - m_kV.y * m_kU.z;
    const ParticlePoint& p0 = m_kU; const ParticlePoint& p1 = m_kU; const ParticlePoint& p2 = m_kU; const ParticlePoint& u = m_kU; const ParticlePoint& p4 = m_kU; const ParticlePoint& p5 = m_kU; const ParticlePoint& v = m_kV; const ParticlePoint& p7 = m_kU;
    normal.y = m_kU.z * v.x - u.x * m_kV.z;
    normal.z = m_kV.y * u.x - v.x * m_kU.y;
    if (pRotAngles != 0) {
        if (pColors != 0) {
            for (unsigned int i = 0; i < count; ++i) {
                unsigned int color = (((((unsigned int)fnv_FloatToInt(pColors->a * 255.0) << 8)
                    | fnv_FloatToInt(pColors->r * 255.0)) << 8
                    | fnv_FloatToInt(pColors->g * 255.0)) << 8)
                    | fnv_FloatToInt(pColors->b * 255.0);
                float radius = (*pSizes) * (*pScales);
                float angle = *pRotAngles;
                float s, c;
                fnv_SinCos(angle, s, c);
                float cos_plus_sin_r = (c + s) * radius;
                float cos_minus_sin_r = (c - s) * radius;
                ParticlePoint offsetA = cos_plus_sin_r * m_kU + cos_minus_sin_r * m_kV;
                ParticlePoint offsetB = -cos_minus_sin_r * m_kU + cos_plus_sin_r * m_kV;
                pDestVertices->pos = *pPositions - offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions - offsetB;
                pDestVertices->normal.x = normal.x;
                pDestVertices->normal.y = normal.y;
                pDestVertices->normal.z = normal.z;
                pDestVertices->color = color;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetA;
                pDestVertices->color = color;
                pDestVertices->normal.x = normal.x;
                pDestVertices->normal.y = normal.y;
                pDestVertices->normal.z = normal.z;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetB;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pPositions++;
                pColors++;
                pSizes++;
                pScales++;
                pRotAngles++;
                pSubTextures++;
            }
        } else {
            unsigned int color = 0xffffffff;
            for (unsigned int i = 0; i < count; ++i) {
                float radius = (*pSizes) * (*pScales);
                float angle = *pRotAngles;
                float s, c;
                fnv_SinCos(angle, s, c);
                float cos_plus_sin_r = (c + s) * radius;
                float cos_minus_sin_r = (c - s) * radius;
                ParticlePoint offsetA = cos_plus_sin_r * m_kU + cos_minus_sin_r * m_kV;
                ParticlePoint offsetB = -cos_minus_sin_r * m_kU + cos_plus_sin_r * m_kV;
                pDestVertices->pos = *pPositions - offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions - offsetB;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetB;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pPositions++;
                pSizes++;
                pScales++;
                pRotAngles++;
                pSubTextures++;
            }
        }
    } else {
        ParticlePoint v_minus_u = m_kV - m_kU;
        ParticlePoint v_plus_u = m_kV + m_kU;
        if (pColors != 0) {
            for (unsigned int i = 0; i < count; ++i) {
                unsigned int color = (((((unsigned int)fnv_FloatToInt(pColors->a * 255.0) << 8)
                    | fnv_FloatToInt(pColors->r * 255.0)) << 8
                    | fnv_FloatToInt(pColors->g * 255.0)) << 8)
                    | fnv_FloatToInt(pColors->b * 255.0);
                float radius = (*pSizes) * (*pScales);
                ParticlePoint offsetA = radius * v_plus_u;
                ParticlePoint offsetB = radius * v_minus_u;
                pDestVertices->pos = *pPositions - offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions - offsetB;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetB;
                pDestVertices->normal.x = normal.x;
                pDestVertices->color = color;
                pDestVertices->normal.y = normal.y;
                pDestVertices->normal.z = normal.z;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pPositions++;
                pColors++;
                pSizes++;
                pScales++;
                pSubTextures++;
            }
        } else {
            unsigned int color = 0xffffffff;
            for (unsigned int i = 0; i < count; ++i) {
                float radius = (*pSizes) * (*pScales);
                ParticlePoint offsetA = radius * v_plus_u;
                ParticlePoint offsetB = radius * v_minus_u;
                pDestVertices->pos = *pPositions - offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions - offsetB;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 1.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetA;
                pDestVertices->color = color;
                pDestVertices->normal = normal;
                pDestVertices->u = 1.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pDestVertices->pos = *pPositions + offsetB;
                pDestVertices->color = color;
                pDestVertices->normal.x = normal.x;
                pDestVertices->normal.y = normal.y;
                pDestVertices->normal.z = normal.z;
                pDestVertices->u = 0.0f;
                pDestVertices->v = 0.0f;
                pDestVertices->subTexture = (float)*pSubTextures;
                ++pDestVertices;
                pPositions++;
                pSizes++;
                pScales++;
                pSubTextures++;
            }
        }
    }
}

static __forceinline float StoreMiddle(float& out,float factor,const float& value) {out=factor*value;return out;}
struct S00e69ea0_Pt {
 float x,y,z;
 S00e69ea0_Pt() {}
 S00e69ea0_Pt(float a,float b,float c):x(a),y(b),z(c) {}
 S00e69ea0_Pt& operator=(const S00e69ea0_Pt& p) { x=p.x;y=p.y;z=p.z;return *this; }
 S00e69ea0_Pt operator+(const S00e69ea0_Pt& p) const { S00e69ea0_Pt r;r.x=x+p.x;r.y=y+p.y;r.z=z+p.z;return r; }
 S00e69ea0_Pt operator-(const S00e69ea0_Pt& p) const { return S00e69ea0_Pt(x-p.x,y-p.y,z-p.z); }
 S00e69ea0_Pt operator*(float f) const { return S00e69ea0_Pt(f*x,f*y,f*z); }
 S00e69ea0_Pt ScalePrecise(float f) const {const double& g=f;return S00e69ea0_Pt(g*x,f*y,f*z);}
S00e69ea0_Pt ScaleColored(float f) const {S00e69ea0_Pt r;r.x=f*x;StoreMiddle(r.y,f,y);r.z=f*z;return r;}
 S00e69ea0_Pt Cross(const S00e69ea0_Pt& p) const { return S00e69ea0_Pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x); }
};
struct S00e69ea0_Color { float r, g, b, a; };
struct S00e69ea0_Vtx {
    S00e69ea0_Pt kPos;
    S00e69ea0_Pt kNormal;
    unsigned int uiColor;
    float fTextureCoordinateU, fV;
};
struct S00e69ea0_Rnd : StandIn_Renderer {
    const S00e69ea0_Pt& GetRight() const { return *(const S00e69ea0_Pt*)&m_kScreenRight; }
    const S00e69ea0_Pt& GetUp() const { return *(const S00e69ea0_Pt*)&m_kScreenUp; }
    void NiDX9Renderer_PackPointsSubTexture(S00e69ea0_Vtx* pkVerts, const S00e69ea0_Pt* pkCenters,
        const S00e69ea0_Color* pkColors, const float* pfWidths,
        const float* pfHeights, const float* pfAngles, unsigned short m_usPassCountLocal);
};

static __forceinline S00e69ea0_Pt AddLast(const S00e69ea0_Pt& p,const S00e69ea0_Pt& q) {return S00e69ea0_Pt(p.x+q.x,p.y+q.y,p.z+q.z);}

static __forceinline void WriteQuadVertex(S00e69ea0_Vtx* v, const S00e69ea0_Pt& p, const S00e69ea0_Pt& n, unsigned int c, const float& u, const float& w) { v->kPos=p; v->uiColor=c; v->kNormal=n; v->fTextureCoordinateU=u; v->fV=w; }
// @fnv 0x00e69ea0
// src: COMMUNITY 0x00e69ea0
void S00e69ea0_Rnd::NiDX9Renderer_PackPointsSubTexture(S00e69ea0_Vtx* pkVerts, const S00e69ea0_Pt* pkCenters,
    const S00e69ea0_Color* pkColors, const float* pfWidths,
    const float* pfHeights, const float* pfAngles, unsigned short m_usPassCountLocal)
{
    S00e69ea0_Pt kNormal = GetRight().Cross(GetUp());
    if (pfAngles) {
        if (pkColors) {
            for (unsigned int i = 0; i < m_usPassCountLocal; i++) {
                unsigned int uiColor = (fnv_FloatToInt(pkColors->a * 255.0) << 24) |
                    (fnv_FloatToInt(pkColors->r * 255.0) << 16) |
                    (fnv_FloatToInt(pkColors->g * 255.0) << 8) |
                    fnv_FloatToInt(pkColors->b * 255.0);
                float fScale = *pfWidths * *pfHeights;
                float fCos, fSin;
                fnv_SinCos(*pfAngles, fSin, fCos);
                float fA = (fSin + fCos) * fScale;
                float fB = (fCos - fSin) * fScale;
                S00e69ea0_Pt kA = GetRight().ScaleColored(fA) + GetUp().ScaleColored(fB);
                S00e69ea0_Pt kB = GetRight() * -fB + GetUp() * fA;
                pkVerts->kPos = *pkCenters - kA;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 0.0f;
                pkVerts->fV = 1.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters - kB;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 1.0f;
                pkVerts->fV = 1.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters + kA;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 1.0f;
                pkVerts->fV = 0.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters + kB;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 0.0f;
                pkVerts->fV = 0.0f;
                pkVerts++;
                pfWidths++;
                pfHeights++;
                pkCenters++;
                pkColors++;
                pfAngles++;
            }
        } else {
            for (unsigned int i = 0; i < m_usPassCountLocal; i++) {
                unsigned int uiColor = 0xffffffff;
                float fScale = *pfWidths * *pfHeights;
                float fCos, fSin;
                fnv_SinCos(*pfAngles, fSin, fCos);
                float fA = (fSin + fCos) * fScale;
                float fB = (fCos - fSin) * fScale;
                const S00e69ea0_Pt& kRight = GetRight();
                const S00e69ea0_Pt& kUp = GetUp();
                S00e69ea0_Pt kA = kRight.ScalePrecise(fA) + kUp * fB;
                S00e69ea0_Pt kB = GetRight() * -fB + GetUp() * fA;
                WriteQuadVertex(pkVerts, *pkCenters - kA, kNormal, uiColor, 0.0f, 1.0f); pkVerts++;
                WriteQuadVertex(pkVerts, *pkCenters - kB, kNormal, uiColor, 1.0f, 1.0f); pkVerts++;
                WriteQuadVertex(pkVerts, *pkCenters + kA, kNormal, uiColor, 1.0f, 0.0f); pkVerts++;
                WriteQuadVertex(pkVerts, *pkCenters + kB, kNormal, uiColor, 0.0f, 0.0f); pkVerts++;
                pkCenters++;
                pfWidths++;
                pfHeights++;
                pfAngles++;
            }
        }
    } else {
        S00e69ea0_Pt kDiff = GetUp() - GetRight();
        S00e69ea0_Pt kSum = GetUp() + GetRight();
        if (pkColors) {
            for (unsigned int i = 0; i < m_usPassCountLocal; i++) {
                unsigned int uiColor = (fnv_FloatToInt(pkColors->a * 255.0) << 24) |
                    (fnv_FloatToInt(pkColors->r * 255.0) << 16) |
                    (fnv_FloatToInt(pkColors->g * 255.0) << 8) |
                    fnv_FloatToInt(pkColors->b * 255.0);
                float fScale = *pfWidths * *pfHeights;
                S00e69ea0_Pt kA = kSum * fScale;
                S00e69ea0_Pt kB = kDiff * fScale;
                pkVerts->kPos = *pkCenters - kA;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 0.0f;
                pkVerts->fV = 1.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters - kB;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 1.0f;
                pkVerts->fV = 1.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters + kA;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 1.0f;
                pkVerts->fV = 0.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters + kB;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 0.0f;
                pkVerts->fV = 0.0f;
                pkVerts++;
                pkCenters++;
                pkColors++;
                pfWidths++;
                pfHeights++;
            }
        } else {
            for (unsigned int i = 0; i < m_usPassCountLocal; i++) {
                unsigned int uiColor = 0xffffffff;
                float fScale = *pfWidths * *pfHeights;
                S00e69ea0_Pt kA = kSum * fScale;
                S00e69ea0_Pt kB = kDiff * fScale;
                pkVerts->kPos = *pkCenters - kA;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 0.0f;
                pkVerts->fV = 1.0f;
                pkVerts++;
                pkVerts->kPos = *pkCenters - kB;
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 1.0f;
                pkVerts->fV = 1.0f;
                pkVerts++;
                pkVerts->kPos = AddLast(*pkCenters,kA);
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 1.0f;
                pkVerts->fV = 0.0f;
                pkVerts++;
                pkVerts->kPos = AddLast(*pkCenters,kB);
                pkVerts->uiColor = uiColor;
                pkVerts->kNormal = kNormal;
                pkVerts->fTextureCoordinateU = 0.0f;
                pkVerts->fV = 0.0f;
                pkVerts++;
                pkCenters++;
                pfWidths++;
                pfHeights++;
            }
        }
    }
}

struct StripTransform { float rotation[3][3]; float translation[3]; float scale; };
struct StripRGB { float r,g,b; }; struct StripColor { float r,g,b,a; };

extern bool DAT_0126f0d0;
extern const char DAT_010eddd0[];
struct StripIndexBuffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned int __stdcall Release();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual long __stdcall Lock(unsigned int, unsigned int, void**, unsigned int);
    virtual long __stdcall Unlock();
};
struct StripDevice {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual long __stdcall DrawIndexed(unsigned int,int,unsigned int,unsigned int,unsigned int,unsigned int);
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85();
    virtual void __stdcall slot86();
    virtual void __stdcall slot87();
    virtual void __stdcall slot88();
    virtual void __stdcall slot89();
    virtual void __stdcall slot90();
    virtual void __stdcall slot91();
    virtual void __stdcall slot92();
    virtual void __stdcall slot93();
    virtual void __stdcall slot94();
    virtual void __stdcall slot95();
    virtual void __stdcall slot96();
    virtual void __stdcall slot97();
    virtual void __stdcall slot98();
    virtual void __stdcall slot99();
    virtual long __stdcall SetStream(unsigned int,void*,unsigned int,unsigned int);
    virtual void __stdcall slot101();
    virtual void __stdcall slot102();
    virtual void __stdcall slot103();
    virtual long __stdcall SetIndices(StripIndexBuffer*);
};
struct StripRenderState {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void SetMode(unsigned int);
    virtual void SetTransform(const StripTransform&);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void SetFormat(unsigned int, bool);
};
struct StripShaderX {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78(void*);
    virtual void v7c(void*);
    virtual void v80(void*);
    virtual void v84(void*);
    virtual void v88(void*,bool);
    virtual void v8c();
    virtual void v90();
};
struct StripStateFlags {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int flags;
};
struct StripAlphaState {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    float alpha;
};
struct StripProperties {
    StripStateFlags* flags;
    unsigned int unk004;
    StripAlphaState* alpha;
};
struct StripStream {
    void* GetBuffer() const { return buffer; }
    unsigned int GetOffset() const { return offset; }
    unsigned int GetSize() const { return size; }
    unsigned int unk000;
    unsigned int unk004;
    void* buffer;
    unsigned int offset;
    unsigned int size;
};
struct StripRendererData {
    unsigned int GetStride(unsigned int stream) const { return stream < streamCount ? strides[stream] : 0; }
    void SetVertexCount(unsigned int count) { maxVertices = vertexCount = count; }
    void NiGeometryBufferData_SetStreamCount(unsigned int);
    void SetComPointer(unsigned int);
    unsigned int unk000;
    unsigned int flags;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int vertexCount;
    unsigned int maxVertices;
    unsigned int streamCount;
    unsigned int* strides;
    StripStream** streams;
    unsigned int indexCount;
    unsigned int indexBytes;
    StripIndexBuffer* indexBuffer;
    int baseVertex;
    unsigned int primitiveType;
    unsigned int primitiveCount;
    unsigned int maxPrimitives;
    unsigned int draws;
    unsigned int unk4C;
    unsigned int unk50;
};
struct StripGeometryData {
    unsigned short BSStripPSysData_GetPointCount(unsigned int);
    unsigned short BSStripPSysData_GetMaxPointCount();
    unsigned int unk000;
    unsigned int unk004;
    unsigned short fullCount; unsigned short unk0A;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    StripRendererData* rendererData;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned short count; unsigned short unk52;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    void* colors;
};
struct StripGeometry {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    StripColor* color;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    StripTransform world;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    StripGeometryData* data;
    unsigned int unk0BC;
    StripShaderX* shader;
};
struct StripPackManager { void ProcessCollector(void*,StripGeometryData*,void*,void*,void*,void*); };
struct StripVertexManager {
    void NiDX9VertexBufferManager_AllocateBufferSpace(StripRendererData*,bool);
    void* NiDX9VertexBufferManager_LockVB(void*,unsigned int,unsigned int,unsigned int);
    void CopyAndRelease(void*);
};
struct StripIndexManager { StripIndexBuffer* AcquireCachedResource(unsigned int,unsigned int,unsigned int,unsigned int); };
struct StripRenderer {
    void DrawExpanded(StripRendererData*, StripIndexBuffer*, unsigned int, void*, StripGeometryData*, StripStream*);
    unsigned int NiDX9Renderer_GetDecl_Particles();
    unsigned int NiDX9Renderer_GetDecl_ParticlesSubTexture();
    void NiDX9Renderer_PackParticleStrips(void*,void*,StripGeometryData*,unsigned int&,unsigned int&);
    void NiDX9Renderer_RenderLines(StripGeometry*);

    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    StripProperties* properties;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    StripDevice* device;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int unk2B4;
    unsigned int unk2B8;
    unsigned int unk2BC;
    unsigned int unk2C0;
    unsigned int unk2C4;
    unsigned int unk2C8;
    unsigned int unk2CC;
    unsigned int unk2D0;
    unsigned int unk2D4;
    unsigned int unk2D8;
    unsigned int unk2DC;
    unsigned int unk2E0;
    unsigned int unk2E4;
    unsigned int unk2E8;
    unsigned int unk2EC;
    unsigned int unk2F0;
    unsigned int unk2F4;
    unsigned int unk2F8;
    unsigned int unk2FC;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30C;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31C;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32C;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33C;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34C;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35C;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36C;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37C;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38C;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39C;
    unsigned int unk3A0;
    unsigned int unk3A4;
    unsigned int unk3A8;
    unsigned int unk3AC;
    unsigned int unk3B0;
    unsigned int unk3B4;
    unsigned int unk3B8;
    unsigned int unk3BC;
    unsigned int unk3C0;
    unsigned int unk3C4;
    unsigned int unk3C8;
    unsigned int unk3CC;
    unsigned int unk3D0;
    unsigned int unk3D4;
    unsigned int unk3D8;
    unsigned int unk3DC;
    unsigned int unk3E0;
    unsigned int unk3E4;
    unsigned int unk3E8;
    unsigned int unk3EC;
    unsigned int unk3F0;
    unsigned int unk3F4;
    unsigned int unk3F8;
    unsigned int unk3FC;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40C;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41C;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42C;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43C;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44C;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45C;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46C;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47C;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48C;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49C;
    unsigned int unk4A0;
    unsigned int unk4A4;
    unsigned int unk4A8;
    unsigned int unk4AC;
    unsigned int unk4B0;
    unsigned int unk4B4;
    unsigned int unk4B8;
    unsigned int unk4BC;
    unsigned int unk4C0;
    unsigned int unk4C4;
    unsigned int unk4C8;
    unsigned int unk4CC;
    unsigned int unk4D0;
    unsigned int unk4D4;
    unsigned int unk4D8;
    unsigned int unk4DC;
    unsigned int unk4E0;
    unsigned int unk4E4;
    unsigned int unk4E8;
    unsigned int unk4EC;
    unsigned int unk4F0;
    unsigned int unk4F4;
    unsigned int unk4F8;
    unsigned int unk4FC;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50C;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51C;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52C;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53C;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54C;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55C;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56C;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57C;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58C;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59C;
    unsigned int unk5A0;
    unsigned int unk5A4;
    unsigned int unk5A8;
    unsigned int unk5AC;
    unsigned int unk5B0;
    unsigned int unk5B4;
    unsigned int unk5B8;
    unsigned int unk5BC;
    unsigned int unk5C0;
    unsigned int unk5C4;
    unsigned int unk5C8;
    unsigned int unk5CC;
    unsigned int unk5D0;
    unsigned int unk5D4;
    unsigned int unk5D8;
    unsigned int unk5DC;
    unsigned int unk5E0;
    unsigned int unk5E4;
    unsigned int unk5E8;
    unsigned int unk5EC;
    unsigned int unk5F0;
    unsigned int unk5F4;
    unsigned int unk5F8;
    unsigned int unk5FC;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60C;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61C;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62C;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63C;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64C;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65C;
    unsigned int unk660;
    StripColor color;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67C;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68C;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69C;
    unsigned int unk6A0;
    unsigned int unk6A4;
    unsigned int unk6A8;
    unsigned int unk6AC;
    unsigned int unk6B0;
    unsigned int unk6B4;
    unsigned int unk6B8;
    unsigned int unk6BC;
    unsigned int unk6C0;
    unsigned int unk6C4;
    unsigned int unk6C8;
    unsigned int unk6CC;
    unsigned int unk6D0;
    unsigned int unk6D4;
    unsigned int unk6D8;
    unsigned int unk6DC;
    unsigned int unk6E0;
    unsigned int unk6E4;
    unsigned int unk6E8;
    unsigned int unk6EC;
    unsigned int unk6F0;
    unsigned int unk6F4;
    unsigned int unk6F8;
    bool disabled; unsigned char unk6FD; unsigned short unk6FE;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70C;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71C;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72C;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73C;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74C;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75C;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76C;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77C;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78C;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79C;
    unsigned int unk7A0;
    unsigned int unk7A4;
    unsigned int unk7A8;
    unsigned int unk7AC;
    unsigned int unk7B0;
    unsigned int unk7B4;
    unsigned int unk7B8;
    unsigned int unk7BC;
    unsigned int unk7C0;
    unsigned int unk7C4;
    unsigned int unk7C8;
    unsigned int unk7CC;
    unsigned int unk7D0;
    unsigned int unk7D4;
    unsigned int unk7D8;
    unsigned int unk7DC;
    unsigned int unk7E0;
    unsigned int unk7E4;
    unsigned int unk7E8;
    unsigned int unk7EC;
    unsigned int unk7F0;
    unsigned int unk7F4;
    unsigned int unk7F8;
    unsigned int unk7FC;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80C;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81C;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82C;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83C;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84C;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85C;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86C;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87C;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88C;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89C;
    unsigned int unk8A0;
    unsigned int unk8A4;
    unsigned int unk8A8;
    StripPackManager* packManager;
    unsigned int unk8B0;
    void* bufferState;
    StripRenderState* renderState;
    StripVertexManager* vertexManager;
    StripIndexManager* indexManager;
};
// Renders a strip geometry by computing vertex/index counts, configuring the renderer data and render state, and submitting the draw call.
// @fnv 0x00e70720
// src: COMMUNITY 0x00e70720
void StripRenderer::NiDX9Renderer_RenderLines(StripGeometry* geometry)
{
    if (disabled) return;
    if ((properties->flags->flags & 1) && properties->alpha->alpha <= 0.0f) return;
    StripGeometryData* data = geometry->data;
    StripTransform transform = geometry->world;
    StripColor* colorPtr = geometry->color;
    if (!colorPtr) colorPtr = (StripColor*)DAT_011f4288;
    StripColor savedColor = *colorPtr;
    unsigned int count = data->count;
    void* colors = data->colors;
    unsigned int numVertices = 0;
    unsigned int numIndices = 0;
    bool hasStrip = false;
    for (unsigned int i = 0; i < count; ++i) {
        unsigned short length = data->BSStripPSysData_GetPointCount(i);
        if (length >= 2) {
            numVertices += 4 * length;
            if (hasStrip) numIndices += 2;
            else hasStrip = true;
            numIndices += 4 * length + 2;
        }
    }
    StripShaderX* shader = geometry->shader;
    if (!numVertices || !shader) return;
    packManager->ProcessCollector(bufferState,data,0,0,0,0);
    StripRendererData* rd = data->rendererData;
    rd->NiGeometryBufferData_SetStreamCount(1);
    rd->maxPrimitives = rd->primitiveCount = numIndices - 2;
    rd->maxVertices = rd->vertexCount = numVertices;
    rd->unk50 = 0;
    rd->unk4C = 0;
    rd->draws = 1;
    color.a = savedColor.a; *(StripRGB*)&color = *(StripRGB*)&savedColor;
    rd->flags = 0x1c00000;
    renderState->SetMode(0);
    renderState->SetTransform(transform);
    if (colors) {
        if (rd->streamCount > 0) rd->strides[0] = 40;
        renderState->SetFormat(NiDX9Renderer_GetDecl_Particles(),false);
        rd->SetComPointer(NiDX9Renderer_GetDecl_Particles());
    } else {
        if (rd->streamCount > 0) rd->strides[0] = 36;
        renderState->SetFormat(NiDX9Renderer_GetDecl_ParticlesSubTexture(),false);
        rd->SetComPointer(NiDX9Renderer_GetDecl_ParticlesSubTexture());
    }
    rd->primitiveType = 5;
    shader->v90();
    shader->v78(properties);
    shader->v7c(properties);
    shader->v80(properties);
    shader->v84(properties);
    shader->v88(properties,true);
    vertexManager->NiDX9VertexBufferManager_AllocateBufferSpace(rd,false);
    StripStream* stream;
    if (rd->streamCount > 0) stream = rd->streams[0];
    else stream = 0;
    if (!stream->GetBuffer()) return;
    unsigned int vertexBytes = colors ? numVertices * 40 : numVertices * 36;
    void* vertices = vertexManager->NiDX9VertexBufferManager_LockVB(stream->GetBuffer(),stream->GetOffset(),vertexBytes,stream->GetSize());
    if (!vertices) return;
    StripIndexBuffer* indices = rd->indexBuffer;
    unsigned int indexBytes = numIndices * 2;
    if (!indices) {
        unsigned int uiFullCount = data->fullCount;
        unsigned int total = 0;
        bool bAnyStrip = false;
        for (unsigned int i = 0; i < uiFullCount; ++i) {
            unsigned short length = data->BSStripPSysData_GetMaxPointCount();
            if (length >= 2) {
                if (bAnyStrip) total += 2;
                else bAnyStrip = true;
                total += length * 4 + 2;
            }
        }
        unsigned int bytes = total * 2;
        indices = indexManager->AcquireCachedResource(bytes,0,101,!DAT_0126f0d0);
        rd->indexBuffer = indices;
        rd->indexCount = total;
        rd->indexBytes = bytes;
    }
    DrawExpanded(rd, indices, indexBytes, vertices, data, stream);
}

__forceinline void StripRenderer::DrawExpanded(StripRendererData* rd, StripIndexBuffer* indices, unsigned int indexBytes, void* vertices, StripGeometryData* data, StripStream* stream)
{
    unsigned int writtenVertices = 0, numIndices = 0;
    bool ready = false;
    if (indices) {
        void* indexData = 0;
        long status = indices->Lock(0,indexBytes,&indexData,0);
        if (status >= 0) {
            NiDX9Renderer_PackParticleStrips(vertices,indexData,data,writtenVertices,numIndices);
            vertexManager->CopyAndRelease(stream->GetBuffer());
            indices->Unlock();
            ready = true;
        } else {
            Object_DoNothing(DAT_010eddd0);
            indices->Unlock();
            indices->Release();
        }
    } else {
        vertexManager->CopyAndRelease(stream->GetBuffer());
        return;
    }
    if (ready && writtenVertices >= 1) {
        rd->SetVertexCount(writtenVertices);
        rd->maxPrimitives = rd->primitiveCount = numIndices - 2;
        rd->unk50 = 0;
        rd->unk4C = 0;
        rd->draws = 1;
        device->SetStream(0,stream->GetBuffer(),0,rd->GetStride(0));
        device->SetIndices(indices);
        device->DrawIndexed(rd->primitiveType,rd->baseVertex,0,rd->vertexCount,0,rd->primitiveCount);
    }
}

extern "C" void _ReadWriteBarrier();
struct LineColor { float r, g, b; };
struct LineColorA : LineColor { float a; };
struct LineTexCoord { float u, v; };
struct LineVBInfo {
    unsigned int unk00;
    unsigned int unk04;
    void* m_pkOwningStream;
    unsigned int m_uiValueBeforeCount;
    unsigned int m_uiStride;
    unsigned int m_uiSize;
};
struct LineBufferData {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* m_pkVertexDeclaration;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_uiVertexCount;
    unsigned int m_uiVertexDataSize;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    LineVBInfo** m_ppkVBInfo;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_uiBufferSize;
    void NiGeometryBufferData_SetStreamCount(unsigned int uiStreamCount);
    void FUN_00e8f010(unsigned int uiFVF);
};
struct LineGeomData {
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_usActiveVertices;
    unsigned short unk0a;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    NiPoint3* m_pkVertex;
    unsigned int unk24;
    LineColorA* m_pkColor;
    LineTexCoord* m_pkTexture;
    unsigned int unk30;
    LineBufferData* m_pkGeometryRendererData;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned char* m_pkFlags;
};
struct LineShader {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d();
    virtual void SetupGeometryShader(unsigned int);
    virtual void UpdateGeometryEffects(unsigned int);
    virtual void RenderPartitionedSkinGeometry(unsigned int);
    virtual void RenderPartitionedGeometry(unsigned int);
    virtual void RenderLineGeometry(unsigned int, bool);
    virtual void GetGeometryPassCount(unsigned int);
    virtual unsigned int IsRendererActive();
    virtual unsigned int GetRendererStatus();
};
struct LineRenderState {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26();
    virtual void SetShaderDeclaration(void*, bool);
};
struct LineDevice {
    virtual long __stdcall d00(); virtual long __stdcall d01(); virtual long __stdcall d02(); virtual long __stdcall d03();
    virtual long __stdcall d04(); virtual long __stdcall d05(); virtual long __stdcall d06(); virtual long __stdcall d07();
    virtual long __stdcall d08(); virtual long __stdcall d09(); virtual long __stdcall d0a(); virtual long __stdcall d0b();
    virtual long __stdcall d0c(); virtual long __stdcall d0d(); virtual long __stdcall d0e(); virtual long __stdcall d0f();
    virtual long __stdcall d10(); virtual long __stdcall d11(); virtual long __stdcall d12(); virtual long __stdcall d13();
    virtual long __stdcall d14(); virtual long __stdcall d15(); virtual long __stdcall d16(); virtual long __stdcall d17();
    virtual long __stdcall d18(); virtual long __stdcall d19(); virtual long __stdcall d1a(); virtual long __stdcall d1b();
    virtual long __stdcall d1c(); virtual long __stdcall d1d(); virtual long __stdcall d1e(); virtual long __stdcall d1f();
    virtual long __stdcall d20(); virtual long __stdcall d21(); virtual long __stdcall d22(); virtual long __stdcall d23();
    virtual long __stdcall d24(); virtual long __stdcall d25(); virtual long __stdcall d26(); virtual long __stdcall d27();
    virtual long __stdcall d28(); virtual long __stdcall d29(); virtual long __stdcall d2a(); virtual long __stdcall d2b();
    virtual long __stdcall d2c(); virtual long __stdcall d2d(); virtual long __stdcall d2e(); virtual long __stdcall d2f();
    virtual long __stdcall d30(); virtual long __stdcall d31(); virtual long __stdcall d32(); virtual long __stdcall d33();
    virtual long __stdcall d34(); virtual long __stdcall d35(); virtual long __stdcall d36(); virtual long __stdcall d37();
    virtual long __stdcall d38(); virtual long __stdcall d39(); virtual long __stdcall d3a(); virtual long __stdcall d3b();
    virtual long __stdcall d3c(); virtual long __stdcall d3d(); virtual long __stdcall d3e(); virtual long __stdcall d3f();
    virtual long __stdcall d40(); virtual long __stdcall d41(); virtual long __stdcall d42(); virtual long __stdcall d43();
    virtual long __stdcall d44(); virtual long __stdcall d45(); virtual long __stdcall d46(); virtual long __stdcall d47();
    virtual long __stdcall d48(); virtual long __stdcall d49(); virtual long __stdcall d4a(); virtual long __stdcall d4b();
    virtual long __stdcall d4c(); virtual long __stdcall d4d(); virtual long __stdcall d4e(); virtual long __stdcall d4f();
    virtual long __stdcall d50(); virtual long __stdcall d51();
    virtual long __stdcall DrawIndexedPrimitive(int, int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual long __stdcall d53(); virtual long __stdcall d54(); virtual long __stdcall d55(); virtual long __stdcall d56();
    virtual long __stdcall d57(); virtual long __stdcall d58(); virtual long __stdcall d59(); virtual long __stdcall d5a();
    virtual long __stdcall d5b(); virtual long __stdcall d5c(); virtual long __stdcall d5d(); virtual long __stdcall d5e();
    virtual long __stdcall d5f(); virtual long __stdcall d60(); virtual long __stdcall d61(); virtual long __stdcall d62();
    virtual long __stdcall d63();
    virtual long __stdcall SetStreamSource(unsigned int, void*, unsigned int, unsigned int);
    virtual long __stdcall d65(); virtual long __stdcall d66(); virtual long __stdcall d67();
    virtual long __stdcall SetIndices(void*);
};
struct LineGeometry {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    const LineColorA* m_pkColor;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    LineGeomData* m_pkModelData;
    unsigned int unkbc;
    LineShader* m_pShaderHandle;
};
struct LineGroupManager {
    bool CreateLineGroup(void* pkGroup, LineGeomData* pkData, void* pkSkin, bool bStatic, unsigned int uiBones, unsigned int uiBonesPerVertex);
};
struct LineIBManager {
    void* ResizeTempLineConnectivity(unsigned int uiVerts, unsigned char* pkFlags, unsigned int* puiIndexCount, unsigned int uiUnk, unsigned int uiFlag);
};
struct LineVBManager {
    void NiDX9VertexBufferManager_AllocateBufferSpace(LineBufferData* pkBuffData, unsigned int uiUnk);
    float* NiDX9VertexBufferManager_LockVB(void* pkVB, unsigned int uiElapsedMilliseconds, unsigned int uiSize, unsigned int uiStride);
    bool CopyAndRelease(void* pkVB);
};
extern const LineColorA g_kLineDefaultColor_e70be0;
extern bool DAT_0126f0d0;
struct LineRenderer {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int m_uiPassContext;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    LineDevice* m_pDirect3DDevice;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    unsigned int unk650;
    unsigned int unk654;
    unsigned int unk658;
    unsigned int unk65c;
    unsigned int unk660;
    LineColorA m_kLineColorA;
    unsigned int unk674;
    unsigned int unk678;
    unsigned int unk67c;
    unsigned int unk680;
    unsigned int unk684;
    unsigned int unk688;
    unsigned int unk68c;
    unsigned int unk690;
    unsigned int unk694;
    unsigned int unk698;
    unsigned int unk69c;
    unsigned int unk6a0;
    unsigned int unk6a4;
    unsigned int unk6a8;
    unsigned int unk6ac;
    unsigned int unk6b0;
    unsigned int unk6b4;
    unsigned int unk6b8;
    unsigned int unk6bc;
    unsigned int unk6c0;
    unsigned int unk6c4;
    unsigned int unk6c8;
    unsigned int unk6cc;
    unsigned int unk6d0;
    unsigned int unk6d4;
    unsigned int unk6d8;
    unsigned int unk6dc;
    unsigned int unk6e0;
    unsigned int unk6e4;
    unsigned int unk6e8;
    unsigned int unk6ec;
    unsigned int unk6f0;
    unsigned int unk6f4;
    unsigned int unk6f8;
    bool m_bDeviceLost;
    unsigned char unk6fd;
    unsigned char unk6fe;
    unsigned char unk6ff;
    unsigned int unk700;
    unsigned int unk704;
    unsigned int unk708;
    unsigned int unk70c;
    unsigned int unk710;
    unsigned int unk714;
    unsigned int unk718;
    unsigned int unk71c;
    unsigned int unk720;
    unsigned int unk724;
    unsigned int unk728;
    unsigned int unk72c;
    unsigned int unk730;
    unsigned int unk734;
    unsigned int unk738;
    unsigned int unk73c;
    unsigned int unk740;
    unsigned int unk744;
    unsigned int unk748;
    unsigned int unk74c;
    unsigned int unk750;
    unsigned int unk754;
    unsigned int unk758;
    unsigned int unk75c;
    unsigned int unk760;
    unsigned int unk764;
    unsigned int unk768;
    unsigned int unk76c;
    unsigned int unk770;
    unsigned int unk774;
    unsigned int unk778;
    unsigned int unk77c;
    unsigned int unk780;
    unsigned int unk784;
    unsigned int unk788;
    unsigned int unk78c;
    unsigned int unk790;
    unsigned int unk794;
    unsigned int unk798;
    unsigned int unk79c;
    unsigned int unk7a0;
    unsigned int unk7a4;
    unsigned int unk7a8;
    unsigned int unk7ac;
    unsigned int unk7b0;
    unsigned int unk7b4;
    unsigned int unk7b8;
    unsigned int unk7bc;
    unsigned int unk7c0;
    unsigned int unk7c4;
    unsigned int unk7c8;
    unsigned int unk7cc;
    unsigned int unk7d0;
    unsigned int unk7d4;
    unsigned int unk7d8;
    unsigned int unk7dc;
    unsigned int unk7e0;
    unsigned int unk7e4;
    unsigned int unk7e8;
    unsigned int unk7ec;
    unsigned int unk7f0;
    unsigned int unk7f4;
    unsigned int unk7f8;
    unsigned int unk7fc;
    unsigned int unk800;
    unsigned int unk804;
    unsigned int unk808;
    unsigned int unk80c;
    unsigned int unk810;
    unsigned int unk814;
    unsigned int unk818;
    unsigned int unk81c;
    unsigned int unk820;
    unsigned int unk824;
    unsigned int unk828;
    unsigned int unk82c;
    unsigned int unk830;
    unsigned int unk834;
    unsigned int unk838;
    unsigned int unk83c;
    unsigned int unk840;
    unsigned int unk844;
    unsigned int unk848;
    unsigned int unk84c;
    unsigned int unk850;
    unsigned int unk854;
    unsigned int unk858;
    unsigned int unk85c;
    unsigned int unk860;
    unsigned int unk864;
    unsigned int unk868;
    unsigned int unk86c;
    unsigned int unk870;
    unsigned int unk874;
    unsigned int unk878;
    unsigned int unk87c;
    unsigned int unk880;
    unsigned int unk884;
    unsigned int unk888;
    unsigned int unk88c;
    unsigned int unk890;
    unsigned int unk894;
    unsigned int unk898;
    unsigned int unk89c;
    unsigned int unk8a0;
    unsigned int unk8a4;
    unsigned int unk8a8;
    LineGroupManager* m_pGeometryGroupManager;
    unsigned int unk8b0;
    void* m_pDynamicGeometryGroup;
    LineRenderState* m_pCurrentRenderState;
    LineVBManager* m_pShaderStreamInfo;
    LineIBManager* m_pRenderTargetGroup;
    void NiDX9Renderer_RenderScreenTexture(LineGeometry* pkLines);
};
// @fnv 0x00e70be0
// src: COMMUNITY 0x00e70be0
void LineRenderer::NiDX9Renderer_RenderScreenTexture(LineGeometry* pkLines)
{
    if (m_bDeviceLost)
        return;
    LineGeomData* pkData = pkLines->m_pkModelData;
    unsigned short usVerts = pkData->m_usActiveVertices;
    if (usVerts == 0)
        return;
    const LineColorA* pkColor = pkLines->m_pkColor;
    if (!pkColor)
        pkColor = &g_kLineDefaultColor_e70be0;
    LineColorA kColor = *pkColor;
    m_pGeometryGroupManager->CreateLineGroup(m_pDynamicGeometryGroup, pkData, 0, false, 0, 0);
    m_kLineColorA.a = kColor.a;
    static_cast<LineColor&>(m_kLineColorA) = kColor;
    unsigned char* pkFlags = pkData->m_pkFlags;
    NiPoint3* pkVertex = pkData->m_pkVertex;
    LineTexCoord* pkTex = pkData->m_pkTexture;
    LineColorA* pkColors = pkData->m_pkColor;
    unsigned int uiIndexCount = 0;
    unsigned int uiVerts = usVerts;
    void* pkIB = m_pRenderTargetGroup->ResizeTempLineConnectivity(usVerts, pkFlags,
        &uiIndexCount, 0, DAT_0126f0d0 == false);
    if (!pkIB || uiIndexCount == 0)
        return;
    unsigned int uiFVF = 2;
    unsigned int uiStride = 12;
    if (pkTex)
    {
        uiFVF = 0x102;
        uiStride = 20;
    }
    if (pkColors)
    {
        uiFVF |= 0x40;
        uiStride += 4;
    }
    LineShader* pkShader = pkLines->m_pShaderHandle;
    LineBufferData* pkBuffData = pkData->m_pkGeometryRendererData;
    pkBuffData->NiGeometryBufferData_SetStreamCount(1);
    pkBuffData->m_uiVertexCount = uiVerts;
    pkBuffData->m_uiVertexDataSize = uiVerts;
    pkBuffData->FUN_00e8f010(uiFVF);
    if (pkBuffData->m_uiRegisterStreamCount > 0)
        pkBuffData->m_puiVertexStrides[0] = uiStride;
    m_pShaderStreamInfo->NiDX9VertexBufferManager_AllocateBufferSpace(pkBuffData, 0);
    LineVBInfo* pkVBInfo = (pkBuffData->m_uiRegisterStreamCount > 0) ? pkBuffData->m_ppkVBInfo[0] : 0;
    m_pCurrentRenderState->SetShaderDeclaration(pkBuffData->m_pkVertexDeclaration, false);
    if (!pkVBInfo->m_pkOwningStream)
        return;
    if (pkTex)
    {
        if (pkColors)
        {
            float* pfOut = m_pShaderStreamInfo->NiDX9VertexBufferManager_LockVB(pkVBInfo->m_pkOwningStream, pkVBInfo->m_uiValueBeforeCount,
                pkVBInfo->m_uiSize, pkVBInfo->m_uiStride);
            if (!pfOut)
                return;
            for (unsigned int i = 0; i < uiVerts; i++)
            {
                pfOut[0] = pkVertex->x;
                pfOut[1] = pkVertex->y;
                pfOut[2] = pkVertex->z;
                *(unsigned int*)(pfOut + 3) = (((fnv_FloatToInt(pkColors->a * 255.0) << 8 | fnv_FloatToInt(pkColors->r * 255.0)) << 8) | fnv_FloatToInt(pkColors->g * 255.0)) << 8 | fnv_FloatToInt(pkColors->b * 255.0);
                pfOut[4] = pkTex->u;
                pfOut[5] = pkTex->v;
                pfOut += 6;
                pkVertex++;
                pkColors++;
                pkTex++;
            }
        }
        else
        {
            float* pfOut = m_pShaderStreamInfo->NiDX9VertexBufferManager_LockVB(pkVBInfo->m_pkOwningStream, pkVBInfo->m_uiValueBeforeCount,
                pkVBInfo->m_uiSize, pkVBInfo->m_uiStride);
            if (!pfOut)
                return;
            for (unsigned int i = 0; i < uiVerts; i++)
            {
                pfOut[0] = pkVertex->x;
                pfOut[1] = pkVertex->y;
                pfOut[2] = pkVertex->z;
                pfOut[3] = pkTex->u;
                pfOut[4] = pkTex->v;
                pfOut += 5;
                pkVertex++;
                pkTex++;
            }
        }
    }
    else if (pkColors)
    {
        float* pfOut = m_pShaderStreamInfo->NiDX9VertexBufferManager_LockVB(pkVBInfo->m_pkOwningStream, pkVBInfo->m_uiValueBeforeCount,
            pkVBInfo->m_uiSize, pkVBInfo->m_uiStride);
        if (!pfOut)
            return;
        for (unsigned int i = 0; i < uiVerts; i++)
        {
            pfOut[0] = pkVertex->x;
            pfOut[1] = pkVertex->y;
            pfOut[2] = pkVertex->z;
            *(unsigned int*)(pfOut + 3) = (((fnv_FloatToInt(pkColors->a * 255.0) << 8 | fnv_FloatToInt(pkColors->r * 255.0)) << 8) | fnv_FloatToInt(pkColors->g * 255.0)) << 8 | fnv_FloatToInt(pkColors->b * 255.0);
            pfOut += 4;
            pkVertex++;
            pkColors++;
        }
    }
    else
    {
        float* pfOut = m_pShaderStreamInfo->NiDX9VertexBufferManager_LockVB(pkVBInfo->m_pkOwningStream, pkVBInfo->m_uiValueBeforeCount,
            pkVBInfo->m_uiSize, pkVBInfo->m_uiStride);
        if (!pfOut)
            return;
        for (unsigned int i = 0; i < uiVerts; i++)
        {
            pfOut[0] = pkVertex->x;
            pfOut[1] = pkVertex->y;
            pfOut[2] = pkVertex->z;
            pfOut += 3;
            pkVertex++;
        }
    }
    m_pShaderStreamInfo->CopyAndRelease(pkVBInfo->m_pkOwningStream);
    pkShader->SetupGeometryShader(m_uiPassContext);
    pkShader->UpdateGeometryEffects(m_uiPassContext);
    pkShader->RenderPartitionedSkinGeometry(m_uiPassContext);
    pkShader->RenderPartitionedGeometry(m_uiPassContext);
    pkShader->RenderLineGeometry(m_uiPassContext, true);
    unsigned int uiRemainingPasses = pkShader->IsRendererActive();
    unsigned int uiStride0 = (pkBuffData->m_uiRegisterStreamCount > 0) ? pkBuffData->m_puiVertexStrides[0] : 0;
    m_pDirect3DDevice->SetStreamSource(0, pkVBInfo->m_pkOwningStream, 0, uiStride0);
    m_pDirect3DDevice->SetIndices(pkIB);
    while (uiRemainingPasses)
    {
        m_pDirect3DDevice->DrawIndexedPrimitive(2, pkBuffData->m_uiBufferSize, 0,
            pkBuffData->m_uiVertexCount, 0, uiIndexCount >> 1);
        uiRemainingPasses = pkShader->GetRendererStatus();
    }
    pkShader->GetGeometryPassCount(m_uiPassContext);
}


struct Se745_ID3DDeviceStandin {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void pad59();
    virtual void pad60();
    virtual void pad61();
    virtual void pad62();
    virtual void pad63();
    virtual void pad64();
    virtual void pad65();
    virtual void pad66();
    virtual void pad67();
    virtual void pad68();
    virtual void pad69();
    virtual void pad70();
    virtual void pad71();
    virtual void pad72();
    virtual void pad73();
    virtual void pad74();
    virtual void pad75();
    virtual void pad76();
    virtual void pad77();
    virtual void pad78();
    virtual void pad79();
    virtual void pad80();
    virtual int __stdcall DrawPrimitive(_D3DPRIMITIVETYPE type, unsigned int startVertex, unsigned int primCount);
    virtual int __stdcall DrawIndexedPrimitive(_D3DPRIMITIVETYPE type, int baseVertex, unsigned int minVertex, unsigned int numVertices, unsigned int startIndex, unsigned int primCount);
};

struct Se745_GeomData {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_iStridedVertexCount;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int m_hasIndices;
    unsigned int m_baseVertex;
    unsigned int m_ePrimitiveType;
    unsigned int m_primCount;
    unsigned int unk44;
    unsigned int m_numStrips;
    unsigned short* m_pStripIndices;
};

struct StripPartitionCurrent {
    virtual void Destroy();
    unsigned short* bones;
    float* weights;
    unsigned short* vertexMap;
    unsigned char* bonePalette;
    unsigned short* triangles;
    unsigned short* lengths;
    unsigned short vertices;
    unsigned short triangleCount;
    unsigned short boneCount;
    unsigned short strips;
    unsigned short bonesPerVertex;
    unsigned short unk26;
    Se745_GeomData* m_geom;
};

struct Se745_SubBc {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiItemCount;
    StripPartitionCurrent* m_container;
};

struct Se745_ObjBc {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Se745_SubBc* m_sub;
};

struct Se745_SubObjB8_for_28 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned short m_40;
};

struct Se745_SubItem20 {
    unsigned int m_00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned char m_10;
    unsigned char unk11;
    unsigned short unk12;
};

struct Se745_SubObj2 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    Se745_SubObjB8_for_28* m_b8;
    unsigned int unkbc;
    unsigned int unkc0;
    Se745_SubItem20* m_c4;
    unsigned int m_c8;
    unsigned char unkcc;
    unsigned char m_cd;
};

struct Se745_SubObj1 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int m_c4;
};

struct Se745_ObjB8 {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual short Test36();
    unsigned int unk04;
    unsigned int unk08;
    unsigned short unk0c;
    unsigned short m_0e;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    Se745_GeomData* m_geom;
};

struct Se745_ObjC0 {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void Func36();
};

struct Se745_Src {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual Se745_SubObj2* Func28();
    virtual Se745_SubObj1* Func2C();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    Se745_ObjB8* m_b8;
    Se745_ObjBc* m_bc;
    Se745_ObjC0* m_c0;
};

struct Se745_StandinRenderer {
    unsigned int pad00;
    unsigned int pad04;
    unsigned int pad08;
    unsigned int pad0c;
    unsigned int pad10;
    unsigned int pad14;
    unsigned int pad18;
    unsigned int pad1c;
    unsigned int pad20;
    unsigned int pad24;
    unsigned int pad28;
    unsigned int pad2c;
    unsigned int pad30;
    unsigned int pad34;
    unsigned int pad38;
    unsigned int pad3c;
    unsigned int pad40;
    unsigned int pad44;
    unsigned int pad48;
    unsigned int pad4c;
    unsigned int pad50;
    unsigned int pad54;
    unsigned int pad58;
    unsigned int pad5c;
    unsigned int pad60;
    unsigned int pad64;
    unsigned int pad68;
    unsigned int pad6c;
    unsigned int pad70;
    unsigned int pad74;
    unsigned int pad78;
    unsigned int pad7c;
    unsigned int pad80;
    unsigned int pad84;
    unsigned int pad88;
    unsigned int pad8c;
    unsigned int pad90;
    unsigned int pad94;
    unsigned int pad98;
    unsigned int pad9c;
    unsigned int pada0;
    unsigned int pada4;
    unsigned int pada8;
    unsigned int padac;
    unsigned int padb0;
    unsigned int padb4;
    unsigned int padb8;
    unsigned int padbc;
    unsigned int padc0;
    unsigned int padc4;
    unsigned int padc8;
    unsigned int padcc;
    unsigned int padd0;
    unsigned int padd4;
    unsigned int padd8;
    unsigned int paddc;
    unsigned int pade0;
    unsigned int pade4;
    unsigned int pade8;
    unsigned int padec;
    unsigned int padf0;
    unsigned int padf4;
    unsigned int padf8;
    unsigned int padfc;
    unsigned int pad100;
    unsigned int pad104;
    unsigned int pad108;
    unsigned int pad10c;
    unsigned int pad110;
    unsigned int pad114;
    unsigned int pad118;
    unsigned int pad11c;
    unsigned int pad120;
    unsigned int pad124;
    unsigned int pad128;
    unsigned int pad12c;
    unsigned int pad130;
    unsigned int pad134;
    unsigned int pad138;
    unsigned int pad13c;
    unsigned int pad140;
    unsigned int pad144;
    unsigned int pad148;
    unsigned int pad14c;
    unsigned int pad150;
    unsigned int pad154;
    unsigned int pad158;
    unsigned int pad15c;
    unsigned int pad160;
    unsigned int pad164;
    unsigned int pad168;
    unsigned int pad16c;
    unsigned int pad170;
    unsigned int pad174;
    unsigned int pad178;
    unsigned int pad17c;
    unsigned int pad180;
    unsigned int pad184;
    unsigned int pad188;
    unsigned int pad18c;
    unsigned int pad190;
    unsigned int pad194;
    unsigned int pad198;
    unsigned int pad19c;
    unsigned int pad1a0;
    unsigned int pad1a4;
    unsigned int pad1a8;
    unsigned int pad1ac;
    unsigned int pad1b0;
    unsigned int pad1b4;
    unsigned int pad1b8;
    unsigned int pad1bc;
    unsigned int pad1c0;
    unsigned int pad1c4;
    unsigned int pad1c8;
    unsigned int pad1cc;
    unsigned int pad1d0;
    unsigned int pad1d4;
    unsigned int pad1d8;
    unsigned int pad1dc;
    unsigned int pad1e0;
    unsigned int pad1e4;
    unsigned int pad1e8;
    unsigned int pad1ec;
    unsigned int pad1f0;
    unsigned int pad1f4;
    unsigned int pad1f8;
    unsigned int pad1fc;
    unsigned int pad200;
    unsigned int pad204;
    unsigned int pad208;
    unsigned int pad20c;
    unsigned int pad210;
    unsigned int pad214;
    unsigned int pad218;
    unsigned int pad21c;
    unsigned int pad220;
    unsigned int pad224;
    unsigned int pad228;
    unsigned int pad22c;
    unsigned int pad230;
    unsigned int pad234;
    unsigned int pad238;
    unsigned int pad23c;
    unsigned int pad240;
    unsigned int pad244;
    unsigned int pad248;
    unsigned int pad24c;
    unsigned int pad250;
    unsigned int pad254;
    unsigned int pad258;
    unsigned int pad25c;
    unsigned int pad260;
    unsigned int pad264;
    unsigned int pad268;
    unsigned int pad26c;
    unsigned int pad270;
    unsigned int pad274;
    unsigned int pad278;
    unsigned int pad27c;
    unsigned int pad280;
    unsigned int pad284;
    Se745_ID3DDeviceStandin* m_pDirectInputDevice;
    unsigned int pad28c;
    unsigned int pad290;
    unsigned int pad294;
    unsigned int pad298;
    unsigned int pad29c;
    unsigned int pad2a0;
    unsigned int pad2a4;
    unsigned int pad2a8;
    unsigned int pad2ac;
    unsigned int pad2b0;
    unsigned int pad2b4;
    unsigned int pad2b8;
    unsigned int pad2bc;
    unsigned int pad2c0;
    unsigned int pad2c4;
    unsigned int pad2c8;
    unsigned int pad2cc;
    unsigned int pad2d0;
    unsigned int pad2d4;
    unsigned int pad2d8;
    unsigned int pad2dc;
    unsigned int pad2e0;
    unsigned int pad2e4;
    unsigned int pad2e8;
    unsigned int pad2ec;
    unsigned int pad2f0;
    unsigned int pad2f4;
    unsigned int pad2f8;
    unsigned int pad2fc;
    unsigned int pad300;
    unsigned int pad304;
    unsigned int pad308;
    unsigned int pad30c;
    unsigned int pad310;
    unsigned int pad314;
    unsigned int pad318;
    unsigned int pad31c;
    unsigned int pad320;
    unsigned int pad324;
    unsigned int pad328;
    unsigned int pad32c;
    unsigned int pad330;
    unsigned int pad334;
    unsigned int pad338;
    unsigned int pad33c;
    unsigned int pad340;
    unsigned int pad344;
    unsigned int pad348;
    unsigned int pad34c;
    unsigned int pad350;
    unsigned int pad354;
    unsigned int pad358;
    unsigned int pad35c;
    unsigned int pad360;
    unsigned int pad364;
    unsigned int pad368;
    unsigned int pad36c;
    unsigned int pad370;
    unsigned int pad374;
    unsigned int pad378;
    unsigned int pad37c;
    unsigned int pad380;
    unsigned int pad384;
    unsigned int pad388;
    unsigned int pad38c;
    unsigned int pad390;
    unsigned int pad394;
    unsigned int pad398;
    unsigned int pad39c;
    unsigned int pad3a0;
    unsigned int pad3a4;
    unsigned int pad3a8;
    unsigned int pad3ac;
    unsigned int pad3b0;
    unsigned int pad3b4;
    unsigned int pad3b8;
    unsigned int pad3bc;
    unsigned int pad3c0;
    unsigned int pad3c4;
    unsigned int pad3c8;
    unsigned int pad3cc;
    unsigned int pad3d0;
    unsigned int pad3d4;
    unsigned int pad3d8;
    unsigned int pad3dc;
    unsigned int pad3e0;
    unsigned int pad3e4;
    unsigned int pad3e8;
    unsigned int pad3ec;
    unsigned int pad3f0;
    unsigned int pad3f4;
    unsigned int pad3f8;
    unsigned int pad3fc;
    unsigned int pad400;
    unsigned int pad404;
    unsigned int pad408;
    unsigned int pad40c;
    unsigned int pad410;
    unsigned int pad414;
    unsigned int pad418;
    unsigned int pad41c;
    unsigned int pad420;
    unsigned int pad424;
    unsigned int pad428;
    unsigned int pad42c;
    unsigned int pad430;
    unsigned int pad434;
    unsigned int pad438;
    unsigned int pad43c;
    unsigned int pad440;
    unsigned int pad444;
    unsigned int pad448;
    unsigned int pad44c;
    unsigned int pad450;
    unsigned int pad454;
    unsigned int pad458;
    unsigned int pad45c;
    unsigned int pad460;
    unsigned int pad464;
    unsigned int pad468;
    unsigned int pad46c;
    unsigned int pad470;
    unsigned int pad474;
    unsigned int pad478;
    unsigned int pad47c;
    unsigned int pad480;
    unsigned int pad484;
    unsigned int pad488;
    unsigned int pad48c;
    unsigned int pad490;
    unsigned int pad494;
    unsigned int pad498;
    unsigned int pad49c;
    unsigned int pad4a0;
    unsigned int pad4a4;
    unsigned int pad4a8;
    unsigned int pad4ac;
    unsigned int pad4b0;
    unsigned int pad4b4;
    unsigned int pad4b8;
    unsigned int pad4bc;
    unsigned int pad4c0;
    unsigned int pad4c4;
    unsigned int pad4c8;
    unsigned int pad4cc;
    unsigned int pad4d0;
    unsigned int pad4d4;
    unsigned int pad4d8;
    unsigned int pad4dc;
    unsigned int pad4e0;
    unsigned int pad4e4;
    unsigned int pad4e8;
    unsigned int pad4ec;
    unsigned int pad4f0;
    unsigned int pad4f4;
    unsigned int pad4f8;
    unsigned int pad4fc;
    unsigned int pad500;
    unsigned int pad504;
    unsigned int pad508;
    unsigned int pad50c;
    unsigned int pad510;
    unsigned int pad514;
    unsigned int pad518;
    unsigned int pad51c;
    unsigned int pad520;
    unsigned int pad524;
    unsigned int pad528;
    unsigned int pad52c;
    unsigned int pad530;
    unsigned int pad534;
    unsigned int pad538;
    unsigned int pad53c;
    unsigned int pad540;
    unsigned int pad544;
    unsigned int pad548;
    unsigned int pad54c;
    unsigned int pad550;
    unsigned int pad554;
    unsigned int pad558;
    unsigned int pad55c;
    unsigned int pad560;
    unsigned int pad564;
    unsigned int pad568;
    unsigned int pad56c;
    unsigned int pad570;
    unsigned int pad574;
    unsigned int pad578;
    unsigned int pad57c;
    unsigned int pad580;
    unsigned int pad584;
    unsigned int pad588;
    unsigned int pad58c;
    unsigned int pad590;
    unsigned int pad594;
    unsigned int pad598;
    unsigned int pad59c;
    unsigned int pad5a0;
    unsigned int pad5a4;
    unsigned int pad5a8;
    unsigned int pad5ac;
    unsigned int pad5b0;
    unsigned int pad5b4;
    unsigned int pad5b8;
    unsigned int pad5bc;
    unsigned int pad5c0;
    unsigned int pad5c4;
    unsigned int pad5c8;
    unsigned int pad5cc;
    unsigned int pad5d0;
    unsigned int pad5d4;
    unsigned int pad5d8;
    unsigned int pad5dc;
    unsigned int pad5e0;
    unsigned int pad5e4;
    unsigned int pad5e8;
    unsigned int pad5ec;
    unsigned int pad5f0;
    unsigned int pad5f4;
    unsigned int pad5f8;
    unsigned int pad5fc;
    unsigned int pad600;
    unsigned int pad604;
    unsigned int pad608;
    unsigned int pad60c;
    unsigned int pad610;
    unsigned int pad614;
    unsigned int pad618;
    unsigned int pad61c;
    unsigned int pad620;
    unsigned int pad624;
    unsigned int pad628;
    unsigned int pad62c;
    unsigned int pad630;
    unsigned int pad634;
    unsigned int pad638;
    unsigned int pad63c;
    unsigned int pad640;
    unsigned int pad644;
    unsigned int pad648;
    unsigned int pad64c;
    unsigned int pad650;
    unsigned int pad654;
    unsigned int pad658;
    unsigned int pad65c;
    unsigned int pad660;
    unsigned int pad664;
    unsigned int pad668;
    unsigned int pad66c;
    unsigned int pad670;
    unsigned int pad674;
    unsigned int pad678;
    unsigned int pad67c;
    unsigned int pad680;
    unsigned int pad684;
    unsigned int pad688;
    unsigned int pad68c;
    unsigned int pad690;
    unsigned int pad694;
    unsigned int pad698;
    unsigned int pad69c;
    unsigned int pad6a0;
    unsigned int pad6a4;
    unsigned int pad6a8;
    unsigned int pad6ac;
    unsigned int pad6b0;
    unsigned int pad6b4;
    unsigned int pad6b8;
    unsigned int pad6bc;
    unsigned int pad6c0;
    unsigned int pad6c4;
    unsigned int pad6c8;
    unsigned int pad6cc;
    unsigned int pad6d0;
    unsigned int pad6d4;
    unsigned int pad6d8;
    unsigned int pad6dc;
    unsigned int pad6e0;
    unsigned int pad6e4;
    unsigned int pad6e8;
    unsigned int pad6ec;
    unsigned int pad6f0;
    unsigned int pad6f4;
    unsigned int pad6f8;
    unsigned char m_6fc;

    bool NiDX9Renderer_IsHardwareSkinned(Se745_Src* a1, int a2);
    void NiDX9Renderer_RenderTriShape2(Se745_Src* a1);
};

// Draws geometry strips or primitives via m_pDirectInputDevice, selecting indexed or non-indexed paths based on animation state and buffer flags.
// @fnv 0x00e745a0
// src: COMMUNITY 0x00e745a0
void Se745_StandinRenderer::NiDX9Renderer_RenderTriShape2(Se745_Src* apSrc) {
    if (this->m_6fc)
        return;

    Se745_ObjB8* pData = apSrc->m_b8;
    if (!pData->Test36())
        return;

    Se745_ObjBc* pObjectInstance = apSrc->m_bc;
    bool bHasAnimation = this->NiDX9Renderer_IsHardwareSkinned(apSrc, 0);
    Se745_GeomData* pBuffer = apSrc->m_b8->m_geom;
    apSrc->m_c0->Func36();

    if (bHasAnimation) {
        Se745_SubBc* pSub = pObjectInstance->m_sub;
        unsigned int partCount = pSub->m_uiItemCount;
        StripPartitionCurrent* pPartitions = pSub->m_container;
        _D3DPRIMITIVETYPE primType = (_D3DPRIMITIVETYPE)((pPartitions->strips != 0) + 4);
        for (unsigned int partIdx = 0; partIdx < partCount; ++partIdx) {
            StripPartitionCurrent* pPartition = &pPartitions[partIdx];
            Se745_GeomData* pPartGeom = pPartition->m_geom;
            unsigned int startIndex = 0;
            for (unsigned int stripIdx = 0; stripIdx < pPartGeom->m_numStrips; ++stripIdx) {
                unsigned int primCount;
                unsigned short* stripLengths = pPartGeom->m_pStripIndices;
                if (stripLengths) {
                    primCount = stripLengths[stripIdx] - 2;
                } else {
                    primCount = pPartGeom->m_primCount;
                    if (apSrc->Func2C()) {
                        Se745_SubObj1* pObj = apSrc->Func2C();
                        primCount = pObj->m_c4;
                    }
                }
                this->m_pDirectInputDevice->DrawIndexedPrimitive(
                    primType,
                    pPartGeom->m_baseVertex,
                    0,
                    pPartition->vertices,
                    startIndex,
                    primCount
                );
                startIndex += primCount + 2;
            }
        }
    } else {
        if (pBuffer->m_hasIndices) {
            unsigned long startIndex = 0;
            for (unsigned int stripIdx = 0; stripIdx < pBuffer->m_numStrips; ++stripIdx) {
                unsigned short* stripLengths = pBuffer->m_pStripIndices;
                unsigned int primCount = stripLengths ? stripLengths[stripIdx] - 2 : pBuffer->m_primCount;
                if (apSrc->Func28()) {
                    Se745_SubObj2* pSegment = apSrc->Func28();
                    unsigned int count = pSegment->m_cd ? 1 : pSegment->m_c8;
                    for (unsigned int j = 0; count > j; ++j) {
                        if (pSegment->m_c4[j].m_10) {
                            Se745_SubItem20* item = &pSegment->m_c4[j];
                            this->m_pDirectInputDevice->DrawIndexedPrimitive(
                                (_D3DPRIMITIVETYPE)pBuffer->m_ePrimitiveType,
                                pBuffer->m_baseVertex,
                                0,
                                pBuffer->m_iStridedVertexCount,
                                pSegment->m_cd ? 0 : item->m_00,
                                pSegment->m_cd ? pSegment->m_b8->m_40 : item->m_0c
                            );
                        }
                    }
                } else {
                    this->m_pDirectInputDevice->DrawIndexedPrimitive(
                        (_D3DPRIMITIVETYPE)pBuffer->m_ePrimitiveType,
                        pBuffer->m_baseVertex,
                        0,
                        pBuffer->m_iStridedVertexCount,
                        startIndex,
                        primCount
                    );
                }
                startIndex += primCount + 2;
            }
        } else {
            this->m_pDirectInputDevice->DrawPrimitive(
                (_D3DPRIMITIVETYPE)pBuffer->m_ePrimitiveType,
                pBuffer->m_baseVertex,
                pBuffer->m_primCount
            );
        }
    }

    pData->m_0e &= 0xf000;
}

inline void* operator new(unsigned int, void* p){return p;}
namespace RendererReset {



extern "C" void* __cdecl FUN_00ec61c0(void*,int,unsigned int);extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);



typedef InitPoint Vec;extern "C" unsigned char DAT_0126efd8[118];



struct Ref {virtual void slot0();virtual void Destroy();volatile long count;};struct Ptr {Ref* object;void Clear(){Ref* old=object;if(old){if(!InterlockedDecrement(&old->count))old->Destroy();object=0;}}};



struct State {unsigned int values[22];void Clear(){for(int j=0;j<22;++j)values[j]=0;}};



struct Matrix {float data[16];};



struct Renderer {unsigned int unk0;unsigned int unk4;unsigned int unk8;unsigned int unkc;unsigned int unk10;unsigned int unk14;unsigned int unk18;unsigned int unk1c;unsigned int unk20;unsigned int unk24;unsigned int unk28;unsigned int unk2c;unsigned int unk30;unsigned int unk34;unsigned int unk38;unsigned int unk3c;unsigned int unk40;unsigned int unk44;unsigned int unk48;unsigned int unk4c;unsigned int unk50;unsigned int unk54;unsigned int unk58;unsigned int unk5c;unsigned int unk60;unsigned int unk64;unsigned int unk68;unsigned int unk6c;unsigned int unk70;unsigned int unk74;unsigned int unk78;unsigned int unk7c;unsigned int unk80;unsigned int unk84;unsigned int unk88;unsigned int unk8c;unsigned int unk90;unsigned int unk94;unsigned int unk98;unsigned int unk9c;unsigned int unka0;unsigned int unka4;unsigned int unka8;unsigned int unkac;unsigned int unkb0;unsigned int unkb4;unsigned int unkb8;unsigned int unkbc;unsigned int unkc0;unsigned int unkc4;unsigned int unkc8;unsigned int unkcc;unsigned int unkd0;unsigned int unkd4;unsigned int unkd8;unsigned int unkdc;unsigned int unke0;unsigned int unke4;unsigned int unke8;unsigned int unkec;unsigned int unkf0;unsigned int unkf4;unsigned int unkf8;unsigned int unkfc;unsigned int unk100;unsigned int unk104;unsigned int unk108;unsigned int unk10c;unsigned int unk110;unsigned int unk114;unsigned int unk118;unsigned int unk11c;unsigned int unk120;unsigned int unk124;unsigned int unk128;unsigned int unk12c;unsigned int unk130;unsigned int unk134;unsigned int unk138;unsigned int unk13c;unsigned int unk140;unsigned int unk144;unsigned int unk148;unsigned int unk14c;unsigned int unk150;unsigned int unk154;unsigned int unk158;unsigned int unk15c;unsigned int unk160;unsigned int unk164;unsigned int unk168;unsigned int unk16c;unsigned int unk170;unsigned int unk174;unsigned int unk178;unsigned int unk17c;unsigned int unk180;unsigned int unk184;unsigned int unk188;unsigned int unk18c;unsigned int unk190;unsigned int unk194;unsigned int unk198;unsigned int unk19c;unsigned int unk1a0;unsigned int unk1a4;unsigned int unk1a8;unsigned int unk1ac;unsigned int unk1b0;unsigned int unk1b4;unsigned int unk1b8;unsigned int unk1bc;unsigned int unk1c0;unsigned int unk1c4;unsigned int unk1c8;unsigned int unk1cc;unsigned int unk1d0;unsigned int unk1d4;unsigned int unk1d8;unsigned int unk1dc;unsigned int unk1e0;unsigned int unk1e4;unsigned int unk1e8;unsigned int unk1ec;unsigned int unk1f0;unsigned int unk1f4;unsigned int unk1f8;unsigned int unk1fc;unsigned int unk200;unsigned int unk204;unsigned int unk208;unsigned int unk20c;unsigned int unk210;unsigned int unk214;unsigned int unk218;unsigned int unk21c;unsigned int unk220;unsigned int unk224;unsigned int unk228;unsigned int unk22c;unsigned int unk230;unsigned int unk234;unsigned int unk238;unsigned int unk23c;unsigned int unk240;unsigned int unk244;unsigned int unk248;unsigned int unk24c;unsigned int unk250;unsigned int unk254;unsigned int unk258;unsigned int unk25c;unsigned int unk260;unsigned int unk264;unsigned int unk268;unsigned int unk26c;unsigned int unk270;unsigned int unk274;unsigned int unk278;unsigned int unk27c;unsigned int unk280;unsigned int unk284;unsigned int unk288;unsigned int unk28c;unsigned int unk290;unsigned int unk294;unsigned int unk298;unsigned int unk29c;unsigned int unk2a0;unsigned int unk2a4;unsigned int unk2a8;unsigned int unk2ac;unsigned int unk2b0;unsigned int unk2b4;unsigned int unk2b8;unsigned int unk2bc;unsigned int unk2c0;unsigned int unk2c4;unsigned int unk2c8;unsigned int unk2cc;unsigned int unk2d0;unsigned int unk2d4;unsigned int unk2d8;unsigned int unk2dc;unsigned int unk2e0;unsigned int unk2e4;unsigned int unk2e8;unsigned int unk2ec;unsigned int unk2f0;unsigned int unk2f4;unsigned int unk2f8;unsigned int unk2fc;unsigned int unk300;unsigned int unk304;unsigned int unk308;unsigned int unk30c;unsigned int unk310;unsigned int unk314;unsigned int unk318;unsigned int unk31c;unsigned int unk320;unsigned int unk324;unsigned int unk328;unsigned int unk32c;unsigned int unk330;unsigned int unk334;unsigned int unk338;unsigned int unk33c;unsigned int unk340;unsigned int unk344;unsigned int unk348;unsigned int unk34c;unsigned int unk350;unsigned int unk354;unsigned int unk358;unsigned int unk35c;unsigned int unk360;unsigned int unk364;unsigned int unk368;unsigned int unk36c;unsigned int unk370;unsigned int unk374;unsigned int unk378;unsigned int unk37c;unsigned int unk380;unsigned int unk384;unsigned int unk388;unsigned int unk38c;unsigned int unk390;unsigned int unk394;unsigned int unk398;unsigned int unk39c;unsigned int unk3a0;unsigned int unk3a4;unsigned int unk3a8;unsigned int unk3ac;unsigned int unk3b0;unsigned int unk3b4;unsigned int unk3b8;unsigned int unk3bc;unsigned int unk3c0;bool b3c4;unsigned char unk3c5;unsigned char unk3c6;unsigned char unk3c7;unsigned int unk3c8;unsigned int unk3cc;unsigned int unk3d0;unsigned int unk3d4;unsigned int unk3d8;unsigned int unk3dc;unsigned int unk3e0;unsigned int unk3e4;unsigned int unk3e8;unsigned int unk3ec;unsigned int unk3f0;unsigned int unk3f4;unsigned int unk3f8;unsigned int unk3fc;unsigned int unk400;unsigned int unk404;unsigned int unk408;unsigned int unk40c;unsigned int unk410;unsigned int unk414;unsigned int unk418;unsigned int unk41c;unsigned int unk420;unsigned int unk424;unsigned int unk428;unsigned int unk42c;unsigned int unk430;unsigned int unk434;unsigned int unk438;unsigned int unk43c;unsigned int unk440;unsigned int unk444;unsigned int unk448;unsigned int unk44c;unsigned int unk450;unsigned int unk454;unsigned int unk458;unsigned int unk45c;unsigned int unk460;unsigned int unk464;unsigned int unk468;unsigned int unk46c;unsigned int unk470;unsigned int unk474;unsigned int unk478;unsigned int unk47c;unsigned int unk480;unsigned int unk484;unsigned int unk488;unsigned int unk48c;unsigned int unk490;unsigned int unk494;unsigned int unk498;unsigned int unk49c;unsigned int unk4a0;unsigned int unk4a4;unsigned int unk4a8;unsigned int unk4ac;unsigned int unk4b0;unsigned int unk4b4;unsigned int unk4b8;unsigned int unk4bc;unsigned int unk4c0;unsigned int unk4c4;unsigned int unk4c8;unsigned int unk4cc;unsigned int unk4d0;unsigned int unk4d4;unsigned int unk4d8;unsigned int unk4dc;unsigned int unk4e0;unsigned int unk4e4;unsigned int unk4e8;unsigned int unk4ec;unsigned int unk4f0;unsigned int unk4f4;unsigned int unk4f8;unsigned int unk4fc;unsigned int unk500;unsigned int unk504;unsigned int unk508;unsigned int unk50c;unsigned int unk510;unsigned int unk514;unsigned int unk518;unsigned int unk51c;unsigned int unk520;unsigned int unk524;unsigned int unk528;unsigned int unk52c;unsigned int unk530;unsigned int unk534;unsigned int unk538;unsigned int unk53c;unsigned int unk540;unsigned int unk544;unsigned int unk548;unsigned int unk54c;unsigned int unk550;unsigned int unk554;unsigned int unk558;unsigned int unk55c;unsigned int unk560;unsigned int unk564;unsigned int unk568;unsigned int unk56c;unsigned int unk570;unsigned int unk574;unsigned int unk578;unsigned int unk57c;unsigned int unk580;unsigned int unk584;unsigned int unk588;unsigned int unk58c;unsigned int unk590;unsigned int unk594;unsigned int unk598;unsigned int unk59c;unsigned int unk5a0;unsigned int unk5a4;unsigned int unk5a8;unsigned int unk5ac;unsigned int unk5b0;unsigned int unk5b4;unsigned int unk5b8;unsigned int unk5bc;unsigned int unk5c0;unsigned int unk5c4;unsigned int unk5c8;unsigned int unk5cc;unsigned int unk5d0;bool b5d4;bool b5d5;unsigned char unk5d6;unsigned char unk5d7;unsigned int unk5d8;unsigned int unk5dc;unsigned int unk5e0;float unk5e4;unsigned int unk5e8;unsigned int unk5ec;bool b5f0;unsigned char unk5f1;unsigned char unk5f2;unsigned char unk5f3;unsigned int unk5f4;unsigned int unk5f8;unsigned int unk5fc;unsigned int unk600;unsigned int unk604;unsigned int unk608;unsigned int unk60c;unsigned int unk610;unsigned int unk614;unsigned int unk618;unsigned int unk61c;unsigned int unk620;unsigned int unk624;unsigned int unk628;unsigned int unk62c;unsigned int unk630;Vec v634;Vec v640;Vec v64c;Vec v658;unsigned int unk664;unsigned int unk668;unsigned int unk66c;unsigned int unk670;unsigned int unk674;unsigned int unk678;unsigned int unk67c;unsigned int unk680;float unk684;float unk688;Matrix matrix;unsigned int unk6cc;unsigned int unk6d0;unsigned int unk6d4;unsigned int unk6d8;float unk6dc;float unk6e0;unsigned int unk6e4;unsigned int unk6e8;unsigned int unk6ec;unsigned int unk6f0;bool b6f4;bool b6f5;unsigned char unk6f6;unsigned char unk6f7;unsigned int unk6f8;bool b6fc;unsigned char unk6fd;unsigned char unk6fe;unsigned char unk6ff;State states[4];unsigned int counters[4];Ptr refs[4];unsigned int unk880;unsigned int unk884;unsigned int unk888;unsigned int unk88c;unsigned int unk890;unsigned int unk894;unsigned int unk898;unsigned int unk89c;unsigned int unk8a0;bool b8a4;bool b8a5;unsigned char unk8a6;unsigned char unk8a7;unsigned int unk8a8;unsigned int unk8ac;unsigned int unk8b0;unsigned int unk8b4;unsigned int unk8b8;unsigned int unk8bc;unsigned int unk8c0;unsigned int unk8c4;unsigned int unk8c8;unsigned int unk8cc;unsigned int unk8d0;unsigned int unk8d4;unsigned int unk8d8;unsigned int unk8dc;unsigned int unk8e0;unsigned int unk8e4;unsigned int unk8e8;unsigned int unk8ec;unsigned int unk8f0;unsigned int unk8f4;unsigned int unk8f8;unsigned int unk8fc;unsigned int unk900;unsigned int unk904;unsigned int unk908;unsigned int unk90c;unsigned int unk910;unsigned int unk914;unsigned int unk918;unsigned int unk91c;unsigned int unk920;unsigned int unk924;unsigned int unk928;unsigned int unk92c;unsigned int unk930;unsigned int unk934;unsigned int unk938;unsigned int unk93c;unsigned int unk940;unsigned int unk944;unsigned int unk948;float unk94c;unsigned int unk950;unsigned int unk954;unsigned int unk958;float unk95c;unsigned int unk960;unsigned int unk964;unsigned int unk968;float unk96c;unsigned int unk970;unsigned int unk974;unsigned int unk978;float unk97c;unsigned int unk980;unsigned int unk984;unsigned int unk988;unsigned int unk98c;unsigned int unk990;unsigned int unk994;unsigned int unk998;unsigned int unk99c;unsigned int unk9a0;unsigned int unk9a4;unsigned int unk9a8;unsigned int unk9ac;unsigned int unk9b0;unsigned int unk9b4;unsigned int unk9b8;unsigned int unk9bc;unsigned int unk9c0;unsigned int unk9c4;unsigned int unk9c8;unsigned int unk9cc;unsigned int unk9d0;unsigned int unk9d4;unsigned int unk9d8;unsigned int unk9dc;unsigned int unk9e0;unsigned int unk9e4;unsigned int unk9e8;unsigned int unk9ec;unsigned int unk9f0;unsigned int unk9f4;unsigned int unk9f8;unsigned int unk9fc;unsigned int unka00;unsigned int unka04;unsigned int unka08;unsigned int unka0c;unsigned int unka10;unsigned int unka14;unsigned int unka18;unsigned int unka1c;unsigned int unka20;unsigned int unka24;unsigned int unka28;unsigned int unka2c;unsigned int unka30;unsigned int unka34;unsigned int unka38;unsigned int unka3c;unsigned int unka40;unsigned int unka44;unsigned int unka48;unsigned int unka4c;unsigned int unka50;unsigned int unka54;unsigned int unka58;unsigned int unka5c;unsigned int unka60;unsigned int unka64;unsigned int unka68;unsigned int unka6c;unsigned int unka70;unsigned int unka74;unsigned int unka78;unsigned int unka7c;unsigned int unka80;unsigned int unka84;unsigned int unka88;unsigned short wA8c;unsigned short unkA8e;unsigned int unka90;unsigned int unka94;unsigned int unka98;unsigned int unka9c;unsigned int unkaa0;unsigned int unkaa4;unsigned int unkaa8;unsigned int unkaac;unsigned int unkab0;unsigned int unkab4;unsigned int unkab8;unsigned int unkabc;unsigned int unkac0;unsigned int unkac4;unsigned int unkac8;unsigned int unkacc;unsigned int unkad0;__forceinline void ResetColors(){unk5c4=0;unk3c0=0;unk5cc=0;unk5d0=0;b5d4=false;b5d5=false;unk6e4=0;unk6e8=0;unk6ec=0;unk6f0=0;b6f4=false;b6f5=false;unk8a0=0;b8a4=false;b8a5=false;unk6f8=0;b6fc=false;unk5e0=0xff808080;unk5e8=0;unk5ec=0;b5f0=false;unk5c8=1;



v634=DAT_011a946c;v640=DAT_011a9478;v64c=DAT_011a946c;v658=DAT_011a9478;unk684=0.1f;}
void NiXenonRenderer_InitToDefault();};



// Resets selected renderer fields, clears four state, counter, and ref entries, sets the matrix to identity, and writes values to DAT_0126efd8.
// @fnv 0x00e6b990
// src: XBOX_PDB 0x00e6b990
void Renderer::NiXenonRenderer_InitToDefault(){unk288=0;FUN_00ec61c0(&unk28c,0,0x130);



unk5e4=1.0f;unk3bc=0;b3c4=false;ResetColors();unk688=100.0f;FUN_00ec61c0(&matrix,0,64);matrix.data[0]=matrix.data[5]=matrix.data[10]=matrix.data[15]=1.0f;unk620=0;unk624=0;memset(&unk6cc,0,24);unk6cc=0;unk6d0=0;unk6d4=1;unk6d8=1;unk6dc=0.0f;unk6e0=1.0f;



for(unsigned int i=0;i<4;++i){states[i].Clear();counters[i]=0;refs[i].Clear();}



unk96c=unk95c=unk94c=0.0f;unk97c=1.0f;unk880=22;unk888=0;unk88c=0;unk8bc=0;unk8c0=0;unk8c4=0;unk8b8=0;unk8c8=0;unk8ac=0;unk8b0=0;unk8b4=0;unka80=0;unka84=0;unka88=0;unka90=0;wA8c=0;unka94=0;unk280=0;unk284=0;FUN_00ec61c0(DAT_0126efd8,0,118);



DAT_0126efd8[20]=24;



DAT_0126efd8[21]=32;



DAT_0126efd8[22]=32;



DAT_0126efd8[23]=16;



DAT_0126efd8[24]=16;



DAT_0126efd8[25]=16;



DAT_0126efd8[26]=16;



DAT_0126efd8[27]=8;



DAT_0126efd8[28]=8;



DAT_0126efd8[29]=16;



DAT_0126efd8[30]=16;



DAT_0126efd8[31]=32;



DAT_0126efd8[32]=32;



DAT_0126efd8[33]=32;



DAT_0126efd8[34]=32;



DAT_0126efd8[35]=32;



DAT_0126efd8[36]=64;



DAT_0126efd8[40]=16;



DAT_0126efd8[41]=8;



DAT_0126efd8[50]=8;



DAT_0126efd8[51]=16;



DAT_0126efd8[52]=8;



DAT_0126efd8[60]=16;



DAT_0126efd8[61]=16;



DAT_0126efd8[62]=32;



DAT_0126efd8[63]=32;



DAT_0126efd8[64]=32;



DAT_0126efd8[67]=32;



DAT_0126efd8[70]=16;



DAT_0126efd8[71]=32;



DAT_0126efd8[73]=16;



DAT_0126efd8[75]=32;



DAT_0126efd8[77]=32;



DAT_0126efd8[79]=32;



DAT_0126efd8[80]=16;



DAT_0126efd8[82]=32;



DAT_0126efd8[83]=32;



DAT_0126efd8[81]=16;



DAT_0126efd8[101]=16;



DAT_0126efd8[102]=32;



DAT_0126efd8[110]=64;



DAT_0126efd8[111]=16;



DAT_0126efd8[112]=32;



DAT_0126efd8[113]=64;



DAT_0126efd8[114]=32;



DAT_0126efd8[115]=64;



DAT_0126efd8[116]=128;



DAT_0126efd8[117]=16;



}



}


extern const NiRTTI NiDX92DBufferData_ms_RTTI;

struct ScrRect { unsigned int m_fMinimumU; unsigned int m_fMaximumU; unsigned int m_fMinimumV; unsigned int m_fMaximumV; };
struct ScrD3DRect { long left; long top; long right; long bottom; };
struct ScrLockedRect { int Pitch; void* pBits; };
struct ScrSurfaceDesc { unsigned int Format; unsigned int Type; unsigned int Usage; unsigned int Pool; unsigned int MultiSampleType; unsigned int MultiSampleQuality; unsigned int Width; unsigned int Height; };

struct ScrSurface {
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetDevice(void**);
    virtual long __stdcall SetPrivateData(void*, const void*, unsigned long, unsigned long);
    virtual long __stdcall GetPrivateData(void*, void*, unsigned long*);
    virtual long __stdcall FreePrivateData(void*);
    virtual unsigned long __stdcall SetPriority(unsigned long);
    virtual unsigned long __stdcall GetPriority();
    virtual void __stdcall PreLoad();
    virtual int __stdcall GetType();
    virtual long __stdcall GetContainer(void*, void**);
    virtual long __stdcall GetDesc(ScrSurfaceDesc*);
    virtual long __stdcall LockRect(ScrLockedRect*, const ScrD3DRect*, unsigned long);
    virtual long __stdcall UnlockRect();
};

struct ScrDX92DBufferData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ScrSurface* m_pkSurface;
};

struct ScrRendererData {
    ScrDX92DBufferData* DynCast(const NiRTTI* pkRTTI);
};


struct ScrTargetGroup {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual unsigned int GetWidth(unsigned int uiIndex);
    virtual unsigned int GetHeight(unsigned int uiIndex);
    virtual void v37(); virtual void v38();
    virtual const NiPixelFormat* GetPixelFormat(unsigned int uiIndex) throw();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual ScrRendererData* GetRenderTargetBuffer(unsigned int uiIndex);
};

void* _memmove(void*, const void*, unsigned int);

struct ScrDX9Renderer {
    virtual void vf00();
    int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C; int unk020;
    int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C; int unk040;
    int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C; int unk060;
    int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C; int unk080;
    int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C; int unk0A0;
    int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC; int unk0C0;
    int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC; int unk0E0;
    int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC; int unk100;
    int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C; int unk120;
    int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C; int unk140;
    int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C; int unk160;
    int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C; int unk180;
    int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C; int unk1A0;
    int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC; int unk1C0;
    int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC; int unk1E0;
    int unk1E4; int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC; int unk200;
    int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C; int unk220;
    int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C; int unk240;
    int unk244; int unk248; int unk24C; int unk250; int unk254; int unk258; int unk25C; int unk260;
    int unk264; int unk268; int unk26C; int unk270; int unk274; int unk278; int unk27C; int unk280;
    int unk284; int unk288; int unk28C; int unk290; int unk294; int unk298; int unk29C; int unk2A0;
    int unk2A4; int unk2A8; int unk2AC; int unk2B0; int unk2B4; int unk2B8; int unk2BC; int unk2C0;
    int unk2C4; int unk2C8; int unk2CC; int unk2D0; int unk2D4; int unk2D8; int unk2DC; int unk2E0;
    int unk2E4; int unk2E8; int unk2EC; int unk2F0; int unk2F4; int unk2F8; int unk2FC; int unk300;
    int unk304; int unk308; int unk30C; int unk310; int unk314; int unk318; int unk31C; int unk320;
    int unk324; int unk328; int unk32C; int unk330; int unk334; int unk338; int unk33C; int unk340;
    int unk344; int unk348; int unk34C; int unk350; int unk354; int unk358; int unk35C; int unk360;
    int unk364; int unk368; int unk36C; int unk370; int unk374; int unk378; int unk37C; int unk380;
    int unk384; int unk388; int unk38C; int unk390; int unk394; int unk398; int unk39C; int unk3A0;
    int unk3A4; int unk3A8; int unk3AC; int unk3B0; int unk3B4; int unk3B8; int unk3BC; int unk3C0;
    int unk3C4; int unk3C8; int unk3CC; int unk3D0; int unk3D4; int unk3D8; int unk3DC; int unk3E0;
    int unk3E4; int unk3E8; int unk3EC; int unk3F0; int unk3F4; int unk3F8; int unk3FC; int unk400;
    int unk404; int unk408; int unk40C; int unk410; int unk414; int unk418; int unk41C; int unk420;
    int unk424; int unk428; int unk42C; int unk430; int unk434; int unk438; int unk43C; int unk440;
    int unk444; int unk448; int unk44C; int unk450; int unk454; int unk458; int unk45C; int unk460;
    int unk464; int unk468; int unk46C; int unk470; int unk474; int unk478; int unk47C; int unk480;
    int unk484; int unk488; int unk48C; int unk490; int unk494; int unk498; int unk49C; int unk4A0;
    int unk4A4; int unk4A8; int unk4AC; int unk4B0; int unk4B4; int unk4B8; int unk4BC; int unk4C0;
    int unk4C4; int unk4C8; int unk4CC; int unk4D0; int unk4D4; int unk4D8; int unk4DC; int unk4E0;
    int unk4E4; int unk4E8; int unk4EC; int unk4F0; int unk4F4; int unk4F8; int unk4FC; int unk500;
    int unk504; int unk508; int unk50C; int unk510; int unk514; int unk518; int unk51C; int unk520;
    int unk524; int unk528; int unk52C; int unk530; int unk534; int unk538; int unk53C; int unk540;
    int unk544; int unk548; int unk54C; int unk550; int unk554; int unk558; int unk55C; int unk560;
    int unk564; int unk568; int unk56C; int unk570; int unk574; int unk578; int unk57C; int unk580;
    int unk584; int unk588; int unk58C; int unk590; int unk594; int unk598; int unk59C; int unk5A0;
    int unk5A4; int unk5A8; int unk5AC; int unk5B0; int unk5B4; int unk5B8; int unk5BC; int unk5C0;
    int unk5C4; int unk5C8; int unk5CC; int unk5D0; int unk5D4; int unk5D8; int unk5DC; int unk5E0;
    int unk5E4; int unk5E8; int unk5EC; int unk5F0; int unk5F4; int unk5F8; int unk5FC; int unk600;
    int unk604; int unk608; int unk60C; int unk610; int unk614; int unk618; int unk61C; int unk620;
    int unk624; int unk628; int unk62C; int unk630; int unk634; int unk638; int unk63C; int unk640;
    int unk644; int unk648; int unk64C; int unk650; int unk654; int unk658; int unk65C; int unk660;
    int unk664; int unk668; int unk66C; int unk670; int unk674; int unk678; int unk67C; int unk680;
    int unk684; int unk688; int unk68C; int unk690; int unk694; int unk698; int unk69C; int unk6A0;
    int unk6A4; int unk6A8; int unk6AC; int unk6B0; int unk6B4; int unk6B8; int unk6BC; int unk6C0;
    int unk6C4; int unk6C8; int unk6CC; int unk6D0; int unk6D4; int unk6D8; int unk6DC; int unk6E0;
    int unk6E4; int unk6E8; int unk6EC; int unk6F0; int unk6F4; int unk6F8;
    bool m_bDeviceLost; char unk6FD; char unk6FE; char unk6FF;
    int unk700; int unk704; int unk708; int unk70C; int unk710; int unk714; int unk718; int unk71C;
    int unk720; int unk724; int unk728; int unk72C; int unk730; int unk734; int unk738; int unk73C;
    int unk740; int unk744; int unk748; int unk74C; int unk750; int unk754; int unk758; int unk75C;
    int unk760; int unk764; int unk768; int unk76C; int unk770; int unk774; int unk778; int unk77C;
    int unk780; int unk784; int unk788; int unk78C; int unk790; int unk794; int unk798; int unk79C;
    int unk7A0; int unk7A4; int unk7A8; int unk7AC; int unk7B0; int unk7B4; int unk7B8; int unk7BC;
    int unk7C0; int unk7C4; int unk7C8; int unk7CC; int unk7D0; int unk7D4; int unk7D8; int unk7DC;
    int unk7E0; int unk7E4; int unk7E8; int unk7EC; int unk7F0; int unk7F4; int unk7F8; int unk7FC;
    int unk800; int unk804; int unk808; int unk80C; int unk810; int unk814; int unk818; int unk81C;
    int unk820; int unk824; int unk828; int unk82C; int unk830; int unk834; int unk838; int unk83C;
    int unk840; int unk844; int unk848; int unk84C; int unk850; int unk854; int unk858; int unk85C;
    int unk860; int unk864; int unk868; int unk86C; int unk870; int unk874; int unk878; int unk87C;
    int unk880;
    ScrTargetGroup* m_pDefaultRenderTargetGroup;
    NiPixelData* NiDX9Renderer_TakeScreenShot(const ScrRect* pkScreenRect, ScrTargetGroup* pkTarget);
};

enum ScrAllocationTag { ScrAllocatePixels };
__forceinline void* operator new(unsigned int size, ScrAllocationTag) { return NiPixelData::operator new(size); }

// Locks a render target surface, copies the pixel rows into a new NiPixelData buffer, and returns it.
// @fnv 0x00e6f4e0
// src: COMMUNITY 0x00e6f4e0
NiPixelData* ScrDX9Renderer::NiDX9Renderer_TakeScreenShot(const ScrRect* pkScreenRect, ScrTargetGroup* pkTarget)
{
    if (m_bDeviceLost)
        return 0;

    if (!pkTarget)
        pkTarget = m_pDefaultRenderTargetGroup;

    ScrD3DRect* pkRect = 0;
    unsigned int uiWidth = pkTarget->GetWidth(0);
    unsigned int uiTargetHeight = pkTarget->GetHeight(0);
    unsigned int uiHeight;

    ScrD3DRect pDataToSerialize;
    if (pkScreenRect)
    {
        pDataToSerialize.left = pkScreenRect->m_fMinimumU;
        pDataToSerialize.right = pkScreenRect->m_fMaximumU;
        pDataToSerialize.top = pkScreenRect->m_fMinimumV;
        pDataToSerialize.bottom = pkScreenRect->m_fMaximumV;

        float m_fGlyphWidthInPixels = (float)uiWidth;
        if ((float)pDataToSerialize.left >= m_fGlyphWidthInPixels || (float)pDataToSerialize.bottom >= (float)uiTargetHeight)
            return 0;
        if ((float)pDataToSerialize.right > m_fGlyphWidthInPixels)
            pDataToSerialize.right = uiWidth;
        if ((float)pDataToSerialize.bottom > (float)uiTargetHeight)
            pDataToSerialize.bottom = uiTargetHeight;

        uiWidth = pDataToSerialize.right - pDataToSerialize.left;
        uiHeight = pDataToSerialize.bottom - pDataToSerialize.top;
        pkRect = &pDataToSerialize;
    }
    else
        uiHeight = uiTargetHeight;

    ScrRendererData* pkData = pkTarget->GetRenderTargetBuffer(0);
    ScrDX92DBufferData* pkDX9Data = !pkData ? 0 : pkData->DynCast(&NiDX92DBufferData_ms_RTTI);
    ScrSurface* pkSurface = pkDX9Data->m_pkSurface;

    ScrSurfaceDesc kDesc;
    pkSurface->GetDesc(&kDesc);

    ScrLockedRect kLock;
    if (pkSurface->LockRect(&kLock, pkRect, 0x10) < 0)
        return 0;

    NiPixelData* pkPixelData = ::new (ScrAllocatePixels) NiPixelData(uiWidth, uiHeight, *pkTarget->GetPixelFormat(0), 1, 1);
    if (!pkPixelData)
    {
        pkSurface->UnlockRect();
        return 0;
    }

    unsigned int uiRowBytes = pkPixelData->m_puiWidth[0] * pkPixelData->m_uiPixelStride;
    unsigned char* pucDest = pkPixelData->m_pucPixels + pkPixelData->m_puiOffsetInBytes[0];
    unsigned char* pucSrc = (unsigned char*)kLock.pBits;
    for (unsigned int i = 0; i < uiHeight; i++)
    {
        _memmove(pucDest, pucSrc, uiRowBytes);
        pucSrc += kLock.Pitch;
        pucDest += uiRowBytes;
    }

    pkSurface->UnlockRect();
    return pkPixelData;
}

extern "C" void _ReadWriteBarrier();
struct Xf {
    float m[3][3];
    NiPoint3 t;
    float scale;
    __forceinline Xf() {}
    __forceinline Xf(const Xf& other) { memcpy(this, &other, sizeof(Xf)); }
    __forceinline Xf& operator=(const Xf& other) { memcpy(this, &other, sizeof(Xf)); return *this; }
    void FUN_004b4880(Xf* out);
    Xf operator*(const Xf& rhs) const;
};
struct BoneXform {
    Xf xf;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
};
struct Skin8 { int a, b, c, d, e, f, g, h; };
struct SkinNode {
    Skin8 n0;
    Skin8 n1;
    Skin8 n2;
    int n3;
    int n4;
    Xf world;
};
struct Geom {
    int unk00;
    int unk04;
    int unk08;
    Xf world;
    BoneXform* boneData;
    unsigned int boneCount;
};
struct SkinMatrixBlock {
    int unk00;
    int unk04;
    Geom* geom;
    int unk0c;
    SkinNode* root;
    SkinNode** bones;
    const char* entry;
    unsigned int count;
    unsigned int rowsStored;
    unsigned int capacity;
    void* buffer;
};
struct ScaleSink {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61();
    virtual void v62(bool flag);
};
void* __cdecl NiAlignedAlloc(unsigned int count, unsigned int align);
void __cdecl BuildWorldToSkinTransform(NiWorldToSkin_niconsolerenderer*, const NiTransform*, const NiPoint3*, float);
void __cdecl FUN_00b71a40(NiWorldToSkin_niconsolerenderer* out, const Xf* xf, const NiPoint3* pt, float scale);
extern double DAT_0106d508;
extern float DAT_0106b9e0;

// Updates the matrix buffer from per-bone transforms and reports whether a non-unit scale was detected.
// @fnv 0x00e6fe30
// src: COMMUNITY 0x00e6fe30
void __fastcall NiDX9Renderer_CalculateBoneMatrices(NiDX9Renderer* self, void*, SkinMatrixBlock* block, Xf* parent, bool transpose, unsigned int rows, bool skipExtra) {
    const char* cur = block->entry;
    if (cur == (*(NiD3DHLSLVertexShader**)self->_undescribed_8BC)->NiD3DHLSLVertexShader::GetEntryPoint() && rows == block->rowsStored)
        return;

    block->entry = (*(NiD3DHLSLVertexShader**)self->_undescribed_8BC)->NiD3DHLSLVertexShader::GetEntryPoint();


    void* buffer;
    Geom* geometry;
    geometry = block->geom;
    unsigned int boneCount = geometry->boneCount;
    buffer = block->buffer;
    unsigned int uiCapacity = block->capacity;
    if (rows == 3)
        transpose = true;

    unsigned int need = (boneCount * rows) << 4;
    if (need > uiCapacity) {
        _NiAlignedFree(buffer);
        buffer = NiAlignedAlloc(need, 0x10);
        block->buffer = buffer;
        block->capacity = need;
    }
    block->count = boneCount;
    block->rowsStored = rows;

    if (rows == 4 && boneCount > 0) {
        float* m = (float*)buffer + 13;
        unsigned int n = boneCount;
        do {
            if (transpose) {
                m[1] = 0.0f;
                m[0] = 0.0f;
                m[-1] = 0.0f;
            } else {
                m[-2] = 0.0f;
                m[-6] = 0.0f;
                m[-10] = 0.0f;
            }
            m[2] = 1.0f;
            m += 16;
        } while (--n);
    }

    Xf t1;
    Xf t2;
    SkinNode* root = block->root;
    root->world.FUN_004b4880(&t1);
    Geom* current = block->geom;
    t1 = *new (&t2) Xf(current->world * t1);
    t2 = (*parent) * t1;

    bool bNonUnitScale;
    bNonUnitScale = false;
    if (t1.scale < DAT_0106d508) {
        if (t1.scale > 1.01f)
            bNonUnitScale = true;
    }

    SkinNode** bones = block->bones;
    BoneXform* pBoneData = geometry->boneData;
    unsigned int i = 0;
    if (boneCount > 0) {
        float* __restrict p3 = (float*)buffer;
        _ReadWriteBarrier();
        NiWorldToSkin_niconsolerenderer* p4 = (NiWorldToSkin_niconsolerenderer*)p3;
        BoneXform*  pBoneXform = pBoneData;
        
        p3 += 8;
        do {
            new (&t1) Xf(bones[i]->world * pBoneXform->xf);
            if (bones[i]->world.scale < DAT_0106d508) {
                if ((double)bones[i]->world.scale > 1.01f)
                    bNonUnitScale = true;
            }
            if (!skipExtra)
                t1 = t2 * t1;
            if (rows == 4) {
                if (transpose)
                    BuildWorldToSkinTransform(p4, (const NiTransform*)&t1, &t1.t, t1.scale);
                else
                    FUN_00b71a40(p4, &t1, &t1.t, t1.scale);
            } else {
                p3[-8] = t1.m[0][0] * t1.scale;
                p3[-4] = t1.m[1][0] * t1.scale;
                p3[0] = t1.m[2][0] * t1.scale;
                p3[-7] = t1.m[0][1] * t1.scale;
                p3[-3] = t1.m[1][1] * t1.scale;
                p3[1] = t1.m[2][1] * t1.scale;
                p3[-6] = t1.m[0][2] * t1.scale;
                p3[-2] = t1.m[1][2] * t1.scale;
                p3[2] = t1.m[2][2] * t1.scale;
                p3[-5] = t1.t.x - DAT_011f474c.x;
                p3[-1] = t1.t.y - DAT_011f4750;
                p3[3] = t1.t.z - DAT_011f4754;
            }
            ++i;
            ++pBoneXform;
            ++p4;
            p3 += 12;
        } while (i < boneCount);
    }

    ((ScaleSink*)self->pRenderState)->v62(bNonUnitScale);
}


struct SceneArg;

struct FrameInfo {
    NiMatrix3 m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

struct Material {float r,g,b,a;};

extern "C" char DAT_011f4288[16];


extern bool DAT_0126f0d0;



extern "C" void __cdecl Object_DoNothing(void*);

void __cdecl FUN_00b71a40(void*,void*,void*,float);


NiPoint3* __cdecl NiPoint3_TransformByMatrix3(NiPoint3*, const NiPoint3&, const float*);

struct Object3 {int x,y,z;};

struct GateAux {unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38; float m3c;};

struct Gate {unsigned int* flags; unsigned int unk04; GateAux* aux;};

struct IndexBuffer {

    virtual int __stdcall v000();

    virtual int __stdcall v004();

    virtual int __stdcall Release();

    virtual int __stdcall v00c();

    virtual int __stdcall v010();

    virtual int __stdcall v014();

    virtual int __stdcall v018();

    virtual int __stdcall v01c();

    virtual int __stdcall v020();

    virtual int __stdcall v024();

    virtual int __stdcall v028();

    virtual int __stdcall Lock(unsigned int,unsigned int,void**,unsigned int);

    virtual int __stdcall Unlock();



};

struct ParticleGeometry {

    virtual int v000();

    virtual int v004();

    virtual int v008();

    virtual int v00c();

    virtual int v010();

    virtual int v014();

    virtual int v018();

    virtual int v01c();

    virtual int v020();

    virtual int v024();

    virtual int v028();

    virtual int v02c();

    virtual int v030();

    virtual int v034();

    virtual int v038();

    virtual int v03c();

    virtual int v040();

    virtual int v044();

    virtual int v048();

    virtual int v04c();

    virtual int v050();

    virtual int v054();

    virtual int v058();

    virtual int v05c();

    virtual int v060();

    virtual int v064();

    virtual int v068();

    virtual int v06c();

    virtual int v070();

    virtual int v074();

    virtual int v078();

    virtual int v07c();

    virtual int v080();

    virtual int v084();

    virtual int v088();

    virtual int v08c();

    virtual unsigned short GetCount();



    unsigned int unk004;

    unsigned short countInfo; unsigned short unk00a;

    unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024;

    unsigned int m28;

    unsigned int unk02c; unsigned int unk030;

    struct VertexData* vertex;

    unsigned int unk038; unsigned int unk03c; unsigned int unk040;

    unsigned short* rawIndices;

    unsigned int unk048;

    unsigned int f4c;

    unsigned int unk050;

    unsigned int f54;

    unsigned int unk058;

    unsigned int f5c;

    unsigned int unk060;

    unsigned int f64;



};

struct Overlay {

    virtual int v000();

    virtual int v004();

    virtual int v008();

    virtual int v00c();

    virtual int v010();

    virtual int v014();

    virtual int v018();

    virtual int v01c();

    virtual int v020();

    virtual int v024();

    virtual int v028();

    virtual int v02c();

    virtual int v030();

    virtual int v034();

    virtual int v038();

    virtual int v03c();

    virtual int v040();

    virtual int v044();

    virtual int v048();

    virtual int v04c();

    virtual int v050();

    virtual int v054();

    virtual int v058();

    virtual int v05c();

    virtual int v060();

    virtual int v064();

    virtual int v068();

    virtual int v06c();

    virtual int v070();

    virtual int v074();

    virtual void BeginA(void*);

    virtual void BeginB(void*);

    virtual void BeginC(void*);

    virtual void BeginD(void*);

    virtual void BeginE(void*,int);

    virtual void Finish(void*);

    virtual void* GetCommand();

    virtual int NextCommand();



};

struct QuadDevice {

    virtual int __stdcall v000();

    virtual int __stdcall v004();

    virtual int __stdcall v008();

    virtual int __stdcall v00c();

    virtual int __stdcall v010();

    virtual int __stdcall v014();

    virtual int __stdcall v018();

    virtual int __stdcall v01c();

    virtual int __stdcall v020();

    virtual int __stdcall v024();

    virtual int __stdcall v028();

    virtual int __stdcall v02c();

    virtual int __stdcall v030();

    virtual int __stdcall v034();

    virtual int __stdcall v038();

    virtual int __stdcall v03c();

    virtual int __stdcall v040();

    virtual int __stdcall v044();

    virtual int __stdcall v048();

    virtual int __stdcall v04c();

    virtual int __stdcall v050();

    virtual int __stdcall v054();

    virtual int __stdcall v058();

    virtual int __stdcall v05c();

    virtual int __stdcall v060();

    virtual int __stdcall v064();

    virtual int __stdcall v068();

    virtual int __stdcall v06c();

    virtual int __stdcall v070();

    virtual int __stdcall v074();

    virtual int __stdcall v078();

    virtual int __stdcall v07c();

    virtual int __stdcall v080();

    virtual int __stdcall v084();

    virtual int __stdcall v088();

    virtual int __stdcall v08c();

    virtual int __stdcall v090();

    virtual int __stdcall v094();

    virtual int __stdcall v098();

    virtual int __stdcall v09c();

    virtual int __stdcall v0a0();

    virtual int __stdcall v0a4();

    virtual int __stdcall v0a8();

    virtual int __stdcall v0ac();

    virtual int __stdcall SetTransform(int,void*);

    virtual int __stdcall v0b4();

    virtual int __stdcall v0b8();

    virtual int __stdcall v0bc();

    virtual int __stdcall v0c0();

    virtual int __stdcall v0c4();

    virtual int __stdcall v0c8();

    virtual int __stdcall v0cc();

    virtual int __stdcall v0d0();

    virtual int __stdcall v0d4();

    virtual int __stdcall v0d8();

    virtual int __stdcall v0dc();

    virtual int __stdcall v0e0();

    virtual int __stdcall v0e4();

    virtual int __stdcall v0e8();

    virtual int __stdcall v0ec();

    virtual int __stdcall v0f0();

    virtual int __stdcall v0f4();

    virtual int __stdcall v0f8();

    virtual int __stdcall v0fc();

    virtual int __stdcall v100();

    virtual int __stdcall v104();

    virtual int __stdcall v108();

    virtual int __stdcall v10c();

    virtual int __stdcall v110();

    virtual int __stdcall v114();

    virtual int __stdcall v118();

    virtual int __stdcall v11c();

    virtual int __stdcall v120();

    virtual int __stdcall v124();

    virtual int __stdcall v128();

    virtual int __stdcall v12c();

    virtual int __stdcall v130();

    virtual int __stdcall v134();

    virtual int __stdcall v138();

    virtual int __stdcall v13c();

    virtual int __stdcall v140();

    virtual int __stdcall v144();

    virtual int __stdcall DrawIndexedPrimitive(int,int,int,int,int,int);

    virtual int __stdcall v14c();

    virtual int __stdcall v150();

    virtual int __stdcall v154();

    virtual int __stdcall v158();

    virtual int __stdcall v15c();

    virtual int __stdcall v160();

    virtual int __stdcall v164();

    virtual int __stdcall v168();

    virtual int __stdcall v16c();

    virtual int __stdcall v170();

    virtual int __stdcall v174();

    virtual int __stdcall v178();

    virtual int __stdcall v17c();

    virtual int __stdcall v180();

    virtual int __stdcall v184();

    virtual int __stdcall v188();

    virtual int __stdcall v18c();

    virtual int __stdcall SetStreamSource(int,void*,int,int);

    virtual int __stdcall v194();

    virtual int __stdcall v198();

    virtual int __stdcall v19c();

    virtual int __stdcall SetIndices(void*);



};

struct StateQuadDevice {

    virtual int v000();

    virtual int v004();

    virtual int v008();

    virtual int v00c();

    virtual int v010();

    virtual int v014();

    virtual int v018();

    virtual int v01c();

    virtual int v020();

    virtual int v024();

    virtual int v028();

    virtual int Begin(int);

    virtual int End(void*);

    virtual int v034();

    virtual int v038();

    virtual int v03c();

    virtual int v040();

    virtual int v044();

    virtual int v048();

    virtual int v04c();

    virtual int v050();

    virtual int v054();

    virtual int v058();

    virtual int v05c();

    virtual int v060();

    virtual int v064();

    virtual int v068();

    virtual int v06c();

    virtual int v070();

    virtual int v074();

    virtual int v078();

    virtual int v07c();

    virtual int v080();

    virtual int v084();

    virtual int v088();

    virtual int v08c();

    virtual int v090();

    virtual int v094();

    virtual int v098();

    virtual int v09c();

    virtual int v0a0();

    virtual int v0a4();

    virtual int v0a8();

    virtual int Select(int,int);



};

struct StreamRecord { void* unk00; void* unk04; void* buffer; unsigned int offset; unsigned int count; void* Buffer() const { return buffer; } unsigned Offset() const { return offset; } unsigned Count() const { return count; } };
struct FakeCOM_00e8f040;
struct Holder_00e8f040 {
    void SetComPointer(FakeCOM_00e8f040*);
};
struct VertexData : Holder_00e8f040 {

    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c;

    unsigned int streamSize;

    unsigned int* format;

    unsigned int* current;

    unsigned int unk02c; unsigned int unk030;

    IndexBuffer* indexBuffer;

    unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050;



    void NiGeometryBufferData_SetStreamCount(int flag);

    // void FUN_00e8f040(unsigned int val);

};

struct RendererContext {void ProcessCollector(void*,ParticleGeometry*,int,int,int,int);};

struct RendererStorage {

    IndexBuffer* EnsureIndexBuffer(unsigned int primitiveCount,unsigned int count,int a,int b,int force);

    IndexBuffer* AcquireCachedResource(unsigned int count,int a,int b,int force);

};

struct S_00e8c0d0 {

    void NiDX9VertexBufferManager_AllocateBufferSpace(VertexData*,int);

    unsigned int NiDX9VertexBufferManager_LockVB(unsigned int, unsigned int,unsigned int,unsigned int);

    bool CopyAndRelease(void*);

};

struct SceneArg {

    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c;

    Material* material;

    unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040;

    unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060;

    unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080;

    unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0;

    unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4;

    ParticleGeometry* geometry;

    unsigned int unk0bc;

    Overlay* overlay;



};

// NiDX9Renderer particle-drawing view: device at 0x288; its shared header lacks FUN_00e70140 and its draw helpers.
struct ParticleDrawContext {

    unsigned int unk000; unsigned int unk004; unsigned int unk008;

    Gate* gate;

    unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c;

    unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c;

    unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c;

    unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c;

    unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac;

    unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc;

    unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec;

    unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c;

    unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c;

    unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c;

    unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c;

    unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17c; unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18c;

    unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19c; unsigned int unk1a0; unsigned int unk1a4; unsigned int unk1a8; unsigned int unk1ac;

    unsigned int unk1b0; unsigned int unk1b4; unsigned int unk1b8; unsigned int unk1bc; unsigned int unk1c0; unsigned int unk1c4; unsigned int unk1c8; unsigned int unk1cc;

    unsigned int unk1d0; unsigned int unk1d4; unsigned int unk1d8; unsigned int unk1dc; unsigned int unk1e0; unsigned int unk1e4; unsigned int unk1e8; unsigned int unk1ec;

    unsigned int unk1f0; unsigned int unk1f4; unsigned int unk1f8; unsigned int unk1fc; unsigned int unk200; unsigned int unk204; unsigned int unk208; unsigned int unk20c;

    unsigned int unk210; unsigned int unk214; unsigned int unk218; unsigned int unk21c; unsigned int unk220; unsigned int unk224; unsigned int unk228; unsigned int unk22c;

    unsigned int unk230; unsigned int unk234; unsigned int unk238; unsigned int unk23c; unsigned int unk240; unsigned int unk244; unsigned int unk248; unsigned int unk24c;

    unsigned int unk250; unsigned int unk254; unsigned int unk258; unsigned int unk25c; unsigned int unk260; unsigned int unk264; unsigned int unk268; unsigned int unk26c;

    unsigned int unk270; unsigned int unk274; unsigned int unk278; unsigned int unk27c; unsigned int unk280; unsigned int unk284;

    QuadDevice* device;

    unsigned int unk28c; unsigned int unk290; unsigned int unk294; unsigned int unk298; unsigned int unk29c; unsigned int unk2a0; unsigned int unk2a4; unsigned int unk2a8;

    unsigned int unk2ac; unsigned int unk2b0; unsigned int unk2b4; unsigned int unk2b8; unsigned int unk2bc; unsigned int unk2c0; unsigned int unk2c4; unsigned int unk2c8;

    unsigned int unk2cc; unsigned int unk2d0; unsigned int unk2d4; unsigned int unk2d8; unsigned int unk2dc; unsigned int unk2e0; unsigned int unk2e4; unsigned int unk2e8;

    unsigned int unk2ec; unsigned int unk2f0; unsigned int unk2f4; unsigned int unk2f8; unsigned int unk2fc; unsigned int unk300; unsigned int unk304; unsigned int unk308;

    unsigned int unk30c; unsigned int unk310; unsigned int unk314; unsigned int unk318; unsigned int unk31c; unsigned int unk320; unsigned int unk324; unsigned int unk328;

    unsigned int unk32c; unsigned int unk330; unsigned int unk334; unsigned int unk338; unsigned int unk33c; unsigned int unk340; unsigned int unk344; unsigned int unk348;

    unsigned int unk34c; unsigned int unk350; unsigned int unk354; unsigned int unk358; unsigned int unk35c; unsigned int unk360; unsigned int unk364; unsigned int unk368;

    unsigned int unk36c; unsigned int unk370; unsigned int unk374; unsigned int unk378; unsigned int unk37c; unsigned int unk380; unsigned int unk384; unsigned int unk388;

    unsigned int unk38c; unsigned int unk390; unsigned int unk394; unsigned int unk398; unsigned int unk39c; unsigned int unk3a0; unsigned int unk3a4; unsigned int unk3a8;

    unsigned int unk3ac; unsigned int unk3b0; unsigned int unk3b4; unsigned int unk3b8; unsigned int unk3bc; unsigned int unk3c0; unsigned int unk3c4; unsigned int unk3c8;

    unsigned int unk3cc; unsigned int unk3d0; unsigned int unk3d4; unsigned int unk3d8; unsigned int unk3dc; unsigned int unk3e0; unsigned int unk3e4; unsigned int unk3e8;

    unsigned int unk3ec; unsigned int unk3f0; unsigned int unk3f4; unsigned int unk3f8; unsigned int unk3fc; unsigned int unk400; unsigned int unk404; unsigned int unk408;

    unsigned int unk40c; unsigned int unk410; unsigned int unk414; unsigned int unk418; unsigned int unk41c; unsigned int unk420; unsigned int unk424; unsigned int unk428;

    unsigned int unk42c; unsigned int unk430; unsigned int unk434; unsigned int unk438; unsigned int unk43c; unsigned int unk440; unsigned int unk444; unsigned int unk448;

    unsigned int unk44c; unsigned int unk450; unsigned int unk454; unsigned int unk458; unsigned int unk45c; unsigned int unk460; unsigned int unk464; unsigned int unk468;

    unsigned int unk46c; unsigned int unk470; unsigned int unk474; unsigned int unk478; unsigned int unk47c; unsigned int unk480; unsigned int unk484; unsigned int unk488;

    unsigned int unk48c; unsigned int unk490; unsigned int unk494; unsigned int unk498; unsigned int unk49c; unsigned int unk4a0; unsigned int unk4a4; unsigned int unk4a8;

    unsigned int unk4ac; unsigned int unk4b0; unsigned int unk4b4; unsigned int unk4b8; unsigned int unk4bc; unsigned int unk4c0; unsigned int unk4c4; unsigned int unk4c8;

    unsigned int unk4cc; unsigned int unk4d0; unsigned int unk4d4; unsigned int unk4d8; unsigned int unk4dc; unsigned int unk4e0; unsigned int unk4e4; unsigned int unk4e8;

    unsigned int unk4ec; unsigned int unk4f0; unsigned int unk4f4; unsigned int unk4f8; unsigned int unk4fc; unsigned int unk500; unsigned int unk504; unsigned int unk508;

    unsigned int unk50c; unsigned int unk510; unsigned int unk514; unsigned int unk518; unsigned int unk51c; unsigned int unk520; unsigned int unk524; unsigned int unk528;

    unsigned int unk52c; unsigned int unk530; unsigned int unk534; unsigned int unk538; unsigned int unk53c; unsigned int unk540; unsigned int unk544; unsigned int unk548;

    unsigned int unk54c; unsigned int unk550; unsigned int unk554; unsigned int unk558; unsigned int unk55c; unsigned int unk560; unsigned int unk564; unsigned int unk568;

    unsigned int unk56c; unsigned int unk570; unsigned int unk574; unsigned int unk578; unsigned int unk57c; unsigned int unk580; unsigned int unk584; unsigned int unk588;

    unsigned int unk58c; unsigned int unk590; unsigned int unk594; unsigned int unk598; unsigned int unk59c; unsigned int unk5a0; unsigned int unk5a4; unsigned int unk5a8;

    unsigned int unk5ac; unsigned int unk5b0; unsigned int unk5b4; unsigned int unk5b8; unsigned int unk5bc; unsigned int unk5c0; unsigned int unk5c4; unsigned int unk5c8;

    unsigned int unk5cc; unsigned int unk5d0; unsigned int unk5d4; unsigned int unk5d8; unsigned int unk5dc; unsigned int unk5e0; unsigned int unk5e4; unsigned int unk5e8;

    unsigned int unk5ec; unsigned int unk5f0; unsigned int unk5f4; unsigned int unk5f8; unsigned int unk5fc; unsigned int unk600; unsigned int unk604; unsigned int unk608;

    unsigned int unk60c; unsigned int unk610; unsigned int unk614; unsigned int unk618; unsigned int unk61c; unsigned int unk620; unsigned int unk624; unsigned int unk628;

    unsigned int unk62c; unsigned int unk630; NiPoint3 unk634; NiPoint3 unk640;

    NiPoint3 unk64c; NiPoint3 unk658; unsigned int unk664; unsigned int unk668;

    unsigned int unk66c; unsigned int unk670; unsigned int unk674; unsigned int unk678; unsigned int unk67c; unsigned int unk680; unsigned int unk684; unsigned int unk688;

    unsigned int unk68c; unsigned int unk690; unsigned int unk694; unsigned int unk698; unsigned int unk69c; unsigned int unk6a0; unsigned int unk6a4; unsigned int unk6a8;

    unsigned int unk6ac; unsigned int unk6b0; unsigned int unk6b4; unsigned int unk6b8; unsigned int unk6bc; unsigned int unk6c0; unsigned int unk6c4; unsigned int unk6c8;

    unsigned int unk6cc; unsigned int unk6d0; unsigned int unk6d4; unsigned int unk6d8; unsigned int unk6dc; unsigned int unk6e0; unsigned int unk6e4; unsigned int unk6e8;

    unsigned int unk6ec; unsigned int unk6f0; unsigned int unk6f4; unsigned int unk6f8;

    unsigned int disabled;

    unsigned int unk700; unsigned int unk704; unsigned int unk708; unsigned int unk70c; unsigned int unk710; unsigned int unk714; unsigned int unk718; unsigned int unk71c;

    unsigned int unk720; unsigned int unk724; unsigned int unk728; unsigned int unk72c; unsigned int unk730; unsigned int unk734; unsigned int unk738; unsigned int unk73c;

    unsigned int unk740; unsigned int unk744; unsigned int unk748; unsigned int unk74c; unsigned int unk750; unsigned int unk754; unsigned int unk758; unsigned int unk75c;

    unsigned int unk760; unsigned int unk764; unsigned int unk768; unsigned int unk76c; unsigned int unk770; unsigned int unk774; unsigned int unk778; unsigned int unk77c;

    unsigned int unk780; unsigned int unk784; unsigned int unk788; unsigned int unk78c; unsigned int unk790; unsigned int unk794; unsigned int unk798; unsigned int unk79c;

    unsigned int unk7a0; unsigned int unk7a4; unsigned int unk7a8; unsigned int unk7ac; unsigned int unk7b0; unsigned int unk7b4; unsigned int unk7b8; unsigned int unk7bc;

    unsigned int unk7c0; unsigned int unk7c4; unsigned int unk7c8; unsigned int unk7cc; unsigned int unk7d0; unsigned int unk7d4; unsigned int unk7d8; unsigned int unk7dc;

    unsigned int unk7e0; unsigned int unk7e4; unsigned int unk7e8; unsigned int unk7ec; unsigned int unk7f0; unsigned int unk7f4; unsigned int unk7f8; unsigned int unk7fc;

    unsigned int unk800; unsigned int unk804; unsigned int unk808; unsigned int unk80c; unsigned int unk810; unsigned int unk814; unsigned int unk818; unsigned int unk81c;

    unsigned int unk820; unsigned int unk824; unsigned int unk828; unsigned int unk82c; unsigned int unk830; unsigned int unk834; unsigned int unk838; unsigned int unk83c;

    unsigned int unk840; unsigned int unk844; unsigned int unk848; unsigned int unk84c; unsigned int unk850; unsigned int unk854; unsigned int unk858; unsigned int unk85c;

    unsigned int unk860; unsigned int unk864; unsigned int unk868; unsigned int unk86c; unsigned int unk870; unsigned int unk874; unsigned int unk878; unsigned int unk87c;

    unsigned int unk880; unsigned int unk884; unsigned int unk888; unsigned int unk88c; unsigned int unk890; unsigned int unk894; unsigned int unk898; unsigned int unk89c;

    unsigned int unk8a0; unsigned int unk8a4; unsigned int unk8a8;

    RendererContext* ctx8ac;

    unsigned int unk8b0;

    void* extra8b4;

    StateQuadDevice* state;

    S_00e8c0d0* shader;

    RendererStorage* storage;

    unsigned int unk8c4; unsigned int unk8c8; unsigned int unk8cc; unsigned int unk8d0; unsigned int unk8d4; unsigned int unk8d8; unsigned int unk8dc; unsigned int unk8e0;

    unsigned int unk8e4; unsigned int unk8e8; unsigned int unk8ec; unsigned int unk8f0; unsigned int unk8f4; unsigned int unk8f8; unsigned int unk8fc; unsigned int unk900;

    unsigned int unk904; unsigned int unk908; unsigned int unk90c; unsigned int unk910; unsigned int unk914; unsigned int unk918; unsigned int unk91c; unsigned int unk920;

    unsigned int unk924; unsigned int unk928; unsigned int unk92c; unsigned int unk930; unsigned int unk934; unsigned int unk938; unsigned int unk93c; unsigned int unk940;



    FakeCOM_00e8f040* NiDX9Renderer_GetDecl_Particles();

    FakeCOM_00e8f040* NiDX9Renderer_GetDecl_ParticlesSubTexture();

    void NiDX9Renderer_PackPoints(unsigned int, unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);

    void NiDX9Renderer_PackPointsSubTexture(unsigned int, unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);

    void NiDX9Renderer_RenderParticles(SceneArg* input);

};

static __forceinline bool FillIndices(ParticleGeometry* a, IndexBuffer* data, unsigned int primitiveCount)
{
        void* indexDest = 0;
        if (data->Lock(0, (unsigned int)12 * (unsigned short)primitiveCount, &indexDest, 0) >= 0) {
            unsigned short* sourceIndices = a->rawIndices;
            unsigned short* p = (unsigned short*)indexDest;
            for (unsigned int i = 0; (unsigned short)primitiveCount > i; i++) {
                unsigned int base = sourceIndices[i] * 4;
                *p++ = base;
                *p++ = base + 1;
                *p++ = base + 2;
                *p++ = base;
                *p++ = base + 2;
                *p++ = base + 3;
            }
            data->Unlock();
        } else {
            Object_DoNothing("NiDX9IndexBufferManager::PackBuffer> Failed to lock index buffer\n");
            data->Unlock();
            data->Release();
            return 0;
        }
    return 1;
}

// Draws particle geometry by setting up vertex/index buffers, applying material and transform, then issuing DrawIndexedPrimitive calls per overlay command.
// @fnv 0x00e70140
// src: COMMUNITY 0x00e70140
void ParticleDrawContext::NiDX9Renderer_RenderParticles(SceneArg* apSceneArg)
{
    if ((unsigned char)disabled) return;
    if ((gate->flags[6] & 1) && (gate->aux->m3c <= 0.0f)) return;

    ParticleGeometry* a = apSceneArg->geometry;
    unsigned int overlay;
    void* indexDest;
    IndexBuffer* data = 0;
    // This frame is copied in full; its matrix storage needs no construction.
    unsigned int srcMaterialStorage[sizeof(FrameInfo) / sizeof(unsigned int)];
    FrameInfo& srcMaterial = *reinterpret_cast<FrameInfo*>(srcMaterialStorage);
    memcpy(&srcMaterial, &apSceneArg->unk068, sizeof(srcMaterial));
    Material* __restrict passes = apSceneArg->material;
    if (!passes) passes = (Material*)DAT_011f4288;
    Material p28 = *passes;

    unsigned int primitiveCount = a->GetCount();
    unsigned int elementCount = a->countInfo;
    if (!(unsigned short)primitiveCount) return;

    Overlay* overlayArg;
    overlayArg = apSceneArg->overlay;
    ctx8ac->ProcessCollector(extra8b4, a, 0, 0, 0, 0);

    overlay = (unsigned int)(unsigned short)primitiveCount * 4;
    VertexData* buffer = a->vertex;
    buffer->NiGeometryBufferData_SetStreamCount(1);

    buffer->unk018 = overlay;
    buffer->unk01c = (unsigned int)4 * (unsigned short)elementCount;
    buffer->unk040 = (unsigned int)(unsigned short)primitiveCount * 2;
    buffer->unk044 = (unsigned int)(unsigned short)elementCount * 2;
    buffer->unk050 = 0;
    buffer->unk048 = 1;
    buffer->unk04c = 0;
    unk664 = *(unsigned int*)&p28.r;
    *(float*)&unk670 = p28.a;
    unk668 = *(unsigned int*)&p28.g;
    unk66c = *(unsigned int*)&p28.b;
    buffer->unk004 = 0x1c00000;

    if (a->rawIndices) {
        data = buffer->indexBuffer;
        unsigned int nbytes = (unsigned int)(unsigned short)elementCount * 12;
        if (!data) {
            data = storage->AcquireCachedResource(nbytes, 0, 0x65, !DAT_0126f0d0);
            buffer->indexBuffer = data;
            buffer->unk02c = (unsigned int)(unsigned short)elementCount * 6;
            buffer->unk030 = nbytes;
            if (data == 0) return;
        }
        if (!FillIndices(a, data, primitiveCount)) return;
    } else {
        data = storage->EnsureIndexBuffer((unsigned short)primitiveCount, (unsigned short)elementCount, 0, 0, !DAT_0126f0d0);
    }
    if (data == 0) return;

    int m = a->m28;
    int p4c = a->f4c;
    unsigned int k_field_8 = a->f54;
    int primitiveSize = a->unk020;
    unsigned long p5c = a->f5c;
    unsigned int p64 = a->f64;

    state->Begin(0);
    FUN_00b71a40(&unk940, &srcMaterial.m_kOrientation, &srcMaterial.m_kTranslation, srcMaterial.m_fScale);
    device->SetTransform(0x100, &unk940);
    state->End(&srcMaterial);

    { NiPoint3 transformed; CopyPoint3Storage(unk64c, *NiPoint3_TransformByMatrix3(&transformed, unk634, (const float*)&srcMaterial)); }
    { NiPoint3 transformed; CopyPoint3Storage(unk658, *NiPoint3_TransformByMatrix3(&transformed, unk640, (const float*)&srcMaterial)); }

    FakeCOM_00e8f040* handle;
    if (p64) {
        handle = NiDX9Renderer_GetDecl_Particles();
        buffer->SetComPointer(handle);
        if (0 < buffer->streamSize) buffer->format[0] = 0x28;
        shader->NiDX9VertexBufferManager_AllocateBufferSpace(buffer, 0);
        StreamRecord* j = (buffer->streamSize > 0) ? (StreamRecord*)*buffer->current : 0;
        indexDest = &j->buffer;
        if (!j->Buffer()) return;
        unsigned int ib = shader->NiDX9VertexBufferManager_LockVB((unsigned int)j->Buffer(), (unsigned int)j->Offset(), overlay * 40, (unsigned int)j->Count());
        if (ib == 0) return;
        this->NiDX9Renderer_PackPoints(ib, primitiveSize, m, p4c, k_field_8, p5c, p64, primitiveCount);
    } else {
        handle = NiDX9Renderer_GetDecl_ParticlesSubTexture();
        buffer->SetComPointer(handle);
        if (0 < buffer->streamSize) buffer->format[0] = 0x24;
        shader->NiDX9VertexBufferManager_AllocateBufferSpace(buffer, 0);
        StreamRecord* j = (buffer->streamSize > 0) ? (StreamRecord*)*buffer->current : 0;
        indexDest = &j->buffer;
        if (!j->Buffer()) return;
        unsigned int ib = shader->NiDX9VertexBufferManager_LockVB((unsigned int)j->Buffer(), (unsigned int)j->Offset(), 36 * overlay, (unsigned int)j->Count());
        if (!ib) return;
        this->NiDX9Renderer_PackPointsSubTexture(ib, primitiveSize, m, p4c, k_field_8, p5c, primitiveCount);
    }

    shader->CopyAndRelease(*(void**)indexDest);
    int localFrame = (int)overlayArg->GetCommand();
    char* k = (char*)apSceneArg + 0x9c;
    overlayArg->BeginA(k);
    overlayArg->BeginB(k);
    overlayArg->BeginC(k);
    overlayArg->BeginD(k);
    overlayArg->BeginE(k, 1);
    state->Select(buffer->unk010, 0);
    device->SetStreamSource(0, *(void**)indexDest, 0, (buffer->streamSize > 0) ? buffer->format[0] : 0);
    device->SetIndices(data);
    if (localFrame) {
        do {
            device->DrawIndexedPrimitive(buffer->unk03c, buffer->unk038, 0, buffer->unk018, 0, buffer->unk040);
        } while (overlayArg->NextCommand());
    }
    overlayArg->Finish(k);
}
