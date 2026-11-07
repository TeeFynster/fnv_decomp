// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_SHADOWSCENELIGHT_H
#define FNV_SHADOWSCENELIGHT_H

#include "layout_support.h"
#include "NiPoint3.h"
#include "layout_support.h"
class BSMultiBoundNode;
class BSPortal;
class BSPortalGraph;
class BSRenderedTexture;
class BSShaderAccumulator;
class D3DXMATRIX;
class NiAVObject;
class NiCamera;
class NiFrustumPlanes;
class NiLight;
class NiPlane;
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator;
class NiTListItem_NiPointer_NiAVObject___;
class NiTListItem_NiPointer_NiTriBasedGeom___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_NiPointer_NiAVObject___;
class NiTPointerList_NiPointer_NiTriBasedGeom___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___;
class NiTexture;
class NiTriBasedGeom;
class ShadowSceneLight;
class _D3DMATRIX;
#pragma pack(push, 4)
class _D3DMATRIX
{
  public:
    union
    {  // overlapping CodeView storage
        struct
        {
            float _11;  // +0x0, 4 bytes
            float _12;  // +0x4, 4 bytes
            float _13;  // +0x8, 4 bytes
            float _14;  // +0xC, 4 bytes
            float _21;  // +0x10, 4 bytes
            float _22;  // +0x14, 4 bytes
            float _23;  // +0x18, 4 bytes
            float _24;  // +0x1C, 4 bytes
            float _31;  // +0x20, 4 bytes
            float _32;  // +0x24, 4 bytes
            float _33;  // +0x28, 4 bytes
            float _34;  // +0x2C, 4 bytes
            float _41;  // +0x30, 4 bytes
            float _42;  // +0x34, 4 bytes
            float _43;  // +0x38, 4 bytes
            float _44;  // +0x3C, 4 bytes
        };
        float m[4][4];  // +0x0, 64 bytes
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(_D3DMATRIX) == 64);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _11) == 0);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _12) == 4);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _13) == 8);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _14) == 12);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _21) == 16);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _22) == 20);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _23) == 24);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _24) == 28);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _31) == 32);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _32) == 36);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _33) == 40);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _34) == 44);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _41) == 48);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _42) == 52);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _43) == 56);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, _44) == 60);
FNV_STATIC_ASSERT(offsetof(_D3DMATRIX, m) == 0);
#pragma pack(push, 4)
class D3DXMATRIX : public _D3DMATRIX
{
  public:
    // base _D3DMATRIX at +0x0, size 64
    // D3DXMATRIX
    // operator()
    // float* __cdecl D3DXMATRIX::*()
    // const float* __cdecl D3DXMATRIX::*()
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // operator*=
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // D3DXMATRIX& __cdecl D3DXMATRIX::*(float)
    // operator+
    // operator-
    // operator*
    // D3DXMATRIX __cdecl D3DXMATRIX::*(float)
    // int __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
    // int __cdecl D3DXMATRIX::*(const D3DXMATRIX&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(D3DXMATRIX) == 64);
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#include "../../include/NiTPointerAllocator_unsigned_int_.h"
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(
    offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
{
  public:
    NiTListItem_NiPointer_NiTriBasedGeom___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiTriBasedGeom___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___, m_kItemCount) ==
                  8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, const NiPointer<NiTriBasedGeom>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*, const NiPointer<NiTriBasedGeom>&)
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*)
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*&)
    // const NiPointer<NiTriBasedGeom>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*&)
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&)
    // NiPointer<NiTriBasedGeom> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiPointer<NiTriBasedGeom>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<NiTriBasedGeom> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(NiTListItem<NiPointer<NiTriBasedGeom> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___) == 12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_NiTriBasedGeom___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiTriBasedGeom___
{
  public:
    ~NiTPointerList_NiPointer_NiTriBasedGeom___();
    NiTPointerList_NiPointer_NiTriBasedGeom___()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
    void RemoveAll();
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiTriBasedGeom> > at +0x0, size 12
    // NiTPointerList<NiPointer<NiTriBasedGeom> >
    // void __cdecl NiTPointerList<NiPointer<NiTriBasedGeom> >::*()
    // NiTPointerList<NiPointer<NiTriBasedGeom> >& __cdecl NiTPointerList<NiPointer<NiTriBasedGeom> >::*(const NiTPointerList<NiPointer<NiTriBasedGeom> >&)
    // void* __cdecl NiTPointerList<NiPointer<NiTriBasedGeom> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_NiTriBasedGeom___) == 12);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator) ==
                  4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
{
  public:
    NiTListItem_NiPointer_NiAVObject___* m_pkHead;  // +0x0, 4 bytes
    NiTListItem_NiPointer_NiAVObject___* m_pkTail;  // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject_____AntiBloatAllocator
        m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(NiTListItem<NiPointer<NiAVObject> >*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(NiTListItem<NiPointer<NiAVObject> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, NiTListItem<NiPointer<NiAVObject> >*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, NiTListItem<NiPointer<NiAVObject> >*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> > at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, const NiPointer<NiAVObject>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*, const NiPointer<NiAVObject>&)
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*)
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*&)
    // const NiPointer<NiAVObject>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*&)
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&)
    // NiPointer<NiAVObject> __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiPointer<NiAVObject>&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<NiPointer<NiAVObject> >* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(NiTListItem<NiPointer<NiAVObject> >*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___) == 12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_NiAVObject___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_NiAVObject___
{
  public:
    ~NiTPointerList_NiPointer_NiAVObject___();
    NiTPointerList_NiPointer_NiAVObject___()
    {
        m_kItemCount.m_uiCount = 0;
        m_pkHead = 0;
        m_pkTail = 0;
    }
    void RemoveAll();
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,NiPointer<NiAVObject> > at +0x0, size 12
    // NiTPointerList<NiPointer<NiAVObject> >
    // void __cdecl NiTPointerList<NiPointer<NiAVObject> >::*()
    // NiTPointerList<NiPointer<NiAVObject> >& __cdecl NiTPointerList<NiPointer<NiAVObject> >::*(const NiTPointerList<NiPointer<NiAVObject> >&)
    // void* __cdecl NiTPointerList<NiPointer<NiAVObject> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_NiAVObject___) == 12);
#include "../../include/NiPlane.h"
FNV_STATIC_ASSERT(sizeof(NiPlane) == 16);
#include "../../include/NiFrustumPlanes.h"
FNV_STATIC_ASSERT(sizeof(NiFrustumPlanes) == 100);
FNV_STATIC_ASSERT(offsetof(NiFrustumPlanes, m_akPlanes) == 0);
FNV_STATIC_ASSERT(offsetof(NiFrustumPlanes, m_uiActivePlaneMask) == 96);
#pragma pack(push, 4)
class ShadowSceneLight : public NiRefObject
{
  public:
    ShadowSceneLight();
    ~ShadowSceneLight();
    void ClearShadowObjects();
    void AddObject(NiAVObject*);
    void ProcessShadowObject(NiAVObject*);
    void AddShadowObject(NiAVObject*);
    void AddGeometry(NiTriBasedGeom*);
    bool TestSphereFrustum(NiPoint3*);
    bool BoundWithinLightRadius(NiPoint3*, NiLight*, float);
    // base NiRefObject at +0x0, size 8
    int m_iShadowLightState;                                       // +0x8, 4 bytes
    float m_fShadowParameter3;                                     // +0xC, 4 bytes
    D3DXMATRIX m_kShadowMatrix1;                                   // +0x10, 64 bytes
    D3DXMATRIX m_kShadowMatrix2;                                   // +0x50, 64 bytes
    D3DXMATRIX m_kShadowMatrix3;                                   // +0x90, 64 bytes
    float m_fShadowParameter4;                                     // +0xD0, 4 bytes
    float m_fShadowParameter5;                                     // +0xD4, 4 bytes
    float m_fShadowParameter2;                                     // +0xD8, 4 bytes
    float m_fShadowParameter1;                                     // +0xDC, 4 bytes
    NiTPointerList_NiPointer_NiTriBasedGeom___ m_kLightStripList;  // +0xE0, 12 bytes
    bool m_bSkipLightObject;                                       // +0xEC, 1 bytes
    bool m_bLightFlag1;                                            // +0xED, 1 bytes
    unsigned char layoutPaddingEE[2];
    ShadowScenePointer<NiTexture> m_spShadowTexture;  // +0xF0, 4 bytes
    bool m_bLightFlag0;                               // +0xF4, 1 bytes
    bool m_bLightFlag2;                               // +0xF5, 1 bytes
    unsigned char layoutPaddingF6[2];
    ShadowScenePointer<NiLight> m_pMenuLight;  // +0xF8, 4 bytes
    bool m_bIsPipLight;                        // +0xFC, 1 bytes
    unsigned char layoutPaddingFD[3];
    NiPoint3 m_kPipLightPosition;                                    // +0x100, 12 bytes
    ShadowScenePointer<BSRenderedTexture> m_spLightRenderedTexture;  // +0x10C, 4 bytes
    unsigned short m_usEnabledState;                                 // +0x110, 2 bytes
    unsigned char layoutPadding112[2];
    ShadowScenePointer<NiAVObject> m_spSceneObject;  // +0x114, 4 bytes
    bool m_bLightFlag3;                              // +0x118, 1 bytes
    unsigned char layoutPadding119[3];
    float m_fSpotlightParameter;  // +0x11C, 4 bytes
    float m_kShadowLightData;     // +0x120, 4 bytes
    bool m_bLightFlag4;           // +0x124, 1 bytes
    unsigned char layoutPadding125[3];
    ShadowScenePointer<NiAVObject> m_pLightNode;                // +0x128, 4 bytes
    NiTPointerList_NiPointer_NiAVObject___ m_kSceneObjectList;  // +0x12C, 12 bytes
    void* m_pShadowData;                                        // +0x138, 4 bytes
    ShadowScenePointer<NiTriBasedGeom> m_spShadowGeometry;      // +0x13C, 4 bytes
    ShadowScenePointer<NiCamera> m_pCamera;                     // +0x140, 4 bytes
    NiFrustumPlanes m_kFrustumPlanes;                           // +0x144, 100 bytes
    float m_afShadowFrustumData[24];                            // +0x1A8, 96 bytes
    bool m_bShadowFrustumInitialized;                           // +0x208, 1 bytes
    unsigned char layoutPadding209[3];
    ShadowScenePointer<BSShaderAccumulator> m_spShadowShaderAccumulator;  // +0x20C, 4 bytes
    ShadowSceneArray<BSMultiBoundNode*> m_kMultiBoundNodes;               // +0x210, 16 bytes
    ShadowSceneArray<BSPortal*> m_kShadowLightData1;                      // +0x220, 16 bytes
    ShadowSceneArray<NiNode*> m_kShadowLightData2;                        // +0x230, 16 bytes
    BSPortalGraph* m_pPortalConnectivityGraphInfo;                                          // +0x240, 4 bytes
    unsigned char layoutPadding244[12];
    // ShadowSceneLight
    // void __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*(NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiTriBasedGeom*)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiTriBasedGeom*, void*)
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*(const NiBound&, NiLight*, float)
    // bool __cdecl ShadowSceneLight::*(const NiBound&)
    // void __cdecl ShadowSceneLight::*(NiLight*)
    // NiLight* __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*(NiCamera*)
    // float __cdecl ShadowSceneLight::*(NiPoint3, NiLight*)
    // float __cdecl ShadowSceneLight::*(NiPoint3, NiPoint3, NiLight*)
    // float __cdecl ShadowSceneLight::*(NiBound*)
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(NiPoint3)
    // NiPoint3 __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSRenderedTexture*)
    // BSRenderedTexture* __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(bool)
    // unsigned short __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSCubeMapCamera*, NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float)
    // float __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float)
    // float __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*()
    // NiLines* __cdecl ShadowSceneLight::*(float, float)
    // void __cdecl ShadowSceneLight::*(BSShaderLightingProperty*, NiPoint3)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // NiAVObject* __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float, bool)
    // bool __cdecl ShadowSceneLight::*()
    // float __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // const NiFrustumPlanes* __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(float*)
    // float* __cdecl ShadowSceneLight::*()
    // bool __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSCullingProcess&, int)
    // void __cdecl ShadowSceneLight::*(BSCullingProcess&, int)
    // BSSimpleArray<BSMultiBoundNode *,1024>& __cdecl ShadowSceneLight::*()
    // BSSimpleArray<BSPortal *,1024>& __cdecl ShadowSceneLight::*()
    // BSSimpleArray<NiNode *,1024>& __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(BSPortalGraph*)
    // BSPortalGraph* __cdecl ShadowSceneLight::*()
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // void __cdecl ShadowSceneLight::*(NiNode*)
    // void __cdecl ShadowSceneLight::*(bool)
    // bool __cdecl ShadowSceneLight::*(NiBound, NiCullingProcess&, unsigned short)
    // bool __cdecl ShadowSceneLight::*(NiCamera*, NiCamera*)
    // void __cdecl ShadowSceneLight::*(BSCubeMapCamera*, NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiCullingProcess&)
    // void __cdecl ShadowSceneLight::*(NiAVObject*)
    // ShadowSceneLight& __cdecl ShadowSceneLight::*(const ShadowSceneLight&)
    // void __cdecl ShadowSceneLight::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShadowSceneLight) == 592);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_iShadowLightState) == 8);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_fShadowParameter3) == 12);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kShadowMatrix1) == 16);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kShadowMatrix2) == 80);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kShadowMatrix3) == 144);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_fShadowParameter4) == 208);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_fShadowParameter5) == 212);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_fShadowParameter2) == 216);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_fShadowParameter1) == 220);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kLightStripList) == 224);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bSkipLightObject) == 236);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bLightFlag1) == 237);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_spShadowTexture) == 240);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bLightFlag0) == 244);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bLightFlag2) == 245);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_pMenuLight) == 248);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bIsPipLight) == 252);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kPipLightPosition) == 256);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_spLightRenderedTexture) == 268);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_usEnabledState) == 272);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_spSceneObject) == 276);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bLightFlag3) == 280);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_fSpotlightParameter) == 284);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kShadowLightData) == 288);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bLightFlag4) == 292);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_pLightNode) == 296);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kSceneObjectList) == 300);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_pShadowData) == 312);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_spShadowGeometry) == 316);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_pCamera) == 320);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kFrustumPlanes) == 324);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_afShadowFrustumData) == 424);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_bShadowFrustumInitialized) == 520);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_spShadowShaderAccumulator) == 524);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kMultiBoundNodes) == 528);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kShadowLightData1) == 544);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_kShadowLightData2) == 560);
FNV_STATIC_ASSERT(offsetof(ShadowSceneLight, m_pPortalConnectivityGraphInfo) == 576);
#endif
