#include "../../../include/FleePackage.h"
#include "../../../include/Actor.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/Script.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TESPackage.h"
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/PathingAvoidNode.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/BGSLoadFormBuffer.h"

// src/fallout/ai/fleepackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/fleepackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern PlayerCharacter* g_thePlayer;
struct BSSimpleListTESRaceSize
{
    int GetSize();
    PlayerCharacter** _ref_006815c0();
};

// Returns true if the list at offset 0x98 has one entry that is the player and FUN_00953c50 fails; otherwise false.
// @fnv 0x009f1990
// src: COMMUNITY 0x009f1990
bool FleePackage::ShouldShutDown()
{
    if (((BSSimpleListTESRaceSize*)((char*)&AvoidedRefList))->GetSize() == 1)
    {
        bool flag = false;
        {
            PlayerCharacter* item = *((BSSimpleListTESRaceSize*)((char*)&AvoidedRefList))->_ref_006815c0();
            if (item == g_thePlayer)
            {
                if (!g_thePlayer->PlayerCharacter_IsPlayerCharacterInCombat(&flag))
                    return true;
            }
        }
    }
    return false;
}

// Adds apRef to AvoidedRefList if it is not already present.
// @fnv 0x009f1310
// src: XBOX_PDB 0x009f1310
void FleePackage::AddAvoidedRef(TESObjectREFR* apRef)
{
    if (!AvoidedRefList.IsInList(apRef))
        AvoidedRefList.AddHead(apRef);
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

#include "../../../include/PACKAGE_PROCEDURE_TYPE.h"
#include "../../../include/PackageTargetRecord.h"
#include "../../../include/TESSaveLoadGame.h"


class LocationDescriptor
{
  public:
    char pad[0xc];
    LocationDescriptor();
    ~LocationDescriptor();
    void PackageLocation_SetLocReference(TESObjectREFR*);
};

struct TESObjectREFR_Flags
{
    void SetFlags(unsigned int);
};

struct FUN_009f9250 : public TESPackage
{
    float m_fPackageValue;
    int iUnk84;
    int iUnk88;
    int iUnk8c;
    int iUnk90;
    int iUnk94;
    int iUnk98;
    FUN_009f9250(TESObjectREFR* apRef, int a2, int a3, int a4);
    virtual ~FUN_009f9250();
};

// Initializes the package fields, sets reach/complete flags and procedure type, and configures the target from apRef.
// @fnv 0x009f9250
FUN_009f9250::FUN_009f9250(TESObjectREFR* apRef, int aiUnk88, int aiUnk8c, int aiUnk94)
{
    m_fPackageValue = 0.0f;
    iUnk84 = 0;
    iUnk88 = aiUnk88;
    iUnk8c = aiUnk8c;
    SetPackageType(0x17);
    SetMustReachLocation(true);
    SetMustComplete(true);
    PackageTargetRecord* pTarget;
    LocationDescriptor* ploc;
    ploc = new LocationDescriptor;
    ploc->PackageLocation_SetLocReference(apRef);
    SetPackageLocation(ploc);
    delete ploc;
    pTarget = new PackageTargetRecord;
    SetPackageTarget(pTarget);
    delete pTarget;
    SetProcedureType((PACKAGE_PROCEDURE_TYPE)0x14);
    GetTarget()->SetTargetKind(0);
    GetTarget()->SetTargetObjectReference(apRef);
    ((TESObjectREFR_Flags*)GetTarget())->SetFlags(0x80);
    iUnk90 = -1;
    iUnk94 = aiUnk94;
    iUnk98 = 0;
}

struct PTHelper
{
    TESObjectREFR* GetReferenceTarget();
    void SetTargetObjectReference(TESObjectREFR*);
};
struct BSSimpleList_TESObjectREFR_Helper
{
    bool FUN_008256d0();
    TESObjectREFR** _ref_006815c0();
    void Remove(TESObjectREFR*&);
};

// @fnv 0x009f1350
void FleePackage::RemoveRef(TESObjectREFR* apRef)
{
    ((BSSimpleList_TESObjectREFR_Helper*)((char*)&AvoidedRefList))->Remove(apRef);
    TESObjectREFR* pref = 0;
    if (((Script*)this)->GetData())
        pref = ((PTHelper*)((Script*)this)->GetData())->GetReferenceTarget();
    if (pref && pref == apRef)
    {
        if (!((BSSimpleList_TESObjectREFR_Helper*)((char*)&AvoidedRefList))->FUN_008256d0())
        {
            ((PTHelper*)((Script*)this)->GetData())
                ->SetTargetObjectReference(*(((BSSimpleList_TESObjectREFR_Helper*)((char*)&AvoidedRefList))->_ref_006815c0()));
            ((LocationDescriptor*)((Script*)this)->GetText())
                ->PackageLocation_SetLocReference(*(((BSSimpleList_TESObjectREFR_Helper*)((char*)&AvoidedRefList))->_ref_006815c0()));
        }
        else
        {
            ((PTHelper*)((Script*)this)->GetData())->SetTargetObjectReference(0);
            ((LocationDescriptor*)((Script*)this)->GetText())->PackageLocation_SetLocReference(0);
        }
    }
    if (apRef == pRefA4)
        pRefA4 = 0;
}

extern const float runtimeFloatSettingDefault132;
extern int DAT_011f2f10;
extern TESObjectREFR* DAT_011f2f1c;

extern bool __cdecl CanActorReachReference(TESObjectREFR*, long);

struct TESObjectREFR_GetRefPersists
{
    bool GetReferencePersistence();
};

extern TESDataHandler* g_dataHandler;

struct FUN_009f1140_VirtualTarget
{
    virtual int M000()
    {
        return 0;
    }
    virtual int M001()
    {
        return 0;
    }
    virtual int M002()
    {
        return 0;
    }
    virtual int M003()
    {
        return 0;
    }
    virtual int M004()
    {
        return 0;
    }
    virtual int M005()
    {
        return 0;
    }
    virtual int M006()
    {
        return 0;
    }
    virtual int M007()
    {
        return 0;
    }
    virtual int M008()
    {
        return 0;
    }
    virtual int M009()
    {
        return 0;
    }
    virtual int M010()
    {
        return 0;
    }
    virtual int M011()
    {
        return 0;
    }
    virtual int M012()
    {
        return 0;
    }
    virtual int M013()
    {
        return 0;
    }
    virtual int M014()
    {
        return 0;
    }
    virtual int M015()
    {
        return 0;
    }
    virtual int M016()
    {
        return 0;
    }
    virtual int M017()
    {
        return 0;
    }
    virtual int M018()
    {
        return 0;
    }
    virtual int M019()
    {
        return 0;
    }
    virtual int M020()
    {
        return 0;
    }
    virtual int M021()
    {
        return 0;
    }
    virtual int M022()
    {
        return 0;
    }
    virtual int M023()
    {
        return 0;
    }
    virtual int M024()
    {
        return 0;
    }
    virtual int M025()
    {
        return 0;
    }
    virtual int M026()
    {
        return 0;
    }
    virtual int M027()
    {
        return 0;
    }
    virtual int M028()
    {
        return 0;
    }
    virtual int M029()
    {
        return 0;
    }
    virtual int M030()
    {
        return 0;
    }
    virtual int M031()
    {
        return 0;
    }
    virtual int M032()
    {
        return 0;
    }
    virtual int M033()
    {
        return 0;
    }
    virtual int M034()
    {
        return 0;
    }
    virtual int M035()
    {
        return 0;
    }
    virtual int M036()
    {
        return 0;
    }
    virtual int M037()
    {
        return 0;
    }
    virtual int M038()
    {
        return 0;
    }
    virtual int M039()
    {
        return 0;
    }
    virtual int M040()
    {
        return 0;
    }
    virtual int M041()
    {
        return 0;
    }
    virtual int M042()
    {
        return 0;
    }
    virtual int M043()
    {
        return 0;
    }
    virtual int M044()
    {
        return 0;
    }
    virtual int M045()
    {
        return 0;
    }
    virtual int M046()
    {
        return 0;
    }
    virtual int M047()
    {
        return 0;
    }
    virtual int M048()
    {
        return 0;
    }
    virtual int M049()
    {
        return 0;
    }
    virtual int M050()
    {
        return 0;
    }
    virtual int M051()
    {
        return 0;
    }
    virtual int M052()
    {
        return 0;
    }
    virtual int M053()
    {
        return 0;
    }
    virtual int M054()
    {
        return 0;
    }
    virtual int M055()
    {
        return 0;
    }
    virtual int M056()
    {
        return 0;
    }
    virtual int M057()
    {
        return 0;
    }
    virtual int M058()
    {
        return 0;
    }
    virtual int M059()
    {
        return 0;
    }
    virtual int M060()
    {
        return 0;
    }
    virtual int M061()
    {
        return 0;
    }
    virtual int M062()
    {
        return 0;
    }
    virtual int M063()
    {
        return 0;
    }
    virtual int M064()
    {
        return 0;
    }
    virtual int M065()
    {
        return 0;
    }
    virtual int M066()
    {
        return 0;
    }
    virtual int M067()
    {
        return 0;
    }
    virtual int M068()
    {
        return 0;
    }
    virtual int M069()
    {
        return 0;
    }
    virtual int M070()
    {
        return 0;
    }
    virtual int M071()
    {
        return 0;
    }
    virtual int M072()
    {
        return 0;
    }
    virtual int M073()
    {
        return 0;
    }
    virtual int M074()
    {
        return 0;
    }
    virtual int M075()
    {
        return 0;
    }
    virtual int M076()
    {
        return 0;
    }
    virtual int M077()
    {
        return 0;
    }
    virtual int M078()
    {
        return 0;
    }
    virtual int M079()
    {
        return 0;
    }
    virtual int M080()
    {
        return 0;
    }
    virtual int M081()
    {
        return 0;
    }
    virtual int M082()
    {
        return 0;
    }
    virtual int M083()
    {
        return 0;
    }
    virtual int M084()
    {
        return 0;
    }
    virtual int M085()
    {
        return 0;
    }
    virtual int M086()
    {
        return 0;
    }
    virtual int M087()
    {
        return 0;
    }
    virtual int M088()
    {
        return 0;
    }
    virtual int M089()
    {
        return 0;
    }
    virtual int M090()
    {
        return 0;
    }
    virtual int M091()
    {
        return 0;
    }
    virtual int M092()
    {
        return 0;
    }
    virtual int M093()
    {
        return 0;
    }
    virtual int M094()
    {
        return 0;
    }
    virtual int M095()
    {
        return 0;
    }
    virtual int M096()
    {
        return 0;
    }
    virtual int M097()
    {
        return 0;
    }
    virtual int M098()
    {
        return 0;
    }
    virtual int M099()
    {
        return 0;
    }
    virtual int M100()
    {
        return 0;
    }
    virtual int M101()
    {
        return 0;
    }
    virtual int M102()
    {
        return 0;
    }
    virtual int M103()
    {
        return 0;
    }
    virtual int M104()
    {
        return 0;
    }
    virtual int M105()
    {
        return 0;
    }
    virtual int M106()
    {
        return 0;
    }
    virtual int M107()
    {
        return 0;
    }
    virtual int M108()
    {
        return 0;
    }
    virtual int M109()
    {
        return 0;
    }
    virtual int M110()
    {
        return 0;
    }
    virtual int M111()
    {
        return 0;
    }
    virtual int M112()
    {
        return 0;
    }
    virtual int M113()
    {
        return 0;
    }
    virtual int M114()
    {
        return 0;
    }
    virtual int M115()
    {
        return 0;
    }
    virtual int M116()
    {
        return 0;
    }
    virtual int M117()
    {
        return 0;
    }
    virtual int M118()
    {
        return 0;
    }
    virtual int M119()
    {
        return 0;
    }
    virtual int M120()
    {
        return 0;
    }
    virtual int M121()
    {
        return 0;
    }
    virtual int M122()
    {
        return 0;
    }
    virtual int M123()
    {
        return 0;
    }
    virtual int M124()
    {
        return 0;
    }
    virtual NiPoint3* Target()
    {
        return 0;
    }
};

// @fnv 0x009f1140
// src: XBOX_PDB 0x009f1140
bool FleePackage::FindTeleportDoor(TESObjectREFR* apRef, TESObjectREFR* apContext)
{
    if (!flag80)
        return false;

    if (!apContext)
        return false;

    DAT_011f2f1c = apContext;

    if (reinterpret_cast<TESObjectREFR_GetRefPersists*>(apRef)->GetReferencePersistence())
    {
        g_dataHandler->GetReferencesInArea(
            reinterpret_cast<TESObjectCELL*>(reinterpret_cast<BSOcclusionPlane*>(apRef)->GetCullResult()),
            *reinterpret_cast<FUN_009f1140_VirtualTarget*>(apRef)->Target(), runtimeFloatSettingDefault132,
            *reinterpret_cast<FUN_009f1140_VirtualTarget*>(apRef)->Target(), runtimeFloatSettingDefault132,
            CanActorReachReference, reinterpret_cast<long>(apRef));
    }

    pRefA0 = reinterpret_cast<TESObjectREFR*>(DAT_011f2f10);
    DAT_011f2f1c = 0;
    DAT_011f2f10 = 0;

    return pRefA0 != 0;
}

struct Saver
{
    unsigned short TESPackage_GetSaveSize();
};


struct SaveManager;
extern SaveManager* DAT_011de45c;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

TESForm* _ref_004839c0(unsigned int formID);

// Exe 0x009f19f0: unit-local FleepackageInterfaceView view used by this matched implementation.
struct FleepackageInterfaceView
{
    static void __cdecl PrintDebugMessage(const char* format, ...);
};

extern const char str_01093344[];
extern const char $SG7035[];
extern const char $SG7038[];

struct HitSound
{
    unsigned int formID;
    unsigned char padding;
    unsigned int flags;
};

// @fnv 0x009f19f0
unsigned short FleePackage::GetSaveSize()
{
    unsigned short usSize = 0;
    unsigned short usOldSize;

    usSize += reinterpret_cast<Saver*>(this)->TESPackage_GetSaveSize();
    usOldSize = usSize;

    if (reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        usSize += 4;
        usSize += 2;
    }

    usSize += reinterpret_cast<BSSimpleListTESRaceSize*>(&AvoidedRefList)->GetSize() * 4 + 2;
    usSize += 4;
    usSize += 4;
    usSize += 1;
    usSize += 1;
    usSize += 1;
    usSize += 4;
    usSize += 12;
    usSize += 1;
    usSize += 1;

    if (*g_011de4e8.Bool())
    {
        HitSound* m_pContactSound =
            reinterpret_cast<HitSound*>(reinterpret_cast<TESSaveLoadGame*>(DAT_011de45c)->GetHitSound());

        if (m_pContactSound)
        {
            TESForm* pForm = _ref_004839c0(m_pContactSound->formID);

            FleepackageInterfaceView::PrintDebugMessage(
                $SG7035, usSize - usOldSize, m_pContactSound->formID, pForm->GetName(),
                *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(m_pContactSound) + 5), 0x237,
                str_01093344);
        }
        else
        {
            FleepackageInterfaceView::PrintDebugMessage($SG7038, usSize - usOldSize, 0x237, str_01093344);
        }
    }

    return usSize;
}

