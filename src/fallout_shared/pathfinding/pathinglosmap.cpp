#include "../../../include/NavMeshTriangle.h"
#include "../../../include/NiColorA.h"
#include "../../../include/PathingLOSMap.h"
#include "../../../include/Script.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiAlphaProperty.h"
#include "../../../include/NiMaterialProperty.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiProperty.h"
#include "../../../include/NiSortAdjustNode.h"
#include "../../../include/DummyPointerMap.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/NiColor.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/NavMeshCollection.h"

// src/fallout_shared/pathfinding/pathinglosmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathinglosmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl operator delete(void* p, unsigned int size);

// Runs the destructor and, when flags has bit 0 set, frees the object with operator delete, then returns this.
// @fnv 0x006e1440
void* PathingLOSMap::DestroyAndFree(unsigned int flags)
{
    this->PathingLOSMap::~PathingLOSMap();
    if (flags & 1)
        operator delete(this, 0x50);
    return this;
}

// Looks up aNavMeshID in the map at this+8 and returns a pointer into the buffer at this+0x18 offset by the stored offset, or null if not found.
// @fnv 0x006e1610
char* PathingLOSMap::GetTriangleScore(unsigned int aNavMeshID)
{
    unsigned int ioffset;
    if (m_map.GetAt(aNavMeshID, ioffset))
        return pTriangleScores + ioffset;
    else
        return 0;
}

// Calls GetAt on the DummyPointerMap at offset 8 of this object, passing a and b through.
// @fnv 0x006e1650
void PathingLOSMap::GetMapValue(unsigned int uiKey, unsigned int& ruiValue)
{
    m_map.GetAt(uiKey, ruiValue);
}

// Returns the smaller of the two char arguments.
// @fnv 0x006e1f80
char MinChar(char a, char b)
{
    char result;
    if (a < b)
        result = a;
    else
        result = b;
    return result;
}

// Returns the larger of the two char arguments.
// @fnv 0x006e1fb0
char MaxChar(char acFirst, char acSecond)
{
    char c;
    if (acFirst > acSecond)
        c = acFirst;
    else
        c = acSecond;
    return c;
}

// @fnv 0x006e1fe0
void NiSortAdjustNode::SetArraySize(unsigned int aSize)
{
    m_kChildren.SetSize(aSize);
}

// Looks up aiNavMeshID in the map at offset 8 and returns whether GetAt found an entry.
// @fnv 0x006e2050
bool PathingLOSMap::HasNavMeshEntry(unsigned int aiNavMeshID)
{
    unsigned int idummy;
    return m_map.GetAt(aiNavMeshID, idummy);
}

struct ArrHelper
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty() const;
};
// Returns false if the helper at offset 0x1c reports true; otherwise scans text entries and returns true on the first non-positive char whose lookup succeeds.
// @fnv 0x006e1770
// src: COMMUNITY 0x006e1770
bool PathingLOSMap::GetUnseenNavMeshAndTriangle(unsigned int a, unsigned int b)
{
    if (((const ArrHelper*)((char*)this + 0x1c))->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
        return false;
    for (unsigned int i = 0; i < (unsigned int)((Script*)this)->FUN_0055b980(); ++i)
    {
        char cChar = ((Script*)this)->GetByteAt(i);
        if (cChar > 0)
            continue;
        unsigned char d = GetNavMeshAndTriangleForIndex(i, (SpawnedTarget*)a, (unsigned short*)b);
        if (d)
            return true;
    }
    return false;
}

struct FUN_006d7ee0_shell
{
    char GetByteAt(unsigned int a);
};
struct FUN_006d8970_shell
{
    void SetByteAt(int, int);
};
// Iterates over the text characters and sets each character whose value is <= 0 to 0x7f.
// @fnv 0x006e2000
void PathingLOSMap::ClampNonPositiveTextChars()
{
    for (unsigned int i = 0; i < (unsigned int)((Script*)this)->FUN_0055b980(); ++i)
    {
        if (((FUN_006d7ee0_shell*)this)->GetByteAt(i) <= 0)
            ((FUN_006d8970_shell*)this)->SetByteAt((int)i, 0x7f);
    }
}

// Retained destructor layout: the shared DummyPointerMap has no destructor.
// Its automatic cleanup and exception-unwind state are required at 0x006e1470.
struct PathingLOSBase
{
    virtual ~PathingLOSBase();
    unsigned int unk04;
};

struct LOSSub08
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~LOSSub08();
};

