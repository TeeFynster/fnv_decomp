// gamebryo2.2/corelibs/nimain/nicamera.cpp: NiCamera, ComparableCamera, CamLook, ScreenCamera and more (20 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiCamera.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiRenderer.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"

// Preserve this unit's inline initialization of the time and five update flags.
inline NiUpdateData::NiUpdateData()
    : fTime(0.0f), pad1(false), pad2(false), pad3(false), pad4(false), pad5(false)
{}

// The shared stream layout is opaque; preserve this unit's inline field access.
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline unsigned short NiStream::savedFlags()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x284);
}

extern MemoryManager g_memoryManager;
extern const double runtimeInitializationDouble2;
extern "C"
{
    __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
}


// @fnv 0x00A711B0
void NiCamera::UpdateWorldData(NiUpdateData& update)
{
    NiAVObject::UpdateWorldData(update);
    UpdateWorldFrustum();
}

// @fnv 0x00A6FAF0
void NiCamera::UpdateViewFrustum(const NiFrustum& frustum)
{
    m_kViewFrustum.m_fNearPlane = frustum.m_fNearPlane;
    float minimumNear = frustum.m_fFarPlane / m_fMaxFarNearRatio;
    if (m_kViewFrustum.m_fNearPlane < minimumNear)
        m_kViewFrustum.m_fNearPlane = minimumNear;
    if (m_kViewFrustum.m_fNearPlane < m_fMinNearPlaneDist)
        m_kViewFrustum.m_fNearPlane = m_fMinNearPlaneDist;
    m_kViewFrustum.m_fLeftBound = frustum.m_fLeftBound;
    m_kViewFrustum.m_fRightBound = frustum.m_fRightBound;
    m_kViewFrustum.m_fTopBound = frustum.m_fTopBound;
    m_kViewFrustum.m_fBottomBound = frustum.m_fBottomBound;
    m_kViewFrustum.m_fFarPlane = frustum.m_fFarPlane;
    m_kViewFrustum.m_bOrthographic = frustum.m_bOrthographic;
}

// @fnv 0x00A711D0
void NiCamera::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    NiObject* obsoleteScene = stream.GetLoadedObject();
    if (obsoleteScene)
        InterlockedIncrement(reinterpret_cast<volatile long*>(&obsoleteScene->m_uiRefCount));
    unsigned int count = stream.GetLinkID();
    for (unsigned int i = 0; i < count; ++i)
    {
        NiObject* object = stream.GetLoadedObject();
        if (object)
        {
            InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
            if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)))
                object->DeleteThis();
        }
    }
    if (stream.GetFileVersion() >= 0x04010004)
    {
        count = stream.GetLinkID();
        for (unsigned int i = 0; i < count; ++i)
        {
            NiObject* object = stream.GetLoadedObject();
            if (object)
            {
                InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
                if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)))
                    object->DeleteThis();
            }
        }
        if (stream.GetFileVersion() >= 0x0a000107 && stream.GetFileVersion() < 0x0a00010f)
        {
            count = stream.GetLinkID();
            for (unsigned int i = 0; i < count; ++i)
                stream.GetLoadedObject();
        }
    }
    if (obsoleteScene && !InterlockedDecrement(reinterpret_cast<volatile long*>(&obsoleteScene->m_uiRefCount)))
        obsoleteScene->DeleteThis();
}

// @fnv 0x00A703A0
void NiCamera::ScreenPointToRay(float x, float y, NiPoint3& origin, NiPoint3& direction)
{
    if (m_kViewFrustum.m_bOrthographic)
    {
        NiPoint3 basis1;
        basis1.x = m_kWorld.m_Rotate.m_pEntry[0][0];
        basis1.y = m_kWorld.m_Rotate.m_pEntry[1][0];
        basis1.z = m_kWorld.m_Rotate.m_pEntry[2][0];
        direction = basis1;
        direction.ComputeMagnitude();

        NiPoint3 basis2;
        basis2.x = m_kWorld.m_Rotate.m_pEntry[0][1];
        basis2.y = m_kWorld.m_Rotate.m_pEntry[1][1];
        basis2.z = m_kWorld.m_Rotate.m_pEntry[2][1];
        NiPoint3 up;
        up.x = y * basis2.x;
        up.y = y * basis2.y;
        up.z = y * basis2.z;
        NiPoint3 basis3;
        basis3.x = m_kWorld.m_Rotate.m_pEntry[0][2];
        basis3.y = m_kWorld.m_Rotate.m_pEntry[1][2];
        basis3.z = m_kWorld.m_Rotate.m_pEntry[2][2];
        NiPoint3 right;
        right.x = x * basis3.x;
        right.y = x * basis3.y;
        right.z = x * basis3.z;
        NiPoint3 basis4;
        basis4.x = m_kWorld.m_Translate.x + right.x;
        basis4.y = m_kWorld.m_Translate.y + right.y;
        basis4.z = m_kWorld.m_Translate.z + right.z;
        NiPoint3 sum;
        sum.x = basis4.x + up.x;
        sum.y = basis4.y + up.y;
        sum.z = basis4.z + up.z;
        origin = sum;
    }
    else
    {
        NiPoint3 basis1;
        basis1.x = m_kWorld.m_Rotate.m_pEntry[0][1];
        basis1.y = m_kWorld.m_Rotate.m_pEntry[1][1];
        basis1.z = m_kWorld.m_Rotate.m_pEntry[2][1];
        NiPoint3 up;
        up.x = y * basis1.x;
        up.y = y * basis1.y;
        up.z = y * basis1.z;
        NiPoint3 basis2;
        basis2.x = m_kWorld.m_Rotate.m_pEntry[0][2];
        basis2.y = m_kWorld.m_Rotate.m_pEntry[1][2];
        basis2.z = m_kWorld.m_Rotate.m_pEntry[2][2];
        NiPoint3 right;
        right.x = x * basis2.x;
        right.y = x * basis2.y;
        right.z = x * basis2.z;
        NiPoint3 basis3;
        basis3.x = m_kWorld.m_Rotate.m_pEntry[0][0];
        basis3.y = m_kWorld.m_Rotate.m_pEntry[1][0];
        basis3.z = m_kWorld.m_Rotate.m_pEntry[2][0];
        NiPoint3 sum;
        sum.x = basis3.x + right.x;
        sum.y = basis3.y + right.y;
        sum.z = basis3.z + right.z;
        NiPoint3 basis4;
        basis4.x = sum.x + up.x;
        basis4.y = sum.y + up.y;
        basis4.z = sum.z + up.z;
        direction = basis4;
        direction.ComputeMagnitude();
        origin = m_kWorld.m_Translate;
    }
}

