#include "../../include/NiTListItem.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"
// bsshader/shadowscenenode.cpp: shadow scene operations (63 functions)

#include "../../include/AutoMemContext.h"
#include "../../include/BSRenderedTexture.h"
#include "../../include/BSTextureManager.h"
#include "../../include/ShadowSceneLight.h"
#include "../../include/ShadowSceneNode.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSShaderLightingProperty.h"
#include "../../include/BSShaderProperty.h"
#include "../../include/Bound.h"
#include "../../include/NiDirectionalLight.h"
#include "../../include/NiLight.h"
#include "../../include/NiPlane.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/SceneGraph.h"
#include "../../include/StrArr.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiColor.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerList.h"
#include "../../include/hkReferencedObject.h"
#include <string.h>

// Inline implementations used by this unit remain here alongside the shared declarations.
inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c) {}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0) DeleteThis();
}


template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    return *this = kSrc.m_pObject;
}
template <class TAlloc, class T> inline T& NiTPointerListBase<TAlloc, T>::GetNext(void*& pos)
{
    NiTListItem<T>* item = static_cast<NiTListItem<T>*>(pos);
    T& element = item->m_element;
    pos = item->m_pkNext;
    return element;
}

void __fastcall RemoveShadowList(void*);
inline ShadowList::ShadowList() { count = 0; head = 0; tail = 0; }
inline ShadowList::~ShadowList() { RemoveAll(); }
template <class T> inline ShadowSceneList<T>::ShadowSceneList()
{
    m_kItemCount.m_uiCount = 0;
    m_pkHead = 0;
    m_pkTail = 0;
}
template <class T> inline ShadowSceneList<T>::~ShadowSceneList() { RemoveAll(); }
template <class T> inline void ShadowSceneList<T>::RemoveAll() { RemoveShadowList(this); }
inline BSCompoundFrustum::~BSCompoundFrustum() { FUN_00c47770(); }
template <> inline NiPointer<BSFogProperty>::~NiPointer()
{
    if (m_pObject) reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
}
template <> inline NiPointer<NiCamera>::~NiPointer()
{
    if (m_pObject) reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
}
inline void ShadowList::RemoveAll() { RemoveShadowList(this); }

extern BSTextureManager* DAT_011f91a8;
struct ShadowListItem
{
    ShadowListItem* next;
    ShadowListItem* prev;
    ShadowSceneLight* light;
};

struct ShadowLightFlags
{
    char pad[0x30];
    unsigned flags;
    char pad34[0x94];
    NiPoint3 ambient;
    NiPoint3 diffuse;
};

inline float ShadowMax(float a, float b)
{
    return a > b ? a : b;
}

// @fnv 0x00b5eeb0
void ShadowSceneNode::AddObject(NiAVObject* apObject)
{
    if (!apObject)
        return;
    if (apObject->m_uFlags & 1)
        return;
    RemoveSceneObject(apObject, false);
}

// Releases each shadow light's texture, clears the shadow light list, and resets the shadow counts to zero.
// @fnv 0x00b5c3c0
void ShadowSceneNode::UpdateShadowLights()
{
    ShadowListItem* item = lShadowLightList.head;
    while (item)
    {
        ShadowSceneLight*& lightRef = item->light;
        item = item->next;
        ShadowSceneLight* light = lightRef;
        if (light)
        {
            DAT_011f91a8->RemoveRenderedTexture(light->spDynamicShadowMap.m_pObject);
            BSRenderedTexture* old = light->spDynamicShadowMap.m_pObject;
            if (old)
            {
                if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&reinterpret_cast<NiRefObject*>(old)->m_uiRefCount)))
                    reinterpret_cast<NiRefObject*>(old)->DeleteThis();
                light->spDynamicShadowMap.m_pObject = 0;
            }
        }
    }
    lShadowLightList.RemoveAll();
    kShadowLightActiveFence = 0;
    kShadowLightFadingInFence = 0;
}

// @fnv 0x00b5b4d0
float ShadowSceneNode::CalculateLightingAtPoint(NiPoint3 point, int& count, float& ambient, float& diffuse,
                                                NiLight* ignore)
{
    float total = 0.0f;
    ShadowListItem* item = lLightList.head;
    while (item)
    {
        ShadowSceneLight*& ref = item->light;
        item = item->next;
        ShadowSceneLight* light = ref;
        if (light)
        {
            total += light->ComputeLightAttenuation(*reinterpret_cast<const NiPoint3*>(&point), ignore);
            if (total > 0.0f)
                ++count;
        }
    }
    ShadowLightFlags* data = reinterpret_cast<ShadowLightFlags*>(pSunLight->spLight.m_pObject);
    NiPoint3 color;
    memcpy(&color, &data->ambient, sizeof(color));
    ambient = ShadowMax(color.x, ShadowMax(color.y, color.z));
    memcpy(&color, &data->diffuse, sizeof(color));
    diffuse = ShadowMax(color.x, ShadowMax(color.y, color.z));
    return total;
}

struct Node_00b5ac20
{
    Node_00b5ac20* pNext;
    Node_00b5ac20* pPrev;
    void* pItem;
};

struct List_00b5ac20
{
    Node_00b5ac20* pHead;
    Node_00b5ac20* pTail;
    unsigned int ItemUpdateArray;

    void* GetNext(Node_00b5ac20*& pos) const
    {
        if (!pos)
            return 0;
        void* item = pos->pItem;
        pos = pos->pNext;
        return item;
    }

    void* GetNextNoCheck(Node_00b5ac20*& pos) const
    {
        void** pItem = &pos->pItem;
        pos = pos->pNext;
        return *pItem;
    }
};

// Returns the item at the given index from the list at pThis+0xb4, or null if the index is out of range.
// @fnv 0x00b5ac20
void* __fastcall GetListItemAt(char* pThis, int, unsigned int index)
{
    List_00b5ac20* list = (List_00b5ac20*)(pThis + 0xb4);
    if (index >= list->ItemUpdateArray)
        return 0;

    Node_00b5ac20* pos = list->pHead;
    void* item = list->GetNextNoCheck(pos);

    for (unsigned int i = 0; i < index; ++i)
    {
        item = list->GetNextNoCheck(pos);
    }

    return item;
}

// Assigns pObj to the reference-counted pointer at pThis+0x10c, releasing the old object and retaining the new one.
// @fnv 0x00b5aee0
void __fastcall AssignRefObject(char* pThis, int, NiRefObject* pObj)
{
    NiRefObject*& spField = *(NiRefObject**)(pThis + 0x10c);
    if (spField != pObj)
    {
        if (spField)
            spField->DecRefCount();

        spField = pObj;

        if (spField)
            spField->IncRefCount();
    }
}

// Assigns pObj to the reference-counted pointer at pThis+0x128, releasing the old object and retaining the new one.
// @fnv 0x00b5af30
// src: COMMUNITY 0x00b5af30
void __fastcall ShadowSceneLight_SetShadowCaster(char* pThis, int, NiRefObject* pObj)
{
    NiRefObject*& pRef = *(NiRefObject**)(pThis + 0x128);
    if (pRef != pObj)
    {
        if (pRef)
            pRef->DecRefCount();

        pRef = pObj;

        if (pRef)
            pRef->IncRefCount();
    }
}

void __fastcall ClearShaderPropRefs(void* pThis);

struct ShadowLightNode
{
    ShadowLightNode* m_pkNext;
    ShadowLightNode* m_pkPrev;
    char* m_val;
};

static inline char*& GetNextLight(ShadowLightNode*& pkIter)
{
    char*& rVal = pkIter->m_val;
    pkIter = pkIter->m_pkNext;
    return rVal;
}

// @fnv 0x00b5b060
// src: COMMUNITY 0x00b5b060
void __fastcall ShadowSceneNode_DisableAllShadowLights(char* pThis, int)
{
    ShadowLightNode* pkIter = *(ShadowLightNode**)(pThis + 0xC0);
    while (pkIter)
    {
        char* pkLight = GetNextLight(pkIter);
        if (pkLight && *(void**)(pkLight + 0xF8))
        {
            DAT_011f91a8->RemoveRenderedTexture(*(BSRenderedTexture**)(pkLight + 0x10C));
            BSRenderedTexture* pkTex = *(BSRenderedTexture**)(pkLight + 0x10C);
            if (pkTex)
            {
                if (InterlockedDecrement(reinterpret_cast<volatile long*>(&reinterpret_cast<NiRefObject*>(pkTex)->m_uiRefCount)) == 0)
                    reinterpret_cast<NiRefObject*>(pkTex)->DeleteThis();
                *(BSRenderedTexture**)(pkLight + 0x10C) = 0;
            }
            *(unsigned int*)(*(char**)(pkLight + 0xF8) + 0x30) |= 1;
            ClearShaderPropRefs(pkLight);
        }
    }
}

struct VTableStub_00b5b150
{
    void* f0;
    void* f1;
    void* f2;
    void*(__thiscall* GetAsNode)(void*);
    void* f4;
    void* f5;
    void* f6;
    int(__thiscall* GetAsGeometry)(void*);
};

void __cdecl ShadowSceneNode_RemoveLightsFromGeom(void* pObj);

// Iterates the children of pNode, calling FUN_00b5b0e0 on geometry children and recursing into node children.
// @fnv 0x00b5b150
void __fastcall ProcessNodeChildren(void* pThis, int, void* pNode)
{
    for (unsigned int i = 0; i < *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pNode) + 0xa6); ++i)
    {
        void* pChild = (*reinterpret_cast<void***>(reinterpret_cast<char*>(pNode) + 0xa0))[i];
        if (pChild)
        {
            if ((*reinterpret_cast<VTableStub_00b5b150**>(pChild))->GetAsGeometry(pChild))
            {
                ShadowSceneNode_RemoveLightsFromGeom(pChild);
            }
            else
            {
                void* pChildNode = (*reinterpret_cast<VTableStub_00b5b150**>(pChild))->GetAsNode(pChild);
                if (pChildNode)
                {
                    reinterpret_cast<void(__thiscall*)(void*, void*)>(&ProcessNodeChildren)(pThis, pChildNode);
                }
            }
        }
    }
}

void __fastcall BSSimpleArray_Resize(void* pThis);

struct ArrayLike
{
    virtual ~ArrayLike();
    virtual void* Allocate(unsigned int);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;

    void Realloc(unsigned int a, unsigned int b)
    {
        ((void(__thiscall*)(ArrayLike*, unsigned int, unsigned int))BSSimpleArray_Resize)(this, a, b);
    }
};

// Grows the array's capacity if it is full, then increments m_uiSize and returns the index of the newly appended slot.
// @fnv 0x00b5c360
// src: COMMUNITY 0x00b5c360
unsigned int __fastcall BSSimpleArray_GetNextIndex_2(ArrayLike* pThis)
{
    if (pThis->m_uiSize == pThis->m_uiCapacity)
    {
        if (pThis->m_uiCapacity == 0)
        {
            pThis->m_pData = pThis->Allocate(4);
            pThis->m_uiCapacity = 4;
        }
        else
        {
            unsigned int uiNewCapacity =
                (pThis->m_uiCapacity > 0x400) ? (pThis->m_uiCapacity + 0x400) : (pThis->m_uiCapacity * 2);
            pThis->Realloc(uiNewCapacity, pThis->m_uiSize);
            pThis->m_uiCapacity = uiNewCapacity;
        }
    }
    pThis->m_uiSize++;
    return pThis->m_uiSize - 1;
}

struct FUN_00b5aa40_self
{
    unsigned char pad0[0xa0];
    void** items;
    unsigned char pad1[2];
    unsigned short count;
    unsigned char pad2[8];
    int index;
};

// Returns the item at self->index if it is within [0, self->count), otherwise returns null.
// @fnv 0x00b5aa40
// src: COMMUNITY 0x00b5aa40
void* __fastcall NiSwitchNode_GetActiveChild(FUN_00b5aa40_self* self, int unused)
{
    if (self->index >= 0 && self->index < self->count)
        return self->items[self->index];
    return 0;
}

// Walks the linked list from self->head and counts nodes whose item is non-null and whose id is not 0xff.
// @fnv 0x00b5ac60
// src: COMMUNITY 0x00b5ac60
int __fastcall ShadowSceneNode_GetActiveLightCount(ShadowSceneNode* self, int unused)
{
    int count = 0;
    ShadowListItem* n = self->lLightList.head;
    while (n)
    {
        ShadowSceneLight* const* pp = &n->light;
        n = n->next;
        ShadowSceneLight* it = *pp;
        if (it && it->usFrustumCull != 0xff)
            ++count;
    }
    return count;
}

struct ArrOps
{
    void BSSimpleArray_ShadowSceneLight_1024_MoveItems(unsigned* dst, unsigned* src, unsigned n);
};
struct FUN_00b5ade0_arr
{
    virtual void* vfn_00();
    virtual void* Alloc(unsigned n);
    virtual void Free(void* p);
    unsigned* data;
    unsigned count;
    unsigned capacity;
};
// Removes the element at index, shifting the tail down, or reallocates a smaller buffer when shrinking and the count is low enough.
// @fnv 0x00b5ade0
// src: COMMUNITY 0x00b5ade0
void __fastcall BSSimpleArray_ShadowSceneLight_1024_Remove(FUN_00b5ade0_arr* self, int, unsigned index, bool shrink)
{
    if (shrink)
    {
        unsigned cap = self->capacity;
        if (cap > 0x400)
        {
            if (self->count <= cap - 0x800)
                goto resize;
        }
        else
        {
            if (!(self->count > (cap >> 2)))
                goto resize;
        }
    }
    {
        unsigned* p = self->data + index;
        ((ArrOps*)self)->BSSimpleArray_ShadowSceneLight_1024_MoveItems(p, p + 1, self->count - index - 1);
        self->count--;
        return;
    }
resize:
    unsigned newCap = self->capacity > 0x800 ? self->capacity - 0x400 : self->capacity >> 1;
    unsigned* puiNewData = (unsigned*)self->Alloc(newCap);
    ((ArrOps*)self)->BSSimpleArray_ShadowSceneLight_1024_MoveItems(puiNewData, self->data, index);
    ((ArrOps*)self)->BSSimpleArray_ShadowSceneLight_1024_MoveItems(puiNewData + index, self->data + index + 1, self->count - 1);
    self->Free(self->data);
    self->count--;
    self->data = puiNewData;
    self->capacity = newCap;
}

struct FUN_00b5aea0_self
{
    int pad0;
    int* data;
    unsigned int count;
    void BSSimpleArray_ShadowSceneLight_1024_MoveItems(int* dst, int* src, unsigned int n);
    void RemoveRange(unsigned int start, unsigned int n);
};

// Copies up to n elements from the end of the buffer into the gap at start, then reduces count by n.
// @fnv 0x00b5aea0
void FUN_00b5aea0_self::RemoveRange(unsigned int start, unsigned int n)
{
    unsigned int m = count - start - n;
    if (m >= n)
        m = n;
    BSSimpleArray_ShadowSceneLight_1024_MoveItems(data + start, data + (count - m), m);
    count -= n;
}

struct FUN_00b5af80_self
{
    virtual void v0();
    virtual void v1();
    virtual void Release(void* obj);
    void* obj;
    int a;
    int b;
    void UpdateFields_00b5af80(bool destroy);
};

// If obj is set, releases it when destroy is true (clearing obj and b), then resets a to 0.
// @fnv 0x00b5af80
// src: GUESS 0x00b5af80 (confidence: low)
void FUN_00b5af80_self::UpdateFields_00b5af80(bool destroy)
{
    if (obj)
    {
        if (destroy)
        {
            Release(obj);
            obj = 0;
            b = 0;
        }
        a = 0;
    }
}

struct NiAVObjectVirt
{
    virtual ~NiAVObjectVirt();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual NiNode* vfunc3();
};

// If apObject is non-null, gets its node via vfunc3 and, when that node exists, passes it to ProcessNodeChildren on thisptr.
// @fnv 0x00b5b1c0
// src: XBOX_PDB 0x00b5b1c0
void ShadowSceneNode::RemoveObject_00b5b1c0(NiAVObject* apObject)
{
    if (apObject)
    {
        NiNode* pnode = ((NiAVObjectVirt*)apObject)->vfunc3();
        if (pnode)
            reinterpret_cast<void (__thiscall*)(ShadowSceneNode*, NiNode*)>(&ProcessNodeChildren)(this, pnode);
    }
}

// Walks the linked list from self->head and returns the first item whose key equals key, or null if none matches.
// @fnv 0x00b5b4a0
// src: XBOX_PDB 0x00b5b4a0
ShadowSceneLight* __fastcall ShadowSceneNode_GetLight(ShadowSceneNode* self, int unused, int key)
{
    ShadowListItem* n = self->lLightList.head;
    while (n)
    {
        ShadowSceneLight* const* pp = &n->light;
        n = n->next;
        ShadowSceneLight* it = *pp;
        if (it && reinterpret_cast<int>(it->spLight.m_pObject) == key)
            return it;
    }
    return 0;
}

void __fastcall SetShadowEnabled(ShadowSceneLight* light, int, bool enable);

// Walks the linked list from self->lLightList.head and, for the first item whose key matches, calls SetShadowEnabled with flag.
// @fnv 0x00b5c450
void __fastcall CallItemMethodByKey(ShadowSceneNode* self, int unused, int key, int flag)
{
    ShadowListItem* n = self->lLightList.head;
    while (n)
    {
        ShadowSceneLight* const* pp = &n->light;
        n = n->next;
        ShadowSceneLight* it = *pp;
        if (it && reinterpret_cast<int>(it->spLight.m_pObject) == key)
        {
            reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, int)>(&SetShadowEnabled)(it, flag);
            return;
        }
    }
}

void __fastcall ResetSceneLight(ShadowSceneLight*, int);
void __fastcall ProcessSceneLight(ShadowSceneNode*, int, ShadowSceneLight*);
struct V3D
{
    float x, y, z;
};
struct LightDataD
{
    char pad[0x30];
    unsigned flags;
    char pad2[0x58];
    V3D pos;
};

struct PosD
{
    bool _Call_439090(const V3D*);
};
void __fastcall SetLightPosition(ShadowSceneLight*, int, V3D);
// @fnv 0x00b5d930
// src: COMMUNITY 0x00b5d930
void __fastcall ShadowSceneNode_UpdateQueuedDynamicLight(ShadowSceneNode* self, int, ShadowSceneLight* l)
{
    if (l->bPointLight && l->bDynamicLight && !l->bCastShadow)
    {
        LightDataD* d = reinterpret_cast<LightDataD*>(l->spLight.m_pObject);
        if (d->flags & 1)
        {
            reinterpret_cast<void (__thiscall*)(ShadowSceneLight*)>(&ResetSceneLight)(l);
            return;
        }
        V3D p = *reinterpret_cast<V3D*>(&l->bPointPosition);
        if (((PosD*)&p)->_Call_439090(&d->pos) && l->usFrustumCull != 0xff)
        {
            reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, V3D)>(&SetLightPosition)(l, d->pos);
            reinterpret_cast<void (__thiscall*)(ShadowSceneNode*, ShadowSceneLight*)>(&ProcessSceneLight)(self, l);
        }
    }
}

