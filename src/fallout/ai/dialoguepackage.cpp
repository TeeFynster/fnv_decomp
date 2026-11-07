// fallout/ai/dialoguepackage.cpp: DialoguePackage and local helper support (18 functions)

#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/DialogueItem.h"
#include "../../../include/DialoguePackage.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/MobileObject.h"
#include "../../../include/TESPackage.h"
#include "../../../include/TESSound.h"
#include "../../../include/TESTopic.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/Setting.h"
#include "../../../include/TESSaveLoadGame.h"

class BGSTerrainManager;
BGSTerrainManager* LoadBGSTerrainManager(const char* path);
#include "../../../include/SL.h"
#include "../../../include/BGSLoadFormBuffer.h"

// @fnv 0x004d52d0
BGSTerrainManager* LoadBGSTerrainManager(const NiPointer<NiNode>& apNode)
{
    return LoadBGSTerrainManager(reinterpret_cast<const char*>(apNode.operator->()));
}

// @fnv 0x009ee040
// src: XBOX_PDB 0x009ee040
int __fastcall DialoguePackage_GetActorStartedConversation(char* pThis)
{
    return *(int*)(pThis + 0xb0);
}

void __cdecl Deallocate(void*);
namespace p07 {
struct PackageDestructorSupport : DialoguePackage
{
    void FUN_0083dec0();
};
struct PackageDeleteSupport : DialoguePackage
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x009edd50
void* PackageDeleteSupport::Destroy(unsigned int flags)
{
    ((PackageDestructorSupport*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct BSBound;
struct Date
{
    char b[0x24];
    ~Date();
};
struct Q
{
    ~Q();
};
struct PC7d
{
    char pad[0x208];
    void* f208;
    BSBound* GetObjectBounds();
    void SetBoundingBox(BSBound*);
};
extern PC7d* g_thePlayer;
// Retained: the checked DialoguePackage header lacks an explicit destructor and
// the owning members needed for its implicit cleanup and exception unwinding.
struct FUN_009edf40 : public TESPackage
{
    Date d;
    Q* p;
    ~FUN_009edf40();
};
// @fnv 0x009edf40
FUN_009edf40::~FUN_009edf40()
{
    if (this == g_thePlayer->f208)
        g_thePlayer->f208 = 0;
    if ((void*)this == (void*)g_thePlayer->GetObjectBounds())
        g_thePlayer->SetBoundingBox(0);
    delete p;
}

// The checked header does not yet declare these pointer and flag accessors.
struct PackagePointerSupport : DialoguePackage
{
    bool IsPointerMatch(const void* p);
};

// Returns whether p equals the pointer stored at offset 0xb0 of this object.
// @fnv 0x009edd30
bool PackagePointerSupport::IsPointerMatch(const void* apValue)
{
    return apValue == pActor;
}

struct PackageByteSupport : DialoguePackage
{
    unsigned char GetByteAtBC();
};

// @fnv 0x009ef510
unsigned char PackageByteSupport::GetByteAtBC()
{
    return unkBC;
}

struct PackageFlagSupport : DialoguePackage
{
    bool __thiscall DialoguePackage_GetTargetContinueMoving();
};

// @fnv 0x008e95c0
// src: XBOX_PDB 0x008e95c0
bool __thiscall PackageFlagSupport::DialoguePackage_GetTargetContinueMoving()
{
    return reinterpret_cast<bool&>(unkBF);
}

struct FUN_0083b830 : SL
{
    int _c;
    FUN_0083b830();
};
// Initializes the _c member to 0.
// @fnv 0x0083b830
FUN_0083b830::FUN_0083b830()
{
    _c = 0;
}

// Calls CopyFromPackage on apCopy, then dynamic_casts apCopy to DialoguePackage and stores the result in pcopy.
// @fnv 0x009ee060
// src: XBOX_PDB 0x009ee060
void DialoguePackage::Copy_009ee060(TESForm* apCopy)
{
    CopyFromPackage(apCopy);
    DialoguePackage* pSourcePackage = dynamic_cast<DialoguePackage*>(apCopy);
}

// If the mobile object is set, stops its dialogue.
// @fnv 0x009ef530
void DialoguePackage::Stop()
{
    if (m_pkMobileObject)
        m_pkMobileObject->MobileObject_StopCurrentDialogue();
}

namespace fnv_009f01d0 {
// The checked TESPackage header does not yet declare this save helper.
struct PackageSaveSupport : TESPackage
{
    void SaveToBuffer(BGSSaveFormBuffer* buf);
};

// Retained: Conversation.h is absent; 0x0083c270 and 0x0083ba50 are conversation.cpp save/index methods.
struct Conversation
{
    void SaveGameBGS_0083c270(BGSSaveFormBuffer* buf);
    short GetDialogueItemIndex(DialogueItem* item);
};

}  // namespace fnv_009f01d0

// @fnv 0x009f01d0
void DialoguePackage::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    using namespace fnv_009f01d0;
    bool bhasConversation;

    ((PackageSaveSupport*)this)->SaveToBuffer(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData(m_pkMobileObject, 0);
    apSaveGameBuffer->SerializeFormData(pActor, 0);
    apSaveGameBuffer->SerializeFormData(pTargetActor, 0);
    apSaveGameBuffer->SerializeFormData(m_pLinkedReference, 0);
    apSaveGameBuffer->SerializeFormData(m_pkReference, 0);
    apSaveGameBuffer->SerializeFormData(reinterpret_cast<TESTopic*>(topic), 0);
    apSaveGameBuffer->SaveData(&state, 4, 0);
    apSaveGameBuffer->SaveData(&flags, 1, 0);
    apSaveGameBuffer->SaveData(&unkBC, 1, 0);
    apSaveGameBuffer->SaveData(&unkBD, 1, 0);
    apSaveGameBuffer->SaveData(&unkBE, 1, 0);
    apSaveGameBuffer->SaveData(&unkBF, 1, 0);
    apSaveGameBuffer->SaveData(&unkC0, 1, 0);
    apSaveGameBuffer->SaveData(&unkC1, 1, 0);
    apSaveGameBuffer->SaveData(&unkC4, 4, 0);
    apSaveGameBuffer->SaveData(&unkC8, 4, 0);
    apSaveGameBuffer->SaveData(&unkA0, 1, 0);
    apSaveGameBuffer->SaveData(&unkCC, 1, 0);
    apSaveGameBuffer->SaveData(&unkC2, 1, 0);
    bhasConversation = reinterpret_cast<fnv_009f01d0::Conversation*>(conversation);
    apSaveGameBuffer->SaveData(&bhasConversation, 1, 0);
    if (bhasConversation)
    {
        short scurrentResponseIndex;
        short scurrentItemIndex;
        reinterpret_cast<fnv_009f01d0::Conversation*>(conversation)->SaveGameBGS_0083c270(apSaveGameBuffer);
        scurrentItemIndex =
            item
                ? reinterpret_cast<fnv_009f01d0::Conversation*>(conversation)->GetDialogueItemIndex(item)
                : -1;
        apSaveGameBuffer->SaveData(&scurrentItemIndex, 2, 0);
        scurrentResponseIndex = (item && response)
                                    ? item
                                          ->GetResponseIndex(response)
                                    : -1;
        apSaveGameBuffer->SaveData(&scurrentResponseIndex, 2, 0);
    }
}

namespace fnv_009ef560 {

struct SaveManager : public TESSaveLoadGame
{
    unsigned char FUN_008df040();
};

struct Conversation
{
    unsigned short GetSaveSize_0083bb30();
};


// Exe 0x009ef560: unit-local DialoguepackageInterfaceView view used by this matched implementation.
struct DialoguepackageInterfaceView
{
    static void __cdecl PrintDebugMessage(const char* format, int value1, unsigned int value2, const char* value3,
                                          unsigned int value4, int value5, const char* value6);

    static void __cdecl PrintDebugMessage(const char* format, int value1, int value2, const char* value3);
};

extern SaveManager* DAT_011de45c;
extern Setting g_011de4e8;

TESForm* _GetFormByNumericID(unsigned int formID);

}  // namespace fnv_009ef560

// Accumulates the save size of the dialogue package from its saver, conversation and version-dependent fields, optionally logging the size and form details.
// @fnv 0x009ef560
// src: XBOX_PDB 0x009ef560
unsigned short DialoguePackage::GetSaveSize_009ef560()
{
    using namespace fnv_009ef560;
    unsigned short scurrentResponseIndex = 0;

    {
        unsigned short scurrentItemIndex;
        void* apSaveGameBuffer;
        TESForm* pForm;

        scurrentResponseIndex += TESPackage::GetSaveSize();
        scurrentItemIndex = scurrentResponseIndex;

        if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
        {
            scurrentResponseIndex += 4;
            scurrentResponseIndex += 2;
        }

        scurrentResponseIndex += 4;

        if (DAT_011de45c->FUN_008df040() >= 0x6a)
        {
            scurrentResponseIndex += 1;
        }

        scurrentResponseIndex += 0x10;
        scurrentResponseIndex += 2;

        if (m_pkConversation)
        {
            scurrentResponseIndex += ((fnv_009ef560::Conversation*)m_pkConversation)->GetSaveSize_0083bb30();
            scurrentResponseIndex += 2;
            scurrentResponseIndex += 2;
        }

        if (*g_011de4e8.Bool())
        {
            apSaveGameBuffer = DAT_011de45c->GetHitSound();

            if (apSaveGameBuffer)
            {
                pForm = _GetFormByNumericID(*reinterpret_cast<unsigned int*>(apSaveGameBuffer));

                DialoguepackageInterfaceView::PrintDebugMessage(
                    "GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                    scurrentResponseIndex - scurrentItemIndex, *reinterpret_cast<unsigned int*>(apSaveGameBuffer),
                    pForm->GetName(),
                    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(apSaveGameBuffer) + 5), 0x1f4,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
            }
            else
            {
                DialoguepackageInterfaceView::PrintDebugMessage(
                    "GetSaveSize(): %-5i ending at line %i in file %s", scurrentResponseIndex - scurrentItemIndex,
                    0x1f4, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
            }
        }
    }

    return scurrentResponseIndex;
}

namespace fnv_009f0740 {
// The checked TESPackage header does not yet declare this reference helper.
struct PackageReferenceSupport : TESPackage
{
    void DispatchToSubobjects(BGSLoadFormBuffer*);
};

struct Conversation
{
    void InitLoadGame_0083c420(BGSLoadFormBuffer*);
};

TESForm* _GetFormByNumericID(unsigned int);

}  // namespace fnv_009f0740

// Calls the base loader, resolves the stored form IDs to MobileObject/TESObjectREFR pointers, then loads the Conversation if present.
// @fnv 0x009f0740
// src: XBOX_PDB 0x009f0740
void DialoguePackage::InitLoadGame_009f0740(BGSLoadFormBuffer* apLoadGameBuffer)
{
    using namespace fnv_009f0740;
    ((PackageReferenceSupport*)this)->DispatchToSubobjects(apLoadGameBuffer);

    m_pkMobileObject =
        m_pkMobileObject
            ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(m_pkMobileObject)))
            : 0;

    pActor = pActor ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(pActor))) : 0;

    pTargetActor = pTargetActor
                       ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(pTargetActor)))
                       : 0;

    m_pLinkedReference =
        m_pLinkedReference
            ? dynamic_cast<MobileObject*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(m_pLinkedReference)))
            : 0;

    m_pkReference =
        m_pkReference ? dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(reinterpret_cast<unsigned int>(m_pkReference)))
                      : 0;

    if (m_pkConversation)
    {
        ((fnv_009f0740::Conversation*)m_pkConversation)->InitLoadGame_0083c420(apLoadGameBuffer);
    }
}

