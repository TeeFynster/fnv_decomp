
// src/havok/unplaced/cellmopp_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/havok/unplaced/cellmopp.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/havok/unplaced/cellmopp.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cellmopp.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Child;
struct Item
{
    int unk00;
    int unk04;
    Child* child;
};
struct Result
{
    int unk00;
    Item* item;
};
struct This
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual Result* GetResult(char* output);
    void bhkBvTreeShape_CopyMembers(int first, int second);
    void bhkShape_CopyMembers(int first, int second);
};
struct Resolved
{
    int unk00;
    int unk04;
    Child* child;
};
struct Child
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
    virtual Resolved* Resolve(int value);
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual bool IsRejected(int value);
};

// @fnv 0x00ca4e50
// src: XBOX_PDB 0x00ca4e50
void This::bhkBvTreeShape_CopyMembers(int first, int second)
{
    char output;
    Result* result = GetResult(&output);
    if (result->item)
    {
        Child* child = result->item->child;
        if (child && !child->IsRejected(second))
        {
            Resolved* found = child->Resolve(second);
            result->item = (Item*)(found ? found->child : 0);
        }
    }
    bhkShape_CopyMembers(first, second);
}

struct S_00ca4ec0_Stream
{
    void ReadLinkID();
};

struct S_00ca4ec0_Out
{
    int unk00;
    int m_04;
};

struct S_00ca4ec0_Base
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
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual S_00ca4ec0_Out* vb4(int* out);
    void bhkShape_LoadBinary(S_00ca4ec0_Stream& kStream);
};

struct S_00ca4ec0 : S_00ca4ec0_Base
{
    void bhkBvTreeShape_LoadBinary(S_00ca4ec0_Stream& kStream);
};

// @fnv 0x00ca4ec0
// src: XBOX_PDB 0x00ca4ec0
void S_00ca4ec0::bhkBvTreeShape_LoadBinary(S_00ca4ec0_Stream& kStream)
{
    kStream.ReadLinkID();
    S_00ca4ec0_Base::bhkShape_LoadBinary(kStream);
    int tmp;
    vb4(&tmp)->m_04 = 0;
}

struct NiStream;
struct FirstInterface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* FUN_00ca4f40_get();
};
struct SecondInterface
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
    virtual void FUN_00ca4f40_stream(NiStream* stream);
};
struct ReturnedObject
{
    int unk00;
    int unk04;
    SecondInterface* unk08;
};
struct HC1Base
{
    int unk00;
    int unk04;
    FirstInterface* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    bool __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(NiStream* stream);
    void __thiscall bhkBvTreeShape_RegisterStreamables(NiStream* stream);
};
// @fnv 0x00ca4f40
// src: XBOX_PDB 0x00ca4f40
void HC1Base::bhkBvTreeShape_RegisterStreamables(NiStream* stream)
{
    if (this)
    {
        FirstInterface* first = unk08;
        if (first)
        {
            void* result = first->FUN_00ca4f40_get();
            if (result)
            {
                ReturnedObject* object = (ReturnedObject*)((char*)result - 0x10);
                if (object)
                {
                    SecondInterface* second = object->unk08;
                    if (second)
                        second->FUN_00ca4f40_stream(stream);
                }
            }
        }
    }
    BSPackedAdditionalGeometryData_RegisterStreamables(stream);
}

struct Link
{
};
struct Header
{
    int state;
    int flags;
    void* value;
    int type;
    Link link;
};
struct Node
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual Link* get();
};
struct Sink
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void set(void*);
};
struct Owner
{
    int state;
    int flags;
    Node* node;
    void bhkShape_SaveBinary(Sink*);
    void bhkBvTreeShape_SaveBinary(Sink*);
    void* getValue()
    {
        if (this)
        {
            Node* current = node;
            if (current)
            {
                Link* link = current->get();
                if (link)
                {
                    Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                    if (header)
                        return header->value;
                }
            }
        }
        return 0;
    }
};
// @fnv 0x00ca4f80
// src: XBOX_PDB 0x00ca4f80
void Owner::bhkBvTreeShape_SaveBinary(Sink* sink)
{
    sink->set(getValue());
    bhkShape_SaveBinary(sink);
}

