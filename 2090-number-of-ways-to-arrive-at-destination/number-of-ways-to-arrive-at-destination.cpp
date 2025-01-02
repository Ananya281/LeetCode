class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        int mod=1e9+7;
        vector<int>path(n,0);
        path[0]=1;
        vector<long long>dis(n,LLONG_MAX);
        dis[0]=0;
        while(!pq.empty())
        {
            long long t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int wt=it.second;
                if(t+wt<dis[adjnode])
                {
                    dis[adjnode]=t+wt;
                    path[adjnode]=path[node];
                    pq.push({dis[adjnode],adjnode});
                }
                else if(t+wt==dis[adjnode])
                {
                    path[adjnode]=(path[node]+path[adjnode])%mod;
                }
            }
        }
        return path[n-1]%mod;
    }
};