#include "binding_fixture.hpp"
#include <stdio.h>
int main() {
    if (binding_address_a() == binding_address_b()) return 1;
    if (*binding_address_a() != 17 || *binding_address_b() != 29) return 2;
    for (int x = -32; x <= 32; ++x) {
        if (binding_call_a(x) != x * 3 + 22) return 3;
        if (binding_call_b(x) != x * 7 + 20) return 4;
    }
    *binding_address_a() = 37;
    if (*binding_address_b() != 29 || binding_call_a(4) != 54) return 5;
    printf("{\"schema\":1,\"calls\":131,\"distinct_data\":true,\"writable_isolated\":true}\n");
    return 0;
}
