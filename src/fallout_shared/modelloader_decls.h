#ifndef MODELLOADER_DECLS_H
#define MODELLOADER_DECLS_H

namespace std {
template <class T> struct char_traits;
template <class T> class allocator;
template <class T, class Traits, class Alloc> class basic_string
{
  public:
    unsigned char layout[24];
    unsigned int capacity;
    basic_string& assign(const T*, unsigned int);
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
    bool _Inside(const T*);
    bool _Grow(unsigned int, bool);
    T* _Myptr();
    void _Eos(unsigned int);
};
}
void std_Traits_helper_copy_s_std_char_traits_char(char*, unsigned int, const char*, unsigned int);
#endif
