// src/havok/physics/constraintsolver/jacobian/hkpjacobianchainschemas.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/jacobian/hkpjacobianchainschemas.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd13e0
// src: GUESS 0x00dd13e0 (confidence: low)
char* Object_GetElementAddress_00dd13e0(char* base, int index)
{
    return base + 0x20 + ((index * 9) << 4);
}

struct DD13C0Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_data;
};

// @fnv 0x00dd13c0
// src: XBOX_PDB 0x00dd13c0
int* __cdecl hkJacobianBallSocketChainSchema_getJacobians(DD13C0Object* object)
{
    return &object->m_data;
}

// @fnv 0x00dd13b0
// src: XBOX_PDB 0x00dd13b0
int __cdecl hkJacobianStiffSpringChainSchema_getJacobians(unsigned int arg0)
{
    return (int)(arg0 + 16u);
}

// @fnv 0x00dd13d0
// src: COMMUNITY 0x00dd13d0
char* _tolower_00dd13d0(char* base)
{
    return base + 0x20;
}
