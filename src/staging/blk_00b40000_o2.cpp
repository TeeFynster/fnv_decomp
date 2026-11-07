#include "../../include/ImageSpaceTexture.h"
#include "../../include/NiTListItem.h"

// src/staging/blk_00b40000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/BGSDecalNode.h"
#include "../../include/BSTextureManager.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMap.h"
#include "../../include/MemoryManager.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/NiTPointerMap.h"
#include "../../include/NiTPrimitiveArray.h"

// These caches use the pointer-pool allocator (NewItem 0x00e72e50), with
// seven virtual slots; the base's allocation slots are pure.
typedef NiTPointerMap<const char*, NiPointer<NiRefObject> > NamedObjectMap;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>,
                   const char*, NiPointer<NiRefObject> > NamedObjectMapBase;
struct RTEntry;
typedef NiTPointerMap<unsigned int, RTEntry*> RenderItemMap;
typedef NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, RTEntry*> RenderItemMapBase;

// The lookup only reads the map and writes its output reference.
template <> __declspec(noalias) bool RenderItemMapBase::GetAt(unsigned int key, RTEntry*& value) const;

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
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

extern ImageSpaceManager* DAT_011f91ac;

// @fnv 0x00b4f430
// src: COMMUNITY 0x00b4f430
void __cdecl BSShaderManager_SetImageSpaceParameters(int arg)
{
    DAT_011f91ac->SetValue(arg);
}

extern BSTextureManager* DAT_011f91a8;
extern BSRenderedTexture* DAT_011f949c;

// If the global rendered texture is set, passes it to the texture manager and clears the global pointer.
// @fnv 0x00b4f510
// src: COMMUNITY 0x00b4f510
void BSShaderManager_ReturnVelocityBuffers()
{
    if (DAT_011f949c)
    {
        DAT_011f91a8->AddRenderedTexture(DAT_011f949c);
        DAT_011f949c = 0;
    }
}


extern ImageSpaceManager* DAT_011f91ac;

// @fnv 0x00b540b0
// src: COMMUNITY 0x00b540b0
void BSShaderManager_ReturnSceneDepthTexture()
{
    ((ImageSpaceTexture*)DAT_011f91ac->DepthTexture)->AddRenderedTexture();
}

extern int DAT_011ffa0c;
extern int DAT_011ffa10;
void __cdecl AddToCounterIfIdle(unsigned int, unsigned int);

// @fnv 0x00b540d0
// src: COMMUNITY 0x00b540d0
void __cdecl BSShaderManager_DisableFullScreenScissor()
{
    DAT_011ffa10 -= 1;
    DAT_011ffa0c -= 1;
    AddToCounterIfIdle(0, 0);
}

extern int DAT_011f9168;
extern int* DAT_011f9170;

// @fnv 0x00b540f0
int __cdecl PopNextInt()
{
    int index = DAT_011f9168;
    int* p = DAT_011f9170 + index;
    DAT_011f9168 = DAT_011f9168 + 1;
    return *p;
}

struct FUN_00b58110_Class
{
    void FUN_00b57ff0();
    void* __thiscall FUN_00b58110(int flags);
};

void __cdecl _delete(void* p, unsigned int size);

// @fnv 0x00b58110
void* __thiscall FUN_00b58110_Class::FUN_00b58110(int flags)
{
    FUN_00b57ff0();
    if (flags & 1)
        _delete(this, 0x8c);
    return this;
}

extern MemoryManager g_memoryManager;
// @fnv 0x00b58400
NamedObjectMap* __fastcall DestroyNamedObjectMap(NamedObjectMap* map, void*, unsigned int flag)
{
    map->NamedObjectMap::~NiTPointerMap();
    if ((flag & 1))
        g_memoryManager.Deallocate(map);
    return map;
}

extern "C" void __cdecl operator delete(void*, unsigned int);

void __cdecl FUN_00b581c0(void);

// The shared BGSDecalNode has no declaration for this cleanup wrapper.
// Calls FUN_00b581c0, deletes node with size 0x34 when flags has bit 0 set, and returns node.
// @fnv 0x00b584c0
BGSDecalNode* __fastcall FUN_00b584c0(BGSDecalNode* node, void*, unsigned int flags)
{
    FUN_00b581c0();
    if (flags & 1)
        ::operator delete(node, 0x34);
    return node;
}

extern char DAT_011f968c;

struct FUN_00b5a3f0_Class
{
    int __thiscall ImageSpaceEffectDepthRadialBlur_IsActive();
};

// @fnv 0x00b5a3f0
// src: COMMUNITY 0x00b5a3f0
int __thiscall FUN_00b5a3f0_Class::ImageSpaceEffectDepthRadialBlur_IsActive()
{
    if (*(float*)((char*)this + 0x6c) > 0.0f && DAT_011f968c)
        return 1;
    return 0;
}

