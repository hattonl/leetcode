#include <stdio.h>
/* solution 3 */

int findComplement(long num) {
    long i;

    printf("num = 0x%lX\n", num);
    for(i=1;i<=num;i*=2)
    {
        num^=i;
        printf("i   = 0x%lX\n", i);
        printf("num = 0x%lX\n", num);
    }

    return num;
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
