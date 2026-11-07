#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/staging/blk_00d20000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkVector4.h"
#include "../../include/hkArray.h"
#include "../../include/AutoMemContext.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkTransform.h"
#include "../../include/hkRotation.h"


inline hkVector4::hkVector4(const hkVector4& vector) { m_vComponents = vector.m_vComponents; }
inline void hkVector4::operator=(const hkVector4& vector) { m_vComponents = vector.m_vComponents; }
inline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline hkSimdReal hkVector4::getSimdAt3() const
{
    hkSimdReal result;
    result.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    return result;
}
inline hkSimdReal::hkSimdReal() {}
__forceinline void hkVector4::addMul4(const hkSimdReal& scalar, const hkVector4& vector)
{
    m_vComponents = _mm_add_ps(_mm_mul_ps(scalar.m_vValue, vector.m_vComponents), m_vComponents);
}
__forceinline void hkVector4::setNeg4(hkVector4& result, const hkVector4& vector, const __m128& sign)
{
    result.m_vComponents = _mm_xor_ps(vector.m_vComponents, sign);
}


inline void CopyVectorWords(hkVector4& result, const hkVector4& vector)
{
    int* dst = (int*)&result;
    const int* src = (const int*)&vector;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
}
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

#include "../../include/hkpListAgent.h"
#include "../../include/hkpSymmetricAgentFlipBodyCollector.h"

#include <stdio.h>

struct FUN_00d2be30
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    void SetFile(const char* a, const char* b);
};

// @fnv 0x00d2be30
void FUN_00d2be30::SetFile(const char* acPath, const char* acMode)
{
    m_8 = fopen(acPath, acMode);
}

extern "C" void __stdcall FUN_00d2f980(int);
extern int DAT_010ce930;

struct FUN_00d2f220_class
{
    int* p;
    int __thiscall InitializeWithGlobal(int a);
};

// @fnv 0x00d2f220
int __thiscall FUN_00d2f220_class::InitializeWithGlobal(int aiValue)
{
    FUN_00d2f980(aiValue);
    p = &DAT_010ce930;
    return (int)this;
}

void __cdecl hkpCollectionAgent3_process();
void __cdecl Object_InitializeDispatchFunctionTable(int);

// @fnv 0x00d367b0
// src: HAVOK_LIB 0x00d367b0
void __cdecl hkpCollectionAgent3_initAgentFunc(int pObject)
{
    Object_InitializeDispatchFunctionTable(pObject);
    *(void (**)(void))(pObject + 0x2c) = &hkpCollectionAgent3_process;
}

extern "C" void __cdecl hkpListAgent_createListBAgent();
extern "C" void __cdecl hkCollectorD347_ProcessState_00d34790();
extern "C" void __cdecl QueryClosestPoints();
extern "C" void __cdecl hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810();

// Fills the four function pointers at p[0..3] and sets the bytes at offsets 0x10 and 0x11 to 0 and 1.
// @fnv 0x00d36bb0
// src: HAVOK_LIB 0x00d36bb0
void __cdecl hkpListAgent_initAgentFuncInverse(void** p)
{
    p[0] = (void*)&hkpListAgent_createListBAgent;
    p[1] = (void*)&hkCollectorD347_ProcessState_00d34790;
    p[2] = (void*)&QueryClosestPoints;
    p[3] = (void*)&hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810;
    ((char*)p)[0x10] = 0;
    ((char*)p)[0x11] = 1;
}

extern "C" void __cdecl hkpListAgent_createListAAgent();
extern "C" void __cdecl hkpShapeCollectionAgent_staticGetPenetrations();
extern "C" void __cdecl GetClosestPointsShapeCollection();
extern "C" void __cdecl hkpShapeCollectionAgent_staticLinearCast();

// Writes four function pointers into the object at offsets 0, 4, 8 and 12, then sets the bytes at offsets 16 and 17 to 1.
// @fnv 0x00d36c30
// src: HAVOK_LIB 0x00d36c30
void __cdecl hkpListAgent_initAgentFunc(void* apObject)
{
    *(void**)apObject = &hkpListAgent_createListAAgent;
    *(void**)((char*)apObject + 4) = &hkpShapeCollectionAgent_staticGetPenetrations;
    *(void**)((char*)apObject + 8) = &GetClosestPointsShapeCollection;
    *(void**)((char*)apObject + 12) = &hkpShapeCollectionAgent_staticLinearCast;
    *(unsigned char*)((char*)apObject + 16) = 1;
    *(unsigned char*)((char*)apObject + 17) = 1;
}

void CreateRetObj();
void hkpSphereTriangleAgent_staticGetPenetrations();
void hkpCdBody_ProcessAndReturnValue_00d3d8c0();
void Object_ProcessEntries_00daf8e0();

// Fills the first four pointer slots of p with function addresses and clears the two bytes at offsets 0x10 and 0x11.
// @fnv 0x00d3dbe0
// src: GUESS 0x00d3dbe0 (confidence: medium)
void __cdecl Object_InitializeAgentFunctionTable_00d3dbe0(void* apObject)
{
    ((void**)apObject)[0] = (void*)&CreateRetObj;
    ((void**)apObject)[1] = (void*)&hkpSphereTriangleAgent_staticGetPenetrations;
    ((void**)apObject)[2] = (void*)&hkpCdBody_ProcessAndReturnValue_00d3d8c0;
    ((void**)apObject)[3] = (void*)&Object_ProcessEntries_00daf8e0;
    ((unsigned char*)apObject)[0x10] = 0;
    ((unsigned char*)apObject)[0x11] = 0;
}

void __cdecl CreateTargetAgent(void);
void __cdecl QueryD3DCollector(void);
void __cdecl Hkpspheretriangleagent_UpdateState_00d3e110(void);
void __cdecl Object_UpdateFields_00d3ac80(void);

// Fills the first four pointer slots of p with four function pointers and sets the bytes at offsets 0x10 and 0x11 to 1 and 0.
// @fnv 0x00d3dc10
// src: GUESS 0x00d3dc10 (confidence: medium)
void Object_InitializeAgentFunctionTable_00d3dc10(void* apObject)
{
    ((void**)apObject)[0] = (void*)CreateTargetAgent;
    ((void**)apObject)[1] = (void*)QueryD3DCollector;
    ((void**)apObject)[2] = (void*)Hkpspheretriangleagent_UpdateState_00d3e110;
    ((void**)apObject)[3] = (void*)Object_UpdateFields_00d3ac80;
    ((unsigned char*)apObject)[0x10] = 1;
    ((unsigned char*)apObject)[0x11] = 0;
}

namespace fnv_00d3fce0 {
extern "C" void __cdecl Object_ConstructObject_00d3f620();
extern "C" void __cdecl hkpSphereSphereAgent_staticGetPenetrations();
extern "C" void __cdecl hkpSphereSphereAgent_staticGetClosestPoints();
extern "C" void __cdecl Object_ProcessEntries_00daf8e0();

// Stores four function pointers (FUN_00d3f620, FUN_00d3f6a0, FUN_00d3fb20, FUN_00daf8e0) into the first four slots of the object at p.
// @fnv 0x00d3fce0
// src: HAVOK_LIB 0x00d3fce0
void __cdecl hkpSphereSphereAgent_initAgentFunc(void* apObject)
{
    void** a = (void**)apObject;
    a[0] = (void*)Object_ConstructObject_00d3f620;
    a[1] = (void*)hkpSphereSphereAgent_staticGetPenetrations;
    a[2] = (void*)hkpSphereSphereAgent_staticGetClosestPoints;
    a[3] = (void*)Object_ProcessEntries_00daf8e0;
}
}  // namespace fnv_00d3fce0

struct FUN_00db0920 {
    void Init();
};

// @fnv 0x00d3fdf0
void* __cdecl InitAndGetOffset(void* apUnused1, void* apUnused2, void* apObject)
{
    if (apObject)
        ((FUN_00db0920*)apObject)->Init();
    return (char*)apObject + 0x40;
}

struct CollisionAgentFunctionTable {
    void* a;
    void* b;
    void* c;
    void* d;
    char e;
    char f;
};
struct Agent {
    void AppendRecordAndRegisterAgents(CollisionAgentFunctionTable*, int, int);
};
void __cdecl hkpBvTreeStreamAgent_createBvTreeShapeAgent();
void __cdecl hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970();
void __cdecl hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0();
void __cdecl Runtime_CopyMemory_00d2daf0();
void __cdecl hkpBvTreeStreamAgent_createShapeBvAgent();
void __cdecl hkpBvTreeAgent_staticGetPenetrations();
void __cdecl hkpBvTreeAgent_staticGetClosestPoints();
void __cdecl hkTransform_setMulInverseMul_ComputeValues_00d2f0d0();
void __cdecl CreateAgentForBodyPair();
// @fnv 0x00d2dc70
// src: HAVOK_LIB 0x00d2dc70
void __cdecl hkpMoppBvTreeStreamAgent_registerAgent(Agent* pAgent)
{
    CollisionAgentFunctionTable f;
    f.a = (void*)&hkpBvTreeStreamAgent_createBvTreeShapeAgent;
    f.b = (void*)&hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970;
    f.c = (void*)&hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0;
    f.d = (void*)&Runtime_CopyMemory_00d2daf0;
    f.e = 1;
    f.f = 1;
    pAgent->AppendRecordAndRegisterAgents(&f, 10, 18);
    f.a = (void*)&hkpBvTreeStreamAgent_createShapeBvAgent;
    f.b = (void*)&hkpBvTreeAgent_staticGetPenetrations;
    f.c = (void*)&hkpBvTreeAgent_staticGetClosestPoints;
    f.d = (void*)&hkTransform_setMulInverseMul_ComputeValues_00d2f0d0;
    f.e = 0;
    f.f = 1;
    pAgent->AppendRecordAndRegisterAgents(&f, 18, 10);
    f.a = (void*)&CreateAgentForBodyPair;
    f.b = (void*)&hkpBvTreeAgent_staticGetPenetrations;
    f.c = (void*)&hkpBvTreeAgent_staticGetClosestPoints;
    f.d = (void*)&hkTransform_setMulInverseMul_ComputeValues_00d2f0d0;
    f.e = 0;
    f.f = 1;
    pAgent->AppendRecordAndRegisterAgents(&f, 10, 10);
}

// @fnv 0x00d275a0
void ReplaceEntry(int pList, int pOldEntry, int pNewEntry, unsigned short usValue)
{
    int iVar1 = *(int*)(pList + 0x10);
    int pCached = *(int*)(pList + 0x30);
    if (iVar1 == 0)
    {
        if (pCached != 0)
        {
            *(int*)(pCached + 0xc) = pNewEntry;
            *(unsigned short*)(pCached + 0x10) = usValue;
        }
        return;
    }
    if (iVar1 == pOldEntry)
    {
        *(int*)(pList + 0x10) = pNewEntry;
        if (pCached != 0)
        {
            *(int*)(pCached + 0xc) = pNewEntry;
            *(unsigned short*)(pCached + 0x10) = usValue;
        }
        return;
    }
    int pCur = *(int*)(iVar1 + 0x14);
    while (pCur != pOldEntry)
    {
        iVar1 = pCur;
        pCur = *(int*)(pCur + 0x14);
    }
    *(int*)(iVar1 + 0x14) = pNewEntry;
    *(unsigned short*)(iVar1 + 0x12) = usValue;
}

struct FUN_00d27f50_Obj {
    void __thiscall Insert(int a, int b, int c);
    void __thiscall hkSmallArray_hkConstraintInternal_insertAt(int param_1, int param_2);
};

// @fnv 0x00d27f50
// src: COMMUNITY 0x00d27f50
void __thiscall FUN_00d27f50_Obj::hkSmallArray_hkConstraintInternal_insertAt(int aFirst, int aSecond) {
    this->Insert(aFirst, aSecond, 1);
}

struct FUN_00d27f70 {
    int** m_ppIndices;
    int m_iIndexCount;

    FUN_00d27f70(int** indices, int numIndices);
};

// Stores the index array and its count, then fills the array with -1.
// @fnv 0x00d27f70
FUN_00d27f70::FUN_00d27f70(int** indices, int numIndices)
{
    m_ppIndices = indices;
    m_iIndexCount = numIndices;
    for (int i = 0; i < numIndices; i++)
        (*m_ppIndices)[i] = -1;
}

struct FUN_00d27ff0_class {int** values; void __thiscall UnionFindMerge(int first, int second);};
// @fnv 0x00d27ff0
void FUN_00d27ff0_class::UnionFindMerge(int first, int second)
{
    int* data = *values;
    int value = data[first];
    if (first < second) {
        ((volatile int*)data)[first] += data[second];
        (*values)[second] = first;
    } else {
        data[second] += value;
        (*values)[first] = second;
    }
}

struct D28030FixedArray {
    int* m_data;
    int m_iElementCount;

    int& operator[](int i) { return m_data[i]; }
};

struct D28030UnionFind {
    D28030FixedArray& m_pParentArray;

    __forceinline int _findRootOfNode(int i)
    {
        int root = i;
        while (m_pParentArray[root] >= 0)
            root = m_pParentArray[root];
        while (m_pParentArray[i] >= 0) {
            int j = m_pParentArray[i];
            m_pParentArray[i] = root;
            i = j;
        }
        return i;
    }

    void Union(int i, int j);
};

// @fnv 0x00d28030
void D28030UnionFind::Union(int aiNodeA, int aiNodeB)
{
    int iRootA = _findRootOfNode(aiNodeA);
    int iRootB = _findRootOfNode(aiNodeB);
    if (iRootA != iRootB) {
        int iSizeA = m_pParentArray[iRootA];
        if (iRootA < iRootB) {
            m_pParentArray[iRootA] += m_pParentArray[iRootB];
            m_pParentArray[iRootB] = iRootA;
        } else {
            m_pParentArray[iRootB] += iSizeA;
            m_pParentArray[iRootA] = iRootB;
        }
    }
}

struct LinkedIndexArray { int** entries; int count; void hkUnionFind_collapseTree(); };
// For each non-negative entry, follows the chain of indices in entries until a negative value is reached, then advances to the next entry.
// @fnv 0x00d280e0
// src: HAVOK_LIB 0x00d280e0
void LinkedIndexArray::hkUnionFind_collapseTree(){
int* values=*entries; int* current=*entries; int* end=current+count;while(current!=end){if(*current>=0){while(values[*current]>=0){*current=values[*current];values=*entries;}}++current;}
}

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
struct IndexBuffer { int* data; int size; unsigned capacityFlags; };
struct IndexStorage { int* data; };
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*, IndexBuffer*, int);
struct IndexRemapper { IndexStorage* entries; int length; void hkUnionFind_collapseTree(); void RemapIndices(IndexBuffer*); };
// @fnv 0x00d28120
void IndexRemapper::RemapIndices(IndexBuffer* output) {
 hkUnionFind_collapseTree(); int nextIndex=0;
 for(int i=0;i<length;++i) {
  int* values=entries->data; int value=values[i];
  if(value<0) {
   value=-value;
   hkMemoryRouter* manager=hkMemoryRouter_getInstance();
   if(output->size == (output->capacityFlags & 0x3fffffffU)) ResizeAudioStream(manager->m_heap,output,4);
   int* slot = output->data + output->size; __assume(slot != 0); new (slot) int(value);
   ++output->size; entries->data[i]=nextIndex++;
  } else { values[i]=values[value]; }
 }
}

