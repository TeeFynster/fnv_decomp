#include "../../../../include/NiFrustum.h"
#include "../../../../include/BSScrapArray.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPick.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/GO.h"
#include "../../../../include/Menu.h"
#include "../../../../include/LoveTesterMenu.h"
#include "../../../../include/SPECIALBookMenu.h"
#include "../../../../include/NP.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/TES.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/Bound.h"

// BSAudio's shared factory declarations still return legacy handle types.
struct AudioView
{
    BSSoundHandle GetSoundHandleByEditorID(const char*, unsigned int);
};

// src/fallout/interface/menus/lovetestermenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/lovetestermenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl Deallocate(void*);

struct FUN_00791a80_shell
{
    void __thiscall FUN_00795dc0();
    void* __thiscall FUN_00791a80(unsigned int flags);
};

// @fnv 0x00791a80
void* __thiscall FUN_00791a80_shell::FUN_00791a80(unsigned int flags)
{
    FUN_00795dc0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int();
};
extern LoveTesterMenu* DAT_011da2c8;
struct Inner
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void Target(int, int, unsigned int);
};
struct Outer
{
    char _0[12];
    Inner* q;
};
// @fnv 0x00795780
void FUN_00795780(Outer* pOuter)
{
    pOuter->q->Target(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[17]);
}

struct FUN_00795dc0
{
    char _pad[8];
    GO m;
    ~FUN_00795dc0();
};
// @fnv 0x00795dc0
FUN_00795dc0::~FUN_00795dc0()
{
    m = 0;
}

namespace fnv_00795390 {
struct InnerV
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual int m7(int);
};
struct PC7d
{
    char _pad[0xA4];
    InnerV inner;
};
extern PC7d* g_thePlayer;
extern LoveTesterMenu* DAT_011da2c8;
struct Target00795390
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60(int, int, unsigned int);
};
struct Param00795390
{
    int unk0;
    Target00795390* unk4;
    char pad8[12];
    int unk14;
};
// Calls m7 on the player's inner object with p->unk14, then invokes f60 on p->unk4 using the indexed arr entry from DAT_011da2c8.
// @fnv 0x00795390
void FUN_00795390(Param00795390* pParam)
{
    int t = g_thePlayer->inner.m7(pParam->unk14);
    pParam->unk4->f60(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[t]);
}
}  // namespace fnv_00795390

namespace fnv_00795c60 {
extern LoveTesterMenu* DAT_011da2c8;

// If the LoveTesterMenu singleton exists and its flag is set, calls StepPosition with 1 and then FUN_00795e20 on it.
// @fnv 0x00795c60
void FUN_00795c60()
{
    if (DAT_011da2c8 && DAT_011da2c8->m_bState54)
    {
        DAT_011da2c8->StepPosition(1);
        DAT_011da2c8->FUN_00795e20();
    }
}
}  // namespace fnv_00795c60

namespace fnv_00795ca0 {
extern LoveTesterMenu* DAT_011da2c8;

// @fnv 0x00795ca0
void __cdecl FUN_00795ca0()
{
    if (DAT_011da2c8 && DAT_011da2c8->m_bState54)
    {
        DAT_011da2c8->StepPosition(0);
        DAT_011da2c8->FUN_00795e20();
    }
}
}  // namespace fnv_00795ca0


struct AVOwner_007927a0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int GetValue(int aiIndex);
};
struct Player_007927a0
{
    char _pad[0xa4];
    AVOwner_007927a0 avOwner;
};
extern Player_007927a0* g_thePlayer;

// @fnv 0x007927a0
bool LoveTesterMenu::HandleKeyInput(int aiKey)
{
    switch (aiKey)
    {
    case '+':
    case '=':
    case 0x80000003: {
        int iIndex = this->FUN_00794d30();
        if (iIndex != -1 && FUN_00794d80() < m_iEntryCount && g_thePlayer->avOwner.GetValue(iIndex) < 10)
        {
            HandleSelection(2, 0);
            return true;
        }
        break;
    }
    case '-':
    case '_':
    case 0x80000004: {
        int iIndex2 = this->FUN_00794d30();
        if (iIndex2 != -1 && g_thePlayer->avOwner.GetValue(iIndex2) > 1)
        {
            HandleSelection(3, 0);
            return true;
        }
        break;
    }
    case 0x80000001:
    case 0x80000002:
        HandleSelection(aiKey == 0x80000001, 0);
        return true;
    }
    return false;
}

// Sums the player's avOwner values for indices 5 through 11 and returns the total.
// @fnv 0x00794d80
int LoveTesterMenu::FUN_00794d80()
{
    return g_thePlayer->avOwner.GetValue(5) + g_thePlayer->avOwner.GetValue(6) + g_thePlayer->avOwner.GetValue(7) +
           g_thePlayer->avOwner.GetValue(8) + g_thePlayer->avOwner.GetValue(9) + g_thePlayer->avOwner.GetValue(10) +
           g_thePlayer->avOwner.GetValue(11);
}

// @fnv 0x00795700
void SetTargetFromGlobalState(Outer* apOuter)
{
    if (DAT_011da2c8->mode == 8 &&
        DAT_011da2c8->FUN_00794d80() < DAT_011da2c8->m_iEntryCount)
        apOuter->q->Target(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[15]);
    else
        apOuter->q->Target(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[16]);
}

struct Date
{
    int _0;
    int _4;
    int _8;
    ~Date();
};



void __cdecl FUN_007917a0(void);
extern int _data_011c16bc;

// @fnv 0x00795ce0
void __cdecl FUN_00795ce0(void* apButton)
{
    if (DAT_011da2c8 && DAT_011da2c8->FUN_00794d80() == DAT_011da2c8->m_iEntryCount)
    {
        ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumberFinished", 0x121).Play(false);
        FUN_007917a0();
    }
    else
    {
        ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("UIActivateNothing", 0x121).Play(false);
    }
}

struct RendererHelper
{
    void FUN_007148c0(int, int);
};
RendererHelper* FUN_0043c4b0();
struct CameraHelper
{
    void FUN_00c4f270(bool);
    void FUN_004a0fd0(int);
    void FUN_00c4f2d0();
};
struct ManagerHelper
{
    CameraHelper* FUN_008d80e0();
};
ManagerHelper* FUN_0045c670();
struct InterfaceHelper
{
    int FUN_007fd640();
};
InterfaceHelper* FUN_004b7210();
extern Flt DAT_011da2f4;
void UpdateCameraFrustum(unsigned int, float);
void* FUN_00450b80(int);
void FUN_00b6bee0(unsigned int, void*, CameraHelper*);
void FUN_00b6c0d0(unsigned int, int, int);
// @fnv 0x007948d0
void FUN_007948d0()
{
    if (!DAT_011da2c8 || !(unsigned int)DAT_011da2f4)
        return;
    FUN_0043c4b0()->FUN_007148c0(0, 4);
    ManagerHelper* manager = FUN_0045c670();
    CameraHelper* camera = manager->FUN_008d80e0();
    camera->FUN_00c4f270(true);
    unsigned int localNode = (unsigned int)DAT_011da2f4;
    UpdateCameraFrustum(localNode, 0.65f);
    NP node(FUN_004b7210()->FUN_007fd640());
    camera->FUN_004a0fd0((int)node);
    FUN_00b6bee0(localNode, FUN_00450b80(1), camera);
    FUN_00b6c0d0(localNode, (int)node, 0);
    camera->FUN_004a0fd0(0);
    camera->FUN_00c4f2d0();
}


