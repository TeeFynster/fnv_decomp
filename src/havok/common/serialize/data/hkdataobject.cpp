#include "../../../../../include/hkArray.h"

// src/havok/common/serialize/data/hkdataobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/hkdataobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dba680_cls
{
    void* vtbl;
    void* p1;
    void* p2;
    void __thiscall hkDataClass_getName();
};
// @fnv 0x00dba680
// src: XBOX_PDB 0x00dba680
void __thiscall FUN_00dba680_cls::hkDataClass_getName()
{
    void* self = *(void**)this;
    void** vt = *(void***)self;
    void(__thiscall * f)(FUN_00dba680_cls*) = *(void(__thiscall*)(FUN_00dba680_cls*))vt[2];
    f((FUN_00dba680_cls*)self);
}

struct FUN_00dbaab0_cls
{
    void* vtbl;
    void* p1;
    void __thiscall DispatchFloatToVtbl(float f);
};

// @fnv 0x00dbaab0
void __thiscall FUN_00dbaab0_cls::DispatchFloatToVtbl(float f)
{
    void* obj = this;
    void* vt = *(void**)(obj);
    void* p = *(void**)(vt);
    void* a = *(void**)((char*)obj + 4);
    void* fn = *(void**)((char*)p + 0x4c);
    ((void(__thiscall*)(void*, void*, float))fn)(vt, a, f);
}

struct Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct This
{
    Inner* object;
    void ForwardCall_00dba690();
};
// @fnv 0x00dba690
// src: GUESS 0x00dba690 (confidence: low)
void This::ForwardCall_00dba690()
{
    object->v3();
}

namespace fnv_00dba6c0 {
struct Inner
{
    virtual void v0();
    virtual void v1();
};

struct FUN_00dba6c0_cls
{
    Inner* m_p;
    void hkDataClass_getWorld();
};

// @fnv 0x00dba6c0
// src: XBOX_PDB 0x00dba6c0
void FUN_00dba6c0_cls::hkDataClass_getWorld()
{
    m_p->v1();
}
}  // namespace fnv_00dba6c0

struct dba6d0_Ret
{
    int a, b, c;
};
struct dba6d0_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual dba6d0_Ret v5(int h);
};
struct FUN_00dba6d0_cls
{
    dba6d0_Target* m_p;
    dba6d0_Ret __thiscall CallVirtualV5(const int& h);
};
// @fnv 0x00dba6d0
dba6d0_Ret FUN_00dba6d0_cls::CallVirtualV5(const int& h)
{
    return m_p->v5(h);
}

struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void invoke();
};
struct Wrapper
{
    Target* target;
    void ForwardCall_00dba6f0();
};
// @fnv 0x00dba6f0
// src: GUESS 0x00dba6f0 (confidence: low)
void Wrapper::ForwardCall_00dba6f0()
{
    target->invoke();
}

// Exe 0x00dba730: unit-local Interface view; declarations and layout are preserved.
struct HkdataobjectInterfaceView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
struct FUN_00dba730_cls
{
    HkdataobjectInterfaceView* ptr;
    void ForwardCall_00dba730();
};
// @fnv 0x00dba730
// src: GUESS 0x00dba730 (confidence: low)
void FUN_00dba730_cls::ForwardCall_00dba730()
{
    ptr->f9();
}

struct FUN_00dba740_Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C(int a);
};

struct FUN_00dba740_Owner
{
    FUN_00dba740_Target* unk00;

    void InvokeVirtualMethod_00dba740(int a);
};

// @fnv 0x00dba740
// src: GUESS 0x00dba740 (confidence: low)
void FUN_00dba740_Owner::InvokeVirtualMethod_00dba740(int a)
{
    unk00->unk2C(a);
}

struct FUN_00dba750
{
    void* m_pObject;

    FUN_00dba750();
};

// @fnv 0x00dba750
FUN_00dba750::FUN_00dba750()
{
    m_pObject = 0;
}

struct S_00dba890_Vec
{
    float x, y, z;
};
struct S_00dba890_Impl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00dba890_Vec Get(int i);
};
struct S_00dba890_Wrap
{
    S_00dba890_Impl* m_pClassImpl;
    S_00dba890_Vec Get_Thunk(int i);
};
// @fnv 0x00dba890
// src: GUESS 0x00dba890 (confidence: medium)
S_00dba890_Vec S_00dba890_Wrap::Get_Thunk(int i)
{
    return m_pClassImpl->Get(i);
}

struct DBA8C0Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18(int a);
};

struct DBA8C0Owner
{
    DBA8C0Target* unk00;

    void InvokeVirtualMethod_00dba8c0(int a);
};

// @fnv 0x00dba8c0
// src: GUESS 0x00dba8c0 (confidence: low)
void DBA8C0Owner::InvokeVirtualMethod_00dba8c0(int a)
{
    unk00->unk18(a);
}

namespace fnv_00dba920 {
struct FirstInterface
{
    virtual void slot0();
    virtual void slot1();
    virtual int acquire();
};
struct SecondInterface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void write(int value, int* output);
    virtual int query(int value);
};
struct ResultData
{
    int unk00;
    int unk04;
    int value;
    int unk0c;
    int unk10;
};
struct Target
{
    void* object;
    int value;
    int QueryAndWriteResult();
};
// If object is set, acquires a second interface, queries it with value, writes the result into a ResultData and returns its value field; otherwise returns 0.
// @fnv 0x00dba920
int Target::QueryAndWriteResult()
{
    if (object != 0)
    {
        FirstInterface* first = (FirstInterface*)object;
        SecondInterface* second = (SecondInterface*)first->acquire();
        ResultData result;
        result.unk00 = 0;
        result.unk04 = 0;
        result.value = 0;
        result.unk0c = 0;
        result.unk10 = 0;
        int queried = second->query(value);
        second->write(queried, &result.unk00);
        return result.value;
    }
    return 0;
}
}  // namespace fnv_00dba920

struct FUN_00dba980_cls
{
    void* m_p00;
    bool hkDataObject_isNull() const;
};

// @fnv 0x00dba980
// src: XBOX_PDB 0x00dba980
bool FUN_00dba980_cls::hkDataObject_isNull() const
{
    return m_p00 == 0;
}

namespace fnv_00dba9a0 {
// Exe 0x00dba9a0: unit-local Interface view; declarations and layout are preserved.
struct HkdataobjectInterfaceView
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(void* first, unsigned int second);
};
struct FUN_00dba9a0_cls
{
    HkdataobjectInterfaceView* ptr;
    void* p1;
    void DispatchToInterface(unsigned int param);
};
// @fnv 0x00dba9a0
void FUN_00dba9a0_cls::DispatchToInterface(unsigned int param)
{
    ptr->f14(p1, param);
}
}  // namespace fnv_00dba9a0

struct FUN_00dba9c0_target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void Dispatch2c(void* arg);
};

struct FUN_00dba9c0_cls
{
    FUN_00dba9c0_target* target;
    void* payload;
    void hkDataObject_Value_asString();
};

// @fnv 0x00dba9c0
// src: XBOX_PDB 0x00dba9c0
void FUN_00dba9c0_cls::hkDataObject_Value_asString()
{
    target->Dispatch2c(payload);
}

