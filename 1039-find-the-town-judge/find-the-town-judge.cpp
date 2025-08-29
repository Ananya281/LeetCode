class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(auto it:trust)
        {
            int a=it[0];
            int b=it[1];
            indegree[b]++;
            outdegree[a]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(outdegree[i]==0 && indegree[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};