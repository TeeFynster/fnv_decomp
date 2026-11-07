// fallout_shared/speedtree/bstreemanager.cpp: BSTreeManager, LFFreeList, TreeManager (27 functions)

#include "../../../include/NiPointer.h"
#include "../../../include/NiMemObject.h"
#include "../../../include/NP.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiColor.h"
#include "../../../include/NiPixelFormat.h"
#include "../../../include/NiPixelData.h"
#include "../../../include/NiPosData.h"
#include "../../../include/NiProperty.h"
#include "../../../include/NiTexture.h"
#include "../../../include/BSTreeModel.h"
#include "../../../include/Sky.h"
#include "../../../include/TESFile.h"
#include "../../../include/TESModel.h"
#include "../../../include/TESObjectTREE.h"
#include "../../../include/Setting.h"

#include <new>
#include "../../../include/TES.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/NiTPointerMap.h"

#include "../../../include/MEM_CONTEXT.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BSShaderNoLightingProperty.h"
#include "../../../include/BSTreeManager.h"

class LockFreeMap_TESObjectREFR___BSTreeNode___;
extern BSTreeManager* DAT_011d5c48;
extern TES* g_TES;
void BSTreeManager_Destroy_();
void* BSTreeManager_GetInstance(bool);
void SetGlobalValue(bool);
void SetGlobalFloatFromUInt(unsigned int);
void ClampAndStoreValue(float);
extern float DAT_011fd890;
extern float DAT_011adce0;

// @fnv 0x00664870
void BSTreeManager::Create(bool create)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TREESYSTEM, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp",
                           0xb1);
    if (DAT_011d5c48)
    {
        if (create)
            BSTreeManager_Destroy_();
        else
            return;
    }

    DAT_011d5c48 = new BSTreeManager();
}

// @fnv 0x00665860
void BSTreeManager::UpdateTreeInstances()
{
    if (((NiPointer<NiAVObject>*)((char*)BSTreeManager_GetInstance(true) + 4))->operator NiAVObject*())
    {
        ((NiPointer<NiNode>*)((char*)BSTreeManager_GetInstance(true) + 4))->operator=(0);
        SetGlobalValue(false);
        g_TES->LoadCanopyShadowTexture("Data\\Textures\\Trees\\CanopyShadow.dds", 0);
    }
}

// Returns DAT_011d5c48, creating the BSTreeManager first when create is true and it is not yet set.
// @fnv 0x00664840
// src: XBOX_PDB 0x00664840
void* BSTreeManager_GetInstance(bool create)
{
    if (!DAT_011d5c48 && create)
        BSTreeManager::Create(false);

    return DAT_011d5c48;
}

// Stores the unsigned int argument converted to float into the global DAT_011fd890.
// @fnv 0x00664720
void SetGlobalFloatFromUInt(unsigned int value)
{
    DAT_011fd890 = (float)value;
}

// Clamps value to the range [0.0, 1.0] and stores the result in DAT_011adce0.
// @fnv 0x00665520
void ClampAndStoreValue(float value)
{
    float fClampedResult;
    float fClampedValue;

    if (value >= 0.0)
    {
        if (value <= 1.0)
            fClampedValue = value;
        else
            fClampedValue = 1.0f;

        fClampedResult = fClampedValue;
    }
    else
    {
        fClampedResult = 0.0f;
    }

    DAT_011adce0 = fClampedResult;
}


extern NP DAT_011f95e4;

// @fnv 0x00664820
void SetGlobalValue(unsigned int value)
{
    DAT_011f95e4 = (void*)value;
}

// @fnv 0x006652c0
void BSTreeModel::SetByteAtOffset44(unsigned char value)
{
    *reinterpret_cast<unsigned char*>(&unk44) = value;
}

extern Setting originalRuntimeFloatSetting1295;

// @fnv 0x006655a0
// src: COMMUNITY 0x006655a0
float GameSetting_fTreeNearDistanceBase_Get()
{
    return *originalRuntimeFloatSetting1295.Float();
}

namespace fnv_006655f0 {
extern Setting originalRuntimeFloatSetting1296;

// @fnv 0x006655f0
float GetOriginalRuntimeFloatSetting1296()
{
    return *originalRuntimeFloatSetting1296.Float();
}
}  // namespace fnv_006655f0

