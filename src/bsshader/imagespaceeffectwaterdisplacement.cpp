// Keep the shared string operations inline, as in the original water displacement update.
#define inline __forceinline
#include "../../include/NiFixedString.h"
#undef inline
#include "../../include/MemoryManager.h"
#include "../../include/NiMemObject.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiScreenElementsData.h"
#include "../../include/NiScreenElements.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/ImageSpaceTexture.h"
#include "../../include/BSRenderedTexture.h"
#include "../../include/ImageSpaceEffectParam.h"
#include "../../include/NiPoint4.h"

// src/bsshader/imagespaceeffectwaterdisplacement.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectwaterdisplacement.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// Preserve the original NiMemObject allocation and throwing new-expression bookkeeping.
__forceinline void* __cdecl operator new(size_t size)
{
    return NiMemObject::operator new(size);
}

struct RenderTargetGroup
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void vfn_0014();
    virtual void vfn_0018();
    virtual void vfn_001c();
    virtual void vfn_0020();
    virtual void vfn_0024();
    virtual void vfn_0028();
    virtual void vfn_002c();
    virtual void vfn_0030();
    virtual void vfn_0034();
    virtual void vfn_0038();
    virtual void vfn_003c();
    virtual void vfn_0040();
    virtual void vfn_0044();
    virtual void vfn_0048();
    virtual void vfn_004c();
    virtual void vfn_0050();
    virtual void vfn_0054();
    virtual void vfn_0058();
    virtual void vfn_005c();
    virtual void vfn_0060();
    virtual void vfn_0064();
    virtual void vfn_0068();
    virtual void vfn_006c();
    virtual void vfn_0070();
    virtual void vfn_0074();
    virtual void vfn_0078();
    virtual void vfn_007c();
    virtual void vfn_0080();
    virtual void vfn_0084();
    virtual void vfn_0088();
    virtual void vfn_008c();
    virtual void vfn_0090();
    virtual void vfn_0094();
    virtual void vfn_0098();
    virtual void vfn_009c();
    virtual void vfn_00a0();
    virtual void vfn_00a4();
    virtual void vfn_00a8();
    virtual void vfn_00ac();
    virtual void vfn_00b0();
    virtual void* GetView();
};

// The shared layout lacks constructor 0x00b6b380; expose it on a fieldless derived helper.
struct RenderedTextureWrapper : public BSRenderedTexture, public NiMemObject
{
    RenderedTextureWrapper(void*, int, int, void*);
};

struct HolderForAccum
{
    virtual void Dispose();
    virtual void Dispatch(void*, void*, void*, int);
    void SetAccumulatorAt(unsigned int, void*, unsigned int);
};

struct Emitter
{
    void FUN_00b8a790(int index, float x, float y, float z, float w);
    void SetFloat4At(int index, float x, float y, float z, float w);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

template <class T> __forceinline NiPointer<T>::NiPointer(T* p) : m_pObject(p)
{
    if (m_pObject)
    {
        InterlockedIncrement((volatile long*)&m_pObject->m_uiRefCount);
    }
}

template <class T> __forceinline NiPointer<T>::~NiPointer()
{
    if (m_pObject)
    {
        if (InterlockedDecrement((volatile long*)&m_pObject->m_uiRefCount) == 0)
        {
            m_pObject->DeleteThis();
        }
    }
}

template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

inline NiUpdateData::NiUpdateData(float t) : fTime(t), pad1(false), pad2(false), pad3(false), pad4(false), pad5(false)
{}

inline NiFixedString::operator const void*() const
{
    return &m_kHandle;
}

struct Allocator
{
    virtual void Delete0();
    virtual void Delete1();
    virtual void Free(void*);
};

struct GameObject
{
    int unk00;
    int unk04;
    int unk08;
    HolderForAccum** nodes;
    int unk10;
    int unk14;
    int unk18;
    Emitter** emitters;
    int unk20;
    int unk24;
    int unk28;
    ImageSpaceTexture** assets;
    template <int I> ImageSpaceTexture*& GetAsset()
    {
        return assets[I];
    }
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
    NiPointer<NiScreenElements> widget;
    float time;
    float previous;
    int unk64;
    float accumulated;
    float step;

