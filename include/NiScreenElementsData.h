#pragma once

#include "NiTriShapeData.h"

class NiScreenElementsData__Polygon;

class NiScreenElementsData : public NiTriShapeData
{
  public:

    NiScreenElementsData(bool, bool, unsigned short, int, int, int, int, int, int);
    virtual ~NiScreenElementsData();

    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual void GetViewerStrings(NiViewerStringsArray*);

    void NiScreenElementsData_UpdateBound();
    bool FUN_00a87ae0(int, int, int);
    bool FUN_00a88130(int, int, float, float, float, float);
    void FUN_00a67050(int);

    bool SetRectangle(int, float, float, float, float);
    bool SetRectangleBounds(int, unsigned short, float, float, float, float);
    bool SetRectangleBounds(int, float, float, float, float);

    NiScreenElementsData__Polygon* m_akPolygon;
    unsigned short* m_ausPIndexer;
    unsigned short m_usMaxPQuantity;
    unsigned short m_usPGrowBy;
    unsigned short m_usPQuantity;
    unsigned short m_usMaxVQuantity;
    unsigned short m_usVGrowBy;
    unsigned short m_usMaxIQuantity;
    unsigned short m_usIGrowBy;
    bool m_bGeometryInitialized;
    unsigned char layoutPadding6F[1];
};
