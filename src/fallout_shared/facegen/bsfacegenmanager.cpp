#include "../../../include/BSSimpleArray.h"
// fallout_shared/facegen/bsfacegenmanager.cpp: BSFaceGenManager, FGModelCache, BSFaceGenModelMap_t, TESRace and more (111 functions)

#include <windows.h>
#include "../../../include/FaceGenMatrix.h"
#include "../../../include/BSStringT.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../include/NiPointer.h"
#include "../../../include/ARCHIVE_TYPE_INDEX.h"
#include <d3d9.h>
#include "../../../include/NiMemObject.h"
#include "../../../include/NiColorA.h"

int CopyStringChecked(char*, unsigned int, const char*);
int AppendStringChecked(char*, unsigned int, const char*);

struct NiNode;

#include "../../../include/BSFaceGenModelMap.h"

#include "../../../include/BSFaceGenManager.h"

extern BSFaceGenManager* DAT_011d59e8;
void BSFaceGenManager_InitializeSystem();
extern "C" void* memset(void*, int, unsigned int);
#include "../../../include/TESRace.h"
#include "../../../include/ENUM_FORM_ID.h"
#include "../../../include/SEX.h"
#include "../../../include/TESActorBase.h"
extern "C" char* __insecure_strcpy(char*, const char*);
char* FUN_00ec6380(char*, const char*);
extern const char* DAT_0119b734[2];
extern float DAT_01016970;
#include "../../../include/NiPointer.h"
class NiTexture;
class FaceGenPaletteBase
{
  public:
    char pad[0x2c];
    ~FaceGenPaletteBase();
};
class FaceGenPaletteEntry : public FaceGenPaletteBase
{
  public:
    NiPointer<NiTexture> first, second;
    ~FaceGenPaletteEntry();
};

extern const char DAT_0104aad0[];

#include "../../../include/AutoMemContext.h"
#include "../../../include/GO.h"

#include "../../../include/BaseFormComponent.h"
#include "../../../include/TESFile.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESFullName.h"
#include "../../../include/TESTexture.h"
#include "../../../include/BGSQuestObjective.h"

using ::NiColorA;
using ::NiStream;
// 12 bytes on 0x00653470's frame, tested through BSStringT<char>::operator const char* (0x00559450) at its
// start; not derived from the shared BSStringT, whose size (8) and declared destructor the exe frame does not have
class GeometryVertexBuffer
{
  public:
    int a;
    int b;
    int c;
    GeometryVertexBuffer();
};

#include "../../../include/NiPoint2.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/NiPixelData.h"
#include "../../../include/NiSourceTexture.h"
#include "../../../include/NiObjectNET.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/NiTriBasedGeom.h"
#include "../../../include/NiShadeProperty.h"
#include "../../../include/NiRenderer.h"
#include "../../../include/NiExtraData.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/NP.h"
#include "../../../include/BSFaceGenModel.h"
#include "../../../include/BSFaceGenMorphData.h"
#include "../../../include/BSShader.h"
#include "../../../include/BSShaderPPLightingProperty.h"
#include "../../../include/BSShaderManager.h"
#include "../../../include/Tile.h"
#include "../../../include/BSFadeNode.h"
#include "../../../include/TES.h"
// include/PlacedObjectInfo.h (through TESObjectREFR.h) holds the one shared NiPoint3
#include "../../../include/AlchemyItem.h"
namespace fnv_00655fa0 {
using ::NiColorA;
}
namespace fnv_00650ea0 {
}
namespace fnv_00652190 {
#include "../../../include/RecursiveLock.h"
}
#include "../../../include/BSFaceGenNiNode.h"
namespace fnv_00654720 {
}
#include "../../../include/TESEyes.h"

// @fnv 0x006521e0
FaceGenCoordinates* BSFaceGenManager::GetFaceGenCoordinates()
{
    return &GetFaceGenManager()->coords;
}

// @fnv 0x00651b30
BSFaceGenManager* BSFaceGenManager::GetFaceGenManager()
{
    if (!DAT_011d59e8)
        BSFaceGenManager_InitializeSystem();
    return DAT_011d59e8;
}

// @fnv 0x006131a0
BGSTextureModel* TESRace::GetBodyTextureModel(int sex)
{
    return &m_kFaceGenTextureModels[sex];
}

// @fnv 0x00652110
BSFaceGenModelMap* BSFaceGenManager::GetModelMap()
{
    if (!DAT_011d59e8)
        return 0;
    return DAT_011d59e8->m_pModelCache;
}

// If values and count are non-zero, zeroes count floats in the values array.
// @fnv 0x00653e20
void BSFaceGenManager::NormalizeFaceGenValues(float* values, unsigned int count)
{
    if (!values || !count)
        return;
    memset(values, 0, count * 4);
}

// Returns SEX based on the base flag when the form type is ENUM_FORM_ID_NPC__ID, otherwise SEX_SEX_NONE.
// @fnv 0x005f0cc0
SEX TESActorBase::GetSex() const
{
    if (GetFormType() == ENUM_FORM_ID_NPC__ID)
        return static_cast<SEX>(TESActorBaseData::GetFlag(1) ? 1 : 0);
    return SEX_SEX_NONE;
}

// Resizes the three coordinate arrays in coords to 50, 30 and 50 entries respectively, returning early if coords is null.
// @fnv 0x006521f0
void BSFaceGenManager::InitializeFaceGenCoordinates(FaceGenCoordinates* coords)
{
    if (!coords)
        return;
    reinterpret_cast<FaceGenMatrix<float>*>(coords)[0].resize(50, true);
    reinterpret_cast<FaceGenMatrix<float>*>(coords)[1].resize(30, true);
    reinterpret_cast<FaceGenMatrix<float>*>(coords)[2].resize(50, true);
}

// Copies DAT_0104aad0 into dest, then appends DAT_0119b734[part] for part 0 or 1 (else index 0), and returns dest.
// @fnv 0x00657820
char* BSFaceGenManager::BuildFaceGenPartPath(char* dest, int part)
{
    __insecure_strcpy(dest, DAT_0104aad0);
    if (part > -1 && part < 2)
        FUN_00ec6380(dest, DAT_0119b734[part]);
    else
        FUN_00ec6380(dest, DAT_0119b734[0]);
    return dest;
}

// If values and count are non-zero, either zeroes count floats or sets each to DAT_01016970.
// @fnv 0x00653dc0
void BSFaceGenManager::ApplyFaceGenValues(float* values, unsigned int count, bool zero)
{
    if (!values || !count)
        return;
    if (zero)
        memset(values, 0, count * 4);
    else
        for (unsigned int i = 0; i < count; i++)
            values[i] = DAT_01016970;
}

// Destructor for FaceGenPaletteEntry; performs no work.
// @fnv 0x0043ebb0
FaceGenPaletteEntry::~FaceGenPaletteEntry()
{}

namespace std {
template <class _Elem> struct char_traits;
template <class _Ty> class allocator;
template <class _Elem, class _Traits, class _Ax> class basic_string
{
  public:
    char* _Myptr();
};
}

// @fnv 0x0044a560
// src: COMMUNITY 0x0044a560
char* __fastcall std_string_debug_c_str(std::basic_string<char, std::char_traits<char>, std::allocator<char> >* pThis)
{
    return pThis->_Myptr();
}

struct FaceGenCoordinateValue
{
    float* m_pfValues;
    unsigned int m_uiCount;
    FaceGenCoordinateValue(float* p);
    FaceGenCoordinateValue(const FaceGenCoordinateValue&);
    float& NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(unsigned int uiIndex);
};

// Returns a coordinate value wrapping the element pointer at row i, computed from the column count.
// @fnv 0x0060b370
template <>
// src: GUESS 0x0060b370 (confidence: low)
FaceGenCoordinateValue FaceGenMatrix<float>::ForwardCall_0060b370(unsigned int aiRow)
{
    return FaceGenCoordinateValue(GetElementPointerChecked(0, m_uiColumnCount) + aiRow * m_uiColumnCount);
}

extern int DAT_01065678;

struct Dummy658aa0
{
    void __thiscall Initialize(int a, int b);
};

// @fnv 0x0064fd80
// src: EXE 0x0064fd80
void* __fastcall BSFaceGenModelMap_BSFaceGenModelMap(void* pThis)
{
    *(int**)pThis = &DAT_01065678;
    ((Dummy658aa0*)((char*)pThis + 4))->Initialize(0x25, 1);
    for (unsigned int cnt = 0; cnt < 2; ++cnt)
    {
        ((unsigned int*)((char*)pThis + 0x18))[cnt] = 0x10000000;
    }
    *((unsigned char*)pThis + 0x20) = 0;
    return pThis;
}

void __fastcall FUN_00659b50(void*);

#include "../../../include/NiMemObject.h"

struct FUN_00650170_thiscall
{
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_00659b50 on this, then deletes this via NiMemObject::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00650170
void* FUN_00650170_thiscall::DestroyIfFlagged(unsigned int flags)
{
    FUN_00659b50(this);
    if (flags & 1)
        NiMemObject::operator delete(this, 0x10);
    return this;
}

struct NiNode;
struct EBase
{
    int a;
    int b;
    ~EBase();
};
struct FUN_006501a0_shell : EBase
{
    NiPointer<NiNode> sp;
    ~FUN_006501a0_shell();
};
// @fnv 0x006501a0
FUN_006501a0_shell::~FUN_006501a0_shell()
{}


// Returns the string held by the BSStringT pointer stored at pThis+0xC, or null if that pointer is null.
// @fnv 0x00650600
// src: COMMUNITY 0x00650600
const char* __fastcall BSFaceGenModel_GetString(char* pThis)
{
    return *reinterpret_cast<BSStringT<char>**>(pThis + 0xC)
               ? static_cast<const char*>(**reinterpret_cast<BSStringT<char>**>(pThis + 0xC))
               : 0;
}

struct FUN_006508e0_shell
{
    char pad[0x18];
    int arr[4];
    void BSFaceGenModelMap_VerifyData(int);
    void SetArrayValue(int i, int v);
};
// Stores v into arr[i] and then calls FUN_00650ba0(0).
// @fnv 0x006508e0
void FUN_006508e0_shell::SetArrayValue(int aiIndex, int aiValue)
{
    arr[aiIndex] = aiValue;
    BSFaceGenModelMap_VerifyData(0);
}

struct Dummy_00650910
{
    int pad[6];
    int arr[1];
    int GetArrayElement(int idx);
};

// @fnv 0x00650910
int Dummy_00650910::GetArrayElement(int idx)
{
    return arr[idx];
}

struct FUN_00651520
{
    FaceGenMatrix<float> a[2];
    FaceGenMatrix<float> b;
    FaceGenMatrix<float> c[2];
    FUN_00651520();
};
// @fnv 0x00651520
FUN_00651520::FUN_00651520()
{}

namespace fnv_00651630 {
// @fnv 0x00651630
// src: GUESS 0x00651630 (confidence: medium)
void* __fastcall BSFaceGenManager_InitializeFaceGenMatrix(FaceGenMatrix<float>* pThis)
{
    pThis->FaceGenMatrix<float>::FaceGenMatrix();
    return pThis;
}
}  // namespace fnv_00651630

void __stdcall FUN_ehvec_ctor(void*, unsigned int, int, void*, void*);
void FUN_ctor();
void FUN_dtor();

// @fnv 0x00651670
// src: GUESS 0x00651670 (confidence: low)
void* __fastcall BSFaceGenManager_EvaluateValue_00651670(void* p)
{
    FUN_ehvec_ctor(p, 0x20, 2, &FUN_ctor, &FUN_dtor);
    return p;
}


// Actually, instructions say: "Define it as a free function named exactly FUN_006516c0. If it is a __thiscall method (this pointer in ecx, callee pops stack arguments with ret N) write a free function with __fastcall whose first parameter is the this pointer and whose second parameter is an unused int (for edx), then the real arguments."
// Wait: in MSVC /Od, a __fastcall function with (void* this_ptr, int edx, bool abTF) will spill BOTH ecx and edx to the stack! `push ecx; push ecx; mov [ebp-8], edx; mov [ebp-4], ecx;`
// Let's check how only `ecx` is spilled: if edx is NOT named or not a parameter? No, __fastcall always has 2 register params if there are >=2 integer params, EXCEPT if the first parameter is 64-bit, or if there is only 1 register parameter (i.e. the second param is passed on stack, e.g., a struct by value of size 1, 2, or 4!).
struct _stack_bool
{
    bool v;
};

// @fnv 0x006516c0
// src: COMMUNITY 0x006516c0
void __fastcall NiPixelData_SetInternal(char* pThis, _stack_bool abTF)
{
    *reinterpret_cast<bool*>(pThis + 0x70) = abTF.v;
}

namespace fnv_006516e0 {
struct M657a80
{
    char d[0x18];
    M657a80();
    ~M657a80();
};
struct M657b50
{
    char d[0x10];
    M657b50();
};
struct FUN_006516e0
{
    char pad[8];
    FaceGenMatrix<float> m[4];
    M657a80 a;
    M657b50 b;
    FUN_006516e0();
};
// @fnv 0x006516e0
FUN_006516e0::FUN_006516e0()
{}
}  // namespace fnv_006516e0

void __cdecl FUN_00657960();
void __cdecl FUN_006579d0();
void __stdcall compiler_eh_vector_destructor_iterator(void*, unsigned int, int, void(__cdecl*)(), void(__cdecl*)());

// @fnv 0x006517e0
void* __fastcall DestroyVectorElements(void* pThis)
{
    compiler_eh_vector_destructor_iterator(pThis, 0x18, 4, FUN_00657960, FUN_006579d0);
    return pThis;
}


struct Sol;
using ::AutoMemContext;
struct Sol
{
    char pad[0x10];
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Sol();
    unsigned int BSFaceGenModel_GetString();
    void FUN_0065a760(void* a);
    bool BSFaceGenModel_LoadModel(char*, char*, char*, char*, int, bool);
};
struct SolPtr
{
    Sol* p;
    SolPtr(Sol*);
    ~SolPtr();
    Sol* Get() const;
    SolPtr& operator=(Sol*);
};

struct GO45CFE0
{
    char* FUN_004503f0();
};

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);


void __fastcall BSFaceGenModelMap_RemoveAllUnusedModels(void*);

// If DAT_011d59e8 and the pointer at offset 0x1194 are non-null, calls FUN_006503b0 on that pointer.
// @fnv 0x00651e30
// src: XBOX_PDB 0x00651e30
void BSFaceGenManager_ClearModelCache()
{
    if (!DAT_011d59e8)
    {
        return;
    }
    if (!DAT_011d59e8->m_pModelCache)
    {
        return;
    }
    BSFaceGenModelMap_RemoveAllUnusedModels(DAT_011d59e8->m_pModelCache);
}

void __fastcall ClearModelTextures(void*);

// If DAT_011d59e8 is set and its field at offset 0x1194 is non-null, calls ClearModelTextures on that field.
// @fnv 0x00651f40
// src: XBOX_PDB 0x00651f40
void BSFaceGenManager_ClearEGTCache()
{
    if (DAT_011d59e8 != 0 && DAT_011d59e8->m_pModelCache != 0)
        ClearModelTextures(DAT_011d59e8->m_pModelCache);
}

struct GlobalObject_0044fae0
{
    void BSCriticalSection_Lock(int);
};
extern GlobalObject_0044fae0 g_011d5a9c;
extern int DAT_011d59dc;
// @fnv 0x00652140
// src: XBOX_PDB 0x00652140
void BSFaceGenManager_LockFaceGenAccess()
{
    g_011d5a9c.BSCriticalSection_Lock(0);
    DAT_011d59dc = DAT_011d59dc + 1;
}

namespace fnv_00652160 {
struct GlobalObject_0044fae0
{
    bool BSCriticalSection_TryLock();
};

extern GlobalObject_0044fae0 g_011d5a9c;
extern int DAT_011d59dc;

// Calls FUN_0044b130 on g_011d5a9c; if it returns true, increments DAT_011d59dc, and returns that result.
// @fnv 0x00652160
// src: COMMUNITY 0x00652160
bool BSFaceGenManager_TryLockFaceGenAccess()
{
    bool bresult = g_011d5a9c.BSCriticalSection_TryLock();
    if (bresult == true)
    {
        DAT_011d59dc += 1;
    }
    return bresult;
}
}  // namespace fnv_00652160

namespace fnv_00652190 {


extern RecursiveLock g_011d5a9c;
extern int DAT_011d59dc;

// @fnv 0x00652190
// src: COMMUNITY 0x00652190
void __cdecl BSFaceGenManager_UnlockFaceGenAccess(void)
{
    g_011d5a9c.Leave();
    DAT_011d59dc--;
}
}  // namespace fnv_00652190

struct Sub_00aabdb0
{
    float FanGenCtlsGrpC_getAttribute(int, int, int, int);
};

// @fnv 0x00652440
// src: COMMUNITY 0x00652440
float __cdecl BSFaceGenManager_GetFaceCoordAttribute(int apCoord, int aeFanAttribute, int aeFanType)
{
    return reinterpret_cast<Sub_00aabdb0*>(&BSFaceGenManager::GetFaceGenManager()->m_kModels)
        ->FanGenCtlsGrpC_getAttribute(0, aeFanAttribute, aeFanType, apCoord);
}

namespace fnv_006529a0 {
// @fnv 0x006529a0
// src: COMMUNITY 0x006529a0
void __cdecl BSFaceGenManager_CopyFaceGenCoord(FaceGenMatrix<float> (*apCopyFromCoord)[2], FaceGenMatrix<float> (*apCopyToCoord)[2],
                          bool abGeometryOnly, bool abTextureOnly)
{
    if (!apCopyFromCoord || !apCopyToCoord)
        return;

    for (int etype = 0; etype < 2; ++etype)
    {
        for (int esymm = 0; esymm < 2; ++esymm)
        {
            if (apCopyFromCoord[etype][esymm].NiAVObject_GetParent() &&
                apCopyFromCoord[etype][esymm].FUN_00441110())
            {
                apCopyToCoord[etype][esymm].SetDimensions(apCopyFromCoord[etype][esymm].NiAVObject_GetParent(),
                                                        apCopyFromCoord[etype][esymm].FUN_00441110());
                if ((abGeometryOnly && etype == 0) || (abTextureOnly && etype == 1) ||
                    (abGeometryOnly == abTextureOnly))
                {
                    apCopyToCoord[etype][esymm] = apCopyFromCoord[etype][esymm];
                }
            }
            else
            {
                apCopyToCoord[etype][esymm].SetDimensions(0, 0);
            }
        }
    }
}
}  // namespace fnv_006529a0

class NiNode;

