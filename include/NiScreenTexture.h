#pragma once

#include "NiStream.h"
#include "NiObject.h"
#include "NiTexturingProperty.h"

class RendererDataRecord;

class NiScreenTexture : public NiObject
{
public:
    virtual ~NiScreenTexture();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual bool RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;

    bool FUN_00a954f0(NiStream&);
    void LinkTexturingProperty(NiStream&);
    void __thiscall ReleaseReference_00a95590();
    void* __thiscall FUN_00a95740(unsigned int);

    RendererDataRecord* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    NiTexturingProperty* m_pTexturingProperty;
    unsigned short flags;
    unsigned short unk1A;
    void* m_pkGeometryRendererData;
};