// @fnv 0x00A70B40
void NiCamera::UpdateWorldBound()
{
    if (!m_kWorldBound)
    {
        NiBound* bound = static_cast<NiBound*>(g_memoryManager.Allocate(sizeof(NiBound)));
        SetObjectBound(bound);
        bound = reinterpret_cast<NiBound*>(m_kWorldBound);
        bound->m_kCenter = NiPoint3::ZERO;
        bound->m_fRadius = 0.0f;
    }
    reinterpret_cast<NiBound*>(m_kWorldBound)->m_kCenter = m_kWorld.m_Translate;
}

#pragma optimize("", off)
// @fnv 0x0045BBE0
const NiFrustum& NiCamera::GetViewFrustum() const
{
    return m_kViewFrustum;
}
#pragma optimize("", on)

extern int DAT_0109cb9c;
void __fastcall ReleaseStorage_00a5a390(void* pThis);

#include "../../../../include/NiMemObject.h"

// @fnv 0x00a70050
void* __fastcall DestroyCamera(int* pThis, int, unsigned int flags)
{
    *pThis = (int)&DAT_0109cb9c;
    ReleaseStorage_00a5a390(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, 0x114);
    return pThis;
}

extern const char* const g_011f5e6c_arg1;
// @fnv 0x00a70040
// src: COMMUNITY 0x00a70040
const char* const* __cdecl NiCamera_GetRTTI()
{
    return &g_011f5e6c_arg1;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a713e0_shell : public NiCamera
{
    NiObject* NiCamera_CreateClone(CloningProcess*);
};

struct CameraCloneStorage
{
    CameraCloneStorage() throw();
    char body[0x114];

    static void* __cdecl operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
};
struct CamStub
{
    void NiCamera_CopyMembers(void*, CloningProcess*);
};
// @fnv 0x00a713e0
// src: XBOX_PDB 0x00a713e0
void* __fastcall NiCamera_CreateClone(CamStub* self, int edx, CloningProcess* kCloning)
{
    CameraCloneStorage* pkObject = new CameraCloneStorage();
    self->NiCamera_CopyMembers(pkObject, kCloning);
    return pkObject;
}

namespace fnv_00a71430 {
// @fnv 0x00a71430
// src: EXE 0x00a71430
CameraCloneStorage* NiCamera_CreateObject()
{
    return new CameraCloneStorage();
}
}  // namespace fnv_00a71430

// 0x00a5ad00 is the viewer append helper, not the shared virtual GetViewerStrings (0x00a5ea70).
struct CameraViewerAppender
{
    void AppendViewerStrings(StrArr* strings);
};

// The shared frustum and rect types do not declare these viewer formatting helpers.
void FormatFrustum();
void FormatCameraPort();

struct NiPoint3ViewerProxy
{
    char* GetViewerString_00a59af0(char const* name);
};

extern char const* const g_011f5e6c_arg1;

char* __cdecl _FUN_00a7d330(char const* value);
char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

struct FUN_00a71920_shell
{
    void NiCamera_GetViewerStrings(StrArr* strings);
};

// @fnv 0x00a71920
// src: XBOX_PDB 0x00a71920
void FUN_00a71920_shell::NiCamera_GetViewerStrings(StrArr* strings)
{
    reinterpret_cast<CameraViewerAppender*>(this)->AppendViewerStrings(strings);

    char* value;
    unsigned int index;
    unsigned int size;

    value = _FUN_00a7d330(g_011f5e6c_arg1);
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    value =
        reinterpret_cast<char* (__thiscall*)(NiFrustum*, const char*)>(FormatFrustum)(
            &reinterpret_cast<NiCamera*>(this)->m_kViewFrustum, "m_kViewFrustum");
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    value = reinterpret_cast<char* (__thiscall*)(NiRect<float>*, const char*)>(FormatCameraPort)(
        &reinterpret_cast<NiCamera*>(this)->m_kPort, "m_kPort");
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    NiPoint3 point;
    point.x = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x68);
    point.y = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x74);
    point.z = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x80);
    value = reinterpret_cast<NiPoint3ViewerProxy*>(&point)->GetViewerString_00a59af0("m_kWorldDir");
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    point.x = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x6c);
    point.y = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x78);
    point.z = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x84);
    value = reinterpret_cast<NiPoint3ViewerProxy*>(&point)->GetViewerString_00a59af0("m_kWorldUp");
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    point.x = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x70);
    point.y = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x7c);
    point.z = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x88);
    value = reinterpret_cast<NiPoint3ViewerProxy*>(&point)->GetViewerString_00a59af0("m_kWorldRight");
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fMinNearPlaneDist", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf8));
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d550("m_fMaxFarNearRatio", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xfc));
    index = strings->m_usSize;
    size = strings->m_usMaxSize;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_usGrowBy) + index);
    strings->SetAt(index, value);
}

extern double DAT_01011588;

class FUN_00a6fb90_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    void NiCamera_AdjustAspectRatio(float scale, unsigned char flag);
};

// Recomputes the four float members from the current pair, scaled by scale and DAT_01011588, swapping which pair is updated based on flag.
// @fnv 0x00a6fb90
// src: COMMUNITY 0x00a6fb90
void FUN_00a6fb90_cls::NiCamera_AdjustAspectRatio(float scale, unsigned char flag)
{
    if (flag != 0)
    {
        float d = m_fRightBound - m_fLeftBound;
        float tc = (float)((d / scale) * DAT_01011588);
        float fSum = (float)((m_fBottomBound + m_fTopBound) * DAT_01011588);
        m_fTopBound = fSum + tc;
        m_fBottomBound = fSum - tc;
    }
    else
    {
        float d = m_fTopBound - m_fBottomBound;
        float tc = (float)((d * scale) * DAT_01011588);
        float fSum = (float)((m_fRightBound + m_fLeftBound) * DAT_01011588);
        m_fRightBound = fSum + tc;
        m_fLeftBound = fSum - tc;
    }
}

