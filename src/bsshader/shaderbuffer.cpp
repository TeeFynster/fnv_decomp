#include "../../include/NiTStringPointerMap.h"
// bsshader/shaderbuffer.cpp: ShaderBufferCollection, SpawnedObject (5 functions)

#include "shaderbuffer_tables.h"
#include "MemoryManager.h"
#include "../../include/NiTStringPointerMap.h"

class ShaderBufferRecord;


class ShaderBufferCollection
{
  public:
    ~ShaderBufferCollection();
    ShaderBufferRecord* Get(const char* name);
    char* pFileName;
    char* m_pBufferName;
    NiTStringPointerMap<ShaderBufferRecord*> m_kBufferMap;
};

extern MemoryManager g_memoryManager;

// Looks up the entry for name in the string-pointer map and returns it, or null if not found.
// @fnv 0x00b7fac0
ShaderBufferRecord* ShaderBufferCollection::Get(const char* name)
{
    ShaderBufferRecord* entry = 0;
    m_kBufferMap.GetAt(name, entry);
    return entry;
}

// @fnv 0x00b7fd50
ShaderBufferCollection::~ShaderBufferCollection()
{
    if (pFileName)
    {
        g_memoryManager.Deallocate(pFileName);
        pFileName = 0;
    }
    if (m_pBufferName)
    {
        g_memoryManager.Deallocate(m_pBufferName);
        m_pBufferName = 0;
    }
}

// Clears two global tables and assigns sequential index values to a series of global slots.
// @fnv 0x00b97c10
void InitializeShaderBufferTables()
{
    fnv_zlib_memset(DAT_011ffa30, -1, 0x3fc);
    fnv_zlib_memset(DAT_011ff9d8, 0, 0x54);
    DAT_011ffa4c = 0;
    DAT_011ffa68 = 1;
    DAT_011ffa8c = 2;
    DAT_011ffd3c = 3;
    DAT_011ffa6c = 4;
    DAT_011ffa90 = DAT_011ffa94 = 5;
    DAT_011ffa9c = 6;
    DAT_011ffa80 = DAT_011ffa7c = 7;
    DAT_011ffcdc = 8;
    DAT_011ffb00 = 9;
    DAT_011ffb0c = DAT_011ffb08 = DAT_011ffb04 = 10;
    DAT_011ffb18 = DAT_011ffb14 = DAT_011ffb10 = 11;
    DAT_011ffb1c = 12;
    DAT_011ffce8 = 13;
    DAT_011ffc90 = 15;
    DAT_011ffcd0 = 16;
    DAT_011ffd30 = DAT_011ffd2c = DAT_011ffd28 = 17;
    DAT_011ffa50 = 18;
    DAT_011ffa88 = 19;
}

struct FUN_00aa4060_Manager
{
    void* MemoryManager_Deallocate(void* object);
};

extern FUN_00aa4060_Manager DAT_011f6238;
extern void* DAT_010ef53c;

extern void FUN_0045cec0(void* object);
extern void __stdcall FUN_00ec5fce(void* base, unsigned int elementSize, unsigned int count, void (*destructor)(void*));

struct FUN_00b7e2b0_Class
{
    void* unk00;
    void* unk04;

    void* Destroy(unsigned char flags);
};

// Releases the owned buffer at unk04 via FUN_00ec5fce and the manager, optionally frees this, and returns this.
// @fnv 0x00b7e2b0
void* FUN_00b7e2b0_Class::Destroy(unsigned char flags)
{
    void* base = unk04;
    *reinterpret_cast<void**>(this) = &DAT_010ef53c;

    if (base != 0)
    {
        void* allocation = static_cast<char*>(base) - 4;
        unsigned int count = *reinterpret_cast<unsigned int*>(allocation);

        FUN_00ec5fce(base, 4, count, FUN_0045cec0);
        DAT_011f6238.MemoryManager_Deallocate(allocation);
    }

    if ((flags & 1) != 0)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }

    return this;
}

namespace fnv_00b7fa40 {
class ShaderLookupTable
{
  public:
    void* Find(unsigned int key);
};
extern ShaderLookupTable DAT_011f6238;

void FNVRegisterEntry(void* found, void* name, unsigned int flags);
void FNVClearRange(void* object, unsigned int value, unsigned int size);
void FNVSetOwner(void* object, unsigned int size, void* owner);

class SpawnedObject
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int m_100;
    void* m_104;
    SpawnedObject* ShaderBufferData_ShaderBufferData(void* arg1, void* arg2, unsigned int arg3);
};

// Stores arg3 in m_100, looks up arg3 in DAT_011f6238 and registers arg2 when both are non-zero, clears the first 0x100 bytes, and sets arg1 as owner if non-null.
// @fnv 0x00b7fa40
// src: COMMUNITY 0x00b7fa40
SpawnedObject* SpawnedObject::ShaderBufferData_ShaderBufferData(void* apOwner, void* apName, unsigned int auiKey)
{
    m_100 = auiKey;
    if (auiKey != 0)
    {
        if (apName != 0)
        {
            void* found = DAT_011f6238.Find(auiKey);
            m_104 = found;
            FNVRegisterEntry(found, apName, m_100);
            goto done;
        }
    }
    m_104 = 0;
done:
    FNVClearRange(this, 0, 0x100);
    if (apOwner != 0)
    {
        FNVSetOwner(this, 0x100, apOwner);
    }
    return this;
}
}  // namespace fnv_00b7fa40