namespace fnv_00ca5010 {
// Exe 0x00ca5010: unit-local Interface view; declarations and layout are preserved.
struct CellmoppInterfaceView
{
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* GetObject() = 0;
};
typedef void(__thiscall* FinishObject)(CellmoppInterfaceView*);
struct Owner
{
    int unk00;
    int unk04;
    CellmoppInterfaceView* unk08;
    void bhkBvTreeShape_DestroyDisplayGeometry();
};
// @fnv 0x00ca5010
// src: XBOX_PDB 0x00ca5010
void Owner::bhkBvTreeShape_DestroyDisplayGeometry()
{
    if (this == 0)
        return;
    CellmoppInterfaceView* input = unk08;
    if (input == 0)
        return;
    void* raw = input->GetObject();
    if (raw == 0)
        return;
    char* base = (char*)raw - 0x10;
    if (base == 0)
        return;
    CellmoppInterfaceView* object = *(CellmoppInterfaceView**)(base + 8);
    if (object == 0)
        return;
    FinishObject finish = (FinishObject)(*(void***)object)[54];
    finish(object);
}
}  // namespace fnv_00ca5010

namespace fnv_00cafff0 {
struct Owner
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
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45(char*);
    void bhkBvTreeShape_CopyMembers(int, int);
    void bhkTriSampledHeightFieldBvTreeShape_CopyMembers(int first, int second);
};
// @fnv 0x00cafff0
// src: XBOX_PDB 0x00cafff0
void Owner::bhkTriSampledHeightFieldBvTreeShape_CopyMembers(int first, int second)
{
    char local;
    V45(&local);
    bhkBvTreeShape_CopyMembers(first, second);
}
}  // namespace fnv_00cafff0

extern __declspec(thread) int iCurrentMemContext;

struct MemoryContextGuard
{
    int previous;
    MemoryContextGuard()
    {
        previous = iCurrentMemContext;
        iCurrentMemContext = 0x10;
    }
    ~MemoryContextGuard()
    {
        iCurrentMemContext = previous;
    }
};

struct FUN_00cb0780_Allocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Free(void* memory, unsigned int size);
};
struct FUN_00cb0780_Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb0780_Allocator* allocator;
};
void* __cdecl hkMemoryRouter_getInstance();

struct FUN_00cb0780_class
{
    int unk00;
    int unk04;
    int unk08;
    void* memory;
    void bhkTriSampledHeightFieldBvTreeShape_KillCinfo(bool release);
};
// @fnv 0x00cb0780
// src: XBOX_PDB 0x00cb0780
void FUN_00cb0780_class::bhkTriSampledHeightFieldBvTreeShape_KillCinfo(bool release)
{
    void* allocation;
    MemoryContextGuard guard;
    if (release)
    {
        allocation = memory;
        if (allocation)
        {
            FUN_00cb0780_Manager* manager = (FUN_00cb0780_Manager*)hkMemoryRouter_getInstance();
            manager->allocator->Free(allocation, 0x30);
        }
        memory = 0;
    }
}

