// 不使用多余的空间：利用原数据结构的空间进行存储：在一遍遍历过程中，遍历过后的部分可以用作结果返回的存储空间

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i = 0 || nums[i] != nums[i-1]) {
                nums[pos++] = nums[i];
            }
        }
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0; // 记录重复的个数
        for(int i = 1; i < n; i++) {
            if(A[i] == A[i-1]) count++; // 有重复则记录重复次数
            else A[i-count] = A[i]; // 不是重复则应该记录下来
        }
        return n-count;
    }
};

class Solution3 {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1])
                nums[count++] = nums[i];
        }
    }
};

class Solution4 {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        if (nums.size() == 0)
            return 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1])
                nums[count++] = nums[i];
        }
        return count;
    }
};
