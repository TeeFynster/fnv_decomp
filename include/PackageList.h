#pragma once

#include "MagicTarget.h"

class Actor;
class TESForm;
class TESPackage;

class PackageList
{
public:
    BSSimpleList<TESPackage*> m_kPackages;

    ~PackageList();
    void FUN_0067e3a0();
    int FUN_00726070();
    BSSimpleList<TESPackage*>* GetListOfPackages();
    BSSimpleList<TESPackage*>* GetListOfPackages() const;
    void Copy(const PackageList* src);
    void ClearPackageList();
    TESPackage* GetPackageForActor(Actor* actor);
    void CollectEligiblePackages(Actor* actor, BSSimpleList<TESPackage*>* packages, float first, float second);
    void InitItem(TESForm* form);
    void AddPackage(TESPackage* package);
    bool DiffersFrom(PackageList* other);
};