void __fastcall RemoveLightObjects(ShadowSceneNode*, int, ShadowSceneLight*);

// @fnv 0x00b5ddb0
void __fastcall UpdateLightObjects(ShadowSceneNode* self, int, bool a, bool b)
{
    if (a)
    {
        ShadowListItem* n = self->lLightList.head;
        while (n)
        {
            ShadowSceneLight* const* pp = &n->light;
            n = n->next;
            ShadowSceneLight* it = *pp;
            if (it)
                reinterpret_cast<void (__thiscall*)(ShadowSceneNode*, ShadowSceneLight*)>(&RemoveLightObjects)(self, it);
        }
        if (!b)
            self->RemoveAllLights();
    }
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
GlobalObjectO2_00a7b610 g_011f9e80;

// @fnv 0x00b5e590
// src: XBOX_PDB 0x00b5e590
GlobalObjectO2_00a7b610* ShadowSceneNode_GetRTTI()
{
    return &g_011f9e80;
}

void* __cdecl FUN_00ec7230(void*, const void*, unsigned int);
// @fnv 0x00cb9930
// src: COMMUNITY 0x00cb9930
void __fastcall BSSimpleArray_ShadowSceneLight_1024_MoveItems(void* self, int, unsigned* dst, unsigned* src, unsigned count)
{
    if (count > 0)
    {
        if (dst < src)
        {
            for (unsigned i = 0; i < count; i++)
                FUN_00ec7230(&dst[i], &src[i], 4);
        }
        else if (dst > src)
        {
            for (int i = count - 1; i >= 0; i--)
                FUN_00ec7230(&dst[i], &src[i], 4);
        }
    }
}

inline void NiDirectionalLight::SetAmbientColor(const NiColor& color)
{
    m_kAmb = color;
    revID++;
}
inline void NiDirectionalLight::SetDiffuseColor(const NiColor& color)
{
    m_kDiff = color;
    revID++;
}
inline void NiLight::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
inline void NiLight::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis();
}
inline bool NiLight::IsKindOfType(const NiRTTI* pkRTTI) const
{
    for (const NiRTTI* pkType = GetRTTI(); pkType; pkType = pkType->m_pBaseRTTI)
    {
        if (pkType == pkRTTI) return true;
    }
    return false;
}

namespace fnv_00b9dda0 { void __fastcall BindLight(ShadowSceneLight*, int, NiLight*); }
extern NiColor DAT_011f4998;

// @fnv 0x00b5aac0
void __fastcall SetSunLight(ShadowSceneNode* self, int, NiDirectionalLight* apLight)
{
    if (self->pSunLight)
    {
        delete self->pSunLight;
        self->pSunLight = 0;
    }
    if (apLight)
    {
        self->pSunLight = new ShadowSceneLight;
        reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, NiLight*)>(&fnv_00b9dda0::BindLight)(self->pSunLight, apLight);
    }
    else
    {
        NiDirectionalLight* pdefaultsun = new NiDirectionalLight;
        pdefaultsun->SetAmbientColor(DAT_011f4998);
        pdefaultsun->SetDiffuseColor(DAT_011f4998);
        self->pSunLight = new ShadowSceneLight;
        reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, NiLight*)>(&fnv_00b9dda0::BindLight)(self->pSunLight, pdefaultsun);
    }
}

struct SSFrustumPlanes
{
    NiPlane m_akPlanes[6];
    unsigned int m_uiActivePlaneMask;
    SSFrustumPlanes()
    {
        m_uiActivePlaneMask = 0x3f;
    }
};
struct SSCullData
{
    unsigned int aData[25];
    SSFrustumPlanes g_kFrustumPlanes;
};
struct SSCamera
{
    char pad0[0x8c];
    NiPoint3 m_kWorldTranslate;
    char pad1[0xdc - 0x98];
    char m_kViewFrustum[0x1c];
};
struct FUN_00a693e0
{
    unsigned int pad0[3];
    SSCamera* m_pkAccumulationCamera;
    unsigned int pad1[7];
    ~FUN_00a693e0();
};
struct FUN_00a69400 : FUN_00a693e0
{
    FUN_00a69400(void* pkVisibleSet);
    void NiCullingProcess_SetFrustum(void* pkFrustum);
};
struct SSNode
{
    char pad[0x40];
    int iState;
    bool BSOcclusionPlane_WithinFrustum(void* pkData, int iFlags, NiPoint3 kIntersectionOffset);
    bool BSOcclusionPlane_ViewerOnCorrectSide(NiPoint3 kPoint);
};
struct SSListNode
{
    SSListNode* m_pkNext;
    SSListNode* m_pkPrev;
    SSNode* m_element;
};
struct SSListOwner
{
    char pad[8];
    SSListNode* m_pkHead;
    SSListNode* GetHeadPos() const
    {
        return m_pkHead;
    }
    SSNode* const& GetNext(SSListNode*& kPos) const
    {
        SSNode* const& kElement = kPos->m_element;
        kPos = kPos->m_pkNext;
        return kElement;
    }
};

// @fnv 0x00b5ac90
void __fastcall UpdatePortalVisibility(ShadowSceneNode* self, int, SSCamera* pkCamera)
{
    if (reinterpret_cast<SSListOwner*>(self->pBSPortalGraph))
    {
        FUN_00a69400 kCuller(0);
        kCuller.m_pkAccumulationCamera = pkCamera;
        kCuller.NiCullingProcess_SetFrustum(&pkCamera->m_kViewFrustum);
        SSListNode* pkPos = reinterpret_cast<SSListOwner*>(self->pBSPortalGraph)->GetHeadPos();
        SSCullData kData;
        while (pkPos)
        {
            SSNode* pkNode = reinterpret_cast<SSListOwner*>(self->pBSPortalGraph)->GetNext(pkPos);
            if (pkNode)
            {
                bool bA = pkNode->BSOcclusionPlane_WithinFrustum(&kData, 0, *reinterpret_cast<const NiPoint3*>(&NiPoint3::ZERO));
                bA &= pkNode->BSOcclusionPlane_ViewerOnCorrectSide(*reinterpret_cast<const NiPoint3*>(&pkCamera->m_kWorldTranslate));
                pkNode->iState = bA ? 1 : 2;
            }
        }
    }
}

namespace fnv_00b5c490 {
extern NiRTTI g_011f5f1c_arg1;
struct AVObj_b5c490
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual AVObj_b5c490* IsSceneNode();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual AVObj_b5c490* IsGeometry();
    char pad04[0x1c];
    Bound* m_pBound;
    char pad24[0xc];
    unsigned int m_uiObjectFlags;
    char pad34[0x6c];
    AVObj_b5c490** m_ppObjects;
    unsigned short m_usMax;
    unsigned short m_usElementCount;
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*);
};
struct FUN_00b5aa40_self
{
    AVObj_b5c490* NiSwitchNode_GetActiveChild();
};
bool ShadowSceneNode_UpdateQueuedObjectLighting(AVObj_b5c490*, void*, void*, void*, void*);

// Recursively tests pObj and its children for a non-zero bound and no flag bit 1, calling FUN_00b5b260 on geometry children; returns false on early failure.
// @fnv 0x00b5c490
// src: COMMUNITY 0x00b5c490
bool ShadowSceneNode_UpdateQueuedObjectLighting_0(AVObj_b5c490* pObj, void* apArg2, void* apArg3, void* apArg4, void* apArg5)
{
    if (!pObj)
        return true;
    if (!pObj->m_pBound || pObj->m_pBound->radius == 0.0f || (pObj->m_uiObjectFlags & 1) || !pObj->IsSceneNode())
        return false;
    AVObj_b5c490* pNode = pObj->IsSceneNode();
    bool bResult = true;
    unsigned int i = 0;
    FUN_00b5aa40_self* pSwitch = pNode ? (FUN_00b5aa40_self*)((DynCastHelper*)pNode)->DynamicCast(&g_011f5f1c_arg1) : 0;
    if (pSwitch)
    {
        AVObj_b5c490* pChild = pSwitch->NiSwitchNode_GetActiveChild();
        if (pChild)
            bResult &= ShadowSceneNode_UpdateQueuedObjectLighting_0(pChild, apArg2, apArg3, apArg4, apArg5);
    }
    else
    {
        for (; i < pNode->m_usElementCount; i++)
        {
            AVObj_b5c490* pChild = pNode->m_ppObjects[i];
            if (pChild)
            {
                if (pChild->IsGeometry())
                    bResult &= ShadowSceneNode_UpdateQueuedObjectLighting(pChild, apArg2, apArg3, apArg4, apArg5);
                else
                    bResult &= ShadowSceneNode_UpdateQueuedObjectLighting_0(pChild, apArg2, apArg3, apArg4, apArg5);
            }
        }
    }
    return bResult;
}
}  // namespace fnv_00b5c490

struct Nd5;
struct AV5
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Nd5* IsSceneNode();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* IsGeom();
    char pad04[0x1c];
    Bound* pBound;
    char pad24[0xc];
    unsigned int flags;
};
struct Nd5 : AV5
{
    char pad34[0x6c];
    AV5** children;
    unsigned short maxSize;
    unsigned short count;
};
struct SW5
{
    AV5* NiSwitchNode_GetActiveChild();
};
struct DynCastHelper
{
    NiObject* DynamicCast(const void*);
};
extern const char* const g_011f5f1c_arg1;
bool ShadowSceneNode_UpdateQueuedObjectLightingList(AV5*, void*, void*, bool);
bool CheckBoundAndChildren(AV5* obj, void* a, void* b, bool c);

// @fnv 0x00b5c5c0
bool CheckBoundAndChildren(AV5* apObject, void* apArg1, void* apArg2, bool c)
{
    if (!apObject)
        return true;
    if (apObject->pBound && apObject->pBound->radius != 0.0f && !(apObject->flags & 1) && apObject->IsSceneNode())
    {
        Nd5* node = apObject->IsSceneNode();
        bool result = true;
        unsigned int i = 0;
        SW5* sw;
        if (node && (sw = (SW5*)((DynCastHelper*)node)->DynamicCast(&g_011f5f1c_arg1)) != 0)
        {
            AV5* child = sw->NiSwitchNode_GetActiveChild();
            if (child)
                result &= CheckBoundAndChildren(child, apArg1, apArg2, c);
        }
        else
        {
            for (; i < node->count; i++)
            {
                AV5* pChild = node->children[i];
                if (pChild)
                {
                    if (pChild->IsGeom())
                        result &= ShadowSceneNode_UpdateQueuedObjectLightingList(pChild, apArg1, apArg2, c);
                    else
                        result &= CheckBoundAndChildren(pChild, apArg1, apArg2, c);
                }
            }
        }
        return result;
    }
    return false;
}

inline void StrArr::SetAt(unsigned int uiIndex, char*& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != 0) m_usESize++;
    }
    else if (element != 0)
    {
        if (m_pBase[uiIndex] == 0) m_usESize++;
    }
    else if (m_pBase[uiIndex] != 0) m_usESize--;
    m_pBase[uiIndex] = element;
}
inline unsigned int StrArr::Add(char*& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize) SetSize(uiIndex + m_usGrowBy);
    (this->*static_cast<void (StrArr::*)(unsigned int, char*&)>(&StrArr::SetAt))(uiIndex, element);
    return uiIndex;
}

namespace fnv_00b5c7d0 {
struct FUN_00c51570_Class
{
    void* NiNode_GetViewerStrings(void*);
};
char* NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d490(const char*, unsigned short);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
extern const char* g_011f9e80;

struct LightNode
{
    LightNode* next;
    LightNode* prev;
    char* light;
};

// Local method adapters add no object storage to the shared node layout.
class ShadowSceneViewer : public ShadowSceneNode
{
  public:
    unsigned int CountLights() const { return lLightList.count; }
    static char* const& Next(LightNode*& pos)
    {
        char* const& light = pos->light;
        pos = pos->next;
        return light;
    }
    char* GetLightAt(unsigned short index) const
    {
        if (index >= lLightList.count)
            return 0;
        LightNode* pos = reinterpret_cast<LightNode*>(lLightList.head);
        char* light = Next(pos);
        for (unsigned int i = 0; i < index; i++)
            light = Next(pos);
        return light;
    }
    void AppendLightStats(StrArr* strings);
};
// @fnv 0x00b5c7d0
void ShadowSceneViewer::AppendLightStats(StrArr* pkStrings)
{
    reinterpret_cast<FUN_00c51570_Class*>(this)->NiNode_GetViewerStrings(pkStrings);
    char* s = NiViewerStrings_NiGetViewerString_Title(g_011f9e80);
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(s);
    s = NiGetViewerString_00a7d490("light count", CountLights());
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(s);
    int iShadowLightCount = 0;
    unsigned int ItemUpdateArray = CountLights();
    for (int i = 0; i < (unsigned short)ItemUpdateArray; i++)
    {
        if (GetLightAt((unsigned short)i)[0xec])
            iShadowLightCount++;
    }
    s = NiGetViewerString_00a7d4d0("shadow light count", iShadowLightCount);
    (pkStrings->*static_cast<unsigned int (StrArr::*)(char*&)>(&StrArr::Add))(s);
}
}  // namespace fnv_00b5c7d0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern int _fnv_particle_shader_renderer_level;
extern char DAT_011f91d8;

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

inline AutoMemContext::AutoMemContext(int newContext)
{
    m_eMemoryContext = (MEM_CONTEXT)g_tlsData.memContext;
    g_tlsData.memContext = newContext;
}
inline AutoMemContext::~AutoMemContext()
{
    g_tlsData.memContext = m_eMemoryContext;
}

struct TexturePtr
{
    BSRenderedTexture* m_pObject;
    void operator=(BSRenderedTexture* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject != 0)
            {
                NiRefObject* object = reinterpret_cast<NiRefObject*>(m_pObject);
                if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
                    object->DeleteThis();
            }
            m_pObject = p;
        }
    }
    operator BSRenderedTexture*() const
    {
        return m_pObject;
    }
};

// @fnv 0x00b9dcb0
void __fastcall SetShadowEnabled(ShadowSceneLight* light, int, bool bEnable)
{
    AutoMemContext memContext(0x20);

    int bShadows = 0;
    if ((!light->bCastShadow || bEnable) && _fnv_particle_shader_renderer_level >= 3)
        bShadows = (DAT_011f91d8 & 0x10) > 0;

    if (!(char)bShadows)
    {
        if (reinterpret_cast<TexturePtr&>(light->spDynamicShadowMap))
        {
            DAT_011f91a8->RemoveRenderedTexture(reinterpret_cast<TexturePtr&>(light->spDynamicShadowMap));
            reinterpret_cast<TexturePtr&>(light->spDynamicShadowMap) = 0;
        }
    }
    light->bCastShadow = bEnable;
}

namespace fnv_00b9dda0 {
extern "C"
{
    __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
}

extern const NiRTTI g_011f5ec4_arg1;
extern const NiRTTI g_011f5f6c;

// @fnv 0x00b9dda0
void __fastcall BindLight(ShadowSceneLight* self, int, NiLight* apLight)
{
    self->spLight = apLight;

    bool bKind1 = apLight && apLight->IsKindOfType(&g_011f5ec4_arg1);
    self->bPointLight = bKind1;
    if (bKind1)
    {
        if (self->bDynamicLight)
            memcpy(&self->bPointPosition, &apLight->m_kWorld.m_Translate, sizeof(self->bPointPosition));
    }
    else
    {
        self->fLODDimmer = 1.0f;
    }

    bool bKind2 = apLight && apLight->IsKindOfType(&g_011f5f6c);
    self->bAmbientLight = bKind2;
}
}  // namespace fnv_00b9dda0

typedef bool(__cdecl* FUN_00b5a930_pred)(void** item, void* ctx);

class FUN_00b5a930_cls
{
  public:
    unsigned int unk00;
    void** m_ppItems;
    unsigned int m_uiCount;
    int FindFirstMatch(void* ctx, unsigned int start, FUN_00b5a930_pred pred);
};

// Scans m_ppItems from start to m_uiCount, returning the first index whose item satisfies pred, or -1 if none match.
// @fnv 0x00b5a930
int FUN_00b5a930_cls::FindFirstMatch(void* apContext, unsigned int start, FUN_00b5a930_pred apPredicate)
{
    if (start < m_uiCount)
    {
        do
        {
            if (m_ppItems != 0)
            {
                if (apPredicate(&m_ppItems[start], apContext))
                {
                    return (int)start;
                }
            }
            ++start;
        } while (start < m_uiCount);
    }
    return -1;
}

// @fnv 0x00b5afc0
ShadowSceneLight* __fastcall FirstActiveShadowLight(ShadowSceneNode* self, int)
{
    ShadowListItem* node = self->lShadowLightList.head;
    reinterpret_cast<ShadowListItem* volatile&>(self->kShadowLightListIterator) = node;
    if (!node)
        return 0;
    ShadowListItem* next = node->next;
    reinterpret_cast<ShadowListItem* volatile&>(self->kShadowLightListIterator) = next;
    ShadowSceneLight* it = node->light;
    while (next)
    {
        if (it && it->spLight.m_pObject)
            break;
        node = reinterpret_cast<ShadowListItem* volatile&>(self->kShadowLightListIterator);
        next = node->next;
        reinterpret_cast<ShadowListItem* volatile&>(self->kShadowLightListIterator) = next;
        it = node->light;
    }
    return it;
}

// Advances the shadow-light iterator and returns the first light with an attached game light, or the last item.
// @fnv 0x00b5b010
ShadowSceneLight* __fastcall NextActiveShadowLight(ShadowSceneNode* self, int)
{
    ShadowSceneLight* item = 0;
    if (reinterpret_cast<ShadowListItem*&>(self->kShadowLightListIterator) != 0)
    {
        ShadowListItem* node = *(ShadowListItem* volatile*)&reinterpret_cast<ShadowListItem*&>(self->kShadowLightListIterator);
        reinterpret_cast<ShadowListItem*&>(self->kShadowLightListIterator) = node->next;
        item = node->light;
        while (reinterpret_cast<ShadowListItem*&>(self->kShadowLightListIterator) != 0)
        {
            if (item != 0 && item->spLight.m_pObject != 0)
                return item;
            node = *(ShadowListItem* volatile*)&reinterpret_cast<ShadowListItem*&>(self->kShadowLightListIterator);
            reinterpret_cast<ShadowListItem*&>(self->kShadowLightListIterator) = node->next;
            item = node->light;
        }
    }
    return item;
}

