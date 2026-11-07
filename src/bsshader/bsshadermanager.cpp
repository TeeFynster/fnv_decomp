#include "../../include/ImageSpaceTexture.h"
// bsshader/bsshadermanager.cpp: BSShaderManager, NiFixedString, SkyShaderProperty, StringHashMapBase (31 functions)

#include "bsshadermanager_decls.h"
#include <stddef.h>
#include "../../include/NiPointer.h"
#include "../../include/BSFadeNode.h"
#include "../../include/NiPoint2.h"
#include "../../include/NP.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiObject.h"
#include "../../include/NiBinaryExtraData.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiSourceTexture.h"
#include "../../include/NiTexture.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiTriBasedGeomData.h"
#include "../../include/NiTriBasedGeom.h"
#include "../../include/ShadowSceneNode.h"
#include "../../include/BSShaderManager.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiFile.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiStream.h"
#include "../../include/NiColorA.h"
#include "../../include/ImageSpaceManager.h"

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

inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)))
        DeleteThis();
}
inline void NiTexture::DecRefCount()
{
    NiRefObject::DecRefCount();
}
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
#include "../../include/SkyShaderProperty.h"

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

// Stores mode in DAT_011f91b8 and sets DAT_011f9f3c and DAT_011f9f38 from the per-mode tables, falling back to index 0 when an entry is null.
// @fnv 0x00b4f450
void BSShaderManager::SetRenderMode(unsigned int mode)
{
    DAT_011f91b8 = mode;
    DAT_011f9f3c = DAT_011f9f80[mode];
    if (!DAT_011f9f3c)
        DAT_011f9f3c = DAT_011f9f80[0];
    DAT_011f9f38 = DAT_011f9f40[mode];
    if (!DAT_011f9f38)
        DAT_011f9f38 = DAT_011f9f40[0];
}

// @fnv 0x00b4f4a0
char* BSShaderManager::GetRenderModeName()
{
    switch (fnv_particle_shader_renderer_level)
    {
    case 0:
        return "BSSM_SV_NONE";
    case 1:
        return "BSSM_SV_1_X";
    case 2:
        return "BSSM_SV_2_0";
    case 3:
        return "BSSM_SV_2_A96";
    case 4:
        return "BSSM_SV_2_B96";
    case 5:
        return "BSSM_SV_2_A";
    case 6:
        return "BSSM_SV_2_B";
    case 7:
        return "BSSM_SV_3_0";
    default:
        return "???";
    }
}

// @fnv 0x00b4f5e0
void BSShaderManager::BuildTexturePath(char* acOutPath, const char* acInputPath, const char* suffix,
                                       bool abAddDataPrefix)
{
    char filename[260];
    char extension[10];
    strcpy_s(filename, 260, acInputPath);
    acOutPath[0] = 0;
    char* dot = strrchr(filename, '.');
    char* pcSlash = strrchr(filename, '\\');
    char* pcUnderscore = strrchr(filename, '_');
    if (pcSlash && pcUnderscore && pcUnderscore < pcSlash)
        pcUnderscore = 0;
    if (dot)
    {
        strcpy_s(extension, 10, dot);
        if (pcUnderscore)
            *pcUnderscore = 0;
        *dot = 0;
        if (abAddDataPrefix && filename[0] != '\\' && filename[1] != ':' && _strnicmp(filename, "data", 4))
            sprintf_s(acOutPath, 260, "Data\\%s%s%s", filename, suffix, extension);
        else
            sprintf_s(acOutPath, 260, "%s%s%s", filename, suffix, extension);
    }
}

// @fnv 0x00b54000
void BSShaderManager::SetFOV(float angle)
{
    angle = static_cast<float>(angle * 0.5 * DAT_01023128);
    float sine = static_cast<float>(sin(angle));
    float tangent = sine / static_cast<float>(cos(angle));
    float referenceSine = static_cast<float>(sin(DAT_010ad6d8));
    DAT_011adcc8 = tangent / (referenceSine / static_cast<float>(cos(DAT_010ad6d8)));
}

// @fnv 0x00b55540
void BSShaderManager::SetFogPropertyForIndex(int index, BSFogProperty* fog)
{
    DAT_011f91c8[index]->SetFogPropertyForIndex(fog);
}

// @fnv 0x00b55840
void BSShaderManager::GetTexture(const char* filename, bool load, NiPointer<NiTexture>& texture, bool checkMipmaps,
                                 bool cube)
{
    if (filename)
    {
        fnv_NiStreamGetTexture(filename, texture);
        if (!load)
            return;
        if (!texture.m_pObject && g_fileFinder && g_fileFinder->GetFileLocation(const_cast<char*>(filename), 0, 6, 2))
        {
            if (cube)
                texture = CreateSpawnedCubeShell(NiFixedString(filename), DAT_011f9508, DAT_011a9598);
            else
                texture = NiSourceTexture::Create(NiFixedString(filename), DAT_011a9598, true, false);
            if (texture.m_pObject)
                TextureFileEntrySetter::SetTexture(texture.m_pObject, 0);
        }
        if (checkMipmaps && texture.m_pObject)
        {
            NiSourceTexture* source = static_cast<NiSourceTexture*>(texture.m_pObject->DynamicCast(&DAT_011f444c));
            NiTextureRendererData* data = reinterpret_cast<NiTextureRendererData*>(texture.m_pObject->m_pkRendererData);
            if (data && data->vfn_98() <= 1)
            {
                char message[500];
                if (source)
                    sprintf_s(message, 500, "TEXTURES: texture does not contain mipmaps & will not be used : %s",
                              source->m_kPlatformFilename.m_kHandle);
                else
                    sprintf_s(message, 500,
                              "TEXTURES: texture does not contain mipmaps & will not be used : NOTASOURCETEXTURE");
                goto clearTexture;
            }
        }
    }
    else
        goto clearTexture;
    return;
clearTexture:
    if (texture.m_pObject)
    {
        texture.m_pObject->DecRefCount();
        texture.m_pObject = 0;
    }
}

// @fnv 0x00b57e30
void BSShaderManager::UpdateObjectTypeRecurse(NiAVObject* object, bool dynamic, bool skipRenderer)
{
    object->UpdateSceneObject();
    eObjectType type = BSSM_OBJ_UNITIALIZED;
    if (DAT_011f91ec)
        type = static_cast<eObjectType>(DAT_011f91ec(object));
    SetObjectTypeRecursively(object, type, dynamic, skipRenderer);
}

// The shipped setter was built without optimization.
#pragma optimize("", off)
// @fnv 0x006348e0
void SkyShaderProperty::SetTexture(NiTexture* texture)
{
    m_spTexture = texture;
}
#pragma optimize("", on)

// @fnv 0x00b4f2f0
// src: XBOX_PDB 0x00b4f2f0
void __cdecl BSShaderManager_SetShadowSceneNode(int aiIndex, ShadowSceneNode* apNode)
{
    DAT_011f91c8[aiIndex] = apNode;
}



extern MemoryManager _g_memoryManager;
inline void* ImageSpaceManager::operator new(size_t size)
{
    return _g_memoryManager.Allocate(size);
}
inline void ImageSpaceManager::operator delete(void* data)
{
    _g_memoryManager.Deallocate(data);
}

extern ImageSpaceManager* DAT_011f91ac;

// @fnv 0x00b54090
NiTexture* GetImageSpaceTexture()
{
    return reinterpret_cast<ImageSpaceTexture*>(DAT_011f91ac->DepthTexture)->GetTexture();
}

extern "C" NiTexture* DAT_011f95ec;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

// Replaces the global NiTexture pointer with pkTexture, releasing the previous texture and incrementing the new one's reference count.
// @fnv 0x00b54ac0
// src: COMMUNITY 0x00b54ac0
void __cdecl BSShaderManager_SetAccumulator(NiTexture* pkTexture)
{
    if (DAT_011f95ec != pkTexture)
    {
        if (DAT_011f95ec)
            DAT_011f95ec->DecRefCount();

        DAT_011f95ec = pkTexture;

        if (DAT_011f95ec)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&DAT_011f95ec->m_uiRefCount));
    }
}

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

// @fnv 0x00b55360
void __cdecl ProcessPropertyTree(PropHelper* pProp, int param2)
{
    if (!pProp)
        return;
    if (pProp->vfn_18())
    {
        pProp->GetProperty(3);
        return;
    }
    if (!pProp->vfn_c())
        return;
    for (unsigned int i = 0; i < (unsigned int)pProp->m_uiItemCount; i++)
    {
        PropHelper* child = (PropHelper*)pProp->m_children[i];
        if (child)
            ProcessPropertyTree(child, param2);
    }
}

// @fnv 0x00b55520
// src: XBOX_PDB 0x00b55520
BSFogProperty* __cdecl BSShaderManager_GetFogProperty(int aiShadowSceneNode)
{
    return *(BSFogProperty**)((char*)DAT_011f91c8[aiShadowSceneNode] + 0x134);
}

void ProcessPropertyTree(NiAVObject*, unsigned int);

// If obj is non-null, calls DAT_011f91ec to get a value (0 if unset) and passes obj and that value to ProcessPropertyTree.
// @fnv 0x00b55b80
// src: COMMUNITY 0x00b55b80
void BSShaderManager_SetObjectType(NiAVObject* apObject)
{
    if (apObject)
    {
        unsigned int result = 0;
        if (DAT_011f91ec)
            result = DAT_011f91ec(apObject);
        ProcessPropertyTree(apObject, result);
    }
}

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

// Computes half width/height from apLoadedRect and stores the rect center and half extents into four globals.
// @fnv 0x00b4f300
void __cdecl SetRectCenterAndHalfExtents(tagRECT* apLoadedRect)
{
    int lhalfHeight;
    int lhalfWidth;
    lhalfWidth = (apLoadedRect->right - apLoadedRect->left) / 2;
    lhalfHeight = (apLoadedRect->top - apLoadedRect->bottom) / 2;
    DAT_011f95f4 = apLoadedRect->left + (float)lhalfWidth;
    DAT_011f95f8 = apLoadedRect->bottom + (float)lhalfHeight;
    DAT_011f95fc = (float)lhalfWidth;
    DAT_011f9600 = (float)lhalfHeight;
}

NiObject* __cdecl FUN_00b60f50();
NiObject* __cdecl CreateNewObj();
NiObject* __cdecl CreateB6AE60Obj();
NiObject* __cdecl CreateShaderLightingProperty();
NiObject* __cdecl CreateBlobObj();
NiObject* __cdecl BSShaderTextureSet_CreateObject();
NiObject* __cdecl BSShaderProperty_CreateObject();
NiObject* __cdecl CreateSpawnedObject90();
NiObject* __cdecl CreateObjectDerived();
NiObject* __cdecl CreateInstance();
NiObject* __cdecl TileShaderProperty_CreateObject();
NiObject* __cdecl BSOrderedNode_CreateObject();
NiObject* __cdecl BSMaterialEmittanceMultController_CreateObject();
NiObject* __cdecl CreateDerived();
NiObject* __cdecl CreateInterpDerivedBc36();
NiObject* __cdecl VolumetricFogShaderProperty_CreateObject();
NiObject* __cdecl CreateSpawnedObj9441();
NiObject* __cdecl CreateShaderAccumulator();
extern const char g_011f9140_arg0[];
extern const char g_011f9f00_arg0[];
extern const char g_011fa010_arg0[];
extern const char g_011fa018_arg0[];
extern const char g_011fa05c_arg0[];
extern const char g_011fa560_arg0[];
extern const char g_0120044c_arg0[];
extern const char g_01200464_arg0[];
extern const char g_012005b8_arg0[];
extern const char g_012007b0_arg0[];
extern const char g_012007c8_arg0[];
extern const char g_012007d8_arg0[];
extern const char g_01201f84_arg0[];
extern const char g_01201f90_arg0[];
extern const char g_01201f9c_arg0[];
extern const char g_01201fa8_arg0[];
extern const char g_01201fb0_arg0[];
extern const char g_01201fb8_arg0[];
extern const char g_01204378_arg0[];

// Registers a series of NiStream factory callbacks, each paired with a class-name string, including BSFadeNode::CreateObject.
// @fnv 0x00b4f1a0
void RegisterNiStreamFactories()
{
    NiStream::RegisterObjectLoader(g_01200464_arg0, BSShaderProperty_CreateObject);
    NiStream::RegisterObjectLoader(g_011fa560_arg0, CreateBlobObj);
    NiStream::RegisterObjectLoader(g_011fa010_arg0, CreateNewObj);
    NiStream::RegisterObjectLoader(g_012007b0_arg0, CreateObjectDerived);
    NiStream::RegisterObjectLoader(g_01201fb8_arg0, CreateSpawnedObj9441);
    NiStream::RegisterObjectLoader("NoFaderShaderProperty", CreateObjectDerived);
    NiStream::RegisterObjectLoader(g_011fa018_arg0, CreateB6AE60Obj);
    NiStream::RegisterObjectLoader(g_011fa05c_arg0, CreateShaderLightingProperty);
    NiStream::RegisterObjectLoader(g_01201fb0_arg0, VolumetricFogShaderProperty_CreateObject);
    NiStream::RegisterObjectLoader(g_012005b8_arg0, CreateSpawnedObject90);
    NiStream::RegisterObjectLoader(g_011f9f00_arg0, FUN_00b60f50);
    NiStream::RegisterObjectLoader(g_01204378_arg0, CreateShaderAccumulator);
    NiStream::RegisterObjectLoader(g_0120044c_arg0, BSShaderTextureSet_CreateObject);
    NiStream::RegisterObjectLoader(g_01201fa8_arg0, CreateInterpDerivedBc36);
    NiStream::RegisterObjectLoader(g_01201f9c_arg0, CreateDerived);
    NiStream::RegisterObjectLoader(g_012007d8_arg0, TileShaderProperty_CreateObject);
    NiStream::RegisterObjectLoader(g_01201f90_arg0, BSMaterialEmittanceMultController_CreateObject);
    NiStream::RegisterObjectLoader(g_011f9140_arg0, BSFadeNode::CreateObject);
    NiStream::RegisterObjectLoader(g_01201f84_arg0, BSOrderedNode_CreateObject);
    NiStream::RegisterObjectLoader(g_012007c8_arg0, CreateInstance);
}

