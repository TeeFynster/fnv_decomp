// bscore/memoryusagetracker.cpp: AutoMemContext (1 function)
#include "../../include/AutoMemContext.h"

// @fnv 0x00404ee0
AutoMemContext::~AutoMemContext()
{
    Leave();
}
