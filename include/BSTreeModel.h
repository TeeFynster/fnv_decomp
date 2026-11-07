#pragma once

#include "NiRefObject.h"
#include "NiAVObject.h"

class CSpeedTreeRT;
class NiNode;
class NiTexture;
class NiTriStrips;
class NiTriStripsData;
class TESObjectTREE;
class TreeCallback;
class TreeInput;
class TreeLeafRef;
class TreeModelInput;
class LoaderX;

class BSTreeModel : public NiRefObject
{
  public:
    union
    {
        int initialized;
        unsigned int unk08;
    };
    union
    {
        CSpeedTreeRT* m_pTreeRuntime;
        CSpeedTreeRT* runtime;
    };
    NiPointer<BSTreeModel> source;
    union
    {
        NiPointer<NiTriStripsData>* pLeafGeometry;
        NiPointer<NiTriStripsData>* branchGeometry;
    };
    union
    {
        NiPointer<NiTriStripsData>* leafGeometry;
        NiPointer<NiTriStripsData>* m_pspLeafGeometry;
    };
    NiPointer<NiNode> billboard;
    NiPointer<NiAVObject> unk20;
    union
    {
        NiPointer<NiTriStrips>* pLeafShapes;
        NiPointer<NiTriStrips>* branchNodes;
    };
    union
    {
        NiPointer<NiTriStrips>* leafNodes;
        NiPointer<NiTriStrips>* m_pspLeafShaders;
    };
    NiPointer<NiTexture> unk2c;
    NiPointer<NiTexture> unk30;
    NiPointer<NiTexture> unk34;
    NiPointer<NiNode> collision;
    union
    {
        float unk3c;
        float m_fLeafScale;
        float scale;
    };
    unsigned int unk40;
    bool unk44;
    unsigned char unk45[3];
    union
    {
        float unk48;
        float radius;
    };
    union
    {
        float unk4c;
        float height;
    };

    BSTreeModel();
    virtual ~BSTreeModel();
    virtual void DeleteThis();
    virtual void f2();
    virtual NiAVObject* CreateInstance(float);
    virtual void ApplyInput(TreeInput*);
    virtual void ClearArrays();
    virtual void LoadTreeCollision(TESObjectTREE*);

    void f1();
    void vf04();
    void vf05();
    void vf06();
    unsigned int FUN_00726070();
    bool BSTreeModel_InitFromBase(TESObjectTREE*, unsigned int);
    bool BSTreeModel_InitFromBase(TreeModelInput*, int);
    bool CombatProcedure_GetFinished();
    unsigned short __thiscall GetNumBranchLODLevels();
    unsigned short FUN_006699d0();
    unsigned short GetUnsignedShort();
    bool CloneFromModel(BSTreeModel*);
    void SetByteAtOffset44(unsigned char);
    void BSTreeModel_CreateBranchGeometry();
    void BSTreeModel_CreateLeafGeometry(TESObjectTREE*);
    void BSTreeModel_CreateLeafGeometry(TreeLeafRef*);
    void BSTreeModel_CreateBillboardGeometry(TESObjectTREE*);
    void BSTreeModel_CreateBillboardGeometry(LoaderX*);
    void UpdateTreeLod(TreeCallback*);
    void Setup(TreeModelInput*);
    void Finish(TreeModelInput*);
    NiAVObject* CreateTree(float);
    NiAVObject* ConvertFloatToUInt();
    void ReleaseData();
    void* DestroyAndFree(unsigned int flags);
};
