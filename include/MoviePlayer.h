#pragma once

class Direct3DDeviceInterface;
class MovieJob;

class MoviePlayer
{
public:
    virtual void* vf00(unsigned int flags);
    virtual void BeginMoviePlayback();
    virtual void EndMoviePlayback();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual Direct3DDeviceInterface* GetDevice();
    virtual void StartScene();
    virtual void FinishScene();
    virtual unsigned int UpdateInterfaceState();
    virtual unsigned int GetFirstInterfaceFloat();
    virtual bool IsDeviceReady();
    virtual unsigned int GetScreenWidthOverride();
    virtual int vf14();
    virtual unsigned int GetUptimeMilliseconds();
    virtual bool UpdateMoviePlayback(bool continuePlaying);

    int m_0004;
    int m_0008;
    MovieJob* m_000c;

    void __thiscall WaitForJobCompletion();
};
