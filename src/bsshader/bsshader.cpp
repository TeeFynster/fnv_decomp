// bsshader/bsshader.cpp: BSShader and shader helpers (27 functions)

#include "../../include/NiPointer.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShaderProperty.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiPropertyState.h"
// BSRenderStateManager_bsshader: local type (was include/BSRenderStateManager.h, which had no evidence of one real class); its methods are 0x00b97fa0 BSRenderState::SetAlphaBlendEnable, 0x00b98380 BSRenderState::SetColorWriteEnable
#include "../../include/BSRENDERSTATE_LOCK.h"

class BSRenderStateManager_bsshader
{
public:
    static void __cdecl SetDepthBufferEnabled(bool, BSRENDERSTATE_LOCK);
    static void __cdecl SetDepthBufferEnabled(bool, int);
    static void __cdecl SetColorWriteMask(unsigned int, BSRENDERSTATE_LOCK);
    static void __cdecl SetColorWriteMask(unsigned int, unsigned int);
};
#include "../../include/BSFile.h"
#include "../../include/NiD3DGPUProgramCache.h"
#include "../../include/NiD3DShaderProgram.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiGPUProgram.h"
#include "../../include/NiD3DPass.h"



// Shader passes use the pool reference count.
inline void ReleaseShaderPass(NiD3DPass* pass)
{
    if (--pass->m_uiRefCount == 0)
        pass->DestroyPass();
}
template <> inline NiPointer<NiD3DPass>& NiPointer<NiD3DPass>::operator=(NiD3DPass* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            ReleaseShaderPass(m_pObject);
        m_pObject = object;
        if (object)
            ++object->m_uiRefCount;
    }
    return *this;
}
#include "../../include/BSShader.h"

// Initializes the object by zeroing the first element of an array and setting a flag to false.
// @fnv 0x00be2200
BSShader::BSShader()
{
    spPass[0] = 0;
    bFirstPass = false;
}

class IMemoryHeap;
#include "../../include/MemoryManager.h"

extern MemoryManager g_memoryManager;
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int strcpy_s(char*, unsigned int, const char*);
extern "C" int strcat_s(char*, unsigned int, const char*);
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
struct _iobuf;
#include "../../include/_D3DXMACRO.h"
struct _FILETIME
{
    unsigned int dwLowDateTime, dwHighDateTime;
};
class FileFinder
{
  public:
    static BSFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
    static bool GetFileTime(const char*, _FILETIME&, unsigned int);
};
class ShaderBufferRecord;
class ShaderBufferCollection
{
  public:
    ShaderBufferRecord* Get(const char*);
};
class ShaderBufferTableBuilder
{
  public:
    void Add(const char*, char*, unsigned int);
};
class ID3DXBuffer;
class ID3DXConstantTable;
class ID3DXInclude;
extern "C" long __stdcall D3DXCompileShader(const char*, unsigned int, const _D3DXMACRO*, ID3DXInclude*, const char*,
                                            const char*, unsigned long, ID3DXBuffer**, ID3DXBuffer**,
                                            ID3DXConstantTable**);
extern GraphicsRenderer* g_pkRenderer;
extern char DAT_011f9200[260];
extern bool DAT_011f941e;
extern bool DAT_011ae638;
extern bool DAT_011f94a7;
extern ShaderBufferCollection* DAT_011f9498;
extern ShaderBufferTableBuilder* DAT_011f9494;
void BuildShaderCachePath(char*, const char*, const char*, const char*);
void HasFileInArchives(const char*);

// Pooled strings, the include vtable and the compiler exception handler.

int FUN_00f2d322(void*, void*, void*, void*);
extern const unsigned char DAT_01011584[];
extern const unsigned char DAT_01012630[];
extern const unsigned char DAT_01063ec8[];
extern const unsigned char DAT_0106e798[];
extern const unsigned char DAT_01094d90[];
extern const unsigned char DAT_010bc610[];
extern const unsigned char DAT_010bc754[];
extern const unsigned char DAT_010bc784[];
extern const unsigned char DAT_010bc7b8[];
extern const unsigned char DAT_010bc7e4[];
extern const unsigned char DAT_010bc7fc[];
extern const unsigned char DAT_010bc808[];
extern const unsigned char DAT_010bc820[];
extern const unsigned char DAT_010bc824[];
extern const unsigned char DAT_010bc828[];
extern const unsigned char DAT_010bc82c[];
extern const unsigned char DAT_010bc860[];
extern const unsigned char DAT_010bc868[];
void FUN_00ec8660();


extern char DAT_011f9308[];
extern void _strcat_s(char*, unsigned, const char*);
extern void __splitpath_s(const char*, char*, unsigned, char*, unsigned, char*, unsigned, char*, unsigned);
extern void FUN_00ec825b(char*, unsigned, const char*, const char*, const char*, const char*);

// @fnv 0x00be0c00
void __cdecl BSShader::GetShaderPath(const char* path, char* result)
{
    char drive[0x10];
    char dir[0x104];
    char name[0x80];
    char ext[8];
    char szBaseDir[0x104];
    if (result)
    {
        __splitpath_s(path, drive, 0x10, dir, 0x104, name, 0x80, ext, 8);
        __splitpath_s(DAT_011f9308, drive, 0x10, szBaseDir, 0x104, 0, 0, 0, 0);
        _strcat_s(szBaseDir, 0x104, dir);
        FUN_00ec825b(result, 0x104, drive, szBaseDir, name, ext);
    }
}

extern char DAT_011f9308[260];

// Builds a cache path from the default or configured directory, an optional "HDR." prefix, and the cache name, writing it into apCachePath.
// @fnv 0x00be0dc0
void __cdecl BuildCachePath(char* apCachePath, const char* apFileName, const char* apCacheName)
{
    if (apCachePath && apFileName && apCacheName)
    {
        char* ppath = DAT_011f9200;
        if (!DAT_011f9200[0])
            ppath = DAT_011f9308;
        strcpy_s(apCachePath, 260, ppath);
        if (DAT_011f941e)
            strcat_s(apCachePath, 260, "HDR.");
        strcat_s(apCachePath, 260, apCacheName);
    }
}

// @fnv 0x00be0e30
// src: GUESS 0x00be0e30 (confidence: high)
int __stdcall BSShader_FreeBlockAndReturnZero(void* apUnused, void* apBlock)
{
    g_memoryManager.Deallocate(apBlock);
    return 0;
}


extern unsigned int DAT_011f91e4;
void __cdecl BSRenderState_SetZWriteEnable(unsigned int, unsigned int);
void __cdecl BSRenderState_SetZFunc(unsigned int, unsigned int);

// @fnv 0x00be0e50
// src: COMMUNITY 0x00be0e50
void __stdcall BSShader_SetupGeometryNonFirstPass(int)
{
    if (DAT_011f91e4 < 0x252 || DAT_011f91e4 > 0x256)
    {
        BSRenderStateManager_bsshader::SetDepthBufferEnabled(true, BSRENDERSTATE_LOCK_BSRS_NOLOCK);
        BSRenderState_SetZWriteEnable(0, 0);
        BSRenderState_SetZFunc(2, 0);
    }
}

namespace fnv_00be0e90 {
void __cdecl BSRenderState_SetZWriteEnable(unsigned int, unsigned int);
void __cdecl BSRenderState_SetZFunc(unsigned int, unsigned int);

// @fnv 0x00be0e90
// src: COMMUNITY 0x00be0e90
void __cdecl BSShader_RestoreGeometryNonFirstPass()
{
    BSRenderStateManager_bsshader::SetDepthBufferEnabled(false, BSRENDERSTATE_LOCK_BSRS_NOLOCK);
    BSRenderState_SetZWriteEnable(1, 0);
    BSRenderState_SetZFunc(3, 0);
}
}  // namespace fnv_00be0e90

