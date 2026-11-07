#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"
#include "../../include/NiTListItem.h"
#include "../../include/NiTPointerListBase.h"

// src/staging/blk_00c20000_od_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/staging/blk_00c20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00c20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
// The empty forwarding destructor must leave the BSTask vtable installation to its base.
class __declspec(novtable) IOTask;
#include "../../include/AutoMemContext.h"
#include "../../include/BSMultiBoundNode.h"
#include "../../include/NiBound.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTListItem.h"
#include "../../include/IOManager.h"
#include "../../include/IOTask.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiCamera.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiNode.h"
#include "../../include/NiObject.h"
#include "../../include/NiPlane.h"
#include "../../include/NiPoint3.h"
// LocalPoint: unit-local copy of the former shared stand-in Point. Same layout as NiPoint3 with the stand-in's own inline operators; with NiPoint3, FUN_00c358a0/FUN_00c33870 (Point by value, /Ob1) do not match.
class Scalar;
class Vector;

class LocalPoint
{
public:
    float x;
    float y;
    float z;

    __forceinline LocalPoint()
    {
    }
    __forceinline LocalPoint(float px, float py, float pz)
        : x(px), y(py), z(pz)
    {
    }

    float& operator()(int index);
    const float& operator()(int index) const;
    LocalPoint operator+(const LocalPoint& other) const;
    LocalPoint operator-(const LocalPoint& other) const;
    inline LocalPoint operator-() const
    {
        return LocalPoint(-x, -y, -z);
    }
    __forceinline LocalPoint operator*(float scalar) const
    {
        return LocalPoint(scalar * x, scalar * y, scalar * z);
    }
    __forceinline LocalPoint operator/(float scalar) const
    {
        float inverse = 1.0f / scalar;
        return LocalPoint(x * inverse, y * inverse, z * inverse);
    }
    __forceinline LocalPoint& operator+=(const LocalPoint& other)
    {
        x = (float)(other.x + x);
        y = (float)(other.y + y);
        z = (float)(other.z + z);
        return *this;
    }
    __forceinline LocalPoint& operator*=(float scalar)
    {
        x = scalar * x;
        y = scalar * y;
        z = scalar * z;
        return *this;
    }
    inline bool operator==(const LocalPoint& other) const
    {
        return other.x == x && other.y == y && other.z == z;
    }

    LocalPoint ApplyScaled(float scalar);
    LocalPoint Cross(const LocalPoint& other) const;
    float Dot(const LocalPoint& other) const;
    double DotProduct(const LocalPoint& other);
    float Length() const;
    float Distance(LocalPoint* other);
    float GetX();
    float GetY();

    bool HasEqualComponents(const LocalPoint& other) const;
    LocalPoint SubtractIntoVector(const LocalPoint& other);
    LocalPoint FUN_00439e90(const LocalPoint& other);
    void Unitize_004a0c10();
    char* GetViewerString_00a59af0(const char* text);
    float FUN_004a7290() const;
    float FUN_00435e00();
    float AStarSearch_EvaluateValue_006a7f50();

    float& at(int index);
    float at(int index) const;
    void add(const LocalPoint& a, const LocalPoint& b);
    void difference(const LocalPoint& a, const LocalPoint& b);
    void absolute();
    void scale(float scalar);

    void flip();
    void setZero4();
    void setSub4(const LocalPoint& a, const LocalPoint& b);
    void setAdd4(const LocalPoint& a, const LocalPoint& b);
    void setMul4(const Scalar& scalar, const LocalPoint& point);
    void addMul4(const Scalar& scalar, const LocalPoint& point);
    void setCross(const LocalPoint& a, const LocalPoint& b);
    Scalar dot3(const LocalPoint& point) const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    const Vector& pos() const;
    const Vector& dir() const;
};

namespace loader
{
    struct LocalPoint
    {
        float x;
        float y;
        float z;

        LocalPoint(float x, float y, float z);
    };
}
#include "../../include/NiRefObject.h"
#include "../../include/QueuedFile.h"
#include "../../include/QueuedParents.h"
#include "../../include/Setting.h"
#include "../../include/BSCoreMessage.h"
#include "../../include/MemoryManager.h"
#include "../../include/MessageHandler.h"
#include "../../include/NiStream.h"
#include "../../include/NiTArray.h"
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiUpdateData.h"
#include "../../include/RecursiveSpinLock.h"
struct FUN_00c3a090_Class
{
    char __thiscall BSMultiBoundRoom_IsEqual(void* arg);
    char __thiscall IsSameAs(void* arg);
};
extern "C" void* g_01202828;
struct FUN_00c3a610_Class
{
    void* __thiscall BSMultiBoundRoom_GetRTTI();
};
extern MemoryManager g_memoryManager;
struct FUN_00c3a640_Class
{
    void* AllocateStorage_00c3a640(unsigned int size);
};
extern "C" void* g_012043dc;
struct FUN_00c3b9e0_Class
{
    void* __thiscall GetGlobalPointer();
};
extern "C" void* g_012043e4;
struct FUN_00c3ba70_Class
{
    void* __thiscall BSNodeReferences_GetRTTI();
};
int __cdecl Object_ComputeValue_00c3c200();
extern const void* DAT_010c14e8;
extern void __cdecl SetVtableAndProcessState_00c3d930();
struct FUN_00c3c520_class
{
    const void* vtbl;
    void __thiscall SetVirtualTable_00c3c520();
};
extern int DAT_010c1510;
extern int DAT_010c14fc;
struct FUN_00c3f6f0_Class
{
    void LockFreeMap_int64_NiPointer_BSTask_int64_IncrementCount();
};
struct FUN_00c3fc80_class
{
    void __thiscall CallSecondVirtualMethod(void* p);
};
struct FUN_00c35980_Class
{
    int BSOcclusionPlane_GetJoinedPlaneType();
};
struct FUN_00c3a080_Class
{
    void* __thiscall BSMultiBoundRoom_CreateClone(int arg);
};
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
struct FUN_00c3a0c0_Class
{
    void* __thiscall BSMultiBoundNode_GetViewerStrings(unsigned int a);
    void __thiscall AddFirstEmptyFromGlobal(unsigned int a);
};
struct FUN_00c3a100_Class
{
    void __thiscall BSMultiBoundRoom_LinkObject(int);
};
struct FUN_00c3a110_Class
{
    void __thiscall BSMultiBoundRoom_LoadBinary(int arg);
};
struct FUN_00c3a120_Class
{
    void __thiscall BSMultiBoundRoom_SaveBinary(int);
};
struct FUN_00c3a130_Class
{
    char __thiscall BSMultiBoundRoom_RegisterStreamables(void* arg);
};
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c3a140_Class
{
    void __thiscall FUN_00c39770();
    void* __thiscall FUN_00c3a140(unsigned int flags);
};
struct FUN_00c3a620_Class
{
    void __thiscall SetVirtualTableAndProcessState_00c3a620();
};
struct FUN_00c3a6a0_Class
{
    void* __thiscall FUN_00c3a6a0(unsigned int flags);
};
extern char DAT_01202c50[260];
extern char DAT_01202fa0[];
void MessageHandler_SetAllWarningFileNames(const char* src);
extern char DAT_01202a40[0x104];
extern char DAT_01202fa0[0x104];
void __cdecl MessageHandler_SetProgrammerOutputFileName(const char* p);
extern const void* DAT_010c14a8;
MessageHandler* MessageHandler::pHandler;
struct FUN_00c3c070_Class
{
    void* __thiscall std__Ref_count_base__Get_deleter(int arg);
};
extern "C" unsigned char DAT_011af49c;
void __cdecl Object_ProcessEntries_00c3c0c0();
struct FUN_00c3fca0_Class
{
    void __thiscall BSTaskManager_int64_RemoveTask(void* a);
    void __thiscall ProcessStateTransitionFourToFive_00c3fca0(void* p);
};
struct FUN_00c3fe00_Class
{
    void* __thiscall LockFreeMapInterface_LockFreeMapInterface(int a, int b, int c, int d);
};
void __fastcall BSTask_int64_DecRefCount(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FUN_00c416a0_Class
{
    bool __thiscall LockFreeMapInterface_Find_0(int a, int b, int c);
};
struct FUN_00c3fe80_Class : FUN_00c416a0_Class
{
    bool __thiscall LockFreeMapInterface_GetAt(int a, int b, int c, void** out);
};
int __cdecl Setting_DataType_00c33090(const char* p);
typedef void*(__cdecl* PFN_00c3c100)(void*, void*, unsigned int);
extern PFN_00c3c100 DAT_01202d5c;
extern int DAT_01202d70;
void __cdecl MessageHandler_InstallMessageBoxHook();
void __cdecl MessageHandler_RemoveMessageBoxHook();
void* __cdecl MessageHandler_DoMessageBox(void* a, void* b, unsigned int c);
struct FUN_00c465a0;
struct FUN_00c4fb10_shell;
struct FUN_00c61b10;
typedef NiObject*(__cdecl* PFN_NiObjectLoader)(void);
NiObject* __cdecl BSReference_CreateObject();
NiObject* __cdecl BSNodeReferences_CreateObject();
NiObject* __cdecl NiBSBoneLODController_CreateObject();
NiObject* __cdecl BSBound_CreateObject();
NiObject* __cdecl BSXFlags_CreateObject();
NiObject* __cdecl CreateNamedNode();
FUN_00c465a0* __cdecl BSWindModifier_CreateObject();
NiObject* __cdecl CreatePositionModifierObject();
NiObject* __cdecl BSFurnitureMarker_CreateObject();
FUN_00c61b10* __cdecl BSPSysArrayEmitter_CreateObject();
NiObject* __cdecl BSWArray_CreateObject();
NiObject* __cdecl BSDamageStage_CreateObject();
NiObject* __cdecl BSBlastNode_CreateObject();
NiObject* __cdecl BSValueNode_CreateObject();
NiObject* __cdecl BSPSysMultiTargetEmitterCtlr_CreateObject();
NiObject* __cdecl BSMasterParticleSystem_CreateObject();
NiObject* __cdecl BSMultiBound_CreateObject();
NiObject* __cdecl CreateNewObject();
NiObject* __cdecl CreateNewBodyCls();
NiObject* __cdecl CreateBC36500Object();
NiObject* __cdecl BSMultiBoundCapsule_CreateObject();
FUN_00c4fb10_shell* __cdecl BSMultiBoundSphere_CreateObject();
NiObject* __cdecl BSPSysSimpleColorModifier_CreateObject();
NiObject* __cdecl BSDebrisNode_CreateObject();
NiObject* __cdecl CreatePositionModifierInstance();
extern char const g_012043dc_arg0[];
extern char const g_012043e4_arg0[];
extern char const g_012031b8_arg0[];
extern char const g_012031e8_arg0[];
extern char const g_01202de0_arg0[];
extern char const g_012043d4_arg0[];
extern char const g_01202e60_arg0[];
extern char const g_012043c8_arg0[];
extern char const g_012031c4_arg0[];
extern char const g_012043b0_arg0[];
extern char const g_012043a4_arg0[];
extern char const g_01202e8c_arg0[];
extern char const g_01202e7c_arg0[];
extern char const g_01202de8_arg0[];
extern char const g_01203340_arg0[];
extern char const g_0120436c_arg0[];
extern char const g_01202810_arg0[];
extern char const g_01202e74_arg0[];
extern char const g_01202820_arg0[];
extern char const g_01202818_arg0[];
extern char const g_01204398_arg0[];
extern char const g_01203108_arg0[];
extern char const g_01204390_arg0[];
extern char const g_01202e84_arg0[];
extern char const g_01204388_arg0[];
void BSStream_InitLoaders();
extern "C" void __cdecl operator delete(void*, unsigned int);
struct FUN_00c3ba80_Class
{
    void __thiscall FUN_00c3bab0();
    void* __thiscall FUN_00c3ba80(unsigned int flags);
    int a, b, c, d;
};
extern "C" unsigned char DAT_01202d55;
void* __cdecl MessageHandler_DoMessageBox(void*, void*, unsigned int);
void* __cdecl MessageHandler_MenuMessageBoxYesNo(void* a);
extern unsigned char DAT_01202d55;
void* __cdecl MessageHandler_MenuMessageBoxYesNoAll(void* a);
struct GlobalObject_00c3bcf0
{
    ~GlobalObject_00c3bcf0();
    void* __thiscall DestroyAndFree(unsigned int flags);
};
extern MemoryManager g_memoryManager;
struct FUN_00c42f00_Class
{
    void __thiscall DestroyResources();
    void* __thiscall FUN_00c3f130(unsigned int flags);
};
int __cdecl FUN_00ec6130(int value);
struct StateVec3
{
    unsigned int x, y, z;
};
struct StateVec2
{
    unsigned int x, y;
};
struct StateMatrix3
{
    unsigned int entries[9];
};
struct FUN_00c337c0_State
{
    unsigned int unk00;
    unsigned int unk04;
    StateVec3 primary;
    StateVec2 secondary;
    StateMatrix3 transform;
    unsigned int scalar;
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
    unsigned char dirtyE4;
    unsigned char dirtyE5;

    void CopyStateTo(FUN_00c337c0_State* destination, unsigned int unused);
};
struct FUN_00c347d0_Elem
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct FUN_00c347d0_Slot
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int Probe(FUN_00c347d0_Elem* e);
};
struct FUN_00c347d0_Scratch
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
};
struct FUN_00c347d0_Obj
{
    FUN_00c347d0_Slot m_slot[6];
    unsigned int m_uiMask;
};
struct FUN_00c347d0_cls
{
    void Init(FUN_00c347d0_Elem* res);
    bool BSOcclusionPlane_CompletelyWithinFrustum(FUN_00c347d0_Obj* obj);
};
class Node
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};
class Sub08
{
  public:
    unsigned int unk00;
    Node* Acquire();
};
class Mid
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    Sub08 m_08;
    void Consume(Node* n);
};
class Scratch18
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
};
class FUN_00c39a80_cls
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74,
        unk78, unk7c, unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4,
        unkb8, unkbc;
    Mid m_c0;
    void BSMultiBoundRoom_AddOccluder(unsigned int a1);
};
extern "C" int DAT_010c117c;
struct FUN_00c3a220_cls
{
    void* m_vptr;

    void InitBuffer(int a, int b);
    FUN_00c3a220_cls* SetVirtualTable_00c3a220();
};
struct FUN_00c3a350_cls
{
    void** m_pBuffer;
    unsigned int m_uiLogicalSize;
    unsigned int m_iReserved;

    virtual void v0();
    virtual void* Alloc(unsigned int n);

    void InitBuffer(unsigned int a, unsigned int b);
};
struct FUN_00c3a4b0_node
{
    FUN_00c3a4b0_node* m_00;
    void* m_04;
    unsigned int m_08;
};
struct FUN_00c3a4b0_sub
{
    unsigned int m_uiItemCount;
    void __thiscall NiTPointerAllocator_unsigned_int_Deallocate(FUN_00c3a4b0_node* p);
};
struct FUN_00c3a4b0_cls
{
    FUN_00c3a4b0_node* m_00;
    void* m_04;
    FUN_00c3a4b0_sub m_08;
    unsigned int __thiscall RemoveHead();
};
struct FUN_00c3a530_node
{
    FUN_00c3a530_node* m_00;
    FUN_00c3a530_node* m_04;
    void* m_08;
};
struct FUN_00c3a530_alloc
{
    unsigned int m_uiCount;
    void FreeNode(FUN_00c3a530_node* node);
};
struct FUN_00c3a530_cls
{
    FUN_00c3a530_node* m_00;
    FUN_00c3a530_node* m_04;
    FUN_00c3a530_alloc m_08;
    void* RemoveTail();
};
struct FUN_00c3a530_pad
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct S_00c3a5e0
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
    void NiNode_UpdateUpwardPass();
    void FUN_00c3a5e0();
};
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(
    const char* lpAppName, const char* lpKeyName, const char* lpDefault, char* lpReturnedString, unsigned long nSize,
    const char* lpFileName);
