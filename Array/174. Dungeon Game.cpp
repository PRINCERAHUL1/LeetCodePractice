class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();
        vector<vector<int>> solve(r, vector<int>(c));

        solve[r-1][c-1] = dungeon[r-1][c-1] > 0 ? 1 : 1-dungeon[r-1][c-1];

        for(int i = r-2; i>=0; i--)
            solve[i][c-1] = max(solve[i+1][c-1] - dungeon[i][c-1], 1);
        
        for(int j = c-2; j>=0; j--)
            solve[r-1][j] = max(solve[r-1][j+1] - dungeon[r-1][j], 1);
        
        for(int i = r-2; i>=0; i--)
        {
            for(int j = c-2; j>=0; j--)
            {
                solve[i][j] = max(min(solve[i+1][j], solve[i][j+1]) - dungeon[i][j], 1);
            }
        }

        return solve[0][0];
    }
};
