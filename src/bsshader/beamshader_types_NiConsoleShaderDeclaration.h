// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NICONSOLESHADERDECLARATION_H
#define FNV_NICONSOLESHADERDECLARATION_H

#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiShaderDeclaration.h"
#include "NiObject.h"
class Direct3DDeviceInterface;
class COMUnknownInterface;
class NiD3DShaderDeclaration__ShaderRegisterStream;
class NiRenderer;
class GraphicsRenderer;
class NiD3DVertexDeclaration;
class VertexDeclarationLayout;
class _D3DVERTEXELEMENT9;
#pragma pack(push, 4)
class NiD3DVertexDeclaration : public NiD3DShaderDeclaration
{
  public:
    // base NiD3DShaderDeclaration at +0x0, size 44
    _D3DVERTEXELEMENT9* m_pkVertexElements;         // +0x2C, 4 bytes
    COMUnknownInterface* m_pkD3DVertexDeclaration;  // +0x30, 4 bytes
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
    // void __cdecl NiD3DVertexDeclaration::*()
    // NiD3DVertexDeclaration* __cdecl NiD3DVertexDeclaration::*(NiRenderer*, unsigned int, unsigned int)
    // SetEntry
    // bool __cdecl NiD3DVertexDeclaration::*(unsigned int, unsigned int)
    // bool __cdecl NiD3DVertexDeclaration::*(unsigned int)
    // unsigned int __cdecl NiD3DVertexDeclaration::*()
    // NiVBChip* __cdecl NiD3DVertexDeclaration::*(NiGeometryData*, NiSkinInstance*, NiSkinPartition::Partition*, unsigned short, NiVBChip*, unsigned int, void*)
    // bool __cdecl NiD3DVertexDeclaration::*(COMUnknownInterface*&, unsigned int&)
    // unsigned int __cdecl NiD3DVertexDeclaration::*(unsigned int)
    // COMUnknownInterface* __cdecl NiD3DVertexDeclaration::*()
    // bool __cdecl NiD3DVertexDeclaration::*(_D3DDECLUSAGE, unsigned int, NiShaderDeclaration::ShaderParameter&, NiShaderDeclaration::ShaderParameterType&, NiShaderDeclaration::ShaderParameterUsage&, NiD3DShaderDeclaration::ShaderParameterTesselator&)
    // NiD3DVertexDeclaration
    // NiD3DVertexDeclaration& __cdecl NiD3DVertexDeclaration::*(const NiD3DVertexDeclaration&)
    // void __cdecl NiD3DVertexDeclaration::*()
};
#pragma pack(pop)
#endif