PFN_NiObjectLoader __cdecl BSStream_GetCreatorFunction(const char* name);
static const char kLoadersSection[] = "Loaders";
static const char kNoDefault[] = "";
static const char kBackslash[] = "\\";
static const char kIniName[] = "Loaders.ini";
static const char kSpace[] = " ";
void __cdecl LoadObjectLoadersFromIni(const char* dir);
extern "C" int __cdecl _strnicmp(const char* a, const char* b, unsigned int n);
void __cdecl BuildDataPath(char* out, const char* path, const char* suffix);
extern "C" unsigned char DAT_01202b48;
void* __cdecl GetProgramFlowTextPath();
extern char DAT_01202a40[0x104];
char* __cdecl MessageHandler_GetProgrammerOutputFileName();
// FUN_00c3bc70 returns the address of the 0x104-byte scratch buffer that the
// sibling helpers FUN_00c3bc80 (strcpy_s/strcat_s on it) operate on.
extern char DAT_01202938[0x104];
char* __cdecl MessageHandler_GetCrashTraceFileName();
int __cdecl return_0_8();
extern "C" unsigned char DAT_011af49d;
extern "C" unsigned char DAT_011af49e;
extern "C" unsigned char DAT_011af49f;
extern unsigned char DAT_011f6370[0x18];
extern unsigned int DAT_01202d74;
extern unsigned int DAT_011f6388;
void __cdecl MessageHandler_InitSDM();
void __cdecl MessageHandler_Init(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned int e);
int* __cdecl MessageHandler_GetWarningFileName();
int __cdecl BSSystemFile_DeleteFileA(const char* p);
int __cdecl GetFileSize(int* buf, int* out);
struct FUN_00c3bda0_Class : BSCoreMessage
{
    ~FUN_00c3bda0_Class();
};
int Object_ReturnZero_00c3be40();
int __cdecl MessageHandler_Output();
extern "C" __declspec(dllimport) DWORD __stdcall GetCurrentThreadId();
extern "C" void __cdecl CbtHookProc(int code, WPARAM wParam, LPARAM lParam);
extern int DAT_01202d70;
void __cdecl MessageHandler_InstallMessageBoxHook();
void __cdecl MessageHandler_RemoveMessageBoxHook();
extern "C" void* fnv_zlib_memset(void* pvDest, int iValue, int iSize);
typedef void* C3C2B0HWND;
extern int(__stdcall* g_pfnC3C2B0GetClassName)(C3C2B0HWND hWnd, char* pcClassName, int m_iMaximumCount);
extern int(__stdcall* g_pfnC3C2B0GetWindowText)(C3C2B0HWND hWnd, char* pcString, int m_iMaximumCount);
int C3C2B0StrCmp(const char* pcA, const char* pcB);
int __stdcall FindFirstNonCancelButton(C3C2B0HWND hWnd, long lParam);
int __stdcall FindFirstNonCancelButton(void* hwnd, int lParam);
int __stdcall CbtHookProc(int code, unsigned int wParam, int lParam);
struct FUN_00c3c540_Class
{
    int* unk00;
    void __thiscall Resize(int a, int b);
    int* __thiscall QueuedParents_00c3c540();
};
struct C3D3E0Heap
{
    void Deallocate(void* pvMem);
};
extern C3D3E0Heap g_kC3D3E0Heap;
class C3D3E0Palette
{
  public:
    int unk00;

    ~C3D3E0Palette();
    C3D3E0Palette* FUN_00c3d3e0(unsigned int uiFlags);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObject
{
    void* vtable;
    long unk04;
    volatile long refCount;
};
struct Array
{
    virtual ~Array();
    virtual void* Allocate(unsigned int count);
    RefObject** data;
    unsigned int size;
    unsigned int capacity;
    void __thiscall Resize(unsigned int reserve, unsigned int count);
};
class FUN_00c3d870_cls
{
  public:
    virtual void* v0();
    virtual void* v1(void* a);
    virtual void v2(void* a);
    virtual void* v3(void* a, void* b);
    void Helper(void* a, void* b, void* c);
    void QueuedChildren_SetLength(void* a1, void* a2);

    void* m_04;
    unsigned int unk08;
    void* m_0c;
};
struct FUN_00c3f650_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_uiModulus;
    unsigned int Modulo(volatile unsigned int value, unsigned int unused);
};
struct C3F670Timer
{
    unsigned __int64 LockFreeMap_int64_NiPointer_BSTask_int64_GenerateKey(unsigned __int64 uiTicks);
};
struct FUN_00c3f690_pair
{
    int x;
    int y;
};
struct FUN_00c3f690_cls
{
    int unk00;
    void __thiscall CopyPair(FUN_00c3f690_pair p, FUN_00c3f690_pair* out);
};
struct S_00c3f6b0_Class
{
    bool IsGreaterOrEqual(__int64 a, __int64 b);
};
struct FUN_00c3fa70_elem
{
    virtual int vDtor(int flags);
};
struct DynamicMemoryAllocator
{
    void MemoryManager_Deallocate(void* apPtr);
};
extern "C" DynamicMemoryAllocator DAT_011f6238;
struct TeardownBase
{
    virtual void v00();
    ~TeardownBase();
};
struct FUN_00c3fa70_cls : public TeardownBase
{
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
    unsigned int m_uCount4c;
    FUN_00c3fa70_elem** m_ppItems50;
    void* m_p54;

    virtual ~FUN_00c3fa70_cls();
};
struct NiCullingProcess;
struct BoundShape
{
    void AddRef();
};
struct TESBoundObjectBounds
{
    int unk00;
    int unk04;
    int iType;
};
struct BoundHolder
{
    int unk00;
    int unk04;
    int unk08;
    TESBoundObjectBounds* pData;
};
struct CullerData
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
    int iCullMode;
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
    BoundShape* pBound;
};

// src: GUESS 0x00439ef0 (confidence: high)
inline NiPoint3 NiPoint3::SubtractIntoVector(const NiPoint3& other)
{
    return NiPoint3(x - other.x, y - other.y, z - other.z);
}
inline NiPoint3 NiPoint3::FUN_00439e90(const NiPoint3& other)
{
    return NiPoint3(x + other.x, y + other.y, z + other.z);
}
inline NiPoint3 NiPoint3::ApplyScaled(float scale) const
{
    return NiPoint3(scale * x, scale * y, scale * z);
}
struct FNVPlane
{
    NiPoint3 normal;
    float distance;
    float GetPlaneConstant() const
    {
        return distance;
    }
};
struct FNVPlaneSet
{
    FNVPlane plane[6];
    unsigned int enabledFlags;
};
struct FNVClip
{
    bool BSOcclusionShape_TestLineSegmentAllPlanes(NiPoint3* begin, NiPoint3* end, FNVPlane* face, FNVPlaneSet* region);
};
extern const double DAT_01012060;
extern const double DAT_01012070;
extern const double DAT_010c0f58;
// @fnv 0x00c35ae0
// src: COMMUNITY 0x00c35ae0
bool FNVClip::BSOcclusionShape_TestLineSegmentAllPlanes(NiPoint3* begin, NiPoint3* end, FNVPlane* face, FNVPlaneSet* region)
{
    NiPoint3 direction = end->SubtractIntoVector(*begin);
    NiPoint3 normal = face->normal;
    float denom = normal.DotProduct(direction);
    float fraction;
    if (denom == DAT_01012060)
        return false;
    {
        fraction = (face->GetPlaneConstant() - normal.DotProduct(*begin)) / denom;
        if (fraction >= DAT_01012060 && fraction <= DAT_01012070)
        {
            NiPoint3 result = begin->FUN_00439e90(direction.ApplyScaled(fraction));
            for (int i = 0; i < 6; ++i)
            {
                if ((bool)((1 << i) & region->enabledFlags))
                {
                    if (region->plane[i].normal.DotProduct(result) - region->plane[i].GetPlaneConstant() <=
                        DAT_010c0f58)
                        return false;
                }
            }
            return true;
        }
    }
    return false;
}

// NiStream::GetLoader(const char*): look the name up in the static loader map.
// GetAt is an inline template member with two locals; declined inlining at /Od still reserves them.
template <class TVAL> struct NiTStringMapItemL
{
    NiTStringMapItemL* m_pkNext;
    const char* m_key;
    TVAL m_val;
};

