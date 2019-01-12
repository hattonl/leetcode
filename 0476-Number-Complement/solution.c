#include <stdio.h>

/* solution 1 */
int findComplement(int num) {
    int cplt = num ^ (~(0x0));
    int index = 0;
    unsigned int mask = 0;
    while (num > 0)
    {
        index++;
        num = num >> 1;
    }

    mask = ((~((unsigned int)0x0)) >> (32 - index));

    return (cplt & mask);
}

int main()
{
    int num;
    int cplt;

    scanf("%d", &num);
    printf("Get num: %d\n", num);
    cplt = findComplement(num);
    printf("Complement: %d\n", cplt);

    return 0;
}