// Shared BSTextureManager does not yet declare this entry point.
extern void FUN_00b6d130();

struct LightNodeStandIn
{
    LightNodeStandIn* m_pkNext;
    LightNodeStandIn* m_pkPrev;
    ShadowSceneLight* m_val;
};

static inline ShadowSceneLight*& GetNextLightStandIn(LightNodeStandIn*& pkIter)
{
    ShadowSceneLight*& kVal = pkIter->m_val;
    pkIter = pkIter->m_pkNext;
    return kVal;
}

// @fnv 0x00b5b1f0
// src: COMMUNITY 0x00b5b1f0
void __fastcall ShadowSceneNode_ReleaseAllShadowMaps(ShadowSceneNode* pThis, int)
{
    LightNodeStandIn* pLightNode = (LightNodeStandIn*)pThis->lShadowLightList.head;
    while (pLightNode)
    {
        ShadowSceneLight* light = GetNextLightStandIn(pLightNode);
        if (light)
        {
            DAT_011f91a8->RemoveRenderedTexture(light->spDynamicShadowMap.m_pObject);
            BSRenderedTexture* pTexture = light->spDynamicShadowMap.m_pObject;
            if (pTexture)
            {
                if (InterlockedDecrement(reinterpret_cast<volatile long*>(&reinterpret_cast<NiRefObject*>(pTexture)->m_uiRefCount)) == 0)
                    reinterpret_cast<NiRefObject*>(pTexture)->DeleteThis();
                light->spDynamicShadowMap.m_pObject = 0;
            }
        }
    }
    reinterpret_cast<void (__thiscall*)(BSTextureManager*)>(&FUN_00b6d130)(DAT_011f91a8);
}

struct SearchNode
{
    SearchNode* next;
    SearchNode* previous;
    char* item;
};
struct SearchList
{
    void* unused00;
    void* unused04;
    SearchNode* first;
};
struct ProcessArgs
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};
struct SearchObject
{
    unsigned char CheckProcStateAndPlane(ProcessArgs args, char* target, char* item);
};

typedef unsigned char(__thiscall* TestCallback)(void*, char*);
// @fnv 0x00b5bbe0
void __fastcall ProcessTargetIfEligible(ShadowSceneNode* self, int, SearchObject* source, ProcessArgs args, char* target)
{
    char* subobject = *(char**)((char*)source + 0xac);
    void* object = *(void**)(subobject + 0xc);
    unsigned int type = *(unsigned int*)(target + 0x90);
    unsigned int state = *(unsigned int*)((char*)object + 8);
    if (type != 1 && type != 3 && state == 0 && *(unsigned short*)((char*)source + 0xa8) > (unsigned short)state)
    {
        unsigned char accepted = (*(TestCallback*)((char*)*(void**)object + 0x9c))(object, target + 0x2c);
        *(unsigned int*)(*(char**)(*(char**)((char*)source + 0xac) + 0xc) + 8) = (accepted == 0) + 1;
        if (accepted)
        {
            SearchList* list = reinterpret_cast<SearchList*>(self->pBSPortalGraph);
            if (list)
            {
                SearchNode* position = list->first;
                while (position)
                {
                    char** ppItem = &position->item;
                    position = position->next;
                    char* item = *ppItem;
                    if (item && *(unsigned int*)(item + 0x40) == 1)
                    {
                        if (!source->CheckProcStateAndPlane(args, target, item))
                            break;
                    }
                }
            }
        }
    }
}

struct NiRTTI_b5
{
    const char* m_pcName;
    const NiRTTI_b5* m_pBaseRTTI;
};

extern NiRTTI_b5 DAT_011f4a28;
extern NiRTTI_b5 DAT_011f4a98;

struct UpdData_b5
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bUpdateGeomorphs;
    bool m_bUpdateShadowSceneNode;
    bool m_bFlag;
    UpdData_b5()
    {
        m_fTime = 0.0f;
        m_bUpdate = false;
        m_bIsMultiThreaded = false;
        m_bUpdateGeomorphs = false;
        m_bUpdateShadowSceneNode = false;
        m_bFlag = false;
    }
};

struct Node_b5;

struct AV_b5
{
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI_b5* GetRTTI();
    virtual Node_b5* IsSceneNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    void Update(UpdData_b5& data);
    struct Cast_b5* DynamicCast(const NiRTTI_b5* rtti);
};

struct Cast_b5
{
    int unkPlaceholder;
};

struct Node_b5 : AV_b5
{
    AV_b5** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short GetArrayCount() const
    {
        return m_usSize;
    }
};

struct Geom_b5 : AV_b5
{
    int unka0;
    int unka4;
    unsigned int m_uiRevID;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    NiPoint3 m_kVec;
};

inline bool IsKindOf_b5(const NiRTTI_b5* pkRTTI, AV_b5* pkObj)
{
    const NiRTTI_b5* r = pkObj->GetRTTI();
    while (r)
    {
        if (r == pkRTTI)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}

void __fastcall CreateChildLight(ShadowSceneNode*, int, AV_b5*, bool);
// @fnv 0x00b5ca70
int __fastcall UpdateChildLights(ShadowSceneNode* self, int, Node_b5* node, float time)
{
    int count = 0;
    for (unsigned int i = 0; i < node->GetArrayCount(); i++)
    {
        AV_b5* child = node->m_pBase[i];
        if (!child)
            continue;
        Node_b5* sub = child->IsSceneNode();
        if (sub)
        {
            count += reinterpret_cast<int (__thiscall*)(ShadowSceneNode*, Node_b5*, float)>(&UpdateChildLights)(self, sub, time);
            continue;
        }
        AV_b5* obj = IsKindOf_b5(&DAT_011f4a28, child) ? child : 0;
        if (!obj)
            continue;
        reinterpret_cast<void (__thiscall*)(ShadowSceneNode*, AV_b5*, bool)>(&CreateChildLight)(self, obj, true);
        UpdData_b5 data;
        obj->Update(data);
        Geom_b5* g = (Geom_b5*)obj->DynamicCast(&DAT_011f4a98);
        if (g)
        {
            g->m_uiRevID++;
            g->m_kVec = NiPoint3(time, 0.0f, 0.0f);
        }
        count++;
    }
    return count;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    long m_refs;
    void AcquireReference()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRef()
    {
        if (InterlockedDecrement(&m_refs) == 0)
            DeleteThis();
    }
};

template <class T> struct RefPtr
{
    T* m_p;
    RefPtr& operator=(T* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRef();
            m_p = p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
    operator T*() const
    {
        return m_p;
    }
    T* operator->() const
    {
        return m_p;
    }
};

struct ShadowRenderTarget : RefObj
{
    ShadowRenderTarget(int a);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    RefPtr<RefObj> sp130;
    int unk134;
    int unk138;
    int unk13c;
};

struct UpdateData
{
    float fTime;
    bool b4;
    bool b5;
    bool b6;
    bool b7;
    bool b8;
    UpdateData(float t = 0.0f, bool a = false, bool b = false, bool c = false, bool d = false, bool e = false)
        : fTime(t), b4(a), b5(b), b6(c), b7(d), b8(e)
    {}
};

struct AVObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int m_uiObjectFlags;
    void Update(UpdateData& data);
};

struct LightNode
{
    LightNode* m_pNext;
    LightNode* m_pListObject;
    ShadowSceneLight* m_pInventoryEntryData;
};

inline ShadowSceneLight* const& GetNext(LightNode*& pos)
{
    ShadowSceneLight* const& item = pos->m_pInventoryEntryData;
    pos = pos->m_pNext;
    return item;
}

struct RenderHelper
{
    int unk00;
    void SetTarget(int a, int b);
};
extern RenderHelper g_renderHelper;
extern ShadowSceneLight* g_pCurrentShadowLight;

void __fastcall RenderSceneLight(ShadowSceneLight*, int, int, int);
// @fnv 0x00b5b880
void __fastcall RenderShadowLights(ShadowSceneNode* self, int, int arg)
{
    AutoMemContext ctx(0x20);
    if (!reinterpret_cast<RefPtr<ShadowRenderTarget>&>(self->spCubeMapCamera))
    {
        reinterpret_cast<RefPtr<ShadowRenderTarget>&>(self->spCubeMapCamera) = new ShadowRenderTarget(0);
    }
    reinterpret_cast<RefPtr<ShadowRenderTarget>&>(self->spCubeMapCamera)->unk114 = 0;
    if (self->lShadowLightList.count)
    {
        int n = 0;
        LightNode* pos = reinterpret_cast<LightNode*>(self->lShadowLightList.head);
        while (pos)
        {
            ShadowSceneLight* light = GetNext(pos);
            if (light && reinterpret_cast<AVObj*>(light->spLight.m_pObject))
            {
                if (!(reinterpret_cast<AVObj*>(light->spLight.m_pObject)->m_uiObjectFlags & 1))
                {
                    UpdateData data;
                    reinterpret_cast<AVObj*>(light->spLight.m_pObject)->Update(data);
                    if (light->usFrustumCull != 0xff)
                    {
                        g_pCurrentShadowLight = light;
                        reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, int, int)>(&RenderSceneLight)(light, arg, n);
                        n++;
                    }
                }
                else
                {
                    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*)>(&ResetSceneLight)(light);
                }
            }
        }
        for (int i = n + 0x11; i < 0x15; i++)
            g_renderHelper.SetTarget(1, i);
    }
    reinterpret_cast<RefPtr<ShadowRenderTarget>&>(self->spCubeMapCamera)->sp130 = 0;
}

struct SPData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int iCount;
};

struct SPPropData
{
    int unk00;
    int unk04;
    int iType;
};

struct SPProperty
{
    int unk00;
    int unk04;
    int unk08;
    SPPropData* pData;
};

struct SPRenderer
{
    void Begin(int aiPass);
    void BeginPair();
    void EndPair();
    void AddData(SPData* apData);
    void Flush();
    void End();
};

struct SPGeometry
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    SPProperty* pProperty;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    SPData* m_pSPData;
};

struct SPOwnerGeom
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    SPRenderer* pRenderer;
};

struct SPPass
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    SPGeometry* pGeomA;
    SPGeometry* pGeomB;
    SPOwnerGeom* pOwner;
};

// @fnv 0x00b5ba80
void __fastcall SetShadowPassData(ShadowSceneNode* self, int, int aiPass, SPPass* apPass)
{
    SPRenderer* pRenderer = apPass->pOwner->pRenderer;
    SPGeometry* pGeomA = apPass->pGeomA;
    SPGeometry* pGeomB = apPass->pGeomB;

    bool bEnabledA = pGeomA ? pGeomA->pProperty->pData->iType == 1 : self->bVisibleUnboundSpace;
    bool bEnabledB = pGeomB ? pGeomB->pProperty->pData->iType == 1 : self->bVisibleUnboundSpace;
    bool bUseA = pGeomA ? (bEnabledA && pGeomA->m_pSPData) : reinterpret_cast<SPData&>(self->kCompoundFrustum).iCount == 0;
    bool bUseB = pGeomB ? (bEnabledB && pGeomB->m_pSPData) : reinterpret_cast<SPData&>(self->kCompoundFrustum).iCount == 0;
    SPData* pDataA = pGeomA ? pGeomA->m_pSPData : &reinterpret_cast<SPData&>(self->kCompoundFrustum);
    SPData* pDataB = pGeomB ? pGeomB->m_pSPData : &reinterpret_cast<SPData&>(self->kCompoundFrustum);

    pRenderer->Begin(aiPass);
    if (bEnabledA && !pDataA->iCount)
        return;
    if (bEnabledB && !pDataB->iCount)
        return;

    if (bUseA && !bUseB)
    {
        pRenderer->AddData(pDataA);
    }
    else if (!bUseA && bUseB)
    {
        pRenderer->AddData(pDataB);
    }
    else if (bUseA && bUseB)
    {
        pRenderer->BeginPair();
        pRenderer->AddData(pDataA);
        pRenderer->AddData(pDataB);
        pRenderer->EndPair();
    }
    pRenderer->Flush();
    pRenderer->End();
}

struct BoundRef_t
{
    void* m_pObject;
};

struct BoundList_t
{
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
    void AddTail(const BoundRef_t& kBound);
};

struct GlobalLock_t
{
    unsigned int m_uiThread;
    unsigned int m_uiCount;
    void Lock(const char* pcName);
    void Unlock()
    {
        if (--m_uiCount == 0)
            m_uiThread = 0;
    }
};
extern GlobalLock_t DAT_011f9ea0;

// If pkBound has an object and m_b1FC is set, locks DAT_011f9ea0, appends pkBound to m_kBounds, then unlocks.
// @fnv 0x00b5cff0
void __fastcall QueueLightRemoval(ShadowSceneNode* self, int, BoundRef_t* pkBound)
{
    if (!pkBound->m_pObject)
        return;
    if (!self->bAllowLightRemoveQueues)
        return;
    DAT_011f9ea0.Lock(0);
    reinterpret_cast<BoundList_t*>(&self->lLightQueueRemove)->AddTail(*pkBound);
    DAT_011f9ea0.Unlock();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

NiTListItem<NiPointer<ShadowSceneLight> >* __cdecl NewListItemB5D(ShadowSceneLight* pkObject);

template <class TAlloc, class T> __declspec(noinline) void NiTPointerListBase<TAlloc, T>::AddTail(const T& element)
{
    NiTListItem<T>* pkItem = NewListItemB5D(element.m_pObject);
    pkItem->m_pkNext = 0;
    pkItem->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = pkItem;
    else
        m_pkHead = pkItem;
    m_pkTail = pkItem;
    m_kItemCount.m_uiCount++;
}

class CriticalLockB5D
{
  public:
    void Lock(const char* pcName);
    void Unlock()
    {
        if (--m_uiLockCount == 0)
            m_uiOwner = 0;
    }

    unsigned int m_uiOwner;
    unsigned int m_uiLockCount;
};

extern CriticalLockB5D g_kMultiBoundLockB5D;

void __fastcall RefreshShadowLights(ShadowSceneNode*, int);
// @fnv 0x00b5d180
// src: XBOX_PDB 0x00b5d180
void ShadowSceneNode::RemoveAllLights()
{
    void* pkPos = reinterpret_cast<NiTPointerList<NiPointer<ShadowSceneLight> >&>(lLightList).m_pkHead;
    while (pkPos)
    {
        ShadowSceneLight* pkBound = reinterpret_cast<NiTPointerList<NiPointer<ShadowSceneLight> >&>(lLightList).GetNext(pkPos).m_pObject;
        if (pkBound)
        {
            NiPointer<ShadowSceneLight> pMultiBound(pkBound);
            if (bAllowLightRemoveQueues)
            {
                g_kMultiBoundLockB5D.Lock(0);
                reinterpret_cast<NiTPointerList<NiPointer<ShadowSceneLight> >&>(lLightQueueRemove).AddTail(pMultiBound);
                g_kMultiBoundLockB5D.Unlock();
            }
        }
    }
    reinterpret_cast<void (__thiscall*)(ShadowSceneNode*)>(&RefreshShadowLights)(this);
    reinterpret_cast<NiTPointerList<NiPointer<ShadowSceneLight> >&>(lShadowLightList).RemoveAll();
    kShadowLightActiveFence = 0;
    kShadowLightFadingInFence = 0;
    reinterpret_cast<void (__thiscall*)(ShadowSceneNode*)>(&RefreshShadowLights)(this);
}

struct Obj_b5d270
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39(void* apOwner);
    long m_lRefCount;
    unsigned int unkValue;
    unsigned int m_uiKey;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};