struct Obj114;
struct Handle114;
struct Vec114
{
    float x, y, z;
};
struct String114
{
    unsigned int data;
    unsigned int size;
    String114();            // 0x4037b0
    String114(String114*);  // 0x4047f0
    ~String114();           // 0x4037d0
    void FUN_00438470(String114*);
    void* Modelloader_GetReferencedThis();
};
struct Handle114
{
    unsigned int a, b, c;
    Handle114(const Handle114&);  // 0x418900
    ~Handle114();                 // 0x483710
    void* Modelloader_GetReferencedThis();
    Handle114& BSAudio_GetSoundHandleByFilename();
    Handle114& FUN_00418900(const Handle114&);
    void FUN_00ad8be0(float, float);
    void FUN_00ad8b60(float, float, float);
    void FUN_00ad8f20(Obj114*);
    void FUN_00ad8870(int, int);
};
struct Obj114
{
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00c();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01c();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02c();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03c();
    virtual void virtual040();
    virtual void v44(Obj114*, int, int, int, int, int);
    virtual void virtual048();
    virtual void virtual04c();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05c();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06c();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07c();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08c();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09c();
    virtual void virtual0a0();
    virtual void virtual0a4();
    virtual void virtual0a8();
    virtual void virtual0ac();
    virtual void virtual0b0();
    virtual void virtual0b4();
    virtual void virtual0b8();
    virtual void virtual0bc();
    virtual void virtual0c0();
    virtual void virtual0c4();
    virtual void virtual0c8();
    virtual void virtual0cc();
    virtual void virtual0d0();
    virtual void virtual0d4();
    virtual void virtual0d8();
    virtual void virtual0dc();
    virtual void virtual0e0();
    virtual void virtual0e4();
    virtual void virtual0e8();
    virtual void virtual0ec();
    virtual void virtual0f0();
    virtual void virtual0f4();
    virtual void virtual0f8();
    virtual void virtual0fc();
    virtual bool v100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10c();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual bool v11c();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12c();
    virtual void virtual130();
    virtual void virtual134();
    virtual void virtual138();
    virtual void virtual13c();
    virtual void virtual140();
    virtual void virtual144();
    virtual void virtual148();
    virtual void virtual14c();
    virtual void virtual150();
    virtual void virtual154();
    virtual void virtual158();
    virtual void virtual15c();
    virtual void virtual160();
    virtual void virtual164();
    virtual void virtual168();
    virtual void virtual16c();
    virtual void virtual170();
    virtual void virtual174();
    virtual void virtual178();
    virtual void virtual17c();
    virtual void virtual180();
    virtual void virtual184();
    virtual void virtual188();
    virtual void virtual18c();
    virtual void virtual190();
    virtual void virtual194();
    virtual void virtual198();
    virtual void virtual19c();
    virtual void virtual1a0();
    virtual void virtual1a4();
    virtual void virtual1a8();
    virtual void virtual1ac();
    virtual void virtual1b0();
    virtual void virtual1b4();
    virtual void virtual1b8();
    virtual void virtual1bc();
    virtual void virtual1c0();
    virtual void virtual1c4();
    virtual void virtual1c8();
    virtual void virtual1cc();
    virtual Obj114* v1d0();
    virtual void virtual1d4();
    virtual void virtual1d8();
    virtual void virtual1dc();
    virtual void virtual1e0();
    virtual Obj114* v1e4();
    virtual void virtual1e8();
    virtual void virtual1ec();
    virtual void virtual1f0();
    virtual Vec114& v1f4();
    virtual void virtual1f8();
    virtual void virtual1fc();
    virtual void v200(int);
    virtual void virtual204();
    virtual void virtual208();
    virtual void virtual20c();
    virtual void virtual210();
    virtual void virtual214();
    virtual void virtual218();
    virtual void virtual21c();
    virtual void virtual220();
    virtual void virtual224();
    virtual void virtual228();
    virtual bool v22c(int);
    virtual void virtual230();
    virtual void virtual234();
    virtual void virtual238();
    virtual void virtual23c();
    virtual void virtual240();
    virtual void virtual244();
    virtual void virtual248();
    virtual void virtual24c();
    virtual void virtual250();
    virtual void virtual254();
    virtual void virtual258();
    virtual void virtual25c();
    virtual void virtual260();
    virtual void virtual264();
    virtual void virtual268();
    virtual void virtual26c();
    virtual void virtual270();
    virtual void virtual274();
    virtual void virtual278();
    virtual void virtual27c();
    virtual void virtual280();
    virtual float v284(void*, Handle114*, Obj114*, Obj114*, void*, Obj114*, Obj114*, Obj114*, int, int, int, int, int);
    virtual void virtual288();
    virtual void virtual28c();
    virtual void virtual290();
    virtual void virtual294();
    virtual void virtual298();
    virtual void virtual29c();
    virtual void virtual2a0();
    virtual void virtual2a4();
    virtual void virtual2a8();
    virtual void virtual2ac();
    virtual void virtual2b0();
    virtual void virtual2b4();
    virtual void virtual2b8();
    virtual void virtual2bc();
    virtual void virtual2c0();
    virtual void virtual2c4();
    virtual void virtual2c8();
    virtual void virtual2cc();
    virtual void virtual2d0();
    virtual void virtual2d4();
    virtual void virtual2d8();
    virtual void virtual2dc();
    virtual void virtual2e0();
    virtual void virtual2e4();
    virtual bool v2e8();
    virtual void virtual2ec();
    virtual void virtual2f0();
    virtual void virtual2f4();
    virtual void virtual2f8();
    virtual void virtual2fc();
    virtual void virtual300();
    virtual void virtual304();
    virtual void virtual308();
    virtual void virtual30c();
    virtual void virtual310();
    virtual void virtual314();
    virtual void virtual318();
    virtual void virtual31c();
    virtual void virtual320();
    virtual void virtual324();
    virtual void virtual328();
    virtual void virtual32c();
    virtual void virtual330();
    virtual void virtual334();
    virtual void virtual338();
    virtual void virtual33c();
    virtual void virtual340();
    virtual void virtual344();
    virtual void virtual348();
    virtual void virtual34c();
    virtual void virtual350();
    virtual void virtual354();
    virtual void virtual358();
    virtual void virtual35c();
    virtual void virtual360();
    virtual void virtual364();
    virtual void virtual368();
    virtual bool v36c();
    virtual void virtual370();
    virtual void v374(int);
    virtual bool v378();
    virtual int v37c();
    virtual void v380(int);
    virtual void virtual384();
    virtual void virtual388();
    virtual void virtual38c();
    virtual void virtual390();
    virtual void virtual394();
    virtual void virtual398();
    virtual void virtual39c();
    virtual void virtual3a0();
    virtual void virtual3a4();
    virtual void virtual3a8();
    virtual void virtual3ac();
    virtual void virtual3b0();
    virtual void virtual3b4();
    virtual void virtual3b8();
    virtual void virtual3bc();
    virtual void virtual3c0();
    virtual void virtual3c4();
    virtual void virtual3c8();
    virtual void virtual3cc();
    virtual void virtual3d0();
    virtual void virtual3d4();
    virtual void virtual3d8();
    virtual void virtual3dc();
    virtual void virtual3e0();
    virtual void virtual3e4();
    virtual void virtual3e8();
    virtual void virtual3ec();
    virtual void virtual3f0();
    virtual void virtual3f4();
    virtual void virtual3f8();
    virtual void virtual3fc();
    virtual void virtual400();
    virtual void virtual404();
    virtual void virtual408();
    virtual void virtual40c();
    virtual void virtual410();
    virtual void virtual414();
    virtual void virtual418();
    virtual void virtual41c();
    virtual void virtual420();
    virtual void virtual424();
    virtual void virtual428();
    virtual void virtual42c();
    virtual void virtual430();
    virtual void virtual434();
    virtual void virtual438();
    virtual void virtual43c();
    virtual void virtual440();
    virtual void virtual444();
    virtual void virtual448();
    virtual void virtual44c();
    virtual void virtual450();
    virtual void virtual454();
    virtual void virtual458();
    virtual void virtual45c();
    virtual void virtual460();
    virtual void virtual464();
    virtual void virtual468();
    virtual void virtual46c();
    virtual void virtual470();
    virtual void virtual474();
    virtual void virtual478();
    virtual void virtual47c();
    virtual void virtual480();
    virtual void virtual484();
    virtual void virtual488();
    virtual void virtual48c();
    virtual void virtual490();
    virtual void virtual494();
    virtual void virtual498();
    virtual void virtual49c();
    virtual void virtual4a0();
    virtual void virtual4a4();
    virtual void virtual4a8();
    virtual void virtual4ac();
    virtual void virtual4b0();
    virtual void virtual4b4();
    virtual void virtual4b8();
    virtual void virtual4bc();
    virtual void virtual4c0();
    virtual void virtual4c4();
    virtual void virtual4c8();
    virtual void virtual4cc();
    virtual void virtual4d0();
    virtual void virtual4d4();
    virtual void virtual4d8();
    virtual void virtual4dc();
    virtual void virtual4e0();
    virtual void virtual4e4();
    virtual void virtual4e8();
    virtual void virtual4ec();
    virtual void virtual4f0();
    virtual void virtual4f4();
    virtual void virtual4f8();
    virtual void virtual4fc();
    virtual void virtual500();
    virtual void virtual504();
    virtual void virtual508();
    virtual void virtual50c();
    virtual void virtual510();
    virtual void virtual514();
    virtual void virtual518();
    virtual void virtual51c();
    virtual void virtual520();
    virtual void virtual524();
    virtual void virtual528();
    virtual void virtual52c();
    virtual void virtual530();
    virtual void virtual534();
    virtual void virtual538();
    virtual void virtual53c();
    virtual void virtual540();
    virtual void virtual544();
    virtual void virtual548();
    virtual void virtual54c();
    virtual void virtual550();
    virtual void virtual554();
    virtual void virtual558();
    virtual void virtual55c();
    virtual void virtual560();
    virtual void virtual564();
    virtual void virtual568();
    virtual void virtual56c();
    virtual void virtual570();
    virtual void virtual574();
    virtual void virtual578();
    virtual void virtual57c();
    virtual void virtual580();
    virtual void virtual584();
    virtual void virtual588();
    virtual void virtual58c();
    virtual void virtual590();
    virtual void virtual594();
    virtual void virtual598();
    virtual void virtual59c();
    virtual void virtual5a0();
    virtual void virtual5a4();
    virtual void virtual5a8();
    virtual void virtual5ac();
    virtual void virtual5b0();
    virtual void virtual5b4();
    virtual void virtual5b8();
    virtual void virtual5bc();
    virtual void virtual5c0();
    virtual void virtual5c4();
    virtual void virtual5c8();
    virtual void virtual5cc();
    virtual void virtual5d0();
    virtual void virtual5d4();
    virtual void virtual5d8();
    virtual void virtual5dc();
    virtual void virtual5e0();
    virtual void virtual5e4();
    virtual void virtual5e8();
    virtual void virtual5ec();
    virtual void virtual5f0();
    virtual void virtual5f4();
    virtual void virtual5f8();
    virtual void virtual5fc();
    virtual void virtual600();
    virtual void virtual604();
    virtual void virtual608();
    virtual void virtual60c();
    virtual void virtual610();
    virtual void virtual614();
    virtual void virtual618();
    virtual void virtual61c();
    virtual void virtual620();
    virtual void virtual624();
    virtual void virtual628();
    virtual void virtual62c();
    virtual void virtual630();
    virtual void v634(Obj114*);
    virtual void virtual638();
    virtual void virtual63c();
    virtual void virtual640();
    virtual void v644(int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned char flag80;
    Obj114* FUN_008d8520();
    void Conversation_FirstItem();
    Obj114* FUN_0083c820();
    void FUN_0083c7b0();
    void NextResponse_0083c7e0();
    void Conversation_NextItem();
    Obj114* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    Obj114* NiAVObject_GetParent();
    void MobileObject_StopCurrentDialogue();
    Obj114* BGSSaveFormBuffer_GetForm();
    Handle114 PlaySoundByFormID(Obj114*, int, unsigned int, int);
    void FUN_0083c850(int);
    void SetFlag86(bool);
    Obj114* FUN_0044ddc0();
    bool GetField24();
    Obj114* FUN_00441110();
    Obj114* FUN_006815c0();
    void* BSStringT_char_Length();
    Obj114* BGSExplosion_GetImpactDataSet();
    String114* TESDataHandler_GetWorldSpaceList();
    void* Modelloader_GetReferencedThis();
    bool BSSoundHandle_BSSoundHandle_008c1bc0();
};
struct Manager114
{
    Handle114 BSAudio_GetSoundHandleByFilename(char*, unsigned int, int);
    void BSAudioManager_SetCompletionCallback(void*, void (*)(), Obj114*);
};
extern Manager114* __cdecl BSAudioManager_QInstance_00ad9060();
void MobileObject_SoundFileCallBack();
void MobileObject_DialogueConversationCallBack();
extern Setting DAT_011e05ec, DAT_011d8928;
extern unsigned char DAT_011f122d;
struct Player114
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    void* process;
};
extern Player114* DAT_011dea3c;
void __cdecl Warning_005b5e40(const char*, ...);
void __cdecl FUN_00406d30(char*, unsigned int, void*);
Manager114* __cdecl BSAudio_QInstance();
float __cdecl BSAudio_GetMaxDialogDist();
float __cdecl BSAudio_GetMinDialogDist();
void __cdecl Interface_ShowSubtitle(void*, Handle114, Vec114, Obj114*, int);
// The checked header lacks the dialogue processing method and these two helpers.
// Reuse its fields through typed views in the method body.
struct PackageDialogueSupport : DialoguePackage
{
    bool GetByteAtBC();
    void FUN_00705b10(Obj114*);
    void DialoguePackage_Speak(bool process);
};

