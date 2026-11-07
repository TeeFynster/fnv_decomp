// fallout_shared/teleportdata_decls.h: declares DoorTeleportLoadData, DoorTeleportSpaceReceiver, DoorTeleportSpaceOwner, DoorCell and more
#ifndef FNV_TELEPORTDATA_DECLS_H
#define FNV_TELEPORTDATA_DECLS_H
#include "../../include/layout_support.h"
#include "ActorPackageContext.h"
#include "../../include/TESForm.h"
#include "NiPoint3.h"
#include "TESFile.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);
struct DoorTeleportLoadData
{
    TESObjectREFR* door;
    NiPoint3 position;
    NiPoint3 rotation;
    unsigned char flags;
    DoorTeleportLoadData();  // 0x0055a400
    void SwapEndian();
};
class DoorTeleportSpaceReceiver
{
  public:
    TESForm* IsPathingComplete(void);
};
struct DoorTeleportSpaceOwner
{
    unsigned char padding[0x190];
    DoorTeleportSpaceReceiver* receiver;
};
class DoorCell
{
  public:
    TESForm* GetOwner(void);
    TESWorldSpace* GetParentWorldSpace(void);
    void SetTempPublic(bool set);
};
class DoorCellProvider
{
  public:
    virtual DoorCell* vfn_0(void);
};
class TESFormLookup
{
  public:
    static TESForm* GetFormByID(unsigned int formID);
};
class TESFormTypeView
{
  public:
    ENUM_FORM_ID GetFormType(void) const;
};
extern "C"
{
    void FNV_GetFile(void);
    void FNV_AddCompileIndex(void);
    void FNV_GetFormByNumericID(void);
    void FNV_DynamicCast(void);
    void FNV_GetObjectReference(void);
    void FNV_GetFormType(void);
    void FNV_GetFormID(void);
    void FNV_Warning(void);
    void FNV_Finite(void);
    void FNV_IsNaN(void);
    extern const char FNV_NoDoor[];
    extern const char FNV_InvalidDoor[];
    extern const char FNV_BadLocation[];
    extern const char FNV_BadAngle[];
    extern const unsigned char FNV_FormTypeNames[];
    extern const unsigned char FNV_NiPoint3Zero[];
    extern const unsigned char FNV_RTTI_TESObjectREFR[];
    extern const unsigned char FNV_RTTI_TESForm[];
}
#endif