namespace fnv_00dbaa00 {
struct Delegate
{
    virtual void slot00(void*) = 0;
    virtual void slot01(void*) = 0;
    virtual void slot02(void*) = 0;
    virtual void slot03(void*) = 0;
    virtual void slot04(void*) = 0;
    virtual void slot05(void*) = 0;
    virtual void slot06(void*) = 0;
    virtual void slot07(void*) = 0;
    virtual void slot08(void*) = 0;
    virtual void slot09(void*) = 0;
    virtual void slot10(void*) = 0;
    virtual void slot11(void*) = 0;
    virtual void slot12(void*) = 0;
    virtual void slot13(void*) = 0;
    virtual void slot14(void*) = 0;
    virtual void Target(void*) = 0;
};
struct Wrapper
{
    Delegate* delegate;
    void* value;
    void InvokeVirtualMethod_00dbaa00();
};
// @fnv 0x00dbaa00
// src: GUESS 0x00dbaa00 (confidence: low)
void Wrapper::InvokeVirtualMethod_00dbaa00()
{
    delegate->Target(value);
}
}  // namespace fnv_00dbaa00

struct Inner2
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int a, __int64 b);
};

struct FUN_00dbaaf0_cls
{
    Inner2* m_p;
    int m_iWordAt04;
    void DispatchToInner(unsigned char b);
};

// @fnv 0x00dbaaf0
void FUN_00dbaaf0_cls::DispatchToInner(unsigned char b)
{
    m_p->v16(m_iWordAt04, b);
}

struct AudioInterface
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Apply(void*, unsigned int, unsigned int);
};
struct AudioHandle
{
    AudioInterface* system;
    void* object;
    void Apply_Thunk(unsigned int, unsigned int);
};
// @fnv 0x00dbab10
// src: GUESS 0x00dbab10 (confidence: medium)
void AudioHandle::Apply_Thunk(unsigned int a, unsigned int b)
{
    system->Apply(object, a, b);
}

struct S_00dbab30_Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual int unk50(int a, int b);
};
struct S_00dbab30_Ref
{
    S_00dbab30_Target* m_target;
    int m_04;
    int ForwardCall_00dbab30(int b);
};
// @fnv 0x00dbab30
// src: GUESS 0x00dbab30 (confidence: low)
int S_00dbab30_Ref::ForwardCall_00dbab30(int b)
{
    return m_target->unk50(m_04, b);
}

struct FUN_00dbab70_obj
{
    unsigned short m_u04;
    short m_sCount06;
    int m_iRefCount;
    virtual ~FUN_00dbab70_obj();
};

struct FUN_00dbab70_cls
{
    FUN_00dbab70_obj* m_pEntryObject;
    void ReleaseStorage_00dbab70();
};

// @fnv 0x00dbab70
// src: GUESS 0x00dbab70 (confidence: low)
void FUN_00dbab70_cls::ReleaseStorage_00dbab70()
{
    FUN_00dbab70_obj* pObj = m_pEntryObject;
    if (pObj)
    {
        pObj->m_sCount06--;
        if (--pObj->m_iRefCount == 0)
            delete pObj;
    }
}

struct ResultPair
{
    void* m_pFirst;
    void* m_pSecond;

    ResultPair(void* apFirst, void* apSecond) : m_pFirst(apFirst), m_pSecond(apSecond)
    {}
};

struct FUN_00dbabb0_cls
{
    void* m_pIntegerData;
    ResultPair CreateResultPair(void* apExtra);
};

// @fnv 0x00dbabb0
// src: GUESS 0x00dbabb0 (confidence: medium)
ResultPair FUN_00dbabb0_cls::CreateResultPair(void* apExtra)
{
    return ResultPair(m_pIntegerData, apExtra);
}

struct S_00dbabd0_Inner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct S_00dbabd0
{
    S_00dbabd0_Inner* m_inner;
    void ForwardCall_00dbabd0();
};

// @fnv 0x00dbabd0
// src: GUESS 0x00dbabd0 (confidence: low)
void S_00dbabd0::ForwardCall_00dbabd0()
{
    m_inner->v2();
}

namespace fnv_00dbac00 {
struct Target
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void Invoke();
};
struct Wrapper
{
    Target* target;
    void InvokeVirtualMethod_00dbac00();
};
// @fnv 0x00dbac00
// src: GUESS 0x00dbac00 (confidence: low)
void Wrapper::InvokeVirtualMethod_00dbac00()
{
    target->Invoke();
}
}  // namespace fnv_00dbac00

struct Inner_dbac40
{
    virtual void v0();
    virtual void v1();
};
struct Outer_dbac40
{
    Inner_dbac40* p;
    void InvokeVirtualMethod_00dbac40();
};
// @fnv 0x00dbac40
// src: GUESS 0x00dbac40 (confidence: low)
void Outer_dbac40::InvokeVirtualMethod_00dbac40()
{
    p->v1();
}

struct dbac70_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(int a);
};
struct FUN_00dbac70_cls
{
    dbac70_Target* m_p;
    int m_f;
    void __thiscall ForwardCall_00dbac70();
};
// @fnv 0x00dbac70
// src: GUESS 0x00dbac70 (confidence: low)
void FUN_00dbac70_cls::ForwardCall_00dbac70()
{
    m_p->v10(m_f);
}

namespace fnv_00dbac80 {
struct Target
{
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14();
    virtual void method18();
    virtual void method1c();
    virtual void method20();
    virtual void method24();
    virtual void method28();
    virtual void method2c();
    virtual void apply(void* value);
};
struct Wrapper
{
    Target* target;
    void* value;
    void ApplyValue();
};
// @fnv 0x00dbac80
void Wrapper::ApplyValue()
{
    target->apply(value);
}
}  // namespace fnv_00dbac80

struct S_00dbac90_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40(void* arg);
};
struct S_00dbac90
{
    S_00dbac90_Obj* m_obj;
    void* m_arg;
    void CallVirtualWithArg();
};
// @fnv 0x00dbac90
void S_00dbac90::CallVirtualWithArg()
{
    m_obj->vf40(m_arg);
}

struct ValueProvider
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void* CreateValue(void* source);
};
struct FUN_00dba760_cls
{
    void* value;
    void hkDataObject_hkDataObject(void* newValue);
};
struct FUN_00dbaca0_cls
{
    ValueProvider* provider;
    void* source;
    FUN_00dba760_cls* CreateValueInto(FUN_00dba760_cls* output);
};
// Calls provider->CreateValue(source) and stores the result into output via FUN_00dba760, then returns output.
// @fnv 0x00dbaca0
FUN_00dba760_cls* FUN_00dbaca0_cls::CreateValueInto(FUN_00dba760_cls* output)
{
    output->hkDataObject_hkDataObject(provider->CreateValue(source));
    return output;
}

struct dbad00_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a, int b);
};
struct FUN_00dbad00_cls
{
    dbad00_Target* m_p;
    int m_f;
    void __thiscall InvokeVirtualMethod_00dbad00(int* a);
};
// @fnv 0x00dbad00
// src: GUESS 0x00dbad00 (confidence: low)
void FUN_00dbad00_cls::InvokeVirtualMethod_00dbad00(int* piValue)
{
    m_p->v21(m_f, *piValue);
}

namespace fnv_00dbad20 {
struct AudioInterface
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Reserved4();
    virtual void Reserved5();
    virtual void Reserved6();
    virtual void Reserved7();
    virtual void Reserved8();
    virtual void Reserved9();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Apply(void*, float);
};
struct AudioHandle
{
    AudioInterface* system;
    void* object;
    void Apply_Thunk(float);
};
// @fnv 0x00dbad20
// src: GUESS 0x00dbad20 (confidence: medium)
void AudioHandle::Apply_Thunk(float value)
{
    system->Apply(object, value);
}
}  // namespace fnv_00dbad20

