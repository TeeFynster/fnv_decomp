#pragma once

#include "BSTempEffect.h"
#include "BSSimpleArray.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "NiPlane.h"
#include "NiColor.h"

class RenderQuery;
class BSRenderedTexture;
class BGSTextureSet;
class NiPoint2;
class NiColorA;
class BGSDecalNode;
class QueuedFile;
class TESTopicInfoData;
class DecalData;
class NiPoint3;
class NiPoint3;
class DecalPoint;
struct DecalPointRecord;
class Geometry;
class Param;

class BSTempEffectSimpleDecal : public BSTempEffect
{
  public:
    BSTempEffectSimpleDecal(int p1, float afLifetime, DecalData* pData);
    virtual ~BSTempEffectSimpleDecal();
    virtual const NiRTTI* GetRTTI() const;
    virtual void Initialize();
    virtual bool Update(float afTime);
    virtual NiAVObject* Get3D();

    bool ReleaseTextureObject();
    bool CreateDecalTexture();
    void SetDecalTint(NiColorA& color, bool enabled);
    bool GetByteAt2D();
    TESTopicInfoData* BSTempEffectSimpleDecal_GetDecalParent();
    void CleanUpMemory();
    bool AddDecalGeometry(int count, int* indices, NiPoint3* positions,
                          const NiPoint3* attributes);
    bool AddDecalGeometry(int count, int* indices, DecalPoint* positions,
                          DecalPoint* attributes);
    bool AddDecalGeometry(int count, unsigned int* indices, NiPoint3* positions,
                          NiPoint3* attributes);
    void ProcessDecalTriangles(NiAVObject* object);
    void ProcessDecalTriangles(Geometry* geometry);
    void ProcessDecalTriangles(Param* object);
    bool ProcessGeometry(NiAVObject* object);
    bool ProcessGeometry(unsigned int object);
    bool ProcessGeometry(Param* object);
    int CreateTriData_0068ca90();
    void ResizeMeshBuffers();
    int ClipPolygonByPlanes(int count, const int* indices, const NiPoint3* positions,
                            const NiPoint3* attributes, int* outIndices,
                            NiPoint3* outPositions, NiPoint3* outAttributes);
    int ClipPolygonByPlanes(int count, float* apInVerts, NiPoint3* apInB, NiPoint3* apInC,
                            float* apOutB, NiPoint3* apOutPos, NiPoint3* apOutC);
    int ClipPolygonByPlanes(int count, unsigned int* indices, NiPoint3* positions,
                            NiPoint3* attributes, unsigned int* outIndices,
                            NiPoint3* outPositions, NiPoint3* outAttributes);

    static void QueueDecalDataFile();
    static void UnloadDecalData();
    static int ClipPolygonToPlane(NiPlane* plane, int count, const int* indices,
                                  const NiPoint3* positions, const NiPoint3* attributes,
                                  int* outIndices, NiPoint3* outPositions,
                                  NiPoint3* outAttributes);
    static int ClipPolygonToPlane(void* plane, int count, NiPoint3* inPositions,
                                  float* inAttributes, NiPoint3* inVectors,
                                  float* outAttributes, NiPoint3* outPositions,
                                  NiPoint3* outVectors);
    static NiPointer<QueuedFile> ms_pPreloadDecalDataFile;

    bool bWasPlaying;
    bool m_bTextureDirty;
    bool m_bNeedsManagerUpdate;
    bool m_bDecalRenderingEnabled;
    RenderQuery* m_pRenderQuery;
    NiPointer<BSRenderedTexture> m_pDecalRenderTexture;
    unsigned int m_uiTextureReferenceCount;
    NiPointer<NiAVObject> m_pSceneObject;
    bool bPermanent;
    bool m_bSecondObjectFlag;
    bool TexturedObjectPlacementInfo;
    unsigned char layoutPadding2F[1];
    BGSTextureSet* m_pTextureSet;
    NiPoint3 pOrigin;
    NiPoint3 m_kSecondVertex;
    NiPoint3 m_kThirdPoint;
    NiPoint3 m_kFourthPoint;
    NiPlane m_akFacePlanes[6];
    int m_iFirstValueAfterPlanes;
    int m_iSecondValueAfterPlanes;
    NiPoint3* m_pFirstPoint3Array;
    NiPoint3* m_pVertexNormals;
    NiPoint3* m_pThirdPoint3Array;
    NiPoint3* m_pVertexBitangents;
    NiPoint2* m_pPrimaryTextureCoordinates;
    NiPoint2* m_pSecondaryTextureCoordinates;
    NiColorA* m_pFirstElementArray;
    NiColorA* NavMeshGeometryBuffers;
    unsigned short* m_pFirstUnsignedShortArray;
    unsigned short* m_pSecondUnsignedShortArray;
    short* m_pSignedShortArray;
    // A single collection retains array decay for buffer access.
    BSSimpleArray<DecalPointRecord*> m_aucByteBuffer[1];
    BGSDecalNode* m_pDecalNode;
    NiPointer<NiAVObject> m_pTargetNode;
    float fScale;
    float fPathHeading;
    float m_fGlyphWidthInPixels;
    float m_fGlyphExtent;
    float m_fProjectionDepth;
    unsigned char m_ucByteAfterFloats;
    bool m_bFlagBeforeFloat;
    unsigned char layoutPadding126[2];
    float m_fFloatBeforeScalarFlagState;
    unsigned char ScalarFlagState;
    bool m_bFirstBooleanFlag;
    bool m_bSecondBooleanFlag;
    unsigned char layoutPadding12F[1];
    float m_fSpecularStrength;
    NiColor m_kSurfaceColor;
    bool m_bTextureFlag;
    bool m_bDecalTextureCreated;
    unsigned char layoutPadding142[2];
};
