#pragma once

#include "NiProperty.h"

class NiCullingProperty : public NiProperty
{
  public:
    virtual NiCullingProperty* MakeClone(CloningProcess& kCloning);
    virtual void LoadBinary(NiStream& stream);

    void FUN_00a5d7a0(void* destination, CloningProcess& kCloning);
    void FUN_00a5d7a0(NiCullingProperty* destination, CloningProcess& kCloning);
    NiCullingProperty* FUN_00a8f530(CloningProcess& kCloning);
    NiCullingProperty* FUN_00a9a5f0(CloningProcess& kCloning);
    void FUN_00a8f650(NiStream& stream);
    void FUN_00a99e00(void* destination, CloningProcess& kCloning);
    void FUN_00a81430(void* destination, CloningProcess& kCloning);

    unsigned short m_usFlags;
    unsigned short unk1A;
};
