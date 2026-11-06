
// src/fallout/ai/combat/projectile_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout/ai/combat/projectile.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


extern "C" __declspec(thread) int tls_memContext;

inline int GetMemContext()
{
    return tls_memContext;
}
inline void SetMemContext(int aiMemoryContext)
{
    tls_memContext = aiMemoryContext;
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};

class SoundResult
{
  public:
    unsigned int uiID;
    ~SoundResult();
};

class SoundSystem
{
  public:
    SoundResult FUN_00ae5a50(int a, int b, int c);
};

SoundSystem* FUN_00ad9060();

class SoundWrapper
{
  public:
    SoundResult FUN_00ad7480(int a, int b, int c);
};

// @fnv 0x00ad7480
SoundResult SoundWrapper::FUN_00ad7480(int a, int b, int c)
{
    MemContextGuard kGuard(11);
    return FUN_00ad9060()->FUN_00ae5a50(a, b, c);
}