struct ObjPtr_b5d270
{
    Obj_b5d270* m_pObject;
    ObjPtr_b5d270(Obj_b5d270* pObject)
    {
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~ObjPtr_b5d270()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    ObjPtr_b5d270& operator=(const ObjPtr_b5d270& kPtr)
    {
        if (m_pObject != kPtr.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = kPtr.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    Obj_b5d270* operator->() const
    {
        return m_pObject;
    }
};

typedef NiTListItem<ObjPtr_b5d270 > Node_b5d270;

struct Alloc_b5d270
{

    void* NiGeometry_AddProperty();
};

typedef NiTPointerListBase<Alloc_b5d270, ObjPtr_b5d270 > List_b5d270;
template <> inline void NiTPointerListBase<Alloc_b5d270, ObjPtr_b5d270 >::AddTail(const ObjPtr_b5d270& element)
{
        Node_b5d270* pkNode = (Node_b5d270*)m_kItemCount.NiGeometry_AddProperty();
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_kItemCount.m_uiCount++;
        m_pkTail = pkNode;
    }

// If pObj is non-null, appends it to m_kList via AddTail.
// @fnv 0x00b5d270
void __fastcall RemoveLightObjects(ShadowSceneNode* self, int, ShadowSceneLight* light)
{
    Obj_b5d270* pObj = reinterpret_cast<Obj_b5d270*>(light);
    if (pObj)
        reinterpret_cast<List_b5d270*>(&self->lLightQueueUpdate)->AddTail(pObj);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern NiPoint3 DAT_011f426c;

struct Ref
{
    virtual void first();
    virtual void DeleteThis();
    long refs;
    void Dec()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <class T> struct Ptr
{
    T* p;
    Ptr() : p(0)
    {}
    ~Ptr()
    {
        if (p)
            p->Dec();
    }
    void operator=(T* q)
    {
        if (p != q)
        {
            if (p)
                p->Dec();
            p = q;
            if (q)
                InterlockedIncrement(&q->refs);
        }
    }
    T* operator->()
    {
        return p;
    }
};

struct Base
{
    Bound* EnsureBound();
    void SetRadius(float);
    Base(unsigned);
    virtual ~Base();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void SetObjectBound(void*);
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    Bound* bound;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned flags;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    void AssignFixedString(const struct Fixed&);
};
struct StringTable
{
    static char* AddString(const char*);
};
extern char* DAT_0109b220;
struct Fixed
{
    char* text;
    Fixed(const char* s) : text(StringTable::AddString(s))
    {}
    __forceinline ~Fixed()
    {
        if (text != DAT_0109b220)
            InterlockedDecrement((volatile long*)(text - 8));
    }
};
struct Alloc
{
    static void* operator new(unsigned);
    static void operator delete(void*);
};

struct Fog : Ref, Alloc
{
    Fog();
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    NiPoint3 color;
    float near1, far1, near2, far2;
    void SetRange1(float v)
    {
        near1 = v;
        far1 = v;
    }
    void SetRange2(float v)
    {
        near2 = v;
        far2 = v;
    }
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    NiPoint3 color2;
    unsigned unk060;
};
struct Manager
{
    void* Allocate(unsigned);
};
extern Manager _g_memoryManager;
inline Bound* Base::EnsureBound()
{
    if (!bound)
    {
        void* allocation = _g_memoryManager.Allocate(16);
        SetObjectBound(allocation);
        Bound* b = bound;
        *reinterpret_cast<NiPoint3*>(&b->x) = DAT_011f426c;
        b->radius = 0;
    }
    return bound;
}
inline void Base::SetRadius(float r)
{
    bound->radius = r;
}

// @fnv 0x00b5e0f0
ShadowSceneNode::ShadowSceneNode() : NiNode(0)
{
    reinterpret_cast<Base*>(this)->AssignFixedString(Fixed("shadow scene node"));
    lLightList.RemoveAll();
    lShadowLightList.RemoveAll();
    pWindowReflectionEnvMap = (NiRefObject*)0;
    iCurrentCubeMapFace = 0;
    bDisableLightUpdate = false;
    bVisibleUnboundSpace = true;
    *reinterpret_cast<NiPoint3*>(&kEyePosition) = DAT_011f426c;
    pBSPortalGraph = 0;
    kShadowLightActiveFenceObject = new ShadowSceneLight;
    kShadowLightFadingInFenceObject = new ShadowSceneLight;
    kShadowLightActiveFence = 0;
    kShadowLightFadingInFence = 0;
    NiDirectionalLight* light = new NiDirectionalLight;
    light->SetAmbientColor(DAT_011f4998);
    light->SetDiffuseColor(DAT_011f4998);
    pSunLight = new ShadowSceneLight;
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, NiLight*)>(&fnv_00b9dda0::BindLight)(pSunLight, light);
    m_uFlags |= 0x800;
    reinterpret_cast<Base*>(this)->EnsureBound()->radius = 1;
    m_uFlags |= 0x2000;
    bWireframe = false;
    *reinterpret_cast<NiPoint3*>(&kLightingOffset) = DAT_011f426c;
    bAllowLightRemoveQueues = true;
    Ptr<Fog>& fog = reinterpret_cast<Ptr<Fog>&>(spFog);
    fog = new Fog;
    fog->SetRange1(500000.0f);
    fog->SetRange2(500000.0f);
    fog->color = NiPoint3(0.5f, 0.5f, 0.5f);
    fog->color2 = NiPoint3(0.5f, 0.5f, 0.5f);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

void __cdecl ReleaseBoundB5E(ShadowSceneLight* pkBound);

// Queues removal of the first shadow light attached to the requested scene object.
class ShadowSceneLightRemoval : public ShadowSceneNode
{
  public:
    __declspec(noinline) void RemoveBound(const NiPointer<ShadowSceneLight>& light)
    {
        ReleaseBoundB5E(light.m_pObject);
        reinterpret_cast<unsigned int&>(kShadowLightListIterator)++;
    }
};
// @fnv 0x00b5edf0
void __fastcall RemoveLightByOwner(ShadowSceneNode* self, int, void* pvOwner)
{
    if (!pvOwner)
        return;
    void* pkPos = reinterpret_cast<NiTPointerList<NiPointer<ShadowSceneLight> >&>(self->lShadowLightList).m_pkHead;
    while (pkPos)
    {
        ShadowSceneLight* pkBound = reinterpret_cast<NiTPointerList<NiPointer<ShadowSceneLight> >&>(self->lShadowLightList).GetNext(pkPos).m_pObject;
        if (pkBound && pkBound->spShadowScene.m_pObject == pvOwner)
        {
            static_cast<ShadowSceneLightRemoval*>(self)->RemoveBound(pkBound);
            return;
        }
    }
}

static __forceinline hkMemoryAllocator& RouterHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}
hkMemoryRouter& hkMemoryRouter_getInstance();
__forceinline void* __cdecl hkReferencedObject::operator new(std::size_t amount)
{
    void* result = RouterHeap(hkMemoryRouter_getInstance()).blockAlloc(amount);
    static_cast<hkReferencedObject*>(result)->m_usMemSizeAndFlags = (unsigned short)amount;
    return result;
}

struct InterfacePart
{
    virtual void f0();
};
struct InterfaceArray;
void ResizeAudioStream(void*, void*, int);
struct InterfaceArray
{
    InterfacePart** data;
    int size;
    int capacity;
    __forceinline InterfaceArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~InterfaceArray()
    {
        hkMemoryAllocator* heap = &RouterHeap(hkMemoryRouter_getInstance());
        size = 0;
        if ((capacity & 0x80000000u) == 0)
            heap->bufFree(data, (capacity & 0x3fffffff) * 4);
    }
    __forceinline void AddBack(InterfacePart* value)
    {
        hkMemoryAllocator* heap = &RouterHeap(hkMemoryRouter_getInstance());
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(heap, this, 4);
        data[size++] = value;
    }
};
struct WorldContext : hkReferencedObject, InterfacePart
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    WorldContext();
    void SetWorld(void*);
};
struct Process : hkReferencedObject
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    Process(InterfaceArray&, int);
    void SetValue(int);
};
void hkpPhysicsContext_registerAllPhysicsProcesses();
struct Root
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void* GetWorld();
    int unk04, unk08, unk0c;
    Process* process;
    void SetProcessEnabled(bool);
};
// Creates and stores a Process with a WorldContext when enable is true, or releases and clears process when false.
// @fnv 0x00c6a640
void Root::SetProcessEnabled(bool enable)
{
    AutoMemContext context(16);
    if (enable)
    {
        if (!process)
        {
            InterfaceArray array;
            hkpPhysicsContext_registerAllPhysicsProcesses();
            WorldContext* item = new WorldContext;
            item->SetWorld(GetWorld());
            array.AddBack(item);
            process = new Process(array, 0);
            process->SetValue(0x61a9);
        }
    }
    else
    {
        if (process)
        {
            GetWorld();
            process->removeReference();
            process = 0;
        }
    }
}

class LightingElem;

class LightingElem
{
  public:
    void ShadowSceneLight_RemoveTriGeom(void* arg1, int arg2);
};

struct FUN_00b5b0e0_Inner
{
    int unk9C;
    int unkA0;
    int unkA4;
    BSShaderLightingProperty* m_pProp;
};

struct FUN_00b5b0e0_Scene
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    FUN_00b5b0e0_Inner m_kInner;
};

// Validates the prop's shader type and iterates its lighting elements, calling FUN_00ba01a0 on each with pv and 0.
// @fnv 0x00b5b0e0
// src: COMMUNITY 0x00b5b0e0
void __cdecl ShadowSceneNode_RemoveLightsFromGeom(void* pv)
{
    FUN_00b5b0e0_Scene* pObj = (FUN_00b5b0e0_Scene*)pv;
    if (!pObj)
        return;
    FUN_00b5b0e0_Inner* pInner = &pObj->m_kInner;
    BSShaderLightingProperty* pProp = pInner ? pInner->m_pProp : 0;
    if (!pProp)
        pProp = pObj->m_kInner.m_pProp;
    int bValidShader = pProp == 0 ? 0 : (int)((unsigned int)(pProp->iShaderPropertyType - 1) <= 11);
    BSShaderLightingProperty* pValidProp = bValidShader ? pProp : 0;
    if (pValidProp)
    {
        void* pos;
        LightingElem* pElem;
        while ((pElem = reinterpret_cast<LightingElem*>(pValidProp->GetFirstAttachedLight(pos))) != 0)
            pElem->ShadowSceneLight_RemoveTriGeom(pv, 0);
    }
}

namespace fnv_00b5d040 {
struct RefPtr_b9fcc0
{
    NiObject* m_pObject;
    ~RefPtr_b9fcc0()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
        }
    }
};

struct List_b9fcc0
{
    int head;
    int tail;
    unsigned int count;
    RefPtr_b9fcc0 Remove(void* object);
};

int __cdecl Object_ComputeValue_00b5a980(int*, int*);

struct Container_b5a
{
    void* vtable;
    void** data;
    unsigned int count;
    unsigned int capacity;
    int Find(void* object, int zero, int(__cdecl* callback)(int*, int*));
    void RemoveAt(unsigned int index, bool a2);
};

struct Item1
{
    int item1_00;
    int item1_04;
    int item1_08;
    int item1_0C;
    int item1_10;
    int item1_14;
    int item1_18;
    int item1_1C;
    int item1_20;
    int item1_24;
    int item1_28;
    int item1_2C;
    int item1_30;
    int item1_34;
    int item1_38;
    int item1_3C;
    int item1_40;
    int item1_44;
    int item1_48;
    int item1_4C;
    int item1_50;
    int item1_54;
    int item1_58;
    int item1_5C;
    int item1_60;
    int item1_64;
    int item1_68;
    int item1_6C;
    int item1_70;
    int item1_74;
    int item1_78;
    int item1_7C;
    int item1_80;
    int item1_84;
    int item1_88;
    int item1_8C;
    int item1_90;
    int item1_94;
    int item1_98;
    int item1_9C;
    int item1_A0;
    int item1_A4;
    int item1_A8;
    int item1_AC;
    int item1_B0;
    int item1_B4;
    int item1_B8;
    int item1_BC;
    int item1_C0;
    int item1_C4;
    int item1_C8;
    int item1_CC;
    int item1_D0;
    int item1_D4;
    int item1_D8;
    Container_b5a container;
};

struct SubItem
{
    int sub_00;
    int sub_04;
    int sub_08;
    int sub_0C;
    int sub_10;
    int sub_14;
    int sub_18;
    int sub_1C;
    int sub_20;
    int sub_24;
    int sub_28;
    int sub_2C;
    int sub_30;
    int sub_34;
    int sub_38;
    int sub_3C;
    int sub_40;
    int sub_44;
    int sub_48;
    int sub_4C;
    int sub_50;
    int sub_54;
    int sub_58;
    int sub_5C;
    int sub_60;
    int sub_64;
    int sub_68;
    int sub_6C;
    int sub_70;
    int sub_74;
    int sub_78;
    int sub_7C;
    int sub_80;
    int sub_84;
    int sub_88;
    int sub_8C;
    int sub_90;
    int sub_94;
    int sub_98;
    int sub_9C;
    int sub_A0;
    int sub_A4;
    int sub_A8;
    int sub_AC;
    Container_b5a container;
};

struct Item2
{
    int item2_00;
    int item2_04;
    int item2_08;
    int item2_0C;
    int item2_10;
    int item2_14;
    int item2_18;
    int item2_1C;
    int item2_20;
    int item2_24;
    int item2_28;
    int item2_2C;
    int item2_30;
    int item2_34;
    int item2_38;
    int item2_3C;
    int item2_40;
    int item2_44;
    int item2_48;
    int item2_4C;
    int item2_50;
    int item2_54;
    int item2_58;
    int item2_5C;
    int item2_60;
    int item2_64;
    int item2_68;
    int item2_6C;
    int item2_70;
    int item2_74;
    int item2_78;
    int item2_7C;
    int item2_80;
    int item2_84;
    int item2_88;
    int item2_8C;
    int item2_90;
    int item2_94;
    int item2_98;
    int item2_9C;
    int item2_A0;
    int item2_A4;
    int item2_A8;
    int item2_AC;
    int item2_B0;
    int item2_B4;
    int item2_B8;
    int item2_BC;
    int item2_C0;
    int item2_C4;
    int item2_C8;
    int item2_CC;
    int item2_D0;
    int item2_D4;
    int item2_D8;
    int item2_DC;
    int item2_E0;
    int item2_E4;
    int item2_E8;
    int item2_EC;
    int item2_F0;
    int item2_F4;
    int item2_F8;
    int item2_FC;
    int item2_100;
    SubItem* subItem;
};

struct AmbientLight
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
};

// @fnv 0x00b5d040
void __fastcall RemoveLightFromNode(ShadowSceneNode* self, int, void** object, void* apLight)
{

    if (reinterpret_cast<AmbientLight*>(self->pBSPortalGraph) && reinterpret_cast<AmbientLight*>(self->pBSPortalGraph)->unk28)
    {
        ShadowSceneLight* node = (ShadowSceneLight*)*object;
        for (unsigned int i = 0; i < node->kMultiboundRooms.iSize; ++i)
        {
            Item1* item = reinterpret_cast<Item1**>(node->kMultiboundRooms.pBuffer)[i];
            if (item && item->container.count)
            {
                int index = item->container.Find(object, 0, &Object_ComputeValue_00b5a980);
                if (index != -1)
                    item->container.RemoveAt(index, true);
            }
            node = (ShadowSceneLight*)*object;
        }
        node = (ShadowSceneLight*)*object;
        for (unsigned int i = 0; i < node->kPortals.iSize; ++i)
        {
            Item2* item = reinterpret_cast<Item2**>(node->kPortals.pBuffer)[i];
            if (item)
            {
                SubItem* sub = item->subItem;
                if (sub->container.count)
                {
                    Container_b5a* c = &sub->container;
                    unsigned int count = c->count;
                    int index = -1;
                    for (unsigned int j = 0; j < count; ++j)
                    {
                        if (c->data && c->data[j] == (void*)node)
                        {
                            index = j;
                            break;
                        }
                    }
                    if (index != -1)
                        c->RemoveAt(index, true);
                }
            }
            node = (ShadowSceneLight*)*object;
        }
    }
    ShadowSceneLight* node = (ShadowSceneLight*)*object;
    if (node->bCastShadow)
        reinterpret_cast<List_b9fcc0*>(&self->lShadowLightList)->Remove(apLight);
    else
        reinterpret_cast<List_b9fcc0*>(&self->lLightList)->Remove(apLight);
}
}  // namespace fnv_00b5d040

void FUN_00e74d40();

// @fnv 0x00b5c7c0
// src: GUESS 0x00b5c7c0 (confidence: low)
void Object_ForwardCall_00b5c7c0()
{
    FUN_00e74d40();
}

extern unsigned int DAT_010a2720;
struct FUN_00aa54a0_s
{
    void* Allocate(unsigned int size, unsigned int extra);
    void* Allocate(unsigned int size)
    {
        return Allocate(size, DAT_010a2720);
    }
    void Deallocate(void* p);
};
struct MemMgr5
{
    FUN_00aa54a0_s* GetCtx();
};
extern "C" char DAT_011f6238;
extern "C" char DAT_011f4288;
extern "C" char DAT_01202828;
extern "C" char DAT_012030b8;
int __cdecl CompareFloatAtOffsetC(const void* a, const void* b);
void __cdecl FUN_00ec6f20(void* base, int count, int size, int(__cdecl* cmp)(const void*, const void*));

struct Obj5;
template <class T> struct S5_LArr
{
    void** m_ppVirtualMethodTable;
    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int GetAllocatedSize() const
    {
        return m_uiMaxSize;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};

template <class T> struct S5_List
{
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
    unsigned int GetSize() const
    {
        return m_uiCount;
    }
    NiTListItem<T>* GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListItem<T>*& pos) const
    {
        T& e = pos->m_element;
        pos = pos->m_pkNext;
        return e;
    }
};

struct Obj5
{
    virtual void v0();
    virtual void v1();
    virtual const void* GetRtti();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int Predicate();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Obj5* child;
    int unk1c;
    Bound* bound;
};
class SceneLightBounds : public ShadowSceneLight
{
  public:
    int GetKey() const { return reinterpret_cast<int>(spLight.m_pObject); }
    bool TestBound(Bound*, int, float);
    float Accum(Bound*);
};
struct S5_A
{
    void** vt;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    S5_LArr<SceneLightBounds*> children;
};
struct S5_B
{
    void** vt;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    S5_LArr<SceneLightBounds*> children;
};

void __cdecl ShadowSceneNode_UpdateQueuedObjectLighting(Obj5* obj, ShadowSceneNode* a2, bool a3, S5_A* pA, S5_B* pB);
void __cdecl ShadowSceneNode_UpdateQueuedObjectLighting_0(Obj5* obj, ShadowSceneNode* a2, bool a3, S5_A* pA, S5_B* pB);
bool __cdecl CheckBoundAndChildren(Obj5* obj, ShadowSceneNode* a2, SceneLightBounds** b, bool c);

// With flag set, filters child candidates by the object's bound, sorts matches, and calls CheckBoundAndChildren; otherwise dispatches based on Predicate().
// @fnv 0x00b5dac0
// src: XBOX_PDB 0x00b5dac0
bool __cdecl ShadowSceneNode_UpdateQueuedObjectLightingStart(Obj5* obj, ShadowSceneNode* apList, bool a3, bool abTestBound)
{
    if (obj == 0)
        return true;
    S5_A* pA = 0;
    S5_B* pB = 0;
    Obj5* a = obj->child;
    if (a != 0)
    {
        bool bIsTypeA = a->GetRtti() == (const void*)&DAT_01202828;
        if (bIsTypeA)
        {
            pA = (S5_A*)a;
        }
        bool bIsTypeB = false;
        if (!bIsTypeA)
        {
            bIsTypeB = a->GetRtti() == (const void*)&DAT_012030b8;
        }
        if (bIsTypeB)
        {
            pB = (S5_B*)a;
        }
    }
    if (abTestBound)
    {
        FUN_00aa54a0_s* ctx = ((MemMgr5*)&DAT_011f6238)->GetCtx();
        int count = 0;
        Bound* pBound = obj->bound;
        Bound bound = *(pBound ? pBound : (Bound*)&DAT_011f4288);
        SceneLightBounds** out;
        if (pA != 0)
        {
            out = (SceneLightBounds**)ctx->Allocate((pA->children.GetAllocatedSize() + 1) * sizeof(SceneLightBounds*));
            for (unsigned int i = 0; i < pA->children.GetAllocatedSize(); i++)
            {
                SceneLightBounds* it = pA->children.GetAt(i);
                if (it == 0)
                    continue;
                if (a3 && it->usFrustumCull == 0xff)
                    continue;
                if (it->TestBound(&bound, it->GetKey(), 1.0f))
                {
                    out[count] = it;
                    count++;
                    it->Accum(&bound);
                }
            }
        }
        else if (pB != 0)
        {
            out = (SceneLightBounds**)ctx->Allocate((pB->children.GetAllocatedSize() + 1) * sizeof(SceneLightBounds*));
            for (unsigned int i = 0; i < pB->children.GetAllocatedSize(); i++)
            {
                SceneLightBounds* it = pB->children.GetAt(i);
                if (it == 0)
                    continue;
                if (a3 && it->usFrustumCull == 0xff)
                    continue;
                if (it->TestBound(&bound, it->GetKey(), 1.0f))
                {
                    out[count] = it;
                    count++;
                    it->Accum(&bound);
                }
            }
        }
        else
        {
            out = (SceneLightBounds**)ctx->Allocate((reinterpret_cast<S5_List<SceneLightBounds*>&>(apList->lLightList).GetSize() + 1) * sizeof(SceneLightBounds*));
            NiTListItem<SceneLightBounds*>* pos = reinterpret_cast<S5_List<SceneLightBounds*>&>(apList->lLightList).GetHeadPos();
            while (pos)
            {
                SceneLightBounds* it = reinterpret_cast<S5_List<SceneLightBounds*>&>(apList->lLightList).GetNext(pos);
                if (it == 0)
                    continue;
                if (a3 && it->usFrustumCull == 0xff)
                    continue;
                if (it->TestBound(&bound, it->GetKey(), 1.0f))
                {
                    out[count] = it;
                    count++;
                    it->Accum(&bound);
                }
            }
        }
        if (count > 0)
            FUN_00ec6f20(out, count, 4, CompareFloatAtOffsetC);
        out[count] = 0;
        CheckBoundAndChildren(obj, apList, out, a3);
        ctx->Deallocate(out);
        return true;
    }
    else
    {
        if (obj->Predicate())
            ShadowSceneNode_UpdateQueuedObjectLighting(obj, apList, a3, pA, pB);
        else
            ShadowSceneNode_UpdateQueuedObjectLighting_0(obj, apList, a3, pA, pB);
        return true;
    }
}

