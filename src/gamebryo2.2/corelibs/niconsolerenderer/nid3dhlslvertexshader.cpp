// gamebryo2.2/corelibs/niconsolerenderer/nid3dhlslvertexshader.cpp: NiD3DHLSLVertexShader (8 functions)

#include "nid3dhlslvertexshader_decls.h"
#include "../../../../include/NiD3DHLSLVertexShader.h"
// Constructs a NiTPrimitiveArray by forwarding the size and grow arguments to the NiTArray base constructor.
// @fnv 0x00e98db0
template <>
NiTPrimitiveArray<NiD3DShaderProgramCreatorObj*>::NiTPrimitiveArray(unsigned int size, unsigned int grow)
    : NiTArray<NiD3DShaderProgramCreatorObj*, NiTMallocInterface<NiD3DShaderProgramCreatorObj*> >(size, grow)
{}

struct VT_00e89b10
{
    char _pad[0x178];
    int(__stdcall* m_fn)(void*, unsigned int, const float*, unsigned int);
};
struct DEV_00e89b10
{
    VT_00e89b10* vtable;
};
struct CLS_00e89b10
{
    bool CallVtableMethod(unsigned int a1, const float* a2, unsigned int a3, unsigned int a4);
};
// @fnv 0x00e89b10
bool CLS_00e89b10::CallVtableMethod(unsigned int auiArg1, const float* apfArg2, unsigned int auiArg3,
                                    unsigned int auiArg4)
{
    DEV_00e89b10* dev = *(DEV_00e89b10**)((char*)this + 0x10F8);
    return dev->vtable->m_fn(dev, auiArg1, apfArg2, auiArg3) >= 0;
}

struct MyConstTable
{
    virtual void __stdcall Dummy0();
    virtual void __stdcall Dummy1();
    virtual void __stdcall Release();
};
// Releases the held const table if present, clears the pointer, then calls FUN_00e89ac0.
// @fnv 0x00e97210
void __fastcall ReleaseConstTable(NiD3DHLSLVertexShader* pkShader, void*)
{
    if (pkShader->m_pShaderConstantTable)
    {
        ((MyConstTable*)pkShader->m_pShaderConstantTable)->Release();
        pkShader->m_pShaderConstantTable = 0;
    }
    pkShader->NiD3DVertexShader::UnloadShader();
}

struct MyDesc
{
    const char* Creator;
    unsigned int Version;
    unsigned int Constants;
};
struct MyTable
{
    virtual long __stdcall F0();
    virtual long __stdcall F1();
    virtual long __stdcall F2();
    virtual long __stdcall F3();
    virtual long __stdcall F4();
    virtual long __stdcall GetDesc(MyDesc* pDesc);
};
// Returns the shader's Constants from its descriptor, or 0 if the table is null or GetDesc fails.
// @fnv 0x00e97250
unsigned int __fastcall GetConstants(NiD3DHLSLVertexShader* pkShader, void*)
{
    MyDesc kDesc;
    if (!pkShader->m_pShaderConstantTable)
        return 0;
    long hr = ((MyTable*)pkShader->m_pShaderConstantTable)->GetDesc(&kDesc);
    return hr < 0 ? 0 : kDesc.Constants;
}

struct _D3DXCONSTANT_DESC
{
    const char* Name;
    unsigned int f0;
    unsigned int f1;
    unsigned int f2;
    unsigned int f3;
    unsigned int f4;
    unsigned int f5;
    unsigned int f6;
    unsigned int f7;
    unsigned int f8;
    unsigned int f9;
    unsigned int f10;
};
struct ConstTable
{
    virtual int __stdcall f0();
    virtual int __stdcall f1();
    virtual int __stdcall f2();
    virtual int __stdcall f3();
    virtual int __stdcall f4();
    virtual int __stdcall f5();
    virtual int __stdcall GetConstantDescription(unsigned int hConstant, _D3DXCONSTANT_DESC* pDesc,
                                                 unsigned int* pCount);
    virtual int __stdcall f7();
    virtual unsigned int __stdcall GetPlaneConstant(unsigned int hConstant, unsigned int uiIndex);
};
// Looks up the constant handle at uiIndex, queries its descriptor, and returns the descriptor's Name if found, otherwise null.
// @fnv 0x00e97280
const char* NiD3DHLSLVertexShader::GetConstantName(unsigned int uiIndex)
{
    _D3DXCONSTANT_DESC kDesc;
    unsigned int ItemUpdateArray;
    unsigned int hConstant;
    hConstant = ((ConstTable*)m_pShaderConstantTable)->GetPlaneConstant(0, uiIndex);
    if (hConstant)
    {
        ItemUpdateArray = 1;
        if (((ConstTable*)m_pShaderConstantTable)->GetConstantDescription(hConstant, &kDesc, &ItemUpdateArray) >= 0 && ItemUpdateArray != 0)
            return kDesc.Name;
    }
    return 0;
}

