
// src/havok/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spheresphere/hkpspheresphereagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl hkpSphereSphereAgent_staticGetPenetrations(void* a, void* b, void* c, void* d);

// @fnv 0x00d3fcc0
// src: HAVOK_SRC 0x00d3fcc0
void __stdcall hkpSphereSphereAgent_getPenetrations(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    hkpSphereSphereAgent_staticGetPenetrations(apArg1, apArg2, apArg3, apArg4);
}

struct S_00d3f660_Owner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Release(unsigned short id, void* arg);
};

struct S_00d3f660
{
    virtual ~S_00d3f660();
    int unk4;
    S_00d3f660_Owner* unk8;
    unsigned short unkC;
    void ReleaseAndDelete(void* arg);
};

// Releases the stored id through unk8 if unkC is not 0xffff, resets unkC to 0xffff, then deletes this.
// @fnv 0x00d3f660
void S_00d3f660::ReleaseAndDelete(void* arg)
{
    if (unkC != 0xffff)
    {
        unk8->Release(unkC, arg);
        unkC = 0xffff;
    }
    delete this;
}
