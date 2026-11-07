// gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderstate.cpp: ShaderPassRenderer, RenderState (3 functions)

#include "niconsolerenderstate_decls.h"
#include "../../../../include/NiD3DDefaultShader.h"

// @fnv 0x00e69460
unsigned int ShaderPassRenderer::Create(unsigned int useEx)
{
    unsigned int result = 0;
    if (!DAT_0126f0d8)
    {
        if (!InitD3D9CreateFunctions())
            goto failure;
        if (DAT_0126f0e0 && (unsigned char)useEx)
        {
            DepthDevice* device;
            DAT_0126f0e0(32, &device);
            if (!device)
            {
                NiD3DDefaultShader::SetShaderName("Create D3D9Ex instance...FAILED\n");
                result = ~0u;
            }
            else
            {
                DAT_0126f0d0 = true;
                DAT_0126f0d8 = device;
                NiD3DDefaultShader::SetShaderName("Create D3D9Ex instance...SUCCESSFUL\n");
            }
        }
        if (!DAT_0126f0d8)
        {
            DAT_0126f0d8 = DAT_0126f0dc(32);
            if (!DAT_0126f0d8)
            {
            failure:
                NiD3DDefaultShader::SetShaderName("Create D3D9 instance...FAILED\n");
                return ~0u;
            }
            NiD3DDefaultShader::SetShaderName("Create D3D9 instance...SUCCESSFUL\n");
        }
    }
    return result;
}

struct FUN_00a77960_shell
{
    int field0;
    int field4;
    int __thiscall IsField4InRange();
};

// @fnv 0x00a77960
int __thiscall FUN_00a77960_shell::IsField4InRange()
{
    if (field4 >= 4 && field4 <= 6)
        return 1;
    return 0;
}

struct RenderDevice
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void SetState(unsigned int, unsigned int, unsigned int, unsigned int);
};
struct ExtraObject
{
    int unk00, unk04, active;
};
struct Descriptor
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned short unk18 : 1;
    unsigned short kind : 3;
    unsigned short unk1a;
    int unk1c;
    ExtraObject** extra;
};
struct RenderModes
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned short unk18 : 3;
    unsigned short enabled : 1;
    unsigned short mode : 2;
};
struct RenderState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    RenderDevice* device;
    void* invalid;
    void* cached;
    bool oldEnabled;
    bool enabled;
    unsigned short unk2e;
    unsigned int kind;
    unsigned int mode;
    void NiDX9LightManager_UpdateLights(void*);
    void ApplyRenderModes(void*, Descriptor*, RenderModes*);
};
// @fnv 0x00e8bb70
void RenderState::ApplyRenderModes(void* resource, Descriptor* desc, RenderModes* modes)
{
    kind = desc->kind;
    ExtraObject* extra = *desc->extra;
    if (extra && extra->active && kind == 0)
    {
        device->SetState(137, 0, 0, 0);
        return;
    }
    unsigned int newMode = 0;
    unsigned int lighting = 1;
    if (modes)
    {
        newMode = modes->mode;
        lighting = modes->enabled;
    }
    bool bLighting = true;
    if (lighting == 0)
    {
        switch (newMode)
        {
        case 0:
        case 2:
            enabled = false;
            if (mode == 1)
            {
                device->SetState(148, 0, 0, 0);
                device->SetState(147, 0, 0, 0);
                device->SetState(145, 0, 0, 0);
                mode = 0;
            }
            break;
        case 1:
            bLighting = false;
            break;
        default:
            bLighting = false;
            break;
        }
    }
    else
    {
        if (newMode != mode)
        {
            switch (newMode)
            {
            case 0:
                device->SetState(148, 0, 0, 0);
                device->SetState(147, 0, 0, 0);
                device->SetState(145, 0, 0, 0);
                break;
            case 1:
                device->SetState(148, 1, 0, 0);
                device->SetState(147, 0, 0, 0);
                device->SetState(145, 0, 0, 0);
                break;
            case 2:
                device->SetState(148, 0, 0, 0);
                device->SetState(147, 1, 0, 0);
                device->SetState(145, 1, 0, 0);
                break;
            }
            mode = newMode;
        }
        enabled = true;
    }
    if (bLighting)
    {
        device->SetState(137, 1, 0, 0);
        if (cached == invalid || resource != cached || enabled != oldEnabled)
        {
            NiDX9LightManager_UpdateLights(resource);
            cached = resource;
            oldEnabled = enabled;
        }
    }
    else
    {
        device->SetState(137, 0, 0, 0);
    }
}
