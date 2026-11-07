// gamebryo2.2/corelibs/nimain/niobject_decls.h: declares CloningProcess, NiObject, NiObjectCopyInfo, NiAVObject and more
#ifndef FNV_NIOBJECT_LUNA_DEFS_H
#define FNV_NIOBJECT_LUNA_DEFS_H

template <class T> class NiPointer;
class NiRTTI;
class NiStream;
class NiObject;
template <class T> class NiTPointerAllocator;
template <class Alloc, class Key, class Data> class NiTMapBase;
template <> class NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>
{
  public:
    void SetAt(NiObject*, bool);
};
class CloningProcess
{
  public:
    void* m_pCloneMap;
    NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, bool>* m_pProcessMap;
};
class NiObject
{
  public:
    virtual void ProcessClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    virtual bool RegisterStreamables(NiStream&);
    virtual const NiRTTI* GetStreamableRTTI();
    NiObject();
    void FUN_00a5d3d0();
    void CopyMembersStream(unsigned int, void*);
    NiObject* Clone();
    void ResolveObjectPointer(NiPointer<NiObject>&);
    void CopyMemberData(NiObject*, CloningProcess&);
    void LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_RemoveAt_00528ce0(NiObject*);
};
extern "C" void NiObjectCopyInfoCtorAlias();
extern "C" void NiTMapSetAtAlias();
extern "C" void NiStreamGetGroupFromIDAlias();
extern "C" void NiStreamCtorAlias();
extern "C" void NiStreamInsertObjectAlias();
extern "C" void NiStreamSaveAlias();
extern "C" void NiStreamLoadAlias();
extern "C" void NiStreamDtorAlias();
extern "C" void NiFreeAlias();
extern "C" void SecurityCookieAlias();
class NiObjectCopyInfo
{
  public:
    NiObjectCopyInfo(unsigned int);
};
class NiAVObject : public NiObject
{
  public:
    virtual void ProcessClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
    void bhkRefObject_SethkObject(NiObject*);
};
class bhkRefObject : public NiObject
{
  public:
    bhkRefObject* Initialize();
    void Destroy();
    void UpdateReference(bool);
    void* GetReferencedData();
    void* GetReferencedDataSafe();
};
class bhkSerializable : public bhkRefObject
{
  public:
    void Destroy();
};
class hkLimitedHingeConstraintCinfo
{
  public:
    hkLimitedHingeConstraintCinfo* Initialize();
    void UpdateNodeState(void*);
};
class NiPlane
{
  public:
    bool operator==(const NiPlane&) const;
};
#include "../../../../include/NiMatrix3.h"
class NiVBSet
{
  public:
    void Create(unsigned int, void*);
};
class MemoryManager
{
  public:
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern unsigned int DAT_011c16bc;
extern unsigned int DAT_0126fd98;
extern unsigned char DAT_00f31ee0, DAT_00f31f10, DAT_00f306c8;
extern unsigned char DAT_0102023c, DAT_010c5b54, DAT_010c5dc0, DAT_01268160;
extern unsigned char DAT_011f426c, DAT_011f4270, DAT_011f4274, DAT_011a9448;
extern "C" void Call_a5d3a0();

extern "C" void Call_439090();
extern "C" void Call_4d9ae0();

#endif
