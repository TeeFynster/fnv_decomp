#include "../../../../include/NiBSPNode.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiSphere.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/StrArr.h"

// The game inlines these point operations in this unit.
inline const float& NiPoint3::Zref() const { return z; }
inline const NiPoint3& NiPoint3::Value() const { return *this; }
inline NiPoint3::NiPoint3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth) {}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const { return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z); }
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const { return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z); }
inline float NiPoint3::operator*(const NiPoint3& p) const { return x * p.x + y * p.y + z * p.z; }
inline NiPoint3 NiPoint3::operator/(float s) const { float inv = 1.0f / s; return NiPoint3(x * inv, y * inv, z * inv); }

// src/gamebryo2.2/corelibs/nimain/nibspnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibspnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a9a710
// src: XBOX_PDB 0x00a9a710
void NiBSPNode::LoadBinary_00a9a710(NiStream& stream)
{
    NiNode::LoadBinary(stream);
    m_pSphere.LoadBinary(stream);
}

// @fnv 0x00a9a840
// src: XBOX_PDB 0x00a9a840
void __thiscall NiBSPNode::UpdateWorldData_00a9a840(NiUpdateData& aUpdateData)
{
    NiAVObject::UpdateWorldData(aUpdateData);
    UpdateWorldPlane();
}

struct GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f5f54;

// @fnv 0x00a9adc0
// src: COMMUNITY 0x00a9adc0
GlobalObjectO2_00a7b610* __cdecl NiBSPNode_GetRTTI()
{
    return &g_011f5f54;
}

// Bind members missing from the shared declarations as function symbols, using
// typed thiscall calls below. Undeclared BSP operations keep ECX as their node
// parameter and leave EDX unused so their stack arguments retain the original ABI.
void __cdecl DestroyNode();
void __cdecl _delete(void*, unsigned int);

// Calls FUN_00a5e930 on this, deletes this with size 0xCC when bit 0 of a1 is set, and returns this.
// @fnv 0x00a9add0
void* __fastcall DestroyIfFlagged(NiBSPNode* apNode, void*, unsigned int auiFlags)
{
    ((void (__thiscall*)(NiNode*))DestroyNode)((NiNode*)apNode);
    if (auiFlags & 1)
        _delete(apNode, 0xCC);
    return apNode;
}

// @fnv 0x00a9a740
// src: XBOX_PDB 0x00a9a740
void NiBSPNode::SaveBinary_00a9a740(NiStream& stream)
{
    NiNode::SaveBinary(stream);
    m_pSphere.SaveBinary(stream);
}

void __cdecl GetNodeViewerStrings();
void __cdecl FormatPlaneString();
char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610*);

// @fnv 0x00a9acf0
void __fastcall AppendPlaneNames(NiBSPNode* apNode, void*, StrArr* apViewerStrings)
{
    ((void* (__thiscall*)(NiNode*, void*))GetNodeViewerStrings)((NiNode*)apNode, apViewerStrings);
    char* pName = _FUN_00a7d330(*(GlobalObjectO2_00a7b610**)&g_011f5f54);
    unsigned int uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->SetSize(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->SetAt(uiIndex, pName);
    pName = ((char* (__thiscall*)(NiPlane*, const char*))FormatPlaneString)((NiPlane*)((char*)apNode + 0xac), "m_kModelPlane");
    uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->SetSize(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->SetAt(uiIndex, pName);
    pName = ((char* (__thiscall*)(NiPlane*, const char*))FormatPlaneString)((NiPlane*)((char*)apNode + 0xbc), "m_kWorldPlane");
    uiIndex = *(unsigned short*)((char*)apViewerStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)apViewerStrings + 0x8))
        apViewerStrings->SetSize(uiIndex + *(unsigned short*)((char*)apViewerStrings + 0xe));
    apViewerStrings->SetAt(uiIndex, pName);
}

struct FUN_00a59e00_shell
{
    void FUN_00a59e00(NiStream& stream);
};

void __cdecl ClassifyPlanePoint();

struct BinaryDataRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    float unk68;
    int unk6c;
    int unk70;
    float unk74;
    int unk78;
    int unk7c;
    float unk80;
    int unk84;
    int unk88;
    float unk8c;
};

struct PtrPair
{
    FUN_00a59e00_shell* unk00;
    FUN_00a59e00_shell* unk04;
};

