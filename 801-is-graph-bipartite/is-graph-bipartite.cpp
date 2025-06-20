class Solution {
public:
    bool bfs(int node, int color, vector<int>& colored, vector<vector<int>>& graph, queue<int>& q)
    {
        int n = graph.size();
        colored[node] = color;
        q.push(node);
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            for(auto it:graph[n])
            {
                if(colored[it]==-1)
                {
                    if(bfs(it,!color,colored,graph,q) == false)
                    {
                        return false;
                    }   
                }
                else if(colored[it] == color)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colored(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(colored[i]==-1)
            {
                if(bfs(i,0,colored,graph,q) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};