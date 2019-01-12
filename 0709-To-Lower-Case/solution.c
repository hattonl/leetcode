char* toLowerCase(char* str) {
    int len = 0;

    if (str == NULL)
        return NULL;
    
    len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] += ('a' - 'A');
        }
    }
    return str;
}
