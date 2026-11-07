
// src/gamebryo2.2/corelibs/nimain/nistring.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nistring.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct StringPointerRecord
{
    char* m_kHandle;
};
extern "C" float __cdecl _atof(const char*);
extern int __cdecl _FUN_00ecbf20(const char*, const char*);

struct FUN_00a88c00_shell : StringPointerRecord
{
    bool NiString_ToFloat(float* out);
};

// @fnv 0x00a88c00
// src: COMMUNITY 0x00a88c00
bool FUN_00a88c00_shell::NiString_ToFloat(float* out)
{
    if (!m_kHandle)
        return false;

    *out = _atof(m_kHandle);

    if (*out == 0.0f)
    {
        if (m_kHandle)
        {
            int pos = _FUN_00ecbf20(m_kHandle, "-0");
            if (pos != 0 && pos - (int)m_kHandle >= 0 && pos - (int)m_kHandle != -1)
                return true;
        }
        return false;
    }
    return true;
}

char* __cdecl AllocStringHandle(const char*);
extern "C" unsigned int __cdecl strlen(const char*);
struct MyStr
{
    char* m_kHandle;
    MyStr& AssignString(const char*);
};
// Stores the string returned by AllocStringHandle into m_kHandle and, if non-null, writes its strlen into the int preceding the buffer.
// @fnv 0x00a88b80
MyStr& MyStr::AssignString(const char* acString)
{
    char* v = AllocStringHandle(acString);
    m_kHandle = v;
    if (v)
        *(int*)(v - 4) = (int)strlen(v);
    return *this;
}

void __cdecl _NiFreeAlias(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
struct S00a88bc0
{
    char* m_kHandle;
    void ReleaseHandle();
};
// Decrements the reference count stored before m_kHandle and frees the aliased block when it reaches zero, then clears m_kHandle.
// @fnv 0x00a88bc0
void S00a88bc0::ReleaseHandle()
{
    if (m_kHandle)
    {
        long* ref = (long*)(m_kHandle - 8);
        InterlockedDecrement(ref);
        if (*ref == 0)
        {
            char* tmp = m_kHandle;
            if (tmp)
            {
                _NiFreeAlias(tmp - 12);
                m_kHandle = 0;
            }
        }
        m_kHandle = 0;
    }
}

unsigned int __cdecl NiString_GetBestBufferSize(unsigned int);
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl _memmove(void*, const void*, unsigned int);

// Allocates a handle for a copy of pcStr, stores the length before the string and returns a pointer to the copied string, or 0 on failure.
// @fnv 0x00a88b10
char* __cdecl AllocStringHandle(const char* pcSource)
{
    if (!pcSource)
        return 0;

    unsigned int uiLen = (unsigned int)strlen(pcSource);
    unsigned int uiSize = uiLen;
    if (!uiSize)
        uiSize = 1;
    unsigned int uiAlloc = uiSize + 0xd;
    unsigned int uiRet = NiString_GetBestBufferSize(uiAlloc);
    unsigned int* pkMem = (unsigned int*)_NiMalloc(uiRet);
    *pkMem = uiRet;
    char* pcHandle = (char*)(pkMem + 3);
    pkMem[1] = 1;
    pkMem[2] = 0;

    if (!pcHandle)
        return 0;

    _memmove(pcHandle, pcSource, uiLen + 1);
    *(unsigned int*)(pcHandle - 4) = uiLen;
    return pcHandle;
}
