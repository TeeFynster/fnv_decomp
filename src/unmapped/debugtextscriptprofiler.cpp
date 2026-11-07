// src/unmapped/debugtextscriptprofiler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextscriptprofiler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Node
{
    unsigned int data;
};
struct ScriptPool
{
    void* NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem();
};
struct ScriptList : ScriptPool
{
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(unsigned int* element);
    void NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(Node*);
};
// Stores the value pointed to by element into the node obtained from FUN_0049fa80 at offset 8, then passes the node to FUN_0049fa20.
// @fnv 0x0076b660
// src: XBOX_PDB 0x0076b660
void ScriptList::NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddHead(unsigned int* puiElement)
{
    Node* node = static_cast<Node*>(this->NiTPointerListBase_NiTPointerAllocator_unsigned_int_unsigned_int_NewItem());
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(node) + 8) = *puiElement;
    NiTListBase_NiTPointerAllocator_unsigned_int_unsigned_int_AddNodeHead(node);
}
