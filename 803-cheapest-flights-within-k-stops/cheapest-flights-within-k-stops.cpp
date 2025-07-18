class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        vector<int>minstops(n,1e9);
        while(!pq.empty())
        {
            int cost=pq.top()[0];
            int node=pq.top()[1];
            int stops=pq.top()[2];
            pq.pop();
            if(node==dst)
            {
                return cost;
            }
            if(stops>k || stops>=minstops[node])
            {
                continue;
            }
            minstops[node]=stops;
            for(auto it:adj[node])
            {
                int nei=it.first;
                int price=it.second;
                pq.push({cost+price,nei,stops+1});
            }
        }
        return -1;
    }
};