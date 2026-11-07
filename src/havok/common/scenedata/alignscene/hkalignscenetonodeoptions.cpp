
// src/havok/common/scenedata/alignscene/hkalignscenetonodeoptions.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/alignscene/hkalignscenetonodeoptions.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkReferencedObject.h"

struct Inner
{
    void Run();
};

struct FUN_00e4a540_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Inner* m_14;
    void InvokeVirtualMethod_00e4a540();
};

// @fnv 0x00e4a540
// src: GUESS 0x00e4a540 (confidence: low)
void FUN_00e4a540_cls::InvokeVirtualMethod_00e4a540()
{
    m_14->Run();
}

// The TLS accessor at 0x00c85750 supplies the heap at +0x10; no include/hkMemoryRouter.h exists yet.
#include "../../../../../include/hkMemoryRouter.h"
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void Object_UpdateFields_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        Object_UpdateFields_00cb0c00();
    }
};



inline void hkReferencedObject::operator delete(void* p)
{
    hkMemoryRouter_getInstance().heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

// The reflected layout is 0x18 bytes; no include/ header exists for these options yet.
class hkAlignSceneToNodeOptions : public hkReferencedObject
{
  public:
    char m_bOption1;
    char m_bOption2;
    char m_bOption3;
    char m_bOption4;
    char m_bOption5;
    char m_bOption6;
    char m_bOption7;
    int m_iOptionValue;
    FUN_00cb0c00_class m_kNodeName;

    hkAlignSceneToNodeOptions* FUN_00e4afa0(unsigned int uiFlags) throw();
};

// Destroys the object and, when uiFlags has bit 0 set, frees its memory via operator delete; returns this.
// @fnv 0x00e4afa0
hkAlignSceneToNodeOptions* hkAlignSceneToNodeOptions::FUN_00e4afa0(unsigned int uiFlags) throw()
{
    this->hkAlignSceneToNodeOptions::~hkAlignSceneToNodeOptions();
    if (uiFlags & 1)
        hkAlignSceneToNodeOptions::operator delete(this);
    return this;
}

// Exe 0x00e4a5a0 FUN_00e4a5a0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps();
struct Vec4E4
{
    LocalM128 m_vComponents;
    __forceinline Vec4E4& operator=(const Vec4E4& v) throw()
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setZero4() throw()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline float& operator()(int i) throw()
    {
        return ((float*)&m_vComponents)[i];
    }
};
// local form of hkMatrix4: 0x00e4a5a0 needs inline setIdentity; shared out-of-line call cannot reproduce exe bytes.
struct Matrix4E4
{
    Vec4E4 m_kColumn0, m_kColumn1, m_kColumn2, m_kColumn3;
    __forceinline void setIdentity() throw()
    {
        Vec4E4 zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn3 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_kColumn3(3) = 1.0f;
    }
    void MultiplyInPlace(const Matrix4E4& m) throw();
};
struct MatArrE4
{
    Matrix4E4* m_data;
    int m_iElementCount;
    int m_cap;
};
struct PoseE4
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    MatArrE4 m_mats;
};
template <class T, int N> struct InplaceArrE4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];
    __forceinline InplaceArrE4() throw()
    {
        static_cast<T* volatile&>(m_data) = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = N | 0x80000000;
    }
    __forceinline int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_data[i];
    }
    __forceinline void release() throw()
    {
        hkMemoryAllocator& h = hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            h.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    __forceinline ~InplaceArrE4() throw()
    {
        release();
    }
};
struct NodeOpsE4
{
    int InvokeVirtualMethod_00e4a540(void* pSrc, InplaceArrE4<PoseE4*, 32>& arr) throw();
    int ProcessEntries_00e4a5a0(void* volatile pSrc, Matrix4E4* pOut, int iIndex);
};
// Initializes pOut, then passes one indexed matrix from each gathered pose to FUN_00de8e50; returns 1 when gathering returns nonzero.
// @fnv 0x00e4a5a0
// src: GUESS 0x00e4a5a0 (confidence: low)
int NodeOpsE4::ProcessEntries_00e4a5a0(void* volatile pSrc, Matrix4E4* pOut, int iIndex)
{
    InplaceArrE4<PoseE4*, 32> arr;
    void* source = pSrc;
    if (InvokeVirtualMethod_00e4a540(source, arr))
        return 1;
    pOut->setIdentity();
    for (int i = 0; i < arr.GetLogicalSize(); i++)
    {
        PoseE4* p = arr[i];
        int n = p->m_mats.m_iElementCount;
        int idx = (iIndex < n) ? iIndex : n - 1;
        pOut->MultiplyInPlace(p->m_mats.m_data[idx]);
    }
    return 0;
}