namespace fnv_00dbad40 {
struct Delegate
{
    virtual void slot00(void*, void*) = 0;
    virtual void slot01(void*, void*) = 0;
    virtual void slot02(void*, void*) = 0;
    virtual void slot03(void*, void*) = 0;
    virtual void slot04(void*, void*) = 0;
    virtual void slot05(void*, void*) = 0;
    virtual void slot06(void*, void*) = 0;
    virtual void slot07(void*, void*) = 0;
    virtual void slot08(void*, void*) = 0;
    virtual void slot09(void*, void*) = 0;
    virtual void slot10(void*, void*) = 0;
    virtual void slot11(void*, void*) = 0;
    virtual void slot12(void*, void*) = 0;
    virtual void slot13(void*, void*) = 0;
    virtual void slot14(void*, void*) = 0;
    virtual void Target(void*, void*) = 0;
};
struct Wrapper
{
    Delegate* delegate;
    void* value;
    void InvokeVirtualMethod_00dbad40(void*);
};
// @fnv 0x00dbad40
// src: GUESS 0x00dbad40 (confidence: low)
void Wrapper::InvokeVirtualMethod_00dbad40(void* arg)
{
    delegate->Target(value, arg);
}
}  // namespace fnv_00dbad40

struct dbad60_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int a, int b);
};
struct FUN_00dbad60_cls
{
    dbad60_Target* m_p;
    int m_f;
    void __thiscall InvokeVirtualMethod_00dbad60(int a, int b);
};
// @fnv 0x00dbad60
// src: GUESS 0x00dbad60 (confidence: low)
void FUN_00dbad60_cls::InvokeVirtualMethod_00dbad60(int aiArg, int aiUnused)
{
    m_p->v9(m_f, aiArg);
}

namespace fnv_00dbada0 {
// Exe 0x00dbada0: unit-local Interface view; declarations and layout are preserved.
struct HkdataobjectInterfaceView
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void Invoke(void* value, int argument);
};
struct Wrapper
{
    HkdataobjectInterfaceView* interfaceObject;
    void* value;
    void InvokeOnInterface(int argument);
};
// @fnv 0x00dbada0
void Wrapper::InvokeOnInterface(int argument)
{
    interfaceObject->Invoke(value, argument);
}
}  // namespace fnv_00dbada0

struct DBADC0Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void call(void* data, void* arg);
};

struct DBADC0Binding
{
    DBADC0Target* m_target;
    void* m_data;

    void InvokeVirtualMethod_00dbadc0(void* arg);
};

// @fnv 0x00dbadc0
// src: GUESS 0x00dbadc0 (confidence: low)
void DBADC0Binding::InvokeVirtualMethod_00dbadc0(void* arg)
{
    m_target->call(m_data, arg);
}

namespace fnv_00dbae10 {
struct Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual int v80(int a);
};

struct Outer
{
    Inner* unk00;
    int hkDataArray_setAll_00dbae10(int a);
};

// @fnv 0x00dbae10
// src: HAVOK_LIB 0x00dbae10
int Outer::hkDataArray_setAll_00dbae10(int a)
{
    return unk00->v80(a);
}
}  // namespace fnv_00dbae10

struct Callback
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void* invoke(void* argument);
};
struct FUN_00dbab50_cls
{
    void __thiscall FUN_00dbab50(void* value);
};
struct FUN_00dbaea0_cls
{
    Callback* target;
    FUN_00dbab50_cls* __thiscall InvokeCallbackInto(FUN_00dbab50_cls* output, void* argument);
};
// Calls invoke on the stored callback with argument, passes the result to output's FUN_00dbab50, and returns output.
// @fnv 0x00dbaea0
FUN_00dbab50_cls* __thiscall FUN_00dbaea0_cls::InvokeCallbackInto(FUN_00dbab50_cls* output, void* argument)
{
    output->FUN_00dbab50(this->target->invoke(argument));
    return output;
}

struct FUN_00dbaf10_callback
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void dispatch(int index, void* record);
};
struct FUN_00dbaf10_cls
{
    FUN_00dbaf10_callback* vtbl;
    void* p1;
    void* p2;
    int __thiscall ForwardCall_00dba6f0();
    void __thiscall DispatchRecords(void* records);
};
// @fnv 0x00dbaf10
void __thiscall FUN_00dbaf10_cls::DispatchRecords(void* records)
{
    int count = ForwardCall_00dba6f0();
    int index = 0;
    if (count > 0)
    {
        int offset = 0;
        do
        {
            vtbl->dispatch(index, (char*)*(void**)records + offset);
            ++index;
            offset += 20;
        } while (index < count);
    }
}

extern char __stdcall Equals(void*);
// @fnv 0x00dbaf90
// src: GUESS 0x00dbaf90 (confidence: low)
bool __stdcall Hkdataobject_UpdateState_00dbaf90(void* param_1)
{
    char result = Equals(param_1);
    return result == 0;
}

struct DBAFB0Source
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual int getValue(int key);
};

struct DBAFB0Result
{
    int unk00;
    int unk04;

    DBAFB0Result(int value);
};

struct DBAFB0Handle
{
    DBAFB0Source* m_pObservedSource;
    int m_key;

    DBAFB0Result GetResult();
};

// Returns a DBAFB0Result constructed from the value the source object returns for m_key.
// @fnv 0x00dbafb0
DBAFB0Result DBAFB0Handle::GetResult()
{
    return DBAFB0Result(m_pObservedSource->getValue(m_key));
}

struct FUN_00dba650_cls
{
    unsigned int m_00;
    FUN_00dba650_cls* SetField00(unsigned int value);
};

// @fnv 0x00dba650
// src: GUESS 0x00dba650 (confidence: low)
FUN_00dba650_cls* FUN_00dba650_cls::SetField00(unsigned int value)
{
    this->m_00 = value;
    return this;
}

struct CpuObject
{
    int value;
    bool TestValue();
};
// @fnv 0x00dba670
// src: GUESS 0x00dba670 (confidence: low)
bool CpuObject::TestValue()
{
    return value == 0;
}

struct VirtualTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void* v10();
};

struct ValueHolder
{
    void* m_uiFilterValue;
    __declspec(noinline) void __thiscall SetValue(void* p);
};

void __thiscall ValueHolder::SetValue(void* p)
{
    m_uiFilterValue = (void*)((unsigned int)m_uiFilterValue << ((unsigned int)p & 31));
}

struct FUN_00dba6a0_cls
{
    VirtualTarget* m_00;
    void* __thiscall SetShiftedValue(void* a1);
};

// @fnv 0x00dba6a0
void* __thiscall FUN_00dba6a0_cls::SetShiftedValue(void* pTarget)
{
    void* r = m_00->v10();
    reinterpret_cast<ValueHolder*>(pTarget)->SetValue(r);
    return pTarget;
}

// FUN_00dba700 - forwarding stub (9 bytes).
//
// The object behind `this` owns a target object (its first member).  The stub
// tail-jumps to the target's virtual function that lives at vtable offset
// 0x20, forwarding its own argument unchanged (the callee pops it, so the
// stub needs no prologue and no epilogue of its own).
struct Sub_dba700
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(void* a);
};

struct Owner_dba700
{
    Sub_dba700* m_target;
    void __thiscall InvokeVirtualMethod_00dba700(void* a);
};

// @fnv 0x00dba700
// src: GUESS 0x00dba700 (confidence: low)
void __thiscall Owner_dba700::InvokeVirtualMethod_00dba700(void* a)
{
    m_target->v20(a);
}

