#pragma once

#include "NiFloatInterpController.h"
#include "NiTexturingProperty.h"

class NiAlphaController;
class NiTexture;
class NiUpdateDataF;

class NiFlipController : public NiFloatInterpController
{
public:
    NiFlipController();
    virtual ~NiFlipController() throw();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void Update(NiUpdateData& update);
    virtual const char* GetControllerID() const;
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                     bool accumulateAnimations, float threshold, unsigned char size);
    virtual bool TargetIsRequired(NiObjectNET* object) const;
    virtual void UpdateFloatValue(float* value);

    void* __thiscall FUN_00a4f820();
    void* GetEntryAt(int index);
    const char* __thiscall GetFormattedValue();
    void* GetSrc(unsigned int index);
    void __thiscall AttachTexture(void* texture, unsigned int index);
    void __thiscall CopyMembers_00a4f920(NiAlphaController* clone, CloningProcess& process);
    bool __thiscall RegisterStreamables_00a4f350(NiStream& stream);
    void* CreateFlipController(CloningProcess& process);
    void __thiscall GetFloatValue(float* value);
    unsigned char __thiscall IsEqual_00a4f290(NiFlipController* object);
    void __thiscall SaveToStream(NiStream* stream);
    void UpdateFlipController(NiUpdateDataF& update);
    void __thiscall LoadFromStream(NiStream* stream);
    void __thiscall LinkObject_00a4f990(NiStream& stream) throw();
    void CopyMemberData(NiFlipController* clone, CloningProcess& process);
    unsigned short GetField(unsigned short mask, unsigned short position) const;
    bool GetManagerControlled() const;
    bool AdvanceController(float time);

    NiTPrimitiveArray<NiPointer<NiTexture> > m_kTextureSwapList;
    unsigned int m_uiPosition;
    unsigned int m_eAffectedMap;
    void* m_pkBuf;
};
