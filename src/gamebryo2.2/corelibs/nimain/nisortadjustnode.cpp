// src/gamebryo2.2/corelibs/nimain/nisortadjustnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nisortadjustnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiSortAdjustNode.h"
#include "../../../../include/NiStream.h"

extern "C" void* g_011f5ed8;
extern int DAT_010a0384;
void __fastcall UpdateFields_00c5faa0(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void* __cdecl Object_DispatchCommandFour(unsigned int);

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}

// The shared header does not yet expose the position and transfer callbacks.
// Keep the inline I/O here, using its callback types without a second class layout.
inline void NiBinaryStream::Write(void* buf)
{
    unsigned int size = 4;
    unsigned int& position = *(unsigned int*)((char*)this + 4);
    position += (*(NIBINARYSTREAM_WRITEFN*)((char*)this + 0xc))(this, buf, 4, &size, 1);
}
inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiComponentSize = 4;
    unsigned int uiRead = (*(NIBINARYSTREAM_READFN*)((char*)this + 8))(
        this, pvBuffer, uiBytes, &uiComponentSize, 1);
    *(unsigned int*)((char*)this + 4) += uiRead;
    return uiRead;
}

// NiStream keeps its fields opaque in the shared header.
inline unsigned int NiStream::GetFileVersion() const
{
    return *(const unsigned int*)((const char*)this + 0xd8);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *(NiBinaryStream**)((char*)this + 0x24c);
}

inline NiBinaryStream* SortAdjustOutputStream(NiStream& stream)
{
    return *(NiBinaryStream**)((char*)&stream + 0x250);
}

struct SortAdjustVisibleObject
{
    unsigned char _00[0x30];
    unsigned int m_uiObjectFlags;
};
struct SortAdjustVisibleList
{
    SortAdjustVisibleObject** m_ppItems;
    unsigned int m_uItemCount;
};
struct SortAdjustCullingData
{
    int unk00;
    int unk04;
    SortAdjustVisibleList* m_pEntries;
};

// NiNode does not declare its equality override; retain only the direct-call
// declaration, without a second NiNode layout.
struct NiNodeEqualityCalls
{
    bool IsEqual(NiObject* other);
};

// The shared NiSortAdjustNode header does not expose the trailing mode yet.
inline int& SortAdjustMode(NiSortAdjustNode* node)
{
    return *(int*)((char*)node + sizeof(NiNode));
}

inline NiSortAdjustNode* ConstructSortAdjustNode(void* storage) throw()
{
    ::new (storage) NiNode(0);
    *(void**)storage = &DAT_010a0384;
    NiSortAdjustNode* node = (NiSortAdjustNode*)storage;
    SortAdjustMode(node) = 0;
    return node;
}

// Missing streaming, cloning, equality and culling declarations remain free
// functions here. Their unused second fastcall parameter preserves the game's
// ECX object argument and stack arguments without another class definition.

// @fnv 0x00a95310
// src: COMMUNITY 0x00a95310
void* __cdecl NiSortAdjustNode_GetRTTI()
{
    return &g_011f5ed8;
}

// @fnv 0x00a95320
void* __thiscall NiSortAdjustNode::Destructor(unsigned int flags)
{
    *(void**)this = &DAT_010a0384;
    UpdateFields_00c5faa0(this);
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xb0);
    return this;
}

// @fnv 0x00a952a0
// src: EXE 0x00a952a0
void* __cdecl NiSortAdjustNode_CreateObject()
{
    void* p = BSFadeNode::operator new(0xB0);
    if (p)
    {
        ::new (p) NiNode(0);
        *(void**)p = (void*)&DAT_010a0384;
        SortAdjustMode((NiSortAdjustNode*)p) = 0;
        return p;
    }
    return 0;
}

// @fnv 0x00a95410
void __fastcall LinkSortAdjustNode(NiSortAdjustNode* self, void*, NiStream& stream)
{
    self->NiNode::ReadChildListFromStream(stream);
    if (stream.GetFileVersion() < 0x14000004)
        stream.GetLoadedObject();
}

// @fnv 0x00a954b0
void __fastcall SaveSortAdjustNode(NiSortAdjustNode* self, void*, NiStream& stream)
{
    self->NiNode::SaveBinary(stream);
    SortAdjustOutputStream(stream)->Write(&SortAdjustMode(self));
}

// @fnv 0x00a952e0
unsigned char __fastcall IsSortAdjustNodeEqual(NiSortAdjustNode* self, void*, NiSortAdjustNode* other)
{
    unsigned char result = ((NiNodeEqualityCalls*)self)->IsEqual(other);
    if (!result)
        return result;
    return (unsigned char)(SortAdjustMode(self) == SortAdjustMode(other));
}

// @fnv 0x00a953b0
NiNode* __fastcall CloneSortAdjustNode(NiSortAdjustNode* self, void*, void* process)
{
    void* storage = Object_DispatchCommandFour(0xb0);
    NiSortAdjustNode* p = storage ? ConstructSortAdjustNode(storage) : 0;
    self->NiNode::CopyMemberData(p, *(CloningProcess*)process);
    SortAdjustMode(p) = SortAdjustMode(self);
    return p;
}

// @fnv 0x00a95440
void __fastcall LoadSortAdjustNode(NiSortAdjustNode* self, void*, NiStream& stream)
{
    self->NiNode::LoadBinary(stream);
    int eMode;
    stream.GetBinaryStream()->BinaryRead((void*)&eMode, 4);
    SortAdjustMode(self) = eMode;
    if (SortAdjustMode(self) >= 2)
        SortAdjustMode(self) = 0;
    if (stream.GetFileVersion() < 0x14000004)
        stream.ReadLinkID();
}

// @fnv 0x00a95350
void __fastcall CullSortAdjustNode(NiSortAdjustNode* self, void*, SortAdjustCullingData* pArg)
{
    bool hide = (SortAdjustMode(self) != 1);
    unsigned int start = pArg->m_pEntries->m_uItemCount;
    self->NiNode::OnVisible(*(NiCullingProcess*)pArg);

    SortAdjustVisibleList* pList = pArg->m_pEntries;
    unsigned int end = pList->m_uItemCount;
    unsigned int uiIndex = start;
    if (uiIndex < end)
    {
        do
        {
            SortAdjustVisibleObject* pItem = pList->m_ppItems[uiIndex];
            if (!hide)
                pItem->m_uiObjectFlags |= 0x40u;
            else
                pItem->m_uiObjectFlags &= 0xffffffbfu;
            uiIndex++;
        } while (uiIndex < end);
    }
}

void __cdecl NiNode_ProcessClone();
// @fnv 0x00a95290
// src: XBOX_PDB 0x00a95290
void __cdecl NiSortAdjustNode_ProcessClone()
{
    NiNode_ProcessClone();
}
