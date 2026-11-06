#pragma once

#include "NiTriBasedGeom.h"
#include "NiGeometryData.h"
#include "NiTriShapeData.h"

class NiStream;
class NiPoint3V;
class SkyShaderProperty;
class ObjC;
class ObjD;
class NineDw;

enum NiGeometryDataFlags
{
    NI_GEOM_DATA_DEFAULT = 0
};

class NiTriShape : public NiTriBasedGeom
{
  public:
    NiTriShape(unsigned int data);
    NiTriShape(unsigned short vertices, NiPoint3* vertex, NiPoint3* normal, void* color,
               NiPoint2* texture, unsigned short textureSets, unsigned int nbtMethod,
               unsigned short triangles, unsigned short* triangleList);
    NiTriShape(unsigned short vertices, NiPoint3* vertex, NiPoint3* normal, void* color,
               void* texture, unsigned short textureSets, unsigned int nbtMethod,
               unsigned short triangles, unsigned short* triangleList);
    NiTriShape(unsigned short vertices, NiPoint3V* vertex, NiPoint3V* normal, NiColorA* color,
               NiPoint2* texture, unsigned short textureSets, unsigned int nbtMethod,
               unsigned short triangles, unsigned short* triangleList);
    NiTriShape(unsigned short vertices, NiPoint3* vertex, NiPoint3* normal, NiColorA* color,
               NiPoint2* texture, unsigned short textureSets, NiGeometryDataFlags nbtMethod,
               unsigned short triangles, unsigned short* triangleList);
    NiTriShape(unsigned short vertices, NiPoint3* vertex, NiPoint3* normal, NiColorA* color,
               NiPoint2* texture, unsigned short textureSets, NiGeometryData__DataFlags nbtMethod,
               unsigned short triangles, unsigned short* triangleList);

    NiTriShape(unsigned short vertices, NiPoint3* vertex, NiPoint3* normal, NiColorA* color,
               NiPoint2* texture, unsigned short textureSets, int nbtMethod,
               unsigned short triangles, unsigned short* triangleList,
               int arg10, int arg11, int arg12, int arg13);

    virtual ~NiTriShape();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiTriShape* IsTriShape() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void RenderImmediate(NiRenderer* renderer);
    virtual void RenderWithRenderer(NiRenderer* renderer);
    virtual void GetTrianglePoints(unsigned short triangle, NiPoint3** a, NiPoint3** b, NiPoint3** c);

    static NiObject* CreateObject();

    void CopyMemberData(NiTriShape* source, CloningProcess* process);
    unsigned int GetTriListLength();
    unsigned short* GetTriangleList();
    void AssignFixedString(const NiFixedString& name);
    void SetName(const NiFixedString& name);
    void AttachProperty(NiObject* property);
    SkyShaderProperty* GetProperty(unsigned int type);
    void FUN_00439410(void* property);
    void FUN_00439410(NiObject* property);
    void FUN_0043fa80(int rotation);
    void FUN_0043fa80(const void* rotation);
    using NiTriBasedGeom::FUN_0043fa80;
    void FUN_00440460(int position);
    using NiTriBasedGeom::FUN_00440460;
    void FUN_00440490(float scale);
    void FUN_004902f0(bool value);
    void FUN_004adde0(ObjD* data);
    void FUN_004bc1f0(float x, float y, float z);
    void FUN_004f00e0(int value);
    using NiTriBasedGeom::FUN_004f00e0;
    void* FUN_005495f0(ObjC* data, int a, int b, int d, int e, int f, int g);
    void FUN_00635fe0(bool value);
    void FUN_00688430(NineDw* transform);
    void FUN_00a5a040();
    void SetValue(float value);
    NiBound* GetSourceFilesFromForm();
    void Method58();
    void __local_vftable_ctor_closure();
};

typedef char NiTriShape_size_check[(sizeof(NiTriShape) == 196) ? 1 : -1];
