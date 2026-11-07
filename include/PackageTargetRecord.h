#pragma once

#include "PACKAGE_OBJECT_TYPE.h"
#include "PACK_TARG_TYPE.h"

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class TESForm;
class TESObjectREFR;

// Bethesda PackageTargetRecord: a package's target (PTDT record), 0x10 bytes: allocated with operator new(0x10)
// (0x008982c0); constructor 0x0067ff70 sets type 2 and zeroes +4/+8/+0xC; scalar deleting destructor 0x007b3fa0.
// No vtable.
class PackageTargetRecord
{
  public:
    unsigned char m_uiTargetType;    // +0x00 PACK_TARG_TYPE: 0 reference, 1 object, 2 object type, ...
    unsigned char layoutPadding1[3];
    union
    {
        TESObjectREFR* m_pWorldReferenceInfo; // +0x04 type 0
        TESForm* pObject;                     // +0x04 type 1
        TESForm* pTargetForm;
        PACKAGE_OBJECT_TYPE eObjType;                         // +0x04 type 2 (PACKAGE_OBJECT_TYPE)
    };
    int iValue;                      // +0x08 count / distance
    float m_fTargetValue;            // +0x0C acquire radius

    PackageTargetRecord();                                  // 0x0067ff70
    ~PackageTargetRecord();

    void SetTargValue(int value);                           // 0x00403550
    int GetTargValue();                                     // 0x0044ddc0
    int GetTargetKind();                                    // 0x00519b00
    void SetTargAcquireRadius(float radius);                // 0x0063f790
    void Copy(PackageTargetRecord* other);                  // 0x0067ffa0
    TESObjectREFR* GetReferenceTarget();                    // 0x00680020
    TESForm* GetTargetForm();                               // 0x00680050
    int GetTargetObjectType();                              // 0x00680080
    void SetTargetKind(PACK_TARG_TYPE type);
    void SetTargetKind(int type);                           // 0x006800b0
    void SetTargetObjectReference(TESObjectREFR* reference); // 0x00680110
    void SetTargObject(TESForm* form);                      // 0x00680140
    void SetTargObjectType(int type);                       // 0x00680170
    void UpdateState_00680170(void* reference);
    void PackageTarget_Copy(PackageTargetRecord* other);           // 0x006801a0
    void PackageTarget_Save(int chunk);                           // 0x006802f0
    void InitItem(TESForm* owner);                          // 0x006803b0
    float GetTargAcquireRadius();                           // 0x0084d030
    float FUN_0084d030();
    bool GetIsValidTarget(TESForm* form);
    bool Compare(PackageTargetRecord* other);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer* buffer);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void InitLoadGame(BGSLoadFormBuffer* buffer);
};