    void ImageSpaceEffectWaterDisplacement_Render(void* arg1, void* arg2, int arg3, int arg4);
};

extern float DAT_010313d4;
extern float DAT_011f9410;
extern float DAT_011ffff4;
extern float DAT_010542a4;
extern float DAT_01013ea4;
extern unsigned char DAT_011fffec;
extern unsigned char DAT_011fffed;
extern unsigned char DAT_01200000;
extern int DAT_011ffffc;
extern int DAT_011ada08;
extern int DAT_011ada0c;
extern int DAT_011ada18;
extern int DAT_011ada1c;
extern NiPoint2* DAT_011ada04;
extern NiPoint2* DAT_011ada14;
extern Allocator DAT_011ada00;
extern Allocator DAT_011ada10;
extern NiPoint4 DAT_01200004;
extern NiPoint4 DAT_01200014;
extern NiPoint2 DAT_01200024;
extern NiPoint4 DAT_0120002c;
extern NiPoint4 DAT_0120003c;
extern void* DAT_011f9508;
extern ImageSpaceManager* DAT_011f91ac;

static HolderForAccum* GetNode(HolderForAccum* p)
{
    void* d = p ? (void*)((char*)p - 0x6c) : 0;
    return d ? (HolderForAccum*)((char*)d + 0x6c) : 0;
}

// @fnv 0x00ba0900
// src: XBOX_PDB 0x00ba0900
void GameObject::ImageSpaceEffectWaterDisplacement_Render(void* arg1, void* arg2, int arg3, int arg4)
{
    if (DAT_011fffed)
    {
        step = DAT_010313d4;
        float nextTime = time + DAT_011f9410;
        time = nextTime;
        accumulated += nextTime;
    }
    else
    {
        step = DAT_010313d4;
        float nextTime = time + DAT_011f9410;
        time = nextTime;
        accumulated += nextTime;
    }

    ImageSpaceTexture tex54;
    ImageSpaceTexture tex64;
    ImageSpaceTexture tex34;

    tex64.ImageSpaceTexture_BorrowRenderedTexture(8);

    tex34.ImageSpaceTexture_SetTexture((BSRenderedTexture*)new RenderedTextureWrapper(tex64.ImageSpaceTexture_GetRenderedTexture()->BSRenderedTexture_GetTexture(), 0, 1,
                                         ((RenderTargetGroup*)GetAsset<1>()->ImageSpaceTexture_GetRenderedTexture()->GetGroup())->GetView()));

    ImageSpaceTexture tex44;

    if (DAT_011fffec)
    {
        HolderForAccum* node = GetNode(nodes[0]);
        Emitter* pEmitter = emitters[0];

        node->SetAccumulatorAt(0, &tex34, 0);
        node->SetAccumulatorAt(1, assets[1], 1);
        node->Dispatch(arg1, arg2, pEmitter, 1);

        tex44.InitializeFields_00ba3940(assets[1]);
        tex54.InitializeFields_00ba3940(&tex34);
        tex34.InitializeFields_00ba3940(&tex44);
        DAT_011fffec = 0;
    }

    if (DAT_011fffed)
    {
        HolderForAccum* node = GetNode(nodes[1]);
        Emitter* pEmitter = emitters[1];

        pEmitter->FUN_00b8a790(0, time, 0.0f, 0.0f, 0.0f);
        pEmitter->FUN_00b8a790(1, DAT_011ffff4, 0.0f, 0.0f, 0.0f);
        pEmitter->FUN_00b8a790(2, DAT_01200024.x, DAT_01200024.y, 0.0f, 0.0f);
        pEmitter->FUN_00b8a790(4, DAT_01200004.x, DAT_01200004.y, DAT_01200004.z, DAT_01200004.w);
        pEmitter->FUN_00b8a790(5, DAT_01200014.x, DAT_01200014.y, DAT_01200014.z, DAT_01200014.w);

        node->SetAccumulatorAt(0, &tex34, 0);
        node->SetAccumulatorAt(1, assets[1], 0);
        node->Dispatch(arg1, arg2, pEmitter, 1);

        if (DAT_011fffed)
        {
            DAT_011ffffc = 0;
            HolderForAccum* handler = GetNode(nodes[2]);
            Emitter* secondary = emitters[2];
            handler->SetAccumulatorAt(0, &tex34, 0);

            if ((unsigned int)DAT_011ada08 > 0)
            {
                if (!widget.m_pObject)
                {
                    NiPointer<NiScreenElementsData> spScreenData(
                        ::new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1));
                    widget = ::new NiScreenElements(spScreenData);

                    NiScreenElementsData* localData0 = (NiScreenElementsData*)widget->m_spModelData.m_pObject;
                    localData0->FUN_00a87ae0(4, 0, 0);
                    NiScreenElementsData* localData1 = (NiScreenElementsData*)widget->m_spModelData.m_pObject;
                    localData1->SetRectangle(0, 0.0f, DAT_01013ea4, 1.0f, DAT_010542a4);
                    ((NiScreenElementsData*)widget->m_spModelData.m_pObject)->NiScreenElementsData_UpdateBound();
                    NiScreenElementsData* localData2 = (NiScreenElementsData*)widget->m_spModelData.m_pObject;
                    localData2->FUN_00a88130(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
                    widget->UpdateProperties();

                    NiUpdateData kData(0.0f);
                    widget->Update(&kData);

                    widget->SetName(NiFixedString("Partial Screen Trishape"));
                }

                for (int i = 0; i < DAT_011ada08; ++i)
                {
                    NiPoint2* endpoint = &DAT_011ada14[i];
                    DAT_0120002c.x = DAT_011ada04[i].x - DAT_011ada14[i].x;
                    DAT_0120003c.x = DAT_011ada04[i].y - endpoint->y;
                    DAT_0120002c.z = DAT_011ada14[i].x;
                    NiPoint2 tangent;
                    tangent.x = -DAT_0120003c.x;
                    tangent.y = DAT_0120002c.x;
                    tangent.Unitize();
                    DAT_0120002c.y = tangent.x;
                    DAT_0120003c.y = tangent.y;
                    DAT_0120003c.z = endpoint->y;
                    secondary->SetFloat4At(0, DAT_0120002c.x, DAT_0120002c.y, DAT_0120002c.z, DAT_0120002c.w);
                    secondary->SetFloat4At(1, DAT_0120003c.x, DAT_0120003c.y, DAT_0120003c.z, DAT_0120003c.w);
                    handler->Dispatch(widget, arg2, secondary, 1);
                    ++DAT_011ffffc;
                }

                if (DAT_011ada04)
                {
                    Allocator* a = &DAT_011ada00;
                    a->Free(DAT_011ada04);
                    DAT_011ada04 = 0;
                    DAT_011ada0c = 0;
                    DAT_011ada08 = 0;
                }
                if (DAT_011ada14)
                {
                    Allocator* a = &DAT_011ada10;
                    a->Free(DAT_011ada14);
                    DAT_011ada14 = 0;
                    DAT_011ada1c = 0;
                    DAT_011ada18 = 0;
                }
            }
        }
    }

    DAT_01200000 = 0;
    tex44.InitializeFields_00ba3940(assets[1]);
    tex54.InitializeFields_00ba3940(&tex34);
    tex34.InitializeFields_00ba3940(&tex44);

    int frames = 0;
    while (time - previous > step)
    {
        previous = previous + step;
        if (DAT_011fffed)
        {
            ++frames;
            HolderForAccum* node = GetNode(nodes[4]);
            Emitter* pEmitter = emitters[4];
            pEmitter->FUN_00b8a790(0, time, 0.0f, 0.0f, 0.0f);
            pEmitter->FUN_00b8a790(1, DAT_011ffff4, 0.0f, 0.0f, 0.0f);
            pEmitter->FUN_00b8a790(2, DAT_01200024.x, DAT_01200024.y, 0.0f, 0.0f);
            pEmitter->FUN_00b8a790(4, DAT_01200004.x, DAT_01200004.y, DAT_01200004.z, DAT_01200004.w);
            pEmitter->FUN_00b8a790(5, DAT_01200014.x, DAT_01200014.y, DAT_01200014.z, DAT_01200014.w);
            node->SetAccumulatorAt(0, &tex34, 0);
            node->SetAccumulatorAt(1, &tex54, 1);
            node->Dispatch(arg1, arg2, pEmitter, 1);
            DAT_01200000 = 1;
            tex44.InitializeFields_00ba3940(&tex54);
            tex54.InitializeFields_00ba3940(&tex34);
            tex34.InitializeFields_00ba3940(&tex44);
        }
    }

    if (frames % 2 == 0)
    {
        void* renderer = DAT_011f9508;
        ImageSpaceManager* pManager = DAT_011f91ac;
        pManager->ImageSpaceManager_RenderEffect(0x22, renderer, tex54.ImageSpaceTexture_GetRenderedTexture(), tex34.ImageSpaceTexture_GetRenderedTexture(), 0, 1);
    }

    if (tex64.GetTexture())
    {
        tex64.ImageSpaceTexture_ReturnRenderedTexture();
    }
}

extern MemoryManager _g_memoryManager;

extern const float DAT_011add48[];

class ImageSpaceShaderParam
{
  public:
    int unk00;
    int unk04;
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
    char unk54;
    char unk55;
    char unk56;
    char unk57;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;

    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }
    ImageSpaceShaderParam();
    void FUN_00b8ab10(int a1, int a2);
    void CopyParamData(int a1, const float* a2, unsigned int a3);
};

