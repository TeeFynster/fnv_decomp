#pragma once

#include "NiObject.h"

class NiAVObject;
class NiFixedString;
class StrArr;

class NiAVObjectPalette : public NiObject
{
public:
    virtual NiAVObject* FindAVObject(const NiFixedString& kName);
    virtual void AddNamedAVObject(const NiFixedString& kName, NiAVObject* pkObject);

    NiAVObject* FindAVObject(NiFixedString& kName);
    void AppendString(StrArr* pkStrings);
};
