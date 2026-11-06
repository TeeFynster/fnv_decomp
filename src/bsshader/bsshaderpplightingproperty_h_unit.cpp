#include "../../include/BGSTerrainManager.h"
#include "../../include/BSShaderPPLightingProperty.h"

// @fnv 0x00441110
unsigned int BGSTerrainManager::GetMinLevel()
{
    return uiMinLevel;
}

// @fnv 0x0047d3f0
unsigned short BSShaderPPLightingProperty::GetDiffuseTextureIndex()
{
    // The original folded getter reads the word at +0x0a, within the inherited name handle.
    return reinterpret_cast<const unsigned short*>(&m_kName.m_kHandle)[1];
}
