// Local system-color declarations used by bssoundhandle.cpp.
#ifndef FNV_BSSOUNDHANDLE_WORKER_DECLS_H
#define FNV_BSSOUNDHANDLE_WORKER_DECLS_H

class NiColor;

class SystemColorManager
{
  public:
    class SystemColor
    {
      public:
        void SystemColorManager_SystemColor_GetColor(NiColor&);
    };

    SystemColor* Find(int);
    bool GetColor(int, NiColor&);
};

#endif