extern int g_011d5bb8;
NiNode* __cdecl GetNodeFromGeometry(void*);
void* __cdecl DynamicCastByRTTI(void*, NiNode*);

// @fnv 0x00653230
// src: COMMUNITY 0x00653230
void* __cdecl BSFaceGenUtils_GetFaceGenMorphDataHead(void* apGeom)
{
    NiNode* pGeometryNode = GetNodeFromGeometry(apGeom);
    if (pGeometryNode == 0)
    {
        return 0;
    }
    return DynamicCastByRTTI(&g_011d5bb8, pGeometryNode);
}

struct NiNode;

NiNode* __cdecl GetNodeFromGeometry(void*);
void* __cdecl DynamicCastByRTTI(void*, NiNode*);
extern int g_011d5ba8;

// @fnv 0x00653300
// src: COMMUNITY 0x00653300
void* __cdecl BSFaceGenUtils_GetFaceGenMorphDataHair(void* apGeom)
{
    NiNode* pGeometryNode = GetNodeFromGeometry(apGeom);
    if (pGeometryNode == 0)
    {
        return 0;
    }
    return DynamicCastByRTTI(&g_011d5ba8, pGeometryNode);
}


const NiFixedString& __cdecl BSFaceGenBaseMorphExtraData_GetTag();

// Returns the extra data named by FUN_00653460 from apGeom, or null if apGeom is null.
// @fnv 0x00653430
NiExtraData* __cdecl GetExtraDataIfPresent(NiAVObject* apGeom)
{
    return apGeom ? apGeom->GetExtraData(BSFaceGenBaseMorphExtraData_GetTag()) : 0;
}

namespace fnv_00653470 {
extern double _gModifierZero;
struct Morph653
{
    void ApplyMorph_00662460(NiGeometry*, int, float);
};
Morph653* __cdecl BSFaceGenUtils_GetFaceGenMorphDataHair(NiGeometry*);
void __cdecl BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(NiGeometry*, GeometryVertexBuffer*);
// @fnv 0x00653470
// src: COMMUNITY 0x00653470
void BSFaceGenManager_ApplyHairMorph(NiGeometry* apGeom, float afModifierValue)
{
    if (!apGeom || afModifierValue < _gModifierZero)
        return;
    Morph653* pMorph = BSFaceGenUtils_GetFaceGenMorphDataHair(apGeom);
    if (!pMorph)
        return;
    if (apGeom->GetModelData()->IsGeometryDataStreamable(true))
    {
        GeometryVertexBuffer iter;
        apGeom->GetModelData()->NiGeometryData_GetVerticesIterator(iter);
        BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(apGeom, &iter);
        if ((const char*)*reinterpret_cast<BSStringT<char>*>(&iter))
        {
            pMorph->ApplyMorph_00662460(apGeom, 0, afModifierValue);
        }
        apGeom->GetModelData()->NiGeometryData_UnlockPackedVertexData();
    }
}
}  // namespace fnv_00653470

// Maps the input value 1-7 to a slot index (0,1,2,3,4,13) and returns -1 for any other value.
// @fnv 0x00653cf0
// src: XBOX_PDB 0x00653cf0
int __cdecl BSFaceGenManager_GetExpressionFromEmotion(int aiValue)
{
    switch (aiValue)
    {
    case 1:
        return 0;
    case 2:
        return 0;
    case 3:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 6:
        return 4;
    case 7:
        return 13;
    default:
        return -1;
    }
}

extern double _gModifierZero;

// @fnv 0x00653d70
void __cdecl SplitSignedDifference(float afValueA, float afValueB, float* param_3, float* param_4)
{
    float diff = afValueA * -1.0 + afValueB;
    if (diff >= _gModifierZero)
    {
        *param_3 = 0.0f;
        *param_4 = diff;
    }
    else
    {
        *param_3 = diff * -1.0;
        *param_4 = 0.0f;
    }
}


struct GO633 : NP
{
    GO633(int);
};
struct S654
{
    NP NiTPointerListBase_NiPropertyPtr_Remove(GO633&);
    void ForwardToSubobject(int v);
};
// Constructs a GO633 from v and passes it to FUN_0057c5d0 on the S654 subobject at offset 0x24.
// @fnv 0x00654640
void S654::ForwardToSubobject(int aiValue)
{
    GO633 a(aiValue);
    ((S654*)((char*)this + 0x24))->NiTPointerListBase_NiPropertyPtr_Remove(a);
}


struct FUN_00656d80_this
{
    char pad[0x24];
    BGSQuestObjective* pObj;
};

// Returns the target list of the stored BGSQuestObjective, or null if no objective is set.
// @fnv 0x00656d80
BSSimpleList<RegionObjectEntry*>* __fastcall GetObjectiveTargetList(FUN_00656d80_this* pThis)
{
    if (pThis->pObj)
    {
        return pThis->pObj->GetTargetList();
    }
    else
    {
        return 0;
    }
}

struct V3
{
    int a;
    int b;
    int c;
};
struct FUN_00656fd0_shell
{
    V3* p;
    void CopyV3(V3* out);
};
// Copies the V3 value pointed to by p into out.
// @fnv 0x00656fd0
void FUN_00656fd0_shell::CopyV3(V3* out)
{
    V3* y;
    V3* x = p;
    y = x;
    *out = *y;
}

namespace fnv_00657010 {
struct NiProperty;

struct NiSkinInstance;

NiRenderer* __cdecl NiXenonRenderer_GetRenderer();
// @fnv 0x00657010
void SetGeometryCompressFlags(NiAVObject* apObj, unsigned int aiShaderIndex, unsigned int aiCompressFlags)
{
    if (apObj)
    {
        NiTriBasedGeom* pgeom = reinterpret_cast<NiTriBasedGeom*>(apObj->IsTriBasedGeometry());
        if (pgeom)
        {
            if (pgeom->GetModelData())
            {
                pgeom->GetModelData()->SetCompressFlags(aiCompressFlags);
                pgeom->GetModelData()->SetDataConsistency(0);
                if (!pgeom->GetSkinInstance())
                {
                    BSShader* pshader = static_cast<BSShader*>(reinterpret_cast<AlchemyItem*>(pgeom)->CombatController_GetTarget());
                    if (pshader)
                    {
                        NiRenderer* r = NiXenonRenderer_GetRenderer();
                        // This renderer draw slot is not declared by the shared header.
                        reinterpret_cast<void (__thiscall*)(NiRenderer*, NiAVObject*, int, int, int)>((*reinterpret_cast<void***>(r))[59])(r, pgeom, 0, 0, reinterpret_cast<int (__thiscall*)(BSShader*, NiAVObject*, ::NiProperty*)>((*reinterpret_cast<void***>(pshader))[70])(pshader, pgeom, pgeom->GetProperty(3)));
                        NiXenonRenderer_GetRenderer()->NiDX9Renderer_PerformPrecache();  // 0x00e74120 (NiRenderer::TryUnlock is 0x00b6b330)
                    }
                }
            }
        }
    }
}
}  // namespace fnv_00657010

struct _elem_60
{
    char pad[0x3c];
};

struct _vec_60
{
    int pad0;
    int pad1;
    int pad2;
    _elem_60* first;
    _elem_60* last;
};

// @fnv 0x00657a30
// src: COMMUNITY 0x00657a30
unsigned int __fastcall std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size(const _vec_60* apVec)
{
    return apVec->last - apVec->first;
}

struct OpaqueDataBlock
{
    char pad[0x3c];
};
unsigned int FUN_00ec7c56();
struct FUN_00657a50_shell
{
    char pad[0xc];
    OpaqueDataBlock* first;
    unsigned int std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size();
    OpaqueDataBlock* GetElementPointerChecked(unsigned int i);
};
// Returns a pointer to the element at index i after bounds-checking it against the count from FUN_00657a30.
// @fnv 0x00657a50
// src: GUESS 0x00657a50 (confidence: high)
OpaqueDataBlock* FUN_00657a50_shell::GetElementPointerChecked(unsigned int uiIndex)
{
    if (!(uiIndex < std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size()))
        FUN_00ec7c56();
    do
    {
    } while (0);
    return first + uiIndex;
}

// @fnv 0x006591f0
float SquareFloat(float afValue)
{
    return afValue * afValue;
}

struct VIter
{
    float* p0;
    void* p1;
    VIter& operator=(const VIter&);
};
struct VIterD : public VIter
{
};
struct FloatVec
{
    unsigned int std_vector_float_std_allocator_float_size() const;
    unsigned int FaceGenData_GetUnk014MinusMinDivBy4() const;
    float* ProcessAndReturnValue_0060b8a0(float*, unsigned int, const float&);
    VIterD CallWithSelf();
    VIter UpdateState_00657c50(VIter, const float&);
    void PushBack(const float& _Val);
    char pad[0x10];
    float* _Mylast;
};

// @fnv 0x006578e0
void FloatVec::PushBack(const float& afValue)
{
    if (std_vector_float_std_allocator_float_size() < FaceGenData_GetUnk014MinusMinDivBy4())
        _Mylast = ProcessAndReturnValue_0060b8a0(_Mylast, 1, afValue);
    else
        UpdateState_00657c50(CallWithSelf(), afValue);
}

namespace fnv_00655fa0 {
struct TESHair;
struct FaceGenData
{
    void* __vecDelDtor(unsigned int);
    char m_kFaceGenCoordinates[96];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    char m_kModelObjectsItem[16];
    char pTexture[16];
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad_b6[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    char Accessories[8];
};
typedef char _sizecheck_FaceGenNpcData[sizeof(FaceGenData) == 204 ? 1 : -1];

typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];

typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];

// Stand-in for the folded getter at 0x00441110 (returns the dword at +0x1C; BGSTerrainManager::GetMinLevel shares it),
// called here on face-gen coordinate and shader-property objects.
struct FoldedDwordGetter1C
{
    unsigned int GetMinLevel();
};

struct Flt
{
    operator unsigned int() const;
};


struct NiNodeHelper
{
    NiAVObject* GetAt(unsigned int);
    int NiNode_GetChildCount();
    void Update(const NiUpdateData&);
};



struct FNStub
{
    const char* GetFullName();
};

struct GlobalObject_004aff00
{
    unsigned int GetSize();
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct CellLightingTemplate
{
    float TESCombatStyle_GetWeaponMinRangeMult();
};

struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct LightPropHelper
{
    int GetFltValue(int);
    void BSShaderProperty_SetFlag(int, bool);
    void NiMaterialProperty_SetShine(float);
};
struct TextureFormatHelper
{
    int _ref_00726070();
};
extern TES* g_TES;
extern const char DAT_01019f08[];
float floorf(float);
float BSFaceGenManager_GetFaceCoordAttribute(FaceGenData*, int, int);
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
int BSFaceGenManager_GetAsNearestDetailDDSFile(BSStringT<char>*, int, unsigned char, const char*);
int General_uiEGTClampSize_Get();
void* BSFaceGenUtils_GetDefaultDetailModulationTexture();
void* BSShader_GetDefNormalMap();
void* __fastcall GetObjectiveTargetList(void*);
void SetGeometryCompressFlags(NiAVObject*, unsigned int, unsigned int);
bool Actor_AreReferencedValuesEqual(const NiFixedString&, const NiFixedString&);
int _sprintf_s(char*, unsigned int, const char*, ...);
unsigned int _strlen(const char*);
int __strnicmp(const char*, const char*, unsigned int);
struct NodeCalls
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
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
    virtual void v094();
    virtual void v098();
    virtual NiAVObject* GetObjectByName(const NiFixedString&);
};
struct ObjCalls
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual NiAVObject* GetGeometry();
};
struct LightPropCalls
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
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
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void Refresh();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void SetTexture3(int, int, void*);
    virtual void v0f4();
    virtual void v0f8();
    virtual void SetTexture2(int, void*);
    virtual void SetTexture(int, void*);
};
struct ModelCalls
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void GetNormalName(void*);
};

// Applies facegen texture coordinates and shader properties to an NPC model node, then updates its child nodes and geometry.
// @fnv 0x00655fa0
void ApplyFaceGenTextures(NiAVObject* apNode, FaceGenData* arNpcData)
{
    AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xc2a);
    NiFixedString leftEye("FaceGenEyeLeft");
    NiFixedString rightEye("FaceGenEyeRight");
    NiFixedString headAccessory("FaceGenAccessory");
    NiFixedString hair(DAT_0104aad0);
    BSStringT<char> filename;
    BSStringT<char> fileEGM;
    BSStringT<char> fileDDS;
    BSStringT<char> fileDetail;
    NiAVObject* pobj;
    BSStringT<char> fileNormal;
    GO sptexNormal(0);
    GO sptexBaseMod(0);
    GO sptexDetailMod(0);
    unsigned int ishaderindex = 0;
    bool bspecular = false;
    char cage;
    char tmp[260];
    LightPropCalls* pshaderpropLighting;
    NiAVObject* pgeom;
    NiAVObject* pmodelFG;
    void* pshaderprop;
    unsigned char UpdateData[sizeof(NiUpdateData)];

    BSFaceGenManager_LockFaceGenAccess();
    if (apNode == 0 || arNpcData == 0)
    {
        BSFaceGenManager_UnlockFaceGenAccess();
        return;
    }
    cage = (char)floorf(BSFaceGenManager_GetFaceCoordAttribute(arNpcData, 0, 0));
    CopyStringChecked(tmp, 0x104, "Textures\\");
    for (unsigned int ipart = 0; ipart < 8; ipart++)
    {
        fileDetail.Set("", 0);
        if (ipart == 6 || ipart == 7)
            continue;
        if (ipart == 0 || ipart == 1)
            ishaderindex = 0xe;
        else
            ishaderindex = 1;
        if (*((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0x94))->GetAtPointer(ipart) == 0 ||
            *((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xa4))->GetAtPointer(ipart) == 0)
            continue;
        pobj = ((NodeCalls*)apNode)
                   ->GetObjectByName(NiFixedString((const char*)*((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xb4))->GetAtPointer(ipart)));
        if (pobj == 0)
            continue;
        pgeom = ((ObjCalls*)pobj)->GetGeometry();
        if (pgeom == 0)
            continue;
        pmodelFG = BSFaceGenModel::GetFaceGenModelNode(pgeom);
        if (pmodelFG == 0)
            continue;
        BSShaderManager::UpdateObjectTypeRecurse(pobj, false, false);
        pshaderprop = ((PropHelper*)pobj)->GetProperty(3);
        if ((pshaderpropLighting =
                 (LightPropCalls*)((pshaderprop == 0 ? 0
                                                     : ((int)((FoldedDwordGetter1C*)pshaderprop)->GetMinLevel() >= 8 &&
                                                        (int)((FoldedDwordGetter1C*)pshaderprop)->GetMinLevel() <= 12))
                                       ? pshaderprop
                                       : 0)) == 0)
            continue;
        if (((GlobalObject_004aff00*)((char*)arNpcData + 0xc4))->GetSize() && *((bool*)arNpcData + 0xd4))
            *(Helper62d0*)&sptexBaseMod = *(void* const*)((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xc4))->GetAtPointer(ipart);
        if (ipart == 0 && cage >= 0 &&
            BSFaceGenManager_GetAsNearestDetailDDSFile(&fileDetail, *(int*)((char*)arNpcData + 0x90), (unsigned char)cage,
                         ((FNStub*)*((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xa4))->GetAtPointer(ipart))->GetFullName()))
        {
            if (((GlobalObject_004aff00*)((char*)arNpcData + 0xc4))->GetSize() == 0 ||
                *(Flt*)((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xc4))->GetAtPointer(ipart) == 0)
                ((BSFaceGenModel*)pmodelFG)
                    ->ApplyTextureCoordinate(reinterpret_cast<::FaceGenCoordinates*>(arNpcData), reinterpret_cast<::GO&>(sptexBaseMod), General_uiEGTClampSize_Get());
            g_TES->CreateTextureImage(static_cast<const char*>(fileDetail), sptexDetailMod, true, true);
            TESTexture::NormalizeTextureFilePath(fileNormal, static_cast<const char*>(fileDetail));
        }
        else
        {
            if (((GlobalObject_004aff00*)((char*)arNpcData + 0xc4))->GetSize() == 0 ||
                *(Flt*)((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xc4))->GetAtPointer(ipart) == 0)
                ((BSFaceGenModel*)pmodelFG)
                    ->ApplyTextureCoordinate(reinterpret_cast<::FaceGenCoordinates*>(arNpcData), reinterpret_cast<::GO&>(sptexBaseMod), General_uiEGTClampSize_Get());
            BSStringT<char> tempstr;
            ((ModelCalls*)*((BSSimpleArray<unsigned int,1024>*)((char*)arNpcData + 0xa4))->GetAtPointer(ipart))->GetNormalName(&tempstr);
            if (reinterpret_cast<unsigned int>(static_cast<const char*>(tempstr)))
            {
                fileNormal = "Textures\\";
                fileNormal += static_cast<const char*>(tempstr);
            }
        }
        if (reinterpret_cast<unsigned int>(static_cast<const char*>(fileNormal)))
            g_TES->CreateTextureImage(static_cast<const char*>(fileNormal), sptexNormal, true, true);
        if ((unsigned int)*(Flt*)&sptexNormal)
        {
            pshaderpropLighting->SetTexture(0, (void*)(unsigned int)*(Flt*)&sptexNormal);
            int eFormat = ((TextureFormatHelper*)GetObjectiveTargetList((void*)(unsigned int)*(Flt*)&sptexNormal))
                              ->_ref_00726070();
            bspecular = (eFormat == 5 || eFormat == 6 || eFormat == 1);
            ((LightPropHelper*)pshaderpropLighting)->BSShaderProperty_SetFlag(0, bspecular);
        }
        else if (((LightPropHelper*)pshaderpropLighting)->GetFltValue(0) == 0)
        {
            pshaderpropLighting->SetTexture(0, BSShader_GetDefNormalMap());
        }
        if (*((bool*)arNpcData + 0xd4) && ishaderindex == 0xe)
        {
            pshaderpropLighting->SetTexture2(1, (void*)(unsigned int)*(Flt*)&sptexBaseMod);
            pshaderpropLighting->SetTexture(
                1, (unsigned int)*(Flt*)&sptexDetailMod ? (void*)(unsigned int)*(Flt*)&sptexDetailMod : BSFaceGenUtils_GetDefaultDetailModulationTexture());
            ((LightPropHelper*)pshaderpropLighting)->BSShaderProperty_SetFlag(0xa, true);
            void* pmatprop = ((PropHelper*)pobj)->GetProperty(2);
            if (pmatprop && ((CellLightingTemplate*)pmatprop)->TESCombatStyle_GetWeaponMinRangeMult() < 1.0)
                ((LightPropHelper*)pmatprop)->NiMaterialProperty_SetShine(4.0f);
            if (reinterpret_cast<unsigned int>(static_cast<const char*>(fileNormal)))
            {
                char pfilename[260];
                char ptexfilename[260];
                _sprintf_s(ptexfilename, 0x104, DAT_01019f08, static_cast<const char*>(fileNormal));
                BSShaderManager::BuildTexturePath(pfilename, static_cast<const char*>(ptexfilename), "_sk", true);
                if (pfilename[0])
                {
                    GO spTempSourceTexture(0);
                    g_TES->CreateTextureImage(pfilename, spTempSourceTexture, true, true);
                    pshaderpropLighting->SetTexture3(2, 0, (void*)(unsigned int)*(Flt*)&spTempSourceTexture);
                }
            }
        }
        *(Helper62d0*)&sptexBaseMod = reinterpret_cast<void* const&>(((NP*)&sptexDetailMod)->operator=(static_cast<void*>(0)));
        ((NP*)&sptexNormal)->operator=(static_cast<void*>(0));
        unsigned int icompress = 1;
        SetGeometryCompressFlags(pobj, ishaderindex, icompress);
        pshaderpropLighting->Refresh();
    }
    for (unsigned int i = 0; i < (unsigned int)((NiNodeHelper*)apNode)->NiNode_GetChildCount(); i++)
    {
        NiAVObject* pchild = ((NiNodeHelper*)apNode)->GetAt(i);
        if (pchild)
        {
            unsigned int icompress = 1;
            if (Actor_AreReferencedValuesEqual(((NiAVObject*)pchild)->GetName(), leftEye) ||
                Actor_AreReferencedValuesEqual(((NiAVObject*)pchild)->GetName(), rightEye))
            {
                icompress = 0;
                BSShaderManager::UpdateObjectTypeRecurse(pchild, false, false);
            }
            else if (__strnicmp(*(NiFixedString*)&((NiAVObject*)pchild)->GetName(),
                                *(NiFixedString*)&hair, _strlen(*(NiFixedString*)&hair)) == 0 ||
                     Actor_AreReferencedValuesEqual(((NiAVObject*)pchild)->GetName(), headAccessory))
            {
                BSShaderManager::UpdateObjectTypeRecurse(pchild, false, false);
                void* pgeomdata = ((PropHelper*)pchild)->GetProperty(3);
                LightPropCalls* pchildgeom;
                if ((pchildgeom =
                         (LightPropCalls*)((pgeomdata == 0 ? 0
                                                           : (int)((FoldedDwordGetter1C*)pgeomdata)->GetMinLevel() == 8)
                                               ? pgeomdata
                                               : 0)) != 0)
                {
                    unsigned int uiColor = *(unsigned int*)((char*)arNpcData + 0x84);
                    *(NiColorA*)((char*)pchildgeom + 0x84) =
                        NiColorA((float)((unsigned char)(uiColor & 0xff) / 255.0),
                                  (float)((unsigned char)(((unsigned short)uiColor >> 8) & 0xff) / 255.0),
                                  (float)((unsigned char)((uiColor >> 16) & 0xff) / 255.0), 1.0f);
                    pchildgeom->Refresh();
                }
                else
                {
                    LightPropCalls* eNBTmethod;
                    if ((eNBTmethod =
                             (LightPropCalls*)((pgeomdata == 0
                                                    ? 0
                                                    : (int)((FoldedDwordGetter1C*)pgeomdata)->GetMinLevel() == 12)
                                                   ? pgeomdata
                                                   : 0)) != 0)
                    {
                        unsigned int uiColor = *(unsigned int*)((char*)arNpcData + 0x84);
                        *(NiColorA*)((char*)eNBTmethod + 0x84) =
                            NiColorA((float)((unsigned char)(uiColor & 0xff) / 255.0),
                                      (float)((unsigned char)(((unsigned short)uiColor >> 8) & 0xff) / 255.0),
                                      (float)((unsigned char)((uiColor >> 16) & 0xff) / 255.0), 1.0f);
                        eNBTmethod->Refresh();
                    }
                }
            }
            SetGeometryCompressFlags(pchild, ishaderindex, icompress);
        }
    }
    ((NiAVObject*)apNode)->UpdateSceneObject();
    reinterpret_cast<NiUpdateData*>(UpdateData)->FUN_0043d410(0.0f, false, false);
    ((NiNodeHelper*)apNode)->Update(*reinterpret_cast<const NiUpdateData*>(UpdateData));
    BSFaceGenManager_UnlockFaceGenAccess();
}
}  // namespace fnv_00655fa0

