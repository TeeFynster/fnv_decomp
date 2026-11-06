
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for Font::TextMeasurement.
//
// The original build compiled bsmenu/font.h inside a menu translation unit.
// This translation unit plays that role for the matcher build: it includes
// the shared Font definition and references the covered function so the compiler
// emits its COMDAT body the same way the original translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "../../include/Font.h"

void FontEmitCoveredFunctions()
{
    Font::TextMeasurement* data = 0;
    // Qualified call: keeps the inline destructor's body in this object file.
    data->Font::TextMeasurement::~TextMeasurement();
}
