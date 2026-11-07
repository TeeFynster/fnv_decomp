
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

class NiRenderTargetGroup;
#include "niconsolerenderer_packet.h"
enum _D3DFORMAT
{
    D3DFMT_PACKET_FORCE_DWORD = 0x7fffffff
};
struct RendererPacketEntry
{
    unsigned int pad[2];
    void* resource;
};
#include "../../../../include/NiMemObject.h"
class GraphicsRenderer : public NiMemObject
{
  public:
    virtual ~GraphicsRenderer() throw();
    GraphicsRenderer() throw();
    unsigned int pad[7];
    unsigned int count;
    unsigned int pad24;
    RendererPacketEntry** entries;
    __declspec(noinline) bool HasPendingPackets();
    static const char* GetD3DFormatName(_D3DFORMAT);
    char remaining[0xb80 - 44];
    static GraphicsRenderer* Create(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                    unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                    unsigned int, unsigned int, unsigned int);
    bool Create(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
class RecursiveSpinLock
{
  public:
    unsigned int value;
    void Lock(const char*);
};
template <class T> class PoolAllocatorBase
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* next;
        LinkedListEntry* prev;
        char* data;
    };
    static LinkedListEntry* ms_pFreeList;
    static RecursiveSpinLock ms_kPoolState;
};
extern unsigned int DAT_011c5f84;
template <class T> class NiTPointerAllocator
{
};
template <class Alloc, class T> class NiTPointerListBase
{
  public:
    typedef PoolAllocatorBase<unsigned int>::LinkedListEntry Node;
    Node* head;
    Node* tail;
    unsigned int count;
    T RemoveTail();
};
class ShaderPassRenderer
{
  public:
    static unsigned int Create(unsigned int);
};
class NiObject;
class NiStream
{
  public:
    static void UnregisterObjectLoader(const char*);
    static int RegisterObjectLoader(const char*, NiObject* (*)());
};
extern "C" int fnv_CopyFilePath(char*, unsigned int, const char*, unsigned int);
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
extern "C" void* g_011f4430;
void* __cdecl NiVertexColorProperty_GetRTTI();
extern "C" int g_011f443c;
int __cdecl NiZBufferProperty_GetRTTI();
int __cdecl NiZBufferProperty_GetType_0();
int __cdecl Object_ComputeValue_00dc9e60();
struct NiDX9Renderer
{
    unsigned int pad[0x228];
    unsigned int m_8a0;
    unsigned int __thiscall NiDX9Renderer_GetMaxBuffersPerRenderTargetGroup();
};
struct FUN_00e695f0_shell
{
    char pad[0x8a4];
    unsigned char flag;
    unsigned char NiDX9Renderer_GetIndependentBufferBitDepths();
};
struct FUN_00e69600_shell
{
    unsigned int __thiscall NiDX9Renderer_GetDefaultRenderTargetGroup();
};
struct FUN_00e69900_shell
{
    void SetTwoValues(unsigned int a, unsigned int b);
};
void NiDX9Renderer_SetLastErrorString(const char* path);
struct FUN_00e69b40_shell
{
    unsigned int pad[8];
    unsigned int count;
    unsigned int pad24;
    unsigned int* entries;
    unsigned int GetEntry(unsigned int index);
};
unsigned int GetValueForIndex(unsigned int param);
#include "../../../../include/NiTransform.h"
extern NiPoint3 DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f4754;
struct NiWorldToSkin
{
    float r00, r10, r20;
    float tx;
    float r01, r11, r21;
    float ty;
    float r02, r12, r22;
    float tz;
    float pad[3];
    float scale;
};
void __cdecl BuildWorldToSkinTransform(NiWorldToSkin* out, const NiTransform* kWorldToRootParent,
                                       const NiPoint3* kIntersectionOffset, float fScale);
extern int DAT_0126efc0;
bool __stdcall NiDX9Renderer_SetMipmapSkipLevel(int value);
void __cdecl _NiAlignedFree(void*);
void __stdcall NiDX9Renderer_PurgeSkinInstance(void* a1);
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
struct LinkedListEntry
{
    LinkedListEntry* next;
    LinkedListEntry* prev;
    char* data;
};
void __stdcall NiTPointerListBase_DeleteItem(LinkedListEntry* a);
struct NiTMapBase_StandIn
{
    void RemoveAll();
};
extern "C" void __cdecl _NiFreeAlias(void*);
extern "C" void* __cdecl _DeallocateAlias(void*);
extern int DAT_010eda84;
extern int DAT_010edb5c;
extern struct MemoryManager
{
    void* Deallocate(void*);
} g_memoryManager;
struct FUN_00e6eab0_shell : NiTMapBase_StandIn
{
    char pad[8];
    void* data;
    int __thiscall DestroyMap(int flag);
};
struct NodePoolView
{
    void* AddHead();
};
struct FUN_00e72e50_shell
{
    void* __thiscall FUN_00e72e50();
};
extern "C" void* g_0126f0f0;
void* __cdecl NiDX9Renderer_GetRTTI();
struct FUN_00e757c0_shell
{
    unsigned char* data;
    unsigned char NiDX9Renderer_IsVerticalDisplay();
};
struct FUN_00e75830_shell : GraphicsRenderer
{
    float GetSomeFloat();
};
struct FUN_00e75840_shell
{
    unsigned int pad[0x5e0 / 4];
    unsigned int color;
    void NiDX9Renderer_SetBackgroundColor(float* param);
};
extern "C" void* g_01270900;
void* __cdecl NiShaderDeclaration_GetRTTI();
struct FUN_00e758f0_shell
{
    void PackColorToUInt(float* floats);
};
extern int DAT_0126f580[];
void __cdecl NiDX92DBufferData_ClearRenderTarget(int* param1, int param2);
