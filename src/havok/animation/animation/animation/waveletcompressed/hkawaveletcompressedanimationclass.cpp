#include "../../../../../../include/hkArray.h"

// src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimationclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimationclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"

struct DFB610Ostream
{
    __declspec(nothrow) DFB610Ostream& operator<<(const char* str);
};

struct DFB610ErrStream : DFB610Ostream
{
    int unk00;
    int unk04;
    int unk08;

    DFB610ErrStream(void* buf, int bufSize);
    void release();
};

struct DFB610Error
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual __declspec(nothrow) int message(int type, int id, const char* description, const char* file, int line);
};

extern DFB610Error* g_DFB610ErrorInstance;

struct DFB610QsTransform;
struct DFB610ChunkCache;

struct DFB610Animation
{
    void SamplePartialPose(float time, int maxNumTracks, DFB610QsTransform* transformOut, int maxNumFloatTracks,
                           float* floatTracksOut, DFB610ChunkCache* cache) const;
};

// Reports an assertion that samplePartialPose is not implemented for this animation type, then releases the error stream.
// @fnv 0x00dfb610
void DFB610Animation::SamplePartialPose(float time, int maxNumTracks, DFB610QsTransform* transformOut,
                                        int maxNumFloatTracks, float* floatTracksOut, DFB610ChunkCache* cache) const
{
    int assertBuf[128];
    DFB610ErrStream ostr(assertBuf, sizeof(assertBuf));
    ostr << "samplePartialPose not implemented for this type of animation";
    if (g_DFB610ErrorInstance->message(
            3, 0x54e32123, (const char*)assertBuf,
            "d:\\Projects\\fallout\\code\\Havok\\Source\\Animation/Animation/Animation/hkaAnimation.inl", 25))
        __debugbreak();
    ostr.release();
}

struct HkError
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Message(int aiKind, unsigned int auiId, const char* apText, const char* apFile, int aiLine);
};

extern HkError* g_01268360;

struct HkStringBuf
{
    char* m_pBuffer;
    int m_iCapacity;
    int m_iReferenceCount;
    HkStringBuf(char* apBuffer, unsigned int auiCapacity);
    void Append(const char* apText);
    void Release();
};

// Builds a fixed message about getDataChunks being unimplemented, reports it via g_01268360->Message and breaks if it returns nonzero.
// @fnv 0x00dfb670
void __stdcall ReportGetDataChunksNotImplemented(int a1, int a2, int a3, int a4)
{
    unsigned int auBuffer[128];
    HkStringBuf buf((char*)auBuffer, sizeof(auBuffer));
    buf.Append("getDataChunks not implemented for this type of animation");
    if (g_01268360->Message(
            3, 0x54e32124, (char*)auBuffer,
            "d:\\Projects\\fallout\\code\\Havok\\Source\\Animation/Animation/Animation/hkaAnimation.inl", 0x25))
        __debugbreak();
    buf.Release();
}

struct S_00dfb720_Allocator
{
    virtual ~S_00dfb720_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00dfb720_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00dfb720_Allocator* m_pStreamAllocator;
    S_00dfb720_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00dfb720_Router* hkMemoryRouter_getInstance();
template <class T> __forceinline void destruct(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}
template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
        { S_00dfb720_Allocator& alloc = hkMemoryRouter_getInstance()->heap();
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
     }
    
}
struct S_00dfb720_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~S_00dfb720_Elem() throw();
};
struct S_00dfb720_Ref
{
    void FUN_00c905b0();
};
template <class T> struct S_00dfb720_RefPtr
{
    T* m_pRetainedObject;
    __forceinline ~S_00dfb720_RefPtr() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};
struct S_00dfb720_Base
{
    virtual ~S_00dfb720_Base() throw()
    {}
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct __declspec(novtable) FUN_00dfb720 : S_00dfb720_Base
{
    S_00dfb720_RefPtr<S_00dfb720_Ref> m_ref;
    hkArray<S_00dfb720_Elem> m_ppData;
    virtual ~FUN_00dfb720() throw();
};
// Destructor of FUN_00dfb720; the body is empty, member destructors run implicitly.
// @fnv 0x00dfb720
FUN_00dfb720::~FUN_00dfb720() throw()
{}

namespace fnv_00dfb7e0 {
struct Callback
{
    virtual void V0();
    virtual void V1();
    virtual void Notify(void* owner, unsigned short value);
    virtual void V3();
    virtual void Release(void* buffer, unsigned int size);
};
struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Callback* callback;
};
Manager* hkMemoryRouter_getInstance();
struct Container
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    void* data1c;
    int count20;
    int state24;
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
    void FUN_00dfb720();
};
struct Record : Container
{
    void* data64;
    int unk68;
    int state6c;
    Record* ClearAndNotify(unsigned int flags);
};
// Releases data64 through the manager callback, resets state6c and unk68, calls FUN_00dfb720, and notifies the callback when flags bit 0 is set.
// @fnv 0x00dfb7e0
Record* Record::ClearAndNotify(unsigned int flags)
{
    Manager* manager = hkMemoryRouter_getInstance();
    Callback* callback = manager->callback;
    int size = state6c;
    unk68 = 0;
    if ((size >> 31) == 0)
        callback->Release(data64, size & 0x3fffffff);
    data64 = 0;
    state6c = 0x80000000;
    FUN_00dfb720();
    if (flags & 1)
    {
        manager = hkMemoryRouter_getInstance();
        manager->callback->Notify(this, *(unsigned short*)((char*)this + 4));
    }
    return this;
}
}  // namespace fnv_00dfb7e0

struct VirtualFloat
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual float Slot3(float, int);
};
struct FloatOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    VirtualFloat* unk18;
    float __thiscall hkaAnimation_getExtractedMotionReferenceFrame(float value, int mode);
};
// Forwards value and mode to the virtual Slot3 of the object at unk18 and returns its result.
// @fnv 0x00dfb6d0
// src: HAVOK_LIB 0x00dfb6d0
float __thiscall FloatOwner::hkaAnimation_getExtractedMotionReferenceFrame(float value, int mode)
{
    return unk18->Slot3(value, mode);
}

struct Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void V10(float afA, float afB, int aiC, int aiD);
};

struct FUN_00dfb6f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Sub* m_pSub;

    void ForwardToSub(float afA, float afB, int aiC, int aiD);
};

// Forwards the four arguments to the virtual V10 method of m_pSub.
// @fnv 0x00dfb6f0
void FUN_00dfb6f0_cls::ForwardToSub(float afA, float afB, int aiC, int aiD)
{
    m_pSub->V10(afA, afB, aiC, aiD);
}

namespace fnv_00dfb7b0 {
struct Allocator
{
    virtual void unknown00() = 0;
    virtual void unknown04() = 0;
    virtual void Release(void* object, unsigned int bytes) = 0;
};
BSAudio* hkMemoryRouter_getInstance();
struct Owner
{
    unsigned int unk00;
    unsigned short size4, unk06;
    void FUN_00dfb720();
    Owner* FUN_00dfb7b0(unsigned int flags);
};
// Calls FUN_00dfb720, and if flags has bit 0 set, releases this object via the BSAudio allocator using size4 bytes, then returns this.
// @fnv 0x00dfb7b0
Owner* Owner::FUN_00dfb7b0(unsigned int flags)
{
    FUN_00dfb720();
    if (flags & 1u)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        unsigned int bytes = size4;
        reinterpret_cast<Allocator*>(audio->pListener)->Release(this, bytes);
    }
    return this;
}
}  // namespace fnv_00dfb7b0
