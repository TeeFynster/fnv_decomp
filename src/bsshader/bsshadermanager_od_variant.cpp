#include "../../include/ImageSpaceTexture.h"

// src/bsshader/bsshadermanager_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshadermanager.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bsshadermanager_decls.h"
#include <stddef.h>
#include "../../include/BSShaderManager.h"
#include "../../include/ImageSpaceManager.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiObject.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/NiTexture.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/ShadowSceneNode.h"
#include "../../include/SkyShaderProperty.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" int __cdecl sprintf_s(char*, size_t, const char*, ...);
extern "C" int __cdecl strcpy_s(char*, size_t, const char*);
extern "C" char* __cdecl strrchr(const char*, int);
extern "C" int __cdecl _strnicmp(const char*, const char*, size_t);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
class NiRTTI;
class NiRenderer;
class BSFileEntry;
class BSFogProperty;
class NiTextureRendererData
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual unsigned int vfn_98();
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_NOT_FOUND = 0
    };
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
};
class TextureFileEntrySetter
{
  public:
    static void SetTexture(NiTexture*, const BSFileEntry*);
};
extern "C" FileFinder* g_fileFinder;
extern "C" bool fnv_NiStreamGetTexture(const char*, NiPointer<NiTexture>&);
NiTexture* CreateSpawnedCubeShell(const NiFixedString&, NiRenderer*, NiTexture::TextureFormatPreferences&);
extern NiRenderer* DAT_011f9508;
extern NiTexture::TextureFormatPreferences DAT_011a9598;
extern NiRTTI DAT_011f444c;
extern const double DAT_01023128, DAT_010ad6d8;
extern float DAT_011adcc8;
extern unsigned int DAT_011f91b8;
extern void (*DAT_011f9f38)(), (*DAT_011f9f3c)();
extern void (*DAT_011f9f40[16])(), (*DAT_011f9f80[16])();
extern unsigned int (*DAT_011f91ec)(NiAVObject*);
extern ShadowSceneNode* DAT_011f91c8[4];
#pragma intrinsic(sin, cos)
// The shipped setter was built without optimization.
#pragma optimize("", off)
#pragma optimize("", on)
void __cdecl BSShaderManager_SetShadowSceneNode(int idx, ShadowSceneNode* p);

extern ImageSpaceManager* DAT_011f91ac;
NiTexture* GetImageSpaceTexture();
extern "C" NiTexture* DAT_011f95ec;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
void __cdecl BSShaderManager_SetAccumulator(NiTexture* pkTexture);
struct PropHelper
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void* vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void* vfn_18();
    void* GetProperty(unsigned int);
    char _pad[0x9C];
    void** m_children;
    unsigned short _pad2;
    unsigned short m_uiItemCount;
};
void __cdecl ProcessPropertyTree(PropHelper*, int);
void __cdecl ProcessPropertyTree(PropHelper* obj, int param2);
BSFogProperty* __cdecl BSShaderManager_GetFogProperty(int aiShadowSceneNode);
void ProcessPropertyTree(NiAVObject*, unsigned int);
void BSShaderManager_SetObjectType(NiAVObject* obj);
struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};
extern float DAT_011f95f4;
extern float DAT_011f95f8;
extern float DAT_011f95fc;
extern float DAT_011f9600;
void __cdecl SetRectCenterAndHalfExtents(tagRECT* apLoadedRect);

struct TGProperty;
struct TGGeometry;
struct TGTextureInfo;

struct TGRTTI
{
    int unk00;
};

struct TGAVObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int IsSceneNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int IsGeometry();
};

struct TGNode : TGAVObject
{
    unsigned int GetArrayCount();
    TGAVObject* GetAt(unsigned int auiIndex);
};

struct TGGeometry : TGAVObject
{
    TGProperty* GetProperty(unsigned int auiType);
};

struct TGTexturingProperty
{
    TGTextureInfo* GetDetailMap(TGGeometry* apGeom, const char* apName, int aiArg, bool abAlpha);
    TGTextureInfo* GetBumpMap(TGGeometry* apGeom, const char* apName, int aiArg, bool abAlpha);
    TGTextureInfo* GetGlowMap(TGGeometry* apGeom, const char* apName, int aiArg, bool abAlpha);
    TGTextureInfo* GetGlossMap(TGGeometry* apGeom, const char* apName, int aiArg, bool abAlpha);
    TGTextureInfo* GetDarkMap(TGGeometry* apGeom, const char* apName, int aiArg, bool abAlpha);
    unsigned int GetDecalMapCount();
    TGTextureInfo* GetDecalMap(unsigned int auiIndex, TGGeometry* apGeom, const char* apName, int aiArg, bool abAlpha);
};

extern TGRTTI g_kTexturingPropertyRTTI;
TGTexturingProperty* __cdecl TGDynamicCast(const TGRTTI* apRTTI, TGProperty* apProperty);

struct TGGatherer
{
    void AddTexture(TGTextureInfo* apInfo);
    void TESDataHandler_CheckTexturesRecurse(TGAVObject* apObject, int aiArg);
};

// @fnv 0x0046e910
// src: COMMUNITY 0x0046e910
void TGGatherer::TESDataHandler_CheckTexturesRecurse(TGAVObject* apObject, int aiArg)
{
    if (apObject)
    {
        if (apObject->IsGeometry())
        {
            TGGeometry* pGeom = (TGGeometry*)apObject;
            TGProperty* pAlpha6 = pGeom->GetProperty(3);
            TGTexturingProperty* pTexProp2 = TGDynamicCast(&g_kTexturingPropertyRTTI, pGeom->GetProperty(5));
            if (pTexProp2)
            {
                AddTexture(pTexProp2->GetDetailMap(pGeom, "Detail Map", aiArg, pAlpha6 != 0));
                AddTexture(pTexProp2->GetBumpMap(pGeom, "Bump Map", aiArg, pAlpha6 != 0));
                AddTexture(pTexProp2->GetGlowMap(pGeom, "Glow Map", aiArg, pAlpha6 != 0));
                AddTexture(pTexProp2->GetGlossMap(pGeom, "Gloss Map", aiArg, pAlpha6 != 0));
                AddTexture(pTexProp2->GetDarkMap(pGeom, "Dark Map", aiArg, pAlpha6 != 0));
                for (unsigned int i = 0; i < pTexProp2->GetDecalMapCount(); i++)
                    AddTexture(pTexProp2->GetDecalMap(i, pGeom, "Decal Map", aiArg, pAlpha6 != 0));
            }
        }
        else if (apObject && apObject->IsSceneNode())
        {
            TGNode* pNode = (TGNode*)apObject;
            unsigned int uiCount5 = pNode->GetArrayCount();
            for (unsigned int j2 = 0; j2 < uiCount5; j2++)
            {
                TGAVObject* pChild2 = pNode->GetAt(j2);
                if (pChild2)
                    TESDataHandler_CheckTexturesRecurse(pChild2, aiArg);
            }
        }
    }
}
