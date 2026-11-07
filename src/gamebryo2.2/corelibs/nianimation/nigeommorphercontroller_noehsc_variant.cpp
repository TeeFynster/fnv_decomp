
// src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller_noehsc_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp
// NiGeomMorpherController: morph-target interpolator management.
#include "NiRefObject_inline.h"
#include "nigeommorphercontroller.h"

namespace fnv_00a3b150 {
struct MorphMemoryManager
{
    void* Game_DoHeapAlloc(unsigned int size);
};
extern MorphMemoryManager DAT_011f6238;
struct BinaryReader
{
    unsigned int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(BinaryReader*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* destination, unsigned int size)
    {
        unsigned int componentSize = size;
        position += read(this, destination, size, &componentSize, 1);
    }
};
struct MorphStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int version;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    BinaryReader* reader;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned short unk284;
    unsigned short legacyFlags;
    void ReadLinkID();
    void NiStream_ReadMultipleLinkIDs();
    NiInterpolator* FUN_00a64620();
};
struct LoadBase : NiInterpController
{
    void LoadBinary(MorphStream&);
};
struct LoadItem
{
    NiPointer<NiInterpolator> interpolator;
    float weight;
    __declspec(noinline) LoadItem() throw() : weight(0.0f)
    {}
    ~LoadItem() throw()
    {}
    static void* operator new[](unsigned int size) throw()
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
};
struct MorphLoad : LoadBase
{
    unsigned short m_uiObjectFlags;
    unsigned short unk36;
    NiPointer<NiMorphData> m_spMorphTargetData;
    LoadItem* m_pInterpolatorItems;
    bool m_bUpdateEnabled;
    bool m_bUpdateNormals;
    bool m_bNeedsUpdate;
    bool m_bUpdateBounds;
    void NiGeomMorpherController_LoadBinary(MorphStream& stream);
};
// @fnv 0x00a3b150
// src: XBOX_PDB 0x00a3b150
void MorphLoad::NiGeomMorpherController_LoadBinary(MorphStream& stream)
{
    LoadBase::LoadBinary(stream);
    if (stream.version < 0x0a000102)
        m_uiObjectFlags = (stream.legacyFlags >> 5) & 0x3f;
    else
        stream.reader->Read(&m_uiObjectFlags, 2);
    stream.ReadLinkID();
    if (stream.version >= 0x04000002)
    {
        unsigned char value;
        stream.reader->Read(&value, 1);
        m_bNeedsUpdate = value != 0;
    }
    if (stream.version >= 0x0a010068)
    {
        if (stream.version < 0x14010003)
        {
            stream.NiStream_ReadMultipleLinkIDs();
        }
        else
        {
            unsigned int count;
            stream.reader->Read(&count, 4);
            m_pInterpolatorItems = new LoadItem[count];
            for (unsigned short index = 0; index < count; ++index)
            {
                m_pInterpolatorItems[index].interpolator = stream.FUN_00a64620();
                stream.reader->Read(&m_pInterpolatorItems[index].weight, 4);
            }
        }
    }
}
}  // namespace fnv_00a3b150
