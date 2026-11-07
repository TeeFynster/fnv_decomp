#include "../../../../include/hkArray.h"

// src/havok/common/visualize/hkserverdebugdisplayhandler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkserverdebugdisplayhandler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_VEC4_SIMD
#include "../../../../include/Vec4.h"

extern int DAT_010d7cfc;
void __cdecl _Deallocate(void*);
struct FUN_00dd97c0
{
    int* m_p;
    FUN_00dd97c0(char f);
};
// @fnv 0x00dd97c0
FUN_00dd97c0::FUN_00dd97c0(char acFlags)
{
    m_p = &DAT_010d7cfc;
    if (acFlags & 1)
        _Deallocate(this);
}

extern "C" __declspec(dllimport) void __stdcall _fnv_EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);
struct FUN_00d605d0_Class
{
    void hkOArchive_write32u(unsigned int value);
    void hkOArchive_write8u(unsigned int value);
    void hkDisplaySerializeOStream_writeQuadVector4(unsigned int value);
    void hkOArchive_WriteBinaryData_Thunk_00d609e0(__int64 value);
    void WriteInt(unsigned int value);
    const char* ForwardValueToObject(unsigned int* value);
};
struct Record
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    bool SetConfigValues(unsigned int a, unsigned int b, unsigned int c, int d, unsigned int e);
};
// Locks the critical section, writes five values to config, reads back a string, and returns whether the read-back string is empty.
// @fnv 0x00dd9b40
bool Record::SetConfigValues(unsigned int uiValueA, unsigned int uiValueB, unsigned int uiValueC, int iValueD,
                             unsigned int uiValueE)
{
    _fnv_EnterCriticalSection(criticalSection);
    if (config)
    {
        config->hkOArchive_write32u(0x29);
        config->hkOArchive_write8u(8);
        config->hkDisplaySerializeOStream_writeQuadVector4(uiValueA);
        config->hkDisplaySerializeOStream_writeQuadVector4(uiValueB);
        config->hkOArchive_write32u(uiValueC);
        config->hkOArchive_WriteBinaryData_Thunk_00d609e0(iValueD);
        config->WriteInt(uiValueE);
    }
    bool hasValue;
    if (config)
    {
        const char* value = config->ForwardValueToObject(&uiValueA);
        if (value[0] == 0)
            goto noValue;
        hasValue = true;
        goto valueChecked;
    noValue:
        hasValue = false;
    valueChecked:;
    }
    else
        hasValue = false;
    _fnv_LeaveCriticalSection(criticalSection);
    return !hasValue;
}

struct FUN_00dd9ab0_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_pWorldLock;
    bool hkServerDebugDisplayHandler_displayPoint(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

// @fnv 0x00dd9ab0
// src: HAVOK_LIB 0x00dd9ab0
bool FUN_00dd9ab0_cls::hkServerDebugDisplayHandler_displayPoint(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
    bool ok;
    _fnv_EnterCriticalSection(m_pWorldLock);
    if (m_pConfiguration != 0)
    {
        m_pConfiguration->hkOArchive_write32u(0x1d);
        m_pConfiguration->hkOArchive_write8u(7);
        m_pConfiguration->hkDisplaySerializeOStream_writeQuadVector4(a1);
        m_pConfiguration->hkOArchive_write32u(a2);
        m_pConfiguration->hkOArchive_WriteBinaryData_Thunk_00d609e0(a3);
        m_pConfiguration->WriteInt(a4);
    }
    if (m_pConfiguration == 0)
    {
        goto not_found;
    }
    {
        const char* s = m_pConfiguration->ForwardValueToObject(&a1);
        if (*s != 0)
        {
            ok = true;
            goto done;
        }
    }
not_found:
    ok = false;
done:
    _fnv_LeaveCriticalSection(m_pWorldLock);
    return !ok;
}

struct ConfigExt
{
    void unk607b0(unsigned int a, unsigned int b);
};

struct FUN_00dd9be0_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_cs;
    bool hkServerDebugDisplayHandler_sendMemStatsDump(unsigned int a, unsigned int b);
};

