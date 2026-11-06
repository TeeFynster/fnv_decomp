#pragma once

class FormRecordHeader
{
public:
    unsigned int form;
    unsigned int length;
    unsigned int flags;
    unsigned int iFormID;
    unsigned int m_uiVersionControlInfo;
    unsigned short m_usFormVersion;
    unsigned short m_usHeaderUnknown;
};
