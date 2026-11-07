#pragma once

// Bethesda NavMeshTriangle: one navmesh triangle, 0x10 bytes (element of BSSimpleArray<NavMeshTriangle,1024>, RTTI
// vftable 0x0106ac2c; no vtable of its own). Vertices = vertex indices, Triangles = neighbour triangle (or edge extra
// info index when the edge's flag bit is set), m_uiTriangleFlags = bits 0..2 edge-extra-info, 0x40/0x10/0x200 type
// flags, 0x0FBE0000 cover bits. The methods are /Od out-of-line accessors; the FUN_ names are the units' names for
// them, with what each one does (from the exe) in the comment.
class NavMeshTriangle
{
  public:
    unsigned short GetVert_005582d0(int index);               // 0x005582d0 Vertices[index] (folded ushort-array getter)
    bool IsEdgeFlagSet(int edge);                          // 0x0068f1d0 m_uiTriangleFlags & (1 << edge)
    unsigned char IsEdgeConnected(int edge);                  // 0x0068f200 Triangles[edge] != 0xFFFF
    unsigned short GetEdgeExtraInfo_0068f2c0(int edge);                 // 0x0068f2c0 Triangles[edge]
    bool HasFlags();                                       // 0x00690770 m_uiTriangleFlags & 0x0FBE0000 (cover bits)
    void ClearFlag(int edge);                              // 0x00690790 clear bit edge, Triangles[edge] = 0xFFFF
    void SetArrayValue(int edge, unsigned short value);    // 0x006907d0 ClearFlag(edge), Triangles[edge] = value
    void SetEdge(int edge, unsigned short value);          // 0x006907d0 (same function)
    bool GetFlag(int flag);                                // 0x00691140 m_uiTriangleFlags & flag
    bool FUN_00691140(unsigned int flag);                  // 0x00691140 (same function)
    void SetFlag_00691570(unsigned int flag);                  // 0x00691570 m_uiTriangleFlags |= flag
    bool HasFlag40();                                      // 0x00693b70 m_uiTriangleFlags & 0x40
    bool IsNoLargeCreature();                                   // 0x00693b90 GetFlag(0x10)
    unsigned short GetBits13To15();                        // 0x00699790 (m_uiTriangleFlags & 0xE000) >> 13
    bool NavMeshTriangle_IsWater();                                   // 0x006a5ec0 GetFlag(0x200)

    unsigned short Vertices[3];     // +0x00
    unsigned short Triangles[3];    // +0x06
    unsigned int m_uiTriangleFlags; // +0x0C
};
