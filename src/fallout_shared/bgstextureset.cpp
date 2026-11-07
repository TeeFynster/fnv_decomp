
// Fallout: New Vegas decompilation: fallout_shared/bgstextureset.cpp.
#include "bgstextureset_packet.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTexture.h"
#include "../../include/BSShaderManager.h"

// The shared class does not yet declare these unit-local method bodies.
// This helper adds no storage and only overrides an existing virtual slot.
struct BGSTextureSetMethods : public BGSTextureSet
{
    void* DeleteTextureSet(unsigned int flags);
    void SetFullNameByType(int aeType, const char* apFilename);
    void SaveTextureSet();
    bool CompareTextureSet(TESForm* apCompare);
    void CopyFromTextureSet(TESForm* apForm);
    using BSTextureSet::GetTexture;
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum aeTextureType, NiPointer<NiTexture>& arspTexture);
};

// @fnv 0x005922e0
BGSTextureSet::BGSTextureSet()
{
    ResetFormData();
    SetFormType(ENUM_FORM_ID_TXST_ID);
}

// @fnv 0x00592450
void BGSTextureSet::ResetFormData()
{
    for (int i = 0; i < 6; i++)
        pTextures[i].Init();
    m_pDecalData = 0;
    iFlags = 0;
    FillBytes(m_ppTextureFileEntries, 0, sizeof(m_ppTextureFileEntries));
}

// Frees all six textures, deletes the decal data object if present, and clears the flags.
// @fnv 0x005924d0
void BGSTextureSet::ClearData()
{
    int i;
    for (i = 0; i < 6; i++)
        pTextures[i].Free();
    void* pX;
    void* pY = this->m_pDecalData;
    pX = pY;
    pX ? ((DecalDataDeleter*)pX)->DeleteThis(1) : 0;
    iFlags = 0;
}

// @fnv 0x00592e70
const char* BGSTextureSet::GetTexture(BSShaderProperty::TextureTypeEnum aeTextureType)
{
    const char* pTextureFilePath = 0;
    switch (aeTextureType)
    {
    case 0:
        pTextureFilePath = pTextures[0].GetTextureResourceName();
        break;
    case 1:
        pTextureFilePath = pTextures[1].GetTextureResourceName();
        break;
    case 2:
        pTextureFilePath = pTextures[3].GetTextureResourceName();
        break;
    case 3:
        pTextureFilePath = pTextures[4].GetTextureResourceName();
        break;
    case 4:
        pTextureFilePath = pTextures[5].GetTextureResourceName();
        break;
    case 5:
        pTextureFilePath = pTextures[2].GetTextureResourceName();
        break;
    }
    if (pTextureFilePath && *pTextureFilePath == '\0')
        pTextureFilePath = 0;
    return pTextureFilePath;
}

// Queues each non-null texture in the set to the model loader with the given priority and queued file.
// @fnv 0x005930e0
void BGSTextureSet::LoadTextures(int aePriority, QueuedFile* apQueuedFile, bool abFlag)
{
    for (int i = 0; i < 6; i++)
    {
        if (m_ppTextureFileEntries[i])
            g_pModelLoader->QueueTextureFile(m_ppTextureFileEntries[i], aePriority, apQueuedFile);
    }
}

// Creates the null texture set once, assigns it ref ID 40 and editor ID "NullTextureSet", and registers it with the data handler.
// @fnv 0x00593140
void BGSTextureSet::InitializeNullTextureSet()
{
    if (!s_pNullTextureSet)
    {
        s_pNullTextureSet = new BGSTextureSet;
        s_pNullTextureSet->SetRefID(40, true);
        s_pNullTextureSet->SetEditorID_AtRuntime("NullTextureSet");
        ((TESDataHandlerForms*)g_dataHandler)->AddFormToDataHandler(s_pNullTextureSet);
    }
}

