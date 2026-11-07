#include "../../include/CTreeEngine.h"
#include "../../include/IdvFileError.h"
#include "../../include/NiPoint3.h"
#include <errno.h>
#include <string.h>
#include <vector>

// src/speedtree/treeengine_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/treeengine.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/treeengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/treeengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl operator delete(void*);
struct FUN_00b2ae60_shell
{
    void __thiscall FUN_00b2ae90();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
struct RandomNumberGenerator
{
    void SeedRandomGenerator(long);
    float GenerateRandomFloat(float, float);
};
extern float DAT_0108cb00;
extern float _DAT_010162c0;

struct ElementIterator
{
    int __thiscall GetNextElement();
};


extern unsigned int DAT_010173f0;
struct FUN_00b04d40_Obj
{
    float CVec3_Distance(int a);
};
extern FUN_00b04d40_Obj DAT_011f8e9c;
extern double DAT_01012060;
extern double DAT_01012070;

struct FUN_00b3d720_String
{
    void __thiscall fopen_0044a730(bool a, unsigned int b);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_00b3d720_Class
{
    bool unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    FUN_00b3d720_String unk14;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;

    FUN_00b3d720_Class* __thiscall SIdvLeafTexture_SIdvLeafTexture();
};
extern float DAT_01030ff0;
extern float DAT_0101df44;
extern float DAT_01016248;
extern float DAT_010a587c;
extern float DAT_01017b78;

void __stdcall FUN_00ec5fce(void* self, unsigned int elemSize, unsigned int count, void* dtor);
void FUN_00b33370();

struct S00b2b490_Guard
{
    S00b2b490_Guard()
    {}
    ~S00b2b490_Guard()
    {}
};

struct S00b2b490_Elem
{
    void* m0;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void UpdateState_00b17f50();
    void* FUN_00b2b490(unsigned int flags);
};

// @fnv 0x00b2b490
void* S00b2b490_Elem::FUN_00b2b490(unsigned int flags)
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x18, *((unsigned int*)this - 1), FUN_00b33370);
        if (flags & 1)
        {
            operator delete((char*)this - 4);
        }
        return (char*)this - 4;
    }
    {
        S00b2b490_Guard g;
        UpdateState_00b17f50();
    }
    {
        void* p = m0;
        operator delete(p);
    }
    if (flags & 1)
    {
        operator delete(this);
    }
    return this;
}

extern const char* DAT_011ad36c;
extern unsigned int DAT_010173f0;
void FUN_00ec7c56();
void std_Traits_helper_copy_s_std_char_traits_char(char*, unsigned int, const char*, unsigned int);
unsigned int __cdecl strlen(const char*);

struct SptAllocator
{
    SptAllocator()
    {}
};
struct SptStringBase
{
    SptAllocator allocator;
    SptStringBase(SptAllocator);
};

struct SptString : SptStringBase
{
    union Buffer
    {
        char buffer[16];
        char* data;
    } storage;
    unsigned int length;
    unsigned int capacity;
    SptString(const char* text) : SptStringBase(SptAllocator())
    {
        fopen_0044a730(false, 0);
        assign(text);
    }
    SptString() : SptStringBase(SptAllocator())
    {
        fopen_0044a730(false, 0);
    }
    SptString(const SptString& rhs) : SptStringBase(SptAllocator())
    {
        fopen_0044a730(false, 0);
        assign(rhs, 0, DAT_010173f0);
    }
    void range_error();
    bool grow(unsigned int, bool = false);
    SptString& erase(unsigned int, unsigned int = -1);
    SptString& assign(const SptString& rhs, unsigned int off, unsigned int count)
    {
        if (rhs.size() < off)
            range_error();
        unsigned int num = rhs.size() - off;
        if (count < num)
            num = count;
        if (this == &rhs)
        {
            erase(off + num);
            erase(0, off);
        }
        else if (grow(num))
        {
            std_Traits_helper_copy_s_std_char_traits_char(pointer(), capacity, rhs.pointer() + off, num);
            eos(num);
        }
        return *this;
    }
    SptString& assign(const char*, unsigned int);
    SptString& assign(const char* p)
    {
        return assign(p, strlen(p));
    }
    SptString& append(const char*);
    SptString& append(const SptString&);
    SptString& AppendChars(unsigned int, char);
    ~SptString()
    {
        fopen_0044a730(true, 0);
    }
    SptString& FUN_0044a4c0(const char*);
    void deallocate(char*, unsigned int);
    char* pointer()
    {
        return capacity >= 16 ? storage.data : storage.buffer;
    }
    void eos(unsigned int n)
    {
        pointer()[length = n] = char();
    }
// src: XBOX_PDB 0x0044a730
    void fopen_0044a730(bool built, unsigned int n)
    {
        if (!built)
        {
        }
        else if (capacity >= 16)
        {

            if (n > 0)
                std_Traits_helper_copy_s_std_char_traits_char(storage.buffer, 16, storage.data, n);
            deallocate(storage.data, capacity + 1);
        }
        capacity = 15;
        eos(n);
    }
    const char* pointer() const
    {
        return capacity >= 16 ? storage.data : storage.buffer;
    }
    unsigned int size() const
    {
        return length;
    }
    int compare(unsigned int, unsigned int, const char*, unsigned int) const;
// src: GUESS 0x00ac9da0 (confidence: low)
    int UpdateFields_00ac9da0(const SptString& rhs) const
    {
        unsigned int n = rhs.size();
        const char* p = rhs.pointer();
        unsigned int m = size();
        return compare(0, m, p, n);
    }
};

__forceinline bool operator==(const SptString& left, const SptString& right)
{
    int unused;
    return left.UpdateFields_00ac9da0(right) == 0;
}
__forceinline bool operator!=(const SptString& left, const SptString& right)
{
    return !(left == right);
}

inline SptString operator+(const SptString& left, const char* right)
{
    return SptString(left).append(right);
}
inline SptString operator+(const SptString& left, const SptString& right)
{
    return SptString(left).append(right);
}
int* FUN_00ec85e3();
char* FUN_00ecdb42(int);

struct SptException
{
    int unk04;
    int unk08;
    SptException();
    virtual ~SptException();
    virtual const char* what() const;
};

struct SptRuntimeError : SptException
{
    SptString message;
    SptRuntimeError(const SptString& text) : message(text)
    {}
    ~SptRuntimeError();
};

struct SptError : SptRuntimeError
{
    SptError(const SptString& text, bool append)
        : SptRuntimeError(text + " [" + (append ? SptString(FUN_00ecdb42(*FUN_00ec85e3())) : SptString("")) + "]")
    {}
    SptError(const SptError&);
    ~SptError();
};

inline CTreeEngine::SptFilename::~SptFilename()
{
    fopen_0044a730(true, 0);
}
__forceinline void CTreeEngine::SptFilename::operator=(const SptFilename& rhs)
{
    EvaluateValue_00b2b910(SptFilename(rhs));
}

struct CTreeFileAccessBuffer
{
    int unk00;
    int unk04;
    int unk08;
    char* m_kRayStart;
    char* m_kRayEnd;
    unsigned int size() const
    {
        return m_kRayEnd - m_kRayStart;
    }
    char& operator[](unsigned int n)
    {
        if (n >= size())
            FUN_00ec7c56();
        return m_kRayStart[n];
    }
};

struct CTreeFileAccessImpl : ElementIterator
{
    unsigned int m_pos;
    CTreeFileAccessBuffer m_buffer;
    int GetNextElement()
    {
        int* token = (int*)&m_buffer[m_pos];
        m_pos += 4;
        return *token;
    }
    bool EndOfFile()
    {
        return m_pos >= m_buffer.size();
    }
    int GetElementAtOffset();
// src: COMMUNITY 0x00b3ee40
    SptString CTreeFileAccess_ParseString()
    {
        SptString value;
        int length = GetNextElement();
        for (int i = 0; i < length; ++i)
            value.AppendChars(1, m_buffer[m_pos++]);
        return SptString(value);
    }
};

