#pragma once

#include "NiObject.h"

class BSAnimNotes : public NiObject
{
public:
    virtual ~BSAnimNotes();
    virtual bool RegisterStreamables(NiStream& arStream);

    void Destroy();
    void* DestroyIfFlagged(unsigned int auiFlags);

    NiObject** m_ppNotes;
    unsigned short m_usNumAnimNotes;
};
