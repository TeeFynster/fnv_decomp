// fallout_shared/tesobjectweap.cpp: TESObjectWEAP, TransHolder, Weapon, WeaponCopyAccess and more (72 functions)

#include <stddef.h>

#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/BSFaceGenAnimationData.h"
#include "../../include/BSFaceGenNiNode.h"
#include "../../include/Actor.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiMatrix3.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/BaseProcess.h"
#include "../../include/PlayerCharacter.h"
#include "tesobjectweap_decls.h"
// Reads a weapon record from the file: validates form type 40, then dispatches each chunk to its loader and fixes up invalid weapon data.
// @fnv 0x0051f630
bool TESObjectWEAP::LoadForm(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if(formType != 40) return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    CHUNK_ID chunk;
    while((chunk = (CHUNK_ID)file->GetChunkID()) != 0) {
        switch(chunk) {
        case 0x44494445: // EDID
        {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID,512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f: // OBND
        {
            readOBNDSubRecord(file);
            break;
        }
        case 0x4c4c5546: // FULL
        {
            TESFullNameLoader::LoadFullNameChunk(this,file);
            break;
        }
        case 0x44444f4d: // MODD
        case 0x44534f4d: // MOSD
        case 0x4c444f4d: // MODL
        case 0x54444f4d: // MODT
        {
            TESModel::LoadModelData(this,file);
            break;
        }
        case 0x53444f4d: // MODS
        {
            unsigned int textureSwapSize = file->GetChunkSize();
            void* textureSwaps = _alloca(textureSwapSize);
            file->GetChunkData(textureSwaps,textureSwapSize);
            ParseTextureSwapData(textureSwaps,textureSwapSize,((TESFileFormVersion*)file)->GetFormVersion());
            break;
        }
        case 0x4e4f4349: // ICON
        {
            TESTexture::ReadTextureData(this,file);
            break;
        }
        case 0x4f43494d: // MICO
        {
            BGSMessageIcon::LoadMessageIconChunk(this,file);
            break;
        }
        case 0x49524353: // SCRI
        {
            Script* script = (Script*)0;
            file->GetChunkData((unsigned int*)&script);
            TESScriptableForm::SetScript(script);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d544945: // EITM
        case 0x4d414e45: // ENAM
        {
            EnchantmentItem* enchantment = (EnchantmentItem*)0;
            file->GetChunkData((unsigned int*)&enchantment);
            SetFormEnchanting(enchantment);
            break;
        }
        case 0x4d414e41: // ANAM
        case 0x544d4145: // EAMT
        {
            unsigned short enchantmentAmount = 0;
            ((TESFileChunkData16*)file)->GetChunkData(&enchantmentAmount);
            FUN_00483170(enchantmentAmount);
            break;
        }
        case 0x304d414e: // NAM0
        {
            TESAmmo* ammo = (TESAmmo*)0;
            file->GetChunkData((unsigned int*)&ammo);
            SetAmmo(ammo);
            break;
        }
        case 0x44545344: // DSTD
        case 0x54534544: // DEST
        {
            BGSDestructibleObjectForm::LoadDestructibleData(this,file);
            break;
        }
        case 0x4c504552: // REPL
        {
            BGSListForm* repairList = (BGSListForm*)0;
            file->GetChunkData((unsigned int*)&repairList);
            SetRepairItemList(repairList);
            break;
        }
        case 0x50595445: // ETYP
        {
            BGSEquipType__EQUIP_TYPE equipType = (BGSEquipType__EQUIP_TYPE)0;
            file->GetChunkData((unsigned int*)&equipType);
            SetEquipType(equipType);
            break;
        }
        case 0x4c504942: // BIPL
        {
            BGSListForm* bipedList = (BGSListForm*)0;
            file->GetChunkData((unsigned int*)&bipedList);
            SetBipedModelList(bipedList);
            break;
        }
        case 0x4d414e59: // YNAM
        {
            TESSound* pickupSound = (TESSound*)0;
            file->GetChunkData((unsigned int*)&pickupSound);
            SetPickupSound(pickupSound);
            break;
        }
        case 0x4d414e5a: // ZNAM
        {
            TESSound* putdownSound = (TESSound*)0;
            file->GetChunkData((unsigned int*)&putdownSound);
            SetPutdownSound(putdownSound);
            break;
        }
        case 0x41544144: // DATA
        {
            ((BGSImpactData*)this)->ReadTypedData(file,0,0);
            break;
        }
        case 0x4d414e44: // DNAM
        {
            if (((TESFileFormVersion*)file)->GetFormVersion() < 12) {
                memset(&data,0,sizeof(data));
                data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
                data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
                file->GetChunkData(&data,file->GetChunkSize());
                if(file->IsEndianConversionRequired()) data.Endian();
                if(data.m_ucAttackAnimation < 168 && data.m_ucAttackAnimation >= 56) {
                    data.m_ucAttackAnimation += 18;
                    if(data.m_ucAttackAnimation < 168 && data.m_ucAttackAnimation >= 86) data.m_ucAttackAnimation += 6;
                }
            } else if (((TESFileFormVersion*)file)->GetFormVersion() < 14) {
                memset(&data,0,sizeof(data));
                data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
                data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
                file->GetChunkData(&data,file->GetChunkSize());
                if(file->IsEndianConversionRequired()) data.Endian();
                if(data.m_ucAttackAnimation < 168 && data.m_ucAttackAnimation >= 86) data.m_ucAttackAnimation += 6;
            } else {
                memset(&data,0,sizeof(data));
                data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
                data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
                file->GetChunkData(&data,sizeof(data));
                if(file->IsEndianConversionRequired()) data.Endian();
                if(data.m_fLimbDamageMultiplier <= 0.0) data.m_fLimbDamageMultiplier = 1.0f;
                switch(data.m_ucGripAnimation) {
                case 230: case 231: case 232: case 233: case 234: case 235: case 255: break;
                default: data.m_ucGripAnimation = 255; break;
                }
                if(!ActorValue::IsSkill(data.m_eWeaponSkill)) data.m_eWeaponSkill = (ActorValue__Index)45;
                if(!ActorValue_IsResistance(data.m_eResistanceType) && data.m_eResistanceType != -1) data.m_eResistanceType = (ActorValue__Index)-1;
            }
            break;
        }
        case 0x4d414e57: // WNAM
        {
            TESObjectSTAT* firstPersonObject0 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject0);
            Set1stPersonObject(firstPersonObject0);
            break;
        }
        case 0x314d4e57: // WNM1
        {
            TESObjectSTAT* firstPersonObject1 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject1);
            SetModObject(1,firstPersonObject1);
            break;
        }
        case 0x324d4e57: // WNM2
        {
            TESObjectSTAT* firstPersonObject2 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject2);
            SetModObject(2,firstPersonObject2);
            break;
        }
        case 0x334d4e57: // WNM3
        {
            TESObjectSTAT* firstPersonObject3 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject3);
            SetModObject(3,firstPersonObject3);
            break;
        }
        case 0x344d4e57: // WNM4
        {
            TESObjectSTAT* firstPersonObject4 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject4);
            SetModObject(4,firstPersonObject4);
            break;
        }
        case 0x354d4e57: // WNM5
        {
            TESObjectSTAT* firstPersonObject5 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject5);
            SetModObject(5,firstPersonObject5);
            break;
        }
        case 0x364d4e57: // WNM6
        {
            TESObjectSTAT* firstPersonObject6 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject6);
            SetModObject(6,firstPersonObject6);
            break;
        }
        case 0x374d4e57: // WNM7
        {
            TESObjectSTAT* firstPersonObject7 = 0;
            file->GetChunkData((unsigned int*)&firstPersonObject7);
            SetModObject(7,firstPersonObject7);
            break;
        }
        case 0x31494d57: // WMI1
        {
            TESObjectIMOD* modItem1 = 0;
            file->GetChunkData((unsigned int*)&modItem1);
            SetModItem((unsigned char)1,modItem1);
            break;
        }
        case 0x32494d57: // WMI2
        {
            TESObjectIMOD* modItem2 = 0;
            file->GetChunkData((unsigned int*)&modItem2);
            SetModItem((unsigned char)2,modItem2);
            break;
        }
        case 0x33494d57: // WMI3
        {
            TESObjectIMOD* modItem3 = 0;
            file->GetChunkData((unsigned int*)&modItem3);
            SetModItem((unsigned char)4,modItem3);
            break;
        }
        case 0x314d414e: // NAM1
        case 0x32444f4d: // MOD2
        {
            if(file->GetChunkSize()) {
                char* modelPath0 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath0,0);
                m_kModel.SetModelFilePath(modelPath0);
            } else m_kModel.SetModelFilePath(0);
            break;
        }
        case 0x54324f4d: // MO2T
        {
            TESModel::LoadTextureSwapData(&m_kModel,file);
            break;
        }
        case 0x33444f4d: // MOD3
        {
            if(file->GetChunkSize()) {
                char* modelPath1 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath1,0);
                m_kModel1stPerson.SetModelFilePath(modelPath1);
            } else m_kModel1stPerson.SetModelFilePath(0);
            break;
        }
        case 0x54334f4d: // MO3T
        {
            TESModel::LoadTextureSwapData(&m_kModel1stPerson,file);
            break;
        }
        case 0x34444f4d: // MOD4
        {
            if(file->GetChunkSize()) {
                char* modelPath2 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath2,0);
                m_kModel3rdPerson.SetModelFilePath(modelPath2);
            } else m_kModel3rdPerson.SetModelFilePath(0);
            break;
        }
        case 0x54344f4d: // MO4T
        {
            TESModel::LoadTextureSwapData(&m_kModel3rdPerson,file);
            break;
        }
        case 0x3144574d: // MWD1
        {
            if(file->GetChunkSize()) {
                char* modelPath3 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath3,0);
                m_kWeaponModTextureSwap1.SetModelFilePath(modelPath3);
            } else m_kWeaponModTextureSwap1.SetModelFilePath(0);
            break;
        }
        case 0x3154574d: // MWT1
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap1,file);
            break;
        }
        case 0x3244574d: // MWD2
        {
            if(file->GetChunkSize()) {
                char* modelPath4 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath4,0);
                m_kWeaponModTextureSwap2.SetModelFilePath(modelPath4);
            } else m_kWeaponModTextureSwap2.SetModelFilePath(0);
            break;
        }
        case 0x3254574d: // MWT2
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap2,file);
            break;
        }
        case 0x3444574d: // MWD4
        {
            if(file->GetChunkSize()) {
                char* modelPath5 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath5,0);
                m_kWeaponModTextureSwap3.SetModelFilePath(modelPath5);
            } else m_kWeaponModTextureSwap3.SetModelFilePath(0);
            break;
        }
        case 0x3454574d: // MWT4
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap3,file);
            break;
        }
        case 0x3344574d: // MWD3
        {
            if(file->GetChunkSize()) {
                char* modelPath6 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath6,0);
                m_kWeaponModTextureSwap4.SetModelFilePath(modelPath6);
            } else m_kWeaponModTextureSwap4.SetModelFilePath(0);
            break;
        }
        case 0x3354574d: // MWT3
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap4,file);
            break;
        }
        case 0x3544574d: // MWD5
        {
            if(file->GetChunkSize()) {
                char* modelPath7 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath7,0);
                m_kWeaponModTextureSwap5.SetModelFilePath(modelPath7);
            } else m_kWeaponModTextureSwap5.SetModelFilePath(0);
            break;
        }
        case 0x3554574d: // MWT5
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap5,file);
            break;
        }
        case 0x3644574d: // MWD6
        {
            if(file->GetChunkSize()) {
                char* modelPath8 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath8,0);
                m_kWeaponModTextureSwap6.SetModelFilePath(modelPath8);
            } else m_kWeaponModTextureSwap6.SetModelFilePath(0);
            break;
        }
        case 0x3654574d: // MWT6
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap6,file);
            break;
        }
        case 0x3744574d: // MWD7
        {
            if(file->GetChunkSize()) {
                char* modelPath9 = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(modelPath9,0);
                m_kWeaponModTextureSwap7.SetModelFilePath(modelPath9);
            } else m_kWeaponModTextureSwap7.SetModelFilePath(0);
            break;
        }
        case 0x3754574d: // MWT7
        {
            TESModel::LoadTextureSwapData(&m_kWeaponModTextureSwap7,file);
            break;
        }
        case 0x44534645: // EFSD
        {
            TESEffectShader* scopeEffect = 0;
            file->GetChunkData((unsigned int*)&scopeEffect);
            SetEffectShader(scopeEffect);
            break;
        }
        case 0x4d414e4e: // NNAM
        {
            char* embeddedWeaponNodeText = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(embeddedWeaponNodeText,0);
            m_kEmbeddedWeaponNodeName.Set(embeddedWeaponNodeText,0);
            break;
        }
        case 0x4d4e4156: // VANM
        {
            char* vATSAttackNameText = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(vATSAttackNameText,0);
            VATSAttackName.Set(vATSAttackNameText,0);
            break;
        }
        case 0x54445243: // CRDT
        {
            file->GetChunkData(&m_kCriticalData,sizeof(m_kCriticalData));
            if(file->IsEndianConversionRequired()) m_kCriticalData.OBJ_WEAP_CRITICAL_Endian();
            break;
        }
        case 0x53544156: // VATS
        {
            file->GetChunkData(&m_kVATSData,sizeof(m_kVATSData));
            if(file->IsEndianConversionRequired()) m_kVATSData.OBJ_WEAP_VATS_SPECIAL_Endian();
            break;
        }
        case 0x4d414e49: // INAM
        {
            BGSImpactDataSet* impactDataSet = 0;
            file->GetChunkData((unsigned int*)&impactDataSet);
            SetImpactDataSet(impactDataSet);
            break;
        }
        case 0x4d414e53: // SNAM
        {
            TESSound* attackSound = 0;
            file->GetChunkData((unsigned int*)&attackSound);
            if(GetAttackSound(false)) SetDistantAttackSound(attackSound);
            else SetAttackSound(attackSound);
            break;
        }
        case 0x4d414e58: // XNAM
        {
            TESSound* attackSound2 = 0;
            file->GetChunkData((unsigned int*)&attackSound2);
            SetAttackSound2(attackSound2);
            break;
        }
        case 0x374d414e: // NAM7
        {
            TESSound* attackLoop = 0;
            file->GetChunkData((unsigned int*)&attackLoop);
            TESObjectWEAP_SetAttackLoop(attackLoop);
            break;
        }
        case 0x4d414e54: // TNAM
        {
            TESSound* attackFail = 0;
            file->GetChunkData((unsigned int*)&attackFail);
            SetAttackFailSound(attackFail);
            break;
        }
        case 0x364d414e: // NAM6
        {
            TESSound* meleeBlock = 0;
            file->GetChunkData((unsigned int*)&meleeBlock);
            SetMeleeBlockSound(meleeBlock);
            break;
        }
        case 0x4d414e55: // UNAM
        {
            TESSound* idleSound = 0;
            file->GetChunkData((unsigned int*)&idleSound);
            SetIdleSound(idleSound);
            break;
        }
        case 0x394d414e: // NAM9
        {
            TESSound* equipSound = 0;
            file->GetChunkData((unsigned int*)&equipSound);
            SetEquipSound(equipSound);
            break;
        }
        case 0x384d414e: // NAM8
        {
            TESSound* unequipSound = 0;
            file->GetChunkData((unsigned int*)&unequipSound);
            SetUnequipSound(unequipSound);
            break;
        }
        case 0x31534d57: // WMS1
        {
            TESSound* modAttackSound = 0;
            file->GetChunkData((unsigned int*)&modAttackSound);
            if(GetModDistantAttackSound()) SetModAttackSound2(modAttackSound);
            else SetModAttackSound(modAttackSound);
            break;
        }
        case 0x32534d57: // WMS2
        {
            TESSound* modDistantAttackSound = 0;
            file->GetChunkData((unsigned int*)&modDistantAttackSound);
            SetModDistantAttackSound2(modDistantAttackSound);
            break;
        }
        case 0x4d414e56: // VNAM
        {
            unsigned int soundLevel;
            file->GetChunkData(&soundLevel);
            if(soundLevel > 3) m_eSoundLevel = (TESObjectWEAP::SOUND_LEVEL)_SoundLevel::NORMAL;
            else m_eSoundLevel = (TESObjectWEAP::SOUND_LEVEL)soundLevel;
            break;
        }
        }
        if(!file->NextChunk()) break;
    }
    if(!GetDamageForActor(false,true,0) && GetProjectileData(0)) TESObjectWEAP_SetNumProjectiles(1);
    if(data.eType >= 14) {
        Warning("MASTERFILE: Clearing invalid type on weapon '%s' (%08X).",GetName(),GetFormID());
        data.eType = 0;
    }
    return true;
}