struct ThreadState
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
extern __declspec(thread) ThreadState s_tlsData;
struct NiStringArray
{
    void* unk00;
    char** data;
    unsigned short capacity;
    unsigned short count;
    unsigned short unk0C;
    unsigned short growth;
    void FUN_0096ad30(unsigned int newCapacity);
    void FUN_0096ae90(unsigned int index, char** value);
};
struct GlobalString
{
    const char* value;
};
extern GlobalString g_01268350;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* text);
struct StringBuilder
{
    void bhkBvTreeShape_GetViewerStrings(NiStringArray* array);
    void bhkTriSampledHeightFieldBvTreeShape_GetViewerStrings(NiStringArray* array);
};
struct ThreadStateGuard
{
    int previous;
    ThreadStateGuard() : previous(s_tlsData.unk2B4)
    {
        s_tlsData.unk2B4 = 0x10;
    }
    ~ThreadStateGuard()
    {
        s_tlsData.unk2B4 = previous;
    }
};
// @fnv 0x00cb09b0
// src: XBOX_PDB 0x00cb09b0
void StringBuilder::bhkTriSampledHeightFieldBvTreeShape_GetViewerStrings(NiStringArray* array)
{
    ThreadStateGuard guard;
    bhkBvTreeShape_GetViewerStrings(array);
    char* value = NiViewerStrings_NiGetViewerString_Title(g_01268350.value);
    unsigned int count = array->count;
    unsigned int capacity = array->capacity;
    if (count >= capacity)
        array->FUN_0096ad30(count + array->growth);
    array->FUN_0096ae90(count, &value);
}

struct EP
{
    int u0[0x50];
    int m254;
    int m260;
    int __thiscall FUN_00a63430();
};

struct K46
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
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual int M45(void* p);
};

struct QTF
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
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual int M45(void* p);
    void __thiscall bhkShape_LinkObject(EP* p);
    void bhkBvTreeShape_LinkObject(EP* a1);
};

// @fnv 0x00ca4f00
// src: XBOX_PDB 0x00ca4f00
void QTF::bhkBvTreeShape_LinkObject(EP* a1)
{
    char tmp;
    void* r;
    r = (void*)this->M45(&tmp);
    int v = a1->FUN_00a63430();
    if (v != 0)
        ((int*)r)[1] = ((int*)v)[2];
    this->bhkShape_LinkObject(a1);
}

struct FUN_00ca4fd0_Value
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void Target(int first, int second);
};

class FUN_00ca4fd0_cls
{
  public:
    int unk00;
    int unk04;
    Node* m_pReferencedNode;

    void bhkBvTreeShape_BuildDisplayGeometry(int first, int second);
};

// @fnv 0x00ca4fd0
// src: XBOX_PDB 0x00ca4fd0
void FUN_00ca4fd0_cls::bhkBvTreeShape_BuildDisplayGeometry(int first, int second)
{
    Node* pNode;
    Link* m_pTaskletData;
    Header* pHeader;
    void* pValue;

    if (this == 0)
    {
        return;
    }
    pNode = m_pReferencedNode;
    if (pNode == 0)
    {
        return;
    }
    m_pTaskletData = pNode->get();
    if (m_pTaskletData == 0)
    {
        return;
    }
    pHeader = reinterpret_cast<Header*>(reinterpret_cast<char*>(m_pTaskletData) - 16);
    if (pHeader == 0)
    {
        return;
    }
    pValue = pHeader->value;
    if (pValue == 0)
    {
        return;
    }
    ((FUN_00ca4fd0_Value*)pValue)->Target(first, second);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);

void bhkBvTreeShape_RembhkShapeRef();

struct RefCounted
{
    int unk00;
    long refCount;
};

struct Owner_Ext : public Owner
{
    void bhkShape_Link(bool flag);
    void bhkBvTreeShape_Link(bool flag);
};

