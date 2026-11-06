#pragma once

#include <cstddef>
#include "hkOstream.h"

class hkErrStream : public hkOstream
{
public:
    hkErrStream(void* buf, int bufSize) throw();
    virtual ~hkErrStream() throw();

    hkErrStream& operator<<(const char* str) throw();

    static void* __cdecl operator new(std::size_t size, void* p);
};
