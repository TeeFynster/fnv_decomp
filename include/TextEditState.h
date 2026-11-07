#pragma once

class TextEditState
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;

    void EditableTextField_SetMaxSize(int maxLength);
    void SetBothStrings(const char* text);
    void TextEditMenu_Data_SetIsActive(bool enabled);
    void FUN_007e6580(bool foreground);
};
