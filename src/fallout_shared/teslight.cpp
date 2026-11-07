// fallout_shared/teslight.cpp: TESObjectLIGH, TESFullName and light record helpers (29 functions)

#include "../../include/BSStringT.h"
#include "../../include/BGSTerrainManager.h"
#include "../../include/TESFile.h"
#include "../../include/TESModel.h"
#include "../../include/TESTexture.h"

// MSVC synthesizes this reserved helper when the shared bound-object class is
// instantiated; give the explicit, unused declaration a non-reserved name.
#define __local_vftable_ctor_closure DeclaredVftableCtorClosure
#include "../../include/TESForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/Data.h"
#include "../../include/NiDynamicEffect.h"
#include "../../include/NiLight.h"
#include "../../include/NiPointLight.h"
#include "../../include/TESObjectLIGH.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/LightSourceData.h"
#include "../../include/TES.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESSound.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/NiSortAdjustNode.h"
#include "../../include/NiRTTI.h"
#undef __local_vftable_ctor_closure

void* __cdecl Object_DispatchCommandFour(unsigned int);



// These record operations are absent from the shared light declaration.
// Add only their declarations here; all layout and lifetime come from TESObjectLIGH.
struct LightRecordAccess : TESObjectLIGH
{
    void TESForm_LoadData(TESFile*, void*, unsigned short);
    LightSourceData* GetLightData();
    unsigned short GetSize(unsigned int flags);
    void MarkChanged(unsigned int flags);
    void MarkUnchanged(unsigned int first, unsigned int second);
    void SaveChanged(unsigned int flags);
    void LoadLightGame(BGSLoadFormBuffer* buffer);
    void* DestroyIfFlagged(unsigned int flags);
    void CopyFromLight(TESForm* form);
    void SaveLight();
    bool LoadLight(TESFile* file);
    bool CompareLight(TESForm* form);
    void SetLightFlag(bool value);
    TESSound* GetSound();
    void SetFadeAmount(float value);
};

template <class T> unsigned int __cdecl BSStringLength(const T* string);
bool __cdecl NiObject_IsKindOf(const NiRTTI* type, NiAVObject* object);
extern NiRTTI DAT_011f4a28;
extern "C" void* __cdecl _alloca(unsigned int);

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" const char DAT_01029064[];
extern int __cdecl Warning(const char* format, ...);
extern float DAT_010249d8;

// These nonvirtual TESForm record helpers are defined in tesform.cpp at the
// listed addresses; the shared header lacks their exact signatures. No layout is copied.
struct FormRecordAccess : TESForm
{
    unsigned short GetRecordSaveSize(unsigned int flags); // 0x00484bf0
    void BeginRecordSave(unsigned int flags);             // 0x00484c20
    void LoadRecordArguments(unsigned int, unsigned int); // 0x00484c50 (two arguments)
    void SaveIfChanged(unsigned int flags);               // 0x00484d60
    bool HasFlag10();                                    // 0x0050d4a0
};

// Returns the reference's model node, or a new NiSortAdjustNode when the model name is empty or the node has no children.
// @fnv 0x0050d4c0
NiAVObject* TESObjectLIGH::Get3DObject(TESObjectREFR* reference)
{
    NiAVObject* result = 0;
    if (BSStringLength(GetModelFilePath()))
        result = TESBoundObject::Get3DObject(reference);
    else
        result = new NiSortAdjustNode(0);

    if (result && !result->IsSceneNode())
    {
        NiSortAdjustNode* node = new NiSortAdjustNode(0);
        node->AttachChildInAvailableSlot(result, true);
        result = node;
    }
    return result;
}

// Recursively searches a NiNode's children for the first NiAVObject matching DAT_011f4a28 and returns it as a NiLight, or null.
// @fnv 0x0050d6d0
NiLight* FindLightInNode(NiNode* node)
{
    NiLight* result = 0;
    if (!node)
        return result;

    for (unsigned int index = 0; index < node->GetNumChildren(); ++index)
    {
        NiPointer<NiAVObject> child(node->GetAt(index));
        if (child)
        {
            if (static_cast<NiAVObject*>(child)->IsSceneNode())
            {
                result = FindLightInNode(static_cast<NiNode*>(static_cast<NiAVObject*>(child)));
                if (result)
                    return result;
            }
            else if (NiObject_IsKindOf(&DAT_011f4a28, static_cast<NiAVObject*>(child)))
            {
                return static_cast<NiLight*>(static_cast<NiAVObject*>(child));
            }
        }
    }
    return result;
}