class B4F9A0Shader
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void ClearCachedState();
};

class B4F9A0ShaderManager
{
  public:
    static B4F9A0Shader* ms_apShaders[35];

    static void ClearAllCachedStates();
};

// Iterates the 35 shader slots and calls ClearCachedState on each non-null shader.
// @fnv 0x00b4f9a0
void B4F9A0ShaderManager::ClearAllCachedStates()
{
    for (int i = 0; i < 35; i++)
    {
        if (ms_apShaders[i])
            ms_apShaders[i]->ClearCachedState();
    }
}

int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);

// @fnv 0x00b4f9d0
// src: XBOX_PDB 0x00b4f9d0
const char* BSShaderManager_GetPassName(int aiShader)
{
    switch (aiShader)
    {
    case 1:
        return "BSSM_ZONLY";
    case 2:
        return "BSSM_ZONLY_At";
    case 3:
        return "BSSM_ZONLY_S";
    case 4:
        return "BSSM_ZONLY_TEXEFFECT";
    case 5:
        return "BSSM_ZONLY_TEXEFFECT_S";
    case 6:
        return "BSSM_CONSTALPHA";
    case 7:
        return "BSSM_CONSTALPHA_At";
    case 8:
        return "BSSM_CONSTALPHA_S";
    case 9:
        return "BSSM_AMBIENT_OCCLUSION";
    case 16:
        return "BSSM_DEPTHMAP";
    case 17:
        return "BSSM_DEPTHMAP_At";
    case 18:
        return "BSSM_DEPTHMAP_S";
    case 19:
        return "BSSM_DEPTHMAP_SAt";
    case 487:
        return "BSSM_DEPTH";
    case 488:
        return "BSSM_DEPTH_S";
    case 489:
        return "BSSM_DEPTH_Mn";
    case 604:
        return "BSSM_GRASS_DIRONLY_LF";
    case 605:
        return "BSSM_GRASS_DIRONLY_LV";
    case 606:
        return "BSSM_GRASS_DIRONLY_LFS";
    case 607:
        return "BSSM_GRASS_DIRONLY_LVS";
    case 608:
        return "BSSM_GRASS_DIRONLY_LFP";
    case 609:
        return "BSSM_GRASS_DIRONLY_LVP";
    case 610:
        return "BSSM_GRASS_DIRONLY_LFSP";
    case 611:
        return "BSSM_GRASS_DIRONLY_LVSP";
    case 612:
        return "BSSM_GRASS_DIRONLY_LFShp";
    case 613:
        return "BSSM_GRASS_DIRONLY_LVShp";
    case 614:
        return "BSSM_GRASS_DIRONLY_LFSShp";
    case 615:
        return "BSSM_GRASS_DIRONLY_LVSShp";
    case 616:
        return "BSSM_GRASS_DIRONLY_LFPShp";
    case 617:
        return "BSSM_GRASS_DIRONLY_LVPShp";
    case 618:
        return "BSSM_GRASS_DIRONLY_LFSPShp";
    case 619:
        return "BSSM_GRASS_DIRONLY_LVSPShp";
    case 620:
        return "BSSM_GRASS_DIRONLY_LFB";
    case 621:
        return "BSSM_GRASS_DIRONLY_LFSB";
    case 622:
        return "BSSM_GRASS_DIRONLY_LFPB";
    case 623:
        return "BSSM_GRASS_DIRONLY_LFSPB";
    case 624:
        return "BSSM_GRASS_1POINT_LF";
    case 625:
        return "BSSM_GRASS_1POINT_LV";
    case 626:
        return "BSSM_GRASS_1POINT_LFS";
    case 627:
        return "BSSM_GRASS_1POINT_LVS";
    case 628:
        return "BSSM_GRASS_1POINT_LFP";
    case 629:
        return "BSSM_GRASS_1POINT_LVP";
    case 630:
        return "BSSM_GRASS_1POINT_LFSP";
    case 631:
        return "BSSM_GRASS_1POINT_LVSP";
    case 632:
        return "BSSM_GRASS_1POINT_LFShp";
    case 633:
        return "BSSM_GRASS_1POINT_LVShp";
    case 634:
        return "BSSM_GRASS_1POINT_LFSShp";
    case 635:
        return "BSSM_GRASS_1POINT_LVSShp";
    case 636:
        return "BSSM_GRASS_1POINT_LFPShp";
    case 637:
        return "BSSM_GRASS_1POINT_LVPShp";
    case 638:
        return "BSSM_GRASS_1POINT_LFSPShp";
    case 639:
        return "BSSM_GRASS_1POINT_LVSPShp";
    case 640:
        return "BSSM_GRASS_1POINT_LFB";
    case 641:
        return "BSSM_GRASS_1POINT_LFSB";
    case 642:
        return "BSSM_GRASS_1POINT_LFPB";
    case 643:
        return "BSSM_GRASS_1POINT_LFSPB";
    case 644:
        return "BSSM_GRASS_SHADOW_L";
    case 645:
        return "BSSM_GRASS_SHADOW_LS";
    case 646:
        return "BSSM_GRASS_SHADOW_LB";
    case 647:
        return "BSSM_GRASS_SHADOW_LSB";
    case 22:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LF";
    case 23:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LV";
    case 24:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFS";
    case 25:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVS";
    case 26:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFP";
    case 27:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVP";
    case 28:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFSP";
    case 29:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVSP";
    case 30:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFShp";
    case 31:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVShp";
    case 32:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFSShp";
    case 33:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVSShp";
    case 34:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFPShp";
    case 35:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVPShp";
    case 36:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFSPShp";
    case 37:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LVSPShp";
    case 38:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFB";
    case 39:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFSB";
    case 40:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFPB";
    case 41:
        return "BSSM_GRASS_NOALPHA_DIRONLY_LFSPB";
    case 42:
        return "BSSM_GRASS_NOALPHA_1POINT_LF";
    case 43:
        return "BSSM_GRASS_NOALPHA_1POINT_LV";
    case 44:
        return "BSSM_GRASS_NOALPHA_1POINT_LFS";
    case 45:
        return "BSSM_GRASS_NOALPHA_1POINT_LVS";
    case 46:
        return "BSSM_GRASS_NOALPHA_1POINT_LFP";
    case 47:
        return "BSSM_GRASS_NOALPHA_1POINT_LVP";
    case 48:
        return "BSSM_GRASS_NOALPHA_1POINT_LFSP";
    case 49:
        return "BSSM_GRASS_NOALPHA_1POINT_LVSP";
    case 50:
        return "BSSM_GRASS_NOALPHA_1POINT_LFShp";
    case 51:
        return "BSSM_GRASS_NOALPHA_1POINT_LVShp";
    case 52:
        return "BSSM_GRASS_NOALPHA_1POINT_LFSShp";
    case 53:
        return "BSSM_GRASS_NOALPHA_1POINT_LVSShp";
    case 54:
        return "BSSM_GRASS_NOALPHA_1POINT_LFPShp";
    case 55:
        return "BSSM_GRASS_NOALPHA_1POINT_LVPShp";
    case 56:
        return "BSSM_GRASS_NOALPHA_1POINT_LFSPShp";
    case 57:
        return "BSSM_GRASS_NOALPHA_1POINT_LVSPShp";
    case 58:
        return "BSSM_GRASS_NOALPHA_1POINT_LFB";
    case 59:
        return "BSSM_GRASS_NOALPHA_1POINT_LFSB";
    case 60:
        return "BSSM_GRASS_NOALPHA_1POINT_LFPB";
    case 61:
        return "BSSM_GRASS_NOALPHA_1POINT_LFSPB";
    case 62:
        return "BSSM_LEAVES_AD";
    case 63:
        return "BSSM_LEAVES_ADPt";
    case 64:
        return "BSSM_FRONDS";
    case 65:
        return "BSSM_PARTICLE_PREPASS";
    case 66:
        return "BSSM_NOLIGHTING";
    case 67:
        return "BSSM_NOLIGHTING_VC";
    case 68:
        return "BSSM_NOLIGHTING_TexVC";
    case 69:
        return "BSSM_NOLIGHTING_MAT";
    case 74:
        return "BSSM_NOLIGHTING_FALLOFF";
    case 75:
        return "BSSM_NOLIGHTING_VC_FALLOFF";
    case 76:
        return "BSSM_NOLIGHTING_TexVC_FALLOFF";
    case 77:
        return "BSSM_NOLIGHTING_MAT_FALLOFF";
    case 70:
        return "BSSM_NOLIGHTING_S";
    case 71:
        return "BSSM_NOLIGHTING_VC_S";
    case 72:
        return "BSSM_NOLIGHTING_TexVC_S";
    case 73:
        return "BSSM_NOLIGHTING_MAT_S";
    case 78:
        return "BSSM_NOLIGHTING_FALLOFF_S";
    case 79:
        return "BSSM_NOLIGHTING_VC_FALLOFF_S";
    case 80:
        return "BSSM_NOLIGHTING_TexVC_FALLOFF_S";
    case 81:
        return "BSSM_NOLIGHTING_MAT_FALLOFF_S";
    case 82:
        return "BSSM_NOLIGHTING_PSYS";
    case 83:
        return "BSSM_NOLIGHTING_PSYS_SUBTEX_OFFSET";
    case 84:
        return "BSSM_NOLIGHTING_PSYS_PREMULT_ALPHA";
    case 85:
        return "BSSM_NOLIGHTING_PSYS_SUBTEX_OFFSET_PREMULT_ALPHA";
    case 86:
        return "BSSM_NOLIGHTING_STRIP_PSYS";
    case 87:
        return "BSSM_NOLIGHTING_STRIP_PSYS_SUBTEX";
    case 88:
        return "BSSM_AMBIENT";
    case 89:
        return "BSSM_AMBIENT_G";
    case 90:
        return "BSSM_AMBIENT_At";
    case 91:
        return "BSSM_AMBIENT_GAt";
    case 92:
        return "BSSM_AMBIENT_S";
    case 93:
        return "BSSM_AMBIENT_SG";
    case 94:
        return "BSSM_AMBIENT_SAt";
    case 95:
        return "BSSM_AMBIENT_SGAt";
    case 96:
        return "BSSM_AMBIENT_Sb";
    case 97:
        return "BSSM_AMBIENT_Mn";
    case 98:
        return "BSSM_AMBIENT_F";
    case 99:
        return "BSSM_AMBIENT_FAt";
    case 100:
        return "BSSM_AMBDIFFTEX";
    case 101:
        return "BSSM_AMBDIFFTEX_Vc";
    case 127:
        return "BSSM_AMBDIFFTEX_F";
    case 128:
        return "BSSM_AMBDIFFTEX_FVc";
    case 102:
        return "BSSM_AMBDIFFTEX_G";
    case 103:
        return "BSSM_AMBDIFFTEX_GVc";
    case 129:
        return "BSSM_AMBDIFFTEX_FG";
    case 130:
        return "BSSM_AMBDIFFTEX_FGVc";
    case 104:
        return "BSSM_AMBDIFFTEX_Fg";
    case 105:
        return "BSSM_AMBDIFFTEX_A";
    case 106:
        return "BSSM_AMBDIFFTEX_AVc";
    case 131:
        return "BSSM_AMBDIFFTEX_FA";
    case 132:
        return "BSSM_AMBDIFFTEX_FAVc";
    case 107:
        return "BSSM_AMBDIFFTEX_GA";
    case 108:
        return "BSSM_AMBDIFFTEX_GAVc";
    case 109:
        return "BSSM_AMBDIFFTEX_FgA";
    case 133:
        return "BSSM_AMBDIFFTEX_FFg";
    case 134:
        return "BSSM_AMBDIFFTEX_FGA";
    case 135:
        return "BSSM_AMBDIFFTEX_FGAVc";
    case 110:
        return "BSSM_AMBDIFFTEX_GFgA";
    case 136:
        return "BSSM_AMBDIFFTEX_FGFgA";
    case 111:
        return "BSSM_AMBDIFFTEX_S";
    case 112:
        return "BSSM_AMBDIFFTEX_SVc";
    case 137:
        return "BSSM_AMBDIFFTEX_SF";
    case 138:
        return "BSSM_AMBDIFFTEX_SFVc";
    case 113:
        return "BSSM_AMBDIFFTEX_SG";
    case 114:
        return "BSSM_AMBDIFFTEX_SGVc";
    case 139:
        return "BSSM_AMBDIFFTEX_SFG";
    case 140:
        return "BSSM_AMBDIFFTEX_SFGVc";
    case 115:
        return "BSSM_AMBDIFFTEX_SFg";
    case 143:
        return "BSSM_AMBDIFFTEX_SFFg";
    case 116:
        return "BSSM_AMBDIFFTEX_SA";
    case 117:
        return "BSSM_AMBDIFFTEX_SAVc";
    case 141:
        return "BSSM_AMBDIFFTEX_SFA";
    case 142:
        return "BSSM_AMBDIFFTEX_SFAVc";
    case 118:
        return "BSSM_AMBDIFFTEX_SGA";
    case 119:
        return "BSSM_AMBDIFFTEX_SGAVc";
    case 120:
        return "BSSM_AMBDIFFTEX_SFgA";
    case 144:
        return "BSSM_AMBDIFFTEX_SFGA";
    case 145:
        return "BSSM_AMBDIFFTEX_SFGAVc";
    case 121:
        return "BSSM_AMBDIFFTEX_SGFgA";
    case 146:
        return "BSSM_AMBDIFFTEX_SFGFgA";
    case 122:
        return "BSSM_AMBDIFFTEX_Sb";
    case 123:
        return "BSSM_AMBDIFFTEX_SbF";
    case 124:
        return "BSSM_AMBDIFFDIRANDPT";
    case 125:
        return "BSSM_AMBDIFFDIRANDPT_S";
    case 126:
        return "BSSM_AMBDIFFDIRANDPT_Sb";
    case 147:
        return "BSSM_LANDAD";
    case 215:
        return "BSSM_AD2";
    case 216:
        return "BSSM_AD2_G";
    case 217:
        return "BSSM_AD2_Px";
    case 218:
        return "BSSM_AD2_GPx";
    case 219:
        return "BSSM_AD2_Fg";
    case 220:
        return "BSSM_AD2_S";
    case 221:
        return "BSSM_AD2_SG";
    case 222:
        return "BSSM_AD2_SFg";
    case 223:
        return "BSSM_AD2_Sb";
    case 224:
        return "BSSM_AD2_Shp";
    case 225:
        return "BSSM_AD2_GShp";
    case 226:
        return "BSSM_AD2_PxShp";
    case 227:
        return "BSSM_AD2_GPxShp";
    case 228:
        return "BSSM_AD2_FgShp";
    case 229:
        return "BSSM_AD2_SShp";
    case 230:
        return "BSSM_AD2_SGShp";
    case 231:
        return "BSSM_AD2_SFgShp";
    case 232:
        return "BSSM_AD2_SbShp";
    case 233:
        return "BSSM_AD3";
    case 234:
        return "BSSM_AD3_G";
    case 235:
        return "BSSM_AD3_Px";
    case 236:
        return "BSSM_AD3_GPx";
    case 237:
        return "BSSM_AD3_Fg";
    case 238:
        return "BSSM_AD3_S";
    case 239:
        return "BSSM_AD3_SG";
    case 240:
        return "BSSM_AD3_SFg";
    case 241:
        return "BSSM_AD3_Sb";
    case 242:
        return "BSSM_AD3_Shp";
    case 243:
        return "BSSM_AD3_GShp";
    case 244:
        return "BSSM_AD3_PxShp";
    case 245:
        return "BSSM_AD3_GPxShp";
    case 246:
        return "BSSM_AD3_FgShp";
    case 247:
        return "BSSM_AD3_SShp";
    case 248:
        return "BSSM_AD3_SGShp";
    case 249:
        return "BSSM_AD3_SFgShp";
    case 250:
        return "BSSM_AD3_SbShp";
    case 251:
        return "BSSM_ADT";
    case 252:
        return "BSSM_ADT_Opt";
    case 253:
        return "BSSM_ADT_OptLOD";
    case 254:
        return "BSSM_ADT_Mn";
    case 255:
        return "BSSM_ADT_G";
    case 256:
        return "BSSM_ADT_Fg";
    case 257:
        return "BSSM_ADT_Px";
    case 258:
        return "BSSM_ADT_PxOpt";
    case 259:
        return "BSSM_ADT_GPx";
    case 260:
        return "BSSM_ADT_H";
    case 261:
        return "BSSM_ADT_S";
    case 262:
        return "BSSM_ADT_SG";
    case 263:
        return "BSSM_ADT_SFg";
    case 264:
        return "BSSM_ADT_Sb";
    case 265:
        return "BSSM_ADT_SH";
    case 266:
        return "BSSM_ADT_Shp";
    case 267:
        return "BSSM_ADT_MnShp";
    case 268:
        return "BSSM_ADT_GShp";
    case 269:
        return "BSSM_ADT_FgShp";
    case 270:
        return "BSSM_ADT_PxShp";
    case 271:
        return "BSSM_ADT_GPxShp";
    case 272:
        return "BSSM_ADT_HShp";
    case 273:
        return "BSSM_ADT_SShp";
    case 274:
        return "BSSM_ADT_SGShp";
    case 275:
        return "BSSM_ADT_SFgShp";
    case 276:
        return "BSSM_ADT_SbShp";
    case 277:
        return "BSSM_ADT_SHShp";
    case 278:
        return "BSSM_ADT2";
    case 279:
        return "BSSM_ADT2_G";
    case 280:
        return "BSSM_ADT2_Fg";
    case 281:
        return "BSSM_ADT2_Px";
    case 282:
        return "BSSM_ADT2_GPx";
    case 283:
        return "BSSM_ADT2_H";
    case 284:
        return "BSSM_ADT2_S";
    case 285:
        return "BSSM_ADT2_SG";
    case 286:
        return "BSSM_ADT2_SFg";
    case 287:
        return "BSSM_ADT2_Sb";
    case 288:
        return "BSSM_ADT2_SH";
    case 289:
        return "BSSM_ADT2_Shp";
    case 290:
        return "BSSM_ADT2_GShp";
    case 291:
        return "BSSM_ADT2_FgShp";
    case 292:
        return "BSSM_ADT2_PxShp";
    case 293:
        return "BSSM_ADT2_GPxShp";
    case 294:
        return "BSSM_ADT2_HShp";
    case 295:
        return "BSSM_ADT2_SShp";
    case 296:
        return "BSSM_ADT2_SGShp";
    case 297:
        return "BSSM_ADT2_SFgShp";
    case 298:
        return "BSSM_ADT2_SbShp";
    case 299:
        return "BSSM_ADT2_SHShp";
    case 149:
        return "BSSM_ADTS";
    case 150:
        return "BSSM_ADTS_G";
    case 151:
        return "BSSM_ADTS_H";
    case 152:
        return "BSSM_ADTS_Fg";
    case 153:
        return "BSSM_ADTS_Px";
    case 154:
        return "BSSM_ADTS_GPx";
    case 155:
        return "BSSM_ADTS_S";
    case 156:
        return "BSSM_ADTS_SG";
    case 157:
        return "BSSM_ADTS_SH";
    case 158:
        return "BSSM_ADTS_SFg";
    case 159:
        return "BSSM_ADTS_Sb";
    case 160:
        return "BSSM_ADTS_Shp";
    case 161:
        return "BSSM_ADTS_GShp";
    case 162:
        return "BSSM_ADTS_HShp";
    case 163:
        return "BSSM_ADTS_FgShp";
    case 164:
        return "BSSM_ADTS_PxShp";
    case 165:
        return "BSSM_ADTS_GPxShp";
    case 166:
        return "BSSM_ADTS_SShp";
    case 167:
        return "BSSM_ADTS_SGShp";
    case 168:
        return "BSSM_ADTS_SHShp";
    case 169:
        return "BSSM_ADTS_SFgShp";
    case 170:
        return "BSSM_ADTS_SbShp";
    case 171:
        return "BSSM_ADTS2";
    case 172:
        return "BSSM_ADTS2_G";
    case 173:
        return "BSSM_ADTS2_H";
    case 174:
        return "BSSM_ADTS2_Fg";
    case 175:
        return "BSSM_ADTS2_Px";
    case 176:
        return "BSSM_ADTS2_GPx";
    case 177:
        return "BSSM_ADTS2_S";
    case 178:
        return "BSSM_ADTS2_SG";
    case 179:
        return "BSSM_ADTS2_SH";
    case 180:
        return "BSSM_ADTS2_SFg";
    case 181:
        return "BSSM_ADTS2_Sb";
    case 182:
        return "BSSM_ADTS2_Shp";
    case 183:
        return "BSSM_ADTS2_GShp";
    case 184:
        return "BSSM_ADTS2_HShp";
    case 185:
        return "BSSM_ADTS2_FgShp";
    case 186:
        return "BSSM_ADTS2_PxShp";
    case 187:
        return "BSSM_ADTS2_GPxShp";
    case 188:
        return "BSSM_ADTS2_SShp";
    case 189:
        return "BSSM_ADTS2_SGShp";
    case 190:
        return "BSSM_ADTS2_SHShp";
    case 191:
        return "BSSM_ADTS2_SFgShp";
    case 192:
        return "BSSM_ADTS2_SbShp";
    case 193:
        return "BSSM_ADTS_ONELIGHT";
    case 194:
        return "BSSM_ADTS_DIRANDPT";
    case 195:
        return "BSSM_ADT10";
    case 196:
        return "BSSM_ADT10_G";
    case 197:
        return "BSSM_ADT10_Fg";
    case 198:
        return "BSSM_ADT10_S";
    case 199:
        return "BSSM_ADT10_SG";
    case 200:
        return "BSSM_ADT10_SFg";
    case 201:
        return "BSSM_ADT4";
    case 202:
        return "BSSM_ADT4_Opt";
    case 203:
        return "BSSM_ADT4_G";
    case 204:
        return "BSSM_ADT4_Fg";
    case 205:
        return "BSSM_ADT4_S";
    case 206:
        return "BSSM_ADT4_SG";
    case 207:
        return "BSSM_ADT4_SFg";
    case 208:
        return "BSSM_ADTS10";
    case 209:
        return "BSSM_ADTS10_Opt";
    case 210:
        return "BSSM_ADTS10_G";
    case 211:
        return "BSSM_ADTS10_Fg";
    case 212:
        return "BSSM_ADTS10_S";
    case 213:
        return "BSSM_ADTS10_SG";
    case 214:
        return "BSSM_ADTS10_SFg";
    case 300:
        return "BSSM_DIFFUSEDIR";
    case 301:
        return "BSSM_DIFFUSEPT";
    case 302:
        return "BSSM_DIFFUSEDIR_S";
    case 303:
        return "BSSM_DIFFUSEPT_S";
    case 304:
        return "BSSM_DIFFUSEDIR_Sb";
    case 305:
        return "BSSM_DIFFUSEPT_Sb";
    case 306:
        return "BSSM_DIFFUSEPT2";
    case 307:
        return "BSSM_DIFFUSEPT2_Fg";
    case 308:
        return "BSSM_DIFFUSEPT2_Px";
    case 309:
        return "BSSM_DIFFUSEPT2_S";
    case 310:
        return "BSSM_DIFFUSEPT2_SFg";
    case 311:
        return "BSSM_DIFFUSEPT2_Sb";
    case 312:
        return "BSSM_DIFFUSEPT2_Shp";
    case 313:
        return "BSSM_DIFFUSEPT2_FgShp";
    case 314:
        return "BSSM_DIFFUSEPT2_PxShp";
    case 315:
        return "BSSM_DIFFUSEPT2_SShp";
    case 316:
        return "BSSM_DIFFUSEPT2_SFgShp";
    case 317:
        return "BSSM_DIFFUSEPT2_SbShp";
    case 318:
        return "BSSM_DIFFUSEPT3";
    case 319:
        return "BSSM_DIFFUSEPT3_Fg";
    case 320:
        return "BSSM_DIFFUSEPT3_Px";
    case 321:
        return "BSSM_DIFFUSEPT3_S";
    case 322:
        return "BSSM_DIFFUSEPT3_SFg";
    case 323:
        return "BSSM_DIFFUSEPT3_Sb";
    case 324:
        return "BSSM_DIFFUSEPT3_Shp";
    case 325:
        return "BSSM_DIFFUSEPT3_FgShp";
    case 326:
        return "BSSM_DIFFUSEPT3_PxShp";
    case 327:
        return "BSSM_DIFFUSEPT3_SShp";
    case 328:
        return "BSSM_DIFFUSEPT3_SFgShp";
    case 329:
        return "BSSM_DIFFUSEPT3_SbShp";
    case 330:
        return "BSSM_TEXTURE";
    case 331:
        return "BSSM_TEXTURE_Fg";
    case 332:
        return "BSSM_TEXTURE_H";
    case 333:
        return "BSSM_TEXTURE_S";
    case 334:
        return "BSSM_TEXTURE_Vc";
    case 335:
        return "BSSM_TEXTURE_SVc";
    case 336:
        return "BSSM_TEXTURE_SFg";
    case 337:
        return "BSSM_TEXTURE_Sb";
    case 338:
        return "BSSM_TEXTURE_SH";
    case 339:
        return "BSSM_TEXTURE_Px";
    case 340:
        return "BSSM_SPECULARDIR";
    case 341:
        return "BSSM_SPECULARPT";
    case 342:
        return "BSSM_SPECULARDIR_S";
    case 343:
        return "BSSM_SPECULARPT_S";
    case 346:
        return "BSSM_2x_SPECULARDIR";
    case 347:
        return "BSSM_2x_SPECULARDIR_H";
    case 348:
        return "BSSM_2x_SPECULARDIR_Px";
    case 349:
        return "BSSM_2x_SPECULARDIR_S";
    case 350:
        return "BSSM_2x_SPECULARDIR_SH";
    case 351:
        return "BSSM_2x_SPECULARDIR_Sb";
    case 352:
        return "BSSM_2x_SPECULARDIR_Shp";
    case 353:
        return "BSSM_2x_SPECULARDIR_HShp";
    case 354:
        return "BSSM_2x_SPECULARDIR_PxShp";
    case 355:
        return "BSSM_2x_SPECULARDIR_SShp";
    case 356:
        return "BSSM_2x_SPECULARDIR_SHShp";
    case 357:
        return "BSSM_2x_SPECULARDIR_SbShp";
    case 358:
        return "BSSM_2x_SPECULARPT";
    case 359:
        return "BSSM_2x_SPECULARPT_H";
    case 360:
        return "BSSM_2x_SPECULARPT_Px";
    case 361:
        return "BSSM_2x_SPECULARPT_S";
    case 362:
        return "BSSM_2x_SPECULARPT_SH";
    case 363:
        return "BSSM_2x_SPECULARPT_Sb";
    case 364:
        return "BSSM_2x_SPECULARPT2";
    case 365:
        return "BSSM_2x_SPECULARPT2_H";
    case 366:
        return "BSSM_2x_SPECULARPT2_Px";
    case 367:
        return "BSSM_2x_SPECULARPT2_S";
    case 368:
        return "BSSM_2x_SPECULARPT2_SH";
    case 369:
        return "BSSM_2x_SPECULARPT2_Sb";
    case 370:
        return "BSSM_2x_SPECULARPT3";
    case 371:
        return "BSSM_2x_SPECULARPT3_H";
    case 372:
        return "BSSM_2x_SPECULARPT3_Px";
    case 373:
        return "BSSM_2x_SPECULARPT3_S";
    case 374:
        return "BSSM_2x_SPECULARPT3_SH";
    case 375:
        return "BSSM_2x_SPECULARPT3_Sb";
    case 148:
        return "BSSM_LANDAD_Shp";
    case 495:
        return "BSSM_LANDDIFF";
    case 496:
        return "BSSM_LAND2xDIFF";
    case 497:
        return "BSSM_LAND_G";
    case 498:
        return "BSSM_LANDAD_A";
    case 499:
        return "BSSM_LANDAD_AShp";
    case 500:
        return "BSSM_LAND_GA";
    case 501:
        return "BSSM_LANDDIFF_A";
    case 502:
        return "BSSM_LAND2xDIFF_A";
    case 503:
        return "BSSM_LAND1O";
    case 504:
        return "BSSM_LAND1O_Shp";
    case 505:
        return "BSSM_LAND1O_Simple";
    case 506:
        return "BSSM_LAND1O_SimpleShp";
    case 507:
        return "BSSM_LAND1O4";
    case 508:
        return "BSSM_LAND1O4_Shp";
    case 509:
        return "BSSM_LAND1O4_Simple";
    case 510:
        return "BSSM_LAND1O4_SimpleShp";
    case 511:
        return "BSSM_LAND2O";
    case 512:
        return "BSSM_LAND2O_Shp";
    case 513:
        return "BSSM_LAND2O_Simple";
    case 514:
        return "BSSM_LAND2O_SimpleShp";
    case 515:
        return "BSSM_LAND2O4";
    case 516:
        return "BSSM_LAND2O4_Shp";
    case 517:
        return "BSSM_LAND2O4_Simple";
    case 518:
        return "BSSM_LAND2O4_SimpleShp";
    case 519:
        return "BSSM_LAND3O";
    case 520:
        return "BSSM_LAND3O_Shp";
    case 521:
        return "BSSM_LAND3O_Simple";
    case 522:
        return "BSSM_LAND3O_SimpleShp";
    case 523:
        return "BSSM_LAND3O4";
    case 524:
        return "BSSM_LAND3O4_Shp";
    case 525:
        return "BSSM_LAND3O4_Simple";
    case 526:
        return "BSSM_LAND3O4_SimpleShp";
    case 527:
        return "BSSM_LAND4O";
    case 528:
        return "BSSM_LAND4O_Shp";
    case 529:
        return "BSSM_LAND4O_Simple";
    case 530:
        return "BSSM_LAND4O_SimpleShp";
    case 531:
        return "BSSM_LAND4O4";
    case 532:
        return "BSSM_LAND4O4_Shp";
    case 533:
        return "BSSM_LAND4O4_Simple";
    case 534:
        return "BSSM_LAND4O4_SimpleShp";
    case 535:
        return "BSSM_LAND5O";
    case 536:
        return "BSSM_LAND5O_Shp";
    case 537:
        return "BSSM_LAND5O_Simple";
    case 538:
        return "BSSM_LAND5O_SimpleShp";
    case 539:
        return "BSSM_LAND5O4";
    case 540:
        return "BSSM_LAND5O4_Shp";
    case 541:
        return "BSSM_LAND5O4_Simple";
    case 542:
        return "BSSM_LAND5O4_SimpleShp";
    case 543:
        return "BSSM_LAND6O";
    case 544:
        return "BSSM_LAND6O_Shp";
    case 545:
        return "BSSM_LAND6O_Simple";
    case 546:
        return "BSSM_LAND6O_SimpleShp";
    case 547:
        return "BSSM_LAND6O4";
    case 548:
        return "BSSM_LAND6O4_Shp";
    case 549:
        return "BSSM_LAND6O4_Simple";
    case 550:
        return "BSSM_LAND6O4_SimpleShp";
    case 551:
        return "BSSM_LAND7O";
    case 552:
        return "BSSM_LAND7O_Shp";
    case 553:
        return "BSSM_LAND7O_Simple";
    case 554:
        return "BSSM_LAND7O_SimpleShp";
    case 555:
        return "BSSM_LAND7O4";
    case 556:
        return "BSSM_LAND7O4_Shp";
    case 557:
        return "BSSM_LAND7O4_Simple";
    case 558:
        return "BSSM_LAND7O4_SimpleShp";
    case 559:
        return "BSSM_LANDO_Am";
    case 560:
        return "BSSM_LANDLO_A";
    case 561:
        return "BSSM_2x_SIMPLESHADOW";
    case 562:
        return "BSSM_2x_SIMPLESHADOW_S";
    case 563:
        return "BSSM_2x_SIMPLESHADOW_LAND";
    case 564:
        return "BSSM_2x_SIMPLESHADOW_Sb";
    case 565:
        return "BSSM_ADT_Sbb";
    case 566:
        return "BSSM_DISTANT_TREE_BASE";
    case 376:
        return "BSSM_3XOCCLUSION";
    case 10:
        return "BSSM_3XZONLY";
    case 11:
        return "BSSM_3XZONLY_S";
    case 12:
        return "BSSM_3XZONLY_Vc";
    case 13:
        return "BSSM_3XZONLY_SVc";
    case 14:
        return "BSSM_3XZONLY_TEXEFFECT";
    case 15:
        return "BSSM_3XZONLY_TEXEFFECT_S";
    case 383:
        return "BSSM_3XLIGHTING";
    case 384:
        return "BSSM_3XLIGHTING_S";
    case 385:
        return "BSSM_3XLIGHTING_H";
    case 386:
        return "BSSM_3XLIGHTING_Px";
    case 387:
        return "BSSM_3XLIGHTING_Pxo";
    case 388:
        return "BSSM_3XLIGHTING_Fg";
    case 389:
        return "BSSM_3XLIGHTING_SFg";
    case 390:
        return "BSSM_3XLIGHTING_G";
    case 391:
        return "BSSM_3XLIGHTING_SG";
    case 392:
        return "BSSM_3XLIGHTING_Vc";
    case 393:
        return "BSSM_3XLIGHTING_VcS";
    case 394:
        return "BSSM_3XLIGHTING_VcPx";
    case 395:
        return "BSSM_3XLIGHTING_VcPxo";
    case 396:
        return "BSSM_3XLIGHTING_VcG";
    case 397:
        return "BSSM_3XLIGHTING_VcSG";
    case 398:
        return "BSSM_3XLIGHTING_Spc";
    case 399:
        return "BSSM_3XLIGHTING_SSpc";
    case 400:
        return "BSSM_3XLIGHTING_HSpc";
    case 401:
        return "BSSM_3XLIGHTING_PxSpc";
    case 402:
        return "BSSM_3XLIGHTING_PxoSpc";
    case 403:
        return "BSSM_3XLIGHTING_FgSpc";
    case 404:
        return "BSSM_3XLIGHTING_SFgSpc";
    case 405:
        return "BSSM_3XLIGHTING_GSpc";
    case 406:
        return "BSSM_3XLIGHTING_SGSpc";
    case 407:
        return "BSSM_3XLIGHTING_VcSpc";
    case 408:
        return "BSSM_3XLIGHTING_VcSSpc";
    case 409:
        return "BSSM_3XLIGHTING_VcPxSpc";
    case 410:
        return "BSSM_3XLIGHTING_VcPxoSpc";
    case 411:
        return "BSSM_3XLIGHTING_VcGSpc";
    case 412:
        return "BSSM_3XLIGHTING_VcSGSpc";
    case 413:
        return "BSSM_3XLIGHTING_Shp";
    case 414:
        return "BSSM_3XLIGHTING_SShp";
    case 415:
        return "BSSM_3XLIGHTING_HShp";
    case 416:
        return "BSSM_3XLIGHTING_PxShp";
    case 417:
        return "BSSM_3XLIGHTING_PxoShp";
    case 418:
        return "BSSM_3XLIGHTING_FgShp";
    case 419:
        return "BSSM_3XLIGHTING_SFgShp";
    case 420:
        return "BSSM_3XLIGHTING_GShp";
    case 421:
        return "BSSM_3XLIGHTING_SGShp";
    case 422:
        return "BSSM_3XLIGHTING_VcShp";
    case 423:
        return "BSSM_3XLIGHTING_VcSShp";
    case 424:
        return "BSSM_3XLIGHTING_VcPxShp";
    case 425:
        return "BSSM_3XLIGHTING_VcPxoShp";
    case 426:
        return "BSSM_3XLIGHTING_VcGShp";
    case 427:
        return "BSSM_3XLIGHTING_VcSGShp";
    case 428:
        return "BSSM_3XLIGHTING_ShpSpc";
    case 429:
        return "BSSM_3XLIGHTING_SShpSpc";
    case 430:
        return "BSSM_3XLIGHTING_HShpSpc";
    case 431:
        return "BSSM_3XLIGHTING_PxShpSpc";
    case 432:
        return "BSSM_3XLIGHTING_PxoShpSpc";
    case 433:
        return "BSSM_3XLIGHTING_FgShpSpc";
    case 434:
        return "BSSM_3XLIGHTING_SFgShpSpc";
    case 435:
        return "BSSM_3XLIGHTING_GShpSpc";
    case 436:
        return "BSSM_3XLIGHTING_SGShpSpc";
    case 437:
        return "BSSM_3XLIGHTING_VcShpSpc";
    case 438:
        return "BSSM_3XLIGHTING_VcSShpSpc";
    case 439:
        return "BSSM_3XLIGHTING_VcPxShpSpc";
    case 440:
        return "BSSM_3XLIGHTING_VcPxoShpSpc";
    case 441:
        return "BSSM_3XLIGHTING_VcGShpSpc";
    case 442:
        return "BSSM_3XLIGHTING_VcSGShpSpc";
    case 445:
        return "BSSM_3XENVMAP";
    case 446:
        return "BSSM_3XENVMAP_W";
    case 447:
        return "BSSM_3XENVMAP_Vc";
    case 448:
        return "BSSM_3XENVMAP_WVc";
    case 449:
        return "BSSM_3XENVMAP_S";
    case 450:
        return "BSSM_3XENVMAP_SVc";
    case 451:
        return "BSSM_3XENVMAP_EYE";
    case 452:
        return "BSSM_3XLIGHTING_SIMPLESHADOW";
    case 453:
        return "BSSM_3XLIGHTING_SIMPLESHADOW_Vc";
    case 454:
        return "BSSM_3XLIGHTING_SIMPLESHADOW_S";
    case 455:
        return "BSSM_3XLIGHTING_SIMPLESHADOW_VcS";
    case 456:
        return "BSSM_3XDEPTHMAP";
    case 457:
        return "BSSM_3XDEPTHMAP_Vc";
    case 458:
        return "BSSM_3XDEPTHMAP_S";
    case 459:
        return "BSSM_3XDEPTHMAP_VcS";
    case 467:
        return "BSSM_3XCONSTALPHA";
    case 468:
        return "BSSM_3XCONSTALPHA_Vc";
    case 469:
        return "BSSM_3XCONSTALPHA_S";
    case 470:
        return "BSSM_3XCONSTALPHA_SVc";
    case 460:
        return "BSSM_3XRENDERNORMALS";
    case 461:
        return "BSSM_3XRENDERNORMALS_Vc";
    case 462:
        return "BSSM_3XRENDERNORMALS_S";
    case 463:
        return "BSSM_3XRENDERNORMALS_VcS";
    case 464:
        return "BSSM_3XRENDERNORMALS_FIRE";
    case 465:
        return "BSSM_3XRENDERNORMALS_CLEAR";
    case 466:
        return "BSSM_3XRENDERNORMALS_CLEAR_S";
    case 443:
        return "BSSM_3XSILHOUETTE";
    case 444:
        return "BSSM_3XSILHOUETTE_Vc";
    case 477:
        return "BSSM_3XLOCALMAP";
    case 478:
        return "BSSM_3XLOCALMAP_S";
    case 479:
        return "BSSM_3XLOCALMAP_CLEAR";
    case 480:
        return "BSSM_3XTEXEFFECT";
    case 481:
        return "BSSM_3XTEXEFFECT_S";
    case 490:
        return "BSSM_VELOCITY";
    case 491:
        return "BSSM_VELOCITY_S";
    case 475:
        return "BSSM_3XVELOCITY";
    case 476:
        return "BSSM_3XVELOCITY_S";
    case 471:
        return "BSSM_3XDEPTH";
    case 472:
        return "BSSM_3XDEPTH_Vc";
    case 473:
        return "BSSM_3XDEPTH_S";
    case 474:
        return "BSSM_3XDEPTH_SVc";
    case 568:
        return "BSSM_SKYBASEPRE";
    case 569:
        return "BSSM_SKY";
    case 572:
        return "BSSM_SKY_TEXTURE";
    case 570:
        return "BSSM_SKY_MOON_STARS_MASK";
    case 722:
        return "BSSM_SKY_SUNGLARE";
    case 571:
        return "BSSM_SKY_STARS";
    case 574:
        return "BSSM_SKY_CLOUDS_UNDERWATER";
    case 573:
        return "BSSM_SKY_CLOUDS";
    case 723:
        return "BSSM_SELFILLUM_SKY_SUN";
    case 725:
        return "BSSM_SELFILLUM_SKY_SKY_QUAD";
    case 724:
        return "BSSM_SELFILLUM_SKY_CLOUDS";
    case 650:
        return "BSSM_WATER_WADING";
    case 651:
        return "BSSM_WATER_WADING_NO_REFLECTIONS_NO_REFRACTIONS";
    case 652:
        return "BSSM_WATER_WADING_NO_REFRACTIONS";
    case 653:
        return "BSSM_WATER_WADING_NO_REFLECTIONS";
    case 654:
        return "BSSM_WATER_WADING_NO_DEPTH";
    case 655:
        return "BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS";
    case 656:
        return "BSSM_WATER_WADING_NO_DEPTH_NO_REFRACTIONS";
    case 657:
        return "BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS";
    case 658:
        return "BSSM_WATER_INTERIOR_WADING";
    case 659:
        return "BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS_NO_REFRACTIONS";
    case 660:
        return "BSSM_WATER_INTERIOR_WADING_NO_REFRACTIONS";
    case 661:
        return "BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS";
    case 662:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH";
    case 663:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS";
    case 664:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFRACTIONS";
    case 665:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS";
    case 666:
        return "BSSM_WATER_WADING_SPECULAR_LIGHTING";
    case 684:
        return "BSSM_WATER";
    case 685:
        return "BSSM_WATER_NO_REFLECTIONS_NO_REFRACTIONS";
    case 686:
        return "BSSM_WATER_NO_REFRACTIONS";
    case 687:
        return "BSSM_WATER_NO_REFLECTIONS";
    case 688:
        return "BSSM_WATER_INTERIOR";
    case 689:
        return "BSSM_WATER_INTERIOR_NO_REFLECTIONS_NO_REFRACTIONS";
    case 690:
        return "BSSM_WATER_INTERIOR_NO_REFRACTIONS";
    case 691:
        return "BSSM_WATER_INTERIOR_NO_REFLECTIONS";
    case 692:
        return "BSSM_WATER_NODEPTH";
    case 693:
        return "BSSM_WATER_NODEPTH_NO_REFLECTIONS";
    case 694:
        return "BSSM_WATER_NODEPTH_NO_REFRACTIONS";
    case 695:
        return "BSSM_WATER_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS";
    case 696:
        return "BSSM_WATER_INTERIOR_NODEPTH";
    case 697:
        return "BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS";
    case 698:
        return "BSSM_WATER_INTERIOR_NODEPTH_NO_REFRACTIONS";
    case 699:
        return "BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS";
    case 648:
        return "BSSM_WATER_STENCIL";
    case 700:
        return "BSSM_WATER_SPECULAR_LIGHTING";
    case 701:
        return "BSSM_WATER_UNDERWATER";
    case 667:
        return "BSSM_WATER_WADING_Vc";
    case 670:
        return "BSSM_WATER_WADING_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 669:
        return "BSSM_WATER_WADING_NO_REFRACTIONS_Vc";
    case 668:
        return "BSSM_WATER_WADING_NO_REFLECTIONS_Vc";
    case 671:
        return "BSSM_WATER_WADING_NO_DEPTH_Vc";
    case 672:
        return "BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS_Vc";
    case 673:
        return "BSSM_WATER_WADING_NO_DEPTH_NO_REFRACTIONS_Vc";
    case 674:
        return "BSSM_WATER_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 675:
        return "BSSM_WATER_INTERIOR_WADING_Vc";
    case 678:
        return "BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 677:
        return "BSSM_WATER_INTERIOR_WADING_NO_REFRACTIONS_Vc";
    case 676:
        return "BSSM_WATER_INTERIOR_WADING_NO_REFLECTIONS_Vc";
    case 679:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_Vc";
    case 680:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS_Vc";
    case 681:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFRACTIONS_Vc";
    case 682:
        return "BSSM_WATER_INTERIOR_WADING_NO_DEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 683:
        return "BSSM_WATER_WADING_SPECULAR_LIGHTING_Vc";
    case 702:
        return "BSSM_WATER_Vc";
    case 703:
        return "BSSM_WATER_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 704:
        return "BSSM_WATER_NO_REFRACTIONS_Vc";
    case 705:
        if (aiShader == 705)
        {
        }  // consumes compiler label $LN85, which the symbol DB binds elsewhere
        return "BSSM_WATER_NO_REFLECTIONS_Vc";
    case 706:
        return "BSSM_WATER_INTERIOR_Vc";
    case 707:
        return "BSSM_WATER_INTERIOR_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 708:
        return "BSSM_WATER_INTERIOR_NO_REFRACTIONS_Vc";
    case 709:
        return "BSSM_WATER_INTERIOR_NO_REFLECTIONS_Vc";
    case 710:
        return "BSSM_WATER_NODEPTH_Vc";
    case 711:
        return "BSSM_WATER_NODEPTH_NO_REFLECTIONS_Vc";
    case 712:
        return "BSSM_WATER_NODEPTH_NO_REFRACTIONS_Vc";
    case 713:
        return "BSSM_WATER_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 714:
        return "BSSM_WATER_INTERIOR_NODEPTH_Vc";
    case 715:
        return "BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS_NO_REFRACTIONS_Vc";
    case 716:
        return "BSSM_WATER_INTERIOR_NODEPTH_NO_REFRACTIONS_Vc";
    case 717:
        return "BSSM_WATER_INTERIOR_NODEPTH_NO_REFLECTIONS_Vc";
    case 649:
        return "BSSM_WATER_STENCIL_Vc";
    case 718:
        return "BSSM_WATER_SPECULAR_LIGHTING_Vc";
    case 575:
        return "BSSM_WATER_LOD";
    case 576:
        return "BSSM_WATER_LOD_NO_REFLECTIONS";
    case 719:
        return "BSSM_PRECIPITATION_RAIN";
    case 577:
        return "BSSM_PARTICLE";
    case 578:
        return "BSSM_BOLT";
    case 579:
        return "BSSM_BEAM";
    case 580:
        return "BSSM_ENVMAP";
    case 581:
        return "BSSM_ENVMAP_Vc";
    case 582:
        return "BSSM_ENVMAP_S";
    case 583:
        return "BSSM_ENVMAP_SVc";
    case 584:
        return "BSSM_2x_ENVMAP";
    case 585:
        return "BSSM_2x_ENVMAP_S";
    case 586:
        return "BSSM_2x_ENVMAP_W";
    case 587:
        return "BSSM_2x_ENVMAP_EYE";
    case 590:
        return "BSSM_TEXEFFECT";
    case 591:
        return "BSSM_TEXEFFECT_S";
    case 592:
        return "BSSM_2x_TEXEFFECT";
    case 593:
        return "BSSM_2x_TEXEFFECT_S";
    case 588:
        return "BSSM_GEOMDECAL";
    case 589:
        return "BSSM_GEOMDECAL_S";
    case 594:
        return "BSSM_FOG";
    case 595:
        return "BSSM_FOG_A";
    case 596:
        return "BSSM_FOG_S";
    case 597:
        return "BSSM_FOG_SA";
    case 598:
        return "BSSM_FOG_Sb";
    case 728:
        return "BSSM_WATER_DEPTH";
    case 729:
        return "BSSM_WATER_DEPTH_S";
    case 730:
        return "BSSM_3XWATER_DEPTH";
    case 731:
        return "BSSM_3XWATER_DEPTH_S";
    case 732:
        return "BSSM_NLWATER_DEPTH";
    case 733:
        return "BSSM_NLWATER_DEPTH_S";
    case 734:
        return "BSSM_WATER_DEPTH_At";
    case 735:
        return "BSSM_WATER_DEPTH_SAt";
    case 736:
        return "BSSM_3XWATER_DEPTH_At";
    case 737:
        return "BSSM_3XWATER_DEPTH_SAt";
    case 738:
        return "BSSM_NLWATER_DEPTH_At";
    case 739:
        return "BSSM_NLWATER_DEPTH_At_S";
    case 740:
        return "BSSM_WATER_DEPTH_Vc";
    case 741:
        return "BSSM_WATER_DEPTH_SVc";
    case 742:
        return "BSSM_3XWATER_DEPTH_Vc";
    case 743:
        return "BSSM_3XWATER_DEPTH_SVc";
    case 744:
        return "BSSM_NLWATER_DEPTH_Vc";
    case 745:
        return "BSSM_NLWATER_DEPTH_Vc_S";
    case 746:
        return "BSSM_WATER_DEPTH_AtVc";
    case 747:
        return "BSSM_WATER_DEPTH_SAtVc";
    case 748:
        return "BSSM_3XWATER_DEPTH_AtVc";
    case 749:
        return "BSSM_3XWATER_DEPTH_SAtVc";
    case 750:
        return "BSSM_NLWATER_DEPTH_AtVc";
    case 751:
        return "BSSM_NLWATER_DEPTH_AtVc_S";
    case 720:
        return "BSSM_SKYBASEPOST";
    case 721:
        return "BSSM_SELFILLUM_SKY";
    case 726:
        return "BSSM_SELFILLUMALPHA";
    case 727:
        return "BSSM_SELFILLUMALPHA_S";
    case 20:
        return "BSSM_SELFILLUMALPHABLOCK";
    case 21:
        return "BSSM_SELFILLUMALPHABLOCK_S";
    case 754:
        return "BSSM_SHADOWVOLUME_BACK";
    case 755:
        return "BSSM_SHADOWVOLUME_FRONT";
    case 756:
        return "BSSM_SHADOWVOLUME_WIRE";
    case 482:
        return "BSSM_RENDERNORMALS";
    case 483:
        return "BSSM_RENDERNORMALS_S";
    case 484:
        return "BSSM_RENDERNORMALS_FIRE";
    case 485:
        return "BSSM_RENDERNORMALS_CLEAR";
    case 486:
        return "BSSM_RENDERNORMALS_CLEAR_S";
    case 492:
        return "BSSM_LOCALMAP";
    case 493:
        return "BSSM_LOCALMAP_S";
    case 494:
        return "BSSM_LOCALMAP_CLEAR";
    case 753:
        return "BSSM_BLOOD_SPLATTER";
    case 752:
        return "BSSM_BLOOD_SPLATTER_FLARE";
    case 757:
        return "BSSM_TILE";
    default: {
        char acBuffer[10];
        sprintf_s(acBuffer, 10, "??? %d", aiShader);
        return "???";
    }
    }
}

