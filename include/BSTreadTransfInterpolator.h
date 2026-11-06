#pragma once

#include "NiKeyBasedInterpolator.h"
#include "NiAVObject.h"

class TreadTransformEntry;

class BSTreadTransfInterpolator : public NiKeyBasedInterpolator
{
  public:
    BSTreadTransfInterpolator() throw();
    virtual ~BSTreadTransfInterpolator();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual bool UpdateTransform(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);

    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void vf57();
    virtual void vf58();
    virtual NiAnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;
    virtual void vf61(unsigned short usChannel);

    void CopyMembers(BSTreadTransfInterpolator* destination, void* context);
    BSTreadTransfInterpolator* FUN_00a439e0(void* kCloning);
    void FUN_00a43690(BSTreadTransfInterpolator* pkDest, void* kCloning);
    bool UpdateSampleValue(float time, int, int);
    void* FUN_00a43580(unsigned short flag);
    bool FUN_00a435e0(int arg);
    void* FUN_00a43a50(unsigned int flags);

    TreadTransformEntry* entries;
    unsigned int count;
    float firstValue;
    float secondValue;
    unsigned int unk1c;
    NiPointer<NiObject> reference;
};
