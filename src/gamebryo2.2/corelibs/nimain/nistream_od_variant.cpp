
// src/gamebryo2.2/corelibs/nimain/nistream_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nistream.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


extern "C" void __cdecl Clear();
struct NiStream2
{
    void ClearTopLevelObjects();
    void Clear();
    void BSStream_FreeAllObjects();
};
// @fnv 0x00c3b370
// src: COMMUNITY 0x00c3b370
void NiStream2::BSStream_FreeAllObjects()
{
    ClearTopLevelObjects();
    *(int*)((char*)this + 0x25c) = 0;
    *(int*)((char*)this + 0x26c) = 0;
    *(int*)((char*)this + 0x260) = 0;
    *(int*)((char*)this + 0x270) = 0;
    Clear();
}

struct S_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc(S_Obj* pkA, int flag);
};

struct S_Stream
{
    unsigned int __thiscall FUN_00a63460();
    S_Obj* __thiscall FUN_00a63430();
};

struct S_Arr
{
    void __thiscall FUN_00c4c920(unsigned int count);
};

struct S_Class
{
    int unk00;
    int unk04;
    S_Arr unk08;
    void __thiscall nullsub_3(S_Stream* stream);
    void __thiscall BSNodeReferences_LinkObject(S_Stream* stream);
};

// @fnv 0x00c64ad0
// src: XBOX_PDB 0x00c64ad0
void __thiscall S_Class::BSNodeReferences_LinkObject(S_Stream* stream)
{
    nullsub_3(stream);
    unsigned int count = stream->FUN_00a63460();
    if (count)
    {
        unk08.FUN_00c4c920(count);
        count >>= 1;
        for (unsigned int i = 0; i < count; i++)
        {
            int pkParent[3];
            S_Obj* pkA;
            S_Obj* ref;
            ref = stream->FUN_00a63430();
            pkA = stream->FUN_00a63430();
            if (ref && pkA)
            {
                ref->vfn_dc(pkA, 0);
            }
        }
    }
}
