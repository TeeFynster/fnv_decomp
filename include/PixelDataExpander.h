#pragma once

class NiPixelData;

class PixelDataExpander
{
public:
    NiPixelData* ExpandPixelData(const NiPixelData&) throw();
};