struct Node_00be0eb0
{
    int a;
    int b;
    Node_00be0eb0* next;
};

extern int DAT_0126f74c;
void __cdecl BSRenderState_SetRenderState(int, int, int);

// Walks the linked list at DAT_0126f74c+0x30+0x10 and calls FUN_00b97d90 on each node's a and b fields with 0.
// @fnv 0x00be0eb0
// src: COMMUNITY 0x00be0eb0
void __stdcall BSShader_SetupPassRenderStates(int)
{
    int ecx_val = *(int*)(DAT_0126f74c + 0x30);
    Node_00be0eb0* pNode = *(Node_00be0eb0**)(ecx_val + 0x10);
    while (pNode)
    {
        BSRenderState_SetRenderState(pNode->a, pNode->b, 0);
        pNode = pNode->next;
    }
}

struct Node_00be0ee0
{
    int m_val;
    int m_auiShapeKeys;
    Node_00be0ee0* m_next;
};

extern int DAT_0126f74c;
void __cdecl BSRenderState_RestoreState(int, int);

// Walks the linked list at DAT_0126f74c+0x30's +0x10 and calls FUN_00b98610 with each node's m_val and 0.
// @fnv 0x00be0ee0
// src: COMMUNITY 0x00be0ee0
void __stdcall BSShader_RestorePassRenderStates(int)
{
    int p1 = *(int*)(DAT_0126f74c + 0x30);
    Node_00be0ee0* node = *(Node_00be0ee0**)(p1 + 0x10);
    while (node)
    {
        BSRenderState_RestoreState(node->m_val, 0);
        node = node->m_next;
    }
}

// The approved NiFile layout does not name the stream state in unk04 yet.
inline bool ShaderFileIsGood(BSFile* file)
{
    return *(bool*)((char*)file + 0x2c);
}

void __cdecl ResolveRelativePath(const char*, const char*, char*);


// Builds a full path from pFileName, opens the file, allocates a buffer of its size, reads it into ppData, and returns the byte count in pBytes.
// @fnv 0x00be1eb0
long __stdcall ReadFileIntoMemory(void* pThis, int aiUnused, const char* pFileName, int aiUnused2, const void** appData,
                                  unsigned int* apuiBytes)
{
    char fullPath[260];
    ResolveRelativePath(*((const char**)pThis + 1), pFileName, fullPath);

    BSFile* pFile = FileFinder::GetFile(fullPath, NiFile::READ_ONLY, 0x4000, 0x20);
    if (pFile)
    {
        if (ShaderFileIsGood(pFile))
        {
            unsigned int size = pFile->GetSize();
            void* pData = g_memoryManager.Allocate(size);
            *appData = pData;
            unsigned int compSize = 1;
            unsigned int bytesRead = (*(NiBinaryStream::ReadFunction*)((char*)pFile + 8))(pFile, pData, size, &compSize, 1);
            *(unsigned int*)((char*)pFile + 4) += bytesRead;
            *apuiBytes = bytesRead;
            delete pFile;
            return 0;
        }
        delete pFile;
    }
    return 0x80004005;
}

namespace fnv_00be1f90 {
struct ObjA
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31_set(int);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35_set(int);
};

struct ObjB
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual int v31_get(int);
    virtual void v32();
    virtual int v33_get(int);
};

struct GlobalMgr
{
    char pad0[0x44];
    ObjB* p44;
    char pad1[0x14];
    ObjB* p5c;
};

extern GlobalMgr* DAT_0126f74c;
ObjA* __fastcall NiD3DPass_GetD3DRenderState(GlobalMgr*);

// Gets an ObjA from DAT_0126f74c and sets its v35 from p5c->v33_get(0), and if p44 is non-null sets its v31 from p44->v31_get(0).
// @fnv 0x00be1f90
void __fastcall SetFromGlobalManager(void* this_ptr, int edx_unused, int aiUnused)
{
    ObjA* pObjA = NiD3DPass_GetD3DRenderState(DAT_0126f74c);
    pObjA->v35_set(DAT_0126f74c->p5c->v33_get(0));
    ObjB* p44 = DAT_0126f74c->p44;
    if (p44)
    {
        pObjA->v31_set(p44->v31_get(0));
    }
}
}  // namespace fnv_00be1f90

int __cdecl BSRenderState_SetAlphaTestFuncRef(unsigned int, unsigned int, int);

// Reads a byte array from param, extracts a 3-bit value from offset 0x18 and a byte at 0x1a, and passes them to FUN_00b97f20.
// @fnv 0x00be20b0
// src: COMMUNITY 0x00be20b0
int __stdcall BSShader_SetupGeometryAlphaTesting(unsigned char** apData)
{
    unsigned char* p = *apData;
    return BSRenderState_SetAlphaTestFuncRef((*(unsigned short*)(p + 0x18) >> 10) & 7, p[0x1a], 0);
}

extern int DAT_0126f74c;

// Iterates the pass list at DAT_0126f74c and calls ApplyRenderStateChanges(false) on each non-null pass that is flagged and has a nonzero field at offset 8.
// @fnv 0x00be2170
// src: COMMUNITY 0x00be2170
void __cdecl BSShader_ApplyTextureStages()
{
    int p = DAT_0126f74c;
    unsigned int count = *(unsigned int*)(p + 0x18);
    for (unsigned int i = 0; i < count; ++i)
    {
        NiD3DPass* pass = ((NiD3DPass**)*(int*)(p + 0x24))[i];
        if (!pass)
            break;
        if (*(bool*)((char*)pass + 0x64) && *(int*)((char*)pass + 8))
            pass->ApplyRenderStateChanges(false);
    }
}

extern int DAT_011ae640[];
extern int DAT_0126f74c;

// @fnv 0x00be21b0
// src: COMMUNITY 0x00be21b0
void __cdecl BSShader_ApplyTextureStagesFlags()
{
    int p = DAT_0126f74c;
    unsigned int count = *(unsigned int*)(p + 0x18);
    int mask = *(char*)(p + 0x4c);
    for (unsigned int i = 0; i < count; ++i)
    {
        if (DAT_011ae640[i] & mask)
        {
            NiD3DPass* pass = ((NiD3DPass**)*(int*)(p + 0x24))[i];
            if (!pass)
                break;
            if (*(int*)((char*)pass + 8) != 0)
                pass->ApplyRenderStateChanges(false);
        }
    }
}

// @fnv 0x00be0ce0
void BSShader::ClearAllTextureStages()
{
    ClearTextureStages(spPass[0].m_pObject);
}

struct BeamTextureState
{
    void SetStageValue(unsigned int, unsigned int, bool);
    void NiD3DTextureStageGroup_SetSamplerState(unsigned int, unsigned int, unsigned int, bool);
};

struct BeamStage
{
    char _pad0[4];
    unsigned int m_arg2;
    char _pad8[8];
    BeamTextureState* m_pTextureState;
    char _pad14[0x4a];
    unsigned char m_byte5e;

    void ApplyPairToState(unsigned int);
    void NiD3DTextureStage_SetFilterMode(unsigned int);
};

