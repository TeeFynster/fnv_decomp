// gamebryo2.2/corelibs/niparticle/nipsyspositionmodifier.cpp: NiPSysPositionModifier, Helper, NiPSysModifier (9 functions)

#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/StrArr.h"
#include <string.h>

extern NiFixedString EmptyFS;
extern void* g_modifierVtable;
extern void* g_positionModifierVtable;
void __cdecl ConstructNiObject();

// The shared base supplies the layout. These entry points provide the
// constructor and viewer-string operations absent from its declaration.
class PositionModifierOperations : public NiPSysModifier
{
public:
    __declspec(noinline) PositionModifierOperations* Initialize() throw();
    void AppendString(StrArr* strings);
    void AppendModifierStrings(StrArr* strings);
    PositionModifierOperations* Clone(CloningProcess& process);
    void CopyPositionMembers(PositionModifierOperations* destination, CloningProcess& process);
};

// @fnv 0x00c31720
PositionModifierOperations* PositionModifierOperations::Initialize() throw()
{
    typedef void (__thiscall *ObjectConstructor)(NiObject*);
    reinterpret_cast<ObjectConstructor>(&ConstructNiObject)(this);
    *(void**)this = &g_modifierVtable;
    m_kName.m_kHandle = EmptyFS.m_kHandle;
    memset(&m_uiUpdateOrder, 0,
        reinterpret_cast<char*>(&m_pkTarget + 1) - reinterpret_cast<char*>(&m_uiUpdateOrder));
    m_bModifierActive = true;
    return this;
}

extern "C" void* g_012026b8;

// @fnv 0x00c28b90
// src: COMMUNITY 0x00c28b90
void* __cdecl NiPSysPositionModifier_GetRTTI()
{
    return &g_012026b8;
}

void __cdecl FUN_00c31750(void);
void __cdecl _delete(void*, unsigned int);
struct Helper
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00c31750, then deletes this with size 0x18 when bit 0 of flags is set, and returns this.
// @fnv 0x00c28ba0
void* Helper::DestroyIfFlagged(unsigned int flags)
{
    FUN_00c31750();
    if (flags & 1)
        _delete(this, 0x18);
    return this;
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
// @fnv 0x00c28cb0
void PositionModifierOperations::AppendString(StrArr* pkStrings)
{
    AppendModifierStrings(pkStrings);
    char* pcStr = NiViewerStrings_NiGetViewerString_Title((const char*)g_012026b8);
    unsigned int uiIdx = pkStrings->m_usSize;
    if (uiIdx >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIdx + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIdx, pcStr);
}

struct FnvV3
{
    float x, y, z;
};

struct FnvPSysPos
{
    float x, y, z;
};

struct FnvPSysPart
{
    float x, y, z;
    float unk0c, unk10;
    float lastTime;
    int unk18;
};

struct FnvMod
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FnvPSysPos* positions;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    unsigned short count;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    FnvPSysPart* parts;
    int unk74;
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void Slot43();
};

// Advances each particle position by its velocity times the elapsed time since its last update, then stores the new time.
// @fnv 0x00c28bc0
void __stdcall IntegrateParticlePositions(float fTime, FnvMod* pMod)
{
    pMod->Slot43();
    FnvPSysPart* parts = pMod->parts;
    for (unsigned short usIndex = 0; usIndex < pMod->count; usIndex++)
    {
        FnvPSysPart* part = parts + usIndex;
        FnvPSysPos* pos = pMod->positions + usIndex;
        // the time delta is built in two steps: the copy of fTime and the
        // subtraction of the stored stamp.  Keeping them apart changes how
        // cl 15.00.30729.01 schedules the x87 stack, which is what the
        // original code shows.
        float dt = fTime;
        dt = dt - part->lastTime;
        FnvV3 v;
        v.x = part->x * dt;
        v.y = part->y * dt;
        v.z = part->z * dt;
        pos->x += v.x;
        pos->y += v.y;
        pos->z += v.z;
        part->lastTime = fTime;
    }
}

inline PositionModifierOperations* ConstructPositionModifier(void* memory) throw()
{
    PositionModifierOperations* object = static_cast<PositionModifierOperations*>(memory);
    object->Initialize();
    *(void**)object = &g_positionModifierVtable;
    return object;
}

// @fnv 0x00c28c60
PositionModifierOperations* PositionModifierOperations::Clone(CloningProcess& kCloning)
{
    void* memory = NiPSysModifier::operator new(sizeof(NiPSysModifier));
    PositionModifierOperations* pkClone = memory ? ConstructPositionModifier(memory) : 0;
    CopyPositionMembers(pkClone, kCloning);
    return pkClone;
}

// @fnv 0x00c28b50
// src: XBOX_PDB 0x00c28b50
void NiPSysModifier::NiPSysPositionModifier_LoadBinary(NiStream& a1)
{
    NiPSysModifier::LoadBinary(a1);
}

void __cdecl FUN_00c31830();
// @fnv 0x00c28b80
// src: XBOX_PDB 0x00c28b80
void __cdecl NiPSysPositionModifier_IsEqual()
{
    FUN_00c31830();
}

void __cdecl FUN_00c31950();

// @fnv 0x00c28b70
// src: XBOX_PDB 0x00c28b70
void __cdecl NiPSysPositionModifier_SaveBinary()
{
    FUN_00c31950();
}
