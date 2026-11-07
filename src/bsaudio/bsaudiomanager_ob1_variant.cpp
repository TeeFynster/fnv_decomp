#include "../../include/NiTMapItem.h"
#include "../../include/Setting.h"
#include "../../include/NiPointer.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}

__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}

__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}

inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../include/BSAudioManagerThread.h"
#include "../../include/BSGameSound.h"
#include "../../include/NP.h"
#include "../../include/NavMeshPtr.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiRefObject.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiPoint3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3/CVec3; this unit's code depends on the stand-in's own overload set and inline bodies (its own NiPoint3/CVec3 bodies differ), so the shared class cannot replace it.
#include "../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& other) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* other);
    float CVec3_Distance(const LocalVec3& other) const;
    LocalVec3 TransformPointByMatrix4(const Mat& matrix);
    LocalVec3 TransformPointByMatrix4(const Matrix4* matrix);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
#include "../../include/NiPoint3.h"
#include "../../include/IOManager.h"
#include "../../include/BSSemaphore_adf080.h"
#include "../../include/BSAudioManager.h"
#include "../../include/BSAudio.h"
#include "../../include/GO.h"
#include "../../include/MemoryManager.h"
#include "../../include/AudioLoadTask.h"

__forceinline NiPoint3::NiPoint3(float ax, float ay, float az) : x(ax), y(ay), z(az)
{}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiRefObject::AcquireReference()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiRefObject::DecRef()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> inline NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (m_pObject)
        ((NiRefObject*)m_pObject)->IncRefCount();
}
template <> inline NiPointer<NiRefObject>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

inline NavMeshPtr::NavMeshPtr(RefObject* object)
{
    m_pObject = (NavMesh*)object;
    if (m_pObject)
        ((NiRefObject*)m_pObject)->IncRefCount();
}
inline NavMeshPtr::NavMeshPtr(const NavMeshPtr& other)
{
    m_pObject = other.m_pObject;
    if (m_pObject)
        ((NiRefObject*)m_pObject)->IncRefCount();
}
inline NavMeshPtr::~NavMeshPtr()
{
    if (m_pObject)
        ((NiRefObject*)m_pObject)->DecRef();
}

inline NP::NP(NiAVObject* object)
{
    p = object;
    if (p)
        ((NiRefObject*)p)->IncRefCount();
}
__forceinline NP::NP(RefObject* object) : p(object)
{
    if (p)
        ((NiRefObject*)p)->AcquireReference();
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
inline void BSSemaphore_adf080::Signal()
{
    ReleaseSemaphore(semaphore, 1, 0);
    InterlockedIncrement(&count);
}
inline void BSSemaphore_adf080::Wait()
{
    WaitForSingleObject(semaphore, 0xffffffff);
    InterlockedDecrement(&count);
}
inline LocalVec3::LocalVec3()
{}
void __cdecl NiObjectGarbage_Add(NiAVObject* object);

// src/bsaudio/bsaudiomanager_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/bsaudio/bsaudiomanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/bsaudio/bsaudiomanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiomanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" int __cdecl FUN_00ec7d40(int);
int __cdecl abs_0072fa80(int param_1);

struct FUN_00ad8d60_shell
{
    int m_uiSoundResourceID;
    int pad;
    int eState;
    bool __thiscall BSSoundHandle_FadeInPlay(int param2);
};
struct FUN_00ada300_shell
{
    void SetConditions_00ada300(float fval, int param);
};
struct FUN_00adb960_shell
{
    bool __thiscall BSAudioManager_SetBalance(int arg1, int arg2);
};
struct FUN_00adbf40_shell
{
    bool BSAudioManager_SetOrientation(float f1, float f2, float f3, float f4);
};
struct FUN_00c3d0e0_stub
{
    bool __thiscall QueuedFileEntry_GetDescription(char* apDescription, unsigned int aiBufferSize, const char* apName);
};
struct FUN_00ae7480_shell : FUN_00c3d0e0_stub
{
    bool __thiscall FUN_00ae7480(char* apDescription, unsigned int aiBufferSize);
};
struct FUN_00adcaa0_shell
{
    void BSAudioManager_UnMuteAllOfType(int param_2, int param_3);
};
struct FUN_00ad84b0_shell
{
    void FUN_00ad84b0(int param_2, int param_3);
};
struct FUN_00adcc10_shell
{
    void __thiscall BSAudioManager_UnPauseAllOfType(int, int);
};
struct FUN_00ad8540_shell
{
    void __thiscall FUN_00ad8540(int param1, bool param2);
};
struct S_00ae5f70
{
    int f0;
    char f4;
    int f8;
};
struct C_00ae5f70
{
    S_00ae5f70* __thiscall Init(S_00ae5f70* p, int a2, int a3, int a4, int a5, int a6, int a7);
};
int __cdecl BSAudioManager_CompareUnsignedValues(unsigned int* a, unsigned int* b);
extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;
struct FUN_00ae6c60_shell
{
    int __thiscall _BSAudioManager_AudioCacheSize();
};
extern int DAT_010a3718;
struct _Base_00441d20
{
    _Base_00441d20();
    ~_Base_00441d20();
};
struct FUN_00ae7020_shell : _Base_00441d20
{
    void __thiscall DestroyFields_00ae7020();
};
struct SoundMessageRecord;
// AudioMessageStack::Push (0x00ae75f0) uses this 16-byte count/bottomless/top/limit layout.
struct AudioMessageStack
{
    void Push(SoundMessageRecord*);
    void PushOne(SoundMessageRecord*);
    SoundMessageRecord* Pop();
    void SetBottomless(bool);
    void* __vecDelDtor(unsigned int);
    unsigned int iCount;
    bool m_bBottomless;
    char _pad_5[3];
    SoundMessageRecord* pTop;
    unsigned int m_uiStackLimit;
};
typedef char _sizecheck_AudioMessageStack[sizeof(AudioMessageStack) == 16 ? 1 : -1];
struct FUN_00ae7510_shell : public AudioMessageStack
{
    void FUN_00ae7510();
};
struct FUN_00ae7510 : public AudioMessageStack
{
    FUN_00ae7510();
};
extern MemoryManager* g_memoryManager;
struct FUN_00ad93f0_shell
{
    void __thiscall FUN_00ad93f0(void);
};
struct FUN_00ae77a0_shell : FUN_00ae7480_shell
{
    void* FUN_00ae77a0(unsigned int flags);
};
template <typename T> struct AudioPointerAllocator
{
    void __thiscall Deallocate(void*);
};
struct Host00ae8ef0
{
    char _p[12];
    AudioPointerAllocator<unsigned int> alloc;
    void __thiscall ClearAndFreeEntry(void* p);
};
struct Helper
{
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(void*);
};
struct BSAudioDefinition
{
    BSAudioDefinition();
};
struct FUN_00ae89f0
{
    unsigned int m_uiSoundID;
    float m_fSoundVolume;
    int _08;
    unsigned int m_uiValueAt0C;
    unsigned int m_uiPlaybackFlags;
    bool m_bValueAt14;
    char _pad[3];
    BSAudioDefinition _18;
    FUN_00ae89f0();
};
extern Setting g_011f6e14;
extern Setting g_011f6e20;
extern Setting g_011f6e2c;
extern Setting g_011f6e38;
extern Setting g_011f6e44;
extern Setting g_011f6e50;
struct AudioVolumes_00ad9da0
{
    float fVal[6];
    float fMult[6];
};
struct FUN_00ad9da0_t
{
    void InitAudioVolumes();
};
struct FUN_00ae6d30_shell
{
    bool __thiscall HasMatchingEntry(unsigned int mask);
};
struct FUN_00ae6e60_shell
{
    bool __thiscall ClearPausedType(int param_2, unsigned char param_3);
};
struct SoundEmitter;
struct SoundMessageRecord;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

extern BSAudio* DAT_011f6d98;
extern char $SG6265[];
struct FUN_00ada330_shell
{
    void __thiscall BSAudioManager_SynchVoiceStates();
};
struct FUN_00addc00_shell
{
    void __thiscall BSAudioManager_Process();
};
struct FUN_00ada1d0_shell
{
    unsigned char _pad[0x134];
    bool m_bUISoundsEnabled;
    void __thiscall InitUISounds(bool);
};
struct BADC7D0Item
{
    unsigned int m_uiKey;
};
class BADC7D0Map
{
  public:
    bool GetAt(unsigned int uiKey, BADC7D0Item*& pkItem);
};
class BADC7D0Cache
{
  public:
    bool ContainsKey(unsigned int uiKey);

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
    BADC7D0Map m_kUnsortedGeometryList;
};
struct CritSecA
{
    int unk[6];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSecA* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSecA* cs);
struct ObjEntry
{
    char unk0[0x144];
    int m_144;
    int m_148;
};
struct ObjNode
{
    ObjNode* m_pNext;
    int unk4;
    ObjEntry* m_pEntryObject;
};
struct ObjRegistry
{
    char unk0[0x94];
    ObjNode* m_pHead;
    char unk98[0xdc - 0x98];
    CritSecA m_kCS;

    bool BSAudioManager_IsInCache(int m_uiSoundID, bool bCheckAlt);
};
extern "C" void __cdecl Warning_005b5e40(const char* msg, int value);
extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;
struct AudioCacheOwner
{
    void BSAudioManager_SetCacheEnabled(int flags);
    void SetAudioCacheSize(int size);
};
struct AE6DE0Slot
{
    void* m_pResource;
    unsigned short m_usState;
    unsigned short unk06;
};
class AE6DE0Table
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
    AE6DE0Slot* m_pkSlots;
    unsigned int m_uiSlotCount;

    bool AddSlot(void* pvData, bool bPrimary);
};
extern "C" int __cdecl CopyRelativeDataPath(int src, char* dst, unsigned int size);
class BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;

    BaseObj_b5112(int aValue);
    ~BaseObj_b5112();
    void SetupBuffer(char* apBuffer);
    void SetMode(int aMode);
};
class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    int m_30;

    FUN_00ae6f50(int aValue);
};

struct AudioHelper7390
{
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove();
};
AudioHelper7390* __stdcall BSAudioManager_QInstance_00ad9060(AudioLoadTask*);
struct Ptr_6e5cc0
{
    void* p;
    Ptr_6e5cc0& operator=(const Ptr_6e5cc0& rhs);
};
struct Msg_ae7990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Ptr_6e5cc0 ptr10;
    union
    {
        float f14[3];
        unsigned short s14[5];
    };
    Msg_ae7990& CopyFrom(const Msg_ae7990& rhs);
};
struct AE8470Item;
struct AE8470List
{
    AE8470Item* m_pkItem;
    AE8470List* m_pkNext;

    void SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*));
};
struct FUN_00ae8550_shell
{
    void __thiscall SortValuesByComparison(int* values, int(__cdecl* compare)(int, int), int count);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);


extern NiPoint3 DAT_011f426c;

class DetectRefPtr
{
  public:
    DetectRefPtr(NiRefObject* pkObject = 0) : m_pPointer(pkObject)
    {
        if (m_pPointer)
            m_pPointer->IncRefCount();
    }
    DetectRefPtr(const DetectRefPtr& kPtr) : m_pPointer(kPtr.m_pPointer)
    {
        if (m_pPointer)
            m_pPointer->IncRefCount();
    }
    ~DetectRefPtr()
    {
        if (m_pPointer)
            m_pPointer->DecRefCount();
    }
    NiRefObject* m_pPointer;
};

class DetectOwner
{
  public:
    bool BSAudioManager_ComposeMessage(int iType, int iParam, int iUnk0, int iUnk1, DetectRefPtr spRetainedObject, NiPoint3 kPoint);
    bool BSAudioManager_Pause(int iParam);
};

// @fnv 0x00adb590
// src: XBOX_PDB 0x00adb590
bool DetectOwner::BSAudioManager_Pause(int iParam)
{
    BSAudioManager_ComposeMessage(3, iParam, 0, 0, DetectRefPtr(0), DAT_011f426c);
    return false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiAVObjPtr
{
    NiRefObject* m_pObject;
    NiAVObjPtr(NiRefObject* p = 0)
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiAVObjPtr();
};

struct BSAudioMgr : BSAudioManager
{
    bool IsPlaying(unsigned int);
    void PostMsg(int eMsg, unsigned int id, int a3, int a4, NiAVObjPtr obj, NiPoint3 pos);
    void BSAudioManager_FadeInPlay(int id, int param);
};

// @fnv 0x00adc670
// src: COMMUNITY 0x00adc670
void BSAudioMgr::BSAudioManager_FadeInPlay(int id, int param)
{
    if (IsPlaying(id))
        return;
    PostMsg(7, id, 0, 0, 0, NiPoint3::ZERO);
    PostMsg(1, id, 0, 0, 0, NiPoint3::ZERO);
    PostMsg(0xb, id, 0, param, 0, NiPoint3::ZERO);
}

struct S_00adc830_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iValue;

    int GetValue() const
    {
        return m_iValue;
    }
};

struct S_00adc830_MapItem
{
    S_00adc830_MapItem* m_pkNext;
    unsigned int m_key;
    S_00adc830_Entry* m_val;
};

struct S_00adc830_Map
{
    virtual unsigned int KeyToHashIndex(unsigned int key) const;
    virtual bool IsKeysEqual(unsigned int a, unsigned int b) const;
    unsigned int m_uiHashSize;
    S_00adc830_MapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    bool GetAt(unsigned int key, S_00adc830_Entry*& val) const
    {
        unsigned int uiIndex = KeyToHashIndex(key);
        S_00adc830_MapItem* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(pkItem->m_key, key))
            {
                val = pkItem->m_val;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};

class C_00adc830
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

    S_00adc830_Map m_kFormatEntries;

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

    CritSecA m_kCS;

    int BSAudioManager_GetDuration(unsigned int uiKey);
};

// @fnv 0x00adc830
// src: XBOX_PDB 0x00adc830
int C_00adc830::BSAudioManager_GetDuration(unsigned int uiKey)
{
    int iValue = 0;
    S_00adc830_Entry* pkEntry = 0;
    EnterCriticalSection(&m_kCS);
    m_kFormatEntries.GetAt(uiKey, pkEntry);
    LeaveCriticalSection(&m_kCS);
    iValue = pkEntry ? pkEntry->GetValue() : 0;
    return iValue;
}

extern void* __cdecl NiMalloc(unsigned int);
extern void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
struct FUN_00a1b940
{
    int state, count, data;
    FUN_00a1b940();
    ~FUN_00a1b940();
};
struct MessageStackMember : AudioMessageStack
{
    MessageStackMember();
    ~MessageStackMember();
};
struct SoundMapBase
{
    virtual ~SoundMapBase();
    unsigned int count, capacity;
    void* entries;
    SoundMapBase(unsigned int = 37);
};
struct SoundMap : SoundMapBase
{
    virtual ~SoundMap();
};
struct PointerMapBase
{
    virtual ~PointerMapBase();
    unsigned int capacity;
    void* entries;
    unsigned int count;
    PointerMapBase(unsigned int size = 37);
};
struct PointerMap : PointerMapBase
{
    PointerMap() : PointerMapBase(37)
    {}
    virtual ~PointerMap();
};
struct CachedPointerMapBase
{
    virtual ~CachedPointerMapBase();
    unsigned int capacity;
    void* entries;
    unsigned int count;
    CachedPointerMapBase(unsigned int size = 37)
    {
        capacity = size;
        count = 0;
        unsigned int bytes = capacity * sizeof(void*);
        entries = NiMalloc(bytes);
        unsigned int clearBytes = capacity * sizeof(void*);
        void* clearEntries = entries;
        fnv_zlib_memset(clearEntries, 0, clearBytes);
    }
};
struct CachedPointerMap : CachedPointerMapBase
{
    CachedPointerMap() : CachedPointerMapBase(37)
    {}
    virtual ~CachedPointerMap();
};
struct TaskMapBase
{
    virtual void Release();
    unsigned int count, capacity;
    void* entries;
    TaskMapBase(unsigned int = 37);
};
struct TaskMap : TaskMapBase
{
    virtual void Release();
};
struct AudioList
{
    void* head;
    void* tail;
    unsigned int count;
    AudioList()
    {
        count = 0;
        head = 0;
        tail = 0;
    }
};
struct AudioCriticalSection
{
    int debugInfo, lockCount, recursionCount, owningThread, lockSemaphore, spinCount;
    AudioCriticalSection()
    {
        InitializeCriticalSection(this);
    }
};
struct FUN_00ad90e0
{
    virtual void Update();
    unsigned int state, enabled;
    FUN_00a1b940 channels[2];
    MessageStackMember incoming, outgoing, freeMessages;
    SoundMap sounds;
    PointerMap activeSounds;
    CachedPointerMap cachedSounds;
    TaskMap tasks;
    AudioList pending;
    unsigned int pendingFlags, unknownA4;
    float elapsed;
    AudioCriticalSection messageLock, soundLock, cacheLock, taskLock, listenerLock;
    AudioList completed;
    unsigned long lastTick;
    bool precacheCompleted, updating;
    unsigned int unknown138, unknown13C;
    float volume140, volume144, volume148, volume14C, volume150, volume154;
    float volume158, volume15C, volume160, volume164, volume168, volume16C;
    unsigned int unknown170;
    bool muted, paused;
    unsigned int unknown178, unknown17C, initialized;
    FUN_00ad90e0();
};
// @fnv 0x00ad90e0
FUN_00ad90e0::FUN_00ad90e0()
{
    unknown138 = 0;
    volume140 = 0.0f;
    volume144 = 0.0f;
    volume148 = 0.0f;
    volume14C = 0.0f;
    volume150 = 0.0f;
    volume154 = 0.0f;
    volume158 = 0.0f;
    volume15C = 0.0f;
    volume160 = 0.0f;
    volume164 = 0.0f;
    volume168 = 0.0f;
    volume16C = 0.0f;
    precacheCompleted = false;
    unknownA4 = 0;
    initialized = 1;
    state = 0;
    enabled = 1;
    pendingFlags = 0;
    unknown13C = 0;
    unknown170 = 0;
    updating = false;
    unknownA4 = 0;
    elapsed = 0.0f;
    lastTick = GetTickCount();
    muted = false;
    paused = false;
}

extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned);
struct PoolX
{
    void* Game_DoHeapAlloc(unsigned n);
};
extern PoolX DAT_011f6238;
struct StrSetX
{
    int a;
    char buf[4];
};
extern StrSetX g_str_011f6d9c;
extern char g_empty_01202800[];
struct Ent8
{
    int a, b;
    static void* operator new[](unsigned n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
struct FUN_00ae8650
{
    int m[8];
    FUN_00ae8650();
    static void* operator new(unsigned n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
struct FUN_00ae77d0
{
    int m[19];
    FUN_00ae77d0();
    static void* operator new(unsigned n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
struct ListX
{
    int m0;
    void FUN_00ae75f0(FUN_00ae8650* p);
};
struct MgrX
{
    char p0[0x24];
    ListX l24;
    int p28[3];
    ListX l34;
    int p38[4];
    char b48;
    char p49[0xa4 - 0x49];
    int ma4;
    char pa8[0x13c - 0xa8];
    FUN_00ae77d0* m13c;
    char p140[0x178 - 0x140];
    Ent8* m178;
    unsigned m17c;
    void InitAudioVolumes();
    void BSAudioManager_Initialize();
};
inline const unsigned char* GetName()
{
    const unsigned char* r = &g_str_011f6d9c ? (unsigned char*)g_str_011f6d9c.buf
                                             : (g_empty_01202800[0] = 0, (unsigned char*)g_empty_01202800);
    return r;
}
inline void ClearX(void* p, unsigned n)
{
    FUN_00ec61c0(p, 0, n);
}
inline void DbgX()
{
    const char* a;
    const char* b;
    const char* c;
    const char* d;
    const char* e;
    const char* f;
}
// @fnv 0x00ad9640
// src: COMMUNITY 0x00ad9640
void MgrX::BSAudioManager_Initialize()
{
    if (!*GetName())
        return;
    // ? (unsigned char*)g_str_011f6d9c.buf : (g_empty_01202800[0] = 0, (unsigned char*)g_empty_01202800);
    {
        ma4 = 0;
        m17c = 8;
        m178 = new Ent8[m17c];
        ClearX(m178, m17c * 8);
        InitAudioVolumes();
        unsigned uiCount2 = 0x100;
        unsigned i;
        for (i = 0; i < uiCount2; i++)
            l24.FUN_00ae75f0(new FUN_00ae8650);
        *(char*)&p28[0] = 1;
        unsigned j2;
        for (j2 = 0; j2 < uiCount2; j2++)
            l34.FUN_00ae75f0(new FUN_00ae8650);
        *(char*)&p38[0] = 1;
        b48 = 0;
        m13c = new FUN_00ae77d0;
        DbgX();
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

extern const NiPoint3 NiPoint3_ZERO;

struct RefPointer
{
    NiRefObject* m_pObject;

    RefPointer(NiRefObject* object) throw() : m_pObject(object)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    RefPointer(const RefPointer&) throw();
    ~RefPointer() throw();
};

struct AudioMessageSender
{
    void __thiscall BSAudioManager_ComposeMessage(int message, int id, unsigned short volume, int zero, RefPointer object,
                                 NiPoint3 point);
};

struct BSAudioManagerCall : AudioMessageSender
{
    bool __thiscall BSAudioManager_SetStaticAttenuation(unsigned int id, unsigned short volume);
};

// @fnv 0x00adb720
// src: COMMUNITY 0x00adb720
bool __thiscall BSAudioManagerCall::BSAudioManager_SetStaticAttenuation(unsigned int id, unsigned short volume)
{
    volume = volume > 10000 ? 10000 : volume;
    BSAudioManager_ComposeMessage(0x21, id, volume, 0, RefPointer(0), NiPoint3_ZERO);
    return false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefPointer405
{
    NiRefObject* object;
    RefPointer405(NiRefObject* value) : object(value)
    {
        if (object)
            object->IncRefCount();
    }
    RefPointer405(const RefPointer405& other) : object(other.object)
    {
        if (object)
            object->IncRefCount();
    }
    ~RefPointer405()
    {
        if (object)
            object->DecRef();
    }
};


extern "C" NiPoint3 _NiPoint3_ZERO;

struct FUN_00adb850_cls
{
    void BSAudioManager_ComposeMessage(int message, int soundID, int milliseconds, int flags, RefPointer405 target, NiPoint3 position);
    bool BSAudioManager_SetModFrequency(int soundID, float seconds);
};

// @fnv 0x00adb850
// src: COMMUNITY 0x00adb850
bool FUN_00adb850_cls::BSAudioManager_SetModFrequency(int soundID, float seconds)
{
    BSAudioManager_ComposeMessage(0x42, soundID, static_cast<int>(seconds * 1000.0), 0, RefPointer405(0), _NiPoint3_ZERO);
    return false;
}

namespace fnv_00adcb20 {
extern long(__stdcall* DAT_00fdf1c0)(volatile long*);

struct S_adcb20_Ptr
{
    NiRefObject* m_p;
    __forceinline S_adcb20_Ptr(NiRefObject* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    __forceinline S_adcb20_Ptr(const S_adcb20_Ptr& other)
    {
        m_p = other.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    __forceinline ~S_adcb20_Ptr()
    {}
};

extern NiPoint3 NiPoint3_ZERO;

struct S_adcb20
{
    void BSAudioManager_ComposeMessage(int a1, int a2, int a3, int a4, S_adcb20_Ptr a5, NiPoint3 a6);
    void BSAudioManager_PauseAllOfType(int a1, bool a2);
};

// @fnv 0x00adcb20
// src: COMMUNITY 0x00adcb20
void S_adcb20::BSAudioManager_PauseAllOfType(int a1, bool a2)
{
    if (a2)
        BSAudioManager_ComposeMessage(0x1c, 0, a1, 0, S_adcb20_Ptr(0), NiPoint3_ZERO);
    else
        BSAudioManager_ComposeMessage(0x1a, 0, a1, 0, S_adcb20_Ptr(0), NiPoint3_ZERO);
}
}  // namespace fnv_00adcb20

struct IdentifierState
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    IdentifierState()
    {
        uiID = 0xffffffff;
        m_bLooping = false;
        uiState = 0;
    }
    IdentifierState(const IdentifierState& r)
    {
        uiID = r.uiID;
        m_bLooping = r.m_bLooping;
        uiState = r.uiState;
    }
    ~IdentifierState()
    {}
};
typedef bool(__cdecl* FileCB)(const char*, char*, unsigned int*, unsigned int*);
inline bool AudioXReady(BSAudio* audio)
{
    return audio->bAudioEnabled;
}

inline BSAudio* GetAudioX()
{
    BSAudio* p = (BSAudio*)DAT_011f6d98;
    return p;
}
struct FUN_00ae5870_t
{
    IdentifierState __thiscall BSAudioManager_InitSoundPath(char*, unsigned int, unsigned int);
    IdentifierState __thiscall BSAudioManager_InitSoundForm(const char* pName, unsigned int uiFlags);
};
// @fnv 0x00ae5870
// src: COMMUNITY 0x00ae5870
IdentifierState FUN_00ae5870_t::BSAudioManager_InitSoundForm(const char* pName, unsigned int uiFlags)
{
    unsigned int uiFileFlags_hk = 0;
    if (!AudioXReady(GetAudioX()))
        return IdentifierState();
    FileCB pfnCB_fi = (FileCB)GetAudioX()->pfnIDCallback;
    unsigned int uiExtra_mh = 0;
    char acPath_kmt[260];
    if (!pfnCB_fi || !pfnCB_fi(pName, acPath_kmt, &uiFileFlags_hk, &uiExtra_mh))
        return IdentifierState();
    if ((uiFileFlags_hk & 1) && (uiFlags & 2))
    {
        uiFlags &= ~2;
        uiFlags |= 1;
    }
    if (uiFileFlags_hk & 0x8000000)
    {
        uiFlags |= 0x8000000;
        uiFlags |= 1;
        uiFlags &= ~2;
    }
    if (uiFileFlags_hk & 0x2000000)
    {
        uiFlags |= 0x2000000;
        uiFlags &= ~0x10;
    }
    else if (uiFileFlags_hk & 0x4000000)
    {
        uiFlags |= 0x4000000;
        uiFlags &= ~0x10;
    }
    IdentifierState kHandle_nhzv = BSAudioManager_InitSoundPath(acPath_kmt, uiFlags, uiExtra_mh);
    return kHandle_nhzv;
}

extern int DAT_010a3368, DAT_010a3308, DAT_010a33b0;
extern int DAT_010a3328, DAT_010a3390, DAT_010a3348, DAT_010a3370;
extern "C" void __cdecl _NiFree_00aa10f0(void*);
extern "C" void __cdecl FUN_00a1bbd0();
void __stdcall FUN_0065ee50_Helper(void*, unsigned int, int, void(__cdecl*)());
struct StackView
{
    int offset_00, offset_04, offset_08, offset_0c;
    void SoundMessageStack_Clear();
    ~StackView()
    {
        SoundMessageStack_Clear();
    }
};
struct FramePair
{
    int offset_00, offset_04;
};
template <int N> inline void ReserveFrame();
template <> inline void ReserveFrame<0>()
{}
template <> inline void ReserveFrame<1>()
{
    FramePair frame;
    (void)&frame;
}
template <> inline void ReserveFrame<2>()
{
    FramePair frame, other;
    (void)&frame;
    (void)&other;
}
template <int Pad> struct ListCleanup
{
    ~ListCleanup()
    {
        ReserveFrame<Pad>();
    }
};
template <int Pad> struct ListView : ListCleanup<Pad>
{
    int offset_00, offset_04, offset_08;
    void FUN_00ae8370();
    ~ListView()
    {
        FUN_00ae8370();
    }
};
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct CSView
{
    int offset_00, offset_04, offset_08, offset_0c, offset_10, offset_14;
    ~CSView()
    {
        DeleteCriticalSection(this);
    }
};
template <int* V, int Pad> struct ContainerBase
{
    int offset_04;
    void* offset_08;
    int offset_0c;
    void ClearAll();
    virtual ~ContainerBase()
    {
        ReserveFrame<Pad>();
        ClearAll();
        _NiFree_00aa10f0(offset_08);
    }
};
template <int* V, int* B, int Pad = 1> struct ContainerView : ContainerBase<B, Pad>
{
    virtual ~ContainerView()
    {
        ClearAll();
    }
};
struct ArrayView
{
    int offset_00, offset_04, offset_08, offset_0c, offset_10, offset_14;
    ~ArrayView()
    {
        FUN_0065ee50_Helper(this, 12, 2, FUN_00a1bbd0);
    }
};
struct FUN_00ad93f0
{
    int offset_04, offset_08;
    ArrayView offset_0c;
    StackView offset_24, offset_34, offset_44;
    ContainerView<&DAT_010a3348, &DAT_010a3370> offset_54;
    ContainerView<&DAT_010a3328, &DAT_010a3390, 2> offset_64;
    ContainerView<&DAT_010a3328, &DAT_010a3390> offset_74;
    ContainerView<&DAT_010a3308, &DAT_010a33b0> offset_84;
    ListView<1> offset_94;
    int offset_a0, offset_a4, offset_a8;
    CSView offset_ac, offset_c4, offset_dc, offset_f4, offset_10c;
    ListView<0> offset_124;
    virtual ~FUN_00ad93f0();
};
// @fnv 0x00ad93f0
FUN_00ad93f0::~FUN_00ad93f0()
{}

// 0x00ad9870 -- BSAudioManager::Update
extern int DAT_01202800;

struct H70
{
    char* v;
};
inline void operator delete[](void* p)
{
    ((MemoryManager*)&g_memoryManager)->Deallocate(p);
}

class SetObj_70
{
  public:
    void* m_pVtbl;
    char m_cValue;
    char& GetPtr()
    {
        return this ? m_cValue : (*(char*)&DAT_01202800 = 0, *(char*)&DAT_01202800);
    }
};
extern SetObj_70 g_011f6ebc;

inline BSAudio* GetAudio70()
{
    return DAT_011f6d98;
}
inline bool IsMultiThreaded70(BSAudio* p)
{
    return p->bMultiThread;
}

class MemMgr70
{
  public:
    void __thiscall Deallocate(void* p)
    {
        DeallocateAlias(p);
    }
    void __thiscall DeallocateAlias(void* p);
};
extern MemMgr70* g_memMgr70;

struct BSSoundInfo70
{
    int m_iWordAt00;
    int m_iWordAt04;
    void FUN_00ae8af0();
    ~BSSoundInfo70()
    {
        FUN_00ae8af0();
    }
    void operator delete(void* p)
    {
        ((MemoryManager*)&g_memoryManager)->Deallocate(p);
    }
};

struct BSSoundMsg70
{
    int m_iWordAt00;
    void FUN_00ae86d0();
    ~BSSoundMsg70()
    {
        FUN_00ae86d0();
    }
    void operator delete(void* p)
    {
        ((MemoryManager*)&g_memoryManager)->Deallocate(p);
    }
};

struct BSSoundMsgV70
{
    int m_iWordAt04;
    int GetID() const
    {
        return m_iWordAt04;
    }
    virtual ~BSSoundMsgV70();
};

inline void Free70(void* const& p)
{
    ((MemoryManager*)&g_memoryManager)->Deallocate(p);
}

struct StackNode70
{
    StackNode70* next;
    StackNode70* prev;
    BSSoundMsg70* value;
};
struct SndStack70
{
    StackNode70* head;
    StackNode70* tail;
    unsigned int count;
    bool IsEmpty()
    {
        return count == 0;
    }
    BSSoundMsg70* __thiscall FUN_00ae7f90()
    {
        StackNode70* node = head;
        head = head->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        BSSoundMsg70* value = node->value;
        node->value = 0;
        ((AudioPointerAllocator<unsigned int>*)&count)->Deallocate(node);
        --count;
        return value;
    }
};

struct MapNode70
{
    MapNode70* next;
    int key;
    void* value;
};
struct MsgQueue70
{
    virtual void v0();
    virtual unsigned int Hash(int);
    virtual bool Equal(int, int);
    virtual void v3();
    virtual void ClearValue(MapNode70*);
    virtual void v5();
    virtual void DeleteItem(MapNode70*);
    unsigned int m_uiItemCount;
    MapNode70** m_items;
    unsigned int size;
    void __thiscall FUN_00a0c850(void** pos, int* key, void** value)
    {
        MapNode70* node = (MapNode70*)*pos;
        *key = node->key;
        *value = node->value;
        if (node->next)
            *pos = node->next;
        else
        {
            unsigned int index = Hash(node->key);
            for (++index; index < m_uiItemCount; ++index)
            {
                node = m_items[index];
                if (node)
                {
                    *pos = node;
                    return;
                }
            }
            *pos = 0;
        }
    }
    bool __thiscall FUN_00a1e240(int key)
    {
        unsigned int index = Hash(key);
        MapNode70* node = m_items[index];
        if (node)
        {
            if (Equal(key, node->key))
            {
                m_items[index] = node->next;
                ClearValue(node);
                DeleteItem(node);
                --size;
                return true;
            }
            else
            {
                MapNode70* prev = node;
                MapNode70* current = prev->next;
                while (current && !Equal(key, current->key))
                {
                    prev = current;
                    current = current->next;
                }
                if (current)
                {
                    prev->next = current->next;
                    ClearValue(current);
                    DeleteItem(current);
                    --size;
                    return true;
                }
            }
        }
        return false;
    }
    bool __thiscall FUN_00a1e380(int key, BSSoundInfo70** out)
    {
        unsigned int index = Hash(key);
        MapNode70** bucket = &m_items[index];
        MapNode70* node = *bucket;
        while (node)
        {
            int nodeKey = node->key;
            bool equal = Equal(key, nodeKey);
            if (equal)
            {
                BSSoundInfo70* info = (BSSoundInfo70*)node->value;
                *out = info;
                return true;
            }
            node = node->next;
        }
        return false;
    }
    void __thiscall ClearAll();
    void* First()
    {
        for (unsigned int i = 0; i < m_uiItemCount; i++)
            if (m_items[i])
                return m_items[i];
        return 0;
    }
};

struct InfoQueue70
{
    virtual void v0();
    virtual unsigned int Hash(int);
    virtual bool Equal(int, int);
    virtual void v3();
    virtual void ClearValue(MapNode70*);
    virtual void v5();
    virtual void DeleteItem(MapNode70*);
    unsigned int m_uiItemCount;
    MapNode70** m_items;
    unsigned int size;
    void __thiscall FUN_00a0c850(void** pos, int* key, void** value)
    {
        MapNode70* node = (MapNode70*)*pos;
        *key = node->key;
        *value = node->value;
        if (node->next)
            *pos = node->next;
        else
        {
            unsigned int index = Hash(node->key);
            for (++index; index < m_uiItemCount; ++index)
            {
                node = m_items[index];
                if (node)
                {
                    *pos = node;
                    return;
                }
            }
            *pos = 0;
        }
    }
    bool __thiscall FUN_00a1e240(int key)
    {
        unsigned int index = Hash(key);
        MapNode70* node = m_items[index];
        if (node)
        {
            if (Equal(key, node->key))
            {
                m_items[index] = node->next;
                ClearValue(node);
                DeleteItem(node);
                --size;
                return true;
            }
            else
            {
                MapNode70* prev = node;
                MapNode70* current = prev->next;
                while (current && !Equal(key, current->key))
                {
                    prev = current;
                    current = current->next;
                }
                if (current)
                {
                    prev->next = current->next;
                    ClearValue(current);
                    DeleteItem(current);
                    --size;
                    return true;
                }
            }
        }
        return false;
    }
    bool __thiscall FUN_00a1e380(int key, BSSoundInfo70** out)
    {
        unsigned int index = Hash(key);
        MapNode70** bucket = &m_items[index];
        MapNode70* node = *bucket;
        while (node)
        {
            bool equal = Equal(key, node->key);
            if (equal)
            {
                *out = (BSSoundInfo70*)node->value;
                return true;
            }
            node = node->next;
        }
        return false;
    }
    void __thiscall ClearAll();
    void* First()
    {
        MapNode70* current;
        MapNode70* previous;
        for (unsigned int i = 0; i < m_uiItemCount; i++)
            if (m_items[i])
                return m_items[i];
        return 0;
    }
};

class AudioMgr70
{
  public:
    bool IsEmpty1()
    {
        return m_0c.count == 0;
    }
    bool IsEmpty2()
    {
        return m_18.count == 0;
    }

    void __thiscall InitUISounds(bool);
    void __thiscall BSAudioManager_SetVoiceState(int, int);
    void __thiscall AddSound(int);
    void BSAudioManager_Shutdown();

    int m_00;
    int unk004;
    int unk008;
    SndStack70 m_0c;
    SndStack70 m_18;
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
    MsgQueue70 m_54;
    InfoQueue70 m_64;
    InfoQueue70 m_74;
    MsgQueue70 m_84;
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
    BSSoundMsgV70* m_13c;
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
    H70 m_178;
};

// @fnv 0x00ad9870
// src: COMMUNITY 0x00ad9870
void AudioMgr70::BSAudioManager_Shutdown()
{
    if (!IsMultiThreaded70(GetAudio70()))
    {
        InitUISounds(false);
        InitUISounds(false);
        InitUISounds(false);
    }

    BSSoundMsg70* pInfo = 0;
    while (!m_0c.IsEmpty())
    {
        pInfo = m_0c.FUN_00ae7f90();
        delete pInfo;
    }
    while (!m_18.IsEmpty())
    {
        pInfo = m_18.FUN_00ae7f90();
        delete pInfo;
    }
    pInfo = 0;
    if (m_13c)
    {
        delete m_13c;
        m_13c = 0;
    }

    BSSoundMsgV70* pMsg = 0;
    int iVal7 = 0;
    void* pFirst5 = m_54.First();
    while (pFirst5)
    {
        m_54.FUN_00a0c850(&pFirst5, &iVal7, (void**)&pMsg);
        m_54.FUN_00a1e240(pMsg->GetID());
        BSAudioManager_SetVoiceState(pMsg->GetID(), 0);
        BSSoundMsgV70* pDelete3 = pMsg;
        delete pDelete3;
    }

    m_84.ClearAll();
    void* pFound4 = m_74.First();
    BSSoundInfo70* pOut9 = 0;
    BSSoundInfo70* pDel;
    iVal7 = 0;
    while (pFound4)
    {
        m_74.FUN_00a0c850(&pFound4, &iVal7, (void**)&pDel);
        while (m_64.FUN_00a1e380(iVal7, &pOut9))
        {
            while (m_64.FUN_00a1e240(iVal7))
            {
            }
            delete pOut9;
        }
        delete pDel;
    }
    m_74.ClearAll();

    char cSave3 = g_011f6ebc.GetPtr();
    g_011f6ebc.GetPtr() = 0;
    AddSound(0);
    g_011f6ebc.GetPtr() = cSave3;

    delete[] m_178.v;
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pValue);

struct AudioObjectPtr
{
    NiAVObject* m_pObject;

    AudioObjectPtr(NiAVObject* pkObject = 0) : m_pObject(pkObject)
    {
        int scratch;
        if (m_pObject)
            m_pObject->NiRefObject::IncRefCount();
    }

    ~AudioObjectPtr()
    {
        if (m_pObject)
            InterlockedDecrement((volatile long*)&m_pObject->m_uiRefCount);
    }
};

struct BSAudioThread
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
    BSSemaphore_adf080 m_kRelease;
    int unk38;
    BSSemaphore_adf080 m_kWait;
    int unk44;
    bool m_bSignalled;

    void WaitForSound()
    {
        m_kWait.Wait();
    }

    void ReleaseSemaphoreAndIncrement();
};

struct BSAudioManager_
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
    BSAudioThread* m_pAudioThread;

    void BSAudioManager_SuspendAudioThread();
    void BSAudioManager_ComposeMessage(int a1, int a2, int a3, int a4, AudioObjectPtr ptr, NiPoint3 kPos);
};

// @fnv 0x00ada020
// src: COMMUNITY 0x00ada020
void BSAudioManager_::BSAudioManager_SuspendAudioThread()
{
    if (m_pAudioThread)
        m_pAudioThread->ReleaseSemaphoreAndIncrement();

    BSAudioManager_ComposeMessage(0x35, 0, 0, 0, 0, NiPoint3::ZERO);

    if (m_pAudioThread)
        m_pAudioThread->WaitForSound();
}

namespace fnv_00adb4e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

struct NiPtrB4E0
{
    NiRefObject* m_pObject;
    NiPtrB4E0(NiRefObject* p = 0)
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    NiPtrB4E0(const NiPtrB4E0&);
    ~NiPtrB4E0();
};

struct BSAudioMgrB4E0
{
    bool IsPlaying(unsigned int);
    void PostMsg(int eMsg, unsigned int uiID, unsigned int ulFadeStartTimeTick, int iArg, NiPtrB4E0 kObj, NiPoint3 kPos);
    bool BSAudioManager_PlayAfter(unsigned int id, unsigned int delay, int flags);
};

inline unsigned int AddDelayB4E0(unsigned int delay)
{
    unsigned int t = GetTickCount();
    return t + delay;
}

// @fnv 0x00adb4e0
// src: XBOX_PDB 0x00adb4e0
bool BSAudioMgrB4E0::BSAudioManager_PlayAfter(unsigned int id, unsigned int delay, int)
{
    if (IsPlaying(id))
        return true;
    if (delay > 0x2710)
        delay = 0x2710;
    PostMsg(5, id, AddDelayB4E0(delay), 0, NiPtrB4E0(), NiPoint3_ZERO);
    return true;
}
}  // namespace fnv_00adb4e0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

inline long NiAtomicIncrementB7C0(long& lValue)
{
    return InterlockedIncrement(&lValue);
}
inline long NiAtomicDecrementB7C0(long& lValue)
{
    return InterlockedDecrement(&lValue);
}



class MessageSenderB7C0
{
  public:
    bool BSAudioManager_ComposeMessage(int iType, unsigned int uiTarget, int iDelayMs, int iFlags,
                      NiPointer<NiRefObject> spRetainedObject, NiPoint3 kPos);
    bool BSAudioManager_SetFrequency(unsigned int uiTarget, float m_fDelay);
};

// @fnv 0x00adb7c0
// src: COMMUNITY 0x00adb7c0
bool MessageSenderB7C0::BSAudioManager_SetFrequency(unsigned int uiTarget, float m_fDelay)
{
    BSAudioManager_ComposeMessage(0x13, uiTarget, (int)(m_fDelay * 1000.0), 0, 0, NiPoint3::ZERO);
    return false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
struct FUN_00adc560_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_FadeOut(int a, int b, unsigned int c);
};
// @fnv 0x00adc560
// src: XBOX_PDB 0x00adc560
void FUN_00adc560_cls::BSAudioManager_FadeOut(int a, int b, unsigned int c)
{
    BSAudioManager_ComposeMessage(9, a, 0, b, 0, NiPoint3((float)c, 0.0f, 0.0f));
}

struct Item_adc910
{
    Item_adc910* m_pkNext;
    unsigned int m_uiKey;
    BADC7D0Item* m_pkVal;
};
class Map_adc910
{
  public:
    virtual ~Map_adc910();
    virtual unsigned int KeyToHashIndex(unsigned int uiKey) const;
    virtual bool IsKeysEqual(unsigned int uiKey1, unsigned int uiKey2) const;
    unsigned int m_uiHashSize;
    Item_adc910** m_ppkHashTable;
    bool FUN_00a1e380(unsigned int uiKey, BADC7D0Item*& pkVal) const
    {
        unsigned int uiIndex = KeyToHashIndex(uiKey);
        Item_adc910* pkItem = m_ppkHashTable[uiIndex];
        while (pkItem)
        {
            if (IsKeysEqual(uiKey, pkItem->m_uiKey))
            {
                pkVal = pkItem->m_pkVal;
                return true;
            }
            pkItem = pkItem->m_pkNext;
        }
        return false;
    }
};
struct Loaded_adc910 : BADC7D0Item
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    bool m_bLoadComplete;
    bool IsLoaded() const
    {
        return m_bLoadComplete;
    }
};
struct Cache_adc910
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
    Map_adc910 m_kUnsortedGeometryList;
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
    CritSecA m_kCS;
    bool BSAudioManager_IsPlaying(unsigned int uiKey);
};
// @fnv 0x00adc910
// src: XBOX_PDB 0x00adc910
bool Cache_adc910::BSAudioManager_IsPlaying(unsigned int uiKey)
{
    BADC7D0Item* pkItem = 0;
    EnterCriticalSection(&m_kCS);
    bool bResult;
    if (m_kUnsortedGeometryList.FUN_00a1e380(uiKey, pkItem))
        bResult = pkItem && static_cast<Loaded_adc910*>(pkItem)->IsLoaded();
    else
        bResult = false;
    LeaveCriticalSection(&m_kCS);
    return bResult;
}

struct ScrapHeapBuffer
{
    int unk00, unk04, unk08;
    int used;
    int GetUsed()
    {
        return used;
    }
};

template <class TKey, class TValue> struct BSMapBase
{
    struct Item
    {
        Item* next;
        TKey key;
        TValue value;
    };
    virtual unsigned int Hash(TKey key);
    virtual bool Equal(TKey first, TKey second);
    unsigned int bucketCount;
    Item** buckets;
    unsigned int count;
    bool __thiscall GetAt(TKey key, TValue& value)
    {
        unsigned int bucket = Hash(key);
        Item* item = buckets[bucket];
        while (item)
        {
            if (Equal(key, item->key))
            {
                value = item->value;
                return true;
            }
            item = item->next;
        }
        return false;
    }
};

struct FUN_00adc9a0_shell
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    BSMapBase<unsigned long, ScrapHeapBuffer*> heaps;
    int unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90;
    int unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0;
    int unkB4, unkB8, unkBC, unkC0;
    CritSecA criticalSection;
    int __thiscall BSAudioManager_GetSoundType(unsigned long param_2);
};

// @fnv 0x00adc9a0
// src: COMMUNITY 0x00adc9a0
int __thiscall FUN_00adc9a0_shell::BSAudioManager_GetSoundType(unsigned long param_2)
{
    int uStack2 = 0;
    ScrapHeapBuffer* iStack_c;
    EnterCriticalSection(&criticalSection);
    if (heaps.GetAt(param_2, iStack_c))
    {
        uStack2 = iStack_c == 0 ? 0 : iStack_c->GetUsed();
    }
    else
    {
        uStack2 = 0;
    }
    LeaveCriticalSection(&criticalSection);
    return uStack2;
}

typedef bool(__cdecl* AudioFileResolverD570)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                             unsigned int* puiExtra);

inline bool AudioSystemReadyD570(BSAudio* audio)
{
    return audio->bAudioEnabled;
}
inline AudioFileResolverD570 AudioSystemResolverD570(BSAudio* audio)
{
    return (AudioFileResolverD570)audio->pfnNameCallback;
}

extern BSAudio* g_pkAudioSystemD570;
inline BSAudio* GetAudioSystemD570()
{
    return g_pkAudioSystemD570;
}

class AudioManagerD570
{
  public:
    void BSAudioManager_Precache_00add6f0(const char* pcPath, unsigned int uiFlags, unsigned int uiExtra);
    void BSAudioManager_Precache(const char* pcName, unsigned int uiFlags);
};

// @fnv 0x00add570
// src: COMMUNITY 0x00add570
void AudioManagerD570::BSAudioManager_Precache(const char* pcName, unsigned int uiFlags)
{
    unsigned int uiFlagsCopy = uiFlags;
    AudioFileResolverD570 pfnResolve = AudioSystemResolverD570(GetAudioSystemD570());
    unsigned int uiExtra = 0;
    {
        char acPath[264];
        if (!AudioSystemReadyD570(GetAudioSystemD570()) || !pfnResolve || !pfnResolve(pcName, acPath, &uiFlagsCopy, &uiExtra))
            return;
        BSAudioManager_Precache_00add6f0(acPath, uiFlags, uiExtra);
    }
}

extern "C" int __cdecl strcpy_s(char* dst, unsigned int size, const char* src);
extern "C" unsigned int __cdecl FUN_00ae9d80(const char* path);
struct SndHandleQ
{
    int m_uiSoundID;
    char bFlag;
    int iData;
    SndHandleQ(int id) : m_uiSoundID(id), bFlag(0), iData(0)
    {}
    ~SndHandleQ()
    {}
};
struct SoundQ3
{
    int unk0;
    int m_uiSoundID;
    int iFlags;
    int iExtra;
    char pad10[0x174 - 0x10];
    int iA;
    int iB;
    void FUN_00ae9d50(int);
    void SetAB(int a, int b)
    {
        iA = a;
        iB = b;
    }
    void SetExtra(int e)
    {
        iExtra = e;
    }
};
typedef void(__cdecl* PfnA_Q)(SndHandleQ*, int, int*);
typedef bool(__cdecl* PfnB_Q)(int, int*, int*);
// BSAudio.h lacks the typed virtual callback and sound-creation signatures.
struct AudioQ3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual PfnB_Q GetPfnB();
    virtual SoundQ3* Create(const char*);
    virtual void Normalize(char*);
    bool bReady;
    char pad5[0x2c - 5];
    PfnA_Q pfnA;
    bool IsReady() const
    {
        return bReady;
    }
    PfnA_Q GetPfnA() const
    {
        return pfnA;
    }
};
inline AudioQ3* GetAudioQ3()
{
    return (AudioQ3*)DAT_011f6d98;
}
struct OwnerQ3 : ObjRegistry
{
    char padf4[0x180 - 0xf4];
    int m_iNextID;
    void BSAudioManager_Precache_00add960(SoundQ3*);
    void BSAudioManager_Precache_00add6f0(const char* pPath, int iFlags, int iArg);
};
// @fnv 0x00add6f0
// src: COMMUNITY 0x00add6f0
void OwnerQ3::BSAudioManager_Precache_00add6f0(const char* pPath, int iFlags, int iArg)
{
    if (!pPath || !GetAudioQ3()->IsReady())
        return;
    int iFlags9 = iFlags;
    int iID_2 = m_iNextID++;
    SndHandleQ kHandle3(iID_2);
    char acPath3[0x104];
    strcpy_s(acPath3, 0x104, pPath);
    GetAudioQ3()->Normalize(acPath3);
    unsigned int uiHash3 = FUN_00ae9d80(acPath3);
    if (BSAudioManager_IsInCache(uiHash3, true))
        return;
    SoundQ3* pSound7 = GetAudioQ3()->Create(pPath);
    pSound7->m_uiSoundID = iID_2;
    pSound7->iFlags = iFlags9;
    pSound7->FUN_00ae9d50(0);
    PfnA_Q pfnA = GetAudioQ3()->GetPfnA();
    int iExtraTmp = 0;
    if (pfnA)
        pfnA(&kHandle3, iArg, &iExtraTmp);
    PfnB_Q pfnB4 = GetAudioQ3()->GetPfnB();
    int a9 = 0;
    int b2 = 0;
    if (pfnB4 && pfnB4(iArg, &a9, &b2))
        pSound7->SetAB(a9, b2);
    pSound7->SetExtra(iExtraTmp);
    BSAudioManager_Precache_00add960(pSound7);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern float DAT_010a3484;

// The shared NiPoint3 does not declare the single-int initialization overload.
// Its three-float overload adds argument temporaries in FUN_00adea90.
struct Pos3
{
    float x, y, z;
    Pos3()
    {}
    Pos3(int) : x(DAT_010a3484), y(0.0f), z(0.0f)
    {}
};

inline Pos3& AudioObjectPosition(NiAVObject* object)
{
    return (Pos3&)object->m_kWorld.m_Translate;
}
struct MgrT
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual Pos3* vfn_3();
};

struct EvtT
{
    virtual void vfn_0();
    virtual bool vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19(Pos3 p);
    int GetID() const
    {
        return f4;
    }
    int GetFlags() const
    {
        return f8;
    }
    bool HasFlag20000() const
    {
        return (f10 & 0x20000) != 0;
    }
    int f4;
    int f8;
    int fc;
    int f10;
};

struct Ptr
{
    NiAVObject* m_p;
    Ptr(NiAVObject* p = 0) : m_p(p)
    {
        if (m_p)
            m_p->AcquireReference();
    }
    __forceinline ~Ptr()
    {
        if (m_p)
            m_p->DecRef();
    }
    operator NiAVObject*() const
    {
        return m_p;
    }
    NiAVObject* operator->() const
    {
        return m_p;
    }
    NiAVObject* Get() const
    {
        return m_p;
    }
    bool IsValid() const
    {
        return m_p != 0;
    }
    void DebugCheck() const
    {
        int a, b;
    }
    void FUN_0066b0d0(NiAVObject* p);
};

extern "C" double DAT_010179e0;
extern float DAT_010a3484;

inline BSAudio* AudioInstanceT()
{
    return DAT_011f6d98;
}
inline MgrT* AudioListenerT(BSAudio* audio)
{
    return (MgrT*)audio->pListener;
}

struct MapItem54
{
    MapItem54* next;
    unsigned int key;
    EvtT* val;
};

struct M54
{
    virtual void vfn_0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int k1, unsigned int k2);
    unsigned int m_uiHashSize;
    MapItem54** m_ppkHashTable;
    unsigned int m_uiCount;
    int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    bool FUN_00a1e380(unsigned int n, EvtT** out)
    {
        unsigned int idx = KeyToHashIndex(n);
        MapItem54* item = m_ppkHashTable[idx];
        while (item)
        {
            if (IsKeysEqual(n, item->key))
            {
                *out = item->val;
                return true;
            }
            item = item->next;
        }
        return false;
    }
};

struct MapItem84
{
    MapItem84* next;
    unsigned int key;
    Ptr val;
};

struct M84
{
    virtual void vfn_0();
    virtual unsigned int KeyToHashIndex(unsigned int key);
    virtual bool IsKeysEqual(unsigned int k1, unsigned int k2);
    virtual void vfn_3();
    virtual void ClearValue(MapItem84* item);
    virtual void vfn_5();
    virtual void DeleteItem(MapItem84* item);
    unsigned int n;
    MapItem84** data;
    unsigned int m_uiCount;
    void FUN_00ae7ee0(void** out, unsigned int* pn, Ptr* psp)
    {
        MapItem84* item = (MapItem84*)*out;
        *pn = item->key;
        if (item->next)
        {
            *out = item->next;
            return;
        }
        unsigned int idx = KeyToHashIndex(item->key);
        for (++idx; idx < n; ++idx)
        {
            item = data[idx];
            if (item)
            {
                *out = item;
                return;
            }
        }
        *out = 0;
    }
    bool FUN_00a1e240(unsigned int key)
    {
        unsigned int idx = KeyToHashIndex(key);
        MapItem84* item = data[idx];
        if (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                data[idx] = item->next;
                ClearValue(item);
                DeleteItem(item);
                --m_uiCount;
                return true;
            }
            else
            {
                MapItem84* prev = item;
                MapItem84* curr = prev->next;
                while (curr && !IsKeysEqual(key, curr->key))
                {
                    prev = curr;
                    curr = curr->next;
                }
                if (curr)
                {
                    prev->next = curr->next;
                    ClearValue(curr);
                    DeleteItem(curr);
                    --m_uiCount;
                    return true;
                }
            }
        }
        return false;
    }
    void* FindFirst()
    {
        for (unsigned int k = 0; k < n; k++)
            if (data[k])
                return data[k];
        return 0;
    }
};

