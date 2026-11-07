#include "../../include/BSSimpleArray.h"
#include "../../include/NiTArray.h"
// staging/blk_00ca0000_o2_rtm_variant.cpp: QuaternionLocal_00cb2ca0, AryType, RayCaster_rc1c, VelocityController and more (19 functions)
#include <xmmintrin.h>
typedef ::__m128 LocalM128; // Earlier CRT include owns the global intrinsic; only quaternion_simd keeps a local view.
// src/staging/blk_00ca0000_o2_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00ca0000_o2.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// SSE_DECLARATIONS_DEFER_TO_SDK
#include <windows.h>
// src/staging/blk_00ca0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
// BaseCinfo_blk_00ca0000_o2_rtm_variant: local type (was include/BaseCinfo.h, which had no evidence of one real class); no method of it is bound to a named game function
#include <stddef.h>
#include "../../include/AutoMemContext.h"
#include "../../include/NiPointer.h"
#include "../../include/NiRefObject.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"

// hkMemoryRouter::GetMonitorStream, Router::get and both former GetMemoryRouter helpers bind to 0x00c85750.
inline hkMemoryAllocator& GetHavokHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

template <typename TYPE> inline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    ReturnMemory(p, numElem * sizeof(TYPE));
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

class NiStream;

class BaseCinfo_blk_00ca0000_o2_rtm_variant
{
public:
    unsigned int unk00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;

    static void* operator new(size_t size) throw();
    static void operator delete(void*);

    __forceinline BaseCinfo_blk_00ca0000_o2_rtm_variant()
        : m_iWordAt04(0), m_8(1), m_iThirdValue(0), m_10(0)
    {}

    void v00();
    void v04();
    void LoadBinary(NiStream& kStream);
};
#include "../../include/LandTextureParameters.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiTimeController.h"
#include "../../include/CA0E60Array.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/Pair.h"
#include "../../include/Transform.h"
#include "../../include/bhkCapsuleShape.h"
#include "../../include/bhkCharacterPointCollector.h"
#include "../../include/bhkPackedNiTriStripsShape.h"
#include "../../include/bhkRagdollTemplateData.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkSerializable.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/hkBool.h"
#include "../../include/hkpShapePhantom.h"
#include "../../include/hkQsTransform.h"
#include "../../include/NiStream.h"
#include "../../include/StrArr.h"
#include "../../include/hkReferencedObject.h"



template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) : m_pObject(kSrc.m_pObject)
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
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    return *this = kSrc.m_pObject;
}
void __cdecl ReleaseStorage_00ca3570(void);
void __cdecl _delete(void* p, int);
struct FUN_00ca3980_class
{
    FUN_00ca3980_class* __thiscall FUN_00ca3980(int);
};
extern "C" void NiFreeAlias(void*);
extern int DAT_010c759c;
struct FUN_00ca4470_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall UpdateState_00ca4470();
};
struct FUN_00ca5310_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_p;
};
float __fastcall GetField24Float(struct FUN_00ca5310_class* pClass);
struct FUN_00ca6590_t
{
    int __thiscall ProcessState_00ca6590();
    FUN_00ca6590_t* __thiscall FUN_00ca6650(int flags);
};
void __cdecl _delete(void* p, unsigned int size);
struct FUN_00ca9840_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void SetFieldValue(float v);
};
extern int DAT_010c8288;
struct FUN_00ca9a80
{
    int a, b, c, d, e;
    FUN_00ca9a80();
};
extern "C" int __cdecl hkString_strLen(int);
struct FUN_00cb0a80_class
{
    int __thiscall hkStringPtr_getLength();
};
char ToUpperAscii(char acChar);
char ToLowerAscii(char acChar);
void __cdecl FUN_00cc9640();
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00cb9b60_class
{
    FUN_00cb9b60_class* DestroyIfFlagged(int flag);
};
struct FUN_00cbc8f0_cls
{
    void hkpSimpleContactConstraintData_getContactPointIdAt(int arg);
};
struct GlobalObject_0045cfe0
{
    GlobalObject_0045cfe0(const char* name, int flags);
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
};
struct FUN_00cbf400_class : GlobalObject_0045cfe0
{
    FUN_00cbf400_class();
};
extern int DAT_010c7310;
struct FUN_00ca0d40_class
{
    void __thiscall UpdateFields_00ca0d40();
};
void __cdecl FUN_00ca4490();
extern MemoryManager _g_memoryManager;
struct FUN_00ca4a90_Class
{
    FUN_00ca4a90_Class* __thiscall FUN_00ca4a90(int flags);
};
extern int DAT_01030a24;
extern int DAT_01030b0c;
extern int DAT_01030bf4;
extern int DAT_01066e2c;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268324;
void __cdecl RegisterStaticCollisionAgent(void*);
void __cdecl hkPredGskAgent3_registerAgent3(void*, int, int);
void __cdecl RegisterScriptHandlers(void*);
void __cdecl hkpBoxBoxAgent_registerAgent(void*);
void __cdecl hkBoxBoxAgent3_registerAgent3(void*);
void __cdecl Object_UpdateFields_00d3fd00(void*);
void __cdecl hkpSphereCapsuleAgent_registerAgent(void*);
void __cdecl Object_UpdateFields_00d3dca0(void*);
void __cdecl hkpSphereBoxAgent_registerAgent(void*);
void __cdecl RegisterHandlers(void*);
void __cdecl Object_UpdateFields_00d3abc0(void*);
void __cdecl hkCapsuleTriangleAgent3_registerAgent3(void*);
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(void*);
void __cdecl hkpMultiRayConvexAgent_registerAgent(void*);
void __cdecl hkpBvTreeStreamAgent_registerMultiRayAgent(void*);
void __cdecl hkpAgentRegisterUtil__registerTerminalAgents(void* pObject);
struct FUN_00cbbfa0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cbbfa0_class();
};
struct FUN_00ca5540_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_p;
    int GetEntryValue(int i);
};
extern int DAT_010c8d14;
struct FUN_00cba080_class
{
    int m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    FUN_00cba080_class* __thiscall FUN_00cba080(int flag);
};
extern int DAT_010c8d00;
extern void(__cdecl* DAT_010c8d08)(void*);
struct FUN_00cba030_class
{
    int m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_00cba030_class* __thiscall FUN_00cba030(int flag);
};
struct FUN_00ca2020_Class
{
    void FUN_00ca2020();
};
struct FUN_00ca20e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void ClearAndFreeEntries();
};
void __cdecl _NiFree(void*);
struct FUN_00ca4440_Class
{
    void* m_vtbl;
    void* m_data;
    FUN_00ca4440_Class* __thiscall FUN_00ca4440(unsigned int flags);
};
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern void(__stdcall* DAT_00fdf1c0)(void*);
struct FUN_00ca47a0_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    FUN_00ca47a0_Class* __thiscall AssignFrom(FUN_00ca47a0_Class* other);
};
struct FUN_00ca5340_class
{
    int __thiscall FUN_00ca5290();
    FUN_00ca5340_class* __thiscall FUN_00ca5340(int flags);
};
extern int _data_011c16bc;
extern int DAT_010c44e4;
extern int DAT_010c761c;
extern int DAT_012682d8;
extern int DAT_012686d0;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};
struct S_00cb79d0_Base : public A51BF0Base
{
    void* m_vptr;
    char m_iWordAt04[8];
    int m_iThirdValue;
    int m_10;

    S_00cb79d0_Base();
};
bhkPackedNiTriStripsShape* CreatePackedNiTriStripsShape();
struct HC1Base
{
    bool BSPackedAdditionalGeometryData_RegisterStreamables(NiStream*);
    bool bhkPackedNiTriStripsShape_RegisterStreamables(NiStream*);
};
float __fastcall Object_GetNestedFloatOrOne_00ca6620(void* p, int);
float __cdecl hkpConstraintData_getMaxLinearImpulse();
extern int DAT_0102e388;
void __fastcall Object_SetVirtualTable_00ca9900(int* p);
void __cdecl _delete(void* p, int size);
struct FUN_00ca9920_class
{
    void __thiscall FUN_00ca9860();
    FUN_00ca9920_class* __thiscall FUN_00ca9920(int flags);
};
struct NiStream;
struct FUN_00cac980_Holder
{
    void* hkpCharacterProxy_getShapePhantom();
};
struct BaseThunk
{
    bool BSTextureSet_RegisterStreamables(NiStream&);
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cac980_Holder* m_8;
};
struct FUN_00cac070_Stub : BaseThunk
{
    void bhkCharacterProxy_RegisterStreamables(NiStream&);
};
struct FUN_00cac920_Class
{
    char pad[0x30];
    void* m_30;
    char pad2[0x24];
    float m_58;
    float m_5c;
    void __thiscall hkpCharacterProxy_setPosition(void* body);
};
extern int DAT_010c8b0c;
extern int DAT_01268648;
struct FUN_00cb99a0_class
{
    void __thiscall FUN_00cb99a0(int a);
};
struct FUN_00cb9b30_class : FUN_00cb99a0_class
{
    int m_vtbl;
    FUN_00cb9b30_class(int a);
};
struct FUN_00cc66b0
{
    virtual ~FUN_00cc66b0();
};
struct FUN_00cb9c10_class : FUN_00cc66b0
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c10_class* __thiscall FUN_00cb9c10(int flags);
};
extern int DAT_010c8cc8;
struct FUN_00cb9c30_class
{
    int m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c30_class();
};
extern int DAT_010c8ce4;
struct FUN_00cb9c50_class
{
    int m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c50_class();
};
struct MemoryManagerReallocateHelper
{
    void* __thiscall Reallocate(void* p, unsigned int size);
};
struct FUN_00cb9cc0_class
{
    void* __thiscall ReallocateArray(void* p, unsigned int count);
};
void __stdcall Runtime_ProcessEntries_00cb9d50(int* paiValues, unsigned int n);
struct FUN_00cba000_class
{
    int m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    ~FUN_00cba000_class();
};
extern void(__stdcall* DAT_010c8d1c)(void*);
void __cdecl FUN_00cba1d0();
struct FUN_00cba6d0_class
{
    FUN_00cba6d0_class* __thiscall FUN_00cba6d0(int flags);
};
extern float g_fCA0CD0StepTime;
extern float DAT_011ac39c;
__int64 CA0CD0GetPerformanceCounter();
class CA0CD0World
{
  public:
    void Reset();
};
struct CA0CD0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA0CD0World* m_pkWorld;
    int unk14;
    int unk18;
    int unk1C;
    bool m_bValueAt0C;
};
class CA0CD0Manager
{
  public:
    int unk00;
    int unk04;
    CA0CD0Entry** m_ppkEntries;
    unsigned int m_uiCount;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __int64 m_i64StartTime;
    __int64 m_i64Duration;

    void ResetEntries();
};
extern int DAT_010c7310;
extern void(__stdcall* DAT_010c7318)(void*);
extern MemoryManager _g_memoryManager;
struct FUN_00ca0d70_Class
{
    int m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* __thiscall FUN_00ca0d70(unsigned char flag);
};
struct SubObject04
{
    virtual ~SubObject04();
    virtual void Slot1();
    virtual void Free(void* apPtr);
    int unk04;
    int unk08;
    int unk0c;

    SubObject04();
};
struct Flag18
{
    unsigned char m_v;
    Flag18()
    {
        m_v = 0;
    }
    ~Flag18();
};
SubObject04::SubObject04()
{
    unk04 = 0;
    unk08 = 0;
    unk0c = 0;
}
struct GuardBase04
{
    GuardBase04()
    {}
    ~GuardBase04();
};
struct FUN_00ca0dc0_cls : GuardBase04
{
    virtual ~FUN_00ca0dc0_cls();
    SubObject04 m_sub04;
    int unk14;
    unsigned char m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;

    FUN_00ca0dc0_cls();
};
// BSSimpleArray-style container of pointer-sized elements.
struct CA1080_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct CA1080_Holder
{
    int unk00;
    int unk04;
    int unk08;
    CA1080_Shape* shape;
};
struct CA1080_Entry
{
    CA1080_Holder* holder;
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
};
struct CA1080_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
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
    CA1080_Entry* entries;
    unsigned short entryCount;
    unsigned short unkb2;
    CA1080_Holder** holders;
    int holderCount;
};
struct CA1080_NodeList
{
    CA1080_Node** data;
    int count;
    CA1080_Node* GetAt(int i) const
    {
        return data[i];
    }
};
struct CA1080_PtrArray
{
    virtual void v00();
    virtual void** Allocate(unsigned int count);
    virtual void v08();
    virtual void** Reallocate(void** data, unsigned int count);

    void** data;
    unsigned int size;
    unsigned int capacity;

    void Add(void* item)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                {
                    data = Reallocate(data, newCap);
                }
                else
                {
                    data = Allocate(newCap);
                    capacity = newCap;
                }
                capacity = newCap;
            }
        }
        size++;
        data[size - 1] = item;
    }
};
void __stdcall CollectMixedTypeNodes(CA1080_NodeList* list, CA1080_PtrArray* out);
extern int DAT_01267e64;
extern int DAT_012681c0;
extern int DAT_011f4428;
struct SceneLookupBase_cls
{
    void* Find(const void* key);
};
struct SceneHost_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SceneHost_cls* m_10;
};
struct SceneLeaf_cls : SceneLookupBase_cls
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
    virtual int v37();
};
struct SceneNode_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    SceneHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    SceneNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};
struct SceneWalker_cls
{
    void TraverseSceneNode(SceneNode_cls* node, int a2, int a3);
    void CollectLeafObjects(SceneLeaf_cls* leaf, int a2, int a3);
};
struct FNVTaskElement
{
};
extern "C" void __fastcall nullsub_14(FNVTaskElement* element);
struct FNVTaskDynamicBuffer
{
    void* entries;
    int elementCount;
    unsigned int capacityAndFlags;
    void __thiscall Clear();
};
extern __declspec(thread) int g_iCA2020AllocTag;
struct CA2020AllocTagScope
{
    int m_iSaved;

    CA2020AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA2020AllocTag;
        g_iCA2020AllocTag = aiAllocationTag;
    }
    ~CA2020AllocTagScope()
    {
        g_iCA2020AllocTag = m_iSaved;
    }
};
class CA2020Object
{
  public:
    virtual ~CA2020Object();
};
class CA2020Referenced
{
  public:
    void removeReference();
};
class CA2020Array
{
  public:
    ~CA2020Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
};
class FUN_00ca2020_Holder
{
  public:
    ~FUN_00ca2020_Holder();

    int unk00;
    CA2020Referenced* m_pkShape;
    CA2020Object* m_pkFirst;
    CA2020Object* m_pkSecond;
    CA2020Referenced* m_pkBody;
    CA2020Array m_kEntries;
};
struct FUN_00a5d3d0_class
{
    void __thiscall FUN_00a5d3d0();
};
struct FUN_00ca3570_class : FUN_00a5d3d0_class
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;

    void __thiscall ReleaseStorage_00ca3570();
};
extern "C" char DAT_010c740c[];
extern MemoryManager _g_memoryManager;
struct Record
{
    int m_iValue;
    int m_iField04;
    int m_iField08;
};
struct Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int* m_pValues;
};
struct Owner
{
    int unk00[29];
    Table* m_pTable;

    int GetValueByIndex(unsigned int a1);
};
struct FUN_00ca3b10_cls
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    int m_8;

    bool hkpMeshShape_isWeldingEnabled();
};
void __cdecl _NiFree_00aa10f0(void*);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct CombinedBase : PrimaryPart, SecondaryPart
{
    virtual ~CombinedBase()
    {}
};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        _NiFree_00aa10f0(data);
    }
    void* data;
};
struct FUN_00ca4490 : CombinedBase
{
    ResourceMember resource;
    virtual ~FUN_00ca4490();
};
struct FUN_00ca4780_tableEntry
{
    unsigned int m_iIndex;
    void* m_pIntegerData;
};
struct FUN_00ca4780_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    FUN_00ca4780_tableEntry* m_pTable;
    void* hkNiTriStripsShape_getCollisionFilterInfo(unsigned int a1);
};
struct S_00ca49a0_Elem
{
    NiPointer<NiRefObject> obj;
    int unk04;
    S_00ca49a0_Elem(int v = 0) : obj(0)
    {
        unk04 = v;
    }
    bool operator==(const S_00ca49a0_Elem& o) const
    {
        return obj.m_pObject == o.obj.m_pObject && unk04 == o.unk04;
    }
    bool operator!=(const S_00ca49a0_Elem& o) const
    {
        return !(*this == o);
    }
};
struct S_00ca49a0_Array
{
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    int unk08;
    unsigned int m_uiESize;
    unsigned int m_uiCount;
    void NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(unsigned int idx, const S_00ca49a0_Elem& e);
};
struct HandlePage
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    unsigned short m_40;
};
struct HandleSlot
{
    HandlePage* m_pHandlePage;
    int m_04;
};
struct HandleOwner
{
    bool __thiscall IsDegenerate(unsigned int handle);
};
class HandleManager
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    HandleSlot* m_88;
    int m_8C;
    int m_90;

    int __thiscall hkNiTriStripsShape_getNextKey(int handle);
};
struct RecordEntry
{
    NiPointer<NiRefObject> object;
    unsigned int value;
    RecordEntry() : object(), value(0)
    {}
};
struct RecordArray
{
    void* vtable;
    RecordEntry* records;
    unsigned int capacity;
    unsigned int count;
    unsigned int elementSize;
    void ClearRecords();
};
class FUN_00ca4d20_cls;
class FNVSub3Blob
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVSub4
{
  public:
    void Attach(void* p);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVEntry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};
class FNVSub2
{
  public:
    void Reset();
    void Grow(void* p);
    void Store(unsigned int index, FNVEntry* entry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    void* m_14;
};
class FNVArg
{
  public:
    unsigned int unk00;
    float m_04;
    FNVSub2 m_08;
    FNVSub4 m_20;
};
class FUN_00ca4d20_cls
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
    FNVSub3Blob m_80;
    float m_90;
    unsigned int unk94;
    FNVEntry* m_98;
    unsigned int unk9c;
    int m_a0;
    void CopyEntriesToArg(FNVArg* a1);
};
struct S_00ca4e10_T
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00ca4e10_Out
{
    int unk00;
    void* unk04;
};
struct S_00ca4e10_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual char* v10();
};
struct S_00ca4e10_Cls
{
    int unk00;
    int unk04;
    S_00ca4e10_Obj* unk08;
    void bhkShape_CopyCinfo(S_00ca4e10_Out* out);
    char* bhkBvTreeShape_CopyCinfo(S_00ca4e10_Out* out);
};
extern int DAT_012682d8;
struct FUN_00cd2de0
{
    virtual ~FUN_00cd2de0();
};
struct FUN_00ca5290 : FUN_00cd2de0
{
    virtual ~FUN_00ca5290();
    void bhkSerializable_Kill();
};
extern int DAT_012682dc;
int* __cdecl bhkPackedNiTriStripsShape_GetRTTI();
struct MatchData
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
    int value84;
};
struct MatchObject
{
    int unk00;
    int unk04;
    MatchData* data;
    bool __thiscall bhkShape_IsEqual(MatchObject* rhs);
    bool __thiscall Equals(MatchObject* rhs);
};
struct S_00ca59d0_Out;
struct S_00ca59d0_Bin
{
    int unk00;
    unsigned int unk04;
    unsigned int(__cdecl* unk08)(S_00ca59d0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* unk0C)(S_00ca59d0_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* buf, unsigned int bytes, unsigned int* compSize, unsigned int n)
    {
        unk04 += unk0C(this, buf, bytes, compSize, n);
    }
};
template <class T> inline void S_00ca59d0_Save(S_00ca59d0_Bin& bin, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    bin.Write(p, n * sizeof(T), &uiSize, 1);
}
struct S_00ca59d0_Stream
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
    virtual void v12(int link);
    int unk4;
    int unk8;
    int unkC;
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
    int unk244;
    int unk248;
    int unk24C;
    S_00ca59d0_Bin* unk250;
};
struct S_00ca59d0_Vec4
{
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};
struct S_00ca59d0_Member
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    S_00ca59d0_Vec4 unk90;
    float unkA0;
};
struct S_00ca59d0_Self
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
    virtual void v41(int out);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(int* out);
    int unk04;
    S_00ca59d0_Member* unk08;
    void bhkShape_SaveBinary(S_00ca59d0_Stream* s);
    void bhkPackedNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* s);
};
struct TlsBlock_t
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
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
struct Owned_t
{
    void Destroy();
};
struct PoolFree_t
{
    void Free(void* p);
};
extern PoolFree_t DAT_011f6238;
struct FUN_00ca5a80_cls
{
    int unk00;
    int unk04;
    int unk08;
    Owned_t* m_0c;

    void ReleaseOwned(bool flag);
};
// FUN_00ca6600 : a one-line function - getter
extern int g_target_00ca6600;
void* bhkNiTriStripsShape_GetRTTI();
extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012682e4;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};
struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};
struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};
struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        DAT_012682e4 += 1;
    }
};
SpawnedObject* bhkNiTriStripsShape_CreateObject();
struct ArgB
{
    unsigned int unk00, unk04, unk08, unk0c;
    float f10;
};
struct ca6720Target
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float f20, f24, f28, f2c;
};
struct S_00ca6810_Callable
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
    virtual void slot54(int arg);
};
struct S_00ca6810_Entry
{
    S_00ca6810_Callable* callable;
    int unk04;
};
struct S_00ca6810_Inner
{
    void* unk00;
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
    S_00ca6810_Entry* unk98;
    int unk9c;
    int unkA0;
};
extern S_00ca6810_Callable* DAT_012682f0;
struct S_00ca6810_Class
{
    void* unk00;
    int unk04;
    S_00ca6810_Inner* unk08;

