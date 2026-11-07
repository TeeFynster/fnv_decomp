#pragma once

#include "NiPoint3.h"

// BSAudioListener: abstract listener base, RTTI .?AVBSAudioListener@@, vftable 0x010a3bb4 (13 slots; slots 1, 2, 5
// and 8 are _purecall, 0x00aa7830 is the shared empty /Od body). BSWin32AudioListener (vftable 0x010a3b7c) derives
// from it. Layout from the /Od bodies: vptr at 0x00, position 0x04, velocity 0x10, forward 0x1C, up 0x28,
// flags 0x44 (written by slot 10, cleared by the slot-0 deleting destructor); size 0x48.
class BSAudioListener
{
public:
    virtual void* Destroy(unsigned int auiFlags);           // 0x00 0x00aeabb0
    virtual void vfn_4() = 0;                               // 0x04
    virtual void vfn_8(NiPoint3* pos) = 0;                  // 0x08
    virtual NiPoint3& GetPosition_00aeaad0();                       // 0x0C
    virtual void vfn_10();                                  // 0x10 0x00aa7830
    virtual void vfn_14(NiPoint3* front, NiPoint3* top) = 0; // 0x14
    virtual NiPoint3* GetFrontOrientation();                       // 0x18
    virtual NiPoint3& GetTopOrientation();                       // 0x1C
    virtual void vfn_20(NiPoint3* velocity) = 0;            // 0x20
    virtual void SetGain(float afGain);                // 0x24
    virtual void SetListenerID(unsigned int);               // 0x28 0x00aeab50
    virtual unsigned int GetListenerID();                   // 0x2C 0x00aeab70
    virtual void SetRolloffFactor(float afRolloffFactor);   // 0x30 0x00aeab90

    NiPoint3 m_kListenerPosition;    // +0x04
    NiPoint3 m_kListenerVelocity;    // +0x10
    NiPoint3 m_kForward;             // +0x1C
    NiPoint3 m_kUp;                  // +0x28
    unsigned int m_uiListenerID;     // +0x34
    float m_fGain;                   // +0x38
    float m_fDopplerScale;           // +0x3C
    float m_fDistanceScale;          // +0x40
    unsigned int m_uiListenerFlags;  // +0x44
};
