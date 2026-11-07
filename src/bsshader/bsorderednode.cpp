// bsshader/bsorderednode.cpp: BSOrderedNode, NiBound (6 functions)

#include "../../include/NiBinaryStream.h"
#include "../../include/NiBound.h"
#include "../../include/NiCullingProcess.h"
#include "../../include/NiNode.h"
#include "../../include/NiStream.h"
#include "../../include/NiTransform.h"

// The legacy declarations header defines NiSphere again, so retain its other declarations here.
// These loaders use different callback slots in their original stream layouts.
inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes)
{
    unsigned int size = 1;
    unsigned int result = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 8))(
        this, buffer, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += result;
    return result;
}

inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes)
{
    unsigned int size = 1;
    unsigned int result = (*reinterpret_cast<NIBINARYSTREAM_READFN*>(reinterpret_cast<char*>(this) + 12))(
        this, buffer, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += result;
    return result;
}
// Preserve the field offsets used by the two original loaders.
inline unsigned int NiStream::version()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

class BSOrderedNode : public NiNode
{
  public:
    NiSphere bound;
    bool staticBound;
    void LoadBinary(NiStream&);
};
// Calls NiNode::LoadBinary, loads bound from the stream, and reads staticBound when stream.version() > 23, otherwise sets it to true.
// @fnv 0x00bc2e80
void BSOrderedNode::LoadBinary(NiStream& stream)
{
    NiNode::LoadBinary(stream);
    bound.LoadBinary(stream);
    if (stream.version() > 23)
    {
        stream.GetBinaryStream()->Read(&staticBound, 1);
    }
    else
    {
        staticBound = true;
    }
}

inline bool NiBound::operator==(const NiBound& b) const
{
    return m_kCenter.x == b.m_kCenter.x && m_kCenter.y == b.m_kCenter.y &&
           m_kCenter.z == b.m_kCenter.z && m_fRadius == b.m_fRadius;
}
// Returns true when this NiBound differs from b, i.e. the negation of operator==.
// @fnv 0x00a926b0
// src: GUESS 0x00a926b0 (confidence: high)
bool NiBound::IsDifferent(const NiBound& b)
{
    return !(*this == b);
}

// ---------------------------------------------------------------------------
// UpdateCullingBound - the culling helper of a BSOrderedNode.
//
// The node hands its bound over to the accumulator of the culling process.
// A node with a static bound transforms the centre of its bound sphere with
// its own transform and scales the radius of the sphere; every other node
// just passes the bound it keeps itself (or the default bound when it has
// none).  Afterwards the node is notified about the culling process and the
// accumulator is closed.
// ---------------------------------------------------------------------------

// The accumulator of the culling process.
class DummyAccum
{
  public:
    void RenderBound(NiBound& bound, int flag);
    void DispatchBatchRenderer();
};

// The node the culling code works on.  Its layout is the one of a
// BSOrderedNode: the data of the node, the bound sphere and the flag that
// tells whether the bound is static.
class DummyNode
{
  public:
    unsigned char unk00[0x20];  // +0x00
    NiBound* pBound;            // +0x20  bound of a node without a static bound
    unsigned char unk24[0x44];  // +0x24
    NiTransform xform;          // +0x68
    unsigned char unk9c[0x10];  // +0x9c
    NiSphere bound;             // +0xac
    bool staticBound;           // +0xbc
    void NiNode_OnVisible(NiCullingProcess* culling);
    void UpdateCullingBound(NiCullingProcess* culling);
};

// The bound a node without a bound of its own is given.
extern NiBound g_defaultBound;

// @fnv 0x00bc2d70
void DummyNode::UpdateCullingBound(NiCullingProcess* culling)
{
    // The extended culling process stores its accumulator beyond the shared base.
    DummyAccum* accum = *reinterpret_cast<DummyAccum**>(reinterpret_cast<char*>(culling) + 0xc4);

    if (staticBound)
    {
        NiPoint3 centre;
        xform.ComputeValue_00524c40(&centre, &bound);

        // The original fills this storage without calling the NiBound constructor.
        NiSphere storage;
        NiBound& out = *reinterpret_cast<NiBound*>(&storage);
        out.m_kCenter = centre;
        out.m_fRadius = bound.r * xform.m_fScale;
        accum->RenderBound(out, 0);
    }
    else
    {
        NiBound* b = pBound;
        if (!b)
            b = &g_defaultBound;
        accum->RenderBound(*b, 0);
    }

    NiNode_OnVisible(culling);
    accum->DispatchBatchRenderer();
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct SpawnedObject
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    SpawnedObject();
};

class FUN_00bc2e00_cls
{
  public:
    void CopyTailFields(SpawnedObject* obj, void* arg);
    SpawnedObject* CreateSpawnedObject(void* arg);
};

// Allocates a SpawnedObject, initialises it via CopyTailFields with arg, and returns the new object.
// @fnv 0x00bc2e00
SpawnedObject* FUN_00bc2e00_cls::CreateSpawnedObject(void* arg)
{
    SpawnedObject* obj = 0;
    obj = new SpawnedObject();
    this->CopyTailFields(obj, arg);
    return obj;
}

struct FUN_00bc2ee0_cls : NiNode
{
    NiBound bound;
    bool staticBound;

    void NiNode_SaveBinary(NiStream& aStream);
    void LoadBoundSphereAndStaticBound(NiStream& aStream);
};

// Calls the base loader, loads the bound sphere from the stream, then reads one byte into staticBound.
// @fnv 0x00bc2ee0
void FUN_00bc2ee0_cls::LoadBoundSphereAndStaticBound(NiStream& aStream)
{
    NiNode_SaveBinary(aStream);
    bound.LoadBinary(aStream);

    aStream.Istr().BinaryRead(static_cast<void*>(&staticBound), 1);
}

struct S_00bc2f30_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
struct S_00bc2f30_Base
{
    void NiNode_GetViewerStrings(S_00bc2f30_Arr* a);
};
extern const char* DAT_01201f84;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* s);
char* __cdecl NiGetViewerString(const char* fmt, ...);
struct S_00bc2f30_Cls : S_00bc2f30_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    NiTransform m68;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    NiBound mAC;
    unsigned char mBC;
    void AppendAlphaSortBound(S_00bc2f30_Arr* a);
};
__forceinline void S_00bc2f30_Add(S_00bc2f30_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        a->FUN_0096ad30(i + a->growBy);
    a->FUN_0096ae90(i, s);
}
// @fnv 0x00bc2f30
void S_00bc2f30_Cls::AppendAlphaSortBound(S_00bc2f30_Arr* a)
{
    NiNode_GetViewerStrings(a);
    S_00bc2f30_Add(a, NiViewerStrings_NiGetViewerString_Title(DAT_01201f84));
    S_00bc2f30_Add(a, NiGetViewerString("bHasStaticBound", mBC));
    NiPoint3 sortVec;
    m68.ComputeValue_00524c40(&sortVec, reinterpret_cast<const NiSphere*>(&mAC));
    // The original fills this storage without calling the NiBound constructor.
    NiSphere storage;
    NiBound& b = *reinterpret_cast<NiBound*>(&storage);
    b.m_fRadius = mAC.m_fRadius * m68.m_fScale;
    b.m_kCenter = sortVec;
    S_00bc2f30_Add(a, b.GetViewerString_00a7fb20("Alpha Sort Bound"));
}