// @fnv 0x00a9ac10
void __fastcall LoadFromStream(NiBSPNode* apNode, void*, NiStream& stream)
{
    BinaryDataRecord* data = *(BinaryDataRecord**)((char*)&stream + 0xc);
    int r = ((int (__thiscall*)(NiPlane*, void*))ClassifyPlanePoint)((NiPlane*)((char*)apNode + 0xbc), &data->unk8c);
    if (r == 0)
    {
        NiPoint3 kTriple;
        kTriple.x = data->unk68;
        kTriple.y = data->unk74;
        kTriple.z = data->unk80;
        r = ((int (__thiscall*)(NiPlane*, void*))ClassifyPlanePoint)((NiPlane*)((char*)apNode + 0xbc), &kTriple);
    }
    PtrPair* p = (PtrPair*)apNode->m_kChildren.m_pBase;
    FUN_00a59e00_shell* a = p->unk00;
    FUN_00a59e00_shell* b = p->unk04;
    if (r == 2)
    {
        if (b != 0)
        {
            b->FUN_00a59e00(stream);
        }
        if (a != 0)
        {
            a->FUN_00a59e00(stream);
        }
    }
    else
    {
        if (a != 0)
        {
            a->FUN_00a59e00(stream);
        }
        if (b != 0)
        {
            b->FUN_00a59e00(stream);
        }
    }
}

void __cdecl UnequalModelPlane();

void __cdecl EqualNode();
void __cdecl CopyNodeMembers();

// Returns true if IsEqual(pkObject) holds and this node's m_kBound equals the other node's m_kBound; otherwise false.
// @fnv 0x00a9acb0
bool __fastcall IsEqualWithBound(NiBSPNode* apNode, void*, NiObject* pkObject)
{
    if (!((bool (__thiscall*)(NiNode*, NiObject*))EqualNode)(apNode, pkObject))
        return false;

    NiBSPNode* pkOther = (NiBSPNode*)pkObject;
    if (((bool (__thiscall*)(const NiPlane*, const NiPlane&))UnequalModelPlane)((const NiPlane*)&apNode->m_pSphere, *(const NiPlane*)&pkOther->m_pSphere))
        return false;

    return true;
}

extern char vtable_010a1024;
void* __cdecl Object_DispatchCommandFour(unsigned int bytes);
void __cdecl InitializeNode();
void __cdecl InitializePlane();
struct ChildNode
{
    void FUN_0060bef0(unsigned int);
};

// @fnv 0x00a9ae00
// src: XBOX_PDB 0x00a9ae00
void* __fastcall NiBSPNode_CreateClone(NiBSPNode* apNode, void*, void* arg)
{
    char* memory = (char*)Object_DispatchCommandFour(0xcc);
    char* result;
    if (memory)
    {
        ((void (__thiscall*)(NiNode*, int))InitializeNode)((NiNode*)memory, 0);
        *(void**)memory = &vtable_010a1024;
        ((void (__thiscall*)(NiPlane*))InitializePlane)((NiPlane*)(memory + 0xac));
        ((void (__thiscall*)(NiPlane*))InitializePlane)((NiPlane*)(memory + 0xbc));
        ((ChildNode*)(memory + 0x9c))->FUN_0060bef0(2);
        *(unsigned short*)(memory + 0xaa) = 0;
        result = memory;
    }
    else
    {
        result = 0;
    }
    ((void (__thiscall*)(NiNode*, void*, void*))CopyNodeMembers)(apNode, result, arg);
    *(NiSphere*)(result + 0xac) = apNode->m_pSphere;
    return result;
}

__declspec(noreturn) void __cdecl ReadChildListFromStream();

// @fnv 0x00a9a730
// src: XBOX_PDB 0x00a9a730
void __cdecl NiBSPNode_LinkObject()
{
    ReadChildListFromStream();
}

void __cdecl RegisterChildStreamables();
// @fnv 0x00a93c40
// src: XBOX_PDB 0x00a93c40
void __cdecl NiBSPNode_RegisterStreamables()
{
    RegisterChildStreamables();
}

struct BSPWorldMatrix
{
    NiPoint3 a, b, c;
    NiPoint3 operator*(const NiPoint3& v) const
    {
        return NiPoint3(a.x * v.x + a.y * v.y + a.z * v.z, b.x * v.x + b.y * v.y + b.z * v.z,
                          c.x * v.x + c.y * v.y + c.z * v.z);
    }
};

// Transforms modelNormal and modelConstant into world space using rotation, translation, and scale.
// @fnv 0x00a9a760
// src: XBOX_PDB 0x00a9a760
void NiBSPNode::UpdateWorldPlane()
{
    NiPoint3 normal = (*(BSPWorldMatrix*)&m_kWorld.m_Rotate) * *(NiPoint3*)&m_pSphere.x;
    volatile float fWorldConstant = m_kWorld.m_Translate.Dot(normal);
    *(NiPoint3*)((char*)this + 0xbc) = normal;
    double oldConstant = fWorldConstant;
    fWorldConstant = oldConstant + m_kWorld.m_fScale * *(volatile float*)&m_pSphere.r;
    *(float*)((char*)this + 0xc8) = fWorldConstant;
}

