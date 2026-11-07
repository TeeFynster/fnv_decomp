
// src/havok/common/serialize/data/dict/hkdataobjectdict.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/dict/hkdataobjectdict.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkThreadMemory.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkDataRefCounted.h"
#include "../../../../../../include/hkDataClassImpl.h"
#include "../../../../../../include/hkDataClassDict.h"

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct hkDataMemberInfo
{
    const char* name;
    hkDataRefCounted* referencedClass;
    int unk08;
    int unk0c;
    int type;
    int unk14;
};

struct hkDataClassMemberInfo
{
    int m_key;
    const hkDataClassDict* m_table;
    int m_uiFilterValue;
    void* m_object;
    int m_flags;
};

hkDataClassDict* __fastcall ConstructDataClassDict(hkDataClassDict* pkClass, void*, hkDataWorldDict* pkOwner,
                                                const char* pcName, int iFlags) throw();

// The base destructor is empty and inlined by 0x00dca0f0 in the game executable.
inline hkDataRefCounted::~hkDataRefCounted()
{}


__forceinline Pair::Pair() throw()
{
    *reinterpret_cast<volatile int*>(&a) = 0;
    a = 0;
    b = 0;
}

inline hkMemoryAllocator& GetSerializationHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

// The legacy router view stores its heap pointer in the shared pListener slot.
inline hkMemoryAllocator& BSAudio::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(pListener);
}

struct FUN_00dc72e0_class
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
    void* m_p6;
    void* m_p7;
    void hkDataWorldDict_setClassVersion(void* pArg, void* pVal);
};

// @fnv 0x00dc72e0
// src: XBOX_PDB 0x00dc72e0
void FUN_00dc72e0_class::hkDataWorldDict_setClassVersion(void* pArg, void* apValue)
{
    ((void**)(*(void***)pArg))[5] = apValue;
}

struct FUN_00dc8a60_class
{
    char m_data[0x28];
    char* ArrayOfTuplesImplementation_asArray(int arg);
};

// @fnv 0x00dc8a60
// src: XBOX_PDB 0x00dc8a60
char* FUN_00dc8a60_class::ArrayOfTuplesImplementation_asArray(int aiScale)
{
    *(int*)((char*)this + 0x1c) = *(int*)((char*)this + 0x24) * aiScale;
    return (char*)this + 0xc;
}

struct FUN_00dc8fc0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    void ResetEntries();
    void Reset();
};
// @fnv 0x00dc8fc0
void FUN_00dc8fc0_Class::Reset()
{
    m_iWordAt04 = 0;
    reinterpret_cast<FUN_00dc8fc0_Class*>(reinterpret_cast<char*>(this) + 0xc)->ResetEntries();
    m_18 = -1;
}

struct FUN_00dc9540_class
{
    int __thiscall hkDataObjectDict_getMemberName(int a);
};

// @fnv 0x00dc9540
// src: XBOX_PDB 0x00dc9540
int __thiscall FUN_00dc9540_class::hkDataObjectDict_getMemberName(int aiIndex)
{
    int* p = *(int**)((char*)this + 0x10);
    return p[aiIndex * 4];
}

struct FUN_00dc9550_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    void* m_p10;
    void hkDataObjectDict_getMemberValue(void** out, int idx);
};

// @fnv 0x00dc9550
// src: XBOX_PDB 0x00dc9550
void FUN_00dc9550_Class::hkDataObjectDict_getMemberValue(void** out, int aiIndex)
{
    out[0] = this;
    void* base = *(void**)((char*)this + 0x10);
    out[1] = *(void**)((char*)base + (aiIndex << 4));
}

struct FUN_00dc9ab0_class
{
    int* __thiscall VecArrayImplementation_asVec(int a);
};

// @fnv 0x00dc9ab0
// src: XBOX_PDB 0x00dc9ab0
int* __thiscall FUN_00dc9ab0_class::VecArrayImplementation_asVec(int aiIndex)
{
    return *(int**)((char*)this + 0xc) + *(int*)((char*)this + 0x18) * aiIndex;
}

extern int DAT_010d707c;

struct FUN_00dca1c0
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int m12;
    int m16;
    int m20;
    FUN_00dca1c0();
};

// @fnv 0x00dca1c0
FUN_00dca1c0::FUN_00dca1c0()
{
    m6 = 0;
    m8 = 0;
    m12 = 0;
    m16 = 0;
    m20 = 0x80000000;
    m0 = &DAT_010d707c;
}

struct FUN_00dca1f0
{
    int m0;
    int m4;
    int m8;
    int mc;
    void __thiscall Set(char* a, char b);
};

// @fnv 0x00dca1f0
void __thiscall FUN_00dca1f0::Set(char* pcBuffer, char cValue)
{
    pcBuffer[mc] = cValue;
}

struct FUN_00dca5d0_Class
{
    float* SetFloatAt(int index, float value);
};

// @fnv 0x00dca5d0
float* FUN_00dca5d0_Class::SetFloatAt(int index, float value)
{
    float* p = *(float**)((char*)this + 0xc);
    p[index] = value;
    return p;
}


// @fnv 0x00dcad80
int hkDataClassDict::getNumMembers() const
{
    const hkDataClassDict* node = parent;
    int count = this->count;
    while (node)
    {
        count += node->count;
        node = node->parent;
    }
    return count;
}

struct FUN_00dcb0d0_class
{
    int* m_p;
    void UpdateState_00dcb0d0(int* p);
};
// @fnv 0x00dcb0d0
// src: GUESS 0x00dcb0d0 (confidence: low)
void __thiscall FUN_00dcb0d0_class::UpdateState_00dcb0d0(int* pOut)
{
    *pOut = (int)this;
    pOut[1] = 0;
}

struct FUN_00dcb170_class
{
    int __thiscall StructArrayImplementation_Object_isValid(int);
};

// @fnv 0x00dcb170
// src: XBOX_PDB 0x00dcb170
int __thiscall FUN_00dcb170_class::StructArrayImplementation_Object_isValid(int a)
{
    int* p = *(int**)((char*)this + 0xc);
    int r = 0;
    r = a < *(p + 4);
    return r;
}

struct FUN_00dcb2b0_StandIn
{
    int __thiscall StructArrayImplementation__find(int);
};

struct FUN_00dcb490_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int __thiscall StructArrayImplementation_swizzleObjectMember(int);
};

// @fnv 0x00dcb490
// src: XBOX_PDB 0x00dcb490
int __thiscall FUN_00dcb490_Class::StructArrayImplementation_swizzleObjectMember(int a)
{
    int i = ((FUN_00dcb2b0_StandIn*)this)->StructArrayImplementation__find(a);
    return ((int*)m_0c)[i * 2 + 1];
}

// @fnv 0x00dc72f0
// src: HAVOK_LIB 0x00dc72f0
void __stdcall hkDataWorldDict_getType(int* p)
{
    *p = 1;
}

struct FUN_00dc9530_StandIn
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    char hkDataObjectDict_isValid(int a);
};
// @fnv 0x00dc9530
// src: HAVOK_LIB 0x00dc9530
char FUN_00dc9530_StandIn::hkDataObjectDict_isValid(int a)
{
    return a < m_14 ? 1 : 0;
}

struct FUN_00dca5c0_Class
{
    float* m_p0;
    float* m_p4;
    float* m_p8;
    float* m_pc;
    float RealArrayImplementation_asReal(int index);
};

// @fnv 0x00dca5c0
// src: HAVOK_LIB 0x00dca5c0
float FUN_00dca5c0_Class::RealArrayImplementation_asReal(int index)
{
    return m_pc[index];
}


// @fnv 0x00dc8e50
hkDataMemberInfo* hkDataClassDict::FindEntry(const char* value)
{
    hkDataClassDict* dict = this;
    while (dict)
    {
        int count = dict->count;
        for (int i = 0; i < count; ++i)
        {
            if (dict->members[i].name == value)
                return dict->members + i;
        }
        dict = dict->parent;
    }
    return 0;
}

struct FUN_00dca2b0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    __int64* m_iThirdValue;
    __int64 __thiscall IntArrayImplementation_asInt64(int index);
};

// @fnv 0x00dca2b0
// src: XBOX_PDB 0x00dca2b0
__int64 FUN_00dca2b0_Class::IntArrayImplementation_asInt64(int index)
{
    return m_iThirdValue[index];
}

struct FUN_00dcb0c0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void SetPair(void** out, int value);
};

// @fnv 0x00dcb0c0
void FUN_00dcb0c0_class::SetPair(void** out, int value)
{
    out[0] = this;
    out[1] = (void*)value;
}

struct FUN_00dcb190_Elem
{
    void* m0;
    void* m4;
};

struct FUN_00dcb190_Inner
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00dcb190_Elem* m_data;
};

struct FUN_00dcb190_Class
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00dcb190_Inner* m_iThirdValue;
    void* __thiscall StructArrayImplementation_Object_getMemberName(int index);
};

// Returns the m0 pointer of the element at the given index in the inner object's m_data array.
// @fnv 0x00dcb190
// src: XBOX_PDB 0x00dcb190
void* FUN_00dcb190_Class::StructArrayImplementation_Object_getMemberName(int index)
{
    return m_iThirdValue->m_data[index].m0;
}

struct FUN_00dc6fd0_VTable
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void(__thiscall* m_8)(void*);
};

struct FUN_00dc6fd0_Intermediate
{
    char m_00[0x20];
    void* m_20;
};

struct FUN_00dc6fd0_class
{
    char m_00[0x0C];
    FUN_00dc6fd0_Intermediate* m_0C;
    void ArrayOfTuplesImplementation_View_clear();
};

// @fnv 0x00dc6fd0
// src: XBOX_PDB 0x00dc6fd0
void FUN_00dc6fd0_class::ArrayOfTuplesImplementation_View_clear()
{
    void* object = m_0C->m_20;
    FUN_00dc6fd0_VTable* vtable = *(FUN_00dc6fd0_VTable**)object;
    vtable->m_8(object);
}

struct FUN_00dc6ff0_Stream
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void call(void*, unsigned char)
    {}
};

struct FUN_00dc6ff0_Wrapper
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc6ff0_Stream* m20;
};

struct FUN_00dc6ff0_class
{
    void* m00;
    void* m04;
    void* m08;
    FUN_00dc6ff0_Wrapper* m0c;
    unsigned char* m10;

    void ArrayOfTuplesImplementation_View_setAll(const unsigned char* data, int count);
};

// @fnv 0x00dc6ff0
// src: XBOX_PDB 0x00dc6ff0
void FUN_00dc6ff0_class::ArrayOfTuplesImplementation_View_setAll(const unsigned char* data, int count)
{
    for (int i = 0; i < count; ++i)
        m0c->m20->call(m10 + i, data[i]);
}

struct FUN_00dc7030_Target
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void va() = 0;
    virtual void vb() = 0;
    virtual void vc() = 0;
    virtual void FUN_00dc7030_virtual(unsigned char* p, float value) = 0;
};

struct FUN_00dc7030_Holder
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc7030_Target* m20;
};

struct FUN_00dc7030_StandIn
{
    void* m00;
    void* m04;
    void* m08;
    FUN_00dc7030_Holder* m0c;
    unsigned char* m10;

    void __thiscall ArrayOfTuplesImplementation_View_setAll_00dc7030(float* values, int count);
};

// @fnv 0x00dc7030
// src: XBOX_PDB 0x00dc7030
void FUN_00dc7030_StandIn::ArrayOfTuplesImplementation_View_setAll_00dc7030(float* values, int count)
{
    for (int i = 0; i < count; ++i)
    {
        m0c->m20->FUN_00dc7030_virtual(m10 + i, values[i]);
    }
}

struct FUN_00dc7070_target
{
    virtual void FUN_00dc7070_v0() = 0;
    virtual void FUN_00dc7070_v1() = 0;
    virtual void FUN_00dc7070_v2() = 0;
    virtual void FUN_00dc7070_v3() = 0;
    virtual void FUN_00dc7070_v4() = 0;
    virtual void FUN_00dc7070_v5() = 0;
    virtual void FUN_00dc7070_v6() = 0;
    virtual void FUN_00dc7070_v7() = 0;
    virtual void* FUN_00dc7070_v8(int) = 0;
};

struct FUN_00dc7070_holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7070_target* m_20;
};

struct FUN_00dc7070_class
{
    void* m_00;
    int m_04;
    void* m_08;
    FUN_00dc7070_holder* m_0c;
    int m_10;

    void* ArrayOfTuplesImplementation_View_asVec(int a);
};

// @fnv 0x00dc7070
// src: XBOX_PDB 0x00dc7070
void* FUN_00dc7070_class::ArrayOfTuplesImplementation_View_asVec(int aiOffset)
{
    return m_0c->m_20->FUN_00dc7070_v8(m_10 + aiOffset);
}

struct FUN_00dc7090_vtable
{
    void* m_slots[10];
};

struct FUN_00dc7090_target
{
    FUN_00dc7090_vtable* m_ppVirtualMethodTable;
};

struct FUN_00dc7090_wrapper
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7090_target* m_20;
};

struct FUN_00dc7090_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7090_wrapper* m_0c;
    int m_10;
    void __thiscall InvokeTargetMethod(int a, int b);
};

typedef void(__thiscall* FUN_00dc7090_call)(void*, int, int);

// @fnv 0x00dc7090
void __thiscall FUN_00dc7090_class::InvokeTargetMethod(int aiOffset, int b)
{
    FUN_00dc7090_call fn = reinterpret_cast<FUN_00dc7090_call>(reinterpret_cast<void**>(m_0c->m_20->m_ppVirtualMethodTable)[9]);

    fn(m_0c->m_20, m_10 + aiOffset, b);
}

struct FUN_00dc70e0_Virtual
{
    virtual void F0() = 0;
    virtual void F1() = 0;
    virtual void F2() = 0;
    virtual void F3() = 0;
    virtual void F4() = 0;
    virtual void F5() = 0;
    virtual void F6() = 0;
    virtual void F7() = 0;
    virtual void F8() = 0;
    virtual void F9() = 0;
    virtual void F10() = 0;
    virtual void Call(int value, void* data) = 0;
};

struct FUN_00dc70e0_Intermediate
{
    char m_00[0x20];
    FUN_00dc70e0_Virtual* m_20;
};

struct FUN_00dc70e0_class
{
    char m_00[0x0c];
    FUN_00dc70e0_Intermediate* m_0c;
    int m_10;

    void __thiscall CallAtOffset(int offset, void* data);
};

// Forwards the sum of m_10 and offset, with data, to the Call method of the object reached through m_0c->m_20.
// @fnv 0x00dc70e0
void __thiscall FUN_00dc70e0_class::CallAtOffset(int offset, void* data)
{
    m_0c->m_20->Call(m_10 + offset, data);
}

struct FUN_00dc7110_Target
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual int FUN_00dc7110_virtual(int) = 0;
};

struct FUN_00dc7110_Intermediate
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7110_Target* m_20;
};

struct FUN_00dc7110_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7110_Intermediate* m_0c;
    int m_10;
    int GetVirtualResult(int a);
};

// @fnv 0x00dc7110
int FUN_00dc7110_Class::GetVirtualResult(int aiOffset)
{
    return m_0c->m_20->FUN_00dc7110_virtual(m_10 + aiOffset);
}

struct FUN_00dc7180_callee
{
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual int ArrayOfTuplesImplementation_View_setInt(int, int) = 0;
};

struct FUN_00dc7180_middle
{
    char m_ucUnknownByte[0x20];
    FUN_00dc7180_callee* m_callee;
};

struct FUN_00dc7180_class
{
    char m_ucUnknownByte[0x0c];
    FUN_00dc7180_middle* m_middle;
    int m_uiFilterValue;

    int __thiscall ArrayOfTuplesImplementation_View_setInt(int a, int b);
};

// @fnv 0x00dc7180
// src: XBOX_PDB 0x00dc7180
int __thiscall FUN_00dc7180_class::ArrayOfTuplesImplementation_View_setInt(int aiOffset, int b)
{
    return m_middle->m_callee->ArrayOfTuplesImplementation_View_setInt(m_uiFilterValue + aiOffset, b);
}

struct FUN_00dc71b0_target
{
    virtual void m00() = 0;
    virtual void m04() = 0;
    virtual void m08() = 0;
    virtual void m0c() = 0;
    virtual void m10() = 0;
    virtual void m14() = 0;
    virtual void m18() = 0;
    virtual void m1c() = 0;
    virtual void m20() = 0;
    virtual void m24(int) = 0;
    virtual void m28() = 0;
    virtual void m2c() = 0;
    virtual void m30() = 0;
    virtual void m34() = 0;
    virtual void m38() = 0;
    virtual void m3c() = 0;
    virtual void m40() = 0;
    virtual void m44() = 0;
    virtual int m48(int) = 0;
};

struct FUN_00dc71b0_inner
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc71b0_target* m20;
};

struct FUN_00dc71b0_class
{
    void* m00;
    void* m04;
    void* m08;
    FUN_00dc71b0_inner* m0c;
    int m10;
    int __thiscall GetOffsetValue(int);
};

// @fnv 0x00dc71b0
int __thiscall FUN_00dc71b0_class::GetOffsetValue(int aiOffset)
{
    return m0c->m20->m48(m10 + aiOffset);
}

struct FUN_00dc7220_VirtualBase
{
// @fnv 0x00dc7220
    virtual void FUN_00dc7220_v00()
    {}
    virtual void FUN_00dc7220_v01()
    {}
    virtual void FUN_00dc7220_v02()
    {}
    virtual void FUN_00dc7220_v03()
    {}
    virtual void FUN_00dc7220_v04()
    {}
    virtual void FUN_00dc7220_v05()
    {}
    virtual void FUN_00dc7220_v06()
    {}
    virtual void FUN_00dc7220_v07()
    {}
    virtual void FUN_00dc7220_v08()
    {}
    virtual void FUN_00dc7220_v09()
    {}
    virtual void FUN_00dc7220_v10()
    {}
    virtual void FUN_00dc7220_v11()
    {}
    virtual void FUN_00dc7220_v12()
    {}
    virtual void FUN_00dc7220_v13()
    {}
    virtual void FUN_00dc7220_v14()
    {}
    virtual void FUN_00dc7220_v15()
    {}
    virtual void FUN_00dc7220_v16()
    {}
    virtual void FUN_00dc7220_v17()
    {}
    virtual void FUN_00dc7220_v18()
    {}
    virtual void FUN_00dc7220_v19()
    {}
    virtual void FUN_00dc7220_v20()
    {}
};

struct FUN_00dc7220_Virtual : FUN_00dc7220_VirtualBase
{
    virtual void FUN_00dc7220_virtual(int, int)
    {}
};

struct FUN_00dc7220_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7220_Virtual* m_20;
};

struct FUN_00dc7220_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7220_Holder* m_0c;
    int m_10;

    void ArrayOfTuplesImplementation_View_setObject(int a, int b);
};

// src: XBOX_PDB 0x00dc7220
void FUN_00dc7220_class::ArrayOfTuplesImplementation_View_setObject(int a, int b)
{
    m_0c->m_20->FUN_00dc7220_virtual(m_10 + a, b);
}

struct FUN_00dc7270_virtual
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void FUN_00dc7270_virtual_call(int, int) = 0;
};

struct FUN_00dc7270_manager
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7270_virtual* m_20;
};

struct FUN_00dc7270_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7270_manager* m_0c;
    int m_10;
    void __thiscall DispatchOffsetCall(int, int);
};

// Forwards m_10 + a and b to the virtual call on m_0c->m_20.
// @fnv 0x00dc7270
void __thiscall FUN_00dc7270_class::DispatchOffsetCall(int aiOffset, int b)
{
    m_0c->m_20->FUN_00dc7270_virtual_call(m_10 + aiOffset, b);
}

struct Receiver
{
    void FUN_009ba760(void* pArg);
};

struct FUN_00dc72a0_data
{
    char m_00[0x2c];
    void* m_2c;
};

struct FUN_00dc72a0_class
{
    char m_00[8];
    FUN_00dc72a0_data* m_08;

    void* __thiscall ForwardToReceiver(Receiver* m_pReceiver);
};

// @fnv 0x00dc72a0
void* FUN_00dc72a0_class::ForwardToReceiver(Receiver* m_pReceiver)
{
    m_pReceiver->FUN_009ba760(m_08->m_2c);
    return m_pReceiver;
}

namespace fnv_00dc72c0 {
struct Receiver
{
    void FUN_009ba760(void* pArg);
};

// @fnv 0x00dc72c0
void* __stdcall DispatchToReceiver(void* pObject, void** pValue)
{
    Receiver* m_pReceiver = static_cast<Receiver*>(pObject);
    m_pReceiver->FUN_009ba760(*pValue);
    return pObject;
}
}  // namespace fnv_00dc72c0

// FUN_00dcaaf0 placeholder: __thiscall member taking two pointer args (ret 8)
struct FUN_00dcaaf0_Class
{
    void UpdateObjectKeyMapping(void* a, void* b);
};

// Stand-in for the refcounted object at [edi+8] with virtual dtor (vtable slot 0)
struct FUN_00dc7cc0_RefCounted
{
    virtual void FUN_00dc7cc0_vtbl0(int);
    int m_auiShapeKeys;       // +0x4
    int m_refcount;  // +0x8
};

// Object whose vtable slot at +0x10 is called with no args, returns a pointer
struct FUN_00dc7cc0_VtblObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get();  // +0x10
};

struct FUN_00dc7cc0_Class
{
    void AssignRefCountedSlot(void** a, void** b);
};

// Increments the new reference's count, releases the old one at offset 0x18, stores the new pointer, then calls FUN_00dcaaf0 with the object's get() result.
// @fnv 0x00dc7cc0
void FUN_00dc7cc0_Class::AssignRefCountedSlot(void** a, void** apNewRef)
{
    FUN_00dc7cc0_VtblObj* obj = *(FUN_00dc7cc0_VtblObj**)a;
    void* result = obj->get();

    FUN_00dc7cc0_RefCounted** ppRefSlot = (FUN_00dc7cc0_RefCounted**)((char*)*(void**)a + 0x18);
    FUN_00dc7cc0_RefCounted* newRef = *(FUN_00dc7cc0_RefCounted**)apNewRef;

    if (newRef)
        newRef->m_refcount++;

    FUN_00dc7cc0_RefCounted* old = *ppRefSlot;
    if (old)
    {
        if (--old->m_refcount == 0)
            old->FUN_00dc7cc0_vtbl0(1);
    }
    *ppRefSlot = newRef;

    FUN_00dcaaf0_Class* self = *(FUN_00dcaaf0_Class**)((char*)this + 8);
    self->UpdateObjectKeyMapping(result, *(void**)a);
}

struct FUN_00dc89d0_vt
{
    virtual void v0();
    virtual int v1();
};
struct FUN_00dc89d0
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    FUN_00dc89d0_vt* m20;
    int __thiscall getType();
};
// @fnv 0x00dc89d0
int FUN_00dc89d0::getType()
{
    return ((FUN_00dc89d0_vt*)m20)->v1() | 0x20;
}

struct FUN_00dc8a00_Array
{
    virtual void FUN_00dc8a00_0() = 0;
    virtual void FUN_00dc8a00_1() = 0;
    virtual void FUN_00dc8a00_2() = 0;
    virtual void ArrayOfTuplesImplementation_reserve(int value) = 0;
};

struct FUN_00dc8a00_class
{
    char m_00[0x20];
    FUN_00dc8a00_Array* m_p20;
    int m_24;

    void ArrayOfTuplesImplementation_reserve(int value);
};

// @fnv 0x00dc8a00
// src: XBOX_PDB 0x00dc8a00
void FUN_00dc8a00_class::ArrayOfTuplesImplementation_reserve(int value)
{
    m_p20->ArrayOfTuplesImplementation_reserve(m_24 * value);
}

struct FUN_00dc8a20_impl
{
    virtual void FUN_00dc8a20_0();
    virtual void FUN_00dc8a20_1();
    virtual void FUN_00dc8a20_2();
    virtual void FUN_00dc8a20_3();
    virtual void FUN_00dc8a20_4(int value);
};

struct FUN_00dc8a20_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc8a20_impl* m_20;
    int m_24;

    void ArrayOfTuplesImplementation_setSize(int value);
};

// @fnv 0x00dc8a20
// src: XBOX_PDB 0x00dc8a20
void FUN_00dc8a20_class::ArrayOfTuplesImplementation_setSize(int value)
{
    m_20->FUN_00dc8a20_4(value * m_24);
}

struct FUN_00dc8a40_Inner
{
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    virtual int ArrayOfTuplesImplementation_getSize();
    virtual int FUN_00dc8a40_b();
    virtual int FUN_00dc8a40_c();
    virtual int FUN_00dc8a40_d();
    virtual int FUN_00dc8a40_e();
    virtual int FUN_00dc8a40_f();
};

struct FUN_00dc8a40_Class
{
    char m_data[0x20];
    FUN_00dc8a40_Inner* m_p20;
    int m_24;
    int ArrayOfTuplesImplementation_getSize();
};

// @fnv 0x00dc8a40
// src: XBOX_PDB 0x00dc8a40
int FUN_00dc8a40_Class::ArrayOfTuplesImplementation_getSize()
{
    int r = m_p20->FUN_00dc8a40_f();
    return r / m_24;
}

struct FUN_00dc9a20_Allocator
{
    virtual void FUN_00dc9a20_0() = 0;
    virtual void FUN_00dc9a20_1() = 0;
    virtual void FUN_00dc9a20_Deallocate(void* object, unsigned short size) = 0;
};

struct FUN_00dc9a20_Router
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    FUN_00dc9a20_Allocator* m_pThreadAllocator;
};

FUN_00dc9a20_Router* _D1A0E0GetMemoryRouter();

struct FUN_00dc9a20_class
{
    void* m_p0;
    unsigned short m_iElementCount;

    void __thiscall FUN_00dc96a0();
    unsigned long* __thiscall FUN_00dc9a20(unsigned long flags);
};

// @fnv 0x00dc9a20
unsigned long* __thiscall FUN_00dc9a20_class::FUN_00dc9a20(unsigned long flags)
{
    FUN_00dc96a0();

    if (flags & 1)
    {
        FUN_00dc9a20_Router* router = _D1A0E0GetMemoryRouter();
        router->m_pThreadAllocator->FUN_00dc9a20_Deallocate(this, m_iElementCount);
    }

    return reinterpret_cast<unsigned long*>(this);
}

struct FUN_00dc9ad0_class
{
    char m_000[0x0c];
    float* m_p0c;
    char m_010[0x08];
    int m_18;

    void __thiscall CopyRow(int multiplier, const float* source);
};

// Copies m_18 floats from source into the row at index multiplier of the float array m_p0c.
// @fnv 0x00dc9ad0
void __thiscall FUN_00dc9ad0_class::CopyRow(int aiRowIndex, const float* source)
{
    for (int i = 0; i < m_18; ++i)
        m_p0c[aiRowIndex * m_18 + i] = source[i];
}

namespace fnv_00dc9b20 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* alloc, void* ptr, int size, int align);

struct VecArrayImplementation
{
    void reserve_00dc9b20(int n);
};

// Ensures the array's capacity (low 30 bits of the third int at offset 0xc) is at least elementSize*n, doubling or growing it via the memory router's allocator.
// @fnv 0x00dc9b20
// src: XBOX_PDB 0x00dc9b20
void VecArrayImplementation::reserve_00dc9b20(int aiCount)
{
    int size = *(int*)((char*)this + 0x18) * aiCount;
    int* p = (int*)((char*)this + 0xc);
    void* router = _D1A0E0GetMemoryRouter();
    void* alloc = *(void**)((char*)router + 0x10);
    int cap = p[2] & 0x3fffffff;
    if (cap < size)
    {
        cap += cap;
        if (size >= cap)
            cap = size;
        _FUN_00c908c0(alloc, p, cap, 4);
    }
}
}  // namespace fnv_00dc9b20

namespace fnv_00dc9b60 {
struct VecArrayImplementation
{
    void* m_data;         // +0x0
    int m_iElementCount;           // +0x4
    int m_pRayCursor;       // +0x8
    int m_flags;          // +0xc
    void* m_p0;           // +0x10
    void* m_p4;           // +0x14
    int m_iElementIndex;  // +0x18
    void Resize(int count);
};

void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* allocator, void* array, int size, int align);

