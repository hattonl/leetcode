// dp solution
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int i = 0, j = 0;
    int len    = 0;
    int maxLen = 0;
    int start  = 0;
    char *ret  = NULL;
    unsigned char *dp = NULL;

    if (s == NULL)
        return ret;

    len = strlen(s);
    dp = (unsigned char *)calloc(len, sizeof(unsigned char));

    for (i = len - 1; i >= 0; i--)
    {
        for (j = len - 1; j >= i; j--)
        {
            dp[j] = ((j - i < 2 ? 1: dp[j-1]) && s[i] == s[j]) ? 1: 0;
            
            if (dp[j] && (maxLen < (j - i + 1)))
            {
                maxLen = j - i + 1;
                start = i;
            }
        }
    }
    free(dp);
    ret = (char *)malloc(sizeof(char) * (maxLen+1));
    memcpy(ret, s + start, maxLen);
    ret[maxLen] = 0;

    return ret;
}

int main()
{
    char s[100] = {0};
    char *ret = NULL;

    gets(s);
    printf("Get string : %s\n", s);

    ret = longestPalindrome(s);

    printf("The ret is %s\n", ret);
    free(ret);
    return 0;
}

