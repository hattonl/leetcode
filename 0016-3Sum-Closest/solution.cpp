class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        if (nums.size() <= 3)
        {
            for (int i = 0; i < nums.size(); ++i) ret += nums[i];
            return ret;
        }
        ret = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; ++i)
        {
            int newTarget = target - nums[i];
            int hi        = nums.size() - 1;
            int lo        = i + 1;

            while (lo < hi)
            {
                int hiAndLo = nums[hi] + nums[lo];
                if (hiAndLo == newTarget)
                {
                    ret = target;
                    return ret;
                }
                else if (hiAndLo < newTarget) lo++;
                else hi--;

                if (abs(ret - target) > abs(newTarget-hiAndLo))
                    ret = nums[i] + hiAndLo;
            }
        }
        return ret;
    }
};
