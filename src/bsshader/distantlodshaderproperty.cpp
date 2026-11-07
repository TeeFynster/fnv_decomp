
// src/bsshader/distantlodshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/distantlodshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSStream.h"
#include "../../include/NiAlphaProperty.h"
#include "../../include/NiColorA.h"
#include "../../include/NiObject.h"
#include "../../include/NiProperty.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiStream.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiTriShapeData.h"
#include "../../include/NiPoint3.h"
#include "../../include/Vec4.h"

struct NiDynamicTriShapeData : NiTriShapeData
{
    unsigned short unk58;
    unsigned short unk5a;
    NiDynamicTriShapeData(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*, unsigned short, NiGeometryData__DataFlags,
                 unsigned short, unsigned short*, unsigned short, unsigned short);
};
// Constructs the base NiTriShapeData from the given arguments, then stores p1, p8 and p8*3 into unk08, unk40 and unk44 and p10/p11 into unk58/unk5a.
// @fnv 0x00a816a0
NiDynamicTriShapeData::NiDynamicTriShapeData(unsigned short p1, NiPoint3* p2, NiPoint3* p3, NiColorA* p4, NiPoint2* p5,
                           unsigned short p6, NiGeometryData__DataFlags aeDataFlags, unsigned short p8,
                           unsigned short* p9, unsigned short p10, unsigned short p11)
    : NiTriShapeData(p10, p2, p3, reinterpret_cast<NiColorA*>(p4), p5, p6, static_cast<unsigned int>(aeDataFlags), p11, p9), unk58(p10), unk5a(p11)
{
    m_usVertices = p1;
    m_usTriangles = p8;
    m_uiTriListLength = p8 * 3;
}

struct S_Pool
{
    void* Alloc(unsigned int size);
    void Free(void* p);
};

extern S_Pool DAT_011f6238;

struct S_A
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
    S_A();
    void Release()
    {
        FUN_00b6f0b0();
        DAT_011f6238.Free(this);
    }
    void FUN_00b6f0b0();
    void BSTextureManager_PrecreateTextures(unsigned int v);
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Alloc(n);
    }
};

struct S_B
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
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    S_B();
    void Release()
    {
        FUN_00b97690();
        DAT_011f6238.Free(this);
    }
    void FUN_00b97690();
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Alloc(n);
    }
};

extern unsigned char DAT_011f91c6;
extern S_A* DAT_011f91a8;
extern S_B* DAT_011f91ac;
extern unsigned int DAT_011f91e0;
extern unsigned int DAT_011f9508;

void InitRenderSystem();
void ClearAllCachedStates();
void ParticleShader_Free();
void BoltShader_Free();
void ClearRefObject();

// @fnv 0x00b578a0
// src: COMMUNITY 0x00b578a0
void BSShaderManager_Reinitialize()
{
    if (DAT_011f91c6 == 0)
    {
        InitRenderSystem();
        return;
    }

    ClearAllCachedStates();
    ParticleShader_Free();
    BoltShader_Free();
    ClearRefObject();

    if (DAT_011f91ac != 0)
    {
        DAT_011f91ac->Release();
        DAT_011f91ac = 0;
    }
    if (DAT_011f91a8 != 0)
    {
        DAT_011f91a8->Release();
        DAT_011f91a8 = 0;
    }

    DAT_011f91e0 = 0;
    DAT_011f91a8 = new S_A;

    if (DAT_011f9508 != 0)
    {
        DAT_011f91ac = new S_B;
    }

    DAT_011f91a8->BSTextureManager_PrecreateTextures(DAT_011f9508);
}

extern unsigned int DAT_011f9640;

// Exe 0x00b59ae0: unit-local ListNode view; declarations and layout are preserved.
struct DistantlodshaderpropertyListNodeView
{
    DistantlodshaderpropertyListNodeView* next;
    unsigned int m_04;
    unsigned int key;
};

struct KeyedList
{
    DistantlodshaderpropertyListNodeView* first;
    void __thiscall AllocateStorage_00b584e0(unsigned int* key);
    bool Find(const unsigned int& k, DistantlodshaderpropertyListNodeView** out)
    {
        DistantlodshaderpropertyListNodeView* n = first;
        if (n == 0)
        {
            return false;
        }
        do
        {
            unsigned int* item = &n->key;
            *out = n;
            n = n->next;
            if (*(const volatile unsigned int*)&k == *item)
            {
                return true;
            }
        } while (n);
        return false;
    }
};

