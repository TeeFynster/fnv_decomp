// ActorDeletionQueue_magicprojectile: local type (was include/ActorDeletionQueue.h, which had no evidence of one real class); its methods are 0x0096d450 ProcessLists::AddReference, 0x0096d470 ProcessLists::RemoveReference, 0x0096d490 ProcessLists::GetSystemTimeClock
// PathfindQueueStorage_magicprojectile: local type (was include/PathfindQueueStorage.h, which had no evidence of one real class); its methods are 0x0096aaf0 ProcessArray::RemoveActor
class MobileObject;

class PathfindQueueStorage_magicprojectile
{
public:
    void ProcessArray_RemoveActor_0096aaf0(MobileObject* apObject, int aeLevel);
};

class MobileObject;
class ActorSV;
struct ReferenceView;

class ActorDeletionQueue_magicprojectile
{
public:
    unsigned int pad;
    PathfindQueueStorage_magicprojectile storage;
    unsigned char unk05[3];

    void ProcessLists_RemoveReference(MobileObject*, int);
    void ProcessLists_RemoveReference(ActorSV*, int);
    void ProcessLists_RemoveReference(ReferenceView*, int);
    float ProcessLists_GetSystemTimeClock();
    void ProcessLists_AddReference(MobileObject*, int, bool, bool, bool);
    void ProcessLists_AddReference(ActorSV*, int, bool, bool, ActorSV*);
};
#include "../../../include/MagicProjectile.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/HighProcess.h"
#include "../../../include/MagicItem.h"
#include "../../../include/MobileObject.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiPoint3.h"

extern ActorDeletionQueue_magicprojectile DAT_011e0e80;

// src/fallout/magic/magicprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0081aa80_shell
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    FUN_0081aa80_shell* ComputeValue_0081aa80(void* a, void* b, void* c);
};

// Stores the three arguments into the object's fields and returns this.
// @fnv 0x0081aa80
// src: GUESS 0x0081aa80 (confidence: low)
FUN_0081aa80_shell* FUN_0081aa80_shell::ComputeValue_0081aa80(void* pFirst, void* pSecond, void* pThird)
{
    m_kPointA = pFirst;
    m_kPointB = pSecond;
    m_iThirdValue = pThird;
    return this;
}

struct Call741e0
{
    void FUN_00c741e0(int a);
};
extern int DAT_010795b8;
extern int DAT_010795d4;
extern int DAT_010795e4;
struct FUN_00806eb0
{
    FUN_00806eb0(int a1, int a2);
};
// Calls FUN_00c741e0 with a1, installs three vtable pointers at offsets 0x0, 0x3E0 and 0x410, and stores a2 at offset 0x650.
// @fnv 0x00806eb0
FUN_00806eb0::FUN_00806eb0(int aiArg, int aiValue)
{
    ((Call741e0*)this)->FUN_00c741e0(aiArg);
    *(void**)this = (void*)&DAT_010795e4;
    *(void**)((char*)this + 0x3E0) = (void*)&DAT_010795d4;
    *(void**)((char*)this + 0x410) = (void*)&DAT_010795b8;
    *(int*)((char*)this + 0x650) = aiValue;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct MobileSaveRecord
{
    unsigned int MobileObject_GetSaveSize(unsigned int);
};

// Computes a save record size: adds the result of FUN_00931ff0(a) plus 12, and 4 more each when the save version is at least 0x48 and 0x64.
// @fnv 0x0081e830
unsigned short MagicProjectile::GetSaveRecordSize(unsigned int a)
{
    unsigned short usSize = 0;
    usSize += (unsigned short)reinterpret_cast<MobileSaveRecord*>(this)->MobileObject_GetSaveSize(a);
    usSize += 4;
    usSize += 4;
    usSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x48)
        usSize += 4;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x64)
        usSize += 4;
    return usSize;
}

