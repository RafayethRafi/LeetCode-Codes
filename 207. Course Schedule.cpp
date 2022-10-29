class Solution {
public:

    bool cycle(int cur,int vertex,vector<bool>&vis,vector<vector<int>>&v)
    {
        vis[cur] =1;
        
        for(auto u:v[cur])
        {
            if(u==vertex)
                return true;
            
            if(!vis[u])
            {
                if(cycle(u,vertex,vis,v))
                    return true;
            }
        }
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);

        for(int i=0;i<prerequisites.size();i++)
        {
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            vector<bool>vis(numCourses,0);
            if(cycle(i,i,vis,v))
                return false;
        }
        
        return true;
        
    }

    
};
