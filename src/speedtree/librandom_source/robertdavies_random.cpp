// speedtree/librandom_source/robertdavies_random.cpp: Random, PosGen, Normal (30 functions)

#include "../../../include/Random.h"
#include "../../../include/Normal.h"
#include "../../../include/PosGen.h"
#include "../../../include/SymGen.h"
#include <stdexcept>

extern "C" double __cdecl fabs(double);
extern "C" double __cdecl exp(double);
extern double RandomSeed;
extern "C" int randomInitCount;
extern "C" float randomXi;
extern "C" float* randomSx;
extern "C" float* randomSfx;
extern "C" float randomSamples[128];

// @fnv 0x00b43630
PosGen::PosGen()
{
    NotReady = true;
    xi = 0.0f;
    sx = 0;
    m_pYValues = 0;
}

// Returns the standard normal density of value, or 0 when |value| exceeds 8.
// @fnv 0x00b43ce0
float Normal::Density(volatile float value) const
{
    return (float)fabs(value) > 8.0 ? 0.0 : 0.398942280 * (float)exp((float)((double)value * -value / 2.0));
}

// @fnv 0x00b43310
float Random::Raw()
{
    long lo, hi, iseed;
    iseed = (long)RandomSeed;
    hi = iseed / 127773L;
    lo = iseed - hi * 127773L;
    iseed = 16807 * lo - 2836 * hi;
    if (iseed <= 0)
        iseed += 2147483647L;
    RandomSeed = (double)iseed;
    return (float)RandomSeed * 4.656612875e-10;
}

// @fnv 0x00b43ae0
Normal::Normal()
{
    if (randomInitCount != 0)
    {
        NotReady = false;
        xi = randomXi;
        sx = randomSx;
        m_pYValues = randomSfx;
    }
    else
    {
        Build(true);
        randomXi = xi;
        randomSx = sx;
        randomSfx = m_pYValues;
    }
    ++randomInitCount;
}

// Validates that value is in (0,1), stores it scaled by 2147483648 into RandomSeed, then refills 128 randomSamples via Raw().
// @fnv 0x00b43510
void Random::Set(double adSeed)
{
    if (adSeed >= 1.0 || adSeed <= 0.0)
        throw std::logic_error("Newran: seed out of range");
    RandomSeed = (long)(adSeed * 2147483648L);
    for (int i = 0; i < 128; i++)
        randomSamples[i] = Raw();
}

extern const double runtimeInitializationDouble2;

// @fnv 0x00b43710
void PosGen::Build(bool symmetric)
{
    int count;
    float a, x, f;  // x is the sampling area increment; a is the coordinate.
    NotReady = false;
    sx = new float[60];
    m_pYValues = new float[60];
    a = 0.0f;
    x = symmetric ? 0.01f : 0.02f;
    for (count = 0; count < 60; count++)
    {
        sx[count] = a;
        f = Density(a);
        m_pYValues[count] = f;
        if (f <= 0.0)
            goto complete;
        a = x / f + a;
    }
    throw std::runtime_error("Newran: area too large");
complete:
    if (count < 50)
        throw std::runtime_error("Newran: area too small");
    xi = symmetric ? count * runtimeInitializationDouble2 : count;
}

// @fnv 0x00b43390
float Random::Density(float) const
{
    return 0.0f;
}

// Stores value as RandomSeed, then fills randomSamples with 128 values from Random::Raw().
// @fnv 0x00b435f0
void Random::SetLong(long alSeed)
{
    int i;
    RandomSeed = (double)alSeed;
    for (i = 0; i < 128; ++i)
    {
        randomSamples[i] = Random::Raw();
    }
}

// Sets the first float and the following int of the given buffer to zero and returns the buffer.
// @fnv 0x00b43bc0
FloatIntPair* Normal::vf04(FloatIntPair* afBuffer)
{
    *reinterpret_cast<int*>(reinterpret_cast<float*>(afBuffer) + 1) = 0;
    *reinterpret_cast<float*>(afBuffer) = 0.0f;
    return afBuffer;
}

extern "C" void __cdecl Deallocate(void*);