struct PC7d
{
    void TESForm_SaveGameDataOLD(unsigned int, int);
};
struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(int, int);
};
struct FUN_00932070_shell
{
    void SaveProcess(unsigned int);
};
// The shared MagicItem header does not yet declare its ID accessor.
unsigned int __fastcall GetMagicItemID(MagicItem* item);

// @fnv 0x0081e8c0
// src: XBOX_PDB 0x0081e8c0
void MagicProjectile::SaveGame_0081e8c0(unsigned int aiFlags)
{
    reinterpret_cast<FUN_00932070_shell*>(this)->SaveProcess(aiFlags);
    unsigned int icasterID = m_magicCaster->GetCasterHandle();
    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&icasterID), 4);
    unsigned int ispellID = GetMagicItemID(m_magicItem);
    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<int>(&ispellID), 4);
    reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
        reinterpret_cast<unsigned int>(&unkA4), 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x48)
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(&unk90), 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x64)
        reinterpret_cast<PC7d*>(this)->TESForm_SaveGameDataOLD(
            reinterpret_cast<unsigned int>(&unk8C), 4);
}

struct STR00
{
    void TESForm_LoadGameDataOLD(void*, unsigned int);
};
struct FUN_00484d40_Host
{
    void TESForm_LoadNumericID(unsigned int*, int);
};

struct MobileLoadRecord
{
    void SetProcessLevel(unsigned int, unsigned int);
};

// @fnv 0x0081e980
// src: XBOX_PDB 0x0081e980
void __thiscall MagicProjectile::LoadGame_0081e980(unsigned int a, unsigned int b)
{
    reinterpret_cast<MobileLoadRecord*>(this)->SetProcessLevel(a, b);
    unsigned int icasterID;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&icasterID, 4);
    m_magicCaster = reinterpret_cast<MagicCaster*>(icasterID);
    unsigned int ispellID;
    ((FUN_00484d40_Host*)this)->TESForm_LoadNumericID(&ispellID, 4);
    m_magicItem = reinterpret_cast<MagicItem*>(ispellID);
    ((STR00*)this)->TESForm_LoadGameDataOLD(&unkA4, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x48)
        ((STR00*)this)->TESForm_LoadGameDataOLD(&unk90, 4);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x64)
        ((STR00*)this)->TESForm_LoadGameDataOLD(&unk8C, 4);
}

struct Form
{
    virtual void FUN_00800000() = 0;
    virtual Form* FUN_00800004() = 0;
};

// Exe 0x0081a960: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct MagicprojectileOffset08View
{
    unsigned int GetFlags();
};

struct FUN_0081aa80
{
    Form* m_pForm;
    unsigned int m_uiCurrentValue;
    FUN_0081aa80* m_pNext;

    FUN_0081aa80(Form* pForm, unsigned int value, FUN_0081aa80* pNext);
};

struct S3c60
{
    unsigned char m_auiShapeKeys[0xc8];
    FUN_0081aa80* m_pEntries;

    int GetArchetype();
    bool AddAudioFormEntry(Form* pForm, MagicprojectileOffset08View* pAudio);
};

unsigned int __fastcall _ref_0084e3a0(MagicprojectileOffset08View* pAudio);
void* __cdecl operator new(unsigned int);

// @fnv 0x0081a960
bool S3c60::AddAudioFormEntry(Form* pForm, MagicprojectileOffset08View* pAudio)
{
    if (!pForm || !pAudio)
        return false;

    if (pAudio->GetFlags() != GetArchetype())
        return true;

    Form* form = pForm->FUN_00800004();
    unsigned int value = _ref_0084e3a0(pAudio);

    FUN_0081aa80* node = m_pEntries;
    while (node)
    {
        if (node->m_pForm == form && node->m_uiCurrentValue == value)
            return false;
        node = node->m_pNext;
    }

    FUN_0081aa80* pNewEntry = new FUN_0081aa80(form, value, m_pEntries);
    m_pEntries = pNewEntry;
    return true;
}

struct Calendar;

struct AreaDisplayObject
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual Calendar* v039(const NiFixedString&);
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058(AreaDisplayObject*);
};

