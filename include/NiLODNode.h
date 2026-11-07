#pragma once

#include <stddef.h>
#include "NiSwitchNode.h"

class Arg99;
class Holder;
class Obj;
class NiLODData;
class NiRangeLODData;

class NiLODNode : public NiSwitchNode
{
  public:
    NiLODNode();
    virtual ~NiLODNode() throw();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void UpdateWorldData(NiUpdateData& data);
    virtual void OnVisible(NiCullingProcess& culler);

    bool __thiscall NiBSPNode_RegisterStreamables(NiStream* stream);
    bool __thiscall RegisterStreamables_00a992e0(NiStream* stream);
    void __thiscall FUN_00a99470();
    NiLODNode* __thiscall FUN_00a99670(unsigned int flags);
    void __thiscall UpdateWorldData_00a99110(NiUpdateData& data);
    void __thiscall SaveBinary_00a99310(NiStream& stream);
    void __thiscall CopyMembers_00a99390(NiSwitchNode* destination, CloningProcess& process);
    bool IsEqual_00a99400(Holder* other);
    void __thiscall LoadBinary_00a994d0(NiStream* stream);
    void GetViewerStrings_00a99760(NiViewerStringsArray* strings);

    void __thiscall UpdateChildrenWorldData();
    void UpdateTargetIndex(Arg99* argument);
    void UpdateSwitchChild(Arg99* argument);
    void AssignRefCounted(Obj* object);
    void LoadRefFromStream(NiStream* stream);
    void SetLODData(NiRangeLODData* data);
    NiLODNode* CreateCloneLODNode(CloningProcess& process);

    NiPointer<NiLODData> m_spLODData;  // 0xcc
    bool m_bLODActive;                 // 0xd0; NiLODNode is 0xd4 (operator new(0xd4) at 0x00a99710)
};

typedef char NiLODNode_lod_data_offset_check[(offsetof(NiLODNode, m_spLODData) == 0xCC) ? 1 : -1];
typedef char NiLODNode_size_check[(sizeof(NiLODNode) == 0xD4) ? 1 : -1];