struct FUN_00794e70
{
    int unk00;
    int unk04;
    NiPointer<NiAVObject> spRetainedObject;
    NiProperty* pProperty;
    FUN_00794e70(int a, int b, const char* name);
};

// Stores two ints, looks up a scene object by name, and stores its property 3 if its type is between 8 and 12, else null.
// @fnv 0x00794e70
FUN_00794e70::FUN_00794e70(int iFirst, int iSecond, const char* pcObjectName) : spRetainedObject(0)
{
    unk00 = iFirst;
    unk04 = iSecond;
    spRetainedObject = DAT_011da2c8->root->GetObjectByName(NiFixedString(pcObjectName));
    NiAVObject* obj = DAT_011da2c8->root->GetObjectByName(NiFixedString(pcObjectName));
    pProperty = (!obj->GetProperty(3) ? false : (obj->GetProperty(3)->Type() >= 8 && obj->GetProperty(3)->Type() <= 12))
                    ? obj->GetProperty(3)
                    : 0;
}

namespace fnv_007950b0 {
struct FUN_007950b0
{
    int unk00;
    NiProperty* unk04;
    NiProperty* unk08;
    NiAVObject* unk0C;
    NiAVObject* unk10;
    int unk14;
    int unk18;

    FUN_007950b0(int a1, const char* pcName, const char* pcName2, int a4, bool bFirst, int a6);
};

// Looks up two named NiAVObjects on one of two scene nodes and stores their property of type 3 when its value is between 8 and 12.
// @fnv 0x007950b0
FUN_007950b0::FUN_007950b0(int a1, const char* pcObjectName, const char* pcSecondObjectName, int aiParam4,
                           bool abUseFirstNode, int aiParam6)
{
    unk00 = a1;
    unk14 = aiParam4;
    unk18 = aiParam6;
    if (abUseFirstNode)
        unk0C = DAT_011da2c8->root->GetObjectByName(NiFixedString(pcObjectName));
    else
        unk0C = ((const NiAVObject*)DAT_011da2c8->cabinet)->GetObjectByName(NiFixedString(pcObjectName));
    unk04 = (unk0C->GetProperty(3) == 0
                 ? 0
                 : (unk0C->GetProperty(3)->FUN_00441110() >= 8 && unk0C->GetProperty(3)->FUN_00441110() <= 12))
                ? unk0C->GetProperty(3)
                : 0;
    if (pcSecondObjectName)
    {
        if (abUseFirstNode)
            unk10 = DAT_011da2c8->root->GetObjectByName(NiFixedString(pcSecondObjectName));
        else
            unk10 = ((const NiAVObject*)DAT_011da2c8->cabinet)->GetObjectByName(NiFixedString(pcSecondObjectName));
        unk08 = (unk10->GetProperty(3) == 0
                     ? 0
                     : (unk10->GetProperty(3)->FUN_00441110() >= 8 && unk10->GetProperty(3)->FUN_00441110() <= 12))
                    ? unk10->GetProperty(3)
                    : 0;
    }
    else
    {
        unk10 = 0;
        unk08 = 0;
    }
}
}  // namespace fnv_007950b0

struct DigitView
{
    int unk00;
    Inner* tens;
    Inner* ones;
    NiAVObject* tensVisibility;
    NiAVObject* onesVisibility;
};
// @fnv 0x007953f0
void __cdecl UpdateDigitDisplay(DigitView* view)
{
    if (!view->tens || !view->ones)
        return;
    int ones = DAT_011da2c8->m_iEntryCount - DAT_011da2c8->FUN_00794d80();
    int value = (ones / 10 < 9 ? ones / 10 : 9) > 0 ? (ones / 10 < 9 ? ones / 10 : 9) : 0;
    int tens = ones % 10 < 0 ? 0 : ones % 10;
    if (value > 0)
    {
        view->tensVisibility->FUN_00450f90(false);
        view->tens->Target(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[value]);
    }
    else
    {
        view->tensVisibility->FUN_00450f90(false);
        view->tens->Target(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[0]);
    }
    view->onesVisibility->FUN_00450f90(false);
    view->ones->Target(0, 0, (unsigned int)(NiSourceTexture*)DAT_011da2c8->tex[tens]);
}

struct Entry_00795580
{
    void FUN_00450f90();
};
struct List_00795580
{
    Entry_00795580* FUN_00559450(int flag);
};
// Adjustment-button callback state: +0x08 retains its scene object and +0x24 is an actor-value index; Menu has a vtable and a fade state at +0x24.
struct AdjustmentButtonState
{
    char _0[8];
    List_00795580 m8;
    char _1[0x1b];
    int m24;
};

unsigned char FUN_004b71d0();

// @fnv 0x00795580
void __cdecl UpdateMenuEntryState(AdjustmentButtonState* pMenu)
{
    int iVar1 = pMenu->m24;
    if (iVar1 != -1)
    {
        if (g_thePlayer->avOwner.GetValue(iVar1) > 1)
            pMenu->m8.FUN_00559450(0)->FUN_00450f90();
        else
            pMenu->m8.FUN_00559450(1)->FUN_00450f90();
        if (FUN_004b71d0() && DAT_011da2c8->mode == 8 &&
            iVar1 != DAT_011da2c8->special + 4)
            pMenu->m8.FUN_00559450(1)->FUN_00450f90();
    }
}

extern const char DAT_010747c4[];
int __cdecl FUN_00647b70(int, int);
struct PlayerSetter
{
    void FUN_0093a7c0(int, int);
};
struct CallbackInput
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int actorValue;
};
// @fnv 0x007957c0
void __cdecl FUN_007957c0(CallbackInput* input)
{
    if (!DAT_011da2c8)
        return;
    int value = input->actorValue;
    if (value != -1)
    {
        int count = g_thePlayer->avOwner.GetValue(value);
        if (count > 1)
        {
            BSSoundHandle sound;
            sound = ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID(DAT_010747c4, 0x121);
            sound.Play(false);
        }
        ((PlayerSetter*)g_thePlayer)->FUN_0093a7c0(value, FUN_00647b70(count - 1, 1));
    }
    DAT_011da2c8->FUN_00795e20();
}

namespace fnv_007958e0 {
struct PlayerOps
{
    void FUN_0093a7c0(int, int);
};
int FUN_00647b70(int, int);
// @fnv 0x007958e0
void FUN_007958e0()
{
    if (!DAT_011da2c8)
        return;
    int index = DAT_011da2c8->FUN_00794d30();
    if (index != -1)
    {
        int value = g_thePlayer->avOwner.GetValue(index);
        if (value > 1)
        {
            BSSoundHandle sound;
            sound = ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumberDown", 0x121);
            sound.Play(false);
        }
        ((PlayerOps*)g_thePlayer)->FUN_0093a7c0(index, FUN_00647b70(value - 1, 1));
    }
    ((Menu*)DAT_011da2c8)->FUN_00795e20();
}
}  // namespace fnv_007958e0

