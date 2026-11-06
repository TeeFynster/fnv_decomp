#pragma once

#include "NiD3DShaderDeclaration.h"

class NiRenderer;
struct _D3DVERTEXELEMENT9;

// Gamebryo 2.2 NiDX9ShaderDeclaration (RTTI vftable 0x010ee70c), 0x38 bytes: Create (0x00e76700) allocates 0x38,
// runs the NiD3DShaderDeclaration constructor (0x00e78840), sets the vtable and clears +0x2C, +0x30 and the bool at
// +0x34; the destructor (0x00e78510) frees +0x2C through the memory manager and Releases the D3D declaration at +0x30.
// Units that call it "NiD3DVertexDeclaration" (a class name) mean this class: real Gamebryo's NiD3DVertexDeclaration is
// the typedef LPDIRECT3DVERTEXDECLARATION9, the type of m_hVertexDecl.
class NiDX9ShaderDeclaration : public NiD3DShaderDeclaration
{
public:
    using NiD3DShaderDeclaration::GenerateVertexParameters;

    static NiDX9ShaderDeclaration* Create(NiRenderer* pkRenderer, unsigned int uiMaxStreamEntryCount,
                                          unsigned int uiStreamCount); // 0x00e76700

    virtual bool GenerateVertexParameters(IDirect3DVertexDeclaration9** declaration, unsigned int* streamCount);

    _D3DVERTEXELEMENT9* m_pkElements;           // +0x2C
    IDirect3DVertexDeclaration9* m_hVertexDecl; // +0x30
    bool m_bDeclarationValid;                   // +0x34
};