struct FUN_006797c0_shell
{
    void TESPackage_SaveGame(void*);
};

struct FleeSaveReferenceList
{
    TESObjectREFR** _ref_006815c0();
    FleeSaveReferenceList* _ref_00726070();
};

// Serializes the object's extra fields and its reference list into the save buffer, then writes the reference count and a form value.
// @fnv 0x009f2380
void FleePackage::SaveExtraData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    FleeSaveReferenceList* isaveGameBufferPos;
    unsigned int pForm;
    unsigned int isaveGameCount;
    TESObjectREFR* pCurrentElementNext;

    reinterpret_cast<FUN_006797c0_shell*>(this)->TESPackage_SaveGame(apSaveGameBuffer);

    apSaveGameBuffer->SaveData((void*)((char*)&flag80), 1, 0);
    apSaveGameBuffer->SaveData((void*)((char*)&flag81), 1, 0);
    apSaveGameBuffer->SaveData((void*)((char*)&position), 0xc, 0);
    apSaveGameBuffer->SaveData((void*)((char*)&timer), 4, 0);
    apSaveGameBuffer->SaveData((void*)((char*)&flag94), 1, 0);
    apSaveGameBuffer->SaveData((void*)((char*)&flagA8), 1, 0);
    apSaveGameBuffer->SaveData((void*)((char*)&flagA9), 1, 0);

    apSaveGameBuffer->SerializeFormData(pRefA0, 0);
    apSaveGameBuffer->SerializeFormData(pRefA4, 0);

    isaveGameCount = 0;
    pForm = apSaveGameBuffer->StartVariableSizedValue();
    isaveGameBufferPos = (FleeSaveReferenceList*)((char*)&AvoidedRefList);

    while (isaveGameBufferPos != 0)
    {
        pCurrentElementNext = *isaveGameBufferPos->_ref_006815c0();
        if (pCurrentElementNext != 0)
        {
            apSaveGameBuffer->SerializeFormData(pCurrentElementNext, 0);
            ++isaveGameCount;
        }
        isaveGameBufferPos = isaveGameBufferPos->_ref_00726070();
    }

    apSaveGameBuffer->SaveVariableSizedValue_00865ff0(isaveGameCount, pForm);
}

