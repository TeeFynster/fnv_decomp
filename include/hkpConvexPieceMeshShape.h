#pragma once

#include "hkpShapeCollection.h"

class hkpConvexPieceStreamData;

class hkpConvexPieceMeshShape : public hkpShapeCollection
{
public:
    virtual void calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const;
    void CollectShapeStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();

    hkpConvexPieceStreamData* m_pConvexPieceStreamData;
    hkpShapeCollection* m_pDisplayMesh;
    hkReal m_fSphereRadius;
};