struct hkMemAllocStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& sizeInOut);
    virtual void ReturnMemory(void* p, int size);

    int* bufAllocInts(int& n)
    {
        int s = n * 4;
        void* p = AllocateBufferWithSize(s);
        n = s / 4;
        return (int*)p;
    }
};

struct hkMemCtxStub
{
    int unk00;
    int unk04;
    int unk08;
    hkMemAllocStub* alloc;
    void* mem;

    hkMemAllocStub& temp() { return *alloc; }
    void* heap() { return mem; }
};

hkMemCtxStub* GetMemCtx();
void ArrayReserveImpl(void* mem, void* arr, int numElem, int elemSize);

static __forceinline void IntArrayStub_reserveWith(hkArrayBase<int>& self, void* mem, int n)
{
        int cap = self.m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            ArrayReserveImpl(mem, (&self), n < cap2 ? cap2 : n, 4);
        }
    }

static __forceinline void IntArrayStub_setSizeWith(hkArrayBase<int>& self, void* mem, int n)
{
        IntArrayStub_reserveWith(self, mem, n);
        self.m_iElementCount = n;
    }

struct KeyArrayStub
{
    hkArrayBase<int>* m_keys;
    int m_iElementCount;

    void BuildKeyOffsets(hkArrayBase<int>* counts, hkArrayBase<int>* out);
};

// Sizes out to the key count, builds per-key offsets from counts, then fills out with the index of each key occurrence.
// @fnv 0x00d283e0
void KeyArrayStub::BuildKeyOffsets(hkArrayBase<int>* counts, hkArrayBase<int>* out)
{
    int size = m_iElementCount;
    IntArrayStub_setSizeWith((*(out)), GetMemCtx()->heap(), size);
    int n = counts->m_iElementCount;
    if (n > 0)
    {
        int c = n;
        int* offsets = GetMemCtx()->temp().bufAllocInts(c);
        int capFlags = c ? c : 0x80000000;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            offsets[i] = sum;
            sum += counts->m_data[i];
        }
        int* outData = out->m_data;
        int* keys = m_keys->m_data;
        for (int i = 0; i < m_iElementCount; i++)
        {
            int iKey = keys[i];
            int idx = offsets[iKey];
            offsets[iKey] = idx + 1;
            outData[idx] = i;
        }
        hkMemAllocStub& a = GetMemCtx()->temp();
        if ((capFlags & 0x80000000) == 0)
            a.ReturnMemory(offsets, (capFlags & 0x3fffffff) * 4);
    }
}

namespace fnv_00d2f240 {


inline hkMemoryAllocator& HeapD2F240(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct D2F240Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_iType;
};

struct D2F240Body {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    D2F240Shape* m_pkShape;
};

struct D2F240CdBody {
    D2F240Body* m_pkBody;
};

class D2F240Agent {
public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    D2F240Agent(void* pvMgr) throw();
    virtual ~D2F240Agent();

    static void* operator new(unsigned int uiSize) {
        void* p = HeapD2F240(hkMemoryRouter_getInstance()).blockAlloc(uiSize);
        static_cast<D2F240Agent*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

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
};

class D2F240SymmetricAgent : public D2F240Agent {
public:
    D2F240SymmetricAgent(void* pvMgr) : D2F240Agent(pvMgr) {}
    virtual ~D2F240SymmetricAgent();
};

// Compares the shape types of two bodies and allocates a D2F240Agent if A's type is lower, otherwise a D2F240SymmetricAgent.
// @fnv 0x00d2f240
D2F240Agent* CreateAgentForBodyPair(const D2F240CdBody& kBodyA, const D2F240CdBody& kBodyB, const void* pvInput, void* pvMgr) {
    if (kBodyA.m_pkBody->m_pkShape->m_iType < kBodyB.m_pkBody->m_pkShape->m_iType)
        return new D2F240Agent(pvMgr);
    return new D2F240SymmetricAgent(pvMgr);
}
}  // namespace fnv_00d2f240

typedef void (__cdecl *D2F2C0Func)();

struct D2F2C0AgentFuncs {
    D2F2C0Func m_pCreateFunc;
    D2F2C0Func m_pQueryPenetrationsFunc;
    D2F2C0Func m_getClosestPointsFunc;
    D2F2C0Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

class D2F2C0Dispatcher {
public:
    void registerCollisionAgent(D2F2C0AgentFuncs& f, int typeA, int typeB);
};

void __cdecl hkpBvTreeAgent_createBvTreeShapeAgent();
void __cdecl hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970();
void __cdecl hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0();
void __cdecl Runtime_CopyMemory_00d2daf0();
void __cdecl hkpBvTreeAgent_createShapeBvAgent();
void __cdecl hkpBvTreeAgent_staticGetPenetrations();
void __cdecl hkpBvTreeAgent_staticGetClosestPoints();
void __cdecl hkTransform_setMulInverseMul_ComputeValues_00d2f0d0();
void __cdecl CreateAgentForBodyPair();

// Registers three collision agent function tables with the dispatcher for type pairs (10,-1), (-1,10) and (10,10).
// @fnv 0x00d2f2c0
// src: HAVOK_LIB 0x00d2f2c0
void __cdecl hkpMoppAgent_registerAgent(D2F2C0Dispatcher* dispatcher)
{
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = hkpBvTreeAgent_createBvTreeShapeAgent;
        f.m_pQueryPenetrationsFunc = hkpSymmetricAgentFlipBodyCollector_UpdateState_00d2e970;
        f.m_getClosestPointsFunc = hkpSymmetricAgentFlipCollector_UpdateState_00d2e9b0;
        f.m_pLinearCastFunc = Runtime_CopyMemory_00d2daf0;
        f.m_bIsFlipped = true;
        f.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(f, 10, -1);
    }
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = hkpBvTreeAgent_createShapeBvAgent;
        f.m_pQueryPenetrationsFunc = hkpBvTreeAgent_staticGetPenetrations;
        f.m_getClosestPointsFunc = hkpBvTreeAgent_staticGetClosestPoints;
        f.m_pLinearCastFunc = hkTransform_setMulInverseMul_ComputeValues_00d2f0d0;
        f.m_bIsFlipped = false;
        f.m_bIsPredictive = false;
        dispatcher->registerCollisionAgent(f, -1, 10);
    }
    {
        D2F2C0AgentFuncs f;
        f.m_pCreateFunc = CreateAgentForBodyPair;
        f.m_pQueryPenetrationsFunc = hkpBvTreeAgent_staticGetPenetrations;
        f.m_getClosestPointsFunc = hkpBvTreeAgent_staticGetClosestPoints;
        f.m_pLinearCastFunc = hkTransform_setMulInverseMul_ComputeValues_00d2f0d0;
        f.m_bIsFlipped = false;
        f.m_bIsPredictive = true;
        dispatcher->registerCollisionAgent(f, 10, 10);
    }
}

