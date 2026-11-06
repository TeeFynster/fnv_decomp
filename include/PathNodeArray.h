#pragma once

class PathNode;

class PathNodeArray
{
public:
    PathNodeArray();
    ~PathNodeArray();

    void Clear(bool abFree);
    unsigned int GetSize();
    unsigned int Size();
    PathNode*& GetAt(unsigned int uiIndex);
    PathNode& GetAt(int i);

    PathNode** m_data;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;
    unsigned int m_10;
};