struct ShaderListNode
{
    void* m_data;
    ShaderListNode* m_next;
};

class ShaderEntryBase
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual ShaderListNode* vfn_8();
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
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
};

extern ShaderEntryBase* DAT_011f9548;
extern char DAT_011f95d4;
extern char DAT_0126f554;
struct ImageSpaceTail
{
    void Tail();
};

// Iterates shader entries, calls vfn_120 on each whose node list contains DAT_0126f554, then calls Tail on DAT_011f91ac.
// @fnv 0x00b557d0
// src: COMMUNITY 0x00b557d0
void __cdecl BSShaderManager_ReloadShaders()
{
    ShaderEntryBase** ppEntry = (ShaderEntryBase**)&DAT_011f9548;
    do
    {
        ShaderEntryBase* p = *ppEntry;
        if (p != 0)
        {
            ShaderListNode* n = p->vfn_8();
            unsigned char found;
            if (n != 0)
            {
                do
                {
                    if ((char*)n == &DAT_0126f554)
                        goto hit;
                    n = n->m_next;
                } while (n != 0);
            }
            found = 0;
            goto join;
        hit:
            found = 1;
        join: {
            ShaderEntryBase* t = (ShaderEntryBase*)((unsigned int)p & (found ? 0xffffffffu : 0u));
            if (t != 0)
            {
                t->vfn_120();
            }
        }
        }
        ++ppEntry;
    } while ((int)ppEntry < (int)&DAT_011f95d4);
    ((ImageSpaceTail*)DAT_011f91ac)->Tail();
}