namespace fnv_00796100 {
extern TES* g_TES;
int __cdecl _sprintf_s(char* aBuf, int aSize, const char* aFmt, ...);
int __cdecl strcpy_s(char* aDst, unsigned int aSize, const char* aSrc);
void __cdecl FUN_004b7240(char* aDst, char* aSrc, unsigned int aSize);
bool __cdecl FUN_00709d40();
extern const char str_0101996c[];
extern const char str_01074cc0[];
extern const char str_01074c9c[];
extern const char str_01074c78[];
extern const char str_01074c6c[];
extern const char str_01074c58[];
extern const char str_01074c4c[];
extern const char str_01074c40[];
extern const char str_0101fd1c[];
extern const char str_0101fd24[];
extern const char str_01074c38[];
extern const char str_01074c2c[];
extern const char str_01074c24[];
extern const char str_01074c1c[];
extern const char str_01074c14[];
extern const char str_01074c08[];
extern const char str_01074c00[];
extern const char str_01074bf8[];
extern const char str_01074be8[];
extern const char str_01074bd8[];
extern const char str_01074bc8[];
extern const char str_01074bb8[];
// Builds texture paths with _sprintf_s and FUN_004b7240, then creates each texture via g_TES->CreateTextureImage into tex[0..26].
// @fnv 0x00796100
}  // namespace fnv_00796100

void LoveTesterMenu::FUN_00796100()
{
    using namespace fnv_00796100;
    char bufB[0x104];
    char bufA5[0x108];
    char plat[8];
    int i3;
    int j;
    _sprintf_s(bufA5, 0x104, str_0101996c, str_01074c9c, str_01074cc0);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[25], false, false);
    _sprintf_s(bufA5, 0x104, str_0101996c, str_01074c9c, str_01074c78);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[26], false, false);
    for (i3 = 0; i3 < 11; i3++)
    {
        _sprintf_s(bufA5, 0x104, str_01074c4c, str_01074c58, str_01074c6c, i3);
        FUN_004b7240(bufA5, bufB, 0x104);
        g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[i3], false, false);
    }
    for (j = 1; j < 5; j++)
    {
        _sprintf_s(bufA5, 0x104, str_01074c4c, str_01074c9c, str_01074c40, j);
        FUN_004b7240(bufA5, bufB, 0x104);
        g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[j + 10], false, false);
    }
    if (FUN_00709d40())
    {
        strcpy_s(plat, 5, str_0101fd1c);
    }
    else
    {
        strcpy_s(plat, 5, str_0101fd24);
    }
    _sprintf_s(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c38);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[16], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c24);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[15], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c1c);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[17], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c08, str_01074c9c, str_01074c14);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[18], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074c00);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[19], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c2c, str_01074c58, plat, str_01074bf8);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[20], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c08, str_01074c58, str_01074be8);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[21], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c08, str_01074c58, str_01074bd8);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[22], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c08, str_01074c58, str_01074bc8);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[23], false, false);
    _sprintf_s(bufA5, 0x104, str_01074c08, str_01074c58, str_01074bb8);
    FUN_004b7240(bufA5, bufB, 0x104);
    g_TES->CreateTextureImage(static_cast<const char*>(bufB), tex[24], false, false);
}

struct ResetResourceManager
{
    void FUN_0045a5e0(const char*);
};
extern ResetResourceManager* DAT_011c3b3c;
struct ResetPlayer
{
    void FUN_004def90();
    void FUN_00b5d180();
};
struct ResetString
{
    void FUN_0066b0d0(int);
};
struct IntegerBooleanHandler
{
    void FUN_00700320(int, bool);
};
void* FUN_00791740();
IntegerBooleanHandler* FUN_00a09030(void*);
// @fnv 0x007917a0
void __cdecl FUN_007917a0()
{
    int menu;
    unsigned int m, j, k, l;
    IntegerBooleanHandler* i = FUN_00a09030(FUN_00791740());
    if (!i)
        return;
    DAT_011c3b3c->FUN_0045a5e0("Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Activate.NIF");
    DAT_011c3b3c->FUN_0045a5e0("Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Cabinet.NIF");
    ((ResetPlayer*)FUN_00450b80(1))->FUN_004def90();
    ((ResetPlayer*)FUN_00450b80(1))->FUN_00b5d180();
    DAT_011da2c8->counter5c = 0;
    DAT_011da2c8->counter60 = 0;
    ((ResetString*)&DAT_011da2f4)->FUN_0066b0d0(0);
    for (menu = 0; menu < 9; menu++)
    {
        for (k = 0; k < DAT_011da2c8->groups[menu].objects.FUN_0044ddc0(); k++)
        {
            FUN_00791a80_shell* object = (FUN_00791a80_shell*)*DAT_011da2c8->groups[menu].objects.FUN_006a7ad0(k);
            FUN_00791a80_shell* doomed = object;
            doomed ? doomed->FUN_00791a80(1) : 0;
        }
        for (l = 0; l < DAT_011da2c8->groups[menu].allocations.FUN_0044ddc0(); l++)
        {
            FUN_00791a80_shell* allocation = (FUN_00791a80_shell*)*DAT_011da2c8->groups[menu].allocations.FUN_006a7ad0(l);
            Deallocate(allocation);
        }
        DAT_011da2c8->groups[menu].objects.FUN_008454f0(1);
        DAT_011da2c8->groups[menu].allocations.FUN_008454f0(1);
    }
    for (j = 0; j < DAT_011da2c8->list1a4.FUN_0044ddc0(); j++)
    {
        FUN_00791a80_shell* object = (FUN_00791a80_shell*)*DAT_011da2c8->list1a4.FUN_006a7ad0(j);
        FUN_00791a80_shell* doomed = object;
        doomed ? doomed->FUN_00791a80(1) : 0;
    }
    for (m = 0; m < DAT_011da2c8->list1b4.FUN_0044ddc0(); m++)
    {
        FUN_00791a80_shell* allocation = (FUN_00791a80_shell*)*DAT_011da2c8->list1b4.FUN_006a7ad0(m);
        Deallocate(allocation);
    }
    DAT_011da2c8->list1a4.FUN_008454f0(1);
    DAT_011da2c8->list1b4.FUN_008454f0(1);
    DAT_011da2c8->list64.FUN_008454f0(1);
    DAT_011da2c8->list74.FUN_008454f0(1);
    if (DAT_011da2c8)
    {
        i->FUN_00700320(6002, 1);
        DAT_011da2c8->FUN_00a1d910();
    }
}

