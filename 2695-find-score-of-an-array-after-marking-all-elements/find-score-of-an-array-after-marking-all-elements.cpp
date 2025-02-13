class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        while(!pq.empty())
        {
            int num=pq.top().first;
            int ind=pq.top().second;
            pq.pop();
            if(vis[ind]==true)
            {
                continue;
            }
            else
            {
                vis[ind]=true;
                if((ind-1)>=0)
                {
                    vis[ind-1]=true;
                }
                if((ind+1)<n)
                {
                    vis[ind+1]=true;
                }
                sum=sum+(long long)nums[ind];
            }
        }
        return sum;
    }
};