template <class TVAL> class NiTStringPointerMapL
{
  public:
    virtual ~NiTStringPointerMapL();
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    unsigned int m_uiHashSize;
    NiTStringMapItemL<TVAL>** m_ppkHashTable;
    unsigned int m_uiCount;
    bool GetAt(const char* key, TVAL& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        NiTStringMapItemL<TVAL>* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(key, pkItem->m_key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};
extern NiTStringPointerMapL<PFN_NiObjectLoader>* DAT_011f4784;

// @fnv 0x00c3b3c0
// src: COMMUNITY 0x00c3b3c0
PFN_NiObjectLoader __cdecl BSStream_GetCreatorFunction(const char* pcName)
{
    PFN_NiObjectLoader pfnLoader = 0;
    DAT_011f4784->GetAt(pcName, pfnLoader);
    return pfnLoader;
}

struct FUN_00a699d0
{
    float x, y, z, w;
    FUN_00a699d0(const LocalPoint&, const LocalPoint&, const LocalPoint&);
    int ClassifyPoint(const LocalPoint*);
};
struct FUN_00a699d0s
{
    FUN_00a699d0 planes[6];
    unsigned int active;
    inline void SetWaterColorParameter(unsigned int i, const FUN_00a699d0& p)
    {
        planes[i] = p;
    }
    inline void DisablePlane(unsigned int i)
    {
        active &= ~(1 << i);
    }
};
struct CornerMatrix
{
    float entries[9];
    LocalPoint operator*(const LocalPoint&) const;
};
struct Builder
{
    int unk00;
    int unk04;
    LocalPoint center;
    float halfWidth;
    float halfHeight;
    CornerMatrix rotation;
    int unk40;
    FUN_00a699d0s cached;
    LocalPoint cachedCorners[4];
    LocalPoint last;
    bool cornersDirty;
    bool dirty;
    unsigned char disabled[4];
// src: COMMUNITY 0x00c35c10
    inline void BSOcclusionPlane_GetVertices(LocalPoint* out)
    {
        if (!cornersDirty)
        {
            memcpy(out, cachedCorners, 48);
            return;
        }
        LocalPoint right(halfWidth, 0, 0);
        LocalPoint up(0, 0, halfHeight);
        CornerMatrix* transform = &rotation;
        right = (*transform) * right;
        up = (*transform) * up;
        out[3] = center - right + up;
        out[2] = center - right - up;
        out[1] = center + right - up;
        out[0] = center + right + up;
        memcpy(cachedCorners, out, 48);
        cornersDirty = false;
    }
    void BSOcclusionPlane_UpdateFrustumPlanes(LocalPoint eye, FUN_00a699d0s* out);
};
// @fnv 0x00c33870
// src: COMMUNITY 0x00c33870
void Builder::BSOcclusionPlane_UpdateFrustumPlanes(LocalPoint eye, FUN_00a699d0s* out)
{
    if (!dirty && last == eye)
    {
        *out = cached;
        return;
    }
    LocalPoint corners5[4];
    BSOcclusionPlane_GetVertices(corners5);
    out->active = 63;
    FUN_00a699d0 test7(corners5[0], corners5[1], corners5[2]);
    if (test7.ClassifyPoint(&eye) != 1)
    {
        out->SetWaterColorParameter(0, FUN_00a699d0(corners5[0], corners5[1], corners5[2]));
        out->DisablePlane(1);
        out->SetWaterColorParameter(2, FUN_00a699d0(corners5[0], corners5[1], eye));
        out->SetWaterColorParameter(3, FUN_00a699d0(corners5[2], corners5[3], eye));
        out->SetWaterColorParameter(4, FUN_00a699d0(corners5[3], corners5[0], eye));
        out->SetWaterColorParameter(5, FUN_00a699d0(corners5[1], corners5[2], eye));
    }
    else
    {
        out->SetWaterColorParameter(0, FUN_00a699d0(corners5[1], corners5[0], corners5[2]));
        out->DisablePlane(1);
        out->SetWaterColorParameter(2, FUN_00a699d0(corners5[1], corners5[0], eye));
        out->SetWaterColorParameter(3, FUN_00a699d0(corners5[3], corners5[2], eye));
        out->SetWaterColorParameter(4, FUN_00a699d0(corners5[0], corners5[3], eye));
        out->SetWaterColorParameter(5, FUN_00a699d0(corners5[2], corners5[1], eye));
    }
    for (int index = 0; index < 4; index++)
    {
        if (disabled[index] == 1)
            out->DisablePlane(index + 2);
    }
    last = eye;
    cached = *out;
    dirty = false;
}

extern int DAT_010c1064;
struct FUN_00c46970
{
    FUN_00c46970();
    virtual ~FUN_00c46970();
};
// 0x00c39640 initializes these by-value buffers at +0xb4, +0xc0 and +0xd0.
// Each occupies 12 bytes with no vptr; NiTPrimitiveArray would occupy 16 and
// move the following members (including the scalar at +0xcc). Keep this layout.
template <class T> struct RoomValueBuffer
{
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMax;
    RoomValueBuffer()
    {
        m_uiMax = 0;
        m_pBase = 0;
        m_uiSize = 0;
    }
    ~RoomValueBuffer();
};
struct MemberX
{
    MemberX();
};
struct FUN_00c39640 : FUN_00c46970
{
    char pad04[0x2c];
    unsigned int m_uiValue1;
    char pad34[0x80];
    RoomValueBuffer<int> m_kA;
    RoomValueBuffer<int> m_kB;
    unsigned int m_uiCC;
    RoomValueBuffer<int> m_kC;
    MemberX m_kCubicCoefficient;
    void SetBit(unsigned int uiMask, bool bVal)
    {
        int aiD[3];
        if (bVal)
            m_uiValue1 |= uiMask;
        else
            m_uiValue1 &= ~uiMask;
    }
    FUN_00c39640();
    virtual ~FUN_00c39640();
};
// @fnv 0x00c39640
FUN_00c39640::FUN_00c39640()
{
    SetBit(0x800, true);
    m_uiCC = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern const char* DAT_011af484[];
extern const char* DAT_0109b220;
extern int DAT_011a9598;
void __cdecl BuildDataPath(char*, const char*, const char*);
bool __cdecl NiFile_Access(const char*, int);
struct TextureObject
{
    virtual void v0();
    virtual void DeleteThis();
    volatile long refs;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct TexturePtr
{
    TextureObject* object;
    __forceinline TexturePtr()
    {
        object = 0;
        if (object)
            object->IncRefCount();
    }
    __forceinline ~TexturePtr()
    {
        if (object)
            object->DecRefCount();
    }
    inline TexturePtr& __thiscall FUN_0066b0d0(TextureObject* other)
    {
        if (object != other)
        {
            if (object)
                object->DecRefCount();
            object = other;
            if (object)
                object->IncRefCount();
        }
        return *this;
    }
};
bool __cdecl FindTextureByPath(char*, TexturePtr*);
void __cdecl FUN_00a61c50(TextureObject*, int);
char* __cdecl FUN_00a5b690(const char*);
TextureObject* __cdecl FUN_00a5fd70(const NiFixedString&, int&, bool, bool);
struct TextureLoader
{
    void __thiscall BSStream_LoadShaderTextures(const char* path);
};
// @fnv 0x00c3b5e0
// src: COMMUNITY 0x00c3b5e0
void TextureLoader::BSStream_LoadShaderTextures(const char* path)
{
    char filename[260];
    for (const char** suffix = DAT_011af484; *suffix; ++suffix)
    {
        BuildDataPath(filename, path, *suffix);
        TexturePtr texture;
        FindTextureByPath(filename, &texture);
        if (!texture.object && NiFile_Access(filename, 0))
        {
            texture.FUN_0066b0d0(FUN_00a5fd70(NiFixedString((const char*)filename), DAT_011a9598, true, false));
            if (texture.object)
                FUN_00a61c50(texture.object, 0);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}


struct QueuedPointer
{
    QueuedFile* pointer;
    QueuedPointer(QueuedFile* p = 0) : pointer(p)
    {
        if (pointer)
        {
            QueuedFile* object = pointer;
            InterlockedIncrement((volatile long*)&object->BackgroundTask);
        }
    }
};

struct BaseArray
{
    QueuedPointer* data;
    unsigned int size;
    unsigned int capacity;
    virtual ~BaseArray();
    virtual QueuedPointer* Allocate(unsigned int count);
    BaseArray()
    {
        Init(5, 0);
    }
    void Init(unsigned int reserve, unsigned int count)
    {
        data = 0;
        size = 0;
        capacity = 0;
        if (count > reserve)
            reserve = count;
        if (reserve > 0)
        {
            data = Allocate(reserve);
            capacity = reserve;
        }
        if (count > 0)
        {
            QueuedPointer* destination = data;
            for (unsigned int i = 0; i < count; ++i)
            {
                QueuedPointer* element = new (destination + i) QueuedPointer;
            }
            size = count;
        }
    }
};

struct FUN_00c3c4e0 : BaseArray
{
    unsigned int children;
    virtual ~FUN_00c3c4e0();
    FUN_00c3c4e0();
};

// @fnv 0x00c3c4e0
FUN_00c3c4e0::FUN_00c3c4e0()
{
    children = 0;
}

struct PoolShell
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
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

struct TlsScope
{
    int saved;
    static int Get()
    {
        return g_tlsBlock.m_2b4;
    }
    static void Set(int value)
    {
        g_tlsBlock.m_2b4 = value;
    }
    TlsScope() : saved(Get())
    {
        Set(6);
    }
    ~TlsScope()
    {
        Set(saved);
    }
};

struct Child10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Child10(int count);
    static void* operator new(unsigned int sz)
    {
        return reinterpret_cast<PoolShell*>(&DAT_011f6238)->Game_DoHeapAlloc(sz);
    }
};

struct SmartRef
{
    int* ptr;
    SmartRef() : ptr(0)
    {
        if (ptr)
            AddRef(ptr);
    }
    static void AddRef(int* object)
    {
        InterlockedIncrement((volatile long*)(object + 2));
    }
};
struct Pair8
{
    int unk00;
    SmartRef unk04;
    Pair8() : unk00(0)
    {}
    static void* operator new(unsigned int sz)
    {
        return reinterpret_cast<PoolShell*>(&DAT_011f6238)->Game_DoHeapAlloc(sz);
    }
};
inline void* operator new[](unsigned int sz)
{
    return reinterpret_cast<PoolShell*>(&DAT_011f6238)->Game_DoHeapAlloc(sz);
}
struct TwoInts
{
    int first;
    int second;
    TwoInts() : first(0), second(0)
    {}
};
struct BaseObj
{
    BaseObj()
    {}
    virtual ~BaseObj()
    {}
    virtual void vfunc0();
};
struct FUN_00c3eeb0 : BaseObj
{
    Pair8* unk04;
    Pair8* unk08;
    int unk0C;
    void* unk10;
    Child10* unk14;
    int unk18;
    int unk1C;
    TwoInts unk20;
    FUN_00c3eeb0(int count, int arg2);
    virtual ~FUN_00c3eeb0();
    virtual void vfunc0();
};
// @fnv 0x00c3eeb0
FUN_00c3eeb0::FUN_00c3eeb0(int count, int arg2)
{
    TlsScope context;
    unk18 = 0;
    unk04 = new Pair8();
    unk08 = unk04;
    unk0C = arg2;
    unk10 = new int[count << 1];
    unk14 = new Child10(count);
}

struct HeapContext_c3f530
{
    int unk000;
};
extern __declspec(thread) int g_iHeapContext_c3f530;

static __forceinline int GetHeap203()
{
    return g_iHeapContext_c3f530;
}
static __forceinline void SetHeap203(int v)
{
    g_iHeapContext_c3f530 = v;
}
struct ScopedHeap_c3f530
{
    int iOld;
    __forceinline ScopedHeap_c3f530(int iNew)
    {
        iOld = GetHeap203();
        SetHeap203(iNew);
    }
    __forceinline ~ScopedHeap_c3f530()
    {
        SetHeap203(iOld);
    }
};

struct Owner_c3f530;

struct Item_c3f530
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
    Item_c3f530(Owner_c3f530* owner, float* x, float* y, float* z);
    void* operator new(unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
};

struct Owner_c3f530
{
    int unk00;
    float* pElementBuffer;
    Item_c3f530* LockFreeMap_int64_NiPointer_BSTask_int64_AllocateInterface(int i);
};

// @fnv 0x00c3f530
// src: COMMUNITY 0x00c3f530
Item_c3f530* Owner_c3f530::LockFreeMap_int64_NiPointer_BSTask_int64_AllocateInterface(int i)
{
    ScopedHeap_c3f530 heap(6);
    return new Item_c3f530(this, &pElementBuffer[i * 3], &pElementBuffer[i * 3 + 1], &pElementBuffer[i * 3 + 2]);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pl);
struct RefX
{
    virtual void v00();
    int m_i04;
    long m_lRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void BSTask_int64_DecRefCount();
};
struct SPX
{
    RefX* m_pObject;
    SPX(const SPX& kOther)
    {
        int aiD[2];
        m_pObject = kOther.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SPX()
    {
        int aiE[3];
        if (m_pObject)
            m_pObject->BSTask_int64_DecRefCount();
    }
};
struct LockX
{
    int m_iOwner;
    int m_iArrayLength;
    void BSSpinLock_Lock(int i);
    void Unlock()
    {
        if (--m_iArrayLength == 0)
            m_iOwner = 0;
    }
};
struct ListQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05();
    virtual bool Test(unsigned int uiIndex, SPX pSceneObject);
    int m_i04;
    unsigned int m_uiCount;
    char pad0c[0x14];
    LockX m_kLock;
    bool LockFreeMap_int64_NiPointer_BSTask_int64_Func07(SPX pSceneObject);
};
// @fnv 0x00c3f960
// src: COMMUNITY 0x00c3f960
bool ListQ::LockFreeMap_int64_NiPointer_BSTask_int64_Func07(SPX pSceneObject)
{
    bool bFound = false;
    m_kLock.BSSpinLock_Lock(0);
    for (unsigned int i = 0; i < m_uiCount && !bFound; i++)
        bFound = Test(i, pSceneObject);
    m_kLock.Unlock();
    return bFound;
}

#include <math.h>

inline NiPoint3::NiPoint3(float x0, float y0, float z0) : x(x0), y(y0), z(z0)
{}
inline int NiPlane::Side(const FNVVec3& point) const
{
    float distance = x * reinterpret_cast<const NiPoint3&>(point).x +
                     y * reinterpret_cast<const NiPoint3&>(point).y +
                     z * reinterpret_cast<const NiPoint3&>(point).z - c;
    if (distance < 0.0)
        return 2;
    else if (distance > 0.0)
        return 1;
    else
        return 0;
}
namespace fnv_00c33cf0 {
extern const NiPoint3 NiPoint3_ZERO;
struct ClipMatrix
{
    float values[3][3];
    inline NiPoint3 operator*(const NiPoint3& point) const
    {
        return NiPoint3(values[0][0] * point.x + values[0][1] * point.y + values[0][2] * point.z,
                        values[1][0] * point.x + values[1][1] * point.y + values[1][2] * point.z,
                        values[2][0] * point.x + values[2][1] * point.y + values[2][2] * point.z);
    }
    __forceinline void GetRow(unsigned row, NiPoint3& out) const
    {
        out.x = values[row][0];
        out.y = values[row][1];
        out.z = values[row][2];
    }
};
struct ClipVolume
{
    NiPlane planes[6];
    unsigned mask;
};
struct RectangleClip
{
    int unk00, unk04;
    NiPoint3 center;
    float halfWidth, halfHeight;
    ClipMatrix rotation;
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
    NiPoint3 cached[4];
    int unkd8;
    int unkdc;
    int unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
// src: COMMUNITY 0x00c35c10
    inline void BSOcclusionPlane_GetVertices(NiPoint3* out)
    {
        if (!dirty)
        {
            memcpy(out, cached, sizeof(cached));
            return;
        }
        NiPoint3 horizontal(halfWidth, 0, 0);
        NiPoint3 vertical(0, 0, halfHeight);
        horizontal = rotation * horizontal;
        vertical = rotation * vertical;
        out[3] = center - horizontal + vertical;
        out[2] = center - horizontal - vertical;
        out[1] = center + horizontal - vertical;
        out[0] = center + horizontal + vertical;
        memcpy(cached, out, sizeof(cached));
        dirty = false;
    }
    bool BSOcclusionShape_TestLineSegmentAllPlanes(NiPoint3*, NiPoint3*, void*, void*);
    bool BSOcclusionPlane_WithinFrustum(ClipVolume* volume, bool testCenter, NiPoint3 point);
};
// @fnv 0x00c33cf0
// src: COMMUNITY 0x00c33cf0
bool RectangleClip::BSOcclusionPlane_WithinFrustum(ClipVolume* volume, bool testCenter, NiPoint3 point)
{
    NiPoint3 corners[4];
    BSOcclusionPlane_GetVertices(corners);
    int masks[4];
    masks[0] = masks[1] = masks[2] = masks[3] = 0;
    for (int plane = 0; plane < 6; plane++)
    {
        if (bool(volume->mask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 4; vertex++)
            {
                if (volume->planes[plane].Side(reinterpret_cast<const FNVVec3&>(corners[vertex])) != 2)
                {
                    outside = false;
                }
                else
                {
                    masks[vertex] |= 1 << plane;
                }
            }
            if (outside)
                return false;
        }
    }
    edge0 = (masks[0] & masks[1]) != 0;
    edge1 = (masks[3] & masks[2]) != 0;
    edge2 = (masks[0] & masks[3]) != 0;
    edge3 = (masks[2] & masks[1]) != 0;
    bool needsTest = false;
    if (edge0 && edge1 && edge2 && edge3)
        needsTest = true;
    else if (!edge0 && edge1 && edge2 && edge3)
    {
        bool hit0 = false;
        for (int plane0 = 2; plane0 < 6; plane0++)
        {
            if (BSOcclusionShape_TestLineSegmentAllPlanes(&corners[0], &corners[1], &volume->planes[plane0], volume))
            {
                hit0 = true;
                break;
            }
        }
        if (!hit0)
            needsTest = true;
    }
    else if (edge0 && !edge1 && edge2 && edge3)
    {
        bool hit1 = false;
        for (int plane1 = 2; plane1 < 6; plane1++)
        {
            if (BSOcclusionShape_TestLineSegmentAllPlanes(&corners[3], &corners[2], &volume->planes[plane1], volume))
            {
                hit1 = true;
                break;
            }
        }
        if (!hit1)
            needsTest = true;
    }
    else if (edge0 && edge1 && !edge2 && edge3)
    {
        bool hit2 = false;
        for (int plane2 = 2; plane2 < 6; plane2++)
        {
            if (BSOcclusionShape_TestLineSegmentAllPlanes(&corners[0], &corners[3], &volume->planes[plane2], volume))
            {
                hit2 = true;
                break;
            }
        }
        if (!hit2)
            needsTest = true;
    }
    else if (edge0 && edge1 && edge2 && !edge3)
    {
        bool hit3 = false;
        for (int plane3 = 2; plane3 < 6; plane3++)
        {
            if (BSOcclusionShape_TestLineSegmentAllPlanes(&corners[2], &corners[1], &volume->planes[plane3], volume))
            {
                hit3 = true;
                break;
            }
        }
        if (!hit3)
            needsTest = true;
    }
    if (needsTest)
    {
        for (int planeLast = 2; planeLast < 6; planeLast++)
        {
            if (BSOcclusionShape_TestLineSegmentAllPlanes(&corners[0], &corners[2], &volume->planes[planeLast], volume) ||
                BSOcclusionShape_TestLineSegmentAllPlanes(&corners[1], &corners[3], &volume->planes[planeLast], volume))
                return true;
        }
        if (testCenter)
        {
            NiPoint3 delta = point - center;
            NiPoint3 axis = NiPoint3_ZERO;
            rotation.GetRow(0, axis);
            float vec = fabsf(delta.Dot(axis));
            rotation.GetRow(1, axis);
            float height = fabsf(delta.Dot(axis));
            if (vec <= halfWidth && height <= halfHeight)
                return true;
        }
        return false;
    }
    return true;
}

}  // namespace fnv_00c33cf0
namespace fnv_00c34350 {
struct ClipMatrix
{
    float values[3][3];
    inline NiPoint3 operator*(const NiPoint3& point) const
    {
        return NiPoint3(values[0][0] * point.x + values[0][1] * point.y + values[0][2] * point.z,
                        values[1][0] * point.x + values[1][1] * point.y + values[1][2] * point.z,
                        values[2][0] * point.x + values[2][1] * point.y + values[2][2] * point.z);
    }
};
struct ClipVolume
{
    NiPlane planes[6];
    unsigned mask;
};
struct RectangleClip
{
    int unk00, unk04;
    NiPoint3 center;
    float halfWidth, halfHeight;
    ClipMatrix rotation;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4;
    NiPoint3 cached[4];
    int unkd8, unkdc, unke0;
    bool dirty, unkE5, edge0, edge1, edge2, edge3;
// src: COMMUNITY 0x00c35c10
    inline void BSOcclusionPlane_GetVertices(NiPoint3* out)
    {
        if (!dirty)
        {
            memcpy(out, cached, sizeof(cached));
            return;
        }
        NiPoint3 horizontal(halfWidth, 0, 0);
        NiPoint3 vertical(0, 0, halfHeight);
        horizontal = rotation * horizontal;
        vertical = rotation * vertical;
        out[3] = center - horizontal + vertical;
        out[2] = center - horizontal - vertical;
        out[1] = center + horizontal - vertical;
        memcpy(cached, out, sizeof(cached));
        dirty = false;
    }
    unsigned char BSPortal_WithinFrustumFullTest(ClipVolume* volume);
};
// @fnv 0x00c34350
// src: COMMUNITY 0x00c34350
unsigned char RectangleClip::BSPortal_WithinFrustumFullTest(ClipVolume* volume)
{
    NiPoint3 corners[4];
    BSOcclusionPlane_GetVertices(corners);
    int masks[4];
    masks[0] = masks[1] = masks[2] = masks[3] = 0;
    unsigned char needsTest = 1;
    for (int plane = 0; plane < 6; plane++)
    {
        if (bool(volume->mask & (1 << plane)))
        {
            bool outside = true;
            for (int vertex = 0; vertex < 4; vertex++)
            {
                if (volume->planes[plane].Side(reinterpret_cast<const FNVVec3&>(corners[vertex])) != 2)
                    outside = false;
                else
                    masks[vertex] |= 1 << plane;
            }
            if (outside)
                needsTest = 0;
        }
    }
    edge0 = (masks[0] & masks[1]) != 0;
    edge1 = (masks[3] & masks[2]) != 0;
    edge2 = (masks[0] & masks[3]) != 0;
    edge3 = (masks[2] & masks[1]) != 0;
    return needsTest;
}
}  // namespace fnv_00c34350

namespace fnv_00c344c0 {
extern "C" double __cdecl sqrt(double);
extern const NiPoint3 NiPoint3_ZERO;
extern "C" double __cdecl fabs(double);
inline float fabs(float f)
{
    return (float)fabs((double)f);
}
struct ClipPlane
{
    NiPoint3 normal;
    float constant;
    ClipPlane(const NiPoint3&, const NiPoint3&, const NiPoint3&);
    inline float GetPlaneConstant() const
    {
        return constant;
    }
    inline float Distance(const NiPoint3& p) const
    {
        return normal.Dot(p) - constant;
    }
};
struct ClipMatrix
{
    float entries[3][3];
    NiPoint3 operator*(const NiPoint3&) const;
    inline void GetColumn(unsigned int col, NiPoint3& out) const
    {
        out.x = entries[col][0];
        out.y = entries[col][1];
        out.z = entries[col][2];
    }
};
extern const double DAT_01072f80;
extern int g_012030b0;
struct SSNode
{
    virtual void v0();
    virtual void v1();
    virtual const void* GetType();
    int unk04;
    NiPoint3 center;
    float extentX, extentY;
    ClipMatrix orientation;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4;
    NiPoint3 cache[4];
    int unkd8, unkdc, unke0;
    bool dirty;
// src: COMMUNITY 0x00c35c10
    inline void BSOcclusionPlane_GetVertices(NiPoint3* out)
    {
        if (!dirty)
            memmove(out, cache, 48);
        else
        {
            NiPoint3 a(extentX, 0.0f, 0.0f);
            NiPoint3 b(0.0f, 0.0f, extentY);
            a = orientation * a;
            b = orientation * b;
            out[3] = center - a + b;
            out[2] = center - a - b;
            out[1] = center + a - b;
            out[0] = center + a + b;
            memmove(cache, out, 48);
            dirty = false;
        }
    }
    bool BSOcclusionPlane_WithinFrustum(void*, int, NiPoint3);
    bool BSOcclusionPlane_WithinFrustumDistFirst(void*, const NiPoint3&);
    inline bool IsExactType()
    {
        if (!this)
            return false;
        return GetType() == &g_012030b0;
    }
};
inline float ClipAbs(float f)
{
    return (double)(float)fabs((double)f);
}
inline float DistanceFromFirst(void* data, int index, const NiPoint3& point)
{
    const ClipPlane* selected = &((ClipPlane*)data)[index];
    return selected->Distance(point);
}
// @fnv 0x00c344c0
// src: COMMUNITY 0x00c344c0
bool SSNode::BSOcclusionPlane_WithinFrustumDistFirst(void* planes, const NiPoint3& point)
{
    NiPoint3 verticesTmp[4];
    BSOcclusionPlane_GetVertices(verticesTmp);
    ClipPlane plane3(verticesTmp[0], verticesTmp[1], verticesTmp[2]);
    float distance2 = plane3.Distance(point);
    NiPoint3 projected8 = point + (-distance2 * plane3.normal);
    distance2 += DistanceFromFirst(planes, 0, point);
    if (distance2 >= -5.0 && distance2 < 5.0)
    {
        NiPoint3 axisX = NiPoint3_ZERO;
        NiPoint3 axisY4 = NiPoint3_ZERO;
        orientation.GetColumn(0, axisX);
        orientation.GetColumn(1, axisY4);
        float x5 = projected8.Dot(axisX) - center.x;
        float y4 = projected8.Dot(axisY4) - center.y;
        if (ClipAbs(x5) <= extentX && ClipAbs(y4) <= extentY)
        {
            if (IsExactType())
                return true;
            else
                return false;
        }
    }
    return BSOcclusionPlane_WithinFrustum(planes, 1, projected8);
}
}  // namespace fnv_00c344c0

inline NiPoint3 NiPoint3::operator-(const NiPoint3& pt) const
{
    return NiPoint3(x - pt.x, y - pt.y, z - pt.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& pt) const
{
    return NiPoint3(x + pt.x, y + pt.y, z + pt.z);
}
inline NiPoint3 NiPoint3::operator*(float f) const
{
    return NiPoint3(x * f, y * f, z * f);
}
inline const NiPoint3& NiPlane::GetPlaneNormal() const
{
    return *(const NiPoint3*)&x;
}
inline float NiPlane::GetPlaneConstant() const
{
    return c;
}
namespace fnv_00c359d0 {
class SegmentPlaneTester
{
  public:
    bool UpdateState_00c359d0(const NiPoint3& kStart, const NiPoint3& kEnd, const NiPlane& m_kFogPlane, const NiPlane& kBound0,
                      const NiPlane& kBound1);
};

// @fnv 0x00c359d0
// src: GUESS 0x00c359d0 (confidence: low)
bool SegmentPlaneTester::UpdateState_00c359d0(const NiPoint3& kStart, const NiPoint3& kEnd, const NiPlane& m_kFogPlane,
                                      const NiPlane& kBound0, const NiPlane& kBound1)
{
    NiPoint3 kDir4 = kEnd - kStart;
    NiPoint3 kNormal2;
    *(StateVec3*)&kNormal2 = *(const StateVec3*)&m_kFogPlane.GetPlaneNormal();
    float fDenom = kNormal2.Dot(kDir4);
    if (fDenom == 0.0)
        return false;

    float fT5 = (m_kFogPlane.GetPlaneConstant() - kNormal2.Dot(kStart)) / fDenom;
    if (fT5 >= 0.0 && fT5 <= 1.0)
    {
        NiPoint3 kPoint = kStart + kDir4 * fT5;
        if (kBound0.GetPlaneNormal().Dot(kPoint) - kBound0.GetPlaneConstant() >= -0.0001)
        {
            if (kBound1.GetPlaneNormal().Dot(kPoint) - kBound1.GetPlaneConstant() >= -0.0001)
                return true;
        }
    }
    return false;
}
}  // namespace fnv_00c359d0


inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}
__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
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
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
class MbShape : public NiRefObject
{
};

class FUN_00c35eb0 : public NiRefObject
{
  public:
    int unk08;
    NiPointer<MbShape> m_spTransformData;
    virtual ~FUN_00c35eb0();
};

// @fnv 0x00c35eb0
FUN_00c35eb0::~FUN_00c35eb0()
{
    m_spTransformData = 0;
}

namespace fnv_00c39560 {

extern "C" double __cdecl _fabs(double);
extern const double DAT_01016408;

inline float AbsF(float v)
{
    return ((void)v, (float)_fabs((double)v));
}

class FUN_00c39560_Class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    NiPoint3 center;
    NiPoint3 extents;
    bool BSMultiBoundAABB_FastPointWithin(NiPoint3 point);
};

// @fnv 0x00c39560
// src: COMMUNITY 0x00c39560
bool FUN_00c39560_Class::BSMultiBoundAABB_FastPointWithin(NiPoint3 point)
{
    NiPoint3 pointDelta = point.Sub(center);
    float uX;
    float sZ;
    float xY;
    float inX;
    float nX;
    float oy;
    float dstY;
    float az;
    float lz;
    return ((inX = pointDelta.x), (nX = AbsF(inX)), !(nX - extents.x > DAT_01016408)) &&
           ((oy = pointDelta.y), (dstY = AbsF(oy)), !(dstY - extents.y > DAT_01016408)) &&
           ((az = pointDelta.z), (lz = AbsF(az)), !(lz - extents.z > DAT_01016408));
}
}  // namespace fnv_00c39560

struct Base_00c46af0
{
    virtual ~Base_00c46af0();
    void FlushRef();
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
};

struct ListItem
{
    ListItem* next;
    ListItem* prev;
    void* value;
};
struct List_b4_base
{
    ListItem* head;
    ListItem* tail;
    unsigned count;
    inline ~List_b4_base()
    {}
};
struct List_b4 : List_b4_base
{
    inline ~List_b4()
    {
        FUN_00b71300();
    }
    void FUN_00b71300();
    void DeleteItem(ListItem*);
    void Deallocate(ListItem*);
};

struct List_c0_base
{
    ListItem* head;
    ListItem* tail;
    unsigned count;
    int unk0C;
    inline ~List_c0_base()
    {}
};
struct List_c0 : List_c0_base
{
    inline ~List_c0()
    {
        FUN_004ed900();
    }
    void FUN_004ed900();
    void DeleteItem(ListItem*);
};

struct Map_d0_base
{
    ListItem* head;
    ListItem* tail;
    unsigned count;
    inline ~Map_d0_base()
    {}
};
struct Map_d0 : Map_d0_base
{
    inline ~Map_d0()
    {
        ProcessEntries_00c3a2e0();
    }
    void ProcessEntries_00c3a2e0();
    void DeleteItem(ListItem*);
};

inline void List_b4::DeleteItem(ListItem* item)
{
    item->value = 0;
    Deallocate(item);
}

inline void List_b4::FUN_00b71300()
{
    List_b4* self = this;
    ListItem* current = head;
    while (current)
    {
        ListItem* item = current;
        current = current->next;
        self->DeleteItem(item);
    }
    count = 0;
    head = 0;
    tail = 0;
}
inline void List_c0::FUN_004ed900()
{
    ListItem* current = head;
    while (current)
    {
        ListItem* item = current;
        current = current->next;
        DeleteItem(item);
    }
    count = 0;
    head = 0;
    tail = 0;
}
// src: GUESS 0x00c3a2e0 (confidence: low)
inline void Map_d0::ProcessEntries_00c3a2e0()
{
    Map_d0* self = this;
    ListItem* current = head;
    while (current)
    {
        ListItem* item = current;
        ListItem* next = current->next;
        current = next;
        self->DeleteItem(item);
    }
    self->count = 0;
    self->head = 0;
    self->tail = 0;
}

struct Array_dc
{
    virtual ~Array_dc();
    virtual void Allocate();
    virtual void Deallocate(void*);
    void* data;
    unsigned size;
    unsigned capacity;
// src: GUESS 0x00b5af80 (confidence: low)
    inline void UpdateFields_00b5af80(bool b)
    {
        void* allocation = data;
        if (allocation)
        {
            if (b)
            {
                Deallocate(allocation);
                data = 0;
                capacity = 0;
            }
            size = 0;
        }
    }
};

class FUN_00c39770 : public Base_00c46af0
{
  public:
    List_b4 m_b4;
    List_c0 m_c0;
    Map_d0 m_d0;
    Array_dc m_dc;
    virtual ~FUN_00c39770();
};

// @fnv 0x00c39770
FUN_00c39770::~FUN_00c39770()
{
    m_b4.FUN_00b71300();
    m_c0.FUN_004ed900();
    m_d0.ProcessEntries_00c3a2e0();
    m_dc.UpdateFields_00b5af80(true);
    if (m_c0.unk0C)
        FlushRef();
}

struct Handler39
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
    virtual unsigned char v8c(void* arg);
};

struct Node39
{
    Node39* next;
    int prev;
    Handler39* item;
};

struct Owner39
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8;
    Handler39* handler;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    Node39* head;
    int tail;
    unsigned int count;
    unsigned char BSMultiBoundRoom_QPointWithin(void* arg);
};

inline Handler39* Pass39(Handler39* p)
{
    return p;
}

// @fnv 0x00c39b00
// src: XBOX_PDB 0x00c39b00
unsigned char Owner39::BSMultiBoundRoom_QPointWithin(void* arg)
{
    unsigned char Dir;
    Node39* CN;
    Handler39* CN2;
    Handler39* PN;
    Node39* CSA;
    Handler39** EndLoc;
    PN = handler;
    Dir = Pass39(PN)->v8c(arg);
    if (!Dir)
    {
        if (!(unsigned char)(unsigned int)(count == 0))
        {
            CSA = head;
            CN = CSA;
            while (!Dir && CN != 0)
            {
                EndLoc = &CN->item;
                CN = CN->next;
                CN2 = *EndLoc;
                Dir = CN2->v8c(arg);
            }
        }
    }
    return Dir;
}

class TargetC39B
{
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
    virtual int Process(void* pvArg);
};

class HolderC39B
{
  public:
    TargetC39B* GetTarget()
    {
        TargetC39B* p = m_pkTarget;
        return p;
    }
    int unk00;
    int unk04;
    int unk08;
    TargetC39B* m_pkTarget;
};

typedef void* NiTListIteratorC39B;

// Unlike NiTPointerList (12 bytes), this list has a leading word: head +4, tail +8, count +12 in 0x00c39bb0.
template <class T> class ChildHolderList
{
  public:
    bool IsEmpty() const
    {
        return m_uiCount == 0;
    }
    NiTListIteratorC39B GetHeadPos() const
    {
        return m_pkHead;
    }
    T GetNext(NiTListIteratorC39B& kPos) const
    {
        T* element = &((NiTListItem<T>*)kPos)->m_element;
        kPos = ((NiTListItem<T>*)kPos)->m_pkNext;
        return *element;
    }
    void* m_pVTable;
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;
};

class OwnerC39B
{
  public:
    HolderC39B* GetHolder()
    {
        HolderC39B* p = m_pkHolder;
        return p;
    }
    int BSMultiBoundRoom_CheckBound(void* pvArg);

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
    HolderC39B* m_pkHolder;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    ChildHolderList<HolderC39B*> m_kChildList;
};

// @fnv 0x00c39bb0
// src: XBOX_PDB 0x00c39bb0
int OwnerC39B::BSMultiBoundRoom_CheckBound(void* pvArg)
{
    int iResult = GetHolder()->GetTarget()->Process(pvArg);
    if (iResult != 1 && !m_kChildList.IsEmpty())
    {
        NiTListIteratorC39B kPos = m_kChildList.GetHeadPos();
        while (iResult != 1 && kPos)
        {
            HolderC39B* pkChild = m_kChildList.GetNext(kPos);
            int node = pkChild->GetTarget()->Process(pvArg);
            if (node)
                iResult = node;
        }
    }
    return iResult;
}

inline NiBound::NiBound()
{
}
extern NiBound DAT_011f4288;
struct BoundProvider144
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void GetBound(NiBound&);
};
struct Controller144
{
    int unk00, unk04, unk08;
    BoundProvider144* provider;
};
struct Link144
{
    Link144* next;
    int unk04;
    Controller144* controller;
};
struct Node144
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    NiBound* bound;
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
    Node144** children;
    unsigned short capacity, size, used, grow;
    Controller144* controller;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    Link144* head;
    int unkD4;
    unsigned int count;
    void FUN_005467e0();
    void BSMultiBoundRoom_UpdateWorldBound();
    bool Flag80000()
    {
        return (unk30 & 0x80000) ? 1 : 0;
    }
};
// @fnv 0x00c39d50
// src: XBOX_PDB 0x00c39d50
void Node144::BSMultiBoundRoom_UpdateWorldBound()
{
    const NiBound* a0;
    float aAcoustic;
    Node144** aATmp;
    NiBound* a2;
    float aAction;
    const NiBound* aA6;
    int a114;
    int a3;
    int aActorList;
    float aActive;
    Node144** aAct;
    NiBound* a4;
    BoundProvider144* a2_3;
    Controller144* a1c8;
    Controller144** aAVal;
    Link144* aAB;
    int aAEPos;
    int a60;
    int a5;
    BoundProvider144* aA3;
    Controller144* aAX;
    Controller144* a9;
    Node144* a7;
    unsigned int a8;
    unsigned int aA5;
    NiBound aA;
    Link144* aA2;
    BoundProvider144* aAa;
    bool first;
    first = true;
    a9 = controller;
    if (a9)
    {
        aAX = controller;
        aA3 = aAX->provider;
        aAa = aA3;
        if (aAa)
        {
            FUN_005467e0();
            aAa->GetBound(*bound);
            if (!(unsigned char)(unsigned int)(count == 0))
            {
                aAB = head;
                aA2 = aAB;
                while (aA2)
                {
                    aAVal = &aA2->controller;
                    aA2 = aA2->next;
                    a1c8 = *aAVal;
                    a2_3 = a1c8->provider;
                    aAa = a2_3;
                    aAa->GetBound(aA);
                    bound->NiBound_Merge(&aA);
                }
            }
            first = false;
        }
    }
    if (first)
    {
        if (bound && Flag80000())
        {
            a4 = bound;
            a4->radius = 0.0f;
        }
        a8 = size;
        for (aA5 = 0; aA5 < a8; ++aA5)
        {
            aAct = &children[aA5];
            a7 = *aAct;
            if (a7 && ((a7->bound && ((aActive = a7->bound->radius), (double)aActive != 0.0)) ? 1 : 0))
            {
                FUN_005467e0();
                aA6 = a7->bound ? a7->bound : &DAT_011f4288;
                a2 = bound;
                aAction = aA6->radius;
                a2->m_kCenter = aA6->m_kCenter;
                a2->radius = aAction;
                ++aA5;
                break;
            }
        }
        for (; aA5 < a8; ++aA5)
        {
            aATmp = &children[aA5];
            a7 = *aATmp;
            if (a7 && ((a7->bound && ((aAcoustic = a7->bound->radius), (double)aAcoustic != 0.0)) ? 1 : 0))
            {
                a0 = a7->bound ? a7->bound : &DAT_011f4288;
                bound->NiBound_Merge(a0);
            }
        }
    }
}

