
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiD3DShaderProgramCreatorAsm.h"
#include "../../../../include/NiD3DVertexShader.h"
#include "../../../../include/NiD3DPixelShader.h"

// Gets the shader code, creates its handle, and stores the handle on the pixel shader.
// @fnv 0x00e97940
bool NiD3DShaderProgramCreatorAsm::Recreate(NiD3DPixelShader* pkPixelShader)
{
    GeometryRelatedType* hShader;
    void* pvCode;
    hShader = static_cast<GeometryRelatedType*>(pkPixelShader->GetCode());
    if (!hShader)
        return false;
    pvCode = CreateHandle(hShader);
    if (!pvCode)
        return false;
    pkPixelShader->SetD3DPixelShader(static_cast<GeometryRelatedType*>(pvCode));
    return true;
}

struct PixelShaderInterface
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual GeometryRelatedType* GetPixelShader();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void* GetShaderData();
    virtual void Slot32();
    virtual void Slot33();
    virtual void SetShaderProgram(void*);
    virtual void* GetShaderProgram();
};
struct PixelShaderCreator
{
    void* CreateVertexShaderChecked(GeometryRelatedType*, void**, void*, int, int, int);
    bool CreateShaderProgram(PixelShaderInterface*);
};
// Gets the pixel shader, creates a program from its data, stores it on the interface and returns whether creation succeeded.
// @fnv 0x00e978d0
bool PixelShaderCreator::CreateShaderProgram(PixelShaderInterface* shader)
{
    GeometryRelatedType* pixel = shader->GetPixelShader();
    if (!pixel)
        return false;
    void* program = shader->GetShaderProgram();
    void* created = CreateVertexShaderChecked(pixel, &program, shader->GetShaderData(), 0, 0, 0);
    if (!created)
        return false;
    shader->SetShaderProgram(created);
    return true;
}

extern void* DAT_0126fa2c;

int NiShaderFactory_ReportError(int, int, const char*, long);

inline NiD3DVertexShader::NiD3DVertexShader(void* pkRenderer) : NiD3DShaderProgram(pkRenderer, 0)
{
    m_bIsInitialized = false;
    m_uiShaderUsage = 0;
    m_pD3DPixelShader = 0;
    m_pD3DVertexShader = 0;
}

struct VertexShaderCreatorAsm
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual bool LoadShaderCode(const char* pcFileName, void*& pvCode, unsigned int& uiCodeSize, void*& pvConstants,
                                void*& pvConstantsExtra, int bRecoverable);

    void* CreateVertexShaderChecked(void* pvCode, void** phDecl, unsigned int uiUsage, void* pvConstants,
                                    void* pvConstantsExtra, bool bSoftwareVP);
    NiD3DVertexShader* NiD3DShaderProgramCreatorAsm_CreateVertexShaderFromFile(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                                    int iArg, void* hDecl, unsigned int uiUsage, bool bSoftwareVP, int bRecoverable);
};

// @fnv 0x00e97980
// src: XBOX_PDB 0x00e97980
NiD3DVertexShader* VertexShaderCreatorAsm::NiD3DShaderProgramCreatorAsm_CreateVertexShaderFromFile(const char* pcFileName, const char* pcShaderName,
                                                        const char* pcEntryPoint, int iArg, void* hDecl,
                                                        unsigned int uiUsage, bool bSoftwareVP, int bRecoverable)
{
    NiD3DVertexShader* pkVertexShader = new NiD3DVertexShader(DAT_0126fa2c);
    if (!pkVertexShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    void* pvConstantsExtra = 0;
    void* pvConstants = 0;
    if (!LoadShaderCode(pcFileName, pvCode, uiCodeSize, pvConstants, pvConstantsExtra, bRecoverable))
    {
        delete pkVertexShader;
        return 0;
    }

    void* hShader = CreateVertexShaderChecked(pvCode, &hDecl, uiUsage, pvConstants, pvConstantsExtra, bSoftwareVP);
    if (!hShader)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreateVertexShader call on %s\n", (long)pcShaderName);
        delete pkVertexShader;
        return 0;
    }

    pkVertexShader->SetName(const_cast<char*>(pcShaderName));
    pkVertexShader->SetShaderProfile(const_cast<char*>(pcFileName));
    pkVertexShader->SetProgramCode(uiCodeSize, pvCode);
    pkVertexShader->SetCreator(reinterpret_cast<NiD3DShaderProgramCreator*>(this));
    pkVertexShader->SetD3DPixelShader(hShader);
    pkVertexShader->SetShaderUsage(uiUsage);
    pkVertexShader->SetVertexDeclaration(hDecl);
    pkVertexShader->SetSoftwareVertexProcessing(bSoftwareVP);
    return pkVertexShader;
}