// @fnv 0x00489100
void TESFullName::SetFullName(const char* name)
{
    m_kName.Set(name, 0);
}

// @fnv 0x0050c990
void TESObjectLIGH::ResetFormData()
{
    FUN_0050c9e0(0);
    memset(&data, 0, 0x18);
    fFadeAmount = 1.0f;
    data.fFOV = DAT_010249d8;
}

// @fnv 0x0050ca00
void TESObjectLIGH::InitItem()
{
    if (IsFormInitialized())
        return;

    TESScriptableForm::InitItem(static_cast<TESForm*>(this));
    BGSDestructibleObjectForm::InitItem(static_cast<TESForm*>(this));
    TESModelTextureSwap::InitItem(static_cast<TESForm*>(this));

    if (m_pGameSound)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pGameSound);
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pGameSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!m_pGameSound)
            Warning(DAT_01029064, formID, GetName());
    }
    SetInitializationState(true);
}

// @fnv 0x0050c9e0
void TESObjectLIGH::SetSound(TESSound* sound)
{
    m_pGameSound = sound;
}

// @fnv 0x0050c630
void NiPointLight::SetConstantAttenuation(float fC)
{
    *reinterpret_cast<float*>(storage) = fC;
    NiDynamicEffect::IncRevisionID();
}

// @fnv 0x0050c660
void NiPointLight::SetLinearAttenuation(float fL)
{
    *reinterpret_cast<float*>(storage + 4) = fL;
    NiDynamicEffect::IncRevisionID();
}

// @fnv 0x0050d4a0
bool FormRecordAccess::HasFlag10()
{
    return (iFormFlags & 0x10) ? true : false;
}

// @fnv 0x0050dd90
// src: COMMUNITY 0x0050dd90
bool TESObjectLIGH::GetDynamic()
{
    return (data.flags & 1) ? true : false;
}

// Stores fQ at offset 0xf8 of the object and increments its revision ID.
// @fnv 0x0050c690
void NiPointLight::SetQuadraticAttenuation(float fQ)
{
    *reinterpret_cast<float*>(storage + 8) = fQ;
    NiDynamicEffect::IncRevisionID();
}

// @fnv 0x0050dd50
void NiPointLight::SetSpecularColor(const NiPoint3& color)
{
    m_kSpec = reinterpret_cast<const NiColor&>(color);
    NiDynamicEffect::IncRevisionID();
}

// @fnv 0x0050c820
NiColor* TESObjectLIGH::GetLightColor()
{
    return &m_kDiffuseColor;
}

// @fnv 0x0050d100
LightSourceData* LightRecordAccess::GetLightData()
{
    return &data;
}

// Returns the sum of the sizes reported by FUN_00484bf0 on this and FUN_0048e9b0 on the object at offset 0x8c, both called with aiFlags.
// @fnv 0x0050e4f0
unsigned short __thiscall LightRecordAccess::GetSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<FormRecordAccess*>(this)->GetRecordSaveSize(aiFlags);
    isize += ((TESValueForm*)((char*)this + 0x8c))->GetFlaggedDataSize(aiFlags);
    return isize;
}

// Forwards aiFlags to FUN_00484c20 on this and to FUN_0048e9e0 on the object at offset 0x8c.
// @fnv 0x0050e550
void LightRecordAccess::MarkChanged(unsigned int aiFlags)
{
    reinterpret_cast<FormRecordAccess*>(this)->BeginRecordSave(aiFlags);
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x8c)->SaveGame_0048e9e0(aiFlags);
}

// @fnv 0x0050e580
void LightRecordAccess::MarkUnchanged(unsigned int a1, unsigned int a2)
{
    reinterpret_cast<FormRecordAccess*>(this)->LoadRecordArguments(a1, a2);
    ((TESValueForm*)((char*)this + 0x8c))->LoadGame_0048ea10(a1, a2);
}