    void __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(int arg);
    void __thiscall bhkNiTriStripsShape_RegisterStreamables(int arg);
};
struct S_00ca6880_Node
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
};
struct S_00ca6880_Class
{
    int unk00;
    int unk04;
    S_00ca6880_Node* unk08;
    char __thiscall bhkShape_IsEqual(S_00ca6880_Class* arg);
    char __thiscall IsEquivalent(S_00ca6880_Class* arg);
};
static inline int Val(S_00ca6880_Class* o)
{
    if (o && o->unk08)
        return o->unk08->unka0;
    return 0;
}
extern __declspec(thread) int g_threadAllocationContext;
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
extern int DAT_010c771c;
extern int DAT_012682e4;
struct AllocationContextGuard
{
    int previous;
    AllocationContextGuard()
    {
        previous = g_threadAllocationContext;
        g_threadAllocationContext = 16;
    }
    ~AllocationContextGuard()
    {
        g_threadAllocationContext = previous;
    }
};
struct FNVShape : S_00cb79d0_Base
{
    FNVShape()
    {
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_vptr = &DAT_010c44e4;
        ++DAT_012686d0;
        m_vptr = &DAT_010c771c;
        ++DAT_012682e4;
    }
};
struct FNVShapeHost
{
    virtual void Slot00() = 0;
    virtual void Slot04() = 0;
    virtual void Slot08() = 0;
    virtual void Slot0c() = 0;
    virtual void Slot10() = 0;
    virtual void Slot14() = 0;
    virtual void Slot18() = 0;
    virtual void Slot1c() = 0;
    virtual void Slot20() = 0;
    virtual void Slot24() = 0;
    virtual void Slot28() = 0;
    virtual void Slot2c() = 0;
    virtual void Slot30() = 0;
    virtual void Slot34() = 0;
    virtual void Slot38() = 0;
    virtual void Slot3c() = 0;
    virtual void Slot40() = 0;
    virtual void Slot44() = 0;
    virtual void Slot48() = 0;
    virtual void Slot4c() = 0;
    virtual void Slot50() = 0;
    virtual void Slot54() = 0;
    virtual void Slot58() = 0;
    virtual void Slot5c() = 0;
    virtual void Slot60() = 0;
    virtual void Slot64() = 0;
    virtual void Slot68() = 0;
    virtual void Slot6c() = 0;
    virtual void Slot70() = 0;
    virtual void Slot74() = 0;
    virtual void Slot78() = 0;
    virtual void Slot7c() = 0;
    virtual void Slot80() = 0;
    virtual void Slot84() = 0;
    virtual void Slot88() = 0;
    virtual void Slot8c() = 0;
    virtual void Slot90() = 0;
    virtual void Slot94() = 0;
    virtual void Slot98() = 0;
    virtual void Slot9c() = 0;
    virtual void Slota0() = 0;
    virtual void Slota4() = 0;
    virtual void Slota8() = 0;
    virtual void Slotac() = 0;
    virtual void Slotb0() = 0;
    virtual void Slotb4() = 0;
    virtual void Slotb8() = 0;
    virtual void Slotbc() = 0;
    virtual void Slotc0() = 0;
    virtual void AssignShape(FNVShape* shape, int flags) = 0;
    FNVShape* CreateShape(int flags);
};
struct S_00ca7310_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
    S_00ca7310_Arr() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000)
    {}
};
struct S_00ca7310_Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00ca7310_Root()
    {
        unk00 = 0;
    }
};
struct S_00ca7310_Vec
{
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    S_00ca7310_Vec()
    {
        unk10 = 0.0f;
        unk14 = 0.0f;
        unk18 = 0.0f;
        unk1C = 0.0f;
    }
};
struct FUN_00ca7310 : S_00ca7310_Root
{
    S_00ca7310_Vec vec;
    int unk20;
    S_00ca7310_Arr unk24;
    S_00ca7310_Arr unk30;
    S_00ca7310_Arr unk3C;
    S_00ca7310_Arr unk48;
    S_00ca7310_Arr unk54;
    S_00ca7310_Arr unk60;
    S_00ca7310_Arr unk6C;
    S_00ca7310_Arr unk78;
    S_00ca7310_Arr unk84;
    S_00ca7310_Arr unk90;
    S_00ca7310_Arr unk9C;
    S_00ca7310_Arr unkA8;
    FUN_00ca7310();
};
struct MotionByte
{
    void FindFloatTableIndex(const float*);
};
struct MotionInstance
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void SetMass(float);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void SetInertia(const float*);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void SetGridPosition(const void*);
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
    MotionByte linearDamping;
    MotionByte angularDamping;
};
struct MotionStorage
{
    MotionInstance* FUN_00ca9270(const void*, const void*);
    MotionInstance* FUN_00d1e690(const void*, const void*);
    MotionInstance* FUN_00d21930(const void*, const void*);
    MotionInstance* FUN_00d1dfa0(const void*, const void*);
    MotionInstance* FUN_00ca9240(const void*, const void*);
    MotionInstance* InitFixedRigidMotion(const void*, const void*);
};
float NiMin(float, float);
float NiMax(float, float);
void hkpRigidBody_createDynamicRigidMotion(int type, const void* position, const void* rotation, float mass, const float* inertia,
                  const void* center, float linearDamping, float angularDamping, MotionStorage* storage);
struct Ctx
{
    void* pThis;
    int a1;
    char a2;
};
struct Obj
{
    virtual void v0();
    virtual void v1(Ctx*);
};
struct C
{
    char pad[0x8c];
    Obj** m8c;
    int m90;
    void NotifyAll(int a1, char a2);
};
extern int DAT_0126830c;
class FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_base();
};
class FUN_00ca9860_cls : public FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_cls();
    void bhkSerializable_Kill();
};
extern int DAT_01268310;
int __cdecl Runtime_EvaluateValue_00ca9910();
struct S_00ca9940_Child
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual unsigned int vfn_20();
};
struct S_00ca9940_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ca9940_Child* m_pChildObject;
};
void __cdecl hkBallAndSocketConstraintCinfo_ApplyScale(float f, S_00ca9940_Child* c);
void __cdecl hkHingeConstraintCinfo_ApplyScale(float f, S_00ca9940_Child* c);
void __cdecl hkMalleableConstraintCinfo_ApplyScale(float afValue, S_00ca9940_Obj* pObj);
struct FUN_00ca9aa0;
struct State
{
    unsigned int value;
    State() : value(0)
    {}
};
struct BaseOwner
{
    virtual void Act();
    unsigned short unk04;
    unsigned short unk06;
    State unk08;
    BaseOwner() : unk06(1), unk08()
    {}
};
struct InternalPart
{
    unsigned short mode;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    InternalPart() : mode(1)
    {}
    ~InternalPart();
};
void __fastcall hkpBridgeConstraintAtom_init(InternalPart* part, unsigned int command, FUN_00ca9aa0* parent);
struct FUN_00ca9aa0 : BaseOwner
{
    virtual void Act();
    unsigned int unk0c;
    InternalPart part;
    float value;
    FUN_00ca9aa0();
};
class BCA9D50BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCA9D50BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCA9D50BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCA9D50Stream
{
  public:
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
    unsigned int m_uiFileVersion;
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
    int unk244;
    int unk248;
    BCA9D50BinaryStream* m_pUnderlyingStream;
    BCA9D50BinaryStream* m_pBackingStream;
};
template <class T>
inline void BCA9D50BinaryStreamSave(BCA9D50BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCA9D50SaveBinary(BCA9D50Stream& kStream, const T& value)
{
    BCA9D50BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class BCA9D50Object;
void __cdecl bhkConstraintManager_SaveBinary(BCA9D50Stream& kStream, BCA9D50Object* pkObject);
struct BCA9D50Data
{
    int unk00;
    int unk04;
    int unk08;
    BCA9D50Object* m_pPointer;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
};
class BCA9D50Base
{
  public:
    void SaveBinary(BCA9D50Stream& kStream);
};
class BCA9D50Wrapper : public BCA9D50Base
{
  public:
    int unk00;
    BCA9D50Data* m_pUserData;

    void hkMalleableConstraintCinfo_SaveBinary(BCA9D50Stream& kStream);
};
struct FUN_00ca9b40_Obj
{
    void __thiscall UpdateFields_00ca9b40(int value);
};
struct FUN_00ca9e50_Obj
{
    int unk00;
    FUN_00ca9b40_Obj* unk04;

    void __thiscall ProcessState_00ca9e50(int value);
};
extern int DAT_01268318;
class PolyBase
{
  public:
    virtual ~PolyBase();
};
class FUN_00caa140_cls : public PolyBase
{
  public:
    virtual ~FUN_00caa140_cls();
    void bhkSerializable_Kill();
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct SpawnedObject20_b9537
{
    char m00[0x14];
    SpawnedObject20_b9537();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
SpawnedObject20_b9537* CreateSpawnedObject20();
unsigned int __cdecl PackBytesBigEndian(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
struct FUN_00cac9a0_Obj
{
    void __thiscall getCinfo(int value);
};
struct FUN_00cabfd0_Obj
{
    int unk00;
    int unk04;
    FUN_00cac9a0_Obj* unk08;

    void __thiscall bhkCharacterProxy_GetCinfo(int value);
};
struct FUN_00cabff0_res
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
};
struct FUN_00cabff0_cls
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
    virtual void vac();
    virtual void vb0();
    virtual FUN_00cabff0_res* SlotB4(int* p);
    void FUN_00c87650(int a);
    void bhkCharacterProxy_LoadBinary(int a);
};
void __fastcall ReadLinkID(int a);
struct S_00cac0b0_Arg
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
    virtual void v0c(int value);
};
struct S_00cac0b0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00cac0b0_Obj
{
    int unk00;
    int unk04;
    S_00cac0b0_Inner* unk08;
    S_00cac0b0_Inner* hkpCharacterProxy_getShapePhantom();
};
struct S_00cac0b0_cls
{
    int unk00;
    int unk04;
    S_00cac0b0_Obj* unk08;
    void bhkCharacterProxy_SaveBinary(S_00cac0b0_Arg* a);
    void SaveSerializeData(S_00cac0b0_Arg* a);
};
struct FUN_00cac110_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void bhkCharacterController_UnMarkWrite();
};
class CAC680World
{
  public:
    void Update();
};
class CAC680Listener
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void OnUpdate();

    int unk04;
};
class CAC680Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void Toggle();

    int unk04;
    CAC680World* m_pkWorld;
    int unk0C;
    CAC680Listener m_kListener;

    void ToggleAndUpdate();
};
// Rect-like record used by InitRect and its helper.
struct FUN_00cb0ed0_rect
{
    volatile int m_fMinimumU;
    volatile int m_fMinimumV;
    volatile int m_fMaximumU;
    volatile int m_fMaximumV;
    volatile bool m_bValueAt0C;
};
void __cdecl ResizeBuffer(FUN_00cb0ed0_rect* pRect, int aFlag);
void __cdecl InitRect(FUN_00cb0ed0_rect* pRect, int nLeft, int nSize);
static __declspec(noinline) char CB1030ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}
// Exported elsewhere through a function pointer, which keeps the helper's cdecl stack arguments.
char(__cdecl* g_pfnCB1030ToLower)(char) = CB1030ToLower;
int __cdecl CompareCaseInsensitive(const char* pcA, const char* pcB, int n);
// FUN_00cb75d0 : default constructor of the object whose first member holds
// the class table pointer.  The constructor clears three trailing dword
// members, sets a byte flag to 1 and installs the table pointer last.
extern int DAT_010c88b8;
struct FUN_00cb75d0_cls
{
    void* m_pVTable;
    int m_iValue04;
    unsigned char m_bValue08;
    int m_iValue0c;
    int m_iValue10;

    FUN_00cb75d0_cls();
};
static float DAT_010c8ae4 = 0.016f;
extern double DAT_010241b0;
struct S_00cb9770_Foo
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual float V41(float value);

    int unk04;
    unsigned short unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
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
    float unk50;

    void __thiscall bhkForceController_ApplyForce();
    bool GetActive()
    {
        return ((this->unk08 >> 3) & 1) != 0;
    }
    void __thiscall UpdateActiveState(float* param);
};
extern int DAT_01268188;
extern int DAT_0108febc;
struct FUN_00c87c30
{
    void* vtable;
    int unk04;
    int unk08;
    FUN_00c87c30();
};
struct InitializedField
{
    int value;
    InitializedField() : value(0)
    {}
    ~InitializedField();
};
struct FUN_00cb99a0 : FUN_00c87c30
{
    InitializedField unk0c;
    FUN_00cb99a0(char* source);
    void SpawnAndAttach(char* source);
};
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_01268324;
struct S_cb9a90_Base
{
    int unk04;
    int unk08;
    S_cb9a90_Base();
    virtual ~S_cb9a90_Base();
};
struct S_cb9a90_A : S_cb9a90_Base
{
    int unk0c;
    int unk10;
    S_cb9a90_A()
    {
        unk0c = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
};
struct S_cb9a90_B : S_cb9a90_A
{
    S_cb9a90_B()
    {
        DAT_01268274++;
    }
};
struct S_cb9a90_C : S_cb9a90_B
{
    S_cb9a90_C()
    {
        DAT_01268250++;
    }
};
struct FUN_00cb9a90 : S_cb9a90_C
{
    void bhkCapsuleShape_Init(int a, int b, float c);
    FUN_00cb9a90(int a, int b, float c);
    virtual ~FUN_00cb9a90();
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126864c;
GlobalObjectO2_00a7b610* __cdecl bhkBallAndSocketConstraint_GetRTTI();
struct CB9B80Header
{
    int unk00;
};
struct CB9B80BaseInfo
{
    int unk00;
};
struct CB9B80Info : CB9B80Header, CB9B80BaseInfo
{
};
class CB9B80RefObject
{
  public:
    CB9B80RefObject();
    virtual ~CB9B80RefObject();

    int unk04;
    int unk08;
};
class CB9B80SerializableObject : public CB9B80RefObject
{
  public:
    CB9B80SerializableObject() : m_pkWorld(0)
    {}

    void* m_pkWorld;
};
class CB9B80WorldObject : public CB9B80SerializableObject
{
  public:
    CB9B80WorldObject()
    {
        ++ms_uiCount;
    }
    virtual ~CB9B80WorldObject();

    static unsigned int ms_uiCount;
};
class FUN_00cb9b80 : public CB9B80WorldObject
{
  public:
    FUN_00cb9b80(CB9B80Info* pkInfo);
    virtual ~FUN_00cb9b80();

    void Init(CB9B80BaseInfo* pkInfo);

    static unsigned int ms_uiCount;
};
struct CpuOpaque;
extern CpuOpaque DAT_01268610;
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00cb9c00();
class FUN_00cb9c70_item
{
  public:
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
    virtual void v21(int a1);
};
class FUN_00cb9c70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb9c70_item** m_ppItems;
    unsigned int m_uiCount;
    bool Check(int a1);
    bool bhkRagdollTemplate_RegisterStreamables(int a1);
};
struct RefCountedStandIn
{
    virtual void Unk0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};
struct ArgStandIn
{
    RefCountedStandIn* FUN_00a63430();
};
class FUN_00cb9ee0_cls
{
  public:
    void AssignRefCountedArray(ArgStandIn* arg);
    void FUN_00a7b3b0(ArgStandIn* arg);

    char unk00[0x10];
    RefCountedStandIn** m_10;
    unsigned int m_14;
};
class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class BCB9F60Stream
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void SaveLinkID(void* pkObject);

  public:
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
    unsigned int m_uiFileVersion;
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
    int unk244;
    int unk248;
    BCB9F60BinaryStream* m_pUnderlyingStream;
    BCB9F60BinaryStream* m_pBackingStream;
};
template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}
template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}
class BCB9F60ExtraData
{
  public:
    void SaveBinary(BCB9F60Stream& kStream);
};
class BCB9F60LinkData : public BCB9F60ExtraData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppkObjects;
    unsigned int m_uiCount;

    void bhkRagdollTemplate_SaveBinary(BCB9F60Stream& kStream);
};
// Releases the resource held by the object and resets it to its empty state.
typedef void(__stdcall* FreeFn)(void*);
struct FUN_00cb9fd0_cls
{
    void* m_ppVirtualMethodTable;
    void* m_pData;
    int m_i08;
    int m_i0c;
    void ResetAndFreeData();
};
class FUN_00cba0d0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    long m_04;
};
void __stdcall ReleaseItems(FUN_00cba0d0_cls** items, unsigned int count);
extern void* DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);
void* __cdecl FUN_00a5b690(int flag);
class CBaseOwner
{
  public:
    virtual void unk00();
    unsigned int unk04;
    CBaseOwner();
    ~CBaseOwner();
};
class CSlot08
{
  public:
    void* p;
    CSlot08(void* v)
    {
        p = v;
    }
    ~CSlot08();
};
class CSubA
{
  public:
    virtual void unkA00();
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0c;
    CSubA()
    {
        unkA04 = 0;
        unkA08 = 0;
        unkA0c = 0;
    }
    ~CSubA();
};
class CSubB
{
  public:
    virtual void unkB00();
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0c;
    CSubB()
    {
        unkB04 = 0;
        unkB08 = 0;
        unkB0c = 0;
    }
    ~CSubB();
};
class FUN_00cba110 : public CBaseOwner
{
  public:
    CSlot08 m_08;
    CSubA m_0c;
    CSubB m_1c;
    FUN_00cba110();
};
extern int DAT_01268400;
void* __cdecl bhkRagdollTemplateData_GetRTTI();
extern unsigned int DAT_01268418;
void hkMemorySystem_replaceInstance(unsigned int a1);
// FUN_00cbd960 registers the 0x00cbd7a0 comparison helper in the global
// callback slot at 0x01268430, which is later called indirectly with two
// arguments (see the indirect call through 0x01268430).
extern void(__cdecl* DAT_01268430)(void*, void*);
void __cdecl InsertIntoContext(void* pList, void* pContext);
void __cdecl hkpFixedBufferCdPointCollector_registerDefaultAddCdPointFunction(void);
extern int DAT_01268434;
struct PrimaryBase
{
    virtual ~PrimaryBase();
};
struct HolderBase
{
    void Release();
};
struct FUN_00cbd970 : PrimaryBase
{
    int unk04;
    virtual ~FUN_00cbd970();
};
struct WriteStream
{
    void* unk00;
    unsigned int transferred;
    void* unk08;
    int(__cdecl* write)(WriteStream*, const void*, unsigned int, unsigned int*, int);
};
struct BufferOwner
{
    void* unk00;
    unsigned char* buffer;
    void __thiscall hkConstraintCinfo_SaveBinary(void*);
    void __thiscall WriteToStream(void*);
};
extern "C" void _ReadWriteBarrier(void);
extern float DAT_0104da48;
struct FUN_00cbe820_sub
{
    void Init(float* value);
};
struct FUN_00cbe820_cls
{
    short m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c;
    short m_90;
    short m_92;
    short m_94;
    unsigned char m_96;
    FUN_00cbe820_sub m_97;
    float m_98;

    FUN_00cbe820_cls* hkpHingeConstraintData_Atoms_Atoms();
};
struct FUN_00cbe880_Class
{
    int m_iWordAt00;
    void __thiscall UpdateFields_00cbe880();
};
extern "C" void __cdecl FUN_00c9eec0();
unsigned char __stdcall bhkWorldObject_Add(void*);
void* __cdecl PackBytesBigEndian(int, int, int, int);
struct FUN_00c68e30_cls
{
    void __thiscall bhkWorld_SetDebugObjectColor(void* a, void* b);
};
struct FUN_00cbe890_cls
{
    int m_auiShapeKeys[7];
    unsigned char m_1c;
    unsigned char __thiscall bhkCollisionBox_Add(void* a);
};
// Release the per-body lists: destroy every inner array, then free the outer array.
template <class T> inline void CBF490Deallocate(hkMemoryAllocator& alloc, T* p, int numElem)
{
    alloc.ReturnMemory(p, numElem * sizeof(T));
}
template <class T> __forceinline void CBF490Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}
template <class T> struct CBF490Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~CBF490Array() throw()
    {
        hkMemoryAllocator& alloc = GetHavokHeap(*(&hkMemoryRouter::getInstance()));
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    __forceinline void ClearAndRelease() throw()
    {
        hkMemoryAllocator& alloc = GetHavokHeap(*(&hkMemoryRouter::getInstance()));
        CBF490Destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            CBF490Deallocate(alloc, m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
class CBF490Lists
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CBF490Array<CBF490Array<int> > m_kLists;

    void ClearLists();
};
class CBFC60Dispatcher
{
  public:
    void SetEnableChecks(hkBool bEnable);
};
void __cdecl hkpListAgent_registerAgent(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpCollectionAgent3_registerAgent3(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpCollectionCollectionAgent3_registerAgent3(CBFC60Dispatcher* pkDispatcher);
void __cdecl RegisterConvexListAgentCollisionFuncs(CBFC60Dispatcher* pkDispatcher);
void __cdecl RegisterAgent3Entries(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpHeightFieldAgent_registerAgent(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpAgentRegisterUtil__registerListAgents(CBFC60Dispatcher* pkDispatcher);
struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetKind();
};
struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};
struct PassEntry
{
    PropHolder* pHolder;
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
};
struct ShaderData
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
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unkb2;
    PropHolder** ppExtra;
    int iExtraCount;
};
struct ShaderProp
{
    int unk00;
    int unk04;
    ShaderData* pData;
};
struct CastResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShaderProp* pShader;
};
struct RttiObject
{
    CastResult* DynamicCast(const void* type);
};
extern const int g_kShaderRtti;
struct GeomNode;
struct ChildNode
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
    GeomNode** ppChildren;
    unsigned short unka4;
    unsigned short usChildCount;
};
struct GeomNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ChildNode* GetAsNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RttiObject* pProp;
};
struct GeomArray
{
    virtual void v00();
    virtual GeomNode** Allocate(unsigned int count);
    GeomNode** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    void Grow(unsigned int newCap, unsigned int size);

    __forceinline void Add(GeomNode* p)
    {
        if (uiSize == uiCapacity)
        {
            if (uiCapacity == 0)
            {
                pData = Allocate(4);
                uiCapacity = 4;
            }
            else
            {
                unsigned int newCap = uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2;
                Grow(newCap, uiSize);
                uiCapacity = newCap;
            }
        }
        pData[++uiSize - 1] = p;
    }
};
struct GeomCollector
{
    void CollectShaderNodes(GeomNode* pObj, GeomArray* pArray);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:
    virtual ~BaseCA3()
    {}

    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
class FUN_00ca3b90 : public BaseCA3
{
  public:
    virtual ~FUN_00ca3b90();

    NiPointer<NiRefObject> m_pReferencedObject;
};
// The pack prelude keeps only the declaration of this file-static helper (used by a
// neighbouring function's function-pointer table); provide its body so the unit links.
void* NiMalloc(unsigned int size);
void NiFree(void* p);
struct PtrEntry
{
    NiPointer<NiRefObject> m_pReferencedObject;
    int m_iValue;
    PtrEntry() : m_pReferencedObject(0), m_iValue(0)
    {}
    bool operator==(const PtrEntry& other) const
    {
        return m_pReferencedObject == other.m_pReferencedObject && m_iValue == other.m_iValue;
    }
    bool operator!=(const PtrEntry& other) const
    {
        return !(*this == other);
    }
};
struct PtrEntryArray
{
    virtual ~PtrEntryArray();
    PtrEntry* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Resize(unsigned int uiMaxSize);
};
// Prelude helper whose body the unit prelude omits.
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCA56B0AllocTag;
struct CA56B0AllocTagScope
{
    int m_iSaved;

    CA56B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA56B0AllocTag;
        g_iCA56B0AllocTag = aiAllocationTag;
    }
    ~CA56B0AllocTagScope()
    {
        g_iCA56B0AllocTag = m_iSaved;
    }
};
void CA56B0Lock();
void CA56B0Unlock();
class CA56B0RefObject
{
  public:
    CA56B0RefObject();
    virtual ~CA56B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CA56B0Shape : public CA56B0RefObject
{
  public:
    CA56B0Shape() : m_pUserData(0), m_pkExtra(0)
    {
        ++ms_iCount;
    }
    virtual ~CA56B0Shape();

    void* m_pUserData;
    void* m_pkExtra;

    static int ms_iCount;
};
class CA56B0MidShape : public CA56B0Shape
{
  public:
    CA56B0MidShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0MidShape();

    static int ms_iCount;
};
class CA56B0ListShape : public CA56B0MidShape
{
  public:
    CA56B0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0ListShape();

    static int ms_iCount;
};
class CA56B0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void AddShape(CA56B0Shape* pkShape, int iIndex);

    CA56B0Shape* CreateListShape(int iIndex);
};
struct ReadBin
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadBin*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        position += read(this, data, bytes, sizes, n);
    }
};
template <class T> inline void Load(ReadBin& bin, T* data, unsigned int n)
{
    unsigned int size = sizeof(T);
    bin.Read(data, n * sizeof(T), &size, 1);
}
struct ReadStream
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
    ReadBin* binary;
    void ReadLinkID();
};
struct ReadData
{
    int unk00, unk04;
    int value08;
    int unk0c;
    float vector10[4];
};
struct CA5940
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual ReadData* GetData(char* out);
    void bhkShape_LoadBinary(ReadStream* stream);
    void ReadDataFromStream(ReadStream* stream);
};
extern __declspec(thread) int g_CA6E60AllocTag;
struct CA6E60AllocTagScope
{
    int m_iSaved;

