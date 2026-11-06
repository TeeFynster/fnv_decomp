#pragma once

// Preserve a unit's checked Gamebryo nothrow inlines without copying the class.
#ifndef FNV64_NIPOINTER_EXCEPTION_SPEC
#define FNV64_NIPOINTER_EXCEPTION_SPEC
#endif

// Gamebryo 2.2 NiSmartPointer.h: template <class T> class NiPointer, one T* (4 bytes, no vtable; every
// NiTArray<NiPointer<X>,...> / BSSimpleArray<NiPointer<X>> element in the exe is 4 bytes, RTTI has no NiPointer
// type descriptor because it is not polymorphic).
//
// Gamebryo declares one constructor NiPointer(T* pObject = (T*)0). The FNV units that already share this class
// (through NiAVObject.h) define a separate default constructor out of class, so the two are declared separately
// here; the code they generate is the same (m_pObject = object; IncRefCount when non-null).
//
// Bodies: NiSmartPointer.inl. VC9 inlining of these depends on how each unit spells them (/Od units call them
// out of line, units built with /Ob1 need them visible), so most units define them out of class themselves:
//     template <class T> inline NiPointer<T>::~NiPointer() { if (m_pObject != 0) m_pObject->DecRefCount(); }
// Define FNV64_NIPOINTER_INLINE_BODIES before the first include to get the Gamebryo bodies from this header.
template <class T> class NiPointer
{
  public:
    NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;
    NiPointer(T* object) FNV64_NIPOINTER_EXCEPTION_SPEC;
    NiPointer(const NiPointer& other) FNV64_NIPOINTER_EXCEPTION_SPEC;
    ~NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC;

    operator T*() const FNV64_NIPOINTER_EXCEPTION_SPEC;
    T& operator*() const FNV64_NIPOINTER_EXCEPTION_SPEC;
    T* operator->() const FNV64_NIPOINTER_EXCEPTION_SPEC;

    NiPointer& operator=(T* object) FNV64_NIPOINTER_EXCEPTION_SPEC;
    NiPointer& operator=(const NiPointer& other) FNV64_NIPOINTER_EXCEPTION_SPEC;


#if defined(FNV64_NIPOINTER_INLINE_BODIES) || defined(FNV64_NIPOINTER_COMPARE_DECLS)
    // Gamebryo's comparison operators (it also has operator!=(T*)), with the bodies: /Od code calls them (0x006c6400
    // calls operator!= 0x00631820). Without the bodies, comparisons go through operator T*, as the units that define
    // the bodies themselves expect.
    bool operator==(T* object) const FNV64_NIPOINTER_EXCEPTION_SPEC;
    bool operator==(const NiPointer& other) const FNV64_NIPOINTER_EXCEPTION_SPEC;
    bool operator!=(const NiPointer& other) const FNV64_NIPOINTER_EXCEPTION_SPEC;
#endif

    union
    {
        T* m_pObject;
        T* value;  // same member under the name src/fallout/ai/combatcontroller.cpp still uses; drop when it says m_pObject
    };
};

// Explicit specializations with unit-specific lifecycle declarations share this header.
class BSFaceGenModel;
class BSNodeReferences;
class NiBoolData;

template <> class NiPointer<BSFaceGenModel>
{
public:
    union
    {
        BSFaceGenModel* m_pObject;
        BSFaceGenModel* value;
    };

    NiPointer();
    NiPointer(BSFaceGenModel* object);
    NiPointer(const NiPointer& other);
    ~NiPointer();
    NiPointer& operator=(BSFaceGenModel* object);
    NiPointer& operator=(const NiPointer& other);
    operator BSFaceGenModel*() const;
    BSFaceGenModel* operator->() const;
    BSFaceGenModel& operator*() const;
    bool operator==(BSFaceGenModel* object) const;
    bool operator==(const NiPointer& other) const;
    bool operator!=(const NiPointer& other) const;
};

template <> class NiPointer<BSNodeReferences>
{
public:
    BSNodeReferences* m_pObject;

    NiPointer(BSNodeReferences* object = 0) : m_pObject(object) {}
    ~NiPointer();
    operator BSNodeReferences*() const;
    BSNodeReferences* operator->() const;
    NiPointer& operator=(BSNodeReferences* object);
};

template <> class NiPointer<NiBoolData>
{
  public:
    union
    {
        NiBoolData* m_pObject;
        NiBoolData* value;
    };

    NiPointer();
    NiPointer(NiBoolData* object);
    NiPointer(const NiPointer& other);
    ~NiPointer();
    NiPointer& operator=(NiBoolData* object);
    NiPointer& operator=(const NiPointer& other);
    operator NiBoolData*() const;
    NiBoolData* operator->() const;
    NiBoolData& operator*() const;
};

#ifdef FNV64_NIPOINTER_INLINE_BODIES
// Out-of-class bodies, in the order the exe's /Od helpers need them. Every null test below compiles to the same
// `cmp [ptr],0 / je` (or `test`) the original has.
template <class T> inline NiPointer<T>::~NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> inline NiPointer<T>::NiPointer() FNV64_NIPOINTER_EXCEPTION_SPEC
{
    // the default-argument form of the one Gamebryo constructor: /Od stores 0 and still tests it
    m_pObject = 0;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::NiPointer(T* pkInit) FNV64_NIPOINTER_EXCEPTION_SPEC
{
    m_pObject = pkInit;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> inline NiPointer<T>::NiPointer(const NiPointer& kSrc) FNV64_NIPOINTER_EXCEPTION_SPEC
{
    m_pObject = kSrc.m_pObject;
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

// assignment: skip the work when the pointer does not change, else release the old object and hold the new one
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc) FNV64_NIPOINTER_EXCEPTION_SPEC
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew) FNV64_NIPOINTER_EXCEPTION_SPEC
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline T* NiPointer<T>::operator->() const FNV64_NIPOINTER_EXCEPTION_SPEC { return m_pObject; }
template <class T> inline T& NiPointer<T>::operator*() const FNV64_NIPOINTER_EXCEPTION_SPEC { return *m_pObject; }
template <class T> inline NiPointer<T>::operator T*() const FNV64_NIPOINTER_EXCEPTION_SPEC { return m_pObject; }

template <class T> inline bool NiPointer<T>::operator!=(const NiPointer& kSrc) const FNV64_NIPOINTER_EXCEPTION_SPEC { return m_pObject != kSrc.m_pObject; }
template <class T> inline bool NiPointer<T>::operator==(const NiPointer& kSrc) const FNV64_NIPOINTER_EXCEPTION_SPEC { return m_pObject == kSrc.m_pObject; }
template <class T> inline bool NiPointer<T>::operator==(T* pkCmp) const FNV64_NIPOINTER_EXCEPTION_SPEC { return m_pObject == pkCmp; }

#endif