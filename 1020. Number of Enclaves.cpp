class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i,j,ans=0;
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        
        queue<pair<int,int>> q;

        for(i=0,j=0;j<m;j++)
        {
            if(grid[i][j] == 1 && !vis[i][j])
            {
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
        for(i=n-1,j=0;j<m;j++)
        {
            if(grid[i][j] == 1 && !vis[i][j])
            {
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
        for(i=0,j=0;i<n;i++)
        {
            if(grid[i][j] == 1 && !vis[i][j])
            {
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
        for(i=0,j=m-1;i<n;i++)
        {
            if(grid[i][j] == 1 && !vis[i][j])
            {
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty())
        {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for(i=0;i<4;i++)
            {
                int x = u+dx[i];
                int y = v+dy[i];

                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1 && !vis[x][y])
                {
                    q.push({x,y});
                    vis[x][y] = 1;
                }
            }

        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                ans++;
            }
        }

        return ans;
    }
};