    CA6E60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CA6E60AllocTag;
        g_CA6E60AllocTag = aiAllocationTag;
    }
    ~CA6E60AllocTagScope()
    {
        g_CA6E60AllocTag = m_iSaved;
    }
};
class CA6E60Buffer
{
  public:
    virtual ~CA6E60Buffer()
    {
        NiFreeAlias(m_pResource);
    }

    void* m_pResource;
};
class CA6E60Data
{
  public:
    static void operator delete(void* pvMem)
    {
        unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
        _g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
    }

    int unk00;
    int unk04;
    CA6E60Buffer m_kBuffer;
};
class CA6E60Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CA6E60Data* m_pUserData;

    void ReleaseData(bool bRelease);
};
extern char* DAT_012682e8;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
char* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
struct PartFlags
{
    void* vtable;
    int references;
    int unk08;
    unsigned short flags;
};
struct PartValue
{
    int value;
    void AppendToViewerStrings(StrArr* output);
};
struct DiagnosticShape : S_00ca6810_Class
{
    void bhkShapeCollection_GetViewerStrings(StrArr* output);
    void AppendSubpartDiagnostics(StrArr* output);
    unsigned int Count() const
    {
        return this && unk08 ? (unsigned int)unk08->unkA0 : 0;
    }
    S_00ca6810_Entry& Part(unsigned int index) const
    {
        if (this && unk08)
            return unk08->unk98[index];
        return *reinterpret_cast<S_00ca6810_Entry*>(&DAT_012682f0);
    }
};
struct LockFlag_t
{
    bool m_kPointB;
    LockFlag_t(bool b) : m_kPointB(b)
    {}
    LockFlag_t(const LockFlag_t& o) : m_kPointB(o.m_kPointB)
    {}
};
struct WorldLock_t
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Mark(unsigned int id, LockFlag_t flag);
};
extern WorldLock_t* g_pWorldLock_01268360;
struct CAC300Owner
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
    virtual void SetObject(hkReferencedObject* obj);
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
    virtual void Apply(int arg);

    void bhkCharacterProxy_Init(int arg);
};
// Prelude helper whose body the unit prelude omits.
// Factory: create a new 0x40-byte object.
class BA2D0Object
{
  public:
    BA2D0Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};
BA2D0Object* CreateBA2D0Object();
// Prelude helper whose body the unit prelude omits.
// NiTMap destructor: remove all entries, then the base map frees its hash table.
void __cdecl CBC740NiFree(void* pvMem);
class CBC740MapBase
{
  public:
    virtual ~CBC740MapBase()
    {
        RemoveAll();
        CBC740NiFree(m_ppkHashTable);
    }
    void RemoveAll();

    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00cbc740 : public CBC740MapBase
{
  public:
    virtual ~FUN_00cbc740();
};
extern __declspec(thread) int g_iCBEA40AllocTag;
struct BCBEA40AllocTagScope
{
    int m_iSaved;

    BCBEA40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCBEA40AllocTag;
        g_iCBEA40AllocTag = aiAllocationTag;
    }
    ~BCBEA40AllocTagScope()
    {
        g_iCBEA40AllocTag = m_iSaved;
    }
};
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > BCBEA40StringArray;
extern const char* g_pcCBEA40Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class BCBEA40Owner
{
  public:
    void bhkSimpleShapePhantom_GetViewerStrings(BCBEA40StringArray* pkArray);
    void AddNameToArray(BCBEA40StringArray* pkArray);
};
// Registers a batch of classes with the registry while it is temporarily locked.
class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
class CBFC10Registry
{
  public:
    void Set(CBFC10Bool bLocked);
};
void __cdecl CBFC10RegisterA(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterB(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterC(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterD(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterE(CBFC10Registry* pkRegistry);
void __cdecl RegisterAll(CBFC10Registry* pkRegistry);
extern unsigned int DAT_011b1730;
extern unsigned int DAT_011b1734;
struct FUN_00ca3dc0_cls
{
    int unk00;
    int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned short m_10;
    unsigned short unk12;
    void* m_14;
    void* m_18;
    int unk1C;
    void* m_20;
    void* m_24;
    void __thiscall hkPackedNiTriStripsData_SaveBinary(S_00ca59d0_Stream* s);
};
struct SArr046
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char*& value);
    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};
struct InnerEntry046
{
    void* f0;
    int f4;
    void* f8;
};
struct Inner046
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m_uiItemCount;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    InnerEntry046* m_entries;
};
struct SubObj046
{
    int unk00[0x21];
    Inner046* m_84;
};
struct NodePtr046
{
    void* m_p;
    void AppendToViewerStrings(SArr046* arr);
};
extern int DAT_012682dc;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* a);
char* __cdecl NiGetViewerString_00a7d510(const char* s, unsigned int n);
char* __cdecl NiGetViewerString_00a7d4d0(const char* s, int n);
struct ThisCls046
{
    int unk00;
    int unk04;
    SubObj046* m_8;
    void bhkShapeCollection_GetViewerStrings(SArr046* arr);
    void AppendSubpartNames(SArr046* arr);
};
extern int DAT_01268340;
struct LinkedObject
{
    int unk00[2];
    int m_iValue;  // +0x08
};
struct LinkStream
{
    LinkedObject* FUN_00a63430();
};
class LinkBase
{
  public:
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
    virtual LandTextureParameters* GetHavokData(char& rcFlag);  // +0xb4
    void bhkSerializable_LinkObject(LinkStream& kStream);                     // base LinkObject
};
class LinkWrapper : public LinkBase
{
  public:
    void CopyHavokValueFromStream(LinkStream& kStream);
};
struct FUN_00cb9d80_child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(void* context);
};
typedef int(__cdecl* FUN_00cb9d80_read_fn)(void* stream, void* data, unsigned int size, void* result, int flag);
struct FUN_00cb9d80_stream
{
    int unk00;
    int position;
    int unk08;
    FUN_00cb9d80_read_fn read;
};
struct FUN_00a641f0_class
{
    void __thiscall WriteObjectLink(void* object);
};
void __stdcall nullsub_3(void* context);
struct FUN_00cb9d80_class
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0c;
    FUN_00cb9d80_child** unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    void __thiscall ReadFromStream(void* context);
};
struct StandInBinaryStream
{
    int m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(StandInBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
template <class T> inline void BinaryStreamLoad(StandInBinaryStream& kIs, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kIs.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}
struct StandInStream : public NiStream
{
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
    int unk244;
    int unk248;
    StandInBinaryStream* m_pkIStream;

    void FUN_00a64df0(void* pLinkID);
};
template <class T> inline void StreamRead(StandInStream& kStream, T& val)
{
    BinaryStreamLoad(*kStream.m_pkIStream, &val, 1);
}
struct MemoryManager_t
{
    void* Game_DoHeapAlloc(unsigned int size);
};
extern int DAT_0108ff98;
extern int DAT_010c5dc0;
struct Cinfo_13 : public BaseCinfo_blk_00ca0000_o2_rtm_variant
{
    __forceinline Cinfo_13()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_0 : public BaseCinfo_blk_00ca0000_o2_rtm_variant
{
    __forceinline Cinfo_0()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_1 : public BaseCinfo_blk_00ca0000_o2_rtm_variant
{
    __forceinline Cinfo_1()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_2 : public BaseCinfo_blk_00ca0000_o2_rtm_variant
{
    __forceinline Cinfo_2()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct Cinfo_7 : public BaseCinfo_blk_00ca0000_o2_rtm_variant
{
    __forceinline Cinfo_7()
    {}
    virtual void LoadBinary(NiStream& kStream);
};
struct FUN_00ca0ca0_Class
{
    void* m_vtbl;
    FUN_00ca0ca0_Class* __thiscall FUN_00ca0ca0(int flags);
};
struct MemMgr_00aa4060
{
    void __thiscall MemoryManager_Deallocate(FUN_00ca0ca0_Class* p);
};
extern int DAT_010c7304;
struct WalkPlacement
{
};
inline void* operator new(unsigned int, WalkPlacement, void* p)
{
    return p;
}
struct WalkRTTI
{
    const char* name;
    WalkRTTI* parent;
};
extern WalkRTTI DAT_01267b70, DAT_0126817c;
extern int DAT_0126818c;
struct WalkObject
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    struct WalkBody* body;
    struct WalkType* fallback;
    WalkObject* FUN_00653290(const WalkRTTI*);
    __forceinline WalkObject* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&DAT_0126818c) ? this : 0;
    }
    bool IsKind(const void* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline WalkObject* KindCast(WalkObject* item)
{
    if (!item)
        return 0;
    return item->IsKind(&DAT_0126818c) ? item : 0;
}
struct WalkType
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct WalkBody
{
    int unk, unkCur, unkValue;
    WalkType* type;
};
struct WalkLink
{
    WalkObject* item;
    WalkLink* next;
    WalkObject* GetItem()
    {
        return item;
    }
    WalkLink* Next()
    {
        return next;
    }
};
struct WalkLeaf
{
    int unk, unkCur;
    void* object;
    int unk0c, uNewnk;
    WalkLink links;
};
class NiRTTI;
class GarbageCollectorObjectPtr
{
  public:
    WalkObject* object;
    int high;
};
GarbageCollectorObjectPtr* __cdecl bhkWorldObject_GetProperty(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> __forceinline void WalkDestruct(T* ptr, int count)
{
    for (int i = 0; i < count; ++i)
        ptr[i].~T();
}
template <class T> inline void WalkDeallocate(hkMemoryAllocator& alloc, T* ptr, int count)
{
    alloc.bufFree(ptr, count * int(sizeof(T)));
}
struct WalkArray
{
    void** data;
    int size;
    int capacity;
    WalkArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~WalkArray()
    {
        hkMemoryAllocator& alloc = GetHavokHeap(*(&hkMemoryRouter::getInstance()));
        ClearAndRelease(alloc);
    }
    void ClearAndRelease(hkMemoryAllocator& alloc)
    {
        WalkDestruct(data, size);
        size = 0;
        if ((capacity & 0x80000000) == 0)
            WalkDeallocate(alloc, data, capacity & 0x3fffffff);
        data = 0;
        capacity = 0x80000000;
    }

    __forceinline void Add(void* const& value)
    {
        hkMemoryAllocator* alloc = &GetHavokHeap(*(&hkMemoryRouter::getInstance()));
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(alloc, this, 4);
        *new (WalkPlacement(), &data[size]) void* = value;
        ++size;
    }
};
inline WalkObject* GetRoot(void* obj)
{
    GarbageCollectorObjectPtr temp;
    return bhkWorldObject_GetProperty(&temp, (NiAVObject*)obj, (const NiRTTI*)&DAT_01267b70)->object;
}
void __stdcall CollectLeafObjects(WalkLeaf* leaf, WalkArray* outObjects, WalkArray* outBodies);
struct TlsBlock_ca57
{
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_ca57 g_tls;
struct TlsFlagGuard_ca57
{
    unsigned int m_saved;
    TlsFlagGuard_ca57()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 16;
    }
    ~TlsFlagGuard_ca57()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class Pool_ca57
{
  public:
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
class Node_ca57
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Node_ca57();
    static void operator delete(void*) throw()
    {}
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->Game_DoHeapAlloc(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
};
class Owner_ca57
{
  public:
    unsigned int unk00, unk04, m_08;
    unsigned int* m_0c;
    void bhkPackedNiTriStripsShape_CopyCinfo(unsigned int*);
    unsigned int* GetOrCreateNode(bool*);
};
int __cdecl bhkShape_CanShare(int param_1);
int __cdecl bhkExtendedMeshShape_CanShare(int param_1);
template <typename T> struct FNVArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~FNVArray()
    {
        _clearAndDeallocate(GetHavokHeap(*(&hkMemoryRouter::getInstance())));
    }
};
struct FUN_00ca73c0
{
    int unk00[9];
    FNVArray<int> unk24;
    FNVArray<int> unk30;
    FNVArray<int> unk3C;
    FNVArray<int> unk48;
    FNVArray<char> unk54;
    FNVArray<int> unk60;
    FNVArray<int> unk6C;
    FNVArray<int> unk78;
    FNVArray<int> unk84;
    FNVArray<int> unk90;
    FNVArray<int> unk9C;
    FNVArray<int> unkA8;
    ~FUN_00ca73c0();
};
struct PositionCommand
{
    unsigned char opcode;
    void* sender;
    float x;
    float y;
    float z;
};
struct PositionQueue
{
    void hkpWorld_queueOperation(PositionCommand* command);
};
struct PositionOwner
{
    int unk00;
    int unk04;
    PositionQueue* queue;

    void OnTrigger(float* position);
    void SendPositionCommand(float* position);
};
void __cdecl bhkConstraint_LoadBinary();
void __cdecl bhkBallAndSocketConstraint_LoadBinary();
char Runtime_ReturnConstant_0xff();
unsigned int __cdecl PackColorBigEndian(float, float, float, float);
struct RNG_cabbd0
{
    int unk00;
    unsigned int m_uiState;

    unsigned int Next()
    {
        m_uiState = m_uiState * 1664525 + 1013904223;
        return m_uiState;
    }
};
unsigned int __cdecl hkColor_getRandomColor(RNG_cabbd0* rng);
extern int DAT_011b1a58[8];
extern char DAT_00ffffff;
int __cdecl CombineIndexedMaskAndShift(int aiIndex, int aiHighByte);
struct SomeClass
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
};
int* __fastcall ahkpCharacterProxy_GetCdPoints(SomeClass* pThis);
struct FnvCpu_FUN_00cac950_CpuObject
{
    char* hkpCharacterProxy_getLinearVelocity();
};
struct FUN_00CAFEC0_This
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
    void** unk60;
    int unk64;
    float unk68;
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
};
struct FUN_00CAFEC0_Class
{
    float __thiscall GetTableValue(int param_2, int param_3);
};
struct FUN_00cb0a70_Class
{
    void* ReturnSelf(int a);
};
int __cdecl FUN_00ec6cc4(char*, const char*, char*);
void __cdecl hkString_sprintf(char* a, const char* b, char* c);
extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);
int __cdecl j_strncmp(const char* s1, const char* s2, unsigned int count);
void __stdcall isOk_00cd4af0(int a1);
unsigned int __stdcall hkRotation_isOk(unsigned int uiValue);
void __cdecl bhkPCollisionObject_LoadBinary(void);
void __cdecl bhkSPCollisionObject_LoadBinary(void);
void __cdecl bhkPCollisionObject_LinkObject();
void __cdecl bhkSPCollisionObject_LinkObject();
void __cdecl bhkCollisionObject_RegisterStreamables();
void __cdecl bhkBlendCollisionObject_RegisterStreamables();
bool __cdecl bhkCollisionObject_IsEqual(int param_1, int param_2);
bool __cdecl bhkSPCollisionObject_IsEqual(int param_1, int param_2);
extern int DAT_012683e8;
struct FUN_00c86720
{
    virtual ~FUN_00c86720();
};
struct FUN_00cb83f0 : FUN_00c86720
{
    void bhkSerializable_Kill();
    virtual ~FUN_00cb83f0();
};
struct CpuOpaque;
extern CpuOpaque DAT_012683ec;
CpuOpaque* __cdecl bhkOrientHingedBodyAction_GetRTTI();
void __cdecl bhkUnaryAction_CopyMembers();
void __cdecl bhkOrientHingedBodyAction_CopyMembers();
extern "C" void __cdecl FUN_00aa1460(void* self, int size);
struct FUN_00cb8480_class
{
    void FUN_00cb83f0();
    FUN_00cb8480_class* FUN_00cb8480(char flag);
};
struct FUN_00d2acf0
{
    void* vtable;
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    unsigned int unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34;
    unsigned int unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54;
    unsigned int unk58, unk5C;

    FUN_00d2acf0(void* source, void* start, void* end, float nearValue, float farValue, int flags);
    void FUN_00c905b0();

    static void* operator new(unsigned int bytes)
    {
        hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
        FUN_00d2acf0* object = (FUN_00d2acf0*)GetHavokHeap(*router).blockAlloc(bytes);
        object->memorySizeAndFlags = (unsigned short)bytes;
        return object;
    }
    static void operator delete(void* object);
};
struct FUN_00cb88d0_owner : CAC300Owner
{
    void __thiscall CreateShapeAndApply(void* parameters);
};
extern GlobalObjectO2_00a7b610 g_012683ec;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610* p);
struct FUN_00cb89c0_cls
{
    void bhkUnaryAction_GetViewerStrings(SArr046* arr);
    void AppendGlobalReference(SArr046* arr);
};
struct CpuOpaque;
extern CpuOpaque DAT_012683f4;
CpuOpaque* __cdecl bhkForceController_GetRTTI();
void __cdecl FUN_00a7b3d0();
void __cdecl bhkExtraData_IsEqual();
class CBADDynamicArray : public CA0E60Array
{
  public:
    void Runtime_ProcessEntries_00cb9d50(void** elements, unsigned int count);
    void ReleaseItems(void** elements, unsigned int count);
    void BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int requestedSize, bool compact);
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01268408;
GlobalObjectO2_00a7b610* __cdecl bhkRagdollTemplate_GetRTTI();
struct FUN_00cbaf90_Obj
{
    void FUN_00cbaf90();
};
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct FUN_00cbb130_Class : FUN_00cbaf90_Obj
{
    unsigned int __thiscall FUN_00cbb130(unsigned char flag);
};
extern int DAT_010c9194;
struct FUN_00cbc460
{
    void* m_ppVirtualMethodTable;
    unsigned short m_04;
    unsigned short m_w06;
    // volatile keeps the vptr store ahead of the zero stores, as in the original
    void* volatile m_p08;
    void* volatile m_p0c;
    void* volatile m_p10;
    void* volatile m_p14;
    void* volatile m_p18;
    void* volatile m_p1c;
    void* volatile m_p20;
    void* volatile m_p24;
    void* volatile m_p28;
    void* volatile m_p2c;
    void* volatile m_p30;
    FUN_00cbc460();
};
void __cdecl ClearLists();
void __cdecl Runtime_ClearLists_Thunk();
struct HeapAllocator
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern HeapAllocator g_heapAllocator;
struct RefHolder
{
    NiRefObject* object;
    RefHolder()
    {}
    ~RefHolder()
    {
        if (object)
            object->DecRefCount();
    }
};
struct ThreadLocalData
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
    int heapIndex;
};
extern __declspec(thread) ThreadLocalData g_threadLocalData;
struct HeapIndexGuard
{
    int saved;
    HeapIndexGuard(int index)
    {
        saved = g_threadLocalData.heapIndex;
        g_threadLocalData.heapIndex = index;
    }
    ~HeapIndexGuard()
    {
        g_threadLocalData.heapIndex = saved;
    }
};
extern int DAT_010c7600;
struct ShapePrefix
{
    int unk00;
    float unk04;
    ShapePrefix() : unk00(0), unk04(0.0f)
    {}
};
struct ShapeStrips
{
    void* vtbl;
    void* pBase;
    unsigned int maxSize;
    unsigned int size;
    unsigned int eSize;
    unsigned int growBy;

    ShapeStrips(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        maxSize = uiMaxSize;
        growBy = uiGrowBy;
        size = 0;
        eSize = 0;
        if (uiMaxSize > 0)
            pBase = g_heapAllocator.Allocate(uiMaxSize);
        else
            pBase = 0;
        vtbl = &DAT_010c7600;
    }
};
struct ShapeVector
{
    float x;
    float y;
    float z;
    float w;
    ShapeVector()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};
struct ShapeData : ShapePrefix
{
    ShapeStrips strips;
    ShapeVector scale;

    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_heapAllocator.Allocate(size + 16);
        unsigned char off = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += off;
        p[-1] = off;
        return p;
    }
    static void operator delete(void* p)
    {
        if (p)
        {
            unsigned char off = ((unsigned char*)p)[-1];
            g_heapAllocator.Deallocate((char*)p - off);
        }
    }

    ShapeData()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
    void SetScale()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
};
struct ShapeOwnerTarget
{
    void CopyEntriesToArg(ShapeData* data);
};
struct MyObj
{
    int unk00;
    int unk04;
    ShapeOwnerTarget* unk08;
    ShapeData* unk0c;

    void bhkShape_CopyCinfo(ShapeData* data);
    ShapeData* GetOrCreateShapeData(bool* created);
};
struct FNV_InnerObject
{
    virtual void __fastcall Call0(int);
    virtual void __fastcall Call1(int);
    virtual void __fastcall Call2(int);
    virtual void __fastcall Call3(int);
    virtual void __fastcall Call4(int);
    virtual void __fastcall Call5(int);
    virtual void __fastcall Call6(int);
    virtual void __fastcall Call7(int);
    virtual void __fastcall Call8(int);
};
struct FNV_OwnerObject
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
    FNV_InnerObject inner;
    void __fastcall hkpRigidBody_setInertiaInvLocal(int);
};
struct CA8B80Command;
struct CA8B80Queue
{
    void __thiscall Push(CA8B80Command*);
};
struct FUN_00ca8a30_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    CA8B80Queue* m_8;
    void __thiscall PushCommand(NiPoint3*);
    void __thiscall hkpRigidBody_setAngularVelocity(NiPoint3*);
};
struct FUN_00ca8a30_Local
{
    unsigned char m_kPointB;
    FUN_00ca8a30_Class* m_p;
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};
extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;
extern __declspec(thread) int tls_memContext;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl _delete(void* p, int size);
struct ScopedMemContext_ca9e60
{
    int m_iOld;
    ScopedMemContext_ca9e60(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext_ca9e60()
    {
        tls_memContext = m_iOld;
    }
};
struct Holder_ca9e60
{
    void* p;
    Holder_ca9e60(void* q) : p(q)
    {}
    ~Holder_ca9e60()
    {
        if (p)
            _delete(p, 0x10);
    }
};
struct Host_ca9e60
{
    void* __thiscall bhkMalleableConstraint_Clone(void* arg);
    void __thiscall bhkConstraint_CopyMembers(void* a, void* b);
};
void __cdecl DispatchToTarget();
void __cdecl bhkHingeLimitsConstraint_SetEntityB();
extern int DAT_01268334;
extern int DAT_01268338;
extern int DAT_0126833c;
unsigned int __cdecl hkColor_getRandomColor(int*);
unsigned int __cdecl hkColor_getRandomColor_00cabe90();
struct CA0F0Result
{
    int unk00;
    int unk04;
    int m_8;
};
struct CA0F0Object : BaseThunk
{
    int __thiscall GetResultValue();
};
struct RefCountedCAC4B0
{
    int unk00;
    long m_iRefCount;
};
struct ShapeHolderCAC4B0
{
    int unk00;
    int unk04;
    int unk08;
    RefCountedCAC4B0* m_pkShape;
};
struct WorldObjectCAC4B0
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
    void* m_pkUserData;
    ShapeHolderCAC4B0* hkpCharacterProxy_getShapePhantom();
};
void __cdecl bhkCharacterProxy_RembhkRefs();
struct RefObjectCAC4B0
{
    void UpdateReference(bool bAdd);
    int unk00;
    int unk04;
    WorldObjectCAC4B0* m_pkHavokObject;
    WorldObjectCAC4B0* GetHavokObject()
    {
        return this ? m_pkHavokObject : 0;
    }
};
struct ShapeRefCAC4B0 : public RefObjectCAC4B0
{
    void bhkCharacterProxy_Link(bool bAdd);
};
class BufferOwnerC5E0
{
  public:
    void FreeBuffer(bool bFree);

