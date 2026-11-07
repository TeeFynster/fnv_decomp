#include "../../../include/NiPointer.h"
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }

// src/fallout_shared/settings/xgamesetting_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/settings/xgamesetting.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../include/NiObject.h"
#include "../../../include/NiSourceTexture.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiTransform.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/NiCamera.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/StrArr.h"
#include "../../../include/Transform.h"

extern const NiRTTI g_011f3fd4;
extern const NiRTTI g_011f49a4;
extern const NiRTTI g_011f4428;
struct FUN_00a4f300_shell
{
    int unk[16];
    unsigned short pad40;
    unsigned short m_usElementCount;
    void* GetEntryAt(int i);
};
using ::NiPointer;
struct NiNodeY
{
    int unk[0x28];
    NiPointer<NiAVObject>* m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    __forceinline NiPointer<NiAVObject>& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
__forceinline bool IsKindOfA(const NiRTTI* r)
{
    while (r)
    {
        if (r == &g_011f49a4)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}
__forceinline bool IsKindOfN(const NiRTTI* r)
{
    while (r)
    {
        if (r == &g_011f4428)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}
__forceinline NiAVObject* CastA(NiAVObject* p)
{
    if (!p)
        return 0;
    return (NiAVObject*)(IsKindOfA(p->GetRTTI()) ? p : 0);
}
__forceinline NiNodeY* CastN(NiAVObject* p)
{
    int u;
    if (!p)
        return 0;
    return (NiNodeY*)(IsKindOfN(p->GetRTTI()) ? p : 0);
}

// @fnv 0x00c4bd80
// src: COMMUNITY 0x00c4bd80
void __cdecl BSUtilities_FindAnimatedTextures(NiAVObject* obj, StrArr* arr)
{
    NiNodeY* node7;
    FUN_00a4f300_shell* c7;
    NiAVObject* propA;
    NiAVObject* geom2;
    unsigned int count4;
    unsigned int i3;
    char* s2;
    unsigned int j;
    if (obj)
    {
        c7 = (FUN_00a4f300_shell*)obj->GetController(&g_011f3fd4);
        if (!c7 && (obj->IsTriBasedGeometry() || obj->IsParticlesGeom()))
        {
            geom2 = obj;
            propA = CastA((NiAVObject*)geom2->GetProperty(5));
            if (propA)
                c7 = (FUN_00a4f300_shell*)((NiAVObject*)propA)->GetController(&g_011f3fd4);
        }
        if (c7)
        {
            count4 = c7->m_usElementCount;
            for (i3 = 0; i3 < count4; i3++)
            {
                s2 = (char*)c7->GetEntryAt(i3);
                if (s2)
                    (arr->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(s2);
            }
        }
        node7 = CastN(obj);
        if (node7)
        {
            for (j = 0; j < node7->m_usSize; j++)
            {
                BSUtilities_FindAnimatedTextures(node7->GetAt(j), arr);
            }
        }
    }
}

inline float NiMatrix3::GetEntry(unsigned int uiRow, unsigned int uiCol) const
{
    return reinterpret_cast<const float (*)[3]>(&m_pEntry[0][0])[uiRow][uiCol];
}

namespace fnv_00c4c2d0 {
struct Mat4
{
    float m[4][4];
};
extern NiPoint3 DAT_011f474c;
extern "C" Mat4* __stdcall D3DXMatrixInverse_00ee6dda(Mat4* pOut, float* pDet, const Mat4* pM);
inline void Dead21()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
}
// @fnv 0x00c4c2d0
// src: COMMUNITY 0x00c4c2d0
void __cdecl BSUtilities_GetInverseWorldMatrix(NiAVObject* pObj, int bInverse, Mat4* pOut)
{
    if (!bInverse)
    {
        // The output method fills this transform without default construction.
        float transformStorage[sizeof(NiTransform) / sizeof(float)];
        pObj->FUN_004b4880(reinterpret_cast<NiTransform*>(transformStorage));
        Dead21();
        pOut->m[0][0] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(0, 0) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[0][1] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(1, 0) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[0][2] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(2, 0) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[0][3] = 0.0f;
        pOut->m[1][0] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(0, 1) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[1][1] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(1, 1) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[1][2] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(2, 1) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[1][3] = 0.0f;
        pOut->m[2][0] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(0, 2) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[2][1] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(1, 2) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[2][2] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Rotate.GetEntry(2, 2) * reinterpret_cast<const NiTransform*>(transformStorage)->m_fScale;
        pOut->m[2][3] = 0.0f;
        pOut->m[3][0] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Translate.x;
        pOut->m[3][1] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Translate.y;
        pOut->m[3][2] = reinterpret_cast<const NiTransform*>(transformStorage)->m_Translate.z;
        pOut->m[3][3] = 1.0f;
    }
    else
    {
        Mat4 kM;
        kM.m[3][2] = 0.0f;
        kM.m[3][1] = 0.0f;
        kM.m[3][0] = 0.0f;
        kM.m[2][3] = 0.0f;
        kM.m[2][1] = 0.0f;
        kM.m[2][0] = 0.0f;
        kM.m[1][3] = 0.0f;
        kM.m[1][2] = 0.0f;
        kM.m[1][0] = 0.0f;
        kM.m[0][3] = 0.0f;
        kM.m[0][2] = 0.0f;
        kM.m[0][1] = 0.0f;
        kM.m[3][3] = 1.0f;
        kM.m[2][2] = 1.0f;
        kM.m[1][1] = 1.0f;
        kM.m[0][0] = 1.0f;
        const NiPoint3& rPos = DAT_011f474c;
        kM.m[3][0] = rPos.x;
        kM.m[3][1] = rPos.y;
        kM.m[3][2] = rPos.z;
        D3DXMatrixInverse_00ee6dda(pOut, 0, &kM);
    }
}
}  // namespace fnv_00c4c2d0

inline float GetTransformEntry(const Transform::Mat* rotation, unsigned int row, unsigned int column)
{
    return rotation->entries[row][column];
}

// @fnv 0x00c4c530
// src: COMMUNITY 0x00c4c530
void __cdecl BSUtilities_ApplyTransformToVerticesAndNormals(const Transform& transform, unsigned int count, const NiPoint3* positions,
                          NiPoint3* transformedPositions, const NiPoint3* normals, NiPoint3* transformedNormals)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        if (transformedPositions)
        {
            {
                float a = GetTransformEntry(&transform.rotation, 0, 0);
                float b = GetTransformEntry(&transform.rotation, 0, 1);
                float c = GetTransformEntry(&transform.rotation, 0, 2);
                transformedPositions[i].x =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.position.x);
            }
            {
                float a = GetTransformEntry(&transform.rotation, 1, 0);
                float b = GetTransformEntry(&transform.rotation, 1, 1);
                float c = GetTransformEntry(&transform.rotation, 1, 2);
                transformedPositions[i].y =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.position.y);
            }
            {
                float a = GetTransformEntry(&transform.rotation, 2, 0);
                float b = GetTransformEntry(&transform.rotation, 2, 1);
                float c = GetTransformEntry(&transform.rotation, 2, 2);
                transformedPositions[i].z =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.position.z);
            }
        }
        if (transformedNormals)
        {
            {
                float a = GetTransformEntry(&transform.rotation, 0, 0);
                float b = GetTransformEntry(&transform.rotation, 0, 1);
                float c = GetTransformEntry(&transform.rotation, 0, 2);
                transformedNormals[i].x = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
            {
                float a = GetTransformEntry(&transform.rotation, 1, 0);
                float b = GetTransformEntry(&transform.rotation, 1, 1);
                float c = GetTransformEntry(&transform.rotation, 1, 2);
                transformedNormals[i].y = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
            {
                float a = GetTransformEntry(&transform.rotation, 2, 0);
                float b = GetTransformEntry(&transform.rotation, 2, 1);
                float c = GetTransformEntry(&transform.rotation, 2, 2);
                transformedNormals[i].z = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
        }
    }
}

inline bool IsKindOfC4BB(const NiRTTI* pkRTTI, const NiObject* pkObject)
{
    const NiRTTI* pkTmp = pkObject->GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->m_pBaseRTTI;
    }
    return false;
}

