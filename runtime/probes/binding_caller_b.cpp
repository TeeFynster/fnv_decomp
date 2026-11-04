#include "binding_fixture.hpp"
extern "C" int binding_call_b(int x) { return binding_shared(x) + binding_data; }
extern "C" int* binding_address_b() { return &binding_data; }