    int unk00;
    int unk04;
    int unk08;
    void* pvContextData;
};
extern "C" int DAT_0126834c;
struct CAFBase
{
    virtual ~CAFBase();
};
struct FUN_00caff80 : CAFBase
{
    virtual ~FUN_00caff80();
    void bhkSerializable_Kill();
};
// FUN_00cb0aa0: allocator-backed string dup. Takes the source string in the
// caller's edi (private convention derived for this static noinline helper):
// length via FUN_00cb10d0 (+1 for the NUL), block allocated through the task
// memory router's allocator, contents filled by FUN_00cb1090.
extern "C" int __cdecl hkString_strLen(int);
extern "C" void* __cdecl AllocateWithHeader(void* allocator, unsigned int count);
extern "C" void __cdecl hkString_strCpy(void* block, int value);
static void* strDup(char* s);
void zz_probe_call(char* s);
struct Cb1b80Arr
{
    int* m_data;
    int m_flags;
    int m_uiItemCount;
    Cb1b80Arr* hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator_hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator(void* data, unsigned int size);
};
void __cdecl bhkCollisionObject_SaveBinary(void);
void __cdecl bhkSPCollisionObject_SaveBinary(void);
extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_010c8914;
extern int DAT_01268118;
extern int DAT_01268154;
struct S00cb84f0_Obj : FUN_00c87c30
{
    int unk0c;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    S00cb84f0_Obj()
    {
        *(void**)this = (void*)&DAT_0102016c;
        unk0c = 0;
        DAT_01268154 += 1;
        *(void**)this = (void*)&DAT_0102009c;
        DAT_01268118 += 1;
        *(void**)this = (void*)&DAT_010c8914;
    }
};
void* __cdecl bhkOrientHingedBodyAction_CreateObject();
void __cdecl FUN_00a6d290(void);
struct FUN_00aa4060_Class
{
    void __thiscall MemoryManager_Deallocate(void* p);
};
struct FUN_00cb9260_Class
{
    int __thiscall FUN_00cb9260(unsigned char flags);
};
extern "C" void __cdecl CopyMembers_00a7b330();
void __cdecl bhkRagdollTemplate_CopyMembers();
struct FUN_00cbadb0_Dispatch
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
};
struct FUN_00cbadb0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
    virtual ~FUN_00cbadb0_Obj();

    void* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void ReleaseItems(void* items, unsigned int count);
};
extern int DAT_010c8d28;
struct FUN_00cbaec0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* data);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;
    void __thiscall ReleaseItems(void* data, unsigned int size);
    FUN_00cbaec0_Obj* __thiscall ReleaseAndDestroy(unsigned char flags);
};
struct ArrayCBAF90
{
    virtual __forceinline ~ArrayCBAF90()
    {
        RemoveAll();
    }
    virtual void v04();
    virtual void Deallocate(void* pvBase);
    void ReleaseItems(void* pvBase, unsigned int ItemUpdateArray);
    __forceinline void RemoveAll()
    {
        if (m_pBase)
        {
            ReleaseItems(m_pBase, m_uiSize);
            Deallocate(m_pBase);
            m_pBase = 0;
            m_uiAllocated = 0;
            m_uiSize = 0;
        }
    }
    void* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiAllocated;
};
struct ObjectCBAF90
{
    virtual ~ObjectCBAF90();
    int unk04;
    int unk08;
};
struct FUN_00cbaf90 : public ObjectCBAF90
{
    virtual ~FUN_00cbaf90();
    ArrayCBAF90 m_kArray;
};
struct CBB050Array
{
    void BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int count, bool enabled);
};
struct CBB050Object
{
    int unk00;
    int unk04;
    int unk08;
    CBB050Array array;
    void FUN_00a7b4a0(ReadStream* stream);
    void bhkRagdollTemplate_LoadBinary(ReadStream* stream);
};
void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_011f49e0;
struct FUN_00cbaf20_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    FUN_00cbaf20_class();
    void AssignFixedString(const NiFixedString& name);
};
FUN_00cbaf20_class* CreateNamedObject();
struct FUN_00cbf540_class
{
    void __thiscall CreateObjects(int* a, int b);
};
struct FUN_00cbf6b0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall EnsureObjectsCreated(int v);
};
extern int(__stdcall* DAT_00fdf1d0)();
extern int DAT_010c925c;
struct FUN_00cbf6e0_cls
{
    void* m_ppVirtualMethodTable;
    FUN_00cbf6e0_cls* FUN_00cbf6e0(unsigned int flags);
};
struct FUN_00ca5620
{
    unsigned int m_00;
    NiPointer<NiRefObject> m_pReferencedObject;
    ~FUN_00ca5620();
};
#include <math.h>
class BufferC520
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return GetHavokHeap(*(&hkMemoryRouter::getInstance())).blockAlloc(uiSize);
    }
    BufferC520() throw()
    {
        Init();
    }
    void Init() throw();
    int m_aiData0;
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
};
class ConsumerC520
{
  public:
    void SetBuffer(BufferC520* pkBuffer);
};
class BufferOwnerC520
{
  public:
    BufferC520* GetBuffer(bool* pbCreated);

    int unk00;
    int unk04;
    ConsumerC520* m_pkConsumer;
    BufferC520* m_pCacheEntry;
};
// FUN_00cac980: __thiscall getter, 4 bytes: mov eax,[ecx+0x30]; ret
// Original index entry spans 0xcac980..0xcac993 (20 bytes): this 4-byte getter,
// 12 bytes of int3 COMDAT pad, then a byte-identical anonymous twin getter at
// 0xcac990 (mov eax,[ecx+0x30]; ret) that the pack does not index.
// Twin drafted below so a re-indexer has the neighbor shape.
struct FUN_00cac980_class
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
    void* m_30;
    void* hkpCharacterProxy_getShapePhantom();
};
struct CAC980_Twin_class
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
    void* m_30;
    void* TwinGet();
};
void* CAC980_Twin_class::TwinGet()
{
    return m_30;
}
struct GetterCAC990
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
    int m_30;
    int Get();
};
struct S00cafef0_Elem
{
    int e0;
    int e4;
    float ez;
};
struct S00cafef0_Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    float m_18;
    float m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    S00cafef0_Elem* m_30;
    float m_34;
    void UpdateBoundsFromElements();
};
#ifndef _INCLUDED_MM2
// Exe 0x00cb2ca0 quaternion_simd: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#endif
extern const LocalM128 DAT_01267e30;
extern float DAT_01016248;
extern float DAT_0101e2bc;
extern __declspec(thread) int DAT_012722b4;
struct S00cb87e0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LocalM128 v10;
    LocalM128 v20;
    volatile float f30;
    float f34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __forceinline S00cb87e0_Node()
    {
        f30 = DAT_01016248;
        unk00 = 0;
        unk04 = 0;
        v10 = DAT_01267e30;
        v20 = DAT_01267e30;
        f34 = DAT_0101e2bc;
    }
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((MemoryManager_t*)&DAT_011f6238)->Game_DoHeapAlloc(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
    void operator delete(void*) throw()
    {}
};
struct S00cb87e0_Guard
{
    int m_saved;
    S00cb87e0_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cb87e0_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};
struct S00cb87e0_Obj
{
    int unk00;
    int unk04;
    int m_08;
    S00cb87e0_Node* m_0c;
    void bhkOrientHingedBodyAction_CopyCinfo(S00cb87e0_Node* p);
    void* GetNode(bool* out);
};
extern int DAT_010c81ac;
struct SpawnMidBase : FUN_00c87c30
{
    InitializedField unk0c;
    SpawnMidBase()
    {
        vtable = &DAT_0108febc;
        ++DAT_01268188;
    }
};
struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char* source);
    void SpawnAndAttach(char* source);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);
class CbaItem
{
  public:
    virtual ~CbaItem();
};
// Gamebryo-style array whose storage is released through its own virtual Free.
template <class T> class CbaArray
{
  public:
    virtual ~CbaArray()
    {
        RemoveAll();
    }
    virtual void* Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void* pvMem);

    void RemoveAll()
    {
        if (m_pBase)
        {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }

    unsigned int GetSize() const
    {
        return m_uiSize;
    }
    T& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
};
class CbaString
{
  public:
    ~CbaString()
    {
        if (m_pcString != DAT_0109b220)
            InterlockedDecrement((long*)((char*)m_pcString - 8));
    }
    void* m_pcString;
};
class CbaBase
{
  public:
    virtual ~CbaBase();  // FUN_00a5d3d0
    unsigned int unk04;
};
class FUN_00cba1d0 : public CbaBase
{
  public:
    virtual ~FUN_00cba1d0();

    CbaString m_kName;
    CbaArray<CbaItem*> m_kUnsortedGeometryList;
    CbaArray<void*> m_kOther;
};
void __cdecl Object_DoNothing_00cbb920();
extern int DAT_0126841c;
struct CB920Entry
{
    void* m_uiFilterValue;
    CB920Entry* m_pNext;

    void Remove(void*& item);
    void Cleanup();
};
struct CB920Map
{
    void GetAt(void* key, void** out) const;
    void RemoveAt(void* key);
};
extern CB920Map DAT_011b2190;
struct CB920Base
{
    virtual ~CB920Base();
};
static void CB920SetTag(int aiAllocationTag)
{
    g_tlsBlock.m_2b4 = aiAllocationTag;
}
struct CB920Guard
{
    int m_saved;

    CB920Guard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    void Leave()
    {
        CB920SetTag(m_saved);
    }

    ~CB920Guard()
    {
        Leave();
    }
};
struct FUN_00cbc920 : CB920Base
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* m_name;

    void Cleanup();
    virtual ~FUN_00cbc920();
};
struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
};
struct ChainSource
{
    LocalM128 m_00;
    LocalM128 m_10;
    ChainNode* m_20;
    ChainNode* m_24;
};
struct ChainDest
{
    LocalM128 m_00;
    LocalM128 m_10;
    ChainNode* m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    ChainNode* m_48;
    int m_4c;
    int m_50[1];
};
static void setHit(ChainSource* src, ChainDest* dst);
void __cdecl InsertIntoContext(void* pList, void* pContext);
void __cdecl Runtime_DoNothing_00cbf190();
float __cdecl hkMath_hkFloor(float value);
extern double DAT_010c9300;
extern double DAT_010c92f8;
extern double DAT_010c92f0;
extern double DAT_01030f38;
extern double DAT_0101ff40;
float __cdecl Atan2(float x, float y);
extern int DAT_010c771c;
extern int g_fnvDecompCounter;
struct ScopeHost_cls
{
    void* m_vptr;
    void bhkSerializable_Kill();
    void FUN_00cd2de0();
    void ProcessState_00ca6590();
};
struct OwnerGuard_cls
{
    ScopeHost_cls* m_pOwnerObject;
    OwnerGuard_cls(ScopeHost_cls* owner)
    {
        m_pOwnerObject = owner;
        owner->m_vptr = &DAT_010c771c;
    }
    ~OwnerGuard_cls()
    {
        m_pOwnerObject->FUN_00cd2de0();
    }
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00ca6780_sub
{
    unsigned int unk00;
    int m_04;
    int(__cdecl* m_08)(void* a, volatile unsigned int* b, unsigned int c, unsigned int d, unsigned int e);
};
struct FUN_00ca6780_arg
{
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
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned short unk1E6;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00ca6780_sub* m_24c;
};
struct FUN_00ca6780_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual int v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* v2D(unsigned char* out);
    int bhkNiTriStripsShape_LoadCInfo(FUN_00ca6780_arg* a1);
};
struct BlockData
{
    LocalM128 position;
    LocalM128 rotation;
};
struct QueueCA8960
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
    void __thiscall hkpWorld_queueOperation(hkMonitorStream::Command* cmd);
};
struct FUN_00ca8960_Class
{
    int unk00;
    int unk04;
    QueueCA8960* queue08;
    void __thiscall hkpRigidBody_setPositionAndRotation(const LocalM128* position, const LocalM128* rotation);
    void EnqueueTransform(const LocalM128* position, const LocalM128* rotation);
};
// Adjustor thunk for FUN_00cabf40: sub ecx,0xc; jmp FUN_00cac120.
// Primary base sized 12 (vptr + 8 pad) so the secondary->primary
// this adjustment is exactly 0xc.
struct Prim_00cabf40
{
    virtual void AdjustThisAndForward_00cabf40();
    int m04;
    int m08;
};
struct Sec_00cabf40
{
    virtual void AdjustThisAndForward_00cabf40();
};
struct TO_00cabf40 : Prim_00cabf40, Sec_00cabf40
{
// @fnv 0x00cabf40
// src: GUESS 0x00cabf40 (confidence: low)
    virtual void AdjustThisAndForward_00cabf40();
};
// Forces vtable emission: the override lands in both the primary and the
// secondary vftable, so VC9 emits [thunk]:TO_00cabf40::FUN_00cabf40
// 'adjustor{12}' = sub ecx,0xc ; jmp TO_00cabf40::FUN_00cabf40.
static TO_00cabf40 g_thunk_00cabf40;
struct CAC410_TLSState
{
    char m_ucUnknownByte[0x2B4];
    int m_uiFilterValue;
};
__declspec(thread) CAC410_TLSState g_CAC410_TLSState;
struct CAC410_RefCounted
{
    virtual void Dummy();
    virtual void Release();
};
struct FUN_00cac980_Result
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    CAC410_RefCounted* m_iThirdValue;
};
struct CAC410_ScopedValue
{
    int m_oldValue;

    CAC410_ScopedValue() : m_oldValue(g_CAC410_TLSState.m_uiFilterValue)
    {
        g_CAC410_TLSState.m_uiFilterValue = 0x10;
    }

    ~CAC410_ScopedValue()
    {
        g_CAC410_TLSState.m_uiFilterValue = m_oldValue;
    }
};
void __fastcall bhkCharacterProxy_RembhkRefs(void* pThis);
extern int DAT_01268358;
void CB0Free(void* p);
int CB0Len(const char* s);
struct CB0StringPtr
{
    int m_pcText;
    CB0StringPtr(const CB0StringPtr& other);
    const char* cString() const
    {
        return (const char*)(m_pcText & ~1);
    }
};
struct CB0SelfRef
{
    CB0StringPtr* p;
};
static void assign_00cb0b10(CB0SelfRef selfRef, const char* s, int len);
struct CC3320Info
{
    unsigned int unk00, unk04, unk08, unk0c;
    LocalM128 vec10, vec20;
    float out30, out34;
};
struct CC3320Source
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    LocalM128 vec20, vec30;
    unsigned int unk40, unk44, unk48, unk4c;
    float value50, value54;
};
struct CC3320Base
{
    int unk00;
    void __thiscall GetInfo(CC3320Info* info);
};
struct FUN_00cb84a0_cls : CC3320Base
{
    int unk04;
    CC3320Source* src08;
    void bhkOrientHingedBodyAction_CopyCinfo(CC3320Info* info);
};
struct S00cb8590_Out
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
};
struct S00cb8590_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk1e0;
    unsigned char unk1e4;
    unsigned char unk1e5;
};
void __stdcall bhkUnaryAction_LoadBinary(S00cb8590_Obj* p);
struct S00cb8590_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual S00cb8590_Out* vfn2d(S00cb8590_Obj** pp)
    {
        return 0;
    }
    void bhkOrientHingedBodyAction_LoadBinary(int a0);
};
static __forceinline void S00cb8590_swapAll(S00cb8590_Out* p)
{
    p->unk10 = _byteswap_ulong(p->unk10);
    _ReadWriteBarrier();
    p->unk14 = _byteswap_ulong(p->unk14);
    _ReadWriteBarrier();
    p->unk18 = _byteswap_ulong(p->unk18);
    _ReadWriteBarrier();
    p->unk1c = _byteswap_ulong(p->unk1c);
    _ReadWriteBarrier();
    p->unk20 = _byteswap_ulong(p->unk20);
    _ReadWriteBarrier();
    p->unk24 = _byteswap_ulong(p->unk24);
    _ReadWriteBarrier();
    p->unk28 = _byteswap_ulong(p->unk28);
    _ReadWriteBarrier();
    p->unk2c = _byteswap_ulong(p->unk2c);
    _ReadWriteBarrier();
    p->unk30 = _byteswap_ulong(p->unk30);
    _ReadWriteBarrier();
    p->unk34 = _byteswap_ulong(p->unk34);
    _ReadWriteBarrier();
}
struct FUN_00c868b0_Obj
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
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
};
struct FUN_00cb8610_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}

    virtual void bhkOrientHingedBodyAction_SaveBinary(void* arg);

    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}

    virtual FUN_00c868b0_Obj* vfB4(unsigned char* value);

    void bhkUnaryAction_SaveBinary(void* arg);
};
// bhkRagdollTemplate::bhkRagdollTemplate @ 0xcbaf20 (84 bytes)
// ctor: NiExtraData base ctor (0xa7b2e0), derived vftable (0x10c8dcc), then member
// BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> (vftable 0x10c8d28 + three
// zero stores) constructed inline; returns this.
// The original carries a dead /GS+EH unwind-only registration frame (FuncInfo
// optimizer folded away, and the c1 EH scope (unwind funclet destroys the base
// subobject) survived as stale weight.
// base NiExtraData: named after its ctor's address so the implicit base-ctor
// call binds to 0xa7b2e0
struct FUN_00a7b2e0
{
    virtual void v0();
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a7b2e0();
    ~FUN_00a7b2e0();
};
struct AryType
{  // BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> stand-in
    virtual void v0();
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
    AryType();
};
class FUN_00cbaf20 : public FUN_00a7b2e0
{
  public:
    AryType m_data;
    FUN_00cbaf20();
};
AryType::AryType()
{
    if (0)
        throw 1;
    m_pData = 0;
    m_uiSize = 0;
    m_uiMaxSize = 0;
}
struct SearchNodeCB
{
    int unk00;
    unsigned int id;
    int unk08;
    SearchNodeCB* parent;
};
struct InputCB
{
    LocalM128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* first;
    SearchNodeCB* second;
};
struct OutputCB
{
    LocalM128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* firstRoot;
    unsigned int firstId;
    int unk28_0;
    int unk28_1;
    int unk28_2;
    int unk28_3;
    int unk28_4;
    int unk28_5;
    int unk28_6;
    int unk28_7;
    SearchNodeCB* secondRoot;
    unsigned int secondId;
    unsigned int secondPath[8];
};
struct ContextCB
{
    int unk00;
    float limit;
    OutputCB* begin;
    OutputCB* next;
    int capacity;
    int size;
};
static __declspec(noinline) void CopyCB(OutputCB* dest, const InputCB* src)
{
    dest->point = src->point;
    *(LocalM128*)&dest->x = *(LocalM128 const*)&src->x;
    SearchNodeCB* c = src->first;
    while (c->parent)
        c = c->parent;
    dest->firstRoot = c;
    c = src->second;
    while (c->parent)
        c = c->parent;
    dest->secondRoot = c;
    dest->firstId = src->first->id;
    dest->secondId = src->second->id;
    SearchNodeCB* h = src->second;
    int count = 0;
    SearchNodeCB* n = h->parent;
    while (n)
    {
        n = n->parent;
        ++count;
    }
    dest->secondPath[count] = 0xffffffff;
    int i = count - 1;
    while (i >= 0)
    {
        dest->secondPath[i] = h->id;
        h = h->parent;
        --i;
    }
}
void __cdecl InsertIntoContext(const InputCB* input, ContextCB* context);
struct FUN_00cbda30_io;
struct FUN_00cbda30_io
{
    unsigned int unk00;
    unsigned int m04;
    unsigned int(__cdecl* m08)(FUN_00cbda30_io*, void*, unsigned int, unsigned int, unsigned int);
};
struct FUN_00cbda30_arg
{
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
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
    char unk1E6;
    char unk1E7;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00cbda30_io* m24C;
};
struct FUN_00cbda30_rec
{
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
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};
struct FUN_00cbda30_cls
{
    virtual void v00()
    {}
    FUN_00cbda30_rec* m04;
    void hkConstraintCinfo_LoadBinary(FUN_00cbda30_arg* a);
    void ReadRecord(FUN_00cbda30_arg* a1);
};
void SwapEndianBlocks(void* p);
extern "C" void _ReadWriteBarrier(void);
unsigned int* __cdecl SwapEndianBlocks(unsigned int* arg);
struct CA3F10MemMgr
{
    void* Allocate(unsigned int size);
};
extern CA3F10MemMgr g_kCA3F10MemMgr;
struct CA3F10BinaryStream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CA3F10BinaryStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};
struct CA3F10Stream
{
    void* unk00;
    unsigned int m_uiFormatVersion;
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
    int unk244;
    int unk248;
    CA3F10BinaryStream* m_pUnderlyingStream;
};
template <class T> inline unsigned int CA3F10LoadBinary(CA3F10BinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}
extern unsigned int DAT_011b1750[];
extern unsigned int DAT_011b1754[];
struct CA3F10Triangle
{
    unsigned int uiVerts01;
    unsigned int uiVert2Welding;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};
struct CA3F10OldTriangle
{
    CA3F10Triangle kTri;
    float f08;
    float f0c;
    float f10;
};
struct CA3F10Vertex
{
    float x;
    float y;
    float z;
    CA3F10Vertex()
    {}
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};
struct CA3F10Normal
{
    float x;
    float y;
    float z;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};
struct CA3F10Data
{
    int unk00;
    int unk04;
    unsigned int m_uiTriangles;
    unsigned int m_uiVertices;
    unsigned short m_usNormals;
    unsigned short unk12;
    CA3F10Triangle* m_pkTriangles;
    CA3F10Vertex* m_pkVertices;
    int unk1c;
    int unk20;
    CA3F10Normal* m_pkNormals;