struct FUN_00b55b00_prop
{
    char unk00[0x1c];
    unsigned int m_uiType;
    char unk20[0x6c - 0x20];
    float m_fValue;
};

// @fnv 0x00b55b00
// src: XBOX_PDB 0x00b55b00
void __cdecl BSShaderManager_RecursiveSetForcedDarkness(PropHelper* pPropHelper, float fValue)
{
    FUN_00b55b00_prop* prop = (FUN_00b55b00_prop*)pPropHelper->GetProperty(3);
    if (prop != 0)
    {
        unsigned int t = prop->m_uiType - 1;
        int iOutOfRange = (t > 11) ? -1 : 0;
        int inRange = (iOutOfRange + 1) != 0 ? -1 : 0;
        FUN_00b55b00_prop* target = (FUN_00b55b00_prop*)((unsigned int)prop & (unsigned int)inRange);
        if (target != 0)
        {
            target->m_fValue = fValue;
        }
    }
    if (pPropHelper->vfn_c() != 0)
    {
        unsigned int i = 0;
        unsigned short zero = 0;
        if (zero < pPropHelper->m_uiItemCount)
        {
            do
            {
                void* child = pPropHelper->m_children[i];
                if (child != 0)
                {
                    BSShaderManager_RecursiveSetForcedDarkness((PropHelper*)child, fValue);
                }
                ++i;
            } while (i < pPropHelper->m_uiItemCount);
        }
    }
}