struct C_00adea90
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50;
    M54 m54;
    M84 m84;
    void BSAudioManager_UpdateMovingSounds();
    void BSAudioManager_ComposeMessage(int, int, int, int, Ptr, Pos3);
};

// @fnv 0x00adea90
// src: COMMUNITY 0x00adea90
void C_00adea90::BSAudioManager_UpdateMovingSounds()
{
    EvtT* pEvt = 0;
    Ptr sp8;
    if (!AudioListenerT(AudioInstanceT()))
        return;
    Pos3 pos4 = *(AudioListenerT(AudioInstanceT()))->vfn_3();
    Pos3 unusedPos;
    Pos3 n3;
    void* objTmp = m84.FindFirst();
    unsigned int v2 = 0;
    unsigned int val4 = 0;
    while (objTmp)
    {
        pEvt = 0;
        m84.FUN_00ae7ee0(&objTmp, &v2, &sp8);
        m54.FUN_00a1e380(v2, &pEvt);
        val4 = sp8.IsValid() ? sp8->NiRefObject::GetRefCount() : 0;
        if (pEvt && (pEvt->vfn_1() || pEvt->HasFlag20000()) && sp8 && val4 > 2)
        {
            unusedPos = AudioObjectPosition(sp8.Get());
            if (pEvt->GetFlags() & 4)
                unusedPos.z = (float)(unusedPos.z + DAT_010179e0);
            pEvt->vfn_19(unusedPos);
        }
        else if (pEvt == 0)
        {
            m84.FUN_00a1e240(v2);
            if (sp8)
            {
                Ptr g(sp8.Get());
                sp8.DebugCheck();
                NiObjectGarbage_Add(sp8);
                sp8.FUN_0066b0d0(0);
            }
        }
        else if (!sp8)
        {
            BSAudioManager_ComposeMessage(9, pEvt->GetID(), 0, 1000, 0, Pos3(0));
            m84.FUN_00a1e240(v2);
            if (sp8)
            {
                Ptr p(sp8.Get());
                NiObjectGarbage_Add(sp8);
                sp8.FUN_0066b0d0(0);
            }
        }
    }
}

namespace fnv_00adef80 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
struct FUN_00adef80_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_PositionListener(NiPoint3 kPos);
};
// @fnv 0x00adef80
// src: COMMUNITY 0x00adef80
void FUN_00adef80_cls::BSAudioManager_PositionListener(NiPoint3 kPos)
{
    BSAudioManager_ComposeMessage(0x38, 0, 0, 0, 0, kPos);
}
}  // namespace fnv_00adef80

template <class T> inline NiPointer<T>::NiPointer()
{
    m_pObject = 0;
    if (m_pObject)
        ((NiRefObject*)m_pObject)->AcquireReference();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer& rhs) : m_pObject(rhs.m_pObject)
{
    if (m_pObject)
        ((NiRefObject*)m_pObject)->AcquireReference();
}
template <> inline NiPointer<NiAVObject>::~NiPointer()
{
    if (m_pObject)
        ((NiRefObject*)m_pObject)->DecRef();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject)
            ((NiRefObject*)m_pObject)->DecRef();
        m_pObject = pkNew;
        if (m_pObject)
            ((NiRefObject*)m_pObject)->AcquireReference();
    }
    return *this;
}
template <class T> inline T* NiPointer<T>::operator->() const { return m_pObject; }
template <class T> inline NiPointer<T>::operator T*() const { return m_pObject; }

namespace fnv_00adf080 {
struct AudioListener_adf080;

typedef unsigned int UInt32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) void __stdcall DebugBreak();

struct MemoryManagerAllocHelper
{
    void* __thiscall Allocate(unsigned int);
};
extern MemoryManager _g_memoryManager;

namespace AudioTask_adf080 {
class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    int m_30;
    unsigned int m_34;
    FUN_00ae6f50(int value);
    static __forceinline void* operator new(unsigned int size)
    {
        return ((MemoryManagerAllocHelper*)&_g_memoryManager)->Allocate(size);
    }
    static __forceinline void operator delete(void* memory)
    {
        _g_memoryManager.Deallocate(memory);
    }
};
}

extern const NiPoint3 NiPoint3_ZERO;
extern double DAT_01088f48;
extern char DAT_010a3488[];
extern Setting g_011f6e80;
extern Setting g_011f6e8c;
extern Setting g_011f6e98;
static __forceinline float& AudioSettingValue_adf080(Setting* setting)
{
    return setting ? setting->uValue.f : (*(float*)&DAT_01202800 = 0.0f);
}

struct AudioTls_adf080
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
    UInt32 m_uiMemoryContext;
};
extern __declspec(thread) AudioTls_adf080 g_AudioTls_adf080;
static __forceinline UInt32 AudioGetContext_adf080()
{
    return g_AudioTls_adf080.m_uiMemoryContext;
}
static __forceinline void AudioSetContext_adf080(UInt32 context)
{
    g_AudioTls_adf080.m_uiMemoryContext = context;
}

} // namespace fnv_00adf080
__forceinline AutoMemContext::AutoMemContext(int value)
{
    m_eMemoryContext = (MEM_CONTEXT)fnv_00adf080::AudioGetContext_adf080();
    fnv_00adf080::AudioSetContext_adf080(value);
}
__forceinline AutoMemContext::~AutoMemContext()
{
    fnv_00adf080::AudioSetContext_adf080(m_eMemoryContext);
}
namespace fnv_00adf080 {


typedef ::NiPointer<NiAVObject> AudioRef_adf080;
inline bool AudioPointersEqual(const AudioRef_adf080& left, const AudioRef_adf080& right)
{
    return left.m_pObject == right.m_pObject;
}


enum AudioMessageType_adf080
{
    AudioFirst_adf080 = 1,
    AudioLast_adf080 = 66
};
struct SoundMessageRecord
{
    AudioMessageType_adf080 type;
    int id;
    int argument1;
    UInt32 argument2;
    AudioRef_adf080 object;
    union
    {
        float floats[3];
        UInt16 shorts[5];
    };
    __forceinline void SetObject(AudioRef_adf080 value)
    {
        object = value;
    }
    __forceinline AudioMessageType_adf080 GetType() const
    {
        return type;
    }
    __forceinline int GetID() const
    {
        return id;
    }
    __forceinline int GetArgument1() const
    {
        return argument1;
    }
    __forceinline UInt32 GetArgument2() const
    {
        return argument2;
    }
    __forceinline void SetArgument1(int value)
    {
        argument1 = value;
    }
    __forceinline void SetArgument2(UInt32 value)
    {
        argument2 = value;
    }
    __forceinline UInt16 GetShort(unsigned int index) const
    {
        return shorts[index];
    }
    __forceinline NiPoint3 GetAudioPosition() const
    {
        return NiPoint3(floats[0], floats[1], floats[2]);
    }
};
typedef char AudioMessageSize_adf080[sizeof(SoundMessageRecord) == 0x20 ? 1 : -1];

struct AudioMessageNode_adf080
{
    AudioMessageNode_adf080* next;
    AudioMessageNode_adf080* previous;
    SoundMessageRecord* data;
};
struct AudioNodeAllocator_adf080
{
    AudioMessageNode_adf080* __thiscall NiGeometry_AddProperty();
};
struct AudioMessageList_adf080
{
    AudioMessageNode_adf080* first;
    AudioMessageNode_adf080* last;
    AudioNodeAllocator_adf080 allocator;
    void __thiscall AddItem(SoundMessageRecord* const&);
    void __thiscall FUN_00a11db0(AudioMessageNode_adf080*);
    __forceinline void AddHead(SoundMessageRecord* const& message)
    {
        AudioMessageNode_adf080* node = allocator.NiGeometry_AddProperty();
        node->data = message;
        FUN_00a11db0(node);
    }
    __forceinline AudioMessageNode_adf080* GetHead() const
    {
        return first;
    }
    __forceinline SoundMessageRecord*& GetNext(AudioMessageNode_adf080*& position)
    {
        SoundMessageRecord*& data = position->data;
        position = position->next;
        return data;
    }
};

} // namespace fnv_00adf080

