#pragma once

#include "hkReferencedObject.h"
#include "hkpMoppModifier.h"
#include "hkArray.h"

typedef unsigned int hkUint32;

class hkpMoppCode;
class hkpShapeContainer;
class hkAabb;

class hkpRemoveTerminalsMoppModifier : public hkReferencedObject, public hkpMoppModifier
{
public:
    hkpRemoveTerminalsMoppModifier(const hkpMoppCode* code, const hkpShapeContainer* container,
                                  const hkArray<hkUint32>& shapesToRemove) throw();
    hkpRemoveTerminalsMoppModifier(const hkpMoppCode* code, const hkAabb& aabb,
                                  const hkArray<hkUint32>& shapesToRemove) throw();
    virtual ~hkpRemoveTerminalsMoppModifier() throw();

protected:
    hkpRemoveTerminalsMoppModifier() throw();

    virtual hkBool shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties) throw();
    virtual void addTerminalRemoveInfo(int relativeMoppAddress) throw();

public:
    hkArray<hkUint32> m_kRemovedTerminalIds;           // +0x0c m_removeInfo
    const hkArray<hkUint32>* m_pTerminalIdsToRemove;  // +0x18 m_tempShapesToRemove
};