struct FnvCpu_FUN_00dba710_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00dba710_CpuOwner
{
    FnvCpu_FUN_00dba710_CpuInterface* target;
    void ForwardCall_00dba710(int arg0);
};
// @fnv 0x00dba710
// src: GUESS 0x00dba710 (confidence: low)
void FnvCpu_FUN_00dba710_CpuOwner::ForwardCall_00dba710(int arg0)
{
    target->Invoke(arg0);
}

struct RefObj
{
    int unk00;
    short unk04;
    unsigned short m_w06;
    int m_i08;
};

struct FUN_00dba780_cls
{
    RefObj* m_pReference;

    FUN_00dba780_cls* AssignRef(FUN_00dba780_cls* apOther);
};

// @fnv 0x00dba780
FUN_00dba780_cls* FUN_00dba780_cls::AssignRef(FUN_00dba780_cls* apOther)
{
    RefObj* pRef = apOther->m_pReference;
    m_pReference = pRef;
    if (pRef != 0)
    {
        pRef->m_w06 += 1;
        pRef->m_i08 += 1;
    }
    return this;
}

struct RefCountedObj
{
    virtual ~RefCountedObj()
    {}
    unsigned short unk04;
    short m_refFlags;
    int m_iObjectReferenceCount;
};

struct FUN_00dba7a0_cls
{
    RefCountedObj* m_pEntryObject;
    void __thiscall AssignRefCounted(FUN_00dba7a0_cls* src);
};

// @fnv 0x00dba7a0
void __thiscall FUN_00dba7a0_cls::AssignRefCounted(FUN_00dba7a0_cls* src)
{
    RefCountedObj* newObj = src->m_pEntryObject;
    if (newObj)
    {
        newObj->m_refFlags++;
        newObj->m_iObjectReferenceCount++;
    }
    RefCountedObj* oldObj = m_pEntryObject;
    if (oldObj)
    {
        int delta = -1;
        oldObj->m_refFlags += delta;
        oldObj->m_iObjectReferenceCount += delta;
        if (oldObj->m_iObjectReferenceCount == 0)
        {
            delete oldObj;
            m_pEntryObject = src->m_pEntryObject;
            return;
        }
        m_pEntryObject = src->m_pEntryObject;
        return;
    }
    m_pEntryObject = src->m_pEntryObject;
}

struct DBA7F0Object
{
    virtual ~DBA7F0Object();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_iReferenceCount;
};

struct DBA7F0Ref
{
    DBA7F0Object* m_pRetainedObject;

    void ReleaseStorage_00dba7f0();
};

// @fnv 0x00dba7f0
// src: GUESS 0x00dba7f0 (confidence: low)
void DBA7F0Ref::ReleaseStorage_00dba7f0()
{
    DBA7F0Object* object = m_pRetainedObject;
    if (object)
    {
        object->m_sReferenceCount += -1;
        object->m_iReferenceCount += -1;
        if (object->m_iReferenceCount == 0)
            delete object;
    }
}

struct FUN_00dba810_pair
{
    unsigned int lo;
    unsigned int hi;
};

class ValueSource
{
  public:
    virtual void v0();
    virtual FUN_00dba810_pair* v1(FUN_00dba810_pair* out);
};

struct FUN_00dba810_cls
{
    ValueSource* m_pSource;

    FUN_00dba810_pair GetSourcePair();
};

// Returns the pair from m_pSource->v1, or a zero pair when m_pSource is null.
// @fnv 0x00dba810
FUN_00dba810_pair FUN_00dba810_cls::GetSourcePair()
{
    FUN_00dba810_pair zeroPair;
    FUN_00dba810_pair tmpPair;
    zeroPair.lo = 0;
    zeroPair.hi = 0;
    FUN_00dba810_pair* src;
    if (m_pSource != 0)
    {
        src = m_pSource->v1(&tmpPair);
    }
    else
    {
        src = &zeroPair;
    }
    return *src;
}

struct VTarget
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3(void* a, void* b) = 0;
};

struct FUN_00dba870_cls
{
    VTarget* m_pFlagTarget;
    void* __thiscall UpdateState_00dba870(void* a, void* b);
};

// @fnv 0x00dba870
// src: GUESS 0x00dba870 (confidence: low)
void* FUN_00dba870_cls::UpdateState_00dba870(void* a, void* b)
{
    VTarget* target = this->m_pFlagTarget;
    target->v3(a, b);
    return a;
}

struct FUN_00dba8b0_tgt
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
};

struct FUN_00dba8b0_cls
{
    FUN_00dba8b0_tgt* m_00;
    void __thiscall ForwardCall_00dba8b0();
};

// @fnv 0x00dba8b0
// src: GUESS 0x00dba8b0 (confidence: low)
void FUN_00dba8b0_cls::ForwardCall_00dba8b0()
{
    m_00->unk14();
}

struct FnvCpu_FUN_00dba8d0_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00dba8d0_CpuOwner
{
    FnvCpu_FUN_00dba8d0_CpuInterface* target;
    void ForwardCall_00dba8d0(int arg0);
};
// @fnv 0x00dba8d0
// src: GUESS 0x00dba8d0 (confidence: low)
void FnvCpu_FUN_00dba8d0_CpuOwner::ForwardCall_00dba8d0(int arg0)
{
    target->Invoke(arg0);
}

// FUN_00dba8e0 (0x00dba8e0, 9 bytes) - forwarding stub.
//
//   mov ecx, [ecx]        ; ecx = this->m_00   (the owned sub-object)
//   mov eax, [ecx]        ; eax = m_00->vptr
//   mov eax, [eax+0x20]   ; eax = vtable slot 8
//   jmp eax               ; tail jump, argument forwarded in place
//
// The stub owns the object at owner+0x00 and forwards its single pointer
// argument unchanged (the callee pops it), so the stub needs no prologue and
// no epilogue of its own.
//
// MSVC 2008 puts the FIRST virtual at vptr+0 (the RTTI pointer lives at
// [vftable-4]), so the virtual at vtable offset 0x20 is the NINTH one: eight
// dummies plus the real one.
//
// The tail-jump target register follows the callee's stack arguments: a
// virtual call with NO stack argument gets its target in EDX (jmp edx), a
// call with one 4-byte stack argument forwarded in place gets it in EAX
// (jmp eax) - which is what the original does.  The virtual therefore takes
// one pointer argument and returns void (a non-void return would reserve EAX
// for the result and push the call target into EDX instead).
struct Sub_dba8e0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20(void* a);
};

struct Owner_dba8e0
{
    Sub_dba8e0* m_target;
    void __thiscall InvokeVirtualMethod_00dba8e0(void* a);
};

// @fnv 0x00dba8e0
// src: GUESS 0x00dba8e0 (confidence: low)
void __thiscall Owner_dba8e0::InvokeVirtualMethod_00dba8e0(void* a)
{
    m_target->v20(a);
}

struct Dispatch
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void* V24(void* apFirst, void* apSecond);
};

struct FUN_00dba8f0_cls
{
    Dispatch* m_pDispatch;

    void* EvaluateValue_00dba8f0(void* apFirst, void* apSecond);
};

// @fnv 0x00dba8f0
// src: GUESS 0x00dba8f0 (confidence: low)
void* FUN_00dba8f0_cls::EvaluateValue_00dba8f0(void* apFirst, void* apSecond)
{
    m_pDispatch->V24(apFirst, apSecond);
    return apFirst;
}