__forceinline unsigned int BSGameSound::GetID() const
{
    return iSoundID;
}
__forceinline void BSGameSound::SetID(unsigned int value)
{
    iSoundID = value;
}
__forceinline unsigned int BSGameSound::GetFlags() const
{
    return iSoundTypeFlags;
}
__forceinline void BSGameSound::SetFlags(unsigned int value)
{
    iSoundTypeFlags = value;
}
__forceinline void* BSGameSound::GetResource144() const
{
    return (void*)iSoundHash;
}
__forceinline void* BSGameSound::GetResource148() const
{
    return (void*)iDirectoryHash;
}
__forceinline bool BSGameSound::SameResource144(void* value) const
{
    return value == (void*)iSoundHash;
}
__forceinline bool BSGameSound::SameResource148(void* value) const
{
    return value == (void*)iDirectoryHash && iDirectoryHash != 0;
}
__forceinline bool BSGameSound::Ready800() const
{
    return (iStateFlags & 0x800) != 0;
}
__forceinline bool BSGameSound::Ready100() const
{
    return (iStateFlags & 0x100) != 0;
}
__forceinline bool BSGameSound::Pending1() const
{
    return (iStateFlags & 1) != 0;
}
__forceinline bool BSGameSound::Stopped10() const
{
    return (iStateFlags & 0x10) != 0;
}
__forceinline bool BSGameSound::Alternate0c() const
{
    return (iModifierFlags & 1) != 0;
}
__forceinline bool BSGameSound::Alternate1000() const
{
    return (iSoundTypeFlags & 0x1000) != 0;
}
__forceinline bool BSGameSound::Random40() const
{
    return (iSoundTypeFlags & 0x40) != 0;
}
__forceinline bool BSGameSound::SpecialCategory() const
{
    return (iSoundTypeFlags & 0x10) || (iSoundTypeFlags & 0x4000000) || (iSoundTypeFlags & 0x2000000);
}
__forceinline void BSGameSound::Set1000(bool b)
{
    iStateFlags = b ? (iStateFlags | 0x1000) : (iStateFlags & ~0x1000);
}
__forceinline void BSGameSound::Set10(bool b)
{
    iStateFlags = b ? (iStateFlags | 0x10) : (iStateFlags & ~0x10);
}
__forceinline void BSGameSound::Set200(bool b)
{
    iStateFlags = b ? (iStateFlags | 0x200) : (iStateFlags & ~0x200);
}
__forceinline void BSGameSound::Set10000(bool b)
{
    iStateFlags = b ? (iStateFlags | 0x10000) : (iStateFlags & ~0x10000);
}
__forceinline void BSGameSound::Set2000(bool b)
{
    iStateFlags = b ? (iStateFlags | 0x2000) : (iStateFlags & ~0x2000);
}
__forceinline void BSGameSound::SetRandom40(bool b)
{
    b ? iSoundTypeFlags |= 0x40 : iSoundTypeFlags &= ~0x40;
}
__forceinline void BSGameSound::SetRandomPercent(unsigned char value)
{
    iFreqVariance = value;
}
__forceinline unsigned char BSGameSound::GetRandomPercent() const
{
    return iFreqVariance;
}
__forceinline void BSGameSound::SetAttenuation18(unsigned short value)
{
    iStaticAttenuation = value;
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::SetAttenuation1a(unsigned short value)
{
    iReverbAttenuation = value;
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::SetAttenuation1c(unsigned short value)
{
    iSystemAttenuation = value;
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::SetFade20(double value)
{
    iFaderAttenuation = (unsigned short)value;
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::SetFade1c(double fraction)
{
    iSystemAttenuation = (unsigned short)(fraction * fnv_00adf080::DAT_01088f48);
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::SetAttenuation20(unsigned short value)
{
    iFaderAttenuation = value;
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::RefreshVolume()
{
    v3c(fCurrentVolume);
}
__forceinline void BSGameSound::Set164(unsigned int value)
{
    fnCompletionCallback = (void*)value;
}
__forceinline void BSGameSound::Set168(unsigned int value)
{
    fnPlayedCallback = (void*)value;
}
__forceinline void BSGameSound::Set16c(int value)
{
    pSoundCompletionContext = (void*)value;
}
__forceinline void BSGameSound::Set170(int value)
{
    pSoundPlayContext = (void*)value;
}
__forceinline void BSGameSound::Set188(int value)
{
    iPriority = value;
}
__forceinline void BSGameSound::SetFrequencyScale(float scale)
{
    iModSamplesPerSecond = (unsigned short)(iSamplesPerSecond * scale);
}
__forceinline void BSGameSound::Set28(int value)
{
    fBeginTime = (float)(value * 0.09375);
}
__forceinline void BSGameSound::Set2c(unsigned short value)
{
    fEndTime = (float)(value * 0.09375);
}
__forceinline void BSGameSound::Set15c(int value)
{
    iSynchStartTime = value;
    iSoundTypeFlags |= 0x1000000;
}
__forceinline void BSGameSound::Clear15c()
{
    iSynchStartTime = 0;
    iSoundTypeFlags &= ~0x1000000;
}
__forceinline void BSGameSound::Set8000(bool b)
{
    iStateFlags = b ? (iStateFlags | 0x8000) : (iStateFlags & ~0x8000);
}
__forceinline void BSGameSound::SetReferenceVector(::NiPoint3 value)
{
    vBeamEnd = value;
    Set8000(true);
}
__forceinline void BSGameSound::QueueTail(SoundMessageRecord* message)
{
    ((fnv_00adf080::AudioMessageList_adf080*)QueuedMessages)->AddItem((fnv_00adf080::SoundMessageRecord* const&)message);
}
__forceinline void BSGameSound::QueueHead(SoundMessageRecord* message)
{
    ((fnv_00adf080::AudioMessageList_adf080*)QueuedMessages)->AddHead((fnv_00adf080::SoundMessageRecord* const&)message);
}

namespace fnv_00adf080 {

template <class TVAL> struct AudioMapItem_adf080
{
    AudioMapItem_adf080* next;
    UInt32 key;
    TVAL val;
};
template <class TVAL> struct AudioMap_adf080
{
    typedef AudioMapItem_adf080<TVAL> Item;
    virtual ~AudioMap_adf080();
    virtual UInt32 KeyToHashIndex(UInt32 key);
    virtual bool IsKeysEqual(UInt32 key1, UInt32 key2);
    virtual void SetValue(Item* item, UInt32 key, TVAL val);
    virtual void ClearValue(Item* item);
    virtual Item* NewItem();
    virtual void DeleteItem(Item* item);
    UInt32 size;
    Item** buckets;
    UInt32 count;
    inline bool GetAt(UInt32 key, TVAL& val)
    {
        UInt32 index = KeyToHashIndex(key);
        Item* item = buckets[index];
        while (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                val = item->val;
                return true;
            }
            item = item->next;
        }
        return false;
    }
    inline void SetAt(UInt32 key, TVAL val)
    {
        UInt32 index = KeyToHashIndex(key);
        Item* item = buckets[index];
        UInt32 depth = 0;
        while (item)
        {
            depth++;
            if (IsKeysEqual(key, item->key))
            {
                item->val = val;
                return;
            }
            item = item->next;
        }
        item = NewItem();
        SetValue(item, key, val);
        item->next = buckets[index];
        buckets[index] = item;
        count++;
    }
    inline bool RemoveAt(UInt32 key)
    {
        UInt32 index = KeyToHashIndex(key);
        Item* item = buckets[index];
        if (item)
        {
            if (IsKeysEqual(key, item->key))
            {
                buckets[index] = item->next;
                ClearValue(item);
                DeleteItem(item);
                count--;
                return true;
            }
            else
            {
                Item* prev = item;
                Item* cur = prev->next;
                while (cur && !IsKeysEqual(key, cur->key))
                {
                    prev = cur;
                    cur = cur->next;
                }
                if (cur)
                {
                    prev->next = cur->next;
                    ClearValue(cur);
                    DeleteItem(cur);
                    count--;
                    return true;
                }
            }
        }
        return false;
    }
    __forceinline Item* GetFirst() const
    {
        for (UInt32 i = 0; i < size; i++)
            if (buckets[i])
                return buckets[i];
        return 0;
    }
    inline void GetNext(Item*& pos, UInt32& key, TVAL& val)
    {
        Item* item = pos;
        key = item->key;
        val = item->val;
        if (item->next)
        {
            pos = item->next;
            return;
        }
        UInt32 i = KeyToHashIndex(item->key);
        for (++i; i < size; i++)
        {
            item = buckets[i];
            if (item)
            {
                pos = item;
                return;
            }
        }
        pos = 0;
    }
};
typedef AudioMap_adf080<BSGameSound*> AudioSoundMap_adf080;
typedef AudioMap_adf080<AudioRef_adf080> AudioRefMap_adf080;
typedef AudioMapItem_adf080<BSGameSound*> AudioSoundItem_adf080;
typedef AudioMapItem_adf080<AudioRef_adf080> AudioRefItem_adf080;

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* semaphore, long count, long* previous);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* handle, unsigned long milliseconds);

} // namespace fnv_00adf080

// src: COMMUNITY 0x00ae7ac0
inline void BSAudioManagerThread::ExitThread_00ae7ac0()
{
    waiting48 = true;
    workSemaphore3c.Signal();
    ForwardCall_00aa6590(0, 0);
}
// src: COMMUNITY 0x00ae7a50
inline void BSAudioManagerThread::Suspended()
{
    waiting48 = true;
    workSemaphore3c.Signal();
    doneSemaphore30.Wait();
    waiting48 = false;
}

namespace fnv_00adf080 {

struct AudioListener_adf080
{
    virtual void v00();
    virtual void v04();
    virtual void v08(const NiPoint3&);
};

extern IOManager* DAT_01202d98;

struct FUN_00aa5140
{
    unsigned int state[624];
    unsigned int index;
    unsigned int seed;
    unsigned int mode;
    FUN_00aa5140();
    UInt32 __thiscall FUN_00aa5230(UInt32);
};
static __forceinline float AudioRandomRange_adf080(float minimum, float maximum)
{
    static FUN_00aa5140 generator;
    UInt32 random = generator.FUN_00aa5230(0xffffffff);
    return (float)(minimum + random * (maximum - minimum) / 4294967296.0);
}

static __forceinline BSAudio* GetAudio_adf080()
{
    return DAT_011f6d98;
}
static __forceinline bool IsMultiThreaded_adf080(BSAudio* audio)
{
    return audio->bMultiThread;
}
static __forceinline AudioListener_adf080* GetListener_adf080(BSAudio* audio)
{
    return (AudioListener_adf080*)audio->pListener;
}
static __forceinline UInt32 GetThreadID_adf080()
{
    return GetCurrentThreadId();
}



} // namespace fnv_00adf080

// @fnv 0x00adf080
// src: COMMUNITY 0x00adf080
bool BSAudioManager::ProcessMessage_00adf080(::SoundMessageRecord* message)
{
    using namespace fnv_00adf080;
    AutoMemContext m_uiMemoryContext(11);
    BSGameSound* pkSound = 0;
    UInt32 now = fnv_00adf080::GetTickCount();
    bool bWasPlaying = false;
    AudioSoundItem_adf080* pkItem;
    UInt32 uId;
    {
        switch (reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetType())
        {
        case 37: {
            pkSound = (BSGameSound*)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
            if (!fnv_00adf080::DAT_01202d98)
            {
                BSAudioManager_ComposeMessage(37, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(), AudioRef_adf080(),
                             fnv_00adf080::NiPoint3_ZERO);
            }
            else if (pkSound)
            {
                bool alternate = !pkSound->FUN_00ae9d50(0);
                BSGameSound* prior = 0;
                if (!(pkSound->GetFlags() & 0x10000))
                    prior = BSAudioManager_GetFromCache(pkSound->GetResource144(), pkSound->GetResource148(), pkSound->GetFlags());
                if (!prior)
                {
                    if (!pkSound->pFilename[0])
                        ::Warning_005b5e40(DAT_010a3488, (int)pkSound->pFilename);
                    AudioTask_adf080::FUN_00ae6f50* task = new AudioTask_adf080::FUN_00ae6f50((int)pkSound);
                    pkSound->Set1000(true);
                    fnv_00adf080::DAT_01202d98->AddTask((QIOTask*)task);
                    (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).SetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound);
                }
                else
                {
                    prior->iSoundTypeFlags = pkSound->GetFlags();
                    if (!alternate && prior->SameResource144(pkSound->GetResource144()))
                    {
                        delete pkSound;
                    }
                    else if (prior->SameResource148(pkSound->GetResource148()))
                    {
                        BSAudioManager_Precache_00add960(pkSound);
                    }
                    pkSound = prior;
                    pkSound->SetID(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID());
                    (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).SetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound);
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
            }
            break;
        }
        case 38: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                pkSound->Set10(true);
                pkSound->Set200(false);
            }
            break;
        }
        case 58: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                int value = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                pkSound->Set164(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2());
                pkSound->Set16c(value);
            }
            break;
        }
        case 59: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                int value = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                pkSound->Set168(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2());
                pkSound->Set170(value);
            }
            break;
        }
        case 39: {
            AudioRef_adf080 incoming;
            incoming.operator=(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->object);
            AudioRef_adf080 previous;
            if ((*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), previous))
            {
                (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).RemoveAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID());
                if (previous->NiRefObject::GetRefCount() == 1)
                    NiObjectGarbage_Add(previous);
                previous = 0;
            }
            (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).SetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), incoming);
            reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->SetObject(0);
            break;
        }
        case 64: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                bool enabled = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                if (enabled)
                    pkSound->SetFlags(pkSound->GetFlags() | 0x40000);
                else
                    pkSound->SetFlags(pkSound->GetFlags() & ~0x40000);
            }
            break;
        }
        case 63: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->Seek(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1());
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueTail((::SoundMessageRecord*)queued);
                }
            }
            break;
        }
        case 1: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {

                    if (!pkSound->CanPlayNow(0, fCurrentGamehour))
                        pkSound->Set10000(true);
                    if ((pkSound->GetFlags() & iMuteMask) && !(pkSound->GetFlags() & 0x800))
                        pkSound->SetAttenuation1c(10000);
                    if (bDialogueFade && !(pkSound->GetFlags() & 0x20) && !(pkSound->GetFlags() & 4) &&
                        !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                    {
                        pkSound->SetAttenuation20((UInt16)(AudioSettingValue_adf080(&g_011f6e80) * 100.0));
                    }
                    if (pkSound->Random40())
                    {
                        float frequency = pkSound->v68();
                        float variation = (float)(pkSound->GetRandomPercent() / 100.0);
                        frequency += AudioRandomRange_adf080(0.0f, (float)(2.0 * variation)) - variation;
                        pkSound->v64(frequency);
                    }
                    if (pkSound->Alternate0c() || pkSound->Alternate1000())
                        pkSound->SetFlagAndApplyValue(bListenerUnderwater);
                    pkSound->RefreshVolume();
                    pkSound->v30(false);
                    bool paused = false;
                    if (HasMatchingEntry(pkSound->GetFlags()))
                        paused = true;
                    if (paused && !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x2000) &&
                        !(pkSound->GetFlags() & 0x1000))
                    {
                        pkSound->v34();
                    }
                    else if (paused && (pkSound->GetFlags() & 0x400000))
                    {
                        pkSound->SetFlagAndApplyValue(true);
                    }
                    else if (paused && !pkSound->SpecialCategory() &&
                             ((pkSound->GetFlags() & 0x2000) || (pkSound->GetFlags() & 0x1000)))
                    {
                        pkSound->v38();
                        pkSound->Set10(true);
                    }
                    pkSound->Set2000(true);
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else if (pkSound->Pending1())
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueTail((::SoundMessageRecord*)queued);
                }
                else
                {
                    BSAudioManager_ComposeMessage(1, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 2: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v30(true);
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueTail((::SoundMessageRecord*)queued);
                }
            }
            break;
        }
        case 3: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v34();
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueTail((::SoundMessageRecord*)queued);
                }
            }
            break;
        }
        case 4: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v38();
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueTail((::SoundMessageRecord*)queued);
                }
            }
            break;
        }
        case 5: {
            if ((UInt32)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() <= now)
            {
                if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
                {
                    if (pkSound->Ready800() && pkSound->Ready100())
                    {

                        if (!pkSound->CanPlayNow(0, fCurrentGamehour))
                            pkSound->Set10000(true);
                        if ((pkSound->GetFlags() & iMuteMask) && !(pkSound->GetFlags() & 0x800))
                            pkSound->SetAttenuation1c(10000);
                        if (bDialogueFade && !(pkSound->GetFlags() & 0x20) && !(pkSound->GetFlags() & 4) &&
                            !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                        {
                            pkSound->SetAttenuation20((UInt16)(AudioSettingValue_adf080(&g_011f6e80) * 100.0));
                        }
                        if (pkSound->Random40())
                        {
                            float frequency = pkSound->v68();
                            float variation = (float)(pkSound->GetRandomPercent() / 100.0);
                            frequency += AudioRandomRange_adf080(0.0f, (float)(2.0 * variation)) - variation;
                            pkSound->v64(frequency);
                        }
                        if (pkSound->Alternate0c() || pkSound->Alternate1000())
                            pkSound->SetFlagAndApplyValue(bListenerUnderwater);
                        pkSound->RefreshVolume();
                        if (!pkSound->IsPaused())
                            pkSound->v30(false);
                        bool paused = false;
                        if (HasMatchingEntry(pkSound->GetFlags()))
                            paused = true;
                        if (paused && !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x2000) &&
                            !(pkSound->GetFlags() & 0x1000))
                        {
                            pkSound->v34();
                        }
                        else if (paused && (pkSound->GetFlags() & 0x400000))
                        {
                            pkSound->SetFlagAndApplyValue(true);
                        }
                        else if (paused && !pkSound->SpecialCategory() &&
                                 ((pkSound->GetFlags() & 0x2000) || (pkSound->GetFlags() & 0x1000)))
                        {
                            pkSound->v38();
                            pkSound->Set10(true);
                        }
                        pkSound->Set2000(true);
                        BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                    }
                    else
                    {
                        BSAudioManager_ComposeMessage(1, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                     AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                    }
                }
            }
            else
            {
                BSAudioManager_ComposeMessage(5, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(), AudioRef_adf080(),
                             fnv_00adf080::NiPoint3_ZERO);
            }
            break;
        }
        case 6: {
            break;
        }
        case 9: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    if (reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() == 0)
                    {
                        reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->SetArgument1(now);
                        reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->SetArgument2(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2() + now);
                    }
                    UInt32 start = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                    int uiEndTime = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation1c(10000);
                        pkSound->Set200(false);
                        int followup = (UInt32)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition().x;
                        if (followup > 0)
                            BSAudioManager_ComposeMessage(followup, pkSound->GetID(), 0, 0, AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->Set200(true);
                        pkSound->SetFade1c(1.0 - (double)(uiEndTime - now) / (uiEndTime - start));
                        BSAudioManager_ComposeMessage(9, pkSound->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                     AudioRef_adf080(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                    }
                    pkSound->RefreshVolume();
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else
                {
                    if (now >= reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2())
                    {
                        pkSound->SetAttenuation1c(10000);
                        pkSound->Set200(false);
                        int followup = (UInt32)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition().x;
                        if (followup > 0)
                            BSAudioManager_ComposeMessage(followup, pkSound->GetID(), 0, 0, AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                    }
                    else
                    {
                        BSAudioManager_ComposeMessage(9, pkSound->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                     AudioRef_adf080(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                    }
                }
            }
            break;
        }
        case 11: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    if (reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() == 0)
                    {
                        reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->SetArgument1(now);
                        reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->SetArgument2(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2() + now);
                    }
                    UInt32 start = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                    int uiEndTime = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation1c(0);
                        pkSound->Set200(false);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->Set200(true);
                        pkSound->SetFade1c((double)(uiEndTime - now) / (uiEndTime - start));
                        BSAudioManager_ComposeMessage(11, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                     AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                    }
                    pkSound->RefreshVolume();
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else if (pkSound->Ready800() && now >= reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2())
                {
                    pkSound->SetAttenuation1c(0);
                    pkSound->Set200(false);
                    BSAudioManager_ComposeMessage(8, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
                else
                {
                    BSAudioManager_ComposeMessage(11, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 13: {
            bDialogueFade = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID() != 0;
            UInt32 duration = bDialogueFade ? (UInt32)(AudioSettingValue_adf080(&g_011f6e98) * 1000.0)
                                       : (UInt32)(AudioSettingValue_adf080(&g_011f6e8c) * 1000.0);
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if (!(pkSound->GetFlags() & 0x20) && !(pkSound->GetFlags() & 4) && !(pkSound->GetFlags() & 0x800) &&
                    !(pkSound->GetFlags() & 0x100000))
                {
                    if (bDialogueFade)
                    {
                        BSAudioManager_ComposeMessage(10, pkSound->GetID(), now, now + duration, AudioRef_adf080(),
                                     NiPoint3(AudioSettingValue_adf080(&g_011f6e80), 0.0f, 0.0f));
                    }
                    else
                    {
                        BSAudioManager_ComposeMessage(12, pkSound->GetID(), now, now + duration, AudioRef_adf080(),
                                     NiPoint3(AudioSettingValue_adf080(&g_011f6e80), 0.0f, 0.0f));
                    }
                }
            }
            break;
        }
        case 10: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    UInt32 attenuation = (UInt32)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition().x * 100.0);
                    UInt32 start = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                    int uiEndTime = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation20((UInt16)attenuation);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->SetFade20((1.0 - (double)(uiEndTime - now) / (uiEndTime - start)) * attenuation);
                        BSAudioManager_ComposeMessage(10, pkSound->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                     AudioRef_adf080(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                    }
                    pkSound->RefreshVolume();
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(10, pkSound->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                }
            }
            break;
        }
        case 12: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    UInt32 attenuation = (UInt32)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition().x * 100.0);
                    UInt32 start = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                    int uiEndTime = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
                    if (now >= uiEndTime)
                    {
                        pkSound->SetAttenuation20(0);
                    }
                    else if (now < uiEndTime)
                    {
                        pkSound->SetFade20((double)(uiEndTime - now) / (uiEndTime - start) * attenuation);
                        BSAudioManager_ComposeMessage(12, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                     AudioRef_adf080(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                    }
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(12, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                }
            }
            break;
        }
        case 14: {
            pkItem = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            while (pkItem)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(pkItem, uId, pkSound);
                if (pkSound)
                    pkSound->RefreshVolume();
            }
            break;
        }
        case 15: {
            break;
        }
        case 16: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v3c((float)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() / 1000.0));
                    BSAudioManager_SetVoiceState(pkSound->GetID(), pkSound);
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(16, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), 0, AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 17: {
            break;
        }
        case 18: {
            break;
        }
        case 19: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                pkSound->v64((float)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() / 1000.0));
            }
            break;
        }
        case 66: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                pkSound->SetFrequencyScale((float)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() / 1000.0));
            }
            break;
        }
        case 20: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                pkSound->SetRandom40(true);
                pkSound->SetRandomPercent((UInt8)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1());
            }
            break;
        }
        case 21: {
            break;
        }
        case 22: {
            break;
        }
        case 7: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->SetAttenuation1c(10000);
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueHead((::SoundMessageRecord*)queued);
                }
            }
            break;
        }
        case 8: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->SetAttenuation1c(0);
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                    *queued = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                    pkSound->QueueHead((::SoundMessageRecord*)queued);
                }
            }
            break;
        }
        case 23: {
            break;
        }
        case 24: {
            UInt32 uiThreshold = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID();
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            iMuteMask |= mask;
            int duration = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if ((pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                {
                    if (duration && uiThreshold > 5000)
                    {
                        BSAudioManager_ComposeMessage(9, pkSound->GetID(), now, now + duration, AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                    }
                    else if (duration)
                    {
                        duration = duration;
                    }
                    else
                    {
                        pkSound->SetFlagAndApplyValue(true);
                        pkSound->RefreshVolume();
                    }
                }
            }
            break;
        }
        break;
        case 25: {
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            iMuteMask &= ~mask;
            int duration = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if ((pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                {
                    if (duration)
                    {
                        BSAudioManager_ComposeMessage(11, pkSound->GetID(), now, now + duration, AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                    }
                    else
                    {
                        pkSound->SetFlagAndApplyValue(false);
                        pkSound->RefreshVolume();
                    }
                }
            }
            break;
        }
        break;
        case 26: {
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            AddSlot((void*)mask, false);
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if (pkSound->IsPlaying() && (pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) &&
                    !(pkSound->GetFlags() & 0x100000) && !(pkSound->GetFlags() & 0x400000))
                {
                    pkSound->v34();
                }
                else if ((pkSound->GetFlags() & mask) && (pkSound->GetFlags() & 0x400000))
                {
                    pkSound->SetFlagAndApplyValue(true);
                }
            }
            break;
        }
        break;
        case 27: {
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if (!pkSound->Stopped10() && pkSound->IsPaused() && (pkSound->GetFlags() & mask) &&
                    !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000) &&
                    !(pkSound->GetFlags() & 0x400000))
                {
                    pkSound->v30(false);
                }
                else if ((pkSound->GetFlags() & mask) && (pkSound->GetFlags() & 0x400000))
                {
                    pkSound->SetFlagAndApplyValue(false);
                }
            }
            ClearPausedType(mask, 0);
            break;
        }
        break;
        case 28: {
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            AddSlot((void*)mask, true);
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if (!pkSound->HasStatusFlag0x80000() && pkSound->IsPlaying() && (pkSound->GetFlags() & mask) == mask &&
                    !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000) &&
                    !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x2000) &&
                    !(pkSound->GetFlags() & 0x1000) && !pkSound->Stopped10())
                {
                    pkSound->v34();
                }
                else if ((pkSound->GetFlags() & mask) == mask &&
                         ((pkSound->GetFlags() & 0x400000) || (pkSound->GetFlags() & 0x1000) ||
                          (pkSound->GetFlags() & 0x2000)))
                {
                    pkSound->SetFlagAndApplyValue(true);
                }
            }
            break;
        }
        break;
        case 29: {
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if (!pkSound->Stopped10() && pkSound->IsPaused() && (pkSound->GetFlags() & mask) == mask &&
                    !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000) &&
                    !(pkSound->GetFlags() & 0x400000) && !(pkSound->GetFlags() & 0x1000) &&
                    !(pkSound->GetFlags() & 0x2000) && !(pkSound->GetFlags() & 0x1000))
                {
                    pkSound->v30(false);
                }
                else if ((pkSound->GetFlags() & mask) == mask &&
                         ((pkSound->GetFlags() & 0x400000) || (pkSound->GetFlags() & 0x1000) ||
                          (pkSound->GetFlags() & 0x1000) || (pkSound->GetFlags() & 0x2000)))
                {
                    pkSound->SetFlagAndApplyValue(false);
                }
            }
            ClearPausedType(mask, 1);
            break;
        }
        break;
        case 30: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                NiPoint3 value = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition();
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v4c((const ::NiPoint3&)value);
                }
                else
                {
                    fnv_00adf080::SoundMessageRecord* queued4 = 0;
                    AudioMessageList_adf080* kQueued = (AudioMessageList_adf080*)pkSound->QueuedMessages;
                    AudioMessageNode_adf080* iterator = 0;
                    bool foundTmp = false;
                    iterator = kQueued->GetHead();
                    while (iterator && !foundTmp)
                    {
                        queued4 = kQueued->GetNext(iterator);
                        if (queued4 && queued4->GetType() == 30)
                        {
                            *queued4 = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                            foundTmp = true;
                        }
                    }
                    if (!foundTmp)
                    {
                        queued4 = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(GetFreeQueueMessage());
                        *queued4 = *reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message);
                        pkSound->QueueHead((::SoundMessageRecord*)queued4);
                    }
                }
            }
            break;
        }
        case 31: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                NiPoint3 value = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition();
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->SetReferenceVector((const ::NiPoint3&)value);
                }
                else if (!pkSound->Stopped10())
                {
                    AudioRef_adf080 object;
                    object.operator=(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->object);
                    BSAudioManager_ComposeMessage(31, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(), object,
                                 reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition());
                    reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->SetObject(0);
                }
            }
            break;
        }
        case 32: {
            break;
        }
        case 33: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                UInt16 value = (UInt16)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                pkSound->SetAttenuation18(value);
            }
            break;
        }
        case 34: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                UInt16 value = (UInt16)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
                pkSound->SetAttenuation1a(value);
            }
            break;
        }
        case 35: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                float duration = (float)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2() / 1000.0);
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v5c((float)(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1() / 1000.0), duration);
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(35, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 36: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v60(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(0), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(1), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(2), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(3),
                                 reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(4));
                }
                else
                {
                    BSAudioManager_SetAttenuationCurve(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(0), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(1), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(2),
                                 reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(3), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetShort(4));
                }
            }
            break;
        }
        case 40: {
            NiPoint3 origin;
            AudioRef_adf080 object;
            AudioRefItem_adf080* iterator = (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).GetFirst();
            UInt32 uiID;
            while (iterator)
            {
                (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).GetNext(iterator, uiID, object);
                (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).RemoveAt(uiID);
                if (object->NiRefObject::GetRefCount() == 1)
                    NiObjectGarbage_Add(object);
                object.operator=(0);
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(uiID, pkSound);
                if (pkSound)
                {
                    pkSound->v38();
                    pkSound->Set10(true);
                    pkSound->Set200(false);
                }
            }
            break;
        }
        case 41: {
            NiPoint3 navPos;
            AudioRef_adf080 target;
            target.operator=(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->object);
            AudioRef_adf080 object;
            int mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
            AudioRefItem_adf080* aPos = (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).GetFirst();
            UInt32 uiID;
            while (aPos)
            {
                (*reinterpret_cast<AudioRefMap_adf080*>(MovingRefrList)).GetNext(aPos, uiID, object);
                if (AudioPointersEqual(object, target))
                {
                    (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(uiID, pkSound);
                    if (pkSound)
                    {
                        if (!mask || (mask && (mask & pkSound->GetFlags())))
                            pkSound->v38();
                        if ((pkSound->GetFlags() && 0x2000000) || (pkSound->GetFlags() && 0x4000000))
                            pkSound->SetFlags(pkSound->GetFlags() | 0x100);
                    }
                }
            }
            break;
        }
        case 42: {
            UInt32 mask = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1();
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if ((pkSound->GetFlags() & mask) && !(pkSound->GetFlags() & 0x800) && !(pkSound->GetFlags() & 0x100000))
                {
                    pkSound->v38();
                    pkSound->Set200(false);
                    pkSound->Set10(true);
                }
            }
            break;
        }
        case 43: {
            break;
        }
        case 44: {
            break;
        }
        case 45: {
            break;
        }
        case 46: {
            break;
        }
        case 47: {
            break;
        }
        case 48: {
            break;
        }
        case 49: {
            break;
        }
        case 50: {
            break;
        }
        case 51: {
            pkSound = (BSGameSound*)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2();
            if (pkSound)
            {
                AddSound(pkSound);
                delete pkSound;
            }
            break;
        }
        case 52: {
            (*reinterpret_cast<AudioMessageStack*>(GarbageMessages)).Push(message);
            if (IsMultiThreaded_adf080(GetAudio_adf080()) && GetThreadID_adf080() == dwAudioThreadID && pUpdateThread)
            {
                ::DAT_011f6d98->bMultiThread = false;
                pUpdateThread->ExitThread_00ae7ac0();
            }
            break;
        }
        case 53: {
            (*reinterpret_cast<AudioMessageStack*>(GarbageMessages)).Push(message);
            if (IsMultiThreaded_adf080(GetAudio_adf080()) && GetThreadID_adf080() == dwAudioThreadID && pUpdateThread)
            {
                ::DAT_011f6d98->bMultiThread = false;
                LeaveCriticalSection(&(*reinterpret_cast<CritSecA*>(ProcessingCritSection)));
                pUpdateThread->Suspended();
                EnterCriticalSection(&(*reinterpret_cast<CritSecA*>(ProcessingCritSection)));
                bWasPlaying = true;
            }
            else if (GetThreadID_adf080() != dwAudioThreadID)
            {
                DebugBreak();
            }
            break;
        }
        break;
        case 54: {
            break;
        }
        case 55: {
            AudioSoundItem_adf080* iterator = (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetFirst();
            UInt32 soundHandle;
            while (iterator)
            {
                (*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetNext(iterator, soundHandle, pkSound);
                if (!pkSound->Stopped10() && (pkSound->Alternate0c() || pkSound->Alternate1000()))
                    pkSound->SetFlagAndApplyValue(bListenerUnderwater);
            }
            break;
        }
        break;
        case 56: {
            NiPoint3 value = reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetAudioPosition();
            if (GetListener_adf080(GetAudio_adf080()))
            {
                GetListener_adf080(GetAudio_adf080())->v08(value);
                bListenerMoved = true;
            }
            break;
        }
        case 57: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready800() && pkSound->Ready100())
                {
                    pkSound->v48(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1());
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(57, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), 0, AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 65: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
                pkSound->Set188(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1());
            break;
        }
        case 60: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready100())
                {
                    pkSound->Set15c(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1());
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(60, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 61: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                if (pkSound->Ready100())
                {
                    pkSound->Clear15c();
                }
                else if (!pkSound->Stopped10())
                {
                    BSAudioManager_ComposeMessage(61, reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1(), reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2(),
                                 AudioRef_adf080(), fnv_00adf080::NiPoint3_ZERO);
                }
            }
            break;
        }
        case 62: {
            if ((*reinterpret_cast<AudioSoundMap_adf080*>(SoundList)).GetAt(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetID(), pkSound) && pkSound)
            {
                pkSound->Set28(reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument1());
                pkSound->Set2c((UInt16)reinterpret_cast<fnv_00adf080::SoundMessageRecord*>(message)->GetArgument2());
            }
            break;
        }
        }
    }
    return bWasPlaying;
}