// @fnv 0x0051e420
void TESObjectWEAP::InitItem()
{
    if(IsFormInitialized()) return;
    BGSBipedModelList::InitItem(this);
    TESScriptableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    BGSAmmoForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSRepairItemList::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    unsigned int formID = (unsigned int)GetProjectileData(0);
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        TESCreature_SetMaterialType(dynamic_cast<BGSProjectile*>(TESForm::GetFormByID(formID)));
        if(!GetProjectileData(0)) Warning("MASTERFILE: Could not find projectile (%08X) on weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)GetScopeEffect();
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        SetEffectShader(dynamic_cast<TESEffectShader*>(TESForm::GetFormByID(formID)));
        if(!GetScopeEffect()) Warning("MASTERFILE: Could not find scope effect (%08X) on weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)GetField1CC();
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        UpdateState_0051f4f0(dynamic_cast<SpellItem*>(TESForm::GetFormByID(formID)));
        if(!GetField1CC()) Warning("MASTERFILE: Could not find Spell Item (%08X) on weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)GetVATSSpecialEffect();
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        TESObjectWEAP_SetVATSEffect(dynamic_cast<SpellItem*>(TESForm::GetFormByID(formID)));
        if(!GetVATSSpecialEffect()) Warning("MASTERFILE: Could not find vats Spell Item (%08X) on weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound1;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound1 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound1) Warning("MASTERFILE: Could not find open sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound2;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound2 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound2) Warning("MASTERFILE: Could not find open sound2 (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound3;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound3 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound3) Warning("MASTERFILE: Could not find open sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound4;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound4 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound4) Warning("MASTERFILE: Could not find sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound5;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound5 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound5) Warning("MASTERFILE: Could not find open sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound6;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound6 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound6) Warning("MASTERFILE: Could not find open sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound7;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound7 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound7) Warning("MASTERFILE: Could not find idle sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponSound8;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponSound8 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponSound8) Warning("MASTERFILE: Could not find equip sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponUnequipSound;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponUnequipSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponUnequipSound) Warning("MASTERFILE: Could not find unequip sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponEquipSound;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponEquipSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponEquipSound) Warning("MASTERFILE: Could not find unequip sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponPickupSound;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponPickupSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponPickupSound) Warning("MASTERFILE: Could not find unequip sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponDropSound;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponDropSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponDropSound) Warning("MASTERFILE: Could not find unequip sound (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pImpactDataSet;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pImpactDataSet = dynamic_cast<BGSImpactDataSet*>(TESForm::GetFormByID(formID));
        if(!m_pImpactDataSet) Warning("MASTERFILE: Could not find impact data set (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonObject;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonObject = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonObject) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod1Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod1Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod1Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod2Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod2Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod2Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod3Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod3Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod3Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod12Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod12Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod12Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod13Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod13Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod13Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod23Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod23Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod23Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)p1stPersonMod123Object;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        p1stPersonMod123Object = dynamic_cast<TESObjectSTAT*>(TESForm::GetFormByID(formID));
        if(!p1stPersonMod123Object) Warning("MASTERFILE: Could not find 1st person model object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponMod1;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponMod1 = dynamic_cast<TESObjectIMOD*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponMod1) Warning("MASTERFILE: Could not find misc object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponMod2;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponMod2 = dynamic_cast<TESObjectIMOD*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponMod2) Warning("MASTERFILE: Could not find misc object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    formID = (unsigned int)m_pWeaponMod3;
    if(formID) {
        TESForm::RemapFormIDForFile(formID,GetFile(-1));
        m_pWeaponMod3 = dynamic_cast<TESObjectIMOD*>(TESForm::GetFormByID(formID));
        if(!m_pWeaponMod3) Warning("MASTERFILE: Could not find misc object (%08X) for weapon '%s' (%08X).",formID,GetName(),GetFormID());
    }
    if(data.fSpeed <= 0.0) data.fSpeed = 1.0f;
    if(data.m_fAnimationAttackMultiplier <= 0.0) data.m_fAnimationAttackMultiplier = 1.0f;
    if(*DAT_011c94d0.Bool()) SetNPCsUseAmmo(true);
    m_bHasReloadAnimation = false;
    if(data.m_ucReloadAnimation >= 19) m_bHasReloadAnimation = true;
    SetInitializationState(true);
}

// Resets the weapon's data block to defaults, initializes embedded sub-structures, sets casting type and sound level, and flags a reload-anim condition.
// @fnv 0x0051ddf0
void TESObjectWEAP::ResetFormData()
{
    memset(&data,0,sizeof(data));
    data.m_ucAmmoUse = 1;
    data.fWeaponDamageMultiplier = 5.0f;
    data.m_fMinimumSpread = 0.0f;
    data.fBodyPartChance = 10.0f;
    data.m_fUnknownFloat = 1.0f;
    data.m_ucBaseVATSChance = 5;
    data.m_ucReloadAnimation = 0;
    data.m_ucAttackAnimation = 255;
    data.m_ucGripAnimation = 255;
    data.pProjectile = 0;
    data.m_ucProjectileCount = 1;
    data.m_fMinimumRange = 500.0f;
    data.m_fMaximumRange = 2000.0f;
    data.m_eHitBehavior = WEAPONHITBEHAVIOR_WHB_NORMAL;
    data.m_fOverrideActionPoints = 0.0f;
    data.m_fLeftRumbleMotorStrength = 0.5f;
    data.m_fRightRumbleMotorStrength = 1.0f;
    data.m_fRumbleDuration = 0.33f;
    data.m_fOverrideDamageToWeaponMultiplier = 1.0f;
    data.m_eWeaponSkill = (ActorValue__Index)45;
    data.m_fLimbDamageMultiplier = 1.0f;
    data.m_fSightUsage = 0.0f;
    data.m_eResistanceType = (ActorValue__Index)-1;
    data.m_fMinimumSemiAutomaticFireDelay = 0.1f;
    data.m_fMaximumSemiAutomaticFireDelay = 0.5f;
    data.m_uiStrengthRequirement = 0;
    data.m_uiSkillRequirement = 0;
    data.m_fModValueA1 = 0.0f;
    data.m_fModValueA2 = 0.0f;
    data.m_fModValueA3 = 0.0f;
    data.m_fModValueB1 = 0.0f;
    data.m_fModValueB2 = 0.0f;
    data.m_fModValueB3 = 0.0f;
    data.m_fKillImpulse = 1.0f;
    data.m_ucPowerAttackAnimationOverride = 255;
    data.m_cReloadAnimationMod = -1;
    data.m_cUnknownByte = -1;
    m_kCriticalData.m_usCriticalDamage = 0;
    m_kCriticalData.m_fCriticalChanceMultiplier = 1.0f;
    m_kCriticalData.m_bEffectOnDeath = true;
    m_kCriticalData.pEffect = 0;
    m_kVATSData.m_fSkill = 0.0f;
    m_kVATSData.m_fDamageMultiplier = 0.0f;
    m_kVATSData.m_pVATSAttackSpell = 0;
    m_kVATSData.m_fActionPointCost = 0.0f;
    m_kVATSData.bSilent = true;
    m_kVATSData.m_bModRequired = false;
    m_pWeaponEffectShader = 0;
    m_pWeaponSound1 = 0;
    m_pWeaponSound2 = 0;
    m_pWeaponSound3 = 0;
    m_pWeaponSound4 = 0;
    m_pWeaponSound5 = 0;
    m_pWeaponSound6 = 0;
    m_pWeaponSound7 = 0;
    m_pWeaponSound8 = 0;
    m_pWeaponUnequipSound = 0;
    m_pWeaponEquipSound = 0;
    m_pWeaponPickupSound = 0;
    m_pWeaponDropSound = 0;
    m_pImpactDataSet = 0;
    p1stPersonObject = 0;
    p1stPersonMod1Object = 0;
    p1stPersonMod2Object = 0;
    p1stPersonMod3Object = 0;
    p1stPersonMod12Object = 0;
    p1stPersonMod13Object = 0;
    p1stPersonMod23Object = 0;
    p1stPersonMod123Object = 0;
    m_pWeaponMod1 = 0;
    m_pWeaponMod2 = 0;
    m_pWeaponMod3 = 0;
    m_kModel.Init();
    m_kModel1stPerson.Init();
    m_kModel3rdPerson.Init();
    m_kWeaponModTextureSwap1.Init();
    m_kWeaponModTextureSwap2.Init();
    m_kWeaponModTextureSwap3.Init();
    m_kWeaponModTextureSwap4.Init();
    m_kWeaponModTextureSwap5.Init();
    m_kWeaponModTextureSwap6.Init();
    m_kWeaponModTextureSwap7.Init();
    SetCastingType(MagicSystem__CastingType_WHEN_STRIKES);
    m_eSoundLevel = (TESObjectWEAP::SOUND_LEVEL)_SoundLevel::NORMAL;
    m_bHasReloadAnimation = false;
    if(GetReloadAnim(false) >= 196) m_bHasReloadAnimation = true;
}

// @fnv 0x0051d770
TESObjectWEAP::TESObjectWEAP()
{
    SetFormType(ENUM_FORM_ID_WEAP_ID);
    ResetFormData();
}

// @fnv 0x0051e300
void TESObjectWEAP::ClearData()
{
    m_kModel.Free();
    m_kModel1stPerson.Free();
    m_kModel3rdPerson.Free();
    m_kWeaponModTextureSwap1.Free();
    m_kWeaponModTextureSwap2.Free();
    m_kWeaponModTextureSwap3.Free();
    m_kWeaponModTextureSwap4.Free();
    m_kWeaponModTextureSwap5.Free();
    m_kWeaponModTextureSwap6.Free();
    m_kWeaponModTextureSwap7.Free();
    m_kEmbeddedWeaponNodeName.Set(0,0);
    VATSAttackName.Set(0,0);
}
// BGSProjectile and BGSImpactDataSet reached through their BGSPreloadable base (the original calls the inherited
// BGSPreloadable::QueueResourceLoad slot; the shared classes redeclare it)
struct ProjectilePreloadView : public TESBoundObject, public TESFullName, public TESModel, public BGSPreloadable
{
};
struct ImpactDataSetPreloadView : public TESForm, public BGSPreloadable
{
};


// @fnv 0x00525510
void TESObjectWEAP::QueueResourceLoad(int priority, QueuedFile* file, bool includeScope)
{
    if(m_kModel.GetModelLength())
        g_modelLoader->ProcessModelRequest(&m_kModel,priority,file,false,true,false,false);
    if(includeScope && GetHasScope() && m_kModel1stPerson.GetModelLength())
        g_modelLoader->ProcessModelRequest(&m_kModel1stPerson,priority,file,TES::GetModelResourceType(this),true,false,false);
    if(GetProjectileData(0)) reinterpret_cast<ProjectilePreloadView*>(GetProjectileData(0))->QueueResourceLoad((IO_TASK_PRIORITY)priority,file);
    if(m_pImpactDataSet) reinterpret_cast<ImpactDataSetPreloadView*>(m_pImpactDataSet)->QueueResourceLoad((IO_TASK_PRIORITY)priority,file);
}

// @fnv 0x00525b20
unsigned char TESObjectWEAP::GetDamageForActor(bool includeMods, bool ignoreAmmo, Actor* actor)
{
    unsigned char count = data.m_ucProjectileCount;
    if(!ignoreAmmo && GetCurrentAmmo(actor) && GetCurrentAmmo(actor)->GetByteAtOffsetB0() > 0)
        count = GetCurrentAmmo(actor)->GetByteAtOffsetB0() * GetAmmoPerShot();
    if(includeMods) count += GetModdedWeaponValue(WEAPON_MOD_EFFECT_WEAPON_MOD_SPLIT_BEAM,0);
    return count;
}

// @fnv 0x009b6600
ActorValue__Index TESObjectWEAP::GetResistance()
{
    return data.m_eResistanceType;
}

// @fnv 0x0051e2a0
int TESObjectWEAP::GetReloadAnim(bool modValue) {
    if (modValue) {
        if (data.m_cReloadAnimationMod != 255) {
            return data.m_cReloadAnimationMod + 177;
        } else {
            return data.m_ucReloadAnimation + 177;
        }
    } else {
        return data.m_ucReloadAnimation + 177;
    }
}

struct FUN_0051f570_shell : public TESObjectWEAP {
    void SetEffectShader(TESEffectShader*);
};

// @fnv 0x0051f570
void FUN_0051f570_shell::SetEffectShader(TESEffectShader* apEffect)
{
    m_pWeaponEffectShader = apEffect;
}

struct FUN_005214d0_shell : public TESObjectWEAP {
    void SetFirstPersonModObject(unsigned char, TESObjectSTAT*);
};

// Stores apObject into the first-person mod object slot selected by the bitmask iModSlots (bits 1, 2 and 4).
// @fnv 0x005214d0
void FUN_005214d0_shell::SetFirstPersonModObject(unsigned char iModSlots, TESObjectSTAT* apObject)
{
    if (iModSlots & 1) {
        if (iModSlots & 2) {
            if (iModSlots & 4)
                p1stPersonMod123Object = apObject;
            else
                p1stPersonMod12Object = apObject;
        } else {
            if (iModSlots & 4)
                p1stPersonMod13Object = apObject;
            else
                p1stPersonMod1Object = apObject;
        }
    } else if (iModSlots & 2) {
        if (iModSlots & 4)
            p1stPersonMod23Object = apObject;
        else
            p1stPersonMod2Object = apObject;
    } else if (iModSlots & 4) {
        p1stPersonMod3Object = apObject;
    }
}

struct FUN_005215a0_shell : public TESObjectWEAP {
    TESSound* TESObjectWEAP_GetAttackSound(bool);
};

// Returns one of two TESSound pointers depending on bModSound.
// @fnv 0x005215a0
// src: XBOX_PDB 0x005215a0
TESSound* FUN_005215a0_shell::TESObjectWEAP_GetAttackSound(bool bModSound)
{
    if (bModSound)
        return m_pWeaponEquipSound;
    else
        return m_pWeaponSound1;
}

struct FUN_005215d0_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetAttackSound(TESSound*);
};

// @fnv 0x005215d0
// src: XBOX_PDB 0x005215d0
void FUN_005215d0_shell::TESObjectWEAP_SetAttackSound(TESSound* apSnd)
{
    m_pWeaponSound1 = apSnd;
}

struct FUN_005215f0_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetAttackSound2(TESSound*);
};

// @fnv 0x005215f0
// src: XBOX_PDB 0x005215f0
void FUN_005215f0_shell::TESObjectWEAP_SetAttackSound2(TESSound* apSnd)
{
    m_pWeaponSound2 = apSnd;
}

struct FUN_00521610_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetModAttackSound(TESSound*);
};

// @fnv 0x00521610
// src: XBOX_PDB 0x00521610
void FUN_00521610_shell::TESObjectWEAP_SetModAttackSound(TESSound* apSnd)
{
    m_pWeaponEquipSound = apSnd;
}

struct FUN_00521650_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetAttackLoop(TESSound*);
};

// @fnv 0x00521650
// src: XBOX_PDB 0x00521650
void FUN_00521650_shell::TESObjectWEAP_SetAttackLoop(TESSound* apSnd)
{
    m_pWeaponSound4 = apSnd;
}

struct FUN_00521670_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetAttackFailSound(TESSound*);
};

// @fnv 0x00521670
// src: XBOX_PDB 0x00521670
void FUN_00521670_shell::TESObjectWEAP_SetAttackFailSound(TESSound* apSnd)
{
    m_pWeaponSound5 = apSnd;
}

struct FUN_005216b0_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetIdleSound(TESSound*);
};

// @fnv 0x005216b0
// src: XBOX_PDB 0x005216b0
void FUN_005216b0_shell::TESObjectWEAP_SetIdleSound(TESSound* apSnd)
{
    m_pWeaponSound7 = apSnd;
}

struct FUN_005216d0_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetEquipSound(TESSound*);
};

// @fnv 0x005216d0
// src: XBOX_PDB 0x005216d0
void FUN_005216d0_shell::TESObjectWEAP_SetEquipSound(TESSound* apSnd)
{
    m_pWeaponSound8 = apSnd;
}

struct FUN_005216f0_shell : public TESObjectWEAP {
    void TESObjectWEAP_SetUnEquipSound(TESSound*);
};

// @fnv 0x005216f0
// src: XBOX_PDB 0x005216f0
void FUN_005216f0_shell::TESObjectWEAP_SetUnEquipSound(TESSound* apSnd)
{
    m_pWeaponUnequipSound = apSnd;
}

void __cdecl NiSinCos_004169a0(float, float &, float &);

// one matrix row per macro use, entries in column order (the exe stores them in this order)
#define WEAP_M3_ROW(r, a, b, c) m_pEntry[r][0] = a; m_pEntry[r][1] = b; m_pEntry[r][2] = c;
// Builds a rotation matrix about the X axis from the sine and cosine of the given angle.
// @fnv 0x00524ac0
void NiMatrix3::MakeXRotation(float afAngle)
{
    float sn, cs;
    NiSinCos_004169a0(afAngle, sn, cs);

    WEAP_M3_ROW(0, 1.0f, 0.0f, 0.0f)
    WEAP_M3_ROW(1, 0.0f, cs, sn)
    WEAP_M3_ROW(2, 0.0f, -sn, cs)
}
#undef WEAP_M3_ROW

// @fnv 0x00524cf0
// src: COMMUNITY 0x00524cf0
NiAVObject* __fastcall TESObjectCELL_GetMarkerNode(TESObjectCELL* apCell)
{
    return (NiAVObject*)apCell->GetCellChildAt(1);
}

// @fnv 0x00524d10
// src: XBOX_PDB 0x00524d10
bool __fastcall PlayerCharacter_IsActually3rdPerson(bool* pThis)
{
    return pThis[0x64b];
}

