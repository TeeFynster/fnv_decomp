#pragma once

#include "NiObject.h"
#include "NiBound.h"
#include "NiAVObject.h"
#include "NiPoint2.h"
#include "NiColorA.h"

class NiAdditionalGeometryData;
class GeometryBufferView;
class GeometryVertexBuffer;
class TangentPoint3;
template <class T> class LayoutNiPointer;

enum NiGeometryData__DataFlags
{
    DataFlags_None = 0
};

class NiGeometryData : public NiObject
{
  public:
    class RendererData
    {
      public:
        virtual ~RendererData();
    };

    enum Consistency
    {
        MUTABLE = 0,
        STATIC = 16384,
        VOLATILE = 32768,
        CONSISTENCY_MASK = 28672
    };

    enum DataFlags
    {
        NBT_METHOD_NONE = 0,
        NBT_METHOD_NDL = 4096,
        NBT_METHOD_DEPRECATED = 8192,
        NBT_METHOD_ATI = 12288,
        NBT_METHOD_MASK = 61440,
        TEXTURE_SET_MASK = 1
    };

    NiGeometryData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*,
                   unsigned short, NiGeometryData__DataFlags);
    virtual ~NiGeometryData();

    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual void SaveBinary(NiStream&);

    virtual void vf35();
    virtual unsigned short GetVertexCount();
    virtual void vf37();
    virtual void vf38();
    virtual bool ContainsVertexData(int);
    virtual void vf40();

    void SetDataConsistency(Consistency);
    void SetDataConsistency(int);
    void SetDirtyFlags(unsigned int);
    void SetCompressFlags(unsigned char);
    void SetCompressFlags(unsigned int);
    bool IsGeometryDataStreamable(bool);
    bool HasAdditionalGeometryData(unsigned int);
    void SetByteAtOffset38(int);
    void SetByteAtOffset38(unsigned char);
    void IncRefCount();
    void DecRefCount();
    void* GetSharedObject();
    void CreateCopy(NiPointer<NiGeometryData>*);
    void CreateCopy(LayoutNiPointer<NiGeometryData>*);
    NiPoint3* GetVertices();
    NiColorA* GetColors();
    unsigned short GetVertexCount() const;
    unsigned short GetUVSetCount() const;

    int GetConsistency_00457b80();
    void FUN_004410f0(int);
    NiPoint2* NiGeometryData_GetTextureSet(unsigned short);
    unsigned short* FUN_00a75f10();
    void NiGeometryData_ReplaceData(unsigned short, TangentPoint3*, TangentPoint3*, NiColorA*,
                      NiPoint2*, unsigned short, unsigned int);
    void FUN_00a67050(int);
    void NiGeometryData_UnlockPackedVertexData();
    void NiGeometryData_GetVerticesIterator(GeometryBufferView&);
    void NiGeometryData_GetVerticesIterator(GeometryVertexBuffer&);

    unsigned short m_usVertices;
    unsigned short m_usID;
    unsigned short m_usDataFlags;
    unsigned short m_usDirtyFlags;
    NiBound m_kBound;
    NiPoint3* m_pkVertex;
    NiPoint3* m_pkNormal;
    NiColorA* m_pkColor;
    NiPoint2* m_pkTexture;
    NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData;
    void* m_pkBuffData;
    unsigned char m_ucKeepFlags;
    unsigned char m_ucCompressFlags;
    bool m_bVBLocked;
    bool m_bVBLockWrite;
    bool m_bSaveVertexData;
    unsigned char _pad3D[3];
};
