
// src/speedtree/speedtreert.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/speedtreert.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/MemoryManager.h"
#include "../../include/CVec3.h"

struct FUN_00b02e00_class
{
    void UpdateFields_00b02e00();
};

// @fnv 0x00b02e00
// src: GUESS 0x00b02e00 (confidence: low)
void FUN_00b02e00_class::UpdateFields_00b02e00()
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
}

struct FUN_00b2bcf0_shell
{
    void CTreeEngine_GetSize(float*, float*);
    void CSpeedTreeRT_GetTreeSize(float* a, float* b);
};

// @fnv 0x00b06260
// src: COMMUNITY 0x00b06260
void FUN_00b2bcf0_shell::CSpeedTreeRT_GetTreeSize(float* pfA, float* pfB)
{
    ((FUN_00b2bcf0_shell*)*(int*)this)->CTreeEngine_GetSize(pfA, pfB);
}

struct FUN_00b071c0_Class
{
    void __thiscall SetField14(int param);
};

// Stores the low byte of param at offset 0x14 of the object pointed to by the pointer at this+0x10.
// @fnv 0x00b071c0
void __thiscall FUN_00b071c0_Class::SetField14(int aiValue)
{
    int* p = *(int**)((char*)this + 0x10);
    *(char*)((char*)p + 0x14) = (char)aiValue;
}

struct FUN_00b07390_class
{
    void* m_p;
    void SetField9C(float f);
};

// If m_p is non-null, writes the float f to the field at offset 0x9c of the object pointed to by m_p.
// @fnv 0x00b07390
void FUN_00b07390_class::SetField9C(float afValue)
{
    if (!m_p)
        return;
    *(float*)((char*)m_p + 0x9c) = afValue;
}

struct FUN_00b073c0_class
{
    void* m_p;
    void SetField98(float f);
};

// If m_p is non-null, stores f at offset 0x98 of the object pointed to by m_p.
// @fnv 0x00b073c0
void FUN_00b073c0_class::SetField98(float afValue)
{
    if (!m_p)
        return;
    *(float*)((char*)m_p + 0x98) = afValue;
}

struct FUN_00b07490
{
    void* m_p;
    void Set(float f);
};
// If m_p is non-null, writes f to the float at offset 0xcc of m_p.
// @fnv 0x00b07490
void FUN_00b07490::Set(float afValue)
{
    if (!m_p)
        return;
    *(float*)((char*)m_p + 0xcc) = afValue;
}

struct FUN_00b074c0_class
{
    void* m_p;  // +0x0
    void SetFieldD0(float f);
};

// If m_p is non-null, stores f at offset 0xd0 of the object pointed to by m_p.
// @fnv 0x00b074c0
void FUN_00b074c0_class::SetFieldD0(float afValue)
{
    if (!m_p)
        return;
    *(float*)((char*)m_p + 0xd0) = afValue;
}

struct FUN_00b074f0_obj
{
    void* GetNestedPointer();
};
// @fnv 0x00b074f0
void* FUN_00b074f0_obj::GetNestedPointer()
{
    void* p = *(void**)((char*)*(void**)((char*)this + 0x10) + 0x10);
    return p;
}

struct FUN_00b076c0_Class
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    void* m20;
    void* m24;
    void* m28;
    void* m2c;
    void* m30;
    void* m34;
    void* m38;
    void* m3c;
    void* m40;
    void* m44;
    void* m48;
    void* m4c;
    void* m50;
    void* m54;
    void* m58;
    void* m5c;
    void* m60;
    void* m64;
    void* m68;
    void* m6c;
    void* m70;
    void* m74;
    void* m78;
    void* m7c;
    void* m80;
    void* m84;
    void* m88;
    void* m8c;
    void* m90;
    void* m94;
    void* m98;
    void* m9c;
    void* ma0;
    void* ma4;
    void* ma8;
    void* mac;
    void* mb0;
    void* mb4;
    void* mb8;
    void* mbc;
    void* mc0;
    void* mc4;
    void* mc8;
    void* mcc;
    void* md0;
    void* md4;
    void* md8;
    void* mdc;
    void* me0;
    void* me4;
    void* me8;
    void* mec;
    void* mf0;
    void* mf4;
    void* mf8;
    void* mfc;
    void* fun_00b076c0();
};

// @fnv 0x00b076c0
void* FUN_00b076c0_Class::fun_00b076c0()
{
    void* result = *(void**)((char*)m10 + 8);
    return result;
}

struct FUN_00b078e0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* GetFieldAt0C();
};

// @fnv 0x00b078e0
void* FUN_00b078e0_Class::GetFieldAt0C()
{
    void* result = *(void**)((char*)m_10 + 0xc);
    return result;
}

struct FUN_00b2bdc0_shell
{
    void UpdateFields_00b2bdc0(float, float);
};

struct FUN_00b08500_shell
{
    void CSpeedTreeRT_SetNearFarDists(float a, float b);
};

// Forwards the two float arguments to the object pointed to by the first member of this object.
// @fnv 0x00b08500
// src: COMMUNITY 0x00b08500
void __thiscall FUN_00b08500_shell::CSpeedTreeRT_SetNearFarDists(float afValue, float afOther)
{
    ((FUN_00b2bdc0_shell*)*reinterpret_cast<int*>(this))->UpdateFields_00b2bdc0(afValue, afOther);
}

struct FUN_00b086f0_class
{
    unsigned short __thiscall GetLowWordAtOffset0x78();
};
// @fnv 0x00b086f0
unsigned short __thiscall FUN_00b086f0_class::GetLowWordAtOffset0x78()
{
    int v;
    v = *reinterpret_cast<int*>(reinterpret_cast<char*>(*reinterpret_cast<int*>(this)) + 0x78);
    return *reinterpret_cast<unsigned short*>(&v);
}

struct CSpeedTreeRT
{
    void* m_pFirstPointer;
    unsigned short GetNumLeafLodLevels();
};
// @fnv 0x00b08710
// src: XBOX_PDB 0x00b08710
unsigned short CSpeedTreeRT::GetNumLeafLodLevels()
{
    unsigned int v = *(unsigned int*)((char*)m_pFirstPointer + 0xd8);
    return (unsigned short)v;
}

namespace fnv_00b08730 {
struct CSpeedTreeRT
{
    unsigned short m_usId;
    unsigned short GetId();
};

// @fnv 0x00b08730
unsigned short CSpeedTreeRT::GetId()
{
    return ((unsigned short*)((char*)this + 0x64))[0];
}
}  // namespace fnv_00b08730