class ActiveEffect;
class ActorMover;
class ActorValueOwner;
class AlchemyItem;
struct BGSEncounterZone;
class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
struct BGSMusicType;
class BGSNote;
class BGSPerk;
class BGSPerkEntry;
class BGSQuestObjective;
class BGSSaveFormBuffer;
class BGSSaveGameBuffer;
class BGSTextureSet;
class BSAnimGroupSequence;
class BSAnimNote;
class BSAnimNoteReceiver;
class BSExtraData;
class BSMultiBound;
class BSMultiBoundRoom;
class BaseProcess;
class CellMopp;
class CombatController;
class ActorCombatGroup;
class ContinuousBeamProjectile;
class DialoguePackage;
class EffectItem;
class ExtraDataList;
class ExtraLock;
class FormRecordHeader;
class FurnitureMark;
class IDebugText;
class ImageSpaceModifierInstanceDOF;
class ImageSpaceModifierInstanceDRB;
struct InventoryChanges;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
class MagicProjectile;
class MagicShaderHitEffect;
class MagicTarget;
struct MediaLocationController;
class MobileObject;
class NiAVObject;
class NiControllerManager;
class NiControllerSequence;
class NiFixedString;
class NiGeometry;
class NiLight;
class NiNode;
class NiPointLight;
class PlacedObjectInfo;
class PathingAvoidNodeArray;
class PathingLocation;
class PathingRequest;
class Projectile;
class QueuedFile;
class Script;
class ScriptLocals;
class TESActorBase;
class TESCaravanCard;
class TESClass;
class TESCombatStyle;
class TESContainer;
class TESFaction;
class TESGlobal;
class TESIdleForm;
class TESObjectARMO;
class TESObjectBOOK;
class TESObjectCLOT;
class TESObjectDOOR;
class TESObjectLIGH;
class TESPackage;
class TESQuest;
class TESRace;
class TESRegion;
class TESReputation;
class TESSkill;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
class TargetEntry;
class PathingPath;
class TrespassPackage;
class WeaponObject;
class bhkCharacterController;
class bhkMouseSpringAction;
class bhkNiCollisionObject;
class bhkRagdollController;
class bhkRigidBody;
class hkpRigidBody;
namespace fnv_00524d70 {
struct ActorCause;
struct ActorCombatEntry;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct MusicMarkerReference;
struct ExplosionForm;
struct BipedAnim;
struct BipedActor;
struct CombatGroupCollection;
struct NiNodeBooleanState;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct TESFileGroup;
struct BooleanIntegerAccessor;
struct FurnitureRelatedType;
struct BooleanFloatQuery;
struct CellDataNode;
struct MagicEffectCollection;
struct MapMarkerData;
struct Point3Offset;
struct AnimationInterpolator;
struct IndexedPointerCollection;
struct PlayerTargetLocation;
struct LocationDescriptor;
struct IntegerPairPointerRecord;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct PlayerQuestData;
struct TESRegionList;
struct TrapEntry;
struct WaterZone;
struct bhkRagdollPenetrationUtil;
struct blob4 { char b[4]; };
struct blob12 { char b[12]; };
struct blob16 { char b[16]; };
struct blob48 { char b[48]; };

extern blob12 NiPoint3_ZERO;

// @fnv 0x00524d70
// src: COMMUNITY 0x00524d70
void __fastcall PlayerCharacter_ClearAutoAim(char* this_ptr)
{
    *(int*)(this_ptr + 0xd2c) = 0;
    *(blob12*)(this_ptr + 0xd30) = NiPoint3_ZERO;
}
}  // namespace fnv_00524d70

struct Flt { BSFaceGenNiNode* GetNode() const; };
struct GlobalObject_00633c90 { char pad[4]; };
extern GlobalObject_00633c90 g_011deb7c;
// @fnv 0x00524c90
// src: XBOX_PDB 0x00524c90
BSFaceGenAnimationData* Main_WorldRootCamera()
{
    return ((BSFaceGenNiNode*)(((Flt*)&g_011deb7c)->GetNode()))->BSFaceGenNiNode::GetAnimationData();
}

struct FUN_00522440_shell
{
    int __thiscall GetValueByFlag(bool bUse);
};

// Returns the int at offset 0x244 when bUse is true, otherwise the int at offset 0x220.
// @fnv 0x00522440
int __thiscall FUN_00522440_shell::GetValueByFlag(bool bUse)
{
    if (bUse)
    {
        return *(int*)((char*)this + 0x244);
    }
    else
    {
        return *(int*)((char*)this + 0x220);
    }
}

struct FUN_00522500_shell
{
    char pad[0x234];
    unsigned int field234;
    unsigned int GetField234();
};

// @fnv 0x00522500
unsigned int FUN_00522500_shell::GetField234()
{
    return field234;
}

struct FUN_00522520_shell
{
    int __thiscall GetField238();
};

// @fnv 0x00522520
int __thiscall FUN_00522520_shell::GetField238()
{
    return *(int*)((char*)this + 0x238);
}

struct FUN_00522560_shell
{
    int __thiscall ComputeValue_00522560(bool param);
};

// Returns 2 when param is true, otherwise returns the int stored at offset 0x364 of this object.
// @fnv 0x00522560
// src: GUESS 0x00522560 (confidence: low)
int __thiscall FUN_00522560_shell::ComputeValue_00522560(bool abReturnTwo)
{
    if (abReturnTwo)
        return 2;
    else
        return *(int*)((char*)this + 0x364);
}

class BGSLoadFormBuffer;

struct FUN_0048ea80_t {
    void FUN_0048ea80(BGSLoadFormBuffer* b);
};

void FUN_0048ea80_t::FUN_0048ea80(BGSLoadFormBuffer* b) {}

struct FUN_00523120_shell : public TESForm {
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x00523120
void FUN_00523120_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    reinterpret_cast<FUN_0048ea80_t*>(reinterpret_cast<char*>(this) + 0x84)->FUN_0048ea80(buffer);
}

extern void* DAT_011c621c;

// @fnv 0x00524cb0
// src: COMMUNITY 0x00524cb0
void* get_g_LaserSight()
{
    return DAT_011c621c;
}

struct NiFixedString;
extern NiFixedString* DAT_011c6220;

// @fnv 0x00524cc0
// src: COMMUNITY 0x00524cc0
NiFixedString* get_g_AimSight()
{
    return DAT_011c6220;
}

struct FUN_00524d30_shell {
    void SetByteAtOffset1F8(char arg);
};

// @fnv 0x00524d30
void FUN_00524d30_shell::SetByteAtOffset1F8(char acValue) {
    ((char*)this)[0x1f8] = acValue;
}

struct FUN_00525be0_shell
{
    char GetByteAtOffsetB0();
};

// @fnv 0x00525be0
char FUN_00525be0_shell::GetByteAtOffsetB0()
{
    return *reinterpret_cast<char*>(reinterpret_cast<unsigned char*>(this) + 0xb0);
}

struct FUN_00645c60_shell
{
    virtual float GetField178Float() const;
};

// @fnv 0x00645c60
float FUN_00645c60_shell::GetField178Float() const
{
    return *reinterpret_cast<const float*>(reinterpret_cast<const unsigned char*>(this) + 0x178);
}

struct FUN_008bffa0_shell
{
    int __thiscall GetField228();
};

// @fnv 0x008bffa0
int __thiscall FUN_008bffa0_shell::GetField228()
{
    return *(int*)((char*)this + 0x228);
}

struct FUN_0051f5f0_shell
{
    unsigned int GetByteAt11D();
};

// @fnv 0x0051f5f0
unsigned int FUN_0051f5f0_shell::GetByteAt11D()
{
    return ((unsigned char*)this)[0x11d];
}

struct FUN_0051f610_shell {
    unsigned int GetByteAtOffset101();
};

// @fnv 0x0051f610
unsigned int FUN_0051f610_shell::GetByteAtOffset101()
{
    return ((unsigned char*)this)[0x101];
}

struct FUN_00521580_shell {
    char m_011e; // placeholder
    void TESObjectWEAP_SetNumProjectiles(bool bVal);
};

// @fnv 0x00521580
// src: XBOX_PDB 0x00521580
void FUN_00521580_shell::TESObjectWEAP_SetNumProjectiles(bool bVal)
{
    *(char*)((char*)this + 0x11E) = bVal;
}

struct FUN_00522540_shell {
    int __thiscall GetField23C();
};

// @fnv 0x00522540
int __thiscall FUN_00522540_shell::GetField23C()
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x23c);
}

namespace fnv_00522c00 {
struct Flt {
    operator unsigned int() const;
};

struct FUN_00522c00_shell {
    unsigned char TESObjectWEAP_IsEmbeddedWeapon();
    unsigned int TESObjectWEAP_GetEmbeddedWeaponNode();
};

// @fnv 0x00522c00
// src: XBOX_PDB 0x00522c00
unsigned int FUN_00522c00_shell::TESObjectWEAP_GetEmbeddedWeaponNode()
{
    if (TESObjectWEAP_IsEmbeddedWeapon())
    {
        return reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0x35c)->operator unsigned int();
    }
    return 0;
}
}  // namespace fnv_00522c00

// The base-form loader at 0x00484c50 needs two flags; TESForm has no declaration for this overload.
struct FormRecordLoadAccess : TESForm {
    void LoadRecordArguments(unsigned int, unsigned int);
};

struct WeaponRecordLoadAccess : TESObjectWEAP {
    void LoadRecordArguments(unsigned int, unsigned int);
};

// Loads the base form and value component using the same change flags.
// @fnv 0x005230b0
void WeaponRecordLoadAccess::LoadRecordArguments(unsigned int auiArg1, unsigned int auiArg2)
{
    reinterpret_cast<FormRecordLoadAccess*>(this)->LoadRecordArguments(auiArg1, auiArg2);
    TESValueForm::LoadGame_0048ea10(auiArg1, auiArg2);
}

struct BGSSaveFormBuffer;

struct FUN_00484d60_holder {
    void SaveIfChanged(BGSSaveFormBuffer*);
};

struct FUN_005230f0_shell : TESObjectWEAP {
    void TESObjectWEAP_SaveGame_005230f0(BGSSaveFormBuffer* buffer);
};

// @fnv 0x005230f0
// src: XBOX_PDB 0x005230f0
void FUN_005230f0_shell::TESObjectWEAP_SaveGame_005230f0(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(buffer);
    TESValueForm::SaveGameBGS_0048ea40(buffer);
}

struct FUN_00524cd0_shell
{
    unsigned char GetByteAt0D();
};

// @fnv 0x00524cd0
unsigned char FUN_00524cd0_shell::GetByteAt0D()
{
    return ((unsigned char*)this)[0x0d];
}

struct FUN_00524d50_shell
{
    char GetByteAtOffset1F8();
};

// @fnv 0x00524d50
char FUN_00524d50_shell::GetByteAtOffset1F8()
{
    return ((char*)this)[0x1f8];
}

void __cdecl _Deallocate(void*);
struct FUN_0051dad0_This {
    void FUN_0051db00();
    void* FUN_0051dad0(unsigned int);
};
// Calls FUN_0051db00 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0051dad0
void* FUN_0051dad0_This::FUN_0051dad0(unsigned int flags)
{
    this->FUN_0051db00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004fb7a0_obj { int BGSImpactDataSet_GetImpactData(int); };
struct FUN_00522ba0_obj { int TESObjectWEAP_GetImpactData(int); };
// If the object at offset 0x24C is non-null, forwards a1 to its FUN_004fb7a0 and returns the result; otherwise returns 0.
// @fnv 0x00522ba0
// src: XBOX_PDB 0x00522ba0
int FUN_00522ba0_obj::TESObjectWEAP_GetImpactData(int a1)
{
    int val = 0;
    if (*reinterpret_cast<FUN_004fb7a0_obj**>(reinterpret_cast<char*>(this) + 0x24C) != 0)
        val = (*reinterpret_cast<FUN_004fb7a0_obj**>(reinterpret_cast<char*>(this) + 0x24C))->BGSImpactDataSet_GetImpactData(a1);
    return val;
}

namespace fnv_00522be0 {
struct Flt { operator unsigned int(); };
struct FUN_00522be0_shell {
    unsigned int TESObjectWEAP_GetVATSAttackName();
};
// @fnv 0x00522be0
// src: COMMUNITY 0x00522be0
unsigned int FUN_00522be0_shell::TESObjectWEAP_GetVATSAttackName()
{
    return ((Flt*)((char*)this + 0x368))->operator unsigned int();
}
}  // namespace fnv_00522be0

struct FUN_0051b070_shell { void TESForm_SaveGame(unsigned int); void SaveGame_0048e9e0(unsigned int); };
struct FUN_00523080_shell { void TESObjectWEAP_SaveGame(unsigned int); };
// Forwards aiFlags to FUN_00484c20 on this and to FUN_0048e9e0 on the object at offset 0x84.
// @fnv 0x00523080
// src: XBOX_PDB 0x00523080
void FUN_00523080_shell::TESObjectWEAP_SaveGame(unsigned int aiFlags)
{
    ((FUN_0051b070_shell*)this)->TESForm_SaveGame(aiFlags);
    ((FUN_0051b070_shell*)((char*)this + 0x84))->SaveGame_0048e9e0(aiFlags);
}

float __cdecl BSMAX_00404010(float, float);
struct FUN_00524b80_This : TESObjectWEAP { float TESObjectWEAP_GetMinSpread(bool); };
// Returns the weapon's spread at offset 0x104, reduced by the weapon-mod decrease-spread effect when bModValue is set.
// @fnv 0x00524b80
// src: COMMUNITY 0x00524b80
float FUN_00524b80_This::TESObjectWEAP_GetMinSpread(bool abApplyMod)
{
	if (abApplyMod)
		return BSMAX_00404010(0.0f, *(float*)((char*)this + 0x104) - GetModdedWeaponValue(WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD, 0));
	else
		return *(float*)((char*)this + 0x104);
}

float __cdecl BSMAX_00404010(float, float);
struct FUN_00524be0_shell : TESObjectWEAP { float TESObjectWEAP_GetSpread(bool); };
// Returns the weapon's spread at offset 0x108, reduced by the weapon-mod decrease-spread effect when bModValue is set.
// @fnv 0x00524be0
// src: COMMUNITY 0x00524be0
float FUN_00524be0_shell::TESObjectWEAP_GetSpread(bool abApplyMod)
{
	if (abApplyMod)
		return BSMAX_00404010(0.0f, *(float *)((char *)this + 0x108) - GetModdedWeaponValue(WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD, 0));
	else
		return *(float *)((char *)this + 0x108);
}

namespace fnv_00524c40 {
struct TransHolder { NiMatrix3 rot; NiPoint3 pos; float scl; NiPoint3 ComputeValue_00524c40(NiPoint3 const &) const; };
// Applies the holder's rotation and scale to a point, then adds its position offset.
// @fnv 0x00524c40
// src: GUESS 0x00524c40 (confidence: low)
NiPoint3 TransHolder::ComputeValue_00524c40(NiPoint3 const &aPoint) const
{
    return (rot * aPoint) * scl + pos;
}
}  // namespace fnv_00524c40

struct Unk005256b0 {
    bool TESObjectWEAP_IsEmbeddedWeapon();
    const char* TESObjectWEAP_GetEmbeddedWeaponNode();
    const char* GetProjectileNodeName();
};
// Returns the result of FUN_00522c00 if FUN_0046e8c0 and FUN_00522c00 succeed and the string is non-empty, otherwise "ProjectileNode".
// @fnv 0x005256b0
const char* Unk005256b0::GetProjectileNodeName()
{
    return TESObjectWEAP_IsEmbeddedWeapon() && TESObjectWEAP_GetEmbeddedWeaponNode() && *TESObjectWEAP_GetEmbeddedWeaponNode() ? TESObjectWEAP_GetEmbeddedWeaponNode() : "ProjectileNode";
}

struct SceneObjectLookup { static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*); };
struct UnkClass25700 { const char* GetProjectileNodeName(); NiAVObject* TESObjectWEAP_GetFireNode(NiAVObject*); };
// @fnv 0x00525700
// src: XBOX_PDB 0x00525700
NiAVObject* UnkClass25700::TESObjectWEAP_GetFireNode(NiAVObject* apObject)
{
    NiAVObject* pFoundObject;
    const char* pNodeName;
    pNodeName = this->GetProjectileNodeName();
    pFoundObject = SceneObjectLookup::GetObjectByName(apObject, pNodeName);
    if (pFoundObject == 0)
        pFoundObject = SceneObjectLookup::GetObjectByName(apObject, "##ProjectileNode");
    return pFoundObject;
}

struct S_00522470
{
    char pad0[0x224];
    void* p224;
    char pad1[0x20];
    void* p248;
    void* GetPointerByFlag(bool);
};
// Returns p248 when the flag is true, otherwise returns p224.
// @fnv 0x00522470
void* S_00522470::GetPointerByFlag(bool a)
{
    if (a)
        return p248;
    else
        return p224;
}

struct S522c30
{
    unsigned char _pad[0x11F];
    unsigned char field_11F;
    bool TESObjectWEAP_IsEmbeddedWeapon();
    int TESObjectWEAP_GetEmbeddedWeaponConditionValue();
};
// Returns -1 unless FUN_0046e8c0 succeeds, otherwise field_11F + 0x19 clamped to at most 0x1F.
// @fnv 0x00522c30
// src: COMMUNITY 0x00522c30
int S522c30::TESObjectWEAP_GetEmbeddedWeaponConditionValue()
{
    int model = -1;
    if (TESObjectWEAP_IsEmbeddedWeapon())
    {
        model = field_11F + 0x19;
        if (model >= 0x20)
            model = 0x1F;
    }
    return model;
}

struct FUN_00484bf0 {
    unsigned short GetSaveSize(unsigned int);
};
struct WeaponRecordSaveSizeAccess : TESObjectWEAP {
    unsigned short GetRecordSaveSize(unsigned int aiFlags);
};

// Returns the sum of the save sizes reported by the two embedded objects for the given flags.
// @fnv 0x00523020
unsigned short WeaponRecordSaveSizeAccess::GetRecordSaveSize(unsigned int aiFlags)
{
    unsigned short usSize = 0;
    usSize += reinterpret_cast<FUN_00484bf0*>(this)->GetSaveSize(aiFlags);
    usSize += TESValueForm::GetFlaggedDataSize(aiFlags);
    return usSize;
}

