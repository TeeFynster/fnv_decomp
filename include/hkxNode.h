#pragma once

#include "hkxAttributeHolder.h"
#include "hkStringPtr.h"

struct SceneMatrix;
struct SceneAnnotation;

class hkxNode : public hkxAttributeHolder
{
public:
    hkStringPtr name;
    hkReferencedObject* object;
    hkArray<SceneMatrix> keyFrames;
    hkArray<hkxNode*> children;
    hkArray<SceneAnnotation> annotations;
    hkStringPtr userProperties;
    bool selected;
    bool bone;

    explicit hkxNode(FinishingFlag flag) throw();
    virtual ~hkxNode() throw();
};