struct S00c3a180_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

    void FUN_004ed900();
    void ProcessState_00c3a180();
};

struct S00c3a180_Scope
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    __forceinline ~S00c3a180_Scope()
    {}
};

// @fnv 0x00c3a180
// src: GUESS 0x00c3a180 (confidence: low)
void S00c3a180_cls::ProcessState_00c3a180()
{
    S00c3a180_Scope s;
    FUN_004ed900();
}

struct ScopeGuardA3a1
{
    __forceinline ~ScopeGuardA3a1()
    {}
};

struct FUN_00c3a1d0_cls
{
    void ProcessEntries_00c3a2e0();
    void ProcessState_00c3a1d0();
};

// @fnv 0x00c3a1d0
// src: GUESS 0x00c3a1d0 (confidence: low)
void FUN_00c3a1d0_cls::ProcessState_00c3a1d0()
{
    int s0, s1, s2, s3, s4, s5;
    ScopeGuardA3a1 guard;
    ProcessEntries_00c3a2e0();
}

typedef NiTListItem<void* > Node250;

struct Alloc250
{

    void Deallocate(void* p);
};

typedef NiTPointerListBase<Alloc250, void* > List250;
template <> inline void* NiTListBase<Alloc250, void* >::GetHeadPos() const
{
        return m_pkHead;
    }