struct LOSHeap
{
    unsigned int unk00;
    static void operator delete(void* apMemory);
};

struct LOSMember1C
{
    unsigned int unk00;
    void ReleaseMember();
};

struct PathingLOSMapDestructor : PathingLOSBase
{
    LOSSub08 m_08;
    LOSHeap* m_18;
    LOSMember1C m_1c;

    virtual ~PathingLOSMapDestructor();
};

// Destructor that deletes m_18 if non-null, then calls ReleaseMember on m_1c.
// @fnv 0x006e1470
PathingLOSMapDestructor::~PathingLOSMapDestructor()
{
    if (m_18 != 0)
    {
        delete m_18;
    }
    m_1c.ReleaseMember();
}


// Clears the total count, maps each array entry's navmesh id to a running offset, sums sizes, then allocates and fills m_pData with 0x7f.
// @fnv 0x006e1500
bool PathingLOSMap::BuildNavMeshMap(NavMeshCollection* pNavMeshArray)
{
    unsigned int i;
    unsigned int j2;
    m_uTotalCount = 0;
    for (i = 0; i < pNavMeshArray->FUN_0044ddc0(); i++)
    {
        m_map.SetAt(pNavMeshArray->FUN_00877a30(i).Modelloader_GetReferencedThis()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), m_uTotalCount);
        m_uTotalCount += pNavMeshArray->FUN_00877a30(i).Modelloader_GetReferencedThis()->NavMesh_GetTriangleCount();
        m_shell1c.AppendValue(pNavMeshArray->FUN_00877a30(i));
    }
    if (m_pData)
    {
        delete m_pData;
    }
    m_pData = new char[m_uTotalCount];
    for (j2 = 0; j2 < m_uTotalCount; j2++)
    {
        m_pData[j2] = 0x7f;
    }
    return true;
}

