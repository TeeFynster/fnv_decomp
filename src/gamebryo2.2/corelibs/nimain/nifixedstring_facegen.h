// gamebryo2.2/corelibs/nimain/nifixedstring_facegen.h: declares FaceGenImageView, FaceGenColor and more
#ifndef FNV_NIFIXEDSTRING_FACEGEN_H
#define FNV_NIFIXEDSTRING_FACEGEN_H

#include "../../../../include/NiMemObject.h"
class FaceGenImage;
struct FaceGenImageView
{
    float* pixels;
    unsigned int stride;
    FaceGenImageView();
    float* ForwardCall_0064dbd0();
};
struct FaceGenColor
{
    float r, g, b, a;
};
struct FaceGenModeParameters
{
    int weight;
    unsigned int stride;
};
struct FaceGenChannelData
{
    int scale;
    const signed char* row;
};
struct FaceGenOutputData
{
    float multiplier;
    float* output;
};
class FaceGenImage : public NiMemObject
{
  public:
    unsigned char data[44];
    FaceGenImage(unsigned int);
    FaceGenImage* GetOrConvertImage();
    void ApplyToCopy_Thunk(unsigned int, FaceGenColor*);
    FaceGenImageView _Doraise();
};
struct TextureChannel
{
    unsigned char data[24];
    const signed char* GetElementChecked_0065cc70(unsigned int);
};
struct TextureRow
{
    float scale;
    unsigned int width, height, rowPadding;
    TextureChannel rows[3];
};
struct TextureBasis
{
    unsigned char data[24];
    unsigned int GetPointerSpanCount_0065cea0();
    TextureRow* ProcessEntries_0065cec0(unsigned int);
};
struct FaceGenTextureFile
{
    ~FaceGenTextureFile();
    static void operator delete(void*);
    unsigned int flags;
    TextureBasis basis[2];
};
struct FaceGenCoordinateValue
{
    const float* values;
    unsigned int stride;
    const float* NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt();
};
struct FaceGenCoordinateBasis
{
    unsigned char data[32];
    FaceGenCoordinateValue ForwardCall_0060b370(unsigned int, unsigned int);
};
class BSFaceGenTexture
{
  public:
    BSStringT<char> m_kEGTFileName;
    FaceGenTextureFile* m_pTextureData;
    unsigned int GetCharacterSex();
};
#include "../../../../include/BSFaceGenModel.h"
NiTexture* GetFaceGenManagerValue();
FaceGenTextureFile* BSFaceGenModel_EGTData_Create(const char*);
bool BSFaceGenManager_LoadEGTData(BSFaceGenModel*);
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
int Warning(const char*, ...);
void ReportAssertionViolation(const char*, unsigned int);
extern double DAT_010231d8;
extern float DAT_01065b9c;
extern float DAT_01065b98;
struct NiPoint3StartupTable;
extern NiPoint3StartupTable gNiPoint3StartupSrc;
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
#endif
