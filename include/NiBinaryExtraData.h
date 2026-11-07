#pragma once

#include "NiExtraData.h"

class NiAVObject;
class NiStreamLike;

class NiBinaryExtraData : public NiExtraData
{
  public:
    NiBinaryExtraData();
    NiBinaryExtraData(unsigned int, unsigned char*) throw();
    virtual ~NiBinaryExtraData();

    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* apObject) const;

    NiExtraData* CreateClone_00a7f920(CloningProcess& cloning);
    void FUN_00a7b2c0(NiStreamLike* stream);
    void FUN_00a7b2c0(NiStream* stream);
    void SaveBinary_00a7fa20(NiStreamLike* stream);
    void SaveBinary_00a7fa20(NiStream* stream);
    void FUN_00a7b580(NiStream* stream);
    void GetViewerStrings_00a7fa90(NiStream* stream);
    void FUN_00a7b4a0(NiStream& stream);
    void LoadBinary_00a7f9a0(NiStream& stream);
    void NiBinaryExtraData_LinkObject(NiAVObject* object);
    void BSXFlags_LinkObject(NiAVObject* object);
    bool RegisterStreamables_00a89ae0(void* argument);
    bool BSXFlags_RegisterStreamables(void* argument);

    union
    {
        unsigned int count;
        char* m_pData;
        char* m_pByteBuffer;
        void* unk0c;
    };
    union
    {
        unsigned char* data;
        unsigned int m_uiSize;
        unsigned int unk10;
    };
};
