class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            result.push_back(ele);
            for(auto it:adj[ele])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return result.size()==n ? result : vector<int>{};
    }
};