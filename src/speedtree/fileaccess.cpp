#include "../../include/CVec3.h"

// src/speedtree/fileaccess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/fileaccess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b3ede0_shell
{
    void* p;
    void* next;
    void* prev;
    unsigned int used;
    unsigned int size;
    void* AdvanceBlockAllocationCursor();
};

unsigned int __cdecl FUN_00ec7c56(void);

// Checks the block has room for alloc bytes, calls FUN_00ec7c56 if not, advances p twice and returns the pointer at used+alloc.
// @fnv 0x00b3ede0
// src: GUESS 0x00b3ede0 (confidence: medium)
void* FUN_00b3ede0_shell::AdvanceBlockAllocationCursor()
{
    unsigned int alloc = *(unsigned int*)this;
    FUN_00b3ede0_shell* block = (FUN_00b3ede0_shell*)((char*)this + 4);
    if (alloc >= (block->size - block->used))
        FUN_00ec7c56();
    void* result = (void*)((unsigned int)block->used + alloc);
    p = (void*)((unsigned int)p + 4);
    p = (void*)((unsigned int)p + 4);
    return *(void**)result;
}

struct FUN_00b3ef80_shell
{
    int m_iValueAt00;
    void* m_pObjectAt04;
    float CTreeFileAccess_ParseFloat();
    CVec3 GetVector3();
};

// Builds a 3-component vector by calling FUN_00b3ed20 once per component and returns it.
// @fnv 0x00b3ef80
CVec3 FUN_00b3ef80_shell::GetVector3()
{
    // Preserve explicit initialization without calling the shared default constructor.
    float vecResult[sizeof(CVec3) / sizeof(float)];
    int iComponent;
    vecResult[2] = 0.0f;
    vecResult[1] = 0.0f;
    vecResult[0] = 0.0f;
    for (iComponent = 0; iComponent < 3; iComponent++)
        vecResult[iComponent] = CTreeFileAccess_ParseFloat();
    return *reinterpret_cast<CVec3*>(vecResult);
}

struct FUN_00b3ed20_range
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uBase;
    unsigned int m_uEnd;
};

unsigned int __cdecl FUN_00ec7c56(void);

struct FUN_00b3ed20_cls
{
    unsigned int m_nCursor;
    FUN_00b3ed20_range m_range;
    float CTreeFileAccess_ParseFloat();
};

// @fnv 0x00b3ed20
// src: COMMUNITY 0x00b3ed20
float FUN_00b3ed20_cls::CTreeFileAccess_ParseFloat()
{
    unsigned int idx = m_nCursor;
    FUN_00b3ed20_range* p2 = &m_range;
    if (idx >= p2->m_uEnd - p2->m_uBase)
    {
        FUN_00ec7c56();
    }
    float* ptr = (float*)(p2->m_uBase + idx);
    m_nCursor = m_nCursor + 4;
    return *ptr;
}

// Stand-in for the element array the object points at.
struct S_00b3ed80_Array
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_pData;       // +0x0c  first element
    void* m_pRecordEnd;  // +0x10  one past the last element
};

struct S_00b3ed80
{
    unsigned int m_nOffset;     // +0x00  byte offset of the next element
    S_00b3ed80_Array m_ppData;  // +0x04
    void* GetNextElement();
};

// Returns the element at m_nOffset in the array, advances m_nOffset by 4, and calls FUN_00ec7c56 if the offset is out of bounds.
// @fnv 0x00b3ed80
void* S_00b3ed80::GetNextElement()
{
    unsigned int offset = m_nOffset;
    S_00b3ed80_Array* pArray = &m_ppData;
    if (offset >= (unsigned int)((char*)pArray->m_pRecordEnd - (char*)pArray->m_pData))
        FUN_00ec7c56();
    void** element = (void**)((char*)pArray->m_pData + offset);
    m_nOffset = m_nOffset + 4;
    return *element;
}

// Constructor of an object whose base class constructor lives in another unit.

struct FUN_00b40150_base
{
    virtual void vBaseSlot();
    FUN_00b40150_base();
};

struct FUN_00b40150_cls : public FUN_00b40150_base
{
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    unsigned char m_unk10;
    int m_i14;
    unsigned char m_unk18;
    // These vectors are initialized explicitly in the constructor body.
    float m_vec1[sizeof(CVec3) / sizeof(float)];
    float m_vec2[sizeof(CVec3) / sizeof(float)];
    float m_vec3[sizeof(CVec3) / sizeof(float)];
    unsigned char m_unk40;
    float m_f44;
    int m_i48;

    FUN_00b40150_cls();
};

// @fnv 0x00b40150
FUN_00b40150_cls::FUN_00b40150_cls()
{
    m_unk10 = 0;
    m_i14 = -1;
    m_unk18 = 0;

    CVec3* v1 = reinterpret_cast<CVec3*>(m_vec1);
    v1->z = 0.0f;
    v1->y = 0.0f;
    v1->x = 0.0f;

    CVec3* v2 = reinterpret_cast<CVec3*>(m_vec2);
    v2->z = 0.0f;
    v2->y = 0.0f;
    v2->x = 0.0f;

    CVec3* v5 = reinterpret_cast<CVec3*>(m_vec3);
    v5->z = 0.0f;
    v5->y = 0.0f;
    v5->x = 0.0f;

    m_unk40 = 0;
    m_f44 = 0.0f;
    m_i48 = 0;
}