struct TextureManager
{
    int unk00;
    int unk04;
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
    ImageSpaceTexture* unk40;
    ImageSpaceTexture* unk44;
    ImageSpaceTexture* unk48;
    ImageSpaceTexture* unk4C;
    ImageSpaceTexture* unk50;
    ImageSpaceTexture* unk54;
    ImageSpaceTexture* unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    ImageSpaceTexture* unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    ImageSpaceTexture* unk104;
};

struct EffectInitData
{
    int unk00;
    int unk04;
    TextureManager* unk08;
};

// This unit uses the const-reference array API, distinct from the transitive shared array.
namespace waterdisplacement
{
// Unit-local view of NiTPrimitiveArray for the code in namespace waterdisplacement: built on the shared NiTPrimitiveArray, that code does not compile or does not match.
template <class T> class NiTPrimitiveArray_waterdisplacement
{
  public:
    __declspec(noalias) void SetAt(unsigned int uiIndex, const T& element);
};
}

struct ImageSpaceEffect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    waterdisplacement::NiTPrimitiveArray_waterdisplacement<ImageSpaceShaderParam*> m_params;

    void SetTextureArraySize(int count);
    void FUN_00ba3c70(int index, ImageSpaceTexture* tex, ImageSpaceShaderParam* param, int flag);
    void SetEffectParamAt(int index, int a2, int a3);
    void SetArrayEntry(int index, int a2, int a3, int a4, int a5);

    void InitFromEffectInitData(EffectInitData* initData, int unused);
};