namespace fnv_00b088b0 {
struct SpeedTreeLodData
{
    void __thiscall FreeLodBuffers();
};
struct CSpeedTreeRT
{
    int m_p0;
    int m_p4;
    SpeedTreeLodData* m_pLodData;
    void __thiscall FreeLeafLODDataArrays();
};
// @fnv 0x00b088b0
// src: COMMUNITY 0x00b088b0
void __thiscall CSpeedTreeRT::FreeLeafLODDataArrays()
{
    if (m_pLodData)
        m_pLodData->FreeLodBuffers();
}
}  // namespace fnv_00b088b0

struct FUN_00b0d5d0_Class
{
    int m_unk_00;
    int m_unk_04;
    int m_unk_08;
    int m_unk_0c;
    int m_unk_10;
    int m_unk_14;
    int m_unk_18;
    int m_unk_1c;
    int m_unk_20;
    int m_unk_24;
    int m_unk_28;
    int m_unk_2c;
    int m_unk_30;
    int m_unk_34;
    int m_unk_38;
    int m_unk_3c;
    int m_unk_40;
    int m_unk_44;
    int m_unk_48;
    int m_unk_4c;
    int m_unk_50;
    int m_unk_54;
    int m_unk_58;
    int m_unk_5c;
    int m_unk_60;
    int m_unk_64;
    int m_unk_68;
    int GetUnk68();
};

// @fnv 0x00b0d5d0
int FUN_00b0d5d0_Class::GetUnk68()
{
    return m_unk_68;
}

struct FUN_00b051e0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* CSpeedTreeRT_InstanceOf();
};

// Returns the pointer stored at the object referenced by m_34, or null if m_34 is null.
// @fnv 0x00b051e0
// src: COMMUNITY 0x00b051e0
void* FUN_00b051e0_class::CSpeedTreeRT_InstanceOf()
{
    void* result = 0;
    if (m_34)
        result = *(void**)m_34;
    return result;
}

struct FUN_0065f2b0_class
{
    void std_vector_float_std_allocator_float_Destroy(int, int);
};
struct FUN_0064df10_helper
{
    void deallocate(void*, unsigned int);
};
struct FUN_00657f60_class
{
    int a;
    int b;
    int c;
    void* d;
    void* e;
    void* f;
    void ReleaseStorage_00657f60();
};
// Frees the buffer at d via FUN_0065f2b0 and deallocate, then clears d, e and f.
// @fnv 0x00657f60
// src: GUESS 0x00657f60 (confidence: medium)
void FUN_00657f60_class::ReleaseStorage_00657f60()
{
    if (d)
    {
        ((FUN_0065f2b0_class*)this)->std_vector_float_std_allocator_float_Destroy((int)d, (int)e);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate(d, (unsigned int)((char*)f - (char*)d));
    }
    d = 0;
    e = 0;
    f = 0;
}

struct FUN_00b02e20
{
    void* p0;
    void* p4;
    void* p8;
    void* pc;
    void* p10;
    void* p14;
    void* p18;
    FUN_00b02e20();
};
// Initializes all seven pointer fields of the object to null.
// @fnv 0x00b02e20
FUN_00b02e20::FUN_00b02e20()
{
    p0 = 0;
    p4 = 0;
    p8 = 0;
    pc = 0;
    p10 = 0;
    p14 = 0;
    p18 = 0;
}

struct GlobalObject_00b3f100
{
    char data[0x18];
    ~GlobalObject_00b3f100();
};

struct FUN_00b050d0_class
{
    GlobalObject_00b3f100 a;
    GlobalObject_00b3f100 b;
    ~FUN_00b050d0_class();
};

// Destructor for a class holding two GlobalObject_00b3f100 members; the body is empty.
// @fnv 0x00b050d0
FUN_00b050d0_class::~FUN_00b050d0_class()
{}

struct FUN_00b08440_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    float CSpeedTreeRT_GetLodLevel();
};

// @fnv 0x00b08440
// src: XBOX_PDB 0x00b08440
float FUN_00b08440_shell::CSpeedTreeRT_GetLodLevel()
{
    float fLevel = -1.0f;
    if (m_34)
    {
        fLevel = *(float*)((char*)m_34 + 0x10);
    }
    else
    {
        fLevel = *(float*)((char*)m_00 + 0x14);
    }
    return fLevel;
}

extern unsigned char DAT_011f8b78;

// @fnv 0x00b084f0
// src: COMMUNITY 0x00b084f0
void CSpeedTreeRT_SetDropToBillboard(unsigned char param_1)
{
    DAT_011f8b78 = param_1;
}

void __cdecl _memmove(void* dst, const void* src, unsigned int size);
void __cdecl AssignString(const char* s);

struct CSpeedTreeRT_GetBoundingBox
{
    void __thiscall CSpeedTreeRT_GetBoundingBox_00b08c80(float* dst);
};

// @fnv 0x00b08c80
// src: XBOX_PDB 0x00b08c80
void __thiscall CSpeedTreeRT_GetBoundingBox::CSpeedTreeRT_GetBoundingBox_00b08c80(float* afBounds)
{
    if (afBounds)
    {
        void* src = *(void**)((char*)this + 0x40);
        _memmove(afBounds, src, 0x18);
    }
    else
    {
        AssignString("GetBoundingBox() expects a non-NULL parameter");
    }
}

struct FUN_00b0a260_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    int __thiscall GetEntryCount();
};
// @fnv 0x00b0a260
int __thiscall FUN_00b0a260_Class::GetEntryCount()
{
    int result = 0;
    if (m_58)
    {
        void* p = m_58;
        result = (((int*)p)[4] - ((int*)p)[3]) / 28;
    }
    return result;
}

extern unsigned char DAT_011f8b79;

// @fnv 0x00b0d7b0
// src: COMMUNITY 0x00b0d7b0
void CSpeedTreeRT_SetFlipTextures(unsigned char param_1)
{
    DAT_011f8b79 = param_1;
}

struct FUN_00b02b70_shell
{
    int m_iWordAt00;
    unsigned short m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    unsigned short m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    FUN_00b02b70_shell();
};
// Initializes all fields of the object: sets the first int to -1 and every other field to 0.
// @fnv 0x00b02b70
FUN_00b02b70_shell::FUN_00b02b70_shell()
{
    m_iWordAt00 = -1;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
}

struct FUN_00b02c10_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void ClearPointers();
};
// @fnv 0x00b02c10
void FUN_00b02c10_class::ClearPointers()
{
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

struct FUN_00b02c90_class
{
    char m_iWordAt00;
    float m_iWordAt04;
    int m_8;
    unsigned short m_iThirdValue;
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
    FUN_00b02c90_class();
};
// Initializes all members: sets the char and short to 0, the float to -1.0f, and the remaining int fields to 0 or -1.
// @fnv 0x00b02c90
FUN_00b02c90_class::FUN_00b02c90_class()
{
    m_iWordAt00 = 0;
    m_iWordAt04 = -1.0f;
    m_8 = -1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
}

struct FUN_00b02d40_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void __thiscall ClearFields();
};

