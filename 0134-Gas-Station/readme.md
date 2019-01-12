[Gas Station](https://leetcode.com/problems/gas-station/)

There are *N* gas stations along a circular route, where the amount of gas at station *i* is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from station *i* to its next station (*i*+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

**Note:**

- If there exists a solution, it is guaranteed to be unique.
- Both input arrays are non-empty and have the same length.
- Each element in the input arrays is a non-negative integer.

**Example 1:**

```
Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

**Example 2:**

```
Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```

在解答本题时参考了两个Discuss，[第一个Discuss](https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.)给出了解答本题的两种基本思想，[第二个Discuss](https://leetcode.com/problems/gas-station/discuss/42572/Proof-of-%22if-total-gas-is-greater-than-total-cost-there-is-a-solution%22.-C%2B%2B)则对第二个基本思想进行了证明。

两个基本的结论：

1. 如果汽车从gas[A]开始启动，第一个无法到达的加油站是gas[B]，则汽车从位于gas[A]和gas[B]之间任意一个加油站gas[C]都无法到达gas[B]。
2. 如果所有加油站的油量总和`gas[ALL]: gas[0]+gas[1]+...+gas[n-1]`不小于所有的汽油消耗`cast[ALL]: cost[0]+cost[1]+...+cost[n-1]`，则必存在起始点start满足题意。

第一个基本结论容易被想到，下面证明一下第二个结论。

前提条件有:

```
gas[0]-cost[0] + gas[1]-cost[1] + ... gas[n-1]+cost[n-1] >= 0
```

假设有i属于[0, n)，使得下列式子为最小值。

```
gas[0]-cost[0] + gas[1]-cost[1] + ... gas[i]+cost[i]
```

则有下列式子成立：

```
假设约定 sum[i] = gas[0]-cost[0] + gas[1]-cost[1] + ... gas[i]+cost[i];

sum[i] <= sum[i] + gas[i+1]-cost[i+1];
sum[i] <= sum[i] + gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2];
sum[i] <= sum[i] + gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1];
```

两边减去sum[i]

```
gas[i+1]-cost[i+1] >= 0;
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] >= 0;
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] >= 0;
```

已知

```
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] + sum[i]>= 0;
```

又因为`sum[i]`是最小值，所以

```
sum[i] < gas[0]-cost[0];
sum[i] < gas[0]-cost[0] + gas[1]-cost[1];
sum[i] < gas[0]-cost[0] + gas[1]-cost[1] + ... + gas[i-1]-cost[i-1];
```

则有

```
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] + gas[0]-cost[0] >= 0;
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] + gas[0]-cost[0] >= 0;
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] + gas[0]-cost[0] + gas[1]-cost[1]>=0;
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] + gas[0]-cost[0] + gas[1]-cost[1] + ... + gas[i-1]-cost[i-1] >= 0;
gas[i+1]-cost[i+1] + gas[i+2]-cost[i+2] +...+ gas[n-1]-cost[n-1] + sum[i]>= 0;
```

所以i+1是满足题意的起始点。

Solution1直接判断了i+1的位置。Solution2则根据结论1来进行求解。