struct ModelPathIface {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual char* GetModelFilePath();
};
struct FUN_00522df0_shell : public TESObjectWEAP {
    int FUN_00446390();
    TESModel* GetModelForModFlags(unsigned char acModFlags, bool abNoWorldModel);
};

// @fnv 0x00522df0
TESModel* FUN_00522df0_shell::GetModelForModFlags(unsigned char acModFlags, bool abNoWorldModel)
{
    TESModel* m_kModelObjectsItem = 0;
    if (FUN_00446390() == 0 && !abNoWorldModel)
    {
        if (*((ModelPathIface*)&m_kModel3rdPerson)->GetModelFilePath())
            return &m_kModel3rdPerson;
        else
            return this;
    }
    if (acModFlags & 1)
    {
        if (acModFlags & 2)
        {
            if (acModFlags & 4)
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap7)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap7;
            }
            else
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap4)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap4;
            }
        }
        else
        {
            if (acModFlags & 4)
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap5)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap5;
            }
            else
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap1)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap1;
            }
        }
    }
    else
    {
        if (acModFlags & 2)
        {
            if (acModFlags & 4)
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap6)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap6;
            }
            else
            {
                if (*((ModelPathIface*)&m_kWeaponModTextureSwap2)->GetModelFilePath())
                    m_kModelObjectsItem = &m_kWeaponModTextureSwap2;
            }
        }
        else if (acModFlags & 4)
        {
            if (*((ModelPathIface*)&m_kWeaponModTextureSwap3)->GetModelFilePath())
                m_kModelObjectsItem = &m_kWeaponModTextureSwap3;
        }
    }
    if (!m_kModelObjectsItem || GetFormID() == 0x1735d4)
        m_kModelObjectsItem = this;
    return m_kModelObjectsItem;
}

struct FUN_00525450_shell {
    void QueueModelsForLoad(int, class QueuedFile*);
};

// @fnv 0x00525450
void FUN_00525450_shell::QueueModelsForLoad(int aiIndex, class QueuedFile* apFile)
{
    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x104)->GetModelLength())
        g_modelLoader->ProcessModelRequest(reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x104), aiIndex, apFile, 0, true, false, false);
    if (reinterpret_cast<TESObjectWEAP*>(reinterpret_cast<char*>(this) - 0xcc)->GetProjectileData(0))
        reinterpret_cast<BGSPreloadable*>(reinterpret_cast<char*>(reinterpret_cast<TESObjectWEAP*>(reinterpret_cast<char*>(this) - 0xcc)->GetProjectileData(0)) + 0x54)->QueueResourceLoad((IO_TASK_PRIORITY)aiIndex, apFile);
    if (*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x180))
        reinterpret_cast<BGSPreloadable*>(reinterpret_cast<char*>(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x180)) + 0x18)->QueueResourceLoad((IO_TASK_PRIORITY)aiIndex, apFile);
}

struct GlobalObject_0045cfe0 { int* Int(); };
extern GlobalObject_0045cfe0 g_011cd3b4;
extern GlobalObject_0045cfe0 g_011cd538;
extern GlobalObject_0045cfe0 g_011cdde0;
struct FUN_00525620_shell { int GetStateValue(bool a, bool b); };
// Reads a state value from offset 0x364, overridden to 2 or 1 by the flags, and returns the int from the matching global.
// @fnv 0x00525620
int FUN_00525620_shell::GetStateValue(bool abForceState2, bool abForceState1)
{
    int r7 = 0;
    int s = *(int*)((char*)this + 0x364);
    if (abForceState2) s = 2;
    if (abForceState1) s = 1;
    switch (s) {
    case 2: r7 = *g_011cd3b4.Int(); break;
    case 1: r7 = *g_011cd538.Int(); break;
    case 0: r7 = *g_011cdde0.Int(); break;
    }
    return r7;
}

struct FUN_0051db00 :
    public TESBoundObject,
    public TESFullName,
    public TESModelTextureSwap,
    public TESIcon,
    public TESScriptableForm,
    public TESEnchantableForm,
    public TESValueForm,
    public TESWeightForm,
    public TESHealthForm,
    public TESAttackDamageForm,
    public BGSAmmoForm,
    public BGSClipRoundsForm,
    public BGSDestructibleObjectForm,
    public BGSRepairItemList,
    public BGSEquipType,
    public BGSPreloadable,
    public BGSMessageIcon,
    public BGSBipedModelList,
    public BGSPickupPutdownSounds
{
    WeaponProperties data;
    WeaponCriticalData m_kCriticalData;
    TESModel m_kModel;
    TESModel m_kModel1stPerson;
    TESModel m_kModel3rdPerson;
    TESEffectShader* m_pWeaponEffectShader;
    TESSound* m_pWeaponSound1;
    TESSound* m_pWeaponSound2;
    TESSound* m_pWeaponSound3;
    TESSound* m_pWeaponSound4;
    TESSound* m_pWeaponSound5;
    TESSound* m_pWeaponSound6;
    TESSound* m_pWeaponSound7;
    TESSound* m_pWeaponSound8;
    TESSound* m_pWeaponUnequipSound;
    TESSound* m_pWeaponEquipSound;
    TESSound* m_pWeaponPickupSound;
    TESSound* m_pWeaponDropSound;
    BGSImpactDataSet* m_pImpactDataSet;
    TESObjectSTAT* p1stPersonObject;
    TESObjectSTAT* p1stPersonMod1Object;
    TESObjectSTAT* p1stPersonMod2Object;
    TESObjectSTAT* p1stPersonMod3Object;
    TESObjectSTAT* p1stPersonMod12Object;
    TESObjectSTAT* p1stPersonMod23Object;
    TESObjectSTAT* p1stPersonMod13Object;
    TESObjectSTAT* p1stPersonMod123Object;
    TESModelTextureSwap m_kWeaponModTextureSwap1;
    TESModelTextureSwap m_kWeaponModTextureSwap2;
    TESModelTextureSwap m_kWeaponModTextureSwap3;
    TESModelTextureSwap m_kWeaponModTextureSwap4;
    TESModelTextureSwap m_kWeaponModTextureSwap5;
    TESModelTextureSwap m_kWeaponModTextureSwap6;
    TESModelTextureSwap m_kWeaponModTextureSwap7;
    TESObjectIMOD* m_pWeaponMod1;
    TESObjectIMOD* m_pWeaponMod2;
    TESObjectIMOD* m_pWeaponMod3;
    BSStringT<char> m_kEmbeddedWeaponNodeName;
    SOUND_LEVEL m_eSoundLevel;
    BSStringT<char> VATSAttackName;
    WeaponVATSData m_kVATSData;
    bool m_bHasReloadAnimation;
    unsigned char layoutPadding385[3];

    ~FUN_0051db00();
};

// Destructor that clears the weapon's data via TESObjectWEAP::ClearData.
// @fnv 0x0051db00
FUN_0051db00::~FUN_0051db00()
{
    reinterpret_cast<TESObjectWEAP*>(this)->TESObjectWEAP::ClearData();
}

class FUN_0051f590_cls {
public:
    unsigned int m_000;
    unsigned int m_004;
    unsigned int m_008;
    unsigned int m_00C;
    unsigned int m_010;
    unsigned int m_014;
    unsigned int m_018;
    unsigned int m_01C;
    unsigned int m_020;
    unsigned int m_024;
    unsigned int m_028;
    unsigned int m_02C;
    unsigned int m_030;
    unsigned int m_034;
    unsigned int m_038;
    unsigned int m_03C;
    unsigned int m_040;
    unsigned int m_044;
    unsigned int m_048;
    unsigned int m_04C;
    unsigned int m_050;
    unsigned int m_054;
    unsigned int m_058;
    unsigned int m_05C;
    unsigned int m_060;
    unsigned int m_064;
    unsigned int m_068;
    unsigned int m_06C;
    unsigned int m_070;
    unsigned int m_074;
    unsigned int m_078;
    unsigned int m_07C;
    unsigned int m_080;
    unsigned int m_084;
    unsigned int m_088;
    unsigned int m_08C;
    unsigned int m_090;
    unsigned int m_094;
    unsigned int m_098;
    unsigned int m_09C;
    unsigned int m_0A0;
    unsigned int m_0A4;
    unsigned int m_0A8;
    unsigned int m_0AC;
    unsigned int m_0B0;
    unsigned int m_0B4;
    unsigned int m_0B8;
    unsigned int m_0BC;
    unsigned int m_0C0;
    unsigned int m_0C4;
    unsigned int m_0C8;
    unsigned int m_0CC;
    unsigned int m_0D0;
    unsigned int m_0D4;
    unsigned int m_0D8;
    unsigned int m_0DC;
    unsigned int m_0E0;
    unsigned int m_0E4;
    unsigned int m_0E8;
    unsigned int m_0EC;
    unsigned int m_0F0;
    unsigned int m_0F4;
    unsigned int m_0F8;
    unsigned int m_0FC;
    unsigned int m_100;
    unsigned int m_104;
    unsigned int m_108;
    unsigned int m_10C;
    unsigned int m_110;
    unsigned int m_114;
    unsigned int m_118;
    unsigned int m_11C;
    unsigned int m_120;
    unsigned int m_124;
    unsigned int m_128;
    unsigned int m_flags;
    void SetFlag2(bool abSet);
};

// @fnv 0x0051f590
void FUN_0051f590_cls::SetFlag2(bool abSet)
{
    abSet ? (m_flags |= 2) : (m_flags &= 0xfffffffd);
}

typedef unsigned int UInt32;



void __cdecl WriteChunkU32(UInt32 chunk, UInt32 value);
void __cdecl WriteChunkStr(UInt32 chunk, const char* str, UInt32 len);
void __cdecl WriteChunkBuf(UInt32 chunk, void* buf, UInt32 len);
bool __cdecl IsBigEndian();

// a BSStringT<char> member viewed with out-of-line Length/CStr calls (the shared BSString defines CStr inline)
struct WeaponStringView
{
    char* pString;
    unsigned short len;
    unsigned short max;
    UInt32 Length();
    const char* CStr();
};
struct FullName { char pad[0xc]; void Save(); };
struct ModelSwap { char pad[0x20]; void Save(UInt32 a, UInt32 b, UInt32 c); void SaveSwap(UInt32 a); };
struct Icon { char pad[0xc]; void Save(UInt32 a); };
struct Scriptable { char pad[0xc]; void Save(); };
struct Enchantable { char pad[0x30]; void Save(); };
struct ValueForm { char pad[0x10]; void Save(); };
struct WeightForm { char pad[0x8]; void Save(); };
struct HealthForm { char pad[0x8]; void Save(); };
struct AttackDamage { char pad[0xc]; void Save(); };
struct MessageFullNameRecord { char pad[0x10]; void Save(UInt32 a); };
struct AmmoForm { char pad[0x8]; void Save(); };
struct ClipRounds { char pad[0xc]; void Save(); };
struct WeapData { char pad[0x24]; TESForm* pProjectile; char pad2[0xa4]; void Swap(); };
struct CritData { char pad[0xc]; TESForm* pEffect; void Swap(); };
struct Model { char pad[0x18]; void Save(UInt32 a, UInt32 b); };
struct ModModel { char pad[0x20]; void Save(UInt32 a, UInt32 b, UInt32 c); };
struct VATSData { TESForm* pEffect; char pad[0x10]; void Swap(); };

struct Weapon
{
    char pad000[0x30];
    FullName fullName;          // 0x30
    ModelSwap model;            // 0x3c
    Icon icon;                  // 0x5c
    Scriptable script;          // 0x68
    Enchantable enchant;        // 0x74
    ValueForm value;            // 0xa4
    WeightForm weight;          // 0xb4
    HealthForm health;          // 0xbc
    AttackDamage damage;        // 0xc4
    MessageFullNameRecord messageIcon;    // 0xd0
    AmmoForm ammo;              // 0xe0
    ClipRounds clip;            // 0xe8
    WeapData data;              // 0xf4
    CritData crit;              // 0x1c0
    Model shellModel;           // 0x1d0
    Model scopeModel;           // 0x1e8
    Model worldModel;           // 0x200
    TESForm* m_pWeaponEffectShader;      // 0x218
    TESForm* m_pWeaponSound1;      // 0x21c
    TESForm* m_pWeaponSound2;     // 0x220
    TESForm* m_pWeaponSound3;    // 0x224
    TESForm* m_pWeaponSound4;       // 0x228
    TESForm* pAttackFail;       // 0x22c
    TESForm* pMeleeBlock;       // 0x230
    TESForm* m_pIdleForm;             // 0x234
    TESForm* pEquip;            // 0x238
    TESForm* pUnEquip;          // 0x23c
    TESForm* pSilenced;         // 0x240
    TESForm* pSilenced2;        // 0x244
    TESForm* pSilenced2D;       // 0x248
    TESForm* pImpact;           // 0x24c
    TESForm* p1st;              // 0x250
    TESForm* p1st1;             // 0x254
    TESForm* p1st2;             // 0x258
    TESForm* p1st3;             // 0x25c
    TESForm* p1st12;            // 0x260
    TESForm* p1st23;            // 0x264
    TESForm* p1st13;            // 0x268
    TESForm* p1st123;           // 0x26c
    ModModel mod1;              // 0x270
    ModModel mod2;              // 0x290
    ModModel mod3;              // 0x2b0
    ModModel mod12;             // 0x2d0
    ModModel mod13;             // 0x2f0
    ModModel mod23;             // 0x310
    ModModel mod123;            // 0x330
    TESForm* pMod1;             // 0x350
    TESForm* pMod2;             // 0x354
    TESForm* pMod3;             // 0x358
    WeaponStringView embeddedNode;      // 0x35c
    UInt32 soundLevel;          // 0x364
    WeaponStringView vatsAttackName;    // 0x368
    VATSData vats;              // 0x370

    void BeginSave();
    void EndSave();
    void SaveHeader();
    bool HasScope();
    void Save();
};