struct FnvOwner
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    KeyedList m_1c;
    void __thiscall DistantLODGroup_Add(Vec4* v, unsigned int key);
    void __thiscall DistantLODGroup_UpdateGroupBound();
};

struct ObjR
{
    void __thiscall FUN_00a53c30();
};

struct ObjA4
{
    unsigned int m_00;
    unsigned int m_04;
    void* m_08;
};

struct Obj3
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
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
};

unsigned short __cdecl GetOrCreateItem(ObjA4* a4, void* a1, FnvOwner** out, Obj3* a3);
ObjR* __stdcall Object_GetOrCreateRenderItemCache(void* v, FnvOwner** out);

// Passes Vec4 values assembled from a5 and a6 to the located object, then inserts key when absent from its KeyedList.
// @fnv 0x00b59ae0
// src: XBOX_PDB 0x00b59ae0
void __cdecl DistantLODShaderProperty_AddDistantLOD(void* a1, unsigned int key, Obj3* apObj3, ObjA4* apObjA4, NiPoint3* apPoints, float* a6,
                          unsigned short count)
{
    DAT_011f9640 += count;
    int iIndex = 0;
    int i = 0;

    FnvOwner* pOwner;
    while (count > 0)
    {
        pOwner = 0;
        unsigned short n = GetOrCreateItem(apObjA4, a1, &pOwner, apObj3);
        if (pOwner == 0)
        {
            return;
        }
        for (iIndex = 0; iIndex < (int)n; ++iIndex, ++i)
        {
            if (!(count > 0))
                break;
            Vec4 v;
            v.x = apPoints[i].x;
            v.y = apPoints[i].y;
            v.z = apPoints[i].z;
            v.w = a6[i];
            pOwner->DistantLODGroup_Add(&v, key);
            --count;
        }
        pOwner->DistantLODGroup_UpdateGroupBound();
        iIndex = 0;
    }

    apObj3->v47();
    pOwner = 0;
    ObjR* r = Object_GetOrCreateRenderItemCache(apObjA4->m_08, &pOwner);
    r->FUN_00a53c30();

    KeyedList* pKeyedList = &pOwner->m_1c;
    DistantlodshaderpropertyListNodeView* node;
    if (!pKeyedList->Find(key, &node) || node == 0)
    {
        pKeyedList->AllocateStorage_00b584e0(&key);
    }
}

#include <windows.h>
#include "../../include/Bound.h"
#include "../../include/MemoryManager.h"

// Keep the original inline reference release used by these container wrappers.
__forceinline void ReleaseContainerReference(NiRefObject* object) throw()
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

struct S_00b6f0b0_Ptr
{
    NiRefObject* m_pObject;
    S_00b6f0b0_Ptr(NiRefObject* p = 0) throw() : m_pObject(p)
    {}
    ~S_00b6f0b0_Ptr()
    {
        if (m_pObject)
            ReleaseContainerReference(m_pObject);
    }
    S_00b6f0b0_Ptr& operator=(const S_00b6f0b0_Ptr& p) throw()
    {
        if (m_pObject != p.m_pObject)
        {
            if (m_pObject)
                ReleaseContainerReference(m_pObject);
            m_pObject = p.m_pObject;
        }
        return *this;
    }
    static void operator delete(void* p) throw()
    {
        DAT_011f6238.Free(p);
    }
};
struct S_00b6f0b0_Node
{
    S_00b6f0b0_Node* next;
    S_00b6f0b0_Node* prev;
    S_00b6f0b0_Ptr* item;
};
struct S_00b6f0b0_Lock
{
    int owner;
    void BSSpinLock_Lock(const char* s) throw();
};
extern S_00b6f0b0_Lock DAT_011c5f80;
extern S_00b6f0b0_Node* DAT_011c5f58;
extern int DAT_011c5f84;
extern char DAT_011a2fe4;
extern int DAT_011f4748;

