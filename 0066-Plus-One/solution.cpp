class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int index = 0;
        int carry = 1;
        vector<int> ret;
        
        while (index < len && digits[index] == 9) index++;
                
        if (index == len)
        {
            ret.resize(len+1, 0);
            ret[0] = 1;
            return ret;
        }
        else
            ret.resize(len, 0);
        
        for (index = len -1; index >= 0; --index)
        {
            int temp = digits[index] + carry;
            if (temp >= 10)
            {
                temp -= 10;
                carry = 1;
            }
            else
                carry = 0;
            
            ret[index] = temp;            
        }
        
        return ret;
    }
};


class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for (int i = digits.size()-1; i >= 0; --i)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        vector<int> ret(digits.size() + 1, 0);
        ret[0] = 1;
        return ret;
    }
};