extern unsigned char __cdecl GetFirstProcessListByte(void);
extern unsigned char* __cdecl _FUN_00664840(bool);

// Returns 1 if GetFirstProcessListByte succeeds and the byte at offset 0x18 of the object from _FUN_00664840(true) is nonzero, otherwise 0.
// @fnv 0x0054ee20
// src: COMMUNITY 0x0054ee20
unsigned char BSTreeManager_GetTreesEnabled(bool abCreateIfNotFound)
{
    int result;
    if (GetFirstProcessListByte() && ((unsigned char*)(_FUN_00664840(true) + 0x18))[0])
        result = 1;
    else
        result = 0;
    return result;
}

struct S664990
{
    void* DestroyIfFlagged(int);
};
// If DAT_011d5c48 is set, calls its DestroyIfFlagged with 1, then clears DAT_011d5c48.
// @fnv 0x00664940
// src: COMMUNITY 0x00664940
void BSTreeManager_Destroy_()
{
    void* b;
    if (DAT_011d5c48)
    {
        void* a;
        a = DAT_011d5c48;
        b = a;
        {
            void* c;
            if (b)
                c = ((S664990*)b)->DestroyIfFlagged(1);
            else
                c = 0;
        }
        DAT_011d5c48 = 0;
    }
}

struct FUN_00664990_shell
{
    void FUN_00664740();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00664740, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x00664990
void* FUN_00664990_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00664740();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern Setting DAT_011f9158;
// Returns the result of FUN_006655a0 multiplied by the float value stored in DAT_011f9158.
// @fnv 0x00665570
// src: COMMUNITY 0x00665570
float fTreeNearDistance_Get()
{
    return (double)GameSetting_fTreeNearDistanceBase_Get() * *DAT_011f9158.Float();
}

double GetOriginalRuntimeFloatSetting1296();
extern Setting DAT_011f9158;
// Returns the value from GetOriginalRuntimeFloatSetting1296 multiplied by the float stored in DAT_011f9158.
// @fnv 0x006655c0
// src: COMMUNITY 0x006655c0
float fTreeFarDistanceBase_Get()
{
    return GetOriginalRuntimeFloatSetting1296() * *DAT_011f9158.Float();
}

struct I2_665b80
{
    virtual int Func(int);
};
struct I1_665b80
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned char Foo(int, I2_665b80**, int);
};
struct C665b80
{
    void BSTreeManager_AddBackgroundLoadedTree(int, I2_665b80*);
};
// Calls Foo on the object at this+0x1c; if it returns false, calls Func(1) on b when b is non-null.
// @fnv 0x00665b80
// src: XBOX_PDB 0x00665b80
void C665b80::BSTreeManager_AddBackgroundLoadedTree(int aiValue, I2_665b80* pObject)
{
    I2_665b80* p1;
    I2_665b80* p2;
    if (!(*(I1_665b80**)((char*)this + 0x1c))->Foo(aiValue, &pObject, 0))
    {
        p1 = pObject;
        p2 = p1;
        p2 ? p2->Func(1) : 0;
    }
}

