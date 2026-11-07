// gamebryo2.2/corelibs/nianimation/niinterpolator.cpp: NiInterpolator, NiKeyBasedInterpolator (8 functions)

// The constructor installs its vtable explicitly after initializing m_fLastTime.
class __declspec(novtable) NiInterpolator;
#include "../../../../include/NiKeyBasedInterpolator.h"

extern const float DAT_01015f5c;
extern void* NiInterpolator_VTable[];

// @fnv 0x00a56ff0
NiInterpolator::NiInterpolator() : m_fLastTime(DAT_01015f5c)
{
    *reinterpret_cast<void**>(this) = NiInterpolator_VTable;
}

struct BSBlendTreadTransfInterpolator;
struct NiBlendInterpolator;
struct CloningProcess;
struct NiObjectNET;
struct NiQuatTransform;
struct NiStream;
struct FUN_00a57030_shell : public NiInterpolator
{
    void GetKeyTimeRange(float*, float*);
};

// @fnv 0x00a57030
void FUN_00a57030_shell::GetKeyTimeRange(float* fBeginKeyTime, float* fEndKeyTime)
{
    *fBeginKeyTime = 0.0f;
    *fEndKeyTime = 0.0f;
}

extern "C" const char* const g_011f36fc_arg1;

// @fnv 0x00a57070
// src: COMMUNITY 0x00a57070
const char* const* __cdecl NiInterpolator_GetRTTI()
{
    return &g_011f36fc_arg1;
}

// Preserve the original explicit base cleanup without a stand-in member declaration.
// @fnv 0x00a57010
void __fastcall DestructNiInterpolator(NiInterpolator* apInterpolator)
{
    *reinterpret_cast<void**>(apInterpolator) = NiInterpolator_VTable;
    apInterpolator->NiRefObject::~NiRefObject();
}

#include "../../../../include/NiTPrimitiveArray.h"
void __stdcall AppendCameraPathEntries(NiTPrimitiveArray<char*>*);
char* _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_011f36fc_arg1) to pkStrings, growing the array when full.
// @fnv 0x00a570b0
// src: XBOX_PDB 0x00a570b0
void __stdcall NiInterpolator_GetViewerStrings(NiTPrimitiveArray<char*>* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* pcString = _FUN_00a7d330(g_011f36fc_arg1);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiMaxSize = pkStrings->m_usMaxSize;
    if (uiSize >= uiMaxSize)
    {
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    }
    pkStrings->SetAt(uiSize, pcString);
}

// Reconstructed: 26-byte stdcall wrapper that grabs an object from a
// factory-like helper and calls one virtual on it (vtable slot 0xD0).
class NiAnimTarget
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
};

extern "C" void* __cdecl FUN_00a5d680();

// @fnv 0x00a57050
// src: XBOX_PDB 0x00a57050
NiAnimTarget* __stdcall NiInterpolator_GetSequenceInterpolator(int a, int b)
{
    NiAnimTarget* p = (NiAnimTarget*)FUN_00a5d680();
    p->v52();
    return p;
}

// @fnv 0x00a57020
// src: COMMUNITY 0x00a57020
char __stdcall NiInterpolator_Update(int a, int b, int c)
{
    return 0;
}

void __cdecl operator delete(void*, unsigned int);
struct FUN_00a57080_Owner
{
    void* Destroy(unsigned int);
};
// Sets the vtable to NiInterpolator, calls the NiRefObject destructor, and frees the object when a1 has bit 0 set.
// @fnv 0x00a57080
void* FUN_00a57080_Owner::Destroy(unsigned int auiFlags)
{
    *(void**)this = (void*)NiInterpolator_VTable;
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        ::operator delete(this, 0xc);
    return this;
}
