// src/unmapped/cuassembler_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/unmapped/cuassembler.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned int __cdecl strlen(const char* pStr);

extern "C" int __cdecl memcpy_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
namespace std {
struct _Secure_char_traits_tag;
template <class _Elem> struct char_traits;
template <> struct char_traits<char>
{
    typedef char _Elem;
    typedef _Secure_char_traits_tag _Secure_char_traits;
    static void assign(_Elem& _Left, const _Elem& _Right)
    {
        _Left = _Right;
    }
    static unsigned int length(const _Elem* _First)
    {
        return strlen(_First);
    }
    static _Elem* _Copy_s(_Elem* _First1, unsigned int _Size_in_bytes, const _Elem* _First2, unsigned int _Count)
    {
        memcpy_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
};
struct _Secure_char_traits_tag
{
};
template <class _Traits> inline typename _Traits::_Secure_char_traits _Char_traits_cat()
{
    return (typename _Traits::_Secure_char_traits());
}
struct _Traits_helper
{
    template <class _Traits>
    static typename _Traits::_Elem* copy_s(typename _Traits::_Elem* _First1, unsigned int _Size,
                                           const typename _Traits::_Elem* _First2, unsigned int _Count)
    {
        return copy_s<_Traits>(_First1, _Size, _First2, _Count, _Char_traits_cat<_Traits>());
    }
    template <class _Traits>
    static typename _Traits::_Elem* copy_s(typename _Traits::_Elem* _First1, unsigned int _Size,
                                           const typename _Traits::_Elem* _First2, unsigned int _Count,
                                           _Secure_char_traits_tag)
    {
        return _Traits::_Copy_s(_First1, _Size, _First2, _Count);
    }
};
template <class _Ty> class allocator
{
  public:
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(_Ty);
        return (0 < _Count ? _Count : 1);
    }
};
template <class _Elem, class _Traits = char_traits<_Elem>, class _Ax = allocator<_Elem> > class basic_string
{
  public:
    typedef basic_string<_Elem, _Traits, _Ax> _Myt;
    typedef unsigned int size_type;
    enum
    {
        _BUF_SIZE = 16
    };
    static const size_type npos = (size_type)(-1);

    _Myt& operator=(const _Elem* _Ptr)
    {
        return (assign(_Ptr));
    }
    _Myt& operator+=(const _Elem* _Ptr)
    {
        return (append(_Ptr));
    }

    _Myt& append(const _Myt& _Right, size_type _Roff, size_type _Count);
    _Myt& append(const _Elem* _Ptr, size_type _Count)
    {
        if (_Inside(_Ptr))
            return (append(*this, _Ptr - _Myptr(), _Count));
        if (npos - _Mysize <= _Count)
            _Xlen();
        if (_Count == 0)
            return (*this);

        size_type _Num;
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            _Traits_helper::copy_s<_Traits>(_Myptr() + _Mysize, _Myres - _Mysize, _Ptr, _Count);
            _Eos(_Num);
        }
        return (*this);
    }
    _Myt& append(const _Elem* _Ptr)
    {
        return (append(_Ptr, _Traits::length(_Ptr)));
    }

    _Myt& assign(const _Myt& _Right, size_type _Roff, size_type _Count);
    _Myt& assign(const _Elem* _Ptr, size_type _Count)
    {
        if (_Inside(_Ptr))
            return (assign(*this, _Ptr - _Myptr(), _Count));

        if (_Grow(_Count))
        {
            _Traits_helper::copy_s<_Traits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return (*this);
    }
    _Myt& assign(const _Elem* _Ptr)
    {
        return (assign(_Ptr, _Traits::length(_Ptr)));
    }

    size_type max_size() const
    {
        size_type _Num = _Alval.max_size();
        return (_Num <= 1 ? 1 : _Num - 1);
    }

    void _Copy(size_type _Newsize, size_type _Oldlen);
    void _Eos(size_type _Newsize)
    {
        _Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
    }
    bool _Grow(size_type _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
            _Xlen();
        if (_Myres < _Newsize)
            _Copy(_Newsize, _Mysize);
        else if (_Trim && _Newsize < _BUF_SIZE)
            _Tidy(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        else if (_Newsize == 0)
            _Eos(0);
        return (0 < _Newsize);
    }
    bool _Inside(const _Elem* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
            return (false);
        else
            return (true);
    }
    void _Tidy(bool _Built = false, size_type _Newsize = 0);
    static void _Xlen();
    _Elem* _Myptr()
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }

    _Ax _Alval;
    union _Bxty
    {
        _Elem _Buf[_BUF_SIZE];
        _Elem* _Ptr;
    } _Bx;
    size_type _Mysize;
    size_type _Myres;
};
typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

static const char s_acNoErrors[] = "No errors";
static const char s_acFileCorrupt[] = "File corrupt";
static const char s_acFileOfIncorrectType[] = "File of incorrect type";
static const char s_acFileNotFound[] = "File not found";
static const char s_acFileNotReadable[] = "File not readable";
static const char s_acFileNotWriteable[] = "File not writeable";
static const char s_acFileWriteError[] = "File write error";
static const char s_acFileSeekError[] = "File seek error";
static const char s_acOpenglInitializationError[] = "OpenGL initialization error";
static const char s_acCannotLoadIncompatibleModel[] = "Cannot load incompatible model";
static const char s_acOutOfMemory[] = "Out of memory";
static const char s_acError[] = "Error";
static const char s_acDimensionOfTheImageIsNotPowerOf2[] = "Dimension of the image is not power of 2";
static const char s_acUndocumentedError[] = "Undocumented error";
static const char s_acSeparator[] = " : ";

extern int DAT_011f6c88;
extern char DAT_011f6c8c[];

// @fnv 0x00ac6540
// src: GUESS 0x00ac6540 (confidence: low)
bool __cdecl Object_ProcessAndReturnValue_00ac6540(std::string& kString)
{
    switch (DAT_011f6c88)
    {
    case 0:
        kString = s_acNoErrors;
        break;
    case 1:
        kString = s_acFileCorrupt;
        break;
    case 2:
        kString = s_acFileOfIncorrectType;
        break;
    case 3:
        kString = s_acFileNotFound;
        break;
    case 4:
        kString = s_acFileNotReadable;
        break;
    case 5:
        kString = s_acFileNotWriteable;
        break;
    case 6:
        kString = s_acFileWriteError;
        break;
    case 7:
        kString = s_acFileSeekError;
        break;
    case 8:
        kString = s_acOpenglInitializationError;
        break;
    case 9:
        kString = s_acCannotLoadIncompatibleModel;
        break;
    case 10:
        kString = s_acOutOfMemory;
        break;
    case 11:
        kString = s_acError;
        break;
    case 12:
        kString = s_acDimensionOfTheImageIsNotPowerOf2;
        break;
    default:
        kString = s_acUndocumentedError;
        break;
    }
    if (DAT_011f6c88 == 0)
        return true;
    else
    {
        if (strlen(DAT_011f6c8c) > 0)
        {
            kString += s_acSeparator;
            kString += DAT_011f6c8c;
        }
    }
    return false;
}
