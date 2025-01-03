class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)
            return 0;
        
        int i=0;

        while(i<s.size() && s[i]==' ')
            i++;
        
        s = s.substr(i);

        int sign = 1;
        long res = 0;

        if(s[0] == '-')
            sign = -1;
        
        int MAX = INT_MAX, MIN = INT_MIN;

        i = (s[0] == '+' || s[0] == '-') ? 1:0;

        while(i<s.length())
        {
            if(s[0] == ' ' || !isdigit(s[i]))
                break;
            
            res = res*10 + s[i]-'0';

            if(sign == -1 && -1*res<MIN)
                return MIN;
            
            if(sign == 1 && res>MAX)
                return MAX;

            i++;
        }

        return (int)(sign*res);
    }
};
