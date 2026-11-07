#pragma once
#include "BSStreamHeader.h"

class NiObject;
class NiObjectGroup;
class NiAVObject;
class NiBinaryStream;
class NiFile;
class BSFile;
class NiFixedString;
class NiTexture;
class NiSourceTexture;
class NiSearchPath;
class NiThread;
class WriteStream;
class StreamRecord;
template <class T> class NiPointer;

// Bethesda's NIF header block (BS version, then the exporter's author / process script / export script strings).

// Gamebryo 2.2 NiStream: RTTI .?AVNiStream@@ has no base classes, vftable 0x0109bdcc (24 slots); 0x5C4 bytes
// (BSStream, the only derived class, adds two dwords and ends at 0x5CC). Built by 0x00a66150, destroyed by 0x00a66350.
struct NiStream
{
public:
    // Storage of the Gamebryo containers NiStream holds by value. The container templates themselves have no
    // shared header (units define their own NiTArray/NiTLargeArray/NiTSet/NiTPointerMap), so these give their
    // exact members and offsets; m_pvContainerVtbl is the container's own vftable pointer.
    template <class T> struct NiTPrimitiveArrayStorage  // NiTPrimitiveArray<T>, 0x10 bytes
    {
        void* m_pvContainerVtbl;
        T* m_pBase;
        unsigned short m_usMaxSize;
        unsigned short m_usSize;
        unsigned short m_usESize;
        unsigned short m_usGrowBy;
    };
    template <class T> struct NiTLargeArrayStorage  // NiTLargeObjectArray<T> / NiTLargePrimitiveArray<T>, 0x18 bytes
    {
        void* m_pvContainerVtbl;
        T* m_pBase;
        unsigned int m_uiMaxSize;
        unsigned int m_uiSize;
        unsigned int m_uiESize;
        unsigned int m_uiGrowBy;
    };
    template <class T> struct NiTPrimitiveSetStorage  // NiTPrimitiveSet<T> (no vftable), 0xC bytes
    {
        T* m_pBase;
        unsigned int m_uiAlloced;
        unsigned int m_uiUsed;
    };
    template <class K, class V> struct NiTPointerMapStorage  // NiTPointerMap<K, V>, 0x10 bytes
    {
        void* m_pvContainerVtbl;
        unsigned int m_uiHashSize;
        void** m_ppkHashTable;
        unsigned int m_uiCount;
    };
    struct ProcessorAffinity  // NiProcessorAffinity, 8 bytes
    {
        unsigned int m_eIdealProcessor;
        unsigned int m_uiAffinityMask;
    };
    enum ThreadStatus
    {
        IDLE,
        LOADING,
        CANCELLING,
        PAUSING,
        PAUSED
    };
    class BackgroundLoadProcedure;

    BSStreamHeader m_kHeader;                                            // +0x004
    NiTPrimitiveArrayStorage<NiObjectGroup*> m_kGroups;                  // +0x0C8
    unsigned int m_uiNifFileVersion;                                     // +0x0D8
    unsigned int m_uiNifFileUserDefinedVersion;                          // +0x0DC
    char m_acFileName[260];                                              // +0x0E0
    bool m_bSaveLittleEndian;                                            // +0x1E4
    bool m_bSourceIsLittleEndian;                                        // +0x1E5
    NiSearchPath* m_pkSearchPath;                                        // +0x1E8
    NiTLargeArrayStorage<NiPointer<NiObject> > m_kObjects;               // +0x1EC  link ID -> object
    NiTLargeArrayStorage<unsigned int> m_kObjectSizes;                   // +0x204
    NiTLargeArrayStorage<NiPointer<NiObject> > m_kTopObjects;            // +0x21C
    NiTLargeArrayStorage<NiFixedString> m_kFixedStrings;                 // +0x234
    NiBinaryStream* m_pkIstr;                                            // +0x24C  stream being loaded
    NiBinaryStream* m_pkOstr;                                            // +0x250  stream being saved
    NiTPrimitiveSetStorage<unsigned int> m_kLinkIDs;                     // +0x254
    unsigned int m_uiLinkIndex;                                          // +0x260
    NiTPrimitiveSetStorage<unsigned int> m_kLinkIDBlocks;                // +0x264
    unsigned int m_uiLinkBlockIndex;                                     // +0x270
    NiTPointerMapStorage<const NiObject*, unsigned int> m_kRegisterMap;  // +0x274
    unsigned short m_usNiAVObjectFlags;                                  // +0x284
    unsigned short m_usNiTimeControllerFlags;                            // +0x286
    unsigned short m_usNiPropertyFlags;                                  // +0x288
    ThreadStatus m_eBackgroundLoadStatus;                                // +0x28C
    bool m_bBackgroundLoadExitStatus;                                    // +0x290
    unsigned int m_uiLoad;                                               // +0x294  object being loaded (ChangeObject)
    unsigned int m_uiBackgroundLoadState;                                // +0x298
    unsigned int m_uiBackgroundLoadThreadInfo;                           // +0x29C
    NiThread* m_pkThread;                                                // +0x2A0
    BackgroundLoadProcedure* m_pkBGLoadProc;                             // +0x2A4
    int m_ePriority;                                                     // +0x2A8  NiThread::Priority
    ProcessorAffinity m_kAffinity;                                       // +0x2AC
    char m_acLoadPath[260];                                              // +0x2B4
    unsigned int m_uiNativeThreadId;                                     // +0x3B8
    char m_acLastErrorMessage[260];                                      // +0x3BC
    char m_acStreamPath[260];                                            // +0x4C0  SetStreamPath / GetLastLoadedFilePath

