// bsshader/imagespaceeffectgethit.cpp: Standin (4 functions)

#include "imagespaceeffectgethit_types_ImageSpaceEffectGetHit.h"
#include "imagespaceeffectgethit_types_ImageSpaceShaderParam.h"
#include "../../include/MemoryManager.h"
#include "../../include/ImageSpaceManager.h"
#include "imagespaceeffectgethit_decls.h"
extern MemoryManager g_memoryManager;

// The original out-of-line SetAt (0x00ba3aa0) does not alias other effect arrays.
template <>
__declspec(noalias) void NiTArray<GetHitEffectParamLocalForm*, NiTMallocInterface<GetHitEffectParamLocalForm*> >::SetAt(
    unsigned int index, GetHitEffectParamLocalForm* const& element);

// Updates two shader parameters from global constants using a computed angle, sets DAT_012003c4, and returns true.
// @fnv 0x00c03740
bool ImageSpaceEffectWithTwoTextures::UpdateParams(GetHitEffectParamLocalForm* param)
{
    ImageSpaceShaderParam* shader = reinterpret_cast<ImageSpaceShaderParam*>(pEffectParamList.m_pBase[3]);
    float angle = static_cast<float>(DAT_011f940c / DAT_01012640 * DAT_0104eea0);
    shader->SetShaderConstantVector4(0, 0.0f, 0.0f, DAT_0120240c * DAT_012023fc, DAT_0120240c);
    float cosine = static_cast<float>(cos(angle));
    float sine = static_cast<float>(sin(angle));
    shader->SetShaderConstantVector4(1, sine * DAT_01202400, cosine * DAT_01202400, 1.0f, 1.0f);
    DAT_012003c4 = DAT_010162c0;
    return true;
}

// @fnv 0x00c03810
ImageSpaceEffectWithTwoTextures::ImageSpaceEffectWithTwoTextures()
{
    pTextures.SetSize(4);  // 0x00a90180: the folded NiTArray<T>::SetSize
}

struct Standin
{
    void FUN_00c03580();
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_00c03580, then if bit 0 of flags is set deallocates this via g_memoryManager, and returns this.
// @fnv 0x00c03890
void* Standin::ReleaseIfFlagged(unsigned int flags)
{
    FUN_00c03580();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

inline ImageSpaceEffect* ImageSpaceManager::GetEffect(int index)
{
    return reinterpret_cast<NiTPrimitiveArray<ImageSpaceEffect*>*>(pEffectList)->m_pBase[index];
}

// Sets texture and parameter arrays, configures four effect slots, and creates shader constants for the fourth slot.
// @fnv 0x00c038b0
void ImageSpaceEffectWithTwoTextures::Setup(ImageSpaceManager* manager, GetHitEffectParamLocalForm* param)
{
    SetTextureArrayCount(4);
    pTextures.SetSize(4);
    pEffectParamList.SetAt(0, 0);
    SetEffectParamAt(0, 1, 0);
    SetEffectAt(0, manager->GetEffect(34), 0, 2);
    pEffectParamList.SetAt(1, 0);
    SetEffectAt(1, 2, 3, 0, 0);
    SetEffectAt(1, manager->GetEffect(17), 0, 2);
    pEffectParamList.SetAt(2, 0);
    SetEffectAt(2, 2, 3, 0, 0);
    SetEffectAt(2, manager->GetEffect(17), 0, 2);
    ImageSpaceShaderParam* shaderParam = new ImageSpaceShaderParam;
    shaderParam->AllocateShaderConstants(0, 2);
    shaderParam->m_bTextureFlags[2] = false;
    pEffectParamList.SetAt(3, shaderParam);
    SetEffectAt(3, 1, 2, 0, 0);
    SetEffectAt(3, manager->GetEffect(44), shaderParam, 0);
}
