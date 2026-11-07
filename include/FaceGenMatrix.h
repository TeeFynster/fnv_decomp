#pragma once

struct FaceGenCoordinateValue;
struct MxIter;
struct MxConstIter;

// FaceGenMatrix<T>: a row/column matrix over a std::vector<T>; TESNPC and TESRace hold FaceGenMatrix<float> arrays
// (sizeof 32), and BSFaceGenModel/bipedanim/bsfacegenmanager take FaceGenCoord arguments.
template <class T> class FaceGenMatrix
{
public:
    // A std::vector<T> (24 bytes in this VC9 build): no char storage, so a local FaceGenMatrix gets no /GS buffer
    // treatment (BipedAnim 0x004af490 and 0x004ac1e0 have none).
    unsigned int vectorHeader[3];
    T* m_pFirst;
    T* m_pLast;
    T* m_pEnd;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;
    FaceGenMatrix();
    FaceGenMatrix(unsigned int rows, unsigned int cols);
    FaceGenMatrix(const FaceGenMatrix& rhs);
    ~FaceGenMatrix();
    void SetDimensions(unsigned int, unsigned int);
    void resize(unsigned int, bool);
    void FillMemory_0060b3b0();
    unsigned int NiAVObject_GetParent();
    unsigned int FUN_00441110();
    FaceGenMatrix& operator=(const FaceGenMatrix&);
    FaceGenMatrix operator*(const FaceGenMatrix& rhs);
    float GetTrace();
    FaceGenCoordinateValue ForwardCall_0060b370(unsigned int row);
    FaceGenCoordinateValue ForwardCall_0060b370(unsigned int row, unsigned int col);
    T* GetElementPointerChecked(unsigned int);
    T* GetElementPointerChecked(unsigned int) const;
    T* GetElementPointerChecked(unsigned int, unsigned int) const;
    bool FUN_00657880(const FaceGenMatrix* apOther) const;
    unsigned int std_vector_float_std_allocator_float_size();
    void FUN_00658f30(const FaceGenMatrix<float>& rhs);
    FaceGenMatrix Scaled(float afScale) const;
    void Assign(const FaceGenMatrix& arOther);
    void FUN_006581e0(FaceGenMatrix*);
    float FUN_006588a0();
    void ScaleAll(float);
    void std_vector_float_std_allocator_float_clear();
    void PushBack(const T&);
    FaceGenMatrix* AddMatrix(FaceGenMatrix* other);
    MxIter begin();
    MxIter end();
    MxConstIter EvaluateValue_0065fd10() const;
    MxConstIter ProcessAndReturnValue_0065fd40() const;
};
typedef FaceGenMatrix<float> FaceGenCoord;
