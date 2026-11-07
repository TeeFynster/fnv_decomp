
// src/bsshader/speedtreebillboardshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/speedtreebillboardshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010b8330;
void __fastcall FUN_00b67380(void*);
void __cdecl operator delete(void*, unsigned int);

struct FUN_00ba8690
{
    void* m_p;
    FUN_00ba8690(int flags);
};

// @fnv 0x00ba8690
FUN_00ba8690::FUN_00ba8690(int flags)
{
    m_p = (void*)&DAT_010b8330;
    FUN_00b67380(this);
    if (flags & 1)
        operator delete((void*)this, 0x104);
}

struct S_00ba8630_Base
{
    int unk4;
    int unk8;
    int unkC;
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
    int unk4C;
    int unk50;
    int unk54;
    S_00ba8630_Base();
    virtual ~S_00ba8630_Base();
};

struct FUN_00ba8630 : S_00ba8630_Base
{
    int unk58;
    FUN_00ba8630();
    virtual ~FUN_00ba8630();
};

// Initializes the object: sets unk58 to 1 and unk1C to 0xb.
// @fnv 0x00ba8630
FUN_00ba8630::FUN_00ba8630() : unk58(1)
{
    unk1C = 0xb;
}

extern int DAT_0120043c;

// @fnv 0x00ba8680
// src: COMMUNITY 0x00ba8680
int* __cdecl SpeedTreeBillboardShaderProperty_GetRTTI()
{
    return &DAT_0120043c;
}

void __stdcall BSShaderPPLightingProperty_IsEqual(void* apValue);

// @fnv 0x00ba8670
// src: COMMUNITY 0x00ba8670
bool __stdcall SpeedTreeBillboardShaderProperty_IsEqual(void* apValue)
{
    BSShaderPPLightingProperty_IsEqual(apValue);
    return false;
}

struct ACS00bac
{
    void* m_p;
};

struct A5A040Cls
{
    void UpdateProperties();
};

struct BA86C0Owner
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int* unkAC;

    int SpeedTreeBillboardShaderProperty_ClarifyShader(A5A040Cls* pArg, int arg2, int arg3);
};

// Calls FUN_00a5a040 when pArg+0x9c is null and clears unk58 when *unkAC is zero, then returns 0.
// @fnv 0x00ba86c0
// src: XBOX_PDB 0x00ba86c0
int BA86C0Owner::SpeedTreeBillboardShaderProperty_ClarifyShader(A5A040Cls* pArg, int arg2, int arg3)
{
    if ((char*)pArg + 0x9c == 0)
        pArg->UpdateProperties();
    if (*unkAC == 0)
        unk58 = 0;
    return 0;
}

extern int DAT_010b8330;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl operator delete(void*, unsigned int);

struct SpawnedBase
{
    virtual ~SpawnedBase();
    SpawnedBase();
};

struct SpawnedObject : SpawnedBase
{
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
    SpawnedObject()
    {
        unk58 = 1;
        unk1C = 0xb;
    }
};

struct SpawnerHost
{
    void Lighting30ShaderProperty_CopyMembers(SpawnedObject* obj, int flags);
    int* CreateSpawnedObject(int a1);
};

// Allocates a SpawnedObject, passes it with a1 to FUN_00b665d0, and returns the object as an int pointer.
// @fnv 0x00ba86f0
int* SpawnerHost::CreateSpawnedObject(int aiFlags)
{
    SpawnedObject* p = new SpawnedObject();
    this->Lighting30ShaderProperty_CopyMembers(p, aiFlags);
    return (int*)p;
}

extern int DAT_0120043c;
void __stdcall BSShaderPPLightingProperty_GetViewerStrings(void* p);
void* __cdecl NiViewerStrings_NiGetViewerString_Title(int v);

struct ObjHdr
{
    int unk0;
    int unk4;
    unsigned short unk8;
    unsigned short unkA;
    unsigned short unkC;
    unsigned short unkE;
    void FUN_0096ad30(int v);
    void FUN_0096ae90(unsigned int count, void** out);
};

// @fnv 0x00ba8780
// src: COMMUNITY 0x00ba8780
void __stdcall SpeedTreeBillboardShaderProperty_GetViewerStrings(ObjHdr* apObj)
{
    ObjHdr* pObj = apObj;
    BSShaderPPLightingProperty_GetViewerStrings(pObj);
    void* pValue = NiViewerStrings_NiGetViewerString_Title(DAT_0120043c);
    unsigned int count = pObj->unkA;
    if (count >= pObj->unk8)
    {
        pObj->FUN_0096ad30((int)(pObj->unkE + count));
    }
    pObj->FUN_0096ae90(count, &pValue);
}

struct S_00b68ed0_Stream;
struct S_00b68ed0_Obj
{
    void ReadFromStream(S_00b68ed0_Stream*);
};
struct FUN_00ba8660_S
{
    void _BSShaderPPLightingProperty_SaveBinary(S_00b68ed0_Stream*);
};
// @fnv 0x00ba8660
// src: COMMUNITY 0x00ba8660
void FUN_00ba8660_S::_BSShaderPPLightingProperty_SaveBinary(S_00b68ed0_Stream* p)
{
    ((S_00b68ed0_Obj*)this)->ReadFromStream(p);
}
