#pragma once

class BSCoreMessage
{
public:
    virtual ~BSCoreMessage();
    virtual void vf01(int a);
    virtual void vf02();
    virtual int vf03();
    virtual void vf04();
    virtual BSCoreMessage* vf05(unsigned int auiTextID, unsigned int auiCaptionID,
                               const char* apcText, const char* apcCaption,
                               unsigned int aStyle);

    void UpdateFields_00aa4c80();
    void* FUN_00aa4d00(unsigned int flags);
};
