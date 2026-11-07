// bsshader/bsshadertextureset.cpp: BipedAnim, BSShaderTextureSet (8 functions)
#include "NiRefObject_inline.h"

#include "../../include/BIPED_BONE.h"
#include "bsshadertextureset_types_BipedAnim.h"
#include "../../include/NiTexture.h"
#include "../../include/NiPointer.h"
#include "bsshadertextureset_decls.h"
#include "../../include/BSShaderManager.h"
#include "../../include/BSShaderTextureSet.h"
#include "../../include/BSTextureSet.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiStream.h"

// @fnv 0x004ab230
#pragma optimize("", off)
#pragma optimize("y", off)
NiNode* BipedAnim::GetBoneNode(BIPED_BONE boneIndex)
{
    return bone[boneIndex].pParent;
}
#pragma optimize("y", on)
#pragma optimize("", on)

// Looks up the texture name for a texture type, resolves it via BSShaderManager::GetTexture, and assigns it to textureOut with refcount handling.
// @fnv 0x00ba87f0
void BSShaderTextureSet::GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& textureOut)
{
    NiPointer<NiTexture> texture;
    register const char* textureName = GetTexture(textureType);
    if (textureName)
        BSShaderManager::GetTexture(textureName, true, texture, true, textureType == BSShaderProperty::TEXTYPE_ENV);
    if (textureOut.m_pObject != texture.m_pObject)
    {
        NiTexture* previous = textureOut.m_pObject;
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        textureOut.m_pObject = texture.m_pObject;
        if (texture.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&texture.m_pObject->m_uiRefCount));
    }
}

// @fnv 0x00ba88d0
void BSShaderTextureSet::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    int count = 0;
    char* pcstring = 0;
    NiBinaryStream* pkStream = stream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &count, 4, &uiBytesRead, 1);
    }
    for (int i = 0; i < count; ++i)
    {
        stream.ReadStreamString(pcstring);
        if (i >= 0)
        {
            reinterpret_cast<BSStringT<char>*>(names)[i].Set(pcstring, 0);
        }
        NiFree(pcstring);
        pcstring = 0;
    }
}

// @fnv 0x00ba89e0
void BSShaderTextureSet::SetTexture(BSShaderProperty::TextureTypeEnum aiType, const char* apFilename)
{
    reinterpret_cast<BSStringT<char>*>(names)[aiType].Set(apFilename, 0);
}

// @fnv 0x00ba87e0
const char* BSShaderTextureSet::GetTexture(BSShaderProperty::TextureTypeEnum textureType)
{
    return reinterpret_cast<BSStringT<char>*>(names)[textureType].pString;
}

void __cdecl _MyHelper00a5d2f0(int a);
// @fnv 0x00a81fe0
// src: XBOX_PDB 0x00a81fe0
void __cdecl BSTextureSet_RegisterStreamables(int a)
{
    _MyHelper00a5d2f0(a);
}

void nullsub_3();

// @fnv 0x00a724d0
// src: COMMUNITY 0x00a724d0
void NiInterpolator_LinkObject()
{
    nullsub_3();
}

template <class T> inline void NiStreamSaveBinaryBA89(NiBinaryStream* pkStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnWrite(pkStream, &value, sizeof(T), &uiSize, 1);
}

// Links the object into the stream, writes the texture count 6, and writes each of the six texture name strings to the stream.
// @fnv 0x00ba8970
void BSShaderTextureSet::SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);

    unsigned int uiTextureCount = 6;
    NiStreamSaveBinaryBA89(stream.m_pkOstr, uiTextureCount);

    for (int i = 0; i < 6; i++)
        stream.WriteStreamString(reinterpret_cast<BSStringT<char>*>(names)[i].pString);
}
