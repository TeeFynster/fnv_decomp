#pragma once

class FinishingFlag
{
public:
    FinishingFlag() : m_bFinishing(0) {}
    explicit FinishingFlag(int value) : m_bFinishing(value) {}

    int m_bFinishing;
};
