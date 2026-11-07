#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysFieldModifier.h"
#include "../../../../include/NiPSysPositionModifier.h"
#include "../../../../include/NiPSysRadialFieldModifier.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/NiMatrix3.h"
// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysradialfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_012026b0;
void* __cdecl NiPSysRadialFieldModifier_GetRTTI();
extern int DAT_010c0b5c;
struct FUN_00c31ff0 : NiPSysPositionModifier
{
    int _m18;
    float _m1c;
    float _m20;
    bool _m24;
    float _m28;
    float _m2c;
    FUN_00c31ff0();
};
extern "C" char __stdcall FUN_00c32060(void*);
unsigned char __stdcall NiPSysRadialFieldModifier_IsEqual(void* p);
struct S_00c28a90_Arr
{
    int unk00;
    int unk04;
    unsigned short size;
    unsigned short esize;
    unsigned short unk0c;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
};
struct S_00c28a90_Base
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
    void FUN_00c322b0(S_00c28a90_Arr* a);
};
extern const char* DAT_012026b0;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* s);
char* __cdecl NiGetViewerString_00a7d550(const char* name, float value);
struct S_00c28a90 : S_00c28a90_Base
{
    float m30;
    void WriteToArray(S_00c28a90_Arr* a);
};
__forceinline void S_00c28a90_Add(S_00c28a90_Arr* a, char* s)
{
    unsigned int i = a->esize;
    if (i >= a->size)
        a->FUN_0096ad30(i + a->growBy);
    a->FUN_0096ae90(i, s);
}

struct Point3ParameterData
{
    NiPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
};

struct FieldMod
{
    void* vtbl;
    int m_uiRefCount;
    int m_kName;
    int m_uiUpdateOrder;
    NiAVObject* m_pkTarget;
    int m_bModifierActive;
    NiAVObject* m_pkFieldObject;
    float m_fInfluence;
    void Update(float fTime, NiPSysData* pkData);
};

extern int DAT_010be99c;
void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct RadialFieldObject_00c285d0 : FUN_00c31ff0
{
    static void* operator new(unsigned int, void* where) throw()
    {
        return where;
    }
    float m30;
    RadialFieldObject_00c285d0()
    {
        m30 = 0.0f;
        *((int*)this) = (int)&DAT_010be99c;
    }
};

struct FUN_00c285d0_cls
{
    int unk0;
    void NiPSysFieldModifier_CopyMembers(void* obj, unsigned int a1);
    void* NiPSysRadialFieldModifier_CreateClone(unsigned int a1);
};

// @fnv 0x00c285d0
// src: XBOX_PDB 0x00c285d0
void* FUN_00c285d0_cls::NiPSysRadialFieldModifier_CreateClone(unsigned int a1)
{
    RadialFieldObject_00c285d0* p = new (Object_DispatchCommandFour(0x34)) RadialFieldObject_00c285d0;
    NiPSysFieldModifier_CopyMembers(p, a1);
    return p;
}