// @fnv 0x00dd9be0
// src: HAVOK_LIB 0x00dd9be0
bool FUN_00dd9be0_cls::hkServerDebugDisplayHandler_sendMemStatsDump(unsigned int auiValue, unsigned int auiParam)
{
    _fnv_EnterCriticalSection(m_cs);
    if (m_pConfiguration != 0)
    {
        unsigned int v = auiParam;
        m_pConfiguration->hkOArchive_write32u(v + 5);
        m_pConfiguration->hkOArchive_write8u(0xf);
        m_pConfiguration->WriteInt(v);
        ((ConfigExt*)m_pConfiguration)->unk607b0(auiValue, v);
    }
    bool result;
    if (m_pConfiguration != 0)
    {
        const char* s = m_pConfiguration->ForwardValueToObject(&auiParam);
        if (*s == 0)
        {
            goto zero;
        }
        result = true;
        goto done;
    }
zero:
    result = false;
done:
    _fnv_LeaveCriticalSection(m_cs);
    return !result;
}

struct S_00dd9c60
{
    int unk00;
    FUN_00d605d0_Class* unk04;
    void* unk08;
    bool hkServerDebugDisplayHandler_holdImmediate();
};
// @fnv 0x00dd9c60
// src: HAVOK_LIB 0x00dd9c60
bool S_00dd9c60::hkServerDebugDisplayHandler_holdImmediate()
{
    _fnv_EnterCriticalSection(unk08);
    if (unk04)
    {
        unk04->hkOArchive_write32u(1);
        unk04->hkOArchive_write8u(0xb);
    }
    bool r;
    char c;
    if (unk04 && *unk04->ForwardValueToObject((unsigned int*)&c) != 0)
        r = true;
    else
        r = false;
    _fnv_LeaveCriticalSection(unk08);
    return !r;
}

int __cdecl hkDisplaySerializeOStream_computeBytesRequired_00dda850(const char* str);

typedef hkArray<const char*> DD9D70StringArray;

// @fnv 0x00dd9d70
// src: HAVOK_LIB 0x00dd9d70
static __declspec(noinline) int _getGeometryByteSize(const DD9D70StringArray& strings)
{
    int size = 4;
    for (int i = 0; i < strings.m_iElementCount; i++)
    {
        const char* const& s = strings.m_data[i];
        size += hkDisplaySerializeOStream_computeBytesRequired_00dda850(s);
    }
    return size;
}

// Caller so the file-static helper is emitted with its register calling convention.
int DD9D70ComputeSize(const DD9D70StringArray* a, const DD9D70StringArray* b)
{
    return _getGeometryByteSize(*a) + _getGeometryByteSize(*b);
}

extern "C" __declspec(dllimport) void __stdcall _fnv_EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);

class ConfigStub
{
  public:
    void WriteShape(unsigned int value);
};

struct ItemList
{
    unsigned int* m_pItems;
    int m_iArrayLength;
};

class FUN_00dd9da0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    FUN_00d605d0_Class* m_pConfig;
    void* m_pUserData;

    void ApplyItemList(ItemList* pList);
};

// @fnv 0x00dd9da0
void FUN_00dd9da0_cls::ApplyItemList(ItemList* pItemList)
{
    int i;

    _fnv_EnterCriticalSection(m_pUserData);
    m_pConfig->WriteInt(pItemList->m_iArrayLength);
    for (i = 0; i < pItemList->m_iArrayLength; i++)
    {
        ((ConfigStub*)m_pConfig)->WriteShape(pItemList->m_pItems[i]);
    }
    _fnv_LeaveCriticalSection(m_pUserData);
}

extern int DAT_010d7cfc;
void __cdecl _Deallocate(void*);

extern "C" __declspec(dllimport) void __stdcall _fnv_EnterCriticalSection(void* section);
extern "C" __declspec(dllimport) void __stdcall _fnv_LeaveCriticalSection(void* section);

struct ParentRec
{
    void ApplyItemList(unsigned int value);
};

struct ConfigAux
{
    void WriteTransform(unsigned int value);
};

unsigned int _getGeometryByteSize();

struct FUN_00dd9df0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    bool hkServerDebugDisplayHandler_addGeometry(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);
};

