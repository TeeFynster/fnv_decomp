
// src/havok/common/base/system/io/ostream/hkostream_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/system/io/ostream/hkostream.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkOstream.h"
#include "../../../../../../../include/hkStreamWriter.h"

// Unused declarations copied from the other hkOstream flag variants are omitted.
#include <stdarg.h>
extern "C" void __cdecl hkString_vsnprintf(char* buffer, unsigned int size, const char* fmt, char* args);
extern "C" int __cdecl hkString_strLen(int value);
extern "C" const char str_010c9308[];

class hkWriter0080
{
  public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void write(const char* data, int len);
};

// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(hkWriter0080* out, const char* str)
{
    if (str)
    {
        out->write(str, hkString_strLen((int)str));
    }
    else
    {
        out->write(str_010c9308, 6);
    }
}

// @fnv 0x00cc0410
// src: HAVOK_LIB 0x00cc0410
void __cdecl hkOstream_printf(hkOstream* self, const char* fmt, ...)
{
    char buf[0x2728];
    va_list ap;
    va_start(ap, fmt);
    hkString_vsnprintf(buf, 0x2728, fmt, ap);
    va_end(ap);
    writeString((hkWriter0080*)self->m_pStreamWriter, buf);
}
