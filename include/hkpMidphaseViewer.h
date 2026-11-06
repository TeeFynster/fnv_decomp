#pragma once

#include "hkpWorldViewerBase.h"
#include "hkpWorldPostSimulationListener.h"

class hkpMidphaseViewer : public hkpWorldViewerBase,
                          public hkpWorldPostSimulationListener
{
public:
    // One element of the broadphase display array; the original's member is hkArray<hkDisplayAABB>
    // (Havok 7.1 hkpMidphaseViewer.h): 0x80 bytes, virtual destructor (hkDisplayAABB : hkDisplayGeometry).
    class Element
    {
    public:
        virtual ~Element() throw();
        int unk04;
        int unk08;
        int unk0C;
        int unk10;
        int unk14;
        int unk18;
        int unk1C;
        int unk20;
        int unk24;
        int unk28;
        int unk2C;
        int unk30;
        int unk34;
        int unk38;
        int unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
        int unk54;
        int unk58;
        int unk5C;
        int unk60;
        int unk64;
        int unk68;
        int unk6C;
        int unk70;
        int unk74;
        int unk78;
        int unk7C;
    };

    struct ElementArray
    {
        Element* m_data;
        int m_iElementCount;
        int m_iCapacityState;

        __forceinline ElementArray() throw()
            : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
        {}
        ~ElementArray() throw();
    };

    hkpMidphaseViewer();
    hkpMidphaseViewer(int a);
    virtual ~hkpMidphaseViewer() throw();
    virtual void postSimulationCallback(hkpWorld* world);

    void FUN_00d6a8a0();
    void FUN_00d6a750();
    void* FUN_00d6a8b0(int flags);

    ElementArray m_elements;
};

