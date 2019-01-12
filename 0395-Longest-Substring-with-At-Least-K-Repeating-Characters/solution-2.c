#include <stdio.h>
#include <string.h>

/* solution 2 */
/* 0ms? beats 100% c submissions */
#define MAX(x, y) (x > y? x: y)

int longestSubstring(char* s, int k) {

    int len = 0;

    int count[26] = {0};
    int mask = 0;
    int i = 0;
    int subLen = 0;
    char ch;
    if (s == NULL || (len = strlen(s)) < k)
        return 0;
    
    for (i = 0; i < len; i++)
    {
        ch = s[i] - 'a';
        count[ch]++;
        if (count[ch] >= k)
            mask &= ~(0x01 << ch);
        else 
            mask |= (0x01 << ch);
    }

    if (mask == 0)
        return len;

    // printf("mask: 0x%x\n", mask);

    for (i = 0; i < len; i++)
    {
        ch = s[i] - 'a';
        if ((mask >> ch) & 0x01)
        {
            s[i] = 0;
        }
    }
    // printf("After handle: %s\n", s);

    for (i = 0; i < len;)
    {
        int nowLen = longestSubstring(s + i, k);
        // printf("nowlen = %d\n", nowLen);
        subLen = MAX(subLen, nowLen);

        i = i + strlen(s + i) + 1;
    }

    return subLen;
}

int main()
{
    char s[100];
    int k = 0;
    int ret = 0;

    scanf("%s", s);
    printf("Get string : %s\n", s);
    scanf("%d", &k);
    printf("Get k : %d\n", k);

    ret = longestSubstring(s, k);

    printf("The ret is %d\n", ret);

    return 0;
}
