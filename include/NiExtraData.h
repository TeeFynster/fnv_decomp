#pragma once

#include "NiObject.h"
#include "NiFixedString.h"

class NiExtraData : public NiObject
{
  public:
    // With no arguments, __fastcall keeps this in ECX and uses a distinct symbol.
    __fastcall NiExtraData();
    NiExtraData(const NiFixedString& name);
    NiExtraData(BSFadeNode* node);
    virtual ~NiExtraData();

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsGeometryController();
    virtual bool IsCloneable();

    void SetName(const NiFixedString& name);
    void* CloneFloatExtraData(void* cloning);
    void BSXFlags_SetFlags(bool, bool);
    bool FUN_00448a40();
    bool BSXFlags_IsEditorMarker();
    void FUN_00a7b2e0();
    void DestroyFields_00a7b300();
    void CopyMembers_00a7b330(void* destination, void* cloning);
    void CopyMembers_00a7b330(void* destination, CloningProcess* cloning);
    void BSAttachPoints_LinkObject(NiStream& stream);


    NiFixedString m_kName;
};
