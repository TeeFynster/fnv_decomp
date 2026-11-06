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
    unsigned int FUN_0044edb0();
    void FUN_0086ff70();
    InputManager* FUN_00877720();
    InputManager* FUN_00877720(int);
    InputManager* FUN_00877720(int, int);
};