// @fnv 0x00ca5130
// src: XBOX_PDB 0x00ca5130
void Owner_Ext::bhkBvTreeShape_Link(bool flag)
{
    if (flag)
    {
        RefCounted* val = (RefCounted*)getValue();
        if (val)
        {
            InterlockedIncrement(&val->refCount);
        }
    }
    else
    {
        bhkBvTreeShape_RembhkShapeRef();
    }
    bhkShape_Link(flag);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" void __cdecl bhkSerializable_CloneCritLock();
extern "C" void __cdecl bhkSerializable_CloneCritUnlock();
extern "C" char DAT_01030bf4[];
extern "C" char DAT_0104dbac[];
extern "C" int DAT_012680f8;
extern "C" int DAT_012682cc;
extern "C" int DAT_0126834c;

struct SpawnedObject
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void ctorBase();
    SpawnedObject()
    {
        ctorBase();
        m_vtbl = (void*)DAT_01030bf4;
        unk0C = 0;
        unk10 = 0;
        DAT_012680f8++;
        m_vtbl = (void*)DAT_0104dbac;
        DAT_012682cc++;
        m_vtbl = (void*)"@$b";
        DAT_0126834c++;
    }
    void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00cb05d0_cls
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(SpawnedObject* obj, int a1);
    SpawnedObject* bhkTriSampledHeightFieldBvTreeShape_CreateClone(int a1);
};

// @fnv 0x00cb05d0
// src: XBOX_PDB 0x00cb05d0
SpawnedObject* FUN_00cb05d0_cls::bhkTriSampledHeightFieldBvTreeShape_CreateClone(int a1)
{
    ThreadStateGuard guard;
    bhkSerializable_CloneCritLock();
    SpawnedObject* p = new SpawnedObject();
    this->v49(p, a1);
    bhkSerializable_CloneCritUnlock();
    return p;
}

struct FUN_00cb06c0_Alloc
{
    virtual void slot00();
    virtual void* Alloc(unsigned int size);
};
struct FUN_00cb06c0_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb06c0_Alloc* allocator;
};
struct FUN_00cb06c0_Obj
{
    void* FUN_00622490();
};
struct FUN_00cb06c0_cls
{
    int unk00;
    int unk04;
    void* unk08;
    void* unk0c;
    void UpdateState_00cb0030(void* value);
    void* bhkTriSampledHeightFieldBvTreeShape_CreateCinfo(bool* out);
};

// @fnv 0x00cb06c0
// src: XBOX_PDB 0x00cb06c0
void* FUN_00cb06c0_cls::bhkTriSampledHeightFieldBvTreeShape_CreateCinfo(bool* out)
{
    ThreadStateGuard guard;
    bool empty = (unk0c == 0);
    *out = empty;
    if (empty)
    {
        FUN_00cb06c0_Holder* holder = reinterpret_cast<FUN_00cb06c0_Holder*>(hkMemoryRouter_getInstance());
        void* result = holder->allocator->Alloc(0x50);
        if (result != 0)
        {
            result = reinterpret_cast<FUN_00cb06c0_Obj*>(result)->FUN_00622490();
        }
        else
        {
            result = 0;
        }
        unk0c = result;
        if (unk08 != 0)
        {
            UpdateState_00cb0030(result);
        }
    }
    return unk0c;
}

struct S00cb0820_Alloc
{
    virtual void slot00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* memory, unsigned int size);
};
struct S00cb0820_Mem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cb0820_Alloc* allocator;
    S00cb0820_Alloc& heap()
    {
        return *allocator;
    }
};

struct S00cb0820_Ref
{
    void* m_vtbl;
    unsigned short m_usAllocationSize;
    short m_iObjectReferenceCount;
    void* operator new(unsigned int size)
    {
        S00cb0820_Ref* b = (S00cb0820_Ref*)((S00cb0820_Mem*)hkMemoryRouter_getInstance())->heap().Alloc(size);
        b->m_usAllocationSize = (unsigned short)size;
        return b;
    }
    void operator delete(void* p, unsigned int size);
    void FUN_00c905b0();
};

struct S00cb0820_Src
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
    float unk34;
};

struct S00cb0820_Outer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00cb0820_Src src;
};

extern char DAT_010c853c;
extern double DAT_01012070;
extern float DAT_01016248;

struct S00cb0820_Shape : S00cb0820_Ref
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void ProcessAndReturnValue_00d248a0(S00cb0820_Src* src, int n);
};

