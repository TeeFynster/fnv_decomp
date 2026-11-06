#pragma once

#include "hkTagfileReader.h"
#include "hkArray.h"

class hkClass;
class hkStatisticsCollector;
struct DataObjectImplReference;

class hkBinaryTagfileReader : public hkTagfileReader
{
public:
    virtual ~hkBinaryTagfileReader();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual unsigned int __stdcall FUN_00dc5d50(unsigned int a, unsigned int b, unsigned int c);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    hkArray<char*> m_pStringFunctions;

    int FUN_00dc5bd0() throw();
    __int64 ReadVarInt();
    void FUN_00dd8fe0(void* pvBuf, int iElemSize, int iNumElems) throw();
    void ReadBits(int iNumBits, hkArray<char>& kBitsOut) throw();
    void FUN_00dd90d0(void* pvBuf, int iNumBytes) throw();
    char* ReadString();
    void ReadByteArray(void* buf, int size, int count);
    int ReadTag();
    int readMetadata();
    DataObjectImplReference readObjectTopLevel(int tag);
    DataObjectImplReference FUN_00dc6e50();
};