// @fnv 0x00dc9b60
void VecArrayImplementation::Resize(int count)
{
    int total = m_iElementIndex * count;
    int* base = (int*)((char*)this + 0xc);
    void* router = _D1A0E0GetMemoryRouter();
    void* allocator = *(void**)((char*)router + 0x10);
    int cap = base[2] & 0x3fffffff;
    if (cap < total)
    {
        int newcap = cap + cap;
        if (total >= newcap)
            newcap = total;
        _FUN_00c908c0(allocator, base, newcap, 4);
    }
    int oldsize = base[1];
    int* data = (int*)base[0];
    int diff = total - oldsize;
    int* dst = data + oldsize;
    if (diff > 0)
    {
        int zero = 0;
        int n = diff;
        while (n--)
            *dst++ = zero;
    }
    base[1] = total;
}
}  // namespace fnv_00dc9b60

namespace fnv_00dc9cd0 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* alloc, void* arr, int count, int flag);

struct FUN_00dc9cd0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void BasicArrayImplementation_unsigned_char_1_reserve(int count);
};

// Grows the array at offset 0xc to hold at least count elements, doubling capacity or using count, via the memory router's allocator.
// @fnv 0x00dc9cd0
// src: XBOX_PDB 0x00dc9cd0
void FUN_00dc9cd0_Class::BasicArrayImplementation_unsigned_char_1_reserve(int count)
{
    int* arr = (int*)((char*)this + 0xc);
    void* router = _D1A0E0GetMemoryRouter();
    int alloc = *(int*)((char*)router + 0x10);
    int cap = arr[2] & 0x3fffffff;
    if (cap < count)
    {
        int newcap = cap * 2;
        if (count >= newcap)
            newcap = count;
        _FUN_00c908c0((void*)alloc, arr, newcap, 1);
    }
}
}  // namespace fnv_00dc9cd0

namespace fnv_00dc9d70 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* allocator, void* array, int newCap, int elemSize);

struct FUN_00dc9d70_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void BasicArrayImplementation_int64_2_reserve(int newCap);
};

// Grows the array at offset 0xc to hold newCap elements, doubling the current capacity unless newCap is smaller, then reallocates via the memory router.
// @fnv 0x00dc9d70
// src: XBOX_PDB 0x00dc9d70
void FUN_00dc9d70_Class::BasicArrayImplementation_int64_2_reserve(int newCap)
{
    int* arr = (int*)((char*)this + 0xc);
    void* router = _D1A0E0GetMemoryRouter();
    void* alloc = *(void**)((char*)router + 0x10);
    int cap = arr[2] & 0x3fffffff;
    if (cap < newCap)
    {
        int iDoubledCapacity = cap + cap;
        if (!(newCap < iDoubledCapacity))
            cap = newCap;
        else
            cap = iDoubledCapacity;
        _FUN_00c908c0(alloc, arr, cap, 8);
    }
}
}  // namespace fnv_00dc9d70

struct FUN_00dca080_StandIn
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int* m_iThirdValue;
    int __thiscall GetIndexedValue_00dca080(int i);
};

// @fnv 0x00dca080
// src: GUESS 0x00dca080 (confidence: low)
int __thiscall FUN_00dca080_StandIn::GetIndexedValue_00dca080(int i)
{
    return m_iThirdValue[i];
}

extern int DAT_010d7114;
struct FUN_00dca260_Class
{
    int m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int mc;
    int m10;
    int m14;
    FUN_00dca260_Class();
};
// @fnv 0x00dca260
FUN_00dca260_Class::FUN_00dca260_Class()
{
    m6 = 0;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0x80000000;
    m0 = (int)&DAT_010d7114;
}

struct FUN_00dca280_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    __int64* m_iThirdValue;
    int __thiscall IntArrayImplementation_asInt(int index);
};
// @fnv 0x00dca280
// src: HAVOK_LIB 0x00dca280
int __thiscall FUN_00dca280_Class::IntArrayImplementation_asInt(int index)
{
    return (int)m_iThirdValue[index];
}

struct FUN_00dca290_StandIn
{
    void* m_00;
    void* m_04;
    void* m_08;
    __int64* m_0c;
    void __thiscall IntArrayImplementation_setInt(int index, int value);
};

// @fnv 0x00dca290
// src: XBOX_PDB 0x00dca290
void FUN_00dca290_StandIn::IntArrayImplementation_setInt(int index, int value)
{
    m_0c[index] = value;
}

namespace fnv_00dca4e0 {
void* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl _FUN_00c908c0(void* router, void* array, int count, int size);

struct FUN_00dca4e0_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void AssignIntArray(int* src, int count);
};

// Grows the array at this+0xc to hold count 8-byte elements, sets its size, then copies each int from src widened to 64 bits.
// @fnv 0x00dca4e0
void FUN_00dca4e0_Class::AssignIntArray(int* src, int count)
{
    char* base = (char*)this + 0xc;
    void* router = _D1A0E0GetMemoryRouter();
    int* alloc = *(int**)((char*)router + 0x10);
    int cap = *(int*)(base + 8) & 0x3fffffff;
    if (cap < count)
    {
        int newCap = cap + cap;
        if (count >= newCap)
            newCap = count;
        _FUN_00c908c0(alloc, base, newCap, 8);
    }
    *(int*)(base + 4) = count;
    for (int i = 0; i < count; ++i)
    {
        __int64 v = src[i];
        ((__int64*)*(void**)base)[i] = v;
    }
}
}  // namespace fnv_00dca4e0

extern int DAT_010d71ac;

struct FUN_00dca5a0_Class
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int m12;
    int m16;
    int m20;
    FUN_00dca5a0_Class();
};

// @fnv 0x00dca5a0
FUN_00dca5a0_Class::FUN_00dca5a0_Class()
{
    m6 = 0;
    m8 = 0;
    m12 = 0;
    m16 = 0;
    m20 = 0x80000000;
    m0 = &DAT_010d71ac;
}

extern int DAT_010d7244;

struct FUN_00dca650
{
    int* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int m12;
    int m16;
    int m20;

    FUN_00dca650();
};

// @fnv 0x00dca650
FUN_00dca650::FUN_00dca650()
{
    m6 = 0;
    m8 = 0;
    m12 = 0;
    m16 = 0;
    m20 = 0x80000000;
    m0 = &DAT_010d7244;
}

namespace fnv_00dca720 {
struct FUN_00dca720_Manager
{
    virtual void FUN_00dca720_Dummy0();
    virtual void FUN_00dca720_Dummy1();
    virtual void Free(void* p, unsigned short size);
};

struct FUN_00dca720_Router
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    FUN_00dca720_Manager* m_manager;
};

extern FUN_00dca720_Router* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00dca720_class
{
    void* m_iWordAt00;
    unsigned short m_iWordAt04;

    void FUN_00dca6b0();
    void* DestroyIfFlagged(unsigned char flag);
};

// Calls FUN_00dca6b0, then if bit 0 of flag is set frees this through the memory router's manager, and returns this.
// @fnv 0x00dca720
void* FUN_00dca720_class::DestroyIfFlagged(unsigned char flag)
{
    FUN_00dca6b0();

    if (flag & 1)
    {
        FUN_00dca720_Router* router = _D1A0E0GetMemoryRouter();
        router->m_manager->Free(this, m_iWordAt04);
    }

    return this;
}
}  // namespace fnv_00dca720

namespace fnv_00dcb0e0 {
struct FUN_00dcb0e0_Object
{
    void* vtable;
    unsigned short m_iElementCount;
    unsigned short m_flag;
    unsigned int m_zero;
    void* m_pOwnerObject;
    void* m_arg;
};

struct FUN_00dcb0e0_Allocator
{
    // Virtual destructor for the allocator stand-in; does nothing.
// @fnv 0x00dcb0e0
    virtual ~FUN_00dcb0e0_Allocator()
    {}
    virtual FUN_00dcb0e0_Object* FUN_00dcb0e0_alloc(unsigned int size);
};

struct FUN_00dcb0e0_Router
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    FUN_00dcb0e0_Allocator* m_10;
};

extern char DAT_010d7494;
extern FUN_00dcb0e0_Router* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00dcb0e0_class
{
    void* __thiscall StructArrayImplementation_asObject(void* arg);
};

// src: XBOX_PDB 0x00dcb0e0
void* FUN_00dcb0e0_class::StructArrayImplementation_asObject(void* arg)
{
    FUN_00dcb0e0_Router* router = _D1A0E0GetMemoryRouter();
    FUN_00dcb0e0_Object* object = router->m_10->FUN_00dcb0e0_alloc(0x14);

    object->m_iElementCount = 0x14;
    object->m_pOwnerObject = this;
    object->m_flag = 0;
    object->m_zero = 0;
    object->vtable = &DAT_010d7494;
    object->m_arg = arg;

    return object;
}
}  // namespace fnv_00dcb0e0

struct FUN_00dcb120_InternedString
{
    int m_iOwnerObjectOffset;
};

struct FUN_00dcb120_Inner
{
    void* m0;
    void* m4;
    void* m8;
    int m_iThirdValue;
    int m_10;
};

struct FUN_00dcb120_Class
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00dcb120_Inner* m_iThirdValue;
    int __thiscall HasMember(int member);
};

// Interns the given member name via a virtual call, then scans the inner array of up to m_10 entries for a matching id and returns 1 if found, else 0.
// @fnv 0x00dcb120
int FUN_00dcb120_Class::HasMember(int member)
{
    FUN_00dcb120_InternedString internedName;
    ((void(__thiscall*)(FUN_00dcb120_Class*, FUN_00dcb120_InternedString*, int)) *
     (void**)((char*)m0 + 0x60))(this, &internedName, member);
    FUN_00dcb120_Inner* inner = m_iThirdValue;
    int count = inner->m_10;
    int i = 0;
    if (count > 0)
    {
        int* p = (int*)inner->m_iThirdValue;
        int id = internedName.m_iOwnerObjectOffset;
        do
        {
            if (id == *p)
                return 1;
            ++i;
            p += 2;
        } while (i < count);
    }
    return 0;
}

struct FUN_00dcb250_item
{
    virtual void FUN_00dcb250_item_v0();
    virtual void FUN_00dcb250_item_v1();
    virtual void FUN_00dcb250_item_v2();
    virtual void FUN_00dcb250_item_call(void* arg);
};

struct FUN_00dcb250_entry
{
    void* m_iWordAt00;
    FUN_00dcb250_item* m_iWordAt04;
};

struct FUN_00dcb250_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb250_entry* m_iThirdValue;
    int m_10;

    void CallItems(void* arg);
};

// @fnv 0x00dcb250
void FUN_00dcb250_class::CallItems(void* arg)
{
    for (int i = 0; i < m_10; ++i)
        m_iThirdValue[i].m_iWordAt04->FUN_00dcb250_item_call(arg);
}

struct FUN_00dcb280_Elem
{
    virtual void FUN_00dcb280_0();
    virtual void FUN_00dcb280_1();
    virtual void FUN_00dcb280_2();
    virtual void FUN_00dcb280_3();
    virtual void FUN_00dcb280_4(int value);
};

struct FUN_00dcb280_Item
{
    void* m_00;
    FUN_00dcb280_Elem* m_04;
};

struct FUN_00dcb280_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dcb280_Item* m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;

    void StructArrayImplementation_setSize(int value);
};

// Stores value in m_1c, then forwards it to the element of each of the m_10 items in m_0c.
// @fnv 0x00dcb280
// src: XBOX_PDB 0x00dcb280
void FUN_00dcb280_Class::StructArrayImplementation_setSize(int value)
{
    m_1c = value;
    for (int i = 0; i < m_10; ++i)
        m_0c[i].m_04->FUN_00dcb280_4(value);
}

struct FUN_00dc9570_StandIn
{
    void __thiscall GetPooledNameOrEmpty(int a, int b);
};

struct FUN_00dcb320_Class
{
    int m_00;
    int m_04;
    int m_08;
    char* m_0c;
    int CallWithArgs(int a, int b);
};

// @fnv 0x00dcb320
int FUN_00dcb320_Class::CallWithArgs(int aiArg1, int aiArg2)
{
    FUN_00dc9570_StandIn* p = *(FUN_00dc9570_StandIn**)(m_0c + 0x18);
    p->GetPooledNameOrEmpty(aiArg1, aiArg2);
    return aiArg1;
}

struct FUN_00dcb3a0_Entry
{
    void* m_iWordAt00;
    void* m_cByteAtOffset1;
};

struct FUN_00dcb3a0_Element
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual int f22(int value)
    {
        return value;
    }
};

struct FUN_00dcb3a0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb2b0_StandIn* m_iThirdValue;
    int m_10;

    int __thiscall StructArrayImplementation_Object_asArray(int index);
};

// @fnv 0x00dcb3a0
// src: XBOX_PDB 0x00dcb3a0
int __thiscall FUN_00dcb3a0_class::StructArrayImplementation_Object_asArray(int index)
{
    int result = m_iThirdValue->StructArrayImplementation__find(index);

    int* entries = *reinterpret_cast<int**>(reinterpret_cast<char*>(m_iThirdValue) + 0xc);

    FUN_00dcb3a0_Element* element = reinterpret_cast<FUN_00dcb3a0_Element*>(entries[result * 2 + 1]);

    return element->f22(m_10);
}

struct FUN_00dcb3d0_virtual
{
    virtual int f00(int) = 0;
    virtual int f01(int) = 0;
    virtual int f02(int) = 0;
    virtual int f03(int) = 0;
    virtual int f04(int) = 0;
    virtual int f05(int) = 0;
    virtual int f06(int) = 0;
    virtual int f07(int) = 0;
    virtual int f08(int) = 0;
    virtual int f09(int) = 0;
    virtual int f10(int) = 0;
    virtual int f11(int) = 0;
    virtual int f12(int) = 0;
    virtual int f13(int) = 0;
    virtual int f14(int) = 0;
    virtual int f15(int) = 0;
    virtual int f16(int) = 0;
};

struct FUN_00dcb3d0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dcb2b0_StandIn* m_0c;
    int m_10;
    __int64 __thiscall CallVirtualOnElement(int);
};

// Looks up the element at index via m_0c, fetches the object pointer from the element array, and calls its virtual slot 16 with m_10.
// @fnv 0x00dcb3d0
__int64 __thiscall FUN_00dcb3d0_class::CallVirtualOnElement(int index)
{
    int element = m_0c->StructArrayImplementation__find(index);
    void** elements = *reinterpret_cast<void***>(reinterpret_cast<char*>(m_0c) + 0x0c);
    void* object = *reinterpret_cast<void**>(reinterpret_cast<char*>(elements) + element * 8 + 4);
    FUN_00dcb3d0_virtual* virtualObject = reinterpret_cast<FUN_00dcb3d0_virtual*>(object);
    return virtualObject->f16(m_10);
}

struct FUN_00dcb400_Target
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void target(int value) = 0;
};

struct FUN_00dcb400_Class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dcb2b0_StandIn* m_0c;
    int m_10;
    void __thiscall DispatchToIndexedTarget(int value);
};

// Looks up an index via m_0c, fetches a target pointer from the table at that index, and calls its target method with m_10.
// @fnv 0x00dcb400
void __thiscall FUN_00dcb400_Class::DispatchToIndexedTarget(int value)
{
    int index = m_0c->StructArrayImplementation__find(value);

    void* table = *(void**)((char*)m_0c + 0x0c);
    FUN_00dcb400_Target* target = *(FUN_00dcb400_Target**)((char*)table + index * 8 + 4);

    return target->target(m_10);
}

struct FUN_00dcb6f0_Object
{
// @fnv 0x00dcb6f0
    virtual void FUN_00dcb6f0_0()
    {}
    virtual void FUN_00dcb6f0_1()
    {}
    virtual void FUN_00dcb6f0_2()
    {}
    virtual void FUN_00dcb6f0_3()
    {}
    virtual void FUN_00dcb6f0_4()
    {}
    virtual void FUN_00dcb6f0_5()
    {}
    virtual void FUN_00dcb6f0_6()
    {}
    virtual void FUN_00dcb6f0_7()
    {}
    virtual void FUN_00dcb6f0_8()
    {}
    virtual void FUN_00dcb6f0_9()
    {}
    virtual void FUN_00dcb6f0_10()
    {}
    virtual void FUN_00dcb6f0_11(int, int)
    {}
};

struct FUN_00dcb5d0_Entry
{
    void* m_p0;
    FUN_00dcb6f0_Object* m_p4;
};

struct FUN_00dcb5d0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Entry* m_iThirdValue;
    int __thiscall StructArrayImplementation__findOrAdd(int);
};

struct FUN_00dcb6f0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Class* m_iThirdValue;
    int m_10;
    void __thiscall StructArrayImplementation_Object_assign_00dcb6f0(int, int);
};

// src: XBOX_PDB 0x00dcb6f0
void __thiscall FUN_00dcb6f0_Class::StructArrayImplementation_Object_assign_00dcb6f0(int arg0, int arg1)
{
    int index = m_iThirdValue->StructArrayImplementation__findOrAdd(arg0);
    m_iThirdValue->m_iThirdValue[index].m_p4->FUN_00dcb6f0_11(m_10, arg1);
}

struct FUN_00dcb790_Element;

struct FUN_00dcb790_Pair
{
    void* m_iWordAt00;
    FUN_00dcb790_Element* m_iWordAt04;
};

struct FUN_00dcb790_Element
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9(int a, int b)
    {}
};

struct FUN_00dcb5d0_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb790_Pair* m_iThirdValue;

// src: XBOX_PDB 0x00dcb5d0
    __declspec(noinline) int __thiscall StructArrayImplementation__findOrAdd(int a)
    {
        return 0;
    }
};

struct FUN_00dcb790_class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_00dcb5d0_class* m_iThirdValue;
    int m_10;

    void __thiscall DispatchToElement(int a, int b, int c);
};

// @fnv 0x00dcb790
void __thiscall FUN_00dcb790_class::DispatchToElement(int a, int b, int aiUnused)
{
    int index = m_iThirdValue->StructArrayImplementation__findOrAdd(a);
    m_iThirdValue->m_iThirdValue[index].m_iWordAt04->f9(m_10, b);
}

namespace fnv_00dcb960 {
struct FUN_00d1a0e0_vtable
{
    void* m_00;
    void* m_04;
    void(__thiscall* m_08)(void* self, void* object, unsigned short size);
};

struct FUN_00d1a0e0_memory
{
    FUN_00d1a0e0_vtable* m_ppVirtualMethodTable;
};

struct FUN_00d1a0e0_router
{
    unsigned char m_00[0x10];
    FUN_00d1a0e0_memory* m_10;
};

extern FUN_00d1a0e0_router* __cdecl _D1A0E0GetMemoryRouter();

struct StructArrayImplementation
{
    void* m_00;
    unsigned short m_04;
    void ProcessEntries_00dcb890();
    void* __thiscall FUN_00dcb960(unsigned int flags);
};

// @fnv 0x00dcb960
void* __thiscall StructArrayImplementation::FUN_00dcb960(unsigned int flags)
{
    ProcessEntries_00dcb890();

    if (flags & 1)
    {
        FUN_00d1a0e0_router* router = _D1A0E0GetMemoryRouter();
        FUN_00d1a0e0_memory* memory = router->m_10;
        memory->m_ppVirtualMethodTable->m_08(memory, this, m_04);
    }

    return this;
}
}  // namespace fnv_00dcb960

namespace fnv_00dcbf90 {
struct FUN_00dc8080_Class
{
    void* m_00;
    unsigned short m_04;
    void ReleaseStorage_00dc8080();
};

struct FUN_00dcbf90_router
{
    virtual void FUN_00dcbf90_router_0();
    virtual void FUN_00dcbf90_router_1();
    virtual void FUN_00dcbf90_router_2(void* object, unsigned short size);
};

struct FUN_00dcbf90_manager
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    FUN_00dcbf90_router* m_10;
};

FUN_00dcbf90_manager* _D1A0E0GetMemoryRouter();

struct FUN_00dcbf90_class : FUN_00dc8080_Class
{
    FUN_00dcbf90_class* FUN_00dcbf90(char flags);
};

// Calls FUN_00dc8080, then if flags bit 0 is set, passes this and m_04 to the memory router's virtual function, and returns this.
// @fnv 0x00dcbf90
FUN_00dcbf90_class* FUN_00dcbf90_class::FUN_00dcbf90(char flags)
{
    ReleaseStorage_00dc8080();

    if (flags & 1)
    {
        FUN_00dcbf90_manager* manager = _D1A0E0GetMemoryRouter();
        manager->m_10->FUN_00dcbf90_router_2(this, m_04);
    }

    return this;
}
}  // namespace fnv_00dcbf90

struct FUN_00dc6fe0_inner
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
};

struct FUN_00dc6fe0_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00dc6fe0_inner* m_0c;
    int ArrayOfTuplesImplementation_View_getSize();
};

// @fnv 0x00dc6fe0
// src: XBOX_PDB 0x00dc6fe0
int FUN_00dc6fe0_cls::ArrayOfTuplesImplementation_View_getSize()
{
    return m_0c->m_24;
}

struct FnvCpu_FUN_00dc7390_CpuTarget
{
    void hkDataWorldDict_ObjectTracker_findTrackedClasses();
};
struct FnvCpu_FUN_00dc7390_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00dc7390_CpuTarget* target;
    void hkDataWorldDict_findAllClasses();
};
// @fnv 0x00dc7390
// src: HAVOK_SRC 0x00dc7390
void FnvCpu_FUN_00dc7390_CpuOwner::hkDataWorldDict_findAllClasses()
{
    target->hkDataWorldDict_ObjectTracker_findTrackedClasses();
}

struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    CpuInterface* target;
    void ArrayOfTuplesImplementation_getClass();
};
// @fnv 0x00dc89e0
// src: XBOX_PDB 0x00dc89e0
void CpuObject::ArrayOfTuplesImplementation_getClass()
{
    target->Invoke();
}

namespace fnv_00dc89f0 {
struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    CpuInterface* target;
    void ArrayOfTuplesImplementation_clear();
};
// @fnv 0x00dc89f0
// src: XBOX_PDB 0x00dc89f0
void CpuObject::ArrayOfTuplesImplementation_clear()
{
    target->Invoke();
}
}  // namespace fnv_00dc89f0

struct FUN_00dc9b00_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int VecArrayImplementation_getSize();
};

// @fnv 0x00dc9b00
// src: XBOX_PDB 0x00dc9b00
int FUN_00dc9b00_cls::VecArrayImplementation_getSize()
{
    return m_10 / m_18;
}

struct FUN_00dc9b10_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void ClearField10();
};

// @fnv 0x00dc9b10
// src: GUESS 0x00dc9b10 (confidence: low)
void FUN_00dc9b10_cls::ClearField10()
{
    m_10 = 0;
}

namespace fnv_00dcac10 {
struct CpuScalar
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
};
}  // namespace fnv_00dcac10
// @fnv 0x00dcac10
const char* hkDataClassDict::getName() const
{
    return reinterpret_cast<const char*>(reinterpret_cast<const fnv_00dcac10::CpuScalar*>(m_name)->value);
}

struct FUN_00dc70c0_Target
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual int V10(unsigned char* pucData);
};

struct FUN_00dc70c0_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc70c0_Target* m_20;
};

struct FUN_00dc70c0_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc70c0_Holder* m_0c;
    unsigned char* m_10;

    int ArrayOfTuplesImplementation_View_asString(int iOffset);
};

// @fnv 0x00dc70c0
// src: XBOX_PDB 0x00dc70c0
int FUN_00dc70c0_cls::ArrayOfTuplesImplementation_View_asString(int iOffset)
{
    return m_0c->m_20->V10(m_10 + iOffset);
}

struct FUN_00dc7130_Target
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual int V13(unsigned char* pucData, float fValue);
};

struct FUN_00dc7130_Holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc7130_Target* m_20;
};

struct FUN_00dc7130_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc7130_Holder* m_0c;
    unsigned char* m_10;

    int ArrayOfTuplesImplementation_View_setReal(int iOffset, float fValue);
};

// Forwards to the target's V13 with the buffer at m_10 plus iOffset and fValue, returning its result.
// @fnv 0x00dc7130
// src: XBOX_PDB 0x00dc7130
int FUN_00dc7130_cls::ArrayOfTuplesImplementation_View_setReal(int iOffset, float fValue)
{
    return m_0c->m_20->V13(m_10 + iOffset, fValue);
}

struct DispatchInterface
{
    virtual int slot00() = 0;
    virtual int slot04() = 0;
    virtual int slot08() = 0;
    virtual int slot0c() = 0;
    virtual int slot10() = 0;
    virtual int slot14() = 0;
    virtual int slot18() = 0;
    virtual int slot1c() = 0;
    virtual int slot20() = 0;
    virtual int slot24() = 0;
    virtual int slot28() = 0;
    virtual int slot2c() = 0;
    virtual int slot30() = 0;
    virtual int slot34() = 0;
    virtual int slot38() = 0;
    virtual int slot3c() = 0;
    virtual int Dispatch(int address) = 0;
};
struct DispatchHolder
{
    void* member00;
    void* member04;
    void* member08;
    void* member0c;
    void* member10;
    void* member14;
    void* member18;
    void* member1c;
    DispatchInterface* volatile member20;
};
struct DispatchAdapter
{
    void* member00;
    void* member04;
    void* member08;
    DispatchHolder* member0c;
    int member10;
    int DispatchAtOffset(int offset);
};
// @fnv 0x00dc7160
int DispatchAdapter::DispatchAtOffset(int offset)
{
    DispatchInterface* pInterface = member0c->member20;
    return pInterface->Dispatch(member10 + offset);
}

struct FUN_00dc71d0_target
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual int v19(int, int, int) = 0;
};
struct FUN_00dc71d0_holder
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    FUN_00dc71d0_target* m_20;
};
struct FUN_00dc71d0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    FUN_00dc71d0_holder* m_0c;
    int m_10;

    int InvokeTargetVirtual(int a, int b, int c);
};
// Forwards the call to the target object's v19 with m_10 added to the first argument.
// @fnv 0x00dc71d0
int FUN_00dc71d0_class::InvokeTargetVirtual(int aiOffset, int aiArg2, int aiArg3)
{
    return m_0c->m_20->v19(m_10 + aiOffset, aiArg2, aiArg3);
}

class hkStreamDC72
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual int seekTo(int iOffset);
    virtual void V21();
    virtual int tellFrom(int iOffset);
};

struct hkStreamHolderDC72
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkStreamDC72* m_stream;
};

class hkSubStreamDC72
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStreamHolderDC72* m_holder;
    int m_baseOffset;

    int SeekTo(int iOffset);
};

// @fnv 0x00dc7200
int hkSubStreamDC72::SeekTo(int iOffset)
{
    return m_holder->m_stream->seekTo(m_baseOffset + iOffset);
}

class hkStreamDC7B
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual int seekTo(int iOffset);
    virtual void V21();
    virtual int tellFrom(int iOffset);
};

struct hkStreamHolderDC7B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkStreamDC7B* m_stream;
};

class hkSubStreamDC7B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStreamHolderDC7B* m_holder;
    int m_baseOffset;

    int TellFromOffset(int iOffset);
};

// @fnv 0x00dc7250
int hkSubStreamDC7B::TellFromOffset(int iOffset)
{
    return m_holder->m_stream->tellFrom(m_baseOffset + iOffset);
}

struct DC7300Callee
{
    void* GetValue(void* a, int b);
};

class DC7300Owner
{
  public:
    int unk00;
    int unk04;
    DC7300Callee* m_callee;

    void* hkDataWorldDict_findClass(void* p);
};

// @fnv 0x00dc7300
// src: HAVOK_SRC 0x00dc7300
void* DC7300Owner::hkDataWorldDict_findClass(void* p)
{
    DC7300Callee* callee = m_callee;
    if (p)
        return callee->GetValue(p, 0);
    return 0;
}

struct FUN_00dc92d0_Obj
{
    int __thiscall CollectShapes(int a, int b, int c, int* d);
};

struct FUN_00dc73a0_Holder
{
    int unk00;
    int unk04;
    FUN_00dc92d0_Obj* unk08;
    void __thiscall CallWithReset(int a, int* b);
};

// Resets b[1] to 0 and forwards a, 0, 1 and b to the object stored at unk08.
// @fnv 0x00dc73a0
void FUN_00dc73a0_Holder::CallWithReset(int a, int* pBuffer)
{
    FUN_00dc92d0_Obj* o = unk08;
    o->CollectShapes(a, (pBuffer[1] = 0, 0), 1, pBuffer);
}