struct S00cb0820_Shape70 : S00cb0820_Shape
{
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
    int unk5c;
    int unk60;
    int unk64;
    float unk68;
    int unk6c;
    S00cb0820_Shape70(S00cb0820_Src* src)
    {
        ProcessAndReturnValue_00d248a0(src, 2);
        m_vtbl = &DAT_010c853c;
        double d = unk14 - DAT_01012070;
        unk60 = src->unk30;
        unk64 = (int)d;
        unk68 = src->unk34;
    }
};

struct S00cb0820_Obj40 : S00cb0820_Ref
{
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
    S00cb0820_Obj40(S00cb0820_Shape70* shape, float value);
};

struct S00cb0820_Tag
{
    char v;
    S00cb0820_Tag() : v(0)
    {}
    S00cb0820_Tag(const S00cb0820_Tag& o) : v(o.v)
    {}
};

struct S00cb0820_Obj30 : S00cb0820_Ref
{
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
    S00cb0820_Obj30(S00cb0820_Obj40* body, S00cb0820_Tag tag);
};

struct S00cb0820_World
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
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35(S00cb0820_Obj30* obj);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(S00cb0820_Outer* a1);
    void bhkTriSampledHeightFieldBvTreeShape_Init(S00cb0820_Outer* a1);
};

// @fnv 0x00cb0820
// src: XBOX_PDB 0x00cb0820
void S00cb0820_World::bhkTriSampledHeightFieldBvTreeShape_Init(S00cb0820_Outer* a1)
{
    ThreadStateGuard guard;
    S00cb0820_Shape70* shape = new S00cb0820_Shape70(a1 ? &a1->src : 0);
    S00cb0820_Obj40* body = new S00cb0820_Obj40(shape, DAT_01016248);
    S00cb0820_Obj30* phantom = new S00cb0820_Obj30(body, S00cb0820_Tag());
    v35(phantom);
    phantom->FUN_00c905b0();
    body->FUN_00c905b0();
    shape->FUN_00c905b0();
    v47(a1);
}

#include <windows.h>
struct ValueRefObject
{
    virtual void v00();
    virtual void Destroy();
    LONG m_lRefCount;
};

struct ValueHeader
{
    int unk00;
    int unk04;
    ValueRefObject* value;
};

struct ValueNode
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void* get();
};

struct FUN_00ca5080_cls
{
    int unk00;
    int unk04;
    ValueNode* m_pReferencedNode;

    void bhkBvTreeShape_RembhkShapeRef();
};

// @fnv 0x00ca5080
// src: XBOX_PDB 0x00ca5080
void FUN_00ca5080_cls::bhkBvTreeShape_RembhkShapeRef()
{
    ThreadStateGuard guard;
    if (this != 0)
    {
        ValueNode* pNode = m_pReferencedNode;
        if (pNode != 0)
        {
            void* m_pTaskletData = pNode->get();
            if (m_pTaskletData != 0)
            {
                ValueHeader* pHeader = (ValueHeader*)((char*)m_pTaskletData - 16);
                if (pHeader != 0)
                {
                    ValueRefObject* pValue = pHeader->value;
                    if (pValue != 0)
                    {
                        if (InterlockedDecrement(&pValue->m_lRefCount) == 0)
                        {
                            pValue->Destroy();
                        }
                    }
                }
            }
        }
    }
}

struct BinaryDataRecord
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int value10;
    unsigned int value14;
    unsigned int value18;
    unsigned int value1C;
    unsigned int value20;
    unsigned int value24;
    unsigned int value28;
    unsigned int value2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int flags40;
};

