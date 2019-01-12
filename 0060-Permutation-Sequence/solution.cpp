class Solution {
public:
    string getPermutation(int n, int k) {
        
        string ret = "";
        vector <int> factorial(n+1, 1);
        vector <char> number(n, '1');

        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i-1]*i;
            number[i]    = '0' + i + 1;
        }
        factorial[n] = factorial[n-1] * n;
        
        for (--k; n > 0; --n) {
            int index = k / factorial[n-1];
            ret = ret + number[index];
            number.erase(number.begin() + index);
            k -= index * factorial[n-1];
        }
        return ret;
    }
};
