
#include "nitmapbase_decls.h"

template<>
// @fnv 0x00a53c30
bool NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*>::GetAt(
    const char* key, NiShader*& data) const
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<const char*, NiShader*>* item = m_ppkHashTable[index];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            data = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template<>
// @fnv 0x00b63170
bool NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>::GetAt(
    NiObject* key, bool& data) const
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<NiObject*, bool>* item = m_ppkHashTable[index];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            data = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template<>
// @fnv 0x00a5d320
void NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>::SetAt(
    NiObject* key, bool data)
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<NiObject*, bool>* item = m_ppkHashTable[index];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            item->m_val = data;
            return;
        }
        item = item->m_pkNext;
    }
    item = NewItem();
    SetValue(item, key, data);
    item->m_pkNext = m_ppkHashTable[index];
    m_ppkHashTable[index] = item;
    m_kItemCount.m_uiCount++;
}

template<>
// @fnv 0x00e92760
bool NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiPointer<RefCountedNamedObject> >::GetAt(
    const char* key, NiPointer<RefCountedNamedObject>& data) const
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<const char*, NiPointer<RefCountedNamedObject> >* item = m_ppkHashTable[index];
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            data = item->m_val;
            return true;
        }
        item = item->m_pkNext;
    }
    return false;
}

template<>
// @fnv 0x00e91fd0
bool NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*>::RemoveAt(
    const char* key)
{
    unsigned int index = KeyToHashIndex(key);
    NiTMapItem<const char*, NiShader*>* item = m_ppkHashTable[index];
    if (!item)
        return false;
    if (IsKeysEqual(key, item->m_key))
    {
        m_ppkHashTable[index] = item->m_pkNext;
        ClearValue(item);
        DeleteItem(item);
        m_kItemCount.m_uiCount--;
        return true;
    }

    NiTMapItem<const char*, NiShader*>* previous = item;
    item = item->m_pkNext;
    while (item)
    {
        if (IsKeysEqual(key, item->m_key))
        {
            previous->m_pkNext = item->m_pkNext;
            ClearValue(item);
            DeleteItem(item);
            m_kItemCount.m_uiCount--;
            return true;
        }
        previous = item;
        item = item->m_pkNext;
    }
    return false;
}


#pragma optimize("", off)

// @fnv 0x00404d30
bool FUN_00404d30_Owner::GetFirstPos()
{
    return count != 0;
}

// @fnv 0x00589000
// the base constructor 0x005892c0, then the NiTPointerMap<int,TESObjectCELL *> vftable 0x01031fec.
template <>
NiTPointerMap<int, TESObjectCELL*>::NiTPointerMap(unsigned int size)
    : NiTMapBase<NiTPointerAllocator<unsigned int>, int, TESObjectCELL*>(size)
{
}

// @fnv 0x004701d0
FUN_004701d0_TESFormLargeArray::FUN_004701d0_TESFormLargeArray(unsigned int size, unsigned int flags)
{
 NiTLargeArray_TESForm_NiTMallocInterface_TESForm_NiTLargeArray(size,flags);
 vtable = DAT_01019a3c;
}

// @fnv 0x00402d00
TESFullName::TESFullName() {}


// @fnv 0x00845690
FUN_00845690_Owner* FUN_00845690_Owner::Destructor(unsigned int flags)
{
 Object_ForwardCall_008456c0();
 if (flags & 1) operator delete(this);
 return this;
}

// @fnv 0x006b7b30
// src: COMMUNITY 0x006b7b30
unsigned int NavMeshInfo_GetCellOrCoords(NavMeshInfo* info)
{
 TESObjectCELL* cell = info->GetInteriorCell();
 if (cell)
   return reinterpret_cast<unsigned int (__cdecl*)(TESObjectCELL*)>(PrepareScriptMessage)(cell);
 else
   return reinterpret_cast<unsigned int (__cdecl*)(TESObjectCELL*)>(PrepareScriptMessage)(reinterpret_cast<TESObjectCELL*>(info->m_uiPathingFlags));
}

// @fnv 0x00473210
void TESFile::SetCompileIndex(unsigned char index)
{
 m_kFileMetadata.m_uiThirdUnsignedValue = (static_cast<unsigned int>(index) << 24) | (m_kFileMetadata.m_uiThirdUnsignedValue & 0x00ffffff);
 m_ucCompileIndex = index;
}

// @fnv 0x0043d410
NiUpdateData::NiUpdateData(float time,bool updateControllers,bool isMultiThreaded)
{
 // pad1..pad5 are the shared header's names for Gamebryo's update flags (+0x4 controllers, +0x5 multithreaded).
 this->fTime=time;
 this->pad1=updateControllers;
 this->pad2=isMultiThreaded;
 pad3=false;
 pad4=false;
 pad5=false;
}

// @fnv 0x004b9ba0
void* BGSReconstructFormsInAllFilesMap::GetFirstPos()
{
 for (unsigned int i=0;i<m_uiHashSize;i++)
 {
  if(m_ppkHashTable[i]) return m_ppkHashTable[i];
 }
 return 0;
}

// @fnv 0x00843470
FormChangeMap::FormChangeMap() {}