class InputManager
{
public:
    int FUN_00a24180(int, int);
};
extern OSGlobals* g_osGlobals;
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
extern InventoryMenuSetting DAT_011c3cb4;
bool FUN_00702450(int);
int FUN_00408b20(const char*, const char*);
extern const char DAT_0101fd00[];
struct ModelOps
{
    NiTimeController* GetObject3D();
    void FUN_00a59c60(const NiUpdateData&);
};
extern const NiRTTI DAT_011f36bc;
NiTimeController* FUN_00653270(const NiRTTI*, NiTimeController*);
union AnimationNames
{
    bool enabled;
    const char* names[9];
};
extern AnimationNames DAT_011a039c;
extern const char* DAT_011a03c0[9];
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
// @fnv 0x00791ab0
void LoveTesterMenu::UpdateAnimation()
{
    if (!FUN_00702450(0x432))
        return;
    InputManager* current = g_osGlobals->FUN_00877720();
    int input = 30;
    if (!FUN_00408b20(DAT_011c3cb4.FUN_00403df0(), DAT_0101fd00))
        input = 16;
    if (current->FUN_00a24180(input, 1))
    {
        HandleSelection(4, 0);
        return;
    }
    NiTimeController* iter = model->GetObject3D();
    if (iter)
    {
        NiTimeController* manager = iter;
        NiControllerSequence* sequence = 0;
        if (!DAT_011a039c.enabled || animationIndex > 0)
            sequence = manager->FUN_0047a520(NiFixedString(DAT_011a039c.enabled ? DAT_011a039c.names[animationIndex]
                                                                                : DAT_011a03c0[animationIndex]));
        elapsed += g_timeGlobal.FUN_0084d030();
        if (sequence)
        {
            sequence->Update(elapsed, true);
            if (sequence->FUN_00508120() < sequence->FUN_00508100() && animationIndex > 0)
                finished = false;
            else
                finished = true;
        }
        else
            finished = true;
        for (; iter; iter = iter->GetNext())
        {
            NiTimeController* transform = FUN_00653270(&DAT_011f36bc, iter);
            if (transform)
            {
                NiUpdateData updateData(elapsed, false, false);
                iter->Update(updateData);
                break;
            }
        }
    }
    NiUpdateData updateData(0.0f, false, false);
    model->FUN_00a59c60(updateData);
}

bool __cdecl SKIsMenuMode(int aiMenuID);

struct SKValueOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int GetActorValue(int aiIndex);
};

struct SKPlayer
{
    int unk00;
    int unk04;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    SKValueOwner kValueOwner;
};

extern SKPlayer* g_pSKPlayer;

// In menu mode 0x432, maps a key to a click action (3 or 2) on the selected entry when mode and actor-value limits allow, returning whether it handled the key.
// @fnv 0x00791cf0
bool LoveTesterMenu::HandleMenuKey(int aiKey, int aiUnused)
{
    if (SKIsMenuMode(0x432))
    {
        int iIndex = GetSelectedIndex();
        switch (aiKey)
        {
        case 4:
            if (iMode != 8)
                return false;
        case 2:
            if (iMode == 8)
                return false;
        case 10:
            if (iIndex != -1 && g_pSKPlayer->kValueOwner.GetActorValue(iIndex) > 1)
                HandleSelection(3, 0);
            return true;
        case 3:
            if (iMode != 8)
                return false;
        case 1:
            if (iMode == 8)
                return false;
        case 9:
            if (iIndex != -1 && GetCount() < m_iMaximumCount && g_pSKPlayer->kValueOwner.GetActorValue(iIndex) < 10)
                HandleSelection(2, 0);
            return true;
        }
    }
    return false;
}

namespace fnv_007945f0 {
extern bool DAT_011f9426;
extern NiColorA DAT_011ad840;
extern int DAT_011f9434;
struct SettingFloatHelper
{
    float* Float();
};
extern SettingFloatHelper DAT_01203144, DAT_01203150;
struct CameraRenderer
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual float GetAspectRatio();
};
struct FUN_00a712f0
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
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FUN_00a712f0();
    void FUN_00712e60(const NiColorA&);
    void FUN_00507700(float);
    void FUN_00a6faf0(const NiFrustum&);
    void FUN_004bc1f0(float, float, float);
    void FUN_00a59c60(NiUpdateData&);
    void SetLookAt(const NiPoint3&, const NiPoint3&);
    void FUN_00733fd0(float);
    void AssignFixedString(const NiFixedString&);
};
int FUN_004dc200();
int FUN_004dc1f0();
float FUN_0057dd70(float);
struct SurgeryCameraMenu
{
    FUN_00a712f0* CreateSurgeryCamera();
};
// Allocates and configures a new camera object from the aspect ratio, FOV and screen ratio settings, then returns it.
// @fnv 0x007945f0
FUN_00a712f0* SurgeryCameraMenu::CreateSurgeryCamera()
{
    FUN_00a712f0* k = new FUN_00a712f0;
    NiColorA ba(0.0f, 1.0f, 1.0f, 0.0f);
    if (DAT_011f9426)
        ba = DAT_011ad840;
    k->FUN_00712e60(ba);
    NiFrustum c;
    c.Init(false);
    c.farPlane = ((CameraRenderer*)FUN_0045c670())->GetAspectRatio();
    c.nearPlane = *DAT_01203144.Float();
    k->FUN_00507700(c.farPlane / c.nearPlane);
    float l = double(DAT_011f9426 ? DAT_011f9434 : FUN_004dc200()) / FUN_004dc1f0();
    float e = 0.75f;
    float j = *DAT_01203150.Float() * 0.01745329238474369 * 0.6499999761581421;
    c.left = -FUN_0057dd70(j) * e;
    c.right = FUN_0057dd70(j) * e;
    c.bottom = -FUN_0057dd70(j) * l * e;
    c.top = FUN_0057dd70(j) * l * e;
    c.ortho = false;
    k->FUN_00a6faf0(c);
    k->FUN_004bc1f0(0.0f, 0.0f, 1.0f);
    NiUpdateData b(0.0f, false, false);
    k->FUN_00a59c60(b);
    k->SetLookAt(NiPoint3(0.0f, 0.0f, 0.0f), NiPoint3(0.0f, 1.0f, 0.0f));
    k->FUN_00733fd0(1.0f);
    k->AssignFixedString(NiFixedString("Surgery3DCamera"));
    return k;
}
}  // namespace fnv_007945f0

// This sequence operation is absent from the shared declaration.
void __fastcall SetSequenceNegatedGlobal(NiControllerSequence* sequence);

struct Controller170
{
    NiControllerSequence* FUN_0047a520(const NiFixedString&);
    void FUN_0048fef0(float);
    void FUN_0047aab0(NiControllerSequence*, int, int, float, float, int);
    void FUN_0047aa40(bool);
};
extern LoveTesterMenu* scene170;
extern bool increasing170;
extern const char* upNames170[];
extern const char* downNames170[];
extern const char rtti170;
// Moves position up or down within bounds, plays page-turn or limit sounds, and triggers the matching animation sequence on the scene controller.
// @fnv 0x007949f0
bool LoveTesterMenu::StepPosition(bool increase)
{
    bool changed = false;
    if (increase)
    {
        increasing170 = true;
        if (position < 8)
        {
            position++;
            changed = true;
            BSSoundHandle sound;
            sound = ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121);
            sound.Play(false);
        }
        else
        {
            if (FUN_00794d80() == available)
            {
                ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumberFinished", 0x121).Play(false);
                FUN_007917a0();
            }
            else
            {
                ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("UIActivateNothing", 0x121).Play(false);
            }
            return false;
        }
    }
    else
    {
        increasing170 = false;
        if (position > 0)
        {
            position--;
            changed = true;
            BSSoundHandle sound;
            sound = ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialPageTurn", 0x121);
            sound.Play(false);
        }
        else
        {
            return false;
        }
    }
    if (changed)
    {
        Controller170* object = (Controller170*)((NiNode*)scene170->root)->FUN_00a5c570((NiRTTI*)&rtti170);
        if (object)
        {
            Controller170* manager = object;
            NiControllerSequence* sequence = 0;
            if (!increasing170 || position > 0)
            {
                sequence =
                    manager->FUN_0047a520(NiFixedString(increasing170 ? upNames170[position] : downNames170[position]));
            }
            if (sequence)
            {
                manager->FUN_0048fef0(0.0f);
                manager->FUN_0047aab0(sequence, 0, 1, 1.0f, 0.0f, 0);
                manager->FUN_0047aa40(true);
                SetSequenceNegatedGlobal(sequence);
            }
        }
    }
    return true;
}

