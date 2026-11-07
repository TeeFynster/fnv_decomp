#pragma once

#include "PathingRequest.h"
#include "BSSimpleArray.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class __declspec(novtable) PathingRequestLOS : public PathingRequest
{
public:
    PathingRequestLOS();
    PathingRequestLOS(const PathingRequestLOS&);
    PathingRequestLOS(const PathingRequest*);
    virtual ~PathingRequestLOS();
    virtual void CopyTo(PathingRequest*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);


    void* DestroyAndFree(unsigned int flags);
    void InitFromActor(void*);
    void SetCantOpenDoors(bool);
    void PathingRequest_SetNoDestination();
    void AssignAtOffsetB0(const NiPointer<void>&);
    void SetByteAtOffset9B(int);
    const NiPointer<Actor>& GetLOSActor() const;
    void SetSearchCenter(NiPoint3, float);
    void PathingRequestLOS_SetIgnoreLocationRadius(float);
    void PathingRequestLOS_SetIgnoreLocations(void*);
    NiPoint3& GetPosition(NiPoint3&) const;
    float GetRadius() const;
    void Place(NiPoint3, float);

    struct ParentSpaceNode
    {
        union
        {
            unsigned char data[12];
            unsigned char unk00[12];
        };
    };

    class NodeArray : public BSSimpleArray<ParentSpaceNode, 1024>
    {
    public:
        NodeArray();
        virtual ~NodeArray();
        void CopyTo(NodeArray*);
        void CopyTo(NodeArray*) const;
        void SetSize(int, int);

    };

    struct LOSData
    {
        NiPointer<Actor> m_b0;
        NodeArray m_b4;
        union
        {
            float m_c4;
            float m_fWeight;
            int unkc4;
        };
        NiPoint3 m_c8;
        union
        {
            float m_d4;
            int unkd4;
        };
    };

    union
    {
        char extra[40];
        struct
        {
            NiPointer<Actor> m_b0;
            NodeArray m_b4;
            union
            {
                float m_c4;
                float m_fWeight;
                int unkc4;
            };
            NiPoint3 m_c8;
            union
            {
                float m_d4;
                int unkd4;
            };
        };
    };
};
