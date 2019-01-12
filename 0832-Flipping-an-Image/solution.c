/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {    
    int **ret = (int **)malloc(sizeof(int *) * ARowSize);
    *columnSizes = (int *)malloc(sizeof(int) * ARowSize);
    
    for (int i = 0; i < ARowSize; i++)
    {
        ret[i] = (int *)malloc(sizeof(int) * AColSizes[i]);
        (*columnSizes)[i] = AColSizes[i];
        for (int j = 0; j < AColSizes[i]; j++)
        {
            ret[i][AColSizes[i]-j-1] = (A[i][j] == 1 ? 0: 1);
        }
    }

    *returnSize = ARowSize;
    return ret;
}
