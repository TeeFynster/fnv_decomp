// fallout_shared/bgsidlecollection.cpp: BGSIdleCollection (14 functions)

#include "../../include/BGSIdleCollection.h"
#include "../../include/Actor.h"
#include "../../include/TESIdleForm.h"
#include "../../include/TESObjectANIO.h"
#include "bgsidlecollection_decls.h"

// @fnv 0x004797e0
void BGSIdleCollection::InitializeComponent()
{
    m_ucIdleCount = 0;
    m_ucPickType = 0;
    m_ppIdleForms = 0;
    m_fIdleChance = 0.0f;
}

// Resolves each stored form ID to a TESObjectANIO idle, keeps valid idles, and warns and removes entries that are missing or lack an animation.
// @fnv 0x00479b00
void BGSIdleCollection::InitItem(TESForm* form)
{
    TESObjectANIO* idle;

    idle = 0;
    for (unsigned int index = 0; index < m_ucPickType; ++index)
    {
        unsigned int formID;
        formID = reinterpret_cast<unsigned int>(m_ppIdleForms[index]);
        TESForm::RemapFormIDForFile(formID, form->GetFile(-1));
        idle = dynamic_cast<TESObjectANIO*>(TESFormInitFlag::GetFormByID(formID));
        if (idle)
        {
            if (reinterpret_cast<TESIdleForm*>(idle)->IsIdleFile())
            {
                m_ppIdleForms[index] = reinterpret_cast<TESIdleForm*>(idle);
            }
            else
            {
                Warning(kBGSIdleCollectionMissingAnim, reinterpret_cast<TESIdleForm*>(idle)->GetName(), form->GetName(),
                        form->GetFormID());
                RemoveIdleEntry(index);
                --index;
            }
        }
        else
        {
            Warning(kBGSIdleCollectionMissingIdle, formID, form->GetName(), form->GetFormID());
            RemoveIdleEntry(index);
            --index;
        }
    }
}

// @fnv 0x00479c40
void BGSIdleCollection::Load(TESFile* file)
{
    int chunk = file->GetChunkID();
    if (FUN_00479e20(chunk))
    {
        switch (chunk)
        {
        case 0x464c4449:
            file->GetChunkData(&m_ucIdleCount, 1);
            break;
        case 0x434c4449:
            if (file->GetChunkSize() == 1)
                file->GetChunkData(&m_ucPickType, 1);
            else
            {
                unsigned int count = 0;
                file->GetChunkData(&count);
                m_ucPickType = (unsigned char)count;
            }
            if (m_ucPickType)
            {
                if (m_ppIdleForms)
                    delete[] m_ppIdleForms;
                m_ppIdleForms = new TESIdleForm*[m_ucPickType];
                memset(m_ppIdleForms, 0, m_ucPickType * 4);
            }
            break;
        case 0x414c4449:
            if (m_ppIdleForms)
            {
                unsigned int size = m_ucPickType * 4;
                if (file->GetChunkSize() == size)
                {
                    file->GetChunkData(m_ppIdleForms, size);
                    if (file->IsEndianConversionRequired())
                        for (int i = 0; i < m_ucPickType; ++i)
                            BSEndian(reinterpret_cast<unsigned int*>(&m_ppIdleForms[i]), EndianSizeTag<4>());
                }
            }
            break;
        case 0x544c4449:
            file->GetChunkData(reinterpret_cast<unsigned int*>(&m_fIdleChance));
            break;
        }
    }
}

// @fnv 0x0047a030
unsigned int BGSIdleCollection::GetAvailableIdles(Actor* actor, TESObjectREFR* target,
                                                  BSSimpleArray<TESIdleForm*, 1024>* idles)
{
    unsigned int count = 0;
    if (actor)
    {
        unsigned int size = 0;
        if (idles)
            size = idles->GetSize();
        for (int i = 0; i < m_ucPickType; ++i)
        {
            TESIdleForm* idle = m_ppIdleForms[i];
            if (idle && actor->HasIdleInFormArray(idle) &&
                idle->IsValidForReferences(reinterpret_cast<TESObjectREFR*>(actor), target, true))
            {
                if (idles)
                {
                    if (count < size)
                        idles->SetAt(count, idle);
                    else
                        idles->Add(idle);
                }
                ++count;
            }
        }
    }
    return count;
}

// Returns true if chunk matches one of six IDLE-family chunk IDs, otherwise false.
// @fnv 0x00479e20
bool IsIdleCollectionChunk(int chunk)
{
    switch (chunk)
    {
    case 0x464c4449:
    case 0x414c4449:
    case 0x424c4449:
    case 0x434c4449:
    case 0x4e4c4449:
    case 0x544c4449:
        return true;
    default:
        return false;
    }
}

// @fnv 0x00479e80
int BGSIdleCollection::GetPickType()
{
    if (m_ucIdleCount & 1)
        return 1;
    return 0;
}