struct FnvCpu_FUN_00dba910_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00dba910_CpuOwner
{
    FnvCpu_FUN_00dba910_CpuInterface* target;
    void ForwardCall_00dba910(int arg0);
};
// @fnv 0x00dba910
// src: GUESS 0x00dba910 (confidence: low)
void FnvCpu_FUN_00dba910_CpuOwner::ForwardCall_00dba910(int arg0)
{
    target->Invoke(arg0);
}

struct S_00dba990_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual int v12(void* arg);
};

struct S_00dba990
{
    S_00dba990_Target* m_pFlagTarget;
    void* m_arg;

    int ForwardCall_00dba990();
};

// @fnv 0x00dba990
// src: GUESS 0x00dba990 (confidence: low)
int S_00dba990::ForwardCall_00dba990()
{
    return m_pFlagTarget->v12(m_arg);
}

struct InnerObj
{
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13(void* a);
};

struct FUN_00dba9d0_cls
{
    InnerObj* m_00;
    void* m_04;
    void* __thiscall GetWrappedDataObject(FUN_00dba760_cls* arg);
};

// Calls v13 on m_00 with m_04, passes the result to arg's FUN_00dba760, and returns arg.
// @fnv 0x00dba9d0
// src: GUESS 0x00dba9d0 (confidence: medium)
void* __thiscall FUN_00dba9d0_cls::GetWrappedDataObject(FUN_00dba760_cls* arg)
{
    void* result = m_00->v13(m_04);

    arg->hkDataObject_hkDataObject(result);

    return arg;
}

struct FUN_00dbaa30_target
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40(void* p, __int64 a);
};

struct FUN_00dbaa30_cls
{
    FUN_00dbaa30_target* m_00;
    void* m_04;
    void __thiscall ForwardCall_00dbaa30(int a1);
};

// @fnv 0x00dbaa30
// src: GUESS 0x00dbaa30 (confidence: low)
void __thiscall FUN_00dbaa30_cls::ForwardCall_00dbaa30(int aiValue)
{
    m_00->v40(m_04, (__int64)aiValue);
}

// DispatchToObject: forwards a call through the object stored at offset 0.
struct VirtDispatchIface
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void Dispatch(void* p1, void* value);
};

struct FUN_00dbaa50_cls
{
    void* m_pObject;
    void* m_pParam;
    void __thiscall DispatchToObject(void** pArg);
};

// @fnv 0x00dbaa50
void __thiscall FUN_00dbaa50_cls::DispatchToObject(void** pArg)
{
    VirtDispatchIface* obj = (VirtDispatchIface*)m_pObject;
    obj->Dispatch(m_pParam, *pArg);
}

struct Callee
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a, int b);
};

struct Holder
{
    Callee* m_pCallee;
    int m_iArg;
    void InvokeWithArg(int* pParam);
};

// @fnv 0x00dbaa70
void Holder::InvokeWithArg(int* piValue)
{
    m_pCallee->v21(m_iArg, *piValue);
}

struct SpawnedDispatcher
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
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
    virtual void v40(void* target, int a, int b);
};

struct FUN_00dbaa90_cls
{
    SpawnedDispatcher* m_pDispatcher;
    void* m_pFlagTarget;

    void ForwardCall_00dbaa90(int a, int b);
};

// @fnv 0x00dbaa90
// src: GUESS 0x00dbaa90 (confidence: low)
void FUN_00dbaa90_cls::ForwardCall_00dbaa90(int aiArg1, int aiArg2)
{
    m_pDispatcher->v40(m_pFlagTarget, aiArg1, aiArg2);
}

struct FUN_00dbaad0_target
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12(void* p, int a);
};

struct FUN_00dbaad0_cls
{
    FUN_00dbaad0_target* m_00;
    void* m_04;
    void __thiscall ForwardCall_00dbaad0(int a1);
};

// @fnv 0x00dbaad0
// src: GUESS 0x00dbaad0 (confidence: low)
void FUN_00dbaad0_cls::ForwardCall_00dbaad0(int aiValue)
{
    m_00->v12(m_04, aiValue);
}

struct SpawnedPair
{
    void* first;
    void* second;
};

struct FUN_00dbab90_cls
{
    void* m_pObservedSource;

    SpawnedPair __thiscall UpdateState_00dbab90(void* value);
};

// @fnv 0x00dbab90
// src: GUESS 0x00dbab90 (confidence: low)
SpawnedPair FUN_00dbab90_cls::UpdateState_00dbab90(void* value)
{
    SpawnedPair r;
    r.first = m_pObservedSource;
    r.second = value;
    return r;
}

struct DBABE0Target
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void get(void* arg);
};

struct DBABE0Binding
{
    DBABE0Target* m_target;

    void Get_Thunk(void* arg);
};

// @fnv 0x00dbabe0
// src: GUESS 0x00dbabe0 (confidence: medium)
void DBABE0Binding::Get_Thunk(void* arg)
{
    m_target->get(arg);
}

namespace fnv_00dbac10 {
struct CpuInterface
{
    virtual void slot00();
    virtual void Invoke();
};
struct CpuObject
{
    CpuInterface* target;
    void ForwardCall_00dbac10();
};
// @fnv 0x00dbac10
// src: GUESS 0x00dbac10 (confidence: low)
void CpuObject::ForwardCall_00dbac10()
{
    target->Invoke();
}
}  // namespace fnv_00dbac10

struct VirtualTarget00
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(void* q, int a1, int a2);
};

struct FUN_00dbad80_cls
{
    VirtualTarget00* m_pFlagTarget;
    void* m_pArg;
    void __thiscall InvokeVirtualMethod_00dbad80(int a1, int a2);
};

// @fnv 0x00dbad80
// src: GUESS 0x00dbad80 (confidence: low)
void __thiscall FUN_00dbad80_cls::InvokeVirtualMethod_00dbad80(int aiArg1, int aiArg2)
{
    m_pFlagTarget->v19(m_pArg, aiArg1, aiArg2);
}

struct FUN_00dbade0_obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c(int a);
};

struct FUN_00dbade0_cls
{
    FUN_00dbade0_obj* m_00;
    void __thiscall hkDataArray_setAll(int a);
};

// @fnv 0x00dbade0
// src: HAVOK_LIB 0x00dbade0
void FUN_00dbade0_cls::hkDataArray_setAll(int a)
{
    m_00->v8c(a);
}

struct FnvCpu_FUN_00dbadf0_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00dbadf0_CpuOwner
{
    FnvCpu_FUN_00dbadf0_CpuInterface* target;
    void hkDataArray_setAll_00dbadf0(int arg0);
};
// @fnv 0x00dbadf0
// src: HAVOK_LIB 0x00dbadf0
void FnvCpu_FUN_00dbadf0_CpuOwner::hkDataArray_setAll_00dbadf0(int arg0)
{
    target->Invoke(arg0);
}

struct FnvCpu_FUN_00dbae00_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00dbae00_CpuOwner
{
    FnvCpu_FUN_00dbae00_CpuInterface* target;
    void hkDataArray_setAll_00dbae00(int arg0);
};
// @fnv 0x00dbae00
// src: HAVOK_LIB 0x00dbae00
void FnvCpu_FUN_00dbae00_CpuOwner::hkDataArray_setAll_00dbae00(int arg0)
{
    target->Invoke(arg0);
}

struct FnvCpu_FUN_00dbae30_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00dbae30_CpuOwner
{
    FnvCpu_FUN_00dbae30_CpuInterface* target;
    void ForwardCall_00dbae30(int arg0);
};
// @fnv 0x00dbae30
// src: GUESS 0x00dbae30 (confidence: low)
void FnvCpu_FUN_00dbae30_CpuOwner::ForwardCall_00dbae30(int arg0)
{
    target->Invoke(arg0);
}