namespace fnv_00ae7050 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* apValue);








inline unsigned int GetCurrentTime7050()
{
    return GetTickCount();
}

extern unsigned int DAT_011f6e0c;
extern unsigned int DAT_011f6e10;



} // namespace fnv_00ae7050

// @fnv 0x00ae7050
void AudioLoadTask::Run()
{
    using namespace fnv_00ae7050;
    bool bLoopSound = (static_cast<BSGameSound*>(SoundAssetTmp)->GetFlags() & 0x8000) != 0;
    bool bResult = false;

    if (static_cast<BSGameSound*>(SoundAssetTmp)->GetResource144() == 0 && static_cast<BSGameSound*>(SoundAssetTmp)->GetResource148() != 0)
    {
        static_cast<BSGameSound*>(SoundAssetTmp)->FUN_00ae9d50(true);
        if (BSAudioManager::GetRandomGenerator().BSAudioManager_IsInCache((unsigned int)static_cast<BSGameSound*>(SoundAssetTmp)->GetResource144(), false))
        {
            if (bLoopSound)
            {
                delete static_cast<BSGameSound*>(SoundAssetTmp);
            }
            else
            {
                static_cast<BSGameSound*>(SoundAssetTmp)->Set200(false);
                static_cast<BSGameSound*>(SoundAssetTmp)->Set1000(false);
                static_cast<BSGameSound*>(SoundAssetTmp)->Set10(true);
            }
            return;
        }
    }

    if (bLoopSound && DAT_011f6e0c == (unsigned int)static_cast<BSGameSound*>(SoundAssetTmp)->GetResource144() && GetCurrentTime7050() - DAT_011f6e10 < 1000)
    {
        delete static_cast<BSGameSound*>(SoundAssetTmp);
        return;
    }

    bResult = static_cast<BSGameSound*>(SoundAssetTmp)->v24();
    if (bLoopSound)
    {
        if (bResult)
        {
            DAT_011f6e0c = (unsigned int)static_cast<BSGameSound*>(SoundAssetTmp)->GetResource144();
            DAT_011f6e10 = ::GetTickCount();
            BSAudioManager::GetRandomGenerator().BSAudioManager_ComposeMessage(0x33, 0, 0, (unsigned int)SoundAssetTmp, 0, NiPoint3_ZERO);
        }
        else
        {
            delete static_cast<BSGameSound*>(SoundAssetTmp);
        }
    }
}


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);

extern MemoryManager _g_memoryManager;

struct SoundMessageRecord
{
    int unk00;
    int unk04;
    int unk08;
    SoundMessageRecord* pNext;

    void __thiscall FUN_00ae86d0();
    ~SoundMessageRecord()
    {
        int a;
        int b;
        int c;
        int d;
        FUN_00ae86d0();
    }
    static void operator delete(void* p)
    {
        _g_memoryManager.Deallocate(p);
    }
};

inline void AudioMessageStack::PushOne(SoundMessageRecord* param_2)
{
    SoundMessageRecord* top = pTop;
    param_2->pNext = top;
    pTop = param_2;
    iCount = iCount + 1;
}


inline unsigned int NowA()
{
    unsigned int tick = GetTickCount();
    return tick;
}

// @fnv 0x00ae75f0
void AudioMessageStack::Push(SoundMessageRecord* param_2)
{
    if (param_2 != 0)
    {
        if (this->m_bBottomless && this->iCount > 0x200)
        {
            if ((unsigned int)(NowA() - this->m_uiStackLimit) > 0x3E8)
            {
                delete param_2;
                return;
            }
        }
        PushOne(param_2);
    }
}

namespace fnv_00ae76b0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

extern MemoryManager DAT_011f6238;
struct FUN_00ae8650
{
    FUN_00ae8650()
    {
        m_uiID = 0;
        m_uiValue1 = 0;
        m_uiState = 0;
        m_pNext = 0;
        m_fPlaybackVolume = 0.0f;
        m_fFrequency = 0.0f;
        m_fPan = 0.0f;
    }
    static void* operator new(unsigned int uiSize)
    {
        return DAT_011f6238.Game_DoHeapAlloc(uiSize);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
    FUN_00ae8650* GetNext() const
    {
        return m_pNext;
    }
    unsigned int m_uiID;
    unsigned int m_uiValue1;
    unsigned int m_uiState;
    FUN_00ae8650* m_pNext;
    NiRefObjectPtr_audio m_spSound;
    float m_fPlaybackVolume;
    float m_fFrequency;
    float m_fPan;
};
struct Pool_ae76b0
{
    unsigned int m_uiCount;
    bool m_bCanGrow;
    FUN_00ae8650* pAudioItems;
    unsigned int m_uiLastAlloc;
    FUN_00ae8650* AudioMessageStack_Pop_00ae76b0();
};
// @fnv 0x00ae76b0
// src: COMMUNITY 0x00ae76b0
FUN_00ae8650* Pool_ae76b0::AudioMessageStack_Pop_00ae76b0()
{
    FUN_00ae8650* pkNode = 0;
    if (pAudioItems)
    {
        pkNode = pAudioItems;
        pAudioItems = pAudioItems->GetNext();
        pkNode->m_pNext = 0;
        m_uiCount--;
    }
    else if (m_bCanGrow)
    {
        pkNode = new FUN_00ae8650;
        pkNode->m_pNext = 0;
        m_uiLastAlloc = GetTickCount();
    }
    return pkNode;
}
}  // namespace fnv_00ae76b0

namespace fnv_00ae81e0 {
extern "C" void* __cdecl _alloca(unsigned int);

struct MemoryManagerAllocHelper
{
    void* __thiscall Allocate(unsigned int size);
    void __thiscall Deallocate(void* block);
};
extern MemoryManagerAllocHelper _g_memoryManager;

// Unit-local view of BSSimpleList for 0x00ae81e0 (namespace fnv_00ae81e0): built on the shared BSSimpleList, that code does not compile or does not match.
template <class T> struct BSSimpleList_00ae81e0
{
    T m_item;
    BSSimpleList_00ae81e0<T>* m_pkNext;

    BSSimpleList_00ae81e0(const T& item)
    {
        m_item = item;
        m_pkNext = 0;
    }
    ~BSSimpleList_00ae81e0()
    {
        RemoveAll();
    }
    static void* operator new(unsigned int size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete(void* block)
    {
        _g_memoryManager.Deallocate(block);
    }

    int Count()
    {
        int count = 0;
        BSSimpleList_00ae81e0<T>* iterA = this;
        while (iterA)
        {
            if (iterA->m_item)
                count++;
            iterA = iterA->m_pkNext;
        }
        return count;
    }
    void RemoveAll()
    {
        while (m_pkNext)
        {
            BSSimpleList_00ae81e0<T>* next = m_pkNext->m_pkNext;
            m_pkNext->m_pkNext = 0;
            delete m_pkNext;
            m_pkNext = next;
        }
        m_item = 0;
    }
    void SetItem(T item)
    {
        if (!item)
            return;
        m_item = item;
    }
    void SortList(int(__cdecl* cmp)(T, T))
    {
        BSSimpleList_00ae81e0<T>* current = this;
        BSSimpleList_00ae81e0<T>* previous = 0;
        if (current)
        {
            int count = current->Count();
            bool swapped = true;
            while (count && swapped)
            {
                swapped = false;
                while (current)
                {
                    if (previous)
                    {
                        T item = current->m_item;
                        T prevItem = previous->m_item;
                        if (cmp(prevItem, item) > 0)
                        {
                            current->SetItem(prevItem);
                            previous->SetItem(item);
                            swapped = true;
                        }
                    }
                    previous = current;
                    current = current->m_pkNext;
                }
                count--;
            }
        }
    }
// src: GUESS 0x00ae8550 (confidence: high)
    void SortValuesByComparison(T* arr, int(__cdecl* cmp)(T, T), int count)
    {
        int gap = 0;
        int left = 0;
        int right = count - 1;
        for (gap = 1; gap <= (right - left) / 9; gap = 3 * gap + 1)
        {
        }
        for (; gap > 0; gap /= 3)
        {
            for (int i = left + gap; i <= right; i++)
            {
                int j = i;
                T value = arr[i];
                while (j >= left + gap && cmp(value, arr[j - gap]) < 0)
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = value;
            }
        }
    }
    void ProcessEntries_00ae81e0(int(__cdecl* cmp)(T, T));
};

// @fnv 0x00ae81e0
// src: GUESS 0x00ae81e0 (confidence: low)
template <> void BSSimpleList_00ae81e0<unsigned char*>::ProcessEntries_00ae81e0(int(__cdecl* cmp)(unsigned char*, unsigned char*))
{
    unsigned char** arr5;
    BSSimpleList_00ae81e0<unsigned char*>* node2;
    int i;
    BSSimpleList_00ae81e0<unsigned char*>* prev6;
    int j;
    int _num;
    _num = Count();
    arr5 = (unsigned char**)_alloca(_num * 4 + 4);
    if (!arr5)
    {
        SortList(cmp);
        return;
    }
    node2 = this;
    for (i = 0; i < _num; i++, node2 = node2->m_pkNext)
        arr5[i] = node2->m_item;
    SortValuesByComparison(arr5, cmp, _num);
    RemoveAll();
    node2 = this;
    prev6 = 0;
    for (j = 0; j < _num; j++)
    {
        if (j > 0)
        {
            node2 = new BSSimpleList_00ae81e0<unsigned char*>(arr5[j]);
        }
        else
        {
            node2->m_item = arr5[j];
            node2->m_pkNext = 0;
        }
        if (prev6)
            prev6->m_pkNext = node2;
        prev6 = node2;
    }
}
}  // namespace fnv_00ae81e0

void __cdecl NiFree8F70(void* pvMem);


extern MemoryManager g_kMemoryManager8F70;



class MapBase8F70
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager8F70.Deallocate(pvMem);
    }
    virtual ~MapBase8F70()
    {
        RemoveAll();
        NiFree8F70(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00ae8f70 : public MapBase8F70
{
// @fnv 0x00ae8f70
  public:
    __forceinline FUN_00ae8f70()
    {}
    virtual ~FUN_00ae8f70()
    {
        RemoveAll();
    }
};

void* MakeMap8F70()
{
    return new FUN_00ae8f70;
}

void __cdecl NiFree9060(void* pvMem);


extern MemoryManager g_kMemoryManager9060;



class MapBase9060
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager9060.Deallocate(pvMem);
    }
    virtual ~MapBase9060()
    {
        RemoveAll();
        NiFree9060(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(NiTMapItem<const char*, void*>* pkItem, const char* key, void* val);
    virtual void ClearValue(NiTMapItem<const char*, void*>* pkItem);
    virtual NiTMapItem<const char*, void*>* NewItem();
    virtual void DeleteItem(NiTMapItem<const char*, void*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, void*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, void*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
class FUN_00ae9060 : public MapBase9060
{
// @fnv 0x00ae9060
  public:
    __forceinline FUN_00ae9060()
    {}
    virtual ~FUN_00ae9060()
    {
        RemoveAll();
    }
};

void* MakeMap9060()
{
    return new FUN_00ae9060;
}





// @fnv 0x00adcc10
// src: XBOX_PDB 0x00adcc10
void FUN_00adcc10_shell::BSAudioManager_UnPauseAllOfType(int param1, int param2)
{
    if ((unsigned char)param2)
        ((BSAudioManager*)this)->BSAudioManager_ComposeMessage(0x1d, 0, param1, 0, 0, NiPoint3_ZERO);
    else
        ((BSAudioManager*)this)->BSAudioManager_ComposeMessage(0x1b, 0, param1, 0, 0, NiPoint3_ZERO);
}

namespace fnv_00ada0f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);

struct NiAVObjPtr
{
    NiRefObject* m_pObject;
    NiAVObjPtr(NiRefObject* p = 0)
    {
        int m_uiChunkSize;
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiAVObjPtr();
};

struct AudioThreadA0
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
    BSSemaphore_adf080 m_kDone;

    void __thiscall ReleaseSemaphoreAndIncrement();
    void __thiscall StopAndCloseHandle();

    void WaitDone()
    {
        BSSemaphore_adf080* pSem = &m_kDone;
        WaitForSingleObject(pSem->semaphore, 0xFFFFFFFF);
        InterlockedDecrement(&pSem->count);
    }
};

struct BSAudioMgrA0
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
    AudioThreadA0* m_pAudioThread;

    void BSAudioManager_ComposeMessage(int eMsg, unsigned int id, int a3, int a4, NiAVObjPtr obj, NiPoint3 pos);
    void BSAudioManager_StopAudioThread();
};

// @fnv 0x00ada0f0
// src: COMMUNITY 0x00ada0f0
void BSAudioMgrA0::BSAudioManager_StopAudioThread()
{
    if (m_pAudioThread != 0)
    {
        m_pAudioThread->ReleaseSemaphoreAndIncrement();
    }
    BSAudioManager_ComposeMessage(0x34, 0, 0, 0, 0, NiPoint3::ZERO);
    if (m_pAudioThread != 0)
    {
        m_pAudioThread->WaitDone();
        m_pAudioThread->StopAndCloseHandle();
    }
}
}  // namespace fnv_00ada0f0

namespace fnv_00ada330 {
inline void Dead8()
{
    int a[8];
}
inline void Dead5()
{
    int a[5];
}
inline void Dead2()
{
    int a[2];
}
extern MemoryManager DAT_011f6238;
struct FUN_00ae8af0
{
    int m0;
    int Get() const
    {
        return m0;
    }
    ~FUN_00ae8af0();
    void operator delete(void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
};
struct MapQ
{
    void* vt;
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    bool IsEmpty() const
    {
        return m_uiCount == 0;
    }
    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    void FUN_00a0c850(void*& kPos, unsigned int& key, FUN_00ae8af0*& val) const;
    bool FUN_00a1e380(unsigned int key, FUN_00ae8af0*& val) const;
    bool FUN_00a1e240(unsigned int key);
    void InsertOrUpdate(unsigned int key, FUN_00ae8af0* val);
    void ClearAll();
};
struct OwnerQ
{
    char p00[0x64];
    MapQ m64;
    MapQ m74;
    char p84[0x40];
    CritSecA cs;
    void BSAudioManager_SynchVoiceStates();
};
// @fnv 0x00ada330
// src: COMMUNITY 0x00ada330
void OwnerQ::BSAudioManager_SynchVoiceStates()
{
    EnterCriticalSection(&cs);
    if (!m74.IsEmpty())
    {
        FUN_00ae8af0* SoundAssetTmp;
        void* kPos = m74.GetFirstPos();
        SoundAssetTmp = 0;
        while (kPos)
        {
            unsigned int uiID;
            FUN_00ae8af0* pVal;
            m74.FUN_00a0c850(kPos, uiID, pVal);
            while (m64.FUN_00a1e380(uiID, SoundAssetTmp))
            {
                while (m64.FUN_00a1e240(uiID))
                    ;
                delete SoundAssetTmp;
            }
            Dead8();
            if (pVal->Get())
                m64.InsertOrUpdate(uiID, pVal);
            else
                delete pVal;
        }
        m74.ClearAll();
    }
    bool bReport = false;
    if (bReport && !m64.IsEmpty())
    {
        Dead5();
        void* pos = m64.GetFirstPos();
        Dead2();
        while (pos)
        {
            unsigned int uiID;
            FUN_00ae8af0* pVal;
            m64.FUN_00a0c850(pos, uiID, pVal);
            Warning_005b5e40("AUDIO: ID %i Still In Map", uiID);
        }
        m74.ClearAll();
    }
    LeaveCriticalSection(&cs);
}
}  // namespace fnv_00ada330

namespace fnv_00adad80 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// Unit-local view of NiPointer for 0x00adad80 (namespace fnv_00adad80): built on the shared NiPointer, that code does not compile or does not match.
template <class T> struct NiPointer_00adad80
{
    T* object;
    NiPointer_00adad80(T* p);
    NiPointer_00adad80();
    NiPointer_00adad80(T* p, int);
    ~NiPointer_00adad80()
    {
        if (object)
        {
            T* value = object;
            if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount)))
                value->DeleteThis();
        }
    }
    NiPointer_00adad80& operator=(const NiPointer_00adad80&);
    NiPointer_00adad80& operator=(T*);
    bool IsSet() const
    {
        return object != 0;
    }
};
struct NP501 : NiPointer_00adad80<NiAVObject>
{
    NP501(NiAVObject* p) : NiPointer_00adad80<NiAVObject>(p, 0)
    {}
    ~NP501();
};

// Xbox AudioMessageStack::Push takes BSSoundMessage*: this is the sound record cleared at 0x00adad80.
struct BSSoundMessage
{
    unsigned int id, type, data, flags;
    NiPointer_00adad80<NiAVObject> node;
    NiPoint3 position;
    void SetObj(NP501 sp);
    __forceinline void Reset(NiPoint3 pt, NiPointer_00adad80<NiAVObject> sp);
};
struct FreeList501
{
    void FUN_00ae75f0(BSSoundMessage*);
};
struct Manager501
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FreeList501 messages;
    void BSAudioManager_FreeMessage(BSSoundMessage*);
};
template <class T> inline NiPointer_00adad80<T>::NiPointer_00adad80(T* p)
{
    object = p;
    int dq[2];
    if (object)
    {
        T* value = object;
        InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
}
template <class T> inline NiPointer_00adad80<T>::NiPointer_00adad80(T* p, int)
{
    object = p;
    if (object)
    {
        T* value = object;
        InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
}
template <class T> inline NiPointer_00adad80<T>::NiPointer_00adad80()
{
    object = 0;
    if (object)
    {
        int dq[2];
        T* value = object;
        InterlockedIncrement(reinterpret_cast<volatile long*>(&value->m_uiRefCount));
    }
}
inline void BSSoundMessage::SetObj(NP501 sp)
{
    node = sp;
    int dq2[2];
}
__forceinline void BSSoundMessage::Reset(NiPoint3 pt, NiPointer_00adad80<NiAVObject> sp)
{
    int dqB[2];
    id = 0;
    type = 0;
    data = 0;
    flags = 0;
    node = sp;
    position.x = pt.x;
    position.y = pt.y;
    position.z = pt.z;
}
// @fnv 0x00adad80
// src: COMMUNITY 0x00adad80
void Manager501::BSAudioManager_FreeMessage(BSSoundMessage* message)
{
    NiPointer_00adad80<NiAVObject> old;
    old = message->node;
    if (old.IsSet())
    {
        message->SetObj(0);
        NiObjectGarbage_Add(old.object);
        old = static_cast<NiAVObject*>(0);
    }
    message->Reset(NiPoint3::ZERO, 0);
    messages.FUN_00ae75f0(message);
}
}  // namespace fnv_00adad80

namespace fnv_00adafa0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

// Unit-local view of NiPointer for 0x00adafa0 (namespace fnv_00adafa0): built on the shared NiPointer, that code does not compile or does not match.
template <class T> class NiPointer_00adafa0
{
  public:
    T* p;
    NiPointer_00adafa0(T* q = 0) : p(q)
    {
        if (p)
            p->NiRefObject::IncRefCount();
    }
    NiPointer_00adafa0(const NiPointer_00adafa0& q) : p(q.p)
    {
        if (p)
            p->NiRefObject::IncRefCount();
    }
    ~NiPointer_00adafa0()
    {
        if (p)
            p->DecRef();
    }
    NiPointer_00adafa0& operator=(const NiPointer_00adafa0& q)
    {
        if (p != q.p)
        {
            if (q.p)
                q.p->NiRefObject::IncRefCount();
            if (p)
                p->DecRef();
            p = q.p;
        }
        return *this;
    }
    NiPointer_00adafa0& operator=(T* q)
    {
        if (p != q)
        {
            T* old = p;
            p = q;
            if (p)
                p->NiRefObject::IncRefCount();
            if (old)
                old->DecRef();
        }
        return *this;
    }
    bool operator!=(T* q) const
    {
        return p != q;
    }
};


extern NiPoint3 DAT_011f426c;
struct MessageA
{
    int a, b, c, d;
    NiPointer_00adafa0<NiAVObject> obj;
    NiPoint3 pos;
    __forceinline void SetObj(NP ptr)
    {
        obj = reinterpret_cast<const NiPointer_00adafa0<NiAVObject>&>(ptr);
    }
    __forceinline void Reset(NiPoint3 position, NiPointer_00adafa0<NiAVObject> empty)
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        obj = empty;
        pos.x = position.x;
        pos.y = position.y;
        pos.z = position.z;
    }
};
struct StackA
{
    void FUN_00ae75f0(MessageA*);
};
struct HostA
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24, u28, u2c, u30;
    StackA stack;
    void BSAudioManager_QueueMessage(MessageA*);
};
// @fnv 0x00adafa0
// src: COMMUNITY 0x00adafa0
void HostA::BSAudioManager_QueueMessage(MessageA* msg)
{
    NiPointer_00adafa0<NiAVObject> object;
    object = msg->obj;
    if (object != 0)
    {
        msg->SetObj((NiAVObject*)0);
        NiObjectGarbage_Add(object.p);
        object = (NiAVObject*)0;
    }
    msg->Reset(DAT_011f426c, 0);
    stack.FUN_00ae75f0(msg);
}
}  // namespace fnv_00adafa0

namespace fnv_00adb1a0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(thread) int tls_state;
inline void Dead1()
{
    int a[1];
}
inline void Dead2()
{
    int a[2];
}

inline bool Ready()
{
    BSAudio* a = (BSAudio*)DAT_011f6d98;
    bool b = a->bInitialized;
    return b;
}
inline void SetState(int s)
{
    tls_state = s;
}
struct StateGuard
{
    int m_00;
    StateGuard(int s) : m_00(s)
    {
        tls_state = 11;
    }
    ~StateGuard()
    {
        Dead1();
        SetState(m_00);
    }
};

struct Record
{
    int m_00, m_04, m_08, m_0c;
    NavMeshPtr m_10;
    float m_14, m_18, m_1c;
    void Set(int a, int b, int c, int d, NavMeshPtr n, NiPoint3 p)
    {
        m_00 = a;
        m_04 = b;
        m_08 = c;
        m_0c = d;
        m_10 = n;
        m_14 = p.x;
        m_18 = p.y;
        m_1c = p.z;
        Dead2();
    }
};
struct ListView
{
    char m_00[12];
    void AddItem(const void*);
};
struct Host
{
    int m_00, m_04, m_08;
    ListView m_0c[13];
    char m_a8[4];
    CritSecA m_ac;
    Record* AudioMessageStack_Pop();
    void BSAudioManager_ComposeMessage(int, int, int, int, NavMeshPtr, NiPoint3);
};
// @fnv 0x00adb1a0
// src: XBOX_PDB 0x00adb1a0
void Host::BSAudioManager_ComposeMessage(int a, int b, int c, int d, NavMeshPtr n, NiPoint3 p)
{
    if (Ready())
    {
        StateGuard guard(tls_state);
        EnterCriticalSection(&m_ac);
        Record* result2 = AudioMessageStack_Pop();
        if (result2)
        {
            result2->Set(a, b, c, d, n, p);
            m_0c[m_04].AddItem(&result2);
        }
        LeaveCriticalSection(&m_ac);
    }
    return;
}
}  // namespace fnv_00adb1a0

