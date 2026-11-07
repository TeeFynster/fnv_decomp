
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) void __stdcall D3DXMatrixTranspose(void);
// @fnv 0x00ee6dd4
// src: COMMUNITY 0x00ee6dd4
void D3DXMatrixTranspose_00ee6dd4()
{
    D3DXMatrixTranspose();
}

float* __stdcall D3DXMatrixInverse_00ee6dda(float* pOut, float* pDeterminant, const float* pM);
float* __stdcall D3DXMatrixTranspose_00ee6dd4(float* pOut, const float* pM);

// Builds a 4x4 matrix from a 2D affine transform (layout depends on iMode), optionally inverts and transposes it, or sets identity when affine is null.
// @fnv 0x00e83550
void __cdecl SetAffineMatrix(float* afMatrix, const float* affine, bool bInvert, bool bTranspose, int iMode)
{
    if (affine)
    {
        afMatrix[0] = affine[0];
        afMatrix[4] = affine[1];
        afMatrix[1] = affine[3];
        afMatrix[5] = affine[4];
        if (iMode == 4 || iMode == 3)
        {
            afMatrix[8] = 0.0f;
            afMatrix[12] = affine[2];
            afMatrix[9] = 0.0f;
            afMatrix[13] = affine[5];
        }
        else if (iMode == 2)
        {
            afMatrix[8] = affine[2];
            afMatrix[12] = 0.0f;
            afMatrix[9] = affine[5];
            afMatrix[13] = 0.0f;
        }
        afMatrix[14] = 0.0f;
        afMatrix[10] = 0.0f;
        afMatrix[6] = 0.0f;
        afMatrix[2] = 0.0f;
        afMatrix[15] = 0.0f;
        afMatrix[11] = 0.0f;
        afMatrix[7] = 0.0f;
        afMatrix[3] = 0.0f;
        if (bInvert)
            D3DXMatrixInverse_00ee6dda(afMatrix, 0, afMatrix);
        if (bTranspose)
            D3DXMatrixTranspose_00ee6dd4(afMatrix, afMatrix);
    }
    else
    {
        afMatrix[14] = 0.0f;
        afMatrix[13] = 0.0f;
        afMatrix[12] = 0.0f;
        afMatrix[11] = 0.0f;
        afMatrix[9] = 0.0f;
        afMatrix[8] = 0.0f;
        afMatrix[7] = 0.0f;
        afMatrix[6] = 0.0f;
        afMatrix[4] = 0.0f;
        afMatrix[3] = 0.0f;
        afMatrix[2] = 0.0f;
        afMatrix[1] = 0.0f;
        afMatrix[15] = 1.0f;
        afMatrix[10] = 1.0f;
        afMatrix[5] = 1.0f;
        afMatrix[0] = 1.0f;
    }
}
