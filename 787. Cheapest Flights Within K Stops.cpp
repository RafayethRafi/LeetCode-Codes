class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);
        dist[src] = 0;

        queue<pair<int,pair<int,int>>> q;

        q.push({0,{0,src}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int dis = it.second.first;
            int node = it.second.second;

            if(steps >k ) continue;

            for(auto u : adj[node])
            {
                int adjNode = u.first;
                int edWt = u.second;

                if( dis + edWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edWt;
                    q.push({steps+1,{dist[adjNode],adjNode}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