struct G2
{
    void __thiscall AddHead(int*);
};

// Calls LoadGame, reads several fields from the buffer, then reads a count and loads that many TESObjectREFR forms into the list at offset 0x98.
// @fnv 0x009f24d0
// src: XBOX_PDB 0x009f24d0
void FleePackage::LoadGame_009f24d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<TESPackage*>(this)->TESPackage::LoadGame(apLoadGameBuffer);

    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&flag80)), 1);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&flag81)), 1);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&position)), 0x0c);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&timer)), 4);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&flag94)), 1);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&flagA8)), 1);
    apLoadGameBuffer->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(&flagA9)), 1);

    apLoadGameBuffer->ReadFormIdentifier(reinterpret_cast<void*>(reinterpret_cast<char*>(&pRefA0)));
    apLoadGameBuffer->ReadFormIdentifier(reinterpret_cast<void*>(reinterpret_cast<char*>(&pRefA4)));

    unsigned int isaveGameCount = apLoadGameBuffer->ReadElementCount();
    {
        unsigned int uiIndex;
        for (uiIndex = 0; uiIndex < isaveGameCount; uiIndex++)
        {
            TESObjectREFR* pForm = 0;
            apLoadGameBuffer->ReadFormIdentifier(&pForm);
            reinterpret_cast<G2*>(reinterpret_cast<char*>(&AvoidedRefList))->AddHead(reinterpret_cast<int*>(&pForm));
        }
    }
}

