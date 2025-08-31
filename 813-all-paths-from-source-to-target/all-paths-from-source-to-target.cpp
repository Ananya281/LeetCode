class Solution {
public:
    void dfs(vector<vector<int>>&graph,int node,int dest,vector<vector<int>>&result,vector<int>&temp)
    {
        temp.push_back(node);
        if(node==dest)
        {
            result.push_back(temp);
        }
        else
        {
            for(auto it:graph[node])
            {
                dfs(graph,it,dest,result,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int source=0;
        int dest=n-1;
        vector<vector<int>>result;
        vector<int>temp;
        dfs(graph,source,dest,result,temp);
        return result;
    }
};