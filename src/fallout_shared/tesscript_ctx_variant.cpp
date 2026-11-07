
// tesscript_ctx_variant.cpp: context variant of src/fallout_shared/tesscript.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesscript_decls.h"
// TESFileFormInt_tesscript: local type (was include/TESFileFormInt.h, which had no evidence of one real class); its methods are 0x00472660 TESFile::GetTESForm
class TESFileFormInt_tesscript
{
public:
    int GetTESForm();
};

class ScriptLoader : public Script
{
  public:
    bool Script_Load(TESFile* file);
};

// @fnv 0x005ab9f0
// src: XBOX_PDB 0x005ab9f0
bool ScriptLoader::Script_Load(TESFile* file)
{
    ScriptVariableInfo* chunk = 0;
    unsigned int reference;
    char* variable;
    int size;
    char* variableName;
    unsigned int unusedID;
    ScriptReferencedObject* referenceID;
    unsigned int editorID;
    if (reinterpret_cast<TESFileFormInt_tesscript*>(file)->GetTESForm() != ENUM_FORM_ID_SCPT_ID)
        return false;
    LoadRecordHeader(file);
    while (size = file->GetChunkID())
    {
        switch (size)
        {
        case 0x44494445:
            variable = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(variable, 0x200);
            SetEditorID_AtRuntime(variable);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x52484353:
            file->GetChunkData(&m_kHeader, 0);
            if (file->IsEndianConversionRequired())
                m_kHeader.Endian();
            break;
        case 0x44534c53:
            chunk = new ScriptVariableInfo;
            chunk->Load(file);
            GetVariableList()->AddTail(chunk);
            break;
        case 0x52564353:
            if (chunk)
            {
                variableName = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(variableName, 0x200);
                chunk->name.Set(variableName, 0);
            }
            break;
        case 0x41444353:
            reference = file->GetChunkSize();
            m_data = AllocateZeroed(1, reference);
            memset(m_data, 0, reference);
            file->GetChunkData(m_data, 0);
            break;
        case 0x4f524353:
        case 0x56524353:
            referenceID = new ScriptReferencedObject;
            file->GetChunkData(&unusedID);
            if (size == 0x4f524353)
                referenceID->pForm = (TESForm*)unusedID;
            else
                referenceID->m_uiFormID = unusedID;
            GetReferencedObjectList()->AddTail(referenceID);
            break;
        case 0x54584353:
            break;
        case 0x44484353:
            break;
        case 0x4d414e52:
            file->GetChunkData(&editorID);
        }
        if (!file->NextChunk())
            break;
    }
    if (!m_data)
        Warning("MASTERFILE: Script '%s' in file '%s' has not been compiled.\r\n", GetName(), file->GetFilename());
    return true;
}