struct CallTarget_00d2f760 { int hkpBvTreeAgent_updateShapeCollectionFilter(int, int, int, int); };
struct SearchObject {
    int UpdateState_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d2f3d0
// src: GUESS 0x00d2f3d0 (confidence: low)
int SearchObject::UpdateState_00d2f3d0(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiResult = (unsigned int)((CallTarget_00d2f760*)this)->hkpBvTreeAgent_updateShapeCollectionFilter((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)uiResult;
}

namespace fnv_00d2f430 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00d2f430_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void DestroyArray();
    FnvCpu_FUN_00d2f430_CpuObject* FUN_00d2f430(unsigned int flags);
};
// @fnv 0x00d2f430
FnvCpu_FUN_00d2f430_CpuObject* FnvCpu_FUN_00d2f430_CpuObject::FUN_00d2f430(unsigned int flags)
{
    DestroyArray();
    if (flags & 1) {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        (reinterpret_cast<hkMemoryAllocator*>(holder->m_heap))->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d2f430

struct FnvCpu_FUN_00d31730_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d31730_CpuObject {
    void hkpBvTreeAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d31730_CpuCallData*);
    void UpdateState_00d31730(void*, void*, unsigned int, unsigned int);
};
// Builds a call data struct from the arguments and DAT globals, then forwards it to FUN_00d315d0 with second and first swapped.
// @fnv 0x00d31730
// src: GUESS 0x00d31730 (confidence: low)
void FnvCpu_FUN_00d31730_CpuObject::UpdateState_00d31730(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d31730_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpBvTreeAgent_getClosestPoints(second, first, third, &data);
}

namespace fnv_00d327e0 {
extern int DAT_010ceaa8;
extern int DAT_0102e388;


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00d327e0_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    void* m_pData;
    int m_10;
    int m_uiItemCount;

    FUN_00d327e0_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Resets the object's vtable and data, frees the data array via the audio allocator, and frees the object itself when acFlags bit 0 is set.
// @fnv 0x00d327e0
FUN_00d327e0_cls* FUN_00d327e0_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010ceaa8;
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    m_10 = 0;
    int count = m_uiItemCount;
    if (((unsigned int)count & 0x80000000u) == 0) {
        pAllocator->bufFree(m_pData, (unsigned int)(count & 0x3fffffff) * 2);
    }
    m_pData = 0;
    m_uiItemCount = 0x80000000;
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d327e0

extern "C" void __cdecl InitBlockPool(void* p);
extern int DAT_010ced34;

struct FUN_00d36b20_Class {
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    FUN_00d36b20_Class* __thiscall InitializeFields_00d36b20(int param1, int param2, int* param3, int param4);
};

// @fnv 0x00d36b20
// src: GUESS 0x00d36b20 (confidence: low)
FUN_00d36b20_Class* FUN_00d36b20_Class::InitializeFields_00d36b20(int aiUnused1, int aiUnused2, int* piValue, int aiValue) {
    this->unk06 = 1;
    this->unk08 = aiValue;
    this->unk00 = &DAT_010ced34;

    int* data = &this->unk10;
    data[0] = 0;
    data[1] = 0;
    data[2] = 0x80000000;

    this->unk0C = *piValue;
    InitBlockPool(data);
    return this;
}

namespace fnv_00d36be0 {
// FUN_00d36be0 : cdecl factory. Allocates a 0x1c byte block through the global
// allocator holder, stamps the 16-bit size at +4, runs the out-of-line block
// initializer with the arguments in a2, a1, a3, a4 order, stores the vtable
// pointer and returns the block.

extern "C" char DAT_010ced70[];

struct FUN_00d36be0_cls
{
    void* unk00;
    unsigned short m_04;
    void __thiscall InitializeFields_00d36b20(int a, int b, int c, int d);
};


extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x00d36be0
// src: HAVOK_LIB 0x00d36be0
void* __cdecl hkpListAgent_createListAAgent(int a1, int a2, int a3, int a4)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAlloc = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    FUN_00d36be0_cls* pBlock = (FUN_00d36be0_cls*)pAlloc->blockAlloc(0x1c);
    pBlock->m_04 = 0x1c;
    pBlock->InitializeFields_00d36b20(a2, a1, a3, a4);
    pBlock->unk00 = DAT_010ced70;
    return pBlock;
}
}  // namespace fnv_00d36be0

struct FUN_00d36cc0_Obj {
    void __thiscall FUN_00d368c0(int a1, int a2, int a3, int a4);
    void __thiscall ForwardCall_00d36cc0(int param_1, int param_2, int param_3, int param_4);
};

// @fnv 0x00d36cc0
// src: GUESS 0x00d36cc0 (confidence: low)
void __thiscall FUN_00d36cc0_Obj::ForwardCall_00d36cc0(int param_1, int param_2, int param_3, int param_4) {
    this->FUN_00d368c0(param_2, param_1, param_3, param_4);
}

struct FnvCpu_FUN_00d36ce0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d36ce0_CpuObject {
    void hkpListAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d36ce0_CpuCallData*);
    void UpdateFields_00d36ce0(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data struct from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first and third to FUN_00d36940.
// @fnv 0x00d36ce0
// src: GUESS 0x00d36ce0 (confidence: low)
void FnvCpu_FUN_00d36ce0_CpuObject::UpdateFields_00d36ce0(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d36ce0_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpListAgent_getClosestPoints(second, first, third, &data);
}

namespace fnv_00d36f50 {


struct FUN_00d36f50_Obj
{
    void* unk00;
    unsigned short unk04;
    int unk08;
    int unk0C;
    void* unk10;
    int unk14;
    int unk18;

    FUN_00d36f50_Obj* __thiscall FUN_00d36f50(unsigned char flag);
};

extern int DAT_0102e388;
void* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x00d36f50
FUN_00d36f50_Obj* __thiscall FUN_00d36f50_Obj::FUN_00d36f50(unsigned char flag)
{
    hkMemoryRouter* manager = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = reinterpret_cast<hkMemoryAllocator*>(manager->m_heap);
    int capacity = unk18;

    unk14 = 0;
    if ((capacity & 0x80000000) == 0)
        allocator->bufFree(unk10, (unsigned int)(capacity & 0x3fffffff) * 4);

    unk10 = 0;
    unk18 = 0x80000000;
    unk00 = &DAT_0102e388;

    if (flag & 1)
    {
        manager = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        allocator = reinterpret_cast<hkMemoryAllocator*>(manager->m_heap);
        allocator->blockFree(this, unk04);
    }

    return this;
}
}  // namespace fnv_00d36f50

extern float DAT_0104da48;

class D37B90Collector {
public:
    D37B90Collector(int iFilter) : m_fEarlyOutDistance(DAT_0104da48), m_iFilter(iFilter) {}
    virtual void AddCdPoint(const void* pkEvent);

    float m_fEarlyOutDistance;
    int m_iFilter;
};

class D37B90Agent {
public:
    void hkpMultiRayConvexAgent_getClosestPoints(void* pkA, void* pkB, void* pkInput, D37B90Collector* pkCollector);
    void hkpSymmetricAgentLinearCast_hkpMultiRayConvexAgent_getClosestPoints(void* pkA, void* pkB, void* pkInput, int iFilter);
};

// Constructs a D37B90Collector with iFilter and runs FUN_00d37010 with pkB, pkA, pkInput and the collector.
// @fnv 0x00d37b90
// src: XBOX_PDB 0x00d37b90
void D37B90Agent::hkpSymmetricAgentLinearCast_hkpMultiRayConvexAgent_getClosestPoints(void* pkA, void* pkB, void* pkInput, int iFilter)
{
    D37B90Collector kCollector(iFilter);
    hkpMultiRayConvexAgent_getClosestPoints(pkB, pkA, pkInput, &kCollector);
}

namespace fnv_00d37da0 {


inline hkMemoryAllocator& HeapD37DA0(hkMemoryRouter* holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
}
hkMemoryRouter* hkMemoryRouter_getInstance();



struct S_00d37da0_Agent : hkReferencedObject {
    void* m_pContactManager;
    S_00d37da0_Agent(void* mgr) : m_pContactManager(mgr) {}
    virtual void getPenetrations();
};

struct S_00d37da0_Shape {
    int unk0[8];
};

struct S_00d37da0_CdBody {
    char* m_pCollisionShape;
};

struct S_00d37da0_Plane {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

void hkpCollideTriangleUtil_setupClosestPointTriangleCache(const void* verts, S_00d37da0_Plane* out) throw();

struct S_00d37da0_TriAgent : S_00d37da0_Agent {
    S_00d37da0_Plane m_kTriangleNormal;
    unsigned short m_ids[8];
    virtual void getPenetrations();
    __forceinline S_00d37da0_TriAgent(const S_00d37da0_CdBody& bodyA, void* mgr) : S_00d37da0_Agent(mgr)
    {
        for (int i = 0; i < 8; i++)
            m_ids[i] = 0xffff;
        hkpCollideTriangleUtil_setupClosestPointTriangleCache(bodyA.m_pCollisionShape + 0x20, &m_kTriangleNormal);
    }
};

// Allocates and constructs a TriAgent from bodyA and mgr, returning it as an Agent pointer.
// @fnv 0x00d37da0
S_00d37da0_Agent* CreateTriAgent(const void* a1, const S_00d37da0_CdBody& bodyA, const void* a3, void* mgr)
{
    return new S_00d37da0_TriAgent(bodyA, mgr);
}
}  // namespace fnv_00d37da0

void __cdecl ReleaseHandles(int a1, int a2, int a3, int a4);

// @fnv 0x00d39130
// src: GUESS 0x00d39130 (confidence: medium)
void __cdecl Runtime_ReleaseHandles_Thunk(int a1, int a2, int a3, int a4, int a5)
{
    ReleaseHandles(a1, a2, a3, a4);
}

namespace fnv_00d398c0 {
extern "C" void* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl ComputeInverseLengths(const void*, void*);

struct FUN_00d398c0_Vtable
{
    virtual void Method();
};


struct FUN_00d398c0_Object
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short unk10;
    unsigned short unk12;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    char unk18;
    char unk19;
    char unk1a;
    char unk1b;
    char unk1c;
    char unk1d;
    char unk1e;
    char unk1f;
    char unk20;
    char unk21;
    char unk22;
    char unk23;
    char unk24;
    char unk25;
    char unk26;
    char unk27;
};

extern FUN_00d398c0_Vtable DAT_010ceefc;

// @fnv 0x00d398c0
extern "C" void* __cdecl CreateObjectFromFactory(
    int aiUnused,
    int* param_2,
    int aiUnused2,
    int aiValue)
{
    hkMemoryRouter* factory =
        reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());

    FUN_00d398c0_Object* object =
        reinterpret_cast<FUN_00d398c0_Object*>(
            (reinterpret_cast<hkMemoryAllocator*>(factory->m_heap))->blockAlloc(0x28));

    object->unk00 = reinterpret_cast<void*>(&DAT_010ceefc);
    object->unk04 = 0x28;
    object->unk06 = 1;
    object->unk08 = aiValue;
    object->unk0c = 0xffff;
    object->unk0e = 0xffff;
    object->unk10 = 0xffff;

    ComputeInverseLengths(
        reinterpret_cast<const void*>(
            static_cast<unsigned int>(*reinterpret_cast<int*>(param_2)) + 0x20),
        reinterpret_cast<void*>(&object->unk14));

    return object;
}
}  // namespace fnv_00d398c0

namespace fnv_00d3b380 {
extern unsigned int DAT_010cef94;

struct FUN_00d3b380_object
{
    unsigned int* unk00;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    unsigned short unk10;
};


extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// Allocates a 0x14-byte object from the singleton's allocator and initializes its fields, storing param_4 and a global pointer.
// @fnv 0x00d3b380
// src: HAVOK_LIB 0x00d3b380
void __cdecl hkpCapsuleCapsuleAgent_createCapsuleCapsuleAgent(int aiUnused1, int aiUnused2, int aiUnused3,
                         unsigned int auiValue)
{
    hkMemoryRouter* singleton = hkMemoryRouter_getInstance();
    FUN_00d3b380_object* object = static_cast<FUN_00d3b380_object*>(reinterpret_cast<hkMemoryAllocator*>(singleton->m_heap)->blockAlloc(0x14));

    object->unk04 = 0x14;
    object->unk06 = 1;
    object->unk08 = auiValue;
    object->unk00 = &DAT_010cef94;
    object->unk0c = 0xffff;
    object->unk0e = 0xffff;
    object->unk10 = 0xffff;
}
}  // namespace fnv_00d3b380

struct FnvCpu_FUN_00d3f480_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d3f480_CpuObject {
    void hkpSphereCapsuleAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d3f480_CpuCallData*);
    void hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data record from the fourth argument, a global float and a global byte, then forwards it with the other arguments to FUN_00d3e850.
// @fnv 0x00d3f480
// src: XBOX_PDB 0x00d3f480
void FnvCpu_FUN_00d3f480_CpuObject::hkpSymmetricAgentLinearCast_hkpSphereCapsuleAgent_getClosestPoints(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d3f480_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpSphereCapsuleAgent_getClosestPoints(second, first, third, &data);
}

extern float DAT_0104da48;

struct S_00d3f4c0_Obj {
    virtual void vfn0();
    float unk04;
    int unk08;
    S_00d3f4c0_Obj(int a) : unk04(DAT_0104da48), unk08(a) {}
};

void* __cdecl FUN_00d3ebe0(void* a, void* b, void* c, S_00d3f4c0_Obj* o);

// Constructs an S_00d3f4c0_Obj from d and DAT_0104da48, then calls FUN_00d3ebe0 with b, a, c and the object.
// @fnv 0x00d3f4c0
// src: GUESS 0x00d3f4c0 (confidence: low)
void* __cdecl Object_ProcessAndReturnValue_00d3f4c0(void* a, void* b, void* c, int iValue)
{
    S_00d3f4c0_Obj obj(iValue);
    return FUN_00d3ebe0(b, a, c, &obj);
}

namespace fnv_00d3f620 {


inline hkMemoryAllocator& HeapD3F620(hkMemoryRouter* holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
}hkMemoryRouter* hkMemoryRouter_getInstance() throw();

struct S_00d3f620_Mid : hkReferencedObject {
    int unk08;
    S_00d3f620_Mid(int a) throw() { unk08 = a; }
};
struct S_00d3f620_Obj : S_00d3f620_Mid {
    unsigned short unk0c;
    S_00d3f620_Obj(int a) throw() : S_00d3f620_Mid(a) { unk0c = 0xffff; }
    virtual ~S_00d3f620_Obj() throw();
};
// Allocates and constructs an S_00d3f620_Obj with a4, returning the new object.
// @fnv 0x00d3f620
// src: GUESS 0x00d3f620 (confidence: medium)
S_00d3f620_Obj* __cdecl Object_ConstructObject_00d3f620(int a1, int a2, int a3, int aiValue) {
    return new S_00d3f620_Obj(aiValue);
}
}  // namespace fnv_00d3f620

void __cdecl hkpSphereSphereAgent_initAgentFunc(CollisionAgentFunctionTable*);
// @fnv 0x00d3fd00
// src: GUESS 0x00d3fd00 (confidence: low)
void __cdecl Object_UpdateFields_00d3fd00(Agent* agent) {
    CollisionAgentFunctionTable funcs;
    funcs.e = 0;
    funcs.f = 0;
    hkpSphereSphereAgent_initAgentFunc(&funcs);
    agent->AppendRecordAndRegisterAgents(&funcs, 1, 1);
}

struct FUN_00d3fd60_cls_Entry { unsigned short m_key; unsigned short m_uiFilterValue; };

struct FUN_00d3fd60_cls
{
    unsigned char m_unk00;
    unsigned char m_unk01;
    FUN_00d3fd60_cls_Entry m_entries[7];
    unsigned short m_key7;
    unsigned char m_unk32;
    unsigned char m_uiItemCount;
    void __thiscall RemoveEntry(int index);
};

struct FUN_00d3fd60_cls_Ref
{
    unsigned char m_unk00;
    unsigned char m_unk01;
    unsigned char m_iObjectReferenceCount;
};

// @fnv 0x00d3fd60
void* __cdecl RemoveEntryByKey(FUN_00d3fd60_cls_Ref* ref, FUN_00d3fd60_cls* table, unsigned short key)
{
    int count = table->m_uiItemCount;
    if (count > 0)
    {
        int i = 0;
        FUN_00d3fd60_cls_Entry* e = (FUN_00d3fd60_cls_Entry*)((char*)table + 2);
        do
        {
            if (e->m_key == key)
            {
                table->RemoveEntry(i);
                ref->m_iObjectReferenceCount--;
                return ref;
            }
            i++;
            e++;
        } while (i < count);
        return (void*)i;
    }
    return 0;
}

struct FUN_00d3fda0_entry {
    unsigned short key00;
    unsigned short val02;
};

struct FUN_00d3fda0_table {
    unsigned short unk00;
    FUN_00d3fda0_entry entries[7];
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char count;
};

// @fnv 0x00d3fda0
int __cdecl FindOrClaimEntry(int unused, FUN_00d3fda0_table* table, unsigned short value) {
    int i = 0;
    int n = table->count;
    if (n > 0) {
        FUN_00d3fda0_entry* e = &table->entries[0];
        do {
            if (e->key00 == 0xffff) {
                table->entries[i].key00 = value;
                goto found;
            }
            ++i;
            ++e;
        } while (i < n);
    }
found:
    return i;
}

struct D3FE10Agent {
    unsigned short m_flags;
    unsigned short m_iOwnerObjectOffset;
};

struct D3FE10Entry {
    D3FE10Agent m_pAgents[8];
    unsigned char unk20;
    unsigned char m_numAgents;
    unsigned short unk22;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

struct D3FE10Header {
    unsigned short unk00;
    unsigned char m_iNumberOfEntries;
};

class D3FE10Manager {
public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void ResetAgent(unsigned short id, void* pkInfo);
};

// @fnv 0x00d3fe10
D3FE10Entry* __cdecl ResetEntryAgents(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, void* pkInfo)
{
    for (int i = 0; i < pkEntry->m_numAgents; i++) {
        unsigned short id = pkEntry->m_pAgents[i].m_iOwnerObjectOffset;
        if (id != 0xffff)
            pkManager->ResetAgent(id, pkInfo);
    }
    pkEntry->m_numAgents = 0;
    pkHeader->m_iNumberOfEntries = 0;
    return pkEntry + 1;
}

// The parent-array reference at +0 identifies hkUnionFind; include/hkUnionFind.h is not available.
class hkUnionFind {
public:
    int FindRoot(int i);

    hkArray<int>& m_pParentArray;
};

// Walks the parent array to the root of element i, then path-compresses the chain so every visited element points at the root, and returns the last element index.
// @fnv 0x00d27fb0
int hkUnionFind::FindRoot(int aiIndex)
{
    int root = aiIndex;
    while (m_pParentArray[root] >= 0)
        root = m_pParentArray[root];

    while (m_pParentArray[aiIndex] >= 0) {
        int j = m_pParentArray[aiIndex];
        m_pParentArray[aiIndex] = root;
        aiIndex = j;
    }
    return aiIndex;
}

extern int DAT_010ce81c;
struct SpawnedBuf { void* m_iWordAt00; unsigned char m_iWordAt04; int m_8; };
struct Wrapper {
    void ForwardToFunction(int,int,int,SpawnedBuf*);
    void hkpSymmetricAgentLinearCast_hkpMultiRayConvexAgent_getPenetrations(int a,int b,int c,int d);
};
// Builds a SpawnedBuf pointing at DAT_010ce81c with the given value and passes it to ForwardToFunction along with b, a and c.
// @fnv 0x00d37bd0
// src: XBOX_PDB 0x00d37bd0
void Wrapper::hkpSymmetricAgentLinearCast_hkpMultiRayConvexAgent_getPenetrations(int a,int b,int c,int d) {
    SpawnedBuf s;
    s.m_8=d; s.m_iWordAt04=0; s.m_iWordAt00=&DAT_010ce81c;
    ForwardToFunction(b,a,c,&s);
}

typedef void (*CallbackD3D)();

void CreateRetObj();
void hkpSphereTriangleAgent_staticGetPenetrations();
void hkpCdBody_ProcessAndReturnValue_00d3d8c0();
void Object_ProcessEntries_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void Hkpspheretriangleagent_UpdateState_00d3e110();
void Object_UpdateFields_00d3ac80();

struct AgentFuncsD3D {
    AgentFuncsD3D() : m_bA(false), m_bB(false) {}

    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};

static __declspec(noinline) void InitFuncsB(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateRetObj;
    pkFuncs->m_pfnB = hkpSphereTriangleAgent_staticGetPenetrations;
    pkFuncs->m_pfnC = hkpCdBody_ProcessAndReturnValue_00d3d8c0;
    pkFuncs->m_pfnD = Object_ProcessEntries_00daf8e0;
    pkFuncs->m_bA = false;
    pkFuncs->m_bB = false;
}

static __declspec(noinline) void InitFuncsA(AgentFuncsD3D* pkFuncs)
{
    pkFuncs->m_pfnA = CreateTargetAgent;
    pkFuncs->m_pfnB = QueryD3DCollector;
    pkFuncs->m_pfnC = Hkpspheretriangleagent_UpdateState_00d3e110;
    pkFuncs->m_pfnD = Object_UpdateFields_00d3ac80;
    pkFuncs->m_bA = true;
    pkFuncs->m_bB = false;
}

void (*g_apfnInitD3D[2])(AgentFuncsD3D*) = { InitFuncsA, InitFuncsB };

class DispatcherD3D {
public:
    void RegisterAgent(AgentFuncsD3D* pkFuncs, int iA, int iB);
};

// Registers two D3D agent function sets with the dispatcher: one initialized by InitFuncsA with (3,1) and one by InitFuncsB with (1,3).
// @fnv 0x00d3dc40
void __cdecl RegisterD3DAgents(DispatcherD3D* pkDispatcher)
{
    {
        AgentFuncsD3D kFuncs;
        InitFuncsA(&kFuncs);
        pkDispatcher->RegisterAgent(&kFuncs, 3, 1);
    }
    {
        AgentFuncsD3D kFuncs;
        InitFuncsB(&kFuncs);
        pkDispatcher->RegisterAgent(&kFuncs, 1, 3);
    }
}

struct D27690_Atom {
    unsigned short m_type;
};

struct D27690_ConstraintInfo {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct D27690_Modifier {
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_usModifierAtomSize;
    unsigned short m_childResult;
    D27690_Atom* m_pChildAtom;

    void addModifierDataToConstraintInfo(D27690_ConstraintInfo* info, unsigned char* flags);
};

struct D27690_Entity {
    int unk000; int unk004; int unk008; int unk00C;
    int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C;
    int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C;
    int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C;
    int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C;
    int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC;
    int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC;
    unsigned short unk0D0;
    unsigned char unkD2;
};

struct D27690_Internal {
    void* m_pHavokConstraint;
    int unk04;
    int unk08;
    D27690_Atom* m_kBridgeAtoms;
    unsigned short m_childResult;
    unsigned short unk12;
    unsigned short m_stats;
};

struct D27690_Instance {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D27690_Modifier* m_pConstraintModifier;
    D27690_Entity* m_pEntityA;
    D27690_Entity* m_pEntityB;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    D27690_Internal* m_pConstraintInternal;
};

struct D27690_Owner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void checkReadOnly();

    int unk04;
    int unk08;
    int m_iElementCount;

    void hkpConstraintOwner_subConstraintInfo(void* unk, D27690_ConstraintInfo* info);
};


extern unsigned short DAT_010cb7a8;

// Removes the modifier of the given type from the instance's chain, updates internal child result and stats, then frees the modifier.
// @fnv 0x00d27690
// src: HAVOK_LIB 0x00d27690
void __cdecl hkpWorldConstraintUtil_removeAndDeleteModifier(D27690_Instance* instance, D27690_Owner* owner, unsigned int modifierType)
{
    owner->checkReadOnly();

    D27690_Modifier* curr = instance->m_pConstraintModifier;
    if (!curr)
        return;

    D27690_Internal* internal = instance->m_pConstraintInternal;

    if (curr->m_type == modifierType)
    {
        D27690_Atom* child = curr->m_pChildAtom;
        if (internal)
        {
            internal->m_kBridgeAtoms = child;
            internal->m_childResult = curr->m_childResult;
        }
        instance->m_pConstraintModifier = (child->m_type >= 0x17) ? (D27690_Modifier*)child : 0;
    }
    else
    {
        D27690_Modifier* prev = curr;
        for (D27690_Atom* child = curr->m_pChildAtom; child->m_type >= 0x17; child = curr->m_pChildAtom)
        {
            curr = (D27690_Modifier*)child;
            if (curr->m_type == modifierType)
            {
                prev->m_pChildAtom = curr->m_pChildAtom;
                prev->m_childResult = curr->m_childResult;
                goto FOUND;
            }
            prev = curr;
        }
        return;
    }

FOUND:
    if (internal)
    {
        D27690_ConstraintInfo info;
        info.unk00 = 0;
        info.unk04 = 0;
        info.unk08 = 0;
        info.unk0C = 0;
        unsigned char flags = 0;

        curr->addModifierDataToConstraintInfo(&info, &flags);

        flags &= (instance->m_pEntityA->unkD2 | instance->m_pEntityB->unkD2);
        unsigned short delta = (&DAT_010cb7a8)[flags & 7];
        owner->m_iElementCount += delta;
        instance->m_pConstraintInternal->m_stats += delta;

        owner->hkpConstraintOwner_subConstraintInfo(internal->m_pHavokConstraint, &info);
    }

    int size = curr->m_usModifierAtomSize;
    hkMemoryRouter* mgr = hkMemoryRouter_getInstance();
    (reinterpret_cast<hkMemoryAllocator*>(mgr->m_heap))->blockFree(curr, size);
}

struct Base {
    int unk4;
    char m_8;
    Base(int a, int b);
    virtual void v0();
};
struct FUN_00d21930 : Base {
    FUN_00d21930(int a, int b);
    virtual void v0();
};
// Constructs the object by forwarding a and b to the Base constructor and setting m_8 to 6.
// @fnv 0x00d21930
FUN_00d21930::FUN_00d21930(int a, int b) : Base(a, b) { m_8 = 6; }

struct FUN_00d219e0_node
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d219e0_node* unk0C;
};
struct FUN_00d219e0_cls
{
    int unk00;
    unsigned char unk04;
    FUN_00d219e0_node* unk08;
    int unk0C;
    FUN_00d219e0_node* unk10;
    int unk14;
    void __thiscall SetLists(FUN_00d219e0_node* a, FUN_00d219e0_node* b);
};
// Walks both linked lists to their tails, stores each tail and the head's unk04 in the object, and sets unk04 to 1.
// @fnv 0x00d219e0
void __thiscall FUN_00d219e0_cls::SetLists(FUN_00d219e0_node* pFirstList, FUN_00d219e0_node* pSecondList)
{
    FUN_00d219e0_node* pTail = pFirstList;
    while (pTail->unk0C)
        pTail = pTail->unk0C;
    unk08 = pTail;
    unk0C = pFirstList->unk04;
    pTail = pSecondList;
    while (pTail->unk0C)
        pTail = pTail->unk0C;
    unk10 = pTail;
    unk14 = pSecondList->unk04;
    unk04 = 1;
}

extern int DAT_0101e594;
struct VtblStub_0101e594 { void* m_ppVirtualMethodTable; };
extern "C" void __cdecl FormHeapFreeAndLog_00401030(VtblStub_0101e594*);
struct FUN_00d26210
{
    void* m_ppVirtualMethodTable;
    FUN_00d26210(char construct);
};
// @fnv 0x00d26210
FUN_00d26210::FUN_00d26210(char construct)
{
    m_ppVirtualMethodTable = &DAT_0101e594;
    if (construct & 1)
        FormHeapFreeAndLog_00401030((VtblStub_0101e594*)this);
}

struct PairEntry
{
	void* m_pCollisionAgent;
	unsigned int m_link0;
	unsigned int m_link1;
	int m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
};

struct PairNode
{
	int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
	int m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
	int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
	int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
	int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c;
	int m_a0, m_a4, m_a8;
	PairEntry* m_entries;
	unsigned short m_iNumberOfEntries;
	unsigned short m_pRayCursor;
};

// Scans both nodes' entry arrays for an entry whose XOR-linked node equals the other node and returns that entry's value, else 0.
// @fnv 0x00d27610
void* __cdecl FindSharedEntryValue(PairNode* pNodeA, PairNode* pNodeB)
{
	PairNode* pNodePair[2];
	pNodePair[0] = pNodeA;
	pNodePair[1] = pNodeB;
	for (int i = 0; i < 2; i++)
	{
		PairNode* self = pNodePair[i];
		PairNode* other = pNodePair[1 - i];
		for (int j = 0; j < self->m_iNumberOfEntries; j++)
		{
			PairEntry* e = &self->m_entries[j];
			if ((PairNode*)(e->m_link1 ^ e->m_link0 ^ (unsigned int)self) == other)
			{
				return self->m_entries[j].m_pCollisionAgent;
			}
		}
	}
	return 0;
}

struct FUN_00d277f0_node
{
    unsigned short unk00;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00d277f0_node* unk14;
};
struct FUN_00d277f0_arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d277f0_node* unk10;
};
// Walks the linked list from a->unk10 while node unk00 is at least 0x17 and returns the last node visited.
// @fnv 0x00d277f0
// src: HAVOK_LIB 0x00d277f0
FUN_00d277f0_node* __cdecl hkpWorldConstraintUtil_findLastModifier(FUN_00d277f0_arg* a)
{
    FUN_00d277f0_node* p = a->unk10;
    if (!p) {
        return p;
    }
    FUN_00d277f0_node* n = p->unk14;
    if (n->unk00 < 0x17) {
        return p;
    }
    do {
        p = n;
        n = n->unk14;
    } while (n->unk00 >= 0x17);
    return p;
}

struct FUN_00d61840_class {
    int m_iWordAt00;
    int __thiscall FUN_00d61c10(int a);
    int __thiscall ReplaceChar(int a, int b, int c);
};
// @fnv 0x00d2b330
int __cdecl CallAndGetId(int a, FUN_00d61840_class* obj)
{
    obj->FUN_00d61c10(a);
    obj->ReplaceChar(0x2f, 0x5c, 1);
    return obj->m_iWordAt00;
}

struct PathHelper {
    char* m_data;

