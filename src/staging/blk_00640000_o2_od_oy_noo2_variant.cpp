
// src/staging/blk_00640000_o2_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/staging/blk_00640000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00640000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include <stddef.h>
#include "../../include/NiDevImageConverter.h"
#include "../../include/NiPixelFormat.h"
#include "../../include/NiPixelData.h"
#include "../../include/NiTexture.h"
#include "../../include/Setting.h"

extern const NiPixelFormat DAT_011aa2e8;
extern const NiPixelFormat DAT_011aa2a0;
extern int DAT_011a9598;

double FloatFloor(float v);
bool BSShaderManager_GetTintMipMaps();
void BSShaderUtil_TintUncompressedPixelDataByMipMap(void* p);
NiTexture* NiSourceTexture_Create(void* p, int a, void* b);
NiTexture* BSShaderUtil_ConvertTexture(NiTexture* t, void* p);

extern Setting g_011d59ac;

struct NiPtrTex
{
    NiTexture* m_ptr;
    NiPtrTex(void* p);
    ~NiPtrTex();
    NiTexture* Modelloader_GetReferencedThis();
    NiPtrTex& FUN_0066b0d0(NiTexture* t);
    NiPtrTex& FUN_006e5cc0(NiPtrTex& other);
    void FUN_0045cec0();
};

struct FaceGenImageView
{
    float* ForwardCall_0064dbd0();
    FaceGenImageView* CopyPairAfterCallback(FaceGenImageView* a, int b);
    void* m_00;
    void* m_04;
};

struct FaceGenImage
{
    bool ForwardCall_0064db00();
    FaceGenImageView* SetIteratorDataAndOwner(FaceGenImageView* out);
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};






// @fnv 0x0064ceb0
// src: COMMUNITY 0x0064ceb0
NiTexture* NiTexture::BSFaceGenImage_GetCompressedImage(float lo, float hi, float scale, void* srcv)
{
    if (((NiPtrTex*)&m_kName)->Modelloader_GetReferencedThis() == 0 && ((FaceGenImage*)&m_spControllers)->ForwardCall_0064db00() == 0 && (*(int*)&m_pkRendererData) != 0 && (*(int*)&m_pkPrev) != 0 && lo < hi)
    {
        __declspec(align(128)) NiDevImageConverter creator;
        NiPtrTex result(0);
        NiPixelData* pixelData = 0;
        NiTexture* createdTex = 0;
        FaceGenImageView viewStorage;
        FaceGenImageView view = *((FaceGenImage*)&m_spControllers)->SetIteratorDataAndOwner(&viewStorage);
        int count = (*(int*)&m_pkRendererData) * (*(int*)&m_pkPrev);
        unsigned char* cursor = 0;
        float value;
        if (((NiTexture*)srcv)->FUN_00726070() == 0)
        {
            pixelData = new NiPixelData((*(int*)&m_pkRendererData), (*(int*)&m_pkPrev), &DAT_011aa2e8, 1, 1);
            cursor = (unsigned char*)pixelData->NiPixelData_GetPixels(0, 0);
            for (unsigned int i = 0; i < (unsigned int)count; i++)
            {
                value = view.ForwardCall_0064dbd0()[0];
                cursor[0] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                value = view.ForwardCall_0064dbd0()[1];
                cursor[1] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                value = view.ForwardCall_0064dbd0()[2];
                cursor[2] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                cursor += 3;
                FaceGenImageView tmp;
                view.CopyPairAfterCallback(&tmp, 0);
            }
        }
        else
        {
            pixelData = new NiPixelData((*(int*)&m_pkRendererData), (*(int*)&m_pkPrev), &DAT_011aa2a0, 1, 1);
            cursor = (unsigned char*)pixelData->NiPixelData_GetPixels(0, 0);
            for (unsigned int i = 0; i < (unsigned int)count; i++)
            {
                value = view.ForwardCall_0064dbd0()[0];
                cursor[0] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                value = view.ForwardCall_0064dbd0()[1];
                cursor[1] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                value = view.ForwardCall_0064dbd0()[2];
                cursor[2] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                value = view.ForwardCall_0064dbd0()[3];
                cursor[3] = (unsigned char)((FloatFloor(value >= lo ? (value <= hi ? value : hi) : lo) - lo) * scale);

                cursor += 4;
                FaceGenImageView tmp;
                view.CopyPairAfterCallback(&tmp, 0);
            }
        }

        if (g_011d59ac.GetBoolValue())
        {
            createdTex = creator.GenerateMipmaps(pixelData, 0);
            delete pixelData;
            if (BSShaderManager_GetTintMipMaps())
                BSShaderUtil_TintUncompressedPixelDataByMipMap(createdTex);
            result.FUN_0066b0d0(NiSourceTexture_Create(createdTex, 0, &DAT_011a9598));
        }
        else
        {
            if (BSShaderManager_GetTintMipMaps())
                BSShaderUtil_TintUncompressedPixelDataByMipMap(pixelData);
            result.FUN_0066b0d0(NiSourceTexture_Create(pixelData, 0, &DAT_011a9598));
        }

        if (((NiTexture*)srcv)->FUN_00726070() == 1 || ((NiTexture*)srcv)->FUN_00726070() == 0)
        {
            ((NiPtrTex*)&m_kName)->FUN_006e5cc0(result);
        }
        else
        {
            ((NiPtrTex*)&m_kName)->FUN_0066b0d0(BSShaderUtil_ConvertTexture(result.Modelloader_GetReferencedThis(), srcv));
        }

        if (!((NiPtrTex*)&m_kName)->Modelloader_GetReferencedThis())
        {
            ((NiPtrTex*)&m_kName)->FUN_006e5cc0(result);
        }
    }
    return ((NiPtrTex*)&m_kName)->Modelloader_GetReferencedThis();
}
