#pragma once

#include "NiMemObject.h"

class NiGeometryBufferData;
class NiGeometryData;
class NiScreenTexture;

class NiGeometryGroup : public NiMemObject
{
public:
    NiGeometryGroup();

    virtual void Purge();
    virtual void vf01(NiScreenTexture*);
    virtual void vf02();
    virtual void vf03(NiGeometryData*);
    virtual void vf04(void*);
    virtual void vf05(NiGeometryData*);
    virtual void vf06();
    virtual void vf07(NiGeometryBufferData*, unsigned int);
    virtual void vf08();
    virtual ~NiGeometryGroup();

    void RemoveObject(NiGeometryBufferData*);
    void RemoveAndDeleteBuffer(NiGeometryData*);

    unsigned int m_uiRefCount;
    void* m_pD3DDevice;
};
