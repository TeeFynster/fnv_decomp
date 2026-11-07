#include "../../../../include/NiD3DShaderProgramCreatorHLSL.h"
#include "../../../../include/NiD3DPixelShader.h"
#include "../../../../include/NiD3DShaderProgram.h"
#include "../../../../include/NiD3DVertexShader.h"
#include "../../../../include/NiD3DHLSLVertexShader.h"
#include "../../../../include/NiD3DHLSLPixelShader.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


extern "C" void __cdecl FUN_00e89970();
extern void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

// @fnv 0x00be0af0
void* __thiscall NiD3DPixelShader::DestroyPixelShader(unsigned int flags)
{
    NiD3DPixelShader* p = this;
    FUN_00e89970();
    if (flags & 1)
        __Dummy_00b6fef0(p, 0x30);
    return p;
}


// @fnv 0x00be0bd0
// src: XBOX_PDB 0x00be0bd0
void NiD3DVertexShader::SetVertexDeclaration_00be0bd0(COMUnknownInterface* hDecl)
{
    m_pD3DVertexShader = hDecl;
}


// @fnv 0x00be0bf0
// src: XBOX_PDB 0x00be0bf0
void NiD3DVertexShader::SetSoftwareVertexProcessing_00be0bf0(bool bSoftwareVP)
{
    m_bIsInitialized = bSoftwareVP;
}

struct VTableObj
{
    int m_uiX;
    int m_uiY;
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void Call(int a, int b);
};

extern "C" void* __cdecl hkMemoryRouter_getInstance();

struct FUN_00c7b0f0_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void UpdateState_00c7b0f0();
};

// @fnv 0x00c7b0f0
// src: GUESS 0x00c7b0f0 (confidence: low)
void FUN_00c7b0f0_shell::UpdateState_00c7b0f0()
{
    void* p = hkMemoryRouter_getInstance();
    VTableObj* pTarget = *(VTableObj**)((char*)p + 0x10);
    m_kPointB = 0;
    unsigned int uiFlags = m_iThirdValue;
    if (!(uiFlags & 0x80000000))
    {
        int size = (uiFlags & 0x3fffffff) * 4;
        pTarget->Call(m_kPointA, size);
    }
    m_kPointA = 0;
    m_iThirdValue = 0x80000000;
}

extern "C" void* g_0126fa40;

// @fnv 0x00e95cc0
// src: COMMUNITY 0x00e95cc0
void* __cdecl NiD3DHLSLPixelShader_GetRTTI()
{
    return &g_0126fa40;
}

extern const void* g_0126fa48;

// @fnv 0x00e95df0
// src: COMMUNITY 0x00e95df0
const void* __cdecl NiD3DHLSLVertexShader_GetRTTI()
{
    return &g_0126fa48;
}

extern void(__cdecl* DAT_fdf3f0)();

// @fnv 0x00ee6e2e
// src: COMMUNITY 0x00ee6e2e
void __cdecl D3DXGetVertexShaderProfile()
{
    return DAT_fdf3f0();
}


// @fnv 0x00eea540
// src: XBOX_PDB 0x00eea540
void __thiscall NiD3DShaderProgram::SetCreator_00eea540(NiD3DShaderProgramCreator* pkCreator)
{
    m_pCreator = pkCreator;
}

extern "C" void __cdecl operator delete(void*, unsigned int);
void __cdecl RemoveDeviceAndClearShader();


// Calls FUN_00e89b70, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00be0b70
void* __fastcall DestroyVertexShader(NiD3DVertexShader* shader, void*, unsigned int flags)
{
    RemoveDeviceAndClearShader();
    if (flags & 1)
        operator delete(shader, 0x3c);
    return shader;
}

extern "C" void __cdecl operator delete(void*, unsigned int);

// Calls FUN_00e96c90, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00e95cd0
void* __thiscall NiD3DHLSLPixelShader::FUN_00e95cd0(unsigned int flags)
{
    UpdateState_00e96c90();
    if (flags & 1)
        ::operator delete(this, 0x3c);
    return this;
}


// @fnv 0x00be0ab0
void __thiscall NiD3DShaderProgram::SetShaderCode(unsigned int uiSize, void* pvCode)
{
    m_uiProgramCodeSize = uiSize;
    m_pProgramCode = pvCode;
}

