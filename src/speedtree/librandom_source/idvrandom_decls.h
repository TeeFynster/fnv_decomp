// speedtree/librandom_source/idvrandom_decls.h: declares RandomNumberGenerator

class RandomNumberGenerator
{
  public:
    RandomNumberGenerator();
    void SeedRandomGenerator(long seed);
    float GenerateRandomFloat(float low, float high);
};
extern bool DAT_011f8eb8;
extern "C" __int64 __cdecl _time64(__int64*);