namespace fnv_00b5a480 {
extern MemoryManager g_memoryManager;
void __cdecl FUN_00b59c20();
struct FUN_00b5a480_Class
{
    void* FUN_00b5a480(unsigned char flag);
};
// @fnv 0x00b5a480
void* FUN_00b5a480_Class::FUN_00b5a480(unsigned char flag)
{
    FUN_00b59c20();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00b5a480

// @fnv 0x00b5a980
// src: GUESS 0x00b5a980 (confidence: low)
int __cdecl Object_ComputeValue_00b5a980(int* piLeft, int* piRight)
{
    return *piLeft == *piRight;
}

struct FUN_00b5a9d0_class
{
    void SetTripleInts(int a, int b, int c);
};

// Stores the three int arguments at offsets 0x100, 0x104 and 0x108 of this object.
// @fnv 0x00b5a9d0
void FUN_00b5a9d0_class::SetTripleInts(int aiFirst, int aiSecond, int aiThird)
{
    *(int*)((char*)this + 0x100) = aiFirst;
    *(int*)((char*)this + 0x104) = aiSecond;
    *(int*)((char*)this + 0x108) = aiThird;
}

extern "C" void __cdecl operator delete(void*, unsigned int);

void __cdecl FUN_00b5e5a0();

struct FUN_00b5f980_class
{
    void* __thiscall FUN_00b5f980(bool flag);
};

// Calls FUN_00b5e5a0, then deletes this with size 0x200 when flag's low bit is set, and returns this.
// @fnv 0x00b5f980
void* __thiscall FUN_00b5f980_class::FUN_00b5f980(bool abDelete)
{
    FUN_00b5e5a0();
    if (abDelete & 1)
        operator delete(this, 0x200);
    return this;
}

struct FUN_00b57fe0_class
{
    void __thiscall DistantLODShaderProperty_SetClampNI(int value);
};
// @fnv 0x00b57fe0
// src: XBOX_PDB 0x00b57fe0
void __thiscall FUN_00b57fe0_class::DistantLODShaderProperty_SetClampNI(int value)
{
    *(int*)((char*)this + 0x84) = value;
}

struct NodePoolView
{
    void* AddHead();
};
struct FUN_00b58570_Class
{
    void* __thiscall NiTPointerListBase_AddTail(void* source);
};
// Allocates a node from the pool at this+8, links it after the current tail (this+4) or as the first node, and returns it.
// @fnv 0x00b58570
// src: COMMUNITY 0x00b58570
void* __thiscall FUN_00b58570_Class::NiTPointerListBase_AddTail(void* source)
{
    void* node = ((NodePoolView*)((char*)this + 8))->AddHead();
    *(void**)((char*)node + 8) = *(void**)source;
    *(void**)node = 0;
    *(void**)((char*)node + 4) = *(void**)((char*)this + 4);
    if (*(void**)((char*)this + 4))
    {
        *(void**)(*(void**)((char*)this + 4)) = node;
        ++*(unsigned int*)((char*)this + 8);
        *(void**)((char*)this + 4) = node;
        return node;
    }
    ++*(unsigned int*)((char*)this + 8);
    *(void**)this = node;
    *(void**)((char*)this + 4) = node;
    return node;
}

// @fnv 0x00b5aa70
int CompareFloatAtOffsetC(int* pLeft, int* pRight)
{
    float x = *(float*)((char*)pLeft[0] + 0xc);
    float y = *(float*)((char*)pRight[0] + 0xc);
    if (x > y)
        return -1;
    if (x < y)
        return 1;
    return 0;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
struct FUN_00b584e0_Node
{
    void* pPrev;
    void* pNext;
    void* pData;
};

struct FUN_00b584e0_Class
{
    void* pHead;
    FUN_00b584e0_Node* pTail;
    unsigned int ItemUpdateArray;
    FUN_00b584e0_Node* AllocateStorage_00b584e0(void* pData);
};

// Allocates a 12-byte node, stores the value pointed to by pData, links it before pTail, and updates pHead/pTail and the count.
// @fnv 0x00b584e0
// src: GUESS 0x00b584e0 (confidence: medium)
FUN_00b584e0_Node* FUN_00b584e0_Class::AllocateStorage_00b584e0(void* pData)
{
    FUN_00b584e0_Node* pNewNode =
        static_cast<FUN_00b584e0_Node*>(reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0xc));
    pNewNode->pData = *static_cast<void**>(pData);
    pNewNode->pPrev = 0;
    pNewNode->pNext = pTail;
    if (pTail)
    {
        pTail->pPrev = pNewNode;
        ++ItemUpdateArray;
        pTail = pNewNode;
    }
    else
    {
        ++ItemUpdateArray;
        pHead = pNewNode;
        pTail = pNewNode;
    }
    return pNewNode;
}

struct ImageSpaceShaderParam
{
    void SetShaderConstantVector4(int, float, float, float, float);
};
struct FUN_00b59cb0_Class
{
    bool ApplyShaderParams(int arg);
};
// @fnv 0x00b59cb0
bool FUN_00b59cb0_Class::ApplyShaderParams(int arg)
{
    ImageSpaceShaderParam* pShaderParam = *reinterpret_cast<ImageSpaceShaderParam**>(*(int*)((char*)this + 0x1c));
    pShaderParam->SetShaderConstantVector4(0, *(float*)((char*)this + 0x58), *(float*)((char*)this + 0x5c),
                                           *(float*)((char*)this + 0x60), *(float*)((char*)this + 0x64));
    pShaderParam->SetShaderConstantVector4(1, *(float*)((char*)this + 0x6c), *(float*)((char*)this + 0x70),
                                           *(float*)((char*)this + 0x68), 0.0f);
    return true;
}

struct FUN_00b5a8d0_Node
{
    FUN_00b5a8d0_Node* m_pSecondNode;
    FUN_00b5a8d0_Node* m_next;
};
struct FUN_00b5a8d0_List
{
    FUN_00b5a8d0_Node* m_pFirstNode;
    FUN_00b5a8d0_Node* m_pTail;
    void __thiscall MoveBefore(FUN_00b5a8d0_Node* a, FUN_00b5a8d0_Node* b);
};
// Unlinks node a from the list and reinserts it immediately before node b, updating head, tail and neighbour links.
// @fnv 0x00b5a8d0
void __thiscall FUN_00b5a8d0_List::MoveBefore(FUN_00b5a8d0_Node* pNodeToMove, FUN_00b5a8d0_Node* pInsertBefore)
{
    if (pNodeToMove != pInsertBefore)
    {
        if (m_pFirstNode == pNodeToMove)
            m_pFirstNode = pNodeToMove->m_pSecondNode;
        if (m_pTail == pNodeToMove)
            m_pTail = pNodeToMove->m_next;
        if (m_pTail == pInsertBefore)
            m_pTail = pNodeToMove;
        if (pNodeToMove->m_pSecondNode)
            pNodeToMove->m_pSecondNode->m_next = pNodeToMove->m_next;
        if (pNodeToMove->m_next)
            pNodeToMove->m_next->m_pSecondNode = pNodeToMove->m_pSecondNode;
        pNodeToMove->m_pSecondNode = pInsertBefore->m_pSecondNode;
        pNodeToMove->m_next = pInsertBefore;
        if (pNodeToMove->m_pSecondNode)
            pNodeToMove->m_pSecondNode->m_next = pNodeToMove;
        pInsertBefore->m_pSecondNode = pNodeToMove;
    }
}

struct FUN_00b5a3a0_Class
{
    void ImageSpaceEffectDepthRadialBlur_ReturnTextures();
};

// @fnv 0x00b5a3a0
// src: COMMUNITY 0x00b5a3a0
void FUN_00b5a3a0_Class::ImageSpaceEffectDepthRadialBlur_ReturnTextures()
{
    int iZero;
    ImageSpaceTexture* tex = *(ImageSpaceTexture**)((char*)this + 0x2c);
    tex = *(ImageSpaceTexture**)((char*)tex + 8);
    tex->AddRenderedTexture();
    NiTPrimitiveArray<int>* arr = (NiTPrimitiveArray<int>*)((char*)this + 0x28);
    iZero = 0;
    arr->SetAt(2, iZero);
    iZero = 0;
    arr->SetAt(3, iZero);
}

void __cdecl AccumulateAndDispatch(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

// Calls AccumulateAndDispatch with the four arguments and 1, then calls AddToCounterIfIdle with 1 and 1.
// @fnv 0x00b4f540
// src: COMMUNITY 0x00b4f540
void __cdecl BSShaderManager_EnableFullScreenScissor(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    AccumulateAndDispatch(a, b, c, d, 1);
    AddToCounterIfIdle(1, 1);
}

// @fnv 0x00b59d10
// src: COMMUNITY 0x00b59d10
int __fastcall ImageSpaceEffectRadialBlur_IsActive(char* p, int)
{
    if (*(float*)(p + 0x58) > 0.0f && DAT_011f968c)
        return 1;
    return 0;
}

struct S_00b4e1e0_Item
{
    int unk0;
    int unk4;
    void BSFadeNode_FreeLinkedNodesRecursively();
    ~S_00b4e1e0_Item()
    {
        BSFadeNode_FreeLinkedNodesRecursively();
    }
};
struct S_00b4e1e0_Base
{
    S_00b4e1e0_Base();
    virtual ~S_00b4e1e0_Base();
    int unk4;
    int unk8;
    int unk12;
    int unk16;
    int unk20;
    int unk24;
    int unk28;
    int unk32;
    int unk36;
    int unk40;
    int unk44;
    int unk48;
    int unk52;
    int unk56;
    int unk60;
    int unk64;
    int unk68;
    int unk72;
    int unk76;
    int unk80;
    int unk84;
    int unk88;
    int unk92;
    int unk96;
    int unk100;
    int unk104;
    int unk108;
    int unk112;
    int unk116;
    int unk120;
    int unk124;
    int unk128;
    int unk132;
    int unk136;
    int unk140;
    int unk144;
    int unk148;
    int unk152;
    int unk156;
    int unk160;
    int unk164;
    int unk168;
    int unk172;
    int unk176;
    int unk180;
    int unk184;
    int unk188;
    int unk192;
    int unk196;
    int unk200;
    int unk204;
    int unk208;
};
struct FUN_00b4e1e0 : S_00b4e1e0_Base
{
    S_00b4e1e0_Item unk212;
    S_00b4e1e0_Item unk220;
    virtual ~FUN_00b4e1e0();
};
// Destructor that releases the two embedded items by calling their cleanup routine.
// @fnv 0x00b4e1e0
FUN_00b4e1e0::~FUN_00b4e1e0()
{
    unk212.BSFadeNode_FreeLinkedNodesRecursively();
    unk220.BSFadeNode_FreeLinkedNodesRecursively();
}

extern int DAT_011f9168;

// @fnv 0x00b4f570
// src: COMMUNITY 0x00b4f570
void __cdecl BSShaderManager_ResetNextAvailableShadowMapAccumulator()
{
    DAT_011f9168 = 0;
}

extern int DAT_011f95ec;

// @fnv 0x00b4f5c0
// src: XBOX_PDB 0x00b4f5c0
int BSShaderManager_GetAccumulator()
{
    return DAT_011f95ec;
}

struct FUN_00b54620_This
{
    int unk00;
    void __thiscall NiPointer_NiRefObject_NiPointer_NiRefObject();
};

// @fnv 0x00b54620
// src: COMMUNITY 0x00b54620
void FUN_00b54620_This::NiPointer_NiRefObject_NiPointer_NiRefObject()
{
    this->unk00 = 0;
}

class B55480Node;

struct B55480ShaderProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiValue1;
};

struct B55480Property
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
    int m_iValue;
};

class B55480AVObject
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual B55480Node* IsSceneNode();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void* IsGeometry();

    void* GetProperty(unsigned int uiType);
};

class B55480Node : public B55480AVObject
{
  public:
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
    int unk9C;
    B55480AVObject** m_pkChildren;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

// @fnv 0x00b55480
void SetPropertyValueRecursive(B55480AVObject* pkObject, int iValue)
{
    if (!pkObject)
        return;
    if (pkObject->IsGeometry())
    {
        B55480Property* pkProp = static_cast<B55480Property*>(pkObject->GetProperty(2));
        B55480ShaderProperty* pkShader = static_cast<B55480ShaderProperty*>(pkObject->GetProperty(3));
        if (pkProp && pkShader && (pkShader->m_uiValue1 & 0x20000000) > 0)
            pkProp->m_iValue = iValue;
    }
    else
    {
        B55480Node* pkNode = pkObject->IsSceneNode();
        if (pkNode)
        {
            unsigned int ItemUpdateArray = pkNode->m_usSize;
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                B55480AVObject* pkChild = pkNode->m_pkChildren[i];
                if (pkChild)
                    SetPropertyValueRecursive(pkChild, iValue);
            }
        }
    }
}

struct S_00b57e70_Class
{
    int unk00;
    int unk04;
    int unk08;

    S_00b57e70_Class* __thiscall DistantLODShaderProperty_DistantLODParam_DistantLODParam();
};

