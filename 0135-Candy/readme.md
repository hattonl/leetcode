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

第一种解决方法采用两次遍历的方式。首先声明一个与`ratings`大小相同的数组`candies`并全部初始化为1。`candies[i]`表示为第`i`位同学分配的糖果。第一次遍历从左向右，修正数组`candies`使得如果一个孩子的评分比左边孩子高的话保证其拥有的糖果数量也会高于左边的同学。然后在第一遍遍历的基础上进行第二遍遍历，从右向左遍历，以保证如果一个孩子的评分比右边孩子高的话其拥有的糖果数量也会高于右边的同学。

第一种解决方法的时间复杂度为O(*n*)，其空间复杂度也是O(*n*)。第二种解决方法结合了极值的思想，使得一遍遍历完成，时间复杂度为O(*n*)，其空间复杂度也是O(*1*)。不过尚未完全理解透。

