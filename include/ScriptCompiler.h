#pragma once

class CStringArgument;
class Script;
class ScriptLineBuffer;
class TESObjectREFR;
enum COMPILER_NAME;

class ScriptCompiler
{
public:
    ScriptCompiler();

    bool CompilePartialScript(Script* script, TESObjectREFR* ownerObject, COMPILER_NAME compilerIndex, bool flag);
    bool Compile_005aeb90(Script*, CStringArgument*);
    unsigned int ParseLine(CStringArgument*);
    bool VerifyBlocks(CStringArgument*);
    bool ScriptCompiler_CompileLine(Script*, CStringArgument*, ScriptLineBuffer*);
};