struct QueuedFile;
struct TESModel;
struct TESRace;
struct TESHair;
struct BGSHeadPart;


struct FNStub
{
    const char* GetFullName();
};
struct Flt
{
    operator unsigned int() const;
};


struct ModelLoader
{
    void QueueModelFilePath(const char*, int, QueuedFile*);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void LoadMesh(TESModel*, int, QueuedFile*, unsigned int);
    void LoadTaskFromPath(TESModel*, int, QueuedFile*, unsigned int);
};
extern ModelLoader* g_modelLoader;
struct FUN_004ac110_shell
{
    TESRace* TESNPC_GetRace();
};
struct FUN_006141f0_shell
{
    void BuildAppearance(TESActorBase*, void*, SEX, bool);
};
struct FUN_00604310_shell
{
    bool TESNPC_GetHeadPartModTextureFileName(int, char*, unsigned int);
};
struct FUN_0048cee0_shell
{
    int FUN_0048cee0();
};
struct HPList
{
    char data[8];
};
BGSHeadPart** __fastcall _ref_006815c0(HPList*);
HPList* __fastcall _ref_00726070(HPList*);
float __cdecl BSFaceGenManager_GetFaceCoordAttribute(void*, int, int);
float __cdecl floorf(float);
void __cdecl AppendNormalMapSuffix(const char*, char*);
int __cdecl BSFaceGenManager_GetAsNearestDetailDDSFile(void*, int, char, const char*);

namespace lc1 {
using ::AutoMemContext;
struct FaceGenData
{
    FaceGenData();
    ~FaceGenData();
    char m_kFaceGenCoordinates[0x80];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    BSSimpleArray<unsigned int,1024> m_kModelObjectsItem;
    BSSimpleArray<unsigned int,1024> pTexture;
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    HPList Accessories;
};
}

// Builds face-gen data for an actor and queues eye, hair, head-part and part textures/models with the model loader at the given priority.
// @fnv 0x00657150
void __cdecl QueueFaceGenAssets(TESActorBase* apNPC, int aePriority, QueuedFile* apParent)
{
    lc1::AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xe38);
    lc1::FaceGenData faceGenData;
    ((FUN_006141f0_shell*)((FUN_004ac110_shell*)apNPC)->TESNPC_GetRace())
        ->BuildAppearance(apNPC, &faceGenData, apNPC->GetSex(), true);
    if (!&faceGenData)
        return;
    char cage = (char)floorf(BSFaceGenManager_GetFaceCoordAttribute(&faceGenData, 0, 0));
    if (faceGenData.pEyes)
    {
        char pTexturePath[260];
        CopyStringChecked(pTexturePath, 260, "Textures\\");
        AppendStringChecked(pTexturePath, 260, ((FNStub*)((char*)faceGenData.pEyes + 0x24))->GetFullName());
        g_modelLoader->QueueModelFilePath(pTexturePath, aePriority, apParent);
    }
    else
    {
        g_modelLoader->QueueModelFilePath("Textures\\Characters\\Eyes\\EyeDefault.dds", aePriority, apParent);
    }
    if (faceGenData.m_pHair)
    {
        g_modelLoader->ProcessModelRequest(faceGenData.m_pHair ? (TESModel*)((char*)faceGenData.m_pHair + 0x24) : 0,
                                           aePriority, apParent, 0, false, false, true);
        char pTexturePath[260];
        CopyStringChecked(pTexturePath, 260, "Textures\\");
        AppendStringChecked(pTexturePath, 260, ((FNStub*)((char*)faceGenData.m_pHair + 0x3c))->GetFullName());
        g_modelLoader->QueueModelFilePath(pTexturePath, aePriority, apParent);
        g_modelLoader->LoadMesh(faceGenData.m_pHair ? (TESModel*)((char*)faceGenData.m_pHair + 0x24) : 0, aePriority,
                                apParent, 9);
    }
    char pheadModTexture[260];
    if (((FUN_00604310_shell*)apNPC)->TESNPC_GetHeadPartModTextureFileName(0, pheadModTexture, 260))
        g_modelLoader->QueueModelFilePath(pheadModTexture, aePriority, apParent);
    unsigned int ipart = 0;
    for (ipart = 0; ipart < 8; ++ipart)
    {
        if (ipart == 6 || ipart == 7)
            continue;
        if (!*faceGenData.m_kModelObjectsItem.GetAtPointer(ipart) || !*faceGenData.pTexture.GetAtPointer(ipart))
            continue;
        int ishaderindex = 1;
        if (ipart == 0 || ipart == 1)
            ishaderindex = 14;
        BSStringT<char> fileDetail;
        char ptextureName[260];
        CopyStringChecked(ptextureName, 260, "Textures\\");
        AppendStringChecked(ptextureName, 260, ((FNStub*)*faceGenData.pTexture.GetAtPointer(ipart))->GetFullName());
        g_modelLoader->QueueModelFilePath(ptextureName, aePriority, apParent);
        if (ipart == 0 && cage >= 0 &&
            BSFaceGenManager_GetAsNearestDetailDDSFile(&fileDetail, faceGenData.m_eSex, cage,
                         ((FNStub*)*faceGenData.pTexture.GetAtPointer(ipart))->GetFullName()))
        {
            CopyStringChecked(ptextureName, 260, static_cast<const char*>(fileDetail));
            g_modelLoader->QueueModelFilePath(ptextureName, aePriority, apParent);
        }
        char pnormalFileName[260];
        AppendNormalMapSuffix(ptextureName, pnormalFileName);
        g_modelLoader->QueueModelFilePath(pnormalFileName, aePriority, apParent);
        if (faceGenData.bFaceGenTexturing && ishaderindex == 14)
        {
            char pskinFileName[260];
            TESTexture::ConvertTexturePath(ptextureName, pskinFileName);
            g_modelLoader->QueueModelFilePath(pskinFileName, aePriority, apParent);
        }
    }
    for (ipart = 0; ipart < 8; ++ipart)
    {
        TESModel* pmodel = (TESModel*)*faceGenData.m_kModelObjectsItem.GetAtPointer(ipart);
        if (pmodel && ((FUN_0048cee0_shell*)pmodel)->FUN_0048cee0())
        {
            g_modelLoader->ProcessModelRequest(pmodel, aePriority, apParent, 0, false, false, true);
            g_modelLoader->LoadMesh(pmodel, aePriority, apParent, ipart);
            g_modelLoader->LoadTaskFromPath(pmodel, aePriority, apParent, ipart);
        }
    }
    HPList* pheadPartList = &faceGenData.Accessories;
    while (pheadPartList)
    {
        BGSHeadPart* pheadPart = *_ref_006815c0(pheadPartList);
        if (pheadPart && ((FUN_0048cee0_shell*)((char*)pheadPart + 0x24))->FUN_0048cee0())
        {
            g_modelLoader->ProcessModelRequest(pheadPart ? (TESModel*)((char*)pheadPart + 0x24) : 0, aePriority,
                                               apParent, 0, false, false, true);
            g_modelLoader->LoadMesh(pheadPart ? (TESModel*)((char*)pheadPart + 0x24) : 0, aePriority, apParent, ipart);
            g_modelLoader->LoadTaskFromPath(pheadPart ? (TESModel*)((char*)pheadPart + 0x24) : 0, aePriority, apParent,
                                            ipart);
        }
        pheadPartList = _ref_00726070(pheadPartList);
    }
}

struct ModelHelper
{
    void EnsureMorphData();
    bool LoadFaceGenTexture();
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
    operator ModelHelper*() const;
};
struct FGEntry
{
    char pad[8];
    void* model;
    unsigned int tick;
};
struct FGModelMap
{
    bool GetAt(void*, GO&);
};
unsigned int __cdecl gm_GetTickCount();
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();

struct FGModelCache
{
    char pad[4];
    FGModelMap map;
    char pad2[0x1b];
    bool loaded;
    void BSFaceGenModelMap_VerifyData(int);
    bool BSFaceGenModelMap_GetAt(void* key, Helper62d0* out);
};

// @fnv 0x00650200
// src: COMMUNITY 0x00650200
bool FGModelCache::BSFaceGenModelMap_GetAt(void* key, Helper62d0* out)
{
    BSFaceGenManager_LockFaceGenAccess();
    GO entry(0);
    bool res = false;
    if (map.GetAt(key, entry))
    {
        static_cast<FGEntry*>(entry)->tick = gm_GetTickCount();
        *out = static_cast<FGEntry*>(entry)->model;
        BSFaceGenModelMap_VerifyData(reinterpret_cast<int>(static_cast<FGEntry*>(entry)));
        static_cast<ModelHelper*>(*out)->EnsureMorphData();
        static_cast<ModelHelper*>(*out)->LoadFaceGenTexture();
        loaded = true;
        res = true;
    }
    BSFaceGenManager_UnlockFaceGenAccess();
    return res;
}

namespace fnv_00650930 {
struct ModelHelper
{
    unsigned int GetEGMSize();
    unsigned int BSFaceGenModel_GetEGTDataSize();
};
struct Helper62d0
{
    operator ModelHelper*() const;
};
struct FGEntry
{
    char pad[8];
    Helper62d0 model;
};
// The face-gen model map at +4 of the manager; GetFirstPos is the folded hash-map iterator start (NiTMapBase::GetFirstPos).
struct FaceGenModelMapPositions
{
    void* GetFirstPos();
};
struct Map62d0
{
    void NiTMap_Ptr_GetNext(void*&, unsigned int&, GO&);
};
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();

struct FGMapOwner
{
    char pad[4];
    FaceGenModelMapPositions map;
    unsigned int GetModelValueSum(int which);
};

// Iterates the map's positions, accumulating either GetEGMSize or FUN_0065c490 results from each entry's model based on which, and returns the sum.
// @fnv 0x00650930
unsigned int FGMapOwner::GetModelValueSum(int aiMode)
{
    void* pos2;
    unsigned int id6 = 0;
    GO ptr(0);
    unsigned int result3 = 0;
    BSFaceGenManager_LockFaceGenAccess();
    pos2 = map.GetFirstPos();
    while (pos2)
    {
        reinterpret_cast<Map62d0*>(&map)->NiTMap_Ptr_GetNext(pos2, id6, ptr);
        switch (aiMode)
        {
        case 0:
            result3 += static_cast<ModelHelper*>(reinterpret_cast<FGEntry*>(static_cast<::FGEntry*>(ptr))->model)->GetEGMSize();
            break;
        case 1:
            result3 += static_cast<ModelHelper*>(reinterpret_cast<FGEntry*>(static_cast<::FGEntry*>(ptr))->model)->BSFaceGenModel_GetEGTDataSize();
            break;
        }
    }
    BSFaceGenManager_UnlockFaceGenAccess();
    return result3;
}
}  // namespace fnv_00650930

namespace fnv_00650ea0 {
using ::AutoMemContext;
struct OpaqueDataBlock
{
    void* __vecDelDtor(unsigned int);
    char ctl[24];
    char label[28];
};
typedef char _sizecheck_FanLinCtlS[sizeof(OpaqueDataBlock) == 52 ? 1 : -1];

namespace lc1 {
using ::AutoMemContext;
}

struct NarrowString
{
    NarrowString(const char* pName);
    ~NarrowString();
    void* _Alval;
    char _Bx[16];
    unsigned int _Mysize;
    unsigned int _Myres;
};




}  // namespace fnv_00650ea0

class FaceGenAlphaProperty
{
  public:
    static void* operator new(unsigned int stSize);
    static void operator delete(void* pMem, unsigned int);
    FaceGenAlphaProperty();
    void IncRefCount();
    void DecRefCount();
    void SetFlag512(bool bValue);
    void SetFlags(unsigned short usFlags);
    void NiAlphaProperty_SetTestRef(unsigned char ucRef);
    char data[0x1c];
};

namespace fnv_00650ea0 {


struct TextureFormatPreferences
{
    int ePixelLayout;
    int eAlphaFmt;
    int eMipMapped;
};

bool __cdecl fanReadCtlFile(const NarrowString& kFile, FaceGenSam* pSam, unsigned int* pTileTexture, unsigned int* pInfo,
                          FaceGenCtls* pCtls, FaceGenModels* pModels);
NiTexture* __cdecl NiSourceTexture_Create(NiPixelData* pkPixelData, const char* pcName, const TextureFormatPreferences& kPrefs);
int Warning(const char* pcFormat, ...);
extern TextureFormatPreferences DAT_011a9598;
extern const NiPixelFormat gNiPoint3StartupSrc;
extern bool DAT_011d59e0;

}  // namespace fnv_00650ea0