// @fnv 0x00b2b550
// src: XBOX_PDB 0x00b2b550
bool CTreeEngine::Parse_00b2b550(CTreeFileAccessImpl* file)
{
    bool bSuccess = false;

    int strBuf9 = file->GetNextElement();
    if (strBuf9 != 0x3e8)
    {
        throw SptError("missing begin_file token", false);
    }

    SptString str3 = ((CTreeFileAccessImpl*)file)->CTreeFileAccess_ParseString();
    if (str3 != SptString(DAT_011ad36c))
    {
        throw SptError("not a valid SpeedTree SPT file", false);
    }

    strBuf9 = file->GetNextElement();
    do
    {
        switch (strBuf9)
        {
        case 0x3ea:
            ParseTreeInfo(file);
            break;
        case 0x3ec:
            m_sub94.SIdvLeafInfo_Parse(file);
            break;
        case 0x3f3:
            m_sub10c.SIdvWindInfo_Parse(file);
            break;
        default:
            throw SptError("malformed SpeedTree SPT file", false);
        }
        strBuf9 = file->GetNextElement();
    } while (strBuf9 != 0x3e9);

    if (!((CTreeFileAccessImpl*)file)->EndOfFile() && ((CTreeFileAccessImpl*)file)->GetElementAtOffset() == 0x1b58)
    {
        static_cast<ElementIterator*>(file)->GetNextElement();
        ParseLeafCluster(file);
    }

    m_pcFileName = m_pcFileName;

    m_suba4.CTreeEngine_SetLeafTextures(&m_suba4);

    if (m_actualSize > -1.0f)
    {
        SetSize_00b2bd20(m_actualSize, m_actualVariance);
    }

    bSuccess = true;
    return bSuccess;
}


// @fnv 0x00b2b910
// src: GUESS 0x00b2b910 (confidence: low)
CTreeEngine::SptFilename& CTreeEngine::SptFilename::EvaluateValue_00b2b910(const SptFilename& rhs)
{
    typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > FilenameString;
    reinterpret_cast<FilenameString*>(this)->assign(reinterpret_cast<const FilenameString&>(rhs), 0, DAT_010173f0);
    return *this;
}