void __cdecl FUN_00e89ad0();

// @fnv 0x00e97240
// src: XBOX_PDB 0x00e97240
void __cdecl NiD3DHLSLVertexShader_RecreateRendererData()
{
    FUN_00e89ad0();
}

extern char* DAT_0109b220;
extern unsigned int DAT_011f5fc4[];
extern const char str_010f14a0[];
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl Object_DoNothing(const char*, ...);

struct VS_00e972e0_Str
{
    char* m_kHandle;
    VS_00e972e0_Str& AssignInternedString(const VS_00e972e0_Str& other);
};
struct VS_00e972e0_Desc
{
    const char* Name;
    unsigned int m_uiRegisterSet;
    unsigned int m_uiRegisterIndex;
    unsigned int m_uiRegisterSpan;
    unsigned int Class;
    unsigned int Type;
    unsigned int Rows;
    unsigned int Columns;
    unsigned int Elements;
    unsigned int m_uiStructMembers;
    unsigned int Bytes;
    const void* DefaultValue;
};
struct VS_00e972e0_Table
{
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual void* __stdcall GetBufferPointer();
    virtual unsigned long __stdcall GetBufferSize();
    virtual long __stdcall GetDesc(void*);
    virtual long __stdcall GetConstantDescription(void* hConstant, VS_00e972e0_Desc* pDesc, unsigned int* pCount);
    virtual unsigned int __stdcall GetSamplerRegisterIndex(void*);
    virtual void* __stdcall GetPlaneConstant(void*, unsigned int);
    virtual void* __stdcall FindConstantByName(void*, const char*);
};
struct __declspec(align(16)) VS_00e972e0_Matrix
{
    float _11, _12, _13, _14;
    float _21, _22, _23, _24;
    float _31, _32, _33, _34;
    float _41, _42, _43, _44;
};
VS_00e972e0_Matrix* __stdcall D3DXMatrixTranspose_00ee6dd4(VS_00e972e0_Matrix* pOut, const VS_00e972e0_Matrix* pM);

