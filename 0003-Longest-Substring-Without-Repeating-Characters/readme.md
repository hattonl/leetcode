这道题要求从给定的字符串中找出一个没有重复字符的最长子串，并返回这个子串的长度。

最简单暴力的方法做这个题就是依次遍历出所有的子串，每个子串判断是否符合没有重复字符的要求。统计出符合要求的最大的子串长度，并返回。

笔者觉得大部分巧妙的算法都是通过对简单暴力方法实现细节进行优化而来的。在遍历查找子串的步骤中，最简单暴力的方法就是设定变量i和j用于分别表示子串s[i,j)的左右下标。首先令i = 0, j = i + 1; 得到第一个子串。然后j每向后移动一位，就得到一个以i = 0的新子串（j <= strlen(s)的前提下）。则s[0,j)(0< j <= strlen(s))表示所有以s[0]为起始字节的子串。同理，字符串s的所有子串可以表示为s[i,j) (i < j <= strlen(s)).

在本题目中，当子串s[i,j)中出现重复字节时，s[i,k)(j <= k <= strlen(s))中一定出现重复字节，不符合要求。这时就应该开始判断以s[i+1]为起始字节的子串是否符合要求。

判断是否含有重复子串可以使用数组标记的方式。将当前子串中所有字符对应的位置标记为1。若s[i,j)中没有重复字符时，判断s[j]在数组中对对应的位置是否标记为1。若标记为1则s[i,j+1)含有重复字符。

解题代码见：solution.c

```
// O(2n) solition
int lengthOfLongestSubstring(char* s) {
    int longestSubStr = 0;
    int currentSubStr = 0;
    int i = 0, j = 0;
    int slen = 0;
    int mapTable[128] = {0};

    if (s == NULL)
        return 0;

    slen = strlen(s);

    if (slen == 0 || slen == 1)
        return slen;

    for (i = 0,j = i + 1, mapTable[s[i]] = 1; s[j] != '\0'; j++)
    {
        if (mapTable[s[j]] == 1)
        {
            currentSubStr = j - i;
            if (currentSubStr > longestSubStr)
                longestSubStr = currentSubStr;
            
            while(s[i] != s[j])
            {
                mapTable[s[i]] = 0;
                i++;
            }
            mapTable[s[i]] = 0;
            i++;
        }
        mapTable[s[j]] = 1;
    }

    currentSubStr = j - i;
    if (currentSubStr > longestSubStr)
        longestSubStr = currentSubStr;

    return longestSubStr;
}
```


将数组标记换为记录字符在字符串中最后一次出现的下标时，上述方案还可以再优化。时间复杂度从o(2n)将为o(n)。

解题代码见：solution-2.c

```
// O(n) solition
int lengthOfLongestSubstring(char* s) {
    int longestSubStr = 0;
    int currentSubStr = 0;
    int i = 0, j = 0;
    int slen = 0;
    int mapTable[128] = {0};

    if (s == NULL)
        return 0;

    slen = strlen(s);

    if (slen == 0 || slen == 1)
        return slen;

    memset(mapTable, -1, sizeof(int) * 128);

    for (i = 0,j = i + 1, mapTable[s[i]] = 0; s[j] != '\0'; j++)
    {
        if (mapTable[s[j]] >=  i)
        {
            currentSubStr = j - i;
            if (currentSubStr > longestSubStr)
                longestSubStr = currentSubStr;

            i = mapTable[s[j]] + 1;
        }
        mapTable[s[j]] = j;
    }

    currentSubStr = j - i;
    if (currentSubStr > longestSubStr)
        longestSubStr = currentSubStr;

    return longestSubStr;
}
```
