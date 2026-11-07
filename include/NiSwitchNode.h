#pragma once

#include <stddef.h>
#include "NiNode.h"

// m_kChildRevID's type: NiTPrimitiveArray<unsigned int> (RTTI vftable 0x0101a3ac) over
// NiTArray<unsigned int,NiTMallocInterface<unsigned int> > (vftable 0x0101a3a4); NiSwitchNode's constructor (0x00a94360)
// stores both, its destructor (0x00a94400) the base one before NiFree(m_pBase). The NiSwitchNode / NiLODNode units
// inline GetSize / GetAt (Gamebryo NiTArray.inl) and call RemoveAt (nothrow) out of line: member specializations here.
#include "NiTMallocInterface.h"
#include "NiTPrimitiveArray.h"

template <> inline unsigned int NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::GetSize() const
{
    return m_usSize;
}
template <> inline unsigned int& NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::GetAt(unsigned int uiIndex)
{
    return m_pBase[uiIndex];
}
template <>
inline const unsigned int& NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::GetAt(unsigned int uiIndex) const
{
    return m_pBase[uiIndex];
}
template <> unsigned int NiTArray<unsigned int, NiTMallocInterface<unsigned int> >::RemoveAt(unsigned int uiIndex) throw();

class NiSwitchNode : public NiNode
{
  public:
    NiSwitchNode();
    // no user-declared destructor: the implicit one (deleting form 0x00a94400, inlined in ~NiLODNode 0x00a99470)
    // stores no NiSwitchNode vftable, only m_kChildRevID's NiTArray one, then calls ~NiNode

    bool __thiscall NiNode_IsEqual(NiObject* object);
    bool __thiscall IsEqual_00a94000(NiObject* object);
    void __thiscall FUN_00a94360();

    // flags: bit 0 update only the active child, bit 1 update controllers
    union
    {
        unsigned short m_usFlags;
        struct
        {
            char m_0ac;
            char m_0ad;
        };
    };
    union
    {
        unsigned short unkAE;
        struct
        {
            char m_0ae;
            char m_0af;
        };
    };
    union
    {
        int m_iIndex;
        void* m_0b0;
    };
    float m_fSavedTime;                             // 0xb4
    unsigned int m_uiRevID;                         // 0xb8
    NiTPrimitiveArray<unsigned int> m_kChildRevID;  // 0xbc; NiSwitchNode is 0xcc (operator new(0xcc) at 0x00a94500, 0x00a94550)
};

typedef char NiSwitchNode_child_rev_id_offset_check[(offsetof(NiSwitchNode, m_kChildRevID) == 0xBC) ? 1 : -1];
typedef char NiSwitchNode_size_check[(sizeof(NiSwitchNode) == 0xCC) ? 1 : -1];
