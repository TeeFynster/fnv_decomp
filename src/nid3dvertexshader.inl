// @fnv 0x00be0b30
NiD3DVertexShader::NiD3DVertexShader(GraphicsRenderer *const pkRenderer) :
    NiD3DShaderProgram(pkRenderer, false)
{
    m_bIsInitialized = false;
    m_uiShaderUsage = 0;
    m_pD3DPixelShader = 0;
    m_pD3DVertexShader = 0;
}

// @fnv 0x00be0b60
const NiRTTI* NiD3DVertexShader::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x00be0bb0
void NiD3DVertexShader::SetD3DPixelShader(RenderableGeometry *const hShader)
{
    m_pD3DPixelShader = hShader;
}

// @fnv 0x00be0bc0
COMUnknownInterface* NiD3DVertexShader::GetShaderDeclaration() const
{
    return m_pD3DVertexShader;
}