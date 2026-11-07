// Local light declarations pending the missing shared light/effect methods.
#ifndef FNV_NILIGHT_DECLS_H
#define FNV_NILIGHT_DECLS_H

#include "NiObjectNET.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "NiPoint3.h"
#include "nilight_types_NiStream.h"

class NiCollisionObject;
class FourComponentFloatVector;
class CloningProcess;
struct StrArr;

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value, sizeof(T));
}

struct NiLightTransform
{
    float m_kOrientation[9];
    NiPoint3 m_kTranslation;
    float m_fScale;
};

class NiAVObject : public NiObjectNET
{
  public:
    NiAVObject();
    virtual ~NiAVObject();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    void CopyMembers_00a5ac90(NiAVObject*, CloningProcess&);
    NiNode* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiProperty> > SceneGraphObject;
    unsigned int m_uiObjectFlags;
    NiLightTransform m_kLocalTransform;
    NiLightTransform m_kWorldSpaceTransform;
};

// The shared declaration lacks IsEqual, SaveBinary, and AppendEffectProperties.
class NiDynamicEffect : public NiAVObject
{
  public:
    NiDynamicEffect();
    bool IsEqual(NiObject*) const;
    void SaveBinary(NiStream&);
    void AppendEffectProperties(StrArr*);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    bool m_bEffectEnabled;
    unsigned char m_ucEffectCategory;
    int m_iIndex;
    unsigned int m_uiEffectPushCount;
    unsigned int m_uiRevID;
    NiTListBase<NiTPointerAllocator<unsigned int>, NiNode*> m_kEffectTargetNodes;
    NiTListBase<NiTPointerAllocator<unsigned int>, NiNode*> m_kAffectedNodes;
};

// The shared declaration lacks the link/save/equality and viewer-string overrides.
class NiLight : public NiDynamicEffect
{
  public:
    NiLight();
    const NiRTTI* GetRTTI() const;
    void DestroyMembers();
    void* Destroy(unsigned int);
    bool IsEqual(NiObject*) const;
    void AppendEffectProperties(StrArr*);
    void SaveBinary(NiStream&);
    void LinkObject(NiStream&);
    virtual void LoadBinary(NiStream&);
    void CopyMemberData(NiLight*, CloningProcess&);
    float m_fDimmer;
    NiColor m_kAmb;
    NiColor m_kDiff;
    NiColor m_kSpec;
    void* m_pMaterialData;
};

FNV_STATIC_ASSERT(sizeof(NiAVObject) == 0x9c);
FNV_STATIC_ASSERT(sizeof(NiDynamicEffect) == 0xc4);
FNV_STATIC_ASSERT(offsetof(NiDynamicEffect, m_iIndex) == 0xa0);
FNV_STATIC_ASSERT(offsetof(NiDynamicEffect, m_uiEffectPushCount) == 0xa4);
FNV_STATIC_ASSERT(offsetof(NiLight, m_fDimmer) == 0xc4);
FNV_STATIC_ASSERT(offsetof(NiLight, m_pMaterialData) == 0xec);
#endif
