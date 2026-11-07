// fallout/misc/saveload/bgschangeflags_decls.h: declares LocalFormChangeMask (unit-local FormChangeMask), FormChangeRecord, BGSChangeFlagsState

// Shared FormChangeMask declares a copy constructor; using it makes 0x00841120
// call that constructor instead of copying the result directly (102 bytes vs 98).
// LocalFormChangeMask: unit-local FormChangeMask without the shared header's copy constructor: 0x00841120 HasFormChanged returns its by-value mask with a bitwise store,
// where the shared form (copy-constructed arguments, e.g. 0x005f1590) would call one
class LocalFormChangeMask
{
  public:
    unsigned int flags;
    unsigned int Modelloader_GetReferencedThis();
    static LocalFormChangeMask HasFormChanged(LocalFormChangeMask changes, LocalFormChangeMask forced, int type, bool enabled);
};
class FormChangeRecord
{
  public:
    unsigned int flags;
    bool FUN_00562210(unsigned int mask);
};
class BGSChangeFlagsState
{
  public:
    unsigned char padding[0x28];
    unsigned int flags;
    void CombineFlags(bool enabled);
};
