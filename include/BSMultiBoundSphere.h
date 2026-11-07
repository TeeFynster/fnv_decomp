#pragma once

#include "BSMultiBoundShape.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class BSMultiBound;
class CloningProcess;

class BSMultiBoundSphere : public BSMultiBoundShape
{
public:
    BSMultiBoundSphere();
    BSMultiBoundSphere(const NiPoint3& center, float radius);
    virtual ~BSMultiBoundSphere();

    NiPoint3 center;
    float radius;

    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual float GetRadius() const;
    virtual void SetGridPosition(const NiPoint3& center);

    BSMultiBoundSphere* CreateClone_00c4fb30(CloningProcess& kCloning);
    void CopyMembers_00c4fbc0(BSMultiBoundSphere* pkDest, CloningProcess& kCloning);

    void DestroyBase();
    static void _delete(void* p, unsigned int size);
    void* FUN_004a7bf0(unsigned int flags);
    void DestroyBase_Thunk();
    void CombatLocation_SetRadius(float radius);
    int CheckBound(BSMultiBound* bound);
};
