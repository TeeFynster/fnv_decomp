#pragma once

#include "NiFloatInterpController.h"

class NiTexturingProperty__Map;

enum NiTextureTransformController__TransformMember
{
    NiTextureTransformController__TransformMember_TT_TRANSLATE_U = 0,
    NiTextureTransformController__TransformMember_TT_TRANSLATE_V = 1,
    NiTextureTransformController__TransformMember_TT_ROTATE = 2,
    NiTextureTransformController__TransformMember_TT_SCALE_U = 3,
    NiTextureTransformController__TransformMember_TT_SCALE_V = 4
};

class NiTextureTransformController : public NiFloatInterpController
{
public:
    unsigned int m_uiLastKeyIndex;
    NiTexturingProperty__Map* m_pTaskMap;
    bool m_bIsBumpMap;
    unsigned char layoutPadding41[3];
    unsigned int m_uiTextureMapIndex;
    NiTextureTransformController__TransformMember m_eTransformMember;
    mutable char* m_pCachedControllerID;

    virtual const char* GetControllerID() const;
    virtual void Update(NiUpdateData& data);
    bool IsTextureMapValid();
    NiTextureTransformController(NiObjectNET* property, NiTexturingProperty__Map* map,
                                 NiTextureTransformController__TransformMember member) throw();
};

