#include "../../include/BSStringT.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSTalkingActivator.h"
#include "../../include/FormChangeMask.h"
#include "../../include/TESSound.h"
#include "../../include/TESWaterForm.h"
#include "../../include/EffectSetting.h"
#include "../../include/CombatProcedure.h"

#undef LoadString
#undef CompareString

class TESFileFormVersion
{
public:
    unsigned short GetFormVersion();
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
#include <malloc.h>
#include "../../include/BGSSaveGameBuffer.h"

template <> BSStringT<char>::~BSStringT()
{
    Set(0, 0);
}

extern const char g_emptyTopicInfoPrompt[];
// Resets several fields to zero and sets the prompt pointer to g_emptyTopicInfoPrompt.
// @fnv 0x00510710
void TESObjectACTI::ResetFormData()
{
    m_pSoundEffect = 0;
    m_pLoopSound = 0;
    m_pWaterForm = 0;
    m_pTalkingActivator = 0;
    pRadioTemplate = 0;
    m_kActivationPrompt = g_emptyTopicInfoPrompt;
}
// @fnv 0x00510a90
bool TESObjectACTI::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct TextureChunk
            {
                int size;
                char* data;
            } textureChunk;
            textureChunk.size = file->GetChunkSize();
            textureChunk.data = (char*)_alloca(textureChunk.size);
            file->GetChunkData(textureChunk.data, textureChunk.size);
            ParseTextureSwapData(textureChunk.data, textureChunk.size,
                                 reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case 0x49524353: {
            unsigned int script = 0;
            file->GetChunkData(&script);
            reinterpret_cast<CombatProcedure*>((char*)this + 0x5c)
                ->Initialize(reinterpret_cast<CombatController*>(script));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x4d414e53: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            SetLoopingSound(reinterpret_cast<TESSound*>(sound));
            break;
        }
        case 0x4d414e56: {
            unsigned int water = 0;
            file->GetChunkData(&water);
            reinterpret_cast<EffectSetting*>(this)->SetEffectShader(reinterpret_cast<TESEffectShader*>(water));
            break;
        }
        case 0x4d414e49: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(reinterpret_cast<TESEffectShader*>(sound));
            break;
        }
        case 0x4d414e57: {
            unsigned int station = 0;
            file->GetChunkData(&station);
            reinterpret_cast<EffectSetting*>(this)->SetCastSound(reinterpret_cast<TESSound*>(station));
            break;
        }
        case 0x4d414e52: {
            unsigned int radioTemplate = 0;
            file->GetChunkData(&radioTemplate);
            reinterpret_cast<EffectSetting*>(this)->SetBoltSound(reinterpret_cast<TESSound*>(radioTemplate));
            break;
        }
        case 0x4f544158: {
            int size = file->GetChunkSize();
            if (size > 1)
            {
                char* text = new char[size];
                file->GetChunkData(text, size);
                SetActivationPrompt(BSStringT<char>(text));
                delete[] text;
            }
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_004fd3a0_shell : public TESObjectACTI
{
    TESSound* TESChallenge_GetFormOne();
};

// @fnv 0x004fd3a0
// src: COMMUNITY 0x004fd3a0
TESSound* FUN_004fd3a0_shell::TESChallenge_GetFormOne()
{
    return *(TESSound**)((char*)this + 0x74);
}

extern int DAT_01029ee0;

// @fnv 0x00510620
// src: EXE 0x00510620
void* __fastcall BGSOpenCloseForm_BGSOpenCloseForm(void** pThis)
{
    *pThis = &DAT_01029ee0;
    return pThis;
}

struct FloatValueProvider : public TESObjectACTI
{
    void TESObjectACTI_SetActivationPrompt(BSStringT<char> s);
};
// Sets the activation prompt at offset 0x88 to the given string.
// @fnv 0x00510ea0
// src: COMMUNITY 0x00510ea0
void FloatValueProvider::TESObjectACTI_SetActivationPrompt(BSStringT<char> s)
{
    m_kActivationPrompt.Set(s);
}

struct TESFullName_ext : TESFullName
{
    const char* GetFullName();
};

// @fnv 0x00511840
// src: XBOX_PDB 0x00511840
const char* __fastcall TESSound_GetFilename(char* apObject)
{
    return ((TESFullName_ext*)(apObject + 0x30))->GetFullName();
}

void _Deallocate(void*);
struct Holder005105F0 : TESObjectACTI
{
    void* FUN_005105f0(unsigned int);
};
// Destructs the TESObjectACTI base and, when flags has bit 0 set, deallocates this object; returns this.
// @fnv 0x005105f0
void* Holder005105F0::FUN_005105f0(unsigned int flags)
{
    this->TESObjectACTI::~TESObjectACTI();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00484d60_holder
{
    void SaveIfChanged(BGSSaveFormBuffer*);
};
struct FNStub
{
    const char* GetFullName() const;
};
struct FUN_00511860_holder
{
    void TESObjectACTI_SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x00511860
// src: XBOX_PDB 0x00511860
void FUN_00511860_holder::TESObjectACTI_SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    ((FUN_00484d60_holder*)this)->SaveIfChanged(apSaveGameBuffer);
    if (((BGSLoadFormBuffer*)apSaveGameBuffer)->GetChangeFlags(4).operator bool())
    {
        const char* pfullname = ((FNStub*)((char*)this + 0x30))->GetFullName();
        ((BGSSaveGameBuffer*)apSaveGameBuffer)->SaveGameString(pfullname, 0);
    }
}

struct QBase
{
    virtual void Foo();
    char _pad[44];
    QBase(int);
};
struct FUN_00837250 : QBase
{
    int field_30;
    FUN_00837250(unsigned int iflags);
};
// Calls the QBase constructor with 0 and stores the given flags in field_30.
// @fnv 0x00837250
FUN_00837250::FUN_00837250(unsigned int auiFlags) : QBase(0)
{
    field_30 = auiFlags;
}

struct FUN_005110e0_Holder
{
    char _pad[0x88];
    BSStringT<char> m_88;
    BSStringT<char> GetString();
};
// Returns the BSStringT<char> member at offset 0x88 of the holder.
// @fnv 0x005110e0
BSStringT<char> FUN_005110e0_Holder::GetString()
{
    return m_88;
}

struct FUN_00510770_shell : public TESObjectACTI
{
    void TESObjectACTI_InitItem();
};

struct BGSDestructibleObjectFormInitItemProxy
{
    void InitItem(TESForm* form);
};

struct TESModelTextureSwapInitItemProxy
{
    void InitItem(TESForm* form);
};

TESForm* _GetFormByNumericID(unsigned int formID);
void _FNV_Warning(const char* format, ...);

void BGSDestructibleObjectFormInitItemProxy::InitItem(TESForm* form)
{}

void TESModelTextureSwapInitItemProxy::InitItem(TESForm* form)
{}

// Resolves the activator's sound, water and radio-station form IDs, warns when a lookup fails, and initializes the scriptable, destructible and model sub-forms.
// @fnv 0x00510770
// src: XBOX_PDB 0x00510770
void FUN_00510770_shell::TESObjectACTI_InitItem()
{
    if (IsFormInitialized())
        return;

    reinterpret_cast<TESScriptableForm*>(reinterpret_cast<char*>(this) + 0x5C)->InitItem(this);
    reinterpret_cast<BGSDestructibleObjectFormInitItemProxy*>(reinterpret_cast<char*>(this) + 0x68)->InitItem(this);
    reinterpret_cast<TESModelTextureSwapInitItemProxy*>(reinterpret_cast<char*>(this) + 0x3C)->InitItem(this);

    unsigned int itempint = reinterpret_cast<unsigned int>(m_pSoundEffect);
    if (itempint)
    {
        RemapFormIDForFile(itempint, GetFile(-1));
        m_pSoundEffect = dynamic_cast<TESSound*>(_GetFormByNumericID(itempint));
        if (!m_pSoundEffect)
            _FNV_Warning("MASTERFILE: Could not find looping sound (%08X) for activator '%s' (%08X).", itempint,
                         GetName(), GetFormID());
    }

    itempint = reinterpret_cast<unsigned int>(m_pLoopSound);
    if (itempint)
    {
        RemapFormIDForFile(itempint, GetFile(-1));
        m_pLoopSound = dynamic_cast<TESSound*>(_GetFormByNumericID(itempint));
        if (!m_pLoopSound)
            _FNV_Warning("MASTERFILE: Could not find activate sound (%08X) for activator '%s' (%08X).", itempint,
                         GetName(), GetFormID());
    }

    itempint = reinterpret_cast<unsigned int>(pRadioTemplate);
    if (itempint)
    {
        RemapFormIDForFile(itempint, GetFile(-1));
        pRadioTemplate = dynamic_cast<TESSound*>(_GetFormByNumericID(itempint));
        if (!pRadioTemplate)
            _FNV_Warning("MASTERFILE: Could not find pRadioTemplate (%08X) for activator '%s' (%08X).", itempint,
                         GetName(), GetFormID());
    }

    itempint = reinterpret_cast<unsigned int>(m_pWaterForm);
    if (itempint)
    {
        RemapFormIDForFile(itempint, GetFile(-1));
        m_pWaterForm = dynamic_cast<TESWaterForm*>(_GetFormByNumericID(itempint));
        if (!m_pWaterForm)
            _FNV_Warning("MASTERFILE: Could not find water form (%08X) for activator '%s' (%08X).", itempint, GetName(),
                         GetFormID());
    }

    itempint = reinterpret_cast<unsigned int>(m_pTalkingActivator);
    if (itempint)
    {
        RemapFormIDForFile(itempint, GetFile(-1));
        m_pTalkingActivator = dynamic_cast<BGSTalkingActivator*>(_GetFormByNumericID(itempint));
        if (!m_pTalkingActivator || !m_pTalkingActivator->IsRadioStation())
        {
            _FNV_Warning("MASTERFILE: Could not find radio station (%08X) for activator '%s' (%08X).", itempint,
                         GetName(), GetFormID());
            m_pTalkingActivator = 0;
        }
    }

    SetInitializationState(true);
}

// BSStringT.h does not yet declare the string-to-string comparison at 0x00501c90.
struct BSStringComparison
{
    int CompareString(const BSStringT<char>* apOther, bool abCaseInsensitive);
};

struct ACTIView : public TESObjectACTI
{
    TESSound* GetLoopSoundA();
    TESForm* GetFormTwoA();
    TESForm* GetFormThreeA();
    TESSound* GetFormFourA();
    BSStringT<char> GetPromptA();
    bool CompareFormA(TESForm* apForm);
    bool TESObjectACTI_Compare(TESForm* apForm);
};

// @fnv 0x005111e0
// src: XBOX_PDB 0x005111e0
bool ACTIView::TESObjectACTI_Compare(TESForm* apForm)
{
    int iCompare;
    ACTIView* pOther = (ACTIView*)dynamic_cast<TESObjectACTI*>(apForm);
    if (!pOther)
        return true;
    if (GetLoopSoundA() != pOther->GetLoopSoundA())
        return true;
    if (GetFormTwoA() != pOther->GetFormTwoA())
        return true;
    if (GetFormThreeA() != pOther->GetFormThreeA())
        return true;
    if (GetAssociatedWaterForm() != pOther->GetAssociatedWaterForm())
        return true;
    if (GetFormFourA() != pOther->GetFormFourA())
        return true;
    iCompare = reinterpret_cast<BSStringComparison*>(&GetPromptA())->CompareString(&pOther->GetPromptA(), true);
    if (iCompare)
        return true;
    if (CompareFormA(pOther))
        return true;
    return false;
}

struct SoundId
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct Chunk487010
{
    int unk00;
    int unk04;
    int unk08;
    void Save_00487010();
};
struct Chunk48a520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct Chunk48cca0
{
    int unk00;
    int unk04;
    int unk08;
    void Save_0048cca0();
};
struct Chunk477f20
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00477f20();
};
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
void TESForm_AddChunkArray(unsigned int, void*, unsigned int);

struct ActiSave
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
    Chunk487010 name30;
    Chunk48a520 model3c;
    Chunk48cca0 script5c;
    Chunk477f20 destruct68;
    SoundId* m_pSoundEffect;
    SoundId* m_pLoopSound;
    SoundId* pRadioTemplate;
    SoundId* m_pWaterForm;
    SoundId* m_pTalkingActivator;
    BSStringT<char> m_kActivationPrompt;

    void BeginFormRecord();
    void FinishSave();
    BSStringT<char> GetString();
    void Save();
};

// Runs the base save, saves the name, model, script and destruction chunks, writes each sound id under its tag, then writes the text chunk and finishes the save.
// @fnv 0x00510f00
void ActiSave::Save()
{
    BeginFormRecord();
    name30.Save_00487010();
    model3c.ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    script5c.Save_0048cca0();
    destruct68.FUN_00477f20();
    if (m_pSoundEffect)
    {
        unsigned int uiSoundId = m_pSoundEffect->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e53, uiSoundId);
    }
    if (m_pLoopSound)
    {
        unsigned int uiSoundId = m_pLoopSound->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e56, uiSoundId);
    }
    if (pRadioTemplate)
    {
        unsigned int uiSoundId = pRadioTemplate->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e49, uiSoundId);
    }
    if (m_pWaterForm)
    {
        unsigned int uiSoundId = m_pWaterForm->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e57, uiSoundId);
    }
    if (m_pTalkingActivator)
    {
        unsigned int uiSoundId = m_pTalkingActivator->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e52, uiSoundId);
    }
    if (m_kActivationPrompt.Length() > 0)
    {
        TESForm_AddChunkArray(0x4f544158, (void*)GetString().String(), GetString().Length() + 1);
    }
    FinishSave();
}