extern "C" int __cdecl sprintf_s(char*, size_t, const char*, ...);
struct RTTIStub
{
    int unk00;
};
extern RTTIStub g_012021b8;
extern RTTIStub g_01200508;
extern RTTIStub g_01202040;
struct ShProp;
struct PropPtr
{
    ShProp* m_p;
    PropPtr& operator=(ShProp*);
};

struct AVObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual int vfn_30();
    int unk04;
    const char* m_name;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    PropPtr m_props[8];
    int unkbc;
    struct Shader* m_shaderC0;
    void* GetProperty(unsigned int);
    void RemoveProperty(unsigned int);
    void AttachProperty(ShProp*);
};
struct ShProp
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual int vfn_8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual ShProp* vfn_b0(AVObj*, int, int);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    unsigned char flags38;
    unsigned char unk39;
    unsigned short unk3a;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    void* unk58;
};
struct Shader
{
    virtual void v00();
    virtual void v04();
    virtual RTTIStub* vfn_8();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void vfn_50(AVObj*);
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual int vfn_118(AVObj*, ShProp*);
};
struct Renderer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vfn_ec(AVObj*, int, int, int);
};
extern Renderer* DAT_011f4748;
inline bool IsExactB(Shader* s, RTTIStub* r)
{
    bool b = s->vfn_8() == r;
    return b;
}

Shader* __cdecl BSShaderManager_GetShader(void*);

