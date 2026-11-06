#pragma once

class TESIdleForm;
class Script;
class TESTopic;

class PackageAction
{
public:
    void Finish();
    int FUN_0045cd60();

    TESIdleForm* idle;
    Script* script;
    TESTopic* topic;
    unsigned long type;
};