struct Calendar : public AreaDisplayObject
{
    Calendar* GetDaysPassed();
};

Calendar* AreaDisplayObject::v039(const NiFixedString&)
{
    return 0;
}

void AreaDisplayObject::v058(AreaDisplayObject*)
{}

// Gets the "MagicAreaDisplay" child node and, if its GetDaysPassed() returns a node, passes the child to that node's v058.
// @fnv 0x0081e730
// src: COMMUNITY 0x0081e730
void MagicProjectile::KillAreaEffectGeometry()
{
    AreaDisplayObject* pAreaDisplay = GetNiNode() ? reinterpret_cast<AreaDisplayObject*>(GetNiNode())->v039(NiFixedString("MagicAreaDisplay")) : 0;

    if (pAreaDisplay)
    {
        if (static_cast<Calendar*>(pAreaDisplay)->GetDaysPassed())
        {
            static_cast<Calendar*>(pAreaDisplay)->GetDaysPassed()->v058(pAreaDisplay);
        }
    }
}

namespace fnv_0081ea40 {

struct SaveManager
{
    void AddFormToList(MagicProjectile*);
};

extern SaveManager* DAT_011de45c;

}  // namespace fnv_0081ea40

// @fnv 0x0081ea40
void MagicProjectile::ResolveMagicReferences(unsigned int aiFlags, unsigned int aiOldFlags)
{
    using namespace fnv_0081ea40;
    unsigned int ispellID;
    unsigned int icasterID;

    icasterID = reinterpret_cast<unsigned int>(m_magicCaster);
    m_magicCaster = MagicCaster::GetCasterByHandle(icasterID);

    ispellID = reinterpret_cast<unsigned int>(m_magicItem);
    m_magicItem = MagicItem::GetMagicItemByID(ispellID);

    m_effectItem = m_magicItem->FindCostliestEffectItem(2, 0);
    m_avEffect = m_magicItem->GetEffectSettingForRange(MagicSystem::SELF);

    this->GenerateNiNode(false);

    reinterpret_cast<MobileObject*>(this)->SetProcessFlags(aiFlags, aiOldFlags);

    DAT_011e0e80.ProcessLists_RemoveReference(reinterpret_cast<MobileObject*>(this),
                       static_cast<int>(reinterpret_cast<MobileObject*>(this)->GetCurrentProcessLevel()));

    DAT_011e0e80.ProcessLists_AddReference(reinterpret_cast<MobileObject*>(this),
                       static_cast<int>(reinterpret_cast<MobileObject*>(this)->GetCurrentProcessLevel()), false, false,
                       0);

    if (!m_magicCaster || !m_magicItem)
        DAT_011de45c->AddFormToList(this);
}

struct EventData
{
    bool HasDetrimentalEffect();
    bool HasNonDetrimentalEffect();
};
struct Event
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int GetType();
    int id;
    int state;
    EventData data;
};
struct Handler
{
    virtual void Handle4(void*, bool);
    virtual void Handle10(void*, bool);
    virtual void v2();
    virtual void v3();
    virtual void Handle1(void*, int, bool);
    virtual void v5();
    virtual void v6();
    virtual void HandleYes();
    virtual void HandleNo();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int HasError();
    virtual void v14();
    virtual void v15();
    virtual void SetEvent(Event*);
    virtual void v17();
    virtual void SetValue(int);
    void FUN_00818af0(int, const char*);
    bool MagicCaster_CastSpell(Event*, int, bool);
};
extern char DAT_0107acc8[];
extern char DAT_0107acac[];
extern char DAT_01183140[];
extern char DAT_01183060[];
extern "C" void* __cdecl FUN_00ec43fb(Event*, int, const char*, const char*, int);
// Checks evt->data, dispatches by evt->GetType() to Handle4/Handle1/Handle10, else logs errors and calls SetEvent/SetValue then HandleYes or HandleNo.
// @fnv 0x00815480
// src: XBOX_PDB 0x00815480
bool Handler::MagicCaster_CastSpell(Event* pEvent, int value, bool flag)
{
    if (pEvent->data.HasDetrimentalEffect())
    {
        FUN_00818af0(5, DAT_0107acc8);
        return false;
    }
    switch (pEvent->GetType())
    {
    case 4:
        Handle4(FUN_00ec43fb(pEvent, 0, DAT_01183140, DAT_01183060, 0), flag);
        return true;
        break;
    case 1:
        Handle1(FUN_00ec43fb(pEvent, 0, DAT_01183140, DAT_01183060, 0), value, flag);
        return true;
        break;
    case 10:
        Handle10(FUN_00ec43fb(pEvent, 0, DAT_01183140, DAT_01183060, 0), flag);
        return true;
    }
    if (HasError())
    {
        FUN_00818af0(6, DAT_0107acac);
        return false;
    }
    SetEvent(pEvent);
    SetValue(value);
    if (pEvent->data.HasNonDetrimentalEffect() && value)
    {
        HandleYes();
    }
    else
    {
        HandleNo();
    }
    return true;
}

