class Solution {
public:
    int strStr(string haystack, string needle) {
        int lastCheckPoint = haystack.length() - needle.length();
        if (needle.length() == 0) return 0;
        if (lastCheckPoint < 0) return -1;
        
        for (int i = 0; i <= lastCheckPoint; ++i)
        {
            int point = i;
            for (int j = 0; j < needle.length();)
            {
                if (needle[j++] != haystack[point++])
                    break;
                
                if (j == needle.length())
                    return i;
            }
        }
        
        return -1;
    }
};

// 其他算法

