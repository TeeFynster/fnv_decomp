#pragma once

class NiFixedString;
class NiAVObject;
class NiRefObject;
class NiObjPtr;
struct MapItem;

class NiTFixedStringMap_NiAVObject___
{
public:
    void* m_baseData0;
    void* m_baseData1;

    void GetNext(void*& position, NiFixedString& key, NiAVObject*& value);
    __declspec(noalias) void GetNext(void*& position, NiFixedString& key, NiAVObject*& value) const;
    void GetNextEntry(MapItem*& position, NiFixedString& key, NiObjPtr& value);
    MapItem* NiTMapIterator_GetFirstPos();
    bool Lookup(unsigned int* key, NiRefObject** value);
    bool GetAt(const NiFixedString& key, NiAVObject*& value);
    void RemoveAll();
    void* Destroy(int flags);
};