template <> inline void* NiTPointerListBase<Alloc250, void* >::FindPos(void* const& element, void* kStart) const
{
        void* kPrevNode;
        if (kStart == 0)
        {
            Node250* head = (Node250*)GetHeadPos();
            kStart = head;
        }
        while (kStart)
        {
            kPrevNode = kStart;
            void** pElement = &((Node250*)kStart)->m_element;
            kStart = ((Node250*)kStart)->m_pkNext;
            if (element == *pElement)
                return kPrevNode;
        }
        return 0;
    }
template <> inline void* NiTPointerListBase<Alloc250, void* >::RemoveHead()
{
        Node250* pkItem = m_pkHead;
        m_pkHead = m_pkHead->m_pkNext;
        if (m_pkHead)
            m_pkHead->m_pkPrev = 0;
        else
            m_pkTail = 0;
        void* element = pkItem->m_element;
        pkItem->m_element = 0;
        m_kItemCount.Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
        return element;
    }
template <> inline void* NiTPointerListBase<Alloc250, void* >::RemoveTail()
{
        Node250* pkItem = m_pkTail;
        m_pkTail = m_pkTail->m_pkPrev;
        if (m_pkTail)
            m_pkTail->m_pkNext = 0;
        else
            m_pkHead = 0;
        void* element = pkItem->m_element;
        pkItem->m_element = 0;
        m_kItemCount.Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
        return element;
    }
template <> inline void* NiTPointerListBase<Alloc250, void* >::RemovePos(void*& kPos)
{
        int slot0 = 0;
        int slot1 = 0;
        int slot2 = 0;
        int slot3 = 0;
        int slot4 = 0;
        int slot5 = 0;
        int slot6 = 0;
        (void)slot0;
        (void)slot1;
        (void)slot2;
        (void)slot3;
        (void)slot4;
        (void)slot5;
        (void)slot6;
        Node250* pkItem = (Node250*)kPos;
        if (pkItem == m_pkHead)
        {
            kPos = pkItem->m_pkNext;
            return RemoveHead();
        }
        else if (pkItem == m_pkTail)
        {
            kPos = 0;
            return RemoveTail();
        }
        Node250* pkPrev = pkItem->m_pkPrev;
        Node250* pkNext = pkItem->m_pkNext;
        kPos = pkNext;
        if (pkPrev)
            pkPrev->m_pkNext = pkNext;
        if (pkNext)
            pkNext->m_pkPrev = pkPrev;
        void* element = pkItem->m_element;
        pkItem->m_element = 0;
        m_kItemCount.Deallocate(pkItem);
        m_kItemCount.m_uiCount--;
        return element;
    }

// @fnv 0x00c3a250
template <> void* NiTPointerListBase<Alloc250, void* >::Remove(void* const& element)
{
    void* kPos = FindPos(element);
    return kPos ? RemovePos(kPos) : element;
}

template <class T> class StagingPointerAllocator
{
public:
    void Deallocate(void* pointer);
};
template <class T> inline void StagingPointerAllocator<T>::Deallocate(void* pointer)
{
    unsigned a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;
    a0 = 1;
    a1 = 2;
    a2 = 3;
    a3 = 4;
    a4 = 5;
    a5 = 6;
    a6 = 7;
    a7 = 8;
    a8 = 9;
    a9 = 10;
    a10 = 11;
    a11 = 12;
    a12 = 13;
    if (pointer == 0)
    {
        return;
    }
    Deallocate((void*)((char*)pointer + a0));
}

typedef NiTListItem<void* > FNVPointerListItem;
typedef NiTListBase<StagingPointerAllocator<unsigned int>, void*> FNVPointerListBase;
typedef NiTPointerListBase<StagingPointerAllocator<unsigned int>, void* > FUN_00c3a3f0_cls;


// @fnv 0x00c3a3f0
template <> void* NiTPointerListBase<StagingPointerAllocator<unsigned int>, void* >::RemovePos(void*& position)
{
    FNVPointerListItem* node = (FNVPointerListItem*)position;
    if (node == m_pkHead)
    {
        position = node->m_pkNext;
        return RemoveHead();
    }
    if (node == m_pkTail)
    {
        position = 0;
        return RemoveTail();
    }
    FNVPointerListItem* link = node->m_pkPrev;
    FNVPointerListItem* pkNext = node->m_pkNext;
    position = pkNext;
    if (link != 0)
    {
        link->m_pkNext = pkNext;
    }
    if (pkNext != 0)
    {
        pkNext->m_pkPrev = link;
    }
    void* value = node->m_element;
    node->m_element = 0;
    m_kItemCount.Deallocate(node);
    m_kItemCount.m_uiCount = m_kItemCount.m_uiCount - 1;
    return value;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);
extern const char DAT_010c1364[];

struct S_Base
{
    void FUN_00a5d3d0();
    inline ~S_Base()
    {
        FUN_00a5d3d0();
    }
};
struct S_X : S_Base
{
    void BSReference_SetName(int);
    inline ~S_X();
    S_X* FUN_00c3b9f0(unsigned int flags);
};

inline S_X::~S_X()
{
    BSReference_SetName(0);
}

// @fnv 0x00c3b9f0
S_X* S_X::FUN_00c3b9f0(unsigned int flags)
{
    *(const void**)this = DAT_010c1364;
    this->S_X::~S_X();
    if (flags & 1)
    {
        FUN_00aa1460(this, 12);
    }
    return this;
}

void __cdecl NiFree(void*);

template <class T> inline void NiTMallocInterface<T>::Deallocate(T* pArray)
{
    NiFree(pArray);
}

template <class T, class TAlloc> inline NiTArray<T, TAlloc>::~NiTArray()
{
    TAlloc::Deallocate(m_pBase);
}

template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::RemoveAll()
{
    for (unsigned short i = 0; i < m_usSize; ++i)
        m_pBase[i] = 0;
    m_usSize = 0;
    m_usESize = 0;
}

namespace fnv_00c3bab0 {

class FUN_00c3bab0 : public NiRefObject
{
  public:
    NiTArray<NiAVObject*, NiTMallocInterface<NiAVObject*> > m_aiIndexedValues;
    ~FUN_00c3bab0();
};

// @fnv 0x00c3bab0
FUN_00c3bab0::~FUN_00c3bab0()
{
    m_aiIndexedValues.RemoveAll();
}
}  // namespace fnv_00c3bab0

struct MH
{
    void* vtbl;
    bool bStatic;
    MH(bool b);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};

MH::MH(bool b)
{}

// @fnv 0x00c3c460
// src: COMMUNITY 0x00c3c460
void __cdecl MessageHandler_InitSDM()
{
    MessageHandler::pHandler = (MessageHandler*)new MH(false);
}

extern long volatile DAT_01202d94;

struct QfDeletable
{
    virtual ~QfDeletable();
};

template <class T> inline BSTask<T>::~BSTask()
{
    InterlockedDecrement(&DAT_01202d94);
}
inline IOTask::~IOTask()
{}

