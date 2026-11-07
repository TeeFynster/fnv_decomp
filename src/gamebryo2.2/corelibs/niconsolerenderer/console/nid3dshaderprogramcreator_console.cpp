
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FakeDevice
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual long __stdcall CreateVertexShader(const unsigned long* pFunction, void** ppShader);
};
extern FakeDevice* DAT_0126fa28;
int __cdecl NiShaderFactory_ReportError(int, int, const char*, long);
// Creates a vertex shader via DAT_0126fa28; on failure logs an error with the HRESULT and returns 0, otherwise returns the shader pointer.
// @fnv 0x00e98890
void* __stdcall CreateVertexShaderChecked(void* pShaderBytecode, void* pUnused, unsigned int uiUnused, void* pUnused2,
                                          unsigned int uiUnused2, unsigned int uiUnused3)
{
    long hr = DAT_0126fa28->CreateVertexShader((const unsigned long*)pShaderBytecode, (void**)&pShaderBytecode);
    if (hr < 0)
    {
        NiShaderFactory_ReportError(1, 0, "Failed to create vertex shader\nError 0x%08x\n", hr);
        return 0;
    }
    return pShaderBytecode;
}

struct GeometryRelatedType;

struct PixelShaderDevice : FakeDevice
{
    virtual void f92() = 0;
    virtual void f93() = 0;
    virtual void f94() = 0;
    virtual void f95() = 0;
    virtual void f96() = 0;
    virtual void f97() = 0;
    virtual void f98() = 0;
    virtual void f99() = 0;
    virtual void f100() = 0;
    virtual void f101() = 0;
    virtual void f102() = 0;
    virtual void f103() = 0;
    virtual void f104() = 0;
    virtual void f105() = 0;
    virtual long __stdcall CreatePixelShader(const unsigned long*, GeometryRelatedType**);
};

// Creates a pixel shader from pvCode via DAT_0126fa28, logging an error and returning 0 on failure.
// @fnv 0x00e988d0
// src: GAMEBRYO_LIB 0x00e988d0
GeometryRelatedType* __stdcall NiD3DShaderProgramCreator_CreatePixelShader(void* pvShaderCode)
{
    GeometryRelatedType* hShader;
    long m_kResult =
        ((PixelShaderDevice*)DAT_0126fa28)->CreatePixelShader((const unsigned long*)pvShaderCode, &hShader);
    if (m_kResult < 0)
    {
        NiShaderFactory_ReportError(1, 0, "Failed to create pixel shader\nError 0x%08x\n", m_kResult);
        return 0;
    }
    return hShader;
}