// Initializes the effect's texture array and shader parameters from the TextureManager fields in initData.
// @fnv 0x00ba4940
void ImageSpaceEffect::InitFromEffectInitData(EffectInitData* initData, int unused)
{
    SetTextureArraySize(11);

    ImageSpaceShaderParam* param = new ImageSpaceShaderParam();
    param->FUN_00b8ab10(0, 0x18);
    param->unk55 = 0;
    param->CopyParamData(3, DAT_011add48, 0x40);
    ImageSpaceTexture* texture = initData->unk08->unk104;
    FUN_00ba3c70(0, texture, param, 2);
    m_params.SetAt(0, +param);
    SetEffectParamAt(0, 1, 1);

    m_params.SetAt(1, 0);
    SetArrayEntry(1, 2, 3, 0, 0);
    ImageSpaceTexture* texture1 = initData->unk08->unk40;
    FUN_00ba3c70(1, texture1, 0, 2);

    m_params.SetAt(2, 0);
    SetArrayEntry(2, 2, 3, 0, 0);
    ImageSpaceTexture* texture2 = initData->unk08->unk44;
    FUN_00ba3c70(2, texture2, 0, 2);

    m_params.SetAt(3, 0);
    SetArrayEntry(3, 2, 3, 0, 0);
    ImageSpaceTexture* texture3 = initData->unk08->unk48;
    FUN_00ba3c70(3, texture3, 0, 2);

    m_params.SetAt(4, 0);
    SetArrayEntry(4, 2, 3, 0, 0);
    ImageSpaceTexture* texture4 = initData->unk08->unk4C;
    FUN_00ba3c70(4, texture4, 0, 2);

    m_params.SetAt(5, 0);
    SetArrayEntry(5, 2, 3, 0, 0);
    ImageSpaceTexture* texture5 = initData->unk08->unk50;
    FUN_00ba3c70(5, texture5, 0, 2);

    m_params.SetAt(6, 0);
    SetArrayEntry(6, 2, 3, 0, 0);
    ImageSpaceTexture* texture6 = initData->unk08->unk54;
    FUN_00ba3c70(6, texture6, 0, 2);

    m_params.SetAt(7, 0);
    SetArrayEntry(7, 2, 3, 0, 0);
    ImageSpaceTexture* texture7 = initData->unk08->unk58;
    FUN_00ba3c70(7, texture7, 0, 2);

    param = new ImageSpaceShaderParam();
    param->FUN_00b8ab10(0, 0x18);
    param->CopyParamData(3, DAT_011add48, 0x40);
    ImageSpaceTexture* texture8 = initData->unk08->unk104;
    FUN_00ba3c70(8, texture8, param, 0);
    m_params.SetAt(8, +param);
    SetEffectParamAt(8, 2, 1);

    param = new ImageSpaceShaderParam();
    param->FUN_00b8ab10(0, 0x18);
    param->CopyParamData(3, DAT_011add48, 0x40);
    ImageSpaceTexture* texture9 = initData->unk08->unk104;
    FUN_00ba3c70(9, texture9, param, 0);
    m_params.SetAt(9, +param);
    SetEffectParamAt(9, 2, 1);

    param = new ImageSpaceShaderParam();
    param->FUN_00b8ab10(0, 0x18);
    ImageSpaceTexture* texture10 = initData->unk08->unk88;
    FUN_00ba3c70(10, texture10, param, 0);
    m_params.SetAt(10, +param);
    SetEffectParamAt(10, 1, 0);
}

