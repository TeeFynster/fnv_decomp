// Local geometry vertex buffer helpers.
#ifndef BSFACEGENMORPH_DECLS_H
#define BSFACEGENMORPH_DECLS_H


#include "../../../include/BSFaceGenBaseMorphExtraData.h"
#include "../../../include/BSFaceGenMorph.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiGeometryData.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTriBasedGeom.h"

class GeometryVertexBuffer
{
  public:
    char* m_pkDeltas;
    unsigned int stride;
    unsigned int third;

    void SetVertex(unsigned int, const NiPoint3&);
    GeometryVertexBuffer();
    void FUN_00534570(unsigned int, NiPoint3&);
    void CopyV3(NiPoint3&);
    void SetPoint(const NiPoint3&);
    void AddToA();
};
unsigned int MinUnsigned(unsigned int, unsigned int);
#endif
