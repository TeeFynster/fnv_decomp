#include "../../include/BSFile.h"
#include "../../include/BSFadeNode.h"
#include "../../include/GO.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiTMap.h"
#include "../../include/SL.h"
#include "../../include/StrMem.h"
#include "../../include/TES.h"

// src/fallout_shared/bgstextureusemap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgstextureusemap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_004aa3d0_shell
{
    void BGSTextureUseMap_CollectTexUseDataRecursive(int a, char b);
    void SetValueAndCall(int a, int b, char c);
};

// src: XBOX_PDB 0x004aa3d0
void FUN_004aa3d0_shell::BGSTextureUseMap_CollectTexUseDataRecursive(int a, char b)
{}

// Stores b into the object's first field and forwards a and c to FUN_004aa3d0.
// @fnv 0x004aa3a0
void FUN_004aa3d0_shell::SetValueAndCall(int aiArg, int aiValue, char c)
{
    *(int*)this = aiValue;
    BGSTextureUseMap_CollectTexUseDataRecursive(aiArg, c);
}

struct FUN_004aa830;

struct UnsignedIntegerRecord
{
    unsigned int m0;
    unsigned long m_ulSecondValue;
};

struct NiTMapContainer
{
    unsigned int m1;
    NiTMap<unsigned int, FUN_004aa830*> m_kEntryMap;
    unsigned long BGSTextureUseMap_GetTotalTextureSize();
};

// @fnv 0x004aa890
// src: XBOX_PDB 0x004aa890
unsigned long NiTMapContainer::BGSTextureUseMap_GetTotalTextureSize()
{
    unsigned long ulretsize = 0;
    void* iter = this->m_kEntryMap.GetFirstPos();
    while (iter)
    {
        unsigned int key = 0;
        UnsignedIntegerRecord* pdata = 0;
        this->m_kEntryMap.GetNext(iter, key, reinterpret_cast<FUN_004aa830*&>(pdata));
        if (pdata)
        {
            ulretsize += pdata->m_ulSecondValue;
        }
    }
    return ulretsize;
}

extern int _data_011c16bc;
struct FUN_004aa340
{
    int _m0;
    NiTMap<unsigned int, FUN_004aa830*> _m1;
    void RemoveAllEntries();
    ~FUN_004aa340();
};
// @fnv 0x004aa340
FUN_004aa340::~FUN_004aa340()
{
    RemoveAllEntries();
}