struct VS_00e972e0_Entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    VS_00e972e0_Str m_kName;
    unsigned int unk10;
    unsigned int m_uiValue1;
    unsigned int unk18;
    unsigned int m_uiValueAt1C;
    unsigned int m_uiValue4;
    VS_00e972e0_Str m_kSecondaryString;
    unsigned int unk28;
    unsigned int unk2c;
    const void* m_pConstantData;
    bool m_bOwnsData;
    bool m_bFlag1;
    void NiShaderConstantMapEntry_SetVariableName(VS_00e972e0_Str& kName);
};
struct VS_00e972e0_Renderer
{
    unsigned int unk0000, unk0004, unk0008, unk000c, unk0010, unk0014, unk0018, unk001c;
    unsigned int unk0020, unk0024, unk0028, unk002c, unk0030, unk0034, unk0038, unk003c;
    unsigned int unk0040, unk0044, unk0048, unk004c, unk0050, unk0054, unk0058, unk005c;
    unsigned int unk0060, unk0064, unk0068, unk006c, unk0070, unk0074, unk0078, unk007c;
    unsigned int unk0080, unk0084, unk0088, unk008c, unk0090, unk0094, unk0098, unk009c;
    unsigned int unk00a0, unk00a4, unk00a8, unk00ac, unk00b0, unk00b4, unk00b8, unk00bc;
    unsigned int unk00c0, unk00c4, unk00c8, unk00cc, unk00d0, unk00d4, unk00d8, unk00dc;
    unsigned int unk00e0, unk00e4, unk00e8, unk00ec, unk00f0, unk00f4, unk00f8, unk00fc;
    unsigned int unk0100, unk0104, unk0108, unk010c, unk0110, unk0114, unk0118, unk011c;
    unsigned int unk0120, unk0124, unk0128, unk012c, unk0130, unk0134, unk0138, unk013c;
    unsigned int unk0140, unk0144, unk0148, unk014c, unk0150, unk0154, unk0158, unk015c;
    unsigned int unk0160, unk0164, unk0168, unk016c, unk0170, unk0174, unk0178, unk017c;
    unsigned int unk0180, unk0184, unk0188, unk018c, unk0190, unk0194, unk0198, unk019c;
    unsigned int unk01a0, unk01a4, unk01a8, unk01ac, unk01b0, unk01b4, unk01b8, unk01bc;
    unsigned int unk01c0, unk01c4, unk01c8, unk01cc, unk01d0, unk01d4, unk01d8, unk01dc;
    unsigned int unk01e0, unk01e4, unk01e8, unk01ec, unk01f0, unk01f4, unk01f8, unk01fc;
    unsigned int unk0200, unk0204, unk0208, unk020c, unk0210, unk0214, unk0218, unk021c;
    unsigned int unk0220, unk0224, unk0228, unk022c, unk0230, unk0234, unk0238, unk023c;
    unsigned int unk0240, unk0244, unk0248, unk024c, unk0250, unk0254, unk0258, unk025c;
    unsigned int unk0260, unk0264, unk0268, unk026c, unk0270, unk0274, unk0278, unk027c;
    unsigned int unk0280, unk0284, unk0288, unk028c, unk0290, unk0294, unk0298, unk029c;
    unsigned int unk02a0, unk02a4, unk02a8, unk02ac, unk02b0, unk02b4, unk02b8, unk02bc;
    unsigned int unk02c0, unk02c4, unk02c8, unk02cc, unk02d0, unk02d4, unk02d8, unk02dc;
    unsigned int unk02e0, unk02e4, unk02e8, unk02ec, unk02f0, unk02f4, unk02f8, unk02fc;
    unsigned int unk0300, unk0304, unk0308, unk030c, unk0310, unk0314, unk0318, unk031c;
    unsigned int unk0320, unk0324, unk0328, unk032c, unk0330, unk0334, unk0338, unk033c;
    unsigned int unk0340, unk0344, unk0348, unk034c, unk0350, unk0354, unk0358, unk035c;
    unsigned int unk0360, unk0364, unk0368, unk036c, unk0370, unk0374, unk0378, unk037c;
    unsigned int unk0380, unk0384, unk0388, unk038c, unk0390, unk0394, unk0398, unk039c;
    unsigned int unk03a0, unk03a4, unk03a8, unk03ac, unk03b0, unk03b4, unk03b8, unk03bc;
    unsigned int unk03c0, unk03c4, unk03c8, unk03cc, unk03d0, unk03d4, unk03d8, unk03dc;
    unsigned int unk03e0, unk03e4, unk03e8, unk03ec, unk03f0, unk03f4, unk03f8, unk03fc;
    unsigned int unk0400, unk0404, unk0408, unk040c, unk0410, unk0414, unk0418, unk041c;
    unsigned int unk0420, unk0424, unk0428, unk042c, unk0430, unk0434, unk0438, unk043c;
    unsigned int unk0440, unk0444, unk0448, unk044c, unk0450, unk0454, unk0458, unk045c;
    unsigned int unk0460, unk0464, unk0468, unk046c, unk0470, unk0474, unk0478, unk047c;
    unsigned int unk0480, unk0484, unk0488, unk048c, unk0490, unk0494, unk0498, unk049c;
    unsigned int unk04a0, unk04a4, unk04a8, unk04ac, unk04b0, unk04b4, unk04b8, unk04bc;
    unsigned int unk04c0, unk04c4, unk04c8, unk04cc, unk04d0, unk04d4, unk04d8, unk04dc;
    unsigned int unk04e0, unk04e4, unk04e8, unk04ec, unk04f0, unk04f4, unk04f8, unk04fc;
    unsigned int unk0500, unk0504, unk0508, unk050c, unk0510, unk0514, unk0518, unk051c;
    unsigned int unk0520, unk0524, unk0528, unk052c, unk0530, unk0534, unk0538, unk053c;
    unsigned int unk0540, unk0544, unk0548, unk054c, unk0550, unk0554, unk0558, unk055c;
    unsigned int unk0560, unk0564, unk0568, unk056c, unk0570, unk0574, unk0578, unk057c;
    unsigned int unk0580, unk0584, unk0588, unk058c, unk0590, unk0594, unk0598, unk059c;
    unsigned int unk05a0, unk05a4, unk05a8, unk05ac, unk05b0, unk05b4, unk05b8, unk05bc;
    unsigned int unk05c0, unk05c4, unk05c8, unk05cc, unk05d0, unk05d4, unk05d8, unk05dc;
    unsigned int unk05e0, unk05e4, unk05e8, unk05ec, unk05f0, unk05f4, unk05f8, unk05fc;
    unsigned int unk0600, unk0604, unk0608, unk060c, unk0610, unk0614, unk0618, unk061c;
    unsigned int unk0620, unk0624, unk0628, unk062c, unk0630, unk0634, unk0638, unk063c;
    unsigned int unk0640, unk0644, unk0648, unk064c, unk0650, unk0654, unk0658, unk065c;
    unsigned int unk0660, unk0664, unk0668, unk066c, unk0670, unk0674, unk0678, unk067c;
    unsigned int unk0680, unk0684, unk0688, unk068c, unk0690, unk0694, unk0698, unk069c;
    unsigned int unk06a0, unk06a4, unk06a8, unk06ac, unk06b0, unk06b4, unk06b8, unk06bc;
    unsigned int unk06c0, unk06c4, unk06c8, unk06cc, unk06d0, unk06d4, unk06d8, unk06dc;
    unsigned int unk06e0, unk06e4, unk06e8, unk06ec, unk06f0, unk06f4, unk06f8, unk06fc;
    unsigned int unk0700, unk0704, unk0708, unk070c, unk0710, unk0714, unk0718, unk071c;
    unsigned int unk0720, unk0724, unk0728, unk072c, unk0730, unk0734, unk0738, unk073c;
    unsigned int unk0740, unk0744, unk0748, unk074c, unk0750, unk0754, unk0758, unk075c;
    unsigned int unk0760, unk0764, unk0768, unk076c, unk0770, unk0774, unk0778, unk077c;
    unsigned int unk0780, unk0784, unk0788, unk078c, unk0790, unk0794, unk0798, unk079c;
    unsigned int unk07a0, unk07a4, unk07a8, unk07ac, unk07b0, unk07b4, unk07b8, unk07bc;
    unsigned int unk07c0, unk07c4, unk07c8, unk07cc, unk07d0, unk07d4, unk07d8, unk07dc;
    unsigned int unk07e0, unk07e4, unk07e8, unk07ec, unk07f0, unk07f4, unk07f8, unk07fc;
    unsigned int unk0800, unk0804, unk0808, unk080c, unk0810, unk0814, unk0818, unk081c;
    unsigned int unk0820, unk0824, unk0828, unk082c, unk0830, unk0834, unk0838, unk083c;
    unsigned int unk0840, unk0844, unk0848, unk084c, unk0850, unk0854, unk0858, unk085c;
    unsigned int unk0860, unk0864, unk0868, unk086c, unk0870, unk0874, unk0878, unk087c;
    unsigned int unk0880, unk0884, unk0888, unk088c, unk0890, unk0894, unk0898, unk089c;
    unsigned int unk08a0, unk08a4, unk08a8, unk08ac, unk08b0, unk08b4, unk08b8, unk08bc;
    unsigned int unk08c0, unk08c4, unk08c8, unk08cc, unk08d0, unk08d4, unk08d8, unk08dc;
    unsigned int unk08e0, unk08e4, unk08e8, unk08ec, unk08f0, unk08f4, unk08f8, unk08fc;
    unsigned int unk0900, unk0904, unk0908, unk090c, unk0910, unk0914, unk0918, unk091c;
    unsigned int unk0920, unk0924, unk0928, unk092c, unk0930, unk0934, unk0938, unk093c;
    unsigned int unk0940, unk0944, unk0948, unk094c, unk0950, unk0954, unk0958, unk095c;
    unsigned int unk0960, unk0964, unk0968, unk096c, unk0970, unk0974, unk0978, unk097c;
    unsigned int unk0980, unk0984, unk0988, unk098c, unk0990, unk0994, unk0998, unk099c;
    unsigned int unk09a0, unk09a4, unk09a8, unk09ac, unk09b0, unk09b4, unk09b8, unk09bc;
    unsigned int unk09c0, unk09c4, unk09c8, unk09cc, unk09d0, unk09d4, unk09d8, unk09dc;
    unsigned int unk09e0, unk09e4, unk09e8, unk09ec, unk09f0, unk09f4, unk09f8, unk09fc;
    unsigned int unk0a00, unk0a04, unk0a08, unk0a0c, unk0a10, unk0a14, unk0a18, unk0a1c;
    unsigned int unk0a20, unk0a24, unk0a28, unk0a2c, unk0a30, unk0a34, unk0a38, unk0a3c;
    unsigned int unk0a40, unk0a44, unk0a48, unk0a4c, unk0a50, unk0a54, unk0a58, unk0a5c;
    unsigned int unk0a60, unk0a64, unk0a68, unk0a6c, unk0a70, unk0a74, unk0a78, unk0a7c;
    unsigned int unk0a80, unk0a84, unk0a88, unk0a8c, unk0a90, unk0a94, unk0a98, unk0a9c;
    unsigned int unk0aa0, unk0aa4, unk0aa8, unk0aac, unk0ab0, unk0ab4, unk0ab8, unk0abc;
    unsigned int unk0ac0, unk0ac4, unk0ac8, unk0acc, unk0ad0, unk0ad4, unk0ad8, unk0adc;
    unsigned int unk0ae0, unk0ae4, unk0ae8, unk0aec, unk0af0, unk0af4, unk0af8, unk0afc;
    unsigned int unk0b00, unk0b04, unk0b08, unk0b0c, unk0b10, unk0b14, unk0b18, unk0b1c;
    unsigned int unk0b20, unk0b24, unk0b28, unk0b2c, unk0b30, unk0b34, unk0b38, unk0b3c;
    unsigned int unk0b40, unk0b44, unk0b48, unk0b4c, unk0b50, unk0b54, unk0b58, unk0b5c;
    unsigned int unk0b60, unk0b64, unk0b68, unk0b6c, unk0b70, unk0b74, unk0b78, unk0b7c;
    unsigned int unk0b80, unk0b84, unk0b88, unk0b8c, unk0b90, unk0b94, unk0b98, unk0b9c;
    unsigned int unk0ba0, unk0ba4, unk0ba8, unk0bac, unk0bb0, unk0bb4, unk0bb8, unk0bbc;
    unsigned int unk0bc0, unk0bc4, unk0bc8, unk0bcc, unk0bd0, unk0bd4, unk0bd8, unk0bdc;
    unsigned int unk0be0, unk0be4, unk0be8, unk0bec, unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    unsigned int unk0c00, unk0c04, unk0c08, unk0c0c, unk0c10, unk0c14, unk0c18, unk0c1c;
    unsigned int unk0c20, unk0c24, unk0c28, unk0c2c, unk0c30, unk0c34, unk0c38, unk0c3c;
    unsigned int unk0c40, unk0c44, unk0c48, unk0c4c, unk0c50, unk0c54, unk0c58, unk0c5c;
    unsigned int unk0c60, unk0c64, unk0c68, unk0c6c, unk0c70, unk0c74, unk0c78, unk0c7c;
    unsigned int unk0c80, unk0c84, unk0c88, unk0c8c, unk0c90, unk0c94, unk0c98, unk0c9c;
    unsigned int unk0ca0, unk0ca4, unk0ca8, unk0cac, unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    unsigned int unk0cc0, unk0cc4, unk0cc8, unk0ccc, unk0cd0, unk0cd4, unk0cd8, unk0cdc;
    unsigned int unk0ce0, unk0ce4, unk0ce8, unk0cec, unk0cf0, unk0cf4, unk0cf8, unk0cfc;
    unsigned int unk0d00, unk0d04, unk0d08, unk0d0c, unk0d10, unk0d14, unk0d18, unk0d1c;
    unsigned int unk0d20, unk0d24, unk0d28, unk0d2c, unk0d30, unk0d34, unk0d38, unk0d3c;
    unsigned int unk0d40, unk0d44, unk0d48, unk0d4c, unk0d50, unk0d54, unk0d58, unk0d5c;
    unsigned int unk0d60, unk0d64, unk0d68, unk0d6c, unk0d70, unk0d74, unk0d78, unk0d7c;
    unsigned int unk0d80, unk0d84, unk0d88, unk0d8c, unk0d90, unk0d94, unk0d98, unk0d9c;
    unsigned int unk0da0, unk0da4, unk0da8, unk0dac, unk0db0, unk0db4, unk0db8, unk0dbc;
    unsigned int unk0dc0, unk0dc4, unk0dc8, unk0dcc, unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    unsigned int unk0de0, unk0de4, unk0de8, unk0dec, unk0df0, unk0df4, unk0df8, unk0dfc;
    unsigned int unk0e00, unk0e04, unk0e08, unk0e0c, unk0e10, unk0e14, unk0e18, unk0e1c;
    unsigned int unk0e20, unk0e24, unk0e28, unk0e2c, unk0e30, unk0e34, unk0e38, unk0e3c;
    unsigned int unk0e40, unk0e44, unk0e48, unk0e4c, unk0e50, unk0e54, unk0e58, unk0e5c;
    unsigned int unk0e60, unk0e64, unk0e68, unk0e6c, unk0e70, unk0e74, unk0e78, unk0e7c;
    unsigned int unk0e80, unk0e84, unk0e88, unk0e8c, unk0e90, unk0e94, unk0e98, unk0e9c;
    unsigned int unk0ea0, unk0ea4, unk0ea8, unk0eac, unk0eb0, unk0eb4, unk0eb8, unk0ebc;
    unsigned int unk0ec0, unk0ec4, unk0ec8, unk0ecc, unk0ed0, unk0ed4, unk0ed8, unk0edc;
    unsigned int unk0ee0, unk0ee4, unk0ee8, unk0eec, unk0ef0, unk0ef4, unk0ef8, unk0efc;
    unsigned int unk0f00, unk0f04, unk0f08, unk0f0c, unk0f10, unk0f14, unk0f18, unk0f1c;
    unsigned int unk0f20, unk0f24, unk0f28, unk0f2c, unk0f30, unk0f34, unk0f38, unk0f3c;
    unsigned int unk0f40, unk0f44, unk0f48, unk0f4c, unk0f50, unk0f54, unk0f58, unk0f5c;
    unsigned int unk0f60, unk0f64, unk0f68, unk0f6c, unk0f70, unk0f74, unk0f78, unk0f7c;
    unsigned int unk0f80, unk0f84, unk0f88, unk0f8c, unk0f90, unk0f94, unk0f98, unk0f9c;
    unsigned int unk0fa0, unk0fa4, unk0fa8, unk0fac, unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    unsigned int unk0fc0, unk0fc4, unk0fc8, unk0fcc, unk0fd0, unk0fd4, unk0fd8, unk0fdc;
    unsigned int unk0fe0, unk0fe4, unk0fe8, unk0fec, unk0ff0, unk0ff4, unk0ff8, unk0ffc;
    unsigned int unk1000, unk1004, unk1008, unk100c, unk1010, unk1014, unk1018, unk101c;
    unsigned int unk1020, unk1024, unk1028, unk102c, unk1030, unk1034, unk1038, unk103c;
    unsigned int unk1040, unk1044, unk1048, unk104c, unk1050, unk1054, unk1058, unk105c;
    unsigned int unk1060, unk1064, unk1068, unk106c, unk1070, unk1074, unk1078, unk107c;
    unsigned int unk1080, unk1084, unk1088, unk108c, unk1090, unk1094, unk1098, unk109c;
    unsigned int unk10a0, unk10a4, unk10a8, unk10ac, unk10b0, unk10b4, unk10b8, unk10bc;
    unsigned int unk10c0, unk10c4, unk10c8, unk10cc, unk10d0, unk10d4, unk10d8, unk10dc;
    unsigned int unk10e0, unk10e4, unk10e8, unk10ec, unk10f0, unk10f4;
    DEV_00e89b10* m_pDirect3DDevice;
    __forceinline long SetVSF(unsigned int uiReg, const float* pv, unsigned int ItemUpdateArray)
    {
        return m_pDirect3DDevice->vtable->m_fn(m_pDirect3DDevice, uiReg, pv, ItemUpdateArray);
    }
    bool CallVtableMethod(unsigned int uiStart, const void* pvData, unsigned int ItemUpdateArray, unsigned int uiFlags);
    bool SetDeviceState(unsigned int uiStart, const void* pvData, unsigned int ItemUpdateArray, unsigned int uiFlags);
    bool IsVtblCallSucceeded(unsigned int uiStart, const void* pvData, unsigned int ItemUpdateArray, unsigned int uiFlags);
};
__forceinline bool SetF(NiD3DHLSLVertexShader* pkShader, unsigned int uiReg, const void* pv, unsigned int ItemUpdateArray)
{
    return ((VS_00e972e0_Renderer*)pkShader->m_pRenderState)->CallVtableMethod(uiReg, pv, ItemUpdateArray, 0);
}
__forceinline bool SetI(NiD3DHLSLVertexShader* pkShader, unsigned int uiReg, const void* pv, unsigned int ItemUpdateArray)
{
    return ((VS_00e972e0_Renderer*)pkShader->m_pRenderState)->SetDeviceState(uiReg, pv, ItemUpdateArray, 0);
}
__forceinline bool SetB(NiD3DHLSLVertexShader* pkShader, unsigned int uiReg, const void* pv, unsigned int ItemUpdateArray)
{
    return ((VS_00e972e0_Renderer*)pkShader->m_pRenderState)->IsVtblCallSucceeded(uiReg, pv, ItemUpdateArray, 0);
}
__forceinline long SetM(NiD3DHLSLVertexShader* pkShader, unsigned int uiReg, const float* pv, unsigned int ItemUpdateArray)
{
    return ((VS_00e972e0_Renderer*)pkShader->m_pRenderState)->SetVSF(uiReg, pv, ItemUpdateArray);
}

