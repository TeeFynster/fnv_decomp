// gamebryo2.2/corelibs/nimain/niskininstance.cpp: NiSkinInstance (8 functions)

#include "../../../../include/NiSkinInstance.h"
#include "../../../../include/NiSkinData.h"
#include "../../../../include/NiTPointerMap.h"
#include "niskininstance_decls.h"
// @fnv 0x00a86340
void NiSkinInstance::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    stream.ResetStreamState();
    if (stream.m_uiNifFileVersion >= 0x0a010065)
        stream.ResetStreamState();
    stream.ResetStreamState();
    stream.ReadUnsignedInteger();
}
// @fnv 0x00a86380
void NiSkinInstance::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_pSkinData = stream.GetLoadedObject();
    if (stream.m_uiNifFileVersion >= 0x0a010065)
        m_pkSkinMeshPartition = stream.GetLoadedObject();
    m_pRootParent = stream.GetLoadedObject();
    unsigned int count = stream.GetLinkID();
    m_ppBones = (NiObject**)_NiMalloc(count * sizeof(NiObject*));
    for (unsigned int i = 0; i < count; ++i)
        m_ppBones[i] = stream.GetLoadedObject();
}

// @fnv 0x00a864d0
bool NiSkinInstance::IsEqual(NiObject* pkObject) const
{
    NiSkinInstance* pkSkinInstance = (NiSkinInstance*)pkObject;
    if (!((NiObject*)this)->NiObject::IsEqual(pkObject))
        return false;
    void* pData = *(void**)((char*)this + 8);
    void* pOtherData = *(void**)((char*)pkSkinInstance + 8);
    if (!((bool(__thiscall*)(void*, void*))((void**)*(void**)pData)[0x5c / 4])(pData, pOtherData))
        return false;
    void* pThisPart = *(void**)((char*)this + 0xc);
    if (pThisPart)
    {
        void* pOtherPart = *(void**)((char*)pkSkinInstance + 0xc);
        if (!((bool(__thiscall*)(void*, void*))((void**)*(void**)pThisPart)[0x5c / 4])(pThisPart, pOtherPart))
            return false;
    }
    if (*(void**)((char*)this + 0xc) == 0 && *(void**)((char*)pkSkinInstance + 0xc) != 0)
        return false;
    return true;
}

__forceinline void VisitLinkedObject(NiObject* object, NiStream& stream)
{
    object->RegisterStreamables(stream);
}
// @fnv 0x00a86460
bool NiSkinInstance::RegisterStreamables(NiStream& stream)
{
    if (!NiObject::RegisterStreamables(stream))
        return false;
    VisitLinkedObject(m_pSkinData.m_pObject, stream);
    if (m_pkSkinMeshPartition.m_pObject)
        VisitLinkedObject(m_pkSkinMeshPartition.m_pObject, stream);
    VisitLinkedObject(m_pRootParent, stream);
    unsigned int count = static_cast<NiSkinData*>(m_pSkinData.m_pObject)->m_uiBoneCount;
    for (unsigned int index = 0; index < count; ++index)
    {
        VisitLinkedObject(m_ppBones[index], stream);
    }
    return true;
}

class NiPtrAssignHelper
{
  public:
    NiObject* p;
    void Assign(NiObject* value);
};

// @fnv 0x00a86740
void NiSkinInstance::PostLinkObject(NiStream& stream)
{
    if (stream.m_uiNifFileVersion >= 0xa010065)
    {
        return;
    }
    if (m_pSkinData.m_pObject == 0)
    {
        return;
    }
    NiSkinData* data = static_cast<NiSkinData*>(m_pSkinData.m_pObject);
    reinterpret_cast<NiPtrAssignHelper*>(&m_pkSkinMeshPartition)->Assign(static_cast<NiObject*>(data->m_sp.m_pObject));
    NiPointer<NiObject>& rSkinLink =
        reinterpret_cast<NiPointer<NiObject>&>(static_cast<NiSkinData*>(m_pSkinData.m_pObject)->m_sp);
    if (rSkinLink.m_pObject != 0)
    {
        rSkinLink = 0;
    }
}

void* NiMalloc(unsigned int uiSize);

template <class T> inline NiPointer<T>::NiPointer(T* pkNew)
{
    m_pObject = pkNew;
    if (pkNew)
        InterlockedIncrement((volatile long*)&pkNew->m_uiRefCount);
}

__forceinline NiSkinInstance::NiSkinInstance() throw()
    : m_pSkinData((NiObject*)0), m_pkSkinMeshPartition((NiObject*)0), m_pRootParent(0), m_ppBones(0)
{
    // The shared header currently describes only the prefix; the original constructor initializes this 0x34-byte object.
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x18) = 0xffffffff;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x1c) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x20) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x24) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x28) = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x30) = 0;
}

// Explicit-size allocation covers the renderer cache omitted from NiSkinInstance.h.
inline void* operator new(size_t, unsigned int uiSize) throw()
{
    return NiMemObject::operator new(uiSize);
}

