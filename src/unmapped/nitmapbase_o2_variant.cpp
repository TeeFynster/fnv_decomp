#include "../../include/NiTMapItem.h"
// src/unmapped/nitmapbase_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/unmapped/nitmapbase.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BSShaderManager.h"
#include "../../include/NiStream.h"

struct NiMapBase
{
    void __thiscall BSShaderLightingProperty_SaveBinary(NiStream*);
    void __thiscall TallGrassShaderProperty_SaveBinary(NiStream* stream);
};
// @fnv 0x00b60210
// src: COMMUNITY 0x00b60210
void __thiscall NiMapBase::TallGrassShaderProperty_SaveBinary(NiStream* stream)
{
    BSShaderLightingProperty_SaveBinary(stream);
    stream->SaveCString(*(const char**)((char*)this + 0x88));
}



struct S_00b601a0_Map
{
    virtual ~S_00b601a0_Map();
    virtual unsigned int KeyToHashIndex(int key) const;
    virtual bool IsKeysEqual(int a, int b) const;
    virtual void SetValue(NiTMapItem<int, int>* item, int key, int val);
    virtual void ClearValue(NiTMapItem<int, int>* item);
    virtual NiTMapItem<int, int>* NewItem();
    virtual void DeleteItem(NiTMapItem<int, int>* item);

    unsigned int m_uiHashSize;
    NiTMapItem<int, int>** m_ppkHashTable;
    unsigned int m_uiCount;

    void NiTPointerMap_RemoveAll_00b601a0();
};

// @fnv 0x00b601a0
// src: COMMUNITY 0x00b601a0
void S_00b601a0_Map::NiTPointerMap_RemoveAll_00b601a0()
{
    for (unsigned int i = 0; i < m_uiHashSize; i++)
    {
        while (m_ppkHashTable[i])
        {
            NiTMapItem<int, int>* pkSave = m_ppkHashTable[i];
            m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
            ClearValue(pkSave);
            DeleteItem(pkSave);
        }
    }
    m_uiCount = 0;
}

struct TexBase
{
    void BSShaderProperty_PostLinkObject(NiStream* stream);
};

struct TexMap : TexBase
{
    char pad[0x84];
    NiTexture* m_texture;
    const char* m_path;

    void TallGrassShaderProperty_PostLinkObject(NiStream* stream);
};

// @fnv 0x00b60240
// src: XBOX_PDB 0x00b60240
void TexMap::TallGrassShaderProperty_PostLinkObject(NiStream* stream)
{
    BSShaderProperty_PostLinkObject(stream);
    if (m_path)
        BSShaderManager::GetTexture(m_path, true, m_texture, true, false);
}
