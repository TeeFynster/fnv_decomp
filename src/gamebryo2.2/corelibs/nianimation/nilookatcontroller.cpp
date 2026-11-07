#include "../../../../include/BSFaceGenMorphData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiLookAtController.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiTPointerMap.h"

// src/gamebryo2.2/corelibs/nianimation/nilookatcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nilookatcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f98;

// @fnv 0x00a4cd30
// src: COMMUNITY 0x00a4cd30
void* __cdecl NiLookAtController_GetRTTI()
{
    return &g_011f3f98;
}

void __cdecl FUN_00a6d290();
extern "C" __declspec(noinline) void __cdecl _delete(void* p, unsigned int flags);

// Calls FUN_00a6d290, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00a4cd40
void* __thiscall NiLookAtController::FUN_00a4cd40(unsigned int flags)
{
    FUN_00a6d290();
    if (flags & 1)
        _delete(this, 0x3c);
    return this;
}

struct BaseStub
{
    void FUN_00a6d830(StrArr*);
};
char* _FUN_00a7d330(const char*);

// Appends the string returned by _FUN_00a7d330(g_011f3f98) to pkStrings, growing its size first if it is full.
// @fnv 0x00a4cef0
void NiLookAtController::AppendString(StrArr* pkStrings)
{
    ((BaseStub*)this)->FUN_00a6d830(pkStrings);
    char* s = _FUN_00a7d330((const char*)g_011f3f98);
    unsigned int sz = pkStrings->m_usSize;
    if (sz >= pkStrings->m_usMaxSize)
    {
        unsigned int gr = pkStrings->m_usGrowBy;
        pkStrings->SetSize(gr + sz);
    }
    pkStrings->SetAt(sz, s);
}

// The stream stays opaque here; this accessor takes only the this register.
NiObject* __fastcall GetLoadedObject(NiStream* stream);

// @fnv 0x00a4c840
// src: XBOX_PDB 0x00a4c840
void NiLookAtController::LinkObject_00a4c840(NiStream& stream)
{
    NiTimeController::LinkObject(stream);
    m_pkLookAt = static_cast<NiAVObject*>(GetLoadedObject(&stream));
}

struct TCReg
{
    bool __thiscall NiTimeController_RegisterStreamables(NiStream&);
};

// @fnv 0x00a4c860
// src: XBOX_PDB 0x00a4c860
bool __thiscall NiLookAtController::RegisterStreamables_00a4c860(NiStream& s)
{
    if (!((TCReg*)this)->NiTimeController_RegisterStreamables(s))
        return false;
    if (m_pkLookAt)
        m_pkLookAt->RegisterStreamables(s);
    return true;
}

struct BinaryInput
{
    unsigned int flags;
    unsigned int position;
    unsigned int(__cdecl* read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int);
};
struct StreamLayout
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int version;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    BinaryInput* input;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned short unk284;
    unsigned short controllerFlags;
};
struct BaseLoad
{
    void FUN_00a6d5e0(NiStream&);
};
struct StreamFinish
{
    void ReadLinkID();
};

// @fnv 0x00a4ce20
// src: XBOX_PDB 0x00a4ce20
void NiLookAtController::LoadBinary_00a4ce20(NiStream& stream)
{
    reinterpret_cast<BaseLoad*>(this)->FUN_00a6d5e0(stream);
    StreamLayout& streamLayout = reinterpret_cast<StreamLayout&>(stream);
    if (streamLayout.version < 0x0a000102)
    {
        *reinterpret_cast<unsigned short*>(_pad) = (streamLayout.controllerFlags >> 5) & 0xff;
    }
    else
    {
        BinaryInput* input = streamLayout.input;
        unsigned int(__cdecl * read)(BinaryInput*, void*, unsigned int, unsigned int*, unsigned int) = input->read;
        unsigned int size = 2;
        input->position += read(input, _pad, 2, &size, 1);
    }
    reinterpret_cast<StreamFinish*>(&stream)->ReadLinkID();
}