struct FUN_00dc92d0_StandIn
{
    int CollectShapes(int, int, int, int);
};

struct FUN_00dc73c0_class
{
    void* m0;
    void* m4;
    FUN_00dc92d0_StandIn* m8;
    int InitAndRun(int a, int b);
};

// Clears the int at offset 4 of b, then calls CollectShapes on m8 with a, 1, 1, b and returns its result.
// @fnv 0x00dc73c0
int FUN_00dc73c0_class::InitAndRun(int aiArg, int b)
{
    FUN_00dc92d0_StandIn* m = m8;
    *(int*)(b + 4) = 0;
    return m->CollectShapes(aiArg, 1, 1, b);
}

struct hkAllocatorDC76
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC76
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    hkAllocatorDC76* m_pkHeap;
    hkAllocatorDC76& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDC76* __cdecl hkMemoryRouter_getInstance() throw();
extern "C" char* __cdecl hkString_strDup_00cb1410(const char* pcStr) throw();

template <typename T>
__forceinline void hkArrayUtil::destruct(T* t, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

template <class T> __forceinline void hkArrayBase<T>::clear()
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsClass());
    m_iElementCount = 0;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkAllocatorDC76& kAlloc = hkMemoryRouter_getInstance()->heap();
    this->clear();
    if ((this->m_iCapacityState & 0x80000000) == 0)
        kAlloc.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap());
}

// Explicit-release owners use hkArrayBase so cleanup occurs at the original point in their destructor.
template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& kAlloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T>
__forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& e, hkTypeIsPod)
{
    for (int i = 0; i < n; ++i)
        p[i] = e;
}

void __cdecl ResizeAudioStream(hkMemoryAllocator* allocator, void* array, int elementSize);
template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& kAlloc, const T& e)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(kAlloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, e, hkTypeIsPod());
    ++m_iElementCount;
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCap = getCapacity();
    if (iCap < n)
    {
        int iCap2 = 2 * iCap;
        int iNewCap = (n < iCap2) ? iCap2 : n;
        hkArrayUtil::_reserve(kAlloc, this, iNewCap, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& kAlloc, int n)
{
    GrowArrayCapacity(kAlloc, n);
    m_iElementCount = n;
}

class FUN_00d47a80_class
{
  public:
    void* GetValue(const void* pvKey, int iDefault) throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, const void* pvValue) throw();
};

// Calls 0x00dc9470, the concrete class dictionary member remover, not hkDataClassImpl.


// Calls 0x00dc90f0, the concrete object dictionary member remover, not hkDataObjectImpl.
class ObjectDictionaryMemberRemoval
{
  public:
    void RemoveEntryAndCompact(const char* pcName) throw();
};

// Calls 0x00dc8ea0, which removes an 8-byte named array column, not a generic hkDataArrayImpl operation.
class StructArrayMemberRemoval
{
  public:
    void RemoveKeyedEntry(const char* pcName) throw();
};

class FUN_00dba680_cls
{
  public:
    hkDataClassDict* m_pClassImpl;
    const void* hkDataClass_getName() throw();
};

// String pool at 0x4c and collection calls at 0x00dc9180 identify the dictionary tracker view.
class DictionaryMemberRemovalTracker
{
  public:
    int m_00[0x13];
    FUN_00d47a80_class m_stringPool;

    void CollectShapes(const void* pvClass, int iRecurse, int iUnk,
                       hkArray<ObjectDictionaryMemberRemoval*>& kObjectsOut) throw();
    void CollectSlotIdsRecursively(hkDataClassDict* pkClass, int iRecurse,
                      hkArray<StructArrayMemberRemoval*>& kArraysOut) throw();

    const char* InternString(const char* pcStr)
    {
        if (pcStr)
        {
            const char* pcPooled = (const char*)m_stringPool.GetValue(pcStr, 0);
            if (pcPooled == 0)
            {
                pcPooled = hkString_strDup_00cb1410(pcStr);
                m_stringPool.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pcPooled, pcPooled);
            }
            return pcPooled;
        }
        return 0;
    }
    void GetObjectsOfClass(const void* pvClass, hkArray<ObjectDictionaryMemberRemoval*>& kObjectsOut)
    {
        kObjectsOut.clear();
        CollectShapes(pvClass, 1, 0, kObjectsOut);
    }
};

// Tracker at 0x08 gives the 12-byte dictionary-world layout; Xbox hkDataWorld is 8 bytes.
class DictionaryWorldMemberRemoval
{
  public:
    int m_00;
    int m_04;
    DictionaryMemberRemovalTracker* m_pClassImpl;

    void ProcessEntries_00dc7600(FUN_00dba680_cls& kClass, const char* pcName) throw();
};

// @fnv 0x00dc7600
// src: GUESS 0x00dc7600 (confidence: low)
void DictionaryWorldMemberRemoval::ProcessEntries_00dc7600(FUN_00dba680_cls& kClass, const char* pcName) throw()
{
    hkDataClassDict* pkClassImpl = kClass.m_pClassImpl;
    const char* pcNewName = m_pClassImpl->InternString(pcName);
    hkArray<ObjectDictionaryMemberRemoval*> kObjects;
    m_pClassImpl->GetObjectsOfClass(kClass.hkDataClass_getName(), kObjects);
    for (int i = 0; i < kObjects.GetLogicalSize(); i++)
        kObjects[i]->RemoveEntryAndCompact(pcNewName);
    hkArray<StructArrayMemberRemoval*> kArrays;
    m_pClassImpl->CollectSlotIdsRecursively(pkClassImpl, 1, kArrays);
    for (int i = 0; i < kArrays.GetLogicalSize(); i++)
        kArrays[i]->RemoveKeyedEntry(pcNewName);
    pkClassImpl->FUN_00dc9470(pcNewName);
}

struct FUN_00dcab50_StandIn
{
    int m0;
    int m4;
    int m8;
    void __thiscall RenameMappedObject(int a, int b);
};
struct FUN_00dc7dc0_StandIn
{
    int m0;
    int m4;
    int m8;
    void __thiscall hkDataWorldDict_castObject(int a, int b);
};
// @fnv 0x00dc7dc0
// src: XBOX_PDB 0x00dc7dc0
void FUN_00dc7dc0_StandIn::hkDataWorldDict_castObject(int piA, int piB)
{
    ((FUN_00dcab50_StandIn*)*(int**)((char*)this + 8))->RenameMappedObject(*(int*)piA, *(int*)piB);
}

namespace fnv_00dc8030 {
extern "C" void* DAT_010d7510[];
struct FUN_00dc8030_Allocator
{
    virtual void slot0();
    virtual void* Allocate(unsigned int bytes);
};
struct FUN_00dc8030_Memory
{
    int unk00, unk04, unk08, unk0c;
    FUN_00dc8030_Allocator* allocator;
};
extern "C" FUN_00dc8030_Memory* __cdecl hkMemoryRouter_getInstance();
struct FUN_00dc7fd0_Class
{
    int unk00;
};
extern "C" FUN_00dc7fd0_Class* __fastcall Initialize(FUN_00dc7fd0_Class*);
struct FUN_00dc8030_Class
{
    void** vtable;
    unsigned short allocationSize, refCount;
    FUN_00dc7fd0_Class* owned;
    FUN_00dc8030_Class* __thiscall hkDataWorldDict_hkDataWorldDict();
};
// Sets refCount to 1 and the vtable, then allocates 0x88 bytes and stores the constructed object in owned.
// @fnv 0x00dc8030
// src: XBOX_PDB 0x00dc8030
FUN_00dc8030_Class* __thiscall FUN_00dc8030_Class::hkDataWorldDict_hkDataWorldDict()
{
    refCount = 1;
    vtable = DAT_010d7510;
    FUN_00dc8030_Memory* pMemory = hkMemoryRouter_getInstance();
    FUN_00dc8030_Allocator* allocator = pMemory->allocator;
    FUN_00dc7fd0_Class* p = (FUN_00dc7fd0_Class*)allocator->Allocate(0x88);
    owned = p ? Initialize(p) : (FUN_00dc7fd0_Class*)0;
    return this;
}
}  // namespace fnv_00dc8030

namespace fnv_00dc80c0 {

struct SkRefPtr
{
    hkReferencedObject* m_pRetainedObject;
    SkRefPtr()
    {}
    SkRefPtr(const SkRefPtr& rp)
    {
        if (rp.m_pRetainedObject)
        {
            rp.m_pRetainedObject->addReference();
        }
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~SkRefPtr()
    {
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = 0;
    }
};

BSAudio* hkMemoryRouter_getInstance();
extern "C" char* hkString_strDup_00cb1410(const char* str) throw();

struct FUN_00d47a80_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void* GetValue(void* key, int def) throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, int value) throw();
};

struct SkShared
{
    virtual void Release(int flags);
    unsigned short m_iElementCount;
    unsigned short m_flags;
    int m_iObjectReferenceCount;
};

struct SkOwner;

inline hkDataClassDict* AllocateDataClassDict(int size)
{
    hkDataClassDict* p = (hkDataClassDict*)hkMemoryRouter_getInstance()->heap().blockAlloc(size);
    p->m_memSize = (unsigned short)size;
    return p;
}

struct SkStore
{
    FUN_00d47a80_class m_map;
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
    FUN_00d47a80_class m_ppNames;

    void RegisterObject(hkDataClassDict* item);
    SkRefPtr* FindOrCreateTypeEntry(SkRefPtr* out, void* key) throw();

    char* Intern(char* str)
    {
        return str ? Lookup(str) : 0;
    }

    char* Lookup(char* str)
    {
        char* name = (char*)m_ppNames.GetValue(str, 0);
        if (!name)
        {
            name = hkString_strDup_00cb1410(str);
            m_ppNames.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(name, (int)name);
        }
        return name;
    }
};

struct SkEntry
{
    char* name;
    int unk04;
    int unk08;
    void* key;
};

struct SkDesc
{
    int unk00;
    int unk04;
    void* shared;
    SkEntry* entries;
    int count;
};

struct SkOwner
{
    int unk00;
    int unk04;
    SkStore* m_store;

    hkDataClassDict* CreateItem(SkDesc* desc);
};

// Allocates a hkDataClassDict from desc, resolves and reference-counts its shared object, registers it in the store, then adds each desc entry via Intern and FUN_00dc8d70.
// @fnv 0x00dc80c0
hkDataClassDict* SkOwner::CreateItem(SkDesc* desc)
{
    hkDataClassDict* mem = AllocateDataClassDict(sizeof(hkDataClassDict));
    hkDataClassDict* item = reinterpret_cast<hkDataClassDict* (__thiscall*)(hkDataClassDict*, hkDataWorldDict*, const char*, int)>(ConstructDataClassDict)(mem, reinterpret_cast<hkDataWorldDict*>(this), reinterpret_cast<const char*>(desc->unk00), desc->unk04);
    if (desc->shared)
    {
        SkShared* shared = (SkShared*)m_store->m_map.GetValue(desc->shared, 0);
        if (shared)
        {
            shared->m_iObjectReferenceCount++;
        }
        SkShared* old = reinterpret_cast<SkShared*>(item->parent);
        if (old)
        {
            if (--old->m_iObjectReferenceCount == 0)
            {
                old->Release(1);
            }
        }
        item->parent = reinterpret_cast<hkDataClassDict*>(shared);
    }
    item->m_count++;
    m_store->RegisterObject(item);
    for (int i = 0; i < desc->count; i++)
    {
        SkEntry* entry = &desc->entries[i];
        char* name = m_store->Intern(entry->name);
        SkRefPtr ref;
        item->FUN_00dc9f20(name, entry->unk04, *reinterpret_cast<const hkRefPtrDC82<hkRefObjDC82>*>(m_store->FindOrCreateTypeEntry(&ref, entry->key)), entry->unk08);
    }
    return item;
}
}  // namespace fnv_00dc80c0

struct hkRefObjDC88
{
    virtual void deletingDtor(unsigned int flags);
    int unk04;
    int m_iObjectReferenceCount;
};

struct FUN_00dba660
{
    hkRefObjDC88* m_ptr;
    ~FUN_00dba660() throw();
};

struct FUN_00dba650 : public FUN_00dba660
{
    FUN_00dba650(hkRefObjDC88* p) throw();
};

struct FUN_00dcbdd0_cls
{
    void hkDataWorldDict_ObjectTracker_untrackClass(hkRefObjDC88* p);
};

struct hkObjDC88
{
    int unk00;
    int unk04;
    FUN_00dcbdd0_cls* m_08;

    void ReleaseRef(FUN_00dba660& handle);
};

// Clears the handle, notifies m_08 with the old pointer, and destroys the referenced object when its reference count reaches zero.
// @fnv 0x00dc8870
void hkObjDC88::ReleaseRef(FUN_00dba660& handle)
{
    hkRefObjDC88* p = handle.m_ptr;
    {
        FUN_00dba650 empty(0);
        handle = empty;
    }
    m_08->hkDataWorldDict_ObjectTracker_untrackClass(p);
    if (--p->m_iObjectReferenceCount == 0)
        p->deletingDtor(1);
}

namespace fnv_00dc88c0 {
struct hkAllocatorDC88
{
    virtual void V0();
    virtual void V1();
    virtual void ReleaseBlock(void* p, int iNumBytes);
};

struct hkMemoryRouterDC88
{
    char m_acUnk00[0x10];
    hkAllocatorDC88* m_pkHeap;
    hkAllocatorDC88& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDC88* __cdecl hkMemoryRouter_getInstance();

void hkString_strFree(int iString);

union hkDataValueDC88
{
    void* m_pResource;
    hkDataRefCounted* m_pkRef;
    int m_iString;
    double m_dPad;
};

// @fnv 0x00dc88c0
void __cdecl ReleaseDataValues(int iType, hkDataValueDC88* pkValues, int iCount)
{
    if (iType & 0x30)
    {
        hkDataRefCounted* pkArray = pkValues->m_pkRef;
        if (pkArray)
            pkArray->removeReference();
        return;
    }
    switch (iType)
    {
    case 4:
    case 6:
    case 7:
        for (int i = 0; i < iCount; i++)
        {
            void* pvData = pkValues[i].m_pResource;
            if (pvData)
            {
                hkMemoryRouter_getInstance()->heap().ReleaseBlock(pvData, (iType - 3) << 4);
                pkValues[i].m_pResource = 0;
            }
        }
        break;
    case 8:
    case 9:
        for (int i = 0; i < iCount; i++)
        {
            if (pkValues[i].m_pkRef)
            {
                pkValues[i].m_pkRef->removeReference();
                pkValues[i].m_pkRef = 0;
            }
        }
        break;
    case 10:
        for (int i = 0; i < iCount; i++)
        {
            hkString_strFree(pkValues[i].m_iString);
            pkValues[i].m_iString = 0;
        }
        break;
    }
}
}  // namespace fnv_00dc88c0

namespace fnv_00dc8d20 {
extern "C" char* __cdecl hkString_strDup_00cb1410(const char* s) throw();

struct FUN_00d47a80_class
{
    void* GetValue(void* a, int b);
};

struct FUN_00d874d0_s : public FUN_00d47a80_class
{
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, int value);
};

struct hkPooledStringDC8D
{
    const char* m_kStringBuffer;
    hkPooledStringDC8D()
    {}
};

struct hkObjDC8D
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
    FUN_00d874d0_s m_kNodePool;

    hkPooledStringDC8D GetPooledString(const char* name);
};

// Looks up name in the string pool, inserting it via FUN_00cb1410 if absent, and returns a pooled string holding the result (or null when name is null).
// @fnv 0x00dc8d20
hkPooledStringDC8D hkObjDC8D::GetPooledString(const char* name)
{
    hkPooledStringDC8D result;
    if (name)
    {
        char* s = (char*)m_kNodePool.GetValue((void*)name, 0);
        if (!s)
        {
            s = hkString_strDup_00cb1410(name);
            m_kNodePool.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(s, (int)s);
        }
        result.m_kStringBuffer = s;
    }
    else
    {
        result.m_kStringBuffer = 0;
    }
    return result;
}
}  // namespace fnv_00dc8d20

struct FUN_00dc8fe0_entry
{
    int key;
    int next;
};

struct FUN_00dc8fe0_class
{
    FUN_00dc8fe0_entry* m_iWordAt00;

    void hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(void* key, int index);
    void __thiscall hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_removeByValue(void* key, int* value);
};

int __stdcall LookupWithDefault(void* key);

// @fnv 0x00dc8fe0
// src: XBOX_PDB 0x00dc8fe0
void FUN_00dc8fe0_class::hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_removeByValue(void* key, int* piValue)
{
    int index = LookupWithDefault(key);

    if (index == -1)
        return;

    int wanted = *piValue;
    FUN_00dc8fe0_entry* entries = m_iWordAt00;

compare:
    if (entries[index].key == wanted)
    {
        hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(key, index);
        return;
    }

    index = entries[index].next;
    if (index != -1)
        goto compare;
}

struct hkMapPairDC90
{
    int key;
    int val;
};

struct FUN_00cb18f0_t
{
    hkMapPairDC90* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int FindSlot(int key);
    int RemoveEntry(int it);
};

struct hkLinkDC90
{
    int m_uiFilterValue;
    int m_next;
};

class hkMultiMapDC90
{
  public:
    hkLinkDC90* m_ppLinks;
    int unk04;
    int unk08;
    FUN_00cb18f0_t m_pHashFunction;
    int m_kFreeListEntries;

    void RemoveKey(int key);
};

// Looks up key in the map, unlinks its entry, and moves the entry's chain to the front of the free list.
// @fnv 0x00dc9030
void hkMultiMapDC90::RemoveKey(int key)
{
    int it = m_pHashFunction.FindSlot(key);
    int first = m_pHashFunction.m_kPrimitiveElement[it].val;
    m_pHashFunction.RemoveEntry(it);
    if (first != -1)
    {
        int last = first;
        while (m_ppLinks[last].m_next != -1)
            last = m_ppLinks[last].m_next;
        m_ppLinks[last].m_next = m_kFreeListEntries;
        m_kFreeListEntries = first;
    }
}

namespace fnv_00dc96a0 {
class hkMemoryAllocatorDC96
{
  public:
    virtual ~hkMemoryAllocatorDC96() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC96
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC96* m_pStreamAllocator;
    hkMemoryAllocatorDC96& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC96& __cdecl hkMemoryRouter_getInstance() throw();


// 16-byte object member storage (value at 0x08); Xbox PDB hkEntry is a distinct 12-byte type.
struct ObjectMemberStorageWords
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

class hkBaseDC96
{
  public:
    virtual ~hkBaseDC96() throw()
    {}
};

class FUN_00dc96a0 : public hkBaseDC96
{
  public:
    virtual ~FUN_00dc96a0() throw();
    void selfDestruct() throw();

    int m_04;
    int m_08;
    hkDataRefCounted* m_ref;
    hkArrayBase<ObjectMemberStorageWords> m_entries;
};

// Releases the entry array, decrements the reference count and deletes the referenced object when it reaches zero, then clears m_ref.
// @fnv 0x00dc96a0
FUN_00dc96a0::~FUN_00dc96a0() throw()
{
    selfDestruct();
    m_entries._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
    hkDataRefCounted* pCounted = m_ref;
    if (pCounted)
    {
        pCounted->removeReference();
    }
    m_ref = 0;
}
}  // namespace fnv_00dc96a0

struct FUN_00dc9710_Obj
{
    void __thiscall hkDataObjectDict__writeAccess(int* out, int value, int count);
};

struct FUN_00dc97f0_Class : public FUN_00dc9710_Obj
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;

    void __thiscall SetSlotValue(int index, void* value);
};

// @fnv 0x00dc97f0
void FUN_00dc97f0_Class::SetSlotValue(int index, void* value)
{
    int local[2];

    if (value != 0)
    {
        ++(*(int*)((char*)value + 8));
    }

    hkDataObjectDict__writeAccess(local, index, 8);

    *(int*)((char*)m_10 + local[1] * 16 + 8) = (int)value;
}

struct FUN_00dc9830_Object
{
    virtual void vf00();
    virtual int vf04();
    int m_08;
};

struct FUN_00dc9830_Local
{
    int unk00;
    int unk04;
};

struct FUN_00dc9830_Class
{
    void* m_00;
    void* m_04;
    int m_08;
    void* m_0c;
    void* m_10;

    void __thiscall hkDataObjectDict__writeAccess(void* a, int b, int c);
    void __thiscall AddObjectToSlot(int value, FUN_00dc9830_Object* obj);
};

// Increments obj's counter, calls obj->vf04(), runs FUN_00dc9710 with value and result|0x10, then stores obj in m_10 at the slot indexed by local.unk04.
// @fnv 0x00dc9830
void __thiscall FUN_00dc9830_Class::AddObjectToSlot(int value, FUN_00dc9830_Object* pObject)
{
    ++*(int*)((char*)pObject + 8);

    int result = pObject->vf04();

    FUN_00dc9830_Local local;
    hkDataObjectDict__writeAccess(&local, value, result | 0x10);

    *(int*)((char*)m_10 + (local.unk04 << 4) + 8) = (int)pObject;
}

extern "C" char* __cdecl hkString_strDup_00cb1410(const char* pcString);

struct hkResultDC98
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDC98()
    {}
};

// 0x00dc9880 writes a string at 0x08 with 16-byte stride; Xbox PDB hkEntry is 12 bytes.
struct ObjectStringMemberStorage
{
    int m_key;
    int m_04;
    char* m_uiFilterValue;
    int m_0c;
};

class hkObjDC98
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    ObjectStringMemberStorage* m_entries;

    hkResultDC98 hkDataObjectDict__writeAccess(int iKey, int iType) throw();
    void SetStringEntry(int iKey, const char* pcValue) throw();
};

// @fnv 0x00dc9880
void hkObjDC98::SetStringEntry(int iKey, const char* pcValue) throw()
{
    hkResultDC98 kRes = hkDataObjectDict__writeAccess(iKey, 10);
    m_entries[kRes.m_uiEdgeIndex].m_uiFilterValue = pcValue ? hkString_strDup_00cb1410(pcValue) : 0;
}

struct FUN_00dc98d0_Local
{
    float value;
    int index;
};

struct FUN_00dc98d0_StandIn
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;

    void hkDataObjectDict__writeAccess(float* out, int a, int b);
    void SetValueAt(int index, float value);
};

// Looks up the slot for index via FUN_00dc9710 and writes value into the float at offset 8 of that slot in m10.
// @fnv 0x00dc98d0
void FUN_00dc98d0_StandIn::SetValueAt(int index, float value)
{
    FUN_00dc98d0_Local result;

    this->hkDataObjectDict__writeAccess(&result.value, index, 3);

    *reinterpret_cast<float*>(reinterpret_cast<char*>(this->m10) + result.index * 16 + 8) = value;
}

struct hkHalfDC99
{
    short m_uiFilterValue;
    operator float() const
    {
        int t = m_uiFilterValue << 16;
        return *reinterpret_cast<float*>(&t);
    }
};

struct hkResultDC99
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDC99()
    {}
};

// 0x00dc9910 writes a real at 0x08 with 16-byte stride; Xbox PDB hkEntry is 12 bytes.
struct ObjectRealMemberStorage
{
    int m_key;
    int m_04;
    float m_uiFilterValue;
    int m_0c;
};

class hkObjDC99
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    ObjectRealMemberStorage* m_entries;

    hkResultDC99 hkDataObjectDict__writeAccess(int iKey, int iType) throw();
    void SetEntryValue(int iKey, hkHalfDC99 kValue) throw();
};

// Looks up the entry for iKey with type 3 and stores kValue into that entry's float field.
// @fnv 0x00dc9910
void hkObjDC99::SetEntryValue(int iKey, hkHalfDC99 kValue) throw()
{
    hkResultDC99 kRes = hkDataObjectDict__writeAccess(iKey, 3);
    m_entries[kRes.m_uiEdgeIndex].m_uiFilterValue = kValue;
}

struct hkMemberInfoDC99
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_type;
};

struct hkResultDC99C
{
    hkMemberInfoDC99* m_item;
    int m_uiEdgeIndex;
    hkResultDC99C()
    {}
};

// The value at +0x08 belongs to a 16-byte dictionary member record; hkEntry is 12 bytes.
struct IntegerOrRealMemberData
{
    int m_key;
    int m_04;
    union
    {
        __int64 m_int;
        float m_vValue;
    };
};

class hkObjDC99C
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    IntegerOrRealMemberData* m_entries;

    hkResultDC99C hkDataObjectDict__writeAccess(int iKey, int iType) throw();
    void hkDataObjectDict_assign_00dc99c0(int iKey, __int64 iValue) throw();
};

// Looks up the entry for iKey, then stores iValue into it as an integer or float depending on the member type.
// @fnv 0x00dc99c0
// src: XBOX_PDB 0x00dc99c0
void hkObjDC99C::hkDataObjectDict_assign_00dc99c0(int iKey, __int64 iValue) throw()
{
    hkResultDC99C kRes = hkDataObjectDict__writeAccess(iKey, 0);
    IntegerOrRealMemberData& kEntry = m_entries[kRes.m_uiEdgeIndex];
    int iType = kRes.m_item->m_type;
    switch (iType)
    {
    case 1:
    case 2:
        kEntry.m_int = iValue;
        break;
    case 3:
        kEntry.m_vValue = static_cast<float>(iValue);
        break;
    }
}

class hkBaseDC9A
{
  public:
    hkBaseDC9A() : m_06(0), m_08(0)
    {}
    virtual ~hkBaseDC9A() throw();

    unsigned short m_04;
    unsigned short m_06;
    int m_08;
};

class FUN_00dc9a50 : public hkBaseDC9A
{
  public:
    FUN_00dc9a50(int iArg) throw();
    virtual ~FUN_00dc9a50() throw();

    hkArray<int> m_ppData;
    int m_18;
};

// Constructs the object, storing iArg into m_18; the base and array members are default-initialised.
// @fnv 0x00dc9a50
FUN_00dc9a50::FUN_00dc9a50(int iArg) throw() : m_18(iArg)
{}

struct FUN_00dc9a80_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_type;

    int GetTypeCode() const;
};

// Maps m_type (4, 12, 16) to 4, 6, 7 respectively, returning 0 for any other value.
// @fnv 0x00dc9a80
int FUN_00dc9a80_cls::GetTypeCode() const
{
    switch (m_type)
    {
    case 4:
        return 4;
    case 12:
        return 6;
    case 16:
        return 7;
    default:
        return 0;
    }
}

namespace fnv_00dc9c20 {
struct FnvAllocator;
struct FnvMemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FnvAllocator* m_pStreamAllocator;
};
FnvMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvNodeValue
{
    int unk00;
    int unk04;
    void* m_uiFilterValue;
};
struct FnvNode
{
    int m_iOwnerObjectOffset;
    FnvNodeValue* m_keySource;
    int unk08;
    int unk0c;
    void* m_iValueAtOffset0C;
    int m_flags;
};
struct FnvEntry
{
    int m_iOwnerObjectOffset;
    struct FnvRefCounted* m_object;
};
struct FnvEntries
{
    FnvEntry* m_data;
    int m_iElementCount;
    int m_pRayCursor;
};
void __cdecl ResizeAudioStream(FnvAllocator*, FnvEntries*, unsigned int);
struct FnvStringMaker
{
    void* GetValue(void* value, int flags);
};
struct FnvCreatorResult
{
    int unk00;
    int unk04;
    FnvStringMaker* m_maker;
};
struct FnvManager
{
    virtual void vf00();
    virtual FnvCreatorResult* GetCreator();
};
struct FnvRefCounted
{
    int unk00;
    int unk04;
    int m_refs;
};
FnvRefCounted* __cdecl hkDataArrayDict_create(void* context, void* key, int flags);
struct FnvObjectHolder
{
    int unk00;
    int unk04;
    int unk08;
    FnvEntries m_entries;
    FnvManager* m_manager;
    int AddNodeEntry(FnvNode* node);
};
// Appends an entry for node to m_entries, creating a ref-counted object from the node's key source and context, and returns the new entry index.
// @fnv 0x00dc9c20
int FnvObjectHolder::AddNodeEntry(FnvNode* node)
{
    if (!node->m_iValueAtOffset0C)
        return -1;

    FnvEntries* entries = &m_entries;
    FnvMemoryRouter* router = hkMemoryRouter_getInstance();
    if (entries->m_iElementCount == (entries->m_pRayCursor & 0x3fffffff))
        ResizeAudioStream(router->m_pStreamAllocator, entries, sizeof(FnvEntry));

    FnvEntry* entry = entries->m_data + entries->m_iElementCount;
    if (entry)
        entry->m_iOwnerObjectOffset = 0;
    entry = entries->m_data + entries->m_iElementCount++;
    entry->m_iOwnerObjectOffset = node->m_iOwnerObjectOffset;

    FnvManager* manager = m_manager;
    FnvNodeValue* source = node->m_keySource;
    void* original = source->m_uiFilterValue;
    FnvStringMaker* maker = manager->GetCreator()->m_maker;
    void* key = original ? maker->GetValue(original, 0) : 0;
    void* context = node->m_iValueAtOffset0C;
    FnvRefCounted* created = hkDataArrayDict_create(context, key, node->m_flags);
    entry->m_object = created;
    ++created->m_refs;
    return m_entries.m_iElementCount - 1;
}
}  // namespace fnv_00dc9c20

