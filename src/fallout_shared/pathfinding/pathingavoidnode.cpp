// fallout_shared/pathfinding/pathingavoidnode.cpp: NavMesh, NavMeshTriangleReference, AvoidNodeList (4 functions)

#include "pathingavoidnode_decls.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NavMesh.h"
#include "../../../include/PathingAvoidNode.h"
// @fnv 0x005582f0
NavMeshTriangle* NavMesh::GetTriangle(unsigned short index)
{
    return &Triangles.GetAt(static_cast<unsigned int>(index));
}
// @fnv 0x006a78d0
// src: XBOX_PDB 0x006a78d0
NavMeshTriangle* NavMeshTriangleReference::NavMeshSearchNode_GetTriangle() const
{
    return m_pLocationNavMesh->GetTriangle(m_usTriangleIdentifier);
}

typedef char _sizecheck_PathingAvoidNode[sizeof(PathingAvoidNode) == 36 ? 1 : -1];

// Reads a type byte, two floats and a 12-byte block from the load buffer, plus a second 12-byte block when the type is 1.
// @fnv 0x006dc910
void PathingAvoidNode::LoadPathingAvoidNode(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ctype = 0;
    apLoadGameBuffer->ReadTypedData(&ctype, 1u);
    eType = ctype;
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fRadius), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&m_fPathingCostCur), 4u);
    apLoadGameBuffer->ReadTypedData(&m_kLocation, 12u);
    if (eType == 1)
    {
        apLoadGameBuffer->ReadTypedData(&TwoComponentVector, 12u);
    }
}

extern NiPoint3 NiPoint3_ZERO;

struct AvoidNodeList
{
    unsigned int GetCount();
    PathingAvoidNode* GetAt(unsigned int);
    float PathingAvoidNodeArray_ComputeCenter(const NiPoint3& point, NiPoint3& outDir);
};

// @fnv 0x006dc9f0
// src: COMMUNITY 0x006dc9f0
float AvoidNodeList::PathingAvoidNodeArray_ComputeCenter(const NiPoint3& point, NiPoint3& outDir)
{
    float fValueSum = 0.0f;
    outDir = NiPoint3_ZERO;
    float fCostSum = 0.0f;
    unsigned int count8 = GetCount();
    if (count8 > 0)
    {
        for (unsigned int aI = 0; aI < count8; aI++)
        {
            PathingAvoidNode* pNode = GetAt(aI);
            float fCost3 = pNode->m_fPathingCostCur;
            NiPoint3 closestPoint = pNode->m_kLocation;
            if (pNode->eType == 1)
            {
                NiPoint3 segmentDir = pNode->TwoComponentVector - pNode->m_kLocation;
                NiPoint3 toPoint = point - pNode->m_kLocation;
                float fDot = toPoint.Dot(segmentDir);
                if (fDot < 0.0)
                {
                    closestPoint = pNode->m_kLocation;
                }
                else if (fDot > segmentDir.SqrLength())
                {
                    closestPoint = pNode->TwoComponentVector;
                }
                else
                {
                    float fSegLen = segmentDir.GetLen();
                    closestPoint = pNode->m_kLocation + (segmentDir * fDot).Divide(fSegLen);
                }
            }
            outDir += closestPoint * fCost3;
            fValueSum += pNode->fRadius;
            fCostSum += fCost3;
        }
        outDir.DivideBy(fCostSum);
    }
    return fValueSum;
}
