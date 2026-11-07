// fallout_shared/facegen/bsfacegenmorph.cpp: BSFaceGenMorphStatistical, BSFaceGenMorphDifferential, GeometryVertexBuffer (14 functions)

#include "../../../include/BSFaceGenMorphDifferential.h"
#include "../../../include/BSFaceGenMorphStatistical.h"
#include "bsfacegenmorph_decls.h"

extern "C" void _Deallocate(void*);

// @fnv 0x00660690
BSFaceGenMorph::BSFaceGenMorph()
{}

// @fnv 0x006606e0
BSFaceGenMorph::~BSFaceGenMorph()
{}

// @fnv 0x00660700
BSFaceGenMorphDifferential::BSFaceGenMorphDifferential(unsigned int count)
{
    data[1] = count;
    if (data[1])
        data[0] = (unsigned int)new NiPoint3[data[1]];
    else
        data[0] = 0;
}

// @fnv 0x00660820
BSFaceGenMorphDifferential::~BSFaceGenMorphDifferential()
{
    if (data[0] != 0)
    {
        void* tmp = (void*)data[0];
        _Deallocate(tmp);
    }
}

// @fnv 0x00660970
BSFaceGenMorphStatistical::BSFaceGenMorphStatistical(unsigned int count, unsigned int firstIndex)
{
    data[1] = count;
    this->extra = firstIndex;
    if (data[1])
        data[0] = (unsigned int)new unsigned long[data[1]];
    else
        data[0] = 0;
}

// @fnv 0x00660a50
BSFaceGenMorphStatistical::~BSFaceGenMorphStatistical()
{
    if (data[0] != 0)
    {
        void* tmp = (void*)data[0];
        _Deallocate(tmp);
    }
}

// @fnv 0x0065b390
void GeometryVertexBuffer::SetVertex(unsigned int index, const NiPoint3& vertex)
{
    ((MagicCaster*)this)->MagicCaster::SetSelectedMagicItem((MagicItem*)index);
    char* pVertex = m_pkDeltas + index * stride;
    NiPoint3& result = *(NiPoint3*)pVertex;
    result = vertex;
}

// Applies a weighted morph differential to the geometry's vertex positions when geom is valid and weight is in (0,1].
// @fnv 0x00660860
void BSFaceGenMorphDifferential::ApplyDifferentialMorph(NiTriBasedGeom* geom, BSFaceGenBaseMorphExtraData* extra,
                                                        float weight)
{
    if (!geom || weight <= 0.0 || weight > 1.0)
        return;
    NiGeometryData* pData = geom->NiGeometry_GetModelData();
    GeometryVertexBuffer localC;
    pData->NiGeometryData_GetVerticesIterator(localC);
    NiPoint3 localD;
    unsigned int ItemUpdateArray = MinUnsigned(pData->NiGeometryData::GetVertexCount(), data[1]);
    for (unsigned int i = 0; i < ItemUpdateArray; ++i, localC.AddToA())
    {
        localC.CopyV3(localD);
        localD.ComputeValue_0063c8a0(((NiPoint3*)data[0])[i] * weight);
        localC.SetPoint(localD);
    }
}

// @fnv 0x00660a90
void BSFaceGenMorphStatistical::ApplyDifferentialMorph(NiTriBasedGeom* geom, BSFaceGenBaseMorphExtraData* extra,
                                                       float weight)
{
    if (!geom || weight <= 0.0 || weight > 1.0 || !extra->GetVertices())
        return;
    NiPoint3* pData = extra->GetVertices();
    NiGeometryData* pGeomData = geom->NiGeometry_GetModelData();
    GeometryVertexBuffer localC;
    pGeomData->NiGeometryData_GetVerticesIterator(localC);
    NiPoint3 localD;
    unsigned int ItemUpdateArray;
    for (unsigned int i = 0; i < data[1]; ++i)
    {
        ItemUpdateArray = ((unsigned long*)data[0])[i];
        localC.NiGeometryDataIteratorNiPoint3_Get(ItemUpdateArray, localD);
        localD.ComputeValue_0063c8a0((pData[this->extra + i] - pData[ItemUpdateArray]) * weight);
        localC.SetVertex(ItemUpdateArray, localD);
    }
}

// Returns the smaller of a 16-bit value and a 32-bit value, comparing them as unsigned integers.
// @fnv 0x00660940
unsigned int __cdecl MinUnsigned(unsigned short ausValue, unsigned int auValue)
{
    return ausValue < auValue ? ausValue : auValue;
}


struct B65EB90Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    B65EB90Entry& operator=(const B65EB90Entry& kRight);
};

class FUN_0065eb90
{
  public:
    float m_fValue;
    int unk04;
    int unk08;
    int unk0C;
    B65EB90Entry m_akEntries[3];

    FUN_0065eb90& operator=(const FUN_0065eb90& kRight);
};

// Copies m_fValue, unk04, unk08, unk0C and the three m_akEntries from kRight into this object and returns *this.
// @fnv 0x0065eb90
FUN_0065eb90& FUN_0065eb90::operator=(const FUN_0065eb90& kRight)
{
    m_fValue = kRight.m_fValue;
    unk04 = kRight.unk04;
    unk08 = kRight.unk08;
    unk0C = kRight.unk0C;
    for (unsigned int i = 0; i < 3; i++)
        m_akEntries[i] = kRight.m_akEntries[i];
    return *this;
}