// @fnv 0x00b57e70
// src: XBOX_PDB 0x00b57e70
S_00b57e70_Class* __thiscall S_00b57e70_Class::DistantLODShaderProperty_DistantLODParam_DistantLODParam()
{
    unk08 = 0;
    unk04 = 0;
    unk00 = 0;
    return this;
}

struct FUN_00b57e80_cls
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
    int m_84;
    void DistantLODShaderProperty_SetClampD3D(int value);
};

// @fnv 0x00b57e80
// src: XBOX_PDB 0x00b57e80
void FUN_00b57e80_cls::DistantLODShaderProperty_SetClampD3D(int value)
{
    m_84 = (value != 3) ? 3 : 0;
}

// Stand-in for the base class of FUN_00b57f90: virtual at 0, size 0x7c.
// Its constructor (FUN_00b71720) is external: it is the call the original makes.
struct FUN_00b7c000_Base
{
    virtual void FUN_00b7c000_v();
    int m_i01;
    int m_i02;
    int m_i03;
    int m_i04;
    int m_i05;
    int m_i06;
    int m_i07;
    int m_i08;
    int m_i09;
    int m_i10;
    int m_i11;
    int m_i12;
    int m_i13;
    int m_i14;
    int m_i15;
    int m_i16;
    int m_i17;
    int m_i18;
    int m_i19;
    int m_i20;
    int m_i21;
    int m_i22;
    int m_i23;
    int m_i24;
    int m_i25;
    int m_i26;
    int m_i27;
    int m_i28;
    int m_i29;
    int m_i30;
    FUN_00b7c000_Base();
};

// The derived class whose constructor is FUN_00b57f90: its vtable has 64
// entries, and it owns the two dwords at 0x7c and 0x80.
// The two members are volatile so that the compiler keeps the zero stores
// below the vtable store, exactly as in the original.
struct FUN_00b57f90 : public FUN_00b7c000_Base
{
    volatile int m_i31;
    volatile int m_i32;
    virtual void FUN_00b7c000_v();
    virtual void FUN_00b7c002_v();
    virtual void FUN_00b7c003_v();
    virtual void FUN_00b7c004_v();
    virtual void FUN_00b7c005_v();
    virtual void FUN_00b7c006_v();
    virtual void FUN_00b7c007_v();
    virtual void FUN_00b7c008_v();
    virtual void FUN_00b7c009_v();
    virtual void FUN_00b7c010_v();
    virtual void FUN_00b7c011_v();
    virtual void FUN_00b7c012_v();
    virtual void FUN_00b7c013_v();
    virtual void FUN_00b7c014_v();
    virtual void FUN_00b7c015_v();
    virtual void FUN_00b7c016_v();
    virtual void FUN_00b7c017_v();
    virtual void FUN_00b7c018_v();
    virtual void FUN_00b7c019_v();
    virtual void FUN_00b7c020_v();
    virtual void FUN_00b7c021_v();
    virtual void FUN_00b7c022_v();
    virtual void FUN_00b7c023_v();
    virtual void FUN_00b7c024_v();
    virtual void FUN_00b7c025_v();
    virtual void FUN_00b7c026_v();
    virtual void FUN_00b7c027_v();
    virtual void FUN_00b7c028_v();
    virtual void FUN_00b7c029_v();
    virtual void FUN_00b7c030_v();
    virtual void FUN_00b7c031_v();
    virtual void FUN_00b7c032_v();
    virtual void FUN_00b7c033_v();
    virtual void FUN_00b7c034_v();
    virtual void FUN_00b7c035_v();
    virtual void FUN_00b7c036_v();
    virtual void FUN_00b7c037_v();
    virtual void FUN_00b7c038_v();
    virtual void FUN_00b7c039_v();
    virtual void FUN_00b7c040_v();
    virtual void FUN_00b7c041_v();
    virtual void FUN_00b7c042_v();
    virtual void FUN_00b7c043_v();
    virtual void FUN_00b7c044_v();
    virtual void FUN_00b7c045_v();
    virtual void FUN_00b7c046_v();
    virtual void FUN_00b7c047_v();
    virtual void FUN_00b7c048_v();
    virtual void FUN_00b7c049_v();
    virtual void FUN_00b7c050_v();
    virtual void FUN_00b7c051_v();
    virtual void FUN_00b7c052_v();
    virtual void FUN_00b7c053_v();
    virtual void FUN_00b7c054_v();
    virtual void FUN_00b7c055_v();
    virtual void FUN_00b7c056_v();
    virtual void FUN_00b7c057_v();
    virtual void FUN_00b7c058_v();
    virtual void FUN_00b7c059_v();
    virtual void FUN_00b7c060_v();
    virtual void FUN_00b7c061_v();
    virtual void FUN_00b7c062_v();
    virtual void FUN_00b7c063_v();
    virtual void FUN_00b7c064_v();
    FUN_00b57f90();
};

// Constructor: initialises the base and sets m_i32 and m_i31 to 0, m_i22 to 3 and m_i07 to 2.
// @fnv 0x00b57f90
FUN_00b57f90::FUN_00b57f90() : FUN_00b7c000_Base()
{
    m_i32 = 0;
    m_i31 = 0;
    m_i22 = 3;
    m_i07 = 2;
}

// FUN_00b57fd0 : a one-line function - getter
extern int g_target_00b57fd0;
// @fnv 0x00b57fd0
// src: XBOX_PDB 0x00b57fd0
void* DistantLODShaderProperty_GetRTTI()
{
    return &g_target_00b57fd0;
}

class B57FF0Base
{
  public:
    virtual ~B57FF0Base();

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
};

class FUN_00b57ff0 : public B57FF0Base
{
  public:
    virtual ~FUN_00b57ff0();

    int m_iFadeIndex;
    NiPointer<NiRefObject> m_pReferencedObject;
};

// @fnv 0x00b57ff0
FUN_00b57ff0::~FUN_00b57ff0()
{
    m_iFadeIndex = 0;
}

class B58070AVObject
{
  public:
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
    unsigned int m_uiObjectFlags;

    bool GetAppCulled() const
    {
        return (bool)(m_uiObjectFlags & 1);
    }
    void SetAppCulled(bool bCulled)
    {
        if (bCulled)
            m_uiObjectFlags |= 1;
        else
            m_uiObjectFlags &= ~1;
    }
};

extern B58070AVObject* g_pkB58070Root;

// @fnv 0x00b58070
bool SetRootAppCulled(bool bCulled)
{
    B58070AVObject* pkRoot = g_pkB58070Root;
    bool bWasCulled = pkRoot->GetAppCulled();
    pkRoot->SetAppCulled(bCulled);
    return bWasCulled;
}

struct CpuObject
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
    int value;
    int SpeedTreeShaderLightingProperty_GetClampNI();
};
// @fnv 0x00b58090
// src: XBOX_PDB 0x00b58090
int CpuObject::SpeedTreeShaderLightingProperty_GetClampNI()
{
    return value;
}

void* __cdecl NiFreeAlias(void* p);

template <class TAlloc, class TKEY, class TVAL>
inline NiTMapBase<TAlloc, TKEY, TVAL>::~NiTMapBase()
{
    RemoveAll();
    NiFreeAlias(m_ppkHashTable);
}

// Clears the named cache before releasing the base hash table.
// @fnv 0x00b580a0
template <> NamedObjectMap::~NiTPointerMap()
{
    RemoveAll();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct FUN_00b58140_Class
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
    unsigned int copiedValue7c;
    NiRefObject* reference80;
    unsigned int copiedValue84;
    unsigned int copiedValue88;
    void __thiscall BSShaderLightingProperty_CopyMembers(FUN_00b58140_Class* destination, unsigned int flags);
    void __thiscall CopyTo(FUN_00b58140_Class* destination, unsigned int flags);
};

// @fnv 0x00b58140
void FUN_00b58140_Class::CopyTo(FUN_00b58140_Class* destination, unsigned int flags)
{
    BSShaderLightingProperty_CopyMembers(destination, flags);
    if (destination->reference80 != reference80)
    {
        if (destination->reference80)
        {
            destination->reference80->DecRefCount();
        }
        destination->reference80 = reference80;
        if (destination->reference80)
        {
            destination->reference80->IncRefCount();
        }
    }
    destination->copiedValue84 = copiedValue84;
    destination->copiedValue88 = copiedValue88;
    destination->copiedValue7c = copiedValue7c;
}