// @fnv 0x00be0cf0
void __cdecl ConfigureBeamStage(BeamStage* stage, unsigned int uiValue, unsigned int arg3, unsigned int arg4,
                                bool bFlag)
{
    stage->m_arg2 = uiValue;
    stage->m_pTextureState->SetStageValue(11, uiValue, false);
    stage->m_pTextureState->SetStageValue(1, 1, false);
    stage->m_pTextureState->SetStageValue(2, 2, false);
    stage->m_pTextureState->SetStageValue(4, 1, false);
    stage->m_pTextureState->SetStageValue(5, 2, false);
    stage->m_byte5e = 0;
    stage->m_pTextureState->SetStageValue(24, 0, false);
    if (arg3 == 3)
        stage->ApplyPairToState(0);
    else
        stage->ApplyPairToState(3);
    stage->m_pTextureState->NiD3DTextureStageGroup_SetSamplerState(5, arg4, 0, false);
    stage->m_pTextureState->NiD3DTextureStageGroup_SetSamplerState(6, arg4, 0, false);
    stage->m_pTextureState->NiD3DTextureStageGroup_SetSamplerState(7, arg4, 0, false);
    stage->NiD3DTextureStage_SetFilterMode(bFlag ? 6 : 2);
}

struct M64Inner
{
    char pad[8];
    int f8;
    int fc;
};
struct M64Outer
{
    char pad[0x18];
    int count;
    char pad2[8];
    M64Inner** items;
};
// For each item in o->items, if the item's fc is not 1, sets its f8 to 0.
// @fnv 0x00be0fb0
// src: COMMUNITY 0x00be0fb0
void __stdcall BSShader_ClearPass(M64Outer* pOuter)
{
    if (pOuter)
    {
        int iCount = pOuter->count;
        for (int i = 0; i < iCount; i++)
        {
            M64Inner* pEntry = pOuter->items[i];
            if (pEntry->fc != 1)
                pEntry->f8 = 0;
        }
    }
}

void __cdecl BSRenderState_SetCullMode(int, int);
void __cdecl BSRenderState_SetAlphaTestEnable(bool, int);
extern unsigned int DAT_011f91e4;

struct Obj
{
    char pad[0x18];
    unsigned short flags;
};

struct StructA
{
    Obj* prop0;
    char pad[0xC];
    Obj* prop10;
};

// Derives two booleans from param_1's prop10/prop0 flags and DAT_011f91e4, then calls FUN_00b984d0 and FUN_00b97ed0 with them.
// @fnv 0x00be20e0
// src: COMMUNITY 0x00be20e0
void __stdcall NiD3DShader_SetupGeometryRenderStates(StructA* pStruct, bool bCheckProp0)
{
    unsigned int v = DAT_011f91e4;
    bool bFlagA = false;
    if (pStruct && pStruct->prop10)
    {
        if ((pStruct->prop10->flags & 0xc00) == 0xc00)
        {
            bFlagA = true;
        }
    }
    if ((v - 0x56) <= 1)
    {
        bFlagA = true;
    }

    bool bFlagB = false;
    if (bCheckProp0)
    {
        if (pStruct && pStruct->prop0)
        {
            bFlagB = (pStruct->prop0->flags >> 9) & 1;
        }
    }

    BSRenderState_SetCullMode(bFlagA ? 3 : 1, 0);
    BSRenderState_SetAlphaTestEnable(bFlagB, 0);
}

struct StageReturn
{
    void ReturnToPool();
};
struct StagePool
{
    StageReturn** m_pStackBuffer;
    int m_pad4;
    int m_uiCount;
    int m_pad0c;
    int m_uiCapacity;
    void AppendBlock(int cap);
    StageReturn* Get()
    {
        if (m_uiCount == 0)
        {
            AppendBlock(m_uiCapacity);
            m_uiCapacity *= 2;
        }
        StageReturn* s = m_pStackBuffer[0];
        --m_uiCount;
        m_pStackBuffer[0] = m_pStackBuffer[m_uiCount];
        return s;
    }
};
extern StagePool* DAT_0126f6cc;

// Gets a StageReturn from DAT_0126f6cc, marks it, and refcount-swaps it into output, releasing the previous one.
// @fnv 0x00e7edf0
void AssignStageFromPool(StageReturn*& output)
{
    StageReturn* stage = DAT_0126f6cc->Get();
    if (stage)
        ++*(unsigned int*)((char*)stage + 0x60);
    *((char*)stage + 0x5f) = 1;
    StageReturn* old = output;
    if (old != stage)
    {
        if (old)
        {
            if (--*(unsigned int*)((char*)old + 0x60) == 0)
                old->ReturnToPool();
        }
        output = stage;
        ++*(unsigned int*)((char*)stage + 0x60);
    }
    if (--*(unsigned int*)((char*)stage + 0x60) == 0)
        stage->ReturnToPool();
}

