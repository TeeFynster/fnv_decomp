#include "../../../include/SettingT.h"
// fallout_shared/sky/stars.cpp: Stars (7 functions)

#include "../../../include/BSStringT.h"
#include "../../../include/SkyObject.h"
#include "../../../include/SkyShaderProperty.h"
#include "../../../include/Stars.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiNode.h"
#include "../../../include/TESWaterForm.h"
#include "../../../include/BSAudio.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/BSStream.h"
#include "../../../include/NiQuaternion.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/Sky.h"
#include "../../../include/SETTING_VALUE.h"
#include "../../../include/BGSTerrainManager.h"
// @fnv 0x0063fd90
void Stars::Initialize(NiNode* node)
{
    SkyObject::Initialize(node);
}


// @fnv 0x0043fa80
// src: XBOX_PDB 0x0043fa80
void NiAVObject::SetRotate_0043fa80(const NiMatrix3& kRot)
{
    m_kLocal.m_Rotate = kRot;
}

struct blob16
{
    char b[16];
};
typedef char _sizecheck_NiQuaternion[sizeof(NiQuaternion) == 16 ? 1 : -1];

// @fnv 0x004f0160
// src: COMMUNITY 0x004f0160
void NiAVObject::NiNode_SetRotate(const NiQuaternion& rotation)
{
    const_cast<NiQuaternion&>(rotation).ToRotationMatrix(&m_kLocal.m_Rotate);
}

