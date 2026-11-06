#pragma once

#include "hkpRemoveTerminalsMoppModifier.h"

class hkpMoppCode;
class hkBitField;
typedef unsigned long hkUlong;

// Havok 7.1: RTTI vftables 0x010ec1a4 (+0) and 0x010ec1b8 (+8); constructor 0x00e487a0; 0x20 bytes.
class hkpRemoveTerminalsMoppModifier2 : public hkpRemoveTerminalsMoppModifier
{
public:
    // Havok 7.1 declares the first parameter const hkpMoppCode*. 0x00e487a0 reads [ebp+8] lazily at the call;
    // VC9 SP1 loads it at entry as soon as a pointer type is anywhere on its way to the call (parameter or
    // callee argument), so only an integer-typed parameter passed on as an integer reproduces the original.
    hkpRemoveTerminalsMoppModifier2(hkUlong moppCode, const hkBitField& enabledKeys) throw();

protected:
    virtual hkBool shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties) throw();

    const hkBitField* m_enabledKeys;  // +0x1c
};