struct BSMultiBoundNode;
struct BSResizableTriShape;
struct BSSegmentedTriShape;
struct Direct3DDeviceInterface;
struct GeometryRelatedType;
struct NiD3DShaderProgramCreator;
struct NiGeometry;
struct NiLines;
struct NiNode;
struct NiParticles;
struct NiShaderConstantMapEntry;
struct NiTriBasedGeom;
struct NiTriShape;
struct NiTriStrips;
struct ShaderPassRenderer;
struct GraphicsRenderer;
struct _D3DXCONSTANTTABLE_DESC;
struct _D3DXCONSTANT_DESC;
struct bhkBlendCollisionObject;
struct bhkLimitedHingeConstraint;
struct bhkNiCollisionObject;
struct bhkRigidBody;
struct IUnknown
{
    virtual int QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
typedef char _sizecheck_IUnknown[sizeof(IUnknown) == 4 ? 1 : -1];
struct ID3DXBuffer : public IUnknown
{
    virtual void* GetBufferPointer();
    virtual unsigned long GetBufferSize();
    virtual int QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
};
typedef char _sizecheck_ID3DXBuffer[sizeof(ID3DXBuffer) == 4 ? 1 : -1];
struct ID3DXConstantTable : public ID3DXBuffer
{
    virtual int GetDesc(_D3DXCONSTANTTABLE_DESC*);
    virtual int GetConstantDescription(unsigned int, _D3DXCONSTANT_DESC*, unsigned int*);
    virtual unsigned int GetSamplerRegisterIndex(unsigned int);
    virtual unsigned int GetPlaneConstant(unsigned int, unsigned int);
    virtual unsigned int FindConstantByName(unsigned int, char*);
    virtual unsigned int GetArrayElementConstant(unsigned int, unsigned int);
    virtual int ApplyDefaults(Direct3DDeviceInterface*);
    virtual int SetValue(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetBool(Direct3DDeviceInterface*, unsigned int, int);
    virtual int SetBoolArray(Direct3DDeviceInterface*, unsigned int, int*, unsigned int);
    virtual int SetInt(Direct3DDeviceInterface*, unsigned int, int);
    virtual int SetIntArray(Direct3DDeviceInterface*, unsigned int, int*, unsigned int);
    virtual int SetFloat(Direct3DDeviceInterface*, unsigned int, float);
    virtual int SetFloatArray(Direct3DDeviceInterface*, unsigned int, float*, unsigned int);
    virtual int SetReferenceVector(Direct3DDeviceInterface*, unsigned int, void*);
    virtual int SetConstantVectorArray(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetMatrix(Direct3DDeviceInterface*, unsigned int, void*);
    virtual int SetMatrixArray(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetMatrixArrayPointers(Direct3DDeviceInterface*, unsigned int, void**, unsigned int);
    virtual int SetMatrixTranspose(Direct3DDeviceInterface*, unsigned int, void*);
    virtual int SetMatrixTransposeArray(Direct3DDeviceInterface*, unsigned int, void*, unsigned int);
    virtual int SetTransposeMatrixArrayPointers(Direct3DDeviceInterface*, unsigned int, void**, unsigned int);
    virtual int QueryInterface(void*, void**);
    virtual unsigned long AddRef();
    virtual unsigned long Release();
    virtual void* GetBufferPointer();
    virtual unsigned long GetBufferSize();
};
typedef char _sizecheck_ID3DXConstantTable[sizeof(ID3DXConstantTable) == 4 ? 1 : -1];
struct ShaderBufferRecord
{
    char* QName();
    unsigned int QSize();
    char* QData();
    unsigned int GetTotalSize();
    char pName[256];
    unsigned int uiSize;
    char pData[1];
    char _pad_105[3];
};
typedef char _sizecheck_ShaderBufferEntry[sizeof(ShaderBufferRecord) == 264 ? 1 : -1];
typedef char _sizecheck_NiGPUProgram[sizeof(NiGPUProgram) == 12 ? 1 : -1];
typedef char _sizecheck_NiD3DShaderProgram[sizeof(NiD3DShaderProgram) == 44 ? 1 : -1];
typedef char _sizecheck_NiD3DPixelShader[sizeof(NiD3DPixelShader) == 48 ? 1 : -1];

int FUN_00ec8a19(const char*, const char*, unsigned int);
int FUN_00ecda70(_iobuf*);
struct ShaderCodeBuffer_be1750
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void* __stdcall GetBufferPointer();
    virtual unsigned long __stdcall GetBufferSize();
};
// ShaderIncludes has an 8-byte include-callback ABI (filename at +4); no shared header exists yet.
struct ShaderIncludes
{
    const void* vtbl;
    const char* pShaderFileName;
};
struct ShaderDevice_be1750
{
    virtual void __stdcall s000();
    virtual void __stdcall s001();
    virtual void __stdcall s002();
    virtual void __stdcall s003();
    virtual void __stdcall s004();
    virtual void __stdcall s005();
    virtual void __stdcall s006();
    virtual void __stdcall s007();
    virtual void __stdcall s008();
    virtual void __stdcall s009();
    virtual void __stdcall s010();
    virtual void __stdcall s011();
    virtual void __stdcall s012();
    virtual void __stdcall s013();
    virtual void __stdcall s014();
    virtual void __stdcall s015();
    virtual void __stdcall s016();
    virtual void __stdcall s017();
    virtual void __stdcall s018();
    virtual void __stdcall s019();
    virtual void __stdcall s020();
    virtual void __stdcall s021();
    virtual void __stdcall s022();
    virtual void __stdcall s023();
    virtual void __stdcall s024();
    virtual void __stdcall s025();
    virtual void __stdcall s026();
    virtual void __stdcall s027();
    virtual void __stdcall s028();
    virtual void __stdcall s029();
    virtual void __stdcall s030();
    virtual void __stdcall s031();
    virtual void __stdcall s032();
    virtual void __stdcall s033();
    virtual void __stdcall s034();
    virtual void __stdcall s035();
    virtual void __stdcall s036();
    virtual void __stdcall s037();
    virtual void __stdcall s038();
    virtual void __stdcall s039();
    virtual void __stdcall s040();
    virtual void __stdcall s041();
    virtual void __stdcall s042();
    virtual void __stdcall s043();
    virtual void __stdcall s044();
    virtual void __stdcall s045();
    virtual void __stdcall s046();
    virtual void __stdcall s047();
    virtual void __stdcall s048();
    virtual void __stdcall s049();
    virtual void __stdcall s050();
    virtual void __stdcall s051();
    virtual void __stdcall s052();
    virtual void __stdcall s053();
    virtual void __stdcall s054();
    virtual void __stdcall s055();
    virtual void __stdcall s056();
    virtual void __stdcall s057();
    virtual void __stdcall s058();
    virtual void __stdcall s059();
    virtual void __stdcall s060();
    virtual void __stdcall s061();
    virtual void __stdcall s062();
    virtual void __stdcall s063();
    virtual void __stdcall s064();
    virtual void __stdcall s065();
    virtual void __stdcall s066();
    virtual void __stdcall s067();
    virtual void __stdcall s068();
    virtual void __stdcall s069();
    virtual void __stdcall s070();
    virtual void __stdcall s071();
    virtual void __stdcall s072();
    virtual void __stdcall s073();
    virtual void __stdcall s074();
    virtual void __stdcall s075();
    virtual void __stdcall s076();
    virtual void __stdcall s077();
    virtual void __stdcall s078();
    virtual void __stdcall s079();
    virtual void __stdcall s080();
    virtual void __stdcall s081();
    virtual void __stdcall s082();
    virtual void __stdcall s083();
    virtual void __stdcall s084();
    virtual void __stdcall s085();
    virtual void __stdcall s086();
    virtual void __stdcall s087();
    virtual void __stdcall s088();
    virtual void __stdcall s089();
    virtual void __stdcall s090();
    virtual void __stdcall s091();
    virtual void __stdcall s092();
    virtual void __stdcall s093();
    virtual void __stdcall s094();
    virtual void __stdcall s095();
    virtual void __stdcall s096();
    virtual void __stdcall s097();
    virtual void __stdcall s098();
    virtual void __stdcall s099();
    virtual void __stdcall s100();
    virtual void __stdcall s101();
    virtual void __stdcall s102();
    virtual void __stdcall s103();
    virtual void __stdcall s104();
    virtual void __stdcall s105();
    virtual long __stdcall CreatePixelShader(const unsigned int*, GeometryRelatedType**);
};
template <unsigned int _Size> inline int ShaderStrCat_be1750(char (&_Dest)[_Size], const char* _Source)
{
    return strcat_s(_Dest, _Size, _Source);
}

// @fnv 0x00be1750
NiD3DPixelShader* BSShader::CompilePixelShader(const char* apFilename, const _D3DXMACRO* apMacro,
                                             const char* apTarget, const char* apCacheName)
{
    bool bSourceExists;
    bool bfreeBuffer;
    ShaderCodeBuffer_be1750* pCompiledCode = 0;
    bool busecache;
    ShaderBufferRecord* pprePackagedShader = 0;
    ShaderCodeBuffer_be1750* pCompileError = 0;
    NiD3DPixelShader* pshader = 0;
    ID3DXConstantTable* pConstantTable = 0;
    unsigned int uiShaderSize = 0;
    char pcachepath[260];
    GeometryRelatedType* pd3dShader;
    bool bCacheExists;
    unsigned int* pshaderbuffer;
    char perror[260];

    BuildShaderCachePath(pcachepath, apFilename, apCacheName, "pso");
    busecache = true;
    bCacheExists = false;
    if (DAT_011f9498)
        pprePackagedShader = DAT_011f9498->Get(apCacheName);

    if (DAT_011ae638 && !pprePackagedShader)
    {
        _FILETIME ksrcFile = {};
        _FILETIME kcacheFile = {};
        bSourceExists = FileFinder::GetFileTime(apFilename, ksrcFile, 0x20);
        bCacheExists = FileFinder::GetFileTime(pcachepath, kcacheFile, 0x20);
        if (!bCacheExists && DAT_011f94a7)
        {
            const char* ppath = DAT_011f9200;
            if (0 == ppath || 0 == *ppath)
            {
                strcpy_s(DAT_011f9200, 0x104, (const char*)DAT_010bc860);
                BuildShaderCachePath(pcachepath, apFilename, apCacheName, "pso");
            }
            bCacheExists = FileFinder::GetFileTime(pcachepath, kcacheFile, 0x20);
        }
        if (!bSourceExists)
        {
            sprintf_s(perror, 0x104, (const char*)DAT_010bc82c, apFilename);
        }
        if (!bCacheExists)
            busecache = false;
    }

    bfreeBuffer = false;
    pshaderbuffer = 0;
    if (pprePackagedShader)
    {
        pshaderbuffer = (unsigned int*)pprePackagedShader->pData;
    }
    else if (!busecache)
    {
        _D3DXMACRO* pMacroDefines = 0;
        if (DAT_011f941e)
        {
            _D3DXMACRO* phdrmacro = (_D3DXMACRO*)apMacro;
            for (int imacro = 1; phdrmacro->Name; imacro++)
                phdrmacro = &((_D3DXMACRO*)apMacro)[imacro];
            phdrmacro->Name = (const char*)DAT_010bc828;
            phdrmacro->Definition = (const char*)DAT_01011584;
            pMacroDefines = phdrmacro;
        }
        const char* pProfile = apTarget;
        if (FUN_00ec8a19(apTarget, "ps_2_0", 4) == 0)
        {
            pProfile = NiD3DGPUProgramCache::GetPixelShaderProfile(true);
            if (!pProfile)
                pProfile = apTarget;
        }
        BSFile* pfile =
            (BSFile*)FileFinder::GetFile(apFilename, NiFile::READ_ONLY, 0x4000, 0x20);
        if (!pfile || !ShaderFileIsGood(pfile))
        {
            if (pfile)
                delete pfile;
            sprintf_s(perror, 0x104, (const char*)DAT_010bc7b8, apFilename);
            return 0;
        }
        unsigned int uiFileSize = pfile->GetSize();
        char* pfileData = (char*)g_memoryManager.Allocate(uiFileSize);
        pfile->NiBinaryStream::Read(pfileData, uiFileSize);
        ShaderIncludes includes;
        includes.vtbl = DAT_010bc610;
        includes.pShaderFileName = apFilename;
        {
            char pCompileMacros[1300];
            char pMacroDefines[1300];
            char perror[1300];
            pCompileMacros[0] = 0;
            pMacroDefines[0] = 0;
            for (int imacro = 0; imacro < 8; imacro++)
            {
                if (((_D3DXMACRO*)apMacro)[imacro].Name)
                {
                    ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[imacro].Name);
                    ShaderStrCat_be1750(pMacroDefines, (const char*)DAT_010bc824);
                    ShaderStrCat_be1750(pMacroDefines, ((_D3DXMACRO*)apMacro)[imacro].Name);
                    if (((_D3DXMACRO*)apMacro)[imacro].Definition && *((_D3DXMACRO*)apMacro)[imacro].Definition)
                    {
                        ShaderStrCat_be1750(pCompileMacros, (const char*)DAT_01063ec8);
                        ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[imacro].Definition);
                        ShaderStrCat_be1750(pMacroDefines, (const char*)DAT_01063ec8);
                        ShaderStrCat_be1750(pMacroDefines, ((_D3DXMACRO*)apMacro)[imacro].Definition);
                    }
                    else
                    {
                        ShaderStrCat_be1750(pMacroDefines, (const char*)DAT_010bc820);
                    }
                    ShaderStrCat_be1750(pCompileMacros, (const char*)DAT_01012630);
                }
            }
            sprintf_s(perror, 0x514, (const char*)DAT_010bc808, apFilename, apTarget, pCompileMacros);
            unsigned long uiCompileFlags = 0;
            long hResult =
                D3DXCompileShader(pfileData, uiFileSize, (_D3DXMACRO*)apMacro, (ID3DXInclude*)&includes,
                                  (const char*)DAT_01094d90, pProfile, uiCompileFlags, (ID3DXBuffer**)&pCompiledCode,
                                  (ID3DXBuffer**)&pCompileError, &pConstantTable);
            delete pfile;
            g_memoryManager.Deallocate(pfileData);
            if (pCompileError && !pCompiledCode)
            {
                pCompileMacros[0] = 0;
                for (int i = 0; i < 8; i++)
                {
                    if (((_D3DXMACRO*)apMacro)[i].Name)
                    {
                        ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[i].Name);
                        if (((_D3DXMACRO*)apMacro)[i].Definition && *((_D3DXMACRO*)apMacro)[i].Definition)
                        {
                            ShaderStrCat_be1750(pCompileMacros, (const char*)DAT_01063ec8);
                            ShaderStrCat_be1750(pCompileMacros, ((_D3DXMACRO*)apMacro)[i].Definition);
                        }
                        ShaderStrCat_be1750(pCompileMacros, (const char*)DAT_01012630);
                    }
                }
                sprintf_s(perror, 0x514, (const char*)DAT_010bc7fc, apFilename, pCompileMacros,
                          pCompileError->GetBufferPointer());
                pCompileError->Release();
                pCompileError = 0;
            }
            if (hResult == 0 && pCompiledCode)
            {
                _iobuf* pOutFile = fopen(pcachepath, (const char*)DAT_0106e798);
                uiShaderSize = pCompiledCode->GetBufferSize();
                fwrite(pCompiledCode->GetBufferPointer(), uiShaderSize, 1, pOutFile);
                FUN_00ecda70(pOutFile);
                fclose(pOutFile);
                HasFileInArchives(pcachepath);
                pshaderbuffer = (unsigned int*)pCompiledCode->GetBufferPointer();
            }
            else
            {
                if (!bCacheExists)
                    return 0;
                pfile = (BSFile*)FileFinder::GetFile(pcachepath, NiFile::READ_ONLY, 0x4000, 0x20);
                if (!pfile)
                    return 0;
                if (ShaderFileIsGood(pfile))
                {
                    uiShaderSize = pfile->GetSize();
                    pshaderbuffer = (unsigned int*)g_memoryManager.Allocate(uiShaderSize);
                    bfreeBuffer = true;
                    pfile->NiBinaryStream::Read(pshaderbuffer, uiShaderSize);
                }
                delete pfile;
                if (!pshaderbuffer)
                    return 0;
            }
        }
        if (pMacroDefines)
        {
            pMacroDefines->Name = 0;
            pMacroDefines->Definition = 0;
        }
    }
    else
    {
        BSFile* pfile =
            (BSFile*)FileFinder::GetFile(pcachepath, NiFile::READ_ONLY, 0x4000, 0x20);
        if (pfile)
        {
            if (ShaderFileIsGood(pfile))
            {
                uiShaderSize = pfile->GetSize();
                pshaderbuffer = (unsigned int*)g_memoryManager.Allocate(uiShaderSize);
                bfreeBuffer = true;
                pfile->NiBinaryStream::Read(pshaderbuffer, uiShaderSize);
            }
            delete pfile;
        }
        else
        {
            char perror[260];
            sprintf_s(perror, 0x104, (const char*)DAT_010bc754, pcachepath);
            return 0;
        }
    }