    void __thiscall FUN_00d61c10(const char* s);
    void __thiscall ReplaceChar(char from, char to, int all);
    void __thiscall hkStringBuf_replace(const char* from, const char* to, int all);
    int __thiscall FUN_00d61560(const char* s);
    void __thiscall RemoveFront(int count);
};

// @fnv 0x00d2b360
// src: HAVOK_LIB 0x00d2b360
const char* __cdecl hkNativeFileSystem_nativePlatformToHavokConvertPath(const char* path, PathHelper* aPathHelper)
{
    aPathHelper->FUN_00d61c10(path);
    aPathHelper->ReplaceChar('\\', '/', 1);
    aPathHelper->hkStringBuf_replace("/./", "/", 1);
    if (aPathHelper->FUN_00d61560("./"))
        aPathHelper->RemoveFront(2);
    return aPathHelper->m_data;
}

struct FnvCpu_FUN_00d2c7d0_CpuInterface {
    virtual void Invoke(int value);
};
// @fnv 0x00d2c7d0
// src: GUESS 0x00d2c7d0 (confidence: low)
void __cdecl Runtime_ForwardCall_00d2c7d0(FnvCpu_FUN_00d2c7d0_CpuInterface* object)
{
    object->Invoke(0);
}

class FUN_00d2c7e0 {
public:
    virtual ~FUN_00d2c7e0();
    FUN_00d2c7e0(int count);
};
class ObjD2C840 : public FUN_00d2c7e0 {
public:
    virtual ~ObjD2C840();
    ObjD2C840(int count) : FUN_00d2c7e0(count) {}
    static void* operator new(unsigned int, void* p) throw() { return p; }
    static void operator delete(void*, void*) throw() {}
};
// Placement-constructs an ObjD2C840 with the given count into the provided storage.
// @fnv 0x00d2c840
void __cdecl ConstructObjD2C840(void* storage, int count)
{
    new(storage) ObjD2C840(count);
}

struct FUN_00d04350_Obj
{
    void __thiscall Create(int a, int b);
};
struct FUN_00d2cd80_Obj
{
    int unk00;
    FUN_00d04350_Obj unk04;

    FUN_00d2cd80_Obj* __thiscall ProcessAndReturnValue_00d2cd80();
};
// @fnv 0x00d2cd80
// src: GUESS 0x00d2cd80 (confidence: low)
FUN_00d2cd80_Obj* __thiscall FUN_00d2cd80_Obj::ProcessAndReturnValue_00d2cd80()
{
    FUN_00d2cd80_Obj* self = this;
    self->unk04.Create(0, 6);
    return self;
}

struct SubA { void hkThread_hkThread(); };
struct SubB { void Create(int a, int b); };
struct C_d2cda0 {
    int m_iWordAt00;
    int unk04;
    SubA a8;
    int unk0C, unk10, unk14;
    int m_18;
    int unk1C;
    char m_20;
    char pad21[3];
    SubB b24;
    int m_28;
    int m_2c;
    C_d2cda0* InitializeFields_00d2cda0();
};
// @fnv 0x00d2cda0
// src: GUESS 0x00d2cda0 (confidence: low)
C_d2cda0* C_d2cda0::InitializeFields_00d2cda0()
{
    a8.hkThread_hkThread();
    b24.Create(0, 1);
    m_28 = 0;
    m_2c = 0;
    m_20 = 0;
    m_18 = -1;
    m_iWordAt00 = 0;
    return this;
}

struct FnvCpu_FUN_00d329b0_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d329b0_CpuObject {
    void hkpHeightFieldAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d329b0_CpuCallData*);
    void DispatchWithBound(void*, void*, unsigned int, unsigned int);
};
// Builds a call-data record from the fourth argument, DAT_0104da48 and DAT_010ce7fc, then forwards it to FUN_00d32170 with the first two arguments swapped.
// @fnv 0x00d329b0
void FnvCpu_FUN_00d329b0_CpuObject::DispatchWithBound(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d329b0_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpHeightFieldAgent_getClosestPoints(second, first, third, &data);
}

// @fnv 0x00d32ac0
// src: GUESS 0x00d32ac0 (confidence: low)
int __cdecl Object_ComputeValue_00d32ac0(int param_1, int param_2)
{
    return param_2 + 0x10;
}

// @fnv 0x00d32ad0
// src: GUESS 0x00d32ad0 (confidence: low)
void* __cdecl Runtime_EvaluateValue_00d32ad0(int unused, char* p) {
    return p + 16;
}

extern int DAT_010ce81c;
void __cdecl hkpConvexListAgent_staticGetPenetrations(int b, int a, int c, SpawnedBuf* buffer);
// Initializes a SpawnedBuf with zero, a global pointer and d, then calls FUN_00d33b90 with b, a, c and the buffer.
// @fnv 0x00d34930
void __cdecl InitSpawnedBuffer(int a, int b, int c, int d)
{
    SpawnedBuf buffer;
    buffer.m_iWordAt04 = 0;
    buffer.m_iWordAt00 = &DAT_010ce81c;
    buffer.m_8 = d;
    hkpConvexListAgent_staticGetPenetrations(b, a, c, &buffer);
}

struct FUN_00d34aa0_Obj {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();

    void __thiscall hkpConvexListAgent_updateShapeCollectionFilter(int a, int b, int c, int d);
    virtual void __thiscall HkpConvexListAgent_updateShapeCollectionFilter_Thunk(int a, int b, int c, int d);
};
// @fnv 0x00d34aa0
// src: GUESS 0x00d34aa0 (confidence: medium)
void __thiscall FUN_00d34aa0_Obj::HkpConvexListAgent_updateShapeCollectionFilter_Thunk(int param_1, int param_2, int param_3, int param_4)
{
    hkpConvexListAgent_updateShapeCollectionFilter(param_2, param_1, param_3, param_4);
}

struct FnvCpu_FUN_00d34b00_CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct FnvCpu_FUN_00d34b00_CpuObject {
    void hkpConvexListAgent_getClosestPoints(void*, void*, unsigned int, FnvCpu_FUN_00d34b00_CpuCallData*);
    void DispatchCpuCall(void*, void*, unsigned int, unsigned int);
};
// @fnv 0x00d34b00
void FnvCpu_FUN_00d34b00_CpuObject::DispatchCpuCall(void* first, void* second, unsigned int third, unsigned int fourth)
{
    FnvCpu_FUN_00d34b00_CpuCallData data;
    data.value = fourth;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    hkpConvexListAgent_getClosestPoints(second, first, third, &data);
}

// Scans the first three entries of table for key and, if found, replaces it with 0xffff and returns.
// @fnv 0x00d39030
void RemoveKeyFromTable(int, unsigned short* table, unsigned short key)
{
    for (int i = 0; i < 3; ++i) {
        if (table[i] == key) {
            table[i] = 0xffff;
            return;
        }
    }
}

