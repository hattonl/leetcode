### 题目

There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume **nums1** and **nums2** cannot be both empty.

**Example 1:**

```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

**Example 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

### 思路

##### 情况1

A[0]  A[1]  A[2]  A[3] ... A[n-2]  A[n-1]

​                                                                    B[0]  B[1]  B[2]  B[3] ... B[m-2]  B[m-1]

##### 情况2

A[0]  A[1]  A[2]  A[3] ... A[n-2]  A[n-1]

​                                          B[0]     B[1]      B[2]  B[3] ... B[m-2]  B[m-1]

##### 情况3

A[0]  A[1]  A[2]  A[3] ... A[n-2]  A[n-1]

​          B[0]  B[1]  ...  B[m-1]



A[0]  A[1]  A[2]  A[i]     A[i + 1] ... A[n-2]  A[n-1]

​          B[0]  B[1]  B[j]    B[j+1] ...  B[m-1]

偶数情况下：

等式i + j = n - 1 -i + m - 1 - j = n + m - i - j - 2

整理得： 2 * (i + j) = m + n -2

j = (m + n - 2) / 2 - i   (为了在奇偶情况下都可以使用同一个公式得到相同的结果这步骤改成 j = (m + n - 1)/2 - i )

> 奇数情况：i + j = n - 1 - i + m - 1 - j + 1 = n + m -i -j -1. (左边比右边多一个)
>
> 2 * (i + j) = m + n - 1
>
> J = (m + n - 1) / 2 - i
>
> 偶数依然要满足。B[j] <= A[i + 1]，A[i] <= B[j+1]
>
> 中位数 = max(A[i], B[j])
>
> 







B[j] <= A[i + 1]

A[i] <= B[j+1]

中位数 = ( max(A[i], B[j]) + min(A[i + 1], B[j + 1]) ) / 2

 下一步的指向：
先确定了一个 i

计算出 j    j = (m + n -2) / 2 - i

判断 j 的范围是否合理。 ***不合理的情况是否可以统一修正***

***先假设合理***：A[i] > B[j+1] || B[j] > A[i+1]      这两个不可能同时发生只能是或的关系

​                          i 减小                    i 增大

如果满足B[j] <= A[i + 1] ，A[i] <= B[j+1] 即可返回中位数，中位数 = ( max(A[i], B[j]) + min(A[i + 1], B[j + 1]) ) / 2。



如果先确定了一个 i，计算出的 j 不符合，

1. j < 0，(m + n -2) / 2 - i  < 0，  此种情况不可取。如果有此情况，可以直接求出中位数。

   i > (m + n) / 2 - 1， 此种情况亦不可取，如果有此情况，也可以直接求出中位数。

   说明 i 有一个取值范围。

如果 m 和 n 一个是奇数，一个是偶数。

那么中位数只有一个。



i 的取值范围 [0, n-2] 临界情况 i == n-1

j 取值范围 [0, m-2] 临界情况 j == m-1