// @fnv 0x00b579e0
void __cdecl UpdateShaderProperty(AVObj* obj, bool abUnused, bool abFlag8, bool a3)
{
    char buf[1000];
    ShProp* prop = (ShProp*)obj->GetProperty(3);
    ShProp* pShaderProp;
    if (prop && (pShaderProp = prop->unk1c != -1 ? prop : 0) != 0)
    {
        ShProp* pNewProp = pShaderProp->vfn_b0(obj, 0, 1);
        if (pNewProp)
        {
            obj->RemoveProperty(3);
            pShaderProp = pNewProp;
            obj->AttachProperty(pNewProp);
            if (pNewProp->vfn_8c() <= 7)
                obj->m_props[pNewProp->vfn_8c()] = pNewProp;
        }
        if (!pShaderProp->unk58)
        {
            obj->RemoveProperty(3);
            return;
        }
        Shader* pShader = BSShaderManager_GetShader(pShaderProp->unk58);
        obj->m_shaderC0 = pShader;
        pShader->vfn_50(obj);
        bool bIsShaderA = pShader->vfn_8() == &g_012021b8;
        bool bIsShaderB = IsExactB(pShader, &g_01200508);
        a3 |= (bIsShaderB || bIsShaderA != bIsShaderB || obj->vfn_30());
        bool bIsShaderC = pShader->vfn_8() == &g_01202040;
        ShProp* pFlagsProp = obj->m_props[7].m_p;
        int iFlags = pFlagsProp->flags38 | 0x33;
        pFlagsProp->flags38 = (bIsShaderC ? 4 : 0) | ((abFlag8 || bIsShaderC) ? 8 : 0) | iFlags;
        if (!a3)
        {
            Renderer* r = DAT_011f4748;
            r->vfn_ec(obj, 0x12, 4, pShader->vfn_118(obj, pShaderProp));
        }
    }
    else
    {
        sprintf_s(buf, 1000, "ERROR: %s does not have a shader property. ", obj->m_name);
    }
}

void* __cdecl NiMalloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
extern MemoryManager _g_memoryManager;

struct StringHashMapBase
{
    virtual void vfn_0();
    virtual void vfn_4();
    unsigned int m_uiCount;
    void** m_apBuckets;
    int m_iUnk14;
    unsigned char m_bShaderEnabled;
    StringHashMapBase();
    ~StringHashMapBase();
};
StringHashMapBase::StringHashMapBase()
{
    m_uiCount = 0x25;
    m_iUnk14 = 0;
    m_apBuckets = (void**)NiMalloc(0x94);
    unsigned int uiBytes = m_uiCount;
    uiBytes += uiBytes;
    uiBytes += uiBytes;
    _fnv_zlib_memset(m_apBuckets, 0, uiBytes);
    m_bShaderEnabled = 1;
}
// Exe 0x00b7ff40: unit-local ShaderMap view; declarations and layout are preserved.
struct BsshadermanagerShaderMapView : StringHashMapBase
{
    virtual void vfn_8();
};
struct FUN_00b7ff40
{
    char* m_name;
    int m_unk04;
    BsshadermanagerShaderMapView m_map;
    FUN_00b7ff40(int value);
};
// Initializes m_name to null and, when value is positive, allocates and stores a formatted "Data\Shaders\shaderpackage%03i.sdp" path.
// @fnv 0x00b7ff40
FUN_00b7ff40::FUN_00b7ff40(int aiPackageIndex)
{
    m_unk04 = 0;
    m_name = 0;
    if (aiPackageIndex > 0)
    {
        char acBuffer[100];
        sprintf_s(acBuffer, 100, "Data\\Shaders\\shaderpackage%03i.sdp", aiPackageIndex);
        unsigned int uiLength = strlen(acBuffer) + 1;
        m_name = (char*)_g_memoryManager.Allocate(uiLength);
        strcpy_s(m_name, uiLength, acBuffer);
    }
}


// @fnv 0x00b4f2e0
// src: COMMUNITY 0x00b4f2e0
NiFile* BSShaderManager_DefaultFileCreateFunc(char const* fileName, NiFile::OpenMode openMode, unsigned int size)
{
    return NiFile::GetFile(fileName, openMode, size);
}

struct CopyMap
{
    virtual ~CopyMap();
};
struct NiObjectCopyInfo
{
    CopyMap* first;
    CopyMap* second;
    unsigned int unk08, unk0C;
    NiObjectCopyInfo(unsigned int);
    ~NiObjectCopyInfo()
    {
        delete first;
        delete second;
    }
};
struct Color3
{
    float r, g, b;
};
struct Material : NiRefObject
{
    unsigned int unk08, controller, unk10, unk14, unk18;
    Color3 color1, color2;
    Color3* colorOverride;
    float value38, value3C, value40;
    unsigned int revision, unk48;
    static void* operator new(unsigned int);
    Material();
    void SetColor1(const Color3& v)
    {
        color1 = v;
        ++revision;
    }
    void SetColor2(const Color3& v)
    {
        color2 = v;
        ++revision;
    }
    void Set40(float v)
    {
        value40 = v;
        ++revision;
    }
    void Set38(float v)
    {
        value38 = v;
        ++revision;
    }
    void Set3C(float v)
    {
        value3C = v;
        ++revision;
    }
};
template <class T> inline NiPointer<T>::NiPointer(T* p) : m_pObject(p)
{
    if (p)
        InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}
struct Walker : PropHelper
{
    void RemoveProperty(Material*);
    void AttachProperty(Material*);
};
// Copies the material property (index 2) of obj and its descendants, cloning it when it has no controller and reattaching it.
// @fnv 0x00b57c60
void __cdecl CopyMaterialPropertyRecursive(Walker* apWalker)
{
    if (apWalker)
    {
        NiPointer<Material> prop(static_cast<Material*>(apWalker->GetProperty(2)));
        Material* pSourceMaterial = prop.m_pObject;
        if (pSourceMaterial)
        {
            apWalker->RemoveProperty(pSourceMaterial);
            NiObjectCopyInfo copyInfo(0x101);
            Material* pDestMaterial;
            if (pSourceMaterial->controller)
                pDestMaterial = pSourceMaterial;
            else
            {
                pDestMaterial = new Material;
                pDestMaterial->SetColor1(pSourceMaterial->color1);
                Color3* pColor2;
                if (pSourceMaterial->colorOverride != 0)
                {
                    pColor2 = prop.m_pObject->colorOverride;
                }
                else
                {
                    pColor2 = &pSourceMaterial->color2;
                }
                pDestMaterial->SetColor2(*pColor2);
                pDestMaterial->Set40(pSourceMaterial->value40);
                pDestMaterial->Set38(pSourceMaterial->value38);
                pDestMaterial->Set3C(pSourceMaterial->value3C);
            }
            apWalker->AttachProperty(pDestMaterial);
        }
        PropHelper* pChildNode = static_cast<PropHelper*>(apWalker->vfn_c());
        if (pChildNode)
        {
            unsigned int count = pChildNode->m_uiItemCount;
            for (unsigned int i = 0; i < count; ++i)
            {
                Walker* child = static_cast<Walker*>(pChildNode->m_children[i]);
                if (child)
                    CopyMaterialPropertyRecursive(child);
            }
        }
    }
}

extern "C" int __cdecl _strnicmp(const char*, const char*, size_t);
extern int DAT_011f91c0;
extern int DAT_011f91d8;
extern unsigned char DAT_011f941e;
extern unsigned char DAT_011f94a4;
extern unsigned char DAT_011f94a6;
extern int DAT_011ad870;
extern int DAT_011f94b8;
extern float DAT_01200458;
extern unsigned char DAT_011ad80e;
extern unsigned char DAT_011f94d8;
extern unsigned char DAT_011f94e4;
extern unsigned char DAT_011f91a4;
// Sets DAT_011f91c0 and DAT_011f91d8 from a0/a1, then classifies a4 as ATI, NV, or IG and stores the result in DAT_011f91bc.
// @fnv 0x00b4f710
void __cdecl DetectGpuVendor(unsigned int a0, unsigned int a1, bool abForceLow, int a3, const char* apVendorName,
                             int a5)
{
    const unsigned char* p0 = (const unsigned char*)&a0;
    const unsigned char* p1 = (const unsigned char*)&a1;
    int bHighLevel = (p0[1] >= 2 && p1[1] >= 2);
    if (bHighLevel)
    {
        DAT_011f91c0 = 2;
        DAT_011f91d8 = 0x2f;
        if (p0[1] >= 3 && p1[1] >= 3)
            DAT_011f94a4 = 1;
    }
    else if (p0[1] >= 1 && p1[1] >= 1)
    {
        DAT_011f91c0 = 1;
        DAT_011f941e = 0;
        DAT_011f91d8 = 0xf;
    }
    else
    {
        DAT_011f91c0 = 0;
        DAT_011f941e = 0;
    }
    if (bHighLevel && a3 != 0 && apVendorName != 0)
    {
        if (_strnicmp(apVendorName, "ati", 3) == 0)
        {
            if (a5 > 0x60)
            {
                if (DAT_011f91c0 == 2)
                    DAT_011f91c0 = 6;
                DAT_011f91bc = 6;
                if (a5 > 0xff)
                    DAT_011f94a6 = 1;
            }
            else
            {
                if (DAT_011f91c0 == 2)
                    DAT_011f91c0 = 4;
                DAT_011f91bc = 6;
            }
            DAT_011ad870 = 0x15;
            DAT_011f94b8 = 2;
        }
        else if (_strnicmp(apVendorName, "nv", 2) == 0)
        {
            if (a5 > 0x60)
            {
                if (DAT_011f91c0 == 2)
                    DAT_011f91c0 = 5;
                DAT_011f91bc = 5;
                if (a5 > 0xff)
                    DAT_011f94a6 = 1;
            }
            else
            {
                if (DAT_011f91c0 == 2)
                    DAT_011f91c0 = 3;
                DAT_011f91bc = 5;
            }
            DAT_011f94b8 = 1;
        }
        else if (_strnicmp(apVendorName, "ig", 2) == 0)
        {
            if (a5 > 0x60)
            {
                if (DAT_011f91c0 == 2)
                    DAT_011f91c0 = 5;
                DAT_011f91bc = 5;
                if (a5 > 0xff)
                    DAT_011f94a6 = 1;
            }
            else
            {
                if (DAT_011f91c0 == 2)
                    DAT_011f91c0 = 3;
                DAT_011f91bc = 5;
            }
            DAT_011f94b8 = 3;
        }
        else
        {
            DAT_011f91c0 = 2;
            DAT_011f91bc = 2;
        }
        DAT_01200458 = -2e-5f;
    }
    if (DAT_011f91c0 < 2)
        DAT_011f91d8 &= 0xffffffef;
    if (abForceLow && DAT_011f91c0 != 0)
        DAT_011f91c0 = 1;
    if (DAT_011ad80e != 0 && DAT_011f94a4 != 0 && DAT_011f94d8 != 0)
        DAT_011ad80e = 1;
    else
        DAT_011ad80e = 0;
    DAT_011f91a4 = DAT_011f94e4;
}

template <class T, class Allocator> inline T& NiTArray<T, Allocator>::GetAt(unsigned int index)
{
    return m_pBase[index];
}
void __cdecl UpdateShaderProperty(NiAVObject* pkObject, BSShaderManager::eObjectType eType, bool bArg2, bool bArg3);

// Recursively applies a shader property to a NiAVObject, descending into child nodes when the object is not geometry.
// @fnv 0x00b57bd0
// src: COMMUNITY 0x00b57bd0
void __cdecl BSShaderManager_PrepareObjectRecurse(NiAVObject* pkObject, BSShaderManager::eObjectType eType, bool bArg2, bool bArg3)
{
    if (pkObject->IsSceneNode() || pkObject->IsGeometry())
    {
        if (pkObject->IsGeometry())
        {
            UpdateShaderProperty(pkObject, eType, bArg2, bArg3);
        }
        else
        {
            NiNode* pkNode = (NiNode*)pkObject;
            for (unsigned int i = 0; i < pkNode->m_kChildren.m_usSize; i++)
            {
                NiAVObject* pkChild = pkNode->m_kChildren.GetAt(i).m_pObject;
                if (pkChild)
                    BSShaderManager_PrepareObjectRecurse(pkChild, eType, bArg2, bArg3);
            }
        }
    }
}

struct ChunkHeader
{
    unsigned int tag;
    unsigned int count;
    unsigned int key;
};

struct Rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int m_100;
};

struct Reader
{
    virtual void vfn_0(int);
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20(int, int);
    int m_04;
    int(__cdecl* m_08)(Reader*, ChunkHeader*, unsigned int, int*, int);
    int ReadBytes(Rec*, unsigned int);
    int Read(ChunkHeader* pvBuffer, unsigned int uiBytes)
    {
        int iComponentSize = 1;
        int iRead = m_08(this, pvBuffer, uiBytes, &iComponentSize, 1);
        m_04 += iRead;
        return iRead;
    }
};

struct SubObj
{
    void FUN_00a642a0(Rec*, Rec*);
};

struct Mgr
{
    Rec* Game_DoHeapAlloc(unsigned int);
    void MemoryManager_Deallocate(Rec*);
};

extern int DAT_011f6238;
extern "C" Reader* __cdecl FileFinder_GetFile_(int, int, int);

struct FUN_00b7fe40_cls
{
    unsigned int m_00;
    Rec* m_04;
    SubObj m_08;
    bool LoadFromReader(int param);
};

// Reads a chunk into an allocated record, then calls a helper on each subobject.
// @fnv 0x00b7fe40
bool FUN_00b7fe40_cls::LoadFromReader(int param)
{
    bool result = false;
    ChunkHeader buf;
    buf.tag = 0;
    buf.count = 0;
    buf.key = 0;
    if (param != 0)
    {
        Reader* obj = FileFinder_GetFile_(param, 0, 0);
        if (obj != 0)
        {
            obj->vfn_20(0, 0);
            int r = obj->Read(&buf, 12);
            if (r == 12 && buf.tag == 100)
            {
                m_04 = ((Mgr*)&DAT_011f6238)->Game_DoHeapAlloc(buf.key);
                if (obj->ReadBytes(m_04, buf.key) == (int)buf.key)
                {
                    Rec* pRecord = m_04;
                    result = true;
                    for (unsigned int i = 0; i < buf.count; ++i)
                    {
                        m_08.FUN_00a642a0(pRecord, pRecord);
                        pRecord = (Rec*)((char*)pRecord + pRecord->m_100 + 0x104);
                    }
                }
                else
                {
                    ((Mgr*)&DAT_011f6238)->MemoryManager_Deallocate(m_04);
                    m_04 = 0;
                }
            }
            obj->vfn_0(1);
        }
    }
    return result;
}

