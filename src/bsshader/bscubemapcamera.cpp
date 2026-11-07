// src/bsshader/bscubemapcamera.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bscubemapcamera.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
#include "../../include/ImageSpaceManager.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiDX9Renderer.h"
extern int(__stdcall* DAT_00fdf1c0)(void*);
__declspec(dllimport) int __stdcall InterlockedDecrement(long*);
struct RefObject
{
    virtual void slot0();
    virtual void Destroy();
    long refs;
    void AcquireReference()
    {
        DAT_00fdf1c0(&refs);
    }
};
template <class T> struct Ptr
{
    T* value;
    Ptr(T* p = 0) : value(p)
    {
        if (value)
            DAT_00fdf1c0(&value->refs);
    }
    ~Ptr()
    {
        T* p = value;
        if (p && !InterlockedDecrement(&p->refs))
            p->Destroy();
    }
    operator T*() const
    {
        return value;
    }
    T* operator->() const
    {
        return value;
    }
    Ptr& operator=(const Ptr& p)
    {
        T* old = value;
        if (old != p.value)
        {
            if (old && !InterlockedDecrement(&old->refs))
                old->Destroy();
            value = p.value;
            if (value)
                DAT_00fdf1c0(&value->refs);
        }
        return *this;
    }
    Ptr& operator=(T* p)
    {
        T* old = value;
        if (old != p)
        {
            if (old)
            {
                if (!InterlockedDecrement(&old->refs))
                    old->Destroy();
            }
            value = p;
            if (p)
                DAT_00fdf1c0(&p->refs);
        }
        return *this;
    }
};
struct Cube : RefObject
{
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
    Ptr<RefObject> current;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    unsigned face;
    Ptr<RefObject> faces[6];
    void Select(unsigned n)
    {
        face = n;
        current = faces[n];
    }
};
struct TextureRef
{
    virtual void slot0();
    virtual void destroy();
    long refs;
    void AcquireReference()
    {
        DAT_00fdf1c0(&refs);
    }
    void Destroy()
    {
        destroy();
    }
};

struct RenderTexture : TextureRef
{
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
    Ptr<Cube> cube;
    void* FUN_00b6b260();
};
struct Color
{
    float channels[4];
    Color()
    {}
    Color(float r, float g, float b, float a)
    {
        channels[0] = r;
        channels[1] = g;
        channels[2] = b;
        channels[3] = a;
    }
};


struct Scene : RefObject
{
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
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void UpdateScene(void*);
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
    bool flag;
    char unk085;
    short unk086;
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
    enum Mode
    {
        normal,
        special = 7
    };
    volatile Mode mode;
};
struct Water
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
    RenderTexture* texture;
    unsigned short mask;
};
struct UpdateData
{
    float time;
    bool flag0;
    bool flag1;
    bool flag2;
    bool flag3;
    bool flag4;
};
struct FUN_00a69400
{
    void* vtbl;
    int unk004;
    int unk008;
    void* camera;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    struct Plane
    {
        float x, y, z, w;
    };
    Plane planes[6];
    unsigned activePlanes;
    FUN_00a69400(void*);
    void NiCullingProcess_SetFrustum(void*);
};
extern "C" void* DAT_0101e2ec;
struct CleanupRef
{
    struct Methods
    {
        void(__thiscall* slot0)(CleanupRef*);
        void(__thiscall* destroy)(CleanupRef*);
    };
    Methods* methods;
    long refs;
    void AcquireReference()
    {
        DAT_00fdf1c0(&refs);
    }
    void Destroy()
    {
        Methods* table = methods;
        table->destroy(this);
    }
};

