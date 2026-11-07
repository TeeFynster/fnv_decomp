#pragma once

#include "NiObject.h"
#include "StrArr.h"

class TimedAnimationKey;
class NiUVKey;
class NiUVStream;
struct NiStreamX;

enum NiUVKeyType
{
    NOINTERP,
    LINKEY,
    BEZKEY,
    TCBKEY,
    EULERKEY,
    STEPKEY,
    NUMKEYTYPES
};

class NiUVData : public NiObject
{
public:
    virtual ~NiUVData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);

    void Destructor();
    void* FUN_00a45200(unsigned int flags);
    void ReplaceUOffsetAnim(TimedAnimationKey* keys, unsigned int numKeys, unsigned int type);
    void ReplaceVOffsetAnim(void* keys, unsigned int count, int type);
    void ReplaceUTilingAnim(void* keys, unsigned int count, unsigned int type);
    void ReplaceVTilingAnim(void* keys, unsigned int count, unsigned int type);
    bool IsEqual_00a45090(NiUVData* pkOther);
    void FUN_00a453a0(NiUVStream& kStream);
    void FUN_00a45610(NiStreamX& kStream);
    void AppendKeyNames(StrArr* apViewerStrings);
    void ReplaceUOffsetKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceVOffsetKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceUTilingKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    void ReplaceVTilingKeys(NiUVKey* pkKeys, unsigned int uiNumKeys, NiUVKeyType eType);
    static unsigned char* GetKeyPointerByIndex(unsigned char* pk, unsigned int i, unsigned char uc);

    unsigned int m_uiNumUOffsetKeys;
    unsigned char* m_pUOffsetKeys;
    unsigned int m_uiUOffsetKeyStride;
    unsigned int m_uiNumVOffsetKeys;
    unsigned char* m_pVOffsetKeys;
    unsigned int m_uiVOffsetKeyStride;
    unsigned int m_uiNumUTilingKeys;
    unsigned char* m_pUTilingKeys;
    unsigned int m_uiUTilingKeyStride;
    unsigned int m_uiNumVTilingKeys;
    unsigned char* m_pVTilingKeys;
    unsigned int m_uiVTilingKeyStride;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    unsigned char m_ucByte48;
    unsigned char m_ucByte49;
    unsigned char m_ucByte4A;
    unsigned char m_ucByte4B;
};
