
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nid3dshaderconstantmap_decls.h"
void BuildTransformMatrix(float* d, const NiMatrix3& r, const NiPoint3& t, float s);
struct NiShaderConstantMap
{
    static bool __cdecl FindConstantMapping(char const*, unsigned int&, unsigned int&);
};
unsigned int __cdecl NiShaderConstantMap_LookUpPredefinedMappingType_(unsigned int, unsigned int);
unsigned int __cdecl NiShaderConstantMap_LookUpPredefinedMappingType(const char* name);
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126f7c4;
GlobalObjectO2_00a7b610* __cdecl NiD3DShaderConstantMap_GetRTTI();
void __fastcall UpdateMatrix(void*);
char* __fastcall NiTextureTransform_GetMatrix(char* self);
void* __fastcall NiD3DShaderConstantMap_GetEntryAtIndex(char* self, int unused, unsigned int i);
struct FUN_00e82ac0_e
{
    char pad[0xc];
    unsigned int key;
    void* p10;
    unsigned int flags;
    char pad2[8];
    unsigned int v20;
};
extern unsigned char DAT_011f5fb4[];
bool __cdecl LookupShaderConstantMapping(unsigned int, void*&);
unsigned int __cdecl GetAttributeTypeForMapping(void*, unsigned int*, unsigned int*);
unsigned int __stdcall UpdateEntryFromKey(FUN_00e82ac0_e* e);
void __fastcall FUN_00e81c00(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
void* __fastcall FUN_00e83630(void* self, int unused, unsigned int flags);
struct FUN_00e84b60_prog
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual bool SetConstant(void* entry, const void* data, unsigned int n);
};
const void* __stdcall GetConstantData(void*);
unsigned int __stdcall NiD3DShaderConstantMap_SetConstantConstant(FUN_00e84b60_prog* prog, void* entry, unsigned int pass);
extern char* EmptyFS;
struct RMapEntry
{
    char pad[0xc];
    char* key;
    unsigned int pad3;
    unsigned int flags;
};
struct RMap
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual unsigned int LookupSequenceByKey(const char*);
    char pad[0xc];
    RMapEntry** entries;
    char pad2[0x20];
    volatile unsigned int status;
};
void __cdecl RemoveGlobalConstant(char**);
struct RArr
{
    void NiTObjectArray_NiShaderConstantMapEntry_SetAt(unsigned int, void*);
};
unsigned int __fastcall LookupAndReleaseEntry(RMap* self, int unused, const char* name);
unsigned int __cdecl FUN_00a9bc16();
unsigned int __cdecl FUN_00a9bc1c();
int __cdecl FUN_00a9bc22();
unsigned int __cdecl FUN_00a9bc28();
