// fallout_shared/tesmodeltextureswap.cpp: TESModelTextureSwap, NiFixedString, TESModel, DistantTreeTextureInfo (23 functions)

#include "tesmodeltextureswap_decls.h"
#include "../../include/BGSDistantTreeBlock.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/BGSEquipType.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESFullName.h"
#include "../../include/TESIcon.h"
#include "../../include/TESTexture.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESWeightForm.h"

// Deletes every entry in the list by taking the head item, removing it, and freeing it, until the list is empty.
// @fnv 0x0048ade0
void TESModelTextureSwap::ClearTextureSwaps()
{
    void* pDelete;
    BGSPerkEntry* pItem;
    while (!reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(&textureList)->IsEmpty())
    {
        pItem = reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&textureList)->GetItem();
        reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(&textureList)->RemoveHead();
        pDelete = pItem;
        ::operator delete(pDelete);
    }
}

// Resolves each texture-swap entry's formID to a BGSTextureSet, warns and removes entries that fail to resolve.
// @fnv 0x0048aa80
void TESModelTextureSwap::InitItem(TESForm* form)
{
    struct InitItemLocals
    {
        unsigned int formID;
        DistantTreeTextureInfo* swap;
        BSSimpleList<PerkButtonEntry*>* list;
    } locals;

    BSSimpleList<PerkButtonEntry*>* previous;

    locals.list =
        reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(reinterpret_cast<TESAIForm*>(this)->GetPackageList());
    previous = 0;
    while (locals.list && !locals.list->IsEmpty())
    {
        locals.swap = reinterpret_cast<DistantTreeTextureInfo*>(
            reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(locals.list)->GetItem());
        locals.formID = locals.swap->formID;
        TESForm::RemapFormIDForFile(locals.formID, form->GetFile(-1));
        locals.swap->formID =
            reinterpret_cast<unsigned int>(dynamic_cast<BGSTextureSet*>(TESForm::GetFormByID(locals.formID)));
        if (!locals.swap->formID)
        {
            Warning(kModelTextureSwapInitWarning, locals.formID, form->GetName(), form->GetFormID());
            if (previous)
            {
                reinterpret_cast<BSSimpleList<TESGrass*>*>(previous)->Remove(reinterpret_cast<TESGrass*&>(locals.swap));
                locals.list = reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(previous)->GetNext());
            }
            else
            {
                locals.list->RemoveHead();
            }
            delete locals.swap;
        }
        else
        {
            previous = locals.list;
            locals.list = reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(
                reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(locals.list)->GetNext());
        }
    }
}

// @fnv 0x0048b130
bool TESModelTextureSwap::ApplyTextureSwapToNode(NiAVObject* object, BSMap<int, DistantTreeTextureInfo*>* apSwapMap,
                                                 int& index)
{
    if (object && apSwapMap)
    {
        NiNode* node = object->IsSceneNode();
        if (node)
        {
            unsigned int count = node->FUN_0043b480();
            for (unsigned int i = 0; i < count; i++)
            {
                NiAVObject* child = node->GetAt(i);
                if (child)
                {
                    if (ApplyTextureSwapToNode(child, apSwapMap, index))
                        return true;
                }
            }
        }
        else if (object->IsGeometry())
        {
            DistantTreeTextureInfo* swap = 0;
            if (reinterpret_cast<NiTPointerMap<unsigned int, TESObjectREFR*>*>(apSwapMap)->GetAt(
                    index, reinterpret_cast<TESObjectREFR*&>(swap)) &&
                swap)
            {
                if (reinterpret_cast<BGSTextureSet*>(swap->formID) == BGSTextureSet::GetEmptyTextureSet())
                    reinterpret_cast<NiGeometry*>(object)->SetAppCulled(true);
                else
                {
                    NiProperty* property = object->GetProperty(3);
                    if (BSShaderPPLightingProperty* shader = static_cast<BSShaderPPLightingProperty*>(
                            (!property ? false
                                       : (static_cast<int>(
                                              reinterpret_cast<BGSDehydrationStage*>(property)->FUN_00441110()) >= 8 &&
                                          static_cast<int>(
                                              reinterpret_cast<BGSDehydrationStage*>(property)->FUN_00441110()) <= 12))
                                ? property
                                : 0))
                    {
                        BSShaderTextureSet* textureSet =
                            reinterpret_cast<BGSTextureSet*>(swap->formID)->BuildShaderTextureSet();
                        shader->SetTextureSet(textureSet);
                        shader->BuildShaderTextureSet(0, 0);
                        // The shared shader header does not yet expose virtual slot 0x108.
                        reinterpret_cast<void (__thiscall *)(BSShaderPPLightingProperty*)>((*reinterpret_cast<void***>(shader))[0x108 / 4])(shader);
                    }
                }
                reinterpret_cast<NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int,
                                            CombatThreatRecord*>*>(apSwapMap)
                    ->RemoveAt(index);
                if (!reinterpret_cast<TESForm*>(apSwapMap)->GetFormID())
                    return true;
            }
            index++;
        }
    }
    return false;
}