// Locks the critical section, applies the given values to config and parent, then returns whether the config's check fails.
// @fnv 0x00dd9df0
// src: HAVOK_LIB 0x00dd9df0
bool FUN_00dd9df0_cls::hkServerDebugDisplayHandler_addGeometry(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
    _fnv_EnterCriticalSection(this->criticalSection);
    if (this->config != 0)
    {
        unsigned int uiValue1Copy = a1;
        unsigned int v = _getGeometryByteSize();
        this->config->WriteInt(v + 0x29);
        this->config->hkOArchive_write8u(1);
        ((ParentRec*)((char*)this - 8))->ApplyItemList(uiValue1Copy);
        ((ConfigAux*)this->config)->WriteTransform(a2);
        this->config->hkOArchive_WriteBinaryData_Thunk_00d609e0(a3);
        this->config->WriteInt(a4);
    }
    bool ok;
    if (this->config == 0)
    {
        goto notok;
    }
    if (*this->config->ForwardValueToObject(&a1) != 0)
    {
        ok = true;
        goto done;
    }
notok:
    ok = false;
done:
    _fnv_LeaveCriticalSection(this->criticalSection);
    return !ok;
}

unsigned int _getGeometryByteSize();

struct FUN_00dd9da0_ext
{
    void ApplyItemList(unsigned int value);
};

struct FUN_00dd9f40_cls
{
    int unk00;
    FUN_00d605d0_Class* m_pConfiguration;
    void* m_pWorldLock;
    bool SetAndCheck(unsigned int a1, unsigned int a2, int a3, unsigned int a4);
};

// @fnv 0x00dd9f40
bool FUN_00dd9f40_cls::SetAndCheck(unsigned int uiValue, unsigned int a2, int a3, unsigned int a4)
{
    bool ok;
    _fnv_EnterCriticalSection(m_pWorldLock);
    if (m_pConfiguration != 0)
    {
        unsigned int v = uiValue;
        m_pConfiguration->WriteInt(_getGeometryByteSize() + 0x11);
        m_pConfiguration->hkOArchive_write8u(6);
        reinterpret_cast<FUN_00dd9da0_ext*>((char*)this - 8)->ApplyItemList(v);
        m_pConfiguration->hkOArchive_write32u(a2);
        m_pConfiguration->hkOArchive_WriteBinaryData_Thunk_00d609e0((__int64)a3);
        m_pConfiguration->WriteInt(a4);
    }
    if (m_pConfiguration == 0)
    {
        goto not_found;
    }
    {
        const char* s = m_pConfiguration->ForwardValueToObject(&uiValue);
        if (*s != 0)
        {
            ok = true;
            goto done;
        }
    }
not_found:
    ok = false;
done:
    _fnv_LeaveCriticalSection(m_pWorldLock);
    return !ok;
}

struct FUN_00d605d0_ext
{
    void hkOArchive_writeRaw(unsigned int a, unsigned int len);
    void WriteUInt16(unsigned int len);
};

int hkString_strLen(unsigned int value);

struct FUN_00dda0e0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    int hkServerDebugDisplayHandler_displayText(unsigned int a, unsigned int b, int c, unsigned int d);
};

// @fnv 0x00dda0e0
// src: HAVOK_LIB 0x00dda0e0
int FUN_00dda0e0_cls::hkServerDebugDisplayHandler_displayText(volatile unsigned int auiValue, unsigned int b, int c, unsigned int d)
{
    _fnv_EnterCriticalSection(criticalSection);
    if (config != 0)
    {
        unsigned int v = auiValue;
        int len = hkString_strLen(v);
        int n = (len < 0xffff) ? len : 0xffff;
        config->hkOArchive_write32u(n + 0x13);
        config->hkOArchive_write8u(9);
        reinterpret_cast<FUN_00d605d0_ext*>(config)->WriteUInt16(n);
        reinterpret_cast<FUN_00d605d0_ext*>(config)->hkOArchive_writeRaw(v, n);
        config->WriteInt(b);
        config->hkOArchive_WriteBinaryData_Thunk_00d609e0((__int64)c);
        config->WriteInt(d);
    }
    bool ok = (config != 0) && (config->ForwardValueToObject((unsigned int*)&auiValue)[0] != 0);
    _fnv_LeaveCriticalSection(criticalSection);
    return !ok;
}

int __cdecl hkString_strLen(const char* text);

struct FUN_00d605d0_ext_cls
{
    void WriteUInt16(unsigned int value);
    void hkOArchive_writeRaw(const char* text, unsigned int length);
    void HashUInt(float value);
};

struct FUN_00dda1a0_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;

    bool WriteConfigEntry(const char* name, const float* vec, unsigned int a, int b, unsigned int c);
};

