// gamebryo2.2/corelibs/niconsolerenderer/nigeometrybufferdata.h: declares COMBaseInterface, COMUnknownInterface
#ifndef NIGEOMETRYBUFFERDATA_H
#define NIGEOMETRYBUFFERDATA_H


// D3D9-style interface subset (STDMETHODCALLTYPE is __stdcall on x86).
struct COMBaseInterface
{
    virtual long __stdcall QueryInterface(const void* kRIID, void** ppkObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct COMUnknownInterface
{
    virtual long __stdcall QueryInterface(const void* kRIID, void** ppkObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

#endif
