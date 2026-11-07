
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00658260_D
{
    int unk00;
    int unk04;
};
struct S_00658260_E
{
    int unk00;
    int unk04;
};
struct S_00658260_F
{
    int unk00;
};
struct S_00658260_H
{
    int unk00;
};
struct S_00658260_G
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S_00658260_A
{
    S_00658260_A(int a, int b);
    S_00658260_A(const S_00658260_A& o);
    ~S_00658260_A();
    void Attach(void* p);
    int unk00;
    int unk04;
};

struct S_00658260_B
{
    void Begin(S_00658260_D* d, int v);
    bool Next(S_00658260_F* f);
    float* Value();
    int unk00;
    int unk04;
};

struct S_00658260_C
{
    void Begin(S_00658260_E* e, int v);
    float* Slot();
    int unk00;
    int unk04;
};

struct S_00658260_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m18;
    int m1c;

    void InitB(S_00658260_B* b);
    S_00658260_F* GetF(S_00658260_F* f);

    S_00658260_A BuildScaledValues(float scale);
};

// Iterates x over GetF(&info), writes each value times scale into it.Slot(), and returns a copy of a built from m18 and m1c.
// @fnv 0x00658260
S_00658260_A S_00658260_Owner::BuildScaledValues(float scale)
{
    S_00658260_F info;
    S_00658260_H obj;
    S_00658260_E arr;
    S_00658260_D ent;
    S_00658260_B x;
    S_00658260_A a(m18, m1c);
    S_00658260_G aa;
    S_00658260_C it;
    for (InitB(&x), a.Attach(&it); x.Next(GetF(&info)); x.Begin(&ent, 0), it.Begin(&arr, 0))
    {
        *it.Slot() = (float)(*x.Value() * scale);
    }
    return a;
}

struct Cursor
{
    void* unk00;
    void* unk04;
};

struct Iterator
{
    void* unk00;
    void* unk04;
    void CopyPairTo(Cursor* pos, int flags);
    bool IsNotIdentical(void* handle);
    float* ForwardCall_0064dbd0();
};

class Mgr
{
  public:
    void SetIteratorDataAndOwner(Iterator* iter);
    void* CallWithSelf(Cursor* key);
    Mgr* ScaleAll(float scale);
};

// Iterates over the manager's entries and multiplies each entry's float value by scale, returning this.
// @fnv 0x00658650
Mgr* Mgr::ScaleAll(float scale)
{
    Iterator iter;
    Cursor key;
    Cursor currentPos;
    for (this->SetIteratorDataAndOwner(&iter); iter.IsNotIdentical(this->CallWithSelf(&key)); iter.CopyPairTo(&currentPos, 0))
    {
        *iter.ForwardCall_0064dbd0() *= scale;
    }
    return this;
}

struct A87A0Element
{
    void* m_pMatrix;
    unsigned int m_uiPosition;

    float& Ref();
};

class A87A0Matrix
{
  public:
    A87A0Matrix(unsigned int uiRows, unsigned int uiCols);
    A87A0Matrix(const A87A0Matrix& kOther);
    ~A87A0Matrix();

    A87A0Element At(unsigned int uiRow, unsigned int uiCol);

    A87A0Matrix Transpose();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned int m_uiRows;
    unsigned int m_uiCols;
};

// Builds a matrix with rows and columns swapped and copies each element from At(i, j) into At(j, i).
// @fnv 0x006587a0
A87A0Matrix A87A0Matrix::Transpose()
{
    A87A0Matrix kResult(m_uiCols, m_uiRows);
    for (unsigned int i = 0; i < m_uiRows; i++)
    {
        for (unsigned int j = 0; j < m_uiCols; j++)
            kResult.At(j, i).Ref() = At(i, j).Ref();
    }
    return kResult;
}
