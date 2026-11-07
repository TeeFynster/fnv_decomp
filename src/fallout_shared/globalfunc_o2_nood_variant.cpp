
// src/fallout_shared/globalfunc_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy /GF (unit src/fallout_shared/globalfunc.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "../../include/ActorMover.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSSysInfoSystemUtility.h"
#include "../../include/EffectSetting.h"
#include "../../include/NiBound.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiNode.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiProperty.h"
#include "../../include/NiTexture.h"
#include "../../include/NiTimeController.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/SettingT.h"
#include "../../include/TES.h"
#include "../../include/TESRecipe.h"
#include "../../include/TESTopicInfoData.h"
#include "../../include/bhkWorld.h"
#include "globalfunc_decls.h"
#include "../../include/NiRTTI.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/StrArr.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkVector4.h"
bool ConvertLocalizedString(const char* input, char* output, unsigned int capacity);
bool UpdateObjectVisibility(NiAVObject* object);
bool RemoveInvalidChildNodes(NiNode* object);
bool HandleUnparentedObjectNode(NiNode* object);
void SetObjectFormID(NiAVObject* object, unsigned int referenceID);
bool IsObjectNetValid(NiObjectNET* object);
float GetAngleFromVector(const NiPoint3& vector);
int CountCollisionObjects(NiAVObject* object, bool skipPhantoms, bool skipBlendObjects, bool skipUnknown);
LANGUAGE GetConfiguredLanguage();
bool IsSettingEnabled();

extern __declspec(thread) int g_tlsCur;
struct MemoryContextScope
{
    int previous;
    __forceinline MemoryContextScope(int value)
    {
        previous = g_tlsCur;
        g_tlsCur = value;
    }
    __forceinline ~MemoryContextScope()
    {
        g_tlsCur = previous;
    }
};
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
extern const float DAT_01016248;
extern const float DAT_01017870;
extern const float DAT_0101b2d0;
extern const float str_0101ffc0;
extern const char* DAT_0126812c;
struct __declspec(align(16)) SpringInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float pos[3];
    float unk1c;
    float vel[3];
    float unk2c;

    float damping, elasticity, maxForce, objectDamping;
};
struct MouseSpringDiagnostic
{
    void bhkUnaryAction_GetViewerStrings(StrArr*);
    void bhkMouseSpringAction_CopyCinfo(SpringInfo*);
    void bhkMouseSpringAction_GetViewerStrings(StrArr*);
};
static void AppendString(StrArr* strings, char*& value)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize)
        strings->SetSize(index + strings->m_usGrowBy);
    strings->SetAt(index, value);
}
// @fnv 0x00c873d0
// src: XBOX_PDB 0x00c873d0
void MouseSpringDiagnostic::bhkMouseSpringAction_GetViewerStrings(StrArr* strings)
{
    MemoryContextScope scope(16);
    char* str;
    bhkUnaryAction_GetViewerStrings(strings);
    str = NiViewerStrings_NiGetViewerString_Title(DAT_0126812c);
    AppendString(strings, str);
    SpringInfo info;
    info.unk00 = 0;
    info.unk04 = 0;
    for (int i = 0; i < 3; i++)
        info.pos[i] = 0;
    info.unk1c = 0;
    info.vel[0] = 0;
    info.vel[1] = 0;
    info.vel[2] = 0;
    info.unk2c = 0;
    info.damping = DAT_01016248;
    info.elasticity = DAT_01017870;
    info.maxForce = DAT_0101b2d0;
    info.objectDamping = str_0101ffc0;
    bhkMouseSpringAction_CopyCinfo(&info);
    str = NiGetViewerString_00a7d550("Damping", info.damping);
    AppendString(strings, str);
    str = NiGetViewerString_00a7d550("Elasticity", info.elasticity);
    AppendString(strings, str);
    str = NiGetViewerString_00a7d550("Object Damping", info.objectDamping);
    AppendString(strings, str);
    str = NiGetViewerString_00a7d550("Max Force", info.maxForce);
    AppendString(strings, str);
}

#include <xmmintrin.h>
extern "C" __declspec(thread) int tls_memContext;

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = tls_memContext;
        tls_memContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        tls_memContext = m_iSaved;
    }
};


// 0x00c85750 returns the shared router, whose heap allocator is at +0x10.

static inline const hkVector4& AsHkVector4(const __m128& components)
{
    return reinterpret_cast<const hkVector4&>(components);
}

struct MouseSpringInfo
{
    int unk00;
    void* m_pkBody;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_fSpringDamping;
    float m_fSpringElasticity;
    float m_fMaxRelativeForce;
    float m_fObjectDamping;
};

struct MouseSpringAction
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short unk06;

    static void* operator new(unsigned int nbytes)
    {
        MouseSpringAction* p = (MouseSpringAction*)hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    MouseSpringAction(const hkVector4& kPositionInRbLocal, const hkVector4& kMousePositionInWorld, float fSpringDamping,
                      float fSpringElasticity, float fObjectDamping, void* pkBody, int iUserData);
    void hkpMouseSpringAction_setMaxRelativeForce(float fMaxRelativeForce);
    void FUN_00c905b0();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct MouseSpringOwner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void RegisterAction(struct MouseSpringAction* pkAction);
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void finish(struct MouseSpringInfo* pkInfo);
    void bhkMouseSpringAction_Init(MouseSpringInfo* pkInfo);
};

// @fnv 0x00c87260
// src: XBOX_PDB 0x00c87260
void MouseSpringOwner::bhkMouseSpringAction_Init(MouseSpringInfo* pkInfo)
{
    MemContextGuard kGuard(0x10);
    MouseSpringAction* pkAction = new MouseSpringAction(
        AsHkVector4(_mm_setr_ps(pkInfo->m_f10, pkInfo->m_f14, pkInfo->m_f18, pkInfo->m_f1C)),
        AsHkVector4(_mm_setr_ps(pkInfo->m_f20, pkInfo->m_f24, pkInfo->m_f28, pkInfo->m_f2C)), pkInfo->m_fSpringDamping,
        pkInfo->m_fSpringElasticity, pkInfo->m_fObjectDamping, pkInfo->m_pkBody, 0);
    pkAction->hkpMouseSpringAction_setMaxRelativeForce(pkInfo->m_fMaxRelativeForce);
    RegisterAction(pkAction);
    pkAction->FUN_00c905b0();
    finish(pkInfo);
}
