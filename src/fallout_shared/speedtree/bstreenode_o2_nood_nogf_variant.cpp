#include "../../../include/NiMatrix3.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTransform.h"
#include "../../../include/hkVector4.h"
#include "../../../include/hkRotation.h"
#include "../../../include/hkTransform.h"
#include "../../../include/NiFixedString.h"
#include "../../../include/BSTreeNode.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiNode.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BGSBodyPart.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/NiObject.h"
#include "../../../include/bhkCapsuleShape.h"
#include "../../../include/bhkCollisionObject.h"
#include "../../../include/bhkTransformShape.h"

// src/fallout_shared/speedtree/bstreenode_o2_nood_nogf_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/speedtree/bstreenode.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/speedtree/bstreenode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/speedtree/bstreenode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct GlobalObjectO2_00a7b610
{
};
GlobalObjectO2_00a7b610 g_012681b4;

#include <xmmintrin.h>
extern __declspec(thread) unsigned int t_uiMemContextC8C;

inline unsigned int GetMemContextC8C()
{
    return t_uiMemContextC8C;
}
inline void SetMemContextC8C(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContextC8C = m_uiGeometryShaderFlags;
}

inline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(GetMemContextC8C());
    SetMemContextC8C(context);
}

inline AutoMemContext::~AutoMemContext()
{
    SetMemContextC8C(m_eMemoryContext);
}

// These value constructors leave their storage uninitialized in this unit.
inline NiTransform::NiTransform() {}
inline hkTransform::hkTransform() {}

inline void hkTransform::operator=(const hkTransform& transform)
{
    m_kColumn0 = transform.m_kColumn0;
    m_kColumn1 = transform.m_kColumn1;
    m_kColumn2 = transform.m_kColumn2;
    m_vTranslation = transform.m_vTranslation;
}

extern hkTransform g_kIdentityTransformC8C;

extern "C" void __cdecl HK2NI_00624b10(NiMatrix3* pOut, const hkRotation* pIn);
extern "C" void __cdecl FUN_00458620(NiPoint3* pOut, const hkVector4* pIn);


__declspec(restrict) void* __cdecl Object_DispatchCommandFour(unsigned int uiSize);
void __cdecl FUN_00aa1460(void* p);



struct ArgC8C;

struct LinkC8C
{
    int unk00, unk04;
    NiNode* m_pkOwnerManager;
};

struct BodyC8C
{
    int unk00, unk04, unk08, unk0C, unk10;
    LinkC8C* m_pkLink;
    int unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkTransform m_kTransform;
};

class SceneObjectC8C
{
  public:
    int unk00, unk04;
    BodyC8C* m_pkBody;

    void bhkTransformShape_BuildDisplayGeometry(NiNode* pkParent, ArgC8C* iValue);
};

// @fnv 0x00c8c860
// src: XBOX_PDB 0x00c8c860
void SceneObjectC8C::bhkTransformShape_BuildDisplayGeometry(NiNode* pkParent, ArgC8C* iValue)
{
    AutoMemContext kContext(0x10);

    hkTransform kXform;
    kXform = (this && m_pkBody) ? m_pkBody->m_kTransform : g_kIdentityTransformC8C;

    NiTransform kLocal;
    HK2NI_00624b10(&kLocal.m_Rotate, &kXform.m_rotation);
    FUN_00458620(&kLocal.m_Translate, &kXform.position);

    NiNode* __restrict pkNode = new NiNode(0);
    pkNode->SetName(NiFixedString("bhkTransformShape"));
    pkParent->AttachChildInAvailableSlot(static_cast<NiAVObject*>(pkNode), true);
    pkNode->m_kLocal.m_Translate = kLocal.m_Translate;
    pkNode->m_kLocal.m_Rotate = kLocal.m_Rotate;

    if (this)
    {
        BodyC8C* pkBody = m_pkBody;
        if (pkBody)
        {
            LinkC8C* pkLink = pkBody->m_pkLink;
            if (pkLink)
            {
                NiNode* pkOwner = pkLink->m_pkOwnerManager;
                if (pkOwner)
                {
                    // This callback uses two arguments at slot 0xD4; the shared
                    // NiNode declaration does not expose that signature.
                    typedef void (__thiscall* AttachCallback)(NiNode*, NiNode*, ArgC8C*);
                    reinterpret_cast<AttachCallback>((*reinterpret_cast<void***>(pkOwner))[0xD4 / sizeof(void*)])(pkOwner, pkNode, iValue);
                }
            }
        }
    }
}
