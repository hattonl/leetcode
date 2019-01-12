
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 1, count = 1;
        if (nums.size() == 0) return 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i-1])
            {
                nums[ret++] = nums[i];
                count = 1;
            }
            else if (count < 2)
            {
                nums[ret++] = nums[i];
                count++;
            }
        }
        return ret;
    }
};

/* other */
/* mark */
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
        return i;
    }
};

/* mark */
class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
    }
};
