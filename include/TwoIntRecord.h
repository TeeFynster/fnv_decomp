#pragma once

class NavMesh;

struct TwoIntRecord
{
public:
    int a;
    int b;

    TwoIntRecord();
    TwoIntRecord(NavMesh*, unsigned short);
    TwoIntRecord(const TwoIntRecord&);
    TwoIntRecord& operator=(const TwoIntRecord&);
    void FUN_FNVH(const TwoIntRecord&);
};

struct TwoIntRecordValue
{
public:
    int m;

    TwoIntRecordValue(const TwoIntRecordValue&);
    TwoIntRecordValue& operator=(const TwoIntRecordValue&);
};