    if (pshaderbuffer)
    {
        if (DAT_011f9494)
        {
            DAT_011f9494->Add(apCacheName, (char*)pshaderbuffer, uiShaderSize);
        }
        else
        {
            ShaderDevice_be1750* pdevice = *(ShaderDevice_be1750**)((char*)g_pkRenderer + 0x288);
            if (pdevice->CreatePixelShader(pshaderbuffer, &pd3dShader))
            {
                char perror[260];
                sprintf_s(perror, 0x104, "SHADER ERROR : failed to create pixel shader : %s", pcachepath);
                return 0;
            }
            pshader = new NiD3DPixelShader(g_pkRenderer);
            pshader->SetD3DPixelShader(pd3dShader);
        }
    }
    if (bfreeBuffer)
        g_memoryManager.Deallocate(pshaderbuffer);
    return (NiD3DPixelShader*)pshader;
}

class BBDF6C0Light;

struct BBDF6C0GeometryData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short m_usFlags;
};

class BBDF6C0Geometry
{
  public:
    int unk00;
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
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    BBDF6C0GeometryData* m_pUserData;
};

struct BBDF6C0RenderPass
{
    int unk00;
    short unk04;
    unsigned char m_ucLightingType;
};

class BBDF6C0PassArray
{
  public:
    void Add(BBDF6C0Geometry* pkGeometry, unsigned short usPassType, bool bEnabled, unsigned char ucLights,
             BBDF6C0Light* pkLight0, BBDF6C0Light* pkLight1, BBDF6C0Light* pkLight2, BBDF6C0Light* pkLight3);