struct ComparableCamera : NiCamera
{
    bool FUN_00a5a260(NiObject*);
    bool IsEqualTo(NiObject* other);
};
// @fnv 0x00a6ff20
bool ComparableCamera::IsEqualTo(NiObject* other)
{
    NiCamera* camera = (NiCamera*)other;
    if (FUN_00a5a260(other) && m_kViewFrustum.m_fLeftBound == camera->m_kViewFrustum.m_fLeftBound &&
        m_kViewFrustum.m_fRightBound == camera->m_kViewFrustum.m_fRightBound &&
        m_kViewFrustum.m_fTopBound == camera->m_kViewFrustum.m_fTopBound &&
        m_kViewFrustum.m_fBottomBound == camera->m_kViewFrustum.m_fBottomBound &&
        m_kViewFrustum.m_fNearPlane == camera->m_kViewFrustum.m_fNearPlane &&
        m_kViewFrustum.m_fFarPlane == camera->m_kViewFrustum.m_fFarPlane &&
        m_kPort.m_fMinimumU == camera->m_kPort.m_fMinimumU && m_kPort.m_fMaximumU == camera->m_kPort.m_fMaximumU &&
        m_kPort.m_fMinimumV == camera->m_kPort.m_fMinimumV && m_kPort.m_fMaximumV == camera->m_kPort.m_fMaximumV &&
        m_fLODAdjust == camera->m_fLODAdjust)
        return true;
    return false;
}

struct CamPoint
{
    float x, y, z;
    CamPoint()
    {}
    CamPoint(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    CamPoint operator-(const CamPoint& p) const
    {
        return CamPoint(x - p.x, y - p.y, z - p.z);
    }
    CamPoint operator-() const
    {
        return CamPoint(-x, -y, -z);
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
    void Unitize();
    CamPoint CrossProduct(const CamPoint& v) const;
};

struct CamMatrix
{
    float m_afEntries[3][3];
    CamMatrix()
    {}
    CamMatrix(const CamPoint& c0, const CamPoint& c1, const CamPoint& c2)
    {
        m_afEntries[0][0] = c0.x;
        m_afEntries[1][0] = c0.y;
        m_afEntries[2][0] = c0.z;
        m_afEntries[0][1] = c1.x;
        m_afEntries[1][1] = c1.y;
        m_afEntries[2][1] = c1.z;
        m_afEntries[0][2] = c2.x;
        m_afEntries[1][2] = c2.y;
        m_afEntries[2][2] = c2.z;
    }
    void SetCols(const CamPoint& c0, const CamPoint& c1, const CamPoint& c2)
    {
        m_afEntries[0][0] = c0.x;
        m_afEntries[1][0] = c0.y;
        m_afEntries[2][0] = c0.z;
        m_afEntries[0][1] = c1.x;
        m_afEntries[1][1] = c1.y;
        m_afEntries[2][1] = c1.z;
        m_afEntries[0][2] = c2.x;
        m_afEntries[1][2] = c2.y;
        m_afEntries[2][2] = c2.z;
    }
    CamMatrix ComposeMatrices(const CamMatrix& m) const;
};

struct CamLook : public NiCamera
{
    bool SetLookAt(const CamPoint& point, const CamPoint& up);
    const CamPoint& GetWorldTranslate() const
    {
        return *(const CamPoint*)&m_kWorld.m_Translate;
    }
    void SetLocalRotation(const CamMatrix& m)
    {
        *(CamMatrix*)&m_kLocal.m_Rotate = m;
    }
    __forceinline void Update(float t)
    {
        NiUpdateData data;
        data.fTime = t;
        data.pad1 = false;
        data.pad2 = false;
        data.pad3 = false;
        data.pad4 = false;
        data.pad5 = false;
        UpdateWorldData(data);
        UpdateWorldBound();
    }
};

// @fnv 0x00a701b0
bool CamLook::SetLookAt(const CamPoint& point, const CamPoint& worldUp)
{
    CamPoint dir = GetWorldTranslate() - point;
    if (dir.SqrLength() < (double)1e-10f)
        return false;
    dir.Unitize();
    CamMatrix rot;
    {
        CamPoint right = worldUp.CrossProduct(dir);
        if (right.SqrLength() < 0.5f)
            return false;
        CamPoint up = dir.CrossProduct(right);
        if (up.SqrLength() < 0.5f)
            return false;
        rot.SetCols(-dir, up, right);
    }
    if (m_pkParent)
        rot = ((const CamMatrix*)&m_pkParent->m_kWorld.m_Rotate)->ComposeMatrices(rot);
    SetLocalRotation(rot);
    Update(0.0f);
    return true;
}

struct ScreenCamera : public NiCamera
{
    bool ProjectToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float fZeroTolerance) const;
};

// @fnv 0x00a6fc50
bool ScreenCamera::ProjectToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float fZeroTolerance) const
{
    float fW = kPt.x * m_aafWorldToCam[3][0] + kPt.y * m_aafWorldToCam[3][1] + kPt.z * m_aafWorldToCam[3][2] +
               m_aafWorldToCam[3][3];

    if (fW > fZeroTolerance)
    {
        float fInvW = 1.0f / fW;

        fBx = kPt.x * m_aafWorldToCam[0][0] + kPt.y * m_aafWorldToCam[0][1] + kPt.z * m_aafWorldToCam[0][2] +
              m_aafWorldToCam[0][3];
        fBy = kPt.x * m_aafWorldToCam[1][0] + kPt.y * m_aafWorldToCam[1][1] + kPt.z * m_aafWorldToCam[1][2] +
              m_aafWorldToCam[1][3];

        fBx = fBx * fInvW;
        fBy = fBy * fInvW;

        if (fBx >= -1.0f && fBx <= 1.0f && fBy >= -1.0f && fBy <= 1.0f)
        {
            fBx = (m_kPort.m_fMaximumU - m_kPort.m_fMinimumU) * 0.5 * fBx;
            fBy = (m_kPort.m_fMinimumV - m_kPort.m_fMaximumV) * 0.5 * fBy;
            fBx += (m_kPort.m_fMaximumU + m_kPort.m_fMinimumU) * 0.5;
            fBy += (m_kPort.m_fMaximumV + m_kPort.m_fMinimumV) * 0.5;
            return true;
        }
    }

    return false;
}

