#pragma once

#include "NiRefObject.h"

class Actor;
class Animation;
class BSAnimGroupSequence;
class KFModel;
class NiPoint3;
class TESIdleForm;

class AnimIdle : public NiRefObject
{
  public:
    enum PLAY_TYPE_ENUM  // values: Xbox PDB AnimIdle::PLAY_TYPE_ENUM
    {
        PLAY_TYPE_REPLACE = 0,
        PLAY_TYPE_QUEUE = 1,
        PLAY_TYPE_AUTO = 2,
        PLAY_TYPE_AUTO_EXCLUSIVE = 3
    };

    AnimIdle(TESIdleForm*, int, int, Actor*, int, Animation*);
    AnimIdle(TESIdleForm*, int, int, Actor*, bool, Animation*);
    virtual ~AnimIdle();

    void IncRefCount();
    void DecRefCount();
    int GetSection();
    unsigned int GetFlags();
    BSAnimGroupSequence* GetControllerSequence();
    void Loaded(KFModel*);
    void SetTranslate(const NiPoint3& kTranslate);
    void SetRotate(const void* pvRotate);
};
