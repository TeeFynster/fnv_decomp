#include "../../../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtopathdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtopathdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../../include/hkTransform.h"

inline hkMemoryAllocator& PointToPathHeap(hkMemoryRouter* record)
{
    return *record->m_heap;
}


inline hkVector4::hkVector4(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

static __forceinline void hkVector4Array_ClearAndRelease(hkArrayBase<hkVector4>& self, hkMemoryAllocator& alloc);

static __forceinline void hkVector4Array_ClearAndRelease(hkArrayBase<hkVector4>& self, hkMemoryAllocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(hkVector4));
    }

struct PointSource
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void getPoints(hkArrayBase<hkVector4>& points);
};

struct BoneTransformData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    PointSource* m_kPoints;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    hkTransform m_kMotionTransform;
    void hkpPointToPathConstraintData_calcPivot(const hkVector4* in, hkVector4* out);
};

struct ExtraData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkVector4 m_endPoint;
};

struct Input
{
    int unk00;
    int unk04;
    int unk08;
    BoneTransformData* m_scene;
    int unk10;
    ExtraData* m_extra;
};

struct LineDrawer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void drawLine(const hkVector4& a, const hkVector4& b, int color, int id, int tag);
};

int __cdecl PackColorBigEndian(float r, float g, float b, float a);
extern float DAT_0101622c;

struct Processor
{
    void hkpPrimitiveDrawer_setDisplayHandler(LineDrawer* drawer);
};

struct Viewer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_endPoint;
    hkVector4 m_vContactPosition;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    Processor m_processor;

    void hkpConstraintDrawer_updateCommonParameters(Input* input, hkTransform* transform, hkTransform* extra);
    void hkpConstraintDrawer_drawBodyFrames(int id, int tag);
    void hkpConstraintDrawer_drawPivots(int id, int tag);
    void UpdateViewerAndDrawPointLines(Input* input, LineDrawer* drawer, int id, int tag);
};

// Runs several viewer update steps, then draws lines between consecutive points of the scene's point source, transformed to world space, using drawer.
// @fnv 0x00de7020
// src: GUESS 0x00de7020 (confidence: medium)
void Viewer::UpdateViewerAndDrawPointLines(Input* input, LineDrawer* drawer, int id, int tag)
{
    BoneTransformData* scene = input->m_scene;
    // Vector-backed storage preserves the original stack layout and /GS classification.
    hkVector4 localTransformStorage[4] = { hkVector4(), hkVector4(), hkVector4(), hkVector4() };
    hkVector4 worldTransformStorage[4] = { hkVector4(), hkVector4(), hkVector4(), hkVector4() };
    hkVector4 extraTransformStorage[4] = { hkVector4(), hkVector4(), hkVector4(), hkVector4() };
    hkTransform& localTransform = *reinterpret_cast<hkTransform*>(localTransformStorage);
    hkTransform& worldTransform = *reinterpret_cast<hkTransform*>(worldTransformStorage);
    hkTransform& extraTransform = *reinterpret_cast<hkTransform*>(extraTransformStorage);

    m_processor.hkpPrimitiveDrawer_setDisplayHandler(drawer);
    hkpConstraintDrawer_updateCommonParameters(input, &localTransform, &extraTransform);
    m_vContactPosition.m_vComponents = localTransform.m_vTranslation;
    scene->hkpPointToPathConstraintData_calcPivot(&input->m_extra->m_endPoint, &m_endPoint);
    hkpConstraintDrawer_drawBodyFrames(id, tag);
    hkpConstraintDrawer_drawPivots(id, tag);

    if (scene->m_kPoints)
    {
        worldTransform.hkTransform_setMul(localTransform, scene->m_kMotionTransform);
        PointSource* source = scene->m_kPoints;
        if (source)
        {
            hkArrayBase<hkVector4> points;
            source->getPoints(points);
            int numPoints = points.m_iElementCount;
            for (int i = 1; i < numPoints; i++)
            {
                hkVector4 a;
                hkVector4 b;
                hkVector4 p = points.m_data[i];
                a.setTransformedPos_00c7f640(worldTransform, p);
                p = points.m_data[i - 1];
                b.setTransformedPos_00c7f640(worldTransform, p);
                drawer->drawLine(a, b, PackColorBigEndian(0.0f, DAT_0101622c, 1.0f, 1.0f), id, tag);
            }
            hkVector4Array_ClearAndRelease(points, PointToPathHeap(hkMemoryRouter_getInstance()));
        }
    }
}
