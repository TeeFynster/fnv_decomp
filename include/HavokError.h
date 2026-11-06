#pragma once

#include "hkError.h"

class HavokError : public hkError
{
public:
    HavokError();
    virtual ~HavokError() throw();
    virtual int message(int type, int id, const char* description, const char* file, int line);
    virtual void vf06();
    virtual void beginSection(int id, const char* name);
    virtual void endSection();
    virtual void FUN_00625e70(const char* file, int line);
    virtual void RemoveEntryByPathAndValue(const char* path, int value);
    virtual void FUN_00625790(const char* prefix, int soundId, const char* message, const char* file, int line);
    virtual void ReportWarning(const char* what, int id, const char* description, const char* file, int line);
    virtual void WarnWithLocation(const char* message, int unused, const char* type, const char* file, int line);
    virtual void ReportError(const char* what, int id, const char* description, const char* file, int line);
    virtual void FUN_00625a80(const char* str);
    virtual const char* FUN_00625aa0(const char* path);

    bool FUN_00625c50(const char* path, int value);

    int Warning(int type, int id, const char* desc, const char* file, int line);
    void __thiscall FUN_00625650();
};
