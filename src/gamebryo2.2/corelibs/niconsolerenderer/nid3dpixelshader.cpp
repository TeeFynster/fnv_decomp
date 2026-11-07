
//
// Compile form of nid3dpixelshader.inl: MSVC 2008 cl does not accept the
// .inl extension as a source file, so this identical unit is compiled as .cpp
// by the matcher. Content is the authored body of the .inl source of record.

#include "../../../../include/NiD3DPixelShader.h"

// @fnv 0x00BE0B20
void NiD3DPixelShader::SetD3DPixelShader(GeometryRelatedType* const pixelShader)
{
    m_pD3DPixelShader = pixelShader;
}

void __cdecl NiD3DShaderProgramFactory_RecreatePixelShader(NiD3DPixelShader*);

// @fnv 0x00e898d0
void __thiscall NiD3DPixelShader::BuildVertexShader()
{
    NiD3DShaderProgramFactory_RecreatePixelShader(this);
}

// ---- stand-ins for identities not defined in this unit ----
struct FakeShader;
struct FakeRenderer
{
    void PurgeShader(FakeShader* shader);
};

// @fnv 0x00e898c0
void NiD3DPixelShader::UnloadShader()
{
    if (m_pD3DPixelShader)
    {
        reinterpret_cast<FakeRenderer*>(m_pShaderObject)->PurgeShader(reinterpret_cast<FakeShader*>(this));
    }
}
