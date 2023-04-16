class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(),i;

        vector<int> adj[n];
        int inDegree[n];
        memset(inDegree, 0, sizeof(inDegree));

        for(i=0;i<n;i++)
        {
            for(auto u: graph[i])
            {
                adj[u].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for(i=0;i<n;i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int x = q.front();
            ans.push_back(x);

            q.pop();

            for(auto u: adj[x])
            {
                inDegree[u]--;
                if(inDegree[u] ==0)
                {
                    q.push(u);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;


    }
};