extern Player_007927a0* DAT_011dea3c;

struct MenuParam_00795630
{
    int unk00;
    int unk04;
    List_00795580 unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

// @fnv 0x00795630
void __cdecl FUN_00795630(MenuParam_00795630* pMenuParam)
{
    int value = pMenuParam->unk24;
    if (value != -1)
    {
        if (DAT_011dea3c->avOwner.GetValue(value) < 10 &&
            (DAT_011da2c8 == 0 || DAT_011da2c8->FUN_00794d80() < DAT_011da2c8->m_iEntryCount))
        {
            pMenuParam->unk08.FUN_00559450(0)->FUN_00450f90();
        }
        else
        {
            pMenuParam->unk08.FUN_00559450(1)->FUN_00450f90();
        }

        if (FUN_004b71d0() && DAT_011da2c8->mode == 8 &&
            value != DAT_011da2c8->special + 4)
        {
            pMenuParam->unk08.FUN_00559450(1)->FUN_00450f90();
        }
    }
}

struct WorkerButton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int value;
};
extern const char DAT_010747ac[];
AudioView* __cdecl FUN_00453a70();
int __cdecl MinInt(int, int);
struct WorkerActor
{
    void FUN_0093a7c0(int, int);
};
// @fnv 0x00795a00
void FUN_00795a00(WorkerButton* button)
{
    if (!DAT_011da2c8)
        return;
    int index = button->value;
    if (index != -1)
    {
        int value = g_thePlayer->avOwner.GetValue(index);
        if (value < 10)
        {
            BSSoundHandle sound;
            sound = FUN_00453a70()->GetSoundHandleByEditorID(DAT_010747ac, 0x121);
            sound.Play(false);
        }
        if (DAT_011da2c8->FUN_00794d80() < DAT_011da2c8->available)
            ((WorkerActor*)g_thePlayer)->FUN_0093a7c0(index, MinInt(value + 1, 10));
    }
    DAT_011da2c8->FUN_00795e20();
}

RendererHelper* FUN_0043c4b0();

ManagerHelper* FUN_0045c670();

InterfaceHelper* FUN_004b7210();

extern int* DAT_011daa38;
extern Flt DAT_011daa9c;
void UpdateCameraFrustum(unsigned int, float);
void* FUN_00450b80(int);
void FUN_00b6bee0(unsigned int, void*, CameraHelper*);
void FUN_00b6c0d0(unsigned int, int, int);

// If DAT_011daa38 and DAT_011daa9c are set, configures the camera for scene DAT_011daa9c with a node from FUN_007fd640 and calls FUN_00b6bee0/FUN_00b6c0d0.
// @fnv 0x007c9ca0
void __cdecl FUN_007c9ca0()
{
    if (!DAT_011daa38 || !DAT_011daa9c)
        return;
    {
        FUN_0043c4b0()->FUN_007148c0(0, 4);
        ManagerHelper* mgr = FUN_0045c670();
        CameraHelper* cam = mgr->FUN_008d80e0();
        cam->FUN_00c4f270(true);
        unsigned int scene = DAT_011daa9c;
        UpdateCameraFrustum(scene, 0.15f);
        NP node(FUN_004b7210()->FUN_007fd640());
        cam->FUN_004a0fd0(node);
        FUN_00b6bee0(scene, FUN_00450b80(1), cam);
        FUN_00b6c0d0(scene, node, 0);
        cam->FUN_004a0fd0(0);
        cam->FUN_00c4f2d0();
    }
}

namespace fnv_007caa80 {
AudioView* __cdecl FUN_00453a70();
extern SPECIALBookMenu* DAT_011daa38;
struct Player_7caa80
{
    void FUN_0093a7c0(int, int);
};
int __cdecl MinInt(int, int);
struct Button_7caa80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int stat;
};
// @fnv 0x007caa80
void __cdecl PlaySpecialBookSoundAndSetStat(Button_7caa80* button)
{
    if (!DAT_011daa38)
        return;
    int key = button->stat;
    if (key != -1)
    {
        int value = g_thePlayer->avOwner.GetValue(key);
        if (value < 10)
        {
            BSSoundHandle sound;
            sound = FUN_00453a70()->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121);
            sound.Play(false);
        }
        if (DAT_011daa38->FUN_00794d80() < DAT_011daa38->limit)
        {
            ((Player_7caa80*)g_thePlayer)->FUN_0093a7c0(key, MinInt(value + 1, 10));
        }
    }
    DAT_011daa38->InvokeCallbacksForSlot();
}
}  // namespace fnv_007caa80

int __cdecl MinInt(int, int);

// @fnv 0x00795b30
void __cdecl UpdateLoveTester()
{
    if (!DAT_011da2c8)
        return;
    int key = DAT_011da2c8->FUN_00794d30();
    if (key != -1)
    {
        int value = g_thePlayer->avOwner.GetValue(key);
        if (value < 10)
        {
            BSSoundHandle sound;
            sound = ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121);
            sound.Play(false);
        }
        if (DAT_011da2c8->FUN_00794d80() < DAT_011da2c8->m_iEntryCount)
            ((PlayerSetter*)g_thePlayer)->FUN_0093a7c0(key, MinInt(value + 1, 10));
    }
    DAT_011da2c8->FUN_00795e20();
}

namespace fnv_007928e0 {
struct Matrix109
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix109();
    void FUN_00524ac0(float);
    void FUN_004a0c90(float);
    Matrix109 FUN_0043f8d0(const Matrix109&);
};
struct Update109
{
    float time;
    bool update, force;
    short unk06;
    int unk08;
    Update109(float, bool, bool);
};
struct Color109
{
    float r, g, b;
    Color109(float, float, float);
};
extern TimeGlobal DAT_011f6394;
struct Controller109
{
    NiControllerSequence* FUN_0047a520(const NiFixedString&);
    void FUN_0048fef0(float);
    void FUN_0047aab0(NiControllerSequence*, int, int, float, float, int);
    void FUN_0047aa40(bool);
    Controller109* FUN_004a8a90();
};
}  // namespace fnv_007928e0

struct Scene109
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual Scene109* v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094(const fnv_007928e0::Update109&);
    virtual void v098();
    virtual Scene109* v09c(const NiFixedString&);
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc(Scene109*, bool);
    void FUN_00440490(float);
    void FUN_004bc1f0(float, float, float);
    void FUN_0043fa80(const fnv_007928e0::Matrix109&);
    void FUN_00a59c60(const fnv_007928e0::Update109&);
    fnv_007928e0::Controller109* FUN_00a5c570(const void*);
    Bound* FUN_0043d450();
    Scene109* FUN_00b5ca70(Scene109*, float);
    void FUN_00b5c940(Scene109*, int);
    void FUN_00440460(const fnv_007928e0::Color109&);
    void SetEffectColor(const fnv_007928e0::Color109&);
    void FUN_0050dd50(const fnv_007928e0::Color109&);
    void FUN_0050dd20(float);
};