class CleanupRef : public NiRefObject
{
  public:
    void Release()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
namespace fnv_00b54630 {
struct CleanupHeap
{
    void MemoryManager_Deallocate(void*);
};
extern CleanupHeap DAT_011f6238;
}
inline void NP::operator=(CleanupRef* const& incoming)
{
    // Preserve typed reference access through the shared pointer storage.
    CleanupRef*& value = reinterpret_cast<CleanupRef*&>(p);
    if (value != incoming)
    {
        if (value)
            value->Release();
        value = incoming;
        if (value)
            ++value->m_uiRefCount;
    }
}
inline void NP::operator delete[](void* data)
{
    fnv_00b54630::DAT_011f6238.MemoryManager_Deallocate(data);
}
namespace fnv_00b54630 {
namespace CleanupState {
extern NP* DAT_011f9170;
extern unsigned int DAT_011f916c;
struct CleanupB
{
    void FUN_00b6f0b0();
    ~CleanupB()
    {
        FUN_00b6f0b0();
    }
    static void operator delete(void* data)
    {
        DAT_011f6238.MemoryManager_Deallocate(data);
    }
};
extern ImageSpaceManager* DAT_011f91ac;
extern CleanupB* DAT_011f91a8;
extern NiFixedString* DAT_011f94bc;
struct CleanupPool
{
    void MTRenderingSystem_DestroyThreads();
};
extern CleanupPool DAT_01200088;
extern bool DAT_011f91c6;
extern void* DAT_011f917c;
extern void* DAT_011f91e0;
extern char DAT_010ad6e8;
int BSsprintf(char*, unsigned int, const char*, ...);
void FUN_00b62a20();
void ClearCachedEntryMap();
void ParticleShader_Free();
void BoltShader_Free();
void ClearRefObject();
void Object_DoNothing();
extern NP DAT_011f950c;
extern NP DAT_011f9510;
extern NP DAT_011f9514;
extern NP DAT_011f9518;
extern NP DAT_011f951c;
extern NP DAT_011f9520;
extern NP DAT_011f9524;
extern NP DAT_011f9528;
extern NP DAT_011f952c;
extern NP DAT_011f9530;
extern NP DAT_011f9534;
extern NP DAT_011f9538;
extern NP DAT_011f953c;
extern NP DAT_011f9540;
extern NP DAT_011f9544;
extern NP DAT_011f95d4;
extern NP DAT_011f95ec;
extern NP DAT_011f95f0;
extern NP DAT_011f9508;
extern NP DAT_011f95d8;
extern NP DAT_011f9548[35];
// When all is true, clears cached references and deletes cleanup objects; always clears selected globals and releases the pointer array.
// @fnv 0x00b54630
// src: COMMUNITY 0x00b54630
void BSShaderManager_Free(bool all)
{
    if (all)
    {
        FUN_00b62a20();
        ClearCachedEntryMap();
        ParticleShader_Free();
        BoltShader_Free();
        ClearRefObject();
        DAT_011f950c = static_cast<CleanupRef*>(0);
        DAT_011f9510 = static_cast<CleanupRef*>(0);
        DAT_011f9514 = static_cast<CleanupRef*>(0);
        DAT_011f9518 = static_cast<CleanupRef*>(0);
        DAT_011f951c = static_cast<CleanupRef*>(0);
        DAT_011f9520 = static_cast<CleanupRef*>(0);
        DAT_011f9524 = static_cast<CleanupRef*>(0);
        DAT_011f9528 = static_cast<CleanupRef*>(0);
        DAT_011f952c = static_cast<CleanupRef*>(0);
        DAT_011f9530 = static_cast<CleanupRef*>(0);
        DAT_011f9534 = static_cast<CleanupRef*>(0);
        DAT_011f9538 = static_cast<CleanupRef*>(0);
        DAT_011f953c = static_cast<CleanupRef*>(0);
        DAT_011f9540 = static_cast<CleanupRef*>(0);
        DAT_011f9544 = static_cast<CleanupRef*>(0);
        DAT_011f95d4 = static_cast<CleanupRef*>(0);
        DAT_011f917c = 0;
        if (DAT_011f91ac)
        {
            delete DAT_011f91ac;
            DAT_011f91ac = 0;
        }
        if (DAT_011f91a8)
        {
            delete DAT_011f91a8;
            DAT_011f91a8 = 0;
        }
        DAT_011f95ec = static_cast<CleanupRef*>(0);
        for (int i = 0; i < 35; i++)
        {
            if (DAT_011f9548[i].p)
            {
                if (static_cast<CleanupRef*>(DAT_011f9548[i].p)->m_uiRefCount > 1)
                {
                    char message[255];
                    BSsprintf(message, 255, &DAT_010ad6e8, i, static_cast<CleanupRef*>(DAT_011f9548[i].p)->m_uiRefCount);
                }
                DAT_011f9548[i] = static_cast<CleanupRef*>(0);
            }
        }
        delete DAT_011f94bc;
        DAT_011f94bc = 0;
        DAT_011f91c6 = false;
        DAT_01200088.MTRenderingSystem_DestroyThreads();
        Object_DoNothing();
        DAT_011f95f0 = static_cast<CleanupRef*>(0);
    }
    DAT_011f9508 = static_cast<CleanupRef*>(0);
    DAT_011f91e0 = 0;
    DAT_011f95d8 = static_cast<CleanupRef*>(0);
    for (unsigned int i = 0; i < DAT_011f916c; i++)
        DAT_011f9170[i] = static_cast<CleanupRef*>(0);
    delete[] DAT_011f9170;
}
}
}  // namespace fnv_00b54630

extern "C" unsigned long __readfsdword(unsigned long);
struct ShaderTLS
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    int heap;
};
extern volatile unsigned int DAT_0126fd98;
inline ShaderTLS* GetShaderTLS()
{
    unsigned int index = DAT_0126fd98;
    return reinterpret_cast<ShaderTLS**>(__readfsdword(0x2c))[index];
}
extern __declspec(thread) ShaderTLS g_shaderTLS;
struct HeapScope
{
    int old;
    HeapScope(int heap)
    {
        old = g_shaderTLS.heap;
        g_shaderTLS.heap = heap;
    }
    ~HeapScope()
    {
        g_shaderTLS.heap = old;
    }
};

struct RefShader : NiRefObject
{
};

__forceinline bool ResetShaderPointer(NiPointer<RefShader>& pointer)
{
    if (pointer.m_pObject)
    {
        pointer.m_pObject->DecRefCount();
        pointer.m_pObject = 0;
        return true;
    }
    return false;
}

RefShader* __cdecl ShadowLightShader_CreateShader();
RefShader* __cdecl CreateShaderFadeNode();
RefShader* __cdecl DistantLODShader_CreateShader();
RefShader* __cdecl SpeedTreeBranchShader_CreateShader();
RefShader* __cdecl SpeedTreeFrondShader_CreateShader();
RefShader* __cdecl CreateSpeedTreeLeafShader();
RefShader* __cdecl FUN_00bd23f0();
RefShader* __cdecl SkyShader_CreateShader();
RefShader* __cdecl HairShader_CreateShader();
RefShader* __cdecl CreateFaceGenMorphShader();
RefShader* __cdecl ParallaxShader_CreateShader();
RefShader* __cdecl CreateGeometryDecalShader();
RefShader* __cdecl FUN_00b86de0();
RefShader* __cdecl FUN_00ba58b0();
RefShader* __cdecl FUN_00bc10e0();
RefShader* __cdecl FUN_00bc4af0();
RefShader* __cdecl FUN_00bbd0d0();
RefShader* __cdecl PrecipitationShader_CreateShader();
RefShader* __cdecl TileShader_CreateShader();
RefShader* __cdecl FUN_00bc93c0();
RefShader* __cdecl FUN_00bc59b0();
RefShader* __cdecl FUN_00b80e70();
RefShader* __cdecl CreateTreeShader();

// Returns the cached RefShader for the given index, lazily creating it via a switch on the index if it is not yet initialized.
// @fnv 0x00b55560
// src: XBOX_PDB 0x00b55560
Shader* __cdecl BSShaderManager_GetShader(void* aiIndex)
{
    if (!DAT_011f9508 || (unsigned int)aiIndex > 0x22)
        return 0;
    NiPointer<RefShader>* shaders = (NiPointer<RefShader>*)&DAT_011f9548;
    if (!shaders[(unsigned int)aiIndex].m_pObject)
    {
        HeapScope heapScope(5);
        switch ((unsigned int)aiIndex)
        {
        case 1:
            shaders[(unsigned int)aiIndex] = ShadowLightShader_CreateShader();
            break;
        case 2:
            shaders[(unsigned int)aiIndex] = CreateShaderFadeNode();
            break;
        case 3:
            shaders[(unsigned int)aiIndex] = DistantLODShader_CreateShader();
            break;
        case 4:
            BSShaderManager_GetShader((void*)1);
            shaders[(unsigned int)aiIndex] = SpeedTreeBranchShader_CreateShader();
            break;
        case 5:
            shaders[(unsigned int)aiIndex] = SpeedTreeFrondShader_CreateShader();
            break;
        case 6:
            shaders[(unsigned int)aiIndex] = CreateSpeedTreeLeafShader();
            break;
        case 9:
            shaders[(unsigned int)aiIndex] = FUN_00bd23f0();
            break;
        case 10:
            shaders[(unsigned int)aiIndex] = SkyShader_CreateShader();
            break;
        case 13:
            shaders[(unsigned int)aiIndex] = HairShader_CreateShader();
            break;
        case 14:
            shaders[(unsigned int)aiIndex] = CreateFaceGenMorphShader();
            break;
        case 15:
            shaders[(unsigned int)aiIndex] = ParallaxShader_CreateShader();
            break;
        case 16:
            shaders[(unsigned int)aiIndex] = CreateGeometryDecalShader();
            break;
        case 17:
            shaders[(unsigned int)aiIndex] = FUN_00b86de0();
            break;
        case 24:
            shaders[(unsigned int)aiIndex] = FUN_00ba58b0();
            break;
        case 25:
            shaders[(unsigned int)aiIndex] = FUN_00bc10e0();
            break;
        case 26:
            shaders[(unsigned int)aiIndex] = FUN_00bc4af0();
            break;
        case 29:
            if (DAT_011f94a6)
                shaders[(unsigned int)aiIndex] = FUN_00bbd0d0();
            else if (ResetShaderPointer(shaders[(unsigned int)aiIndex]))
                return (Shader*)shaders[(unsigned int)aiIndex].m_pObject;
            break;
        case 30:
            shaders[(unsigned int)aiIndex] = PrecipitationShader_CreateShader();
            break;
        case 32:
            shaders[(unsigned int)aiIndex] = TileShader_CreateShader();
            break;
        case 33:
            shaders[(unsigned int)aiIndex] = FUN_00bc93c0();
            break;
        case 34:
            shaders[(unsigned int)aiIndex] = FUN_00bc59b0();
            break;
        case 7:
            shaders[(unsigned int)aiIndex] = FUN_00b80e70();
            break;
        case 8:
            shaders[(unsigned int)aiIndex] = CreateTreeShader();
            break;
        }
    }
    return (Shader*)shaders[(unsigned int)aiIndex].m_pObject;
}