namespace fnv_00b5ddf0 {
extern "C" void _ReadWriteBarrier();
struct ArrOps
{
    void BSSimpleArray_ShadowSceneLight_1024_MoveItems(unsigned*, unsigned*, unsigned);
};

struct LocalLock
{
    unsigned owner, count;
    void BSSpinLock_Lock(char*);
    void unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern "C" LocalLock DAT_011f9ea0, DAT_011f9ec0;
struct LocalArray
{
    virtual void v0();
    virtual void** Allocate(unsigned);
    virtual void Free(void**);
    void** data;
    unsigned count, capacity;
    void BSSimpleArray_ShadowSceneLight_1024_Remove(unsigned, bool);
    void clear()
    {
        if (data)
        {
            Free(data);
            data = 0;
            capacity = 0;
            count = 0;
        }
    }
    unsigned find(void* p)
    {
        for (unsigned i = 0; i < count; i++)
            if (data && data[i] == p)
                return i;
        return ~0u;
    }
    __forceinline void remove(unsigned i)
    {
        if (i == ~0u)
            return;
        unsigned n = count;
        if (capacity > 1024)
        {
            if (n <= capacity - 2048)
                goto slow;
        }
        else
        {
            if (n <= capacity / 4)
                goto slow;
        }
        _ReadWriteBarrier();
        ((ArrOps*)this)->BSSimpleArray_ShadowSceneLight_1024_MoveItems((unsigned*)(data + i), (unsigned*)(data + i + 1), n - i - 1);
    done:
        --count;
        return;
    slow:
        unsigned cap = capacity > 2048 ? capacity - 1024 : capacity / 2;
        void** fresh = Allocate(cap);
        ((ArrOps*)this)->BSSimpleArray_ShadowSceneLight_1024_MoveItems((unsigned*)fresh, (unsigned*)data, i);
        ((ArrOps*)this)->BSSimpleArray_ShadowSceneLight_1024_MoveItems((unsigned*)(fresh + i), (unsigned*)(data + i + 1), count - 1);
        Free(data);
        data = fresh;
        capacity = cap;
        goto done;
    }
};
template <class T> struct LocalLink
{
    LocalLink* next;
    LocalLink* prev;
    T* item;
};
template <class T> T* const& nextItem(LocalLink<T>*& p)
{
    T* const& item = p->item;
    p = p->next;
    return item;
}
struct LocalObject
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
    LocalArray geometryLinks;
    LocalArray lightLinks;
};
struct LocalLightData
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
    LocalArray objects;
};

struct LocalLight
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
    LocalLightData* data;
};
struct LocalGeometry
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
    LocalLink<LocalLight>* lights;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    LocalArray objects;
};
struct LocalContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    LocalLink<LocalGeometry>* geometries;
};

// When the context changes, clears five lists, removes geometry and light references from old-context objects, then stores the new context.
// @fnv 0x00b5ddf0
void __fastcall SetPortalGraph(ShadowSceneNode* self, int, LocalContext* apContext)
{
    if (apContext != reinterpret_cast<LocalContext*&>(self->pBSPortalGraph))
    {
        DAT_011f9ea0.BSSpinLock_Lock(0);
        DAT_011f9ec0.BSSpinLock_Lock(0);
        self->bAllowLightRemoveQueues = false;
        RemoveShadowList(&self->lLightQueueAdd);
        RemoveShadowList(&self->lLightQueueRemove);
        RemoveShadowList(&self->lLightQueueUpdate);
        RemoveShadowList(&self->lObjectQueueUpdate);
        RemoveShadowList(&self->lObjectQueueUpdateActiveOnly);
        if (reinterpret_cast<LocalContext*&>(self->pBSPortalGraph))
        {
            LocalLink<LocalGeometry>* geometryPos = reinterpret_cast<LocalContext*&>(self->pBSPortalGraph)->geometries;
            while (geometryPos)
            {
                LocalGeometry* geometry = nextItem(geometryPos);
                if (geometry)
                {
                    for (unsigned i = 0; i < geometry->objects.count; i++)
                    {
                        LocalObject* obj = (LocalObject*)geometry->objects.data[i];
                        unsigned index = obj->geometryLinks.find(geometry);
                        if (index != ~0u)
                            obj->geometryLinks.BSSimpleArray_ShadowSceneLight_1024_Remove(index, true);
                    }
                    geometry->objects.clear();
                    LocalLink<LocalLight>* lightPos = geometry->lights;
                    while (lightPos)
                    {
                        LocalLight* light = nextItem(lightPos);
                        if (light)
                        {
                            int n = (int)light->data->objects.count;
                            for (int j = 0; j < n; j++)
                            {
                                LocalArray* links = &((LocalObject*)light->data->objects.data[j])->lightLinks;
                                unsigned index = links->find(light);
                                if (index != ~0u)
                                    links->remove(index);
                            }
                            light->data->objects.clear();
                        }
                    }
                }
            }
        }
        self->bAllowLightRemoveQueues = true;
        DAT_011f9ea0.unlock();
        DAT_011f9ec0.unlock();
        self->RemoveAllLights();
    }
    reinterpret_cast<LocalContext*&>(self->pBSPortalGraph) = apContext;
}
}  // namespace fnv_00b5ddf0

namespace fnv_00b5b260 {
class FourComponentFloatVector
{
  public:
    NiPoint3 center;
    float radius;
};

extern FourComponentFloatVector DAT_011f4288;
struct S00b5b260_Geom;

struct S00b5b260_Geom
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    FourComponentFloatVector* worldBound;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int flags;
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    BSShaderProperty* shader;
};

struct LightOwnerA
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

    unsigned int unk0d8;

    unsigned int unk0dc;

    ShadowSceneLight** lights;
    unsigned int count;
};

struct LightOwnerB
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

    ShadowSceneLight** lights;
    unsigned int count;
};

SceneGraph* BSShaderManager_GetAccumulator();

extern ShadowSceneNode* DAT_011f91c8;

static inline BSShaderProperty* AsShader(BSShaderProperty* p)
{
    return p->iShaderPropertyType != ~0u ? p : 0;
}
static inline int IsLightingType(BSShaderProperty* p)
{
    unsigned int t = p->iShaderPropertyType;
    return t >= 1 && t <= 12;
}
static inline BSShaderLightingProperty* AsLighting(BSShaderProperty* p)
{
    return IsLightingType(p) ? static_cast<BSShaderLightingProperty*>(p) : 0;
}
static inline ShadowSceneLight* GetNext(ShadowListItem*& pos)
{
    ShadowSceneLight*& result = pos->light;
    pos = pos->next;
    return result;
}
bool __fastcall TestLightSphere(ShadowSceneLight*, int, FourComponentFloatVector*, ShadowLightFlags*, float);
static inline void S00b5b260_Apply(ShadowSceneLight* light, FourComponentFloatVector* bound, S00b5b260_Geom* geom)
{
    if (light)
    {
        ShadowLightFlags* data = reinterpret_cast<ShadowLightFlags*>(light->spLight.m_pObject);
        if (reinterpret_cast<bool (__thiscall*)(ShadowSceneLight*, FourComponentFloatVector*, ShadowLightFlags*, float)>(&TestLightSphere)(light, bound, data, 1.0f))
            light->AddGeometry(reinterpret_cast<NiTriBasedGeom*>(geom));
    }
}
// @fnv 0x00b5b260
// src: COMMUNITY 0x00b5b260
bool ShadowSceneNode_UpdateQueuedObjectLighting(S00b5b260_Geom* geom, ShadowSceneNode* scene, void* unused, LightOwnerA* ownerA, LightOwnerB* ownerB)
{
    BSShaderProperty* pShader = geom->shader;
    if (pShader)
    {
        BSShaderProperty* shader = AsShader(pShader);
        BSShaderLightingProperty* lighting = 0;
        if (shader)
            lighting = AsLighting(shader);
        if (!lighting)
            return false;
        if (!scene)
        {
            // The shared SceneGraph does not yet expose the PC shadow-scene pointer.
            scene = *reinterpret_cast<ShadowSceneNode**>(reinterpret_cast<char*>(BSShaderManager_GetAccumulator()) + 0x194);
            if (!scene)
                scene = DAT_011f91c8;
        }
        lighting->BSShaderLightingProperty_FenceAllLights();
        FourComponentFloatVector* bound = geom->worldBound;
        if (!bound)
            bound = &DAT_011f4288;
        FourComponentFloatVector boundCopy;
        memcpy(&boundCopy, bound, sizeof(boundCopy));
        if (ownerA)
        {
            for (unsigned int i = 0; i < ownerA->count; ++i)
            {
                S00b5b260_Apply(ownerA->lights[i], &boundCopy, geom);
            }
        }
        else if (ownerB)
        {
            for (unsigned int i = 0; i < ownerB->count; ++i)
            {
                S00b5b260_Apply(ownerB->lights[i], &boundCopy, geom);
            }
        }
        else
        {
            ShadowListItem* pos = scene->lLightList.head;
            while (pos)
            {
                S00b5b260_Apply((ShadowSceneLight*)GetNext(pos), &boundCopy, geom);
            }
        }
        lighting->RemoveItemsAfterPos(geom);
        geom->flags |= 0x400000;
        return true;
    }
    return true;
}
}  // namespace fnv_00b5b260

extern const double _gModifierZero;
inline float maximum(float a, float b)
{
    return a > b ? a : b;
}
struct WeightVec
{
    float x, y, z;
    __declspec(noalias) void Unitize_004a0c10();
    WeightVec operator*(float s) const
    {
        WeightVec r;
        r.x = x * s;
        r.y = y * s;
        r.z = z * s;
        return r;
    }
    float Dot(const WeightVec& v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }
};

struct WeightLink
{
    WeightLink* next;
    int previous;
    ShadowSceneLight* item;
};
struct WeightData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    WeightVec ambient;
    WeightVec diffuse;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    WeightVec direction;
};

// Sums light contributions, adds ambient and diffuse terms, and returns the total weighted lighting value at a position.
float __fastcall EvaluateSceneLight(ShadowSceneLight*, int, WeightVec, WeightVec, int);
// @fnv 0x00b5b610
float __fastcall CalculateWeightedLighting(ShadowSceneNode* self, int, WeightVec position, int* count, float* ambient, float* diffuse, WeightVec target, int flags)
{
    float total = 0.0f;
    float previous = 0.0f;
    *count = 0;
    WeightLink* node = reinterpret_cast<WeightLink*>(self->lLightList.head);
    while (node)
    {
        ShadowSceneLight*& light = node->item;
        node = node->next;
        if (light)
        {
            total += reinterpret_cast<float (__thiscall*)(ShadowSceneLight*, WeightVec, WeightVec, int)>(&EvaluateSceneLight)(light, position, target, flags);
            if (total > previous)
            {
                ++*count;
                previous = total;
            }
        }
    }
    WeightData* data = reinterpret_cast<WeightData*>(self->pSunLight->spLight.m_pObject);
    WeightVec* __restrict pAmbient = &data->ambient;
    WeightVec color = *pAmbient;
    float value = maximum(color.x, maximum(color.y, color.z));
    *ambient = value;
    total += value * 0.25;
    WeightVec direction = data->direction;
    WeightVec* __restrict pDiffuse = &data->diffuse;
    color = *pDiffuse;
    value = maximum(color.x, maximum(color.y, color.z));
    *diffuse = value;
    color.x = target.x - position.x;
    color.y = target.y - position.y;
    color.z = target.z - position.z;
    color.Unitize_004a0c10();
    direction.Unitize_004a0c10();
    target = color * 0.75f;
    float factor = target.Dot(direction);
    factor += 0.25;
    float clamped = 1.0f < factor ? 1.0f : factor;
    factor = clamped < _gModifierZero ? 0.0 : clamped;
    factor = 1.0 - factor;
    return factor * value + total;
}

// Reference-taking argument wrapper: the constructor adds a reference; the caller drops it after the call.
template <class T> class S5c6e0_RefArg
{
  public:
    S5c6e0_RefArg(T* p) : m_p(p)
    {
        if (p)
            p->IncRefCount();
    }
    ~S5c6e0_RefArg()
    {
        m_p = m_p;
    }
    T* m_p;
};

template <class T> class S5c6e0_PointerList
{
  public:
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;

    const T& GetNext(void*& pos) const
    {
        NiTListItem<T>* pkItem = static_cast<NiTListItem<T>*>(pos);
        const T& element = pkItem->m_element;
        pos = pkItem->m_pkNext;
        return element;
    }

    void* FindPos(const T& element, void* pos = 0) const
    {
        if (pos == 0)
            pos = m_pkHead;
        while (pos)
        {
            void* savePos = pos;
            if (element == GetNext(pos))
                return savePos;
        }
        return 0;
    }

    void AddTail(const S5c6e0_RefArg<NiRefObject>& element);  // AddTail
};

class S5c6e0_Owner
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
    S5c6e0_PointerList<NiPointer<NiRefObject> > m_kList;

    void BSPortalGraph_AddRoomToAccumList(NiRefObject* pkObject);
};

// @fnv 0x00b5c6e0
// src: COMMUNITY 0x00b5c6e0
void S5c6e0_Owner::BSPortalGraph_AddRoomToAccumList(NiRefObject* pkObject)
{
    if (!m_kList.FindPos(pkObject))
    {
        m_kList.AddTail(pkObject);
        if (pkObject != 0)
            pkObject->DecRefCount();
    }
}

namespace fnv_00b5c940 {
extern NiRTTI g_kDirLightRTTI;    // 0x011f4a68
extern NiRTTI g_kPointLightRTTI;  // 0x011f4a98

static inline bool IsExactLightType(const NiRTTI* type, const NiLight* light)
{
    if (!light) return false;
    return light->GetRTTI() == type;
}

class LightCS
{
  public:
    unsigned int m_uiThreadID;
    unsigned int m_uiEnterCount;
    void Enter(const char* pcName);
    void Leave()
    {
        if (--m_uiEnterCount == 0)
            m_uiThreadID = 0;
    }
};

extern LightCS g_kShadowLightCS;  // 0x011f9ea0

void* AllocObject(unsigned int uiSize);



template <class T> class SSPointerList
{
  public:
    __declspec(noinline) void AddTail(const T& element)
    {
        NiTListItem<T>* pkNode = new NiTListItem<T>;
        pkNode->m_element = element;
        pkNode->m_pkNext = 0;
        pkNode->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkNode;
        else
            m_pkHead = pkNode;
        m_pkTail = pkNode;
        m_uiCount++;
    }
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
};

// Validates pkLight is a directional or point light, creates an ShadowSceneLight, stores bFlag, adds it to m_kLights, and returns the new ShadowSceneLight.
// @fnv 0x00b5c940
ShadowSceneLight* __fastcall CreateSceneLight(ShadowSceneNode* self, int, NiLight* pkLight, bool bFlag)
{
    if (!IsExactLightType(&g_kDirLightRTTI, pkLight) &&
        !IsExactLightType(&g_kPointLightRTTI, pkLight))
        return 0;

    g_kShadowLightCS.Enter(0);
    ShadowSceneLight* pkShadowSceneLight = new ShadowSceneLight;
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, NiLight*)>(&fnv_00b9dda0::BindLight)(pkShadowSceneLight, pkLight);
    pkShadowSceneLight->bDynamicLight = bFlag;
    reinterpret_cast<SSPointerList<NiPointer<ShadowSceneLight> >*>(&self->lLightQueueAdd)->AddTail(pkShadowSceneLight);
    pkShadowSceneLight->pPortalGraph = self->pBSPortalGraph;
    g_kShadowLightCS.Leave();
    return pkShadowSceneLight;
}
}  // namespace fnv_00b5c940

namespace fnv_00b5cbd0 {
struct GlobalObject_0096a2d0
{
    unsigned int m_pOwnerObject;
    unsigned int m_uiItemCount;
    void Lock(const char* = 0);
    void Unlock()
    {
        if (--m_uiItemCount == 0)
            m_pOwnerObject = 0;
    }
};
extern "C" GlobalObject_0096a2d0 DAT_011f9ea0;
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);

struct ActiveLightList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiRefObject> >
{
    NiTListItem<NiPointer<NiRefObject> >* NewItem();
    void AddTail(const NiPointer<NiRefObject>& element);
};

void ActiveLightList::AddTail(const NiPointer<NiRefObject>& element)
{
    NiTListItem<NiPointer<NiRefObject> >* node = NewItem();
    node->m_element = element;
    node->m_pkNext = 0;
    node->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = node;
    else
        m_pkHead = node;
    m_pkTail = node;
    m_kItemCount.m_uiCount++;
}

// Finds a shadow light matching key in shadowLights, clears its flag and returns it, or creates a new LightEx, adds it to m_activeLights, and returns it.
void __fastcall FadeSceneLight(ShadowSceneLight*, int, float, int);
// @fnv 0x00b5cbd0
ShadowSceneLight* __fastcall FindSceneObjectLight(ShadowSceneNode* self, int, void* key)
{
    ShadowListItem* pos = self->lShadowLightList.head;
    while (pos)
    {
        ShadowSceneLight* const& ref = pos->light;
        pos = pos->next;
        ShadowSceneLight* light = (ShadowSceneLight*)ref;
        if (light && light->spShadowScene.m_pObject == key)
        {
            ShadowLightFlags* flags = reinterpret_cast<ShadowLightFlags*>(light->spLight.m_pObject);
            flags->flags &= 0xfffffffe;
            reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, float, int)>(&FadeSceneLight)(light, 1.0f, 0);
            return light;
        }
    }

    DAT_011f9ea0.Lock(0);
    ShadowSceneLight* light = new ShadowSceneLight;
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, void*)>(&ShadowSceneLight_SetShadowCaster)(light, key);
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, bool)>(&SetShadowEnabled)(light, true);
    reinterpret_cast<ActiveLightList*>(&self->lLightQueueAdd)->AddTail(NiPointer<NiRefObject>(light));
    DAT_011f9ea0.Unlock();
    return light;
}
}  // namespace fnv_00b5cbd0

