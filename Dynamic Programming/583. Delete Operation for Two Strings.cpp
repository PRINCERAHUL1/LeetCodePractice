class Solution {
public:

    vector<vector<int>> dp;
    int helper(string &w1, string &w2, int i, int j)
    {
        if(i == w1.size() && j == w2.size())
            return 0;
        
        if(i == w1.size() || j == w2.size())
            return max(w1.size()-i, w2.size()-j);
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(w1[i] == w2[j])
            return helper(w1, w2, i+1, j+1);
        
        return dp[i][j] = 1+(min(helper(w1, w2, i+1, j), helper(w1, w2, i, j+1)));
    }

    int minDistance(string word1, string word2) {
        dp.resize(word1.size()+1, vector<int>(word2.size()+1, -1));
        return helper(word1, word2, 0, 0);
    }
};
