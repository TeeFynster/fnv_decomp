// bsshader/speedtreeleafshader.cpp: SpeedTreeLeafShader (5 functions)

#include "../../include/BSFadeNode.h"
#include "../../include/BSShader.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderConstantMap.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderConstantMap.h"
#include "speedtreeleafshader_decls.h"
#include "speedtreeleafshader_types_SpeedTreeLeafShader.h"
#include "speedtreeleafshader_types_SpeedTreeShader.h"
// The shared NiRefObject declares the reference-count methods; their inline bodies (Gamebryo NiRefObject.inl).
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <> inline NiPointer<NiD3DShaderConstantMap>&
NiPointer<NiD3DShaderConstantMap>::operator=(NiD3DShaderConstantMap* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            static_cast<NiRefObject*>(m_pObject)->DecRefCount();
        m_pObject = object;
        if (m_pObject)
            static_cast<NiRefObject*>(m_pObject)->IncRefCount();
    }
    return *this;
}

struct SpeedTreeLeafShaderColor
{
    float r, g, b, a;
    SpeedTreeLeafShaderColor(float R, float G, float B, float A) : r(R), g(G), b(B), a(A)
    {}
};

// @fnv 0x00bb2a00
SpeedTreeLeafShader::SpeedTreeLeafShader() : BSShader()
{
    iShaderType = 9;
    fnv_zlib_memset(m_afShaderConstants, 0, sizeof(m_afShaderConstants));
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200638) = SpeedTreeLeafShaderColor(1, 1, 1, 1);
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200648) = SpeedTreeLeafShaderColor(1, 1, 1, 1);
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200658) = SpeedTreeLeafShaderColor(0, 0, 0, 0);
    reinterpret_cast<SpeedTreeLeafShaderColor&>(DAT_01200668) = SpeedTreeLeafShaderColor(0, 0, 0, 0);
}

// Creates the vertex shader constant map if absent and registers the leaf shader constants, including a conditional one when DAT_011F941E is set.
// @fnv 0x00bb2d10
void SpeedTreeLeafShader::UpdateShaderConstants()
{
    if (m_spVertexConstantMap.m_pObject)
        return;

    m_spVertexConstantMap = new NiD3DShaderConstantMap(m_pkD3DRenderer, NiGPUProgram__ProgramType_PROGRAM_VERTEX);

    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010A1E50, 0x20000009, 0, 0, 4, 0, 0, 0, 0, false);
    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010AF568, 0x10000007, 0, 5, 1, DAT_01011584, 0x10, 4, DAT_011FA0C0, false);
    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010B92F8, 0x10000007, 0, 6, 1, DAT_01011584, 0x10, 4, DAT_011FA0D0, false);
    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010B92E8, 0x10000007, 0, 7, 1, DAT_01011584, 0x10, 4, DAT_011FA0E0, false);
    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010AF60C, 0x10000007, 0, 8, 1, DAT_01011584, 0x10, 4, DAT_011FA280, false);
    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010AF5E4, 0x10000007, 0, 9, 1, DAT_01011584, 0x10, 4, DAT_011FA290, false);

    if (DAT_011F941E)
    {
        m_spVertexConstantMap.m_pObject->SetConstant(DAT_010B92DC, 0x10000004, 0, 10, 1, DAT_01011584, 4, 4, DAT_011F918C, false);
    }

    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010B8C34, 0x10000009, 0, 11, 6, DAT_01011584, 0x60, 4, DAT_01200618, false);

    SpeedTreeLeafShaderConstantMapSetup::ConfigureShaderConstantMap(m_spVertexConstantMap.m_pObject, 0x11);

    m_spVertexConstantMap.m_pObject->SetConstant(DAT_010B92D0, 0x10000009, 0, 0x22, 0x30, DAT_01011584, 0x300, 4, m_afShaderConstants, false);
}

struct FUN_00bb2bb0_holder
{
    void FUN_00bb1c10();
    void* DestroyIfFlagged(unsigned int);
};
void _delete(void*, unsigned int);
// @fnv 0x00bb2bb0
void* FUN_00bb2bb0_holder::DestroyIfFlagged(unsigned int flags)
{
    FUN_00bb1c10();
    if (flags & 1)
        _delete(this, 0x38C);
    return this;
}

struct NiRenderer;
struct NiD3DVertexDeclaration
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
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool SetEntry(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void v36();
    virtual bool SetEntry8(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                           unsigned int, unsigned int);
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void Finalize();
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
};
extern NiRenderer* DAT_011f9508;
struct LeafV
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
    virtual void Init19();
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
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void SetDecl(NiD3DVertexDeclaration*);
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void Init71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void Init79();
};
struct FadeTag
{
};
inline void* operator new(unsigned int sz, FadeTag*)
{
    return BSFadeNode::operator new(sz);
}
// The original unwind (0x00f2b670) frees with the sized form: push 0x38c (sizeof(SpeedTreeLeafShader)).
inline void operator delete(void* p, FadeTag*)
{
    BSFadeNode::operator delete(p, sizeof(SpeedTreeLeafShader));
}
struct FUN_00bb1d40_t
{
    void CreatePasses();
};

// @fnv 0x00bb2c00
SpeedTreeLeafShader* CreateSpeedTreeLeafShader()
{
    NiD3DVertexDeclaration* pDecl = NiD3DVertexDeclaration::Create(DAT_011f9508, 4, 1);
    pDecl->SetEntry(0, 0, 0, 2, 0);
    pDecl->SetEntry(1, 3, 3, 2, 0);
    pDecl->SetEntry(2, 7, 5, 1, 0);
    pDecl->SetEntry8(0, 3, 8, 0x80000000, 3, 2, 0, 0);
    pDecl->Finalize();
    SpeedTreeLeafShader* pLeafShader = ::new ((FadeTag*)0) SpeedTreeLeafShader;
    ((LeafV*)pLeafShader)->Init19();
    ((LeafV*)pLeafShader)->Init79();
    ((FUN_00bb1d40_t*)pLeafShader)->CreatePasses();
    ((LeafV*)pLeafShader)->Init71();
    ((LeafV*)pLeafShader)->SetDecl(pDecl);
    return pLeafShader;
}

struct FUN_00bb2be0_shell : LeafV
{
    void SpeedTreeLeafShader_ReloadShaders();
};

// @fnv 0x00bb2be0
// src: XBOX_PDB 0x00bb2be0
void FUN_00bb2be0_shell::SpeedTreeLeafShader_ReloadShaders()
{
    this->Init79();
    reinterpret_cast<FUN_00bb1d40_t*>(this)->CreatePasses();
}
