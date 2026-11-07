#pragma once

#pragma pack(push, 4)
template <class T, unsigned int Capacity> class Stack
{
public:
    T items[Capacity];
    int top;

    // Operand-stack helpers called by ExpressionEvaluator::Eval (0x00593db0); no PC names known.
    void AddEntry(T value);
    T PopEntry();
    int Stack_ExpressionOperand_32_empty();
    void ResetField();
};
#pragma pack(pop)
