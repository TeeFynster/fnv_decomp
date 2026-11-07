// fallout_shared/packagelocation_decls.h: declares LocationDescriptor
#ifndef FNV_PACKAGELOCATION_DECLS_H
#define FNV_PACKAGELOCATION_DECLS_H


class TESForm;

#include "../../include/PACK_LOC_TYPE.h"

// LocationDescriptor's nonvirtual, 12-byte layout is shared by the PC accessors
class LocationDescriptor
{
  public:
    char m_ucLocationType;
    unsigned int m_pLocationData;
    union
    {
        TESForm* pObject;
        TESObjectREFR* pRef;
        TESObjectCELL* pCell;
        TESForm* m_pLocationObject;
    };

    TESObjectREFR* GetLocationReference();
    TESObjectCELL* GetLocationCellReference();
    PACK_LOC_TYPE GetLocType() const;
    void PackageLocation_SetLocCell(TESObjectCELL* cell);
    void SetValue(TESForm* object);
    // Keep this distinct, community-confirmed callee address explicit.
    void PackageLocation_SetLocReference(TESObjectREFR* reference);
    void InitItem(TESForm* owner);
    TESObjectREFR* ResolveLocationReference(MobileObject* object);
};

typedef char PackageLocation_size_check[sizeof(LocationDescriptor) == 12 ? 1 : -1];
#endif
