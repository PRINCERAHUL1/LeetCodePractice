class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> rowSet;

            for (int j = 0; j < n; j++)
            {
                int x = matrix[i][j];
                
                if (x < 1 || x > n || rowSet.count(x))
                    return false;
                
                rowSet.insert(x);
            }
        }

        for (int j = 0; j < n; j++)
        {
            unordered_set<int> colSet;

            for (int i = 0; i < n; i++)
            {
                int x = matrix[i][j];
                
                if (x < 1 || x > n || colSet.count(x))
                    return false;
                
                colSet.insert(x);
            }
        }

        return true;
    }
};