template <> inline NiPointer<QueuedFile>::~NiPointer()
{
    int spareA;
    int spareB;
    int spareC;
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

// @fnv 0x00c3c620
QueuedFile::~QueuedFile()
{
    delete (QfDeletable*)pChildren;
    delete pAdditionalParents;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct MemMgr2
{
    void* Game_DoHeapAlloc(unsigned);
};
struct RefObj
{
    void* vtbl;
    int m_04;
    long m_08;
    void AcquireReference()
    {
        InterlockedIncrement(&m_08);
    }
    void BSTask_int64_DecRefCount();
    void QueuedFile_AddChild(void*);
};
struct RefPtr
{
    RefObj* m_p;
    RefPtr(RefObj* p = 0)
    {
        RefObj* self;
        RefObj* object = p;
        m_p = object;
        if (m_p)
        {
            self = m_p;
            InterlockedIncrement(&self->m_08);
        }
    }
    RefPtr& operator=(const RefPtr& other)
    {
        if (m_p != other.m_p)
        {
            if (m_p)
                m_p->BSTask_int64_DecRefCount();
            m_p = other.m_p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
    ~RefPtr()
    {
        if (m_p)
            m_p->BSTask_int64_DecRefCount();
    }
};
__forceinline void ConstructRefs(RefPtr* buffer, unsigned count)
{
    for (unsigned i = 0; i < count; ++i)
    {
        new (buffer + i) RefPtr;
    }
}
struct OwnArr
{
    RefObj** m_data;
    unsigned m_uiItemCount;
    int m_0c;
    OwnArr();
    static void* operator new(unsigned s)
    {
        return ((MemMgr2*)&DAT_011f6238)->Game_DoHeapAlloc(s);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    int Find(RefObj* o)
    {
        for (unsigned i = 0; i < m_uiItemCount; i++)
        {
            if (m_data && (unsigned char)(unsigned int)(m_data[i] == o))
                return i;
        }
        return -1;
    }
    virtual void unused();
    virtual RefObj** Allocate(unsigned);
    virtual void Deallocate(RefObj**);
    virtual RefObj** Reallocate(RefObj**, unsigned);
    void FUN_0042fb60(RefObj**, RefObj**, unsigned);
// src: COMMUNITY 0x00c3d870
    inline void QueuedChildren_SetLength(unsigned capacity, unsigned count)
    {
        if (m_data)
        {
            if (count == (unsigned)m_0c)
            {
                m_data = Reallocate(m_data, capacity);
            }
            else
            {
                RefObj** buffer = Allocate(capacity);
                FUN_0042fb60(buffer, m_data, count);
                Deallocate(m_data);
                m_data = 0;
                m_data = buffer;
            }
        }
        else
        {
            m_data = Allocate(capacity);
            m_0c = capacity;
        }
    }
// src: COMMUNITY 0x00c3d6c0
    __forceinline unsigned QueuedChildren_GetAppendIndex()
    {
        unsigned oldCapacity = m_0c;
        unsigned oldSize = m_uiItemCount;
        bool full = oldSize == oldCapacity;
        if (full)
        {
            if (!oldCapacity)
            {
                unsigned capacity = 4;
                m_data = Allocate(capacity);
                m_0c = capacity;
            }
            else
            {
                unsigned capacity = oldCapacity > 1024 ? oldCapacity + 1024 : oldCapacity * 2;
                QueuedChildren_SetLength(capacity, oldSize);
                m_0c = capacity;
            }
        }
        ++m_uiItemCount;
        return m_uiItemCount - 1;
    }
// src: COMMUNITY 0x00c3d4f0
    inline unsigned QueuedChildren_Append(const RefPtr& item)
    {
        unsigned index = QueuedChildren_GetAppendIndex();
        RefPtr* first = (RefPtr*)(m_data + index);
        unsigned count = 1;
        ConstructRefs(first, count);
        RefPtr* destination = (RefPtr*)(m_data + index);
        *destination = item;
        return index;
    }
};
// The legacy IOTask entry points operate on QueuedFile parent-link storage.
// @fnv 0x00c3c7e0
// src: COMMUNITY 0x00c3c7e0
void IOTask::QueuedFile_AddAdditionalParent(RefObj* obj)
{
    if (!((OwnArr*&)((QueuedFile*)this)->pAdditionalParents))
    {
        ((OwnArr*&)((QueuedFile*)this)->pAdditionalParents) = new OwnArr;
    }
    else if (((OwnArr*&)((QueuedFile*)this)->pAdditionalParents)->Find(obj) != -1)
    {
        return;
    }
    ((OwnArr*&)((QueuedFile*)this)->pAdditionalParents)->QueuedChildren_Append(obj);
    obj->QueuedFile_AddChild(this);
}

namespace fnv_00c3cb70 {
inline void Dead3()
{
    int a[3];
}
inline void Dead5()
{
    int a[5];
}
inline void Dead9()
{
    int a[9];
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
struct RefPtr
{
    RefObj* m_p;
    void Clear()
    {
        Dead3();
        if (m_p)
        {
            if (m_p)
                m_p->BSTask_int64_DecRefCount();
            m_p = 0;
            if (m_p)
                m_p->AcquireReference();
        }
    }
};
struct PtrArr
{
    void* vtbl;
    RefObj** m_data;
    unsigned m_uiItemCount;
    unsigned GetCount()
    {
        return m_uiItemCount;
    }
    RefObj*& ElementAt(unsigned i)
    {
        RefObj*& r = m_data[i];
        return r;
    }
    RefObj* GetAt(unsigned i)
    {
        return ElementAt(i);
    }
};
struct OwnArr
{
    virtual ~OwnArr();
    RefObj** m_data;
    unsigned m_uiItemCount;
    unsigned GetCount()
    {
        return m_uiItemCount;
    }
    RefObj*& ElementAt(unsigned i)
    {
        return m_data[i];
    }
    RefObj* GetAt(unsigned i)
    {
        RefObj*& r = m_data[i];
        return r;
    }
    void ReleaseEntries_00c3d5e0(unsigned, int);
};
extern IOManager* DAT_01202d98;
}  // namespace fnv_00c3cb70
inline RefObj* IOTask::GetCur()
{
    return (RefObj*)((QueuedFile*)this)->m_pParent.m_pObject;
}
inline void IOTask::SetState(long v)
{
    long old = eState;
    bool r = InterlockedCompareExchange((volatile long*)&eState, v, old) == old;
}
// @fnv 0x00c3cb70
// src: XBOX_PDB 0x00c3cb70
void IOTask::QueuedFile_Cancel(int state, RefObj* obj)
{
    using namespace fnv_00c3cb70;
    ::InterlockedIncrement((volatile long*)&BackgroundTask);
    if (obj)
    {
        if (GetCur() == obj)
        {
            ((fnv_00c3cb70::RefPtr&)((QueuedFile*)this)->m_pParent).Clear();
        }
        else if (((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents))
        {
            for (unsigned i = 0; i < ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents)->GetCount(); i++)
            {
                if (((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents)->GetAt(i) == obj)
                {
                    ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents)->ReleaseEntries_00c3d5e0(i, 1);
                    break;
                }
            }
            Dead5();
            if (((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents)->GetCount() == 0)
            {
                delete ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents);
                ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents) = 0;
            }
        }
    }
    else
    {
        ((fnv_00c3cb70::RefPtr&)((QueuedFile*)this)->m_pParent).Clear();
        delete ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents);
        ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents) = 0;
    }
    if (GetCur() || ((fnv_00c3cb70::OwnArr*&)((QueuedFile*)this)->pAdditionalParents))
    {
        if (state == 1)
            DAT_01202d98->AddTask((QIOTask*)this);
        else
            SetState(state);
    }
    else if (((fnv_00c3cb70::PtrArr*&)((QueuedFile*)this)->pChildren))
    {
        unsigned n = ((fnv_00c3cb70::PtrArr*&)((QueuedFile*)this)->pChildren)->m_uiItemCount;
        for (unsigned j = 0; j < n; j++)
        {
            RefObj* o = ((fnv_00c3cb70::PtrArr*&)((QueuedFile*)this)->pChildren)->ElementAt(j);
            if (o)
                DAT_01202d98->BSTaskManager_CancelTask(o, this);
        }
    }
    BSTask_int64_DecRefCount();
    Dead9();
}


extern int __cdecl BSsprintf(char*, unsigned int, const char*, ...);
struct QEntry
{
    unsigned int unk00, unk04, packedSize, packedOffset;
};
struct QTask
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Describe(char*, unsigned int);
};
struct QPointer
{
    QTask* value;
    operator QTask*()
    {
        return value;
    }
};
struct QArray
{
    unsigned int unk00;
    QPointer* data;
    unsigned int count;
};
struct QRequest
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    QArray* tasks;
    unsigned int unk24;
    const char* name;
    QEntry* entry;
    bool QueuedFileEntry_GetDescription(char*, unsigned int, const char*);
};
// @fnv 0x00c3d0e0
// src: XBOX_PDB 0x00c3d0e0
bool QRequest::QueuedFileEntry_GetDescription(char* out, unsigned int size, const char* type)
{
    char buffer[13000];
    unsigned int i;
    {
        QEntry* a;
        const char* b;
        if ((a = entry) && (b = name))
        {
            QEntry* f = entry;
            unsigned int g = f->packedSize & 0x3fffffff;
            unsigned int c;
            QEntry* d = entry;
            c = d->packedOffset & 0x7fffffff;
            const char* e = name;
            BSsprintf(out, size, "Queued %s %s with file entry offset %i and size %i", type, e, c, g);
        }
        else
        {
            QEntry* h = entry;
            if (h)
            {
                QEntry* k = entry;
                unsigned int l = k->packedSize & 0x3fffffff;
                QEntry* j = entry;
                BSsprintf(out, size, "Queued %s with file entry offset %i and size %i", type,
                             j->packedOffset & 0x7fffffff, l);
            }
            else
            {
                const char* m = name;
                BSsprintf(out, size, "Queued %s %s", type, m);
            }
        }
        if (tasks)
        {
            unsigned int n;
            for (i = 0; i < (n = tasks->count); i++)
            {
                QPointer* p = &tasks->data[i];
                QTask* o = p->value;
                if (o)
                {
                    QPointer* q = &tasks->data[i];
                    if (static_cast<QTask*>(*q)->Describe(buffer, sizeof(buffer)))
                    {
                        strcat_s(out, size, "\n * ");
                        strcat_s(out, size, buffer);
                    }
                }
            }
        }
    }
    return true;
}

struct ObjA
{
    void BSTask_int64_DecRefCount();
};
inline unsigned Zero()
{
    return 0;
}

struct FUN_00c3d5e0_Class
{
    void* unk00;
    void** m_pBase;
    unsigned int m_uiSize;
    void __thiscall FUN_0042fb60(void* dst, void* src, unsigned int count);
    void __thiscall ReleaseEntries_00c3d5e0(unsigned int uiStart, unsigned int ItemUpdateArray);
};

// @fnv 0x00c3d5e0
// src: GUESS 0x00c3d5e0 (confidence: low)
void __thiscall FUN_00c3d5e0_Class::ReleaseEntries_00c3d5e0(unsigned int uiStart, unsigned int ItemUpdateArray)
{
    unsigned int i;
    unsigned int base;
    unsigned int index;
    unsigned int q;
    unsigned int b;
    unsigned int count;
    unsigned int p;
    void** n0;
    unsigned int a;
    void** tmp;
    count = m_uiSize - uiStart - ItemUpdateArray;
    p = (count < ItemUpdateArray) ? count : ItemUpdateArray;
    n0 = m_pBase + uiStart;
    for (a = 0; a < ItemUpdateArray; ++a)
    {
        tmp = n0 + a;
        if (*tmp)
            ((ObjA*)(*tmp))->BSTask_int64_DecRefCount();
        if ((Zero() & 1u) != 0)
            ((MemoryManager*)&g_memoryManager)->Deallocate(tmp);
    }
    FUN_0042fb60(m_pBase + uiStart, (m_pBase + m_uiSize) - p, p);
    m_uiSize -= ItemUpdateArray;
}

struct ArrayC3D6C0
{
    void** vtbl;
    void* data;
    unsigned int size;
    unsigned int cap;
// src: COMMUNITY 0x00c3d870
    inline void QueuedChildren_SetLength(unsigned int neu, unsigned int count)
    {
        unsigned int i = neu;
        unsigned int s = count;
        unsigned int u = neu;
        i = i + s;
        s = s + u;
        u = u + i;
        i = i + s;
        s = s + 1;
        u = u + 1;
        i = i + s;
        s = s + u;
        u = u + i;
        i = i + 2;
        s = s + 2;
        u = u + 2;
        i = i + s + u;
        s = i;
        u = s;
        i = u + 3;
        s = i + 4;
        u = s + 5;
        i = u + s;
        s = i + 6;
        u = s + 7;
        i = u + 8;
        s = i + 9;
        u = s + 1;
        if (i > s)
            u = i;
        else
            u = s;
        data = (void*)(i + s + u + count);
        cap = neu;
    }
    int QueuedChildren_GetAppendIndex();
};

// @fnv 0x00c3d6c0
// src: COMMUNITY 0x00c3d6c0
int ArrayC3D6C0::QueuedChildren_GetAppendIndex()
{
    unsigned int first;
    unsigned int high;
    bool last;
    if (size == cap)
        last = true;
    else
        last = false;
    if (last)
    {
        if (cap == 0)
        {
            first = 4;
            typedef void*(__thiscall * AllocFn)(void*, unsigned int);
            data = ((AllocFn)vtbl[1])(this, first);
            cap = first;
        }
        else
        {
            high = cap > 0x400 ? cap + 0x400 : cap * 2;
            QueuedChildren_SetLength(high, size);
            cap = high;
        }
    }
    size = size + 1;
    return size - 1;
}

inline unsigned int DbgFlags()
{
    return 0;
}

struct ItemSlot
{
    void** ptr;
    int unk04;
    int unk08;
    int unk0C;
};

struct C3D980Cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void** pItems);
    void** m_ppItems;
    unsigned int m_uCount;
    int unk0C;

    void BSSimpleArray_NiPointer_QueuedFile_1024_Clear(bool bFree);
};

// @fnv 0x00c3d980
// src: XBOX_PDB 0x00c3d980
void C3D980Cls::BSSimpleArray_NiPointer_QueuedFile_1024_Clear(bool bFree)
{
    unsigned int used;
    void** data;
    ItemSlot pItem;
    unsigned int i;
    if (m_ppItems != 0)
    {
        used = m_uCount;
        data = m_ppItems;
        for (i = 0; i < used; i++)
        {
            pItem.ptr = &data[i];
            if (*pItem.ptr != 0)
            {
                BSTask_int64_DecRefCount(*pItem.ptr);
            }
            if (DbgFlags() & 1)
            {
                DAT_011f6238.MemoryManager_Deallocate(pItem.ptr);
            }
        }
        if (bFree)
        {
            v08(m_ppItems);
            m_ppItems = 0;
            m_ppItems = 0;
            unk0C = 0;
        }
        m_uCount = 0;
    }
}

namespace fnv_00c3dbf0 { struct TaskPtr; }
struct IOQueue
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual unsigned Count();
    void LockFreePriorityQueue_NiPointer_IOTask_Pop(fnv_00c3dbf0::TaskPtr& out);
};
inline unsigned IOManager::QueuedCount()
{
    return m_queue->Count();
}
inline void IOTask::AcquireReference()
{
    InterlockedIncrement((volatile long*)&BackgroundTask);
}
namespace fnv_00c3dbf0 {
inline void Dead3()
{
    int a[3];
}
inline void Dead16()
{
    int a[16];
}
inline void Dead19()
{
    int a[19];
}
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern unsigned DAT_01202800;
extern unsigned char DAT_01202dd8;
extern float DAT_011ac39c;
__int64 BSPrecisionTimer_GetTimer();
extern Setting DAT_01202da8;
extern Setting DAT_01202db4;
struct TaskPtr
{
    IOTask* m_p;
    TaskPtr(IOTask* p) : m_p(p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    ~TaskPtr()
    {
        if (m_p)
            m_p->BSTask_int64_DecRefCount();
    }
    TaskPtr& operator=(IOTask* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->BSTask_int64_DecRefCount();
            m_p = p;
            if (m_p)
                m_p->AcquireReference();
        }
        return *this;
    }
    operator IOTask*() const
    {
        return m_p;
    }
    IOTask* operator->() const
    {
        return m_p;
    }
};
}  // namespace fnv_00c3dbf0
inline unsigned* Setting::GetPtr()
{
    return this ? (unsigned*)&uValue.f : (fnv_00c3dbf0::DAT_01202800 = 0, &fnv_00c3dbf0::DAT_01202800);
}
inline unsigned Setting::GetUInt()
{
    unsigned* p = GetPtr();
    return *p;
}
// @fnv 0x00c3dbf0
// src: COMMUNITY 0x00c3dbf0
bool IOManager::UpdateQueue()
{
    using namespace fnv_00c3dbf0;
    if (DAT_01202dd8)
        return true;
    bool result2 = true;
    DAT_01202dd8 = 1;
    unsigned ms = 0;
    if (m_uiContentCount == 6)
        ms = DAT_01202da8.GetUInt();
    else
        ms = DAT_01202db4.GetUInt();
    __int64 start = 0;
    __int64 limit5 = 0;
    start = BSPrecisionTimer_GetTimer();
    limit5 = (__int64)(ms * DAT_011ac39c);
    if (m_canRunFn)
        result2 = m_canRunFn();
    TaskPtr taskA(0);
    m_queue->LockFreePriorityQueue_NiPointer_IOTask_Pop(taskA);
    while (taskA)
    {
        Dead16();
        taskA->ProcessLoadedAnimIdle();
        if (m_idleFn)
            m_idleFn();
        if (!(bool)(BSPrecisionTimer_GetTimer() - start > limit5 ? 1 : 0))
        {
            m_queue->LockFreePriorityQueue_NiPointer_IOTask_Pop(taskA);
        }
        else
        {
            taskA = 0;
        }
    }
    DAT_01202dd8 = 0;
    Dead3();
    return result2;
}


extern volatile long DAT_01202d9c;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

inline int S00c3de80_Zero()
{
    return 0;
}

// These task-submission entry points are absent from IOManager's shared interface.
// Keep their thiscall ABI here while using the shared manager and task storage.
struct TaskSubmissionEntry
{
    bool __thiscall BSTaskManager_int64_AddTask(IOTask* object);
    bool __thiscall IOManager_AddTask(IOTask* object);
};

