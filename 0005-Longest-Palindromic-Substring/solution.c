// Expand Around Center

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expandAroundCenter(char *s, int strlen, int left, int right)
{
    while ((left >=0 && right < strlen) && (s[left] == s[right]))
    {
       left--;
       right++;
    }

    return (right - left - 1);
}

char* longestPalindrome(char* s) {
    
    int len    = 0;
    int index  = 0;
    int subLen = 0;
    int start  = 0, end = 0;
    char *ret  = NULL;

    if (s == NULL)
        return ret;
    
    len = strlen(s);
    
    for (index = 0; index < len; index++)
    {
        int subLen1 = 0;
        int subLen2 = 0;

        subLen1 = expandAroundCenter(s, len, index - 1, index + 1);
        subLen2 = expandAroundCenter(s, len, index, index + 1);

        subLen1 = (subLen1 > subLen2 ? subLen1: subLen2);
        if (subLen1 > subLen)
        {
            subLen = subLen1;
            start = index - (subLen - 1)/2;
            end = index + subLen/2;
        }
    }

    ret = malloc(sizeof(char) * (subLen + 1));
    memcpy(ret, s + start, subLen);
    ret[subLen] = 0;

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

    return 0;
}