// FindNearestRef: flee-package helper: scan avoided-ref list, pick nearest candidate.
struct FUN_009f1210_ref;
struct FUN_009f1210_node
{
    FUN_009f1210_ref** _ref_006815c0();
    FUN_009f1210_node* FUN_00726070();
};
struct FUN_009f1210_ref
{
    virtual void M000();
    virtual void M001();
    virtual void M002();
    virtual void M003();
    virtual void M004();
    virtual void M005();
    virtual void M006();
    virtual void M007();
    virtual void M008();
    virtual void M009();
    virtual void M010();
    virtual void M011();
    virtual void M012();
    virtual void M013();
    virtual void M014();
    virtual void M015();
    virtual void M016();
    virtual void M017();
    virtual void M018();
    virtual void M019();
    virtual void M020();
    virtual void M021();
    virtual void M022();
    virtual void M023();
    virtual void M024();
    virtual void M025();
    virtual void M026();
    virtual void M027();
    virtual void M028();
    virtual void M029();
    virtual void M030();
    virtual void M031();
    virtual void M032();
    virtual void M033();
    virtual void M034();
    virtual void M035();
    virtual void M036();
    virtual void M037();
    virtual void M038();
    virtual void M039();
    virtual void M040();
    virtual void M041();
    virtual void M042();
    virtual void M043();
    virtual void M044();
    virtual void M045();
    virtual void M046();
    virtual void M047();
    virtual void M048();
    virtual void M049();
    virtual void M050();
    virtual void M051();
    virtual void M052();
    virtual void M053();
    virtual void M054();
    virtual void M055();
    virtual void M056();
    virtual void M057();
    virtual void M058();
    virtual void M059();
    virtual void M060();
    virtual void M061();
    virtual void M062();
    virtual void M063();
    virtual void M064();
    virtual void M065();
    virtual void M066();
    virtual void M067();
    virtual void M068();
    virtual void M069();
    virtual void M070();
    virtual void M071();
    virtual void M072();
    virtual void M073();
    virtual void M074();
    virtual void M075();
    virtual void M076();
    virtual void M077();
    virtual void M078();
    virtual void M079();
    virtual void M080();
    virtual void M081();
    virtual void M082();
    virtual void M083();
    virtual void M084();
    virtual void M085();
    virtual void M086();
    virtual void M087();
    virtual void M088();
    virtual void M089();
    virtual void M090();
    virtual void M091();
    virtual void M092();
    virtual void M093();
    virtual void M094();
    virtual void M095();
    virtual void M096();
    virtual void M097();
    virtual void M098();
    virtual void M099();
    virtual void M100();
    virtual void M101();
    virtual void M102();
    virtual void M103();
    virtual void M104();
    virtual void M105();
    virtual void M106();
    virtual void M107();
    virtual void M108();
    virtual void M109();
    virtual void M110();
    virtual void M111();
    virtual void M112();
    virtual void M113();
    virtual void M114();
    virtual void M115();
    virtual void M116();
    virtual void M117();
    virtual void M118();
    virtual void M119();
    virtual void M120();
    virtual void M121();
    virtual void M122();
    virtual void M123();
    virtual void M124();
    virtual void M125();
    virtual void M126();
    virtual void M127();
    virtual void M128();
    virtual void M129();
    virtual void M130();
    virtual void M131();
    virtual void M132();
    virtual void M133();
    virtual void M134();
    virtual void M135();
    virtual void M136();
    virtual void M137();
    virtual void M138();
    virtual bool M139(int a);
    bool TESObjectREFR_GetRefPersists_005653d0();
    float TESObjectREFR_GetDistanceFromReference(FUN_009f1210_ref* apRef, int a2, int a3);
    bool FUN_00440da0();
};
extern const float DAT_01016970;

