// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollideclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollideclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void FUN_00e36b80();
void* hkMemoryRouter_getInstance();

class PCls
{
  public:
    virtual void PV0();
    virtual void PV1();
    virtual void PV2(void* a1, unsigned int a2);
};

class SELF
{
  public:
    int pad;
    unsigned short w;
    SELF* FUN_00dfbd80(unsigned char flag);
};

// Calls FUN_00e36b80, and if bit 0 of flag is set, calls PV2 on the object at offset 0x10 of FUN_00c85750's result with this and w, then returns this.
// @fnv 0x00dfbd80
SELF* SELF::FUN_00dfbd80(unsigned char flag)
{
    FUN_00e36b80();
    if (flag & 1)
    {
        void* gp = hkMemoryRouter_getInstance();
        (*(PCls**)((char*)gp + 0x10))->PV2(this, (unsigned int)w);
    }
    return this;
}
