
// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00ddfcd0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};
struct S_00ddfcd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddfcd0_Allocator* m_pStreamAllocator;
    S_00ddfcd0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddfcd0_Router* hkMemoryRouter_getInstance();
struct S_00ddfcd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00ddfcd0_RefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00ddfcd0_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddfcd0_RefObj* b = static_cast<S_00ddfcd0_RefObj*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00ddfcd0_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00ddfcd0_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00ddfcd0_Obj : S_00ddfcd0_RefObj
{
    S_00ddfcd0_Array m_ppData;
    S_00ddfcd0_Obj() throw()
    {}
    virtual ~S_00ddfcd0_Obj() throw();
};
S_00ddfcd0_RefObj* hkpUserShapeDisplayBuildercreate();

#include <xmmintrin.h>
struct __declspec(align(16)) Mat4
{
    float m[4][4];
};
struct XfResult
{
    int m_00;
    int m_04;
};
struct Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    __declspec(noinline) void resetX();
    void applyX(void* shape, Mat4* m, XfResult* r);
    void UpdateState_00de0f90(void* shape, XfResult* result);
};
__declspec(noinline) void Node::resetX()
{
    unk10 = 0;
}
// @fnv 0x00de0f90
// src: GUESS 0x00de0f90 (confidence: low)
void Node::UpdateState_00de0f90(void* shape, XfResult* result)
{
    Mat4 t;
    _mm_store_ps(t.m[0], _mm_setzero_ps());
    t.m[0][0] = 1.0f;
    _mm_store_ps(t.m[1], _mm_setzero_ps());
    t.m[1][1] = 1.0f;
    _mm_store_ps(t.m[2], _mm_setzero_ps());
    t.m[2][2] = 1.0f;
    _mm_store_ps(t.m[3], _mm_setzero_ps());
    resetX();
    result->m_04 = 0;
    applyX(shape, &t, result);
}
