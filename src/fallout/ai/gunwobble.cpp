// src/fallout/ai/gunwobble.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/gunwobble.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_008d6a80_Obj
{
    void* NiAVObject_GetCollisionObject();
};
struct S_008d6a80_Holder
{
    void bhkBlendCollisionObjectAddRotation_SetAdditionalRotation(void* data);
};
extern void* DAT_011e00e0[];
extern char DAT_012681cc;
extern char DAT_011a9448;
S_008d6a80_Obj* BSUtilities_GetObjectByName(void* root, void* name);
void* NiObject_DynamicCast(void* rtti, void* obj);

// Looks up the object named by DAT_011e00e0[idx] under root, resolves its holder via FUN_00653270 and passes DAT_011a9448 to FUN_004f0110.
// @fnv 0x008d6a80
// src: XBOX_PDB 0x008d6a80
void ClearGunWobble(int iIndex, void* root)
{
    if (DAT_011e00e0[iIndex])
    {
        S_008d6a80_Obj* obj = BSUtilities_GetObjectByName(root, DAT_011e00e0[iIndex]);
        if (obj)
        {
            S_008d6a80_Holder* holder = (S_008d6a80_Holder*)NiObject_DynamicCast(&DAT_012681cc, obj->NiAVObject_GetCollisionObject());
            if (holder)
                holder->bhkBlendCollisionObjectAddRotation_SetAdditionalRotation(&DAT_011a9448);
        }
    }
}
