[Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

You are climbing a stair case. It takes *n* steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Note:** Given *n* will be a positive integer.

**Example 1:**

```
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```



使用动态规划的方法，在solution中也有被称为*Fibonacci*。将输入的*n*看作是要爬到的台阶编号。只考虑当要爬上第*i*级台阶时，其前一步有两种情况。第一种情况是在*i-1*级台阶一次一个step上到第*i*个台阶，第二种情况是在*i-2*级台阶一次两个step上到第*i*级台阶。所以*climbStairs(i) = climbStairs(i-1) + climbStairs(i-2)*，初始条件*climbStairs(1) = 1, climbStairs(2) = 2;*。使用递归的方法比较消耗内存资源，所以使用自下而上求解的方法。如果设置数组*dp[n]*来存储*climbStairs(i)*的结果，一遍遍历过后就可以得出*climbStairs(n)*的值。进一步，发现设置数组*dp[n]*有点浪费空间，可以只设置两个变量*first*和*second*来表示*climbStairs(i-1)*和*climbStairs(n-2)*，并在每次循环中更新。



这道题的*solution*中有两个比较牛逼的算法，暂时还没有理解，*mark*一下。[Solution](https://leetcode.com/problems/climbing-stairs/solution/)

