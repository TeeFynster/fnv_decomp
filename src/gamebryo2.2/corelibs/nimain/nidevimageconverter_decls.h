// Private pixel-conversion helpers for nidevimageconverter.cpp.
#ifndef NIDEVIMAGECONVERTER_DECLS_H
#define NIDEVIMAGECONVERTER_DECLS_H

#include "../../../../include/NiMemObject.h"
struct NiPoint3StartupTable;
extern NiPoint3StartupTable gNiPoint3StartupSrc;
#define SOURCE_FORMAT_RGB reinterpret_cast<const NiPixelFormat&>(gNiPoint3StartupSrc)
extern const NiPixelFormat DAT_011aa180;
extern const NiPixelFormat DAT_011aa1c8;
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa258;
extern const NiPixelFormat DAT_011aa2e8;
extern const NiPixelFormat DAT_011aa330;
extern const NiPixelFormat DAT_011aa3c0;
extern const NiPixelFormat DAT_011aa408;
extern const NiPixelFormat DAT_011aa450;
template <class T> class ImageConverterPointer
{
  public:
    T* m_pObject;
    ImageConverterPointer() throw() : m_pObject(0)
    {}
    operator T*() const throw()
    {
        return m_pObject;
    }
    T* operator->() const throw()
    {
        return m_pObject;
    }
    T& operator*() const throw()
    {
        return *m_pObject;
    }
    ImageConverterPointer& operator=(T*) throw();
    ~ImageConverterPointer() throw()
    {
        if (m_pObject && InterlockedDecrement((volatile long*)&m_pObject->m_uiRefCount) == 0)
            m_pObject->DeleteThis();
    }
};
extern "C" void* __cdecl fnv_zlib_memcpy(void*, const void*, unsigned);
typedef void(__cdecl* PixelConvertFunc)(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                        const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                        const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a76d70(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a76e90(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelsTo16Bit(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                  const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                  const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRGBToFormat(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRGBAToPacked(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                 const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                 const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a77110(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a771d0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl UnpackPixels(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelsToBytes(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                  const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                  const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a773d0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRgbToRgba(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                              const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                              const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelsToRgb(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPixelFormat(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPackedPixelsToRGBA(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                       const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                       const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a776b0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertRgbToPacked16(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                  const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                  const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a77800(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a77880(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl Convert4BitPalettedTo24Bit(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                        const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                        const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ExpandPalettedImage(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                 const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                 const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a79310(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPaletteTo16Bit(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                   const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                   const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a798c0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a79ae0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a79e20(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl ConvertPalettizedToFormat(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                                       const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                                       const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a7a160(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
void __cdecl FUN_00a7a1f0(unsigned, unsigned, unsigned, unsigned char*, const NiPalette*,
                          const NiDevImageConverter::PixelFormatBitLayout&, const unsigned char*,
                          const NiDevImageConverter::PixelFormatBitLayout&);
bool __cdecl FUN_00a77920(unsigned) throw();
#endif