// The shared MagicProjectile sound member adds destructor cleanup to this constructor.
// Retain the original constructor layout until the shared definition supports it.
struct FUN_0081dbb0 : MobileObject
{
    float unk88, unk8c, unk90;
    int unk94, unk98, unk9c, unka0;
    FUN_0081dbb0();
};

// Initializes the object, zeroes its float and int fields, allocates a HighProcess, and calls FUN_00575690 with the result of FUN_007af430.
// @fnv 0x0081dbb0
FUN_0081dbb0::FUN_0081dbb0()
{
    FUN_0046a010(true);
    unk90 = 0.0f;
    unk94 = 0;
    unk98 = 0;
    unk9c = 0;
    unka0 = 0;
    unk88 = 0.0f;
    unk8c = 0.0f;
    m_pBaseProcess = new HighProcess;
    TESObjectREFR_SetObjectReference(BGSSaveFormBuffer_GetForm());
}

struct MarkerErrorSub
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006(const char* name);
};

struct MarkerErrorObj
{
    unsigned char unk00[0x3c];
    MarkerErrorSub m_sub;
    unsigned char unk40[0xdc - 0x40];

    MarkerErrorObj();
};

struct MarkerErrorMgr
{
    void FUN_004603b0(MarkerErrorObj* pObj);
};

extern MarkerErrorObj* DAT_011dc774;
extern MarkerErrorMgr* DAT_011c3f2c;

// Creates the marker_error.nif object on first call, registers it with DAT_011c3f2c, and returns the cached DAT_011dc774 instance.
// @fnv 0x0081e310
MarkerErrorObj* __cdecl GetMarkerErrorObj()
{
    if (DAT_011dc774 == 0)
    {
        MarkerErrorObj* pObj = new MarkerErrorObj();
        pObj->m_sub.v006("marker_error.nif");
        DAT_011dc774 = pObj;
        DAT_011c3f2c->FUN_004603b0(DAT_011dc774);
    }
    return DAT_011dc774;
}