void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFreeAlias(void*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
extern "C" unsigned int strlen(const char*);
// Frees the stored string at offset 0x30 and replaces it with a newly allocated copy of pcEntryPoint, or null if empty.
// @fnv 0x00e95cf0
// src: GAMEBRYO_SRC 0x00e95cf0
void NiD3DHLSLPixelShader::SetEntryPoint_00e95cf0(const char* pcEntryPoint)
{
    char* pcNewEntryPoint;
    unsigned int uiLen;
    if (m_pcShaderEntryPoint != pcEntryPoint)
    {
        NiFreeAlias(const_cast<char*>(m_pcShaderEntryPoint));
        if (pcEntryPoint && pcEntryPoint[0] != 0)
        {
            uiLen = strlen(pcEntryPoint) + 1;
            pcNewEntryPoint = (char*)NiMalloc(uiLen);
            strcpy_s(pcNewEntryPoint, uiLen, pcEntryPoint);
            m_pcShaderEntryPoint = pcNewEntryPoint;
        }
        else
        {
            m_pcShaderEntryPoint = 0;
        }
    }
}

void* _NiMalloc(unsigned int);
void _NiFreeAlias(void*);
// Frees the stored shader target string and replaces it with a newly allocated copy of pcShaderTarget, unless it is null, empty, or already stored.
// @fnv 0x00e95d60
// src: GAMEBRYO_SRC 0x00e95d60
void __thiscall NiD3DHLSLPixelShader::SetShaderTarget(const char* pcShaderTarget)
{
    char* pcNewShaderTarget;
    unsigned int uiLen;
    if (m_pcShaderProfile == pcShaderTarget)
        return;
    _NiFreeAlias(const_cast<char*>(m_pcShaderProfile));
    if (!pcShaderTarget)
        return;
    if (*pcShaderTarget == 0)
        return;
    uiLen = (unsigned int)strlen(pcShaderTarget) + 1;
    pcNewShaderTarget = (char*)_NiMalloc(uiLen);
    strcpy_s(pcNewShaderTarget, uiLen, pcShaderTarget);
    m_pcShaderProfile = pcNewShaderTarget;
}

struct ID3DXConstantTable
{
    virtual void __stdcall QueryInterface();
    virtual void __stdcall AddRef();
    virtual void __stdcall Release();
};
// Releases the current table and stores pkTable, calling AddRef on it when it differs from the stored one.
// @fnv 0x00e95dc0
void __thiscall NiD3DHLSLPixelShader::AssignTable(ID3DXConstantTable* pkTable)
{
    if (m_pShaderConstantTable != pkTable)
    {
        if (m_pShaderConstantTable)
            m_pShaderConstantTable->Release();
        m_pShaderConstantTable = pkTable;
        if (pkTable)
            pkTable->AddRef();
    }
}

void __cdecl _delete(void*, unsigned int);
// @fnv 0x00e95e00
void* __thiscall NiD3DHLSLVertexShader::DestroyVertexShader(unsigned int flags)
{
    SetVtableAndProcessState_00e971d0();
    if (flags & 1)
        _delete(this, 0x48);
    return this;
}

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFreeAlias(void*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
// Replaces the stored entry-point string with a copy of pcEntryPoint, freeing the old one and clearing it when the input is null or empty.
// @fnv 0x00e95e20
// src: XBOX_PDB 0x00e95e20
void __thiscall NiD3DHLSLVertexShader::SetEntryPoint_00e95e20(const char* pcEntryPoint)
{
    char* pcNewEntryPoint;
    unsigned int uiLen;
    if (m_pcShaderEntryPoint != pcEntryPoint)
    {
        _NiFreeAlias(const_cast<char*>(m_pcShaderEntryPoint));
        if (pcEntryPoint && *pcEntryPoint)
        {
            uiLen = strlen(pcEntryPoint);
            pcNewEntryPoint = (char*)_NiMalloc(uiLen + 1);
            _strcpy_s(pcNewEntryPoint, uiLen + 1, pcEntryPoint);
            m_pcShaderEntryPoint = pcNewEntryPoint;
        }
        else
        {
            m_pcShaderEntryPoint = 0;
        }
    }
}

void* __cdecl _NiMalloc(unsigned int);
void __cdecl _NiFreeAlias(void*);
int __cdecl _strcpy_s(char*, unsigned int, const char*);
// Frees the stored shader target string and, if a non-empty target is given, allocates and copies it into the field.
// @fnv 0x00e95e80
// src: XBOX_PDB 0x00e95e80
void __thiscall NiD3DHLSLVertexShader::SetShaderTarget_00e95e80(const char* pcShaderTarget)
{
    if (m_pcShaderProfile != pcShaderTarget)
    {
        _NiFreeAlias(m_pcShaderProfile);
        if (pcShaderTarget && pcShaderTarget[0] != 0)
        {
            char* pcNewShaderTarget;
            unsigned int uiLen;
            uiLen = strlen(pcShaderTarget) + 1;
            pcNewShaderTarget = (char*)_NiMalloc(uiLen);
            _strcpy_s(pcNewShaderTarget, uiLen, pcShaderTarget);
            m_pcShaderProfile = pcNewShaderTarget;
        }
    }
}

// Replaces the COM-style table pointer at offset 0x44, releasing the old one and AddRef-ing the new one when it differs.
// @fnv 0x00e95ef0
void NiD3DHLSLVertexShader::SetShaderTable(ID3DXConstantTable* pkTable)
{
    ID3DXConstantTable* pkOld = m_pShaderConstantTable;
    if (pkOld != pkTable)
    {
        if (pkOld)
            pkOld->Release();
        m_pShaderConstantTable = pkTable;
        if (pkTable)
            pkTable->AddRef();
    }
}

struct ID3DXBuffer
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void* __stdcall GetBufferPointer();
    virtual unsigned long __stdcall GetBufferSize();
};
extern "C" long __stdcall D3DXCompileShader(const char* pSrcData, unsigned int SrcDataLen, const void* pDefines,
                                            void* pInclude, const char* pFunctionName, const char* pProfile,
                                            unsigned long Flags, ID3DXBuffer** ppShader, ID3DXBuffer** ppErrorMsgs,
                                            ID3DXConstantTable** ppConstantTable);
int __cdecl NiShaderFactory_ReportError(int, bool, const char*, ...);
int __cdecl strcpy_s(char*, unsigned int, char*);
void NiFree(void*);
void* _memmove(void*, const void*, unsigned int);
extern unsigned int DAT_0126fa24;
inline void NiMemcpy(void* pvDest, const void* pvSrc, unsigned int ItemUpdateArray)
{
    _memmove(pvDest, pvSrc, ItemUpdateArray);
}


// Compiles HLSL from a memory buffer via D3DXCompileShader, copies the resulting code into pvCode/uiCodeSize, and logs errors on failure.
// @fnv 0x00e964a0
bool NiD3DShaderProgramCreatorHLSL::CompileShaderFromMemory(const void* apSourceData, unsigned int auiSourceSize,
                                                            const char* pcEntryPoint, const char* pcShaderTarget,
                                                            void*& pvCode, unsigned int& uiCodeSize,
                                                            ID3DXConstantTable*& pkConstantTable, bool bRecoverable)
{
    pvCode = 0;
    uiCodeSize = 0;
    if (apSourceData == 0 || auiSourceSize == 0)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Invalid shader buffer\n");
        return false;
    }

    ID3DXBuffer* pkErrors;
    ID3DXBuffer* pkCode;
    long m_kResult = D3DXCompileShader((const char*)apSourceData, auiSourceSize, 0, 0, pcEntryPoint, pcShaderTarget,
                                       m_uiCompileFlags | DAT_0126fa24, &pkCode, &pkErrors, &pkConstantTable);
    if (m_kResult < 0)
    {
        char* pcErrorText = 0;
        if (pkErrors)
        {
            void* pvErrorData = pkErrors->GetBufferPointer();
            if (pvErrorData)
            {
                unsigned int uiLen = pkErrors->GetBufferSize();
                pcErrorText = (char*)_NiMalloc(uiLen);
                strcpy_s(pcErrorText, uiLen, (char*)pvErrorData);
                NiShaderFactory_ReportError(1, bRecoverable, "Failed to assemble shader %s from memory\nError: %s\n", pcEntryPoint,
                             pcErrorText);
            }
            pkErrors->Release();
        }
        else
        {
            NiShaderFactory_ReportError(1, bRecoverable, "Failed to assemble shader %s from memory\nError: NONE REPORTED\n",
                         pcEntryPoint);
        }
        NiFree(pcErrorText);
        if (pkCode)
            pkCode->Release();
        return false;
    }

    uiCodeSize = pkCode->GetBufferSize();
    pvCode = _NiMalloc(uiCodeSize);
    NiMemcpy(pvCode, pkCode->GetBufferPointer(), uiCodeSize);
    pkCode->Release();
    if (pkErrors)
        pkErrors->Release();
    return true;
}


