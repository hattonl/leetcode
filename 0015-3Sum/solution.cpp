class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;
        
        sort(nums.begin(), nums.end());
                
        for (int i = 0; i < (nums.size()-2); ++i)
        {            
            int target = -nums[i];
            int lo     = i+1;
            int hi     = nums.size()-1;
            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == target)
                {
                    vector<int> triplets = {nums[i], nums[lo], nums[hi]};
                    ret.push_back(triplets);
                    
                    while (lo < hi && nums[lo] == triplets[1]) lo++;
                    while (lo < hi && nums[hi] == triplets[2]) hi--;
                }
                else if (nums[lo] + nums[hi] < target) ++lo;
                else --hi; // nums[lo] + nums[hi] > target
            }
            while (i < nums.size()-2 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
};