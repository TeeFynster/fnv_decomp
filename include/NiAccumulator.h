#pragma once

#include "NiObject.h"

class NiCamera;
class NiGeometry;
class NiVisibleArray;

class NiAccumulator : public NiObject
{
  public:
    virtual ~NiAccumulator();

    virtual void StartAccumulating(const NiCamera* pkCamera);
    virtual void FinishAccumulating();
    virtual void RegisterObjectArray(NiVisibleArray* pkVisibleArray);
    virtual bool RegisterObject(NiGeometry* pkGeom);
    virtual void vf9c();
    virtual void vfa0();

    void SetSortingCamera(const NiCamera* camera);
    void ClearCamera();

    const NiCamera* m_pkCamera;
};