extern "C" int __cdecl strcmp(const char* psz1, const char* psz2);
void __cdecl _NiFree(void*);
int __cdecl _strcpy_s(char* str, unsigned int numberOfElements, const char* source);

// @fnv 0x00be09e0
void NiD3DShaderProgram::SetShaderProfile(char* pszName)
{
    if (!pszName || strcmp(pszName, "") == 0)
    {
        _NiFree(m_pcProfile);
        m_pcProfile = 0;
        return;
    }

    unsigned int uiNewLen = strlen(pszName) + 1;

    if (m_pcProfile)
    {
        unsigned int uiOldLen = strlen(m_pcProfile);
        if (uiOldLen < uiNewLen)
        {
            _NiFree(m_pcProfile);
            m_pcProfile = 0;
        }
    }

    if (!m_pcProfile)
    {
        m_pcProfile = (char*)_NiMalloc(uiNewLen);
    }

    _strcpy_s(m_pcProfile, uiNewLen, pszName);
}

void _NiFree(void*);
int _strcpy_s(char*, unsigned int, const char*);


// Stores a copy of pszName in m_pcProgramName, reallocating the buffer when the new name is longer, or frees it when the name is empty.
// @fnv 0x00be0920
void NiD3DShaderProgram::SetName(char* pszName)
{
    if (!pszName || strcmp(pszName, "") == 0)
    {
        _NiFree(m_pcProgramName);
        m_pcProgramName = 0;
    }
    else
    {
        unsigned int uiNewLen = strlen(pszName) + 1;

        if (m_pcProgramName)
        {
            if (strlen(m_pcProgramName) < uiNewLen)
            {
                _NiFree(m_pcProgramName);
                m_pcProgramName = 0;
            }
        }

        if (!m_pcProgramName)
            m_pcProgramName = static_cast<char*>(_NiMalloc(uiNewLen));

        _strcpy_s(m_pcProgramName, uiNewLen, pszName);
    }
}


// @fnv 0x00be0ba0
void __thiscall NiD3DVertexShader::SetShaderUsage(unsigned int value)
{
    m_uiShaderUsage = value;
}

struct S_00e58ea0_Gen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int NiD3DShaderProgram_GetShaderProgramName();
    int NiD3DShaderProgram_GetName();
    void InitFloatArray(int a, int b, float c);
};

struct S_00e58ea0_Arr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void InitFloatArray(int a, int b, float c);
    void UpdateState_00c7b0f0();
};

struct S_00e58ea0_cls
{
    int unk00;
    int NiRenderTargetGroup_GetRendererData();
    void hkaSparseLSQMatrix_float_MultiplyAdd(S_00e58ea0_Gen* a, S_00e58ea0_Gen* b, S_00e58ea0_Arr* pkOut);
    S_00e58ea0_Gen* ProcessAndReturnValue_00e58ea0(S_00e58ea0_Gen* a1, S_00e58ea0_Gen* a2);
};

// @fnv 0x00e58ea0
// src: GUESS 0x00e58ea0 (confidence: low)
S_00e58ea0_Gen* S_00e58ea0_cls::ProcessAndReturnValue_00e58ea0(S_00e58ea0_Gen* a1, S_00e58ea0_Gen* a2)
{
    a1->InitFloatArray(a2->NiD3DShaderProgram_GetName(), a2->NiD3DShaderProgram_GetShaderProgramName(), 0.0f);
    S_00e58ea0_Arr tmpArr;
    tmpArr.InitFloatArray(NiRenderTargetGroup_GetRendererData(), a2->NiD3DShaderProgram_GetShaderProgramName(), 0.0f);
    hkaSparseLSQMatrix_float_MultiplyAdd(a1, a2, &tmpArr);
    tmpArr.UpdateState_00c7b0f0();
    return a1;
}

struct IUnk_e95
{
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct Shader_e95
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void* GetCode();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShader(void* p);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void SetShaderInterface(IUnk_e95* p);
};

long __stdcall D3DXGetShaderConstantTable_00ee6e40(void* pvCode, IUnk_e95** ppTable);

struct FUN_00e95c40_cls
{
    void* NiD3DShaderProgramCreator_CreatePixelShader(void* pvCode);
    bool AttachShaderFromCode(Shader_e95* pkShader);
};

// @fnv 0x00e95c40
bool FUN_00e95c40_cls::AttachShaderFromCode(Shader_e95* pkShader)
{
    void* pvCode = pkShader->GetCode();
    if (!pvCode)
        return false;
    void* pvShader = NiD3DShaderProgramCreator_CreatePixelShader(pvCode);
    if (!pvShader)
        return false;
    pkShader->SetShader(pvShader);
    IUnk_e95* pkTable;
    if (D3DXGetShaderConstantTable_00ee6e40(pvCode, &pkTable) >= 0)
        pkShader->SetShaderInterface(pkTable);
    if (pkTable)
        pkTable->Release();
    return true;
}

int __cdecl NiShaderFactory_ReportError(int, bool, const char*, ...);

extern NiD3DRenderer* g_pkD3DRenderer;
extern void* g_pkD3DDevice;
extern "C" const char* __stdcall D3DXGetPixelShaderProfile(void* pDevice);

class HLSLCreator;