// @fnv 0x009ee0a0
// src: XBOX_PDB 0x009ee0a0
void PackageDialogueSupport::DialoguePackage_Speak(bool process)
{
    bool started15 = false;
    bool reset26 = true;
    if ((reinterpret_cast<Obj114*&>(m_pkMobileObject) && !reinterpret_cast<Obj114*&>(m_pkMobileObject)->flag80) || reinterpret_cast<Obj114*&>(pActor)->FUN_008d8520()->v11c())
        return;
    if (!reinterpret_cast<bool&>(flags))
    {
        if (!reinterpret_cast<Obj114*&>(item))
        {
            started15 = true;
            if (!reinterpret_cast<Obj114*&>(conversation))
            {
                reinterpret_cast<Obj114*&>(pActor)->v200(1);
                reinterpret_cast<Obj114*&>(pTargetActor)->v200(1);
                return;
            }
            if (GetByteAtBC() && !reinterpret_cast<bool&>(unkC1))
            {
                reinterpret_cast<Obj114*&>(pTargetActor)->FUN_008d8520()->v644(1);
                reinterpret_cast<Obj114*&>(pTargetActor)->FUN_008d8520()->v634(reinterpret_cast<Obj114*&>(pActor));
            }
            reinterpret_cast<Obj114*&>(conversation)->Conversation_FirstItem();
            reinterpret_cast<Obj114*&>(item) = reinterpret_cast<Obj114*&>(conversation)->FUN_0083c820();
            if (reinterpret_cast<Obj114*&>(item))
            {
                reinterpret_cast<Obj114*&>(item)->FUN_0083c7b0();
                reinterpret_cast<Obj114*&>(response) = reinterpret_cast<Obj114*&>(item)->FUN_0083c820();
            }
            else
            {
                reinterpret_cast<Obj114*&>(pActor)->v200(1);
                if (!GetDialogueDoNotControlTarget())
                    reinterpret_cast<Obj114*&>(pTargetActor)->v200(1);
            }
        }
        else if (reinterpret_cast<Obj114*&>(response))
        {
            reinterpret_cast<Obj114*&>(item)->NextResponse_0083c7e0();
            reinterpret_cast<Obj114*&>(response) = reinterpret_cast<Obj114*&>(item)->FUN_0083c820();
        }
        if (reinterpret_cast<Obj114*&>(pActor))
        {
            if (!reinterpret_cast<Obj114*&>(pActor)->v2e8() && !reinterpret_cast<Obj114*&>(pActor)->v22c(0))
            {
                if (!reinterpret_cast<Obj114*&>(response))
                {
                    reinterpret_cast<Obj114*&>(conversation)->Conversation_NextItem();
                    reinterpret_cast<Obj114*&>(item) = reinterpret_cast<Obj114*&>(conversation)->FUN_0083c820();
                }
            }
            else if (!reinterpret_cast<Obj114*&>(response))
                reinterpret_cast<Obj114*&>(item) = 0;
        }
    }
    if (reinterpret_cast<Obj114*&>(item))
    {
        if (!reinterpret_cast<Obj114*&>(response))
        {
            reinterpret_cast<Obj114*&>(item)->FUN_0083c7b0();
            reinterpret_cast<Obj114*&>(response) = reinterpret_cast<Obj114*&>(item)->FUN_0083c820();
            if (!reinterpret_cast<Obj114*&>(response))
                Warning_005b5e40("AI: No responses found for conversation Topic Info (%08X).",
                             reinterpret_cast<Obj114*&>(item)->GetHavokWorldObjectCountInSceneGraph_0084e3a0()->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        }
        if (reinterpret_cast<Obj114*&>(response))
        {
            Obj114* actor18 = reinterpret_cast<Obj114*&>(item)->NiAVObject_GetParent();
            if (actor18->v100())
            {
                Obj114* speaker23 = reinterpret_cast<Obj114*&>(item)->NiAVObject_GetParent();
                if (speaker23 && process)
                {
                    String114 text6;
                    if (reinterpret_cast<Obj114*&>(m_pkMobileObject))
                    {
                        reinterpret_cast<Obj114*&>(m_pkMobileObject)->MobileObject_StopCurrentDialogue();
                        reinterpret_cast<Obj114*&>(m_pkMobileObject) = 0;
                    }
                    bool speak13 = true;
                    if (reinterpret_cast<Obj114*&>(response)->BGSSaveFormBuffer_GetForm() && reinterpret_cast<bool&>(unkCC))
                    {
                        Obj114* topic21 = reinterpret_cast<Obj114*&>(response)->BGSSaveFormBuffer_GetForm()->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                        Handle114 handle23 = speaker23->PlaySoundByFormID(topic21, 0, 0x40000102, 1);
                        Manager114* manager3 = BSAudioManager_QInstance_00ad9060();
                        manager3->BSAudioManager_SetCompletionCallback(handle23.Modelloader_GetReferencedThis(), MobileObject_SoundFileCallBack, reinterpret_cast<Obj114*&>(pActor)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                        reinterpret_cast<bool&>(unkCC) = false;
                        speak13 = false;
                    }
                    if (speak13 && reinterpret_cast<bool&>(unkCC))
                    {
                        text6.FUN_00438470(reinterpret_cast<Obj114*&>(response)->TESDataHandler_GetWorldSpaceList());
                        if (!speaker23->FUN_008d8520()->v37c() && !speaker23->FUN_008d8520()->v36c() &&
                            *DAT_011e05ec.FUN_00408d60() && !speaker23->FUN_008d8520()->v378())
                        {
                            reinterpret_cast<Obj114*&>(unkC4) = reinterpret_cast<Obj114*&>(response)->FUN_0044ddc0();
                            reinterpret_cast<Obj114*&>(unkC8) = reinterpret_cast<Obj114*&>(response)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
                            FUN_00705b10(reinterpret_cast<Obj114*&>(unkC4));
                            if (reinterpret_cast<Obj114*&>(item))
                                reinterpret_cast<Obj114*&>(item)->FUN_0083c850(0);
                            reinterpret_cast<Obj114*&>(m_pkMobileObject) = speaker23;
                            speaker23->SetFlag86(reinterpret_cast<Obj114*&>(response)->GetField24());
                            float duration13 = speaker23->v284(
                                text6.Modelloader_GetReferencedThis(), &reinterpret_cast<Handle114&>(unk80), reinterpret_cast<Obj114*&>(response)->FUN_0044ddc0(), reinterpret_cast<Obj114*&>(response)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                                reinterpret_cast<Obj114*&>(response)->FUN_006815c0()->BSStringT_char_Length(), reinterpret_cast<Obj114*&>(response)->NiAVObject_GetParent(),
                                reinterpret_cast<Obj114*&>(response)->FUN_00441110(), reinterpret_cast<Obj114*&>(pTargetActor), 1, 0, 1, 1, reinterpret_cast<bool&>(unkA0));
                            if (reinterpret_cast<Obj114*&>(m_pLinkedReference))
                            {
                                Obj114* data15 = reinterpret_cast<Obj114*&>(m_pLinkedReference)->BGSSaveFormBuffer_GetForm();
                                if (data15->BGSExplosion_GetImpactDataSet() == speaker23)
                                {
                                    Obj114* target20 = reinterpret_cast<Obj114*&>(pTargetActor);
                                    if (reinterpret_cast<Obj114*&>(pTargetActor) == reinterpret_cast<Obj114*&>(m_pLinkedReference))
                                        target20 = reinterpret_cast<Obj114*&>(pActor);
                                    reinterpret_cast<Obj114*&>(m_pkMobileObject) = reinterpret_cast<Obj114*&>(m_pLinkedReference);
                                    reinterpret_cast<Obj114*&>(m_pLinkedReference)->SetFlag86(reinterpret_cast<Obj114*&>(response)->GetField24());
                                    duration13 = reinterpret_cast<Obj114*&>(m_pLinkedReference)->v284(
                                        text6.Modelloader_GetReferencedThis(), &reinterpret_cast<Handle114&>(unk80), reinterpret_cast<Obj114*&>(response)->FUN_0044ddc0(),
                                        reinterpret_cast<Obj114*&>(response)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), reinterpret_cast<Obj114*&>(response)->FUN_006815c0()->BSStringT_char_Length(),
                                        reinterpret_cast<Obj114*&>(response)->NiAVObject_GetParent(), reinterpret_cast<Obj114*&>(response)->FUN_00441110(), target20, 0, 0, 0, 1, 1);
                                }
                            }
                            if (speaker23->FUN_008d8520()->v36c())
                                reinterpret_cast<bool&>(flags) = true;
                            else
                            {
                                Manager114* manager228 = BSAudioManager_QInstance_00ad9060();
                                manager228->BSAudioManager_SetCompletionCallback(reinterpret_cast<Handle114&>(unk80).Modelloader_GetReferencedThis(), MobileObject_DialogueConversationCallBack, reinterpret_cast<Obj114*&>(pActor)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                                if (reinterpret_cast<Obj114*&>(pActor) != reinterpret_cast<Obj114*&>(pTargetActor))
                                    reinterpret_cast<float&>(state) = 50.0f;
                                speaker23->flag80 = 0;
                            }
                            return;
                        }
                        else
                        {
                            if (speaker23->FUN_008d8520()->v36c() && !speaker23->FUN_008d8520()->v378())
                                return;
                            else
                            {
                                if (!*DAT_011e05ec.FUN_00408d60() && reinterpret_cast<Obj114*&>(item))
                                    reinterpret_cast<Obj114*&>(item)->FUN_0083c850(0);
                                reinterpret_cast<Obj114*&>(m_pkMobileObject) = speaker23;
                                speaker23->SetFlag86(reinterpret_cast<Obj114*&>(response)->GetField24());
                                speaker23->v284(text6.Modelloader_GetReferencedThis(), &reinterpret_cast<Handle114&>(unk80), reinterpret_cast<Obj114*&>(response)->FUN_0044ddc0(),
                                                reinterpret_cast<Obj114*&>(response)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), reinterpret_cast<Obj114*&>(response)->FUN_006815c0()->BSStringT_char_Length(),
                                                reinterpret_cast<Obj114*&>(response)->NiAVObject_GetParent(), reinterpret_cast<Obj114*&>(response)->FUN_00441110(), reinterpret_cast<Obj114*&>(pTargetActor), 1, 0, 0, 1,
                                                reinterpret_cast<bool&>(unkA0));
                                if (reinterpret_cast<Obj114*&>(m_pLinkedReference))
                                {
                                    if (reinterpret_cast<Obj114*&>(m_pLinkedReference))
                                    {
                                        Obj114* data218 = reinterpret_cast<Obj114*&>(m_pLinkedReference)->BGSSaveFormBuffer_GetForm();
                                        if (data218->BGSExplosion_GetImpactDataSet() == speaker23)
                                        {
                                            Obj114* target24 = reinterpret_cast<Obj114*&>(pTargetActor);
                                            if (reinterpret_cast<Obj114*&>(pTargetActor) == reinterpret_cast<Obj114*&>(m_pLinkedReference))
                                                target24 = reinterpret_cast<Obj114*&>(pActor);
                                            reinterpret_cast<Obj114*&>(m_pkMobileObject) = reinterpret_cast<Obj114*&>(m_pLinkedReference);
                                            reinterpret_cast<Obj114*&>(m_pLinkedReference)->SetFlag86(reinterpret_cast<Obj114*&>(response)->GetField24());
                                            reinterpret_cast<Obj114*&>(m_pLinkedReference)->v284(text6.Modelloader_GetReferencedThis(), &reinterpret_cast<Handle114&>(unk80), reinterpret_cast<Obj114*&>(response)->FUN_0044ddc0(),
                                                        reinterpret_cast<Obj114*&>(response)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                                                        reinterpret_cast<Obj114*&>(response)->FUN_006815c0()->BSStringT_char_Length(),
                                                        reinterpret_cast<Obj114*&>(response)->NiAVObject_GetParent(), reinterpret_cast<Obj114*&>(response)->FUN_00441110(), target24, 0,
                                                        0, 0, 1, 1);
                                        }
                                    }
                                }
                                Manager114* manager334 = BSAudioManager_QInstance_00ad9060();
                                manager334->BSAudioManager_SetCompletionCallback(reinterpret_cast<Handle114&>(unk80).Modelloader_GetReferencedThis(), MobileObject_DialogueConversationCallBack, reinterpret_cast<Obj114*&>(pActor)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                                speaker23->flag80 = 0;
                                reset26 = false;
                                reinterpret_cast<Obj114*&>(m_pkMobileObject) = speaker23;
                                speaker23->FUN_008d8520()->v380(0);
                                reinterpret_cast<bool&>(flags) = false;
                                speaker23->FUN_008d8520()->v374(0);
                                if (reinterpret_cast<Obj114*&>(pActor) != reinterpret_cast<Obj114*&>(pTargetActor))
                                    reinterpret_cast<float&>(state) = 2.0f;
                                Obj114* obj21 = reinterpret_cast<Obj114*&>(m_pkMobileObject)->v1e4();
                                Obj114* obj25 = reinterpret_cast<Obj114*&>(pTargetActor)->v1e4();
                            }
                        }
                    }
                }
                if (reset26)
                {
                    if (reinterpret_cast<Obj114*&>(pActor)->FUN_008d8520())
                        reinterpret_cast<Obj114*&>(pActor)->FUN_008d8520()->v44(reinterpret_cast<Obj114*&>(pActor), 0, 2, 0, 1, 1);
                    if (reinterpret_cast<Obj114*&>(pActor) != reinterpret_cast<Obj114*&>(m_pkMobileObject) && reinterpret_cast<Obj114*&>(m_pkMobileObject) && reinterpret_cast<Obj114*&>(m_pkMobileObject)->FUN_008d8520())
                        reinterpret_cast<Obj114*&>(pTargetActor)->FUN_008d8520()->v44(reinterpret_cast<Obj114*&>(pTargetActor), 0, 2, 0, 1, 1);
                }
            }
            else if (actor18 && process)
            {
                char path27[512];
                String114 text22;
                String114 copy14(reinterpret_cast<Obj114*&>(response)->TESDataHandler_GetWorldSpaceList());
                if (reinterpret_cast<Obj114*&>(response)->TESDataHandler_GetWorldSpaceList()->Modelloader_GetReferencedThis())
                {
                    FUN_00406d30(path27, 512, reinterpret_cast<Obj114*&>(response)->TESDataHandler_GetWorldSpaceList()->Modelloader_GetReferencedThis());
                    if (reinterpret_cast<Obj114*&>(m_pkMobileObject))
                    {
                        reinterpret_cast<Obj114*&>(m_pkMobileObject)->MobileObject_StopCurrentDialogue();
                        reinterpret_cast<Obj114*&>(m_pkMobileObject) = 0;
                    }
                    text22.FUN_00438470(reinterpret_cast<Obj114*&>(response)->TESDataHandler_GetWorldSpaceList());
                    if (reinterpret_cast<Obj114*&>(m_pLinkedReference))
                    {
                        Obj114* data310 = reinterpret_cast<Obj114*&>(m_pLinkedReference)->BGSSaveFormBuffer_GetForm();
                        reinterpret_cast<Obj114*&>(m_pLinkedReference)->SetFlag86(reinterpret_cast<Obj114*&>(response)->GetField24());
                        reinterpret_cast<Obj114*&>(m_pkMobileObject) = reinterpret_cast<Obj114*&>(m_pLinkedReference);
                        reinterpret_cast<Obj114*&>(m_pLinkedReference)->v284(text22.Modelloader_GetReferencedThis(), &reinterpret_cast<Handle114&>(unk80), reinterpret_cast<Obj114*&>(response)->FUN_0044ddc0(), reinterpret_cast<Obj114*&>(response)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                                    reinterpret_cast<Obj114*&>(response)->FUN_006815c0()->BSStringT_char_Length(), reinterpret_cast<Obj114*&>(response)->NiAVObject_GetParent(),
                                    reinterpret_cast<Obj114*&>(response)->FUN_00441110(), reinterpret_cast<Obj114*&>(pTargetActor), 0, 0, 0, 1, 1);
                        Manager114* manager45 = BSAudioManager_QInstance_00ad9060();
                        manager45->BSAudioManager_SetCompletionCallback(reinterpret_cast<Handle114&>(unk80).Modelloader_GetReferencedThis(), MobileObject_DialogueConversationCallBack, reinterpret_cast<Obj114*&>(m_pLinkedReference)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
                        reinterpret_cast<Obj114*&>(m_pLinkedReference)->flag80 = 0;
                        reset26 = false;
                    }
                    else
                    {
                        unsigned int flags22 = 0x104;
                        flags22 |= 2;
                        reinterpret_cast<Handle114&>(unk80).FUN_00418900(BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(path27, flags22, 0));
                        Vec114 position1 = actor18->v1f4();
                        reinterpret_cast<Handle114&>(unk80).FUN_00ad8be0(BSAudio_GetMinDialogDist(), BSAudio_GetMaxDialogDist());
                        reinterpret_cast<Handle114&>(unk80).FUN_00ad8b60(position1.x, position1.y, position1.z);
                        reinterpret_cast<Handle114&>(unk80).FUN_00ad8f20(actor18->v1d0());
                        reinterpret_cast<Handle114&>(unk80).FUN_00ad8870(1, 0);
                    }
                }
                if ((this == DAT_011dea3c->process || DAT_011f122d) && reinterpret_cast<Obj114*&>(conversation)->FUN_0083c820() &&
                    reinterpret_cast<Obj114*&>(conversation)->FUN_0083c820()->FUN_0083c820() &&
                    reinterpret_cast<Obj114*&>(conversation)->FUN_0083c820()->FUN_0083c820()->FUN_006815c0()->Modelloader_GetReferencedThis())
                {
                    if (*DAT_011d8928.FUN_00408d60() || (actor18->v100() && actor18->BSSoundHandle_BSSoundHandle_008c1bc0()))
                        Interface_ShowSubtitle(reinterpret_cast<Obj114*&>(conversation)->FUN_0083c820()->FUN_0083c820()->FUN_006815c0()->Modelloader_GetReferencedThis(), reinterpret_cast<Handle114&>(unk80),
                                     actor18->v1f4(), reinterpret_cast<Obj114*&>(pTargetActor), 0);
                }
                if (reinterpret_cast<float&>(state) <= 0.0 && reinterpret_cast<Obj114*&>(pTargetActor) != actor18)
                    reinterpret_cast<float&>(state) = 10.0f;
            }
        }
    }
    else
    {
        reinterpret_cast<Obj114*&>(pActor)->v200(1);
        if (!GetDialogueDoNotControlTarget())
            reinterpret_cast<Obj114*&>(pTargetActor)->v200(1);
    }
}

struct Sound
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
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual int VCall130();
};
struct FUN_008579e0_shell
{
    void __thiscall TESSaveLoadGame_LoadGameDataOLD(void* buf, unsigned int n);
};
struct TimeGlobal : FUN_008579e0_shell
{
    unsigned int __thiscall GetTimeStamp();
};
struct DialogueLoadRecord
{
    unsigned int formID;
};
extern TESSaveLoadGame* DAT_011de45c;
TESForm* __cdecl _ref_004839c0(unsigned int a);
void __cdecl Warning_005b5e40(const char* fmt, ...);
void* __cdecl FUN_00ec43fb(void* a, int b, void* c, void* d, int e);
extern char DAT_01015718;
extern char DAT_010156a8;
extern char DAT_01015588;
extern char DAT_01015500;
extern char DAT_010154a0;
extern char DAT_01015440;
extern char DAT_01093108;
extern void* DAT_01183028;
extern void* DAT_01184720;
struct SLObj
{
    void __thiscall LoadFromSave();
    int __thiscall GetDialogueItemByIndex(unsigned short a);
};
// The shared base does not yet declare these save loading helpers.
struct PackageLoadSupport : DialoguePackage
{
    void __thiscall TESPackage_LoadGame();
    void __thiscall TESForm_LoadGameDataOLD(void*, unsigned int);
    void __thiscall TESForm_LoadNumericID(unsigned int*, int);
};
// @fnv 0x009efa50
void DialoguePackage::LoadSaveData()
{
    ((PackageLoadSupport*)this)->TESPackage_LoadGame();
    {
        unsigned short w18 = 0;
        int flag = 0;
        if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int i;
            DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&i, 4);
            if (i != 0x424c4f4b)
            {
                DialogueLoadRecord* rec = (DialogueLoadRecord*)DAT_011de45c->BGSProjectile_GetExplosion();
                if (rec != 0)
                {
                    TESForm* pForm = _ref_004839c0(rec->formID);
                    Warning_005b5e40(&DAT_01015718, &DAT_01093108, 0x239, rec->formID, ((Sound*)pForm)->VCall130(),
                                 *(unsigned char*)((char*)rec + 9), *(int*)((char*)rec + 5));
                }
                else
                {
                    Warning_005b5e40(&DAT_010156a8, &DAT_01093108, 0x239, DAT_011de45c->FUN_008df040());
                }
            }
            flag = DAT_011de45c->GetTimeStamp();
            DAT_011de45c->TESSaveLoadGame_LoadGameDataOLD(&w18, 2);
        }
        ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&state, 4);
        if ((int)DAT_011de45c->FUN_008df040() >= 0x6a)
        {
            ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&flags, 1);
        }
        unsigned int id;
        ((PackageLoadSupport*)this)->TESForm_LoadNumericID(&id, 4);
        m_pkMobileObject = (MobileObject*)id;
        unsigned int a18;
        ((PackageLoadSupport*)this)->TESForm_LoadNumericID(&a18, 4);
        pActor = (MobileObject*)a18;
        unsigned int a10;
        ((PackageLoadSupport*)this)->TESForm_LoadNumericID(&a10, 4);
        pTargetActor = (MobileObject*)a10;
        unsigned int a14;
        ((PackageLoadSupport*)this)->TESForm_LoadNumericID(&a14, 4);
        topic = (unsigned int)dynamic_cast<TESTopic*>(_ref_004839c0(a14));
        if ((int)DAT_011de45c->FUN_008df040() >= 0x20)
        {
            unsigned short w34;
            ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&w34, 2);
            if (w34 != 0)
            {
                conversation = (Conversation*)new FUN_0083b830;
                ((SLObj*)conversation)->LoadFromSave();
                short w38;
                ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&w38, 2);
                if (w38 != -1)
                {
                    item = (DialogueItem*)((SLObj*)conversation)->GetDialogueItemByIndex((unsigned short)w38);
                }
                else
                {
                    item = 0;
                }
                short w3c;
                ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&w3c, 2);
                response = (DialogueResponse*)w3c;
                if (item != 0 && w3c != -1)
                {
                    response = ((DialogueItem*)item)->GetResponseByIndex((unsigned short)w3c);
                }
                else
                {
                    response = 0;
                }
            }
        }
        if ((int)DAT_011de45c->FUN_008df040() < 0x20)
        {
            unsigned int a40;
            ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&a40, 4);
            conversation = (Conversation*)a40;
            if (a40 != 0)
            {
                short w44;
                ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&w44, 2);
                item = (DialogueItem*)w44;
                short w48;
                ((PackageLoadSupport*)this)->TESForm_LoadGameDataOLD(&w48, 2);
                response = (DialogueResponse*)w48;
            }
            else
            {
                item = 0;
                response = 0;
            }
        }
        if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
        {
            unsigned int ts = DAT_011de45c->GetTimeStamp();
            DialogueLoadRecord* tag = (DialogueLoadRecord*)DAT_011de45c->BGSProjectile_GetExplosion();
            if (tag != 0)
            {
                TESForm* snd = _ref_004839c0(tag->formID);
                if ((unsigned int)ts > (unsigned int)w18 + (unsigned int)flag)
                {
                    Warning_005b5e40(&DAT_01015588, (int)((unsigned int)ts - ((unsigned int)w18 + (unsigned int)flag)),
                                 &DAT_01093108, 0x288, tag->formID, ((Sound*)snd)->VCall130(),
                                 *(unsigned char*)((char*)tag + 9), *(int*)((char*)tag + 5));
                }
                else if ((unsigned int)ts < (unsigned int)w18 + (unsigned int)flag)
                {
                    Warning_005b5e40(&DAT_01015500, (int)(((unsigned int)w18 + (unsigned int)flag) - (unsigned int)ts),
                                 &DAT_01093108, 0x288, tag->formID, ((Sound*)snd)->VCall130(),
                                 *(unsigned char*)((char*)tag + 9), *(int*)((char*)tag + 5));
                }
            }
            else
            {
                if ((unsigned int)ts > (unsigned int)w18 + (unsigned int)flag)
                {
                    Warning_005b5e40(&DAT_010154a0, (int)((unsigned int)ts - ((unsigned int)w18 + (unsigned int)flag)),
                                 &DAT_01093108, 0x288, DAT_011de45c->FUN_008df040());
                }
                else if ((unsigned int)ts < (unsigned int)w18 + (unsigned int)flag)
                {
                    Warning_005b5e40(&DAT_01015440, (int)(((unsigned int)w18 + (unsigned int)flag) - (unsigned int)ts),
                                 &DAT_01093108, 0x288, DAT_011de45c->FUN_008df040());
                }
            }
        }
    }
}

