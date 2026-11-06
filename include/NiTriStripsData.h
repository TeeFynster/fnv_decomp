#pragma once

#include "NiTriBasedGeomData.h"

class NiTriStripsData : public NiTriBasedGeomData
{
  public:
    NiTriStripsData();
    NiTriStripsData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*,
                    unsigned short, NiGeometryData__DataFlags, unsigned short,
                    unsigned short, unsigned short*, unsigned short*);
    NiTriStripsData(unsigned int, unsigned int, unsigned int, unsigned int,
                    unsigned int, unsigned int, unsigned int, unsigned int,
                    unsigned int, unsigned int, unsigned int);
    virtual ~NiTriStripsData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream&);
    virtual void SaveBinary(NiStream&);

    void EnsureNormals(int aiNumVertices);
    void GenerateNormals();

    unsigned short* GetTriangleStripData();
    void GetTriangleStripData(unsigned short&, const unsigned short*&, const unsigned short*&, unsigned int&);
    virtual bool IsEqual(NiObject* object) const;

    unsigned short m_usStrips;
    unsigned char layoutPadding46[2];
    unsigned short* m_pusStripLengths;
    unsigned short* m_pusStripLists;

    static const NiRTTI ms_kRTTI;
};
