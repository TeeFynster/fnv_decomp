#pragma once

struct NiStream;

template <class T> class NiTPrimitiveArray;

class NiBoundingVolume
{
public:
    NiBoundingVolume();

    virtual void LoadBinary(NiStream& kStream);
    virtual void __thiscall SaveBinary(NiStream& kStream);
    virtual ~NiBoundingVolume();
    virtual int F3() const;
    virtual void v10();
    virtual void v5(NiBoundingVolume*, void*);
    virtual NiBoundingVolume* v6();
    virtual NiBoundingVolume* Clone();
    virtual void Copy(const NiBoundingVolume& kABV);
    virtual int IsEqual(const NiBoundingVolume& kABV) const;
    virtual bool IsDifferent(NiBoundingVolume* pkOther);
    virtual void AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings);
};
