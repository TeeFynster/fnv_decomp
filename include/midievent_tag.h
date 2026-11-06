#pragma once

class midievent_tag
{
public:
    unsigned long dwDeltaTime;
    unsigned long dwStreamID;
    unsigned long dwEvent;
    unsigned long dwParms[1];
};
