#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/common/internal/kdtree/build/hkkdtreebuilder_o2_nood_variant_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/kdtree/build/hkkdtreebuilder_o2_nood_variant_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/kdtree/build/hkkdtreebuilder_o2_nood_variant_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/kdtree/build/hkkdtreebuilder_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
#include "fnv_asm_helpers.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkStackMemory.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkErrStream.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkOstream.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkSingleton.h"


template<typename T>
__forceinline T& __cdecl hkSingleton<T>::GetMonitorStream()
{
    return *s_instance;
}

// src/havok/common/internal/kdtree/build/hkkdtreebuilder_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/havok/common/internal/kdtree/build/hkkdtreebuilder.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.
// src/havok/common/internal/kdtree/build/hkkdtreebuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/kdtree/build/hkkdtreebuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const char DAT_010da240[];
extern const char DAT_010da21c[];
typedef float hkReal;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;



typedef ::__m128 LocalM128;
typedef LocalM128 hkQuadReal;
class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};static const hkQuadReal ms_kMaskValues[MASK_XYZW+1];
__forceinline void set(Mask m){m_uiMask=ms_kMaskValues[m];}
private:
hkQuadReal m_uiMask;};extern "C"{
double __cdecl fabs([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]double _X);inline float fabsf([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]float _X)
{return((float)fabs((double)_X));}
}
namespace MathUtilities
{inline hkReal __cdecl fabs(hkReal r){return fabsf(r);}
template<typename T>
inline T __cdecl max2(T x,T y)
{
return x>y ? x:y;
}
template<typename T>
inline T __cdecl min2(T x,T y)
{
return x<y ? x:y;
}
}
class MemoryUtils
{
public:
enum ReplaceType
{
REPLACE_ONE,
REPLACE_ALL
};
static __forceinline void __cdecl memClear16(void*dst,int numQuads);
private:
static void copyAndReplace(char*dest,const char*orig,int origLen,const MemoryUtils&from,const MemoryUtils&to,const hkArray<int>&indices);};void __cdecl MemoryUtils::memClear16(void*dst,int numQuads)
{
;
hkUint32*dst32=reinterpret_cast<hkUint32*>(dst);
{
for(int i=0;i<numQuads;i++)
{
dst32[0]=0;
dst32[1]=0;
dst32[2]=0;
dst32[3]=0;
dst32+=4;
}
}
}
typedef union __declspec(intrin_type)__declspec(align(16))__m128i{
__int8 m128i_i8[16];
__int16 m128i_i16[8];
__int32 m128i_i32[4];
__int64 m128i_i64[2];
unsigned __int8 m128i_u8[16];
unsigned __int16 m128i_u16[8];
unsigned __int32 m128i_u32[4];
unsigned __int64 m128i_u64[2];
}__m128d;
extern "C"{
extern __m128i _mm_setzero_si128(void);};
typedef __m128i hkQuadUint;
class UnsignedIntegerVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void setZero();
private:
hkQuadUint m_vComponents;
public:
operator hkQuadUint()const
{
return m_vComponents;
}
};
inline void UnsignedIntegerVector4::setZero()
{
m_vComponents=_mm_setzero_si128();
}
typedef hkUint16 hkSplitType;
typedef hkUint16 hkHalfPointer;
class KdTreeNode
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline KdTreeNode();
__forceinline void setSplit(int axis,hkSplitType splitMin,hkSplitType splitMax);
__forceinline void setLeftAndRightByteOffset(hkUlong offset);
private:
struct Pair3Pool
{
__declspec(align(8))hkInt32 m_iPrimitiveStartIndex;
hkUint32 m_iNumPrimitives;
};
struct Node
{
hkInt32 m_iSplitValue;
hkSplitType m_eLeftSplitType;
hkSplitType m_eRightSplitType;
};
union{
Pair3Pool m_pLeafNode;
Node m_node;
}m_data;};
struct FieldlessRecord
{
__declspec(align(16))hkSplitType m_kMinimumCorner[3];
hkHalfPointer m_usFirstVectorPadding;
hkSplitType m_kMaximumCorner[3];
void operator=(const FieldlessRecord&other)
{
*(hkQuadReal*)this=*(const hkQuadReal*)&other;
}
};
class KdTree
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
static __forceinline int __cdecl getSizeForFastBuild(int numPrimitives){return 2*numPrimitives;}
protected:
void AllocateNodes(int numNodes);};KdTreeNode::KdTreeNode()
{
m_data.m_pLeafNode.m_iPrimitiveStartIndex=0x7FFFFFFF;
m_data.m_pLeafNode.m_iNumPrimitives=0;
}
void KdTreeNode::setSplit(int axis,hkSplitType splitMin,hkSplitType splitMax)
{
;
m_data.m_node.m_eLeftSplitType=splitMin;
m_data.m_node.m_eRightSplitType=splitMax;
m_data.m_node.m_iSplitValue=0x80000000 |(m_data.m_node.m_iSplitValue&0xFFFFFFFC)| axis;
}
void KdTreeNode::setLeftAndRightByteOffset(hkUlong offset)
{
;
;
m_data.m_node.m_iSplitValue=(m_data.m_node.m_iSplitValue&0x80000003)|((hkUint32)offset);
}
class KdTreeEdgeIndex;
namespace hkKdTreeBuildInput
{
struct KdTreeNodeReference
{
KdTreeNode*m_pTreeNode;
};
struct WorkingSet
{
FieldlessRecord*m_pProjectedEntryBegin;
FieldlessRecord*m_pProjectedEntryEnd;
};
struct ProjectedBoundsContext
{
WorkingSet*m_pWorkingSet;
int m_iFirstInputValue;
int m_iSecondInputValue;
int m_iThirdValue;
int m_iFourthInputValue;
FieldlessRecord m_kBounds;
KdTreeEdgeIndex*m_pStreamWriter;
Vector4Comparison m_kComparison;
ProjectedBoundsContext():m_iSecondInputValue(-1)
{
m_kComparison.set(Vector4Comparison::MASK_XYZ);
}
};}
enum hkSplitPrimitivesStatus
{
SPLIT_PRIMITIVES_OK,
SPLIT_PRIMITIVES_INDISTINGUISHABLE
};
class hkKdTreeBuilder
{
public:
struct SplitInfo
{
int m_iFirstSplitValue;
int m_iSecondSplitValue;
hkSplitType m_eLeftSplitType;
hkSplitType m_eRightSplitType;
};
static hkSplitPrimitivesStatus __cdecl splitPrimitives(const hkKdTreeBuildInput::WorkingSet&buffersIn,int startPrimIdx,int endPrimIdx,SplitInfo&results,
int&numAvailableEmptyNodes,hkKdTreeBuildInput::WorkingSet&buffersOut,const FieldlessRecord&bounds,hkVector4ComparisonParameter allowedEmptySplits);
static int __cdecl buildTreeRecursive(const hkKdTreeBuildInput::ProjectedBoundsContext&input,hkKdTreeBuildInput::KdTreeNodeReference*streamOut,FieldlessRecord*peOut,int&numAllocatedNodes,int&numEmptyNodesRemaining);
static void __cdecl checkBuildRecursiveInput(const hkKdTreeBuildInput::ProjectedBoundsContext&subJob);
static hkSplitPrimitivesStatus __cdecl splitPrimitivesExactly(const hkKdTreeBuildInput::WorkingSet&buffersIn,int startPrimIdx,int endPrimIdx,
SplitInfo&results,hkKdTreeBuildInput::WorkingSet&buffersOut,const FieldlessRecord&bounds);
static void __cdecl ProcessEntries_00df37b0(const hkKdTreeBuildInput::WorkingSet&buffersIn,KdTreeNode*treeOut,int treeSize,int numPrimitives,hkKdTreeBuildInput::ProjectedBoundsContext*subJobs,int subTreeSizes[4],const FieldlessRecord&bounds);
static void __cdecl writeEmptyLeaf(KdTreeNode*treeRoot,int nodeIdx,class KdTreeEdgeIndex*writer);
static void __cdecl writeSinglePrimitiveToLeaf(KdTreeNode*treeRoot,FieldlessRecord*entriesIn,FieldlessRecord*projEntOut,int nodeIdx,int primIdx,KdTreeEdgeIndex*writer);
static int __cdecl writeMultiplePrimitivesToLeaf(KdTreeNode*__restrict treeRoot,const FieldlessRecord*entriesIn,FieldlessRecord*__restrict projEntOut,int nodeIdx,int primIdx,int numPrims,KdTreeEdgeIndex*writer);
};
typedef const FieldlessRecord*ProjectedEntryDirectReadIterator;
typedef FieldlessRecord*__restrict ProjectedEntryDirectWriteIterator;
class KdTreeEdgeIndex
{
public:
KdTreeEdgeIndex();
protected:
void flush();
int m_uiEdgeIndex;};
inline void initializeIterator(ProjectedEntryDirectReadIterator&it,const FieldlessRecord*ptr)
{
it=ptr;
}
inline void initializeIterator(ProjectedEntryDirectWriteIterator&it,FieldlessRecord*ptr)
{
it=ptr;
}
inline void WRITE_NODE_WITH_MANAGER(KdTreeNode*root,int currentNodeIdx,KdTreeNode&thisNode,KdTreeEdgeIndex*writer)
{
root[currentNodeIdx]=thisNode;
}
inline KdTreeEdgeIndex::KdTreeEdgeIndex()
{
m_uiEdgeIndex=0;
}
// @fnv 0x00df37b0
// src: GUESS 0x00df37b0 (confidence: low)
void hkKdTreeBuilder::ProcessEntries_00df37b0(const hkKdTreeBuildInput::WorkingSet&buffersIn,KdTreeNode*treeOut,int treeSize,int numPrimitives,hkKdTreeBuildInput::ProjectedBoundsContext*subJobs,int subTreeSizes[4],const FieldlessRecord&bounds)
{

__declspec(align(128))int distIn[64][4];
__declspec(align(128))int distOut[64][4];
MemoryUtils::memClear16(distIn,64);
MemoryUtils::memClear16(distOut,64);
ProjectedEntryDirectReadIterator entry;
initializeIterator(entry,buffersIn.m_pProjectedEntryBegin);
int skip=1;
if(numPrimitives>10)
skip=2;
if(numPrimitives>100)
skip=3;
if(numPrimitives>1000)
skip=4;
if(numPrimitives>10000)
skip=5;
{
UnsignedIntegerVector4 zero;
zero.setZero();
for(int idx=0;idx<numPrimitives;idx+=skip)
{
FieldlessRecord tempEntry=*entry;
distIn[tempEntry.m_kMinimumCorner[0]>>10][0]++;
distOut[tempEntry.m_kMaximumCorner[0]>>10][0]++;
distIn[tempEntry.m_kMinimumCorner[1]>>10][1]++;
distOut[tempEntry.m_kMaximumCorner[1]>>10][1]++;
distIn[tempEntry.m_kMinimumCorner[2]>>10][2]++;
distOut[tempEntry.m_kMaximumCorner[2]>>10][2]++;
entry+=skip;
}
}
int numPrimsBucketted=numPrimitives / skip;
hkReal bestCost=3.40282e+38f;
int numPartitioned[4]={0,0,0,0};
int splitAxis=-1;
int splitPlaneMidLeft=-1;
int splitPlaneMid=-1;
int splitPlaneMidRight=-1;
for(int d=0;d<3;d++)
{
int splitMid=0;
int numLeft=distIn[0][d];
int numRight=numPrimsBucketted-distOut[0][d];
int bestLeftMid=0;
int bestRightMid=0;
hkReal bestCostMid=3.40282e+38f;
for(int i=1;i<62;i++)
{
numLeft+=distIn[i][d];
numRight-=distOut[i][d];
hkReal cost=MathUtilities::fabs(hkReal(numLeft-numRight));
if(cost<bestCostMid)
{
bestCostMid=cost;
bestLeftMid=numLeft;
bestRightMid=numRight;
splitMid=i;
}
}
numLeft=0;
numRight=bestLeftMid;
int splitMidLeft=0;
int bestLeftMidLeft=0;
int bestRightMidLeft=0;
hkReal bestCostMidLeft=3.40282e+38f;
for(int j=0;j<splitMid;j++)
{
numLeft+=distIn[j][d];
numRight-=distOut[j][d];
hkReal cost=MathUtilities::fabs(hkReal(numLeft-numRight));
if(cost<bestCostMidLeft)
{
bestCostMidLeft=cost;
bestLeftMidLeft=numLeft;
bestRightMidLeft=numRight;
splitMidLeft=j;
}
}
numLeft=0;
numRight=bestRightMid;
int splitMidRight=0;
int bestLeftMidRight=0;
int bestRightMidRight=0;
hkReal bestCostMidRight=3.40282e+38f;
for(int k=splitMid+1;k<63;k++)
{
numLeft+=distIn[k][d];
numRight-=distOut[k][d];
hkReal cost=MathUtilities::fabs(hkReal(numLeft-numRight));
if(cost<bestCostMidRight)
{
bestCostMidRight=cost;
bestLeftMidRight=numLeft;
bestRightMidRight=numRight;
splitMidRight=k;
}
}
int jobSize[4];
jobSize[0]=bestLeftMidLeft;
jobSize[1]=bestRightMidLeft;
jobSize[2]=bestLeftMidRight;
jobSize[3]=bestRightMidRight;
hkReal cost=0.0f;
for(int ji=0;ji<3;ji++)
{
for(int jj=ji;jj<4;jj++)
{
cost+=MathUtilities::fabs(hkReal(jobSize[ji]-jobSize[jj]));
}
}
if(cost<bestCost)
{
bestCost=cost;
splitAxis=d;
splitPlaneMidLeft=splitMidLeft;
splitPlaneMid=splitMid;
splitPlaneMidRight=splitMidRight;
numPartitioned[0]=jobSize[0];
numPartitioned[1]=jobSize[1];
numPartitioned[2]=jobSize[2];
numPartitioned[3]=jobSize[3];
}
}
int jobSize[4];
jobSize[0]=0;
jobSize[1]=0;
jobSize[2]=0;
jobSize[3]=0;
hkSplitType min[4];
hkSplitType max[4];
min[0]=bounds.m_kMaximumCorner[splitAxis];
min[1]=bounds.m_kMaximumCorner[splitAxis];
min[2]=bounds.m_kMaximumCorner[splitAxis];
min[3]=bounds.m_kMaximumCorner[splitAxis];
max[0]=bounds.m_kMinimumCorner[splitAxis];
max[1]=bounds.m_kMinimumCorner[splitAxis];
max[2]=bounds.m_kMinimumCorner[splitAxis];
max[3]=bounds.m_kMinimumCorner[splitAxis];
int splittingValue0=(splitPlaneMidLeft+1)<<10;
int splittingValue1=(splitPlaneMid+1)<<10;
int splittingValue2=(splitPlaneMidRight+1)<<10;
initializeIterator(entry,buffersIn.m_pProjectedEntryBegin);
FieldlessRecord*endEntry=buffersIn.m_pProjectedEntryBegin+numPrimitives;
hkBool fullyBalancedFallback=(numPartitioned[0]==0 || numPartitioned[1]==0 || numPartitioned[2]==0 || numPartitioned[3]==0);
if(fullyBalancedFallback)
{
fullyBalancedFallbackJump:

;
int evenJobSize=numPrimitives / 4;

if(treeSize<KdTree::getSizeForFastBuild(evenJobSize)*4+8)
{

if(1){char assertBuf[512];hkErrStream ostr(assertBuf,sizeof(assertBuf));static_cast<hkOstream&>(ostr)<<DAT_010da240;if(hkError::GetMonitorStream().message(hkError::MESSAGE_ERROR,0x5010d60c,assertBuf,DAT_010da21c,408)){fnv_Breakpoint();}}else;
}
FieldlessRecord*endEntries[4];
endEntries[0]=buffersIn.m_pProjectedEntryBegin+evenJobSize;
endEntries[1]=buffersIn.m_pProjectedEntryBegin+evenJobSize*2;
endEntries[2]=buffersIn.m_pProjectedEntryBegin+evenJobSize*3;
endEntries[3]=endEntry;
for(int j=0;j<4;j++)
{
while(entry<endEntries[j])
{
hkSplitType minE=entry->m_kMinimumCorner[(hkInt16)splitAxis];
hkSplitType maxE=entry->m_kMaximumCorner[(hkInt16)splitAxis];
jobSize[j]++;
min[j]=MathUtilities::min2(min[j],minE);
max[j]=MathUtilities::max2(max[j],maxE);
entry++;
}
}
}
else
{
while(entry<endEntry)
{
hkSplitType minE=entry->m_kMinimumCorner[(hkInt16)splitAxis];
hkSplitType maxE=entry->m_kMaximumCorner[(hkInt16)splitAxis];
if(minE<splittingValue0)
{
jobSize[0]++;
min[0]=MathUtilities::min2(min[0],minE);
max[0]=MathUtilities::max2(max[0],maxE);
}
else if(minE<splittingValue1)
{
jobSize[1]++;
min[1]=MathUtilities::min2(min[1],minE);
max[1]=MathUtilities::max2(max[1],maxE);
}
else if(minE<splittingValue2)
{
jobSize[2]++;
min[2]=MathUtilities::min2(min[2],minE);
max[2]=MathUtilities::max2(max[2],maxE);
}
else
{
jobSize[3]++;
min[3]=MathUtilities::min2(min[3],minE);
max[3]=MathUtilities::max2(max[3],maxE);
}
entry++;
}
if(jobSize[0]==0 || jobSize[1]==0 || jobSize[2]==0 || jobSize[3]==0)
{
fullyBalancedFallback.m_cBooleanValue=1;
min[0]=bounds.m_kMaximumCorner[splitAxis];
min[1]=bounds.m_kMaximumCorner[splitAxis];
min[2]=bounds.m_kMaximumCorner[splitAxis];
min[3]=bounds.m_kMaximumCorner[splitAxis];
max[0]=bounds.m_kMinimumCorner[splitAxis];
max[1]=bounds.m_kMinimumCorner[splitAxis];
max[2]=bounds.m_kMinimumCorner[splitAxis];
max[3]=bounds.m_kMinimumCorner[splitAxis];
jobSize[0]=0;
jobSize[1]=0;
jobSize[2]=0;
jobSize[3]=0;
initializeIterator(entry,buffersIn.m_pProjectedEntryBegin);
goto fullyBalancedFallbackJump;
}
}

;
;
;
;
;
ProjectedEntryDirectWriteIterator dest0;
ProjectedEntryDirectWriteIterator dest1;
ProjectedEntryDirectWriteIterator dest2;
ProjectedEntryDirectWriteIterator dest3;
initializeIterator(dest0,buffersIn.m_pProjectedEntryEnd);
initializeIterator(dest1,buffersIn.m_pProjectedEntryEnd+jobSize[0]);
initializeIterator(dest2,buffersIn.m_pProjectedEntryEnd+jobSize[0]+jobSize[1]);
initializeIterator(dest3,buffersIn.m_pProjectedEntryEnd+jobSize[0]+jobSize[1]+jobSize[2]);
initializeIterator(entry,buffersIn.m_pProjectedEntryBegin);
if(fullyBalancedFallback)
{
int evenJobSize=numPrimitives / 4;
FieldlessRecord*endEntries[4];
endEntries[0]=buffersIn.m_pProjectedEntryBegin+evenJobSize;
endEntries[1]=buffersIn.m_pProjectedEntryBegin+evenJobSize*2;
endEntries[2]=buffersIn.m_pProjectedEntryBegin+evenJobSize*3;
endEntries[3]=endEntry;
while(entry<endEntries[0])
{
*dest0=*entry;
dest0++;
entry++;
}
while(entry<endEntries[1])
{
*dest1=*entry;
dest1++;
entry++;
}
while(entry<endEntries[2])
{
*dest2=*entry;
dest2++;
entry++;
}
while(entry<endEntries[3])
{
*dest3=*entry;
dest3++;
entry++;
}
}
else
{
while(entry<endEntry)
{
hkSplitType minE=entry->m_kMinimumCorner[(hkInt16)splitAxis];
if(minE<splittingValue0)
{
*dest0=*entry;
dest0++;
}
else if(minE<splittingValue1)
{
*dest1=*entry;
dest1++;
}
else if(minE<splittingValue2)
{
*dest2=*entry;
dest2++;
}
else
{
*dest3=*entry;
dest3++;
}
entry++;
}
}

;
;
;
;
KdTreeEdgeIndex sparseWriter;
{
KdTreeNode thisNode;
thisNode.setSplit(splitAxis,MathUtilities::min2(min[2],min[3]),MathUtilities::max2(max[1],max[0]));
thisNode.setLeftAndRightByteOffset(16);
WRITE_NODE_WITH_MANAGER(treeOut,0,thisNode,&sparseWriter);
}
{
KdTreeNode thisNode;
thisNode.setSplit(splitAxis,min[1],max[0]);
thisNode.setLeftAndRightByteOffset(16);
WRITE_NODE_WITH_MANAGER(treeOut,2,thisNode,&sparseWriter);
}
{
KdTreeNode thisNode;
thisNode.setSplit(splitAxis,min[3],max[2]);
thisNode.setLeftAndRightByteOffset(24);
WRITE_NODE_WITH_MANAGER(treeOut,3,thisNode,&sparseWriter);
}
hkKdTreeBuildInput::WorkingSet buffersOut;
buffersOut.m_pProjectedEntryEnd=buffersIn.m_pProjectedEntryBegin;
buffersOut.m_pProjectedEntryBegin=buffersIn.m_pProjectedEntryEnd;
int count=0;
for(int i=0;i<4;i++)
{
*subJobs[i].m_pWorkingSet=buffersOut;
subJobs[i].m_iThirdValue=count;
count+=jobSize[i];
subJobs[i].m_iFourthInputValue=count;
subJobs[i].m_iFirstInputValue=0;
subJobs[i].m_kBounds=bounds;
subJobs[i].m_kBounds.m_kMinimumCorner[splitAxis]=min[i];
subJobs[i].m_kBounds.m_kMaximumCorner[splitAxis]=max[i];
subJobs[i].m_iSecondInputValue=treeSize;
subTreeSizes[i]=KdTree::getSizeForFastBuild(jobSize[i]);
}

;
}