struct NiStream;
class GameTimerRecord;
namespace fnv_006652e0 {
using ::NiMemObject;
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
typedef char _sizecheck_NiColor[sizeof(NiColor) == 12 ? 1 : -1];

struct B006815c0
{
    B006815c0();
    float x;
    float y;
    float z;
};
NiPoint3* __fastcall NiAVObject_GetWorldTranslate(NiAVObject*);
struct Twin_0084d030
{
    float GetStoredFloatValue();
};
extern GameTimerRecord g_timeGlobal;
extern float DAT_011d5dd4;
void CSpeedTreeRT_SetTime(float);
void CSpeedTreeRT_SetCamera(float*, float*);
struct CP_008c48d0
{
    int GetPrevPath();
};
struct FUN_00450570_shell
{
    TESFile* Sky_GetFog();
};
struct FUN_004534f0_shell
{
    void FUN_004534f0(unsigned int);
};
struct FUN_006658b0_shell
{
    void Update();
};
extern Setting g_011d5d98;
extern Setting g_011d5d4c;

// @fnv 0x006652e0
// src: XBOX_PDB 0x006652e0
void BSTreeManager_Update(NiAVObject* apCamera, bool abMenuMode)
{
    B006815c0 vecTemp;
    float fcamDir[3];
    float fcamLoc[3];
    if (!abMenuMode)
    {
        DAT_011d5dd4 += ((Twin_0084d030*)&g_timeGlobal)->GetStoredFloatValue();
        CSpeedTreeRT_SetTime(DAT_011d5dd4);
    }
    if (apCamera)
    {
        fcamLoc[0] = NiAVObject_GetWorldTranslate(apCamera)->x;
        fcamLoc[1] = NiAVObject_GetWorldTranslate(apCamera)->y;
        fcamLoc[2] = NiAVObject_GetWorldTranslate(apCamera)->z;
        vecTemp = (const B006815c0&)NiPosData::ComputePositionAtTime(-1.0f, apCamera->GetWorldTranslation());
        fcamDir[0] = vecTemp.x;
        fcamDir[1] = vecTemp.y;
        fcamDir[2] = vecTemp.z;
        CSpeedTreeRT_SetCamera(fcamLoc, fcamDir);
    }
    if (!abMenuMode)
    {
        if (g_TES && ((BSShaderNoLightingProperty*)g_TES)->GetBaseTexture())
        {
            if (((CP_008c48d0*)g_TES)->GetPrevPath())
                *(float*)(_FUN_00664840(1) + 0x14) = 0.0f;
            else
                *(float*)(_FUN_00664840(1) + 0x14) =
                    ((Sky*)((BSShaderNoLightingProperty*)g_TES)->GetBaseTexture())->GetFieldCC();
            if ((unsigned int)(NiProperty*)*(NiPointer<NiProperty>*)(_FUN_00664840(1) + 8) &&
                ((FUN_00450570_shell*)((BSShaderNoLightingProperty*)g_TES)->GetBaseTexture())->Sky_GetFog())
            {
                NiColor col = *(const NiColor*)((FUN_00450570_shell*)((BSShaderNoLightingProperty*)g_TES)->GetBaseTexture())
                           ->Sky_GetFog()
                           ->GetName();
                ((FUN_004534f0_shell*)(unsigned int)(NiProperty*)*(NiPointer<NiProperty>*)(_FUN_00664840(1) + 8))->FUN_004534f0((unsigned int)&col);
                ((FUN_004534f0_shell*)(unsigned int)(NiProperty*)*(NiPointer<NiProperty>*)(_FUN_00664840(1) + 8))->FUN_004534f0((unsigned int)&col);
                ((NiProperty*)(unsigned int)(NiProperty*)*(NiPointer<NiProperty>*)(_FUN_00664840(1) + 8))->NiMaterialProperty_SetEmittance(&col);
            }
        }
        ((FUN_006658b0_shell*)_FUN_00664840(1))->Update();
    }
    SetGlobalFloatFromUInt(*g_011d5d98.Int());
    ClampAndStoreValue(*((Setting*)&g_011d5d4c)->Float());
}
}  // namespace fnv_006652e0

struct TreeLockObj
{
    void Lock(int);
    void Unlock();
};
extern TreeLockObj g_treeLock;

// The shared class has no key getter; this declaration preserves its ECX-only call.
int __fastcall GetTreeModelKey(const BSTreeModel* model);

struct TreeMgr664b50
{
    NiPointer<BSTreeModel>* GetEntry(TESObjectTREE* tree);
    void GetOrCreateModel(TESObjectTREE* tree, int key, NiPointer<BSTreeModel>& out);
};

// @fnv 0x00664b50
void TreeMgr664b50::GetOrCreateModel(TESObjectTREE* tree, int key, NiPointer<BSTreeModel>& out)
{
    g_treeLock.Lock(0);
    NiPointer<BSTreeModel> spModel3(0);
    if (tree)
    {
        NiPointer<BSTreeModel>* entries3 = GetEntry(tree);
        int freeIdx3 = -1;
        bool found3 = false;
        for (int i3 = 0; i3 < 1; i3++)
        {
            BSTreeModel* model = entries3[i3];
            if (model)
            {
                if (GetTreeModelKey(model) == key)
                {
                    spModel3 = model;
                    found3 = true;
                    break;
                }
            }
            else if (freeIdx3 == -1)
            {
                freeIdx3 = i3;
            }
        }
        if (!found3 || !spModel3)
        {
            if (freeIdx3 < 0)
            {
                spModel3 = *entries3;
            }
            else
            {
                spModel3 = new BSTreeModel;
                entries3[freeIdx3] = spModel3;
            }
        }
    }
    g_treeLock.Unlock();
    out = spModel3;
}

