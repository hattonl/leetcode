Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.


找到给定字符串中最长的子串，该子串满足，所有字符的出现次数都超过k次。


solution 1

mask 中的每个bit标记该位对应的字符的出现次数是否大于k次。标志位为1表示该字符出现，但没有超过k次；标志为为0则表示该字符没有出现或者出现次数已经超过了k次。

当mask的值为1时，则表示当前子串是符合要求的子串。

此时last一直遍历到字符串的末尾。

之后 first 向前移动 到 max_last + 1; max_last 为上次循环中最后一个满足条件的子串的末坐标。（why？ 为什么下一次循环从 max_last + 1 开始？证明一下？）

证明：

    若s[i,j)是符合要求的并以s[i]字符开头的所有子串中最长子串。
    证明s[k,l) k属于(i,j), l > k. 所表示的所有子串中没有符合要求的，或者符合要求的子串长度都小于等于s[i,j).

    1. s[k,l)符合要求时且l <= j时，由于k > i, 所以字符串s[k,l) 的长度小于s[i,j)的长度。

    2. s[k,l)符合要求时且l > j时:
        由于s[i,j)是符合要求的并以s[i]字符开头的所有子串中最长子串，而此时又有l > j,则有s[i,l)必然不满足条件。则可以得出s[j,l)中必不存在于s[i,j)中的字符且出现的次数小于k。又因为s[k,j)时s[i,j)的子串，所以s[j,l)中必不存在于s[k,j)中的字符且出现的次数小于k。因此可得，s[k,l)必然不符合条件。

    由上述推论可得，
        若s[i,j)是符合要求的并以s[i]字符开头的所有子串中最长子串。
    则s[k,l) k属于(i,j), l > k. 所表示的所有子串中没有符合要求的，或者符合要求的子串长度都小于等于s[i,j).

    所以当以s[i]开头的字符串全部检索完毕时。若s[i,j)是符合要求的并以s[i]字符开头的所有子串中最长子串。则下次循环i的初始条件应为j。



solution 2

第二种解题方法采用分治递归的方法。


在一个字符串中，如果出现某个字符，其重复的次数小于K。则说明所有包含该字符的子串都是不和要求的子串，因此可以将该字符看作是分隔符。若没有此类字符，则可以直接得到要求的结果为该字符串的长度。若该字符串的长度小于k则也可直接返回符合要求的子串的长度为0。若不满足以上两个条件，则在该分隔符的分割下，此字符串又被范围若干子串，依次递归求出每个子串中符合要求的子串的长度即可。




solution 3

第三种解法设计有些巧妙，没有看其他人的解题思路之前根本想不到这种解法。
在这种解法中，使用了滑动窗口的方法。只不过这个滑动窗口不是固定长度的，而是满足某种特性。在每一次的滑动窗口中规定了，本次滑动窗口中存在的字符串的种类。当滑动窗口中的字符种类等于本次指定种类时，判断该窗口中所有的字符的出现次数是否满足需求，若满足需求更新最大子串的长度。滑动窗口继续后移直到窗口中的字符不满足要求时，开始收缩窗口直到满足要求。至此，包含x种字符的，满足要求的长度最长子串的长度被返回。只要x从1迭代到26，即可得到所有满足要求的子串。

循环中：


1. end向后，直到窗口中的字符种类等于k
    (若整个字符串中的字符种类没有完全小于k，则可以返回一个错误的编号，表明字符种类再增加时不必再遍历)

2. 在窗口的字符种类保持x的情况下，end向后延伸。记录下符合要求的子串长度。
    (考虑：当第一次end延伸到字符串结束，但是没有符合要求的子串时，时候可以停止字符串种类再增加时的遍历。) ：可以作为一个内循环。
3. end窗口向后延伸到使得窗口中的字符种类超过了k，即为k+1时。start向后延伸，直到窗口中的字符种类再次等于k。  可以作为一个外循环。
2. 在窗口的字符种类保持k的情况下，end向后延伸。记录下符合要求的子串长度。
3. end窗口向后延伸到使得窗口中的字符种类超过了k，即为k+1时。start向后延伸，直到窗口中的字符种类再次等于k。

一直重复2.3... 直到end在向后延伸时延伸到了字符串的末尾。

java代码设计非常精巧，抄袭一下，日后再入理解。
去理解这个循环是如何设计的。

优化：
没有进入到 'maxLen = MAX(maxLen, end - start); '去执行的可能性。
1.整个字符串中所有的字符种类小于x。     。。。。 不必在迭代
2.整个字符串中所有的字符种类等于x，但不满足出现次数 。。。 不必在迭代
3.整个字符串中所有的字符种类大于x，但是都不满足出现次数。
    小的滑动窗不满足，则大的滑动窗也肯定不满足。证明？

经过改进之后，beats 100%

不过还是要分析第三种解法的设计思路。

滑动窗的设计？框架？