extern "C" void __movsd(unsigned long* pDst, const unsigned long* pSrc, unsigned int ItemUpdateArray);

class hkMemoryAllocatorDC9D;

struct hkMemoryRouterDC9D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9D* m_pStreamAllocator;

    hkMemoryAllocatorDC9D& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDC9D {
extern "C" hkMemoryRouterDC9D& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDC9D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

inline void memCpy4DC9D(void* pvDst, const void* pvSrc, unsigned int iNumWords)
{
    __movsd((unsigned long*)pvDst, (const unsigned long*)pvSrc, iNumWords);
}

struct hkPairDC9D
{
    int m_kPointA;
    int m_kPointB;
};

// These pairs are value storage: growing the array zeroes the first pair, then replicates it.
__forceinline void SetZeroedPairCount(hkArray<hkPairDC9D>& array, int n)
{
    array.GrowArrayCapacity(reinterpret_cast<hkMemoryAllocator&>(hkRouterDC9D::hkMemoryRouter_getInstance().heap()), n);
    int iNumToFill = n - array.m_iElementCount;
    hkPairDC9D* pDst = array.m_data + array.m_iElementCount;
    if (iNumToFill > 0)
    {
        pDst[0].m_kPointA = 0;
        pDst[0].m_kPointB = 0;
        memCpy4DC9D(pDst + 1, pDst, ((iNumToFill - 1) * sizeof(hkPairDC9D) + 3) >> 2);
    }
    array.m_iElementCount = n;
}

class hkObjDC9D
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<hkPairDC9D> m_pairs;

    void SetPairCount(int n);
};

// Resizes the m_pairs array to n elements, zero-initialising any newly added pairs.
// @fnv 0x00dc9db0
void hkObjDC9D::SetPairCount(int aiCount)
{
    SetZeroedPairCount(m_pairs, aiCount);
}

class hkMemoryAllocatorDC9F
{
  public:
    virtual ~hkMemoryAllocatorDC9F() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC9F
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC9F* m_pStreamAllocator;
    hkMemoryAllocatorDC9F& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDC9F {
extern "C" hkMemoryRouterDC9F& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkRefObjDC9F
{
  public:
    virtual ~hkRefObjDC9F() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkBufferDC9F : public hkRefObjDC9F
{
  public:
    int unk08;
    hkArrayBase<void*> m_data;

    virtual ~hkBufferDC9F() throw()
    {
        m_data._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDC9F::hkMemoryRouter_getInstance().heap()));
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDC9F::hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkBufferDC9F*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDC9F* FUN_00dc9fd0(unsigned int uiFlags) throw();
};

// Clears m_data, destroys the hkRefObjDC9F base, and frees this via operator delete when uiFlags has bit 0 set; returns this.
// @fnv 0x00dc9fd0
hkBufferDC9F* hkBufferDC9F::FUN_00dc9fd0(unsigned int uiFlags) throw()
{
    m_data._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDC9F::hkMemoryRouter_getInstance().heap()));
    this->hkRefObjDC9F::~hkRefObjDC9F();
    if (uiFlags & 1)
        hkBufferDC9F::operator delete(this);
    return this;
}


class hkHolderDCA0
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkDataRefCounted** m_kTrackedObjects;

    void SetElement(int i, hkDataRefCounted* p);
};

// Adds a reference to p, releases the element currently stored at index i, then stores p in the array at index i.
// @fnv 0x00dca090
void hkHolderDCA0::SetElement(int aiIndex, hkDataRefCounted* apRef)
{
    if (apRef)
        apRef->addReference();
    if (m_kTrackedObjects[aiIndex])
        m_kTrackedObjects[aiIndex]->removeReference();
    m_kTrackedObjects[aiIndex] = apRef;
}

namespace fnv_00dca0f0 {
class hkMemoryAllocatorDCA0
{
  public:
    virtual ~hkMemoryAllocatorDCA0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDCA0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA0* m_pStreamAllocator;
    hkMemoryAllocatorDCA0& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCA0& __cdecl hkMemoryRouter_getInstance();

class FUN_00dca0f0 : public hkDataRefCounted
{
  public:
    hkArray<hkDataRefCounted*> m_members;
    hkDataRefCounted* m_class;

    virtual ~FUN_00dca0f0() throw();
};

// Releases references held by each member in m_members and by m_class, then clears m_class.
// @fnv 0x00dca0f0
FUN_00dca0f0::~FUN_00dca0f0() throw()
{
    for (int i = 0; i < m_members.m_iElementCount; i++)
    {
        if (m_members.m_data[i])
            m_members.m_data[i]->removeReference();
    }
    if (m_class)
        m_class->removeReference();
    m_class = 0;
}
}  // namespace fnv_00dca0f0

namespace fnv_00dca190 {
struct FUN_00dca190_Base
{
    void FUN_00dca0f0();
};

struct FUN_00dca190_Virtual
{
    virtual void v00()
    {}
    virtual void v04()
    {}
    virtual void v08(void* object, int value)
    {}
};

struct FUN_00dca190_VirtualImpl : public FUN_00dca190_Virtual
{
};

struct FUN_00dca190_Holder
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    FUN_00dca190_Virtual* m10;
};

void* __cdecl hkMemoryRouter_getInstance(void);

struct FUN_00dca190_class : public FUN_00dca190_Base
{
    void* m00;
    unsigned short m04;

    void* __thiscall FUN_00dca190(unsigned char flags);
};

// @fnv 0x00dca190
void* __thiscall FUN_00dca190_class::FUN_00dca190(unsigned char flags)
{
    FUN_00dca0f0();

    if ((flags & 1) != 0)
    {
        FUN_00dca190_Holder* holder = reinterpret_cast<FUN_00dca190_Holder*>(hkMemoryRouter_getInstance());

        holder->m10->v08(this, m04);
    }

    return this;
}
}  // namespace fnv_00dca190

struct FUN_00dca1e0_class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char* unk0C;
    unsigned int ByteArrayImplementation_asInt(int index);
};
// @fnv 0x00dca1e0
// src: HAVOK_LIB 0x00dca1e0
unsigned int FUN_00dca1e0_class::ByteArrayImplementation_asInt(int index)
{
    return unk0C[index];
}

namespace fnv_00dca210 {
class hkMemoryAllocatorDCA2;

struct hkMemoryRouterDCA2
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA2* m_pTemp;
    hkMemoryAllocatorDCA2* m_pStreamAllocator;
    hkMemoryAllocatorDCA2& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterDCA2& __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDCA2& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();

class hkObjDCA2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<char> m_data;

    void AssignFromBuffer(const void* src, int n);
};

// Resizes m_data to n elements and copies n bytes from src into it.
// @fnv 0x00dca210
void hkObjDCA2::AssignFromBuffer(const void* src, int iCount)
{
    m_data.setSize(iCount);
    hkString_memCpy(m_data.m_data, src, iCount);
}
}  // namespace fnv_00dca210

// 0x00dca2d0 copies two words with an 8-byte array stride; hkEntry is 12 bytes.
struct TwoWordArrayValue
{
    int m_kPointA;
    int m_kPointB;
};

class hkObjDCA2
{
  public:
    int unk00;
    int unk04;
    int unk08;
    TwoWordArrayValue* m_entries;

    void IntArrayImplementation_setInt64(int i, TwoWordArrayValue e);
};

// @fnv 0x00dca2d0
// src: XBOX_PDB 0x00dca2d0
void hkObjDCA2::IntArrayImplementation_setInt64(int aiIndex, TwoWordArrayValue aEntry)
{
    m_entries[aiIndex] = aEntry;
}

class hkMemoryAllocatorDCA3;

struct hkMemoryRouterDCA3
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA3* m_pTemp;
    hkMemoryAllocatorDCA3* m_pStreamAllocator;
    hkMemoryAllocatorDCA3& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDCA3 {
extern "C" hkMemoryRouterDCA3& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDCA3& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkObjDCA3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<__int64> m_iSlotIds;

    void CopyBoolArray(const hkBool* src, int n);
};

// @fnv 0x00dca2f0
void hkObjDCA3::CopyBoolArray(const hkBool* src, int aiCount)
{
    m_iSlotIds.setSize(aiCount);
    for (int i = 0; i < aiCount; i++)
        m_iSlotIds.m_data[i] = src[i];
}

namespace fnv_00dca360 {
class hkMemoryAllocatorDCA3;

struct hkMemoryRouterDCA3
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA3* m_pStreamAllocator;
    hkMemoryAllocatorDCA3& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCA3& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDCA3& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkInt64ArrayDCA3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<__int64> m_iSlotIds;

    void AssignFromByteArray(const signed char* pSrc, int iCount);
};

// Resizes the embedded int64 array to iCount and copies each byte of pSrc into it as an element.
// @fnv 0x00dca360
void hkInt64ArrayDCA3::AssignFromByteArray(const signed char* pSrc, int iCount)
{
    m_iSlotIds.setSize(iCount);
    for (int i = 0; i < iCount; i++)
        m_iSlotIds[i] = pSrc[i];
}
}  // namespace fnv_00dca360

namespace fnv_00dca3c0 {
class hkMemoryAllocatorDCA4;

struct hkMemoryRouterDCA4
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA4* m_pStreamAllocator;
    hkMemoryAllocatorDCA4& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCA4& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDCA4& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkInt64ArrayDCA4
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<__int64> m_iSlotIds;

    void IntArrayImplementation_setAll(const unsigned char* pSrc, int iCount);
};

// Reserves room for iCount elements in the array and copies each byte of pSrc into it as an __int64 element.
// @fnv 0x00dca3c0
// src: XBOX_PDB 0x00dca3c0
void hkInt64ArrayDCA4::IntArrayImplementation_setAll(const unsigned char* pSrc, int iCount)
{
    m_iSlotIds.setSize(iCount);
    for (int i = 0; i < iCount; i++)
        m_iSlotIds[i] = pSrc[i];
}
}  // namespace fnv_00dca3c0

class hkMemoryAllocatorDCA4;

struct hkMemoryRouterDCA4
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA4* m_pTemp;
    hkMemoryAllocatorDCA4* m_pStreamAllocator;
    hkMemoryAllocatorDCA4& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDCA4 {
extern "C" hkMemoryRouterDCA4& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDCA4& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkObjDCA4
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<__int64> m_iSlotIds;

    void CopyShortsToArray(const short* src, int n);
};

// Resizes the array to n elements, then copies n shorts from src into it as 64-bit values.
// @fnv 0x00dca420
void hkObjDCA4::CopyShortsToArray(const short* src, int n)
{
    m_iSlotIds.setSize(n);
    for (int i = 0; i < n; i++)
        m_iSlotIds.m_data[i] = src[i];
}

namespace fnv_00dca5f0 {
struct C85750Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};
C85750Router* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int newCapacity, int itemSize);
void __cdecl hkString_memCpy(void* dst, const void* src, unsigned int bytes);
struct DCA5F0Array
{
    void* volatile data;
    volatile int count;
    int capacityAndFlags;
};
struct DCA5F0Owner
{
    int unk00;
    int unk04;
    int unk08;
    DCA5F0Array elements;
    void AssignElements(const void* source, int count);
};
// Grows the elements array if its capacity is below count, sets count, then copies count 4-byte items from source into the array data.
// @fnv 0x00dca5f0
void DCA5F0Owner::AssignElements(const void* source, int count)
{
    DCA5F0Array* array = &elements;
    C85750Router* router = hkMemoryRouter_getInstance();
    void* allocator = router->allocator;
    int capacity = array->capacityAndFlags & 0x3fffffff;
    if (capacity < count)
    {
        int grown = capacity * 2;
        if (count >= grown)
            grown = count;
        hkArrayUtil__reserve(allocator, array, grown, 4);
    }
    array->count = count;
    hkString_memCpy(array->data, source, count * 4);
}
}  // namespace fnv_00dca5f0

void __cdecl hkString_strFree(int iString);
extern "C" char* __cdecl hkString_strDup_00cb1410(const char* pcString);

class hkObjDCA6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    char** m_pStringFunctions;

    void SetStringAt(int i, const char* pcValue);
};

// @fnv 0x00dca670
void hkObjDCA6::SetStringAt(int i, const char* pcValue)
{
    hkString_strFree(reinterpret_cast<int>(m_pStringFunctions[i]));
    m_pStringFunctions[i] = pcValue ? hkString_strDup_00cb1410(pcValue) : 0;
}

class hkMemoryAllocatorDCA6
{
  public:
    virtual ~hkMemoryAllocatorDCA6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCA6
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA6* m_pStreamAllocator;
    hkMemoryAllocatorDCA6& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA6 {
extern "C" hkMemoryRouterDCA6& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkRefObjDCA6
{
  public:
    virtual ~hkRefObjDCA6() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

void __cdecl hkString_strFree(int p) throw();

class FUN_00dca6b0 : public hkRefObjDCA6
{
  public:
    int unk08;
    hkArrayBase<int> m_pStringFunctions;

    virtual ~FUN_00dca6b0() throw();
};

// @fnv 0x00dca6b0
FUN_00dca6b0::~FUN_00dca6b0() throw()
{
    for (int i = 0; i < m_pStringFunctions.m_iElementCount; i++)
        hkString_strFree(m_pStringFunctions.m_data[i]);
    m_pStringFunctions._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDCA6::hkMemoryRouter_getInstance().heap()));
}

class hkMemoryAllocatorDCA7
{
  public:
    virtual ~hkMemoryAllocatorDCA7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCA7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCA7* m_pStreamAllocator;
    hkMemoryAllocatorDCA7& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCA7 {
extern "C" hkMemoryRouterDCA7& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkRefObjDCA7
{
  public:
    virtual ~hkRefObjDCA7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkBufferDCA7 : public hkRefObjDCA7
{
  public:
    int unk08;
    hkArrayBase<char> m_data;

    virtual ~hkBufferDCA7() throw()
    {
        m_data._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDCA7::hkMemoryRouter_getInstance().heap()));
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDCA7::hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkBufferDCA7*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDCA7* FUN_00dca750(unsigned int uiFlags) throw();
};

// Clears m_data, destroys the hkRefObjDCA7 base, and if uiFlags has bit 0 set, frees this via operator delete; returns this.
// @fnv 0x00dca750
hkBufferDCA7* hkBufferDCA7::FUN_00dca750(unsigned int uiFlags) throw()
{
    m_data._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDCA7::hkMemoryRouter_getInstance().heap()));
    this->hkRefObjDCA7::~hkRefObjDCA7();
    if (uiFlags & 1)
        hkBufferDCA7::operator delete(this);
    return this;
}

class hkMemoryAllocatorDCB7
{
  public:
    virtual ~hkMemoryAllocatorDCB7() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCB7
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCB7* m_pStreamAllocator;
    hkMemoryAllocatorDCB7& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterDCB7 {
extern "C" hkMemoryRouterDCB7& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkRefObjDCB7
{
  public:
    virtual ~hkRefObjDCB7() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkBufferDCB7 : public hkRefObjDCB7
{
  public:
    int unk08;
    hkArrayBase<__int64> m_data;

    virtual ~hkBufferDCB7() throw()
    {
        m_data._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDCB7::hkMemoryRouter_getInstance().heap()));
    }

    static void operator delete(void* p) throw()
    {
        hkRouterDCB7::hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkBufferDCB7*>(p)->m_usMemSizeAndFlags);
    }
    hkBufferDCB7* FUN_00dca7b0(unsigned int uiFlags) throw();
};

// Clears m_data, destroys the hkRefObjDCB7 base, and frees this via operator delete when uiFlags has bit 0 set; returns this.
// @fnv 0x00dca7b0
hkBufferDCB7* hkBufferDCB7::FUN_00dca7b0(unsigned int uiFlags) throw()
{
    m_data._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkRouterDCB7::hkMemoryRouter_getInstance().heap()));
    this->hkRefObjDCB7::~hkRefObjDCB7();
    if (uiFlags & 1)
        hkBufferDCB7::operator delete(this);
    return this;
}

class hkTypeRegistryDCAB
{
  public:
    void FindOrCreateTypeEntry(void* pvHandleOut, int iType) throw();
};


struct hkTypeOwnerDCAB
{
    int unk00;
    int unk04;
    hkTypeRegistryDCAB* m_registry;
};


__forceinline void InitializeClassArray(hkArrayBase<int>& array)
{
    array.m_data = 0;
    array.m_iElementCount = 0;
    array.m_iCapacityState = 0x80000000;
}
extern "C" void* DAT_010d73c8[];
// The shared base has no initializing constructor; initialize the game's base fields here.
// @fnv 0x00dcabb0
hkDataClassDict* __fastcall ConstructDataClassDict(hkDataClassDict* pkClass, void*, hkDataWorldDict* pkOwner,
                                                const char* pcName, int iFlags) throw()
{
    pkClass->m_externalCount = 0;
    pkClass->m_count = 0;
    *reinterpret_cast<void***>(pkClass) = DAT_010d73c8;
    pkClass->m_pOwningWorld = pkOwner;
    reinterpret_cast<hkTypeOwnerDCAB*>(pkOwner)->m_registry->FindOrCreateTypeEntry(&pkClass->unk10, reinterpret_cast<int>(pcName));
    pkClass->m_version = iFlags;
    pkClass->parent = 0;
    InitializeClassArray(*reinterpret_cast<hkArrayBase<int>*>(&pkClass->unk1c));
    InitializeClassArray(*reinterpret_cast<hkArrayBase<int>*>(&pkClass->members));
    InitializeClassArray(*reinterpret_cast<hkArrayBase<int>*>(&pkClass->unk34));
    return pkClass;
}

namespace fnv_00dcac20 {
class FUN_00d47a80_class
{
  public:
    void* GetValue(void* pvObject, int iFlags);
    void* lookup(void* pvObject)
    {
        return pvObject ? GetValue(pvObject, 0) : 0;
    }
};

struct hkClassRefDCAC
{
    int unk00;
    int unk04;
    void* m_object;
};

// 0x00dcac20 reads 24-byte class member declarations; hkEntry is 12 bytes.
struct DictionaryMemberDeclaration
{
    int m_key;
    hkClassRefDCAC* m_ref;
    int unk08;
    int unk0C;
    int m_uiFilterValue;
    int m_flags;
};

struct hkTrackerDCAC
{
    int unk00;
    int unk04;
    FUN_00d47a80_class* m_registry;
};


// Copies the entry at iIndex into kOut, resolving its object through the registry lookup.
// @fnv 0x00dcac20
}  // namespace fnv_00dcac20
void hkDataClassDict::getDeclaredMemberInfo(int iIndex, hkDataClassMemberInfo& kOut) const
{
    const fnv_00dcac20::DictionaryMemberDeclaration& kEntry = reinterpret_cast<const fnv_00dcac20::DictionaryMemberDeclaration*>(members)[iIndex];
    kOut.m_key = kEntry.m_key;
    kOut.m_table = this;
    kOut.m_object = reinterpret_cast<fnv_00dcac20::hkTrackerDCAC*>(m_pOwningWorld)->m_registry->lookup(kEntry.m_ref->m_object);
    kOut.m_uiFilterValue = kEntry.m_uiFilterValue;
    kOut.m_flags = kEntry.m_flags;
}

namespace fnv_00dcad10 {
extern "C" void* hkString_strDup_00cb1410(const char* str);

struct MapTarget
{
    void* GetValue(const char* key, int zero);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(void* key, void* val);
};

struct InnerContext
{
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
    MapTarget map;

    __forceinline void* Intern(const char* name)
    {
        if (name)
        {
            void* key = map.GetValue(name, 0);
            if (!key)
            {
                key = hkString_strDup_00cb1410(name);
                map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(key, key);
            }
            return key;
        }
        return 0;
    }
};

struct OuterContext
{
    int unk00;
    int unk04;
    InnerContext* inner;
};


// Interns name through the context, then scans m_items for a matching key and returns its index, or -1 if not found.
// @fnv 0x00dcad10
}  // namespace fnv_00dcad10
int hkDataClassDict::getDeclaredMemberIndexByName(const char* name) const
{
    void* key = reinterpret_cast<fnv_00dcad10::OuterContext*>(m_pOwningWorld)->inner->Intern(name);

    for (int i = 0; i < count; ++i)
    {
        if (members[i].name == key)
        {
            return i;
        }
    }
    return -1;
}

namespace fnv_00dcae30 {
class FUN_00d47a80_class
{
  public:
    void* GetValue(void* pvObject, int iFlags);
    void* lookup(void* pvObject)
    {
        return pvObject ? GetValue(pvObject, 0) : 0;
    }
};

struct hkClassRefDCAE
{
    int unk00;
    int unk04;
    void* m_object;
};

// 0x00dcae30 reads 24-byte class member declarations; hkEntry is 12 bytes.
struct DictionaryMemberDeclaration
{
    int m_key;
    hkClassRefDCAE* m_ref;
    int unk08;
    int unk0C;
    int m_uiFilterValue;
    int m_flags;
};

struct hkTrackerDCAE
{
    int unk00;
    int unk04;
    FUN_00d47a80_class* m_registry;
};


// @fnv 0x00dcae30
}  // namespace fnv_00dcae30
void hkDataClassDict::getMemberInfo(int iKey, hkDataClassMemberInfo& kOut) const
{
    const hkDataClassDict* pkTable = this;
    int iIndex = iKey - getNumMembers();
    for (; pkTable; pkTable = pkTable->parent)
    {
        iIndex += pkTable->count;
        if (iIndex >= 0)
        {
            const fnv_00dcae30::DictionaryMemberDeclaration& kEntry = reinterpret_cast<const fnv_00dcae30::DictionaryMemberDeclaration*>(pkTable->members)[iIndex];
            kOut.m_key = kEntry.m_key;
            kOut.m_table = this;
            kOut.m_uiFilterValue = kEntry.m_uiFilterValue;
            kOut.m_object = reinterpret_cast<fnv_00dcae30::hkTrackerDCAE*>(m_pOwningWorld)->m_registry->lookup(kEntry.m_ref->m_object);
            kOut.m_flags = kEntry.m_flags;
            return;
        }
    }
}

struct Obj00dcb210
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
};
struct Entry00dcb210
{
    int unk00;
    Obj00dcb210* p;
};
struct Cls00dcb210
{
    int unk00;
    int unk04;
    int unk08;
    Entry00dcb210* m_aiIndexedValues;
    int m_uiItemCount;
    int unk14;
    int unk18;
    int m_flag;
    void StructArrayImplementation_clear();
};

// @fnv 0x00dcb210
// src: XBOX_PDB 0x00dcb210
void Cls00dcb210::StructArrayImplementation_clear()
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            m_aiIndexedValues[i].p->a2();
            ++i;
        } while (i < m_uiItemCount);
        m_flag = 0;
    }
    else
    {
        m_flag = i;
    }
}

class hkAccessorDCB3
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual int getInt(int obj) throw();
};

struct hkMemberDCB3
{
    const char* m_name;
    hkAccessorDCB3* m_accessor;
};

class hkImplDCB3
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB3* m_members;

    int StructArrayImplementation__find(int iName) throw();
};

class hkObjDCB3
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB3* m_pClassImpl;
    int m_10;

    int GetMemberInt(int iName, int iUnused) throw();
};

// Looks up the member index by name in the implementation and returns the accessor's int value for m_10.
// @fnv 0x00dcb340
int hkObjDCB3::GetMemberInt(int iName, int iUnused) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__find(iName);
    return m_pClassImpl->m_members[idx].m_accessor->getInt(m_10);
}

class hkObjectDCB3
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual int V10(int iValue);
};

// 0x00dcb370 indexes 8-byte key/accessor bindings; hkEntry is 12 bytes.
struct IntegerAccessorBinding
{
    int m_key;
    hkObjectDCB3* m_object;
};

struct hkTableDCB3
{
    int m_00;
    int m_04;
    int m_08;
    IntegerAccessorBinding* m_entries;

    int StructArrayImplementation__find(int iKey);
};

class hkOwnerDCB3
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB3* m_table;
    int m_10;

    int StructArrayImplementation_Object_asString(int iKey);
};

// Looks up the table entry for iKey and returns the object's V10 result for m_10.
// @fnv 0x00dcb370
// src: XBOX_PDB 0x00dcb370
int hkOwnerDCB3::StructArrayImplementation_Object_asString(int iKey)
{
    int iIndex = m_table->StructArrayImplementation__find(iKey);
    return m_table->m_entries[iIndex].m_object->V10(m_10);
}

struct hkValueDCB4
{
    int m_00;
    int m_04;
    hkValueDCB4()
    {}
};

class hkAccessorDCB4
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual hkValueDCB4 getValue(int obj) throw();
};

struct hkMemberDCB4
{
    const char* m_name;
    hkAccessorDCB4* m_accessor;
};

class hkImplDCB4
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB4* m_members;

    int StructArrayImplementation__find(int iName) throw();
};

class hkObjDCB4
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB4* m_pClassImpl;
    int m_10;

    hkValueDCB4 GetMemberValue(int iName) throw();
};

// Looks up the member index for iName in the implementation and returns the value its accessor reads from m_10.
// @fnv 0x00dcb430
hkValueDCB4 hkObjDCB4::GetMemberValue(int iName) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__find(iName);
    return m_pClassImpl->m_members[idx].m_accessor->getValue(m_10);
}

struct hkPairDCB6
{
    int m_00;
    int m_04;
};

class hkAccessorDCB6
{
  public:
    void hkDataArrayImpl_set(int obj, hkPairDCB6 v) throw();
};

struct hkMemberDCB6
{
    const char* m_name;
    hkAccessorDCB6* m_accessor;
};

class hkImplDCB6
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberDCB6* m_members;

    int StructArrayImplementation__findOrAdd(int iName) throw();
};

class hkObjDCB6
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplDCB6* m_pClassImpl;
    int m_10;

    void StructArrayImplementation_Object_assign(int iName, const hkPairDCB6& v) throw();
};

// Looks up the member index for iName in the implementation and passes m_10 and v to that member's accessor.
// @fnv 0x00dcb650
// src: XBOX_PDB 0x00dcb650
void hkObjDCB6::StructArrayImplementation_Object_assign(int iName, const hkPairDCB6& v) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__findOrAdd(iName);
    m_pClassImpl->m_members[idx].m_accessor->hkDataArrayImpl_set(m_10, v);
}

struct FUN_00dcb690_Object
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21(int, int);
};
struct FUN_00dcb690_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Class* m_iThirdValue;
    int m_10;
    void __thiscall DispatchToIndexedObject(int a, int b);
};
// @fnv 0x00dcb690
void __thiscall FUN_00dcb690_Class::DispatchToIndexedObject(int arg0, int arg1)
{
    int index = m_iThirdValue->StructArrayImplementation__findOrAdd(arg0);
    reinterpret_cast<FUN_00dcb690_Object*>(m_iThirdValue->m_iThirdValue[index].m_p4)->vf21(m_10, arg1);
}

struct FUN_00dcb6c0_Target
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
// src: XBOX_PDB 0x00dcb650
    virtual void StructArrayImplementation_Object_assign(int a, int b)
    {}
};

struct FUN_00dcb6c0_Element
{
    FUN_00dcb6c0_Target* m_p0;
    void* m_p4;
};

struct FUN_00dcb6c0_Array
{
    void* m_p0;
    FUN_00dcb6c0_Element m_p4;
};

