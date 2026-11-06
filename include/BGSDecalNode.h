#pragma once

#include "NiNode.h"

class BSTempEffect;
class GO;
template <class T> class BSSimpleList;

class BGSDecalNode : public NiNode
{
  public:
    BGSDecalNode();
    BGSDecalNode(NiNode* parent, unsigned char flag);
    virtual ~BGSDecalNode();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void ProcessClone(CloningProcess& process);
    virtual void OnVisible(NiCullingProcess& culler);
    virtual bool IsDecalNode();
    virtual void AttachChildInAvailableSlot(NiAVObject* object, bool firstAvailable);
    virtual void AttachChildInAvailableSlot(BSTempEffect* effect, bool firstAvailable);

    void CopyMemberData(BGSDecalNode* node, CloningProcess* process);
    void Init();
    void InitNameAndData();
    void RemoveEffect(void* effect);
    void AttachDecalEffect(BSTempEffect* effect);
    void InsertChild(BSTempEffect* effect, void* context);
    void InsertChild(BSTempEffect* effect);
    void RemoveDecals();
    static void RemoveAllDecals();
    void FUN_004ee1e0();
    void FUN_004ee390();
    void FUN_004ee450(BSTempEffect* effect, bool firstAvailable);
    void FUN_004ee4d0(NiAVObject* object, bool firstAvailable);
    void FUN_004ee560(int value);
    void FUN_004ee610(int value);
    void* DestroyDecalNode(unsigned int flags);

    BSSimpleList<GO>* pList;
    unsigned char flag;
};