// Scans the first three slots for the 0xffff empty marker and writes value into the first free one, then returns.
// @fnv 0x00d39060
void __cdecl InsertIntoSlotArray(void* unused, unsigned short* slots, unsigned short value) {
    for (int i = 0; i < 3; ++i) {
        if (slots[i] == 0xffff) {
            slots[i] = value;
            return;
        }
    }
}

// @fnv 0x00d39090
// src: COMMUNITY 0x00d39090
void nullsub_15()
{
}

typedef void (*CallbackD3D)();
void CreateRetObj();
void hkpSphereTriangleAgent_staticGetPenetrations();
void hkpCdBody_ProcessAndReturnValue_00d3d8c0();
void Object_ProcessEntries_00daf8e0();
void CreateTargetAgent();
void QueryD3DCollector();
void Hkpspheretriangleagent_UpdateState_00d3e110();
void Object_UpdateFields_00d3ac80();
struct FUN_00d390a0_Leaf {
    char unk00[0x20];
};
struct FUN_00d390a0_Mid {
    FUN_00d390a0_Leaf* m_pLeafNode;
};
struct FUN_00d390a0_Owner {
    int unk00;
    FUN_00d390a0_Mid* m_mid;
};
struct FUN_00d390a0_Flags {
    char unk00;
    char unk01;
    unsigned char unk02;
};
struct FUN_00d390a0_Out {
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
void __cdecl ComputeInverseLengths(void* a, void* b);
// @fnv 0x00d390a0
char* __cdecl InitOutputDefaults(FUN_00d390a0_Owner* owner, FUN_00d390a0_Flags* flags, FUN_00d390a0_Out* out) {
    FUN_00d390a0_Leaf* leaf = owner->m_mid->m_pLeafNode;
    flags->unk02 = 0;
    out->unk00 = 0xffff;
    out->unk02 = 0xffff;
    out->unk04 = 0xffff;
    ComputeInverseLengths((char*)leaf + 0x20, &out->unk08);
    return (char*)out + 0x20;
}

struct D390Callback {
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(unsigned int key, void* context);
};

struct D390HandleTable {
    unsigned short handles[3];
    unsigned short state06;
    unsigned short state08;
    unsigned short state0a;
    unsigned short state0c;
    unsigned short state0e;
    unsigned short state10;
    unsigned short state12;
    unsigned short state14;
    unsigned short state16;
    unsigned short state18;
    unsigned short state1a;
    unsigned short state1c;
    unsigned short state1e;
    unsigned short state20;
};

// Calls callback->method14 for each non-0xffff handle in handles, marks them 0xffff, and returns &handles->state20.
// @fnv 0x00d390e0
unsigned short* __cdecl ReleaseHandles(void* unused, D390HandleTable* handles, D390Callback* callback, void* context)
{
    for (int index = 0; index < 3; ++index) {
        unsigned int handle = handles->handles[index];
        if ((unsigned short)handle != 0xffff) {
            callback->method14(handle, context);
            handles->handles[index] = 0xffff;
        }
    }
    return &handles->state20;
}

struct D3FD30Funcs {
    D3FD30Funcs() : m_bA(false), m_bB(false) {}
    CallbackD3D m_pfnA;
    CallbackD3D m_pfnB;
    CallbackD3D m_pfnC;
    CallbackD3D m_pfnD;
    bool m_bA;
    bool m_bB;
};
void __cdecl hkpSphereSphereAgent_initAgentFunc(D3FD30Funcs* pkFuncs);
class D3FD30Dispatcher {
public:
    void AddSpawnEntry(D3FD30Funcs* pkFuncs, int iA, int iB);
};

// Builds a D3FD30Funcs via FUN_00d3fce0, then passes it to pkDispatcher->AddSpawnEntry with 1 and 1.
// @fnv 0x00d3fd30
void __cdecl DispatchFuncs(D3FD30Dispatcher* pkDispatcher)
{
    D3FD30Funcs kFuncs;
    hkpSphereSphereAgent_initAgentFunc(&kFuncs);
    pkDispatcher->AddSpawnEntry(&kFuncs, 1, 1);
}

// @fnv 0x00d3fde0
// src: COMMUNITY 0x00d3fde0
void nullsub_16()
{
}

extern int DAT_0102e388;

struct Foo00d24660 {
    void SetVirtualTable_00d24660();
};

// @fnv 0x00d24660
// src: GUESS 0x00d24660 (confidence: low)
void Foo00d24660::SetVirtualTable_00d24660()
{
    *(int*)this = (int)&DAT_0102e388;
}


inline hkMemoryAllocator& HeapD262(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}
namespace hkRouterD262 {
    extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

class FUN_00d496d0 {
public:
    virtual void V0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void SetVirtualTable_00d24660() throw();

    static void operator delete(void* p) throw()
    {
        HeapD262(hkRouterD262::hkMemoryRouter_getInstance()).blockFree(p, static_cast<FUN_00d496d0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d496d0* FUN_00d262e0(unsigned int uiFlags) throw();
};

// Calls FUN_00d24660, then if uiFlags & 1 frees this via operator delete, and returns this.
// @fnv 0x00d262e0
FUN_00d496d0* FUN_00d496d0::FUN_00d262e0(unsigned int uiFlags) throw()
{
    SetVirtualTable_00d24660();
    if (uiFlags & 1)
        FUN_00d496d0::operator delete(this);
    return this;
}

void hkpAgent1nSector_ProcessEntries_00da3510(void*, void*);

// @fnv 0x00d2d460
// src: GUESS 0x00d2d460 (confidence: low)
void Object_ForwardCall_00d2d460(int, void* b, void* c)
{
    hkpAgent1nSector_ProcessEntries_00da3510(b, c);
}

extern unsigned char DAT_011b4284;
// @fnv 0x00d2f530
// src: GUESS 0x00d2f530 (confidence: low)
void __cdecl Runtime_UpdateState_00d2f530(unsigned char* p)
{
    *p = DAT_011b4284;
}

extern unsigned char DAT_011b4284;

// @fnv 0x00d2f540
// src: GUESS 0x00d2f540 (confidence: low)
void __cdecl Object_SetDAT_011b4284_00d2f540(unsigned char value)
{
    DAT_011b4284 = value;
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern "C" void __cdecl GetClosestPointsShapeCollection();

struct D347D0Query {
    const unsigned char* descriptor;
    float bound;
    unsigned int filter;
};

// Builds a D347D0Query from DAT_010ce7fc, DAT_0104da48 and filter, then calls GetClosestPointsShapeCollection with b, a, c and the query.
// @fnv 0x00d347d0
void __cdecl QueryClosestPoints(void* a, void* b, void* c, unsigned int filter)
{
    D347D0Query query = { &DAT_010ce7fc, DAT_0104da48, filter };
    typedef void (__cdecl *Dispatch)(void*, void*, void*, D347D0Query*);
    ((Dispatch)GetClosestPointsShapeCollection)(b, a, c, &query);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct D34970Context {
    void* pointer;
    float maxDistance;
    int option;
};
extern "C" void __cdecl hkpConvexListAgent_QueryClosestPointsAfterHullTest(int first, int second, int third, D34970Context* context);
// Builds a D34970Context from DAT_010ce7fc, DAT_0104da48, and arg3, then calls FUN_00d339d0 with arg1, arg0, arg2, and the context.
// @fnv 0x00d34970
// src: GUESS 0x00d34970 (confidence: low)
void __cdecl Runtime_UpdateState_00d34970(int arg0, int arg1, int arg2, int aiOption) {
    D34970Context context;
    context.pointer = &DAT_010ce7fc;
    context.maxDistance = DAT_0104da48;
    context.option = aiOption;
    hkpConvexListAgent_QueryClosestPointsAfterHullTest(arg1, arg0, arg2, &context);
}

extern int DAT_010ce81c;

struct D34ac0Struct {
    void* e;
    unsigned char f;
    void* g;
};

struct FUN_00d33c80_class {
    void hkpConvexListAgent_getPenetrations(void* a, void* b, void* c, void* d);
    void UpdateFields_00d34ac0(void* a, void* b, void* c, void* d);
};

// Builds a local struct holding &DAT_010ce81c, 0 and d, then calls FUN_00d33c80 with b, a, c and a pointer to the struct.
// @fnv 0x00d34ac0
// src: GUESS 0x00d34ac0 (confidence: low)
void FUN_00d33c80_class::UpdateFields_00d34ac0(void* a, void* b, void* c, void* d)
{
    D34ac0Struct s;
    s.g = d;
    s.f = 0;
    s.e = &DAT_010ce81c;
    hkpConvexListAgent_getPenetrations(b, a, c, &s);
}


struct D3C380_Obj {
    void** vt;
    unsigned short w4;
    unsigned short w6;
    int i8;
    unsigned short wC;
};

extern unsigned int DAT_010cefdc;

// Allocates a 0x10-byte D3C380_Obj via the global hkMemoryRouter, initializes its fields, and returns the pointer.
// @fnv 0x00d3c380
D3C380_Obj* __cdecl CreateD3C380Obj(int aiUnused1, int aiUnused2, int aiUnused3, int aiValue)
{
    hkMemoryRouter* mgr = hkMemoryRouter_getInstance();
    D3C380_Obj* o = (D3C380_Obj*)reinterpret_cast<hkMemoryAllocator*>(mgr->m_heap)->blockAlloc(0x10);
    o->w4 = 0x10;
    o->w6 = 1;
    o->i8 = aiValue;
    o->vt = (void**)&DAT_010cefdc;
    o->wC = 0xFFFF;
    return o;
}

// CreateRetObj: builds a 0x20-byte record from the audio allocation pool.

struct SubBlock
{
    int d0, d1, d2, d3;
};

struct RetObj
{
    void* vtbl;             // 0x00
    unsigned short f04;     // 0x20
    unsigned short f06;     // 1
    int f08;                // param 4
    unsigned short f0c;     // 0xffff
    unsigned short f0e;
    SubBlock m10;
};

extern int DAT_010cf060;
extern void __cdecl hkpCollideTriangleUtil_setupClosestPointTriangleCache(void* src, void* dst);

// Allocates a 0x20-byte object, sets its header fields and vtable pointer, and passes *a2 + 0x20 and its m10 block to FUN_00cd7160.
// @fnv 0x00d3d1a0
void* __cdecl CreateRetObj(int a1, char** a2, int a3, int aiValue)
{
    hkMemoryRouter* o;
    o = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    RetObj* mgr = (RetObj*)reinterpret_cast<hkMemoryAllocator*>(o->m_heap)->blockAlloc(0x20);
    mgr->f04 = 0x20;
    mgr->f06 = 1;
    mgr->f08 = aiValue;
    mgr->f0c = 0xffff;
    mgr->vtbl = (void*)&DAT_010cf060;
    hkpCollideTriangleUtil_setupClosestPointTriangleCache(*a2 + 0x20, &mgr->m10);
    return mgr;
}

extern int DAT_010cf0e4;
struct D3E270_obj {
    void* vt;
    unsigned short f04;
    unsigned short f06;
    int f08;
    unsigned short f0c;
};
struct D3E270_mgr {
    int r00;
    int r04;
    int r08;
    int r0c;
    hkMemoryAllocator* r10;
};

// Allocates a 0x10-byte D3E270_obj via the manager's allocator, sets its size, count and vtable fields, and stores a4 in f08.
// @fnv 0x00d3e270
// src: GUESS 0x00d3e270 (confidence: medium)
D3E270_obj* __cdecl hkMemoryRouter_getInstance_AllocateAndInitializeObject16(int aiUnused1, int aiUnused2, int aiUnused3, int aiValue)
{
    D3E270_mgr* mgr = (D3E270_mgr*)hkMemoryRouter_getInstance();
    D3E270_obj* o = static_cast<D3E270_obj*>(mgr->r10->blockAlloc(0x10));
    o->f04 = 0x10;
    o->f06 = 1;
    o->f08 = aiValue;
    o->vt = &DAT_010cf0e4;
    o->f0c = 0xffff;
    return o;
}

struct D3FE70Info {
    void* pkInfo;
};
// @fnv 0x00d3fe70
// src: GUESS 0x00d3fe70 (confidence: medium)
D3FE10Entry* __cdecl Runtime_ResetEntryAgents_Thunk(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, D3FE70Info kInfo)
{
    return ResetEntryAgents(pkHeader, pkEntry, pkManager, kInfo.pkInfo);
}

#include <xmmintrin.h>
extern float DAT_01011d78;
extern float DAT_01016248;
extern float DAT_01017718;

struct D212D0Seg {
    __m128 a;
    __m128 b;
};

struct D212D0Obj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(char* hitOut, D212D0Seg* seg, void* p3);

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
    __m128 row70;

    unsigned char* hkNormalTriangleShape_castRay(unsigned char* out, D212D0Seg* seg, void* p3);
};

// Normalizes the segment direction and dots it with row70; if negative calls v20, and stores in *out whether a hit was reported, else 0.
// @fnv 0x00d212d0
// src: XBOX_PDB 0x00d212d0
unsigned char* D212D0Obj::hkNormalTriangleShape_castRay(unsigned char* apHit, D212D0Seg* apSegment, void* p3)
{
    __m128 a = apSegment->a;
    __m128 b = apSegment->b;
    __m128 delta = _mm_sub_ps(b, a);
    __m128 t = _mm_mul_ps(delta, delta);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(t, t, 0xAA), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
    __m128 r = _mm_rsqrt_ss(sum);
    __m128 eq = _mm_cmpeq_ss(sum, _mm_set_ss(DAT_01011d78));
    __m128 rr = _mm_mul_ss(_mm_mul_ss(sum, r), r);
    __m128 e = _mm_sub_ss(_mm_set_ss(DAT_01017718), rr);
    __m128 f = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), e);
    __m128 fm = _mm_andnot_ps(eq, f);
    __m128 vBroadcast = _mm_shuffle_ps(fm, fm, 0);
    __m128 pd = _mm_mul_ps(vBroadcast, delta);
    __m128 pr = _mm_mul_ps(pd, row70);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(pr, pr, 0xAA), _mm_add_ss(_mm_shuffle_ps(pr, pr, 0x55), pr)));
    char hit;
    unsigned char bResult;

