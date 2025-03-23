class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        
        string res = "";
        int flag = false;

        if(num<0)
        {
            num = -num;
            flag = true;
        }

        while(num>0)
        {
            int rem = num%7;
            res = to_string(rem) + res;
            num /= 7;
        }

        if(flag)
            res = '-' + res;

        return res;
    }
};
