#pragma once

// Havok 7.1 Common/Base/Monitor/MonitorStreamAnalyzer/hkMonitorStreamAnalyzer.h; so far only the node type
// (values: the 7.1.0-r1 hkbase.pdb, hkMonitorStreamAnalyzer::Node::NodeType).
class hkMonitorStreamAnalyzer
{
public:
    struct Node
    {
        enum NodeType
        {
            NODE_TYPE_TIMER = 0,
            NODE_TYPE_DIRECTORY = 1,
            NODE_TYPE_SINGLE = 2
        };
    };
};