    void hkPackedNiTriStripsData_LoadBinary(CA3F10Stream* pkStream);
};
extern "C" int DAT_010c82ec;
struct Rec9bd0;
struct Sub9bd0
{
    int v;
    void hkpBridgeConstraintAtom_init(Rec9bd0*);
};
struct Item9bd0
{
    void FUN_00c905b0();
};
struct Rec9bd0
{
    void* vt;
    unsigned short cap, fl;
    int pad[2];
    Sub9bd0 sub;
    int pad2[2];
    float score;
    void UpdateFields_00ca9b40(Item9bd0*);
    void FUN_00ca9aa0();
    static void* operator new(unsigned int size)
    {
        Rec9bd0* m = (Rec9bd0*)GetHavokHeap(*(&hkMemoryRouter::getInstance())).blockAlloc(size);
        m->cap = (unsigned short)size;
        return m;
    }
    static void operator delete(void*);
    Rec9bd0()
    {
        FUN_00ca9aa0();
        vt = &DAT_010c82ec;
    }
};
struct Ctx9bd0
{
    int a, b, c;
    void* coll;
    int d[3];
    float score;
};
extern "C" Item9bd0* __cdecl CreateF4A30Result(void* c, int k);
struct Key9bd0
{
    int value;
};
struct Owner9bd0
{
    int u;
    Ctx9bd0* ctx;
    void ReleaseObject(Rec9bd0*, int);
    void hkMalleableConstraintCinfo_CloneData(Rec9bd0* r, Key9bd0 key);
};
extern "C" void _ReadWriteBarrier();
// 0x00cabcd0  340 B  /MT /O2 /GS /EHsc /Gy  - HSV ramp helper.
extern double FUN_00ec6940(double);
struct ColorOutput
{
    float* value;
};
static void HsvToRgb(float* pR, float h, float s, float v, float* pG, float* out1);
void CallerHsv9(float* a, float h, float s, float v, float* r, float* g);
static inline float hkFloor(float x)
{
    return (float)floor((double)x);
}
static __declspec(noinline) void S00cabcd0_HSV(float* b, float h, float s, float v, float* g, float* r)
{
    float* const* pb = &b;
    volatile float* vp = b;
    (void)vp;
    (void)pb;
    int i;
    float f, p, q, t;
    if (s == 0.0f)
    {
        *r = *g = *b = v;
        return;
    }
    if (h == 1.0f)
    {
        i = 5;
        h = 6.0f;
    }
    else
    {
        h = h * 6.0;
        i = (int)hkFloor(h);
    }
    f = h - i;
    p = v * (1.0f - s);
    q = v * (1.0f - s * f);
    t = v * (1.0f - s * (1.0f - f));
    switch (i)
    {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    default:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}
unsigned int __cdecl Runtime_EvaluateValue_00cabe30(float h, float s, float v, float a);
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" void _ReadWriteBarrier();
void __cdecl hkMemoryRouter_easyFree(void*, void*);
extern "C" void __cdecl CopyIfNonEmpty(void*, int, int);
extern int DAT_01268358;
// src: HAVOK_LIB 0x00cb0ad0
static __declspec(noinline) void* strNdup(char* s, int maxLen)
{
    int len = hkString_strLen((int)s);
    if (len > maxLen)
        len = maxLen;
    char* p = (char*)AllocateWithHeader(&GetHavokHeap(*(&hkMemoryRouter::getInstance())), len + 1);
    CopyIfNonEmpty(p, (int)s, len);
    p[len] = 0;
    return p;
}
struct StringSlot
{
    unsigned int* volatile p;
};
static void assign_00cb0b10(StringSlot slotRef, char* s, int len);
void StringSetCaller(unsigned int* slot, char* s, int len);
struct S_ca4520_Entry
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
    unsigned short count;
    unsigned short unk46;
    unsigned short* runs;
    unsigned short* lists;
    unsigned short GetCount() const
    {
        return count;
    }
    unsigned short* GetLengths() const
    {
        return runs;
    }
    unsigned short GetVertices() const
    {
        return (unsigned short)unk08;
    }
    unsigned short* FUN_00a75f10();
};
struct S_ca4520_Slot
{
    NiPointer<S_ca4520_Entry> entry;
    int unk04;
};
struct S_ca4520
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
    S_ca4520_Slot* slots;
    S_ca4520_Slot& GetPart(unsigned int n) const
    {
        return slots[n];
    }
    S_ca4520_Entry* GetData(unsigned int n) const
    {
        return GetPart(n).entry;
    }
    bool IsDegenerate(unsigned int key) const;
};
union HandleKey
{
    unsigned int raw;
    struct
    {
        unsigned int index : 20;
        unsigned int slot : 12;
    };
};
static volatile int g_helperSink;
// src: HAVOK_LIB 0x00cb0b10
__declspec(noinline) static int assign_00cb0b10(int a, int b, int c)
{
    g_helperSink = a + b + c;
    return g_helperSink;
}
void __fastcall Object_UpdateFields_00cb0c00(int p);
struct SStringPtr
{
    void* UpdateState_00cb0c10(const char* s);
};
struct SelfRef
{
    void* p;
};
static int g_sink;
// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (int)s + len;
    *(int*)self.p = g_sink;
}
struct Cb0StringCopy
{
    int m_pcText;
    Cb0StringCopy* UpdateState_00cb0c30(const CB0StringPtr& other);
};
template <typename KEY> struct MapOps
{
    static __forceinline unsigned hash(KEY key, unsigned mod)
    {
        return unsigned((unsigned long)(key) >> 4) * 2654435761U & mod;
    }
    static __forceinline int isValid(KEY key)
    {
        return key != KEY(-1);
    }
    static __forceinline int equal(KEY key0, KEY key1)
    {
        return key0 == key1;
    }
};
extern int DAT_010c7600;
extern float DAT_010c72c0;
struct ExtraArray
{
    ~ExtraArray()
    {
        _NiFree_00aa10f0(m_pBase);
    }
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    unsigned int unk08, m_uiESize, m_uiCount, growBy;
    ExtraArray(unsigned int n = 0, unsigned int g = 1)
    {
        unk08 = n;
        growBy = g;
        m_uiESize = 0;
        m_uiCount = 0;
        m_pBase = 0;
        unk00 = (int)&DAT_010c7600;
    }
    __declspec(noinline) void Resize(unsigned int capacity)
    {
        if (capacity == unk08)
            return;
        if (capacity < m_uiESize)
        {
            for (unsigned int i = capacity; i < m_uiESize; ++i)
            {
                if (m_pBase[i] != S_00ca49a0_Elem(0))
                {
                    m_pBase[i] = S_00ca49a0_Elem(0);
                    --m_uiCount;
                }
            }
            m_uiESize = capacity;
        }
        S_00ca49a0_Elem* old = m_pBase;
        unk08 = capacity;
        if (capacity)
        {
            m_pBase = (S_00ca49a0_Elem*)Object_DispatchCommandFour(capacity * sizeof(S_00ca49a0_Elem));
            for (unsigned int i = 0; i < m_uiESize; ++i)
                m_pBase[i] = old[i];
            for (unsigned int i = m_uiESize; i < unk08; ++i)
                m_pBase[i] = S_00ca49a0_Elem(0);
        }
        else
            m_pBase = 0;
        _NiFree_00aa10f0(old);
    }
    void ClearRecords();
// src: XBOX_PDB 0x00ca49a0
    __declspec(noinline) void NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= m_uiESize)
        {
            m_uiESize = i + 1;
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else if (m_pBase[i] == S_00ca49a0_Elem(0))
        {
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else
        {
            if (e == S_00ca49a0_Elem(0))
                --m_uiCount;
        }
        m_pBase[i] = e;
    }
    const S_00ca49a0_Elem& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    unsigned int Add(const S_00ca49a0_Elem& e)
    {
        return SetAtGrow(m_uiESize, e);
    }
    unsigned int SetAtGrow(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= unk08)
            Resize(i + growBy);
        NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(i, e);
        return i;
    }
};
inline void CopyEntry(ExtraArray& out, int i, const ExtraArray& source);
struct SavedExtraArray : ExtraArray
{
    SavedExtraArray() : ExtraArray()
    {}
};
struct SerializedExtraBody
{
    unsigned int unk00;
    float scale;
    ExtraArray entries;
    unsigned int value20, value24, value28, value2c;
    static void Swap4(void* p)
    {
        *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
    }
    void Swap()
    {
        Swap4(&scale);
        Swap4(&value20);
        Swap4(&value24);
        Swap4(&value28);
        Swap4(&value2c);
    }
};
struct ExtraSerializer
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
    virtual void Restore(int token);
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual SerializedExtraBody* Acquire(int* token);
    void bhkShape_SaveBinary(S_00ca59d0_Stream* stream);
    void bhkNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* stream);
};
inline void SaveR(S_00ca59d0_Bin& bin, const unsigned int* p)
{
    unsigned int uiSize = 4;
    unsigned int written = bin.unk0C(&bin, p, 4, &uiSize, 1);
    bin.unk04 += written;
}
inline void SaveRV(S_00ca59d0_Bin& bin, unsigned int value)
{
    SaveR(bin, &value);
}
extern int DAT_0102009c;
extern int DAT_01268154;
extern int DAT_01268118;
struct cb86f0_obj : bhkRefObject
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;

    cb86f0_obj()
    {
        Initialize();
        vtable = (void*)0x102016c;
        const int inc = 1;
        unk0c = 0;
        DAT_01268154 += inc;
        vtable = (void*)&DAT_0102009c;
        DAT_01268118 += inc;
        vtable = (void*)0x10c8914;
    }

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
struct FUN_00cb86f0_class
{
    virtual void v0();
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
    virtual void v50(void* obj, int param);
    cb86f0_obj* bhkOrientHingedBodyAction_CreateClone(int a1);
};
class RagdollRaycastCleanup
{
  public:
    void* m_vtbl;
    void SetVtbl();
};
struct S_ca5870_Obj
{
    S_ca5870_Obj(void* arg);
    int unk00;
    unsigned short m_04;
    unsigned short unk06;
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
    void FUN_00c905b0();

    static void* operator new(unsigned int size) throw()
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        void* p = GetHavokHeap(*h).blockAlloc(size);
        ((S_ca5870_Obj*)p)->m_04 = (unsigned short)size;
        return p;
    }
};
struct S_ca5870
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void SlotA(S_ca5870_Obj* obj);
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9C();
    virtual void unkA0();
    virtual void unkA4();
    virtual void unkA8();
    virtual void unkAC();
    virtual void unkB0();
    virtual void unkB4();
    virtual void unkB8();
    virtual void SlotB(void* arg);
    void bhkPackedNiTriStripsShape_Init(void* arg);
};
extern "C" void __cdecl _ReadWriteBarrier(void);
struct FUN_00cb1130_class
{
    static char* hkString_strStr(const char* str, const char* substr);
};
template <typename T> hkBool hkString_findAllOccurrences(const char* str, const char* substr, hkArray<int>& indices, int findAll);
struct S_Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    LocalM128 unk20;
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
    float unk58;
    int unk5c;
    int unk60;
};
struct S_D26450
{
    S_Source* hkpTriSampledHeightFieldCollection_getHeightFieldShape();
};
struct S_00cb0030_Obj : S_00ca4e10_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_D26450* unk18;
};
struct S_00cb0030_Out : S_00ca4e10_Out
{
    int unk08;
    int unk0c;
    LocalM128 unk10;
    int unk20;
    int unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
};
struct S_00cb0030_Cls : S_00ca4e10_Cls
{
    void bhkBvTreeShape_CopyCinfo(S_00cb0030_Out* out);
    void UpdateState_00cb0030(S_00cb0030_Out* out);
};

namespace fnv_00ca0b70 {
struct World;

struct WorldObject
{
    int unk00;
    int unk04;
    World* m_pOwningWorld;
};

struct Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char m_iOwnerOffset;
    WorldObject* getOwner() const
    {
        return (WorldObject*)((char*)this + m_iOwnerOffset);
    }
};

struct __declspec(align(16)) LocalEvent
{
    LocalM128 m_vComponents;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_a1;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    Collidable* m_a2;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct TargetClass
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c(LocalEvent& event);
};

struct Mgr
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
    TargetClass* m_target;
};

struct World
{
    int unk000[0xd4];
    Mgr* m_pManager;
};

// @fnv 0x00ca0b70
// src: XBOX_PDB 0x00ca0b70
void __stdcall bhkAcousticSpacePhantomCallbackShape_phantomEnterEvent(void* a1, Collidable* a2, void* a3)
{
    LocalEvent ev;
    ev.m_a1 = a1;
    ev.m_a2 = a2;

    World* world = a2->getOwner()->m_pOwningWorld;
    Mgr* mgr = world ? world->m_pManager : 0;
    mgr->m_target->v1c(ev);
}
}  // namespace fnv_00ca0b70

#include <xmmintrin.h>

extern LocalM128 DAT_010ec7f0;

struct RayScalar_rc1c
{
    LocalM128 value;
    RayScalar_rc1c(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};

struct hkVector4_rc1c
{
    LocalM128 m_vComponents;
    hkVector4_rc1c()
    {}
    __forceinline void operator=(const hkVector4_rc1c& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkVector4_rc1c(const hkVector4_rc1c& v) : m_vComponents(v.m_vComponents)
    {}
    void setInterpolate4(const hkVector4_rc1c& a, const hkVector4_rc1c& b, const RayScalar_rc1c& t)
    {
        LocalM128 tt = t.broadcast();
        LocalM128 s = _mm_sub_ps(DAT_010ec7f0, tt);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, a.m_vComponents), _mm_mul_ps(tt, b.m_vComponents));
    }
};

struct hkpCollidable_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_iOwnerOffset;
    char unk11;
    short unk12;
    int unk14;
    unsigned char m_type;
    char unk19;
    short unk1a;
    unsigned int m_uiCollisionFilterData;
    int getType() const
    {
        return m_type;
    }
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct hkpWorldObject_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkpCollidable_rc1c m_kCollidable;
    unsigned int GetFilterInfoForKey() const
    {
        return m_kCollidable.m_uiCollisionFilterData;
    }
};
inline const hkpWorldObject_rc1c* getBody(const hkpCollidable_rc1c* c)
{
    return c->getType() == 1 ? (const hkpWorldObject_rc1c*)c->getOwner() : 0;
}

struct hkpWorldRayCastOutput_rc1c
{
    hkVector4_rc1c m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
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
    const hkpCollidable_rc1c* m_pRootCollidable;
    int unk54;
    int unk58;
    int unk5c;
    __forceinline hkpWorldRayCastOutput_rc1c(const hkpWorldRayCastOutput_rc1c& o)
    {
        m_vHitNormal = o.m_vHitNormal;
        m_fHitFraction = o.m_fHitFraction;
        m_iExtraInfo = o.m_iExtraInfo;
        unk18 = o.unk18;
        unk1c = o.unk1c;
        unk20 = o.unk20;
        unk24 = o.unk24;
        unk28 = o.unk28;
        unk2c = o.unk2c;
        unk30 = o.unk30;
        unk34 = o.unk34;
        unk38 = o.unk38;
        unk3c = o.unk3c;
        unk40 = o.unk40;
        unk44 = o.unk44;
        unk48 = o.unk48;
        unk4c = o.unk4c;
        m_pRootCollidable = o.m_pRootCollidable;
        unk54 = o.unk54;
        unk58 = o.unk58;
        unk5c = o.unk5c;
    }
};

struct hkpWorldRayCastInput_rc1c
{
    hkVector4_rc1c m_vFrom;
    hkVector4_rc1c m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
    hkpWorldRayCastInput_rc1c() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct hkpRayHitCollector_rc1c
{
    float m_fEarlyOutHitFraction;
    virtual ~hkpRayHitCollector_rc1c();
};

struct hkpWorldRayCastOutputArray_rc1c
{
    hkpWorldRayCastOutput_rc1c* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkpWorldRayCastOutput_rc1c m_kStorage[8];
};

struct hkpAllRayHitCollector_rc1c : public hkpRayHitCollector_rc1c
{
    hkpWorldRayCastOutputArray_rc1c m_kHits;
    hkpAllRayHitCollector_rc1c();
    virtual ~hkpAllRayHitCollector_rc1c();
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
        m_kHits.m_iElementCount = 0;
    }
};

struct hkpWorld_rc1c
{
    void hkpAabbPhantom_castRay(const hkpWorldRayCastInput_rc1c& input, hkpAllRayHitCollector_rc1c& collector) const;
};

struct RayFilter_rc1c
{
    unsigned int bits;
    RayFilter_rc1c(unsigned int x) : bits(x)
    {}
    void AddObjectReference(unsigned int x)
    {
        bits &= 0xffff;
        bits |= x << 16;
    }
    void setLayer(unsigned int x)
    {
        bits &= ~0x7fu;
        bits |= x;
    }
    bool bip() const
    {
        unsigned int layer = bits & 0x7f;
        return layer == 8 || layer == 29;
    }
    operator unsigned int() const
    {
        return bits;
    }
};

struct RayCaster_rc1c
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_systemGroup;
    hkBool bhkRagdollPenetrationUtil_castRay(const hkpWorld_rc1c* world, const hkVector4_rc1c& from, const hkVector4_rc1c& to,
                        hkVector4_rc1c& pointOut, hkVector4_rc1c& normalOut);
};

// @fnv 0x00ca1c50
// src: XBOX_PDB 0x00ca1c50
hkBool RayCaster_rc1c::bhkRagdollPenetrationUtil_castRay(const hkpWorld_rc1c* world, const hkVector4_rc1c& from, const hkVector4_rc1c& to,
                                    hkVector4_rc1c& pointOut, hkVector4_rc1c& normalOut)
{
    bool found = false;
    hkpWorldRayCastInput_rc1c input;
    hkpAllRayHitCollector_rc1c collector;
    RayFilter_rc1c filter(0);
    filter.AddObjectReference(m_systemGroup);
    filter.setLayer(29);

    input.m_vFrom = from;
    input.m_vTo = to;
    input.m_uiFilterInfo = filter;
    collector.reset();
    world->hkpAabbPhantom_castRay(input, collector);
    for (int i = 0; i < collector.m_kHits.m_iElementCount && !found; i++)
    {
        hkpWorldRayCastOutput_rc1c hit = collector.m_kHits.m_data[i];
        const hkpWorldObject_rc1c* owner = getBody(hit.m_pRootCollidable);
        if (owner)
        {
            {
                RayFilter_rc1c hitFilter(owner->GetFilterInfoForKey());
                if (!hitFilter.bip())
                {
                    pointOut.setInterpolate4(input.m_vFrom, input.m_vTo, hit.m_fHitFraction);
                    normalOut = hit.m_vHitNormal;
                    found = true;
                }
            }
        }
    }

    if (!found)
    {
        input.m_vFrom = to;
        input.m_vTo = from;
        input.m_uiFilterInfo = filter;
        input.m_bEnableShapeCollectionFilter = true;
        collector.reset();
        world->hkpAabbPhantom_castRay(input, collector);
        for (int i = 0; i < collector.m_kHits.m_iElementCount && !found; i++)
        {
            hkpWorldRayCastOutput_rc1c hit = collector.m_kHits.m_data[i];
            const hkpWorldObject_rc1c* owner = getBody(hit.m_pRootCollidable);
            if (owner)
            {
                {
                    RayFilter_rc1c hitFilter(owner->GetFilterInfoForKey());
                    if (!hitFilter.bip())
                    {
                        pointOut.setInterpolate4(input.m_vFrom, input.m_vTo, hit.m_fHitFraction);
                        normalOut = hit.m_vHitNormal;
                        found = true;
                    }
                }
            }
        }
    }
    return found;
}

struct Ca35Owner;
struct Ca35Record
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
};
struct Ca35Entry
{
    unsigned short m_00;
    unsigned short unk02;
    unsigned int unk04;
};
struct Ca35Table
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int unk0c;
    unsigned int unk10;
    Ca35Entry* m_14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Ca35Record* m_24;
};
struct Ca35Owner
{
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
    Ca35Table* m_74;
    unsigned int hkPackedNiTriStripsShape_getNextKey(unsigned int a1);
};
// @fnv 0x00ca35d0
// src: COMMUNITY 0x00ca35d0
unsigned int Ca35Owner::hkPackedNiTriStripsShape_getNextKey(unsigned int a1)
{
    unsigned int type = a1 >> 24;
    unsigned int v = (a1 & 0xffffff) + 1;
    if (v >= m_74->m_08)
    {
        return 0xffffffff;
    }
    unsigned int sum = 0;
    for (int i = 0; i <= (int)type; ++i)
        sum += m_74->m_24[i].m_04;
    unsigned int w = m_74->m_14[v].m_00;
    if (w >= sum)
        ++type;
    return (v & 0xffffff) | (type << 24);
}

typedef union __declspec(intrin_type) _CRT_ALIGN(16) S00ca4120_Q
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
} S00ca4120_Q;
extern "C"
{
    ::LocalM128 _mm_min_ps(::LocalM128, ::LocalM128);
    ::LocalM128 _mm_max_ps(::LocalM128, ::LocalM128);
    ::LocalM128 _mm_mul_ps(::LocalM128, ::LocalM128);
    ::LocalM128 _mm_setr_ps(float, float, float, float);
}
extern float DAT_012682c8;
extern const float DAT_01011d78;
extern float DAT_0104da48;
extern const float DAT_0104e148;
struct S00ca4120_Vec
{
    S00ca4120_Q q;
    void set(float a, float b, float c, float d)
    {
        q.m128_f32[0] = a;
        q.m128_f32[1] = b;
        q.m128_f32[2] = c;
        q.m128_f32[3] = d;
    }
    void setMin4(const S00ca4120_Vec& a, const S00ca4120_Vec& b)
    {
        *(::LocalM128*)&q = (_mm_min_ps)(*(::LocalM128*)&a.q, *(::LocalM128*)&b.q);
    }
    void setMax4(const S00ca4120_Vec& a, const S00ca4120_Vec& b)
    {
        *(::LocalM128*)&q = (_mm_max_ps)(*(::LocalM128*)&a.q, *(::LocalM128*)&b.q);
    }
    void mul4(const S00ca4120_Vec& a)
    {
        *(::LocalM128*)&q = (_mm_mul_ps)(*(::LocalM128*)&q, *(::LocalM128*)&a.q);
    }
    void setTransformedPos_00c7f640(const struct S00ca4120_Xf* t, const S00ca4120_Vec* v);
};
struct S00ca4120_Xf
{
    S00ca4120_Vec c0, c1, c2, c3;
};
struct S00ca4120_Pt
{
    float x, y, z;
};
struct S00ca4120_Mesh
{
    unsigned int unk00, unk04;
    unsigned short count, unk0a;
    unsigned int unk0c, unk10, unk14, unk18, unk1c;
    S00ca4120_Pt* positions;
};
struct S00ca4120_Entry
{
    S00ca4120_Mesh* mesh;
    unsigned int unk04;
};
struct S00ca4120_Geom
{
    ::LocalM128 unk00, unk10;
    S00ca4120_Xf transform;
    S00ca4120_Vec minimum, maximum;
    S00ca4120_Vec scale;
    unsigned int unk90, unk94;
    S00ca4120_Entry* entries;
    unsigned int unk9c, count;
    void hkNiTriStripsShape_CalcWorldAabb(const S00ca4120_Xf* input);
};
// @fnv 0x00ca4120
// src: COMMUNITY 0x00ca4120
void S00ca4120_Geom::hkNiTriStripsShape_CalcWorldAabb(const S00ca4120_Xf* input)
{
    *(::LocalM128*)&transform.c0.q = *(::LocalM128 const*)&input->c0.q;
    *(::LocalM128*)&transform.c1.q = *(::LocalM128 const*)&input->c1.q;
    *(::LocalM128*)&transform.c2.q = *(::LocalM128 const*)&input->c2.q;
    *(::LocalM128*)&transform.c3.q = *(::LocalM128 const*)&input->c3.q;
    *(::LocalM128*)&minimum.q = (_mm_setr_ps)(3.40282e38F, 3.40282e38F, 3.40282e38F, 0.0f);
    *(::LocalM128*)&maximum.q = (_mm_setr_ps)(-3.40282e38F, -3.40282e38F, -3.40282e38F, 0.0f);
    unsigned int n = count;
    const S00ca4120_Vec& s = scale;
    for (unsigned int i = 0; i < n; ++i)
    {
        S00ca4120_Mesh* mesh = entries[i].mesh;
        S00ca4120_Pt* p = mesh->positions;
        unsigned int m = mesh->count;
        for (unsigned int j = 0; j < m; ++j)
        {
            S00ca4120_Vec pt;
            pt.set(p[j].x * DAT_012682c8, p[j].y * DAT_012682c8, p[j].z * DAT_012682c8, 0.0f);
            pt.mul4(s);
            S00ca4120_Vec r;
            r.setTransformedPos_00c7f640(input, &pt);
            minimum.setMin4(minimum, r);
            maximum.setMax4(maximum, r);
        }
    }
}

#include <xmmintrin.h>

extern const float DAT_01016410;
extern GlobalObjectO2_00a7b610 g_01267e64;

struct VelocityBody
{
    void hkpRigidBody_applyForce(float amount, const LocalM128* velocity);
};

struct VelocityHolder
{
    int unk00;
    int unk04;
    VelocityBody* body;
};

struct VelocityProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    VelocityHolder* holder;
    int unk14;
    float fraction;
};