// @fnv 0x0050e5c0
void LightRecordAccess::SaveChanged(unsigned int aiFlags)
{
    reinterpret_cast<FormRecordAccess*>(this)->SaveIfChanged(aiFlags);
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x8c)->SaveGameBGS_0048ea40(reinterpret_cast<BGSSaveFormBuffer*>(aiFlags));
}

// Loads the TESForm base and the TESValueForm subobject at offset 0x8c from the buffer.
// @fnv 0x0050e5f0
void LightRecordAccess::LoadLightGame(BGSLoadFormBuffer* pBuffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::LoadGame(pBuffer);
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x8c)->LoadGame(pBuffer);
}

void _Deallocate(void*);
// Destroys the light, deallocates it when bit 0 of flags is set, and returns this.
// @fnv 0x0050c840
void* LightRecordAccess::DestroyIfFlagged(unsigned int flags)
{
    TESObjectLIGH::~TESObjectLIGH();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x0050c6c0
TESObjectLIGH::TESObjectLIGH() : m_kDiffuseColor(0.0f, 0.0f, 0.0f)
{
    TESForm::SetFormType((ENUM_FORM_ID)0x1e);
    ResetFormData();
}

struct RegionPointList
{
    void SetDistanceInsideAtMax(unsigned int);
};
struct CGBase
{
    void SetProcedureType(int);
};
struct GetNextObj
{
    unsigned int GetNext();
};
struct FUN_00510130_shell
{
    void RemoveNode(NiNode* pNode);
};
// @fnv 0x00510130
void FUN_00510130_shell::RemoveNode(NiNode* pNode)
{
    if (pNode == *(NiNode**)((char*)this + 4))
    {
        *(NiNode**)((char*)this + 4) = (NiNode*)((GetNextObj*)(*(NiNode**)((char*)this + 4)))->GetNext();
    }
    if (pNode == *(NiNode**)((char*)this + 8))
    {
        *(NiNode**)((char*)this + 8) = (NiNode*)((BGSTerrainManager*)(*(NiNode**)((char*)this + 8)))->GetMinLevel();
    }
    unsigned int n = ((BGSTerrainManager*)pNode)->GetMinLevel();
    if (n)
    {
        ((RegionPointList*)n)->SetDistanceInsideAtMax((unsigned int)((GetNextObj*)pNode)->GetNext());
    }
    n = (unsigned int)((GetNextObj*)pNode)->GetNext();
    if (n)
    {
        ((TESActorBaseData*)n)->FUN_0050f9a0((TESLevItem*)((BGSTerrainManager*)pNode)->GetMinLevel());
    }
    ((CGBase*)pNode)->SetProcedureType(0);
    *(unsigned int*)this -= 1;
}

float __fastcall GetFieldB4Float(char* value);

// Copies light data from apCopy after casting it to TESObjectLIGH, then sets a float value and the sound from the source light.
// @fnv 0x0050d060
void LightRecordAccess::CopyFromLight(TESForm* apCopy)
{
    TESObjectLIGH* ligh = dynamic_cast<TESObjectLIGH*>(apCopy);

    if (!ligh)
        return;

    TESForm::CopyFrom(apCopy);

    data = *reinterpret_cast<LightSourceData*>(reinterpret_cast<LightRecordAccess*>(ligh)->GetLightData());

    SetFadeAmount(GetFieldB4Float(reinterpret_cast<char*>(ligh)));

    reinterpret_cast<TESObjectLIGH*>(this)->SetSound(
        reinterpret_cast<LightRecordAccess*>(ligh)->GetSound());
}

bool _FUN_00401500();
void _FUN_00485910(unsigned int, float);
void _FUN_00485910(unsigned int, unsigned int);
void __fastcall SwapEndian(void*);

// @fnv 0x0050cf20
void LightRecordAccess::SaveLight()
{
    TESForm::BeginFormRecord();

    TESModelTextureSwap::ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESScriptableForm::Save_0048cca0();
    BGSDestructibleObjectForm::Save();

    if (data.flags & 2)
    {
        TESFullName::Save_00487010();
        TESIcon::Save(0x4e4f4349);
        BGSMessageIcon::Save(0x4f43494d);
    }
    else
    {
        data.flags &= 0xffffffdf;
        data.time = 0xffffffff;
    }

    if (_FUN_00401500())
        SwapEndian(&data.time);

    TESForm::TESForm___SaveData(&data.time, 0x18);

    if (_FUN_00401500())
        SwapEndian(&data.time);

    _FUN_00485910(0x4d414e46, fFadeAmount);

    if (m_pGameSound)
    {
        unsigned int formID = m_pGameSound->GetFormID();
        _FUN_00485910(0x4d414e53, formID);
    }

    TESForm::FinishFormRecord();
}

// @fnv 0x0050c870
TESObjectLIGH::~TESObjectLIGH()
{}

// @fnv 0x0050caf0
bool LightRecordAccess::LoadLight(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 30)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    data.fFOV = 0.0f;
    data.m_fLightFalloff = 0.0f;
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
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
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            unsigned int dataSize = file->GetChunkSize();
            void* swapData = _alloca(dataSize);
            file->GetChunkData(swapData, dataSize);
            TESModelTextureSwap::ParseTextureSwapData(swapData, dataSize, file->GetFormVersion());
            break;
        }
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIcon(this, file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            TESScriptableForm::FUN_006ecd40(scriptID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 0x41544144:
            TESForm_LoadData(file, &data, 24);
            break;
        case 0x4d414e46:
            file->GetChunkData((unsigned int*)&fFadeAmount);
            break;
        case 0x4d414e53: {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            m_pGameSound = (TESSound*)soundID;
            break;
        }
        }
        if (chunk == 0x41544144)
        {
            if (file->IsEndianConversionRequired())
                SwapEndian(&data);
            if (data.fFOV == 0.0)
                data.fFOV = DAT_010249d8;
            if (data.m_fLightFalloff == 0.0)
                data.m_fLightFalloff = 1.0f;
        }
        if (!file->GetNextChunk())
            break;
    }
    return true;
}

