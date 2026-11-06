#pragma once

#include "CIdvCamera.h"

class ElementIterator;
class CTreeFileAccessImpl;
class TreeFileAccess;
class Reader;

class CTreeEngine : public CIdvCamera
{
public:
    struct SptFilename
    {
        int allocator;
        union Buffer
        {
            char buffer[16];
            char* data;
        } storage;
        unsigned int length;
        unsigned int capacity;

        SptFilename(const SptFilename& rhs);
        ~SptFilename();
        void FUN_0044a730(bool built, unsigned int n);
        SptFilename& AssignFromString(const SptFilename& rhs);
        SptFilename& FUN_00b2b910(const SptFilename& rhs);
        void operator=(const SptFilename& rhs);
    };

    struct Sub94
    {
        void FUN_00b3d1b0(ElementIterator* a);
    };

    struct SubA4
    {
        void FUN_00b2db10(SubA4* a);
    };

    struct Sub10c
    {
        void FUN_00b408b0(ElementIterator* a);
    };

    float* m_pfTreeSize;
    float* m_pfTreeSizeVariance;
    float m_actualSize;
    float m_actualVariance;
    int unk20;
    SptFilename m_pcFileName;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    Sub94 m_sub94;
    int unk98;
    int unk9c;
    int unka0;
    SubA4 m_suba4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    float unkF4;
    float unkF8;
    float unkFC;
    float unk100;
    float unk104;
    int unk108;
    Sub10c m_sub10c;

    CTreeEngine(int param);
    virtual ~CTreeEngine();

    void FUN_00b2bc70(float v);
    void FUN_00b2bcf0(float* a, float* b);
    void FUN_00b2bd20(float fSize, float fVariance);
    float GetNormalizedValue();
    void FUN_00b2bdc0(float a, float b);
    void InitSeed(unsigned int seed);
    void InitSeed(int seed);
    bool FUN_00b2b550(CTreeFileAccessImpl* file);
    void FUN_00b2bde0(ElementIterator* a);
    void FUN_00b2cbc0(ElementIterator* a);
    void FUN_00b2daf0(ElementIterator* a);
    void FUN_00b2ceb0(ElementIterator* a);
    void FUN_00b2c790(ElementIterator* a);
    void FUN_00b2c130();
    void FUN_00b2d090(TreeFileAccess* file);
    void FUN_00b2d2e0(Reader* a);
};
