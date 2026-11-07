#pragma once

class hkgpConvexHull;

class hkgpMesh_IConvexOverlap {
public:
    void** vftable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* pVertexList;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* pVertexList2;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    hkgpConvexHull* pConvexHull;

    hkgpConvexHull* GetConvexHull();
};