// Clones the skin instance when cloneable, remapping the skin root and bone objects through the cloning map and copying the bone pointer array.
// @fnv 0x00a86830
// src: XBOX_PDB 0x00a86830
NiSkinInstance* NiSkinInstance::CreateClone_00a86830(CloningProcess& kCloning)
{
    if (!IsCloneable(kCloning))
        return this;

    // Preserve the complete allocation size until the shared header includes the renderer cache fields.
    NiSkinInstance* pkClone = ::new (0x34U) NiSkinInstance;
    CopyMemberData(pkClone, kCloning);

    NiObject* pkClonedObject = 0;
    // CloningProcess is opaque in the shared headers; its first pointer is the clone map
    // (GetAt 0x00a53c30 in nitimecontroller.cpp).
    pkClone->m_pRootParent =
        (*reinterpret_cast<NiTPointerMap<NiObject*, NiObject*>**>(&kCloning))->GetAt(m_pRootParent, pkClonedObject)
            ? pkClonedObject : m_pRootParent;

    unsigned int uiBones = static_cast<NiSkinData*>(m_pSkinData.m_pObject)->m_uiBoneCount;
    pkClone->m_ppBones = (NiObject**)NiMalloc(uiBones * sizeof(NiObject*));
    for (unsigned int i = 0; i < uiBones; i++)
    {
        pkClone->m_ppBones[i] =
            (*reinterpret_cast<NiTPointerMap<NiObject*, NiObject*>**>(&kCloning))->GetAt(m_ppBones[i], pkClonedObject)
                ? pkClonedObject : m_ppBones[i];
    }
    return pkClone;
}

class NiBinaryStreamW
{
  public:
    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int (*m_pfnWrite)(NiBinaryStreamW*, const void*, unsigned int, unsigned int*, unsigned int);

    void Write(const void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = uiBytes;
        BinaryWrite(pvBuffer, uiBytes, &uiSize, 1);
    }
    void BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                     unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
    }
};

inline void SerializeValue(NiStream& kStream, const unsigned int& uiValue)
{
    ((NiBinaryStreamW*)kStream.m_pkOstr)->Write(&uiValue, sizeof(unsigned int));
}

// Writes the skin instance's link IDs, bone count and each bone's link ID to the stream.
// @fnv 0x00a867a0
void NiSkinInstance::SaveBinary(NiStream& kStream)
{
    NiObject::SaveBinary(kStream);
    kStream.SaveLinkID(m_pSkinData.m_pObject);
    kStream.SaveLinkID(m_pkSkinMeshPartition.m_pObject);
    kStream.SaveLinkID(m_pRootParent);
    unsigned int uiBones = static_cast<NiSkinData*>(m_pSkinData.m_pObject)->m_uiBoneCount;
    SerializeValue(kStream, uiBones);
    for (unsigned int i = 0; i < uiBones; i++)
        kStream.SaveLinkID(m_ppBones[i]);
}

#include <string.h>
#include <stdio.h>
struct Strings
{
    void* vtable;
    char** data;
    unsigned short capacity, size, count, grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + grow);
        SetAt(index, value);
    }
    __forceinline void AddInline(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + grow);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (value)
                ++count;
        }
        else if (value)
        {
            if (!data[index])
                ++count;
        }
        else
        {
            if (data[index])
                --count;
        }
        data[index] = value;
    }
};
struct Named
{
    void* vtable;
    unsigned int refs;
    char* name;
    char* GetName()
    {
        return name;
    }
};
struct Root
{
    unsigned int refs;
    char* name;
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
    virtual void Describe(Strings*);
};
extern void __stdcall ClearStrings(Strings*);
extern char* globalName;
char* CopyName(char*);
char* Label(const char*, const char*);
char* NiGetViewerString_00a7d510(const char*, unsigned int);
void* NiMalloc(unsigned int);
void NiFree(void*);
int CompareBoneNames(const void*, const void*);
extern "C" void __cdecl SortNames(void*, unsigned int, unsigned int, int(__cdecl*)(const void*, const void*));
void FUN_00a305b0(char*, unsigned int, const char*, ...);
struct BonePtr
{
    Named* p;
    operator Named*&()
    {
        return p;
    }
    Named*& operator->()
    {
        return p;
    }
};
// Adds skin and parent labels, hardware partition and bone count values, sorted bone labels, then calls partition->Describe.
// @fnv 0x00a86920
void NiSkinInstance::GetViewerStrings(NiViewerStringsArray* strings)
{
    Strings* apStrings = (Strings*)strings;
    ClearStrings(apStrings);
    apStrings->Add(CopyName(globalName));
    if (m_pRootParent)
        apStrings->Add(Label("Root Parent", ((Named*)m_pRootParent)->GetName()));
    NiSkinData* pPartition = static_cast<NiSkinData*>(m_pSkinData.m_pObject);
    if (pPartition)
    {
        unsigned int partitions = (unsigned int)m_pkSkinMeshPartition.m_pObject;
        if (partitions)
            partitions = (unsigned int)((Root*)m_pkSkinMeshPartition.m_pObject)->name;
        apStrings->Add(NiGetViewerString_00a7d510("Hardware partitions", partitions));
        unsigned int uiBoneCount = pPartition->m_uiBoneCount;
        apStrings->Add(NiGetViewerString_00a7d510("Bone Count", uiBoneCount));
        char** ppBoneNames = (char**)NiMalloc(uiBoneCount * sizeof(char*));
        char szBoneName[1000];
        for (unsigned int index = 0; index < uiBoneCount; ++index)
        {
            sprintf(szBoneName, "%s (%08X)", ((BonePtr*)m_ppBones)[index]->GetName(), ((BonePtr*)m_ppBones)[index]);
            ppBoneNames[index] = (char*)NiMalloc(strlen(szBoneName) + 1);
            strcpy(ppBoneNames[index], szBoneName);
        }
        SortNames(ppBoneNames, uiBoneCount, 4, CompareBoneNames);
        for (unsigned int index = 0; index < uiBoneCount; ++index)
        {
            char szIndex[10];
            FUN_00a305b0(szIndex, 10, "  %3d", index);
            apStrings->AddInline(Label(szIndex, ppBoneNames[index] ? ppBoneNames[index] : "<noname>"));
        }
        for (unsigned int index = 0; index < uiBoneCount; ++index)
            NiFree(ppBoneNames[index]);
        NiFree(ppBoneNames);
        ((Root*)m_pkSkinMeshPartition.m_pObject)->Describe(apStrings);
    }
}