// @fnv 0x00c3de80
// src: COMMUNITY 0x00c3de80
bool TaskSubmissionEntry::IOManager_AddTask(IOTask* object)
{
    IOTask* self = object;
    if (((IOManager*)this)->m_uiContentCount != 6)
    {
        if ((unsigned char)(self->Key >> 16) <= ((IOManager*)this)->m_uiContentCount)
        {
            self->Key = (self->Key & 0xffffffffff00ffffLL) + ((__int64)S00c3de80_Zero() << 16);
        }
    }

    self->GenerateKey();

    while (!BSTaskManager_int64_AddTask(self))
    {
        __declspec(align(2)) unsigned short serial = (unsigned short)InterlockedIncrement(&DAT_01202d9c);

        self->Key = (self->Key & 0xffffffffffff0000LL) + (int)serial;
    }

    return true;
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
extern char DAT_011af70c;
// @fnv 0x00c3dfa0
// src: XBOX_PDB 0x00c3dfa0
void IOManager::LoadQueuedPriority(int mode)
{
    if (m_uiContentCount == 7)
        return;
    DAT_011af70c = 0;
    if (m_18 == 0 && QueuedCount() == 0 && (m_pendingFn ? m_pendingFn() : 0) == 0)
    {
        m_uiContentCount = 6;
        DAT_011af70c = 1;
        return;
    }
    m_uiContentCount = mode;
    RequeuePrioritiesToNewPriority(mode, 0);
    unsigned queued9 = m_queue->Count();
    unsigned total2 = SumArrayUpToCount(mode * 4 + 3) + queued9 + (m_pendingFn ? m_pendingFn() : 0);
    float pctVal;
    unsigned remaining = total2;
    bool done7 = false;
    while (remaining != 0 || !done7)
    {
        pctVal = (float)((double)(total2 - remaining) / (double)total2 * 100.0);
        if (m_progressFn)
            m_progressFn(pctVal);
        unsigned limit = m_18;
        if (limit > m_queue->Count())
            Sleep(50);
        done7 = UpdateQueue();
        unsigned queued4 = m_queue->Count();
        remaining = SumArrayUpToCount(mode * 4 + 3) + queued4 + (m_pendingFn ? m_pendingFn() : 0);
    }
    m_uiContentCount = 6;
    if (m_progressFn)
        m_progressFn(100.0f);
    DAT_011af70c = 1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

extern long __cdecl FinishScriptRunLock(volatile long*);

struct RefObj_c3e1b0
{
    virtual ~RefObj_c3e1b0();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Run(int arg);
    int unk04;
    long refCount;
    inline void AcquireReference()
    {
        InterlockedIncrement(&refCount);
    }
    inline void DecRef()
    {
        long remaining = FinishScriptRunLock(&refCount);
        if (remaining == 0)
            delete this;
    }
};

struct RefPtr_c3e1b0
{
    RefObj_c3e1b0* obj;
    inline RefObj_c3e1b0* operator->() const
    {
        return obj;
    }
    inline RefPtr_c3e1b0(RefObj_c3e1b0* p = 0)
    {
        obj = p;
        if (obj)
            obj->AcquireReference();
    }
    inline ~RefPtr_c3e1b0()
    {
        if (obj)
            obj->DecRef();
    }
};

struct StreamBase_c3e1b0
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char flags;
    inline StreamBase_c3e1b0()
    {
        unk08 = 0;
        unk10 = 0;
        unk14 = 0;
        flags = 0;
    }
    virtual ~StreamBase_c3e1b0()
    {}
    virtual void Reset()
    {
        unk10 = 0;
        unk14 = 0;
    }
    inline bool Started() const
    {
        return bool(flags & 1);
    }
    inline bool Finished() const
    {
        return bool(flags & 2);
    }
    inline void SetStarted(bool value)
    {
        if (value)
            flags |= 1;
        else
            flags &= ~1;
    }
    inline void SetFinished(bool value)
    {
        if (value)
            flags |= 2;
        else
            flags &= ~2;
    }
};

struct Stream_c3e1b0 : StreamBase_c3e1b0
{
    int unk1c;
    inline Stream_c3e1b0()
    {}
    inline void Reserve(int size)
    {
        Reset();
        unk08 = size;
        SetStarted(false);
        SetFinished(false);
    }
};

extern unsigned gm_GetCurrentThreadId();
extern int BSAtomicCompareExchange(volatile long*, long, long);
extern void BSSleep(unsigned long);
extern void LockBarrier();
struct NextLockC3
{
    long owner;
    unsigned depth;
    inline void Lock(const char*)
    {
        unsigned threadId = gm_GetCurrentThreadId();
        if (owner == threadId)
            ++depth;
        else
        {
            unsigned spins = 0;
            while (BSAtomicCompareExchange(&owner, 0, threadId))
            {
                ++spins;
                if (spins > 10000)
                    BSSleep(1);
                else
                    BSSleep(0);
            }
            LockBarrier();
            depth = 1;
        }
    }
    inline void Unlock()
    {
        --depth;
        if (!depth)
            owner = 0;
    }
};
struct QueueC3
{
    bool First(unsigned, void*, RefPtr_c3e1b0*);
    bool Next(unsigned, void*, RefPtr_c3e1b0*);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
struct TaskManagerQueueState;
struct QueueRegistryC3
{
    int unk00;
    unsigned tlsIndex;
    QueueC3* Create(TaskManagerQueueState*);
    inline QueueC3* Get(TaskManagerQueueState* mgr)
    {
        unsigned index = tlsIndex;
        void* value = TlsGetValue(index);
        return value ? (QueueC3*)value : Create(mgr);
    }
};
// Queue traversal helpers are not exposed by the shared BSTaskManager interface.
// This adapter has no storage; it accesses the shared IOManager base storage.
struct TaskManagerQueueState
{
    inline unsigned Count() const
    {
        return *(const unsigned*)(((const IOManager*)this)->unk04 + 4);
    }
    inline QueueC3* GetQueue()
    {
        return (*(QueueRegistryC3**)(((IOManager*)this)->unk04 + 0x10))->Get(this);
    }
    void Lock();
    void Unlock();
    inline bool Next(Stream_c3e1b0* s, __int64* key, RefPtr_c3e1b0* p, bool flag)
    {
        ((NextLockC3*)(((IOManager*)this)->unk1C + 4))->Lock(0);
        bool result = false;
        if (s->Finished())
            result = false;
        else
        {
            while (true)
            {
                if (!s->Started())
                {
                    result = GetQueue()->First(s->unk08, &s->unk10, p);
                    s->SetStarted(true);
                }
                else
                    result = GetQueue()->Next(s->unk08, &s->unk10, p);
                if (!result)
                {
                    ++s->unk08;
                    if ((unsigned)s->unk08 >= Count())
                        s->SetFinished(true);
                    else if (flag)
                    {
                        s->SetStarted(false);
                        continue;
                    }
                }
                else
                    *key = *reinterpret_cast<const __int64*>(&s->unk10);
                break;
            }
        }
        ((NextLockC3*)(((IOManager*)this)->unk1C + 4))->Unlock();
        return result;
    }
};

// @fnv 0x00c3e1b0
// src: COMMUNITY 0x00c3e1b0
void IOManager::RequeuePrioritiesToNewPriority(int maxPriority, int arg)
{
    if (maxPriority <= arg)
        return;
    {
        ((TaskManagerQueueState*)this)->Lock();
        Stream_c3e1b0 stream;
        stream.Reserve(arg * 4 + 4);
        while (!bool(stream.flags & 2))
        {
            __int64 key = 0;
            RefPtr_c3e1b0 item3;
            if (((TaskManagerQueueState*)this)->Next(&stream, &key, &item3, 1))
            {
                if ((unsigned char)(key >> 16) > maxPriority)
                    break;
                item3->Run(arg);
            }
        }
        ((TaskManagerQueueState*)this)->Unlock();
    }
}

struct Q
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
    virtual int v9(int x, int y);
};

struct TaskMapHandle
{
    Q* q;
    bool __thiscall LockFreeMapInterface_GetAt(int key, int a, int b, int c);
};

struct LockObj
{
    void* owner;
    int count;
    void __thiscall BSSpinLock_Lock(const char* name);
    __forceinline void Unlock()
    {
        count = count - 1;
        if (count == 0)
            owner = 0;
    }
};

struct Owner
{
    int u0, u1, u2, u3, u4, u5, u6, u7;
    LockObj lock;
    TaskMapHandle* __thiscall LockFreeMap_GetInterface();
    __forceinline bool pass(TaskMapHandle* node, int a, int b, int c)
    {
        return node->LockFreeMapInterface_GetAt(node->q->v9(a, b), a, b, c);
    }
    bool __thiscall LockFreeMap_int64_NiPointer_BSTask_int64_GetAt(int a, int b, int c);
};

// @fnv 0x00c3f160
// src: COMMUNITY 0x00c3f160
bool Owner::LockFreeMap_int64_NiPointer_BSTask_int64_GetAt(int a, int b, int c)
{
    int local4, local5, local6, receiver, answer;
    int extra14, done, status, extra4, extra5;
    int slot2, spare4, spare5, spare6, spare8, spare9, extra15;
    lock.BSSpinLock_Lock(0);
    TaskMapHandle* node = LockFreeMap_GetInterface();
    bool found = pass(node, a, b, c);
    lock.Unlock();
    return found;
}

struct Inner
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9(int a, int b);
};
struct WeightedMapNode
{
    Inner* handler;
    inline bool TryAcquireAndFire(int index, int a, int b)
    {
        int l00 = index + 0;
        int l01 = index + 1;
        int l02 = index + 2;
        int l03 = index + 3;
        int l04 = index + 4;
        int l05 = index + 5;
        int l06 = index + 6;
        int l07 = index + 7;
        int l08 = index + 8;
        int l09 = index + 9;
        int l10 = index + 10;
        int l11 = index + 11;
        int l12 = index + 12;
        int l13 = index + 13;
        int l14 = index + 14;
        int l15 = index + 15;
        int l16 = index + 16;
        int l17 = index + 17;
        int l18 = index + 18;
        int l19 = index + 19;
        int l20 = index + 20;
        int l21 = index + 21;
        int l22 = index + 22;
        int l23 = index + 23;
        int l24 = index + 24;
        int l25 = index + 25;
        int l26 = index + 26;
        int l27 = index + 27;
        int l28 = index + 28;
        int l29 = index + 29;
        int l30 = index + 30;
        int l31 = index + 31;
        int l32 = index + 32;
        int l33 = index + 33;
        int l34 = index + 34;
        int l35 = index + 35;
        return l00 == a + b;
    }
};
inline bool Call(WeightedMapNode* node, int a, int b)
{
    return node->TryAcquireAndFire(node->handler->v9(a, b), a, b);
}
struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    RecursiveSpinLock lock;
    WeightedMapNode* LockFreeMap_GetInterface();
    bool LockFreeMap_int64_NiPointer_BSTask_int64_RemoveAt(int a, int b);
};
// @fnv 0x00c3f2b0
// src: COMMUNITY 0x00c3f2b0
bool Obj::LockFreeMap_int64_NiPointer_BSTask_int64_RemoveAt(int a, int b)
{
    lock.Lock(0);
    bool result = Call(LockFreeMap_GetInterface(), a, b);
    lock.Unlock();
    return result;
}

void __fastcall BSTask_int64_DecRefCount(void*);

struct Ref360
{
    void* ptr;
    inline ~Ref360()
    {
        if (ptr)
            BSTask_int64_DecRefCount(ptr);
    }
};

struct Spin360
{
    int owner;
    int count;
    inline void __thiscall Lock(const char* name)
    {
        unsigned u0, u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14, u15;
        unsigned u16, u17, u18, u19, u20, u21, u22, u23, u24, u25, u26, u27, u28, u29, u30, u31, u32, u33, u34, u35;
        u0 = 0;
        u1 = 1;
        u2 = 2;
        u3 = 3;
        u4 = 4;
        u5 = 5;
        u6 = 6;
        u7 = 7;
        u8 = 8;
        u9 = 9;
        u10 = 10;
        u11 = 11;
        u12 = 12;
        u13 = 13;
        u14 = 14;
        u15 = 15;
        u16 = 16;
        u17 = 17;
        u18 = 18;
        u19 = 19;
        u20 = 20;
        u21 = 21;
        u22 = 22;
        u23 = 23;
        u24 = 24;
        u25 = 25;
        u26 = 26;
        u27 = 27;
        u28 = 28;
        u29 = 29;
        u30 = 30;
        u31 = 31;
        u32 = 32;
        u33 = 33;
        u34 = 34;
        u35 = 35;
        if (owner == (int)name)
            return;
        Lock(name + 1);
    }
    inline void Unlock()
    {
        struct Hold
        {
            int d1;
            int d2;
            int d3;
            Spin360* p;
        } t;
        t.p = this;
        t.p->count -= 1;
        if (t.p->count == 0)
            t.p->owner = 0;
    }
};

struct Helper360
{
    void* __thiscall LockFreeMap_GetInterface(void* a, Ref360* b);
};

struct Result360
{
    char __thiscall ProcessEntries_00c40680();
};

struct Obj360
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Spin360 lock;
    char __thiscall LockFreeMap_int64_NiPointer_BSTask_int64_Func06(void* a, Ref360 b);
};

// @fnv 0x00c3f360
// src: COMMUNITY 0x00c3f360
char __thiscall Obj360::LockFreeMap_int64_NiPointer_BSTask_int64_Func06(void* a, Ref360 b)
{
    lock.Lock(0);
    char r = ((Result360*)((Helper360*)this)->LockFreeMap_GetInterface(a, &b))->ProcessEntries_00c40680();
    lock.Unlock();
    return r;
}

struct C3F4C0_Obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual int unk24(int a, int b);
};

struct C3F4C0_Holder : FUN_00c416a0_Class
{
    C3F4C0_Obj* obj;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_uSlot14;

    inline bool LockFreeMapInterface_GetAt(int x, int a, int b, void** out);
    bool Lookup(int a, int b, void** out)
    {
        return LockFreeMapInterface_GetAt(obj->unk24(a, b), a, b, out);
    }
};

// src: COMMUNITY 0x00c3fe80
inline bool C3F4C0_Holder::LockFreeMapInterface_GetAt(int x, int a, int b, void** out)
{
    bool ok = LockFreeMapInterface_Find_0(x, a, b);
    if (ok)
    {
        unsigned int* pSlot1 = &m_uSlot14;
        void** ppVal = (void**)((*pSlot1 & ~1u) + 8);
        if (*out != *ppVal)
        {
            if (*out)
            {
                BSTask_int64_DecRefCount(*out);
            }
            *out = *ppVal;
            if (*out)
            {
                char* pRef = (char*)*out;
                InterlockedIncrement((volatile long*)(pRef + 8));
            }
        }
        unsigned int* pSlot2 = &m_uSlot14;
        unsigned int uBase = *pSlot2 & ~1u;
        unsigned int* pFlags = (unsigned int*)(uBase + 12);
        if ((*pFlags & 1u) != 0)
        {
            ok = false;
        }
    }
    int n00, n01, n02, n03, n04, n05, n06, n07, n08, n09;
    int n10, n11, n12, n13, n14, n15, n16, n17, n18, n19;
    int n20, n21, n22, n23, n24, n25, n26, n27, n28, n29;
    int n30, n31, n32, n33, n34, n35, n36, n37, n38, n39;
    int n40, n41, n42, n43, n44, n45, n46, n47, n48, n49;
    int n50;
    n00 = n01 = n02 = n03 = n04 = n05 = n06 = n07 = n08 = n09 = x;
    n10 = n11 = n12 = n13 = n14 = n15 = n16 = n17 = n18 = n19 = a;
    n20 = n21 = n22 = n23 = n24 = n25 = n26 = n27 = n28 = n29 = b;
    n30 = n31 = n32 = n33 = n34 = n35 = n36 = n37 = n38 = n39 = n00 + n10;
    n40 = n41 = n42 = n43 = n44 = n45 = n46 = n47 = n48 = n49 = n20 + n30;
    n50 = n40 + 1;
    return ok && n50 != 0x7fffffff;
}

struct C3F4C0_Cls
{
    C3F4C0_Holder* LockFreeMap_GetInterface();
    bool LockFreeMap_int64_NiPointer_BSTask_int64_Func08(int a, int b, void** out);
};

// @fnv 0x00c3f4c0
// src: COMMUNITY 0x00c3f4c0
bool C3F4C0_Cls::LockFreeMap_int64_NiPointer_BSTask_int64_Func08(int a, int b, void** out)
{
    bool res = LockFreeMap_GetInterface()->Lookup(a, b, out);
    return res;
}

struct FUN_00c3f7a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int* m_pValues10;
    void* __thiscall LockFreeQueue_NiPointer_IOTask_AllocateInterface(int index);
};

extern __declspec(thread) int DAT_tls_field;

inline AutoMemContext::AutoMemContext(int aeMemoryContext)
{
    int iOld = DAT_tls_field;
    m_eMemoryContext = (MEM_CONTEXT)iOld;
    DAT_tls_field = aeMemoryContext;
}
inline AutoMemContext::~AutoMemContext()
{
    int iSaved = m_eMemoryContext;
    DAT_tls_field = iSaved;
}

struct Item_00c3f7a0
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0c;
    void* m_p10;

    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    Item_00c3f7a0(void* p0, void* p4, void* p8);
};

