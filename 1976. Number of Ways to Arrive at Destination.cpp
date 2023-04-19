class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
                vector<pair<long long,long long>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LLONG_MAX), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue< pair<long long,long long> , vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        int mod = (int)(1e9+7);

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long node = it.second;
            long long wt = it.first;

            for(auto u : adj[node])
            {
                long long adjNode = u.first;
                long long edWt = u.second;

                if( wt + edWt < dist[adjNode])
                {
                    dist[adjNode] = wt + edWt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if((wt + edWt) == dist[adjNode])
                {
                    ways[adjNode] =( ways[adjNode]+  ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};