// Constructs the manager: loads the CTL file, sizes coordinate arrays, creates the alpha property and default base/detail textures, and sets DAT_011d59e0.
// @fnv 0x00650ea0
BSFaceGenManager::BSFaceGenManager()
    : m_spAlpha(0), m_spBaseTexture(0), m_spDetailTexture(0)
{
    using namespace fnv_00650ea0;
    NiPixelData* pdetailpixeldata;
    unsigned char* pdecalpixels;
    fnv_00650ea0::lc1::AutoMemContext tempMemContext(
        55, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 692);
    NiPixelData* pbasepixeldata;
    unsigned char* pbasepixels;
    fnv_00650ea0::OpaqueDataBlock* pctl = 0;

    if (!fanReadCtlFile("FACEGEN\\SI.CTL", &m_kSam, &m_kSam.uiTex, m_auiInfo, &m_kCtls, &m_kModels))
    {
        if (!fanReadCtlFile("FACEGEN\\SI.CTL", &m_kSam, &m_kSam.uiTex, m_auiInfo, &m_kCtls, &m_kModels))
        {
            Warning("MODELS: Unable to load CTL file");
        }
    }

    for (unsigned int i = 0; i < 2; ++i)
    {
        for (unsigned int j = 0; j < 2; ++j)
        {
            if (m_kCtls.ctl[i][j].std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size())
            {
                pctl = reinterpret_cast<fnv_00650ea0::OpaqueDataBlock*>(m_kCtls.ctl[i][j].GetElementPointerChecked(0));
                if (pctl)
                {
                    m_kSam.coords[i][j].resize(reinterpret_cast<FaceGenMatrix<float>*>(pctl->ctl)->FUN_00441110(),
                                               reinterpret_cast<FaceGenMatrix<float>*>(pctl->ctl)->NiAVObject_GetParent());
                }
            }
            else
            {
                m_kSam.coords[i][j].resize(0, 0);
            }
        }
    }

    m_pModelCache = 0;

    m_spAlpha = new FaceGenAlphaProperty;
    m_spAlpha->SetFlag512(true);
    m_spAlpha->SetFlags(4);
    m_spAlpha->NiAlphaProperty_SetTestRef(100);

    pbasepixeldata = new NiPixelData(32, 32, &gNiPoint3StartupSrc, 1, 1);
    pbasepixels = pbasepixeldata->GetPixels(0, 0);
    memset(pbasepixels, 128, 4096);
    pbasepixeldata->AddString();
    pbasepixeldata->SetOwnsPixelData(true);
    m_spBaseTexture = NiSourceTexture_Create(pbasepixeldata, NiFixedString("DefaultBaseModFaceGenTexture"), DAT_011a9598);

    pdetailpixeldata = new NiPixelData(32, 32, &gNiPoint3StartupSrc, 1, 1);
    pdecalpixels = pdetailpixeldata->GetPixels(0, 0);
    for (int i = 0; i < 1024; ++i)
    {
        pdecalpixels[i * 4] = 62;
        pdecalpixels[i * 4 + 1] = 65;
        pdecalpixels[i * 4 + 2] = 62;
        pdecalpixels[i * 4 + 3] = 64;
    }
    pdetailpixeldata->AddString();
    pdetailpixeldata->SetOwnsPixelData(true);
    m_spDetailTexture = NiSourceTexture_Create(pdetailpixeldata, NiFixedString("DefaultDetailModFaceGenTexture"), DAT_011a9598);

    DAT_011d59e0 = true;
}

// Creates a BSFaceGenManager singleton into DAT_011d59e8 if it is not already set, under an AutoMemContext.
// @fnv 0x006519f0
// src: XBOX_PDB 0x006519f0
void BSFaceGenManager_InitializeSystem()
{
    AutoMemContext context(static_cast<MEM_CONTEXT>(0x37), true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp",
                           0x316);
    if (DAT_011d59e8)
        return;

    DAT_011d59e8 = new BSFaceGenManager();
}


namespace fnv_00651450 {
struct FUN_00651520
{
    int b[0xa0 / 4];
    FUN_00651520();
    ~FUN_00651520();
};
struct FUN_00651630
{
    int b[0x28 / 4];
    FUN_00651630();
    ~FUN_00651630();
};
struct FUN_00651670
{
    int b[0x48 / 4];
    FUN_00651670();
    ~FUN_00651670();
};
struct FUN_00651450
{
    bool initialized;
    FUN_00651520 m_kFaceGenRecords[5];
    FUN_00651630 attr[20];
    FUN_00651670 race[25];
    FaceGenMatrix<float> basis[20];
    FUN_00651450();
};

// Initializes the object by setting the initialized flag to false; the member arrays are default-constructed.
// @fnv 0x00651450
FUN_00651450::FUN_00651450() : initialized(false)
{}
}  // namespace fnv_00651450

struct FGModelPtr
{
    operator BSFaceGenModel*() const;
};
struct FGHolder
{
    char pad[8];
    FGModelPtr model;
};

namespace fnv_00651e70 {
// The face-gen model map at +4 of the manager; GetFirstPos is the folded hash-map iterator start (NiTMapBase::GetFirstPos).
struct FaceGenModelMapPositions
{
    void* GetFirstPos();
};
struct Map62d0
{
    void NiTMap_Ptr_GetNext(void*&, unsigned int&, GO&);
};
struct FGManagerView
{
    char pad[4];
    FaceGenModelMapPositions map;
    void ClearModelTextures();
};
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();

// Calls FUN_00652140, iterates positions from map, clears texture data on each model found, then calls FUN_00652190.
// @fnv 0x00651e70
void FGManagerView::ClearModelTextures()
{
    BSFaceGenManager_LockFaceGenAccess();
    void* pos = map.GetFirstPos();
    while (pos)
    {
        unsigned int id = 0;
        GO ptr(0);
        reinterpret_cast<Map62d0*>(&map)->NiTMap_Ptr_GetNext(pos, id, ptr);
        if (ptr)
        {
            BSFaceGenModel* model = static_cast<FGHolder*>(ptr)->model;
            if (model)
                model->ClearTextureData();
        }
    }
    BSFaceGenManager_UnlockFaceGenAccess();
}
}  // namespace fnv_00651e70

namespace fnv_00651f70 {
namespace lc1 {
using ::AutoMemContext;
}
struct FaceGenImpl
{
    bool BSFaceGenModelMap_LoadEGMData(int);
};

// Checks that the FaceGen manager and its impl exist, then forwards param_1 to impl->FUN_00650480 and returns its result.
// @fnv 0x00651f70
// src: COMMUNITY 0x00651f70
bool BSFaceGenManager_LoadEGMData(int aiArg)
{
    lc1::AutoMemContext ctx(
        0x38, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0x44c);
    if (!DAT_011d59e8)
        return false;
    if (!reinterpret_cast<FaceGenImpl*>(DAT_011d59e8->m_pModelCache))
        return false;
    return reinterpret_cast<FaceGenImpl*>(DAT_011d59e8->m_pModelCache)->BSFaceGenModelMap_LoadEGMData(aiArg);
}
}  // namespace fnv_00651f70

namespace fnv_00652040 {
namespace lc1 {
using ::AutoMemContext;
}
struct FaceGenImpl
{
    bool TouchCachedModel(int);
};

// Checks that the FaceGen manager and its implementation exist, then forwards param_1 to the implementation's TouchCachedModel and returns its result.
// @fnv 0x00652040
// src: COMMUNITY 0x00652040
bool BSFaceGenManager_LoadEGTData(int aiArg)
{
    lc1::AutoMemContext ctx(
        0x39, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0x45a);
    if (!DAT_011d59e8)
        return false;
    if (!reinterpret_cast<FaceGenImpl*>(DAT_011d59e8->m_pModelCache))
        return false;
    return reinterpret_cast<FaceGenImpl*>(DAT_011d59e8->m_pModelCache)->TouchCachedModel(aiArg);
}
}  // namespace fnv_00652040

namespace fnv_00653520 {

struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
char* __cdecl strrchr_0040ab30(char*, int);
int _sprintf_s(char*, unsigned int, const char*, ...);
extern const char* DAT_0119b734[2];

// @fnv 0x00653520
const char* BuildEgmFilename(BSStringT<char>* aOutFilename, const char* apModel, int aeHairPart)
{
    char porigFilename[260];
    char pfinalFilename[260];
    char* pextension = 0;

    if (!apModel)
        return 0;
    TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = strrchr_0040ab30(porigFilename, 0x2e);
    if (!pextension)
        return 0;
    *pextension = 0;
    switch (aeHairPart)
    {
    case 0:
    case 1:
        _sprintf_s(pfinalFilename, 260, "%s%s.egm", porigFilename, DAT_0119b734[aeHairPart]);
        break;
    default:
        _sprintf_s(pfinalFilename, 260, "%s.egm", porigFilename);
        break;
    }
    aOutFilename->Set(pfinalFilename, 0);
    return *aOutFilename;
}
}  // namespace fnv_00653520

extern int sprintf_s(char*, unsigned int, const char*, ...);
extern char* __cdecl strrchr_0040ab30(char*, int);

// @fnv 0x006537d0
const char* __cdecl GetModelEgtFilename(BSStringT<char>* aOutFilename, const char* apModel)
{
    char porigFilename[260];
    char pfinalFilename[260];
    char* pextension = 0;
    if (!apModel)
        return 0;
    CopyStringChecked(porigFilename, 260, apModel);
    pextension = strrchr_0040ab30(porigFilename, '.');
    if (!pextension)
        return 0;
    *pextension = 0;
    sprintf_s(pfinalFilename, 260, "%s.egt", porigFilename);
    aOutFilename->Set(pfinalFilename, 0);
    return *aOutFilename;
}

struct NPX
{
    void* p;
    NPX(int);
    ~NPX();
    operator unsigned int() const;
};

// Returns the value stored at offset 0x1198 of DAT_011d59e8, or 0 when DAT_011d59e8 is null.
// @fnv 0x00655270
// src: XBOX_PDB 0x00655270
unsigned int __cdecl BSFaceGenManager_GetHairTeethAlphaProperty()
{
    return (unsigned int)(DAT_011d59e8 ? *reinterpret_cast<NPX*>(&DAT_011d59e8->m_spAlpha) : NPX(0));
}

namespace fnv_00655320 {
struct NiStream;
struct TESHair;
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct FaceGenData
{
    void* __vecDelDtor(unsigned int);
    char m_kFaceGenCoordinates[96];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    char m_kModelObjectsItem[16];
    char pTexture[16];
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad_b6[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    char Accessories[8];
};
typedef char _sizecheck_FaceGenNpcData[sizeof(FaceGenData) == 204 ? 1 : -1];
using ::AutoMemContext;


class BSFaceGenNiNode;
using ::NiSourceTexture;
namespace lc1 {
using ::AutoMemContext;
}

struct FNStub
{
    const char* GetFullName();
};

extern TES* g_TES;
class BSFileEntry;
using ::NiSourceTexture;
struct FaceGenData;
struct TESHair;
struct V3;
extern V3 _NiPoint3_ZERO;
struct FileNameHash
{
    FileNameHash();
    static void __cdecl CreateDirectoryAndFileHashes(const char* apPath, FileNameHash& arDir, FileNameHash& arFile);
    unsigned int iData[2];
};
struct ArchiveManager
{
    static BSFileEntry* __cdecl FindFileEntry(ARCHIVE_TYPE_INDEX aeType, FileNameHash& arDir, FileNameHash& arFile,
                                              const char* apPath);
};


const char* __cdecl BuildEgmFilename(BSStringT<char>* apOut, const char* apModel, int aePart);
const char* __cdecl BuildTriPathAndSet(BSStringT<char>* apOut, const char* apModel, int aePart);
BSFaceGenModel* __cdecl GetOrCreateFaceGenModel(const char* apEGM, const char* apModel, const char* apTRI, int a4,
                                                int a5, int aePart, int a7);
void __cdecl BSFaceGenManager_ApplyHairMorph(NiTriBasedGeom* apShape, float afLength);
NiObject* __cdecl BSFaceGenManager_GetHairTeethAlphaProperty();


// @fnv 0x00655320
void BuildHairFaceGenNodes(BSFaceGenNiNode** apOutNodeBiped, BSFaceGenNiNode** apOutNodeSkinned, FaceGenData* aNpcData,
                           bool abForceNoSkinning)
{
    lc1::AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xb3b);
    BSStringT<char> filename;
    BSStringT<char> fileEGM;
    BSStringT<char> fileTRI;
    BSStringT<char> fileEGT;
    BSStringT<char> fileFIM;
    NiPointer<NiSourceTexture> sptexBase(0);
    NiPointer<NiTriBasedGeom> spshape(0);
    NiMatrix3 matrot;
    ((NiMatrix3*)&matrot)->MakeYRotation(-1.5707964f);
    if (*(TESHair**)((char*)aNpcData + 0x80))
    {
        for (int ehairPart = 0; ehairPart < 2; ehairPart++)
        {
            filename.PrintfString(
                "Meshes\\%s",
                ((TESModel*)((char*)*(TESHair**)((char*)aNpcData + 0x80) + 0x24))->GetModelFilePath());
            const char* pegm = BuildEgmFilename(&fileEGM, filename, ehairPart);
            const char* ptri = BuildTriPathAndSet(&fileTRI, filename, ehairPart);
            BSFaceGenModel* pmodelFG = 0;
            FileNameHash dirHash;
            FileNameHash fileHash;
            FileNameHash::CreateDirectoryAndFileHashes(pegm, dirHash, fileHash);
            BSFileEntry* pEntry = ArchiveManager::FindFileEntry(ARCHIVE_TYPE_INDEX_MESHES, dirHash, fileHash, pegm);
            if (!pEntry)
            {
                if (ehairPart == 0)
                {
                    pegm = BuildEgmFilename(&fileEGM, filename, -1);
                    ptri = BuildTriPathAndSet(&fileTRI, filename, -1);
                    pmodelFG = GetOrCreateFaceGenModel(pegm, filename, ptri, 0, 1, ehairPart, 0);
                    ehairPart = 2;
                }
            }
            else
            {
                pmodelFG = GetOrCreateFaceGenModel(pegm, filename, ptri, 0, 1, ehairPart, 0);
            }
            if (pmodelFG)
                pmodelFG->ApplyFaceGenMorphs(reinterpret_cast<::FaceGenData*>(aNpcData), reinterpret_cast<::NiPointer<::NiTriBasedGeom>&>(spshape));
            if (spshape)
            {
                if (ehairPart == 1)
                    ((NiTriBasedGeom*)spshape)->FUN_00450f90(true);
                char tempHairName[32];
                ((NiObjectNET*)(NiTriBasedGeom*)spshape)
                    ->SetName(NiFixedString(static_cast<const char*>(BSFaceGenManager::BuildFaceGenPartPath(tempHairName, ehairPart))));
                BSFaceGenManager_ApplyHairMorph(spshape, *(float*)((char*)aNpcData + 0x88));
                filename.PrintfString("Textures\\%s",
                                 ((FNStub*)((char*)*(TESHair**)((char*)aNpcData + 0x80) + 0x3c))->GetFullName());
                g_TES->CreateTextureImage(filename, sptexBase, false, false);
                if (sptexBase)
                {
                    BSShaderPPLightingProperty* pshaderprop;
                    NiShadeProperty* pprop = (NiShadeProperty*)((NiTriBasedGeom*)spshape)->GetProperty(3);
                    if ((pshaderprop =
                             (BSShaderPPLightingProperty*)((pprop == 0
                                                                   ? 0
                                                                   : (pprop->FUN_00441110() >= 8 &&
                                                                      pprop->FUN_00441110() <= 12))
                                                                  ? pprop
                                                                  : 0)) != 0)
                        reinterpret_cast<void (__thiscall*)(BSShaderPPLightingProperty*, int, int, NiSourceTexture*)>((*reinterpret_cast<void***>(pshaderprop))[60])(pshaderprop, 0, 0, sptexBase);
                }
                if (!((NiTriBasedGeom*)spshape)->GetProperty(0))
                    ((NiTriBasedGeom*)spshape)->AttachProperty(BSFaceGenManager_GetHairTeethAlphaProperty());
                if (((NiTriBasedGeom*)spshape)->GetSkinInstance())
                {
                    if (abForceNoSkinning)
                    {
                        ((NiTriBasedGeom*)spshape)->SetSkinInstance(0);
                        reinterpret_cast<NiAVObject*>((NiTriBasedGeom*)spshape)->NiAVObject_SetTranslate(*reinterpret_cast<const NiPoint3*>(&_NiPoint3_ZERO));
                        reinterpret_cast<NiAVObject*>((NiTriBasedGeom*)spshape)->SetRotate_0043fa80(matrot);
                        ((::BSFaceGenNiNode*)*apOutNodeBiped)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                    }
                    else
                    {
                        ((::BSFaceGenNiNode*)*apOutNodeSkinned)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                    }
                }
                else
                {
                    reinterpret_cast<NiAVObject*>((NiTriBasedGeom*)spshape)->SetRotate_0043fa80(matrot);
                    ((::BSFaceGenNiNode*)*apOutNodeBiped)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                }
            }
            pmodelFG = 0;
            spshape = 0;
            sptexBase = 0;
        }
    }
}
}  // namespace fnv_00655320

