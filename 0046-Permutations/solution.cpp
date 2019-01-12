class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = 0;
        int i = 0;
        
        for (i = nums.size() - 2; i >= 0; --i)
            if (nums[i] < nums[i+1]) break;
        
        
        if (i < 0)
        {
            // reverse nums and return
            reverse(nums.begin(), nums.end());
            return;
        }

        k = findMinBigElement(nums, i);
        
        swap(nums[i], nums[k]);
        
        reverse(nums.begin() + i + 1, nums.end());
        return;
        
    }
    
private:
    int findMinBigElement(vector<int>& nums, int index)
    {
        int i = nums.size() - 1;
        for (; i > index; --i)
            if (nums[i] > nums[index]) break;
        
        return i;
    }
    
};
