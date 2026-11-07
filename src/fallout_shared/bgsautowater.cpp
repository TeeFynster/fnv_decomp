#include "../../include/AutoMemHelper.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/NiFixedString.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSMultiBound.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiPoint2.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiStencilProperty.h"

// src/fallout_shared/bgsautowater.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsautowater.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x0049ed40
void* NiStencilProperty::DestroyAndFree(unsigned int flags)
{
    this->NiStencilProperty::~NiStencilProperty();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x24);
    return this;
}

struct Flag512Receiver
{
    void NiAlphaProperty_SetBit(bool, unsigned int);
};

struct FUN_0049ed90_shell : Flag512Receiver
{
    void NiAlphaProperty_SetAlphaBlending(bool bAlpha);
};

// @fnv 0x0049ed90
// src: XBOX_PDB 0x0049ed90
void __thiscall FUN_0049ed90_shell::NiAlphaProperty_SetAlphaBlending(bool bAlpha)
{
    this->NiAlphaProperty_SetBit(bAlpha, 1);
}

// Forwards the given texture slot to FUN_00439360 with flags 0xf000 and value 0xc.
// @fnv 0x0049edb0
// src: COMMUNITY 0x0049edb0
void NiObjectNET::NiStencilProperty_SetStencilFunction(unsigned short argument0)
{
    SetField_00439360(argument0, 0xf000, 0xc);
}

// Calls FUN_00439360 with argument0, 0x380 and 7.
struct AutoWaterStencilFlags : NiObjectNET
{
    void SetStencilFunction(unsigned short value);
};

// @fnv 0x0049ede0
void AutoWaterStencilFlags::SetStencilFunction(unsigned short argument0)
{
    SetField_00439360(argument0, 0x380, 7);
}

// @fnv 0x0049ee10
// src: COMMUNITY 0x0049ee10
void NiObjectNET::NiStencilProperty_SetStencilPassZFailAction(unsigned short ausValue)
{
    SetField_00439360(ausValue, 0x70, 4);
}

// Calls FUN_00439360 with the given unsigned short and the constants 0xc00 and 0xa.
// @fnv 0x0049ee30
// src: COMMUNITY 0x0049ee30
void NiObjectNET::NiStencilProperty_SetDrawMode(unsigned short a)
{
    SetField_00439360(a, 0xc00, 0xa);
}

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void SetEnabledFlag(bool enabled);
};

void TaskQueueInterface::SetTaskFlagDWord(bool, unsigned int)
{}

// @fnv 0x0049ee80
void TaskQueueInterface::SetEnabledFlag(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x8000);
}

extern void* DAT_0101e07c;

// @fnv 0x0049ed70
void NiStencilProperty::Destroy()
{
    *reinterpret_cast<void**>(this) = &DAT_0101e07c;
    DestroyBase();
}

// Clears the bits in flags at offset 0x18 and inserts value shifted by shift into them.
// @fnv 0x00439360
// src: COMMUNITY 0x00439360
void NiObjectNET::SetField_00439360(unsigned short value, unsigned int uiMask, unsigned int shift)
{
    *(unsigned short*)((char*)this + 0x18) =
        (*(unsigned short*)((char*)this + 0x18) & ~(unsigned short)uiMask) | (value << (unsigned short)shift);
}

// @fnv 0x0049ee60
// src: COMMUNITY 0x0049ee60
void BSFadeNode::SetIgnoreFade(bool enabled)
{
    reinterpret_cast<TaskQueueInterface*>(this)->SetEnabledFlag(enabled);
}

struct FUN_0049eea0_shell
{
    char pad[0x30];
    NiPoint3 m_kPoint;
    void TESObjectREFR_SetLocationOnReferenceSimple(const NiPoint3& arPoint);
};

// @fnv 0x0049eea0
// src: XBOX_PDB 0x0049eea0
void FUN_0049eea0_shell::TESObjectREFR_SetLocationOnReferenceSimple(const NiPoint3& arPoint)
{
    m_kPoint = arPoint;
}

// These points are populated by game calls or raw copies. Avoid introducing
// default/copy constructor calls in this unoptimized unit. Array-free storage
// also preserves the original stack layout under /GS.
template <unsigned int Size> struct UninitializedStorage
{
    unsigned int word;
    UninitializedStorage<Size - sizeof(unsigned int)> remaining;
};
template <> struct UninitializedStorage<sizeof(unsigned int)>
{
    unsigned int word;
};

struct FUN_0049eed0_item
{
    NiPoint3* BSSimpleArray_NiPoint3_1024_GetAt();
};

struct FUN_0049eed0_list
{
    int FUN_0059bb30();
    FUN_0049eed0_item* Modelloader_GetReferencedThis(int index);
};

struct FUN_0049eed0_target
{
    bool ContainsMatchingTriple(NiPoint2 v);
};

