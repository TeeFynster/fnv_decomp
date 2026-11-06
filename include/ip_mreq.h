#pragma once

#include "in_addr.h"

class ip_mreq
{
public:
    in_addr imr_multiaddr;
    in_addr imr_interface;
};