    int unk00;
    BBDF6C0RenderPass** m_ppkPasses;
    int unk08;
    int unk0C;
    int m_iArrayLength;
};

class BBDF6C0Shader
{
  public:
    virtual ~BBDF6C0Shader();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiFlags1;
    unsigned int m_uiFlags2;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    BBDF6C0PassArray* m_pkPasses;

    bool GetFlag(unsigned int uiBit) const
    {
        if (uiBit < 32)
            return (m_uiFlags1 & (1 << uiBit)) > 0;
        return (m_uiFlags2 & (1 << (uiBit - 32))) > 0;
    }

    void AddPasses(BBDF6C0Geometry* pkGeometry, bool bSkipDefault);
};

// Adds a render pass chosen by shader flags (or the geometry's default pass) and sets the first pass's lighting type from the flags.
// @fnv 0x00bdf6c0
void BBDF6C0Shader::AddPasses(BBDF6C0Geometry* pkGeometry, bool bSkipDefault)
{
    if (GetFlag(14))
    {
        m_pkPasses->Add(pkGeometry, 0x22f, true, 0, 0, 0, 0, 0);
    }
    else if (GetFlag(33))
    {
        m_pkPasses->Add(pkGeometry, 0x61, true, 0, 0, 0, 0, 0);
    }
    else if (!bSkipDefault)
    {
        BBDF6C0GeometryData* pkData = pkGeometry->m_pUserData;
        if (pkData && (bool)((pkData->m_usFlags >> 9) & 1))
            m_pkPasses->Add(pkGeometry, 0x63, true, 0, 0, 0, 0, 0);
        else
            m_pkPasses->Add(pkGeometry, 0x62, true, 0, 0, 0, 0, 0);
    }

    if (m_pkPasses->m_iArrayLength)
    {
        BBDF6C0RenderPass* pkPass = m_pkPasses->m_ppkPasses[0];
        unsigned char ucLightingType = 0;
        if (GetFlag(33) || GetFlag(34))
            ucLightingType = 10;
        else if (GetFlag(26))
            ucLightingType = GetFlag(53) ? 1 : 4;
        pkPass->m_ucLightingType = ucLightingType;
    }
}

class StageReturnC06
{
  public:
    void ReturnToPool();
    void DecRefCount()
    {
        --m_iRefCount;
        if (m_iRefCount == 0)
            ReturnToPool();
    }

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int m_iRefCount;
    bool m_bEnableState;
};

class StageReturnPtrC06
{
  public:
    StageReturnPtrC06() : m_pPointer(0)
    {}
    ~StageReturnPtrC06()
    {
        if (m_pPointer)
            m_pPointer->DecRefCount();
    }
    StageReturnC06* operator->() const
    {
        return m_pPointer;
    }
    operator StageReturnC06*() const
    {
        return m_pPointer;
    }

    StageReturnC06* m_pPointer;
};

void __cdecl AssignStageFromPool(StageReturnPtrC06& spStage);
void __cdecl ConfigureBeamStage(StageReturnC06* pkStage, unsigned int uiIndex, int iA, int iB, int iC);

class PassC06
{
  public:
    void SetDestructibleData(int iUnk, StageReturnC06* pkStage);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_iStageParam;
    unsigned int m_uiStageData;
    int unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48;
    char m_cMask;
};

// @fnv 0x00c06e10
void __cdecl SetStageMask(PassC06* pkPass, char cMask)
{
    StageReturnPtrC06 spStage;
    unsigned int uiNumStages = pkPass->m_uiStageData;
    if (uiNumStages < 7)
    {
        for (unsigned int i = 0; i < 7; i++)
        {
            AssignStageFromPool(spStage);
            ConfigureBeamStage(spStage, i, 1, 2, 1);
            pkPass->SetDestructibleData(pkPass->m_iStageParam, spStage);
            spStage->m_bEnableState = (cMask & (1 << i)) != 0;
        }
    }
    pkPass->m_cMask = cMask;
}

// FUN_00e7ee80 : default constructor of the small bookkeeping object used by
// the shader pass code.  The object starts out with its flag byte cleared and
// all four counters zeroed; the constructor returns the freshly built object
// (hence the "mov eax, ecx" prologue of a MSVC constructor).
struct FUN_00e7ee80_cls
{
    bool m_bEnableState;
    int m_iCount04;
    int m_iCount08;
    int m_iCount0c;
    int m_iCount10;

    FUN_00e7ee80_cls();
};

// @fnv 0x00e7ee80
FUN_00e7ee80_cls::FUN_00e7ee80_cls() : m_bEnableState(false), m_iCount04(0), m_iCount08(0), m_iCount0c(0), m_iCount10(0)
{}

struct LodShaderBase
{
    void FUN_00e814b0();
};

struct FUN_00b71b90_class : LodShaderBase
{
    void NiDX9FragmentShader_RecreateRendererData();
};

// @fnv 0x00be08b0
// src: XBOX_PDB 0x00be08b0
void FUN_00b71b90_class::NiDX9FragmentShader_RecreateRendererData()
{
    FUN_00e814b0();
}

void __cdecl FUN_00b97fa0(int, int);
void __cdecl AddToTwoCounters(int, int, int);
// Reads alpha and data from input, checks flags and alpha values, then calls FUN_00b97fa0 and AddToTwoCounters with blend or default counters.
// @fnv 0x00be1ff0
// src: COMMUNITY 0x00be1ff0
void __stdcall NiD3DShader_SetupGeometryAlphaBlending(NiPropertyState* input)
{
    NiAlphaProperty* alpha = (NiAlphaProperty*)input->m_aspProps[NiProperty::ALPHA];
    BSShaderProperty* data = (BSShaderProperty*)input->m_aspProps[NiProperty::SHADE];
    BSShaderProperty* pSelected;
    if (!data)
        pSelected = 0;
    else
        pSelected = data->iShaderPropertyType != -1 ? data : 0;
    data = pSelected;
    bool enabled = false;
    bool blend = false;
    volatile bool test = false;
    if (alpha)
    {
        unsigned char uiFlagBit = (unsigned char)(alpha->m_usAlphaArg >> 9);
        if (uiFlagBit & 1)
            test = true;
        if (alpha->m_usAlphaArg & 1)
        {
            enabled = true;
            blend = enabled;
        }
    }
    if (!(data->fAlpha < 1.0f) && !(data->fFadeAlpha < 1.0f) && !enabled)
    {
        FUN_00b97fa0(0, 0);
        return;
    }
    FUN_00b97fa0(1, 0);
    if (blend)
    {
        unsigned int flags = alpha->m_usAlphaArg;
        AddToTwoCounters((flags >> 1) & 15, (flags >> 5) & 15, 0);
    }
    else
        AddToTwoCounters(6, 7, 0);
}

struct Zero4
{
    int a;
    int b;
    int c;
    int d;
    Zero4* Zero();
};

// Sets all four int fields of the struct to zero and returns a pointer to the struct.
// @fnv 0x00e7ee70
Zero4* Zero4::Zero()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return this;
}