// @fnv 0x00dda1a0
bool FUN_00dda1a0_cls::WriteConfigEntry(const char* name, const float* vec, unsigned int uiValueA, int iValueB,
                                        unsigned int uiValueC)
{
    _fnv_EnterCriticalSection(criticalSection);
    if (config != 0)
    {
        int n = hkString_strLen(name);
        int length = (n < 0xffff) ? n : 0xffff;
        config->hkOArchive_write32u(length + 0x1f);
        config->hkOArchive_write8u(0x11);
        reinterpret_cast<FUN_00d605d0_ext_cls*>(config)->WriteUInt16(length);
        reinterpret_cast<FUN_00d605d0_ext_cls*>(config)->hkOArchive_writeRaw(name, length);
        config->WriteInt(uiValueA);
        config->hkOArchive_WriteBinaryData_Thunk_00d609e0((__int64)iValueB);
        config->WriteInt(uiValueC);
        reinterpret_cast<FUN_00d605d0_ext_cls*>(config)->HashUInt(vec[0]);
        reinterpret_cast<FUN_00d605d0_ext_cls*>(config)->HashUInt(vec[1]);
        reinterpret_cast<FUN_00d605d0_ext_cls*>(config)->HashUInt(vec[2]);
    }
    bool result;
    if (config == 0)
    {
        goto done;
    }
    {
        unsigned int id;
        const char* text = config->ForwardValueToObject(&id);
        if (text[0] != 0)
        {
            result = true;
            goto out;
        }
    }
done:
    result = false;
out:
    _fnv_LeaveCriticalSection(criticalSection);
    return !result;
}

struct FUN_00dda290_ext
{
    void hkOArchive_writeRaw(unsigned int a, unsigned int len);
    void WriteUInt16(unsigned int len);
};

int hkString_strLen(unsigned int value);

struct FUN_00dda290_cls
{
    int unk00;
    FUN_00d605d0_Class* config;
    void* criticalSection;
    int WriteConfigValue(unsigned int a, int b, unsigned int c);
};

// @fnv 0x00dda290
int FUN_00dda290_cls::WriteConfigValue(volatile unsigned int a, int aiValue, unsigned int c)
{
    _fnv_EnterCriticalSection(criticalSection);
    if (config != 0)
    {
        unsigned int v = a;
        int len = hkString_strLen(v);
        int n = (len < 0xffff) ? len : 0xffff;
        config->hkOArchive_write32u(n + 0xf);
        config->hkOArchive_write8u(0x14);
        reinterpret_cast<FUN_00dda290_ext*>(config)->WriteUInt16(n);
        reinterpret_cast<FUN_00dda290_ext*>(config)->hkOArchive_writeRaw(v, n);
        config->hkOArchive_WriteBinaryData_Thunk_00d609e0((__int64)aiValue);
        config->WriteInt(c);
    }
    bool ok = (config != 0) && (config->ForwardValueToObject((unsigned int*)&a)[0] != 0);
    _fnv_LeaveCriticalSection(criticalSection);
    return !ok;
}

#include <xmmintrin.h>
#include <windows.h>
struct DD97E0Vector4
{
    __m128 m_vComponents;
};

struct __declspec(align(16)) DD97E0Point
{
    float x;
    float y;
    float z;
    float w;
};

struct DD97E0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD97E0OStream
{
    void writeCommand(unsigned int value);
    void writeCount(unsigned int value);
    void writeVector(const DD97E0Point& v);
    void writeUint64(unsigned __int64 value);
    void writeTag(int value);
    DD97E0Bool IsStreamValid();
};

struct DD97E0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD97E0DisplayHandler
{
    int unk00;
    DD97E0OStream* m_pDisplayStream;
    DD97E0CriticalSection* m_pSynchronizationLock;

    int hkServerDebugDisplayHandler_addGeometryInstance(int a, int b, int c, int d, int e);
};

// Locks m_pSynchronizationLock, checks m_pDisplayStream and its IsStreamValid, then returns 0 if valid or 1 otherwise.
// @fnv 0x00dd97e0
// src: HAVOK_LIB 0x00dd97e0
int DD97E0DisplayHandler::hkServerDebugDisplayHandler_addGeometryInstance(int aUnused, int bUnused, int c, int dUnused, int eUnused)
{
    m_pSynchronizationLock->enter();
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}

