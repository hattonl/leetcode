[Next Permutation](https://leetcode.com/problems/next-permutation/)

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be **in-place** and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

`1,2,3` → `1,3,2`
`3,2,1` → `1,2,3`
`1,1,5` → `1,5,1`

该题目需要求一个数组按照字典顺序排序的下一个全排列。首先需要明确一下对于给定的一个数组，其字典顺序的全排列是如何组织安排的。例如`1,2,3`，其按照字典顺序的全排列如下。也就是说这些数组按照字符串组合在一起是一种升序排序。这样就要求在给定一个数组进行排序的时，第一个一定时按照数组从左到右进行升序排序。然后使前面尽量长的子数组保持从小到大的次序不变，将其后的子数组再依此从小到大排序。

```
1,2,3
1,3,2
2,1,3
2,3,1
3,1,2
3,2,1
```

基于上述思想以及[参考博客](https://www.cnblogs.com/eudiwffe/p/6260699.html)，对于给定数组`nums`，求其`Next Permutation`可以有如下的算法思路。

1. 在数组nums上从后向前查找一个元素nums[i]，使其满足nums[i]<nums[i+1]。如果没有满足要求的i，则表示数组nums为所有全排列中最后一个排列，逆置nums返回即可。
2. 在nums[J]，j属于[i+1，nums.size())中寻找一个满足nums[k] > nums[i]的最小的k。
3. 交换nums[i]和nums[k]。
4. 逆置nums[i+1,nums.size())。

例如，`6,8,7,4,3,2`

```
1. 首先找到i = 0
2. 找到k = 2
3. 交换后得到 7，8，6，4，3，2
4. 逆置nums[1, 6)，得到 7，2，3，4，6，8
```
