#pragma once

class TESObjectCELL;

class TESChildCell
{
public:
    TESChildCell();

    virtual TESObjectCELL* GetSaveParentCell();
};
