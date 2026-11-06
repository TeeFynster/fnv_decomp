#pragma once

#include "NiShaderDeclaration.h"
#include "NiSkinPartition.h"

class GraphicsRenderer;
class VertexDeclarationLayout;
class Direct3DDeviceInterface;
class NiD3DShaderDeclaration__ShaderRegisterStream;
class NiGeometryData;
class NiSkinInstance;
class NiVBChip;
struct IDirect3DVertexDeclaration9;

class NiD3DShaderDeclaration : public NiShaderDeclaration
{
public:
    class ShaderStreamInfo;

    NiD3DShaderDeclaration();
    virtual ~NiD3DShaderDeclaration();
    NiD3DShaderDeclaration& operator=(const NiD3DShaderDeclaration&);

    virtual bool SetEntry(unsigned int, unsigned int, ShaderParameter,
                          ShaderParameterType, unsigned int);
    virtual bool RemoveEntry(unsigned int, unsigned int);
    virtual bool SetEntryAlt(unsigned int, unsigned int, unsigned int,
                             ShaderParameter, ShaderParameterType, ShaderParameterUsage,
                             unsigned int, ShaderParameterTesselator);
    virtual void SetFloatValues(unsigned int, unsigned int, float*);
    virtual void ClearAllEntries(unsigned int);
    virtual unsigned int GetVertexStride(unsigned int);
    virtual void SetSoftwareVertexProcessing();
    virtual bool GetSoftwareVertexProcessing();
    virtual NiVBChip* CreateVertexBufferChip(NiGeometryData*, NiSkinInstance*,
                                             NiSkinPartition::Partition*, unsigned short,
                                             NiVBChip*, unsigned int, void*);
    virtual bool GenerateVertexParameters(IDirect3DVertexDeclaration9**, unsigned int*);
    virtual IDirect3DVertexDeclaration9* GetD3DDeclaration();

    bool SetEntryAlt(unsigned int, unsigned int, unsigned int, unsigned int,
                     unsigned int, unsigned int, unsigned int, unsigned int);
    void Finalize();

    GraphicsRenderer* m_pOwnerShader;
    VertexDeclarationLayout* m_pShaderStreamInfo;
    Direct3DDeviceInterface* m_pD3DDevice;
    unsigned int m_uiVertexElementCount;
    unsigned int m_uiBufferStride;
    unsigned int m_uiShaderRegisterCount;
    unsigned int m_uiRegisterStreamCount;
    NiD3DShaderDeclaration__ShaderRegisterStream* m_pShaderRegisterStream;
    bool m_bHasChanges;
    unsigned char layoutPadding29[3];
};