// @fnv 0x009f1210
TESObjectREFR* FleePackage::FindNearestRef(TESObjectREFR* apRef)
{
    if (flag80 == 0 || !reinterpret_cast<FUN_009f1210_ref*>(apRef)->TESObjectREFR_GetRefPersists_005653d0())
    {
        return 0;
    }
    FUN_009f1210_node* nodeB = reinterpret_cast<FUN_009f1210_node*>(&AvoidedRefList);
    float best = DAT_01016970;
    FUN_009f1210_ref* result2 = 0;
    float d2;
    FUN_009f1210_ref* cand;
    while (nodeB != 0 && *nodeB->_ref_006815c0() != 0)
    {
        cand = *nodeB->_ref_006815c0();
        nodeB = nodeB->FUN_00726070();
        d2 = cand->TESObjectREFR_GetDistanceFromReference(reinterpret_cast<FUN_009f1210_ref*>(apRef), 0, 0);
        if (cand->FUN_00440da0() || cand->M139(0))
        {
            RemoveRef(reinterpret_cast<TESObjectREFR*>(cand));
            nodeB = reinterpret_cast<FUN_009f1210_node*>(&AvoidedRefList);
        }
        else if (best > d2)
        {
            best = d2;
            result2 = cand;
        }
    }
    return reinterpret_cast<TESObjectREFR*>(result2);
}

struct AvoidedReference
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
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual bool IsDead(int);
    bool FUN_00440d80();
    bool Actor_IsInCombat();
};
extern AvoidedReference* DAT_011dea3c;
struct AvoidedList
{
    AvoidedReference* value;
    AvoidedList* next;
    AvoidedReference*& FUN_006815c0();
    void FUN_0063f7b0();
    AvoidedList* FUN_00726070();
};
struct AvoidanceSetting
{
    float* Setting_Float_00403e20();
};
extern AvoidanceSetting DAT_011cd348;
double CombatTimer_GetTimer();
struct AvoidanceContext
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual double GetLastTime(AvoidedReference*, int);
};

// @fnv 0x009f1830
void FleePackage::RemoveInvalidAvoidedReferences(AvoidanceContext* context)
{
    AvoidedList* current = reinterpret_cast<AvoidedList*>(&AvoidedRefList);
    float limit2 = *DAT_011cd348.Setting_Float_00403e20();
    while (current && current->FUN_006815c0())
    {
        AvoidedReference* reference6 = current->FUN_006815c0();
        AvoidedReference* actor = reference6->IsActor() ? reference6 : 0;
        bool remove4 = reference6->IsDead(0) || reference6->FUN_00440d80();
        if (!remove4 && actor && flag81)
        {
            remove4 = (!actor->Actor_IsInCombat() && actor != DAT_011dea3c) ||
                      (context && CombatTimer_GetTimer() - context->GetLastTime(actor, 0) > limit2);
        }
        if (remove4)
        {
            current->FUN_0063f7b0();
            current = reinterpret_cast<AvoidedList*>(&AvoidedRefList);
            continue;
        }
        current = current->FUN_00726070();
    }
}

// Destructor: empty the owned list explicitly, then the list member and the base clean up.

// Destructor that removes all avoided references.
// @fnv 0x009f10c0
FleePackage::~FleePackage()
{
    AvoidedRefList.RemoveAll();
}

struct FUN_00672930_flags
{
    int GetFlags();
};

struct AvoidedRefTarget
{
    virtual void m000();
    virtual void m001();
    virtual void m002();
    virtual void m003();
    virtual void m004();
    virtual void m005();
    virtual void m006();
    virtual void m007();
    virtual void m008();
    virtual void m009();
    virtual void m010();
    virtual void m011();
    virtual void m012();
    virtual void m013();
    virtual void m014();
    virtual void m015();
    virtual void m016();
    virtual void m017();
    virtual void m018();
    virtual void m019();
    virtual void m020();
    virtual void m021();
    virtual void m022();
    virtual void m023();
    virtual void m024();
    virtual void m025();
    virtual void m026();
    virtual void m027();
    virtual void m028();
    virtual void m029();
    virtual void m030();
    virtual void m031();
    virtual void m032();
    virtual void m033();
    virtual void m034();
    virtual void m035();
    virtual void m036();
    virtual void m037();
    virtual void m038();
    virtual void m039();
    virtual void m040();
    virtual void m041();
    virtual void m042();
    virtual void m043();
    virtual void m044();
    virtual void m045();
    virtual void m046();
    virtual void m047();
    virtual void m048();
    virtual void m049();
    virtual void m050();
    virtual void m051();
    virtual void m052();
    virtual void m053();
    virtual void m054();
    virtual void m055();
    virtual void m056();
    virtual void m057();
    virtual void m058();
    virtual void m059();
    virtual void m060();
    virtual void m061();
    virtual void m062();
    virtual void m063();
    virtual void m064();
    virtual void m065();
    virtual void m066();
    virtual void m067();
    virtual void m068();
    virtual void m069();
    virtual void m070();
    virtual void m071();
    virtual void m072();
    virtual void m073();
    virtual void m074();
    virtual void m075();
    virtual void m076();
    virtual void m077();
    virtual void m078();
    virtual void m079();
    virtual void m080();
    virtual void m081();
    virtual void m082();
    virtual void m083();
    virtual void m084();
    virtual void m085();
    virtual void m086();
    virtual void m087();
    virtual void m088();
    virtual void m089();
    virtual void m090();
    virtual void m091();
    virtual void m092();
    virtual void m093();
    virtual void m094();
    virtual void m095();
    virtual void m096();
    virtual void m097();
    virtual void m098();
    virtual void m099();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual void m115();
    virtual void m116();
    virtual void m117();
    virtual void m118();
    virtual void m119();
    virtual void m120();
    virtual void m121();
    virtual void m122();
    virtual void m123();
    virtual void m124();
    virtual NiPoint3* GetPos();
};

