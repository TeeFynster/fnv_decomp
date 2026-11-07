#pragma once

#include "NiTransformInterpolator.h"
#include "NiQuaternion.h"

class TimedRotationKey;

class BSRotAccumTransfInterpolator : public NiTransformInterpolator
{
public:
    virtual ~BSRotAccumTransfInterpolator();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);
    virtual bool IsEqual(NiObject*) const;
    virtual bool UpdateTransform(float, NiObjectNET*, NiQuatTransform&);

    void __vslot_0();
    bool Update(float, NiObjectNET*, NiQuatTransform*);
    void CopyMemberData(BSRotAccumTransfInterpolator*, CloningProcess*);
    void __local_vftable_ctor_closure();
    static NiObject* CreateObject();
    void FUN_00a40360(BSRotAccumTransfInterpolator*, int);
    BSRotAccumTransfInterpolator* CreateInterpolator(int);
    void j_j_j_nullsub_3(int);
    void UpdateRotValue(int);
    void BaseCleanup();
    BSRotAccumTransfInterpolator* FUN_00a43df0(unsigned char);
    TimedRotationKey* GetRotData(unsigned int&, int&, unsigned char&) const;

    NiQuaternion m_kAccumulatedRotation;
};
