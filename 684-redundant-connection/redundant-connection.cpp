class dsu{
    public:
        vector<int>parent;
        vector<int>size;
        dsu(int n)
        {
            parent.resize(n+1,0);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        int find(int n)
        {
            if(n==parent[n])
            {
                return n;
            }
            return parent[n]=find(parent[n]);
        }
        bool unionsize(int u,int v)
        {
            int ulpu=find(u);
            int ulpv=find(v);
            if(ulpu==ulpv)
            {
                return true;
            }
            if(size[ulpu]<size[ulpv])
            {
                parent[ulpu]=ulpv;
                size[ulpv]=size[ulpv]+size[ulpu];
            }
            else
            {
                parent[ulpv]=ulpu;
                size[ulpu]=size[ulpu]+size[ulpv];
            }
            return false;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu ds(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.unionsize(u,v))
            {
                return it;
            }
        }
        return {};
    }
};