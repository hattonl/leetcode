class Solution {
public:
    int climbStairs(int n) {
        
        int first = 1;
        int second = 2;
        int ret = 0;
        
        if (n <= 3) return n;
        
        for (int i = 3; i <= n; ++i)
        {
            ret = first + second;
            first = second;
            second = ret;
        }
        
        return ret;
    }
};
