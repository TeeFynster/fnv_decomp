
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* DAT_010173f0;
struct FUN_0044a500_s
{
    FUN_0044a500_s* CallAndReturnSelf(int);
    void fopen_0044a730(char, int);
    int AssignSubstring(int, int, void*);
    FUN_0044a500_s* InitializeFields_0044a500(int);
};
// @fnv 0x0044a500
// src: GUESS 0x0044a500 (confidence: low)
FUN_0044a500_s* FUN_0044a500_s::InitializeFields_0044a500(int a)
{
    CallAndReturnSelf(a);
    fopen_0044a730(0, 0);
    AssignSubstring(a, 0, DAT_010173f0);
    return this;
}

class FUN_00ec78e0
{
  public:
    FUN_00ec78e0();
    virtual ~FUN_00ec78e0();
    int unk04[2];
};

class FUN_0044a500
{
  public:
    FUN_0044a500(void* pArg);
    int unk00;
};

class FUN_0044a310 : public FUN_00ec78e0
{
  public:
    FUN_0044a500 m_kMember;

    FUN_0044a310(void* pArg);
    virtual ~FUN_0044a310();
};

// Initializes the m_kMember field with the provided pArg pointer.
// @fnv 0x0044a310
FUN_0044a310::FUN_0044a310(void* pArg) : m_kMember(pArg)
{}
