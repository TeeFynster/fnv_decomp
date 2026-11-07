#pragma once

#include "NiProperty.h"

class NiCullingProperty : public NiProperty
{
  public:
    virtual NiCullingProperty* MakeClone(CloningProcess& kCloning);
    virtual void LoadBinary(NiStream& stream);

    void NiProperty_CopyMembers(void* destination, CloningProcess& kCloning);
    void NiProperty_CopyMembers(NiCullingProperty* destination, CloningProcess& kCloning);
    NiCullingProperty* CreateClone_00a8f530(CloningProcess& kCloning);
    NiCullingProperty* NiDitherProperty_CreateClone(CloningProcess& kCloning);
    void LoadBinary_00a8f650(NiStream& stream);
    void NiFogProperty_CopyMembers(void* destination, CloningProcess& kCloning);
    void NiShadeProperty_CopyMembers(void* destination, CloningProcess& kCloning);

    unsigned short m_usFlags;
    unsigned short unk1A;
};
