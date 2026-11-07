
// src/bsshader/imagespaceeffectsunbeams.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffectsunbeams.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiDX9Renderer.h"
#include "../../include/NiRenderTargetGroup.h"
#include "../../include/NiCamera.h"

// Preserve the inline operations used by this unit with the shared declarations.
inline NiPoint3::NiPoint3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{}

inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

extern MemoryManager DAT_011f6238;

struct Node_cls
{
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
    unsigned char unk54;
    unsigned char m_55;
    unsigned char m_56;
    unsigned char unk57;
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
    Node_cls();
    void FUN_00b8ab10(int a1, int a2);
    void FUN_00b8a790(int a1, float f0, float f1, float f2, float f3);
    static void* operator new(unsigned int size) throw()
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    static void operator delete(void* p) throw()
    {}
};

struct Mid_cls
{
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
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int m_d4;
};

struct Ctx_cls
{
    int unk00;
    int unk04;
    Mid_cls* m_08;
};

struct Sub18_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00ba3aa0(int a1, Node_cls** out);
};

struct FUN_00c04aa0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Sub18_cls m_18;
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
    unsigned char unk54;
    unsigned char unk55;
    unsigned char unk56;
    unsigned char unk57;
    float m_58;
    void SetTextureArraySize(int a1);
    void SetArrayEntry(int a1, int a2, int a3, int a4, int a5);
    void FUN_00ba3c70(int a1, int a2, Node_cls* a3, int a4);
    void InitNode(Ctx_cls* a1, int a2);
};

// Creates a Node_cls, configures it, passes it to m_18, then calls SetArrayEntry and FUN_00ba3c70 using a1->m_08->m_d4.
// @fnv 0x00c04aa0
void FUN_00c04aa0_cls::InitNode(Ctx_cls* apCtx, int aiArg)
{
    SetTextureArraySize(1);
    Node_cls* node = new Node_cls();
    node->FUN_00b8ab10(0, 2);
    node->m_55 = 0;
    node->m_56 = 0;
    node->FUN_00b8a790(0, m_58, 0.0f, 0.0f, 0.0f);
    {
        Node_cls* pNodeRef = node;
        m_18.FUN_00ba3aa0(0, &pNodeRef);
    }
    SetArrayEntry(0, 1, 2, 0, 1);
    int iValue = apCtx->m_08->m_d4;
    FUN_00ba3c70(0, iValue, node, 0);
}

struct ConstantMap
{
    void SetReferenceVector(unsigned int reg, float x, float y, float z, float w);
};

extern unsigned char DAT_01202498;
extern float DAT_011f9418;
extern NiDX9Renderer* DAT_011f9508;
extern NiCamera* DAT_011f917c;
extern NiPoint3 DAT_012004f0;

struct FUN_00c04b90_class
{
    char pad_00[0x1c];
    ConstantMap** m_ppConstantMap;
    char pad_20[0x38];
    float m_f58;
    float m_f5c;
    float m_f60;

    bool UpdateCameraConstants(void* param1);
};

// Sets shader constants from the camera matrix and render target width, then returns true.
// @fnv 0x00c04b90
bool FUN_00c04b90_class::UpdateCameraConstants(void* apUnused)
{
    float fVar1 = 0.0f;
    ConstantMap* pkMap = *m_ppConstantMap;

    if (!DAT_01202498)
    {
        float& r = fVar1;
        r = DAT_011f9418;
        if (!(fVar1 > 0.0f))
        {
            fVar1 = 0.0f;
        }
        else
        {
            fVar1 = m_f58;
        }
    }
    else
    {
        fVar1 = m_f58;
    }

    NiRenderTargetGroup* pkRT = DAT_011f9508->GetDefaultRT();
    double d5c = m_f5c;
    unsigned int width = reinterpret_cast<unsigned int>(pkRT->vf36(0));
    float fDiv = (float)(d5c / (float)width);

    pkMap->SetReferenceVector(0, fVar1, fDiv, m_f60, 1.0f);

    NiCamera* pCamera = DAT_011f917c;
    NiPoint3 kCol0(pCamera->m_kWorld.m_Rotate.m_pEntry[0][1], pCamera->m_kWorld.m_Rotate.m_pEntry[1][1], pCamera->m_kWorld.m_Rotate.m_pEntry[2][1]);
    NiPoint3 kCol1(pCamera->m_kWorld.m_Rotate.m_pEntry[0][2], pCamera->m_kWorld.m_Rotate.m_pEntry[1][2], pCamera->m_kWorld.m_Rotate.m_pEntry[2][2]);
    NiPoint3 kVec = DAT_012004f0;
    NiPoint3 negCol0 = -kCol0;

    float fDotY = kVec.Dot(negCol0);
    float fDotX = kVec.Dot(kCol1);

    pkMap->SetReferenceVector(1, fDotX, fDotY, 0.0f, 0.0f);
    return true;
}