struct MADName
{
    char* m_kHandle;
    MADName(const char* pcString);
    ~MADName();
};
#include "../../../include/NiMemObject.h"
struct FUN_00a75650 : NiMemObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48;
    FUN_00a75650();
    void FUN_004534f0(const float* pColor);
    void NiMaterialProperty_SetEmittance(const NiPoint3& kPoint);
};
struct MADNode;
struct MADObject
{
    virtual void v00(), v01(), v02();
    virtual MADNode* IsSceneNode();
    virtual void v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(),
        v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38();
    virtual MADObject* GetObjectByName(const MADName& kName);
    float GetFloatAt64();
    void AssignFixedString(const MADName& kName);
    void NiAVObject_SetTranslate(const void* pData);
    void NiAVObject_AttachProperty(FUN_00a75650* pProperty);
};
struct MADNode : MADObject
{
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52(), v53(),
        v54();
    virtual void AttachChildInAvailableSlot(MADObject* pChild, bool abFirstAvailableSlot);
    void UpdateProperties();
};
struct MADCount
{
    int FUN_00404420();
};
struct MADSetting
{
    float* Setting_Float_00403e20();
};
extern MADSetting DAT_011d15e0;
extern const char DAT_011f426c[];
extern const float DAT_011a9b7c[];
struct MADHandle
{
    void* m_pObject;
    MADHandle& operator=(const MADHandle& kOther);
};
MADObject* __cdecl BSTestObjects_CreateSphere(float fRadius, int iSlices, int iStacks, int iUnk);
void __cdecl GetLayerColor(void* pObject, const NiPoint3& kPoint);
struct MagicAreaOwner
{
    virtual void v000(), v001(), v002(), v003(), v004(), v005(), v006(), v007(), v008(), v009();
    virtual void v010(), v011(), v012(), v013(), v014(), v015(), v016(), v017(), v018(), v019();
    virtual void v020(), v021(), v022(), v023(), v024(), v025(), v026(), v027(), v028(), v029();
    virtual void v030(), v031(), v032(), v033(), v034(), v035(), v036(), v037(), v038(), v039();
    virtual void v040(), v041(), v042(), v043(), v044(), v045(), v046(), v047(), v048(), v049();
    virtual void v050(), v051(), v052(), v053(), v054(), v055(), v056(), v057(), v058(), v059();
    virtual void v060(), v061(), v062(), v063(), v064(), v065(), v066(), v067(), v068(), v069();
    virtual void v070(), v071(), v072(), v073(), v074(), v075(), v076(), v077(), v078(), v079();
    virtual void v080(), v081(), v082(), v083(), v084(), v085(), v086(), v087(), v088(), v089();
    virtual void v090(), v091(), v092(), v093(), v094(), v095(), v096(), v097(), v098(), v099();
    virtual void v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109();
    virtual void v110(), v111(), v112(), v113(), v114(), v115();
    virtual MADObject* Get3D();
    MADCount* CombatController_GetCombatState();
    MADHandle FUN_00931ed0();
    void CreateMagicAreaDisplay();
};
// Builds a sphere node named "MagicAreaDisplay" sized from the magic area count and setting, applies a material, and attaches it to the 3D root's node.
// @fnv 0x0081aab0
void MagicAreaOwner::CreateMagicAreaDisplay()
{
    MADObject* pRoot = Get3D();
    if (!pRoot || pRoot->GetObjectByName(MADName("MagicAreaDisplay")))
    {
        return;
    }
    MADNode* pNode2 = pRoot->IsSceneNode();
    if (pNode2)
    {
        float fRadius3 = CombatController_GetCombatState()->FUN_00404420() * *DAT_011d15e0.Setting_Float_00403e20() / pRoot->GetFloatAt64();
        MADObject* pDisplaySphere = BSTestObjects_CreateSphere(fRadius3, 10, 10, 0);
        pDisplaySphere->AssignFixedString(MADName("MagicAreaDisplay"));
        pDisplaySphere->NiAVObject_SetTranslate(DAT_011f426c);
        NiPoint3 kZero_(0.0f, 0.0f, 0.0f);
        GetLayerColor(FUN_00931ed0().m_pObject, kZero_);
        FUN_00a75650* pMaterial = new FUN_00a75650;
        pMaterial->FUN_004534f0(DAT_011a9b7c);
        pMaterial->FUN_004534f0(DAT_011a9b7c);
        pMaterial->NiMaterialProperty_SetEmittance(kZero_);
        pDisplaySphere->NiAVObject_AttachProperty(pMaterial);
        pNode2->AttachChildInAvailableSlot(pDisplaySphere, true);
        pNode2->UpdateProperties();
    }
}


// Exe 0x0081df60: unit-local Interface view; declarations and layout are preserved.
struct MagicprojectileInterfaceView
{
    float FUN_007014e0(int);
};
extern MagicprojectileInterfaceView* DAT_011d8804;