extern const float runtimeFloatSettingDefault38;
extern const float runtimeFloatSettingDefault1232;
extern const float runtimeFloatSettingDefault1018;

float __cdecl BSMAX_00404010(float, float);

// @fnv 0x009f1440
PathingAvoidNodeArray* FleePackage::BuildAvoidNodeArray()
{
    PathingAvoidNodeArray* pNodes_ = new PathingAvoidNodeArray;
    float fRadius3 = ((TESPackage*)this)->GetTarget()
                         ? (float)((FUN_00672930_flags*)((TESPackage*)this)->GetTarget())->GetFlags()
                         : runtimeFloatSettingDefault1232;
    fRadius3 = BSMAX_00404010(fRadius3, runtimeFloatSettingDefault38);
    AvoidedList* pNode;
    float fRadius4;
    AvoidedReference* pRef;
    unsigned int iSize;
    for (pNode = reinterpret_cast<AvoidedList*>(&AvoidedRefList); pNode != 0; pNode = pNode->FUN_00726070())
    {
        pRef = pNode->FUN_006815c0();
        if (!pRef || ((Actor*)pRef)->GetDisabled() || pRef->IsDead(0))
            continue;

        iSize = ((FUN_00672930_flags*)pNodes_)->GetFlags();
        pNodes_->SetSize(iSize + 1, true);
        fRadius4 = BSMAX_00404010(fRadius3 * fRadius3, runtimeFloatSettingDefault1018);
        *pNodes_->BSSimpleArray_PathingAvoidNode_1024_GetAt(iSize) = PathingAvoidNode(*((AvoidedRefTarget*)pRef)->GetPos(), fRadius3, fRadius4);
    }
    return pNodes_;
}

struct DoorAccess
{
    unsigned int flags;
    TESObjectREFR* destination;
    bool FUN_005021a0();
};
struct ReferenceAccess
{
    bool FUN_00440d80();
    bool TESForm_GetTemporary();
    bool FUN_00440da0();
    void* BGSSaveFormBuffer_GetForm();
    void* FUN_00568e50();
    bool TESObjectREFR_GetInterior();
    float TESObjectREFR_GetDistanceFromReference(ReferenceAccess*, int, int);
    DoorAccess* TESObjectREFR_GetLock();
    bool TESObjectREFR_IsAnOwner(ReferenceAccess*, bool);
    bool Actor_HasObjects(TESObjectREFR*, int, int, int, int*);
    NiPoint3 const& TESObjectREFR_GetLinkedDoorTeleportPosition();
};
extern void* DAT_011ca258;
extern const float runtimeFloatSettingDefault1070;
extern const float runtimeFloatSettingDefault142;
bool __cdecl CallWithNullArgs(PathingLocation*, PathingLocation*, int);

// @fnv 0x009f1600
bool __cdecl CanActorReachReference(TESObjectREFR* reference, long context)
{
    float fDistance;
    {
        ReferenceAccess* pActor;
        {
            float m_fUnknownValue2;
            {
                float fTargetDistance;
                {
                    int iAccessResult;
                    if (!reference || ((ReferenceAccess*)reference)->FUN_00440d80() ||
                        ((ReferenceAccess*)reference)->TESForm_GetTemporary() || ((ReferenceAccess*)reference)->FUN_00440da0())
                        return false;
                    iAccessResult = 0;
                    pActor = (ReferenceAccess*)context;
                    if (!pActor)
                        return false;
                    if (((ReferenceAccess*)reference)->BGSSaveFormBuffer_GetForm() == DAT_011ca258)
                        return false;
                    if (!((ReferenceAccess*)reference)->FUN_00568e50())
                        return false;
                    m_fUnknownValue2 = DAT_011f2f1c && ((ReferenceAccess*)DAT_011f2f1c)->TESObjectREFR_GetInterior()
                                           ? runtimeFloatSettingDefault1070
                                           : runtimeFloatSettingDefault142;
                    fDistance = ((ReferenceAccess*)reference)->TESObjectREFR_GetDistanceFromReference(pActor, 0, 0);
                    fTargetDistance = ((ReferenceAccess*)reference)->TESObjectREFR_GetDistanceFromReference((ReferenceAccess*)DAT_011f2f1c, 0, 0);
                    if (fTargetDistance > m_fUnknownValue2 || fTargetDistance > fDistance)
                    {
                        DoorAccess* door = ((ReferenceAccess*)reference)->TESObjectREFR_GetLock();
                        if (door && door->FUN_005021a0() && !((ReferenceAccess*)reference)->TESObjectREFR_IsAnOwner(pActor, true))
                        {
                            if (!door->destination || !pActor->Actor_HasObjects(door->destination, 0, 1, 0, &iAccessResult))
                                return false;
                        }
                        PathingLocation actorLocation((TESObjectREFR*)pActor);
                        PathingLocation referenceLocation(((ReferenceAccess*)reference)->TESObjectREFR_GetLinkedDoorTeleportPosition(), reference);
                        if (!CallWithNullArgs(&actorLocation, &referenceLocation, 0))
                            return false;
                        DAT_011f2f10 = (int)reference;
                        return true;
                    }
                    return false;
                }
            }
        }
    }
}

