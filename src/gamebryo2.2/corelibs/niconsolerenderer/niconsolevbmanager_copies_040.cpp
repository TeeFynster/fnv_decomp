// Distinct original implementations share reconstructed identifiers.
// Keep each matched body under its own address-qualified name.
#define GetEntryPoint GetEntryPoint_fnv_00639b40


// Compile form of the FNV 2.2 vertex-buffer-manager translation unit for the
// MSVC 2008 (Windows, x86) matcher. This unit defines
// NiD3DHLSLVertexShader::GetEntryPoint (0x00E8BF90, 4 bytes:
// "mov eax,[ecx+0x3c]; ret"). The getter returns the HLSL entry-point string
// held in m_pcShaderEntryPoint, which sits at offset 0x3C (60) inside
// NiD3DHLSLVertexShader, i.e. immediately after the 60-byte NiD3DVertexShader
// base object.

#include "../../../../include/NiD3DHLSLVertexShader.h"

// @fnv 0x00639b40
const char* NiD3DHLSLVertexShader::GetEntryPoint()
{
    return m_pcShaderEntryPoint;
}
