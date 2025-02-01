class DisjointSet
{
    public:
        vector<int>parent;
        vector<int>size;
        vector<int>rank;
        DisjointSet(int n)
        {
            parent.resize(n+1,0);
            size.resize(n+1,0);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        int find(int u)
        {
            if(u==parent[u])
            {
                return u;
            }
            return parent[u]=find(parent[u]);
        }
        void unionrank(int u,int v)
        {
            int up=find(u);
            int vp=find(v);
            if(up==vp)
            {
                return;
            }
            if(rank[up]<rank[vp])
            {
                parent[up]=vp;
            }
            else if(rank[vp]<rank[up])
            {
                parent[vp]=up;
            }
            else
            {
                parent[up]=vp;
                rank[vp]++;
            }
        }
        void unionsize(int u,int v)
        {
            int up=find(u);
            int vp=find(v);
            if(up==vp)
            {
                return;
            }
            if(size[up]<size[vp])
            {
                parent[up]=vp;
                size[vp]=size[vp]+size[up];
            }
            else
            {
                parent[vp]=up;
                size[up]=size[up]+size[vp];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int edges=0;
        for(auto it:connections)
        {
            int node1=it[0];
            int node2=it[1];
            int pnode1=ds.find(node1);
            int pnode2=ds.find(node2);
            if(pnode1==pnode2)
            {
                edges++;
            }
            else
            {
                ds.unionsize(node1,node2);
            }
        }
        int compo=0;
        for(int i=0;i<n;i++)
        {
            if(i==ds.find(i))
            {
                compo++;
            }
        }
        if((compo-1)>(edges))
        {
            return -1;
        }
        return compo-1;
    }
};