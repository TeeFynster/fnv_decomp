// src/gamebryo2.2/corelibs/nianimation/nifloatsextradatapoint3controller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatsextradatapoint3controller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiFloatsExtraData.h"
#include "../../../../include/NiFloatsExtraDataPoint3Controller.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysModifierCtlr.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"

int* __fastcall InitTimeController(int*);
extern "C" int DAT_0109917c;
extern int EmptyFS;

// @fnv 0x00a4ecd0
// src: EXE 0x00a4ecd0
int* __cdecl NiFloatsExtraDataPoint3Controller_CreateObject()
{
    int* p = (int*)BSFadeNode::operator new(0x48);
    if (p)
    {
        InitTimeController(p);
        p[0] = (int)&DAT_0109917c;
        p[0x40 / 4] = -1;
        p[0x44 / 4] = EmptyFS;
        return p;
    }
    return 0;
}

// These file-local entry points use ECX for the shared controller, with the
// unused EDX argument preserving the original stack arguments and cleanup.
// @fnv 0x00a4ec80
NiFloatsExtraDataPoint3Controller* __fastcall ClonePoint3Controller(
    NiFloatsExtraDataPoint3Controller* self, int, void* proc)
{
    NiFloatsExtraDataPoint3Controller* p = (NiFloatsExtraDataPoint3Controller*)BSFadeNode::operator new(0x48);
    if (p) {
        p->InitTimeController();
        *(int**)p = &DAT_0109917c;
        p->m_iFloatsExtraDataIndex = -1;
        *(int*)&p->m_kCtlrID.m_kHandle = EmptyFS;
    } else {
        p = 0;
    }
    ((NiPSysModifierCtlr*)self)->CopyMemberData((NiPSysModifierCtlr*)p, proc);
    p->m_iFloatsExtraDataIndex = self->m_iFloatsExtraDataIndex;
    return p;
}

// @fnv 0x00a4ee90
void __fastcall LoadPoint3Controller(NiFloatsExtraDataPoint3Controller* self, int, void* stream)
{
    ((NiPSysModifierCtlr*)self)->NiPSysModifierCtlr::LoadBinary(*(NiStream*)stream);
    // The shared stream types keep their binary storage opaque.
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)stream + 0x24c);
    unsigned int size = 4;
    *(unsigned int*)((char*)input + 4) +=
        (*(NiBinaryStream::ReadFunction*)((char*)input + 8))(input, &self->m_iFloatsExtraDataIndex, 4, &size, 1);
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f70;
struct Vec12 {
    float x, y, z;
};
struct Holder00 {
    void SetPoseValue(Vec12);
};

// @fnv 0x00a4ed50
void __fastcall SetInterpolatorPoint3(NiFloatsExtraDataPoint3Controller* self, int,
                                     NiObject* pkInterp, unsigned short usIndex)
{
    NiObject* pkFloatInterp;
    NiFloatsExtraData* pkFloatsED;
    Vec12 kPt;
    if (!pkInterp) {
        pkFloatInterp = 0;
    } else {
        pkFloatInterp = pkInterp->DynamicCast((const NiRTTI*)&g_011f3f70);
    }
    pkFloatsED = (NiFloatsExtraData*)self->m_pExtraData.m_pObject;
    kPt.x = pkFloatsED->GetValueAt(self->m_iFloatsExtraDataIndex);
    kPt.y = pkFloatsED->GetValueAt(self->m_iFloatsExtraDataIndex + 1);
    kPt.z = pkFloatsED->GetValueAt(self->m_iFloatsExtraDataIndex + 2);
    ((Holder00*)pkFloatInterp)->SetPoseValue(kPt);
}

void __stdcall AddExtraDataViewerStrings(StrArr* strings);
extern void* g_011f3fc4;
char* __cdecl _FUN_00a7d330(void* value);
char* __cdecl NiGetViewerString_00a7d4d0(char const* name, int value);

// @fnv 0x00a4eed0
void __fastcall GetPoint3ControllerViewerStrings(NiFloatsExtraDataPoint3Controller* self, int, StrArr* strings)
{
    AddExtraDataViewerStrings(strings);

    {
        char* value = _FUN_00a7d330(g_011f3fc4);
        unsigned int index = strings->m_usSize;
        unsigned int capacity = strings->m_usMaxSize;
        if (index >= capacity)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }

    {
        char* value = NiGetViewerString_00a7d4d0("m_iFloatsExtraDataIndex",
                                    self->m_iFloatsExtraDataIndex);
        unsigned int index = strings->m_usSize;
        unsigned int capacity = strings->m_usMaxSize;
        if (index >= capacity)
            strings->SetSize(index + strings->m_usGrowBy);
        strings->SetAt(index, value);
    }
}