// Sets eleven pointer fields of the object (m_10 through m_38) to null.
// @fnv 0x00b02d40
void __thiscall FUN_00b02d40_class::ClearFields()
{
    m_10 = 0;
    m_14 = 0;
    m_18 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    m_30 = 0;
    m_1c = 0;
    m_20 = 0;
    m_34 = 0;
    m_38 = 0;
}

extern MemoryManager g_memoryManager;
struct FUN_00b02e80
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    int m14;
    int m18;
    ~FUN_00b02e80();
};
// Frees the buffers at m08 and m10 via g_memoryManager and clears m00, m08, m10, m14 and m18.
// @fnv 0x00b02e80
FUN_00b02e80::~FUN_00b02e80()
{
    void* p4 = m08;
    g_memoryManager.Deallocate(p4);
    m08 = 0;
    void* p2 = m10;
    g_memoryManager.Deallocate(p2);
    m10 = 0;
    m00 = 0;
    m14 = 0;
    m18 = 0;
}

extern int DAT_011f8e9c;
extern int DAT_011f8ea0;
extern int DAT_011f8ea4;
extern int DAT_011f8eac;
extern int DAT_011f8eb0;
extern int DAT_011f8eb4;
// Copies the global camera position and direction into the two output vectors, or reports an error if either pointer is NULL.
// @fnv 0x00b06b70
// src: XBOX_PDB 0x00b06b70
void __cdecl CSpeedTreeRT_GetCamera(float* pPosition, float* pDirection)
{
    if (pPosition && pDirection)
    {
        // These temporaries are filled explicitly, without calling CVec3 constructors.
        float cCameraPos[sizeof(CVec3) / sizeof(float)];
        float cCameraDirection[sizeof(CVec3) / sizeof(float)];
        reinterpret_cast<CVec3*>(cCameraPos)->z = 0.0f;
        reinterpret_cast<CVec3*>(cCameraPos)->y = 0.0f;
        reinterpret_cast<CVec3*>(cCameraPos)->x = 0.0f;
        reinterpret_cast<CVec3*>(cCameraDirection)->z = 0.0f;
        reinterpret_cast<CVec3*>(cCameraDirection)->y = 0.0f;
        reinterpret_cast<CVec3*>(cCameraDirection)->x = 0.0f;
        *(int*)&reinterpret_cast<CVec3*>(cCameraPos)->x = DAT_011f8e9c;
        *(int*)&reinterpret_cast<CVec3*>(cCameraPos)->y = DAT_011f8ea0;
        *(int*)&reinterpret_cast<CVec3*>(cCameraPos)->z = DAT_011f8ea4;
        *(int*)&reinterpret_cast<CVec3*>(cCameraDirection)->x = DAT_011f8eac;
        *(int*)&reinterpret_cast<CVec3*>(cCameraDirection)->y = DAT_011f8eb0;
        *(int*)&reinterpret_cast<CVec3*>(cCameraDirection)->z = DAT_011f8eb4;
        _memmove(pPosition, &cCameraPos, 0xc);
        _memmove(pDirection, &cCameraDirection, 0xc);
    }
    else
    {
        AssignString("GetCamera() requires non-NULL position and direction values");
    }
}

struct FUN_00b08480_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void CSpeedTreeRT_SetLodLevel(float f);
};
// @fnv 0x00b08480
// src: XBOX_PDB 0x00b08480
void FUN_00b08480_shell::CSpeedTreeRT_SetLodLevel(float afLevel)
{
    if (afLevel >= 0.0 && afLevel <= 1.0)
    {
        if (m_34)
        {
            *(float*)((char*)m_34 + 0x10) = afLevel;
        }
        else
        {
            void* p = m_iWordAt00;
            *(float*)((char*)p + 0x14) = afLevel;
        }
    }
    else
    {
        AssignString("SetLodLevel() expects a value in the range of 0.0 to 1.0");
    }
}

struct FUN_00b02dc0_class
{
    char m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    float m_iThirdValue;
    unsigned short m_10;
    FUN_00b02dc0_class();
};
// Initializes the object's fields to zero, with the float field set to -1.0f.
// @fnv 0x00b02dc0
FUN_00b02dc0_class::FUN_00b02dc0_class()
{
    m_iWordAt00 = 0;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = -1.0f;
    m_10 = 0;
}

struct FUN_00b2b940_class
{
    unsigned char m_bFlag;  // +0x21
    void FUN_00b2b940();
};
struct FUN_00b053e0_shell
{
    void CSpeedTreeRT_DeleteTransientData();
};

// @fnv 0x00b053e0
// src: XBOX_PDB 0x00b053e0
void FUN_00b053e0_shell::CSpeedTreeRT_DeleteTransientData()
{
    unsigned char bFlag = ((unsigned char*)*(void**)((char*)this))[0x21];
    if (bFlag)
        ((FUN_00b2b940_class*)*(void**)((char*)this))->FUN_00b2b940();
    else
        AssignString("DeleteTransientData() called with no intact transient data");
}

struct FUN_00b073f0_class
{
    void* m_p;  // +0x0
    float GetNestedFloatOrZero();
};

// Returns the float at offset 0x18 of the object at m_p+0x5c, or 0.0 if m_p or that object is null.
// @fnv 0x00b073f0
// src: GUESS 0x00b073f0 (confidence: medium)
float FUN_00b073f0_class::GetNestedFloatOrZero()
{
    if (m_p != 0)
    {
        void* a = *(void**)((char*)m_p + 0x5c);
        if (a != 0)
        {
            void* b9 = *(void**)((char*)m_p + 0x5c);
            float f = *(float*)((char*)b9 + 0x18);
            return f;
        }
    }
    return 0.0f;
}

struct FUN_00b07440_Class
{
    void* m_p;
    float __thiscall GetNestedFloatOrZero_00b07440();
};

// Returns the float at offset 0x1c of the object stored at m_p+0x5c, or 0.0f if m_p or that pointer is null.
// @fnv 0x00b07440
// src: GUESS 0x00b07440 (confidence: low)
float __thiscall FUN_00b07440_Class::GetNestedFloatOrZero_00b07440()
{
    if (m_p)
    {
        void* p = *(void**)((char*)m_p + 0x5c);
        if (p)
        {
            void* RunSeventhVirtualOperation = *(void**)((char*)m_p + 0x5c);
            float f = *(float*)((char*)RunSeventhVirtualOperation + 0x1c);
            return f;
        }
    }
    return 0.0f;
}

