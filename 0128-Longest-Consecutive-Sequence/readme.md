[Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(*n*) complexity.

**Example:**

```
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

首先看到题目要求时间复杂度为O(n)，那肯定是可以在一个确定数量的遍历内完成任务的。这里可以想到使用哈希算法来解决。性能良好的哈希算法在元素查找时可以认为其时间复杂度时O(*1*)，并且C++中提供了基于哈希函数的关联容器的操作`unordered_set`和`unordered_map`。另外，此题记录的[解法2](https://leetcode.com/problems/longest-consecutive-sequence/discuss/41088/Possibly-shortest-cpp-solution-only-6-lines.)比较巧妙，值得回顾学习。