inline NiD3DPixelShader::NiD3DPixelShader(NiD3DRenderer* pkRenderer)
    : NiD3DShaderProgram(pkRenderer, 2), m_pD3DPixelShader(0)
{}

namespace fnv_00e97c60 {
extern void* DAT_0126fa2c;
int NiShaderFactory_ReportError(int, int, const char*, long);

struct ShaderCreatorAsmStub
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual bool LoadShaderCode(const char* pcFileName, void*& pvCode, unsigned int& uiCodeSize, void*& pvA, void*& pvB,
                                int iFlags);

    GeometryRelatedType* CreateHandle(void* pvCode);
    NiD3DPixelShader* NiD3DShaderProgramCreatorAsm_CreatePixelShaderFromFile(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                                       const char* pcShaderTarget, int iFlags);
};

// Creates a NiD3DPixelShader, loads its shader code, creates the handle, sets name/file/code/creator/handle, and returns it or 0 on failure.
// @fnv 0x00e97c60
// src: XBOX_PDB 0x00e97c60
NiD3DPixelShader* ShaderCreatorAsmStub::NiD3DShaderProgramCreatorAsm_CreatePixelShaderFromFile(const char* pcFileName, const char* pcShaderName,
                                                         const char* pcEntryPoint, const char* pcShaderTarget,
                                                         int iFlags)
{
    NiD3DPixelShader* pkShader = new NiD3DPixelShader(static_cast<NiD3DRenderer*>(DAT_0126fa2c));
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    void* pvB = 0;
    void* pvA = 0;
    if (!LoadShaderCode(pcFileName, pvCode, uiCodeSize, pvA, pvB, iFlags))
    {
        delete pkShader;
        return 0;
    }

    GeometryRelatedType* hShader = CreateHandle(pvCode);
    if (!hShader)
    {
        NiShaderFactory_ReportError(1, iFlags, "Failed CreatePixelShader call on %s\n", (long)pcShaderName);
        delete pkShader;
        return 0;
    }

    pkShader->SetName(const_cast<char*>(pcShaderName));
    pkShader->SetShaderProfile(const_cast<char*>(pcFileName));
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(reinterpret_cast<NiD3DShaderProgramCreator*>(this));
    pkShader->SetD3DPixelShader(hShader);
    return pkShader;
}
}  // namespace fnv_00e97c60