// @fnv 0x0048afe0
void TESModelTextureSwap::ApplyTextureSwaps(NiAVObject* object)
{
    int warningCount;
    if (object)
    {
        warningCount = Warning();
        SetWarningState(true);
        BSMapBase<int, DistantTreeTextureInfo*> swapMap(37);
        {
            BSSimpleList<PerkButtonEntry*>* list =
                reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(reinterpret_cast<TESAIForm*>(this)->GetPackageList());
            while (list && !list->IsEmpty())
            {
                DistantTreeTextureInfo* swap = reinterpret_cast<DistantTreeTextureInfo*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(list)->GetItem());
                list = reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(list)->GetNext());
                if (swap->index != -1)
                    reinterpret_cast<BSMapBase<unsigned int, BGSDistantTreeBlock::InstanceData*>*>(&swapMap)->SetAt(
                        swap->index, reinterpret_cast<BGSDistantTreeBlock::InstanceData*>(swap));
                else
                    Warning("Found invalid swap index.");
            }
        }
        if (reinterpret_cast<TESForm*>(&swapMap)->GetFormID())
        {
            int index = 0;
            ApplyTextureSwapToNode(object, reinterpret_cast<BSMap<int, DistantTreeTextureInfo*>*>(&swapMap), index);
            if (reinterpret_cast<TESForm*>(&swapMap)->GetFormID())
                Warning("Not all texture swaps were performed.");
        }
        SetWarningState(false);
        if (warningCount != Warning())
            Warning(
                "Warnings were encountered during texture swap for model '%s'. Check warnings file for more information.",
                GetModelFilePath());
    }
}

// @fnv 0x0048a990
void TESModelTextureSwap::ReadTextureSwapChunk(TESModelTextureSwap* model, TESFile* file)
{
    if (!file || !model)
        return;
    int chunk = file->GetChunkID();
    switch (chunk)
    {
    case 0x53324f4d:
    case 0x53334f4d:
    case 0x53344f4d:
    case 0x53444f4d: {
        struct ChunkBuffer
        {
            unsigned int size;
            char* data;
        } buffer;
        buffer.size = file->GetChunkSize();
        buffer.data = static_cast<char*>(_alloca(buffer.size));
        file->GetChunkData(buffer.data, buffer.size);
        model->ParseTextureSwapData(buffer.data, buffer.size,
                                    file->GetFormVersion());
    }
    break;
    default:
        if (FUN_00489280(chunk))
            TESModel::LoadModelData(reinterpret_cast<TESModel*>(model), file);
        break;
    }
}

// @fnv 0x004892d0
void TESModel::LoadModelData(TESModel* model, TESFile* file)
{
    if (!file || !model)
        return;
    int chunk = file->GetChunkID();
    switch (chunk)
    {
    case 0x4c444f4d:
    case 0x4d414e50: {
        char* data = static_cast<char*>(_alloca(file->GetChunkSize()));
        file->GetChunkData(data, 0);
        model->SetModelFilePath(data);
    }
    break;
    case 0x54444f4d:
        LoadTextureSwapData(model, file);
        break;
    case 0x44444f4d:
    case 0x44534f4d: {
        unsigned char flags;
        file->GetChunkData(&flags, 1);
        model->FUN_004893c0(flags);
    }
    break;
    }
}

