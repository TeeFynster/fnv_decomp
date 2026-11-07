
// src/speedtree/branchinfo_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/branchinfo.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/branchinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/branchinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00b3f310_Item
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
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    S_00b3f310_Item();
};
extern float DAT_01017870;
extern float DAT_01018f5c;
extern float DAT_01017b78;
extern float DAT_01016248;
extern float DAT_0101622c;
extern float DAT_0101e2bc;
struct FUN_00b3f310
{
    int unk00;
    int unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    float unk20;
    float unk24;
    int unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    int unk50;
    S_00b3f310_Item* unk54;
    S_00b3f310_Item* unk58;
    int unk5c;
    S_00b3f310_Item* unk60;
    S_00b3f310_Item* unk64;
    S_00b3f310_Item* unk68;
    S_00b3f310_Item* unk6c;
    int unk70;
    FUN_00b3f310();
};

struct S_00b3f310_Item_WithDtor : S_00b3f310_Item
{
    ~S_00b3f310_Item_WithDtor();
};

struct FUN_00b3f310_Host : FUN_00b3f310
{
    void DeleteOwnedItems();
};

// @fnv 0x00b3f620
// src: GUESS 0x00b3f620 (confidence: medium)
void FUN_00b3f310_Host::DeleteOwnedItems()
{
    delete (S_00b3f310_Item_WithDtor*)unk58;
    delete (S_00b3f310_Item_WithDtor*)unk5c;
    delete (S_00b3f310_Item_WithDtor*)unk54;
    delete (S_00b3f310_Item_WithDtor*)unk50;
    delete (S_00b3f310_Item_WithDtor*)unk6c;
    delete (S_00b3f310_Item_WithDtor*)unk64;
    delete (S_00b3f310_Item_WithDtor*)unk68;
    delete (S_00b3f310_Item_WithDtor*)unk60;
    delete (S_00b3f310_Item_WithDtor*)unk70;

    unk58 = 0;
    unk5c = 0;
    unk54 = 0;
    unk50 = 0;
    unk6c = 0;
    unk64 = 0;
    unk68 = 0;
    unk60 = 0;
    unk70 = 0;
}

struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
    unsigned char& FUN_00b15170(unsigned n);
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
    int CTreeFileAccess_ParseBranchParameter();
};
inline void DeadTop()
{
    int aiD[135];
    aiD[94] = 0;
}
struct BranchQ
{
    int iA;
    int iB;
    float afF[5];
    bool bA;
    bool bB;
    char acPad[0x56];
    BranchQ();
    void UpdateFields_00b3fc80(int);
    void ReleaseStorage_00b3fcf0(int);
    void UpdateFields_00b3fd60(int);
    void UpdateState_00b3fdd0(int);
    void UpdateFields_00b3fe40(int);
    void ReleaseStorage_00b3feb0(int);
    void UpdateFields_00b3ff20(int);
    void UpdateState_00b3ff90(int);
    void UpdateFields_00b40000(int);
};
// @fnv 0x00b3f8e0
// src: GUESS 0x00b3f8e0 (confidence: low)
BranchQ* Object_ProcessEntries_00b3f8e0(Parser* p)
{
    DeadTop();
    BranchQ* pBranch = new BranchQ;
    int iToken = p->GetNextElement();
    if (iToken != 0x3f8)
        throw FUN_00b09480("malformed branch data", false);
    iToken = p->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x1770:
            pBranch->UpdateFields_00b3fc80(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1771:
            pBranch->ReleaseStorage_00b3fcf0(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1772:
            pBranch->UpdateFields_00b3fd60(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1773:
            pBranch->UpdateState_00b3fdd0(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1781:
            pBranch->UpdateFields_00b40000(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1774:
            pBranch->UpdateFields_00b3fe40(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1775:
            pBranch->ReleaseStorage_00b3feb0(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1776:
            pBranch->UpdateFields_00b3ff20(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1777:
            pBranch->UpdateState_00b3ff90(p->CTreeFileAccess_ParseBranchParameter());
            break;
        case 0x1778:
            pBranch->iA = p->GetNextElement();
            break;
        case 0x1779:
            pBranch->iB = p->GetNextElement();
            break;
        case 0x177a:
            pBranch->afF[0] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x177b:
            pBranch->afF[1] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x177c:
            pBranch->afF[2] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x177d:
            pBranch->afF[3] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x177e:
            pBranch->afF[4] = p->CTreeFileAccess_ParseFloat();
            break;
        case 0x177f:
            pBranch->bA = p->kData.FUN_00b15170(p->uiPos++) != 0;
            break;
        case 0x1780:
            pBranch->bB = p->kData.FUN_00b15170(p->uiPos++) != 0;
            break;
        default:
            throw FUN_00b09480("malformed general branch information", false);
        }
        iToken = p->GetNextElement();
    } while (iToken != 0x3f9);
    return pBranch;
}
