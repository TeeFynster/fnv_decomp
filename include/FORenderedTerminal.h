#pragma once

#include "FORenderedMenu.h"
#include "NiPoint3.h"

class TilePX;

class FORenderedTerminal : public FORenderedMenu
{
public:
    struct NodeHandle
    {
        NiAVObject* m_pObject;

        NodeHandle(int);
        ~NodeHandle();
        operator NiAVObject*() const;
    };

    FORenderedTerminal();
    virtual ~FORenderedTerminal();

    NiAVObject* GetTerminalScreenObject();
    NiAVObject* FUN_007ffad0();
    void FUN_007060d0();
    void* DestroyIfFlagged(unsigned int);
    void FUN_007ffaf0();
    void FUN_00984f60(TilePX* item);
    void FUN_00705fc0(NiNode* node);
    void Refresh();

    NiPoint3 pt;
    NodeHandle node;
    float unkE8;
    unsigned char unkEC;
    unsigned char unkED[3];
};
