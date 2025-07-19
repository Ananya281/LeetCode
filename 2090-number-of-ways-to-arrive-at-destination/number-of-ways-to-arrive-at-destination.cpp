class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int mod=1e9+7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dis(n,LLONG_MAX);
        vector<int>path(n,0);
        dis[0]=0;
        path[0]=1;
        while(!pq.empty())
        {
            int node=pq.top().second;
            long long d=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int ele=it.first;
                int wt=it.second;
                if(d+wt<dis[ele])
                {
                    dis[ele]=d+wt;
                    pq.push({dis[ele],ele});
                    path[ele]=path[node];
                }
                else if(d+wt==dis[ele])
                {
                    path[ele]=(path[ele]+path[node])%mod;
                }
            }
        }
        return path[n-1]%mod;
    }
};