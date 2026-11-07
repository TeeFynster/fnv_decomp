#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysSpawnModifier.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiTPointerMap.h"

// src/gamebryo2.2/corelibs/niparticle/nipsysagedeathmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysagedeathmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern NiRTTI g_01202798;

// @fnv 0x00c2efe0
// src: COMMUNITY 0x00c2efe0
const NiRTTI* __cdecl NiPSysAgeDeathModifier_GetRTTI()
{
    return &g_01202798;
}

extern "C" const void* g_012027a0;

// @fnv 0x00c2f3d0
// src: COMMUNITY 0x00c2f3d0
const void* __cdecl NiPSysAirFieldSpreadCtlr_GetRTTI()
{
    return &g_012027a0;
}

struct FUN_00c2f3f0Target
{
    char _pad[0x64];
    float unk64;
};

struct NiPSysAirFieldSpreadCtlr
{
    char _pad[0x3c];
    FUN_00c2f3f0Target* unk3c;
    void __thiscall GetTargetFloatValue_00c2f3e0(float& fValue);
    void __thiscall SetTargetFloatValue_00c2f3f0(float fValue);
};

// @fnv 0x00c2f3e0
// src: XBOX_PDB 0x00c2f3e0
void __thiscall NiPSysAirFieldSpreadCtlr::GetTargetFloatValue_00c2f3e0(float& fValue)
{
    unsigned char* base = reinterpret_cast<unsigned char*>(this);
    int* ptr = reinterpret_cast<int*>(*(reinterpret_cast<int*>(base + 0x3c)));
    fValue = *reinterpret_cast<float*>(reinterpret_cast<unsigned char*>(ptr) + 0x64);
}


// No shared NiPSysAgeDeathModifier header is available yet; keep one local definition.
struct ParticleSystem;
struct NiPSysAgeDeathModifier : NiPSysModifier
{
    bool m_bSpawnOnDeath;
    NiPSysSpawnModifier* m_pSpawnModifier;
    void LinkObject_00c2ef60(NiStream&);
    void __thiscall ProcessClone_00c2f1a0(CloningProcess&);
    void* __thiscall Destroy(unsigned int);
    void GetViewerStrings_00c2f2c0(StrArr*);
    NiPSysAgeDeathModifier* CreateClone_00c2f150(CloningProcess&);
    bool IsEqual_00c2ef80(NiObject*);
    void UpdateAges(float, ParticleSystem*);
    void LoadBinary_00c2f200(NiStream&);
    void SaveAgeDeathModifier(NiStream*);
};

// NiStream is opaque here; the unit only needs its existing load/link entry points.
NiObject* __cdecl FUN_00a63430();
void __cdecl ReadLinkID();

// @fnv 0x00c2ef60
// src: XBOX_PDB 0x00c2ef60
void NiPSysAgeDeathModifier::LinkObject_00c2ef60(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
    typedef NiObject*(__thiscall * GetLoadedObjectProc)(NiStream*);
    m_pSpawnModifier = (NiPSysSpawnModifier*)reinterpret_cast<GetLoadedObjectProc>(&FUN_00a63430)(&kStream);
}

namespace fnv_00c2eff0 {
void __cdecl FUN_00c31750();
void __cdecl _delete(void*, unsigned int);
}  // namespace fnv_00c2eff0
// Calls FUN_00c31750, then frees this with _delete when flag has bit 0 set, and returns this.
// @fnv 0x00c2eff0
void* __thiscall NiPSysAgeDeathModifier::Destroy(unsigned int flag)
{
    fnv_00c2eff0::FUN_00c31750();
    if (flag & 1)
        fnv_00c2eff0::_delete(this, 0x20);
    return this;
}

#include "../../../../include/NiMemObject.h"
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

// Clone keys are NiObject pointers; GetAt at 0x00a53c30 is also bound to this
// shared NiTPointerMap specialization by nitimecontroller.cpp and niblendinterpolator.cpp.
// Calls the base ProcessClone, looks up the clone in the cloning map, and remaps the spawn modifier pointer to its cloned counterpart.
// @fnv 0x00c2f1a0
// src: XBOX_PDB 0x00c2f1a0
void __thiscall NiPSysAgeDeathModifier::ProcessClone_00c2f1a0(CloningProcess& kCloning)
{
    bool bFound;
    NiObject* pkClone;
    NiPSysAgeDeathModifier* pkDest;
    NiPSysModifier::ProcessClone(kCloning);
    pkClone = 0;
    kCloning.m_pCloneMap->GetAt(this, pkClone);
    pkDest = (NiPSysAgeDeathModifier*)pkClone;
    if (m_pSpawnModifier)
    {
        bFound = kCloning.m_pCloneMap->GetAt(m_pSpawnModifier, pkClone);
        if (bFound)
        {
            pkDest->m_pSpawnModifier = (NiPSysSpawnModifier*)pkClone;
            return;
        }
        pkDest->m_pSpawnModifier = m_pSpawnModifier;
    }
}