struct FUN_00489100_cls
{
    void FUN_00489100(const char* src);
};
struct S_005118c0
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
    FUN_00489100_cls unk30;
    void FUN_00484da0(BGSLoadFormBuffer* stream);
    void TESObjectACTI_LoadGame(BGSLoadFormBuffer* stream);
};
// Reads a flag from the stream, and if set reads a string into buf and stores it in unk30.
// @fnv 0x005118c0
// src: XBOX_PDB 0x005118c0
void S_005118c0::TESObjectACTI_LoadGame(BGSLoadFormBuffer* stream)
{
    char buf[260];
    FUN_00484da0(stream);
    if (stream->GetChangeFlags(4).operator bool())
    {
        stream->LoadString(buf);
        unk30.FUN_00489100(buf);
    }
}

// TESObjectACTI destructor with natural TESBoundAnimObject, TESFullName,
// TESModelTextureSwap, script/destructible/open-close bases and BSString member.
struct FUN_0050f740
{
    virtual ~FUN_0050f740();
    unsigned unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    char* name;
    unsigned short length, capacity;
};
struct FUN_0048a490
{
    virtual ~FUN_0048a490();
    char* model;
    unsigned short length, capacity;
    unsigned char textureCount;
    void* textures;
    unsigned char modelFlags;
    void* swaps;
    void* nextSwap;
};
struct Scriptable476
{
    virtual void Method();
    void* script;
    bool initialized;
};
struct FUN_00475380
{
    virtual ~FUN_00475380();
    void* data;
};
struct OpenClose476
{
    virtual void Method();
};
struct FUN_00510640 : FUN_0050f740, FUN_00591300, FUN_0048a490, Scriptable476, FUN_00475380, OpenClose476
{
    void* loopingSound;
    void* activationSound;
    void* radioTemplate;
    void* water;
    void* radioStation;
    BSStringT<char> activationPrompt;
    virtual ~FUN_00510640();
};
// @fnv 0x00510640
FUN_00510640::~FUN_00510640()
{}

