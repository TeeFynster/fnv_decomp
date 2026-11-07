#pragma once

#include "BSTempEffect.h"
#include "NiAVObject.h"
#include "NiPoint3.h"

class Aux30;
class Obj4;
class SubDef;
class NiPoint3;
class Pt3Obj;
class Obj4c;
class DGeometry;
class DPoint;
class DBone;
class DNewPartition;

template <class T> class NiPointer;

class BSTempEffectGeometryDecal : public BSTempEffect
{
public:
    BSTempEffectGeometryDecal(int a1, float a2, const Aux30* a3, Obj4* a4,
                             SubDef a5, SubDef a6, float a11, float a12,
                             unsigned int a13);
    virtual ~BSTempEffectGeometryDecal();

    virtual const NiRTTI* GetRTTI() const override;
    virtual void Initialize() override;
    virtual bool Update(float afTime) override;
    virtual NiAVObject* Get3D() override;
    virtual int GetType() override;
    virtual bool IsSaveable() override;
    virtual unsigned short GetSaveSize() override;
    virtual void SaveGame() override;
    virtual bool LoadGame() override;

    NiPointer<BSTempEffect> operator*();

    void BuildSkinPartitions();
    void BuildDecalGeometry();
    void CreateDecalGeometry(DGeometry* geom, unsigned short ausVertexCount,
                             unsigned short ausIndexCount, DPoint* apVertices,
                             DPoint* d, unsigned short* apIndices, DBone* bone,
                             DNewPartition* apNewPartition, unsigned short* apPartMap);
    void CreateDecalGeometry(const char* s, int a, int b, Pt3Obj* c, Pt3Obj* d,
                             unsigned short* e, Obj4c* f, void* g, unsigned short* h);
    bool ShouldAddTriangle(int triangle, int base, bool strip,
                      const unsigned short* indices, const NiPoint3* vertices,
                      const unsigned short* remap);
    bool ShouldAddTriangle(int triangle, int base, bool strip,
                      const unsigned short* indices, const DPoint* vertices,
                      const unsigned short* remap);
    unsigned char ShouldAddTriangle(int a, int b, bool c, unsigned short* d,
                               Pt3Obj* e, int f);

    void Smooth();
    void Straighten();
    void Finalize();
    void FinalizePath();
    unsigned short GetRuntimeFlags();

    const NiRTTI* GetRTTI_006838a0() const;
    void* FUN_006838d0(unsigned int flags);
    bool FUN_006828a0(float f);
    void FUN_00688770();
    bool Update_006888a0(float f);
    void SaveGameTES_00688b00();
    bool LoadGameTES_00688c90();

    unsigned int unk18;
    NiPointer<NiAVObject> m_spGeometry;
    int unk20;
    char* m_pData;
    unsigned char unk28;
    unsigned char unk29[3];
    NiPointer<NiAVObject> m_sp2C;
    NiPointer<NiAVObject> m_sp30;
    NiPointer<NiAVObject> m_sp34;
    NiPoint3 m_38;
    NiPoint3 m_44;
    float m_50;
    float m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
};
