[3Sum Closest](https://leetcode.com/problems/3sum-closest/)

Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example:**

```
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

这道题的解法思路与第15题基本相同。对于排序后的数组采用从左向右递归的方式首先来锁定第一个元素，然后**对其后的子序列进行左右夹逼的方式进行递归**，符合要求的目标。

