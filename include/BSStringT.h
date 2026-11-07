#pragma once
#include <stdarg.h>

// Bethesda BSStringT<T> (bscore/bsstring.h): T* pString; unsigned short sLen; unsigned short sMaxLen; sizeof 8.
// Only BSStringT<char> exists in FNV. Its member functions are /Od template instantiations at fixed addresses
// (listed below). Stand-ins for BSStringT<char>: BSStringT_char, BSStringTChar, BSStr, BSS, BSString (all
// { char* data; unsigned short length; unsigned short capacity; }).
// The member functions are declared here; a unit defines the bodies it needs out of class (as bscore/bsstring.cpp
// does with the original bodies and explicit instantiations), since /Od and /O2 units need different forms.
// sLen == 0xFFFF means "longer than 65534": Length() then measures pString.
#define FNV64_BSSTRINGT_DEFINED   // include/TESFullName.h skips its partial copy

unsigned int BSStringLength(const char* text);                                    // 0x0044a670 (strlen)
unsigned int BSStringCapacityMaximum(unsigned int length, unsigned int minimum);  // 0x00403940 (max)

template <class T> class BSStringT
{
  public:
    T* pString;              // +0
    unsigned short sLen;     // +4
    unsigned short sMaxLen;  // +6

    BSStringT();                                       // 0x004037b0 { Init(); }
    BSStringT(const T* text);                          // 0x0040c0e0 { Init(); Set(text, 0); }
    BSStringT(const BSStringT<T>& text);               // 0x004047f0 { Init(); Set(text.String(), 0); }
    ~BSStringT();                                      // 0x004037d0 { Set(0, 0); }

    bool Set(const T* text, unsigned int length = 0);  // 0x004037f0
    bool Set(const BSStringT<T>& text);                // 0x00438470
    void Init();                                       // 0x00403970 { pString = 0; SetLength(0); SetMaxLength(0); }
    const T* String() const;                           // 0x00559450 { return pString; }
    operator const T*() const;                         // 0x00559450 (folded with String)
    unsigned int Length() const;                       // 0x004048e0 { sLen == 0xFFFF ? BSStringLength(pString) : sLen }
    unsigned int MaxLength();                          // 0x004039a0 { return sMaxLen; }
    void SetLength(unsigned int length);               // 0x004039c0 sLen = min(length, 0xFFFF)
    void SetMaxLength(unsigned int length);            // 0x00403a00 sMaxLen = min(length, 0xFFFF)
    int __cdecl PrintfString(const char* format, ...); // 0x00406f60 -> FUN_00406f90
    int VSPrintF(const char* format, va_list args);// 0x00406f90 vsprintf into char[1024], Set(buf, 0)
    int FUN_00501c90(BSStringT<T>* text, bool ignoreCase); // exe 0x00501c90
    int Equals(const char* text);                     // 0x007002a0 { return !StrCmp(text, true); }
    BSStringT<T>* FUN_007a86b0(unsigned int flags);    // 0x007a86b0 deleting destructor wrapper
    int StrCmp(const char* text, bool ignoreCase) const; // 0x00408a80 (_stricmp 0x00404dc0 / 0x00408b20)
    void BSStringT_ToLower();                               // 0x004afad0 { if (pString) FUN_004afb00(pString, sLen + 1); }

    BSStringT<T>& operator=(const T* text);            // 0x00438390 { Set(text, 0); return *this; }
    BSStringT<T>& operator=(const BSStringT<T>& text); // 0x00501c10 { Set(text); return *this; }
    BSStringT<T>& operator+=(const T* text);           // 0x00404820
};