struct FUN_00dcb5d0_Obj
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb6c0_Array* m_pC;

    int __thiscall StructArrayImplementation__findOrAdd(int a);
};

struct FUN_00dcb6c0_Obj
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Obj* m_pC;
    int m_p10;

    void __thiscall StructArrayImplementation_Object_assign_00dcb6c0(int a, int b);
};

// Looks up an index from m_pC, gets the target element at that index, and calls its FUN_00dcb650 with m_p10 and b.
// @fnv 0x00dcb6c0
// src: XBOX_PDB 0x00dcb6c0
void __thiscall FUN_00dcb6c0_Obj::StructArrayImplementation_Object_assign_00dcb6c0(int a, int b)
{
    int index = m_pC->StructArrayImplementation__findOrAdd(a);
    FUN_00dcb6c0_Target* target = (&m_pC->m_pC->m_p4)[index].m_p0;
    target->StructArrayImplementation_Object_assign(m_p10, b);
}

class hkAccessorXdcb720
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void target(int obj, float v) throw();
};

struct hkMemberXdcb720
{
    const char* m_name;
    hkAccessorXdcb720* m_accessor;
};

class hkImplXdcb720
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb720* m_members;

    int StructArrayImplementation__findOrAdd(int iName) throw();
};

class hkObjXdcb720
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb720* m_pClassImpl;
    int m_10;

    void StructArrayImplementation_Object_assign_00dcb720(int iName, float v) throw();
};

// Looks up a member by name in the implementation and forwards the value to that member's accessor target.
// @fnv 0x00dcb720
// src: XBOX_PDB 0x00dcb720
void hkObjXdcb720::StructArrayImplementation_Object_assign_00dcb720(int iName, float v) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__findOrAdd(iName);
    m_pClassImpl->m_members[idx].m_accessor->target(m_10, v);
}

class hkAccessorXdcb760
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void target(int obj, int v) throw();
};

struct hkMemberXdcb760
{
    const char* m_name;
    hkAccessorXdcb760* m_accessor;
};

class hkImplXdcb760
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb760* m_members;

    int StructArrayImplementation__findOrAdd(int iName) throw();
};

class hkObjXdcb760
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb760* m_pClassImpl;
    int m_10;

    void StructArrayImplementation_Object_assign_00dcb760(int iName, int v) throw();
};

// Looks up the member index for iName in the implementation and forwards the value to that member's accessor target with m_10.
// @fnv 0x00dcb760
// src: XBOX_PDB 0x00dcb760
void hkObjXdcb760::StructArrayImplementation_Object_assign_00dcb760(int iName, int iValue) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__findOrAdd(iName);
    m_pClassImpl->m_members[idx].m_accessor->target(m_10, iValue);
}

struct FUN_00dcb7c0_Object
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void FUN_00dcb7c0_17(int a, int b);
};
struct FUN_00dcb7c0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    FUN_00dcb5d0_Class* m_iThirdValue;
    int m_10;
    void __thiscall CallObjectVirtual(int arg0, int arg1);
};
// @fnv 0x00dcb7c0
void __thiscall FUN_00dcb7c0_Class::CallObjectVirtual(int arg0, int aiValue)
{
    int index = m_iThirdValue->StructArrayImplementation__findOrAdd(arg0);
    reinterpret_cast<FUN_00dcb7c0_Object*>(m_iThirdValue->m_iThirdValue[index].m_p4)->FUN_00dcb7c0_17(m_10, (signed char)aiValue);
}

class hkAccessorXdcb7f0
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void v15() throw();
    virtual void v16() throw();
    virtual void target(int obj, int v) throw();
};

struct hkMemberXdcb7f0
{
    const char* m_name;
    hkAccessorXdcb7f0* m_accessor;
};

class hkImplXdcb7f0
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb7f0* m_members;

    int StructArrayImplementation__findOrAdd(int iName) throw();
};

class hkObjXdcb7f0
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb7f0* m_pClassImpl;
    int m_10;

    void StructArrayImplementation_Object_assign_00dcb7f0(int iName, short v) throw();
};

// Looks up the member index by name and forwards the value to that member's accessor target with m_10.
// @fnv 0x00dcb7f0
// src: XBOX_PDB 0x00dcb7f0
void hkObjXdcb7f0::StructArrayImplementation_Object_assign_00dcb7f0(int iName, short asValue) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__findOrAdd(iName);
    m_pClassImpl->m_members[idx].m_accessor->target(m_10, asValue);
}

class hkAccessorXdcb820
{
  public:
    virtual void v00() throw();
    virtual void v01() throw();
    virtual void v02() throw();
    virtual void v03() throw();
    virtual void v04() throw();
    virtual void v05() throw();
    virtual void v06() throw();
    virtual void v07() throw();
    virtual void v08() throw();
    virtual void v09() throw();
    virtual void v10() throw();
    virtual void v11() throw();
    virtual void v12() throw();
    virtual void v13() throw();
    virtual void v14() throw();
    virtual void v15() throw();
    virtual void v16() throw();
    virtual void target(int obj, int v) throw();
};

struct hkMemberXdcb820
{
    const char* m_name;
    hkAccessorXdcb820* m_accessor;
};

class hkImplXdcb820
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkMemberXdcb820* m_members;

    int StructArrayImplementation__findOrAdd(int iName) throw();
};

class hkObjXdcb820
{
  public:
    void* m_00;
    void* m_04;
    void* m_08;
    hkImplXdcb820* m_pClassImpl;
    int m_10;

    void StructArrayImplementation_Object_assign_00dcb820(int iName, int v) throw();
};

// Looks up the member index by name and forwards the value to that member's accessor target with m_10.
// @fnv 0x00dcb820
// src: XBOX_PDB 0x00dcb820
void hkObjXdcb820::StructArrayImplementation_Object_assign_00dcb820(int iName, int iValue) throw()
{
    int idx = m_pClassImpl->StructArrayImplementation__findOrAdd(iName);
    m_pClassImpl->m_members[idx].m_accessor->target(m_10, iValue);
}

class hkObjectDCB8
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual int V19(int iOwner, int iArg0, int iArg1);
};

// 0x00dcb850 indexes 8-byte key/accessor bindings; hkEntry is 12 bytes.
struct DispatchAccessorBinding
{
    int m_key;
    hkObjectDCB8* m_object;
};

struct hkTableDCB8
{
    int m_00;
    int m_04;
    int m_08;
    DispatchAccessorBinding* m_entries;

    int StructArrayImplementation__findOrAdd(int iKey);
};

class hkOwnerDCB8
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkTableDCB8* m_table;
    int m_10;

    int DispatchToEntryObject(int iKey, int iArg0, int iArg1);
};

// Looks up iKey in m_table and forwards iArg0/iArg1 to the entry object's V19 with m_10 as owner.
// @fnv 0x00dcb850
int hkOwnerDCB8::DispatchToEntryObject(int iKey, int iArg0, int iArg1)
{
    int iIndex = m_table->StructArrayImplementation__findOrAdd(iKey);
    return m_table->m_entries[iIndex].m_object->V19(m_10, iArg0, iArg1);
}

struct FUN_00dcba40_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int hkDataObjectDict__readAccess(int* out, int a, int b);
    int hkDataObjectDict_asArray(int a);
};

// Calls FUN_00dcba40 with a and 0x10, then returns the int at index out[1]*4+2 in the array at m_10.
// @fnv 0x00dcbbf0
// src: XBOX_PDB 0x00dcbbf0
int FUN_00dcba40_class::hkDataObjectDict_asArray(int a)
{
    int out[2];
    hkDataObjectDict__readAccess(out, a, 0x10);
    return ((int*)m_10)[out[1] * 4 + 2];
}

struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};

// The scalar value is at +0x08 in a 16-byte dictionary member record; hkEntry is 12 bytes.
struct ScalarMemberData
{
    int m_key;
    int m_04;
    int m_uiFilterValue;
    int m_0c;
};

class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    ScalarMemberData* m_entries;

    hkResultDCB hkDataObjectDict__readAccess(int iKey, int iType) throw();
    int hkDataObjectDict_asString(int iKey) throw();
};

// @fnv 0x00dcbc20
// src: XBOX_PDB 0x00dcbc20
int hkObjDCB::hkDataObjectDict_asString(int iKey) throw()
{
    hkResultDCB kRes = hkDataObjectDict__readAccess(iKey, 10);
    return m_entries[kRes.m_uiEdgeIndex].m_uiFilterValue;
}

struct FUN_00dcbc50_Item
{
    int unk00;
    int unk04;
    __int64 value;
};

struct FUN_00dcbc50_Argument
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int count;
};

struct FUN_00dcbc50_Result
{
    FUN_00dcbc50_Argument* entry;
    int index;
};

struct FUN_00dcbc50_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00dcbc50_Item* items;

    void hkDataObjectDict__readAccess(FUN_00dcbc50_Result* result, FUN_00dcbc50_Argument* argument, int mode);
    __int64 GetItemValue(FUN_00dcbc50_Argument* argument);
};

// @fnv 0x00dcbc50
__int64 FUN_00dcbc50_Class::GetItemValue(FUN_00dcbc50_Argument* argument)
{
    FUN_00dcbc50_Result result;
    hkDataObjectDict__readAccess(&result, argument, 0);

    if ((unsigned int)(result.entry->count - 1) <= 1)
        return items[result.index].value;

    return 0;
}

namespace fnv_00dcbca0 {
struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};

// The scalar value is at +0x08 in a 16-byte dictionary member record; hkEntry is 12 bytes.
struct ScalarMemberData
{
    int m_key;
    int m_04;
    int m_uiFilterValue;
    int m_0c;
};

class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    ScalarMemberData* m_entries;

    hkResultDCB hkDataObjectDict__readAccess(int iKey, int iType) throw();
    int hkDataObjectDict_asObject(int iKey) throw();
};

// @fnv 0x00dcbca0
// src: XBOX_PDB 0x00dcbca0
int hkObjDCB::hkDataObjectDict_asObject(int iKey) throw()
{
    hkResultDCB kRes = hkDataObjectDict__readAccess(iKey, 8);
    return m_entries[kRes.m_uiEdgeIndex].m_uiFilterValue;
}
}  // namespace fnv_00dcbca0

namespace fnv_00dcbd10 {
struct hkResultDCB
{
    void* m_item;
    int m_uiEdgeIndex;
    hkResultDCB()
    {}
};

// The scalar value is at +0x08 in a 16-byte dictionary member record; hkEntry is 12 bytes.
struct ScalarMemberData
{
    int m_key;
    int m_04;
    float m_uiFilterValue;
    int m_0c;
};

class hkObjDCB
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    ScalarMemberData* m_entries;

    hkResultDCB hkDataObjectDict__readAccess(int iKey, int iType) throw();
    float GetEntryFloat(int iKey) throw();
};

// Looks up iKey with type 3 and returns the float field of the resulting entry.
// @fnv 0x00dcbd10
float hkObjDCB::GetEntryFloat(int iKey) throw()
{
    hkResultDCB kRes = hkDataObjectDict__readAccess(iKey, 3);
    return m_entries[kRes.m_uiEdgeIndex].m_uiFilterValue;
}
}  // namespace fnv_00dcbd10

namespace fnv_00dcbfc0 {

struct hkAllocatorDCBF
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDCBF
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    hkAllocatorDCBF* m_pkHeap;
    hkAllocatorDCBF& heap()
    {
        return *m_pkHeap;
    }
};
extern "C" hkMemoryRouterDCBF* __cdecl hkMemoryRouter_getInstance() throw();

template <typename T> struct hkRefPtrDCBF
{
    T* m_pRetainedObject;
    __forceinline ~hkRefPtrDCBF() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct EntryDCBF
{
    int m_00;
    hkRefPtrDCBF<hkReferencedObject> m_object;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

template <typename T> struct hkSharedPtrDCBF
{
    T* m_pRetainedObject;
    __forceinline ~hkSharedPtrDCBF() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};


}  // namespace fnv_00dcbfc0
void __fastcall ClearDataClassDict(hkDataClassDict* pkClass, void*);

template <class T> __forceinline void DestroyClassArray(hkArrayBase<T>& array)
{
    hkAllocatorDC76& kAlloc = hkMemoryRouter_getInstance()->heap();
    array.clear();
    if ((array.m_iCapacityState & 0x80000000) == 0)
        kAlloc.ReturnMemory(array.m_data, (array.m_iCapacityState & 0x3fffffff) * sizeof(T));
    array.m_data = 0;
    array.m_iCapacityState = 0x80000000;
}

// @fnv 0x00dcbfc0
hkDataClassDict::~hkDataClassDict()
{
    reinterpret_cast<void (__thiscall*)(hkDataClassDict*)>(ClearDataClassDict)(this);
    DestroyClassArray(*reinterpret_cast<hkArrayBase<fnv_00dcbfc0::EntryDCBF>*>(&unk34));
    DestroyClassArray(*reinterpret_cast<hkArrayBase<fnv_00dcbfc0::EntryDCBF>*>(&members));
    DestroyClassArray(*reinterpret_cast<hkArrayBase<int>*>(&unk1c));
    reinterpret_cast<fnv_00dcbfc0::hkSharedPtrDCBF<hkDataRefCounted>*>(&parent)->~hkSharedPtrDCBF();
    reinterpret_cast<fnv_00dcbfc0::hkRefPtrDCBF<hkReferencedObject>*>(&m_name)->~hkRefPtrDCBF();
}

namespace fnv_00dcc100 {
class hkMemoryAllocatorDCC1
{
  public:
    virtual ~hkMemoryAllocatorDCC1() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDCC1
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDCC1* m_pStreamAllocator;
    hkMemoryAllocatorDCC1& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDCC1& __cdecl hkMemoryRouter_getInstance();

}  // namespace fnv_00dcc100

// hkDataClassDict's scalar deleting destructor at 0x00dcc100 is compiler generated.
inline void hkDataRefCounted::operator delete(void* p)
{
    fnv_00dcc100::hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkDataRefCounted*>(p)->m_memSize);
}


char* __cdecl StrDup7320(const char* pcString);

struct StringMap7320
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct Registry7320
{
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
    StringMap7320 m_kNodePool;

    void Rename(const char* pcOldName, const char* pcNewName);
    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDup7320(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct ClassInfo7320
{
    const char* GetName() const;
};

class Owner7320
{
  public:
    void hkDataWorldDict_renameClass(const ClassInfo7320* pkClass, const char* pcNewName);
    int unk00;
    int unk04;
    Registry7320* m_pkRegistry;
};

// Renames the class in the registry from its current name to pcNewName, pooling the old name first if it is not already pooled.
// @fnv 0x00dc7320
// src: XBOX_PDB 0x00dc7320
void Owner7320::hkDataWorldDict_renameClass(const ClassInfo7320* pkClass, const char* pcNewName)
{
    const char* pcName = pkClass->GetName();
    Registry7320* pkRegistry = m_pkRegistry;
    const char* pcPooled = pcName ? pkRegistry->GetPooled(pcName) : 0;
    m_pkRegistry->Rename(pcPooled, pcNewName);
}

// @fnv 0x00dc73e0
// src: GUESS 0x00dc73e0 (confidence: low)
static __declspec(noinline) unsigned int Object_ComputeValue_00dc73e0(unsigned int value)
{
    return (value >> 2) + 3;
}

unsigned int AllocationBlockCount(unsigned int value)
{
    return Object_ComputeValue_00dc73e0(value);
}

struct Memory7DE0
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes);
};
struct Context7DE0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Memory7DE0* m_pkMemory;
};
Context7DE0* GetContext7DE0();

struct Shape7DE0
{
    Shape7DE0() throw() : m_usFlags(0), m_iRefCount(0)
    {}
    virtual ~Shape7DE0();
    static __forceinline void* operator new(unsigned int nbytes) throw()
    {
        Context7DE0* pkContext = GetContext7DE0();
        Shape7DE0* pkShape = static_cast<Shape7DE0*>(pkContext->m_pkMemory->allocateChunk(nbytes));
        pkShape->m_usMemSize = (unsigned short)nbytes;
        return pkShape;
    }
    void AddRef()
    {
        m_iRefCount++;
    }
    unsigned short m_usMemSize;
    unsigned short m_usFlags;
    int m_iRefCount;
};
struct Container7DE0
{
    Container7DE0() throw() : m_usFlags(0), m_iArrayLength(0)
    {}
    virtual ~Container7DE0();
    unsigned short m_usSize;
    unsigned short m_usFlags;
    int m_iArrayLength;
    void* m_pkOwnerManager;
    void AddOwner(void* pkOwner)
    {
        m_iArrayLength++;
        m_pkOwnerManager = pkOwner;
    }
};
struct Wrapper7DE0 : public Shape7DE0
{
    __forceinline Wrapper7DE0(Shape7DE0* pkChild, int iData) throw() : m_pkChild(pkChild)
    {
        int one = 1;
        m_iData = iData;
        pkChild->m_iRefCount += one;
        m_kContainer.m_iArrayLength += one;
        m_kContainer.m_pkOwnerManager = this;
    }
    Container7DE0 m_kContainer;
    int unk1C;
    Shape7DE0* m_pkChild;
    volatile int m_iData;
};
struct ShapeA7DE0 : public Shape7DE0
{
    ShapeA7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
struct ShapeB7DE0 : public Shape7DE0
{
    ShapeB7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
struct ShapeC7DE0 : public Shape7DE0
{
    ShapeC7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};
struct ShapeD7DE0 : public Shape7DE0
{
    ShapeD7DE0(int iStride) throw();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct ShapeE7DE0 : public Shape7DE0
{
    ShapeE7DE0(int iArg) throw();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct ShapeF7DE0 : public Shape7DE0
{
    ShapeF7DE0(int iArg) throw();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct ShapeG7DE0 : public Shape7DE0
{
    ShapeG7DE0() throw();
    int unk0C;
    int unk10;
    int unk14;
};

// Creates a Shape7DE0 subclass based on uiType, wrapping the result in Wrapper7DE0 when the 0x20 flag is set.
// @fnv 0x00dc7de0
// src: XBOX_PDB 0x00dc7de0
Shape7DE0* hkDataArrayDict_create(unsigned int uiType, int iArg, int iData)
{
    if (uiType & 0x20)
    {
        Shape7DE0* pkChild = hkDataArrayDict_create(uiType & ~0x20, iArg, 0);
        return new Wrapper7DE0(pkChild, iData);
    }
    switch (uiType & 0xf)
    {
    case 1:
        return new ShapeA7DE0;
    case 2:
        return new ShapeB7DE0;
    case 3:
        return new ShapeC7DE0;
    case 4:
        return new ShapeD7DE0(4);
    case 6:
        return new ShapeD7DE0(0xc);
    case 7:
        return new ShapeD7DE0(0x10);
    case 8:
        return new ShapeE7DE0(iArg);
    case 9:
        return new ShapeF7DE0(iArg);
    case 10:
        return new ShapeG7DE0;
    }
    return 0;
}

class hkObjDC82
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void setTarget(void* target);
};

class hkRegistryDC82
{
  public:
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void registerObject(void* key, hkObjDC82* obj);
};

struct hkCtxDC82
{
    hkRegistryDC82* m_registry;
};

struct hkDescDC82
{
    void* m_key;
    int unk04;
    unsigned int m_flags;
    void* m_type;
    void* m_target;
};

hkObjDC82* __cdecl hkDataArrayDict_create(unsigned int flags, void* type, void* owner);

// Creates an object from desc->m_type, sets its target, and registers it in ctx->m_registry under desc->m_key.
// @fnv 0x00dc8210
hkObjDC82* __stdcall CreateAndRegisterObject(hkCtxDC82* ctx, hkDescDC82* desc)
{
    unsigned int flags = desc->m_flags;
    void* owner;
    void* target;
    if (flags & 0x10)
    {
        owner = desc->m_target;
        flags &= ~0x10;
        target = 0;
    }
    else
    {
        target = desc->m_target;
        flags &= ~0x20;
        owner = 0;
    }
    hkObjDC82* obj = hkDataArrayDict_create(flags, desc->m_type, owner);
    obj->setTarget(target);
    ctx->m_registry->registerObject(desc->m_key, obj);
    return obj;
}

struct Src80
{
    virtual void s00();
    virtual int GetType();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual int Get8(int idx);
    virtual void s09();
    virtual int Get10(int idx);
    virtual void s11();
    virtual float Get12(int idx);
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int Get16(int idx);
    virtual void s17();
    virtual __int64 Get18(int idx);
    virtual void s19();
    virtual int Get20(int idx);
};
struct Setter80
{
    virtual void t00();
    virtual void t01();
    virtual void t02();
    virtual void t03();
    virtual void t04();
    virtual void t05();
    virtual void t06();
    virtual void t07();
    virtual void t08();
    virtual void Set9(int idx, int val);
    virtual void t10();
    virtual void Set11(int idx, int val);
    virtual void t12();
    virtual void Set13(int idx, float val);
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void Set17(int idx, int val);
    virtual void t18();
    virtual void Set19(int idx, __int64 val);
    virtual void t20();
    virtual void Set21(int idx, int val);
    int m_s04;
    int m_s08;
    int m_s0c;
};
struct DC8A80
{
    int m_00;
    int m_04;
    int m_08;
    Setter80 m_0c;
    int m_1c;
    int m_20;
    int m_24;
    void __thiscall CopyFromSource(int a, Src80* src);
};
// Copies m_24 elements from src into m_0c using the setter matching src's type, and stores m_24 * a in m_1c.
// @fnv 0x00dc8a80
void __thiscall DC8A80::CopyFromSource(int a, Src80* src)
{
    m_1c = m_24 * a;
    int type = src->GetType();
    switch (type)
    {
    case 1:
        for (int i = 0; i < m_24; i++)
            m_0c.Set17(i, src->Get16(i));
        break;
    case 2:
        for (int i = 0; i < m_24; i++)
            m_0c.Set19(i, src->Get18(i));
        break;
    case 3:
        for (int i = 0; i < m_24; i++)
            m_0c.Set13(i, src->Get12(i));
        break;
    case 4:
        for (int i = 0; i < m_24; i++)
            m_0c.Set9(i, src->Get8(i));
        break;
    case 5:
        for (int i = 0; i < m_24; i++)
            m_0c.Set9(i, src->Get8(i));
        break;
    case 6:
        for (int i = 0; i < m_24; i++)
            m_0c.Set9(i, src->Get8(i));
        break;
    case 7:
        for (int i = 0; i < m_24; i++)
            m_0c.Set9(i, src->Get8(i));
        break;
    case 8:
        for (int i = 0; i < m_24; i++)
            m_0c.Set21(i, src->Get20(i));
        break;
    case 9:
        for (int i = 0; i < m_24; i++)
            m_0c.Set21(i, src->Get20(i));
        break;
    case 10:
        for (int i = 0; i < m_24; i++)
            m_0c.Set11(i, src->Get10(i));
        break;
    }
}

class hkMemoryAllocatorDC8C
{
  public:
    virtual ~hkMemoryAllocatorDC8C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDC8C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC8C* m_pStreamAllocator;

    hkMemoryAllocatorDC8C& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDC8C {
extern "C" hkMemoryRouterDC8C& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkBaseObjDC8C
{
  public:
    virtual ~hkBaseObjDC8C() throw()
    {}
};

class hkRefObjDC8C : public hkBaseObjDC8C
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~hkRefObjDC8C() throw()
    {}

    static void operator delete(void* p)
    {
        hkRouterDC8C::hkMemoryRouter_getInstance().heap().ReleaseBlock(p, static_cast<hkRefObjDC8C*>(p)->m_usMemSizeAndFlags);
    }
};

class hkSharedDC8C
{
  public:
    virtual void deleteThis(int flags) throw();
    int unk04;
    int m_uiItemCount;

    void release() throw()
    {
        if (--m_uiItemCount == 0)
            deleteThis(1);
    }
};

class hkMemberDC8C : public hkBaseObjDC8C
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class hkObjDC8C : public hkRefObjDC8C
{
  public:
    int unk08;
    hkMemberDC8C m_kMemberDescriptor;
    hkSharedDC8C* m_pSharedObject;

    virtual ~hkObjDC8C() throw()
    {
        m_pSharedObject->release();
    }

    hkObjDC8C* FUN_00dc8cd0(unsigned int flags);
};

// Calls the hkObjDC8C destructor and, when the low bit of flags is set, frees the object via operator delete, then returns this.
// @fnv 0x00dc8cd0
hkObjDC8C* hkObjDC8C::FUN_00dc8cd0(unsigned int flags)
{
    this->hkObjDC8C::~hkObjDC8C();
    if (flags & 1)
        operator delete(this);
    return this;
}

char* __cdecl hkString_strDup_00cb1410(const char* pcString);

struct StringMapDC8F20
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void remove(const char* pcKey);
    void insert(const char* pcKey, void* pvValue);

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_flags;
};

struct NamedEntryDC8F20
{
    void* m_ppVirtualMethodTable;
    int m_iObjectReferenceCount;
    const char* m_name;
};

struct NameRegistryDC8F20
{
    StringMapDC8F20 m_iSlotIds;
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
    StringMapDC8F20 m_kNodePool;
    StringMapDC8F20 m_entries;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = hkString_strDup_00cb1410(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
    void RenameRegisteredEntry(const char* pcOldName, const char* pcNewName);
};

// Renames a registered entry from pcOldName to pcNewName, updating m_entries and m_iSlotIds with the pooled new name.
// @fnv 0x00dc8f20
// src: GUESS 0x00dc8f20 (confidence: medium)
void NameRegistryDC8F20::RenameRegisteredEntry(const char* pcOldName, const char* pcNewName)
{
    void* pvValue = pcOldName ? m_iSlotIds.FindValueForKey(pcOldName, 0) : 0;
    const char* pcPooled = pcNewName ? GetPooled(pcNewName) : 0;
    if (pcOldName != pcPooled)
    {
        NamedEntryDC8F20* pkEntry = (NamedEntryDC8F20*)m_entries.FindValueForKey(pcOldName, 0);
        m_entries.remove(pcOldName);
        pkEntry->m_name = pcPooled;
        m_entries.insert(pcPooled, pkEntry);
    }
    m_iSlotIds.remove(pcOldName);
    m_iSlotIds.insert(pcPooled, pvValue);
}

struct Entry_dc90f0
{
    int key;
    int flags;
    __int64 value;
};

struct Metadata_dc90f0
{
    int unk00, unk04, unk08, unk0C;
    void* type;
};


void __cdecl ReleaseDataValues(void* type, __int64* value, int count);

struct Object_dc90f0
{
    int unk00, unk04, unk08;
    hkDataClassDict* registry;
    Entry_dc90f0* entries;
    int count;

    void RemoveEntryAndCompact(int key);
};

// Finds the matching entry, releases its value when metadata exists, decrements count, and copies the last entry into its position when needed.
// @fnv 0x00dc90f0
// src: GUESS 0x00dc90f0 (confidence: medium)
void Object_dc90f0::RemoveEntryAndCompact(int key)
{
    const int n = count;
    int i = 0;
    if (n > 0)
    {
        Entry_dc90f0* base = entries;
        Entry_dc90f0* current = base;
        do
        {
            if (current->key == key)
            {
                const unsigned int byteOffset = i * sizeof(Entry_dc90f0);
                Metadata_dc90f0* metadata = reinterpret_cast<Metadata_dc90f0*>(registry->FindEntry(
                    reinterpret_cast<const char*>(reinterpret_cast<Entry_dc90f0*>(reinterpret_cast<char*>(base) + byteOffset)->key)));
                if (metadata)
                    ReleaseDataValues(
                        metadata->type,
                        &reinterpret_cast<Entry_dc90f0*>(reinterpret_cast<char*>(base) + byteOffset)->value, 1);

                --count;
                if (count != i)
                {
                    // Fetch the array again after cleanup and fill the removed slot
                    // with its last entry, preserving the byte offset found above.
                    const __int64* src = reinterpret_cast<const __int64*>(&entries[count]);
                    __int64* dst = reinterpret_cast<__int64*>(reinterpret_cast<char*>(entries) + byteOffset);
                    int j = 0;
                    do
                    {
                        dst[j] = src[j];
                        ++j;
                    } while (j < 2);
                }
                return;
            }
            ++i;
            ++current;
        } while (i < n);
    }
}

class hkMemoryAllocatorDC92;

struct hkMemoryRouterDC92
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC92* m_pStreamAllocator;
};

namespace hkRouterDC92 {
extern "C" hkMemoryRouterDC92& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

class hkMapDC92
{
  public:
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    char* SetBoolFromThreshold(char* out, int it);
    bool isValid(int it)
    {
        char valid;
        SetBoolFromThreshold(&valid, it);
        return valid != 0;
    }
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int it);
    int FindNextUsedSlot(int it);

    void hkDataWorldDict_ObjectTracker_findTrackedClasses(hkArray<int>& out);
};

// Iterates over all used slots in the map and appends each slot's value to the output array.
// @fnv 0x00dc9240
// src: XBOX_PDB 0x00dc9240
void hkMapDC92::hkDataWorldDict_ObjectTracker_findTrackedClasses(hkArray<int>& apUsedValues)
{
    for (int it = hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator(); isValid(it); it = FindNextUsedSlot(it))
    {
        apUsedValues.pushBack(hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(it));
    }
}

class hkMemoryAllocatorDC9;
struct hkMemoryRouterDC9
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9* m_pStreamAllocator;
};
hkMemoryRouterDC9* __cdecl GetMemoryRouterDC9() throw();
void __cdecl ReserveMoreDC9(hkMemoryAllocatorDC9* pkHeap, void* pkArray, int iElemSize);

template <typename T> inline void ConstructWithCopyDC9(T* pDst, int iCount, const T& kItem)
{
    for (int i = 0; i < iCount; ++i)
        pDst[i] = kItem;
}
template <typename T> inline void PushBackDC9(hkArray<T>& kArray, const T& kItem)
{
    hkMemoryRouterDC9* pkRouter = GetMemoryRouterDC9();
    if (kArray.m_iElementCount == (kArray.m_iCapacityState & 0x3fffffff))
        ReserveMoreDC9(pkRouter->m_pStreamAllocator, &kArray, sizeof(T));
    ConstructWithCopyDC9(kArray.m_data + kArray.m_iElementCount, 1, kItem);
    kArray.m_iElementCount++;
}
class ShapeDC9
{
};
class ShapeGroupDC9
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int GetNumShapes();
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
    virtual ShapeDC9* GetShape(int iIndex);
};
struct KeyDC9;
class LinkDC9
{
  public:
    virtual void v00();
    virtual void v04();
    virtual KeyDC9* GetKey();
};
struct OwnerDC9;
OwnerDC9* __stdcall FindOwnerDC9(KeyDC9* pkKey, int iFlags);
template <class T> struct MultiMapDC9
{
    struct Entry
    {
        T m_kValue;
        int m_iNext;
    };
    int Find(OwnerDC9* pkOwner);
    Entry* m_pkEntryArray;
};
class ShapeRegistryDC9
{
  public:
    void CollectShapes(KeyDC9* pkKey, int bRecurse, int bGroups, hkArray<ShapeDC9*>* pkShapesOut);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MultiMapDC9<LinkDC9*> m_kLinks;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    MultiMapDC9<ShapeDC9*> m_kShapes;
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
    MultiMapDC9<ShapeGroupDC9*> m_kObjectGroups;
};

// Collects ShapeDC9 pointers for pkKey's owner into pkShapesOut, optionally including object groups and recursing through linked keys.
// @fnv 0x00dc92d0
void ShapeRegistryDC9::CollectShapes(KeyDC9* pkKey, int bRecurse, int bGroups, hkArray<ShapeDC9*>* pkShapesOut)
{
    if (!pkKey)
        return;
    OwnerDC9* pkOwner = FindOwnerDC9(pkKey, 0);
    if (!pkOwner)
        return;
    for (int i = m_kShapes.Find(pkOwner); i != -1; i = m_kShapes.m_pkEntryArray[i].m_iNext)
    {
        ShapeDC9* pkShape = m_kShapes.m_pkEntryArray[i].m_kValue;
        PushBackDC9(*pkShapesOut, pkShape);
    }
    if (bGroups)
    {
        for (int i = m_kObjectGroups.Find(pkOwner); i != -1; i = m_kObjectGroups.m_pkEntryArray[i].m_iNext)
        {
            ShapeGroupDC9* pkGroup = m_kObjectGroups.m_pkEntryArray[i].m_kValue;
            for (int j = 0; j < pkGroup->GetNumShapes(); j++)
            {
                ShapeDC9* pkShape = pkGroup->GetShape(j);
                PushBackDC9(*pkShapesOut, pkShape);
            }
        }
    }
    if (bRecurse)
    {
        for (int i = m_kLinks.Find(pkOwner); i != -1; i = m_kLinks.m_pkEntryArray[i].m_iNext)
        {
            LinkDC9* pkLink = m_kLinks.m_pkEntryArray[i].m_kValue;
            CollectShapes(pkLink->GetKey(), bRecurse, bGroups, pkShapesOut);
        }
    }
}

char* __cdecl StrDup9570(const char* pcString);

struct StringMap9570
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct Registry9570
{
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
    StringMap9570 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDup9570(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct RegistryHolder9570
{
    int unk00;
    int unk04;
    Registry9570* m_pkRegistry;
};

struct PooledName9570
{
    PooledName9570(const char* pcName)
    {
        m_pcName = pcName;
    }
    const char* m_pcName;
};

class Owner9570
{
  public:
    PooledName9570 GetPooledNameOrEmpty(const char* pcName);
    int unk00;
    int unk04;
    int unk08;
    RegistryHolder9570* m_pkHolder;
};

// Returns a PooledName9570 wrapping the pooled string from the registry for pcName, or an empty PooledName9570 if pcName is null.
// @fnv 0x00dc9570
// src: GUESS 0x00dc9570 (confidence: high)
PooledName9570 Owner9570::GetPooledNameOrEmpty(const char* pcName)
{
    Registry9570* pkRegistry = m_pkHolder->m_pkRegistry;
    if (pcName)
        return PooledName9570(pkRegistry->GetPooled(pcName));
    return PooledName9570(0);
}

class hkMemoryAllocatorDC9E;

struct hkMemoryRouterDC9E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDC9E* m_pStreamAllocator;

    hkMemoryAllocatorDC9E& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDC9E {
extern "C" hkMemoryRouterDC9E& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkMapDC9E
{
  public:
    unsigned long LookupHashEntry(unsigned long key, unsigned long def);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocatorDC9E& alloc, unsigned long key, unsigned long val);
    int unk00[2];
};

struct KeyDC9E
{
    unsigned long m_iOwnerObjectOffset;
};

struct EntryDC9E
{
    unsigned long m_iOwnerObjectOffset;
    unsigned long m_next;
};

class OwnerDC9E
{
  public:
    EntryDC9E* m_pEntries;
    int unk04[2];
    hkMapDC9E m_kFormatEntries;

    int AllocateSlot();
    void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(unsigned long key, const KeyDC9E* pkVal);
};

// Looks up an existing entry for key, allocates a slot, links the new entry to the old one, and stores the slot index in m_kFormatEntries.
// @fnv 0x00dc9ec0
// src: XBOX_PDB 0x00dc9ec0
void OwnerDC9E::hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(unsigned long key, const KeyDC9E* pkVal)
{
    unsigned long uiOldIndex = m_kFormatEntries.LookupHashEntry(key, (unsigned long)-1);
    int iNewIndex = AllocateSlot();
    EntryDC9E& kEntry = m_pEntries[iNewIndex];
    kEntry.m_iOwnerObjectOffset = pkVal->m_iOwnerObjectOffset;
    kEntry.m_next = uiOldIndex;
    hkMemoryAllocatorDC9E* heap = hkRouterDC9E::hkMemoryRouter_getInstance().m_pStreamAllocator;
    m_kFormatEntries.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(*heap, key, iNewIndex);
}

extern int DAT_010d6fe4;

extern "C" void _ReadWriteBarrier(void);

struct FUN_00dca040_class
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    void* __thiscall Init(void* arg);
};

// @fnv 0x00dca040
void* FUN_00dca040_class::Init(void* arg)
{
    m6 = 0;
    _ReadWriteBarrier();
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0x80000000;
    m0 = (void*)&DAT_010d6fe4;
    if (arg != 0)
        ((int*)arg)[2]++;
    m18 = (int)arg;
    return (void*)this;
}

class hkMemoryAllocatorDCA5;

struct hkMemoryRouterDCA5
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorDCA5* m_pTemp;
    hkMemoryAllocatorDCA5* m_pStreamAllocator;
    hkMemoryAllocatorDCA5& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterDCA5& __cdecl hkMemoryRouter_getInstance() throw();
}
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDCA5& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkObjDCA5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<__int64> m_data;

