#pragma once

#include "NiRefObject.h"
#include "NiTFixedStringMap.h"

class NiGlobalConstantEntry;

class NiRenderer;
class RefCountedNamedObject;
class ShaderForUnload;

class NiShaderFactory : public NiRefObject
{
public:
    virtual ~NiShaderFactory();
    virtual ShaderForUnload* Create(const char*, int, int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual RefCountedNamedObject* v14();
    virtual RefCountedNamedObject* v15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();

    static NiShaderFactory* __cdecl GetInstance();

    NiTFixedStringMap<NiGlobalConstantEntry*> m_kGlobalConstantEntryMap;
    bool (__cdecl* m_pFindGlobalConstantEntry)(const char*, NiRenderer*, int, char**, bool,
                                               RefCountedNamedObject**);
    unsigned int (__cdecl* GlobalConstantEntryRegistry)(const char*, NiRenderer*, const char*, bool);
    unsigned int (__cdecl* GlobalConstantMapContext)(const char*, unsigned int, bool);

protected:
    static NiShaderFactory* ms_pShaderFactory;
};