namespace std {
template <class _CharT> struct char_traits
{
};

template <class _CharT> struct allocator
{
};

template <class _CharT, class _Traits, class _Alloc> class basic_string
{
  public:
    void __thiscall _Tidy(bool, unsigned int);
};
}

struct FUN_0044d6f0_This
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void __thiscall FUN_00ec79a1();
};

extern int DAT_010a307c;

struct FUN_00b09780_class : FUN_0044d6f0_This
{
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_iThirdValue;

    void __thiscall UpdateFields_00b09780();
};

// @fnv 0x00b09780
// src: GUESS 0x00b09780 (confidence: low)
void FUN_00b09780_class::UpdateFields_00b09780()
{
    char local[16];

    m_iWordAt00 = &DAT_010a307c;
    m_iThirdValue._Tidy(true, 0);
    FUN_0044d6f0_This::FUN_00ec79a1();
}

extern int DAT_010a51e0;

struct FUN_00b097b0_class
{
    void* m_p;
    char pad[0x60];
    void FUN_00aca270(int a);
    int* IdvFileError_IdvFileError(int a);
};

// Calls FUN_00aca270 with a, sets m_p to the address of DAT_010a51e0, and returns this as an int pointer.
// @fnv 0x00b097b0
// src: EXE 0x00b097b0
int* FUN_00b097b0_class::IdvFileError_IdvFileError(int a)
{
    char pad[0x58];
    FUN_00aca270(a);
    m_p = &DAT_010a51e0;
    return (int*)this;
}

struct FUN_00b09f70_Class
{
    void ProcessState_00b09f70();
    void _Tidy(bool, unsigned int);
};
// @fnv 0x00b09f70
// src: GUESS 0x00b09f70 (confidence: low)
void FUN_00b09f70_Class::ProcessState_00b09f70()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    _Tidy(true, 0);
}

extern MemoryManager _g_memoryManager;
unsigned int _strlen(const char* s);

// Allocates nLength4 + 1 bytes from _g_memoryManager, copies pOrig into the new buffer with _memmove, and returns the copy.
// @fnv 0x00b0d7c0
char* DuplicateString(const char* pOrig)
{
    unsigned int nLength4 = _strlen(pOrig);
    char* pResult = static_cast<char*>(_g_memoryManager.Allocate(nLength4 + 1));
    char* pCopy = pResult;
    _memmove(pCopy, pOrig, nLength4 + 1);
    return pCopy;
}

extern unsigned char DAT_011f8b79;

// @fnv 0x00b0d7a0
// src: COMMUNITY 0x00b0d7a0
unsigned char __cdecl CSpeedTreeRT_GetTextureFlip()
{
    return DAT_011f8b79;
}

struct BoundingBlock
{
    FUN_00b02c10_class contained;
    int extra38;
    __forceinline ~BoundingBlock()
    {
        contained.ClearPointers();
    }
};
struct BranchBlock
{
    FUN_00b02d40_class contained;
    __forceinline ~BranchBlock()
    {
        contained.ClearFields();
    }
};
struct LeafBlock
{
    FUN_00b02e00_class contained;
    int extra04, extra08, extra0c, extra10;
    __forceinline ~LeafBlock()
    {
        contained.UpdateFields_00b02e00();
    }
};
struct FUN_00b02ac0
{
    BoundingBlock root;
    BoundingBlock bounds;
    BranchBlock limbA;
    BranchBlock limbB;
    LeafBlock leafA;
    LeafBlock leafB;
    LeafBlock leafC;
    ~FUN_00b02ac0();
};
// @fnv 0x00b02ac0
FUN_00b02ac0::~FUN_00b02ac0()
{}

extern double _DAT_0101a6b0;
struct FUN_00b08610_shell
{
    unsigned short __thiscall CSpeedTreeRT_GetDiscreteLeafLodLevel(float fLodLevel);
};
// Maps a LOD fraction to a discrete level index using the LOD level count, clamping the top value down by one.
// @fnv 0x00b08610
// src: COMMUNITY 0x00b08610
unsigned short FUN_00b08610_shell::CSpeedTreeRT_GetDiscreteLeafLodLevel(float fLodLevel)
{
    unsigned short nLevel = 0;
    if (fLodLevel == _DAT_0101a6b0)
    {
        fLodLevel = ((FUN_00b08440_shell*)this)->CSpeedTreeRT_GetLodLevel();
    }
    if (DAT_011f8b78)
    {
        int nNumLodLevels = ((CSpeedTreeRT*)this)->GetNumLeafLodLevels() + 1;
        nLevel = (unsigned short)((1.0f - fLodLevel) * nNumLodLevels);
        if (nLevel == nNumLodLevels)
        {
            nLevel--;
        }
    }
    else
    {
        int nNumLodLevels = ((CSpeedTreeRT*)this)->GetNumLeafLodLevels();
        nLevel = (unsigned short)((1.0f - fLodLevel) * nNumLodLevels);
        if (nLevel == nNumLodLevels)
        {
            nLevel--;
        }
    }
    return nLevel;
}

struct std_string
{
    void assign(const char*, unsigned int);
};
extern std_string DAT_011f8ba4;
unsigned int _strlen(const char*);

// Computes the length of s and assigns that many characters from s into DAT_011f8ba4.
// @fnv 0x00b09270
void __cdecl AssignString(const char* pcString)
{
    char buf[0x40];
    unsigned int len = _strlen(pcString);
    DAT_011f8ba4.assign(pcString, len);
}

extern unsigned char DAT_011f8b78;
void __cdecl AssignString(const char* s);
void __cdecl CSpeedTreeRT_GetTransitionValues(float a, unsigned short n, float b, float c, float d, float e, float* pf1, float* pf2,
                          short* ps1, short* ps2);

struct FUN_00b0b920_geo
{
    char m_00[0xc];
    float* m_0c;
    float* m_10;
};

struct FUN_00b0b920_engine
{
    char m_00[0x88];
    FUN_00b0b920_geo m_geo;
    int FUN_00b4b0();
    int FUN_00b530();
    int FUN_00b5b0();
    int FUN_00b630();
    int FUN_00b6b0();
    int FUN_00b730();
    int FUN_00b7b0();
    int FUN_00b830();
    int FUN_00b8b0();
    unsigned short CIndexedGeometry_GetNumStrips(unsigned short i);
    int CIndexedGeometry_GetStripLengthsPointer(unsigned short i);
    int CIndexedGeometry_GetStripsPointer(unsigned short i);
};