struct SeqEntry
{
    SeqEntry* Modelloader_GetReferencedThis();
    Script* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct SeqList
{
    unsigned int FUN_0044ddc0();
    SeqEntry* FUN_00877a30(unsigned int index);
};

struct SubMatcher
{
    bool FUN_00853130(Script* script, unsigned int* outLen);
};

struct SpawnedTarget
{
    void FUN_0042f4c0(SeqEntry* entry);
};

// Scans the sequence list, measuring each entry's script length; when a length exceeds limit, stores the remaining offset and passes the previous entry to target.
// @fnv 0x006e1670
// src: COMMUNITY 0x006e1670
char PathingLOSMap::GetNavMeshAndTriangleForIndex(unsigned int limit, SpawnedTarget* target, unsigned short* outOffset)
{
    unsigned int i;
    unsigned int accum;
    if (((ArrHelper*)((char*)this + 0x1c))->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        return 0;
    }

    i = 0;
    for (accum = 0; accum < ((SeqList*)((char*)this + 0x1c))->FUN_0044ddc0(); accum++)
    {
        unsigned int len;
        Script* script = ((SeqList*)((char*)this + 0x1c))->FUN_00877a30(accum)->Modelloader_GetReferencedThis()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        if (!((SubMatcher*)((char*)this + 8))->FUN_00853130(script, &len))
        {
            return 0;
        }
        if (len > limit)
        {
            *outOffset = (unsigned short)(limit - i);
            target->FUN_0042f4c0(((SeqList*)((char*)this + 0x1c))->FUN_00877a30(accum - 1));
            return 1;
        }
        else
        {
            i = len;
        }
    }
    *outOffset = (unsigned short)(limit - i);
    target->FUN_0042f4c0(((SeqList*)((char*)this + 0x1c))->FUN_00877a30(accum - 1));
    return 1;
}




void* __cdecl BSTestObjects_CreateCircle(float, int, void*);
void* __cdecl BSTestObjects_CreateCappedCylinder(float, float, float, int, int, void*);
void __cdecl AttachLightingPropertyRecursive(void*);
void __cdecl FUN_00b57e30(void*, int, int);
// This external call passes three trivial 12-byte vertices by value.  The
// shared NiPoint3 copy constructor must not change that calling sequence.
struct DebugTriangleVertex
{
    float components[3];
};
NiAVObject* __cdecl MakeTriangle(DebugTriangleVertex, DebugTriangleVertex, DebugTriangleVertex, const NiColorA*, int);

// @fnv 0x006e1800
NiSortAdjustNode* PathingLOSMap::CreateSortAdjustNode()
{
    NiSortAdjustNode* rootNode = new NiSortAdjustNode(0);
    NiPointer<NiAlphaProperty> spA(new NiAlphaProperty());
    spA->NiAlphaProperty_SetAlphaBlending(true);
    NiPointer<NiMaterialProperty> spB(new NiMaterialProperty());
    spB->NiMaterialProperty_SetEmittance((const NiColor*)&NiPoint3(1.0f, 1.0f, 1.0f));
    spB->NiMaterialProperty_SetAlpha(0.75f);
    rootNode->NiAVObject::AttachProperty((NiObject*)(NiAlphaProperty*)spA);
    rootNode->NiAVObject::AttachProperty((NiObject*)(NiMaterialProperty*)spB);

    char highest = (char)0x81;
    char low = (char)0x7f;
    for (unsigned int i = 0; i < (unsigned int)((Script*)this)->FUN_0055b980(); ++i)
    {
        char c = ((Script*)this)->GetByteAt(i);
        if (c == 0x7f)
            continue;
        highest = MaxChar(highest, c);
        low = MinChar(low, c);
    }

    rootNode->SetArraySize((unsigned int)((Script*)this)->FUN_0055b980() + 10);

    for (unsigned int j = 0; j < (unsigned int)((Script*)this)->FUN_0055b980(); ++j)
    {
        NavMeshPtr p2;
        unsigned short p0;
        if (!(unsigned char)GetNavMeshAndTriangleForIndex(j, (SpawnedTarget*)&p2, &p0))
            continue;
        char a = ((Script*)this)->GetByteAt(j);
        if (a == 0x7f)
            continue;
        float p = (a < 0) ? ((float)a / low * 0.5 + 0.5) : 0.0;
        float h1 = (a > 0) ? ((float)a / highest * 0.5 + 0.5) : 0.0;
        NiColorA h0(p, h1, 0.0f, 0.75f);
        NiPoint3 cf[3];
        NavMeshTriangle* h = p2->GetTriangle(p0);
        if (!h->GetFlag(0x20))
        {
            for (unsigned int k = 0; k < 3; ++k)
            {
                cf[k] = p2->GetVertex_0068f0a0(h->GetVert_005582d0(k));
                cf[k].z += 5.0;
            }
            NiPointer<NiAVObject> spC(MakeTriangle(*(DebugTriangleVertex*)&cf[0], *(DebugTriangleVertex*)&cf[1], *(DebugTriangleVertex*)&cf[2], &h0, 1));
            rootNode->AttachChildInAvailableSlot(spC, 1);
        }
    }

    if (this->f48 != 0.0)
    {
        NiSortAdjustNode* p4 = new NiSortAdjustNode(0);
        NiColorA vec(1.0f, 1.0f, 0.0f, 0.5f);
        for (unsigned int m = 0; m < 5; ++m)
        {
            void* ac = BSTestObjects_CreateCircle(this->f48, 0x24, &vec);
            ((NiAVObject*)ac)->NiAVObject_SetTranslate_004bc1f0(this->f3c, this->f40, (float)((double)m * 25.0 + this->f44));
            p4->AttachChildInAvailableSlot((NiAVObject*)ac, 1);
        }
        void* ac1 = BSTestObjects_CreateCappedCylinder(16.0f, 16.0f, 400.0f, 10, 10, &vec);
        ((NiSortAdjustNode*)ac1)->NiAVObject_SetTranslate(*(const NiPoint3*)&this->f3c);
        p4->AttachChildInAvailableSlot((NiAVObject*)ac1, 1);
        AttachLightingPropertyRecursive(p4);
        FUN_00b57e30(p4, 0, 0);
        rootNode->AttachChildInAvailableSlot((NiAVObject*)p4, 1);
    }

    rootNode->UpdateProperties();
    NiUpdateData updateData(0.0f, false, false);
    rootNode->Update((const NiUpdateData&)updateData);
    return rootNode;
}