void __cdecl operator delete(void*);
struct FUN_004aa650_shell
{
    void FUN_004aa680();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_004aa680, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004aa650
void* FUN_004aa650_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_004aa680();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_004aa720_shell
{
    void AddEntry(int a, int b, int c);
};
// If the pointer stored at c is non-null, calls AddEntry on it with a, b and the value at c+4.
// @fnv 0x004aa6f0
void InvokeIfPresent(int aiArg1, int aiArg2, int apHolder)
{
    int pparam = apHolder;
    if (*(int*)pparam)
    {
        ((FUN_004aa720_shell*)*(int*)pparam)->AddEntry(aiArg1, aiArg2, *(int*)(pparam + 4));
    }
}

struct FUN_004aa830
{
    GO m0;
    int m4;
    SL m8;
    FUN_004aa830();
};
// @fnv 0x004aa830
FUN_004aa830::FUN_004aa830() : m0(0)
{}

namespace fnv_004aa680 {
struct ListX
{
    void RemoveAll();
    ~ListX();
};
struct FUN_004aa680_shell
{
    GO base;
    char pad[4];
    ListX m_kNode;
    ~FUN_004aa680_shell();
};

// Destructor that calls RemoveAll on the embedded list before the object is destroyed.
// @fnv 0x004aa680
FUN_004aa680_shell::~FUN_004aa680_shell()
{
    m_kNode.RemoveAll();
}
}  // namespace fnv_004aa680

// Iterates the map at this+4, calls DestroyIfFlagged(1) on each value, then clears the map with RemoveAll.
// @fnv 0x004aa5d0
void FUN_004aa340::RemoveAllEntries()
{
    void* iter = reinterpret_cast<NiTMap<unsigned int, FUN_004aa830*>*>(reinterpret_cast<unsigned char*>(this) + 4)->GetFirstPos();

    while (iter)
    {
        unsigned int pignore = 0;
        void* value = 0;

        reinterpret_cast<NiTMap<unsigned int, FUN_004aa830*>*>(reinterpret_cast<unsigned char*>(this) + 4)->GetNext(iter, pignore, reinterpret_cast<FUN_004aa830*&>(value));

        UnsignedIntegerRecord* pdata = reinterpret_cast<UnsignedIntegerRecord*>(value);
        UnsignedIntegerRecord* key = pdata;

        key ? reinterpret_cast<FUN_004aa650_shell*>(key)->DestroyIfFlagged(1) : 0;
    }

    reinterpret_cast<NiTMap<unsigned int, FUN_004aa830*>*>(reinterpret_cast<unsigned char*>(this) + 4)->RemoveAll();
}

void* __cdecl operator new(unsigned int);

struct G2
{
    void AddHead(int* p);
};

struct LH
{
    bool IsInList(int& value);
};


struct GO_operator
{
    void operator=(void* value);
};

// Looks up or creates a FUN_004aa830 keyed by a in the map at this+4, sets its key and m4, then adds c to its list at offset 8 if absent.
// @fnv 0x004aa720
void FUN_004aa720_shell::AddEntry(int aiKey, int aiValue, int aiItem)
{
    FUN_004aa830* p;

    if (aiKey && aiItem)
    {
        p = 0;

        if (!reinterpret_cast<NiTMap<unsigned int, FUN_004aa830*>*>(reinterpret_cast<char*>(this) + 4)
                 ->GetAt(static_cast<unsigned int>(aiKey), p) ||
            !p)
        {
            p = new FUN_004aa830;

            reinterpret_cast<NiTMap<unsigned int, FUN_004aa830*>*>(reinterpret_cast<char*>(this) + 4)
                ->SetAt(static_cast<unsigned int>(aiKey), p);

            reinterpret_cast<GO_operator*>(p)->operator=(reinterpret_cast<void*>(aiKey));

            p->m4 = aiValue;
        }

        if (!reinterpret_cast<LH*>(reinterpret_cast<char*>(p) + 8)->IsInList(reinterpret_cast<int&>(aiItem)))
        {
            reinterpret_cast<G2*>(reinterpret_cast<char*>(p) + 8)->AddHead(&aiItem);
        }
    }
}

struct LLD_Cell
{
    NiNode* Get3D_00545cb0();
};

struct GridCell
{
    LLD_Cell* m0;
};

struct GlobalObject_0045cfe0
{
    int* Int();
};

extern TES* g_TES;
extern GlobalObject_0045cfe0 g_011c63cc;

struct FUN_004aabb0_shell : public FUN_004aa3d0_shell
{
    void BGSTextureUseMap_CollectTextureUseDataForLoadedArea(char a1);
};

// If a previous path exists, processes its cell; otherwise iterates the 5x5 grid around half the global int and processes each occupied cell.
// @fnv 0x004aabb0
// src: XBOX_PDB 0x004aabb0
void FUN_004aabb0_shell::BGSTextureUseMap_CollectTextureUseDataForLoadedArea(char a1)
{
    LLD_Cell* inner5;
    unsigned int center3;
    unsigned int grid;
    unsigned int maxValue2;
    unsigned int fTargetUpperBound;
    unsigned int previousPath;
    GridCell* outer;
    LLD_Cell* cell;

    if (g_TES->GetPrevPath())
    {
        inner5 = reinterpret_cast<LLD_Cell*>(g_TES->GetPrevPath());
        this->SetValueAndCall(reinterpret_cast<int>(inner5->Get3D_00545cb0()), reinterpret_cast<int>(inner5), a1);
    }
    else
    {
        maxValue2 = static_cast<unsigned int>(*g_011c63cc.Int()) >> 1;
        grid = maxValue2 - 2;
        center3 = maxValue2 + 2;

        for (previousPath = grid; previousPath <= center3; ++previousPath)
        {
            for (fTargetUpperBound = grid; fTargetUpperBound <= center3; ++fTargetUpperBound)
            {
                outer = g_TES->GetGridCell_00457050(previousPath, fTargetUpperBound);
                if (outer->m0)
                {
                    cell = outer->m0;
                    this->SetValueAndCall(reinterpret_cast<int>(cell->Get3D_00545cb0()), reinterpret_cast<int>(cell), a1);
                }
            }
        }
    }
}

NiAVObject* __cdecl NiDynamicCast(const NiRTTI*, NiAVObject*);
extern int DAT_011f444c;
extern const char str_0101f524[];

struct CastedObj
{
    virtual void vt_00();
    virtual void vt_01();
    virtual void vt_02();
    virtual void vt_03();
    virtual void vt_04();
    virtual void vt_05();
    virtual void vt_06();
    virtual void vt_07();
    virtual void vt_08();
    virtual void vt_09();
    virtual void vt_10();
    virtual void vt_11();
    virtual void vt_12();
    virtual void vt_13();
    virtual void vt_14();
    virtual void vt_15();
    virtual void vt_16();
    virtual void vt_17();
    virtual void vt_18();
    virtual void vt_19();
    virtual void vt_20();
    virtual void vt_21();
    virtual void vt_22();
    virtual void vt_23();
    virtual void vt_24();
    virtual void vt_25();
    virtual void vt_26();
    virtual void vt_27();
    virtual void vt_28();
    virtual void vt_29();
    virtual void vt_30();
    virtual void vt_31();
    virtual void vt_32();
    virtual void vt_33();
    virtual void vt_34();
    virtual void vt_35();
    virtual void vt_36();
    virtual void vt_37();
    virtual void vt_38();
    virtual BSFadeNode* vt_9c();
};
struct ElemObj
{
    virtual void vt_00();
    virtual void vt_01();
    virtual void vt_02();
    virtual void vt_03();
    virtual void vt_04();
    virtual void vt_05();
    virtual void vt_06();
    virtual void vt_07();
    virtual void vt_08();
    virtual void vt_09();
    virtual void vt_10();
    virtual void vt_11();
    virtual void vt_12();
    virtual void vt_13();
    virtual void vt_14();
    virtual void vt_15();
    virtual void vt_16();
    virtual void vt_17();
    virtual void vt_18();
    virtual void vt_19();
    virtual void vt_20();
    virtual void vt_21();
    virtual void vt_22();
    virtual void vt_23();
    virtual void vt_24();
    virtual void vt_25();
    virtual void vt_26();
    virtual void vt_27();
    virtual void vt_28();
    virtual void vt_29();
    virtual void vt_30();
    virtual void vt_31();
    virtual void vt_32();
    virtual void vt_33();
    virtual void vt_34();
    virtual void vt_35();
    virtual void vt_36();
    virtual void vt_37();
    virtual void vt_38();
    virtual void vt_39();
    virtual void vt_40();
    virtual void vt_41();
    virtual void vt_42();
    virtual void vt_43();
    virtual void vt_44();
    virtual void vt_45();
    virtual void vt_46();
    virtual void vt_47();
    virtual void vt_48();
    virtual void vt_49();
    virtual void vt_50();
    virtual void vt_51();
    virtual void vt_52();
    virtual void vt_53();
    virtual void vt_54();
    virtual void vt_55();
    virtual void vt_56();
    virtual void vt_57();
    virtual void vt_58();
    virtual void vt_59();
    virtual void vt_60();
    virtual void vt_61();
    virtual void vt_62();
    virtual void vt_63();
    virtual void vt_64();
    virtual void vt_65();
    virtual void vt_66();
    virtual void vt_67();
    virtual void vt_68();
    virtual void vt_69();
    virtual void vt_70();
    virtual void vt_71();
    virtual void vt_72();
    virtual void vt_73();
    virtual void vt_74();
    virtual void vt_75();
    virtual const char* vt_130();
};
struct TESForm_Proxy40e30
{
    const char* TESForm_GetFormTypeString();
};
struct RefObj
{
    unsigned int _ref_0084e3a0();
};
struct TESRegionData;
template <class T> struct TextureUserList
{
    T* data;
    TextureUserList* next;
    bool FUN_008256d0();
    T& GetItem();
    TextureUserList* GetNext();
    unsigned int ItemsInList();
};
int __cdecl BSStringT_char_SPrintF(StrMem*, const char*, ...);
struct TexUseMap
{
    unsigned int m1;
    NiTMap<unsigned int, FUN_004aa830*> m_kEntryMap;
    bool BGSTextureUseMap_WriteToFile(const char* name);
};
// @fnv 0x004aa900
// src: XBOX_PDB 0x004aa900
bool TexUseMap::BGSTextureUseMap_WriteToFile(const char* apFileName)
{
    bool result5 = false;
    BSFile file9(apFileName, true, 0x400, true);
    if (file9.FUN_00aff300(false, false))
    {
        result5 = true;
        void* posVal = m_kEntryMap.GetFirstPos();
        while (posVal)
        {
            unsigned int key5 = 0;
            void* value9 = 0;
            m_kEntryMap.GetNext(posVal, key5, reinterpret_cast<FUN_004aa830*&>(value9));
            CastedObj* casted9 = (CastedObj*)NiDynamicCast((const NiRTTI*)&DAT_011f444c, (NiAVObject*)key5);
            if (casted9 && value9)
            {
                StrMem str5;
                BSStringT_char_SPrintF(&str5, "%s\t%d bytes\t%i users\r\n", casted9->vt_9c()->FUN_0043b1b0(),
                             ((UnsignedIntegerRecord*)value9)->m_ulSecondValue,
                             ((TextureUserList<TESRegionData*>*)((char*)value9 + 8))->ItemsInList());
                file9.BSFile_Write_00affbb0(&str5, 1);
                TextureUserList<TESRegionData*>* listA = (TextureUserList<TESRegionData*>*)((char*)value9 + 8);
                while (listA && !listA->FUN_008256d0())
                {
                    TESRegionData* elem9 = listA->GetItem();
                    listA = listA->GetNext();
                    BSStringT_char_SPrintF(&str5, str_0101f524, ((TESForm_Proxy40e30*)elem9)->TESForm_GetFormTypeString(),
                                 ((ElemObj*)elem9)->vt_130(), ((RefObj*)elem9)->_ref_0084e3a0());
                    file9.BSFile_Write_00affbb0(&str5, 1);
                }
                BSStringT_char_SPrintF(&str5, "\r\n");
                file9.BSFile_Write_00affbb0(&str5, 1);
            }
        }
        file9.FUN_00affd10();
    }
    return result5;
}

class TESForm;
namespace fnv_004aa3d0 {
struct WalkRef;

struct FormTypeHolder
{
    int GetFormType();
};
struct WalkRef
{
    FormTypeHolder* GetBase();
    bool IsDisabledRef();
};
struct WalkProperty
{
    virtual void v00();
    unsigned int GetTypeTag();
};
typedef void (*WalkCallback)(int a, int b, int c);
struct WalkTexProperty : WalkProperty
{
};
struct WalkTexVT
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
    virtual void ForEachTexture(WalkCallback cb, void* ctx);
    unsigned int GetTypeTag();
};
struct WalkGeometry
{
    WalkTexVT* GetProperty(unsigned int idx);
};
struct WalkRefMap
{
    bool GetAt(WalkRef* key, bool* out);
};
extern WalkRefMap* g_walkRefMap;
extern WalkRef* g_walkCurrentRef;

void InvokeIfPresent(int a, int b, int c);

struct WalkCtx
{
    void* owner;
    int value;
};

struct TextureWalker
{
    int m0;
    void BGSTextureUseMap_CollectTexUseDataRecursive(NiAVObject* obj, bool b);
};

// Recursively walks a NiAVObject tree, tracking the current WalkRef from fade nodes and invoking a texture callback on geometry properties.
// @fnv 0x004aa3d0
// src: XBOX_PDB 0x004aa3d0
void TextureWalker::BGSTextureUseMap_CollectTexUseDataRecursive(NiAVObject* obj, bool b)
{
    if (obj && !obj->IsCulledFlag())
    {
        NiNode* node = obj->IsSceneNode();
        if (node)
        {
            bool bSkip = false;
            bool bSet = false;
            BSFadeNode* fade = 0;
            if (node->IsFadeNode())
                fade = (BSFadeNode*)node;
            if (fade)
            {
                WalkRef* ref = reinterpret_cast<WalkRef*>(fade->QUserData());
                if (g_walkRefMap)
                    g_walkRefMap->GetAt(ref, &bSkip);
                if (ref && !bSkip)
                {
                    bool bType = false;
                    switch (ref->GetBase()->GetFormType())
                    {
                    case 0x2a:
                    case 0x2b:
                    case 0x2c:
                    case 0x2d:
                        bType = true;
                    }
                    if (bType && !b || ref->IsDisabledRef())
                        return;
                    bSet = true;
                    g_walkCurrentRef = ref;
                }
            }
            if (!bSkip)
            {
                unsigned int count = node->FUN_0043b480();
                for (unsigned int i = 0; i < count; i++)
                {
                    NiAVObject* child = node->FUN_0043b4a0(i);
                    BGSTextureUseMap_CollectTexUseDataRecursive(child, b);
                }
            }
            if (bSet)
                g_walkCurrentRef = 0;
        }
        else
        {
            WalkGeometry* geom = reinterpret_cast<WalkGeometry*>(obj->IsGeometry());
            if (geom)
            {
                WalkTexVT* pProp = geom->GetProperty(3);
                WalkTexVT* tex = !pProp ? 0 : (pProp->GetTypeTag() != -1 ? pProp : 0);
                if (tex)
                {
                    WalkCtx ctx;
                    ctx.owner = this;
                    ctx.value = g_walkCurrentRef ? (int)g_walkCurrentRef : m0;
                    tex->ForEachTexture(InvokeIfPresent, &ctx);
                }
            }
        }
    }
}
}  // namespace fnv_004aa3d0
