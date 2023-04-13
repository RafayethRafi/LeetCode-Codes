class Solution {
public:

bool dfs(int node,int col,int color[],vector<vector<int>>& graph )
{
    color[node] = col;
    for(auto u: graph[node])
    {
        if(color[u]==-1)
        {
            if(dfs(u,!col,color,graph)== false)
            return false;
        }
        else if(color[u] == col)
        {
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        int color[n];
        memset(color,-1,sizeof(color));

        for(int i=0;i<n;i++)
        {
            if(color[i]== -1)
            {
                if(dfs(i,0,color,graph)==false)
                return false;
            }
        }

        return true;
    }
};
