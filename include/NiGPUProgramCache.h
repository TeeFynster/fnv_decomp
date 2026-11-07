#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"
#include "NiTFixedStringMap_NiAVObject___.h"

class NiFile;
class NiBinaryStream;
class NiGPUProgram;

class NiGPUProgramCache : public NiRefObject
{
public:
    class ObjectMapBase
    {
    public:
        ObjectMapBase() throw();
        virtual ~ObjectMapBase() throw();
        void RemoveAll();

        unsigned int m_uiHashSize;
        void* m_ppkHashTable;
        unsigned int m_uiCount;
    };

    class ObjectMap : public ObjectMapBase
    {
    public:
        ObjectMap() throw();
        virtual ~ObjectMap() throw();
        void RemoveAll();
    };

    NiGPUProgramCache(void* a, unsigned char b, unsigned char c);
    virtual ~NiGPUProgramCache();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void* LookupAndVisit(const char* name, void* visitor);
    virtual void vf19();
    virtual int* GetValidCompileTargetsForPlatform();
    virtual const NiFixedString& GetPlatformName();
    virtual char* GetWorkingDirectory();
    virtual bool SetString(const NiFixedString& s) throw();
    virtual const char* GetRendererName();
    virtual const char* GetShaderType();
    virtual bool LoadCacheFile();
    virtual bool CanCreateDirectory();
    virtual bool vf28();
    virtual char IsLoaded_00ee8aa0();
    virtual unsigned char IsLocked_00ee8ab0();
    virtual bool RemoveMissingKeys(void* keys, void* entries);
    virtual void UpdatePathString() throw();
    virtual bool NiGPUProgramCache_AppendEntry(void* pvArg, void* pvArgCur);
    virtual bool WriteToStream(NiFile* s, NiRefObject* o, int* v);
    virtual bool FiveIntegerLoadRecord(NiFile* pkFile, bool* pbUpdated);
    virtual bool vf90(NiFile* s, int v);
    virtual void vf37();

    void Clear()
    {
        CanCreateDirectory();
    }
    bool LoadFromFile(NiFile* pkFile, void* pvArg, void* pvArgCur);
    ObjectMap& GetObjectMap()
    {
        return reinterpret_cast<ObjectMap&>(m_kObjectMap);
    }

    bool FUN_00ee8e70();
    char* GetShaderProfile();
    bool Save_00ee9620();
    bool CanOpen();
    bool CanSave();
    void onStringChanged();
    void vfn20() throw();
    void v22(NiFile* s, NiRefObject* val, NiFixedString* key);
    bool NiGPUProgramCache_LoadStringA(NiFile* pkFile, char* pcBuffer, unsigned int uiBufferSize);
    void NiGPUProgramCache_SaveString(NiFile* s, unsigned int v);
    void NiGPUProgramCache_SaveString(NiFile* s, int v);

    union
    {
        NiTFixedStringMap_NiAVObject___ m_kObjectMap;
        struct
        {
            char unk08;
            char _pad1[0x0F];
        };
        struct
        {
            unsigned int unk08Map;
            void* m_pkEntryMap;
            unsigned int m_uiStreamIndex;
            unsigned int m_uiEntryMax;
        };
    };
    NiFixedString m_18;
    NiFixedString m_pcWorkingDir;
    NiFixedString m_pcCacheFileName;
    NiFixedString m_s3;
    char** unk28;
    unsigned int m_uiValue1;
    unsigned int m_uiBufferSize;
    unsigned int m_uiReserved;
    bool m_bAutoWrite;
    bool m_bLoadComplete;
    unsigned char m_3a;
    unsigned char unk3B;
};