// Iterates the list's items, builds a NiPoint2 from each item's NiPoint3 x/y, and returns true if the target accepts any of them.
// @fnv 0x0049eed0
bool AnyPointInListMatches(FUN_0049eed0_list* apList, FUN_0049eed0_target* apTarget)
{
    for (int i8 = 0; i8 < apList->FUN_0059bb30(); i8++)
    {
        UninitializedStorage<sizeof(NiPoint3)> p2Storage;
        (*reinterpret_cast<NiPoint3*>(&p2Storage)) = *apList->Modelloader_GetReferencedThis(i8)->BSSimpleArray_NiPoint3_1024_GetAt();
        NiPoint2 v((*reinterpret_cast<NiPoint3*>(&p2Storage)).x, (*reinterpret_cast<NiPoint3*>(&p2Storage)).y);
        if (apTarget->ContainsMatchingTriple(v))
        {
            return true;
        }
    }
    return false;
}

struct MeshPoint
{
    float x, y, z;
    bool FUN_00439090(const MeshPoint&);
    bool HasEqualComponents(const MeshPoint&);
    MeshPoint* SetComponents(float, float, float);
    void FUN_006815c0();
};
struct FUN_00a69990
{
    float x, y, z, w;
    FUN_00a69990(const MeshPoint&, const MeshPoint&);
    int ClassifyPoint(const MeshPoint*);
};
struct FUN_0049f1c0
{
    MeshPoint* data;
    int size;
    int capacity;
    int allocator;
    FUN_0049f1c0();
    ~FUN_0049f1c0();
    void FUN_008454f0(bool);
    void AddItem(const MeshPoint&);
    bool ContainsPlane(const MeshPoint&);
    void FUN_0049f510();
    void CallWithTwelve(bool(__cdecl*)(const MeshPoint&, const MeshPoint&));
    int FUN_0044ddc0();
    MeshPoint& Object_GetIndexedValue_006a1440(int);
};
struct FUN_0049f640
{
    FUN_0049f1c0* data;
    int size;
    int capacity;
    int allocator;
    FUN_0049f640();
    ~FUN_0049f640();
    void InsertPlaneWithGrowth(int, const FUN_0049f1c0&);
    FUN_0049f1c0& GetElementAddress16(int) const;
};
struct ScriptProgram
{
    bool TESObjectLAND_HasVertices();
    void TESObjectLAND_LoadVertices(int);
    void TESObjectLAND_UnLoadVertices();
    float TESObjectLAND_GetBaseHeight();
    MeshPoint** GetSecondPointer();
};
struct MeshMode
{
    unsigned char IsFlag80Set();
};
struct MeshInput
{
    ScriptProgram* TESObjectCELL_GetLand();
    float TESObjectCELL_GetWaterHeight();
    MeshMode* FUN_0054ddd0();
};
extern FUN_0049f1c0* DAT_011c57ac;
extern unsigned short DAT_0118ae90[];
extern unsigned short DAT_0118ae92[];
extern unsigned short DAT_0118ae94[];
extern int __cdecl GetCellCornerFlags(MeshInput*, MeshPoint);
extern int __cdecl NavMeshMath_SegmentPlaneIntersection(const MeshPoint&, const MeshPoint&, const MeshPoint&, const MeshPoint&, MeshPoint&);
extern bool __cdecl FloatKeyedRecord_CompareKeys(const MeshPoint&, const MeshPoint&);
extern bool __cdecl Runtime_CompareFirstFloats(const MeshPoint&, const MeshPoint&);
// Builds triangle geometry from the mesh's vertex data, clipping against a plane and collecting boundary edges into DAT_011c57ac.
// @fnv 0x0049c930
void BuildMeshBoundaryGeometry(MeshInput* pMeshInput)
{
    ScriptProgram* mesh = pMeshInput->TESObjectCELL_GetLand();
    float height = pMeshInput->TESObjectCELL_GetWaterHeight();
    if (!DAT_011c57ac)
        DAT_011c57ac = new FUN_0049f1c0;
    else
        DAT_011c57ac->FUN_008454f0(true);
    if (mesh)
    {
        bool active8 = mesh->TESObjectLAND_HasVertices();
        if (!active8)
            mesh->TESObjectLAND_LoadVertices(0);
        FUN_0049f640 _list1;
        for (int i = 0; i < 4; i++)
        {
            FUN_0049f1c0 temporary;
            _list1.InsertPlaneWithGrowth(i, temporary);
        }
        bool offset6 = false;
        float _saved = 0.0f;
        if (pMeshInput->FUN_0054ddd0() && pMeshInput->FUN_0054ddd0()->IsFlag80Set())
        {
            _saved = mesh->TESObjectLAND_GetBaseHeight();
            offset6 = true;
        }
        MeshPoint** _readObject = mesh->GetSecondPointer();
        for (int side = 0; side < 4; side++)
        {
            for (int triangle = 0; triangle < 1019; triangle++)
            {
                unsigned short _type = DAT_0118ae90[triangle];
                unsigned short _item = DAT_0118ae92[triangle];
                unsigned short _color = DAT_0118ae94[triangle];
                MeshPoint _cross = _readObject[side][_type];
                MeshPoint _delta = _readObject[side][_item];
                MeshPoint _point = _readObject[side][_color];
                if (offset6)
                {
                    _cross.z += _saved;
                    _delta.z += _saved;
                    _point.z += _saved;
                }
                if (_cross.FUN_00439090(_delta) && _cross.FUN_00439090(_point) && _delta.FUN_00439090(_point))
                {
                    MeshPoint origin6;
                    origin6.SetComponents(0.0f, 0.0f, height);
                    MeshPoint normalVal;
                    normalVal.SetComponents(0.0f, 0.0f, 1.0f);
                    FUN_00a69990 _created(normalVal, origin6);
                    unsigned short count8 = 0;
                    bool _done = false;
                    bool _active = false;
                    int _bound = GetCellCornerFlags(pMeshInput, _cross);
                    int aCount2 = GetCellCornerFlags(pMeshInput, _delta);
                    int _current = GetCellCornerFlags(pMeshInput, _point);
                    MeshPoint _orient;
                    _orient.FUN_006815c0();
                    int result3 = NavMeshMath_SegmentPlaneIntersection(_cross, _delta, origin6, normalVal, _orient);
                    if (result3 == 1)
                    {
                        if (_cross.HasEqualComponents(_orient) || _delta.HasEqualComponents(_orient))
                            _done = true;
                        DAT_011c57ac->AddItem(_orient);
                        ++count8;
                        if ((_bound & 1) && (aCount2 & 1))
                            _list1.GetElementAddress16(0).AddItem(_orient);
                        else if ((_bound & 2) && (aCount2 & 2))
                            _list1.GetElementAddress16(1).AddItem(_orient);
                        else if ((_bound & 4) && (aCount2 & 4))
                            _list1.GetElementAddress16(2).AddItem(_orient);
                        else if ((_bound & 8) && (aCount2 & 8))
                            _list1.GetElementAddress16(3).AddItem(_orient);
                    }
                    else if (result3 == -1)
                    {
                        _active = true;
                        DAT_011c57ac->AddItem(_cross);
                        DAT_011c57ac->AddItem(_delta);
                        count8 += 2;
                    }
                    result3 = NavMeshMath_SegmentPlaneIntersection(_cross, _point, origin6, normalVal, _orient);
                    if (result3 == 1)
                    {
                        bool add = true;
                        if (_cross.HasEqualComponents(_orient) || _point.HasEqualComponents(_orient))
                        {
                            if (_done || _active)
                                add = false;
                            else
                                _done = true;
                        }
                        if (add)
                        {
                            DAT_011c57ac->AddItem(_orient);
                            ++count8;
                            if ((_bound & 1) && (_current & 1))
                                _list1.GetElementAddress16(0).AddItem(_orient);
                            else if ((_bound & 2) && (_current & 2))
                                _list1.GetElementAddress16(1).AddItem(_orient);
                            else if ((_bound & 4) && (_current & 4))
                                _list1.GetElementAddress16(2).AddItem(_orient);
                            else if ((_bound & 8) && (_current & 8))
                                _list1.GetElementAddress16(3).AddItem(_orient);
                        }
                    }
                    else if (result3 == -1)
                    {
                        _active = true;
                        for (int discard = 0; discard < count8; discard++)
                            DAT_011c57ac->FUN_0049f510();
                        DAT_011c57ac->AddItem(_cross);
                        DAT_011c57ac->AddItem(_point);
                        count8 = 2;
                    }
                    result3 = NavMeshMath_SegmentPlaneIntersection(_delta, _point, origin6, normalVal, _orient);
                    if (result3 == 1)
                    {
                        bool addThird = true;
                        if (_delta.HasEqualComponents(_orient) || (_point.HasEqualComponents(_orient) && (_done || _active)))
                            addThird = false;
                        if (addThird)
                        {
                            DAT_011c57ac->AddItem(_orient);
                            ++count8;
                            if ((aCount2 & 1) && (_current & 1))
                                _list1.GetElementAddress16(0).AddItem(_orient);
                            else if ((aCount2 & 2) && (_current & 2))
                                _list1.GetElementAddress16(1).AddItem(_orient);
                            else if ((aCount2 & 4) && (_current & 4))
                                _list1.GetElementAddress16(2).AddItem(_orient);
                            else if ((aCount2 & 8) && (_current & 8))
                                _list1.GetElementAddress16(3).AddItem(_orient);
                        }
                    }
                    else if (result3 == -1)
                    {
                        _active = true;
                        for (int discardThird = 0; discardThird < count8; discardThird++)
                            DAT_011c57ac->FUN_0049f510();
                        DAT_011c57ac->AddItem(_delta);
                        DAT_011c57ac->AddItem(_point);
                        count8 = 2;
                    }
                    if (count8 != 2)
                    {
                        for (int discardAll = 0; discardAll < count8; discardAll++)
                            DAT_011c57ac->FUN_0049f510();
                    }
                    if (_bound == 9)
                    {
                        if (_created.ClassifyPoint(&_cross) == 2)
                        {
                            _cross.z = height;
                            if (!_list1.GetElementAddress16(0).ContainsPlane(_cross))
                                _list1.GetElementAddress16(0).AddItem(_cross);
                            if (!_list1.GetElementAddress16(3).ContainsPlane(_cross))
                                _list1.GetElementAddress16(3).AddItem(_cross);
                        }
                    }
                    else if (_bound == 10)
                    {
                        if (_created.ClassifyPoint(&_cross) == 2)
                        {
                            _cross.z = height;
                            if (!_list1.GetElementAddress16(1).ContainsPlane(_cross))
                                _list1.GetElementAddress16(1).AddItem(_cross);
                            if (!_list1.GetElementAddress16(3).ContainsPlane(_cross))
                                _list1.GetElementAddress16(3).AddItem(_cross);
                        }
                    }
                    else if (_bound == 5)
                    {
                        if (_created.ClassifyPoint(&_cross) == 2)
                        {
                            _cross.z = height;
                            if (!_list1.GetElementAddress16(0).ContainsPlane(_cross))
                                _list1.GetElementAddress16(0).AddItem(_cross);
                            if (!_list1.GetElementAddress16(2).ContainsPlane(_cross))
                                _list1.GetElementAddress16(2).AddItem(_cross);
                        }
                    }
                    else if (_bound == 6)
                    {
                        if (_created.ClassifyPoint(&_cross) == 2)
                        {
                            _cross.z = height;
                            if (!_list1.GetElementAddress16(1).ContainsPlane(_cross))
                                _list1.GetElementAddress16(1).AddItem(_cross);
                            if (!_list1.GetElementAddress16(2).ContainsPlane(_cross))
                                _list1.GetElementAddress16(2).AddItem(_cross);
                        }
                    }
                    if (aCount2 == 9)
                    {
                        if (_created.ClassifyPoint(&_delta) == 2)
                        {
                            _delta.z = height;
                            if (!_list1.GetElementAddress16(0).ContainsPlane(_delta))
                                _list1.GetElementAddress16(0).AddItem(_delta);
                            if (!_list1.GetElementAddress16(3).ContainsPlane(_delta))
                                _list1.GetElementAddress16(3).AddItem(_delta);
                        }
                    }
                    else if (aCount2 == 10)
                    {
                        if (_created.ClassifyPoint(&_delta) == 2)
                        {
                            _delta.z = height;
                            if (!_list1.GetElementAddress16(1).ContainsPlane(_delta))
                                _list1.GetElementAddress16(1).AddItem(_delta);
                            if (!_list1.GetElementAddress16(3).ContainsPlane(_delta))
                                _list1.GetElementAddress16(3).AddItem(_delta);
                        }
                    }
                    else if (aCount2 == 5)
                    {
                        if (_created.ClassifyPoint(&_delta) == 2)
                        {
                            _delta.z = height;
                            if (!_list1.GetElementAddress16(0).ContainsPlane(_delta))
                                _list1.GetElementAddress16(0).AddItem(_delta);
                            if (!_list1.GetElementAddress16(2).ContainsPlane(_delta))
                                _list1.GetElementAddress16(2).AddItem(_delta);
                        }
                    }
                    else if (aCount2 == 6)
                    {
                        if (_created.ClassifyPoint(&_delta) == 2)
                        {
                            _delta.z = height;
                            if (!_list1.GetElementAddress16(1).ContainsPlane(_delta))
                                _list1.GetElementAddress16(1).AddItem(_delta);
                            if (!_list1.GetElementAddress16(2).ContainsPlane(_delta))
                                _list1.GetElementAddress16(2).AddItem(_delta);
                        }
                    }
                    if (_current == 9)
                    {
                        if (_created.ClassifyPoint(&_point) == 2)
                        {
                            _point.z = height;
                            if (!_list1.GetElementAddress16(0).ContainsPlane(_point))
                                _list1.GetElementAddress16(0).AddItem(_point);
                            if (!_list1.GetElementAddress16(3).ContainsPlane(_point))
                                _list1.GetElementAddress16(3).AddItem(_point);
                        }
                    }
                    else if (_current == 10)
                    {
                        if (_created.ClassifyPoint(&_point) == 2)
                        {
                            _point.z = height;
                            if (!_list1.GetElementAddress16(1).ContainsPlane(_point))
                                _list1.GetElementAddress16(1).AddItem(_point);
                            if (!_list1.GetElementAddress16(3).ContainsPlane(_point))
                                _list1.GetElementAddress16(3).AddItem(_point);
                        }
                    }
                    else if (_current == 5)
                    {
                        if (_created.ClassifyPoint(&_point) == 2)
                        {
                            _point.z = height;
                            if (!_list1.GetElementAddress16(0).ContainsPlane(_point))
                                _list1.GetElementAddress16(0).AddItem(_point);
                            if (!_list1.GetElementAddress16(2).ContainsPlane(_point))
                                _list1.GetElementAddress16(2).AddItem(_point);
                        }
                    }
                    else if (_current == 6)
                    {
                        if (_created.ClassifyPoint(&_point) == 2)
                        {
                            _point.z = height;
                            if (!_list1.GetElementAddress16(1).ContainsPlane(_point))
                                _list1.GetElementAddress16(1).AddItem(_point);
                            if (!_list1.GetElementAddress16(2).ContainsPlane(_point))
                                _list1.GetElementAddress16(2).AddItem(_point);
                        }
                    }
                }
            }
        }
        if (!active8)
            mesh->TESObjectLAND_UnLoadVertices();
        for (int boundary = 0; boundary < 4; boundary++)
        {
            if (boundary == 0 || boundary == 1)
                _list1.GetElementAddress16(boundary).CallWithTwelve(FloatKeyedRecord_CompareKeys);
            else
                _list1.GetElementAddress16(boundary).CallWithTwelve(Runtime_CompareFirstFloats);
            for (int pair = 0; pair < _list1.GetElementAddress16(boundary).FUN_0044ddc0(); pair += 2)
            {
                if (_list1.GetElementAddress16(boundary).FUN_0044ddc0() > pair + 1)
                {
                    DAT_011c57ac->AddItem(_list1.GetElementAddress16(boundary).Object_GetIndexedValue_006a1440(pair));
                    DAT_011c57ac->AddItem(_list1.GetElementAddress16(boundary).Object_GetIndexedValue_006a1440(pair + 1));
                }
            }
        }
    }
}