// The shared class does not yet declare its response-selection helper.
// This adds only that declaration and inherits the checked layout unchanged.
struct DialogueItemSelection : DialogueItem
{
    void SelectResponse(DialogueResponse* response);
};

namespace fnv_009eff60 {
TESForm* TESForm_GetFormByNumericID(unsigned int formID);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* object);

extern TESSaveLoadGame* g_TESSaveLoadGame;

class Conversation
{
  public:
    DialogueItem* currentItem;
    Character* speaker;
    PlayerCharacter* listener;
    Conversation(Character* speaker, PlayerCharacter* listener, TESTopic* topic);
    void InitLoadGameTES_0083c220();
    DialogueItem* GetDialogueItemByIndex(short index);
    void FUN_0083c8a0(DialogueItem* item);
};

// The shared base does not yet declare this reference fixup helper.
struct PackageResolveSupport : DialoguePackage
{
    void TESPackage_InitLoadGame();
};

}  // namespace fnv_009eff60

// Resolves target, speaker and listener from stored IDs, then rebuilds the conversation, item and response from saved indices.
// @fnv 0x009eff60
void DialoguePackage::ResolveReferences()
{
    using namespace fnv_009eff60;
    ((PackageResolveSupport*)this)->TESPackage_InitLoadGame();
    // Serialized actor IDs are resolved in target, pActor, listener order.
    unsigned int listenerID = (unsigned int)target;
    target = dynamic_cast<Actor*>(TESForm_GetFormByNumericID(listenerID));
    unsigned int targetID;
    unsigned int speakerID = (unsigned int)pActor;
    pActor = dynamic_cast<Actor*>(TESForm_GetFormByNumericID(speakerID));
    targetID = (unsigned int)listener;
    listener = dynamic_cast<Actor*>(TESForm_GetFormByNumericID(targetID));

    if (g_TESSaveLoadGame->FUN_008df040() >= 32 && conversation)
        ((fnv_009eff60::Conversation*)conversation)->InitLoadGameTES_0083c220();
    if (g_TESSaveLoadGame->FUN_008df040() < 32)
    {
        // Retain the saved conversation marker and its two serialized indices.
        fnv_009eff60::Conversation* itemIndex = (fnv_009eff60::Conversation*)conversation;
        short oldConversation = (short)(unsigned int)item;
        short responseIndex = (short)(unsigned int)response;
        if (itemIndex)
        {
            conversation = (::Conversation*)new fnv_009eff60::Conversation((Character*)pActor, (PlayerCharacter*)listener, (TESTopic*)topic);
            if (oldConversation != -1)
                item = ((fnv_009eff60::Conversation*)conversation)->GetDialogueItemByIndex(oldConversation);
            else
                item = 0;
            if (item && responseIndex != -1)
                response = item->GetResponseByIndex(responseIndex);
            else
                response = 0;
            ((fnv_009eff60::Conversation*)conversation)->FUN_0083c8a0(item);
            ((DialogueItemSelection*)item)->SelectResponse(response);
        }
    }
}