struct FUN_00b0b920_arg
{
    char m_00[0x3c];
    FUN_00b02b70_shell m_sub;
    float m_74;
};

struct FUN_00b0b920_self
{
    char m_00[0x1c];
    float m_1c;
    float m_20;
    int m_24;
    float m_28;
    char m_2c[0x18];
    unsigned char m_44;
    char m_45[0x1b];
    FUN_00b0b920_engine* m_60;
    unsigned short GetNumLeafLodLevels();
    short CSpeedTreeRT_GetDiscreteFrondLodLevel(float f);
    float CSpeedTreeRT_GetLodLevel();
    void FillFrondGeometry(FUN_00b0b920_arg* arg, short type);
};

// Copies frond geometry counts and indices from m_60 into arg->m_sub, resolves the type, and computes arg->m_74 from FUN_00b0c8d0 when DAT_011f8b78 is set.
// @fnv 0x00b0b920
void FUN_00b0b920_self::FillFrondGeometry(FUN_00b0b920_arg* arg, short type)
{
    if (m_60)
    {
        FUN_00b02b70_shell* beg = &arg->m_sub;
        FUN_00b0b920_geo* q = &m_60->m_geo;
        unsigned short n;
        float aj;
        float idx;
        short num;
        short cnt;
        int ae, av, bg, ak, au, ba, bl, ac, bd, bv, cu, bq, ce, co, cy, bi, bj, bm, ap, at, by, ai, al, bs, bu, cb, cl;
        beg->m_10 = (unsigned short)((unsigned int)(q->m_10 - q->m_0c) / 3);
        beg->m_14 = m_60->FUN_00b4b0();
        beg->m_24 = m_60->FUN_00b530();
        beg->m_18 = m_60->FUN_00b5b0();
        beg->m_1c = m_60->FUN_00b630();
        beg->m_20 = m_60->FUN_00b6b0();
        beg->m_28 = m_60->FUN_00b730();
        beg->m_2c = m_60->FUN_00b7b0();
        beg->m_30 = m_60->FUN_00b830();
        beg->m_34 = m_60->FUN_00b8b0();
        short w = (type == -1) ? CSpeedTreeRT_GetDiscreteFrondLodLevel(-1.0f) : type;
        beg->m_iWordAt00 = w;
        beg->m_iWordAt04 = m_60->CIndexedGeometry_GetNumStrips((unsigned short)w);
        beg->m_8 = m_60->CIndexedGeometry_GetStripLengthsPointer((unsigned short)w);
        beg->m_iThirdValue = m_60->CIndexedGeometry_GetStripsPointer((unsigned short)w);
        if (DAT_011f8b78)
        {
            n = GetNumLeafLodLevels() + 1;
            aj = -1.0f;
            idx = -1.0f;
            num = -1;
            cnt = -1;
            CSpeedTreeRT_GetTransitionValues(CSpeedTreeRT_GetLodLevel(), n, m_1c, m_28, m_20, (float)m_44, &aj, &idx, &num, &cnt);
            if (num == n - 2)
                arg->m_74 = aj;
            else if (num == n - 1)
            {
                arg->m_74 = 255.0f;
                beg->m_iWordAt00 = -1;
            }
            else
                arg->m_74 = (float)m_44;
        }
        else
            arg->m_74 = (float)m_44;
    }
    else
        AssignString("no frond geometry exists, possible prior call to DeleteFrondGeometry");
}

struct HelperC780
{
    void* CSimpleBillboard_GetBillboardCoords(float, float);
};
void __cdecl CSpeedTreeRT_GetTransitionValues(float, unsigned short, float, float, float, float, float*, float*, short*, short*);
extern "C" char DAT_011ad124;
struct BlockC4
{
    char pad[20];
    float a, b;
};
typedef float EntryC4;
struct ListC4
{
    char pad[8];
    int count;
    EntryC4* data;
};
struct OutC4
{
    char pad[0xf0];
    unsigned char active;
    char p1[3];
    EntryC4* data;
    void* value;
    float weight;
    unsigned short n;
    char p2[2];
    unsigned char active2;
    char p3[15];
    unsigned short n2;
    char p4[2];
    unsigned char active3;
    char p5[3];
    EntryC4* last;
    void* ptr;
    float weight2;
    unsigned short n3;
};
struct TreeC4
{
    char pad[0x14];
    HelperC780* helper;
    int p18;
    float x;
    float y;
    int p24;
    float z;
    char p2c[0x14];
    BlockC4* block;
    unsigned char mode;
    char p45[7];
    ListC4* list;
    char p50[0x1d];
    unsigned char enabled;
    char p6e[2];
    int data;
    void FillSpeedTreeOutput(OutC4* out);
};
// Fills OutC4 from the speed tree: computes weight from FUN_00b0c8d0, sets active flags, data/value pointers and list endpoints.
// @fnv 0x00b0c4f0
void TreeC4::FillSpeedTreeOutput(OutC4* out)
{
    if (DAT_011f8b78)
    {
        unsigned short p = ((CSpeedTreeRT*)this)->GetNumLeafLodLevels() + 1;
        float s = -1.0f;
        float i = -1.0f;
        short h = -1;
        short a = -1;
        float f, eb, cf, q;
        CSpeedTreeRT_GetTransitionValues(((FUN_00b08440_shell*)this)->CSpeedTreeRT_GetLodLevel(), p, x, z, y, (float)mode, &s, &i, &h, &a);
        out->weight = -1.0f;
        if (h == p - 1)
            out->weight = s;
        else if (a == p - 1)
            out->weight = i;
        out->active = out->weight != -1.0 ? 1 : 0;
        out->n = 0;
        if (out->active)
        {
            out->value = helper->CSimpleBillboard_GetBillboardCoords(block->b, block->a);
            if (list)
                out->data = list->data;
            else
                out->data = 0;
        }
        out->active2 = 0;
        out->n2 = 0;
        if (enabled)
        {
            out->ptr = &data;
            if (list)
                out->last = &list->data[8 * (list->count - 1)];
            else
                out->last = 0;
            out->weight2 = out->weight;
            out->active3 = out->weight2 >= 0.0 ? 1 : 0;
            out->weight2 = *(float*)&DAT_011ad124;
        }
        else
            out->active3 = 0;
        out->n3 = 0;
    }
    else
    {
        out->active = 0;
        out->active2 = 0;
        out->active3 = 0;
    }
}

