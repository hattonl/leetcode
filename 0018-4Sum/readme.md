[4Sum](https://leetcode.com/problems/4sum/)

Given an array `nums` of *n* integers and an integer `target`, are there elements *a*, *b*, *c*, and *d* in `nums` such that *a* + *b* + *c* + *d* = `target`? Find all unique quadruplets in the array which gives the sum of `target`.

**Note:**

The solution set must not contain duplicate quadruplets.

**Example:**

```
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

此题解法与15题3Sum与16题3Sum Closest解题思路相同。对输入数组进行排序后，四个元素再依次进行确定。当确定其中一个元素时，则将问题转换为一种3Sum问题；3Sum问题中确定一个元素后又可以转换为2Sum问题。最终时间负责度为O(n^3)。

Note：过多地调用vector可能会引起内存零头问题，导致内存空间分配失败。调用子函数时可以使用传统一点的数组的形式来进行。