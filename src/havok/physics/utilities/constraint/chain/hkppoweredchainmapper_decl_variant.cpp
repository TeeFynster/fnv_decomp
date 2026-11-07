
// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00e3a440: the skeleton of src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp
// with declarations corrected to what the original code does (hkpPoweredChainMapper.h: hkpPoweredChainMapper += void FUN_00e3a440(int linkIndex, int motorIndex, class hkpConstraintMotor* motor);; hkReferencedObject.h: hkReferencedObject += void RetainReference() const; void removeReference() const;). Move the function to its real unit once
// that unit declares it this way.

// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkpConstraintMotor.h"
#include "../../../../../../include/hkpPoweredChainData.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkpPoweredChainMapper.h"

class __declspec(align(16)) hkpPoweredChainDataConstraintInfo
{
  public:
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkQuaternion m_kRotationInA;
    hkQuaternion m_kRotationInB;
    hkpConstraintMotor* m_ppMotors[3];
    char m_bUseMotors;
};
class hkpPoweredChainMapperLinkInfo
{
  public:
    int firstTarget;
    int targetCount;
    void* user;
};
class hkpPoweredChainMapperTarget
{
  public:
    hkpPoweredChainData* chainData;
    int infoIndex;
};
// The approved mapper header does not yet declare this variant's function.
class hkpConstraintChainInstance;
// @fnv 0x00e3a440
// src: HAVOK_LIB 0x00e3a440
void hkpPoweredChainMapper::setMotors(int linkIndex, int motorIndex, hkpConstraintMotor* motor)
{
    hkpPoweredChainMapperLinkInfo* link = &m_ppLinks.m_data[linkIndex];
    for (int i = 0; i < link->targetCount; ++i)
    {
        hkpPoweredChainMapperTarget& target = m_kTargets.m_data[link->firstTarget + i];
        hkpPoweredChainData* data = target.chainData;
        hkpConstraintMotor* oldMotor = data->m_pConstraintInfo.m_data[target.infoIndex].m_ppMotors[motorIndex];
        if (oldMotor)
            static_cast<const hkpConstraintMotor*>(oldMotor)->removeReference();
        data->m_pConstraintInfo.m_data[target.infoIndex].m_ppMotors[motorIndex] = motor;
        if (motor)
            static_cast<const hkpConstraintMotor*>(motor)->addReference();
    }
}
