#ifndef BINDING_FIXTURE_HPP
#define BINDING_FIXTURE_HPP
extern "C" int binding_shared(int);
extern "C" int binding_data;
extern "C" int binding_call_a(int);
extern "C" int binding_call_b(int);
extern "C" int* binding_address_a();
extern "C" int* binding_address_b();
#endif
