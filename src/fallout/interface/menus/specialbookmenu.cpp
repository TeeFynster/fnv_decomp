#include "../../../../include/BookMenu.h"
#include "../../../../include/SPECIALBookMenu.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiAdditionalGeometryData.h"
#include "../../../../include/NiControllerManager.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiPick.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/Tile.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/GO.h"
#include "../../../../include/Menu.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiUpdateData.h"

// src/fallout/interface/menus/specialbookmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/specialbookmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" bool __cdecl _FUN_004b71d0();


// Returns pageIndex + 4 when pageIndex is between 1 and 8, adding 4 more for slot 8 if _FUN_004b71d0() is true; otherwise returns -1.
// @fnv 0x007ca030
int SPECIALBookMenu::FUN_007ca030()
{
    if (this->pageIndex > 0 && this->pageIndex < 9)
    {
        if (_FUN_004b71d0())
        {
            if (this->pageIndex == 8)
                return this->selectedStat + 4;
        }
        return this->pageIndex + 4;
    }
    return -1;
}

extern "C" int __cdecl FUN_007c6110();
// NiNode.h does not declare this cleanup helper; fastcall passes the node in ECX.
void __fastcall RemoveSpecialBookSceneChildren(NiNode* node);
struct ModelLoader
{
    void FUN_0045a5e0(const char*);
};
struct GlobalObject_00633c90
{
    void* m_00;
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
extern ModelLoader* g_modelLoader;
extern SPECIALBookMenu* DAT_011daa38;
extern GlobalObject_00633c90 g_011daa9c;
Menu* __cdecl FindMenuById(int);

// @fnv 0x007c6120
void __cdecl FUN_007c6120()
{
    int i;
    Menu* menu5 = FindMenuById(FUN_007c6110());
    if (!menu5)
        return;
    g_modelLoader->FUN_0045a5e0("Meshes\\Terminals\\Babybook02.NIF");
    RemoveSpecialBookSceneChildren(NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1));
    NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)->FUN_00b5d180();
    *(int*)((char*)DAT_011daa38 + 0x5c) = 0;
    ((GO*)&g_011daa9c)->operator=(0);
    i = 0;
    for (; i < 9; ++i)
    {
        ((GlobalObject_00869f00*)((char*)DAT_011daa38 + i * 32 + 0x60))->Clear(true);
        ((GlobalObject_00869f00*)((char*)DAT_011daa38 + i * 32 + 0x70))->Clear(true);
    }
    if (DAT_011daa38)
    {
        ((Tile*)menu5)->Set(0x1772, 1);
        ((Menu*)DAT_011daa38)->LoadMenuData();
    }
}


// Returns selectedStat + 4 when pageIndex is 8 and _FUN_004b71d0() is true, pageIndex + 4 when pageIndex is between 1 and 7, otherwise -1.
// @fnv 0x00794d30
int SPECIALBookMenu::FUN_00794d30()
{
    if (pageIndex == 8)
    {
        if (_FUN_004b71d0())
            return selectedStat + 4;
    }
    if (pageIndex > 0 && pageIndex < 8)
        return pageIndex + 4;
    return -1;
}


struct FUN_007ca080
{
    int m_00;
    int m_04;
    NiPointer<NiAVObject> m_pController;
    void* m_0c;
    FUN_007ca080(int a, int b, const char* name);
};

// @fnv 0x007ca080
FUN_007ca080::FUN_007ca080(int aiValueA, int aiValueB, const char* name) : m_pController(0)
{
    m_00 = aiValueA;
    m_04 = aiValueB;
    m_pController = DAT_011daa38->pRoot->GetObjectByName(NiFixedString(name));
    NiAVObject* pAnimIdle = DAT_011daa38->pRoot->GetObjectByName(NiFixedString(name));
    m_0c = (!((NiAVObject*)pAnimIdle)->GetProperty(3)
                ? 0
                : (((NiTimeController*)((NiAVObject*)pAnimIdle)->GetProperty(3))->FUN_00441110() >= 8 &&
                   ((NiTimeController*)((NiAVObject*)pAnimIdle)->GetProperty(3))->FUN_00441110() <= 12))
               ? ((NiAVObject*)pAnimIdle)->GetProperty(3)
               : 0;
}


// @fnv 0x007c6c50
bool SPECIALBookMenu::HandleInput(int aiKey)
{
    bool bhandled = false;

    if (aiKey == 0x80000001 || aiKey == 0x80000002)
    {
        HandleSelection(aiKey == 0x80000001, 0);
        bhandled = true;
    }

    if (aiKey == 0x80000003 || aiKey == 0x80000004)
    {
        HandleMenuInput((aiKey != 0x80000003) + 3, 1.0f);
        bhandled = true;
    }

    return bhandled;
}

