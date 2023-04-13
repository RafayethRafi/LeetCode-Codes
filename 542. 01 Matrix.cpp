class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n,vector<int>(m,0));
        int vis[n][m],i,j;

        memset(vis,0,sizeof(vis));

        queue<pair<int,int>> q;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
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
                int x = u+ dx[i];
                int y = v + dy[i];

                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && mat[x][y] == 1)
                {
                    vis[x][y] = 1;
                    q.push({x,y});
                    ans[x][y] = ans[u][v] + 1;
                }
            }
        }

        return ans;

    }
};