// @fnv 0x005928a0
bool BGSTextureSet::LoadForm(TESFile* file)
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
        case 0x30305854:
            TESTextureLoader::ReadTextureData(&pTextures[0], file);
            break;
        case 0x31305854:
            TESTextureLoader::ReadTextureData(&pTextures[1], file);
            break;
        case 0x32305854:
            TESTextureLoader::ReadTextureData(&pTextures[2], file);
            break;
        case 0x33305854:
            TESTextureLoader::ReadTextureData(&pTextures[3], file);
            break;
        case 0x34305854:
            TESTextureLoader::ReadTextureData(&pTextures[4], file);
            break;
        case 0x35305854:
            TESTextureLoader::ReadTextureData(&pTextures[5], file);
            break;
        case 0x4d414e44:
            ((TESFileChunkData16*)file)->GetChunkData(&iFlags);
            break;
        case 0x54444f44:
            if (!m_pDecalData)
                m_pDecalData = new DecalData;
            m_pDecalData->Load(file);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    for (int i = 0; i < 6; i++)
    {
        const char* pTexturePath = pTextures[i].GetTextureResourceName();
        if (pTexturePath && *pTexturePath)
        {
            char fullPath[260];
            TaskQueueInterface::CopyStringToBuffer(fullPath, 260, "Data\\Textures\\");
            strcat_s(fullPath, 260, pTexturePath);
            char path[260];
            CleanPath(fullPath, path, 260);
            NiPoint2 kDirHash;
            NiPoint2 fileHash;
            FileNameHash::CreateDirectoryAndFileHashes(path, (FileNameHash&)kDirHash, (FileNameHash&)fileHash);
            m_ppTextureFileEntries[i] =
                ArchiveManager::FindFileEntry(ARCHIVE_TYPE_INDEX_TEXTURES, (FileNameHash&)kDirHash, (FileNameHash&)fileHash, path);
        }
    }
    return true;
}

// @fnv 0x00593210
// src: COMMUNITY 0x00593210
void BGSTextureSet_ClearNullTextureSet()
{
    BGSTextureSet::s_pNullTextureSet = 0;
}

// @fnv 0x00593220
// src: COMMUNITY 0x00593220
BGSTextureSet* __cdecl BGSTextureSet_GetNullTextureSet()
{
    return BGSTextureSet::s_pNullTextureSet;
}

void __cdecl _Deallocate(void*);
struct S591140
{
    void FUN_00591170();
    void* FUN_00591140(unsigned int);
};
// Calls FUN_00591170, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00591140
void* S591140::FUN_00591140(unsigned int flags)
{
    FUN_00591170();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl _delete(void*, unsigned int);
// Destroys the texture set, frees it when flags has bit 1 set, and returns this.
// @fnv 0x00592380
void* BGSTextureSetMethods::DeleteTextureSet(unsigned int flags)
{
    BGSTextureSet::~BGSTextureSet();
    if (flags & 1)
        _delete(this, 0xa0);
    return this;
}

struct FullNameEx
{
    int _m0;
    int _m1;
    int _m2;
    void SetFullName(char const*);
};
// If aeType is below 6, assigns the filename to that texture entry.
// @fnv 0x00592cc0
void BGSTextureSetMethods::SetFullNameByType(int aeType, char const* apFilename)
{
    if (aeType < 6)
        ((FullNameEx*)&pTextures[aeType])->SetFullName(apFilename);
}

struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};
struct FUN_00593320_shell
{
    void ProcessState_00593320(void*);
};
void __cdecl TESForm_AddChunk_00485950(unsigned int, unsigned int);
extern unsigned int DAT_0118c574[6];
// @fnv 0x00592810
void BGSTextureSetMethods::SaveTextureSet()
{
    int i;
    TESForm::BeginFormRecord();
    for (i = 0; i < 6; ++i)
        ((FUN_0048e370_obj*)&pTextures[i])->TESTexture_Save(DAT_0118c574[i]);
    if (m_pDecalData)
        ((FUN_00593320_shell*)m_pDecalData)->ProcessState_00593320((void*)0x54444f44);
    TESForm_AddChunk_00485950(0x4d414e44, iFlags);
    TESForm::FinishFormRecord();
}

struct FUN_005e79a0_t : public TESForm
{
    bool TESForm_CompareAllComponents(TESForm*);
};

struct FUN_005932e0_shell
{
    bool Compare(void*);
};

struct FUN_005926f0_entry
{
    virtual void FUN_0() = 0;
    virtual void FUN_1() = 0;
    virtual void FUN_2() = 0;
    virtual bool Compare(void*) = 0;
};

