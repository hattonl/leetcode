There are *N* children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

**Example 1:**

```
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
```

**Example 2:**

```
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
```

Note：如果一个孩子的评分比相邻某孩子高的话就需要保证这个孩子拥有的糖果也要比相邻的孩子高。但是如果一个孩子的评分与相邻某孩子相同的话，就不需要这个孩子的糖果和相邻的那个孩子的糖果相同。（虽然有点违反现实中的一般做法）。