extern const double DAT_01012060;
extern const double DAT_010290d0;

// Computes clamped delta time from the global clock, accumulates it into unk90, and calls Update when the interface check passes.
// @fnv 0x0081df60
void MagicProjectile::Process(int param_1)
{
    float dt3;
    float time = DAT_011e0e80.ProcessLists_GetSystemTimeClock();
    dt3 = time - reinterpret_cast<float*>(this)[0xA4 / sizeof(float)];

    if (reinterpret_cast<float*>(this)[0xA4 / sizeof(float)] > time || reinterpret_cast<float*>(this)[0xA4 / sizeof(float)] < 0.0)
    {
        dt3 = 0.0f;
        if (time > 0.0 && time < 0.30000001192092896)
        {
            dt3 = time;
        }
    }

    reinterpret_cast<float*>(this)[0xA4 / sizeof(float)] = time;
    if (DAT_011d8804->FUN_007014e0(1) > 0.0)
        return;
    reinterpret_cast<float*>(this)[0x90 / sizeof(float)] += dt3;
    Update(dt3);
}

namespace fnv_0081e040 {

struct S86a0
{
    int FUN_004086a0();
};

void* __cdecl operator new(unsigned int size);

struct FUN_0080f810
{
    unsigned char m_data[0xc4];

    FUN_0080f810(void* a, int b, GameTimerRecord* c, unsigned int d, NiPoint3 e, NiPoint3 f, unsigned int g, unsigned int h);
};

struct FUN_00811980
{
    unsigned char m_data[0xd8];

    FUN_00811980(void* a, int b, GameTimerRecord* c, unsigned int d, NiPoint3 e, NiPoint3 f);
};

struct FUN_00819360
{
    unsigned char m_data[0xd0];

    FUN_00819360(void* a, int b, GameTimerRecord* c, unsigned int d, NiPoint3 e, NiPoint3 f, unsigned int g, unsigned int h);
};

struct FUN_00822920
{
    unsigned char m_data[0xa8];

    FUN_00822920(void* a, int b, GameTimerRecord* c, unsigned int d, NiPoint3 e, NiPoint3 f);
};

FUN_0080f810::FUN_0080f810(void*, int, GameTimerRecord*, unsigned int, NiPoint3, NiPoint3, unsigned int, unsigned int)
{}

FUN_00811980::FUN_00811980(void*, int, GameTimerRecord*, unsigned int, NiPoint3, NiPoint3)
{}

FUN_00819360::FUN_00819360(void*, int, GameTimerRecord*, unsigned int, NiPoint3, NiPoint3, unsigned int, unsigned int)
{}

FUN_00822920::FUN_00822920(void*, int, GameTimerRecord*, unsigned int, NiPoint3, NiPoint3)
{}

// Constructs one of four class instances based on projectile->FUN_004086a0() and passes it to DAT_011e0e80.
// @fnv 0x0081e040
// src: XBOX_PDB 0x0081e040
void __cdecl MagicProjectile_Launch(void* a, unsigned int b, unsigned int c, int d, GameTimerRecord* timer, S86a0* projectile,
                          NiPoint3 first, NiPoint3 second)
{
    void* result = 0;
    unsigned int currentTime;

    currentTime = projectile ? (unsigned int)projectile : timer->GetTime();

    switch (projectile->FUN_004086a0())
    {
    case 0:
        result = new FUN_0080f810(a, d, timer, currentTime, first, second, b, c);
        break;

    case 1:
        result = new FUN_00811980(a, d, timer, currentTime, first, second);
        break;

    case 3:
        result = new FUN_00819360(a, d, timer, currentTime, first, second, b, c);
        break;

    case 2:
        result = new FUN_00822920(a, d, timer, currentTime, first, second);
        break;
    }

    if (result)
        DAT_011e0e80.ProcessLists_AddReference(static_cast<MobileObject*>(result), 0, 0, 0, 0);
}
}  // namespace fnv_0081e040