struct FUN_00665be0_interface
{
    virtual void f0();
    virtual void f1();
    virtual bool f2(int, void**);
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
};

struct C665be0_shell
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    FUN_00665be0_interface* unk1c;

    void BSTreeManager_RemoveBackgroundLoadedTree(int value);
};

extern "C" void __cdecl _free(void*);

// @fnv 0x00665be0
// src: XBOX_PDB 0x00665be0
void C665be0_shell::BSTreeManager_RemoveBackgroundLoadedTree(int value)
{
    void* result = 0;

    if (unk1c->f2(value, &result))
    {
        unk1c->f5(value);

        if (result != 0)
        {
            _free(result);
        }
    }
}

extern const char kThreadSafeStructuresSourceFile[];
void* CopyMemoryBlock(void* dst, const void* src, unsigned int size);

struct LFNode
{
    LFNode* GetNext();
    void SetNext(LFNode* next);
};

struct LFThreadData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LFNode** m_pAdditionalHudTile;
    unsigned int GetMaxThreads() const;
};

struct LFFreeList
{
    LFThreadData* pThreadData;
    int unk04;
    int unk08;
    unsigned int iCount;
    LFNode* pHead;
    void PruneFreeList();
};

// @fnv 0x006c7610
void LFFreeList::PruneFreeList()
{
    AutoMemContext context_2(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true, kThreadSafeStructuresSourceFile, 0xd0);
    unsigned int uiSlotsVal = pThreadData->GetMaxThreads() * 2;
    LFNode** ppActive = new LFNode*[uiSlotsVal];
    CopyMemoryBlock(ppActive, pThreadData->m_pAdditionalHudTile, uiSlotsVal * 4);
    LFNode* pKept = 0;
    unsigned int uiKept = 0;
    while (pHead)
    {
        LFNode* pNode4 = pHead;
        pHead = pHead->GetNext();
        bool bInUse4 = false;
        for (unsigned int i2 = 0; i2 < uiSlotsVal; i2++)
        {
            if (pNode4 == ppActive[i2])
            {
                bInUse4 = true;
                break;
            }
        }
        if (bInUse4)
        {
            pNode4->SetNext(pKept);
            pKept = pNode4;
            uiKept++;
        }
        else
        {
            pNode4->SetNext(0);
            delete pNode4;
        }
    }
    delete[] ppActive;
    pHead = pKept;
    iCount = uiKept;
}

void __cdecl SetMode664(int iMode);
void __cdecl SetEnabled664(bool bEnabled);
void __cdecl SetTarget664(void* pvTarget);
void __cdecl SetState664(int iState);
void __cdecl Refresh664();

class Child664
{
  public:
    virtual ~Child664();
};

class FUN_00664740
{
  public:
    ~FUN_00664740();

    int unk00;
    NiPointer<NiTexture> m_kFirst;
    NiPointer<NiMaterialProperty> m_kSecond;
    NiPointer<NiAlphaProperty> m_kThird;
    NiPointer<BSXFlags> m_kFourth;
    int unk14;
    int unk18;
    Child664* m_pkChild;
};

// Resets mode, enabled state, target and state, refreshes, then deletes m_pkChild.
// @fnv 0x00664740
FUN_00664740::~FUN_00664740()
{
    SetMode664(0);
    SetEnabled664(false);
    SetTarget664(0);
    SetState664(1);
    Refresh664();
    delete m_pkChild;
}


class FUN_00665c50
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_hashSize;
    void** m_hashTable;
    unsigned int m_uiItemCount;
    FUN_00665c50(int hashSize);
    ~FUN_00665c50();
};

struct Mgr6649c0
{
    FUN_00665c50* m_map;
    NiPointer<NiTexture>* GetOrCreateTexturePointer(unsigned int key);
};