namespace fnv_007928e0 {
struct Light109 : Scene109
{
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    Light109();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct Loader109
{
    Scene109* LoadModel(const char*, int, int, int, int, int);
};
extern Loader109* DAT_011c3b3c;
void __cdecl FUN_004b7660(Scene109*);
void __cdecl FUN_00a6d2d0(Scene109*);
double __cdecl FUN_00706e50();
void* __cdecl FUN_00653270(const void*, Controller109*);
extern int DAT_011f36ac, DAT_011f36bc;
}  // namespace fnv_007928e0

struct Button109
{
    int unk00, unk04, unk08, unk0c, unk10;
    Button109(void*, void*, const char*);
};

namespace fnv_007928e0 {
struct Adjust109 : Button109
{
    int unk14, unk18, unk1c, unk20, unk24;
    __cdecl Adjust109(void*, void*, const char*, int, int, ...);
};
}  // namespace fnv_007928e0

struct Label109 : Button109
{
    int unk14, unk18;
    Label109(void*, const char*, const char*, int, int, int);
};

namespace fnv_007928e0 {
}  // namespace fnv_007928e0

struct Digit109
{
    Scene109* object;
    int value;
    Digit109(Scene109*, int);
};

namespace fnv_007928e0 {
void __cdecl FUN_007958e0(void*);
void __cdecl UpdateLoveTester(void*);
void __cdecl FUN_00795630(void*);
void __cdecl FUN_00795c60(void*);
void __cdecl FUN_00795ca0(void*);
void __cdecl FUN_00795390(void*);
void __cdecl FUN_00795a00(void*);
int __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
// Loads the front and cabinet NIF scenes, positions them, adds lights and creates the digit, value, adjustment and button widgets for the menu.
// @fnv 0x007928e0
}  // namespace fnv_007928e0

void LoveTesterMenu::Init()
{
    using namespace fnv_007928e0;
    DAT_011da2c8->front = fnv_007928e0::DAT_011c3b3c->LoadModel(
        "Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Activate.NIF", 0, 1, 0, 0, 0);
    FUN_004b7660(DAT_011da2c8->front);
    DAT_011da2c8->cabinet = fnv_007928e0::DAT_011c3b3c->LoadModel(
        "Meshes\\architecture\\Goodsprings\\NV_VitoMaticVigorTester_Cabinet.NIF", 0, 1, 0, 0, 0);
    FUN_004b7660(DAT_011da2c8->cabinet);
    Matrix109 rotation5, turn1;
    rotation5.FUN_00524ac0(1.57079637f);
    turn1.FUN_004a0c90(3.14159274f);
    rotation5 = rotation5.FUN_0043f8d0(turn1);
    turn1.FUN_00524ac0(0.125663713f);
    rotation5 = rotation5.FUN_0043f8d0(turn1);
    bool narrow3 = FUN_00706e50() <= 640.0;
    if (narrow3)
    {
        DAT_011da2c8->front->FUN_00440490(1.0f);
        DAT_011da2c8->front->FUN_004bc1f0(0.0f, -85.0f, -75.0f);
        DAT_011da2c8->front->FUN_0043fa80(rotation5);
        DAT_011da2c8->cabinet->FUN_00440490(1.0f);
        DAT_011da2c8->cabinet->FUN_004bc1f0(0.0f, -85.0f, -75.0f);
        DAT_011da2c8->cabinet->FUN_0043fa80(rotation5);
    }
    else
    {
        DAT_011da2c8->front->FUN_00440490(1.0f);
        DAT_011da2c8->front->FUN_004bc1f0(0.0f, -85.0f, -85.0f);
        DAT_011da2c8->front->FUN_0043fa80(rotation5);
        DAT_011da2c8->cabinet->FUN_00440490(1.0f);
        DAT_011da2c8->cabinet->FUN_004bc1f0(0.0f, -85.0f, -85.0f);
        DAT_011da2c8->cabinet->FUN_0043fa80(rotation5);
    }
    Update109 update13(0.0f, false, false), update259(0.0f, false, false);
    DAT_011da2c8->front->FUN_00a59c60(update13);
    DAT_011da2c8->cabinet->FUN_00a59c60(update259);
    DAT_011da2c8->time += DAT_011f6394.FUN_0084d030();
    Controller109* controller7 = DAT_011da2c8->front->FUN_00a5c570(&DAT_011f36ac);
    if (controller7)
    {
        Controller109* animationController20 = controller7;
        NiControllerSequence* animation7 = animationController20->FUN_0047a520(NiFixedString("Forward"));
        if (animation7)
        {
            animationController20->FUN_0048fef0(0.0f);
            animationController20->FUN_0047aab0(animation7, 0, 1, 1.0f, 0.0f, 0);
            animationController20->FUN_0047aa40(true);
            SetSequenceNegatedGlobal(animation7);
        }
    }
    FUN_00a6d2d0(front);
    for (; controller7; controller7 = controller7->FUN_004a8a90())
    {
        void* special = fnv_007928e0::FUN_00653270(&fnv_007928e0::DAT_011f36bc, controller7);
        if (special)
        {
            Update109 controllerUpdate(0.0f, false, false);
            ((Scene109*)controller7)->v094(controllerUpdate);
            break;
        }
    }
    Update109 update31(0.0f, false, false);
    front->FUN_00a59c60(update31);
    float radius41 = DAT_011da2c8->front->FUN_0043d450()->FUN_0084d030() * 20.0;
    Scene109* ambient16 = ((Scene109*)FUN_00450b80(1))->FUN_00b5ca70(DAT_011da2c8->front->v00c(), radius41);
    if (!ambient16)
    {
        Light109* light52 = new Light109;
        light52->FUN_00440460(Color109(0.0f, 0.0f, 0.0f));
        light52->SetEffectColor(Color109(0.85f, 0.85f, 0.85f));
        light52->FUN_0050dd50(Color109(radius41, 0.0f, 0.0f));
        light52->FUN_0050dd20(1.0f);
        Update109 lightUpdate10(0.0f, false, false);
        light52->FUN_00a59c60(lightUpdate10);
        ((Scene109*)FUN_00450b80(1))->v0dc(light52, true);
        ((Scene109*)FUN_00450b80(1))->FUN_00b5c940(light52, 0);
    }
    ((Scene109*)FUN_00450b80(1))->v0dc(DAT_011da2c8->front, true);
    ((Scene109*)FUN_00450b80(1))->v0dc(DAT_011da2c8->cabinet, true);
    Label109* total28 = 0;
    Adjust109* decrease27;
    Adjust109* increase7;
    Button109* button12;
    Label109* value4;
    decrease27 = new Adjust109((void*)fnv_007928e0::FUN_007958e0, (void*)UpdateMenuEntryState, "P1_Decrease_Btn:0", -1, 0);
    DAT_011da2c8->controls.FUN_007cb2e0(decrease27);
    decrease27 = new Adjust109((void*)fnv_007928e0::UpdateLoveTester, (void*)fnv_007928e0::FUN_00795630, "P1_Increase_Btn:0", -1, 0);
    DAT_011da2c8->controls.FUN_007cb2e0(decrease27);
    button12 = new Button109((void*)fnv_007928e0::FUN_00795c60, (void*)SetTargetFromGlobalState, "P1_RT_Btn:0");
    DAT_011da2c8->controls.FUN_007cb2e0(button12);
    button12 = new Button109((void*)fnv_007928e0::FUN_00795ca0, (void*)FUN_00795780, "P1_LT_Btn:0");
    DAT_011da2c8->controls.FUN_007cb2e0(button12);
    for (int row = 1; row < 10; ++row)
    {
        char name[30];
        for (int digit = 0; digit < 10; ++digit)
        {
            FUN_00406d00(name, 30, "P1_PointVal_0%i_GLOW:%i", row, digit);
            if (DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name))))
            {
                Digit109* entry = new Digit109(DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name))), row);
                DAT_011da2c8->digits.FUN_007cb2e0(entry);
            }
        }
        FUN_00406d00(name, 30, "P1_PointVal_0%i_GLOW", row);
        if (DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name))))
        {
            Digit109* entry2 = new Digit109(DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name))), row);
            DAT_011da2c8->digits.FUN_007cb2e0(entry2);
        }
    }
    {
        char name10[30];
        for (int digit10 = 0; digit10 < 10; ++digit10)
        {
            FUN_00406d00(name10, 30, "P1_PointVal_10_GLOW:%i", digit10);
            if (DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name10))))
            {
                Digit109* entry10 = new Digit109(DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name10))), 10);
                DAT_011da2c8->digits.FUN_007cb2e0(entry10);
            }
        }
        FUN_00406d00(name10, 30, "P1_PointVal_10_GLOW");
        if (DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name10))))
        {
            Digit109* entryLast = new Digit109(DAT_011da2c8->cabinet->v09c(NiFixedString(static_cast<const char*>(name10))), 10);
            DAT_011da2c8->digits.FUN_007cb2e0(entryLast);
        }
    }
    total28 = new Label109((void*)UpdateDigitDisplay, "P1_PointsRemainDigit1:0", "P1_PointsRemainDigit2:0", -1, 1, 0);
    totals.FUN_007cb2e0(total28);
    button12 = new Button109((void*)fnv_007928e0::FUN_00795c60, (void*)SetTargetFromGlobalState, "LookInside_Btn:0");
    misc.FUN_007cb2e0(button12);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_StrengthPointVal:0", 0, 5, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_StrengthDecrease_Btn:0", 5, 2,
                               value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 =
        new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_StrengthIncrease_Btn:0", 5, 2, value4, total28);
    adjustments.FUN_007cb2e0(increase7);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_PerceptionPointVal:0", 0, 6, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_PerceptionDecrease_Btn:0", 6, 2,
                               value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 = new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_PerceptionIncrease_Btn:0", 6, 2, value4,
                              total28);
    adjustments.FUN_007cb2e0(increase7);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_EndurancePointVal:0", 0, 7, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_EnduranceDecrease_Btn:0", 7, 2,
                               value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 =
        new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_EnduranceIncrease_Btn:0", 7, 2, value4, total28);
    adjustments.FUN_007cb2e0(increase7);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_CharismaPointVal:0", 0, 8, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_CharismaDecrease_Btn:0", 8, 2,
                               value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 =
        new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_CharismaIncrease_Btn:0", 8, 2, value4, total28);
    adjustments.FUN_007cb2e0(increase7);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_IntelligencePointVal:0", 0, 9, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_IntelligenceDecrease_Btn:0", 9,
                               2, value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 = new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_IntelligenceIncrease_Btn:0", 9, 2,
                              value4, total28);
    adjustments.FUN_007cb2e0(increase7);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_AgilityPointVal:0", 0, 10, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_AgilityDecrease_Btn:0", 10, 2,
                               value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 =
        new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_AgilityIncrease_Btn:0", 10, 2, value4, total28);
    adjustments.FUN_007cb2e0(increase7);
    value4 = new Label109((void*)fnv_007928e0::FUN_00795390, "Index_LuckPointVal:0", 0, 11, 1, 0);
    values.FUN_007cb2e0(value4);
    decrease27 = new Adjust109((void*)FUN_007957c0, (void*)UpdateMenuEntryState, "Index_LuckDecrease_Btn:0", 11, 2,
                               value4, total28);
    adjustments.FUN_007cb2e0(decrease27);
    increase7 =
        new Adjust109((void*)fnv_007928e0::FUN_00795a00, (void*)fnv_007928e0::FUN_00795630, "Index_LuckIncrease_Btn:0", 11, 2, value4, total28);
    adjustments.FUN_007cb2e0(increase7);
    button12 = new Button109((void*)FUN_00795ce0, (void*)SetTargetFromGlobalState, "AllDone_Btn:0");
    adjustments.FUN_007cb2e0(button12);
    FUN_00796100();
    DAT_011da2c8->FUN_00795e20();
    fnv_007928e0::FUN_00795c60(0);
}

