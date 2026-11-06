// Authored declaration for the Nif particle color modifier.
#ifndef FNV_NIPSYSCOLORMODIFIER_H
#define FNV_NIPSYSCOLORMODIFIER_H

#include "../../../../include/NiStream.h"
#include "../../../../include/NiPSysModifier.h"

class NiColorData;

#pragma pack(push, 4)
class NiPSysColorModifier : public NiPSysModifier
{
  public:
    NiPSysColorModifier() throw();
    virtual ~NiPSysColorModifier();

    virtual NiObject* MakeClone(CloningProcess& kCloning);
    virtual void GetViewerStrings(NiViewerStringsArray* pkStrings);
    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual bool IsEqual(NiObject* pkObject) const;
    virtual void Update(float fTime, NiPSysData* pkData);

    NiColorData* GetColorData();
    void SetColorData(NiColorData* pkColorData);
    void RefreshColorTimeBounds();

  protected:
    NiPointer<NiColorData> m_spColorData;  // +0x18
    float m_fLoKeyTime;                    // +0x1c
    float m_fHiKeyTime;                    // +0x20
};
#pragma pack(pop)
#endif