struct InitMemory
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern volatile unsigned int DAT_0126fd98;
extern __declspec(thread) ShaderTLS g_shaderTLS;
struct TextureManagerInit
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    TextureManagerInit();
    void SetShaderRenderer(NiRenderer*);
    static void* operator new(unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<InitMemory*>(&_g_memoryManager)->Deallocate(p);
    }
};
extern TextureManagerInit* DAT_011f91a8;
struct TextureLoaderInit
{
    void* source;
    unsigned int count;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    TextureLoaderInit(void*);
    ~TextureLoaderInit();
    void Load(void*);
    static void* operator new(unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
    static void operator delete(void* p)
    {
        reinterpret_cast<InitMemory*>(&_g_memoryManager)->Deallocate(p);
    }
};
extern TextureLoaderInit* DAT_011f9498;
void* GetTextureSource();
inline void* NiFixedString::operator new(size_t size)
{
    return _g_memoryManager.Allocate(size);
}
inline void NiFixedString::operator delete(void* data)
{
    _g_memoryManager.Deallocate(data);
}
extern NiFixedString* DAT_011f94bc;
extern bool DAT_011f91c6;
void InitShaders();
void InitShader(int);
inline NiColorA::NiColorA(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
{}
extern NiColorA DAT_011fa090;
extern const float DAT_01016248;
void ProcessCommands();
void InsertNodeAtHead();
void ThisCall_Ret1();
void AccumulateRenderPasses();
void Object_ProcessAndReturnValue_00b64440();
void AddEntriesToAccumulator();
void BSShaderAccumulator_RegisterObject_ConstAlpha();
void BSShaderAccumulator_FinishAccumulating_Standard();
void RenderAccumulationPasses();
void BSShaderAccumulator_FinishAccumulating_Interface();
void Object_DoNothing();
void BSShaderAccumulator_FinishAccumulating_WaterDepth();
struct GlobalShaderInit
{
    void FUN_00ba3720();
};
extern GlobalShaderInit DAT_01200088;
void InitializeShaderBufferTables();
extern void* DAT_011f94f0;
extern void* DAT_011a9608;
extern void* DAT_011ffe2c;
extern unsigned int DAT_011ffe30;
extern unsigned int DAT_011f916c;
extern unsigned int DAT_011f9168;
struct AccumulatorInit : NiRefObject
{
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    AccumulatorInit(int, unsigned int, unsigned int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct AccumPointerInit
{
    AccumulatorInit* object;
    AccumPointerInit();
    ~AccumPointerInit();
    static void* operator new[](unsigned int n)
    {
        return _g_memoryManager.Allocate(n);
    }
    static void operator delete[](void* p)
    {
        reinterpret_cast<InitMemory*>(&_g_memoryManager)->Deallocate(p);
    }
    void operator=(AccumulatorInit* p)
    {
        if (object != p)
        {
            if (object)
                object->DecRefCount();
            object = p;
            if (p)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        }
    }
};
extern AccumPointerInit* accumulators;
extern "C" void* __cdecl memset(void*, int, unsigned int);
__forceinline void ClearCallbackTables()
{
    memset(DAT_011f9f40 + 0, 0, 8);
    memset(DAT_011f9f40 + 2, 0, 8);
    memset(DAT_011f9f40 + 4, 0, 8);
    memset(DAT_011f9f40 + 6, 0, 8);
    memset(DAT_011f9f40 + 8, 0, 8);
    memset(DAT_011f9f40 + 10, 0, 8);
    memset(DAT_011f9f40 + 12, 0, 8);
    memset(DAT_011f9f40 + 14, 0, 8);
    memset(DAT_011f9f80 + 0, 0, 8);
    memset(DAT_011f9f80 + 2, 0, 8);
    memset(DAT_011f9f80 + 4, 0, 8);
    memset(DAT_011f9f80 + 6, 0, 8);
    memset(DAT_011f9f80 + 8, 0, 8);
    memset(DAT_011f9f80 + 10, 0, 8);
    memset(DAT_011f9f80 + 12, 0, 8);
    memset(DAT_011f9f80 + 14, 0, 8);
}
// Initializes the texture manager, shaders, image manager, and callback tables, then allocates and initializes the accumulator array.
// @fnv 0x00b57420
void InitRenderSystem()
{
    {
        HeapScope heap(5);
        if (!DAT_011f91c6)
        {
            DAT_011f91a8 = new TextureManagerInit;
            DAT_011f9498 = new TextureLoaderInit(GetTextureSource());
            DAT_011f9498->Load(DAT_011f9498->source);
            if (!DAT_011f9498->count)
            {
                delete DAT_011f9498;
                DAT_011f9498 = 0;
            }
            InitShaders();
            DAT_011fa090 = NiColorA(DAT_01016248, DAT_01016248, DAT_01016248, 1.0f);
            if (DAT_011f9508)
            {
                for (int shader = 1; shader < 35; ++shader)
                    InitShader(shader);
                DAT_011f91ac = new ImageSpaceManager;
                if (DAT_011f9498)
                {
                    delete DAT_011f9498;
                    DAT_011f9498 = 0;
                }
            }
            RegisterNiStreamFactories();
            DAT_011f91a8->SetShaderRenderer(DAT_011f9508);
            DAT_011f94bc = new NiFixedString("TEX%");
            DAT_011f91c6 = true;
        }
        ClearCallbackTables();
        reinterpret_cast<void (**)()>(DAT_011f9f80)[0] = ProcessCommands;
        reinterpret_cast<void (**)()>(DAT_011f9f80)[10] = InsertNodeAtHead;
        reinterpret_cast<void (**)()>(DAT_011f9f80)[11] = ThisCall_Ret1;
        reinterpret_cast<void (**)()>(DAT_011f9f80)[13] = AccumulateRenderPasses;
        reinterpret_cast<void (**)()>(DAT_011f9f80)[9] = Object_ProcessAndReturnValue_00b64440;
        reinterpret_cast<void (**)()>(DAT_011f9f80)[14] = AddEntriesToAccumulator;
        reinterpret_cast<void (**)()>(DAT_011f9f80)[8] = BSShaderAccumulator_RegisterObject_ConstAlpha;
        reinterpret_cast<void (**)()>(DAT_011f9f40)[0] = BSShaderAccumulator_FinishAccumulating_Standard;
        DAT_011f9f3c = ProcessCommands;
        reinterpret_cast<void (**)()>(DAT_011f9f40)[12] = RenderAccumulationPasses;
        reinterpret_cast<void (**)()>(DAT_011f9f40)[10] = BSShaderAccumulator_FinishAccumulating_Interface;
        reinterpret_cast<void (**)()>(DAT_011f9f40)[13] = Object_DoNothing;
        reinterpret_cast<void (**)()>(DAT_011f9f40)[14] = BSShaderAccumulator_FinishAccumulating_WaterDepth;
        DAT_011f9f38 = BSShaderAccumulator_FinishAccumulating_Standard;
        DAT_011ffe2c = 0;
        DAT_011ffe30 = 0;
        DAT_01200088.FUN_00ba3720();
        InitializeShaderBufferTables();
        DAT_011a9608 = DAT_011f94f0;
        accumulators = new AccumPointerInit[DAT_011f916c];
        for (unsigned int index = 0; index < DAT_011f916c; ++index)
        {
            accumulators[index] = new AccumulatorInit(99, 1, 759);
        }
    }
    DAT_011f9168 = 0;
}

struct TangentAllocatorView
{
    void MemoryManager_Deallocate(void*);
};
extern MemoryManager _g_memoryManager;
extern "C" void* Object_DispatchCommandFour(unsigned int);
// Local arithmetic helpers retain the original trivial vector-copy behavior.
struct TangentPoint3
{
    float x, y, z;
    TangentPoint3() {}
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }
    TangentPoint3(float px, float py, float pz) : x(px), y(py), z(pz) {}
    TangentPoint3 operator*(float k) const
    {
        TangentPoint3 r(x * k, y * k, z * k);
        return r;
    }
    TangentPoint3 operator-(const TangentPoint3& p) const
    {
        TangentPoint3 r(x - p.x, y - p.y, z - p.z);
        return r;
    }
    float Dot(const TangentPoint3& p) const { return x * p.x + y * p.y + z * p.Z(); }
    TangentPoint3 Cross(const TangentPoint3& p) const
    {
        TangentPoint3 r(y * p.Z() - Z() * p.y, Z() * p.x - x * p.Z(), x * p.y - y * p.x);
        return r;
    }
    TangentPoint3& operator+=(const TangentPoint3& p)
    {
        x = X() + p.X();
        y = y + p.Y();
        z = z + p.Z();
        return *this;
    }
    // Returning the value preserves the original x87 accumulation order when inlined.
    TangentPoint3 __fastcall AddBinormal(const TangentPoint3& p)
    {
        float sx = p.x;
        x = x + sx;
        y = Y() + p.Y();
        z += p.Z();
        return *this;
    }
    void Unitize_004a0c10();
    static void* operator new[](unsigned int bytes)
    {
        return _g_memoryManager.Allocate(bytes);
    }
};
struct NativeB66810 : NiRefObject
{
    bool owned;
    unsigned char unk09, unk0a, unk0b;
    TangentPoint3* first;
    TangentPoint3* second;
    static void* operator new(unsigned int n)
    {
        return Object_DispatchCommandFour(n);
    }
    TangentPoint3* GetFirst() const
    {
        return first;
    }
    TangentPoint3* GetSecond() const
    {
        return second;
    }
    NativeB66810(bool);
    virtual ~NativeB66810();
};
inline unsigned short NiGeometryData::GetVertexCount() const
{
    return m_usVertices;
}
inline unsigned short NiGeometryData::GetUVSetCount() const
{
    return m_usDataFlags & 1;
}
inline NiGeometryData* NiGeometry::GetData() const
{
    return m_spModelData.m_pObject;
}
inline const char* NiGeometry::GetName() const
{
    return m_kName.m_kHandle;
}
inline unsigned short NiGeometry::GetVertexCount() const
{
    return static_cast<const NiGeometryData*>(GetData())->GetVertexCount();
}
inline unsigned short* NiTriBasedGeom::GetStripIndices()
{
    return m_spModelData.m_pObject->FUN_00a75f10();
}
inline void NiTriBasedGeom::GetTriangle(unsigned short i, unsigned short& a, unsigned short& b, unsigned short& c)
{
    static_cast<NiTriBasedGeomData*>(m_spModelData.m_pObject)->GetTriangleIndices(i, &a, &b, &c);
}
extern const char DAT_0102bf34[];
extern const char DAT_010ad7a8[];
extern const char DAT_010ad730[];
extern "C" void* memmove(void*, const void*, unsigned int);
extern "C" void* FUN_00ec61c0(void*, int, unsigned int);
// Copies tangent and binormal data from extra data when present; otherwise computes per-vertex vectors from UVs and normals and updates geometry data.
// @fnv 0x00b54b60
// src: EXE 0x00b54b60
NativeB66810* __cdecl BSShaderManager_CreateTangentSpaceSimple(NiGeometry* apGeometry)
{
    if (apGeometry->GetName())
        _strnicmp(apGeometry->GetName(), DAT_0102bf34, 4);
    NativeB66810* result = new NativeB66810(true);
    NiBinaryExtraData* pExtraData =
        reinterpret_cast<NiBinaryExtraData*>(apGeometry->FUN_00a5bdd0(NiFixedString(NiGlobalStringTable::AddString(DAT_010ad7a8), 0)));
    if (pExtraData)
    {
        unsigned count = static_cast<const NiGeometry*>(apGeometry)->GetVertexCount();
        char* secondData = pExtraData->m_pData;
        unsigned bytes = count * sizeof(TangentPoint3);
        char* firstData = secondData + bytes;
        result->first = new TangentPoint3[count];
        result->second = new TangentPoint3[count];
        memmove(result->GetFirst(), firstData, bytes);
        memmove(result->GetSecond(), secondData, bytes);
        apGeometry->DeleteExtraDataByKey(NiFixedString(NiGlobalStringTable::AddString(DAT_010ad7a8), 0));
        return result;
    }
    if (!apGeometry->IsTriBasedGeometry())
        return 0;
    NiTriBasedGeom* pTriBasedGeom = apGeometry->IsTriBasedGeometry();
    NiTriBasedGeomData* data = static_cast<NiTriBasedGeomData*>(pTriBasedGeom->m_spModelData.m_pObject);
    unsigned short usTriangleCount = data->m_usTriangles;
    unsigned short count = data->m_usVertices;
    TangentPoint3* positions = reinterpret_cast<TangentPoint3*>(data->m_pkVertex);
    TangentPoint3* normals = reinterpret_cast<TangentPoint3*>(data->m_pkNormal);
    NiPoint2* pUVCoords = data->m_pkTexture;
    bool bIsTriStrips = pTriBasedGeom->IsTriStrips() != 0;
    unsigned short* indices = 0;
    if (bIsTriStrips)
        indices = pTriBasedGeom->GetStripIndices();
    if (!normals)
    {
        char text[256];
        sprintf_s(text, 255, DAT_010ad730);
        return 0;
    }
    TangentPoint3* pTangentAccum = new TangentPoint3[2 * count];
    TangentPoint3* pBinormalAccum = pTangentAccum + count;
    FUN_00ec61c0(pTangentAccum, 0, 2 * count * sizeof(TangentPoint3));
    TangentPoint3* replacement = new TangentPoint3[3 * count];
    TangentPoint3* binormals = replacement + count;
    TangentPoint3* tangents = replacement + 2 * count;
    memmove(replacement, normals, count * sizeof(TangentPoint3));
    unsigned short* pIndexCursor = indices;
    bool flip = false;
    for (unsigned short t = 0; t < usTriangleCount; ++t, ++pIndexCursor)
    {
        unsigned short a, b, c;
        if (bIsTriStrips)
        {
            a = pIndexCursor[0];
            b = pIndexCursor[1];
            c = pIndexCursor[2];
            if (flip)
            {
                unsigned short temp = c;
                c = a;
                a = temp;
            }
            flip = !flip;
        }
        else
            pTriBasedGeom->GetTriangle(t, a, b, c);
        if (a == b || b == c || a == c)
            continue;
        const TangentPoint3& pa = positions[a];
        const TangentPoint3& pb = positions[b];
        const TangentPoint3& pc = positions[c];
        float x1 = pb.x - pa.x, x2 = pc.x - pa.x;
        float y1 = pb.y - pa.y, y2 = pc.y - pa.y;
        float z1 = pb.z - pa.z, z2 = pc.z - pa.z;
        // The approved NiPoint2 header does not name the float UV components.
        float s1 = reinterpret_cast<const float*>(pUVCoords + b)[0] - reinterpret_cast<const float*>(pUVCoords + a)[0],
              s2 = reinterpret_cast<const float*>(pUVCoords + c)[0] - reinterpret_cast<const float*>(pUVCoords + a)[0];
        float t1 = reinterpret_cast<const float*>(pUVCoords + b)[1] - reinterpret_cast<const float*>(pUVCoords + a)[1],
              t2 = reinterpret_cast<const float*>(pUVCoords + c)[1] - reinterpret_cast<const float*>(pUVCoords + a)[1];
        float r = 1.0f / (s1 * t2 - t1 * s2);
        TangentPoint3 binormal;
        TangentPoint3 tangent((t2 * x1 - t1 * x2) * r, (t2 * y1 - t1 * y2) * r, (t2 * z1 - t1 * z2) * r);
        binormal = TangentPoint3((s1 * x2 - s2 * x1) * r, (s1 * y2 - s2 * y1) * r, (s1 * z2 - s2 * z1) * r);
        {
            TangentPoint3& dest = pTangentAccum[a];
            dest += tangent;
        }
        {
            TangentPoint3& dest = pTangentAccum[b];
            dest += tangent;
        }
        pTangentAccum[c] += tangent;
        pBinormalAccum[a].AddBinormal(binormal);
        pBinormalAccum[b].AddBinormal(binormal);
        pBinormalAccum[c] += binormal;
    }
    for (unsigned short i = 0; i < count; ++i)
    {
        float dot = normals[i].Dot(pTangentAccum[i]);
        tangents[i] = pTangentAccum[i] - normals[i] * dot;
        binormals[i] = normals[i].Cross(tangents[i]);
        tangents[i].Unitize_004a0c10();
        binormals[i].Unitize_004a0c10();
    }
    reinterpret_cast<TangentAllocatorView&>(_g_memoryManager).MemoryManager_Deallocate(pTangentAccum);
    NiGeometryData* pDestGeomData = apGeometry->m_spModelData.m_pObject;
    reinterpret_cast<TangentAllocatorView&>(_g_memoryManager).MemoryManager_Deallocate(pDestGeomData->m_pkNormal);
    pDestGeomData->NiGeometryData_ReplaceData(count, reinterpret_cast<TangentPoint3*>(pDestGeomData->m_pkVertex), replacement, pDestGeomData->m_pkColor,
                                pDestGeomData->m_pkTexture, pDestGeomData->GetUVSetCount(), 0x1000);
    delete result;
    return 0;
}
