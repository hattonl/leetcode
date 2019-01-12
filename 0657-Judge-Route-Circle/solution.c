/* solution */
bool judgeCircle(char* moves) {
    int x = 0, y =0;
    int len = 0;

    if (moves == NULL || (len=strlen(moves)) == 0)
        return true;
    
    for (int i = 0; i < len; i++)
    {
        switch (moves[i])
        {
            case 'R': x++; break;
            case 'L': x--; break;
            case 'U': y++; break;
            case 'D': y--; break;
            default: break;
        }
    }

    return ((x==0 && y==0)? true: false);
}