extern unsigned int DAT_011c16bc;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl FUN_00aa1460(void* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

class S00b5cd00_Light
{
  public:
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        FUN_00aa1460(p);
    }
    S00b5cd00_Light();

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
    unsigned int m_flags;
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
};

// Reference-taking argument wrapper: the constructor adds a reference; the caller drops it after the call.
template <class T> class S00b5cd00_Ptr
{
  public:
    S00b5cd00_Ptr(T* p) : m_p(p)
    {
        InterlockedIncrement(&*reinterpret_cast<volatile long*>(&p->m_uiRefCount));
    }
    ~S00b5cd00_Ptr()
    {
        m_p = m_p;
    }
    T* m_p;
};

class S00b5cd00_List
{
  public:
    void AddTail(const S00b5cd00_Ptr<ShadowSceneLight>& item);
};

// @fnv 0x00b5cd00
ShadowSceneLight* __fastcall AddDynamicLight(ShadowSceneNode* self, int, ShadowSceneLight* param)
{
    param->bDynamicLight = 1;
    S00b5cd00_Light* light = new S00b5cd00_Light;
    light->m_flags &= ~1u;
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, S00b5cd00_Light*)>(&fnv_00b9dda0::BindLight)(param, light);
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, bool)>(&SetShadowEnabled)(param, true);
    param->bCubeShadowMap = 0;
    reinterpret_cast<S00b5cd00_List*>(&self->lShadowLightList)->AddTail(param);
    if (InterlockedDecrement(&*reinterpret_cast<volatile long*>(&param->m_uiRefCount)) == 0)
        param->DeleteThis();
    return param;
}

extern float DAT_011ad834;

struct MyShadowListItem
{
    MyShadowListItem* next;
    MyShadowListItem* prev;
    ShadowSceneLight* light;
};

struct MyShadowList
{
    MyShadowListItem* head;
    MyShadowListItem* tail;
    unsigned int count;
    void FUN_00c1b4a0(void* pRef);
    void MoveNodeBefore(MyShadowListItem* a, MyShadowListItem* b);
    void MoveBefore(MyShadowListItem* a, MyShadowListItem* b);
};

// Reorders shadow lights by fade state, moving nodes before the active or fading-in fence.
// @fnv 0x00b5cde0
void __fastcall SortShadowLights(ShadowSceneNode* self, int, ShadowSceneLight* apLight)
{
    MyShadowList* pShadowList = reinterpret_cast<MyShadowList*>(&self->lShadowLightList);

    if (!reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence))
    {
        pShadowList->FUN_00c1b4a0(&self->kShadowLightFadingInFenceObject);
        reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence) = pShadowList->head;
    }
    else
    {
        pShadowList->MoveNodeBefore(reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence), pShadowList->head);
    }

    if (!reinterpret_cast<MyShadowListItem*&>(self->kShadowLightActiveFence))
    {
        pShadowList->FUN_00c1b4a0(&self->kShadowLightActiveFenceObject);
        reinterpret_cast<MyShadowListItem*&>(self->kShadowLightActiveFence) = pShadowList->head;
    }
    else
    {
        pShadowList->MoveNodeBefore(reinterpret_cast<MyShadowListItem*&>(self->kShadowLightActiveFence), pShadowList->head);
    }

    if (!reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence))
        return;

    MyShadowListItem* cur = reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence)->next;
    while (cur)
    {
        MyShadowListItem* node = cur;
        ShadowSceneLight*& light = cur->light;
        cur = cur->next;

        if (!light)
            continue;

        if (light->fShadowLODDimmerTarget <= 0.100000001490116119384765625 && light->fShadowLODDimmerElapsed < DAT_011ad834)
        {
            MyShadowListItem* d0 = reinterpret_cast<MyShadowListItem*&>(self->kShadowLightActiveFence);
            if (node != d0)
            {
                if (pShadowList->head == node)
                    pShadowList->head = node->next;
                if (pShadowList->head == d0)
                    pShadowList->head = node;
                if (pShadowList->tail == node)
                    pShadowList->tail = node->prev;
                if (node->next)
                    node->next->prev = node->prev;
                if (node->prev)
                    node->prev->next = node->next;
                node->prev = d0->prev;
                node->next = d0;
                if (node->prev)
                    node->prev->next = node;
                d0->prev = node;
            }
            continue;
        }

        if (light->fShadowLODDimmerTarget >= 0.89999997615814208984375 && light->fShadowLODDimmerElapsed < DAT_011ad834)
        {
            float val = (light->fShadowLODDimmerTarget > 0.0f) ? light->fShadowLODDimmerElapsed / DAT_011ad834 : 1.0f - light->fShadowLODDimmerElapsed / DAT_011ad834;
            if (val > 0.100000001490116119384765625)
            {
                pShadowList->MoveBefore(node, reinterpret_cast<MyShadowListItem*&>(self->kShadowLightActiveFence));
                continue;
            }
        }

        if (!(reinterpret_cast<ShadowLightFlags*>(light->spLight.m_pObject)->flags & 1))
        {
            if (!(light->fShadowLODDimmerTarget >= 0.89999997615814208984375 && light->fShadowLODDimmerElapsed < DAT_011ad834))
            {
                if (light == apLight)
                {
                    pShadowList->MoveNodeBefore(node, reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence));
                }
                else
                {
                    pShadowList->MoveBefore(node, reinterpret_cast<MyShadowListItem*&>(self->kShadowLightFadingInFence));
                }
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);

extern unsigned int DAT_011c16bc;

struct S00b5d9f0_Lock
{
    unsigned int m_pOwnerObject;
    int m_uiItemCount;

    void __thiscall BSSpinLock_Lock(int spin);
};

extern S00b5d9f0_Lock DAT_011f9ec0;
extern int DAT_011f9ec4;

class S00b5d9f0_Obj
{
  public:
    virtual void vf00();
    virtual void DeleteThis();
    long m_iObjectReferenceCount;
};

struct S00b5d9f0_Temp
{
    S00b5d9f0_Obj* m_p;

    S00b5d9f0_Temp(S00b5d9f0_Obj* p) : m_p(p)
    {
        InterlockedIncrement(&p->m_iObjectReferenceCount);
    }

    ~S00b5d9f0_Temp()
    {
        m_p = m_p;
    }
};

struct S00b5d9f0_List
{
    int unk00;
    int unk04;
    int unk08;

    void __thiscall AddTail(const S00b5d9f0_Temp& item);
};

// Adds obj to m_list108 or m_list114 based on flag, then decrements obj's reference count and deletes it if zero.
// @fnv 0x00b5d9f0
void __fastcall QueueObjectUpdate(ShadowSceneNode* self, int, S00b5d9f0_Obj* obj, unsigned char flag)
{
    if (obj == 0)
        return;

    DAT_011f9ec0.BSSpinLock_Lock(0);

    switch (!flag)
    {
    default:
        reinterpret_cast<S00b5d9f0_List*>(&self->lObjectQueueUpdate)->AddTail(S00b5d9f0_Temp(obj));
        break;
    case 0:
        reinterpret_cast<S00b5d9f0_List*>(&self->lObjectQueueUpdateActiveOnly)->AddTail(S00b5d9f0_Temp(obj));
        break;
    }

    if (InterlockedDecrement(&obj->m_iObjectReferenceCount) == 0)
        obj->DeleteThis();

    --DAT_011f9ec4;
    if (DAT_011f9ec4 == 0)
        DAT_011f9ec0.m_pOwnerObject = 0;
}

class NiCullingProcess;
namespace fnv_00b5e870 {
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();

void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* Addend);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);


struct Obj4
{

    int m_00;

    int m_04;
};

typedef NiPointer<ShadowSceneLight> RefPtr_b9fcc0;
struct FirstOwner
{
    ShadowSceneLight* m_pObject;
    FirstOwner(ShadowSceneLight* p) : m_pObject(p)
    {
        if (p)
            p->IncRefCount();
    }
    ~FirstOwner()
    {
        ShadowSceneLight* p = m_pObject;
        _ReadWriteBarrier();
        if (p)
            p->DecRefCount();
    }
};

struct Node
{

    Node* m_next;

    Node* m_pSecondNode;

    RefPtr_b9fcc0 m_light;
};

class List_b9fcc0
{

  public:
    Node* m_pFirstNode;

    Node* m_pTail;

    unsigned int m_uiItemCount;
    RefPtr_b9fcc0& GetNext(void*& pos)
    {
        RefPtr_b9fcc0& result = static_cast<Node*>(pos)->m_light;
        pos = static_cast<Node*>(pos)->m_next;
        return result;
    }

    RefPtr_b9fcc0 FUN_00b9fcc0(const FirstOwner& r);

    __declspec(noinline) RefPtr_b9fcc0 FUN_00b9efa0(void*& p);
    RefPtr_b9fcc0 PopFront();
    RefPtr_b9fcc0 PopBack();
    void ReleaseRefCountedNode(Node* node);
};

struct Vec3f
{
    float x, y, z;
};

struct MatObj
{

    float m_reserve00_0;
    float m_reserve00_1;
    float m_reserve00_2;
    float m_reserve00_3;
    float m_reserve00_4;
    float m_reserve00_5;
    float m_reserve00_6;
    float m_reserve00_7;

    float m_reserve00_8;
    float m_reserve00_9;
    float m_reserve00_10;
    float m_reserve00_11;
    float m_reserve00_12;
    float m_reserve00_13;
    float m_reserve00_14;
    float m_reserve00_15;

    float m_reserve00_16;
    float m_reserve00_17;
    float m_reserve00_18;
    float m_reserve00_19;
    float m_reserve00_20;
    float m_reserve00_21;
    float m_reserve00_22;
    float m_reserve00_23;

    float m_reserve00_24;
    float m_reserve00_25;

    float m_68;

    float m_6c;

    float m_70;

    float m_74;

    float m_78;

    float m_7c;

    float m_80;

    float m_84;

    float m_88;

    Vec3f m_vContactPosition;
};

class ParamObj
{

  public:
    void BSCullingProcess_ClearSharedMap();

    int m_00;

    int m_04;

    int m_08;

    MatObj* m_0c;
};

struct Obj134
{

    float m_reserve00_0;
    float m_reserve00_1;
    float m_reserve00_2;
    float m_reserve00_3;
    float m_reserve00_4;
    float m_reserve00_5;
    float m_reserve00_6;
    float m_reserve00_7;

    Vec3f m_kDiffuseColor;

    float m_2c;

    float m_30;

    float m_reserve34_0;
    float m_reserve34_1;
    float m_reserve34_2;
    float m_reserve34_3;
    float m_reserve34_4;
    float m_reserve34_5;
    float m_reserve34_6;
    float m_reserve34_7;

    float m_reserve34_8;
    float m_reserve34_9;
    float m_reserve34_10;

    float m_60;
};

char __cdecl BSShaderManager_GetShadows();

struct Vec4f
{

    float x, y, z;
    union
    {
        float w;
        unsigned bitsW;
    };
    Vec4f()
    {}
    void Set(const Vec3f& v, float fourth)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = fourth;
    }
};

extern int DAT_011f91c0;

extern unsigned char DAT_011f91c4;

extern void* DAT_011f917c;

extern unsigned char DAT_011f91a7;

extern int DAT_011ad868;

extern int DAT_011f91d8;

extern float DAT_011ad824;

extern Vec4f DAT_011fa2a0;

extern Vec4f DAT_011fa2b0;

extern Vec4f DAT_011fa2c0;

extern Vec4f DAT_011fa280;

extern Vec4f DAT_011fa290;

extern float DAT_01200504;

extern float DAT_01200500;

extern float DAT_01200558;

struct LinkArray
{
    virtual void v0();
    unsigned int* data;
    unsigned int count, capacity;
    unsigned int FindFirstMatch(const RefPtr_b9fcc0*, unsigned int, int(__cdecl*)(int*, int*));
    void BSSimpleArray_ShadowSceneLight_1024_Remove(unsigned int, bool);
};
struct GeometryLinks
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    LinkArray objects;
};
struct LinkedLightData
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    LinkArray links;
};
struct LinkedLight
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    LinkedLightData* data;
};
struct LightContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int count;
};
extern int __cdecl Object_ComputeValue_00b5a980(int*, int*);

class ShadowSceneUpdater : public ShadowSceneNode
{
  public:
    __declspec(noinline) void RemoveLightFromNode(RefPtr_b9fcc0&, void*&);
    void FUN_00b5d270(ShadowSceneLight*);
    unsigned int NiNode_OnVisible(void*);
    unsigned int ShadowSceneNode_PreOnVisible(ParamObj*);
};
void __fastcall UpdateSceneLight(ShadowSceneLight*, int, void*);
__declspec(noinline) RefPtr_b9fcc0 List_b9fcc0::FUN_00b9efa0(void*& p)
{
    Node* node = static_cast<Node*>(p);
    if (node == m_pFirstNode)
    {
        p = node->m_next;
        return PopFront();
    }
    if (node == m_pTail)
    {
        p = 0;
        return PopBack();
    }
    Node* previous = node->m_pSecondNode;
    Node* next = node->m_next;
    p = next;
    if (previous)
        previous->m_next = next;
    if (next)
        next->m_pSecondNode = previous;
    RefPtr_b9fcc0 item = node->m_light;
    ReleaseRefCountedNode(node);
    --m_uiItemCount;
    return item;
}

__declspec(noinline) void ShadowSceneUpdater::RemoveLightFromNode(RefPtr_b9fcc0& value, void*& position)
{
    LightContext* context = reinterpret_cast<LightContext*>(reinterpret_cast<int>(pBSPortalGraph));
    ShadowSceneLight* item = value;
    if (context && context->count)
    {
        for (unsigned int i = 0; i < item->kMultiboundRooms.iSize; ++i)
        {
            GeometryLinks* geometry = reinterpret_cast<GeometryLinks**>(item->kMultiboundRooms.pBuffer)[i];
            if (geometry && geometry->objects.count)
            {
                unsigned int index = geometry->objects.FindFirstMatch(&value, 0, Object_ComputeValue_00b5a980);
                if (index != ~0u)
                    geometry->objects.BSSimpleArray_ShadowSceneLight_1024_Remove(index, true);
            }
            item = value;
        }
        for (unsigned int i = 0; i < item->kPortals.iSize; ++i)
        {
            LinkedLight* light = reinterpret_cast<LinkedLight**>(item->kPortals.pBuffer)[i];
            if (light && light->data->links.count)
            {
                LinkedLightData* data = light->data;
                unsigned int index = ~0u;
                for (unsigned int j = 0; j < data->links.count; ++j)
                {
                    if (data->links.data && data->links.data[j] == reinterpret_cast<unsigned int>(item))
                    {
                        index = j;
                        break;
                    }
                }
                if (index != ~0u)
                    data->links.BSSimpleArray_ShadowSceneLight_1024_Remove(index, true);
            }
            item = value;
        }
    }
    if (item->bCastShadow)
        reinterpret_cast<List_b9fcc0&>(lShadowLightList).FUN_00b9efa0(position);
    else
        reinterpret_cast<List_b9fcc0&>(lLightList).FUN_00b9efa0(position);
}

// Processes entries in reinterpret_cast<List_b9fcc0&>(lLightList), updates globals from arg and reinterpret_cast<Obj134*>(spFog.m_pObject), and returns a value derived from reinterpret_cast<Obj134*>(spFog.m_pObject) or FUN_00a5dbe0.
// @fnv 0x00b5e870
// src: XBOX_PDB 0x00b5e870
unsigned int ShadowSceneUpdater::ShadowSceneNode_PreOnVisible(ParamObj* arg)

{

    arg->BSCullingProcess_ClearSharedMap();

    MatObj& own = *arg->m_0c;

    if (!bDisableLightUpdate)
    {
        void* y = reinterpret_cast<List_b9fcc0&>(lLightList).m_pFirstNode;
        while (y)
        {
            void* v = y;
            ShadowSceneLight* idx = reinterpret_cast<List_b9fcc0&>(lLightList).GetNext(y);
            if (idx)
            {
                if (reinterpret_cast<Obj4*>(idx->spLight.m_pObject) && reinterpret_cast<Obj4*>(idx->spLight.m_pObject)->m_04 != 1)
                {
                    if (idx->bDynamicLight)
                        FUN_00b5d270(idx);
                    if (!idx->bCastShadow || !BSShaderManager_GetShadows())
                        reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, void*)>(&UpdateSceneLight)(idx, arg);
                }
                else
                {
                    int id = reinterpret_cast<int>(idx->pPortalGraph);
                    int c;
                    c = reinterpret_cast<int>(pBSPortalGraph);
                    if (id != c)
                    {
                        if (idx->bCastShadow)
                        {
                            FirstOwner q(idx);
                            reinterpret_cast<List_b9fcc0&>(lShadowLightList).FUN_00b9fcc0(q);
                        }
                        else
                        {
                            reinterpret_cast<List_b9fcc0&>(lLightList).FUN_00b9efa0(v);
                        }
                    }
                    else
                    {
                        RefPtr_b9fcc0 q(idx);
                        RemoveLightFromNode(q, v);
                    }
                }
            }
        }
    }
    DAT_011f91c4 = (unsigned char)cSceneGraphIndex;

    DAT_011f917c = &own;

    if (DAT_011f91c0 == 0)
    {

        return NiNode_OnVisible(arg);
    }

    if (1 == DAT_011f91a7)
    {

        if (DAT_011ad868 == -1)

            DAT_011ad868 = DAT_011f91d8;

        DAT_011f91d8 = 4;
    }
    else
    {

        unsigned long pForm;

        pForm = DAT_011ad868;

        if (pForm != -1)
        {

            DAT_011f91d8 = pForm;

            DAT_011ad868 = -1;
        }
    }

    Vec3f ptr;
    ptr = own.m_vContactPosition;
    Vec4f n;
    n.Set(ptr, 0.0f);
    DAT_011fa2a0 = n;

    ptr.x = own.m_68;
    ptr.y = own.m_74;
    ptr.z = own.m_80;
    n.Set(ptr, 0.0f);
    DAT_011fa2b0 = n;

    ptr.x = own.m_70;
    ptr.y = own.m_7c;
    ptr.z = own.m_88;
    n.Set(ptr, 0.0f);
    DAT_011fa2c0 = n;

    Obj134* val;
    val = reinterpret_cast<Obj134*>(spFog.m_pObject);
    unsigned result = reinterpret_cast<unsigned>(val);
    if (val)
    {
        ptr = val->m_kDiffuseColor;
        float pObj;
        pObj = val->m_30;
        n.x = pObj;
        n.y = pObj - val->m_2c;
        n.z = val->m_60;
        n.w = 0.0f;
        DAT_011fa280 = n;
        n.Set(ptr, 0.0f);
        DAT_011fa290 = n;
        result = n.bitsW;
    }
    DAT_01200558 = DAT_01200500 + (DAT_01200504 - DAT_01200500) * DAT_011ad824;

    return result;
}
}  // namespace fnv_00b5e870