void* __cdecl Object_DispatchCommandFour(unsigned int);
struct Vec12Sink {
    int FUN_00a49650(Vec12 v);
};

// @fnv 0x00a4eb50
int __fastcall BuildAndDispatchVec12(NiFloatsExtraDataPoint3Controller* self, int, int unused)
{
    NiFloatsExtraData* stub = (NiFloatsExtraData*)self->m_pExtraData.m_pObject;
    Vec12 v;
    v.x = stub->GetValueAt(self->m_iFloatsExtraDataIndex);
    v.y = stub->GetValueAt(self->m_iFloatsExtraDataIndex + 1);
    v.z = stub->GetValueAt(self->m_iFloatsExtraDataIndex + 2);
    Vec12Sink* p = (Vec12Sink*)Object_DispatchCommandFour(0x20);
    if (p != 0) {
        return p->FUN_00a49650(v);
    }
    return 0;
}

extern "C" char* DAT_0109b220;
extern "C" void (__stdcall* DAT_00fdf1c4)(void*);
void __cdecl FUN_00aa1460(void* ptr, unsigned int size);
void __fastcall DestroyExtraDataController(NiExtraDataController* self);

// @fnv 0x00a4ed10
NiFloatsExtraDataPoint3Controller* __fastcall DestroyPoint3Controller(
    NiFloatsExtraDataPoint3Controller* self, int, unsigned char acFlags)
{
    *(void* volatile*)self = (void*)&DAT_0109917c;
    char* volatile* pm44 = (char* volatile*)&self->m_kCtlrID.m_kHandle;
    char* p = *pm44;
    if (p != DAT_0109b220) {
        DAT_00fdf1c4(p - 8);
    }
    DestroyExtraDataController(self);
    if (acFlags & 1) {
        FUN_00aa1460(self, 0x48);
    }
    return self;
}

extern const float DAT_01096324;
struct Pt4edd { float x, y, z; };
class Interp4edd {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24();
    virtual bool Update(float fTime, void* pkTarget, Pt4edd& kValue);
    virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b();
    virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34();
    virtual bool AlwaysUpdate();
};

static unsigned char GetManagerControlledFlag(const NiFloatsExtraDataPoint3Controller* self)
{
    return (self->m_uiObjectFlags >> 5) & 1;
}