struct S00bd7bb0_Cull : FUN_00a69400
{
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
    int unk0bc, unk0c0;
    CleanupRef* ref;
    S00bd7bb0_Cull(void* p) : FUN_00a69400(p)
    {
        vtbl = &DAT_0101e2ec;
        unk090 = 0;
        unk0bc = 0;
        unk0c0 = 0;
        ref = 0;
    }
    void FUN_004a0f60();
    ~S00bd7bb0_Cull()
    {
        FUN_004a0f60();
    }
    void ClearRef()
    {
        CleanupRef* p = 0;
        if (ref != p)
        {
            CleanupRef* old = ref;
            if (old && !InterlockedDecrement(&old->refs))
                old->Destroy();
            ref = p;
            if (ref)
                DAT_00fdf1c0(&ref->refs);
        }
    }
    void BSCullingProcess_SetAccumulator(Scene*);
};
struct TextureArrayFields
{
    void* table;
    void* data;
    unsigned short capacity, growth, count, used;
};
struct RenderStateFields
{
    void* table;
    unsigned modulus;
    void* buckets;
    unsigned count;
};
struct GlobalObjectO2_00b8a9e0
{
    void* table;
    TextureArrayFields borrowedTypes, borrowedFilters;
    int filterMode;
    unsigned clearFlags;
    Color clearColor;
    float* vertexConstants;
    int vertexCount;
    float* pixelConstants;
    int pixelCount;
    void* vertexMap;
    void* pixelMap;
    bool useTexOffset[3];
    TextureArrayFields inputTextures, inputFilterModes;
    RenderStateFields renderStates;
    GlobalObjectO2_00b8a9e0();
    ~GlobalObjectO2_00b8a9e0();
    void FUN_00b8ab10(int, int);
    void FUN_00b8a760(int, float, float, float, float);
};
inline void S00bd7bb0_SetRow(GlobalObjectO2_00b8a9e0& p, int row, float x, const float& y)
{
    p.FUN_00b8a760(row, x, y, 0.0f, 0.0f);
}
extern NiRenderer* DAT_011f9508;
extern int DAT_011a9bd0, DAT_011a9bd4, DAT_011a9bd8, DAT_011a9bdc;
extern unsigned DAT_011f91b8;
extern void* DAT_011f9520;
extern ImageSpaceManager* DAT_011f91ac;
extern int DAT_011ff9f0;
void BSRenderedTexture_StartOffscreen(unsigned, void*);
void BSShaderUtil_AccumulateScene(void*, void*, S00bd7bb0_Cull*);
void FUN_00b6c0d0(void*, Scene*, int);
void BSShaderLightingProperty_SetLight(unsigned, Water*, float);
void FUN_00b97fa0(int, int);
void FUN_00b97ff0(int, int, int);
void FUN_00b6b790();
inline float Sin(float x)
{
    return (float)sin(x);
}
inline float Cos(float x)
{
    return (float)cos(x);
}
struct Camera
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
    Ptr<RenderTexture> target;
    Ptr<Water> water;
    void* sceneData;
    Ptr<Scene> scene;
    void BSCubeMapCamera_SetupTransformation(int);
    void NiAVObject_Update(UpdateData&);
    void CullScene(Water*);
    void BSCubeMapCamera_ClickCubeMapWithMask(int);
};
// For each selected face, selects the cube face, may update and cull the scene, then calls the image-space manager for supported faces.
// @fnv 0x00bd7bb0
// src: COMMUNITY 0x00bd7bb0
void Camera::BSCubeMapCamera_ClickCubeMapWithMask(int aiFace)
{
    UpdateData updateData;
    Color savedColor;
    *(int*)&savedColor.channels[0] = DAT_011a9bd0;
    *(int*)&savedColor.channels[1] = DAT_011a9bd4;
    *(int*)&savedColor.channels[2] = DAT_011a9bd8;
    *(int*)&savedColor.channels[3] = DAT_011a9bdc;
    unsigned short mask = 0;
    static_cast<NiDX9Renderer*>(DAT_011f9508)->GetBackgroundColor(reinterpret_cast<NiVector4*>(&savedColor));
    if (scene->mode == Scene::special)
    {
        mask = water->mask;
        Color c(4096.0f, 4096.0f, 4096.0f, 1.0f);
        static_cast<NiDX9Renderer*>(DAT_011f9508)->SetBackgroundColor(reinterpret_cast<NiVector4*>(&c));
    }
    for (int face = 0; face < 6; ++face)
    {
        if (aiFace != -1 && face != aiFace)
            continue;
        BSCubeMapCamera_SetupTransformation(face);
        Cube* cube = target ? target->cube : (const Ptr<Cube>&)Ptr<Cube>();
        cube->Select(face);
        BSRenderedTexture_StartOffscreen(7, target->FUN_00b6b260());
        unsigned bit = 0;
        switch (face)
        {
        case 1:
            bit = 2;
            break;
        case 0:
            bit = 1;
            break;
        case 3:
            bit = 8;
            break;
        case 2:
            bit = 4;
            break;
        case 5:
            bit = 32;
            break;
        case 4:
            bit = 16;
            break;
        }
        if (!(unsigned short)(bit & mask))
        {
            updateData.time = 0.0f;
            updateData.flag0 = false;
            updateData.flag1 = false;
            updateData.flag2 = false;
            updateData.flag3 = false;
            updateData.flag4 = false;
            NiAVObject_Update(updateData);
            if (DAT_011f91b8 != 7)
            {
                if (sceneData)
                {
                    bool held = false;
                    if (scene->refs == 1)
                    {
                        scene->AcquireReference();
                        held = true;
                    }
                    scene->UpdateScene(this);
                    scene->flag = true;
                    S00bd7bb0_Cull cull(0);
                    cull.camera = this;
                    cull.NiCullingProcess_SetFrustum(&unk0dc);
                    cull.BSCullingProcess_SetAccumulator(scene);
                    BSShaderUtil_AccumulateScene(this, sceneData, &cull);
                    FUN_00b6c0d0(this, scene, 0);
                    cull.ClearRef();
                    if (held)
                    {
                        Scene* p = scene;
                        if (!InterlockedDecrement(&p->refs))
                            p->Destroy();
                    }
                }
            }
            else if (water)
            {
                BSShaderLightingProperty_SetLight(0, water, 1.0f);
                target = water.value->texture;
                CullScene(water);
            }
        }
        FUN_00b97fa0(1, 1);
        FUN_00b97ff0(6, 7, 0);
        void* destination = DAT_011f9520;
        GlobalObjectO2_00b8a9e0 imageSpaceParams;
        ImageSpaceManager* manager = DAT_011f91ac;
        NiRenderer* renderer = DAT_011f9508;
        imageSpaceParams.FUN_00b8ab10(2, 0);
        switch (face)
        {
        case 1: {
            imageSpaceParams.FUN_00b8a760(0, Cos(1.5707963267948966), Sin(1.5707963267948966), 0.0f, 0.0f);
            imageSpaceParams.FUN_00b8a760(1, -Sin(1.5707963267948966), Cos(1.5707963267948966), 0.0f, 0.0f);
            manager->ImageSpaceManager_RenderEffect_2(47, renderer, destination, target, &imageSpaceParams, 0);
            break;
        }
        case 0: {
            imageSpaceParams.FUN_00b8a760(0, Cos(4.7123889923095703), Sin(4.7123889923095703), 0.0f, 0.0f);
            imageSpaceParams.FUN_00b8a760(1, -Sin(4.7123889923095703), Cos(4.7123889923095703), 0.0f, 0.0f);
            manager->ImageSpaceManager_RenderEffect_2(47, renderer, destination, target, &imageSpaceParams, 0);
            break;
        }
        case 3: {
            imageSpaceParams.FUN_00b8a760(0, Cos(3.1415927410125732), Sin(3.1415927410125732), 0.0f, 0.0f);
            imageSpaceParams.FUN_00b8a760(1, -Sin(3.1415927410125732), Cos(3.1415927410125732), 0.0f, 0.0f);
            manager->ImageSpaceManager_RenderEffect_2(47, renderer, destination, target, &imageSpaceParams, 0);
            break;
        }
        case 2: {
            imageSpaceParams.FUN_00b8a760(0, Cos(0.0), Sin(0.0), 0.0f, 0.0f);
            imageSpaceParams.FUN_00b8a760(1, -Sin(0.0), Cos(0.0), 0.0f, 0.0f);
            manager->ImageSpaceManager_RenderEffect_2(47, renderer, destination, target, &imageSpaceParams, 0);
            break;
        }
        case 4:
            manager->ImageSpaceManager_RenderEffect_2(47, renderer, destination, target, &imageSpaceParams, 0);
            break;
        }
        --DAT_011ff9f0;
        FUN_00b97fa0(0, 0);
        FUN_00b6b790();
    }
    static_cast<NiDX9Renderer*>(DAT_011f9508)->SetBackgroundColor(reinterpret_cast<NiVector4*>(&savedColor));
}
