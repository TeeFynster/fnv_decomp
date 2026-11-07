// fallout_shared/lipsynchanim.cpp: LipSyncAnimation (4 functions)

#include "lipsynchanim_decls.h"

// @fnv 0x004d5930
bool LipSyncAnimation::ApplyToAnimationData(BSFaceGenAnimationData* animation, float endDelay)
{
    if (!animation)
        return false;

    animation->SetTransitionDuration(BSMIN(0.2f, GetNegativeMagnitude(false, true, true, true, false)));

    float phonemes[16];
    float modifiers[17];
    for (unsigned int frame = 0; frame < iTransformCountPerTrack; ++frame)
    {
        memcpy(phonemes, m_ppPhonemeFrames[frame], sizeof(phonemes));
        memcpy(modifiers, m_ppModifierFrames[frame], sizeof(modifiers));
        animation->InsertPhonemeKeyframe(phonemes, 0.033333335f);
        animation->AddModifierKeyframe(modifiers, 0.033333335f);
    }

    if (endDelay > 0.0)
    {
        animation->AddKeyframe(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_PHONEME, endDelay, true);
        animation->AddKeyframe(BS_FACEGEN_MORPH_TYPE_BS_FG_MORPH_MODIFIER, endDelay, true);
    }
    return true;
}

// Scalar deleting destructor entry; the destructor body is a separate callee.
// Calls FUN_004d5080, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004d5850
void* LipSyncAnimation::DeleteThis(unsigned int flags)
{
    ReleaseStorage_004d5080();
    if (flags & 1)
        operator delete(this);
    return this;
}

// Reads characters from stream into output until size bytes are consumed, expanding zero markers into runs of zero bytes.
// @fnv 0x004d5880
// src: COMMUNITY 0x004d5880
bool __cdecl LipSynchAnim_Decompress(NiBinaryStream* stream, char* output, unsigned int size)
{
    bool success = true;
    unsigned int remaining = size;
    while (remaining > 0)
    {
        char value = 0;
        if (!stream->Read(&value, 1))
        {
            remaining = 0;
            success = false;
            break;
        }
        if (value)
        {
            *output = value;
            output++;
            remaining--;
        }
        else
        {
            unsigned short count = 0;
            stream->Read(&count, 2);
            memset(output, 0, count);
            output += count;
            remaining -= 3;
        }
    }
    return success;
}

extern int DAT_010a2480;

class Stream
{
  public:
    virtual ~Stream();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void Seek(int, int);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool IsValid(int, int);
    virtual void vfn_24();
    virtual unsigned int GetLength();
};

struct Header
{
    int version;
    int uncompressedSize;
    int flags;
};

LipSyncAnimation* __cdecl ReadBufFromMemory(char* buffer, unsigned int size);
bool __cdecl LipSynchAnim_Decompress(NiBinaryStream*, char*, unsigned int, unsigned int);

// Reads a 12-byte header from the stream, decompresses or reads the payload into a buffer, parses it into an animation, and deletes the stream and buffer.
// @fnv 0x004d5350
LipSyncAnimation* __cdecl ReadAnimationFromStream(Stream* stream)
{
    Header headerTmp;
    char* buffer_;
    LipSyncAnimation* anim = 0;
    if (!stream || !stream->IsValid(1, 0))
    {
        delete stream;
        return 0;
    }
    int streamSize = stream->GetLength();
    ((NiBinaryStream*)stream)->Read(&headerTmp, 12);
    buffer_ = 0;
    if (headerTmp.version != 1)
    {
        streamSize -= 1;
        stream->Seek(1, DAT_010a2480);
        char* tempBuf5 = new char[streamSize];
        ((NiBinaryStream*)stream)->Read(tempBuf5, streamSize);
        char* end = tempBuf5 + streamSize;
        int countB = 0;
        int offset5 = 0;
        while (tempBuf5 + offset5 < end)
        {
            if (tempBuf5[offset5] != 0)
            {
                countB++;
                offset5++;
            }
            else
            {
                offset5++;
                countB += *(unsigned short*)&tempBuf5[offset5];
                offset5 += 2;
            }
        }
        headerTmp.uncompressedSize = countB;
        headerTmp.version = 1;
        headerTmp.flags = 1;
        stream->Seek(1, DAT_010a2480);
        delete[] tempBuf5;
    }
    else
    {
        streamSize -= 12;
    }
    buffer_ = new char[headerTmp.uncompressedSize + 16];
    if (headerTmp.flags & 1)
    {
        LipSynchAnim_Decompress((NiBinaryStream*)stream, buffer_, streamSize, headerTmp.uncompressedSize);
    }
    else
    {
        ((NiBinaryStream*)stream)->Read(buffer_, headerTmp.uncompressedSize);
    }
    anim = ReadBufFromMemory(buffer_, headerTmp.uncompressedSize);
    delete stream;
    delete[] buffer_;
    return anim;
}
