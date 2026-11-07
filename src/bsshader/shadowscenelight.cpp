// bsshader/shadowscenelight.cpp: ShadowSceneLight and shared rendering helpers (22 functions)

#include <windows.h>
#include <stddef.h>
#define FNV_LAYOUT_SUPPORT_H
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#define FNV_ALIGN(n) __declspec(align(n))
#define FNV_FORCEINLINE __forceinline
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTPointerList.h"
#define FNV64_NIPOINTER_COMPARE_DECLS
#include "../../include/NiPointer.h"
class NiAVObject;
class NiTriBasedGeom;
// These owning list instantiations call the game's out-of-line destructors.
// The approved shared template lacks the lifecycle declarations required here.


#include "../../include/ShadowSceneLight.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiShader.h"
#include "../../include/NiTexture.h"
#define FNV_NIPROPERTY_H
#include "../../include/BSFadeNode.h"
#include "../../include/NiLight.h"
#include "../../include/NiTriBasedGeom.h"
#include "../../include/NiCamera.h"
#include "../../include/NiTriShape.h"
#include "../../include/BSShaderAccumulator.h"
#include "../../include/BSShaderLightingProperty.h"
#include "../../include/BSCullingProcess.h"
#include "../../include/NiRenderer.h"
#include "../../include/NiDX9Renderer.h"
#include "../../include/NiTransform.h"
#include "../../include/NiUpdateData.h"
#include "../../include/NiFrustum.h"
#include "../../include/NiRect.h"
#include "../../include/NiCullingProcess.h"
#include "../../include/NiSphere.h"
#include "../../include/NiMaterialProperty.h"
#include "../../include/BSRenderedTexture.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiRenderedCubeMap.h"
#include "../../include/NiColorA.h"
#include "../../include/NiColor.h"
#include "../../include/NiNode.h"
#include "../../include/NiBound.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiPlane.h"
#include "../../include/NiFrustumPlanes.h"
#include "../../include/NiTPointerListBase.h"
#include "../../include/NiTPointerAllocator.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/NiExtraData.h"
#include "../../include/BSBound.h"
#include "../../include/BSTextureManager.h"
#include "../../include/ImageSpaceTexture.h"
#include "../../include/ImageSpaceManager.h"

// The shared manager has no declaration for its shadow texture pool getter.
struct ShadowTextureManager : BSTextureManager
{
    BSRenderedTexture* ActivatePending();
};

extern volatile long DAT_011f4400;
inline NiRefObject::NiRefObject() : m_uiRefCount(0)
{
    InterlockedIncrement(&DAT_011f4400);
}
__forceinline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject)
        reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::DecRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(T* object) : m_pObject(object)
{
    if (m_pObject)
        reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& other) : m_pObject(other.m_pObject)
{
    if (m_pObject)
        reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::IncRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::DecRefCount();
        m_pObject = object;
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::IncRefCount();
    }
    return *this;
}
// This unit calls the game's out-of-line type-erased reference assignment helper.
template <> __declspec(noinline) inline NiPointer<NiRefObject>& NiPointer<NiRefObject>::operator=(NiRefObject* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->NiRefObject::DecRefCount();
        m_pObject = object;
        if (m_pObject)
            m_pObject->NiRefObject::IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::DecRefCount();
        m_pObject = other.m_pObject;
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::IncRefCount();
    }
    return *this;
}
template <class T> inline bool NiPointer<T>::operator==(T* object) const { return m_pObject == object; }
template <class T> inline bool NiPointer<T>::operator==(const NiPointer<T>& other) const { return m_pObject == other.m_pObject; }
template <class T> inline bool NiPointer<T>::operator!=(const NiPointer<T>& other) const { return m_pObject != other.m_pObject; }

template <class T, unsigned int Growth> inline BSSimpleArray<T, Growth>::BSSimpleArray()
    : pBuffer(0), iSize(0), SimpleArrayStorage(0) {}

extern NiBound DAT_011f4288;

inline unsigned char BSShaderLightingProperty::IsLightingProperty()
{
    return static_cast<unsigned int>(iShaderPropertyType) - 1 <= 11;
}

// If object has a node with a world bound and radius, dispatches it to one of two handlers; otherwise forwards tri-based geometry to AddGeometry.
// @fnv 0x00ba0110
void ShadowSceneLight::AddObject(NiAVObject* object)
{
    if (object)
    {
        NiNode* node = object->IsSceneNode();
        if (node && !(*reinterpret_cast<unsigned char*>(&object->m_uFlags) & 1) &&
            reinterpret_cast<NiAVObject*>(node)->m_kWorldBound &&
            reinterpret_cast<NiBound*>(reinterpret_cast<NiAVObject*>(node)->m_kWorldBound)
                ->m_fBoundRadius)
        {
            if (bCastShadow && object == spShadowScene.m_pObject &&
                ((unsigned char)~(object->m_uFlags >> 23) & 1))
                goto AddDisplayGeometry;
            if (bCastShadow)
            {
                ProcessShadowObject(reinterpret_cast<NiAVObject*>(node));
                return;
            }
            else
            {
                AddShadowObject(reinterpret_cast<NiAVObject*>(node));
                return;
            }
        }
    AddDisplayGeometry:
        if (object->IsTriBasedGeometry())
            AddGeometry(reinterpret_cast<NiTriBasedGeom*>(object));
    }
}

