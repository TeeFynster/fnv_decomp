// fallout_shared/bgsaddonnode.cpp: BGSAddonNode, BGSAddonNodeSoundHandleExtra (17 functions)

#include "layout_support.h"
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/BGSAddonNode.h"
#include "../../include/BGSAddonNodeSoundHandleExtra.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiFixedString.h"
#include "../../include/EffectSetting.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESSound.h"

class TESFormInitFlag
{
public:
    bool IsFormInitialized() const;
};
class TESFileFormVersion
{
public:
    unsigned short GetFormVersion();
};
// TESFileAccessor_bgsaddonnode: local type (was include/TESFileAccessor.h, which had no evidence of one real class); its methods are 0x00401680 TESFile::QEndian
class TESFileAccessor_bgsaddonnode
{
public:
    bool GetChunkData();
};
class AddonNodeData
{
public:
    void BSEndian_Thunk();
    unsigned short m_usAddonNodeIndex;
    unsigned char cFlags;
    unsigned char layoutPadding3[1];
};
extern unsigned int DAT_011c8054;
TESForm* GetFormByID(unsigned int formID);
int __cdecl Warning(const char* format, ...);
#include <malloc.h>
#include <string.h>

// @fnv 0x004f8c50
void BGSAddonNode::ResetFormData()
{
    SoundAssetTmp = 0;
    memset(reinterpret_cast<char*>(this) + 0x58, 0, 4);
    uiParticleSystemIndex = 0;
}

// @fnv 0x004f8c90
void BGSAddonNode::InitItem()
{
    if (reinterpret_cast<TESFormInitFlag*>(this)->IsFormInitialized())
        return;

    TESModelTextureSwap::InitItem(this);
    if (SoundAssetTmp)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(SoundAssetTmp);
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        SoundAssetTmp = dynamic_cast<TESSound*>(GetFormByID(formID));
        if (!SoundAssetTmp)
            Warning("MASTERFILE: Unable to find sound (%08X) on addon node '%s'.", formID, GetName());
    }
    SetInitializationState(true);
}

