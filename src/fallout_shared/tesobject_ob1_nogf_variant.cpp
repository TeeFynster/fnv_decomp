
// src/fallout_shared/tesobject_ob1_nogf_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/tesobject.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../include/MemoryManager.h"

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
extern MemoryManager DAT_011f6238;

struct El
{
    std::string s;
    int unk;
    std::vector<unsigned int> v;
    void operator delete(void* p)
    {
        DAT_011f6238.Deallocate(p);
    }
};

namespace std {
template <> class allocator<El>
{
  public:
    typedef El value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    template <class U> struct rebind
    {
        typedef allocator<U> other;
    };
    allocator() throw()
    {}
    allocator(const allocator&) throw()
    {}
    template <class U> allocator(const allocator<U>&) throw()
    {}
    pointer address(reference x) const
    {
        return &x;
    }
    const_pointer address(const_reference x) const
    {
        return &x;
    }
    pointer allocate(size_type n, const void* = 0)
    {
        return _Allocate(n, (pointer)0);
    }
    void deallocate(pointer p, size_type)
    {
        DAT_011f6238.Deallocate(p);
    }
    void construct(pointer p, const El& v)
    {
        _Construct(p, v);
    }
    void destroy(pointer p)
    {
        _Destroy(p);
    }
    size_type max_size() const throw()
    {
        size_type c = (size_type)(-1) / sizeof(El);
        return 0 < c ? c : 1;
    }
};
}

typedef std::vector<El> V;

template <class T> class InsertVector : public std::_Vector_val<T, std::allocator<T> >
{
  public:
    typedef std::vector<T> V;
    typedef unsigned int size_type;
    typedef T* pointer;
    typedef T value_type;
    typedef typename V::const_iterator const_iterator;
    pointer _Myfirst, _Mylast, _Myend;
    static void _Xlen()
    {
        throw std::length_error("vector<T> too long");
    }
    size_type capacity() const
    {
        return _Myfirst == 0 ? 0 : _Myend - _Myfirst;
    }
    size_type size() const
    {
        return _Mylast - _Myfirst;
    }
    size_type max_size() const
    {
        return this->_Alval.max_size();
    }
    void _Destroy(pointer first, pointer last)
    {
        std::_Destroy_range(first, last, this->_Alval);
    }
    template <class Iter> pointer _Umove(Iter first, Iter last, pointer dest)
    {
        return stdext::_Unchecked_uninitialized_move(first, last, dest, this->_Alval);
    }
    pointer _Ufill(pointer dest, size_type count, const T& value)
    {
        stdext::unchecked_uninitialized_fill_n(dest, count, value, this->_Alval);
        return dest + count;
    }
    inline void UpdateState_00abfa90(const_iterator, size_type, const T&);
};

// @fnv 0x00abfa90
// src: GUESS 0x00abfa90 (confidence: low)
template <> void InsertVector<El>::UpdateState_00abfa90(V::const_iterator _Where, V::size_type _Count, const El& _Val)
{
    size_type _Capacity = capacity();
    if (_Count == 0)
        ;
    else if (max_size() - size() < _Count)
        _Xlen();
    else if (_Capacity < size() + _Count)
    {
        _Capacity = max_size() - _Capacity / 2 < _Capacity ? 0 : _Capacity + _Capacity / 2;
        if (_Capacity < size() + _Count)
            _Capacity = size() + _Count;
        pointer _Newvec = this->_Alval.allocate(_Capacity);
        pointer _Ptr = _Newvec;
        _TRY_BEGIN
        _Ptr = _Umove(this->_Myfirst, _VEC_ITER_BASE(_Where), _Newvec);
        _Ptr = _Ufill(_Ptr, _Count, _Val);
        _Umove(_VEC_ITER_BASE(_Where), this->_Mylast, _Ptr);
        _CATCH_ALL
        _Destroy(_Newvec, _Ptr);
        this->_Alval.deallocate(_Newvec, _Capacity);
        _RERAISE;
        _CATCH_END
        _Count += size();
        if (_Myfirst != 0)
        {
            _Destroy(_Myfirst, _Mylast);
            this->_Alval.deallocate(_Myfirst, _Myend - _Myfirst);
        }
        _Myend = _Newvec + _Capacity;
        _Mylast = _Newvec + _Count;
        _Myfirst = _Newvec;
    }
    else if ((size_type)(_Mylast - _VEC_ITER_BASE(_Where)) < _Count)
    {
        value_type _Tmp = _Val;
        _Umove(_VEC_ITER_BASE(_Where), _Mylast, _VEC_ITER_BASE(_Where) + _Count);
        _TRY_BEGIN
        _Ufill(_Mylast, _Count - (_Mylast - _VEC_ITER_BASE(_Where)), _Tmp);
        _CATCH_ALL
        _Destroy(_VEC_ITER_BASE(_Where) + _Count, _Mylast + _Count);
        _RERAISE;
        _CATCH_END
        _Mylast += _Count;
        std::fill(_VEC_ITER_BASE(_Where), _Mylast - _Count, _Tmp);
    }
    else
    {
        value_type _Tmp = _Val;
        pointer _Oldend = _Mylast;
        _Mylast = _Umove(_Oldend - _Count, _Oldend, _Mylast);
        _STDEXT _Unchecked_move_backward(_VEC_ITER_BASE(_Where), _Oldend - _Count, _Oldend);
        std::fill(_VEC_ITER_BASE(_Where), _VEC_ITER_BASE(_Where) + _Count, _Tmp);
    }
}

void emit_insert(InsertVector<El>* p, V::const_iterator w, V::size_type n, const El& x)
{
    p->UpdateState_00abfa90(w, n, x);
}
