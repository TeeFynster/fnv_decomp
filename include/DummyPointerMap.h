#pragma once

class DummyPointerMap
{
public:
    int a;
    int b;
    int c;
    int d;

    DummyPointerMap(int);
    bool GetAt(unsigned int, int&) const;
    bool GetAt(unsigned int, unsigned int&);
    bool GetAt(unsigned int, unsigned int&) const;
    void SetAt(unsigned int, unsigned int);
    void SetAtCoordinates(unsigned int, short, short, unsigned int, unsigned int, unsigned int);
};
