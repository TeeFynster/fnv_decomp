// fallout/ai/highactorculler.cpp: HighActorCuller (1 function)

#include "../../../include/BSFadeNodeCuller.h"
#include "../../../include/BSMultiBoundNode.h"
#include "../../../include/BSMultiBoundSphere.h"
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/BSPortalGraph.h"
#include "../../../include/HighActorCuller.h"
#include "../../../include/MobIterOperator.h"
#include "../../../include/MobileObject.h"
#include "../../../include/NiBound.h"
#include "../../../include/NiCamera.h"
#include "../../../include/NiCullingProcess.h"
#include "../../../include/NiFrustumPlanes.h"
#include "../../../include/NiPlane.h"
#include "../../../include/TES.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESWorldSpace.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/TESObjectCELL.h"

extern TES* g_TES;

#include <string.h>
#pragma intrinsic(memcpy)

// @fnv 0x008d6d40
void HighActorCuller::Operate(MobileObject* mobile)
{
    NiAVObject* object = mobile->Get3DSimple();
    if (object)
    {
        m_kFadeNodeCuller.Process(object);
        BSFadeNode* fade = object->IsFadeNode();
        if (fade && !fade->NiNode_QNotVisible())
        {
            // Preserve the original trivial snapshot; NiBound has an out-of-line copy constructor.
            unsigned __int64 bound[sizeof(NiBound) / sizeof(unsigned __int64)];
            memcpy(bound, &static_cast<const NiAVObject*>(fade)->GetBoundingVolume(), sizeof(bound));
            m_spMultiBoundSphere->SetGridPosition(reinterpret_cast<const NiBound*>(bound)->GetNavMeshData());
            m_spMultiBoundSphere->CombatLocation_SetRadius(reinterpret_cast<const NiBound*>(bound)->FUN_0084d030());
            BSPortalGraph* graph = 0;
            if (g_TES->GetInteriorCell())
                graph = g_TES->GetInteriorCell()->GetPortalGraph_009d9f20();
            else if (g_TES->GetParentWorldSpace())
                graph = g_TES->GetParentWorldSpace()->TESPackage_GetOnChangeIdle();
            if (graph)
            {
                NiTPointerList<BSOcclusionPlane*>& occluders = graph->GetOccluderList();
                void* position = occluders.GetHeadPos();
                while (position)
                {
                    BSOcclusionPlane* plane = occluders.GetNext(position);
                    if (plane && static_cast<const BSOcclusionPlane*>(plane)->GetCullResult() == 1)
                    {
                        if (!m_pMultiBoundNode->CheckProcStateAndPlane(m_kFadeNodeCuller.GetCamera()->NiAVObject_GetWorldTranslate(),
                                                                       m_kFadeNodeCuller, plane))
                            fade->SetTaskFlag(true);
                    }
                }
            }
        }
    }
}
