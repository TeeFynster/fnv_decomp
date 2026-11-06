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
    float FUN_00507da0(float, float, float, bool);
    float FUN_00821640();
    float FUN_00821660();
    float GetFloatAt144();
    float GetValue();
    float FUN_00567470();
    float FUN_00821680();
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
    List* FUN_0043c490();
    int FUN_0044ddc0();
    Ref* Target();
    int Radius();
    void* Resolve();
};
