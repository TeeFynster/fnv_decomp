
// src/fallout/interface/interfacemanager_o2_variant_fpfast_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /fp:fast (unit src/fallout/interface/interfacemanager_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/interfacemanager_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/interfacemanager.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../include/NiBound.h"
#include "../../../include/NiRefObject.h"
#include "../../../include/NiPointer.h"
extern "C" __declspec(dllimport) unsigned int __stdcall XInputGetState(unsigned int dwUserIndex, void* pState);
unsigned int __stdcall XInputGetState_009f996e(unsigned int dwUserIndex, void* pState);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)))
        DeleteThis();
}
template <class T> inline NiPointer<T>::NiPointer(T* p) : m_pObject(p)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* p)
{
    if (m_pObject != p)
    {
        if (p)
            p->IncRefCount();
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = p;
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}
template <class T> inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}
struct Item : NiRefObject
{
    virtual void Unused2();
    virtual int IsVisibleThing();
    unsigned int u08, u0c, u10, u14, u18, u1c;
    NiBound* bound;
    unsigned int u24, u28, u2C, u30, u34, u38, u3C, u40;
    unsigned int u44, u48, u4C, u50, u54, u58, u5C, u60;
    unsigned int u64, u68, u6C, u70, u74, u78, u7C, u80;
    unsigned int u84, u88, u8C, u90, u94, u98, u9C, uA0;
    unsigned int uA4, uA8, uAC, uB0, uB4, uB8, uBC, uC0;
    unsigned int uC4, uC8, uCC, uD0, uD4, uD8, uDC, uE0;
    unsigned int uE4, uE8;
    bool flag_ec;
    unsigned int uF0, uF4, uF8;
    bool flag_fc;
    unsigned int u100, u104, u108;
    NiPointer<NiRefObject> field_10c;
};
template <class T> struct TListItem
{
    TListItem<T>* m_pkNext;
    TListItem<T>* m_pkPrev;
    T m_element;
};
template <class T> struct TPtrList
{
    TListItem<T>* m_pkHead;
    TListItem<T>* m_pkTail;
    unsigned int m_uiCount;
    void* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(void*& pos) const
    {
        T& e = ((TListItem<T>*)pos)->m_element;
        pos = ((TListItem<T>*)pos)->m_pkNext;
        return e;
    }
    void RemoveAll();
};
#include "../../../include/BSTextureManager.h"
struct Sub1e0
{
    void BSPortalGraph_ProcessQueue();
};
struct GlobalObject_0096a2d0
{
    void* owner;
    int count;
    void Lock(const char*);
    void Unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern BSTextureManager* DAT_011f91a8;
extern NiBound DAT_011f4288;
extern float DAT_010231d0;
__forceinline NiBound* BoundOf(Item* i)
{
    NiBound* b = i->bound;
    return b ? b : &DAT_011f4288;
}
extern GlobalObject_0096a2d0 DAT_011f9ea0, DAT_011f9ec0;
struct Owner
{
    unsigned int u0, u4, u8, uC, u10, u14, u18, u1C;
    unsigned int u20, u24, u28, u2C, u30, u34, u38, u3C;
    unsigned int u40, u44, u48, u4C, u50, u54, u58, u5C;
    unsigned int u60, u64, u68, u6C, u70, u74, u78, u7C;
    unsigned int u80, u84, u88, u8C, u90, u94, u98, u9C;
    unsigned int uA0, uA4, uA8, uAC, uB0, uB4, uB8, uBC;
    unsigned int uC0, uC4, uC8, uCC, uD0, uD4, uD8, uDC;
    unsigned int uE0;
    TPtrList<Item*> list0e4;
    TPtrList<Item*> list0f0;
    TPtrList<Item*> list0fc;
    TPtrList<Item*> list108;
    TPtrList<Item*> list114;
    unsigned int u120, u124, u128, u12C, u130, u134, u138, u13C;
    unsigned int u140, u144, u148, u14C, u150, u154, u158, u15C;
    unsigned int u160, u164, u168, u16C, u170, u174, u178, u17C;
    unsigned int u180, u184, u188, u18C, u190, u194, u198, u19C;
    unsigned int u1A0, u1A4, u1A8, u1AC, u1B0, u1B4, u1B8, u1BC;
    unsigned int u1C0, u1C4, u1C8, u1CC, u1D0, u1D4, u1D8, u1DC;
    Sub1e0* field_1e0;
    unsigned int u1E4, u1E8, u1EC, u1F0, u1F4, u1F8;
    bool flag_1fc;
    void FUN_00b5cd00(Item*);
    void FUN_00b5eca0(Item*);
    void ShadowSceneNode_UpdateQueuedDynamicLight(Item*);
    void FUN_00b5d300(Item*);
    void ShadowSceneNode_RemoveQueuedLight(NiPointer<Item>&);
    void ShadowSceneNode_ProcessQueuedLights();
};
void ShadowSceneNode_UpdateQueuedObjectLightingStart(Item*, Owner*, int, bool);
// @fnv 0x00b5fd60
// src: XBOX_PDB 0x00b5fd60
void Owner::ShadowSceneNode_ProcessQueuedLights()
{
    DAT_011f9ea0.Lock(0);
    void* pos = list0e4.GetHeadPos();
    while (pos)
    {
        Item* item = list0e4.GetNext(pos);
        if (item)
        {
            if (item->flag_ec)
                FUN_00b5cd00(item);
            else
                FUN_00b5eca0(item);
        }
    }
    pos = list0fc.GetHeadPos();
    while (pos)
    {
        Item* item = list0fc.GetNext(pos);
        if (item)
        {
            if (item->flag_fc)
                ShadowSceneNode_UpdateQueuedDynamicLight(item);
            else
                FUN_00b5d300(item);
        }
    }
    pos = list0f0.GetHeadPos();
    while (pos)
    {
        Item* item = list0f0.GetNext(pos);
        if (item)
        {
            if (item->flag_ec)
            {
                NiPointer<Item> spItem = item;
                if (spItem)
                {
                    DAT_011f91a8->BSTextureManager_ReturnFrustumShadowTexture(spItem->field_10c);
                    spItem->field_10c = 0;
                    ShadowSceneNode_RemoveQueuedLight(spItem);
                }
            }
            else
            {
                NiPointer<Item> spItem = item;
                ShadowSceneNode_RemoveQueuedLight(spItem);
            }
        }
    }
    DAT_011f9ec0.Lock(0);
    pos = list114.GetHeadPos();
    while (pos)
    {
        Item* item = list114.GetNext(pos);
        if (item)
        {
            if (item->IsVisibleThing() && BoundOf(item)->m_fRadius < DAT_010231d0)
                ShadowSceneNode_UpdateQueuedObjectLightingStart(item, this, 1, true);
            else
                ShadowSceneNode_UpdateQueuedObjectLightingStart(item, this, 1, false);
        }
    }
    pos = list108.GetHeadPos();
    while (pos)
    {
        Item* item = list108.GetNext(pos);
        if (item)
        {
            if (item->IsVisibleThing() && BoundOf(item)->m_fRadius < DAT_010231d0)
                ShadowSceneNode_UpdateQueuedObjectLightingStart(item, this, 0, true);
            else
                ShadowSceneNode_UpdateQueuedObjectLightingStart(item, this, 0, false);
        }
    }
    if (field_1e0)
        field_1e0->BSPortalGraph_ProcessQueue();
    list0e4.RemoveAll();
    list0f0.RemoveAll();
    list0fc.RemoveAll();
    list108.RemoveAll();
    list114.RemoveAll();
    flag_1fc = true;
    DAT_011f9ec0.Unlock();
    DAT_011f9ea0.Unlock();
}
