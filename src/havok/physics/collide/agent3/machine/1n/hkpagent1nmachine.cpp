#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/AgentSectorPointerArray.h"
#include "../../../../../../../include/hkpAgent1nSector.h"
// VC9's SDK __m128 adds byte arrays that trigger parameter shadowing under /GS.
// Retain this unit's original intrinsic layout for the matching compiler.
#if defined(_MSC_VER) && _MSC_VER == 1500 && !defined(_INCLUDED_MM2)
#define _INCLUDED_MM2
// Exe 0x00da3510 FUN_00da3510: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
#endif

#include "../../../../../../../include/hkVector4.h"

void ProcessEntryPair();
void hkAgent1nMachine_VisitAllAgents(int, int, void*);

// @fnv 0x00da48e0
// src: XBOX_PDB 0x00da48e0
void hkAgent1nMachine_UpdateShapeCollectionFilter(int b, int a)
{
    hkAgent1nMachine_VisitAllAgents(b, a, (void*)&ProcessEntryPair);
}

typedef unsigned int BlockPoolsize_t;

struct BlockPoolAllocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct BlockPoolMemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BlockPoolAllocator* m_pStreamAllocator;

    BlockPoolAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" BlockPoolMemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(BlockPoolAllocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct BlockPoolBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    int unk18;

    BlockPoolBlock()
    {
        unk00 = 0;
    }
    static void* operator new(BlockPoolsize_t, void* p) throw()
    {
        return p;
    }
};

struct BlockPoolArrayLocalForm
{ // local form of hkArrayBase: 0x00da4430 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    BlockPoolBlock** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void GrowArrayCapacity(BlockPoolAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(BlockPoolBlock*));
        }
    }

    BlockPoolBlock*& _expandOne(BlockPoolAllocator& alloc)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(BlockPoolBlock*));
        return m_data[m_iElementCount++];
    }
};

// Resets the block array, reserves room for 4 entries, allocates a 0x200-byte block and initialises its fields.
// @fnv 0x00da4430
void __cdecl InitBlockPool(BlockPoolArrayLocalForm* blocks)
{
    blocks->m_iElementCount = 0;
    blocks->GrowArrayCapacity(hkMemoryRouter_getInstance().heap(), 4);
    blocks->_expandOne(hkMemoryRouter_getInstance().heap());
    BlockPoolBlock* block = new (hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(0x200)) BlockPoolBlock();
    blocks->m_data[0] = block;
    block->unk13 = 0x10;
    block->unk10 = 1;
    block->unk18 = -1;
    block->unk14 = -1;
    block->unk00 = 0x10;
}

// hkAgentNmMachine: update the collision filter of one agent entry

struct S_00da40e0_Shape;
struct S_00da40e0_CollisionInput;
struct S_00da40e0_ContactMgr;
struct S_00da40e0_ConstraintOwner;
struct S_00da40e0_Dispatcher;

struct S_00da40e0_Bool
{
    char m_cBooleanValue;
    S_00da40e0_Bool()
    {}
    S_00da40e0_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct __declspec(align(16)) S_00da40e0_MotionState
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
    int unkAC;
};

struct S_00da40e0_CdBody
{
    const S_00da40e0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00da40e0_MotionState* m_pMotionState;
    const S_00da40e0_CdBody* m_parent;