struct FUN_00cb00a0_Class
{
    void bhkBvTreeShape_LoadBinary(char*);
    virtual void* slot00(void*);
    virtual void* slot01(void*);
    virtual void* slot02(void*);
    virtual void* slot03(void*);
    virtual void* slot04(void*);
    virtual void* slot05(void*);
    virtual void* slot06(void*);
    virtual void* slot07(void*);
    virtual void* slot08(void*);
    virtual void* slot09(void*);
    virtual void* slot10(void*);
    virtual void* slot11(void*);
    virtual void* slot12(void*);
    virtual void* slot13(void*);
    virtual void* slot14(void*);
    virtual void* slot15(void*);
    virtual void* slot16(void*);
    virtual void* slot17(void*);
    virtual void* slot18(void*);
    virtual void* slot19(void*);
    virtual void* slot20(void*);
    virtual void* slot21(void*);
    virtual void* slot22(void*);
    virtual void* slot23(void*);
    virtual void* slot24(void*);
    virtual void* slot25(void*);
    virtual void* slot26(void*);
    virtual void* slot27(void*);
    virtual void* slot28(void*);
    virtual void* slot29(void*);
    virtual void* slot30(void*);
    virtual void* slot31(void*);
    virtual void* slot32(void*);
    virtual void* slot33(void*);
    virtual void* slot34(void*);
    virtual void* slot35(void*);
    virtual void* slot36(void*);
    virtual void* slot37(void*);
    virtual void* slot38(void*);
    virtual void* slot39(void*);
    virtual void* slot40(void*);
    virtual void* slot41(void*);
    virtual void* slot42(void*);
    virtual void* slot43(void*);
    virtual void* slot44(void*);
    virtual BinaryDataRecord* getData(void*);
    void bhkTriSampledHeightFieldBvTreeShape_LoadBinary(char*);
};

// @fnv 0x00cb00a0
// src: XBOX_PDB 0x00cb00a0
void FUN_00cb00a0_Class::bhkTriSampledHeightFieldBvTreeShape_LoadBinary(char* object)
{
    this->bhkBvTreeShape_LoadBinary(object);
    if (object[0x1e5] != 1)
    {
        void* out;
        volatile BinaryDataRecord* data = (volatile BinaryDataRecord*)this->getData(&out);
        data->value10 = _byteswap_ulong(data->value10);
        data->value14 = _byteswap_ulong(data->value14);
        data->value18 = _byteswap_ulong(data->value18);
        data->value1C = _byteswap_ulong(data->value1C);
        data->value20 = _byteswap_ulong(data->value20);
        data->value24 = _byteswap_ulong(data->value24);
        data->value28 = _byteswap_ulong(data->value28);
        data->value2C = _byteswap_ulong(data->value2C);
        data->flags40 = 0;
    }
}

struct T
{
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual void slot26() = 0;
    virtual void slot27() = 0;
    virtual void slot28() = 0;
    virtual void slot29() = 0;
    virtual void slot30() = 0;
    virtual void slot31() = 0;
    virtual void slot32() = 0;
    virtual void slot33() = 0;
    virtual void slot34() = 0;
    virtual void slot35() = 0;
    virtual void slot36() = 0;
    virtual void slot37() = 0;
    virtual void slot38() = 0;
    virtual void slot39() = 0;
    virtual void slot40() = 0;
    virtual void slot41() = 0;
    virtual void slot42() = 0;
    virtual void slot43() = 0;
    virtual void slot44() = 0;
    virtual void* Query(char*) = 0;
    void bhkTriSampledHeightFieldBvTreeShape_SaveBinary(void*);
    void bhkBvTreeShape_SaveBinary(void*);
};

