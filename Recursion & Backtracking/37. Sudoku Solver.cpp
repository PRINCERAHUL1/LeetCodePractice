class Solution {
public:

    bool notClash(char num, int i, int j, vector<vector<char>>& board, int n)
    {
        for(int k=0; k<n; k++)
        {
            if(board[i][k] == num)
                return false;
            if(board[k][j] == num)
                return false;
        }

        int s = sqrt(n);
        int startRow = i - i%s;
        int startCol = j - j%s;

        for(int r = startRow; r<startRow+s; r++)
        {
            for(int c = startCol; c<startCol+s; c++)
            {
                if(board[r][c] == num)
                    return false;
            }
        }

        return true;
    }

    bool solver(vector<vector<char>>& board, int n)
    {
        int i,j;
        bool flag = false;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(board[i][j] == '.')
                {
                    flag = true;
                    break;
                }
            }

            if(flag)
                break;
        }

        if(i == n && j == n)
            return true;

        for(int num=1; num<=n; num++)
        {
            if(notClash(num+48, i,j,board, n))
            {
                board[i][j] = num+48;
                
                if(solver(board, n))
                    return true;
                
                board[i][j] = '.'; 
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        
        int n = board.size();
        solver(board, n);
    }
};
