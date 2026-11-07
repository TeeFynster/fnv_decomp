// fallout_shared/bgsprimitive_decls.h: declares NiPoint3, NiColorA, NiBound, NiUpdateData, NiFixedString and more
#ifndef BGSPRIMITIVE_DECLS_H
#define BGSPRIMITIVE_DECLS_H
namespace std {
float abs(float);
}
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
    float& operator[](unsigned int);
    static const NiPoint3 ZERO;
};
#include "../../include/NiColorA.h"
class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
    NiBound();
    void SetCenterAndRadius(const NiPoint3&, float);
};
class NiUpdateData
{
  public:
    float m_fTime;
    unsigned int m_uiValue1;
    unsigned int m_uiUpdateIndex;
    NiUpdateData(float, bool, bool);
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
class NiGeometryData
{
  public:
    NiPoint3* GetVertices();
    NiColorA* GetColors();
    unsigned short GetVertexCount();
    void SetDirtyFlags(unsigned int);
};
#include "../../include/NiMemObject.h"
class NiAVObject : public NiMemObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
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
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void UpdateWorldBound();
    void Update(NiUpdateData&);
    void UpdateSceneObject();
    void SetName(const NiFixedString&);
};
class NiGeometry : public NiAVObject
{
  public:
    NiGeometryData* NiGeometry_GetModelData();
    void SetModelBound(const NiBound&);
    void SetAppCulled(bool);
};
class NiLines : public NiGeometry
{
};
class BSFadeNode : public NiAVObject
{
  public:
    char data[0xe0];
    BSFadeNode();
};
class BGSPrimitive
{
  public:
    BGSPrimitive();
    virtual ~BGSPrimitive();
    int eType;
    NiColorA Color;
    NiPoint3 m_kRadii;
    NiPointer<NiGeometry> m_kGeometry;
    NiPointer<NiLines> m_kLines;
    NiPointer<BSFadeNode> m_pController;
    unsigned int m_uiPrimitiveFlags;
};
class BGSPrimitiveBox : public BGSPrimitive
{
  public:
    BGSPrimitiveBox();
    virtual ~BGSPrimitiveBox();
    void* m_apBoxData[6];
    void NormalizeRadii(NiPoint3&);
    void SetColor(NiColorA&);
    void Build();
};
class BGSPrimitivePlane : public BGSPrimitive
{
  public:
    void SetColor(NiColorA&);
};
typedef char BGSPrimitive_size_check[sizeof(BGSPrimitive) == 0x34 ? 1 : -1];
typedef char BGSPrimitiveBox_size_check[sizeof(BGSPrimitiveBox) == 0x4c ? 1 : -1];
typedef char BSFadeNode_size_check[sizeof(BSFadeNode) == 0xe4 ? 1 : -1];
class bhkMultiSphereShape
{
  public:
    unsigned int GetInstanceSize();
};
#endif
