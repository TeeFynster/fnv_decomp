
// src/havok/physics/dynamics/constraint/util/hkpconstraintdatacloningutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/util/hkpconstraintdatacloningutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Allocator858
{
    virtual void v00();
    virtual void* Allocate(unsigned int uiSize);
};
struct Heap858
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator858* m_pHeapAllocator;

    void* Allocate(unsigned int uiSize)
    {
        return m_pHeapAllocator->Allocate(uiSize);
    }
};
extern "C" Heap858* __cdecl hkMemoryRouter_getInstance();

struct Clonable858
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Clonable858* Clone();
};

struct Object858
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual int GetType();
    unsigned short usSize;
    unsigned short usFlags;
    int iValue;
    int unk0c;
};

struct Payload858
{
    void ProcessAndReturnValue_00d85ba0(const Payload858* pkSrc);
    void AssignFrom(const Payload858* pkSrc);
    void CopyStateFrom(const Payload858* pkSrc);
};

struct Type7Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xe0 - 0x11];
    Clonable858* apkChildren[3];
};
struct Type6Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xac - 0x11];
    Clonable858* pkChild;
};
struct Type2Object858 : Object858
{
    Payload858 kPayload;
    char acPad[0xb0 - 0x11];
    Clonable858* pkChild;
};

struct Raw858
{
    Type7Object858* FUN_00cdf2f0();
    Type6Object858* FUN_00d4fe80();
    Type2Object858* FUN_00cb9090();
};

inline Raw858* Allocate858(unsigned int uiSize)
{
    Object858* pkObject = (Object858*)hkMemoryRouter_getInstance()->Allocate(uiSize);
    pkObject->usSize = (unsigned short)uiSize;
    return (Raw858*)pkObject;
}

// Allocates a new object matching pkSource's type (7, 6 or 2), copies its payload and iValue, clones child pointers, and returns it or 0.
// @fnv 0x00d858f0
// src: HAVOK_LIB 0x00d858f0
Object858* __cdecl hkpConstraintDataCloningUtil_cloneIfCanHaveMotors(Object858* pkSource)
{
    switch (pkSource->GetType())
    {
    case 7: {
        Type7Object858* pkResult = Allocate858(0x140)->FUN_00cdf2f0();
        pkResult->kPayload.ProcessAndReturnValue_00d85ba0(&((Type7Object858*)pkSource)->kPayload);
        pkResult->iValue = pkSource->iValue;
        Clonable858** ppkChildren = pkResult->apkChildren;
        for (int i = 0; i < 3; i++)
        {
            if (ppkChildren[i])
                ppkChildren[i] = ppkChildren[i]->Clone();
        }
        return pkResult;
    }
    case 6: {
        Type6Object858* pkResult = Allocate858(0xd0)->FUN_00d4fe80();
        pkResult->kPayload.AssignFrom(&((Type6Object858*)pkSource)->kPayload);
        pkResult->iValue = pkSource->iValue;
        Clonable858*& rpkChild = pkResult->pkChild;
        if (rpkChild)
            rpkChild = rpkChild->Clone();
        return pkResult;
    }
    case 2: {
        Type2Object858* pkResult = Allocate858(0xe0)->FUN_00cb9090();
        pkResult->kPayload.CopyStateFrom(&((Type2Object858*)pkSource)->kPayload);
        pkResult->iValue = pkSource->iValue;
        Clonable858*& rpkChild = pkResult->pkChild;
        if (rpkChild)
            rpkChild = rpkChild->Clone();
        return pkResult;
    }
    }
    return 0;
}

