// dp solution

#define MAX(x, y) (x > y? x: y)

int findLength(int* A, int ASize, int* B, int BSize) {
    int *L    = NULL;
    int *S    = NULL;
    int LSize = 0;
    int SSize = 0;
    int *dp   = NULL;
    int ret   = 0;

    if (ASize == 0 || BSize == 0) return 0;

    if (ASize > BSize)
    {
        L = A;
        S = B;
        LSize = ASize;
        SSize = BSize; 
    }
    else
    {
        L = B;
        S = A;
        LSize = BSize;
        SSize = ASize; 
    }

    dp = (int *)calloc(SSize, sizeof(int));

    for (int i = 0; i < LSize; i++)
    {
        for (int j = SSize - 1; j >= 0; j--)
        {
            dp[j] = L[i] == S[j]? (i == 0 || j == 0? 1: dp[j-1] + 1): 0;
            
            ret = MAX(ret, dp[j]);
        }
    }

    free(dp);

    return ret;
}
