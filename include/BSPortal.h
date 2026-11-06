#pragma once

#include "NiObject.h"
#include "NiPoint3.h"
#include <stddef.h>

class CellPoint3;

// Preserve the struct tag required by member-function symbol names.
#pragma push_macro("class")
#define class struct
#include "BSOcclusionPlane.h"
#pragma pop_macro("class")

class NiPoint2;
class PortalEntry;

class BSPortal : public BSOcclusionPlane
{
public:
    class PortalPointer
    {
    public:
        unsigned int unk00;

        PortalPointer(int aValue);
        ~PortalPointer();
        void Ping(int aValue);
    };

    template <class T> class PortalArray
    {
    public:
        T* data;
        unsigned short capacity;
        unsigned short count;
    };

    BSPortal(const NiPoint3&, NiPoint2*, char*);
    virtual ~BSPortal();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);

    void DestroyBase();
    void* Destroy(unsigned int flags);
    void CopyFields(BSPortal* apTarget, int aiUnused);
    int QueryLinkedObjects();

    union
    {
        char data[0x40 - sizeof(BSOcclusionPlane)];
        char unk08[0x40 - sizeof(BSOcclusionPlane)];
    };
    unsigned int m_40;
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
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    union
    {
        struct
        {
            unsigned int unka0;
            unsigned int unka4;
        };
        PortalArray<PortalEntry*> entries;
    };
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned char m_e4;
    unsigned char m_e5;
    unsigned short unke6;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int m_fc;
    unsigned int m_100;
    PortalPointer m_104;
};

#if !defined(_WIN64)
typedef char BSPortal_size_check[(sizeof(BSPortal) == 0x108) ? 1 : -1];
typedef char BSPortal_m_40_offset_check[(offsetof(BSPortal, m_40) == 0x40) ? 1 : -1];
typedef char BSPortal_entries_offset_check[(offsetof(BSPortal, entries) == 0xa0) ? 1 : -1];
typedef char BSPortal_m_e4_offset_check[(offsetof(BSPortal, m_e4) == 0xe4) ? 1 : -1];
typedef char BSPortal_m_e5_offset_check[(offsetof(BSPortal, m_e5) == 0xe5) ? 1 : -1];
typedef char BSPortal_m_fc_offset_check[(offsetof(BSPortal, m_fc) == 0xfc) ? 1 : -1];
typedef char BSPortal_m_100_offset_check[(offsetof(BSPortal, m_100) == 0x100) ? 1 : -1];
typedef char BSPortal_m_104_offset_check[(offsetof(BSPortal, m_104) == 0x104) ? 1 : -1];
#endif
