// Unit-private model loader and time declarations.
#ifndef FNV_MAGICMODELHITEFFECT_DECLS_H
#define FNV_MAGICMODELHITEFFECT_DECLS_H

struct NiRTTI;
class NiProperty;
class SkyShaderProperty;
class NiTimeController;
class NiNode;

class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};

class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    void QueueModelLoad(const char*, bool, unsigned int);
};

extern ModelLoader* g_modelLoader;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern NiRTTI DAT_011f36ac;
SkyShaderProperty* __cdecl NiObject_DynamicCast(const NiRTTI*, NiProperty*);
NiAVObject* __cdecl LoadAndCloneModel(const char*);
void __cdecl BSUtilities_ProcessSelectiveUpdate(NiAVObject*);
extern const char kMagicModelHitEffectName[];
#endif
