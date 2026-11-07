
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct InputValues
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int first;
    unsigned int second;
    unsigned long long __thiscall GetValue64();
};
struct Controller
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual bool valid(unsigned long long values);
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual int index(unsigned long long values);
};
struct FUN_00c3fca0_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    long* unk54;
    volatile long unk58;
    bool __thiscall BSTaskManager_int64_RemoveTask(InputValues* input);
};
extern long __cdecl FUN_004019a0(volatile long*);
// @fnv 0x0044e050
// src: COMMUNITY 0x0044e050
bool __thiscall FUN_00c3fca0_Class::BSTaskManager_int64_RemoveTask(InputValues* input)
{
    int item = ((Controller*)this)->index(input->GetValue64());
    if (((Controller*)this)->valid(input->GetValue64()))
    {
        FUN_004019a0(unk54 + item);
        FUN_004019a0(&unk58);
        return true;
    }
    return false;
}