namespace fnv_00ba04c0 {
extern MemoryManager DAT_011f6238;
class ImageSpaceShaderParam : public ImageSpaceEffectParam
{
  public:
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.Allocate(size);
    }
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    char m_54;
    char m_55;
    char m_56;
    char m_57;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    ImageSpaceShaderParam();
    void FUN_00b8ab10(int a, int b);
    void SetBlurClearMode();
};
struct Sub
{
    int f000;
    int f004;
    int f008;
    int f00c;
    int f010;
    int f014;
    int f018;
    int f01c;
    int f020;
    int f024;
    int f028;
    int f02c;
    int f030;
    int f034;
    int f038;
    int f03c;
    int f040;
    int f044;
    int f048;
    int f04c;
    int f050;
    int f054;
    int f058;
    int f05c;
    int f060;
    int f064;
    int f068;
    int f06c;
    int f070;
    int f074;
    int f078;
    int f07c;
    int f080;
    int f084;
    int f088;
    int f08c;
    int f090;
    int f094;
    int f098;
    int f09c;
    int f0a0;
    int f0a4;
    int f0a8;
    int f0ac;
    int f0b0;
    int f0b4;
    int f0b8;
    int f0bc;
    int f0c0;
    int f0c4;
    int f0c8;
    int f0cc;
    int f0d0;
    int f0d4;
    int f0d8;
    int f0dc;
    int f0e0;
    int f0e4;
    int f0e8;
    int f0ec;
    int f0f0;
    int f0f4;
    int f0f8;
    int f0fc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    int f15c;
    int f160;
    int f164;
    int f168;
    int f16c;
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
};
struct Src
{
    int m_00;
    int m_04;
    Sub* m_08;
};
class Arr18
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    __declspec(noalias) void FUN_00ba3aa0(int idx, ImageSpaceEffectParam* const& p);
};
class Arr28
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_00a90180(int n);
};
class ImageSpaceEffect
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    Arr18 m_18;
    Arr28 m_28;
    void SetTextureArraySize(int n);
    void FUN_00ba3c70(int idx, int value, ImageSpaceShaderParam* param, int arg);
    void InitFromConfig(Src* config, int unused);
};
// Initializes nine ImageSpaceShaderParam entries with values from config->m_08 fields f1a4 through f1c4, setting texture array size to 9.
// @fnv 0x00ba04c0
void ImageSpaceEffect::InitFromConfig(Src* config, int unused)
{
    SetTextureArraySize(9);
    m_28.FUN_00a90180(2);
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;
        param->SetBlurClearMode();
        m_18.FUN_00ba3aa0(0, param);
        int value = config->m_08->f1a4;
        FUN_00ba3c70(0, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;
        param->SetBlurClearMode();
        m_18.FUN_00ba3aa0(1, param);
        int value = config->m_08->f1a8;
        FUN_00ba3c70(1, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;

        m_18.FUN_00ba3aa0(2, param);
        int value = config->m_08->f1ac;
        FUN_00ba3c70(2, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;

        m_18.FUN_00ba3aa0(3, param);
        int value = config->m_08->f1b0;
        FUN_00ba3c70(3, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;

        m_18.FUN_00ba3aa0(4, param);
        int value = config->m_08->f1b4;
        FUN_00ba3c70(4, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;

        m_18.FUN_00ba3aa0(5, param);
        int value = config->m_08->f1b8;
        FUN_00ba3c70(5, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;
        param->SetBlurClearMode();
        m_18.FUN_00ba3aa0(6, param);
        int value = config->m_08->f1bc;
        FUN_00ba3c70(6, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;
        param->SetBlurClearMode();
        m_18.FUN_00ba3aa0(7, param);
        int value = config->m_08->f1c0;
        FUN_00ba3c70(7, value, param, 0);
    }
    {
        ImageSpaceShaderParam* param;
        param = new ImageSpaceShaderParam;
        param->FUN_00b8ab10(2, 6);
        param->m_55 = 0;
        param->SetBlurClearMode();
        m_18.FUN_00ba3aa0(8, param);
        int value = config->m_08->f1c4;
        FUN_00ba3c70(8, value, param, 0);
    }
}
}  // namespace fnv_00ba04c0

#include <math.h>
extern float DAT_012003d0;
extern float DAT_012003d4;
extern float DAT_012003d8;
extern float DAT_012003dc;
extern float DAT_011a9490;
extern float DAT_011a9494;
extern float DAT_011a9498;
extern char DAT_012003cc;
extern char DAT_011f94a9;
extern int DAT_011ff9f0;

void __cdecl FUN_00b97fa0(int a, int b);
void __cdecl AddToTwoCounters(int a, int b, int c);

// Image-space effects share this virtual render interface (slot 4).
struct DrawOwner384
{
    virtual void v0();
    // The final argument is a boolean forwarded to each sub-effect.
    virtual void Draw(void* a1, void* a2, void* a3, bool a4);
    virtual void v2();
    virtual void v3();
    virtual void Begin(void* a3);
    virtual void End();
    virtual void v6();
    virtual void Bind(void* a3);
    int unk04;
    int unk08;
    DrawOwner384** m_parts;
    int unk10;
    int unk14;
    int unk18;
    void** m_data;
    void SetEffectParams(int index);
};

// Begins a draw pass, iterates over m_parts to recursively draw, and ends the pass.
// @fnv 0x00ba4d20
void DrawOwner384::Draw(void* apArg1, void* apArg2, void* a3, bool abFlag)
{
    Begin(a3);
    float t = (float)ceil(DAT_012003d0);
    int n = (int)t;
    if (DAT_012003d4 != DAT_011a9490 || DAT_012003d8 != DAT_011a9494 || DAT_012003dc != DAT_011a9498)
    {
        if (DAT_012003cc && DAT_011f94a9 && n < 2)
            n = 2;
    }
    for (int i = 0; i < 8; i++)
    {
        if (i < 1 || i == n)
        {
            SetEffectParams(i);
            Bind(a3);
            m_parts[i]->Draw(apArg1, apArg2, m_data[i], abFlag);
        }
    }
    int iFinalIndex;
    if (DAT_012003d0 < 1.0f)
    {
        SetEffectParams(10);
        Bind(a3);
        m_parts[10]->Draw(apArg1, apArg2, m_data[10], abFlag);
        if (DAT_012003d0 < 1.0f)
        {
            iFinalIndex = 9;
            FUN_00b97fa0(1, 1);
            AddToTwoCounters(6, 7, 0);
        }
        else
        {
            iFinalIndex = 8;
        }
    }
    else
    {
        iFinalIndex = 8;
    }
    SetEffectParams(iFinalIndex);
    Bind(a3);
    m_parts[iFinalIndex]->Draw(apArg1, apArg2, m_data[iFinalIndex], abFlag);
    if (DAT_012003d0 < 1.0f)
    {
        DAT_011ff9f0--;
        FUN_00b97fa0(0, 0);
    }
    End();
}