    void CopyFrom(const __int64* src, int n);
};

// Sets m_data to n elements, then stores each source value after converting it to int.
// @fnv 0x00dca540
void hkObjDCA5::CopyFrom(const __int64* src, int aiCount)
{
    m_data.setSize(aiCount);
    for (int i = 0; i < aiCount; i++)
        m_data.m_data[i] = (int)src[i];
}

class Obj
{
  public:
    virtual void v0();
    virtual void v1();
    virtual const char* getName();
    virtual void v3();
    virtual void* GetIteratorKey();
};
struct Find
{
    char* SetBoolFromThreshold(char*, int);
};
struct Add
{
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char*, int);
};
// Exe 0x00dca820: unit-local Map view; declarations and layout are preserved.
struct HkdataobjectdictMapView
{
    void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(void*, Obj**);
};
struct Registry
{
    int a, b, c, d;
    HkdataobjectdictMapView map;
    int FindStringKey(const char*);
    void RegisterObject(Obj* volatile obj);
};
// Looks up the object's name and, if absent, calls the add routine and adds it to the map when its iterator key is non-null.
// @fnv 0x00dca820
void Registry::RegisterObject(Obj* volatile apObject)
{
    Obj* const current = apObject;
    void* key = current->GetIteratorKey();
    const char* name = current->getName();
    int it = FindStringKey(name);
    char valid;
    reinterpret_cast<Find*>(this)->SetBoolFromThreshold(&valid, it);
    if (!valid)
    {
        const char* pName2 = current->getName();
        reinterpret_cast<Add*>(this)->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pName2, (int)current);
        if (key)
            map.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(key, const_cast<Obj**>(&apObject));
    }
}

struct DCAAObject
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* GetIteratorKey();
};
struct DCAAMapEntry
{
    DCAAObject* value;
    int next;
};
struct DCAAMap
{
    DCAAMapEntry* entries;
    int __thiscall LookupWithDefault(void* key);
    void __thiscall hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(void* key, int index);
    void __thiscall hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(void* key, DCAAObject** value);
};
struct DCAAOwner
{
    int unk00, unk04, unk08, unk0c;
    DCAAMap table;
    void __thiscall UpdateObjectKeyMapping(void* volatile key, DCAAObject* object);
};
// If key is non-null, removes a matching entry; if GetIteratorKey returns non-null, inserts the object under that key.
// @fnv 0x00dcaaf0
// src: GUESS 0x00dcaaf0 (confidence: medium)
void DCAAOwner::UpdateObjectKeyMapping(void* volatile key, DCAAObject* object)
{
    DCAAObject* pObject = object;
    void* pKey = key;
    if (pKey)
    {
        int index = table.LookupWithDefault(pKey);
        while (index != -1)
        {
            if (table.entries[index].value == pObject)
            {
                table.hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(pKey, index);
                break;
            }
            index = table.entries[index].next;
        }
    }
    void* nextKey = pObject->GetIteratorKey();
    if (nextKey)
        table.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(nextKey, &object);
}

char* __cdecl StrDupDCAC(const char* pcString);

