class Solution {
public:
    bool dfs(int node,vector<int>&visited,vector<vector<int>>&graph,int color)
    {
        visited[node]=color;
        for(auto it:graph[node])
        {
            if(visited[it]==-1)
            {
                if(dfs(it,visited,graph,!color)==false)
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
        vector<int>visited(n,-1);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                if(dfs(i,visited,graph,0)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};