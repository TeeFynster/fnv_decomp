// Original runtime adapter; excluded from the reference recipe.
// Compile-only until the independent startup/provider gates are satisfied.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#if !defined(_M_IX86) || !defined(_MSC_VER) || _MSC_VER != 1500
#error This startup adapter requires the reviewed x86 VC9 compiler.
#endif

typedef char fnv_pointer_width_must_be_32[(sizeof(void*) == 4) ? 1 : -1];
typedef char fnv_uint_width_must_be_32[(sizeof(unsigned int) == 4) ? 1 : -1];
typedef char fnv_int_width_must_be_32[(sizeof(int) == 4) ? 1 : -1];

// This typed reference deliberately has stdcall decoration. A later reviewed
// COFF identity-only transform must bind it to the selected physical provider.
// No alias directive or cdecl declaration is used to disguise that boundary.
extern "C" int __stdcall fnv_game_application_entry(
    unsigned int instance, unsigned int previous_instance,
    unsigned int command_tail, unsigned int show_state);

extern "C" int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous_instance,
                             LPSTR command_tail, int show_state)
{
    return fnv_game_application_entry(
        reinterpret_cast<unsigned int>(instance),
        reinterpret_cast<unsigned int>(previous_instance),
        reinterpret_cast<unsigned int>(command_tail),
        static_cast<unsigned int>(show_state));
}