class FUN_00a6ff10_StandIn
{
  public:
    bool FUN_00a59f00(NiStream& stream);
    bool NiDynamicEffect_RegisterStreamables(NiStream& stream);
};

// @fnv 0x00a6ff10
// src: XBOX_PDB 0x00a6ff10
bool FUN_00a6ff10_StandIn::NiDynamicEffect_RegisterStreamables(NiStream& stream)
{
    return FUN_00a59f00(stream);
}

struct NiCameraHack : NiCamera
{
    void NiCamera_LoadBinary(NiStream& stream);
};
inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    // The shared declaration does not expose the position or transfer callbacks.
    unsigned int uiBytesRead =
        (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
            this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytesRead;
    return uiBytesRead;
}
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(stream.GetBinaryStream(), &value, 1);
}
inline void ReadBinaryValue(NiStream& stream, bool& value)
{
    unsigned char ucValue;
    ReadBinaryValue(stream, ucValue);
    value = (ucValue != 0);
}

// Reads camera frustum, port, and trailing values from a NiStream, handling NIF version differences for flags and orthographic projection.
// @fnv 0x00a71450
// src: XBOX_PDB 0x00a71450
void NiCameraHack::NiCamera_LoadBinary(NiStream& stream)
{
    NiAVObject::LoadBinary(stream);

    unsigned int uiAVObjectFlags;
    if (stream.GetFileVersion() < 0x0A000102)
        uiAVObjectFlags = stream.savedFlags();
    else
    {
        NiBinaryStreamLoad(stream.GetBinaryStream(), (unsigned short*)&uiAVObjectFlags, 1);
    }
    ReadBinaryValue(stream, m_kViewFrustum.m_fLeftBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fRightBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fTopBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fBottomBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fNearPlane);
    ReadBinaryValue(stream, m_kViewFrustum.m_fFarPlane);

    if (stream.GetFileVersion() < 0x0A000105)
        m_kViewFrustum.m_bOrthographic = false;
    else
    {
        unsigned char ucOrthographic;
        ReadBinaryValue(stream, ucOrthographic);
        m_kViewFrustum.m_bOrthographic = (ucOrthographic != 0);
    }

    ReadBinaryValue(stream, m_kPort.m_fMinimumU);
    ReadBinaryValue(stream, m_kPort.m_fMaximumU);
    ReadBinaryValue(stream, m_kPort.m_fMinimumV);
    ReadBinaryValue(stream, m_kPort.m_fMaximumV);
    ReadBinaryValue(stream, m_fLODAdjust);

    stream.ResetStreamState();
    stream.ReadUnsignedInteger();

    if (stream.GetFileVersion() >= 0x04010004)
    {
        stream.ReadUnsignedInteger();
        if (stream.GetFileVersion() >= 0x0A000107)
        {
            if (stream.GetFileVersion() < 0x0A00010F)
                stream.ReadUnsignedInteger();
        }
    }
}

#include <math.h>
static inline float CamAbs(float fValue)
{
    return float(fabs(fValue));
}

struct FUN_00a6fdb0_t : public NiCamera
{
    bool ProjectPointToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float& fBz, float fZeroTolerance) const;
};

// Projects a world-space point into camera/screen space using m_aafWorldToCam and m_kPort, writing the result to fBx, fBy, fBz.
// @fnv 0x00a6fdb0
bool FUN_00a6fdb0_t::ProjectPointToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float& fBz,
                                          float fZeroTolerance) const
{
    bool bResult = false;
    float fW = m_aafWorldToCam[3][0] * kPt.x + m_aafWorldToCam[3][1] * kPt.y + m_aafWorldToCam[3][2] * kPt.z +
               m_aafWorldToCam[3][3];
    fW = CamAbs(fW);
    if (fW > fZeroTolerance)
    {
        bResult = true;
        float fInvW = 1.0f / fW;
        fBx = m_aafWorldToCam[0][0] * kPt.x + m_aafWorldToCam[0][1] * kPt.y + m_aafWorldToCam[0][2] * kPt.z +
              m_aafWorldToCam[0][3];
        fBy = m_aafWorldToCam[1][0] * kPt.x + m_aafWorldToCam[1][1] * kPt.y + m_aafWorldToCam[1][2] * kPt.z +
              m_aafWorldToCam[1][3];
        fBx = fBx * fInvW;
        fBy = fBy * fInvW;
        fBx *= (m_kPort.m_fMaximumU - m_kPort.m_fMinimumU) * 0.5f;
        fBy *= (m_kPort.m_fMinimumV - m_kPort.m_fMaximumV) * 0.5f;
        fBx += (m_kPort.m_fMaximumU + m_kPort.m_fMinimumU) * 0.5f;
        fBy += (m_kPort.m_fMaximumV + m_kPort.m_fMinimumV) * 0.5f;
        float fZ = m_aafWorldToCam[2][0] * kPt.x + m_aafWorldToCam[2][1] * kPt.y + m_aafWorldToCam[2][2] * kPt.z +
                   m_aafWorldToCam[2][3];
        fBz = fZ * fInvW;
    }
    return bResult;
}

// Plain vector values preserve the original bounds calculation return convention.
struct CameraBoundsVector
{
    float x, y, z;
};

struct CrossPoint : CameraBoundsVector
{
    __declspec(noalias) CameraBoundsVector CrossProduct(const CameraBoundsVector& vector) const;
};

inline CameraBoundsVector Scaled(float radius, const CameraBoundsVector& unit)
{
    CameraBoundsVector result;
    result.x = radius * unit.x;
    result.y = radius * unit.y;
    result.z = radius * unit.z;
    return result;
}

