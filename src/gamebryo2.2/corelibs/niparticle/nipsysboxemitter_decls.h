
#include "../../../../include/NiColorA.h"
extern NiColorA DAT_011a9be0;
class NiPSysPositionModifier
{
  public:
    NiPSysPositionModifier();
    virtual void LoadBinary(class NiStream&);
    unsigned char modifier[0x14];
};
class NiPSysEmitter : public NiPSysPositionModifier
{
  public:
    NiPSysEmitter();
    virtual void LoadBinary(class NiStream&);
    float speed, speedVar, declination, declinationVar, planarAngle, planarAngleVar;
    NiColorA color;
    float radius, radiusVar, lifespan, lifespanVar, unknown;
};
class NiPSysVolumeEmitter : public NiPSysEmitter
{
  public:
    virtual void LoadBinary(class NiStream&);
    void* emitterObject;
};
class NiPSysBoxEmitter : public NiPSysVolumeEmitter
{
  public:
    virtual void LoadBinary(class NiStream&);
    float width, height, depth;
};
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadFloat(float& value)
    {
        unsigned int size = 4;
        position += read(this, &value, 4, &size, 1);
    }
};
class NiStream
{
  public:
    unsigned char data[0x24c];
    NiBinaryStream* input;
};