class TESSaveLoadGame;
namespace fnv_009ef6e0 {
struct DialogueSaveRecord
{
    unsigned int formID;
    unsigned char type;
    unsigned char flags;
};
class DialogueSaveGameWriter
{
  public:
    unsigned int FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(void*, int);
    unsigned char FUN_008df040();
    DialogueSaveRecord* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern Setting g_011de4e8;
// Retained: Conversation.h is absent; 0x0083bb30 and 0x0083ba50 are conversation.cpp size/index methods.
class Conversation
{
  public:
    unsigned short GetSaveSize_0083bb30();
    void SaveConversation();
    short GetDialogueItemIndex(DialogueItem*);
};
TESForm* TESForm_GetFormByNumericID(unsigned int);
void ProgramFlow(const char*, ...);
void FNV_Warning(const char*, ...);

}  // namespace fnv_009ef6e0

// Writes the DialoguePackage state, topic, quest, info, speaker, conversation item and response indices to the save-game writer, then patches the block size.
// @fnv 0x009ef6e0
// src: XBOX_PDB 0x009ef6e0
void DialoguePackage::SaveGame_009ef6e0()
{
    using namespace fnv_009ef6e0;
    SavePackage();
    unsigned short size5 = 0;    // blockSize
    unsigned short* offset = 0;  // blockStart
    // Initial save position.
    unsigned int saved7 = ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_00825c00();
    if (*g_011de4e8.Bool())
        saved7 = ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_00825c00();
    if (((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int blockTag = 0x424c4f4b;
        ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&blockTag, 4);
        offset = (unsigned short*)((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_00825c00();
        ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&size5, 2);
    }
    TESForm_SaveGameDataOLD(&state, 4);
    if (((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_008df040() >= 106)
        TESForm_SaveGameDataOLD(&flags, 1);
    unsigned int form7 = 0;  // topicID
    if (m_pkMobileObject)
        form7 = m_pkMobileObject->GetFormID();
    ForwardToSaveLoadGame(&form7, 4);
    unsigned int form2 = 0;
    if (quest)
        form2 = quest->GetFormID();
    ForwardToSaveLoadGame(&form2, 4);
    unsigned int formVal = 0;  // infoID
    if (info)
        formVal = info->GetFormID();
    ForwardToSaveLoadGame(&formVal, 4);
    unsigned int form5 = 0;  // speakerID
    if (speaker)
        form5 = speaker->GetFormID();
    ForwardToSaveLoadGame(&form5, 4);
    unsigned short countB = 0;  // count
    if (conversation)
        countB = ((fnv_009ef6e0::Conversation*)conversation)->GetSaveSize_0083bb30();
    ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->TESSaveLoadGame_SaveGameDataOLD(&countB, 2);
    if (countB)
    {
        ((fnv_009ef6e0::Conversation*)conversation)->SaveConversation();
        short itemIndex = -1;
        if (item)
            itemIndex = ((fnv_009ef6e0::Conversation*)conversation)->GetDialogueItemIndex(item);
        TESForm_SaveGameDataOLD(&itemIndex, 2);
        short responseIndex = -1;
        if (item && response)
            responseIndex = item->GetResponseIndex(response);
        TESForm_SaveGameDataOLD(&responseIndex, 2);
    }
    if (*g_011de4e8.Bool())
    {
        unsigned int end = ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_00825c00();
        DialogueSaveRecord* record = ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_004fd3e0();
        if (record)
        {
            TESForm* form = TESForm_GetFormByNumericID(record->formID);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s", end - saved7,
                         record->formID, form->GetName(), (unsigned int&)record->flags, 0x231,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", end - saved7, 0x231,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp");
        }
    }
    if (((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int end = ((DialogueSaveGameWriter*)fnv_009ef6e0::g_TESSaveLoadGame)->FUN_00825c00();
        unsigned int offset2 = (unsigned int)offset;
        if (end > offset2 + 0xffff)
            FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Ai\\DialoguePackage.cpp", 0x231);
        *offset = (unsigned short)(end - offset2);
    }
}

namespace fnv_009f0460 {
// The approved BGSLoadFormBuffer header lacks these loading helpers.
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned id);
struct List0083b830SV
{
    int a, b, c;
    List0083b830SV();
    void* operator new(unsigned);
    void* GetDialogueItemByIndex(unsigned short i);
    void LoadGameBGS_0083c330(BGSLoadFormBuffer* buf);
};
}  // namespace fnv_009f0460

// Loads the base package, reads fields from the buffer, and conditionally loads a list with two indexed selections.
// @fnv 0x009f0460
// src: XBOX_PDB 0x009f0460
void DialoguePackage::LoadGame_009f0460(BGSLoadFormBuffer* apSaveBuffer)
{
    using namespace fnv_009f0460;
    TESPackage::LoadGame(reinterpret_cast< ::BGSLoadFormBuffer*>(apSaveBuffer));
    apSaveBuffer->FUN_008648e0(&m_pkMobileObject);
    apSaveBuffer->FUN_008648e0(&pActor);
    apSaveBuffer->FUN_008648e0(&pTargetActor);
    apSaveBuffer->FUN_008648e0(&m_pLinkedReference);
    apSaveBuffer->FUN_008648e0(&m_pkReference);
    topic = (unsigned int)dynamic_cast<TESTopic*>(TESForm_GetFormByNumericID(apSaveBuffer->FUN_008648a0()));
    apSaveBuffer->LoadData(&state, 4);
    apSaveBuffer->LoadData(&flags, 1);
    apSaveBuffer->LoadData(&unkBC, 1);
    apSaveBuffer->LoadData(&unkBD, 1);
    apSaveBuffer->LoadData(&unkBE, 1);
    apSaveBuffer->LoadData(&unkBF, 1);
    apSaveBuffer->LoadData(&unkC0, 1);
    apSaveBuffer->LoadData(&unkC1, 1);
    apSaveBuffer->LoadData(&unkC4, 4);
    apSaveBuffer->LoadData(&unkC8, 4);
    apSaveBuffer->LoadData(&unkA0, 1);
    apSaveBuffer->LoadData(&unkCC, 1);
    if (apSaveBuffer->GetVersion() >= 3)
        apSaveBuffer->LoadData(&unkC2, 1);
    bool b = false;
    apSaveBuffer->LoadData(&b, 1);
    if (b)
    {
        conversation = (Conversation*)new List0083b830SV();
        ((List0083b830SV*)conversation)->LoadGameBGS_0083c330(apSaveBuffer);
        short i1 = -1;
        apSaveBuffer->LoadData(&i1, 2);
        if (i1 != -1)
            item = (DialogueItem*)((List0083b830SV*)conversation)->GetDialogueItemByIndex(i1);
        short i2 = -1;
        apSaveBuffer->LoadData(&i2, 2);
        if (item && i2 != -1)
            response = item->GetResponseByIndex(i2);
    }
}

