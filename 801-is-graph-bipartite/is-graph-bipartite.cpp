class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,int color,vector<int>&visited)
    {
        visited[node]=color;
        for(auto it:graph[node])
        {
            if(visited[it]==-1)
            {
                if(!dfs(it,graph,!color,visited))
                {
                    return false;
                }
            }
            else if(visited[it]==color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color=0;
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                if(dfs(i,graph,color,visited)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};