// The remaining vertex construction views need an unsigned software-VP argument.
// The shared API takes bool; normalizing that argument changes the creator bytes.
class NiD3DShaderProgramBase
{
  public:
    NiD3DShaderProgramBase(NiD3DRenderer* pkRenderer, int iType) throw();
    virtual void DeleteThis(bool b);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

// Vertex layout: software-VP at 0x2c, usage at 0x30, shader/declaration at 0x34/0x38 (NiD3DVertexShader.h).
class VertexShaderConstructionView : public NiD3DShaderProgramBase
{
  public:
    VertexShaderConstructionView(NiD3DRenderer* pkRenderer) throw() : NiD3DShaderProgramBase(pkRenderer, 0)
    {
        m_bIsInitialized = false;
        m_uiPassCount = 0;
        m_uiProgramCodeSize = 0;
        m_pProgramCode = 0;
    }
    bool m_bIsInitialized;
    unsigned int m_uiPassCount;
    unsigned int m_uiProgramCodeSize;
    void* m_pProgramCode;
};

// Vertex vtable 0x010f119c and constant table at 0x44; pixel vtable is 0x010f10f4 with its table at 0x38.
class HLSLVertexShaderConstructionView : public VertexShaderConstructionView
{
  public:
    HLSLVertexShaderConstructionView(NiD3DRenderer* pkRenderer) throw() : VertexShaderConstructionView(pkRenderer)
    {
        m_pcShaderEntryPoint = 0;
        m_pcShaderProfile = 0;
        m_pShaderConstantTable = 0;
    }
    static void* operator new(unsigned int uiSize);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(HLSLCreator* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetPassCount(unsigned int ItemUpdateArray);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetSoftwareVertexProcessing(unsigned int b);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v43();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v45();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);
    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

class HLSLCreator : public NiD3DShaderProgramCreatorHLSL
{
  public:
    void* CreatePixelShaderHandle(void* pvCode, void* phShader, unsigned int auiGroupKey, void* pvUnused,
                                  unsigned int uiUnused, unsigned int uiSoftware);
    HLSLVertexShaderConstructionView* NiD3DShaderProgramCreatorHLSL_CreateVertexShader(const void* pvBuffer, unsigned int uiBufferSize, const char* pcShaderName,
                                              const char* pcEntryPoint, const char* pcShaderTarget, void* pvHandle,
                                              unsigned int auiGroupKey, unsigned int bSoftwareVP, bool bRecoverable);
};

// Compiles the shader source, creates the pixel shader handle, fills a new HLSLVertexShaderConstructionView with it and returns it, or returns 0 on failure.
// @fnv 0x00e967d0
// src: COMMUNITY 0x00e967d0
HLSLVertexShaderConstructionView* HLSLCreator::NiD3DShaderProgramCreatorHLSL_CreateVertexShader(const void* pvBuffer, unsigned int uiBufferSize,
                                                       const char* pcShaderName, const char* pcEntryPoint,
                                                       const char* pcShaderTarget, void* pvHandle,
                                                       unsigned int auiGroupKey, unsigned int bSoftwareVP,
                                                       bool bRecoverable)
{
    HLSLVertexShaderConstructionView* pkShader = new HLSLVertexShaderConstructionView(g_pkD3DRenderer);
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;

    if (pcEntryPoint == 0)
        pcEntryPoint = "main";
    if (pcShaderTarget == 0)
        pcShaderTarget = D3DXGetPixelShaderProfile(g_pkD3DDevice);

    if (!CompileShaderFromMemory(pvBuffer, uiBufferSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize,
                                 pkConstantTable, bRecoverable))
    {
        pkShader->DeleteThis(true);
        return 0;
    }

    void* hShader = CreatePixelShaderHandle(pvCode, &pvHandle, auiGroupKey, 0, 0, bSoftwareVP);
    if (hShader == 0)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        pkShader->DeleteThis(true);
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->SetShaderProgramFile(0);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    pkShader->SetPassCount(auiGroupKey);
    pkShader->SetSoftwareVertexProcessing(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget);
    pkShader->SetShaderInterface(pkConstantTable);

    if (pkConstantTable)
        pkConstantTable->Release();

    return pkShader;
}

struct MatResult
{
    bool m_ok;
    MatResult()
    {}
};

struct MatrixNm
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_numRows;
    int m_numCols;

    MatrixNm(int numRows, int numCols);
    void Release();
    int GetNumRows() const;
    int GetNumCols() const;
    float* GetPtr(int row, int col);
    float* GetVecPtr(int i);
    float Get(int row, int col);
};

MatResult __cdecl SolveVector(void* solver, MatrixNm& x, MatrixNm& b, int maxIter, float tolerance);

// Solves each column of x against b by copying it into single-column matrices, calling SolveVector, and writing the result back.
// @fnv 0x00e590f0
MatResult __cdecl SolveMatrixColumns(void* solver, MatrixNm& x, MatrixNm& b, int maxIter, float tolerance)
{
    MatResult result;
    MatrixNm xColumn(x.GetNumRows(), 1);
    MatrixNm bColumn(b.GetNumRows(), 1);
    for (int col = 0; col < x.GetNumCols(); col++)
    {
        int row;
        for (row = 0; row < x.GetNumRows(); row++)
        {
            *xColumn.GetVecPtr(row) = *x.GetPtr(row, col);
            float fValue = b.Get(row, col);
            *bColumn.GetVecPtr(row) = fValue;
        }
        if (!SolveVector(solver, xColumn, bColumn, maxIter, tolerance).m_ok)
        {
            result.m_ok = false;
            bColumn.Release();
            xColumn.Release();
            return result;
        }
        for (row = 0; row < x.GetNumRows(); row++)
        {
            *x.GetPtr(row, col) = *xColumn.GetVecPtr(row);
        }
    }
    result.m_ok = true;
    bColumn.Release();
    xColumn.Release();
    return result;
}

bool __cdecl NiShaderFindFile(const char* pcFile, char* pcPath, unsigned int uiLen);
extern "C" long __stdcall D3DXCompileShaderFromFileA(const char* pSrcFile, const void* pDefines, void* pInclude,
                                                     const char* pFunctionName, const char* pProfile,
                                                     unsigned long Flags, ID3DXBuffer** ppShader,
                                                     ID3DXBuffer** ppErrorMsgs, ID3DXConstantTable** ppConstantTable);

struct HLSLFileCreator : NiD3DShaderProgramCreatorHLSL
{
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, ID3DXConstantTable*& pkConstantTable,
                               bool bRecoverable);
};

// Finds the shader file, compiles it with D3DXCompileShaderFromFileA, copies the compiled code into pvCode and reports errors on failure.
// @fnv 0x00e962a0
bool HLSLFileCreator::CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint,
                                            const char* pcShaderTarget, void*& pvCode, unsigned int& uiCodeSize,
                                            ID3DXConstantTable*& pkConstantTable, bool bRecoverable)
{
    pvCode = 0;
    uiCodeSize = 0;

    if (!pcFileName || pcFileName[0] == '\0')
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Invalid shader file name\n");
        return false;
    }

    char acPath[260];
    if (!NiShaderFindFile(pcFileName, acPath, 260))
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed to find shader program file %s\n", pcFileName);
        return false;
    }

    ID3DXBuffer* pkErrors;
    ID3DXBuffer* pkShader;
    long hr = D3DXCompileShaderFromFileA(acPath, 0, 0, pcEntryPoint, pcShaderTarget, m_uiCompileFlags | DAT_0126fa24,
                                         &pkShader, &pkErrors, &pkConstantTable);
    if (hr < 0)
    {
        char* pcError = 0;
        if (pkErrors)
        {
            void* pvError = pkErrors->GetBufferPointer();
            if (pvError)
            {
                unsigned int uiLen = pkErrors->GetBufferSize();
                pcError = (char*)NiMalloc(uiLen);
                strcpy_s(pcError, uiLen, (char*)pvError);
                NiShaderFactory_ReportError(1, bRecoverable, "Failed to compile shader %s in file %s\nError: %s\n", pcEntryPoint,
                             pcFileName, pcError);
            }
            pkErrors->Release();
        }
        else
        {
            NiShaderFactory_ReportError(1, bRecoverable, "Failed to compile shader %s in file %s\nError: NONE REPORTED\n",
                         pcEntryPoint, pcFileName);
        }
        NiFree(pcError);
        if (pkShader)
            pkShader->Release();
        return false;
    }

    uiCodeSize = pkShader->GetBufferSize();
    pvCode = NiMalloc(uiCodeSize);
    NiMemcpy(pvCode, pkShader->GetBufferPointer(), uiCodeSize);
    pkShader->Release();
    if (pkErrors)
        pkErrors->Release();
    return true;
}

