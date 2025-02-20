class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0;
        int j = s.size()-1;
        bool flag = true;

        while(i <= j)
        {
            if(s[i] != s[j])
                flag = false;
            
            i++;
            j--;
        }

        if(flag)
            return 1;
        
        return 2;
    }
};
