#pragma once

struct ActivateEntry334;

struct ActivateList334
{
public:
    ActivateEntry334* value;
    ActivateList334* next;

    unsigned int ItemsInList();
    bool IsEmpty();
    ActivateEntry334*& GetItem();
    ActivateList334* GetNext();
};