namespace fnv_00adb3e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern NiPoint3 DAT_011f426c;
struct Host
{
    bool BSAudioManager_IsPlaying(unsigned int);
    void BSAudioManager_ComposeMessage(int, int, int, int, NavMeshPtr, NiPoint3);
    bool BSAudioManager_Play(unsigned int id, bool flag);
};
// @fnv 0x00adb3e0
// src: XBOX_PDB 0x00adb3e0
bool Host::BSAudioManager_Play(unsigned int id, bool flag)
{
    if (BSAudioManager_IsPlaying(id))
        return true;
    if (flag)
        BSAudioManager_ComposeMessage(0x2d, id, 0, 0, (::RefObject*)0, DAT_011f426c);
    BSAudioManager_ComposeMessage(1, id, 0, 0, (::RefObject*)0, DAT_011f426c);
    return true;
}
}  // namespace fnv_00adb3e0

namespace fnv_00adb610 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);


extern NiPoint3 DAT_011f426c;  // NiPoint3::ZERO


struct Handler_adb610
{
    bool BSAudioManager_ComposeMessage(int iType, int iArg, int iParam1, int iParam2, NiPointer<NiRefObject> spRetainedObject,
                      NiPoint3 kPos);
    bool BSAudioManager_Stop(int iArg);
};

// @fnv 0x00adb610
// src: XBOX_PDB 0x00adb610
bool Handler_adb610::BSAudioManager_Stop(int iArg)
{
    BSAudioManager_ComposeMessage(4, iArg, 0, 0, 0, DAT_011f426c);
    return false;
}
}  // namespace fnv_00adb610

namespace fnv_00adb690 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adb690_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_StopMovingSounds(NiRefObject* pObj, float fSeconds, int c);
};
// @fnv 0x00adb690
// src: XBOX_PDB 0x00adb690
void FUN_00adb690_cls::BSAudioManager_StopMovingSounds(NiRefObject* pObj, float fSeconds, int c)
{
    BSAudioManager_ComposeMessage(0x29, 0, (int)(fSeconds * 1000.0), c, pObj, DAT_011f426c);
}
}  // namespace fnv_00adb690

namespace fnv_00adb970 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);


struct FUN_00adb970_cls
{
    bool BSAudioManager_ComposeMessage(int a1, int a2, int a3, int a4, NiPointer<NiRefObject> spRetainedObject, NiPoint3 kPos);
    bool BSAudioManager_SetPosition(int a1, float x, float y, float z);
};

// @fnv 0x00adb970
// src: XBOX_PDB 0x00adb970
bool FUN_00adb970_cls::BSAudioManager_SetPosition(int a1, float x, float y, float z)
{
    NiPoint3 kPos;
    kPos.x = x;
    kPos.y = y;
    kPos.z = z;
    BSAudioManager_ComposeMessage(0x1e, a1, 0, 0, NiPointer<NiRefObject>(0), kPos);
    return false;
}
}  // namespace fnv_00adb970

namespace fnv_00adb9f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);


struct AudioManagerTarget
{
    void BSAudioManager_ComposeMessage(int, unsigned int, int, unsigned int, NiPointer<NiAVObject>, NiPoint3);
    bool BSAudioManager_SetBeamEnd(unsigned int id, float x, float y, float z);
};
// @fnv 0x00adb9f0
// src: XBOX_PDB 0x00adb9f0
bool AudioManagerTarget::BSAudioManager_SetBeamEnd(unsigned int id, float x, float y, float z)
{
    NiPoint3 position(x, y, z);
    BSAudioManager_ComposeMessage(31, id, 0, 0, NiPointer<NiAVObject>(), position);
    return false;
}
}  // namespace fnv_00adb9f0

namespace fnv_00adba70 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adba70_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_SetMinMaxDistance(int a, float fB, float fC);
};
// @fnv 0x00adba70
// src: COMMUNITY 0x00adba70
void FUN_00adba70_cls::BSAudioManager_SetMinMaxDistance(int a, float fB, float fC)
{
    BSAudioManager_ComposeMessage(0x23, a, (unsigned int)(fB * 1000.0), (unsigned int)(fC * 1000.0), 0, DAT_011f426c);
}
}  // namespace fnv_00adba70

namespace fnv_00adbb30 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
inline void Dead1()
{
    int a[1];
}
inline void Dead2()
{
    int a[2];
}
inline void Dead6()
{
    int a[6];
}
inline void Dead8()
{
    int a[8];
}
extern __declspec(thread) int g_tlsMemContext;

extern NiPoint3 NiPoint3_ZERO;

struct FUN_00ae86d0
{
    int type;
    int id;
    int data0;
    int data1;
    NP node;
    union
    {
        float position[3];
        unsigned short values[5];
    };
    __forceinline FUN_00ae86d0(int soundId, NP src, NiPoint3 zero) : node((::RefObject*)0)
    {
        type = 0x24;
        id = soundId;
        data0 = 0;
        data1 = 0;
        reinterpret_cast<NiPointer<NiAVObject>&>(node) = reinterpret_cast<const NiPointer<NiAVObject>&>(src);
        position[0] = zero.x;
        position[1] = zero.y;
        position[2] = zero.z;
    }
    ~FUN_00ae86d0();
    FUN_00ae86d0& CopyFrom(const FUN_00ae86d0& rhs);
    __forceinline void SetValue(int index, unsigned short value)
    {
        values[index] = value;
    }
};

__forceinline const FUN_00ae86d0& Pass(const FUN_00ae86d0& m)
{
    return m;
}
__forceinline int GetCtx()
{
    return g_tlsMemContext;
}
__forceinline void SetCtx(int value)
{
    g_tlsMemContext = value;
}

struct Queue12
{
    int unk00, unk04, unk08;
    void AddItem(const void*);
};

__forceinline bool IsThreaded()
{
    BSAudio* audio = (BSAudio*)DAT_011f6d98;
    return audio->bInitialized;
}
struct AudioOwner
{
    int unk00;
    int queueIndex;
    int unk08;
    Queue12 queue0, queue1, queue2, queue3, queue4, queue5, queue6, queue7, queue8, queue9, queue10, queue11, queue12;
    int unkA8;
    CritSecA critical;
    FUN_00ae86d0* AudioMessageStack_Pop();
    void BSAudioManager_SetAttenuationCurve(int id, unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e);
};

// @fnv 0x00adbb30
// src: COMMUNITY 0x00adbb30
void AudioOwner::BSAudioManager_SetAttenuationCurve(int id, unsigned short a, unsigned short b, unsigned short c, unsigned short d,
                              unsigned short e)
{
    unsigned short contour[5];
    contour[0] = a <= 100 ? a : 100;
    contour[1] = b <= 100 ? b : 100;
    contour[2] = c <= 100 ? c : 100;
    contour[3] = d <= 100 ? d : 100;
    contour[4] = e <= 100 ? e : 100;
    if (IsThreaded())
    {
        AutoMemContext context(11);
        EnterCriticalSection(&critical);
        FUN_00ae86d0* message = AudioMessageStack_Pop();
        message->CopyFrom(static_cast<const FUN_00ae86d0&>(FUN_00ae86d0(id, (::RefObject*)0, NiPoint3_ZERO)));
        Dead6();
        message->SetValue(0, contour[0]);
        message->SetValue(1, contour[1]);
        message->SetValue(2, contour[2]);
        message->SetValue(3, contour[3]);
        message->SetValue(4, contour[4]);
        (&queue0)[queueIndex].AddItem(&message);
        LeaveCriticalSection(&critical);
        Dead2();
    }
}
}  // namespace fnv_00adbb30

namespace fnv_00adbec0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adbec0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_SetReverbAttenuation(int a, unsigned short b);
};
// @fnv 0x00adbec0
// src: COMMUNITY 0x00adbec0
void FUN_00adbec0_cls::BSAudioManager_SetReverbAttenuation(int a, unsigned short b)
{
    BSAudioManager_ComposeMessage(0x22, a, b, 0, 0, DAT_011f426c);
}
}  // namespace fnv_00adbec0

namespace fnv_00adbf50 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adbf50_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    bool BSAudioManager_Release(int a);
};
// @fnv 0x00adbf50
// src: XBOX_PDB 0x00adbf50
bool FUN_00adbf50_cls::BSAudioManager_Release(int a)
{
    BSAudioManager_ComposeMessage(0x26, a, 0, 0, 0, DAT_011f426c);
    return true;
}
}  // namespace fnv_00adbf50

namespace fnv_00adbfd0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

extern NiPoint3 DAT_011f426c;


struct FUN_00adbfd0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int c, int b, NiPointer<NiRefObject> pSceneObject,
                      NiPoint3 kPos);
    bool BSAudioManager_SetCompletionCallback(int a, int b, int c);
};
// @fnv 0x00adbfd0
// src: XBOX_PDB 0x00adbfd0
bool FUN_00adbfd0_cls::BSAudioManager_SetCompletionCallback(int a, int b, int c)
{
    BSAudioManager_ComposeMessage(0x3a, a, c, b, 0, DAT_011f426c);
    return true;
}
}  // namespace fnv_00adbfd0

namespace fnv_00adc050 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc050_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    bool BSAudioManager_SetPlayCallback(int a, int b, int c);
};
// @fnv 0x00adc050
// src: COMMUNITY 0x00adc050
bool FUN_00adc050_cls::BSAudioManager_SetPlayCallback(int a, int b, int c)
{
    BSAudioManager_ComposeMessage(0x3b, a, c, b, 0, DAT_011f426c);
    return true;
}
}  // namespace fnv_00adc050

namespace fnv_00adc0d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc0d0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    bool BSAudioManager_SetVolume(int a, float fSeconds);
};
// @fnv 0x00adc0d0
// src: XBOX_PDB 0x00adc0d0
bool FUN_00adc0d0_cls::BSAudioManager_SetVolume(int a, float fSeconds)
{
    BSAudioManager_ComposeMessage(0x10, a, (int)(fSeconds * 1000.0), 0, 0, DAT_011f426c);
    return true;
}
}  // namespace fnv_00adc0d0

namespace fnv_00adc160 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc160_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_SetRadioVolume();
};
// @fnv 0x00adc160
// src: XBOX_PDB 0x00adc160
void FUN_00adc160_cls::BSAudioManager_SetRadioVolume()
{
    BSAudioManager_ComposeMessage(0xe, 0, 0, 0, 0, DAT_011f426c);
}
}  // namespace fnv_00adc160

namespace fnv_00adc1e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc1e0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_SetObjectToFollow(int a, NiRefObject* pObj);
};
// @fnv 0x00adc1e0
// src: XBOX_PDB 0x00adc1e0
void FUN_00adc1e0_cls::BSAudioManager_SetObjectToFollow(int a, NiRefObject* pObj)
{
    BSAudioManager_ComposeMessage(0x27, a, 0, 0, pObj, DAT_011f426c);
}
}  // namespace fnv_00adc1e0

namespace fnv_00adc360 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc360_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_SetSynchStartTime(int a, int b);
};
// @fnv 0x00adc360
// src: COMMUNITY 0x00adc360
void FUN_00adc360_cls::BSAudioManager_SetSynchStartTime(int a, int b)
{
    BSAudioManager_ComposeMessage(0x3c, a, b, b, 0, DAT_011f426c);
}
}  // namespace fnv_00adc360

namespace fnv_00adc3e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc3e0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_ClearSynchStartTime(int a);
};
// @fnv 0x00adc3e0
// src: COMMUNITY 0x00adc3e0
void FUN_00adc3e0_cls::BSAudioManager_ClearSynchStartTime(int a)
{
    BSAudioManager_ComposeMessage(0x3d, a, 0, 0, 0, DAT_011f426c);
}
}  // namespace fnv_00adc3e0

namespace fnv_00adc460 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc460_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_SetPriority(int a, int b);
};
// @fnv 0x00adc460
// src: COMMUNITY 0x00adc460
void FUN_00adc460_cls::BSAudioManager_SetPriority(int a, int b)
{
    BSAudioManager_ComposeMessage(0x41, a, b, 0, 0, DAT_011f426c);
}
}  // namespace fnv_00adc460

namespace fnv_00adc4e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);


extern NiPoint3 DAT_011f426c;  // NiPoint3::ZERO


struct Handler_adb610
{
    bool BSAudioManager_ComposeMessage(int iType, int iArg, int iParam1, int iParam2, NiPointer<NiRefObject> spRetainedObject,
                      NiPoint3 kPos);
    void BSAudioManager_SetTimeConstraints(int iArg, bool bFlag1, bool bFlag2);
};

// @fnv 0x00adc4e0
// src: COMMUNITY 0x00adc4e0
void Handler_adb610::BSAudioManager_SetTimeConstraints(int iArg, bool bFlag1, bool bFlag2)
{
    BSAudioManager_ComposeMessage(0x3e, iArg, bFlag1, bFlag2, 0, DAT_011f426c);
}
}  // namespace fnv_00adc4e0

namespace fnv_00adc5f0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adc5f0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_FadeIn(int a, int b, int c);
};
// @fnv 0x00adc5f0
// src: COMMUNITY 0x00adc5f0
void FUN_00adc5f0_cls::BSAudioManager_FadeIn(int a, int b, int c)
{
    BSAudioManager_ComposeMessage(0xb, a, 0, b, 0, DAT_011f426c);
}
}  // namespace fnv_00adc5f0

namespace fnv_00adca20 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adca20_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_MuteAllOfType(int a, int b, int c);
};
// @fnv 0x00adca20
// src: XBOX_PDB 0x00adca20
void FUN_00adca20_cls::BSAudioManager_MuteAllOfType(int a, int b, int c)
{
    BSAudioManager_ComposeMessage(0x18, c, a, b, 0, DAT_011f426c);
}
}  // namespace fnv_00adca20

namespace fnv_00adcaa0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adcaa0_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_UnMuteAllOfType(int a, int b);
};
// @fnv 0x00adcaa0
// src: XBOX_PDB 0x00adcaa0
void FUN_00adcaa0_cls::BSAudioManager_UnMuteAllOfType(int a, int b)
{
    BSAudioManager_ComposeMessage(0x19, 0, a, b, 0, DAT_011f426c);
}
}  // namespace fnv_00adcaa0

namespace fnv_00adcd00 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);


template <class T> struct NiPointer_audio
{
    NiPointer_audio(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiPointer_audio()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    T* m_pObject;
};
typedef NiPointer_audio<NiRefObject> NiRefObjectPtr_audio;
extern NiPoint3 DAT_011f426c;
struct FUN_00adcd00_cls
{
    bool BSAudioManager_ComposeMessage(int m_uiSoundID, int a, int b, int c, NiRefObjectPtr_audio pSceneObject, NiPoint3 kPos);
    void BSAudioManager_KillAllOfType(int a, int b);
};
// @fnv 0x00adcd00
// src: XBOX_PDB 0x00adcd00
void FUN_00adcd00_cls::BSAudioManager_KillAllOfType(int a, int b)
{
    BSAudioManager_ComposeMessage(0x2a, 0, a, b, 0, DAT_011f426c);
}
}  // namespace fnv_00adcd00

#include <math.h>
namespace fnv_00adddd0 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" double __cdecl fabs(double);

struct SoundPtr
{
    NiRefObject* ptr;
    __forceinline SoundPtr(NiRefObject* value = 0) : ptr(value)
    {
        if (ptr)
            ptr->IncRefCount();
    }
    __forceinline ~SoundPtr()
    {
        if (ptr)
            ptr->DecRef();
    }
    SoundPtr& Assign(const SoundPtr&);
    SoundPtr& FUN_0066b0d0(NiRefObject* value)
    {
        if (ptr != value)
        {
            if (ptr)
                ptr->DecRef();
            ptr = value;
            if (ptr)
                ptr->IncRefCount();
        }
        return *this;
    }
};
struct Message
{
    unsigned int type;
    unsigned int Type()
    {
        return type;
    }
};
struct MsgNode
{
    MsgNode* next;
    MsgNode* prev;
    Message* value;
};
struct AudioPoolLock
{
    void Lock(const char*);
    void Unlock();
};
extern AudioPoolLock poolLock;
extern MsgNode* poolFree;
void ReplenishPool();
struct NodePoolView
{
    unsigned int count;
    ~NodePoolView()
    {}
    MsgNode* AddHead()
    {
        poolLock.Lock(0);
        if (!poolFree)
            ReplenishPool();
        MsgNode* item = poolFree;
        MsgNode* next = item->next;
        poolFree = next;
        item->value = 0;
        item->next = 0;
        item->prev = 0;
        poolLock.Unlock();
        return item;
    }
    void Deallocate(MsgNode*);
};
struct AudioListBase
{
    MsgNode* head;
    MsgNode* tail;
    NodePoolView pool;
    ~AudioListBase()
    {
        FUN_00ae8370();
    }
    void FUN_00ae8370()
    {
        MsgNode* item = head;
        while (item)
        {
            MsgNode* old = item;
            item = item->next;
            old->value = 0;
            pool.Deallocate(old);
        }
        pool.count = 0;
        head = 0;
        tail = 0;
    }
};
struct FUN_00a1b940 : AudioListBase
{
    FUN_00a1b940();
    ~FUN_00a1b940()
    {}
    Message* FUN_00ae7f90()
    {
        MsgNode* item = head;
        head = head->next;
        if (head)
            head->prev = 0;
        else
            tail = 0;
        Message* value = item->value;
        item->value = 0;
        pool.Deallocate(item);
        --pool.count;
        return value;
    }
    void FUN_00a11db0(MsgNode* item)
    {
        item->next = 0;
        item->prev = tail;
        if (tail)
            tail->next = item;
        else
            head = item;
        tail = item;
        ++pool.count;
    }
    Message*& GetNext(MsgNode*& item)
    {
        Message*& value = item->value;
        item = item->next;
        return value;
    }
    MsgNode* NewNode()
    {
        return pool.AddHead();
    }
    __forceinline bool Empty()
    {
        return pool.count == 0;
    }
    __forceinline void Push(Message* const& message)
    {
        MsgNode* node = pool.AddHead();
        node->value = message;
        FUN_00a11db0(node);
    }
};
struct GameSound
{
    virtual ~GameSound();
    virtual bool Playing();
    virtual void v08();
    virtual bool Paused();
    virtual void v10();
    virtual void Pause(bool);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void Prepare();
    virtual void v2c();
    virtual void Resume(bool);
    virtual void v34();
    virtual void Stop();
    virtual void v3c();
    virtual void v40();
    virtual void Update(int);
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void SetVolume(float);
    virtual float GetVolume();
    unsigned int id, flags, unk0c, state;
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
    float duration;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    float position;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int delay;
    void(__cdecl* callback)(unsigned int, bool);
    unsigned int unk168, callbackArg;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    FUN_00a1b940 messages;
    __forceinline bool Has(unsigned int mask)
    {
        return (state & mask) != 0;
    }
    __forceinline bool Flag(unsigned int mask)
    {
        return (flags & mask) != 0;
    }
    __forceinline void Mark(unsigned int mask, bool enabled)
    {
        state = enabled ? state | mask : state & ~mask;
    }
    __forceinline bool HasMessages()
    {
        return !messages.Empty();
    }
    bool CanPlayNow(unsigned int, float);
    bool Looping()
    {
        return (flags & 0x10) || (flags & 0x4000000) || (flags & 0x2000000);
    }
    bool FUN_00ae9cf0();
    bool FUN_00ae9d10();
    unsigned int ID()
    {
        return id;
    }
    unsigned int Delay()
    {
        return delay;
    }
    unsigned int Flags()
    {
        return flags;
    }
    float Position()
    {
        return position;
    }
    float Duration()
    {
        return duration;
    }
    void SetDelay(unsigned int value)
    {
        delay = value;
    }
    void SetRange(bool enabled)
    {
        state = enabled ? state | 0x10000 : state & ~0x10000;
    }
    void SetStopped(bool enabled)
    {
        state = enabled ? state | 0x10 : state & ~0x10;
    }
    void(__cdecl* Callback())(unsigned int, bool)
    {
        return callback;
    }
    unsigned int CallbackArg()
    {
        return callbackArg;
    }
};
struct SoundEntry
{
    SoundEntry* next;
    unsigned int key;
    SoundPtr value;
};
struct SoundMap
{
    virtual void v00();
    virtual unsigned int Hash(unsigned int);
    virtual bool Equal(unsigned int, unsigned int);
    virtual void v0c();
    virtual void Clear(SoundEntry*);
    virtual void v14();
    virtual void Free(SoundEntry*);
    unsigned int capacity;
    SoundEntry** entries;
    unsigned int count;
    SoundEntry* First()
    {
        for (unsigned int index = 0; index < capacity; index++)
            if (entries[index])
                return entries[index];
        return 0;
    }
    void FUN_00a0c850(SoundEntry** position, unsigned int* key, GameSound** sound)
    {
        SoundEntry* item = *position;
        *key = item->key;
        *sound = (GameSound*)item->value.ptr;
        if (item->next)
            *position = item->next;
        else
        {
            unsigned int index = Hash(item->key);
            ++index;
            for (; index < capacity; ++index)
            {
                item = entries[index];
                if (item)
                {
                    *position = item;
                    return;
                }
            }
            *position = 0;
        }
    }
    bool FUN_00a1e240(unsigned int key)
    {
        unsigned int hash = Hash(key);
        SoundEntry* first = entries[hash];
        if (first)
        {
            if (Equal(key, first->key))
            {
                entries[hash] = first->next;
                Clear(first);
                Free(first);
                --count;
                return true;
            }
            SoundEntry* previous = first;
            SoundEntry* current = first->next;
            while (current && !Equal(key, current->key))
            {
                previous = current;
                current = current->next;
            }
            if (current)
            {
                previous->next = current->next;
                Clear(current);
                Free(current);
                --count;
                return true;
            }
        }
        return false;
    }
    bool LookupValue(unsigned int key, SoundPtr* result)
    {
        unsigned int hash = Hash(key);
        SoundEntry* item = entries[hash];
        while (item)
        {
            if (Equal(key, item->key))
            {
                result->Assign(item->value);
                return true;
            }
            item = item->next;
        }
        return false;
    }
};
struct AudioDevice
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Update();
};
inline AudioDevice* GetAudioDevice(BSAudio* audio)
{
    return (AudioDevice*)audio->pListener;
}
extern BSAudio* audioInstance;
inline BSAudio* Instance()
{
    return audioInstance;
}
extern float DAT_011ac3a0;

