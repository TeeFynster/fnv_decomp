// the shared NiTArray first: NiNode.h then takes it (its own copy is only for units without one)
#include "../../../include/NiColorA.h"
#include "../../../include/NiTArray.h"

// moon_ctx_variant.cpp: context variant of src/fallout_shared/sky/moon.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "../../../include/NiPoint3.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BSShaderManager.h"
#include "../../../include/Moon.h"
#include "../../../include/SkyObject.h"
#include "../../../include/SkyShaderProperty.h"
#include "../../../include/NiAlphaProperty.h"
#include "../../../include/NiTexture.h"
#include "../../../include/Sky.h"

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
// Hide the inherited unsized delete to preserve this path's sized exception cleanup.
class MoonSceneNodeAllocation : public NiNode
{
  public:
    MoonSceneNodeAllocation(unsigned short);
    static void operator delete(void*, unsigned int);
};
// This initialization path also uses sized cleanup when a shape constructor throws.
class MoonSceneShapeAllocation : public NiTriShape
{
  public:
    MoonSceneShapeAllocation(unsigned short, NiPoint3*, NiPoint3*, void*, NiPoint2*, unsigned short,
                             unsigned int, unsigned short, unsigned short*);
    static void operator delete(void*, unsigned int);
};
// Preserve the out-of-line UV constructors used by this initialization path.
class MoonTextureCoordinate
{
  public:
    float x, y;
    MoonTextureCoordinate();
    MoonTextureCoordinate(float, float);
};
class FUN_00baf3c0
{
  public:
    FUN_00baf3c0();
    unsigned int shaderType;
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
    unsigned char unk38, unk39, unk3a, unk3b;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned char unk44, unk45, unk46, unk47;
    unsigned int unk48;
    unsigned char flags[12];
    unsigned int unk58;
    unsigned char unk5c, unk5d, unk5e, unk5f;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned char unk6c, unk6d, unk6e, unk6f;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned char unk88, unk89, unk8a, unk8b;
    unsigned int unk8c;
    unsigned int shadowType;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned char unkb0, unkb1, unkb2, unkb3;
    unsigned int unkb4;
    void AddProperties(NiTriShape*, unsigned int);
};
class B006815c0
{
  public:
    float m[3][3];
    B006815c0();
    void FUN_00524ac0(float);
};
extern void* __cdecl NiMalloc(unsigned int);
extern "C" void __cdecl FUN_00b57e30(NiNode*, int, int);
// @fnv 0x00634e20
void Moon::Initialize(NiNode* root, const char* name)
{
    AutoMemContext kContext((MEM_CONTEXT)33, true,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Moon.cpp", 102);
    NiPoint3* aMoonNormals = 0;
    NiPoint3* moonVertices4 = 0;
    NiPoint3* shadowNormals9 = 0;
    NiPoint3* k = 0;
    MoonTextureCoordinate* moonUVX = 0;
    MoonTextureCoordinate* kc = 0;
    NiColorA* moonColors4 = 0;
    NiColorA* shadowColors_ = 0;
    unsigned short* moonIndices4 = 0;
    unsigned short* shadowIndicesA = 0;
    SkyObject::Initialize(root);
    aMoonNormals = new NiPoint3[4];
    moonVertices4 = new NiPoint3[4];
    shadowNormals9 = new NiPoint3[4];
    k = new NiPoint3[4];
    moonVertices4[0] = NiPoint3(-1.0 * iSize, (float)iSize, 0.0f);
    moonVertices4[1] = NiPoint3(-1.0 * iSize, -1.0 * iSize, 0.0f);
    moonVertices4[2] = NiPoint3((float)iSize, (float)iSize, 0.0f);
    moonVertices4[3] = NiPoint3((float)iSize, -1.0 * iSize, 0.0f);
    k[0] = NiPoint3(-1.0 * iSize, (float)iSize, 0.0f);
    k[1] = NiPoint3(-1.0 * iSize, -1.0 * iSize, 0.0f);
    k[2] = NiPoint3((float)iSize, (float)iSize, 0.0f);
    k[3] = NiPoint3((float)iSize, -1.0 * iSize, 0.0f);
    moonUVX = new MoonTextureCoordinate[4];
    kc = new MoonTextureCoordinate[4];
    moonUVX[0] = MoonTextureCoordinate(0, 0);
    moonUVX[1] = MoonTextureCoordinate(0, 1);
    moonUVX[2] = MoonTextureCoordinate(1, 0);
    moonUVX[3] = MoonTextureCoordinate(1, 1);
    kc[0] = MoonTextureCoordinate(0, 0);
    kc[1] = MoonTextureCoordinate(0, 1);
    kc[2] = MoonTextureCoordinate(1, 0);
    kc[3] = MoonTextureCoordinate(1, 1);
    moonColors4 = new NiColorA[4];
    shadowColors_ = new NiColorA[4];
    NiColorA iRed(1, 0, 0, 1);
    moonColors4[0] = iRed;
    moonColors4[1] = iRed;
    moonColors4[2] = iRed;
    moonColors4[3] = iRed;
    shadowColors_[0] = iRed;
    shadowColors_[1] = iRed;
    shadowColors_[2] = iRed;
    shadowColors_[3] = iRed;
    moonIndices4 = (unsigned short*)NiMalloc(12);
    shadowIndicesA = (unsigned short*)NiMalloc(12);
    moonIndices4[0] = 0;
    moonIndices4[1] = 1;
    moonIndices4[2] = 2;
    moonIndices4[3] = 2;
    moonIndices4[4] = 1;
    moonIndices4[5] = 3;
    shadowIndicesA[0] = 0;
    shadowIndicesA[1] = 1;
    shadowIndicesA[2] = 2;
    shadowIndicesA[3] = 2;
    shadowIndicesA[4] = 1;
    shadowIndicesA[5] = 3;
    m_pMoonShape = new MoonSceneShapeAllocation(4, moonVertices4, aMoonNormals, moonColors4, (NiPoint2*)moonUVX, 1, 0, 2,
                                  moonIndices4);
    ((NiTriShape*)m_pMoonShape)->NiAVObject_SetSelectiveUpdate(true);
    m_pMoonShadowShape =
        new MoonSceneShapeAllocation(4, k, shadowNormals9, shadowColors_, (NiPoint2*)kc, 1, 0, 2, shadowIndicesA);
    ((NiTriShape*)m_pMoonShadowShape)->NiAVObject_SetSelectiveUpdate(true);
    {
        NiPointer<NiAlphaProperty> alpha(new NiAlphaProperty);
        ((NiAlphaProperty*)alpha)->NiAlphaProperty_SetAlphaBlending(true);
        ((NiAlphaProperty*)alpha)->NiAlphaProperty_SetSrcBlendMode(6);
        ((NiAlphaProperty*)alpha)->NiAlphaProperty_SetDestBlendMode(0);
        ((NiAlphaProperty*)alpha)->NiAlphaProperty_SetNoSorter(true);
        ((NiTriShape*)m_pMoonShape)->AttachProperty(alpha);
        alpha = 0;
    }
    FUN_00baf3c0 kB;
    kB.shaderType = 6;
    kB.shadowType = 6;
    kB.AddProperties(m_pMoonShape, 1);
    kB.shadowType = 7;
    kB.AddProperties(m_pMoonShadowShape, 1);
    if (Sky::GetInstance()->Sky_GetMode() == 3 || Sky::GetInstance()->Sky_GetMode() == 2)
    {
        SkyShaderProperty* texture = ((NiTriShape*)m_pMoonShadowShape)->GetProperty(3);
        NiPointer<NiTexture> loaded(0);
        BSShaderManager::GetTexture("Textures\\Sky\\MoonShadow.dds", true, loaded, true, false);
        NiTexture* shader = loaded;
        if (shader)
            texture->SetTexture(shader);
        ((NiTriShape*)m_pMoonShadowShape)->NiAVObject_SetDisplayObject(shader != 0);
        m_eUpdateStatus = US_INITIALIZE;
    }
    m_pMoonNode = new MoonSceneNodeAllocation(0);
    m_pMoonShadowNode = new MoonSceneNodeAllocation(0);
    ((NiNode*)m_pMoonNode)->NiAVObject_SetSelectiveUpdate(true);
    ((NiNode*)m_pMoonShadowNode)->NiAVObject_SetSelectiveUpdate(true);
    ((NiNode*)m_pMoonNode)->AttachChildInAvailableSlot((NiAVObject*)(NiTriShape*)m_pMoonShape, true);
    ((NiNode*)m_pMoonShadowNode)->AttachChildInAvailableSlot((NiAVObject*)(NiTriShape*)m_pMoonShadowShape, true);
    ((NiNode*)m_pRootNode)->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)m_pMoonShadowNode, true);
    ((NiNode*)m_pRootNode)->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)m_pMoonNode, true);
    {
        B006815c0 rotation;
        rotation.FUN_00524ac0(-1.5707963705062866f);
        ((NiTriShape*)m_pMoonShape)->NiAVObject_SetTranslate_004bc1f0(0, 512, 0);
        ((NiTriShape*)m_pMoonShape)->SetRotate_0043fa80(&rotation);
        ((NiTriShape*)m_pMoonShadowShape)->NiAVObject_SetTranslate_004bc1f0(0, 512, 0);
        ((NiTriShape*)m_pMoonShadowShape)->SetRotate_0043fa80(&rotation);
        FUN_00b57e30(m_pRootNode, 0, 0);
    }
}
