class Solution {
public:

    vector<pair<int,int>> direction = {{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    int memo[205][205];
    
    int dfs(vector<vector<int>>& matrix, int r, int c)
    {
        if (memo[r][c] != 0)
            return memo[r][c];

        int tempAns = 1;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + direction[i].first;
            int nc = c + direction[i].second;
            
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && matrix[nr][nc] > matrix[r][c])
                tempAns = max(tempAns, 1 + dfs(matrix, nr, nc));
        }

        return memo[r][c] = tempAns;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                res = max(res, dfs(matrix, i, j));
        }

        return res;
    }
};