struct StringMapDCAC
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct RegistryDCAC
{
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
    StringMapDCAC m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupDCAC(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};


struct RegistryHolderDCAC
{
    int unk00;
    int unk04;
    RegistryDCAC* m_pkRegistry;
};

struct NameHolderDCAC
{
    int unk00;
    int unk04;
    const char* m_pcName;
};


// Walks the class hierarchy, pooling each name and comparing it with the retained name.
// @fnv 0x00dcac80
hkBool hkDataClassDict::isSuperClass(const hkDataClassImpl* pkClass) const
{
    for (const hkDataClassImpl* pClass = pkClass; pClass; pClass = pClass->getParent())
    {
        const char* pcName = pClass->getName();
        RegistryDCAC* pkRegistry = reinterpret_cast<RegistryHolderDCAC*>(m_pOwningWorld)->m_pkRegistry;
        const char* pcPooled = pcName ? pkRegistry->GetPooled(pcName) : 0;
        if (pcPooled == reinterpret_cast<const NameHolderDCAC*>(m_name)->m_pcName)
            return true;
    }
    return false;
}

char* __cdecl StrDupADA0(const char* pcString);

struct StringMapADA0
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct RegistryADA0
{
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
    StringMapADA0 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupADA0(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct RegistryHolderADA0
{
    int unk00;
    int unk04;
    RegistryADA0* m_pkRegistry;
};


// Searches the class hierarchy for a member by name and returns its computed index, or -1 if not found.
// @fnv 0x00dcada0
int hkDataClassDict::getMemberIndexByName(const char* pcName) const
{
    RegistryADA0* pkRegistry = reinterpret_cast<RegistryHolderADA0*>(m_pOwningWorld)->m_pkRegistry;
    const char* pcPooled = pcName ? pkRegistry->GetPooled(pcName) : 0;
    for (const hkDataClassDict* pkClass = this; pkClass; pkClass = pkClass->parent)
    {
        for (int i = 0; i < pkClass->count; i++)
        {
            if (pkClass->members[i].name == pcPooled)
                return i - pkClass->getNumDeclaredMembers() + pkClass->getNumMembers();
        }
    }
    return -1;
}

class SourceDCB1
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Pair v03(int iKey);
};

class TargetDCB1
{
  public:
    void hkDataArrayImpl_set(void* pArg, Pair kPair);
};

struct EntryDCB1
{
    int iKey;
    TargetDCB1* pkTarget;
};

class FUN_00dcb1c0_C
{
  public:
    int unk00;
    int unk04;
    int unk08;
    EntryDCB1* m_pEntries;
    int m_iNumEntries;

    void ApplySourceToEntries(void* pArg, SourceDCB1* pkSource);
};

// Iterates m_pEntries, calling each entry's target with the source's value for that entry's key.
// @fnv 0x00dcb1c0
void FUN_00dcb1c0_C::ApplySourceToEntries(void* pArg, SourceDCB1* pkSource)
{
    for (int i = 0; i < m_iNumEntries; i++)
    {
        EntryDCB1& kEntry = m_pEntries[i];
        int iKey = kEntry.iKey;
        kEntry.pkTarget->hkDataArrayImpl_set(pArg, pkSource->v03(iKey));
    }
}

char* __cdecl StrDupB2B0(const char* pcString);

struct StringMapB2B0
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const;
    void insert(const char* pcKey, void* pvValue);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct RegistryB2B0
{
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
    StringMapB2B0 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.FindValueForKey(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = StrDupB2B0(pcName);
            m_kNodePool.insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
};

struct RegistryHolderB2B0
{
    int unk00;
    int unk04;
    RegistryB2B0* m_pkRegistry;
};

struct ContextB2B0
{
    int unk00;
    int unk04;
    int unk08;
    RegistryHolderB2B0* m_pkHolder;
};

struct EntryB2B0
{
    const char* m_pcName;
    int m_iValue;
};

class TableB2B0
{
  public:
    int StructArrayImplementation__find(const char* pcName);
    int unk00;
    int unk04;
    int unk08;
    EntryB2B0* m_pkEntryArray;
    int m_iNumEntries;
    int unk14;
    ContextB2B0* m_pkContext;
};

// Pools pcName via m_pkContext's registry and returns the index of the matching entry in m_pkEntryArray, or -1 if not found.
// @fnv 0x00dcb2b0
// src: XBOX_PDB 0x00dcb2b0
int TableB2B0::StructArrayImplementation__find(const char* pcName)
{
    RegistryB2B0* pkRegistry = m_pkContext->m_pkHolder->m_pkRegistry;
    const char* pcPooled = pcName ? pkRegistry->GetPooled(pcName) : 0;
    for (int i = 0; i < m_iNumEntries; i++)
    {
        if (m_pkEntryArray[i].m_pcName == pcPooled)
            return i;
    }
    return -1;
}

template <class T> struct RefPtrDCB990
{
    ~RefPtrDCB990() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(T* e) throw()
    {
        if (e)
            e->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    T* m_pRetainedObject;
};
template <class T> __forceinline void DestructDCB990(T* t, int n) throw()
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <class T> struct ArrayDCB990LocalForm
{ // local form of hkArray: 0x00dcb990 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    __forceinline void clear() throw()
    {
        DestructDCB990(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease() throw()
    {
        hkMemoryRouter* pkRouter = &hkMemoryRouter::getInstance();
        hkMemoryAllocator& kHeap = pkRouter->heap();
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct EntryDCB990
{
    int unk00;
    RefPtrDCB990<hkReferencedObject> m_spShape;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct ObjectDCB990
{
    __forceinline ~ObjectDCB990() throw()
    {
        m_kPairs.ClearAndRelease();
    }
    static void operator delete(void* p, unsigned int nbytes) throw()
    {
        hkMemoryRouter* pkRouter = &hkMemoryRouter::getInstance();
        pkRouter->heap().blockFree(p, (int)nbytes);
    }
    int unk00;
    ArrayDCB990LocalForm<Pair> m_kPairs;
};
extern hkReferencedObject g_kDefaultDCB990;


// Clears class members and owned objects, then resets the retained name handle.
// @fnv 0x00dcb990
void __fastcall ClearDataClassDict(hkDataClassDict* pkClass, void*)
{
    reinterpret_cast<ArrayDCB990LocalForm<EntryDCB990>*>(&pkClass->members)[0].clear();
    for (int i = 0; i < reinterpret_cast<ArrayDCB990LocalForm<ObjectDCB990*>*>(&pkClass->unk1c)[0].m_iElementCount; i++)
        delete reinterpret_cast<ArrayDCB990LocalForm<ObjectDCB990*>*>(&pkClass->unk1c)[0].m_data[i];
    reinterpret_cast<ArrayDCB990LocalForm<ObjectDCB990*>*>(&pkClass->unk1c)[0].m_iElementCount = 0;
    reinterpret_cast<RefPtrDCB990<hkReferencedObject>*>(&pkClass->m_name)[0] = &g_kDefaultDCB990;
}

struct StringMapDC7
{
    void* GetValue(const char* pcKey, void* pvDefault) const;
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* pcKey, void* pvValue) throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct hkDataObjectDictDC7;
struct hkDataArrayDictDC7;

struct RegistryDC7
{
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
    StringMapDC7 m_kNodePool;

    const char* GetPooled(const char* pcName)
    {
        const char* pcPooled = (const char*)m_kNodePool.GetValue(pcName, 0);
        if (!pcPooled)
        {
            pcPooled = hkString_strDup_00cb1410(pcName);
            m_kNodePool.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(pcPooled, (void*)pcPooled);
        }
        return pcPooled;
    }
    void CollectShapes(const char* pcName, int iRecurse, int iFlags,
                       hkArray<hkDataObjectDictDC7*>& kObjectsOut) throw();
    void CollectSlotIdsRecursively(hkDataClassDict* pkClass, int iRecurse, hkArray<hkDataArrayDictDC7*>& kArraysOut) throw();
};

struct ObjectMemberDC7
{
    const char* m_name;
    unsigned int m_type;
    unsigned int m_value0;
    unsigned int m_value1;
};
// Retained: include/hkDataObjectDict.h is absent; member array is at 0x10.
struct hkDataObjectDictDC7
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkArray<ObjectMemberDC7> m_members;
};

struct ArrayMemberDC7
{
    const char* m_name;
    unsigned int m_uiFilterValue;
};
struct hkDataArrayDictDC7
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    hkArray<ArrayMemberDC7> m_members;
};

inline int FindMemberDeclDC7(const hkDataClassDict* pkClass, const char* pcName) throw()
{
    for (int i = pkClass->count - 1; i >= 0; i--)
    {
        if (pkClass->members[i].name == pcName)
            return i;
    }
    return -1;
}


// Retained: include/hkDataClass.h is absent; requires the implementation handle and 0x00dba680.
class hkDataClassDC7
{
  public:
    const char* hkDataClass_getName() const;
    hkDataClassDict* m_pClassImpl;
};

// Retained: include/hkDataWorldDict.h is absent; requires the tracker at 0x08 and member rename.
class hkDataWorldDictDC7
{
  public:
    void RenameClassMember(hkDataClassDC7& kClass, const char* pcOldName, const char* pcNewName) throw();
    unsigned int unk00;
    unsigned int unk04;
    RegistryDC7* m_registry;
};

// Renames a member from pcOldName to pcNewName in object, array, and class member declarations of the given class.
// @fnv 0x00dc73f0
// src: GUESS 0x00dc73f0 (confidence: medium)
void hkDataWorldDictDC7::RenameClassMember(hkDataClassDC7& kClass, const char* pcOldName, const char* pcNewName)
{
    hkDataClassDict* pkClass = kClass.m_pClassImpl;
    RegistryDC7* pkReg = m_registry;
    const char* pcOld = pcOldName ? pkReg->GetPooled(pcOldName) : 0;
    pkReg = m_registry;
    const char* pcNew = pcNewName ? pkReg->GetPooled(pcNewName) : 0;

    hkArray<hkDataObjectDictDC7*> kObjects;
    const char* pcClassName = kClass.hkDataClass_getName();
    kObjects.m_iElementCount = 0;
    m_registry->CollectShapes(pcClassName, 1, 0, kObjects);
    for (int i = 0; i < kObjects.GetLogicalSize(); i++)
    {
        hkDataObjectDictDC7* pkObject = kObjects[i];
        for (int j = 0; j < pkObject->m_members.GetLogicalSize(); j++)
        {
            if (pkObject->m_members[j].m_name == pcOld)
            {
                pkObject->m_members[j].m_name = pcNew;
                break;
            }
        }
    }

    hkArray<hkDataArrayDictDC7*> kArrays;
    m_registry->CollectSlotIdsRecursively(pkClass, 1, kArrays);
    for (int i = 0; i < kArrays.GetLogicalSize(); i++)
    {
        hkDataArrayDictDC7* pkArray = kArrays[i];
        for (int j = 0; j < pkArray->m_members.GetLogicalSize(); j++)
        {
            ArrayMemberDC7& kMember = pkArray->m_members[j];
            if (kMember.m_name == pcOld)
            {
                kMember.m_name = pcNew;
                break;
            }
        }
    }

    pkClass->members[FindMemberDeclDC7(pkClass, pcOld)].name = pcNew;
}

extern int DAT_010d6ee4;

struct RefCounted_dc7c
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_flags;
    int m_sReferenceCount;
    void RetainReference()
    {
        ++m_sReferenceCount;
    }
};

struct Node_dc7c : RefCounted_dc7c
{
    RefCounted_dc7c* m_parent;
    void* volatile m_data;
    int m_iElementCount;
    int m_iCapacityState;
    static void* operator new(unsigned int nbytes) throw()
    {
        Node_dc7c* p = (Node_dc7c*)GetSerializationHeap(hkMemoryRouter::getInstance()).blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Node_dc7c(RefCounted_dc7c* parent) throw()
    {
        m_flags = 0;
        m_sReferenceCount = 0;
        m_vtbl = &DAT_010d6ee4;
        if (parent)
            parent->RetainReference();
        m_parent = parent;
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    const char* getName()
    {
        return ((const char*(__thiscall*)(Node_dc7c*))((void**)m_vtbl)[2])(this);
    }
};

struct NameView_dc7c
{
    virtual void slot0();
    virtual void slot1();
    virtual const char* getName();
};
struct NameMap_dc7c
{
    void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(const char* name, Node_dc7c** value);
};

struct Registry_dc7c
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    Node_dc7c* m_pHeadNode;
    NameMap_dc7c m_kNodeCollection;
};

struct Builder_dc7c
{
    int unk00, unk04;
    Registry_dc7c* m_registry;
    Node_dc7c* hkDataWorldDict_newObject(RefCounted_dc7c* const& parent);
};

// Allocates a Node_dc7c under parent, registers it in the registry's NameMap by name, and sets it as the head node if the registry is empty.
// @fnv 0x00dc7c40
// src: HAVOK_SRC 0x00dc7c40
Node_dc7c* Builder_dc7c::hkDataWorldDict_newObject(RefCounted_dc7c* const& parent)
{
    Node_dc7c* node = new Node_dc7c(parent);
    node->RetainReference();
    Registry_dc7c* registry = m_registry;
    {
        Node_dc7c* entry;
        NameView_dc7c* view = reinterpret_cast<NameView_dc7c*>(node);
        entry = node;
        const char* name = view->getName();
        registry->m_kNodeCollection.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(name, &entry);
    }
    if (!registry->m_pHeadNode)
        registry->m_pHeadNode = node;
    return node;
}

struct Alloc_dc8d
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

extern hkReferencedObject DAT_011b7c00;
extern int DAT_010d6da0;

struct StringPtr_dc8d
{
    const char* m_kStringBuffer;
};

class DataType_dc8d : public hkReferencedObject
{
  public:
    const char* m_name;
};

struct Map_dc8d
{
    void* GetValue(const char* name, const void* value) throw();
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* name, void* value) throw();
};

struct RegistryLayout_dc8d
{
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
    Map_dc8d m_map;
};

struct RegistryImpl_dc8d
{
    StringPtr_dc8d* GetPooledString(StringPtr_dc8d* out, const char* name) throw();
};

struct Registry_dc8d
{
    void* FindOrCreateTypeEntry(void* pvHandleOut, int iType) throw();
};

// For a nonzero type-name pointer, looks up or creates a registry entry and stores it in pvHandleOut.
// @fnv 0x00dc8d70
// src: GUESS 0x00dc8d70 (confidence: medium)
void* Registry_dc8d::FindOrCreateTypeEntry(void* pvDataTypeOut, int pcTypeName) throw()
{
    RegistryLayout_dc8d* registry = reinterpret_cast<RegistryLayout_dc8d*>(this);
    RegistryImpl_dc8d* impl = reinterpret_cast<RegistryImpl_dc8d*>(this);

    *(void**)pvDataTypeOut = 0;
    DAT_011b7c00.addReference();
    if (*(void**)pvDataTypeOut != 0)
        reinterpret_cast<hkReferencedObject*>(*(void**)pvDataTypeOut)->removeReference();

    *(void**)pvDataTypeOut = &DAT_011b7c00;

    if (pcTypeName != 0)
    {
        const char* name = reinterpret_cast<const char*>(pcTypeName);
        void* found = registry->m_map.GetValue(name, 0);

        if (found == 0)
        {
            hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
            Alloc_dc8d* allocator = *reinterpret_cast<Alloc_dc8d**>(reinterpret_cast<char*>(router) + 0x10);

            DataType_dc8d* dataType = reinterpret_cast<DataType_dc8d*>(allocator->AllocateMemoryBlock(12));

            StringPtr_dc8d local;
            dataType->m_usMemSizeAndFlags = 12;
            StringPtr_dc8d* result = impl->GetPooledString(&local, name);

            dataType->m_sReferenceCount = 1;
            *reinterpret_cast<void**>(dataType) = &DAT_010d6da0;

            const char* typeName = result->m_kStringBuffer;
            dataType->m_name = typeName;
            registry->m_map.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(typeName, dataType);
            found = dataType;
        }

        hkReferencedObject* object = reinterpret_cast<hkReferencedObject*>(found);
        object->addReference();
        if (*(void**)pvDataTypeOut != 0)
            reinterpret_cast<hkReferencedObject*>(*(void**)pvDataTypeOut)->removeReference();
        *(void**)pvDataTypeOut = found;
        return pvDataTypeOut;
    }

    return pvDataTypeOut;
}

struct hkRefObj_dc8e
{
    virtual void deleteThis(int flags);
    int unk04;
    int m_sReferenceCount;
    void removeReference()
    {
        if (--m_sReferenceCount == 0)
            deleteThis(1);
    }
};

inline void memMove4_dc8e(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(int*)((char*)dst + i) = *(const int*)((const char*)src + i);
}

struct S00dc8ea0_Obj
{
    int m_00;
    int m_04;
    int m_08;
    Pair* m_data;
    int m_iElementCount;
    void RemoveKeyedEntry(int key);
};

// Finds the Pair entry with the given key, releases its reference, shifts the remaining entries down, and decrements the count.
// @fnv 0x00dc8ea0
// src: GUESS 0x00dc8ea0 (confidence: medium)
void S00dc8ea0_Obj::RemoveKeyedEntry(int key)
{
    int count = m_iElementCount;
    for (int i = 0; i < count; i++)
    {
        Pair& pair = m_data[i];
        if (pair.a == key)
        {
            reinterpret_cast<hkRefObj_dc8e*>(pair.b)->removeReference();
            --m_iElementCount;
            memMove4_dc8e(&m_data[i], &m_data[i + 1], (m_iElementCount - i) * sizeof(Pair));
            return;
        }
    }
}

void __cdecl ResizeAudioStream(hkAllocatorDC76* alloc, void* array, int sizeOfElement);

struct MultiMapEntry_dc91
{
    void* m_uiFilterValue;
    int m_next;
};

struct MultiMap_dc91
{
    MultiMapEntry_dc91* m_data;
    int LookupWithDefault(const void* key);
};

struct Registry_dc91
{
    int unk00, unk04, unk08, unk0C;
    MultiMap_dc91 m_children;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68;
    MultiMap_dc91 m_iSlotIds;
    void CollectSlotIdsRecursively(const void* key, int recurse, hkArray<void*>& out);
};

// Collects slot IDs for a key from m_iSlotIds into out, and if recurse is set, recurses into m_children to gather their slot IDs as well.
// @fnv 0x00dc9180
// src: GUESS 0x00dc9180 (confidence: medium)
void Registry_dc91::CollectSlotIdsRecursively(const void* key, int recurse, hkArray<void*>& out)
{
    for (int i = m_iSlotIds.LookupWithDefault(key); i != -1; i = m_iSlotIds.m_data[i].m_next)
        out.pushBack(m_iSlotIds.m_data[i].m_uiFilterValue);
    if (recurse)
    {
        for (int j = m_children.LookupWithDefault(key); j != -1; j = m_children.m_data[j].m_next)
            CollectSlotIdsRecursively(m_children.m_data[j].m_uiFilterValue, recurse, out);
    }
}

typedef unsigned int hkUint32;
typedef unsigned __int64 hkUint64;

template <class T> struct hkRefPtrT
{
    T* m_pRetainedObject;
    __forceinline ~hkRefPtrT()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};

struct MemberInfoDC
{
    const char* m_name;
    hkRefPtrT<hkReferencedObject> m_pOwnerObject;
    int m_type;
    int m_tuple;
    int m_class;
    int m_uiFormID;
};

__forceinline void memCpyDC(void* dst, const void* src, int nbytes)
{
    char* d = static_cast<char*>(dst);
    const char* s = static_cast<const char*>(src);
    for (int i = 0; i < nbytes; i += 8)
    {
        *reinterpret_cast<hkUint64*>(d + i) = *reinterpret_cast<const hkUint64*>(s + i);
    }
}

template <class T> __forceinline void destructDC(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <class T> struct hkArrDCLocalForm
{ // local form of hkArray: 0x00dc9470 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void removeAtAndCopy(int index)
    {
        destructDC(m_data + index, 1);
        m_iElementCount--;
        memCpyDC(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
    }
};


// Searches backward for name, passes the matching index or -1 to removeAtAndCopy, then returns whether FindEntry finds name.
// The shared method returns void; this helper retains the game's computed EAX result.
// @fnv 0x00dc9470
int __fastcall RemoveClassMember(hkDataClassDict* pkClass, void*, const char* name)
{
    int idx;
    int i = pkClass->count - 1;
    if (i < 0)
        goto notfound;
    {
        MemberInfoDC* p = reinterpret_cast<MemberInfoDC*>(pkClass->members) + i;
        const char* key = (const char*)*(volatile const int*)&name;
        do
        {
            if (p->m_name == key)
                goto found;
            --i;
            --p;
        } while (i >= 0);
    }
notfound:
    idx = -1;
    goto tail;
found:
    idx = i;
tail:
    reinterpret_cast<hkArrDCLocalForm<MemberInfoDC>*>(&pkClass->members)->removeAtAndCopy(idx);
    return pkClass->FindEntry(name) != 0;
}

void __cdecl hkString_memCpy(void*, void const*, int);
// src: GUESS 0x00dc73e0 (confidence: low)
static __declspec(noinline) void* Object_ComputeValue_00dc73e0(int c)
{
    return (void*)(c + 1);
}
struct S00dc9950_heap
{
    virtual void* V0() throw();
    virtual void* alloc(int size) throw();
};
struct S00dc9950_pair
{
    int m_iWordAt00;
    int m_iWordAt04;
};
struct S00dc9950_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    char* m_10;
    void __thiscall hkDataObjectDict_assign(int a, int b, int c);
};
struct S00dc9950_9710
{
    int m_iWordAt00;
    void __thiscall hkDataObjectDict__writeAccess(void* out, int a, void* b);
};
// Calls FUN_00dc9710, allocates c*4 bytes, copies b there, and stores the pointer through m_10 at an indexed offset.
// @fnv 0x00dc9950
// src: XBOX_PDB 0x00dc9950
void __thiscall S00dc9950_cls::hkDataObjectDict_assign(int a, int apSource, int aiCount)
{
    S00dc9950_pair out;
    ((S00dc9950_9710*)this)->hkDataObjectDict__writeAccess(&out, a, Object_ComputeValue_00dc73e0(aiCount));
    hkAllocatorDC76& kAlloc = hkMemoryRouter_getInstance()->heap();
    void* data = ((S00dc9950_heap*)&kAlloc)->alloc(aiCount * 4);
    hkString_memCpy(data, (void*)apSource, aiCount * 4);
    *(void**)(this->m_10 + out.m_iWordAt04 * 16 + 8) = data;
}

namespace fnv_00dc9f20 {
extern hkReferencedObject DAT_011b7c00;

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct RefPtrX
{
    hkReferencedObject* m_pRetainedObject;
    RefPtrX() throw()
    {}
    RefPtrX(const RefPtrX& o) throw()
    {
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->addReference();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    __forceinline void set(const RefPtrX& o) throw()
    {
        DAT_011b7c00.addReference();
        if (o.m_pRetainedObject)
            o.m_pRetainedObject->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        DAT_011b7c00.removeReference();
        m_pRetainedObject = o.m_pRetainedObject;
    }
    ~RefPtrX() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
    }
};

struct KeyX
{
    int v;
};
struct InfoX
{
    InfoX() {}
    InfoX(const InfoX& o) : m_08(o.m_08) {}
    Pair m_08;
    int m_10;
    int m_14;
};
struct EntryX
{
    EntryX(const EntryX& o) throw() : m_key(o.m_key), m_ref(o.m_ref), m_info(o.m_info)
    {
        m_info.m_10 = o.m_info.m_10;
        m_info.m_14 = o.m_info.m_14;
    }

    KeyX m_key;
    RefPtrX m_ref;
    InfoX m_info;
    __forceinline EntryX() throw()
    {}
};

template <class T> struct ArrayXLocalForm
{ // local form of hkArray: 0x00dc9f20 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void AddBack(const T& e) throw()
    {
        hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pkHeap, this, sizeof(T));
        new (m_data + m_iElementCount) T(e);
        m_iElementCount++;
    }
};

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}


// Adds a class member declaration with its retained type and tuple information.
// @fnv 0x00dc9f20
// The game takes its key by value here; keep that ABI in a free helper over the shared class.
void __fastcall AddClassMember(hkDataClassDict* pkClass, void*, KeyX key, int aiInfo10, RefPtrX& ref, int aiInfo14)
{
    DAT_011b7c00.addReference();
    EntryX e;
    e.m_key = key;
    if (ref.m_pRetainedObject)
        ref.m_pRetainedObject->addReference();
    DAT_011b7c00.removeReference();
    e.m_ref.m_pRetainedObject = ref.m_pRetainedObject;
    e.m_info.m_10 = aiInfo10;
    e.m_info.m_14 = aiInfo14;
    reinterpret_cast<ArrayXLocalForm<EntryX>*>(&pkClass->members)->AddBack(e);
}
}  // namespace fnv_00dc9f20

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* mem, void* array, int numElements, int sizeOfElement);

struct Table_dca4
{
    int unk00, unk04, unk08;
    hkArray<__int64> m_iSlotIds;
    void IntArrayImplementation_setAll_00dca480(const unsigned short* src, int n);
};

// Grows m_iSlotIds to n elements and copies n unsigned short values from src into it.
// @fnv 0x00dca480
// src: XBOX_PDB 0x00dca480
void Table_dca4::IntArrayImplementation_setAll_00dca480(const unsigned short* src, int aiCount)
{
    m_iSlotIds.setSize(aiCount);
    for (int i = 0; i < aiCount; i++)
        m_iSlotIds[i] = src[i];
}

struct DCAB_Object
{
    virtual void vf00();
    virtual void vf04();
    virtual const char* GetName();
};
struct DCAB_Entry
{
    DCAB_Object* m_obj;
    int m_next;
};
struct DCAB_Map
{
    DCAB_Entry* m_entries;
    int LookupWithDefault(const char* name);
    void hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(const char* name, int index);
    void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(const char* name, DCAB_Object** value);
};
struct DCAB_Owner
{
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
    DCAB_Map m_map;
    void RenameMappedObject(DCAB_Object* object, const char* newName);
};
// Finds the entry for object in m_map by its current name and, if found, removes it and re-inserts it under newName.
// @fnv 0x00dcab50
// src: GUESS 0x00dcab50 (confidence: medium)
void DCAB_Owner::RenameMappedObject(DCAB_Object* object, const char* newName)
{
    DCAB_Object* obj = *(DCAB_Object* volatile*)&object;
    const char* name = obj->GetName();
    int index = m_map.LookupWithDefault(name);
    if (!name)
        return;
    do
    {
        if (index == -1)
            return;
        if (obj == m_map.m_entries[index].m_obj)
        {
            m_map.hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(name, index);
            m_map.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(newName, &object);
            name = 0;
        }
        index = m_map.m_entries[index].m_next;
    } while (name);
}

extern char DAT_010d73fc;

struct FUN_00dc9ec0_Obj
{
    __declspec(noalias) void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(void* a, void** b);
};

struct S00dcaeb0_Iface
{
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void* f6() = 0;
};


struct DcaeRefPtr
{
    hkDataClassDict* m_pRetainedObject;
    __forceinline DcaeRefPtr(hkDataClassDict* e)
    {
        if (e)
            e->m_count++;
        m_pRetainedObject = e;
    }
    hkDataClassDict* operator->() const
    {
        return m_pRetainedObject;
    }
};

struct DcaeBase
{
    void* m0;
    unsigned short m4;
    unsigned short m6;
    void* m8;
    __forceinline DcaeBase()
    {
        m6 = 0;
        m8 = 0;
    }
};

struct DcaeBase2 : DcaeBase
{
    __forceinline DcaeBase2()
    {
        m0 = &DAT_010d73fc;
    }
};

struct DcaeArray
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
    __forceinline DcaeArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

struct FUN_00dcaeb0 : DcaeBase2
{
    DcaeArray m_aiIndexedValues;
    DcaeRefPtr m18;
    void* m1c;

    void AddNodeEntry(void* p);
    FUN_00dcaeb0(hkDataClassDict* p);
};

// Initializes entries from the retained node, then passes this object and a value to a function reached through the retained node.
// @fnv 0x00dcaeb0
FUN_00dcaeb0::FUN_00dcaeb0(hkDataClassDict* apNode) : m18(apNode), m1c(0)
{
    for (int index = 0; index < m18->getNumMembers(); index++)
    {
        hkDataClassDict* root = m18.m_pRetainedObject;
        int position = index - root->getNumMembers();
        hkDataClassDict* current = root;
        do
        {
            position += current->count;
            if (position >= 0)
                break;
            current = current->parent;
        } while (current != 0);
        char* element;
        if (position >= 0)
            element = reinterpret_cast<char*>(current->members) + position * 0x18;
        else
            element = reinterpret_cast<char*>(root->members) - 0x18;
        AddNodeEntry(element);
    }
    FUN_00dcaeb0* argument = this;
    const void* holder = m18->getWorld();
    void* tracker = *(void**)((const char*)holder + 8);
    void* value = ((S00dcaeb0_Iface*)this)->f6();
    ((FUN_00dc9ec0_Obj*)((char*)tracker + 0x6c))->hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_insert(value, (void**)&argument);
}

class FUN_00dbab70
{
  public:
    void* m_p;
    ~FUN_00dbab70() throw();
};
class FUN_00dba7f0
{
  public:
    void* m_p;
    ~FUN_00dba7f0() throw();
};
class AF70Variant
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00dbab70* GetResult(FUN_00dbab70* out) const throw();
    int ForwardCall_00dba990() const throw();
    float InvokeVirtualMethod_00dbaa00() const throw();
    int DispatchToInterface(int sz) const throw();
    FUN_00dba7f0* GetWrappedDataObject(FUN_00dba7f0* out) const throw();
    int hkDataObject_Value_asString() const throw();
};
class AF70Owner
{
  public:
    virtual void v00();
    virtual int GetType() throw();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void Set24(int idx, int v) throw();
    virtual void v28();
    virtual void Set2c(int idx, int v) throw();
    virtual void v30();
    virtual void Set34(int idx, float v) throw();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void Set44(int idx, int v) throw();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void Set54(int idx, void* v) throw();
    virtual void v58();
    virtual void Set5c(int idx, void* v) throw();
    void hkDataArrayImpl_set(int idx, AF70Variant v) throw();
};
// Stores an AF70Variant value at index idx by dispatching on GetType() to the matching SetXX accessor.
// @fnv 0x00dcaf70
// src: XBOX_PDB 0x00dcaf70
void AF70Owner::hkDataArrayImpl_set(int aiIndex, AF70Variant avVariant)
{
    if (GetType() & 0x20)
    {
        FUN_00dbab70 t;
        FUN_00dbab70* r = avVariant.GetResult(&t);
        Set5c(aiIndex, r->m_p);
        return;
    }
    switch (GetType())
    {
    case 1:
    case 2:
        Set44(aiIndex, avVariant.ForwardCall_00dba990());
        break;
    case 3:
        Set34(aiIndex, avVariant.InvokeVirtualMethod_00dbaa00());
        break;
    case 4:
    case 5:
    case 6:
    case 7: {
        int t = GetType();
        Set24(aiIndex, avVariant.DispatchToInterface(t * 4 - 12));
    }
    break;
    case 8:
    case 9: {
        FUN_00dba7f0 t;
        FUN_00dba7f0* r = avVariant.GetWrappedDataObject(&t);
        Set54(aiIndex, r->m_p);
    }
    break;
    case 10:
        Set2c(aiIndex, avVariant.hkDataObject_Value_asString());
        break;
    }
}

struct hkSerializeMultiMapDC90 : hkMultiMapDC90
{
    int hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(int key, int index);
};

// Removes the entry at index from its hash chain, adds it to the free list, and returns the next chain index.
// @fnv 0x00dcb4b0
// src: XBOX_PDB 0x00dcb4b0
int hkSerializeMultiMapDC90::hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(int key, int index)
{
    int next = m_ppLinks[index].m_next;
    int freed = next;
    if (next != -1)
    {
        m_ppLinks[index] = m_ppLinks[next];
        next = index;
    }
    else
    {
        int it = m_pHashFunction.FindSlot(key);
        int* startp = &m_pHashFunction.m_kPrimitiveElement[it].val;
        freed = *startp;
        if (freed == index)
        {
            *startp = -1;
            freed = index;
        }
        else
        {
            int* nextp = &m_ppLinks[freed].m_next;
            if (*nextp == index)
            {
                *nextp = -1;
                freed = index;
            }
            else
            {
                *startp = *nextp;
                m_ppLinks[index].m_uiFilterValue = m_ppLinks[freed].m_uiFilterValue;
            }
        }
    }
    m_ppLinks[freed].m_next = m_kFreeListEntries;
    m_kFreeListEntries = freed;
    return next;
}

namespace fnv_00dcbcd0 {
// src: GUESS 0x00dc73e0 (confidence: low)
__declspec(noinline) static int Object_ComputeValue_00dc73e0(int x)
{
    return (x >> 2) + 3;
}

struct MyObj : hkObjDCB
{
    int hkDataObjectDict_asVec(int iKey, int iType);
};

// @fnv 0x00dcbcd0
// src: XBOX_PDB 0x00dcbcd0
int MyObj::hkDataObjectDict_asVec(int iKey, int iType)
{
    int mode = Object_ComputeValue_00dc73e0(iType);
    hkResultDCB res = hkDataObjectDict__readAccess(iKey, mode);
    return m_entries[res.m_uiEdgeIndex].m_uiFilterValue;
}
}  // namespace fnv_00dcbcd0

hkBool __cdecl CheckMagicPair(unsigned int magic0, unsigned int magic1);

struct Stream_dcca
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual int read(void* buf, int nbytes);
    virtual void v14();
    virtual void v18();
    virtual void SetCurrentOffset(int aiNewOffset);
    virtual void GetCurrentOffset();
};

struct Format_dcca
{
    int m_uiFilterValue;
    Format_dcca(int v) : m_uiFilterValue(v)
    {}
};

// Seeks to offset 16, reads 16 bytes of magic, and returns a Format_dcca indicating which magic pair matched.
// @fnv 0x00dcca60
// src: XBOX_PDB 0x00dcca60
Format_dcca __cdecl hkTagfileReader_detectFormat(Stream_dcca* stream)
{
    unsigned int magicBytes[4];
    stream->SetCurrentOffset(16);
    if (stream->read(magicBytes, 16) != 16)
        return Format_dcca(0);
    stream->GetCurrentOffset();
    if (CheckMagicPair(magicBytes[0], magicBytes[1]))
        return Format_dcca(2);
    return Format_dcca(1);
}

char* __cdecl hkString_strDup_00cb1410(const char*);
struct Crux53_StringMap
{
    void* GetValue(const char*, int);
    void* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(void*, void*);
};
struct Crux53_MapBody
{
    int a00, a04, a08, a0c, a10, a14, a18, a1c, a20, a24, a28, a2c, a30, a34, a38, a3c, a40, a44, a48;
    Crux53_StringMap map4c;
    void* InternString(const char* key)
    {
        if (key)
        {
            void* value = map4c.GetValue(key, 0);
            if (!value)
            {
                value = hkString_strDup_00cb1410(key);
                map4c.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(value, value);
            }
            return value;
        }
        return 0;
    }
};
struct Crux53_MapInner
{
    void* a00;
    void* a04;
    Crux53_MapBody* a08;
};
struct Crux53_MapOuter
{
    void* a00;
    void* a04;
    void* a08;
    Crux53_MapInner* a0c;
};
struct Crux53_Entry
{
    void* key;
    void* obj;
};
struct Crux53_Owner
{
    void* a00;
    void* a04;
    void* a08;
    Crux53_Entry* entries;
    int count;
    void* a14;
    Crux53_MapOuter* outer;
    int SetItemContextByKey(void*);
    int StructArrayImplementation__findOrAdd(const char*);
};
// Interns key, scans entries for a matching key, returns its index if found, otherwise calls SetItemContextByKey and returns its result.
// @fnv 0x00dcb5d0
// src: XBOX_PDB 0x00dcb5d0
int Crux53_Owner::StructArrayImplementation__findOrAdd(const char* key)
{
    void* value = outer->a0c->a08->InternString(key);
    int i = 0;
    if (count > 0)
    {
        Crux53_Entry* e = entries;
        do
        {
            if (e->key == value)
            {
                if (i != -1)
                    return i;
                break;
            }
            ++i;
            ++e;
        } while (i < count);
    }
    return SetItemContextByKey(value);
}

void ResizeAudioStream(void* mem, void* arr, int elemSize) throw();

struct FUN_00d479e0_class
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;

    void* GetValue(const void* key, const void* defVal) throw();
    void ProcessAndReturnValue_00d87820(const void* key) throw();
};

struct TargetInfo
{
    virtual void unk0() throw();
    virtual void unk1() throw();
    virtual void unk2() throw();
    virtual void unk3() throw();
    virtual void* GetSubTarget() throw();
};

struct Node
{
    virtual ~Node() throw();
    virtual void unkSlot1() throw();
    virtual void* GetTarget() throw();
    int unk04;
    int m_iObjectReferenceCount;

    void ClearEntries() throw();

    void Release() throw()
    {
        if (--m_iObjectReferenceCount == 0)
        {
            delete this;
        }
    }
};

struct MultimapEntry
{
    Node* val;
    int next;
};

struct Multimap
{
    MultimapEntry* m_entries;
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

    int LookupWithDefault(void* key) throw();
    void hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(void* key, int index) throw();
// src: XBOX_PDB 0x00dc8fe0
    void hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_removeByValue(void* key, Node* const& node) throw()
    {
        for (int it = LookupWithDefault(key); it != -1; it = m_entries[it].next)
        {
            if (m_entries[it].val == node)
            {
                hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(key, it);
                return;
            }
        }
    }
    void RemoveKey(void* key) throw();
};

struct hkMemory
{
    virtual void unk0() throw();
    virtual void unk1() throw();
    virtual void unk2() throw();
    virtual void unk3() throw();
    virtual void deallocate(void* p, int nbytes) throw();
};

inline hkThreadMemory* hkThreadMemory::GetMonitorStream() throw()
{
    return reinterpret_cast<hkThreadMemory*>(::hkMemoryRouter_getInstance());
}

// This entry point returns a memory router; its first word is the stack cursor.
inline void*& hkStackCursor(hkThreadMemory* router) throw()
{
    return *reinterpret_cast<void**>(router);
}

inline void hkDeallocateStack(void* p) throw()
{
    hkStackCursor(hkThreadMemory::GetMonitorStream()) = p;
}

template <typename T> struct StackAllocatedArray : public hkArray<T>
{
    T* m_pStackAllocation;

    StackAllocatedArray(int capacity) throw()
    {
        hkThreadMemory* tm = hkThreadMemory::GetMonitorStream();
        void* stack = hkStackCursor(tm);
        hkStackCursor(tm) = (char*)stack + capacity * sizeof(T);
        m_data = (T*)stack;
        m_pStackAllocation = (T*)stack;
        m_iCapacityState = 0x80000000 | capacity;
    }

    ~StackAllocatedArray() throw()
    {
        if (m_pStackAllocation == m_data)
        {
            m_iElementCount = 0;
        }
        hkDeallocateStack(m_pStackAllocation);
    }

    void AddBack(T val) throw()
    {
        hkThreadMemory* tm = hkThreadMemory::GetMonitorStream();
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ResizeAudioStream(tm->m_pMemoryAllocator, this, sizeof(T));
        }
        m_data[m_iElementCount++] = val;
    }
};

struct ManagerClass : public FUN_00d479e0_class
{
    Multimap m_multimap;
    FUN_00d479e0_class m_map5c;

    void hkDataWorldDict_ObjectTracker_untrackClass(Node* arg0) throw();
    void hkDataWorldDict_ObjectTracker_removeClassContent(Node* arg0) throw();
};

// Recursively removes a Node from the multimap and reference maps, releasing child nodes and their references.
// @fnv 0x00dcbdd0
// src: XBOX_PDB 0x00dcbdd0
void ManagerClass::hkDataWorldDict_ObjectTracker_untrackClass(Node* apNode) throw()
{
    void* target = apNode->GetTarget();
    TargetInfo* targetInfo = target ? (TargetInfo*)this->GetValue(target, 0) : 0;
    this->hkDataWorldDict_ObjectTracker_removeClassContent(apNode);
    void* subTarget = targetInfo->GetSubTarget();
    if (subTarget != 0)
    {
        this->m_multimap.hkSerializeMultiMap_hkDataClassDict_hkDataClassDict_removeByValue(subTarget, apNode);
    }
    apNode->ClearEntries();

    {
        StackAllocatedArray<Node*> stackNodes(64);
        int it = this->m_multimap.LookupWithDefault(apNode);
        bool hasKey = (it != -1);
        if (hasKey)
        {
            while (it != -1)
            {
                Node* v = this->m_multimap.m_entries[it].val;
                stackNodes.AddBack(v);
                it = this->m_multimap.m_entries[it].next;
            }
        }

        for (int i = 0; i < stackNodes.m_iElementCount; i++)
        {
            this->hkDataWorldDict_ObjectTracker_untrackClass(stackNodes.m_data[i]);
            stackNodes.m_data[i]->Release();
        }

        if (hasKey)
        {
            this->m_multimap.RemoveKey(apNode);
        }
    }

    hkReferencedObject* refObj = (hkReferencedObject*)this->m_map5c.GetValue(target, 0);
    this->m_map5c.ProcessAndReturnValue_00d87820(target);
    refObj->removeReference();
    this->ProcessAndReturnValue_00d87820(target);
}

struct hkDataObjectImpl : hkDataRefCounted
{
};

union hkDataValue
{
    __int64 integer;
    float real;
    hkDataRefCounted* object;
    char* string;
    void* allocation;
};
struct hkDataMemberValue
{
    const char* name;
    int unk04;
    hkDataValue value;
};

void __cdecl ReleaseDataValues(int type, hkDataValue* values, int count);
struct hkDataObjectDict : hkDataObjectImpl
{
    hkDataClassDict* pClassInfo;
    hkArray<hkDataMemberValue> members;
    void selfDestruct();
};
// Iterates over each member in the hkArray, releases its data value using the type from the class dictionary, then clears the array.
// @fnv 0x00dc90a0
// src: XBOX_PDB 0x00dc90a0
void hkDataObjectDict::selfDestruct()
{
    int index = 0;
    if (members.GetLogicalSize() > index)
    {
        do
        {
            hkDataMemberValue* entry = (members.m_data + index);
            hkDataMemberInfo* metadata = pClassInfo->FindEntry((members.m_data + index)->name);
            if (metadata)
                ReleaseDataValues(metadata->type, &entry->value, 1);
            ++index;
        } while (index < members.GetLogicalSize());
    }
    members.clear();
}

extern "C" void _ReadBarrier();
class hkMemoryAllocatorDCA
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterDCA
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorDCA* m_pTemp;
    hkMemoryAllocatorDCA* m_pStreamAllocator;
    hkMemoryAllocatorDCA& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterDCA& __cdecl GetMemoryRouterDCA() throw();