namespace LightCreation {
struct Color
{
    float r, g, b;
    Color(float, float, float);
    Color GetNegatedVector();
};
typedef NiPointLight Light;
struct AmbientLightColorAccess
{
    void SetAmbientColor(const Color&);
};
struct Parent;
struct Scene;
struct Extra
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual Scene* GetScene();
};
struct Scene
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual Extra* GetExtra(const char*);
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(Light*, bool);
    Parent* NiObjectNET_GetControllers();
};
struct Parent
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual bool IsSpecial();
    Parent* NiTimeController_GetNext();
};
struct Position
{
    float x, y, z;
};
struct EntryListNode
{
    bool FUN_008256d0();
};
struct ObjectPointerProvider
{
    EntryListNode* ExtraDataList_GetLitWaterRefs();
};
struct Reference
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool IsPersistent();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual Position* GetPosition();
    TESForm* BGSSaveFormBuffer_GetForm();
    int FUN_008d6f30();
    float TESObjectREFR_GetRelevantWaterHeight();
    void TESForm_SetFireOff(bool);
    void TESObjectREFR_SetLight(Light*);
    float TESObjectREFR_GetRadius();
    ObjectPointerProvider* BSFile_GetDevice();
};
struct Manager
{
    void FUN_00b5c940(Light*, bool);
};
Manager* __cdecl FUN_00450b80(int);
bool __cdecl TESObjectREFR_HasAddonNodes(Scene*);
void __cdecl ProcessListItems(Scene*);
const char* __cdecl FixedStrings_GetAttachLight();
Light* __cdecl FUN_0050d6d0(Scene*);
void __cdecl BSsprintf(char*, unsigned int, const char*, ...);
void __cdecl ConfigurePointLight(Light*, unsigned int);
extern const char DAT_010290a4[];
extern const Color DAT_011f4998;
extern const double DAT_0101e568;
}  // namespace LightCreation