extern unsigned int DAT_011f426c, DAT_011f4270, DAT_011f4274;
void __cdecl NiObjectGarbage_Add(NiRefObject*);
inline void SafeDelete(GameSound* value)
{
    delete value;
}
struct AudioUpdate
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
    SoundMap sounds;

    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    SoundMap nodes;

    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    float range;
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
    unsigned int lastTick;
    unsigned char unk134, dirty, unk136, unk137;
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
    bool forceVolume;
    void AddSound(GameSound*);
    bool ProcessMessage_00adf080(Message*);
    void BSAudioManager_QueueMessage(Message*);
    void BSAudioManager_SetVoiceState(unsigned int, GameSound*);
    void BSAudioManager_UpdateMovingSounds();
    void BSAudioManager_ProcessSoundUpdates();
};
// @fnv 0x00adddd0
// src: COMMUNITY 0x00adddd0
void AudioUpdate::BSAudioManager_ProcessSoundUpdates()
{
    NiPoint3 origin41;
    GameSound* sound1;
    SoundEntry* entry24;
    unsigned int cursor5;
    unsigned int previousVal4 = lastTick;
    float difference5 = 0.0f;
    float volume2 = 1.0f;
    if (!GetAudioDevice(Instance()))
        return;
    lastTick = GetTickCount() - previousVal4;
    float target2 = DAT_011ac3a0;
    if (target2 < 0.25)
        target2 = 0.25f;
    if (forceVolume)
        target2 = 1.0f;
    SoundPtr node2A = 0;
    {
        bool result = true;
        sound1 = 0;
        *(unsigned int*)&origin41.x = DAT_011f426c;
        *(unsigned int*)&origin41.y = DAT_011f4270;
        *(unsigned int*)&origin41.z = DAT_011f4274;
        cursor5 = 0;
        entry24 = sounds.First();
        while (entry24)
        {
            sounds.FUN_00a0c850(&entry24, &cursor5, &sound1);
            if (sound1->Has(1) && !sound1->Has(0x800) && sound1->Has(0x100))
            {
                sound1->Prepare();
                AddSound(sound1);
                if (sound1->Has(0x800) && sound1->Has(0x100) && sound1->HasMessages())
                {
                    Message* message10 = 0;
                    FUN_00a1b940* source9 = &sound1->messages;
                    FUN_00a1b940 temporary;
                    MsgNode* item9 = 0;
                    while (!source9->Empty())
                    {
                        temporary.Push(source9->FUN_00ae7f90());
                    }
                    item9 = temporary.head;
                    while (item9)
                    {
                        message10 = temporary.GetNext(item9);
                        if (message10)
                        {
                            if (message10->Type() == 30)
                                ProcessMessage_00adf080(message10);
                        }
                    }
                    while (!temporary.Empty())
                    {
                        message10 = temporary.FUN_00ae7f90();
                        result = ProcessMessage_00adf080(message10);
                        BSAudioManager_QueueMessage(message10);
                        message10 = 0;
                    }
                }
            }
            if (sound1->Has(1) && sound1->Has(0x800) && sound1->Has(0x100))
            {
                if (!sound1->Has(0x10000) && !sound1->CanPlayNow(0, range))
                {
                    sound1->SetRange(true);
                }
                else if (sound1->Has(0x10000) && sound1->CanPlayNow(0, range))
                {
                    sound1->SetRange(false);
                }
                sound1->Update(0);
            }
            if (sound1->Has(0x2000) && !sound1->Playing())
            {
                if ((sound1->Flags() & 0x100) && !sound1->Paused() && sound1->Has(0x800))
                {
                    sound1->SetStopped(true);
                }
            }
            if (sound1->Has(0x10) && !sound1->Has(0x200) && !sound1->Has(0x1000))
            {
                if (sound1->Delay() > 0)
                {
                    unsigned int remaining = sound1->Delay() > lastTick ? sound1->Delay() - lastTick : 0;
                    sound1->SetDelay(remaining);
                }
            }
            if (sound1->Has(0x10) && !sound1->Has(0x200) && !sound1->Has(0x1000) && sound1->Delay() == 0)
            {
                sound1->Update(0);
                void(__cdecl * callback)(unsigned int, bool) = sound1->Callback();
                if (callback)
                {
                    callback(sound1->CallbackArg(), sound1->Has(0x100));
                }
                sounds.FUN_00a1e240(sound1->ID());
                nodes.LookupValue(sound1->ID(), &node2A);
                nodes.FUN_00a1e240(sound1->ID());
                if (node2A.ptr)
                {
                    NiObjectGarbage_Add(node2A.ptr);
                    node2A.FUN_0066b0d0(0);
                }
                if (sound1->HasMessages())
                {
                    Message* message10 = 0;
                    FUN_00a1b940* source9 = &sound1->messages;
                    while (source9 && !source9->Empty())
                    {
                        message10 = source9->FUN_00ae7f90();
                        BSAudioManager_QueueMessage(message10);
                        message10 = 0;
                    }
                }
                BSAudioManager_SetVoiceState(sound1->ID(), 0);
                GameSound* doomed = sound1;
                delete doomed;
                sound1 = 0;
                continue;
            }
            else if (sound1->Has(0x800))
                BSAudioManager_SetVoiceState(sound1->ID(), sound1);
            if ((sound1->FUN_00ae9cf0() || sound1->FUN_00ae9d10()) && !sound1->Flag(0x100) && !sound1->Has(0x20000) &&
                sound1->Playing() && sound1->Looping() && !sound1->Flag(0x2000000) &&
                sound1->Position() > sound1->Duration() * 1.05)
            {
                sound1->Stop();
                sound1->Pause(true);
            }
            else if (sound1->Has(0x20000) && !sound1->Paused() && sound1->Position() < sound1->Duration())
            {
                sound1->Pause(false);
                sound1->Resume(true);
            }
            volume2 = sound1->GetVolume();
            difference5 = target2 - volume2;
            bool fixed9 = sound1->Flag(0x80);
            bool increase = difference5 < 0.0;
            if ((float)fabs(difference5) > 0.01f && (!fixed9 || increase) && sound1->Has(0x800))
            {
                if (!(sound1->Flags() & 0x400000))
                {
                    if (!(sound1->Flags() & 0x100000))
                    {
                        if (!(sound1->Flags() & 0x800))
                        {
                            if (!(sound1->Flags() & 0x20))
                            {
                                if (!(sound1->Flags() & 0x200000))
                                    sound1->SetVolume(target2);
                            }
                        }
                    }
                }
            }
        }
    }
    dirty = false;
    BSAudioManager_UpdateMovingSounds();
    GetAudioDevice(Instance())->Update();
    lastTick = GetTickCount();
}
}  // namespace fnv_00adddd0

namespace fnv_00ae5a50 {
// reconstruction of 0x00ae5a50
extern "C" char DAT_011f6238;  // MemoryManager singleton
extern "C" Setting DAT_011f6e68;  // Setting object
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern "C" void __cdecl FUN_005b5e40_v(const char*, ...);

inline float& GetVolume_00ae5a50()
{
    return &DAT_011f6e68 ? DAT_011f6e68.uValue.f : (*(float*)&DAT_01202800 = 0.0f, *(float*)&DAT_01202800);
}


extern "C" NiPoint3 DAT_011f426c;

struct R_00ae5a50
{
    int f0;
    char f4;
    int f8;
    inline R_00ae5a50(int id) : f0(id), f4(0), f8(0)
    {}
    inline R_00ae5a50(const R_00ae5a50& r) : f0(r.f0), f4(r.f4), f8(r.f8)
    {}
    ~R_00ae5a50()
    {}
};

struct MemPool_00ae5a50
{
    void* Game_DoHeapAlloc(unsigned int);
};

struct Sub18_00ae5a50
{
    char* name;
    char nameBuf[260];
    char* source;
    char sourceBuf[260];
    float f210;
    float f214;
    NiPoint3 position;
    int f224;
    float f228;
    float f22c;
    int f230;
    int f234;
    int f238;
    inline void FUN_00ae8770()
    {
        nameBuf[0] = 0;
        sourceBuf[0] = 0;
        name = nameBuf;
        source = sourceBuf;
        f210 = 0.0f;
        f214 = 0.0f;
        position = DAT_011f426c;
        f224 = 0;
        f228 = 0.0f;
        f22c = 0.0f;
        f230 = 0;
        f234 = 0;
        f238 = 0;
    }
};

struct Msg_00ae5a50
{
    int f0;
    int unk04;
    int unk08;
    int fC;
    int f10;
    char f14;

    Sub18_00ae5a50 sub18;
    inline void SetC(int v)
    {
        fC = v;
    }
    inline void Set10(int v)
    {
        f10 = v;
    }
    inline void Set14(char v)
    {
        f14 = v;
    }
    inline Msg_00ae5a50(int id)
    {
        sub18.FUN_00ae8770();
        f0 = id;
        SetC(0);
        Set10(0);
        Set14(0);
    }
    static inline void* operator new(unsigned int n)
    {
        return ((MemPool_00ae5a50*)&DAT_011f6238)->Game_DoHeapAlloc(n);
    }
};

struct PtrArg_00ae5a50
{
    NiRefObject* m_p;
    inline PtrArg_00ae5a50(NiRefObject* p) : m_p(p)
    {
        if (m_p)
        {
            NiRefObject* ref = m_p;
            InterlockedIncrement((long*)&ref->m_uiRefCount);
        }
    }
    inline PtrArg_00ae5a50(const PtrArg_00ae5a50& rhs) : m_p(rhs.m_p)
    {
        if (m_p)
        {
            NiRefObject* ref = m_p;
            InterlockedIncrement((long*)&ref->m_uiRefCount);
        }
    }
    inline ~PtrArg_00ae5a50()
    {
        if (m_p)
            InterlockedDecrement((long*)&m_p->m_uiRefCount);
    }
};

struct Sound10_00ae5a50
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
    virtual int v11();
};

struct Sound_00ae5a50
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int);
    int m_04;
    int m_08;
    unsigned int m_0c;
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
    unsigned int m_160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    unsigned int m_174;
    unsigned int m_178;
    inline void SetFreq(unsigned int v)
    {
        m_160 = v;
    }
    inline void SetMeta(unsigned int v)
    {
        m_0c = v;
    }
    inline int ID()
    {
        return m_04;
    }
    inline void SetPair(unsigned int a, unsigned int b)
    {
        m_174 = a;
        m_178 = b;
    }
};

// BSAudio.h declares these virtual slots as void-returning, without the creation argument.
struct AudioBig_00ae5a50
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* v04();
    virtual Sound_00ae5a50* v05(char*);
    inline bool IsMT()
    {
        return bMultiThread;
    }
    inline void* Get10()
    {
        return m_10;
    }
    inline void* GetCallback()
    {
        return m_2c;
    }
    bool bMultiThread;
    int unk08;
    int unk0c;
    void* m_10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void* m_2c;
};

inline AudioBig_00ae5a50* AudioInstance_00ae5a50()
{
    return (AudioBig_00ae5a50*)DAT_011f6d98;
}
inline bool AudioMT_00ae5a50()
{
    AudioBig_00ae5a50* pa = (AudioBig_00ae5a50*)DAT_011f6d98;
    return pa->bMultiThread;
}
inline void* Audio10_00ae5a50()
{
    AudioBig_00ae5a50* pa = (AudioBig_00ae5a50*)DAT_011f6d98;
    return pa->m_10;
}
inline void* AudioCB_00ae5a50()
{
    AudioBig_00ae5a50* pa = (AudioBig_00ae5a50*)DAT_011f6d98;
    return pa->m_2c;
}

struct AudioMapNode_00ae5a50
{
    AudioMapNode_00ae5a50* next;
    int key;
    Msg_00ae5a50* value;
};
struct MsgStack_00ae5a50
{
    virtual void Destroy();
    virtual unsigned int Hash(int key);
    virtual bool Equal(int key, int other);
    virtual void SetValue(AudioMapNode_00ae5a50*, int, Msg_00ae5a50*);
    virtual void ClearValue(AudioMapNode_00ae5a50*);
    virtual AudioMapNode_00ae5a50* NewNode();
    unsigned int hashSize;
    AudioMapNode_00ae5a50** buckets;
    unsigned int count;
    inline void InsertOrUpdate(int key, Msg_00ae5a50* value)
    {
        unsigned int hash = Hash(key);
        AudioMapNode_00ae5a50* node = buckets[hash];
        unsigned int scanned = 0;
        for (; node; node = node->next)
        {
            ++scanned;
            if (Equal(key, node->key))
            {
                node->value = value;
                return;
            }
        }
        node = NewNode();
        SetValue(node, key, value);
        node->next = buckets[hash];
        buckets[hash] = node;
        ++count;
    }
};

struct Mgr_00ae5a50
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
    MsgStack_00ae5a50 stack;
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
    CritSecA m_cs;
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
    int m_180;

    R_00ae5a50 BSAudioManager_InitSoundPath(char* apName, int aiFlags, void* ap5);
    void BSAudioManager_ComposeMessage(int, int, int, void*, PtrArg_00ae5a50, NiPoint3);
};

typedef int(__cdecl* PFn1_00ae5a50)(R_00ae5a50*, void*, int*);
typedef bool(__cdecl* PFn2_00ae5a50)(void*, int*, int*);

// @fnv 0x00ae5a50
// src: COMMUNITY 0x00ae5a50
R_00ae5a50 Mgr_00ae5a50::BSAudioManager_InitSoundPath(char* apName, int aiFlags, void* ap5)
{
    if (!AudioInstance_00ae5a50()->IsMT())
    {
        return R_00ae5a50(-1);
    }
    int iID4 = this->m_180++;
    if (!*apName)
    {
        FUN_005b5e40_v("Trying to create a sound with no filename\n");
        return R_00ae5a50(-1);
    }
    if (!(aiFlags & 1) && !(aiFlags & 2))
    {
        FUN_005b5e40_v("Audio: Attempting to init %s without defining it as a 2D or 3D sound.", apName);
        aiFlags |= 1;
    }
    Sound_00ae5a50* local1417 = (*(AudioBig_00ae5a50* volatile*)&DAT_011f6d98)->v05(apName);
    local1417->m_08 = aiFlags;
    local1417->m_04 = iID4;
    local1417->SetFreq((unsigned int)(GetVolume_00ae5a50() * 1000.0));
    if (AudioInstance_00ae5a50()->Get10())
    {
        local1417->v06(((Sound10_00ae5a50*)AudioInstance_00ae5a50()->Get10())->v11());
    }
    R_00ae5a50 result300(iID4);
    EnterCriticalSection(&this->m_cs);
    Msg_00ae5a50* local12 = 0;
    local12 = new Msg_00ae5a50(iID4);
    this->stack.InsertOrUpdate(iID4, local12);
    LeaveCriticalSection(&this->m_cs);
    int iResult3 = 0;
    int iOut5 = 0;
    void* local141 = AudioInstance_00ae5a50()->GetCallback();
    if (ap5 && local141)
    {
        iResult3 = ((PFn1_00ae5a50)local141)(&result300, ap5, &iOut5);
    }
    local1417->SetMeta(iOut5);
    if (iResult3)
    {
        if (iResult3 & 0x8000000)
        {
            aiFlags &= ~2;
            aiFlags |= 1;
            aiFlags |= 0x8000000;
        }
        if ((iResult3 & 0x10) || (iResult3 & 0x2000000) || (iResult3 & 0x4000000))
        {
            aiFlags &= ~0x6000010;
            aiFlags |= iResult3 & 0x6000010;
        }
        local1417->m_08 = aiFlags;
    }
    BSAudioManager_ComposeMessage(0x25, local1417->ID(), 0, local1417, PtrArg_00ae5a50((NiRefObject*)0), DAT_011f426c);
    if (ap5 && local141)
    {
        iResult3 = ((PFn1_00ae5a50)local141)(&result300, ap5, 0);
    }
    void* local14 = (*(AudioBig_00ae5a50* volatile*)&DAT_011f6d98)->v04();
    int iA2 = 0;
    int local13 = 0;
    if (local14)
    {
        if (((PFn2_00ae5a50)local14)(ap5, &iA2, &local13))
        {
            local1417->SetPair(iA2, local13);
        }
    }
    return result300;
}
}  // namespace fnv_00ae5a50

namespace fnv_00ae7550 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);


struct Pool_ae7550
{
    void MemoryManager_Deallocate(void* p);
};
extern Pool_ae7550 DAT_011f6238;
struct FUN_00ae86d0
{
    ~FUN_00ae86d0()
    {
        if (m_pReferencedObject)
            NiObjectGarbage_Add(m_pReferencedObject);
    }
    static void operator delete(void* p)
    {
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    FUN_00ae86d0* GetNext() const
    {
        return m_pNext;
    }
    int unk00;
    int unk04;
    int unk08;
    FUN_00ae86d0* m_pNext;
    NiPointer<NiAVObject> m_pReferencedObject;
    float unk14;
    float unk18;
    float unk1C;
};
struct List_ae7550
{
    unsigned int m_uiCount;
    int unk04;
    FUN_00ae86d0* m_pHead;
    void SoundMessageStack_Clear();
};
// @fnv 0x00ae7550
// src: COMMUNITY 0x00ae7550
void List_ae7550::SoundMessageStack_Clear()
{
    FUN_00ae86d0* pkNode = 0;
    while (m_pHead)
    {
        pkNode = m_pHead;
        m_pHead = m_pHead->GetNext();
        m_uiCount--;
        pkNode->m_pNext = 0;
        delete pkNode;
    }
}
}  // namespace fnv_00ae7550

namespace fnv_00ae9150 {
extern char DAT_010a3308;
extern char DAT_010a33b0;

void __cdecl _NiFree_00aa10f0(int value);

struct S00ae9150_Pool
{
    void __thiscall MemoryManager_Deallocate(void* apMemory);
};
extern S00ae9150_Pool DAT_011f6238;

struct S00ae9150_Guard
{
    int unk00;
    inline S00ae9150_Guard()
    {}
    inline ~S00ae9150_Guard()
    {}
};

struct S00ae9150_Obj
{
    void* m_vptr;
    int unk04;
    int m_08;

    void __thiscall ClearAll();
    S00ae9150_Obj* FUN_00ae9150(unsigned int aFlags);
};

// @fnv 0x00ae9150
S00ae9150_Obj* S00ae9150_Obj::FUN_00ae9150(unsigned int aFlags)
{
    int u1;
    int u2;
    int u3;
    m_vptr = &DAT_010a3308;
    {
        S00ae9150_Guard guard;
        ClearAll();
    }
    m_vptr = &DAT_010a33b0;
    ClearAll();
    _NiFree_00aa10f0(m_08);
    if (aFlags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}
}  // namespace fnv_00ae9150

struct FUN_00adb8e0_cls
{
    bool BSAudioManager_SetFrequencyVariance(int a, bool b);
};
// @fnv 0x00adb8e0
// src: COMMUNITY 0x00adb8e0
bool FUN_00adb8e0_cls::BSAudioManager_SetFrequencyVariance(int a, bool b)
{
    ((DetectOwner*)this)->BSAudioManager_ComposeMessage(0x14, a, b, 0, DetectRefPtr(0), DAT_011f426c);
    return false;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

template <class T> struct S00adc260_NiPointerA
{
    T* m_pObject;
    ~S00adc260_NiPointerA()
    {}
    S00adc260_NiPointerA(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
};
struct S00adc260_SoundOwnerA
{
    void BSAudioManager_ComposeMessage(unsigned int flags, int a, int b, int c,
                      S00adc260_NiPointerA<NiRefObject> pSceneObject, NiPoint3 pos);
    void BSAudioManager_Seek(int a, int b);
};
// @fnv 0x00adc260
// src: COMMUNITY 0x00adc260
void S00adc260_SoundOwnerA::BSAudioManager_Seek(int a, int b)
{
    BSAudioManager_ComposeMessage(0x3f, a, b, 0, 0, DAT_011f426c);
}

struct FUN_00adeff0_cls
{
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
    void* unk8C;
    void* unk90;
    void* unk94;
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
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    unsigned char unk174;
    unsigned char m_bState;
    void BSAudioManager_SetListenerUnderwater(unsigned char bNew);
};

// @fnv 0x00adeff0
// src: COMMUNITY 0x00adeff0
void FUN_00adeff0_cls::BSAudioManager_SetListenerUnderwater(unsigned char bNew)
{
    if (bNew != m_bState)
    {
        m_bState = bNew;
        ((DetectOwner*)this)->BSAudioManager_ComposeMessage(0x37, 0, 0, 0, DetectRefPtr(0), DAT_011f426c);
    }
}

struct Param2Ada;

extern __declspec(thread) int g_tlsMemContext;
extern float DAT_01094c4c;
extern double DAT_010a3470;
extern float DAT_01012054;
extern Setting DAT_011f6e5c;
extern "C" void* _fnv_zlib_memset(void*, int, unsigned int);
int __cdecl FUN_00ec65a6(char*, unsigned int, const char*);

struct DebugInit
{
    void FUN_00ae8770();
    void FUN_00ae8830();
};
struct DebugInfo
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
    char* pSelf;
    char name[0x104];
    float f210, f214, f218, f21c, f220;
    int unk224, unk228, unk22c;
    int i230, i234, i238;
    void SetName(Param2Ada* sound);
    __forceinline DebugInfo()
    {
        ((DebugInit*)this)->FUN_00ae8770();
    }
    __forceinline ~DebugInfo()
    {
        ((DebugInit*)this)->FUN_00ae8830();
    }
};
struct InfoHead
{
    int d0;
    float d4, d8;
    int d12, d16;
    bool d20;
};
struct SoundDtor
{
    void FUN_00ae8af0();
};
struct DebugPlain
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
    char* pSelf;
    char name[0x104];
    float f210, f214, f218, f21c, f220;
    int unk224, unk228, unk22c;
    int i230, i234, i238;
    void FUN_00ae8770();
};

struct SoundInfoWrap
{
    FUN_00ae89f0 head;
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
    __forceinline ~SoundInfoWrap()
    {
        ((SoundDtor*)this)->FUN_00ae8af0();
    }
};
struct TempInfo
{
    int b0;
    float b4, b8;
    int b12, b16;
    bool b20;
    DebugPlain debug;
    __forceinline TempInfo(bool debug3, float debug4, int debugB, int debugRoll4, int debug_2)
    {
        debug.FUN_00ae8770();
        b0 = debugB;
        b4 = 1.0f;
        b8 = debug4;
        b12 = debugRoll4;
        b16 = debug_2;
        b20 = debug3;
    }
    __forceinline ~TempInfo()
    {
        ((SoundDtor*)this)->FUN_00ae8af0();
    }
};
struct SoundInfoOps
{
    void AssignFrom(TempInfo*);
};
struct Sub18Ada
{
    void FUN_00ae88c0(DebugInfo* arg);
};
struct EntryInfo : InfoHead
{
    Sub18Ada sub;
    __forceinline void SetDebug(DebugInfo src)
    {
        sub.FUN_00ae88c0(&src);
    }
    __forceinline void Assign(SoundInfoWrap* info)
    {
        d0 = info->head.m_uiSoundID;
        d4 = info->head.m_fSoundVolume;
        d8 = *(float*)&info->head._08;
        d12 = info->head.m_uiValueAt0C;
        d16 = info->head.m_uiPlaybackFlags;
        d20 = info->head.m_bValueAt14;
    }
};
struct Mgr74Ada
{
    bool FUN_00a1e380(int, EntryInfo**);
    void InsertOrUpdate(int, void*);
};
struct BSSoundInfoC
{
    InfoHead head;
    DebugPlain debug;
    BSSoundInfoC(SoundInfoWrap*);
};
struct AllocatorAda
{
    void* Game_DoHeapAlloc(unsigned int);
};
inline void* operator new(unsigned int n)
{
    return ((AllocatorAda*)&g_memoryManager)->Game_DoHeapAlloc(n);
}
inline void operator delete(void* p)
{
    g_memoryManager->Deallocate(p);
}
struct MemContext
{
    int saved;
    __forceinline MemContext()
    {
        int tlsTemp = g_tlsMemContext;
        saved = tlsTemp;
        g_tlsMemContext = 11;
    }
    __forceinline ~MemContext()
    {
        int restore = saved;
        g_tlsMemContext = restore;
    }
};
__forceinline void LockCS(CritSecA* p)
{
    int a, b;
    EnterCriticalSection(p);
}
__forceinline void UnlockCS(CritSecA* p)
{
    int a, b, c;
    LeaveCriticalSection(p);
}
struct Param2Ada
{
    virtual void s0();
    virtual bool v4();
    virtual void s2();
    virtual void s3();
    virtual float v10();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual float* v54(LocalVec3* arg);
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    unsigned short w18;
    unsigned short w1a;
    unsigned short w1c;
    unsigned short w1e;
    int unk20, unk24, unk28, unk2c, unk30;
    short unk34;
    char name[0x104];
    float f13c;
    float f140;
    int unk144, unk148, unk14c;
    float f150;
    __forceinline int Read14()
    {
        return f14;
    }
    __forceinline int Read08()
    {
        return f08;
    }
    __forceinline int Read04()
    {
        return f04;
    }
    __forceinline float Get150()
    {
        return f150;
    }
    __forceinline float Get140()
    {
        return f140;
    }
    __forceinline float Get13c()
    {
        return f13c;
    }
    __forceinline float Read150()
    {
        float t9a0 = f150;
        return (t9a0 > 3.4028234663852886e+37) ? DAT_01012054 : Get150();
    }
    __forceinline float Read140()
    {
        float t9a4 = f140;
        return (t9a4 > 3.4028234663852886e+37) ? DAT_01012054 : Get140();
    }
    __forceinline float Read13c()
    {
        float t9a8 = f13c;
        return (t9a8 > 3.4028234663852886e+37) ? DAT_01012054 : Get13c();
    }
    __forceinline unsigned short Read18()
    {
        return w18;
    }
    __forceinline unsigned short Read1c()
    {
        return w1c;
    }
    __forceinline unsigned short Read1e()
    {
        return w1e;
    }
    bool FUN_00ae9cf0();
    bool FUN_00ae9d10();
};

__forceinline void DebugInfo::SetName(Param2Ada* sound)
{
    if (sound->name)
    {
        char* dst = pSelf;
        FUN_00ec65a6(dst, 0x104, sound->name);
    }
    else
    {
        char* dst = pSelf;
        FUN_00ec65a6(dst, 0x104, "NotTESSound");
    }
}
__forceinline bool ReadDebugSetting()
{
    char* pSel = &DAT_011f6e5c ? (char*)&DAT_011f6e5c.uValue.i : (*(char*)& DAT_01202800 = 0, (char*)&DAT_01202800);
    return *(bool*)pSel;
}
struct ThisClsAda
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
    Mgr74Ada mgr;
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
    CritSecA cs;
    void BSAudioManager_SetVoiceState(int param1, Param2Ada* param2);
};
// @fnv 0x00ada5d0
// src: COMMUNITY 0x00ada5d0
void ThisClsAda::BSAudioManager_SetVoiceState(int param1, Param2Ada* param2)
{
    MemContext context4_2;
    SoundInfoWrap info15;
    DebugInfo descB_;
    DebugInfo debug4;
    void* pSavedB = 0;
    bool flag11_2 = ReadDebugSetting();
    if (param2)
    {
        ((SoundInfoOps*)&info15)
            ->AssignFrom(
                &TempInfo(param2->v4(), param2->v10(), param2->Read04(), param2->Read08(), param2->Read14()));
        if (flag11_2)
        {
            _fnv_zlib_memset(&descB_, 0, 0x23c);
            if (descB_.pSelf != descB_.name)
                descB_.pSelf = descB_.name;
            descB_.SetName(param2);
            if (param2->FUN_00ae9cf0() || param2->FUN_00ae9d10())
            {
                descB_.f220 = param2->Read150();
                descB_.f218 = param2->v54(&LocalVec3())[0];
                descB_.f21c = param2->v54(&LocalVec3())[1];
                descB_.f210 = param2->Read140();
                descB_.f214 = param2->Read13c();
            }
            else
            {
                descB_.f220 = 0.0f;
                descB_.f218 = 0.0f;
                descB_.f21c = 0.0f;
                descB_.f210 = 0.0f;
                descB_.f214 = 0.0f;
            }
            descB_.i230 = param2->Read18();
            descB_.i234 = param2->Read1c();
            descB_.i238 = param2->Read1e();
        }
    }
    LockCS(&cs);
    EntryInfo* pInfo = 0;
    if (mgr.FUN_00a1e380(param1, &pInfo))
    {
        if (flag11_2)
            pInfo->SetDebug(descB_);
        pInfo->Assign(&info15);
    }
    else
    {
        pSavedB = new BSSoundInfoC(&info15);
        if (flag11_2)
            ((EntryInfo*)pSavedB)->SetDebug(descB_);
        mgr.InsertOrUpdate(param1, pSavedB);
    }
    UnlockCS(&cs);
}