    S_00da40e0_CdBody()
    {}
    S_00da40e0_CdBody(const S_00da40e0_CdBody* parent)
    {
        m_parent = parent;
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00da40e0_Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct __declspec(align(16)) S_00da40e0_ShapeBuffer
{
    unsigned int m_data[128];
};

struct S_00da40e0_ShapeContainer
{
    virtual ~S_00da40e0_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00da40e0_Shape* GetShapeForKey(unsigned int key, S_00da40e0_ShapeBuffer& buffer) const;
};

struct S_00da40e0_ShapeCollectionFilter
{
    virtual S_00da40e0_Bool IsCollisionEnabled(const S_00da40e0_CollisionInput& input, const S_00da40e0_CdBody& a,
                                               const S_00da40e0_CdBody& b,
                                               const S_00da40e0_ShapeContainer& containerShapeA,
                                               const S_00da40e0_ShapeContainer& containerShapeB, unsigned int keyA,
                                               unsigned int keyB) const = 0;
};

struct S_00da40e0_CollidableCollidableFilter
{
    virtual void unk0();
};

struct S_00da40e0_ShapeKeyPair
{
    unsigned int m_uiShapeKeyA;
    unsigned int m_uiShapeKeyB;
};

struct S_00da40e0_Entry
{
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
    S_00da40e0_ShapeKeyPair m_kShapeKeyPair;
};

struct S_00da40e0_AgentData;

typedef void(__cdecl* S_00da40e0_DestroyFunc)(S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData,
                                              S_00da40e0_ContactMgr* mgr, S_00da40e0_ConstraintOwner& constraintOwner,
                                              S_00da40e0_Dispatcher* dispatcher);
typedef void(__cdecl* S_00da40e0_UpdateFilterFunc)(S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData,
                                                   const S_00da40e0_CdBody& bodyA, const S_00da40e0_CdBody& bodyB,
                                                   const S_00da40e0_CollisionInput& input, S_00da40e0_ContactMgr* mgr,
                                                   S_00da40e0_ConstraintOwner& constraintOwner);

struct S_00da40e0_Agent3Funcs
{
    S_00da40e0_DestroyFunc m_pAgent3DestroyFuncs;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    S_00da40e0_UpdateFilterFunc m_pUpdateFilterFunc;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
};

struct S_00da40e0_Dispatcher
{
    int unk0;
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
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    int unkDEC;
    int unkDF0;
    int unkDF4;
    int unkDF8;
    int unkDFC;
    int unkE00;
    int unkE04;
    int unkE08;
    int unkE0C;
    int unkE10;
    int unkE14;
    int unkE18;
    int unkE1C;
    int unkE20;
    int unkE24;
    int unkE28;
    int unkE2C;
    int unkE30;
    int unkE34;
    int unkE38;
    int unkE3C;
    int unkE40;
    int unkE44;
    int unkE48;
    int unkE4C;
    int unkE50;
    int unkE54;
    int unkE58;
    int unkE5C;
    int unkE60;
    int unkE64;
    int unkE68;
    int unkE6C;
    int unkE70;
    int unkE74;
    int unkE78;
    int unkE7C;
    int unkE80;
    int unkE84;
    int unkE88;
    int unkE8C;
    int unkE90;
    int unkE94;
    int unkE98;
    int unkE9C;
    int unkEA0;
    int unkEA4;
    int unkEA8;
    int unkEAC;
    int unkEB0;
    int unkEB4;
    int unkEB8;
    int unkEBC;
    int unkEC0;
    int unkEC4;
    int unkEC8;
    int unkECC;
    int unkED0;
    int unkED4;
    int unkED8;
    int unkEDC;
    int unkEE0;
    int unkEE4;
    int unkEE8;
    int unkEEC;
    int unkEF0;
    int unkEF4;
    int unkEF8;
    int unkEFC;
    int unkF00;
    int unkF04;
    int unkF08;
    int unkF0C;
    int unkF10;
    int unkF14;
    int unkF18;
    int unkF1C;
    int unkF20;
    int unkF24;
    int unkF28;
    int unkF2C;
    int unkF30;
    int unkF34;
    int unkF38;
    int unkF3C;
    int unkF40;
    int unkF44;
    int unkF48;
    int unkF4C;
    int unkF50;
    int unkF54;
    int unkF58;
    int unkF5C;
    int unkF60;
    int unkF64;
    int unkF68;
    int unkF6C;
    int unkF70;
    int unkF74;
    int unkF78;
    int unkF7C;
    int unkF80;
    int unkF84;
    int unkF88;
    int unkF8C;
    int unkF90;
    int unkF94;
    int unkF98;
    int unkF9C;
    int unkFA0;
    int unkFA4;
    int unkFA8;
    int unkFAC;
    int unkFB0;
    int unkFB4;
    int unkFB8;
    int unkFBC;
    int unkFC0;
    int unkFC4;
    int unkFC8;
    int unkFCC;
    int unkFD0;
    int unkFD4;
    int unkFD8;
    int unkFDC;
    int unkFE0;
    int unkFE4;
    int unkFE8;
    int unkFEC;
    int unkFF0;
    int unkFF4;
    int unkFF8;
    int unkFFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    S_00da40e0_Agent3Funcs m_kAgent3FunctionTable[1];
};

struct S_00da40e0_FilterHolder;

struct S_00da40e0_CollisionInput
{
    S_00da40e0_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    S_00da40e0_FilterHolder* m_iFilter;
};

struct S_00da40e0_FilterHolder : S_00da40e0_CollidableCollidableFilter
{
    int unk04;
    int unk08;
};

struct S_00da40e0_Filter : S_00da40e0_FilterHolder, S_00da40e0_ShapeCollectionFilter
{
};

struct S_00da40e0_Input
{
    const S_00da40e0_CdBody* m_pBodyA;
    const S_00da40e0_CdBody* m_pBodyB;
    const S_00da40e0_ShapeContainer* m_containerA;
    const S_00da40e0_ShapeContainer* m_containerB;
    const S_00da40e0_CollisionInput* m_pRayCastInput;
    S_00da40e0_ContactMgr* m_pContactManager;
    S_00da40e0_ConstraintOwner* m_pConstraintOwner;
};

const S_00da40e0_CdBody* __cdecl hkAgentMachine_processTransformedShapes(const S_00da40e0_CdBody* cdBody, S_00da40e0_CdBody* newCdBodies,
                                              S_00da40e0_MotionState* newMotionStates, int numSlots,
                                              unsigned char& changeCounter);

// @fnv 0x00da40e0
S_00da40e0_Entry* __cdecl ProcessCollisionEntry(const S_00da40e0_Input& aInput, S_00da40e0_Entry* entry,
                                                S_00da40e0_AgentData* agentData)
{
    S_00da40e0_ShapeKeyPair keys = entry->m_kShapeKeyPair;
    const S_00da40e0_Filter* filter = static_cast<const S_00da40e0_Filter*>(aInput.m_pRayCastInput->m_iFilter);
    if (filter->IsCollisionEnabled(*aInput.m_pRayCastInput, *aInput.m_pBodyA, *aInput.m_pBodyB, *aInput.m_containerA,
                                   *aInput.m_containerB, keys.m_uiShapeKeyA, keys.m_uiShapeKeyB))
    {
        S_00da40e0_UpdateFilterFunc func =
            aInput.m_pRayCastInput->m_pCollisionDispatcher->m_kAgent3FunctionTable[entry->m_ucNnTrackType]
                .m_pUpdateFilterFunc;
        if (func)
        {
            S_00da40e0_ShapeBuffer shapeBufferB;
            S_00da40e0_ShapeBuffer shapeBufferA;
            const S_00da40e0_Shape* shapeB = aInput.m_containerB->GetShapeForKey(keys.m_uiShapeKeyB, shapeBufferB);
            const S_00da40e0_Shape* shapeA = aInput.m_containerA->GetShapeForKey(keys.m_uiShapeKeyA, shapeBufferA);

            S_00da40e0_CdBody bodyB(aInput.m_pBodyB);
            bodyB.SetCollisionShapeAndKey(shapeB, keys.m_uiShapeKeyB);
            S_00da40e0_CdBody bodyA(aInput.m_pBodyA);
            bodyA.SetCollisionShapeAndKey(shapeA, keys.m_uiShapeKeyA);

            const S_00da40e0_CdBody* pBodyB = &bodyB;
            const S_00da40e0_CdBody* pBodyA = &bodyA;

            S_00da40e0_CdBody newCdBodiesA[4];
            S_00da40e0_MotionState newMotionStatesA[4];
            S_00da40e0_CdBody newCdBodiesB[4];
            S_00da40e0_MotionState newMotionStatesB[4];

            if (entry->m_ucAgentType & 8)
            {
                unsigned char ucChangeCounter = 0;
                pBodyB = hkAgentMachine_processTransformedShapes(pBodyB, newCdBodiesB, newMotionStatesB, 4, ucChangeCounter);
                pBodyA = hkAgentMachine_processTransformedShapes(pBodyA, newCdBodiesA, newMotionStatesA, 4, ucChangeCounter);
            }

            unsigned char command = (unsigned char)(entry->m_ucAgentType & 7);
            if (command == 3 || command == 5)
            {
                func(entry, agentData, *pBodyB, *pBodyA, *aInput.m_pRayCastInput, aInput.m_pContactManager,
                     *aInput.m_pConstraintOwner);
            }
            else
            {
                func(entry, agentData, *pBodyA, *pBodyB, *aInput.m_pRayCastInput, aInput.m_pContactManager,
                     *aInput.m_pConstraintOwner);
            }
        }
        return (S_00da40e0_Entry*)((char*)entry + entry->m_iElementCount);
    }
    else
    {
        S_00da40e0_Dispatcher* dispatcher = aInput.m_pRayCastInput->m_pCollisionDispatcher;
        dispatcher->m_kAgent3FunctionTable[entry->m_ucNnTrackType].m_pAgent3DestroyFuncs(
            entry, agentData, aInput.m_pContactManager, *aInput.m_pConstraintOwner, dispatcher);
        return entry;
    }
}

// hkpAgent1nMachine shape-collection filter visitor (one container side): re-check the filter for
struct ShapeCollectionFilter1n
{
    virtual S_00da40e0_Bool IsCollisionEnabled(const S_00da40e0_CollisionInput& input, const S_00da40e0_CdBody& a,
                                               const S_00da40e0_CdBody& b,
                                               const S_00da40e0_ShapeContainer& containerShapeB,
                                               unsigned int keyB) const = 0;
    virtual S_00da40e0_Bool IsCollisionEnabled(const S_00da40e0_CollisionInput& input, const S_00da40e0_CdBody& a,
                                               const S_00da40e0_CdBody& b,
                                               const S_00da40e0_ShapeContainer& containerShapeA,
                                               const S_00da40e0_ShapeContainer& containerShapeB, unsigned int keyA,
                                               unsigned int keyB) const = 0;
};
struct Filter1n : S_00da40e0_FilterHolder, ShapeCollectionFilter1n
{
};

// @fnv 0x00da3f90
S_00da40e0_Entry* __cdecl ProcessEntryPair(const S_00da40e0_Input& in, S_00da40e0_Entry* entry,
                                           S_00da40e0_AgentData* agentData)
{
    S_00da40e0_ShapeKeyPair keys = entry->m_kShapeKeyPair;
    const Filter1n* filter = static_cast<const Filter1n*>(in.m_pRayCastInput->m_iFilter);
    if (filter->IsCollisionEnabled(*in.m_pRayCastInput, *in.m_pBodyA, *in.m_pBodyB, *in.m_containerB,
                                   keys.m_uiShapeKeyB))
    {
        S_00da40e0_UpdateFilterFunc updateFunc =
            in.m_pRayCastInput->m_pCollisionDispatcher->m_kAgent3FunctionTable[entry->m_ucNnTrackType]
                .m_pUpdateFilterFunc;
        if (updateFunc)
        {
            S_00da40e0_ShapeBuffer shapeBuffer;
            const S_00da40e0_Shape* childShape = in.m_containerB->GetShapeForKey(keys.m_uiShapeKeyB, shapeBuffer);
            S_00da40e0_CdBody bodyB(in.m_pBodyB);
            bodyB.SetCollisionShapeAndKey(childShape, keys.m_uiShapeKeyB);
            const S_00da40e0_CdBody* pBodyA = in.m_pBodyA;
            const S_00da40e0_CdBody* pBodyB = &bodyB;
            if (entry->m_ucAgentType & 8)
            {
                unsigned char changeCounter = 0;
                S_00da40e0_MotionState motionStates[4];
                S_00da40e0_CdBody cdBodies[4];
                pBodyB = hkAgentMachine_processTransformedShapes(pBodyB, cdBodies, motionStates, 4, changeCounter);
            }
            unsigned char command = entry->m_ucAgentType & 7;
            if (command == 3 || command == 5)
                updateFunc(entry, agentData, *pBodyB, *pBodyA, *in.m_pRayCastInput, in.m_pContactManager,
                           *in.m_pConstraintOwner);
            else
                updateFunc(entry, agentData, *pBodyA, *pBodyB, *in.m_pRayCastInput, in.m_pContactManager,
                           *in.m_pConstraintOwner);
        }
        return (S_00da40e0_Entry*)((char*)entry + entry->m_iElementCount);
    }
    in.m_pRayCastInput->m_pCollisionDispatcher->m_kAgent3FunctionTable[entry->m_ucNnTrackType].m_pAgent3DestroyFuncs(
        entry, agentData, in.m_pContactManager, *in.m_pConstraintOwner, in.m_pRayCastInput->m_pCollisionDispatcher);
    return entry;
}

extern const float DAT_01012054;

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

struct FourByteState
{
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
};

struct ByteStateWithThreeIntegers : public FourByteState
{
    int m_uiCollisionShapeKey;
    int m_unk08;
    int m_unk0C;
};

struct ByteStateWithMixedNumericData : public FourByteState
{
    int m_uiCollisionShapeKey;
    int m_unk08;
    float m_fFloatValue;
    hkVector4 m_vSeparatingNormal;
};

inline FourByteState* hkpAgent1nSector::getBegin()
{
    return (FourByteState*)(this + 1);
}

inline FourByteState* hkpAgent1nSector::GetStreamEnd()
{
    return (FourByteState*)((char*)(this + 1) + m_uiAgentCount);
}

struct CollisionAgentContext;
typedef void(__cdecl* InvalidateTimFunc)(FourByteState* entry, void* agentData, CollisionAgentContext& input);

struct CollisionAgentContext
{
    char* m_pCollisionDispatcher;
};

// Walks the agent sectors, calling each entry's dispatcher function; for types 4, 5, 12 and 13 it first sets m_fFloatValue and zeroes the separating normal.
// @fnv 0x00da3510
// src: GUESS 0x00da3510 (confidence: low)
void hkpAgent1nSector_ProcessEntries_00da3510(AgentSectorPointerArray& agentTrack, CollisionAgentContext& input)
{
    hkpAgent1nSector* sector = agentTrack.m_kSectors.m_data[0];
    FourByteState* entry = sector->getBegin();
    FourByteState* end = sector->GetStreamEnd();
    int nextSector = 1;
    while (1)
    {
        do
        {
            FourByteState* current = entry;
            switch (current->m_ucAgentType)
            {
            case 2:
            case 3:
            case 6:
            case 10:
            case 11:
            case 14: {
                void* agentData = static_cast<ByteStateWithThreeIntegers*>(entry) + 1;
                entry = (FourByteState*)((char*)entry + entry->m_iElementCount);
                InvalidateTimFunc func =
                    *(InvalidateTimFunc*)(input.m_pCollisionDispatcher + (current->m_ucNnTrackType + 0x49) * 0x50);
                if (func)
                    func(current, agentData, input);
            }
            break;
            case 4:
            case 5:
            case 12:
            case 13: {
                void* agentData = static_cast<ByteStateWithMixedNumericData*>(entry) + 1;
                ByteStateWithMixedNumericData* pMixedState = static_cast<ByteStateWithMixedNumericData*>(current);
                pMixedState->m_fFloatValue = DAT_01012054;
                pMixedState->m_vSeparatingNormal.setZero4();
                entry = (FourByteState*)((char*)entry + entry->m_iElementCount);
                InvalidateTimFunc func =
                    *(InvalidateTimFunc*)(input.m_pCollisionDispatcher + (current->m_ucNnTrackType + 0x49) * 0x50);
                if (func)
                    func(current, agentData, input);
            }
            break;
            case 0:
                entry = (FourByteState*)((char*)entry + entry->m_iElementCount);
                continue;
            case 1:
                return;
            default:
                continue;
            }
        } while (entry < end);
        sector = agentTrack.m_kSectors.m_data[nextSector++];
        entry = sector->getBegin();
        end = sector->GetStreamEnd();
    }
}

typedef void(__cdecl* Da35FuncPtr)(void* entry, void* payload, float fa, float fb, void* holder);

// Iterates through hkpAgent1nSector chunks, dispatching commands via function pointers and updating float fields based on fa and fb.
// @fnv 0x00da35f0
// src: HAVOK_LIB 0x00da35f0
void __cdecl _hkAgent1nMachine_WarpTime(hkpAgent1nSector*** container, float fa, float fb, void** holder)
{
    hkpAgent1nSector* stream = **container;
    unsigned char* p = (unsigned char*)stream + 0x10;
    unsigned char* end;
    *(unsigned char* volatile*)&end = (unsigned char*)stream + stream->m_uiAgentCount + 0x10;
    int index = 4;
    for (;;)
    {
        do
        {
            unsigned char* entry = p;
            unsigned char cmd = p[0];
            switch (cmd)
            {
            case 2:
            case 3:
            case 6:
            case 10:
            case 11:
            case 14: {
                unsigned char* payload = p + 0x10;
                unsigned char idx = entry[1];
                p += entry[3];
                Da35FuncPtr pFunc = *(Da35FuncPtr*)((char*)*holder + idx * 80 + 0x16d4);
                if (pFunc)
                    pFunc(entry, payload, fa, fb, holder);
                break;
            }
            case 4:
            case 5:
            case 12:
            case 13: {
                unsigned char* payload = p + 0x20;
                if (*(float*)(p + 0xC) == fa)
                    *(float*)(p + 0xC) = fb;
                else
                    *(float*)(p + 0xC) = -1.0f;
                unsigned char idx = entry[1];
                p += entry[3];
                Da35FuncPtr pFunc = *(Da35FuncPtr*)((char*)*holder + idx * 80 + 0x16d4);
                if (pFunc)
                    pFunc(entry, payload, fa, fb, holder);
                break;
            }
            case 0:
                p += entry[3];
                break;
            case 1:
                return;
            case 7:
            case 8:
            case 9:
                break;
            default:
                break;
            }
        } while (p < end);
        stream = *(hkpAgent1nSector**)((char*)*container + index);
        unsigned char* pNewEnd = (unsigned char*)stream + stream->m_uiAgentCount + 0x10;
        p = (unsigned char*)stream + 0x10;
        *(unsigned char* volatile*)&end = pNewEnd;
        index += 4;
    }
}

static void* __cdecl Da35Search(hkpAgent1nSector*** container, int key1, int key2, void** out)
{
    hkpAgent1nSector** streams = *container;
    hkpAgent1nSector* stream = *streams;
    int size = stream->m_uiAgentCount;
    streams += 1;
    for (;;)
    {
        unsigned char* end = (unsigned char*)stream + size + 0x10;
        unsigned char* p = (unsigned char*)stream + 0x10;
        do
        {
            unsigned char cmd = p[0];
            switch (cmd)
            {
            case 2:
            case 3:
            case 6:
            case 10:
            case 11:
            case 14: {
                unsigned char* payload = p + 0x10;
                if (*(int*)(p + 8) == key2 && *(int*)(p + 4) == key1)
                {
                    *out = payload;
                    return p;
                }
                p += p[3];
                break;
            }
            case 4:
            case 5:
            case 12:
            case 13: {
                unsigned char* payload = p + 0x20;
                if (*(int*)(p + 8) == key2 && *(int*)(p + 4) == key1)
                {
                    *out = payload;
                    return p;
                }
                p += p[3];
                break;
            }
            case 0:
                p += p[3];
                break;
            case 1:
                return 0;
            case 7:
            case 8:
            case 9:
                break;
            default:
                break;
            }
        } while (p < end);
        stream = *streams;
        size = stream->m_uiAgentCount;
        streams += 1;
    }
}

struct BlockPoolHeap : BlockPoolAllocator
{
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

__forceinline BlockPoolHeap& fullHeap()
{
    return static_cast<BlockPoolHeap&>(hkMemoryRouter_getInstance().heap());
}

// Iterates over all agent entries in the block pool, dispatches their destroy functions, then releases the blocks and resets the array.
// @fnv 0x00da42b0
// src: XBOX_PDB 0x00da42b0
void hkAgent1nMachine_Destroy(BlockPoolArrayLocalForm* blocks, S_00da40e0_Dispatcher* dispatcher, S_00da40e0_ContactMgr* mgr,
                  S_00da40e0_ConstraintOwner& owner)
{
    BlockPoolBlock** sectors = blocks->m_data;
    BlockPoolBlock* sector = sectors[0];
    unsigned char* cursor = (unsigned char*)sector + 16;
    unsigned char* end = (unsigned char*)sector + 16 + sector->unk00;
    int index = 0;
    for (;;)
    {
        S_00da40e0_Entry* entry = (S_00da40e0_Entry*)cursor;
        switch (entry->m_ucAgentType)
        {
        case 2:
        case 3:
        case 6:
        case 10:
        case 11:
        case 14: {
            S_00da40e0_AgentData* agentData = (S_00da40e0_AgentData*)(cursor + 16);
            cursor += entry->m_iElementCount;
            dispatcher->m_kAgent3FunctionTable[entry->m_ucNnTrackType].m_pAgent3DestroyFuncs(entry, agentData, mgr,
                                                                                             owner, dispatcher);
        }
        break;
        case 4:
        case 5:
        case 12:
        case 13: {
            S_00da40e0_AgentData* agentData = (S_00da40e0_AgentData*)(cursor + 32);
            cursor += entry->m_iElementCount;
            dispatcher->m_kAgent3FunctionTable[entry->m_ucNnTrackType].m_pAgent3DestroyFuncs(entry, agentData, mgr,
                                                                                             owner, dispatcher);
        }
        break;
        case 0:
            cursor += entry->m_iElementCount;
            break;
        case 1:
            goto finished;
        }
        if (cursor >= end)
        {
            {
                BlockPoolBlock* done = sectors[index++];
                if (done)
                    fullHeap().ReleaseBlock(done, 512);
            }
            sector = blocks->m_data[index];
            cursor = (unsigned char*)sector + 16;
            end = (unsigned char*)sector + 16 + sector->unk00;
        }
    }
finished: {
    BlockPoolBlock* done = sectors[index];
    if (done)
        fullHeap().ReleaseBlock(done, 512);
}
    BlockPoolHeap& heap = fullHeap();
    int flags = blocks->m_iCapacityState;
    blocks->m_iElementCount = 0;
    if ((flags & 0x80000000) == 0)
        heap.ReturnMemory(blocks->m_data, (flags & 0x3fffffff) * 4);
    blocks->m_iCapacityState = 0x80000000;
    blocks->m_data = 0;
}

#include <string.h>
struct StreamAllocator : BlockPoolAllocator
{
    virtual void ReleaseBlock(void*, int);
};
struct StreamRecord
{
    int first;
    int second;
    void* third;
    void* fourth;
};
struct StreamHeader
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
    void* g;
    void* h;
};
__forceinline static void streamCopy(void* dst, const void* src, int count)
{
    const int* s = (const int*)src;
    int* d = (int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--count > 0);
}
void __cdecl hkMemUtil_memMove(void*, const void*, unsigned int);
typedef unsigned char*(__cdecl* StreamTransform)(void*, unsigned char*, unsigned char*);
// Walks records in the BlockPoolArrayLocalForm blocks, copies them into new 512-byte blocks, applies the callback to some record types, and replaces the array contents.
// @fnv 0x00da44d0
// src: HAVOK_LIB 0x00da44d0
void hkAgent1nMachine_VisitAllAgents(int apBlocks, int apHeader, void* apTransform)
{
    BlockPoolArrayLocalForm* blocks = (BlockPoolArrayLocalForm*)apBlocks;
    int outIndex = 0;
    BlockPoolBlock* input = blocks->m_data[0];
    BlockPoolBlock* previous = 0;
    BlockPoolBlock* output = new (hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(512)) BlockPoolBlock;
    unsigned char* cursor = (unsigned char*)input + 16;
    unsigned char* out = (unsigned char*)output + 16;
    int inIndex = 1;
    unsigned char* end = (unsigned char*)input + input->unk00 + 16;
    unsigned char* limit = (unsigned char*)output + 512;
    int used = 0;
    bool staging = false;
    StreamHeader header;
    __declspec(align(16)) StreamRecord scratchStorage[8];
    unsigned char* scratch = (unsigned char*)scratchStorage;
    int staged;
process:
    streamCopy(out, cursor, cursor[3] >> 4);
    cursor += cursor[3];
    memcpy(&header, (void*)apHeader, 32);
    int offset = 16;
    switch (out[0] & 0xf7)
    {
    case 4:
    case 5:
        offset = 32;
    case 2:
    case 3:
    case 6:
        out = ((StreamTransform)apTransform)(&header, out, out + offset);
        break;
    case 1:
        out += offset;
        break;
    }
    if (cursor == end)
    {
        if (previous)
            ((StreamAllocator*)&hkMemoryRouter_getInstance().heap())->ReleaseBlock(previous, 512);
        previous = input;
        if (inIndex >= blocks->m_iElementCount)
            goto finish;
        input = blocks->m_data[inIndex];
        cursor = (unsigned char*)input + 16;
        end = (unsigned char*)input + input->unk00 + 16;
        ++inIndex;
    }
    if (out + 128 <= limit)
        goto process;
    if (!staging)
    {
        used = out - ((unsigned char*)output + 16);
        staging = true;
        out = scratch;
        limit = scratch + 128;
        goto process;
    }
    staged = out - scratch;
    if (staged <= 496 - used)
    {
        streamCopy((unsigned char*)output + 16 + used, scratch, staged >> 4);
        used += staged;
        if (used < 496)
        {
            out = scratch;
            goto process;
        }
        staging = false;
    }
    output->unk00 = used;
    if (outIndex >= inIndex)
    {
        BlockPoolAllocator& alloc = hkMemoryRouter_getInstance().heap();
        int count = inIndex;
        inIndex = blocks->m_iElementCount + 1;
        int tail = -(count - blocks->m_iElementCount);
        blocks->GrowArrayCapacity(alloc, inIndex);
        hkMemUtil_memMove(&blocks->m_data[count + 1], &blocks->m_data[count], tail * sizeof(BlockPoolBlock*));
        blocks->m_iElementCount = inIndex;
        inIndex = count + 1;
    }
    blocks->m_data[outIndex++] = output;
    if (previous)
    {
        output = previous;
        previous = 0;
    }
    else
        output = new (hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(512)) BlockPoolBlock;
    out = (unsigned char*)output + 16;
    limit = (unsigned char*)output + 512;
    if (staging)
    {
        streamCopy(out, scratch, staged >> 4);
        out += staged;
        staging = false;
    }
    goto process;
finish:
    if (!staging)
        used = out - ((unsigned char*)output + 16);
    else
    {
        int count = out - scratch;
        streamCopy((unsigned char*)output + 16 + used, scratch, count >> 4);
        used += count;
    }
    output->unk00 = used;
    int newCount = outIndex + 1;
    blocks->GrowArrayCapacity(hkMemoryRouter_getInstance().heap(), newCount);
    blocks->m_iElementCount = newCount;
    blocks->m_data[outIndex] = output;
    if (previous)
        ((StreamAllocator*)&hkMemoryRouter_getInstance().heap())->ReleaseBlock(previous, 512);
}

extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}
struct __declspec(align(16)) TOIBody
{
    LocalM128 m_pos;
    LocalM128 m_dir;
    int unk20;
};

// Computes dot products from the two bodies' position difference and directions, then returns 0, 1 or 2 from threshold comparisons.
// @fnv 0x00da37d0
// src: GUESS 0x00da37d0 (confidence: low)
static __declspec(noinline) int Hkpagent1nmachine_ComputeValues_00da37d0(const TOIBody* b, const TOIBody* a, float p0, const float* p1, float p2)
{
    LocalM128 d = _mm_sub_ps(a->m_pos, b->m_pos);
    LocalM128 m0 = _mm_mul_ps(b->m_dir, d);
    LocalM128 m1 = _mm_mul_ps(a->m_dir, d);
    LocalM128 m2 = _mm_mul_ps(a->m_dir, b->m_dir);
    LocalM128 t0 = _mm_unpacklo_ps(m0, m1);
    LocalM128 t1 = _mm_unpackhi_ps(m0, m1);
    m0 = _mm_movelh_ps(t0, m2);
    m1 = _mm_movehl_ps(m0, t0);
    m1 = _mm_shuffle_ps(m1, m2, 0xd4);
    m2 = _mm_shuffle_ps(t1, m2, 0xe4);
    LocalM128 dots = _mm_add_ps(_mm_add_ps(m0, m1), m2);
    float t4 = (dots.m128_f32[2] - 1.0f) * p0 + (-dots.m128_f32[1]);
    float t12 = dots.m128_f32[0] + (dots.m128_f32[2] - 1.0f) * p0;
    float t8 = p0 + p2;
    if (t4 > t8)
        return 0;
    if (dots.m128_f32[2] > 0.9999f && a->unk20 == 0xffff)
        return 0;
    if (a->unk20 == 0xffff && dots.m128_f32[2] < 0.8f && t4 + t12 < 0.1f)
    {
        float m = -t8 * 2;
        if (b->m_dir.m128_f32[3] + a->m_dir.m128_f32[3] < m)
            return 2;
    }
    float s = 0.0f;
    if (a->unk20 != 0xffff)
        s = *p1 * 0.05f;
    if (!(b->m_dir.m128_f32[3] <= a->m_dir.m128_f32[3] - s))
        return 1;
    return 0;
}
volatile int g_toiA;
volatile int g_toiB;
volatile float g_toiF;
volatile int g_toiP;
volatile int g_toiOut;
void CallTarget_da37d0()
{
    g_toiOut = Hkpagent1nmachine_ComputeValues_00da37d0((const TOIBody*)g_toiB, (const TOIBody*)g_toiA, g_toiF, (const float*)g_toiP, g_toiF);
}
