class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(vec.begin(),vec.end());
        vector<int>result;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        long long time=0;
        long long ind=0;
        while(ind<n || !pq.empty())
        {
            if(pq.empty() && time<vec[ind][0])//cpu idle+no task before
            {
                time=vec[ind][0];
            }
            while(ind<n && vec[ind][0]<=time)//cpu idle but task available 
            {
                pq.push({vec[ind][1],vec[ind][2]});
                ind++;
            }
            long long t=pq.top().first;
            long long i=pq.top().second;
            pq.pop();
            time=time+t;
            result.push_back((int)i);
        }
        return result;
    }
};