namespace fnv_006558b0 {
struct NiStream;

struct TESHair;

struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct FaceGenData
{
    void* __vecDelDtor(unsigned int);
    char m_kFaceGenCoordinates[96];
    TESHair* m_pHair;
    int iHairColor;
    float m_fHairLength;
    TESEyes* pEyes;
    int m_eSex;
    char m_kModelObjectsItem[16];
    char pTexture[16];
    char m_kTexturePaths[16];
    char m_kFaceGenTextures[16];
    bool bFaceGenTexturing;
    bool m_bFaceGenDataValid;
    char _pad_b6[2];
    TESModel* m_pHeadModel;
    TESModel* m_pFaceGenModel;
    int m_eFaceGenLOD;
    char Accessories[8];
};
typedef char _sizecheck_FaceGenNpcData[sizeof(FaceGenData) == 204 ? 1 : -1];
using ::AutoMemContext;


namespace lc1 {
using ::AutoMemContext;
}


using ::NiSourceTexture;
class NiSkinInstance;



extern TES* g_TES;
BSFaceGenModel* __cdecl GetOrCreateFaceGenModel(const char*, const char*, const char*, int, bool, int, int);
const char* __cdecl BuildEgmFilename(BSStringT<char>&, const char*, int);
const char* __cdecl BuildTriPathAndSet(BSStringT<char>&, const char*, int);

// Builds the left and right eye geometry from the NPC's eye models, applies the eye texture, and attaches each shape to the biped or skinned node.
// @fnv 0x006558b0
void __cdecl CreateEyeGeometry(BSFaceGenNiNode** apOutNodeBiped, BSFaceGenNiNode** apOutNodeSkinned,
                               FaceGenData* aNpcData, bool abForceNoSkinning)
{
    lc1::AutoMemContext tempMemContext(
        0x37, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0xba7);
    BSStringT<char> filename;
    BSStringT<char> fileEGM;
    BSStringT<char> fileTRI;
    BSStringT<char> fileEGT;
    BSStringT<char> fileFIM;
    NiPointer<NiSourceTexture> sptexBase(0);
    NiPointer<NiTriBasedGeom> spshape(0);
    NiMatrix3 matrot;
    BSFaceGenModel* pmodelFG = 0;
    matrot.MakeYRotation(-1.5707964f);
    if (*(TESModel**)((char*)aNpcData + 0xd8))
    {
        filename.PrintfString("Meshes\\%s", (*(TESModel**)((char*)aNpcData + 0xd8))->GetModelFilePath());
        pmodelFG = GetOrCreateFaceGenModel(BuildEgmFilename(fileEGM, filename, -1), filename,
                                           BuildTriPathAndSet(fileTRI, filename, -1), 0, true, -1, 0);
        if (pmodelFG)
            pmodelFG->ApplyFaceGenMorphs(reinterpret_cast<::FaceGenData*>(aNpcData), reinterpret_cast<::NiPointer<::NiTriBasedGeom>&>(spshape));
        if (spshape)
        {
            spshape->SetName(NiFixedString("FaceGenEyeLeft"));
            if (*(TESEyes**)((char*)aNpcData + 0x8c))
            {
                filename.PrintfString("Textures\\%s", reinterpret_cast<TESTexture*>((char*)*(TESEyes**)((char*)aNpcData + 0x8c) + 0x24)->GetTextureResourceName());
                g_TES->CreateTextureImage(filename, sptexBase, false, false);
            }
            else
            {
                g_TES->CreateTextureImage("Textures\\Characters\\Eyes\\EyeDefault.dds", sptexBase, false, false);
            }
            if (sptexBase)
            {
                NiShadeProperty* pprop = spshape->GetProperty(3);
                BSShaderPPLightingProperty* pshaderprop;
                if (pshaderprop = (pprop == 0 ? 0 : (pprop->FUN_00441110() >= 8 && pprop->FUN_00441110() <= 12))
                                      ? (BSShaderPPLightingProperty*)pprop
                                      : 0)
                    reinterpret_cast<void (__thiscall*)(BSShaderPPLightingProperty*, int, int, NiSourceTexture*)>((*reinterpret_cast<void***>(pshaderprop))[60])(pshaderprop, 0, 0, sptexBase);
            }
            if (spshape->GetSkinInstance())
            {
                if (abForceNoSkinning)
                {
                    spshape->SetSkinInstance(0);
                    spshape->NiAVObject_SetTranslate(NiPoint3::ZERO);
                    spshape->SetLocalRotation(matrot);
                    (*apOutNodeBiped)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                }
                else
                {
                    (*apOutNodeSkinned)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                }
            }
            else
            {
                spshape->SetLocalRotation(matrot);
                (*apOutNodeBiped)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
            }
        }
        pmodelFG = 0;
        spshape = 0;
        sptexBase = 0;
    }
    if (*(TESModel**)((char*)aNpcData + 0xdc))
    {
        filename.PrintfString("Meshes\\%s", (*(TESModel**)((char*)aNpcData + 0xdc))->GetModelFilePath());
        pmodelFG = GetOrCreateFaceGenModel(BuildEgmFilename(fileEGM, filename, -1), filename,
                                           BuildTriPathAndSet(fileTRI, filename, -1), 0, true, -1, 0);
        if (pmodelFG)
            pmodelFG->ApplyFaceGenMorphs(reinterpret_cast<::FaceGenData*>(aNpcData), reinterpret_cast<::NiPointer<::NiTriBasedGeom>&>(spshape));
        if (spshape)
        {
            spshape->SetName(NiFixedString("FaceGenEyeRight"));
            if (*(TESEyes**)((char*)aNpcData + 0x8c))
            {
                filename.PrintfString("Textures\\%s", reinterpret_cast<TESTexture*>((char*)*(TESEyes**)((char*)aNpcData + 0x8c) + 0x24)->GetTextureResourceName());
                g_TES->CreateTextureImage(filename, sptexBase, false, false);
            }
            else
            {
                g_TES->CreateTextureImage("Textures\\Characters\\Eyes\\EyeDefault.dds", sptexBase, false, false);
            }
            if (sptexBase)
            {
                NiShadeProperty* pprop = spshape->GetProperty(3);
                BSShaderPPLightingProperty* pshaderprop;
                if (pshaderprop = (pprop == 0 ? 0 : (pprop->FUN_00441110() >= 8 && pprop->FUN_00441110() <= 12))
                                      ? (BSShaderPPLightingProperty*)pprop
                                      : 0)
                    reinterpret_cast<void (__thiscall*)(BSShaderPPLightingProperty*, int, int, NiSourceTexture*)>((*reinterpret_cast<void***>(pshaderprop))[60])(pshaderprop, 0, 0, sptexBase);
            }
            if (spshape->GetSkinInstance())
            {
                if (abForceNoSkinning)
                {
                    spshape->SetSkinInstance(0);
                    spshape->NiAVObject_SetTranslate(NiPoint3::ZERO);
                    spshape->SetLocalRotation(matrot);
                    (*apOutNodeBiped)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                }
                else
                {
                    (*apOutNodeSkinned)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
                }
            }
            else
            {
                spshape->SetLocalRotation(matrot);
                (*apOutNodeBiped)->AttachChildInAvailableSlot(reinterpret_cast<::NiAVObject*>((NiTriBasedGeom*)spshape), true);
            }
        }
        pmodelFG = 0;
        spshape = 0;
        sptexBase = 0;
    }
}
}  // namespace fnv_006558b0

namespace fnv_00653340 {
struct NiStream;
struct FaceGenVertexIterator
{
    NiPoint3* current;
    unsigned int stride;
    unsigned int position;
};

typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FourComponentNumericValue
{
    char u[16];
};
typedef char _sizecheck___vector4[sizeof(FourComponentNumericValue) == 16 ? 1 : -1];

struct Flt
{
    operator unsigned int() const;
};
struct ScrapMultiMapHelper
{
    void SetPoint(NiPoint3 const&);
    void AddToA();
};
NiExtraData* __cdecl GetExtraDataIfPresent(NiAVObject*);
int __fastcall _ref_0084e3a0(NiExtraData*);
int __fastcall FUN_0049ec60(NiAVObject*);

// @fnv 0x00653340
// src: COMMUNITY 0x00653340
void BSFaceGenUtils_RefreshMeshFromBaseMorphExtraData(NiAVObject* apGeom, NiPoint3* apPoint)
{
    NiExtraData* base = fnv_00653340::GetExtraDataIfPresent(apGeom);
    if (!base)
        return;
    if (!reinterpret_cast<Flt*>(apPoint)->operator unsigned int())
        return;
    FaceGenVertexIterator iter = *reinterpret_cast<FaceGenVertexIterator*>(apPoint);
    unsigned int aI = 0;
    NiPoint3* pSource = reinterpret_cast<NiPoint3*>(_ref_0084e3a0(base));
    for (; aI < reinterpret_cast<NiTriBasedGeom*>(apGeom)->GetNumberOfVertices(); ++aI, ++pSource)
    {
        reinterpret_cast<ScrapMultiMapHelper*>(&iter)->SetPoint(*pSource);
        reinterpret_cast<ScrapMultiMapHelper*>(&iter)->AddToA();
    }
    if (FUN_0049ec60(apGeom))
        reinterpret_cast<NiGeometry*>(apGeom)->GetModelData()->SetDirtyFlags(1);
}
}  // namespace fnv_00653340


// @fnv 0x00508120
// src: XBOX_PDB 0x00508120
float __fastcall NiControllerSequence_GetLastTime(BSFaceGenMorphData* data)
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(data) + 0x34);
}

namespace fnv_0064ffd0 {

struct Flt
{
    operator unsigned int() const;
};
struct SpObst
{
    void* m_pObject;
    SpObst(unsigned int*);
    SpObst(const SpObst&);
    ~SpObst();
};
struct FGModelCacheEntry
{
    unsigned int m_uiRefCount;
    const char* pcKey;
    void* m_pRenderedNodeEntry;
    unsigned int ulFadeStartTimeTick;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    FGModelCacheEntry();
};
struct MapH
{
    bool RemoveAt(unsigned int);
    void InsertOrUpdate(unsigned int, SpObst);
};
struct FGModelCache
{
    void BSFaceGenModelMap_VerifyData(int);
    void BSFaceGenModelMap_SetAt(const char* apcKey, void* apModel);
};
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
unsigned int __cdecl gm_GetTickCount();

// @fnv 0x0064ffd0
// src: COMMUNITY 0x0064ffd0
void FGModelCache::BSFaceGenModelMap_SetAt(const char* apcKey, void* apModel)
{
    BSFaceGenManager_LockFaceGenAccess();
    GO spentry(0);
    if (!apModel)
    {
        ((MapH*)((char*)this + 4))->RemoveAt((unsigned int)apcKey);
        BSFaceGenManager_UnlockFaceGenAccess();
        return;
    }
    (NP&)spentry = new FGModelCacheEntry();
    *(NP*)((unsigned int)(Flt&)spentry + 8) = apModel;
    *(unsigned int*)((unsigned int)(Flt&)spentry + 0xc) = gm_GetTickCount();
    ((MapH*)((char*)this + 4))->InsertOrUpdate((unsigned int)apcKey, SpObst((unsigned int*)&spentry));
    BSFaceGenModelMap_VerifyData((Flt&)spentry);
    BSFaceGenManager_UnlockFaceGenAccess();
}
}  // namespace fnv_0064ffd0

namespace fnv_00650780 {
struct Flt
{
    operator unsigned int() const;
};
struct FGModelMap
{
    bool GetAt(void*, GO&);
};
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
char* __cdecl strrchr_0040ab30(char*, int);
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
void __fastcall BSFaceGenModel_KillTextureData(unsigned int);

struct BSFaceGenModelMap_t
{
    bool BSFaceGenModelMap_KillModelTextureData(const char* apKey);
};

// Looks up apKey in the model map, retries with a .egm extension if missing, and returns true when an entry is found.
// @fnv 0x00650780
// src: COMMUNITY 0x00650780
bool BSFaceGenModelMap_t::BSFaceGenModelMap_KillModelTextureData(const char* apKey)
{
    if (!apKey || !*apKey)
        return false;
    bool bres = false;
    GO spentry(0);
    BSFaceGenManager_LockFaceGenAccess();
    if (!((FGModelMap*)((char*)this + 4))->GetAt((void*)apKey, spentry))
    {
        char* pext;
        char ptemp[260];
        TaskQueueInterface::CopyStringToBuffer(ptemp, 260, apKey);
        pext = strrchr_0040ab30(ptemp, '.');
        if (pext)
        {
            *pext = 0;
            AppendStringChecked(ptemp, 260, ".egm");
            ((FGModelMap*)((char*)this + 4))->GetAt(ptemp, spentry);
        }
    }
    if ((Flt&)spentry)
    {
        BSFaceGenModel_KillTextureData(*(Flt*)((unsigned int)(Flt&)spentry + 8));
        bres = true;
    }
    BSFaceGenManager_UnlockFaceGenAccess();
    return bres;
}
}  // namespace fnv_00650780

namespace fnv_00650ba0 {
struct Flt
{
    operator unsigned int() const;
};
struct Dummy_00650910
{
    int GetArrayElement(int);
};
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
unsigned int __fastcall GetEGMSize(unsigned int);
unsigned int __fastcall BSFaceGenModel_GetEGTDataSize(unsigned int);

struct BSFaceGenModelMap_t : Dummy_00650910
{
    void BSFaceGenModelMap_VerifyData(void* aspNewEntry);
    unsigned int GetModelValueSum(unsigned int);
    void BSFaceGenModelMap_FreeLRUData(unsigned int, void*);
};

// @fnv 0x00650ba0
// src: COMMUNITY 0x00650ba0
void BSFaceGenModelMap_t::BSFaceGenModelMap_VerifyData(void* aspNewEntry)
{
    unsigned int size;
    unsigned int cnt;
    unsigned int totalSizePrev;
    unsigned int totalSize;
    size = 0;
    BSFaceGenManager_LockFaceGenAccess();
    for (cnt = 0; cnt < 2; cnt++)
    {
        if (aspNewEntry)
        {
            switch (cnt)
            {
            case 0:
                if (GetEGMSize(*(Flt*)((char*)aspNewEntry + 8)) > 0)
                    continue;
                size = 10;
                break;
            case 1:
                if (BSFaceGenModel_GetEGTDataSize(*(Flt*)((char*)aspNewEntry + 8)) > 0)
                    continue;
                size = 10;
                break;
            default:
                size = 0;
            }
        }
        totalSize = totalSizePrev = GetModelValueSum(cnt);
        while (totalSize + size > GetArrayElement(cnt))
        {
            totalSizePrev = totalSize;
            BSFaceGenModelMap_FreeLRUData(cnt, aspNewEntry);
            totalSize = GetModelValueSum(cnt);
            if (totalSize == totalSizePrev)
                break;
        }
    }
    BSFaceGenManager_UnlockFaceGenAccess();
}
}  // namespace fnv_00650ba0

namespace fnv_00651830 {
struct FUN_006515b0
{
    FaceGenMatrix<float> kSymmetric;
    FaceGenMatrix<float> kAsymmetric;
    FaceGenMatrix<float> kTexture;
    FaceGenMatrix<float> kGeometry;
    FaceGenMatrix<float> kDetail;
    ~FUN_006515b0();
};

struct FUN_00651650
{
    unsigned int uiID;
    unsigned int uiFlags;
    FaceGenMatrix<float> kCoord;
    ~FUN_00651650();
};

struct FUN_006516a0
{
    unsigned int uiID;
    unsigned int uiFlags;
    FaceGenMatrix<float> kSymmetric;
    FaceGenMatrix<float> kAsymmetric;
    ~FUN_006516a0();
};

struct FUN_00651830
{
    unsigned int uiVersion;
    FUN_006515b0 kModes[5];
    FUN_00651650 kLinear[20];
    FUN_006516a0 kMorphs[25];
    FaceGenMatrix<float> kCoords[20];
    ~FUN_00651830();
};

// @fnv 0x00651830
FUN_00651830::~FUN_00651830()
{}
}  // namespace fnv_00651830

namespace fnv_00652900 {

// @fnv 0x00652900
// src: COMMUNITY 0x00652900
bool BSFaceGenManager_CompareFaceGenCoord(const FaceGenMatrix<float> (*apCoord1)[2], FaceGenMatrix<float> (*apCoord2)[2])
{
    int etype;
    int esymm;
    if (!apCoord1 && !apCoord2)
        return true;
    if (!apCoord1 || !apCoord2)
        return false;
    for (etype = 0; etype < 2; etype++)
    {
        for (esymm = 0; esymm < 2; esymm++)
        {
            if (apCoord1[etype][esymm].FUN_00657880(&apCoord2[etype][esymm]))
                return true;
        }
    }
    return false;
}
}  // namespace fnv_00652900

namespace fnv_00653460 {
extern "C" void* DAT_011d5b8c;

// @fnv 0x00653460
// src: COMMUNITY 0x00653460
void* __cdecl BSFaceGenBaseMorphExtraData_GetTag()
{
    return DAT_011d5b8c;
}
}  // namespace fnv_00653460

namespace fnv_00653620 {
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
char* __cdecl strrchr_0040ab30(char*, int);
int _sprintf_s(char*, unsigned int, const char*, ...);

// @fnv 0x00653620
unsigned int GetModelNifFilename(BSStringT<char>& aOutFilename, const char* apModel)
{
    char porigFilename[260];
    char ptemp[260];
    char* pextension = 0;
    if (!apModel)
        return 0;
    TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = strrchr_0040ab30(porigFilename, '.');
    if (!pextension)
        return 0;
    *pextension = 0;
    _sprintf_s(ptemp, 260, "%s.nif", porigFilename);
    aOutFilename.Set(ptemp, 0);
    return reinterpret_cast<unsigned int>(static_cast<const char*>(aOutFilename));
}
}  // namespace fnv_00653620

namespace fnv_00653880 {
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
char* __cdecl strrchr_0040ab30(char*, int);
struct FileNameHash
{
    unsigned int uiLow;
    unsigned int uiHigh;
    FileNameHash();
    static void __cdecl CreateDirectoryAndFileHashes(const char*, FileNameHash&, FileNameHash&);
};
struct BSFileEntry;
struct ArchiveManager
{
    static BSFileEntry* __cdecl FindFileEntry(ARCHIVE_TYPE_INDEX, FileNameHash&, FileNameHash&, const char*);
};

// @fnv 0x00653880
// src: XBOX_PDB 0x00653880
unsigned int BSFaceGenManager_GetAsNearestDetailDDSFile(BSStringT<char>& aOutFilename, int aeSex, unsigned char acAge, const char* apModel)
{
    char porigFilename[260];
    int iage;
    char cgender;
    char* pextension = 0;
    iage = acAge;
    cgender = 'M';
    if (!apModel || iage > 100 || aeSex >= 2)
        return 0;
    TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = strrchr_0040ab30(porigFilename, '.');
    if (!pextension)
        return 0;
    *pextension = 0;
    if (aeSex == 1)
        cgender = 'F';
    aOutFilename.PrintfString("Textures\\%s%c%d.ddx", porigFilename, cgender, iage);
    FileNameHash dirHash;
    FileNameHash fileHash;
    FileNameHash::CreateDirectoryAndFileHashes(static_cast<const char*>(aOutFilename), dirHash, fileHash);
    BSFileEntry* pFile = ArchiveManager::FindFileEntry(ARCHIVE_TYPE_INDEX_TEXTURES, dirHash, fileHash,
                                                       static_cast<const char*>(aOutFilename));
    if (pFile)
        return reinterpret_cast<unsigned int>(static_cast<const char*>(aOutFilename));
    iage = iage / 10 * 10;
    do
    {
        aOutFilename.PrintfString("Textures\\%s%c%d.dds", porigFilename, cgender, iage);
        pFile = ArchiveManager::FindFileEntry(ARCHIVE_TYPE_INDEX_TEXTURES, dirHash, fileHash,
                                              static_cast<const char*>(aOutFilename));
        if (pFile)
            return reinterpret_cast<unsigned int>(static_cast<const char*>(aOutFilename));
    } while ((iage -= 10) >= 0);
    aOutFilename.Set("", 0);
    return 0;
}
}  // namespace fnv_00653880

namespace fnv_00653c40 {
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
char* __cdecl strrchr_0040ab30(char*, int);
int _sprintf_s(char*, unsigned int, const char*, ...);

// @fnv 0x00653c40
unsigned int BuildModelFilename(BSStringT<char>& aOutFilename, const char* apModel)
{
    char porigFilename[260];
    char ptemp[260];
    char* pextension = 0;
    if (!apModel)
        return 0;
    TaskQueueInterface::CopyStringToBuffer(porigFilename, 260, apModel);
    pextension = strrchr_0040ab30(porigFilename, '_');
    if (!pextension)
        return (unsigned int)apModel;
    *pextension = 0;
    _sprintf_s(ptemp, 260, "%s.nif", porigFilename);
    aOutFilename.Set(ptemp, 0);
    return reinterpret_cast<unsigned int>(static_cast<const char*>(aOutFilename));
}
}  // namespace fnv_00653c40

void __cdecl _FNV_Warning(const char* apFormat, ...);

// @fnv 0x00aafb90
void __cdecl ReportAssertionViolation(const char* apSource, int aiLine)
{
    _FNV_Warning("DEFAULT: FR2 ASSERT violation in %s line %i. Code may crash.", apSource, aiLine);
}

