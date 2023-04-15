class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                vector<int> adj[numCourses];
        
        int inDegree[numCourses],i;
        memset(inDegree,0 ,sizeof(inDegree));
        vector<int> topo;

        for(auto u:prerequisites)
        {
            adj[u[1]].push_back(u[0]);
            inDegree[u[0]]++;
        }
        
        queue<int> q;

        for(i=0;i<numCourses;i++)
        {
            if(inDegree[i] == 0)
            q.push(i);
        }
        
        int cnt = 0;

        while(!q.empty())
        {
            int x = q.front();
            cnt++;
            q.pop();

            topo.push_back(x);

            for(auto u : adj[x])
            {
                inDegree[u]--;

                if(inDegree[u] == 0)
                {
                    q.push(u);
                }
            }
        }

        if(cnt== numCourses) return topo;

        return {};
    }
};