    if (!(dot < 0.0f)) {
        bResult = 0;
    } else {
        v20(&hit, apSegment, p3);
        bResult = hit != 0;
    }
    *apHit = bResult;
    return apHit;
}

namespace sd21cc0 {

class Target {
public:
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
    virtual int Dispatch(int iArg0, int iArg1);
};

// Calls Dispatch on pkTarget with iArg0 and iArg1 and returns the result.
// @fnv 0x00d21cc0
// src: GUESS 0x00d21cc0 (confidence: medium)
int Object_Dispatch_Thunk(Target* pkTarget, int iArg0, int iArg1)
{
    return pkTarget->Dispatch(iArg0, iArg1);
}

}


inline hkRotation::hkRotation() {}
inline hkTransform::hkTransform() {}
inline float& RotationEntry(hkRotation& rotation, int row, int column)
{
    return reinterpret_cast<float*>(&rotation.m_kColumn0 + column)[row];
}
inline void hkRotation::setIdentity()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
    RotationEntry(*this, 0, 0) = 1.0f;
    RotationEntry(*this, 1, 1) = 1.0f;
    RotationEntry(*this, 2, 2) = 1.0f;
}
inline void hkTransform::setIdentity()
{
    m_rotation.setIdentity();
    getPositionMember().setZero4();
}
struct ShapeD22DC0 : public hkReferencedObject {
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType) { m_kMotionTransform.setIdentity(); }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    hkTransform m_kMotionTransform;
    int m_type;
};
struct FUN_00d22dc0 : public ShapeD22DC0 {
    FUN_00d22dc0(const hkVector4& kA, const hkVector4& kB, float fRadius, int iA, int iB) throw();
    virtual ~FUN_00d22dc0() throw();
    hkVector4 m_kA;
    hkVector4 m_kB;
    float m_fBoundRadius;
    int m_iA;
    int m_iB;
};

// Constructs a shape of type 8 and stores two vectors, a float, and two integers.
// @fnv 0x00d22dc0
FUN_00d22dc0::FUN_00d22dc0(const hkVector4& kA, const hkVector4& kB, float afBoundRadius, int iA, int iB) throw()
    : ShapeD22DC0(8), m_iA(iA), m_iB(iB)
{
    m_kA = kA;
    m_kB = kB;
    m_fBoundRadius = afBoundRadius;
}

struct E48 { int a[12]; };
extern "C" void __cdecl hkSmallArrayUtil__reserve(void* self, int newCap, int elemSize);
extern "C" void __cdecl CopyMemoryBackward(void* dst, const void* src, int size);

struct hkSmallArrayE {
    E48* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int getCapacity() const { return m_iCapacityState & 0x3fff; }
    void reserve(int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkSmallArrayUtil__reserve(this, newSize, sizeof(E48));
        }
    }
    void Insert(int i, const E48* a, int numtoinsert);
};

// Inserts numtoinsert elements from a at index i, moving existing elements back and updating the size.
// @fnv 0x00d27ec0
void hkSmallArrayE::Insert(int iIndex, const E48* apElements, int numtoinsert)
{
    const int newsize = m_iElementCount + numtoinsert;
    const int numtomove = m_iElementCount - iIndex;
    if (newsize > getCapacity()) reserve(newsize);
    CopyMemoryBackward(m_data + iIndex + numtoinsert, m_data + iIndex, numtomove * sizeof(E48));
    CopyMemoryBackward(m_data + iIndex, apElements, numtoinsert * sizeof(E48));
    m_iElementCount = (unsigned short)newsize;
}

struct S00d281b0_Alloc {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T>
    __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <typename T>
    __forceinline void _bufFree(T* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

inline S00d281b0_Alloc& TemporaryAllocator(hkMemoryRouter& router)
{
    return *reinterpret_cast<S00d281b0_Alloc*>(router.m_temp);
}

struct S00d281b0_IntArray {
    int* data;
    int count;
};

struct S00d281b0_Target {
    S00d281b0_IntArray* indices;
    int count;
    int MoveLargestToFirst(S00d281b0_IntArray* values);
};

// Finds the index of the largest value in values, swaps it with the first element, and remaps this->indices through the swap permutation.
// @fnv 0x00d281b0
int S00d281b0_Target::MoveLargestToFirst(S00d281b0_IntArray* values)
{
    int largest = 0;
    int size = values->count;
    int max = values->data[0];
    for (int i = 1; i < size; ++i) {
        if (values->data[i] > max) {
            max = values->data[i];
            largest = i;
        }
    }
    if (!largest) return 0;

    int* mapping;
    volatile int capacity;
    S00d281b0_Alloc& a = TemporaryAllocator(hkMemoryRouter::getInstance());
    int n;
    if (size) {
        n = size;
        mapping = a._bufAlloc<int>(n);
        capacity = n;
    } else {
        mapping = 0;
        n = 0;
    }
    if (!n) capacity = 0x80000000;
    for (int i = 0; i < size; ++i) mapping[i] = i;
    mapping[0] = largest;
    mapping[largest] = 0;

    int first = values->data[0];
    int other = values->data[largest];
    values->data[largest] = first;
    values->data[0] = other;

    for (int i = 0; i < this->count; ++i) {
        int& r = this->indices->data[i];
        r = mapping[r];
    }
    S00d281b0_Alloc& b = TemporaryAllocator(hkMemoryRouter::getInstance());
    int c = capacity;
    if ((c & 0x80000000) == 0)
        b._bufFree<int>(mapping, c & 0x3fffffff);
    return largest;
}

struct FUN_00d2acf0_base
{
    void** vtbl;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d2acf0_base(void* a1, int a2);
};

struct FUN_00d2acf0 : FUN_00d2acf0_base
{
    __m128 unk20;
    __m128 unk30;
    __m128 unk40;
    float unk50;
    float unk54;
    int unk58;
    unsigned char unk5c;

    FUN_00d2acf0(void* a1, __m128* a2, __m128* a3, float a4, float a5, int a6);
};

// @fnv 0x00d2acf0
FUN_00d2acf0::FUN_00d2acf0(void* a1, __m128* a2, __m128* a3, float a4, float a5, int a6)
    : FUN_00d2acf0_base(a1, a6)
{
    unk50 = a4;
    unk54 = a5;
    vtbl = (void**)0x10ce504;
    unk5c = 0;
    unk20 = *a2;
    unk30 = *a3;
    unk40 = _mm_setzero_ps();
}

extern __declspec(thread) unsigned int t_uiMemContextB110;
inline unsigned int GetMemContextB110()
{
    return t_uiMemContextB110;
}
inline void SetMemContextB110(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextB110 = m_uiGeometryShaderFlags;
}
inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(GetMemContextB110());
    SetMemContextB110(context);
}
inline AutoMemContext::~AutoMemContext()
{
    SetMemContextB110(m_eMemoryContext);
}

inline hkMemoryAllocator& Heap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* object = static_cast<hkReferencedObject*>(
        Heap(hkMemoryRouter::getInstance()).blockAlloc(nbytes));
    object->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return object;
}
inline void hkReferencedObject::operator delete(void* p, unsigned int nbytes)
{
    hkReferencedObject* object = static_cast<hkReferencedObject*>(p);
    Heap(hkMemoryRouter::getInstance()).blockFree(p, object->m_usMemSizeAndFlags);
}

struct ShapeB110;
struct BodyB110 {
    ShapeB110* getShape() const { return m_pCollisionShape; }
    ShapeB110* m_pCollisionShape;
};
struct InputB110 {
    BodyB110* m_kCollisionBody;
    int m_type;
};

class AgentB110 : public hkReferencedObject {
public:
    AgentB110(ShapeB110* pShape, const hkVector4& kA, const hkVector4& kB, float fA, float fB, void* pUser);
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
    hkVector4 m_offset;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};

class AgentFactoryB110 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAgentData;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_kA;
    hkVector4 m_kB;
    hkVector4 m_offset;
    float m_fCoefficientA;
    float m_fB;

    AgentB110* hkOrientHingedBodyAction_clone(const InputB110* pA, const InputB110* pB);
};

// Creates an AgentB110 from pA's collision body shape when pA is type 2 and pB is type 0, otherwise returns null.
// @fnv 0x00d2b110
// src: XBOX_PDB 0x00d2b110
AgentB110* AgentFactoryB110::hkOrientHingedBodyAction_clone(const InputB110* apInputA, const InputB110* apInputB)
{
    AutoMemContext kContext(0x10);
    if (apInputA->m_type != 2)
        return 0;
    if (apInputB->m_type != 0)
        return 0;
    AgentB110* pAgent = new AgentB110(apInputA->m_kCollisionBody->getShape(), m_kA, m_kB, m_fCoefficientA, m_fB, m_pAgentData);
    pAgent->m_offset = m_offset;
    return pAgent;
}

class AgentD2C9 : public hkReferencedObject {
public:
    AgentD2C9(int aiAgentType, int iOwner); // FUN_00d2c910

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_v20;
};

struct RequestD2C9 {
    int* m_pName;
    int m_iKind;
    int GetName() const { return *m_pName; }
    int* GetNamePtr() const { return m_pName; }
};

struct CountD2C9 {
    int unk00;
    int m_iArrayLength;
};

class FactoryD2C9 {
public:
    AgentD2C9* hkLiquidAction_clone(RequestD2C9* req, CountD2C9* cnt);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iOwner;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_v20;
};

// Creates an AgentD2C9 when the request kind is 2 and the count is zero, copying m_v20 from the factory.
// @fnv 0x00d2c9d0
// src: XBOX_PDB 0x00d2c9d0
AgentD2C9* FactoryD2C9::hkLiquidAction_clone(RequestD2C9* apRequest, CountD2C9* apCount)
{
    AutoMemContext kContext(0x10);
    if (apRequest->m_iKind != 2)
        return 0;
    if (apCount->m_iArrayLength != 0)
        return 0;
    AgentD2C9* agent = new AgentD2C9(apRequest->GetName(), m_iOwner);
    agent->m_v20 = m_v20;
    return agent;
}

extern float DAT_0104da48;
extern int DAT_010ce80c;
extern __m128 DAT_010c44d0;

struct Src {
    int u[20];
    hkVector4 v;
    int t0, t1, t2, t3;
};
struct Q {
    int* vt;
    float d;
    int p1, p2;
    hkVector4 v;
    int x;
    int t1, t2, t3;
};
void __cdecl hkTransform_setMulInverseMul_ComputeValues_00d2f0d0();
typedef void (__cdecl *Fn)(int, int, Src*, Q*, Q*);
// XORs c->v with DAT_010c44d0 into a copy of c, builds one or two Q structs from c->v, d and e, and calls FUN_00d2f0d0 with b, a, the copy and the Qs.
// @fnv 0x00d2daf0
// src: GUESS 0x00d2daf0 (confidence: low)
void __cdecl Runtime_CopyMemory_00d2daf0(int a, int b, Src* apSrc, int d, int e)
{
    __m128 vv = _mm_load_ps((float*)&apSrc->v);
    __m128 n = _mm_xor_ps(vv, DAT_010c44d0);
    Src copy;
    memcpy(&copy, apSrc, sizeof(copy));
    _mm_store_ps((float*)&copy.v, n);
    Q qa;
    qa.d = DAT_0104da48;
    qa.vt = &DAT_010ce80c;
    CopyVectorWords(qa.v, apSrc->v);
    qa.x = d;
    if (e) {
        Q qb;
        qb.vt = &DAT_010ce80c;
        qb.d = DAT_0104da48;
        CopyVectorWords(qb.v, apSrc->v);
        qb.x = e;
        ((Fn)hkTransform_setMulInverseMul_ComputeValues_00d2f0d0)(b, a, &copy, &qa, &qb);
    } else {
        ((Fn)hkTransform_setMulInverseMul_ComputeValues_00d2f0d0)(b, a, &copy, &qa, 0);
    }
}

struct CallbackState {
    const int* m_pIntegerValue;
    char m_cFlag;
    int m_iValue;
};
struct Holder {
    void hkpBvTreeAgent_getPenetrations(int a, int b, int c, CallbackState* s);
    void UpdateState_00d2f3f0(int a, int b, int c, int d);
};
// Fills a CallbackState with d, a zero flag, and a pointer to DAT_010ce81c, then calls FUN_00d315f0 with b, a, c, and the state.
// @fnv 0x00d2f3f0
// src: GUESS 0x00d2f3f0 (confidence: low)
void Holder::UpdateState_00d2f3f0(int a, int b, int c, int aiValue)
{
    CallbackState s;
    s.m_iValue = aiValue;
    s.m_cFlag = 0;
    s.m_pIntegerValue = (const int*)&DAT_010ce81c;
    hkpBvTreeAgent_getPenetrations(b, a, c, &s);
}

extern "C" void _ReadWriteBarrier();
struct ShapeD2F630 {
    int unk00;
    int unk04;
    int unk08;
    int m_type;
};
struct CdBodyD2F630 {
    ShapeD2F630* m_pCollisionShape;
};
struct InputD2F630;
struct CollectorD2F630;
typedef void (__cdecl *AgentFuncD2F630)(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector);
struct AgentFuncsD2F630 {
    AgentFuncD2F630 m_pQueryPenetrationsFunc;
    void* m_func04;
    void* m_func08;
    void* m_func0C;
    void* m_func10;
};
struct DispatcherD2F630 {
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
    int unk0FC;
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
    unsigned char m_agentTypes[32][32];
    unsigned char m_agentTypesPred[32][32];
    AgentFuncsD2F630 m_agentFuncs[32];
};
struct InputD2F630 {
    DispatcherD2F630* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_createPredictive;
};

// Looks up the agent type pair in the dispatcher's type matrix and calls the corresponding penetration query function with the given bodies and input.
// @fnv 0x00d2f630
// src: HAVOK_LIB 0x00d2f630
void __cdecl hkpBvTreeAgent_defaultAgentCreate(const CdBodyD2F630& kA, const CdBodyD2F630& kB, const InputD2F630& kInput, CollectorD2F630& kCollector)
{
    DispatcherD2F630* pkDispatcher = kInput.m_pCollisionDispatcher;
    int iTypeA = kA.m_pCollisionShape->m_type;
    int iTypeB = kB.m_pCollisionShape->m_type;
    const unsigned char (*pTypes)[32] = kInput.m_createPredictive ? pkDispatcher->m_agentTypesPred : pkDispatcher->m_agentTypes;
    int iType = pTypes[iTypeA][iTypeB];
    AgentFuncD2F630 fn = (*(AgentFuncD2F630 volatile*)&pkDispatcher->m_agentFuncs[iType].m_pQueryPenetrationsFunc);
    _ReadWriteBarrier();
    fn(kA, kB, kInput, kCollector);
}

struct FUN_00d32970_Collector {
    void* vtable;
    unsigned char flag;
    unsigned int value;
};

struct FUN_00d32970_Agent {
    void hkpHeightFieldAgent_getPenetrations(void* a, void* b, void* c, FUN_00d32970_Collector* collector);
    void SetVtableAndProcessState_00d32970(void* a1, void* a2, void* a3, unsigned int a4);
};

// Initialises a Collector with a4 and passes it to FUN_00d32150 with a2, a1 and a3.
// @fnv 0x00d32970
// src: GUESS 0x00d32970 (confidence: low)
void FUN_00d32970_Agent::SetVtableAndProcessState_00d32970(void* a1, void* a2, void* a3, unsigned int uiValue)
{
    FUN_00d32970_Collector collector;
    collector.value = uiValue;
    collector.flag = 0;
    collector.vtable = &DAT_010ce81c;
    hkpHeightFieldAgent_getPenetrations(a2, a1, a3, &collector);
}