struct V3cdd0
{
    float x, y, z;
    float CVec3_Distance(const V3cdd0* o);
};
struct P8
{
    int c0, b, fB, d, e, f, g, h;
};
struct R0cff0
{
    void ScaleSwizzled();
};
struct S0cf90
{
    R0cff0* AddVector(V3cdd0* fDist, V3cdd0* dst, V3cdd0* fB, float f);
};
struct T3ea10
{
    void CProjectedShadow_ComputeTexCoords(void* c0, V3cdd0 fB, float b0, void* p);
};
struct B0cdd0
{
    char pad[0x34];
    int v;
};
struct FUN_00b0cdd0_cls
{
    int m0;
    void* m4;
    char pad8[0x38];
    float* m40;
    int m44, m48;
    B0cdd0* m4c;
    T3ea10* m50;
    int m54, m58, m5c;
    void* m60;
    void CSpeedTreeRT_ComputeSelfShadowTexCoords();
};
// @fnv 0x00b0cdd0
// src: COMMUNITY 0x00b0cdd0
void FUN_00b0cdd0_cls::CSpeedTreeRT_ComputeSelfShadowTexCoords()
{
    float b0;
    V3cdd0 c0, dst, fB, fDist, s1, t1;
    if (m4 && m60 && m50)
    {
        s1.x = m40[0];
        s1.y = m40[1];
        s1.z = m40[2];
        c0.x = s1.x;
        c0.y = s1.y;
        c0.z = s1.z;
        t1.x = m40[3];
        t1.y = m40[4];
        t1.z = m40[5];
        dst.x = t1.x;
        dst.y = t1.y;
        dst.z = t1.z;
        b0 = c0.CVec3_Distance(&dst) * 0.5;
        ((S0cf90*)&c0)->AddVector(&fDist, &dst, &fB, 0.5f)->ScaleSwizzled();
        if (m4c)
        {
            m50->CProjectedShadow_ComputeTexCoords(m4, fB, b0, &m4c->v);
            m50->CProjectedShadow_ComputeTexCoords(m60, fB, b0, &m4c->v);
        }
        else
        {
            m50->CProjectedShadow_ComputeTexCoords(m4, fB, b0, 0);
            m50->CProjectedShadow_ComputeTexCoords(m60, fB, b0, 0);
        }
    }
    {
        P8 u;
    }
}

struct StringRecord
{
    int metadata;
    union
    {
        char* allocated;
        char inlineChars[16];
    };
    unsigned int length, capacity;
    int extra1, extra2, extra3, extra4;
};
struct RecordVector
{
    int metadata0, metadata4, metadata8;
    StringRecord *first, *last;
};
void __cdecl FUN_00ec7c56();
struct FUN_00b0d490_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    RecordVector records;
    char* GetRecordStringDataChecked(unsigned int index);
};
// Returns the character data of the record at index, using the inline buffer when capacity is below 16, otherwise the allocated pointer.
// @fnv 0x00b0d490
// src: GUESS 0x00b0d490 (confidence: medium)
char* FUN_00b0d490_Class::GetRecordStringDataChecked(unsigned int index)
{
    RecordVector* data = &records;
    if (index >= static_cast<unsigned int>(data->last - data->first))
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (false);
    StringRecord* entry = data->first + index;
    return entry->capacity >= 16 ? entry->allocated : entry->inlineChars;
}

struct Vec2
{
    float x;
    float y;
};

struct FUN_00b0d5f0_Class
{
    int m_unk_00;
    int m_unk_04;
    int m_unk_08;
    int m_unk_0c;
    int m_unk_10;
    int m_unk_14;
    int m_unk_18;
    int m_unk_1c;
    int m_unk_20;
    int m_unk_24;
    int m_unk_28;
    int m_unk_2c;
    int m_unk_30;
    int m_unk_34;
    int m_unk_38;
    int m_unk_3c;
    float* m_pBoundingBox;
    int m_unk_44;
    int m_unk_48;
    int m_unk_4c;
    int m_unk_50;
    int m_unk_54;
    int m_unk_58;
    int m_unk_5c;
    int m_unk_60;
    int m_unk_64;
    int m_unk_68;
    char m_unk_6c;
    unsigned char m_bFlag;
    char m_unk_6e;
    char m_unk_6f;
    float m_point00;
    float m_point01;
    float m_point02;
    float m_point03;
    float m_point04;
    float m_point05;
    float m_point06;
    float m_point07;
    float m_point08;
    float m_point09;
    float m_point10;
    float m_point11;

    void InitBoundingBoxCorners();
};

// If m_bFlag is set, computes the mid-Z plane of the bounding box and writes four corner points into m_point00..m_point11.
// @fnv 0x00b0d5f0
void FUN_00b0d5f0_Class::InitBoundingBoxCorners()
{
    if (m_bFlag)
    {
        // Keep the original constructor-free temporaries while using the shared layout.
        float pMax6[sizeof(CVec3) / sizeof(float)];
        float pt0[sizeof(CVec3) / sizeof(float)];
        float pForm2[sizeof(CVec3) / sizeof(float)];
        float* idx;
        float pObj2;
        float ptr[sizeof(CVec3) / sizeof(float)];
        float pt2[sizeof(CVec3) / sizeof(float)];
        float* valVal;
        float* v9;
        Vec2 corner3;
        Vec2 kIter_2;
        Vec2 r;
        float n4[sizeof(CVec3) / sizeof(float)];
        float* pt4;
        Vec2 dst3;
        float* max;
        float* c;

        idx = m_pBoundingBox;
        reinterpret_cast<CVec3*>(pt0)->x = idx[0];
        reinterpret_cast<CVec3*>(pt0)->y = idx[1];
        reinterpret_cast<CVec3*>(pt0)->z = idx[2];

        valVal = m_pBoundingBox + 3;
        reinterpret_cast<CVec3*>(pForm2)->x = valVal[0];
        reinterpret_cast<CVec3*>(pForm2)->y = valVal[1];
        reinterpret_cast<CVec3*>(pForm2)->z = valVal[2];

        pObj2 = (reinterpret_cast<CVec3*>(pt0)->z + reinterpret_cast<CVec3*>(pForm2)->z) * 0.5;

        kIter_2.x = reinterpret_cast<CVec3*>(pForm2)->x;
        kIter_2.y = reinterpret_cast<CVec3*>(pForm2)->y;
        reinterpret_cast<CVec3*>(pMax6)->x = kIter_2.x;
        reinterpret_cast<CVec3*>(pMax6)->y = kIter_2.y;
        reinterpret_cast<CVec3*>(pMax6)->z = pObj2;
        v9 = &m_point00;
        v9[0] = reinterpret_cast<CVec3*>(pMax6)->x;
        v9[1] = reinterpret_cast<CVec3*>(pMax6)->y;
        v9[2] = reinterpret_cast<CVec3*>(pMax6)->z;

        corner3.x = reinterpret_cast<CVec3*>(pt0)->x;
        corner3.y = reinterpret_cast<CVec3*>(pForm2)->y;
        reinterpret_cast<CVec3*>(pt2)->x = corner3.x;
        reinterpret_cast<CVec3*>(pt2)->y = corner3.y;
        reinterpret_cast<CVec3*>(pt2)->z = pObj2;
        c = &m_point00 + 3;
        c[0] = reinterpret_cast<CVec3*>(pt2)->x;
        c[1] = reinterpret_cast<CVec3*>(pt2)->y;
        c[2] = reinterpret_cast<CVec3*>(pt2)->z;

        dst3.x = reinterpret_cast<CVec3*>(pt0)->x;
        dst3.y = reinterpret_cast<CVec3*>(pt0)->y;
        reinterpret_cast<CVec3*>(ptr)->x = dst3.x;
        reinterpret_cast<CVec3*>(ptr)->y = dst3.y;
        reinterpret_cast<CVec3*>(ptr)->z = pObj2;
        pt4 = &m_point00 + 6;
        pt4[0] = reinterpret_cast<CVec3*>(ptr)->x;
        pt4[1] = reinterpret_cast<CVec3*>(ptr)->y;
        pt4[2] = reinterpret_cast<CVec3*>(ptr)->z;

        r.x = reinterpret_cast<CVec3*>(pForm2)->x;
        r.y = reinterpret_cast<CVec3*>(pt0)->y;
        reinterpret_cast<CVec3*>(n4)->x = r.x;
        reinterpret_cast<CVec3*>(n4)->y = r.y;
        reinterpret_cast<CVec3*>(n4)->z = pObj2;
        max = &m_point00 + 9;
        max[0] = reinterpret_cast<CVec3*>(n4)->x;
        max[1] = reinterpret_cast<CVec3*>(n4)->y;
        max[2] = reinterpret_cast<CVec3*>(n4)->z;
    }
}