namespace fnv_006536d0 {
int _sprintf_s(char*, unsigned int, const char*, ...);
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
struct Flt
{
    operator unsigned int() const;
};

char* __cdecl strrchr_0040ab30(char*, int);

// Strips the extension from path, builds a .tri path (with a suffix for index 0 or 1), stores it in str and returns its value.
// @fnv 0x006536d0
unsigned int __cdecl BuildTriPathAndSet(BSStringT<char>* str, const char* path, int index)
{
    char szBase[260];
    char szFull[260];
    char* pExt2 = 0;

    if (!path)
        return 0;
    TaskQueueInterface::CopyStringToBuffer(szBase, 260, path);
    pExt2 = strrchr_0040ab30(szBase, 46);
    if (!pExt2)
        return 0;
    *pExt2 = 0;
    switch (index)
    {
    case 0:
    case 1:
        _sprintf_s(szFull, 260, "%s%s.tri", szBase, DAT_0119b734[index]);
        break;
    default:
        _sprintf_s(szFull, 260, "%s.tri", szBase);
        break;
    }
    str->Set(szFull, 0);
    return (unsigned int)static_cast<const char*>(*str);
}
}  // namespace fnv_006536d0

namespace fnv_006521b0 {
struct _vec_60
{
    char data[0x60];
};
extern unsigned int __fastcall std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size(const _vec_60*);

// Indexes into the face gen manager's array at offset 0xb8 by a*0x30+b*0x18, calls FUN_00657a30 on that entry and returns the result minus one.
// @fnv 0x006521b0
// src: GUESS 0x006521b0 (confidence: medium)
unsigned int __cdecl BSFaceGenManager_GetFaceGenManagerVectorSize(int a, int b)
{
    return std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size(reinterpret_cast<const _vec_60*>(&BSFaceGenManager::GetFaceGenManager()->m_kCtls.ctl[a][b])) -
           1;
}
}  // namespace fnv_006521b0


struct FUN_007b3810Class
{
    Tile* m_tile;
    void RaceSexMenu_MenuOption_SetDisplay(const char* a1);
};

// If m_tile and a1 are non-null, calls m_tile->Set with id 0x1009, the string a1 and true.
// @fnv 0x007b3810
// src: COMMUNITY 0x007b3810
void FUN_007b3810Class::RaceSexMenu_MenuOption_SetDisplay(const char* a1)
{
    if (m_tile && a1)
        m_tile->Set(0x1009, a1, true);
}

namespace fnv_00651650 {
struct FUN_00651650 : FaceGenMatrix<float>
{
    ~FUN_00651650();
};

// @fnv 0x00651650
FUN_00651650::~FUN_00651650()
{}
}  // namespace fnv_00651650

struct FUN_00aac170_This
{
    int __thiscall FanGenCtlsGrpC_setAttributes(int, int, int, int);
};
// @fnv 0x006524e0
// src: COMMUNITY 0x006524e0
void __cdecl BSFaceGenManager_SetFaceCoordAttributes(int aiArg4, int aiArg2, int aiArg3)
{
    reinterpret_cast<FUN_00aac170_This*>(&BSFaceGenManager::GetFaceGenManager()->m_kModels)
        ->FanGenCtlsGrpC_setAttributes(0, aiArg2, aiArg3, aiArg4);
}

struct FUN_0065e000_class
{
    int FaceGenData_Iterator_Set_(int, int);
};
struct FUN_0065fd10_class
{
    int _p[3];
    int _f;
    FUN_0065e000_class* EvaluateValue_0065fd10(FUN_0065e000_class*);
};
// Calls FUN_0065da80 on a with this object's _f and this pointer, then returns a.
// @fnv 0x0065fd10
// src: GUESS 0x0065fd10 (confidence: low)
FUN_0065e000_class* FUN_0065fd10_class::EvaluateValue_0065fd10(FUN_0065e000_class* a)
{
    a->FaceGenData_Iterator_Set_(_f, (int)this);
    return a;
}

namespace fnv_0065fd40 {
struct FUN_0065e000_class
{
    int FaceGenData_Iterator_Set_(int, int);
};
struct FUN_0065fd40_class
{
    char pad[16];
    int f10;
    FUN_0065e000_class* ProcessAndReturnValue_0065fd40(FUN_0065e000_class*);
};
// Calls FUN_0065da80 on a with f10 and this, then returns a.
// @fnv 0x0065fd40
// src: GUESS 0x0065fd40 (confidence: low)
FUN_0065e000_class* FUN_0065fd40_class::ProcessAndReturnValue_0065fd40(FUN_0065e000_class* a)
{
    a->FaceGenData_Iterator_Set_(f10, (int)this);
    return a;
}
}  // namespace fnv_0065fd40

float __cdecl BSFaceGenManager_GetFaceCoordAttribute(int, int, int);
void __cdecl BSFaceGenManager_SetFaceCoordAttributes(int, int, int);

// Reads both fan attribute values for a coordinate and fan type, overrides the selected attribute with afValue, then applies the pair.
// @fnv 0x00652470
// src: COMMUNITY 0x00652470
void BSFaceGenManager_SetFaceCoordAttribute(int apCoord, int aeFanAttribute, int aeFanType, float afValue)
{
    int i;
    float values[2];
    for (i = 0; i < 2; i++)
    {
        if (i == aeFanAttribute)
            values[i] = afValue;
        else
            values[i] = BSFaceGenManager_GetFaceCoordAttribute(apCoord, i, aeFanType);
    }
    BSFaceGenManager_SetFaceCoordAttributes(apCoord, aeFanType, (int)values);
}

namespace fnv_00656db0 {

extern GO DAT_011f9510;

// @fnv 0x00656db0
// src: COMMUNITY 0x00656db0
unsigned int BSShader_GetDefNormalMap()
{
    return DAT_011f9510.operator unsigned int();
}
}  // namespace fnv_00656db0

void __cdecl FormHeapFreeAndLog_00401030(void*);
struct Target
{
    void FUN_0064fe10();
    Target* FUN_0064fde0(unsigned int flags);
};
// @fnv 0x0064fde0
Target* Target::FUN_0064fde0(unsigned int flags)
{
    FUN_0064fe10();
    if (flags & 1)
        FormHeapFreeAndLog_00401030(this);
    return this;
}

struct FaceGenModel
{
    void Touch();
};

template <class T> struct ModelPtr
{
    T* m_pObject;
    ModelPtr(T* p);
    ~ModelPtr();
    operator T*() const;
};

struct FaceGenCacheEntry
{
    int unk00;
    int unk04;
    ModelPtr<FaceGenModel> m_pRenderedNodeEntry;
    unsigned int uiTick;
};

struct FGModelKey
{
    const char* GetPrimaryName();
    const char* GetSecondaryName();
};

struct FaceGenCacheEntryMap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool GetAt(const char* apKey, ModelPtr<FaceGenCacheEntry>& arOut);
};

unsigned int BSStringLength(const char* apString);
unsigned int __cdecl gm_GetTickCount();
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();

struct FaceGenModelCacheX
{
    int unk00;
    FaceGenCacheEntryMap kMap;
    int unk14;
    int unk18;
    int unk1C;
    bool bChanged;
    void MoveToFront(FaceGenCacheEntry* apEntry);
    bool TouchCachedModel(FGModelKey* apKey);
};

// Looks up the entry for the key's primary or secondary name, refreshes its tick, moves it to the front, touches its model and marks the cache changed.
// @fnv 0x00650630
bool FaceGenModelCacheX::TouchCachedModel(FGModelKey* apKey)
{
    ModelPtr<FaceGenCacheEntry> spEntry(0);
    if (!apKey || !apKey->GetPrimaryName() || !BSStringLength(apKey->GetPrimaryName()))
        return false;
    bool bResultTmp = false;
    BSFaceGenManager_LockFaceGenAccess();
    if (kMap.GetAt(apKey->GetPrimaryName(), spEntry) ||
        (apKey->GetSecondaryName() && kMap.GetAt(apKey->GetSecondaryName(), spEntry)))
    {
        ((FaceGenCacheEntry*)spEntry)->uiTick = gm_GetTickCount();
        MoveToFront(spEntry);
        ((FaceGenModel*)((FaceGenCacheEntry*)spEntry)->m_pRenderedNodeEntry)->Touch();
        bChanged = true;
        bResultTmp = true;
    }
    BSFaceGenManager_UnlockFaceGenAccess();
    return bResultTmp;
}

bool BSFaceGenManager_TryLockFaceGenAccess();
void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();

struct FGCacheModel
{
    int GetRefCount();
    bool HasPendingData();
    void ReleaseTextureData();
};

struct FGCacheModelPtr
{
    FGCacheModel* m_pObject;
    operator FGCacheModel*() const;
    FGCacheModel* operator->() const;
};

struct FGCacheEntry
{
    int unk00;
    int unk04;
    FGCacheModelPtr m_pRenderedNodeEntry;
};

struct FGCacheEntryPtr
{
    FGCacheEntry* m_pObject;
    FGCacheEntryPtr(FGCacheEntry* apObject);
    ~FGCacheEntryPtr();
    operator FGCacheEntry*() const;
};

struct FGCacheMap
{
    void* GetFirstPos();
    void GetNext(void*& arPos, unsigned int& arKey, FGCacheEntryPtr& arVal);
    bool RemoveAt(unsigned int aKey);
};

struct FaceGenModelCache650
{
    int unk00;
    FGCacheMap kMap;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bool bHasData;
    void PurgeUnusedModels(bool abForce);
};

// @fnv 0x00650a30
void FaceGenModelCache650::PurgeUnusedModels(bool abForce)
{
    unsigned int uiKey4 = 0;
    FGCacheEntryPtr spEntry(0);
    bool bLocked = abForce;
    bool bStillHasData;
    void* pPos3;
    if (!abForce)
        bLocked = BSFaceGenManager_TryLockFaceGenAccess();
    else
        BSFaceGenManager_LockFaceGenAccess();
    if (bLocked)
    {
        bStillHasData = false;
        pPos3 = kMap.GetFirstPos();
        while (pPos3)
        {
            kMap.GetNext(pPos3, uiKey4, spEntry);
            if (((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry->GetRefCount() == 1)
            {
                kMap.RemoveAt(uiKey4);
            }
            else if ((FGCacheEntry*)spEntry && (FGCacheModel*)((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry)
            {
                if (!((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry->HasPendingData())
                    bStillHasData = true;
                ((FGCacheEntry*)spEntry)->m_pRenderedNodeEntry->ReleaseTextureData();
            }
        }
        if (!bStillHasData)
            bHasData = false;
        BSFaceGenManager_UnlockFaceGenAccess();
    }
}

struct FGModel650
{
    unsigned int IsUnusedA();
    unsigned int IsUnusedB();
    void ReleaseA();
    void ReleaseB();
};


struct FGEntry650
{
    void IncRefCount();
    void DecRefCount();
    int unk00;
    int unk04;
    NiPointer<FGModel650> m_pRenderedNodeEntry;
    unsigned int uiLastUsed;
};

struct FGMap650
{
    void* GetFirstPos();
    void GetNext(void*& pos, void*& key, NiPointer<FGEntry650>& val);
};

void BSFaceGenManager_LockFaceGenAccess();
void BSFaceGenManager_UnlockFaceGenAccess();
unsigned int __cdecl gm_GetTickCount();

struct FGCache650
{
    int unk00;
    FGMap650 kMap;
    void BSFaceGenModelMap_FreeLRUData(int aeType, FGEntry650* apExclude);
};

// Scans the map for an entry whose model reports unused for the given type, picks the one with the oldest uiLastUsed, releases it, and returns nothing.
// @fnv 0x00650cb0
// src: COMMUNITY 0x00650cb0
void FGCache650::BSFaceGenModelMap_FreeLRUData(int aeType, FGEntry650* apExclude)
{
    void* pKey = 0;
    void* pBestKey9 = 0;
    NiPointer<FGEntry650> _spEntry(0);
    NiPointer<FGEntry650> spBest2(0);
    unsigned int uiNow5 = gm_GetTickCount();
    BSFaceGenManager_LockFaceGenAccess();
    unsigned int uiUnused8;
    void* pPosVal = kMap.GetFirstPos();
    while (pPosVal)
    {
        kMap.GetNext(pPosVal, pKey, _spEntry);
        if (_spEntry == apExclude)
            continue;
        switch (aeType)
        {
        case 0:
            uiUnused8 = ((FGModel650*)((FGEntry650*)_spEntry)->m_pRenderedNodeEntry)->IsUnusedA();
            break;
        case 1:
            uiUnused8 = ((FGModel650*)((FGEntry650*)_spEntry)->m_pRenderedNodeEntry)->IsUnusedB();
            break;
        default:
            uiUnused8 = 0;
            break;
        }
        if (!uiUnused8)
            continue;
        if (!(FGEntry650*)spBest2)
        {
            spBest2 = _spEntry;
            pBestKey9 = pKey;
        }
        else if (uiNow5 - ((FGEntry650*)_spEntry)->uiLastUsed > uiNow5 - ((FGEntry650*)spBest2)->uiLastUsed)
        {
            spBest2 = _spEntry;
            pBestKey9 = pKey;
        }
    }
    if ((FGEntry650*)spBest2)
    {
        switch (aeType)
        {
        case 0:
            ((FGModel650*)((FGEntry650*)spBest2)->m_pRenderedNodeEntry)->ReleaseA();
            break;
        case 1:
            ((FGModel650*)((FGEntry650*)spBest2)->m_pRenderedNodeEntry)->ReleaseB();
            break;
        }
    }
    BSFaceGenManager_UnlockFaceGenAccess();
}

struct FUN_006515b0
{
    FaceGenMatrix<float> unk00[2];
    FaceGenMatrix<float> unk40;
    FaceGenMatrix<float> unk60[2];

    ~FUN_006515b0();
};

// Empty destructor for the structure; the member destructors run automatically.
// @fnv 0x006515b0
FUN_006515b0::~FUN_006515b0()
{}

struct FUN_00651810_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    ~FUN_00651810_Elem();
};

struct FUN_00651810_cls
{
    FUN_00651810_Elem m_aiIndexedValues[4];

    ~FUN_00651810_cls();
};

// @fnv 0x00651810
FUN_00651810_cls::~FUN_00651810_cls()
{}

// If DAT_011d59e8 is set, deletes it and then clears DAT_011d59e8.
// @fnv 0x00651ab0
// src: COMMUNITY 0x00651ab0
void __cdecl BSFaceGenManager_DestroySystem()
{
    if (DAT_011d59e8 != 0)
    {
        delete DAT_011d59e8;
        DAT_011d59e8 = 0;
    }
}

struct FG652_Obj90
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void* GetVal();
};
struct FG652_ED
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual struct FG652_Applier* GetApplier();
};
struct FG652_Child
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void* GetGeom();
};

struct FG652_Node
{
    unsigned int FUN_0043b480();
    FG652_Child* FUN_0043b4a0(unsigned int);
};
struct FG652_Applier
{
    void ApplyMorphs(FaceGenMatrix<float>*, void*, int);
};
void* __cdecl GetGeomExtraData(void*);
struct FG652_List
{
    struct FG652_Name* FUN_00726070();
};
struct FG652_Name
{
    void* TESRace_GetMeanFaceCoord();
};
struct FG652_NPC
{
    int unk000;
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
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    FG652_List list;
    void FUN_00603ad0(FaceGenMatrix<float>*);
    void* FUN_005f0cc0();
    void* FUN_00601800(int);
};
float __cdecl GetMorphCoordinateValue(FaceGenMatrix<float>*, int, int, int);
void __cdecl BSFaceGenManager_SetFaceCoordValue(FaceGenMatrix<float>*, int, int, int, float);
void __cdecl BSFaceGenManager_OffsetFaceGenCoord(void*, void*, void*, void*);
extern int DAT_011d59f0;
extern bool DAT_011d59e1;

struct FG652_Actor
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6a();
    virtual FG652_Node* GetNode3D(int);
    virtual FG652_Node* GetNode1st(int);
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual FG652_Obj90* GetObj90();
    FG652_NPC* BGSSaveFormBuffer_GetForm();
};

// @fnv 0x00652510
// src: COMMUNITY 0x00652510
void BSFaceGenManager_CycleFaceGenCoordValue(FG652_Actor* apActor)
{
    FG652_NPC* pNPC4 = apActor->BGSSaveFormBuffer_GetForm();
    FG652_Obj90* p9 = apActor->GetObj90();
    void* pVal5 = p9 ? p9->GetVal() : 0;
    FaceGenMatrix<float> kA[4];
    FaceGenMatrix<float> kB9[4];
    FaceGenMatrix<float> kC3[4];
    pNPC4->FUN_00603ad0(kA);
    pNPC4->FUN_00603ad0(kB9);
    float fAge8 = GetMorphCoordinateValue(kA, 0, 0, DAT_011d59f0);
    if (DAT_011d59e1)
    {
        fAge8 += (double)0.1f;
        if (fAge8 >= 10.0)
            DAT_011d59e1 = false;
    }
    else
    {
        fAge8 -= (double)0.1f;
        if (fAge8 <= -10.0)
            DAT_011d59e1 = true;
    }
    BSFaceGenManager_SetFaceCoordValue(kB9, 0, 0, DAT_011d59f0, fAge8);
    BSFaceGenManager_OffsetFaceGenCoord(kA, kB9, kC3, 0);
    FG652_Node* pNodeVal = apActor->GetNode3D(0);
    for (int i4 = 0; i4 < 2; i4++)
    {
        unsigned int uiCount_2 = pNodeVal->FUN_0043b480();
        for (unsigned int jX = 0; jX < uiCount_2; jX++)
        {
            FG652_Child* pChild4 = pNodeVal->FUN_0043b4a0(jX);
            void* aPGeom = pChild4 ? pChild4->GetGeom() : 0;
            if (!aPGeom)
                continue;
            FG652_ED* pED4 = (FG652_ED*)GetGeomExtraData(aPGeom);
            FG652_Applier* pApp3 = pED4 ? pED4->GetApplier() : 0;
            if (!pApp3)
                continue;
            pApp3->ApplyMorphs(kC3, aPGeom, 0);
        }
        pNodeVal = apActor->GetNode1st(0);
    }
    BSFaceGenManager_OffsetFaceGenCoord(pNPC4->list.FUN_00726070()->TESRace_GetMeanFaceCoord(), pNPC4->FUN_005f0cc0(), kB9, pNPC4->FUN_00601800(0));
}

struct MatrixProxy
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int NiAVObject_GetParent();
    unsigned int FUN_00441110();
    void SetDimensions(unsigned int, unsigned int);
    void FUN_006581e0(MatrixProxy*);
    void std_vector_float_std_allocator_float_clear();
    float* GetElementPointerChecked(unsigned int);
    void PushBack(const float&);
};
// @fnv 0x00652e00
// src: COMMUNITY 0x00652e00
void BSFaceGenManager_OffsetFaceGenCoord(MatrixProxy (*a)[2], MatrixProxy (*b)[2], MatrixProxy (*out)[2], bool copy)
{
    if (!a || !b || !out)
        return;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            unsigned int cols = a[i][j].NiAVObject_GetParent();
            unsigned int rows = a[i][j].FUN_00441110();
            if (cols && rows)
            {
                out[i][j].SetDimensions(cols, rows);
                if (i == 1 && copy)
                {
                    out[i][j].FUN_006581e0(&a[i][j]);
                }
                else
                {
                    unsigned int count = cols * rows;
                    out[i][j].std_vector_float_std_allocator_float_clear();
                    for (unsigned int k = 0; k < count; ++k)
                    {
                        float bv = *a[i][j].GetElementPointerChecked(k);
                        float av = *b[i][j].GetElementPointerChecked(k);
                        out[i][j].PushBack(av - bv);
                    }
                }
            }
            else
            {
                out[i][j].SetDimensions(0, 0);
            }
        }
    }
}