class GameSettingCollection;
namespace fnv_00640020 {
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

using ::SettingT;
class GlobalObject_0040e0b0 : public SettingT<GameSettingCollection>
{
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting79;
extern GlobalObject_0040e0b0 g_011ccdc4;
extern GlobalObject_0040e0b0 g_011ccddc;
extern GlobalObject_0040e0b0 g_011cce30;
class Calendar
{
  public:
    unsigned int GetGameDaysPassed();
};
extern Calendar g_calendar;
float __cdecl fmodf(float, float);

}  // namespace fnv_00640020

// Updates the stars node's fade alpha from the sky hour, recolors star geometry, and rotates the stars node by the elapsed game time.
// @fnv 0x00640020
void Stars::Update(Sky* apSky, float afSecondsPassed)
{
    using namespace fnv_00640020;
    if (!apSky->GetAudioBackendData())
        return;
    float fhour = apSky->GetFieldEC();
    fAlpha = 0.0f;
    static NiPoint3 lastColor(0.0f, 0.0f, 0.0f);
    SkyObject::Update(apSky, afSecondsPassed);
    if (apSky->Sky_GetMode() == 3 || apSky->Sky_GetMode() == 2)
    {
        if (!((NiAVObject*)(NiNode*)m_pRootNode)->GetDisplayObject())
        {
            ((NiAVObject*)(NiNode*)m_pRootNode)->SetAppCulled(true);
            return;
        }
        float fSunsetBegin = apSky->Sky_GetSunsetBegin();
        float fSunsetEnd = apSky->GetEndSunsetColors();
        float fSunriseEnd = apSky->Sky_GetSunriseEnd();
        float fSunriseBegin = apSky->GetBeginSunriseColors();
        float fBeginFadeIn = fSunsetEnd - (fSunsetEnd - fSunsetBegin) * 0.5f;
        float fEndFadeOut = fSunriseEnd - (fSunriseEnd - fSunriseBegin) * 0.5f;
        if (fSunriseBegin < fhour && fhour < fEndFadeOut)
            fAlpha = (fEndFadeOut - fhour) / (fEndFadeOut - fSunriseBegin);
        else if (fEndFadeOut <= fhour && fhour <= fBeginFadeIn)
            fAlpha = 0.0f;
        else if (fBeginFadeIn < fhour && fhour < fSunsetEnd)
            fAlpha = (fhour - fBeginFadeIn) / (fSunsetEnd - fBeginFadeIn);
        else
            fAlpha = 1.0f;
        if (fAlpha > 0.0)
        {
            ((NiAVObject*)(NiNode*)m_pRootNode)->SetAppCulled(false);
            NiPoint3 colorThisFrame = *(NiPoint3*)((TESWaterForm*)apSky)->Sky_GetStarsColor();
            NiGeometry* pstarsgeo = 0;
            NiAVObject* pchild = 0;
            unsigned int icount = (NiNode*)m_pStarsNode ? ((NiNode*)m_pStarsNode)->NiNode_GetChildCount() : 0;
            for (unsigned int i = 0; i < icount; i++)
            {
                pchild = ((NiNode*)m_pStarsNode)->GetAt(i);
                if (pchild)
                {
                    pstarsgeo = pchild->IsGeometry();
                    if (pstarsgeo)
                    {
                        SkyShaderProperty* pStarsProp =
                            (pstarsgeo->GetProperty(3) == 0
                                 ? 0
                                 : ((BGSTerrainManager*)pstarsgeo->GetProperty(3))->GetMinLevel() == 13)
                                ? (SkyShaderProperty*)pstarsgeo->GetProperty(3)
                                : 0;
                        if (pStarsProp)
                        {
                            if (lastColor != colorThisFrame)
                            {
                                *(float*)(pStarsProp->propertyData + 0x60) = colorThisFrame.x;
                                *(float*)(pStarsProp->propertyData + 0x64) = colorThisFrame.y;
                                *(float*)(pStarsProp->propertyData + 0x68) = colorThisFrame.z;
                            }
                            *(float*)(pStarsProp->propertyData + 0x6c) = fAlpha;
                        }
                    }
                }
            }
            lastColor = colorThisFrame;
            float felapsed = g_calendar.GetGameDaysPassed() + apSky->GetFieldEC() / 24.0;
            float fangle = fmodf(felapsed, originalRuntimeFloatSetting79.Float()[0]) * 6.2831854820251465 /
                           originalRuntimeFloatSetting79.Float()[0];
            NiPoint3 axis(g_011ccdc4.Float()[0], g_011cce30.Float()[0], g_011ccddc.Float()[0]);
            axis.ComputeMagnitude();
            if ((NiNode*)m_pStarsNode)
                ((NiNode*)m_pStarsNode)->SetLocalRotation(fangle, axis.x, axis.y, axis.z);
        }
        else
        {
            ((NiAVObject*)(NiNode*)m_pRootNode)->SetAppCulled(true);
        }
    }
}
// @fnv 0x0063fd20
Stars::~Stars()
{
    m_pStarsNode = 0;
}

// Minimal interfaces used by the stars model loader.
class Model
{
  public:
    unsigned int unk00, unk04, unk08;
    NiNode* object;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
    NiNode* GetObject3D();
};
extern const char* const DAT_011f4428;
bool __cdecl NiObject_IsKindOf(const void*, NiNode*);
void __cdecl FNV_Warning(const char*);
// @fnv 0x0063fdb0
// src: XBOX_PDB 0x0063fdb0
void Stars::LoadGeometry(const char* path)
{
    if (!path || !*path)
    {
        m_pRootNode->NiAVObject_SetDisplayObject(false);
        return;
    }
    BSStringT<char> fileName;
    fileName.PrintfString("%s%s%s", "Meshes", "\\", path);
    {
        BSStream stream;
        if (!stream.BSStream_Load(fileName, false) || stream.GetRefAt21C() != 1 ||
            !NiObject_IsKindOf(&DAT_011f4428, stream.GetStringAt(0)))
        {
            FNV_Warning("DEFAULT: Cannot load the stars.");
            m_pRootNode->NiAVObject_SetDisplayObject(false);
            return;
        }
        Model model(fileName, &stream, true, false);
        m_pRootNode->NiAVObject_SetDisplayObject(true);
        m_pRootNode->RemoveObject(m_pStarsNode);
        m_pStarsNode = model.GetObject3D();
        m_pStarsNode->NiAVObject_SetSelectiveUpdate(true);
        m_pRootNode->AttachChildInAvailableSlot((NiAVObject*)(NiNode*)m_pStarsNode, true);
        m_pStarsNode->UpdateProperties();
    }
}
