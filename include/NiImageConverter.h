#pragma once
#include "NiRefObject.h"

class NiPixelData;
class NiPixelFormat;

class NiImageConverter : public NiRefObject
{
public:
    virtual void vf02();
    virtual void vf03();
    virtual bool CanConvertPixelFormat(const NiPixelFormat&, const NiPixelFormat&);
    virtual NiPixelData* ConvertImageData(const NiPixelData&, const NiPixelFormat&, NiPixelData*, bool);

    static NiImageConverter* GetSharedImageConverter();
};
