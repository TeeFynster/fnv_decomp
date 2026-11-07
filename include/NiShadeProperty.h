#pragma once

#include "NiProperty.h"

class NiShadeProperty : public NiProperty
{
  public:
    NiShadeProperty();
    virtual ~NiShadeProperty();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& cloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    void CopyMemberData(NiShadeProperty* property, CloningProcess* cloning);
    void CopyMemberData(NiShadeProperty* property, CloningProcess& cloning);

    void SetField(unsigned short value, unsigned short mask, unsigned short shift);
    unsigned short GetField(unsigned short mask, unsigned short shift);
    void SetBit(bool value, unsigned short mask);
    bool GetBit(unsigned short mask);
    void SetSmooth(bool smooth);
    bool GetSmooth();
    bool IsEqualFast(void* property);
    bool IsEqualFast(const NiShadeProperty& property);
    int Type();
    int GetShaderType();
    int GetShaderPropertyType();
    int FUN_00441110();
    NiObject* CreateClone_00a81480(CloningProcess& cloning);
    void NiDitherProperty_LoadBinary(NiStream& stream);
    bool NiCullingProperty_IsEqual(NiObject* object);
    void SaveToStream(NiStream& stream);
    void* Destroy(unsigned int flags);
    void SetTexture(int slot, int index, void* texture);
    NiShadeProperty& operator=(const NiShadeProperty& property);

    static NiObject* CreateObject();
    static int GetType();
    static NiShadeProperty* GetDefault();
    static void InitializePoint3();
    static void ShutdownPoint3();

    unsigned short m_uFlags;
    unsigned char _pad1A[2];
    int iShaderPropertyType;
};
