
// src/gamebryo2.2/corelibs/nimain/nicullingprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicullingprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiPlane.h"

extern char const* const g_01201f7c_arg1;

// @fnv 0x00a693f0
// src: COMMUNITY 0x00a693f0
char const* const* const __cdecl NiCullingProcess_GetRTTI()
{
    return &g_01201f7c_arg1;
}

struct SevenInts
{
    int v[7];
};
struct H74e10
{
    void __thiscall SetFromFrustum(void*, void*);
};
struct S694a0
{
    char _00[12];
    char* _0c;
    char _10[28];
    H74e10 _2c;
    char _pad[95];
    int _8c;
    void __thiscall NiCullingProcess_SetFrustum(void*);
};
// If _0c is set, copies seven ints from src into _10, calls SetFromFrustum on _10 and _0c+0x68, then sets _8c to 63.
// @fnv 0x00a694a0
// src: XBOX_PDB 0x00a694a0
void __thiscall S694a0::NiCullingProcess_SetFrustum(void* pSource)
{
    if (_0c)
    {
        *(SevenInts*)_10 = *(SevenInts*)pSource;
        _2c.SetFromFrustum(_10, _0c + 0x68);
        _8c = 63;
    }
}

struct WorkerS694a0
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    NiPlane planes[6];
    unsigned int flags;
    void __thiscall NiCullingProcess_DoCulling(NiAVObject* object);
};
// @fnv 0x00a694e0
// src: COMMUNITY 0x00a694e0
void WorkerS694a0::NiCullingProcess_DoCulling(NiAVObject* object)
{
    NiBound* bound = reinterpret_cast<NiBound*>(object->m_kWorldBound);
    if (!bound)
        return;
    float radius = bound->m_fRadius;
    if (radius == 0.0f)
        return;
    unsigned int uiSavedFlags = flags;
    unsigned int uiPlaneIndex = 0;
    unsigned int mask = 1;
    NiPlane* plane = planes;
    for (; uiPlaneIndex < 6; ++uiPlaneIndex, ++plane, mask = (mask << 1) | (mask >> 31))
    {
        if (flags & mask)
        {
            int side = const_cast<NiBound&>(object->NiAVObject_GetWorldBound()).WhichSide(plane);
            if (side == 2)
                break;
            if (side == 1)
                flags &= ~mask;
        }
    }
    if (uiPlaneIndex == 6)
        object->OnVisible(*reinterpret_cast<NiCullingProcess*>(this));
    flags = uiSavedFlags;
}

// local form of NiFrustum: 0x00a69400 needs constructor-initializer ordering and the ctor return contract; explicit shared Init changes bytes.
class A69400Frustum
{
  public:
    A69400Frustum(float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar, bool bOrtho);

    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};

class A69400FrustumPlanes
{
  public:
    A69400FrustumPlanes()
    {
        m_uiActivePlaneMask = 0x3f;
    }

    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
};

class FUN_00a69400
{
  public:
    FUN_00a69400(void* pkCamera);
    virtual void vfunc00();

    bool m_bUpdated;
    void* m_pkAccumulationCamera;
    int m_iArrayLength;
    A69400Frustum m_kCameraFrustum;
    A69400FrustumPlanes m_kFrustumPlanes;
};

// @fnv 0x00a69400
FUN_00a69400::FUN_00a69400(void* pkCamera)
    : m_bUpdated(false), m_kCameraFrustum(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, false)
{
    m_pkAccumulationCamera = pkCamera;
    m_iArrayLength = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObjView
{
    virtual void vslot0();
    virtual void vslot1();
    virtual void vslot2();
    virtual void vslot3();
    virtual void vslot4();
    virtual void vslot5();
    virtual void vslot6();
    virtual void vslot7();
    virtual void vslot8();
    virtual void vslot9();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35(void*);
    virtual void vslot36();
    volatile long refCount;
};
struct GlobalMgr
{
    int unk00, unk04;
    void* unk08;
    void __thiscall SetFromCamera(void*);
};
extern GlobalMgr* DAT_011f4748;
struct RefLookup
{
    RefObjView* volatile obj;
    void __thiscall FUN_0066b0d0(void*);
};
struct Handler
{
    void __thiscall FUN_00a59e00(void*);
};
struct Sub694a0 : S694a0
{
    void __thiscall ProcessWorkerWithHandler(void* worker, Handler* handler, void* temporary);
};
// @fnv 0x00a69570
void Sub694a0::ProcessWorkerWithHandler(void* worker, Handler* handler, void* temporary)
{
    if (worker != 0 && handler != 0)
    {
        _0c = (char*)worker;
        NiCullingProcess_SetFrustum((char*)worker + 0xdc);
        void* previous = 0;
        if (temporary)
        {
            previous = *(void**)(_00 + 8);
            *(void**)(_00 + 8) = temporary;
        }
        RefObjView* ref = 0;
        RefLookup refLookup;
        refLookup.obj = 0;
        if (!*(void**)(_00 + 8))
        {
            refLookup.FUN_0066b0d0(DAT_011f4748->unk08);
            ref = refLookup.obj;
            if (ref)
                ref->vslot35(worker);
        }
        handler->FUN_00a59e00(this);
        if (ref)
        {
            DAT_011f4748->SetFromCamera(worker);
            ref->vslot36();
        }
        if (temporary)
            *(void**)(_00 + 8) = previous;
        _0c = 0;
        if (ref && InterlockedDecrement(&ref->refCount) == 0)
            ref->vslot1();
    }
}

struct WorkerA69640 : WorkerS694a0
{
    void __thiscall ProcessObject(NiAVObject* object);
};
// Checks bits 12, 20 and 11 of the object's flags and either invokes the object's callback or calls FUN_00a694e0 based on them and this->flags.
// @fnv 0x00a69640
void WorkerA69640::ProcessObject(NiAVObject* object)
{
    if (static_cast<bool>((object->m_uFlags >> 12) & 1))
    {
        if (!static_cast<bool>((object->m_uFlags >> 20) & 1))
        {
            object->OnVisible(*reinterpret_cast<NiCullingProcess*>(this));
        }
    }
    else if (!static_cast<bool>((object->m_uFlags >> 11) & 1) && this->flags != 0)
    {
        this->NiCullingProcess_DoCulling(object);
    }
    else
    {
        object->OnVisible(*reinterpret_cast<NiCullingProcess*>(this));
    }
}

extern MemoryManager g_memoryManager;
struct FUN_00a69470
{
    virtual ~FUN_00a69470();
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// @fnv 0x00a69470
FUN_00a69470::~FUN_00a69470()
{}
