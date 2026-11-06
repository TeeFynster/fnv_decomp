#pragma once
// Havok 7.1 Common/Base/Thread/Thread/hkThreadLocalData.h, Win32 multi-threaded branch (the one FNV ships):
// a TLS slot id, sizeof == 4. HK_THREAD_LOCAL(T) == hkThreadLocalData<T>; the release build has no HK_ON_DEBUG checks.
// Used by hkMonitorStream / hkThreadMemory instance pointers (e.g. extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream).

#define HK_WIN32_TLS_INVALID ((unsigned int)0xFFFFFFFF)

extern "C"
{
    __declspec(dllimport) unsigned long __stdcall TlsAlloc(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
    __declspec(dllimport) int __stdcall TlsSetValue(unsigned long dwTlsIndex, void* lpTlsValue);
    __declspec(dllimport) int __stdcall TlsFree(unsigned long dwTlsIndex);
}

template <typename T>
class hkThreadLocalData
{
  public:
    hkThreadLocalData() { m_slotID = TlsAlloc(); }
    ~hkThreadLocalData() { TlsFree(m_slotID); }
    __forceinline T getData() const
    {
        return (T)(unsigned long)TlsGetValue(m_slotID);   // hkUlong
    }
    __forceinline void setData(T p)
    {
        unsigned long v = (unsigned long)(p);
        TlsSetValue(m_slotID, (void*)v);
    }
    unsigned long m_slotID;
};

#ifndef HK_THREAD_LOCAL
#define HK_THREAD_LOCAL(TYPE) hkThreadLocalData<TYPE>
#define HK_THREAD_LOCAL_SET(var, value) var.setData(value)
#define HK_THREAD_LOCAL_GET(var) var.getData()
#endif
