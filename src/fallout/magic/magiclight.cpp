#include "../../../include/TESForm.h"
#include "../../../include/GO.h"
#include "../../../include/NiColor.h"
#include "../../../include/NiPointLight.h"
#include "../../../include/ShadowSceneNode.h"
#include "../../../include/TESObjectLIGH.h"

// src/fallout/magic/magiclight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magiclight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_0081c470_shell
{
    char pad0[0x10];
    float m_fFadeInTime;
    float m_fFadeOutTime;
    bool bFadeInActive;
    void MagicLight_Fade(bool abIn, float afTime);
};

// @fnv 0x0081c470
// src: XBOX_PDB 0x0081c470
void FUN_0081c470_shell::MagicLight_Fade(bool abIn, float afTime)
{
    bFadeInActive = abIn;
    m_fFadeOutTime = afTime;
    m_fFadeInTime = 0.0f;
}

// The shared form has no declaration for this light-update operation yet.
// Inherit its checked layout and declare only the missing operation here.
class MagicLightFormOperations : public TESObjectLIGH
{
  public:
    void UpdatePointLight(GO* pData, int iFlag);
};

extern double _DAT_01012060;

struct MagicEffectCollection
{
    void* pVTable;
    TESObjectLIGH* m_pFadeTarget;
    GO m_go;
    unsigned int m_uiRefCount;
    float m_fFadeInTime;
    float m_fFadeOutTime;
    bool bFadeInActive;

    void UpdateLightFade(float fTimeSinceScaleStart);
};

// @fnv 0x0081c320
void MagicEffectCollection::UpdateLightFade(float fTimeSinceScaleStart)
{
    float flightScale;
    unsigned int ucolor;
    // The original uses uninitialized color storage and calls Set before reading it.
    float color[3];

    if (m_pFadeTarget)
    {
        if (m_fFadeOutTime > _DAT_01012060)
        {
            m_fFadeInTime += fTimeSinceScaleStart;

            ucolor = m_pFadeTarget->GetColor();

            reinterpret_cast<NiPoint3&>(color).Set(static_cast<float>(static_cast<unsigned char>(ucolor & 0xff)),
                      static_cast<float>(static_cast<unsigned char>((static_cast<unsigned short>(ucolor) >> 8) & 0xff)),
                      static_cast<float>(static_cast<unsigned char>((ucolor >> 16) & 0xff)));

            if (bFadeInActive)
                flightScale = m_fFadeInTime / m_fFadeOutTime;
            else
                flightScale = 1.0f - m_fFadeInTime / m_fFadeOutTime;

            if (flightScale > 1.0)
            {
                m_fFadeOutTime = 0.0f;
                flightScale = 1.0f;
            }
            else if (flightScale < _DAT_01012060)
            {
                m_fFadeOutTime = 0.0f;
                flightScale = 0.0f;
            }

            reinterpret_cast<NiColor&>(color) *= flightScale / 255.0;

            reinterpret_cast<NiPointLight*>(m_go.operator unsigned int())->SetEffectColor(reinterpret_cast<const NiPoint3&>(color));
        }

        static_cast<MagicLightFormOperations*>(m_pFadeTarget)->UpdatePointLight(&m_go, 0);
    }
}

class S4ee810
{
  public:
    S4ee810(int iValue);
    ~S4ee810();
    int unk00;
};

class PathingSolution;

// Exe 0x0066b0d0 / 0x0045cec0: shared retain/release and destructor; scene references use an erased NiRefObject pointee.
#include "../../../include/NiRefObject.h"
#include "../../../include/NiPointer.h"
template <> NiPointer<NiRefObject>::NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
template <> NiPointer<NiRefObject>::~NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
template <> NiPointer<NiRefObject>& NiPointer<NiRefObject>::operator=(NiRefObject*) FNV64_NIPOINTER_EXCEPTION_SPEC;


class FUN_0081bf80 : public S4ee810
{
  public:
    FUN_0081bf80(int a, int b);
    void Init(int a, int b);

    int m_iFadeIndex;
    NiPointer<NiRefObject> m_kSolution;
    float m_fScale;
    float m_fValue0;
    float m_fValue1;
    bool m_bDone;
};

