class Solution {
public:

    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>> &vis,int n,int m)
    {
        vis[i][j] = 1;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k=0;k<4;k++)
        {
            int x = i+dx[k];
            int y = j+dy[k];

            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && board[x][y]=='O')
            {
                dfs(x,y,board,vis,n,m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int i,j;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(i=0,j=0;j<m;j++)
        {
            if(board[i][j]=='O')
            {
                dfs(i,j,board,vis,n,m);
            }
        }
        for(i=0,j=0;i<n;i++)
        {
            if(board[i][j]=='O')
            {
                dfs(i,j,board,vis,n,m);
            }
        }
        for(i=n-1,j=0;j<m;j++)
        {
            if(board[i][j]=='O')
            {
                dfs(i,j,board,vis,n,m);
            }
        }
        for(i=0,j=m-1;i<n;i++)
        {
            if(board[i][j]=='O')
            {
                dfs(i,j,board,vis,n,m);
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                board[i][j] = 'X';
            }
        }
    }
};