struct Pt
{
    float x, y, z;
    Pt& operator+=(const NiPoint3& other);
};
struct CellOrigin
{
    NiPoint3 TESObjectLAND_GetWorldOffsetForBlock(bool interior);
};
struct Cell
{
    CellOrigin* TESObjectCELL_GetLand();
    int FUN_00544c30();
    int FUN_00544c60();
};
// Offsets point by the cell origin, compares it against the four cell corners and returns a bitmask of which edges/corners it matches.
// @fnv 0x0049ef60
unsigned int __cdecl GetCellCornerFlags(Cell* cell, Pt point)
{
    unsigned int f = 0;  // Edge mask: west=1, east=2, north=4, south=8.
    // Translate the point into the cell's coordinate system.
    NiPoint3 i = cell->TESObjectCELL_GetLand()->TESObjectLAND_GetWorldOffsetForBlock(false);
    point += i;
    // Cell corners: p=southwest, a=southeast, s=northwest, h=northeast.
    NiPoint2 p(float(cell->FUN_00544c30() << 12), float(cell->FUN_00544c60() << 12));
    NiPoint2 a(float((cell->FUN_00544c30() << 12) + 4096), float(cell->FUN_00544c60() << 12));
    NiPoint2 s(float(cell->FUN_00544c30() << 12), float((cell->FUN_00544c60() << 12) + 4096));
    NiPoint2 h(float((cell->FUN_00544c30() << 12) + 4096), float((cell->FUN_00544c60() << 12) + 4096));
    if (point.x == p.x && point.y == p.y)
        f |= 9;
    else if (point.x == a.x && point.y == a.y)
        f |= 10;
    else if (point.x == s.x && point.y == s.y)
        f |= 5;
    else if (point.x == h.x && point.y == h.y)
        f |= 6;
    else if (point.x == p.x)
        f |= 1;
    else if (point.x == a.x)
        f |= 2;
    else if (point.y == p.y)
        f |= 8;
    else if (point.y == h.y)
        f |= 4;
    return f;
}

