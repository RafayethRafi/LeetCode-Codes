class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0] = 0;

        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int dx[] ={1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c== m-1) return diff;
            
            for(int i=0;i<4;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int newEffort = max( diff, abs( heights[nr][nc] - heights[r][c]));

                    if(newEffort < effort[nr][nc])
                    {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

        return effort[n-1][m-1];
    }
};
