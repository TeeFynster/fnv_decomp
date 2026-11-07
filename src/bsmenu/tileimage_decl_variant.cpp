
// src/bsmenu/tileimage_decl_variant.cpp - declaration variant unit created 2026-10-24 by decl_variants.py for paused function 0x00a06dd0: the skeleton of src/bsmenu/tileimage.cpp
// with declarations corrected to what the original code does (tileimage_private.h: int strcat_s(char*, unsigned int, const char*); -> extern "C" int __cdecl strcat_s(char*, unsigned in). Move the function to its real unit once
// that unit declares it this way.

#include "../../include/MemoryManager.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiTexture.h"
#include "../../include/Setting.h"
// Exe 0x00a06dd0: unit-local TileimageInterfaceView view used by this matched implementation.
struct TileimageInterfaceView
{
    static float __cdecl GetInterfaceFloat();
};
struct FileFinder;
extern FileFinder* g_fileFinder;
struct FileFinder
{
    int GetFileLocation(char*, char*, unsigned int, unsigned int);
    static FileFinder* GetSingleton()
    {
        return g_fileFinder;
    }
};
int _strcpy_s(char*, unsigned int, const char*);
int _strcat_s(char*, unsigned int, const char*);
namespace L {
struct NiTexturePtr
{
    NiTexture* m_pObject;
    NiTexturePtr(NiTexture* p = 0)
    {
        m_pObject = p;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~NiTexturePtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    bool operator==(const NiTexture* p) const
    {
        return m_pObject == p;
    }
};
}
bool fnv_NiStreamGetTexture(char*, L::NiTexturePtr*);
void ResolveTexturePath(const char* apFilename, float* afScale, float afZoom, char* axOut);

typedef unsigned int size_t;
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" size_t __cdecl strlen(const char*);
extern "C" char* __cdecl strrchr(const char*, int);
extern "C" char* __cdecl strtok(char*, const char*);
extern "C" double __cdecl atof(const char*);
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
inline unsigned int BSStringLength(const char* p)
{
    return strlen(p);
}
inline unsigned int BSStringCapacityMaximum(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}
// local form of BSStringT<char>: 0x00a06dd0 needs inline construction/Set and trivial destruction; shared replacement changes bytes.
template <class CharT> struct GameString
{
    char* text;
    unsigned short length, capacity;
    unsigned int MaxLength() const
    {
        return capacity;
    }
    void SetLength(unsigned int n)
    {
        length = n <= 65535 ? (unsigned short)n : 65535;
    }
    void SetCapacity(unsigned int n)
    {
        capacity = n <= 65535 ? (unsigned short)n : 65535;
    }
    GameString() : text(0)
    {
        SetLength(0);
        SetCapacity(0);
    }
    bool Set(const char* source, unsigned int requested)
    {
        unsigned int count = source ? BSStringLength(source) : 0;
        unsigned int reserve = BSStringCapacityMaximum(count, requested);
        unsigned int copySize = count + 1;
        unsigned int allocationSize = reserve + 1;
        if (reserve <= MaxLength())
        {
            if (reserve)
            {
                if (source)
                    memcpy(text, source, copySize);
                else
                    *text = 0;
            }
            else
            {
                if (text)
                    delete text;
                text = 0;
                reserve = 0;
                SetCapacity(reserve);
            }
        }
        else
        {
            char* old = text;
            text = new char[allocationSize];
            if (source)
                memcpy(text, source, copySize);
            else
                *text = 0;
            if (old)
                delete old;
            SetCapacity(reserve);
        }
        SetLength(count);
        return count != 0;
    }
    const char* c_str() const
    {
        return text;
    }
};
typedef GameString<char> AtlasString;
extern MemoryManager _g_memoryManager;
struct AtlasRect
{
    float left, right, top, bottom;
    AtlasRect() : left(0), right(0), top(0), bottom(0)
    {}
};
struct AtlasEntry
{
    AtlasString definition, image, texture;
    AtlasRect rect;
    AtlasEntry()
    {}
    static void* operator new(size_t n)
    {
        return _g_memoryManager.Allocate(n);
    }
    static void operator delete(void*);
};
struct AtlasNode
{
    AtlasEntry* entry;
    AtlasNode* next;
    AtlasNode(AtlasEntry* const& value) : entry(value), next(0)
    {}
    static void* operator new(size_t n)
    {
        return _g_memoryManager.Allocate(n);
    }
    void AddToHead(AtlasEntry** value)
    {
        if (!*value)
            return;
        if (entry)
        {
            AtlasNode* node = new AtlasNode(entry);
            node->next = next;
            next = node;
            entry = *value;
        }
        else
            entry = *value;
    }
    AtlasEntry* Get() const
    {
        return entry;
    }
};
extern AtlasNode g_sheetEntries;
struct AtlasFile
{
    virtual ~AtlasFile();
    virtual void S1();
    virtual void S2();
    virtual void S3();
    virtual void S4();
    virtual void S5();
    virtual void S6();
    virtual void S7();
    virtual bool Seek(int, int);
    virtual void S9();
    virtual void S10();
    virtual void S11();
    virtual void S12();
    virtual unsigned int ReadLine(char*, unsigned int, int);
};
AtlasFile* FileFinder_GetFile_(const char*, int, unsigned int);

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
extern "C" int __cdecl memcmp(const void*, const void*, size_t);
extern "C" int __cdecl memcpy_s(void*, size_t, const void*, size_t);
extern "C" int __cdecl memmove_s(void*, size_t, const void*, size_t);
namespace std {
template <class E> struct char_traits;
template <> struct char_traits<char>
{
    typedef char char_type;
    static bool eq(const char& _Left, const char& _Right)
    {
        return _Left == _Right;
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
    static size_t length(const char* _First)
    {
        return ::strlen(_First);
    }
    static int compare(const char* _First1, const char* _First2, size_t _Count)
    {
        return ::memcmp(_First1, _First2, _Count);
    }
    static char* _Copy_s(char* _First1, size_t _Size_in_bytes, const char* _First2, size_t _Count)
    {
        ::memcpy_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
    static char* _Move_s(char* _First1, size_t _Size_in_bytes, const char* _First2, size_t _Count)
    {
        ::memmove_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
};
struct _Secure_char_traits_tag
{
};
template <class T> inline _Secure_char_traits_tag _Char_traits_cat()
{
    _Secure_char_traits_tag _Secure;
    return _Secure;
}
namespace _Traits_helper {
template <class T>
inline typename T::char_type* copy_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count, _Secure_char_traits_tag)
{
    return T::_Copy_s(_First1, _Size, _First2, _Count);
}
template <class T>
inline typename T::char_type* copy_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count)
{
    return copy_s<T>(_First1, _Size, _First2, _Count, _Char_traits_cat<T>());
}
template <class T>
inline typename T::char_type* move_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count, _Secure_char_traits_tag)
{
    return T::_Move_s(_First1, _Size, _First2, _Count);
}
template <class T>
inline typename T::char_type* move_s(typename T::char_type* _First1, size_t _Size, const typename T::char_type* _First2,
                                     size_t _Count)
{
    return move_s<T>(_First1, _Size, _First2, _Count, _Char_traits_cat<T>());
}
}
template <class T> struct _Allocator_base
{
    typedef T value_type;
};
template <class T> class allocator : public _Allocator_base<T>
{
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef int difference_type;
    template <class U> struct rebind
    {
        typedef allocator<U> other;
    };
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    void deallocate(pointer _Ptr, size_type)
    {
        ::operator delete(_Ptr);
    }
    pointer allocate(size_type _Count)
    {
        return (pointer)::operator new(_Count * sizeof(T));
    }
    size_t max_size() const throw()
    {
        size_t _Count = (size_t)-1 / sizeof(T);
        return 0 < _Count ? _Count : 1;
    }
};
class _Container_base_secure
{
};
class _String_base : public _Container_base_secure
{
  public:
    static void _Xran();
    static void _Xlen();
};
template <class T, class A> class _String_val : public _String_base
{
  protected:
    typedef typename A::template rebind<T>::other _Alty;
    _String_val(_Alty _Al = _Alty()) : _Alval(_Al)
    {}

  public:
    _String_val(const _String_val& _Right) : _Alval(_Right._Alval)
    {}

  protected:
    _Alty _Alval;
};
template <class _Elem, class _Traits = char_traits<_Elem>, class _Ax = allocator<_Elem> >
class basic_string : public _String_val<_Elem, _Ax>
{
  public:
    typedef basic_string<_Elem, _Traits, _Ax> _Myt;
    typedef _String_val<_Elem, _Ax> _Mybase;
    typedef typename _Mybase::_Alty _Alloc;
    typedef typename _Alloc::size_type size_type;
    typedef typename _Alloc::difference_type _Dift;
    typedef _Dift difference_type;
    typedef typename _Alloc::pointer _Tptr;
    typedef typename _Alloc::const_pointer _Ctptr;
    typedef _Tptr pointer;
    typedef _Ctptr const_pointer;
    typedef typename _Alloc::reference _Reft;
    typedef _Reft reference;
    typedef typename _Alloc::const_reference const_reference;
    typedef typename _Alloc::value_type value_type;
    basic_string() : _Mybase()
    {
        _Tidy();
    }
    basic_string(const _Myt& _Right, size_type _Roff, size_type _Count, const _Alloc& _Al) : _Mybase(_Al)
    {
        _Tidy();
        assign(_Right, _Roff, _Count);
    }
    basic_string(const _Myt& _Right) : _Mybase(_Right)
    {
        _Tidy();
        assign(_Right, 0, npos);
    }
    ~basic_string()
    {
        _Tidy(true);
    }
    typedef _Traits traits_type;
    typedef _Alloc allocator_type;
    static const size_type npos;
    _Myt& operator=(const _Myt& _Right)
    {
        return (assign(_Right));
    }
    _Myt& append(const _Myt& _Right, size_type _Roff, size_type _Count)
    {
        if (_Right.size() < _Roff)
            _String_base::_Xran();
        size_type _Num = _Right.size() - _Roff;
        if (_Num < _Count)
            _Count = _Num;
        if (npos - _Mysize <= _Count || _Mysize + _Count < _Mysize)
            _String_base::_Xlen();
        if (0 < _Count && _Grow(_Num = _Mysize + _Count))
        {
            _Traits_helper::copy_s<_Traits>(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
            _Eos(_Num);
        }
        return (*this);
    }
// src: COMMUNITY 0x00a0c430
    _Myt& std_string_append(const _Elem* _Ptr, size_type _Count)
    {
        if (_Inside(_Ptr))
            return (append(*this, _Ptr - _Myptr(), _Count));
        if (npos - _Mysize <= _Count || _Mysize + _Count < _Mysize)
            _String_base::_Xlen();
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
        ;
        return (std_string_append(_Ptr, _Traits::length(_Ptr)));
    }
    _Myt& assign(const _Myt& _Right)
    {
        return (assign(_Right, 0, npos));
    }
    _Myt& assign(const _Myt& _Right, size_type _Roff, size_type _Count)
    {
        if (_Right.size() < _Roff)
            _String_base::_Xran();
        size_type _Num = _Right.size() - _Roff;
        if (_Count < _Num)
            _Num = _Count;
        if (this == &_Right)
            erase((size_type)(_Roff + _Num)), erase(0, _Roff);
        else if (_Grow(_Num))
        {
            _Traits_helper::copy_s<_Traits>(_Myptr(), _Myres, _Right._Myptr() + _Roff, _Num);
            _Eos(_Num);
        }
        return (*this);
    }
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
        ;
        return (assign(_Ptr, _Traits::length(_Ptr)));
    }
    _Myt& erase(size_type _Off = 0, size_type _Count = npos)
    {
        if (_Mysize < _Off)
            _String_base::_Xran();
        if (_Mysize - _Off < _Count)
            _Count = _Mysize - _Off;
        if (0 < _Count)
        {
            _Traits_helper::move_s<_Traits>(_Myptr() + _Off, _Myres - _Off, _Myptr() + _Off + _Count,
                                            _Mysize - _Off - _Count);
            size_type _Newsize = _Mysize - _Count;
            _Eos(_Newsize);
        }
        return (*this);
    }
    const _Elem* c_str() const
    {
        return (_Myptr());
    }
    size_type size() const
    {
        return (_Mysize);
    }
    size_type max_size() const
    {
        size_type _Num = _Mybase::_Alval.max_size();
        return (_Num <= 1 ? 1 : _Num - 1);
    }
// src: COMMUNITY 0x00a0c300
    size_type std_string_rfind(const _Elem* _Ptr, size_type _Off, size_type _Count) const
    {
        if (_Count == 0)
            return (_Off < _Mysize ? _Off : _Mysize);
        if (_Count <= _Mysize)
        {
            const _Elem* _Uptr = _Myptr() + (_Off < _Mysize - _Count ? _Off : _Mysize - _Count);
            for (;; --_Uptr)
                if (_Traits::eq(*_Uptr, *_Ptr) && _Traits::compare(_Uptr, _Ptr, _Count) == 0)
                    return (_Uptr - _Myptr());
                else if (_Uptr == _Myptr())
                    break;
        }
        return (npos);
    }
    size_type find_last_of(_Elem _Ch, size_type _Off = npos) const
    {
        return (std_string_rfind((const _Elem*)&_Ch, _Off, 1));
    }
    _Myt Substr(size_type _Off = 0, size_type _Count = npos) const
    {
        return (_Myt(*this, _Off, _Count, get_allocator()));
    }
    allocator_type get_allocator() const
    {
        return (_Mybase::_Alval);
    }
    enum
    {
        _BUF_SIZE = 16 / sizeof(_Elem) < 1 ? 1 : 16 / sizeof(_Elem)
    };

