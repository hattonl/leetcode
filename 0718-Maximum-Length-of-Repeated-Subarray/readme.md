### 718. Maximum Length of Repeated Subarray

[LeetCode718](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)

Given two integer arrays `A` and `B`, return the maximum length of an subarray that appears in both arrays.

 **Example 1:**

```c
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
```

**Note:**

1. 1 <= len(A), len(B) <= 1000
2. 0 <= A[i], B[i] < 100

leetcode 官方给出了四种解决方案



### 1 暴力解法

#### 未改进前的暴力解法：

it‘s easy to understand

```
ans = 0
for i in [0 .. A.length - 1]:
    for j in [0 .. B.length - 1]:
        k = 0
        while (A[i+k] == B[j+k]): k += 1 #and i+k < A.length etc.
        ans = max(ans, k)
```

#### 改进之后的暴力算法，使用了HashMap

We could instead keep a hashmap `Bstarts[A[i]] = all j such that B[j] == A[i]`, and only loop through those in our `j` loop.

Java solution



HashMap : Bstarts   

**can‘t understand**

```java
class Solution {
    public int findLength(int[] A, int[] B) {
        int ans = 0;
        Map<Integer, ArrayList<Integer>> Bstarts = new HashMap();
        for (int j = 0; j < B.length; j++) {
            Bstarts.computeIfAbsent(B[j], x -> new ArrayList()).add(j);
        }

        for (int i = 0; i < A.length; i++) if (Bstarts.containsKey(A[i])) {
            for (int j: Bstarts.get(A[i])) {
                int k = 0;
                while (i+k < A.length && j+k < B.length && A[i+k] == B[j+k]) {
                    k++
                }
                ans = Math.max(ans, k);
            }
        }
        return ans;
    }
}

```



python solution

```python
class Solution(object):
    def findLength(self, A, B):
        ans = 0
        Bstarts = collections.defaultdict(list)
        for j, y in enumerate(B):
            Bstarts[y].append(j)

        for i, x in enumerate(A):
            for j in Bstarts[x]:
                k = 0
                while i+k < len(A) and j+k < len(B) and A[i+k] == B[j+k]:
                    k += 1
                ans = max(ans, k)
        return ans
```

### 2 二分搜索

**算法核心**：

如果数组A，B 有一个长度为k的公共子数组，那么肯定有一个长度为k-1 的公共子数组。

这样我们直接假设所要求的的最长公共子数组长度为s，使用P[n] 表示数组A和数组B之间是否存在长度为n的公共子数组，若P[n] == 0，表示不存在，否则表示存在。则有当 n <= s 时，p[n] != 0，n > s 时，p[n] == 0。这样我们可以直接使用二分法查找 s 的位置即可。每次查找消耗的时间复杂度为O(xxxx)，而总的查找次数为O()。因此，总体时间复杂度为O(xxx)。



### 3 动态规划

**算法核心**：

设置一个二维数组DP





### 4 Hash表法的二分搜索





查找两个字符串中最大相同子串的算法

两个字符串，长度为m的S以及长度为n的T

寻找一个最长的子串



 求两个字符串的最长公共子串

最长公共子序列和最长公共子串区别

从优化到再优化，最长公共子串

寻找最长重复序列(3) 后缀树

利用后缀树求多个字符串的最长公共连续子串(Longest Common Substring)

相似题目：718. Maximum Length of Repeated Subarray

寻找最长子串/子序列又属于另一个研究的范畴，这种解法先放一放。后面与718一起AC。



后缀树的方法

https://blog.csdn.net/v_JULY_v/article/details/6897097

从Trie树（字典树）谈到后缀树（10.28修订）

KMP算法

后缀树



后缀书-处理字符串的有力工具

Longest common substring problem



​	

[查找两个字符串中最大相同子串的算法](https://en.wikipedia.org/wiki/Longest_common_substring_problem)

两个字符串，长度为m的S以及长度为n的T

寻找一个最长的子串



[ 求两个字符串的最长公共子串](https://blog.csdn.net/u010397369/article/details/38979077)

[最长公共子序列和最长公共子串区别](https://www.kancloud.cn/digest/pieces-algorithm/163624)

[从优化到再优化，最长公共子串](http://blog.iderzheng.com/longest-common-substring-problem-optimization/)

[寻找最长重复序列(3) 后缀树](https://blog.csdn.net/louistech/article/details/8890694)

[利用后缀树求多个字符串的最长公共连续子串(Longest Common Substring)](https://blog.csdn.net/ljsspace/article/details/6575390)

相似题目：[718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)

寻找最长子串/子序列又属于另一个研究的范畴，这种解法先放一放。后面与718一起AC。



后缀树的方法

https://blog.csdn.net/v_JULY_v/article/details/6897097

[从Trie树（字典树）谈到后缀树（10.28修订）](https://blog.csdn.net/v_JULY_v/article/details/6897097)

KMP算法

[后缀树](https://www.cnblogs.com/gaochundong/p/suffix_tree.html)



[后缀书-处理字符串的有力工具](https://wenku.baidu.com/view/228caa45b307e87101f696a8)

[Longest common substring problem](https://en.wikipedia.org/wiki/Longest_common_substring_problem)




https://wenku.baidu.com/view/228caa45b307e87101f696a8



此题还有后缀树解法有待整理

