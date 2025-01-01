class Solution {
public:
    bool bfs(int node,int color1,vector<vector<int>>&graph,vector<int>&color)
    {
        int n=graph.size();
        queue<int>q;
        q.push(node);
        color[node]=color1;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            for(auto it:graph[ele])
            {
                if(color[it]==-1)
                {
                    if(!bfs(it,!color1,graph,color))
                    {
                        return false;
                    }
                }
                else if(color[it]==color1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i,0,graph,color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};