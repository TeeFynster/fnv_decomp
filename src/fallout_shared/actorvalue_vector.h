// fallout_shared/actorvalue_vector.h: declares ActorValueShortVector
#ifndef FNV_ACTORVALUE_VECTOR_H
#define FNV_ACTORVALUE_VECTOR_H
// Three signed components observed in the PC implementation.
struct ActorValueShortVector
{
    short x, y, z;
    void NiNPShortPoint3_NiNPShortPoint3(int x, int y, int z);
    ActorValueShortVector* Subtract(ActorValueShortVector* result, const ActorValueShortVector& other);
};
#endif