// Replaces an existing value or inserts a newly allocated hash-chain item.
// @fnv 0x00b582b0
template <> void NamedObjectMapBase::SetAt(const char* key, NiPointer<NiRefObject> value)
{
    unsigned int hash = KeyToHashIndex(key);
    EntryType* node = m_ppkHashTable[hash];
    while (node)
    {
        if (IsKeysEqual(key, node->m_key))
        {
            node->m_val = value;
            return;
        }
        node = node->m_pkNext;
    }
    node = NewItem();
    SetValue(node, key, value);
    node->m_pkNext = m_ppkHashTable[hash];
    m_ppkHashTable[hash] = node;
    ++m_kItemCount.m_uiCount;
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct BlobBase
{
    BlobBase();
    virtual void b00();
};

struct BlobObj : public BlobBase
{
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int m_1c;
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
    int m_58;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int m_7c;
    int m_80;
    int unk084;
    int unk088;
    BlobObj() : BlobBase()
    {
        m_80 = 0;
        m_7c = 0;
        m_58 = 3;
        m_1c = 2;
    }

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p) throw()
    {}
};

struct FUN_00b58420_cls
{
    void __thiscall CopyTo(BlobObj* obj, unsigned int arg);
    BlobObj* CreateBlobObj(unsigned int arg);
};

// Allocates a BlobObj, initializes it via CopyTo with arg, and returns the object.
// @fnv 0x00b58420
BlobObj* FUN_00b58420_cls::CreateBlobObj(unsigned int arg)
{
    BlobObj* obj = new BlobObj;
    this->CopyTo(obj, arg);
    return obj;
}

struct PoolAllocator_b4009
{
    void Free(void* apPtr);
};

extern "C" PoolAllocator_b4009 DAT_011f6238;

struct ListNode_b4009
{
    ListNode_b4009* m_00;
    unsigned int m_04;
    unsigned int m_08;
};

struct FUN_00b58530_cls
{
    ListNode_b4009* m_00;
    unsigned int m_04;
    unsigned int m_08;

    void ProcessEntries_00b58530();
};

// Walks the linked list from m_00, clearing each node's m_08 and freeing it, then resets m_00, m_04 and m_08.
// @fnv 0x00b58530
// src: GUESS 0x00b58530 (confidence: low)
void FUN_00b58530_cls::ProcessEntries_00b58530()
{
    ListNode_b4009* cur = m_00;
    if (cur != 0)
    {
        do
        {
            ListNode_b4009* node = cur;
            cur = cur->m_00;
            node->m_08 = 0;
            DAT_011f6238.Free(node);
        } while (cur != 0);
    }
    m_08 = 0;
    m_00 = 0;
    m_04 = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class BB595B0Heap
{
  public:
    void Deallocate(void* pvMem);
};

extern BB595B0Heap g_kB595B0Heap;

template <class T> class BB595B0Pointer
{
  public:
    ~BB595B0Pointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    BB595B0Pointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
        }
        return *this;
    }

    T* m_pObject;
};

class BB595B0Entry
{
  public:
    ~BB595B0Entry();

    static void operator delete(void* pvMem)
    {
        g_kB595B0Heap.Deallocate(pvMem);
    }
};



template <class T> class BB595B0List
{
  public:
    ~BB595B0List()
    {
        RemoveAll();
    }
    void RemoveAll() throw();

    NiTListItem<T>* GetHeadPos() const
    {
        return m_pkHead;
    }
    T& GetNext(NiTListItem<T>*& pkPos) const
    {
        T& element = pkPos->m_element;
        pkPos = pkPos->m_pkNext;
        return element;
    }

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
};

class BB595B0Queue
{
  public:
    ~BB595B0Queue();
    void Clear();
};

class FUN_00b595b0_cls
{
  public:
    ~FUN_00b595b0_cls();

    int unk00;
    int unk04;
    int unk08;
    BB595B0List<BB595B0Entry*> m_kEntries;
    BB595B0Pointer<NiRefObject> m_pReferencedObject;
    BB595B0Queue m_kQueue;
};

// Releases the held reference object, clears the queue, deletes all entry pointers in the list, then removes the list nodes.
// @fnv 0x00b595b0
FUN_00b595b0_cls::~FUN_00b595b0_cls()
{
    m_pReferencedObject = 0;
    m_kQueue.Clear();
    NiTListItem<BB595B0Entry*>* pkPos = m_kEntries.GetHeadPos();
    while (pkPos)
    {
        delete m_kEntries.GetNext(pkPos);
    }
    m_kEntries.RemoveAll();
}

struct ParameterPair
{
    ImageSpaceShaderParam* first;
    ImageSpaceShaderParam* second;
};
struct Camera
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
    float nearPlane;
    float farPlane;
};
extern Camera* DAT_011f917c;
struct Effect
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    ParameterPair* parameters;
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
    float value5c;
    float value60;
    float value64;
    float value68;
    float value6c;
    float value70;
    float value74;
    float value78;
    float value7c;
    float value80;
    float value84;
    float value88;
    float value8c;
    float value90;
    float value94;
    bool UpdateShaderParams(int);
};
// Writes camera near/far plane derived values into value60/64/68 and sets four-component parameters on both shader params, returning true.
// @fnv 0x00b5a220
bool Effect::UpdateShaderParams(int)
{
    ImageSpaceShaderParam* pSecondParam = parameters->second;
    float nearPlane = DAT_011f917c->nearPlane;
    float farPlane = DAT_011f917c->farPlane;
    value60 = nearPlane;
    value64 = farPlane - nearPlane;
    value68 = nearPlane * farPlane;
    pSecondParam->SetShaderConstantVector4(0, value7c, value80, value84, value88);
    pSecondParam->SetShaderConstantVector4(1, value6c, value70, value74, value78);
    pSecondParam->SetShaderConstantVector4(2, value5c, value60, value64, value68);
    ImageSpaceShaderParam* pFirstParam = parameters->first;
    pFirstParam->SetShaderConstantVector4(0, value8c, value90, value94, 0.0f);
    pFirstParam->SetShaderConstantVector4(1, 0.5f, 0.5f, 0.0f, 0.0f);
    return true;
}

struct FUN_00ba3840_Class
{
    void __thiscall ImageSpaceTexture_BorrowRenderedTexture(int value);
};
struct FUN_00ba3aa0_Class
{
    void __thiscall FUN_00ba3aa0(int kind, void* value);
};
struct FUN_00ba37f0_Class
{
    void __thiscall ImageSpaceTexture_SetTexture_00ba37f0(int value);
};
int __cdecl GetImageSpaceTexture();
struct FUN_00b5a340_Class
{
    void __thiscall InitSubObjects(int arg);
};
// @fnv 0x00b5a340
void FUN_00b5a340_Class::InitSubObjects(int arg)
{
    char* value;
    FUN_00ba37f0_Class* object;
    value = (char*)this + 0xb4;
    ((FUN_00ba3840_Class*)value)->ImageSpaceTexture_BorrowRenderedTexture(0x28);
    ((FUN_00ba3aa0_Class*)((char*)this + 0x28))->FUN_00ba3aa0(2, &value);
    object = (FUN_00ba37f0_Class*)((char*)this + 0xc4);
    value = (char*)object;
    object->ImageSpaceTexture_SetTexture_00ba37f0(GetImageSpaceTexture());
    ((FUN_00ba3aa0_Class*)((char*)this + 0x28))->FUN_00ba3aa0(3, &value);
}

struct PaletteFieldFlags
{
    unsigned int __thiscall GetPackedZeroFlags() const;
};

// Packs four zero-comparison results of bytes at offsets 0xe6-0xe9 into a 4-bit value, with 0xe6 as the lowest bit.
// @fnv 0x00b5aa00
unsigned int __thiscall PaletteFieldFlags::GetPackedZeroFlags() const
{
    const unsigned char* const fieldBytes = reinterpret_cast<const unsigned char*>(this);

    return (((fieldBytes[0xe9] == 0) * 2 | (fieldBytes[0xe8] == 0)) * 2 | (fieldBytes[0xe7] == 0)) * 2 |
           (fieldBytes[0xe6] == 0);
}

struct FnvLookupRecord
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int lookupKey;
};
struct FnvLookupNode
{
    FnvLookupNode* next;
    int unk004;
    FnvLookupRecord* record;
};
struct FnvLookupOwner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    FnvLookupNode* head;
    void FUN_00b5d270(FnvLookupRecord* record);
    void ShadowSceneNode_UpdateLight_0(int lookupKey);
};
// Walks the linked list from head and, for the first node whose record matches lookupKey, calls FUN_00b5d270 on that record and returns.
// @fnv 0x00b5f080
// src: COMMUNITY 0x00b5f080
void FnvLookupOwner::ShadowSceneNode_UpdateLight_0(int lookupKey)
{
    FnvLookupNode* node = head;
    if (node == 0)
        return;
    do
    {
        FnvLookupRecord** ppRecord = &node->record;
        node = node->next;
        FnvLookupRecord* record = *ppRecord;
        if (record != 0 && record->lookupKey == lookupKey)
        {
            FUN_00b5d270(record);
            return;
        }
    } while (node != 0);
}

struct BB5F0C0RTTI
{
    const char* m_pcName;
    const BB5F0C0RTTI* m_pBaseRTTI;

    bool IsKindOfType(const BB5F0C0RTTI* pkRTTI) const
    {
        const BB5F0C0RTTI* pkCurrent = this;
        while (pkCurrent)
        {
            if (pkCurrent == pkRTTI)
                return true;
            pkCurrent = pkCurrent->m_pBaseRTTI;
        }
        return false;
    }
};

