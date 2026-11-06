#pragma once

#include "hkDataRefCounted.h"

class hkBool;
class hkDataWorld;
// The member-description record is shared with the class implementations.
struct hkDataClassMemberInfo;

// The native and dictionary tables (0x010d62fc / 0x010d73c8) share this slot order.
// Their inherited destructor precedes these eleven queries.
class hkDataClassImpl : public hkDataRefCounted
{
public:
    // Class identity, slots 1 through 4.
    virtual const hkDataWorld* getWorld() const = 0; // src: HAVOK_SRC (shape)
    virtual const char* getName() const = 0; // src: HAVOK_SRC (shape)
    virtual int getVersion() const = 0; // src: HAVOK_SRC (shape)
    virtual hkDataClassImpl* getParent() const = 0; // src: HAVOK_SRC (shape)

public:
    // Relationship test, slot 5.
    virtual hkBool isSuperClass(const hkDataClassImpl* descendant) const = 0; // src: HAVOK_SRC (shape)

public:
    // Queries restricted to this class, slots 6 through 8.
    virtual int getNumDeclaredMembers() const = 0; // src: HAVOK_SRC (shape)
    virtual void getDeclaredMemberInfo(int ordinal, hkDataClassMemberInfo& destination) const = 0; // src: HAVOK_SRC (shape)
    virtual int getDeclaredMemberIndexByName(const char* soughtName) const = 0; // src: HAVOK_SRC (shape)

public:
    // Queries including ancestors, slots 9 through 11.
    virtual int getNumMembers() const = 0; // src: HAVOK_SRC (shape)
    virtual void getMemberInfo(int ordinal, hkDataClassMemberInfo& destination) const = 0; // src: HAVOK_SRC (shape)
    virtual int getMemberIndexByName(const char* soughtName) const = 0; // src: HAVOK_SRC (shape)
};