// @fnv 0x0050d810
NiLight* TESObjectLIGH::CreateLight(TESObjectREFR* reference, NiAVObject* pScene, bool force)
{
    using namespace LightCreation;
    if (!reinterpret_cast<Scene*>(pScene))
        return 0;
    TESForm* base;
    if (reinterpret_cast<Reference*>(reference))
    {
        base = reinterpret_cast<Reference*>(reference)->BGSSaveFormBuffer_GetForm();
        if ((data.flags & 0x20) || (reinterpret_cast<Reference*>(reference)->FUN_008d6f30() && reinterpret_cast<Reference*>(reference)->GetPosition()->z < reinterpret_cast<Reference*>(reference)->TESObjectREFR_GetRelevantWaterHeight()))
        {
            if (base->GetFormType() == 30 && TESObjectREFR_HasAddonNodes(reinterpret_cast<Scene*>(pScene)))
            {
                reinterpret_cast<Reference*>(reference)->TESForm_SetFireOff(true);
                ProcessListItems(reinterpret_cast<Scene*>(pScene));
            }
            if (!reinterpret_cast<Reference*>(reference)->IsPersistent() && (data.flags & 0x20))
                return 0;
        }
    }
    Light* lightSlot12 = 0;
    Color tintSlot1(0.0f, 0.0f, 0.0f);
    tintSlot1.r = (unsigned char)(data.color & 0xff) / DAT_0101e568;
    tintSlot1.g = (unsigned char)(((unsigned short)data.color >> 8) & 0xff) / DAT_0101e568;
    tintSlot1.b = (unsigned char)((data.color >> 16) & 0xff) / DAT_0101e568;
    if (data.flags & 4)
        tintSlot1 = tintSlot1.GetNegatedVector();
    Scene* rootSlot19 = 0;
    Extra* extra = reinterpret_cast<Scene*>(pScene)->GetExtra(FixedStrings_GetAttachLight());
    if (extra)
        rootSlot19 = extra->GetScene();
    if (!rootSlot19)
        rootSlot19 = reinterpret_cast<Scene*>(pScene);
    lightSlot12 = FUN_0050d6d0(rootSlot19);
    if (!lightSlot12)
    {
        char name[260];
        BSsprintf(name, 260, DAT_010290a4, GetName());
        lightSlot12 = new Light;
        lightSlot12->SetName(NiFixedString(static_cast<const char*>(name)));
        rootSlot19->Attach(lightSlot12, true);
    }
    if (reinterpret_cast<Reference*>(reference))
        reinterpret_cast<Reference*>(reference)->TESObjectREFR_SetLight(lightSlot12);
    reinterpret_cast<AmbientLightColorAccess*>(lightSlot12)->SetAmbientColor(DAT_011f4998);
    lightSlot12->SetSpecularColor(reinterpret_cast<const NiPoint3&>(DAT_011f4998));
    float radiusValueSlot21 = (float)data.radius;
    if (reinterpret_cast<Reference*>(reference))
        radiusValueSlot21 = reinterpret_cast<Reference*>(reference)->TESObjectREFR_GetRadius();
    lightSlot12->SetSpecularColor(NiPoint3(radiusValueSlot21, radiusValueSlot21, radiusValueSlot21));
    lightSlot12->SetEffectColor(reinterpret_cast<const NiPoint3&>(tintSlot1));
    Parent* parentSlot6;
    for (parentSlot6 = reinterpret_cast<Scene*>(pScene)->NiObjectNET_GetControllers(); parentSlot6; parentSlot6 = parentSlot6->NiTimeController_GetNext())
    {
        if (parentSlot6->IsSpecial())
        {
            reinterpret_cast<LightRecordAccess*>(this)->SetLightFlag(true);
            break;
        }
    }
    if (!(reinterpret_cast<Reference*>(reference) && reinterpret_cast<Reference*>(reference)->BSFile_GetDevice()->ExtraDataList_GetLitWaterRefs()) ||
        (reinterpret_cast<Reference*>(reference) && reinterpret_cast<Reference*>(reference)->BSFile_GetDevice()->ExtraDataList_GetLitWaterRefs() &&
         reinterpret_cast<Reference*>(reference)->BSFile_GetDevice()->ExtraDataList_GetLitWaterRefs()->FUN_008256d0()))
        FUN_00450b80(0)->FUN_00b5c940(lightSlot12, force ? true : GetDynamic());
    if (lightSlot12)
    {
        ConfigurePointLight(lightSlot12, (unsigned int)radiusValueSlot21);
        lightSlot12->SetDimmer(fFadeAmount);
    }
    return lightSlot12;
}

