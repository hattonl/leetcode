#include <stdio.h>
#include <string.h>

/* solution 3 */
#define MAX(x, y) (x > y? x: y)

int findMaxSubLenOfXChar(char *s, int k, int x)
{
    int count[128] = {0}; // for ++
    int start = 0, end = 0;
    int ch = 0;
    int numOfChUnique = 0;
    int numOfChMtRe = 0;
    int len = 0;
    int maxLen = -1;

    len = strlen(s);

    while (end < len)
    {
        if (count[s[end]]++ == 0) numOfChUnique++;
        if (count[s[end++]] == k) numOfChMtRe++;

        while (numOfChUnique > x)
        {
            if (count[s[start]]-- == k) numOfChMtRe--;
            if (count[s[start++]] == 0) numOfChUnique--;
        }

        if (numOfChUnique == x && numOfChMtRe == x)
        {
            maxLen = MAX(maxLen, end - start);
        }
    }

    return maxLen;
}

// let int maxLen == -1;
// 

int longestSubstring(char* s, int k) {
    
    int maxLen = 0;
    int nowLen = 0;

    if (s == NULL || strlen(s) < k)
        return 0;

    for (int i = 1; i <= 26; i ++)
    {
        nowLen = findMaxSubLenOfXChar(s, k, i);
        maxLen = MAX(maxLen, nowLen);
        if (nowLen == -1) break;
    }

    return maxLen;
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
