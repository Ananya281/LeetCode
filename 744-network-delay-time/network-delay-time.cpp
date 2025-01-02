class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int edgenode=it.first;
                int wt=it.second;
                if(d+wt<dis[edgenode])
                {
                    dis[edgenode]=d+wt;
                    pq.push({dis[edgenode],edgenode});
                }
            }
        }
        int time=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
            {
                return -1;
            }
            else
            {
                time=max(time,dis[i]);
            }
        }
        return time;
    }
};