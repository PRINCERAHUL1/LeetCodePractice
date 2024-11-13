class Solution {
public:
    string clearDigits(string s) {
        int i=0;
        string res;

        while(i < s.length())
        {
            if(!isdigit(s[i]))
                res += s[i];
            else
                res.pop_back();
            
            i++;
        }

        return res;
    }
};