// @fnv 0x00c3f7a0
// src: COMMUNITY 0x00c3f7a0
void* FUN_00c3f7a0_Class::LockFreeQueue_NiPointer_IOTask_AllocateInterface(int index)
{
    AutoMemContext kContext(6);
    return new Item_00c3f7a0(this, m_pValues10 + index * 2, m_pValues10 + index * 2 + 1);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
extern __declspec(thread) int g_tlsMemContext;

struct ObjectC3
{
    int unk00;
    int unk04;
    long refs;
    inline void AddRef()
    {
        InterlockedIncrement(&refs);
    }
};
struct RefC3
{
    ObjectC3* ptr;
    inline RefC3(ObjectC3* p = 0)
    {
        ptr = p;
        if (ptr)
            ptr->AddRef();
    }
    inline ~RefC3()
    {
        if (ptr)
            BSTask_int64_DecRefCount(ptr);
    }
    RefC3& AssignRef(RefC3 const&);
    inline void Set(RefC3 const& r)
    {
        if (ptr != r.ptr)
        {
            if (ptr)
                BSTask_int64_DecRefCount(ptr);
            ptr = r.ptr;
            if (ptr)
                ptr->AddRef();
        }
    }
};
struct AllocC3
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern "C" AllocC3 MMGR;
struct NodeC3;
struct TaggedC3
{
    unsigned int bits;
    TaggedC3()
    {}
    inline TaggedC3(NodeC3* p)
    {
        bits = (unsigned int)p;
    }
    inline NodeC3* Get() const
    {
        const TaggedC3* self = this;
        return (NodeC3*)(self->bits & ~1u);
    }
    void LockFreeMap_MarkedPointer_SetMark(bool);
    inline void Mark(bool mark)
    {
        TaggedC3* self = this;
        if (mark)
            self->bits |= 1;
        else
            self->bits &= ~1u;
    }
    inline unsigned int Value() const
    {
        const TaggedC3* self = this;
        return self->bits;
    }
    inline bool Marked() const
    {
        return (bits & 1) != 0;
    }
};
struct NodeC3
{
    __int64 key;
    RefC3 obj;
    TaggedC3 next;
    inline NodeC3(__int64 k, RefC3 const& v) : obj(), next(0)
    {
        key = k;
        obj.AssignRef(v);
    }
    inline static void* operator new(unsigned int size)
    {
        return MMGR.Allocate(size);
    }
    inline static void operator delete(void* p)
    {
        MMGR.Deallocate(p);
    }
};
struct KeyC3
{
    int lo;
    int hi;
};
struct HandlerC3
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
    virtual __int64 Key(KeyC3);
    virtual void v12();
    virtual bool Less(__int64, KeyC3);
    virtual bool Equal(__int64, KeyC3);
    virtual void Done();
    int unk04;
    int unk08;
    struct AtomicC3* buckets;
};
struct ContextC3
{
    int previous;
    inline ContextC3(int old) : previous(old)
    {
        g_tlsMemContext = 6;
    }
    inline static void Set(int value)
    {
        g_tlsMemContext = value;
    }
    inline ~ContextC3()
    {
        Set(previous);
    }
};
struct AtomicC3
{
    long bits;
    inline unsigned int Value() const
    {
        return bits;
    }
    inline bool Compare(unsigned int desired, unsigned int expected)
    {
        bool success = InterlockedCompareExchange((long volatile*)this, desired, expected) == expected;
        return success;
    }
};
struct SearchC3
{
    HandlerC3* handler;
    void** out1;
    void** out2;
    void** out3;
    AtomicC3* link;
    TaggedC3 current;
    TaggedC3 observed;
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(NodeC3*);
// src: COMMUNITY 0x00c416a0
    inline bool LockFreeMapInterface_Find_0(int index, KeyC3 key)
    {
        AtomicC3* start = &handler->buckets[index];
        while (true)
        {
            bool restart = false;
            link = start;
            current.bits = link->bits;
            *out2 = current.Get();
            TaggedC3 safe(current.Get());
            safe.LockFreeMap_MarkedPointer_SetMark(false);
            if (link->bits != safe.Value())
                continue;
            while (true)
            {
                if (!current.Get())
                    return false;
                observed = current.Get()->next;
                *out1 = observed.Get();
                if (observed.Value() != current.Get()->next.Value())
                {
                    restart = true;
                    break;
                }
                __int64 nodeKey = current.Get()->key;
                TaggedC3 expected(current.Get());
                expected.Mark(false);
                if (link->Value() != expected.Value())
                {
                    restart = true;
                    break;
                }
                if (!observed.Marked())
                {
                    if (handler->Less(nodeKey, key))
                        return handler->Equal(nodeKey, key);
                    link = (AtomicC3*)&current.Get()->next;
                    *out3 = current.Get();
                }
                else
                {
                    TaggedC3 desired(observed.Get());
                    desired.Mark(false);
                    if (link->Compare(desired.Value(), expected.Value()))
                        LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_DeleteNode(current.Get());
                    else
                    {
                        restart = true;
                        break;
                    }
                }
                current = observed;
                *out2 = observed.Get();
            }
            if (restart)
                continue;
        }
    }
    bool LockFreeMapInterface_SetAt(int index, KeyC3 key, RefC3* value, bool replace);
};
// @fnv 0x00c3ffb0
// src: COMMUNITY 0x00c3ffb0
bool SearchC3::LockFreeMapInterface_SetAt(int index, KeyC3 key, RefC3* value, bool replace)
{
    ContextC3 context4(g_tlsMemContext);
    bool result2 = true;
    NodeC3* node7 = 0;
    while (true)
    {
        if (LockFreeMapInterface_Find_0(index, key))
        {
            delete node7;
            if (replace)
                current.Get()->obj.Set(*value);
            else
                result2 = false;
            break;
        }
        if (!node7)
            node7 = new NodeC3(handler->Key(key), *value);
        TaggedC3 next4(current.Get());
        next4.LockFreeMap_MarkedPointer_SetMark(false);
        TaggedC3 desired5(node7);
        desired5.Mark(false);
        node7->next = next4;
        if (link->Compare(desired5.Value(), next4.Value()))
        {
            handler->Done();
            break;
        }
    }
    *out1 = 0;
    *out2 = 0;
    *out3 = 0;
    return result2;
}

namespace fnv_00c35c10 {
struct M_004b4500
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3 FUN_004b4500(const NiPoint3* p)
    {
        return NiPoint3(m00 * p->x + m01 * p->y + m02 * p->z, m10 * p->x + m11 * p->y + m12 * p->z,
                         m20 * p->x + m21 * p->y + m22 * p->z);
    }
};
struct Result
{
    NiPoint3 p0, p1, p2, p3;
};
struct Target
{
    int unk00, unk04;
    NiPoint3 center;
    float width, height;
    M_004b4500 matrix;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c,
        unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unkA0, unkA4;
    Result cached;
    int unkD8, unkDC, unkE0;
    bool dirty;
    void BSOcclusionPlane_GetVertices(Result* out);
};
// @fnv 0x00c35c10
// src: COMMUNITY 0x00c35c10
void Target::BSOcclusionPlane_GetVertices(Result* out)
{
    if (!dirty)
    {
        memcpy(out, &cached, 48);
        return;
    }
    NiPoint3 horizontal(width, 0.0f, 0.0f);
    NiPoint3 vertical(0.0f, 0.0f, height);
    horizontal = matrix.FUN_004b4500(&horizontal);
    vertical = matrix.FUN_004b4500(&vertical);
    out->p3 = center - horizontal + vertical;
    out->p2 = center - horizontal - vertical;
    out->p1 = center + horizontal - vertical;
    out->p0 = center + horizontal + vertical;
    memcpy(&cached, out, 48);
    dirty = false;
}
}  // namespace fnv_00c35c10

long __cdecl FUN_004019a0(unsigned int& value);

struct RefObj_c3d4
{
    virtual ~RefObj_c3d4();
    int unk04;
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        unsigned int ui = FUN_004019a0(m_uiRefCount);
        if (ui == 0)
            DeleteThis();
    }
    void DeleteThis()
    {
        delete this;
    }
};

template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(T* pObject) : m_pObject(pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& ptr)
{
    if (m_pObject != ptr.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = ptr.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

inline void* operator new(unsigned int, NiPointer<RefObj_c3d4>* p)
{
    return p;
}

__forceinline void ConstructC3D4(NiPointer<RefObj_c3d4>* pkData, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        NiPointer<RefObj_c3d4>* pkNew = new (&pkData[i]) NiPointer<RefObj_c3d4>;
}

struct PtrArray_c3d4
{
    void* m_vtbl;
    NiPointer<RefObj_c3d4>* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMax;
    unsigned int QueuedChildren_GetAppendIndex();
    unsigned int QueuedChildren_Append(const NiPointer<RefObj_c3d4>& element);
};

// @fnv 0x00c3d4f0
// src: COMMUNITY 0x00c3d4f0
unsigned int PtrArray_c3d4::QueuedChildren_Append(const NiPointer<RefObj_c3d4>& element)
{
    unsigned int uiIndex = QueuedChildren_GetAppendIndex();
    ConstructC3D4(m_pBase + uiIndex, 1);
    m_pBase[uiIndex] = element;
    return uiIndex;
}

struct FUN_00c39c80_obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual int v94(int a);
    virtual int v98(int a);
};
struct FUN_00c39c80_holder
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00c39c80_obj* m_0c;
    FUN_00c39c80_obj* GetObj()
    {
        FUN_00c39c80_obj* a = m_0c;
        return a;
    }
};
struct FUN_00c39c80_node
{
    FUN_00c39c80_node* m_00;
    int unk04;
    FUN_00c39c80_holder* m_08;
};
inline FUN_00c39c80_holder* const& GetNext(FUN_00c39c80_node*& pos)
{
    FUN_00c39c80_holder* const& e = pos->m_08;
    pos = pos->m_00;
    return e;
}
struct FUN_00c39c80_cls
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
    FUN_00c39c80_holder* m_ac;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    FUN_00c39c80_node* m_d0;
    int unkD4;
    int m_d8;
    FUN_00c39c80_node* GetHead()
    {
        FUN_00c39c80_node* first = m_d0;
        return first;
    }
    int BSMultiBoundRoom_CheckBound_00c39c80(int a1);
};

// @fnv 0x00c39c80
// src: XBOX_PDB 0x00c39c80
int FUN_00c39c80_cls::BSMultiBoundRoom_CheckBound_00c39c80(int a1)
{
    int res;
    FUN_00c39c80_node* cur;
    FUN_00c39c80_holder* group;
    int r2;
    FUN_00c39c80_holder* owner;
    owner = m_ac;
    res = owner->GetObj()->v94(a1);
    if (res != 1 && !(bool)(int)(m_d8 == 0))
    {
        cur = GetHead();
        while (res != 1 && cur != 0)
        {
            group = GetNext(cur);
            r2 = group->GetObj()->v94(a1);
            if (r2 != 0)
            {
                res = r2;
            }
        }
    }
    return res;
}

static __forceinline void Dead34()
{
    int aiD[34];
}

struct F1f0Lock
{
    unsigned int m_pOwnerObject;
    unsigned int m_lLockCount;
    void __thiscall BSSpinLock_Lock(unsigned int);
    void Unlock()
    {
        m_lLockCount = m_lLockCount - 1;
        if (m_lLockCount == 0)
            m_pOwnerObject = 0;
    }
};

struct F1f0Inner
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
    virtual void* v24(int a, int b, int c, int d, int e, bool f);
};

struct F1f0Obj
{
    F1f0Inner* m_00;
    bool __thiscall LockFreeMapInterface_SetAt(void* p);
    bool Test(int a1, int a2, int a3, bool a4)
    {
        return LockFreeMapInterface_SetAt(m_00->v24(a1, a2, a1, a2, a3, a4));
    }
};

struct F1f0Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    F1f0Lock m_lock;
    F1f0Obj* __thiscall LockFreeMap_GetInterface();
    bool __thiscall LockFreeMap_int64_NiPointer_BSTask_int64_SetAtAlt(int a1, int a2, int a3, bool a4);
};

// @fnv 0x00c3f1f0
// src: COMMUNITY 0x00c3f1f0
bool F1f0Cls::LockFreeMap_int64_NiPointer_BSTask_int64_SetAtAlt(int a1, int a2, int a3, bool a4)
{
    m_lock.BSSpinLock_Lock(0);
    Dead34();
    bool r = LockFreeMap_GetInterface()->Test(a1, a2, a3, a4);
    m_lock.Unlock();
    return r;
}

unsigned int __cdecl FUN_0040fc90();
int __cdecl BSAtomicCompareExchange(unsigned int* p, unsigned int a, unsigned int b);
void __cdecl BSSleep(int);
void __cdecl ProgramFlow();
struct SpinLockS
{
    unsigned int owningThread;
    unsigned int lockCount;
// src: XBOX_PDB 0x0040fbf0
    void __thiscall BSSpinLock_Lock(const char* name)
    {
        unsigned int threadID = FUN_0040fc90();
        if (owningThread == threadID)
        {
            ++lockCount;
            return;
        }
        unsigned int spinCount = 0;
        while (BSAtomicCompareExchange(&owningThread, 0, threadID))
        {
            if (++spinCount > 10000)
                BSSleep(1);
            else
                BSSleep(0);
        }
        ProgramFlow();
        lockCount = 1;
    }
    void Unlock()
    {
        if (--lockCount == 0)
            owningThread = 0;
    }
};

struct WorkerS
{
    bool __thiscall LockFreeMapInterface_SetAt(int a, int b, int c, int d, unsigned char e);
};

struct ManagerS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SpinLockS lock;
    WorkerS* __thiscall LockFreeMap_GetInterface();
    bool __thiscall LockFreeMap_int64_NiPointer_BSTask_int64_SetAt(int a, int b, int c, int d, unsigned char e);
};

static __forceinline void Dead35()
{
    int aiD[35];
}

// @fnv 0x00c3f430
// src: COMMUNITY 0x00c3f430
bool ManagerS::LockFreeMap_int64_NiPointer_BSTask_int64_SetAt(int a, int b, int c, int d, unsigned char e)
{
    lock.BSSpinLock_Lock(0);
    bool result = LockFreeMap_GetInterface()->LockFreeMapInterface_SetAt(a, b, c, d, e);
    Dead35();
    lock.Unlock();
    return result;
}

namespace fnv_00c3f8c0 {
class SpawnedBase
{
  public:
    virtual void unk00();
    virtual ~SpawnedBase()
    {}
    int unk04;
};

class FUN_00c3f8c0 : public SpawnedBase
{
  public:
    virtual ~FUN_00c3f8c0();
    void LockFreeMap_int64_NiPointer_BSTask_int64_RemoveAll(int flags);
    int unk08;
    int unk0c;
};

// @fnv 0x00c3f8c0
FUN_00c3f8c0::~FUN_00c3f8c0()
{
    this->LockFreeMap_int64_NiPointer_BSTask_int64_RemoveAll(1);
    {
        int unk10 = this->unk0c;
        DAT_011f6238.MemoryManager_Deallocate((void*)unk10);
    }
    {
        int unk18 = this->unk04;
        int unk14 = unk18;
        DAT_011f6238.MemoryManager_Deallocate((void*)unk14);
    }
}
}  // namespace fnv_00c3f8c0


struct FUN_0045c620
{
    NiPlane plane0;
    NiPlane plane1;
    NiPlane plane2;
    NiPlane plane3;
    NiPlane plane4;
    NiPlane plane5;
    unsigned int active;
    FUN_0045c620();
};

struct MatrixC358
{
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    LocalPoint FUN_004b4500(const LocalPoint&);
};

struct OccluderC358
{
    int unk00;
    int unk04;
    LocalPoint center;
    float halfWidth;
    float halfHeight;
    MatrixC358 rotation;
    int unk40;
    FUN_00a699d0s cached;
    LocalPoint corner0;
    LocalPoint corner1;
    LocalPoint corner2;
    LocalPoint corner3;
    LocalPoint last;
    bool cornersDirty;
    bool dirty;
    unsigned char disabled0;
    unsigned char disabled1;
    unsigned char disabled2;
    unsigned char disabled3;
    unsigned char unkEA;
// src: COMMUNITY 0x00c35c10
    inline void BSOcclusionPlane_GetVertices(LocalPoint* out)
    {
        if (!cornersDirty)
        {
            memcpy(out, &corner0, 48);
            return;
        }
        LocalPoint horizontal(halfWidth, 0, 0);
        LocalPoint vertical(0, 0, halfHeight);
        LocalPoint c0, c1, c2, c3;
        horizontal = rotation.FUN_004b4500(horizontal);
        vertical = rotation.FUN_004b4500(vertical);
        c3 = center - horizontal + vertical;
        c2 = center - horizontal - vertical;
        c1 = center + horizontal - vertical;
        c0 = center + horizontal + vertical;
        out[3] = c3;
        out[2] = c2;
        out[1] = c1;
        out[0] = c0;
        memcpy(&corner0, out, 48);
        cornersDirty = false;
    }
    bool BSOcclusionPlane_ViewerOnCorrectSide(LocalPoint point);
};

// @fnv 0x00c358a0
// src: COMMUNITY 0x00c358a0
bool OccluderC358::BSOcclusionPlane_ViewerOnCorrectSide(LocalPoint point)
{
    if (unkEA != 0)
        return true;
    LocalPoint verts[4];
    FUN_0045c620 frustum;
    ((Builder*)this)->BSOcclusionPlane_UpdateFrustumPlanes(point, (FUN_00a699d0s*)&frustum);
    BSOcclusionPlane_GetVertices(verts);
    FUN_00a699d0 plane(verts[0], verts[1], verts[2]);
    if (plane.ClassifyPoint(&point) != 2)
        return false;
    else
        return true;
}