extern const NiRTTI g_sourceTextureRTTI;

inline void* GetPlatformPathImpl(const NiSourceTexture* texture)
{
    return texture->m_kPlatformFilename.m_kHandle;
}

inline void* GetPlatformPath(const NiSourceTexture* texture)
{
    return GetPlatformPathImpl(texture);
}

inline NiSourceTexture* DynamicCastC4BB(NiObject* pkObject)
{
    return !pkObject ? 0 : (NiSourceTexture*)(IsKindOfC4BB(&g_sourceTextureRTTI, pkObject) ? pkObject : 0);
}

// @fnv 0x00c4bb40
// src: XBOX_PDB 0x00c4bb40
void* __cdecl BSUtilities_GetTextureName(NiObject* pkObject)
{
    void* pvData = 0;
    NiSourceTexture* pkTarget;
    if (!pkObject)
        pkTarget = 0;
    else
        pkTarget = (NiSourceTexture*)(IsKindOfC4BB(&g_sourceTextureRTTI, pkObject) ? pkObject : 0);
    if (pkTarget)
        pvData = GetPlatformPath(pkTarget);
    return pvData;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern char* DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* s);
int __cdecl FUN_00ec65a6(char* dst, unsigned size, const char* src);
int __cdecl FUN_00ec6bd2(char* dst, unsigned size, const char* src);
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ1()
{
    int dq[1];
}
struct FixStrQ
{
    char* m_kHandle;
    FixStrQ(const char* s)
    {
        if (s == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(s);
    }
    ~FixStrQ()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        long* pRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(pRef);
    }
    FixStrQ& AssignInternedString(const FixStrQ& o);
    const char* CStr()
    {
        const char* p = m_kHandle;
        return p;
    }
};
struct NamedQ
{
    int unk00, unk04;
    FixStrQ m_kName;
    const char* GetName()
    {
        return m_kName.CStr();
    }
    void SetName(const FixStrQ& kName)
    {
        DeadQ3();
        m_kName.AssignInternedString(kName);
    }
};
struct PathQ
{
    char m_szDir[0x203];
    char m_szName[0x100];
    char m_szExt[0x105];
    PathQ(const char* p);
};
// @fnv 0x00c4bbc0
// src: COMMUNITY 0x00c4bbc0
void __cdecl BSUtilities_SetSequenceFileName(NamedQ* pObj, const char* pcPath)
{
    const char* pcOld_ = pObj->GetName();
    PathQ kKPath(pcPath);
    char acBuf[0x100];
    if (pcOld_)
        FUN_00ec65a6(acBuf, 0x100, pcOld_);
    else
        acBuf[0] = 0;
    FUN_00ec6bd2(acBuf, 0x100, "_:");
    FUN_00ec6bd2(acBuf, 0x100, kKPath.m_szName);
    pObj->SetName(FixStrQ(acBuf));
}

