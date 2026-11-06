// Authored unit-local declarations for
// gamebryo2.2/corelibs/nimain/nitextureeffect.cpp.
//
// - NiFixedString (4 bytes: m_kHandle +0x0) comes from the canonical
//   generated header.
// - NiTextureEffect retains its local layout until a shared header exists.
// - NiGlobalStringTable::AddString, the InterlockedDecrement import and the
//   owned by other units and only declared here.
#ifndef FNV_NITEXTUREEFFECT_UNIT_H
#define FNV_NITEXTUREEFFECT_UNIT_H


#include "NiFixedString.h"

typedef long LONG;


extern "C" __declspec(dllimport) LONG __stdcall InterlockedDecrement(LONG volatile* lpAddend);

extern NiFixedString EmptyFS;

// Explicit in-place call to the NiPlane constructor entry (0x00a69970); a
// placement new expression changes instruction scheduling in 0x00a92710.
struct PlaneInitializer : NiPlane
{
    void Initialize(float* normal, float constant);
};

// The shared NiTextureEffect header is not available yet; retain its local layout.
class NiTextureEffect : public NiDynamicEffect
{
  public:
    NiTextureEffect() throw();
    void* InitializeEffect();
    void CopyTo(NiTextureEffect* pkClone, CloningProcess& kCloning);
    NiTextureEffect* Clone(CloningProcess& kCloning);
    static void InitializePoint3();

    NiMatrix3 m_mat1;
    float m_e8;
    float m_ec;
    float m_f0;
    NiMatrix3 m_mat2;
    float m_118;
    float m_11c;
    float m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    unsigned char m_138;
    unsigned char m_auiShapeKeys[3];
    PlaneInitializer m_sub1;
    PlaneInitializer m_sub2;

  protected:
    static NiFixedString ms_kTextureEffectNames[4];
};

#endif