// Stores 0 in the int at p+1 and 1.0f at p[0], then returns p.
// @fnv 0x00b43bf0
FloatIntPair* Normal::vf05(FloatIntPair* p)
{
    *(int*)(reinterpret_cast<float*>(p) + 1) = 0;
    reinterpret_cast<float*>(p)[0] = 1.0f;
    return p;
}

struct Dummy44a3a0
{
    void __thiscall SetVtableAndProcessState_0044a3d0();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_0044a3d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0044a3a0
void* __thiscall Dummy44a3a0::DestroyIfFlagged(unsigned int flags)
{
    this->SetVtableAndProcessState_0044a3d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void __cdecl DoNothing(int);

// Throws if RandomSeed is zero, picks an index from Random::Raw()*128, refills that sample slot with a new raw value and returns the old sample.
// @fnv 0x00b433a0
float Random::Next()
{
    if (RandomSeed == 0.0)
        throw std::logic_error("Random number generator not initialised");
    int i = (int)(Random::Raw() * 128.0);
    DoNothing(i);
    DoNothing(i);
    float f = randomSamples[i];
    randomSamples[i] = Random::Raw();
    return f;
}

// Throws a std::logic_error with the message "Newran: illegal combination".
// @fnv 0x00b43490
void Random::vf08(int a, int b, int c)
{
    throw std::logic_error("Newran: illegal combination");
}

class FloatIntPair
{
public:
    float f;
    int i;
};
// Sets p->i to 4 and p->f to 0.0f, then returns p.
// @fnv 0x00b43680
FloatIntPair* PosGen::vf04(FloatIntPair* pValue)
{
    int v = 4;
    pValue->i = v;
    pValue->f = 0.0f;
    return pValue;
}

// Apply after constructor definitions: construction needs SymGen's vtable,
// but teardown delegates to PosGen without installing it again.
class __declspec(novtable) SymGen;

// @fnv 0x00b43c50
inline SymGen::~SymGen()
{}

inline Random::~Random()
{}
// @fnv 0x00b436b0
PosGen::~PosGen()
{
    if (!NotReady)
    {
        float* bufferA = sx;
        Deallocate(bufferA);
        float* bufferB = m_pYValues;
        Deallocate(bufferB);
    }
}

// @fnv 0x00b43910
float PosGen::Next()
{
    int idx3;
    float zTmp;
    float y3;
    float r;
    float lo5;

    if (NotReady)
    {
        Build(false);
    }
    do
    {
        r = Random::Next();
        idx3 = (int)(r * xi);
        lo5 = sx[idx3];
        y3 = (float)((double)(sx[idx3 + 1] - lo5) * Random::Next() + lo5);
        zTmp = m_pYValues[idx3] * Random::Next();
    } while (zTmp >= m_pYValues[idx3 + 1] && zTmp >= Density(y3));
    return y3;
}

// @fnv 0x00b439e0
float SymGen::Next()
{
    int idx3;
    float zTmp;
    float aA;
    float y3;
    float fSample;

    if (NotReady)
    {
        Build(true);
    }
    do
    {
        aA = 1.0f;
        fSample = Random::Next();
        if (fSample > 0.5)
        {
            aA = -1.0f;
            fSample = 1.0f - fSample;
        }
        idx3 = (int)(fSample * xi);
        float fLow = sx[idx3];
        y3 = (float)((double)(sx[idx3 + 1] - fLow) * Random::Next() + fLow);
        zTmp = m_pYValues[idx3] * Random::Next();
    } while (zTmp >= m_pYValues[idx3 + 1] && zTmp >= Density(y3));
    return aA * y3;
}

// Retains the shared sampling buffers while another Normal instance remains.
// @fnv 0x00b43ca0
Normal::~Normal()
{
    if (--randomInitCount != 0)
    {
        NotReady = true;
    }
}

// Stand-in for the 8-byte element type copied by FUN_00b42f40 (float + int).
struct S_00b42f40_Er
{
    float f;
    int i;
};

// Copies n elements from src into the array at p, rethrowing on exception after walking local up to p.
// @fnv 0x00b42f40
// src: GUESS 0x00b42f40 (confidence: medium)
void __cdecl Object_CopyElementRange_00b42f40(S_00b42f40_Er* pDest, unsigned int n, S_00b42f40_Er* pSource)
{
    S_00b42f40_Er* pStart = pDest;
    try
    {
        for (; n > 0; n--, pDest++)
        {
            S_00b42f40_Er* dst = pDest;
            S_00b42f40_Er* cur = dst;
            S_00b42f40_Er* pResult;
            if (cur != 0)
            {
                *cur = *pSource;
                pResult = cur;
            }
            else
            {
                pResult = 0;
            }
        }
    }
    catch (...)
    {
        for (; pStart != pDest; pStart++)
        {
        }
        throw;
    }
}

struct Elem8
{
    int lo;
    int hi;
};
struct Alloc8
{
    int unused;
};

struct TagUnchangedBase
{
};
struct TagRangeChecked
{
};
struct TagNonscalar
{
};
struct TagUndefinedMove
{
};

Elem8* __cdecl RobertdaviesRandom_ProcessEntries_00b43230(Elem8* _First, Elem8* _Last, Elem8* _Dest, Alloc8& _Al, TagNonscalar _Tag0,
                            TagRangeChecked _Tag1);

inline TagUndefinedMove MoveCat(Elem8* const& _Iter)
{
    TagUndefinedMove _Cat;
    return _Cat;
}

inline TagNonscalar PtrCat(Elem8*& _T1, Elem8*& _T2)
{
    TagNonscalar _Cat;
    return _Cat;
}

inline Elem8* CheckedBase(Elem8*& _It, TagUnchangedBase)
{
    return _It;
}

inline Elem8* CheckedBase(Elem8*& _It)
{
    TagUnchangedBase _Base_tag;
    return CheckedBase(_It, _Base_tag);
}

inline Elem8* unchecked_uninitialized_copy(Elem8* _First, Elem8* _Last, Elem8* _Dest, Alloc8& _Al)
{
    return RobertdaviesRandom_ProcessEntries_00b43230(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, PtrCat(_First, _Dest), TagRangeChecked());
}

template <class _MoveCatTy>
inline Elem8* UninitMove(Elem8* _First, Elem8* _Last, Elem8* _Dest, Alloc8& _Al, _MoveCatTy, TagRangeChecked)
{
    return unchecked_uninitialized_copy(_First, _Last, _Dest, _Al);
}

// @fnv 0x00b43010
// src: GUESS 0x00b43010 (confidence: medium)
Elem8* __cdecl RobertdaviesRandom_MoveRangeToUninitializedStorage(Elem8* _First, Elem8* _Last, Elem8* _Dest, Alloc8& _Al)
{
    return UninitMove(CheckedBase(_First), CheckedBase(_Last), _Dest, _Al, MoveCat(_Dest), TagRangeChecked());
}

struct B43Cont;

struct B43Aux
{
    const B43Cont* _Mycontainer;
    const B43Cont* _Getcont() const
    {
        return _Mycontainer;
    }
};

struct B43Cont
{
    B43Aux* _Myownedaux;
};

struct B43IterBase
{
    const B43Aux* _Myaux;
    void _Set_container(const B43Cont* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const B43Cont* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
};

struct B43UVecIt : B43IterBase
{
    unsigned int* _Myptr;
    B43UVecIt(unsigned int* _Ptr, const B43Cont* _Pvector);
};

struct B43UVec : B43Cont
{
    char _Alaux;
    char _Alval;
    unsigned int* _Myfirst;
    unsigned int* _Mylast;
    unsigned int* _Myend;
    B43UVecIt begin()
    {
        return (B43UVecIt(_Myfirst, this));
    }
};

inline B43UVecIt::B43UVecIt(unsigned int* _Ptr, const B43Cont* _Pvector)
{
    _SCL_SECURE_VALIDATE(_Pvector != NULL && ((B43UVec*)_Pvector)->_Myfirst <= _Ptr &&
                         _Ptr <= ((B43UVec*)_Pvector)->_Mylast);
    this->_Set_container(_Pvector);
    _Myptr = _Ptr;
}

struct B43BVec : B43Cont
{
    char _Alaux;
    unsigned int _Mysize;
    B43UVec _Myvec;
};

struct B43VbIterBase : B43IterBase
{
    unsigned int* _Myptr;
    unsigned int _Myoff;
};

struct B43VbConstIt : B43VbIterBase
{
    unsigned int* _My_cont_begin() const
    {
        return ((((B43BVec*)this->_Getmycont())->_Myvec.begin())._Myptr);
    }
    unsigned int _My_actual_offset() const
    {
        unsigned int _Off = this->_Myoff;
        _Off += 32 * (this->_Myptr - _My_cont_begin());
        return (_Off);
    }
    void Increment();
};

// Advances the bit-vector const iterator: increments _Myoff, or resets it to 0 and advances _Myptr when the word is exhausted.
// @fnv 0x00b43120
void B43VbConstIt::Increment()
{
    _SCL_SECURE_VALIDATE(this->_Has_container() && this->_Myptr != NULL);
    _SCL_SECURE_VALIDATE_RANGE((this->_My_actual_offset() + 1) <= ((B43BVec*)this->_Getmycont())->_Mysize);
    if (this->_Myoff < 32 - 1)
        ++this->_Myoff;
    else
        this->_Myoff = 0, ++this->_Myptr;
}

struct CopyElement
{
    unsigned int first;
    unsigned int second;
};

CopyElement* __cdecl RobertdaviesRandom_ProcessEntries_00b43230(CopyElement* first, CopyElement* last, CopyElement* destination,
                                  std::allocator<CopyElement>& allocator, std::_Nonscalar_ptr_iterator_tag,
                                  std::_Range_checked_iterator_tag);

// @fnv 0x00b431e0
// src: GUESS 0x00b431e0 (confidence: low)
CopyElement* __cdecl Object_ProcessAndReturnValue_00b431e0(CopyElement* _First, CopyElement* _Last, CopyElement* _Dest,
                                  std::allocator<CopyElement>& _Al)
{
    return RobertdaviesRandom_ProcessEntries_00b43230(std::_Checked_base(_First), std::_Checked_base(_Last), _Dest, _Al, std::_Ptr_cat(_First, _Dest),
                        std::_Range_checked_iterator_tag());
}

struct SpawnedPair
{
    int m_i00;
    int m_i04;
};

inline void Construct(SpawnedPair* p, const SpawnedPair& v)
{
    void* vptr = p;
    ::new (vptr) SpawnedPair(v);
}

inline void Destroy(SpawnedPair* p)
{
    (void)p;
}

// @fnv 0x00b43230
// src: GUESS 0x00b43230 (confidence: low)
SpawnedPair* __cdecl RobertdaviesRandom_ProcessEntries_00b43230(const SpawnedPair* apSource, const SpawnedPair* apSourceEnd, SpawnedPair* apDest)
{
    SpawnedPair* pConstructed = apDest;
    try
    {
        for (; apSource != apSourceEnd; ++apDest, ++apSource)
            Construct(&*apDest, *apSource);
    }
    catch (...)
    {
        for (; pConstructed != apDest; ++pConstructed)
            Destroy(pConstructed);
        throw;
    }
    return apDest;
}

// @fnv 0x00b43480
// src: COMMUNITY 0x00b43480
extern "C" void __cdecl DoNothing(int)
{}

struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
// Forwards the range [_First, _Last) and _Dest to _Copy_optS with a range-checked tag and returns its result.
// @fnv 0x00b42e50
// src: COMMUNITY 0x00b42e50
int* __cdecl std__Move(int* _First, int* _Last, int* _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}

namespace fnv_00b43090 {
struct input_iterator_tagS
{
};
struct output_iterator_tagS
{
};
struct forward_iterator_tagS : public input_iterator_tagS
{
};
struct bidirectional_iterator_tagS : public forward_iterator_tagS
{
};
struct random_access_iterator_tagS : public bidirectional_iterator_tagS
{
};
struct _Range_checked_iterator_tagS
{
};
struct _Unchanged_checked_iterator_base_type_tagS
{
};
struct _Nonscalar_ptr_iterator_tagS
{
};
struct _Scalar_ptr_iterator_tagS
{
};
template <class _Iter> struct iterator_traitsS
{
    typedef typename _Iter::iterator_category iterator_category;
};
template <class _Iter> struct _Iter_valueS
{
    typedef typename _Iter::value_type value_type;
};
template <class _Ty> struct _Iter_valueS<_Ty*>
{
    typedef _Ty value_type;
};
template <class _Ty> struct iterator_traitsS<_Ty*>
{
    typedef random_access_iterator_tagS iterator_category;
};
template <class _Cat1, class _Cat2> struct _Iter_random_helperS
{
    typedef forward_iterator_tagS _Iter_random_cat;
};
template <> struct _Iter_random_helperS<random_access_iterator_tagS, random_access_iterator_tagS>
{
    typedef random_access_iterator_tagS _Iter_random_cat;
};
template <class _Iter1, class _Iter2>
inline typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                     typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat
_Iter_randomS(const _Iter1&, const _Iter2&)
{
    typename _Iter_random_helperS<typename iterator_traitsS<_Iter1>::iterator_category,
                                  typename iterator_traitsS<_Iter2>::iterator_category>::_Iter_random_cat _Cat;
    return (_Cat);
}
template <class _T1, class _T2> struct _Ptr_cat_helperS
{
    typedef _Nonscalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _Ty> struct _Ptr_cat_helperS<_Ty**, _Ty**>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<int*, int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned int*, unsigned int*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<short*, short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned short*, unsigned short*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<char*, char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<unsigned char*, unsigned char*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<float*, float*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <> struct _Ptr_cat_helperS<bool*, bool*>
{
    typedef _Scalar_ptr_iterator_tagS _Ptr_cat;
};
template <class _T1, class _T2> inline typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Ptr_catS(_T1&, _T2&)
{
    typename _Ptr_cat_helperS<_T1, _T2>::_Ptr_cat _Cat;
    return (_Cat);
}
template <class _Iter> struct _Checked_iterator_base_helperS
{
    typedef _Unchanged_checked_iterator_base_type_tagS _Checked_iterator_base_type_tag;
    typedef _Iter _Checked_iterator_base_type;
};
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(
    _Iter& _It, _Unchanged_checked_iterator_base_type_tagS)
{
    return _It;
}
template <class _Iter>
inline typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type _Checked_baseS(_Iter& _It)
{
    typename _Checked_iterator_base_helperS<_Iter>::_Checked_iterator_base_type_tag _Base_tag;
    return _Checked_baseS(_It, _Base_tag);
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Nonscalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    for (; _First != _Last; ++_Dest, ++_First)
        *_Dest = *_First;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                         _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest + (_Last - _First);
    _Copy_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
               _Range_checked_iterator_tagS());
    return _Result;
}
extern "C" int __cdecl memmove_s(void* _Dst, unsigned int _DstSize, const void* _Src, unsigned int _MaxCount);
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                         _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest + _Off;
    if (_Off > 0)
        memmove_s(&*_Dest, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _BidIt1, class _BidIt2, class _InOutItCat>
inline _BidIt2 _Copy_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat,
                                   _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    while (_First != _Last)
        *--_Dest = *--_Last;
    return (_Dest);
}
template <class _InIt, class _OutIt>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, random_access_iterator_tagS,
                                  _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    _OutIt _Result = _Dest - (_Last - _First);
    _Copy_backward_optS(_First, _Last, _Checked_baseS(_Dest), forward_iterator_tagS(), _Nonscalar_ptr_iterator_tagS(),
                        _Range_checked_iterator_tagS());
    return _Result;
}
template <class _InIt, class _OutIt, class _InOutItCat>
inline _OutIt _Copy_backward_optS(_InIt _First, _InIt _Last, _OutIt _Dest, _InOutItCat, _Scalar_ptr_iterator_tagS,
                                  _Range_checked_iterator_tagS)
{
    int _Off = _Last - _First;
    _OutIt _Result = _Dest - _Off;
    if (_Off > 0)
        memmove_s(&*_Result, _Off * sizeof(*_First), &*_First, _Off * sizeof(*_First));
    return _Result;
}
template <class _Iter> inline typename iterator_traitsS<_Iter>::iterator_category _Iter_catS(const _Iter&)
{
    typename iterator_traitsS<_Iter>::iterator_category _Cat;
    return (_Cat);
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _Range_checked_iterator_tagS)
{
    for (; 0 < _Count; --_Count, ++_First)
        *_First = _Val;
}
template <class _OutIt, class _Diff, class _Ty, class _OutCat>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, _OutCat, _Range_checked_iterator_tagS)
{
    _Fill_nS(_First, _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void _Fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val, random_access_iterator_tagS,
                     _Range_checked_iterator_tagS)
{
    _OutIt _Last = _First + _Count;
    (_Last);
    _Fill_nS(_Checked_baseS(_First), _Count, _Val, _Range_checked_iterator_tagS());
}
template <class _OutIt, class _Diff, class _Ty>
inline void unchecked_fill_nS(_OutIt _First, _Diff _Count, const _Ty& _Val)
{
    _Fill_nS(_First, _Count, _Val, _Iter_catS(_First), _Range_checked_iterator_tagS());
}
void __cdecl InvalidParameterNoInfoS();
struct _Iterator_base_universalS
{
};
class _Container_base_auxS;
class _Aux_contS
{
  public:
    const _Container_base_auxS* _Getcont() const
    {
        return _Mycontainer;
    }
    const _Container_base_auxS* _Mycontainer;
};
class _Container_base_auxS
{
  public:
    _Aux_contS* _Myownedaux;
};
template <class _Ty> class allocatorS
{
  public:
    typedef _Ty* pointer;
    void destroy(pointer _Ptr)
    {
        _DestroyS(_Ptr);
    }
};
template <class _Ty> inline void _DestroyS(_Ty* _Ptr)
{
    (_Ptr)->~_Ty();
}
template <class _Alloc> class _Container_base_aux_alloc_realS : public _Container_base_auxS
{
  public:
    _Alloc _Alaux;
};
class _Iterator_base_auxS : public _Iterator_base_universalS
{
  public:
    _Iterator_base_auxS() : _Myaux(0)
    {}
    void _Set_container(const _Container_base_auxS* const _Pcont)
    {
        _Myaux = _Pcont->_Myownedaux;
    }
    const _Container_base_auxS* _Getmycont() const
    {
        return _Myaux ? _Myaux->_Getcont() : 0;
    }
    bool _Same_container(const _Iterator_base_auxS& _Other) const
    {
        return _Myaux == _Other._Myaux;
    }
    bool _Has_container() const
    {
        return _Myaux != 0;
    }
    const _Aux_contS* _Myaux;
};
template <class _Ty> class _RanitS : public _Iterator_base_auxS
{
};
template <class _Ty> class vectorS;
template <class _Ty> class _Vector_const_iteratorS : public _RanitS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Myt;
    typedef vectorS<_Ty> _Myvec;
    typedef _Ty* _Tptr;
    _Vector_const_iteratorS(_Tptr _Ptr, const _Container_base_auxS* _Pvector)
    {
        if (!(_Pvector != 0 && ((_Myvec*)_Pvector)->_Myfirst <= _Ptr && _Ptr <= ((_Myvec*)_Pvector)->_Mylast))
            InvalidParameterNoInfoS();
        this->_Set_container(_Pvector);
        _Myptr = _Ptr;
    }
    _Ty& operator*() const
    {
        if (!(this->_Has_container()))
            InvalidParameterNoInfoS();
        if (!(_Myptr < ((_Myvec*)(this->_Getmycont()))->_Mylast))
            InvalidParameterNoInfoS();
        return (*_Myptr);
    }
    bool operator==(const _Myt& _Right) const
    {
        if (!(this->_Has_container() && this->_Same_container(_Right)))
            InvalidParameterNoInfoS();
        return (_Myptr == _Right._Myptr);
    }
    bool operator!=(const _Myt& _Right) const
    {
        return (!(*this == _Right));
    }
    _Tptr _Myptr;
};
template <class _Ty> class _Vector_iteratorS : public _Vector_const_iteratorS<_Ty>
{
  public:
    typedef _Vector_const_iteratorS<_Ty> _Mybase;
    _Vector_iteratorS(_Ty* _Ptr, const _Container_base_auxS* _Pvector) : _Mybase(_Ptr, _Pvector)
    {}
};
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al)
{
    _Destroy_rangeS(_First, _Last, _Al, _Ptr_catS(_First, _Last));
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Nonscalar_ptr_iterator_tagS)
{
    for (; _First != _Last; ++_First)
        _Al.destroy(_First);
}
template <class _Alloc>
inline void _Destroy_rangeS(typename _Alloc::pointer _First, typename _Alloc::pointer _Last, _Alloc& _Al,
                            _Scalar_ptr_iterator_tagS)
{}
template <class _InIt, class _OutIt> inline _OutIt unchecked_copyS(_InIt _First, _InIt _Last, _OutIt _Dest)
{
    return (_Copy_optS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Iter_randomS(_First, _Dest),
                       _Ptr_catS(_First, _Dest), _Range_checked_iterator_tagS()));
}
template <class _Ty> class _Vector_valS : public _Container_base_aux_alloc_realS<allocatorS<_Ty> >
{
  public:
    allocatorS<_Ty> _Alval;
};
template <class _Ty> class vectorS : public _Vector_valS<_Ty>
{
  public:
    typedef _Vector_iteratorS<_Ty> iterator;
    typedef _Vector_const_iteratorS<_Ty> const_iterator;
    typedef _Ty* pointer;
    typedef unsigned int size_type;
    typedef _Ty& reference;
    size_type size() const
    {
        return (_Mylast - _Myfirst);
    }
    bool empty() const
    {
        return (size() == 0);
    }
    reference operator[](size_type _Pos)
    {
        if (!(_Pos < size()))
            InvalidParameterNoInfoS();
        return (*(_Myfirst + _Pos));
    }
    iterator begin()
    {
        return (iterator(_Myfirst, this));
    }
    iterator end()
    {
        return (iterator(_Mylast, this));
    }
    iterator _Make_iter(const_iterator _Where) const
    {
        return (iterator(_Where._Myptr, this));
    }
    iterator erase(const_iterator _Where)
    {
        unchecked_copyS(_Where._Myptr + 1, _Mylast, _Where._Myptr);
        _Destroy(_Mylast - 1, _Mylast);
        --_Mylast;
        return (_Make_iter(_Where));
    }
    iterator erase(const_iterator _First_arg, const_iterator _Last_arg)
    {
        iterator _First = _Make_iter(_First_arg);
        iterator _Last = _Make_iter(_Last_arg);
        if (_First != _Last)
        {
            pointer _Ptr = unchecked_copyS(_Last._Myptr, _Mylast, _First._Myptr);
            _Destroy(_Ptr, _Mylast);
            _Mylast = _Ptr;
        }
        return (_First);
    }
    void clear()
    {
        erase(begin(), end());
    }
    void _Destroy(pointer _First, pointer _Last)
    {
        _Destroy_rangeS(_First, _Last, this->_Alval);
    }
    pointer _Myfirst;
    pointer _Mylast;
    pointer _Myend;
};
template <class _InIt, class _FwdIt, class _Alloc>
_FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Al, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
struct _Undefined_move_tagS
{
};
template <class _Ty> struct _Move_operation_categoryS
{
    typedef _Undefined_move_tagS _Move_cat;
};
template <class _Iter>
inline typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Move_catS(const _Iter&)
{
    typename _Move_operation_categoryS<typename _Iter_valueS<_Iter>::value_type>::_Move_cat _Cat;
    return (_Cat);
}
template <class _InIt, class _FwdIt, class _Alloc, class _MoveCatTy>
inline _FwdIt _Uninit_moveS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc& _Al, _MoveCatTy,
                            _Range_checked_iterator_tagS)
{
    return (unchecked_uninitialized_copyS(_First, _Last, _Dest, _Al));
}
template <class _Ty1, class _Ty2>
_Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Nonscalar_ptr_iterator_tagS, _Range_checked_iterator_tagS);
template <class _Ty1, class _Ty2>
inline _Ty2 _Uninit_copyS(_Ty1 _First, _Ty1 _Last, _Ty2 _Dest, _Scalar_ptr_iterator_tagS, _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _Ty2 _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt, class _Alloc>
inline _FwdIt _Uninit_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unsigned int _Count = (unsigned int)(_Last - _First);
    _FwdIt _Result = _Dest + _Count;
    if (_Count > 0)
        memmove_s(&*_Dest, _Count * sizeof(*_First), &*_First, _Count * sizeof(*_First));
    return (_Result);
}
template <class _InIt, class _FwdIt>
inline _FwdIt unchecked_uninitialized_copyS(_InIt _First, _InIt _Last, _FwdIt _Dest)
{
    return (_Uninit_copyS(_Checked_baseS(_First), _Checked_baseS(_Last), _Dest, _Ptr_catS(_First, _Dest),
                          _Range_checked_iterator_tagS()));
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al, _Nonscalar_ptr_iterator_tagS,
                     _Range_checked_iterator_tagS);
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void _Uninit_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc&, _Scalar_ptr_iterator_tagS,
                            _Range_checked_iterator_tagS)
{
    unchecked_fill_nS(_First, _Count, _Val);
}
template <class _FwdIt, class _Diff, class _Tval, class _Alloc>
inline void unchecked_uninitialized_fill_nS(_FwdIt _First, _Diff _Count, const _Tval& _Val, _Alloc& _Al)
{
    _Uninit_fill_nS(_First, _Count, _Val, _Al, _Ptr_catS(_First, _First), _Range_checked_iterator_tagS());
}
template <class _BidIt1, class _BidIt2, class _InOutItCat, class _MoveCatTy>
inline _BidIt2 _Move_backward_optS(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest, _InOutItCat _First_dest_cat,
                                   _MoveCatTy, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
struct E3090
{
    int unk00;
    int unk04;
};
// Forwards the range, destination and iterator category to _Copy_backward_optS and returns its result.
// @fnv 0x00b43090
E3090* __cdecl MoveBackwardOpt(E3090* _First, E3090* _Last, E3090* _Dest, random_access_iterator_tagS _First_dest_cat,
                               _Undefined_move_tagS, _Range_checked_iterator_tagS)
{
    return _Copy_backward_optS(_First, _Last, _Dest, _First_dest_cat, _Ptr_catS(_First, _Dest),
                               _Range_checked_iterator_tagS());
}
}  // namespace fnv_00b43090

struct S_00b42ed0_Iter;
struct S_00b42ed0_Ref
{
    int unk00;
    int unk04;
    int unk08;
    S_00b42ed0_Ref(const S_00b42ed0_Iter& it);
    S_00b42ed0_Ref& operator=(bool v);
};

struct S_00b42ed0_Iter
{
    int unk00;
    int unk04;
    int unk08;
    void Increment();
    bool operator==(const S_00b42ed0_Iter& r) const
    {
        return unk04 == r.unk04 && unk08 == r.unk08;
    }
    bool operator!=(const S_00b42ed0_Iter& r) const
    {
        return !(*this == r);
    }
    S_00b42ed0_Ref operator*() const
    {
        return S_00b42ed0_Ref(*this);
    }
};

inline void S_00b42ed0_Pad()
{
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
}

// Assigns val through first for each position, advancing first until it equals last.
// @fnv 0x00b42ed0
// src: GUESS 0x00b42ed0 (confidence: medium)
void __cdecl RobertdaviesRandom_FillIteratorRange(S_00b42ed0_Iter first, S_00b42ed0_Iter last, const bool& val)
{
    for (; first != last; first.Increment())
    {
        *first = val;
        S_00b42ed0_Pad();
    }
}