// @fnv 0x00521730
void Weapon::Save()
{
    UInt32 savedProj;
    UInt32 savedVats;
    UInt32 savedCrit;

    BeginSave();
    fullName.Save();
    model.Save(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    model.SaveSwap(0x44444f4d);
    icon.Save(0x4e4f4349);
    messageIcon.Save(0x4f43494d);
    script.Save();
    enchant.Save();
    value.Save();
    weight.Save();
    health.Save();
    damage.Save();
    ammo.Save();
    clip.Save();
    shellModel.Save(0x32444f4d, 0x54324f4d);
    if (HasScope()) {
        scopeModel.Save(0x33444f4d, 0x54334f4d);
        if (m_pWeaponEffectShader) {
            UInt32 a = m_pWeaponEffectShader->GetFormID();
            WriteChunkU32(0x44534645, a);
        }
    }
    worldModel.Save(0x34444f4d, 0x54344f4d);
    mod1.Save(0x3144574d, 0x3154574d, 0x53444f4d);
    mod2.Save(0x3244574d, 0x3254574d, 0x53444f4d);
    mod3.Save(0x3444574d, 0x3454574d, 0x53444f4d);
    mod12.Save(0x3344574d, 0x3354574d, 0x53444f4d);
    mod13.Save(0x3544574d, 0x3554574d, 0x53444f4d);
    mod23.Save(0x3644574d, 0x3654574d, 0x53444f4d);
    mod123.Save(0x3744574d, 0x3754574d, 0x53444f4d);
    if (embeddedNode.Length())
        WriteChunkStr(0x4d414e4e, embeddedNode.CStr(), embeddedNode.Length() + 1);
    if (vatsAttackName.Length())
        WriteChunkStr(0x4d4e4156, vatsAttackName.CStr(), vatsAttackName.Length() + 1);
    if (pImpact) { UInt32 b = pImpact->GetFormID(); WriteChunkU32(0x4d414e49, b); }
    if (p1st) { UInt32 c = p1st->GetFormID(); WriteChunkU32(0x4d414e57, c); }
    if (p1st1) { UInt32 d = p1st1->GetFormID(); WriteChunkU32(0x314d4e57, d); }
    if (p1st2) { UInt32 e = p1st2->GetFormID(); WriteChunkU32(0x324d4e57, e); }
    if (p1st3) { UInt32 f = p1st3->GetFormID(); WriteChunkU32(0x344d4e57, f); }
    if (p1st12) { UInt32 g = p1st12->GetFormID(); WriteChunkU32(0x334d4e57, g); }
    if (p1st23) { UInt32 h = p1st23->GetFormID(); WriteChunkU32(0x364d4e57, h); }
    if (p1st13) { UInt32 i = p1st13->GetFormID(); WriteChunkU32(0x354d4e57, i); }
    if (p1st123) { UInt32 j = p1st123->GetFormID(); WriteChunkU32(0x374d4e57, j); }
    if (pMod1) { UInt32 k = pMod1->GetFormID(); WriteChunkU32(0x31494d57, k); }
    if (pMod2) { UInt32 l = pMod2->GetFormID(); WriteChunkU32(0x32494d57, l); }
    if (pMod3) { UInt32 m = pMod3->GetFormID(); WriteChunkU32(0x33494d57, m); }
    if (m_pWeaponSound1) { UInt32 n = m_pWeaponSound1->GetFormID(); WriteChunkU32(0x4d414e53, n); }
    if (m_pWeaponSound2) { UInt32 o = m_pWeaponSound2->GetFormID(); WriteChunkU32(0x4d414e53, o); }
    if (m_pWeaponSound3) { UInt32 p = m_pWeaponSound3->GetFormID(); WriteChunkU32(0x4d414e58, p); }
    if (m_pWeaponSound4) { UInt32 q = m_pWeaponSound4->GetFormID(); WriteChunkU32(0x374d414e, q); }
    if (pAttackFail) { UInt32 r = pAttackFail->GetFormID(); WriteChunkU32(0x4d414e54, r); }
    if (pMeleeBlock) { UInt32 s = pMeleeBlock->GetFormID(); WriteChunkU32(0x364d414e, s); }
    if (m_pIdleForm) { UInt32 t = m_pIdleForm->GetFormID(); WriteChunkU32(0x4d414e55, t); }
    if (pEquip) { UInt32 u = pEquip->GetFormID(); WriteChunkU32(0x394d414e, u); }
    if (pUnEquip) { UInt32 v = pUnEquip->GetFormID(); WriteChunkU32(0x384d414e, v); }
    if (pSilenced) { UInt32 w = pSilenced->GetFormID(); WriteChunkU32(0x31534d57, w); }
    if (pSilenced2) { UInt32 x = pSilenced2->GetFormID(); WriteChunkU32(0x31534d57, x); }
    if (pSilenced2D) { UInt32 y = pSilenced2D->GetFormID(); WriteChunkU32(0x32534d57, y); }

    SaveHeader();

    savedCrit = (UInt32)data.pProjectile;
    data.pProjectile = (TESForm*)(data.pProjectile ? data.pProjectile->GetFormID() : 0);
    if (IsBigEndian())
        data.Swap();
    WriteChunkBuf(0x4d414e44, &data, 0xcc);
    if (IsBigEndian())
        data.Swap();

    savedProj = (UInt32)crit.pEffect;
    crit.pEffect = (TESForm*)(crit.pEffect ? crit.pEffect->GetFormID() : 0);
    if (IsBigEndian())
        crit.Swap();
    WriteChunkBuf(0x54445243, &crit, 0x10);
    if (IsBigEndian())
        crit.Swap();

    savedVats = (UInt32)vats.pEffect;
    vats.pEffect = (TESForm*)(vats.pEffect ? vats.pEffect->GetFormID() : 0);
    if (IsBigEndian())
        vats.Swap();
    WriteChunkBuf(0x53544156, &vats, 0x14);
    if (IsBigEndian())
        vats.Swap();

    WriteChunkU32(0x4d414e56, soundLevel);

    data.pProjectile = (TESForm*)savedCrit;
    crit.pEffect = (TESForm*)savedProj;
    vats.pEffect = (TESForm*)savedVats;
    EndSave();
}

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern unsigned char DAT_01183028;
extern unsigned char DAT_01183998;
TESObjectWEAP* __cdecl FUN_00ec43fb(unsigned int, unsigned int, void*, void*, unsigned int);
struct StringCopyAccess : BSStringT<char> {
    const char* Modelloader_GetReferencedThis(bool);
    void FUN_004037f0(const char*);
};
struct StackWord { unsigned int word; };
struct WeaponCopyAccess;
extern "C" void __fastcall TESForm_CopyAllComponents(WeaponCopyAccess*, StackWord);
extern "C" void* __fastcall FUN_008d8ac0(WeaponCopyAccess*);
struct WeaponCopyAccess : TESObjectWEAP {
    void CopyFromWeapon(unsigned int id);
    void FUN_008d8ae0(void*);
    BGSImpactDataSet* FUN_008d8b00();
    TESObjectSTAT* GetModSlotStat(unsigned char);
    TESObjectIMOD* FUN_004bd570(unsigned char);
    TESSound* GetValueByFlag(bool);
    TESSound* GetPointerByFlag(bool);
    TESSound* GetField228();
    TESSound* GetField230();
    TESSound* GetField22C();
    TESSound* FUN_00522500();
    TESSound* GetField238();
    TESSound* GetField23C();
    TESSound* FUN_00521630();
    TESSound* GetField244();
    TESSound* FUN_005224a0();
    void TESObjectWEAP_SetAttackSound2(TESSound*);
    void FUN_005c8a30(TESSound*);
    void FUN_00521710(BGSImpactDataSet*);
    void TESObjectWEAP_SetModAttackSound(TESSound*);
    void FUN_008d8a80(TESSound*);
    void FUN_008d8aa0(TESSound*);
    SOUND_LEVEL ComputeValue_00522560(bool);
    unsigned int FUN_00401170();
    void FUN_004f15a0(unsigned int);
};
// Copies weapon data, strings, mods, sounds and flags from the weapon with the given id into this object.
// @fnv 0x00522020
void WeaponCopyAccess::CopyFromWeapon(unsigned int id)
{
    WeaponCopyAccess* source = (WeaponCopyAccess*)FUN_00ec43fb(id, 0, &DAT_01183028, &DAT_01183998, 0);
    if (source == 0) return;
    {
        TESForm_CopyAllComponents(this, *(StackWord*)&id);
        m_kModel.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kModel));
        ((StringCopyAccess*)&m_kEmbeddedWeaponNodeName)->FUN_004037f0(
            ((StringCopyAccess*)&source->m_kEmbeddedWeaponNodeName)->Modelloader_GetReferencedThis(false));
        ((StringCopyAccess*)&VATSAttackName)->FUN_004037f0(
            ((StringCopyAccess*)&source->VATSAttackName)->Modelloader_GetReferencedThis(false));
        m_kModel3rdPerson.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kModel3rdPerson));
        m_kModel1stPerson.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kModel1stPerson));
        SetEffectShader(source->GetScopeEffect());
        FUN_008d8ae0(FUN_008d8ac0(source));
        FUN_00521710(source->FUN_008d8b00());
        SetModObject(1, source->GetModSlotStat(1));
        SetModObject(2, source->GetModSlotStat(2));
        SetModObject(3, source->GetModSlotStat(3));
        SetModObject(4, source->GetModSlotStat(4));
        SetModObject(5, source->GetModSlotStat(5));
        SetModObject(6, source->GetModSlotStat(6));
        SetModObject(7, source->GetModSlotStat(7));
        SetModItem((unsigned char)1, source->FUN_004bd570(1));
        SetModItem((unsigned char)2, source->FUN_004bd570(2));
        SetModItem((unsigned char)4, source->FUN_004bd570(4));
        m_kWeaponModTextureSwap1.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap1));
        m_kWeaponModTextureSwap2.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap2));
        m_kWeaponModTextureSwap3.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap3));
        m_kWeaponModTextureSwap4.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap4));
        m_kWeaponModTextureSwap5.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap5));
        m_kWeaponModTextureSwap6.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap6));
        m_kWeaponModTextureSwap7.CopyFromBase(static_cast<BaseFormComponent*>(&source->m_kWeaponModTextureSwap7));
        memcpy(&data, &source->data, sizeof(data));
        memcpy(&m_kCriticalData, &source->m_kCriticalData, sizeof(m_kCriticalData));
        memcpy(&m_kVATSData, &source->m_kVATSData, sizeof(m_kVATSData));
        SetAttackSound(source->GetAttackSound(false));
        TESObjectWEAP_SetAttackSound2(source->GetValueByFlag(false));
        FUN_005c8a30(source->GetPointerByFlag(false));
        TESObjectWEAP_SetAttackLoop(source->GetField228());
        SetMeleeBlockSound(source->GetField230());
        SetAttackFailSound(source->GetField22C());
        SetIdleSound(source->FUN_00522500());
        SetEquipSound(source->GetField238());
        SetUnequipSound(source->GetField23C());
        TESObjectWEAP_SetModAttackSound(source->FUN_00521630());
        FUN_008d8a80(source->GetField244());
        FUN_008d8aa0(source->FUN_005224a0());
        m_eSoundLevel = source->ComputeValue_00522560(false);
        FUN_004f15a0(source->FUN_00401170());
    }
}

struct FUN_00522d80_virtual_object {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual char* v05();
};

struct FUN_00522d80_shell {
    unsigned char field00[0x3C];
    FUN_00522d80_virtual_object field3C;
    unsigned char field40[0x1C0];
    FUN_00522d80_virtual_object field200;

    FUN_00522d80_virtual_object* TESObjectWEAP_GetWorldTESModel();
};

// Returns field200 if its v05()[0] is nonzero, otherwise returns field3C (or null if this is null).
// @fnv 0x00522d80
// src: XBOX_PDB 0x00522d80
FUN_00522d80_virtual_object* FUN_00522d80_shell::TESObjectWEAP_GetWorldTESModel() {
    FUN_00522d80_virtual_object* result = 0;

    if (field200.v05()[0] != 0) {
        result = &field200;
    }

    if (result == 0) {
        result = this ? &field3C : 0;
    }

    return result;
}

struct ConversionTag {};
void __cdecl SwapField(int*, ConversionTag);
struct ResetAccess {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    int field90;
    int field94;
    int field98;
    int field9C;
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int fieldAC;
    int fieldB0;
    int fieldB4;
    int fieldB8;
    int fieldBC;
    int fieldC0;
    int fieldC4;
    int fieldC8;
    void OBJ_WEAP_Endian();
};
// Calls SwapField on most of the object's int fields, skipping field00, field0C, field20, field24, field28, fieldA4 and fieldAC.
// @fnv 0x00520ff0
// src: XBOX_PDB 0x00520ff0
void ResetAccess::OBJ_WEAP_Endian() {
    SwapField(&field04, ConversionTag());
    SwapField(&field08, ConversionTag());
    SwapField(&field10, ConversionTag());
    SwapField(&field14, ConversionTag());
    SwapField(&field18, ConversionTag());
    SwapField(&field1C, ConversionTag());
    SwapField(&field2C, ConversionTag());
    SwapField(&field30, ConversionTag());
    SwapField(&field34, ConversionTag());
    SwapField(&field38, ConversionTag());
    SwapField(&field3C, ConversionTag());
    SwapField(&field40, ConversionTag());
    SwapField(&field44, ConversionTag());
    SwapField(&field48, ConversionTag());
    SwapField(&field4C, ConversionTag());
    SwapField(&field50, ConversionTag());
    SwapField(&field54, ConversionTag());
    SwapField(&field58, ConversionTag());
    SwapField(&field5C, ConversionTag());
    SwapField(&field60, ConversionTag());
    SwapField(&field64, ConversionTag());
    SwapField(&field68, ConversionTag());
    SwapField(&field6C, ConversionTag());
    SwapField(&field70, ConversionTag());
    SwapField(&field74, ConversionTag());
    SwapField(&field78, ConversionTag());
    SwapField(&field7C, ConversionTag());
    SwapField(&field80, ConversionTag());
    SwapField(&field84, ConversionTag());
    SwapField(&field88, ConversionTag());
    SwapField(&field8C, ConversionTag());
    SwapField(&field90, ConversionTag());
    SwapField(&field94, ConversionTag());
    SwapField(&field98, ConversionTag());
    SwapField(&field9C, ConversionTag());
    SwapField(&fieldA0, ConversionTag());
    SwapField(&fieldA8, ConversionTag());
    SwapField(&fieldC8, ConversionTag());
    SwapField(&fieldB0, ConversionTag());
    SwapField(&fieldB4, ConversionTag());
    SwapField(&fieldB8, ConversionTag());
    SwapField(&fieldBC, ConversionTag());
    SwapField(&fieldC0, ConversionTag());
    SwapField(&fieldC4, ConversionTag());
}

struct WeaponCompareAccess : TESObjectWEAP {
    bool IsDifferentFrom(TESForm*);
    bool TESForm_CompareAllComponents(TESForm*);
    void* FUN_008d8ac0();
    void* FUN_008d8b00();
    void* GetModSlotStat(unsigned char);
    void* FUN_004bd570(unsigned char);
    void* GetOffsetF4();
    int GetValueByFlag(bool);
    int GetPointerByFlag(bool);
    int ComputeValue_00522560(bool);
    int GetField228();
    int GetField22C();
    int GetField230();
    int FUN_00522500();
    int GetField238();
    int GetField23C();
    int GetField244();
    int FUN_005224a0();
};
struct WeaponStringCompare {
    int CompareString(const BSStringT<char>*, bool);
};
int __cdecl memcmp(const void*, const void*, unsigned int);
// Compares this weapon against another TESObjectWEAP across many fields and accessors, returning true on the first difference or when the form is not a weapon.
// @fnv 0x00522590
bool WeaponCompareAccess::IsDifferentFrom(TESForm* form) {
    WeaponCompareAccess* other = (WeaponCompareAccess*)dynamic_cast<TESObjectWEAP*>(form);
    if (!other) return true;
    if (TESForm_CompareAllComponents(other)) return true;
    if (m_kModel.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kModel))) return true;
    if (m_kModel3rdPerson.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kModel3rdPerson))) return true;
    if (m_kWeaponModTextureSwap1.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap1))) return true;
    if (m_kWeaponModTextureSwap2.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap2))) return true;
    if (m_kWeaponModTextureSwap3.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap3))) return true;
    if (m_kWeaponModTextureSwap4.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap4))) return true;
    if (m_kWeaponModTextureSwap5.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap5))) return true;
    if (m_kWeaponModTextureSwap6.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap6))) return true;
    if (m_kWeaponModTextureSwap7.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kWeaponModTextureSwap7))) return true;
    if (m_kModel1stPerson.CompareWithBase(static_cast<BaseFormComponent*>(&other->m_kModel1stPerson))) return true;
    if (GetScopeEffect() != other->GetScopeEffect()) return true;
    if (FUN_008d8ac0() != other->FUN_008d8ac0()) return true;
    if (FUN_008d8b00() != other->FUN_008d8b00()) return true;
    if (GetModSlotStat(1) != other->GetModSlotStat(1)) return true;
    if (GetModSlotStat(2) != other->GetModSlotStat(2)) return true;
    if (GetModSlotStat(3) != other->GetModSlotStat(3)) return true;
    if (GetModSlotStat(4) != other->GetModSlotStat(4)) return true;
    if (GetModSlotStat(5) != other->GetModSlotStat(5)) return true;
    if (GetModSlotStat(6) != other->GetModSlotStat(6)) return true;
    if (GetModSlotStat(7) != other->GetModSlotStat(7)) return true;
    if (FUN_004bd570(1) != other->FUN_004bd570(1)) return true;
    if (FUN_004bd570(2) != other->FUN_004bd570(2)) return true;
    if (FUN_004bd570(4) != other->FUN_004bd570(4)) return true;
    if (((WeaponStringCompare*)&m_kEmbeddedWeaponNodeName)->CompareString(&other->m_kEmbeddedWeaponNodeName, true)) return true;
    if (((WeaponStringCompare*)&VATSAttackName)->CompareString(&other->VATSAttackName, true)) return true;
    if (memcmp(&data, other->GetOffsetF4(), 0xcc)) return true;
    if (memcmp(&m_kCriticalData, &other->m_kCriticalData, 0x10)) return true;
    if (memcmp(&m_kVATSData, &other->m_kVATSData, 0x14)) return true;
    if (GetAttackSound(false) != other->GetAttackSound(false)) return true;
    if (GetValueByFlag(false) != other->GetValueByFlag(false)) return true;
    if (GetPointerByFlag(false) != other->GetPointerByFlag(false)) return true;
    if (GetField228() != other->GetField228()) return true;
    if (GetField22C() != other->GetField22C()) return true;
    if (GetField230() != other->GetField230()) return true;
    if (FUN_00522500() != other->FUN_00522500()) return true;
    if (GetField238() != other->GetField238()) return true;
    if (GetField23C() != other->GetField23C()) return true;
    if (GetModDistantAttackSound() != other->GetModDistantAttackSound()) return true;
    if (GetField244() != other->GetField244()) return true;
    if (FUN_005224a0() != other->FUN_005224a0()) return true;
    if (m_eSoundLevel != other->ComputeValue_00522560(false)) return true;
    return false;
}

struct WeapNode { NiPoint3* GetWorldPos(); };
struct WeapProcess {
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual WeapNode* GetWeaponNode(void*);
};

extern PlayerCharacter* g_thePlayer;
struct WeapAimShell : public TESObjectWEAP {
    int FUN_00446390();
    WeapNode* TESObjectWEAP_GetFireNode(void* root);
    NiPoint3 TESObjectWEAP_CalculateReleasePoint(TESObjectREFR* ref);
};

// Returns the reference's position raised by its height, or the world position of its weapon or 3D node when a process exists.
// @fnv 0x005257a0
// src: COMMUNITY 0x005257a0
NiPoint3 WeapAimShell::TESObjectWEAP_CalculateReleasePoint(TESObjectREFR* ref)
{
    Actor* actor2 = ref->IsActor() ? (Actor*)ref : 0;
    WeapProcess* process = actor2 ? (WeapProcess*)((const Actor*)actor2)->GetCurrentProcess() : 0;
    bool isPlayer_2 = (void*)actor2 == g_thePlayer;
    NiPoint3 pos5 = *ref->GetPos();
    if (actor2)
        pos5.z += actor2->GetHeight();
    WeapNode* node9 = 0;
    if (actor2 && process && (FUN_00446390() == 10 || FUN_00446390() == 11 || FUN_00446390() == 12 || FUN_00446390() == 13)) {
        void* biped = isPlayer_2 ? g_thePlayer->GetBipedAnim(g_thePlayer->PlayerCharacter_Is3rdPerson()) : (void*)actor2->CallGetValidBip01Names();
        WeapNode* weapNode = process->GetWeaponNode(biped);
        if (weapNode)
            pos5 = *weapNode->GetWorldPos();
    } else {
        if (process)
            node9 = (WeapNode*)ref->Unk_83();
        else
            node9 = TESObjectWEAP_GetFireNode(isPlayer_2 ? g_thePlayer->GetPlayerNode() : ref->GetNiNode());
        if (node9)
            pos5 = *node9->GetWorldPos();
    }
    return pos5;
}

