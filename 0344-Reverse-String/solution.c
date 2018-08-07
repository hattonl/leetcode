char* reverseString(char* s) {
    int i, len;
    char ch;

    if (s == NULL)
        return s;

    for (i = 0, len = strlen(s); i < (len/2); i++)
    {
        ch = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = ch;
    }

    return s;
}