// 0x0050c350  unit_0e65a86e7dd7.cpp  /MT /Od /Oy- /GS /EHsc /Gy

class GlobalObject_0044f440
{
  public:
    float* Float();
    float FUN_00450410();
};
class GlobalObject_0045cfe0
{
  public:
    int* Int();
};
class GlobalObject_0045cf30
{
  public:
    bool IOTask_SetPriority_Thunk(bool b);
};

extern GlobalObject_0044f440 g_011c8fb0;
extern GlobalObject_0044f440 g_011c9000;
extern GlobalObject_0044f440 g_011c9040;
extern GlobalObject_0044f440 g_011c906c;
extern GlobalObject_0044f440 g_011c908c;
extern GlobalObject_0045cfe0 g_011c9054;
extern GlobalObject_0045cfe0 g_011c907c;
extern GlobalObject_0045cf30 g_011c8fc0;
extern unsigned char DAT_011c8fa0;
extern NiRTTI DAT_011f4a98;

extern TES* g_TES;

NiAVObject* NiDynamicCast(const NiRTTI* type, NiAVObject* object);

// @fnv 0x0050c350
void ConfigurePointLight(NiAVObject* object, unsigned int count)
{
    NiPointLight* light = (NiPointLight*)NiDynamicCast(&DAT_011f4a98, object);
    if (light)
    {
        light->SetConstantAttenuation((DAT_011c8fa0 & 1) ? *g_011c9000.Float() : 0.0f);
        light->SetLinearAttenuation(0.0f);
        light->SetQuadraticAttenuation(0.0f);

        if ((DAT_011c8fa0 & 2) || (g_TES->GetPrevPath() != 0 && g_011c8fc0.IOTask_SetPriority_Thunk(true)))
        {
            float a = (double)count * *g_011c8fb0.Float();
            switch (*g_011c9054.Int())
            {
            case 0:
                light->SetLinearAttenuation(*g_011c908c.Float());
                break;
            default:
                light->SetLinearAttenuation((a != 0.0) ? ((1.0 / a) * *g_011c908c.Float()) : 0.01f);
                break;
            case 2:
                light->SetLinearAttenuation((a != 0.0) ? (*g_011c908c.Float() / (a * a)) : 0.01f);
                break;
            }
        }

        if ((DAT_011c8fa0 & 4) || (g_TES->GetPrevPath() == 0 && g_011c8fc0.IOTask_SetPriority_Thunk(true)))
        {
            float b = (double)count * *g_011c906c.Float();
            switch (*g_011c907c.Int())
            {
            case 0:
                light->SetQuadraticAttenuation(*g_011c9040.Float());
                break;
            case 1:
                light->SetQuadraticAttenuation((b != 0.0) ? ((1.0 / (double)count) * g_011c9040.FUN_00450410()) : 0.01f);
                break;
            default:
                light->SetQuadraticAttenuation((b != 0.0) ? (g_011c9040.FUN_00450410() / (b * b)) : 0.01f);
                break;
            }
        }
    }
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);
extern float __fastcall GetFieldB4Float(char*);

// Returns true if this light fails the component, sound, data, or computed-value comparisons.
// @fnv 0x0050d120
bool LightRecordAccess::CompareLight(TESForm* form)
{
    TESObjectLIGH* pOtherLight = dynamic_cast<TESObjectLIGH*>(form);
    if (!pOtherLight)
        return true;
    if (TESForm::Compare(pOtherLight))
        return true;
    if (m_pGameSound != reinterpret_cast<LightRecordAccess*>(pOtherLight)->GetSound())
        return true;
    if (_memcmp(&data, reinterpret_cast<LightRecordAccess*>(pOtherLight)->GetLightData(), sizeof(data)))
        return true;
    if (GetFieldB4Float(reinterpret_cast<char*>(this)) != GetFieldB4Float(reinterpret_cast<char*>(pOtherLight)))
        return true;
    return false;
}