struct FUN_00d60940_Class
{
    void WriteInt(unsigned int);
};
struct Stream : FUN_00d605d0_Class
{
    void hkOArchive_write32u(unsigned int);
    void hkOArchive_WriteBinaryData_Thunk_00d609e0(unsigned int, int);
    char* ForwardValueToObject(void*);
};
struct Output
{
    int state;
    Stream* stream;
    CRITICAL_SECTION* lock;
    int WriteRecord(unsigned int, unsigned int, unsigned int);
};
// Under the lock, writes command 17, count 3, and the three arguments, then returns the negation of the forwarded value's first byte.
// @fnv 0x00dd9830
int Output::WriteRecord(unsigned int first, unsigned int second, unsigned int third)
{
    EnterCriticalSection(lock);
    if (stream)
    {
        stream->hkOArchive_write32u(17);
        stream->hkOArchive_write8u(3);
        stream->hkOArchive_write32u(first);
        stream->hkOArchive_WriteBinaryData_Thunk_00d609e0(second, 0);
        ((FUN_00d60940_Class*)stream)->WriteInt(third);
    }
    bool failed = stream && *stream->ForwardValueToObject(&first);
    LeaveCriticalSection(lock);
    return !failed;
}

enum S_00dd98c0_Result
{
    S_00dd98c0_SUCCESS = 0,
    S_00dd98c0_FAILURE = 1
};
struct S_00dd98c0_Bool
{
    char m_cBooleanValue;
    S_00dd98c0_Bool()
    {}
};
struct S_00dd98c0_Target
{
    void hkOArchive_write32u(int a);
    void hkOArchive_write8u(int a);
    void WriteTransform(int a);
    void hkOArchive_WriteBinaryData_Thunk_00d609e0(int a, int b);
    void WriteInt(int a);
    S_00dd98c0_Bool ForwardValueToObject();
};
struct S_00dd98c0
{
    int unk0;
    S_00dd98c0_Target* unk4;
    CRITICAL_SECTION* unk8;
    S_00dd98c0_Result WriteValue(int a1, int a2, int a3);
};
// Writes a1, a2, a3 to unk4 under unk8, then returns SUCCESS if unk4 and ForwardValueToObject() are true, else FAILURE.
// @fnv 0x00dd98c0
S_00dd98c0_Result S_00dd98c0::WriteValue(int a1, int a2, int a3)
{
    EnterCriticalSection(unk8);
    if (unk4)
    {
        unk4->hkOArchive_write32u(0x29);
        unk4->hkOArchive_write8u(2);
        unk4->WriteTransform(a1);
        unk4->hkOArchive_WriteBinaryData_Thunk_00d609e0(a2, 0);
        unk4->WriteInt(a3);
    }
    bool ok = unk4 && unk4->ForwardValueToObject().m_cBooleanValue;
    LeaveCriticalSection(unk8);
    return ok ? S_00dd98c0_SUCCESS : S_00dd98c0_FAILURE;
}

struct DD9950Bool
{
    char m_cBooleanValue;

    DD9950Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

enum DD9950Result
{
    DD9950_SUCCESS = 0,
    DD9950_FAILURE = 1
};

struct DD9950CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD9950OArchive
{
    void WriteUint8(unsigned char v);
    void WriteUint32(unsigned int v);
    void WriteUint64(unsigned __int64 v);
    void WriteInt32(int v);
    DD9950Bool IsStreamValid() const;
};

struct DD9950DisplayServer
{
    int unk00;
    DD9950OArchive* m_pDisplayStream;
    DD9950CriticalSection* m_outStreamLock;

