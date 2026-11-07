// fallout_shared/sky/clouds.cpp: Clouds (10 functions)

#include "clouds_decls.h"
#include "../../../include/Sky.h"
#include "../../../include/NiPoint3.h"

// @fnv 0x00634110
void Clouds::Update(Sky* sky, float time)
{
    SkyObject::Update(sky, time);
    TESWeather* m_pWeatherObject = sky->TESMain_GetThread();
    TESWeather* m_pPreviousWeather = sky->FUN_00825c00();
    if (!m_pWeatherObject)
        return;
    for (int i = 0; i < GetOffset58(); ++i)
        if (!m_pCloudLayerGeometry[i])
            return;
    if (sky->Sky_GetMode() == 3 || sky->Sky_GetMode() == 2)
    {
        for (int i = 0; i < GetOffset58(); ++i)
        {
            float speed;
            float delta;
            CloudsColorController* controller =
                (!m_pCloudLayerGeometry[i]->FUN_0050d100()->GetControllers()
                     ? false
                     : m_pCloudLayerGeometry[i]->FUN_0050d100()->GetControllers()->FUN_00441110() == 13)
                    ? (CloudsColorController*)m_pCloudLayerGeometry[i]->FUN_0050d100()->GetControllers()
                    : 0;
            if (controller)
            {
                NiColor color = GetPointAt(i);
                controller->color = NiColorA(color.r, color.g, color.b, 1.0f);
            }
            speed = m_pWeatherObject->GetCloudLayerSpeed(i, DAT_011cca6c.Float()->f, 0.0f);
            if (m_pPreviousWeather)
            {
                speed *= sky->Sky_GetCurrentWeatherPct();
                speed += (1.0f - sky->Sky_GetCurrentWeatherPct()) *
                         m_pPreviousWeather->GetCloudLayerSpeed(i, DAT_011cca6c.Float()->f, 0.0f);
            }
            delta = sky->GetFieldCC() * time * speed;
            AddToFloatArray((unsigned short)i, delta);
        }
    }
    if (sky->GetWeatherUpdateFlag() || bForceUpdate)
    {
        bForceUpdate = false;
        if (m_pPreviousWeather)
        {
            for (int i = 0; i < GetOffset58(); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)m_pCloudLayerGeometry[i]->GetProperty(3);
                TESTexture1024* pkTexture = m_pWeatherObject->GetCloudTexture(i);
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->GetTextureResourcePath();
                    path += pkTexture->GetTextureResourceName();
                    sky->GetTextureManager();
                    SkyTextureManager::LoadTextureFromPath(&m_pCloudLayerTexture[i], path);
                }
                else
                    m_pCloudLayerTexture[i] = 0;
            }
        }
        else if (sky->Sky_GetMode() == 3 || sky->Sky_GetMode() == 2)
        {
            for (int i = 0; i < GetOffset58(); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)m_pCloudLayerGeometry[i]->GetProperty(3);
                TESTexture1024* pkTexture = m_pWeatherObject->GetCloudTexture(i);
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->GetTextureResourcePath();
                    path += pkTexture->GetTextureResourceName();
                    NiPointer<NiTexture> loaded = 0;
                    BSShaderManager::GetTexture(path, true, loaded, true, false);
                    NiTexture* raw = loaded;
                    if (raw)
                    {
                        property->SetTexture(raw);
                        property->SetTextureFile(NiFixedString(path));
                        property->SkyShaderProperty_SetBlendValue(0.0f);
                    }
                }
            }
        }
    }
    for (int i = 0; i < GetOffset58(); ++i)
    {
        SkyShaderProperty* property;
        NiProperty* baseProperty = m_pCloudLayerGeometry[i]->GetProperty(3);
        property = NiObject_DynamicCast(&DAT_012005b8, baseProperty);
        if (m_pCloudLayerTexture[i])
        {
            if (property)
            {
                property->NiPhysXProp_SetSnapshot(m_pCloudLayerTexture[i]);
                property->SkyShaderProperty_SetBlendValue(sky->Sky_GetCurrentWeatherPct());
            }
            if (!m_pPreviousWeather)
            {
                property->SetTexture(m_pCloudLayerTexture[i]);
                m_pCloudLayerTexture[i] = 0;
                property->NiPhysXProp_SetSnapshot(0);
                property->SkyShaderProperty_SetBlendValue(0.0f);
            }
        }
        m_pCloudLayerGeometry[i]->FUN_00450f90(!property || !property->BGSCameraShot_GetImagespaceTarget());
    }
}

// Loads Clouds.nif, attaches its 3D to parent, adds each geometry child to the cloud node, and sets the layer count.
// @fnv 0x00633ed0
void Clouds::Initialize(NiNode* parent)
{
    SkyObject::Initialize(parent);
    BSStream stream;
    if (stream.BSStream_Load("Meshes\\Sky\\Clouds.nif", false))
    {
        Model kModel("Meshes\\Sky\\Clouds.nif", &stream, false, false);
        struct LayerBuild
        {
            int layers;
            NiNode* root;
            int children;
        } build;
        build.root = kModel.GetObject3D();
        parent->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)m_pRootNode, true);
        build.layers = 0;
        build.children = build.root->NiNode_GetChildCount();
        for (int i = 0; i < build.children; ++i)
        {
            if (build.root->FUN_0043b4a0(i)->IsGeometry())
            {
                m_pCloudLayerGeometry[i] = (NiGeometry*)build.root->FUN_0043b4a0(i);
                m_pRootNode->AttachChildInAvailableSlot((NiAVObject*)(NiGeometry*)m_pCloudLayerGeometry[i], true);
                ++build.layers;
            }
        }
        SetCloudCount(build.layers);
    }
}

// @fnv 0x006340e0
void Clouds::SetCloudCount(int count)
{
    if (count > 4)
        count = 4;
    m_usCloudCount = (unsigned short)count;
}

// @fnv 0x00634870
// src: XBOX_PDB 0x00634870
bool Sky::GetWeatherUpdateFlag()
{
    return (0 < (uiFlags & 3));
}

// @fnv 0x00634890
SkyTextureManager* Sky::GetTextureManager()
{
    return &SkyController;
}

// Assigns the fixed string to the cloud texture path at offset 0x74.
// @fnv 0x00634900
// src: XBOX_PDB 0x00634900
void SkyShaderProperty::SetTextureFile(const NiFixedString& aFilename)
{
    *(BSStringT<char>*)((char*)this + 0x74) = aFilename;
}

// @fnv 0x009c8680
// src: XBOX_PDB 0x009c8680
NiTexture* SkyShaderProperty::BGSCameraShot_GetImagespaceTarget()
{
    return (NiTexture*)((BSStringT<char>*)((char*)this + 0x70))->operator const char*();
}

// @fnv 0x00633e00
void __fastcall InitializeCloudColor(NiColor* color)
{
    reinterpret_cast<NiPoint3*>(color)->Set(0.0f, 0.0f, 0.0f);
}

// The shared Clouds interface does not yet declare the geometry reset method.
void __fastcall ClearCloudGeometry(Clouds*);

// @fnv 0x00633e30
Clouds::~Clouds()
{
    ClearCloudGeometry(this);
    ClearCloudLayers();
}
