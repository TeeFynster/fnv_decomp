// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "../../../../include/NiD3DPass.h"

struct Matrix4_b7dde0
{
    float m11;
    float m12;
    float m13;
    float m14;
    float m21;
    float m22;
    float m23;
    float m24;
    float m31;
    float m32;
    float m33;
    float m34;
    float m41;
    float m42;
    float m43;
    float m44;
};

struct TextureSource_b7dde0
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual unsigned int GetValue()
    {
        return 0;
    }

    unsigned int unk04;
    unsigned int unk08;
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
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int* handle;
};

struct DrawArgument_b7dde0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    TextureSource_b7dde0* source;
};

struct GeometryView_b7dde0
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
    unsigned int unk28;
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
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned char transform;
};

struct TextureStageView_b7dde0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int texture;
    void ApplyPairToState(unsigned int);
};

struct StagePair_b7dde0
{
    NiD3DPass* first;
    NiD3DPass* second;
};

struct BloodShaderView_b7dde0
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
    StagePair_b7dde0* passes;
};

extern int DAT_0126f74c;
class NiGeometry;
extern NiGeometry** DAT_011f91e0;

void __cdecl BSUtilities_GetInverseWorldMatrix(unsigned char*, int, Matrix4_b7dde0*);

struct BloodDraw_b7dde0
{
    void ShadowLightShader_SetupGeometryOpt_WorldViewProj(GeometryView_b7dde0*, unsigned char*);
    void BSShader_SetLightDirection(Matrix4_b7dde0*);
    void* GetTextureByIndex(char*, int);

    void ShadowLightShader_Setup_ADT_Opt(DrawArgument_b7dde0*);
};

// @fnv 0x00b7dde0
// src: COMMUNITY 0x00b7dde0
void BloodDraw_b7dde0::ShadowLightShader_Setup_ADT_Opt(DrawArgument_b7dde0* argument)
{
    TextureSource_b7dde0* source = argument->source;
    BloodShaderView_b7dde0* global = reinterpret_cast<BloodShaderView_b7dde0*>(DAT_0126f74c);
    StagePair_b7dde0* passes = global->passes;
    NiD3DPass* pass = passes->first;

    reinterpret_cast<TextureStageView_b7dde0*>(pass)->texture = *source->handle;

    reinterpret_cast<TextureStageView_b7dde0*>(pass)->ApplyPairToState(source->GetValue());

    global = reinterpret_cast<BloodShaderView_b7dde0*>(DAT_0126f74c);
    passes = global->passes;
    pass = passes->second;

    reinterpret_cast<TextureStageView_b7dde0*>(pass)->texture =
        reinterpret_cast<unsigned int>(GetTextureByIndex(reinterpret_cast<char*>(source), 0));

    reinterpret_cast<TextureStageView_b7dde0*>(pass)->ApplyPairToState(source->GetValue());

    global = reinterpret_cast<BloodShaderView_b7dde0*>(DAT_0126f74c);
    passes = global->passes;
    passes->first->ApplyRenderStateChanges(false);

    global = reinterpret_cast<BloodShaderView_b7dde0*>(DAT_0126f74c);
    passes = global->passes;
    passes->second->ApplyRenderStateChanges(false);

    GeometryView_b7dde0* geom = reinterpret_cast<GeometryView_b7dde0*>(*DAT_011f91e0);
    unsigned char* field = &geom->transform;
    Matrix4_b7dde0 local;

    BSUtilities_GetInverseWorldMatrix(field, 0, &local);
    ShadowLightShader_SetupGeometryOpt_WorldViewProj(geom, field);
    BSShader_SetLightDirection(&local);
}