// @fnv 0x00be0aa0
void* NiD3DShaderProgram::GetCode()
{
    return m_pProgramCode;
}

// 0x00be0be0  mov al,[ecx+0x2c]; ret

// @fnv 0x00be0be0
unsigned char __fastcall GetSoftwareVertexProcessing(NiD3DVertexShader* shader)
{
    return shader->m_bIsInitialized;
}

struct FnvCpu_FUN_00e09630_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    int value;
    int GetValue();
};
// @fnv 0x00e09630
// src: GUESS 0x00e09630 (confidence: low)
int FnvCpu_FUN_00e09630_CpuObject::GetValue()
{
    return value;
}

struct FUN_00e587a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    int NiD3DShaderProgram_GetShaderProgramName();
};

// @fnv 0x00e587a0
// src: COMMUNITY 0x00e587a0
int __thiscall FUN_00e587a0_Class::NiD3DShaderProgram_GetShaderProgramName()
{
    return this->unk10;
}

// @fnv 0x00e95d50
// src: COMMUNITY 0x00e95d50
unsigned int NiD3DHLSLPixelShader::NiD3DVertexShader_GetShaderHandle()
{
    return reinterpret_cast<unsigned int>(m_pcShaderProfile);
}

// @fnv 0x00e95ee0
int NiD3DHLSLVertexShader::vf45()
{
    return reinterpret_cast<int>(m_pShaderConstantTable);
}

extern "C" void* g_0126fa28;
extern "C" void* g_0126fa2c;
void* __cdecl _NiMalloc_00aa1070(unsigned int uiSize);
void __cdecl FUN_00ec44d0(void* pvDest, const void* pvSrc, unsigned int ItemUpdateArray);

struct HLSLCreator_b10814
{
    int unk00;
    void* __thiscall CreateVertexShaderChecked(void* pvCode, void* phShader, unsigned int auiGroupKey, void* pvUnused1,
                                               unsigned int uiUnused2, unsigned int uiSoftwareVP);
    HLSLVertexShaderConstructionView* NiD3DShaderProgramCreatorHLSL_CreateVertexShaderFromBuffer(void* pvBuffer, unsigned int uiCodeSize, const char* pcShaderName,
                                              const char* pcEntryPoint, const char* pcShaderTarget, const char* pcName,
                                              unsigned int auiGroupKey, unsigned int bSoftwareVP, bool bRecoverable);
};

// @fnv 0x00e95f20
// src: COMMUNITY 0x00e95f20
HLSLVertexShaderConstructionView* HLSLCreator_b10814::NiD3DShaderProgramCreatorHLSL_CreateVertexShaderFromBuffer(void* pvBuffer, unsigned int uiCodeSize,
                                                              const char* pcShaderName, const char* pcEntryPoint,
                                                              const char* pcShaderTarget, const char* pcName,
                                                              unsigned int auiPassCount, unsigned int bSoftwareVP,
                                                              bool bRecoverable)
{
    HLSLVertexShaderConstructionView* pkShader = new HLSLVertexShaderConstructionView((NiD3DRenderer*)g_0126fa2c);
    if (pkShader == 0)
    {
        return 0;
    }

    ID3DXConstantTable* pkConstantTable = 0;
    if (D3DXGetShaderConstantTable_00ee6e40(((ID3DXBuffer*)pvBuffer)->GetBufferPointer(), (IUnk_e95**)&pkConstantTable) < 0)
    {
        return 0;
    }

    if (pcEntryPoint == 0)
    {
        pcEntryPoint = "main";
    }
    if (pcShaderTarget == 0)
    {
        pcShaderTarget = reinterpret_cast<const char*(__stdcall*)(void*)>(&D3DXGetVertexShaderProfile)(g_0126fa28);
    }

    void* pvHandle = this->CreateVertexShaderChecked(((ID3DXBuffer*)pvBuffer)->GetBufferPointer(), (void*)&pcName,
                                                     auiPassCount, 0, 0, bSoftwareVP);
    if (pvHandle == 0)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        pkShader->DeleteThis(true);
        return 0;
    }

    void* pvCode = _NiMalloc_00aa1070(uiCodeSize);
    unsigned int uiSize = ((ID3DXBuffer*)pvBuffer)->GetBufferSize();
    void* pBytecodeData = ((ID3DXBuffer*)pvBuffer)->GetBufferPointer();
    FUN_00ec44d0(pvCode, pBytecodeData, uiSize);

    pkShader->SetName(pcShaderName);
    pkShader->SetShaderProgramFile(0);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator((HLSLCreator*)this);
    pkShader->SetD3DPixelShader(pvHandle);
    pkShader->SetPassCount(auiPassCount);
    pkShader->SetSoftwareVertexProcessing(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget);
    pkShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable != 0)
    {
        pkConstantTable->Release();
    }
    return pkShader;
}

extern void* DAT_0126fa2c;
extern void* DAT_0126fa28;
extern void* DAT_010f10f4;
const char* __stdcall D3DXGetPixelShaderProfile_00ee6e28(void* pkDevice);

struct HLSLPixelShader96 : NiMemObject
{
    virtual void DeleteThis(bool bFree);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);

    void FUN_00e897d0(void* pkRenderer, int eType) throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* m_pD3DPixelShader;
    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

// the vtable at 0x010f10f4 has no symbol, so the inlined constructor stores it by hand
struct HLSLPixelShaderCtor96 : NiMemObject
{
    HLSLPixelShaderCtor96(void* pkRenderer) throw()
    {
        ((HLSLPixelShader96*)this)->FUN_00e897d0(pkRenderer, 2);
        ((HLSLPixelShader96*)this)->m_pD3DPixelShader = 0;
        *(void**)this = &DAT_010f10f4;
        ((HLSLPixelShader96*)this)->m_pcShaderEntryPoint = 0;
        ((HLSLPixelShader96*)this)->m_pcShaderProfile = 0;
        ((HLSLPixelShader96*)this)->m_pShaderConstantTable = 0;
    }
    int m_kNextStreamField[15];
};

