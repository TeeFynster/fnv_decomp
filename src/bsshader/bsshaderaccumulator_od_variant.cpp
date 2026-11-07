
// src/bsshader/bsshaderaccumulator_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderaccumulator.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

class Handler
{
  public:
    virtual void __stdcall v00();
    virtual void __stdcall v01();
    virtual void __stdcall v02();
};

class FUN_00c4ed40_cls
{
  public:
    Handler* m_00;

    void ProcessState_00c4ed40();
};

// @fnv 0x00c4ed40
// src: GUESS 0x00c4ed40 (confidence: low)
void FUN_00c4ed40_cls::ProcessState_00c4ed40()
{
    if (m_00 != 0)
    {
        m_00->v02();
    }
}