extern const BB5F0C0RTTI g_kB5F0C0GeometryRTTI;

class BB5F0C0Object
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual const BB5F0C0RTTI* GetRTTI() const;
    virtual void* IsSceneNode();
};

inline bool BB5F0C0IsKindOf(const BB5F0C0RTTI* pkTarget, const BB5F0C0Object* pkObject)
{
    for (const BB5F0C0RTTI* pkRTTI = pkObject->GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
    {
        if (pkRTTI == pkTarget)
            return true;
    }
    return false;
}

class BB5F0C0Node : public BB5F0C0Object
{
  public:
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
    int unk9C;
    BB5F0C0Object** m_pkChildren;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
};

class BB5F0C0Visitor
{
  public:
    void ShadowSceneNode_RemoveLight(BB5F0C0Object* pkGeometry);
    void FUN_00b5c940(BB5F0C0Object* pkGeometry, bool bFlag);
    void VisitNodeChildren(BB5F0C0Node* pkNode, bool bAttach);
};

// @fnv 0x00b5f0c0
void BB5F0C0Visitor::VisitNodeChildren(BB5F0C0Node* pkNode, bool bAttach)
{
    unsigned int ItemUpdateArray = pkNode->m_usSize;
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        BB5F0C0Object* pkChild = pkNode->m_pkChildren[i];
        if (pkChild)
        {
            if (BB5F0C0IsKindOf(&g_kB5F0C0GeometryRTTI, pkChild))
            {
                if (bAttach)
                    ShadowSceneNode_RemoveLight(pkChild);
                else
                    FUN_00b5c940(pkChild, true);
            }
            else if (pkChild->IsSceneNode())
            {
                VisitNodeChildren((BB5F0C0Node*)pkChild, bAttach);
            }
        }
    }
}

// FUN_00b5f150 - scene target forwarder.
//
// Loads the first argument (a scene target pointer) and tests it for null.
// When it is non-null the value is put back into the outgoing argument slot
// and control is tail-jumped to the scene graph updater, which receives the
// same target pointer and flag.  With a null target the call is skipped and
// the two stack arguments are popped.

void __stdcall VisitNodeChildren(void* pTarget, int flag);

struct FunSceneManager
{
    void ShadowSceneNode_FindAndCullLight(void* pTarget, int flag);
};

// @fnv 0x00b5f150
// src: COMMUNITY 0x00b5f150
void FunSceneManager::ShadowSceneNode_FindAndCullLight(void* pTarget, int flag)
{
    if (pTarget != 0)
        VisitNodeChildren(pTarget, flag);
}

extern int DAT_011f95f0;

// @fnv 0x00b4f5d0
// src: COMMUNITY 0x00b4f5d0
int BSShaderManager_GetCurrentAccumulator()
{
    return DAT_011f95f0;
}

struct FUN_00b54280
{
    FUN_00b54280();
};
extern bool DAT_011f9308;
extern bool DAT_011f9200;
extern bool DAT_011f91df;
extern bool DAT_011f91de;
extern bool DAT_011f91dd;
extern bool DAT_011f91c7;
extern bool DAT_011f91c6;
extern bool DAT_011f91c5;
extern bool DAT_011f91a7;
extern bool DAT_011f91a5;
extern bool DAT_011f91c4;
extern bool DAT_011ad80c;
extern bool DAT_011f91dc;
extern bool DAT_011f91a4;
extern bool DAT_011f9181;
extern bool DAT_011f91a3;
extern bool DAT_011f9182;
extern bool DAT_011f9180;
extern bool DAT_011f94a4;
extern bool DAT_011f94a6;
extern int DAT_011f91e4;
extern int DAT_011f91e0;
extern int DAT_011f91d8;
extern int DAT_011f91f0;
extern int DAT_011f91ec;
extern int DAT_011f91c0;
extern int DAT_011f91bc;
extern int DAT_011f9178;
extern float DAT_011f9190;
extern float DAT_011f918c;
extern float DAT_011f9188;
extern float DAT_011f9184;
void __cdecl BSShaderManager_DefaultFileCreateFunc();
extern void(__cdecl* DAT_011f91f8)();
void __cdecl FUN_00b54000(float);
extern NiPointer<NiRefObject> DAT_011f9548[35];
extern NiPointer<NiRefObject> DAT_011f950c;
extern NiPointer<NiRefObject> DAT_011f9514;
extern NiPointer<NiRefObject> DAT_011f9510;
extern NiPointer<NiRefObject> DAT_011f9518;
extern NiPointer<NiRefObject> DAT_011f951c;
extern NiPointer<NiRefObject> DAT_011f9520;
extern NiPointer<NiRefObject> DAT_011f9524;
extern NiPointer<NiRefObject> DAT_011f9528;
extern NiPointer<NiRefObject> DAT_011f952c;
extern NiPointer<NiRefObject> DAT_011f9530;
extern NiPointer<NiRefObject> DAT_011f9534;
extern NiPointer<NiRefObject> DAT_011f9538;
extern NiPointer<NiRefObject> DAT_011f953c;
extern NiPointer<NiRefObject> DAT_011f9540;
extern NiPointer<NiRefObject> DAT_011f9544;
extern NiPointer<NiRefObject> DAT_011f95d4;

// @fnv 0x00b54280
FUN_00b54280::FUN_00b54280()
{
    DAT_011f9308 = false;
    DAT_011f9200 = false;
    DAT_011f91df = true;
    DAT_011f91e4 = 0;
    DAT_011f91e0 = 0;
    DAT_011f91de = true;
    DAT_011f91dd = false;
    DAT_011f91d8 = 47;
    DAT_011f91f8 = BSShaderManager_DefaultFileCreateFunc;
    DAT_011f91f0 = 0;
    DAT_011f91ec = 0;
    DAT_011f91c7 = true;
    DAT_011f91c6 = false;
    DAT_011f91c5 = false;
    DAT_011f91a7 = false;
    DAT_011f91c0 = 0;
    DAT_011f91bc = 0;
    DAT_011f91a5 = true;
    for (int i = 0; i < 35; ++i)
        DAT_011f9548[i] = 0;
    DAT_011f950c = 0;
    DAT_011f9514 = 0;
    DAT_011f9510 = 0;
    DAT_011f9518 = 0;
    DAT_011f951c = 0;
    DAT_011f9520 = 0;
    DAT_011f9524 = 0;
    DAT_011f9528 = 0;
    DAT_011f952c = 0;
    DAT_011f9530 = 0;
    DAT_011f9534 = 0;
    DAT_011f9538 = 0;
    DAT_011f953c = 0;
    DAT_011f9540 = 0;
    DAT_011f9544 = 0;
    DAT_011f95d4 = 0;
    DAT_011f91c4 = false;
    DAT_011ad80c = true;
    DAT_011f91dc = false;
    DAT_011f91a4 = true;
    DAT_011f9178 = 0;
    reinterpret_cast<NiPointer<NiRefObject>&>(DAT_011f95ec) = 0;
    DAT_011f9181 = false;
    FUN_00b54000(75.0f);
    DAT_011f9184 = DAT_011f9188 = DAT_011f918c = DAT_011f9190 = 1.0f;
    DAT_011f91a3 = false;
    DAT_011f9182 = false;
    DAT_011f9180 = false;
    DAT_011f917c = 0;
    DAT_011f94a4 = false;
    DAT_011f94a6 = false;
    DAT_011f91ac = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

template <> __declspec(noinline) bool NamedObjectMapBase::GetAt(
    const char* key, NiPointer<NiRefObject>& value) const
{
    unsigned int index = KeyToHashIndex(key);
    for (EntryType* item = m_ppkHashTable[index]; item; item = item->m_pkNext)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            value = item->m_val;
            return true;
        }
    }
    return false;
}

NamedObjectMap* __cdecl GetNiTStringMap();

// Looks up pcName in the named map and returns true if a non-null object is found.
// @fnv 0x00b58720
bool __cdecl IsNamedObjectPresent(const char* pcName)
{
    bool bFound = false;
    if (pcName)
    {
        NiPointer<NiRefObject> spRetainedObject;
        if (GetNiTStringMap()->GetAt(pcName, spRetainedObject) && spRetainedObject)
            bFound = true;
    }
    return bFound;
}

