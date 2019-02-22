// 2^31 - 1 =  2147483647   count = 10;
// -2^31    = -2147483648
#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)

class Solution {
public:
    int myAtoi(string str) {
        int sign          = 0; // 0: plus, 1: minus
        int index         = 0;
        int count         = 0;
        long long int ret = 0;

        // find first non-witespace character
        for (;str[index] == ' '; index++);
        
        if (!((str[index] <= '9' && str[index] >= '0') ||
             (str[index] == '+') || (str[index] == '-')))
            return 0; // no valid
        
       
        if (str[index] == '-' || str[index] == '+') 
            sign = (str[index++] == '-'? 1: 0);
        
        // find first non-zero character
        for (;str[index] == '0'; index++);

        while ((str[index] <= '9' && str[index] >= '0') && count <= 10)
        {
            ret = ret * 10 + (str[index++] - '0');
            count++;
        }
        
        return (sign? 
               (-ret < INT_MIN? INT_MIN: (int)-ret): 
               (ret  > INT_MAX? INT_MAX: (int)ret));
        
    }
};