namespace fnv_00be0f10 {
struct ShaderManager
{
    void NiXenonRenderer_PurgeD3DShader(void*);
};
extern ShaderManager* DAT_011f9508;
}  // namespace fnv_00be0f10

// Releases the referenced pass when its count reaches zero, then calls a method on the shader manager.
// @fnv 0x00be0f10
BSShader::~BSShader()
{
    NiD3DPass* p = spPass[0].m_pObject;
    if (p)
    {
        if (--p->m_uiRefCount == 0)
            p->FUN_00e80190();
        spPass[0].m_pObject = 0;
    }
    fnv_00be0f10::DAT_011f9508->NiXenonRenderer_PurgeD3DShader(this);
}

namespace fnv_00be0fe0 {
struct CacheEntryView
{
    char name[260];
    char data[1];
};
class VertexDevice
{
  public:
    virtual void __stdcall DeviceMethod0();
    virtual void __stdcall DeviceMethod1();
    virtual void __stdcall DeviceMethod2();
    virtual void __stdcall DeviceMethod3();
    virtual void __stdcall DeviceMethod4();
    virtual void __stdcall DeviceMethod5();
    virtual void __stdcall DeviceMethod6();
    virtual void __stdcall DeviceMethod7();
    virtual void __stdcall DeviceMethod8();
    virtual void __stdcall DeviceMethod9();
    virtual void __stdcall DeviceMethod10();
    virtual void __stdcall DeviceMethod11();
    virtual void __stdcall DeviceMethod12();
    virtual void __stdcall DeviceMethod13();
    virtual void __stdcall DeviceMethod14();
    virtual void __stdcall DeviceMethod15();
    virtual void __stdcall DeviceMethod16();
    virtual void __stdcall DeviceMethod17();
    virtual void __stdcall DeviceMethod18();
    virtual void __stdcall DeviceMethod19();
    virtual void __stdcall DeviceMethod20();
    virtual void __stdcall DeviceMethod21();
    virtual void __stdcall DeviceMethod22();
    virtual void __stdcall DeviceMethod23();
    virtual void __stdcall DeviceMethod24();
    virtual void __stdcall DeviceMethod25();
    virtual void __stdcall DeviceMethod26();
    virtual void __stdcall DeviceMethod27();
    virtual void __stdcall DeviceMethod28();
    virtual void __stdcall DeviceMethod29();
    virtual void __stdcall DeviceMethod30();
    virtual void __stdcall DeviceMethod31();
    virtual void __stdcall DeviceMethod32();
    virtual void __stdcall DeviceMethod33();
    virtual void __stdcall DeviceMethod34();
    virtual void __stdcall DeviceMethod35();
    virtual void __stdcall DeviceMethod36();
    virtual void __stdcall DeviceMethod37();
    virtual void __stdcall DeviceMethod38();
    virtual void __stdcall DeviceMethod39();
    virtual void __stdcall DeviceMethod40();
    virtual void __stdcall DeviceMethod41();
    virtual void __stdcall DeviceMethod42();
    virtual void __stdcall DeviceMethod43();
    virtual void __stdcall DeviceMethod44();
    virtual void __stdcall DeviceMethod45();
    virtual void __stdcall DeviceMethod46();
    virtual void __stdcall DeviceMethod47();
    virtual void __stdcall DeviceMethod48();
    virtual void __stdcall DeviceMethod49();
    virtual void __stdcall DeviceMethod50();
    virtual void __stdcall DeviceMethod51();
    virtual void __stdcall DeviceMethod52();
    virtual void __stdcall DeviceMethod53();
    virtual void __stdcall DeviceMethod54();
    virtual void __stdcall DeviceMethod55();
    virtual void __stdcall DeviceMethod56();
    virtual void __stdcall DeviceMethod57();
    virtual void __stdcall DeviceMethod58();
    virtual void __stdcall DeviceMethod59();
    virtual void __stdcall DeviceMethod60();
    virtual void __stdcall DeviceMethod61();
    virtual void __stdcall DeviceMethod62();
    virtual void __stdcall DeviceMethod63();
    virtual void __stdcall DeviceMethod64();
    virtual void __stdcall DeviceMethod65();
    virtual void __stdcall DeviceMethod66();
    virtual void __stdcall DeviceMethod67();
    virtual void __stdcall DeviceMethod68();
    virtual void __stdcall DeviceMethod69();
    virtual void __stdcall DeviceMethod70();
    virtual void __stdcall DeviceMethod71();
    virtual void __stdcall DeviceMethod72();
    virtual void __stdcall DeviceMethod73();
    virtual void __stdcall DeviceMethod74();
    virtual void __stdcall DeviceMethod75();
    virtual void __stdcall DeviceMethod76();
    virtual void __stdcall DeviceMethod77();
    virtual void __stdcall DeviceMethod78();
    virtual void __stdcall DeviceMethod79();
    virtual void __stdcall DeviceMethod80();
    virtual void __stdcall DeviceMethod81();
    virtual void __stdcall DeviceMethod82();
    virtual void __stdcall DeviceMethod83();
    virtual void __stdcall DeviceMethod84();
    virtual void __stdcall DeviceMethod85();
    virtual void __stdcall DeviceMethod86();
    virtual void __stdcall DeviceMethod87();
    virtual void __stdcall DeviceMethod88();
    virtual void __stdcall DeviceMethod89();
    virtual void __stdcall DeviceMethod90();
    virtual long __stdcall CreateVertexShader(const char*, void**) = 0;
};
class VertexRendererView
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    VertexDevice* device;
    VertexDevice* GetDevice()
    {
        return device;
    }
};
extern "C" void HasFileInArchives(const char*);
extern "C" void _ReadWriteBarrier();
extern "C" void BuildCachePath(char*, const char*, const char*, const char*);
inline bool IsEmptyDirectory(const char* path)
{
    const char* empty = 0;
    return empty == path || !*path;
}
inline void Cat(char* d, unsigned n, const char* s)
{
    strcat_s(d, n, s);
}
extern "C" int BSsprintf(char*, int, const char*, ...);
extern "C" void* memset(void*, int, unsigned int);
class FileView;
struct FileViewMethods
{
    void(__thiscall* destroy)(FileView*, unsigned);
    void* method1;
    void* method2;
    void* method3;
    void* method4;
    void* method5;
    void* method6;
    void* method7;
    void* method8;
    void* method9;
    unsigned(__thiscall* size)(FileView*);
};
class FileView
{
  public:
    FileViewMethods* methods;
};

}  // namespace fnv_00be0fe0