// Adapted from earlier contributor's unverified source; revised using official checker.
#include "../../include/NiMemObject.h"
struct UpdData
{
    float m_00;
    bool m_04;
    float m_08;
    void NiUpdateData(float, bool, bool);
};
struct AVObj
{
    void AssignFixedString(const NiFixedString&);
    void NiAVObject_AttachProperty(void*);
    int FUN_0049ec60();
    unsigned short NiGeometry_GetVertexCount() const;
};
struct NodeObj
{
    ~NodeObj();
    AVObj* GetModel_0056c7f0();
    AVObj* NiTimeController_GetNext();
    int FUN_0049e3e0(unsigned int);
};
struct BufObj
{
    float x;
    float y;
    float z;
    NiPoint3* TESObjectLAND_GetWorldOffsetForBlock();
};
struct WaterForm
{
    void* GetPlaceableAutoWater();
};
struct ParamObj
{
    float TESObjectCELL_GetWaterHeight();
    BufObj TESObjectCELL_GetLand(int);
    WaterForm* Actor_GetRadiationLevel();
    void FUN_00548230(void*, bool);
};
struct Mgr
{
    void* Modelloader_GetReferencedThis();
    void* DereferenceIfNotNull(void*);
    void* AddEight(void*);
    void* FUN_0049f590(void**);
};
extern Mgr* DAT_011c57b0;
struct SettingObj
{
    unsigned char* FUN_00408d60();
};
extern SettingObj DAT_011cc5a8;
float __cdecl BSMIN(float, float);
float __cdecl BSMAX_00404010(float, float);
namespace std {
float abs(float);
}
struct FUN_0055a2f0
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void vslot2e();
    virtual void vslot2f();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void vslot37();
    virtual void vslot38();
    virtual void vslot39();
    virtual void vslot3a();
    virtual void vslot3b();
    virtual void vslot3c();
    virtual void vslot3d();
    virtual void vslot3e();
    virtual void vslot3f();
    virtual void vslot40();
    virtual void vslot41();
    virtual void vslot42();
    virtual void vslot43();
    virtual void vslot44();
    virtual void vslot45();
    virtual void vslot46();
    virtual void vslot47();
    virtual void vslot48();
    virtual void vslot49();
    virtual void vslot4a();
    virtual void vslot4b();
    virtual void vslot4c();
    virtual void vslot4d();
    virtual void vslot4e();
    virtual void vslot4f();
    virtual void vslot50();
    virtual void vslot51();
    virtual void vslot52();
    virtual void vslot53();
    virtual void vslot54();
    virtual void vslot55();
    virtual void vslot56();
    virtual void vslot57();
    virtual void vslot58();
    virtual void vslot59();
    virtual void vslot5a();
    virtual void vslot5b();
    virtual void vslot5c();
    virtual void vslot5d();
    virtual void vslot5e();
    virtual void vslot5f();
    virtual void vslot60();
    virtual void vslot61();
    virtual void vslot62();
    virtual void vslot63();
    virtual void vslot64();
    virtual void vslot65();
    virtual void vslot66();
    virtual void vslot67();
    virtual void vslot68();
    virtual void vslot69();
    virtual void vslot6a();
    virtual void vslot6b();
    virtual void vslot6c();
    virtual void vslot6d();
    virtual void vslot6e();
    virtual void vslot6f();
    virtual void vslot70();
    virtual void vslot71();
    virtual void vslot72();
    virtual void FUN_vt1cc(void*, bool);
    FUN_0055a2f0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    void TESObjectREFR_SetObjectReference(void*);
    void FUN_00484490();
    void TESObjectREFR_InitHavokForPlaceableWater();
};
struct FUN_00b6abb0 : NiMemObject
{
    FUN_00b6abb0();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
};
// This allocation uses the game's sized cleanup overload on constructor failure.
// Hide the shared unsized overload only at this allocation site.
struct AutoWaterFadeNode : BSFadeNode
{
    AutoWaterFadeNode();
    static void operator delete(void* memory, unsigned int size);
};