namespace shutb2b9 {
void FUN_00ec7c56();
template <class T> inline void GvDestroyOne(T* _Ptr)
{
    _Ptr->~T();
}
extern "C" unsigned int __cdecl strlen(const char* _Str);
int FUN_00ec7c66(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
int FUN_00ec7c6b(void* _Dst, unsigned int _Size, const void* _Src, unsigned int _Count);
struct BxSecureTag
{
};
struct BxStrTraits
{
    static char* _Copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c66(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        FUN_00ec7c6b(_First1, _Size, _First2, _Count);
        return _First1;
    }
    static unsigned int length(const char* _First)
    {
        return strlen(_First);
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};
inline BxSecureTag BxCharTraitsCat()
{
    BxSecureTag _Secure_char_traits;
    return _Secure_char_traits;
}
struct BxTraitsHelper
{
    template <class T>
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Copy_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return copy_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
    template <class T>
    static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count, BxSecureTag)
    {
        return T::_Move_s(_First1, _Size, _First2, _Count);
    }
    template <class T> static char* move_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        return move_s<T>(_First1, _Size, _First2, _Count, BxCharTraitsCat());
    }
};
struct BxException;
struct BxBadAlloc;
template <class T> inline T* BxAllocate(unsigned int count, T*);
template <class T> struct BxAllocT
{
    typedef T* pointer;
    BxAllocT() throw()
    {}
    BxAllocT(const BxAllocT<T>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    pointer allocate(unsigned int _Count, const void*)
    {
        return allocate(_Count);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    unsigned int max_size() const
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
typedef BxAllocT<char> BxCharAlloc;
struct BxStringVal
{
    BxCharAlloc _Alval;
    BxStringVal(BxCharAlloc _Al = BxCharAlloc()) : _Alval(_Al)
    {}
    BxStringVal(const BxStringVal& _Right) : _Alval(_Right._Alval)
    {}
};
struct BxString : public BxStringVal
{
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    BxString(const char* _Ptr) : BxStringVal()
    {
        _Tidy();
        assign(_Ptr);
    }
    BxString(const BxString& _Right) : BxStringVal(_Right)
    {
        _Tidy();
        assign(_Right, 0, (unsigned int)-1);
    }
    ~BxString()
    {
        _Tidy(true);
    }
    static void _Xlen();
    static void _Xran();
    unsigned int size() const
    {
        return _Mysize;
    }
    unsigned int max_size() const
    {
        unsigned int _Num = _Alval.max_size();
        return _Num <= 1 ? 1 : _Num - 1;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        BxStrTraits::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    BxString& erase(unsigned int _Off = 0, unsigned int _Count = (unsigned int)-1)
    {
        if (_Mysize < _Off)
        {
            _Xran();
        }
        if (_Mysize - _Off < _Count)
        {
            _Count = _Mysize - _Off;
        }
        if (0 < _Count)
        {
            BxTraitsHelper::move_s<BxStrTraits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                                _Mysize - _Off - _Count);
            unsigned int _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return *this;
    }
    bool _Inside(const char* _Ptr)
    {
        if (_Ptr == 0 || _Ptr < _Myptr() || _Myptr() + _Mysize <= _Ptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void _Tidy(bool _Built = false, unsigned int _Newsize = 0)
    {
        if (!_Built)
        {
        }
        else if (16 <= _Myres)
        {
            char* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
            {
                BxTraitsHelper::copy_s<BxStrTraits>(_Bx._Buf, 16, _Ptr, _Newsize);
            }
            _Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = 16 - 1;
        _Eos(_Newsize);
    }
    void _Copy(unsigned int _Newsize, unsigned int _Oldlen)
    {
        unsigned int _Newres = _Newsize | 15;
        if (max_size() < _Newres)
        {
            _Newres = _Newsize;
        }
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
        {
            _Newres = _Myres + _Myres / 2;
        }
        char* _Ptr = 0;
        try
        {
            _Ptr = _Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        }
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    bool _Grow(unsigned int _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
        {
            _Xlen();
        }
        if (_Myres < _Newsize)
        {
            _Copy(_Newsize, _Mysize);
        }
        else if (_Trim && _Newsize < 16)
        {
            _Tidy(true, _Newsize < _Mysize ? _Newsize : _Mysize);
        }
        else if (_Newsize == 0)
        {
            _Eos(0);
        }
        return 0 < _Newsize;
    }
    BxString& assign(const BxString& _Right, unsigned int _Roff, unsigned int _Count)
    {
        if (_Right.size() < _Roff)
        {
            _Xran();
        }
        unsigned int _Num = _Right.size() - _Roff;
        if (_Count < _Num)
        {
            _Num = _Count;
        }
        if (this == &_Right)
        {
            erase((unsigned int)(_Roff + _Num)), erase(0, _Roff);
        }
        else if (_Grow(_Num))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr, unsigned int _Count)
    {
        if (_Inside(_Ptr))
        {
            return assign(*this, _Ptr - _Myptr(), _Count);
        }
        if (_Grow(_Count))
        {
            BxTraitsHelper::copy_s<BxStrTraits>(_Myptr(), _Myres, _Ptr, _Count);
            _Eos(_Count);
        }
        return *this;
    }
    BxString& assign(const char* _Ptr)
    {
        return assign(_Ptr, BxStrTraits::length(_Ptr));
    }
};
struct BxException
{
    const char* _m_what;
    int _m_doFree;
    BxException();
    BxException(const char* const& _What);
    BxException(const BxException& _That);
    virtual ~BxException();
    virtual const char* what() const;
};
struct BxBadAlloc : public BxException
{
    BxBadAlloc(const char* _Message = "bad allocation") throw() : BxException(_Message)
    {}
    virtual ~BxBadAlloc() throw()
    {}
};
template <class T> inline T* BxAllocate(unsigned int count, T*)
{
    if (count <= 0)
    {
        count = 0;
    }
    else if (((unsigned int)(-1) / count) < sizeof(T))
    {
        throw BxBadAlloc(0);
    }
    return (T*)operator new(count * sizeof(T));
}
struct BxLogicError : public BxException
{
    BxString _Str;
    explicit BxLogicError(const BxString& _Message) : _Str(_Message)
    {}
    virtual ~BxLogicError()
    {}
    virtual const char* what() const
    {
        return _Str._Myptr();
    }
};
struct BxLengthError : public BxLogicError
{
    explicit BxLengthError(const BxString& _Message) : BxLogicError(_Message)
    {}
    virtual ~BxLengthError()
    {}
};

template <class T> struct GvAlloc
{
    typedef T* pointer;
    GvAlloc() throw()
    {}
    GvAlloc(const GvAlloc<T>&) throw()
    {}
    template <class O> GvAlloc(const GvAlloc<O>&) throw()
    {}
    pointer allocate(unsigned int _Count)
    {
        return BxAllocate(_Count, (pointer)0);
    }
    void deallocate(pointer _Ptr, unsigned int)
    {
        operator delete(_Ptr);
    }
    void destroy(pointer _Ptr)
    {
        GvDestroyOne(_Ptr);
    }
    void construct(pointer _Ptr, const T& _Val)
    {
        GvConstruct(_Ptr, _Val);
    }
    unsigned int max_size() const throw()
    {
        unsigned int _Count = (unsigned int)(-1) / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
struct GvNonscalarTag
{
};
struct GvScalarTag
{
};
struct GvRangeCheckedTag
{
};
template <class T1, class T2> struct GvPtrCatHelper
{
    typedef GvNonscalarTag _Ptr_cat;
};
template <> struct GvPtrCatHelper<char*, char*>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T> struct GvPtrCatHelper<T**, T**>
{
    typedef GvScalarTag _Ptr_cat;
};
template <class T1, class T2> inline typename GvPtrCatHelper<T1, T2>::_Ptr_cat GvPtrCat(T1&, T2&)
{
    typename GvPtrCatHelper<T1, T2>::_Ptr_cat _Cat;
    return _Cat;
}
template <class A> inline void GvDestroyRange(typename A::pointer, typename A::pointer, A&, GvScalarTag)
{}
template <class T, class A>
void GvUninitFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al, GvNonscalarTag, GvRangeCheckedTag);
template <class T, class A> inline void GvUncheckedFillN(T* _First, unsigned int _Count, const T& _Val, A& _Al)
{
    GvUninitFillN(_First, _Count, _Val, _Al, GvPtrCat(_First, _First), GvRangeCheckedTag());
}
template <class A>
inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al, GvNonscalarTag)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class A> inline void GvDestroyRange(typename A::pointer _First, typename A::pointer _Last, A& _Al)
{
    GvDestroyRange<A>(_First, _Last, _Al, GvPtrCat(_First, _Last));
}
struct GvInputTag
{
};
struct GvForwardTag : GvInputTag
{
};
struct GvBidiTag : GvForwardTag
{
};
struct GvRandomTag : GvBidiTag
{
};
struct GvUnchangedTag
{
};
template <class I1, class I2> inline GvRandomTag GvIterRandom(const I1&, const I2&)
{
    GvRandomTag _Cat;
    return _Cat;
}
struct GvBaseTag
{
};
template <class T> struct GvConstIterator;
template <class I> struct GvCheckedHelper
{
    typedef GvUnchangedTag _Tag;
    typedef I _Base;
};
template <class T> struct GvCheckedHelper<GvConstIterator<T> >
{
    typedef GvBaseTag _Tag;
    typedef const T* _Base;
};
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I, class B> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, B)
{
    return _It._Checked_iterator_base();
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It, GvUnchangedTag)
{
    return _It;
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(const I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I> inline typename GvCheckedHelper<I>::_Base GvCheckedBase(I& _It)
{
    typename GvCheckedHelper<I>::_Tag _Base_tag;
    return GvCheckedBase(_It, _Base_tag);
}
template <class I, class O, class C>
inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvNonscalarTag, GvRangeCheckedTag)
{
    for (; _First != _Last; ++_Dest, ++_First)
    {
        *_Dest = *_First;
    }
    return _Dest;
}
template <class I, class O>
inline O GvCopyOpt(I _First, I _Last, O _Dest, GvRandomTag, GvNonscalarTag, GvRangeCheckedTag)
{
    O _Result = _Dest + (_Last - _First);
    GvCopyOpt(_First, _Last, GvCheckedBase(_Dest), GvForwardTag(), GvNonscalarTag(), GvRangeCheckedTag());
    return _Result;
}
template <class I, class O, class C> inline O GvCopyOpt(I _First, I _Last, O _Dest, C, GvScalarTag, GvRangeCheckedTag)
{
    int _Off = _Last - _First;
    O _Result = _Dest + _Off;
    if (_Off > 0)
        FUN_00ec7c6b(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class I, class O> inline O GvUncheckedCopy(I _First, I _Last, O _Dest)
{
    return GvCopyOpt(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, GvIterRandom(_First, _Dest),
                     GvPtrCat(_First, _Dest), GvRangeCheckedTag());
}
template <class I, class F, class A>
inline F GvUninitCopy(I _First, I _Last, F _Dest, A& _Al, GvNonscalarTag, GvRangeCheckedTag)
{
    F _Next = _Dest;
    try
    {
        for (; _First != _Last; ++_Dest, ++_First)
        {
            _Al.construct(_Dest, *_First);
        }
    }
    catch (...)
    {
        for (; _Next != _Dest; ++_Next)
        {
            _Al.destroy(_Next);
        }
        throw;
    }
    return _Dest;
}
template <class I, class F, class A> inline F GvUncheckedUninitCopy(I _First, I _Last, F _Dest, A& _Al)
{
    return GvUninitCopy(GvCheckedBase(_First), GvCheckedBase(_Last), _Dest, _Al, GvPtrCat(_First, _Dest),
                        GvRangeCheckedTag());
}
template <class T1, class T2> inline void GvConstruct(T1* _Ptr, const T2& _Val)
{
    void* _Vptr = _Ptr;
    ::new (_Vptr) T1(_Val);
}
struct GvContainer;
struct GvAuxCont
{
    const GvContainer* _Mycontainer;
    GvAuxCont(const GvContainer* _Pcont) : _Mycontainer(_Pcont)
    {}
    const GvContainer* _Getcont() const
    {
        return _Mycontainer;
    }
};
struct GvContainer
{
    GvAuxCont* _Myownedaux;
    GvContainer()
    {}
    GvContainer(const GvContainer&)
    {}
    GvContainer& operator=(const GvContainer&)
    {
        return *this;
    }
    ~GvContainer()
    {}
};
template <class A> struct GvAuxBase : GvContainer
{
    GvAlloc<GvAuxCont> _Alaux;
    explicit GvAuxBase(A _Al) : _Alaux(_Al)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    GvAuxBase(const GvAuxBase& _Right) : _Alaux(_Right._Alaux)
    {
        _Myownedaux = new (_Alaux.allocate(1)) GvAuxCont(this);
    }
    ~GvAuxBase()
    {
        _Myownedaux->~GvAuxCont();
        _Alaux.deallocate(_Myownedaux, 1);
    }
};
struct GvIterBase
{
    GvAuxCont* _Myaux;
    GvIterBase() : _Myaux(0)
    {}
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    bool _Same_container(const GvIterBase& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    void _Set_container(const GvContainer* _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const GvContainer* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
};
template <class T> struct GvVector;
template <class T> struct GvConstIterator : GvIterBase
{
    T* _Myptr;
    const T* _Checked_iterator_base() const
    {
        return _Myptr;
    }
    GvConstIterator(T* _Ptr, const GvContainer* _Pvector)
    {
        {
            if (!(_Pvector != 0 && ((GvVector<T>*)_Pvector)->_Myfirst <= _Ptr &&
                  _Ptr <= ((GvVector<T>*)_Pvector)->_Mylast))
            {
                FUN_00ec7c56();
            }
        }
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    GvConstIterator& operator+=(int _Off)
    {
        {
            if (!this->_Has_container())
            {
                FUN_00ec7c56();
            }
        }
        {
            if (!(_Myptr + _Off <= ((GvVector<T>*)this->_Getmycont())->_Mylast &&
                  _Myptr + _Off >= ((GvVector<T>*)this->_Getmycont())->_Myfirst))
            {
                FUN_00ec7c56();
            }
        }
        _Myptr += _Off;
        return *this;
    }
    bool operator==(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        do
        {
        } while (0);
        return _Myptr == _Right._Myptr;
    }
    bool operator!=(const GvConstIterator& _Right) const
    {
        return !(*this == _Right);
    }
    int operator-(const GvConstIterator& _Right) const
    {
        {
            if (!(this->_Has_container() && this->_Same_container(_Right)))
            {
                FUN_00ec7c56();
            }
        }
        return _Myptr - _Right._Myptr;
    }
};
template <class T> struct GvIterator : GvConstIterator<T>
{
    GvIterator(T* _Ptr, const GvContainer* _Pvector) : GvConstIterator<T>(_Ptr, _Pvector)
    {}
    GvIterator& operator+=(int _Off)
    {
        (*(GvConstIterator<T>*)this) += _Off;
        return *this;
    }
    GvIterator operator+(int _Off) const
    {
        GvIterator _Tmp = *this;
        return (_Tmp += _Off);
    }
};
template <class T> struct GvVectorVal : GvAuxBase<GvAlloc<T> >
{
    GvAlloc<T> _Alval;
    GvVectorVal(GvAlloc<T> _Al = GvAlloc<T>()) : GvAuxBase<GvAlloc<T> >(_Al), _Alval(_Al)
    {}
};
template <class T> struct GvVector : GvVectorVal<T>
{
    T* _Myfirst;
    T* _Mylast;
    T* _Myend;
    GvVector() : GvVectorVal<T>()
    {
        _Buy(0);
    }
    GvVector(const GvVector& _Right) : GvVectorVal<T>(_Right._Alval)
    {
        if (_Buy(_Right.size()))
        {
            try
            {
                _Mylast = _Ucopy(_Right.begin(), _Right.end(), _Myfirst);
            }
            catch (...)
            {
                _Tidy();
                throw;
            }
        }
    }
    ~GvVector()
    {
        _Tidy();
    }
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    unsigned int max_size() const
    {
        return this->_Alval.max_size();
    }
    GvIterator<T> begin()
    {
        return GvIterator<T>(_Myfirst, this);
    }
    GvIterator<T> end()
    {
        return GvIterator<T>(_Mylast, this);
    }
    GvConstIterator<T> begin() const
    {
        return GvConstIterator<T>(_Myfirst, this);
    }
    GvConstIterator<T> end() const
    {
        return GvConstIterator<T>(_Mylast, this);
    }
    static void _Xlen()
    {
        throw BxLengthError("vector<T> too long");
    }
    bool _Buy(unsigned int _Capacity)
    {
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
        if (_Capacity == 0)
        {
            return false;
        }
        else if (max_size() < _Capacity)
        {
            _Xlen();
        }
        else
        {
            _Myfirst = this->_Alval.allocate(_Capacity);
            _Mylast = _Myfirst;
            _Myend = _Myfirst + _Capacity;
        }
        return true;
    }
    void _Destroy(T* _First, T* _Last)
    {
        GvDestroyRange(_First, _Last, this->_Alval);
    }
    void _Tidy()
    {
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myfirst = 0, _Mylast = 0, _Myend = 0;
    }
    T* _Ufill(T* _Ptr, unsigned int _Count, const T& _Val)
    {
        GvUncheckedFillN(_Ptr, _Count, _Val, this->_Alval);
        return _Ptr + _Count;
    }
    GvIterator<T> _Make_iter(GvConstIterator<T> _Where) const
    {
        return GvIterator<T>(_Where._Myptr, this);
    }
    GvIterator<T> erase(GvConstIterator<T> _First_arg, GvConstIterator<T> _Last_arg)
    {
        GvIterator<T> _First = _Make_iter(_First_arg);
        GvIterator<T> _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            T* _Ptr = GvUncheckedCopy(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return _First;
    }
    void clear()
    {
        erase(begin(), end());
    }
    void resize(unsigned int _Newsize, T _Val)
    {
        if (size() < _Newsize)
            _Insert_n(end(), _Newsize - size(), _Val);
        else if (_Newsize < size())
            erase(begin() + _Newsize, end());
    }
    void resize(unsigned int _Newsize)
    {
        resize(_Newsize, T());
    }
    T& operator[](unsigned int _Pos)
    {
        {
            if (!(_Pos < size()))
            {
                FUN_00ec7c56();
            }
        }
        return *(_Myfirst + _Pos);
    }
    template <class I> T* _Ucopy(I _First, I _Last, T* _Ptr)
    {
        return GvUncheckedUninitCopy(_First, _Last, _Ptr, this->_Alval);
    }
    GvVector& operator=(const GvVector& _Right)
    {
        if (this != &_Right)
        {
            if (_Right.size() == 0)
            {
                clear();
            }
            else if (_Right.size() <= size())
            {
                T* _Ptr = GvUncheckedCopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                _Destroy(_Ptr, _Mylast);
                _Mylast = _Myfirst + _Right.size();
            }
            else if (_Right.size() <= capacity())
            {
                T* _Ptr = _Right._Myfirst + size();
                GvUncheckedCopy(_Right._Myfirst, _Ptr, _Myfirst);
                _Mylast = _Ucopy(_Ptr, _Right._Mylast, _Mylast);
            }
            else
            {
                if (_Myfirst != 0)
                {
                    _Destroy(_Myfirst, _Mylast);
                    this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
                }
                if (_Buy(_Right.size()))
                {
                    _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
                }
            }
        }
        return *this;
    }
    void _Insert_n(GvConstIterator<T> _Where, unsigned int _Count, const T& _Val);
    GvIterator<T> insert(GvConstIterator<T> _Where, const T& _Val)
    {
        unsigned int _Off = size() == 0 ? 0 : _Where - begin();
        _Insert_n(_Where, 1, _Val);
        return begin() + _Off;
    }
    void push_back(const T& _Val)
    {
        if (size() < capacity())
        {
            _Mylast = _Ufill(_Mylast, 1, _Val);
        }
        else
        {
            insert(end(), _Val);
        }
    }
};
struct GvPart
{
    int unk00;
    ~GvPart();
};
struct GvNode
{
    virtual ~GvNode();
};
struct GvLink
{
    int unk00;
    ~GvLink();
};
}
using namespace shutb2b9;

inline bool TreeGeometryInitialized(CTreeEngine* tree)
{
    return *(bool*)((char*)tree + 0x21);
}

// The shared class does not declare this cleanup routine. Keep its ECX receiver
// as a local free function rather than recreating an engine class.
// @fnv 0x00b2b940
void __fastcall ClearTreeGeometry(CTreeEngine* tree)
{
    if (TreeGeometryInitialized(tree))
    {
        delete (*(GvPart**)&tree->unk58);
        (*(GvPart**)&tree->unk58) = 0;
        for (int i = 0; i < tree->unkd8; ++i)
        {
            if ((*(GvVector<GvNode*>**)&tree->unkec))
            {
                for (unsigned int j = 0; j < (*(GvVector<GvNode*>**)&tree->unkec)[i].size(); ++j)
                {
                    delete (*(GvVector<GvNode*>**)&tree->unkec)[i][j];
                    (*(GvVector<GvNode*>**)&tree->unkec)[i][j] = 0;
                }
                (*(GvVector<GvNode*>**)&tree->unkec)[i].clear();
            }
        }
        delete[] (*(GvVector<GvNode*>**)&tree->unkec);
        (*(GvVector<GvNode*>**)&tree->unkec) = 0;
        for (unsigned int k = 0; k < (*(GvVector<GvLink*>*)&tree->unk60).size(); ++k)
        {
            delete (*(GvVector<GvLink*>*)&tree->unk60)[k];
            (*(GvVector<GvLink*>*)&tree->unk60)[k] = 0;
        }
        (*(GvVector<GvLink*>*)&tree->unk60).clear();
        (*(bool*)((char*)tree + 0x21)) = false;
    }
}

extern float DAT_010a5664;
extern float DAT_010a5668;
inline float& TreeVectorComponent(NiPoint3* point, int i)
{
    return (&point->x)[i];
}

inline void SetTreeVector(NiPoint3* point, float fX, float fY, float fZ)
{
    point->x = fX;
    point->y = fY;
    point->z = fZ;
}

// @fnv 0x00b2bc70
// src: COMMUNITY 0x00b2bc70
void CTreeEngine::SetWind(float fScale)
{
    *(float*)((char*)this + 0x124) = fScale;
    float fY = DAT_010a5664 * fScale * TreeVectorComponent((NiPoint3*)&m_sub10c, 1);
    float fX = DAT_010a5668 * fScale * TreeVectorComponent((NiPoint3*)&m_sub10c, 0);
    SetTreeVector((NiPoint3*)((char*)this + 0x118), -fX, fX, fY);
}

struct S2bde0_Str
{
    int iAl;
    int iBuf0;
    int iBuf4;
    int iBuf8;
    int iBufC;
    int iSize;
    int iRes;
    S2bde0_Str(const char* s);
    __forceinline S2bde0_Str(const S2bde0_Str& r)
    {
        fopen_0044a730(false, 0);
        AssignSubstring(r, 0, DAT_010173f0);
    }
    inline S2bde0_Str(struct S2bde0_RStr s);
    __forceinline ~S2bde0_Str()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
    S2bde0_Str& AssignSubstring(const S2bde0_Str& r, unsigned o, unsigned n);
    __forceinline S2bde0_Str& operator=(const S2bde0_Str& r)
    {
        AssignSubstring(r, 0, DAT_010173f0);
        return *this;
    }
};
struct S2bde0_RStr : S2bde0_Str
{
};
struct S2bde0_Name : S2bde0_Str
{
    using S2bde0_Str::operator=;
    S2bde0_Str ProcessEntries_00b09f90();
};
inline S2bde0_Str::S2bde0_Str(S2bde0_RStr s)
{
    fopen_0044a730(false, 0);
    AssignSubstring(s, 0, DAT_010173f0);
}
struct S2bde0_ExBase
{
    int iBase04;
    int iBase08;
    int iBase0C;
    int iBase10;
    int iBase14;
    int iBase18;
    int iBase1C;
    int iBase20;
    int iBase24;
    S2bde0_ExBase(const S2bde0_Str& s);
    virtual ~S2bde0_ExBase();
};
struct FUN_00b09480 : S2bde0_ExBase
{
    FUN_00b09480(const S2bde0_Str& msg, bool bErrno) : S2bde0_ExBase(bErrno ? S2bde0_Str("e") : msg)
    {
        int dq[42];
        dq[0] = 0;
    }
    virtual ~FUN_00b09480();
};
struct S2bde0_Parser
{
    float CTreeFileAccess_ParseFloat();
    bool ProcessAndTransformResult_00b06180();
    S2bde0_RStr CTreeFileAccess_ParseString();
};
struct S2bde0_Ctx
{
    int i00;
    int i04;
    int i08;
    int i0C;
    int i10;
    int i14;
    int i18;
    int i1C;
    int i20;
    int i24;
    int i28;
    int i2C;
    int i30;
    int i34;
    int i38;
    int i3C;
    int i40;
    int i44;
    int i48;
    int i4C;
    int i50;
    int i54;
    int i58;
    int i5C;
    int i60;
    int i64;
    int i68;
    int i6C;
    int i70;
    int i74;
    int i78;
    int i7C;
    int i80;
    int i84;
    int i88;
    int i8C;
    int i90;
    int i94;
    int i98;
    int i9C;
    int iA0;
    int iA4;
    int iA8;
    int iAC;
    int iB0;
    int iB4;
    int iB8;
    int iBC;
    int iC0;
    int iC4;
    int iC8;
    int iCC;
    int iD0;
    int iD4;
    int iD8;
    int iDC;
    int iE0;
    int iE4;
    int iE8;
    int iEC;
};
inline void Gap1()
{
    int aH[1];
}
inline void DeadEnd()
{
    int aiE[9];
}
inline void S2bde0_ResetIn()
{
    S2bde0_Ctx kDummy;
    kDummy.i24 = 0;
}
inline void S2bde0_Reset()
{
    S2bde0_ResetIn();
}

// @fnv 0x00b2bde0
// src: XBOX_PDB 0x00b2bde0
void CTreeEngine::ParseTreeInfo(ElementIterator* p)
{
    int iCount;
    int iToken = ((ElementIterator*)p)->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x7d0: {
            Gap1();
            S2bde0_Str kTmp(((S2bde0_Parser*)p)->CTreeFileAccess_ParseString());
            (*(S2bde0_Name*)&m_pcFileName) = kTmp;
        }
            {
                (*(S2bde0_Name*)&m_pcFileName) = (*(S2bde0_Name*)&m_pcFileName).ProcessEntries_00b09f90();
                break;
            }
        case 0x7d5: {
            iCount = ((ElementIterator*)p)->GetNextElement();
            InitSeed(iCount);
            break;
        }
        case 0x7d3:
            (*(float*)&unk44) = ((S2bde0_Parser*)p)->CTreeFileAccess_ParseFloat();
            break;
        case 0x7d1:
            (*(float*)&unk40) = ((S2bde0_Parser*)p)->CTreeFileAccess_ParseFloat();
            break;
        case 0x7d4:
            ((ElementIterator*)p)->GetNextElement();
            break;
        case 0x7d2:
            ((S2bde0_Parser*)p)->ProcessAndTransformResult_00b06180();
            break;
        case 0x7d6:
            (*(float*)&unk4c) = ((S2bde0_Parser*)p)->CTreeFileAccess_ParseFloat();
            break;
        case 0x7d7:
            (*(float*)&unk50) = ((S2bde0_Parser*)p)->CTreeFileAccess_ParseFloat();
            break;
        case 0x3f6:
            ProcessEntries_00b2c790(p);
            break;
        default:
            throw FUN_00b09480("malformed general tree information", false);
        }
        iToken = ((ElementIterator*)p)->GetNextElement();
    } while (iToken != 0x3eb);
    DeadEnd();
}

namespace fnv_00b2c130 {
void __cdecl FUN_00ec7c56();
void __cdecl CIdvBranch_SortBranchVector(void* p);
void __cdecl FormHeapFreeAndLog_00401030(void* p);

struct Elem
{
    int m_00[12];
    float m_30;
    float m_34;
    float W()
    {
        return m_30;
    }
    void Set(float f)
    {
        m_34 = f;
    }
    void BuildStripIndices(int a, void* p);
};

struct FUN_00b17db0;
struct CIter
{
    int m_00;
    int m_04;
};
struct Iter : CIter
{
    Iter(Elem** p, FUN_00b17db0* v)
    {
        FUN_00b42980(p, v);
    }
    Iter()
    {}
    Iter(const Iter& o)
    {
        (CIter&)* this = (const CIter&)o;
    }
    void FUN_00b42980(Elem** p, FUN_00b17db0* v);
    void UpdateState_00b2e330(int i);
    Iter operator+(int i)
    {
        Iter tmp = *this;
        tmp.UpdateState_00b2e330(i);
        return tmp;
    }
};

struct VB
{
    void* m_00;
    ~VB()
    {
        void* p = m_00;
        FormHeapFreeAndLog_00401030(p);
    }
};

struct FUN_00b17db0 : VB
{
    int m_04;
    int m_08;
    Elem** m_pRayStart;
    Elem** m_kRayEnd;
    FUN_00b17db0();
    ~FUN_00b17db0()
    {
        int d[7];
        UpdateState_00b17f50();
    }
    void UpdateState_00b17f50();
    unsigned int size()
    {
        return m_kRayEnd - m_pRayStart;
    }
    Elem*& operator[](unsigned int i)
    {
        if (i >= size())
            FUN_00ec7c56();
        return m_pRayStart[i];
    }
    Iter begin()
    {
        return Iter(m_pRayStart, this);
    }
    void UpdateState_00b15390(Elem** pp);
    Iter EvaluateValue_00b2def0(CIter p);
    Iter UpdateState_00b156b0(CIter p, Elem** pp);
};

struct FUN_00b3f100
{
    char m_00;
    FUN_00b3f100();
    ~FUN_00b3f100()
    {
        FUN_00aa7830();
    }
    void FUN_00aa7830();
    float FUN_00b3f130(float a, float b);
};

struct Obj58
{
    void CIdvBranch_BuildBranchVector(FUN_00b17db0* vec);
};

struct Obj5c
{
    int m_00[34];
    FUN_00b17db0 m_88;
    void CIndexedGeometry_DeleteLodStrip(int a);
    void CIndexedGeometry_ResetStripCounter(unsigned short a);
    void CIndexedGeometry_AddStrip(int a, int b, int c);
};

inline float W(Elem* const& e)
{
    return e->m_30;
}
inline void Dead2()
{
    int a[2];
}
inline void Dead5()
{
    int a[5];
}
inline void Dead9()
{
    int a[9];
}
inline const float& Max(const float& a, const float& b)
{
    return a < b ? b : a;
}

inline unsigned int Count(CTreeEngine* tree)
{
    unsigned int r = tree->unk78;
    return r;
}
inline float Lerp(CTreeEngine* tree, float t, float a)
{
    return a + (tree->unkF4 - a) * t;
}
} // namespace fnv_00b2c130

// @fnv 0x00b2c130
// src: COMMUNITY 0x00b2c130
void CTreeEngine::BuildBranchLods()
{
    using namespace fnv_00b2c130;
    int v_j;
    Dead2();
    FUN_00b17db0 k;
    if (((Obj58*)unk58))
    {
        if ((unsigned short)(((Obj5c*)unk5c)->m_88.size() / 3) > 0)
            ((Obj58*)unk58)->CIdvBranch_BuildBranchVector(&k);
    }
    float v_sum = 0.0f;
    float v_maxA = 0.0f;
    unsigned int dir;
    float eq;
    float p;
    unsigned int v_pad;
    for (v_pad = 0; v_pad < k.size(); v_pad++)
    {
        eq = W(k[v_pad]);
        v_sum = v_sum + eq;
        if (eq > v_maxA)
            v_maxA = eq;
    }
    FUN_00b3f100 q;
    float fDist = 1.0f - unk104;
    FUN_00b17db0 v_cntIn;
    for (dir = 0; dir < k.size(); dir++)
    {
        float v_z;
        Dead2();
        v_z = W(k[dir]);
        if (v_z > v_maxA * fDist)
        {
            Dead9();
            v_cntIn.UpdateState_00b15390(&k[dir]);
            k.EvaluateValue_00b2def0(k.begin() + dir);
            dir--;
        }
        else
        {
            Dead5();
            float v_g = q.FUN_00b3f130(0.0f, unk100);
            float v_r = 1.0f - v_g;
            v_z = v_r * v_z + v_g * v_maxA;
            v_z = Max(v_z, 0.0f);
            k[dir]->Set(v_z);
        }
    }
    CIdvBranch_SortBranchVector(&k);
    CIdvBranch_SortBranchVector(&v_cntIn);
    {
        int v_n;
        for (v_n = 0; v_n < v_cntIn.size(); v_n++)
            k.UpdateState_00b156b0(k.begin(), &v_cntIn[v_n]);
    }
    Dead9();
    unsigned int v_k;
    v_k = Count(this);
    {
        unsigned int v_p;
        for (v_p = 0; v_p < v_k; v_p++)
        {
            if (!v_p)
                ((Obj5c*)unk5c)->CIndexedGeometry_DeleteLodStrip(0);
            float v_acc = (int)v_k < 2 ? 1.0f : Lerp(this, (float)((double)v_p / (double)(int)(v_k - 1)), unkF8);
            float v_target = v_acc * v_sum;
            int lhs = 0;
            float w = 0.0f;
            unsigned int e;
            for (e = 0; e < k.size() && w < v_target; e++)
            {
                w = w + W(k[e]);
                lhs = 1 + lhs;
            }
            ((Obj5c*)unk5c)->CIndexedGeometry_ResetStripCounter((unsigned short)v_p);
            if (v_p == 0 && lhs == 0)
            {
                ((Obj5c*)unk5c)->CIndexedGeometry_AddStrip(0, 0, 0);
            }
            else
            {
                int v_s;
                for (v_s = 0; v_s < lhs; v_s++)
                    k[v_s]->BuildStripIndices(v_p, ((Obj5c*)unk5c));
            }
        }
    }
}

struct ElemB2CB50
{
    int unk00;
    int unk04;
};
struct AuxB2CB50
{
    int unk00;
};
struct NonscalarTagB2CB50
{
};
inline NonscalarTagB2CB50 PtrCatB2CB50(ElemB2CB50*&, ElemB2CB50*&)
{
    NonscalarTagB2CB50 kCat;
    return kCat;
}
template <class T> inline void DestroyB2CB50(T* pkPtr)
{
    pkPtr->~T();
}
inline void DestroyRangeB2CB50(ElemB2CB50* pkCurrentObject, ElemB2CB50* pkLast, NonscalarTagB2CB50)
{
    for (; pkCurrentObject != pkLast; ++pkCurrentObject)
        DestroyB2CB50(pkCurrentObject);
}
inline void DestroyRangeB2CB50(ElemB2CB50* pkCurrentObject, ElemB2CB50* pkLast)
{
    DestroyRangeB2CB50(pkCurrentObject, pkLast, PtrCatB2CB50(pkCurrentObject, pkCurrentObject));
}
struct AuxBaseB2CB50
{
    ~AuxBaseB2CB50()
    {
        delete m_pkAux;
    }
    AuxB2CB50* m_pkAux;
};
class VectorValB2CB50 : public AuxBaseB2CB50
{
  public:
    void Destroy(ElemB2CB50* pkCurrentObject, ElemB2CB50* pkLast)
    {
        DestroyRangeB2CB50(pkCurrentObject, pkLast);
    }
    void Deallocate(ElemB2CB50* pkPtr, unsigned int)
    {
        delete pkPtr;
    }
    void Tidy()
    {
        if (m_pkFirst != 0)
        {
            Destroy(m_pkFirst, m_pkLast);
            Deallocate(m_pkFirst, m_pkEnd - m_pkFirst);
        }
        m_pkFirst = 0;
        m_pkLast = 0;
        m_pkEnd = 0;
    }
    int unk04;
    int unk08;
    ElemB2CB50* m_pkFirst;
    ElemB2CB50* m_pkLast;
    ElemB2CB50* m_pkEnd;
};
class FUN_00b2cb50 : public VectorValB2CB50
{
  public:
    ~FUN_00b2cb50();
};

// @fnv 0x00b2cb50
FUN_00b2cb50::~FUN_00b2cb50()
{
    Tidy();
}

namespace fnv_00b2cbc0 {
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
};
int __cdecl CBillboardLeaf_Parse(Parser* p);
struct LodQ
{
    int ai[6];
    LodQ();
    ~LodQ();
    void UpdateState_00b15390(const int& v);
};
inline void DeadTop()
{
    int aiD[130];
    aiD[88] = 0;
}

} // namespace fnv_00b2cbc0

// @fnv 0x00b2cbc0
// src: XBOX_PDB 0x00b2cbc0
void CTreeEngine::ParseLeafCluster(ElementIterator* p)
{
    using namespace fnv_00b2cbc0;
    using fnv_00b2cbc0::FUN_00b09480;
    DeadTop();
    int iCount = 0;
    int iLevel = p->GetNextElement();
    unkd8 = iLevel;
    delete[] (*(LodQ**)&unkec);
    (*(LodQ**)&unkec) = new LodQ[unkd8];
    int iTok = p->GetNextElement();
    while (iTok != 0x1b59)
    {
        if (iCount >= unkd8)
            throw FUN_00b09480("too many leaf lod levels", false);
        if (iTok != 0x1b5a)
            throw FUN_00b09480("malformed leaf lod data", false);
        iTok = p->GetNextElement();
        while (iTok != 0x1b5b)
        {
            if (iTok != 0x1b5c)
                throw FUN_00b09480("malformed leaf lod data", false);
            (*(LodQ**)&unkec)[iCount].UpdateState_00b15390(CBillboardLeaf_Parse((Parser*)p));
            iTok = p->GetNextElement();
        }
        iCount++;
        iTok = p->GetNextElement();
    }
    (*(bool*)&unkf0) = true;
}

namespace fnv_00b2d090 {
struct TextureControlB2D090
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    short unk1C;
    bool m_bFlag;
    char unk1F;
    float m_fValue;
};
} // namespace fnv_00b2d090

// ParseBool is defined in the class: VC9 declines to inline it here but keeps its two slots (0x00b2d090's frame gap
// above the first operator[]); its out-of-line copy is 0x00b06180.
struct TreeFileAccess
{
    int ParseToken();
    bool ParseBool()
    {
        return m_vBuffer[m_uiPosition++] != 0;
    }
    float ParseReal();
    unsigned int m_uiPosition;
    std::vector<unsigned char> m_vBuffer;
};

// IdvFileError's constructor is attempted and declined by /Ob1 here (its slots stay reserved at each throw):
// 0x00b2d090 and 0x00b2d2e0 call it at 0x00b09480.
inline IdvFileError::IdvFileError(const std::string& strMessage, bool bUseErrno)
    : std::runtime_error(strMessage + " [" + (bUseErrno ? std::string(strerror(errno)) : std::string("")) + "]")
{}

// @fnv 0x00b2d090
// src: XBOX_PDB 0x00b2d090
void CTreeEngine::ParseTextureControls(TreeFileAccess* pFile)
{
    using namespace fnv_00b2d090;
    for (unsigned int i = 0; i < (*(std::vector<TextureControlB2D090*>*)&unk60).size(); ++i)
    {
        if (pFile->ParseToken() != 15002)
            throw IdvFileError("malformed texture controls", false);
        (*(std::vector<TextureControlB2D090*>*)&unk60)[i]->m_bFlag = pFile->ParseBool();
        if (pFile->ParseToken() != 15003)
            throw IdvFileError("malformed texture controls", false);
        (*(std::vector<TextureControlB2D090*>*)&unk60)[i]->m_fValue = pFile->ParseReal();
    }
    if (pFile->ParseToken() != 15001)
        throw IdvFileError("malformed texture controls", false);
}

// The same SpeedTree file reader as TreeFileAccess, seen through CTreeEngine.h's Reader declaration. Its own
// members, not ElementIterator's: the base-class call form shifts the /Ob1 inline budget of 0x00b2d2e0.
struct Reader
{
    int ParseToken();
    float ParseReal();
};

namespace fnv_00b2d2e0 {
struct Flare
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float value24;
    int value28;
    float value2c;
    float value30;
    float value34;
    float value38;
    float value3c;
    float value40;
    float value44;
    float value48;
    float value4c;
};
} // namespace fnv_00b2d2e0

// @fnv 0x00b2d2e0
// src: XBOX_PDB 0x00b2d2e0
void CTreeEngine::ParseFlareInfo(Reader* reader)
{
    using namespace fnv_00b2d2e0;
    for (unsigned int index = 0; index < (*(std::vector<Flare*>*)&unk60).size(); ++index)
    {
        if (reader->ParseToken() != 0x3e82)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value24 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e83)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value28 = reader->ParseToken();
        if (reader->ParseToken() != 0x3e84)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value2c = reader->ParseReal();
        if (reader->ParseToken() != 0x3e85)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value30 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e86)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value34 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e87)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value38 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e88)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value3c = reader->ParseReal();
        if (reader->ParseToken() != 0x3e89)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value40 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e8a)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value44 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e8b)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value48 = reader->ParseReal();
        if (reader->ParseToken() != 0x3e8c)
            throw IdvFileError("malformed flare info", false);
        (*(std::vector<Flare*>*)&unk60)[index]->value4c = reader->ParseReal();
    }
    if (reader->ParseToken() != 0x3e81)
        throw IdvFileError("malformed flare info", false);
}

struct Elem
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50;
};
struct input_iterator_tag
{
};
struct forward_iterator_tag : input_iterator_tag
{
};
struct bidirectional_iterator_tag : forward_iterator_tag
{
};
struct random_access_iterator_tag : bidirectional_iterator_tag
{
};
struct _Nonscalar_ptr_iterator_tag
{
};
struct _Range_checked_iterator_tag
{
};
struct _Unchanged_checked_iterator_base_type_tag
{
};
inline random_access_iterator_tag _Iter_random(Elem* const&, Elem* const&)
{
    random_access_iterator_tag _Cat;
    return _Cat;
}
inline _Nonscalar_ptr_iterator_tag _Ptr_cat(Elem*&, Elem*&)
{
    _Nonscalar_ptr_iterator_tag _Cat;
    return _Cat;
}
inline Elem* _Checked_base(Elem* const& _It, _Unchanged_checked_iterator_base_type_tag)
{
    return _It;
}
inline Elem* _Checked_base(Elem* const& _It)
{
    _Unchanged_checked_iterator_base_type_tag _Base_tag;
    return _Checked_base(_It, _Base_tag);
}
Elem* __cdecl Object_ProcessAndReturnValue_00b2e500(Elem*, Elem*, Elem*, random_access_iterator_tag, _Nonscalar_ptr_iterator_tag,
                           _Range_checked_iterator_tag);
Elem* __cdecl Runtime_EvaluateValue_00b2e3f0(Elem*, Elem*, Elem*);
inline Elem* copy_new(Elem* _First, Elem* _Last, Elem* _Dest)
{
    return Object_ProcessAndReturnValue_00b2e500(_Checked_base(_First), _Checked_base(_Last), _Dest, _Iter_random(_First, _Dest),
                        _Ptr_cat(_First, _Dest), _Range_checked_iterator_tag());
}
void __cdecl operator delete(void*);
struct Alloc
{
    void deallocate(Elem* _Ptr, unsigned int)
    {
        ::operator delete(_Ptr);
    }
};
Elem* __cdecl Runtime_ProcessEntries_00b2e570(Elem*, Elem*, Elem*, Alloc&, _Nonscalar_ptr_iterator_tag, _Range_checked_iterator_tag);
inline Elem* unchecked_uninitialized_copy(Elem* _First, Elem* _Last, Elem* _Dest, Alloc& _Al)
{
    return Runtime_ProcessEntries_00b2e570(_Checked_base(_First), _Checked_base(_Last), _Dest, _Al, _Ptr_cat(_First, _Dest),
                        _Range_checked_iterator_tag());
}
struct BaseAux
{
    void* _Myownedaux;
};
struct BaseAlloc : BaseAux
{
    char _Alaux;
};
struct VecVal : BaseAlloc
{
    Alloc _Alval;
};
inline void S00b2db10_padA()
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
    int a9;
    int a10;
    int a11;
}
inline void S00b2db10_padB()
{
    int b0;
    int b1;
    int b2;
    int b3;
    int b4;
    int b5;
}
inline void S00b2db10_padC()
{
    int c0;
    int c1;
    int c2;
    int c3;
    int c4;
    int c5;
    int c6;
    int c7;
}
inline void S00b2db10_padC2()
{
    char s0;
    char s1;
}
inline void S00b2db10_padD()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
}
inline void S00b2db10_padE()
{
    int e0;
    int e1;
    int e2;
    int e3;
    int e4;
    int e5;
    int e6;
    int e7;
    int e8;
    int e9;
    int e10;
    int e11;
    int e12;
    int e13;
    int e14;
    int e15;
    int e16;
    int e17;
    int e18;
    int e19;
    int e20;
    int e21;
    int e22;
    int e23;
    int e24;
    int e25;
}
// std::vector of 0x54-byte Elem (_Myfirst/_Mylast/_Myend): 0x00b2db10 = its operator=, 0x00b2e080 = _Buy (GvVectorStore::_Buy in blk_00b20000).
struct Elem54Vector : VecVal
{
    Elem* _Myfirst;
    Elem* _Mylast;
    Elem* _Myend;
    unsigned int size() const
    {
        return _Mylast - _Myfirst;
    }
    unsigned int capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    void ClearAllElements();
    void B2EDestroyRange_Thunk(Elem*, Elem*);
    bool InitBuffer(unsigned int);
    Elem* _Ucopy(Elem* _First, Elem* _Last, Elem* _Ptr)
    {
        return unchecked_uninitialized_copy(_First, _Last, _Ptr, this->_Alval);
    }
    Elem54Vector& CTreeEngine_SetLeafTextures(const Elem54Vector& _Right);
};
// @fnv 0x00b2db10
// src: COMMUNITY 0x00b2db10
Elem54Vector& Elem54Vector::CTreeEngine_SetLeafTextures(const Elem54Vector& _Right)
{
    if (this != &_Right)
    {
        S00b2db10_padA();
        if (_Right.size() == 0)
            ClearAllElements();
        else if (_Right.size() <= size())
        {
            Elem* z = copy_new(_Right._Myfirst, _Right._Mylast, _Myfirst);
            B2EDestroyRange_Thunk(z, _Mylast);
            _Mylast = _Myfirst + _Right.size();
            S00b2db10_padB();
        }
        else if (_Right.size() <= capacity())
        {
            Elem* z;
            z = _Right._Myfirst + size();
            Runtime_EvaluateValue_00b2e3f0(_Right._Myfirst, z, _Myfirst);
            S00b2db10_padC();
            S00b2db10_padC2();
            _Mylast = _Ucopy(z, _Right._Mylast, _Mylast);
            S00b2db10_padD();
        }
        else
        {
            if (_Myfirst != 0)
            {
                B2EDestroyRange_Thunk(_Myfirst, _Mylast);
                this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
            }
            if (InitBuffer(_Right.size()))
            {
                S00b2db10_padE();
                _Mylast = _Ucopy(_Right._Myfirst, _Right._Mylast, _Myfirst);
            }
        }
    }
    return *this;
}

struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
namespace LodErrorDetail {
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
}
extern const float DAT_0101e2bc;
inline void DeadTop()
{
    int aiD[63];
    aiD[14] = 0;
}

// @fnv 0x00b2ceb0
// src: XBOX_PDB 0x00b2ceb0
void __thiscall CTreeEngine::ParseLodInfo(ElementIterator* a)
{
    DeadTop();
    int token = a->GetNextElement();
    do
    {
        switch (token)
        {
        case 0x232f:
            this->unk78 = a->GetNextElement();
            break;
        case 0x2330:
            this->unkF4 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->CTreeFileAccess_ParseFloat();
            break;
        case 0x2332:
            this->unkFC = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->CTreeFileAccess_ParseFloat();
            if (this->unkFC == 0.0f)
                this->unkFC = DAT_0101e2bc;
            break;
        case 0x2333:
            this->unkd8 = a->GetNextElement();
            break;
        case 0x2334:
            this->unkF8 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->CTreeFileAccess_ParseFloat();
            break;
        case 0x2335:
            this->unk100 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->CTreeFileAccess_ParseFloat();
            break;
        case 0x2336:
            this->unk104 = static_cast<S2bde0_Parser*>(static_cast<void*>(a))->CTreeFileAccess_ParseFloat();
            break;
        default:
            throw LodErrorDetail::FUN_00b09480("malformed engine lod data", false);
        }
    } while ((token = a->GetNextElement()) != 0x232e);
}