struct S_ReturnPtr
{
    NiRefObject* object;
};
struct S_00b6f0b0_ListA
{
    int head;
    int tail;
    unsigned int count;
    void PopBack(S_ReturnPtr& result) throw();
    ~S_00b6f0b0_ListA();  // FUN_00e74d40
};
struct S_00b6f0b0_ListE
{
    int head;
    int tail;
    unsigned int count;
    S_00b6f0b0_Ptr PopFront() throw();
    ~S_00b6f0b0_ListE();  // FUN_00b5c7c0
};
struct S_00b6f0b0_ListC
{
    S_00b6f0b0_Node* head;
    S_00b6f0b0_Node* tail;
    unsigned int count;
    ~S_00b6f0b0_ListC() throw();  // FUN_00b71300
};
struct S_00b6f0b0_Base
{
    void ResizeActivePool(int a, int b) throw();
};

struct FUN_00b6f0b0 : S_00b6f0b0_Base
{
    S_00b6f0b0_ListE m0[5];
    S_00b6f0b0_ListE m3c[5];
    S_00b6f0b0_ListC m78;
    S_00b6f0b0_ListC m84;
    S_00b6f0b0_ListA m90;
    S_00b6f0b0_ListA m9c;
    S_00b6f0b0_Ptr ma8;
    S_00b6f0b0_Ptr mac;
    ~FUN_00b6f0b0();
};

// Releases container references, recycles nodes from m84 and m78, and clears ma8 and mac.
// @fnv 0x00b6f0b0
FUN_00b6f0b0::~FUN_00b6f0b0()
{
    S_ReturnPtr result90;
    {
        S_ReturnPtr result9c;
        for (unsigned int n = m9c.count; n; n = m9c.count)
        {
            m9c.PopBack(result9c);
            if (result9c.object)
                ReleaseContainerReference(result9c.object);
        }
        while (m90.count)
        {
            m90.PopBack(result90);
            if (result90.object)
                ReleaseContainerReference(result90.object);
        }
    }
    for (unsigned int n = m84.count; n; n = m84.count)
    {
        S_00b6f0b0_Ptr* slot = m84.head->item;
        *slot = S_00b6f0b0_Ptr(0);
        S_00b6f0b0_Node* node = m84.head;
        m84.head = node->next;
        if (m84.head)
            m84.head->prev = 0;
        else
            m84.tail = 0;
        node->item = 0;
        DAT_011c5f80.BSSpinLock_Lock(0);
        node->prev = 0;
        node->next = DAT_011c5f58;
        if (--DAT_011c5f84 == 0)
        {
            DAT_011c5f58 = node;
            DAT_011c5f80.owner = 0;
        }
        else
        {
            DAT_011c5f58 = node;
        }
        m84.count--;
        delete slot;
    }

    while (m78.count)
    {
        S_00b6f0b0_Ptr* slot = m78.head->item;
        *slot = S_00b6f0b0_Ptr(0);
        S_00b6f0b0_Node* node = m78.head;
        m78.head = node->next;
        if (m78.head)
            m78.head->prev = 0;
        else
            m78.tail = 0;
        node->item = 0;
        DAT_011c5f80.BSSpinLock_Lock(0);
        node->prev = 0;
        node->next = DAT_011c5f58;
        if (--DAT_011c5f84 == 0)
        {
            DAT_011c5f58 = node;
            DAT_011c5f80.owner = 0;
        }
        else
        {
            DAT_011c5f58 = node;
        }
        m78.count--;
        delete slot;
    }

    if (DAT_011a2fe4 == 0)
        ResizeActivePool(DAT_011f4748, 0);
    for (int i = 0; i < 5; i++)
    {
        while (m0[i].count)
            m0[i].PopFront();
    }
    ma8 = S_00b6f0b0_Ptr(0);
    mac = S_00b6f0b0_Ptr(0);
}

extern "C" void _ReadWriteBarrier();

inline void* operator new[](unsigned int n)
{
    MemoryManager* manager = ((MemoryManager*)&DAT_011f6238);
    void* result = manager->Allocate(n);
    return result;
}