// @fnv 0x00e972e0
// src: XBOX_PDB 0x00e972e0
bool __fastcall NiD3DHLSLVertexShader_SetShaderConstant(NiD3DHLSLVertexShader* pkShader, void*, VS_00e972e0_Entry* pkEntry, const void* pvDataSource, unsigned int uiFlags)
{
    if (!pkShader->m_pShaderConstantTable || !pkShader->m_pD3DDevice)
        return false;
    if (!pvDataSource)
        pvDataSource = pkEntry->m_pConstantData;

    if (!pkEntry->m_bFlag1)
    {
        if (pkEntry->m_kSecondaryString.m_kHandle != DAT_0109b220)
            InterlockedIncrement((long volatile*)(pkEntry->m_kSecondaryString.m_kHandle - 8));
        union
        {
            VS_00e972e0_Str kVariable;
            unsigned int ItemUpdateArray;
        } temporary;
        temporary.kVariable.m_kHandle = pkEntry->m_kSecondaryString.m_kHandle;
        if (temporary.kVariable.m_kHandle == DAT_0109b220)
        {
            temporary.kVariable.AssignInternedString(pkEntry->m_kName);
            pkEntry->NiShaderConstantMapEntry_SetVariableName(temporary.kVariable);
        }
        char* pcVariable = temporary.kVariable.m_kHandle;
        void* hConstant = ((VS_00e972e0_Table*)pkShader->m_pShaderConstantTable)->FindConstantByName(0, pcVariable);
        if (hConstant)
        {
            temporary.ItemUpdateArray = 1;
            VS_00e972e0_Desc kDesc;
            ((VS_00e972e0_Table*)pkShader->m_pShaderConstantTable)->GetConstantDescription(hConstant, &kDesc, &temporary.ItemUpdateArray);
            pkEntry->m_uiValueAt1C = kDesc.m_uiRegisterIndex;
            pkEntry->m_uiValue4 = kDesc.m_uiRegisterSpan;
            pkEntry->m_bFlag1 = true;
            if (pcVariable != DAT_0109b220)
                InterlockedDecrement((long volatile*)(pcVariable - 8));
        }
        else
        {
            Object_DoNothing(str_010f14a0, pkShader->m_pcProgramName, pcVariable);
            if (pcVariable != DAT_0109b220)
                InterlockedDecrement((long volatile*)(pcVariable - 8));
            return false;
        }
    }

    bool bResult = false;
    int eType = (int)DAT_011f5fc4[pkEntry->m_uiValue1 & 0xff];
    if (eType == 8 || eType == 9)
    {
        VS_00e972e0_Matrix kTranspose;
        D3DXMatrixTranspose_00ee6dd4(&kTranspose, (const VS_00e972e0_Matrix*)pvDataSource);
        if (SetM(pkShader, pkEntry->m_uiValueAt1C, &kTranspose._11, pkEntry->m_uiValue4) >= 0)
            bResult = true;
    }
    else if (eType == 5 || eType == 6 || eType == 7 || eType == 10)
    {
        if (SetF(pkShader, pkEntry->m_uiValueAt1C, pvDataSource, pkEntry->m_uiValue4))
            bResult = true;
    }
    else if (eType == 4)
    {
        if (SetF(pkShader, pkEntry->m_uiValueAt1C, pvDataSource, pkEntry->m_uiValue4))
            bResult = true;
    }
    else if (eType == 3)
    {
        if (SetI(pkShader, pkEntry->m_uiValueAt1C, pvDataSource, pkEntry->m_uiValue4))
            bResult = true;
    }
    else if (eType == 1)
    {
        if (SetB(pkShader, pkEntry->m_uiValueAt1C, pvDataSource, pkEntry->m_uiValue4))
            bResult = true;
    }
    return bResult;
}

