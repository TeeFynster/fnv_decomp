// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct __declspec(align(16)) FUN_00d72030_cls
{
    char m_c00;
    int m_i04;
    float m_f08;
    int unk0c;
    __m128 m_k10;
    __m128 m_k20;
    __m128 m_k30;
    __m128 m_k40;
    __m128 m_k50;
    __m128 m_k60;
    __m128 m_k70;

    FUN_00d72030_cls* InitializeFields_00d72030(const FUN_00d72030_cls* apSrc);
};

// Copies all fields from apSrc into this object and returns this.
// @fnv 0x00d72030
// src: GUESS 0x00d72030 (confidence: low)
FUN_00d72030_cls* FUN_00d72030_cls::InitializeFields_00d72030(const FUN_00d72030_cls* apSrc)
{
    m_c00 = apSrc->m_c00;
    m_i04 = apSrc->m_i04;
    m_f08 = apSrc->m_f08;
    m_k10 = apSrc->m_k10;
    m_k20 = apSrc->m_k20;
    m_k30 = apSrc->m_k30;
    m_k40 = apSrc->m_k40;
    m_k50 = apSrc->m_k50;
    m_k60 = apSrc->m_k60;
    m_k70 = apSrc->m_k70;
    return this;
}
