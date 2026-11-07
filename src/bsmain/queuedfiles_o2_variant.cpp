
// src/bsmain/queuedfiles_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsmain/queuedfiles.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "../../include/BSTask.h"
#include "../../include/IOTask.h"
#include "../../include/QueuedChildren.h"
#include "../../include/QueuedFile.h"
#include "../../include/QueuedParents.h"
#include "../../include/QueuedFileEntry.h"
#include "../../include/BSStream.h"

inline BSStream::BSStream()
{
    m_5c4 = 0;
}

struct FUN_00b60640 : QueuedFileEntry
{
    BSStream m_stream;
    FUN_00b60640(char const* filename);
    virtual ~FUN_00b60640();
};

// @fnv 0x00b60640
FUN_00b60640::FUN_00b60640(char const* filename) : QueuedFileEntry(2)
{
    SetFileName_00c3cee0(filename);
    LookupFileEntryByArchive(0);
}