struct FUN_00ba3a00
{
    unsigned int unk00, unk04, unk08, unk0c;
    ~FUN_00ba3a00();
    static void operator delete(void* p)
    {
        DAT_011f6238.Free(p);
    }
};
struct Param
{
    virtual ~Param();
};
template <class T> struct Values
{
    unsigned int unk00;
    T** values;
    unsigned int unk08, unk0c;
    void FUN_00ba3aa0(int, T**);
};
struct FUN_00ba3d30
{
    virtual ~FUN_00ba3d30();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
};
struct FUN_00b5a110 : FUN_00ba3d30
{
    Values<Param> params;
    Values<FUN_00ba3a00> items;
    unsigned int unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c,
        unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
    FUN_00ba3a00 storageA4;
    FUN_00ba3a00 storageB4[2];
    virtual ~FUN_00b5a110();
};
// Destructor that deletes the item at index 2 and the params at indices 1 and 0, clearing each slot via FUN_00ba3aa0.
// @fnv 0x00b5a110
FUN_00b5a110::~FUN_00b5a110()
{
    if (items.values[2])
    {
        delete items.values[2];
        FUN_00ba3a00* p = 0;
        items.FUN_00ba3aa0(2, &p);
    }
    if (params.values[1])
    {
        delete params.values[1];
        Param* p = 0;
        params.FUN_00ba3aa0(1, &p);
    }
    if (params.values[0])
    {
        delete params.values[0];
        Param* p = 0;
        params.FUN_00ba3aa0(0, &p);
    }
}

struct NiRenderer;
extern NiRenderer* DAT_011f9508;
namespace nb {
struct Accum
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
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void SetTarget(int idx, int p);
};
struct Rend
{
    char pad[0x8b8];
    Accum* m_8b8;
};
}
// @fnv 0x00b55ac0
// src: COMMUNITY 0x00b55ac0
void __cdecl BSShaderManager_RenderImageSpaceEffects(int a, int b, int c)
{
    DAT_011f91ac->RenderEndOfFrameEffects((GraphicsRenderer*)a, (BSRenderedTexture**)&b, (BSRenderedTexture**)&c);
    for (int i = 0; i < 8; i++)
        ((nb::Rend*)DAT_011f9508)->m_8b8->SetTarget(i, 0);
}

extern long DAT_011f4400;

class SpawnedBase_b581c0
{
  public:
    virtual void Vslot00();
    ~SpawnedBase_b581c0()
    {
        InterlockedDecrement((volatile long*)&DAT_011f4400);
    }
    int unk04;
};

class __declspec(novtable) FUN_00b581c0_cls : public SpawnedBase_b581c0
{
  public:
    NiPointer<NiRefObject> m_08;
    int unk0c, unk10, unk14;
    NiPointer<NiRefObject> m_18;
    NiPointer<NiRefObject> m_1c;
    NiPointer<NiRefObject> m_20;
    NiPointer<NiRefObject> m_24;
    ~FUN_00b581c0_cls();
};

// @fnv 0x00b581c0
FUN_00b581c0_cls::~FUN_00b581c0_cls()
{}

void BSFadeNode_FreeLinkedNodesRecursively();
// @fnv 0x00b4e140
// src: GUESS 0x00b4e140 (confidence: low)
void Object_ForwardCall_00b4e140()
{
    BSFadeNode_FreeLinkedNodesRecursively();
}

struct FUN_00b58530_Obj
{
    void ProcessEntries_00b58530();
};
struct FUN_00b595a0_cls
{
    void j_au_re_GameHeapFree_33();
};
// @fnv 0x00b595a0
// src: COMMUNITY 0x00b595a0
void FUN_00b595a0_cls::j_au_re_GameHeapFree_33()
{
    reinterpret_cast<FUN_00b58530_Obj*>(this)->ProcessEntries_00b58530();
}

void* __cdecl B59890GetMap();
struct B59890Value
{
    ~B59890Value();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
template <class TAlloc, class TKEY, class TVAL>
inline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; ++i)
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    return 0;
}

extern int DAT_011f963c;
extern int DAT_011f9640;
// Iterates the map from its first position, deletes each stored value, then removes all entries and resets DAT_011f963c and DAT_011f9640 to zero.
// @fnv 0x00b59890
void ClearMap()
{
    void* pkItem = ((RenderItemMap*)B59890GetMap())->GetFirstPos();
    void* pos = pkItem;
    RTEntry* volatile value = 0;
    unsigned int key;
    if (((RenderItemMap*)B59890GetMap())->m_kItemCount.m_uiCount > 0 && pkItem != 0)
    {
        do
        {
            ((RenderItemMap*)B59890GetMap())->GetNext(pos, key, (RTEntry*&)value);
            delete (B59890Value*)value;
        } while (pos != 0);
    }
    ((RenderItemMap*)B59890GetMap())->RemoveAll();
    DAT_011f963c = 0;
    DAT_011f9640 = 0;
}

// ImageSpaceEffect-derived constructor. The native base constructor already
// constructs its five arrays; this body resizes the existing array at0x28.
struct EffectArray480
{
    virtual void Method();
    void* data;
    unsigned short capacity, size, effectiveSize, growBy;
    void FUN_00a90180(unsigned size);
};
struct FUN_00ba4080
{
    virtual ~FUN_00ba4080();
    bool active, enabled;
    EffectArray480 array08, array18, array28, array38, array48;
    FUN_00ba4080();
};
struct FUN_00b5a410 : FUN_00ba4080
{
    unsigned unk58, unk5c, unk60, unk64, unk68;
    float amount6c, amount70;
    FUN_00b5a410();
    virtual ~FUN_00b5a410();
};
// @fnv 0x00b5a410
FUN_00b5a410::FUN_00b5a410()
{
    array28.FUN_00a90180(2);
    amount6c = 0.5f;
    amount70 = 0.5f;
}

// @fnv 0x00b5a8c0
// src: COMMUNITY 0x00b5a8c0
void __stdcall ShadowSceneNode_EnableTestLight(int, int, int, int, int, int)
{}

struct FUN_00b59c20 : FUN_00ba3d30
{
    struct Values_Param
    {
        unsigned int unk00;
        Param** values;
        unsigned int unk08;
        unsigned int unk0c;
        void __thiscall FUN_00ba3aa0(int, Param* const&) throw();
    } params;
    virtual ~FUN_00b59c20();
};

// Deletes the first Param in params.values and resets the params container when it is non-null.
// @fnv 0x00b59c20
__thiscall FUN_00b59c20::~FUN_00b59c20()
{
    if (params.values[0])
    {
        delete params.values[0];
        params.FUN_00ba3aa0(0, 0);
    }
}

struct TextureDesc
{
    virtual void vf00();
    virtual void vf04();
    long m_iObjectReferenceCount;
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
    unsigned char unkEC;
    unsigned char unkED;
    unsigned char unkEE;
    unsigned char unkEF;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    void IncRefCount()
    {
        InterlockedIncrement(&m_iObjectReferenceCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_iObjectReferenceCount))
            vf04();
    }
};

struct RefPtr_b9fcc0
{
    TextureDesc* ptr;
    ~RefPtr_b9fcc0()
    {
        if (ptr)
            ptr->DecRefCount();
    }
};
struct TextureNode
{
    TextureNode* next;
    TextureNode* prev;
    RefPtr_b9fcc0 value;
};
struct List_b9fcc0
{
    TextureNode* head;
    TextureNode* tail;
    unsigned int count;
    RefPtr_b9fcc0 FUN_00b9fcc0(const RefPtr_b9fcc0& value);
    TextureNode* Find(const RefPtr_b9fcc0& value)
    {
        TextureNode* pos = head;
        while (pos)
        {
            TextureNode* found = pos;
            const RefPtr_b9fcc0& data = pos->value;
            pos = pos->next;
            if (value.ptr == data.ptr)
                return found;
        }
        return 0;
    }
};
struct TextureOwner
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
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    List_b9fcc0 m_b4;
    List_b9fcc0 m_c0;
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
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;

    void RemoveLightFromNode(const RefPtr_b9fcc0& value, TextureNode** pos);
    void ShadowSceneNode_RemoveQueuedLight(const RefPtr_b9fcc0& value);
};

// If value.ptr->unk240 differs from unk1E0 adds value to m_c0 or m_b4, otherwise finds it there and calls RemoveLightFromNode; unkEC picks the list.
// @fnv 0x00b5ef90
// src: COMMUNITY 0x00b5ef90
void TextureOwner::ShadowSceneNode_RemoveQueuedLight(const RefPtr_b9fcc0& value)
{
    if (value.ptr->unk240 != unk1E0)
    {
        if (value.ptr->unkEC)
            m_c0.FUN_00b9fcc0(value);
        else
            m_b4.FUN_00b9fcc0(value);
    }
    else
    {
        TextureNode* pos;
        if (value.ptr->unkEC)
            pos = m_c0.Find(value);
        else
            pos = m_b4.Find(value);
        if (pos)
            RemoveLightFromNode(value, &pos);
    }
}

extern void* __cdecl FUN_00ec61c0(void* dest, int value, unsigned int count);
extern void* __cdecl _NiMalloc_00aa1070(unsigned int size);

void* __cdecl NiMallocB58(unsigned int uiSize);
extern "C" void* __cdecl MemSetB58(void* pvDest, int iValue, unsigned int uiSize);

