// gamebryo2.2/corelibs/nimain/niscreenloddata_decls.h: local transform and screen-object views

// LocalNiTransform: include/NiTransform.h declares an out-of-line default constructor; 0x00a86530 and 0x00a95fb0
// construct their NiTransform locals without calling one. Passed to NiBound as the shared NiTransform.
class NiTransform;
class LocalNiTransform
{
  public:
    float rotation[9];
    NiPoint3 translation;
    float scale;
    void InvertTransform(LocalNiTransform& result) const;
    LocalNiTransform operator*(const LocalNiTransform& other) const;
};
struct ScreenBone
{
    LocalNiTransform transform;
    NiBound bound;
    char extra[8];
};
struct ScreenData
{
    char pad[12];
    LocalNiTransform transform;
    ScreenBone* bones;
    unsigned int count;
};
struct ScreenObject
{
    char pad[104];
    LocalNiTransform world;
};