struct Cb_WM
{
    void(__cdecl* pfn0)(Cb_WM*);
    void(__cdecl* pfn4)(Cb_WM*);
};
struct Lvl_WM
{
    NiAVObject* obj;
    int level;
    int u08, u0c, u10, u14, u18;
};
// When idx is at most 8, processes level entries and invokes pfn0 or pfn4 across the selected callback arrays.
// @fnv 0x00795e20
void LoveTesterMenu::FUN_00795e20()
{
    int iLevel;
    if (idx <= 8)
    {
        if (DAT_011da2c8)
        {
            int a = DAT_011da2c8->FUN_00794d30();
            iLevel = 0;
            if (a != -1)
                iLevel = DAT_011dea3c->avOwner.GetValue(DAT_011da2c8->FUN_00794d30());
            for (unsigned int i = 0; i < DAT_011da2c8->arr64.FUN_0044ddc0(); i++)
            {
                int x = DAT_011da2c8->arr64.FUN_006a7ad0(i)->u18;
                DAT_011da2c8->arr64.FUN_006a7ad0(i);
            }
            if (0)
            {
            }
            for (unsigned int j = 0; j < DAT_011da2c8->arr74.FUN_0044ddc0(); j++)
            {
                int iRequiredLevel = DAT_011da2c8->arr74.FUN_006a7ad0(j)->level;
                if (DAT_011da2c8->arr74.FUN_006a7ad0(j)->obj)
                    DAT_011da2c8->arr74.FUN_006a7ad0(j)->obj->FUN_00450f90(iLevel < iRequiredLevel);
            }
        }
        for (unsigned int iIndex = 0; iIndex < pairs[idx].b.FUN_0044ddc0(); iIndex++)
            pairs[idx].b.FUN_006a7ad0(iIndex)->pfn0(pairs[idx].b.FUN_006a7ad0(iIndex));
        for (unsigned int k1 = 0; k1 < pairs[idx].a.FUN_0044ddc0(); k1++)
            pairs[idx].a.FUN_006a7ad0(k1)->pfn4(pairs[idx].a.FUN_006a7ad0(k1));
        for (unsigned int k2 = 0; k2 < arr1b4.FUN_0044ddc0(); k2++)
            arr1b4.FUN_006a7ad0(k2)->pfn0(arr1b4.FUN_006a7ad0(k2));
        for (unsigned int k3 = 0; k3 < arr1a4.FUN_0044ddc0(); k3++)
            arr1a4.FUN_006a7ad0(k3)->pfn4(arr1a4.FUN_006a7ad0(k3));
    }
}