    DD9950Result hkServerDebugDisplayHandler_removeGeometry(unsigned long id, int tag, unsigned long shapeIdHint);
};

// @fnv 0x00dd9950
// src: HAVOK_LIB 0x00dd9950
DD9950Result DD9950DisplayServer::hkServerDebugDisplayHandler_removeGeometry(unsigned long id, int tag, unsigned long shapeIdHint)
{
    m_outStreamLock->enter();
    if (m_pDisplayStream)
    {
        m_pDisplayStream->WriteUint8(0xd);
        m_pDisplayStream->WriteUint32(4);
        m_pDisplayStream->WriteUint64(id);
        m_pDisplayStream->WriteInt32(tag);
    }
    bool streamOk = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_outStreamLock->leave();
    return streamOk ? DD9950_SUCCESS : DD9950_FAILURE;
}

namespace fnv_00dd99d0 {
struct DD99D0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD99D0OStream
{
    void writeUint32(unsigned int value);
    void writeCommand(unsigned int value);
    void writeVector(const void* v);
    void writeFloat(float value);
    void writeInt32(int value);
    void WriteByteArray(const char* data, int length);
    DD99D0Bool IsStreamValid();
};

struct DD99D0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

extern "C" int __cdecl hkString_strLen(const char* str);

struct DD99D0DisplayHandler
{
    int unk00;
    DD99D0OStream* m_pDisplayStream;
    DD99D0CriticalSection* m_pSynchronizationLock;

    int WriteDisplayCommand(const void* a, const void* b, const void* c, float x, float y, float z, const char* text);
};

// Writes a display command with three vectors, three floats, and a text string to m_pDisplayStream under m_pSynchronizationLock.
// @fnv 0x00dd99d0
int DD99D0DisplayHandler::WriteDisplayCommand(const void* apVector1, const void* apVector2, const void* apVector3,
                                              float x, float y, float z, const char* text)
{
    m_pSynchronizationLock->enter();
    if (m_pDisplayStream)
    {
        int length = hkString_strLen(text);
        m_pDisplayStream->writeUint32(length + 0x33);
        m_pDisplayStream->writeCommand(0xd);
        m_pDisplayStream->writeVector(apVector1);
        m_pDisplayStream->writeVector(apVector2);
        m_pDisplayStream->writeVector(apVector3);
        m_pDisplayStream->writeFloat(x);
        m_pDisplayStream->writeFloat(y);
        m_pDisplayStream->writeFloat(z);
        m_pDisplayStream->writeInt32(length);
        m_pDisplayStream->WriteByteArray(text, length);
    }
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}
}  // namespace fnv_00dd99d0

struct DD9FE0Vector4
{
    __m128 m_vComponents;
};

struct __declspec(align(16)) DD9FE0Point
{
    float x;
    float y;
    float z;
    float w;
};

struct DD9FE0Bool
{
    char m_cBooleanValue;

    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct DD9FE0OStream
{
    void writeCommand(unsigned int value);
    void writeCount(unsigned int value);
    void writeVector(const DD9FE0Point& v);
    void writeUint64(unsigned __int64 value);
    void writeTag(int value);
    DD9FE0Bool IsStreamValid();
};

struct DD9FE0CriticalSection
{
    CRITICAL_SECTION m_kCriticalSection;

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }
    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};

struct DD9FE0DisplayHandler
{
    int unk00;
    DD9FE0OStream* m_pDisplayStream;
    DD9FE0CriticalSection* m_pSynchronizationLock;

    int WriteTriangle(const DD9FE0Vector4& a, const DD9FE0Vector4& b, const DD9FE0Vector4& c, unsigned int color,
                      int id, int tag);
};

// Writes three line segments forming a triangle to the display stream under a critical section, returning 0 on success or 1 if the stream is missing or invalid.
// @fnv 0x00dd9fe0
int DD9FE0DisplayHandler::WriteTriangle(const DD9FE0Vector4& a, const DD9FE0Vector4& b, const DD9FE0Vector4& c,
                                        unsigned int color, int id, int tag)
{
    m_pSynchronizationLock->enter();
    if (m_pDisplayStream)
    {
        DD9FE0Point verts[4];
        *(__m128*)&verts[0] = a.m_vComponents;
        *(__m128*)&verts[1] = b.m_vComponents;
        *(__m128*)&verts[2] = c.m_vComponents;
        *(__m128*)&verts[3] = a.m_vComponents;
        unsigned __int64 id64 = id;
        for (int i = 0; i < 3; i++)
        {
            m_pDisplayStream->writeCommand(0x29);
            m_pDisplayStream->writeCount(8);
            m_pDisplayStream->writeVector(verts[i]);
            m_pDisplayStream->writeVector(verts[i + 1]);
            m_pDisplayStream->writeCommand(color);
            m_pDisplayStream->writeUint64(id64);
            m_pDisplayStream->writeTag(tag);
        }
    }
    bool ok = m_pDisplayStream && m_pDisplayStream->IsStreamValid();
    m_pSynchronizationLock->leave();
    return ok ? 0 : 1;
}

struct __declspec(align(16)) Transform_dda340
{
    Vec4 rotation0;
    Vec4 rotation1;
    Vec4 rotation2;
    Vec4 translation;
};

struct QsTransform_dda340
{
    Vec4 translation;
    Vec4 rotation;
    Vec4 scale;