struct CombatSettingF
{
	float* Float();
};
extern CombatSettingF DAT_011cf3f0;
extern CombatSettingF DAT_011cea74;

struct CombatExplosion
{
	float GetRadius();
	float GetForce();
};

struct CombatProjectile
{
	CombatExplosion* GetExplosion();
};

struct CombatWeapon
{
	int GetWeaponType();
	CombatProjectile* GetProjectileData(Actor* pkActor);
	int TESObjectWEAP_GetCombatWeaponType();
};

// @fnv 0x00522c80
// src: EXE 0x00522c80
int CombatWeapon::TESObjectWEAP_GetCombatWeaponType()
{
	switch (GetWeaponType())
	{
	case 0:
	case 1:
	case 2:
		return 2;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 13:
		{
			CombatProjectile* pkProjectile = GetProjectileData(0);
			if (pkProjectile && pkProjectile->GetExplosion()
				&& pkProjectile->GetExplosion()->GetRadius() > *DAT_011cf3f0.Float()
				&& pkProjectile->GetExplosion()->GetForce() > *DAT_011cea74.Float())
			{
				return 0;
			}
			return 1;
		}
	case 10:
		return 3;
	case 11:
	case 12:
		return 4;
	default:
		Warning("COMBAT: Unknown weapon type %i encountered in function TESObjectWEAP::GetCombatWeaponType().", GetWeaponType());
		return 2;
	}
}

struct NiFixedString;
BSFaceGenAnimationData* __cdecl Main_WorldRootCamera();
NiAVObject* __fastcall TESObjectCELL_GetMarkerNode(TESObjectCELL*);
NiFixedString* __cdecl get_g_AimSight();
float __cdecl BSMAX_00404010(float, float);

struct FirePoint {
 float x,y,z;
 FirePoint(); FirePoint(float,float,float);
 FirePoint operator*(float) const;
 FirePoint operator+(const FirePoint&) const;
 FirePoint operator-(const FirePoint&) const;
 FirePoint& operator*=(float);
 float Length() const;
};
struct FireNode; struct FireProcess; struct FireExtra; struct FirePackage; struct FireRef;
struct FireNode {
 virtual void unused000();
 virtual void unused004();
 virtual void unused008();
 virtual FireNode* node();
 virtual void unused010();
 virtual void unused014();
 virtual void unused018();
 virtual void unused01c();
 virtual void unused020();
 virtual void unused024();
 virtual void unused028();
 virtual void unused02c();
 virtual void unused030();
 virtual void unused034();
 virtual void unused038();
 virtual void unused03c();
 virtual void unused040();
 virtual void unused044();
 virtual void unused048();
 virtual void unused04c();
 virtual void unused050();
 virtual void unused054();
 virtual void unused058();
 virtual void unused05c();
 virtual void unused060();
 virtual void unused064();
 virtual void unused068();
 virtual void unused06c();
 virtual void unused070();
 virtual void unused074();
 virtual void unused078();
 virtual void unused07c();
 virtual void unused080();
 virtual void unused084();
 virtual void unused088();
 virtual void unused08c();
 virtual void unused090();
 virtual void unused094();
 virtual void unused098();
 virtual FireNode* find(void*);
 virtual void unused0a0();
 virtual void unused0a4();
 virtual void unused0a8();
 virtual void unused0ac();
 virtual void unused0b0();
 virtual void unused0b4();
 virtual void unused0b8();
 virtual void unused0bc();
 virtual void unused0c0();
 virtual void unused0c4();
 virtual void unused0c8();
 virtual void unused0cc();
 virtual void unused0d0();
 virtual void unused0d4();
 virtual void unused0d8();
 virtual void attach(FireNode*,bool);
 virtual void unused0e0();
 virtual void unused0e4();
 virtual void detach(FireNode*);
 FirePoint* NiAVObject_GetWorldTranslate();
 FirePoint* NiAVObject_GetWorldRotate();
 FireNode* FUN_0043b4a0(int);
 FireNode* NiNode_GetAtChecked(int);
 void FUN_00450f90(bool);
 FireNode* NiAVObject_GetParent();
 void SetName(void*);
 void SetRotate_0043fa80(void*);
 void UpdateProperties();
 void Update(struct FireUpdate&);
 void NiMatrix3_ToEulerAnglesZXY(float*,float*,float*);
};
struct FireExtra {
 bool HasEffect(int);
 bool FUN_004bd8d0(int,float*);
 int FUN_00726070();
 TESForm* CurrentObject();
};
struct FirePackage {
 int GetPackType();
 FireRef* GetLocationReference_00676140(FireRef*);
 struct FireUse* TESPackage_GetUseWeaponPackageData();
};
struct FireRef {
 virtual void unused000();
 virtual void unused004();
 virtual void unused008();
 virtual void unused00c();
 virtual void unused010();
 virtual void unused014();
 virtual void unused018();
 virtual void unused01c();
 virtual void unused020();
 virtual void unused024();
 virtual void unused028();
 virtual void unused02c();
 virtual void unused030();
 virtual void unused034();
 virtual void unused038();
 virtual void unused03c();
 virtual void unused040();
 virtual void unused044();
 virtual void unused048();
 virtual void unused04c();
 virtual void unused050();
 virtual void unused054();
 virtual void unused058();
 virtual void unused05c();
 virtual void unused060();
 virtual void unused064();
 virtual void unused068();
 virtual void unused06c();
 virtual void unused070();
 virtual void unused074();
 virtual void unused078();
 virtual void unused07c();
 virtual void unused080();
 virtual void unused084();
 virtual void unused088();
 virtual void unused08c();
 virtual void unused090();
 virtual void unused094();
 virtual void unused098();
 virtual void unused09c();
 virtual void unused0a0();
 virtual void unused0a4();
 virtual void unused0a8();
 virtual void unused0ac();
 virtual void unused0b0();
 virtual void unused0b4();
 virtual void unused0b8();
 virtual void unused0bc();
 virtual void unused0c0();
 virtual void unused0c4();
 virtual void unused0c8();
 virtual void unused0cc();
 virtual void unused0d0();
 virtual void unused0d4();
 virtual void unused0d8();
 virtual void unused0dc();
 virtual void unused0e0();
 virtual void unused0e4();
 virtual void unused0e8();
 virtual void unused0ec();
 virtual void unused0f0();
 virtual void unused0f4();
 virtual void unused0f8();
 virtual void unused0fc();
 virtual bool isActor();
 virtual void unused104();
 virtual void unused108();
 virtual void unused10c();
 virtual void unused110();
 virtual void unused114();
 virtual void unused118();
 virtual void unused11c();
 virtual void unused120();
 virtual void unused124();
 virtual void unused128();
 virtual void unused12c();
 virtual void unused130();
 virtual void unused134();
 virtual void unused138();
 virtual void unused13c();
 virtual void unused140();
 virtual void unused144();
 virtual void unused148();
 virtual void unused14c();
 virtual void unused150();
 virtual void unused154();
 virtual void unused158();
 virtual void unused15c();
 virtual void unused160();
 virtual void unused164();
 virtual void unused168();
 virtual void unused16c();
 virtual void unused170();
 virtual void unused174();
 virtual void unused178();
 virtual void unused17c();
 virtual void unused180();
 virtual void unused184();
 virtual void unused188();
 virtual void unused18c();
 virtual void remove(TESForm*,int,bool);
 virtual void unused194();
 virtual void unused198();
 virtual void unused19c();
 virtual void unused1a0();
 virtual void unused1a4();
 virtual void unused1a8();
 virtual void unused1ac();
 virtual void unused1b0();
 virtual void unused1b4();
 virtual void unused1b8();
 virtual void unused1bc();
 virtual void unused1c0();
 virtual void unused1c4();
 virtual void unused1c8();
 virtual void unused1cc();
 virtual FireNode* root();
 virtual void unused1d4();
 virtual void unused1d8();
 virtual void unused1dc();
 virtual void unused1e0();
 virtual struct FireAnim* anim();
 virtual void unused1e8();
 virtual void* biped();
 virtual void unused1f0();
 virtual void unused1f4();
 virtual void unused1f8();
 virtual void unused1fc();
 virtual void unused200();
 virtual void unused204();
 virtual void unused208();
 virtual FireNode* muzzle();
 virtual void unused210();
 virtual void unused214();
 virtual void unused218();
 virtual void unused21c();
 virtual void unused220();
 virtual void unused224();
 virtual void unused228();
 virtual void unused22c();
 virtual void unused230();
 virtual void unused234();
 virtual void unused238();
 virtual void unused23c();
 virtual void unused240();
 virtual void unused244();
 virtual void unused248();
 virtual void unused24c();
 virtual void unused250();
 virtual void unused254();
 virtual void unused258();
 virtual void unused25c();
 virtual void unused260();
 virtual void unused264();
 virtual void unused268();
 virtual void unused26c();
 virtual void unused270();
 virtual void unused274();
 virtual void unused278();
 virtual void unused27c();
 virtual void unused280();
 virtual void unused284();
 virtual void unused288();
 virtual void unused28c();
 virtual void unused290();
 virtual void unused294();
 virtual void unused298();
 virtual void unused29c();
 virtual void unused2a0();
 virtual void unused2a4();
 virtual void unused2a8();
 virtual void unused2ac();
 virtual void unused2b0();
 virtual void unused2b4();
 virtual void unused2b8();
 virtual float heading(int);
 virtual void unused2c0();
 virtual void unused2c4();
 virtual void unused2c8();
 virtual void unused2cc();
 virtual void unused2d0();
 virtual void unused2d4();
 virtual void unused2d8();
 virtual void unused2dc();
 virtual void unused2e0();
 virtual void unused2e4();
 virtual void unused2e8();
 virtual void unused2ec();
 virtual void unused2f0();
 virtual void unused2f4();
 virtual void unused2f8();
 virtual void unused2fc();
 virtual void unused300();
 virtual void unused304();
 virtual void unused308();
 virtual void unused30c();
 virtual void unused310();
 virtual void unused314();
 virtual void unused318();
 virtual void unused31c();
 virtual void unused320();
 virtual void unused324();
 virtual void unused328();
 virtual void unused32c();
 virtual void unused330();
 virtual void unused334();
 virtual void unused338();
 virtual void unused33c();
 virtual void unused340();
 virtual void unused344();
 virtual void unused348();
 virtual void unused34c();
 virtual void unused350();
 virtual void unused354();
 virtual void unused358();
 virtual void unused35c();
 virtual bool state();
 virtual void unused364();
 virtual void unused368();
 virtual void unused36c();
 virtual void unused370();
 virtual void unused374();
 virtual void unused378();
 virtual void unused37c();
 virtual void unused380();
 virtual void unused384();
 virtual void unused388();
 virtual void unused38c();
 virtual void unused390();
 virtual void unused394();
 virtual void unused398();
 virtual void unused39c();
 virtual void unused3a0();
 virtual void unused3a4();
 virtual void unused3a8();
 virtual void unused3ac();
 virtual void unused3b0();
 virtual void unused3b4();
 virtual void unused3b8();
 virtual void unused3bc();
 virtual void unused3c0();
 virtual void unused3c4();
 virtual void kick(FireExtra*,float,int);
 virtual void unused3cc();
 virtual void unused3d0();
 virtual void unused3d4();
 virtual void unused3d8();
 virtual void unused3dc();
 virtual void unused3e0();
 virtual void unused3e4();
 virtual void unused3e8();
 virtual void unused3ec();
 virtual void count(int);
 virtual void unused3f4();
 virtual void unused3f8();
 virtual void unused3fc();
 virtual void unused400();
 virtual void unused404();
 virtual void unused408();
 virtual void unused40c();
 virtual void unused410();
 virtual void unused414();
 virtual void unused418();
 virtual void unused41c();
 virtual void unused420();
 virtual void unused424();
 virtual struct FireTarget* target();
 int field004;
 int field008;
 int field00c;
 int field010;
 int field014;
 int field018;
 int field01c;
 int field020;
 int field024;
 int field028;
 int field02c;
 int field030;
 int field034;
 int field038;
 int field03c;
 int field040;
 int field044;
 int field048;
 int field04c;
 int field050;
 int field054;
 int field058;
 int field05c;
 int field060;
 int field064;
 int field068;
 int field06c;
 int field070;
 int field074;
 int field078;
 int field07c;
 int field080;
 int field084;
 int field088;
 int field08c;
 int field090;
 int field094;
 int field098;
 int field09c;
 int field0a0;
 int field0a4;
 int field0a8;
 int field0ac;
 int field0b0;
 int field0b4;
 int field0b8;
 int field0bc;
 int field0c0;
 int field0c4;
 int field0c8;
 int field0cc;
 int field0d0;
 int field0d4;
 int field0d8;
 int field0dc;
 int field0e0;
 int field0e4;
 int field0e8;
 int field0ec;
 int field0f0;
 int field0f4;
 int field0f8;
 int field0fc;
 int field100;
 int field104;
 int field108;
 int field10c;
 int field110;
 int field114;
 int field118;
 int field11c;
 int field120;
 int field124;
 int field128;
 int field12c;
 int field130;
 int field134;
 int field138;
 int field13c;
 int field140;
 int field144;
 int field148;
 int field14c;
 int field150;
 int field154;
 int field158;
 int field15c;
 int field160;
 int field164;
 int field168;
 int field16c;
 int field170;
 int field174;
 int field178;
 int field17c;
 int field180;
 int field184;
 int field188;
 int field18c;
 int field190;
 int field194;
 int field198;
 int field19c;
 int field1a0;
 FireProcess* GetCurrentAIProcess();
 float GetLooking();
 bool PlayerCharacter_Is3rdPerson();
 void* GetBipedAnim(bool);
 void PlayerCharacter_ClearAutoAim();
 FireNode* PlayerCharacter_GetCurrentNode();
 bool Actor_GetIronSights();
 bool PlayerCharacter_IsActually3rdPerson();
 float GetCachedSpeed(int);
 void* FUN_008d6f30();
 FirePackage* GetCurrentPackage();
 char GetByteAtOffset1F8(); void SetByteAtOffset1F8(char);
 void FUN_00571b50();
};
struct FireProcess {
 virtual void unused000();
 virtual void unused004();
 virtual void unused008();
 virtual void unused00c();
 virtual void unused010();
 virtual void unused014();
 virtual void unused018();
 virtual void unused01c();
 virtual void unused020();
 virtual void unused024();
 virtual void unused028();
 virtual void unused02c();
 virtual void unused030();
 virtual void unused034();
 virtual void unused038();
 virtual void unused03c();
 virtual void unused040();
 virtual void unused044();
 virtual void unused048();
 virtual void unused04c();
 virtual void unused050();
 virtual void unused054();
 virtual void unused058();
 virtual void unused05c();
 virtual void unused060();
 virtual void unused064();
 virtual void unused068();
 virtual void unused06c();
 virtual void unused070();
 virtual void unused074();
 virtual void unused078();
 virtual void unused07c();
 virtual void unused080();
 virtual void unused084();
 virtual void unused088();
 virtual void unused08c();
 virtual void unused090();
 virtual void unused094();
 virtual void unused098();
 virtual void unused09c();
 virtual void unused0a0();
 virtual void unused0a4();
 virtual void unused0a8();
 virtual void unused0ac();
 virtual void unused0b0();
 virtual void unused0b4();
 virtual void unused0b8();
 virtual void unused0bc();
 virtual void unused0c0();
 virtual void unused0c4();
 virtual void unused0c8();
 virtual void unused0cc();
 virtual void unused0d0();
 virtual void unused0d4();
 virtual void unused0d8();
 virtual void unused0dc();
 virtual void unused0e0();
 virtual void unused0e4();
 virtual void unused0e8();
 virtual void unused0ec();
 virtual void unused0f0();
 virtual void unused0f4();
 virtual void unused0f8();
 virtual void unused0fc();
 virtual void unused100();
 virtual void unused104();
 virtual void unused108();
 virtual void unused10c();
 virtual void unused110();
 virtual void unused114();
 virtual void unused118();
 virtual void unused11c();
 virtual void unused120();
 virtual void unused124();
 virtual void unused128();
 virtual void unused12c();
 virtual void unused130();
 virtual void unused134();
 virtual void unused138();
 virtual void unused13c();
 virtual void unused140();
 virtual void unused144();
 virtual FireExtra* extra();
 virtual FireExtra* weapons();
 virtual void unused150();
 virtual void unused154();
 virtual void unused158();
 virtual void unused15c();
 virtual void unused160();
 virtual void unused164();
 virtual void unused168();
 virtual void unused16c();
 virtual void unused170();
 virtual void unused174();
 virtual void unused178();
 virtual void unused17c();
 virtual void unused180();
 virtual void unused184();
 virtual void unused188();
 virtual void unused18c();
 virtual FireNode* muzzle(void*);
 virtual void unused194();
 virtual void unused198();
 virtual void unused19c();
 virtual void unused1a0();
 virtual void unused1a4();
 virtual void unused1a8();
 virtual void unused1ac();
 virtual void unused1b0();
 virtual void unused1b4();
 virtual void unused1b8();
 virtual void unused1bc();
 virtual void unused1c0();
 virtual void unused1c4();
 virtual void unused1c8();
 virtual void unused1cc();
 virtual void unused1d0();
 virtual void unused1d4();
 virtual void unused1d8();
 virtual void unused1dc();
 virtual void unused1e0();
 virtual void unused1e4();
 virtual void unused1e8();
 virtual void unused1ec();
 virtual void unused1f0();
 virtual void unused1f4();
 virtual void unused1f8();
 virtual void unused1fc();
 virtual void unused200();
 virtual void unused204();
 virtual void unused208();
 virtual void unused20c();
 virtual void unused210();
 virtual void unused214();
 virtual void unused218();
 virtual void unused21c();
 virtual void unused220();
 virtual void unused224();
 virtual void unused228();
 virtual void unused22c();
 virtual void unused230();
 virtual void unused234();
 virtual void unused238();
 virtual void unused23c();
 virtual void unused240();
 virtual void unused244();
 virtual void unused248();
 virtual void unused24c();
 virtual void unused250();
 virtual void unused254();
 virtual void unused258();
 virtual void unused25c();
 virtual void unused260();
 virtual void unused264();
 virtual void unused268();
 virtual void unused26c();
 virtual void unused270();
 virtual struct FireList* data();
 virtual void unused278();
 virtual FirePackage* package();
 virtual void unused280();
 virtual void unused284();
 virtual void unused288();
 virtual void unused28c();
 virtual void unused290();
 virtual void unused294();
 virtual void unused298();
 virtual void unused29c();
 virtual void unused2a0();
 virtual void unused2a4();
 virtual void unused2a8();
 virtual void unused2ac();
 virtual void unused2b0();
 virtual void unused2b4();
 virtual void unused2b8();
 virtual void unused2bc();
 virtual void unused2c0();
 virtual void unused2c4();
 virtual void unused2c8();
 virtual void unused2cc();
 virtual void unused2d0();
 virtual void unused2d4();
 virtual void unused2d8();
 virtual void unused2dc();
 virtual void unused2e0();
 virtual void unused2e4();
 virtual void unused2e8();
 virtual void unused2ec();
 virtual void unused2f0();
 virtual void unused2f4();
 virtual void unused2f8();
 virtual void unused2fc();
 virtual void unused300();
 virtual void unused304();
 virtual void unused308();
 virtual void unused30c();
 virtual void unused310();
 virtual void unused314();
 virtual void unused318();
 virtual void unused31c();
 virtual void unused320();
 virtual void unused324();
 virtual void unused328();
 virtual void unused32c();
 virtual void unused330();
 virtual void unused334();
 virtual void unused338();
 virtual void unused33c();
 virtual void unused340();
 virtual void unused344();
 virtual void unused348();
 virtual void unused34c();
 virtual void unused350();
 virtual void unused354();
 virtual void unused358();
 virtual void unused35c();
 virtual void unused360();
 virtual void unused364();
 virtual void unused368();
 virtual void unused36c();
 virtual void unused370();
 virtual void unused374();
 virtual void unused378();
 virtual void unused37c();
 virtual void unused380();
 virtual void unused384();
 virtual void unused388();
 virtual void unused38c();
 virtual void unused390();
 virtual void unused394();
 virtual void unused398();
 virtual void unused39c();
 virtual void unused3a0();
 virtual void unused3a4();
 virtual void unused3a8();
 virtual void unused3ac();
 virtual void unused3b0();
 virtual void unused3b4();
 virtual void unused3b8();
 virtual void unused3bc();
 virtual void unused3c0();
 virtual void unused3c4();
 virtual void unused3c8();
 virtual void unused3cc();
 virtual void unused3d0();
 virtual void unused3d4();
 virtual void unused3d8();
 virtual void unused3dc();
 virtual void unused3e0();
 virtual void unused3e4();
 virtual void unused3e8();
 virtual void unused3ec();
 virtual void unused3f0();
 virtual void unused3f4();
 virtual void unused3f8();
 virtual void unused3fc();
 virtual void unused400();
 virtual void unused404();
 virtual void unused408();
 virtual void unused40c();
 virtual void unused410();
 virtual void unused414();
 virtual void unused418();
 virtual void unused41c();
 virtual void unused420();
 virtual void unused424();
 virtual void unused428();
 virtual float spread();
 virtual void unused430();
 virtual void unused434();
 virtual void unused438();
 virtual void unused43c();
 virtual unsigned char shots();
 virtual void unused444();
 virtual void shotsCount(int);
};
struct FireFormCheck {
 virtual void slot000();
 virtual void slot004();
 virtual void slot008();
 virtual void slot00c();
 virtual void slot010();
 virtual void slot014();
 virtual void slot018();
 virtual void slot01c();
 virtual void slot020();
 virtual void slot024();
 virtual void slot028();
 virtual void slot02c();
 virtual void slot030();
 virtual void slot034();
 virtual void slot038();
 virtual void slot03c();
 virtual void slot040();
 virtual void slot044();
 virtual void slot048();
 virtual void slot04c();
 virtual void slot050();
 virtual void slot054();
 virtual void slot058();
 virtual void slot05c();
 virtual void slot060();
 virtual void slot064();
 virtual void slot068();
 virtual void slot06c();
 virtual void slot070();
 virtual void slot074();
 virtual void slot078();
 virtual void slot07c();
 virtual void slot080();
 virtual void slot084();
 virtual void slot088();
 virtual void slot08c();
 virtual void slot090();
 virtual void slot094();
 virtual void slot098();
 virtual void slot09c();
 virtual void slot0a0();
 virtual void slot0a4();
 virtual void slot0a8();
 virtual void slot0ac();
 virtual void slot0b0();
 virtual void slot0b4();
 virtual void slot0b8();
 virtual void slot0bc();
 virtual void slot0c0();
 virtual void slot0c4();
 virtual void slot0c8();
 virtual void slot0cc();
 virtual void slot0d0();
 virtual void slot0d4();
 virtual void slot0d8();
 virtual void slot0dc();
 virtual void slot0e0();
 virtual bool bound();
};
struct FireAmmo : TESAmmo {
 TESForm* GetFieldBC(); float PathingRequestCoveredMove_GetAttackerHealth(); void* TESAmmo_GetAmmoEffectList();
};
struct FireAnim { void BlendOut(int,bool); };
extern FireRef* _g_thePlayer;
unsigned int DialogueRandom();
void ApplyPerkModifiers(int,FireRef*,...);
struct AmmoComponentAccess : BGSAmmoForm { TESAmmo* GetAmmoHelper(); };
struct FireWeapon : TESObjectWEAP {
 TESAmmo* GetCurrentAmmo(Actor* who);

