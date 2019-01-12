char* convert(char* s, int numRows) {
    
    int len = 0;
    int orientation = 0;
    
    char **N = (char **)malloc(numRows * sizeof(char *));

    if (numRows <= 1)
        return s;
    
    len = strlen(s);
    for (int i = 0; i < numRows; i++)
        N[i] = (char *)calloc(len+1, sizeof(char));
    
    for (int i = 0, j = 0; i < len; i++)
    {
        if (!orientation)
            N
    }
}
