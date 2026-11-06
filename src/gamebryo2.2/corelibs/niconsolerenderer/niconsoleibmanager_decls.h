#ifndef NICONSOLEIBMANAGER_DECLS_H
#define NICONSOLEIBMANAGER_DECLS_H

#include <stddef.h>
#include "../../../../include/NiTPointerMap.h"
#include "NiRefObject.h"

struct _D3DINDEXBUFFER_DESC
{
    int Format;
    int Type;
    unsigned long Usage;
    int Pool;
    unsigned int Size;
};

class COMBaseInterface
{
  public:
    virtual void __stdcall vfn_0() = 0;
    virtual void __stdcall vfn_4() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual void __stdcall vfn_c() = 0;
    virtual void __stdcall vfn_10() = 0;
    virtual void __stdcall vfn_14() = 0;
    virtual void __stdcall vfn_18() = 0;
    virtual void __stdcall vfn_1c() = 0;
    virtual void __stdcall vfn_20() = 0;
    virtual void __stdcall vfn_24() = 0;
    virtual void __stdcall vfn_28() = 0;
    virtual long __stdcall Lock(unsigned int, unsigned int, void**, unsigned long) = 0;
    virtual long __stdcall Unlock() = 0;
    virtual long __stdcall GetDesc(_D3DINDEXBUFFER_DESC*) = 0;
};

class Direct3DDeviceInterface
{
  public:
    virtual void __stdcall vfn_0() = 0;
    virtual void __stdcall vfn_4() = 0;
    virtual void __stdcall vfn_8() = 0;
    virtual void __stdcall vfn_c() = 0;
    virtual void __stdcall vfn_10() = 0;
    virtual void __stdcall vfn_14() = 0;
    virtual void __stdcall vfn_18() = 0;
    virtual void __stdcall vfn_1c() = 0;
    virtual void __stdcall vfn_20() = 0;
    virtual void __stdcall vfn_24() = 0;
    virtual void __stdcall vfn_28() = 0;
    virtual void __stdcall vfn_2c() = 0;
    virtual void __stdcall vfn_30() = 0;
    virtual void __stdcall vfn_34() = 0;
    virtual void __stdcall vfn_38() = 0;
    virtual void __stdcall vfn_3c() = 0;
    virtual void __stdcall vfn_40() = 0;
    virtual void __stdcall vfn_44() = 0;
    virtual void __stdcall vfn_48() = 0;
    virtual void __stdcall vfn_4c() = 0;
    virtual void __stdcall vfn_50() = 0;
    virtual void __stdcall vfn_54() = 0;
    virtual void __stdcall vfn_58() = 0;
    virtual void __stdcall vfn_5c() = 0;
    virtual void __stdcall vfn_60() = 0;
    virtual void __stdcall vfn_64() = 0;
    virtual void __stdcall vfn_68() = 0;
    virtual long __stdcall CreateIndexBuffer(unsigned int, unsigned long, int, int, COMBaseInterface**, void*) = 0;
};

class NiConsoleIndexBufferManager__NiConsoleIBInfo;
class IndexBufferManager : public NiRefObject
{
  public:
    Direct3DDeviceInterface* m_pDirect3DDevice;
    COMBaseInterface* m_pCurrentIndexBuffer;
    unsigned int m_uiIndexBufferSize;
    COMBaseInterface* m_pPackedIndexBuffer;
    unsigned int m_uiPackedIndexBufferSize;
    NiTPointerMap<unsigned int, NiConsoleIndexBufferManager__NiConsoleIBInfo*> m_kIndexBufferMap;
    NiTPointerMap<unsigned int, NiConsoleIndexBufferManager__NiConsoleIBInfo*> m_kIndexBufferLookupMap;
    NiTPointerMap<unsigned int, NiConsoleIndexBufferManager__NiConsoleIBInfo*> m_kIndexBufferCacheMap;
    COMBaseInterface* PackBuffer(const unsigned short*, unsigned int, unsigned int, COMBaseInterface*, unsigned int&,
                                 unsigned long, unsigned int);
};
typedef char IndexBufferManager_size_check[(sizeof(IndexBufferManager) == 76) ? 1 : -1];
typedef char IndexBufferManager_device_offset_check[(offsetof(IndexBufferManager, m_pDirect3DDevice) == 8) ? 1 : -1];
typedef char D3DINDEXBUFFER_DESC_size_check[(sizeof(_D3DINDEXBUFFER_DESC) == 20) ? 1 : -1];

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl fnv_zlib_memcpy(void*, const void*, unsigned int);
#endif