// @fnv 0x0048ae30
void TESModelTextureSwap::AddTexSwap(const char* name, int index, BGSTextureSet* textureSet)
{
    if (name && textureSet)
    {
        DistantTreeTextureInfo* swap = GetTexSwap(index);
        if (!swap)
        {
            swap = new DistantTreeTextureInfo;
            TaskQueueInterface::CopyStringToBuffer(swap->objectName, 128, name);
            swap->index = index;
            reinterpret_cast<BSSimpleList<SpellItem*>*>(&textureList)
                ->AddHead(reinterpret_cast<SpellItem*&>(swap));
        }
        swap->formID = reinterpret_cast<unsigned int>(textureSet);
    }
}

// Walks the package list and returns the entry whose index matches the given index, or null if index is -1 or no match is found.
// @fnv 0x0048ad70
DistantTreeTextureInfo* TESModelTextureSwap::GetTexSwap(int index)
{
    DistantTreeTextureInfo* result = 0;
    if (index != -1)
    {
        BSSimpleList<PerkButtonEntry*>* list =
            reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(reinterpret_cast<TESAIForm*>(this)->GetPackageList());
        while (list && !list->IsEmpty())
        {
            if (index == reinterpret_cast<DistantTreeTextureInfo*>(
                             reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(list)->GetItem())
                             ->index)
            {
                result = reinterpret_cast<DistantTreeTextureInfo*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(list)->GetItem());
                break;
            }
            list = reinterpret_cast<BSSimpleList<PerkButtonEntry*>*>(
                reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(list)->GetNext());
        }
    }
    return result;
}

// Initializes formID to 0, index to -1, and clears the first character of objectName.
// @fnv 0x0048af10
DistantTreeTextureInfo::DistantTreeTextureInfo()
{
    formID = 0;
    index = -1;
    objectName[0] = 0;
}

// Copy constructor: retains the other string handle, then copies it.
// @fnv 0x0048af40
NiFixedString::NiFixedString(const NiFixedString& other)
{
    FUN_0043ba60(other);
    m_kHandle = other.m_kHandle;
}

// @fnv 0x0048af70
int NiFixedString::IsNotEmpty() const
{
    return m_kHandle != EmptyFS.m_kHandle;
}

// @fnv 0x0048b2f0
void BSShaderPPLightingProperty::SetTextureSet(BSTextureSet* apTextureSet)
{
    *reinterpret_cast<NiPointer<NiNode>*>(&spTextureSet) = reinterpret_cast<NiNode*>(apTextureSet);
}

extern "C" int __cdecl _NiStricmp(const char*, const char*);

struct FUN_0048af90_shell
{
    const char* m_str;
    bool Equals(const char* a1);
};

// Returns true if m_str and a1 are the same pointer, false if either is null, otherwise compares them case-insensitively with _NiStricmp.
// @fnv 0x0048af90
bool FUN_0048af90_shell::Equals(const char* apOther)
{
    if (m_str == apOther)
        return true;
    if (apOther == 0 || m_str == 0)
        return false;
    return _NiStricmp(m_str, apOther) == 0;
}

struct FUN_00409aa0_shell
{
    void FUN_00409aa0(unsigned int flags, bool set);
};

// Sets or clears the given flag bits in the byte at offset 0xa0 of this object.
// @fnv 0x00409aa0
void FUN_00409aa0_shell::FUN_00409aa0(unsigned int flags, bool set)
{
    set ? ((unsigned char*)this)[0xa0] |= flags : ((unsigned char*)this)[0xa0] &= ~flags;
}

struct BipedAnim;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESWaterForm;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
typedef char _sizecheck_BGSMessageIcon[sizeof(BGSMessageIcon) == 16 ? 1 : -1];
typedef char _sizecheck_TESScriptableForm[sizeof(TESScriptableForm) == 12 ? 1 : -1];
typedef char _sizecheck_TESWeightForm[sizeof(TESWeightForm) == 8 ? 1 : -1];
typedef char _sizecheck_BGSEquipType[sizeof(BGSEquipType) == 8 ? 1 : -1];

// @fnv 0x0048a470
void TESModelTextureSwap::InitializeComponent()
{
    TESModel::InitializeComponent();
}

// @fnv 0x0048a500
void TESModelTextureSwap::Free()
{
    ClearTextureSwaps();
    TESModel::Free();
}

