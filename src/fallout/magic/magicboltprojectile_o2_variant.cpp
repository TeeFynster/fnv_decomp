
// src/fallout/magic/magicboltprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicboltprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout/magic/magicboltprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicboltprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct RefH
{
    bool IsDeleted() const;
};
struct FUN_00811930_shell : RefH
{
    bool IsNotDeleted() const;
};
extern int DAT_011ae61c;
void BoltShader_SetSubSegmentCount(int value);
struct FUN_008133d0_shell
{
    void MagicBoltProjectile_SetState(int value);
};

// 0x00bc2360 indexes a 16-byte particle-position stream; NiPoint3 would change the stride to 12.
struct EmitterPosition4View_00bc2360 { float x, y, z, w; };
#include <stdlib.h>
#include <math.h>
double FUN_00ec9e10(double);
inline float rounded(float value)
{
    float result = (float)ceil(value);
    return result;
}
inline float randomRange(const float& range)
{
    float fraction = (float)(rand() / 32767.0);
    return (float)(range * fraction - range * 0.5);
}
struct Emitter
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
    EmitterPosition4View_00bc2360* positions;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    float elapsed;
    int batch;
    int current;
    int emitted;
    int total;
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
    unsigned int unk0d8;
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
    int count;
    unsigned int unk12c;
    float range;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    int stride;
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
    unsigned char active, state, flags, centered;
    int BoltShader_GetMaxSegments();
    void BoltShaderProperty_InitSegmentData();
};
// @fnv 0x00bc2360
// src: XBOX_PDB 0x00bc2360
void Emitter::BoltShaderProperty_InitSegmentData()
{
    int available = BoltShader_GetMaxSegments();
    elapsed = 0.0f;
    active = false;
    if (available < count * stride)
    {
        float deficit = (float)(count * stride - available) / stride;
        float removed = rounded(deficit);
        count -= (int)removed;
    }
    batch = stride > 4 ? 4 : stride;
    total = count * stride;
    for (int i = 0; i < count; ++i)
    {
        if (centered)
        {
            positions[i].x = 0.0f;
            positions[i].y = 0.0f;
            positions[i].z = 0.0f;
        }
        else
        {
            positions[i].x = randomRange(range);
            positions[i].y = randomRange(range);
            positions[i].z = randomRange(range);
        }
    }
    current = 0;
    emitted = 0;
}
