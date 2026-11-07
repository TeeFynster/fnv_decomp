
// src/fallout/ai/creature_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/creature.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.


struct DAT_010c53b4_t
{
    void* vtable;
    void*(__thiscall* Alloc)(void*, unsigned int);
    void(__thiscall* Free)(void*, void*);
};
extern DAT_010c53b4_t DAT_010c53b4;

int __cdecl bhkUtilFunctions_FindCollisionObjectBFSRec(void*, void*, void*, int);

struct LocalObj
{
    void* vptr;
    void* data;
    int size;
    int capacity;

    LocalObj()
    {
        vptr = &DAT_010c53b4;
        data = 0;
        size = 0;
        capacity = 0;
        data = DAT_010c53b4.Alloc(this, 0x20);
        capacity = 0x20;
    }

    ~LocalObj()
    {
        vptr = &DAT_010c53b4;
        if (data)
        {
            DAT_010c53b4.Free(this, data);
        }
    }
};

// @fnv 0x00c812d0
// src: COMMUNITY 0x00c812d0
int __cdecl bhkUtilFunctions_FindCollisionObjectBFS(void* a1, void* a2)
{
    LocalObj local;
    return bhkUtilFunctions_FindCollisionObjectBFSRec(a1, &local, a2, 0);
}

class NiAVObject;
class NiCollisionObject;

struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iValue;
    int iOption;
    int uNewnk;
    int uTmpnk;
};

struct C6A350Properties
{
    int unk;
    int unkCur;
    int unkValue;
    unsigned int m_uiValue1;
};
extern "C" C6A350Properties* GetExtraDataChecked(NiAVObject* pkObject);
static inline unsigned int C6A350IsEnabled(NiAVObject* pkObject)
{
    C6A350Properties* pkProps = GetExtraDataChecked(pkObject);
    return pkProps ? (pkProps->m_uiValue1 & 2) : 0;
}

typedef void (*CollisionObjectCountCallback)(NiCollisionObject*, CollisionObjectCountContext*);
void bhkWorld_DoObjectRec(NiAVObject* pkObject, CollisionObjectCountContext* pkContext,
                  CollisionObjectCountCallback pfnCallback);
extern CollisionObjectCountCallback DAT_011afe9c;

// @fnv 0x00c6a350
// src: XBOX_PDB 0x00c6a350
bool bhkWorld_SetMotion(NiAVObject* pkObject, int iValue, bool bRecurse, bool bForce, bool bOption)
{
    bool bResult = false;
    if (pkObject && (bForce || C6A350IsEnabled(pkObject)))
    {
        CollisionObjectCountContext kContext;
        bResult = true;
        kContext.pCurrentObject = 0;
        kContext.bRecurse = bRecurse;
        kContext.uiTraversalFlags = 5;
        kContext.iValue = iValue;
        kContext.iOption = bOption;
        if (DAT_011afe9c)
            bhkWorld_DoObjectRec(pkObject, &kContext, DAT_011afe9c);
    }
    return bResult;
}