void* __cdecl __memcpy(void*, const void*, unsigned int);
// Reads a count-prefixed list of texture swaps (name, texture pointer, optional geometry index) from a buffer and adds each valid entry via AddTexSwap.
// @fnv 0x0048a7b0
bool TESModelTextureSwap::ParseTextureSwapData(void* apData, unsigned int aiDataSize, unsigned int aiVersion)
{
    unsigned int uiRemaining;
    unsigned char* pdata;
    unsigned int ireadsize;
    if (apData && aiDataSize > 4)
    {
        pdata = (unsigned char*)apData;
        uiRemaining = *(unsigned int*)pdata;
        ireadsize = 4;
        pdata += ireadsize;
        aiDataSize -= ireadsize;
        while (uiRemaining)
        {
            uiRemaining--;
            unsigned int uiNameLength = 0;
            BGSTextureSet* pnewtexture = 0;
            int igeomindex = -1;
            char acName[260];
            acName[0] = 0;
            ireadsize = 4;
            if (ireadsize <= aiDataSize)
            {
                uiNameLength = *(unsigned int*)pdata;
                pdata += ireadsize;
                aiDataSize -= ireadsize;
            }
            else
            {
                return false;
            }
            ireadsize = uiNameLength;
            if (ireadsize <= aiDataSize && ireadsize < 0x104)
            {
                __memcpy(acName, pdata, uiNameLength);
                acName[uiNameLength] = 0;
                pdata += ireadsize;
                aiDataSize -= ireadsize;
            }
            else
            {
                return false;
            }
            ireadsize = 4;
            if (ireadsize <= aiDataSize)
            {
                unsigned int uiTexturePtr = *(unsigned int*)pdata;
                pdata += ireadsize;
                aiDataSize -= ireadsize;
                pnewtexture = (BGSTextureSet*)uiTexturePtr;
            }
            else
            {
                return false;
            }
            if (aiVersion >= 15)
            {
                ireadsize = 4;
                if (ireadsize <= aiDataSize)
                {
                    igeomindex = *(int*)pdata;
                    pdata += ireadsize;
                    aiDataSize -= ireadsize;
                }
                else
                {
                    return false;
                }
            }
            if (acName[0] && pnewtexture)
                AddTexSwap(acName, igeomindex, pnewtexture);
        }
    }
    return true;
}

void __cdecl AppendChunk(unsigned int, unsigned int, unsigned int);
void __cdecl Deallocate(void*);

// Calls WriteToBuffer with a and b, then if SerializeList yields a data pointer and size, passes them with c to AppendChunk and deallocates the pointer.
// @fnv 0x0048a520
void TESModelTextureSwap::ProcessAndFreeData(unsigned int uiFirst, unsigned int uiSecond, unsigned int uiThird)
{
    WriteToBuffer(uiFirst, uiSecond);
    unsigned int pdata = 0;
    unsigned int idatasize = 0;
    if (SerializeList(reinterpret_cast<char**>(&pdata), &idatasize))
    {
        AppendChunk(uiThird, pdata, idatasize);
        Deallocate((void*)pdata);
    }
}

// @fnv 0x0048a490
TESModelTextureSwap::~TESModelTextureSwap()
{
    Free();
}

extern "C" char DAT_01183040;
extern "C" char DAT_011831c4;
void* __cdecl FUN_00ec43fb(unsigned int, int, const void*, const void*, int);
struct TextureSwapRecord
{
    unsigned int formID;
    int index;
    char objectName[128];
};
struct TextureSwapNode
{
    unsigned char FUN_008256d0();
    TextureSwapRecord** FUN_006815c0();
    TextureSwapNode* FUN_00726070();
};
struct TextureSwapNodeAccessor
{
    TextureSwapNode* FUN_00500940();
};

// Looks up a texture swap list for formID, then for each node applies its record's objectName, index and formID via FUN_0048ae30.
// @fnv 0x0048aba0
void TESModelTextureSwap::ApplyTextureSwapOverrides(unsigned int formID)
{
    TESModel::BaseFormRecord(reinterpret_cast<BaseFormComponent*>(formID));
    struct TextureSwapNodeAccessor* list =
        static_cast<struct TextureSwapNodeAccessor*>(FUN_00ec43fb(formID, 0, &DAT_01183040, &DAT_011831c4, 0));
    if (!list)
        return;
    ClearTextureSwaps();
    TextureSwapNode* node = list->FUN_00500940();
    while (node && !node->FUN_008256d0())
    {
        TextureSwapRecord* record = *node->FUN_006815c0();
        AddTexSwap(record->objectName, record->index, reinterpret_cast<BGSTextureSet*>(record->formID));
        node = node->FUN_00726070();
    }
}