struct SavedReference
{
    unsigned int GetFormID();
};
struct SavedReferenceList
{
    SavedReference* value;
    SavedReferenceList* next;
    bool FUN_008256d0();
    SavedReference*& _ref_006815c0();
    SavedReferenceList* FUN_00726070();
};
struct SaveDebugRecord
{
    unsigned int formID;
    unsigned char state;
    unsigned char flags;
};
struct SaveStream
{
    unsigned char* FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);
    SaveDebugRecord* GetHitSound();
};

struct PackageSaveAccess
{
    void SavePackage();
    void ForwardToSaveLoadGame(void*, int);
    void TESForm_SaveGameDataOLD(void*, int);
};
void __cdecl FNV_Warning(const char*, ...);
// @fnv 0x009f1b70
void FleePackage::SaveFleePackage()
{
    reinterpret_cast<PackageSaveAccess*>(this)->SavePackage();
    unsigned short sizeVal = 0;   // Serialized block length.
    unsigned char* position = 0;  // Address of the block length field.
    unsigned char* aPosition = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
    if (*g_011de4e8.Bool())
        aPosition = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
    if (reinterpret_cast<SaveStream*>(DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int tag = 0x424c4f4b;
        reinterpret_cast<SaveStream*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&tag, 4);
        position = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
        reinterpret_cast<SaveStream*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&sizeVal, 2);
    }
    unsigned short kCount = 0;  // Number of avoided references.
    unsigned char* _position = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
    reinterpret_cast<SaveStream*>(DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&kCount, 2);
    SavedReferenceList* node = reinterpret_cast<SavedReferenceList*>(&AvoidedRefList);
    while (node && !node->FUN_008256d0())
    {
        SavedReference* reference = node->_ref_006815c0();
        unsigned int formID = reference->GetFormID();
        reinterpret_cast<PackageSaveAccess*>(this)->ForwardToSaveLoadGame(&formID, 4);
        ++kCount;
        node = node->FUN_00726070();
    }
    *reinterpret_cast<unsigned short*>(_position) = kCount;
    unsigned int formB = 0;
    if (pRefA4)
        formB = reinterpret_cast<SavedReference*>(pRefA4)->GetFormID();
    reinterpret_cast<PackageSaveAccess*>(this)->ForwardToSaveLoadGame(&formB, 4);
    unsigned int form = 0;
    if (pRefA0)
        form = reinterpret_cast<SavedReference*>(pRefA0)->GetFormID();
    reinterpret_cast<PackageSaveAccess*>(this)->ForwardToSaveLoadGame(&form, 4);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&flag81, 1);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&flagA8, 1);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&flag94, 1);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&timer, 4);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&this->position, 12);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&flag80, 1);
    reinterpret_cast<PackageSaveAccess*>(this)->TESForm_SaveGameDataOLD(&flagA9, 1);
    if (*g_011de4e8.Bool())
    {
        unsigned char* end = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
        SaveDebugRecord* reference = reinterpret_cast<SaveStream*>(DAT_011de45c)->GetHitSound();
        if (reference)
        {
            TESForm* form = _ref_004839c0(reference->formID);
            FleepackageInterfaceView::PrintDebugMessage(
                "SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end - aPosition,
                reference->formID, form->GetName(), *reinterpret_cast<unsigned int*>(&reference->flags), 618,
                str_01093344);
        }
        else
        {
            FleepackageInterfaceView::PrintDebugMessage("SaveGame(): %-5i ending at line %i in file %s", end - aPosition, 618,
                                         str_01093344);
        }
    }
    if (reinterpret_cast<SaveStream*>(DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned char* end = reinterpret_cast<SaveStream*>(DAT_011de45c)->FUN_00825c00();
        unsigned char* data = position;
        if (end > data + 65535)
            FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        str_01093344, 618);
        *reinterpret_cast<unsigned short*>(position) = static_cast<unsigned short>(end - data);
    }
}

struct FleeLoadFormInfo
{
    unsigned int auiFormId;
    unsigned char m_ucTimeSettings[6];
};

struct FleeLoadManager
{
    bool IsLoading();
    void ReadTypedData(void* apBuffer, int aiSize);
    unsigned int GetOffset();
    FleeLoadFormInfo* GetCurrentFormInfo();
    unsigned char GetVersion();
};

extern FleeLoadManager* g_pFleeLoadManager;

void __cdecl FleeLoadWarning(const char* apFormat, ...);
TESForm* __cdecl FleeLookupFormByID(unsigned int auiFormID);

struct FleeLoadRef;

struct FleeLoadRefList
{
    void AddHead(FleeLoadRef* const& arRef);
};

struct PackageLoadAccess
{
    void BaseLoadGame();
    void ReadTypedData(void*, int);
    void ReadFormIdentifier(unsigned int*, int);
};

