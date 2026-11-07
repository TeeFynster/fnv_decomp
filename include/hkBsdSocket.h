#pragma once

#include "hkSocket.h"

class hkBsdSocket : public hkSocket
{
public:
    virtual bool* __thiscall isOk_00da2db0(bool* pOut);
    virtual void __thiscall CloseSocket();
    virtual int Read(void* buf, int len);
    virtual int write_00da2e60(int a, int b);
    virtual int connect(const char* host, int port);
    virtual int listen_00da30d0(int iPort) throw();
    virtual bool asyncSelect(int a, int b, int c);
    virtual void* pollForNewClient();

    void __thiscall Destroy();
    void* __thiscall InitWithParam(int param);
    int createSocket();
    bool __thiscall SetNonBlocking(bool blocking);

    unsigned char unk08[0x18];
    int m_pSocket;
};
