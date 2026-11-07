
// src/gamebryo2.2/corelibs/nimain/nirenderer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirenderer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/StrArr.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiPoint3.h"

// @fnv 0x00a62ae0
// src: COMMUNITY 0x00a62ae0
void __cdecl NiRenderer__SDMShutdown()
{
    NiRenderer::ms_pRenderer = 0;
}

extern char const* const g_0126f0f0_arg1;

// @fnv 0x00a62b50
// src: COMMUNITY 0x00a62b50
char const* const* __cdecl NiRenderer_GetRTTI()
{
    return &g_0126f0f0_arg1;
}

// The shared base destructor has another binary entry point. Keep these
// renderer entry points explicit while using the shared object layout.
void __fastcall DestroyRenderer(NiRenderer* renderer);
void __cdecl _delete(void* p, unsigned int flags);
// @fnv 0x00a63230
void* __fastcall DeleteRenderer(NiRenderer* renderer, void*, unsigned int flags)
{
    DestroyRenderer(renderer);
    if (flags & 1)
        _delete(renderer, 0x280);
    return renderer;
}

void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330 to the StrArr, growing its size when it is full.
// @fnv 0x00a63260
// src: XBOX_PDB 0x00a63260
void __stdcall NiRenderer_GetViewerStrings(StrArr* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* psz = _FUN_00a7d330(g_0126f0f0_arg1);
    unsigned int uSize = pkStrings->m_usSize;
    unsigned int uMax = pkStrings->m_usMaxSize;
    if (uSize >= uMax)
        pkStrings->SetSize(uSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uSize, psz);
}

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* cs) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p) throw();

static __forceinline void ReleaseRendererObject(NiObject* object) throw()
{
    if (object && InterlockedDecrement(reinterpret_cast<long volatile*>(&object->m_uiRefCount)) == 0)
        object->DeleteThis();
}

extern void* NiRenderer_vtable[];

// @fnv 0x00a62b60
void __fastcall DestroyRenderer(NiRenderer* renderer)
{
    *reinterpret_cast<void***>(renderer) = NiRenderer_vtable;
    NiRenderer::ms_pRenderer = 0;
    DeleteCriticalSection(renderer->m_kSourceDataCriticalSection);
    DeleteCriticalSection(renderer->m_kPrecacheCriticalSection);
    DeleteCriticalSection(renderer->m_kRendererLock);
    ReleaseRendererObject(*reinterpret_cast<NiObject**>(renderer->m_spErrorShader));
    ReleaseRendererObject(*reinterpret_cast<NiObject**>(renderer->m_spAccum));
    renderer->FUN_00a5d3d0();
}

#include <math.h>
extern float DAT_0109bb88;
extern const double DAT_0101a6b0;

inline float NiPoint3::GetY() const
{
    return y;
}
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& pt) const
{
    NiPoint3 r;
    r.x = x + pt.x;
    r.y = y + pt.y;
    r.z = z + pt.z;
    return r;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    NiPoint3 r;
    r.x = x - pt.x;
    r.y = y - pt.y;
    r.z = z - pt.z;
    return r;
}
inline float NiPoint3::operator*(const NiPoint3& pt) const
{
    float d = x * pt.x + y * pt.y + z * pt.z;
    return d;
}
inline NiPoint3 NiPoint3::operator*(float s) const
{
    NiPoint3 r;
    r.x = x * s;
    r.y = y * s;
    r.z = z * s;
    return r;
}
inline NiPoint3 NiPoint3::Cross(const NiPoint3& pt) const
{
    NiPoint3 r;
    r.x = y * pt.z - z * pt.y;
    r.y = z * pt.x - x * pt.z;
    r.z = x * pt.y - y * pt.x;
    return r;
}
inline NiPoint3 NiPoint3::Sub(const NiPoint3& pt) const
{
    NiPoint3 r;
    r.x = x - pt.x;
    r.y = y - pt.GetY();
    r.z = z - pt.z;
    return r;
}
inline NiPoint3 NiPoint3::Add(const NiPoint3& pt) const
{
    NiPoint3 r;
    r.x = x + pt.x;
    r.y = GetY() + pt.y;
    r.z = z + pt.z;
    return r;
}