class NiPoint3R
{
  public:
    float x, y, z;

    NiPoint3R()
    {}
    NiPoint3R(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    NiPoint3R operator-() const
    {
        return NiPoint3R(-x, -y, -z);
    }
    NiPoint3R operator*(float f) const
    {
        return NiPoint3R(f * x, f * y, f * z);
    }
    NiPoint3R operator+(const NiPoint3R& p) const
    {
        return NiPoint3R(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3R operator-(const NiPoint3R& p) const
    {
        return NiPoint3R(x - p.x, y - p.y, z - p.z);
    }
    float Dot(const NiPoint3R&) const;
    float Length() const;
// src: XBOX_PDB 0x004a0c10
    void Unitize_004a0c10()
    {
        float len = Length();
        if (len > 1e-06)
        {
            float inv = 1.0f / len;
            x *= inv;
            y *= inv;
            z *= inv;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
};
inline NiPoint3R __cdecl operator*(float f, const NiPoint3R& p)
{
    return NiPoint3R(f * p.x, f * p.y, f * p.z);
}
extern "C" NiPoint3R __cdecl FUN_004a3760(float f, const NiPoint3R& p);
class NiMatrix3R
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void NiMatrix3_GetCol(unsigned int, NiPoint3R&) const;
    NiPoint3R Column(unsigned int column) const
    {
        NiPoint3R result;
        NiMatrix3_GetCol(column, result);
        return result;
    }
    void NiMatrix3_NiMatrix3(const NiPoint3R&, const NiPoint3R&, const NiPoint3R&);
};
struct Plane
{
    NiPoint3R normal;
    float distance;
    float Distance(const NiPoint3R& p) const
    {
        return normal.Dot(p) - distance;
    }
};
double __cdecl _fabs(double);
inline double Abs(float value)
{
    return (float)_fabs(value);
}
// @fnv 0x00c4bf40
// src: COMMUNITY 0x00c4bf40
void __cdecl BSUtilities_ReflectCameraAboutArbitraryPlane(NiCamera* source, Plane* plane, NiCamera* dest)
{
    NiPoint3R position = reinterpret_cast<const NiPoint3R&>(source->m_kWorld.m_Translate);
    NiPoint3R first7 = reinterpret_cast<const NiMatrix3R&>(source->m_kWorld.m_Rotate).Column(0);
    NiPoint3R second3 = reinterpret_cast<const NiMatrix3R&>(source->m_kWorld.m_Rotate).Column(2);
    NiPoint3R thirdB = reinterpret_cast<const NiMatrix3R&>(source->m_kWorld.m_Rotate).Column(1);
    NiPoint3R reflected6 = position + (-plane->normal) * (float)(2.0 * plane->Distance(position));
    NiPoint3R direction6 = -first7;
    direction6.Unitize_004a0c10();
    NiPoint3R axisA = (float)(2.0 * plane->normal.Dot(direction6)) * plane->normal - direction6;
    direction6 = -second3;
    direction6.Unitize_004a0c10();
    NiPoint3R axis2 = FUN_004a3760((float)(2.0 * plane->normal.Dot(direction6)), plane->normal) - direction6;
    direction6 = thirdB;
    direction6.Unitize_004a0c10();
    NiPoint3R axis7 = FUN_004a3760((float)(2.0 * plane->normal.Dot(direction6)), plane->normal) - direction6;
    NiMatrix3R matrix;
    matrix.NiMatrix3_NiMatrix3(axisA, axis7, axis2);
    dest->m_kLocal.m_Translate = reinterpret_cast<const NiPoint3&>(reflected6);
    dest->m_kLocal.m_Rotate = reinterpret_cast<const NiMatrix3&>(matrix);
    dest->m_kLocal.m_fScale = Abs(source->m_kWorld.m_fScale);
    dest->UpdateViewFrustum(source->m_kViewFrustum);
    NiUpdateData update2(0.0f, false, false);
    dest->Update(update2);
}