namespace fnv_00d329f0 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d329 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d329 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d329 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d329 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d329 m_key;
    int m_uiFilterValue;
};

struct Agent_d329 {
    void hkpHeightFieldAgent_linearCast(int a1, int a2, Input_d329* input, Record_d329* rec, Record_d329* optRec);
    void UpdateState_00d329f0(int a1, int a2, const Input_d329* input, int a4, int a5);
};
// Copies input, XORs its vector with DAT_010c44d0, builds a Record_d329 with a4, and calls FUN_00d32030 with an optional second record when a5 is non-zero.
// @fnv 0x00d329f0
// src: GUESS 0x00d329f0 (confidence: low)
void Agent_d329::UpdateState_00d329f0(int a1, int a2, const Input_d329* input, int a4, int a5)
{
    Input_d329 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d329 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = a4;

    if (a5 != 0) {
        Record_d329 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = a5;
        hkpHeightFieldAgent_linearCast(a2, a1, &local, &rec, &rec2);
    } else {
        hkpHeightFieldAgent_linearCast(a2, a1, &local, &rec, 0);
    }
}
}  // namespace fnv_00d329f0

namespace fnv_00d34810 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl hkpShapeCollectionAgent_staticLinearCast(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// XORs the input vector with DAT_010c44d0, builds a Record_d2e9 with the key and a4, and calls FUN_00d43b90 with an optional second record for a5.
// @fnv 0x00d34810
// src: GUESS 0x00d34810 (confidence: low)
void __cdecl hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810(int a2, int a1, const Input_d2e9* input, int aiValue, int aiOptionalValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        hkpShapeCollectionAgent_staticLinearCast(a1, a2, &local, &rec, &rec2);
    } else {
        hkpShapeCollectionAgent_staticLinearCast(a1, a2, &local, &rec, 0);
    }
}
}  // namespace fnv_00d34810

namespace fnv_00d349b0 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d2e9 {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9 {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9 {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    int m_uiFilterValue;
};

void __cdecl hkpConvexListAgent_staticLinearCast(int a1, int a2, Input_d2e9* input, Record_d2e9* rec, Record_d2e9* optRec);

// XORs input vector with DAT_010c44d0, builds a Record_d2e9 with a4, and calls FUN_00d33ca0 with an optional second record when a5 is non-zero.
// @fnv 0x00d349b0
// src: GUESS 0x00d349b0 (confidence: low)
void __cdecl hkpConvexListAgent_staticLinearCast_UpdateState_00d349b0(int a2, int a1, const Input_d2e9* input, int aiValue, int aiOptionalValue)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d2e9 rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        hkpConvexListAgent_staticLinearCast(a1, a2, &local, &rec, &rec2);
    } else {
        hkpConvexListAgent_staticLinearCast(a1, a2, &local, &rec, 0);
    }
}
}  // namespace fnv_00d349b0

