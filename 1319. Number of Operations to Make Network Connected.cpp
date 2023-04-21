class DisjointSet{
public:

    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node)
    {
        if(node == parent[node])
        return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ul_pu = findPar(u);
        int ul_pv = findPar(v);

        if( ul_pu == ul_pv) return;
        if(rank[ul_pu] < rank[ul_pv])
        {
            parent[ul_pu] = ul_pv;
        }
        else if(rank[ul_pv] < rank[ul_pu])
        {
            parent[ul_pv] = ul_pu;
        }
        else{
            parent[ul_pv] = ul_pu;
            rank[ul_pu]++;
        }
    }

    void unionBySize(int u,int v){
        int ul_pu = findPar(u);
        int ul_pv = findPar(v);

        if( ul_pu == ul_pv) return;

        if(size[ul_pu] < size[ul_pv]){
            parent[ul_pu] = ul_pv;
            size[ul_pv] += size[ul_pu];
        }
        else{
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extra = 0;
        
        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if( ds.findPar(u) == ds.findPar(v))
            {
                extra++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if( ds.parent[i] == i)
            ans++;
        }

        ans--;

        if(extra >= ans) return ans;

        return -1;
    }
};