extern void* DAT_0126fa2c;
int NiShaderFactory_ReportError(int, int, const char*, long);
struct Creator
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual bool compile(void*, void*, GeometryRelatedType**, void**, void**, void**, int);
    NiD3DPixelShader* NiD3DShaderProgramCreatorAsm_CreatePixelShaderFromBuffer(void*, void*, void*, int, int, int);
};
// @fnv 0x00e97d80
// src: XBOX_PDB 0x00e97d80
NiD3DPixelShader* Creator::NiD3DShaderProgramCreatorAsm_CreatePixelShaderFromBuffer(void* a, void* b, void* apShaderName, int d, int e, int f)
{
    NiD3DPixelShader* shader = new NiD3DPixelShader(static_cast<NiD3DRenderer*>(DAT_0126fa2c));
    if (!shader)
        return 0;
    GeometryRelatedType* first;
    void* second = 0;
    first = 0;
    void* third = 0;
    void* fourth = 0;
    if (!compile(a, b, &first, &second, &fourth, &third, f))
    {
        delete shader;
        return 0;
    }
    void* pShaderHandle = reinterpret_cast<NiD3DShaderProgramCreatorAsm*>(this)->CreateHandle(first);
    if (!pShaderHandle)
    {
        NiShaderFactory_ReportError(1, f, "Failed CreatePixelShader call on %s\n", (long)apShaderName);
        delete shader;
        return 0;
    }
    shader->SetName(static_cast<char*>(apShaderName));
    shader->SetShaderProfile(0);
    shader->SetProgramCode(reinterpret_cast<unsigned int>(second), first);
    shader->SetCreator(reinterpret_cast<NiD3DShaderProgramCreator*>(this));
    shader->SetD3DPixelShader(static_cast<GeometryRelatedType*>(pShaderHandle));
    return shader;
}

int __cdecl NiShaderFactory_ReportError(int eError, int bRecoverable, const char* pcFormat, ...);

struct VertexShaderCreatorHLSL
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual bool LoadShaderCode(const char* pcFileName, const char* pcEntryPoint, void*& pvCode,
                                unsigned int& uiCodeSize, void*& pvConstants, void*& pvConstantsExtra,
                                int bRecoverable);

    void* CreateVertexShaderChecked(void* pvCode, void** phDecl, unsigned int uiUsage, void* pvConstants,
                                    void* pvConstantsExtra, bool bSoftwareVP);
    NiD3DVertexShader* NiD3DShaderProgramCreatorAsm_CreateVertexShaderFromBuffer(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderName,
                                    const char* pcShaderTarget, const char* pcDefines, void* hDecl,
                                    unsigned int uiUsage, bool bSoftwareVP, int bRecoverable);
};

// Creates a NiD3DVertexShader, loads its shader code, builds the shader handle, and sets its name, code, creator, usage and declaration.
// @fnv 0x00e97af0
// src: XBOX_PDB 0x00e97af0
NiD3DVertexShader* VertexShaderCreatorHLSL::NiD3DShaderProgramCreatorAsm_CreateVertexShaderFromBuffer(const char* pcFileName, const char* pcEntryPoint,
                                                         const char* pcShaderName, const char* pcShaderTarget,
                                                         const char* pcDefines, void* hDecl, unsigned int uiUsage,
                                                         bool bSoftwareVP, int bRecoverable)
{
    NiD3DVertexShader* pkVertexShader = new NiD3DVertexShader(DAT_0126fa2c);
    if (!pkVertexShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    void* pvConstantsExtra = 0;
    void* pvConstants = 0;
    if (!LoadShaderCode(pcFileName, pcEntryPoint, pvCode, uiCodeSize, pvConstants, pvConstantsExtra, bRecoverable))
    {
        delete pkVertexShader;
        return 0;
    }

    void* hShader = CreateVertexShaderChecked(pvCode, &hDecl, uiUsage, pvConstants, pvConstantsExtra, bSoftwareVP);
    if (!hShader)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        delete pkVertexShader;
        return 0;
    }

    pkVertexShader->SetName(const_cast<char*>(pcShaderName));
    pkVertexShader->SetShaderProfile(0);
    pkVertexShader->SetProgramCode(uiCodeSize, pvCode);
    pkVertexShader->SetCreator(reinterpret_cast<NiD3DShaderProgramCreator*>(this));
    pkVertexShader->SetD3DPixelShader(hShader);
    pkVertexShader->SetShaderUsage(uiUsage);
    pkVertexShader->SetVertexDeclaration(hDecl);
    pkVertexShader->SetSoftwareVertexProcessing(bSoftwareVP);
    return pkVertexShader;
}
