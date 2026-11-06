// fallout/interface/interface_rebase_PC_NiNode.h: declares NiNode
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_PC_NINODE_DECLARATION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_PC_NINODE_DECLARATION_H
#include "../../../include/NiAVObject.h"
class NiNode : public NiAVObject
{
  public:
    virtual ~NiNode();
    virtual void AttachChildInAvailableSlot(NiAVObject* apChild, bool abFirstAvail);
    virtual void PlaceChildAtIndex(unsigned int i, NiAVObject* apChild);
    virtual void DetachChildAlt(NiAVObject* apChild, NiPointer<NiAVObject>& arRemovedChild);
    virtual void InsertChild(NiAVObject* apChild);
    virtual void DetachChildAtAlt(unsigned int i, NiPointer<NiAVObject>& arRemovedChild);
    virtual void RemoveChildAt(unsigned int i);
    virtual void SetAtAlt(unsigned int i, NiAVObject* apChild, NiPointer<NiAVObject>& arRemovedChild);
    virtual void SetAt(unsigned int i, NiAVObject* apChild);
    virtual void UpdateUpwardPass();
    NiTObjectArray<NiPointer<NiAVObject> > m_kChildList;
};
FNV_STATIC_ASSERT(sizeof(NiNode) == 0xAC);
FNV_STATIC_ASSERT(offsetof(NiNode, m_kChildList) == 0x9C);
#endif
