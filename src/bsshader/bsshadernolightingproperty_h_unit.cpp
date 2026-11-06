// Header unit for bsshadernolightingproperty.h.
// The covered getter is defined in the shared header. This translation
// unit only forces the covered COMDAT to be
// emitted so its bytes can be compared against the original.
#include "../../include/BSShaderNoLightingProperty.h"

void BSShaderNoLightingProperty_UnitReference()
{
    BSShaderNoLightingProperty* pProperty = 0;
    NiTexture* pTexture = pProperty->GetBaseTexture();
    (void)pTexture;
}