struct PixelShaderCreatorHLSL : NiD3DShaderProgramCreatorHLSL
{
    void* NiD3DShaderProgramCreator_CreatePixelShader(void* pvCode);
    HLSLPixelShader96* NiD3DShaderProgramCreatorHLSL_CreatePixelShaderFromBuffer(const void* pvBuffer, unsigned int uiBufferSize, const char* pcShaderName,
                                    const char* pcEntryPoint, const char* pcShaderTarget, bool bRecoverable);
};

// @fnv 0x00e96b10
// src: COMMUNITY 0x00e96b10
HLSLPixelShader96* PixelShaderCreatorHLSL::NiD3DShaderProgramCreatorHLSL_CreatePixelShaderFromBuffer(const void* pvSourceBuffer, unsigned int uiSourceSize,
                                                        const char* pcShaderName, const char* pcEntryPoint,
                                                        const char* pcShaderTarget, bool bRecoverable)
{
    HLSLPixelShader96* pkPixelShader = (HLSLPixelShader96*)new HLSLPixelShaderCtor96(DAT_0126fa2c);
    if (!pkPixelShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;
    if (!pcEntryPoint)
        pcEntryPoint = "main";
    if (!pcShaderTarget)
        pcShaderTarget = D3DXGetPixelShaderProfile_00ee6e28(DAT_0126fa28);

    if (!CompileShaderFromMemory(pvSourceBuffer, uiSourceSize, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize,
                                 pkConstantTable, bRecoverable))
    {
        pkPixelShader->DeleteThis(true);
        return 0;
    }

    void* hShader = NiD3DShaderProgramCreator_CreatePixelShader(pvCode);
    if (!hShader)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreatePixelShader call on %s\n", pcShaderName);
        pkPixelShader->DeleteThis(true);
        return 0;
    }

    pkPixelShader->SetName(pcShaderName);
    pkPixelShader->SetShaderProgramFile(0);
    pkPixelShader->SetProgramCode(uiCodeSize, pvCode);
    pkPixelShader->SetCreator(this);
    pkPixelShader->SetD3DPixelShader(hShader);
    pkPixelShader->SetEntryPoint(pcEntryPoint);
    pkPixelShader->SetPixelShaderTarget(pcShaderTarget);
    pkPixelShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable)
        pkConstantTable->Release();
    return pkPixelShader;
}

struct SolverVector
{
    void* data;
    int size;
    int capacity;
    int rows;
    int columns;
    int NiD3DShaderProgram_GetName();
    SolverVector* Object_ProcessAndReturnValue_00e58e80(SolverVector* out, SolverVector* other);
    void CopyFrom(SolverVector* other);
    void InitArray(int rows, int columns);
    void UpdateState_00c7b0f0();
};
struct SolverMatrix
{
    SolverVector* ProcessAndReturnValue_00e58ea0(SolverVector* out, SolverVector* other);
    int NiRenderTargetGroup_GetRendererData();
    void hkaSparseLSQMatrix_float_Multiply(SolverVector*, SolverVector*, SolverVector*);
    void hkaSparseLSQMatrix_float_MultiplyAdd(SolverVector*, SolverVector*, SolverVector*);
};
float DotProduct(SolverVector*, SolverVector*);
__declspec(noalias) void hkaCGSolver_float_ScaleAdd_00e58960(SolverVector*, float*, SolverVector*);
void hkaCGSolver_float_CopyNegative(SolverVector*, SolverVector*);
void NegateElements(SolverVector*);
__declspec(noalias) void hkaCGSolver_float_ScaleAdd(SolverVector*, SolverVector*, float*, SolverVector*);
// Runs up to count iterations, returning true when the squared residual is below tolerance squared at an iteration check.
// @fnv 0x00e58f10
bool* ConjugateGradientSolve(bool* abConverged, SolverMatrix* matrix, SolverVector* apInitialGuess, SolverVector* apRhs,
                             int aiMaxIterations, float tolerance)
{
    int size = apInitialGuess->NiD3DShaderProgram_GetName();
    SolverVector temp;
    SolverVector pResidual, p, pMatVec, x;
    apRhs->Object_ProcessAndReturnValue_00e58e80(&pResidual, matrix->ProcessAndReturnValue_00e58ea0(&temp, apInitialGuess));
    temp.UpdateState_00c7b0f0();
    p.CopyFrom(&pResidual);
    pMatVec.InitArray(size, 1);
    x.InitArray(matrix->NiRenderTargetGroup_GetRendererData(), 1);
    float fResidualNormSq = DotProduct(&pResidual, &pResidual);
    float fToleranceSq = tolerance * tolerance;
    int i = 0;
    if (aiMaxIterations > 0)
        do
        {
            if (fResidualNormSq < fToleranceSq)
            {
                *abConverged = true;
                goto done;
            }
            matrix->hkaSparseLSQMatrix_float_Multiply(&pMatVec, &p, &x);
            {
                float fStepSize = (float)((double)fResidualNormSq / DotProduct(&p, &pMatVec));
                hkaCGSolver_float_ScaleAdd_00e58960(apInitialGuess, &fStepSize, &p);
                ++i;
                if (i % 50 == 0)
                {
                    hkaCGSolver_float_CopyNegative(&pResidual, apRhs);
                    matrix->hkaSparseLSQMatrix_float_MultiplyAdd(&pResidual, apInitialGuess, &x);
                    NegateElements(&pResidual);
                }
                else
                {
                    fStepSize = -fStepSize;
                    hkaCGSolver_float_ScaleAdd_00e58960(&pResidual, &fStepSize, &pMatVec);
                }
            }
            float fPrevResidualNormSq = fResidualNormSq;
            fResidualNormSq = DotProduct(&pResidual, &pResidual);
            float beta = fResidualNormSq / fPrevResidualNormSq;
            hkaCGSolver_float_ScaleAdd(&p, &pResidual, &beta, &p);
        } while (i < aiMaxIterations);
    *abConverged = false;
done:
    x.UpdateState_00c7b0f0();
    pMatVec.UpdateState_00c7b0f0();
    p.UpdateState_00c7b0f0();
    pResidual.UpdateState_00c7b0f0();
    return abConverged;
}

