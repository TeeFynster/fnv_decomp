#include "../../include/BSStringT.h"

// tesobjectrefr_ctx2_variant.cpp: context variant of src/fallout_shared/tesobjectrefr.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesobjectrefr_decls.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
GarbageCollectorUpdateState* MemoryLevelManager_GetSingleton();
void* DecalData_GetDefaultDecalData();
void FalloutRadio_NewCellEntered();
void TESWaterSystem_SetPlayerForceUnderwater(unsigned char value);
float BSAudio_GetMinDialogDist();
float BSAudio_GetMaxDialogDist();
void CheckWithinMultiBoundTask_CancelAttachment(unsigned int index);

extern "C" void* __cdecl _alloca(unsigned int);
struct LoadFile
{
    unsigned int Size();
    bool Read(void*, unsigned int);
    bool ReadID(unsigned int*);
    bool Special();
    int Chunk();
    bool Next();
};
struct VecLoad
{
    float x, y, z;
};
struct TransformLoad
{
    VecLoad position, rotation;
    TransformLoad();
    void Convert();
};
struct ScriptInfoLoad
{
    int unk00, unk04, unk08;
};
struct ScriptLoad
{
    ScriptInfoLoad* Info();
    int Text();
    unsigned char Compiled();
};
struct ExtraLoad
{
    void* Cell();
    void Clear(bool);
    void InitializeForCell(void*);
    void Load(LoadFile*, void*);
    struct PatrolLoad* Patrol();
};
struct PatrolLoad
{
    ScriptLoad* Script();
};
struct SaveLoadState
{
    bool Active();
};

struct DataLoad
{
    bool Contains(unsigned int);
};

extern SaveLoadState* g_BGSSaveLoadGame;
extern DataLoad* g_dataHandler;
void ResolveID(unsigned int*, LoadFile*);
TESForm* LookupForm(unsigned int);
void WarnLoad(const char*, ...);

int FormatLoad(BSStringT<char>*, const char*, ...);
struct RefLoad
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void Reset3D(int);
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void LoadBounds(LoadFile*);
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* EditorID();
    virtual void SetEditorID(char*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    TESBoundObject* base;
    VecLoad rotation, position;
    unsigned int scale;
    int unk40;
    ExtraLoad extras;
    void ClearFlags(int);
    void LoadHeader(LoadFile*);
    bool Deleted();
    void Cleanup();
    void* GetParent();
    ExtraLoad* Extra();
    void Mark(int);
    unsigned int ID();
    bool TESObjectREFR_Load(LoadFile* file);
};
// @fnv 0x0055af90
// src: XBOX_PDB 0x0055af90
bool RefLoad::TESObjectREFR_Load(LoadFile* file)
{
    int chunkID = 0;
    TransformLoad initial4;
    ClearFlags(0);
    bool failed = false;
    bool hasBaseTmp = false;
    bool reuse = false;
    unsigned int baseIDA = 0;
    LoadHeader(file);
    ClearFlags(0);
    if (Deleted())
    {
        void* cell = extras.Cell();
        if (!g_BGSSaveLoadGame || !((SaveLoadState*)g_BGSSaveLoadGame)->Active())
            Cleanup();
        extras.Clear(true);
        if (cell)
            extras.InitializeForCell(cell);
        return GetParent() != 0;
    }
    while (reuse || (chunkID = file->Chunk()) != 0)
    {
        reuse = false;
        switch (chunkID)
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(file->Size());
            file->Read(editor, 512);
            SetEditorID(editor);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x41505058:
        case 0x42475258:
        case 0x424c4758:
        case 0x424d4c58:
        case 0x434d4158:
        case 0x434f4c58:
        case 0x43524d58:
        case 0x44415258:
        case 0x44455358:
        case 0x44475258:
        case 0x444f4c58:
        case 0x444f5058:
        case 0x44504158:
        case 0x44524f58:
        case 0x44525058:
        case 0x44525358:
        case 0x45535558:
        case 0x46525358:
        case 0x47484358:
        case 0x47525458:
        case 0x49435058:
        case 0x494d4558:
        case 0x49525458:
        case 0x4b4e5258:
        case 0x4b524d41:
        case 0x4b524d4d:
        case 0x4b524d58:
        case 0x4c444558:
        case 0x4c455458:
        case 0x4c4f5358:
        case 0x4c535058:
        case 0x4c545058:
        case 0x4d414e52:
        case 0x4d434358:
        case 0x4d434c58:
        case 0x4d494358:
        case 0x4d495458:
        case 0x4d4c4358:
        case 0x4d525058:
        case 0x4d545258:
        case 0x4e535058:
        case 0x4e574f58:
        case 0x4e5a4558:
        case 0x4f424d58:
        case 0x4f445258:
        case 0x4f4d4358:
        case 0x4f4f5258:
        case 0x4f544158:
        case 0x50424d58:
        case 0x50434f58:
        case 0x50444e58:
        case 0x504c4358:
        case 0x504c4858:
        case 0x50534558:
        case 0x50564e58:
        case 0x52424d58:
        case 0x52434158:
        case 0x52434458:
        case 0x524b4c58:
        case 0x524c4358:
        case 0x524d5258:
        case 0x52504158:
        case 0x52575058:
        case 0x53414358:
        case 0x53424958:
        case 0x53445258:
        case 0x53524858:
        case 0x54434158:
        case 0x54454358:
        case 0x544c4858:
        case 0x544c5758:
        case 0x544d4158:
        case 0x544d4358:
        case 0x544e4358:
        case 0x54574358:
        case 0x57544c58:
            Extra()->Load(file, this);
            break;
        case 0x4c435358:
            file->ReadID(&scale);
            break;
        case 0x454d414e: {
            hasBaseTmp = true;
            file->ReadID(&baseIDA);
            ResolveID(&baseIDA, file);
            TESForm* form3 = LookupForm(baseIDA);
            TESBoundObject* bound5 = dynamic_cast<TESBoundObject*>(form3);
            bool replace = true;
            if (base && ((SaveLoadState*)g_BGSSaveLoadGame)->Active() &&
                ((DataLoad*)g_dataHandler)->Contains(base->ID()))
                replace = false;
            if (replace)
            {
                base = bound5;
                if (!base)
                {
                    WarnLoad("MASTERFILE: Missing/Invalid base object (%08X) for reference (%08X)", baseIDA, ID());
                    failed = true;
                    hasBaseTmp = false;
                }
            }
            break;
        }
        case 0x524c4352:
            break;
        case 0x4d414e4f:
            Mark(8);
            break;
        case 0x41544144:
            if (!failed)
            {
                TransformLoad transform;
                Reset3D(0);
                file->Read(&transform, 24);
                if (file->Special())
                    transform.Convert();
                position = transform.position;
                rotation = transform.rotation;
            }
            break;
        default:
            WarnLoad("MASTERFILE: TESObjectREFR::Load abnormally terminated.\n\n");
            chunkID = 0x41544144;
        }
        if (!file->Next())
            break;
    }
    PatrolLoad* patrolTmp = Extra()->Patrol();
    if (patrolTmp)
    {
        ScriptLoad* script = patrolTmp->Script();
        if (script && !script->Info()->unk08 && script->Text() && !script->Compiled())
        {
            BSStringT<char> warning;
            FormatLoad(&warning, "Patrol point event script for point %s has text but has not been compiled.",
                       EditorID());
            WarnLoad(warning);
        }
    }
    return base != 0;
}
