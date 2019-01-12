[Rotate Image](https://leetcode.com/problems/rotate-image/)

You are given an *n* x *n* 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

**Note:**

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:**

```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

**Example 2:**

```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```

题目要求直接在输入数据上进行修改，不能直接申请一个n*n的数组进行修改。这样的话就要找一找每个数据替换的规律，按照一定顺序进行逐个替换即可。

另外顺时针旋转一张图像相当于先将图像上下翻转，再将图像按对角线翻转如[solution](https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image).

