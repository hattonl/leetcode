// 

#define MAX(x, y) (x > y? x: y)
#define MIN(x, y) (x > y? y: x)

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *A = nums1;
    int *B = nums2;
    int n  = nums1Size;
    int m  = nums2Size;

    int left   = 0;
    int right  = 0;
    int half   = 0;
    double ret = 0.0;

    if (n > m)
    {
        A = nums2, B = nums2;
        n = nums2Size, m = nums1Size;
    }

    right = n;
    half = (m + n + 1)/2;
    while (left <= right) // 满足继续查找条件  查找结束后  i 的范围在 [0, n] 最小为0，最大为n
    {
        int i = (left + right)/2;
        int j = half - i;

        if (i > left && A[i-1] > B[j]) // i 要减小
        {
            right = i - 1;
        }
        else if (i < right && A[i] < B[j-1]) // i 要增加
        {
            left = i + 1;
        }
        else
        {
            int max_left = 0;
            int min_right = 0;

            if (i == 0)
            {
                max_left = B[j-1];

                if (B[])
            }
            if (i == 0) // 判断是否满足要求
            // 1. max(A[i-1], B[j-1])  (0 < i <= n)
            // 2. B[j-1]   (i <= 0)
            if (i == 0) max_left = B[j - 1]; // 
            else max_left = MAX(A[i-1], B[j-1]);

            if (i == n)
            {
                // i == n 且满足要求 max_left = MAX(A[i-1], B[j-1]);
                // i == n 但不满足要求 max_left = 
            }
                // odd 
                // i = 0 ret = B[j-1]
                // i = n 
                // 
            // min_right
            // 1. min(A[i], B[j])  (i = 0, i = n - 1)
            // 2. B[j]   ( i = n )
            if (i = n) min_right = B[j];
            else min_right = MIN(A[i], B[j]);

            ret = (max_left + min_right) / 2.0f;
        }
    }

    return ret;

}
