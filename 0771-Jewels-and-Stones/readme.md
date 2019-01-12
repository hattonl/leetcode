### 问题

You're given strings `J` representing the types of stones that are jewels, and `S` representing the stones you have.  Each character in `S`is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in `J` are guaranteed distinct, and all characters in `J` and `S` are letters. Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

**Example 1:**

```
Input: J = "aA", S = "aAAbbbb"
Output: 3
```

**Example 2:**

```
Input: J = "z", S = "ZZ"
Output: 0
```

**Note:**

- `S` and `J` will consist of letters and have length at most 50.
- The characters in `J` are distinct.

### 思路

这道题目即求，字符串S中的字符，有多少同时也是字符串J中的字符。由于所有的字符都属于大小写字母，所以可以建立一个26*2的数组（还是声明一个全ASCII码空间的，代码会比较简洁一些），来标记J中存在那些字符。然后遍历一遍字符串S，通过查表就可以得到S中字符在J字符串中存在的个数。