struct BSPMatrix
{
    float m_afEntries[3][3];
    const float& At(unsigned i, unsigned j) const
    {
        return m_afEntries[i][j];
    }
    float Get(unsigned i, unsigned j) const
    {
        return m_afEntries[i][j];
    }
    BSPMatrix operator*(const BSPMatrix& m) const;
    BSPMatrix ComposeMatrices(const BSPMatrix& m) const;
    bool Inverse(BSPMatrix& inv) const;
    NiPoint3 operator*(const NiPoint3& p) const
    {
        NiPoint3 r;
        r.x = m_afEntries[0][0] * p.x + (p.y * (m_afEntries[0][1])) + (p.z) * (m_afEntries[0][2]);
        r.y = (((p.x) * m_afEntries[1][0]) + m_afEntries[1][1] * p.y + p.z * m_afEntries[1][2]);
        r.z = (m_afEntries[2][0] * (p.x)) + (p.y) * (m_afEntries[2][1]) + (p.z) * (m_afEntries[2][2]);
        return r;
    }
    __forceinline NiPoint3 TransformNormal(const NiPoint3& p) const
    {
        const NiPoint3& normal = p;
        NiPoint3 r;
        r.x = ((At(0, 0) * normal.x) + (normal.y * Get(1, 0))) + (Get(2, 0) * normal.z);
        r.y = ((p.Value().x * m_afEntries[0][1]) + (p.y * Get(1, 1))) + (p.z * m_afEntries[2][1]);
        r.z = ((m_afEntries[1][2] * p.y) + (p.Value().x * m_afEntries[0][2])) + (m_afEntries[2][2] * p.Zref());
        return r;
    }
    friend NiPoint3 operator*(const NiPoint3& p, const BSPMatrix& m)
    {
        return NiPoint3(p.x * m.m_afEntries[0][0] + p.y * m.m_afEntries[1][0] + p.z * m.m_afEntries[2][0],
                        p.x * m.m_afEntries[0][1] + p.y * m.m_afEntries[1][1] + p.z * m.m_afEntries[2][1],
                        p.x * m.m_afEntries[0][2] + p.y * m.m_afEntries[1][2] + p.z * m.m_afEntries[2][2]);
    }
};

// NiBSPNode.h has no ApplyTransform override or model/world plane members yet.
// Retain this one local layout until that declaration is available.
struct NiBSPTransformNode
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    BSPMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    NiAVObject** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    int unka8;
    NiPlane m_kModelPlane;
    __forceinline void AddPlaneConst(const NiPoint3& kTrn)
    {

        m_kModelPlane.c += ((*(NiPoint3*)&m_kModelPlane.x)) * kTrn;
    }
    __forceinline void ApplyPlane(const BSPMatrix& kMat, const NiPoint3& kTrn)
    {
        BSPMatrix kInv;
        kMat.Inverse(kInv);
        (*(NiPoint3*)&m_kModelPlane.x) = (*(NiPoint3*)&m_kModelPlane.x) * kInv;
        AddPlaneConst(kTrn);
    }
    __forceinline void ApplyPlane2(const BSPMatrix& kMat, const NiPoint3& kTrn)
    {
        BSPMatrix kInv;
        kMat.Inverse(kInv);
        NiPoint3 normal = kInv.TransformNormal((*(NiPoint3*)&m_kModelPlane.x));
        (*(NiPoint3*)&m_kModelPlane.x) = normal;
        m_kModelPlane.c += (*(NiPoint3*)&m_kModelPlane.x) * kTrn;
    }
    void NiBSPNode_ApplyTransform(const BSPMatrix& kMat, const NiPoint3& kTrn, bool bOnLeft);
};

// Applies the supplied matrix and translation to the node's model plane and passes them to each non-null child.
// @fnv 0x00a9a860
// src: XBOX_PDB 0x00a9a860
void NiBSPTransformNode::NiBSPNode_ApplyTransform(const BSPMatrix& kMat, const NiPoint3& kTrn, bool bOnLeft)
{
    if (bOnLeft)
    {
        BSPMatrix kRot = m_kRotate.ComposeMatrices(kMat * m_kRotate);
        NiPoint3 kT = ((kTrn + kMat * m_kTranslate) - m_kTranslate) * m_kRotate / m_fScale;
        ApplyPlane(kRot, kT);
        for (unsigned int i = 0; i < m_usSize; i++)
        {
            NiAVObject* pChild = m_pBase[i];
            if (pChild)
                pChild->ApplyTransform(*(const NiMatrix3*)&kRot, kT, true);
        }
    }
    else
    {
        ApplyPlane2(kMat, kTrn);
        for (unsigned int i = 0; i < m_usSize; i++)
        {
            NiAVObject* pChild = m_pBase[i];
            if (pChild)
                pChild->ApplyTransform(*(const NiMatrix3*)&kMat, kTrn, true);
        }
    }
}
