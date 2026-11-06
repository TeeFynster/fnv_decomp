// fallout_shared/sky/precipitation.cpp: Precipitation (6 functions)

#include "../../../include/NiNode.h"
#include "../../../include/NiSortAdjustNode.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/Precipitation.h"
#include "precipitation_decls.h"
int FUN_00404dc0(const char*, const char*);
// @fnv 0x00636c40
void Precipitation::Load(const char* path)
{
    if (m_pPrecipitationNode)
    {
        pParent->RemoveObject(m_pPrecipitationNode);
        m_pPreviousNode = m_pPrecipitationNode;
        pParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NiNode*>(m_pPreviousNode)), true);
        m_pPrecipitationNode = 0;
    }
    if (path && *path)
    {
        NiNode* model = g_modelLoader->LoadFile(path, ENUM_LOD_MULT_LOD_MULT_NONE, true, false, false, false);
        if (model)
        {
            bool bIsSnow = FUN_00404dc0(path, DAT_0104ed9c) == 0;
            NiUpdateData kUpdateData(0.0f, false, false);
            model->UpdateDownwardPass(kUpdateData, 0);
            m_pPrecipitationNode = new NiSortAdjustNode(0);
            fEmissionRate = 0.0f;
            for (unsigned int index = 0; index < model->FUN_00453470(); ++index)
            {
                NiAVObject* m_pShaderGeometry = model->FUN_0043b4a0(index)->IsSceneNode();
                SkyShaderProperty* pShaderProperty =
                    m_pShaderGeometry ? FUN_00653270(&DAT_012024e0, m_pShaderGeometry->FUN_0045bc00(false)) : 0;
                if (!pShaderProperty)
                    continue;
                NiAVObject* precipParticle = CreateParticleShape(pShaderProperty, pParent->FUN_00461130(bIsSnow));
                if (precipParticle)
                    static_cast<NiNode*>(m_pPrecipitationNode)->AttachChildInAvailableSlot(precipParticle, true);
            }
            pParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NiNode*>(m_pPrecipitationNode)), true);
            static_cast<NiNode*>(m_pPrecipitationNode)->UpdateSceneObject();
        }
    }
}

NiAVObject* __cdecl FUN_0054f4f0(void);

// @fnv 0x00636bb0
void Precipitation::InitParent()
{
    pParent = static_cast<NiNode*>(FUN_0054f4f0());
}

// @fnv 0x00637800
void Precipitation::FlushAll()
{
    if (m_pPreviousNode.operator NiNode*())
    {
        pParent->RemoveObject(static_cast<NiAVObject*>(m_pPreviousNode.operator NiNode*()));
        m_pPreviousNode = static_cast<NiNode*>(0);
    }
    if (m_pPrecipitationNode.operator NiNode*())
    {
        pParent->RemoveObject(static_cast<NiAVObject*>(m_pPrecipitationNode.operator NiNode*()));
        m_pPrecipitationNode = static_cast<NiNode*>(0);
    }
}

void _Deallocate(void*);
// Destroys the object, frees it when requested, and returns its address.
// @fnv 0x00636af0
void* Precipitation::DestroyIfFlagged(unsigned int flags)
{
    this->Precipitation::~Precipitation();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct PrecipQueuedObject
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual void vfn_0010();
    virtual void* vfn_0014(int a0, int a1, int a2, int a3, int a4, int a5);

    int FUN_0048cee0();
};

struct PrecipManager
{
    void FUN_00444040(void* object);
};

extern PrecipManager* DAT_011c3b3c;

// @fnv 0x00636bd0
void Precipitation::QueuePrecipitationObject(PrecipQueuedObject* object)
{
    if (m_pPreviousNode.operator NiNode*())
        return;

    if (object != 0 && object->FUN_0048cee0() != 0)
    {
        DAT_011c3b3c->FUN_00444040(object->vfn_0014(0, 0, 0, 0, 0, 0));
        m_pPrecipitationData = object;
    }
    else
        Load(0);
}

// Release both handles and clear the cached object before destroying the members.
// @fnv 0x00636b20
Precipitation::~Precipitation()
{
    m_pPrecipitationNode = static_cast<NiNode*>(0);
    m_pPreviousNode = static_cast<NiNode*>(0);
    m_pPrecipitationData = 0;
}
