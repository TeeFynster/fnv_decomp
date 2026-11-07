
// src/fallout_shared/bipedanim_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/bipedanim.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/NiFixedString.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiShader.h"
#include "../../include/NiNode.h"
#include "../../include/NiMaterialProperty.h"
#include "../../include/BSShaderProperty.h"
#include "../../include/NiCollisionObject.h"
#include "../../include/bhkBlendCollisionObject.h"
#include "../../include/NiGeometry.h"

extern int EmptyFS;
// @fnv 0x00a5bc40
bool NiAVObject::AddExtraData(const NiFixedString& kName, NiExtraData* pkTex)
{
    if ((int)kName.m_kHandle == EmptyFS)
        return false;
    if (!pkTex)
        return false;
    if (((NiShader*)pkTex)->GetFilename().m_kHandle == (const char*)EmptyFS)
    {
        ((NiAVObject*)pkTex)->SetName(kName);
    }
    else
    {
        if (kName.m_kHandle != ((NiShader*)pkTex)->GetFilename().m_kHandle)
            return false;
    }
    return AddExtraData((void*)pkTex);
}

// @fnv 0x00b553d0
// src: COMMUNITY 0x00b553d0
void __cdecl BSShaderManager_SetEmittanceRecurse(NiGeometry* pObject, NiPoint3* pValue)
{
    if (pObject == 0)
        return;

    if (static_cast<const NiObject*>(pObject)->IsGeometry() != 0)
    {
        NiProperty* pFirst = pObject->GetProperty(2);
        NiProperty* pSecond = pObject->GetProperty(3);

        if (pFirst != 0 && pSecond != 0)
        {
            NiMaterialProperty* pMaterial = (NiMaterialProperty*)pFirst;
            BSShaderProperty* pShader = (BSShaderProperty*)pSecond;

            if ((pShader->ulFlags[0] & 0x20000000u) <= 0)
                return;

            *(NiPoint3*)&pMaterial->unk28 = *pValue;
            ++pMaterial->unk44;
        }
        return;
    }

    NiNode* pNode = pObject->IsSceneNode();
    if (pNode == 0)
        return;

    unsigned int count = pNode->m_kChildren.m_usSize;
    for (unsigned int i = 0; i < count; ++i)
    {
        NiAVObject* pChild = pNode->m_kChildren.m_pBase[i].m_pObject;
        if (pChild != 0)
            BSShaderManager_SetEmittanceRecurse((NiGeometry*)pChild, pValue);
    }
}

NiAVObject* BSUtilities_GetObjectByName_00c4b310(NiAVObject* root, const char* name, int flag);
NiAVObject* BSUtilities_GetObjectByName_00c4b470(NiAVObject* root, NiFixedString* name, int flag);
struct AttachInfo
{
    void* m_data;
};

void WeaponObject_Constrain(void* a1, AttachInfo a2, NiAVObject* obj, NiAVObject* parent, bool a4);

inline NiNode* NiAVObject::GetParent() const
{
    return m_pkParent;
}

static __forceinline NiAVObject* FindAttachParent(NiAVObject* obj, NiAVObject* root)
{
    NiAVObject* p = obj ? static_cast<const NiAVObject*>(obj)->GetParent() : 0;
    while (p)
    {
        NiCollisionObject* c = p->m_spCollisionObject.m_pObject;
        if (c && (!c->IsBhkBlendCollisionObject() || *(unsigned int*)&p->m_spCollisionObject.m_pObject->IsBhkBlendCollisionObject()->unk0C[4] != 0))
            break;
        if (p == root)
            break;
        p = static_cast<const NiAVObject*>(p)->GetParent();
    }
    if (p == root)
        return 0;
    return p;
}

// @fnv 0x00c89050
// src: XBOX_PDB 0x00c89050
void __stdcall WeaponObject_UpdateConstraints(void* a1, AttachInfo a2, NiAVObject* root, bool a4)
{
    NiAVObject* obj = BSUtilities_GetObjectByName_00c4b310(root, "Weapon", 0);
    NiAVObject* parent = FindAttachParent(obj, root);
    if (obj && parent)
        WeaponObject_Constrain(a1, a2, obj, parent, a4);

    static NiFixedString kBackpack("Backpack");
    obj = BSUtilities_GetObjectByName_00c4b470(root, &kBackpack, 0);
    parent = FindAttachParent(obj, root);
    if (obj && parent)
        WeaponObject_Constrain(a1, a2, obj, parent, a4);
}

