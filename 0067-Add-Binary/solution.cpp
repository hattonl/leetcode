class Solution {
public:
    string addBinary(string a, string b) {
   
        int slong = a.length();
        int sshort = b.length();
        const char *clong = a.c_str();
        const char *cshort = b.c_str();
        int lc = 0;
        int carry = 0;
        int i;
        
        if (slong < sshort)
        {
            slong  = b.length();
            sshort = a.length();
            clong = b.c_str();
            cshort = a.c_str();      
        }
        
        lc = slong +1;
        string ret(lc, '0');
        
        for (i = 1; i <= sshort; i++)
        {
            int count = 0;
            count = (clong[slong-i] - '0') + (cshort[sshort-i] - '0') + carry;
            carry = count>1? 1: 0;
            count = count & 0x01;
            
            ret[lc-i] = (char)('0' + count);
        }
        
        for (;i <= slong; i++)
        {
            int count = 0;
            count = (clong[slong-i] - '0') + carry;
            carry = count>1? 1: 0;
            count = count & 0x01;
            ret[lc-i] = (char)('0' + count);
        }
    
    /*
        if (carry)
        {
            ret[0] = '1';
            return ret.substr(0);
        }
        else
        {
            return ret.substr(1);
        }
    */
        ret[0] = '0' + carry;
        return ret.substr(carry^0x01);
        
    }
};
