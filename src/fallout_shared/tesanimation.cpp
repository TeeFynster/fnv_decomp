// fallout_shared/tesanimation.cpp: TESAnimation, ActorValueOwner (10 functions)

#include "../../include/ActorValueOwner.h"
#include "layout_support.h"
#include "../../include/TESAnimation.h"

unsigned int __cdecl BSStringLength(const char*);

// @fnv 0x0047f9f0
TESAnimation::~TESAnimation()
{
    ClearComponent();
}

// Removes and deletes every filename string from the animation list until it is empty.
// @fnv 0x0047fa50
void TESAnimation::ClearComponent()
{
    while (!m_kKFFileList.IsEmpty())
    {
        const char* filename = m_kKFFileList.GetItem();
        m_kKFFileList.RemoveHead();
        delete const_cast<char*>(filename);
    }
}

// @fnv 0x0047fd90
bool TESAnimation::HasSpecialAnimations()
{
    if (m_kKFFileList.IsEmpty())
    {
        return false;
    }
    return true;
}

// @fnv 0x005f78e0
ActorValueOwner::ActorValueOwner()
{}

// @fnv 0x0047faa0
void TESAnimation::LoadComponent(TESForm* form, TESFile* file)
{
    if (!file || !form)
        return;
    unsigned int chunk = file->GetChunkID();
    switch (chunk)
    {
    case 0x5a46464b: {
        char* pCurrent;
        char* pData = new char[file->GetChunkSize()];
        pCurrent = pData;
        file->GetChunkData(pData, 0);
        while (*pCurrent)
        {
            AddPathToList(pCurrent);
            pCurrent = pCurrent + BSStringLength(pCurrent) + 1;
        }
        delete[] pData;
    }
    break;
    }
}

// @fnv 0x0047f9c0
TESAnimation::TESAnimation()
{}

int __cdecl _stricmp(const char*, const char*);
// @fnv 0x0047fcb0
bool TESAnimation::IsKFFileInList(const char* apName)
{
    if (m_kKFFileList.IsEmpty())
        return false;
    BSSimpleList<const char*>* pNode = &m_kKFFileList;
    while (pNode)
    {
        const char* pcName = pNode->GetItem();
        if (!_stricmp(pcName, apName))
            return true;
        pNode = pNode->GetNext();
    }
    return false;
}

void* __cdecl operator new(unsigned int);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
// If the path is not already present, allocates a copy of it, copies the string into it and appends it to the list.
// @fnv 0x0047fd20
void TESAnimation::AddPathToList(const char* apPath)
{
    char* pcPathCopy;
    if (!IsKFFileInList(apPath))
    {
        unsigned int uiSize = BSStringLength(apPath) + 1;
        pcPathCopy = new char[uiSize];
        TaskQueueInterface::CopyStringToBuffer(pcPathCopy, uiSize, apPath);
        m_kKFFileList.AddTail(reinterpret_cast<const char* const&>(pcPathCopy));
    }
}

// Casts apCopyFC to TESAnimation, frees this component, then copies each filename from the source's file list via AddPathToList.
// @fnv 0x0047fb50
void TESAnimation::CopyFromBase(BaseFormComponent* apCopyFC)
{
    TESAnimation* pcopy = dynamic_cast<TESAnimation*>(apCopyFC);
    if (pcopy == 0)
        return;
    ((BaseFormComponent*)this)->Free();
    BSSimpleList<const char*>* pkfFileList = &pcopy->m_kKFFileList;
    while (pkfFileList != 0)
    {
        const char* pkfFilename = pkfFileList->GetItem();
        if (pkfFilename != 0)
            AddPathToList(pkfFilename);
        pkfFileList = pkfFileList->GetNext();
    }
}

int __cdecl CompareNamesNoCase(const char* a, const char* b);

// @fnv 0x0047fbd0
bool TESAnimation::CompareWithBase(BaseFormComponent* component)
{
    const char* x;
    const char* y;
    TESAnimation* other_2 = dynamic_cast<TESAnimation*>(component);
    if (other_2 == 0)
    {
        return true;
    }
    BSSimpleList<const char*>* a = &this->m_kKFFileList;
    BSSimpleList<const char*>* b8 = &other_2->m_kKFFileList;
    while (a != 0 && b8 != 0)
    {
        x = a->GetItem();
        y = b8->GetItem();
        if ((x == 0 && y != 0) || (x != 0 && y == 0))
        {
            return true;
        }
        else
        {
            if (x != 0 && y != 0)
            {
                if (CompareNamesNoCase(x, y) != 0)
                {
                    return true;
                }
            }
        }
        a = a->GetNext();
        b8 = b8->GetNext();
    }
    if (a != 0 || b8 != 0)
    {
        return true;
    }
    return false;
}
