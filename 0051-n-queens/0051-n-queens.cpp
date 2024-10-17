class Solution {
public:
    bool issafe(int row,int col,int n,vector<string> & board)
    {
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }

        row = duprow;
        col = dupcol;

        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans)
    {
        if(col==n) 
        {
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(issafe(i,col,n,board))
            {
                board[i][col] = 'Q';
                solve(col+1,n,board,ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }

        solve(0,n,board,ans);

        return ans;
    }
};