// @fnv 0x00b9f6a0
void ShadowSceneLight::AddShadowObject(NiAVObject* object)
{
    unsigned int active = kShadowCameraPlanes.m_uiActivePlaneMask;
    if (!((unsigned char)(object->m_uFlags >> 11) & 1))
    {
        NiPoint3* bound = reinterpret_cast<NiPoint3*>(object->m_kWorldBound);
        NiLight* light = spLight.m_pObject;
        if (!bound)
            bound = reinterpret_cast<NiPoint3*>(&DAT_011f4288);
        if (!BoundWithinLightRadius(bound, light, 1.0f))
            goto done;
    }
    {
        NiNode* node = object->IsSceneNode();
        if (node)
        {
            NiNode* children = node;
            for (unsigned int i = 0; i < children->m_kChildren.m_usSize; ++i)
            {
                NiAVObject* child = children->m_kChildren.m_pBase[i].m_pObject;
                unsigned int flags;
                if (child &&
                    (((unsigned char)((flags = child->m_uFlags) >> 11) & 1) ||
                     (child->m_kWorldBound &&
                      reinterpret_cast<NiBound*>(child->m_kWorldBound)->m_fBoundRadius)) &&
                    !((unsigned char)flags & 1))
                    AddShadowObject(child);
            }
        }
        else if (object->IsTriBasedGeometry())
            AddGeometry(object->IsTriBasedGeometry());
    }
done:
    kShadowCameraPlanes.m_uiActivePlaneMask = active;
}
// @fnv 0x00b9f5b0
void ShadowSceneLight::ProcessShadowObject(NiAVObject* object)
{
    unsigned int active = kShadowCameraPlanes.m_uiActivePlaneMask;
    if (object == spShadowScene.m_pObject || !((unsigned char)~(object->m_uFlags >> 23) & 1))
        goto done;
    if (active && !((unsigned char)(object->m_uFlags >> 11) & 1))
    {
        NiPoint3* bound = reinterpret_cast<NiPoint3*>(object->m_kWorldBound);
        if (!bound)
            bound = reinterpret_cast<NiPoint3*>(&DAT_011f4288);
        if (!TestSphereFrustum(bound))
            goto done;
    }
    {
        NiNode* node = object->IsSceneNode();
        if (node)
        {
            NiNode* children = node;
            for (unsigned int i = 0; i < children->m_kChildren.m_usSize; ++i)
            {
                NiAVObject* child = children->m_kChildren.m_pBase[i].m_pObject;
                unsigned int flags;
                if (child &&
                    (((unsigned char)((flags = child->m_uFlags) >> 11) & 1) ||
                     (child->m_kWorldBound &&
                      reinterpret_cast<NiBound*>(child->m_kWorldBound)->m_fBoundRadius)) &&
                    !((unsigned char)flags & 1))
                    ProcessShadowObject(child);
            }
        }
        else if (object->IsTriBasedGeometry())
            AddGeometry(reinterpret_cast<NiTriBasedGeom*>(object));
    }
done:
    kShadowCameraPlanes.m_uiActivePlaneMask = active;
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" const NiPoint3 NiPoint3_ZERO;
extern const float runtimeFloatSettingDefault100;
__forceinline void ShadowMatrixIdentity(D3DXMATRIX& m)
{
    m._12 = m._13 = m._14 = m._21 = m._23 = m._24 = m._31 = m._32 = m._34 = m._41 = m._42 = m._43 = 0.0f;
    m._11 = m._22 = m._33 = m._44 = 1.0f;
}
// @fnv 0x00b9fda0
ShadowSceneLight::ShadowSceneLight()
{
    fLuminance = 0.0f;
    fLODDimmer = 0.0f;
    bCubeShadowMap = true;
    fShadowLODDimmer = 0.0f;
    bCastShadow = false;
    bPointLight = false;
    bAmbientLight = false;
    bDynamicLight = false;
    bPointPosition = NiPoint3_ZERO;
    usFrustumCull = 0;
    spSpecularAttenuationTexture = (NiTexture*)0;
    spLight = (NiLight*)0;
    spFrustumVis = (NiAVObject*)0;
    spDynamicShadowMap = (BSRenderedTexture*)0;
    ShadowMatrixIdentity(kViewProjection);
    double spotlightDefault = runtimeFloatSettingDefault100;
    *reinterpret_cast<volatile bool*>(&bCubeShadowMap) = false;
    *reinterpret_cast<volatile float*>(&fSpotlightFOV) = spotlightDefault;
    bShadowSpotlight = false;
    bShowDebugTexture = false;
    fSpotlightFalloff = 1.0f;
    spShadowScene = (NiAVObject*)0;
    kGeomListFence = 0;
    kGeomListFenceObject = (NiTriBasedGeom*)0;
    spShadowCamera = (NiCamera*)0;
    fShadowLODDimmerElapsed = 0.0f;
    fShadowLODDimmerTarget = 1.0f;
    bClipSpacePlanesReady = false;
    fnv_zlib_memset(pfClipSpacePlanes, 0, sizeof(pfClipSpacePlanes));
}

static __forceinline int IsShaderProp_00b9e770(char* prop)
{
    unsigned int t = *(unsigned int*)(prop + 0x1c);
    return t >= 1 && t <= 12;
}

// Walks the list at self+0x138, clears field +0x38 of each item's shader property, then nulls the list head.
// @fnv 0x00b9e770
void __fastcall ClearShaderPropRefs(ShadowSceneLight* self)
{
    NiTListItem<NiTriBasedGeom*>* pNode = static_cast<NiTListItem<NiTriBasedGeom*>*>(self->kGeomListFence);
    while (pNode)
    {
        NiTriBasedGeom** ppData = &pNode->m_element;
        pNode = pNode->m_pkNext;
        NiTriBasedGeom* item = *ppData;
        if (item)
        {
            char* prop = reinterpret_cast<char*>(item->m_PropertyState.m_aspProps[3]);
            if (prop)
            {
                char* pShaderProp = IsShaderProp_00b9e770(prop) ? prop : 0;
                if (pShaderProp)
                    *(void**)(pShaderProp + 0x38) = 0;
            }
        }
    }
    self->kGeomListFence = 0;
}

extern "C" __declspec(dllimport) void __stdcall FreeBlockImp(void*);
extern MemoryManager g_memoryManager;
template <> inline BSSimpleArray<void*>::~BSSimpleArray()
{
    if (pBuffer)
    {
        FreeBlockImp(pBuffer);
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
// @fnv 0x00b9e920
BSSimpleArray<void*>* __fastcall DestroyShadowArray(BSSimpleArray<void*>* p, int, unsigned int flags)
{
    p->BSSimpleArray<void*>::~BSSimpleArray();
    if (flags & 1)
        g_memoryManager.Deallocate(p);
    return p;
}

extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x00ba00e0
ShadowSceneLight* __fastcall FUN_00ba00e0(ShadowSceneLight* this_ptr, int /*edx*/, int param2)
{
    this_ptr->~ShadowSceneLight();
    if (param2 & 1)
        __Dummy_00b6fef0(this_ptr, 0x250);
    return this_ptr;
}

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<BSRenderedTexture> > ShadowRefList;
typedef NiTListItem<NiPointer<BSRenderedTexture> > ShadowRefListItem;

template <> __declspec(noinline) NiPointer<BSRenderedTexture> ShadowRefList::RemoveHead()
{
    ShadowRefListItem* pkNode = m_pkHead;
    m_pkHead = m_pkHead->m_pkNext;
    if (m_pkHead)
        m_pkHead->m_pkPrev = 0;
    else
        m_pkTail = 0;
    NiPointer<BSRenderedTexture> element = pkNode->m_element;
    DeleteItem(pkNode);
    m_kItemCount.m_uiCount--;
    return element;
}

template <> __declspec(noinline) NiPointer<BSRenderedTexture> ShadowRefList::RemoveTail()
{
    ShadowRefListItem* pkNode = m_pkTail;
    m_pkTail = m_pkTail->m_pkPrev;
    if (m_pkTail)
        m_pkTail->m_pkNext = 0;
    else
        m_pkHead = 0;
    NiPointer<BSRenderedTexture> element = pkNode->m_element;
    DeleteItem(pkNode);
    m_kItemCount.m_uiCount--;
    return element;
}

template <> inline void* ShadowRefList::FindPos(const NiPointer<BSRenderedTexture>& element, void* start) const
{
    if (!start)
        start = m_pkHead;
    while (start)
    {
        void* pos = start;
        const NiPointer<BSRenderedTexture>& next = static_cast<ShadowRefListItem*>(start)->m_element;
        start = static_cast<ShadowRefListItem*>(start)->m_pkNext;
        if (element == next)
            return pos;
    }
    return 0;
}

template <> NiPointer<BSRenderedTexture> ShadowRefList::Remove(const NiPointer<BSRenderedTexture>& element)
{
    void* pos = FindPos(element);
    return pos ? RemovePos(pos) : element;
}

extern char* _EmptyFS;

struct ShadowSceneFence : ShadowSceneLight
{
    void InitializeFence();
};
// @fnv 0x00b9fba0
void ShadowSceneFence::InitializeFence()
{
    NiPointer<NiTriBasedGeom>& fence = kGeomListFenceObject;
    if (fence.m_pObject == 0)
    {
        fence = static_cast<NiTriBasedGeom*>(new NiTriShape(0));
        fence->SetName("fence");
    }
    lGeomList.AddHead(fence);
    kGeomListFence = lGeomList.m_pkHead;
}

extern "C" double __cdecl sqrt(double);
inline float __cdecl sqrt(float _X)
{
    return (float)sqrt((double)_X);
}

inline NiColorA::NiColorA(float R, float G, float B, float A) : r(R), g(G), b(B), a(A) {}
inline NiColor& NiColor::operator*=(float value)
{
    r *= value;
    g *= value;
    b *= value;
    return *this;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    NiPoint3 result;
    result.x = x - other.x;
    result.y = y - other.y;
    result.z = z - other.z;
    return result;
}
inline float NiPoint3::Length()
{
    return sqrt(x * x + y * y + z * z);
}
inline float NiPoint3::Length() const
{
    return sqrt(x * x + y * y + z * z);
}
inline float MinF(float a, float b)
{
    return a < b ? a : b;
}
inline float Sqr(float a)
{
    return a * a;
}
inline float MaxF(float a, float b)
{
    return a > b ? a : b;
}
extern double _gModifierZero;

// Computes a light's attenuation at apPoint from its dimmed color and distance/radius falloff, storing and returning the result at this+0xc.
// @fnv 0x00b9bc50
float ShadowSceneLight::ComputeLightAttenuation(NiPoint3 apPoint, NiLight* apIgnore)
{
    NiLight* pkLight = spLight.m_pObject;
    if (pkLight == apIgnore || bCastShadow == 1)
        return 0.0f;
    NiPoint3 lightPos = pkLight->m_kWorld.m_Translate;
    NiColor lightColor = pkLight->m_kDiff;
    lightColor *= pkLight->m_fDimmer;
    float plightRadius = pkLight->m_kSpec.r;
    fLuminance = 1.0f;
    if (bPointLight)
    {
        float fdistance = (reinterpret_cast<const NiPoint3&>(apPoint) - lightPos).Length() / plightRadius;
        fdistance = MinF(1.0f, fdistance < _gModifierZero ? 0.0f : fdistance);
        fLuminance = 1.0f - fdistance * fdistance;
    }
    fLuminance = MaxF(lightColor.r, MaxF(lightColor.g, lightColor.b)) * fLuminance;
    return fLuminance;
}

extern BSTextureManager* DAT_011f91a8;

template <> inline BSSimpleArray<BSMultiBoundNode*>::~BSSimpleArray()
{
    if (pBuffer)
    {
        reinterpret_cast<BSSimpleArray<void*>*>(this)->_Deallocate(reinterpret_cast<void**>(pBuffer));
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
template <> inline BSSimpleArray<BSPortal*>::~BSSimpleArray()
{
    if (pBuffer)
    {
        reinterpret_cast<BSSimpleArray<void*>*>(this)->_Deallocate(reinterpret_cast<void**>(pBuffer));
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}
template <> inline BSSimpleArray<NiNode*>::~BSSimpleArray()
{
    if (pBuffer)
    {
        reinterpret_cast<BSSimpleArray<void*>*>(this)->_Deallocate(reinterpret_cast<void**>(pBuffer));
        pBuffer = 0;
        SimpleArrayStorage = 0;
        iSize = 0;
    }
}

NiRefObject::~NiRefObject()
{
    InterlockedDecrement(&DAT_011f4400);
}

// @fnv 0x00b9f0c0
ShadowSceneLight::~ShadowSceneLight()
{
    ClearShadowObjects();
    spSpecularAttenuationTexture = 0;
    spLight = 0;
    if (spDynamicShadowMap.m_pObject)
    {
        DAT_011f91a8->RemoveRenderedTexture(spDynamicShadowMap.m_pObject);
    }
    spDynamicShadowMap = 0;
    usFrustumCull = 0;
    spFrustumVis = 0;
    spShadowCamera = 0;
    spShadowScene = 0;
    spShadowAccumulator = 0;
    kGeomListFence = 0;
    kGeomListFenceObject = 0;
    {
        BSSimpleArray<BSMultiBoundNode*>& a = kMultiboundRooms;
        if (a.pBuffer)
        {
            reinterpret_cast<BSSimpleArray<void*>*>(&a)->_Deallocate(reinterpret_cast<void**>(a.pBuffer));
            a.pBuffer = 0;
            a.SimpleArrayStorage = 0;
            a.iSize = 0;
        }
    }
    {
        BSSimpleArray<BSPortal*>& a = kPortals;
        if (a.pBuffer)
        {
            reinterpret_cast<BSSimpleArray<void*>*>(&a)->_Deallocate(reinterpret_cast<void**>(a.pBuffer));
            a.pBuffer = 0;
            a.SimpleArrayStorage = 0;
            a.iSize = 0;
        }
    }
    {
        BSSimpleArray<NiNode*>& a = kProcessedNodes;
        if (a.pBuffer)
        {
            reinterpret_cast<BSSimpleArray<void*>*>(&a)->_Deallocate(reinterpret_cast<void**>(a.pBuffer));
            a.pBuffer = 0;
            a.SimpleArrayStorage = 0;
            a.iSize = 0;
        }
    }
}

extern NiColorA DAT_011a9bd0;
extern unsigned int DAT_011f91b8;
extern const float runtimeFloatSettingDefault408;
extern NiRenderer* DAT_011f9508;

template <class T> inline NiPtr<T>::NiPtr(T* object) : m_pObject(object)
{
}
inline NiUpdateData::NiUpdateData() : fTime(0), pad1(false), pad2(false), pad3(false), pad4(false), pad5(false) {}
template <class T> inline NiPtr<T>& NiPtr<T>::operator=(T* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::DecRefCount();
        m_pObject = object;
        if (m_pObject)
            reinterpret_cast<NiRefObject*>(m_pObject)->NiRefObject::IncRefCount();
    }
    return *this;
}

// BSCullingProcess's visible-set constructor, inline in LightView::RenderFaces (0x00BD77C0).
__forceinline BSCullingProcess::BSCullingProcess(void* visibleSet) : NiCullingProcess(static_cast<NiVisibleArray*>(visibleSet))
{
    unk90 = 0;
    unkBc = 0;
    unkC0 = 0;
    m_acRendererDataA.m_pObject = 0;
}

// The cube-map camera adds state beyond the shared NiCamera base.
struct LightView : NiCamera
{
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    NiPointer<BSRenderedTexture> unk130;
    ShadowSceneLight* unk134;
    void* unk138;
    BSShaderAccumulator* unk13C;
    void RenderFaces();
    void BSCubeMapCamera_SetupTransformation(int);
    void CullScene(ShadowSceneLight*);
};
void BSRenderedTexture_StartOffscreen(unsigned int, void*);
void BSShaderUtil_AccumulateScene(LightView*, void*, BSCullingProcess*);
void FUN_00b6c0d0(LightView*, BSShaderAccumulator*, int);
void BSShaderLightingProperty_SetLight(unsigned int, ShadowSceneLight*, float);
void FUN_00b6b790();
// @fnv 0x00bd77c0
void LightView::RenderFaces()
{
    NiColorA old = DAT_011a9bd0;
    unsigned short uiFaceMask = 0;
    DAT_011f9508->GetBackgroundColor(reinterpret_cast<NiVector4*>(&old));
    if (DAT_011f91b8 == 7)
    {
        uiFaceMask = unk134->usFrustumCull;
        NiColorA clear(runtimeFloatSettingDefault408, runtimeFloatSettingDefault408, runtimeFloatSettingDefault408, 1.0f);
        DAT_011f9508->SetBackgroundColor(reinterpret_cast<NiVector4*>(&clear));
    }
    for (int face = 0; face < 6; ++face)
    {
        BSCubeMapCamera_SetupTransformation(face);
        NiRenderedTexture* texture = (unk130 ? reinterpret_cast<NiPointer<NiRenderedTexture>&>(unk130->spTexture[0])
                                      : NiPointer<NiRenderedTexture>());
        NiRenderedCubeMap* pTextureView = static_cast<NiRenderedCubeMap*>(texture);
        pTextureView->unk48 = face;
        pTextureView->m_spRenderTargetBuffer = reinterpret_cast<NiPointer<Ni2DBuffer>&>(pTextureView->m_ppCubeMapFaces[face]);
        BSRenderedTexture_StartOffscreen(7, unk130->GetGroup());
        int uiFaceBit = 0;
        switch (face)
        {
        case 1:
            uiFaceBit = 2;
            break;
        case 0:
            uiFaceBit = 1;
            break;
        case 3:
            uiFaceBit = 8;
            break;
        case 2:
            uiFaceBit = 4;
            break;
        case 5:
            uiFaceBit = 32;
            break;
        case 4:
            uiFaceBit = 16;
            break;
        }
        if (!(unsigned short)(uiFaceBit & uiFaceMask))
        {
            NiUpdateData updateView;
            NiAVObject_Update(updateView);
            if (DAT_011f91b8 != 7)
            {
                if (unk138)
                {
                    if (unk13C->m_uiRefCount == 1)
                        unk13C->NiRefObject::IncRefCount();
                    unk13C->StartAccumulating(reinterpret_cast<const NiCamera*>(this));
                    unk13C->bAccumulate = true;
                    BSCullingProcess cullingProcess(static_cast<void*>(0));
                    cullingProcess.m_pkCamera = reinterpret_cast<const NiCamera*>(this);
                    void* list = &m_kViewFrustum;
                    cullingProcess.NiCullingProcess_SetFrustum(list);
                    BSShaderAccumulator* pAccumulator = unk13C;
                    if (cullingProcess.m_acRendererDataA.m_pObject != pAccumulator)
                    {
                        if (cullingProcess.m_acRendererDataA.m_pObject)
                            cullingProcess.m_acRendererDataA.m_pObject->NiRefObject::DecRefCount();
                        cullingProcess.m_acRendererDataA.m_pObject = pAccumulator;
                        if (pAccumulator)
                            pAccumulator->NiRefObject::IncRefCount();
                    }
                    void* scene = unk138;
                    BSShaderUtil_AccumulateScene(this, scene, &cullingProcess);
                    BSShaderAccumulator* pCurrentAccumulator = unk13C;
                    FUN_00b6c0d0(this, pCurrentAccumulator, 0);
                    if (cullingProcess.m_acRendererDataA.m_pObject)
                    {
                        cullingProcess.m_acRendererDataA.m_pObject->NiRefObject::DecRefCount();
                        cullingProcess.m_acRendererDataA.m_pObject = 0;
                    }
                }
            }
            else if (unk134)
            {
                BSShaderLightingProperty_SetLight(0, unk134, 1.0f);
                unk130 = (BSRenderedTexture*)unk134->spDynamicShadowMap;
                CullScene(unk134);
            }
        }
        FUN_00b6b790();
    }
    DAT_011f9508->SetBackgroundColor(reinterpret_cast<NiVector4*>(&old));
}

template <> __declspec(noinline) void ShadowRefList::AddTail(const NiPointer<BSRenderedTexture>& item)
{
    ShadowRefListItem* entry = static_cast<ShadowRefListItem*>(m_kItemCount.Allocate());
    entry->m_element = item;
    entry->m_pkNext = 0;
    entry->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = entry;
    else
        m_pkHead = entry;
    ++m_kItemCount.m_uiCount;
    m_pkTail = entry;
}
class MultiBoundLists
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    ShadowRefList pending;
    ShadowRefList active;
    BSRenderedTexture* ActivatePending();
};
// If pending is nonempty, pops its last item, appends it to active, and returns the popped value.
// @fnv 0x00b6d3f0
BSRenderedTexture* MultiBoundLists::ActivatePending()
{
    NiPointer<BSRenderedTexture> result;
    if (pending.m_kItemCount.m_uiCount > 0)
    {
        result = pending.RemoveTail();
        active.AddTail(result);
    }
    return result;
}

template <class TAlloc, class T> inline void* NiTListBase<TAlloc, T>::GetHeadPos() const
{
    return m_pkHead;
}
template <class TAlloc, class T> inline T& NiTPointerListBase<TAlloc, T>::GetNext(void*& pos)
{
    T& item = static_cast<NiTListItem<T>*>(pos)->m_element;
    pos = static_cast<NiTListItem<T>*>(pos)->m_pkNext;
    return item;
}

// Detaches lighting properties, then clears the geometry and root lists.
// @fnv 0x00b9ef30
void ShadowSceneLight::ClearShadowObjects()
{
    void* pkPos = lGeomList.GetHeadPos();
    while (pkPos)
    {
        NiTriBasedGeom* pkObj = lGeomList.GetNext(pkPos);
        if (pkObj)
        {
            BSShaderLightingProperty* pkProp = reinterpret_cast<BSShaderLightingProperty*>(pkObj->m_PropertyState.m_aspProps[3]);
            if (pkProp)
            {
                int b = static_cast<unsigned int>(pkProp->iShaderPropertyType) - 1 <= 11;
                int* pbIsLighting = &b;
                BSShaderLightingProperty* pkMatch = (*pbIsLighting) ? pkProp : 0;
                if (pkMatch)
                    pkMatch->GetNextAttachedLight(static_cast<void*>(this));
            }
        }
    }
    lGeomList.RemoveAll();
    lRootList.RemoveAll();
}

template <> NiPointer<BSRenderedTexture> ShadowRefList::RemovePos(void*& position)
{
    ShadowRefListItem* item = static_cast<ShadowRefListItem*>(position);
    if (item == m_pkHead)
    {
        position = item->m_pkNext;
        return RemoveHead();
    }
    if (item == m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    ShadowRefListItem* previous = item->m_pkPrev;
    ShadowRefListItem* next = item->m_pkNext;
    position = next;
    if (previous)
        previous->m_pkNext = next;
    if (next)
        next->m_pkPrev = previous;
    NiPointer<BSRenderedTexture> element = item->m_element;
    DeleteItem(item);
    --m_kItemCount.m_uiCount;
    return element;
}

extern "C" void _ReadWriteBarrier(void);
#include <string.h>
// Explicit result pointers express the VC9 return-buffer ABI of these shared vector methods.
__forceinline NiPoint3* ShadowCross(const NiPoint3& vector, NiPoint3* result, const NiPoint3& other)
{
    typedef NiPoint3 (NiPoint3::*SharedCross)(const NiPoint3&) const;
    typedef NiPoint3* (NiPoint3::*BufferedCross)(NiPoint3*, const NiPoint3&) const;
    return (vector.*reinterpret_cast<BufferedCross>(static_cast<SharedCross>(&NiPoint3::FUN_0053d1a0)))(result, other);
}
__forceinline NiPoint3* ShadowScale(const NiPoint3& vector, NiPoint3* result, float scale)
{
    typedef NiPoint3 (NiPoint3::*SharedScale)(float) const;
    typedef NiPoint3* (NiPoint3::*BufferedScale)(NiPoint3*, float) const;
    return (vector.*reinterpret_cast<BufferedScale>(static_cast<SharedScale>(&NiPoint3::ApplyScaled)))(result, scale);
}
inline void ShadowSet(NiPoint3& vector, float x, float y, float z)
{
    vector.x = x;
    vector.y = y;
    vector.z = z;
}
inline float ShadowOrderedScale(const NiAVObject* object)
{
    _ReadWriteBarrier();
    return object->m_kWorld.m_fScale;
}

namespace fnv_00b9dfc0 {
// BSBound has no shared center/extent members yet; retain only that extension locally.

struct ShadowExtraData : BSBound
{
    NiPoint3 offset;
    NiPoint3 extent;
};

// The shared layout has no declaration for the shadow-light setter yet.
// These method adapters use the shared members without repeating any layout.
struct ShadowAccumulator : BSShaderAccumulator
{
    void SetPass(unsigned int pass)
    {
        eRenderMode = pass;
    }
    void AssignRefCounted(ShadowSceneLight*);
};
struct ShadowEvents
{
    void MTRenderingSystem_SetThreadStage(int, unsigned char*);
    void MTRenderingSystem_AddAccumTask(NiCamera*, int, NiAVObject*, int, int, BSShaderAccumulator*, int, unsigned char*, int);
};
extern ShadowTextureManager* DAT_011f91a8;
extern int DAT_011f91c0, DAT_011f91b0;
extern int DAT_011f91d8;
extern double DAT_01082cb0, DAT_01031148, DAT_010b7ea0;
extern double DAT_01016ff0, DAT_0106c948, DAT_01020758;
extern double DAT_0106b178, DAT_01018a90;
extern float DAT_01032adc;
extern NiPoint3 DAT_011a9484, DAT_011a946c, DAT_011f426c;
extern const void* DAT_012031e4;
extern ShadowEvents DAT_01200088;
inline float ShadowNegate(float f)
{
    return -f;
}
inline float ShadowRadius(const NiBound& b)
{
    return b.radius;
}
extern float __cdecl BSMAX_00404010(float, float);
extern float __cdecl BSMIN(float, float);
extern bool __cdecl BSShaderManager_GetShadows();
extern BSShaderAccumulator* __cdecl PopNextInt();
inline void ShadowEnabled(int& result)
{
    result = (DAT_011f91d8 & 0x10) > 0;
}
inline int ShadowEnabledValue()
{
    int result;
    ShadowEnabled(result);
    return result;
}
class ShadowSceneCameraUpdate : public ShadowSceneLight
{
  public:
    NiLight* GetLight() const
    {
        return spLight.m_pObject;
    }
    bool CastsShadow() const
    {
        return bCastShadow;
    }
    NiCamera* GetShadowCamera()
    {
        return spShadowCamera.m_pObject;
    }
    void AssignRefObject(BSRenderedTexture*);
    void UpdateShadow(void*, unsigned char*);
};

// Updates the shadow camera frustum and viewport when conditions hold; otherwise releases an existing shadow texture.
// @fnv 0x00b9dfc0
void ShadowSceneCameraUpdate::UpdateShadow(void* unused, unsigned char* renderFlags)
{
    bool updateShadow = true;
    if (!(CastsShadow() && DAT_011f91c0 >= 3 && (unsigned char)ShadowEnabledValue()) && !bShadowSpotlight)
        updateShadow = false;

    if (!spDynamicShadowMap.m_pObject)
    {
        BSRenderedTexture* texture = DAT_011f91a8->ActivatePending();
        if (!texture)
            reinterpret_cast<NiAVObject*>(spLight.m_pObject)->m_uFlags |= 1;
        AssignRefObject(texture);
    }

    if (updateShadow && usFrustumCull != 255 && fShadowLODDimmer > DAT_01082cb0 &&
        spDynamicShadowMap.m_pObject)
    {
        NiTransform lightTransform = GetLight()->m_kWorld;
        NiPoint3 a;
        NiPoint3 b;
        NiPoint3 c;
        NiPoint3 d;
        NiPoint3 e;
        ShadowSet(
            a,
            spShadowScene.m_pObject->m_kWorld.m_Translate.x - lightTransform.m_Translate.x,
            spShadowScene.m_pObject->m_kWorld.m_Translate.y - lightTransform.m_Translate.y,
            spShadowScene.m_pObject->m_kWorld.m_Translate.z -
                lightTransform.m_Translate.z);
        a.Unitize_004a0c10();
        ShadowSet(e, -DAT_011a9484.x, -DAT_011a9484.y, -DAT_011a9484.z);
        ShadowCross(a, &b, e);
        if (b.x < DAT_01031148 && b.x > DAT_010b7ea0 && b.y < DAT_01031148 && b.y > DAT_010b7ea0 &&
            b.z < DAT_01031148 && b.z > DAT_010b7ea0)
        {
            e = DAT_011a946c;
            const NiPoint3* __restrict cross = ShadowCross(a, &c, e);
            b = *cross;
        }
        memcpy(&e, ShadowCross(a, &c, b), sizeof(e));
        NiFrustum frustum;
        frustum.Init(false);
        frustum.m_bOrthographic = true;
        ShadowExtraData* pExtraData =
            reinterpret_cast<ShadowExtraData*>(spShadowScene.m_pObject->FUN_00a5bdd0(*reinterpret_cast<const NiFixedString*>(DAT_012031e4)));
        float radius;
        {
            NiAVObject* __restrict scene = spShadowScene.m_pObject;
            {
                const NiPoint3* __restrict origin = &scene->m_kWorld.m_Translate;
                a = *origin;
            }
            {
                const NiPoint3* __restrict extent =
                    pExtraData ? ShadowScale(pExtraData->extent, &c, scene->m_kWorld.m_fScale) : &DAT_011f426c;
                d = *extent;
            }
            const NiBound* bound = reinterpret_cast<NiBound*>(scene->m_kWorldBound);
            if (!bound)
                bound = &DAT_011f4288;
            radius = BSMIN(DAT_01032adc, BSMAX_00404010(float(d.x * DAT_01016ff0),
                                                             BSMAX_00404010(float(d.y * DAT_01016ff0),
                                                                          BSMAX_00404010(float(d.z * DAT_01016ff0),
                                                                                       ShadowRadius(*bound)))));
        }
        NiAVObject* light = static_cast<NiAVObject*>(spLight.m_pObject);
        float distance;
        ShadowSet(c, light->m_kWorld.m_Translate.x - a.x,
                          light->m_kWorld.m_Translate.y - a.y, light->m_kWorld.m_Translate.z - a.z);
        distance = static_cast<const NiPoint3&>(c).FUN_00457990();
        fSpotlightFOV = float((radius / distance) * DAT_0106c948);
        frustum.m_fLeftBound = -radius;
        frustum.m_fBottomBound = -radius;
        frustum.m_fRightBound = radius;
        frustum.m_fTopBound = radius;
        frustum.m_fNearPlane = 1.0f;
        frustum.m_fFarPlane = static_cast<NiLight*>(light)->m_kSpec.r;
        __declspec(align(16)) NiRect<float> viewport;
        viewport.m_fMaximumV = viewport.m_fMinimumU = 0.0f;
        viewport.m_fMinimumV = viewport.m_fMaximumU = 1.0f;

        if (bCastShadow && BSShaderManager_GetShadows())
        {
            reinterpret_cast<NiPointer<NiRefObject>&>(spShadowAccumulator) = static_cast<NiRefObject*>(PopNextInt());
            reinterpret_cast<ShadowAccumulator*>(spShadowAccumulator.m_pObject)->SetPass(7);
            if (!GetShadowCamera())
            {
                NiCamera* camera = new NiCamera;
                reinterpret_cast<NiPointer<NiRefObject>&>(spShadowCamera) = static_cast<NiRefObject*>(camera);
            }
            memcpy(&GetShadowCamera()->m_kLocal.m_Translate, &lightTransform.m_Translate,
                   sizeof(lightTransform.m_Translate));
            reinterpret_cast<NiUpdateData&>(a).fTime = 0.0f;
            reinterpret_cast<NiUpdateData&>(a).pad1 = false;
            reinterpret_cast<NiUpdateData&>(a).pad2 = false;
            reinterpret_cast<NiUpdateData&>(a).pad3 = false;
            reinterpret_cast<NiUpdateData&>(a).pad4 = false;
            reinterpret_cast<NiUpdateData&>(a).pad5 = false;
            GetShadowCamera()->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(a));
            memcpy(&b, &spShadowScene.m_pObject->m_kWorld.m_Translate,
                   sizeof(b));
            pExtraData = reinterpret_cast<ShadowExtraData*>(spShadowScene.m_pObject->FUN_00a5bdd0(*reinterpret_cast<const NiFixedString*>(DAT_012031e4)));
            NiPoint3 tempOffset;
            NiAVObject* __restrict scaleSource = spShadowScene.m_pObject;
            float scale = static_cast<const volatile float&>(scaleSource->m_kWorld.m_fScale);
            NiPoint3* __restrict output = &tempOffset;
            const NiPoint3* input = &pExtraData->offset;
            b.ComputeValue_0063c8a0(*ShadowScale(*input, output, scale));
            ShadowScale(pExtraData->extent, &c, ShadowOrderedScale(spShadowScene.m_pObject));
            if (c.z > c.x + c.y)
            {
                c.x = float(DAT_011a9484.x * DAT_01020758);
                c.y = float(DAT_011a9484.y * DAT_01020758);
                c.z = float(DAT_011a9484.z * DAT_01020758);
                b.x = c.x + b.x;
                b.y = c.y + (*static_cast<const volatile float*>(&b.y));
                b.z = c.z + (*static_cast<const volatile float*>(&b.z));
            }
            GetShadowCamera()->SetLookAt(b, e);
            GetShadowCamera()->FUN_00a6faf0(frustum);
            GetShadowCamera()->FUN_00712e60(viewport);
            reinterpret_cast<NiUpdateData&>(d).fTime = 0.0f;
            reinterpret_cast<NiUpdateData&>(d).pad1 = false;
            reinterpret_cast<NiUpdateData&>(d).pad2 = false;
            reinterpret_cast<NiUpdateData&>(d).pad3 = false;
            reinterpret_cast<NiUpdateData&>(d).pad4 = false;
            reinterpret_cast<NiUpdateData&>(d).pad5 = false;
            GetShadowCamera()->NiAVObject_Update(reinterpret_cast<NiUpdateData&>(d));
            float nearPlane = frustum.m_fNearPlane;
            float farPlane = frustum.m_fFarPlane;
            NiAVObject* __restrict boundSource = spShadowScene.m_pObject;
            const NiBound* bound = reinterpret_cast<NiBound*>(boundSource->m_kWorldBound);
            if (!bound)
                bound = &DAT_011f4288;
            GetShadowCamera()->FitNearAndFarToBound(*bound);
            static_cast<NiFrustum&>(frustum) = GetShadowCamera()->m_kViewFrustum;
            frustum.m_fFarPlane = float(frustum.m_fFarPlane + DAT_0106b178);
            if (!DAT_011f91b0)
                frustum.m_fNearPlane = float(frustum.m_fFarPlane * DAT_01018a90);
            kShadowCameraPlanes.Set(&frustum, &GetShadowCamera()->m_kWorld);
            frustum.m_fNearPlane = nearPlane;
            frustum.m_fFarPlane = farPlane;
            GetShadowCamera()->FUN_00a6faf0(frustum);
            reinterpret_cast<ShadowAccumulator*>(spShadowAccumulator.m_pObject)->AssignRefCounted(this);
            DAT_01200088.MTRenderingSystem_AddAccumTask(spShadowCamera.m_pObject, 0, spShadowScene.m_pObject, 0, 0,
                                      spShadowAccumulator.m_pObject, 0, renderFlags + 0x11, 0);
        }
    }
    else if (spDynamicShadowMap.m_pObject)
    {
        DAT_011f91a8->RemoveRenderedTexture(spDynamicShadowMap.m_pObject);
        spDynamicShadowMap = 0;
        spShadowAccumulator = 0;
    }
    DAT_01200088.MTRenderingSystem_SetThreadStage(0, renderFlags + 0x11);
}
}  // namespace fnv_00b9dfc0

// The shared list has no declaration for its node-splice helper.
struct ShadowGeometryList : NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiTriBasedGeom> >
{
    void MoveNodeBefore(void*, void*);
};

extern NiRTTI g_011fed88_arg1;

// For qualifying shader properties, searches the geometry list; a match may move before pIter, otherwise the geometry is processed and passed to a list helper.
// @fnv 0x00b9f480
// Inline linkage exposes the local static bindings; calls retain the game's out-of-line body.
__declspec(noinline) inline void ShadowSceneLight::AddGeometry(NiTriBasedGeom* apGeom)
{
    static NiPointer<NiTriBasedGeom> spGeom;
    if (apGeom->m_spShader && apGeom->m_spShader->DynamicCast(&g_011fed88_arg1))
    {
        NiPropertyState* pState = &apGeom->m_PropertyState;
        if (pState)
        {
            BSShaderLightingProperty* pProp = reinterpret_cast<BSShaderLightingProperty*>(apGeom->m_PropertyState.m_aspProps[3]);
            int iType = pProp ? pProp->iShaderPropertyType : -1;
            if ((unsigned int)(iType - 1) <= 11)
            {
                void* pStart = kGeomListFence;
                void* pNode = pStart ? pStart : lGeomList.m_pkHead;
                while (pNode)
                {
                    void* pCur = pNode;
                    if (lGeomList.GetNext(pNode) == apGeom)
                    {
                        if (pStart)
                            reinterpret_cast<ShadowGeometryList&>(lGeomList).MoveNodeBefore(pCur, pStart);
                        pProp->AttachLight(this, reinterpret_cast<NiBound*>(apGeom->m_kWorldBound) ? reinterpret_cast<NiBound*>(apGeom->m_kWorldBound) : &DAT_011f4288);
                        return;
                    }
                }
                if (!pProp->GetFlag(0xc) || iType == 4)
                {
                    spGeom.m_pObject = apGeom;
                    pProp->AttachLight(this, reinterpret_cast<NiBound*>(apGeom->m_kWorldBound) ? reinterpret_cast<NiBound*>(apGeom->m_kWorldBound) : &DAT_011f4288);
                    lGeomList.AddHead(spGeom);
                    spGeom.m_pObject = 0;
                }
            }
        }
    }
}

namespace fnv_00b9f780 {
struct RenderPassSetup
{
    void MTRenderingSystem_WaitOnThreadStage(int, int);
};
extern RenderPassSetup g_01200088;

extern NiColorA DAT_011a9bd0;

extern NiRenderer* DAT_011f4748;
// This call passes a texture index; the shared declaration currently omits it.
typedef void* (__thiscall BSRenderedTexture::*RenderedTextureAt)(int);
void BSRenderedTexture_StartOffscreen(unsigned int, void*);

extern NiDX9Renderer* DAT_011f9508;
void FUN_00b6c0d0(NiCamera*, BSShaderAccumulator*, int);
void __stdcall D3DXMatrixMultiply_00ee6de0(D3DXMATRIX*, D3DXMATRIX*, D3DXMATRIX*);
void FUN_00b6b790();
extern int DAT_011f91b0;

extern ShadowTextureManager* DAT_011f91a8;

// local form of ImageSpaceEffectParam: 0x00b9f780 needs a 0x24-byte stack object (shared extent 1053 vs 1056).
struct ShadowEffectParamLocal_00b9f780
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    ShadowEffectParamLocal_00b9f780();
    ~ShadowEffectParamLocal_00b9f780();
};
struct PassEffect
{
    void SetAccumulatorAt(int, ImageSpaceTexture*, int);
};

extern ImageSpaceManager* DAT_011f91ac;
__forceinline ImageSpaceManager* GetImageManager()
{
    return DAT_011f91ac;
}
extern float DAT_010162c0;
extern float DAT_012003c4;
struct PassDebug
{
    void AddTexture(void*);
};
PassDebug* __cdecl BSShaderManager_GetShader(int);
struct ShadowPass : ShadowSceneLight
{
    void ShadowSceneLight_MTRenderFrustumDepthMap(BSCullingProcess*, int);
};
// Renders the shadow pass by setting up the shadow matrices from the light and camera, then applies the image space effect to the light rendered texture.
// @fnv 0x00b9f780
// src: COMMUNITY 0x00b9f780
void ShadowPass::ShadowSceneLight_MTRenderFrustumDepthMap(BSCullingProcess* context, int pass)
{
    g_01200088.MTRenderingSystem_WaitOnThreadStage(1, pass + 17);
    NiColorA previous = DAT_011a9bd0;
    DAT_011f4748->GetBackgroundColor(reinterpret_cast<NiVector4*>(&previous));
    {
        NiColorA white(1.0f, 1.0f, 1.0f, 1.0f);
        DAT_011f4748->SetBackgroundColor(reinterpret_cast<NiVector4*>(&white));
    }
    BSRenderedTexture_StartOffscreen(7, static_cast<void*>(spDynamicShadowMap.m_pObject->GetGroup()));
    DAT_011f4748->SetBackgroundColor(reinterpret_cast<NiVector4*>(&previous));
    context->m_acRendererDataA = reinterpret_cast<BSShaderAccumulator*>(spShadowAccumulator.m_pObject);
    BSShaderAccumulator* renderAccum = reinterpret_cast<BSShaderAccumulator*>(spShadowAccumulator.m_pObject);
    NiCamera* renderCamera = spShadowCamera.m_pObject;
    FUN_00b6c0d0(renderCamera, renderAccum, 0);
    {
        BSShaderAccumulator* accum = reinterpret_cast<BSShaderAccumulator*>(spShadowAccumulator.m_pObject);
        if (accum->spShadowLight.m_pObject)
        {
            accum->spShadowLight.m_pObject->NiRefObject::DecRefCount();
            accum->spShadowLight.m_pObject = 0;
        }
    }
    if (context->m_acRendererDataA.m_pObject)
    {
        context->m_acRendererDataA.m_pObject->NiRefObject::DecRefCount();
        context->m_acRendererDataA.m_pObject = 0;
    }
    NiCamera* camera = spShadowCamera.m_pObject;
    NiPoint3 up;
    up.x = camera->m_kWorld.m_Rotate.m_pEntry[0][2];
    up.y = camera->m_kWorld.m_Rotate.m_pEntry[1][2];
    up.z = camera->m_kWorld.m_Rotate.m_pEntry[2][2];
    NiPoint3 right;
    right.x = camera->m_kWorld.m_Rotate.m_pEntry[0][1];
    right.y = camera->m_kWorld.m_Rotate.m_pEntry[1][1];
    right.z = camera->m_kWorld.m_Rotate.m_pEntry[2][1];
    NiPoint3 dir;
    dir.x = camera->m_kWorld.m_Rotate.m_pEntry[0][0];
    dir.y = camera->m_kWorld.m_Rotate.m_pEntry[1][0];
    dir.z = camera->m_kWorld.m_Rotate.m_pEntry[2][0];
    NiDX9Renderer* renderer = DAT_011f9508;
    renderer->SetCurrentCamera(camera);
    __declspec(align(16)) D3DXMATRIX view = reinterpret_cast<const D3DXMATRIX&>(renderer->kD3DView);
    NiLight* light = spLight.m_pObject;
    D3DXMATRIX proj = reinterpret_cast<const D3DXMATRIX&>(renderer->kD3DProj);
    NiTransform transform = light->m_kWorld;
    kShadowView = view;
    kShadowView._41 = -transform.m_Translate.Dot(up);
    kShadowView._42 = -transform.m_Translate.Dot(right);
    kShadowView._43 = -transform.m_Translate.Dot(dir);
    kShadowProj = proj;
    D3DXMatrixMultiply_00ee6de0(&proj, &kShadowView, &kShadowProj);
    kViewProjection = proj;
    FUN_00b6b790();
    if (!DAT_011f91b0)
    {
        BSRenderedTexture* texture = DAT_011f91a8->ActivatePending();
        ImageSpaceTexture input;
        input.ImageSpaceTexture_SetTexture(texture);
        ShadowEffectParamLocal_00b9f780 param;
        DAT_012003c4 = DAT_010162c0;
        PassEffect* effect = reinterpret_cast<PassEffect**>(*reinterpret_cast<void**>(GetImageManager()->pEffectList + 4))[17];
        effect->SetAccumulatorAt(2, &input, 0);
        NiDX9Renderer* renderer2 = DAT_011f9508;
        GetImageManager()->RenderEffect(17, reinterpret_cast<GraphicsRenderer*>(renderer2), spDynamicShadowMap.m_pObject,
                                        spDynamicShadowMap.m_pObject, reinterpret_cast<::ImageSpaceEffectParam*>(&param), true);
        DAT_011f91a8->RemoveRenderedTexture(texture);
    }
    if (bShowDebugTexture)
    {
        void* texture =
            (spDynamicShadowMap.m_pObject->*reinterpret_cast<RenderedTextureAt>(&BSRenderedTexture::BSRenderedTexture_GetTexture))(0);
        PassDebug* debug = BSShaderManager_GetShader(9);
        debug->AddTexture(texture);
    }
    bClipSpacePlanesReady = false;
}
}  // namespace fnv_00b9f780

inline const NiCamera* NiCullingProcess::GetCamera() const { return m_pkCamera; }
inline float NiPlane::Distance(const NiPoint3& point) const
{
    return x * point.x + point.y * y + point.z * z - c;
}

extern "C" double __cdecl sqrt(double);
static inline float ShadowUpdateSqrt(float value)
{
    return static_cast<float>(sqrt(static_cast<double>(value)));
}

struct RenderContextView_b9e
{
    int unk00, unk04;
    NiCamera* object;
};
namespace sb9e {
extern "C" RenderContextView_b9e* __cdecl BSShaderManager_GetAccumulator();
extern "C" int DAT_011f91c0;
extern "C" char DAT_011f91d8;
extern "C" float DAT_011f9444, DAT_011f9448, DAT_011f9410, DAT_011ad834;
extern "C" int DAT_011f944c, DAT_011f9450;
}

inline bool ShadowFeatureEnabled_b9e()
{
    return (sb9e::DAT_011f91d8 & 16) > 0;
}
inline bool CanCube_b9e()
{
    return sb9e::DAT_011f91c0 >= 3 ? (sb9e::DAT_011f91d8 & 16) > 0 : false;
}

namespace sb9e {
extern "C" BSTextureManager* DAT_011f91a8;
}

struct ShadowSceneCulling : ShadowSceneLight
{
    __declspec(noalias) bool ShadowSceneLight_FrustumFrustumIntersection(const NiCamera*, NiCamera*);
    bool ShadowSceneLight_CubeFaceFrustumFrustumIntersection(NiSphere, NiCullingProcess*, unsigned short);
    void ShadowSceneLight_TestFrustumCull(NiCullingProcess*);
};
// Culls the shadow light against the camera frustum, computes distance-based fade factors, and marks lighting shaders dirty when state changes.
// @fnv 0x00b9e970
// src: COMMUNITY 0x00b9e970
void ShadowSceneCulling::ShadowSceneLight_TestFrustumCull(NiCullingProcess* camera)
{
    NiLight* light = spLight.m_pObject;
    unsigned uiCullMask = 0;
    NiSphere bound;
    *reinterpret_cast<NiPoint3*>(&bound) = light->m_kWorld.m_Translate;
    bound.r = light->m_kSpec.r;
    bool castShadow = bCastShadow;

    bool contained = true;
    if (castShadow && spShadowCamera.m_pObject)
    {
        uiCullMask = ShadowSceneLight_FrustumFrustumIntersection(camera->GetCamera(), spShadowCamera.m_pObject) ? 0 : 255;
    }
    else
    {
        NiFrustumPlanes planes = reinterpret_cast<const NiFrustumPlanes&>(camera->m_kPlanes);
        for (unsigned planeIndex = 0; planeIndex < 6; ++planeIndex)
        {
            if (planes.m_uiActivePlaneMask & (1 << planeIndex))
            {
                NiPlane plane = planes.m_akPlanes[planeIndex];
                float distance = float(plane.x * bound.x + bound.y * plane.y +
                                       bound.z * plane.z) -
                                 plane.c;
                if (distance <= -bound.r)
                {
                    uiCullMask = 255;
                    goto cullDone;
                }
                const float& d = plane.Distance(reinterpret_cast<const NiPoint3&>(bound));
                if (d < 0.0f)
                    contained = false;
            }
        }
        if (!contained && castShadow && CanCube_b9e() && bCubeShadowMap)
        {
            for (unsigned short face = 0; face < 6; ++face)
                if (!ShadowSceneLight_CubeFaceFrustumFrustumIntersection(bound, camera, face))
                    uiCullMask |= 1 << face;
        }
    }
cullDone:
    float dimmer = fLODDimmer;
    float shadow = fShadowLODDimmer;
    float blend;
    if ((unsigned short)uiCullMask != 255)
    {
        const NiCamera* cameraObject = camera->m_pkCamera;
        NiPoint3 cameraPosition = cameraObject->m_kWorld.m_Translate;
        NiPoint3 delta;
        delta.x = bound.x - cameraPosition.x;
        delta.y = bound.y - cameraPosition.y;
        delta.z = bound.z - cameraPosition.z;
        float distance = ShadowUpdateSqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z) - bound.r;
        if (sb9e::BSShaderManager_GetAccumulator()->object)
            distance *= sb9e::BSShaderManager_GetAccumulator()->object->m_fLODAdjust;
        if (distance < sb9e::DAT_011f9444 || sb9e::DAT_011f9448 == 0.0f)
            dimmer = 1.0f;
        else if (sb9e::DAT_011f9448 < distance)
        {
            uiCullMask = 255;
            shadow = dimmer = 0.0f;
            goto propertyFade;
        }
        else
        {
            dimmer = 1.0f - (distance - sb9e::DAT_011f9444) / (sb9e::DAT_011f9448 - sb9e::DAT_011f9444);
            if (!(dimmer > 0.0f))
                goto propertyFade;
        }
        if (bCastShadow)
        {
            if (distance < reinterpret_cast<float&>(sb9e::DAT_011f944c) ||
                reinterpret_cast<float&>(sb9e::DAT_011f9450) == 0.0f)
                shadow = 1.0f;
            else if (distance > reinterpret_cast<float&>(sb9e::DAT_011f9450))
                shadow = 0.0f;
            else
                shadow = 1.0f - (distance - reinterpret_cast<float&>(sb9e::DAT_011f944c)) /
                                    (reinterpret_cast<float&>(sb9e::DAT_011f9450) -
                                     reinterpret_cast<float&>(sb9e::DAT_011f944c));
        }
    propertyFade:
        if (spShadowScene.m_pObject)
        {
            NiMaterialProperty* pAlphaProperty = reinterpret_cast<NiMaterialProperty*>(static_cast<NiGeometry*>(spShadowScene.m_pObject)->FUN_00a59d30(2));
            if (pAlphaProperty)
                shadow *= reinterpret_cast<float&>(pAlphaProperty->unk3c);
        }
        fShadowLODDimmerElapsed += sb9e::DAT_011f9410;
        float ratio = fShadowLODDimmerElapsed / sb9e::DAT_011ad834;
        blend = (1.0f < ratio) ? 1.0f : ratio;
        if (fShadowLODDimmerTarget == 0.0f)
            shadow = (1.0f - blend) * shadow;
        else
            shadow = blend * shadow;
    }
    if ((usFrustumCull == 255 && (unsigned short)uiCullMask != 255) ||
        (usFrustumCull != 255 && (unsigned short)uiCullMask == 255) ||
        (fLODDimmer == 0.0f && dimmer > 0.0f) || (fLODDimmer > 0.0f && dimmer == 0.0f) ||
        (fShadowLODDimmer == 0.0f && shadow > 0.0f) || (fShadowLODDimmer > 0.0f && shadow == 0.0f))
    {
        NiTListItem<NiTriBasedGeom*>* node = *(NiTListItem<NiTriBasedGeom*>**)&lGeomList;
        while (node)
        {
            NiTriBasedGeom* const& geometry = node->m_element;
            node = node->m_pkNext;
            if (geometry)
            {
                BSShaderLightingProperty* prop = reinterpret_cast<BSShaderLightingProperty*>(geometry->m_PropertyState.m_aspProps[3]);
                BSShaderLightingProperty* pLightingShader = (!prop ? 0 : (static_cast<unsigned int>(prop->iShaderPropertyType) - 1 <= 11)) ? prop : 0;
                if (pLightingShader)
                    pLightingShader->bLightListChanged = true;
            }
        }
        if (fShadowLODDimmer == 0.0f && spDynamicShadowMap.m_pObject)
        {
            sb9e::DAT_011f91a8->RemoveRenderedTexture(spDynamicShadowMap.m_pObject);
            spDynamicShadowMap = 0;
        }
    }
    usFrustumCull = (unsigned short)uiCullMask;
    fLODDimmer = dimmer;
    fShadowLODDimmer = shadow;
}