inline void* NiPoint2::operator new[](size_t n)
{
    return ((MemoryManager*)&DAT_011f6238)->Allocate(n);
}
inline NiColorA::NiColorA(float red, float green, float blue, float alpha)
    : r(red), g(green), b(blue), a(alpha) {}
inline BSStream::BSStream() { unk5c4 = unk5c8 = 0; }
inline NiAlphaProperty::NiAlphaProperty()
{
    m_usAlphaArg = 0xec;
    m_ucAlphaArg2 = 0;
}

extern NiRTTI g_011f4a20, g_011f4a88, g_011f4a70, g_011f4aa0;

extern int DAT_011f91c0;

extern volatile long DAT_011f4400;

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

inline NiRefObject::NiRefObject() : m_uiRefCount(0)
{
    InterlockedIncrement(&DAT_011f4400);
}

template <class T> struct Ref
{

    T* ptr;

    Ref() : ptr(0)
    {}

    Ref(T* p) : ptr(p)
    {
        if (ptr)
            InterlockedIncrement((volatile long*)&ptr->m_uiRefCount);
    }

    Ref(const Ref& r) : ptr(r.ptr)
    {
        if (ptr)
            InterlockedIncrement((volatile long*)&ptr->m_uiRefCount);
    }

    __forceinline ~Ref()
    {
        T* old = ptr;
        if (old && !InterlockedDecrement((volatile long*)&old->m_uiRefCount))
            old->DeleteThis();
    }

    __forceinline Ref& operator=(T* p)
    {

        T* old = ptr;

        if (old != p)
        {

            if (old && !InterlockedDecrement((volatile long*)&old->m_uiRefCount))
                old->DeleteThis();

            ptr = p;
            if (p)
                InterlockedIncrement((volatile long*)&p->m_uiRefCount);
        }
        return *this;
    }

    T* operator->() const
    {
        return ptr;
    }

    operator T*() const
    {
        return ptr;
    }

    __forceinline Ref& operator=(const Ref& r)
    {
        return *this = r.ptr;
    }
};

// Shader texture query occupies virtual slot 61 in the game's shader property.
__forceinline NiProperty* GetShaderTexture(NiProperty* property, unsigned int index, unsigned int flags)
{
    typedef NiProperty* (__thiscall *Query)(NiProperty*, unsigned int, unsigned int);
    return ((Query*)*(void**)property)[61](property, index, flags);
}

struct ShaderProperty : NiProperty
{
    unsigned int unk18;
    unsigned int kind;
    __forceinline unsigned int IsTree() const
    {
        unsigned int type = kind;
        unsigned int b = type == 11;
        return b;
    }
};

struct GeometryData : NiObject
{

    unsigned short vertices, unk0a;
    unsigned int unk0c;

    Bound bound;

    NiPoint3* positions;
    NiPoint3* normals;
    NiColorA* colors;
    NiPoint2* texcoords;

    unsigned int unk30, unk34, unk38, unk3c;

    unsigned short triangles, unk42;
    unsigned int indexCount;
    unsigned short* stripLengths;

    __forceinline Bound GetBound() const
    {
        return bound;
    }

    unsigned short* FUN_00a7b850();

    unsigned short* FUN_00a75f10();
};

struct Scene : NiObject
{

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

    Scene** children;

    unsigned short capacity, count;

    unsigned int unk0a8;

    unsigned int unk0ac;

    unsigned int unk0b0;

    unsigned int unk0b4;

    GeometryData* data;

    NiProperty* FUN_00a59d30(int);

    void NiAVObject_RemoveProperty(unsigned int);
};

struct Resource : NiRefObject
{

    Ref<NiRefObject> data;
    bool strips;
    unsigned char unk0d;
    unsigned short unk0e;

    float* ids;
    unsigned int vertices;

    Ref<NiProperty> texture;
    Ref<NiProperty> alpha;
    Ref<NiProperty> opaque;
    Ref<NiProperty> extra;

    float radius;
    unsigned int instances;
    bool node;
    unsigned char unk31;
    unsigned short step;

    Resource()
    {}

    virtual void v00();

    static void* operator new(unsigned int);
};

struct CacheEntry
{
    CacheEntry* next;
    void* key;
    Ref<Resource> value;
};

struct Cache
{

    virtual void v00();

