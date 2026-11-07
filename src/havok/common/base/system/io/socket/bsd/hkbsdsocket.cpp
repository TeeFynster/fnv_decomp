
// src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/socket/bsd/hkbsdsocket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkBsdSocket.h"
#include "../../../../../../../../include/hkStringBuf.h"
#include "../../../../../../../../include/hkError.h"
#include "../../../../../../../../include/hkOstream.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/sockaddr_in.h"

extern "C" void __stdcall closesocket(int);
// Keep the original out-of-line calls after consolidating the socket declarations.
// @fnv 0x00da2dc0
__declspec(noinline) void hkBsdSocket::CloseSocket()
{
    if (m_pSocket != -1)
    {
        closesocket(m_pSocket);
        m_pSocket = -1;
    }
}

extern int DAT_0102e388;
extern int DAT_010d5030;

// @fnv 0x00da3080
__declspec(noinline) void __thiscall hkBsdSocket::Destroy()
{
    *(int*)this = (int)&DAT_010d5030;
    this->hkBsdSocket::CloseSocket();
    *(int*)((char*)this + 0x14) = (int)&DAT_0102e388;
    *(int*)((char*)this + 8) = (int)&DAT_0102e388;
    *(int*)this = (int)&DAT_0102e388;
}

extern "C" void __cdecl FUN_00d2b850(void);
extern int DAT_010d5030;

// Calls FUN_00d2b850, sets the vtable to DAT_010d5030 and m_pSocket to param, calls FUN_00da2de0 if param is -1, and returns this.
// @fnv 0x00da30a0
void* __thiscall hkBsdSocket::InitWithParam(int param)
{
    FUN_00d2b850();
    *(void**)this = &DAT_010d5030;
    m_pSocket = param;
    if (param == -1)
        createSocket();
    return this;
}

// @fnv 0x00da2db0
// src: HAVOK_LIB 0x00da2db0
bool* hkBsdSocket::isOk_00da2db0(bool* pOut)
{
    *pOut = (m_pSocket != -1);
    return pOut;
}

extern "C" int __stdcall FUN_00ee6d5c(int, int, int, int);
extern "C" int __cdecl FUN_00ee6d50(void);

// @fnv 0x00da2e60
// src: HAVOK_SRC 0x00da2e60
int hkBsdSocket::write_00da2e60(int a, int b)
{
    int r;
    if (m_pSocket != -1)
    {
        r = FUN_00ee6d5c(m_pSocket, a, b, 0);
        if (r > 0 && r != -1)
            return r;
        if (FUN_00ee6d50() != 0x2733)
        {
            CloseSocket();
        }
    }
    return 0;
}

int __stdcall FUN_00ee6d4a(int, int, int);

// @fnv 0x00da2de0
// src: HAVOK_LIB 0x00da2de0
__declspec(noinline) int hkBsdSocket::createSocket()
{
    this->CloseSocket();

    int result = FUN_00ee6d4a(2, 1, 0);
    bool success = result == -1;
    m_pSocket = result;
    return success;
}

extern "C" int __stdcall FUN_00ee6d7a(int, int, int, int);
// @fnv 0x00da2f90
// src: HAVOK_LIB 0x00da2f90
bool hkBsdSocket::asyncSelect(int aiArg1, int aiArg2, int c)
{
    return FUN_00ee6d7a(m_pSocket, aiArg1, aiArg2, ((c & 3) | ((c & 0xc) << 2))) != 0;
}

// FUN_00ee6d9e: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 21 (setsockopt, stdcall, 5 args).
extern "C" __declspec(dllimport) int __stdcall setsockopt(unsigned int s, int level, int optname, const char* optval,
                                                          int optlen);

// @fnv 0x00ee6d9e
// src: COMMUNITY 0x00ee6d9e
int __stdcall setsockopt_0(unsigned int s, int level, int optname, const char* optval, int optlen)
{
    return setsockopt(s, level, optname, optval, optlen);
}

extern "C" int __stdcall FUN_00ee6d56(int, void*, int, int);
extern "C" int __cdecl FUN_00ee6d50(void);