struct BaseClone
{
    void FUN_00a6d0c0(void* item);
};

// Resolves the look-at object through the cloning map after the base controller.
// @fnv 0x00a4ccd0
void NiLookAtController::LookupAndLinkItem(void* apItem)
{
    NiObject* local;
    void* pItem;
    bool bFound;
    NiAVObject* pResolved;
    // NiTimeController uses this object cloning map; its GetAt is bound to 0x00a53c30.
    NiTPointerMap<NiObject*, NiObject*>* pMap;

    pItem = apItem;
    reinterpret_cast<BaseClone*>(this)->FUN_00a6d0c0(pItem);
    pMap = *reinterpret_cast<NiTPointerMap<NiObject*, NiObject*>**>(pItem);
    apItem = 0;
    pMap->GetAt(this, reinterpret_cast<NiObject*&>(apItem));
    if (m_pkLookAt != 0)
    {
        bFound = (*reinterpret_cast<NiTPointerMap<NiObject*, NiObject*>**>(pItem))->GetAt(m_pkLookAt, local);
        if (!bFound)
        {
            pResolved = m_pkLookAt;
        }
        else
        {
            pResolved = static_cast<NiAVObject*>(local);
        }
        static_cast<NiLookAtController*>(apItem)->m_pkLookAt = pResolved;
    }
}

// The object the stream keeps at +0x250: a counter that is accumulated over
// the callback plus the callback slot itself.
struct Handler
{
    unsigned int unk000;
    int counter;
    unsigned int unk008;
    typedef int(__cdecl* FnType)(Handler* self, void* arg2, int arg3, int* arg4, int arg5);
    FnType fn;
};

// The stream the controller reads its data from.  Its virtual table entry 12
// (vtable offset 0x30) is the method the controller calls back into.
struct StreamObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12(NiAVObject* arg);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    Handler* m250;
};

// The base class that owns the shared stream handling.
struct Base44
{
    void FUN_00a6d730(StreamObj* stream);
};

// @fnv 0x00a4cea0
// src: XBOX_PDB 0x00a4cea0
void NiLookAtController::SaveBinary_00a4cea0(NiStream* pkStream)
{
    StreamObj* stream = reinterpret_cast<StreamObj*>(pkStream);
    reinterpret_cast<Base44*>(this)->FUN_00a6d730(stream);
    Handler* handler = stream->m250;
    {
        // The out-value is kept in an inner block on purpose: that way the
        // callback expression is a genuine call operand, so it is loaded into
        // the caller's register (EDX) and hoisted to the top of the block,
        // while the store into the out-value stays ordered after the load.
        int local = 2;
        handler->counter += handler->fn(handler, _pad, 2, &local, 1);
    }
    stream->v12(m_pkLookAt);
}

// The shared header leaves the controller flag word unnamed at +0x34.
struct LookAtFlags
{
    void SetBit(bool bVal, unsigned short usMask)
    {
        if (bVal)
            value |= usMask;
        else
            value &= ~usMask;
    }
    bool GetBit(unsigned short usMask) const
    {
        return (value & usMask) != 0;
    }
    void SetField(unsigned short us, unsigned short usMask, unsigned short usPos)
    {
        value = (value & ~usMask) | (us << usPos);
    }
    unsigned short GetField(unsigned short usMask, unsigned short usPos) const
    {
        return (value & usMask) >> usPos;
    }

    unsigned short value;
};
inline LookAtFlags& Flags(NiLookAtController* controller)
{
    return *reinterpret_cast<LookAtFlags*>(controller->_pad);
}
inline const LookAtFlags& Flags(const NiLookAtController* controller)
{
    return *reinterpret_cast<const LookAtFlags*>(controller->_pad);
}