namespace fnv_00653120 {
struct NiNode;
// GetGeomExtraData (0x00607310, tesnpc.cpp) returns named NiExtraData, not a scene object.
struct FaceModelExtraDataDispatch
{
    void** vtable;
};
extern "C" FaceModelExtraDataDispatch* __cdecl GetGeomExtraData(void*);
extern "C" NiNode* __cdecl GetHandleObject(void*);
typedef FaceModelExtraDataDispatch*(__thiscall* FUN_00653120_vfunc_type)(FaceModelExtraDataDispatch*);
typedef NiNode*(__thiscall* FUN_00653180_type)(void*);
// Resolves apGeom to an object, calls its vtable slot at 0x94, and returns the resulting node or null.
// @fnv 0x00653120
NiNode* __cdecl GetNodeFromGeometry(void* apGeom)
{
    FaceModelExtraDataDispatch* pNode = GetGeomExtraData(apGeom);
    NiNode* pObject;
    if (pNode != 0 && ((FUN_00653120_vfunc_type)pNode->vtable[0x94 / 4])(pNode) != 0)
    {
        pObject = ((FUN_00653180_type)GetHandleObject)(((FUN_00653120_vfunc_type)pNode->vtable[0x94 / 4])(pNode));
    }
    else
    {
        pObject = 0;
    }
    return pObject;
}
}  // namespace fnv_00653120

struct C6533F0Point3
{
    float x;
    float y;
    float z;
};

class C6533F0Holder
{
  public:
    C6533F0Point3* m_pkPoint;

    void SetPoint(const C6533F0Point3& kPoint);
};

// Copies the given point into the object pointed to by m_pkPoint.
// @fnv 0x006533f0
void C6533F0Holder::SetPoint(const C6533F0Point3& akPoint)
{
    C6533F0Point3* pkPoint = m_pkPoint;
    C6533F0Point3* pkValue = pkPoint;
    *pkValue = akPoint;
}

class B6579D0Base
{
  public:
    int unk00;

    ~B6579D0Base();
};

class FUN_006579d0 : public B6579D0Base
{
  public:
    void Clear();

    ~FUN_006579d0();
};

// @fnv 0x006579d0
FUN_006579d0::~FUN_006579d0()
{
    Clear();
}

void __cdecl ReportAssertionViolation(const char* apSource, int aiLine);

struct MatIter
{
    float* p0;
    void* p1;
    MatIter(const MatIter&);
    MatIter operator++(int);
    bool operator!=(const MatIter&) const;
    const float& operator*() const;
};

struct MatView
{
    float* p0;
    void* p1;
    MatView(const MatView&);
    MatView operator++(int);
    float& operator*();
};

struct FgMatrixVT
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
    FgMatrixVT(unsigned int r, unsigned int c);
    FgMatrixVT(const FgMatrixVT&);
    ~FgMatrixVT();
    MatView View();
    MatIter Begin() const;
    MatIter End() const;
    FgMatrixVT AddMatrixElements(const FgMatrixVT& other) const;
};

// Asserts matching dimensions, then returns a new matrix whose elements are the element-wise sum of this matrix and other.
// @fnv 0x00658500
// src: GUESS 0x00658500 (confidence: medium)
FgMatrixVT FgMatrixVT::AddMatrixElements(const FgMatrixVT& other) const
{
    (m_uiRowCount == other.m_uiRowCount && m_uiColumnCount == other.m_uiColumnCount)
        ? (void)0
        : ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x16d);
    FgMatrixVT result(m_uiRowCount, m_uiColumnCount);
    MatView out4 = result.View();
    MatIter a2 = Begin();
    MatIter b = other.Begin();
    for (; a2 != End(); a2++, b++, out4++)
        *out4 = *a2 + *b;
    return result;
}

// Reconstructed function FUN_00659100
// Copies a 2-dword pair out of the object, refreshes the object through a
// member helper and stores the saved pair into the caller supplied buffer.

struct FG_00659100_pair
{
    int m_uiX;
    int m_uiY;
};

struct FG_00659100_cls
{
    FG_00659100_pair m_pair;
    void DoNothing();
    FG_00659100_pair* ProcessAndReturnValue_00659100(FG_00659100_pair* pOut, int iUnused);
};

// Copies m_pair to a local, calls FUN_00659190, writes the saved pair to pOut and returns pOut.
// @fnv 0x00659100
// src: GUESS 0x00659100 (confidence: low)
FG_00659100_pair* FG_00659100_cls::ProcessAndReturnValue_00659100(FG_00659100_pair* pOutPair, int iUnused)
{
    FG_00659100_pair tmp = this->m_pair;

    this->DoNothing();

    *pOutPair = tmp;

    return pOutPair;
}

// src: GUESS 0x00659190 (confidence: high)
void FG_00659100_cls::DoNothing()
{}

struct SegThing
{
    int Value();
    int m_00;
};

struct SegItem
{
    int pad[4];
    SegThing t;
};

struct SegRange
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    unsigned int GetCount();
    SegItem* GetItem(unsigned int j);
};

struct SegElem
{
    int m_00;
    SegRange sub;
};

struct SegHolder
{
    int pad[2];
    SegElem* m_08;
};

struct FUN_0065c490_cls
{
    int pad[3];
    SegHolder* m_0c;
    unsigned int BSFaceGenModel_GetEGTDataSize();
};

// Sums a base 0x34 plus per-range counts times 0x58 and per-item values times 3 across two ranges, returning the total.
// @fnv 0x0065c490
// src: COMMUNITY 0x0065c490
unsigned int FUN_0065c490_cls::BSFaceGenModel_GetEGTDataSize()
{
    unsigned int i;
    unsigned int total = 0;
    if (m_0c != 0 && m_0c->m_08 != 0)
    {
        total = 0x34;
        for (i = 0; i < 2; i++)
        {
            total += (*(SegRange*)((char*)(m_0c->m_08) + 4 + i * 0x18)).GetCount() * 0x58;
            for (unsigned int j = 0; j < (*(SegRange*)((char*)(m_0c->m_08) + 4 + i * 0x18)).GetCount(); j++)
            {
                total += (*(SegRange*)((char*)(m_0c->m_08) + 4 + i * 0x18)).GetItem(j)->t.Value() * 3;
            }
        }
    }
    return total;
}

void __stdcall FUN_0065ee50_Helper(void* p, unsigned int size, int count, void (*dtor)());

struct FUN_006516a0_class
{
    void ForwardCall_006516a0();
};

// @fnv 0x006516a0
// src: GUESS 0x006516a0 (confidence: low)
void FUN_006516a0_class::ForwardCall_006516a0()
{
    FUN_0065ee50_Helper(this, 0x20, 2, FUN_dtor);
}

struct FaceGenVectorMember
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ~FaceGenVectorMember();
};

struct FaceGenFinalMember
{
    unsigned int unk00;
    ~FaceGenFinalMember();
};

struct FUN_00651760
{
    unsigned int unk00;
    unsigned int unk04;
    FaceGenMatrix<float> m_kCoordinateElements[4];
    FaceGenVectorMember m_secondary;
    FaceGenFinalMember m_final;
    ~FUN_00651760();
};

// Destructor for a structure holding four FaceGenMatrix<float> entries, a FaceGenVectorMember and a FaceGenFinalMember.
// @fnv 0x00651760
FUN_00651760::~FUN_00651760()
{}

struct FanCtl652
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
    FaceGenMatrix<float> GetMatrix() const;
};
struct FanVec652
{
    int unk00;
    int unk04;
    int unk08;
    FanCtl652* first;
    FanCtl652* last;
    FanCtl652* end;
    unsigned int size() const;
    FanCtl652* at(unsigned int i);
};
// @fnv 0x00652320
// src: COMMUNITY 0x00652320
void __cdecl BSFaceGenManager_SetFaceCoordValue(FaceGenMatrix<float>* apMat, int aeAttr, int aeType, int aiIndex, float afValue)
{
    if (apMat && (unsigned int)aiIndex <
                     reinterpret_cast<FanVec652(*)[2]>(BSFaceGenManager::GetFaceGenManager()->m_kCtls.ctl)[aeAttr][aeType].size())
    {
        float fOrig = GetMorphCoordinateValue(apMat, aeAttr, aeType, aiIndex);
        float fChange = afValue - fOrig;
        ((FaceGenMatrix<float>(*)[2])apMat)[aeAttr][aeType].Assign(
            reinterpret_cast<FanVec652(*)[2]>(BSFaceGenManager::GetFaceGenManager()->m_kCtls.ctl)[aeAttr][aeType]
                .at(aiIndex)->GetMatrix().Scaled(fChange));
    }
}

struct HashB8
{
    int a;
    int b;
};
void __cdecl HashPathComponents(const char* apStr, HPList* apHashA, HPList* apHashB);
int __cdecl FindFileEntryInArchives(int aiZero, HPList* apHashA, HPList* apHashB, const char* apStr);
char* __cdecl strchr(char* apStr, int aiChar);

// @fnv 0x00653a10
// src: COMMUNITY 0x00653a10
const char* __cdecl BSFaceGenManager_GetAsNIFFileLowLOD(BSStringT<char>* aStr, const char* apModel)
{
    BSStringT<char> iter;
    char* dot = 0;
    char* us = 0;
    char buf5[0x104];
    char buf2[0x104];
    HPList hashA;
    HashB8 hashB;
    int r6;

    if (apModel == 0)
        return 0;
    CopyStringChecked(buf5, 0x104, apModel);
    us = strchr(buf5, '_');
    if (us != 0)
    {
        aStr->Set(buf5, 0);
        return apModel;
    }
    dot = strrchr_0040ab30(buf5, '.');
    if (dot == 0)
        return apModel;
    *dot = 0;
    sprintf_s(buf2, 0x104, "%s_50.NIF", buf5);
    aStr->Set(buf2, 0);
    iter.PrintfString("Meshes\\%s", (const char*)*aStr);
    _ref_006815c0(&hashA);
    _ref_006815c0((HPList*)&hashB);
    HashPathComponents(static_cast<const char*>(iter), &hashA, (HPList*)&hashB);
    r6 = FindFileEntryInArchives(0, &hashA, (HPList*)&hashB, static_cast<const char*>(iter));
    if (r6 == 0)
        return 0;
    return *aStr;
}

namespace fnv_00654720 {


struct FileNameHash
{
    unsigned int low, high;
    FileNameHash();
};
struct FG547Property
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void Apply(int, int, void*);
    int FUN_00441110();
    void FUN_00b68d30();
    void BSShaderProperty_SetFlag(int, int);
    void AssignFixedString(const NiFixedString&);
};
struct FG547Node
{
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void Attach(FG547Node*, int);
    void AssignFixedString(const NiFixedString&);
    FG547Property* FUN_00a59d30(unsigned int);
    void NiAVObject_RemoveProperty(int);
    void NiAVObject_AttachProperty(void*);
    void* NiGeometry_GetSkinInstance();
    void NiGeometry_SetSkinInstance(void*);
    void NiAVObject_SetTranslate(const NiPoint3&);
    void SetRotate_0043fa80(const NiMatrix3&);
};
struct FG547Model
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual const char* Path();
    int FUN_0048cee0();
    void FUN_0048afe0(FG547Node*);
};
struct FG547Part
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
    FG547Model model;
};
struct FG547List
{
    FG547Part* data;
    FG547List* next;
    FG547Part** FUN_006815c0();
    FG547List* FUN_00726070();
};
struct FG547Array
{
    int unk00, unk04, unk08, unk0c;
    unsigned int GetShortAtOffsetA();
    FG547Model** FUN_00877a30(unsigned int);
};
struct FG547Data
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
    FG547Array models;
    FG547Array textures;
    FG547Array names;
    int unkc4, unkc8, unkcc, unkd0;
    bool texturing;
    bool player;
    short unkd6;
    void* leftEye;
    void* rightEye;
    int lod;
    FG547List accessories;
};

struct FG547PointerOps
{
    void FUN_0066b0d0(int);
};
struct FG547Setting
{
    bool* FUN_00408d60();
};
extern FG547Setting DAT_011d5adc;
struct FG547TextureLoader
{
    void FUN_004568c0(const char*, GO&, bool, bool);
};
extern FG547TextureLoader* DAT_011dea10;

struct FUN_00a75650 : NiExtraData
{
    // Preserve the complete extra-data allocation represented by the original local base.
    char faceGenExtraDataStorage[0x4c - sizeof(NiExtraData)];
    FUN_00a75650();
    static void operator delete(void*, unsigned int);
};
// Constructor maps to the game's property constructor.
struct FG547NewProperty
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
    void Lighting30shaderproperty_StoreAndAddReference_00a75650();
};
extern const char DAT_01065720[], DAT_01019710[], DAT_010657f8[], DAT_010657e4[], DAT_01200464[];
extern const NiPoint3 DAT_011f426c;
void HashPathComponents(const char*, FileNameHash*, FileNameHash*);
int FindFileEntryInArchives(int, FileNameHash*, FileNameHash*, const char*);
const char* BuildEgmFilename(BSStringT<char>*, const char*, int);
const char* BuildTriPathAndSet(BSStringT<char>*, const char*, int);
BSFaceGenModel* GetOrCreateFaceGenModel(const char*, const char*, const char*, const char*, int, int, int);
unsigned int NiMaterialProperty_GetType();
NiFixedString* NiFixedString_GetDAT_011c6210_006041c0();
FG547Property* NiObject_DynamicCast(const char*, FG547Property*);
bool FUN_00605d20();
void MatchGeometryVertices(FG547Node*, FG547Node*, float, int, int);
void BuildHairFaceGenNodes(FG547Node**, FG547Node**, FG547Data*, bool);
void CreateEyeGeometry(FG547Node**, FG547Node**, FG547Data*, bool);

