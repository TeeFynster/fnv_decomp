
// src/bsshader/boltshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/boltshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern float DAT_0101e2bc;
extern double DAT_0101ffa0;

class Ring216
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    char* m_60;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int m_78;
    int m_7c;
    int unk080;
    float m_84;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    float m_144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    bool wrapped;
    char unk175, unk176, unk177;
    int unk178;
    int unk17c;
    float m_180;
    int count184;

    void AddValueToColumnRange(float v);
    void BoltShaderProperty_CleanupSegments(int idx);
    void BoltShaderProperty_ExtendSegments(int idx);
    void RemoveFromEnd(int idx);

    void AddValue(float p1, float p2, float p3, float p4);
};

// src: COMMUNITY 0x00bc1c70
void Ring216::BoltShaderProperty_CleanupSegments(int idx)
{
    int remainder = idx % unk140;
    m_78 += remainder;
    if (wrapped && m_78 >= unk140)
    {
        m_78 -= unk140;
        wrapped = false;
    }
    count184 -= remainder;
    if (!wrapped && m_78 >= m_7c)
        m_78 = m_7c;
}
// Uses p1 and p3 to update the column range, then adjusts ring indices using p2 and stored bounds.
// @fnv 0x00bc2740
void Ring216::AddValue(float afValue, float p2, float afScale, float afUnused)
{
    float fScaledValue = ((double)afValue > DAT_0101ffa0) ? DAT_0101e2bc : afValue;
    fScaledValue = fScaledValue * afScale;
    this->AddValueToColumnRange(fScaledValue);
    float c = this->m_144;
    if (c > p2)
        p2 = c;

    this->m_84 = *(float*)(this->m_60 + (this->m_7c << 4) + 4);
    float z = *(float*)(this->m_60 + (this->m_78 << 4) + 4);
    this->m_180 = z;

    if (-this->m_144 >= z)
    {
        z = -z / this->m_144;
        this->BoltShaderProperty_CleanupSegments((int)z);
        this->m_180 = *(float*)(this->m_60 + (this->m_78 << 4) + 4);
    }

    if (p2 > this->m_84)
    {
        z = (p2 - this->m_84) / this->m_144;
        this->BoltShaderProperty_ExtendSegments((int)z);
        this->m_84 = *(float*)(this->m_60 + (this->m_7c << 4) + 4);
        return;
    }
    if (this->m_84 >= p2 + this->m_144)
    {
        z = (this->m_84 - (p2 + this->m_144)) / this->m_144;
        this->RemoveFromEnd((int)z);
        this->m_84 = *(float*)(this->m_60 + (this->m_7c << 4) + 4);
    }
}