// @fnv 0x00a4edd0
void __fastcall UpdateController(NiFloatsExtraDataPoint3Controller* self, int, const float& fTime)
{
    if (GetManagerControlledFlag(self))
        self->m_fControllerTime = DAT_01096324;
    else if (self->DontDoUpdate(fTime)
        && (!self->m_spControllerInterpolator.m_pObject ||
            !((Interp4edd*)self->m_spControllerInterpolator.m_pObject)->AlwaysUpdate()))
        return;

    if (self->m_spControllerInterpolator.m_pObject) {
        Pt4edd kValue;
        if (((Interp4edd*)self->m_spControllerInterpolator.m_pObject)->Update(self->m_fControllerTime, self->m_pkTarget, kValue)) {
            NiFloatsExtraData* pkData = (NiFloatsExtraData*)self->m_pExtraData.m_pObject;
            if (pkData) {
                pkData->SetValue((unsigned int)self->m_iFloatsExtraDataIndex, kValue.x);
                pkData->SetValue((unsigned int)self->m_iFloatsExtraDataIndex + 1, kValue.y);
                pkData->SetValue((unsigned int)self->m_iFloatsExtraDataIndex + 2, kValue.z);
            }
        }
    }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <windows.h>
#include "../../../../include/NiPoint3.h"
extern "C" double __cdecl fabs(double);
struct D3DVERTEXBUFFER_DESC { unsigned Format, Type, Usage, Pool, Size, FVF; };
struct IDirect3DVertexBuffer9 {
    virtual void __stdcall v00(); virtual void __stdcall v04(); virtual void __stdcall v08();
    virtual void __stdcall v0c(); virtual void __stdcall v10(); virtual void __stdcall v14();
    virtual void __stdcall v18(); virtual void __stdcall v1c(); virtual void __stdcall v20();
    virtual void __stdcall v24(); virtual void __stdcall v28(); virtual void __stdcall v2c();
    virtual int __stdcall Unlock();
    virtual int __stdcall GetDesc(D3DVERTEXBUFFER_DESC*);
};

extern unsigned int DAT_011bf558;
extern const float DAT_010718c0;
extern const double DAT_0101e568;
extern const char DAT_010efe14[];

struct RenderBuffer {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned count;
    unsigned* firstEntry;
    void** entries;
    void FUN_00e8f010(unsigned count);
};

struct Color4 { float r, g, b, a; };
struct TwoComponentVector { float x, y; TwoComponentVector& operator=(const TwoComponentVector& p) { *(unsigned*)&x=*(const unsigned*)&p.x; *(unsigned*)&y=*(const unsigned*)&p.y; return *this; } };

struct VertexSource {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned short flags;
    unsigned short unk0e;
    unsigned unk10, unk14, unk18, unk1c;
    NiPoint3* positions;
    NiPoint3* normals;
    Color4* colors;
    NiPoint3* GetPositions() const { return positions; }
    NiPoint3* GetNormals() const { return normals; }
    Color4* GetColors() const { return colors; }
    TwoComponentVector* NiGeometryData_GetTextureSet(unsigned index);
};

struct VertexData {
    unsigned unk00;
    unsigned unk04;
    float* attributes;
    unsigned short* indices;
    unsigned unk10, unk14, unk18;
    unsigned short vertexCount;
    unsigned short unk1e;
    unsigned short componentCount;
    unsigned short unk22;
    unsigned unk24;
    RenderBuffer* buffer;
};

struct VertexBufferLockInfo {
    unsigned unk00;
    unsigned unk04;
    IDirect3DVertexBuffer9* buffer;
    unsigned lockArg0;
    unsigned lockArg1;
    unsigned lockArg2;
    unsigned GetBuffer() const { return (unsigned)buffer; }
    unsigned GetOffset() const { return lockArg0; }
    unsigned GetFlags() const { return lockArg2; }
    IDirect3DVertexBuffer9* GetSize() const { return (IDirect3DVertexBuffer9*)lockArg1; }
};

extern int __cdecl FUN_00a305b0(char*, unsigned, const char*, ...);
extern void __cdecl FUN_00ec44d0(void*, unsigned, unsigned);

struct VertexRenderer {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned lockArg;
    unsigned unk44;
    void* lockedPtr;
    unsigned lockedState;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    CRITICAL_SECTION lock;

    __declspec(noalias) void NiDX9VertexBufferManager_GenerateVertexParameters(VertexSource*, VertexData*, unsigned*, unsigned*, unsigned*, unsigned*, unsigned*, unsigned*, unsigned*);
    bool NiDX9VertexBufferManager_AllocateBufferSpace(RenderBuffer*, unsigned);
    void* NiDX9VertexBufferManager_LockVB(unsigned, unsigned, unsigned, IDirect3DVertexBuffer9*);
    VertexBufferLockInfo* NiDX9VertexBufferManager_PackSkinnedVB(VertexSource*, unsigned, VertexData*, unsigned, VertexBufferLockInfo*, char*);
};

// @fnv 0x00e8c820
// src: COMMUNITY 0x00e8c820
VertexBufferLockInfo* VertexRenderer::NiDX9VertexBufferManager_PackSkinnedVB(VertexSource* source, unsigned unused, VertexData* data, unsigned flags, VertexBufferLockInfo* existing, char* option)
{
    unsigned vertexCount;
    unsigned dataFlags;
    unsigned texOffset;
    unsigned normalOffset;
    unsigned attributeOffset;
    unsigned positionOffset;
    unsigned stride;
    NiPoint3* positions = source->GetPositions();
    NiPoint3* normals = source->GetNormals();
    unsigned textureSetCount = source->flags & 1;
    Color4* colors = source->GetColors();
    if (textureSetCount > DAT_011bf558)
        textureSetCount = DAT_011bf558;

    unsigned componentCount = data->componentCount;
    unsigned numVertices = data->vertexCount;
    unsigned short* indices = data->indices;
    vertexCount = 0;
    stride = 0;
    NiDX9VertexBufferManager_GenerateVertexParameters(source, data, &vertexCount, &stride, &positionOffset, &attributeOffset,
                  &normalOffset, &dataFlags, &texOffset);

    RenderBuffer* buffer = data->buffer;
    buffer->FUN_00e8f010(vertexCount);
    if (buffer->count > 0)
        *buffer->firstEntry = stride;

    VertexBufferLockInfo* resource;
    bool needsUnlock = true;
    if (option != 0) {
        resource = existing;
        needsUnlock = false;
    } else {
        bool valid = false;
        IDirect3DVertexBuffer9* existingBuffer;
        if (existing && (existingBuffer = existing->buffer)) {
            D3DVERTEXBUFFER_DESC desc;
            existingBuffer->GetDesc(&desc);
            if ((int)desc.Format == 100 && desc.FVF == vertexCount &&
                desc.Size >= unsigned((unsigned short)numVertices) * stride) {
                resource = existing;
                valid = true;
            }
        }
        if (!valid) {
            if (!NiDX9VertexBufferManager_AllocateBufferSpace(buffer, 0))
                return 0;
            if (buffer->count > 0)
                resource = *(VertexBufferLockInfo**)buffer->entries;
            else
                resource = 0;
            flags = 0xfff;
        }
        option = (char*)NiDX9VertexBufferManager_LockVB(resource->GetBuffer(), resource->GetOffset(),
                                        resource->GetFlags(), resource->GetSize());
    }

    char* dst = (char*)(option + positionOffset);
    if (positions && (flags & 1)) {
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            unsigned k = indices[i];
            *(Vec12*)dst = *(const Vec12*)&positions[k];
            dst += stride;
        }

        float* attrib = data->attributes;
        char* target = (char*)(option + attributeOffset);
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            float sum = 1.0f;
            for (unsigned j = 0; j < (unsigned short)componentCount; ++j)
                sum -= attrib[j];

            float magnitude = (float)fabs(sum);
            if (magnitude > 1e-5f) {
                char message[256];
                FUN_00a305b0(message, 256, "ILLEGAL WEIGHTS! Vertex %4d - Weight Sum %8.5f  (%8.5f)\n", i, 1.0 - (double)sum, (double)sum);
            }

            unsigned short c = 0;
            int limit = (unsigned short)componentCount - 1;
            for (; (int)c < limit; ++c)
                *(float*)(target + c * 4) = attrib[c];
            if ((unsigned short)componentCount == 3 || (unsigned short)componentCount == 1)
                *(float*)(target + c * 4) = attrib[c];

            target += stride;
            attrib += (unsigned short)componentCount;
        }
    }

    if (normals && (flags & 2)) {
        dst = (char*)(option + normalOffset);
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            unsigned k = indices[i];
            *(Vec12*)dst = *(const Vec12*)&normals[k];
            dst += stride;
        }
    }

    if (colors && (flags & 4)) {
        dst = (char*)(option + dataFlags);
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            *(unsigned*)dst = (((fnv_FloatToInt(colors[indices[i]].a * 255.0) << 8) | fnv_FloatToInt(colors[indices[i]].r * 255.0)) << 8 | fnv_FloatToInt(colors[indices[i]].g * 255.0)) << 8 | fnv_FloatToInt(colors[indices[i]].b * 255.0);
            dst += stride;
        }
    }

    if (flags & 8) {
        unsigned i = 0;
        if (i < textureSetCount) {
        TwoComponentVector* dest = (TwoComponentVector*)(option + texOffset);
        do {
            TwoComponentVector* out = dest;
            TwoComponentVector* uv = source->NiGeometryData_GetTextureSet(i);
            for (unsigned j = 0; j < (unsigned short)numVertices; ++j) {
                unsigned k = indices[j];
                *out = uv[k];
                out = (TwoComponentVector*)((char*)out + stride);
            }
            ++i;
            ++dest;
        } while (i < textureSetCount);
        }
    }
    if (needsUnlock) {
        IDirect3DVertexBuffer9* hardwareBuffer = resource->buffer;
        FUN_00ec44d0(lockedPtr, lockArg, lockedState);
        lockedPtr = 0;
        lockedState = 0;
        LeaveCriticalSection(&lock);
        if (hardwareBuffer->Unlock() < 0)
            return 0;
    }
    return resource;
}