namespace fnv_00d34b40 {
extern float DAT_0104da48;
extern const __m128 DAT_010c44d0;
extern unsigned int DAT_010ce80c;

struct __declspec(align(16)) Key_d34b {
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d34b {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union {
        __m128 m_vComponents;
        Key_d34b m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d34b {
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d34b m_key;
    int m_uiFilterValue;
};

struct Agent_d34b {
    void hkpConvexListAgent_linearCast(int a1, int a2, Input_d34b* input, Record_d34b* rec, Record_d34b* optRec);
    void UpdateFields_00d34b40(int a1, int a2, const Input_d34b* input, int a4, int a5);
};
// XORs the input key with a constant, builds a Record_d34b with the key and a4, and calls FUN_00d33da0 with an optional second record for a5.
// @fnv 0x00d34b40
// src: GUESS 0x00d34b40 (confidence: low)
void Agent_d34b::UpdateFields_00d34b40(int a1, int a2, const Input_d34b* input, int aiValue, int aiOptionalValue)
{
    Input_d34b local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d34b rec;
    rec.m_vtbl = &DAT_010ce80c;
    rec.m_fScalar = DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = aiValue;

    if (aiOptionalValue != 0) {
        Record_d34b rec2;
        rec2.m_vtbl = &DAT_010ce80c;
        rec2.m_fScalar = DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = aiOptionalValue;
        hkpConvexListAgent_linearCast(a2, a1, &local, &rec, &rec2);
    } else {
        hkpConvexListAgent_linearCast(a2, a1, &local, &rec, 0);
    }
}
}  // namespace fnv_00d34b40

extern "C" __m128 DAT_010c4c00;
extern "C" void _ReadWriteBarrier(void);


// hkpRootCdPoint (0x30): hkContactPoint (position, separating normal with distance in w) then root collidable /
// shape key pairs at +0x20; flip() is hkContactPoint::flip. Not the shared x,y,z Point.
struct RootCdPoint {
    hkVector4 m_pos;
    hkVector4 m_vHitNormal;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    __forceinline void flip() {
        m_pos.addMul4(m_vHitNormal.getSimdAt3(), m_vHitNormal);
        hkVector4::setNeg4(m_vHitNormal, m_vHitNormal, DAT_010c4c00);
    }
};

struct SubShapeId {
    unsigned char m_kPointA : 4;
    unsigned char m_kPointB : 4;
};

struct CastCollector {
    RootCdPoint* m_currentPoint;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RootCdPoint m_point000; RootCdPoint m_point001; RootCdPoint m_point002; RootCdPoint m_point003;
    RootCdPoint m_point004; RootCdPoint m_point005; RootCdPoint m_point006; RootCdPoint m_point007;
    RootCdPoint m_point008; RootCdPoint m_point009; RootCdPoint m_point010; RootCdPoint m_point011;
    RootCdPoint m_point012; RootCdPoint m_point013; RootCdPoint m_point014; RootCdPoint m_point015;
    RootCdPoint m_point016; RootCdPoint m_point017; RootCdPoint m_point018; RootCdPoint m_point019;
    RootCdPoint m_point020; RootCdPoint m_point021; RootCdPoint m_point022; RootCdPoint m_point023;
    RootCdPoint m_point024; RootCdPoint m_point025; RootCdPoint m_point026; RootCdPoint m_point027;
    RootCdPoint m_point028; RootCdPoint m_point029; RootCdPoint m_point030; RootCdPoint m_point031;
    RootCdPoint m_point032; RootCdPoint m_point033; RootCdPoint m_point034; RootCdPoint m_point035;
    RootCdPoint m_point036; RootCdPoint m_point037; RootCdPoint m_point038; RootCdPoint m_point039;
    RootCdPoint m_point040; RootCdPoint m_point041; RootCdPoint m_point042; RootCdPoint m_point043;
    RootCdPoint m_point044; RootCdPoint m_point045; RootCdPoint m_point046; RootCdPoint m_point047;
    RootCdPoint m_point048; RootCdPoint m_point049; RootCdPoint m_point050; RootCdPoint m_point051;
    RootCdPoint m_point052; RootCdPoint m_point053; RootCdPoint m_point054; RootCdPoint m_point055;
    RootCdPoint m_point056; RootCdPoint m_point057; RootCdPoint m_point058; RootCdPoint m_point059;
    RootCdPoint m_point060; RootCdPoint m_point061; RootCdPoint m_point062; RootCdPoint m_point063;
    RootCdPoint m_point064; RootCdPoint m_point065; RootCdPoint m_point066; RootCdPoint m_point067;
    RootCdPoint m_point068; RootCdPoint m_point069; RootCdPoint m_point070; RootCdPoint m_point071;
    RootCdPoint m_point072; RootCdPoint m_point073; RootCdPoint m_point074; RootCdPoint m_point075;
    RootCdPoint m_point076; RootCdPoint m_point077; RootCdPoint m_point078; RootCdPoint m_point079;
    RootCdPoint m_point080; RootCdPoint m_point081; RootCdPoint m_point082; RootCdPoint m_point083;
    RootCdPoint m_point084; RootCdPoint m_point085; RootCdPoint m_point086; RootCdPoint m_point087;
    RootCdPoint m_point088; RootCdPoint m_point089; RootCdPoint m_point090; RootCdPoint m_point091;
    RootCdPoint m_point092; RootCdPoint m_point093; RootCdPoint m_point094; RootCdPoint m_point095;
    RootCdPoint m_point096; RootCdPoint m_point097; RootCdPoint m_point098; RootCdPoint m_point099;
    RootCdPoint m_point100; RootCdPoint m_point101; RootCdPoint m_point102; RootCdPoint m_point103;
    RootCdPoint m_point104; RootCdPoint m_point105; RootCdPoint m_point106; RootCdPoint m_point107;
    RootCdPoint m_point108; RootCdPoint m_point109; RootCdPoint m_point110; RootCdPoint m_point111;
    RootCdPoint m_point112; RootCdPoint m_point113; RootCdPoint m_point114; RootCdPoint m_point115;
    RootCdPoint m_point116; RootCdPoint m_point117; RootCdPoint m_point118; RootCdPoint m_point119;
    RootCdPoint m_point120; RootCdPoint m_point121; RootCdPoint m_point122; RootCdPoint m_point123;
    RootCdPoint m_point124; RootCdPoint m_point125; RootCdPoint m_point126; RootCdPoint m_point127;
    RootCdPoint m_point128; RootCdPoint m_point129; RootCdPoint m_point130; RootCdPoint m_point131;
    RootCdPoint m_point132; RootCdPoint m_point133; RootCdPoint m_point134; RootCdPoint m_point135;
    RootCdPoint m_point136; RootCdPoint m_point137; RootCdPoint m_point138; RootCdPoint m_point139;
    RootCdPoint m_point140; RootCdPoint m_point141; RootCdPoint m_point142; RootCdPoint m_point143;
    RootCdPoint m_point144; RootCdPoint m_point145; RootCdPoint m_point146; RootCdPoint m_point147;
    RootCdPoint m_point148; RootCdPoint m_point149; RootCdPoint m_point150; RootCdPoint m_point151;
    RootCdPoint m_point152; RootCdPoint m_point153; RootCdPoint m_point154; RootCdPoint m_point155;
    RootCdPoint m_point156; RootCdPoint m_point157; RootCdPoint m_point158; RootCdPoint m_point159;
    RootCdPoint m_point160; RootCdPoint m_point161; RootCdPoint m_point162; RootCdPoint m_point163;
    RootCdPoint m_point164; RootCdPoint m_point165; RootCdPoint m_point166; RootCdPoint m_point167;
    RootCdPoint m_point168; RootCdPoint m_point169; RootCdPoint m_point170; RootCdPoint m_point171;
    RootCdPoint m_point172; RootCdPoint m_point173; RootCdPoint m_point174; RootCdPoint m_point175;
    RootCdPoint m_point176; RootCdPoint m_point177; RootCdPoint m_point178; RootCdPoint m_point179;
    RootCdPoint m_point180; RootCdPoint m_point181; RootCdPoint m_point182; RootCdPoint m_point183;
    RootCdPoint m_point184; RootCdPoint m_point185; RootCdPoint m_point186; RootCdPoint m_point187;
    RootCdPoint m_point188; RootCdPoint m_point189; RootCdPoint m_point190; RootCdPoint m_point191;
    RootCdPoint m_point192; RootCdPoint m_point193; RootCdPoint m_point194; RootCdPoint m_point195;
    RootCdPoint m_point196; RootCdPoint m_point197; RootCdPoint m_point198; RootCdPoint m_point199;
    RootCdPoint m_point200; RootCdPoint m_point201; RootCdPoint m_point202; RootCdPoint m_point203;
    RootCdPoint m_point204; RootCdPoint m_point205; RootCdPoint m_point206; RootCdPoint m_point207;
    RootCdPoint m_point208; RootCdPoint m_point209; RootCdPoint m_point210; RootCdPoint m_point211;
    RootCdPoint m_point212; RootCdPoint m_point213; RootCdPoint m_point214; RootCdPoint m_point215;
    RootCdPoint m_point216; RootCdPoint m_point217; RootCdPoint m_point218; RootCdPoint m_point219;
    RootCdPoint m_point220; RootCdPoint m_point221; RootCdPoint m_point222; RootCdPoint m_point223;
    RootCdPoint m_point224; RootCdPoint m_point225; RootCdPoint m_point226; RootCdPoint m_point227;
    RootCdPoint m_point228; RootCdPoint m_point229; RootCdPoint m_point230; RootCdPoint m_point231;
    RootCdPoint m_point232; RootCdPoint m_point233; RootCdPoint m_point234; RootCdPoint m_point235;
    RootCdPoint m_point236; RootCdPoint m_point237; RootCdPoint m_point238; RootCdPoint m_point239;
    RootCdPoint m_point240; RootCdPoint m_point241; RootCdPoint m_point242; RootCdPoint m_point243;
    RootCdPoint m_point244; RootCdPoint m_point245; RootCdPoint m_point246; RootCdPoint m_point247;
    RootCdPoint m_point248; RootCdPoint m_point249; RootCdPoint m_point250; RootCdPoint m_point251;
    RootCdPoint m_point252; RootCdPoint m_point253; RootCdPoint m_point254; RootCdPoint m_point255;
    hkVector4 m_normal3020;
    float m_dist3030;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_uiShapeKeys[4];
    unsigned char m_byte3048;
    unsigned char m_byte3049;
    SubShapeId m_byte304a;
};

class LinearCastAgent {
public:
    void hkpConvexListAgent_processCollision(int bodyB, int bodyA, int input, int collector);
    void ProcessEntries_00d34c10(int bodyA, int bodyB, int input, int collector);
};

// Calls FUN_00d33f40 with swapped bodies, flips collected points, and if the distance changed, negates the normal and swaps shape-key entries in the collector.
// @fnv 0x00d34c10
// src: GUESS 0x00d34c10 (confidence: low)
void LinearCastAgent::ProcessEntries_00d34c10(int bodyA, int bodyB, int input, int collectorRaw) {
    CastCollector& collector = *(CastCollector*)collectorRaw;
    float saved_dist = collector.m_dist3030;
    RootCdPoint* y = collector.m_currentPoint;

    hkpConvexListAgent_processCollision(bodyB, bodyA, input, collectorRaw);

    for (; y < collector.m_currentPoint; ++y) {
        y->flip();
    }

    if (saved_dist != collector.m_dist3030) {
        hkVector4* pNormal = &collector.m_normal3020;
        pNormal->m_vComponents = _mm_xor_ps(pNormal->m_vComponents, DAT_010c4c00);
        _ReadWriteBarrier();

        unsigned char p = collector.m_byte304a.m_kPointB;
        unsigned char low = collector.m_byte304a.m_kPointA;
        collector.m_byte304a.m_kPointA = p;
        collector.m_byte304a.m_kPointB = low;

        unsigned char cByte48 = collector.m_byte3048;
        unsigned char old49 = collector.m_byte3049;
        collector.m_byte3049 = cByte48;
        unsigned int idx = cByte48;
        idx += old49;
        idx -= 1;
        collector.m_byte3048 = old49;
        unsigned short (&shapeKeys)[4] = collector.m_uiShapeKeys;
        unsigned short old48 = shapeKeys[0];
        shapeKeys[0] = shapeKeys[idx];
        shapeKeys[idx] = old48;

        unsigned char* p48 = &collector.m_byte3048;
        if ((*p48 & collector.m_byte3049) == 2) {
            unsigned short t = collector.m_uiShapeKeys[1];
            collector.m_uiShapeKeys[1] = collector.m_uiShapeKeys[2];
            collector.m_uiShapeKeys[2] = t;
        }
    }
}

extern "C" void __cdecl hkpAgent1nSector_ProcessEntries_00da3510(int, int);
// Forwards a2 and a3 to FUN_00da3510, ignoring a1.
// @fnv 0x00d34d60
void __cdecl ForwardCall(int aUnused, int a2, int a3)
{
    hkpAgent1nSector_ProcessEntries_00da3510(a2, a3);
}

struct FUN_00d36b20
{
    void* unk00;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    static __forceinline void* operator new(unsigned int size) throw()
    {
        hkMemoryRouter* manager = hkMemoryRouter_getInstance();
        FUN_00d36b20* object = static_cast<FUN_00d36b20*>(reinterpret_cast<hkMemoryAllocator*>(manager->m_heap)->blockAlloc(size));
        object->m_usMemSizeAndFlags = (unsigned short)size;
        return object;
    }
    FUN_00d36b20(int param1, int param2, int* param3, int param4) throw();
};
// Allocates a FUN_00d36b20 object via the custom heap operator new and forwards the four constructor arguments to it.
// @fnv 0x00d36b70
// src: HAVOK_LIB 0x00d36b70
FUN_00d36b20* hkpListAgent_createListBAgent(int param1, int param2, int* param3, int param4)
{
    return new FUN_00d36b20(param1, param2, param3, param4);
}

namespace fnv_00d2dc10 {


inline hkMemoryAllocator& HeapD2DC10(hkMemoryRouter& holder)
{
    return *reinterpret_cast<hkMemoryAllocator*>(holder.m_heap);
}
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

class D2DC10BaseObject {
public:
    virtual ~D2DC10BaseObject() {}
};

class FUN_00d2dc10 : public D2DC10BaseObject {
// Default constructor for a D2DC10 base object, inheriting from D2DC10BaseObject with no initialization.
// @fnv 0x00d2dc10
public:
    FUN_00d2dc10() {}
    virtual ~FUN_00d2dc10() {}

    static void* operator new(unsigned int, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void operator delete(void* p, unsigned int nbytes) { HeapD2DC10(hkMemoryRouter_getInstance()).blockFree(p, nbytes); }

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
};

void* D2DC10Construct(void* pvMem)
{
    return new (pvMem) FUN_00d2dc10;
}
}  // namespace fnv_00d2dc10

// fnv_00d37d30 (0x00d37d30) is in blk_00d20000_od_o2_nood_variant_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp: Havok was
// built without exceptions, and the original scalar deleting destructor has no EH frame.

#include <xmmintrin.h>
namespace fnv_00d22260 {
// Exe 0x00d22260 FUN_00d22260: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float f[4]; } __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);

struct D22260_Matrix
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
    float* m_data;
};

inline void RotateVector(hkVector4& result, const float* rows, const hkVector4& input) {
    const LocalM128& value = *(const LocalM128*)&input;
    LocalM128 x = _mm_shuffle_ps(value,value,0);
    LocalM128 ax = _mm_mul_ps(_mm_load_ps(rows),x);
    LocalM128 y = _mm_shuffle_ps(value,value,0x55);
    LocalM128 ay = _mm_mul_ps(_mm_load_ps(rows+4),y);
    LocalM128 z = _mm_shuffle_ps(value,value,0xaa);
    LocalM128 az = _mm_mul_ps(_mm_load_ps(rows+8),z);
    *(LocalM128*)&result = _mm_add_ps(_mm_add_ps(ax,ay),az);
}
inline void CrossVector(hkVector4& result, const hkVector4& inputA, const hkVector4& inputB) {
    const LocalM128& a = *(const LocalM128*)&inputA;
    const LocalM128& b = *(const LocalM128*)&inputB;
    LocalM128 positive = _mm_mul_ps(_mm_shuffle_ps(a,a,0xc9), _mm_shuffle_ps(b,b,0xd2));
    LocalM128 negative = _mm_mul_ps(_mm_shuffle_ps(a,a,0xd2), _mm_shuffle_ps(b,b,0xc9));
    *(LocalM128*)&result = _mm_sub_ps(positive,negative);
}
inline void AddVector(hkVector4& result, const hkVector4& input) {
    *(LocalM128*)&result = _mm_add_ps(*(LocalM128*)&result, *(const LocalM128*)&input);
}

struct D22260_Vector
{
    hkVector4 m_uiFilterValue;
    hkVector4 m_secondary;
};

struct D22260_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_quaternion1;
    hkVector4 m_quaternion2;

    void __thiscall ProcessState_00d22260(
        int ReportDiagnostic,
        int unused1,
        D22260_Matrix* matrix1,
        D22260_Vector* vector1,
        D22260_Matrix* matrix2,
        D22260_Vector* vector2);
};

// Transforms m_quaternion1/2 by the matrices' rows, crosses each result with the vector's second field, and adds the product to its first field.
// @fnv 0x00d22260
// src: GUESS 0x00d22260 (confidence: low)
void __thiscall D22260_Object::ProcessState_00d22260(
    int ReportDiagnostic,
    int unused1,
    D22260_Matrix* matrix1,
    D22260_Vector* vector1,
    D22260_Matrix* matrix2,
    D22260_Vector* vector2)
{
    hkVector4 rotated1, rotated2;
    RotateVector(rotated1, matrix1->m_data, m_quaternion1);
    RotateVector(rotated2, matrix2->m_data, m_quaternion2);
    hkVector4 cross1, cross2;
    CrossVector(cross1, rotated1, vector1->m_secondary);
    CrossVector(cross2, rotated2, vector2->m_secondary);
    AddVector(vector1->m_uiFilterValue, cross1);
    AddVector(vector2->m_uiFilterValue, cross2);
}
}  // namespace fnv_00d22260

// FUN_00d24650 - __stdcall function, callee pops 4 bytes (1 stack parameter)
// @fnv 0x00d24650
// src: GUESS 0x00d24650 (confidence: high)
void __stdcall Runtime_DoNothing_00d24650(int _param) {
}

// local form of hkpSymmetricAgent: 0x00d36d20 needs the Agent base virtual call surface and inherited state omitted by the shared primary.
template<class Agent> class SymmetricAgentLocal_blk00d20000o2 : public Agent {
public:
    void ProcessSwappedCollisionBodies(const hkpCdBody&, const hkpCdBody&,
                     const CollisionAgentContext&, hkpCdBodyPairCollector&);
};
// Swaps the two hkpCdBody arguments and forwards them to hkpListAgent::vf03 via a hkpSymmetricAgentFlipBodyCollector.
// @fnv 0x00d36d20
// src: GUESS 0x00d36d20 (confidence: medium)
template<> void SymmetricAgentLocal_blk00d20000o2<hkpListAgent>::ProcessSwappedCollisionBodies(
    const hkpCdBody& a, const hkpCdBody& b,
    const CollisionAgentContext& input, hkpCdBodyPairCollector& output)
{
    // The game stamps this adapter's table directly without running a constructor.
    void* storage[sizeof(hkpSymmetricAgentFlipBodyCollector) / sizeof(void*)];
    hkpSymmetricAgentFlipBodyCollector& collector = *(hkpSymmetricAgentFlipBodyCollector*)storage;
    collector.payload = &output;
    collector.unk04[0] = 0;
    *(const void**)&collector = &DAT_010ce81c;
    hkpListAgent::vf03(b, a, input, collector);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned int DAT_0126835c;
extern char DAT_010ced28[];
extern char DAT_010c41f8[];
extern volatile float DAT_01012054;

struct Body11
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
};

class __declspec(align(16)) FUN_00d01a60
{
public:
    Body11 m_kCollisionBody;
    float m_unk2C;
    FUN_00d01a60();
};


struct A1Rec
{
    void* unk00;
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
    hkVector4 unk70;
};

struct PRec
{
    int unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Body11 unk20;
};

struct BroadPhaseHandle
{
    int unk14;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
    int unk1C;
    __forceinline void SetOwnerPointer(void* owner)
    {
        unk19 = (unsigned char)((unsigned int)owner - (unsigned int)this);
    }
};
struct __declspec(align(16)) ZT
{
    void* unk00;
    int unk04;
    void* unk08;
    void* unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned short unk12;
    BroadPhaseHandle handle;
    __forceinline ZT()
    {
        unk00 = 0;
        unk08 = 0;
        unk0C = 0;
        unk04 = -1;
        unk10 = 0;
        handle.unk14 = 0;
        handle.unk18 = 0;
        handle.unk1C = 0;
        handle.unk1A = 0xff;
        handle.unk19 = 0x7f;
    }
};

struct CollidableBuffer
{
    ZT z;
    FUN_00d01a60 o40;
    __forceinline CollidableBuffer()
    {
        o40.m_unk2C = DAT_01012054;
        z.handle.SetOwnerPointer(&z);
        z.unk11 = 0;
        z.unk12 = 0;
    }
};

struct __declspec(align(16)) O1T
{
    void* FUN_00d33260(A1Rec* a1);
    void* unk00;
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct __declspec(align(16)) CF56Obj
{
    void* FUN_00cf5640(int* c, int b, void* a);
    void* unk00;
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
};

class FUN_00cf5640
{
public:
    FUN_00cf5640(int* name, int count, void* extra);
    virtual ~FUN_00cf5640();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int r18_00;
    int r18_04;
    int r18_08;
};
struct CF56Ret
{
    virtual void vfunc0(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int r18_00;
    int r18_04;
    int r18_08;
};

struct C85Ret
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

void hkArrayUtil__reserve(void* a, void* b, int c, int d);
int process_00d35770(O1T* o1, int a2, int a3, int a4, int a5);

static __forceinline int maxSize(int minimum, int value) {
    _ReadWriteBarrier();
    return value <= minimum ? minimum : value;
}
// @fnv 0x00d365d0
// src: HAVOK_LIB 0x00d365d0
int hkpCollectionAgent3_process(A1Rec* a1, int a2, int a3, int a4, int a5)
{
    int nameid;
    unsigned int stamped;
    int result;
    O1T o1;
    CF56Obj obj;
    void* tlsblk = TlsGetValue(DAT_0126835c);
    if (*(unsigned int*)((char*)tlsblk + 4) < *(unsigned int*)((char*)tlsblk + 0xc))
    {
        unsigned char* cur = (unsigned char*)(*(unsigned int*)((char*)tlsblk + 4));
        *(const char**)cur = DAT_010ced28;
        __asm
        {
            rdtsc
            mov dword ptr[stamped], eax
        }
        *(unsigned int*)(cur + 4) = stamped;
        *(unsigned int*)((char*)tlsblk + 4) = (unsigned int)cur + 0xc;
    }

    o1.FUN_00d33260(a1);
    o1.unk60 = a1->unk60;
    CopyVectorWords(*(hkVector4*)&o1.unk70, a1->unk70);
    nameid = *(int*)(void*)a1->unk00;
    FUN_00cf5640* shape = new (&obj) FUN_00cf5640(&nameid, 1, 0);
    void* cfret = shape;
    CollidableBuffer cb;
    PRec* p = (PRec*)a1->unk00;
    if (p->unk0C == 0)
    {
        cb.o40.m_kCollisionBody = p->unk20;
    }
    void* t8 = p->unk08;
    void* tc = p->unk0C;
    cb.z.unk0C = tc;
    cb.z.unk08 = t8;
    o1.unk08 = p;
    o1.unk00 = &cb.z;
    cb.z.unk00 = cfret;
    cb.z.unk04 = -1;
    result = process_00d35770(&o1, a2, a3, a4, a5);
    int* r18 = &shape->r18_00;
    hkMemoryRouter* q = hkMemoryRouter_getInstance();
    void* mgr = q->m_heap;
    _ReadWriteBarrier();
    int masked = r18[2] & 0x3fffffff;
    if (masked < 0)
    {
        int sz = masked * 2;
        hkArrayUtil__reserve(mgr, r18, maxSize(0, sz), 0x10);
    }
    r18[1] = 0;
    shape->~FUN_00cf5640();

    void* tlsblk2 = TlsGetValue(DAT_0126835c);
    if (*(unsigned int*)((char*)tlsblk2 + 4) < *(unsigned int*)((char*)tlsblk2 + 0xc))
    {
        unsigned char* cur2 = (unsigned char*)(*(unsigned int*)((char*)tlsblk2 + 4));
        *(const char**)cur2 = DAT_010c41f8;
        __asm
        {
            rdtsc
            mov dword ptr[stamped], eax
        }
        *(unsigned int*)(cur2 + 4) = stamped;
        *(unsigned int*)((char*)tlsblk2 + 4) = (unsigned int)cur2 + 0xc;
    }
    return result;
}

__declspec(noinline) void __cdecl hkpListAgent_initAgentFunc(void* apObject);

// src: HAVOK_LIB 0x00d36bb0
__declspec(noinline) void __cdecl hkpListAgent_initAgentFuncInverse(CollisionAgentFunctionTable* f)
{
    f->a = (void*)(void (__cdecl*)())&hkpListAgent_createListBAgent;
    f->b = (void*)&hkCollectorD347_ProcessState_00d34790;
    f->c = (void*)(void (__cdecl*)())&QueryClosestPoints;
    f->d = (void*)&hkpShapeCollectionAgent_staticLinearCast_UpdateState_00d34810;
    f->e = 0;
    f->f = 1;
}

// Fills a function table via FUN_00d36c30 and passes it to agent->FUN_00cfbbe0 with (9, -1), then refills via FUN_00d36bb0 and passes it with (-1, 9).
// @fnv 0x00d36c60
// src: HAVOK_LIB 0x00d36c60
void __cdecl hkpListAgent_registerAgent(void* apAgent)
{
    CollisionAgentFunctionTable funcs;
    funcs.e = 0;
    funcs.f = 0;
    hkpListAgent_initAgentFunc(&funcs);
    Agent* agent = (Agent*)apAgent;
    agent->AppendRecordAndRegisterAgents(&funcs, 9, -1);
    funcs.e = 0;
    funcs.f = 0;
    hkpListAgent_initAgentFuncInverse(&funcs);
    agent->AppendRecordAndRegisterAgents(&funcs, -1, 9);
}