extern const char str_010a54cc[];
extern char DAT_01170384;

extern "C" void __stdcall FUN_00ec7894(void* pException, void* apThrowInfo);

struct S00b2c790_Error
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    void FUN_00b09480(S2bde0_Str* text, int value);
};

struct S00b2c790_Sub
{
    void std_vector_clear();
    void UpdateState_00b15390(int* value);
};

__forceinline S00b2c790_Sub* TreeSub(CTreeEngine* tree)
{
    return reinterpret_cast<S00b2c790_Sub*>(reinterpret_cast<char*>(tree) + 0x60);
}

__forceinline void TreeClear()
{
    int local[0x178 / sizeof(int)];
    local[0x38 / sizeof(int)] = 0;
}

int __cdecl Object_ProcessEntries_00b3f8e0(ElementIterator* value);

// @fnv 0x00b2c790
// src: GUESS 0x00b2c790 (confidence: low)
void CTreeEngine::ProcessEntries_00b2c790(ElementIterator* parser)
{
    S00b2c790_Error error2;
    int count_2;
    int index4;
    int item5;
    int branchCount;

    TreeClear();
    TreeSub(this)->std_vector_clear();

    count_2 = reinterpret_cast<ElementIterator*>(parser)->GetNextElement();
    for (index4 = 0; index4 < count_2; ++index4)
    {
        item5 = Object_ProcessEntries_00b3f8e0(reinterpret_cast<ElementIterator*>(parser));
        TreeSub(this)->UpdateState_00b15390(&item5);
    }

    branchCount = reinterpret_cast<ElementIterator*>(parser)->GetNextElement();
    if (branchCount != 0x3f7)
    {
        S2bde0_Str text4(str_010a54cc);
        error2.FUN_00b09480(&text4, 0);
        FUN_00ec7894(&error2, &DAT_01170384);
    }
}