// Looks up key in m_map, creating the map if null and inserting a new NiPointer<NiTexture> array when absent, then returns the pointer.
// @fnv 0x006649c0
NiPointer<NiTexture>* Mgr6649c0::GetOrCreateTexturePointer(unsigned int key)
{
    AutoMemContext ctx(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                       "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp", 216);
    NiPointer<NiTexture>* value2 = 0;
    if (key == 0)
        return 0;
    if (m_map == 0)
        m_map = new FUN_00665c50(37);
    if (((NiTPointerMap<unsigned int, unsigned int>*)m_map)->GetAt(key, *(unsigned int*)&value2))
        return value2;
    value2 = new NiPointer<NiTexture>[1];
    ((NiTPointerMap<unsigned int, unsigned int>*)m_map)->SetAt(key, *(unsigned int*)&value2);
    return value2;
}

class TreeReference : public TESObjectREFR
{
  public:
    unsigned int TESObjectREFR_GetSpeedTreeSeed();
    float TESObjectREFR_GetScale_00567400();
};
class LockFreeMap_TESObjectREFR___BSTreeNode___
{
  public:
    virtual void f0();
    virtual void f1();
    virtual bool Find(TreeReference*, NiAVObject**);
    virtual void f3();
    virtual void f4();
    virtual void Remove(TreeReference*);
};
struct TreeModelManager
{
    void GetOrCreateModel(TESObjectTREE*, unsigned int, NiPointer<BSTreeModel>&);
};
struct TreeManager : BSTreeManager
{
    NiAVObject* CreateTreeInstance(TreeReference*, TESObjectTREE*);
};
// Validates the tree and reference, looks up or builds a BSTreeModel, creates a scaled NiAVObject instance, names it from the model path, and returns it.
// @fnv 0x00664f50
NiAVObject* TreeManager::CreateTreeInstance(TreeReference* reference, TESObjectTREE* tree)
{
    AutoMemContext cached(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                          "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp", 462);
    NiPointer<BSTreeModel> scale(0);
    BSTreeModel* model = 0;
    if (!GetFirstProcessListByte() || !tree || !tree->GetModelFilePath() || !tree->TESModel::GetModelLength() ||
        (reference && reference->GetObjectReference() != (TESBoundObject*)tree))
        return 0;
    NiAVObject* m_uiMemoryContext = 0;
    if (m_pTreeInstanceMap->Find(reference, &m_uiMemoryContext))
    {
        m_pTreeInstanceMap->Remove(reference);
        return m_uiMemoryContext;
    }
    unsigned int node = 1;
    if (reference)
        node = reference->TESObjectREFR_GetSpeedTreeSeed();
    ((TreeModelManager*)BSTreeManager_GetInstance(true))->GetOrCreateModel(tree, node, scale);
    if (!(BSTreeModel*)scale)
        return 0;
    if (((BSTreeModel*)scale)->FUN_00726070() > 2)
    {
        model = new BSTreeModel;
        if (!model->CloneFromModel(scale))
        {
            delete model;
            return 0;
        }
    }
    else
    {
        if (!((BSTreeModel*)scale)->BSTreeModel_InitFromBase(tree, node))
            return 0;
        model = scale;
    }
    float key = 1.0f;
    if (reference)
        key = reference->TESObjectREFR_GetScale_00567400();
    NiAVObject* instanceModel = model->CreateInstance(key);
    if (instanceModel)
        instanceModel->SetName(NiFixedString(tree->GetModelFilePath()));
    model->SetByteAtOffset44(1);
    return instanceModel;
}

