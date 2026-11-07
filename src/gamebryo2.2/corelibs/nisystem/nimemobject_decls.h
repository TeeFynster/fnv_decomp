// gamebryo2.2/corelibs/nisystem/nimemobject_decls.h: declares SNAEntry, NiObjectWords, FixedStringHandle
class Flag512Receiver
{
  public:
    void NiAlphaProperty_SetBit(bool enabled, unsigned int mask);
    void SetFlag512(bool enabled);
};
#include "../../../../include/NiPoint2.h"
class SNAEntry
{
  public:
    static void* operator new[](unsigned int size);
};
extern void* DAT_011f6080;

// Declarations for the constructor/getter span.
// NiObject seen as its two raw words: 0x00a5c200 (an NiObjectNET-style ctor) calls the NiObject ctor 0x00a5d3a0 and then
// stores its own vtable by hand, so the stand-in carries no virtuals.
class NiObjectWords
{
  public:
    unsigned int words[2];
    NiObjectWords();
};
// Raw NiFixedString handle: 0x00a5c200 copies EmptyFS (0x0109b220) without touching its refcount.
class FixedStringHandle
{
  public:
    const char* value;
};
extern FixedStringHandle EmptyFS;
extern unsigned char DAT_0109b244[];
extern unsigned char DAT_011f4304[];
