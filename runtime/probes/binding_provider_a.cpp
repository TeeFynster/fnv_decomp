#include "binding_fixture.hpp"
extern "C" { int binding_data = 17; }
extern "C" int binding_shared(int x) { return x * 3 + 5; }
