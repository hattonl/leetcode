[Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)

The set `[1,2,3,...,*n*]` contains a total of *n*! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for *n* = 3:

1. `"123"`
2. `"132"`
3. `"213"`
4. `"231"`
5. `"312"`
6. `"321"`

Given *n* and *k*, return the *k*th permutation sequence.

**Note:**

- Given *n* will be between 1 and 9 inclusive.
- Given *k* will be between 1 and *n*! inclusive.

**Example 1:**

```
Input: n = 3, k = 3
Output: "213"
```

**Example 2:**

```
Input: n = 4, k = 9
Output: "2314"
```

这道题的重点在于找到全排列组织规律。这个[Discuss](https://leetcode.com/problems/permutation-sequence/discuss/22507/%22Explain-like-I'm-five%22-Java-Solution-in-O(n))中所给出的思路理解起来很容易。

例如，n = 4时，有第一个排列为`{1,2,3,4}`，则可以将所有的排列根据第一个字数的不同来分为四组，并且这四组是按照如下所示的循序有序排列的。每组中的序列数为(3!)个。由此，可以确定结果中的第一个数字，并将问题转化为n = 3时的相关问题。继续使用相同的方法即可得到所求的答案。

```CPP
1 + (permutations of 2, 3, 4)

2 + (permutations of 1, 3, 4)

3 + (permutations of 1, 2, 4)

4 + (permutations of 1, 2, 3)
```
