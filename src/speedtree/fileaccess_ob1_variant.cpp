#include "../../include/CVec3.h"

// src/speedtree/fileaccess_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/fileaccess.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
struct FUN_00b3ef80_shell
{
    int m_iValueAt00;
    void* m_pObjectAt04;
    float CTreeFileAccess_ParseFloat();
    CVec3 GetVector3();
};
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
    CVec3 m_vec1;
    CVec3 m_vec2;
    CVec3 m_vec3;
    unsigned char m_unk40;
    float m_f44;
    int m_i48;

    FUN_00b40150_cls();
};

struct Alloc_00b3ee40
{
    Alloc_00b3ee40()
    {}
};
extern unsigned int DAT_010173f0;
struct Str_00b3ee40
{
    int f00;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int mysize;
    unsigned int myres;
    Str_00b3ee40()
    {
        int k;
        Alloc_00b3ee40 c;
        Alloc_00b3ee40* pal = &c;
        int j, o, e, t, f7;
        fopen_0044a730(false, 0);
    }
    Str_00b3ee40(const Str_00b3ee40& rhs)
    {
        int k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16;
        fopen_0044a730(false, 0);
        AssignSubstring(rhs, 0, DAT_010173f0);
    }
    ~Str_00b3ee40()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool, unsigned int);
    Str_00b3ee40& AssignSubstring(const Str_00b3ee40&, unsigned int, unsigned int);
    Str_00b3ee40& AppendChars(unsigned int, char);
    Str_00b3ee40& operator+=(char ch)
    {
        int k;
        char c;
        return AppendChars(1, ch);
    }
};
struct Buf_00b3ee40
{
    int f00;
    int f04;
    int f08;
    char* first;
    char* last;
    unsigned int size() const
    {
        return last - first;
    }
    char& at(unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return first[i];
    }
};
// SpeedTree string input: cursor +0, byte buffer +4; GetNextElement binds to the 32-bit read at 0x00b3ed80.
struct SpeedTreeFileInput
{
    unsigned int pos;
    Buf_00b3ee40 buf;
    int GetNextElement();
    Str_00b3ee40 CTreeFileAccess_ParseString();
};
// @fnv 0x00b3ee40
// src: COMMUNITY 0x00b3ee40
Str_00b3ee40 SpeedTreeFileInput::CTreeFileAccess_ParseString()
{
    Str_00b3ee40 s;
    int count4 = GetNextElement();
    for (int i3 = 0; i3 < count4; i3++)
    {
        s += buf.at(pos++);
    }
    return s;
}