struct SoundOwnerA
{
    void BSAudioManager_ComposeMessage(unsigned int flags, int a, bool b, int c, NiAVObjPtr pSceneObject, NiPoint3 pos);
    void BSAudioManager_SetAtListener(int a, bool b);
};
// @fnv 0x00adc2e0
// src: XBOX_PDB 0x00adc2e0
void SoundOwnerA::BSAudioManager_SetAtListener(int a, bool b)
{
    BSAudioManager_ComposeMessage(0x40, a, b, 0, 0, DAT_011f426c);
}

inline void DeadN()
{
    int a[4];
}
struct SoundQ4
{
    virtual ~SoundQ4();
    int unk04;
    unsigned int uiFlags;
    int unk0C;
    unsigned int uiFlags2;
    char pad14[0x36 - 0x14];
    char cEnabled;
    char pad37[0x144 - 0x37];
    unsigned int uiID;
    int iAlt;
    unsigned int GetFlags() const
    {
        return uiFlags;
    }
    unsigned int GetID() const
    {
        return uiID;
    }
    int GetAlt() const
    {
        return iAlt;
    }
    void SetFlag1000(bool b)
    {
        uiFlags2 = b ? (uiFlags2 | 0x1000) : (uiFlags2 & ~0x1000);
    }
};
struct WrapQ4
{
    char pad[0x30];
    SoundQ4* SoundAssetTmp;
    SoundQ4* GetSoundByEditorID() const
    {
        return SoundAssetTmp;
    }
};
struct NodeQ4
{
    NodeQ4* pNext;
    int unk4;
    WrapQ4* pData;
};
inline void* operator new(unsigned int, PoolX& kMgr)
{
    return kMgr.Game_DoHeapAlloc(0x38);
}
inline void operator delete(void* p, PoolX& kMgr)
{
    ((MemoryManager*)&kMgr)->Deallocate(p);
}
typedef FUN_00ae6f50 TaskQ4;
struct TaskListQ4
{
    NodeQ4* pHead;
    void AddItem(TaskQ4* const&);
};

extern IOManager* DAT_01202d98;
inline bool AudioReadyQ4(const BSAudio* audio)
{
    return audio->bAudioEnabled;
}
inline BSAudio* GetAudioQ4()
{
    return (BSAudio*)DAT_011f6d98;
}
struct OwnerQ4 : ObjRegistry
{
    char padf4[0x10c - 0xf4];
    CritSecA m_kCS2;
    TaskListQ4 m_kTasks;
    void BSAudioManager_Precache_00add960(SoundQ4* SoundAssetTmp);
};
// @fnv 0x00add960
// src: COMMUNITY 0x00add960
void OwnerQ4::BSAudioManager_Precache_00add960(SoundQ4* SoundAssetTmp)
{
    if (AudioReadyQ4(GetAudioQ4()) && SoundAssetTmp->cEnabled && !(SoundAssetTmp->GetFlags() & 0x10000) &&
        !BSAudioManager_IsInCache(SoundAssetTmp->GetID(), false))
    {
        TaskQ4* pTask;
        EnterCriticalSection(&m_kCS2);
        bool bFound;
        NodeQ4* e = m_kTasks.pHead;
        bFound = false;
        while (e)
        {
            WrapQ4* pWrap = e->pData;
            if (pWrap->GetSoundByEditorID()->GetID() == SoundAssetTmp->GetID() && pWrap->GetSoundByEditorID()->GetAlt() == SoundAssetTmp->GetAlt())
            {
                bFound = true;
                break;
            }
            e = e ? e->pNext : 0;
        }
        if (bFound)
        {
            LeaveCriticalSection(&m_kCS2);
            delete SoundAssetTmp;
            return;
        }
        SoundAssetTmp->uiFlags = SoundAssetTmp->GetFlags() | 0x8000;
        DeadN();
        pTask = new (DAT_011f6238) TaskQ4((int)SoundAssetTmp);
        SoundAssetTmp->SetFlag1000(true);
        DAT_01202d98->AddTask((QIOTask*)pTask);
        m_kTasks.AddItem(pTask);
        LeaveCriticalSection(&m_kCS2);
    }
    else
    {
        delete SoundAssetTmp;
    }
}

inline void DeadM()
{
    int a[7];
}
extern "C" int __cdecl rand();
struct SoundQ
{
    virtual ~SoundQ();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(SoundQ*, int);
    unsigned int pad04;
    unsigned int flags;
    char pad0c[0x144 - 0xc];
    unsigned int id;
    int p148;
};
struct NodeQ
{
    NodeQ* next;
    int p4;
    SoundQ* sound;
};
struct SndFactQ
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual SoundQ* Create(int);
};
struct SoundListQ
{
    NodeQ* head;
    int p4;
    unsigned int count;
    NodeQ* GetHead() const
    {
        return head;
    }
    void NiTPointerListBase_RemovePos_0(NodeQ*& pNode);
    void _NiTListBase_AddHead(SoundQ* const& SoundAssetTmp);
};
struct OwnerQ2
{
    char pad[0x94];
    SoundListQ list;
    unsigned int total;
    char more[0x38];
    CritSecA cs;
    SoundQ* BSAudioManager_GetFromCache(unsigned int id, int alt, unsigned int flags);
};
inline SndFactQ* GetFQ()
{
    return (SndFactQ*)DAT_011f6d98;
}
inline SoundQ* NewSoundQ()
{
    return GetFQ()->Create(0);
}
inline unsigned int GetFlagsQ(SoundQ* s)
{
    return s->flags;
}
inline bool IsIDQ(SoundQ* s, unsigned int id)
{
    return id == s->id;
}
inline bool IsAltQ(SoundQ* s, int alt)
{
    return alt == s->p148 && s->p148 != 0;
}
// @fnv 0x00add1e0
// src: COMMUNITY 0x00add1e0
SoundQ* OwnerQ2::BSAudioManager_GetFromCache(unsigned int id, int alt, unsigned int flags)
{
    bool bRandom5 = false;
    if (alt && !id)
        bRandom5 = true;
    EnterCriticalSection(&cs);
    NodeQ* pNodeB = list.GetHead();
    DeadN();
    NodeQ* pPrev_ = 0;
    NodeQ* pSavedPrev = 0;
    SoundQ* pResult = 0;
    SoundQ* pMatch = 0;
    SoundQ* pSaved = 0;
    while (pNodeB)
    {
        SoundQ* SoundAssetTmp = pNodeB->sound;
        if (IsIDQ(SoundAssetTmp, id))
        {
            pResult = NewSoundQ();
            pResult->flags = flags;
            pResult->Copy(SoundAssetTmp, 1);
            pResult->flags = flags;
            list.NiTPointerListBase_RemovePos_0(pNodeB);
            if (!(GetFlagsQ(SoundAssetTmp) & 0x20000000))
                list._NiTListBase_AddHead(SoundAssetTmp);
            else
                delete SoundAssetTmp;
            LeaveCriticalSection(&cs);
            DeadM();
            return pResult;
        }
        else if (IsAltQ(SoundAssetTmp, alt))
        {
            if (pMatch && bRandom5 && rand() % 3 == 0)
            {
                pSaved = pMatch;
                pSavedPrev = pPrev_;
            }
            pMatch = SoundAssetTmp;
            pPrev_ = pNodeB;
        }
        pNodeB = pNodeB ? pNodeB->next : 0;
    }
    if (bRandom5 && pSaved && pMatch && rand() % 2 == 0)
    {
        pMatch = pSaved;
        pPrev_ = pSavedPrev;
    }
    if (pMatch)
    {
        list.NiTPointerListBase_RemovePos_0(pPrev_);
        list._NiTListBase_AddHead(pMatch);
        pResult = NewSoundQ();
        pResult->flags = flags;
        pResult->Copy(pMatch, 1);
        pResult->flags = flags;
    }
    LeaveCriticalSection(&cs);
    return pResult;
}

extern "C" void* __cdecl _alloca(unsigned int);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcat(char*, const char*);
extern "C" char* __cdecl strstr(const char*, const char*);
extern char str_010a36c0[];
extern char str_010a36b4[];
extern char str_010a36a8[];
extern char str_010a3694[];
extern char str_010a3684[];
extern char str_010a3670[];
extern char str_010a3660[];
extern char str_010a3650[];
extern char str_010a3638[];
extern char str_010a3624[];
extern char str_010a3608[];
extern char str_010a35f8[];
extern char str_010a35c0[];
extern char str_010a35a0[];
extern char str_010a3560[];
extern char str_010a353c[];
extern char str_010a3524[];
extern char str_010a352c[];
extern char str_010a3534[];
extern char str_01063958[];
extern char str_010639ec[];
extern char str_01013444[];
inline void* operator new[](unsigned int size) throw()
{
    return DAT_011f6238.Game_DoHeapAlloc(size);
}
struct SoundNode;
struct DebugList
{
    SoundNode* item;
    DebugList* next;
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
    DebugList()
    {
        item = 0;
        next = 0;
    }
    DebugList(SoundNode* const& value)
    {
        item = value;
        next = 0;
    }
    void FUN_00af25b0(SoundNode* const& value)
    {
        if (!value)
            return;
        DebugList* tail = this;
        while (tail->next)
            tail = tail->next;
        if (tail->item)
            tail->next = new DebugList(value);
        else
            tail->item = value;
    }
    static void operator delete(void* block)
    {
        ((MemoryManager*)&g_memoryManager)->Deallocate(block);
    }
    ~DebugList()
    {
        RemoveAll();
    }
    int Count()
    {
        int result = 0;
        DebugList* entry = this;
        while (entry)
        {
            if (entry->item)
                ++result;
            entry = entry->next;
        }
        return result;
    }
    void RemoveAll()
    {
        while (next)
        {
            DebugList* following = next->next;
            next->next = 0;
            delete next;
            next = following;
        }
        item = 0;
    }
    void SetItem(SoundNode* value)
    {
        if (!value)
            return;
        item = value;
    }
    void SortNodes(int(__cdecl* compare)(SoundNode*, SoundNode*))
    {
        DebugList* cursor = this;
        DebugList* prior = 0;
        if (cursor)
        {
            int left = Count();
            bool changed = true;
            while (left && changed)
            {
                changed = false;
                while (cursor)
                {
                    if (prior)
                    {
                        SoundNode* value = cursor->item;
                        SoundNode* previous = prior->item;
                        if (compare(previous, value) > 0)
                        {
                            cursor->SetItem(previous);
                            prior->SetItem(value);
                            changed = true;
                        }
                    }
                    prior = cursor;
                    cursor = cursor->next;
                }
                --left;
            }
        }
    }
    void SortItemsRecursive(SoundNode** items, int(__cdecl* compare)(SoundNode*, SoundNode*), int count)
    {
        int step = 0;
        int first = 0;
        int last = count - 1;
        for (step = 1; step <= (last - first) / 9; step = step * 3 + 1)
        {
        }
        for (; step > 0; step /= 3)
        {
            for (int index = first + step; index <= last; ++index)
            {
                int at = index;
                SoundNode* value = items[index];
                while (at >= first + step && compare(value, items[at - step]) < 0)
                {
                    items[at] = items[at - step];
                    at -= step;
                }
                items[at] = value;
            }
        }
    }
// src: GUESS 0x00ae81e0 (confidence: low)
    void ProcessEntries_00ae81e0(int(__cdecl* compare)(SoundNode*, SoundNode*))
    {
        SoundNode** items;
        DebugList* node;
        int index;
        DebugList* previous;
        int output;
        int count;
        count = Count();
        items = (SoundNode**)_alloca(count * 4 + 4);
        if (!items)
        {
            SortNodes(compare);
            return;
        }
        node = this;
        for (index = 0; index < count; ++index, node = node->next)
            items[index] = node->item;
        SortItemsRecursive(items, compare, count);
        RemoveAll();
        node = this;
        previous = 0;
        for (output = 0; output < count; ++output)
        {
            if (output > 0)
                node = new DebugList(items[output]);
            else
            {
                node->item = items[output];
                node->next = 0;
            }
            if (previous)
                previous->next = node;
            previous = node;
        }
    }
};
struct SoundNode
{
    static void* operator new(unsigned int size) throw()
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    SoundNode()
    {
        index = 0;
        description = 0;
    }
    SoundNode(unsigned int n, char* text)
    {
        index = n;
        description = text;
    }
    unsigned int index;
    char* description;
};
int __cdecl BSAudioManager_CompareUnsignedValues(unsigned int*, unsigned int*);
struct SoundDebugDescription
{
    char* message;
    char messageBuffer[260];
    char* fullName;
    char fullNameBuffer[260];
    float volume;
    float frequency;
    unsigned int unknown218;
    unsigned int unknown21c;
    float attenuation;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int currentTime;
    unsigned int maxTime;
    unsigned int duration;
    SoundDebugDescription()
    {
        messageBuffer[0] = 0;
        fullNameBuffer[0] = 0;
        message = messageBuffer;
        fullName = fullNameBuffer;
        volume = 0.0f;
        frequency = 0.0f;
        unknown218 = *(unsigned int*)&NiPoint3_ZERO.x;
        unknown21c = *(unsigned int*)&NiPoint3_ZERO.y;
        attenuation = NiPoint3_ZERO.z;
        unknown224 = 0;
        unknown228 = 0;
        unknown22c = 0;
        currentTime = 0;
        maxTime = 0;
        duration = 0;
    }
    ~SoundDebugDescription()
    {
        message = 0;
        fullName = 0;
        volume = 0.0f;
        frequency = 0.0f;
        unknown224 = 0;
        unknown228 = 0;
        unknown22c = 0;
        currentTime = 0;
        maxTime = 0;
        duration = 0;
    }
    SoundDebugDescription& __thiscall FUN_00ae88c0(const SoundDebugDescription& other)
    {
        messageBuffer[0] = 0;
        fullNameBuffer[0] = 0;
        if (other.message)
        {
            const char* source = other.message;
            char* dest = message;
            strcpy(dest, source);
        }
        if (other.fullName)
        {
            const char* source = other.fullName;
            char* dest = fullName;
            strcpy(dest, source);
        }
        volume = other.volume;
        frequency = other.frequency;
        unknown218 = other.unknown218;
        unknown21c = other.unknown21c;
        attenuation = other.attenuation;
        unknown224 = other.unknown224;
        unknown228 = other.unknown228;
        unknown22c = other.unknown22c;
        currentTime = other.currentTime;
        maxTime = other.maxTime;
        duration = other.duration;
        return *this;
    }
    char* GetName()
    {
        return fullName;
    }
};
struct SoundRecord
{
    unsigned int id;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int flags;
    unsigned int unknown10;
    bool isPlaying;
    unsigned int GetID()
    {
        unsigned int value = id;
        return value;
    }
    unsigned int GetFlags()
    {
        return flags;
    }
    bool IsPlaying()
    {
        return isPlaying;
    }
    SoundDebugDescription __thiscall GetPayload();
};
struct SoundMapItem
{
    SoundMapItem* next;
    unsigned int key;
    SoundRecord* value;
};
struct SoundEntries
{
    virtual void Destroy();
    virtual unsigned int Hash(unsigned int);
    unsigned int count;
    SoundMapItem** data;
    SoundMapItem* GetFirst()
    {
        for (unsigned int i = 0; i < count; ++i)
        {
            if (data[i] != 0)
                return data[i];
        }
        return 0;
    }
    void __thiscall FUN_00a0c850(SoundMapItem** position, unsigned int* key, SoundRecord** value)
    {
        SoundMapItem* entry = *position;
        *key = entry->key;
        *value = entry->value;
        if (entry->next)
        {
            *position = entry->next;
            return;
        }
        unsigned int index = Hash(entry->key);
        for (++index; index < count; ++index)
        {
            entry = data[index];
            if (entry)
            {
                *position = entry;
                return;
            }
        }
        *position = 0;
    }
};
struct AudioSystem
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    SoundEntries sounds;
    unsigned int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    unsigned int unkb0, unkb4, unkb8, unkbc, unkc0;
    CritSecA criticalSection;
    DebugList* __thiscall BSAudioManager_DebugPrintSounds(unsigned int);
};
// @fnv 0x00ae5ff0
// src: COMMUNITY 0x00ae5ff0
DebugList* AudioSystem::BSAudioManager_DebugPrintSounds(unsigned int filter)
{
    DebugList* head8 = new DebugList;
    unsigned int filterFlags_2 = ~0u;
    reinterpret_cast<FUN_00ada330_shell*>(this)->BSAudioManager_SynchVoiceStates();
    bool includeSpecial = false;
    char* buffer_ = 0;
    char _copy[260];
    char* last2;
    SoundRecord* currentSound6;
    char formatted[260];
    if (filter < 99)
    {
        buffer_ = new char[260];
        sprintf(buffer_, str_010a36c0, filter + 1);
        if (filter == 1)
        {
            strcat(buffer_, str_010a36b4);
            filterFlags_2 = 2;
        }
        else if (filter == 2)
        {
            strcat(buffer_, str_010a36a8);
            filterFlags_2 = 1;
        }
        else if (filter == 3)
        {
            strcat(buffer_, str_010a3694);
            filterFlags_2 = 0x08000000;
        }
        else if (filter == 4)
        {
            strcat(buffer_, str_010a3684);
            filterFlags_2 = 4;
        }
        else if (filter == 5)
        {
            strcat(buffer_, str_010a3670);
            filterFlags_2 = 8;
        }
        else if (filter == 6)
        {
            strcat(buffer_, str_010a3660);
            filterFlags_2 = 0x20;
        }
        else if (filter == 7)
        {
            strcat(buffer_, str_010a3650);
            filterFlags_2 = 0x1000;
        }
        else if (filter == 8)
        {
            strcat(buffer_, str_010a3638);
            filterFlags_2 = 0x40000000;
        }
        else if (filter == 9)
        {
            strcat(buffer_, str_010a3624);
            filterFlags_2 = 0x10000000;
        }
        else if (filter == 10)
        {
            strcat(buffer_, str_010a3608);
            includeSpecial = true;
        }
        head8->FUN_00af25b0(new SoundNode(0, buffer_));
        buffer_ = new char[260];
        sprintf(buffer_, str_010a35f8);
        head8->FUN_00af25b0(new SoundNode(1, buffer_));
    }
    else if (filter == 99)
    {
        filterFlags_2 = 0x800;
    }
    EnterCriticalSection(&criticalSection);
    SoundMapItem* current = sounds.GetFirst();
    SoundDebugDescription description;
    int entries4 = 1;
    unsigned int nextIndex4;
    unsigned int soundID2 = 0;
    int totalTime3 = 0;
    for (; current != 0 && entries4 < 20;)
    {
        sounds.FUN_00a0c850(&current, &nextIndex4, &currentSound6);
        buffer_ = new char[260];
        totalTime3 = 0;
        if (currentSound6 != 0)
        {
            description.FUN_00ae88c0(currentSound6->GetPayload());
            totalTime3 = (unsigned int)totalTime3 > description.currentTime ? totalTime3 : description.currentTime;
            totalTime3 = (unsigned int)totalTime3 > description.maxTime ? totalTime3 : description.maxTime;
            totalTime3 = (unsigned int)totalTime3 > description.duration ? totalTime3 : description.duration;
        }
        if (((includeSpecial && currentSound6 && (!currentSound6->IsPlaying() || totalTime3 > 3000)) ||
             (!includeSpecial && currentSound6 && currentSound6->IsPlaying() && totalTime3 <= 3000)) &&
            (filterFlags_2 & currentSound6->GetFlags()))
        {
            description.FUN_00ae88c0(currentSound6->GetPayload());
            soundID2 = currentSound6->GetID();
            if (nextIndex4 != soundID2)
                soundID2 = soundID2;
            if (description.fullName != 0)
            {
                if (description.fullName != description.fullNameBuffer)
                {
                    description.fullName = description.fullNameBuffer;
                }
                strcpy_s(_copy, 260, description.GetName());
                last2 = strstr(_copy, str_01013444);
                while (last2 && strstr(last2 + 1, str_01013444))
                {
                    last2++;
                    last2 = strstr(last2, str_01013444);
                }
                if (last2 && last2[1] != 0)
                {
                    strcpy_s(description.GetName(), 260, last2);
                }
                else
                {
                    delete[] buffer_;
                    continue;
                }
                if (currentSound6->GetFlags() & 2)
                {
                    sprintf(formatted, str_010a35c0, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : str_010639ec), (double)description.attenuation,
                            (double)description.volume, (double)description.frequency, description.currentTime,
                            description.maxTime, description.duration);
                }
                else if ((currentSound6->GetFlags() & 1) && !(currentSound6->GetFlags() & 0x8000000))
                {
                    sprintf(formatted, str_010a35a0, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : str_010639ec), description.currentTime,
                            description.maxTime);
                }
                else if ((currentSound6->GetFlags() & 1) && (currentSound6->GetFlags() & 0x8000000))
                {
                    sprintf(formatted, str_010a3560, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : str_010639ec), (double)description.attenuation,
                            (double)description.volume, (double)description.frequency, description.currentTime,
                            description.maxTime, description.duration);
                }
                else
                {
                    sprintf(formatted, str_010a353c, soundID2, description.fullName,
                            (currentSound6->IsPlaying() ? str_01063958 : str_010639ec), description.currentTime,
                            description.maxTime);
                }
                strcpy_s(buffer_, 260, formatted);
            }
            else
            {
                sprintf(formatted, str_010a3524, soundID2, currentSound6->IsPlaying() ? str_010a3534 : str_010a352c);
                strcat(buffer_, formatted);
            }
            head8->FUN_00af25b0(new SoundNode(soundID2 + 2, buffer_));
            ++entries4;
        }
    }
    LeaveCriticalSection(&criticalSection);
    head8->ProcessEntries_00ae81e0((int(__cdecl*)(SoundNode*, SoundNode*))BSAudioManager_CompareUnsignedValues);
    return head8;
}
