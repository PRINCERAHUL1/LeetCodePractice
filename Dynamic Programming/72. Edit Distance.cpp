class Solution {
public:

    int minDist(string &word1, string &word2, vector<vector<int>> &dp, int i, int j)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == 0)
        {
            dp[i][j] == j;
            return j;
        }

        if(j == 0)
        {
            dp[i][j] == i;
            return i;
        }

        if(word1[i-1] == word2[j-1])
            dp[i][j] = minDist(word1, word2, dp, i-1, j-1);
        else
        {
            int insertOp = minDist(word1, word2, dp, i, j-1);
            int deleteOp = minDist(word1, word2, dp, i-1, j);
            int replaceOp = minDist(word1, word2, dp, i-1, j-1);

            dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }

        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return minDist(word1, word2, dp, m, n);
    }
};
