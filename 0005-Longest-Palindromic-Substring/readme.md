# 5.Longest Palindromic Substring

题目描述：寻找一个字符串中最长的回文子串，并返回该子串。

### 方法1: 暴力法

单从是否可以完成题目所给的要求方面来说，暴力解法可以解决大多数的字符串问题，也是最容易得出的解法（应该有“之一”吗？）。当然，其性能一般也是最差的。在字符串的子串问题中，使用暴力解法，我们通常会从字符串的左端开始，依次查找出所有的子串同时判断子串是否满足特定的题目要求。如在本题目中，使用暴力解法，我们将遍历给定的字符串的所有子串，并判断是否为回文，同时统计出子串中属于回文的最大长度。遍历所有子串的时间复杂度为O(n^2)，判断是否回文的时间复杂度为O(n)，所以总的时间复杂度为O(n^3)。由于代码过于简单就此略过了。

### 方法2: 从回文中心向外扩展的算法

暴力解法虽然最为普通，性能也最差。但是笔者却认为它是其他高性能解法的基础。换句话说，很多高效的解法都是从最简单的暴力解法中针对特殊问题进行优化而得到的。如在本题目中，我们需要判定的对象是回文子串，回文子串都是一种“中心对称”的存在。所以，在本题中，我们可以对每个回文子串的回文中心可能存在的位置进行遍历以锁定每一个回文子串。如果说暴力解法中可以理解为“查找所有子串”和“判断该子串是否为回文”两部分，那么我们这一步将会把“查找所有子串”这个O(n^2)的步骤降低为“查找回文中心”这个O(n)的步骤。而经由回文中心向外扩散，判断该位置为回文中心的所有回文的最大长度的算法为O(n)。因此总的时间复杂度为O(n^2)。

这里要注意，由于回文子串长度奇偶两种情况的存在，一个长度为n的字符串的可能存在的回文子串中心有2n-1个。如下图所示。

![LL数组](/Users/hatton.liu/Downloads/LL数组 (1).png)

根据该算法的思想可编写C语言代码如下：

```c
int expandAroundCenter(char *s, int strlen, int left, int right)
{
    while ((left >=0 && right < strlen) && (s[left] == s[right]))
    {
       left--;
       right++;
    }
    return (right - left - 1);
}
char* longestPalindrome(char* s) { 
    int len    = 0;
    int index  = 0;
    int subLen = 0;
    int start  = 0, end = 0;
    char *ret  = NULL;
    if (s == NULL)
        return ret;   
    len = strlen(s);   
    for (index = 0; index < len; index++)
    {
        int subLen1 = 0;
        int subLen2 = 0;
        subLen1 = expandAroundCenter(s, len, index - 1, index + 1);
        subLen2 = expandAroundCenter(s, len, index, index + 1);
        subLen1 = (subLen1 > subLen2 ? subLen1: subLen2);
        if (subLen1 > subLen)
        {
            subLen = subLen1;
            start = index - (subLen - 1)/2;
            end = index + subLen/2;
        }
    }
    ret = malloc(sizeof(char) * (subLen + 1));
    memcpy(ret, s + start, subLen);
    ret[subLen] = 0;
    return ret;
}
```



### 方法3: 动态规划

动态规划的解法，也可以理解为对暴力解法的一种改进。在暴力解法中，我们会判断每一个子串是否为回文，并且普通的方式而言同样没有应用到回文的特性从而导致了不必要的重复计算。而在动态规划的解法中，同方法2一样利用到回文子串的“中心对称”特点。如果s[i, j]是回文，判断s[i-1, j+1]是否是回文时，只需要判断字符s[i-1] 是否等于s[j+1]即可。若相等，则s[i, j]为回文，否则s[i, j]不是回文。另外，当s[i, j]不是回文时，则s[i-1, j+1]一定不是回文。

