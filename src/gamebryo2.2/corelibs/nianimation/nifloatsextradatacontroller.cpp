#include <windows.h>
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiFloatInterpolator.h"
#include "../../../../include/NiFloatsExtraData.h"
#include "../../../../include/NiFloatsExtraDataController.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransformController.h"
// src/gamebryo2.2/corelibs/nianimation/nifloatsextradatacontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatsextradatacontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3fcc;

// @fnv 0x00a4ef60
// src: COMMUNITY 0x00a4ef60
void* __cdecl NiFloatsExtraDataController_GetRTTI()
{
    return &g_011f3fcc;
}

int* __fastcall InitTimeController(int*);
extern int DAT_0109928c;
extern int EmptyFS;

// @fnv 0x00a4f000
// src: EXE 0x00a4f000
int* __cdecl NiFloatsExtraDataController_CreateObject()
{
    int* p = static_cast<int*>(BSFadeNode::operator new(0x48));
    if (p)
    {
        InitTimeController(p);
        p[0] = reinterpret_cast<int>(&DAT_0109928c);
        p[0x10] = 0xffffffff;
        p[0x11] = EmptyFS;
        return p;
    }
    return 0;
}

// These member entry points are not declared by the shared headers yet.
// Cast their addresses to the original thiscall signatures at each call site.
void __cdecl FUN_00a57130();
void __cdecl FUN_00a572d0();

// @fnv 0x00a4ef70
NiFloatInterpolator* __fastcall CreateFloatsExtraDataInterpolator(
    NiFloatsExtraDataController* controller, void*, unsigned short usIndex)
{
    NiFloatInterpolator* p = (NiFloatInterpolator*)BSFadeNode::operator new(0x18);
    if (p)
        return p->FUN_00a3c390(static_cast<NiFloatsExtraData*>(controller->m_pExtraData.m_pObject)->GetValueAt(
            controller->m_iFloatsExtraDataIndex));
    return 0;
}

// @fnv 0x00a4efb0
NiFloatsExtraDataController* __fastcall CloneFloatsExtraDataController(
    NiFloatsExtraDataController* controller, void*, CloningProcess& kCloning)
{
    NiFloatsExtraDataController* pkObject = static_cast<NiFloatsExtraDataController*>(BSFadeNode::operator new(0x48));
    if (pkObject)
    {
        InitTimeController(reinterpret_cast<int*>(pkObject));
        *reinterpret_cast<int**>(pkObject) = &DAT_0109928c;
        pkObject->m_iFloatsExtraDataIndex = -1;
        pkObject->m_kCtlrID.m_kHandle = reinterpret_cast<char*>(EmptyFS);
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<NiPSysModifierCtlr*>(controller)->CopyMemberData(
        reinterpret_cast<NiPSysModifierCtlr*>(pkObject), kCloning);
    pkObject->m_iFloatsExtraDataIndex = controller->m_iFloatsExtraDataIndex;
    return pkObject;
}

// The stream headers currently expose the transfer operations without their fields.
// Keep the original field accesses here until those fields have shared names.
// @fnv 0x00a4f1a0
void __fastcall SaveFloatsExtraDataController(
    NiFloatsExtraDataController* controller, void*, NiStream& stream)
{
    reinterpret_cast<void (__thiscall*)(NiFloatsExtraDataController*, NiStream&)>(
        &FUN_00a57130)(controller, stream);
    NiBinaryStream* __restrict output = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x250);
    unsigned int size = 4;
    reinterpret_cast<unsigned int*>(output)[1] +=
        reinterpret_cast<NiBinaryStream::WriteFunction*>(output)[3](
            output, &controller->m_iFloatsExtraDataIndex, 4, &size, 1);
}

extern char g_011f3738;

// @fnv 0x00a4f080
void NiFloatsExtraDataController::ApplyInterpolatorValue(NiInterpolator* pkInterp, unsigned short usIndex)
{
    NiFloatInterpolator* pkFloatInterp;
    if (!pkInterp)
        pkFloatInterp = 0;
    else
        pkFloatInterp = (NiFloatInterpolator*)pkInterp->DynamicCast((const NiRTTI*)&g_011f3738);
    pkFloatInterp->SetFloatValue(static_cast<NiFloatsExtraData*>(m_pExtraData.m_pObject)->GetValueAt(
        m_iFloatsExtraDataIndex));
}

inline void NiBinaryStream::ReadFloat(float& value)
{
    unsigned int size = 4;
    reinterpret_cast<unsigned int*>(this)[1] +=
        reinterpret_cast<ReadFunction*>(this)[2](this, &value, 4, &size, 1);
}

// @fnv 0x00a4f150
void __fastcall LoadFloatsExtraDataController(
    NiFloatsExtraDataController* controller, void*, NiStream& kStream)
{
    reinterpret_cast<NiPSysModifierCtlr*>(controller)->NiPSysModifierCtlr::LoadBinary(kStream);
    NiBinaryStream* input = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&kStream) + 0x24c);
    input->ReadFloat(reinterpret_cast<float&>(controller->m_iFloatsExtraDataIndex));
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&kStream) + 0xd8) < 0x0A010068)
        kStream.ResetStreamState();
}

extern int DAT_01099270;
void __stdcall FUN_00a57420(NiStream* stream);
void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* source);
void* __cdecl NiGetViewerString_00a7d4d0(int* name, void* object);