    void Object_ForwardCall_00ce5300(Transform_dda340* out);
};

struct MemoryAllocator_dda340
{
    virtual void* vfn0() = 0;
    virtual void* vfn1() = 0;
    virtual void* vfn2() = 0;
    virtual void* vfn3() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
};

struct ThreadMemory_dda340
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemoryAllocator_dda340* m_pMemoryAllocator;
};

ThreadMemory_dda340* hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elemSize);



class Array_dda340LocalForm
{ // local form of hkArray: 0x00dda340 needs the original inline/out-of-line helper split; shared replacement changes bytes.
  public:
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    Array_dda340LocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        ThreadMemory_dda340* mem = hkMemoryRouter_getInstance();
        MemoryAllocator_dda340* alloc = mem->m_pMemoryAllocator;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->ReleaseBlock(m_data, (cap & 0x3fffffff) * sizeof(int));
        }
    }

    void AddBack(int val)
    {
        ThreadMemory_dda340* mem = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(mem->m_pMemoryAllocator, this, sizeof(int));
        }
        m_data[m_iElementCount++] = val;
    }
};

struct Config_dda340 : public FUN_00d605d0_Class
{
    void WriteUInt16(unsigned int value);
    void hkOArchive_writeRaw(const char* text, unsigned int length);
    void WriteTransform(const Transform_dda340* t);
};

// 0x00dda340 serializes behavior arrays via the display stream at +4 under the lock at +8.
struct BehaviorGraphDisplaySerializer
{
    int unk00;
    Config_dda340* config;
    void* criticalSection;

    bool Write(const hkArrayBase<unsigned int>& a1, const hkArrayBase<unsigned int>& a2,
               const hkArrayBase<unsigned int>& a3, const hkArrayBase<Vec4>& a4,
               const hkArrayBase<const char*>& a5, const hkArrayBase<unsigned int>& a6,
               const hkArrayBase<unsigned int>& a7, const hkArrayBase<QsTransform_dda340>& a8);
};

// Writes supplied data when a config exists; returns false only when the forwarded value is nonzero.
// @fnv 0x00dda340
bool BehaviorGraphDisplaySerializer::Write(const hkArrayBase<unsigned int>& a1, const hkArrayBase<unsigned int>& a2,
                          const hkArrayBase<unsigned int>& a3, const hkArrayBase<Vec4>& a4,
                          const hkArrayBase<const char*>& a5, const hkArrayBase<unsigned int>& a6,
                          const hkArrayBase<unsigned int>& a7, const hkArrayBase<QsTransform_dda340>& a8)
{
    _fnv_EnterCriticalSection(this->criticalSection);
    if (this->config)
    {
        int size2 = a2.m_iElementCount;
        int iVec4Count = a4.m_iElementCount;
        int totalSize = ((size2 + iVec4Count * 2) * 2 + a8.m_iElementCount * 7 + a6.m_iElementCount + a7.m_iElementCount) * 4 + 25;
        Array_dda340LocalForm stringLengths;
        for (int i = 0; i < a5.m_iElementCount; ++i)
        {
            if (a5.m_data[i] != 0)
            {
                totalSize += 2;
                int len = hkString_strLen(a5.m_data[i]);
                stringLengths.AddBack(len);
                totalSize += len;
            }
            else
            {
                stringLengths.AddBack(0);
            }
        }

        this->config->hkOArchive_write32u(totalSize);
        this->config->hkOArchive_write8u(0x12);
        this->config->hkOArchive_write32u(size2);

        for (int i = 0; i < a2.m_iElementCount; ++i)
        {
            this->config->hkOArchive_write32u(a1.m_data[i]);
            this->config->hkOArchive_write32u(a2.m_data[i]);
        }

        this->config->hkOArchive_write32u(iVec4Count);

        for (int i = 0; i < a4.m_iElementCount; ++i)
        {
            this->config->hkOArchive_write32u(a3.m_data[i]);
            this->config->hkDisplaySerializeOStream_writeQuadVector4((unsigned int)&a4.m_data[i]);
        }

        this->config->hkOArchive_write32u((unsigned short)a5.m_iElementCount);

        for (int i = 0; i < a5.m_iElementCount; ++i)
        {
            if (a5.m_data[i] != 0)
            {
                unsigned int len = stringLengths.m_data[i];
                this->config->WriteUInt16(len);
                this->config->hkOArchive_writeRaw(a5.m_data[i], len);
            }
        }

        this->config->hkOArchive_write32u(a8.m_iElementCount);

        for (int i = 0; i < a8.m_iElementCount; ++i)
        {
            Transform_dda340 t;
            a8.m_data[i].Object_ForwardCall_00ce5300(&t);
            this->config->WriteTransform(&t);
        }

        this->config->hkOArchive_write32u(a6.m_iElementCount);

        for (int i = 0; i < a6.m_iElementCount; ++i)
        {
            this->config->hkOArchive_write32u(a6.m_data[i]);
        }

        this->config->hkOArchive_write32u(a7.m_iElementCount);

        for (int i = 0; i < a7.m_iElementCount; ++i)
        {
            this->config->hkOArchive_write32u(a7.m_data[i]);
        }

        stringLengths.ClearAndRelease();
    }

    char status;
    bool failed = (this->config != 0 && *this->config->ForwardValueToObject((unsigned int*)&status) != 0);

    _fnv_LeaveCriticalSection(this->criticalSection);
    return !failed;
}