struct MenuInput
{
    int FUN_00a24180(int, int);
};
struct MenuOS
{
    MenuInput* FUN_00877720();
};
struct MenuLocale
{
    const char* FUN_00403df0();
};
struct MenuTime
{
    float FUN_0084d030();
};
extern MenuOS* g_osGlobals;
extern MenuLocale g_011c3cb4;
extern MenuTime g_timeGlobal;
extern bool DAT_011a0854;
extern const char* DAT_011a0858[];
extern const char* DAT_011a0878[];
extern int DAT_011f36bc;
bool __cdecl FUN_00702450(int);
int __cdecl FUN_00408b20(const char*, const char*);
NiTimeController* __cdecl FUN_00653270(const int*, NiTimeController*);
// Checks a key press to trigger Handle(4,0), otherwise advances the scene's controller sequence by elapsed time and updates the scene.
// @fnv 0x007c6200
void SPECIALBookMenu::FUN_007c6200()
{
    if (!FUN_00702450(0x424))
        return;
    MenuInput* pInput = g_osGlobals->FUN_00877720();
    {
        NiTimeController* pController;
        {
            int scanCode = 30;
            if (FUN_00408b20(g_011c3cb4.FUN_00403df0(), "FRENCH") == 0)
                scanCode = 16;
            if (pInput->FUN_00a24180(scanCode, 1))
            {
                HandleSelection(4, 0);
                return;
            }
            pController = scene->GetControllers();
            if (pController)
            {
                NiTimeController* manager = pController;
                NiControllerSequence* sequence = 0;
                if (!DAT_011a0854 || pageIndex > 0)
                    sequence = manager->FUN_0047a520(
                        NiFixedString(DAT_011a0854 ? DAT_011a0878[pageIndex] : DAT_011a0858[pageIndex]));
                elapsed += g_timeGlobal.FUN_0084d030();
                if (sequence)
                {
                    sequence->Update(elapsed, true);
                    if (sequence->FUN_00508120() < sequence->FUN_00508100() && pageIndex > 0)
                        finished = false;
                    else
                        finished = true;
                }
                else
                {
                    finished = true;
                }
                for (; pController; pController = pController->GetNext())
                {
                    NiTimeController* castController = FUN_00653270(&DAT_011f36bc, pController);
                    if (castController)
                    {
                        NiUpdateData updateData(elapsed, false, false);
                        pController->Update(updateData);
                        break;
                    }
                }
            }
            NiUpdateData updateData(0.0f, false, false);
            scene->Update(updateData);
        }
    }
}

bool __cdecl FUN_00702450(unsigned int);
struct Values6440
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetValue(int);
};
struct Player6440
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
    int limit;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    Values6440 values;
};
extern Player6440* g_thePlayer;
// @fnv 0x007c6440
bool SPECIALBookMenu::HandleSpecialBookKey(unsigned int key, int unused)
{
    if (FUN_00702450(0x424))
    {
        int index = FUN_007ca030();
        switch (key)
        {
        case 4:
        case 10:
            if (index != -1 && g_thePlayer->values.GetValue(index) > 1)
                HandleSelection(3, 0);
            return true;
        case 3:
        case 9:
            if (index != -1 && FUN_00794d80() < limit && g_thePlayer->values.GetValue(index) < 10)
                HandleSelection(2, 0);
            return true;
        }
    }
    return false;
}

class C7CA200NavMesh;