// @fnv 0x00654720
bool __cdecl BuildCharacterParts(FG547Node** root, FG547Node** alternate, FG547Data* data, bool firstPerson)
{
    AutoMemContext textureObject((MEM_CONTEXT)0x37, true, DAT_01065720, 0xa48);
    BSFaceGenModel* unusedPath = 0;
    GO context(0);
    GO accessory(0);
    FG547Node* cached = 0;
    FG547Node* fallbackPath = 0;
    NiMatrix3 hair;
    BSStringT<char> model;
    BSStringT<char> texture;
    BSStringT<char> primary;
    BSStringT<char> modelPath;
    BSStringT<char> rotation;
    BSStringT<char> meshPath;
    hair.MakeYRotation(-1.5707963705062866f);
    for (unsigned int part = 0; part < 8; ++part)
    {
        if (!data->models.GetShortAtOffsetA() || !*data->models.FUN_00877a30(part) ||
            !(*data->models.FUN_00877a30(part))->FUN_0048cee0())
            continue;
        if (!data->textures.GetShortAtOffsetA() || !*data->textures.FUN_00877a30(part) ||
            !(*data->textures.FUN_00877a30(part))->FUN_0048cee0())
            continue;
        model.PrintfString(DAT_01019710, (*data->models.FUN_00877a30(part))->Path());
        if (data->lod == 0 && part == 0)
        {
            BSFaceGenManager_GetAsNIFFileLowLOD(&meshPath, static_cast<const char*>(model));
            int fallback = 0;
            if (static_cast<const char*>(meshPath))
            {
                FileNameHash hash1;
                FileNameHash hash2;
                HashPathComponents(static_cast<const char*>(meshPath), &hash1, &hash2);
                fallback = FindFileEntryInArchives(0, &hash1, &hash2, static_cast<const char*>(meshPath));
            }
            if (fallback)
                BSFaceGenManager_GetAsNIFFileLowLOD(&model, static_cast<const char*>(model));
        }
        const char* auxiliary = 0;
        switch (part)
        {
        case 0:
            if (data->player || *DAT_011d5adc.FUN_00408d60())
                auxiliary = GetModelEgtFilename(&modelPath, static_cast<const char*>(model));
            unusedPath = GetOrCreateFaceGenModel(
                BuildEgmFilename(&texture, static_cast<const char*>(model), -1),
                static_cast<const char*>(model),
                BuildTriPathAndSet(&primary, static_cast<const char*>(model), -1), auxiliary, 1, -1, 0);
            break;
        case 1:
            unusedPath = GetOrCreateFaceGenModel(
                BuildEgmFilename(&texture, static_cast<const char*>(model), -1),
                static_cast<const char*>(model),
                BuildTriPathAndSet(&primary, static_cast<const char*>(model), -1),
                GetModelEgtFilename(&modelPath, static_cast<const char*>(model)), 1, -1, 0);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            unusedPath = GetOrCreateFaceGenModel(
                BuildEgmFilename(&texture, static_cast<const char*>(model), -1),
                static_cast<const char*>(model),
                BuildTriPathAndSet(&primary, static_cast<const char*>(model), -1), 0, 1, -1, 0);
            break;
        }
        if (!unusedPath)
            continue;
        if (!unusedPath->ApplyFaceGenMorphs(reinterpret_cast<::FaceGenData*>(data), reinterpret_cast<::NiPointer<::NiTriBasedGeom>&>(accessory)) || !(FG547Node*)(FGEntry*)accessory)
            continue;
        ((FG547Node*)(FGEntry*)accessory)
            ->AssignFixedString(NiFixedString((const char*)*data->names.FUN_00877a30(part)));
        if (part == 0)
            cached = (FG547Node*)(FGEntry*)accessory;
        if (part == 1)
            fallbackPath = (FG547Node*)(FGEntry*)accessory;
        model.PrintfString(DAT_010657f8, ((FNStub*)*data->textures.FUN_00877a30(part))->GetFullName());
        DAT_011dea10->FUN_004568c0(static_cast<const char*>(model), context, false, false);
        if ((FGEntry*)context)
        {
            FG547Property* shader = ((FG547Node*)(FGEntry*)accessory)->FUN_00a59d30(3);
            FG547Property* base =
                (!shader ? false : shader->FUN_00441110() >= 8 && shader->FUN_00441110() <= 12) ? shader : 0;
            if (base)
                base->Apply(0, 0, (FGEntry*)context);
        }
        if (part == 4 || part == 3)
        {
            if (((FG547Node*)(FGEntry*)accessory)->FUN_00a59d30(0))
                ((FG547Node*)(FGEntry*)accessory)->NiAVObject_RemoveProperty(0);
            ((FG547Node*)(FGEntry*)accessory)->NiAVObject_AttachProperty((void*)BSFaceGenManager_GetHairTeethAlphaProperty());
        }
        if (part == 0 || part == 1)
        {
            FG547Property* shader = ((FG547Node*)(FGEntry*)accessory)->FUN_00a59d30(NiMaterialProperty_GetType());
            FG547Property* base = shader;
            if (base)
                base->AssignFixedString(*NiFixedString_GetDAT_011c6210_006041c0());
            else
            {
                base = (FG547Property*)new FUN_00a75650;
                base->AssignFixedString(*NiFixedString_GetDAT_011c6210_006041c0());
                ((FG547Node*)(FGEntry*)accessory)->NiAVObject_AttachProperty(base);
            }
        }
        if (((FG547Node*)(FGEntry*)accessory)->NiGeometry_GetSkinInstance())
        {
            if (firstPerson)
            {
                ((FG547Node*)(FGEntry*)accessory)->NiGeometry_SetSkinInstance(0);
                ((FG547Node*)(FGEntry*)accessory)->NiAVObject_SetTranslate(DAT_011f426c);
                ((FG547Node*)(FGEntry*)accessory)->SetRotate_0043fa80(hair);
                (*root)->Attach((FG547Node*)(FGEntry*)accessory, 1);
                FG547Property* shader = ((FG547Node*)(FGEntry*)accessory)->FUN_00a59d30(3);
                FG547Property* base = NiObject_DynamicCast(DAT_01200464, shader);
                if (base)
                    base->BSShaderProperty_SetFlag(1, 0);
            }
            else
                (*alternate)->Attach((FG547Node*)(FGEntry*)accessory, 1);
        }
        else
        {
            ((FG547Node*)(FGEntry*)accessory)->SetRotate_0043fa80(hair);
            (*root)->Attach((FG547Node*)(FGEntry*)accessory, 1);
        }
        FG547Property* base = ((FG547Node*)(FGEntry*)accessory)->FUN_00a59d30(3);
        FG547Property* checked = base;
        FG547Property* shader =
            (!checked ? false : checked->FUN_00441110() >= 8 && checked->FUN_00441110() <= 12) ? checked : 0;
        if (shader)
            shader->FUN_00b68d30();
        unusedPath = 0;
        ((FG547PointerOps*)&context)->FUN_0066b0d0(0);
        ((FG547PointerOps*)&accessory)->FUN_0066b0d0(0);
    }
    if (FUN_00605d20() && cached && fallbackPath)
        MatchGeometryVertices(cached, fallbackPath, 0.10000000149f, 0, 0);
    if (data->unk80)
        BuildHairFaceGenNodes(root, alternate, data, firstPerson);
    if (data->leftEye && data->rightEye)
        CreateEyeGeometry(root, alternate, data, firstPerson);
    FG547List* node = &data->accessories;
    while (node && *node->FUN_006815c0())
    {
        model.PrintfString(DAT_01019710, (*node->FUN_006815c0())->model.Path());
        unusedPath = GetOrCreateFaceGenModel(BuildEgmFilename(&texture, static_cast<const char*>(model), -1),
                                             static_cast<const char*>(model),
                                             BuildTriPathAndSet(&primary, static_cast<const char*>(model), -1),
                                             0, 1, -1, 1);
        if (unusedPath && unusedPath->ApplyFaceGenMorphs(reinterpret_cast<::FaceGenData*>(data), reinterpret_cast<::NiPointer<::NiTriBasedGeom>&>(accessory)) && (FG547Node*)(FGEntry*)accessory)
        {
            ((FG547Node*)(FGEntry*)accessory)->SetRotate_0043fa80(hair);
            (*root)->Attach((FG547Node*)(FGEntry*)accessory, 1);
            (*node->FUN_006815c0())->model.FUN_0048afe0((FG547Node*)(FGEntry*)accessory);
            ((FG547Node*)(FGEntry*)accessory)->AssignFixedString(NiFixedString(DAT_010657e4));
        }
        node = node->FUN_00726070();
    }
    return true;
}
}  // namespace fnv_00654720

float __cdecl NiSqrt_004579e0(float);


extern const NiPoint3 pathingrequestZero;
struct PointIterator
{
    const NiPoint3* points;
    unsigned int stride;
    unsigned int position;
    void NiGeometryDataIteratorNiPoint3_Get(unsigned int, NiPoint3&);
    void CopyV3(NiPoint3*);
    void AddToA();
};
struct BoundingSphere
{
    void FUN_0098ddd0(const NiPoint3&);
    void FUN_0063f790(float);
};
// @fnv 0x00656dc0
void __cdecl ComputeBoundingSphere(BoundingSphere* sphere, PointIterator* points, int count)
{
    if (count <= 0)
    {
        sphere->FUN_0098ddd0(pathingrequestZero);
        sphere->FUN_0063f790(0.0f);
        return;
    }
    // Local spellings and scopes preserve the original MSVC9 stack layout.
    PointIterator second;    // Iterator for the radius pass.
    PointIterator i;         // Iterator for the coordinate-extrema pass.
    int center;              // NiPoint3 index for both passes.
    NiPoint3 point;          // Bounding-sphere center.
    float first = 0.0f;      // Greatest squared distance from the center.
    NiPoint3 maximum;        // Minimum coordinate on each axis.
    NiPoint3 radiusSquared;  // Current point.
    points->NiGeometryDataIteratorNiPoint3_Get(0, maximum);
    {
        V3 minimum = *reinterpret_cast<const V3*>(&maximum);  // Upper corner; maximum is the lower corner.
        i = *points;
        for (center = 1; center < count; ++center, i.AddToA())
        {
            i.CopyV3(&radiusSquared);
            if (maximum.x > radiusSquared.x)
                maximum.x = radiusSquared.x;
            if (maximum.y > radiusSquared.y)
                maximum.y = radiusSquared.y;
            if (maximum.z > radiusSquared.z)
                maximum.z = radiusSquared.z;
            if (reinterpret_cast<NiPoint3&>(minimum).x < radiusSquared.x)
                reinterpret_cast<NiPoint3&>(minimum).x = radiusSquared.x;
            if (reinterpret_cast<NiPoint3&>(minimum).y < radiusSquared.y)
                reinterpret_cast<NiPoint3&>(minimum).y = radiusSquared.y;
            if (reinterpret_cast<NiPoint3&>(minimum).z < radiusSquared.z)
                reinterpret_cast<NiPoint3&>(minimum).z = radiusSquared.z;
        }
        *reinterpret_cast<V3*>(&point) = *reinterpret_cast<const V3*>(&(0.5f * (maximum + reinterpret_cast<NiPoint3&>(minimum))));
        second = *points;
        for (center = 0; center < count; ++center, second.AddToA())
        {
            second.CopyV3(&radiusSquared);
            float distanceSquared;
            {
                NiPoint3 delta = radiusSquared - point;
                distanceSquared = delta.Dot(delta);
            }
            if (distanceSquared > first)
                first = distanceSquared;
        }
        sphere->FUN_0098ddd0(point);
        sphere->FUN_0063f790(NiSqrt_004579e0(first));
    }
}

struct TemporaryAllocator
{
    int value;
    TemporaryAllocator();
    TemporaryAllocator(const TemporaryAllocator&);
};
struct CoordinateArrayBase
{
    CoordinateArrayBase(TemporaryAllocator allocator);
    ~CoordinateArrayBase();
    void ReserveEntries(int value);
};
struct FUN_00657960 : CoordinateArrayBase
{
    FUN_00657960();
};
// Constructs the object with a default TemporaryAllocator and initializes it by calling ReserveEntries with 0.
// @fnv 0x00657960
FUN_00657960::FUN_00657960() : CoordinateArrayBase(TemporaryAllocator())
{
    ReserveEntries(0);
}

struct MxConstIter
{
    float* m_p0;
    void* m_p1;
    MxConstIter ProcessAndReturnValue_00659100(int);
    bool operator!=(const MxConstIter& o) const;
    const float& ProcessEntries_0064dda0() const;
};
struct MxIter
{
    float* m_p0;
    void* m_p1;
    MxIter operator++(int);
    bool operator!=(const MxIter& o) const;
    float& operator*() const;
};

void __cdecl ReportAssertionViolation(const char* msg, int line);


// @fnv 0x006586c0
template <>
FaceGenMatrix<float>* FaceGenMatrix<float>::AddMatrix(FaceGenMatrix<float>* other)
{
    if (m_uiRowCount == other->m_uiRowCount && m_uiColumnCount == other->m_uiColumnCount)
    {
    }
    else
    {
        ReportAssertionViolation("d:\\_fallout3\\platforms\\common\\code\\sdk\\facegen\\matrixVT.hpp", 0x24f);
    }
    MxIter a = begin();
    MxConstIter b5 = other->EvaluateValue_0065fd10();
    for (; a != end() && b5 != other->ProcessAndReturnValue_0065fd40(); a++, b5.ProcessAndReturnValue_00659100(0))
    {
        *a += double(b5.ProcessEntries_0064dda0());
    }
    return this;
}

struct S_0065da80_bounds
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct S_0044ac20_class
{
    void FOVATSEffectManager_SetEffectMode(int value);
};

void __fastcall FaceGenData_Iterator_ClearsData(void* pThis);
unsigned int FUN_00ec7c56();

// @fnv 0x0065da80
// src: COMMUNITY 0x0065da80
int FUN_0065e000_class::FaceGenData_Iterator_Set_(int value, int pBounds)
{
    FaceGenData_Iterator_ClearsData(this);

    if (pBounds == 0 || reinterpret_cast<S_0065da80_bounds*>(pBounds)->unk0c > static_cast<unsigned int>(value) ||
        static_cast<unsigned int>(value) >
            static_cast<unsigned int>(reinterpret_cast<S_0065da80_bounds*>(pBounds)->unk10))
    {
        FUN_00ec7c56();
    }
    do
    {
    } while (0);

    reinterpret_cast<S_0044ac20_class*>(this)->FOVATSEffectManager_SetEffectMode(pBounds);

    reinterpret_cast<int*>(this)[1] = value;

    return reinterpret_cast<int>(this);
}


void BSFaceGenManager_CopyFaceGenCoord(FaceGenMatrix<float> a1[2][2], FaceGenMatrix<float> a2[2][2], int a3, int a4);
float sqrt_004019b0(float);

// For each of the 2x2 FaceGenMatrix<float> slots, combines a1 and a2 into a3 (or copies one source), optionally scaling the result when a5 is exceeded.
// @fnv 0x00652af0
// src: XBOX_PDB 0x00652af0
void BSFaceGenManager_MergeFaceGenCoord(FaceGenMatrix<float> a1[2][2], FaceGenMatrix<float> a2[2][2], FaceGenMatrix<float> a3[2][2], bool a4, float a5)
{
    if (!a3 || (!a1 && !a2))
        return;

    if (!a1)
    {
        BSFaceGenManager_CopyFaceGenCoord(a2, a3, 0, 0);
        return;
    }
    else if (!a2)
    {
        BSFaceGenManager_CopyFaceGenCoord(a1, a3, 0, 0);
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            unsigned int var_c = a1[i][j].NiAVObject_GetParent();
            unsigned int var_10 = a1[i][j].FUN_00441110();
            if (var_c != 0 && var_10 != 0)
            {
                a3[i][j].SetDimensions(var_c, var_10);
                if (i == 1 && a4)
                {
                    a3[i][j].FUN_006581e0(&a1[i][j]);
                    if (a5 > 0.0)
                    {
                        float var_14 = sqrt_004019b0(a3[i][j].FUN_006588a0() / (float)var_c);
                        if (var_14 > a5)
                        {
                            a3[i][j].ScaleAll(a5 / var_14);
                        }
                    }
                }
                else
                {
                    unsigned int var_18 = var_c * var_10;
                    a3[i][j].std_vector_float_std_allocator_float_clear();
                    for (unsigned int k = 0; k < var_18; ++k)
                    {
                        float sum = *a1[i][j].GetElementPointerChecked(k);
                        float var_28 = *a2[i][j].GetElementPointerChecked(k);
                        a3[i][j].PushBack(sum + var_28);
                    }
                    if (a5 > 0.0)
                    {
                        float f2 = sqrt_004019b0(a3[i][j].FUN_006588a0() / (float)var_c);
                        if (f2 > a5)
                        {
                            a3[i][j].ScaleAll(a5 / f2);
                        }
                    }
                }
            }
            else
            {
                a3[i][j].SetDimensions(0, 0);
            }
        }
    }
}



struct FaceGenMorph
{
    FaceGenMatrix<float> FUN_00658360(char* pcCoords);
};

struct FaceGenMorphArray
{
    int unk00;
    int unk04;
    int unk08;
    FaceGenMorph* m_pBegin;
    FaceGenMorph* m_pRecordEnd;
    int unk14;
    unsigned int std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size();
    FaceGenMorph& GetElementPointerChecked(unsigned int uiIndex);
};

// Returns the first coordinate value of a morph at uiIndex for the given pcCoords, or 0.0f if out of range or pcCoords is null.
// @fnv 0x00652230
float GetMorphCoordinateValue(char* pcCoords, unsigned int uiRenderPassIndex, unsigned int uiSub, unsigned int uiIndex)
{
    float fValue = 0.0f;
    if (pcCoords)
    {
        if (uiIndex < reinterpret_cast<FaceGenMorphArray(*)[2]>(BSFaceGenManager::GetFaceGenManager()->m_kCtls.ctl)
                          [uiRenderPassIndex][uiSub].std_vector_FanLinCtlS_std_allocator_FanLinCtlS_size())
        {
            fValue = reinterpret_cast<FaceGenMorphArray(*)[2]>(BSFaceGenManager::GetFaceGenManager()->m_kCtls.ctl)
                         [uiRenderPassIndex][uiSub]
                         .GetElementPointerChecked(uiIndex)
                         .FUN_00658360(pcCoords + uiRenderPassIndex * 0x40 + uiSub * 0x20)
                         .ForwardCall_0060b370(0)
                         .NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(0);
        }
    }
    return fValue;
}

// 0x00651b50 - BSFaceGenManager.cpp helper

extern GO45CFE0 g_011d59f4;
extern GO45CFE0 g_011d5afc;

// Looks up a Sol face-gen model in the BSFaceGenManager cache by a1 or a4, creating and caching a new one via FUN_00659c70 when a5 is true and no entry exists.
// @fnv 0x00651b50
Sol* GetOrCreateFaceGenModel(char* a1, char* a2, char* a3, char* a4, bool abCreateIfMissing, int a6, bool a7)
{
    AutoMemContext mem(0x37, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\FaceGen\\BSFaceGenManager.cpp", 0x3e5);
    SolPtr ref(0);

    if (a1 == 0 && a4 == 0)
        return 0;

    if (BSFaceGenManager::GetFaceGenManager()->m_pModelCache == 0)
    {
        BSFaceGenManager::GetFaceGenManager()->m_pModelCache = new BSFaceGenModelMap;
        BSFaceGenManager::GetFaceGenManager()->m_pModelCache->SetArrayValue(0, g_011d59f4.FUN_004503f0());
        BSFaceGenManager::GetFaceGenManager()->m_pModelCache->SetArrayValue(1, g_011d5afc.FUN_004503f0());
    }

    if (a1)
    {
        if (reinterpret_cast<FGModelCache*>(BSFaceGenManager::GetFaceGenManager()->m_pModelCache)->BSFaceGenModelMap_GetAt(a1, reinterpret_cast<Helper62d0*>(&ref)))
        {
            if (a4)
            {
                if (!ref.Get()->BSFaceGenModel_GetString())
                    ref.Get()->FUN_0065a760(a4);
            }
            return ref.Get();
        }
    }
    else if (a4)
    {
        if (reinterpret_cast<FGModelCache*>(BSFaceGenManager::GetFaceGenManager()->m_pModelCache)->BSFaceGenModelMap_GetAt(a4, reinterpret_cast<Helper62d0*>(&ref)))
            return ref.Get();
    }

    if (abCreateIfMissing)
    {
        ref = new Sol;
        if (ref.Get()->BSFaceGenModel_LoadModel(a1, a2, a3, a4, a6, a7))
        {
            reinterpret_cast<fnv_0064ffd0::FGModelCache*>(BSFaceGenManager::GetFaceGenManager()->m_pModelCache)->BSFaceGenModelMap_SetAt(a1 ? a1 : a4, ref.Get());
        }
        else
        {
            ref = 0;
        }
    }

    return ref.Get();
}

struct FUN_00659190_class
{
    void* unk00;
    unsigned int unk04;

    bool __thiscall ActorCause_IsValid();
    unsigned char* __thiscall FaceGenData_Iterator_FaceGenData_GetUnk00();

    FUN_00659190_class* __thiscall DoNothing();
};

// Calls two checks, increments a field by 4, and returns this.
// @fnv 0x00659190
// src: GUESS 0x00659190 (confidence: high)
FUN_00659190_class* __thiscall FUN_00659190_class::DoNothing()
{
    if (!ActorCause_IsValid())
        FUN_00ec7c56();

    do
    {
    } while (0);

    if (unk04 >= *reinterpret_cast<unsigned int*>(FaceGenData_Iterator_FaceGenData_GetUnk00() + 0x10))
        FUN_00ec7c56();

    do
    {
    } while (0);

    unk04 += 4;
    return this;
}

namespace fnv_006518e0 {
struct Cache
{
    virtual ~Cache();
    void PurgeUnusedModels(bool);
};
}  // namespace fnv_006518e0

// Destroys the object, purging unused models from the cache before deleting it and nulling the pointer.
// @fnv 0x006518e0
BSFaceGenManager::~BSFaceGenManager()
{
    BSFaceGenManager_ClearModelCache();
    if (m_pModelCache)
        m_pModelCache->PurgeUnusedModels(false);
    delete reinterpret_cast<fnv_006518e0::Cache*>(m_pModelCache);
    m_pModelCache = 0;
}
