class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        // vector<array<int,3>>sorted;
        // vector<vector<int>>sorted(n,vector<int>(3));
        vector<vector<int>>sorted;
        for(int i=0;i<n;i++)
        {
            int st=tasks[i][0];
            int pre=tasks[i][1];
            // sorted.push_back({st,pre,i});
            // sorted[i][0]=st;
            // sorted[i][1]=pre;
            // sorted[i][2]=i;
            sorted.push_back({st,pre,i});
        }
        sort(sorted.begin(),sorted.end());
        vector<int>result;
        long long curr=0;
        int ind=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        while(ind<n || !pq.empty())
        {
            if(pq.empty() && curr<sorted[ind][0])
            {
                curr=sorted[ind][0];
            }
            while(ind<n && sorted[ind][0]<=curr)
            {
                pq.push({sorted[ind][1],sorted[ind][2]});
                ind++;
            }
            pair<int,int>currtask=pq.top();
            pq.pop();
            curr=curr+currtask.first;
            result.push_back(currtask.second);
        }
        return result;
    }
};