struct hkRefObj858
{
    void removeReference();
};
struct Heap858b
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator858* m_pHeapAllocator;
    Allocator858& heap()
    {
        return *m_pHeapAllocator;
    }
};
template <class T> __forceinline T* AllocA(unsigned int uiSize)
{
    Object858* p = (Object858*)((Heap858b*)hkMemoryRouter_getInstance())->heap().Allocate(uiSize);
    p->usSize = (unsigned short)uiSize;
    return (T*)p;
}
struct Node858 : Object858
{
    int unk10;
    int unk14;
    Object858* pkChild;
    float unk1c;
    Object858* GetFieldC();
};
struct Breakable858 : Object858
{
    int unk10;
    int unk14;
    Object858* m_pConstraintData;
    int unk1c;
    float m_fBreakingStrength;
    unsigned char m_bRemoveWhenBroken;
    unsigned char m_bRevertBackVelocityOnBreak;
    Object858* GetBreakableObject() const
    {
        return m_pConstraintData;
    }
    float getThreshold() const
    {
        return m_fBreakingStrength;
    }
    void setThreshold(float t)
    {
        m_fBreakingStrength = t;
    }
    unsigned char getRemoveWhenBroken() const
    {
        return m_bRemoveWhenBroken;
    }
    void setRemoveWhenBroken(unsigned char b)
    {
        m_bRemoveWhenBroken = b;
    }
    unsigned char getRevertBackVelocityOnBreak() const
    {
        return m_bRevertBackVelocityOnBreak;
    }
    void setRevertBackVelocityOnBreak(unsigned char b)
    {
        m_bRevertBackVelocityOnBreak = b;
    }
};
struct Kind3Shape858
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
    virtual hkRefObj858* GetChildShape();
};
struct Kind3Result858
{
    void hkpPointToPathConstraintData_setPath(Kind3Shape858* pkChild);
};
struct Raw858b
{
    Breakable858* FUN_00d4df30(Object858* pkChild);
    Node858* FUN_00cdf710(Object858* pkChild);
};
Object858* __cdecl hkpConstraintDataUtils_copyAtoms_hkpBallAndSocketConstraintData_(Object858* pkSource);
Object858* __cdecl copyConstraintAtoms_class_hkpHingeConstraintData(Object858* pkSource);
Object858* __cdecl copyConstraintAtoms_class_hkpLimitedHingeConstraintData(Object858* pkSource);
Object858* __cdecl CloneShape(Object858* pkSource);
Object858* __cdecl CloneAllocatedObject(Object858* pkSource);
Object858* __cdecl CloneStub(Object858* pkSource);
Object858* __cdecl hkpConstraintDataUtils_copyAtoms_hkpStiffSpringConstraintData_(Object858* pkSource);
Object858* __cdecl CloneWithInit(Object858* pkSource);
Object858* __cdecl CloneDataBlock(Object858* pkSource);
Object858* __cdecl CloneWithCopiedPayload(Object858* pkSource);
Object858* __cdecl copyConstraintAtoms_class_hkpHingeLimitsData(Object858* pkSource);
Object858* __cdecl CloneWithAllocatedCopy(Object858* pkSource);

// Dispatches on pkSource->GetType() to clone the object, recursively cloning child nodes and copying breakable properties.
// @fnv 0x00d85700
// src: HAVOK_LIB 0x00d85700
Object858* __cdecl hkpConstraintDataCloningUtil_deepClone(Object858* pkSource)
{
    switch (pkSource->GetType())
    {
    case 0:
        return hkpConstraintDataUtils_copyAtoms_hkpBallAndSocketConstraintData_(pkSource);
    case 1:
        return copyConstraintAtoms_class_hkpHingeConstraintData(pkSource);
    case 2:
        return copyConstraintAtoms_class_hkpLimitedHingeConstraintData(pkSource);
    case 3: {
        Object858* pkResult = CloneShape(pkSource);
        Kind3Shape858* pkChild = (Kind3Shape858*)((Node858*)pkSource)->pkChild;
        hkRefObj858* pkShape = pkChild->GetChildShape();
        ((Kind3Result858*)pkResult)->hkpPointToPathConstraintData_setPath(pkChild);
        pkShape->removeReference();
        return pkResult;
    }
    case 6:
        return CloneAllocatedObject(pkSource);
    case 7:
        return CloneStub(pkSource);
    case 8:
        return hkpConstraintDataUtils_copyAtoms_hkpStiffSpringConstraintData_(pkSource);
    case 9:
        return CloneWithInit(pkSource);
    case 14:
        return CloneDataBlock(pkSource);
    case 15:
        return CloneWithCopiedPayload(pkSource);
    case 18:
        return copyConstraintAtoms_class_hkpHingeLimitsData(pkSource);
    case 19:
        return CloneWithAllocatedCopy(pkSource);
    case 12: {
        Breakable858* pkOld = (Breakable858*)pkSource;
        Object858* pkChild = hkpConstraintDataCloningUtil_deepClone(pkOld->GetBreakableObject());
        if (!pkChild)
            return 0;
        Breakable858* pkNew = AllocA<Raw858b>(0x28)->FUN_00d4df30(pkChild);
        ((hkRefObj858*)pkChild)->removeReference();
        pkNew->m_fBreakingStrength = pkOld->m_fBreakingStrength;
        pkNew->m_bRemoveWhenBroken = pkOld->m_bRemoveWhenBroken;
        pkNew->m_bRevertBackVelocityOnBreak = pkOld->m_bRevertBackVelocityOnBreak;
        pkNew->iValue = pkOld->iValue;
        return pkNew;
    }
    case 13: {
        Node858* pkNode = (Node858*)pkSource;
        Object858* pkChild = hkpConstraintDataCloningUtil_deepClone(pkNode->GetFieldC());
        if (!pkChild)
            return 0;
        Node858* pkClone = AllocA<Raw858b>(0x20)->FUN_00cdf710(pkChild);
        ((hkRefObj858*)pkChild)->removeReference();
        pkClone->unk1c = pkNode->unk1c;
        pkClone->iValue = pkNode->iValue;
        return pkClone;
    }
    }
    return 0;
}
