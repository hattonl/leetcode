#define ISALPANUMERIC(x) ( (x <= 'Z' && x >= 'A') \
                        || (x <= 'z' && x >= 'a') \
                        || (x <= '9' && x >= '0'))

class Solution {
public:
    bool isPalindrome(string s) {
        int strlen = s.length();
        
        int i = 0, j = strlen-1;
        
        while (true)
        {
            while (!ISALPANUMERIC(s[i]) && i < j)
                ++i;
            
            while (!ISALPANUMERIC(s[j]) && i < j)
                --j;
            
            if (i < j)
            {
                if (s[i] <= 'Z' && s[i] >= 'A')
                {
                    s[i] += ('a' - 'A');
                }
                
                if (s[j] <= 'Z' && s[j] >= 'A')
                {
                    s[j] += ('a' - 'A');
                }
                
                if (s[i] != s[j])
                    return false;
            }
            else
                break;
            
            ++i;
            --j;
        }
        
        return true;
    }
};