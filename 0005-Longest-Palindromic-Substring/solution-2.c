// Manacher's Algorithm solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) (x < y? x: y)
char* longestPalindrome(char* s) {

    char *ret = NULL;
    char *st = NULL;
    int *p = NULL;
    int len = 0;
    int newLen = 0;
    int mx = 0;
    int id = 0;
    int maxHalfLen = 0;
    int maxCenter = 0;
    if (s == NULL) return NULL;

    // $ # s[0] # s[1] # ... s[n - 1]  #     /0
    // 0 1  2   3  4   5 ...    2n     2n+1  2n+2
    len = strlen(s);
    newLen = len * 2 + 2;
    st = (char *)malloc(sizeof(char) * (newLen + 1));
    memset(st, '#', newLen);
    st[0] = '$';
    for (int i = 0; i < len; i++)
    {
        st[2*(i+1)] = s[i];
    }
    st[newLen] = 0;

    p = (int *)calloc(newLen, sizeof(int));

    for (int i = 1; i < newLen; i++)
    {
        p[i] = mx >= i? MIN(p[2*id - i], mx - i + 1): 1;
        while(st[i+p[i]] == st[i-p[i]]) ++p[i];

        if (mx < i + p[i] - 1)
        {
            mx = i + p[i] - 1;
            id = i;
        }

        if (maxHalfLen < p[i])
        {
            maxHalfLen = p[i];
            maxCenter = i;
        }
    }
    free(st);
    free(p);
    ret = (char *)malloc(sizeof(char) * maxHalfLen);
    memcpy(ret, s + (maxCenter - maxHalfLen)/2, maxHalfLen - 1);
    ret[maxHalfLen-1] = 0;
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
