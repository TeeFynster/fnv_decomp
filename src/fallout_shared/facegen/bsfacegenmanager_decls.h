// fallout_shared/facegen/bsfacegenmanager_decls.h: supporting declarations for bsfacegenmanager_ob1_variant.cpp

extern BSFaceGenManager* DAT_011d59e8;
void BSFaceGenManager_InitializeSystem();
extern "C" void* memset(void*, int, unsigned int);
#include "../../../include/TESRace.h"
#include "../../../include/ENUM_FORM_ID.h"
#include "../../../include/SEX.h"
#include "../../../include/TESActorBase.h"
class FaceGenCoordArray
{
  public:
    char data[0x20];
    void resize(unsigned int, bool);
};
extern "C" char* __insecure_strcpy(char*, const char*);
char* FUN_00ec6380(char*, const char*);
extern const char* DAT_0119b734[2];
extern float DAT_01016970;
#include "../../../include/NiPointer.h"
class NiTexture;
class FaceGenPaletteBase
{
  public:
    char pad[0x2c];
    ~FaceGenPaletteBase();
};
class FaceGenPaletteEntry : public FaceGenPaletteBase
{
  public:
    NiPointer<NiTexture> first, second;
    ~FaceGenPaletteEntry();
};

extern const char DAT_0104aad0[];
