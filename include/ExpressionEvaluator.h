#pragma once

#include "ExpressionValue.h"

class TESObjectREFR;
class Script;
class ScriptLocals;

#include "EXPRESSION_ERROR.h"

#include "ExpressionOperator.h"

#pragma pack(push, 4)
#include "Stack.h"

class ExpressionEvaluator
{
public:
    EXPRESSION_ERROR m_eExpressionError;
    char m_sExpression[512];
    char m_sExpressionBuffer[512];
    Stack<ExpressionOperator, 64> m_kOperatorStack;
    Stack<ExpressionValue, 32> m_kOperandStack;

    ExpressionEvaluator();
    ~ExpressionEvaluator();
    double Eval(const char* data, TESObjectREFR* reference, TESObjectREFR* container,
                Script* script, ScriptLocals* locals, int length, bool skip);
    EXPRESSION_ERROR ExpressionError();
    void SetError(EXPRESSION_ERROR error);
    int ParseToken(char** expression, char* token, ExpressionOperator* operation,
                   bool unary, const char** next);
};
#pragma pack(pop)