  public:
    enum
    {
        _ALLOC_MASK = sizeof(_Elem) <= 1   ? 15
                      : sizeof(_Elem) <= 2 ? 7
                      : sizeof(_Elem) <= 4 ? 3
                      : sizeof(_Elem) <= 8 ? 1
                                           : 0
    };
    void _Copy(size_type _Newsize, size_type _Oldlen)
    {
        size_type _Newres = _Newsize | _ALLOC_MASK;
        if (max_size() < _Newres)
            _Newres = _Newsize;
        else if (_Newres / 3 < _Myres / 2 && _Myres <= max_size() - _Myres / 2)
            _Newres = _Myres + _Myres / 2;
        _Elem* _Ptr = 0;
        try
        {
            _Ptr = _Mybase::_Alval.allocate(_Newres + 1);
        }
        catch (...)
        {
            _Newres = _Newsize;
            try
            {
                _Ptr = _Mybase::_Alval.allocate(_Newres + 1);
            }
            catch (...)
            {
                _Tidy(true);
                throw;
            }
        }
        if (0 < _Oldlen)
            _Traits_helper::copy_s<_Traits>(_Ptr, _Newres + 1, _Myptr(), _Oldlen);
        _Tidy(true);
        _Bx._Ptr = _Ptr;
        _Myres = _Newres;
        _Eos(_Oldlen);
    }
    void _Eos(size_type _Newsize)
    {
        _Traits::assign(_Myptr()[_Mysize = _Newsize], _Elem());
    }
    bool _Grow(size_type _Newsize, bool _Trim = false)
    {
        if (max_size() < _Newsize)
            _String_base::_Xlen();
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
    void _Tidy(bool _Built = false, size_type _Newsize = 0)
    {
        if (!_Built)
            ;
        else if (_BUF_SIZE <= _Myres)
        {
            _Elem* _Ptr = _Bx._Ptr;
            if (0 < _Newsize)
                _Traits_helper::copy_s<_Traits>(_Bx._Buf, _BUF_SIZE, _Ptr, _Newsize);
            _Mybase::_Alval.deallocate(_Ptr, _Myres + 1);
        }
        _Myres = _BUF_SIZE - 1;
        _Eos(_Newsize);
    }
    union _Bxty
    {
        _Elem _Buf[_BUF_SIZE];
        _Elem* _Ptr;
    } _Bx;
    _Elem* _Myptr()
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }
    const _Elem* _Myptr() const
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }
    size_type _Mysize;
    size_type _Myres;
};
typedef basic_string<char> string;
}
typedef std::string AtlasPath;
// @fnv 0x00a06dd0
// src: COMMUNITY 0x00a06dd0
void Tile_GetTextureAtlasInfo(const char* definition, const char* image, AtlasString* texture, float* bounds)
{
    char line5[1024];
    char filename9[260];
    _strcpy_s(filename9, 260, "Data\\Textures\\");
    AtlasFile* fileA = 0;
    if (definition && image && (texture || bounds))
    {
        const char* slashTmp = strrchr(image, '\\');
        bool foundImage = false;
        bool foundDefinition4 = false;
        _strcat_s(filename9, 260, definition);
        image = slashTmp ? slashTmp + 1 : image;
        for (AtlasNode* nodeB = &g_sheetEntries; nodeB && nodeB->entry; nodeB = nodeB->next)
        {
            if (!strcmp(nodeB->Get()->definition.c_str(), definition))
                foundDefinition4 = true;
            if (!strcmp(nodeB->entry->image.c_str(), image))
            {
                if (texture)
                    texture->Set(nodeB->entry->texture.c_str(), 0);
                if (bounds)
                {
                    bounds[0] = nodeB->entry->rect.left;
                    bounds[3] = nodeB->entry->rect.bottom;
                    bounds[2] = nodeB->entry->rect.top;
                    bounds[1] = nodeB->entry->rect.right;
                }
                foundImage = true;
            }
        }
        if (foundImage || (!foundImage && foundDefinition4))
        {
        }
        else
        {
            fileA = FileFinder_GetFile_(filename9, 0, 0x4000);
            if (fileA && fileA->Seek(0, 0))
            {
                while (fileA->ReadLine(line5, 1024, 10))
                {
                    AtlasPath str;
                    AtlasEntry* entry5 = 0;
                    strtok(line5, " ,\t");
                    if (line5[0] == '#' || line5[0] == '\n' || line5[0] == '\t' || line5[0] == '\r' || line5[0] == ' ')
                        continue;
                    entry5 = new AtlasEntry;
                    entry5->definition.Set(definition, 0);
                    entry5->image.Set(line5, 0);
                    str.assign(definition);
                    str = str.Substr(0, str.find_last_of('\\') + 1);
                    str.append(strtok(0, " ,\t"));
                    entry5->texture.Set(str.c_str(), 0);
                    for (int i3 = 0; i3 < 2; i3++)
                        strtok(0, " ,\t");
                    entry5->rect.left = (float)atof(strtok(0, " ,\t"));
                    entry5->rect.top = (float)atof(strtok(0, " ,\t"));
                    strtok(0, " ,");
                    entry5->rect.right = (float)atof(strtok(0, " ,\t"));
                    entry5->rect.bottom = (float)atof(strtok(0, " ,\t"));
                    entry5->rect.right += entry5->rect.left;
                    entry5->rect.bottom += entry5->rect.top;
                    if (!strcmp(entry5->image.c_str(), image))
                    {
                        if (texture)
                            texture->Set(entry5->texture.c_str(), 0);
                        if (bounds)
                        {
                            bounds[0] = entry5->rect.left;
                            bounds[3] = entry5->rect.bottom;
                            bounds[2] = entry5->rect.top;
                            bounds[1] = entry5->rect.right;
                        }
                    }
                    g_sheetEntries.AddToHead(&entry5);
                }
            }
            delete fileA;
        }
    }
}