struct BaseCopy
{
    void FUN_00a6cfe0(NiTimeController* destination, void* process);
};
extern int DAT_01098c14;
void __fastcall FUN_00a6d220(void*) throw();

// The base constructor's nonthrowing entry is not declared in the shared header.
inline NiLookAtController* AllocateLookAtController()
{
    NiLookAtController* controller = static_cast<NiLookAtController*>(
        BSFaceGenMorphData::operator new(sizeof(NiLookAtController)));
    NiLookAtController* result;
    if (controller)
    {
        FUN_00a6d220(controller);
        *reinterpret_cast<void**>(controller) = &DAT_01098c14;
        controller->m_pkLookAt = 0;
        *reinterpret_cast<unsigned short*>(controller->_pad) = 0;
        controller->m_uiObjectFlags &= ~0x40;
        result = controller;
    }
    else
        result = 0;
    return result;
}

// @fnv 0x00a4cd60
// src: XBOX_PDB 0x00a4cd60
NiLookAtController* NiLookAtController::CreateClone_00a4cd60(void* pkCloning)
{
    NiLookAtController* pkClone = AllocateLookAtController();
    reinterpret_cast<BaseCopy*>(this)->FUN_00a6cfe0(pkClone, pkCloning);
    LookAtFlags& source = Flags(this);
    LookAtFlags& destination = Flags(pkClone);
    destination.value = source.value;
    destination.SetBit(source.GetBit(1), 1);
    destination.SetField(source.GetField(6, 1), 6, 1);
    pkClone->m_pkLookAt = m_pkLookAt;
    return pkClone;
}

// @fnv 0x00a4cde0
void* __cdecl CreateMorphData()
{
    return AllocateLookAtController();
}

struct BaseEqual
{
    bool NiTimeController_IsEqual(NiLookAtController* other);
};

// Compares the base controller and the optional look-at object.
// @fnv 0x00a4c890
// src: XBOX_PDB 0x00a4c890
bool NiLookAtController::IsEqual_00a4c890(NiLookAtController* other)
{
    if (!reinterpret_cast<BaseEqual*>(this)->NiTimeController_IsEqual(other))
        return false;
    if ((m_pkLookAt && !other->m_pkLookAt) || (!m_pkLookAt && other->m_pkLookAt))
        return false;
    if (m_pkLookAt && !m_pkLookAt->IsEqual(other->m_pkLookAt))
        return false;
    return true;
}

