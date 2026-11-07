#include "../../include/AudioLoadTask.h"
#include "../../include/BSAudio.h"
#include "../../include/BSAudioManager.h"
#include "../../include/BSAudioManagerThread.h"
#include "../../include/BSThread.h"
#include "../../include/BSSemaphore_adf080.h"
#include "../../include/GO.h"
#include "../../include/MemoryManager.h"
#include "../../include/Setting.h"

// src/bsaudio/bsaudiomanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiomanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl FUN_00ec7d40(int);

// @fnv 0x0072fa80
// src: XBOX_PDB 0x0072fa80
int __cdecl abs_0072fa80(int param_1)
{
    return FUN_00ec7d40(param_1);
}

struct FUN_00ad8d60_shell
{
    int m_uiSoundResourceID;
    int pad;
    int eState;
    bool __thiscall BSSoundHandle_FadeInPlay(int param2);
};

// @fnv 0x00ad8d60
// src: COMMUNITY 0x00ad8d60
bool FUN_00ad8d60_shell::BSSoundHandle_FadeInPlay(int aiParam)
{
    if (m_uiSoundResourceID == 0xffffffff)
    {
        return false;
    }
    eState = 1;
    BSAudioManager::GetRandomGenerator().BSAudioManager_FadeInPlay(m_uiSoundResourceID, aiParam);
    return true;
}

// Stores param at offset 0xa4 and fval at offset 0xa8 of this object.
// @fnv 0x00ada300
// src: COMMUNITY 0x00ada300
void BSAudioManager::SetConditions_00ada300(float fval, unsigned int param)
{
    iWeatherFlags = param;
    fCurrentGamehour = fval;
}

namespace fnv_00adad60 {
struct BottomlessStack
{
    void AudioMessageStack_Pop_00ae76b0();
};
}

// @fnv 0x00adad60
// src: XBOX_PDB 0x00adad60
void BSAudioManager::AudioMessageStack_Pop()
{
    reinterpret_cast<fnv_00adad60::BottomlessStack*>(FreeMessages)->AudioMessageStack_Pop_00ae76b0();
}

namespace fnv_00adaf80 {

struct BottomlessStack
{
    SoundMessageRecord* Pop();
};

}  // namespace fnv_00adaf80

// @fnv 0x00adaf80
// src: COMMUNITY 0x00adaf80
SoundMessageRecord* BSAudioManager::GetFreeQueueMessage()
{
    return reinterpret_cast<fnv_00adaf80::BottomlessStack*>(FreeQueueMessages)->Pop();
}

// Remaining manager method views cover declarations absent from BSAudioManager.h.
struct FUN_00adb960_shell
{
    bool __thiscall BSAudioManager_SetBalance(int arg1, int arg2);
};

// @fnv 0x00adb960
// src: COMMUNITY 0x00adb960
bool __thiscall FUN_00adb960_shell::BSAudioManager_SetBalance(int arg1, int arg2)
{
    return false;
}

struct FUN_00adbf40_shell
{
    bool BSAudioManager_SetOrientation(float f1, float f2, float f3, float f4);
};

// @fnv 0x00adbf40
// src: COMMUNITY 0x00adbf40
bool FUN_00adbf40_shell::BSAudioManager_SetOrientation(float f1, float f2, float f3, float f4)
{
    return false;
}

// @fnv 0x00ae7480
bool __thiscall AudioLoadTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return QueuedFileEntry::GetDescription(apDescription, aiBufferSize, const_cast<char*>("audio load task"));
}

struct FUN_00adcaa0_shell
{
    void BSAudioManager_UnMuteAllOfType(int param_2, int param_3);
};

// Forwards the two arguments to BSAudioManager's FUN_00adcaa0.
// @fnv 0x00ad84b0
void BSAudio::ForwardToManager(unsigned int param_2, unsigned int param_3)
{
    ((FUN_00adcaa0_shell*)&BSAudioManager::GetRandomGenerator())->BSAudioManager_UnMuteAllOfType(param_2, param_3);
}

struct FUN_00adcc10_shell
{
    void __thiscall BSAudioManager_UnPauseAllOfType(int, int);
};
// Forwards param1 and param2 to the BSAudioManager method FUN_00adcc10.
// @fnv 0x00ad8540
void __thiscall BSAudio::ForwardToManager(unsigned int param1, bool param2)
{
    ((FUN_00adcc10_shell*)&BSAudioManager::GetRandomGenerator())->BSAudioManager_UnPauseAllOfType(param1, param2);
}

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
// Initializes the object: sets f0 to -1, f4 and f8 to 0, and returns the object pointer.
// @fnv 0x00ae5f70
S_00ae5f70* __thiscall C_00ae5f70::Init(S_00ae5f70* pObject, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int i = 0;
    pObject->f0 = -1;
    pObject->f4 = 0;
    pObject->f8 = 0;
    i |= 1;
    return pObject;
}

// Compares the unsigned ints pointed to by a and b, returning -1 if the first is smaller, 1 if larger, else 0.
// @fnv 0x00ae5fb0
// src: GUESS 0x00ae5fb0 (confidence: high)
int __cdecl BSAudioManager_CompareUnsignedValues(unsigned int* puiLeft, unsigned int* puiRight)
{
    unsigned int v1 = *puiLeft;
    unsigned int v2 = *puiRight;
    return v1 < v2 ? -1 : v1 > v2;
}

extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;
struct FUN_00ae6c60_shell
{
    int __thiscall _BSAudioManager_AudioCacheSize();
};
// @fnv 0x00ae6c60
// src: COMMUNITY 0x00ae6c60
int __thiscall FUN_00ae6c60_shell::_BSAudioManager_AudioCacheSize()
{
    int* p = &g_011f6ec8 ? &DAT_011f6ecc : (DAT_01202800 = 0, &DAT_01202800);
    return *p;
}

