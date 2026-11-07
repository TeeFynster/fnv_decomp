#pragma once

class DownloadableContentManager;
class PathingRequest;

class BSSystemUtility
{
public:
    virtual int ResetSystemUtility(int);
    virtual void Initialize(const char*, const char*, unsigned int);
    virtual void Destroy();
    virtual void Update_00af3340();
    virtual bool vf10(void*);

    unsigned char storage[0x94];

    void vfn_00();
    void vfn_04();
    void vfn_08();
    void Update();
    void SetValue(unsigned char);
    void* DestroyIfFlagged(unsigned int);
    void SetVirtualTable_00af3120();
    DownloadableContentManager& QDLCUtility();
    PathingRequest* QDLCUtility() const;
    void* QDLCUtility() volatile;

    static void __cdecl GetRandomGenerator();
    static int s_iUpdateEnabled;
    static BSSystemUtility* ms_pSystemUtility;
};
