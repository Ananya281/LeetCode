class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);//neighbor,cost
        for(auto it:flights)//u->{v,cost}
        {
            int u=it[0];
            int v=it[1];
            int p=it[2];
            adj[u].push_back({v,p});
        }
        queue<pair<int,pair<int,int>>>q;//stops,node,price
        q.push({0,{src,0}});
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty())
        {
            int s=q.front().first;
            int node=q.front().second.first;
            int p=q.front().second.second;
            q.pop();
            for(auto it:adj[node])
            {
                int ele=it.first;
                int price=it.second;
                if(p+price<dis[ele] && s<=k)
                {
                    dis[ele]=p+price;
                    q.push({s+1,{ele,dis[ele]}});
                }
            }
        }
        if(dis[dst]==1e9)
        {
            return -1;
        }
        return dis[dst];
    }
};



//if done using priority_queue, minheap
//{cost,,currentnode,stopused}
// TLE occurs
// if (stops > k || stops >= minStops[node]) continue; 
// minStops[node] = stops;
// means:
// If we’ve used too many stops or we have already reached this node using fewer stops, then skip it.
// Otherwise, update and go ahead."