struct FUN_00c32d80
{
    FUN_00c32d80();
};
extern int DAT_010c03cc;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// @fnv 0x00c2f3a0
// src: EXE 0x00c2f3a0
FUN_00c32d80* __cdecl NiPSysAirFieldSpreadCtlr_CreateObject()
{
    FUN_00c32d80* p = (FUN_00c32d80*)BSFadeNode::operator new(0x40);
    if (p)
    {
        new (p) FUN_00c32d80();
        *(int*)p = (int)&DAT_010c03cc;
        return p;
    }
    return 0;
}

void __cdecl FUN_00c319e0();
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
char* __cdecl NiGetViewerString(char const*, bool);
char* __cdecl NiGetViewerString_00a7d5e0(char const*, char const*);
extern char const* const g_011d1f8c_arg1;
// @fnv 0x00c2f2c0
// src: XBOX_PDB 0x00c2f2c0
void NiPSysAgeDeathModifier::GetViewerStrings_00c2f2c0(StrArr* pkStrings)
{
    typedef void(__thiscall * ViewerStringsProc)(NiPSysModifier*, StrArr*);
    reinterpret_cast<ViewerStringsProc>(&FUN_00c319e0)(this, pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(*(char**)&g_01202798);
    unsigned int uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, pcString);
    pcString = NiGetViewerString("Spawn on Death", m_bSpawnOnDeath);
    uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, pcString);
    char const* pcModifierName =
        m_pSpawnModifier ? m_pSpawnModifier->m_kName.m_kHandle : (char const*)&g_011d1f8c_arg1;
    pcString = NiGetViewerString_00a7d5e0("Spawn Modifier", pcModifierName);
    uiIndex = ((unsigned short*)pkStrings)[5];
    if (uiIndex >= ((unsigned short*)pkStrings)[4])
        pkStrings->SetSize(((unsigned short*)pkStrings)[7] + uiIndex);
    pkStrings->SetAt(uiIndex, pcString);
}

extern int DAT_010c0304;
// @fnv 0x00c2f150
// src: XBOX_PDB 0x00c2f150
NiPSysAgeDeathModifier* NiPSysAgeDeathModifier::CreateClone_00c2f150(CloningProcess& kCloning)
{
    NiPSysAgeDeathModifier* pkObject = (NiPSysAgeDeathModifier*)BSFadeNode::operator new(0x20);
    if (pkObject)
    {
        pkObject->NiPSysModifier::NiPSysModifier();
        *reinterpret_cast<void**>(pkObject) = &DAT_010c0304;
        pkObject->m_bSpawnOnDeath = false;
        pkObject->m_pSpawnModifier = 0;
    }
    else
    {
        pkObject = 0;
    }
    CopyMemberData((NiPSysModifier*)pkObject, kCloning);
    pkObject->m_bSpawnOnDeath = m_bSpawnOnDeath;
    return pkObject;
}

// @fnv 0x00c2ef80
// src: XBOX_PDB 0x00c2ef80
bool NiPSysAgeDeathModifier::IsEqual_00c2ef80(NiObject* pkObject)
{
    if (!NiPSysModifier::IsEqual(pkObject))
        return false;

    NiPSysAgeDeathModifier* pkOther = (NiPSysAgeDeathModifier*)pkObject;

    if (pkOther->m_bSpawnOnDeath != m_bSpawnOnDeath)
        return false;

    if ((pkOther->m_pSpawnModifier && !m_pSpawnModifier) || (!pkOther->m_pSpawnModifier && m_pSpawnModifier))
        return false;

    if (pkOther->m_pSpawnModifier && m_pSpawnModifier && !static_cast<const NiObject*>(pkOther->m_pSpawnModifier)->IsEqual(m_pSpawnModifier))
        return false;

    return true;
}

// Reworked from another contributor's supplied best attempt; credit retained.