    NiStream();
    virtual ~NiStream();

    // VC9 emits each virtual overload group in reverse declaration order.
    virtual bool Load(const char* name);                                     // 3  0x00a63be0
    virtual bool Load(char* buffer, int size);                               // 2  0x00a632f0
    virtual bool Load(NiBinaryStream* stream);                               // 1  0x00a63330
    virtual bool Save(const char* name);                                     // 6  0x00a640b0
    virtual bool Save(char*& buffer, int& size);                             // 5  0x00a635e0
    virtual bool Save(NiBinaryStream* pStream);                               // 4  0x00a63380
    virtual void vf07();                                                     // 7  0x00a29680 (empty)
    virtual bool RegisterFixedString(const NiFixedString& kString);           // 8  0x00a66480
    virtual bool RegisterSaveObject(NiObject* pObject);                       // 9  0x00a663e0
    virtual void ChangeObject(NiObject* pObject);                             // 10 0x00a64550
    virtual unsigned int GetLinkIDFromObject(const NiObject* pObject) const;  // 11 0x00a63480
    virtual void SaveLinkID(const NiObject* pObject);                         // 12 0x0043d050
  public:  // stream phases (slots 13-23): header
    virtual bool LoadHeader();                                               // 13 0x00a65400
    virtual void SaveHeader();                                               // 14 0x00a64940
  public:  // whole-stream load/save
    virtual bool LoadStream();                                               // 15 0x00a65c60
    virtual bool SaveStream();                                               // 16 0x00a66850
  public:  // object registration and top-level lists
    virtual void RegisterObjects();                                          // 17 0x00a635b0
    virtual void LoadTopLevelObjects();                                      // 18 0x00a65720
    virtual void SaveTopLevelObjects();                                      // 19 0x00a63d80
  public:  // per-object load and the size table
    virtual bool LoadObject();                                               // 20 0x00a664e0
    virtual unsigned int PreSaveObjectSizeTable();                           // 21 0x00a63df0
    virtual bool SaveObjectSizeTable(unsigned int uStartOffset);              // 22 0x00a63e60
    virtual bool LoadObjectSizeTable();                                      // 23 0x00a64740

    bool LoadRTTIAndObjects();
    void LoadRTTIString(unsigned int param);
    bool FUN_00a640b0(const char* name);
    void RegisterStreamable(void* object);
    void Register(void* object);
    void RegisterObject(NiObject* object);
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, const unsigned int* value);
    NiObject* FUN_00a63430();
    void NiTexture_SetTexture(NiSourceTexture* texture);
    void SaveCString(const char* name);
    void Read(void* data, unsigned int size, unsigned int count);
    void ReadStreamString(char*& string);
    void WriteStreamString(const char* string);
    void AppendValue(const unsigned int& value);
    int GetRefAt21C();
    NiAVObject* GetStringAt(unsigned int index);
    void ResetStreamState();
    int FindIndex(int* pVal);
    void LoadGroups();
    NiObject* GetLoadedObject();
    NiObject* GetLoadedObject(unsigned int linkID);
    bool Load(const char* name, BSFile* file);
    bool BSStream_Load(const char* name, BSFile* file);
    bool BSStream_Load(const char* name, bool flag);
    bool Save(NiFile* file);
    NiObject* DeserializeObject();
    unsigned int GetLinkID();
    void SerializeString(const char* string);
    void ReadFixedString(NiFixedString& string);
    void ReadStringTableEntry(NiFixedString& string);
    unsigned int ReadUnsignedInteger();
    void ReadUnsignedInteger(unsigned int value);
    void ReadCString(char*& string);
    void SetLinkIDCount(unsigned int count);
    bool SetTexture(NiTexture* texture);
    void SetStreamPath(const char* path);
    void GetTexture(const char* name, NiPointer<NiTexture>& texture);
    NiObjectGroup* GetObjectGroup(unsigned int groupID);
    void ClearTopLevelObjects();
    void InsertObject(NiObject* object);
    bool GetLastLoadedFilePath(char* buffer, unsigned int size);
    void ReadLinkIDStub();
    void ReadLinkID();
    unsigned int GetFileVersion() const;
    void SetLastNiTimeControllerFlags(unsigned short flags);
    NiBinaryStream& Istr();
    NiBinaryStream* GetBinaryStream();
    WriteStream* GetWriter();
    StreamRecord* record();
    unsigned int version();
    unsigned short savedFlags();
    template <class T> void ReadValue(T& value);
    template <class T> void BinaryRead(T& value) throw();

    static int __cdecl RegisterObjectLoader(const char* name, NiObject*(__cdecl* loader)());
    static void __cdecl UnregisterObjectLoader(const char* name);
    static void RegisterPostProcess(void(__cdecl* function)(NiStream&, NiObject*));
};