// Initialises the base with 0, clears the solution reference, sets scale to 1.0, clears the done flag and values, then calls Init(a, b).
// @fnv 0x0081bf80
FUN_0081bf80::FUN_0081bf80(int a, int b) : S4ee810(0)
{
    m_iFadeIndex = 0;
    m_kSolution.operator=(static_cast<NiRefObject*>(0));
    m_fScale = 1.0f;
    m_bDone = false;
    m_fValue0 = 0.0f;
    m_fValue1 = 0.0f;
    Init(a, b);
}


TESForm* __cdecl MLLookupFormByID(unsigned int auiFormID);

struct MLPoint3
{
    float x;
    float y;
    float z;

    MLPoint3(float afX, float afY, float afZ);
    MLPoint3& operator/=(float afScale);
};

template <class T> struct MLPointer
{
    T* m_pObject;

    MLPointer& operator=(T* apObject);
    operator T*() const;
};

ShadowSceneNode* __cdecl MLGetShadowSceneNode(int aiIndex);

extern float g_fMagicLightAttenuation;

struct MagicLightObject
{
    MLPointer<NiNode> m_pController;
    TESObjectLIGH* pLightForm;
    MLPointer<NiPointLight> m_pMenuLight;
    float fFadeAmount;

    void CreatePointLight(unsigned int auiFormID, NiNode* apNode);
};

// @fnv 0x0081c030
void MagicLightObject::CreatePointLight(unsigned int auiFormID, NiNode* apNode)
{
    TESForm* pForm2 = MLLookupFormByID(auiFormID);
    pLightForm = dynamic_cast<TESObjectLIGH*>(pForm2);
    if (pLightForm)
    {
        m_pMenuLight = new NiPointLight;
        fFadeAmount = 1.0f;
        unsigned int uiColor = pLightForm->GetColor();
        MLPoint3 kDiffuseColor((unsigned char)(uiColor & 0xff), (unsigned char)(((unsigned short)uiColor >> 8) & 0xff),
                               (unsigned char)((uiColor >> 16) & 0xff));
        kDiffuseColor /= 255.0f;
        ((NiPointLight*)m_pMenuLight)->SetEffectColor(reinterpret_cast<const NiPoint3&>(kDiffuseColor));
        MLPoint3 kAttenuation(g_fMagicLightAttenuation, 0.0f, 0.0f);
        ((NiPointLight*)m_pMenuLight)->FUN_0050dd50(reinterpret_cast<const NiPoint3&>(kAttenuation));
        ((NiPointLight*)m_pMenuLight)->NiLight_SetDimmer(pLightForm->GetRadius());
        ShadowSceneNode* pShadowNode5 = MLGetShadowSceneNode(0);
        if (pShadowNode5)
            pShadowNode5->GetShadowSceneLight(m_pMenuLight, true);
        m_pController = apNode;
        ((NiNode*)m_pController)->AttachChildInAvailableSlot(static_cast<NiAVObject*>(static_cast<NiPointLight*>(m_pMenuLight)), true);
    }
}

ShadowSceneNode* FUN_00450b80(int i);
class FUN_00418f40 : public NiPointer<NiNode>
{
  public:
    ~FUN_00418f40();
    using NiPointer<NiNode>::operator=;
};
class FUN_0081c240
{
  public:
    NiPointer<NiAVObject> m_pReferencedObject;
    unsigned int m_uiValue1;
    FUN_00418f40 m_spNode;
    ~FUN_0081c240();
};
// Calls the referenced object's virtual method and the shadow scene node with m_spNode, then clears the members.
// @fnv 0x0081c240
FUN_0081c240::~FUN_0081c240()
{
    if (m_pReferencedObject)
        static_cast<NiNode*>(m_pReferencedObject.operator->())->RemoveObject(m_spNode);
    m_pReferencedObject = 0;
    ShadowSceneNode* pShadow = FUN_00450b80(0);
    if (pShadow)
        pShadow->ShadowSceneNode_RemoveLight(m_spNode);
    m_spNode = 0;
    m_uiValue1 = 0;
}
