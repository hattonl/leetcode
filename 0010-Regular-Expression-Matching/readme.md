[Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'`.

```
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
```

The matching should cover the **entire** input string (not partial).

**Note:**

- `s` could be empty and contains only lowercase letters `a-z`.
- `p` could be empty and contains only lowercase letters `a-z`, and characters like `.` or `*`.

**Example 1:**

```
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

**Example 3:**

```
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

**Example 4:**

```
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
```

**Example 5:**

```
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
```



从前向后进行匹配

先读`string p`，先读取一个字节，若第二个字节为*，则读取两个字节。

再从`string s`中读取相应字节数的字节进行匹配（若`string p`中读取的为一个字节，则读一个字节，否则可能为0字节，或者n个字节。）

可能出现问题，`.*i`，sadfhjkhasd（本不该匹配，但给匹配上了），sadfhjkhasdi

.* + 特定字符

特定字符* + . （1. `.`为是该特定字符时，  2. `.`不是该特定字符时。（）

特定字符* + .另一个特定字符

1. 字符* + 字符

   1. 两个字符相同

      字符* + 字符* 情况

      ​	表示该字符至少应该出现一次，读取处理p时应该一次处理到结束。

   2. 两个字符不同

      ​	正常逻辑处理

2. 字符* + .

    当实际情况中 . 与 字符相同

   ​	p = a*. ...

   ​	s = aaaa ...

   ​	s = aaaa b ...

   ​	**两种情况都符合？** 

   ​		**所以从前向后逐个匹配的算法不是很有效？**

3. .* + 字符

4. .* + .

使用递归方法，可以解决此种**多情况的或者**关系。

匹配情况不唯一



DP方法

string s， string p

s.length() 

p.length()



dp\[i][j]  == true 表示从 s[0, i)  与 p[0, j) 匹配  

​	      == false 表示从 s[0, i)  与 p[0, j) 不匹配

i 属于 [1, s.length()]

j 属于 [1, p.length()]

可能回访问到的地址：i-1 （s）  j-2（p）

越界控制：当访问j-2时 j 



dp\[i][j]的取值

if p[i] 是 .  s[j] 为任意值匹配，增加匹配 dp\[i][j] = dp\[i-1][j-1]

if p[i] != . 且 p[i] != *   若p[i] == s[j]，则增加匹配 dp\[i][j] = dp\[i-1][j-1]



if p[i] 是* 

​	p[i-1]p[i]  即 (a*) 组合，与s[j]进行匹配

​		a* = 空     p[i-1] ！= s[j]    dp[i]dp[j] = dp\[i][j-2]



​		a* = a       p[i-1] == s[j]     dp[i]dp[j] = dp\[i][j-1]

​		a * = aa...  p[i-1] == s[j]  dp[i]dp[j] = dp\[i][j-1]



​		.* = 空   p[i-1] == .   dp[i]dp[j] = dp\[i][j-2]



​		// .* = .    p[i-1] == .  dp[i]dp[j] = dp\[i-1][j-2]

​		. * = .....  p[i-1] == .  dp[i]dp[j] = dp\[i-1][j]



​		p[i-1] == s[j]     dp\[i][j] = dp\[i-1][j-1]

​
测试数据：

string s = "aa";
string p = "a";

失败

dp[2][1]时 判断s[0, 2)  与 p[0, 1) 匹配

因为 S[2] == p[1]
dp[2][1] = dp[1][0];  // dp[1][0] 表示 s[0, 1)  与 p[0, 0) （空串）的匹配 初始应位 false

当j == 0时，表示s[0, i） 与空串的匹配， i != 0时，为false, 当 i == 0 时应为ture

当i == 0时，s[0, 0) 空串， p[0, j)  DP[0][j]  dp[0][0] = true; dp[0][1]  if (p[0] == *) dp[0][1] == 0

if (p[1] == * && dp[0][1] == true) dp[1][2] ==  



dp2 Bottom-Up Variation
​
dp\[i]\[j] 表示s[i:]与p[j:] 可匹配

i取值范围 [0, s.length())    s.length() 可为0

j取值范围 [0，p.lenght()）  l.length() 可为0



```cpp
for (int i = s.length(); i >= 0; ++i) //
{
    for (int j = p.length(); j >= 0; ++j)
    {
        
    }
}
```

非特殊情况时：

dp\[i]\[j]  的取值

当 s[i] == p[j] 或 p[j] == .  时 -> first match

​	此时，若且 dp\[i+1]\[j+1] == true , 则dp\[i]\[j] = true;

​	若 dp\[i+1]\[j+1] ！= true，

判断通配符的存在：

​	p[j+1] 是否是通配符

  1. 若是

     dp\[i]\[j] = dp\[i]\[j+2] || first_match && dp\[i+1]\[j];

  2. 

