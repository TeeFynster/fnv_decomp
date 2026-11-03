#include "binding_fixture.hpp"
extern "C" int binding_call_a(int x) { return binding_shared(x) + binding_data; }
extern "C" int* binding_address_a() { return &binding_data; }
