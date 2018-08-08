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
