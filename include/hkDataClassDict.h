#pragma once

#include "hkDataClassImpl.h"
#include "hkBool.h"

class hkDataWorldDict;
struct hkDataMemberInfo;
struct hkRefObjDC82;
struct hkHandleDC82;
template <class T> class hkRefPtrDC82;

class hkDataClassDict : public hkDataClassImpl
{
public:
    hkDataClassDict(hkDataWorldDict* world, const char* name, int version) throw();

    virtual ~hkDataClassDict();
    virtual const hkDataWorld* getWorld() const;
    virtual const char* getName() const;
    virtual int getVersion() const;
    virtual hkDataClassImpl* getParent() const;
    virtual hkBool isSuperClass(const hkDataClassImpl* k) const;
    virtual int getNumDeclaredMembers() const;
    virtual void getDeclaredMemberInfo(int i, hkDataClassMemberInfo& info) const;
    virtual int getDeclaredMemberIndexByName(const char* name) const;
    virtual int getNumMembers() const;
    virtual void getMemberInfo(int i, hkDataClassMemberInfo& info) const;
    virtual int getMemberIndexByName(const char* name) const;

    hkDataMemberInfo* FindEntry(const char* name);
    void setParent(hkDataClassDict* p);
    void FUN_00dc9470(const char* name) throw();
    void FUN_00dc9f20(const char* name, int type,
                     const hkRefPtrDC82<hkRefObjDC82>& typeName, int count) throw();
    __declspec(noalias) void FUN_00dc9f20(const char* name, int type,
                                       const struct hkHandleDC82& typeName, int count);

    // The vptr and reference counts at +0x00 through +0x0b belong to the base.
    union
    {
        int unk0c;
        hkDataWorldDict* m_pOwningWorld;
    };
    union
    {
        int unk10;
        const char* m_name;
    };
    union
    {
        int unk14;
        int m_version;
    };
    hkDataClassDict* parent;
    int unk1c;
    int unk20;
    int unk24;
    union
    {
        hkDataMemberInfo* members;
        int unk28;
    };
    union
    {
        int count;
        int unk2c;
    };
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};