struct TextureSwapListHead
{
    TextureSwapNode* FUN_00500940();
};
struct TextureSwapCount
{
    int GetSize();
};
int FUN_00404dc0(const char*, const char*);

// @fnv 0x0048ac40
bool TESModelTextureSwap::CompareTextureSwaps(BaseFormComponent* other)
{
    if (TESModel::CompareWithBase(other))
        return true;
    TESModelTextureSwap* pOther = dynamic_cast<TESModelTextureSwap*>(other);
    if (!pOther)
        return true;
    if (((TextureSwapCount*)((TextureSwapListHead*)pOther)->FUN_00500940())->GetSize() !=
        ((TextureSwapCount*)((TextureSwapListHead*)this)->FUN_00500940())->GetSize())
        return true;
    TextureSwapNode* pNode = ((TextureSwapListHead*)pOther)->FUN_00500940();
    while (pNode && !pNode->FUN_008256d0())
    {
        TextureSwapRecord* pSwap = *pNode->FUN_006815c0();
        TextureSwapRecord* pMine = reinterpret_cast<TextureSwapRecord*>(GetTexSwap(pSwap->index));
        if (!pMine)
            return true;
        if (pMine->formID != pSwap->formID)
            return true;
        if (pMine->objectName[0] && pSwap->objectName[0] && FUN_00404dc0(pMine->objectName, pSwap->objectName))
            return true;
        pNode = pNode->FUN_00726070();
    }
    return false;
}

class TextureSwapSerializationNode
{
  public:
    bool FUN_008256d0();
    unsigned int* FUN_006815c0();
    TextureSwapSerializationNode* FUN_00726070();
};

class ObjectRef
{
  public:
    int FUN_0084e3a0();
};

char* __cdecl FormHeap_Allocate(unsigned int);
unsigned int __cdecl FUN_0044a670(unsigned int);
bool __cdecl FUN_00401500();
struct FUN_00401080_tag
{
};
void __cdecl FUN_00401080(int*, FUN_00401080_tag);
void __cdecl FUN_00401460(char*, unsigned int, unsigned int);

// @fnv 0x0048a590
bool TESModelTextureSwap::SerializeList(char** apBuffer, unsigned int* auiSize)
{
    *apBuffer = 0;
    *auiSize = 0;
    TextureSwapSerializationNode* iT = reinterpret_cast<TextureSwapSerializationNode*>(reinterpret_cast<TESAIForm*>(this)->GetPackageList());
    unsigned int v;
    unsigned int P;
    unsigned int r;
    unsigned int t;
    int count;
    int loA2;
    char* _w;
    if (!iT->FUN_008256d0())
    {
        count = 0;
        *auiSize = 4;
        while (iT != 0 && !iT->FUN_008256d0())
        {
            v = *iT->FUN_006815c0();
            *auiSize += 4;
            *auiSize += FUN_0044a670(v + 8);
            *auiSize += 4;
            *auiSize += 4;
            count++;
            iT = iT->FUN_00726070();
        }
        *apBuffer = FormHeap_Allocate(*auiSize);
        _w = *apBuffer;
        loA2 = count;
        if (FUN_00401500())
        {
            FUN_00401080(&loA2, FUN_00401080_tag());
        }
        *(int*)_w = loA2;
        _w += 4;
        iT = reinterpret_cast<TextureSwapSerializationNode*>(reinterpret_cast<TESAIForm*>(this)->GetPackageList());
        while (iT != 0 && !iT->FUN_008256d0())
        {
            P = *iT->FUN_006815c0();
            r = FUN_0044a670(P + 8);
            if (FUN_00401500())
            {
                FUN_00401080(&loA2, FUN_00401080_tag());
            }
            *(unsigned int*)_w = r;
            _w += 4;
            FUN_00401460(_w, P + 8, r);
            _w += r;
            t = 0;
            if (*(unsigned int*)P != 0)
                t = ((ObjectRef*)*(unsigned int*)P)->FUN_0084e3a0();
            *(unsigned int*)_w = t;
            _w += 4;
            *(unsigned int*)_w = *((unsigned int*)P + 1);
            _w += 4;
            iT = iT->FUN_00726070();
        }
    }
    return *apBuffer != 0;
}