// @fnv 0x00479790
BGSIdleCollection::BGSIdleCollection()
{
    InitializeComponent();
}

struct Arr
{
    unsigned int* GetAt(int);
};
struct SArgs
{
    int i;
    unsigned int* v;
};
// Stores the value pointed to by a.v into the element of self at index a.i.
// @fnv 0x0047a110
// src: XBOX_PDB 0x0047a110
void __fastcall BSSimpleArray_TESAmmo_1024_SetAt(Arr* self, SArgs aArgs)
{
    *self->GetAt(aArgs.i) = *aArgs.v;
}

// @fnv 0x004797c0
BGSIdleCollection::~BGSIdleCollection()
{
    BGSIdleCollection::Free();
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

// @fnv 0x00479930
bool __thiscall BGSIdleCollection::CompareWithBase(BaseFormComponent* other)
{
    BGSIdleCollection* idle = dynamic_cast<BGSIdleCollection*>(other);
    if (!idle)
        return true;
    if (m_ucIdleCount != idle->m_ucIdleCount)
        return true;
    if (m_ucPickType != idle->m_ucPickType)
        return true;
    if (m_fIdleChance != idle->m_fIdleChance)
        return true;
    if (m_ppIdleForms && idle->m_ppIdleForms &&
        memcmp(m_ppIdleForms, idle->m_ppIdleForms,
               m_ucPickType * 4))
        return true;
    return false;
}

void __cdecl _Deallocate(void*);
// @fnv 0x00479810
void BGSIdleCollection::Free()
{
    void* idleArray = m_ppIdleForms;
    _Deallocate(idleArray);
    m_ucPickType = 0;
    m_ppIdleForms = 0;
}

struct _DeallocateHelper
{
    static void _Deallocate(void*);
};
struct __memcpyHelper
{
    static void __memcpy(void*, const void*, unsigned int);
};
// Copies the idle count, reallocates and copies the idle form array from apCopyFC, and copies the extra field.
// @fnv 0x00479850
void BGSIdleCollection::CopyFromBase(BaseFormComponent* apCopyFC)
{
    BGSIdleCollection* pSource = dynamic_cast<BGSIdleCollection*>(apCopyFC);
    if (!pSource)
        return;
    m_ucIdleCount = pSource->m_ucIdleCount;
    {
        TESIdleForm** pOld = m_ppIdleForms;
        _DeallocateHelper::_Deallocate(pOld);
    }
    m_ppIdleForms = 0;
    m_ucPickType = 0;
    if (pSource->m_ucPickType)
    {
        m_ppIdleForms = new TESIdleForm*[pSource->m_ucPickType];
        __memcpyHelper::__memcpy(m_ppIdleForms, pSource->m_ppIdleForms, pSource->m_ucPickType * 4);
        m_ucPickType = pSource->m_ucPickType;
    }
    m_fIdleChance = pSource->m_fIdleChance;
}

void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl _FUN_00485910(unsigned int, float);
void __cdecl _FUN_00485710(unsigned int, unsigned int*, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);

// @fnv 0x004799f0
void __fastcall SaveIdleCollection(BGSIdleCollection* self)
{
    unsigned int isize3;
    unsigned int* parray;
    unsigned int i;

    if (self->m_ucPickType)
    {
        TESForm_AddChunk_3(0x464c4449, self->m_ucIdleCount);
        TESForm_AddChunk_3(0x434c4449, self->m_ucPickType);
        _FUN_00485910(0x544c4449, self->m_fIdleChance);

        isize3 = self->m_ucPickType << 2;
        parray = (unsigned int*)_alloca(isize3);

        for (i = 0; i < self->m_ucPickType; i++)
        {
            if (self->m_ppIdleForms[i] != 0)
                parray[i] = self->m_ppIdleForms[i]->GetFormID();
            else
                parray[i] = 0;
        }

        _FUN_00485710(0x414c4449, parray, self->m_ucPickType);
    }
}

void* __memcpy(void* dst, const void* src, unsigned int size);

// Removes the element at index from the array, shrinking the count and reallocating the array without that element.
// @fnv 0x00479ea0
void BGSIdleCollection::RemoveIdleEntry(unsigned int index)
{
    if (index < m_ucPickType)
    {
        if (m_ucPickType == 1)
        {
            m_ucPickType = 0;
            delete m_ppIdleForms;
            m_ppIdleForms = 0;
        }
        else
        {
            m_ucPickType--;
            int n;
            TESIdleForm** newArrayA = new TESIdleForm*[m_ucPickType];
            n = index;
            if (n > 0)
            {
                __memcpy(newArrayA, m_ppIdleForms, n * 4);
            }
            n = m_ucPickType - index;
            if (n > 0)
            {
                __memcpy(&newArrayA[index], &m_ppIdleForms[index + 1], n * 4);
            }
            delete m_ppIdleForms;
            m_ppIdleForms = newArrayA;
        }
    }
}
