#pragma once

class hkpCdBody;
class hkpContactMgr;
class hkpLinkedCollidable;

class hkpAgentNnEntry
{
public:
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
    unsigned short m_ausAgentData[2];
    hkpContactMgr* m_pContactManager;
    unsigned char m_cAgentType;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned char m_ucHeaderByte;
    unsigned char m_usHeaderWord;
    hkpLinkedCollidable* m_kCollidable[2];

    inline hkpCdBody* getCollidableA()
    {
        return reinterpret_cast<hkpCdBody*>(m_kCollidable[0]);
    }

    inline hkpCdBody* getCollidableB()
    {
        return reinterpret_cast<hkpCdBody*>(m_kCollidable[1]);
    }
};
