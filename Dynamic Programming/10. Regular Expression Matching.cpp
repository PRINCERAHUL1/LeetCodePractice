class Solution {
public:

    int stringMatch(vector<vector<int>> &dp, string &s, string &p, int lenS, int lenP)
    {
        if(lenS == 0 && lenP == 0)
            return 1;
        
        if(lenP == 0)
            return 0;
        
        if(dp[lenS][lenP] != -1)
            return dp[lenS][lenP];
        
        if(lenP > 1 && p[lenP - 1] == '*')
        {
            int res = stringMatch(dp, s, p, lenS, lenP - 2);
            int len_rep = 0;

            while(lenS - len_rep > 0 && (s[lenS - 1 - len_rep] == p[lenP - 2] || p[lenP - 2] == '.'))
            {
                len_rep++;
                res = res | stringMatch(dp, s, p, lenS - len_rep, lenP - 2);
            }

            return dp[lenS][lenP] = res;
        }

        if(lenS == 0)
            return dp[lenS][lenP] = 0;

        if(p[lenP - 1] == '.' || s[lenS - 1] == p[lenP - 1])
            return dp[lenS][lenP] = stringMatch(dp, s, p, lenS - 1, lenP - 1);
            
        return dp[lenS][lenP] = 0;
    }

    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        vector<vector<int>> dp(lenS+1, vector<int>(lenP+1, -1));

        return stringMatch(dp, s, p, lenS, lenP);
    }
};

