
// src/bsmenu/tilerect_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bsmenu/tilerect.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/NiNode.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiFixedString.h"
#include "../../include/Tile.h"
#include "../../include/TileRect.h"

// TileRect::CalculateNode (0x00a1f3b0, also bound by tilemenu.cpp) builds
// the tile's named node and attaches Tile::Extra (constructor 0x00a1f610).

inline void NiNode::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiNode::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

inline void NiNode::SetHidden(bool hidden, unsigned int mask)
{
    if (hidden)
        m_uFlags |= mask;
    else
        m_uFlags &= ~mask;
}

template <> inline NiPointer<NiNode>::operator NiNode*() const
{
    return m_pObject;
}

template <> inline NiNode* NiPointer<NiNode>::operator->() const
{
    return m_pObject;
}

template <> inline NiPointer<NiNode>& NiPointer<NiNode>::operator=(NiNode* object)
{
    if (m_pObject != object)
    {
        NiNode* oldObject = m_pObject;
        m_pObject = object;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
        if (oldObject)
            oldObject->DecRefCount();
    }
    return *this;
}

extern const char DAT_010954cc[];

inline Tile::Extra::Extra(Tile* tile, NiNode* node) : pTile(tile), pNode(node)
{
    SetName(NiFixedString(DAT_010954cc));
}

NiNode* FUN_00706d30();
void Interface_SetNeedToUpdate(int iValue);

// @fnv 0x00a1f3b0
NiNode* TileRect::CalculateNode()
{
    NiNode* pkParent = GetUnderlyingNode();
    m_pRenderedNodeEntry = new NiNode(0);
    if (pkParent == 0)
        pkParent = FUN_00706d30();
    pkParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(m_pRenderedNodeEntry), true);
    m_pRenderedNodeEntry->SetName(NiFixedString(static_cast<const char*>(StringProvider.pString)));
    m_pRenderedNodeEntry->SetHidden(!IsTraitNonZero(0xfa3), 1);
    m_pRenderedNodeEntry->UpdateProperties();
    Interface_SetNeedToUpdate(1);
    m_pRenderedNodeEntry->AddExtraData(new Tile::Extra(this, m_pRenderedNodeEntry));
    Tile::SetTraitValue(0xfa1, GetFloat(0xfa1), 0);
    Tile::SetTraitValue(0xfa2, GetFloat(0xfa2), 0);
    return m_pRenderedNodeEntry;
}
