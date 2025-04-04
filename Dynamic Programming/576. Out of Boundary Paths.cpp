class Solution {
public:

    int dp[51][51][51];
    int mod = 1000000007;

    long countBoundary(int m, int n, int maxMove, int i, int j)
    {
        if(i>=m || i<0 || j>=n || j<0)
            return 1;
        
        if(maxMove <= 0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        
        long res = 0;
        res += countBoundary(m, n, maxMove-1, i-1, j);
        res += countBoundary(m, n, maxMove-1, i+1, j);
        res += countBoundary(m, n, maxMove-1, i, j-1);
        res += countBoundary(m, n, maxMove-1, i, j+1);
        return dp[i][j][maxMove] = res%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return countBoundary(m, n, maxMove, startRow, startColumn);
    }
};
