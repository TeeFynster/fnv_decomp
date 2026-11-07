#pragma once

#include "NiTimeController.h"
#include "NiTPrimitiveSet.h"
#include "NiTPrimitiveArray.h"
#include "NiStream.h"

class GeometrySkinInstancePair;
class NiTriBasedGeom;

class NiBoneLODController : public NiTimeController
{
public:
    typedef NiTPrimitiveSet<NiNode*> BoneSet;
    typedef NiTPrimitiveSet<GeometrySkinInstancePair*> SkinInfoSet;

    NiBoneLODController();
    virtual ~NiBoneLODController();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void ProcessClone(CloningProcess& process);
    virtual void PostLinkObject(NiStream& stream);
    virtual void Update(NiUpdateData& update);

    using NiTimeController::Update;

    void UpdateLOD(NiUpdateData& update);
    bool IsTargetOfType() const;
    void ClearEntries();
    void AppendViewerStrings(NiViewerStringsArray* strings);
    void ReadFromStream(NiStream* stream);
    void CloneFrom(CloningProcess* process);

    NiBoneLODController* FUN_00a550b0();
    void FUN_00a6cfe0(NiBoneLODController* clone, CloningProcess* process);
    NiBoneLODController* CreateClone_00a552c0(CloningProcess& process);
    void FUN_00a541f0(int lod);
    void PostLinkObject_00a54340(NiStream& stream);
    void* FUN_00a553f0(unsigned int flags);
    bool RegisterStreamables_00a53d00(NiStream& stream);
    void LinkObject_00a53d70(NiStream& stream);
    bool IsEqual_00a53ea0(NiObject* object);
    void SaveBinary_00a549d0(NiStream& stream);
    void FUN_00a6d0c0(CloningProcess* process);
    void FUN_00a6d5e0(NiStream* stream);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiTPrimitiveArray<BoneSet*> m_kBoneSetArray;
    NiTPrimitiveArray<SkinInfoSet*> m_kSkinInfoSets;
    NiTPrimitiveSet<NiTriBasedGeom*> m_kShapeGroups;
};
