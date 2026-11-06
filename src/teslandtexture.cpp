// teslandtexture.cpp: TESLandTexture, BGSTextureSet, LTCopy (11 functions)

#include "teslandtexture_decls.h"
#include "../include/TESLandTexture.h"

// @fnv 0x00540c50
TESLandTexture::TESLandTexture()
{
    SetFormType(ENUM_FORM_ID_LTEX_ID);
    SetInitializationState(true);
    ResetFormData();
}

// @fnv 0x00540d80
void TESLandTexture::ResetFormData()
{
    m_pTextureSet = 0;
    LandTextureParameters.m_ucParameter1 = 2;
    LandTextureParameters.m_ucParameter2 = 30;
    LandTextureParameters.m_ucParameter3 = 30;
    m_ucTextureTiling = 30;
}

// @fnv 0x005412a0
bool TESLandTexture::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != ENUM_FORM_ID_LTEX_ID)
        return false;
    LoadRecordHeader(file);
    do
    {
        switch (static_cast<int>(file->GetChunkID()))
        {
        case 'DIDE': {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'MANT': {
            unsigned int textureID = 0;
            file->GetChunkData(&textureID);
            m_pTextureSet = reinterpret_cast<BGSTextureSet*>(textureID);
            break;
        }
        case 'MANH':
            file->GetChunkData(&LandTextureParameters, 3);
            break;
        case 'MANS':
            file->GetChunkData(&m_ucTextureTiling, 1);
            break;
        case 'MANG': {
            unsigned int grassID = 0;
            file->GetChunkData(&grassID);
            if (grassID)
                GetGrassList()->AddTail(reinterpret_cast<TESGrass*>(grassID));
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

// Resolves the grass list and texture set form IDs, warns about missing entries, and marks the item initialized.
// @fnv 0x00540fe0
void TESLandTexture::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    BSSimpleList<TESGrass*>* current = GetGrassList();
    BSSimpleList<TESGrass*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        struct GrassResolution
        {
            unsigned int formID;
            TESGrass* grass;
        } grassEntry;
        grassEntry.formID = reinterpret_cast<unsigned int>(current->GetItem());
        RemapFormIDForFile(grassEntry.formID, GetFile(-1));
        grassEntry.grass = dynamic_cast<TESGrass*>(GetFormByID(grassEntry.formID));
        if (!grassEntry.grass)
        {
            Warning("MASTERFILE: Could not find Grass (%08X) for LandTexture '%s' (%08X).", grassEntry.formID,
                    GetName(), GetFormID());
            if (previous)
            {
                previous->Remove(reinterpret_cast<TESGrass*>(grassEntry.formID));
                current = previous->GetNext();
            }
            else
            {
                current->RemoveHead();
            }
        }
        else
        {
            current->SetItem(grassEntry.grass);
            previous = current;
            current = current->GetNext();
        }
    }
    if (m_pTextureSet)
    {
        unsigned int textureID = reinterpret_cast<unsigned int>(m_pTextureSet);
        RemapFormIDForFile(textureID, GetFile(-1));
        m_pTextureSet = dynamic_cast<BGSTextureSet*>(GetFormByID(textureID));
        if (!m_pTextureSet)
            Warning("MASTERFILE: Could not find Texture Set (%08X) for LandTexture '%s' (%08X).", textureID, GetName(),
                    GetFormID());
        if (m_pTextureSet)
        {
            if (!m_pTextureSet->GetTexture(BSShaderProperty::TEXTYPE_DIFFUSE))
                Warning("MASTERFILE: TextureSet '%s' (%08X) missing diffuse texture (required for landscape textures).",
                        m_pTextureSet->GetName(), m_pTextureSet->GetFormID());
            if (!m_pTextureSet->GetTexture(BSShaderProperty::TEXTYPE_NORMAL))
                Warning("MASTERFILE: TextureSet '%s' (%08X) missing normal texture (required for landscape textures).",
                        m_pTextureSet->GetName(), m_pTextureSet->GetFormID());
            m_pTextureSet->SetHasSpecular(false);
        }
    }
    SetInitializationState(true);
}

// Sets or clears bit 0 of iFlags according to hasSpecular.
// @fnv 0x00541250
void BGSTextureSet::SetHasSpecular(bool hasSpecular)
{
    if (hasSpecular)
        iFlags &= ~1;
    else
        iFlags |= 1;
}

void _Deallocate(void*);
// @fnv 0x00540ce0
void* TESLandTexture::Delete(unsigned int flags)
{
    this->~TESLandTexture();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00540dc0
void TESLandTexture::ClearData()
{
    GetGrassList()->RemoveAll();
}

// @fnv 0x00540d10
TESLandTexture::~TESLandTexture()
{
    TESLandTexture::ClearData();
}

void MemCopy(void* dst, const void* src, unsigned int n);
// Copies land texture data from pForm into this object, clearing and rebuilding the grass list from the source's grass entries.
// @fnv 0x00540de0
void TESLandTexture::CopyFrom(const TESForm* pForm)
{
    TESLandTexture* src = dynamic_cast<TESLandTexture*>(const_cast<TESForm*>(pForm));
    if (!src)
        return;
    BSSimpleList<TESGrass*>* node = 0;
    GetGrassList()->RemoveAll();
    TESForm::CopyFrom(src);
    MemCopy(&LandTextureParameters, &src->LandTextureParameters, 3);
    m_ucTextureTiling = src->m_ucTextureTiling;
    m_pTextureSet = src->GetTextureSet();
    node = src->GetGrassList();
    while (node && !node->IsEmpty())
    {
        TESGrass* g = node->GetItem();
        m_kGrassList.AddTail(g);
        node = node->GetNext();
    }
}

void __fastcall Cb_004855a0(void* self);
void __fastcall Cb_00483710(void* self);
unsigned int __fastcall Cb_0084e3a0(void* self);
void __cdecl Cb_00485910(unsigned int tag, unsigned int value);
bool __cdecl Cb_00401500();
void __cdecl Cb_00485990(unsigned int tag, void* data, unsigned int size);
void __cdecl Cb_004858f0(unsigned int tag, unsigned int value);
void __fastcall Cb_00485680(void* self);

// @fnv 0x00541440
void TESLandTexture::SaveForm()
{
    unsigned int formId;
    BSSimpleList<TESGrass*>* node3;
    {
        TESGrass* grass;
        unsigned int grassId;

        Cb_004855a0(this);
        Cb_00483710(this);
        if (m_pTextureSet != 0)
        {
            formId = Cb_0084e3a0(m_pTextureSet);
            Cb_00485910(0x4d414e54, formId);
        }
        if (Cb_00401500())
        {
            Cb_00483710(&LandTextureParameters);
        }
        Cb_00485990(0x4d414e48, &LandTextureParameters, 3);
        if (Cb_00401500())
        {
            Cb_00483710(&LandTextureParameters);
        }
        Cb_004858f0(0x4d414e53, m_ucTextureTiling);
        node3 = GetGrassList();
        while (node3 != 0 && !node3->IsEmpty())
        {
            grass = node3->GetItem();
            grassId = Cb_0084e3a0(grass);
            Cb_00485910(0x4d414e47, grassId);
            node3 = node3->GetNext();
        }
    }
    Cb_00485680(this);
}

#include <string.h>
// Returns true if form is not a TESLandTexture or differs in base compare, parameters, tiling, texture set or grass list.
// @fnv 0x00540ec0
bool TESLandTexture::Compare(TESForm* apOther)
{
    TESLandTexture* other = dynamic_cast<TESLandTexture*>(apOther);
    if (!other)
        return true;
    if (TESForm::Compare(other))
        return true;
    if (memcmp(&LandTextureParameters, &other->LandTextureParameters, 3))
        return true;
    if (m_ucTextureTiling != other->m_ucTextureTiling)
        return true;
    if (m_pTextureSet != other->GetTextureSet())
        return true;
    BSSimpleList<TESGrass*>* pGrassList = GetGrassList();
    BSSimpleList<TESGrass*>* pOtherGrassList = other->GetGrassList();
    while (pGrassList && pOtherGrassList)
    {
        if (pGrassList->GetItem() != pOtherGrassList->GetItem())
            return true;
        pOtherGrassList = pOtherGrassList->GetNext();
        pGrassList = pGrassList->GetNext();
    }
    if ((!pGrassList && pOtherGrassList) || (!pOtherGrassList && pGrassList))
        return true;
    return false;
}
