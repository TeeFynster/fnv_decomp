
// src/fallout_shared/havok/cameracaster_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout_shared/havok/cameracaster_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/havok/cameracaster_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/cameracaster.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout_shared/havok/cameracaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cameracaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/bhkCharacterListener.h"

extern int DAT_0104da3c;
struct FUN_00621100_shell
{
    void SetVtable();
};
extern float DAT_0104da4c;
struct FUN_00621290_shell
{
    void* InitFloats();
    void _ref_006815c0();
};

struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4();
};
struct __declspec(align(16)) xVec4b
{
    xM128 m_vComponents;
    int m_auiShapeKeys[4];
    xVec4b();
};
void xFUN_004a3e00(void*, const xP3&);
struct xHit
{
    int m_iWordAt00[18];
    void* m_48;
};
struct xHitList
{
    int FUN_00726070();
    xHit* FUN_00807770(int);
};
struct xTag
{
    xTag();
    bool FUN_005609f0();
    char m_iThirdValue;
};
struct __declspec(align(16)) xCollector
{
    xCollector();
    ~xCollector();
    xTag FUN_00621210();
    void FUN_00cabad0();
    xHitList* FUN_00460140();
    int m_q[0xe8];
};
struct xPhantom
{
    void InvokeInterfaceCall(xVec4*, xVec4b*, xCollector*, int);
};
struct xFilter
{
    xFilter(unsigned int);
    int FUN_0043b4d0();
    unsigned int m_uiFilterValue;
};
unsigned int __fastcall xFUN_0043b540(void*);
struct xNode
{
    bool FUN_00456610();
};
xNode* xFUN_00c7fa90(void*);
struct xOwnerP
{
    bool FUN_00621240();
};
struct xActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual bool FUN_fc();
    xOwnerP* FUN_009306d0();
};

xActor* xFUN_0056f930(xNode*);
struct xMenuItem
{
    int m_iWordAt00[3];
    xActor* m_iThirdValue;
};
struct MenuItemCollection
{
    unsigned int FUN_0044ddc0();
    xMenuItem* FUN_009c71c0();
};
extern MenuItemCollection xg_11f2250;
extern xActor* xg_11f21cc;
extern xActor* xg_player_11dea3c;
struct xOutHit
{
    void FUN_006212c0(xHit*);
    xVec4* FUN_006815c0();
};
void xFUN_00458620(xP3&, xVec4*);
struct xPtr
{
    xPhantom* FUN_00559450();
    void* m_p;
};
struct xCaster
{
    xPtr m_iWordAt00;
    bool FUN_00620bc0(const xP3& akFrom, xP3& akTo, xOutHit* apOut);
};
// @fnv 0x00620bc0
bool xCaster::FUN_00620bc0(const xP3& akFrom, xP3& akTo, xOutHit* apOut)
{
    bool RESULT = false;
    if (m_iWordAt00.FUN_00559450())
    {
        xVec4 FROM;
        xCollector COL;
        xVec4b TO;
        xFUN_004a3e00(&FROM, akFrom);
        xFUN_004a3e00(&TO, akTo);
        m_iWordAt00.FUN_00559450()->InvokeInterfaceCall(&FROM, &TO, &COL, 0);
        RESULT = COL.FUN_00621210().FUN_005609f0();
        if (RESULT)
        {
            COL.FUN_00cabad0();
            int I = 0;
            bool FOUND = false;
            bool ISX = xg_11f2250.FUN_0044ddc0() == 4;
            xActor* TARGET = 0;
            if (ISX)
            {
                xMenuItem* ITEM = xg_11f2250.FUN_009c71c0();
                if (ITEM)
                    TARGET = ITEM->m_iThirdValue;
                else
                    TARGET = xg_11f21cc;
                if (!TARGET)
                    TARGET = xg_player_11dea3c;
            }
            while (!FOUND && I < COL.FUN_00460140()->FUN_00726070())
            {
                void* SHAPE = COL.FUN_00460140()->FUN_00807770(I)->m_48;
                xFilter FILTER(xFUN_0043b540(SHAPE));
                int TYPE = FILTER.FUN_0043b4d0();
                xNode* NODE = xFUN_00c7fa90(SHAPE);
                if (TYPE != 0x11 && (!NODE || NODE->FUN_00456610()))
                {
                    I++;
                    continue;
                }
                FOUND = true;
                switch (TYPE)
                {
                case 5:
                case 8:
                case 29:
                    if (!ISX)
                        break;
                case 19:
                case 20:
                case 25:
                case 30:
                case 32:
                    if (NODE)
                    {
                        xActor* ACTOR = xFUN_0056f930(NODE);
                        if (ACTOR)
                        {
                            if (ISX && ACTOR == TARGET)
                                FOUND = false;
                            else if (ACTOR->FUN_fc())
                            {
                                xActor* PACTOR = ACTOR;
                                xOwnerP* OWNER = PACTOR->FUN_009306d0();
                                if (OWNER && OWNER->FUN_00621240())
                                    FOUND = false;
                            }
                        }
                    }
                    break;
                }
                if (!FOUND)
                    I++;
                else if (ISX)
                    void* LAST = COL.FUN_00460140()->FUN_00807770(I)->m_48;
            }
            if (FOUND)
            {
                apOut->FUN_006212c0(COL.FUN_00460140()->FUN_00807770(I));
                xFUN_00458620(akTo, apOut->FUN_006815c0());
            }
            else
                RESULT = false;
        }
    }
    return RESULT;
}