struct DynCastHelper
{
    VelocityProperty* DynamicCast(const GlobalObjectO2_00a7b610* type);
};

struct VelocityNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DynCastHelper* property;
};

struct VelocityController
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
    VelocityNode* node;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    LocalM128 velocity;
    float amount;
    void bhkForceController_ApplyForce();
};

// @fnv 0x00cb9290
// src: XBOX_PDB 0x00cb9290
void VelocityController::bhkForceController_ApplyForce()
{
    if (node && node->property)
    {
        VelocityProperty* prop = node->property->DynamicCast(&g_01267e64);
        if (prop && prop->fraction < 1.0f)
        {
            VelocityHolder* holder = prop->holder;
            if (holder)
            {
                VelocityBody* body = holder->body;
                if (body)
                {
                    LocalM128 scalar = _mm_load_ss(&DAT_01016410);
                    LocalM128 factor = _mm_shuffle_ps(scalar, scalar, 0);
                    LocalM128 scaled = _mm_mul_ps(factor, velocity);
                    body->hkpRigidBody_applyForce(amount, &scaled);
                }
            }
        }
    }
}

#include <xmmintrin.h>
class NiRTTI;
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012683f4;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern double DAT_0101de30;
extern const float g_011c56fc_arg1;
extern float DAT_01015f5c;
extern float DAT_011b1d3c;
void __fastcall FUN_00a6d220(void* p);
struct MemoryManagerAllocHelper : MemoryManager
{
    void* Allocate(unsigned int size);
};
struct Aux2
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
    float f194;
};
struct Aux1
{
    void* m_iWordAt00;
    int unk04;
    void* unk08;
    float FUN_0062ab20();
};
extern int DAT_010c8a2c;
union Mem128
{
    LocalM128 v;
    struct
    {
        float x;
        float y;
        float z;
        float w;
    } components;
};
struct ForceControllerStorage : NiTimeController
{
    int unk34;
    int unk38;
    int unk3c;
    Mem128 m_40;
    float m_50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    void* operator new(unsigned int size) throw();
    void operator delete(void*)
    {}
    ForceControllerStorage();
};
void* ForceControllerStorage::operator new(unsigned int size) throw()
{
    char* p = (char*)((MemoryManagerAllocHelper*)&_g_memoryManager)->Allocate(size);
    unsigned char adj = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
    p += adj;
    p[-1] = (char)adj;
    return p;
}

ForceControllerStorage::ForceControllerStorage()
{
    *(void**)this = (void*)&DAT_010c8a2c;
    m_40.v = DAT_01267e30;
    m_50 = 0.0f;
}

// @fnv 0x00cb9320
// src: XBOX_PDB 0x00cb9320
void __cdecl bhkForceController_TestForce(NiAVObject* a1, const void* a2, NiAVObject* a3)
{
    NiAVObject* pObj = a3;
    if (pObj == 0)
        pObj = a1;
    NiTimeController* pCtl = pObj->GetController((const NiRTTI*)&g_012683f4);
    if (pCtl == 0)
    {
        pCtl = new ForceControllerStorage();
        pCtl->SetTarget(pObj);
    }
    NiObject* pUnk;
    if (pObj->m_spCollisionObject.m_pObject == 0)
        pUnk = 0;
    else
        pUnk = ((NiObject*)pObj->m_spCollisionObject.m_pObject)->DynamicCast((const void*)&g_012043f8);
    LocalM128 vec = _mm_load_ps((const float*)a2);
    if (pUnk != 0 && (*reinterpret_cast<Aux1**>(reinterpret_cast<char*>(pUnk) + 0x10)) != 0)
    {
        Aux1* pA1 = (Aux1*)(*reinterpret_cast<Aux1**>(reinterpret_cast<char*>(pUnk) + 0x10));
        float scale = pA1->FUN_0062ab20();
        scale = DAT_011b1d3c * scale;
        LocalM128 scalar = _mm_load_ss(&scale);
        LocalM128 t1 = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), vec);
        Aux2* pA2 = (Aux2*)((volatile Aux1*)pA1)->unk08;
        float bias = (float)(pA2->f194 * 0.75);
        LocalM128 tb = _mm_load_ss(&bias);
        vec = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(tb, tb, 0x00), t1), t1);
    }
    ForceControllerStorage* __restrict pT = (ForceControllerStorage*)pCtl;
    pT->m_fLoKeyTime = 0.0f;
    pT->m_fHiKeyTime = g_011c56fc_arg1;
    pT->m_uiObjectFlags = (unsigned short)((pT->m_uiObjectFlags & 0xfff5) | 5);
    pT->m_fPhase = 0.0f;
    pT->m_fFrequency = 1.0f;
    pT->m_40.v = vec;
    pCtl->Start(DAT_01015f5c);
}

#include <xmmintrin.h>

class CBD9E0V4
{
  public:
    LocalM128 m_vComponents;
    void mul(float s)
    {
        LocalM128 scalar = _mm_load_ss(&s);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), m_vComponents);
    }
};

struct FUN_00cbd9e0_cls
{
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
    CBD9E0V4 m_v50;
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
    CBD9E0V4 m_v90;
};

// @fnv 0x00cbd9e0
// src: COMMUNITY 0x00cbd9e0
void hkHingeConstraintCinfo_ApplyScale(float scale, FUN_00cbd9e0_cls* p)
{
    if (p == 0 || scale == 1.0f)
        return;
    p->m_v50.mul(scale);
    p->m_v90.mul(scale);
}

extern int DAT_010c91ec;

struct S00cbe7b0_Obj
{
    void* m_vtbl;
    unsigned short m_iWordAt04;
    unsigned short m_6;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    float m_18;
    float m_1c;
    ::LocalM128 q20;
    ::LocalM128 q30;
    ::LocalM128 q40;
    ::LocalM128 q50;
    ::LocalM128 q60;
    ::LocalM128 q70;
    ::LocalM128 q80;
    ::LocalM128 q90;
    unsigned char m_a0;
    unsigned char m_a1;
    unsigned char m_a2;
    S00cbe7b0_Obj* hkpHingeConstraintData_hkpHingeConstraintData();
};

// @fnv 0x00cbe7b0
// src: XBOX_PDB 0x00cbe7b0
S00cbe7b0_Obj* S00cbe7b0_Obj::hkpHingeConstraintData_hkpHingeConstraintData()
{
    m_6 = 1;
    m_8 = 0;
    m_vtbl = &DAT_010c91ec;
    reinterpret_cast< ::FUN_00cbe820_cls*>(reinterpret_cast<char*>(this) + 0x10)->hkpHingeConstraintData_Atoms_Atoms();
    ::LocalM128 z = (_mm_setzero_ps)();
    (_mm_store_ps)((float*)&q20, z);
    (_mm_store_ps)((float*)&q30, z);
    (_mm_store_ps)((float*)&q40, z);
    q20.m128_f32[0] = 1.0f;
    q30.m128_f32[1] = 1.0f;
    q40.m128_f32[2] = 1.0f;
    (_mm_store_ps)((float*)&q50, z);
    (_mm_store_ps)((float*)&q60, z);
    (_mm_store_ps)((float*)&q70, z);
    (_mm_store_ps)((float*)&q80, z);
    q60.m128_f32[0] = 1.0f;
    q70.m128_f32[1] = 1.0f;
    q80.m128_f32[2] = 1.0f;
    (_mm_store_ps)((float*)&q90, z);
    m_a2 = 0;
    return this;
}


static inline NiPoint3 Scale_00cbe8d0(NiPoint3 p, float fScalar)
{
    NiPoint3 kResult;
    kResult.x = p.x * fScalar;
    kResult.y = p.y * fScalar;
    kResult.z = p.z * fScalar;
    return kResult;
}

union BoundCenter
{
    ::LocalM128 m_vComponents;
    unsigned char m_bytes[16];
};

struct BoundView_00cbe8d0
{
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
};

struct BoundItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BoundView_00cbe8d0* m_pkBound;
};

struct BoundSource
{
    BoundItem* bhkWorldObject_GetAVObject(int iIndex);
};

class NodeView_00cbe8d0
{
  public:
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
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    BoundSource* m_pkSource;
    ::LocalM128* bhkCharacterProxy_GethkPosition();
};

struct Scaled
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};

struct BoundHolderBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct ScaledList
{
    Scaled* m_pkScaled;
};

struct ScaledHolder : public BoundHolderBase, public ScaledList
{
};

extern bool DAT_01268440;
extern float DAT_011b21e8;
extern float DAT_0126844c;
extern BoundView_00cbe8d0 DAT_011f4288;

class BoundOwner
{
  public:
    int unk00;
    int unk04;
    ScaledHolder* m_pkHolder;
    int unk0C;
    int unk10;
    int unk14;
    NodeView_00cbe8d0* m_pkNode;

    void Object_DoNothing();
    void bhkShapePhantom_setPositionNi(const ::NiPoint3* pkCenter);
    void bhkCollisionBox_Update();
};

// @fnv 0x00cbe8d0
// src: COMMUNITY 0x00cbe8d0
void BoundOwner::bhkCollisionBox_Update()
{
    if (DAT_01268440 || !m_pkNode)
        return;

    BoundCenter kTargetCenter;
    float fRadius;
    BoundSource* pkSource = m_pkNode->m_pkSource;
    BoundItem* pkItem;
    if (pkSource && (pkItem = pkSource->bhkWorldObject_GetAVObject(0)) != 0)
    {
        BoundView_00cbe8d0* __restrict source = pkItem->m_pkBound ? pkItem->m_pkBound : &DAT_011f4288;
        BoundView_00cbe8d0 kBound = *source;
        (*reinterpret_cast<NiPoint3*>(kTargetCenter.m_bytes)) = kBound.m_kCenter;
        fRadius = kBound.m_fBoundRadius;
    }
    else
    {
        kTargetCenter.m_vComponents = *m_pkNode->bhkCharacterProxy_GethkPosition();
        (*reinterpret_cast<NiPoint3*>(kTargetCenter.m_bytes)) = Scale_00cbe8d0((*reinterpret_cast<NiPoint3*>(kTargetCenter.m_bytes)), DAT_011b21e8);
        fRadius = 1.0f;
    }

    ScaledHolder* pkHolder = m_pkHolder;
    ScaledList* pkList = 0;
    if (pkHolder)
    {
        Object_DoNothing();
        pkList = (ScaledList*)pkHolder;
        Object_DoNothing();
    }
    Scaled* pkScaled = pkList ? pkList->m_pkScaled : 0;

    if (!(fRadius > 0.0f))
        fRadius = 1.0f;
    pkScaled->m_fScale = DAT_0126844c * fRadius;
    bhkShapePhantom_setPositionNi(reinterpret_cast<const ::NiPoint3*>(&kTargetCenter.m_bytes[0]));
}

namespace TriStripIntrinsics {
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(float const*);
}

static float DAT_012682c8;

union S00ca45b0_Vec
{
    LocalM128 m_vComponents;
    char m_bytes[16];
    void set(float x, float y, float z, float w)
    {
        float* f = m_vComponents.m128_f32;
        f[0] = x;
        f[1] = y;
        f[2] = z;
        f[3] = w;
    }
    void operator=(const S00ca45b0_Vec& o)
    {
        m_vComponents = o.m_vComponents;
    }
    void mul4(const S00ca45b0_Vec& o)
    {
        m_vComponents =
            TriStripIntrinsics::_mm_mul_ps(TriStripIntrinsics::_mm_load_ps(m_vComponents.m128_f32), o.m_vComponents);
    }
};

struct S00ca45b0_Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S00ca45b0_Vec m_v0;
    S00ca45b0_Vec m_v1;
    S00ca45b0_Vec m_v2;
};

struct S00ca45b0_Alloc
{
    S00ca45b0_Tri* FUN_00ca39a0(float r);
};

struct S00ca45b0_Chunk
{
    unsigned short* FUN_00a75f10();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float* m_verts;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned short m_numStrips;
    unsigned short unk46;
    unsigned short* m_pStripIndices;
};

struct S00ca45b0_Slot
{
    S00ca45b0_Chunk* m_pCurrentMemoryChunk;
    int unk04;
};

struct S00ca45b0_Shape
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
    S00ca45b0_Vec m_vScale;
    float m_fSphereRadius;
    int unk84;
    S00ca45b0_Slot* m_slots;

    S00ca45b0_Tri* hkNiTriStripsShape_getChildShape(unsigned int key, S00ca45b0_Alloc* alloc);
};

// @fnv 0x00ca45b0
// src: COMMUNITY 0x00ca45b0
S00ca45b0_Tri* S00ca45b0_Shape::hkNiTriStripsShape_getChildShape(unsigned int key, S00ca45b0_Alloc* alloc)
{
    S00ca45b0_Chunk* chunk = m_slots[key >> 20].m_pCurrentMemoryChunk;
    unsigned short numStrips = chunk->m_numStrips;
    unsigned short* idx = chunk->FUN_00a75f10();
    unsigned short* lengths = chunk->m_pStripIndices;
    float* verts = chunk->m_verts;
    unsigned short s = 0;
    unsigned int t = key & 0xfffff;
    for (; s < numStrips; s++)
    {
        if (t < (unsigned int)(lengths[s] - 2))
            break;
        t -= lengths[s] - 2;
        idx += lengths[s];
    }
    unsigned short* p = &idx[t];
    unsigned short i0 = *p;
    unsigned short i1 = *++p;
    unsigned short i2 = *++p;
    if (i0 == i1 || i0 == i2 || i1 == i2)
        return 0;
    const float* a = &verts[i0 * 3];
    const float* b = &verts[i1 * 3];
    const float* c = &verts[i2 * 3];
    S00ca45b0_Tri* tri = alloc ? alloc->FUN_00ca39a0(m_fSphereRadius) : 0;
    S00ca45b0_Vec v;
    float* q = v.m_vComponents.m128_f32;
    q[0] = *(float volatile*)&a[0] * DAT_012682c8;
    q[1] = a[1] * DAT_012682c8;
    q[2] = a[2] * DAT_012682c8;
    q[3] = 0.0f;
    v.mul4(m_vScale);
    tri->m_v0 = v;
    q[0] = b[0] * DAT_012682c8;
    q[1] = b[1] * DAT_012682c8;
    q[2] = b[2] * DAT_012682c8;
    q[3] = 0.0f;
    v.mul4(m_vScale);
    tri->m_v1 = v;
    q[0] = c[0] * DAT_012682c8;
    q[1] = c[1] * DAT_012682c8;
    q[2] = c[2] * DAT_012682c8;
    q[3] = 0.0f;
    v.mul4(m_vScale);
    tri->m_v2 = v;
    return tri;
}

namespace PointBoundsSse {
extern "C" LocalM128 _mm_load_ps1(float const* p);
extern "C" LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
}

extern float DAT_0104da48;

struct BoundVector
{
    union
    {
        LocalM128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct PointBounds
{
    BoundVector min;
    BoundVector max;
};
struct PointArrayArg
{
    BoundVector** p;
    PointArrayArg(BoundVector** v) : p(v)
    {}
};
struct BoundsArg
{
    PointBounds* p;
    BoundsArg(PointBounds* v) : p(v)
    {}
};

// @fnv 0x00cbebf0
// src: GUESS 0x00cbebf0 (confidence: low)
void Runtime_ProcessEntries_00cbebf0(PointArrayArg points, int n, BoundsArg bounds)
{
    if (!n)
    {
        PointBounds* pd = bounds.p;
        _ReadWriteBarrier();
        pd->min.quad = PointBoundsSse::_mm_load_ps1(&DAT_0104da48);
        pd->max.quad = PointBoundsSse::_mm_load_ps1(&DAT_0104e148);
    }
    else
    {
        BoundVector** pa = points.p;
        LocalM128 first = pa[0]->quad;
        _ReadWriteBarrier();
        PointBounds* pd = bounds.p;
        pd->min.quad = first;
        pd->max.quad = pa[0]->quad;
        for (int i = 1; i < n; ++i)
        {
            pd->min.quad = PointBoundsSse::_mm_min_ps(pa[i]->quad, pd->min.quad);
            pd->max.quad = PointBoundsSse::_mm_max_ps(pa[i]->quad, pd->max.quad);
        }
        pd->min.w = 0.0f;
        pd->max.w = 0.0f;
    }
}

namespace StripsBoundsIntrinsics {
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_load_ps1(const float*);
    void _mm_store_ss(float*, LocalM128);
}
}

union StripsBoundsQuad
{
    LocalM128 simd;
    float lanes[4];
    signed char bytes[16];
};

struct StripsBoundsTransform;
class StripsBoundsVector
{
  public:
    StripsBoundsQuad m_vComponents;
    void add(const StripsBoundsQuad& r)
    {
        m_vComponents.simd = StripsBoundsIntrinsics::_mm_add_ps(m_vComponents.simd, r.simd);
    }
    float getX() const
    {
        float x;
        StripsBoundsIntrinsics::_mm_store_ss(&x, m_vComponents.simd);
        return x;
    }
    void setTransformedPos_00c7f640(const StripsBoundsTransform& t, const StripsBoundsVector& v);
};
struct StripsBoundsVertex
{
    float x, y, z;
};
struct StripsBoundsAabb
{
    StripsBoundsVector m_kMinimumCorner, m_kMaximumCorner;
};
struct StripsBoundsCache
{
    hkBool hkTransform_isApproximatelyEqual(const StripsBoundsTransform& t, float tolerance) const;
    int unk00;
};
struct StripsBoundsData
{
    int unk00, unk04;
    unsigned short count;
    unsigned short unk0a;
    int unk0c, unk10, unk14, unk18, unk1c;
    StripsBoundsVertex* vertices;
};
struct StripsBoundsEntry
{
    StripsBoundsData* data;
    int unk04;
};
extern float DAT_012682c8;
class StripsBoundsShape
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    StripsBoundsCache m_pAccessManager;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    StripsBoundsVector m_cachedMin, m_cachedMax, m_vScale;
    float m_fSphereRadius;
    int unk94;
    StripsBoundsEntry* entries;
    unsigned capacity, count;
    void hkNiTriStripsShape_getAabb(const StripsBoundsTransform& t, float tolerance, StripsBoundsAabb& out);
};

// @fnv 0x00ca4280
// src: XBOX_PDB 0x00ca4280
void StripsBoundsShape::hkNiTriStripsShape_getAabb(const StripsBoundsTransform& t, float tolerance, StripsBoundsAabb& out)
{
    if (m_cachedMin.getX() != 3.402820018375656e+38 && m_pAccessManager.hkTransform_isApproximatelyEqual(t, 0.001f).m_cBooleanValue)
    {
        out.m_kMinimumCorner.m_vComponents.simd = m_cachedMin.m_vComponents.simd;
        out.m_kMaximumCorner.m_vComponents.simd = m_cachedMax.m_vComponents.simd;
    }
    else
    {
        out.m_kMinimumCorner.m_vComponents.simd =
            StripsBoundsIntrinsics::_mm_setr_ps(3.40282e38f, 3.40282e38f, 3.40282e38f, 0.0f);
        out.m_kMaximumCorner.m_vComponents.simd =
            StripsBoundsIntrinsics::_mm_setr_ps(-3.40282e38f, -3.40282e38f, -3.40282e38f, 0.0f);
        unsigned n = count;
        const StripsBoundsVector& scale = m_vScale;
        for (unsigned i = 0; i < n; ++i)
        {
            StripsBoundsData* data = entries[i].data;
            const StripsBoundsVertex* p = data->vertices;
            unsigned vertices = data->count;
            for (unsigned j = 0; j < vertices; ++j)
            {
                StripsBoundsVector v;
                v.m_vComponents.lanes[0] = p[j].x * DAT_012682c8;
                v.m_vComponents.lanes[1] = p[j].y * DAT_012682c8;
                v.m_vComponents.lanes[2] = p[j].z * DAT_012682c8;
                v.m_vComponents.lanes[3] = 0.0f;
                v.m_vComponents.simd =
                    StripsBoundsIntrinsics::_mm_mul_ps(scale.m_vComponents.simd, v.m_vComponents.simd);
                StripsBoundsVector tv;
                tv.setTransformedPos_00c7f640(t, v);
                out.m_kMinimumCorner.m_vComponents.simd =
                    StripsBoundsIntrinsics::_mm_min_ps(out.m_kMinimumCorner.m_vComponents.simd, tv.m_vComponents.simd);
                out.m_kMaximumCorner.m_vComponents.simd =
                    StripsBoundsIntrinsics::_mm_max_ps(out.m_kMaximumCorner.m_vComponents.simd, tv.m_vComponents.simd);
            }
        }
    }
    float radius = m_fSphereRadius + tolerance;
    StripsBoundsQuad r;
    r.simd = StripsBoundsIntrinsics::_mm_load_ps1(&radius);
    out.m_kMinimumCorner.m_vComponents.simd =
        StripsBoundsIntrinsics::_mm_sub_ps(out.m_kMinimumCorner.m_vComponents.simd, r.simd);
    out.m_kMaximumCorner.add(r);
}

namespace PackedDisplayIntrinsics {
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
}


extern char str_010c3fc0[];
static float DAT_011b1864 = 6.9991255f;
extern int DAT_0109b2d4;
void* __cdecl FUN_00ec44d0(void* dst, const void* src, unsigned int n);
__forceinline void* S00ca5da0_Memcpy(void* dst, const void* src, unsigned int n)
{
    return FUN_00ec44d0(dst, src, n);
}

union __declspec(align(16)) DisplayVector
{
    LocalM128 simd;
    float lanes[4];
    unsigned char byteLanes[16];
};

struct S00ca5da0_ArrayAllocation
{
    static __forceinline void* operator new[](unsigned int size)
    {
        return ((MemoryManager_t*)&DAT_011f6238)->Game_DoHeapAlloc(size);
    }
    static __forceinline void operator delete[](void*)
    {}
};

struct S00ca5da0_Vec3 : S00ca5da0_ArrayAllocation
{
    float x, y, z;
};
struct S00ca5da0_Index : S00ca5da0_ArrayAllocation
{
    unsigned short value;
};

struct S00ca5da0_Entry
{
    unsigned short f0;
    unsigned short f1;
    unsigned short f2;
    unsigned short f6;
};

struct S00ca5da0_Part
{
    int unk00;
    unsigned int count;
    int unk08;
};

struct S00ca5da0_Geom
{
    int unk00;
    int unk04;
    unsigned int m_08;
    int unk0c;
    unsigned short m_10;
    unsigned short unk12;
    S00ca5da0_Entry* m_14;
    S00ca5da0_Vec3* m_18;
    int unk1c;
    int unk20;
    S00ca5da0_Part* m_24;
};

struct S00ca5da0_Data
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
    struct S00ca5da0_Geom* m_84;
};

struct S00ca5da0_Arr
{
    void* m_vtbl;
    unsigned short* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    __declspec(noalias) void NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(unsigned int size);
    __forceinline S00ca5da0_Arr(unsigned int maxSize = 0, unsigned int growBy = 1)
    {

        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_vtbl = &DAT_0109b2d4;
    }
    __forceinline ~S00ca5da0_Arr()
    {
        _NiFree_00aa10f0(m_pBase);
    }
    __forceinline void SetAt(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usSize)
        {
            m_usSize = (unsigned short)(idx + 1);
            if (v != 0)
                m_usESize++;
        }
        else
        {
            if (v != 0)
            {
                if (m_pBase[idx] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[idx] != 0)
                    m_usESize--;
            }
        }
        m_pBase[idx] = v;
    }
    __forceinline unsigned int SetAtGrow(unsigned int idx, const unsigned short& v)
    {
        if (idx >= m_usMaxSize)
            NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(idx + m_usGrowBy);
        SetAt(idx, v);
        return idx;
    }
    __forceinline unsigned int Add(const unsigned short& v)
    {
        return SetAtGrow(m_usSize, v);
    }
    __forceinline void RemoveAll()
    {
        for (unsigned short q = 0; q < m_usSize; q++)
            m_pBase[q] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }
};

