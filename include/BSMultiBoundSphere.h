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

    BSMultiBoundSphere* FUN_00c4fb30(CloningProcess& kCloning);
    void FUN_00c4fbc0(BSMultiBoundSphere* pkDest, CloningProcess& kCloning);

    void DestroyBase();
    static void _delete(void* p, unsigned int size);
    void* FUN_004a7bf0(unsigned int flags);
    void FUN_004a7130();
    void FUN_00819a50(float radius);
    int FUN_00c4ff60(BSMultiBound* bound);
};
