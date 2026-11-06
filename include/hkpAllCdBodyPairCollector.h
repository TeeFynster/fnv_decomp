#pragma once

#include "hkpCdBodyPairCollector.h"

class hkpAllCdBodyPairCollector : public hkpCdBodyPairCollector
{
public:
    struct BodyPair
    {
        void* bodyA;
        void* bodyB;
        void* bodyC;
        void* bodyD;
    };

    struct PairArray
    {
        void* data;
        int size;
        int capacity;
        BodyPair pairs[16];

        PairArray(int a);
        ~PairArray();
    };

    int unk04;
    PairArray m8;

    hkpAllCdBodyPairCollector();
    virtual ~hkpAllCdBodyPairCollector();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
    virtual void FUN_0062d330();

    void* FUN_0062d440(unsigned int flags);
    void FUN_0062d310();
};