void __cdecl FUN_00ec7c56();

struct FUN_00b0eca0_t
{
    int a;
    int b;
    bool ProcessEntries_00b0eca0(FUN_00b0eca0_t* p);
};

// Calls FUN_00ec7c56 if a is zero or differs from p->a, then returns whether b equals p->b.
// @fnv 0x00b0eca0
// src: GUESS 0x00b0eca0 (confidence: low)
bool FUN_00b0eca0_t::ProcessEntries_00b0eca0(FUN_00b0eca0_t* apOther)
{
    if (!static_cast<bool>(static_cast<int>(a != 0)) || !static_cast<bool>(static_cast<int>(a == apOther->a)))
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);
    return b == apOther->b;
}

void __cdecl FUN_00ec7c56(void);

struct FUN_00b10430_Arg
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};

struct FUN_00b10430_Class
{
    int unk00;
    int unk04;

    FUN_00b10430_Class* __thiscall SetCheckedRangeIndex(unsigned int index, FUN_00b10430_Arg* range);
};

// Resets unk00, validates index against range bounds via FUN_00ec7c56, then stores range->unk00 and index into the object.
// @fnv 0x00b10430
// src: GUESS 0x00b10430 (confidence: medium)
FUN_00b10430_Class* FUN_00b10430_Class::SetCheckedRangeIndex(unsigned int index, FUN_00b10430_Arg* range)
{
    unk00 = 0;

    if (range == 0 || range->unk0C > index || index > range->unk10)
    {
        FUN_00ec7c56();
    }

    do
    {
    } while (0);

    unk00 = range->unk00;
    unk04 = index;

    return this;
}

struct BasePart : FUN_00b02b70_shell
{
    ~BasePart();
};
struct RotationPart : FUN_00b02c90_class
{
    ~RotationPart();
};
struct DataPart : FUN_00b02dc0_class
{
    ~DataPart();
};
struct FUN_00b029f0 : BasePart
{
    float m_38;
    BasePart m_3c;
    float m_74;
    RotationPart m_78;
    RotationPart m_b4;
    DataPart m_f0;
    DataPart m_104;
    DataPart m_118;
    FUN_00b029f0();
};
// Default constructor for FUN_00b029f0 that initializes m_38 and m_74 to -1.0f.
// @fnv 0x00b029f0
FUN_00b029f0::FUN_00b029f0() : m_38(-1.0f), m_74(-1.0f)
{}

extern MemoryManager DAT_011f6238;

struct FUN_0044a730_shell
{
    void __thiscall fopen_0044a730(bool first, unsigned int second);
};

struct FUN_00b04420_pad
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class FUN_00b04420_class
{
  public:
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    FUN_0044a730_shell m18;

    void ReleaseStorage_00b04420();
};

// Releases m04, m0c, and m14 via DAT_011f6238.Deallocate, nulls them, and calls m18.FUN_0044a730(true, 0).
// @fnv 0x00b04420
// src: GUESS 0x00b04420 (confidence: medium)
void FUN_00b04420_class::ReleaseStorage_00b04420()
{
    void* n;
    FUN_00b04420_pad v_;
    n = m04;
    DAT_011f6238.Deallocate(n);
    m04 = 0;
    void* c;
    c = m0c;
    DAT_011f6238.Deallocate(c);
    m0c = 0;
    void* v0c;
    v0c = m14;
    DAT_011f6238.Deallocate(v0c);
    m14 = 0;
    m18.fopen_0044a730(true, 0);
}

struct S00b065e0_Vec
{
    float x;
    float y;
    float z;
};

struct S00b065e0_Cls
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void CSpeedTreeRT_SetTreePosition(float a, float b, float c);
};
// @fnv 0x00b065e0
// src: XBOX_PDB 0x00b065e0
void S00b065e0_Cls::CSpeedTreeRT_SetTreePosition(float a, float b, float c)
{
    void* base;
    float* n;
    float x;
    float y;
    float v;
    if (m_34)
    {
        n = (float*)((char*)m_34 + 4);
        n[0] = a;
        n[1] = b;
        n[2] = c;
    }
    else
    {
        x = a;
        y = b;
        v = c;
        base = m_iWordAt00;
        *(S00b065e0_Vec*)((char*)base + 4) = *(S00b065e0_Vec*)&x;
    }
}

extern double _DAT_0101a6b0;
struct FUN_00b08530_class
{
    short GetIndexFromLevel(float level);
};

// Returns (short)((1.0 - level) * count) with count from offset 0x78; level comes from FUN_00b08440 if it equals a constant, and index == count is decremented.
// @fnv 0x00b08530
short FUN_00b08530_class::GetIndexFromLevel(float level)
{
    short index = 0;
    if (level == _DAT_0101a6b0)
        level = ((FUN_00b08440_shell*)this)->CSpeedTreeRT_GetLodLevel();

    int count = ((FUN_00b086f0_class*)this)->GetLowWordAtOffset0x78();
    index = (short)((1.0 - level) * count);
    if (index == count)
        --index;
    return index;
}

