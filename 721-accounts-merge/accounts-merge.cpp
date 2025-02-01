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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        map<string,int>mpp;
        for(int i=0;i<n;i++)
        {
            int s=accounts[i].size();
            for(int j=1;j<s;j++)
            {
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end())
                {
                    mpp[mail]=i;
                }
                else
                {
                    ds.unionsize(i,mpp[mail]); 
                }
            }
        }
        vector<vector<string>>merge(n);
        for(auto it:mpp)
        {
            string mail=it.first;
            int node=ds.find(it.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            vector<string>result;
            if(merge[i].size()==0)
            {
                continue;
            }
            result.push_back(accounts[i][0]);
            for(auto it:merge[i])
            {
                result.push_back(it);
            }
            ans.push_back(result);
        }
        return ans;
    }
};