class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums)
        {
            mpp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mpp)
        {
            int value=it.first;
            int freq=it.second;
            pq.push({freq,value});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>result;
        while(!pq.empty())
        {
            int value=pq.top().second;
            result.push_back(value);
            pq.pop();
        }
        return result;
    }
};