struct ParticleInfo
{
    float x, y, z, age, lifespan, lastUpdate, variance;
};
struct ParticleSystem
{
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
    virtual void SetParticleCount(unsigned short);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
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
    unsigned short capacity;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    ParticleInfo* info;
};
// Advances each particle's age by the elapsed time and removes particles whose age exceeds their lifespan, optionally spawning on death.
// @fnv 0x00c2f010
void NiPSysAgeDeathModifier::UpdateAges(float time, ParticleSystem* particles)
{
    if (m_bSpawnOnDeath && m_pSpawnModifier)
    {
        unsigned short info = particles->count;
        while (info > 0)
        {
            unsigned short index = info - 1;
            ParticleInfo* age = &particles->info[index];
            float r;
            r = time - age->lastUpdate + age->age;
            age->age = r;
            if (age->lifespan < r)
            {
                // The shared overload takes an unsigned int; this call uses the original unsigned-short ABI.
                typedef void(__thiscall * SpawnChildProc)(NiPSysSpawnModifier*, float, float,
                                                         unsigned short, ParticleSystem*);
                SpawnChildProc* vtable = *reinterpret_cast<SpawnChildProc**>(m_pSpawnModifier);
                vtable[41](m_pSpawnModifier, time, age->lifespan + time - r, index,
                           reinterpret_cast<ParticleSystem*>(m_pkTarget));
                particles->SetParticleCount(index);
            }
            --info;
        }
    }
    else
    {
        unsigned short info = particles->count;
        while (info > 0)
        {
            unsigned short index = info - 1;
            ParticleInfo* age = &particles->info[index];
            float r = time - age->lastUpdate + age->age;
            age->age = r;
            if (r > age->lifespan)
                particles->SetParticleCount(index);
            --info;
        }
    }
}

// Stream storage is opaque in the shared header; retain the original inline transfers.
inline void NiBinaryStream::ReadScalar(void* pvValue, unsigned int uiSize)
{
    unsigned int uiComponentSize = uiSize;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) +=
        (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
            this, pvValue, 1, &uiComponentSize, 1);
}

// @fnv 0x00c2f200
// src: XBOX_PDB 0x00c2f200
void NiPSysAgeDeathModifier::LoadBinary_00c2f200(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    unsigned char ucFlag;
    (*reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c))->ReadScalar(&ucFlag, 1);
    m_bSpawnOnDeath = ucFlag != 0;
    typedef void(__thiscall * ResetStreamProc)(NiStream*);
    reinterpret_cast<ResetStreamProc>(&ReadLinkID)(&kStream);
}

inline void NiBinaryStream::WriteSpawnFlag(const bool& onDeath)
{
    unsigned int count = 1;
    unsigned int amount = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(
        this, &onDeath, 1, &count, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += amount;
}
// Calls the base modifier save, writes the spawn-on-death flag to the stream's binary output, then writes the spawn modifier link.
// @fnv 0x00c2f260
void NiPSysAgeDeathModifier::SaveAgeDeathModifier(NiStream* stream)
{
    reinterpret_cast<NiPSysModifier*>(this)->FUN_00c31950(*stream);
    NiPSysAgeDeathModifier* modifier = reinterpret_cast<NiPSysAgeDeathModifier*>(this);
    bool spawnOnDeath = modifier->m_bSpawnOnDeath;
    NiBinaryStream* output = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(stream) + 0x250);
    output->WriteSpawnFlag(spawnOnDeath);
    typedef void(__thiscall * WriteLinkProc)(NiStream*, NiPSysSpawnModifier*);
    WriteLinkProc* pVtbl = *reinterpret_cast<WriteLinkProc**>(stream);
    pVtbl[12](stream, modifier->m_pSpawnModifier);
}

double g_01012060 = 0.0;
double g_01012070 = 1.0;

// Clamps fValue to [0,1] and stores it into the target's unk64 field.
// @fnv 0x00c2f3f0
// src: XBOX_PDB 0x00c2f3f0
void __thiscall NiPSysAirFieldSpreadCtlr::SetTargetFloatValue_00c2f3f0(float fValue)
{
    FUN_00c2f3f0Target* target = this->unk3c;
    float fClamped = fValue;

    if (fClamped < g_01012060)
    {
        fClamped = 0.0f;
    }
    if (fClamped > g_01012070)
    {
        fClamped = 1.0f;
    }

    target->unk64 = fClamped;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct Host2f440
{
    void FUN_00c32de0(FUN_00c32d80* obj, int arg);
    FUN_00c32d80* CreateAndInit(int arg);
};
// Allocates a 0x40-byte object, constructs it with a vtable, initializes it via FUN_00c32de0 with arg, and returns it (or null on allocation failure).
// @fnv 0x00c2f440
FUN_00c32d80* Host2f440::CreateAndInit(int arg)
{
    FUN_00c32d80* p = (FUN_00c32d80*)Object_DispatchCommandFour(0x40);
    if (p)
    {
        new (p) FUN_00c32d80;
        *(int**)p = &DAT_010c03cc;
    }
    else
    {
        p = 0;
    }
    FUN_00c32de0(p, arg);
    return p;
}

void __cdecl FUN_00c31670();

// @fnv 0x00c28b60
// src: XBOX_PDB 0x00c28b60
void __cdecl NiPSysAgeDeathModifier_RegisterStreamables()
{
    FUN_00c31670();
}
