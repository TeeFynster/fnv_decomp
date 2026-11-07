#pragma once

namespace ActorValue
{
    enum Index;
}

class List;
class Ref;
class RefObj;
class Texture;
class V;

class Data
{
public:
    ActorValue::Index eReqSkill;
    union
    {
        int iReqSkillLevel;
        struct
        {
            unsigned short m_04;
            short pad;
        };
    };
    union
    {
        struct
        {
            unsigned int uiCategoryID;
            unsigned int uiSubCategoryID;
        };
        RefObj* m_08;
    };

    Data();
    ~Data();

    static void* operator new(unsigned int);

    void Load(unsigned int);
    float TESEffectShader_BirthParticles(float, float, float, bool);
    float TESObjectWEAP_GetShotsPerSecond();
    float GetFootWeight();
    float GetFloatAt144();
    float GetValue();
    float TESEffectShader_GetAddOnScaleStart();
    float TESObjectWEAP_GetFiringRumbleRightMotorStrength();
    void UpdateShaderState(Texture*, float, float, float, bool);
    void FUN_00680110(void*);
    void FUN_00403550(int);
    int FUN_00519b00();
    V* FUN_00680020();
    V* FUN_00680050();
    V* FUN_00680080();
    int GetLength();
    void GetData(char*);
    void** FUN_006815c0();
    List* GetTranslate_0043c490();
    int FUN_0044ddc0();
    Ref* Target();
    int Radius();
    void* Resolve();
};
