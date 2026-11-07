#pragma once

#include <stddef.h>
#include "NiObjectNET.h"
#include "NiTransform.h"
#include "NiPointer.h"
#include "NiTPointerList.h"

class NiNode;
class NiCollisionObject;
class FourComponentFloatVector;
class NiProperty;
class NiAlphaProperty;
class NiUpdateData;
class NiUpdateDataH;
class NiPropertyState;
class NiDynamicEffectState;
class NiCullingProcess;
class NiRenderer;
class FixedText;
class BSStringTChar;
class AnimTimeSource;
class M3_;
class Mtx;
class DebugPoint;
class NiPoint3Value;
class NiMatrix3Value;
class NiQuaternion;
class NiAVObjectPalette;
class PropertyList;
struct GridRotation;
struct GridEuler;
namespace H { class NiMatrix3; }
namespace PC { class NiMatrix3; }

class NiAVObject : public NiObjectNET
{
  public:
    NiAVObject();
    virtual ~NiAVObject();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void SetObjectBound(NiBound* bound);

    virtual void UpdateControllers(NiUpdateData& arData);
    virtual void ApplyTransform(const NiMatrix3& arRotation, const NiPoint3& arPosition, bool abOnLeft);
    virtual void SetMaterialNeedsUpdate(bool abNeedsUpdate);
    virtual void SetDefaultMaterialNeedsUpdateFlag(bool abNeedsUpdate);
    virtual NiAVObject* GetObjectByName(const NiFixedString& arName) const;
    virtual void SetSelectiveUpdateFlags(bool& arSelectiveUpdate, bool abSelectiveUpdateTransforms, bool& arRigid);
    virtual void UpdateDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdateRigidDownwardPass(NiUpdateData& arData, unsigned int auiFlags);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* apParentState);
    virtual void UpdateEffectsDownward(NiDynamicEffectState* apEffectState);
    virtual void UpdateWorldData(NiUpdateData& arData);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& arData);
    virtual void PreAttachUpdate(NiNode* apEventualParent, NiUpdateData& arData);
    virtual void PreAttachUpdateProperties(NiNode* apEventualParent);
    virtual void FinalizeAttachUpdate(NiNode* apEventualParent);
    virtual void CompleteAttachUpdate();
    virtual void OnVisible(NiCullingProcess& arCuller);
    virtual void PurgeRendererData(NiRenderer* apRenderer);


    void IncRefCount();
    void DecRefCount();
    unsigned int GetRefCount() const;
    NiAVObject* Clone();
    NiAVObject* CloneObject(CloningProcess& process);
    int IsVisualObject();
    bool IsKindOfType(const NiRTTI* type);
    void SetName(const NiFixedString& name);
    void SetName(const FixedText& name);
    using NiObjectNET::SetName;
    bool AddExtraData(void* extra);
    bool AddExtraData(const NiFixedString& name, NiExtraData* extra);
    using NiObjectNET::AddExtraData;
    bool DeleteExtraDataByKey(const NiFixedString& name);
    bool RemoveExtraDataByName(const NiFixedString& name);
    NiExtraData* GetExtraData(const NiFixedString& name);
    NiTimeController* GetController(const NiRTTI* rtti);
    NiFixedString& GetName();
    const NiFixedString& GetName() const;
    BSStringTChar& GetTextUnused();
    AnimTimeSource* GetObject3D();

    NiNode* GetParent();
    NiNode* GetParent() const;
    NiNode* GetParentNode();
    void AssignParent(NiNode* parent);
    void SetEventualParent(NiNode* parent);
    void AssignCollisionObject(NiCollisionObject* collision);
    NiProperty* GetProperty(unsigned int type);
    void AttachProperty(NiObject* property);
    void AttachProperty(NiAlphaProperty* property);
    void RemoveProperty(unsigned int type);
    void BuildPropertyState(NiPropertyState* parentState, bool copy, NiPropertyState*& state);
    void CopyMemberData();

    void SetBit(bool value, unsigned int mask);
    void SetBit(unsigned int mask, bool value);
    void SetAppCulled(bool value);
    bool IsCulledFlag();
    unsigned char flagSet(unsigned int bit) const;
    unsigned char SelectedFlag() const;
    unsigned char RigidFlag() const;
    unsigned char TransformFlag() const;
    unsigned char BoundFlag13() const;
    unsigned char BoundFlag19() const;
    bool GetHasPropertyController() const;
    void* SetTaskFlag(bool value);
    void SetByteAtOffset38(unsigned int flags);
    void RemoveGarbageMark();

    const NiBound& GetBound();
    NiBound& GetBoundingVolume();
    const NiBound& GetBoundingVolume() const;
    void EnsureWorldBound();
    const NiMatrix3& GetRotate() const;
    const NiMatrix3& GetLocalRotateStub();
    NiPoint3 GetWorldTranslation();
    const NiTransform& GetWorldTransform() const;
    float GetFloatAt64();
    float GetHeadTail();
    void SetRotation(const NiMatrix3& rotation);
    void SetLocalRotation(const NiMatrix3& rotation);
    void SetLocalRotation(const H::NiMatrix3& rotation);
    void SetLocalRotation(const PC::NiMatrix3& rotation);
    void SetLocalRotation(const M3_& rotation);
    void SetLocalRotation(const Mtx& rotation);
    void SetLocalRotation(float x, float y, float z, float w);
    void SetPosition(float x, float y, float z);
    void SetScale(float scale);
    void SetEffectColor(const NiPoint3& color);

    void Update(NiUpdateData& data);
    void Update(const NiUpdateData& data);
    void Update(NiUpdateDataH& data);
    void UpdateSceneObject();
    void UpdateModelBound();
    void UpdateTimeControllers(NiUpdateData& data, bool updateProperties);
    void UpdateWorldLoc();
    void Cull(NiCullingProcess& culler);

    NiAVObject* NiNode_GetAtChecked(int index);
    NiProperty* NiNode_GetAtChecked(bool flag);
    void NiRefObject_DecRefCount();
    PropertyList& FUN_00430830();
    int EvaluateValue_0043c470();
    NiPoint3& GetTranslate_0043c490();
    const NiBound& NiAVObject_GetWorldBound() const;
    void NiAVObject_AttachProperty(void* value);
    void SetRotate_0043fa80(NiTransform* transform);
    void SetRotate_0043fa80(const void* rotation);
    void SetRotate_0043fa80(const NiMatrix3& rotation);
    void SetRotate_0043fa80(const NiMatrix3Value& rotation);
    void SetRotate_0043fa80(const GridRotation& rotation);
    void NiAVObject_SetTranslate(const NiPoint3& position);
    void NiAVObject_SetTranslate(NiPoint3* position);
    void NiAVObject_SetTranslate(const DebugPoint& position);
    void NiAVObject_SetTranslate(const NiPoint3Value& position);
    void NiAVObject_SetScale(float scale);
    void FUN_004410f0(unsigned int flags);
    void FUN_00450f90(bool culled);
    bool GetAppCulled_00456610();
    const NiPoint3& NiAVObject_GetWorldTranslate();
    const NiPoint3& NiAVObject_GetWorldTranslate() const;
    const NiTransform& NiAVObject_GetWorldRotate() const;
    void FUN_004b4880(NiTransform* transform);
    void NiAVObject_SetTranslate_004bc1f0(float x, float y, float z);
    void SetHasMovingSound(bool value);
    void NiAVObject_SetWorldTranslate(void* value);
    bool GetSelectiveUpdate();
    void NiNode_SetRotate(const NiQuaternion& rotation);
    void FUN_0050dd50(const NiPoint3& value);
    bool GetDisplayObject();
    NiObject* NiAVObject_GetCollisionObject();
    NiMatrix3& NiAVObject_GetRotate_006a9540();
    const char* DialoguePackage_GetActorStartedConversation();
    void NiAVObject_Update(NiUpdateData& data);
    void NiAVObject_Update(const GridEuler& rotation);
    int GetObjectByName_00a59e20(int value);
    void UpdateProperties();
    void NiAVObject_CloneProperties(NiAVObject* object, void* data, CloningProcess& process);
    void CopyMembers_00a5ac90(NiAVObject* object, CloningProcess& process);
    NiExtraData* FUN_00a5bdd0(const NiFixedString& name);
    bool SetExtraDataName(NiExtraData* extra);
    void RemoveAllControllers();
    NiAVObjectPalette* FUN_00a64620();
    void NiStream_ReadMultipleLinkIDs();
    void FUN_00a67050(unsigned int flags);
    void* FUN_00a75f10();
    void* FUN_00a7b850();
    void BSXFlags_Init();
    void BSWArray_SetName();
    void FUN_00c66240(NiObject* object);
    void bhkRefObject_SethkObject(NiObject* object);

    enum { APP_CULLED = 1 };

    NiNode* m_pkParent;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    FourComponentFloatVector* m_kWorldBound;
    NiTPointerList<NiPointer<NiProperty> > m_kPropertyList;
    unsigned int m_uFlags;
    NiTransform m_kLocal;
    NiTransform m_kWorld;
};

typedef char NiAVObject_size_check[(sizeof(NiAVObject) == 156) ? 1 : -1];
typedef char NiAVObject_parent_offset_check[(offsetof(NiAVObject, m_pkParent) == 0x18) ? 1 : -1];
typedef char NiAVObject_collision_offset_check[(offsetof(NiAVObject, m_spCollisionObject) == 0x1c) ? 1 : -1];
typedef char NiAVObject_bound_offset_check[(offsetof(NiAVObject, m_kWorldBound) == 0x20) ? 1 : -1];
typedef char NiAVObject_properties_offset_check[(offsetof(NiAVObject, m_kPropertyList) == 0x24) ? 1 : -1];
typedef char NiAVObject_flags_offset_check[(offsetof(NiAVObject, m_uFlags) == 0x30) ? 1 : -1];
typedef char NiAVObject_local_offset_check[(offsetof(NiAVObject, m_kLocal) == 0x34) ? 1 : -1];
typedef char NiAVObject_world_offset_check[(offsetof(NiAVObject, m_kWorld) == 0x68) ? 1 : -1];
