#pragma once

#include "hkBool.h"
#include "hkVariant.h"

class hkClassEnum;
class hkClassMember;
class hkCustomAttributes;

typedef int hkInt32;
typedef unsigned int hkUint32;

template <class T>
struct hkSimpleArray
{
    T* m_data;
    int m_iElementCount;
};

class hkClass
{
public:
    enum SignatureFlags
    {
        SIGNATURE_LOCAL = 1
    };

    enum FlagValues
    {
        FLAGS_NONE = 0,
        FLAGS_NOT_SERIALIZABLE = 1
    };

    int GetNumDeclaredMembers() const;
    const hkClassMember& GetDeclaredMember(int i) const;
    void touch() const;
    hkBool GetLastNodeFlag() const;
    hkBool hkClass_isSuperClass(const hkClass& kOther) const;
    const char* getName() const;
    unsigned int CalculateDatabaseSignature(int iFlags) const throw();
    const hkClassMember& __thiscall getMember(int i) const;
    const char* FUN_00d46d40() const;
    const hkClass* FUN_00d46d50() const;
    int FUN_00d47120() const;
    int FUN_00d46f70() const;
    const hkVariant* FUN_00d47260(const char* id) const;
    const hkClassMember& FUN_00d46f80(int i) const;

    char* m_name;
    hkClass* m_parent;
    hkInt32 m_iObjectSize;
    hkInt32 m_iNumImplementedInterfaces;
    hkSimpleArray<hkClassEnum> m_kDeclaredEnums;
    hkSimpleArray<hkClassMember> m_kDeclaredMembers;
    void* m_pDefaultObject;
    hkCustomAttributes* m_pCustomAttributes;
    hkUint32 m_flags;
    hkInt32 m_iDescribedVersion;
};