namespace fnv_00ae6ca0 {
extern int DAT_011f6ec0;
extern char DAT_01202800;
extern int g_011f6ebc;
struct BSAudioManager_shell : BSAudioManager
{
    void __thiscall AddSound(int arg2);
    void __thiscall BSAudioManager_SetCacheEnabled(bool enable);
};
// Stores enable into a global flag and, when disabling, calls AddSound(0).
// @fnv 0x00ae6ca0
// src: COMMUNITY 0x00ae6ca0
void __thiscall BSAudioManager_shell::BSAudioManager_SetCacheEnabled(bool enable)
{
    char* target = &g_011f6ebc ? (char*)&DAT_011f6ec0 : ((void)(DAT_01202800 = 0), (char*)&DAT_01202800);
    *target = enable;
    if (!enable)
        AddSound(0);
}
}  // namespace fnv_00ae6ca0

namespace fnv_00ae6cf0 {
extern int g_011f6ebc;
extern bool DAT_011f6ec0;
extern bool DAT_01202800;
struct FUN_00ae6cf0_shell
{
    bool __thiscall BSAudioManager_IsEnableAudioCache();
};
// @fnv 0x00ae6cf0
// src: COMMUNITY 0x00ae6cf0
bool __thiscall FUN_00ae6cf0_shell::BSAudioManager_IsEnableAudioCache()
{
    bool* mode = &g_011f6ebc ? &DAT_011f6ec0 : (DAT_01202800 = 0, &DAT_01202800);
    return *mode;
}
}  // namespace fnv_00ae6cf0

extern int DAT_010a3718;

// Sets the vtable pointer to DAT_010a3718, touches the field at offset 0x30, then calls the base destructor.
// @fnv 0x00ae7020
// src: GUESS 0x00ae7020 (confidence: medium)
void __thiscall AudioLoadTask::DestroyFields_00ae7020()
{
    *reinterpret_cast<void**>(this) = &DAT_010a3718;
    SoundAssetTmp = SoundAssetTmp;
    QueuedFileEntry::~QueuedFileEntry();
}

struct SoundMessageRecord;
struct BottomlessStack
{
    void Push(SoundMessageRecord*);
    SoundMessageRecord* Pop();
    void SetBottomless(bool);
    void* __vecDelDtor(unsigned int);
    unsigned int iCount;
    bool m_bBottomless;
    char _pad_5[3];
    SoundMessageRecord* pTop;
    unsigned int m_uiStackLimit;
};
typedef char _sizecheck_AudioMessageStack[sizeof(BottomlessStack) == 16 ? 1 : -1];
struct FUN_00ae7510_shell : public BottomlessStack
{
    void FUN_00ae7510();
};

struct FUN_00ae7510 : public BottomlessStack
{
    FUN_00ae7510();
};
// Initializes the stack: clears the count, top pointer, bottomless flag and the extra field.
// @fnv 0x00ae7510
FUN_00ae7510::FUN_00ae7510()
{
    iCount = 0;
    pTop = 0;
    m_bBottomless = false;
    m_uiStackLimit = 0;
}

