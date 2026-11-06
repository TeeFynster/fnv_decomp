// This instantiation uses the canonical folded smart-pointer lifetime routines.
class ObstacleData;
template <> NiPointer<ObstacleData>::NiPointer(const NiPointer&);
template <> NiPointer<ObstacleData>::~NiPointer();