struct S00b5eca0_Ref
{
    virtual void vfn00();
    virtual void DeleteThis();
    long m_lRefCount;
};
struct S00b5eca0_Ptr
{
    ShadowSceneLight* const m_pObject;
    S00b5eca0_Ptr(ShadowSceneLight* p) : m_pObject(p)
    {
        InterlockedIncrement(&((S00b5eca0_Ref*)p)->m_lRefCount);
    }
    operator ShadowSceneLight*() const
    {
        return m_pObject;
    }
    ~S00b5eca0_Ptr()
    {
        if (InterlockedDecrement(&((S00b5eca0_Ref*)m_pObject)->m_lRefCount) == 0)
            ((S00b5eca0_Ref*)m_pObject)->DeleteThis();
    }
};
struct S00b5eca0_List
{
    ShadowListItem* head;
    ShadowListItem* tail;
    unsigned count;
    void AddTail(const S00b5eca0_Ptr& sp);
};
ShadowListItem* S00b5eca0_NewItem();
__declspec(noinline) void S00b5eca0_List::AddTail(const S00b5eca0_Ptr& sp)
{
    ShadowListItem* pkItem = S00b5eca0_NewItem();
    pkItem->light = sp.m_pObject;
    pkItem->next = 0;
    pkItem->prev = tail;
    if (tail)
        tail->next = pkItem;
    else
        head = pkItem;
    tail = pkItem;
    count++;
}
struct S00b5eca0_Group
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void SetBuffer(void* pkBuffer);
};
// Entry points not yet declared by the shared BSTextureManager header.
extern void* BSTextureManager_GetShadowDepthBuffer();
extern BSRenderedTexture* FUN_00b6d3f0();
extern NiRenderer* DAT_011f9508;
struct S00b5eca0_Settings
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    char unkec;
    bool m_bUseRenderedShadows;
};

// Adds pkLight to the lights list, assigning a shadow texture if it casts shadows, and returns an existing light with the same lightData or null.
// @fnv 0x00b5eca0
ShadowSceneLight* __fastcall AddSceneLight(ShadowSceneNode* self, int, ShadowSceneLight* pkLight)
{
    ShadowListItem* pkIter = self->lLightList.head;
    ShadowLightFlags* pkData = reinterpret_cast<ShadowLightFlags*>(pkLight->spLight.m_pObject);
    while (pkIter)
    {
        ShadowSceneLight*& rkExisting = pkIter->light;
        pkIter = pkIter->next;
        ShadowSceneLight* pkExisting = rkExisting;
        if (pkExisting && reinterpret_cast<ShadowLightFlags*>(pkExisting->spLight.m_pObject) == pkData)
        {
            pkExisting->bDynamicLight = pkLight->bDynamicLight;
            reinterpret_cast<void (__thiscall*)(ShadowSceneNode*, ShadowSceneLight*)>(&ProcessSceneLight)(self, pkExisting);
            return pkExisting;
        }
    }
    ((S00b5eca0_List*)&self->lLightList)->AddTail(pkLight);

    if (pkLight->bCastShadow)
    {
        BSRenderedTexture* pkTexture;
        if (((S00b5eca0_Settings*)0)->m_bUseRenderedShadows)
        {
            pkTexture = static_cast<BSRenderedTexture*>(DAT_011f91a8->BSTextureManager_BorrowRenderedTexture(DAT_011f9508, 0x2a, 0, 0, 0));
            reinterpret_cast<S00b5eca0_Group*>(pkTexture->GetGroup())->SetBuffer(reinterpret_cast<void* (__thiscall*)(BSTextureManager*)>(&BSTextureManager_GetShadowDepthBuffer)(DAT_011f91a8));
        }
        else
        {
            pkTexture = reinterpret_cast<BSRenderedTexture* (__thiscall*)(BSTextureManager*)>(&FUN_00b6d3f0)(DAT_011f91a8);
        }
        reinterpret_cast<void (__thiscall*)(ShadowSceneLight*, BSRenderedTexture*)>(&AssignRefObject)(pkLight, pkTexture);
    }
    reinterpret_cast<void (__thiscall*)(ShadowSceneNode*, ShadowSceneLight*)>(&ProcessSceneLight)(self, pkLight);
    return 0;
}

namespace fnv_00b5f9b0 {
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct CullProcess;
struct CullObject;
struct CullObject
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void Cull(CullProcess*);
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
    unsigned int flags;
    void FUN_00a59e00(CullProcess*);
};
struct CullEntry;
struct CullLightNode
{
    CullLightNode* next;
    CullLightNode* prev;
    CullEntry* item;
};
struct CullLightList
{
    CullLightNode* head;
    CullLightNode* tail;
    unsigned count;
    CullEntry*& GetNext(CullLightNode*& pos)
    {
        CullEntry*& item = pos->item;
        pos = pos->next;
        return item;
    }
};
struct CullEntry
{
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    CullObject* object;
};
struct CullGroupNode
{
    CullGroupNode* next;
    CullGroupNode* prev;
    struct CullGroup* item;
};
struct CullGroupList
{
    CullGroupNode* head;
    CullGroupNode* tail;
    unsigned count;
    unsigned unknown;
    CullGroup*& GetNext(CullGroupNode*& pos)
    {
        CullGroup*& item = pos->item;
        pos = pos->next;
        return item;
    }
};
struct CullGroup : CullObject
{
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    CullLightList lights;
};
struct CullProcess
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void* camera;
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
    int mode;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int state;
    bool BSCullingProcess_AddShared(CullObject*);
};
struct CullManager
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    CullLightList lights;
    CullGroupList groups20;
    CullGroupList groups30;
    unsigned int unk40, unk44, unk48;
    CullObject* extra;
    unsigned int BSPortalGraph_GetAlwaysRenderArrayCount();
    CullObject* BSPortalGraph_GetAlwaysRenderAt(unsigned int);
};
struct CullScratch
{
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
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    void FUN_00c47660();
    void FUN_00c47770();
    CullScratch()
    {
        FUN_00c47660();
    }
    ~CullScratch()
    {
        FUN_00c47770();
    }
};
struct CullHeap
{
    void* ScrapHeap_Allocate(unsigned int, unsigned int);
    void ScrapHeap_Deallocate(void*);
};
struct CullMemoryManager
{
    CullHeap* FUN_00aa42e0();
};
extern CullMemoryManager DAT_011f6238;
extern unsigned int DAT_010a2720;
NiRefObject* BSShaderManager_GetAccumulator();

// Culls scene objects and lights by iterating group lists and calling Cull on visible entries, using a saved flags buffer to track state changes.
class ShadowSceneCuller : public ShadowSceneNode
{
  public:
    void ShadowSceneNode_PreOnVisible(CullProcess*);
    void NiNode_OnVisible(CullProcess*);
    void FUN_00b5ba80(void*, CullEntry*);
    void ShadowSceneNode_OnVisible(CullProcess*);
};
// @fnv 0x00b5f9b0
// src: XBOX_PDB 0x00b5f9b0
void ShadowSceneCuller::ShadowSceneNode_OnVisible(CullProcess* process)
{
    ShadowSceneNode_PreOnVisible(process);
    NiPointer<NiRefObject> context(BSShaderManager_GetAccumulator());
    unsigned int rc = context->m_uiRefCount;
    if (rc == 1)
        context->IncRefCount();
    if (reinterpret_cast<CullManager*>(pBSPortalGraph))
    {
        CullHeap* heap = DAT_011f6238.FUN_00aa42e0();
        bool* pSavedFlags = 0;
        if (reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderArrayCount() > 0)
        {
            pSavedFlags = (bool*)heap->ScrapHeap_Allocate(reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderArrayCount(), DAT_010a2720);
            FUN_00ec61c0(pSavedFlags, 0, reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderArrayCount());
        }
        for (unsigned int i = 0; i < reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderArrayCount(); ++i)
        {
            CullObject* object = reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderAt(i);
            if (object)
            {
                pSavedFlags[i] = (bool)(object->flags & 1);
                object->flags |= 1;
            }
        }
        {
            CullObject* extra = reinterpret_cast<CullManager*>(pBSPortalGraph)->extra;
            if (extra)
                extra->flags |= 1;
        }
        if (!bVisibleUnboundSpace && process->mode != 1 && process->mode != 3)
        {
            CullGroupNode* pos = reinterpret_cast<CullManager*>(pBSPortalGraph)->groups30.head;
            while (pos)
            {
                CullGroup* group = reinterpret_cast<CullManager*>(pBSPortalGraph)->groups30.GetNext(pos);
                if (group)
                {
                    group->Cull(process);
                    if (group->lights.count)
                    {
                        CullLightNode* pLightNode = group->lights.head;
                        while (pLightNode)
                        {
                            CullEntry* entry = group->lights.GetNext(pLightNode);
                            if (entry)
                            {
                                CullObject* object = entry->object;
                                if (process->BSCullingProcess_AddShared(object))
                                {
                                    void* camera = process->camera;
                                    FUN_00b5ba80(camera, entry);
                                    entry->object->Cull(process);
                                }
                            }
                        }
                    }
                    process->state = 0;
                }
            }
            for (unsigned int i = 4; i < m_kChildren.m_usSize; ++i)
            {
                CullObject* object = reinterpret_cast<CullObject**>(m_kChildren.m_pBase)[i];
                if (object)
                    object->FUN_00a59e00(process);
            }
        }
        else
        {
            NiNode_OnVisible(process);
            CullGroupList* list = &reinterpret_cast<CullManager*>(pBSPortalGraph)->groups30;
            if (process->mode == 1 || process->mode == 3)
                list = &reinterpret_cast<CullManager*>(pBSPortalGraph)->groups20;
            CullGroupNode* pos = list->head;
            CullScratch scratch;
            while (pos)
            {
                CullGroup* group = list->GetNext(pos);
                CullLightList* lights = group ? &group->lights : &reinterpret_cast<CullManager*>(pBSPortalGraph)->lights;
                if (lights->count)
                {
                    CullLightNode* pLightNode = lights->head;
                    while (pLightNode)
                    {
                        CullEntry* entry = lights->GetNext(pLightNode);
                        if (entry)
                        {
                            CullObject* object = entry->object;
                            if (process->BSCullingProcess_AddShared(object))
                                entry->object->Cull(process);
                        }
                    }
                }
                process->state = 0;
            }
        }
        for (unsigned int i = 0; i < reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderArrayCount(); ++i)
        {
            CullObject* object = reinterpret_cast<CullManager*>(pBSPortalGraph)->BSPortalGraph_GetAlwaysRenderAt(i);
            if (object && !pSavedFlags[i])
            {
                object->flags &= ~1;
                object->FUN_00a59e00(process);
            }
        }
        {
            CullObject* extra = reinterpret_cast<CullManager*>(pBSPortalGraph)->extra;
            if (extra)
                extra->flags &= ~1;
        }
        heap->ScrapHeap_Deallocate(pSavedFlags);
    }
    else
    {
        NiNode_OnVisible(process);
    }
}
}  // namespace fnv_00b5f9b0

#include <math.h>
struct LightObj
{
    virtual void v0();
    virtual void v1();
    virtual void* GetRTTI();
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    NiPoint3 pos;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    float radius;
};

extern ShadowSceneNode* DAT_011f91c8;
extern char DAT_011f4a68[];

// Uses defLight when l is null, returns true for matching RTTI, otherwise compares an adjusted distance with l->radius.
// @fnv 0x00b9dae0
// src: COMMUNITY 0x00b9dae0
bool ShadowSceneLight::BoundWithinLightRadius(NiPoint3* apPoint, NiLight* light, float scale)
{
    LightObj* apLight = reinterpret_cast<LightObj*>(light);
    if (!apLight)
        apLight = reinterpret_cast<LightObj*>(spLight.m_pObject);
    if (apLight->GetRTTI() == (void*)DAT_011f4a68)
        return true;
    NiPoint3 d;
    d.x = apLight->pos.x - apPoint->x;
    d.y = apLight->pos.y - apPoint->y;
    d.z = apLight->pos.z - apPoint->z;
    NiPoint3 g;
    memcpy(&g, &DAT_011f91c8->kLightingOffset, sizeof(g));
    NiPoint3 s;
    s.x = g.x + d.x;
    s.y = g.y + d.y;
    s.z = g.z + d.z;
    float len = (float)sqrt((double)s.Dot(s));
    float v = len - apPoint[1].x * scale;
    if (v < apLight->radius)
        return true;
    return false;
}

namespace fnv_00b5b410 {

struct Sub1
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    BSShaderLightingProperty* unk0c;
};

struct Obj
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned int flags;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    Sub1 sub1;
};

inline int valid(BSShaderLightingProperty* q)
{
    switch (q->iShaderPropertyType)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return 1;
    default:
        return 0;
    }
}

// @fnv 0x00b5b410
// src: COMMUNITY 0x00b5b410
bool __cdecl ShadowSceneNode_UpdateQueuedObjectLightingList(Obj* pObj, void* apUnused, ShadowSceneLight** apLights, bool abUnused)
{
    Sub1* pSub1 = &pObj->sub1;
    if (pSub1)
    {
        BSShaderLightingProperty* pSub2 = pSub1->unk0c;
        if (pSub2)
        {
            BSShaderLightingProperty* p = (pSub2->iShaderPropertyType != -1) ? pSub2 : 0;
            if (!p)
                goto fail;
            p = valid(p) ? p : 0;
            if (!p)
                goto fail;

            p->BSShaderLightingProperty_FenceAllLights();
            for (int i = 0; apLights[i]; ++i)
            {
                if (apLights[i])
                {
                    apLights[i]->AddGeometry(reinterpret_cast<NiTriBasedGeom*>(pObj));
                }
            }
            p->RemoveItemsAfterPos(pObj);
            pObj->flags |= 0x400000;
            return true;

        fail:
            return false;
        }
    }
    return true;
}
}  // namespace fnv_00b5b410

namespace fnv_00b5d300 {
struct Pt4
{
    NiPoint3 pt;
    float w;
    __forceinline Pt4(const NiPoint3& a_pt, float a_w)
    {
        pt = a_pt;
        w = a_w;
    }
};

int __cdecl Object_ComputeValue_00b5a980(int*, int*);

template <class T> struct ArrayLikeT
{
    void* vptr;
    T* data;
    unsigned int count;
    int f0c;
    int FindFirstMatch(const T* key, int zero, int(__cdecl* cb)(int*, int*));
    unsigned int BSSimpleArray_GetNextIndex_2();
    unsigned int FUN_00761540();

    __forceinline int Find(const T& key)
    {
        return FindFirstMatch(&key, 0, Object_ComputeValue_00b5a980);
    }

    __forceinline void Clear()
    {
        if (data)
        {
            void** vt = *(void***)this;
            void(__thiscall * fn)(void*, void*) = (void(__thiscall*)(void*, void*))vt[2];
            fn(this, data);
            data = 0;
            f0c = 0;
            count = 0;
        }
    }

    __forceinline unsigned int FindIdx(T val)
    {
        unsigned int i = 0;
        if (count > 0)
        {
            T* d = data;
            do
            {
                if (d && d[i] == val)
                    return i;
                i++;
            } while (i < count);
        }
        return (unsigned int)-1;
    }

    __forceinline void Add(const T& val)
    {
        unsigned int ni = BSSimpleArray_GetNextIndex_2();
        data[ni] = val;
    }

    __forceinline void Add76(T val)
    {
        unsigned int ni = FUN_00761540();
        data[ni] = val;
    }
};

class FUN_00b5aea0_self
{
  public:
    void RemoveRange(unsigned int, unsigned int);
};

class FUN_00c5b5d0_class
{
  public:
    unsigned int BSPortalGraph_GetAlwaysRenderArrayCount();
};
class FUN_00c5b5a0_cls
{
  public:
    int BSPortalGraph_GetAlwaysRenderAt(int);
};

struct LightData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    char flag30;
    char unk31, unk32, unk33;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    NiPoint3 pt;
    int unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    float f_c4;
    int unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    float f_e0;
};

struct Coll;
struct ItemObj;
struct OwnerObj;

struct OwnerObj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    ArrayLikeT<ShadowSceneLight*> arr;
};

struct Node
{
    Node* next;
    int f04;
    ItemObj* data;
};

struct PtrList
{
    Node* head;
    Node* tail;
    int count;
    inline ItemObj*& GetNext(Node*& pos) const
    {
        ItemObj*& elt = pos->data;
        pos = pos->next;
        return elt;
    }
};

struct VirtObj
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual char v45(NiPoint3*);
};
struct Holder
{
    int unk00, unk04, unk08;
    VirtObj* m_0c;
};

struct ItemObj
{
    virtual void vfn00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual int v68(Pt4*);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    Holder* m_ac;
    int f_b0;
    PtrList listB4;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8;
    ArrayLikeT<ShadowSceneLight*> mapDc;
    int unkec, unkf0, unkf4, unkf8, unkfc, unk100;
    OwnerObj* m_104;
};

struct Coll
{
    int unk00, unk04, unk08, unk0c, unk10;
    PtrList list14;
    PtrList list20;
    int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    void** arr6c;
    unsigned int count70;
};

class ElemObj
{
  public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void* vfn3();
};
struct GetterObj
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    int f_18;
};

extern ShadowSceneNode* DAT_011f91c8;

