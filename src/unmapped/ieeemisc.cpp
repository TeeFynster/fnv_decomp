
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

int FUN_00ec75b1(double value);
int FUN_00ec7595(double value);
double FUN_00ec6cde(double value);
void ReportAssertionViolation(const char* file, int line);
extern float DAT_01016970;
extern float DAT_01015f5c;
// @fnv 0x00ac79e0
// src: GUESS 0x00ac79e0 (confidence: low)
float Object_ProcessAndReturnValue_00ac79e0(float a, float b)
{
    float fSum;
    if (!FUN_00ec75b1(a))
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0x1b2);
    }
    if (!FUN_00ec75b1(b))
    {
    }
    else
    {
        ReportAssertionViolation("D:\\_Fallout3\\Platforms\\Common\\Code\\SDK\\FaceGen\\algs.cpp", 0x1b3);
    }
    fSum = a + b;
    if (!FUN_00ec7595(fSum))
    {
        if ((double)fSum == (float)FUN_00ec6cde(fSum))
        {
            return DAT_01016970;
        }
        else
        {
            return DAT_01015f5c;
        }
    }
    return fSum;
}