template <class TAlloc, class TKEY, class TVAL>
inline NiTMapBase<TAlloc, TKEY, TVAL>::NiTMapBase(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_kItemCount.m_uiCount = 0;
    unsigned int uiSize = sizeof(EntryType*) * m_uiHashSize;
    m_ppkHashTable = (EntryType**)NiMallocB58(uiSize);
    MemSetB58(m_ppkHashTable, 0, m_uiHashSize * sizeof(EntryType*));
}

template <class TKEY, class TVAL>
inline NiTPointerMap<TKEY, TVAL>::NiTPointerMap(unsigned int uiHashSize)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, TKEY, TVAL>(uiHashSize)
{}

// Returns the static render-item cache, creating it on first call.
// @fnv 0x00b585c0
// src: GUESS 0x00b585c0 (confidence: medium)
RenderItemMap* __cdecl Object_GetOrCreateRenderItemCache()
{
    static RenderItemMap map(37);
    return &map;
}

// Returns the static named-object cache, creating it on first call.
// @fnv 0x00b58670
NamedObjectMap* __cdecl GetNiTStringMap()
{
    static NamedObjectMap s_kMap;
    return &s_kMap;
}

struct Region;
struct Portal;
struct Frustum;
struct Link
{
    Link* next;
    Link* prev;
    Region* data;
};
struct PoolLock
{
    void Lock(const char*);
    void Unlock();
    volatile int owner;
};
extern PoolLock g_011c5f80;
extern unsigned int DAT_011c5f84;
extern Link* DAT_011c5f58;
void NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();
struct LinkAllocator
{
    unsigned count;
    Link* AddHead();
};
struct Pending
{
    Link* head;
    Link* tail;
    LinkAllocator alloc;
    Pending()
    {
        alloc.count = 0;
        head = 0;
        tail = 0;
    }
    ~Pending()
    {
        FUN_00b71300();
    }
    void FUN_00b71300() throw();
    Region*& getNext(Link*& p)
    {
        Region*& data = p->data;
        p = p->next;
        return data;
    }
    __forceinline void push(Region* data)
    {
        Link* n;
        {
            g_011c5f80.Lock(0);
            n = DAT_011c5f58;
            if (!n)
            {
                NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();
                n = DAT_011c5f58;
            }
            DAT_011c5f58 = n->next;
            n->data = 0;
            n->next = 0;
            n->prev = 0;
            if (!--DAT_011c5f84)
                g_011c5f80.owner = 0;
            Link* oldTail = tail;
            n->data = data;
            n->next = 0;
            n->prev = oldTail;
            if (oldTail)
                oldTail->next = n;
            else
                head = n;
            ++alloc.count;
            tail = n;
        }
    }
    __forceinline Region* pop()
    {
        Link* n = head;
        head = n->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        Region* data = n->data;
        n->data = 0;
        g_011c5f80.Lock(0);
        n->prev = 0;
        n->next = DAT_011c5f58;
        DAT_011c5f58 = n;
        if (!--DAT_011c5f84)
            g_011c5f80.owner = 0;
        --alloc.count;
        return data;
    }
};
struct VisitedList : Pending
{
    ~VisitedList() throw();
};
__declspec(noinline) Link* LinkAllocator::AddHead()
{
    g_011c5f80.Lock(0);
    if (!DAT_011c5f58)
        NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();
    Link* n = DAT_011c5f58;
    DAT_011c5f58 = DAT_011c5f58->next;
    n->data = 0;
    n->next = 0;
    n->prev = 0;
    g_011c5f80.Unlock();
    return n;
}
__declspec(noinline) void Pending::FUN_00b71300() throw()
{
    Link* n = head;
    while (n)
    {
        Link* cur = n;
        n = n->next;
        cur->data = 0;
        g_011c5f80.Lock(0);
        cur->prev = 0;
        cur->next = DAT_011c5f58;
        DAT_011c5f58 = cur;
        if (!--DAT_011c5f84)
            g_011c5f80.owner = 0;
    }
    alloc.count = 0;
    head = 0;
    tail = 0;
}
inline Region*& Next(Link*& p)
{
    Region*& data = p->data;
    p = p->next;
    return data;
}
struct Position
{
    int x, y, z;
};
struct View
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    Position position;
};
extern P03MM _g_memoryManager;
struct Frustum
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int count;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    bool special;
    Frustum();
    ~Frustum() throw();
    static void* operator new(unsigned size)
    {
        return _g_memoryManager.Allocate(size);
    }
    void InitFromArg(View*);
    void BSCompoundFrustum_StartGroupIntersection();
    void BSCompoundFrustum_EndGroup();
    void BSCompoundFrustum_AddOcclusionPlane(Portal*);
    void BSCompoundFrustum_PrethreadOpList();
    bool EvaluateQuery(Portal*);
    void BSCompoundFrustum_MakeIntoUnion();
    void BSCompoundFrustum_AddCompoundFrustum(Frustum*);
    void UpdateRecords(Portal*, int);
    void BSCompoundFrustum_BuildForPortal(Frustum*, Portal*);
};
struct RenderState
{
    int unk00;
    int unk04;
    int state;
};
struct RenderObject
{
    int unk00;
    int unk04;
    int unk08;
    RenderState* state;
    void MakeVisible()
    {
        RenderState* data = state;
        data->state = 1;
    }
};
struct RenderLink
{
    RenderLink* next;
    RenderLink* prev;
    RenderObject* data;
};
struct Region
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    RenderObject* render;
    int unk0b0;
    Link* head;
    int unk0b8;
    int unk0bc;
    Link* portals;
    int unk0c4;
    int count;
    Frustum* frustum;
    RenderLink* renders;
    void SetFieldCC(Frustum*);
};
struct Portal
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int state;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    Region* first;
    Region* second;
    bool BSOcclusionPlane_WithinFrustumDistFirst(int, Position*);
    int GetPackedZeroFlags();
};
struct LinkedChain
{
    Link* head;
    Link* tail;
    unsigned count;
};
struct World
{
    int unk000;
    int unk004;
    LinkedChain portals;
    Link* head;
    int unk018;
    int unk01c;
    void BSPortalGraph_AddRoomToAccumList(Region*);
};
struct Traversal
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    Frustum frustum;
    bool flag1dc;
    World* world;
    void UpdateVisibility(Region*, View*, int, bool);
};
// Flood-fills regions through portals from start, building per-region frustums and marking render objects visible.
// @fnv 0x00b5f170
void Traversal::UpdateVisibility(Region* start, View* view, int arg, bool reset)
{
    VisitedList unused;
    Pending pending;
    unsigned char begun;
    if (reset)
        flag1dc = false;
    frustum.InitFromArg(view);
    Position position = view->position;

    if (!start)
    {
        flag1dc = true;
        if (world->portals.count)
        {
            begun = 0;

            for (Link* pos = world->portals.head; pos;)
            {
                Portal* portal = (Portal*)Next(pos);
                if (portal && (portal->state == 1   ? true
                               : portal->state == 0 ? portal->BSOcclusionPlane_WithinFrustumDistFirst(arg, &position)
                                                    : false))
                {
                    if (!begun)
                    {
                        frustum.BSCompoundFrustum_StartGroupIntersection();
                        begun = true;
                    }
                    frustum.BSCompoundFrustum_AddOcclusionPlane(portal);
                }
            }
            if (begun)
                frustum.BSCompoundFrustum_EndGroup();
        }
        {
            Link* n = pending.alloc.AddHead();
            n->data = 0;
            n->next = 0;
            n->prev = 0;
            pending.head = n;
            pending.tail = n;
            pending.alloc.count = 1;
        }
    }
    else
    {
        Frustum* f = new Frustum;
        f->InitFromArg(view);
        char begun = 0;
        for (Link* pos = start->portals; pos;)
        {
            Portal* portal = (Portal*)Next(pos);
            if (portal && (portal->state == 1 || (portal->state == 0 && portal->BSOcclusionPlane_WithinFrustumDistFirst(arg, &position))))
            {
                if (!begun)
                {
                    f->BSCompoundFrustum_StartGroupIntersection();
                    begun = true;
                }
                f->BSCompoundFrustum_AddOcclusionPlane(portal);
            }
        }
        if (begun)
            f->BSCompoundFrustum_EndGroup();
        start->SetFieldCC(f);
        {
            Link* n = pending.alloc.AddHead();
            n->data = start;
            n->next = 0;
            n->prev = 0;
            pending.head = n;
            pending.tail = n;
            pending.alloc.count = 1;
        }
    }
    do
    {
        Region* current = pending.pop();
        world->BSPortalGraph_AddRoomToAccumList(current);
        Frustum* active;
        Link** source;
        if (current)
        {
            current->render->MakeVisible();
            for (RenderLink* pos = current->renders; pos;)
            {
                RenderObject*& object = pos->data;
                pos = pos->next;
                if (object)
                    object->MakeVisible();
            }
            active = current->frustum;
            source = &current->head;
        }
        else
        {
            flag1dc = true;
            source = &world->head;
            active = &frustum;
        }
        active->BSCompoundFrustum_PrethreadOpList();
        for (Link* pos = *source; pos;)
        {
            Portal* portal = (Portal*)Next(pos);
            if (!portal || portal->state != 0 || !active->EvaluateQuery(portal))
                continue;
            Region* dest = portal->first;
            if (dest == current)
            {
                dest = portal->second;
                if (dest == current)
                    continue;
            }
            if (dest != start)
            {
                pending.push(dest);
                if (dest)
                {
                    if (dest->frustum && dest->frustum->count)
                    {
                        Frustum* pTargetFrustum = dest->frustum;
                        pTargetFrustum->BSCompoundFrustum_MakeIntoUnion();
                        if ((active && active->count) || dest->count)
                        {
                            pTargetFrustum->BSCompoundFrustum_StartGroupIntersection();
                            if (active && active->count)
                                pTargetFrustum->BSCompoundFrustum_AddCompoundFrustum(active);
                        }
                        pTargetFrustum->UpdateRecords(portal, 0);
                        for (Link* it = dest->portals; it;)
                        {
                            Portal* other = (Portal*)Next(it);
                            if (other && active->EvaluateQuery(other))
                                pTargetFrustum->BSCompoundFrustum_AddOcclusionPlane(other);
                        }
                        pTargetFrustum->BSCompoundFrustum_EndGroup();
                        if ((active && active->count) || dest->count)
                            pTargetFrustum->BSCompoundFrustum_EndGroup();
                    }
                    else
                    {
                        Frustum* pTargetFrustum = dest->frustum;
                        if (!pTargetFrustum)
                            pTargetFrustum = new Frustum;
                        pTargetFrustum->InitFromArg(view);
                        Frustum* pSavedFrustum = active;
                        if (active->count > 25)
                            active = 0;
                        if ((active && active->count) || dest->count)
                        {
                            pTargetFrustum->BSCompoundFrustum_StartGroupIntersection();
                            if (active && active->count)
                            {
                                Frustum temp;
                                temp.BSCompoundFrustum_BuildForPortal(active, portal);
                                pTargetFrustum->BSCompoundFrustum_AddCompoundFrustum(&temp);
                            }
                        }
                        pTargetFrustum->UpdateRecords(portal, 0);
                        for (Link* it = dest->portals; it;)
                        {
                            Portal* other;
                            other = (Portal*)Next(it);
                            if (other && (!active || active->EvaluateQuery(other)))
                                pTargetFrustum->BSCompoundFrustum_AddOcclusionPlane(other);
                        }
                        if ((active && active->count) || dest->count)
                        {
                            if (pTargetFrustum->count == 1)
                                pTargetFrustum->InitFromArg(view);
                            else
                                pTargetFrustum->BSCompoundFrustum_EndGroup();
                        }
                        if (!active || active->special || (!active->count && portal->GetPackedZeroFlags() == 15))
                            pTargetFrustum->special = true;
                        active = pSavedFrustum;
                        if (dest->frustum == 0)
                            dest->SetFieldCC(pTargetFrustum);
                    }
                }
                else
                {
                    LinkedChain* portals = &world->portals;
                    if (!frustum.count)
                    {
                        if ((active && active->count) || portals->count)
                        {
                            frustum.BSCompoundFrustum_StartGroupIntersection();
                            if (active && active->count)
                            {
                                Frustum temp2;
                                temp2.BSCompoundFrustum_BuildForPortal(active, portal);
                                frustum.BSCompoundFrustum_AddCompoundFrustum(&temp2);
                            }
                        }
                        frustum.UpdateRecords(portal, 0);
                        for (Link* it = portals->head; it;)
                        {
                            Portal* other = (Portal*)Next(it);
                            if (other && active->EvaluateQuery(other))
                                frustum.BSCompoundFrustum_AddOcclusionPlane(other);
                        }
                        if ((active && active->count) || portals->count)
                            frustum.BSCompoundFrustum_EndGroup();
                        if (!active || (!active->count && portal->GetPackedZeroFlags() == 15))
                            frustum.special = true;
                    }
                    else
                    {
                        frustum.BSCompoundFrustum_MakeIntoUnion();
                        if ((active && active->count) || portals->count)
                        {
                            frustum.BSCompoundFrustum_StartGroupIntersection();
                            if (active && active->count)
                                frustum.BSCompoundFrustum_AddCompoundFrustum(active);
                        }
                        frustum.UpdateRecords(portal, 0);
                        for (Link* it = portals->head; it;)
                        {
                            Portal* other = (Portal*)Next(it);
                            if (other && active->EvaluateQuery(other))
                                frustum.BSCompoundFrustum_AddOcclusionPlane(other);
                        }
                        frustum.BSCompoundFrustum_EndGroup();
                        if ((active && active->count) || portals->count)
                            frustum.BSCompoundFrustum_EndGroup();
                    }
                }
            }
            portal->state = 1;
        }
    } while (pending.alloc.count);
}

