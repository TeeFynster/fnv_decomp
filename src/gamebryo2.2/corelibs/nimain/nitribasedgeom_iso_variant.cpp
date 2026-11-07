
// src/gamebryo2.2/corelibs/nimain/nitribasedgeom_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/nimain/nitribasedgeom.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "nitribasedgeom_decls.h"
#include "../../../../include/NiUpdateData.h"

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4a48;

// @fnv 0x00a74790
// src: COMMUNITY 0x00a74790
const GlobalObjectO2_00a7b610* NiLines_GetRTTI()
{
    return &g_011f4a48;
}

extern "C" unsigned int DAT_0109ed94;
extern "C" void __fastcall UpdateFields_00a80580(::NiGeometry*);
extern "C" void __cdecl FUN_00aa1460(void*, unsigned int);

// @fnv 0x00a89790
extern "C" ::NiGeometry* __fastcall FUN_00a89790(::NiGeometry* geometry, void*, unsigned int flags)
{
    *reinterpret_cast<void**>(geometry) = &DAT_0109ed94;
    UpdateFields_00a80580(geometry);
    if (flags & 1u)
        FUN_00aa1460(geometry, sizeof(*geometry));
    return geometry;
}

struct FUN_00a59f90_holder
{
    void __thiscall FUN_00a59f90(NiUpdateData& data, unsigned int value);
};
struct ParticleDownwardPassReceiver
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void dispatch(void* data);
    void __thiscall NiParticleSystem_UpdateDownwardPass(void* data, unsigned int value);
};
// @fnv 0x00c1ad90
// src: XBOX_PDB 0x00c1ad90
void ParticleDownwardPassReceiver::NiParticleSystem_UpdateDownwardPass(void* data, unsigned int value)
{
    NiUpdateData* update = (NiUpdateData*)data;
    if (update->pad2 != 0)
    {
        update->pad3 = 1;
        return;
    }
    dispatch(data);
    ((FUN_00a59f90_holder*)this)->FUN_00a59f90(*(NiUpdateData*)data, value);
}

class NiStream;
class ParticleLinkEndpoint : public NiGeometry
{
  public:
    void FUN_00a80b50(NiStream&);
// @fnv 0x00a74780
// src: XBOX_PDB 0x00a74780
    void NiLines_LinkObject(NiStream& input)
    {
        FUN_00a80b50(input);
    }
};

void (ParticleLinkEndpoint::*linkEndpoint)(NiStream&) = &ParticleLinkEndpoint::NiLines_LinkObject;

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f5b70;

// @fnv 0x00a89780
// src: COMMUNITY 0x00a89780
extern "C" GlobalObjectO2_00a7b610* __cdecl NiTriBasedGeom_GetRTTI()
{
    return &g_011f5b70;
}

// Integrate after NiGeometry::NiGeometry(), before the existing final optimization-off boundary.
namespace TriGeomViewerDetail {
struct EntryArray
{
    void* vtable;
    char** data;
    unsigned short capacity;
    unsigned short end;
    unsigned short occupied;
    unsigned short growBy;

    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int position, char* const& entry);

    void Append(char* const& entry)
    {
        const unsigned int position = end;
        if (position >= capacity)
            FUN_0096ad30(position + growBy);
        FUN_0096ae90(position, entry);
    }
};

extern const char* const g_011f4a20_arg1;
void __stdcall FUN_00a80e70(EntryArray*);
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
}

// @fnv 0x00a897c0
// src: XBOX_PDB 0x00a897c0
void __stdcall NiTriBasedGeom_GetViewerStrings(TriGeomViewerDetail::EntryArray* entries)
{
    TriGeomViewerDetail::FUN_00a80e70(entries);
    char* label = TriGeomViewerDetail::NiViewerStrings_NiGetViewerString_Title(TriGeomViewerDetail::g_011f4a20_arg1);
    entries->Append(label);
}

namespace LineLoadEntry {
class BinaryDataRecord;
class LineReceiver : public ::NiGeometry
{
  public:
    void FUN_00a80bf0(BinaryDataRecord& stream);
    void NiLines_LoadBinary(BinaryDataRecord& stream);
};

// @fnv 0x00a9b180
// src: XBOX_PDB 0x00a9b180
void LineReceiver::NiLines_LoadBinary(BinaryDataRecord& stream)
{
    FUN_00a80bf0(stream);
}
}

class NiGeometryData;

class ParticleDataEndpoint : public ::NiGeometry
{
  public:
    void FUN_00a80680(NiGeometryData*);
    virtual void NiParticleSystem_SetModelData(NiGeometryData*);
};

// @fnv 0x00c1ad80
// src: XBOX_PDB 0x00c1ad80
void ParticleDataEndpoint::NiParticleSystem_SetModelData(NiGeometryData* replacement)
{
    FUN_00a80680(replacement);
}
