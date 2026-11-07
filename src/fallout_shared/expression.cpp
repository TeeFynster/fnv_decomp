// fallout_shared/expression.cpp: ExpressionConverter (10 functions)

#include "expression_decls.h"
#include "ExpressionEvaluator.h"

// Initializes the character and operand stacks and sets the error state to zero.
// @fnv 0x00593490
ExpressionEvaluator::ExpressionEvaluator()
{
    reinterpret_cast<ExpressionCharStackInit*>(&m_kOperatorStack)->Stack_enum_EXPRESSION_OPERATORS_64_Stack_enum_EXPRESSION_OPERATORS_64();
    reinterpret_cast<ExpressionOperandStackInit*>(&m_kOperandStack)->InitStack();
    m_eExpressionError = static_cast<EXPRESSION_ERROR>(0);
}

// @fnv 0x00594b60
// src: XBOX_PDB 0x00594b60
void* __fastcall Stack_enum_EXPRESSION_OPERATORS_64_Stack_enum_EXPRESSION_OPERATORS_64(void* pThis)
{
    *(int*)((char*)pThis + 0x100) = -1;
    return pThis;
}

struct Dummy_00594c60
{
    char pad[0x200];
    int top;
    Dummy_00594c60* __thiscall ctor();
};

__declspec(noinline) Dummy_00594c60* __thiscall Dummy_00594c60::ctor()
{
    this->top = -1;
    return this;
}

// @fnv 0x00594c60
int __fastcall InitStack(Dummy_00594c60* _this)
{
    _this->top = -1;
    return (int)_this;
}

struct FUN_00594b80_shell
{
    void PushInt(int arg);
};

// Increments the counter at index 0x40 and stores arg at the slot indexed by the new counter value.
// @fnv 0x00594b80
void FUN_00594b80_shell::PushInt(int aiValue)
{
    ++((int*)this)[0x40];
    ((int*)this)[((int*)this)[0x40]] = aiValue;
}

struct FUN_00594c40_shell
{
    void ResetIndex();
};

// @fnv 0x00594c40
void FUN_00594c40_shell::ResetIndex()
{
    *(int*)((char*)this + 0x100) = 0xffffffff;
}

// Exe 0x005934d0: unit-local Interface view; declarations and layout are preserved.
struct ExpressionInterfaceView
{
    static void __cdecl PrintDebugMessage(char const*, ...);
};
extern char const* g_expressionErrorStrings[];
struct Holder5934d0
{
    int err;
    void SetError(int);
};
// @fnv 0x005934d0
void Holder5934d0::SetError(int aiErrorCode)
{
    err = aiErrorCode;
    ExpressionInterfaceView::PrintDebugMessage("%s", g_expressionErrorStrings[aiErrorCode]);
}

struct FUN_00594c00_shell
{
    int Expression_Operands_IsEmpty();
};

// @fnv 0x00594c00
// src: COMMUNITY 0x00594c00
int FUN_00594c00_shell::Expression_Operands_IsEmpty()
{
    return *(int*)((char*)this + 0x100) == -1;
}

struct FUN_00594c20_shell
{
    char pad[0x100];
    int m_100;
    bool Expression_Operands_IsFull();
};

// @fnv 0x00594c20
// src: COMMUNITY 0x00594c20
bool FUN_00594c20_shell::Expression_Operands_IsFull()
{
    return m_100 + 1 == 0x40;
}

struct S_00594bc0
{
    int unk00[64];
    int unk100;

    int Expression_Operands_Pop();
};

// Returns the int at unk00 indexed by unk100, then decrements unk100.
// @fnv 0x00594bc0
// src: COMMUNITY 0x00594bc0
int S_00594bc0::Expression_Operands_Pop()
{
    return unk00[unk100--];
}

extern void* __cdecl memcpy(void*, const void*, unsigned int);
extern unsigned int __cdecl BSStringLength(const char*);
struct OperatorInfo
{
    signed char priority;
    char text[7];
};
extern OperatorInfo DAT_0118cad4[];
struct OpStack
{
    int items[64];
    int top;
    void clear();
    int empty();
    int full();
    int pop();
    void push(int);
};
struct OperandValue
{
    int type;
    int metadata;
    double value;
};
struct OperandStack
{
    OperandValue items[32];
    int top;
    void clear();
};
struct ExpressionConverter
{
    int error;
    char infix[512];
    char postfix[512];
    OpStack operators;
    OperandStack operands;
    void setError(int);
    int next(char**, char*, int*, int, int);
    char* ConvertToPostfix(const char*, unsigned int*);
};
// Converts the infix expression in data to postfix in postfix using an operator stack, returning postfix and setting length, or 0 on error.
// @fnv 0x00593500
char* ExpressionConverter::ConvertToPostfix(const char* pInfix, unsigned int* puiLength)
{
    char token[64];
    {
        int count2 = 0;
        bool operand5;
        error = 0;
        operators.clear();
        operands.clear();
        char* input = infix;
        char bracket = '(';
        *input = bracket;
        input++;
        memcpy(input, pInfix, *puiLength);
        input += *puiLength;
        bracket = ')';
        *input = bracket;
        input++;
        *input = 0;
        input++;
        input = infix;
        char* output2 = postfix;
        *output2 = 0;
        operand5 = false;
        int kind_;
        do
        {
            kind_ = 16;
            count2 = next(&input, token, &kind_, 0, 0);
            if (count2)
            {
                if (kind_ < 16)
                {
                    switch (kind_)
                    {
                    case 0:
                        if (!operators.full())
                            operators.push(0);
                        else
                        {
                            setError(2);
                            return 0;
                        }
                        break;
                    case 1:
                        if (!operators.empty())
                        {
                            int popped;
                            while (popped = operators.pop())
                            {
                                *output2 = ' ';
                                output2++;
                                int textLength = BSStringLength(DAT_0118cad4[popped].text);
                                memcpy(output2, DAT_0118cad4[popped].text, textLength);
                                output2 += textLength;
                            }
                        }
                        else
                        {
                            setError(5);
                            return 0;
                        }
                        break;
                    case 10:
                        if (!operand5)
                            kind_ = 15;
                    default:
                        while (!operators.empty())
                        {
                            int popped = operators.pop();
                            if (DAT_0118cad4[popped].priority >= DAT_0118cad4[kind_].priority)
                            {
                                *output2 = ' ';
                                output2++;
                                int textLength = BSStringLength(DAT_0118cad4[popped].text);
                                memcpy(output2, DAT_0118cad4[popped].text, textLength);
                                output2 += textLength;
                            }
                            else
                            {
                                operators.push(popped);
                                break;
                            }
                        }
                        if (!operators.full())
                            operators.push(kind_);
                        else
                        {
                            setError(2);
                            return 0;
                        }
                        break;
                    }
                }
                else
                {
                    *output2 = ' ';
                    output2++;
                    memcpy(output2, token, count2);
                    output2 += count2;
                }
            }
            if (kind_ == 16)
                operand5 = true;
            else if (kind_ < 16 && kind_ > 1)
                operand5 = false;
        } while (count2);
        *output2 = 0;
        if (!operators.empty())
        {
            setError(5);
            return 0;
        }
        else
        {
            *puiLength = output2 - postfix;
            return postfix;
        }
    }
}