struct MemoryManager;
extern MemoryManager g_memoryManager;
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int size);
};
struct MemoryManagerDealloc
{
    void Deallocate(void* p);
};

struct RTTexture;

struct RTKey
{
    int unk00;
    int unk04;
    int unk08;
    RTKey()
    {
        unk08 = 0;
        unk04 = 0;
        unk00 = 0;
    }
};

struct RTItem
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short usTotal;
    unsigned short usUsed;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int uiKey;

    RTItem(RTTexture* tex, unsigned int key, int flags);
    void Setup(RTKey* key);
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<MemoryManagerAllocHelper*>(&g_memoryManager)->Allocate(size);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<MemoryManagerDealloc*>(&g_memoryManager)->Deallocate(p);
    }
};

struct RTNode
{
    RTNode* next;
    RTNode* prev;
    RTItem* data;
};

struct RTItemList
{
    RTNode* head;
    RTNode* tail;
    unsigned int count;
    RTItemList()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
    void* AddHeadItem(RTItem** item);
    static RTItem* GetNext(RTNode*& pos)
    {
        RTItem*& el = pos->data;
        pos = pos->next;
        return el;
    }
};

struct RTTexPtr
{
    RTTexture* obj;
    RTTexPtr()
    {
        obj = 0;
    }
    RTTexPtr& operator=(RTTexture* t);
};

struct RTEntry
{
    RTKey key;
    RTItemList items;
    RTTexPtr tex;
    RTItemList items2;

    RTEntry()
    {}
    static void* operator new(unsigned int size)
    {
        return reinterpret_cast<MemoryManagerAllocHelper*>(&g_memoryManager)->Allocate(size);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<MemoryManagerDealloc*>(&g_memoryManager)->Deallocate(p);
    }
};

extern "C" RTTexture* __cdecl DistantLODShaderProperty_GetCachedGeometry(RTKey* key);

struct RTRenderer
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void Register(int obj, int flag);
};
extern RTRenderer* DAT_011f9644;
extern int DAT_011f9654;
extern int DAT_011f963c;

static __forceinline bool Lookup(int k, RTEntry*& found)
{
    found = 0;
    return Object_GetOrCreateRenderItemCache()->GetAt((unsigned int)k, found);
}

// Finds or creates an RTItem for key using a snapped position value, stores it in *out and returns usTotal minus usUsed.
// @fnv 0x00b596a0
int __cdecl GetOrCreateItem(RTKey* key, unsigned int pos, RTItem** ppItem)
{
    int n = DAT_011f9654;
    unsigned int snap;
    if (n <= 1)
    {
        snap = n;
    }
    else
    {
        short x = (short)pos;
        short y = (short)(pos >> 16);
        y += n / 2 - y % n;
        x += n / 2 - x % n;
        int hi = y << 16;
        snap = (unsigned short)x;
        snap |= hi;
    }
    *ppItem = 0;
    RTTexture* tex = DistantLODShaderProperty_GetCachedGeometry(key);
    if (!tex)
        return 0;
    RTEntry* entry;
    {
        RTEntry* found;
        found = 0;
        if (!Object_GetOrCreateRenderItemCache()->GetAt((unsigned int)key->unk08, found))
        {
            entry = new RTEntry;
            entry->tex = tex;
            entry->key = *key;
            Object_GetOrCreateRenderItemCache()->SetAt((unsigned int)key->unk08, entry);
        }
        else
        {
            entry = found;
        }
    }
    RTItemList& list = entry->items;
    for (RTNode* node = list.head; !*ppItem && node;)
    {
        RTItem* item = RTItemList::GetNext(node);
        if (item->usUsed != item->usTotal && snap == item->uiKey)
        {
            *ppItem = item;
            break;
        }
    }
    if (!*ppItem || (unsigned short)((*ppItem)->usTotal - (*ppItem)->usUsed) == 0)
    {
        *ppItem = new RTItem(tex, snap, 0);
        DAT_011f963c++;
        (*ppItem)->Setup(key);
        list.AddHeadItem(ppItem);
        DAT_011f9644->Register((*ppItem)->unk00, 1);
    }
    return (*ppItem)->usTotal - (*ppItem)->usUsed;
}
