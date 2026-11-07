#pragma once

#include "MagicProjectile.h"
#include "MagicCaster.h"

class MagicFogProjectile : public MagicProjectile
{
public:
    struct VirtualInterface
    {
        char unk0[8];
        VirtualInterface* next;
    };

    struct SoundState
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0C;

        ~SoundState();
        bool FUN_00ad8ce0();
        void FUN_00ad88f0();
        void FUN_00ad8d10();
    };

    struct LightState
    {
        ~LightState();
    };

    __forceinline SoundState& GetSoundState()
    {
        return *reinterpret_cast<SoundState*>(reinterpret_cast<char*>(this) + 0xBC);
    }
    __declspec(property(get=GetSoundState)) SoundState& m_kSound;

    __forceinline LightState*& GetLightState()
    {
        return *reinterpret_cast<LightState**>(reinterpret_cast<char*>(this) + 0xCC);
    }
    __declspec(property(get=GetLightState)) LightState*& m_pkCc;

    __forceinline char& GetPadByte(unsigned int index)
    {
        return reinterpret_cast<char*>(this)[index];
    }
    __declspec(property(get=GetPadByte)) char _pad[];

    __forceinline VirtualInterface*& GetActiveTargetList()
    {
        return *reinterpret_cast<VirtualInterface**>(reinterpret_cast<char*>(this) + 0xC8);
    }
    __declspec(property(get=GetActiveTargetList)) VirtualInterface*& pActiveTargetList;

    __forceinline float& GetM14()
    {
        return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x14);
    }
    __declspec(property(get=GetM14)) float& _m14;

    virtual ~MagicFogProjectile();

    void DeleteAllNodes();
    unsigned short GetSaveRecordSize(unsigned int);
    unsigned short GetSaveSize_0081ad00(unsigned int flags);
    bool IsAboveZero();
    void FUN_008196e0();
    MagicCaster* FUN_009185e0();
    void* DestroyIfFlagged(unsigned int);
};
