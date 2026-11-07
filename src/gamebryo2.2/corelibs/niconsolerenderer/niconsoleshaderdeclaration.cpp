
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiRenderer.h"

extern void* DAT_010ee70c;

struct NiD3DVertexDeclaration
{
    void* m_vtbl;
    void* m_auiShapeKeys[0x2b / 4];
    void* m_pkVertexElements;
    void* m_pkD3DVertexDeclaration;
    char m_flag;
    void Construct();
    char NiD3DShaderDeclaration_Initialize(NiRenderer*, unsigned int, unsigned int);
    virtual void vfn(int);
};

// @fnv 0x00e76700
// src: COMMUNITY 0x00e76700
NiD3DVertexDeclaration* NiDX9ShaderDeclaration_Create(NiRenderer* renderer, unsigned int maxStreamEntries, unsigned int streamCount)
{
    // The backend stream limit is not exposed by the shared NiRenderer base.
    if (streamCount > *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(renderer) + 0x6e8))
        return 0;

    NiD3DVertexDeclaration* pkShaderDeclaration = static_cast<NiD3DVertexDeclaration*>(BSFadeNode::operator new(0x38));
    if (pkShaderDeclaration)
    {
        pkShaderDeclaration->Construct();
        *reinterpret_cast<void**>(pkShaderDeclaration) = &DAT_010ee70c;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x2c) = 0;
        *reinterpret_cast<void**>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x30) = 0;
        *reinterpret_cast<char*>(reinterpret_cast<char*>(pkShaderDeclaration) + 0x34) = 0;
        if (!pkShaderDeclaration->NiD3DShaderDeclaration_Initialize(renderer, maxStreamEntries, streamCount))
        {
            pkShaderDeclaration->vfn(1);
            pkShaderDeclaration = 0;
        }
    }
    else
    {
        pkShaderDeclaration = 0;
    }
    return pkShaderDeclaration;
}
