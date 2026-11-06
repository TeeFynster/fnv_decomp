#pragma once

#include "hkReferencedObject.h"
#include "hkBool.h"
#include "hkResult.h"

class hkStreamWriter : public hkReferencedObject
{
public:
    enum SeekWhence
    {
        STREAM_SET = 0,
        STREAM_CUR = 1,
        STREAM_END = 2
    };

    virtual void WriteField(const void* field, const void* data, int flags);
    virtual int write(const void* buf, int len) = 0;
    virtual void WriteArray(int kind, const void* field, const void* data, int bytes, void* allocation);
    virtual hkBool seekTellSupported() const;
    virtual hkResult seek(int offset, SeekWhence whence);
    virtual int tell() const;

    void DispatchWithMode(const void* field, const void* data, int bytes, int flags);
};
