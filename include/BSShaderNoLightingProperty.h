#pragma once

#include "BSShaderProperty.h"
#include "NiAVObject.h"
#include "NiTexturingProperty.h"
#include "TESFullName.h"

class NiTexture;

// PC layout (0x80): every allocation site pushes 0x80 before calling the constructor at 0x00b6fc90, which runs
// BSShaderProperty's constructor (0x00ba8e50, base size 0x60), sets the vtable 0x010ae670 (NiRTTI
// "BSShaderNoLightingProperty" at 0x011fa05c), clears +0x60 and the string at +0x64, stores clamp mode 3 at +0x6c and
// zeroes the four falloff floats at +0x70..+0x7c. The destructor (0x00b6fd30) releases +0x60 as a reference-counted
// pointer and frees +0x64 as a BSStringT; GetViewerStrings (0x00b6ff20) prints "base texture" from +0x60 and the
// "falloff start/stop angle/opacity" values from +0x70..+0x7c.
class BSShaderNoLightingProperty : public BSShaderProperty
{
  public:
    BSShaderNoLightingProperty();
    virtual ~BSShaderNoLightingProperty();

    NiTexture* GetBaseTexture()
    {
        return reinterpret_cast<NiPointer<NiTexture>*>(&kBaseTextureName.sLen)->m_pObject;
    }
    NiObject* MakeClone(CloningProcess& process);                                   // 0x00b6fe00
    void CopyMembers(BSShaderNoLightingProperty* dest, CloningProcess& process);    // 0x00b6f540
    static NiObject* CreateObject();                                                // 0x00b6fe80

    NiPointer<NiTexture> spBaseTexture;          // +0x60
    BSStringT<char> kBaseTextureName;            // +0x64
    NiTexturingProperty::ClampMode eClampMode;   // +0x6c
    float fFalloffStartAngle;                    // +0x70
    float fFalloffStopAngle;                     // +0x74
    float fFalloffStartOpacity;                  // +0x78
    float fFalloffStopOpacity;                   // +0x7c
};