struct FUN_00dbae60_Inner
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void Tail(int a);
};

struct FUN_00dbae60_cls
{
    FUN_00dbae60_Inner* m_00;
    void __thiscall InvokeVirtualMethod_00dbae60(int a);
};

// @fnv 0x00dbae60
// src: GUESS 0x00dbae60 (confidence: low)
void FUN_00dbae60_cls::InvokeVirtualMethod_00dbae60(int a)
{
    m_00->Tail(a);
}

// The controller reached through this->controller is a polymorphic object.
// FUN_00dbae80 forwards to the virtual at vtable offset 0x64 (slot 25) of that
// controller; the two arguments are already in the caller's stack frame, so the
// forwarded call is a plain tail jump.
struct Controller_cls
{
    virtual void v00(void* a, void* b);
    virtual void v01(void* a, void* b);
    virtual void v02(void* a, void* b);
    virtual void v03(void* a, void* b);
    virtual void v04(void* a, void* b);
    virtual void v05(void* a, void* b);
    virtual void v06(void* a, void* b);
    virtual void v07(void* a, void* b);
    virtual void v08(void* a, void* b);
    virtual void v09(void* a, void* b);
    virtual void v10(void* a, void* b);
    virtual void v11(void* a, void* b);
    virtual void v12(void* a, void* b);
    virtual void v13(void* a, void* b);
    virtual void v14(void* a, void* b);
    virtual void v15(void* a, void* b);
    virtual void v16(void* a, void* b);
    virtual void v17(void* a, void* b);
    virtual void v18(void* a, void* b);
    virtual void v19(void* a, void* b);
    virtual void v20(void* a, void* b);
    virtual void v21(void* a, void* b);
    virtual void v22(void* a, void* b);
    virtual void v23(void* a, void* b);
    virtual void v24(void* a, void* b);
    virtual void v25(void* a, void* b);
};

struct FUN_00dbae80_cls
{
    Controller_cls* controller;  // +0x00
    void* p1;                    // +0x04
    void __thiscall InvokeVirtualMethod_00dbae80(void* a, void* b);
};

// @fnv 0x00dbae80
// src: GUESS 0x00dbae80 (confidence: low)
void __thiscall FUN_00dbae80_cls::InvokeVirtualMethod_00dbae80(void* a, void* b)
{
    controller->v25(a, b);
}

// FUN_00dbae90 : the stub family - load a sub-object out of `this` and tail-jump
// to one of its virtuals.  The target is in EAX, which means the callee takes ONE
// 4-byte stack argument forwarded in place.  The virtual sits at vtable offset
// 0x60, and MSVC puts the first virtual at vptr+0, so 24 virtuals are needed.
struct Sub_dbae90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
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
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60(void* a);
};
struct Own_dbae90
{
    Sub_dbae90* m_sub;
    void __thiscall ForwardCall_00dbae90(void* a);
};
// @fnv 0x00dbae90
// src: GUESS 0x00dbae90 (confidence: low)
void __thiscall Own_dbae90::ForwardCall_00dbae90(void* a)
{
    m_sub->v60(a);
}

struct S_00dbaed0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct S_00dbaed0_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void vfn28(int index, S_00dbaed0_Elem* e);
};

struct S_00dbaed0_Obj
{
    S_00dbaed0_Target* m_target;
    int ForwardCall_00dba730();
    void DispatchItems(S_00dbaed0_Elem** items);
};

// Calls FUN_00dba730 for a count, then for each index passes the corresponding element to m_target->vfn28.
// @fnv 0x00dbaed0
void S_00dbaed0_Obj::DispatchItems(S_00dbaed0_Elem** items)
{
    int n = ForwardCall_00dba730();
    for (int i = 0; i < n; i++)
        m_target->vfn28(i, *items + i);
}

namespace fnv_00dbaf50 {
struct SpawnedPair
{
    int unk00;
    int unk04;
};

struct FUN_00dbaf50_cls
{
    void Fill(SpawnedPair* apOut);
    bool Equals(FUN_00dbaf50_cls* apOther);
};

// Fills two SpawnedPair values via Fill and returns whether both of their fields are equal.
// @fnv 0x00dbaf50
bool FUN_00dbaf50_cls::Equals(FUN_00dbaf50_cls* apOther)
{
    SpawnedPair aLeft;
    SpawnedPair aRight;
    this->Fill(&aLeft);
    apOther->Fill(&aRight);
    return aLeft.unk00 == aRight.unk00 && aLeft.unk04 == aRight.unk04;
}
}  // namespace fnv_00dbaf50

struct S_Alloc
{
    int unk0;
};
struct S_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_Alloc* m10;
    S_Alloc& heap()
    {
        return *m10;
    }
};
S_Router* hkMemoryRouter_getInstance();
void hkArrayUtil__reserve(S_Alloc& a, void* arr, int n, int esz);

struct S_Obj
{
    virtual void v0();
    virtual void v1();
    virtual int v2();
};

struct S_Item
{
    int m0;
    int m4;
    int m8;
    S_Obj* mc;
    int m10;
    S_Item()
    {
        m0 = 0;
        m4 = 0;
        m8 = 0;
        mc = 0;
        m10 = 0;
    }
};

struct S_Elem
{
    int m0;
    int m4;
    int m8;
    int mc;
};
static inline void SetElem(S_Elem* e, const S_Item& it, int r)
{
    e->m0 = it.m0;
    e->m4 = it.m8;
    e->m8 = it.m10;
    e->mc = r;
}
static inline void SetElem2(S_Elem* e, int a, int b, int c, int r)
{
    e->m0 = a;
    e->m4 = b;
    e->mc = r;
    e->m8 = c;
}
struct S_Iface
{
    virtual void v0();
    virtual void v1();
    virtual int v2();
    virtual int v3();
    virtual S_Obj* v4();
    virtual void v5();
    virtual int v6();
    virtual void v7(int i, S_Item* out);
};

struct S_Arr
{
    S_Elem* data;
    int size;
    int cap;
    void reserve(S_Alloc& a, int n)
    {
        int c = cap & 0x3fffffff;
        if (c < n)
        {
            int c2 = c + c;
            hkArrayUtil__reserve(a, this, (n < c2) ? c2 : n, 16);
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(hkMemoryRouter_getInstance()->heap(), n);
        size = n;
    }
};

struct S_Out
{
    int m0;
    int m4;
    int m8;
    S_Arr arr;
};

struct S_00dbafe0
{
    S_Iface* iface;
    void FillOutFromInterface(S_Out* out);
};

// Fills an S_Out from iface: copies v2/v3, resolves v4's v2, sizes arr to v6 and stores each v7 item with its mc v2.
// @fnv 0x00dbafe0
void S_00dbafe0::FillOutFromInterface(S_Out* out)
{
    out->m0 = iface->v2();
    out->m4 = iface->v3();
    out->m8 = iface->v4() ? iface->v4()->v2() : 0;
    int n = iface->v6();
    out->arr.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
    {
        S_Item it;
        iface->v7(i, &it);
        S_Elem* e = &out->arr.data[i];
        SetElem2(e, it.m0, it.m8, it.m10, it.mc ? it.mc->v2() : 0);
    }
}

struct Fnv299VTarget
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20(int arg);
};
struct FUN_00dbac50_cls
{
    Fnv299VTarget* m_00;
    int m_04;
    void __thiscall DispatchToVTableSlot8(int a1);
};
typedef void(__thiscall* Fnv299Dispatch)(Fnv299VTarget*, int);
// @fnv 0x00dbac50
void FUN_00dbac50_cls::DispatchToVTableSlot8(int aiArg)
{
    Fnv299VTarget* t = m_00;
    void* volatile* table = *(void* volatile**)t;
    *(volatile int*)&aiArg = m_04;
    Fnv299Dispatch fn = (Fnv299Dispatch)table[8];
    fn(t, aiArg);
}