class ActiV511
{
  public:
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual TESWaterForm* GetWaterForm();

    TESSound* TESChallenge_GetFormOne();
    TESEffectShader* FUN_00407840();
    TESSound* GetEffectShader_00407820();
    TESSound* BGSProjectile_GetExplosion();
    BSStringT<char> GetString();

    void FUN_004febb0(TESSound* pkSound);
    void FUN_004febd0(TESEffectShader* pkShader);
    void FUN_00442a80(TESSound* pkSound);
    void SetWaterForm(TESWaterForm* pkWater);
    void FUN_004fb090(TESSound* pkSound);
    void TESForm_CopyAllComponents(TESForm* pkForm);

    void TESObjectACTI_Copy(TESForm* pkForm);
};

// @fnv 0x00511120
// src: XBOX_PDB 0x00511120
void ActiV511::TESObjectACTI_Copy(TESForm* pkForm)
{
    ActiV511* pkActi = (ActiV511*)dynamic_cast<TESObjectACTI*>(pkForm);
    if (!pkActi)
        return;

    FUN_004febb0(pkActi->TESChallenge_GetFormOne());
    FUN_004febd0(pkActi->FUN_00407840());
    FUN_00442a80(pkActi->GetEffectShader_00407820());
    SetWaterForm(pkActi->GetWaterForm());
    FUN_004fb090(pkActi->BGSProjectile_GetExplosion());
    ((TESObjectACTI*)this)->SetActivationPrompt(pkActi->GetString());
    TESForm_CopyAllComponents(pkForm);
}