 void TESObjectWEAP_Fire(FireRef*);
 int GetWeaponType() const;
 FireNode* TESObjectWEAP_GetFireNode(FireNode*);
 bool FUN_004ad030();
 struct FireString* TESCasino_GetData();
 float TESObjectWEAP_GetMinSpread(bool); float TESObjectWEAP_GetSpread(bool);
 bool TESObjectWEAP_IsThrownWeapon();
 struct FireRefData* GetOrFallback(FireRef*);
 bool GetIsAutomaticWeapon();
 void TESObjectWEAP_EjectShellCasing(FireRef*);
 bool TESObjectWEAP_IsEmbeddedWeapon();
 float GetFloatAt144(); float TESObjectWEAP_GetFiringRumbleRightMotorStrength(); float TESEffectShader_GetAddOnScaleStart();
 float GetEffectValue(int,unsigned char);
};
struct FireString { int GetModelLength(); };
struct FireVats {
 int FUN_0044ddc0(); struct FireShot* VATS_GetCurrentAction();
 int FUN_00441110();
 void VATS_SetFirstProjectile(struct FireRefData*); void SetValue(struct FireRefData*);
};
extern FireVats DAT_011f2250;
FirePoint* FireRefPosition(FireRef*);
struct FirePositionRef { FirePoint* FUN_00436aa0(); const FirePoint& GetAngleOnReference() const; };
extern FirePoint DAT_011a9484;
struct FireFace {
 struct FireTransform* NiAVObject_GetWorldRotate();
};
struct FireTransform { FirePoint ComputeValue_00524c40(const FirePoint&); };

struct FireSetting { float* Float(); unsigned char* Bool(); };
extern FireSetting g_011c94a0, g_011c94b0, g_011ce23c;
struct FireSmart {
 FireNode* ptr;
 FireSmart(FireNode*); ~FireSmart();
 operator FireNode*() const;
 FireSmart& operator=(FireNode*);
};
struct FireColor { float r,g,b,a; FireColor(float,float,float,float); };
struct FireMatrix { float xx,xy,xz,yx,yy,yz,zx,zy,zz; FireMatrix(); void FUN_00524ac0(float); };
struct FireUpdate { float time; bool a,b; int flags; FireUpdate(float,bool,bool); };
void* get_g_LaserSight();
FireNode* BSTestObjects_CreateCylinder(float,float,float,int,int,FireColor*);
void AttachLightingPropertyRecursive(FireNode*);
void FUN_00b57e30(FireNode*,int,int);
void PlayWeaponSound(FireWeapon*,FireRef*,FireNode*,bool);

struct FireTarget { bool CallHelperFoo(FirePoint*,FirePoint*); };
struct FireList {
 virtual void ReportDiagnostic(); virtual void unused4(); virtual int type();
 FireRef* FUN_00726070();
};
struct FireRefData {
 float GetFloatAtOffset68(); void SetWhich(int);
};
extern FireSetting originalRuntimeFloatSetting375, originalRuntimeFloatSetting393;
float FUN_004b1550(FirePoint*);
float NiASin_004b54c0(float);


FireNode* BSTestObjects_CreateBox(FirePoint*,FirePoint*,float,float,float,float,FireColor*,int);
FirePoint ComputeTrajectory(FireRef*,FireRef*,int,FireRefData*,float,bool);
FirePoint GetTargetLocationWithOffset(FireRef*,bool);
void NiSinCos_004169a0(float,float&,float&);
struct FireControls { void Controls_Rumble(float,float,int,int,int,int,int); };
struct FireOS { FireControls* Main_GetControls(); };
extern FireOS* g_osGlobals;
bool Interface_IsInMenuMode();
float ComputeAmmoEffectValue(int,void*,float);
struct FireAmmoFlag { bool FUN_00474a80(); };


struct WeaponAmmoView { int field000; int field004; int field008; int field00c; int field010; int field014; int field018; int field01c; int field020; int field024; int field028; int field02c; int field030; int field034; int field038; int field03c; int field040; int field044; int field048; int field04c; int field050; int field054; int field058; int field05c; int field060; int field064; int field068; int field06c; int field070; int field074; int field078; int field07c; int field080; int field084; int field088; int field08c; int field090; int field094; int field098; int field09c; int field0a0; FireAmmoFlag ammoForm; };
struct FireShot { int id; int field04; unsigned char ammo, special,field0a,field0b; FireRef* target; };
struct FireUse { bool InterfaceManager_GetMenuMode(); unsigned char GetByteAt0D(); };
extern FireRef* DAT_011f21f0;
extern FireRef* DAT_011f21e8;
extern FireRef* DAT_011f21ec;
extern float DAT_011c9508;
bool ActionPoints_IsAttackAction(int);
float RandomFloat(float,float);
float sin_004e44b0(float);
float FireCos(float);
FireRefData* CreateProjectile(FireRefData*,FireRef*,FireTarget*,FireWeapon*,FirePoint,float,float,FireNode*,FireRef*,bool,bool,float,float,int);
extern FireSetting originalRuntimeFloatSetting538,originalRuntimeFloatSetting539;
float CombatFormulas_CalcDamageToWeapon(FireRef*);

