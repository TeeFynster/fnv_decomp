// fallout_shared/packagelocation_package.h: declares BGSMessageInitAccess
#ifndef FNV_PACKAGELOCATION_PACKAGE_H
#define FNV_PACKAGELOCATION_PACKAGE_H


#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESDescription.h"

// Procedure tag used by the package setter.
#include "../../include/PACKAGE_PROCEDURE_TYPE.h"
// Canonical named access view for the message icon's serialized form ID.
struct BGSMessageInitAccess : public TESForm
{
    TESFullName fullName;
    TESDescription description;
    unsigned int iconFormID;

    unsigned int GetIconFormID();
};

FNV_STATIC_ASSERT(offsetof(BGSMessageInitAccess, iconFormID) == 0x2c);

#endif