class C7CA200Base
{
  public:
    C7CA200Base(int iArg1, int iArg2, int iArg3);
    ~C7CA200Base();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class C7CA200NavMeshArray
{
  public:
    C7CA200NavMeshArray();
    ~C7CA200NavMeshArray();

    unsigned int Add(C7CA200NavMesh*& rpkNavMesh);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_007ca200 : public C7CA200Base
{
  public:
    FUN_007ca200(int iArg1, int iArg2, int iArg3, int iArg4, int iNumNavMeshes, ...);

    C7CA200NavMeshArray m_kNavMeshes;
    int m_iArg4;
};

// Initializes the base with three arguments, stores iArg4, and adds iNumNavMeshes nav mesh pointers from the variadic argument list to m_kNavMeshes.
// @fnv 0x007ca200
FUN_007ca200::FUN_007ca200(int iArg1, int iArg2, int iArg3, int iArg4, int iNumNavMeshes, ...)
    : C7CA200Base(iArg1, iArg2, iArg3)
{
    m_iArg4 = iArg4;

    char* pcArgs = (char*)&iNumNavMeshes + sizeof(iNumNavMeshes);
    for (int i = 0; i < iNumNavMeshes; i++)
        m_kNavMeshes.Add(*(C7CA200NavMesh**)((pcArgs += sizeof(C7CA200NavMesh*)) - sizeof(C7CA200NavMesh*)));
    pcArgs = 0;
}

struct FUN_007ca2c0
{
    int m_00;
    NiTimeController* m_04;
    NiTimeController* m_08;
    NiAVObject* m_0c;
    NiAVObject* m_10;
    int m_14;
    FUN_007ca2c0(int a, const char* first, const char* second, int d);
};
// Stores the given ints, looks up two named objects under the scene root, and caches each object's property 3 controller when its value is between 8 and 12.
// @fnv 0x007ca2c0
FUN_007ca2c0::FUN_007ca2c0(int a, const char* apFirstName, const char* apSecondName, int d)
{
    m_00 = a;
    m_14 = d;
    m_0c = (NiAVObject*)DAT_011daa38->pRoot->GetObjectByName(NiFixedString(apFirstName));
    m_04 = (!m_0c->GetProperty(3) ? 0
                                  : (((NiTimeController*)m_0c->GetProperty(3))->FUN_00441110() >= 8 &&
                                     ((NiTimeController*)m_0c->GetProperty(3))->FUN_00441110() <= 12))
               ? (NiTimeController*)m_0c->GetProperty(3)
               : 0;
    if (apSecondName)
    {
        m_10 = (NiAVObject*)DAT_011daa38->pRoot->GetObjectByName(NiFixedString(apSecondName));
        m_08 = (!m_10->GetProperty(3) ? 0
                                      : (((NiTimeController*)m_10->GetProperty(3))->FUN_00441110() >= 8 &&
                                         ((NiTimeController*)m_10->GetProperty(3))->FUN_00441110() <= 12))
                   ? (NiTimeController*)m_10->GetProperty(3)
                   : 0;
    }
}

// Candidate for FUN_007cadd0 (FNV decompilation, official checker)

// __thiscall, no stack args (caller pops 0). /Od /Oy- /GS /EHsc.

// Based on an unverified GLM (Z.ai) / zai_glm_01 draft, round 4.

struct G_011dea10_cls
{

    void FUN_004568c0(char* a, int* b, int c, int d);
};

extern G_011dea10_cls* g_011dea10;

void __cdecl FUN_00406d00(char* dst, int size, const char* a, const char* b, const char* c, ...);

void __cdecl FUN_00406d30(char* dst, int n, const char* src);

void __cdecl FUN_004b7240(char* src, char* dst, int n);

bool __cdecl FUN_00709d40();

extern const char str_01074c4c[];

extern const char str_01076cc0[];

extern const char str_01074c6c[];

extern const char str_01076ca4[];

extern const char str_01074c40[];

extern const char str_0101fd1c[];

extern const char str_0101fd24[];

extern const char str_01074c38[];

extern const char str_01074c24[];

extern const char str_01074c08[];

extern const char str_01074c1c[];

extern const char str_01074c14[];

extern const char str_01074c00[];

extern const char str_01074bf8[];

extern const char str_01074be8[];

extern const char str_01074bd8[];

extern const char str_01074bc8[];

extern const char str_01074bb8[];

extern const char str_01076c94[];


// @fnv 0x007cadd0
void SPECIALBookMenu::FUN_007cadd0()

{

    int iStack_228;

    int auStack_110;

    char iStack_224[8];

    char auStack_220[264];

    char auStack_218[264];

    for (auStack_110 = 0; auStack_110 < 0xb; auStack_110++)
    {

        FUN_00406d00(auStack_220, 0x104, str_01074c4c, str_01076cc0, str_01074c6c, auStack_110);

        FUN_004b7240(auStack_220, auStack_218, 0x104);

        g_011dea10->FUN_004568c0(auStack_218, &m180[auStack_110], 0, 0);
    }

    for (iStack_228 = 1; iStack_228 < 5; iStack_228++)
    {

        FUN_00406d00(auStack_220, 0x104, str_01074c4c, str_01076ca4, str_01074c40, iStack_228);

        FUN_004b7240(auStack_220, auStack_218, 0x104);

        g_011dea10->FUN_004568c0(auStack_218, &m1a8[iStack_228], 0, 0);
    }

    if (FUN_00709d40())

        FUN_00406d30(iStack_224, 5, str_0101fd1c);

    else

        FUN_00406d30(iStack_224, 5, str_0101fd24);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074c38);

    g_011dea10->FUN_004568c0(auStack_218, &m1c0, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074c24);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1bc, 0, 0);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074c1c);

    g_011dea10->FUN_004568c0(auStack_218, &m1c4, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074c14);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1c8, 0, 0);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074c00);

    g_011dea10->FUN_004568c0(auStack_218, &m1cc, 0, 0);

    FUN_00406d00(auStack_218, 0x104, str_01076c94, str_01076cc0, iStack_224, str_01074bf8);

    g_011dea10->FUN_004568c0(auStack_218, &m1d0, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074be8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1d4, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074bd8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1d8, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074bc8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1dc, 0, 0);

    FUN_00406d00(auStack_220, 0x104, str_01074c08, str_01076cc0, str_01074bb8);

    FUN_004b7240(auStack_220, auStack_218, 0x104);

    g_011dea10->FUN_004568c0(auStack_218, &m1e0, 0, 0);
}