针对基础情况。当i== j时，s[i, j]一定是长度为1的回文子串。i 取完所有的0 到 n-1所有值时为所有奇数长度的子串提供了一个基础情况。当j = i + 1时，如果有s[i] == s[j]，s[i, j]是一个长度为2的回文子串。i 取完所有0 到n-2所有值时为所有偶数长度的子串提供了一个基础情况。如下图所示。

![屏幕快照 2018-08-24 下午10.47.34](/Users/hatton.liu/Desktop/屏幕快照 2018-08-24 下午10.47.34.png)

了解了算法的思想之后，我们从编程的角度看一下如何进行实现。列出一个表格，横向 j 表示子串的尾字符在给定字符串中的下标，纵向 i 表示子串的首字符在给定子串中的下标，每个表象表示子串S[i, j] 是否是回文子串即P[i, j]。由于 i >= j ，因此表格的左下部分没有用到，只用到了右上部分。并且由上述的公式可知，右上部分中P[i -1,j+1] 与P[i, j]的对应关系是斜对角的形式，如下图中箭头所示。即图片中右上方的真假，依赖于左下方的真假。所以根据依赖关系，选择从下到上开始编程求解问题会更加方便。

![LL数组](/Users/hatton.liu/Downloads/LL数组 (2).png)

编写C语言代码如下：

```c
char* longestPalindrome(char* s) {
    int i = 0, j = 0;
    int len    = 0;
    int maxLen = 0;
    int start  = 0;
    char *ret  = NULL;
    unsigned char *dp = NULL;
    if (s == NULL)
        return ret;

    len = strlen(s);
    dp = (unsigned char *)calloc(len, sizeof(unsigned char));
    for (i = len - 1; i >= 0; i--)
    {
        for (j = len - 1; j >= i; j--)
        {
            dp[j] = ((j - i < 2 ? 1: dp[j-1]) && s[i] == s[j]) ? 1: 0;
            
            if (dp[j] && (maxLen < (j - i + 1)))
            {
                maxLen = j - i + 1;
                start = i;
            }
        }
    }
    free(dp);
    ret = (char *)malloc(sizeof(char) * (maxLen+1));
    memcpy(ret, s + start, maxLen);
    ret[maxLen] = 0;
    return ret;
}
```

这样的话，我们遍历了所有的子串，这个过程的时间复杂度为O(n^2)。而判断每个子串是否为回文的时间复杂度就降低为了O(1)。总体时间复杂度O(n^2)。

### 方法4: Manacher‘s Algorithm

Manacher‘s Algorithm是由一个叫Manacher的人在1975年发明的用于查找字符串中最长回文子串的方法。其最大贡献在于将求解最长回文子串的算法的时间复杂度降低到了O(n)。

我们再来看一下题目，寻找最长回文子串。既然是“最长”，那一遍遍历是不可少的。遍历的时间复杂度怎么说也得O(n)，而Manacher‘s Algorithm的总体时间复杂度就是O(n)。说明该方案在一次线性遍历的同时，就在判断最长回文子串的长度，并且该判断方法与n无关。说到这里，直觉告诉我们，这步一定有时利用了回文子串的特殊的性质。是的，你的直觉没有问题。

在讲解Manacher‘s Algorithm的核心思想时，我们先对算法的基本操作进行一下说明。首先Manacher‘s Algorithm在对给定字符串进行遍历时，采用自左向右的顺序进行遍历，依次寻找以某字符为回文中心时，该回文子串的最大长度。变量i表示当前遍历的位置。

所有的回文子串的回文中心，末尾字符都在原给定子串有对应的下标。这里设置变量mx表示，已经遍历过的所有回文子串中，子串的末尾字符能达到的最大的下标，同时，使用变量id表示这个回文子串的回文中心。

下面让我们看一下当遍历到回文中心 i 时将会发生的操作。

分情况：