// @fnv 0x00cb0120
// src: XBOX_PDB 0x00cb0120
void T::bhkTriSampledHeightFieldBvTreeShape_SaveBinary(void* arg)
{
    char local;
    volatile unsigned int* data = (volatile unsigned int*)Query(&local);
    unsigned char* context = (unsigned char*)arg;
    if (context[0x1e4] != 1)
    {
        data[0x4] = _byteswap_ulong(data[0x4]);
        data[0x5] = _byteswap_ulong(data[0x5]);
        data[0x6] = _byteswap_ulong(data[0x6]);
        data[0x7] = _byteswap_ulong(data[0x7]);
        data[0x8] = _byteswap_ulong(data[0x8]);
        data[0x9] = _byteswap_ulong(data[0x9]);
        data[0xa] = _byteswap_ulong(data[0xa]);
        data[0xb] = _byteswap_ulong(data[0xb]);
        data[0x10] = 0;
    }
    bhkBvTreeShape_SaveBinary(arg);
    if (context[0x1e4] != 1)
    {
        data[0x4] = _byteswap_ulong(data[0x4]);
        data[0x5] = _byteswap_ulong(data[0x5]);
        data[0x6] = _byteswap_ulong(data[0x6]);
        data[0x7] = _byteswap_ulong(data[0x7]);
        data[0x8] = _byteswap_ulong(data[0x8]);
        data[0x9] = _byteswap_ulong(data[0x9]);
        data[0xa] = _byteswap_ulong(data[0xa]);
        data[0xb] = _byteswap_ulong(data[0xb]);
        data[0x10] = 0;
    }
}

struct ValueRecord
{
    void* value;
    int type;
    Link link;
};
struct ValueObj
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
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual bool vD0(int a);
};
struct ValueOwner
{
    int state;
    int flags;
    Node* node;
    void* getValue()
    {
        if (this)
        {
            Node* current = node;
            if (current)
            {
                Link* link = current->get();
                if (link)
                {
                    Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                    if (header)
                        return header->value;
                }
            }
        }
        return 0;
    }
    bool __thiscall bhkShape_CanShare(int a);
    bool __thiscall bhkBvTreeShape_CanShare(int a);
};
// @fnv 0x00ca5040
// src: XBOX_PDB 0x00ca5040
bool ValueOwner::bhkBvTreeShape_CanShare(int a)
{
    ValueObj* pkColl = static_cast<ValueObj*>(getValue());
    bool bResult;
    if (pkColl)
        bResult = pkColl->vD0(a);
    else
        bResult = bhkShape_CanShare(a);
    return bResult;
}

extern "C"
{
    extern const char* DAT_012682d0;
}

struct StringArrayCalls_00ca5190
{
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char**);
};
struct StringBuilderCalls_00ca5190
{
    void bhkShape_GetViewerStrings(NiStringArray* array);
};

struct ValueObject_00ca5190
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
    virtual void v60(NiStringArray* array);
};

struct StringBuilder_ca5190 : public StringBuilder
{
    void bhkBvTreeShape_GetViewerStrings(NiStringArray* array);
};

// @fnv 0x00ca5190
// src: XBOX_PDB 0x00ca5190
void StringBuilder_ca5190::bhkBvTreeShape_GetViewerStrings(NiStringArray* array)
{
    ThreadStateGuard guard;
    reinterpret_cast<StringBuilderCalls_00ca5190*>(this)->bhkShape_GetViewerStrings(array);

    char* text = NiViewerStrings_NiGetViewerString_Title(DAT_012682d0);
    unsigned int count = array->count;
    if (count >= array->capacity)
    {
        reinterpret_cast<StringArrayCalls_00ca5190*>(array)->FUN_0096ad30(count + array->growth);
    }
    reinterpret_cast<StringArrayCalls_00ca5190*>(array)->FUN_0096ae90(count, &text);

    if (this != 0)
    {
        FirstInterface* m_8 = reinterpret_cast<HC1Base*>(this)->unk08;
        if (m_8 != 0)
        {
            void* link = m_8->FUN_00ca4f40_get();
            if (link != 0)
            {
                Header* header = reinterpret_cast<Header*>(reinterpret_cast<char*>(link) - 16);
                if (header != 0)
                {
                    void* value = header->value;
                    if (value != 0)
                    {
                        reinterpret_cast<ValueObject_00ca5190*>(value)->v60(array);
                    }
                }
            }
        }
    }
}