struct S00a4c8e0_Pt
{
    float x, y, z;
    S00a4c8e0_Pt()
    {}
    S00a4c8e0_Pt(float a, float b, float c) : x(a), y(b), z(c)
    {}
    S00a4c8e0_Pt operator-(const S00a4c8e0_Pt& b) const
    {
        return S00a4c8e0_Pt(x - b.x, y - b.y, z - b.z);
    }
    S00a4c8e0_Pt operator+(const S00a4c8e0_Pt& b) const
    {
        return S00a4c8e0_Pt(x + b.x, y + b.y, z + b.z);
    }
    S00a4c8e0_Pt operator*(float f) const
    {
        return S00a4c8e0_Pt(x * f, y * f, z * f);
    }
    S00a4c8e0_Pt operator-() const
    {
        return S00a4c8e0_Pt(-x, -y, -z);
    }
    S00a4c8e0_Pt& operator-=(const S00a4c8e0_Pt& p)
    {
        x -= p.x;
        y -= p.y;
        z -= p.z;
        return *this;
    }
    float Dot(const S00a4c8e0_Pt& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    S00a4c8e0_Pt Cross(const S00a4c8e0_Pt& p) const
    {
        return S00a4c8e0_Pt(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }
    __declspec(noalias) void Unitize_004a0c10();
};
struct S00a4c8e0_Mat
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    S00a4c8e0_Pt FUN_004b4500(const S00a4c8e0_Pt&) const;
    S00a4c8e0_Mat FUN_00a588a0(const S00a4c8e0_Mat&) const;
    void Identity()
    {
        m00 = 1;
        m01 = 0;
        m02 = 0;
        m10 = 0;
        m11 = 1;
        m12 = 0;
        m20 = 0;
        m21 = 0;
        m22 = 1;
    }
    void Column0(const S00a4c8e0_Pt& p)
    {
        m00 = p.x;
        m10 = p.y;
        m20 = p.z;
    }
    void Column1(const S00a4c8e0_Pt& p)
    {
        m01 = p.x;
        m11 = p.y;
        m21 = p.z;
    }
    void Column2(const S00a4c8e0_Pt& p)
    {
        m02 = p.x;
        m12 = p.y;
        m22 = p.z;
    }
};

extern S00a4c8e0_Mat DAT_011a9448;
extern S00a4c8e0_Pt DAT_011a9478;
extern S00a4c8e0_Pt DAT_011a9484;

inline bool NiLookAtController::GetFlip() const
{
    return (Flags(this).value & 1) != 0;
}
inline unsigned short NiLookAtController::GetAxis() const
{
    return (Flags(this).value & 6) >> 1;
}
inline bool NiLookAtController::IsActive() const
{
    return ((m_uiObjectFlags >> 3) & 1) != 0;
}

// Rotates the controlled node to face the target node by building a look-at matrix from their world positions and applying the parent transform.
// @fnv 0x00a4c8e0
void NiLookAtController::Update(NiUpdateData& update)
{
    if (!m_pkLookAt || !IsActive())
        return;
    S00a4c8e0_Pt targetPos = reinterpret_cast<const S00a4c8e0_Pt&>(m_pkLookAt->m_kWorld.m_Translate);
    NiAVObject* node = reinterpret_cast<NiAVObject*>(m_pkTarget);
    NiAVObject* pParent = reinterpret_cast<NiAVObject*>(node->m_pkParent);
    S00a4c8e0_Mat parentRot;
    S00a4c8e0_Pt worldPos;
    if (pParent)
    {
        parentRot = reinterpret_cast<const S00a4c8e0_Mat&>(pParent->m_kWorld.m_Rotate);
        float parentScale = pParent->m_kWorld.m_fScale;
        worldPos = reinterpret_cast<const S00a4c8e0_Pt&>(pParent->m_kWorld.m_Translate) + parentRot.FUN_004b4500(reinterpret_cast<const S00a4c8e0_Pt&>(node->m_kLocal.m_Translate)) * parentScale;
    }
    else
    {
        parentRot = DAT_011a9448;
        worldPos = reinterpret_cast<const S00a4c8e0_Pt&>(node->m_kLocal.m_Translate);
    }
    S00a4c8e0_Pt at = targetPos - worldPos;
    S00a4c8e0_Mat rot;
    float fDistSq = at.Dot(at);
    if (fDistSq < 0.001f)
    {
        rot.Identity();
    }
    else
    {
        at.Unitize_004a0c10();
        S00a4c8e0_Pt up;
        float d;
        if (at.z < 1.001f && at.z > 0.9990000128746033)
        {
            up = DAT_011a9478;
            d = at.y;
        }
        else
        {
            up = DAT_011a9484;
            d = at.z;
        }
        up -= at * d;
        up.Unitize_004a0c10();
        if (!GetFlip())
            at = -at;
        S00a4c8e0_Pt right = up.Cross(at);
        switch (GetAxis())
        {
        case 0:
            rot.Column0(at);
            rot.Column1(up);
            rot.Column2(-right);
            break;
        case 1:
            rot.Column0(right);
            rot.Column1(at);
            rot.Column2(-up);
            break;
        case 2:
            rot.Column0(right);
            rot.Column1(up);
            rot.Column2(at);
            break;
        }
        rot = parentRot.FUN_00a588a0(rot);
    }
    reinterpret_cast<S00a4c8e0_Mat&>(node->m_kLocal.m_Rotate) = rot;
}