extern NiRTTI DAT_011f36ac;


extern SPECIALBookMenu* g_sceneHolder_7c9dc0;


void __fastcall SetNegatedGlobal(void* p);

extern bool DAT_011a0854;
extern const char* DAT_011a0858[8];
extern const char* DAT_011a0878[8];


// @fnv 0x007c9dc0
bool SPECIALBookMenu::FUN_007c9dc0(bool forward)
{
    bool turned = false;
    if (forward)
    {
        DAT_011a0854 = true;
        if (pageIndex < 9)
        {
            pageIndex++;
            turned = true;
            BSSoundHandle sound;
            sound = reinterpret_cast<const BSSoundHandle&>(BSAudio::GetSingleton()->FUN_00ad7550("OBJBookSpecialPageTurn", 0x121));
            sound.Play(false);
        }
        else
        {
            return false;
        }
    }
    else
    {
        DAT_011a0854 = false;
        if (pageIndex >= 1)
        {
            pageIndex--;
            turned = true;
            BSSoundHandle sound;
            sound = reinterpret_cast<const BSSoundHandle&>(BSAudio::GetSingleton()->FUN_00ad7550("OBJBookSpecialPageTurn", 0x121));
            sound.Play(false);
        }
        else
        {
            return false;
        }
    }
    if (turned)
    {
        NiControllerManager* found = (NiControllerManager*)g_sceneHolder_7c9dc0->pRoot->GetController(&DAT_011f36ac);
        if (found)
        {
            NiControllerManager* manager = found;
            NiControllerSequence* sequence = 0;
            if (!DAT_011a0854 || pageIndex > 0)
            {
                sequence = manager->FindSequenceByName(
                    NiFixedString(DAT_011a0854 ? DAT_011a0878[pageIndex] : DAT_011a0858[pageIndex]));
            }
            if (sequence)
            {
                manager->FUN_0048fef0(0.0f);
                manager->ActivateControllerSequence(sequence, 0, true, 1.0f, 0.0f, 0);
                manager->FUN_0047aa40(true);
                SetNegatedGlobal(sequence);
            }
        }
    }
    return true;
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern "C" void* __cdecl FormHeap_Allocate(unsigned int size);

void __cdecl CallVfunc60WithGlobalOffset(void* p);
void __cdecl FUN_007cabb0(void* p);
void __cdecl FUN_007ca8a0(void* p);
void __cdecl FUN_007cabf0(void* p);
void __cdecl DispatchSourceCallback(void* p);
void __cdecl FUN_007cac30(void* p);
void __cdecl UpdateEntryRankText(void* p);
void __cdecl DispatchStateCallback(void* p);
void __cdecl UpdateLodVisibility(void* p);
void __cdecl FUN_007ca700(void* p);
void __cdecl FUN_007ca960(void* p);
void __cdecl FUN_007ca7a0(void* p);
void __cdecl PlaySpecialBookSoundAndSetStat(void* p);

typedef void(__cdecl* ItemCb)(void* p);

struct BkPoint3
{
    float x, y, z;
    BkPoint3* Init(float ax, int ay, int az);
};
struct BkColor
{
    float r, g, b;
    BkColor(float ar, float ag, float ab);
};
struct BkTimer
{
    float FUN_0084d030();
};
struct BkLight
{
    char pad[0xfc];
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    BkLight();
    void FUN_00440460(const BkColor& c);
    void SetEffectColor(const BkColor& c);
    void FUN_0050dd50(const BkColor& c);
    void FUN_0050dd20(float f);
    void FUN_00a59c60(const BkPoint3& p);
};
struct BkScene
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void HandleSelection();
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
    virtual void HandleMenuInput();
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
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(void* child, int firstAvail);
    void* FUN_00b5ca70(NiNode* node, float radius);
    void FUN_00b5c940(BkLight* l, int a);
};
struct BkLoader
{
    NiNode* LoadModel(const char* path, int a, int b, int c, int d, int e);
};

struct BkItemBase
{
    static void* operator new(unsigned int size);
    static void operator delete(void*);
};
struct BkButton : BkItemBase
{
    ItemCb m_cb0;
    ItemCb m_cb4;
    int unk08;
    int unk0C;
    int unk10;
    BkButton(ItemCb a, ItemCb b, const char* name);
};
struct BkStepButton : BkButton
{
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    BkStepButton(ItemCb a, ItemCb b, const char* name, int stat, int count, ...);
};
struct BkDisplay : BkItemBase
{
    ItemCb m_cb;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    BkDisplay(ItemCb cb, const char* name, const char* name2, int stat);
};

