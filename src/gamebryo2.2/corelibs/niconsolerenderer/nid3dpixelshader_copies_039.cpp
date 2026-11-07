
// Provisional build file (plan B2): exact copies of the nid3dpixelshader recipe for other original addresses.
// The original identities of these functions are unknown.
//
// Compile form of nid3dpixelshader.inl: MSVC 2008 cl does not accept the
// .inl extension as a source file, so this identical unit is compiled as .cpp
// by the matcher. Content is the authored body of the .inl source of record.

#include "../../../../include/NiD3DPixelShader.h"

// @fnv 0x0086cf00
void NiD3DPixelShader::SetD3DPixelShader(GeometryRelatedType* const pixelShader)
{
    m_pD3DPixelShader = pixelShader;
}

// Keep the duplicate entry point's pointer argument on the stack under __fastcall.
struct PixelShaderArgument
{
    GeometryRelatedType* pixelShader;
};

// @fnv 0x00c3cf40
// src: XBOX_PDB 0x00c3cf40
void __fastcall QueuedFileEntry_SetFileEntry(NiD3DPixelShader* shader, PixelShaderArgument argument)
{
    shader->m_pD3DPixelShader = argument.pixelShader;
}
