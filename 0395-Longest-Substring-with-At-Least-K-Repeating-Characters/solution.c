#include <stdio.h>
#include <string.h>

/* solution 1 */

#define MAX(x,y) (x > y ? x: y)

int longestSubstring(char* s, int k) {
    
    int i = 0, j = 0;
    int len = 0;

    int nowLen = 0;
    int maxLen = 0;
    int lastPost = 0;

    if (s == NULL || (len=strlen(s)) < k )
    {
        return 0;
    }

    for (i = 0; i+k <= len;)
    {
        int count[26] = {0};
        int mask = 0;
        int ch = 0;

        lastPost = i;
        ch = s[i] - 'a';
        count[ch]++;
        if (count[ch] < k)
            mask |= (0x0001 << ch);
        else
            mask &= ~(0x0001 << ch);

        if (mask == 0)
        {
            nowLen = 1;
            maxLen = MAX(maxLen, nowLen);
        }

        for (j = i+1; j < len; j++)
        {
            ch = s[j] - 'a';
            count[ch]++;

            if (count[ch] < k)
                mask |= (0x0001 << ch);
            else
                mask &= ~(0x0001 << ch);

            if (mask == 0)
            {
                nowLen = j - i + 1;
                maxLen = MAX(maxLen, nowLen);
                lastPost = j;
            }
        }
        i = lastPost + 1;
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