__forceinline CameraBoundsVector Added(const CameraBoundsVector& a, const CameraBoundsVector& b)
{
    CameraBoundsVector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

__forceinline void ClampBounds(float& lower, float& upper, float minimum, float maximum)
{
    if (lower < minimum)
    {
        lower = minimum;
        if (upper < minimum)
            upper = minimum;
        else if (upper > maximum)
            upper = maximum;
    }
    else if (upper > maximum)
    {
        upper = maximum;
        if (lower > maximum)
            lower = maximum;
    }
}

__forceinline void FullBound(CameraBoundsVector& lo, CameraBoundsVector& hi)
{
    lo.y = -1.0f;
    lo.x = -1.0f;
    hi.y = 1.0f;
    hi.x = 1.0f;
}

struct CameraBoundMatcher : public NiCamera
{
    void NiCamera_ScreenSpaceBoundBound(const NiBound& bound, NiPoint3& kMinBoundsCur, NiPoint3& kMaxPoint, float fTolerance);
};

// @fnv 0x00a705f0
// src: XBOX_PDB 0x00a705f0
void CameraBoundMatcher::NiCamera_ScreenSpaceBoundBound(const NiBound& bound, NiPoint3& minimum, NiPoint3& maximum, float fTolerance)
{
    CameraBoundsVector& kMinPoint = reinterpret_cast<CameraBoundsVector&>(minimum);
    CameraBoundsVector& kMaxPoint = reinterpret_cast<CameraBoundsVector&>(maximum);
    CameraBoundsVector kTargetCenter = reinterpret_cast<const CameraBoundsVector&>(bound.m_kCenter);
    float fRadius = bound.m_fRadius;
    CameraBoundsVector kScratch;
    kScratch.x = kTargetCenter.x - m_kWorld.m_Translate.x;
    kScratch.y = kTargetCenter.y - m_kWorld.m_Translate.y;
    kScratch.z = kTargetCenter.z - m_kWorld.m_Translate.z;
    float fInv = 1.0f / (m_kViewFrustum.m_fFarPlane - m_kViewFrustum.m_fNearPlane);
    CameraBoundsVector kCol0;
    kCol0.x = m_kWorld.m_Rotate.m_pEntry[0][0];
    kCol0.y = m_kWorld.m_Rotate.m_pEntry[1][0];
    kCol0.z = m_kWorld.m_Rotate.m_pEntry[2][0];
    float m_fProjectionDepth = kCol0.x * kScratch.x + kCol0.y * kScratch.y + kCol0.z * kScratch.z;
    m_fProjectionDepth = m_fProjectionDepth - m_kViewFrustum.m_fNearPlane;
    if (m_kViewFrustum.m_bOrthographic)
    {
        kMinPoint.z = 0.0f;
        kMaxPoint.z = 0.0f;
    }
    else
    {
        kMinPoint.z = float(m_fProjectionDepth - fRadius) * fInv;
        kMaxPoint.z = float(m_fProjectionDepth + fRadius) * fInv;
    }
    {
        CameraBoundsVector kRel;
        kRel.x = m_kWorld.m_Rotate.m_pEntry[0][1];
        kRel.y = m_kWorld.m_Rotate.m_pEntry[1][1];
        kRel.z = m_kWorld.m_Rotate.m_pEntry[2][1];
        CameraBoundsVector kCross = Scaled(fRadius, ((const CrossPoint&)kScratch).CrossProduct(kRel));
        CameraBoundsVector kPt;
        kPt.x = kTargetCenter.x - kCross.x;
        kPt.y = kTargetCenter.y - kCross.y;
        kPt.z = kTargetCenter.z - kCross.z;
        float fW = kPt.x * m_aafWorldToCam[3][0] + (double)(kPt.y * m_aafWorldToCam[3][1]) +
                   (double)(kPt.z * m_aafWorldToCam[3][2]) + m_aafWorldToCam[3][3];
        if (fW > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        float coordinateX = kPt.x;
        float coordinateZ = kPt.z;
        kMinPoint.x = (coordinateX * m_aafWorldToCam[0][0] + kPt.y * m_aafWorldToCam[0][1] +
                       coordinateZ * m_aafWorldToCam[0][2] + m_aafWorldToCam[0][3]) /
                      fW;
        CameraBoundsVector kPositive = Added(kTargetCenter, kCross);
        float fWMax = kPositive.x * m_aafWorldToCam[3][0] + kPositive.y * m_aafWorldToCam[3][1] +
                      kPositive.z * m_aafWorldToCam[3][2] + m_aafWorldToCam[3][3];
        if (fWMax > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        kMaxPoint.x = (kPositive.x * m_aafWorldToCam[0][0] + kPositive.y * m_aafWorldToCam[0][1] +
                       kPositive.z * m_aafWorldToCam[0][2] + m_aafWorldToCam[0][3]) /
                      fWMax;
    }
    {
        CameraBoundsVector kRel;
        kRel.x = m_kWorld.m_Rotate.m_pEntry[0][2];
        kRel.y = m_kWorld.m_Rotate.m_pEntry[1][2];
        kRel.z = m_kWorld.m_Rotate.m_pEntry[2][2];
        CameraBoundsVector kCross = Scaled(fRadius, ((const CrossPoint&)kRel).CrossProduct(kScratch));
        CameraBoundsVector kPt;
        kPt.x = kTargetCenter.x - kCross.x;
        kPt.y = kTargetCenter.y - kCross.y;
        kPt.z = kTargetCenter.z - kCross.z;
        float fW = kPt.x * m_aafWorldToCam[3][0] + kPt.y * m_aafWorldToCam[3][1] + kPt.z * m_aafWorldToCam[3][2] +
                   m_aafWorldToCam[3][3];
        if (fW > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        kMinPoint.y = ((double)(kPt.x * m_aafWorldToCam[1][0]) + (double)(kPt.y * m_aafWorldToCam[1][1]) +
                       kPt.z * m_aafWorldToCam[1][2] + m_aafWorldToCam[1][3]) /
                      fW;
        CameraBoundsVector kPositive;
        kPositive.x = kTargetCenter.x + kCross.x;
        kPositive.y = kTargetCenter.y + kCross.y;
        kPositive.z = kTargetCenter.z + kCross.z;
        float fWMax = kPositive.x * m_aafWorldToCam[3][0] + kPositive.y * m_aafWorldToCam[3][1] +
                      kPositive.z * m_aafWorldToCam[3][2] + m_aafWorldToCam[3][3];
        if (fWMax > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        kMaxPoint.y = (kPositive.x * m_aafWorldToCam[1][0] + kPositive.y * m_aafWorldToCam[1][1] +
                       kPositive.z * m_aafWorldToCam[1][2] + m_aafWorldToCam[1][3]) /
                      fWMax;
    }
    ClampBounds(kMinPoint.x, kMaxPoint.x, -1.0f, 1.0f);
    ClampBounds(kMinPoint.y, kMaxPoint.y, -1.0f, 1.0f);

    ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
}

struct CameraVector
{
    float x, y, z;
    float UpDot(const CameraVector& b) const
    {
        return (x * b.x) + y * b.y + z * b.z;
    }
    CameraVector()
    {}
    CameraVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    float Dot(const CameraVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    float ParenDot(const CameraVector& b) const
    {
        return (x * b.x + y * b.y) + z * b.z;
    }
    float operator*(const CameraVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};
struct CameraMatrix
{
    float m_afEntries[3][3];
    void GetCol(int col, CameraVector& out) const
    {
        out.x = m_afEntries[0][col];
        out.y = m_afEntries[1][col];
        out.z = m_afEntries[2][col];
    }
};


inline const CameraMatrix& CameraRotation(const NiCamera* camera)
{
    return *(const CameraMatrix*)&camera->m_kWorld.m_Rotate;
}
inline void CameraRight(const NiCamera* camera, float& x, float& y, float& z)
{
    x = camera->m_kWorld.m_Rotate.m_pEntry[0][2];
    y = camera->m_kWorld.m_Rotate.m_pEntry[1][2];
    z = camera->m_kWorld.m_Rotate.m_pEntry[2][2];
}

// Computes the m_aafWorldToCam matrix from the camera orientation, translation, and view frustum for orthographic or perspective projection.
// @fnv 0x00a70ba0
void NiCamera::UpdateWorldToCamera()
{
    CameraVector kWorldPosition;
    CameraRotation(this).GetCol(0, kWorldPosition);
    CameraVector kLoc = *(const CameraVector*)&m_kWorld.m_Translate;
    CameraVector kUp;
    CameraRotation(this).GetCol(1, kUp);
    CameraVector kRight;
    CameraRight(this, kRight.x, kRight.y, kRight.z);

    float fRightDot = -kLoc.Dot(kRight);
    float fUpDot = -kLoc.UpDot(kUp);
    float fDirDot = -kLoc.Dot(kWorldPosition);

    float fRpL = m_kViewFrustum.m_fRightBound + m_kViewFrustum.m_fLeftBound;
    float fBpT = m_kViewFrustum.m_fBottomBound + m_kViewFrustum.m_fTopBound;
    float fInvRmL = 1.0f / (m_kViewFrustum.m_fRightBound - m_kViewFrustum.m_fLeftBound);
    float fInvTmB = 1.0f / (m_kViewFrustum.m_fTopBound - m_kViewFrustum.m_fBottomBound);
    float fInvFmN = 1.0f / (m_kViewFrustum.m_fFarPlane - m_kViewFrustum.m_fNearPlane);

    if (m_kViewFrustum.m_bOrthographic)
    {
        float f2RmL = (float)(2.0 * fInvRmL);
        float f2TmB = (float)(2.0 * fInvTmB);
        m_aafWorldToCam[0][0] = kRight.x * f2RmL;
        m_aafWorldToCam[0][1] = kRight.y * f2RmL;
        m_aafWorldToCam[0][2] = kRight.z * f2RmL;
        float fA = fRpL * fInvRmL;
        m_aafWorldToCam[0][3] = fA + fRightDot * f2RmL;
        m_aafWorldToCam[1][0] = kUp.x * f2TmB;
        m_aafWorldToCam[1][1] = kUp.y * f2TmB;
        m_aafWorldToCam[1][2] = kUp.z * f2TmB;
        float fB = fBpT * fInvTmB;
        m_aafWorldToCam[1][3] = fB + fUpDot * f2TmB;
        m_aafWorldToCam[2][0] = kWorldPosition.x * fInvFmN;
        m_aafWorldToCam[2][1] = kWorldPosition.y * fInvFmN;
        m_aafWorldToCam[2][2] = kWorldPosition.z * fInvFmN;
        float fC = -m_kViewFrustum.m_fNearPlane * fInvFmN;
        m_aafWorldToCam[2][3] = fDirDot * fInvFmN + fC;
        m_aafWorldToCam[3][0] = 0.0f;
        m_aafWorldToCam[3][1] = 0.0f;
        m_aafWorldToCam[3][2] = 0.0f;
        m_aafWorldToCam[3][3] = 1.0f;
    }
    else
    {
        float f2RmL = (float)(2.0 * fInvRmL);
        float fA = -fRpL * fInvRmL;
        float f2TmB = (float)(2.0 * fInvTmB);
        float fB = -fBpT * fInvTmB;
        float fF = m_kViewFrustum.m_fFarPlane * fInvFmN;
        m_aafWorldToCam[0][0] = fA * kWorldPosition.x + f2RmL * kRight.x;
        m_aafWorldToCam[0][1] = fA * kWorldPosition.y + f2RmL * kRight.y;
        m_aafWorldToCam[0][2] = fA * kWorldPosition.z + f2RmL * kRight.z;
        m_aafWorldToCam[0][3] = fA * fDirDot + f2RmL * fRightDot;
        m_aafWorldToCam[1][0] = fB * kWorldPosition.x + f2TmB * kUp.x;
        m_aafWorldToCam[1][1] = fB * kWorldPosition.y + f2TmB * kUp.y;
        m_aafWorldToCam[1][2] = fB * kWorldPosition.z + f2TmB * kUp.z;
        m_aafWorldToCam[1][3] = fB * fDirDot + f2TmB * fUpDot;
        m_aafWorldToCam[2][0] = fF * kWorldPosition.x;
        m_aafWorldToCam[2][1] = fF * kWorldPosition.y;
        m_aafWorldToCam[2][2] = fF * kWorldPosition.z;
        float fC = -m_kViewFrustum.m_fNearPlane * fF;
        m_aafWorldToCam[2][3] = fF * fDirDot + fC;
        m_aafWorldToCam[3][0] = kWorldPosition.x;
        m_aafWorldToCam[3][1] = kWorldPosition.y;
        m_aafWorldToCam[3][2] = kWorldPosition.z;
        m_aafWorldToCam[3][3] = fDirDot;
    }
}

extern "C" void* __cdecl FUN_00ec44d0(void* destination, const void* source, unsigned int count);

union FUN_00a70f60_FloatBits
{
    float f;
    unsigned int i;
};

struct FUN_00a70f60_Obj
{
    void __thiscall NiCamera_CopyMembers(NiCamera* destination, int second);
};

// Copies NiCamera state from source to destination via base copy, memcpy, and field assignments.
// @fnv 0x00a70f60
// src: XBOX_PDB 0x00a70f60
void __thiscall FUN_00a70f60_Obj::NiCamera_CopyMembers(NiCamera* destination, int second)
{
    NiCamera* source = reinterpret_cast<NiCamera*>(this);

    source->NiAVObject::CopyMembers_00a5ac90(destination, *reinterpret_cast<CloningProcess*>(second));

    FUN_00ec44d0(reinterpret_cast<char*>(destination) + 0x9C, reinterpret_cast<char*>(source) + 0x9C, 0x40);

    FUN_00a70f60_FloatBits* sourceTranslate =
        reinterpret_cast<FUN_00a70f60_FloatBits*>(reinterpret_cast<char*>(source) + 0x8C);
    FUN_00a70f60_FloatBits* destinationTranslate =
        reinterpret_cast<FUN_00a70f60_FloatBits*>(reinterpret_cast<char*>(destination) + 0x8C);

    destinationTranslate[0].i = sourceTranslate[0].i;
    destinationTranslate[1].i = sourceTranslate[1].i;
    destinationTranslate[2].i = sourceTranslate[2].i;

    destination->m_kViewFrustum = source->m_kViewFrustum;

    volatile int* sourceValues = reinterpret_cast<volatile int*>(reinterpret_cast<char*>(source) + 0x100);
    volatile int* destinationValues = reinterpret_cast<volatile int*>(reinterpret_cast<char*>(destination) + 0x100);

    destinationValues[0] = sourceValues[0];
    destinationValues[1] = sourceValues[1];
    destinationValues[2] = sourceValues[2];
    destinationValues[3] = sourceValues[3];

    float* sourceFloats = reinterpret_cast<float*>(reinterpret_cast<char*>(source) + 0x110);
    float* destinationFloats = reinterpret_cast<float*>(reinterpret_cast<char*>(destination) + 0x110);

    destinationFloats[0] = sourceFloats[0];
    destinationFloats[-6] = sourceFloats[-6];
    destinationFloats[-5] = sourceFloats[-5];
}

struct CameraWindowRay : NiCamera
{
    bool MapScreenToRay(long x, long y, NiPoint3& origin, NiPoint3& direction, const NiRenderTargetGroup* group);
};
// Maps screen coordinates to a view-space ray using the camera port and view frustum, returning false if the point is outside the port.
// @fnv 0x00a71080
bool CameraWindowRay::MapScreenToRay(long aiScreenX, long aiScreenY, NiPoint3& origin, NiPoint3& direction,
                                     const NiRenderTargetGroup* apRenderTargetGroup)
{
    if (!NiRenderer::ms_pRenderer)
        return false;
    float fMappedU, fMappedV;
    {
        float mappedX, mappedY;
        if (!NiRenderer::ms_pRenderer->MapScreenCoordinates(aiScreenX, aiScreenY, mappedX, mappedY,
                                                            apRenderTargetGroup))
            return false;
        if (mappedX > m_kPort.m_fMaximumU || mappedX < m_kPort.m_fMinimumU || mappedY > m_kPort.m_fMinimumV ||
            mappedY < m_kPort.m_fMaximumV)
            return false;
        fMappedU = mappedX;
        fMappedV = mappedY;
    }
    ScreenPointToRay(
        m_kViewFrustum.m_fLeftBound +
            (m_kViewFrustum.m_fRightBound - m_kViewFrustum.m_fLeftBound) *
                static_cast<float>((fMappedU - m_kPort.m_fMinimumU) / (m_kPort.m_fMaximumU - m_kPort.m_fMinimumU)),
        m_kViewFrustum.m_fBottomBound +
            (m_kViewFrustum.m_fTopBound - m_kViewFrustum.m_fBottomBound) *
                static_cast<float>((fMappedV - m_kPort.m_fMaximumV) / (m_kPort.m_fMinimumV - m_kPort.m_fMaximumV)),
        origin, direction);
    return true;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes,
                                                unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    // The shared declaration does not expose the position or transfer callbacks.
    unsigned int uiBytesWritten =
        (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(
            this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += uiBytesWritten;
    return uiBytesWritten;
}

template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& binary, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return binary.BinaryWrite(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

inline NiBinaryStream* GetOstr(NiStream& kStream)
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x250);
}

template <class T> inline void SerializeValue(NiStream& kStream, const T& tValue)
{
    WriteBinaryArray(*GetOstr(kStream), &tValue, 1);
}

struct NiCamera_Candidate : public NiCamera
{
    void NiCamera_SaveBinary(NiStream& kStream);
};

// Saves the camera's AV object data, view frustum, port, and link ID to the binary stream via SerializeValue calls.
// @fnv 0x00a716c0
// src: XBOX_PDB 0x00a716c0
void NiCamera_Candidate::NiCamera_SaveBinary(NiStream& kStream)
{
    NiAVObject::SaveBinary(kStream);

    unsigned short usFlags = 0;
    SerializeValue(kStream, usFlags);

    SerializeValue(kStream, m_kViewFrustum.m_fLeftBound);
    SerializeValue(kStream, m_kViewFrustum.m_fRightBound);
    SerializeValue(kStream, m_kViewFrustum.m_fTopBound);
    SerializeValue(kStream, m_kViewFrustum.m_fBottomBound);
    SerializeValue(kStream, m_kViewFrustum.m_fNearPlane);
    SerializeValue(kStream, m_kViewFrustum.m_fFarPlane);
    bool bOrtho = m_kViewFrustum.m_bOrthographic;
    SerializeValue(kStream, bOrtho);

    SerializeValue(kStream, m_kPort.m_fMinimumU);
    SerializeValue(kStream, m_kPort.m_fMaximumU);
    SerializeValue(kStream, m_kPort.m_fMinimumV);
    SerializeValue(kStream, m_kPort.m_fMaximumV);

    SerializeValue(kStream, m_fLODAdjust);

    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(0));

    unsigned int ItemUpdateArray = 0;
    SerializeValue(kStream, ItemUpdateArray);
    SerializeValue(kStream, ItemUpdateArray);
}

#include <string.h>
int NiSprintf(char*, unsigned int, const char*, ...);
void* NiMalloc(unsigned int);



// Formats the rect's four float bounds into a newly allocated string prefixed by pPrefix.
// @fnv 0x00a71020
template <> char* NiRect<float>::ToString(const char* pPrefix) const
{
    char* pString;
    unsigned int uiLen;
    uiLen = (unsigned int)strlen(pPrefix) + 64;
    pString = (char*)NiMalloc(uiLen);
    NiSprintf(pString, uiLen, "%s = (L=%g,R=%g,T=%g,B=%g)", pPrefix, m_fMinimumU, m_fMaximumU, m_fMinimumV,
              m_fMaximumV);
    return pString;
}

extern const float g_fDefaultMaxFarNearRatioA71;

// NiFrustum is shared by NiCamera.h; its constructor at 0x00a71b70 is not declared there.
void InitializeFrustum();
inline void InitializeCameraFrustum(NiFrustum* frustum, bool orthographic) throw()
{
    reinterpret_cast<void (__thiscall*)(NiFrustum*, bool)>(InitializeFrustum)(frustum, orthographic);
}



inline void InitializeCameraPort(NiRect<float>& port)
{
    port.m_fMinimumU = 0.0f;
    port.m_fMaximumU = 0.0f;
    port.m_fMinimumV = 0.0f;
    port.m_fMaximumV = 0.0f;
}

// Keep the original constructor's non-throwing base update contract.
inline void UpdateCameraConstructionData(NiAVObject* object, NiUpdateData& data) throw()
{
    object->NiAVObject::UpdateWorldData(data);
}

inline void CameraConstructFrustum(NiCamera* camera) throw()
{
    camera->UpdateWorldToCamera();
}
inline void CameraConstructBound(NiCamera* camera) throw()
{
    camera->NiCamera::UpdateWorldBound();
}

// Initialises the camera's view frustum, port, near/far limits and trailing value, then calls UpdateWorldData, UpdateWorldFrustum and UpdateCameras.
// @fnv 0x00a712f0
extern void* g_NiCameraVftable;
NiCamera::NiCamera()
{
    // The shared novtable declaration suppresses this exe-required vftable write.
    *reinterpret_cast<void**>(this) = &g_NiCameraVftable;
    InitializeCameraFrustum(&m_kViewFrustum, false);
    InitializeCameraPort(m_kPort);
    m_kViewFrustum.m_bOrthographic = false;
    m_kViewFrustum.m_fNearPlane = 1.0f;
    m_kViewFrustum.m_fFarPlane = 2.0f;
    m_kViewFrustum.m_fTopBound = 0.5f;
    m_kViewFrustum.m_fBottomBound = -0.5f;
    m_kViewFrustum.m_fLeftBound = -0.5f;
    m_kViewFrustum.m_fRightBound = 0.5f;
    m_fMinNearPlaneDist = 0.1f;
    m_fMaxFarNearRatio = g_fDefaultMaxFarNearRatioA71;
    m_kPort.m_fMinimumV = 1.0f;
    m_kPort.m_fMaximumU = 1.0f;
    m_fLODAdjust = 1.0f;
    m_kPort.m_fMaximumV = 0.0f;
    m_kPort.m_fMinimumU = 0.0f;

    NiUpdateData kData;
    UpdateCameraConstructionData(this, kData);
    CameraConstructFrustum(this);
    CameraConstructBound(this);
}

inline NiPoint3 CameraForwardVector(const NiCamera& camera)
{
    NiPoint3 direction;
    direction.x = camera.m_kWorld.m_Rotate.m_pEntry[0][0];
    direction.y = camera.m_kWorld.m_Rotate.m_pEntry[1][0];
    direction.z = camera.m_kWorld.m_Rotate.m_pEntry[2][0];
    return direction;
}

inline NiPoint3 CameraPointDifference(const NiPoint3& first, const NiPoint3& second)
{
    NiPoint3 difference;
    difference.x = first.x - second.x;
    difference.y = first.y - second.y;
    difference.z = first.z - second.z;
    return difference;
}

// Projects a bound onto the camera's forward axis to set the view frustum near/far planes, then updates world data and bound.
// @fnv 0x00a70080
// src: COMMUNITY 0x00a70080
bool NiCamera::FitNearAndFarToBound(const NiBound& bound)
{
    NiPoint3 kWDir = CameraForwardVector(*this);
    NiPoint3 kDiff = CameraPointDifference(bound.m_kCenter, m_kWorld.m_Translate);
    float fProjection = kWDir.x * kDiff.x + kWDir.y * kDiff.y + kDiff.z * kWDir.z;
    float fNear = fProjection - bound.m_fBoundRadius;
    float fFar = fProjection + bound.m_fBoundRadius;
    if (fFar <= 0.0f)
        return false;
    float minimum = fFar / m_fMaxFarNearRatio;
    if (fNear < minimum)
        fNear = minimum;
    if (fNear < m_fMinNearPlaneDist)
        fNear = m_fMinNearPlaneDist;
    m_kViewFrustum.m_fNearPlane = fNear;
    m_kViewFrustum.m_fFarPlane = fFar;
    NiUpdateData update;
    UpdateWorldData(update);
    UpdateWorldBound();
    return true;
}