extern BkLoader* DAT_011c3b3c;
extern BkTimer DAT_011f6394;
void __cdecl FUN_004b7660(NiNode* node);
void __cdecl FUN_00a6d2d0(NiNode* node);
void* __cdecl FUN_00653270(void* rtti, NiTimeController* obj);
BkScene* __cdecl FUN_00450b80(int a);


// Loads the Babybook02.NIF scene, sets up its transform and animation, then creates and registers the displays and buttons for all nine menu groups.
// @fnv 0x007c6ce0
void SPECIALBookMenu::InitMenu()
{
    BkDisplay* pDigits;
    BkPoint3 pos;
    float aScale;
    BkStepButton* declA;
    BkStepButton* pIncrease;
    BkButton* next;
    BkButton* pLeft;
    void* found;
    NiTimeController* aPCtrl;
    BkPoint3 akStart;
    BkDisplay* valueX;
    BkDisplay* kMsg;

    DAT_011daa38->m_pReferencedNode =
        DAT_011c3b3c->LoadModel("Meshes\\Terminals\\Babybook02.NIF", 0, 1, 0, 0, 0);
    FUN_004b7660(DAT_011daa38->m_pReferencedNode);
    DAT_011daa38->m_pReferencedNode->FUN_00440490(0.05f);
    DAT_011daa38->m_pReferencedNode->FUN_004bc1f0(0.0f, 0.0f, -60.0f);
    DAT_011daa38->m_pReferencedNode->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
    akStart.Init(0.0f, 0, 0);
    DAT_011daa38->m_pReferencedNode->Update((NiUpdateData&)akStart);
    DAT_011daa38->m_fTime += DAT_011f6394.FUN_0084d030();
    aPCtrl = DAT_011daa38->m_pReferencedNode->GetController(&DAT_011f36ac);
    if (aPCtrl)
    {
        NiControllerManager* mgr5 = (NiControllerManager*)aPCtrl;
        NiControllerSequence* pForwardSequence = mgr5->FUN_0047a520(NiFixedString("Forward"));
        if (pForwardSequence)
        {
            mgr5->FUN_0048fef0(0.0f);
            mgr5->FUN_0047aab0(pForwardSequence, 0, 1, 1.0f, 0.0f, 0);
            mgr5->FUN_0047aa40(true);
            SetNegatedGlobal(pForwardSequence);
        }
    }
    FUN_00a6d2d0(m_pReferencedNode);
    for (; aPCtrl; aPCtrl = aPCtrl->GetNext())
    {
        void* pMatch = FUN_00653270(&DAT_011f36bc, aPCtrl);
        if (pMatch)
        {
            BkPoint3 pT4;
            pT4.Init(0.0f, 0, 0);
            aPCtrl->Update((NiUpdateData&)pT4);
            break;
        }
    }
    pos.Init(0.0f, 0, 0);
    m_pReferencedNode->Update((NiUpdateData&)pos);
    aScale = DAT_011daa38->m_pReferencedNode->FUN_0043d450()->FUN_0084d030() * 20.0;
    found = FUN_00450b80(1)->FUN_00b5ca70(DAT_011daa38->m_pReferencedNode->IsSceneNode(), aScale);
    if (found == 0)
    {
        BkLight* apTargetLight = new BkLight();
        apTargetLight->FUN_00440460(BkColor(0.0f, 0.0f, 0.0f));
        apTargetLight->SetEffectColor(BkColor(0.85f, 0.85f, 0.85f));
        apTargetLight->FUN_0050dd50(BkColor(aScale, 0.0f, 0.0f));
        apTargetLight->FUN_0050dd20(1.0f);
        BkPoint3 kLightPos;
        kLightPos.Init(0.0f, 0, 0);
        apTargetLight->FUN_00a59c60(kLightPos);
        FUN_00450b80(1)->AttachChildInAvailableSlot(apTargetLight, 1);
        FUN_00450b80(1)->FUN_00b5c940(apTargetLight, 0);
    }
    FUN_00450b80(1)->AttachChildInAvailableSlot(DAT_011daa38->m_pReferencedNode, 1);

    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "LookInside_Btn:0");
    m_groups[0].buttons.FUN_007cb2e0(next);

    valueX = new BkDisplay(UpdateEntryRankText, "P1_PointVal:0", 0, 5);
    kMsg = new BkDisplay(DispatchStateCallback, "P1_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P1_PointsRemainDigit1:0", "P1_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P1_Decrease_Btn:0", 5, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P1_Increase_Btn:0", 5, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P1_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P1_LT_Btn:0");
    m_groups[1].displays.FUN_007cb2e0(valueX);
    m_groups[1].displays.FUN_007cb2e0(kMsg);
    m_groups[1].displays.FUN_007cb2e0(pDigits);
    m_groups[1].buttons.FUN_007cb2e0(declA);
    m_groups[1].buttons.FUN_007cb2e0(pIncrease);
    m_groups[1].buttons.FUN_007cb2e0(next);
    m_groups[1].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P2_PointVal:0", 0, 6);
    kMsg = new BkDisplay(DispatchStateCallback, "P2_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P2_PointsRemainDigit1:0", "P2_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P2_Decrease_Btn:0", 6, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P2_Increase_Btn:0", 6, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P2_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P2_LT_Btn:0");
    m_groups[2].displays.FUN_007cb2e0(valueX);
    m_groups[2].displays.FUN_007cb2e0(kMsg);
    m_groups[2].displays.FUN_007cb2e0(pDigits);
    m_groups[2].buttons.FUN_007cb2e0(declA);
    m_groups[2].buttons.FUN_007cb2e0(pIncrease);
    m_groups[2].buttons.FUN_007cb2e0(next);
    m_groups[2].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P3_PointVal:0", 0, 7);
    kMsg = new BkDisplay(DispatchStateCallback, "P3_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P3_PointsRemainDigit1:0", "P3_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P3_Decrease_Btn:0", 7, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P3_Increase_Btn:0", 7, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P3_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P3_LT_Btn:0");
    m_groups[3].displays.FUN_007cb2e0(valueX);
    m_groups[3].displays.FUN_007cb2e0(kMsg);
    m_groups[3].displays.FUN_007cb2e0(pDigits);
    m_groups[3].buttons.FUN_007cb2e0(declA);
    m_groups[3].buttons.FUN_007cb2e0(pIncrease);
    m_groups[3].buttons.FUN_007cb2e0(next);
    m_groups[3].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P4_PointVal:0", 0, 8);
    kMsg = new BkDisplay(DispatchStateCallback, "P4_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P4_PointsRemainDigit1:0", "P4_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P4_Decrease_Btn:0", 8, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P4_Increase_Btn:0", 8, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P4_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P4_LT_Btn:0");
    m_groups[4].displays.FUN_007cb2e0(valueX);
    m_groups[4].displays.FUN_007cb2e0(kMsg);
    m_groups[4].displays.FUN_007cb2e0(pDigits);
    m_groups[4].buttons.FUN_007cb2e0(declA);
    m_groups[4].buttons.FUN_007cb2e0(pIncrease);
    m_groups[4].buttons.FUN_007cb2e0(next);
    m_groups[4].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P5_PointVal:0", 0, 9);
    kMsg = new BkDisplay(DispatchStateCallback, "P5_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P5_PointsRemainDigit1:0", "P5_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P5_Decrease_Btn:0", 9, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P5_Increase_Btn:0", 9, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P5_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P5_LT_Btn:0");
    m_groups[5].displays.FUN_007cb2e0(valueX);
    m_groups[5].displays.FUN_007cb2e0(kMsg);
    m_groups[5].displays.FUN_007cb2e0(pDigits);
    m_groups[5].buttons.FUN_007cb2e0(declA);
    m_groups[5].buttons.FUN_007cb2e0(pIncrease);
    m_groups[5].buttons.FUN_007cb2e0(next);
    m_groups[5].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P6_PointVal:0", 0, 10);
    kMsg = new BkDisplay(DispatchStateCallback, "P6_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P6_PointsRemainDigit1:0", "P6_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P6_Decrease_Btn:0", 10, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P6_Increase_Btn:0", 10, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P6_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P6_LT_Btn:0");
    m_groups[6].displays.FUN_007cb2e0(valueX);
    m_groups[6].displays.FUN_007cb2e0(kMsg);
    m_groups[6].displays.FUN_007cb2e0(pDigits);
    m_groups[6].buttons.FUN_007cb2e0(declA);
    m_groups[6].buttons.FUN_007cb2e0(pIncrease);
    m_groups[6].buttons.FUN_007cb2e0(next);
    m_groups[6].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "P7_PointVal:0", 0, 11);
    kMsg = new BkDisplay(DispatchStateCallback, "P7_Message:0", 0, -1);
    pDigits = new BkDisplay(UpdateLodVisibility, "P7_PointsRemainDigit1:0", "P7_PointsRemainDigit2:0", -1);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "P7_Decrease_Btn:0", 11, 2, valueX, pDigits);
    pIncrease =
        new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "P7_Increase_Btn:0", 11, 2, valueX, pDigits);
    next = new BkButton(FUN_007cabb0, CallVfunc60WithGlobalOffset, "P7_RT_Btn:0");
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "P7_LT_Btn:0");
    m_groups[7].displays.FUN_007cb2e0(valueX);
    m_groups[7].displays.FUN_007cb2e0(kMsg);
    m_groups[7].displays.FUN_007cb2e0(pDigits);
    m_groups[7].buttons.FUN_007cb2e0(declA);
    m_groups[7].buttons.FUN_007cb2e0(pIncrease);
    m_groups[7].buttons.FUN_007cb2e0(next);
    m_groups[7].buttons.FUN_007cb2e0(pLeft);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_StrengthPointVal:0", 0, 5);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_StrengthDecrease_Btn:0", 5, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_StrengthIncrease_Btn:0", 5, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_PerceptionPointVal:0", 0, 6);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_PerceptionDecrease_Btn:0", 6, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_PerceptionIncrease_Btn:0", 6, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_EndurancePointVal:0", 0, 7);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_EnduranceDecrease_Btn:0", 7, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_EnduranceIncrease_Btn:0", 7, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_CharismaPointVal:0", 0, 8);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_CharismaDecrease_Btn:0", 8, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_CharismaIncrease_Btn:0", 8, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_IntelligencePointVal:0", 0, 9);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_IntelligenceDecrease_Btn:0", 9, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_IntelligenceIncrease_Btn:0", 9, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_AgilityPointVal:0", 0, 10);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_AgilityDecrease_Btn:0", 10, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_AgilityIncrease_Btn:0", 10, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    valueX = new BkDisplay(UpdateEntryRankText, "Index_LuckPointVal:0", 0, 11);
    m_groups[8].displays.FUN_007cb2e0(valueX);
    declA = new BkStepButton(FUN_007ca960, FUN_007ca700, "Index_LuckDecrease_Btn:0", 11, 2, valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(declA);
    pIncrease = new BkStepButton(PlaySpecialBookSoundAndSetStat, FUN_007ca7a0, "Index_LuckIncrease_Btn:0", 11, 2,
                                 valueX, pDigits);
    m_groups[8].buttons.FUN_007cb2e0(pIncrease);

    kMsg = new BkDisplay(DispatchStateCallback, (char*)"Index_Message:0", 0, -1);
    m_groups[8].displays.FUN_007cb2e0(kMsg);
    pDigits = new BkDisplay(UpdateLodVisibility, (char*)"Index_PointsRemainDigit1:0", "Index_PointsRemainDigit2:0", -1);
    m_groups[8].displays.FUN_007cb2e0(pDigits);
    next = new BkButton(FUN_007cac30, DispatchSourceCallback, "AllDone_Btn:0");
    m_groups[8].buttons.FUN_007cb2e0(next);
    pLeft = new BkButton(FUN_007cabf0, FUN_007ca8a0, "Index_LT_Btn:0");
    m_groups[8].buttons.FUN_007cb2e0(pLeft);

    FUN_007cadd0();
    for (int iGroup = 0; iGroup < 9; iGroup++)
    {
        for (unsigned int iItem = 0; iItem < m_groups[iGroup].displays.FUN_0044ddc0(); iItem++)
        {
            m_groups[iGroup].displays.FUN_006a7ad0(iItem)->m_cb(m_groups[iGroup].displays.FUN_006a7ad0(iItem));
        }
        for (unsigned int iButton = 0; iButton < m_groups[iGroup].buttons.FUN_0044ddc0(); iButton++)
        {
            m_groups[iGroup].buttons.FUN_006a7ad0(iButton)->m_cb4(m_groups[iGroup].buttons.FUN_006a7ad0(iButton));
        }
    }
}