struct OrderArg
{
    const unsigned short* p;
};
extern "C" void _ReadWriteBarrier();
extern const char str_010f14e8[];
// Resolves the constant by name, then uploads matrix, float, integer, or boolean data to shader registers, optionally using the supplied entry order.
// @fnv 0x00e974f0
// src: XBOX_PDB 0x00e974f0
bool __fastcall NiD3DHLSLVertexShader_SetShaderConstantArray(NiD3DHLSLVertexShader* pkShader, void*, VS_00e972e0_Entry* pkEntry, const void* pvData, unsigned int uiNumEntries,
                               unsigned int uiRegistersPerEntry, OrderArg orderArg)
{
    if (pkShader->m_pShaderConstantTable == 0 || pkShader->m_pD3DDevice == 0)
        return false;

    int eType = DAT_011f5fc4[pkEntry->m_uiValue1 & 0xff];
    if (eType != 8 && eType != 9)
        return false;

    if (pvData == 0)
        pvData = pkEntry->m_pConstantData;

    bool bTransposed = false;
    unsigned int uiInternal = pkEntry->unk10;
    if (uiInternal == 0x21 || uiInternal == 0x23 || uiInternal == 0x22 || uiInternal == 0x24)
        bTransposed = true;

    union
    {
        VS_00e972e0_Desc desc;
        VS_00e972e0_Matrix matrix;
    } scratch;
    union
    {
        VS_00e972e0_Str kName;
        unsigned int ItemUpdateArray;
        unsigned int index;
    } temporary;
    if (!pkEntry->m_bFlag1)
    {
        if (pkEntry->m_kSecondaryString.m_kHandle != DAT_0109b220)
            InterlockedIncrement((long volatile*)(pkEntry->m_kSecondaryString.m_kHandle - 8));
        temporary.kName.m_kHandle = pkEntry->m_kSecondaryString.m_kHandle;
        VS_00e972e0_Str& kVariableName = temporary.kName;
        if (kVariableName.m_kHandle == DAT_0109b220)
        {
            kVariableName.AssignInternedString(pkEntry->m_kName);
            pkEntry->NiShaderConstantMapEntry_SetVariableName(kVariableName);
        }

        char* pcVariable = kVariableName.m_kHandle;
        void* hConstant = ((VS_00e972e0_Table*)pkShader->m_pShaderConstantTable)->FindConstantByName(0, pcVariable);
        if (hConstant)
        {
            VS_00e972e0_Desc& kDesc = scratch.desc;
            temporary.ItemUpdateArray = 1;
            ((VS_00e972e0_Table*)pkShader->m_pShaderConstantTable)->GetConstantDescription(hConstant, &kDesc, &temporary.ItemUpdateArray);
            pkEntry->m_uiValueAt1C = kDesc.m_uiRegisterIndex;
            pkEntry->m_uiValue4 = kDesc.m_uiRegisterSpan;
            pkEntry->m_bFlag1 = true;
        }
        else
        {
            Object_DoNothing(str_010f14e8, pkShader->m_pcProgramName, pcVariable);
            if (pcVariable != DAT_0109b220)
                InterlockedDecrement((long volatile*)(pcVariable - 8));
            return false;
        }
        if (pcVariable != DAT_0109b220)
            InterlockedDecrement((long volatile*)(pcVariable - 8));
    }

    volatile bool bSuccess = false;
    if (orderArg.p)
    {
        unsigned int uiRegister = pkEntry->m_uiValueAt1C;
        for (temporary.index = 0; temporary.index < uiNumEntries; temporary.index++)
        {
            _ReadWriteBarrier();
            unsigned short usIndex = orderArg.p[temporary.index];
            bSuccess = false;
            const float* pVector4;
            VS_00e972e0_Matrix& kMatrix = scratch.matrix;
            if (bTransposed)
            {
                pVector4 = (const float*)((const char*)pvData + usIndex * uiRegistersPerEntry * 16);
                if (SetM(pkShader, uiRegister, pVector4, uiRegistersPerEntry) < 0)
                {
                    break;
                }
            }
            else
            {
                D3DXMatrixTranspose_00ee6dd4(&kMatrix,
                             (const VS_00e972e0_Matrix*)((const char*)pvData + usIndex * uiRegistersPerEntry * 16));
                pVector4 = &kMatrix._11;
                if (SetM(pkShader, uiRegister, pVector4, uiRegistersPerEntry) < 0)
                {
                    break;
                }
            }
            uiRegister += uiRegistersPerEntry;
            bSuccess = true;
        }
    }
    else if (bTransposed)
    {
        if (SetF(pkShader, pkEntry->m_uiValueAt1C, (const float*)pvData, pkEntry->m_uiValue4))
        {
            bSuccess = true;
        }
    }
    else
    {
        unsigned int uiRegister = pkEntry->m_uiValueAt1C;
        const float* pVector4 = (const float*)pvData;
        for (temporary.index = 0; temporary.index < uiNumEntries; temporary.index++)
        {
            _ReadWriteBarrier();
            VS_00e972e0_Matrix& kMatrix = scratch.matrix;
            D3DXMatrixTranspose_00ee6dd4(&kMatrix, (const VS_00e972e0_Matrix*)pVector4);
            bSuccess = false;
            if (SetM(pkShader, uiRegister, &kMatrix._11, uiRegistersPerEntry) < 0)
            {
                break;
            }
            uiRegister += uiRegistersPerEntry;
            pVector4 += uiRegistersPerEntry * 4;
            bSuccess = true;
        }
    }
    return bSuccess;
}