struct FUN_00c37ec0 : NiMemObject
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void FUN_vtb8(void*);
    FUN_00c37ec0();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    void BSMultiBound_SetHalfExtents(const NiPoint3&);
};
struct FUN_00c46970 : NiMemObject
{
    virtual void vslot00();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot0a();
    virtual void vslot0b();
    virtual void vslot0c();
    virtual void vslot0d();
    virtual void vslot0e();
    virtual void vslot0f();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot1a();
    virtual void vslot1b();
    virtual void vslot1c();
    virtual void vslot1d();
    virtual void vslot1e();
    virtual void vslot1f();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot2a();
    virtual void vslot2b();
    virtual void vslot2c();
    virtual void vslot2d();
    virtual void vslot2e();
    virtual void vslot2f();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void FUN_vtdc(void*, bool);
    FUN_00c46970();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    void FUN_00439920(void*);
};
void __cdecl FUN_00b57e30(void*, int, int);

// @fnv 0x0049e410
void __cdecl CreateAutoWaterNode(ParamObj* a0)
{
    AutoMemHelper aex(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSAutoWater.cpp", 717);
    void* s;
    {
        void* i;
        // Preserve the original packing of the origin and its water-state flag.
        struct
        {
            UninitializedStorage<sizeof(NiPoint3)> position;
            unsigned char reserved0, reserved1, reserved2;
            bool hasWaterForm;
        } origin;
        {
            NodeObj* nodeX;
            if (0 != DAT_011c57b0)
            {
                (*reinterpret_cast<NiPoint3*>(&origin.position)).Set(a0->TESObjectCELL_GetLand(0).TESObjectLAND_GetWorldOffsetForBlock()->x, a0->TESObjectCELL_GetLand(0).TESObjectLAND_GetWorldOffsetForBlock()->y,
                                 a0->TESObjectCELL_GetWaterHeight());
                origin.hasWaterForm = false;
                s = DAT_011c57b0->Modelloader_GetReferencedThis();
                i = 0;
                while (0 != s)
                {
                    i = DAT_011c57b0->DereferenceIfNotNull(s);
                    if (!!s)
                    {
                        nodeX = *(NodeObj**)DAT_011c57b0->AddEight(s);
                        if (nodeX->GetModel_0056c7f0() != 0 && nodeX->NiTimeController_GetNext() != 0)
                        {
                            {
                                UninitializedStorage<sizeof(NiPoint3)> nStorage;
                                {
                                    UninitializedStorage<sizeof(NiPoint3)> pt44Storage;
                                    {
                                        float minZ;
                                        {
                                            float maxY;
                                            {
                                                BSMultiBound* p6c;
                                                {
                                                    AVObj* bufA;
                                                    {
                                                        UpdData res;
                                                        {
                                                            NiPoint3* verts;
                                                            {
                                                                float val;
                                                                {
                                                                    NiStencilProperty* minY;
                                                                    {
                                                                        BSFadeNode* p80;
                                                                        {
                                                                            FUN_00c46970* oldNode2;
                                                                            {
                                                                                float minX;
                                                                                {
                                                                                    FUN_00c37ec0* p7c;
                                                                                    {
                                                                                        FUN_00b6abb0* geom;
                                                                                        {
                                                                                            FUN_0055a2f0* p84;
                                                                                            {
                                                                                                float p50;
                                                                                                {
                                                                                                    float n7c;
                                                                                                    {
                                                                                                        int b;
                                                                                                        {
                                                                                                            UninitializedStorage<sizeof(NiPoint3)> oldNodeStorage;
                                                                                                            nodeX
                                                                                                                ->GetModel_0056c7f0()
                                                                                                                ->AssignFixedString(
                                                                                                                    NiFixedString(
                                                                                                                        "AutoWaterNode"));
                                                                                                            nodeX
                                                                                                                ->NiTimeController_GetNext()
                                                                                                                ->AssignFixedString(
                                                                                                                    NiFixedString(
                                                                                                                        "AutoWater"));
                                                                                                            p84 =
                                                                                                                new FUN_0055a2f0;
                                                                                                            geom =
                                                                                                                new FUN_00b6abb0;
                                                                                                            nodeX
                                                                                                                ->NiTimeController_GetNext()
                                                                                                                ->NiAVObject_AttachProperty(
                                                                                                                    geom);
                                                                                                            FUN_00b57e30(
                                                                                                                nodeX
                                                                                                                    ->GetModel_0056c7f0(),
                                                                                                                0, 0);
                                                                                                            minY =
                                                                                                                new NiStencilProperty;
                                                                                                            minY->NiStencilProperty_SetDrawMode(
                                                                                                                3);
                                                                                                            nodeX
                                                                                                                ->NiTimeController_GetNext()
                                                                                                                ->NiAVObject_AttachProperty(
                                                                                                                    minY);
                                                                                                            p84->TESObjectREFR_SetObjectReference(
                                                                                                                a0->Actor_GetRadiationLevel()
                                                                                                                    ->GetPlaceableAutoWater());
                                                                                                            p80 =
                                                                                                                new AutoWaterFadeNode;
                                                                                                            p80->SetIgnoreFade(
                                                                                                                true);
                                                                                                            p84->FUN_vt1cc(
                                                                                                                p80,
                                                                                                                true);
                                                                                                            p80->NiAVObject_SetTranslate(
                                                                                                                (*reinterpret_cast<NiPoint3*>(&origin.position)));
                                                                                                            ((FUN_0049eea0_shell*)
                                                                                                                 p84)
                                                                                                                ->TESObjectREFR_SetLocationOnReferenceSimple(
                                                                                                                    (*reinterpret_cast<NiPoint3*>(&origin.position)));
                                                                                                            p7c =
                                                                                                                new FUN_00c37ec0;
                                                                                                            val = 0.0f;
                                                                                                            maxY = 0.0f;
                                                                                                            n7c = 0.0f;
                                                                                                            minX = 0.0f;
                                                                                                            p50 = 0.0f;
                                                                                                            minZ = 0.0f;
                                                                                                            bufA =
                                                                                                                nodeX
                                                                                                                    ->NiTimeController_GetNext();
                                                                                                            verts =
                                                                                                                (NiPoint3*)bufA
                                                                                                                    ->FUN_0049ec60();
                                                                                                            for (
                                                                                                                b = 0;
                                                                                                                b <
                                                                                                                (int)bufA
                                                                                                                    ->NiGeometry_GetVertexCount();
                                                                                                                b++)
                                                                                                            {
                                                                                                                (*reinterpret_cast<NiPoint3*>(&oldNodeStorage)) = verts
                                                                                                                    [b];
                                                                                                                if (0 <
                                                                                                                    b)
                                                                                                                {
                                                                                                                    val = BSMIN(
                                                                                                                        val,
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .x);
                                                                                                                    maxY = BSMIN(
                                                                                                                        maxY,
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .y);
                                                                                                                    n7c = BSMIN(
                                                                                                                        n7c,
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .z);
                                                                                                                    minX = BSMAX_00404010(
                                                                                                                        minX,
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .x);
                                                                                                                    p50 = BSMAX_00404010(
                                                                                                                        p50,
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .y);
                                                                                                                    minZ = BSMAX_00404010(
                                                                                                                        minZ,
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .z);
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    minX =
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .x;
                                                                                                                    val =
                                                                                                                        minX;
                                                                                                                    p50 =
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .y;
                                                                                                                    maxY =
                                                                                                                        p50;
                                                                                                                    minZ =
                                                                                                                        (*reinterpret_cast<NiPoint3*>(&oldNodeStorage))
                                                                                                                            .z;
                                                                                                                    n7c =
                                                                                                                        minZ;
                                                                                                                }
                                                                                                            }
                                                                                                            (*reinterpret_cast<NiPoint3*>(&pt44Storage)).Set(
                                                                                                                (float)std::abs((
                                                                                                                    float)((minX -
                                                                                                                            val) /
                                                                                                                           2.0)),
                                                                                                                (float)std::abs((
                                                                                                                    float)((p50 -
                                                                                                                            maxY) /
                                                                                                                           2.0)),
                                                                                                                (float)std::abs((
                                                                                                                    float)((minZ -
                                                                                                                            n7c) /
                                                                                                                           2.0)));
                                                                                                            (*reinterpret_cast<NiPoint3*>(&nStorage)).Set(
                                                                                                                minX -
                                                                                                                    (*reinterpret_cast<NiPoint3*>(&pt44Storage)).x,
                                                                                                                p50 -
                                                                                                                    (*reinterpret_cast<NiPoint3*>(&pt44Storage)).y,
                                                                                                                minZ -
                                                                                                                    (*reinterpret_cast<NiPoint3*>(&pt44Storage)).z);
                                                                                                            (*reinterpret_cast<NiPoint3*>(&nStorage)).ComputeValue_0063c8a0(
                                                                                                                (*reinterpret_cast<NiPoint3*>(&origin.position)));
                                                                                                            p7c->FUN_vtb8(
                                                                                                                &(*reinterpret_cast<NiPoint3*>(&nStorage)));
                                                                                                            p7c->BSMultiBound_SetHalfExtents(
                                                                                                                (*reinterpret_cast<NiPoint3*>(&pt44Storage)));
                                                                                                            p6c =
                                                                                                                new BSMultiBound;
                                                                                                            p6c->BSMultiBound_SetShape(
                                                                                                                p7c);
                                                                                                            oldNode2 =
                                                                                                                new FUN_00c46970;
                                                                                                            oldNode2
                                                                                                                ->FUN_00439920(
                                                                                                                    p6c);
                                                                                                            p80->AttachChildInAvailableSlot(
                                                                                                                reinterpret_cast<NiAVObject*>(oldNode2),
                                                                                                                true);
                                                                                                            oldNode2->FUN_vtdc(
                                                                                                                nodeX
                                                                                                                    ->GetModel_0056c7f0(),
                                                                                                                true);
                                                                                                            res.NiUpdateData(
                                                                                                                0.0f,
                                                                                                                false,
                                                                                                                false);
                                                                                                            p80->NiAVObject_Update(
                                                                                                                &res);
                                                                                                            a0->FUN_00548230(
                                                                                                                p84,
                                                                                                                false);
                                                                                                            p84->FUN_00484490();
                                                                                                            if (*DAT_011cc5a8
                                                                                                                        .FUN_00408d60() !=
                                                                                                                    0 &&
                                                                                                                !origin.hasWaterForm)
                                                                                                            {
                                                                                                                p84->TESObjectREFR_InitHavokForPlaceableWater();
                                                                                                                origin.hasWaterForm =
                                                                                                                    true;
                                                                                                            }
                                                                                                            delete nodeX;
                                                                                                            nodeX = 0;
                                                                                                            DAT_011c57b0
                                                                                                                ->FUN_0049f590(
                                                                                                                    &s);
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    s = i;
                }
            }
        }
    }
}

extern float DAT_0106c288;
extern double DAT_01012060;
extern double DAT_01012070;

float __cdecl FUN_00408840(float v);
NiPoint3 __cdecl FUN_004a3760(float t, const NiPoint3& point);

// Computes the intersection of the line through p0 and p1 with the plane defined by (*reinterpret_cast<NiPoint3*>(&p2Storage)) and p3, writing the result to out.
// @fnv 0x006b9a10
// src: COMMUNITY 0x006b9a10
int __cdecl NavMeshMath_SegmentPlaneIntersection(const NiPoint3& apStart, const NiPoint3& apEnd, const NiPoint3& apPlanePoint,
                         const NiPoint3& apPlaneNormal, NiPoint3& out)
{
    float f3 = DAT_0106c288;
    float f2;
    float f28;
    float f6;

    NiPoint3 v1 = apEnd.SubtractIntoVector(apStart);
    NiPoint3 v6 = apStart.SubtractIntoVector(apPlanePoint);
    f28 = apPlaneNormal.DotProduct(v1);
    f2 = -apPlaneNormal.DotProduct(v6);
    if (f3 > FUN_00408840(f28))
    {
        if (f2 == DAT_01012060)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    f6 = f2 / f28;
    if (f6 < DAT_01012060 || f6 > DAT_01012070)
    {
        return 0;
    }
    out = apStart.FUN_00439e90(FUN_004a3760(f6, v1));
    return 1;
}

struct WaterPointerList
{
    void FUN_004ed900();
};
void BuildWaterSurfaces(MeshInput*);

// Builds auto-water boundary geometry and creates the auto-water node for the given mesh input.
// @fnv 0x0049c860
// src: XBOX_PDB 0x0049c860
void BGSAutoWater_GeneratePlaceableWaterForCell(MeshInput* apMeshInput)
{
    AutoMemHelper context(29, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSAutoWater.cpp", 83);
    if (!apMeshInput || !reinterpret_cast<TESObjectCELL*>(apMeshInput)->HasWater())
        return;
    if (DAT_011c57ac)
        DAT_011c57ac->FUN_008454f0(true);
    if (DAT_011c57b0)
        reinterpret_cast<WaterPointerList*>(DAT_011c57b0)->FUN_004ed900();
    BuildMeshBoundaryGeometry(apMeshInput);
    BuildWaterSurfaces(apMeshInput);
    CreateAutoWaterNode(reinterpret_cast<ParamObj*>(apMeshInput));
}