struct ConstTableE95
{
    virtual long __stdcall QueryInterface(void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

class ShaderSrcE95
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0A();
    virtual void vfn_0B();
    virtual void vfn_0C();
    virtual void vfn_0D();
    virtual void vfn_0E();
    virtual void vfn_0F();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void* GetCode();
    virtual void vfn_1A();
    virtual void vfn_1B();
    virtual void vfn_1C();
    virtual void vfn_1D();
    virtual void vfn_1E();
    virtual unsigned int GetCodeSize();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void SetD3DPixelShader(void* pvHandle);
    virtual unsigned int GetShaderVersion();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2A();
    virtual void vfn_2B();
    virtual void vfn_2C();
    virtual void vfn_2D();
    virtual void SetShaderInterface(ConstTableE95* pkTable);
};

long __stdcall D3DXGetShaderConstantTable_00ee6e40(void* pvCode, ConstTableE95** ppkTable);

class ShaderMgrE95
{
  public:
    void* CreateVertexShaderChecked(void* pvCode, unsigned int* puiVersion, unsigned int uiCodeSize, void* pvDecl,
                                    unsigned int uiFlags, unsigned int uiUsage);
    bool NiD3DShaderProgramCreatorHLSL_RecreateVertexShader(ShaderSrcE95* pkShader);
};

// Creates a shader handle from pkShader's code and version, stores it and an optional interface, and returns success.
// @fnv 0x00e95ba0
// src: COMMUNITY 0x00e95ba0
bool ShaderMgrE95::NiD3DShaderProgramCreatorHLSL_RecreateVertexShader(ShaderSrcE95* pkShader)
{
    void* pvCode = pkShader->GetCode();
    if (!pvCode)
        return false;

    unsigned int uiVersion = pkShader->GetShaderVersion();
    void* pvHandle = CreateVertexShaderChecked(pvCode, &uiVersion, pkShader->GetCodeSize(), 0, 0, 0);
    if (!pvHandle)
        return false;

    pkShader->SetD3DPixelShader(pvHandle);

    ConstTableE95* pkTable;
    if (D3DXGetShaderConstantTable_00ee6e40(pvCode, &pkTable) >= 0)
        pkShader->SetShaderInterface(pkTable);
    if (pkTable)
        pkTable->Release();
    return true;
}

extern "C" void _ReadWriteBarrier();
struct S00e96610_CT
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct D3DDeviceStandIn;
const char* __stdcall D3DXGetVertexShaderProfile(void* pDevice);

int __cdecl NiShaderFactory_ReportError(int, bool, const char*, ...);

struct S00e96610_Creator;
struct ShaderTargetName
{
    const char* value;
    ShaderTargetName(const char* name) : value(name)
    {}
};
inline void S00e96610_DefaultTarget(const char*& pcTarget)
{
    if (!pcTarget)
        pcTarget = D3DXGetVertexShaderProfile(DAT_0126fa28);
}

struct S00e96610_VSBase
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    S00e96610_VSBase(void* pkRenderer, void* hDecl) throw();
    virtual ~S00e96610_VSBase();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void HasMaster(const char* pcFileName);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(S00e96610_Creator* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetShaderUsage(unsigned int uiUsage);
    virtual void v33();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void SetSoftwareVP(unsigned int bSoftwareVP);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v43();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v45();
    virtual void SetShaderInterface(S00e96610_CT* pkTable);
};

struct S00e96610_VSMid : S00e96610_VSBase
{
    bool m_b2C;
    int m_i30;
    int m_i34;
    int m_i38;
    S00e96610_VSMid(void* pkRenderer) : S00e96610_VSBase(pkRenderer, 0), m_b2C(false), m_i30(0), m_i34(0), m_i38(0)
    {}
};

struct S00e96610_VS : S00e96610_VSMid
{
    int m_i3C;
    int m_i40;
    int m_i44;
    S00e96610_VS(void* pkRenderer) : S00e96610_VSMid(pkRenderer)
    {
        m_i3C = 0;
        m_i40 = 0;
        m_i44 = 0;
    }
    virtual ~S00e96610_VS();
    static void* operator new(unsigned int);
};

struct S00e96610_Creator
{
    void* m_vtbl;
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, S00e96610_CT*& pkConstantTable,
                               bool bRecoverable);
    void* CreateVertexShaderChecked(void* pvCode, void** phDecl, unsigned int uiUsage, void* pvUnused,
                                    unsigned int uiUnused1, unsigned int bSoftwareVP);
    S00e96610_VS* NiD3DShaderProgramCreatorHLSL_CreateVertexShaderFromFile(const char* pcFileName, const char* pcShaderName, const char* pcEntryPoint,
                               ShaderTargetName pcShaderTarget, void* hDecl, unsigned int uiUsage,
                               unsigned int bSoftwareVP, bool bRecoverable);
};

// Compiles a vertex shader from pcFileName and creates a D3D vertex shader, returning a configured S00e96610_VS or null on failure.
// @fnv 0x00e96610
// src: COMMUNITY 0x00e96610
S00e96610_VS* S00e96610_Creator::NiD3DShaderProgramCreatorHLSL_CreateVertexShaderFromFile(const char* pcFileName, const char* pcShaderName,
                                              const char* pcEntryPoint, ShaderTargetName pcShaderTarget, void* hDecl,
                                              unsigned int uiUsage, unsigned int bSoftwareVP, bool bRecoverable)
{
    S00e96610_VS* pkShader = new S00e96610_VS(DAT_0126fa2c);
    if (!pkShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    S00e96610_CT* pkConstantTable = 0;

    if (!pcEntryPoint)
        pcEntryPoint = "main";
    S00e96610_DefaultTarget(pcShaderTarget.value);
    _ReadWriteBarrier();

    if (!CompileShaderFromFile(pcFileName, pcEntryPoint, pcShaderTarget.value, pvCode, uiCodeSize, pkConstantTable,
                               bRecoverable))
    {
        delete pkShader;
        return 0;
    }

    void* hShader = CreateVertexShaderChecked(pvCode, &hDecl, uiUsage, 0, 0, bSoftwareVP);
    if (!hShader)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreateVertexShader call on %s\n", pcShaderName);
        delete pkShader;
        return 0;
    }

    pkShader->SetName(pcShaderName);
    pkShader->HasMaster(pcFileName);
    pkShader->SetProgramCode(uiCodeSize, pvCode);
    pkShader->SetCreator(this);
    pkShader->SetD3DPixelShader(hShader);
    pkShader->SetShaderUsage(uiUsage);
    pkShader->SetSoftwareVP(bSoftwareVP);
    pkShader->SetEntryPoint(pcEntryPoint);
    pkShader->SetPixelShaderTarget(pcShaderTarget.value);
    pkShader->SetShaderInterface(pkConstantTable);

    if (pkConstantTable)
        pkConstantTable->Release();

    return pkShader;
}

