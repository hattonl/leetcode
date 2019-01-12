void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}

int firstMissingPositive(int* nums, int numsSize) {
    int ret = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        while (nums[i] > 0         \ 
            && nums[i] <= numsSize \
            && nums[i] != i+1      \
            && nums[nums[i]-1] != nums[i] )
        {
            swap(&nums[i], &nums[nums[i]-1]);
        }
    }

    for (ret = 0; ret < numsSize; ret ++)
    {
        if (nums[ret] != ret+1)
            break;
    }

    return ret + 1;
}