class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int c=it[2];
            adj[u].push_back({v,c});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});//{stop,{node,cost}}
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        while(!q.empty())
        {
            int stop=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int cw=it.second;
                if(cost+cw<dis[adjnode]&&stop<=k)
                {
                    dis[adjnode]=cost+cw;
                    q.push({stop+1,{adjnode,dis[adjnode]}});
                }
            }
        }
        if(dis[dst]==INT_MAX)
        {
            return -1;
        }
        return dis[dst];
    }
};