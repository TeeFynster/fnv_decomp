
// Gamebryo 2.2 NiMain: NiParticleMeshes. PC build's default constructor only
// constructs the NiParticles base and installs the NiParticleMeshes vtable.
#include "../../../../include/NiParticleMeshes.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiUpdateData.h"

// @fnv 0x00a9b120
NiParticleMeshes::NiParticleMeshes()
{}


extern NiRTTI* g_011f5f14;

// @fnv 0x00a98ec0
const NiRTTI* NiParticleMeshes::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011f5f14);
}

extern void __cdecl UpdateFields_00a80580();
extern "C" void __cdecl _delete(void*, unsigned int);

// Calls FUN_00a80580, then deletes this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a98ed0
void* NiParticleMeshes::Delete(unsigned int flags)
{
    NiParticleMeshes* p = this;
    UpdateFields_00a80580();
    if (flags & 1)
        _delete(p, 0xcc);
    return p;
}

class NiParticleMeshesData;
// @fnv 0x00a99090
void NiParticleMeshes::PurgeRendererData(NiRenderer* pkRenderer)
{
    NiGeometry::PurgeRendererData(pkRenderer);
    NiParticleMeshesData* pkPMData = (NiParticleMeshesData*)m_spModelData.m_pObject;
    if (pkPMData)
    {
        NiNode* pkMeshes = *(NiNode**)((char*)pkPMData + 0x70);
        if (pkMeshes)
        {
            pkMeshes->PurgeRendererData(pkRenderer);
        }
    }
}

struct StrArr2
{
    char** m_pData;
    unsigned int m_u04;
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* __cdecl _FUN_00a7d330(const char*);
extern const char* const g_011f5f14_arg1;
// Appends the string returned by _FUN_00a7d330(g_011f5f14_arg1) to pkStrings, growing the array if it is full.
// @fnv 0x00a990c0
void NiParticleMeshes::AppendString(StrArr2* pkStrings)
{
    NiParticles_GetViewerStrings(pkStrings);
    char* psz = _FUN_00a7d330(g_011f5f14_arg1);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMax = pkStrings->m_usMax;
    if (uiSize >= uiMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrow);
    pkStrings->SetAt(uiSize, psz);
}

// @fnv 0x00a99000
void NiParticleMeshes::SetSelectiveUpdateFlags(bool& bSelectiveUpdate, bool bSelectiveUpdateTransforms, bool& bRigid)
{
    NiGeometry::SetSelectiveUpdateFlags(bSelectiveUpdate, true, bRigid);
    NiNode* pkParticlesContainer = *(NiNode**)((char*)m_spModelData.m_pObject + 0x70);
    pkParticlesContainer->SetSelectiveUpdateFlags(bSelectiveUpdate, true, bRigid);
    bRigid = false;
    pkParticlesContainer->m_uFlags &= 0xffffffef;
}

// @fnv 0x00a99040
void NiParticleMeshes::UpdatePropertyState(NiPropertyState* pkParentState)
{
    NiGeometry::UpdatePropertiesDownwardPass(pkParentState);
    NiNode* pkParticlesContainer = *(NiNode**)((char*)m_spModelData.m_pObject + 0x70);
    pkParticlesContainer->UpdatePropertiesDownwardPass(&m_PropertyState);
}

// @fnv 0x00a98e30
void NiParticleMeshes::UpdateDownwardPass(NiUpdateData& apVal, unsigned int x)
{
    m_fLastTime = apVal.fTime;
    m_bUpdate = *reinterpret_cast<bool*>(&apVal.pad1);
    FUN_00a59f90(&apVal, x);
}

// Stores kData.fTime into m_fLastTime, then forwards kData to the base UpdateDownwardPassIfSelective.
// @fnv 0x00a98e50
void NiParticleMeshes::UpdateSelectedDownwardPass(NiUpdateData& kData, unsigned int flags)
{
    m_fLastTime = kData.fTime;
    NiAVObject::UpdateSelectedDownwardPass(kData, flags);
}

struct MeshesData
{
    char pad[0x70];
    NiNode* m_pkTarget;
};
// @fnv 0x00a99070
void NiParticleMeshes::RenderTarget(NiRenderer* pkRenderer)
{
    ((MeshesData*)m_spModelData.m_pObject)->m_pkTarget->OnVisible(*reinterpret_cast<NiCullingProcess*>(pkRenderer));
}

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern const char DAT_010a0a6c;



// Allocates and initializes a particle mesh clone, then copies member data.
// @fnv 0x00a98f00
NiParticleMeshes* NiParticleMeshes::CreateAndInitObj(void* pArg)
{
    NiParticleMeshes* pObj = (NiParticleMeshes*)Object_DispatchCommandFour(0xcc);
    if (pObj != 0)
    {
        pObj->Init();
        *(const char**)pObj = &DAT_010a0a6c;
        pObj->m_bUpdate = true;
    }
    else
    {
        pObj = 0;
    }
    NiParticleMeshes_CopyMembers(pObj, pArg);
    return pObj;
}

#include <math.h>

inline float A98F60Abs(float f)
{
    return (float)fabs(f);
}

struct A98F60Renderer
{
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
    NiNode* m_pkMeshes;
    bool m_bValueAt0C;

    void UpdateParticleMeshes();
};

// Copies the object's world transform to the meshes node's local transform, updates particle meshes, and calls two functions when the renderer flag is set.
// @fnv 0x00a98f60
void NiParticleMeshes::UpdateWorldData(NiUpdateData& kData)
{
    NiAVObject::UpdateWorldData(kData);
    A98F60Renderer* pkRenderer = (A98F60Renderer*)m_spModelData.m_pObject;
    NiNode* pkMeshes = pkRenderer->m_pkMeshes;
    pkRenderer->UpdateParticleMeshes();
    pkMeshes->m_kLocal.m_Rotate = m_kWorld.m_Rotate;
    pkMeshes->m_kLocal.m_Translate = m_kWorld.m_Translate;
    pkMeshes->m_kLocal.m_fScale = A98F60Abs(m_kWorld.m_fScale);
    pkMeshes->UpdateDownwardPass(kData, 0);
    if (pkRenderer->m_bValueAt0C)
    {
        UpdateProperties();
        Object_DoNothing();
        pkRenderer->m_bValueAt0C = false;
    }
}

