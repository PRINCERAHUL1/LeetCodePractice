class Solution {
public:

    bool isSafe(int row, int col, int n, vector<vector<char>>& board)
    {
        for (int c=0; c<col; c++)
        {    
            if (board[row][c] == 'Q') 
                return false;
        }

        for (int r=row, c=col; r>=0 && c>=0; r--, c--)
        {   
             if (board[r][c] == 'Q')
                return false;
        }
        
        for (int r=row, c=col; r<n && c>=0; r++, c--)
        {
            if (board[r][c] == 'Q') 
                return false;
        }
        
        return true;
    }

    void backtrack(int col, int n, vector<vector<char>>& board, int& count)
    {
        if (col == n)
        {
            count++;
            return;
        }

        for (int row=0; row<n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 'Q';
                backtrack(col + 1, n, board, count);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int count = 0;
        
        backtrack(0, n, board, count);
        return count;
    }
};
