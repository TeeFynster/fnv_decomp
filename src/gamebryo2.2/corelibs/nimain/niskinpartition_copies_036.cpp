
// Provisional build file (plan B2): exact copies of the niskinpartition recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
#include "../../../../include/NiAccumulator.h"
#include "../../../../include/NiSkinPartition.h"

struct Twin_00af3000 : public NiAccumulator
{
    void SetSortingCamera(const NiCamera* camera);
};
// @fnv 0x00af3000
void Twin_00af3000::SetSortingCamera(const NiCamera* camera)
{
    m_pkCamera = camera;
}
