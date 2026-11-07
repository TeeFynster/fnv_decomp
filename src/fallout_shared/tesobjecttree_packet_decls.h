// fallout_shared/tesobjecttree_packet_decls.h: declares BGSProjectile, PathingRequest, TESWorldSpace
#ifndef TESOBJECTTREE_PACKET_DECLS_H
#define TESOBJECTTREE_PACKET_DECLS_H
class BGSProjectile
{
  public:
    unsigned char prefix[0x7c];
    float explosionProximity;
    float GetExplosionProximity() const;
};
class PathingRequest
{
  public:
    unsigned char prefix[0x6c];
    float actorRadius;
    float smoothingRandomness;
    float centerRadius;
    float targetRadius;
    unsigned char gap7c[12];
    float goalZDelta;
    float GetSmoothingRandomness();
    float GetTargetRadius();
    float GetActorRadius();
    float GetCenterRadius();
    float GetGoalZDelta();
    void SetActorRadius(float value);
    void SetCenterRadius(float value);
    void SetSmoothingRandomness(float value);
};
class TESWorldSpace
{
  public:
    unsigned char prefix[0x7c];
    float field7c;
    void SetWaterLODHeight(float value);
};
#endif