// Loads the package's avoided-ref list, targets, flags, value and position from the save buffer, validating the BLOK header and block size.
// @fnv 0x009f1e80
// src: XBOX_PDB 0x009f1e80
void FleePackage::LoadGame_009f1e80()
{
    unsigned short usCount4;
    unsigned int uiRefA7;
    unsigned int uiRefA9;
    unsigned int uiBlockStart7;
    unsigned short usBlockSize2;
    int i3;

    reinterpret_cast<PackageLoadAccess*>(this)->BaseLoadGame();
    usBlockSize2 = 0;
    uiBlockStart7 = 0;

    if (g_pFleeLoadManager->IsLoading())
    {
        int iMarker;
        g_pFleeLoadManager->ReadTypedData(&iMarker, 4);
        if (iMarker != 'BLOK')
        {
            FleeLoadFormInfo* pInfo = g_pFleeLoadManager->GetCurrentFormInfo();
            if (pInfo)
            {
                TESForm* pForm = FleeLookupFormByID(pInfo->auiFormId);
                FleeLoadWarning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\FleePackage.cpp", 0x272, pInfo->auiFormId,
                    pForm->GetName(), pInfo->m_ucTimeSettings[5], *(unsigned int*)(pInfo->m_ucTimeSettings + 1));
            }
            else
            {
                FleeLoadWarning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\FleePackage.cpp", 0x272,
                    g_pFleeLoadManager->GetVersion());
            }
        }
        uiBlockStart7 = g_pFleeLoadManager->GetOffset();
        g_pFleeLoadManager->ReadTypedData(&usBlockSize2, 2);
    }

    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&usCount4, 2);
    for (i3 = 0; i3 < usCount4; i3++)
    {
        unsigned int auiFormId;
        reinterpret_cast<PackageLoadAccess*>(this)->ReadFormIdentifier(&auiFormId, 4);
        unsigned int uiRef = auiFormId;
        reinterpret_cast<FleeLoadRefList*>(&AvoidedRefList)->AddHead((FleeLoadRef*)uiRef);
    }

    reinterpret_cast<PackageLoadAccess*>(this)->ReadFormIdentifier(&uiRefA9, 4);
    pRefA4 = reinterpret_cast<TESObjectREFR*>(uiRefA9);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadFormIdentifier(&uiRefA7, 4);
    pRefA0 = reinterpret_cast<TESObjectREFR*>(uiRefA7);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&flag81, 1);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&flagA8, 1);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&flag94, 1);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&timer, 4);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(position.components, 0xc);
    reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&flag80, 1);
    if (g_pFleeLoadManager->GetVersion() >= 0x71)
        reinterpret_cast<PackageLoadAccess*>(this)->ReadTypedData(&flagA9, 1);

    if (g_pFleeLoadManager->IsLoading())
    {
        unsigned int uiBlockEndA = g_pFleeLoadManager->GetOffset();
        FleeLoadFormInfo* pEndInfo = g_pFleeLoadManager->GetCurrentFormInfo();
        if (pEndInfo)
        {
            TESForm* pEndForm = FleeLookupFormByID(pEndInfo->auiFormId);
            if (uiBlockEndA > usBlockSize2 + uiBlockStart7)
                FleeLoadWarning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    uiBlockEndA - (usBlockSize2 + uiBlockStart7),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\FleePackage.cpp", 0x29a, pEndInfo->auiFormId,
                    pEndForm->GetName(), pEndInfo->m_ucTimeSettings[5],
                    *(unsigned int*)(pEndInfo->m_ucTimeSettings + 1));
            else if (uiBlockEndA < usBlockSize2 + uiBlockStart7)
                FleeLoadWarning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    (usBlockSize2 + uiBlockStart7) - uiBlockEndA,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\FleePackage.cpp", 0x29a, pEndInfo->auiFormId,
                    pEndForm->GetName(), pEndInfo->m_ucTimeSettings[5],
                    *(unsigned int*)(pEndInfo->m_ucTimeSettings + 1));
        }
        else
        {
            if (uiBlockEndA > usBlockSize2 + uiBlockStart7)
                FleeLoadWarning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    uiBlockEndA - (usBlockSize2 + uiBlockStart7),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\FleePackage.cpp", 0x29a,
                    g_pFleeLoadManager->GetVersion());
            else if (uiBlockEndA < usBlockSize2 + uiBlockStart7)
                FleeLoadWarning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    (usBlockSize2 + uiBlockStart7) - uiBlockEndA,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\FleePackage.cpp", 0x29a,
                    g_pFleeLoadManager->GetVersion());
        }
    }
}

TESForm* _ref_004839c0(unsigned int formID);

struct RefListNode
{
    TESObjectREFR* item;
    RefListNode* next;
    bool IsEmpty();
    TESObjectREFR** GetItem();
    void SetItem(TESObjectREFR* const& apItem);
    void RemoveAfter(TESObjectREFR* const& apItem);
    RefListNode* GetNext();
    void RemoveHead();
};

struct TESPackageInitLoadAccess
{
    void InitLoadGame(void* apBuffer);
};

// Calls the base InitLoadGame, re-resolves pRefA0/pRefA4 and the AvoidedRefList entries via _ref_004839c0, removing entries that no longer resolve.
// @fnv 0x009f25f0
// src: XBOX_PDB 0x009f25f0
void FleePackage::InitLoadGame_009f25f0(void* apBuffer)
{
    reinterpret_cast<TESPackageInitLoadAccess*>(this)->InitLoadGame(apBuffer);
    pRefA0 = pRefA0 ? dynamic_cast<TESObjectREFR*>(_ref_004839c0((unsigned int)pRefA0)) : 0;
    pRefA4 = pRefA4 ? dynamic_cast<TESObjectREFR*>(_ref_004839c0((unsigned int)pRefA4)) : 0;

    RefListNode* pNode = reinterpret_cast<RefListNode*>(&AvoidedRefList);
    RefListNode* pPrev = 0;
    while (pNode && !pNode->IsEmpty())
    {
        TESObjectREFR* pRef = *pNode->GetItem();
        bool bRemove = false;
        if (pRef)
        {
            pRef = pRef ? dynamic_cast<TESObjectREFR*>(_ref_004839c0((unsigned int)pRef)) : 0;
            if (pRef)
                pNode->SetItem(pRef);
            else
                bRemove = true;
        }
        else
        {
            bRemove = true;
        }
        if (bRemove)
        {
            if (pPrev)
            {
                pPrev->RemoveAfter(*pNode->GetItem());
                pNode = pPrev->GetNext();
            }
            else
            {
                pNode->RemoveHead();
            }
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->GetNext();
        }
    }
}
