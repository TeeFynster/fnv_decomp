
// src/havok/common/base/memory/util/hkmemutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/util/hkmemutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl hkMemUtil_memCpy_00d2caa0(void*, void*, unsigned int);
void __cdecl CopyMemoryBackward(void*, void*, unsigned int);

// @fnv 0x00d2cc70
// src: HAVOK_LIB 0x00d2cc70
void __cdecl hkMemUtil_memMove(void* dst, void* src, unsigned int size)
{
    if (dst > src)
    {
        CopyMemoryBackward(dst, src, size);
    }
    else if (dst < src)
    {
        hkMemUtil_memCpy_00d2caa0(dst, src, size);
    }
}

// Overlap-safe backward block copy: 8-, 4-, 2- and 1-byte stages.
// Copies size bytes from src to dst in descending order, using 8-, 4-, 2- and 1-byte chunks when both pointers and the size are aligned.
// @fnv 0x00d2cb70
void __cdecl CopyMemoryBackward(void* apDest, void* apSource, unsigned int size)
{
    unsigned int n = size;
    unsigned int uiBulk8 = n & ~7u;

    if (uiBulk8 != 0 && (n & 7) == 0 && ((unsigned int)apDest & 7) == 0 && ((unsigned int)apSource & 7) == 0)
    {
        unsigned int uiCount8 = n >> 3;
        if (n >= 8)
        {
            unsigned char* pCursor8 = (unsigned char*)apDest + uiCount8 * 8 - 8;
            unsigned int uiSrcDelta = (unsigned int)apSource - (unsigned int)apDest;
            do
            {
                *(unsigned int*)pCursor8 = *(unsigned int*)(pCursor8 + uiSrcDelta);
                *(unsigned int*)(pCursor8 + 4) = *(unsigned int*)(pCursor8 + uiSrcDelta + 4);
                pCursor8 -= 8;
            } while (--uiCount8 != 0);
        }
        apDest = (unsigned char*)apDest + uiBulk8;
        apSource = (unsigned char*)apSource + uiBulk8;
        n = 0;
    }

    {
        unsigned int bulk4 = n & ~3u;
        if (bulk4 != 0 && (n & 3) == 0 && ((unsigned int)apDest & 3) == 0 && ((unsigned int)apSource & 3) == 0)
        {
            unsigned int uiCount4 = n >> 2;
            if (n >= 4)
            {
                unsigned int uiSrcDelta = (unsigned int)apSource;
                unsigned char* pCursor8 = (unsigned char*)apDest + uiCount4 * 4 - 4;
                uiSrcDelta -= (unsigned int)apDest;
                unsigned int i = uiCount4;
                do
                {
                    *(unsigned int*)pCursor8 = *(unsigned int*)(pCursor8 + uiSrcDelta);
                    pCursor8 -= 4;
                } while (--i != 0);
            }
            apDest = (unsigned char*)apDest + bulk4;
            apSource = (unsigned char*)apSource + bulk4;
            n = 0;
        }
    }

    {
        unsigned int bulk2 = n & ~1u;
        if (bulk2 != 0 && (n & 1) == 0 && ((unsigned int)apDest & 1) == 0 && ((unsigned int)apSource & 1) == 0)
        {
            unsigned int uiCount2 = n >> 1;
            if (n >= 2)
            {
                unsigned int uiSrcDelta = (unsigned int)apSource;
                unsigned char* pCursor8 = (unsigned char*)apDest + uiCount2 * 2 - 2;
                uiSrcDelta -= (unsigned int)apDest;
                unsigned int i = uiCount2;
                do
                {
                    *(unsigned short*)pCursor8 = *(unsigned short*)(pCursor8 + uiSrcDelta);
                    pCursor8 -= 2;
                } while (--i != 0);
            }
            apDest = (unsigned char*)apDest + bulk2;
            apSource = (unsigned char*)apSource + bulk2;
            n = 0;
        }
    }

    for (unsigned int i = n; i >= 1; --i)
    {
        unsigned char* pCursor1 = (unsigned char*)apDest + i - 1;
        *pCursor1 = *(pCursor1 + ((unsigned int)apSource - (unsigned int)apDest));
        --pCursor1;
    }
}

