// speedtree/libspline_source/idvspline_decls.h: declares IdvSplineToken, IdvSplineInputCursor
#ifndef IDVSPLINE_DECLS_H
#define IDVSPLINE_DECLS_H

#include <stddef.h>
#define FNV_STATIC_ASSERT_JOIN_(a, b) a##b
#define FNV_STATIC_ASSERT_JOIN(a, b) FNV_STATIC_ASSERT_JOIN_(a, b)
#define FNV_STATIC_ASSERT(c) typedef char FNV_STATIC_ASSERT_JOIN(idvspline_assert_, __LINE__)[(c) ? 1 : -1]
#include "../../../include/ExpressionEvaluator.h"
#include "../../../include/Script.h"

struct IdvSplineToken
{
    ExpressionOperator type;
    char* text;
};
struct IdvSplineInputCursor
{
    int consumed;
    const char* data;
};
int IsIntegerString(const char*);
int IsAFloat(const char*);
int Warning(const char*, ...);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" long __cdecl atol(const char*);
extern "C" double __cdecl atof(const char*);
#endif
