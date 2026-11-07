
// src/bsshader/lighting30shader_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/bsshader/lighting30shader_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsshader/lighting30shader_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/lighting30shader.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "lighting30shader_lighting30_factory_types.h"
#include "lighting30shader_packet.h"

struct S00bbe6b0_Mat
{
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};

struct __declspec(align(16)) S00bbe6b0_MatA16 : S00bbe6b0_Mat
{
};

__forceinline S00bbe6b0_Mat* S00bbe6b0_Identity(S00bbe6b0_Mat* m)
{
    m->_12 = m->_13 = m->_14 = m->_21 = m->_23 = m->_24 = m->_31 = m->_32 = m->_34 = m->_41 = m->_42 = m->_43 = 0.0f;
    m->_11 = m->_22 = m->_33 = m->_44 = 1.0f;
    return m;
}

struct S00bbe6b0_Setting
{
    int unk00;
    int unk04;
    bool bEnabled;
};

struct S00bbe6b0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00bbe6b0_Mat world;
};

struct S00bbe6b0_NodeRef
{
    char* base;
};

struct S00bbe6b0_Pair
{
    S00bbe6b0_Node* first;
    S00bbe6b0_Node* second;
};

struct S00bbe6b0_Src
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char count;
    unsigned char unk0a;
    unsigned char unk0b;
    S00bbe6b0_Pair* pair;
};

struct S00bbe6b0_Cam
{
    int unk00;
};

extern S00bbe6b0_Setting* DAT_01201098;
extern S00bbe6b0_Setting* DAT_012010b8;
extern S00bbe6b0_Mat DAT_01201170;
extern float DAT_011f474c;
extern float DAT_011f4750;
extern float DAT_011f4754;
extern S00bbe6b0_Mat DAT_012012b0;

void NiD3DUtility_GetD3DFromNi_(S00bbe6b0_Mat* m, void* out);
S00bbe6b0_Mat* __stdcall D3DXMatrixMultiply_00ee6de0(S00bbe6b0_Mat* out, const S00bbe6b0_Mat* a, const S00bbe6b0_Mat* b);
S00bbe6b0_Mat* __stdcall D3DXMatrixTranspose_00ee6dd4(S00bbe6b0_Mat* out, const S00bbe6b0_Mat* in);
void* FUN_00ec44d0(void* dst, const void* src, unsigned int n);

struct S00bbe6b0_Renderer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    char* m_18;
    void Lighting30Shader_SetupGeometryConstants_ObjToCubemap(S00bbe6b0_Src* src, unsigned int id, int flag, void* out);
};

// @fnv 0x00bbe6b0
// src: COMMUNITY 0x00bbe6b0
void S00bbe6b0_Renderer::Lighting30Shader_SetupGeometryConstants_ObjToCubemap(S00bbe6b0_Src* src, unsigned int id, int flag, void* out)
{
    __declspec(align(16)) S00bbe6b0_Mat mat;
    __declspec(align(16)) S00bbe6b0_Mat world;
    __declspec(align(16)) S00bbe6b0_Mat res;

    if (DAT_01201098->bEnabled)
    {
        S00bbe6b0_Pair* pair = src->pair;
        if (!pair || (src->count > 0 && *((unsigned char*)pair->first + 0xed)) || (id >= 0x1bd && id <= 0x1c3) ||
            (id >= 0x2d8 && id <= 0x2ef))
        {
            mat = *(S00bbe6b0_Mat*)(m_18 + 0x940);
            D3DXMatrixTranspose_00ee6dd4(&mat, &mat);
            DAT_01201170._11 = mat._11;
            DAT_01201170._12 = mat._12;
            DAT_01201170._13 = mat._13;
            DAT_01201170._14 = mat._14;
            DAT_01201170._21 = mat._21;
            DAT_01201170._22 = mat._22;
            DAT_01201170._23 = mat._23;
            DAT_01201170._24 = mat._24;
            DAT_01201170._31 = mat._31;
            DAT_01201170._32 = mat._32;
            DAT_01201170._33 = mat._33;
            DAT_01201170._34 = mat._34;
            DAT_01201170._41 = mat._41;
            DAT_01201170._42 = mat._42;
            DAT_01201170._43 = mat._43;
            DAT_01201170._44 = mat._44;
        }
        else
        {
            if (src->count > 0)
            {
                S00bbe6b0_Identity(&world);
                S00bbe6b0_Identity(&mat);
                if (!flag)
                    NiD3DUtility_GetD3DFromNi_(&world, out);
                world._41 += DAT_011f474c;
                world._42 += DAT_011f4750;
                world._43 += DAT_011f4754;
                D3DXMatrixMultiply_00ee6de0(&res, &world, &(id - 0x1c4 <= 3 ? pair->first : pair->second)->world);
                mat = res;
                D3DXMatrixTranspose_00ee6dd4(&mat, &mat);
                FUN_00ec44d0(&DAT_01201170, &mat, 0x40);
            }
        }
    }
    if (DAT_012010b8->bEnabled && flag)
    {
        S00bbe6b0_Identity(&mat);
        FUN_00ec44d0(&DAT_012012b0, &mat, 0x40);
    }
}
