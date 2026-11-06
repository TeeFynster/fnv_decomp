#pragma once

struct hkpConstraintInfo
{
public:
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;

    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }

    void add(int iSchemaSize, int iNumSolverResults, int iNumSolverElemTemps)
    {
        m_iSchemaByteSize += iSchemaSize;
        m_iSolverResultCount += iNumSolverResults;
        m_iSolverElementTemporaryCount += iNumSolverElemTemps;
    }
};