// FUN_00dda650 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00dda650
{
    A1_00dda650();
    virtual void FUN_00dda650();
    char pad[0x04];
};
struct A2_00dda650
{
    A2_00dda650();
    virtual void FUN_00dda650();
};
struct Own_00dda650 : A1_00dda650, A2_00dda650
{
    Own_00dda650();
    virtual void key_fn();
// @fnv 0x00dda650
    void FUN_00dda650();
};
Own_00dda650::Own_00dda650()
{}
void Own_00dda650::key_fn()
{}
Own_00dda650* make_00dda650()
{
    static Own_00dda650 o;
    return &o;
}

namespace fnv_00dda660 {
struct FUN_00dda660_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct FUN_00dda660_MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00dda660_Allocator* m_pStreamAllocator;

    FUN_00dda660_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" FUN_00dda660_MemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct FUN_00dda660
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00dda660();
    virtual ~FUN_00dda660();

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00dda660* b = static_cast<FUN_00dda660*>(p);
        hkMemoryRouter_getInstance().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// The constructor has an empty body.
// @fnv 0x00dda660
FUN_00dda660::FUN_00dda660()
{}
}  // namespace fnv_00dda660

unsigned int _getGeometryByteSize();

struct FUN_00dd9da0_owner
{
    void ApplyItemList(unsigned int value);
};

struct ConfigQ : FUN_00d605d0_Class
{
    void WriteInt(unsigned int value);
    void WriteTransform(unsigned int value);
    const char* ForwardValueToObject(unsigned int* value);
};

struct SecondaryDisplay
{
    int unk00;
    ConfigQ* config;
    void* criticalSection;

    bool hkServerDebugDisplayHandler_displayGeometry(unsigned int a, unsigned int b, unsigned int c, int d, unsigned int e);
};

// Locks criticalSection, writes values through config when present, and returns true if config is absent or the returned first character is zero.
// @fnv 0x00dd9e90
// src: HAVOK_LIB 0x00dd9e90
bool SecondaryDisplay::hkServerDebugDisplayHandler_displayGeometry(unsigned int a, unsigned int b, unsigned int c, int d, unsigned int e)
{
    _fnv_EnterCriticalSection(criticalSection);
    if (config)
    {
        unsigned int a2 = a;
        config->WriteInt(_getGeometryByteSize() + 0x2d);
        config->hkOArchive_write8u(5);
        reinterpret_cast<FUN_00dd9da0_owner*>((char*)this - 8)->ApplyItemList(a2);
        config->WriteTransform(b);
        config->hkOArchive_write32u(c);
        config->hkOArchive_WriteBinaryData_Thunk_00d609e0((__int64)d);
        config->WriteInt(e);
    }
    bool ok = config != 0 && config->ForwardValueToObject(&a)[0] != 0;
    _fnv_LeaveCriticalSection(criticalSection);
    return !ok;
}
