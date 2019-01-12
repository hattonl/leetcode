### 题目

Given a List of words, return the words that can be typed using letters of **alphabet** on only one row's of American keyboard like the image below.

 

![American keyboard](https://leetcode.com/static/images/problemset/keyboard.png)

 

**Example 1:**

```
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
```

**Note:**

1. You may use one character in the keyboard more than once.
2. You may assume the input string will only contain letters of alphabet.

### 思路

将输入的每一个字符串进行所有字符是否出现在同一行的判断，并记录下每一个符合要求的字符串的位置。最后申请一个二维数组的内存空间，拷贝符合要求的字符串到该空间并返回即可。