// @fnv 0x004f8d50
bool BGSAddonNode::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x58)
        return false;

    LoadRecordHeader(file);
    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {

        switch (chunkID)
        {
        case 0x44494445:  // EDID
        {
            char* data = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(data, 0x200);
            SetEditorID_AtRuntime(data);
            break;
        }
        case 0x444e424f:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:  // MODL
        case 0x44444f4d:  // MODD
        case 0x44534f4d:  // MOSD
        case 0x54444f4d:  // MODT
        {
            TESModel::LoadModelData(this ? reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x30) : 0, file);
            break;
        }
        case 0x53444f4d:  // MODS
        {
            struct MODS_BUFFER
            {
                unsigned int size;
                char* data;
            } buffer;
            buffer.size = file->GetChunkSize();
            buffer.data = static_cast<char*>(_alloca(buffer.size));
            file->GetChunkData(buffer.data, buffer.size);
            reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<char*>(this) + 0x30)
                ->ParseTextureSwapData(buffer.data, buffer.size,
                                       reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case 0x41544144:  // DATA
            file->GetChunkData(&uiIndex);
            break;
        case 0x4d414e53:  // SNAM
        {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            SoundAssetTmp = reinterpret_cast<TESSound*>(formID);
            break;
        }
        case 0x4d414e44:  // DNAM
        {
            file->GetChunkData(reinterpret_cast<char*>(this) + 0x58, 4);
            if (reinterpret_cast<TESFileAccessor_bgsaddonnode*>(file)->GetChunkData())
                reinterpret_cast<AddonNodeData*>(reinterpret_cast<char*>(this) + 0x58)->BSEndian_Thunk();
            if (FUN_00448bf0())
            {
                uiParticleSystemIndex = DAT_011c8054;
                ++DAT_011c8054;
            }
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004f8b00
BGSAddonNode::BGSAddonNode() : uiIndex(-1)
{
    SetFormType(ENUM_FORM_ID_ADDN_ID);
    ResetFormData();
}

extern NiFixedString* DAT_011c8058;

// Allocates the "ASH" extra-data name and stores it in DAT_011c8058.
// @fnv 0x004f92e0
// src: COMMUNITY 0x004f92e0
void __cdecl BGSAddonNodeSoundHandleExtra_InitTag()
{
    DAT_011c8058 = ::new NiFixedString("ASH");
}

// @fnv 0x004f9230
// src: XBOX_PDB 0x004f9230
const NiFixedString& BGSAddonNodeSoundHandleExtra_Tag()
{
    return *DAT_011c8058;
}

void _Deallocate(void*);
struct Proxy_004f8b90
{
    void FUN_004f8bc0();
    void* FUN_004f8b90(unsigned int);
};
// @fnv 0x004f8b90
void* Proxy_004f8b90::FUN_004f8b90(unsigned int flags)
{
    FUN_004f8bc0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void _delete(void*, unsigned int);
// Calls FUN_004f9270, deletes this with size 24 when bit 0 of flags is set, and returns this.
// @fnv 0x004f9240
void* BGSAddonNodeSoundHandleExtra::FUN_004f9240(unsigned int flags)
{
    this->FUN_004f9270();
    if (flags & 1)
        _delete(this, 24);
    return this;
}

namespace fnv_004f9360 {
// Calls FUN_004b9900(1) on DAT_011c8058 if it is non-null, then sets DAT_011c8058 to null.
// @fnv 0x004f9360
// src: GUESS 0x004f9360 (confidence: low)
void Object_UpdateFields_004f9360()
{
    NiFixedString* pName;
    {
        NiFixedString* inner = DAT_011c8058;
        pName = inner;
        pName ? pName->FUN_004b9900(1) : 0;
    }
    DAT_011c8058 = 0;
}
}  // namespace fnv_004f9360

struct FUN_004fc940_cls
{
    char _pad[0x4C];
    EffectSetting* fld4C;
    void* GetCastSoundOrEffect();
};
// @fnv 0x004fc940
void* FUN_004fc940_cls::GetCastSoundOrEffect()
{
    if (fld4C == 0 || ((TESForm*)this)->IsFormInitialized() == 0 || fld4C->GetCastSound() == 0)
        return fld4C;
    return fld4C->GetCastSound();
}

void TESForm_AddChunk_00485910(unsigned int, unsigned int);
void AppendChunk(unsigned int, void*, unsigned int);
bool TESForm_QEndianSwapOnSave();
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct FUN_004f8fe0_shell : public BGSAddonNode
{
    void BGSAddonNode_SaveAlt();
};
// @fnv 0x004f8fe0
// src: COMMUNITY 0x004f8fe0
void FUN_004f8fe0_shell::BGSAddonNode_SaveAlt()
{
    reinterpret_cast<::FUN_004855a0*>(this)->M();
    reinterpret_cast<S_0048a520*>(reinterpret_cast<char*>(this) + 0x30)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESForm_AddChunk_00485910(0x41544144, uiIndex);
    if (SoundAssetTmp)
    {
        unsigned int itempint = SoundAssetTmp->TESForm::GetFormID();
        TESForm_AddChunk_00485910(0x4d414e53, itempint);
    }
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<AddonNodeData*>(reinterpret_cast<char*>(this) + 0x58)->BSEndian_Thunk();
    AppendChunk(0x4d414e44, reinterpret_cast<char*>(this) + 0x58, 4);
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<AddonNodeData*>(reinterpret_cast<char*>(this) + 0x58)->BSEndian_Thunk();
    reinterpret_cast<::FUN_00485680*>(this)->M();
}

extern "C" NiRTTI g_011c806c;

// @fnv 0x004f9220
const NiRTTI* BGSAddonNodeSoundHandleExtra::GetRTTI() const
{
    return &g_011c806c;
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct FUN_004f90a0_shell : BGSAddonNode
{
    void CopyFromAddonNode(TESForm* apCopy);
};
// @fnv 0x004f90a0
void FUN_004f90a0_shell::CopyFromAddonNode(TESForm* apCopy)
{
    BGSAddonNode* pcopy = dynamic_cast<BGSAddonNode*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
    *(unsigned int*)((char*)this + 0x50) = *(unsigned int*)((char*)pcopy + 0x50);
    *(TESSound**)((char*)this + 0x54) = *(TESSound**)((char*)pcopy + 0x54);
    memcpy((char*)this + 0x58, (char*)pcopy + 0x58, 4);
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};

struct FUN_004f9110_shell : BGSAddonNode
{
    bool BGSAddonNode_Compare(TESForm* apCompare);
};

// @fnv 0x004f9110
// src: XBOX_PDB 0x004f9110
bool FUN_004f9110_shell::BGSAddonNode_Compare(TESForm* apCompare)
{
    BGSAddonNode* pcomp;

    pcomp = dynamic_cast<BGSAddonNode*>(apCompare);
    if (!pcomp)
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pcomp))
        return true;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x50) !=
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pcomp) + 0x50))
        return true;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x54) !=
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pcomp) + 0x54))
        return true;

    if (memcmp(reinterpret_cast<const void*>(reinterpret_cast<const char*>(this) + 0x58),
               reinterpret_cast<const void*>(reinterpret_cast<const char*>(pcomp) + 0x58), 4))
        return true;

    return false;
}

// Clears the sound handle before the member and base destructors run.
// @fnv 0x004f9270
BGSAddonNodeSoundHandleExtra::~BGSAddonNodeSoundHandleExtra()
{
    m_kData.Stop();
}

extern TESDataHandler* g_dataHandler;

class FUN_004f8bc0 : public TESBoundObject, public TESModelTextureSwap
{
  public:
    virtual ~FUN_004f8bc0();
};

// Destructor that, when g_dataHandler is set, passes this object to TESDataHandler::RemoveAddonNode as a BGSAddonNode.
// @fnv 0x004f8bc0
FUN_004f8bc0::~FUN_004f8bc0()
{
    if (g_dataHandler)
    {
        g_dataHandler->RemoveAddonNode(reinterpret_cast<BGSAddonNode*>(this));
    }
}

// @fnv 0x004f91b0
BGSAddonNodeSoundHandleExtra::BGSAddonNodeSoundHandleExtra() : NiExtraData(BGSAddonNodeSoundHandleExtra_Tag())
{}
