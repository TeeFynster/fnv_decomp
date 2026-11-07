#pragma once

class Controls;
class InputManager;
class OSInputGlobals;
class OSSoundGlobals;

class OSGlobals
{
public:
    unsigned char oneMore;
    unsigned char quitGame;
    unsigned char exitToMainMenu;
    unsigned char layoutPadding3;
    unsigned short layoutPadding4;
    bool isFlycam;
    unsigned char layoutPadding7;
    void* window;
    void* procInstance;
    unsigned int mainThreadID;
    void* mainThreadHandle;
    void* scrapHeapBuffer;
    unsigned int layoutPadding1C;
    OSInputGlobals* input;
    OSSoundGlobals* sound;

    unsigned int GetUptimeMilliseconds();
    unsigned int GetThreadId();
    Controls* GetInputControls();
    InputManager* GetInputManager();
    unsigned int TESMain_GetThread();
    void Main_Swap();
    InputManager* Main_GetControls();
    InputManager* Main_GetControls(int);
    InputManager* Main_GetControls(int, int);
};