    virtual unsigned int Hash(void*);

    virtual bool Equal(void*, void*);

    unsigned int bucketCount;

    CacheEntry** buckets;

    unsigned int size;

    __declspec(noinline) bool FUN_00e92760(void*, Ref<Resource>*);

    void InsertOrAssign(void*, Ref<Resource>);
};

bool Cache::FUN_00e92760(void* key, Ref<Resource>* out)
{

    CacheEntry* entry = buckets[Hash(key)];

    while (entry)
    {

        if (Equal(key, entry->key))
        {
            *out = entry->value;
            return true;
        }

        entry = entry->next;
    }

    return false;
}

Cache* GetNiTStringMap();

struct Input
{
    const char* path;
    Scene* scene;
    void* key;
};

struct UnsignedShortBuffer : NiRefObject
{

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

    UnsignedShortBuffer(unsigned short, NiPoint3*, NiPoint3*, NiColorA*, NiPoint2*, unsigned short,
                        NiGeometryData__DataFlags, unsigned short, unsigned short, unsigned short*, unsigned short*,
                        unsigned short, unsigned short);

    static void* operator new(unsigned int);
};

inline void* operator new(unsigned int n)
{
    return Resource::operator new(n);
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

int __cdecl PrintError(char*, unsigned int, const char*, ...);

__forceinline bool IsKindOfType(NiObject* p, const NiRTTI* type)
{

    const NiRTTI* r = p->GetRTTI();

    while (r)
    {
        if (r == type)
            return true;
        r = r->m_pBaseRTTI;
    }

    return false;
}

// Loads a distant LOD NIF, clones its geometry into a multi-instance buffer with instance IDs, and caches the resulting Resource under the input key.
// @fnv 0x00b587c0
// src: COMMUNITY 0x00b587c0
Resource* __cdecl DistantLODShaderProperty_GetCachedGeometry(Input* input)
{

    if (DAT_011f91c0 == 0)
        return 0;

    Scene* geometry = 0;

    BSStream stream;

    if (input->key == 0)
        return 0;

    Ref<Resource> cachedResource;

    if (!GetNiTStringMap()->FUN_00e92760(input->key, &cachedResource))
    {

        if (!input->scene && input->path && stream.BSStream_Load(input->path, false))
        {

            // The top-level object array is at stream offset 0x220.
            Scene* loaded = reinterpret_cast<Scene**>(stream.m_kTopObjects.m_pBase)[0];

            if (loaded)
                input->scene = (Scene*)loaded->IsSceneNode();
        }

        if (input->scene)
        {

            Scene* rootNode = input->scene;

            while (!geometry)
            {

                if (!rootNode)
                    break;

                for (unsigned int child = 0; child < rootNode->count; child++)
                {

                    Scene* object = rootNode->children[child];

                    if (object)
                    {
                        geometry = (Scene*)object->IsGeometry();
                        if (geometry)
                            break;
                    }
                }
            }

            {

                NiObject* stripShape;
                if (geometry == 0)
                    stripShape = 0;
                else
                    stripShape = geometry->DynamicCast(&g_011f4a20);

                unsigned short vertexCount = 0;

                unsigned short instances;
                if (DAT_011f91c0 >= 2)
                    instances = 228;
                else
                    instances = 80;

                unsigned short sourceIndexCount = 0;

                bool isStrip;

                NiRefObject* combinedData = 0;

                float* instanceIds = 0;

                unsigned short indexStep;

                indexStep = 0;

                if (stripShape == 0)
                {

                    isStrip = false;

                    NiTriShapeData* source;

                    if (geometry->data == 0)
                        source = 0;
                    else
                        source = (NiTriShapeData*)geometry->data->DynamicCast(&g_011f4a88);

                    NiPoint3* srcPositions;

                    srcPositions = source->m_pkVertex;

                    vertexCount = source->m_usVertices;

                    NiPoint3* srcNormals;

                    srcNormals = source->m_pkNormal;

                    unsigned int storedIndexCount = source->m_uiTriListLength;

                    NiColorA* srcColors = reinterpret_cast<NiColorA*>(source->m_pkColor);

                    NiPoint2* srcUVs;

                    srcUVs = source->m_pkTexture;

                    unsigned short* srcIndices = source->GetTriangleList();

                    unsigned short maxCopies = (unsigned short)(65535 / (int)vertexCount);

                    if ((unsigned short)instances >= maxCopies)
                        instances = maxCopies;

                    sourceIndexCount = (unsigned short)storedIndexCount;

                    maxCopies = (unsigned short)(65535 / (int)sourceIndexCount);

                    if ((unsigned short)instances >= maxCopies)
                        instances = maxCopies;

                    int copyCount = (int)instances;
                    int totalVertices = (int)instances * (int)vertexCount;

                    NiPoint3* positions = new NiPoint3[totalVertices];

                    NiPoint3* normals = new NiPoint3[totalVertices];

                    NiColorA* colors = new NiColorA[totalVertices];

                    NiPoint2* uvs = new NiPoint2[totalVertices];

                    instanceIds = new float[totalVertices];

                    int indexCount = (int)sourceIndexCount;
                    unsigned short* indices = new unsigned short[indexCount * (int)copyCount];

                    int writtenIndices;

                    writtenIndices = 0;

                    for (int instance = 0; instance < (int)instances; instance++)
                    {

                        int vertexOffset = instance * vertexCount;

                        for (int vertex = 0; vertex < (int)vertexCount; vertex++)
                        {

                            int offset = vertexOffset + vertex;

                            // Preserve the original trivial copies rather than floating-point assignment.
                            memcpy(&positions[offset], &srcPositions[vertex], sizeof(NiPoint3));

                            memcpy(&normals[offset], &srcNormals[vertex], sizeof(NiPoint3));

                            colors[offset] = srcColors[vertex];

                            uvs[offset] = srcUVs[vertex];

                            instanceIds[offset] = (float)instance;
                        }

                        for (int index = 0; index < (int)sourceIndexCount; index++)

                            indices[writtenIndices++] = srcIndices[index] + vertexOffset;
                    }

                    int sourceTriangles = sourceIndexCount / 3;

                    indexStep = sourceTriangles;

                    combinedData = (NiRefObject*)new NiDynamicTriShapeData(
                        (unsigned short)(instances * vertexCount), positions, normals, colors, uvs, 1, DataFlags_None,
                        (unsigned short)(instances * sourceTriangles), (unsigned short*)indices,
                        (unsigned short)(instances * vertexCount), 0);
                }
                else
                {

                    isStrip = true;

                    GeometryData* source;

                    if (geometry->data == 0)
                        source = 0;
                    else
                        source = (GeometryData*)geometry->data->DynamicCast(&g_011f4a70);

                    NiPoint3* srcPositions = source->positions;

                    NiPoint3* srcNormals = source->normals;

                    vertexCount = source->vertices;

                    unsigned short* stripLengths = source->stripLengths;

                    NiColorA* srcColors = source->colors;

                    NiPoint2* srcUVs = source->texcoords;

                    unsigned short* srcIndices = source->FUN_00a75f10();

                    unsigned short maxCopies;

                    maxCopies = (unsigned short)(65535 / (int)vertexCount);

                    if ((unsigned short)instances >= maxCopies)
                        instances = maxCopies;

                    int stripLength = *stripLengths;
                    maxCopies = (unsigned short)(65535 / ((stripLength % 2 ? 3 : 2) + stripLength));

                    if ((unsigned short)instances >= maxCopies)
                        instances = maxCopies;

                    int totalVertices = (int)instances * (int)vertexCount;

                    NiPoint3* positions = new NiPoint3[totalVertices];

                    NiPoint3* normals = new NiPoint3[totalVertices];

                    NiColorA* colors = new NiColorA[totalVertices];

                    NiPoint2* uvs = new NiPoint2[totalVertices];

                    instanceIds = new float[totalVertices];

                    unsigned short joinedStripSize =
                        (unsigned short)((unsigned short)*stripLengths + ((int)*stripLengths % 2 ? 3 : 2));

                    unsigned short* indices =
                        new unsigned short[(instances - 1) * (int)joinedStripSize + (int)*stripLengths];

                    unsigned int writtenIndices = 0;

                    for (int instance = 0; instance < (int)instances; instance++)
                    {

                        memcpy(positions + instance * vertexCount, srcPositions, vertexCount * sizeof(NiPoint3));

                        memcpy(normals + instance * vertexCount, srcNormals, vertexCount * sizeof(NiPoint3));

                        memcpy(colors + instance * vertexCount, srcColors, vertexCount * sizeof(NiColorA));

                        memcpy(uvs + instance * vertexCount, srcUVs, vertexCount * sizeof(NiPoint2));

                        for (int vertex = 0; vertex < (int)vertexCount; vertex++)
                            instanceIds[instance * vertexCount + vertex] = (float)instance;

                        for (int index = 0; index < (int)*stripLengths; index++)

                            indices[writtenIndices++] = srcIndices[index] + instance * vertexCount;

                        if (instance < (int)instances - 1)
                        {

                            indices[writtenIndices++] =
                                srcIndices[*stripLengths - 1] + (unsigned short)instance * vertexCount;

                            indices[writtenIndices++] = srcIndices[0] + ((unsigned short)instance + 1) * vertexCount;

                            if ((int)*stripLengths % 2 == 1)
                                indices[writtenIndices++] =
                                    srcIndices[0] + ((unsigned short)instance + 1) * vertexCount;
                        }
                    }

                    unsigned short* combinedLengths = new unsigned short[1];

                    *combinedLengths = (unsigned short)writtenIndices;

                    int firstStripLength = *stripLengths;

                    if (firstStripLength % 2 == 1)
                        indexStep = (unsigned short)(firstStripLength + 3);

                    else
                        indexStep = (unsigned short)(firstStripLength + 2);

                    combinedData = new UnsignedShortBuffer(
                        (unsigned short)(instances * vertexCount), positions, normals, colors, uvs, 1, DataFlags_None,
                        (unsigned short)(writtenIndices - 2), 1, (unsigned short*)combinedLengths,
                        (unsigned short*)indices, (unsigned short)(instances * vertexCount), 0);
                }

                Ref<NiProperty> texture;

                if (geometry->FUN_00a59d30(3) && ((ShaderProperty*)geometry->FUN_00a59d30(3))->IsTree())
                {

                    NiProperty* shader = geometry->FUN_00a59d30(3);

                    if (shader)
                        texture = GetShaderTexture(shader, 0, 0);
                }

                geometry->NiAVObject_RemoveProperty(0);

                NiAlphaProperty* alpha = new NiAlphaProperty;

                alpha->m_ucAlphaArg2 = 0;

                alpha->m_usAlphaArg = (alpha->m_usAlphaArg & 0xf3ff) | 0x1201;

                NiAlphaProperty* opaqueAlpha;

                opaqueAlpha = new NiAlphaProperty;

                opaqueAlpha->m_usAlphaArg = (opaqueAlpha->m_usAlphaArg & 0xf3fe) | 0x1200;

                opaqueAlpha->m_ucAlphaArg2 = 0;

                NiProperty* extraProperty = geometry->FUN_00a59d30(4);

                Bound bound = geometry->data->GetBound();

                cachedResource = new Resource;

                cachedResource->strips = isStrip;

                cachedResource->data = combinedData;

                cachedResource->ids = instanceIds;

                cachedResource->vertices = vertexCount;

                cachedResource->texture = texture;

                cachedResource->opaque = opaqueAlpha;

                cachedResource->alpha = alpha;

                cachedResource->extra = extraProperty;

                cachedResource->radius = bound.radius;

                cachedResource->instances = instances;

                cachedResource->step = indexStep;

                cachedResource->node = false;

                Scene* scene = input->scene;

                if (scene)
                {
                    bool hasNodeType = IsKindOfType(scene, &g_011f4aa0);
                    Scene* matchingNode = hasNodeType ? scene : 0;

                    if (matchingNode)
                        cachedResource->node = true;
                }

                GetNiTStringMap()->InsertOrAssign(input->key, cachedResource);
            }
        }
    }

    Resource* answer = cachedResource;

    if (answer == 0)
    {
        char error[200];
        PrintError(error, 200, "DISTANT LOD ERROR : could not load DistantLOD nif %s", input->path);
    }

    return answer;
}

