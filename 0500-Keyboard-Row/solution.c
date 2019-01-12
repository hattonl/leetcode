#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRowNum(char c);
int inOneLine(char *s);

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    int retSize = 0;
    char **retArray = NULL;
    int *mask = (int *)calloc(wordsSize, sizeof(int));

    for (int i = 0; i < wordsSize; i ++)
    {
        if (inOneLine(words[i]))
        {
            mask[i] = 1;
            retSize++;
        }
    }
    // alloc array ready to return
    retArray = (char**)malloc(sizeof(char*) * retSize);
    
    for (int i = 0, j = 0; i < retSize; i++, j++)
    {
        int size = 0;

        while(mask[j] == 0) j++;
        size = strlen(words[j]);
        retArray[i] = (char *)malloc((size + 1) * sizeof(char));
        strcpy(retArray[i], words[j]);
    }

    free(mask);

    *returnSize = retSize;
    return retArray;
}

int inOneLine(char *s)
{
    int sameFlag = 1;
    int initRow = 0;
    int nowRow = 0;
    int wordLen = strlen(s);
        
    for (int j = 0; j < wordLen; j++)
    {
        char tempWord = s[j];
        if (tempWord <= 'Z' && tempWord >= 'A')
            tempWord += 32;

        nowRow = getRowNum(tempWord);
        
        if (initRow == 0)
        {
            initRow = nowRow;
        } 
        else if (initRow != nowRow)
        {
            // not in the same line
            sameFlag = 0;
            break;
        }
    }
    return sameFlag;
}

int getRowNum(char c)
{
    int row = 0;
    
    switch (c)
    {
    case 'q': case 'w': case 'e': case 'r': case 't':
    case 'y': case 'u': case 'i': case 'o': case 'p':
        row = 1;
        break;

    case 'a': case 's': case 'd': case 'f': case 'g':
    case 'h': case 'j': case 'k': case 'l':
        row = 2;
        break;
    
    case 'z': case 'x': case 'c': case 'v': case 'b':
    case 'n': case 'm':
        row = 3;
        break;
    
    default:
        row = 0;
    }

    return row;
}

int main()
{
    
    return 0;
}