template <typename T> __forceinline T* hkAllocateStackDCA(int n)
{
    hkMemoryRouterDCA& kRouter = GetMemoryRouterDCA();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackDCA(T* p)
{
    GetMemoryRouterDCA().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayDCA : public hkArray<T>
{
    __forceinline hkLocalArrayDCA(int n) throw()
    {
        T* pLocal = hkAllocateStackDCA<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayDCA() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackDCA(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

class hkOstreamDCA
{
  public:
    hkOstreamDCA(void* pvBuffer, int iSize) throw();
    ~hkOstreamDCA() throw();
    hkOstreamDCA& operator<<(const char* pcString) throw();
    hkOstreamDCA& operator<<(int i) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};

// clearMembers binds to concrete hkDataObjectDict code at 0x00dc90a0, not hkDataObjectImpl.
class DictionaryObjectRemovalTarget
{
  public:
    virtual ~DictionaryObjectRemovalTarget() throw();
    virtual void v04();
    virtual hkDataClassImpl* GetVariantValue() const throw();
    void removeReference() throw()
    {
        if (--m_uiItemCount == 0)
            delete this;
    }
    void clearMembers() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_iReferenceCount;
    int m_uiItemCount;
};

struct hkPointerMapDCA
{
    int FindValueForKey(const void* pvKey, int iDefault) const throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

template <typename K, typename V> class hkSerializeMultiMapDCA
{
  public:
    int getFirstIndex(K k) const throw();
    int GetNextChainIndex(int i) const
    {
        return m_kChainValues[i].m_next;
    }
    V getValue(int i) const
    {
        return m_kChainValues[i].m_uiFilterValue;
    }
    void RemoveValuesForKey(K k) throw();
    struct Value
    {
        V m_uiFilterValue;
        int m_next;
    };
    hkArray<Value> m_kChainValues;
    hkPointerMapDCA m_pHashFunction;
};

class hkDataWorldDictTrackerDCA
{
  public:
    int getClassKey(const hkDataClassImpl* pkClass, int iDefault) const throw();
    void hkDataWorldDict_ObjectTracker_removeClassContent(DictionaryObjectRemovalTarget* pkObject) throw();

    hkPointerMapDCA m_kLookupMap;
    unsigned int unk0c;
    hkSerializeMultiMapDCA<DictionaryObjectRemovalTarget*, DictionaryObjectRemovalTarget*> m_children;
    unsigned int unk28;
    DictionaryObjectRemovalTarget* m_pParent;
    hkSerializeMultiMapDCA<int, DictionaryObjectRemovalTarget*> m_kChildrenByIndex;
};

// Recursively removes pkObject and its children from the tracker, clearing members and releasing references while warning about external references.
// @fnv 0x00dca890
// src: XBOX_PDB 0x00dca890
void hkDataWorldDictTrackerDCA::hkDataWorldDict_ObjectTracker_removeClassContent(DictionaryObjectRemovalTarget* pkObject) throw()
{
    hkDataClassImpl* pkClass = pkObject->GetVariantValue();
    int iClassKey = pkClass ? getClassKey(pkClass, 0) : 0;

    for (int i = m_children.getFirstIndex(pkObject); i != -1; i = m_children.GetNextChainIndex(i))
    {
        hkDataWorldDict_ObjectTracker_removeClassContent(m_children.getValue(i));
    }

    int iIndex = m_kChildrenByIndex.getFirstIndex(iClassKey);
    if (iIndex != -1)
    {
        hkLocalArrayDCA<DictionaryObjectRemovalTarget*> kObjects(0x200);
        for (; iIndex != -1; iIndex = m_kChildrenByIndex.GetNextChainIndex(iIndex))
        {
            kObjects.pushBack(m_kChildrenByIndex.getValue(iIndex));
        }
        int j;
        _ReadBarrier();
        for (j = 0; j < kObjects.GetLogicalSize(); j++)
        {
            if (m_pParent == kObjects[j])
                m_pParent = 0;
            if (kObjects[j]->m_iReferenceCount > 0)
            {
                unsigned int warnBuf[128];
                hkOstreamDCA ostr(warnBuf, sizeof(warnBuf));
                ostr
                    << "The object of class " << kObjects[j]->GetVariantValue()->getName()
                    << " is about to be removed and all references to it will be invalid.\nHowever, the object is referenced ("
                    << kObjects[j]->m_iReferenceCount
                    << ") from outside the world and it will lead to unexpected behavior or crash.";
                hkError::s_instance->message(1, 0x760d3794, (const char*)warnBuf, ".\\Data\\Dict\\hkDataObjectDict.cpp",
                                      0x7b9);
            }
            kObjects[j]->clearMembers();
        }
        _ReadBarrier();
        for (j = 0; j < kObjects.GetLogicalSize(); j++)
        {
            kObjects[j]->removeReference();
        }
        m_kChildrenByIndex.RemoveValuesForKey(iClassKey);
    }
}

namespace fnv_00dc95d0 {
// FUN_00dc95d0: string-table lookup + registered-entry scan.

struct FUN_00d874d0_s
{
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(char const* name, int value);
};

struct FUN_00d479e0_class : FUN_00d874d0_s
{
    void* GetValue(void const* key, void const* fallback);
};

struct Holder_dc95d0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
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
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    FUN_00d479e0_class m_4c;
};

struct ChainB_dc95d0
{
    void* m_00;
    void* m_04;
    Holder_dc95d0* volatile m_08;
    void* m_0c;
};

struct ChainA_dc95d0
{
    void* m_00;
    void* m_04;
    void* m_08;
    ChainB_dc95d0* m_0c;
};

struct Entry_dc95d0
{
    void* key;
    void* m_04;
    void* m_08;
    void* m_0c;
};

struct Ctx_dc95d0
{
    void* m_00;
    void* m_04;
    void* m_08;
    ChainA_dc95d0* m_0c;
    Entry_dc95d0* m_10;
    int m_14;
    int hkDataObjectDict_hasMember(void const* key);
};

extern "C" void* hkString_strDup_00cb1410(void const* key);

inline void* Intern_dc95d0(Holder_dc95d0* holder, const void* key)
{
    void* value;
    if (key)
    {
        FUN_00d479e0_class* t = &holder->m_4c;
        value = t->GetValue(key, 0);
        if (!value)
        {
            value = hkString_strDup_00cb1410(key);
            t->hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert((const char*)value, (int)value);
        }
        return value;
    }
    return 0;
}

// Interns the key via Intern_dc95d0 and returns 1 if the interned value matches any entry key in the m_10 array, else 0.
// @fnv 0x00dc95d0
// src: XBOX_PDB 0x00dc95d0
int Ctx_dc95d0::hkDataObjectDict_hasMember(void const* key)
{
    void* value = Intern_dc95d0(m_0c->m_0c->m_08, key);
    int count = m_14;
    for (int i = 0; i < count; i++)
    {
        if (m_10[i].key == value)
            return 1;
    }
    return 0;
}
}  // namespace fnv_00dc95d0

namespace fnv_00dc9640 {
struct FUN_00d47a80_class
{
    void* GetValue(void* key, int def);
    void hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(const char* key, int value);
};

extern "C" char* __cdecl hkString_strDup_00cb1410(const char* s);

struct hkWorldDC96
{
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
    FUN_00d47a80_class m_pStringFunctions;
};

struct hkHolderDC96
{
    int unk00;
    int unk04;
    hkWorldDC96* m_pOwningWorld;
};

struct hkOwnerDC96
{
    int unk00;
    int unk04;
    int unk08;
    hkHolderDC96* m_holder;
};

class hkNameDC96;

struct hkNameRefDC96
{
    hkNameDC96* m_pOwnerObject;
    char* m_name;
};

inline char* internDC96(hkWorldDC96* world, const char* name)
{
    if (name)
    {
        char* s = static_cast<char*>(world->m_pStringFunctions.GetValue(const_cast<char*>(name), 0));
        if (!s)
        {
            s = hkString_strDup_00cb1410(name);
            world->m_pStringFunctions.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_insert(s, reinterpret_cast<int>(s));
        }
        return s;
    }
    return 0;
}

class hkNameDC96
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkOwnerDC96* m_pOwnerObject;

    hkNameRefDC96 hkDataObjectDict_accessByName(const char* name);
};

// Interns the given name string in the owning world and returns a hkNameRefDC96 pointing to this hkNameDC96.
// @fnv 0x00dc9640
// src: XBOX_PDB 0x00dc9640
hkNameRefDC96 hkNameDC96::hkDataObjectDict_accessByName(const char* name)
{
    hkWorldDC96* world = m_pOwnerObject->m_holder->m_pOwningWorld;
    hkNameRefDC96 r;
    r.m_name = internDC96(world, name);
    r.m_pOwnerObject = this;
    return r;
}
}  // namespace fnv_00dc9640

namespace fnv_00dc9d10 {
extern "C" void* __cdecl fnv_zlib_memset(void* pvDest, int iValue, unsigned int iCount);
extern "C" void _ReadWriteBarrier(void);

class hkMemoryAllocatorDC9D;

struct hkMemoryRouterDC9D
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC9D* m_pStreamAllocator;
    hkMemoryAllocatorDC9D& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC9D& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocatorDC9D& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

__forceinline void SetByteBufferSize(hkArray<char>& array, int n, const char& fill)
{
    array.GrowArrayCapacity(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()), n);
    int iNumToFill = n - array.m_iElementCount;
    char* pDst = array.m_data + array.m_iElementCount;
    _ReadWriteBarrier();
    if (iNumToFill > 0)
        fnv_zlib_memset(pDst, fill, iNumToFill);
    array.m_iElementCount = n;
}

class hkStreamBufferDC9D
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<char> m_buffer;

    void BasicArrayImplementation_unsigned_char_1_setSize(int iSize);
};

// Sets the buffer size to iSize, zero-filling any newly added bytes.
// @fnv 0x00dc9d10
// src: XBOX_PDB 0x00dc9d10
void hkStreamBufferDC9D::BasicArrayImplementation_unsigned_char_1_setSize(int iSize)
{
    SetByteBufferSize(m_buffer, iSize, 0);
}
}  // namespace fnv_00dc9d10

namespace fnv_00dcb890 {
extern int DAT_010d73fc;
extern int DAT_010d62f4;
void* hkMemoryRouter_getInstance();
struct FUN_00dcb890_Owner
{
    int unk00;
    int unk04;
    int unk08;
};
struct FUN_00dcb890_Node
{
    void* key;
    int next;
};
struct FUN_00dcb890_Table
{
    FUN_00dcb890_Node* m_kNodeCollection;
    int LookupWithDefault(int key);
    void hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(int key, int idx);
};
struct FUN_00dcb890_Ref
{
    virtual void Destroy(int flags);
    virtual FUN_00dcb890_Owner* Lookup();
    int unk04;
    int refCount;
};
struct FUN_00dcb890_Pair
{
    int key;
    FUN_00dcb890_Ref* ref;
};
struct FUN_00dcb890_Alloc
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void Free(void* p, int size);
};
struct FUN_00dcb890_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00dcb890_Alloc* m10;
};
struct FUN_00dcb890_cls
{
    void* unk00;
    int unk04;
    int unk08;
    FUN_00dcb890_Pair* unk0c;
    int unk10;
    int unk14;
    FUN_00dcb890_Ref* unk18;
    void ProcessEntries_00dcb890();
};
// Releases the pair array, decrements refcounts on contained refs and unk18, and unlinks this object from the owning table.
// @fnv 0x00dcb890
// src: GUESS 0x00dcb890 (confidence: low)
void FUN_00dcb890_cls::ProcessEntries_00dcb890()
{
    unk00 = &DAT_010d73fc;
    for (int i = 0; i < unk10; ++i)
    {
        FUN_00dcb890_Ref* r = unk0c[i].ref;
        if (--r->refCount == 0)
            r->Destroy(1);
    }
    int base = unk18->Lookup()->unk08;
    int key = ((int(__thiscall*)(FUN_00dcb890_cls*))((void**)unk00)[6])(this);
    FUN_00dcb890_Table* tbl = reinterpret_cast<FUN_00dcb890_Table*>(base + 0x6c);
    int idx = tbl->LookupWithDefault(key);
    if (idx != -1)
    {
        FUN_00dcb890_Node* nodes = tbl->m_kNodeCollection;
        do
        {
            if ((void*)this == nodes[idx].key)
            {
                tbl->hkSerializeMultiMap_hkDataClassDict_hkDataArrayImpl_removeByIndex(key, idx);
                break;
            }
            idx = nodes[idx].next;
        } while (idx != -1);
    }
    FUN_00dcb890_Ref* ref = unk18;
    if (ref)
    {
        if (--ref->refCount == 0)
            ref->Destroy(1);
    }
    unk18 = 0;
    FUN_00dcb890_Holder* pHolder = (FUN_00dcb890_Holder*)hkMemoryRouter_getInstance();
    FUN_00dcb890_Alloc* a = pHolder->m10;
    int cap = unk14;
    unk10 = 0;
    if (!(cap & 0x80000000))
        a->Free(unk0c, (cap & 0x3fffffff) * 8);
    unk0c = 0;
    int& flag = unk14;
    flag = (int)0x80000000;
    unk00 = &DAT_010d62f4;
}
}  // namespace fnv_00dcb890

struct MemberReset
{
    void Reset();
};
void ResizeAudioStream(void* allocator, void* array, int elementSize);
struct TypeInfo
{
    virtual void slot00();
    virtual void slot04();
    virtual const char* name();
};
struct ReferencedObject
{
    virtual void destroy(int flags);
    virtual void slot04();
    virtual TypeInfo* type();
    short allocationSize;
    short externalReferences;
    int references;
    void selfDestruct();
    void FUN_00c905b0();
    void release()
    {
        if (--references == 0)
            destroy(1);
    }
};
struct PointerArray
{
    ReferencedObject** data;
    int size;
    int capacity;
    PointerArray() : data(0), size(0), capacity(0x80000000)
    {}
    void push(ReferencedObject* value)
    {
        hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(router->m_pkHeap, this, 4);
        data[size++] = value;
    }
    void clearStorage(bool reset = true)
    {
        hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
        hkAllocatorDC76* heap = router->m_pkHeap;
        size = 0;
        if (!(capacity & 0x80000000))
            heap->ReturnMemory(data, (capacity & 0x3fffffff) * 4);
        if (reset)
        {
            data = 0;
            capacity = 0x80000000;
        }
    }
};
struct LocalPointerArray : PointerArray
{
    char* original;
    LocalPointerArray(int count)
    {
        hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
        char* storage = (char*)router->m_p00;
        router->m_p00 = storage + count * 4;
        data = (ReferencedObject**)storage;
        capacity = count | 0x80000000;
        original = storage;
    }
    void finish(bool reset = true)
    {
        char* storage = original;
        if (storage == (char*)data)
            size = 0;
        hkMemoryRouter_getInstance()->m_p00 = storage;
        clearStorage(reset);
    }
};
struct ChainEntry
{
    ReferencedObject* object;
    int next;
};
struct ChainArray
{
    ChainEntry* data;
    int size;
    int capacity;
    int LookupWithDefault(ReferencedObject* p);
    void RemoveKey(ReferencedObject* p);
    void clearStorage(bool reset = true)
    {
        hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
        hkAllocatorDC76* heap = router->m_pkHeap;
        size = 0;
        if (!(capacity & 0x80000000))
            heap->ReturnMemory(data, (capacity & 0x3fffffff) * 8);
        if (reset)
        {
            data = 0;
            capacity = 0x80000000;
        }
    }
};
struct BucketStorage
{
    int* data;
    int size;
    int capacity;
    int count;
    void ProcessArgument(hkAllocatorDC76* allocator);
    void Object_DoNothing();
};
struct ObjectMap
{
    int* entries;
    int size;
    int capacity;
    int count;
    int hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
    ReferencedObject* hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(int iterator);
    int FindNextUsedSlot(int iterator);
    char* SetBoolFromThreshold(char* result, int iterator);
    void FreeBuffer();
};
struct StringStream
{
    void* buffer;
    int position;
    int capacity;
    void FUN_00cb1600(void* buffer, int length);
    StringStream& ProcessAndReturnValue_00cc01c0(const char* text);
    StringStream& WriteInt(int value);
    void FUN_00cc00e0();
};
struct ErrorReporter
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void report(int severity, int id, const char* text, const char* file, int line);
};
extern ErrorReporter* DAT_01268360;
void hkString_strFree(ReferencedObject* object);
struct WorldData
{
    ObjectMap objects;
    PointerArray members;
    BucketStorage memberBuckets;
    int objectCount;
    ChainArray chains;
    BucketStorage chainBuckets;
    ObjectMap strings;
    ObjectMap references;
    ChainArray values;
    BucketStorage valueBuckets;
    void ClearWorldContainers();
};
// Processes pending objects and clears the value, reference, string, chain, member, and object containers.
// @fnv 0x00dc7750
// src: GUESS 0x00dc7750 (confidence: medium)
void WorldData::ClearWorldContainers()
{
    {
        LocalPointerArray pendingObjects(512);
        LocalPointerArray retainedObjects(64);
        ((MemberReset*)&members)->Reset();
        objectCount = 0;
        int iterator = objects.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
        char valid;
        ReferencedObject* p;
        objects.SetBoolFromThreshold(&valid, iterator);
        while (valid)
        {
            p = objects.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(iterator);
            retainedObjects.push(p);
            int index = chains.LookupWithDefault(p);
            if (index != -1)
            {
                do
                {
                    pendingObjects.push(chains.data[index].object);
                    index = chains.data[index].next;
                } while (index != -1);
                chains.RemoveKey(p);
            }
            iterator = objects.FindNextUsedSlot(iterator);
            objects.SetBoolFromThreshold(&valid, iterator);
        }
        for (int i = 0; i < pendingObjects.size; ++i)
        {
            if (pendingObjects.data[i]->externalReferences > 0)
            {
                int errorText[128];
                StringStream stream;
                stream.FUN_00cb1600(errorText, 512);
                stream.ProcessAndReturnValue_00cc01c0("The object of class ")
                    .ProcessAndReturnValue_00cc01c0(pendingObjects.data[i]->type()->name())
                    .ProcessAndReturnValue_00cc01c0(
                        " is about to be removed and all references to it will be invalid.\nHowever, the object is referenced (")
                    .WriteInt(pendingObjects.data[i]->externalReferences)
                    .ProcessAndReturnValue_00cc01c0(") from outside the world and it will lead to unexpected behavior or crash.");
                DAT_01268360->report(1, 0x760d3795, (const char*)errorText, ".\\Data\\Dict\\hkDataObjectDict.cpp",
                                     1780);
                stream.FUN_00cc00e0();
            }
            pendingObjects.data[i]->selfDestruct();
        }
        for (int i = 0; i < pendingObjects.size; ++i)
            pendingObjects.data[i]->release();
        for (int i = 0; i < retainedObjects.size; ++i)
            retainedObjects.data[i]->release();
        iterator = references.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
        references.SetBoolFromThreshold(&valid, iterator);
        while (valid)
        {
            references.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(iterator)->FUN_00c905b0();
            iterator = references.FindNextUsedSlot(iterator);
            references.SetBoolFromThreshold(&valid, iterator);
        }
        iterator = strings.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getIterator();
        strings.SetBoolFromThreshold(&valid, iterator);
        while (valid)
        {
            hkString_strFree(strings.hkCachedHashMap_hkStringMapOperations_hkContainerHeapAllocator_getValue(iterator));
            iterator = strings.FindNextUsedSlot(iterator);
            strings.SetBoolFromThreshold(&valid, iterator);
        }
        retainedObjects.finish();
        if (pendingObjects.original == (char*)pendingObjects.data)
            pendingObjects.size = 0;
        char* storage = pendingObjects.original;
        hkMemoryRouter_getInstance()->m_p00 = storage;
        pendingObjects.clearStorage(false);
    }
    valueBuckets.ProcessArgument(hkMemoryRouter_getInstance()->m_pkHeap);
    valueBuckets.Object_DoNothing();
    values.clearStorage();
    references.FreeBuffer();
    strings.FreeBuffer();
    chainBuckets.ProcessArgument(hkMemoryRouter_getInstance()->m_pkHeap);
    chainBuckets.Object_DoNothing();
    chains.clearStorage();
    memberBuckets.ProcessArgument(hkMemoryRouter_getInstance()->m_pkHeap);
    memberBuckets.Object_DoNothing();
    // Member storage contains pairs, as do the other persistent arrays.
    ((ChainArray*)&members)->clearStorage();
    return objects.FreeBuffer();
}

struct VarObject : public Shape7DE0
{
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void SetValue(int);
};
struct VarFactory
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int CreateValue(int);
};
struct VarDef
{
    int m_00;
    int m_04;
    int m_iInfo;
};
struct VarRecord
{
    int m_00;
    VarDef* m_pkDef;
    int m_08;
    int m_0c;
    int m_iFlags;
    int m_iInitial;
};
struct VarEntry
{
    int m_iKey;
    int m_04;
    VarObject* m_pPointer;
    int m_0c;
    VarEntry() : m_iKey(0)
    {}
};
template <typename T> __forceinline void hkConstructDefault(T* p, int n)
{
    for (int i = 0; i < n; i++)
        ::new (p + i) T();
}
template <typename T> struct VarArrayLocalForm
{ // local form of hkArray: 0x00dcba40 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& AllocatePair()
    {
        hkAllocatorDC76& a = hkMemoryRouter_getInstance()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&a, this, sizeof(T));
        hkConstructDefault(m_data + m_iElementCount, 1);
        return m_data[m_iElementCount++];
    }
};
struct VarResult
{
    VarRecord* m_pkRecord;
    int m_iIndex;
    VarResult()
    {}
    VarResult(VarRecord* r, int i) : m_pkRecord(r), m_iIndex(i)
    {}
};
struct VarSet
{
    int m_00;
    int m_04;
    int m_08;
    hkDataClassDict* m_pkLookup;
    VarArrayLocalForm<VarEntry> m_kEntries;
    VarResult hkDataObjectDict__readAccess(int, int);
};
// Looks up a VarRecord by key, adds a new VarEntry to m_kEntries if missing, and returns a VarResult with the record and entry index.
// @fnv 0x00dcba40
// src: XBOX_PDB 0x00dcba40
VarResult VarSet::hkDataObjectDict__readAccess(int iKey, int iType)
{
    VarRecord* pkRecord = (VarRecord*)m_pkLookup->FindEntry(reinterpret_cast<const char*>(iKey));
    if (pkRecord)
    {
        int iIndex = -1;
        for (int i = 0; i < m_kEntries.m_iElementCount; i++)
            if (m_kEntries.m_data[i].m_iKey == iKey)
                iIndex = i;
        if (iIndex == -1)
        {
            iIndex = m_kEntries.m_iElementCount;
            VarEntry& e = m_kEntries.AllocatePair();
            e.m_iKey = *(volatile int*)&iKey;
            unsigned int uiFlags = pkRecord->m_iFlags;
            if (uiFlags & 0x10)
            {
                VarFactory* pkFactory = (VarFactory*)m_pkLookup->m_pOwningWorld;
                int iInfo = pkRecord->m_pkDef->m_iInfo;
                int v = pkFactory->CreateValue(iInfo);
                e.m_pPointer = static_cast<VarObject*>(hkDataArrayDict_create(uiFlags & ~0x10, v, 0));
                e.m_pPointer->m_iRefCount++;
            }
            else if (uiFlags & 0x20)
            {
                VarFactory* pkFactory = (VarFactory*)m_pkLookup->m_pOwningWorld;
                int iInfo = pkRecord->m_pkDef->m_iInfo;
                int v = pkFactory->CreateValue(iInfo);
                e.m_pPointer = static_cast<VarObject*>(hkDataArrayDict_create(uiFlags & ~0x20, v, 0));
                e.m_pPointer->SetValue(pkRecord->m_iInitial);
                e.m_pPointer->m_iRefCount++;
            }
            else if (uiFlags == 8)
            {
                e.m_pPointer = 0;
            }
            else
            {
                e.m_pPointer = 0;
                e.m_0c = 0;
            }
        }
        return VarResult(pkRecord, iIndex);
    }
    return VarResult(0, -1);
}

struct S00dcbd40_Destination;

struct S00dcbd40_Id
{
    S00dcbd40_Destination* dictionary;
    int id;
};

struct S00dcbd40_Info
{

    int unk00;

    int unk04;

    int unk08;

    int unk0C;

    int flags;
};

struct S00dcbd40_Shared
{

    int unk00;

    int unk04;

    int references;
};

struct S00dcbd40_Pair
{

    S00dcbd40_Shared* object;

    int value;
};

struct S00dcbd40_Entry
{

    int key;

    int unk04;

    S00dcbd40_Pair data;

    S00dcbd40_Entry() : key(0)
    {}
};

struct S00dcbd40_Result
{

    S00dcbd40_Info* info;

    int index;

    S00dcbd40_Result()
    {}

    S00dcbd40_Result(S00dcbd40_Info* p, int i) : info(p), index(i)
    {}
};

struct S00dcbd40_Handle
{

    int v;

    S00dcbd40_Handle(int x) : v(x)
    {}
};

struct S00dcbd40_Array
{

    S00dcbd40_Entry* data;

    int size;

    int capacityAndFlags;

    S00dcbd40_Entry& operator[](int i)
    {
        return data[i];
    }
};


void __cdecl ResizeAudioStream(hkAllocatorDC76*, S00dcbd40_Array*, int) throw();

void __cdecl ReleaseDataValues(int, S00dcbd40_Pair*, int) throw();

struct S00dcbd40_Destination
{

    int unk00;

    int unk04;

    int unk08;

    hkDataClassDict* pClassInfo;

    S00dcbd40_Array entries;

    S00dcbd40_Result __thiscall hkDataObjectDict__writeAccess(S00dcbd40_Handle ref, int flags) throw();

    S00dcbd40_Result __thiscall hkDataObjectDict__readAccess(S00dcbd40_Handle key, int flags) throw();

    void __thiscall hkDataObjectDict_assign_00dcbd40(int target, S00dcbd40_Id* id) throw();
};

// Copies source entry data into a destination entry and increments its object reference count when flags & 0x18 is nonzero.
// @fnv 0x00dcbd40
// src: XBOX_PDB 0x00dcbd40
void S00dcbd40_Destination::hkDataObjectDict_assign_00dcbd40(int target, S00dcbd40_Id* apSourceId)

{

    S00dcbd40_Destination* src = apSourceId->dictionary;

    int iSourceIndex;

    S00dcbd40_Info* info;

    {

        S00dcbd40_Result r = src->hkDataObjectDict__readAccess(apSourceId->id, 0);

        iSourceIndex = r.index;

        info = r.info;
    }

    S00dcbd40_Pair p = src->entries[iSourceIndex].data;

    if ((info->flags & 0x18) != 0 && p.object != 0)
    {

        p.object->references++;
    }

    {

        S00dcbd40_Result result = hkDataObjectDict__writeAccess(target, info->flags);

        int dst = result.index;

        S00dcbd40_Entry* pSourceEntries = src->entries.data;

        entries[dst].data = pSourceEntries[iSourceIndex].data;
    }
}

// src: XBOX_PDB 0x00dc9710
S00dcbd40_Result S00dcbd40_Destination::hkDataObjectDict__writeAccess(S00dcbd40_Handle key, int flags)
{
    S00dcbd40_Info* info = reinterpret_cast<S00dcbd40_Info*>(pClassInfo->FindEntry(reinterpret_cast<const char*>(key.v)));
    if (!info)
        return S00dcbd40_Result(0, -1);
    int index = 0;
    for (; index < entries.size; ++index)
    {
        if (entries.data[index].key == key.v)
        {
            ReleaseDataValues(info->flags, &entries.data[index].data, 1);
            return S00dcbd40_Result(info, index);
        }
    }
    int oldSize = entries.size;
    hkMemoryRouterDC76* router = hkMemoryRouter_getInstance();
    if (entries.size == (entries.capacityAndFlags & 0x3fffffff))
        ResizeAudioStream(router->m_pkHeap, &entries, sizeof(S00dcbd40_Entry));
    S00dcbd40_Entry* entry = new (entries.data + entries.size) S00dcbd40_Entry;
    ++entries.size;
    entry->key = key.v;
    entry->data.object = 0;
    entry->data.value = 0;
    return S00dcbd40_Result(info, oldSize);
}


struct MemberInfoDC97
{
    int name;
    int className;
    int classInfo;
    int flags;
    int type;
    int tupleSize;
};
void __cdecl ResizeAudioStream(void* allocator, void* array, int stride);
void __cdecl ReleaseDataValues(int type, void* target, int count);
struct EntryDC97
{
    int key, flags, next, previous;
};
struct EntryArrayDC97
{
    EntryDC97* data;
    int size;
    unsigned int capacityFlags;
};
struct FindResultDC97
{
    int* node;
    int index;
};
struct DictWriteAccessDC97
{
    void* owner;
    void* context;
    void* extra;
    hkDataClassDict* finder;
    EntryArrayDC97 entries;
    FindResultDC97* __thiscall hkDataObjectDict__writeAccess(FindResultDC97* result, int key, int option);
};
// If the finder returns a node, searches entries, copies its type into a match or appends one; otherwise returns index -1.
// @fnv 0x00dc9710
// src: XBOX_PDB 0x00dc9710
FindResultDC97* DictWriteAccessDC97::hkDataObjectDict__writeAccess(FindResultDC97* result, int key, int option)
{
    int* node = reinterpret_cast<int*>(finder->FindEntry(reinterpret_cast<const char*>(key)));
    if (node)
    {
        int count = entries.size;
        for (int i = 0; i < count; ++i)
        {
            if (entries.data[i].key == key)
            {
                ReleaseDataValues(reinterpret_cast<MemberInfoDC97*>(node)->type, &entries.data[i].next, 1);
                result->index = i;
                result->node = node;
                return result;
            }
        }
        EntryArrayDC97* array = &entries;
        hkMemoryRouterDC76* allocationContext = hkMemoryRouter_getInstance();
        if (array->size == (int)(array->capacityFlags & 0x3fffffff))
        {
            ResizeAudioStream(allocationContext->m_pkHeap, array, sizeof(EntryDC97));
        }
        EntryDC97* slot = array->data + array->size;
        if (slot)
            slot->key = 0;
        slot = array->data + array->size++;
        slot->key = key;
        slot->next = 0;
        slot->previous = 0;
        result->index = count;
        result->node = node;
        return result;
    }
    result->node = 0;
    result->index = -1;
    return result;
}
