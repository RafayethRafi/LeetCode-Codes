class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size(), i;
        if(grid[0][0] !=0 || grid[n-1][n-1] != 0) return -1;
        if(n==1) return 1;
        vector<vector<int>> dist(n, vector<int>(n,1e9));

        dist[0][0] = 1;

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        int dx[] = {1,-1,0,0,1,1,-1,-1};
        int dy[] = {0,0,1,-1,1,-1,1,-1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;


            for(i=0;i<8;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && (grid[nr][nc] == 0) && ( dis + 1 < dist[nr][nc]))
                {
                    if((nr == (n-1)) && (nc == (n-1))) return (dis + 1);

                    dist[nr][nc] = dis+1;
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }

        return -1;
    }
};
