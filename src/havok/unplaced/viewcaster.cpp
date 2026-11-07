
// src/havok/unplaced/viewcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/viewcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Inner62
{
    int bhkWorldObject_GethkWorld();
};

int __cdecl bhkWorld_Getbhk(int value);

struct FUN_00621440_cls
{
    int unk00;

    void* Modelloader_GetReferencedThis();
    int CameraCaster_GetWorld();
};

// If FUN_00559450 returns non-null, passes the result of its FUN_00c87a40 call through FUN_00621480; otherwise returns 0.
// @fnv 0x00621440
// src: XBOX_PDB 0x00621440
int FUN_00621440_cls::CameraCaster_GetWorld()
{
    int result = 0;
    if (Modelloader_GetReferencedThis())
        result = bhkWorld_Getbhk(((Inner62*)Modelloader_GetReferencedThis())->bhkWorldObject_GethkWorld());
    return result;
}

struct SpawnedObject
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
    virtual void v39(SpawnedObject* obj);
    void bhkWorld_SetDebugObjectColor(SpawnedObject* a, unsigned int b);
};

class ScopeGuard
{
  public:
    unsigned int m_unk00;
    ScopeGuard(unsigned int a, unsigned int b, const char* file, unsigned int line);
    ~ScopeGuard();
};

unsigned int __cdecl PackBytesBigEndian(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

class FUN_00631ca0_cls
{
  public:
    SpawnedObject* Modelloader_GetReferencedThis();
    void ViewCaster_Add(SpawnedObject* obj);
};

// Creates a scope guard, and if the stored object is non-null, calls v39 on it and then FUN_00c68e30 with the object and a computed value.
// @fnv 0x00631ca0
// src: XBOX_PDB 0x00631ca0
void FUN_00631ca0_cls::ViewCaster_Add(SpawnedObject* obj)
{
    ScopeGuard guard(0x10, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Havok\\ViewCaster.cpp", 0x74);
    if (this->Modelloader_GetReferencedThis() != 0)
    {
        this->Modelloader_GetReferencedThis()->v39(obj);
        if (obj != 0)
        {
            obj->bhkWorld_SetDebugObjectColor(this->Modelloader_GetReferencedThis(), PackBytesBigEndian(0x58, 0xad, 0x56, 0x19));
        }
    }
}

struct PathingCopyBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    PathingCopyBase& operator=(const PathingCopyBase& other);
};

struct PathingCopyBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00632d40_shell : PathingCopyBase
{
    int unk20;
    int unk24;
    PathingCopyBlock unk28;
    int unk48;
    int unk4C;
    PathingCopyBlock unk50;

    FUN_00632d40_shell& hkpRootCdPoint_hkpRootCdPoint(const FUN_00632d40_shell& other);
};

// Copy-assigns all members of the source object into this object and returns a reference to this.
// @fnv 0x00632d40
// src: XBOX_PDB 0x00632d40
FUN_00632d40_shell& FUN_00632d40_shell::hkpRootCdPoint_hkpRootCdPoint(const FUN_00632d40_shell& other)
{
    PathingCopyBase::operator=(other);
    unk20 = other.unk20;
    unk24 = other.unk24;
    unk28 = other.unk28;
    unk48 = other.unk48;
    unk4C = other.unk4C;
    unk50 = other.unk50;
    return *this;
}
