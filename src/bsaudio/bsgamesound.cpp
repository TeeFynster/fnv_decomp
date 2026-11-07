// bsaudio/bsgamesound.cpp: BSGameSound, BSGameSoundOperations, AudioPathFixer (24 functions)

#include "../../include/BSWin32Audio.h"
#include "../../include/BSAudioManager.h"
#include "../../include/BSGameSound.h"
#include "../../include/MemoryManager.h"
// LocalVec: unit-local copy of the former shared stand-in Vec. Its default constructor fills x/y/z with FLT_MAX here, unlike NiPoint3's empty one.
#include <xmmintrin.h>
class Matrix;
class Scalar;
class Simd;
class Tok;
class Mask;
class Elem;
class Iter;
class CIter;
class CMutIter;
class Mat3;
class Mat4;
class hkVector4;
class hkQuaternion;

class LocalVec
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        struct
        {
            void* m_pData;
            int m_iArrayLength;
            int m_iCapacity;
        };
    };

    LocalVec();
    LocalVec(float a, float b, float c);
    // Keep the implicit copy constructor, copy assignment and destructor trivial.

    void negative(const LocalVec& n);
    void inv(const Matrix& m, const LocalVec& n);
    void point(const Matrix& m, const LocalVec& b);
    void difference(const LocalVec& a, const LocalVec& b);
    Scalar dot(const LocalVec& n) const;
    Scalar at(int i) const;
    void set(float a, float b, float c, float d);

    Simd lengthSquared() const;
    void mul(const Simd& factor);
    void SetProduct(const Simd& factor, const LocalVec& v);

    void resize(unsigned n);
    Tok& operator[](unsigned i);
    void release(int elemSize);

    LocalVec& operator-=(const LocalVec& v);
    LocalVec& operator+=(const LocalVec& v);
    LocalVec operator*(float scale) const;
    LocalVec operator+(const LocalVec& v) const;
    LocalVec operator-(const LocalVec& v) const;
    float Squared() const;
    float Length() const;
    float Normalize();
    float Dot(const LocalVec& v) const;
    LocalVec Cross(const LocalVec& v) const;
    LocalVec ApplyScaled(float scale);
    LocalVec ApplyScaled(float scale) const;
    void ProcessState_00acf580(unsigned n, Tok value);
    LocalVec GetNegatedVector();
    LocalVec GetNegatedVector() const;
    LocalVec FUN_0053d1a0(const LocalVec& v);
    LocalVec FUN_004b3800(const LocalVec& v);
    LocalVec FUN_004b3800(const LocalVec& v) const;
    LocalVec FUN_00439e90(const LocalVec& v);
    LocalVec FUN_00439e90(const LocalVec& v) const;
    LocalVec SubtractIntoVector(const LocalVec& v);
    LocalVec SubtractIntoVector(const LocalVec& v) const;
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    void FUN_006815c0();
    void ScaleComponents(float scale);
    LocalVec& ComputeValue_0063c8a0(const LocalVec& v);
    float FUN_004a7290();
    float FUN_004a7290() const;
    void SetQuaternionComponentsFromVector(const float* values);
    void FUN_00a38560();
    void NiQuaternion_ToRotation(void* value);

    LocalVec& ScaleByInverse(float divisor);
    float FUN_00457910();
    LocalVec* FastNavMeshTriLocation_GetLocation();
    bool HasEqualComponents(const LocalVec& v);

    __m128 get() const;
    void set(__m128 value);
    void operator=(const __m128& value);
    operator __m128() const;
    __m128& getQuad();
    const __m128& getQuad() const;
    __m128& quad();
    const __m128& quad() const;
    float& operator()(int component);
    const float& operator()(int component) const;
    void setZero4();
    void setSub4(const LocalVec& a, const LocalVec& b);
    void setAdd4(const LocalVec& a, const LocalVec& b);
    void setMul4(const LocalVec& a, const LocalVec& b);
    void setMul4(const Scalar& a, const LocalVec& b);
    void add4(const LocalVec& v);
    void mul4(const LocalVec& v);
    void mul4(const Scalar& value);
    void add3clobberW(const LocalVec& v);
    void sub3clobberW(const LocalVec& v);
    void setBroadcast3clobberW(const LocalVec& v, int component);
    Scalar horizontalAdd3() const;
    void setCross(const LocalVec& a, const LocalVec& b);
    Scalar dot3(const LocalVec& v) const;
    Scalar lengthSquared3() const;
    Scalar lengthInverse3() const;
    void normalize3();
    Scalar getSimdAt(int component) const;
    void setInterpolate4(const LocalVec& a, const LocalVec& b, const Scalar& fraction);
    void setAddMul4(const LocalVec& a, const LocalVec& b, const Scalar& scale);
    void setNeg4(const LocalVec& v);
    Mask compareLessThanZero4() const;
    void SetRotatedDirection(const hkQuaternion& rotation, const LocalVec& direction);
    void setRotatedTranslation(const hkQuaternion& rotation, const LocalVec& direction);
    void cross(const LocalVec& a, const LocalVec& b);
    Scalar squared() const;
    Scalar inverseLength() const;
    void normalize();
    void negate(const LocalVec& v);

    void setTransformedPos_00c7f640(const void* matrix, const hkVector4& point);
    void setTransformedPos_00c7f640(Mat4* matrix, void* point);
    void setTransformedPos_00c7f640(const void* matrix, const LocalVec* point);
    void setTransformedPos_00c7f640(const void* matrix, const void* point);
    void hkVector4_setRotatedDir(Mat3* matrix, void* point);
    void hkVector4_setRotatedDir(const void* matrix, const LocalVec* point);
    void Normalize_00b12790();
    void Diff_00b13040(LocalVec* out, const LocalVec* v);
    LocalVec* ScaleSwizzled(LocalVec* out, float factor);
    void AddVector(LocalVec* out, const LocalVec* v);
    float Dot(const LocalVec& v);
    LocalVec* FUN_004a3c90(const LocalVec* v);
    LocalVec* FUN_0062b0a0(LocalVec* out, LocalVec* v);
    LocalVec* hkVector4_lengthInverse3(LocalVec* target);

    void FUN_00cf7690(Elem* value);
    void UpdateState_00b1e970();
    Iter begin();
    Iter end();
    CIter UpdateState_00b33030(CIter first, CIter last);
    void m_vStrips_clear();
    unsigned int size() const;
    unsigned int capacity() const;
    void ClearAllElements();
    void B2EDestroyRange_Thunk(Elem* first, Elem* last);
    bool InitBuffer(unsigned int count);
    Elem* _Ucopy(Elem* first, Elem* last, Elem* out);
    LocalVec& CTreeEngine_SetLeafTextures(const LocalVec& v);
    CMutIter ProcessAndReturnValue_00aceb80(CMutIter first, CMutIter last);
    void ProcessState_00acac40();
    LocalVec& ReleaseStorage_00ad61e0(const LocalVec& v);
};
#include "../../include/NiPoint3.h"