// @fnv 0x00da2e10
int hkBsdSocket::Read(void* buf, int len)
{
    if (m_pSocket != -1)
    {
        int res = FUN_00ee6d56(m_pSocket, buf, len, 0);
        if (res > 0 && res != -1)
        {
            return res;
        }
        if (FUN_00ee6d50() != 0x2733)
        {
            CloseSocket();
        }
    }
    return 0;
}

// InitBuffer initializes the array; the finishing constructor avoids redundant stores.
inline hkStringBuf::hkStringBuf() throw() : m_string(FinishingFlag())
{
    InitBuffer();
}

// FUN_00cbbd40 performs the complete array cleanup in this unit.
template <> __forceinline hkArray<char, hkContainerTempAllocator>::~hkArray()
{
}

inline hkStringBuf::~hkStringBuf() throw()
{
    UpdateFields_00cbbd40();
}

inline hkStringBuf& hkStringBuf::operator=(const char* pcString)
{
    FUN_00d61c10(pcString);
    return *this;
}

// @fnv 0x00cbbd40
// src: GUESS 0x00cbbd40 (confidence: low)
__declspec(noinline) void hkStringBuf::UpdateFields_00cbbd40() throw()
{
    hkMemoryRouter* pHolder = (&hkMemoryRouter::getInstance());
    hkMemoryAllocator* r = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_temp);
    int iOldValue = m_string.m_iCapacityState;
    m_string.m_iElementCount = 0;
    if (!(iOldValue & 0x80000000))
        r->bufFree(m_string.m_data, iOldValue & 0x3fffffff);
    m_string.m_data = 0;
    m_string.m_iCapacityState = 0x80000000;
}

extern "C" int __stdcall FUN_00ee6d80(unsigned int s, long lCmd, unsigned long* pulArg);

// Sets the socket to non-blocking mode via FUN_00ee6d80 and returns whether the call succeeded.
// @fnv 0x00da2fc0
bool hkBsdSocket::SetNonBlocking(bool blocking)
{
    bool* pBlocking = &blocking;
    volatile unsigned long ulNonBlocking;

    ulNonBlocking = (*pBlocking == 0);

    int result = FUN_00ee6d80(m_pSocket, 0x8004667e, const_cast<unsigned long*>(&ulNonBlocking));

    return !!result;
}

extern char DAT_01269acc;
extern const char str_010d5004[];
extern const char str_010d4fdc[];
int __stdcall WSAStartup_0(unsigned short, void*);

extern hkError* DAT_01268360;

// When the flag is clear, calls FUN_00ee6d86 with 0x202, reports failure, and sets the flag.
// @fnv 0x00da2ff0
void InitWinsock()
{
    if (DAT_01269acc == 0)
    {
        struct
        {
            int wsa[0x64];
            int buf[0x80];
        } L;
        if (WSAStartup_0(0x202, L.wsa) == -1)
        {
            unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
            hkOstream& ostr = *reinterpret_cast<hkOstream*>(streamStorage);
            ostr.FUN_00cb1600(L.buf, 0x200);
            ostr.ProcessAndReturnValue_00cc01c0(str_010d5004);
            if (DAT_01268360->message(3, 0x321825f8, (const char*)L.buf, str_010d4fdc, 0x48))
                __debugbreak();
            ostr.FUN_00cc00e0();
        }
        DAT_01269acc = 1;
    }
}

extern "C" void __cdecl hkString_memSet(void*, int, unsigned int);
extern "C" void __cdecl hkString_memCpy(void*, const void*, unsigned int);
extern "C" int __stdcall FUN_00ee6d74(int);
extern "C" int __stdcall FUN_00ee6d6e(const char*);
extern "C" int __stdcall FUN_00ee6d68(const char*);
extern "C" int __stdcall FUN_00ee6d62(int, void*, int);
extern "C" int __cdecl FUN_00ee6d50(void);

// src: HAVOK_LIB 0x00da2eb0
static __declspec(noinline) bool* hkIsDigit(int c, bool* out)
{
    *out = false;
    if (c >= '0' && c <= '9')
        *out = true;
    return out;
}

struct HostEntry
{
    char* name;
    char** aliases;
    short address_type;
    short address_length;
    char** addresses;
};

