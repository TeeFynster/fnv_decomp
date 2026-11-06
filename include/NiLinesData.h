#pragma once

#include "NiGeometryData.h"

class NiLinesData : public NiGeometryData
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* other) const;
    virtual void GetViewerStrings(NiViewerStringsArray* arr);

    void* Destroy(unsigned int flags);
    bool IsGeometryEqual(NiObject* other) const;
    void RegisterGeometryFields(NiViewerStringsArray* arr);

    unsigned char* m_pkFlags;
};
