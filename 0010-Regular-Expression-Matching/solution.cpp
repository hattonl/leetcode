#include <string>

// Recursion

class Solution {
public:
    bool isMatch(string s, string p) {
        
        if (p.length() == 0)
            return (s.length() == 0);
        
        bool firstMatch = (s.length() != 0) && (p[0] == '.' || p[0] == s[0]);
        
        if (p.length() >= 2 && p[1] == '*')
        {
            return isMatch(s, p.substr(2)) ||
                   (firstMatch && isMatch(s.substr(1), p));
        }
        else
        {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// DP

class Solution2 {
public:
    bool isMatch(string s, string p) {

        bool dp[s.length()+1][p.length()+1];

        dp[0][0] = true;

        // init
        for (int i = 1; i <= s.length(); i++) dp[i][0] = false;
        for (int j = 1; j <= p.length(); j++)
            dp[0][j] = (p[j-1] == '*'? (dp[0][j-1] || (j>1? dp[0][j-2]: true)): false);
        
        // dp start
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= p.length(); j++)
            {
                if (p[j-1] == '.' || p[j-1] == s[i-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*')
                {
                    if (p[j-2] == '.' || p[j-2] == s[i-1])
                        dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[s.length()][p.length()];
    }
};
