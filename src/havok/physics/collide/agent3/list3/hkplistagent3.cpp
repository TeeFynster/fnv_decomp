
// src/havok/physics/collide/agent3/list3/hkplistagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/list3/hkplistagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DA6E60Shape
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int getType();
};

struct DA6E60Collidable
{
    DA6E60Shape* m_pCollisionShape;
};

struct DA6E60Input
{
    int m_unk00;
    DA6E60Collidable* m_kCollidable;
    int m_unk08;
    int m_iType;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
};

void __cdecl hkAgent1nMachine_UpdateShapeCollectionFilter(int context, DA6E60Input* input);

// Reads the collidable's shape type, fills a DA6E60Input from the arguments, and passes it to FUN_00da48e0 with the context.
// @fnv 0x00da6e60
// src: GUESS 0x00da6e60 (confidence: low)
void __cdecl Object_UpdateFields_00da6e60(int unused, int context, int a, DA6E60Collidable* collidable, int b, int c, int d)
{
    int shapeType = collidable->m_pCollisionShape->getType();
    DA6E60Input input;
    input.m_unk00 = a;
    input.m_kCollidable = collidable;
    input.m_unk10 = b;
    input.m_unk14 = c;
    input.m_iType = shapeType;
    input.m_unk18 = d;
    hkAgent1nMachine_UpdateShapeCollectionFilter(context, &input);
}

void __cdecl _hkAgent1nMachine_WarpTime(int a1, float a2, float a3, int a4);

// Calls FUN_00da35f0 with unk08, unk0C, unk10 and unk14, dropping unk04.
// @fnv 0x00da6e30
// src: GUESS 0x00da6e30 (confidence: medium)
void __cdecl Hkplistagent3_HkAgent1nMachine_WarpTime_Thunk(int aiUnused, int aiArg1, float afArg2, float afArg3, int aiArg4)
{
    _hkAgent1nMachine_WarpTime(aiArg1, afArg2, afArg3, aiArg4);
}

// 0x00da6de0: virtual call at vtable +0x18 with a type-name string, then
// FUN_00d97250(a3, this, this), then tail call to vtable +0x1c.
struct hkListAgent3
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18(const char* typeName);
    virtual unsigned int v1c();
};

extern const char g_hkListAgent3_typeName[];

extern void __cdecl hkpAgentMachineUtil_calc1nStatistics(int a1, int a2, void* a3);

// Calls self->v18 with the hkListAgent3 type name, then FUN_00d97250 with a2, a3 and self, and returns self->v1c().
// @fnv 0x00da6de0
// src: GUESS 0x00da6de0 (confidence: low)
unsigned int __cdecl hkListAgent3_ProcessAndReturnValue_00da6de0(int a1, int a2, int a3, hkListAgent3* self)
{
    self->v18(g_hkListAgent3_typeName);
    hkpAgentMachineUtil_calc1nStatistics(a2, a3, self);
    return self->v1c();
}
