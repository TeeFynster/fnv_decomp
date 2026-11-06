#pragma once

#include "hkDataClassImpl.h"

class hkClass;
class hkClassMember;
class hkClassMemberDBBE;
class hkDataWorldNative;
class hkMemberInfo;
class hkMemberInfoDBBE;
class Shape;

class hkDataClassNative : public hkDataClassImpl
{
public:
    virtual ~hkDataClassNative() throw();
    virtual const hkDataWorld* getWorld() const;                                   // 0x00e587a0
    virtual const char* getName() const;                                           // 0x00dbb920
    virtual int getVersion() const;                                                // 0x00dbb930
    virtual hkDataClassImpl* getParent() const;                                    // 0x00dbb940
    virtual hkBool isSuperClass(const hkDataClassImpl* k) const;                   // 0x00dbb970
    virtual int getNumDeclaredMembers() const;                                     // 0x00dbb9d0
    virtual void getDeclaredMemberInfo(int i, hkDataClassMemberInfo& info) const;  // 0x00dbbfa0
    virtual int getDeclaredMemberIndexByName(const char* name) const;              // 0x00dbb9e0
    virtual int getNumMembers() const;                                             // 0x00dbb9f0
    virtual void getMemberInfo(int i, hkDataClassMemberInfo& info) const;          // 0x00dbbfd0
    virtual int getMemberIndexByName(const char* name) const;                      // 0x00dbba00

    // 0x00dbbe80: fills info from one hkClassMember
    void GetMemberInfo(const Shape* member, hkDataClassMemberInfo& info) const;
    void GetMemberInfo(const hkClassMemberDBBE& kMember, hkMemberInfoDBBE& kInfo) const throw();
    void GetMemberInfo(const hkClassMember& kMember, hkMemberInfo& kInfo) const throw();

    union
    {
        hkClass* m_0c;
        hkClass* m_0C;
    };
    union
    {
        hkDataWorldNative* m_10;
        hkDataWorldNative* m_pOwningWorld;
    };
};