// Fires the weapon for the given reference: resolves ammo and muzzle, computes spread and aim, spawns projectiles per shot, and updates ammo counts and recoil.
// @fnv 0x00523150
// src: XBOX_PDB 0x00523150
void FireWeapon::TESObjectWEAP_Fire(FireRef* reference) {
 if (reference) {
  FireRef* actor19 = reference->isActor() ? reference : 0;
  if (actor19 == _g_thePlayer) {
   FireAmmo* ammo3 = (FireAmmo*)GetCurrentAmmo((Actor*)_g_thePlayer);
   if (ammo3) {
    TESForm* removed32 = 0;
    TESForm* effect7 = ammo3->GetFieldBC();
    float chance1 = ammo3->PathingRequestCoveredMove_GetAttackerHealth();
    ApplyPerkModifiers(57,_g_thePlayer,this,&chance1);
    float roll4 = (float)(DialogueRandom()%100);
    if (effect7 && roll4 <= chance1) {
     if (((FireFormCheck*)effect7)->bound()) removed32 = effect7;
     if (removed32) {
      TESFullName* fullName1 = dynamic_cast<TESFullName*>(effect7);
      _g_thePlayer->remove(removed32,0,true);
     }
    }
   }
  }
  if (actor19 && actor19->field1a0) return;
  bool player12 = actor19 == _g_thePlayer;
  struct FireShot* shot16 = 0;
  FireProcess* process39 = actor19 ? actor19->GetCurrentAIProcess() : 0;
  const int unusedResult10 = 0;
  FireExtra* extra13 = process39 ? process39->extra() : 0;
  FirePoint position6 = actor19 ? *((FirePositionRef*)reference)->FUN_00436aa0() + DAT_011a9484 * 96.0f : *((FirePositionRef*)reference)->FUN_00436aa0();
  float pitch37 = actor19 ? actor19->GetLooking() : ((FirePositionRef*)reference)->GetAngleOnReference().x;
  float yaw21 = actor19 ? actor19->heading(0) : ((FirePositionRef*)reference)->GetAngleOnReference().z;
  FireNode* muzzle11 = 0;
  if (process39 && (GetWeaponType()==10 || GetWeaponType()==11 || GetWeaponType()==12 || GetWeaponType()==13)) {
   float unusedPad[18];
   if (player12 && process39 && process39->weapons() && process39->weapons()->FUN_00726070()>1) {
    muzzle11 = process39->muzzle(_g_thePlayer->GetBipedAnim(_g_thePlayer->PlayerCharacter_Is3rdPerson()));
    if (muzzle11 && muzzle11->node() && muzzle11->node()->NiNode_GetAtChecked(0)) muzzle11->node()->FUN_0043b4a0(0)->FUN_00450f90(true);
   }
   muzzle11 = process39->muzzle(actor19->biped());
   if (muzzle11) position6 = *muzzle11->NiAVObject_GetWorldTranslate();
   if (player12) _g_thePlayer->PlayerCharacter_ClearAutoAim();
  } else {
   if (process39) muzzle11 = reference->muzzle();
   else muzzle11 = TESObjectWEAP_GetFireNode(player12 ? _g_thePlayer->PlayerCharacter_GetCurrentNode() : reference->root());
   if (muzzle11) {
    position6 = *muzzle11->NiAVObject_GetWorldTranslate();
    if (DAT_011f2250.FUN_0044ddc0()!=4 && actor19==_g_thePlayer && _g_thePlayer->Actor_GetIronSights() && TESCasino_GetData()->GetModelLength()) {
     bool useFace2 = false;
     if (FUN_004ad030()) {
      FireProcess* faceProcess = _g_thePlayer->GetCurrentAIProcess();
      if (faceProcess && faceProcess->extra() && faceProcess->extra()->HasEffect(14)) useFace2 = true;
     } else useFace2 = true;
     FireFace* face31 = (FireFace*)Main_WorldRootCamera();
     if (useFace2 && face31) {
      static FirePoint offset(0.0f,-5.0f,0.0f);
      position6 = face31->NiAVObject_GetWorldRotate()->ComputeValue_00524c40(offset);
     }
    }
    if (reference && reference==_g_thePlayer && !_g_thePlayer->PlayerCharacter_IsActually3rdPerson()) {
     yaw21 = _g_thePlayer->heading(0);
     pitch37 = _g_thePlayer->GetLooking();
    } else {
     float roll4;
     ((FireNode*)muzzle11->NiAVObject_GetWorldRotate())->NiMatrix3_ToEulerAnglesZXY(&yaw21,&pitch37,&roll4);
    }
    if (*g_011c94a0.Bool()) {
     FireNode* root = muzzle11->node();
     if (!root) root = muzzle11->NiAVObject_GetParent()->node();
     if (root) {
      FireSmart marker(root->find(get_g_LaserSight()));
      if (!(FireNode*)marker) {
       FireColor color(1,0,0,1);
       marker = BSTestObjects_CreateCylinder(1,1,4096.0f,10,10,&color);
       ((FireNode*)marker)->SetName(get_g_LaserSight());
       FireMatrix rotation;
       rotation.FUN_00524ac0(1.57079637f);
       ((FireNode*)marker)->SetRotate_0043fa80(&rotation);
       AttachLightingPropertyRecursive(marker);
       FUN_00b57e30(marker,0,0);
       root->attach(marker,true);
       ((FireNode*)marker)->UpdateProperties();
       FireUpdate update(0,false,false);
       ((FireNode*)marker)->Update(update);
      }
     }
    }
    PlayWeaponSound(this,reference,muzzle11,player12);
   }
  }

  float accuracy5 = actor19 ? actor19->GetCachedSpeed(1) : *g_011ce23c.Float();
  bool modSpread31 = false;
  if (actor19 && actor19->GetCurrentAIProcess() && extra13 && extra13->HasEffect(3)) modSpread31 = true;
  float spread50 = (TESObjectWEAP_GetMinSpread(modSpread31) + TESObjectWEAP_GetSpread(modSpread31)*accuracy5) * 0.01745329238474369;
  if (actor19 && actor19->GetCurrentAIProcess()) {
   spread50 = ComputeAmmoEffectValue(3,GetCurrentAmmo((Actor*)actor19) ? ((FireAmmo*)GetCurrentAmmo((Actor*)actor19))->TESAmmo_GetAmmoEffectList() : 0,spread50);
  }
  float processSpread1 = 0;
  FireTarget* target20 = 0;
  if (!player12 && actor19) {
   FirePoint targetPosition;
   target20 = actor19->target();
   if (target20) {
    if (!target20->CallHelperFoo(&targetPosition,&position6)) {
     if (TESObjectWEAP_IsThrownWeapon()) actor19->anim()->BlendOut(4,false);
     return;
    }
    FirePoint direction = targetPosition-position6;
    yaw21 = FUN_004b1550(&direction);
    pitch37 = -NiASin_004b54c0(direction.z/direction.Length());
    if (*g_011c94b0.Bool()) {
     FireNode* cellNode = (FireNode*)TESObjectCELL_GetMarkerNode((TESObjectCELL*)actor19->FUN_008d6f30());
     if (cellNode) {
      FireSmart cellMarker31(cellNode->find((void*)get_g_AimSight()));
      if ((FireNode*)cellMarker31) ((FireNode*)cellMarker31)->NiAVObject_GetParent()->detach(cellMarker31);
      FireColor cellColor14(0,1,0,1);
      cellMarker31 = BSTestObjects_CreateBox(&position6,&targetPosition,0.5f,0.5f,0.5f,0.5f,&cellColor14,0);
      ((FireNode*)cellMarker31)->SetName((void*)get_g_AimSight());
      cellNode->attach(cellMarker31,true);
      ((FireNode*)cellMarker31)->UpdateProperties();
      FireUpdate cellUpdate73(0,false,false);
      ((FireNode*)cellMarker31)->Update(cellUpdate73);
     }
    }
   } else if (process39 && process39->package() && process39->package()->GetPackType()==16) {
    FireList* data = process39->data();
    if (data) {
     FireList* list = data;
     FireRef* packageTarget = list->FUN_00726070();
     if (!packageTarget) return;
     bool lob = false;
     FireRefData* projectile = GetOrFallback(0);
     if (projectile) {
      float speed = projectile->GetFloatAtOffset68()*(lob ? *originalRuntimeFloatSetting375.Float() : 1.0f);
      targetPosition = ComputeTrajectory(actor19,packageTarget,0,projectile,speed,lob);
     } else targetPosition = GetTargetLocationWithOffset(packageTarget,true);
     FirePoint direction = targetPosition-position6;
     if (process39->package()->GetLocationReference_00676140(actor19)==packageTarget) {
      direction.z=0;
      NiSinCos_004169a0(actor19->heading(0),direction.x,direction.y);
      direction *= 512.0f;
      targetPosition=position6+direction;
     }
     yaw21=FUN_004b1550(&direction);
     pitch37=-NiASin_004b54c0(direction.z/direction.Length());
    }
   }
   float aim = actor19->GetCachedSpeed(2);
   spread50 += aim * *originalRuntimeFloatSetting393.Float() * 0.01745329238474369;
   processSpread1 = actor19->GetCurrentAIProcess()->spread();
   spread50 += processSpread1;
  }
  if ((reference==_g_thePlayer && process39 && process39->weapons()) || ((WeaponAmmoView*)this)->ammoForm.FUN_00474a80()) {
   if (!Interface_IsInMenuMode()) {
    FireControls* controls = g_osGlobals->Main_GetControls();
    if (GetFloatAt144()>0.0) controls->Controls_Rumble(TESEffectShader_GetAddOnScaleStart(),TESObjectWEAP_GetFiringRumbleRightMotorStrength(),(int)(GetFloatAt144()*1000.0),0,0,0,0);
    if (GetFloatAt144()>0.0) controls->Controls_Rumble(0.5f,1.0f,330,0,0,0,0);
   }
  }


  char shots14 = process39 ? process39->shots() : 1;
  bool split2 = false;
  if (extra13) split2 = extra13->HasEffect(12);
  if (split2) spread50 *= GetEffectValue(12,1);
  int projectileCount11 = GetDamageForActor(false,false,(Actor*)actor19) * shots14;
  int usedAmmo26=unusedResult10;
  FireSmart lastNode23(0);
  if (DAT_011f2250.FUN_0044ddc0()==4 && actor19==DAT_011f21f0) shot16=DAT_011f2250.VATS_GetCurrentAction();
  bool aimed26=false;
  unsigned char specialFlag19=0;
  FirePackage* package3 = actor19 ? actor19->GetCurrentPackage() : 0;
  if (package3) {
   FireUse* use=package3->TESPackage_GetUseWeaponPackageData();
   if (use) { aimed26=use->InterfaceManager_GetMenuMode(); specialFlag19=use->GetByteAt0D(); }
  }
  bool specialAmmo35=false;
  if (shot16 && shot16->special && ActionPoints_IsAttackAction(shot16->id)) specialAmmo35=true;
  if (actor19 && process39) process39->shotsCount(projectileCount11);
  bool vatTarget22=false;
  FireRef* aimTarget25=0;
  if (shot16 && actor19 && (actor19==DAT_011f21e8 || actor19==DAT_011f21ec)) {
   vatTarget22=true; aimed26=true; aimTarget25=shot16->target;
  }
  if (aimed26 && !vatTarget22) {
   FireList* data=process39->data();
   if (data && data->type()==16) {
    FireList* list=data;
    aimTarget25=list->FUN_00726070();
   }
  }
  while (shots14) {
   bool useSpecial62 = specialAmmo35 && ((DAT_011c9508<0.0 && shot16->special>0) || !shot16->ammo);
   bool firstProjectile43=true;
   FireRefData* spawned19=0;
   unsigned char count3=GetDamageForActor(split2,false,(Actor*)actor19);
   while (count3) {
    float shotPitch5=pitch37;
    float shotYaw16=yaw21;
    float pitchOffset13=0;
    float yawOffset5=0;
    if (!aimed26) {
     float radius=RandomFloat(0,spread50);
     float angle=RandomFloat(0,6.28318548f);
     pitchOffset13=sin_004e44b0(angle)*radius;
     yawOffset5=FireCos(angle)*radius;
     shotPitch5+=pitchOffset13;
     shotYaw16+=yawOffset5;
    }
    FireRef* shooter2=0;
    if (reference->isActor()) shooter2=reference;
    spawned19=CreateProjectile(GetOrFallback(shooter2),reference,target20,this,position6,shotYaw16,shotPitch5,lastNode23,aimTarget25,aimed26,(bool)(specialFlag19 || useSpecial62),yawOffset5,pitchOffset13,0);
    if (shot16 && (shot16->ammo || shot16->special) && ActionPoints_IsAttackAction(shot16->id) && !useSpecial62) {
     if (!GetIsAutomaticWeapon() || (!DAT_011f2250.FUN_00441110() && GetIsAutomaticWeapon())) DAT_011f2250.VATS_SetFirstProjectile(spawned19);
    }
    if (!firstProjectile43) spawned19->SetWhich(0);
    else firstProjectile43=false;
    --count3;
   }
   if (!useSpecial62) ++usedAmmo26;
   if (shot16 && (shot16->ammo || shot16->special) && ActionPoints_IsAttackAction(shot16->id)) {
    if (useSpecial62 && shot16->special) --shot16->special;
    else {
     int ammoPerShot=GetAmmoPerShot();
     if (ammoPerShot<1) ammoPerShot=1;
     shot16->ammo-=ammoPerShot;
    }
    float ratio=*originalRuntimeFloatSetting538.Float()/BSMAX_00404010(*originalRuntimeFloatSetting538.Float(),*originalRuntimeFloatSetting539.Float());
    DAT_011c9508+=ratio;
    if (DAT_011c9508>=ratio) DAT_011c9508-=1.0;
    if (!useSpecial62 && !shot16->ammo) DAT_011f2250.SetValue(spawned19);
   }
   --shots14;
  }
  if (actor19) {
   int savedAmmo=0;
   if (actor19==_g_thePlayer) {
    FireProcess* playerProcess=_g_thePlayer->GetCurrentAIProcess();
    if (playerProcess && playerProcess->extra()) {
     float chance1=0;
     if (playerProcess->extra()->FUN_004bd8d0(5,&chance1)) {
      _g_thePlayer->SetByteAtOffset1F8(_g_thePlayer->GetByteAtOffset1F8()+usedAmmo26);
      const int threshold=4;
      if (_g_thePlayer->GetByteAtOffset1F8()>=threshold) {
       _g_thePlayer->SetByteAtOffset1F8(_g_thePlayer->GetByteAtOffset1F8()-threshold);
       savedAmmo=1;
      }
     }
    }
   }
   actor19->count(usedAmmo26-savedAmmo);
  }
  if ((process39 && GetWeaponType()==10) || GetWeaponType()==11 || GetWeaponType()==12 || GetWeaponType()==13) {
   if (!process39->weapons() || process39->weapons()->FUN_00726070()<=0) actor19->FUN_00571b50();
   else if (muzzle11) {
    FireNode* child=muzzle11->node()->NiNode_GetAtChecked(0);
    if (child) child->FUN_00450f90(true);
   }
  }
  lastNode23=0;
  switch (GetWeaponType()) {
   case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    if (actor19 && actor19->state() && process39 && process39->extra() && !TESObjectWEAP_IsEmbeddedWeapon()) {
     float recoil=CombatFormulas_CalcDamageToWeapon(actor19);
     actor19->kick(actor19->GetCurrentAIProcess()->extra(),recoil,0);
    }
    break;
  }
  if (GetIsAutomaticWeapon()) TESObjectWEAP_EjectShellCasing(reference);

 }
}

// @fnv 0x004169a0
// src: XBOX_PDB 0x004169a0
void __cdecl NiSinCos_004169a0(float fRadians, float& fSin, float& fCos)
{
    float s, c;
    __asm {
        fld fRadians
        fsincos
        fstp c
        fstp s
    }
    fSin = s;
    fCos = c;
}

namespace fnv_00524db0 {
struct P12 {
    float x, y, z;
    void FUN_006815c0();
    void SubtractIntoVector(P12*, P12*);
    double FUN_00457990();
    P12* SetComponents(float, float, float);
    void ComputeValue_0063c8a0(P12*);
    void ScaleComponents(float);
};
struct Mat36 { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
struct Sub461130 {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void NiMatrix3_GetCol(int, P12*);
    P12* FUN_004b4500(P12*, P12*);
};
struct GetterBase { P12* NiAVObject_GetWorldTranslate(); };
struct NodeObj : GetterBase { Sub461130* NiAVObject_GetWorldRotate(); };
struct SubA {
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual int vfn_14();
    unsigned int FUN_0048cee0();
};
struct Param {
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void Unk_0c();
    virtual void Unk_0d();
    virtual void Unk_0e();
    virtual void Unk_0f();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1a();
    virtual void Unk_1b();
    virtual void Unk_1c();
    virtual void Unk_1d();
    virtual void Unk_1e();
    virtual void Unk_1f();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2a();
    virtual void Unk_2b();
    virtual void Unk_2c();
    virtual void Unk_2d();
    virtual void Unk_2e();
    virtual void Unk_2f();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3a();
    virtual void Unk_3b();
    virtual void Unk_3c();
    virtual void Unk_3d();
    virtual void Unk_3e();
    virtual void Unk_3f();
    virtual bool Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4a();
    virtual void Unk_4b();
    virtual void Unk_4c();
    virtual void Unk_4d();
    virtual void Unk_4e();
    virtual void Unk_4f();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5a();
    virtual void Unk_5b();
    virtual void Unk_5c();
    virtual void Unk_5d();
    virtual void Unk_5e();
    virtual void Unk_5f();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6a();
    virtual void Unk_6b();
    virtual void Unk_6c();
    virtual void Unk_6d();
    virtual void Unk_6e();
    virtual void Unk_6f();
    virtual void Unk_70();
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void* Unk_74();
    int FUN_009306d0();
    void* FUN_008d6f30();
    void* PlayerCharacter_GetCurrentNode();
    bool PlayerCharacter_Is3rdPerson();
};
extern Param* DAT_011dea3c;
struct SettingObj { float* Setting_Float_00403e20(); };
extern SettingObj DAT_011cf57c;
extern SettingObj DAT_011cf4b0;
extern SettingObj DAT_011cf498;
extern SettingObj DAT_011ce0e4;
extern SettingObj DAT_011cf1d4;
extern SettingObj DAT_011ce7c0;
struct Obj2250 { bool VATS_IsInVats(); };
extern Obj2250 DAT_011f2250;
extern float DAT_0101e704;
extern float DAT_010162c0;
extern P12 DAT_011a946c;
extern char DAT_0102cb00;
void* __cdecl Object_DispatchCommandFour(unsigned int);
struct XObj {
    static void* __cdecl operator new(unsigned int size) { return Object_DispatchCommandFour(size); } static void operator delete(void*, unsigned int);
    void* pEffect; void* pSource; void* pTransform; unsigned int flags; float intensity; float x; float y; float z; unsigned int lifetime;
    XObj(void*, float, int, Param*, P12*, Mat36*, P12*, P12*, float, int, int);
    void FUN_007e6580(int);
};
BSFaceGenAnimationData* __cdecl Main_WorldRootCamera();
bool __cdecl Main_GetSceneIsComplex();
NodeObj* __cdecl BSUtilities_GetObjectByName(void*, const char*);
bool __cdecl PointInFrustum(P12, BSFaceGenAnimationData*, float);
float __cdecl FUN_00476b70(float, float);
void __cdecl FUN_00458620(P12*, int);
float __cdecl BSMIN(float, float);
void __cdecl NiPoint3_UnitizeVector(P12*);
struct ThisObj {
    SubA* FUN_004600d0();
    void TESObjectWEAP_EjectShellCasing(Param* param);
};

// Creates an XObj using node data, settings, and a call on param when the conditions pass.
// @fnv 0x00524db0
// src: COMMUNITY 0x00524db0
void ThisObj::TESObjectWEAP_EjectShellCasing(Param* param)
{
    if (param != 0) {
    if (param->Unk_40()) {
    if (this->FUN_004600d0()->FUN_0048cee0() > 0) {
    if (!Main_GetSceneIsComplex()) {
    P12 bufC3;
    P12 tempBCz;
    XObj* qB7;
    XObj* qA7;
    float _fa8;
    P12 vecA0;
    P12 temp6;
    float f8c2;
    P12 ob88;
    float f7c5;
    float f9;
    P12 obj14;
    int dword4;
    P12 point1;
    Mat36 matTmp;
    P12 obj34;
    bool flag7;
    P12 aVec24;
    NodeObj* node3;
    Param* paramHome8;
    void* pR;
    paramHome8 = param;
    pR = (paramHome8 == DAT_011dea3c) ? DAT_011dea3c->PlayerCharacter_GetCurrentNode() : paramHome8->Unk_74();
    node3 = BSUtilities_GetObjectByName(pR, (const char*)&DAT_0102cb00);
    if (node3 != 0) {
    flag7 = true;
    if (!PointInFrustum(*node3->NiAVObject_GetWorldTranslate(), Main_WorldRootCamera(), DAT_0101e704))
        flag7 = false;
    node3->NiAVObject_GetWorldTranslate()->SubtractIntoVector(&aVec24, (P12*)&((NiAVObject*)Main_WorldRootCamera())->NiAVObject_GetWorldTranslate());
    if (aVec24.FUN_00457990() > *DAT_011cf57c.Setting_Float_00403e20())
        flag7 = false;
    if (flag7) {
    dword4 = this->FUN_004600d0()->vfn_14();
    point1 = *node3->NiAVObject_GetWorldTranslate();
    matTmp = *(Mat36*)node3->NiAVObject_GetWorldRotate();
    obj34.FUN_006815c0();
    node3->NiAVObject_GetWorldRotate()->NiMatrix3_GetCol(2, &obj34);
    f7c5 = -*DAT_011cf4b0.Setting_Float_00403e20();
    f9 = *DAT_011cf4b0.Setting_Float_00403e20();
    obj34.ComputeValue_0063c8a0(tempBCz.SetComponents(FUN_00476b70(f7c5, f9), FUN_00476b70(f7c5, f9), FUN_00476b70(f7c5, f9)));
    obj34.ScaleComponents(*DAT_011cf498.Setting_Float_00403e20());
    if (paramHome8->FUN_009306d0()) {
        ob88.FUN_006815c0();
        FUN_00458620(&ob88, paramHome8->FUN_009306d0() + 0x4f0);
        obj34.ComputeValue_0063c8a0(&ob88);
    }
    obj14.FUN_006815c0();
    vecA0 = DAT_011a946c;
    _fa8 = -*DAT_011ce0e4.Setting_Float_00403e20();
    f8c2 = *DAT_011ce0e4.Setting_Float_00403e20();
    vecA0.ScaleComponents(1.0f + FUN_00476b70(_fa8, f8c2));
    NiPoint3_UnitizeVector(&vecA0);
    temp6.SetComponents(*DAT_011cf1d4.Setting_Float_00403e20() * vecA0.x, 0.0f, *DAT_011cf1d4.Setting_Float_00403e20() * vecA0.z);
    obj14 = *node3->NiAVObject_GetWorldRotate()->FUN_004b4500(&bufC3, &temp6);
    if (paramHome8 == DAT_011dea3c && !DAT_011dea3c->PlayerCharacter_Is3rdPerson() && !DAT_011f2250.VATS_IsInVats()) {
        qA7 = new XObj(param->FUN_008d6f30(), BSMIN(*DAT_011ce7c0.Setting_Float_00403e20(), DAT_010162c0), dword4, param, &point1, &matTmp, &obj34, &obj14, 1.0f, 0, 1);
        qA7->FUN_007e6580(1);
    } else {
        qB7 = new XObj(param->FUN_008d6f30(), *DAT_011ce7c0.Setting_Float_00403e20(), dword4, param, &point1, &matTmp, &obj34, &obj14, 1.0f, 0, 1);
    }
    }
    }
    }
    }
    }
    }
}
}  // namespace fnv_00524db0