struct FUN_00b085a0_local_shell
{
    float CSpeedTreeRT_GetLodLevel();
    unsigned short GetId();
    short CSpeedTreeRT_GetDiscreteFrondLodLevel(float fLodLevel);
};

extern double _DAT_0101a6b0;
unsigned short __cdecl FUN_00ec62c0();

// Converts a float LOD level to a clamped integer LOD index using the object's LOD count and a fallback value.
// @fnv 0x00b085a0
// src: COMMUNITY 0x00b085a0
short FUN_00b085a0_local_shell::CSpeedTreeRT_GetDiscreteFrondLodLevel(float fLodLevel)
{
    short sLevel = 0;

    if (fLodLevel == _DAT_0101a6b0)
    {
        fLodLevel = CSpeedTreeRT_GetLodLevel();
    }

    int nNumLodLevels = GetId();
    sLevel = (short)((1.0f - fLodLevel) * nNumLodLevels);

    if (sLevel == nNumLodLevels)
    {
        sLevel--;
    }

    return sLevel;
}

struct FUN_00ac2f70_shell
{
    void ClearAllElements();
};
struct FUN_00b08750_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void UpdateState_00b08750();
};
// @fnv 0x00b08750
// src: GUESS 0x00b08750 (confidence: low)
void FUN_00b08750_class::UpdateState_00b08750()
{
    unsigned int ctx00;
    unsigned int ctx04;
    unsigned int ctx08;
    unsigned int ctx0c;
    unsigned int ctx10;
    unsigned int ctx14;
    unsigned int ctx18;
    unsigned int ctx1c;
    unsigned int ctx20;
    unsigned int ctx24;
    unsigned int ctx28;
    unsigned int ctx2c;
    unsigned int ctx30;
    unsigned int ctx34;
    unsigned int ctx38;
    unsigned int ctx3c;
    unsigned int ctx40;
    unsigned int ctx44;
    unsigned int ctx48;
    unsigned int ctx4c;
    unsigned int ctx50;
    unsigned int ctx54;
    unsigned int ctx58;
    unsigned int ctx5c;
    unsigned int ctx60;
    unsigned int ctx64;
    unsigned int ctx68;
    unsigned int ctx6c;
    unsigned int ctx70;
    {
        FUN_00ac2f70_shell* p;
        if (m_iWordAt04)
        {
            p = (FUN_00ac2f70_shell*)m_iWordAt04;
            ((FUN_00ac2f70_shell*)((char*)p + 0x70))->ClearAllElements();
        }
    }
}

extern unsigned int DAT_010173f0;
extern int DAT_010a307c;

struct FUN_00ec78e0
{
    void* vtbl;
    int unk04;
    int unk08;

    FUN_00ec78e0();
};

struct FUN_00b096a0_Str
{
    void fopen_0044a730(bool, unsigned int);
    void AssignSubstring(const FUN_00b096a0_Str&, unsigned int, unsigned int);

    ~FUN_00b096a0_Str();
};

struct FUN_00b096a0 : FUN_00ec78e0
{
    FUN_00b096a0_Str m_str;

    FUN_00b096a0(const FUN_00b096a0_Str& pName);
};

// @fnv 0x00b096a0
FUN_00b096a0::FUN_00b096a0(const FUN_00b096a0_Str& pName)
{
    int v00;
    int v01;
    int v02;
    int v03;
    int v04;
    int v05;
    int v06;
    int v07;
    int v08;
    int v09;
    int v10;
    int v11;
    int v12;
    int v13;
    int v14;
    int v15;
    int v16;
    int v17;
    int v18;
    int v19;
    int v20;
    int v21;
    int v22;
    int v23;
    int v24;
    int v25;

    *(void**)this = (void*)&DAT_010a307c;

    {
        FUN_00b096a0_Str& s = m_str;
        s.fopen_0044a730(false, 0);
        s.AssignSubstring(pName, 0, DAT_010173f0);
    }
}

namespace fnv_00b09730 {
struct FUN_00b09730_Local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

extern MemoryManager DAT_011f6238;

struct FUN_00b09730_Class : FUN_0044d6f0_This
{
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_iThirdValue;

    void* __thiscall FUN_00b09730(unsigned int flags);
};

// @fnv 0x00b09730
void* __thiscall FUN_00b09730_Class::FUN_00b09730(unsigned int flags)
{
    FUN_00b09730_Local local;

    *(void**)this = &DAT_010a307c;
    m_iThirdValue._Tidy(true, 0);
    FUN_0044d6f0_This::FUN_00ec79a1();

    if ((flags & 1) != 0)
    {
        DAT_011f6238.Deallocate(this);
    }

    return this;
}
}  // namespace fnv_00b09730

// Returns an approximate distance to other, estimating the square root of the squared component differences with an integer bit trick.
// @fnv 0x00b04d40
// src: COMMUNITY 0x00b04d40
float V3cdd0::CVec3_Distance(const V3cdd0* other)
{
    float f =
        (other->z - (+z)) * (other->z - (+z)) +
        ((other->y - (+y)) * (other->y - (+y)) + (other->x - ((this + 1 - 1)->x)) * (other->x - ((this + 1 - 1)->x)));
    int i = (*(int*)&f >> 1) + 0x1fc00000;
    return *(float*)&i;
}

struct V
{
    float x, y, z;
};
struct M
{
    float _00, _01, _02, _03;
    float _10, _11, _12, _13;
    float _20, _21, _22, _23;
    float _30, _31, _32, _33;
};
struct S
{
    float x, y, z;
    V* TransformPointByMatrix4(V* out, M* m);
};
// Applies the 4x4 matrix m to the vector (x, y, z) and stores the resulting x, y, z components in out.
// @fnv 0x00b05000
// src: GUESS 0x00b05000 (confidence: medium)
V* S::TransformPointByMatrix4(V* out, M* apMatrix)
{
    float tx = (double)apMatrix->_30 + (apMatrix->_20 * z + (apMatrix->_10 * y + apMatrix->_00 * x));
    float ty = (double)apMatrix->_31 + (apMatrix->_21 * z + (apMatrix->_11 * y + apMatrix->_01 * x));
    float tz5 = (double)apMatrix->_32 + (apMatrix->_22 * z + (apMatrix->_12 * y + apMatrix->_02 * x));
    out->x = tx;
    out->y = ty;
    out->z = tz5;
    return out;
}
