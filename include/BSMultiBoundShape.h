#pragma once

#include "NiObject.h"
#include "NiPlane.h"
#include "NiPoint3.h"

class BSMultiBound;
class NiPoint3;
class SphereBound;
class Vec57;

class BSMultiBoundShape : public NiObject
{
public:
    BSMultiBoundShape();

    virtual int GetShapeType();
    virtual float GetRadius() const;
    virtual int FUN_00c369b0(BSMultiBound* p);
    virtual int v98(SphereBound* b);
    virtual void vf39();
    virtual void vf40();
    virtual void va4(SphereBound* b);
    virtual void vf42();
    virtual void vf43();
    virtual int FUN_004a7030();
    virtual bool FUN_00c50380(NiPoint3* other);
    virtual void SetGridPosition(const NiPoint3& center);

    int v8c();
    void GetPlanes(NiPlane* planes);
    void center(const Vec57& center);
    void update();
    void FUN_00c39270(NiPoint3* pts);
    void FUN_00c37a00(NiPoint3* pts);

    union
    {
        unsigned int m_uiShapeType;
        unsigned int flags;
        int unk08;
    };
};
