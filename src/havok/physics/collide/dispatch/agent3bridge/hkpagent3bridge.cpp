
// src/havok/physics/collide/dispatch/agent3bridge/hkpagent3bridge.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/dispatch/agent3bridge/hkpagent3bridge.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef void (*Callback)();
extern void CreateAgent();
extern void InvokeDispatch();
extern void hkAgent3Bridge_removePoint();
extern void hkAgent3Bridge_commitPotential();
extern void CallIfaceMethod();
extern void hkAgent3Bridge_updateFilter();
extern void AddChildAgent2ToCollector();
extern void CallObjectVirtual();
extern void DispatchVirtualCall();
extern void CallVirtualWithVectorArgs();
struct __declspec(align(16)) CallbackTable
{
    Callback callback00;
    Callback callback04;
    Callback callback08;
    Callback callback0c;
    Callback callback10;
    Callback callback14;
    Callback callback18;
    Callback callback1c;
    Callback callback20;
    Callback callback24;
    Callback callback28;
    Callback callback2c;
    unsigned char flag30;
    unsigned char flag31;
    unsigned char flag32;
    unsigned char flag33;
    Callback unk34;
    Callback unk38;
    Callback unk3c;
};
struct Context
{
    void AddEntry(CallbackTable*, int, int);
};
// Fills a CallbackTable with the callback functions and flags, then passes it to AddEntry with -1, -1.
// @fnv 0x00d923b0
// src: HAVOK_LIB 0x00d923b0
void __cdecl hkAgent3Bridge_registerAgent3(void* context)
{
    CallbackTable table;
    table.flag31 = 0;
    table.flag32 = 0;
    table.callback28 = 0;
    table.callback08 = 0;
    table.callback10 = hkAgent3Bridge_commitPotential;
    table.callback14 = CallIfaceMethod;
    table.callback0c = hkAgent3Bridge_removePoint;
    table.callback00 = CreateAgent;
    table.callback2c = CallVirtualWithVectorArgs;
    table.callback04 = InvokeDispatch;
    table.callback18 = hkAgent3Bridge_updateFilter;
    table.callback1c = AddChildAgent2ToCollector;
    table.callback20 = CallObjectVirtual;
    table.callback24 = DispatchVirtualCall;
    table.flag30 = 1;
    ((Context*)context)->AddEntry(&table, -1, -1);
}
