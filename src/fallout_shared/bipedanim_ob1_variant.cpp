
// src/fallout_shared/bipedanim_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bipedanim.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "bipedanim_decls.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern char* DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* s);
struct FixStrQ
{
    char* m_kHandle;
    FixStrQ(const char* s)
    {
        if (s == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(s);
    }
    ~FixStrQ()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        long* pRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(pRef);
    }
};
struct ResultQ;
struct FinderQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34();
    virtual ResultQ* Find(const FixStrQ& name);
};
struct ExtQ
{
    char pad[0x78];
    FinderQ* m_pFinder;
    FinderQ* GetFinder()
    {
        FinderQ* p = m_pFinder;
        return p;
    }
};
extern "C" char DAT_011f36ac;
struct ObjQ
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(),
        v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38();
    virtual ResultQ* GetObjectByName(const FixStrQ& name);
    ExtQ* __thiscall NiObjectNET_GetController(void* rtti);
};
// @fnv 0x00c4b310
// src: XBOX_PDB 0x00c4b310
ResultQ* __cdecl BSUtilities_GetObjectByName_00c4b310(ObjQ* pObj, const char* pcName, bool bRecurse)
{
    if (!pObj || !pcName)
        return 0;
    ExtQ* pExt3 = pObj->NiObjectNET_GetController(&DAT_011f36ac);
    FixStrQ kName9(pcName);
    if (pExt3)
    {
        ResultQ* pRes2 = pExt3->GetFinder()->Find(kName9);
        if (pRes2)
            return pRes2;
    }
    if (bRecurse)
        return pObj->GetObjectByName(kName9);
    return 0;
}