struct S00ca5da0_Mesh
{
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        _NiFree_00aa10f0(p);
    }
    S00ca5da0_Mesh();
    void NiGeometryData_SetData(unsigned short count, S00ca5da0_Vec3* verts, int a, int b, int c, int d, int e);
    void NiTriShapeData_SetData(unsigned short count, unsigned short* tris);
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
};

struct S00ca5da0_Prop
{
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        _NiFree_00aa10f0(p);
    }
    S00ca5da0_Prop();
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

    int m_28;
    int m_2c;
    int m_30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;

    int m_44;
    int unk48;
};

struct S00ca5da0_Shape
{
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        _NiFree_00aa10f0(p);
    }
    S00ca5da0_Shape(S00ca5da0_Mesh* mesh);
    void AssignFixedString(const NiFixedString& name);
    void NiAVObject_AttachProperty(S00ca5da0_Prop* prop);
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

    float m_64;
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
};

struct S00ca5da0_Pt
{
    int x, y, z;
};

struct S00ca5da0_Node
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
    virtual void AttachChildInAvailableSlot(S00ca5da0_Shape* child, int one);
};

struct S00ca5da0_Builder
{
    int unk00;
    int unk04;
    S00ca5da0_Data* m_08;
    void bhkPackedNiTriStripsShape_BuildDisplayGeometry(S00ca5da0_Node* parent, S00ca5da0_Pt* pt);
};
double __fastcall GetField24Float(S00ca5da0_Builder* self);

// @fnv 0x00ca5da0
// src: XBOX_PDB 0x00ca5da0
void S00ca5da0_Builder::bhkPackedNiTriStripsShape_BuildDisplayGeometry(S00ca5da0_Node* parent, S00ca5da0_Pt* pt)
{
    TlsGuard_t guard;
    S00ca5da0_Geom* geom = (this ? m_08 : 0)->m_84;
    S00ca5da0_Arr arr;
    unsigned short base = 0;
    unsigned short flag;
    unsigned short c;
    unsigned short prevJ = 0;
    unsigned short a;
    unsigned short j = 0;
    unsigned short b;
    for (int i = 0; i < geom->m_10; i++)
    {
        a = 0;
        b = 0;
        c = 0;
        flag = 0;
        do
        {
            S00ca5da0_Entry* e = &geom->m_14[j];
            if (flag == 0)
            {
                a = e->f0;
                b = e->f1;
                c = e->f2;
                if (a >= base + geom->m_24[i].count)
                    break;
                arr.Add((unsigned short)(a - base));
                arr.Add((unsigned short)(b - base));
                arr.Add((unsigned short)(c - base));
                j++;
                flag = 1;
            }
            else if (b == e->f0 && c == e->f1)
            {
                a = b;
                b = c;
                c = e->f2;
                arr.Add((unsigned short)(a - base));
                arr.Add((unsigned short)(b - base));
                arr.Add((unsigned short)(c - base));
                flag++;
                j++;
            }
            else
            {
                flag = 0;
            }
        } while (a < base + geom->m_24[i].count && j < geom->m_08);

        S00ca5da0_Mesh* mesh = new S00ca5da0_Mesh;
        unsigned short cnt = (unsigned short)geom->m_24[i].count;
        S00ca5da0_Vec3* verts = new S00ca5da0_Vec3[cnt];
        for (unsigned short k = base; k < base + cnt; k++)
        {
            DisplayVector storage;
            LocalM128& v = *(LocalM128*)&storage.byteLanes[0];
            float* t = storage.lanes;
            t[0] = geom->m_18[k].x;
            t[1] = geom->m_18[k].y;
            t[2] = geom->m_18[k].z;
            t[3] = 0.0f;
            float x, y, z;
            PackedDisplayIntrinsics::_mm_store_ss(&x, v);
            PackedDisplayIntrinsics::_mm_store_ss(&y, PackedDisplayIntrinsics::_mm_shuffle_ps(v, v, 0x55));
            PackedDisplayIntrinsics::_mm_store_ss(&z, PackedDisplayIntrinsics::_mm_shuffle_ps(v, v, 0xaa));
            S00ca5da0_Vec3* d = &verts[k - base];
            d->x = x * DAT_011b1864;
            d->y = y * DAT_011b1864;
            d->z = z * DAT_011b1864;
        }
        mesh->NiGeometryData_SetData(cnt, verts, 0, 0, 0, 0, 0);
        unsigned short nTri = (unsigned short)(j - prevJ);
        unsigned short* tris = (unsigned short*)new S00ca5da0_Index[nTri * 3];
        S00ca5da0_Memcpy(tris, arr.m_pBase, arr.m_usSize * sizeof(unsigned short));
        mesh->NiTriShapeData_SetData(nTri, tris);

        S00ca5da0_Shape* shape = new S00ca5da0_Shape(mesh);
        shape->AssignFixedString(NiFixedString((const char*)str_010c3fc0));
        float f = (float)GetField24Float(this);
        shape->m_64 = (float)fabs(f);
        arr.RemoveAll();

        S00ca5da0_Prop* prop = new S00ca5da0_Prop;
        prop->m_28 = pt->x;
        prop->m_2c = pt->y;
        prop->m_30 = pt->z;
        prop->m_44++;
        shape->NiAVObject_AttachProperty(prop);
        parent->AttachChildInAvailableSlot(shape, 1);
        base += cnt;
        prevJ = j;
    }
}

extern const char DAT_010c9288[];
extern const char DAT_010c41f8[];
extern unsigned long DAT_0126835c;
extern void*(__stdcall* DAT_00fdf044)(unsigned long);
extern "C" void _ReadWriteBarrier(void);

struct S00cbfaa0_Entry
{
    const char* name;
    unsigned int time;
    unsigned int unk08;
};

struct S00cbfaa0_Stream
{
    int unk00;
    S00cbfaa0_Entry* m_cur;
    int unk08;
    S00cbfaa0_Entry* m_kRayEnd;
};

struct __declspec(align(16)) SinglePointVector
{
    float x, y, z, w;
};

struct S00cbfaa0_Src
{
    SinglePointVector q00;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned char m_20;
};

struct S00cbfaa0_Dst
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S00cbfaa0_Rec
{
    SinglePointVector vec;
    int m_10;
    const void* m_14;
    int m_18;
    int m_1c;
};

struct S00cbfaa0_Base
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23(S00cbfaa0_Rec* r, struct S00cbfaa0_Obj* o, int z);
};

struct S00cbfaa0_Obj
{
    int unk00;
    S00cbfaa0_Src* m_04;
    void* m_08;
    int m_0c;
    int m_10;
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
    void* m_44;
    void UpdateFields_00cbfaa0(S00cbfaa0_Base* a0, S00cbfaa0_Src* a1, int a2, S00cbfaa0_Dst* a3, int a4, int a5, int a6);
};

// @fnv 0x00cbfaa0
// src: GUESS 0x00cbfaa0 (confidence: low)
void S00cbfaa0_Obj::UpdateFields_00cbfaa0(S00cbfaa0_Base* a0, S00cbfaa0_Src* a1, int a2, S00cbfaa0_Dst* a3, int a4, int a5,
                                 int a6)
{
    volatile unsigned int ts;
    void*(__stdcall * getStream)(unsigned long) = DAT_00fdf044;
    S00cbfaa0_Stream* st = (S00cbfaa0_Stream*)getStream(DAT_0126835c);
    S00cbfaa0_Entry* cur = st->m_cur;
    if (cur < st->m_kRayEnd)
    {
        cur->name = DAT_010c9288;
        _ReadWriteBarrier();
        ts = (unsigned int)__rdtsc();
        cur->time = ts;
        cur = cur + 1;
        st->m_cur = cur;
    }

    m_04 = a1;
    m_08 = a3 ? &a3->unk14 : 0;
    m_0c = a5;
    m_10 = a6;
    if (a1->m_20)
    {
        m_44 = a3 ? &a3->unk10 : 0;
    }
    else
    {
        m_44 = 0;
    }

    S00cbfaa0_Rec r;
    *(::LocalM128*)&r.vec = *(const ::LocalM128*)&a1->q00;
    r.m_1c = a4;
    r.m_14 = &a1->unk10;
    r.m_10 = a2;
    r.m_18 = 0x30;
    a0->vf23(&r, this, 0);

    st = (S00cbfaa0_Stream*)getStream(DAT_0126835c);
    cur = st->m_cur;
    if (cur < st->m_kRayEnd)
    {
        cur->name = DAT_010c41f8;
        _ReadWriteBarrier();
        ts = (unsigned int)__rdtsc();
        cur->time = ts;
        cur = cur + 1;
        st->m_cur = cur;
    }
}

#include <xmmintrin.h>
namespace fnv_00ca1410 {
extern "C"
{
    ::LocalM128(_mm_load_ss)(const float*);
    void(_mm_store_ss)(float*, ::LocalM128);
    ::LocalM128(_mm_shuffle_ps)(::LocalM128, ::LocalM128, int);
    ::LocalM128(_mm_setr_ps)(float, float, float, float);
    ::LocalM128(_mm_sub_ps)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_mul_ps)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_add_ps)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_add_ss)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_sqrt_ss)(::LocalM128);
    ::LocalM128(_mm_set_ss)(float);
    ::LocalM128(_mm_cmpeq_ss)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_rsqrt_ss)(::LocalM128);
    ::LocalM128(_mm_mul_ss)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_sub_ss)(::LocalM128, ::LocalM128);
    ::LocalM128(_mm_andnot_ps)(::LocalM128, ::LocalM128);
}
extern __int64 __cdecl BSPrecisionTimer_GetTimer();
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern float DAT_0126829c;
extern float DAT_012682a8;
extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01012068 = 1.0f;
extern void __cdecl hkArrayUtil__reserve(hkMemoryAllocator&, void*, int, int);
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline void grow(hkMemoryAllocator& heap, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int doubled = 2 * cap;
            int wanted = n < doubled ? doubled : n;
            hkArrayUtil__reserve(heap, this, wanted, sizeof(T));
        }
    }
    __forceinline void reserveExact(hkMemoryAllocator& heap, int n)
    {
        if (getCapacity() < n)
            hkArrayUtil__reserve(heap, this, n, sizeof(T));
    }
    __forceinline void SetSizeAndGrow(hkMemoryAllocator& heap, int n)
    {
        grow(heap, n);
        size = n;
    }
    __forceinline void setSizeZero(hkMemoryAllocator& heap, int n)
    {
        grow(heap, n);
        int remaining = n - size;
        T* out = data + size;
        for (int k = 0; k < remaining; ++k)
            *out++ = 0;
        size = n;
    }
};
struct HeapChoice
{
    hkMemoryAllocator& get(const void*)
    {
        return GetHavokHeap(::hkMemoryRouter::getInstance());
    }
};
template <class T> struct WorkArray : ArrayBase<T>
{
    ~WorkArray();
    __forceinline void reserve(int n)
    {
        reserveExact(HeapChoice().get(this), n);
    }
    __forceinline void resize(int n)
    {
        SetSizeAndGrow(HeapChoice().get(this), n);
    }
    __forceinline void resizeZero(int n)
    {
        setSizeZero(HeapChoice().get(this), n);
    }
};
struct SkeletonBone;
struct Skeleton
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    ArrayBase<SkeletonBone> bones;
    ArrayBase<hkQsTransform> reference;
    ArrayBase<char*> slots;
};
struct ScalarValue
{
    ::LocalM128 q;
    ScalarValue()
    {}
    ScalarValue(const ::LocalM128& v) : q(v)
    {}
    ScalarValue(float f)
    {
        q = (_mm_load_ss)(&f);
    }
    operator float() const
    {
        float f;
        (_mm_store_ss)(&f, q);
        return f;
    }
    __forceinline ::LocalM128 splat() const
    {
        return (_mm_shuffle_ps)(q, q, 0);
    }
};
union VectorQuad
{
    ::LocalM128 simd;
    float lanes[4];
    signed char bytes[16];
};
struct VectorValue
{
    VectorQuad q;
    VectorValue()
    {}
    VectorValue(float x, float y, float z, float w)
    {
        q.simd = (_mm_setr_ps)(x, y, z, w);
    }
    VectorValue(const VectorValue& v)
    {
        q.simd = v.q.simd;
    }
    VectorValue(const ::LocalM128& v)
    {
        q.simd = v;
    }
    operator ::LocalM128() const
    {
        return q.simd;
    }
    void operator=(const ::LocalM128& v)
    {
        q.simd = v;
    }
    void operator=(const VectorValue& v)
    {
        q.simd = v.q.simd;
    }
    __forceinline void difference(const VectorValue& a, const VectorValue& b)
    {
        q.simd = (_mm_sub_ps)(a.q.simd, b.q.simd);
    }
    __forceinline void cross(const VectorValue& a, const VectorValue& b)
    {
        ::LocalM128 lhs =
            (_mm_mul_ps)((_mm_shuffle_ps)(a.q.simd, a.q.simd, 0xc9), (_mm_shuffle_ps)(b.q.simd, b.q.simd, 0xd2));
        ::LocalM128 rhs =
            (_mm_mul_ps)((_mm_shuffle_ps)(a.q.simd, a.q.simd, 0xd2), (_mm_shuffle_ps)(b.q.simd, b.q.simd, 0xc9));
        q.simd = (_mm_sub_ps)(lhs, rhs);
    }
    __forceinline void add(const VectorValue& a)
    {
        q.simd = (_mm_add_ps)(q.simd, a.q.simd);
    }
    __forceinline ScalarValue dot(const VectorValue& a) const
    {
        ::LocalM128 products = (_mm_mul_ps)(q.simd, a.q.simd);
        ::LocalM128 xy = (_mm_add_ss)((_mm_shuffle_ps)(products, products, 0x55), products);
        return (_mm_add_ss)((_mm_shuffle_ps)(products, products, 0xaa), xy);
    }
    __forceinline ScalarValue length() const
    {
        return (_mm_sqrt_ss)(dot(*this).q);
    }
    __forceinline ScalarValue inverseLength() const
    {
        ::LocalM128 half = (_mm_set_ss)(0.5f);
        ::LocalM128 three = (_mm_set_ss)(3.0f);
        ::LocalM128 zero = (_mm_set_ss)(0.0f);
        ::LocalM128 squared = dot(*this).q;
        ::LocalM128 isZero = (_mm_cmpeq_ss)(squared, zero);
        ::LocalM128 estimate = (_mm_rsqrt_ss)(squared);
        ::LocalM128 result = (_mm_mul_ss)((_mm_mul_ss)(half, estimate),
                                       (_mm_sub_ss)(three, (_mm_mul_ss)((_mm_mul_ss)(squared, estimate), estimate)));
        return (_mm_andnot_ps)(isZero, result);
    }
    __forceinline void normalize()
    {
        q.simd = (_mm_mul_ps)(inverseLength().splat(), q.simd);
    }
    __forceinline void scale(const ScalarValue& a, const VectorValue& b)
    {
        q.simd = (_mm_mul_ps)(a.splat(), b.q.simd);
    }
};
struct Contact
{
    short bone;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    VectorValue point, direction;
};
struct FUN_00c7c030
{
    Skeleton* skeleton;
    WorkArray<hkQsTransform> localFUN_00c7c030, modelFUN_00c7c030;
    WorkArray<int> flags;
    bool modelSync, localSync;
    WorkArray<float> floats;
    __forceinline FUN_00c7c030(Skeleton* s) : skeleton(s), modelSync(false), localSync(false)
    {
        int n = skeleton->bones.GetLogicalSize();
        modelFUN_00c7c030.resize(n);
        localFUN_00c7c030.resize(n);
        flags.resize(n);
        const int paddedCount = (skeleton->slots.GetLogicalSize() + 3) & ~3;
        floats.reserve(paddedCount);
        floats.resizeZero(skeleton->slots.GetLogicalSize());
    }
    ~FUN_00c7c030();
    ArrayBase<hkQsTransform>& FUN_00cd9fe0();
};
struct BodyHeader
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
    virtual void apply(const VectorValue*, const VectorValue*);
    unsigned int unk04;
    unsigned char type;
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
};
struct Body : BodyHeader
{
    VectorValue position;
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
    VectorValue linearVelocity;
    VectorValue angularVelocity;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    float FUN_00c86430();
    __forceinline void pointVelocity(const VectorValue& point, VectorValue& result) const
    {
        VectorValue offset;
        offset.difference(point, position);
        result.cross(angularVelocity, offset);
        result.add(linearVelocity);
    }
};
struct Properties
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int flags;
};
struct Meta
{
    unsigned int unk00, unk04, unk08, unk0c;
    Properties props;
};
struct Wrapper
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
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void refresh();
    unsigned int unk04;
    Meta* meta;
    void Object_DoNothing();
    inline Properties* getProps()
    {
        return meta ? &meta->props : 0;
    }
    inline unsigned int GetPropertyFlags()
    {
        Properties* p = getProps();
        return p ? p->flags : 0;
    }
    inline void setFlags(unsigned int value)
    {
        Meta* m = meta;
        if (m)
        {
            Object_DoNothing();
            Properties* props = &m->props;
            Object_DoNothing();
            if (props)
                props->flags = value;
        }
    }
    inline void changeFlag(bool set)
    {
        unsigned int f = GetPropertyFlags();
        if (((unsigned char)(f >> 14) & 1) != set)
        {
            setFlags(set ? f | 0x4000 : f & ~0x4000);
            refresh();
        }
    }
};
struct World
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
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    void* context;
};
struct Bone
{
    unsigned int unk00;
    unsigned int unk04;
    World* world;
    Wrapper* wrapper;
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
    Body body;
    void activate_00c9c1d0();
};
struct Rig
{
    unsigned int unk00;
    unsigned int unk04;
    ArrayBase<Bone*> bones;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    void hkaRagdollInstance_getPoseWorldSpace_00ce18d0(hkQsTransform*);
    inline Skeleton* getSkeleton() const
    {
        return skeleton;
    }
    inline int getNumBones() const
    {
        return getSkeleton()->bones.GetLogicalSize();
    }
    inline const ArrayBase<Bone*>& getBodies() const
    {
        return bones;
    }
    inline Bone* getBone(int n)
    {
        int index = boneMap[n];
        return index >= 0 ? bones[index] : 0;
    }
    inline World* getWorld()
    {
        Bone* root = bones[0];
        return root ? root->world : 0;
    }
};
struct ByteBoolean
{
    unsigned char value;
    operator bool() const
    {
        return value != 0;
    }
};
struct Controller
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    WorkArray<int> states;
    inline const ArrayBase<int>& getStates() const
    {
        return states;
    }
    void ResetEntries();
    ByteBoolean hkaDetectRagdollPenetration_detectPenetration(FUN_00c7c030&, WorkArray<Contact>&);
};
struct Observer
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
    virtual World* getWorld();
    virtual void v98();
    virtual void setWorld(void*);
};
struct Entry
{
    unsigned int unk00;
    Rig* rig;
    unsigned int unk08;
    Observer* observer;
    Controller* controller;
    WorkArray<Contact> contacts;
    bool active;
};
struct EntryListNode
{
    unsigned int capacity;
    Entry** data;
    unsigned int size;
    inline unsigned int GetLogicalSize() const
    {
        return size;
    }
    __forceinline Entry*& operator[](unsigned int i)
    {
        return data[i];
    }
};
struct UpdateManager
{
    unsigned int unk00;
    EntryListNode entries;
    unsigned int unk10, unk14, unk18, unk1c;
    __int64 startTime, duration;
    void bhkRagdollPenetrationUtil_Update();
};
// @fnv 0x00ca1410
// src: XBOX_PDB 0x00ca1410
void UpdateManager::bhkRagdollPenetrationUtil_Update()
{
    for (unsigned int i = 0; i < entries.GetLogicalSize(); ++i)
    {
        Entry* entry = entries[i];
        Rig* rig = entry->rig;
        bool excluded = false;
        for (int k = 0; k < rig->bones.GetLogicalSize() && !excluded; ++k)
        {
            unsigned char type = rig->bones[k]->body.type;
            excluded = type == 4 || type == 5;
        }
        if (rig->getWorld() && !excluded && (entry->active || BSPrecisionTimer_GetTimer() - startTime <= duration))
        {
            if (BSPrecisionTimer_GetTimer() - startTime <= duration || entries[i]->active)
                entries[i]->controller->ResetEntries();
            FUN_00c7c030 pose(entries[i]->rig->getSkeleton());
            entries[i]->rig->hkaRagdollInstance_getPoseWorldSpace_00ce18d0(pose.FUN_00cd9fe0().begin());
            if (entries[i]->rig->getWorld() != entries[i]->observer->getWorld())
            {
                World* w = entries[i]->rig->getWorld();
                entries[i]->observer->setWorld(w ? w->context : 0);
            }
            bool wasActive = entries[i]->active;
            entries[i]->active = entries[i]->controller->hkaDetectRagdollPenetration_detectPenetration(pose, entries[i]->contacts);
            int j;
            if (entries[i]->active)
            {
                const ArrayBase<int>& states = entries[i]->controller->getStates();
                for (j = 0; j < entries[i]->rig->getNumBones(); ++j)
                {
                    Bone* bone = entries[i]->rig->getBone(j);
                    if (bone && bone->wrapper)
                    {
                        Wrapper* wrapper = bone->wrapper;
                        if (states[j])
                        {
                            wrapper->changeFlag(true);
                            if (states[j] == 1)
                            {
                                VectorValue position(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01011d78);
                                VectorValue direction(DAT_01011d78, DAT_01011d78, DAT_01012068, DAT_01011d78);
                                for (int k = 0; k < entries[i]->contacts.GetLogicalSize(); ++k)
                                {
                                    if (j == entries[i]->contacts[k].bone)
                                    {
                                        position = entries[i]->contacts[k].point;
                                        direction = entries[i]->contacts[k].direction;
                                    }
                                }
                                VectorValue velocity;
                                bone->body.pointVelocity(position, velocity);
                                float speed = velocity.length();
                                float projection;
                                if (speed > DAT_0104da4c)
                                {
                                    velocity.normalize();
                                    projection = direction.dot(velocity);
                                }
                                else
                                    projection = 0;
                                float mass = bone->body.FUN_00c86430();
                                float impulse = mass * (DAT_0126829c - projection * speed);
                                impulse = impulse > DAT_012682a8 ? DAT_012682a8 : impulse;
                                impulse = impulse < -DAT_012682a8 ? -DAT_012682a8 : impulse;
                                VectorValue force;
                                force.scale(ScalarValue(impulse), direction);
                                bone->activate_00c9c1d0();
                                bone->body.apply(&force, &position);
                            }
                        }
                        else
                            wrapper->changeFlag(false);
                    }
                }
            }
            else if (wasActive)
            {
                entries[i]->controller->ResetEntries();
                for (j = 0; j < entries[i]->rig->getNumBones(); ++j)
                {
                    Bone* bone = entries[i]->rig->getBone(j);
                    if (bone && bone->wrapper)
                        bone->wrapper->changeFlag(false);
                }
            }
        }
        else
        {
            if (entries[i]->rig->getWorld())
                entries[i]->controller->ResetEntries();
        }
    }
}

}  // namespace fnv_00ca1410