int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);

struct StatValues
{
    virtual int GetValue(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int GetBaseValue(int);
};
struct BookPlayer
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
    int limit;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    StatValues values;
    void FUN_0093a7c0(int stat, int value);
};
struct RawBookPtr
{
    void* FUN_00559450();
};
struct BookButton
{
    void(__cdecl* activate)(BookButton*);
    void(__cdecl* other)(BookButton*);
    RawBookPtr object;
    int unk0c;
    int unk10;
};
struct BookInterface
{
    float FUN_009a9350();
    float FUN_00792760();
};
BookInterface* __cdecl FUN_004b7210();
struct RenderBuffer
{
    unsigned int FUN_0084e3a0();
};
struct BookRenderer
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
    virtual void HandleMenuInput();
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
    virtual RenderBuffer* GetBuffer();
};
BookRenderer* __cdecl FUN_0043c4b0();
extern bool DAT_011f9426;
extern float DAT_011ad84c;
extern float DAT_011ad848;
struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
};
class PickRecord
{
public:
    void* FUN_00968670();
};
struct BookScene
{
    void MapScreenToRay(int, int, FUN_006815c0*, FUN_006815c0*, int);
};

// Dispatches key values to page, stat, callback, and button handling; key 4 calls FUN_007c6120 when page index equals limit.
// @fnv 0x007c6550
void SPECIALBookMenu::HandleKey(unsigned int key, int unused)
{
    bool turned = false;
    switch (key)
    {
    case 4:
        if (FUN_00794d80() == limit)
            FUN_007c6120();
        else
            reinterpret_cast<BSSoundHandle&>(BSAudio::GetSingleton()->FUN_00ad7550("UIActivateNothing", 0x121)).Play(false);
        break;
    case 0:
    case 1:
        if (finished)
        {
            if (key == 0)
                turned = FUN_007c9dc0(true);
            else
                turned = FUN_007c9dc0(false);
            InvokeCallbacksForSlot();
        }
        break;
    case 2:
    case 3: {
        int oldValue9 = 0;
        int newValue = 0;
        if (FUN_007ca030() != -1)
        {
            oldValue9 = ((BookPlayer*)g_thePlayer)->values.GetBaseValue(FUN_007ca030());
            if (key == 2)
            {
                if (FUN_00794d80() < limit)
                    ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(FUN_007ca030(), MinInt(oldValue9 + 1, 10));
            }
            else
            {
                ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(FUN_007ca030(), FUN_00647b70(oldValue9 - 1, 1));
            }
            newValue = ((BookPlayer*)g_thePlayer)->values.GetValue(FUN_007ca030());
        }
        else if (_FUN_004b71d0() && pageIndex == 8)
        {
            int stat = selectedStat + 4;
            oldValue9 = ((BookPlayer*)g_thePlayer)->values.GetBaseValue(stat);
            if (key == 2)
            {
                if (FUN_00794d80() < limit)
                    ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(stat, MinInt(oldValue9 + 1, 10));
            }
            else
            {
                ((BookPlayer*)g_thePlayer)->FUN_0093a7c0(stat, FUN_00647b70(oldValue9 - 1, 1));
            }
            newValue = ((BookPlayer*)g_thePlayer)->values.GetValue(stat);
        }
        if (oldValue9 != newValue)
        {
            BSSoundHandle sound;
            sound = reinterpret_cast<const BSSoundHandle&>(BSAudio::GetSingleton()->FUN_00ad7550("OBJBookSpecialNumber", 0x121));
            sound.Play(false);
        }
        InvokeCallbacksForSlot();
        break;
    }
    case 5:
        if (pageIndex < 9)
        {
            BookInterface* interfaceManager3 = FUN_004b7210();
            int mouseX = (int)interfaceManager3->FUN_009a9350();
            int mouseY = (int)interfaceManager3->FUN_00792760();
            if (DAT_011f9426)
                mouseY = (int)(mouseY * (DAT_011ad848 - DAT_011ad84c) +
                               FUN_0043c4b0()->GetBuffer()->FUN_0084e3a0() * DAT_011ad84c);
            for (unsigned int i = 0; i < groups[pageIndex].buttons.FUN_0044ddc0(); i++)
            {
                FUN_006815c0 origin20;
                FUN_006815c0 direction1;
                NiPick pick(0, 8);
                pick.SetByteAtOffset17(1);
                pick.FUN_00705fc0(groups[pageIndex].buttons.FUN_006a7ad0(i)->object.FUN_00559450());
                pick.FUN_006ecd40(0);
                pick.SetByteAtOffset30(1);
                ((BookScene*)((RawBookPtr*)&g_011daa9c)->FUN_00559450())
                    ->MapScreenToRay(mouseX, mouseY, &origin20, &direction1, 0);
                if (pick.FUN_00e98e20((const NiPoint3&)origin20, (const NiPoint3&)direction1, 0))
                {
                    unsigned int resultIndex = 0;
                    void* hit = pick.FUN_00500940(resultIndex)->FUN_00968670();
                    if (hit)
                    {
                        groups[pageIndex].buttons.FUN_006a7ad0(i)->activate(groups[pageIndex].buttons.FUN_006a7ad0(i));
                        break;
                    }
                }
            }
        }
        break;
    case 6:
        if (pageIndex == 8 && selectedStat > 1)
        {
            selectedStat--;
            reinterpret_cast<BSSoundHandle&>(BSAudio::GetSingleton()->FUN_00ad7550("OBJBookSpecialFocus", 0x121)).Play(false);
        }
        InvokeCallbacksForSlot();
        break;
    case 7:
        if (pageIndex == 8 && selectedStat < 7)
        {
            selectedStat++;
            reinterpret_cast<BSSoundHandle&>(BSAudio::GetSingleton()->FUN_00ad7550("OBJBookSpecialFocus", 0x121)).Play(false);
        }
        InvokeCallbacksForSlot();
        break;
    }
}