struct AVRead
{
    virtual int GetCurrent(int);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int GetBase(int);
};
struct InputPlayer
{
    int unk00;
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
    int unk9c;
    int unka0;
    AVRead owner;
};
struct Hit
{
    void* FUN_00968670();
};

struct ClickNode
{
    void(__cdecl* click)(ClickNode*);
    int u04;
    Flt object;
};
struct Cursor
{
    float FUN_009a9350();
    float FUN_00792760();
};
struct Buffer
{
    unsigned int FUN_0084e3a0();
};
struct Render
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
    virtual Buffer* GetBuffer();
};
struct CameraRay
{
    void MapScreenToRay(int, int, NiPoint3&, NiPoint3&, bool);
};
extern bool DAT_011f9426;
extern float DAT_011ad84c;
extern float DAT_011ad848;
// Handles menu button cases for navigation, value changes, and ray-tested clicks on menu tiles.
// @fnv 0x00791e40
void LoveTesterMenu::HandleButton(int button, int unused)
{
    bool local720986 = false;
    switch (button)
    {
    case 4:
        if (FUN_00794d80() == available)
        {
            ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumberFinished", 0x121).Play(false);
            FUN_007917a0();
        }
        else
        {
            ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("UIActivateNothing", 0x121).Play(false);
        }
        break;
    case 0:
    case 1:
        if (finished)
        {
            if (button == 0)
                local720986 = StepPosition(true);
            else
                local720986 = StepPosition(false);
            FUN_00795e20();
        }
        break;
    case 2:
    case 3: {
        int local972322 = 0;
        int local421248 = 0;
        if (this->FUN_00794d30() != -1)
        {
            local972322 = ((InputPlayer*)g_thePlayer)->owner.GetBase(this->FUN_00794d30());
            if (button == 2)
            {
                if (FUN_00794d80() < available)
                    ((PlayerSetter*)g_thePlayer)
                        ->FUN_0093a7c0(this->FUN_00794d30(), MinInt(local972322 + 1, 10));
            }
            else
            {
                ((PlayerSetter*)g_thePlayer)
                    ->FUN_0093a7c0(this->FUN_00794d30(), FUN_00647b70(local972322 - 1, 1));
            }
            local421248 = ((InputPlayer*)g_thePlayer)->owner.GetCurrent(this->FUN_00794d30());
        }
        else if (FUN_004b71d0() && mode == 8)
        {
            int local294918 = special + 4;
            local972322 = ((InputPlayer*)g_thePlayer)->owner.GetBase(local294918);
            if (button == 2)
            {
                if (FUN_00794d80() < available)
                    ((PlayerSetter*)g_thePlayer)->FUN_0093a7c0(local294918, MinInt(local972322 + 1, 10));
            }
            else
            {
                ((PlayerSetter*)g_thePlayer)->FUN_0093a7c0(local294918, FUN_00647b70(local972322 - 1, 1));
            }
            local421248 = ((InputPlayer*)g_thePlayer)->owner.GetCurrent(local294918);
        }
        if (local972322 > local421248)
            ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumberDown", 0x121).Play(false);
        if (local972322 < local421248)
            ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialNumber", 0x121).Play(false);
        FUN_00795e20();
    }
    break;
    case 5:
        if (mode <= 8)
        {
            int local879956;
            Cursor* local97635 = (Cursor*)FUN_004b7210();
            local879956 = (int)local97635->FUN_009a9350();
            int local866269 = (int)local97635->FUN_00792760();
            if (DAT_011f9426)
                local866269 = (int)(local866269 * (DAT_011ad848 - DAT_011ad84c) +
                                    ((Render*)FUN_0043c4b0())->GetBuffer()->FUN_0084e3a0() * (double)DAT_011ad84c);
            for (unsigned int local610845 = 0; local610845 < groups[mode].objects.FUN_0044ddc0(); local610845++)
            {
                NiPoint3 local960365;
                NiPoint3 local282417;
                NiPick local38019(0, 8);
                local38019.SetByteAtOffset17(true);
                local38019.FUN_00705fc0(
                    (void*)(*groups[mode].objects.FUN_006a7ad0(local610845))->object.operator unsigned int());
                local38019.FUN_006ecd40(0);
                local38019.SetByteAtOffset30(true);
                ((CameraRay*)DAT_011da2f4.operator unsigned int())
                    ->MapScreenToRay(local879956, local866269, local960365, local282417, false);
                if (local38019.FUN_00e98e20(local960365, local282417, false))
                {
                    unsigned int local919856 = 0;
                    void* local799449 = ((Hit*)local38019.FUN_00500940(local919856))->FUN_00968670();
                    if (local799449)
                    {
                        (*groups[mode].objects.FUN_006a7ad0(local610845))
                            ->click(*groups[mode].objects.FUN_006a7ad0(local610845));
                        break;
                    }
                }
            }
            for (unsigned int local966572 = 0; local966572 < list1a4.FUN_0044ddc0(); local966572++)
            {
                NiPoint3 local960365;
                NiPoint3 local282417;
                NiPick local38019(0, 8);
                local38019.SetByteAtOffset17(true);
                local38019.FUN_00705fc0((void*)(*list1a4.FUN_006a7ad0(local966572))->object.operator unsigned int());
                local38019.FUN_006ecd40(0);
                local38019.SetByteAtOffset30(true);
                ((CameraRay*)DAT_011da2f4.operator unsigned int())
                    ->MapScreenToRay(local879956, local866269, local960365, local282417, false);
                if (local38019.FUN_00e98e20(local960365, local282417, false))
                {
                    unsigned int local919856 = 0;
                    void* local799449 = ((Hit*)local38019.FUN_00500940(local919856))->FUN_00968670();
                    if (local799449)
                    {
                        (*list1a4.FUN_006a7ad0(local966572))->click(*list1a4.FUN_006a7ad0(local966572));
                        break;
                    }
                }
            }
        }
        break;
    case 6:
        if (mode == 8 && special > 1)
        {
            special--;
            ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121).Play(false);
        }
        FUN_00795e20();
        break;
    case 7:
        if (mode == 8 && special < 7)
        {
            special++;
            ((AudioView*)BSAudio::GetSingleton())->GetSoundHandleByEditorID("OBJBookSpecialFocus", 0x121).Play(false);
        }
        FUN_00795e20();
        break;
    }
}

#include <stdarg.h>
struct Animation;

struct FUN_00723fa0
{
    void* m_pData;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    unsigned int m_uiGrow;
    FUN_00723fa0();
    ~FUN_00723fa0();
};

struct FUN_00794ff0 : FUN_00794e70
{
    int m_10;
    FUN_00723fa0 m_kAnims;
    int m_24;
    FUN_00794ff0(int a, int b, const char* pName, int iParam, int iCount, ...);
};

// Initialises m_24 with iParam and appends iCount Animation* arguments from the variadic list to m_kAnims.
// @fnv 0x00794ff0
FUN_00794ff0::FUN_00794ff0(int aiParam1, int aiParam2, const char* pName, int iParam, int aiAnimCount, ...)
    : FUN_00794e70(aiParam1, aiParam2, pName)
{
    m_24 = iParam;
    va_list kArgs;
    va_start(kArgs, aiAnimCount);
    for (int i = 0; i < aiAnimCount; i++)
        ((BSScrapArray<Animation*, 0x400>*)&m_kAnims)->Add(va_arg(kArgs, Animation*));
    va_end(kArgs);
}