// Updates p's arrays using entries from reinterpret_cast<Coll*>(self->pBSPortalGraph) or reinterpret_cast<ElemObj**>(self->m_kChildren.m_pBase), adding or removing entries based on virtual checks.
void __fastcall ClearLightGeometry(ShadowSceneLight*, int);
void __fastcall FinishLightGeometry(ShadowSceneLight*, int);
static inline void AddPortalObject(ShadowSceneLight* light, void* object)
{
    light->AddObject(reinterpret_cast<NiAVObject*>(object));
}
// @fnv 0x00b5d300
void __fastcall ProcessPortalLight(ShadowSceneNode* self, int, ShadowSceneLight* apLight)
{
    LightData* ld = reinterpret_cast<LightData*>(apLight->spLight.m_pObject);
    if ((ld->flag30 & 1) || ld->f_c4 < (double)0.05f)
    {
        reinterpret_cast<void (__thiscall*)(ShadowSceneLight*)>(&ResetSceneLight)(apLight);
        return;
    }
    reinterpret_cast<Coll*&>(apLight->pPortalGraph) = reinterpret_cast<Coll*>(self->pBSPortalGraph);
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*)>(&ClearLightGeometry)(apLight);
    unsigned int uiIndex = 0;
    if (reinterpret_cast<Coll*>(self->pBSPortalGraph) && reinterpret_cast<Coll*>(self->pBSPortalGraph)->list20.count)
    {
        reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kMultiboundRooms).Clear();
        reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kPortals).Clear();
        reinterpret_cast<ArrayLikeT<OwnerObj*>&>(apLight->kProcessedNodes).Clear();
        LightData* pLightData2 = reinterpret_cast<LightData*>(apLight->spLight.m_pObject);
        NiPoint3 ptPos;
        memcpy(&ptPos, &pLightData2->pt, sizeof(ptPos));
        Pt4 pt4Pos(ptPos, reinterpret_cast<LightData*>(apLight->spLight.m_pObject)->f_e0);
        Node* node = reinterpret_cast<Coll*>(self->pBSPortalGraph)->list20.head;
        while (node)
        {
            ItemObj* item = reinterpret_cast<Coll*>(self->pBSPortalGraph)->list20.GetNext(node);
            if (!item)
                continue;
            int idx = item->mapDc.Find(apLight);
            if (!item->m_ac->m_0c->v45(&ptPos) && !item->v68(&pt4Pos))
            {
                if (idx != -1)
                {
                    ((FUN_00b5aea0_self*)&item->mapDc)->RemoveRange(idx, 1);
                    Node* pSubNode = item->listB4.head;
                    while (pSubNode)
                    {
                        ItemObj* pSubItem = item->listB4.GetNext(pSubNode);
                        if (pSubItem && reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kPortals).Find(pSubItem) == -1)
                        {
                            OwnerObj* pOwner = pSubItem->m_104;
                            int iOwnerIndex = pOwner->arr.Find(apLight);
                            if (iOwnerIndex != -1)
                            {
                                ((FUN_00b5aea0_self*)&pSubItem->m_104->arr)->RemoveRange(iOwnerIndex, 1);
                            }
                        }
                    }
                }
            }
            else
            {
                if (idx == -1)
                {
                    item->mapDc.Add(apLight);
                }
                Node* fn = item->listB4.head;
                while (fn)
                {
                    ItemObj* pSubItem = item->listB4.GetNext(fn);
                    if (pSubItem)
                    {
                        if (pSubItem->m_104->arr.FindIdx(apLight) == (unsigned int)-1)
                        {
                            pSubItem->m_104->arr.Add(apLight);
                        }
                        OwnerObj* pOwner = pSubItem->m_104;
                        if (reinterpret_cast<ArrayLikeT<OwnerObj*>&>(apLight->kProcessedNodes).FindIdx(pOwner) == (unsigned int)-1)
                        {
                            AddPortalObject(apLight, pOwner);
                            reinterpret_cast<ArrayLikeT<OwnerObj*>&>(apLight->kProcessedNodes).Add76(pSubItem->m_104);
                        }
                        if (reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kPortals).FindIdx(pSubItem) == (unsigned int)-1)
                        {
                            reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kPortals).Add(pSubItem);
                        }
                    }
                }
                AddPortalObject(apLight, item);
                reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kMultiboundRooms).Add(item);
            }
        }
        for (unsigned int i = 0; i < reinterpret_cast<Coll*>(self->pBSPortalGraph)->count70; i++)
        {
            AddPortalObject(apLight, reinterpret_cast<Coll*>(self->pBSPortalGraph)->arr6c[i]);
        }
        Node* fn = reinterpret_cast<Coll*>(self->pBSPortalGraph)->list14.head;
        while (fn)
        {
            ItemObj* pSubItem = reinterpret_cast<Coll*>(self->pBSPortalGraph)->list14.GetNext(fn);
            if (pSubItem)
            {
                if (pSubItem->m_104->arr.FindIdx(apLight) == (unsigned int)-1)
                {
                    pSubItem->m_104->arr.Add(apLight);
                }
                OwnerObj* pOwner = pSubItem->m_104;
                if (reinterpret_cast<ArrayLikeT<OwnerObj*>&>(apLight->kProcessedNodes).FindIdx(pOwner) == (unsigned int)-1)
                {
                    AddPortalObject(apLight, pOwner);
                    reinterpret_cast<ArrayLikeT<OwnerObj*>&>(apLight->kProcessedNodes).Add76(pSubItem->m_104);
                }
                if (reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kPortals).FindIdx(pSubItem) == (unsigned int)-1)
                {
                    reinterpret_cast<ArrayLikeT<ItemObj*>&>(apLight->kPortals).Add(pSubItem);
                }
            }
        }
        for (unsigned int i = 0; i < ((FUN_00c5b5d0_class*)reinterpret_cast<Coll*>(self->pBSPortalGraph))->BSPortalGraph_GetAlwaysRenderArrayCount(); i++)
        {
            void* pElement = (void*)((FUN_00c5b5a0_cls*)reinterpret_cast<Coll*>(self->pBSPortalGraph))->BSPortalGraph_GetAlwaysRenderAt(i);
            if (pElement)
                AddPortalObject(apLight, pElement);
        }
    }
    else
    {
        if (self != DAT_011f91c8)
        {
            for (; uiIndex < self->m_kChildren.m_usSize; uiIndex++)
            {
                ElemObj* e = reinterpret_cast<ElemObj**>(self->m_kChildren.m_pBase)[uiIndex];
                if (e)
                {
                    void* r = e->vfn3();
                    if (r)
                        AddPortalObject(apLight, r);
                }
            }
        }
        else
        {
            if (self->m_kChildren.m_usSize > 3)
            {
                ElemObj* e = reinterpret_cast<ElemObj**>(self->m_kChildren.m_pBase)[3];
                if (e)
                {
                    void* r = e->vfn3();
                    if (r)
                        AddPortalObject(apLight, r);
                }
            }
            if (self->m_kChildren.m_usSize > 6)
            {
                ElemObj* e = reinterpret_cast<ElemObj**>(self->m_kChildren.m_pBase)[6];
                if (e)
                {
                    void* r = e->vfn3();
                    if (r)
                        AddPortalObject(apLight, r);
                }
            }
        }
        if (reinterpret_cast<Coll*>(self->pBSPortalGraph))
        {
            for (unsigned int i = 0; i < ((FUN_00c5b5d0_class*)reinterpret_cast<Coll*>(self->pBSPortalGraph))->BSPortalGraph_GetAlwaysRenderArrayCount(); i++)
            {
                GetterObj* pElement = (GetterObj*)((FUN_00c5b5a0_cls*)reinterpret_cast<Coll*>(self->pBSPortalGraph))->BSPortalGraph_GetAlwaysRenderAt(i);
                if (pElement && pElement->f_18 == 0)
                    AddPortalObject(apLight, pElement);
            }
        }
    }
    reinterpret_cast<void (__thiscall*)(ShadowSceneLight*)>(&FinishLightGeometry)(apLight);
}
}  // namespace fnv_00b5d300

inline float Larger(float a, float b)
{
    return a > b ? a : b;
}

inline NiPoint3 NiPoint3::operator*(float f) const
{
    NiPoint3 r;
    r.x = x * f; r.y = y * f; r.z = z * f;
    return r;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    NiPoint3 r;
    r.x = x - p.x; r.y = y - p.y; r.z = z - p.z;
    return r;
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    NiPoint3 r;
    r.x = x + p.x; r.y = y + p.y; r.z = z + p.z;
    return r;
}
struct Product
{
    float x, y, z;
    Product(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
};
inline Product ScaleProduct(const NiPoint3& p, float f)
{
    return Product(p.x * f, p.y * f, p.z * f);
}
inline void AddBlend(NiPoint3& a, const Product& b)
{
    a.x = b.x + a.x;
    a.y = a.y + b.y;
    a.z = a.z + b.z;
}
struct Factor
{
    float f;
};
struct BlendColor
{
    float x, y, z;
    BlendColor& operator*=(float f)
    {
        x *= f;
        y *= f;
        z *= f;
        return *this;
    }
    __forceinline BlendColor operator*(float f) const
    {
        BlendColor r = *this;
        r.x *= f;
        r.y *= f;
        r.z *= f;
        return r;
    }
};
struct BlendData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned flags;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    NiPoint3 position;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    float scale;
    int unkc8;
    int unkcc;
    int unkd0;
    BlendColor diffuse;
    float radius;
    int unke4;
    int unke8;
    int unkec;
    NiPoint3 direction;
    float Dimmer() const
    {
        return scale;
    }
    const BlendColor& Diffuse() const
    {
        return diffuse;
    }
    __forceinline float Brightness() const
    {
        BlendColor c = diffuse * scale;
        return (c.x + c.y + c.z) / 3.0;
    }
};

struct BlendNode
{
    BlendNode* next;
    BlendNode* prev;
    ShadowSceneLight* light;
};
extern float DAT_011f9838[100];
extern float DAT_011f96a8[100];
struct BlendDirection : NiPoint3
{
    BlendDirection()
    {}
};
extern const double DAT_010228a0;
extern const double DAT_01012060;
inline ShadowSceneLight* const& NextLight(BlendNode*& pos)
{
    ShadowSceneLight* const& item = pos->light;
    pos = pos->next;
    return item;
}
extern unsigned DAT_011f9e78;
extern BlendDirection DAT_011f99c8[100];

class ShadowSceneBlender : public ShadowSceneNode
{
  public:
    __declspec(noinline) ShadowSceneLight* GetListItemAt(unsigned int);
    unsigned ShadowSceneNode_GetAverageLightPos(const NiPoint3&, const NiPoint3&, NiPoint3&);
};
__declspec(noinline) ShadowSceneLight* ShadowSceneBlender::GetListItemAt(unsigned index)
{
    if (index >= lLightList.count)
        return 0;
    BlendNode* node = reinterpret_cast<BlendNode*>(lLightList.head);
    ShadowSceneLight* light = NextLight(node);
    while (index > 0)
    {
        --index;
        light = NextLight(node);
    }
    return light;
}
// Computes a blended light position from point and normal, storing the result and returning whether any lights were used.
// @fnv 0x00b5bca0
// src: COMMUNITY 0x00b5bca0
unsigned ShadowSceneBlender::ShadowSceneNode_GetAverageLightPos(const NiPoint3& point, const NiPoint3& normal, NiPoint3& result)
{
    BlendData* mainData = reinterpret_cast<BlendData*>(pSunLight->spLight.m_pObject);
    unsigned used = 0;
    NiPoint3 direction;
    memcpy(&direction, &NiPoint3::ZERO, sizeof(direction));
    if (mainData->Brightness() > DAT_010228a0)
    {
        NiPoint3 tmp;
        tmp.x = -mainData->direction.x;
        tmp.y = -mainData->direction.y;
        tmp.z = -mainData->direction.z;
        tmp.Unitize();
        NiPoint3 scaled = tmp * 1000.0f;
        memcpy(&direction, &scaled, sizeof(direction));
        used = 1;
    }
    else
    {
        if (!(DAT_011f9e78 & 1))
            DAT_011f9e78 |= 1;
        NiPoint3 zero;
        memcpy(&zero, &NiPoint3::ZERO, sizeof(zero));
        float maximum = Larger(Larger(zero.x, zero.y), zero.z);
        int positive = 0;
        float total = 0.0f;
        unsigned index = 0;
        ShadowSceneLight* light = GetListItemAt(0);
        while (light)
        {
            if (used >= 100)
                break;
            BlendData* data = reinterpret_cast<BlendData*>(light->spLight.m_pObject);
            if (!(data->flags & 1))
            {
                NiPoint3 delta = data->position - point;
                NiPoint3 unit;
                memcpy(&unit, &delta, sizeof(unit));
                unit.Unitize();
                float dot = normal.x * unit.x + normal.y * unit.y + normal.z * unit.z;
                if (dot < 0.0f)
                    dot = 0.0f;
                float luminance = reinterpret_cast<BlendData*>(light->spLight.m_pObject)->Brightness();
                float lengthSquared = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
                float distance = sqrt(lengthSquared);
                float attenuation = 1.0f - (distance - maximum) / data->radius;
                float lower = attenuation < DAT_01012060 ? 0.0f : attenuation;
                float upper = 1.0 < lower ? 1.0f : lower;
                float weight = upper * dot * luminance;
                DAT_011f96a8[used] = DAT_011f9838[used] = weight;
                if (weight > 0.01f)
                    ++positive;
                total += weight;
                memcpy(&static_cast<NiPoint3&>(DAT_011f99c8[used]), &delta, sizeof(delta));
                ++used;
            }
            ++index;
            unsigned idx = (unsigned short)index;
            if (idx >= lLightList.count)
                break;
            BlendNode* node = reinterpret_cast<BlendNode*>(lLightList.head);
            unsigned remaining = idx;
            ShadowSceneLight* item = NextLight(node);
            while (remaining > 0)
            {
                --remaining;
                item = NextLight(node);
            }
            light = item;
        }
        if (positive > 0)
        {
            for (unsigned i = 0; i < used; ++i)
            {
                float fraction = DAT_011f96a8[i] / total;
                if (fraction > 0.0f)
                    AddBlend(direction, ScaleProduct(DAT_011f99c8[i], fraction));
            }
        }
        else
        {
            const NiPoint3& source = reinterpret_cast<BlendData*>(pSunLight->spLight.m_pObject)->direction;
            NiPoint3 tmp;
            tmp.x = -source.x;
            tmp.y = -source.y;
            tmp.z = -source.z;
            tmp.Unitize();
            NiPoint3 scaled = tmp * 1000.0f;
            memcpy(&direction, &scaled, sizeof(direction));
            used = 1;
        }
    }
    NiPoint3 sum = point + direction;
    memcpy(&result, &sum, sizeof(result));
    return used > 0;
}

extern void __cdecl BSShaderManager_SetShadowSceneNode(int, ShadowSceneNode*);

struct ShadowDtorContext
{
    int unkCtx_000;
    int unkCtx_004;
    int unkCtx_008;
    int unkCtx_00c;
    int unkCtx_010;
    int unkCtx_014;
    int unkCtx_018;
    int unkCtx_01c;
    int unkCtx_020;
    int unkCtx_024;
    int unkCtx_028;
    int unkCtx_02c;
    int unkCtx_030;
    int unkCtx_034;
    int unkCtx_038;
    int unkCtx_03c;
    int unkCtx_040;
    int unkCtx_044;
    int unkCtx_048;
    int unkCtx_04c;
    int unkCtx_050;
    int unkCtx_054;
    int unkCtx_058;
    int unkCtx_05c;
    int unkCtx_060;
    int unkCtx_064;
    int unkCtx_068;
    int unkCtx_06c;
    int unkCtx_070;
    int unkCtx_074;
    int unkCtx_078;
    int unkCtx_07c;
    int unkCtx_080;
    int unkCtx_084;
    int unkCtx_088;
    int unkCtx_08c;
    int unkCtx_090;
    int unkCtx_094;
    int unkCtx_098;
    int unkCtx_09c;
    int unkCtx_0a0;
    int unkCtx_0a4;
    int unkCtx_0a8;
    int unkCtx_0ac;
    int unkCtx_0b0;
    int unkCtx_0b4;
    int unkCtx_0b8;
    int unkCtx_0bc;
    int unkCtx_0c0;
    int unkCtx_0c4;
    int unkCtx_0c8;
    int unkCtx_0cc;
    int unkCtx_0d0;
    int unkCtx_0d4;
    int unkCtx_0d8;
    int unkCtx_0dc;
    int unkCtx_0e0;
    int unkCtx_0e4;
    int unkCtx_0e8;
    int unkCtx_0ec;
    int unkCtx_0f0;
    int unkCtx_0f4;
    int unkCtx_0f8;
    int unkCtx_0fc;
    int unkCtx_100;
    int unkCtx_104;
    int unkCtx_108;
    int unkCtx_10c;
    int unkCtx_110;
    int unkCtx_114;
    int unkCtx_118;
    int unkCtx_11c;
    int unkCtx_120;
    int unkCtx_124;
    int unkCtx_128;
    int unkCtx_12c;
    int unkCtx_130;
    int unkCtx_134;
    int unkCtx_138;
    int unkCtx_13c;
    int unkCtx_140;
    int unkCtx_144;
    int unkCtx_148;
    int unkCtx_14c;
    int unkCtx_150;
    int unkCtx_154;
    int unkCtx_158;
    int unkCtx_15c;
    int unkCtx_160;
    int unkCtx_164;
    int unkCtx_168;
    int unkCtx_16c;
    int unkCtx_170;
    int unkCtx_174;
    int unkCtx_178;
    int unkCtx_17c;
    int unkCtx_180;
    int unkCtx_184;
    int unkCtx_188;
    int unkCtx_18c;
    int unkCtx_190;
    void* unk194;
};
extern ShadowDtorContext* __cdecl BSShaderManager_GetAccumulator();

// Destroys the shadow scene object, clearing its node, light, texture, and list references.
// @fnv 0x00b5e5a0
ShadowSceneNode::~ShadowSceneNode()
{
    ShadowSceneNode* node = ((ShadowSceneNode**)&DAT_011f91c8)[cSceneGraphIndex];
    if (node == (ShadowSceneNode*)this)
    {
        BSShaderManager_SetShadowSceneNode(cSceneGraphIndex, 0);
    }
    if (BSShaderManager_GetAccumulator() && BSShaderManager_GetAccumulator()->unk194 == this)
    {
        BSShaderManager_GetAccumulator()->unk194 = 0;
    }
    RemoveAllLights();
    kShadowLightActiveFenceObject = 0;
    kShadowLightFadingInFenceObject = 0;
    delete pSunLight;
    if (pWindowReflectionEnvMap)
    {
        DAT_011f91a8->AddRenderedTexture(reinterpret_cast<BSRenderedTexture*>(pWindowReflectionEnvMap.m_pObject));
    }
    pWindowReflectionEnvMap = 0;
    lLightQueueAdd.RemoveAll();
    lLightQueueRemove.RemoveAll();
    lLightQueueUpdate.RemoveAll();
    pBSPortalGraph = 0;
    reinterpret_cast<NiPointer<NiRefObject>&>(spCubeMapCamera) = 0;
}