extern MemoryManager* g_memoryManager;
struct FUN_00ad93f0_shell
{
    void __thiscall FUN_00ad93f0(void);
};
struct FUN_00ae77a0_shell
{
    void* FUN_00ae77a0(unsigned int flags);
};
// Calls FUN_00ad93f0 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ae77a0
void* FUN_00ae77a0_shell::FUN_00ae77a0(unsigned int flags)
{
    ((FUN_00ad93f0_shell*)this)->FUN_00ad93f0();
    if (flags & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

namespace fnv_00ae7870 {
struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM* g_memoryManager;

struct FUN_00ae7870_shell
{
    void __thiscall CloseAudioManagerHandles();
    void* __thiscall FUN_00ae7870(unsigned int flags);
};

// @fnv 0x00ae7870
void* FUN_00ae7870_shell::FUN_00ae7870(unsigned int flags)
{
    CloseAudioManagerHandles();
    if (flags & 1)
        ((P03MM*)&g_memoryManager)->DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00ae7870

// Calls FUN_00ae7020, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ae7b10
void* __thiscall AudioLoadTask::FUN_00ae7b10(unsigned int flags)
{
    DestroyFields_00ae7020();
    if (flags & 1)
        reinterpret_cast<MemoryManager*>(&g_memoryManager)->Deallocate(this);
    return this;
}

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
// Clears the pointer at offset 8 of p, then deallocates p through the allocator.
// @fnv 0x00ae8ef0
// src: GUESS 0x00ae8ef0 (confidence: medium)
void __thiscall Host00ae8ef0::ClearAndFreeEntry(void* p)
{
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    ((GO*)((char*)p + 8))->operator=(0);
    alloc.Deallocate(p);
}

namespace fnv_00ae8f20 {
void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern int DAT_010a3370;
struct S00a0d390
{
    int _0;
    int _4;
    void* _8;
    void __thiscall ClearAll();
    void* __thiscall FUN_00ae8f20(int);
};
// @fnv 0x00ae8f20
void* __thiscall S00a0d390::FUN_00ae8f20(int aiFlags)
{
    int _u1;
    int _u2;
    *(void**)this = (void*)&DAT_010a3370;
    ClearAll();
    _NiFreeAlias(_8);
    if (aiFlags & 1)
    {
        g_memoryManager.Deallocate(this);
    }
    (void)_u1;
    (void)_u2;
    return this;
}
}  // namespace fnv_00ae8f20

namespace fnv_00ae9010 {
extern int DAT_010a3390;
void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
struct S00a0d390
{
    void __thiscall ClearAll();
};
struct FUN_00ae9010Owner
{
    void* f0;
    int f4;
    void* f8;
    void* __thiscall DestroyOwner(int);
};
// @fnv 0x00ae9010
void* __thiscall FUN_00ae9010Owner::DestroyOwner(int aiFlags)
{
    int x;
    int y;
    *(void**)this = (void*)&DAT_010a3390;
    ((S00a0d390*)this)->ClearAll();
    _NiFreeAlias(f8);
    if (aiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00ae9010

namespace fnv_00ae9100 {
void _NiFreeAlias(void*);
struct S00a0d390
{
    void* _00;
    int _04;
    void* _08;
    void __thiscall ClearAll();
    void* __thiscall FUN_00ae9100(unsigned int);
};
extern int DAT_010a33b0;
extern MemoryManager g_memoryManager;
// Sets the vtable, calls ClearAll, frees _08 via _NiFreeAlias, and deallocates this when flag bit 0 is set.
// @fnv 0x00ae9100
void* __thiscall S00a0d390::FUN_00ae9100(unsigned int auiFlags)
{
    int d1;
    int d2;
    *(void**)this = (void*)&DAT_010a33b0;
    ClearAll();
    _NiFreeAlias(_08);
    if (auiFlags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00ae9100

struct Helper
{
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(void*);
};
// Calls a helper on the BSAudioManager singleton with this task, then assigns the task's pointer field to itself.
// @fnv 0x00ae7360
// src: XBOX_PDB 0x00ae7360
void AudioLoadTask::Finish_00ae7360()
{
    ((Helper*)&BSAudioManager::GetRandomGenerator())->NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(this);
    SoundAssetTmp = SoundAssetTmp;
}

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
// @fnv 0x00ae89f0
FUN_00ae89f0::FUN_00ae89f0()
{
    m_uiSoundID = 0;
    m_fSoundVolume = 0.0f;
    m_uiValueAt0C = 0;
    m_uiPlaybackFlags = 0;
    m_bValueAt14 = 0;
}

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

// Copies the six setting values into the fVal array at this+0x140 and sets all six fMult entries to 1.0.
// @fnv 0x00ad9da0
void FUN_00ad9da0_t::InitAudioVolumes()
{
    float* r0 = &g_011f6e14 ? &g_011f6e14.uValue.f : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[0] = *r0;
    {
        float* r1 = &g_011f6e20 ? &g_011f6e20.uValue.f : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
        ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[1] = *r1;
        {
            float* r2 = &g_011f6e2c ? &g_011f6e2c.uValue.f : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
            ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[2] = *r2;
            {
                float* r3 = &g_011f6e38 ? &g_011f6e38.uValue.f : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[3] = *r3;
                {
                    float* r4 =
                        &g_011f6e44 ? &g_011f6e44.uValue.f : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[4] = *r4;
                    {
                        float* r5 =
                            &g_011f6e50 ? &g_011f6e50.uValue.f : (*(float*)& DAT_01202800 = 0.0f, (float*)&DAT_01202800);
                        ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fVal[5] = *r5;
                    }
                }
            }
        }
    }
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[0] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[1] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[2] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[3] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[4] = 1.0f;
    ((AudioVolumes_00ad9da0*)((char*)this + 0x140))->fMult[5] = 1.0f;
}

// @fnv 0x00ae6d30
bool BSAudioManager::HasMatchingEntry(unsigned int mask)
{
    unsigned int i = 0;
    for (; i < *(unsigned int*)((char*)this + 0x17c); ++i)
    {
        if (*(unsigned short*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8 + 4) == 1 &&
            (mask & *(unsigned int*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8)) ==
                *(unsigned int*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8))
            return true;
        else if (*(unsigned short*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8 + 4) == 2 &&
                 (mask & *(unsigned int*)((char*)*(unsigned int*)((char*)this + 0x178) + i * 8)))
            return true;
    }
    return false;
}

// @fnv 0x00ae6e60
// src: COMMUNITY 0x00ae6e60
bool __thiscall BSAudioManager::ClearPausedType(int param_2, unsigned char abMatchStateOne)
{
    int i = 0;
    for (; i < *(unsigned int*)((char*)this + 0x17c); ++i)
    {
        if (param_2 == *(int*)((char*)*(int*)((char*)this + 0x178) + i * 8) &&
            ((!abMatchStateOne && *(unsigned short*)((char*)*(int*)((char*)this + 0x178) + i * 8 + 4) == 2) ||
             (abMatchStateOne && *(unsigned short*)((char*)*(int*)((char*)this + 0x178) + i * 8 + 4) == 1)))
        {
            *(unsigned short*)((char*)*(int*)((char*)this + 0x178) + i * 8 + 4) = 0;
            *(int*)((char*)*(int*)((char*)this + 0x178) + i * 8) = 0;
            return true;
        }
    }
    return false;
}

struct SoundEmitter;
struct BSGameSound;
struct SoundMessageRecord;
struct NiAVObject;
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

// @fnv 0x00ada1d0
void FUN_00ada1d0_shell::InitUISounds(bool abPlayGameWorldSounds)
{
    if (!m_bUISoundsEnabled)
    {
        DAT_011f6d98->Precache($SG6265, 0);
        DAT_011f6d98->Precache(const_cast<char*>("UIMenuFocus"), 0x20000);
        DAT_011f6d98->Precache(const_cast<char*>("UIMenuCancel"), 0x20001);
        DAT_011f6d98->Precache(const_cast<char*>("UIMenuTab"), 0x20000);
        DAT_011f6d98->Precache(const_cast<char*>("UIMenuOK"), 0x20001);
        DAT_011f6d98->Precache(const_cast<char*>("UIMenuPrevNext"), 1);
        DAT_011f6d98->Precache(const_cast<char*>("WPNRifleAssaultFire3D"), 0x102);
        DAT_011f6d98->Precache(const_cast<char*>("FXBulletImpactConc"), 0x102);
        DAT_011f6d98->Precache(const_cast<char*>("UILoadScreenMicroFiche01"), 0x101);
        DAT_011f6d98->Precache(const_cast<char*>("UILoadScreenInitial"), 0x101);
        m_bUISoundsEnabled = true;
    }

    reinterpret_cast<FUN_00ada330_shell*>(this)->BSAudioManager_SynchVoiceStates();

    BSAudio* pAudio = DAT_011f6d98;
    volatile bool bAudioMultiThreaded = pAudio->bMultiThread;
    if (!bAudioMultiThreaded)
    {
        reinterpret_cast<FUN_00addc00_shell&>(BSAudioManager::GetRandomGenerator()).BSAudioManager_Process();
    }
}

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

// Looks up uiKey in the map and returns true if an item is found whose key equals uiKey.
// @fnv 0x00adc7d0
bool BADC7D0Cache::ContainsKey(unsigned int uiKey)
{
    bool bFound4 = false;
    BADC7D0Item* pkItem9 = 0;
    m_kUnsortedGeometryList.GetAt(uiKey, pkItem9);
    if (pkItem9)
    {
        void* pvX;
        void* pvUnusedB;
        unsigned int uiItemKey = pkItem9->m_uiKey;
        if (uiItemKey == uiKey)
            bFound4 = true;
    }
    if (!bFound4)
        bFound4 = bFound4;
    return bFound4;
}

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

// @fnv 0x00add480
// src: COMMUNITY 0x00add480
bool ObjRegistry::BSAudioManager_IsInCache(int m_uiSoundID, bool bCheckAlt)
{
    if (m_uiSoundID == 0)
        return false;
    EnterCriticalSection(&m_kCS);
    bool bFound = false;
    ObjNode* pNode = m_pHead;
    while (pNode)
    {
        ObjEntry* pEntry = pNode->m_pEntryObject;
        if (pEntry)
        {
            if ((bool)(int)(m_uiSoundID == pEntry->m_144) ||
                (bCheckAlt && (int)(unsigned char)(m_uiSoundID == pEntry->m_148 && pEntry->m_148 ? 1 : 0)))
            {
                bFound = true;
                break;
            }
        }
        pNode = pNode ? pNode->m_pNext : 0;
    }
    LeaveCriticalSection(&m_kCS);
    return bFound;
}

extern "C" void __cdecl Warning_005b5e40(const char* msg, int value);

extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;

struct AudioCacheOwner
{
    void BSAudioManager_SetCacheEnabled(int flags);
    void SetAudioCacheSize(int size);
};

// Sets the audio cache size when it is below 0x1000, otherwise logs an error; a size of 0 also calls FUN_00ae6ca0(0).
// @fnv 0x00ae6bf0
void AudioCacheOwner::SetAudioCacheSize(int size)
{
    if (size == 0)
    {
        BSAudioManager_SetCacheEnabled(0);
    }
    if ((unsigned int)size < 0x1000)
    {
        int* piCacheSize = (&g_011f6ec8 != 0) ? &DAT_011f6ecc : (DAT_01202800 = 0, &DAT_01202800);
        *piCacheSize = size;
    }
    else
    {
        Warning_005b5e40("AUDIO: Attempted to set audio cache size to %i. Cache size must be < 4MB", size);
    }
}

struct AE6DE0Slot
{
    void* m_pResource;
    unsigned short m_usState;
    unsigned short unk06;
};

// Finds the first slot with state 0, sets its state to 1 or 2 depending on bPrimary, stores pvData in it, and returns true; returns false if no free slot exists.
// @fnv 0x00ae6de0
bool BSAudioManager::AddSlot(void* pData, bool bPrimary)
{
    for (unsigned int i = 0; i < iPauseListSize; i++)
    {
        if (reinterpret_cast<AE6DE0Slot*>(pPauseEntries)[i].m_usState == 0)
        {
            reinterpret_cast<AE6DE0Slot*>(pPauseEntries)[i].m_usState = bPrimary ? 1 : 2;
            reinterpret_cast<AE6DE0Slot*>(pPauseEntries)[i].m_pResource = pData;
            return true;
        }
    }
    return false;
}

extern "C" int __cdecl CopyRelativeDataPath(int src, char* dst, unsigned int size);

// AudioLoadTask.h lacks AudioLoadTask(int); retain its constructor and base method view.
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

// @fnv 0x00ae6f50
FUN_00ae6f50::FUN_00ae6f50(int aValue) : BaseObj_b5112(0)
{
    m_30 = aValue;
    char buf[0x104];
    CopyRelativeDataPath(m_30 + 0x36, buf, 0x104);
    SetupBuffer(buf);
    SetMode(3);
}

struct Sound7390
{
    virtual void* __thiscall ScalarDeletingDestructor(unsigned int);
    int unk04;
    unsigned int uiFlags08;
    int unk0C;
    unsigned int uiFlags10;
};
struct AudioHelper7390
{
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove();
};
AudioHelper7390* __stdcall BSAudioManager_QInstance_00ad9060(AudioLoadTask*);
// @fnv 0x00ae7390
void __thiscall AudioLoadTask::Cancel(BS_TASK_STATE, void*)
{
    BSAudioManager_QInstance_00ad9060(this)->NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove();
    unsigned int uiSoundFlags;
    Sound7390* pDeleteFirst;
    Sound7390* pSoundToDelete;
    if (SoundAssetTmp && ((uiSoundFlags = reinterpret_cast<Sound7390*>(SoundAssetTmp)->uiFlags08) & 0x8000))
    {
        pDeleteFirst = static_cast<Sound7390*>(SoundAssetTmp);
        pSoundToDelete = pDeleteFirst;
        pSoundToDelete ? pSoundToDelete->ScalarDeletingDestructor(1) : 0;
    }
    else if (SoundAssetTmp)
    {
        Sound7390* nodeToClear = static_cast<Sound7390*>(SoundAssetTmp);
        nodeToClear->uiFlags10 = false ? nodeToClear->uiFlags10 | 0x200u : nodeToClear->uiFlags10 & ~0x200u;
        Sound7390* nodeToSet = static_cast<Sound7390*>(SoundAssetTmp);
        nodeToSet->uiFlags10 = true ? nodeToSet->uiFlags10 | 0x10u : nodeToSet->uiFlags10 & ~0x10u;
    }
}

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

// @fnv 0x00ae7990
Msg_ae7990& Msg_ae7990::CopyFrom(const Msg_ae7990& aOther)
{
    int j;
    int e;
    unsigned int uiShortIndex;
    unsigned int p;
    unk00 = aOther.unk00;
    unk04 = aOther.unk04;
    unk08 = aOther.unk08;
    unk0c = aOther.unk0c;
    ptr10 = aOther.ptr10;
    for (p = 0; p < 3; ++p)
    {
        f14[p] = aOther.f14[p];
    }
    for (uiShortIndex = 0; uiShortIndex < 5; ++uiShortIndex)
    {
        s14[uiShortIndex] = aOther.s14[uiShortIndex];
    }
    return *this;
}

struct AE8470Item;

struct AE8470List
{
    AE8470Item* m_pkItem;
    AE8470List* m_pkNext;

    void SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*));
};

// Bubble-sorts the linked list by swapping item pointers using pfnCompare, counting non-null items to bound the passes.
// @fnv 0x00ae8470
void AE8470List::SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*))
{
    AE8470List* pkCur8 = this;
    AE8470List* pkPrev4 = 0;
    if (pkCur8)
    {
        int iPasses;
        AE8470Item* pkCurItem;
        AE8470Item* pkPrevItemTmp;
        {
            int iCount = 0;
            AE8470List* pkIter3 = pkCur8;
            while (pkIter3)
            {
                if (pkIter3->m_pkItem)
                    iCount++;
                pkIter3 = pkIter3->m_pkNext;
            }
            iPasses = iCount;
        }
        bool bSwapped = true;
        while (iPasses && bSwapped)
        {
            bSwapped = false;
            while (pkCur8)
            {
                if (pkPrev4)
                {
                    pkCurItem = pkCur8->m_pkItem;
                    pkPrevItemTmp = pkPrev4->m_pkItem;
                    if (pfnCompare(pkPrevItemTmp, pkCurItem) > 0)
                    {
                        if (!pkPrevItemTmp)
                        {
                        }
                        else
                        {
                            pkCur8->m_pkItem = pkPrevItemTmp;
                        }
                        if (!pkCurItem)
                        {
                        }
                        else
                        {
                            pkPrev4->m_pkItem = pkCurItem;
                        }
                        bSwapped = true;
                    }
                }
                pkPrev4 = pkCur8;
                pkCur8 = pkCur8->m_pkNext;
            }
            iPasses--;
        }
    }
}

struct FUN_00ae8550_shell
{
    void __thiscall SortValuesByComparison(int* values, int(__cdecl* compare)(int, int), int count);
};

// Sorts the values array in place using a Shell sort with a Knuth gap sequence and the given comparison function.
// @fnv 0x00ae8550
// src: GUESS 0x00ae8550 (confidence: high)
void __thiscall FUN_00ae8550_shell::SortValuesByComparison(int* values, int(__cdecl* compare)(int, int), int count)
{
    int offset;
    {
        int last;
        int gap;
        {
            int index;
            {
                int value;
                {
                    int position;

                    gap = 0;
                    offset = 0;
                    last = count - 1;
                    gap = 1;

                    for (; gap <= (last - offset) / 9; gap = gap * 3 + 1)
                    {
                    }

                    for (; gap > 0; gap /= 3)
                    {
                        for (index = offset + gap; index <= last; ++index)
                        {
                            position = index;
                            value = values[index];

                            while (position >= offset + gap && compare(value, values[position - gap]) < 0)
                            {
                                values[position] = values[position - gap];
                                position -= gap;
                            }

                            values[position] = value;
                        }
                    }
                }
            }
        }
    }
}

extern Setting g_011f6ee0;

void __cdecl SetAudioThreadName(int aiHandle, const char* apName);

// @fnv 0x00ad9f30
// src: COMMUNITY 0x00ad9f30
void BSAudioManager::StartAudioThread(void)
{
    if (pUpdateThread)
    {
        int iHandle = pUpdateThread->m_uiCreatedThreadId;
        if (iHandle == 0)
        {
            pUpdateThread->Initialize(BSThread::MEDIUM_STACK_SIZE, "LibAudioUpdate", false);

            int iHandleAfterInit = pUpdateThread->m_uiCreatedThreadId;
            dwAudioThreadID = iHandleAfterInit;

            int* pSettingValue = &g_011f6ee0 ? &g_011f6ee0.uValue.i : &(DAT_01202800 = 0);
            int iSetPriority = *pSettingValue;
            pUpdateThread->SetPriority(iSetPriority);

            pUpdateThread->SetName("LibAudioUpdate");
            int iThreadIdentifier = pUpdateThread->m_uiCreatedThreadId;
            int iPrioritySave;  // the original source declares this and never uses it; the slot is part of its frame
            SetAudioThreadName(iThreadIdentifier, "LibAudioUpdate");
        }
        pUpdateThread->Wakeup();
    }
}

typedef bool(__cdecl* ADD630ResolveFunc)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                         unsigned int* puiExtra);

extern BSAudio* DAT_011f6d98;

// @fnv 0x00add630
// src: COMMUNITY 0x00add630
void BSAudioManager::Precache_00add630(unsigned int pcName, unsigned int uiFlags)
{
    unsigned int uiResolvedFlags3 = uiFlags;
    BSAudio* pkAudio5 = DAT_011f6d98;
    ADD630ResolveFunc pfnResolve4 = reinterpret_cast<ADD630ResolveFunc>(pkAudio5->pfnIDCallback);
    unsigned int _uiExtra = 0;
    BSAudio* pkAudio2 = DAT_011f6d98;
    bool bEnabled6 = pkAudio2->bAudioEnabled;
    char acPath4[260];
    if (!bEnabled6 || !pfnResolve4 || !pfnResolve4(reinterpret_cast<const char*>(pcName), acPath4, &uiResolvedFlags3, &_uiExtra))
        return;
    uiFlags |= uiResolvedFlags3;
    BSAudioManager_Precache_00add6f0(reinterpret_cast<unsigned int>(acPath4), uiFlags, _uiExtra);
}

struct Sub
{
    void __thiscall FUN_00ae88c0(const void* src);
};

struct S
{
    int f0;
    float f4;
    float f8;
    int fc;
    int f10;
    unsigned char f14;
    char pad15[3];
    Sub sub;
    S* __thiscall AssignFrom(const S* src);
};

// Copies the scalar fields from src into this and forwards src's sub object to sub.FUN_00ae88c0, returning this.
// @fnv 0x00ae7920
S* __thiscall S::AssignFrom(const S* apSource)
{
    int u1, u2, u3, u4;
    f0 = apSource->f0;
    f4 = apSource->f4;
    f8 = apSource->f8;
    fc = apSource->fc;
    f10 = apSource->f10;
    f14 = apSource->f14;
    sub.FUN_00ae88c0(&apSource->sub);
    return this;
}

extern Setting g_011f6e74;


// Scales a1 by fMasterVolume*fMasterSecondaryVolume and a setting value, then applies a further gain pair chosen by the flags in a2 and returns the result.
// @fnv 0x00adac30
// src: COMMUNITY 0x00adac30
float BSAudioManager::GetVolumeValue(float afBase, unsigned int auiFlags)
{
    float f6 = afBase;
    float* pSettingValue = &g_011f6e74 ? &g_011f6e74.uValue.f : &(*(float*)& DAT_01202800 = 0.0f);
    f6 = fMasterVolume * fMasterSecondaryVolume * *pSettingValue * f6;
    if (auiFlags & 0x800000)
    {
        return f6 * fMusicVolume * fMusicSecondaryVolume;
    }
    if (auiFlags & 8)
    {
        f6 = fFootVolume * fFootSecondaryVolume * f6;
    }
    else if (auiFlags & 4)
    {
        f6 = fVoiceVolume * fVoiceSecondaryVolume * f6;
    }
    else if (auiFlags & 0x800)
    {
        f6 = fMusicVolume * fMusicSecondaryVolume * f6;
    }
    else if (auiFlags & 0x100000)
    {
        f6 = fRadioVolume * fRadioSecondaryVolume * f6;
    }
    else
    {
        f6 = fEffectsVolume * fEffectsSecondaryVolume * f6;
    }
    return f6;
}

extern "C" char DAT_011f6ebc;
extern "C" char DAT_011f6ed4;
extern "C" char DAT_011f6ec8;
struct Sound
{
    virtual ~Sound();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual Sound* Create(int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(Sound*, int);
    int p4;
    unsigned int flags;
    char padding[0x138];
    unsigned int id;
    int p148;
    unsigned int size;
};
struct Node
{
    Node* next;
    int p4;
    Sound* sound;
};
struct LinkedSoundQueue
{
    Node* head;
    int p4;
    unsigned int count;
    Sound* FUN_00ae7f90();
    Sound* PopFront();
    void _NiTListBase_AddHead(Sound* const&);
};
struct DeleteView
{
    virtual void* Destroy(unsigned int);
};
// Locks the critical section, rejects duplicate or oversized sounds, clones the input into the list, then evicts entries while total exceeds the limit.
// @fnv 0x00adcd80
void BSAudioManager::AddSound(BSGameSound* apSound)
{
    Sound* v35 = 0;
    Sound* v16;
    Sound* v2;
    Sound* v13;
    Sound* v9;
    EnterCriticalSection(reinterpret_cast<CritSecA*>(CacheCritSection));
    int count;
    {
        unsigned int n = reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->count;
        count = n;
    }
    {
        unsigned char* p = &DAT_011f6ebc ? (unsigned char*)&DAT_011f6ebc + 4
                                         : (*(unsigned char*)& DAT_01202800 = 0, (unsigned char*)&DAT_01202800);
        if (!*p && count > 0)
        {
            struct U8
            {
                int a, b;
            };
            U8 unused;
            while (!(unsigned char)(int)(reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->count == 0))
            {
                v35 = reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->FUN_00ae7f90();
                if (v35)
                {
                    v2 = v35;
                    v16 = v2;
                    v16 ? ((DeleteView*)v16)->Destroy(1) : 0;
                }
            }
            LeaveCriticalSection(reinterpret_cast<CritSecA*>(CacheCritSection));
            return;
        }
        else
        {
            unsigned char* p = &DAT_011f6ebc ? (unsigned char*)&DAT_011f6ebc + 4
                                             : (*(unsigned char*)& DAT_01202800 = 0, (unsigned char*)&DAT_01202800);
            {
                unsigned int n;
                {
                    unsigned int* pi;
                    {
                        unsigned int f;
                        if (!*p || !apSound ||
                            (n = reinterpret_cast<Sound*>(apSound)->size,
                             pi = &DAT_011f6ed4 ? (unsigned int*)(&DAT_011f6ed4 + 4)
                                                : (*(unsigned int*)& DAT_01202800 = 0, (unsigned int*)&DAT_01202800),
                             n > (*pi << 10)) ||
                            (f = reinterpret_cast<Sound*>(apSound)->flags, f & 0x10000))
                        {
                            LeaveCriticalSection(reinterpret_cast<CritSecA*>(CacheCritSection));
                            return;
                        }
                    }
                }
            }
        }
    }
    Node* v3 = reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->head;
    while (v3)
    {
        v35 = v3->sound;
        if ((unsigned char)(int)(reinterpret_cast<Sound*>(apSound)->id == v35->id))
        {
            LeaveCriticalSection(reinterpret_cast<CritSecA*>(CacheCritSection));
            return;
        }
        v3 = v3 ? v3->next : 0;
    }
    Sound* v15 = reinterpret_cast<Sound*>((*(BSAudio* volatile*)&DAT_011f6d98)->Create(0));
    {
        unsigned int f = reinterpret_cast<Sound*>(apSound)->flags;
        {
            Sound* p = v15;
            p->flags = f;
        }
    }
    v15->Copy(reinterpret_cast<Sound*>(apSound), 0);
    {
        unsigned int f = reinterpret_cast<Sound*>(apSound)->flags;
        {
            Sound* p = v15;
            p->flags = f | 0x8000;
        }
    }
    reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->_NiTListBase_AddHead(v15);
    {
        struct U4
        {
            int a;
        };
        U4 unused;
    }
    {
        unsigned int f = reinterpret_cast<Sound*>(apSound)->flags;
        if (!(f & 0x20000000))
        {
            unsigned int n = v15->size;
            iCurrentCachSize += n;
        }
    }
    v35 = 0;
    int v1 = 0;
    {
        unsigned int* p;
        {
            struct U12
            {
                int a, b, c;
            };
            U12 unused;
        }
        {
            unsigned int f;
            {
                unsigned int g;
                {
                    unsigned int n;
                    while ((p = &DAT_011f6ec8 ? (unsigned int*)(&DAT_011f6ec8 + 4)
                                              : (*(unsigned int*)& DAT_01202800 = 0, (unsigned int*)&DAT_01202800),
                            iCurrentCachSize > (*p << 10)) &&
                           !(unsigned char)(int)(reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->count == 0))
                    {
                        v35 = reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->PopFront();
                        if (v35 &&
                            (((f = v35->flags, !(f & 0x20000)) && (g = v35->flags, !(g & 0x20000000))) || v1 > 30))
                        {
                            n = v35->size;
                            iCurrentCachSize -= n;
                            v9 = v35;
                            v13 = v9;
                            v13 ? ((DeleteView*)v13)->Destroy(1) : 0;
                        }
                        else
                        {
                            if (v35)
                                reinterpret_cast<LinkedSoundQueue*>(CachedSoundList)->_NiTListBase_AddHead(v35);
                        }
                        v1++;
                    }
                }
            }
        }
    }
    {
        struct U16
        {
            int a, b, c, d;
        };
        U16 unused;
    }
    LeaveCriticalSection(reinterpret_cast<CritSecA*>(CacheCritSection));
}

namespace fnv_00addc70 {
struct LinkedSoundQueue
{
    int pHead;
    int pTail;
    int iCount;
    int __thiscall FUN_00ae7f90();
    void __thiscall FUN_00ae8370();
};
struct FUN_00ae76b0_shell
{
    void __thiscall FUN_00ae75f0(int item);
    int __thiscall AudioMessageStack_Pop_00ae76b0();
};
struct AudioThreadData
{
    int unk00;
    int iWriteIndex;
    int iReadIndex;
    LinkedSoundQueue kLists0;
    LinkedSoundQueue kLists1;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_00ae76b0_shell kQueue;
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
    CritSecA kLock;
    bool __thiscall ProcessMessage_00adf080(int item);
    void __thiscall BSAudioManager_FreeMessage(int item);
    void __thiscall ProcessAudioQueue();
};
// @fnv 0x00addc70
void AudioThreadData::ProcessAudioQueue()
{
    int item9 = 0;
    LinkedSoundQueue* pListU = &kLists0 + iReadIndex;
    int aPHead;
    int kPTail;
    int pHead2;
    int pTail2;
    int unkA;
    int unk1;
    int unk5;
    int unk9;
    int unkE;
    int aUnk;
    int unk2;
    int unk6;
    if (pListU == 0)
        return;
    while (!(bool)(int)(pListU->iCount == 0) && (aPHead = pListU->pHead) != 0 && (kPTail = pListU->pTail) != 0)
    {
        item9 = pListU->FUN_00ae7f90();
        if (ProcessMessage_00adf080(item9))
            return;
        kQueue.FUN_00ae75f0(item9);
    }
    if (!(bool)(int)(pListU->iCount == 0) && ((pHead2 = pListU->pHead) == 0 || (pTail2 = pListU->pTail) == 0))
        pListU->FUN_00ae8370();
    EnterCriticalSection(&kLock);
    iWriteIndex = (iWriteIndex + 1) % 2;
    iReadIndex = (iWriteIndex + 1) % 2;
    item9 = kQueue.AudioMessageStack_Pop_00ae76b0();
    while (item9)
    {
        BSAudioManager_FreeMessage(item9);
        item9 = kQueue.AudioMessageStack_Pop_00ae76b0();
    }
    LeaveCriticalSection(&kLock);
}
}  // namespace fnv_00addc70

struct Handle_ae5680
{
    int f0;
    char f4;
    int f8;
};

typedef bool(__cdecl* Resolver_ae5680)(int, void*, unsigned int*, int*);

struct AudioClass_ae5680
{
    Handle_ae5680 __thiscall BSAudioManager_InitSoundPath(const void* pPath, unsigned int uiFlags, int iExtra);
    Handle_ae5680* __thiscall ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags);
};

// @fnv 0x00ae5680
Handle_ae5680* AudioClass_ae5680::ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags)
{
    int iState = 0;
    unsigned int uiOutFlags = 0;
    BSAudio* pMgrJ = reinterpret_cast<BSAudio*>(DAT_011f6d98);
    bool bReady_ = pMgrJ->bAudioEnabled;
    BSAudio* pMgr4;
    Resolver_ae5680 pfn3;
    char path3[260];
    int aIExtra;
    if (!bReady_)
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    pMgr4 = reinterpret_cast<BSAudio*>(DAT_011f6d98);
    pfn3 = reinterpret_cast<Resolver_ae5680>(pMgr4->pfnNameCallback);
    aIExtra = 0;
    if (pfn3 == 0 || !pfn3(aiSoundId, path3, &uiOutFlags, &aIExtra))
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    if (uiOutFlags & 0x08000000)
    {
        uiFlags |= 1;
        uiFlags |= 0x08000000;
    }
    if (uiOutFlags & 0x02000000)
    {
        uiFlags |= 0x02000000;
        uiFlags &= ~0x10;
    }
    else if (uiOutFlags & 0x04000000)
    {
        uiFlags |= 0x04000000;
        uiFlags &= ~0x10;
    }
    if (path3[0] == 0)
    {
        pOut->f0 = -1;
        pOut->f4 = 0;
        pOut->f8 = 0;
        iState |= 1;
        return pOut;
    }
    Handle_ae5680 h7 = BSAudioManager_InitSoundPath(path3, uiFlags, aIExtra);
    pOut->f0 = h7.f0;
    pOut->f4 = h7.f4;
    pOut->f8 = h7.f8;
    iState |= 1;
    return pOut;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct FUN_00ae8650_cls
{
    unsigned int m_00, m_04, m_08, m_0c;
    void* m_10;
    float m_14, m_18, m_1c;
    FUN_00ae8650_cls* InitializeFields();
};
// Initializes all members to zero and increments the reference count of the object stored in m_10 if it is non-null.
// @fnv 0x00ae8650
// src: GUESS 0x00ae8650 (confidence: medium)
FUN_00ae8650_cls* FUN_00ae8650_cls::InitializeFields()
{
    void* pTarget;
    {
        void** slot = &m_10;
        *slot = 0;
        if (*slot != 0)
        {
            pTarget = *slot;
            InterlockedIncrement((long*)((char*)pTarget + 4));
        }
    }
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_0c = 0;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    return this;
}

extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_00fdbfd0();
extern int DAT_011f6ef0;
struct FUN_00ad90e0_shell
{
    FUN_00ad90e0_shell();
    ~FUN_00ad90e0_shell();
};
// Returns a pointer to a static singleton instance of FUN_00ad90e0_shell.
// @fnv 0x00ad9060
// src: XBOX_PDB 0x00ad9060
FUN_00ad90e0_shell* __cdecl BSAudioManager_QInstance_00ad9060()
{
    static FUN_00ad90e0_shell sInstance;
    return &sInstance;
}

extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void*);

struct AudioHelperA
{
    void UpdateAccumulatedTime();
};

struct AudioHelperB
{
    void ProcessAudioQueue();
    void BSAudioManager_ProcessSoundUpdates();
};

struct AudioManagerUpdate
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8;
    CritSecA critical0dc;
    CritSecA m_cs;
    void BSAudioManager_Process();
};

// Calls the audio system update helper, then acquires m_cs and invokes two AudioHelperB methods if the lock is obtained.
// @fnv 0x00addc00
// src: COMMUNITY 0x00addc00
void AudioManagerUpdate::BSAudioManager_Process()
{
    BSAudio* p = DAT_011f6d98;
    reinterpret_cast<AudioHelperA*>(&p->SynchTimer)->UpdateAccumulatedTime();
    bool locked = fnv_Import_TryEnterCriticalSection(&m_cs) != 0;
    if (locked)
    {
        reinterpret_cast<AudioHelperB*>(BSAudioManager_QInstance_00ad9060())->ProcessAudioQueue();
        reinterpret_cast<AudioHelperB*>(BSAudioManager_QInstance_00ad9060())->BSAudioManager_ProcessSoundUpdates();
        LeaveCriticalSection(&m_cs);
    }
}

extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
struct S_00ae77d0_Sem
{
    long initial;
    void* h;
    long max;
};
// BSAudioManagerThread.h lacks an explicit default constructor; retain this constructor view.
struct FUN_00ae77d0 : BSThread
{
    S_00ae77d0_Sem sem0;
    S_00ae77d0_Sem sem1;
    char unk48;
    FUN_00ae77d0();
    virtual void v0();
};
// Initializes two binary semaphores with initial count 0 and max 1, and sets unk48 to 1.
// @fnv 0x00ae77d0
FUN_00ae77d0::FUN_00ae77d0()
{
    S_00ae77d0_Sem* a = &sem0;
    a->initial = 0;
    a->max = 1;
    a->h = CreateSemaphoreA(0, a->initial, a->max, 0);
    S_00ae77d0_Sem* b = &sem1;
    b->initial = 0;
    b->max = 1;
    b->h = CreateSemaphoreA(0, b->initial, b->max, 0);
    unk48 = 1;
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* h, long n, long* prev);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* h, unsigned long ms);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

// Sets processing, signals signalSemaphore, waits on waitSemaphore, then clears processing.
// @fnv 0x00ae7a50
// src: COMMUNITY 0x00ae7a50
void BSAudioManagerThread::Suspended()
{

    waiting48 = true;

    BSSemaphore_adf080* signal = &workSemaphore3c;

    ReleaseSemaphore(signal->semaphore, 1, 0);

    InterlockedIncrement(&signal->count);

    BSSemaphore_adf080* waiting = &doneSemaphore30;

    WaitForSingleObject(waiting->semaphore, 0xFFFFFFFF);

    InterlockedDecrement(&waiting->count);

    waiting48 = false;
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

// Sets waiting48, releases workSemaphore3c, increments its count, and calls FUN_00aa6590.
// @fnv 0x00ae7ac0
// src: COMMUNITY 0x00ae7ac0
void BSAudioManagerThread::ExitThread_00ae7ac0()
{
    waiting48 = true;
    BSSemaphore_adf080* semaphore = &workSemaphore3c;
    ReleaseSemaphore(semaphore->semaphore, 1, 0);
    InterlockedIncrement(&semaphore->count);
    ForwardCall_00aa6590(0, 0);
}

struct S00ae6f10_SubObj_00ae6f10
{
    void __thiscall NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSTextureManager_RenderedTextureData_RemovePos(void* p);
};
struct S00ae6f10_FUN_00ae6f10_cls
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
    CritSecA m_10c;
    S00ae6f10_SubObj_00ae6f10 m_124;
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(int arg);
};

struct S00ae6f10_FUN_00ae6f10_frame
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
};

// Locks m_10c, passes the address of arg to m_124.FUN_00ae8150, then unlocks m_10c.
// @fnv 0x00ae6f10
// src: XBOX_PDB 0x00ae6f10
void S00ae6f10_FUN_00ae6f10_cls::NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(int aValue)
{
    S00ae6f10_FUN_00ae6f10_frame frame;
    EnterCriticalSection(&m_10c);
    m_124.NiTPointerListBase_NiTPointerAllocator_unsigned_int_BSTextureManager_RenderedTextureData_RemovePos((void*)&aValue);
    LeaveCriticalSection(&m_10c);
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
extern int DAT_01202d98;

// Waits on doneSemaphore30, then loops calling FUN_00addc00 on the update object when DAT_01202d98 is set, sleeping 1 ms each iteration.
// @fnv 0x00ae74b0
unsigned int BSAudioManagerThread::ThreadProc()
{
    BSSemaphore_adf080* semaphore = &doneSemaphore30;
    WaitForSingleObject(semaphore->semaphore, 0xFFFFFFFF);
    InterlockedDecrement(&semaphore->count);
    waiting48 = false;
    while (1)
    {
        if (DAT_01202d98 != 0)
        {
            reinterpret_cast<AudioManagerUpdate*>(BSAudioManager_QInstance_00ad9060())->BSAudioManager_Process();
        }
        Sleep(1);
    }
    return 0;
}

struct ScrapHeapBuffer;
struct BSMapBase
{
    bool __thiscall GetAt(unsigned long, ScrapHeapBuffer*&);
};
struct FUN_00adc8b0_shell
{
    float __thiscall BSAudioManager_GetVolume(unsigned long);
};
// @fnv 0x00adc8b0
// src: XBOX_PDB 0x00adc8b0
float __thiscall FUN_00adc8b0_shell::BSAudioManager_GetVolume(unsigned long auiKey)
{
    float fVol;
    {
        ScrapHeapBuffer* pBuffer;
        {
            int iUnusedA;
            int iUnusedB;
            pBuffer = 0;
            fVol = 0.0f;
            EnterCriticalSection((CritSecA*)((char*)this + 0xC4));
            ((BSMapBase*)((char*)this + 0x64))->GetAt(auiKey, pBuffer);
            LeaveCriticalSection((CritSecA*)((char*)this + 0xC4));
            if (pBuffer != 0)
            {
                fVol = *(float*)((char*)pBuffer + 8);
            }
        }
    }
    return fVol;
}
