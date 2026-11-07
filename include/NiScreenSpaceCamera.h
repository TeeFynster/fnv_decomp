#pragma once

#include "NiCamera.h"

class NiScreenSpaceCamera : public NiCamera
{
  public:
    template <class T> class Array
    {
      public:
        Array(unsigned short maxSize, unsigned short growBy);
        virtual ~Array() throw();

        union
        {
            T* m_pBase;
            void* m_pData;
        };
        unsigned short m_usMaxSize;
        union
        {
            unsigned short m_usSize;
            unsigned short m_usElementCount;
        };
        unsigned short m_usESize;
        unsigned short m_usGrowBy;
    };

    template <class T> class PrimitiveArray : public Array<T>
    {
      public:
        PrimitiveArray(unsigned short maxSize, unsigned short growBy);
        virtual ~PrimitiveArray() throw();

        void FUN_00a2e620() throw();
        void AssignElement(unsigned int index, unsigned int* element) throw();
        void FUN_00a90980(unsigned int index, unsigned int* element) throw();
    };

    NiScreenSpaceCamera();
    virtual ~NiScreenSpaceCamera();

    void __thiscall FUN_00a915d0();
    void* __thiscall FUN_00a91e60(unsigned int flags);
    NiScreenSpaceCamera* __thiscall NiScreenSpaceCamera_00a91d80();

    PrimitiveArray<void*> m_kObjectPointers;
    PrimitiveArray<float> m_kFloatValues;

    PrimitiveArray<void*>& GetObjectPointers() { return m_kObjectPointers; }
    PrimitiveArray<float>& GetFloatValues() { return m_kFloatValues; }
    __declspec(property(get=GetObjectPointers)) PrimitiveArray<void*> m_arr1;
    __declspec(property(get=GetFloatValues)) PrimitiveArray<float> m_arr2;
};
