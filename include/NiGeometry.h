#pragma once

#include "NiAVObject.h"
#include "NiPropertyState.h"

class NiGeometryData;
class NiSkinInstance;
class NiShader;
class NiAdditionalGeometryData;
class NiPoint2;
class NiColorA;
class NiGeometryProperties;
class GeomInfo;

class NiGeometry : public NiAVObject
{
  public:
    NiGeometry();
    NiGeometry(NiGeometryData* data);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual void SetSelectiveUpdateFlags(bool& selectiveUpdate, bool transforms, bool& rigid);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* state);
    virtual void UpdateWorldBound();
    virtual void OnVisible(NiCullingProcess& process);
    virtual void PurgeRendererData(NiRenderer* renderer);

    virtual void RenderImmediate(NiRenderer* renderer);
    virtual void RenderWithRenderer(NiRenderer* renderer);
    virtual void ReplaceModelData(NiGeometryData* data);
    virtual void CalculateNormals();
    virtual void CalculateConsistency(bool value);

    void CopyMemberData(NiGeometry* source, CloningProcess* process);
    NiGeometry* CopyMemberData();
    void UpdatePropertyControllers(NiGeometryProperties& properties);

    bool FUN_00a59f00(NiStream& stream);
    bool FUN_00a5a260(NiGeometry* object);
    void FUN_00a5ad00(void* strings);
    NiGeometryData* NiGeometry_GetModelData();
    NiObjectNET* FUN_0050d100();
    GeomInfo* FUN_00a59d30(int index);

    virtual const NiRTTI* GetRTTI() const;
    using NiAVObject::GetRTTI;
    virtual bool RegisterStreamables(NiStream& stream);
    using NiAVObject::RegisterStreamables;
    virtual void SaveBinary(NiStream& stream);
    using NiAVObject::SaveBinary;
    virtual bool IsEqual(NiObject* object) const;
    using NiAVObject::IsEqual;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    using NiAVObject::GetViewerStrings;
    using NiAVObject::IsGeometry;
    using NiAVObject::SetObjectBound;
    virtual void ApplyTransform(const NiMatrix3& rotation, const NiPoint3& position, bool onLeft);
    using NiAVObject::ApplyTransform;
    using NiAVObject::PostLinkObject;
    void RenderImmediate();
    void RenderImmediateAlt();
    void SetGeometryData(NiGeometryData* data);
    void* GetSpecialGeometry();
    NiTriBasedGeom* GetTriBasedGeom();
    void* GetTriStrips();

    unsigned short GetVertexCount();
    unsigned short GetVertexCount() const;
    NiPoint3* GetVertices();
    void SetActiveVertexQuantity(unsigned short quantity);
    unsigned short GetActiveVertexQuantity();
    void SetDynamicData(bool dynamic);
    NiPoint3* GetNormals();
    int GetNormalBinormalTangentMethod();
    void StoreNormalBinormalTangent(int method);
    void SetModelBound(void* bound);
    void SetModelBound(const NiBound& bound);
    NiBound* GetModelBound();
    void CreateColors(bool create);
    NiColorA* GetColors();
    void CreateTextures(bool create, unsigned short count);
    unsigned short GetTextureSets();
    NiPoint2* GetTextures();
    NiPoint2* GetTextureSet(unsigned short index);
    void AppendTextureSet(NiPoint2* textures);
    NiSkinInstance* GetSkinInstance();
    void SetSkinInstance(NiSkinInstance* instance);
    NiAdditionalGeometryData* GetAdditionalGeometryData();
    void AssignAdditionalGeometryData(NiAdditionalGeometryData* data);
    void SetSortObject(bool sort);
    bool GetSortObject();
    NiPropertyState* GetPropertyStateP();
    NiShader* GetGeometryShaderObject();
    NiShader* GetShaderFromMaterial();
    void SetShader(NiShader* shader);
    NiGeometryData* GetModelData();
    NiGeometryData* GetModelData() const;
    NiGeometryData* GetData() const;
    bool HasGeometryProperty(int property);
    int GetConsistency();
    void SetDataConsistency(int consistency);
    unsigned int QMemContext();

    const NiBound& GetBoundingVolume() const;
    using NiAVObject::GetBoundingVolume;
    bool GetFlag19() const;
    bool GetFlag13() const;
    bool GetFlag22() const;
    void SetFlag22(bool value);
    const NiTransform& GetWorldTransform() const;
    const char* GetName() const;
    void DeleteExtraDataByKey(const NiFixedString& name);
    NiProperty* GetProperty(unsigned int type);
    NiProperty* GetProperty(int type);
    void SetAppCulled(bool culled);

    NiPropertyState m_PropertyState;
    NiPointer<NiGeometryData> m_spModelData;
    NiPointer<NiSkinInstance> m_spSkinInstance;
    NiShader* m_spShader;
};

typedef char NiGeometry_size_check[(sizeof(NiGeometry) == 196) ? 1 : -1];
typedef char NiGeometry_property_state_offset_check[(offsetof(NiGeometry, m_PropertyState) == 0x9C) ? 1 : -1];
typedef char NiGeometry_model_data_offset_check[(offsetof(NiGeometry, m_spModelData) == 0xB8) ? 1 : -1];
typedef char NiGeometry_skin_instance_offset_check[(offsetof(NiGeometry, m_spSkinInstance) == 0xBC) ? 1 : -1];
typedef char NiGeometry_shader_offset_check[(offsetof(NiGeometry, m_spShader) == 0xC0) ? 1 : -1];
