class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());
        if (nums.size() < 4) return ret;

        for (int i = 0; i < nums.size()-3; ++i)
        {
            int newTarget = target - nums[i];
            vector<vector<int>> triplets;
            triplets = threeSum(nums.data() + i + 1, nums.size() - i - 1, newTarget);
            for (int j = 0; j < triplets.size(); ++j)
            {
                ret.push_back({nums[i], triplets[j][0], triplets[j][1], triplets[j][2]});
            }
            while (i < nums.size()-3 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
    
private:
    // using vector<int> nums(nums.begin()+i+1, nums.end());
    // vector<vector<int>> threeSum(vector<int> nums, int target) {
    vector<vector<int>> threeSum(int nums[], int size, int target) {
        // no need to sort vector
        vector<vector<int>> ret;
        // no need to check nums size
        for (int i = 0; i < size-2; ++i)
        {
            int newTarget = target - nums[i];
            int hi        = size-1;
            int lo        = i + 1;

            while (lo < hi)
            {
                if (nums[hi] + nums[lo] == newTarget)
                {
                    vector<int> triplets = {nums[i], nums[lo], nums[hi]};
                    ret.push_back(triplets);

                    while (lo < hi && nums[lo] == triplets[1]) lo++;
                    while (lo < hi && nums[hi] == triplets[2]) hi--;
                }
                else if (nums[hi] + nums[lo] < newTarget) lo++;
                else hi--; // nums[hi] + nums[lo] > newTarget
            }
            while (i < size-2 && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }

};