struct ShaderArgs
{
    const char* pcFileName;
    const char* pcShaderName;
};
class ShaderProgram96 : public NiMemObject
{
  public:
    ShaderProgram96(void* pkRenderer, int eType) throw();
    virtual ~ShaderProgram96();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class PixelShader96 : public ShaderProgram96
{
  public:
    PixelShader96(void* pkRenderer) throw() : ShaderProgram96(pkRenderer, 2)
    {
        m_pD3DPixelShader = 0;
    }
    virtual ~PixelShader96();
    void* m_pD3DPixelShader;
};

// local form of NiD3DHLSLPixelShader: 0x00e96100 and 0x00e96990 need the inline derived/base ctor chain; shared out-of-line construction changes bytes.
class LocalInlineHLSLPixelShader : public PixelShader96
{
  public:
    LocalInlineHLSLPixelShader(void* pkRenderer) throw() : PixelShader96(pkRenderer)
    {
        m_pcShaderEntryPoint = 0;
        m_pcShaderProfile = 0;
        m_pShaderConstantTable = 0;
    }
    virtual ~LocalInlineHLSLPixelShader();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void SetName(const char* pcName);
    virtual void v22();
    virtual void SetShaderProgramFile(const char* pcFile);
    virtual void v24();
    virtual void v25();
    virtual void SetProgramCode(unsigned int uiSize, void* pvCode);
    virtual void v27();
    virtual void SetCreator(void* pkCreator);
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void SetD3DPixelShader(void* hShader);
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual void v37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual void v39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);

    const char* m_pcShaderEntryPoint;
    const char* m_pcShaderProfile;
    ID3DXConstantTable* m_pShaderConstantTable;
};

struct HLSLFileShaderCreator : NiD3DShaderProgramCreatorHLSL
{
    bool CompileShaderFromFile(const char* pcFileName, const char* pcEntryPoint, const char* pcShaderTarget,
                               void*& pvCode, unsigned int& uiCodeSize, ID3DXConstantTable*& pkConstantTable,
                               bool bRecoverable);
    void* NiD3DShaderProgramCreator_CreatePixelShader(void* pvCode);
    LocalInlineHLSLPixelShader* NiD3DShaderProgramCreatorHLSL_CreatePixelShaderFromFile(ShaderArgs args, const char* pcEntryPoint, const char* pcShaderTarget,
                                     bool bRecoverable);
};

// Creates an LocalInlineHLSLPixelShader by compiling a shader file and configuring the new object with the compiled code and metadata.
// @fnv 0x00e96990
// src: COMMUNITY 0x00e96990
LocalInlineHLSLPixelShader* HLSLFileShaderCreator::NiD3DShaderProgramCreatorHLSL_CreatePixelShaderFromFile(ShaderArgs args, const char* pcEntryPoint,
                                                        const char* pcShaderTarget, bool bRecoverable)
{
    LocalInlineHLSLPixelShader* pkPixelShader = new LocalInlineHLSLPixelShader(DAT_0126fa2c);
    if (!pkPixelShader)
        return 0;

    unsigned int uiCodeSize = 0;
    void* pvCode = 0;
    ID3DXConstantTable* pkConstantTable = 0;

    if (!pcEntryPoint)
        pcEntryPoint = "main";
    if (!pcShaderTarget)
        pcShaderTarget = D3DXGetPixelShaderProfile_00ee6e28(DAT_0126fa28);

    if (!CompileShaderFromFile(args.pcFileName, pcEntryPoint, pcShaderTarget, pvCode, uiCodeSize, pkConstantTable,
                               bRecoverable))
    {
        delete pkPixelShader;
        return 0;
    }
    void* hShader = NiD3DShaderProgramCreator_CreatePixelShader(pvCode);
    if (!hShader)
    {
        NiShaderFactory_ReportError(1, bRecoverable, "Failed CreatePixelShader call on %s\n", args.pcShaderName);
        delete pkPixelShader;
        return 0;
    }
    pkPixelShader->SetName(args.pcShaderName);
    pkPixelShader->SetShaderProgramFile(args.pcFileName);
    pkPixelShader->SetProgramCode(uiCodeSize, pvCode);
    pkPixelShader->SetCreator(this);
    pkPixelShader->SetD3DPixelShader(hShader);
    pkPixelShader->SetEntryPoint(pcEntryPoint);
    pkPixelShader->SetPixelShaderTarget(pcShaderTarget);
    pkPixelShader->SetShaderInterface(pkConstantTable);
    if (pkConstantTable)
        pkConstantTable->Release();
    return pkPixelShader;
}

struct Dummy_00cc0760
{
    int unk00, unk04, unk08;
    int rows;
    int NiD3DShaderProgram_GetName();
};
// @fnv 0x00cc0760
// src: COMMUNITY 0x00cc0760
int Dummy_00cc0760::NiD3DShaderProgram_GetName()
{
    return rows;
}

extern "C" long __stdcall D3DXGetShaderConstantTable(const unsigned long*, ID3DXConstantTable**);

struct BufferPixelShaderCreator : HLSLFileShaderCreator
{
    LocalInlineHLSLPixelShader* NiD3DShaderProgramCreatorHLSL_CreatePixelShaderFromD3DXBuffer(ID3DXBuffer* code, unsigned int codeSize, const char* name, const char* entryPoint,
                                     const char* target, bool recoverable);
};

// @fnv 0x00e96100
// src: COMMUNITY 0x00e96100
LocalInlineHLSLPixelShader* BufferPixelShaderCreator::NiD3DShaderProgramCreatorHLSL_CreatePixelShaderFromD3DXBuffer(ID3DXBuffer* code, unsigned int codeSize, const char* name,
                                                           const char* entryPoint, const char* target, bool recoverable)
{
    LocalInlineHLSLPixelShader* shader = new LocalInlineHLSLPixelShader(DAT_0126fa2c);
    if (!shader)
        return 0;

    ID3DXConstantTable* constants = 0;
    if (D3DXGetShaderConstantTable((const unsigned long*)code->GetBufferPointer(), &constants) < 0)
        return 0;

    if (!entryPoint)
        entryPoint = "main";
    if (!target)
        target = D3DXGetPixelShaderProfile_00ee6e28(DAT_0126fa28);

    void* handle = NiD3DShaderProgramCreator_CreatePixelShader(code->GetBufferPointer());
    if (!handle)
    {
        NiShaderFactory_ReportError(1, recoverable, "Failed CreatePixelShader call on %s\n", name);
        delete shader;
        return 0;
    }

    void* copy = NiMalloc(codeSize);
    NiMemcpy(copy, code->GetBufferPointer(), code->GetBufferSize());

    shader->SetName(name);
    shader->SetShaderProgramFile(0);
    shader->SetProgramCode(codeSize, copy);
    shader->SetCreator(this);
    shader->SetD3DPixelShader(handle);
    shader->SetEntryPoint(entryPoint);
    shader->SetPixelShaderTarget(target);
    shader->SetShaderInterface(constants);
    if (constants)
        constants->Release();
    return shader;
}
