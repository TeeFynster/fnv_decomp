
// src/havok/physics/collide/util/kdtree/mediator/hkpcollidablemediator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/kdtree/mediator/hkpcollidablemediator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Child { unsigned int unk00; unsigned int unk04; };
struct Owner { unsigned int unk00; unsigned int unk04; Child* child; unsigned int hkpCollidableMediator_getNumPrimitives(); };
// @fnv 0x00d9e000
// src: XBOX_PDB 0x00d9e000
unsigned int Owner::hkpCollidableMediator_getNumPrimitives() { return child->unk04; }

// InitWalker: thiscall (2 stack args). Stores vptr, flag word and list, walks the item list when ctx != 0, returns this.

extern int DAT_010d40b4;

struct __declspec(align(16)) OutSlot {
    void* m_ptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
};

struct OutPlain { void* m_ptr; };

struct SubRec {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(OutSlot* out);
    void hkpPhantom_setBoundingVolumeData(OutSlot* out);
};

struct ItemRec {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    signed char m_subOff;
    unsigned int unk14;
    unsigned char m_flag18;
    unsigned int unk1c;
    unsigned int m_20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
};

struct ItemListRec {
    ItemRec** m_items;
    int m_uiItemCount;
};

struct CtxRec {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    void* m_78;
};

void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void* mgr, OutSlot* out, int flag);

class ListWalker {
public:
    int m_vptr;
    unsigned short unk04;
    unsigned short m_06;
    ItemListRec* m_08;
    ListWalker* InitWalker(ItemListRec* list, CtxRec* ctx);
};

// @fnv 0x00d9df50
ListWalker* ListWalker::InitWalker(ItemListRec* list, CtxRec* ctx)
{
    m_06 = 1;
    m_vptr = (int)&DAT_010d40b4;
    m_08 = list;
    if (ctx != 0) {
        int iIndex = 0;
        if (list->m_uiItemCount > 0) {
            do {
                ItemRec* item = m_08->m_items[iIndex];
                if (item->m_20 > item->m_30) {
                    if (item->m_flag18 == 1) {
                        OutPlain out;
                        SubRec* sub = (SubRec*)((char*)m_08->m_items[iIndex] + m_08->m_items[iIndex]->m_subOff);
                        out.m_ptr = sub;
                        hkpEntityAabbUtil_entityBatchRecalcAabb(ctx->m_78, (OutSlot*)&out, 1);
                    } else {
                        OutSlot out;
                        SubRec* sub = (SubRec*)((char*)m_08->m_items[iIndex] + m_08->m_items[iIndex]->m_subOff);
                        sub->v18(&out);
                        sub->hkpPhantom_setBoundingVolumeData(&out);
                    }
                }
                ++iIndex;
            } while (iIndex < m_08->m_uiItemCount);
        }
    }
    return this;
}

struct FUN_00d9e010_cls {
    unsigned int unk00;
    unsigned int unk04;
    Child* child;
    unsigned int hkpCollidableMediator_getPrimitiveId(unsigned int index);
};

// @fnv 0x00d9e010
// src: HAVOK_LIB 0x00d9e010
unsigned int FUN_00d9e010_cls::hkpCollidableMediator_getPrimitiveId(unsigned int index)
{
    unsigned int* table = (unsigned int*)child->unk00;
    return table[index];
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
