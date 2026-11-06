#include "../../../../../../../../include/hkBsdSocket.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/fd_set.h"
#include "../../../../../../../../include/sockaddr_in.h"
#include "../../../../../../../../include/timeval.h"

// src/havok/common/base/system/io/socket/bsd/hkbsdsocket_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/socket/bsd/hkbsdsocket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// FUN_00ee6d9e: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 21 (setsockopt, stdcall, 5 args).
int __stdcall FUN_00ee6d9e(unsigned int s, int level, int optname, const char* optval, int optlen);

namespace fnv_00da3230 {
inline hkMemoryAllocator& GetHeapAllocator(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

extern "C" int __stdcall FUN_00ee6dbc(int nfds, fd_set* pRead, fd_set* pWrite, fd_set* pExcept,
                                      const timeval* pTimeout);
extern "C" int __stdcall FUN_00ee6db6(unsigned int s, fd_set* pSet);
extern "C" unsigned int __stdcall FUN_00ee6db0(unsigned int s, sockaddr_in* pAddr, int* pAddrLen);
extern "C" unsigned short __stdcall FUN_00ee6daa(unsigned short usNet);
extern "C" char* __stdcall FUN_00ee6da4(unsigned int uiAddr);

struct StrBufD32
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[0x80];

    void InitBuffer();
    void FUN_00cbbd40();
};
void __cdecl FUN_00d61d00(StrBufD32* pBuf, const char* pcFmt, ...);

struct OstreamD32
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00cb1600(char* pcBuf, int iSize);
    OstreamD32& InvokeFromRequest(const StrBufD32& kStr);
    void FUN_00cc00e0();
};

struct ErrorD32
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int message(int eType, int aiSoundId, const char* pcDesc, const char* pcFile, int iLine);
};
extern ErrorD32* DAT_01268360;

}  // namespace fnv_00da3230

// @fnv 0x00da3230
void* hkBsdSocket::FUN_00da3230()
{
    using namespace fnv_00da3230;
    if (m_pSocket != -1)
    {
        fd_set readFds;
        (((fd_set*)(&readFds))->fd_count = 0);
        do
        {
            unsigned int __i;
            for (__i = 0; __i < ((fd_set*)(&readFds))->fd_count; __i++)
            {
                if (((fd_set*)(&readFds))->fd_array[__i] == (m_pSocket))
                {
                    break;
                }
            }
            if (__i == ((fd_set*)(&readFds))->fd_count)
            {
                if (((fd_set*)(&readFds))->fd_count < 64)
                {
                    ((fd_set*)(&readFds))->fd_array[__i] = (m_pSocket);
                    ((fd_set*)(&readFds))->fd_count++;
                }
            }
        } while (0, 0);
        fd_set exceptFds;
        (((fd_set*)(&exceptFds))->fd_count = 0);
        do
        {
            unsigned int __i;
            for (__i = 0; __i < ((fd_set*)(&exceptFds))->fd_count; __i++)
            {
                if (((fd_set*)(&exceptFds))->fd_array[__i] == (m_pSocket))
                {
                    break;
                }
            }
            if (__i == ((fd_set*)(&exceptFds))->fd_count)
            {
                if (((fd_set*)(&exceptFds))->fd_count < 64)
                {
                    ((fd_set*)(&exceptFds))->fd_array[__i] = (m_pSocket);
                    ((fd_set*)(&exceptFds))->fd_count++;
                }
            }
        } while (0, 0);
        timeval t;
        t.tv_sec = 0;
        t.tv_usec = 0;
        int nfds = int(m_pSocket);
        nfds++;
        int numHits = FUN_00ee6dbc(nfds, &readFds, 0, &exceptFds, &t);
        if ((numHits > 0) && FUN_00ee6db6(m_pSocket, &readFds))
        {
            sockaddr_in from;
            int iFromLen = sizeof(from);
            unsigned int s = FUN_00ee6db0(m_pSocket, &from, &iFromLen);
            StrBufD32 kMsg;
            kMsg.InitBuffer();
            FUN_00d61d00(&kMsg, "Socket got connection from [%s:%d]\n", FUN_00ee6da4(from.sin_addr.S_un.S_addr),
                         FUN_00ee6daa(from.sin_port));
            {
                char acBuf[512];
                OstreamD32 kOstr;
                kOstr.FUN_00cb1600(acBuf, sizeof(acBuf));
                kOstr.InvokeFromRequest(kMsg);
                DAT_01268360->message(0, -1, acBuf, ".\\System\\Io\\Socket\\Bsd\\hkBsdSocket.cpp", 0x193);
                kOstr.FUN_00cc00e0();
            }
            if (s == -1)
            {
                kMsg.FUN_00cbbd40();
                return 0;
            }
            int iNoDelay = 1;
            FUN_00ee6d9e(s, 6, 1, (const char*)&iNoDelay, 4);
            void* p = GetHeapAllocator(hkMemoryRouter::getInstance()).blockAlloc(0x24);
            ((unsigned short*)p)[2] = 0x24;
            void* pkSocket = ((hkBsdSocket*)p)->InitWithParam(s);
            kMsg.FUN_00cbbd40();
            return pkSocket;
        }
    }
    return 0;
}
