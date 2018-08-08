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
