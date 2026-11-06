#pragma once

#include "hkSocket.h"

class hkBsdSocket : public hkSocket
{
public:
    virtual bool* __thiscall FUN_00da2db0(bool* pOut);
    virtual void __thiscall CloseSocket();
    virtual int Read(void* buf, int len);
    virtual int FUN_00da2e60(int a, int b);
    virtual int FUN_00da2ec0(const char* host, int port);
    virtual int FUN_00da30d0(int iPort) throw();
    virtual bool FUN_00da2f90(int a, int b, int c);
    virtual void* FUN_00da3230();

    void __thiscall Destroy();
    void* __thiscall InitWithParam(int param);
    int FUN_00da2de0();
    bool __thiscall SetNonBlocking(bool blocking);

    unsigned char unk08[0x18];
    int m_pSocket;
};