// Compiles a vertex shader source file with macros and profile, caches the bytecode to disk, and creates a shader object on the device.
// @fnv 0x00be0fe0
NiD3DVertexShader* BSShader::CompileVertexShader(const char* source, const _D3DXMACRO* apMacros,
                                              const char* profile, const char* shaderName)
{
    using namespace fnv_00be0fe0;
    using fnv_00be0fe0::BuildCachePath;
    using fnv_00be0fe0::HasFileInArchives;
    _D3DXMACRO* macros = (_D3DXMACRO*)apMacros;
    ShaderBufferRecord* pCacheEntry = 0;
    ShaderCodeBuffer_be1750* pCompiledShader = 0;
    ShaderCodeBuffer_be1750* pCompileErrors = 0;
    NiD3DVertexShader* result = 0;
    ID3DXConstantTable* constants = 0;
    unsigned int bytecodeSize = 0;
    void* d3dShader;
    char cachePath[260];
    char message[260];
    char defines[1300];
    char errorMessage[260];
    char commandLine[1300];
    char diagnostic[1300];
    BuildCachePath(cachePath, source, shaderName, (const char*)DAT_010bc868);
    bool useCache = true;
    bool cacheExists = false;
    if (DAT_011f9498)
        pCacheEntry = DAT_011f9498->Get(shaderName);
    if (DAT_011ae638 && !pCacheEntry)
    {
        _ReadWriteBarrier();
        _FILETIME ftSourceTime;
        _FILETIME ftCacheTime;
        memset(&ftSourceTime, 0, sizeof(ftSourceTime));
        memset(&ftCacheTime, 0, sizeof(ftCacheTime));
        cacheExists = FileFinder::GetFileTime(cachePath, ftCacheTime, 32);
        bool sourceExists = FileFinder::GetFileTime(source, ftSourceTime, 32);
        if (!cacheExists && DAT_011f94a7)
        {
            if (IsEmptyDirectory(DAT_011f9200))
            {
                strcpy_s(DAT_011f9200, 260, (const char*)DAT_010bc860);
                BuildCachePath(cachePath, source, shaderName, (const char*)DAT_010bc868);
            }
            cacheExists = FileFinder::GetFileTime(cachePath, ftCacheTime, 32);
        }
        if (!sourceExists)
            BSsprintf(message, 260, (const char*)DAT_010bc82c, source);
        if (!cacheExists)
            useCache = false;
    }
    bool owned = false;
    char* bytecode = 0;
    if (pCacheEntry)
    {
        bytecode = ((CacheEntryView*)pCacheEntry)->data;
    }
    else if (!useCache)
    {
        _D3DXMACRO* addedMacro = 0;
        if (DAT_011f941e)
        {
            _D3DXMACRO* pMacro = macros;
            if (pMacro->Name)
            {
                _D3DXMACRO* next = macros + 1;
                do
                {
                    pMacro = next++;
                } while (pMacro->Name);
            }
            pMacro->Name = (const char*)DAT_010bc828;
            pMacro->Definition = (const char*)DAT_01011584;
            addedMacro = pMacro;
        }
        BSFile* pSourceFile = (BSFile*)FileFinder::GetFile(source, NiFile::READ_ONLY, 0x4000, 32);
        if (!pSourceFile || !ShaderFileIsGood(pSourceFile))
        {
            if (pSourceFile)
                delete pSourceFile;
            BSsprintf(message, 260, (const char*)DAT_010bc7b8, source);
            goto failure;
        }
        unsigned int sourceSize = pSourceFile->GetSize();
        char* sourceData = (char*)g_memoryManager.Allocate(sourceSize);
        pSourceFile->NiBinaryStream::Read(sourceData, sourceSize);
        struct IncludeHandler
        {
            const unsigned char* methods;
            const char* source;
        } include;
        include.methods = DAT_010bc610;
        include.source = source;
        defines[0] = 0;
        commandLine[0] = 0;
        for (int i = 0; i < 8; i++)
        {
            if (macros[i].Name)
            {
                Cat(defines, 1300, macros[i].Name);
                Cat(commandLine, 1300, (const char*)DAT_010bc824);
                Cat(commandLine, 1300, macros[i].Name);
                if (macros[i].Definition && macros[i].Definition[0])
                {
                    Cat(defines, 1300, (const char*)DAT_01063ec8);
                    Cat(defines, 1300, macros[i].Definition);
                    Cat(commandLine, 1300, (const char*)DAT_01063ec8);
                    Cat(commandLine, 1300, macros[i].Definition);
                }
                else
                {
                    Cat(commandLine, 1300, (const char*)DAT_010bc820);
                }
                Cat(defines, 1300, (const char*)DAT_01012630);
            }
        }
        BSsprintf(diagnostic, 1300, (const char*)DAT_010bc808, source, profile, defines);
        long lCompileStatus =
            D3DXCompileShader(sourceData, sourceSize, macros, (ID3DXInclude*)&include, (const char*)DAT_01094d90,
                              profile, 0, (ID3DXBuffer**)&pCompiledShader, (ID3DXBuffer**)&pCompileErrors, &constants);
        delete pSourceFile;
        g_memoryManager.Deallocate(sourceData);
        if (pCompileErrors && !pCompiledShader)
        {
            defines[0] = 0;
            for (int i = 0; i < 8 && macros[i].Name; i++)
            {
                Cat(defines, 1300, macros[i].Name);
                if (macros[i].Definition && macros[i].Definition[0])
                {
                    Cat(defines, 1300, (const char*)DAT_01063ec8);
                    Cat(defines, 1300, macros[i].Definition);
                }
                Cat(defines, 1300, (const char*)DAT_01012630);
            }
            BSsprintf(diagnostic, 1300, (const char*)DAT_010bc7fc, source, defines,
                         pCompileErrors->GetBufferPointer());
            pCompileErrors->Release();
            pCompileErrors = 0;
        }
        if (!lCompileStatus && pCompiledShader)
        {
            _iobuf* pOutputFile = fopen(cachePath, (const char*)DAT_0106e798);
            if (pOutputFile)
            {
                bytecodeSize = pCompiledShader->GetBufferSize();
                fwrite(pCompiledShader->GetBufferPointer(), bytecodeSize, 1, pOutputFile);
                fclose(pOutputFile);
                HasFileInArchives(cachePath);
            }
            else
            {
                BSsprintf(message, 255, (const char*)DAT_010bc7e4, cachePath);
            }
            bytecode = (char*)pCompiledShader->GetBufferPointer();
        }
        else
        {
            if (!cacheExists)
                goto failure;
            BSFile* pCacheFile =
                (BSFile*)FileFinder::GetFile(cachePath, NiFile::READ_ONLY, 0x4000, 32);
            if (!pCacheFile)
                goto failure;
            if (ShaderFileIsGood(pCacheFile))
            {
                bytecodeSize = pCacheFile->GetSize();
                bytecode = (char*)g_memoryManager.Allocate(bytecodeSize);
                owned = true;
                pCacheFile->NiBinaryStream::Read(bytecode, bytecodeSize);
            }
            delete pCacheFile;
            if (!bytecode)
                goto failure;
        }
        if (addedMacro)
        {
            addedMacro->Name = 0;
            addedMacro->Definition = 0;
        }
    }
    else
    {
        BSFile* pCacheFile = (BSFile*)FileFinder::GetFile(cachePath, NiFile::READ_ONLY, 0x4000, 32);
        if (pCacheFile)
        {
            if (ShaderFileIsGood(pCacheFile))
            {
                FileView* pFileView = (FileView*)pCacheFile;
                bytecodeSize = pFileView->methods->size(pFileView);
                bytecode = (char*)g_memoryManager.Allocate(bytecodeSize);
                owned = true;
                pCacheFile->NiBinaryStream::Read(bytecode, bytecodeSize);
            }
            delete pCacheFile;
        }
        else
        {
            BSsprintf(errorMessage, 260, (const char*)DAT_010bc754, cachePath);
            goto failure;
        }
    }
    if (bytecode)
    {
        if (DAT_011f9494)
            DAT_011f9494->Add(shaderName, bytecode, bytecodeSize);
        else
        {
            VertexDevice* device = ((VertexRendererView*)g_pkRenderer)->GetDevice();
            if (device->CreateVertexShader(bytecode, &d3dShader))
                goto deviceError;
            result = new NiD3DVertexShader(g_pkRenderer);
            result->SetD3DPixelShader(d3dShader);
        }
    }
    if (owned)
        g_memoryManager.Deallocate(bytecode);
    return result;
deviceError:
    BSsprintf(errorMessage, 260, (const char*)DAT_010bc784, cachePath);
failure:
    _ReadWriteBarrier();
    return result;
}
