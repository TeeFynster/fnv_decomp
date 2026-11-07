// fallout_shared/pathfinding/navmesh_loadsave_decls.h: declares Pathing, TES, NavMeshPtr, BGSReconstructFormsInAllFilesMap, NavMeshObstacleMap and more

#include "navmesh_loadsave_types_NavMesh.h"
class Pathing
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void SetAltered(bool);
    bool FUN_00460340();
};
class TES
{
  public:
    Pathing* GetActiveCell();
};
extern TES* g_TES;

class ObstacleData;
// Shared PC smart-pointer operations have several existing type aliases.
template <> class NiPointer<ObstacleData>
{
  public:
    ObstacleData* m_pObject;
    NiPointer(ObstacleData*);
    NiPointer(const NiPointer&);
    ~NiPointer();
};
class NavMeshPtr
{
  public:
    NavMesh* operator->() const;
};
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
};
class NavMeshObstacleMap : public BGSReconstructFormsInAllFilesMap
{
  public:
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_ObstacleData_unsigned_short_NiPointer_ObstacleData_GetNext(void*&, unsigned short&, NiPointer<ObstacleData>&);
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NiPointer_NavMeshObstacleData_unsigned_short_NiPointer_NavMeshObstacleData_SetAt(unsigned short, NiPointer<ObstacleData>);
};
class NavMeshPOVMap : public BGSReconstructFormsInAllFilesMap
{
  public:
    void NiTMapBase_DFALL_NiTMapItem_unsigned_short_NavMeshPOVData_unsigned_short_NavMeshPOVData_GetNext(void*&, unsigned short&, NavMeshPOVData&);
    void InsertOrUpdate(unsigned short, NavMeshPOVData);
};
