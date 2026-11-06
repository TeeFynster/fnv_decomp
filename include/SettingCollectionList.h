#pragma once

template <class T> class BSSimpleList;
template <class T> class NiTPrimitiveArray;

template <class T>
class SettingCollectionList
{
public:
    SettingCollectionList();
    ~SettingCollectionList();

    void Add(T* setting);
    void Remove(T* setting);
    unsigned int GetViewerStrings(NiTPrimitiveArray<char*>* strings);
    bool WriteAllSettings();
    bool ReadAllSettings();
    bool Get(const char* key, T*& result);
    T* GetPtr(const char* key);
    BSSimpleList<T*>* Head();
    BSSimpleList<T*>* Next(BSSimpleList<T*>* position);
};
