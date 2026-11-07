
// src/havok/common/base/reflection/hkclassupdate.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassupdate.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/BSAudio.h"

BSAudio* hkMemoryRouter_getInstance();
struct TypeNode;
struct VisitMap
{
    unsigned int LookupHashEntry(TypeNode*, int);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator*, TypeNode*, unsigned int);
};
struct Member
{
    void* type;
    TypeNode* getClass();
};
struct TypeNode
{
    TypeNode* hkClass_getParent();
    int FUN_00d46f70();
    Member* FUN_00d46f80(int);
};
// Walks a type node and its members, skipping nodes whose visited flags intersect mask, marking them visited, and invoking callback on each member.
// @fnv 0x00e04af0
void __cdecl VisitTypeMembers(TypeNode* node, VisitMap* visited, unsigned int mask, void(__cdecl* callback)(Member*))
{
    for (;;)
    {
        unsigned int flags = visited->LookupHashEntry(node, 0);
        if (mask & flags)
            return;
        BSAudio* audio = hkMemoryRouter_getInstance();
        visited->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<Allocator*>(audio->pListener), node, flags | mask);
        for (int i = 0; i < node->FUN_00d46f70(); ++i)
        {
            Member* member = node->FUN_00d46f80(i);
            TypeNode* child = member->getClass();
            if (child)
                VisitTypeMembers(child, visited, mask, callback);
            callback(member);
        }
        if (!node->hkClass_getParent())
            return;
        node = node->hkClass_getParent();
    }
}

namespace fnv_00e04bb0 {
struct Allocator;
BSAudio* hkMemoryRouter_getInstance();
struct TypeNode;
struct VisitMap
{
    unsigned int LookupHashEntry(TypeNode*, int);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator*, TypeNode*, unsigned int);
};
struct Member
{
    int unk00;
    void* type;
    TypeNode* FUN_00d86910();
};
struct TypeNode
{
    TypeNode* hkClass_getParent();
    int FUN_00d46f70();
    Member* FUN_00d46f80(int);
};
struct Property
{
    int unk00, unk04, unk08, unk0C;
    short unk10;
    unsigned short offset;
};
struct Registry
{
    Property* FUN_00d46fe0(const char*);
};
extern Registry DAT_0126ed90;
extern char DAT_010ea4cc[], DAT_010e5210[];
// Marks a type node as visited, resets an offset field up the ancestor chain, bumps a count, then recurses into member types and the parent node.
// @fnv 0x00e04bb0
void VisitTypeNode(TypeNode* node, VisitMap* visited)
{
    unsigned int flags = visited->LookupHashEntry(node, 0);
    if (!(flags & 1))
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        visited->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<Allocator*>(audio->pListener), node, flags | 1);
        unsigned int offset = DAT_0126ed90.FUN_00d46fe0(DAT_010ea4cc)->offset;
        TypeNode* ancestor = node;
        while (ancestor->hkClass_getParent())
        {
            *reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor) + offset) = 0;
            ancestor = ancestor->hkClass_getParent();
        }
        if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ancestor) + offset))
        {
            unsigned int countOffset = DAT_0126ed90.FUN_00d46fe0(DAT_010e5210)->offset;
            ++*reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor) + countOffset);
        }
        *reinterpret_cast<int*>(reinterpret_cast<char*>(ancestor) + offset) = 0;
        for (int i = 0; i < node->FUN_00d46f70(); ++i)
        {
            Member* member = node->FUN_00d46f80(i);
            if (member->type)
                VisitTypeNode(member->FUN_00d86910(), visited);
        }
        if (node->hkClass_getParent())
            VisitTypeNode(node->hkClass_getParent(), visited);
    }
}
}  // namespace fnv_00e04bb0

void __cdecl VisitTypeNode(void* registry, void* context);
void __cdecl VisitTypeMembers(void* registry, void* context, int size, void(__cdecl* func)(void*));
void __cdecl Object_UpdateFields_00e04a60(void* data);
void __cdecl UpdateStateFlags(void* data);

extern void* g_E04D30Last;

// Stand-in for the file-static FUN_00e04cc0: its body here is a placeholder; only its
// existence as a static function (which MSVC calls with the argument in eax) matters.
static __declspec(noinline) void E04D30Finish(void* registry)
{
    g_E04D30Last = registry;
}

// Registers context handlers by level: at level 1 runs VisitTypeNode and records registry, and below 4/5 registers size-2 and size-8 handlers.
// @fnv 0x00e04d30
void __cdecl RegisterContextHandlers(void* registry, void* context, int level)
{
    if (level == 1)
    {
        VisitTypeNode(registry, context);
        E04D30Finish(registry);
    }
    if (level < 4)
        VisitTypeMembers(registry, context, 2, Object_UpdateFields_00e04a60);
    if (level < 5)
        VisitTypeMembers(registry, context, 8, UpdateStateFlags);
}

struct TraverseNode
{
    const char* FUN_00d46d40();
    char* FUN_00d46f80(int index) const;
};
struct TypeDefinition
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned short fieldOffset;
};
struct TypeRegistry
{
    TypeDefinition* getMember(int index);
};
extern TypeRegistry DAT_0126ca58;
extern const char DAT_010d27bc[];
int __cdecl hkString_strCmp(const char*, const char*);

// Marks the node visited and, when its name matches DAT_010d27bc, writes 0x19 at the selected member offset.
// @fnv 0x00e04cc0
// src: GUESS 0x00e04cc0 (confidence: low)
static __declspec(noinline) void __cdecl Object_UpdateFields_00e04cc0(TraverseNode* node, VisitMap* visited)
{
    unsigned int flags = visited->LookupHashEntry(reinterpret_cast<TypeNode*>(node), 0);
    if ((flags & 4) == 0)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        visited->hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<Allocator*>(audio->pListener), reinterpret_cast<TypeNode*>(node), flags | 4);
        if (hkString_strCmp(node->FUN_00d46d40(), DAT_010d27bc) == 0)
        {
            char* member = node->FUN_00d46f80(2);
            TypeDefinition* type = DAT_0126ca58.getMember(4);
            member[type->fieldOffset] = 0x19;
        }
    }
}

void CallTraversal(TraverseNode* node, VisitMap* visited)
{
    Object_UpdateFields_00e04cc0(node, visited);
}

struct ParentNodeView : TypeNode
{
    const char* name;
    TypeNode* parent;

    TypeNode* hkClass_getParent();
};

// @fnv 0x00d46d60
// src: XBOX_PDB 0x00d46d60
TypeNode* ParentNodeView::hkClass_getParent()
{
    return parent;
}