// Resolves the host to an IPv4 address, ensures a socket exists, and calls the connection routine with the address and port.
// @fnv 0x00da2ec0
// src: HAVOK_LIB 0x00da2ec0
int hkBsdSocket::connect(const char* host, int port)
{
    // Word storage preserves the original stack protection with the shared sin_zero character array.
    unsigned int targetStorage[sizeof(sockaddr_in) / sizeof(unsigned int)];
    sockaddr_in& target = *reinterpret_cast<sockaddr_in*>(targetStorage);
    hkString_memSet(&target, 0, sizeof(target));
    target.sin_family = 2;
    target.sin_port = (unsigned short)FUN_00ee6d74(port);

    if (*hkIsDigit(host[0], (bool*)&port))
    {
        target.sin_addr.S_un.S_addr = FUN_00ee6d6e(host);
    }
    else
    {
        HostEntry* pHostEntry = (HostEntry*)FUN_00ee6d68(host);
        if (!pHostEntry)
            return 1;
        hkString_memCpy(&target.sin_addr.S_un.S_addr, pHostEntry->addresses[0], pHostEntry->address_length);
    }

    if (m_pSocket == -1 && createSocket())
        return 1;
    int iResult = FUN_00ee6d62(m_pSocket, &target, sizeof(target));
    if (iResult != -1)
        goto success;
    if (FUN_00ee6d50() == 0x2733)
        goto success;
    CloseSocket();
    return 1;
success:
    return 0;
}

unsigned short __stdcall FUN_00ee6d74(unsigned short usHostShort);
int __stdcall bind_0(unsigned int s, const void* pvName, int iNameLen);
int __stdcall listen_0(unsigned int s, int iBacklog);
int __stdcall gethostname_0(char* pcName, int iNameLen);
extern "C" int __stdcall setsockopt_0(unsigned int s, int level, int option, const void* value, int size);

extern const char str_010d505c[];
extern const char str_010d5070[];

// Shared hkOstream lacks the overload taking hkStringBuf at 0x00cc05f0.
extern "C" __declspec(nothrow) void AppendSocketHost();
typedef hkOstream& (__thiscall *AppendSocketHostMethod)(hkOstream*, const hkStringBuf&);

// Binds the socket to the given port, sets it to listen with backlog 2, and logs the host name and port.
// @fnv 0x00da30d0
// src: HAVOK_LIB 0x00da30d0
int hkBsdSocket::listen_00da30d0(int iPort) throw()
{
    if (createSocket() != 0)
        return 1;

    // Word storage preserves the original stack protection with the shared sin_zero character array.
    unsigned int nameStorage[sizeof(sockaddr_in) / sizeof(unsigned int)];
    sockaddr_in& kName = *reinterpret_cast<sockaddr_in*>(nameStorage);
    kName.sin_family = 2;
    kName.sin_addr.S_un.S_addr = 0;
    kName.sin_port = FUN_00ee6d74((unsigned short)iPort);

    int iOn = 1;
    setsockopt_0(m_pSocket, 0xffff, 4, (const void*)&iOn, sizeof(int));

    if (bind_0(m_pSocket, &kName, sizeof(kName)) == -1)
    {
        CloseSocket();
        return 1;
    }
    if (listen_0(m_pSocket, 2) == -1)
    {
        CloseSocket();
        return 1;
    }

    hkStringBuf kHost;
    unsigned int auiHostName[64];
    gethostname_0((char*)auiHostName, sizeof(auiHostName));
    kHost = (const char*)auiHostName;
    {
        unsigned int auiReportBuf[128];
        hkOstream kReportStream(auiReportBuf, sizeof(auiReportBuf));
        reinterpret_cast<AppendSocketHostMethod>(AppendSocketHost)(
            &kReportStream.ProcessAndReturnValue_00cc01c0(str_010d505c), kHost).ProcessAndReturnValue_00cc01c0(str_010d5070).WriteInt(iPort);
        DAT_01268360->message(0, -1, (const char*)auiReportBuf, str_010d4fdc, 364);
    }
    return 0;
}

// Scalar deleting wrapper: ECX holds self; the unused EDX preserves the thiscall stack arguments.
// @fnv 0x00da33d0
hkBsdSocket* __fastcall DestroySocket(hkBsdSocket* self, void*, bool flag)
{
    self->Destroy();
    if (flag & 1)
    {
        hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(self, self->m_usMemSizeAndFlags);
    }
    return self;
}
