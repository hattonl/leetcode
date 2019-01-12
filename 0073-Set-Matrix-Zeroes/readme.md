[Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

Given a *m* x *n* matrix, if an element is 0, set its entire row and column to 0. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

**Example 1:**

```
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
```

**Example 2:**

```
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
```

**Follow up:**

- A straight forward solution using O(*m***n*) space is probably a bad idea.
- A simple improvement uses O(*m* + *n*) space, but still not the best solution.
- Could you devise a constant space solution?



使用*matrix*的第一行和第一列来作为该行或者该列是否有元素为*0*。另外就需要来判断*matrix*第一行和第一列是否需要清零的情况，可以使用*matrix\[0][0]*标记第一行是否需要全置为*0*，额外变量colSetZero标记第一列是否需要全置为*0*。

