
// src/fallout_shared/havok/decalcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/decalcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiShader.h"
#include "../../../include/RootContactPoint.h"
#include "../../../include/bhkNiCollisionObject.h"
#include "../../../include/hkpWorldObject.h"

// Exe 0x00623290: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct DecalcasterOffset08View
{
    unsigned int GetFlags();
};
const void* __fastcall hkpCollidable_getOwner(const char*);
struct DecalCaster
{
    const RootContactPoint* DecalCaster_GetCollision(unsigned int);
    unsigned int GetCollisionFlags(unsigned int);
};
// Looks up the entry at aiIndex, resolves its name to a collision object, casts it to NiAVObject and returns its flags, or 0 if absent.
// @fnv 0x00623290
unsigned int DecalCaster::GetCollisionFlags(unsigned int aiIndex)
{
    unsigned int uiFlags;
    uiFlags = 0;
    {
        const RootContactPoint* pEntry;
        pEntry = DecalCaster_GetCollision(aiIndex);
        if (pEntry->m_pRootCollidableB)
        {
            {
                bhkNiCollisionObject* pCollisionObject;
                pCollisionObject = (bhkNiCollisionObject*)hkpCollidable_getOwner((const char*)pEntry->m_pRootCollidableB);
                {
                    NiAVObject* pObject;
                    pObject = NiShader::DynamicCast((NiAVObject*)pCollisionObject);
                    if (pObject)
                        uiFlags = ((DecalcasterOffset08View*)pObject)->GetFlags();
                }
            }
        }
    }
    return uiFlags;
}
