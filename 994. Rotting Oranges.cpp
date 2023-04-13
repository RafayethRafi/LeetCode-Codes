class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),i,j;
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
                vis[i][j] = 0;
            }
        }

        int mxt = 0;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        while(!q.empty())
        {
            int u = q.front().first.first;
            int v= q.front().first.second;
            int t = q.front().second;
            mxt =max(mxt,t);

            q.pop();

            for(i=0;i<4;i++)
            {
                int x = u + dx[i];
                int y = v + dy[i];
                
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y] != 2 && grid[x][y]==1)
                {
                    q.push({{x,y},t+1});
                    vis[x][y] = 2;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if((vis[i][j] != 2) && (grid[i][j]==1))
                return -1;
            }
        }

        return mxt;

    }
};
