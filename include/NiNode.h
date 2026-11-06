#pragma once

#include <stddef.h>
#include "NiAVObject.h"
class FaceGenUndo;
template <class T> class NiTPrimitiveArray;

class GeometryData;
class Tile__Extra;
class NiPointLight;
class Motion;
class UpdData;
class TreeCloneProcess;
class FloatMatrix3;
namespace L { class NiFixedString; }
template <class T> class ChildPtr;
template <class T> class ChildArray;

#include "NiTNewInterface.h"
#include "NiTObjectArray.h"

class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short arraySize);
    virtual ~NiNode();

    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual NiAVObject* GetObjectByName(const NiFixedString& name) const;
    virtual void UpdateDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdateSelectedDownwardPass(NiUpdateData& data, unsigned int flags);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* state);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& data);
    virtual void OnVisible(NiCullingProcess& culler);

    virtual void AttachChildInAvailableSlot(NiAVObject* child, bool firstAvailable);
    virtual void AddObjectAt(unsigned int index, NiAVObject* object);
    virtual void RemoveObject2(NiAVObject* object, NiAVObject** removed);
    virtual void RemoveObject(NiAVObject* object);
    virtual void RemoveNthObject2(unsigned int index, NiAVObject** removed);
    virtual void RemoveNthObject(unsigned int index);
    virtual void ReplaceNthObject2(unsigned int index, NiAVObject* object, NiAVObject** removed);
    virtual void ReplaceNthObject(unsigned int index, NiAVObject* object);
    virtual void UpdateUpwardPass();

    static const unsigned int APP_CULLED_MASK = 1;

    void IncRefCount();
    void DecRefCount();
    void AssignFixedString(const L::NiFixedString& name);
    void SetName(const NiFixedString& name);
    using NiAVObject::SetName;
    void SetExtraDataName(void* extra);
    void SetExtraDataName(Motion* motion);
    bool AddExtraData(Tile__Extra* extra);
    using NiAVObject::AddExtraData;
    GeometryData* GetGeometryData();
    void SetExtraBuffer(void* buffer);
    void SetHidden(bool hidden, unsigned int mask);
    void SetAppCulled(bool culled);
    void UpdateModel();
    void Update(NiUpdateData& data);
    void Update(const NiUpdateData& data);
    void Update(NiUpdateData* data);
    void Update(const UpdData& data);
    using NiAVObject::Update;
    using NiAVObject::SetSelectiveUpdateFlags;
    void CopyMemberData(NiNode* source, CloningProcess& process);
    using NiAVObject::CopyMemberData;
    void ReadChildListFromStream(NiStream& stream);
    void ReadChildListFromStream(void* stream);

    void FUN_00439410(NiNode* child);
    using NiAVObject::FUN_00439410;
    NiBound* FUN_0043d450();
    using NiAVObject::FUN_0043d450;
    NiAVObject* FUN_0045bc00(unsigned int index);
    using NiAVObject::FUN_0045bc00;
    unsigned int FUN_00453470();
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int index);

    void FUN_006fb940(float x, float y, float z);
    bool FUN_009dc530();
    void FUN_0043fa80(const FloatMatrix3& rotation);
    using NiAVObject::FUN_0043fa80;
    void FUN_00440460(const NiPoint3* position);
    using NiAVObject::FUN_00440460;
    void FUN_004def90();
    void FUN_004902f0(bool enabled);
    void FUN_004add70();
    void FUN_00546780(bool enabled);
    void FUN_00572160();
    NiAVObject* FUN_00461130(bool flag);
    using NiAVObject::FUN_00461130;
    void FUN_00635fe0(bool enabled);
    void FUN_006404b0(float angle, float x, float y, float z);
    NiTimeController* FUN_00a5c570(NiRTTI* rtti);
    void FUN_00a7dae0(NiUpdateData& data, unsigned int flags);
    void FUN_00c46ca0(NiStream& stream);

    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int index);
    NiAVObject* GetChildAt(unsigned int index);
    ChildArray<ChildPtr<NiAVObject> >& GetChildren();
    void DetachAllChildren();
    NiPoint3& GetLocalTranslate();
    void SetLocalTranslate(const NiPoint3& position);
    void SetLocalTranslate(float x, float y, float z);
    using NiAVObject::GetBoundingVolume;
    using NiAVObject::GetParent;
    using NiAVObject::GetName;
    void AttachProperty(NiObject* property);
    using NiAVObject::AttachProperty;
    NiObject* GetControllers();
    using NiAVObject::GetControllers;
    NiNode* Clone();
    NiNode* CloneWithProcess(TreeCloneProcess* process);
    void ApplyRDTNodeScales();
    NiAVObject* operator->();

    void AttachChildInAvailableSlot(NiNode* child, bool firstAvailable);
    void AttachChildInAvailableSlot(NiPointLight* child, bool firstAvailable);
    void AttachChildInAvailableSlot(NiObject* child, bool firstAvailable);
    void AddObject(NiAVObject* object, bool firstAvailable);
    void AddObject(NiNode* object, bool firstAvailable);
    void PlaceChildAtIndex(unsigned int index, NiAVObject* child);
    void DetachChildAlt(NiAVObject* child, NiPointer<NiAVObject>& removed);
    void DetachChildAlt(NiAVObject* child);
    void DetachChildAlt(NiNode* child);
    void InsertChild(NiAVObject* child);
    void InsertChild(NiNode* child);
    void InsertChild(const char* child);
    void DetachChildAtAlt(unsigned int index, NiPointer<NiAVObject>& removed);
    void RemoveChildAt(unsigned int index);
    void SetAtAlt(unsigned int index, NiAVObject* child, NiPointer<NiAVObject>& removed);
    void SetAt(unsigned int index, NiAVObject* child);
    NiAVObject* GetObjectByBone(int bone);
    using NiAVObject::MakeClone;
    int GetPropertyType();
    const void* GetType();
    NiNode* GetNiNode();
    BSFadeNode* GetFadeNode();
    void SetBool(int a, int b, int c);

    NiTObjectArray<NiPointer<NiAVObject> > m_kChildren;
};

typedef char NiNode_size_check[(sizeof(NiNode) == 172) ? 1 : -1];
typedef char NiNode_children_offset_check[(offsetof(NiNode, m_kChildren) == 0x9c) ? 1 : -1];