1. mx > i: 表示当前遍历到的回文中心，在曾经遍历过的某个回文中。由回文的对称性可知，一定存在一个点j，i和j关于点id对称，并且以j点为中心的回文半径已经求知（由遍历顺序可以知）。这样的话又可以分为两个情况。假设mx关于id的对称点为my。

   - j点的回文半径小于等于(j - my)时。由对称性可知，i点的回文半径与j点相同，必然小于等于(mx - i)。i 点无需再求。

   - j点的回文半径大于(j - my)时。由对称性可知，i点的回文半径必然大于或等于(mx - i)。但不一定与j点的回文半径相同。此时，需要在i 点，以回文半径(mx - i)开始扩展回文半径。同时，更新mx与id的值。

     ![1345942506_7744](/Users/hatton.liu/Downloads/1345942506_7744.png)

2. mx <= i: 这种情况就无法使用到情况1中的性质。因此，需要在i 点，以回文半径(mx - i)开始扩展回文半径。同时，更新mx与id的值。

 总结为一行代码 ` p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;`  p[i]表示以点i 为回文中心的回文半径。Manacher‘s Algorithm 在查找回文半径时，利用到了已有的回文半径的数据，将求解最长回文子串问题的时间复杂度降低到了O(n)。

代码实现如下：

```c
#define MIN(x, y) (x < y? x: y)
char* longestPalindrome(char* s) {
    int   len        = 0;
    int   newLen     = 0;
    int   mx         = 0;
    int   id         = 0;
    int   maxHalfLen = 0;
    int   maxCenter  = 0;
    char *ret        = NULL;
    char *st         = NULL;
    int  *p          = NULL;
    
    if (s == NULL) return NULL;

    // $ # s[0] # s[1] # ... s[n - 1]  #     /0
    // 0 1  2   3  4   5 ...    2n     2n+1  2n+2
    len = strlen(s);
    newLen = len * 2 + 2;
    st = (char *)malloc(sizeof(char) * (newLen + 1));
    memset(st, '#', newLen);
    st[0] = '$';
    for (int i = 0; i < len; i++)
    {
        st[2*(i+1)] = s[i];
    }
    st[newLen] = 0;

    p = (int *)calloc(newLen, sizeof(int));

    for (int i = 1; i < newLen; i++)
    {
        p[i] = mx >= i? MIN(p[2*id - i], mx - i + 1): 1;
        while(st[i+p[i]] == st[i-p[i]]) ++p[i];
        if (mx < i + p[i] - 1)
        {
            mx = i + p[i] - 1;
            id = i;
        }
        if (maxHalfLen < p[i])
        {
            maxHalfLen = p[i];
            maxCenter = i;
        }
    }
    free(st);
    free(p);
    ret = (char *)malloc(sizeof(char) * maxHalfLen);
    memcpy(ret, s + (maxCenter - maxHalfLen)/2, maxHalfLen - 1);
    ret[maxHalfLen-1] = 0;
    return ret;
}
```

### 方法5: 使用查找两个字符串中最长相同子串的方法。

将原字符串反转，寻找反转后的字符串与原字符串之间的最长的相同子串。在这里，要注意也可能出现，反转后的子串与原子串之间的最长相同子串不是回文的情况。因此，每次查找到一个最长子串后选项时，都需要检查一下它们的下标在原子串和反转后的子串中是否满足要求。这样就将寻找最长回文子串的问题转化为了寻找两个字符串最长公共子串的问题。与leetcode718十分相似，关于这个问题，笔者目前了解到两种解法，一种是动态规划，另一种是使用后缀树。这里先挖一个坑，到下期接leetcode718时一并讨论了。



参考文献：

[leetcode官方solution](https://leetcode.com/problems/longest-palindromic-substring/solution/)

[动态规划参考](http://windliang.cc/2018/08/05/leetCode-5-Longest-Palindromic-Substring/)

[动态规划参考2](https://leetcode.com/problems/longest-palindromic-substring/discuss/2921/Share-my-Java-solution-using-dynamic-programming)

[Manacher's Algorithm 马拉车算法](https://www.cnblogs.com/grandyang/p/4475985.html)