// @fnv 0x005926f0
bool BGSTextureSetMethods::CompareTextureSet(TESForm* apCompare)
{
    BGSTextureSet* pcompare = dynamic_cast<BGSTextureSet*>(apCompare);
    int i;

    if (!pcompare)
        return true;

    for (i = 0; i < 6; ++i)
    {
        if (reinterpret_cast<FUN_005926f0_entry*>(&pTextures[i])
                ->Compare(reinterpret_cast<void*>(&pcompare->pTextures[i])))
            return true;
    }

    if (reinterpret_cast<FUN_005932e0_shell*>(pcompare->m_pDecalData))
    {
        if (!m_pDecalData)
            return true;

        if (reinterpret_cast<FUN_005932e0_shell*>(m_pDecalData)->Compare(reinterpret_cast<FUN_005932e0_shell*>(pcompare->m_pDecalData)))
            return true;
    }
    else if (m_pDecalData)
    {
        return true;
    }

    if (iFlags != pcompare->iFlags)
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pcompare))
        return true;

    return false;
}

struct DecalDataOwned : public DecalData
{
    ~DecalDataOwned();
};

struct DecalDataCopier
{
    void Copy(DecalData* apSrc);
};

// Copies the six texture entries, the decal data and the flags from another BGSTextureSet, then copies the bound object.
// @fnv 0x00592560
void BGSTextureSetMethods::CopyFromTextureSet(TESForm* apForm)
{
    BGSTextureSet* pSourceTextureSet = dynamic_cast<BGSTextureSet*>(apForm);
    if (!pSourceTextureSet)
        return;
    for (int i = 0; i < 6; i++)
        ((BaseFormComponent*)&pTextures[i])->CopyFromBase(&pSourceTextureSet->pTextures[i]);
    if (pSourceTextureSet->m_pDecalData)
    {
        if (!m_pDecalData)
            m_pDecalData = new DecalData;
        ((DecalDataCopier*)m_pDecalData)->Copy(pSourceTextureSet->m_pDecalData);
    }
    else if (m_pDecalData)
    {
        delete (DecalDataOwned*)m_pDecalData;
        m_pDecalData = 0;
    }
    iFlags = pSourceTextureSet->iFlags;
    TESForm::CopyFrom(pSourceTextureSet);
}

int FUN_00406d30(char*, unsigned int, const char*);

// Looks up the texture filename for aeTextureType, builds a Data\Textures\ path, loads the texture via BSShaderManager::GetTexture and stores it in arspTexture.
// @fnv 0x00592f30
void BGSTextureSetMethods::GetTexture(BSShaderProperty::TextureTypeEnum aeTextureType, NiPointer<NiTexture>& arspTexture)
{
    const char* pFilename;
    {
        NiPointer<NiTexture> spTexture = 0;
        char acPath[0x104];
        pFilename = GetTexture(aeTextureType);
        if (pFilename && *pFilename)
        {
            FUN_00406d30(acPath, 0x104, "Data\\Textures\\");
            strcat_s(acPath, 0x104, pFilename);
            BSShaderManager::GetTexture(acPath, true, spTexture, true, false);
        }
        arspTexture = spTexture;
    }
}

namespace s593030 {

struct ValueList
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00489100(int iValue);
};

struct Owner
{
    int unk00;
    int unk04;
    ValueList m_kList0;
    ValueList m_kList1;
    ValueList m_kList5;
    ValueList m_kList2;
    ValueList m_kList3;
    ValueList m_kList4;

    void BGSTextureSet_SetTexturePath(unsigned int uiType, int iValue);
};

// Dispatches iValue to the ValueList member selected by uiType, calling FUN_00489100 on the matching list.
// @fnv 0x00593030
// src: COMMUNITY 0x00593030
void Owner::BGSTextureSet_SetTexturePath(unsigned int uiType, int iValue)
{
    switch (uiType)
    {
    case 0:
        m_kList0.FUN_00489100(iValue);
        break;
    case 1:
        m_kList1.FUN_00489100(iValue);
        break;
    case 2:
        m_kList2.FUN_00489100(iValue);
        break;
    case 3:
        m_kList3.FUN_00489100(iValue);
        break;
    case 4:
        m_kList4.FUN_00489100(iValue);
        break;
    case 5:
        m_kList5.FUN_00489100(iValue);
        break;
    }
}

}