extern MemoryManager g_memoryManager;

inline LocalVec::LocalVec()
{
    x = 3.402823466e+38F;
    y = 3.402823466e+38F;
    z = 3.402823466e+38F;
}

class MersenneTwister
{
  public:
    MersenneTwister();
    unsigned int GetRandomUInt(unsigned int);
    static __forceinline MersenneTwister& GetRandomGenerator()
    {
        static MersenneTwister random;
        return random;
    }
};

// Operations not yet declared by the shared interface add no fields or virtual slots.
struct BSGameSoundOperations : BSGameSound
{
    bool SetFlagState(bool value);
    void SetFlag(bool value);
    bool IsSameSound(BSGameSound* sound);
    bool IsSameSound(unsigned int priority);
    bool UpdateDistance(float);
    bool Flag100() { return (iSoundTypeFlags & 0x100) != 0; }
    bool State20000() { return (iStateFlags & 0x20000) != 0; }
    bool Flag2000000() { return (iSoundTypeFlags & 0x2000000) != 0; }
    bool IsSpatial()
    {
        return (iSoundTypeFlags & 0x10) || (iSoundTypeFlags & 0x4000000) || (iSoundTypeFlags & 0x2000000);
    }
    // Slot 0x14 takes a bool here; the shared v14 declaration has no parameter yet.
    __forceinline void SetVirtualFlag(bool value)
    {
        ((void (__thiscall*)(BSGameSound*, bool))(*(void***)this)[5])(this, value);
    }
};

extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);

extern BSAudio* DAT_011f6d98;

inline BSAudio* BSAudio::GetRandomGenerator()
{
    return DAT_011f6d98;
}

inline void(__cdecl* BSAudio::GetCallback())(char*)
{
    return (void(__cdecl*)(char*))pfnRandomFilenameCallback;
}

// @fnv 0x00ae9cf0
bool BSGameSound::HasSoundFlagTwo()
{
    return (iSoundTypeFlags & 2) != 0;
}

// Computes a hash from the characters of pName after the first, returning 0 when pName is null.
// @fnv 0x00ae9d80
unsigned int BSGameSound::ComputeSoundNameHash(const char* pName)
{
    unsigned int hash = 0;
    if (!pName)
        return hash;
    {
        const char* p = pName;
        while (*(++p))
            hash = *p + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

// @fnv 0x00ae9d50
bool BSGameSound::LoadFromFilename(bool resolve)
{
    if (pFilename)
    {
        return HasMaster(pFilename, resolve);
    }
    else
    {
        return false;
    }
}
// @fnv 0x00ae9d10
bool BSGameSound::CanStartPlayback()
{
    return (iSoundTypeFlags & 1) && (iSoundTypeFlags & 0x08000000);
}

// @fnv 0x00ae9de0
bool BSGameSound::Prepare()
{
    if (iModifierFlags & 2)
    {
        unsigned int duration = iDurationInMS;
        unsigned int zlimit = duration;
        unsigned int time = MersenneTwister::GetRandomGenerator().GetRandomUInt(zlimit);
        Seek(time);
    }
    iStateFlags = true ? (iStateFlags | 0x800) : (iStateFlags & ~0x800);
    return true;
}

// @fnv 0x00ae97a0
void BSGameSound::Copy(BSGameSound* source, bool)
{
    iSoundHash = source->iSoundHash;
    iDirectoryHash = source->iDirectoryHash;
    HasMaster(source->pFilename, false);
    iSoundID = BSAudioManager::GetRandomGenerator().GetNextID();
    iStateFlags = source->iStateFlags;
    iModifierFlags = source->iModifierFlags;
    iDurationInMS = source->iDurationInMS;
    iStaticAttenuation = source->iStaticAttenuation;
    iReverbAttenuation = source->iReverbAttenuation;
    iSystemAttenuation = source->iSystemAttenuation;
    iDistanceAttenuation = source->iDistanceAttenuation;
    fCurrentVolume = source->fCurrentVolume;
    fBeginTime = source->fBeginTime;
    fEndTime = source->fEndTime;
    iWeatherFlags = source->iWeatherFlags;
    iSamplesPerSecond = source->iSamplesPerSecond;
    iModSamplesPerSecond = source->iModSamplesPerSecond;
    fMaxDist = source->fMaxDist;
    iSoundSize = source->iSoundSize;
    iLoopStart = source->iLoopStart;
    iLoopEnd = source->iLoopEnd;
    fnCompletionCallback = source->fnCompletionCallback;
    fnPlayedCallback = source->fnPlayedCallback;
    pSoundCompletionContext = source->pSoundCompletionContext;
    pSoundPlayContext = source->pSoundPlayContext;
}

// @fnv 0x00ae9460
bool BSGameSound::HasMaster(const char* filename, bool resolve)
{
    bool bResult = true;
    if (!filename)
        return false;
    if (pFilename != filename)
        strcpy_s(pFilename, 260, filename);
    BSAudio::GetRandomGenerator()->vfn_18(pFilename);
    void(__cdecl * pfnCallback)(char*) = BSAudio::GetRandomGenerator()->GetCallback();
    unsigned int iLength = strlen(pFilename);
    bool bDirectory = pFilename[iLength - 1] == '\\' || pFilename[iLength - 1] == '/';
    if (bDirectory && !iDirectoryHash)
        iDirectoryHash = ComputeSoundNameHash(pFilename);
    if (resolve && bDirectory && pfnCallback)
    {
        pfnCallback(pFilename);
        BSAudio::GetRandomGenerator()->vfn_18(pFilename);
    }
    else if (bDirectory && !resolve)
        bResult = false;
    if (!bDirectory || resolve)
        iSoundHash = ComputeSoundNameHash(pFilename);
    else
        iSoundHash = 0;
    return bResult;
}

extern float const g_011c7374_arg1;

// Initializes the object's fields to zero/default values, sets flags at offset 0x10, and clears bit 0x8000.
// @fnv 0x00ae95e0
// src: XBOX_PDB 0x00ae95e0
void __fastcall BSGameSound_Init(BSGameSound* pObject)
{
    pObject->iSoundID = 0;
    pObject->iSoundTypeFlags = 0;
    pObject->iModifierFlags = 0;
    pObject->iStateFlags = 0;
    pObject->iStateFlags |= 0x100;
    pObject->iDurationInMS = 0;
    pObject->iStaticAttenuation = 0;
    pObject->iReverbAttenuation = 0;
    pObject->iSystemAttenuation = 0;
    pObject->iDistanceAttenuation = 0;
    pObject->iFaderAttenuation = 0;
    pObject->fCurrentVolume = 1.0f;
    pObject->fBeginTime = 0.0f;
    pObject->fEndTime = 0.0f;
    pObject->iWeatherFlags = 0;
    pObject->iSamplesPerSecond = 0;
    pObject->fMaxDist = g_011c7374_arg1;
    pObject->fMinDist = 50.0f;
    pObject->iSoundSize = 0;
    pObject->iEnvironmentType = 0;
    pObject->iCleanupDelayInMS = 0;
    pObject->iSynchStartTime = 0;
    pObject->iSoundHash = 0;
    pObject->iDirectoryHash = 0;
    pObject->fDistanceToListener = 3.4028234663852886e+38f;
    pObject->iFreqVariance = 0;
    pObject->iModSamplesPerSecond = 0;
    pObject->iLoopStart = 0;
    pObject->iLoopEnd = 0;
    pObject->fnCompletionCallback = 0;
    pObject->fnPlayedCallback = 0;
    pObject->pSoundCompletionContext = 0;
    pObject->pSoundPlayContext = 0;
    pObject->iStateFlags = false ? (pObject->iStateFlags | 0x8000) : (pObject->iStateFlags & ~0x8000);
}

// If a callback pointer at offset 0x168 is set, calls it with the value at 0x170 and the id at 0x14, then clears both fields.
// @fnv 0x00ae9af0
void __fastcall ClearCallback(BSGameSound* pObject)
{
    if (pObject->fnPlayedCallback != 0)
    {
        int id = pObject->iDurationInMS;
        ((void(__cdecl*)(void*, int))pObject->fnPlayedCallback)(pObject->pSoundPlayContext, id);
        pObject->pSoundPlayContext = 0;
        pObject->fnPlayedCallback = 0;
    }
}

// Sets or clears bits in flags depending on v, and when v is false also sets bit 0x10 and sets iDurationInMS to 1; returns v.
// @fnv 0x00ae9c50
bool BSGameSoundOperations::SetFlagState(bool v)
{
    if (v)
    {
        iStateFlags |= 1;
        iStateFlags |= 0x100;
        iStateFlags &= 0xffffefff;
    }
    else
    {
        iStateFlags &= 0xfffffeff;
        iStateFlags |= 1;
        iStateFlags &= 0xffffefff;
        iStateFlags |= 0x10;
        iDurationInMS = 1;
    }
    return v;
}

struct OL4Alloc
{
    void* p;
    ~OL4Alloc()
    {}
};
struct NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___
{
    void RemoveAll();
    OL4Alloc alloc;
    void* a;
    void* b;
    ~NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___()
    {
        RemoveAll();
    }
};
struct OL4List : NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile__TileTemplateItem___
{
    ~OL4List()
    {}
};
// The shared interface stores the message list as raw bytes.
// @fnv 0x00ae93f0
BSGameSound::~BSGameSound()
{
    int unused[5];
    ((OL4List*)QueuedMessages)->OL4List::~OL4List();
}

extern double _gModifierZero;

// @fnv 0x00ae9b50
// src: COMMUNITY 0x00ae9b50
bool BSGameSound::CanPlayNow(int mask, float afTime)
{
    if ((iWeatherFlags & mask) == 0 && iWeatherFlags != 0 && mask != 0)
        return false;
    float fSpan = fEndTime - fBeginTime;
    fSpan = (fSpan < _gModifierZero) ? fSpan * -1.0 : fSpan;
    if (fSpan >= 0.09375)
    {
        if ((fBeginTime < fEndTime && (fBeginTime > afTime || fEndTime < afTime)) ||
            (fBeginTime > fEndTime && fBeginTime > afTime && fEndTime < afTime))
            return false;
    }
    return true;
}

namespace fnv_00ae9ec0 {
struct BSGameSoundDeletion : BSGameSound
{
    void* DeleteThis(unsigned int flags);
};
// Destroys the base object and, when bit 0 of flags is set, deallocates this via g_memoryManager, returning this.
// @fnv 0x00ae9ec0
void* BSGameSoundDeletion::DeleteThis(unsigned int flags)
{
    this->BSGameSound::~BSGameSound();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00ae9ec0

// @fnv 0x00ae9f70
void BSGameSoundOperations::SetFlag(bool abSet)
{
    iStateFlags = abSet ? (iStateFlags | 0x20000) : (iStateFlags & 0xfffdffff);
}

// Returns true when this sound's value at offset 0x188 is less than the other sound's value at offset 0x188.
// @fnv 0x00ae9fd0
bool BSGameSoundOperations::IsSameSound(BSGameSound* apSound)
{
    return iPriority < apSound->iPriority;
}

// @fnv 0x00aea000
bool BSGameSoundOperations::IsSameSound(unsigned int aiToCompare)
{
    return iPriority < aiToCompare;
}

// Exe 0x00aea590: unit-local BsgamesoundInterfaceView view used by this matched implementation.
struct BsgamesoundInterfaceView
{
    static void __cdecl PrintDebugMessage(const char*);
};

// Initialization methods absent from the shared interface live in this extension.
// It adds no fields and uses BSWin32Audio's shared layout.
struct BSWin32AudioInitialization : BSWin32Audio
{
    bool CheckResult(int result, const char* context);
    void SetWindow(int window);
    void FUN_00ad7020(int);
};

// Returns true when param is non-negative; otherwise logs "Audio system could not be initialized." and returns false.
// @fnv 0x00aea590
bool BSWin32AudioInitialization::CheckResult(int aiResult, const char* unused)
{
    if (aiResult >= 0)
        return true;
    BsgamesoundInterfaceView::PrintDebugMessage("Audio system could not be initialized.");
    return false;
}

struct FUN_00aeac20
{
    FUN_00aeac20(unsigned int a);
    static void* operator new(unsigned int)
    {
        return g_memoryManager.Allocate(0x230);
    }
};
struct FUN_00aea5c0
{
    FUN_00aeac20* Create(unsigned int a);
};
// Allocates a new FUN_00aeac20 object via the memory manager, constructing it with the given value, and returns it.
// @fnv 0x00aea5c0
FUN_00aeac20* FUN_00aea5c0::Create(unsigned int auiValue)
{
    return new FUN_00aeac20(auiValue);
}

namespace fnv_00aea700 {
struct FUN_00aea700;
void __fastcall SetVtableAndProcessState_00aea210(FUN_00aea700* p);
struct FUN_00aea700
{
    void* DeleteThis(unsigned int flags);
};
// Calls FUN_00aea210 on this, frees this via g_memoryManager._DeallocateAlias when flags has bit 0 set, and returns this.
// @fnv 0x00aea700
void* FUN_00aea700::DeleteThis(unsigned int flags)
{
    SetVtableAndProcessState_00aea210(this);
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}
}  // namespace fnv_00aea700

struct BSWin32GameSoundPosition : BSGameSound
{
    NiPoint3* GetPos(NiPoint3* output);
};
// Returns the position through the caller-provided return storage.
// @fnv 0x00aefd20
NiPoint3* BSWin32GameSoundPosition::GetPos(NiPoint3* output)
{
    if (HasSoundFlagTwo() || CanStartPlayback())
    {
        *output = *(NiPoint3*)((char*)this + 0x218);
        return output;
    }
    output->x = 0.0f;
    output->y = 0.0f;
    output->z = 0.0f;
    return output;
}

// Checks spatial and state flags to toggle v14/v30 and call v38 based on comparing fDistanceToListener against fMaxDist, then returns true.
// @fnv 0x00ae9960
bool BSGameSoundOperations::UpdateDistance(float unused)
{
    float distance2, maximum2, distance, maximum;
    if ((HasSoundFlagTwo() || CanStartPlayback()) && !Flag100() && !State20000() && IsPlaying() && IsSpatial() && !Flag2000000() &&
        (distance2 = fDistanceToListener, maximum2 = fMaxDist, maximum2 < distance2))
    {
        v38();
        SetVirtualFlag(true);
    }
    else if (State20000() && !IsPaused() && (distance = fDistanceToListener, maximum = fMaxDist, distance < maximum))
    {
        SetVirtualFlag(false);
        v30(true);
    }
    return true;
}

// BSWin32Audio - the PC audio manager.  This function is vtable slot 1 of it.

// The sound the manager is currently playing.  Slot 0 takes a flag and
// returns a status word.
struct BSAudioVoice
{
    virtual int FUN_00f0(int abEnable);
};

// A sink the manager hands a piece of work to.  Its slots are __stdcall
// callbacks that receive the sink back as their only argument.
struct BSAudioSink
{
    virtual void __stdcall FUN_00f0();
    virtual void __stdcall FUN_00f4();
    virtual void __stdcall FUN_00f8();
};

extern "C" void BSAudio_Shutdown();

extern void(__cdecl* g_pAudioShutdownCallback)();

// @fnv 0x00aea4d0
void BSWin32Audio::Shutdown()
{
    this->bInitialized = 0;
    ((void(__thiscall*)(BSAudio*))BSAudio_Shutdown)(this);
    g_pAudioShutdownCallback();
    if (this->pListener)
    {
        BSAudioVoice* pVoice = (BSAudioVoice*)this->pListener;
        BSAudioVoice* pVoiceChecked = pVoice;
        (pVoiceChecked != 0) ? pVoiceChecked->FUN_00f0(1) : 0;
        this->pListener = 0;
    }
    if (this->pPrimaryBuffer)
    {
        ((BSAudioSink*)this->pPrimaryBuffer)->FUN_00f8();
        this->pPrimaryBuffer = 0;
    }
    if (this->pDirectSound)
    {
        ((BSAudioSink*)this->pDirectSound)->FUN_00f8();
        this->pDirectSound = 0;
    }
}

extern "C" char DAT_011f6d9c, DAT_01202800, DAT_011f6238;
extern "C" char DAT_010a3b10, DAT_010a3ae0, DAT_010a3a78, DAT_010a3a38, DAT_010a39f8, DAT_01100fa4;
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char*);
extern "C" int __stdcall DirectSoundCreate8_00ee81e0(int, void*, int);
extern "C" void* __cdecl FUN_00ec61c0(void*, int, unsigned);
struct Sound
{
    virtual void s0();
    virtual void s1();
    virtual void s2(LocalVec*);
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12(float);
};
struct FUN_00aea730_Class : Sound
{
    char data[96];
    FUN_00aea730_Class(int);
    static void* operator new(unsigned n)
    {
        return ((MemoryManager*)&DAT_011f6238)->Game_DoHeapAlloc(n);
    }
    static void operator delete(void*);
};
struct Desc
{
    int size, flags;
    char rest[28];
};
struct Com
{
    virtual int __stdcall q(void*, int*);
    virtual int __stdcall r1();
    virtual int __stdcall r2();
    virtual int __stdcall create(Desc*, Com**, int);
    virtual int __stdcall caps(void*);
    virtual int __stdcall r5();
    virtual int __stdcall coop(int, int);
};
struct Text
{
    char b[4];
    const char* Get2()
    {
        const char* z = this ? b + 4 : (DAT_01202800 = 0, &DAT_01202800);
        return z;
    }
    const char* Get()
    {
        return Get2();
    }
};
// The shared header does not yet declare this initialization entry point.
// @fnv 0x00aea230
void BSWin32AudioInitialization::SetWindow(int aiWindow)
{
    Desc desc;
    int iResult;
    int iInterface;
    this->hWnd = (void*)aiWindow;
    if (this->bInitialized)
        return;
    if (*(const unsigned char*)((Text*)&DAT_011f6d9c)->Get())
    {
        GetModuleHandleA(0);
        iResult = DirectSoundCreate8_00ee81e0(0, &this->pDirectSound, 0);
        if (!CheckResult(iResult, &DAT_010a3b10))
            return;
        iResult = ((Com*)this->pDirectSound)->coop((int)this->hWnd, 2);
        CheckResult(iResult, &DAT_010a3ae0);
        *(int*)this->Caps = 96;
        iResult = ((Com*)this->pDirectSound)->caps(this->Caps);
        CheckResult(iResult, &DAT_010a3a78);
        FUN_00ec61c0(&desc, 0, 36);
        desc.size = 36;
        desc.flags = 145;
        iResult = ((Com*)this->pDirectSound)->create(&desc, (Com**)&this->pPrimaryBuffer, 0);
        if (!CheckResult(iResult, &DAT_010a3a38))
            return;
        iResult = ((Com*)this->pPrimaryBuffer)->q(&DAT_01100fa4, &iInterface);
        if (!CheckResult(iResult, &DAT_010a39f8))
            return;
        this->pListener = (BSAudioListener*)new FUN_00aea730_Class(iInterface);
    }
    if (this->pListener)
    {
        ((Sound*)this->pListener)->s2(&LocalVec());
        ((Sound*)this->pListener)->s12(1.0f);
    }
    this->bInitialized = 1;
    this->bAudioEnabled = 1;
    BSAudioManager::GetRandomGenerator().BSAudioManager_Initialize();
    FUN_00ad7020(0);
}

extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);

struct AudioPathFixer
{
    void BSWin32Audio_FixSoundPath(char* apName);
};
// If apName starts with "fx" or "song", copies it to a buffer, then rewrites apName to "data\sound\" followed by the original name.
// @fnv 0x00aea640
// src: XBOX_PDB 0x00aea640
void AudioPathFixer::BSWin32Audio_FixSoundPath(char* apName)
{
    char acBuffer[260];
    if (apName && ((apName[0] == 102 && apName[1] == 120) ||
                   (apName[0] == 115 && apName[1] == 111 && apName[2] == 110 && apName[3] == 103)))
    {
        strcpy_s(acBuffer, 260, apName);
        strcpy_s(apName, 260, "data\\sound\\");
        strcat_s(apName, 260, acBuffer);
    }
}
