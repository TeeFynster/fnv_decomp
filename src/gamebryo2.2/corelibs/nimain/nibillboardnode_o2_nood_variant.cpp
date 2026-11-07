
// src/gamebryo2.2/corelibs/nimain/nibillboardnode_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/nibillboardnode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../../include/NiBillboardNode.h"

void* __cdecl Object_DispatchCommandFour(unsigned int);


inline NiBillboardNode::NiBillboardNode() : NiNode(0)
{
    *(float*)&unkB0 = 0.0f;
    *(unsigned short*)&unkAC = 9;
}

inline void* __cdecl operator new(size_t, void* storage) { return storage; }

// @fnv 0x00a7e770
// src: EXE 0x00a7e770
NiBillboardNode* NiBillboardNode_CreateObject()
{
    void* storage = NiNode::operator new(sizeof(NiBillboardNode));
    return storage ? ::new (storage) NiBillboardNode : 0;
}