// @fnv 0x00a4f1e0
void __fastcall RegisterFloatsExtraDataController(
    NiFloatsExtraDataController* controller, void*, NiStream* stream)
{
    FUN_00a57420(stream);
    void* value = NiViewerStrings_NiGetViewerString_Title(g_011f3fcc);
    unsigned int index = reinterpret_cast<unsigned short*>(stream)[5];
    if (index >= reinterpret_cast<unsigned short*>(stream)[4])
        stream->FUN_0096ad30(index + reinterpret_cast<unsigned short*>(stream)[7]);
    stream->FUN_0096ae90(index, reinterpret_cast<const unsigned int*>(&value));
    value = NiGetViewerString_00a7d4d0(&DAT_01099270, reinterpret_cast<void*>(controller->m_iFloatsExtraDataIndex));
    index = reinterpret_cast<unsigned short*>(stream)[5];
    if (index >= reinterpret_cast<unsigned short*>(stream)[4])
        stream->FUN_0096ad30(index + reinterpret_cast<unsigned short*>(stream)[7]);
    stream->FUN_0096ae90(index, reinterpret_cast<const unsigned int*>(&value));
}

extern char* DAT_0109b220;
extern "C" unsigned int __cdecl strlen(const char*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void* __cdecl NiMalloc(unsigned int);
void __cdecl NiFree(void*);
char* __cdecl FUN_00a305b0(char*, unsigned int, const char*, char*, int);

inline NiFixedString& NiFixedString::operator=(const char* pcStr)
{
    char* old = m_kHandle;
    if (old != pcStr)
    {
        m_kHandle = NiGlobalStringTable::AddString(pcStr);
        if (old != DAT_0109b220)
            InterlockedDecrement((long volatile*)(old - 8));
    }
    return *this;
}

// @fnv 0x00a4ebd0
char* __fastcall GetFloatsExtraDataControllerID(NiFloatsExtraDataController* controller)
{
    if (controller->m_kCtlrID.m_kHandle != DAT_0109b220)
        return controller->m_kCtlrID.m_kHandle;
    controller->m_kCtlrID = static_cast<const char*>(0);
    char* prefix = controller->m_kDataName.m_kHandle;
    if (prefix)
    {
        unsigned int size = strlen(prefix) + 0xf;
        char* buf = (char*)NiMalloc(size);
        FUN_00a305b0(buf, size, "%s[%d]", prefix, controller->m_iFloatsExtraDataIndex);
        controller->m_kCtlrID = static_cast<const char*>(buf);
        NiFree(buf);
    }
    return controller->m_kCtlrID.m_kHandle;
}

extern float DAT_01096324;

// @fnv 0x00a4f0c0
void __fastcall UpdateFloatsExtraDataController(NiFloatsExtraDataController* controller, void*, float* updateData)
{
    if (((unsigned char)(controller->m_uiObjectFlags >> 5) & 1) != 0)
    {
        controller->m_fControllerTime = DAT_01096324;
    }
    else if (controller->DontDoUpdate(*updateData))
    {
        if (!controller->m_spControllerInterpolator.m_pObject ||
            !controller->m_spControllerInterpolator.m_pObject->AlwaysUpdate())
            return;
    }
    float value;
    if (controller->m_spControllerInterpolator.m_pObject &&
        controller->m_spControllerInterpolator.m_pObject->UpdateFloat(
            controller->m_fControllerTime, controller->m_pkTarget, value))
    {
        if (controller->m_pExtraData.m_pObject)
            static_cast<NiFloatsExtraData*>(controller->m_pExtraData.m_pObject)->SetValue(
                controller->m_iFloatsExtraDataIndex, value);
    }
}

// @fnv 0x00c312f0
void __fastcall CopyFloatsExtraDataController(
    NiFloatsExtraDataController* controller, void*, NiFloatsExtraDataController* pkDest, void* kCloning)
{
    reinterpret_cast<NiTransformController*>(controller)->CopyMemberData(
        reinterpret_cast<NiTransformController*>(pkDest), kCloning);
    char* pcName = controller->m_kDataName.m_kHandle;
    if (pkDest->m_kDataName.m_kHandle != pcName)
    {
        if (pcName != (char*)EmptyFS)
            InterlockedIncrement((volatile long*)(pcName - 8));
        char* pcOldName = pkDest->m_kDataName.m_kHandle;
        if (pcOldName != (char*)EmptyFS)
            InterlockedDecrement((volatile long*)(pcOldName - 8));
        pkDest->m_kDataName.m_kHandle = pcName;
    }
}

void __cdecl FUN_00aa1460(void*, unsigned int);

// @fnv 0x00a4f040
NiFloatsExtraDataController* __fastcall DestroyFloatsExtraDataController(
    NiFloatsExtraDataController* controller, void*, unsigned int destroyFlag)
{
    *reinterpret_cast<void* volatile*>(controller) = &DAT_0109928c;
    controller->m_kCtlrID.~NiFixedString();
    reinterpret_cast<void (__thiscall*)(NiFloatsExtraDataController*)>(&FUN_00a572d0)(controller);
    if ((destroyFlag & 1) != 0)
        FUN_00aa1460(controller, sizeof(*controller));
    return controller;
}
