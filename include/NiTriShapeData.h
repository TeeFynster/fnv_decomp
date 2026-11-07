#pragma once

#include "NiTriBasedGeomData.h"

class NiTriShapeData__SharedNormalArray;
class NiTriShapeData__SNAMemBlock;

class NiTriShapeData : public NiTriBasedGeomData
{
  public:
    NiTriShapeData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*,
                   unsigned short, NiGeometryData__DataFlags, unsigned short,
                   unsigned short*) throw();
    NiTriShapeData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*,
                   unsigned short, unsigned int, unsigned short, unsigned short*);
    virtual ~NiTriShapeData();

    virtual void LoadBinary(NiStream&);
    virtual void SaveBinary(NiStream&);

    void EnsureNormals(bool bInitialize);
    void RecalculateNormals();
    unsigned short* GetTriangleList();
    bool IsEqual_00a7b7e0(const NiTriShapeData*);

    unsigned int m_uiTriListLength;
    unsigned short* m_pusTriList;
    NiTriShapeData__SharedNormalArray* m_pkSharedNormals;
    unsigned short m_usSharedNormalsArraySize;
    unsigned char _pad52[2];
    NiTriShapeData__SNAMemBlock* m_pkSNAMemoryBlocks;
};
