int findOneInBinary(int x)
{
    int ret = 0;

    for (ret = 0; x > 0; x = x>>1)
        if (x & 0x01) ret ++;

    return ret;
}

int hammingDistance(int x, int y) {
    // x = x^y;
    return findOneInBinary(x^y);
}


