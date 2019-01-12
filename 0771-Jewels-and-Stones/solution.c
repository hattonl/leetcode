int numJewelsInStones(char* J, char* S) {
    unsigned char table[128] = {0};
    int ret = 0;
    int j_len = 0;
    int s_len = 0;

    if (J == NULL || S == NULL) return 0;
    
    j_len = strlen(J);
    s_len = strlen(S);
    for (int i = 0; i < j_len; i++)
    {
        table[J[i]] = 1;
    }

    for (int i = 0; i < s_len; i++)
    {
        ret += table[S[i]];
    }

    return ret;
}