// @fnv 0x00dba660
// src: GUESS 0x00dba660 (confidence: high)
void __cdecl Object_DoNothing_00dba660()
{}

struct ObjectValue
{
    void* object;
    __declspec(noinline) ObjectValue(void* value);
};

ObjectValue::ObjectValue(void* value) : object(value)
{}

struct ObjectProvider
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void* GetObject();
};

struct ProviderWrapper
{
    ObjectProvider* provider;
    ObjectValue GetObjectValue();
};

// @fnv 0x00dba850
ObjectValue ProviderWrapper::GetObjectValue()
{
    return ObjectValue(provider->GetObject());
}

struct DBAB50Object
{
    virtual ~DBAB50Object();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_iReferenceCount;
};

struct FUN_00dbab50
{
    DBAB50Object* m_pRetainedObject;

    FUN_00dbab50(DBAB50Object* p);
};

// @fnv 0x00dbab50
FUN_00dbab50::FUN_00dbab50(DBAB50Object* apObject)
{
    m_pRetainedObject = apObject;
    if (apObject)
    {
        apObject->m_sReferenceCount += 1;
        apObject->m_iReferenceCount += 1;
    }
}

struct DB8000_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct DB8000_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DB8000_Alloc* m10;
    DB8000_Alloc& heap()
    {
        return *m10;
    }
};

struct DB8000_Handle
{
    unsigned int m_00;
    DB8000_Handle* SetField00(unsigned int value);
    void Object_DoNothing_00dba660();
};

struct DB8000_Ref
{
    void* m_pRetainedObject;
    void hkDataObject_hkDataObject(void* p);
    void ReleaseStorage_00dba7f0();
};

struct DB8000_PtrArrayLocalForm
{ // local form of hkArray: 0x00db8000 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }

    void ClearAndRelease()
    {
        DB8000_Alloc& alloc = ((DB8000_Router*)hkMemoryRouter_getInstance())->heap();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, (cap & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct DB8000_Out
{
    const char* m_name;
    int m_unk04;
    int m_unk08;
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void init(const char* name, int unk04)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
        m_name = name;
        m_unk04 = unk04;
        m_unk08 = 0;
    }

    void ClearAndRelease()
    {
        DB8000_Alloc& alloc = ((DB8000_Router*)hkMemoryRouter_getInstance())->heap();
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, (cap & 0x3fffffff) * 16);
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

typedef void(__cdecl* DB8000_Callback)(DB8000_Ref*);

struct DB8000_OpData
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct DB8000_Op
{
    int m_type;
    DB8000_OpData* m_data;
};

struct DB8000_Item
{
    const char* m_name0;
    const char* m_name1;
    int m_unk08;
    int m_unk0c;
    DB8000_Op* m_pOperations;
    int m_numOps;
};

typedef hkArray<DB8000_Item*> DB8000_ItemArray;

extern int __cdecl hkString_strCmp(const char* a, const char* b);

struct DB8000_Self
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfn3(DB8000_Out* out);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned int vfn9(const char* name);

    void hkDataWorldDict_renameClass(DB8000_Handle* h, const char* name);
    void RenameClassMember(DB8000_Handle* h, int a, int b);
    void FUN_00dc7d20(DB8000_Handle* h, int a, int b, int c, int d);
    void ProcessEntries_00dc7600(DB8000_Handle* h, int a);
    void InitAndRun(const char* name, DB8000_PtrArrayLocalForm* out);
    void AssignRefCountedSlot(DB8000_Handle* h1, DB8000_Handle* h2);
    void CallWithReset(const char* name, DB8000_PtrArrayLocalForm* out);
    void hkDataWorldDict_castObject(DB8000_Ref* ref, DB8000_Handle* h);
    void ReleaseRef(DB8000_Handle* h);
    void hkDataWorldDict_setClassVersion(DB8000_Handle* h, int a);
};

// Iterates items, selects a name, and dispatches recognized operations through self; some item fields also control reference handling.
// @fnv 0x00db8000
// src: XBOX_PDB 0x00db8000
static __declspec(noinline) int __cdecl applyPatchesFinally(DB8000_Self* self, DB8000_ItemArray* items)
{
    int i = 0;
    if (items->m_iElementCount > 0)
    {
        do
        {
            DB8000_Item* item = items->m_data[i];
            const char* name;
            if (item->m_name0 != 0)
            {
                name = item->m_name0;
            }
            else
            {
                name = item->m_name1;
            }

            if (item->m_unk08 == -1)
            {
                DB8000_Out out;
                out.init(name, item->m_unk0c);
                if (self->vfn9(name) != 0)
                {
                    out.ClearAndRelease();
                    return 1;
                }
                self->vfn3(&out);
                out.ClearAndRelease();
            }

            DB8000_Handle hMain;
            hMain.SetField00(self->vfn9(name));

            if (item->m_name0 != 0 && item->m_name1 != 0 && hkString_strCmp(item->m_name0, item->m_name1) != 0)
            {
                self->hkDataWorldDict_renameClass(&hMain, item->m_name1);
            }

            int jIndex = 0;
            if (item->m_numOps > 0)
            {
                do
                {
                    DB8000_Op* op = &item->m_pOperations[jIndex];
                    switch (op->m_type)
                    {
                    case 3:
                        self->RenameClassMember(&hMain, op->m_data->m_00, op->m_data->m_04);
                        break;
                    case 1:
                        self->FUN_00dc7d20(&hMain, op->m_data->m_00, op->m_data->m_04, op->m_data->m_08,
                                           op->m_data->m_0c);
                        break;
                    case 2:
                        self->ProcessEntries_00dc7600(&hMain, op->m_data->m_00);
                        break;
                    case 4: {
                        DB8000_Callback pCallback = (DB8000_Callback)op->m_data->m_04;
                        DB8000_PtrArrayLocalForm arr4;
                        arr4.init();
                        self->InitAndRun(name, &arr4);
                        for (int kIndex = 0; kIndex < arr4.m_iElementCount; ++kIndex)
                        {
                            DB8000_Ref ref4;
                            ref4.hkDataObject_hkDataObject(arr4.m_data[kIndex]);
                            pCallback(&ref4);
                            ref4.ReleaseStorage_00dba7f0();
                        }
                        arr4.ClearAndRelease();
                        break;
                    }
                    case 7: {
                        const char* pString = (const char*)op->m_data->m_04;
                        unsigned int val = pString ? self->vfn9(pString) : 0;
                        DB8000_Handle hSub7;
                        hSub7.SetField00(val);
                        self->AssignRefCountedSlot(&hMain, &hSub7);
                        hSub7.Object_DoNothing_00dba660();
                        break;
                    }
                    case 5: {
                        DB8000_OpData* d = op->m_data;
                        DB8000_Handle hSub5;
                        hSub5.SetField00(self->vfn9((const char*)d->m_00));
                        DB8000_PtrArrayLocalForm arr5;
                        arr5.init();
                        self->CallWithReset(name, &arr5);
                        for (int kIndex = 0; kIndex < arr5.m_iElementCount; ++kIndex)
                        {
                            DB8000_Ref ref5;
                            ref5.hkDataObject_hkDataObject(arr5.m_data[kIndex]);
                            self->hkDataWorldDict_castObject(&ref5, &hSub5);
                            ref5.ReleaseStorage_00dba7f0();
                        }
                        arr5.ClearAndRelease();
                        hSub5.Object_DoNothing_00dba660();
                        break;
                    }
                    default:
                        break;
                    }
                    ++jIndex;
                } while (jIndex < item->m_numOps);
            }

            int unk0c = item->m_unk0c;
            if (unk0c == -1)
            {
                self->ReleaseRef(&hMain);
            }
            else if (item->m_unk08 != -1 && item->m_unk08 != unk0c)
            {
                self->hkDataWorldDict_setClassVersion(&hMain, unk0c);
            }

            hMain.Object_DoNothing_00dba660();
            ++i;
        } while (i < items->m_iElementCount);
    }
    return 0;
}

volatile DB8000_Self* g_db8000_self;
volatile DB8000_ItemArray* g_db8000_items;
volatile int g_db8000_ret;
void call_db8000()
{
    g_db8000_ret = applyPatchesFinally((DB8000_Self*)g_db8000_self, (DB8000_ItemArray*)g_db8000_items);
}

struct DataClassMemberAccess
{
    S_00dbaed0_Target* m_pClassImpl;

    void InvokeVirtualMethod_00dba720(int index, S_00dbaed0_Elem* info) const;
};

// @fnv 0x00dba720
// src: GUESS 0x00dba720 (confidence: low)
void DataClassMemberAccess::InvokeVirtualMethod_00dba720(int index, S_00dbaed0_Elem* info) const
{
    m_pClassImpl->vfn28(index, info);
}

struct MemberValueHandle;

struct MemberValueTarget
{
    virtual void Reserved00();
    virtual void Reserved04();
    virtual void Reserved08();
    virtual void Reserved0c();
    virtual void Reserved10();
    virtual void Reserved14();
    virtual void Reserved18();
    virtual void Reserved1c();
    virtual void Reserved20();
    virtual void Reserved24();
    virtual void Reserved28();
    virtual void Reserved2c();
    virtual void Reserved30();
    virtual void Reserved34();
    virtual void Reserved38();
    virtual void Reserved3c();
    virtual void Reserved40();
    virtual void Reserved44();
    virtual void Reserved48();
    virtual void Reserved4c();
    virtual void Reserved50();
    virtual void Reserved54();
    virtual void Reserved58();
    virtual void Assign(const char* name, const MemberValueHandle& value);
};

struct MemberValueHandle
{
    MemberValueTarget* implementation;
    const char* name;

    void Assign_Thunk(const MemberValueHandle& value);
};

// @fnv 0x00dbaa10
// src: GUESS 0x00dbaa10 (confidence: medium)
void MemberValueHandle::Assign_Thunk(const MemberValueHandle& value)
{
    implementation->Assign(name, value);
}

struct ArrayReserveTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C(int a);
};

struct ArrayReserveHandle
{
    ArrayReserveTarget* m_inner;
    void ForwardCall_00dbabf0(int a);
};

// @fnv 0x00dbabf0
// src: GUESS 0x00dbabf0 (confidence: low)
void ArrayReserveHandle::ForwardCall_00dbabf0(int a)
{
    m_inner->v0C(a);
}

struct BulkArrayTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
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
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C(const short* values, int count);
};