namespace fnv_00665610 {
extern const NiPixelFormat DAT_011aa2e8;
struct TreeTextureState
{
    unsigned int unk00;
    NiPointer<NiSourceTexture> shadow;
};
struct TextureLoader
{
    void FUN_004568c0(const char* filename, NiPointer<NiSourceTexture>& texture, bool first, bool second);
};
struct TextureFormatPrefs
{
    unsigned int pixelLayout;
    unsigned int alphaFormat;
    unsigned int mipmapped;
};
extern const TextureFormatPrefs DAT_011a9598;
NiSourceTexture* NiSourceTexture_Create(NiPixelData* pixels, const char* name, const TextureFormatPrefs& preferences);

// Ensures the tree state's shadow texture is loaded from CanopyShadow.dds or generated as a 16x16 white NiPixelData, then returns it.
// @fnv 0x00665610
// src: XBOX_PDB 0x00665610
NiSourceTexture* BSTreeManager_GetCanopyShadow()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TREEART, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\SpeedTree\\BSTreeManager.cpp", 629);
    if (!((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow.operator NiSourceTexture*())
    {
        if (g_TES)
            ((TextureLoader*)g_TES)
                ->FUN_004568c0("Data\\Textures\\Trees\\CanopyShadow.dds",
                               ((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow, true, false);
        else
            ((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow.operator=(0);
        SetGlobalValue((unsigned int)((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow.operator NiSourceTexture*());
    }
    if (!((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow.operator NiSourceTexture*())
    {
        NiPixelData* pixels = new NiPixelData(16, 16, &DAT_011aa2e8, 1, 1);
        unsigned char* pPixelBytes = pixels->NiPixelData_GetPixels(0u, 0u);
        for (unsigned int y = 0; y < 16; ++y)
        {
            for (unsigned int x = 0; x < 16; ++x)
            {
                pPixelBytes[(y * 16 + x) * 3] = 255;
                pPixelBytes[(y * 16 + x) * 3 + 1] = 255;
                pPixelBytes[(y * 16 + x) * 3 + 2] = 255;
            }
        }
        pixels->FUN_004f31b0();
        ((TreeTextureState*)BSTreeManager_GetInstance(true))
            ->shadow.operator=(NiSourceTexture_Create(pixels, NiFixedString("CanopyShadowTexture"), DAT_011a9598));
        SetGlobalValue((unsigned int)((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow.operator NiSourceTexture*());
    }
    return ((TreeTextureState*)BSTreeManager_GetInstance(true))->shadow.operator NiSourceTexture*();
}
}  // namespace fnv_00665610

// The compiler's array-deletion entry is absent from the shared template's public API.
// Keep its ECX entry as a deletion helper; the elements use the shared NiPointer layout.
struct TreeModelPointerArrayDeleter
{
    void* Delete(unsigned int flags);
};
struct Map664
{
    virtual void* Destroy(unsigned int);
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*&, unsigned int&, NiPointer<BSTreeModel>*&);
    bool RemoveKey(unsigned int);
    bool IsFieldCZero();
    void FUN_00438af0();
};
struct Timer664
{
    void BSCriticalSection_Enter(int);
    void FUN_004538c0();
};
extern "C" char DAT_011d5cc0;
struct Entry664
{
    static void BSTreeManager_ClearModelCache(bool);
};
// @fnv 0x00664cd0
// src: XBOX_PDB 0x00664cd0
void Entry664::BSTreeManager_ClearModelCache(bool partial)
{
    NiPointer<BSTreeModel>* p;
    void* h;
    unsigned int a;
    bool i;
    int s;
    void* f;
    NiPointer<BSTreeModel>* eb;
    unsigned int cf;
    NiPointer<BSTreeModel> *b, *q, *c, *l;
    Map664 *k, *ba, *j, *e;
    if (!*(Map664**)_FUN_00664840(true))
        return;
    ((Timer664*)&DAT_011d5cc0)->BSCriticalSection_Enter(0);
    if (partial)
    {
        h = (*(Map664**)_FUN_00664840(true))->FUN_004b9ba0();
        while (h)
        {
            (*(Map664**)_FUN_00664840(true))->FUN_006b7f20(h, a, p);
            if (p)
            {
                i = true;
                for (s = 0; s < 1; ++s)
                {
                    if (p[s].operator BSTreeModel*())
                    {
                        if (p[s].operator BSTreeModel*()->FUN_00726070() <= 1)
                            p[s].operator=(0);
                        else
                            i = false;
                    }
                }
                if (i)
                {
                    b = p;
                    q = b;
                    q ? reinterpret_cast<TreeModelPointerArrayDeleter*>(q)->Delete(3) : 0;
                    p = 0;
                    (*(Map664**)_FUN_00664840(true))->RemoveKey(a);
                    h = (*(Map664**)_FUN_00664840(true))->FUN_004b9ba0();
                }
            }
        }
        if ((*(Map664**)_FUN_00664840(true))->IsFieldCZero())
        {
            (*(Map664**)_FUN_00664840(true))->FUN_00438af0();
            k = *(Map664**)_FUN_00664840(true);
            ba = k;
            ba ? ba->Destroy(1) : 0;
            *(Map664**)_FUN_00664840(true) = 0;
        }
    }
    else
    {
        f = (*(Map664**)_FUN_00664840(true))->FUN_004b9ba0();
        while (f)
        {
            (*(Map664**)_FUN_00664840(true))->FUN_006b7f20(f, cf, eb);
            c = eb;
            l = c;
            l ? reinterpret_cast<TreeModelPointerArrayDeleter*>(l)->Delete(3) : 0;
        }
        (*(Map664**)_FUN_00664840(true))->FUN_00438af0();
        j = *(Map664**)_FUN_00664840(true);
        e = j;
        e ? e->Destroy(1) : 0;
        *(Map664**)_FUN_00664840(true) = 0;
    }
    ((Timer664*)&DAT_011d5cc0)->FUN_004538c0();
}

extern "C" char DAT_011d5dec, DAT_011d5de8, DAT_011d5dd8, DAT_0119b8cc;
extern "C" char DAT_011f6394, DAT_011d5dc4, DAT_011d5d3c, DAT_011d5c68, DAT_011d5c74, DAT_011d5c5c, DAT_011d5cdc;
struct Time6658
{
    float FUN_0084d030();
};
// Wind update reads two float frequencies per entry; shared Pair stores two integers.
struct WindFrequency
{
    float x, y;
};
float NiSinQ(float);
float NiCosQ(float);
namespace std {
double abs(float);
}
void Object_ProcessAndReturnValue_00bb2fc0(int, float, float);
void Runtime_UpdateState_00bb1390(float, float, float, float);
struct C6658
{
    char pad[20];
    float value;
    void Update();
};
// @fnv 0x006658b0
void C6658::Update()
{
    if ((*(int*)&DAT_011d5dec & 1) == 0)
    {
        *(int*)&DAT_011d5dec |= 1;
        (*(float*)&DAT_011d5de8) = value;
    }
    int i = 0;
    float amplitudeB = value * 0.6100000143051147;
    float sum = 0.0f;
    for (i = 0; i < 4; i++)
    {
        ((float*)&DAT_011d5dd8)[i] += ((Time6658*)&DAT_011f6394)->FUN_0084d030();
        if (value != 0.0)
            ((float*)&DAT_011d5dd8)[i] = ((float*)&DAT_011d5dd8)[i] * (*(float*)&DAT_011d5de8) / value;
        float speed4 = value * 20.0;
        float s7 = NiSinQ(speed4 * ((WindFrequency*)&DAT_0119b8cc)[i].x * ((float*)&DAT_011d5dd8)[i]);
        float c = NiCosQ(speed4 * ((WindFrequency*)&DAT_0119b8cc)[i].y * ((float*)&DAT_011d5dd8)[i]);
        if (i == 2)
        {
            sum += std::abs(s7);
            sum += std::abs(c);
        }
        Object_ProcessAndReturnValue_00bb2fc0(i, amplitudeB * s7, amplitudeB * c);
    }
    float a7 = (1.0 - *((Setting*)&DAT_011d5dc4)->Float()) +
               *((Setting*)&DAT_011d5dc4)->Float() * sum / 2.0;
    float b = (1.0 - *((Setting*)&DAT_011d5d3c)->Float()) +
              *((Setting*)&DAT_011d5d3c)->Float() * sum / 2.0;
    float outerc4 = (1.0 - *((Setting*)&DAT_011d5c68)->Float()) +
                    *((Setting*)&DAT_011d5c68)->Float() * sum / 2.0;
    float d9 = (1.0 - *((Setting*)&DAT_011d5c74)->Float()) +
               *((Setting*)&DAT_011d5c74)->Float() * sum / 2.0;
    Runtime_UpdateState_00bb1390(value * a7, value * b,
                 ((Time6658*)&DAT_011f6394)->FUN_0084d030() * *((Setting*)&DAT_011d5cdc)->Float() * outerc4,
                 ((Time6658*)&DAT_011f6394)->FUN_0084d030() * *((Setting*)&DAT_011d5c5c)->Float() * d9);
    (*(float*)&DAT_011d5de8) = value;
}

struct xMemObj
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* p, unsigned int);
};


class xMatProp : public xMemObj
{
  public:
    int m_ai[0x13];
    xMatProp();
    void SetAmbient(const NiColor& kColor);
    void SetEmittance(const NiColor& kColor);
};

class xAlphaProp : public xMemObj
{
  public:
    int m_ai[7];
    xAlphaProp();
    void SetAlphaBlending(bool b);
    void SetSrcBlendMode(unsigned short us);
    void SetTestRef(unsigned char uc);
    void SetAlphaTesting(bool b);
};

class xFlagsObj : public xMemObj
{
  public:
    int m_ai[4];
    xFlagsObj(int i);
};

class xMapObj
{
  public:
    int m_ai[0x10];
    xMapObj(int a, int b, int c);
};

extern Setting xGB5d00;
extern Setting xGI5d98;

void xF_b07db0(int i);
void xF_b084f0(unsigned char uc);
void xF_b0d7b0(unsigned char uc);
void xF_664720(unsigned int ui);

class FUN_00664440
{
  public:
    int m_i0;
    NiPointer<xMemObj> m_sp4;
    NiPointer<xMatProp> m_spMat;
    NiPointer<xAlphaProp> m_spAlpha;
    NiPointer<xFlagsObj> m_spFlags;
    float m_f14;
    bool m_b18;
    bool m_b19;
    bool m_b1a;
    bool m_b1b;
    xMapObj* m_pMapObject;
    FUN_00664440();
};

// Initializes material, alpha, and flag properties with default values, then creates a map object and calls global setup functions.
// @fnv 0x00664440
FUN_00664440::FUN_00664440()
    : m_sp4(0), m_spMat(0), m_spAlpha(0), m_spFlags(0)
{
    m_i0 = 0;
    m_f14 = 0.0f;
    m_b19 = true;
    m_b18 = true;
    m_b1a = false;
    m_b1b = *xGB5d00.Bool();
    m_spMat = new xMatProp();
    m_spMat->SetAmbient(NiColor(1.0f, 1.0f, 1.0f));
    m_spMat->SetAmbient(NiColor(1.0f, 1.0f, 1.0f));
    m_spMat->SetEmittance(NiColor(1.0f, 1.0f, 1.0f));
    m_spAlpha = new xAlphaProp();
    m_spAlpha->SetAlphaBlending(true);
    m_spAlpha->SetSrcBlendMode(4);
    m_spAlpha->SetTestRef(0x54);
    m_spAlpha->SetAlphaTesting(false);
    m_spFlags = new xFlagsObj(3);
    xF_b07db0(4);
    xF_b084f0(1);
    xF_b0d7b0(1);
    xF_664720(*xGI5d98.Int());
    m_pMapObject = new xMapObj(2, 0x25, 0xc);
}

// The array iterator needs the existing destructor entry as a callback.
void __fastcall DestroyTreeModelPointer(NiPointer<BSTreeModel>* pointer);
struct PointerArrayCount667
{
    unsigned int count;
};
void __stdcall FUN_00ec5fce(void*, unsigned int, int, void (__thiscall*)(NiPointer<BSTreeModel>*));

// Destroys the object or its array elements, optionally frees the allocation, and returns this or the preceding count header.
// @fnv 0x00667120
void* TreeModelPointerArrayDeleter::Delete(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 4, (reinterpret_cast<PointerArrayCount667*>(this) - 1)->count,
                     reinterpret_cast<void (__thiscall*)(NiPointer<BSTreeModel>*)>(&DestroyTreeModelPointer));
        if (flags & 1)
            ::operator delete(reinterpret_cast<PointerArrayCount667*>(this) - 1);
        return reinterpret_cast<PointerArrayCount667*>(this) - 1;
    }
    reinterpret_cast<NiPointer<BSTreeModel>*>(this)->~NiPointer();
    if (flags & 1)
        ::operator delete(this);
    return this;
}
