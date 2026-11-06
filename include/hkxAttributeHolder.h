#pragma once

#include "FinishingFlag.h"
#include "hkReferencedObject.h"

class SceneAttribute;

#include "hkArray.h"

class hkxAttributeHolder : public hkReferencedObject
{
public:
    hkArray<SceneAttribute> attributes;

    explicit hkxAttributeHolder(FinishingFlag flag) throw();
};
