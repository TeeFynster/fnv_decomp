#pragma once

#include "NiAVObject.h"

class WaitableObject;
class PathingSolution;
enum PATHING_MESSAGE_TYPE;

class QueuedMessage
{
public:
    int m_eMessageType;
    NiPointer<WaitableObject> m_pPathingSolution;

    QueuedMessage(PATHING_MESSAGE_TYPE type, const NiPointer<PathingSolution>& solution);
    ~QueuedMessage();
    QueuedMessage& operator=(const QueuedMessage&);
};
