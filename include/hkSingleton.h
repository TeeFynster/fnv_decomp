#pragma once

template <typename T>
class hkSingleton
{
public:
    static T* s_instance;
    static __forceinline T& __cdecl GetMonitorStream();

protected:
    hkSingleton();
};
