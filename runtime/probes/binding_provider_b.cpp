#include "binding_fixture.hpp"
extern "C" { int binding_data = 29; }
extern "C" int binding_shared(int x) { return x * 7 - 9; }
