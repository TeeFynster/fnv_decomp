#pragma once

class NiScreenElementsData__Polygon
{
  public:
    unsigned short m_usVertexCount;
    unsigned short m_usVertexOffset;
    unsigned short m_usTriangleCount;
    unsigned short m_usTriangleIndexOffset;
};
typedef char NiScreenElementsData_polygon_size_check[(sizeof(NiScreenElementsData__Polygon) == 8) ? 1 : -1];
