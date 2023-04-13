class Solution {
public:

    void dfs(int i, vector<vector<int>>& isConnected, vector<int> &vis)
    {


        vis[i] = 1;
        for(int j=0;j<isConnected[i].size();j++)
        {
            if(isConnected[i][j] == 1 && vis[j]== 0)
            {
                dfs(j,isConnected,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size(),0);

        int ans = 0,i;

        for(i=0;i<isConnected.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans;
    }
};
