#pragma once
#include "NiPointer.h"

#include "NiStream.h"

class NiNode;
class NiObjectNET;
class BSNodeReferences;
template <class T> class NiTStringMap;

class BSStream : public NiStream
{
public:
    union
    {
        int unk5c4;
        NiTStringMap<NiObjectNET*>* m_pObjectNameMap;
        unsigned int streamState;
        int m_5c4;
    };
    union
    {
        struct
        {
            NiPointer<BSNodeReferences> m_spNodeReferences;
        };
        int unk5c8;
        int m_5c8;
    };

    BSStream();
    virtual ~BSStream();

    using NiStream::BSStream_Load;
    virtual bool BSStream_Load(const char* name);

    unsigned int GetRefAt21C();
    NiNode* GetStringAt(unsigned int index);
    void DestroyObject();
    void* FUN_0043d150(unsigned int flags);
};
