[Trapping Rain Water ](https://leetcode.com/problems/trapping-rain-water/)

Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

![img](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. **Thanks Marcos** for contributing this image!

**Example:**

```
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
```



观察注水完毕后的图像，可知规律：整幅图的Y坐标呈现先单调非递减达到最大值后即最高的那个bar，呈现单调非递减。根据这个规律可以设计如下的算法进行求解：

1. 首先找到最大的bar的下标。
2. 从最左向右开始遍历直到最大的bar的下标处。如果不符合单调非递增，则将其注水以使其符合条件。
3. 从最右向左开始遍历直到最大的bar的下标处。同样，如果不符合单调非递增，则将其注水以使其符合条件。
4. 将所有注水的值相加即可求出答案。

这里要注意，最大的bar不一定只有一个。如果有多个的话，从左向右遍历直到最左出现的最大的bar[1]，同理从右向左遍历直到最右出现的最大的bar[2]。bar[1]和bar[2]中间则逐个求出其与最大值的差值并加入到最终的返回结果即可。

这个解法的性能还行，虽然solution中还有一些比较特殊的方法，不过在这里就不再进行分析了。