namespace fnv_00d2caa0 {
void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

// @fnv 0x00d2caa0
// src: XBOX_PDB 0x00d2caa0
void __cdecl hkMemUtil_memCpy_00d2caa0(void* dst, void* src, unsigned int size)
{
    _memmove(dst, src, size);
}
}  // namespace fnv_00d2caa0

void __cdecl FUN_00ec61c0();
// @fnv 0x00d2cab0
// src: XBOX_PDB 0x00d2cab0
void __cdecl hkMemUtil_memSet()
{
    FUN_00ec61c0();
}

struct D2CAC0Elem
{
    unsigned int lo;
    unsigned int hi;
};

// static: VC9 /O2 gives it a register convention (src in ecx, dst in edx, nbytes in eax)
// Copies nbytes/sizeof(D2CAC0Elem) elements from src to dst in reverse order, decrementing nbytes by one element per iteration.
// @fnv 0x00d2cac0
static void __declspec(noinline)
    CopyElementsBackward(D2CAC0Elem* apDest, const D2CAC0Elem* apSource, unsigned int auiByteCount)
{
    unsigned int n = auiByteCount / sizeof(D2CAC0Elem);
    while (auiByteCount >= sizeof(D2CAC0Elem))
    {
        auiByteCount -= sizeof(D2CAC0Elem);
        apDest[n - 1] = apSource[n - 1];
        n--;
    }
}

void D2CAC0Caller(void* dst, const void* src, unsigned int nbytes)
{
    CopyElementsBackward((D2CAC0Elem*)dst, (const D2CAC0Elem*)src, nbytes);
}

// Copies complete 4-byte chunks from src to dst in reverse order when size is at least 4.
// @fnv 0x00d2caf0
// src: HAVOK_LIB 0x00d2caf0
static __declspec(noinline) void memCopyBackwards_4(void* dst, void* src, unsigned int size)
{
    unsigned int n = size >> 2;

    if (size >= 4)
    {
        unsigned int* d = (unsigned int*)dst + n - 1;
        unsigned int off = (unsigned int)src - (unsigned int)dst;

        do
        {
            unsigned int uiValue = *(unsigned int*)(off + (char*)d);
            *d = uiValue;
            d -= 1;
        } while (--n != 0);
    }
}

void q_call_d2caf0(void* dst, void* src, unsigned int size)
{
    memCopyBackwards_4(dst, src, size);
}

// @fnv 0x00d2cb20
// src: HAVOK_LIB 0x00d2cb20
static __declspec(noinline) void memCopyBackwards_2(void* dst, void* src, unsigned int count)
{
    unsigned int words = count >> 1;
    if (count >= 2)
    {
        unsigned short* d = (unsigned short*)dst + (words - 1);
        unsigned int off = (unsigned int)src - (unsigned int)dst;
        do
        {
            *d = *(unsigned short*)(off + (char*)d);
            d = d - 1;
            words = words - 1;
        } while (words != 0);
    }
}

void q_call_d2cb20(void* a, void* b, unsigned int c)
{
    memCopyBackwards_2(a, b, c);
}

// @fnv 0x00d2cb50
// src: HAVOK_LIB 0x00d2cb50
static __declspec(noinline) void memCopyBackwards_1(unsigned int count, unsigned char* dst, const unsigned char* src)
{
    for (unsigned int i = count; i >= 1; --i)
    {
        dst[i - 1] = src[i - 1];
    }
}

void copy_backward(unsigned char* dst, const unsigned char* src, unsigned int count)
{
    memCopyBackwards_1(count, dst, src);
}