// The rotation matrix local of FUN_00a62be0 is trivially constructed (a POD 3x3 float matrix): the shared
// NiMatrix3's empty user-declared constructor alone reschedules 20 x87 bytes of the inlined row products,
// so this unit keeps its own POD view under a non-colliding name (its two methods bound to 0x004168a0 and 0x004b4500).
struct FUN_00a62be0_Matrix3
{
    float m[3][3];
    void __thiscall FUN_004168a0(float angle, float x, float y, float z);
    void MakeAxisAngleRotation(float angle, const NiPoint3& axis)
    {
        FUN_004168a0(angle, axis.x, axis.y, axis.z);
    }
    NiPoint3 FUN_004b4500(const NiPoint3& p) const
    {
        return NiPoint3(m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z, m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
                        m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z);
    }
};

// NiACos: inlined until the inline budget runs out, called after that
inline float AcosClamped(float v)
{
    if (v > DAT_0101a6b0)
    {
        if (v < 1.0f)
            return acos(v);
        return 0.0f;
    }
    return DAT_0109bb88;
}

// Computes four corner points and right/up axes around a center, using a basis or target direction and a given width.
// @fnv 0x00a62be0
// src: XBOX_PDB 0x00a62be0
bool __cdecl NiRenderer_PackParticleStripUtil_GetVerts(const NiPoint3** basis, const NiPoint3* apCenter, const NiPoint3* target, float width,
                          NiPoint3* corners, NiPoint3* axes, NiPoint3& direction)
{
    FUN_00a62be0_Matrix3 rotMatrix;
    NiPoint3 right, up;
    const NiPoint3* normal = basis[0];
    if (!normal && !target)
        return false;
    const NiPoint3* center = apCenter;
    if (!target)
    {
        direction = *basis[0];
        const NiPoint3* current = basis[0];
        const NiPoint3& currentNormal = *current;
        NiPoint3 axis = direction.Cross(*basis[0]);
        axis.Unitize_004a0c10();
        rotMatrix.FUN_004168a0(AcosClamped(currentNormal * direction), axis.x, axis.y, axis.z);
        const NiPoint3& basisRight = *basis[1];
        right = rotMatrix.FUN_004b4500(basisRight);
        normal = basis[2];
        up = rotMatrix.FUN_004b4500(*normal);
    }
    else if (!basis[0])
    {
        direction = target->Sub(*center);
        right = NiPoint3(0.0f, 0.1f, 1.0f);
        right.Unitize_004a0c10();
        up = right.Cross(direction);
        up.Unitize_004a0c10();
        right = up.Cross(direction);
        right.Unitize_004a0c10();
    }
    else
    {
        NiPoint3 delta = *target - *center;
        delta.Unitize_004a0c10();
        direction = *normal + delta;
        direction.Unitize_004a0c10();
        const NiPoint3& currentNormal = *basis[0];
        NiPoint3 axis = direction.Cross(*basis[0]);
        axis.Unitize_004a0c10();
        float angle = AcosClamped(direction * currentNormal);
        rotMatrix.MakeAxisAngleRotation(angle, axis);
        right = rotMatrix.FUN_004b4500(*basis[1]);
        up = rotMatrix.FUN_004b4500(*basis[2]);
    }
    direction.Unitize_004a0c10();
    corners[0] = center->Add(up * (float)(width * 0.5));
    corners[1] = center->Sub(up * (float)(width * 0.5));
    corners[2] = center->Add(right * (float)(width * 0.5));
    corners[3] = center->Sub(right * (float)(width * 0.5));
    axes[0] = right;
    axes[1] = up;
    return true;
}
