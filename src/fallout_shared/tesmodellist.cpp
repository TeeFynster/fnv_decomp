// fallout_shared/tesmodellist.cpp: TESModelList, ActorValue, FileEntryListCollection

#include "layout_support.h"
#include "../../include/TESModelList.h"
#include <new>
#include "../../include/ActorValueOwner.h"
#include "../../include/PathingRequest.h"
#include "../../include/SettingT_GameSettingCollection_.h"
#include "../../include/TESActorBaseData.h"

#include "../../include/ActorValue.h"
namespace ActorValue {
bool __cdecl GetFlag(Index index, unsigned int flag);
}


class TESModelListCopyTarget
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual unsigned short vfn_10() = 0;
};


// Deletes every filename string in the list at offset 4, then calls ClearAndDeleteArray on the object at offset 12.
// @fnv 0x00489b40
void TESModelList::ClearComponent()
{
    while (!m_kModelPaths.IsEmpty())
    {
        const char* filenameToDelete;
        const char* filename;
        filenameToDelete = m_kModelPaths.GetItem();
        m_kModelPaths.RemoveHead();
        filename = filenameToDelete;
        ::operator delete((void*)filename);
    }
    reinterpret_cast<FileEntryListCollection*>(m_kModelData)->ClearAndDeleteArray();
}

// @fnv 0x00489ae0
TESModelList::~TESModelList()
{
    ClearComponent();
}

// @fnv 0x005fa180
unsigned int TESModelList::BaseFormRecord(unsigned int type)
{
    unsigned int result = 0;
    if (ActorValue::GetFlag((ActorValue::Index)type, 0x400))
    {
        result = ((TESModelList*)((char*)this - 0x100))->HasModels();
    }
    else
    {
        switch (type)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0x0c))->vfn_10();
            break;
        default:
            result = ((ActorValueOwner*)this)->ActorValueOwner::GetActorValue((ActorValue::Index)type);
            break;
        }
    }
    return result;
}

struct FUN_00478690_shell
{
    void BGSDestructibleObjectForm_RemoveData();
};


// Releases the object stored at offset 4 by calling its virtual method with 1, then sets that pointer to null.
// @fnv 0x00478690
// src: XBOX_PDB 0x00478690
void FUN_00478690_shell::BGSDestructibleObjectForm_RemoveData()
{
    delete *(FileEntryListCollection**)((char*)this + 4);
    *(void**)((char*)this + 4) = 0;
}

class GameSettingCollection;
template <class T> class SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting43;

// Returns the byte at pThis+0x12d, adding the scaled level from the actor base data when it matches the PC level.
// @fnv 0x005f8f70
// src: COMMUNITY 0x005f8f70
unsigned char __fastcall TESCreature_GetCombatSkill(char* pThis)
{
    unsigned char ucLevel = static_cast<unsigned char>(pThis[0x12d]);
    if (reinterpret_cast<TESActorBaseData*>(pThis + 0x30)->GetMatchesPCLevel())
    {
        short slevel = reinterpret_cast<TESActorBaseData*>(pThis + 0x30)->TESActorBaseData_GetLevel();
        if (slevel < 1)
            slevel = 1;
        ucLevel =
            ucLevel +
            static_cast<unsigned char>(
                slevel * reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting43).Float()->f);
    }
    return ucLevel;
}

struct FUN_005fa180_cls : public ActorValueOwner
{
    char pad[0xc - 4];
    int TESCreature_GetActorValueI(ActorValue::Index aeIndex);
};
// @fnv 0x005fa180
// src: COMMUNITY 0x005fa180
int FUN_005fa180_cls::TESCreature_GetActorValueI(ActorValue::Index aeIndex)
{
    int result = 0;
    if (ActorValue::GetFlag(aeIndex, 0x400))
    {
        result = ((TESModelList*)((char*)this - 0x100))->HasModels();
    }
    else
    {
        switch (aeIndex)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0xc))->vfn_10();
            break;
        default:
            result = ActorValueOwner::GetActorValue(aeIndex);
            break;
        }
    }
    return result;
}

// Initializes the model list and its collection storage, then clears the component.
// @fnv 0x00489a60
TESModelList::TESModelList()
{
    // The raw storage is initialized as a list without adding a member destructor.
    reinterpret_cast<BSSimpleList<const char*>*>(m_kModelData)->BSSimpleList<const char*>::BSSimpleList();
    Free();
}

unsigned int __cdecl BSStringLength(const char*);
// @fnv 0x00489ce0
void TESModelList::LoadStringChunk(TESModelList* p1, TESFile* apFile)
{
    if (!apFile || !p1)
        return;
    unsigned int id = apFile->GetChunkID();
    switch (id)
    {
    case 0x5a46494e: {
        char* pChunkBuffer = new char[apFile->GetChunkSize()];
        {
            char* pString = pChunkBuffer;
            apFile->GetChunkData(pChunkBuffer, 0);
            while (*pString)
            {
                AddModel_00489fa0(pString);
                pString += BSStringLength(pString) + 1;
            }
        }
        delete pChunkBuffer;
        break;
    }
    case 0x5446494e:
        reinterpret_cast<FileEntryListCollection*>(m_kModelData)->LoadFromTESFile(p1, apFile);
        break;
    }
}

// Deletes each element of the array at this+4, frees the array, nulls the pointer, and resets the count at this+0 to zero.
// @fnv 0x0048a010
void FileEntryListCollection::ClearAndDeleteArray()
{
    unsigned int i;
    if (m_ppElementArray)
    {
        for (i = 0; i < m_uiFileEntryCount; i++)
            delete m_ppElementArray[i];
        delete m_ppElementArray;
        m_ppElementArray = 0;
    }
    m_uiFileEntryCount = 0;
}

