#pragma once

#include "NiRefObject.h"
#include <stddef.h>

class NiRTTI;

class BSFaceGenMorphData : public NiRefObject
{
public:
    struct Buffers
    {
        void* vertices;
        void* normals;
        void* tangents;
    };

    BSFaceGenMorphData();
    virtual ~BSFaceGenMorphData();

    virtual const NiRTTI* GetRTTI() const;
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();

    unsigned int DynamicCast();
    float NiControllerSequence_GetLastTime();

};