template <class T, unsigned Growth> __forceinline T& GetAtSV(BSSimpleArray<T, Growth>& a, int index)
{
    return a.pBuffer[index];
}
union RagdollScalarVector
{
    ::LocalM128 simd;
    struct
    {
        float x, y, z, w;
    } scalar;
    signed char bytes[16];
};
struct ScalarValue
{
    float value;
    ScalarValue(float x)
    {
        RagdollScalarVector copy;
        *reinterpret_cast<float*>(&copy.bytes[0]) = x;
        value = copy.scalar.x;
    }
};

namespace RagdollConstruction {
struct FUN_00cb9a90 : S_cb9a90_C
{
    FUN_00cb9a90(int, int, float);
    static __forceinline void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char*);
    static __forceinline void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
struct FUN_00cb9b80 : CB9B80WorldObject
{
    FUN_00cb9b80(CB9B80Info*);
    static __forceinline void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
}
extern "C" void _ReadWriteBarrier();
struct CopyMap
{
    virtual ~CopyMap();
};
struct Init
{
    CopyMap* clones;
    CopyMap* processed;
    int copyType;
    char append;
    Init(unsigned int);
    __forceinline ~Init()
    {
        delete clones;
        delete processed;
    }
};
struct ScaleShapeData
{
    int unk00;
    void FUN_00c905b0();
};
struct IntegerBlock18
{
    __forceinline int GetC() const
    {
        return unk0c;
    }
    __forceinline int GetD() const
    {
        return unk10;
    }
    __forceinline void SetC(int v)
    {
        unk0c = v;
    }
    __forceinline void SetD(int v)
    {
        unk10 = v;
    }
    __forceinline ScaleShapeData* GetShape() const
    {
        return shape;
    }
    int unk00;
    ScaleShapeData* shape;
    int unk08;
    int unk0c;
    int unk10;
    void SetChildObject(ScaleShapeData*);
};
struct ViewPrefix
{
    int prefix;
};
struct ViewPart
{
    int part;
};
struct ShapeView : ViewPrefix, ViewPart
{
    int unk04;
    int unk08;
    int unk0c;
};
struct ShapeRef
{
    virtual void v00();
    virtual void DeleteThis();
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
    virtual void SetContext(void*);
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual ViewPart* GetView(char*);
    volatile long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    ScaleShapeData* data;
    int unk0c;
};
struct MaterialShape : ShapeRef
{
    int material;
};
struct FUN_00cb9b30 : ShapeRef
{
    FUN_00cb9b30(IntegerBlock18*);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};
struct FUN_009ba410 : ShapeRef
{
    FUN_009ba410(IntegerBlock18*);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};
struct FUN_00c88380 : ShapeRef
{
    FUN_00c88380(IntegerBlock18*);
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void* p)
    {
        _delete(p, 0x10);
    }
};

struct ShapeLink
{
    ShapeLink* next;
    ShapeLink* prev;
    ShapeRef* object;
};
struct Body;
struct Motion
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetMass(float);
};
struct Body
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetShape(ScaleShapeData*);
    int unk04;
    int unk08;
    int unk0c;
    ShapeLink* shapeHead;
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
    float damping90;
    float damping94;
    Motion* hkpRigidBody_getStoredDynamicMotion_00ca86c0();
    void hkpRigidBody_setMass(float);
};
struct BodyOwner
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
    virtual void* GetContextOwner();
    int unk04;
    Body* body;
    int unk0c;
    int unk10;
    NiPointer<ShapeRef> shape;
    __declspec(noinline) void Object_DoNothing();
    __forceinline ShapeRef* GetShape(Body* current)
    {
        if (current)
        {
            Object_DoNothing();
            ShapeLink** head = &current->shapeHead;
            Object_DoNothing();
            if (head && *head)
                return (*head)->object;
        }
        return 0;
    }
    __forceinline void SetMass(const ScalarValue& mass)
    {
        Motion* motion = body ? body->hkpRigidBody_getStoredDynamicMotion_00ca86c0() : 0;
        if (motion)
            motion->SetMass(mass.value);
        else if (body)
            body->hkpRigidBody_setMass(mass.value);
    }
    __forceinline void SetAngularDamping(const ScalarValue& a)
    {
        body->damping90 = a.value;
    }
    __forceinline void SetLinearDamping(const ScalarValue& a)
    {
        body->damping94 = a.value;
    }
};
struct CastBody
{
    int unk00, unk04, unk08, unk0c;
    BodyOwner* owner;
};
struct CastObject
{
    CastBody* FUN_00653290(const void*);
};
struct SceneObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    CastObject* collision;
};
extern int DAT_012043f8;
struct TransformData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float source;
    int unk24, unk28, unk2c;
    float target;
};
struct CloneProcess : Init
{
    float scaleX, scaleY, scaleZ;
    __forceinline CloneProcess(unsigned n) : Init(n)
    {
        scaleX = scaleY = scaleZ = 1.0f;
    }
};
extern "C" void __cdecl hkMalleableConstraintCinfo_ApplyScale(float, ScaleShapeData*);
extern "C" void __cdecl hkBallAndSocketConstraintCinfo_ApplyScale(float, ScaleShapeData*);
struct ContextOwner
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
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    void* context;
};
struct ShapeUpdater
{
    int unk00, unk04, unk08;
    BSSimpleArray<IntegerBlock18*, 1024> shapes;
    BSSimpleArray<unsigned, 1024> kinds;
    float mass, linearDamping, angularDamping, radius;
    int material;
    __forceinline int GetMaterial() const
    {
        return material;
    }
    __forceinline IntegerBlock18* GetInfo(unsigned i)
    {
        return GetAtSV(shapes, i);
    }
    __forceinline unsigned GetKind(unsigned i)
    {
        return GetAtSV(kinds, i);
    }
    void bhkRagdollTemplateData_ReplaceRagdollData(SceneObject*, float);
};
static __forceinline NiPointer<ShapeRef>& AssignSV(NiPointer<ShapeRef>& self, const NiPointer<ShapeRef>& other)
{
    if (self.m_pObject != other.m_pObject)
    {
        if (self.m_pObject)
            self.m_pObject->DecRefCount();
        self.m_pObject = other.m_pObject;
        if (self.m_pObject)
            self.m_pObject->IncRefCount();
    }
    return self;
}
struct ScaledShapeData : ScaleShapeData
{
};
void __cdecl hkHingeConstraintCinfo_ApplyScale(float, ScaledShapeData*);
struct CapsuleData : ScaleShapeData
{
};
void __cdecl hkHingeConstraintCinfo_ApplyScale(float, CapsuleData*);
struct ScriptProgram : ScaleShapeData
{
};
void __cdecl hkHingeConstraintCinfo_ApplyScale(float, ScriptProgram*);
// @fnv 0x00cba6f0
// src: XBOX_PDB 0x00cba6f0
void ShapeUpdater::bhkRagdollTemplateData_ReplaceRagdollData(SceneObject* object, float scale)
{
    if (!object->collision)
        return;
    CastBody* cast = object->collision->FUN_00653290(&DAT_012043f8);
    if (!cast)
        return;
    BodyOwner* owner = cast->owner;
    if (!owner)
        return;
    Body* body = owner->body;
    if (!body)
        return;
    owner->SetMass(ScalarValue(mass));
    Body* current = owner->body;
    {
        ScalarValue value(angularDamping);
        float* damping = &current->damping90;
        *damping = value.value;
    }
    {
        ScalarValue value(linearDamping);
        float* damping = &current->damping94;
        *damping = value.value;
    }
    MaterialShape* old = (MaterialShape*)owner->GetShape(current);
    old->material = GetMaterial();
    RagdollConstruction::FUN_00cb9a90* replacement = new RagdollConstruction::FUN_00cb9a90(
        int(old->data ? &((TransformData*)old->data)->source : (const float*)&DAT_01267e30),
        int(old->data ? &((TransformData*)old->data)->target : (const float*)&DAT_01267e30), radius * scale);
    ((NiRefObject*)replacement)->IncRefCount();
    replacement->unk10 = GetMaterial();
    ScaleShapeData* scaledData = (ScaleShapeData*)replacement->unk08;
    body->SetShape(scaledData);
    old->DecRefCount();
    ContextOwner* contextOwner = (ContextOwner*)owner->GetContextOwner();
    void* context = contextOwner ? contextOwner->context : 0;
    for (unsigned int i = 0; i < shapes.iSize; ++i)
    {
        if (owner->shape)
        {
            char viewFlag;
            ShapeView* view = static_cast<ShapeView*>(owner->shape->GetView(&viewFlag));
            IntegerBlock18* source = (IntegerBlock18*)view;
            GetAtSV(shapes, i)->SetC(source->unk0c);
            GetAtSV(shapes, i)->SetD(source->unk10);
            ShapeRef* result = 0;
            CloneProcess clone(0x101);
            switch (GetAtSV(kinds, i))
            {
            case 13:
                hkMalleableConstraintCinfo_ApplyScale(scale, GetAtSV(shapes, i)->GetShape());
                result = (ShapeRef*)new RagdollConstruction::FUN_00cb9a10((char*)GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        (::CreateF4A30Result)(GetAtSV(shapes, i)->GetShape(), reinterpret_cast<int>(&clone)));
                    if (copy)
                    {
                        GetAtSV(shapes, i)->SetChildObject(copy);
                        copy->FUN_00c905b0();
                    }
                }
                hkMalleableConstraintCinfo_ApplyScale(1.0f / scale, GetAtSV(shapes, i)->GetShape());
                break;
            case 0:
                hkBallAndSocketConstraintCinfo_ApplyScale(scale, GetAtSV(shapes, i)->GetShape());
                result = new FUN_00cb9b30(GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        (::CreateF4A30Result)(GetAtSV(shapes, i)->GetShape(), reinterpret_cast<int>(&clone)));
                    if (copy)
                    {
                        GetAtSV(shapes, i)->SetChildObject(copy);
                        copy->FUN_00c905b0();
                    }
                }
                hkBallAndSocketConstraintCinfo_ApplyScale(1.0f / scale, GetAtSV(shapes, i)->GetShape());
                break;
            case 1:
                hkHingeConstraintCinfo_ApplyScale(scale, (ScaledShapeData*)GetAtSV(shapes, i)->GetShape());
                result = new FUN_009ba410(GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        (::CreateF4A30Result)(GetAtSV(shapes, i)->GetShape(), reinterpret_cast<int>(&clone)));
                    if (copy)
                    {
                        GetAtSV(shapes, i)->SetChildObject(copy);
                        copy->FUN_00c905b0();
                    }
                }
                hkHingeConstraintCinfo_ApplyScale(1.0f / scale, (ScaledShapeData*)GetAtSV(shapes, i)->GetShape());
                break;
            case 2:
                hkHingeConstraintCinfo_ApplyScale(scale, (CapsuleData*)GetAtSV(shapes, i)->GetShape());
                result = new FUN_00c88380(GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        (::CreateF4A30Result)(GetAtSV(shapes, i)->GetShape(), reinterpret_cast<int>(&clone)));
                    if (copy)
                    {
                        GetAtSV(shapes, i)->SetChildObject(copy);
                        copy->FUN_00c905b0();
                    }
                }
                hkHingeConstraintCinfo_ApplyScale(1.0f / scale, (CapsuleData*)GetAtSV(shapes, i)->GetShape());
                break;
            case 7:
                hkHingeConstraintCinfo_ApplyScale(scale, (ScriptProgram*)GetAtSV(shapes, i)->GetShape());
                result =
                    (ShapeRef*)new RagdollConstruction::FUN_00cb9b80((CB9B80Info*)(IntegerBlock18*)GetAtSV(shapes, i));
                if (scale != 0.0f)
                {
                    ScaleShapeData* copy = reinterpret_cast<ScaleShapeData*>(
                        (::CreateF4A30Result)(GetAtSV(shapes, i)->GetShape(), reinterpret_cast<int>(&clone)));
                    if (copy)
                    {
                        GetAtSV(shapes, i)->SetChildObject(copy);
                        copy->FUN_00c905b0();
                    }
                }
                hkHingeConstraintCinfo_ApplyScale(1.0f / scale, (ScriptProgram*)GetAtSV(shapes, i)->GetShape());
                break;
            }
            {
                NiPointer<ShapeRef> ref(result);
                if (ref)
                    AssignSV(owner->shape, ref);
            }
            result->SetContext(context);
        }
    }
}

namespace fnv_00cb2ca0 {
namespace quaternion_simd {
// Exe 0x00cb2ca0 quaternion_simd: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    } lanes;
} __m128, LocalM128;
extern "C"
{
    quaternion_simd::LocalM128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_mul_ps(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_mul_ss(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_add_ss(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_xor_ps(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_shuffle_ps(quaternion_simd::LocalM128, quaternion_simd::LocalM128, int);
    quaternion_simd::LocalM128 _mm_sub_ps(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_add_ps(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
    quaternion_simd::LocalM128 _mm_unpackhi_ps(quaternion_simd::LocalM128, quaternion_simd::LocalM128);
}
}

extern unsigned int DAT_010c4c00;

// local form of hkSimdReal: 0x00cb2ca0 needs quaternion_simd packet operands and its RTM inline/conversion ABI.
struct __declspec(align(16)) QuaternionScalarLocal_00cb2ca0
{
    float realX, realY, realZ, realW;
    quaternion_simd::LocalM128 getRealQuad() const
    {
        return *(const quaternion_simd::LocalM128*)this;
    }
    QuaternionScalarLocal_00cb2ca0(quaternion_simd::LocalM128 q)
    {
        *(quaternion_simd::LocalM128*)this = q;
    }
    QuaternionScalarLocal_00cb2ca0(const float& f)
    {
        *(quaternion_simd::LocalM128*)this = quaternion_simd::_mm_load_ss(&f);
    }
    operator float() const
    {
        float f;
        quaternion_simd::_mm_store_ss(&f, getRealQuad());
        return f;
    }
};
inline QuaternionScalarLocal_00cb2ca0 operator*(const QuaternionScalarLocal_00cb2ca0& a, const QuaternionScalarLocal_00cb2ca0& b)
{
    return QuaternionScalarLocal_00cb2ca0(quaternion_simd::_mm_mul_ss(a.getRealQuad(), b.getRealQuad()));
}
// local form of hkVector4: 0x00cb2ca0 needs quaternion_simd packet operands and its RTM inline/conversion ABI.
struct __declspec(align(16)) QuaternionVectorLocal_00cb2ca0
{
    float x, y, z, w;
    quaternion_simd::LocalM128 getQuad() const
    {
        return *(quaternion_simd::LocalM128*)this;
    }
    void setQuad(quaternion_simd::LocalM128 q)
    {
        *(quaternion_simd::LocalM128*)this = q;
    }
    QuaternionScalarLocal_00cb2ca0 dot3(const QuaternionVectorLocal_00cb2ca0& a) const
    {
        quaternion_simd::LocalM128 mul = quaternion_simd::_mm_mul_ps(getQuad(), a.getQuad());
        quaternion_simd::LocalM128 shuf1 = quaternion_simd::_mm_shuffle_ps(mul, mul, 0x55);
        quaternion_simd::LocalM128 add1 = quaternion_simd::_mm_add_ss(shuf1, mul);
        quaternion_simd::LocalM128 shuf2 = quaternion_simd::_mm_shuffle_ps(mul, mul, 0xaa);
        return quaternion_simd::_mm_add_ss(shuf2, add1);
    }
};

// local form of hkQuaternion: 0x00cb2ca0 needs quaternion_simd packet operands and its RTM inline/conversion ABI.
struct __declspec(align(16)) QuaternionLocal_00cb2ca0
{
    QuaternionVectorLocal_00cb2ca0 m_vec;
    QuaternionLocal_00cb2ca0& operator=(const QuaternionLocal_00cb2ca0& other)
    {
        m_vec.setQuad(other.m_vec.getQuad());
        return *this;
    }
    void removeAxisComponent(const QuaternionVectorLocal_00cb2ca0& axis);
    void setMul(const QuaternionLocal_00cb2ca0& q1, const QuaternionLocal_00cb2ca0& q2);
    float GetAngle();
    void SetConjugate(const QuaternionLocal_00cb2ca0& q)
    {
        m_vec.setQuad(quaternion_simd::_mm_xor_ps(q.m_vec.getQuad(), *(quaternion_simd::LocalM128*)&DAT_010c4c00));
    }
    void setInverseMul(const QuaternionLocal_00cb2ca0& q0, const QuaternionLocal_00cb2ca0& q1)
    {
        QuaternionLocal_00cb2ca0 inv0;
        inv0.SetConjugate(q0);
        setMul(inv0, q1);
    }
    float getReal() const
    {
        return m_vec.w;
    }
    const QuaternionVectorLocal_00cb2ca0& getImag() const
    {
        return m_vec;
    }
    void hkQuaternion_decomposeRestAxis(const QuaternionVectorLocal_00cb2ca0& axis, QuaternionLocal_00cb2ca0& restOut, float& angleOut) const;
};

__declspec(noinline) void copyQuaternionVector(QuaternionVectorLocal_00cb2ca0* out, const QuaternionVectorLocal_00cb2ca0* in)
{
    out->setQuad(in->getQuad());
}
// src: COMMUNITY 0x00c66320
__declspec(noinline) void QuaternionLocal_00cb2ca0::setMul(const QuaternionLocal_00cb2ca0& a, const QuaternionLocal_00cb2ca0& b)
{
    quaternion_simd::LocalM128 u = a.m_vec.getQuad(), v = b.m_vec.getQuad();
    quaternion_simd::LocalM128 cross =
        quaternion_simd::_mm_sub_ps(quaternion_simd::_mm_mul_ps(quaternion_simd::_mm_shuffle_ps(u, u, 0xc9),
                                                                quaternion_simd::_mm_shuffle_ps(v, v, 0xd2)),
                                    quaternion_simd::_mm_mul_ps(quaternion_simd::_mm_shuffle_ps(u, u, 0xd2),
                                                                quaternion_simd::_mm_shuffle_ps(v, v, 0xc9)));
    quaternion_simd::LocalM128 uw = quaternion_simd::_mm_shuffle_ps(u, u, 0xff),
                            vw = quaternion_simd::_mm_shuffle_ps(v, v, 0xff);
    quaternion_simd::LocalM128 xyz = quaternion_simd::_mm_add_ps(quaternion_simd::_mm_mul_ps(uw, v), cross);
    xyz = quaternion_simd::_mm_add_ps(quaternion_simd::_mm_mul_ps(vw, u), xyz);
    quaternion_simd::LocalM128 product = quaternion_simd::_mm_mul_ps(u, v);
    quaternion_simd::LocalM128 yz =
        quaternion_simd::_mm_add_ss(quaternion_simd::_mm_shuffle_ps(product, product, 0x55), product);
    quaternion_simd::LocalM128 dot =
        quaternion_simd::_mm_add_ss(quaternion_simd::_mm_shuffle_ps(product, product, 0xaa), yz);
    dot = quaternion_simd::_mm_shuffle_ps(dot, dot, 0);
    quaternion_simd::LocalM128 real = quaternion_simd::_mm_sub_ps(product, dot);
    QuaternionVectorLocal_00cb2ca0 result;
    result.setQuad(quaternion_simd::_mm_shuffle_ps(xyz, quaternion_simd::_mm_unpackhi_ps(xyz, real), 0xc4));
    copyQuaternionVector(&m_vec, &result);
}

// @fnv 0x00cb2ca0
// src: XBOX_PDB 0x00cb2ca0
void QuaternionLocal_00cb2ca0::hkQuaternion_decomposeRestAxis(const QuaternionVectorLocal_00cb2ca0& axis, QuaternionLocal_00cb2ca0& restOut, float& angleOut) const
{
    restOut = *this;
    restOut.removeAxisComponent(axis);
    QuaternionLocal_00cb2ca0 q;
    q.setInverseMul(restOut, *this);
    float angle = q.GetAngle();
    angleOut = angle;
    QuaternionScalarLocal_00cb2ca0 dot = axis.dot3(q.getImag());
    QuaternionScalarLocal_00cb2ca0 w = q.getReal();
    if (float(w * dot) < float(QuaternionScalarLocal_00cb2ca0(*(const float*)&DAT_01011d78)))
    {
        angleOut = -angle;
    }
}

#include <xmmintrin.h>
}  // namespace fnv_00cb2ca0
namespace fnv_00cb94a0 {
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();
extern float DAT_011b1d3c;
extern float DAT_01015f5c;
extern void* DAT_010c8a2c;
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_012683f4;
extern GlobalObjectO2_00a7b610 g_012043f8;
extern "C" float __fastcall FUN_0062ab20(void* p);
extern void __fastcall FUN_00a6d220(void* p);
struct ChildInner
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
    float unk194;
};
struct ChildObj
{
    int unk00;
    int unk04;
    ChildInner* unk08;
};
struct DynCastHelper
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ChildObj* unk10;
    DynCastHelper* FUN_00653290(const GlobalObjectO2_00a7b610* type);
};
struct MyRTTI;
class bhkForceController;
struct MyHost
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DynCastHelper* unk1c;
    bhkForceController* NiObjectNET_GetController(const MyRTTI* rtti) const;
};
class bhkForceController : public NiTimeController
{
  public:
    LocalM128 unk40;
    float unk50;
    static void operator delete(void*);
    static void* operator new(unsigned int size)
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->Game_DoHeapAlloc(size + 16);
        unsigned char lo = (unsigned char)raw;
        unsigned char pad = 16 - (lo & 15);
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
    bhkForceController() : unk40(*(LocalM128*)&DAT_01267e30), unk50(0.0f)
    {}
    __forceinline void Configure(float duration)
    {
        m_fLoKeyTime = 0.0f;
        unsigned short flags = m_uiObjectFlags;
        m_fHiKeyTime = duration;
        flags = (flags & 0xFFF5) | 5;
        m_fPhase = 0.0f;
        *(volatile unsigned short*)&m_uiObjectFlags = flags;
        m_fFrequency = 1.0f;
    }
};
// @fnv 0x00cb94a0
// src: XBOX_PDB 0x00cb94a0
void __cdecl bhkForceController_TestForce2(MyHost* param1, const LocalM128* param2, float param3)
{
    TlsGuard_t guard;
    bhkForceController* controller = param1->NiObjectNET_GetController((const MyRTTI*)&g_012683f4);
    if (!controller)
    {
        controller = new bhkForceController();
        controller->SetTarget((NiObjectNET*)param1);
    }
    DynCastHelper* castObj =
        !param1->unk1c ? 0 : param1->unk1c->FUN_00653290((const GlobalObjectO2_00a7b610*)&g_012043f8);
    LocalM128 val = *param2;
    if (castObj && castObj->unk10)
    {
        ChildObj* child = castObj->unk10;
        float scale = FUN_0062ab20(child);
        scale = DAT_011b1d3c * scale;
        ChildInner* inner = *(ChildInner* const volatile*)&child->unk08;
        LocalM128 original = *param2;
        LocalM128 r1 = _mm_load1_ps(&scale);
        double s2 = inner->unk194 * 0.75;
        _ReadWriteBarrier();
        LocalM128 first = _mm_mul_ps(r1, val);
        scale = (float)s2;
        LocalM128 r2 = _mm_load_ss(&scale);
        r2 = _mm_shuffle_ps(r2, r2, 0);
        val = _mm_add_ps(_mm_mul_ps(r2, original), first);
    }
    bhkForceController* __restrict output = controller;
    output->Configure(param3);
    output->unk40 = val;
    output->Start(DAT_01015f5c);
}
}  // namespace fnv_00cb94a0