struct FUN_0048a2c0_shell
{
    void TESTextureListArray_Copy(PathingLocation*);
};
// Casts component to TESModelList, copies each filename via FUN_00489fa0, then copies the origin pathing location.
// @fnv 0x00489db0
void TESModelList::BaseFormRecord(BaseFormComponent* component)
{
    TESModelList* source = dynamic_cast<TESModelList*>(component);
    if (!source)
        return;
    Free();
    BSSimpleList<char const*>* list = &source->m_kModelPaths;
    while (list)
    {
        const char* filename = list->GetItem();
        if (filename)
            AddModel_00489fa0(filename);
        list = list->GetNext();
    }
    ((FUN_0048a2c0_shell*)((char*)this + 0xc))->TESTextureListArray_Copy(((PathingRequest*)source)->GetOrigin());
}

struct TaskQueueInterface
{
    static void CopyStringToBuffer(char* dest, unsigned int size, const char* src);
};
struct SoundListView
{
    void AddTail(char* const&);
};
// If the string is not already present, allocates a copy of it, copies the text into it, and appends it to the list at this+4.
// @fnv 0x00489fa0
// src: COMMUNITY 0x00489fa0
void TESModelList::AddModel_00489fa0(const char* apString)
{
    if (!ContainsFile(apString))
    {
        int size = BSStringLength(apString) + 1;
        char* copy = static_cast<char*>(operator new(size));
        char* dest = copy;
        TaskQueueInterface::CopyStringToBuffer(dest, size, apString);
        ((SoundListView*)((char*)this + 4))->AddTail(dest);
    }
}

struct FNV_NodeIter
{
    int* GetItem();
    FNV_NodeIter* GetNext();
};

extern char DAT_01183040;
extern char DAT_01186b14;

void* __cdecl FUN_00ec43fb(unsigned int a, unsigned int b, void* c, void* d, unsigned int e);
int __cdecl BSstricmp(int a, int b);

// Looks up a record via FUN_00ec43fb and walks both node lists, returning true if any pair of entries differs or the lists have different lengths.
// @fnv 0x00489e40
bool TESModelList::CompareWithBase(BaseFormComponent* arg)
{
    char* p = (char*)FUN_00ec43fb(reinterpret_cast<unsigned int>(arg), 0, &DAT_01183040, &DAT_01186b14, 0);
    if (p == 0)
    {
        return true;
    }
    FNV_NodeIter* a = (FNV_NodeIter*)((char*)this + 4);
    FNV_NodeIter* b = (FNV_NodeIter*)(p + 4);
    int y4;
    int x3;
    while (a != 0 && b != 0)
    {
        x3 = *a->GetItem();
        y4 = *b->GetItem();
        if ((x3 == 0 && y4 != 0) || (x3 != 0 && y4 == 0))
        {
            return true;
        }
        else
        {
            if (x3 != 0 && y4 != 0 && BSstricmp(x3, y4) != 0)
            {
                return true;
            }
        }
        a = a->GetNext();
        b = b->GetNext();
    }
    if (a != 0 || b != 0)
    {
        return true;
    }
    return false;
}

int __cdecl BSstricmp(const char* lhs, const char* rhs);

// Returns true if filename is non-null and matches an entry in the model list, otherwise false.
// @fnv 0x00489f20
bool TESModelList::ContainsFile(const char* filename)
{
    if (m_kModelPaths.IsEmpty() || filename == 0)
        return false;

    BSSimpleList<const char*>* entry = &m_kModelPaths;
    while (entry != 0)
    {
        const char* value = entry->GetItem();
        if (value && BSstricmp(value, filename) == 0)
            return true;
        entry = entry->GetNext();
    }

    return false;
}

unsigned int __cdecl BSstrlen(const char* text);
void __cdecl FUN_00406d30(char* destination, unsigned int capacity, const char* source);
void __cdecl TESForm_AddChunkArray(void* destination, char* source, unsigned int length);

// If the model list is non-empty, concatenates its strings into a new buffer, copies it to destination, frees it, then clears the list data.
// @fnv 0x00489ba0
void TESModelList::CopyModelListToBuffer(void* destination, unsigned int flags)
{
    if (!m_kModelPaths.IsEmpty())
    {
        unsigned int iStack_8 = 1;
        BSSimpleList<const char*>* iStack7 = &m_kModelPaths;
        const char* piVar4;
        char* allocResult;
        char* puVar4;
        char* puStack_18;
        unsigned int iStack_c;
        const char* iVarTmp;
        unsigned int count9;
        char* freeBuffer_;

        while (iStack7 != 0)
        {
            piVar4 = iStack7->GetItem();
            if (piVar4 != 0)
                iStack_8 = iStack_8 + BSstrlen(piVar4) + 1;
            iStack7 = iStack7->GetNext();
        }

        allocResult = (char*)::operator new(iStack_8);
        puVar4 = allocResult;
        puStack_18 = puVar4;
        iStack7 = &m_kModelPaths;
        iStack_c = iStack_8;
        while (iStack7 != 0)
        {
            iVarTmp = iStack7->GetItem();
            if (iVarTmp != 0)
            {
                FUN_00406d30(puStack_18, iStack_c, iVarTmp);
                count9 = BSstrlen(iVarTmp) + 1;
                puStack_18 = puStack_18 + count9;
                iStack_c = iStack_c - count9;
            }
            iStack7 = iStack7->GetNext();
        }
        *puStack_18 = 0;
        TESForm_AddChunkArray(destination, puVar4, iStack_8);
        freeBuffer_ = puVar4;
        ::operator delete(freeBuffer_);
    }
    reinterpret_cast<FileEntryListCollection*>(m_kModelData)->ClearData(flags);
}
