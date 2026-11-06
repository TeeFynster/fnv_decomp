
// @fnv 0x00407840
unsigned int TESPackage::GetRefCount()
{
    return unk07C;
}
// @fnv 0x008d83e0
BSTreeModel* BSTreeNode::GetModelFilePath()
{
    return reinterpret_cast<BSTreeModel*>(model.operator->());
}