struct BulkArrayWrapper
{
    BulkArrayTarget* m_inner;
    void InvokeVirtualMethod_00dbae20(const short* values, int count);
};

// @fnv 0x00dbae20
// src: GUESS 0x00dbae20 (confidence: low)
void BulkArrayWrapper::InvokeVirtualMethod_00dbae20(const short* values, int count)
{
    m_inner->v7C(values, count);
}

struct ArrayBulkIntTarget
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void Forward(const int* values, int count);
};

struct ArrayBulkIntBinding
{
    ArrayBulkIntTarget* m_pArrayBulkIntTarget;
    void InvokeVirtualMethod_00dbae40(const int* values, int count);
};

// @fnv 0x00dbae40
// src: GUESS 0x00dbae40 (confidence: low)
void ArrayBulkIntBinding::InvokeVirtualMethod_00dbae40(const int* values, int count)
{
    m_pArrayBulkIntTarget->Forward(values, count);
}

struct ArrayBulkInterface
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0c();
    virtual void VirtualFunction10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1c();
    virtual void reserved20();
    virtual void VirtualFunction24();
    virtual void VirtualFunction28();
    virtual void reserved2c();
    virtual void reserved30();
    virtual void reserved34();
    virtual void reserved38();
    virtual void reserved3c();
    virtual void reserved40();
    virtual void reserved44();
    virtual void reserved48();
    virtual void reserved4c();
    virtual void reserved50();
    virtual void reserved54();
    virtual void reserved58();
    virtual void reserved5c();
    virtual void reserved60();
    virtual void reserved64();
    virtual void reserved68();
    virtual void reserved6c();
    virtual void assignAll(const unsigned int* values, int count);
};

struct ArrayBulkHandle
{
    ArrayBulkInterface* implementation;
    void AssignAll_Thunk(const unsigned int* values, int count);
};

// @fnv 0x00dbae50
// src: GUESS 0x00dbae50 (confidence: medium)
void ArrayBulkHandle::AssignAll_Thunk(const unsigned int* values, int count)
{
    implementation->assignAll(values, count);
}

struct ArrayBulkTarget;
typedef void(__fastcall* ArrayBulkSlot)(ArrayBulkTarget*, int);
struct ArrayBulkTarget
{
    ArrayBulkSlot* vtbl;
};
struct ArrayBulkOwner
{
    ArrayBulkTarget* object;
};

// @fnv 0x00dbae70
// src: GUESS 0x00dbae70 (confidence: low)
void __fastcall Hkdataobject_UpdateState_00dbae70(ArrayBulkOwner* self, int forwarded)
{
    ArrayBulkTarget* object = self->object;
    object->vtbl[26](object, forwarded);
}

struct DataObjectHandle
{
    RefObj* object;
    DataObjectHandle* __thiscall hkDataObject_hkDataObject(RefObj* p);
};

// @fnv 0x00dba760
// src: XBOX_PDB 0x00dba760
DataObjectHandle* DataObjectHandle::hkDataObject_hkDataObject(RefObj* apObject)
{
    object = apObject;
    if (apObject != 0)
    {
        apObject->m_w06++;
        apObject->m_i08++;
    }
    return this;
}

struct DataClassResult : FUN_00dba650_cls
{
    DataClassResult* SetField00(unsigned int value);
    DataClassResult(unsigned int value)
    {
        SetField00(value);
    }
};

// src: GUESS 0x00dba650 (confidence: low)
__declspec(noinline) DataClassResult* DataClassResult::SetField00(unsigned int value)
{
    m_00 = value;
    return this;
}

struct DataClassProvider
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual unsigned int getClassValue();
};

struct DataClassAccess
{
    DataClassProvider* provider;
    DataClassResult ProcessAndReturnValue_00dbac20();
};

// @fnv 0x00dbac20
// src: GUESS 0x00dbac20 (confidence: low)
DataClassResult DataClassAccess::ProcessAndReturnValue_00dbac20()
{
    return DataClassResult(provider->getClassValue());
}
