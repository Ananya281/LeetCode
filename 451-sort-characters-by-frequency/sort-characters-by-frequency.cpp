class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto it:s)
        {
            freq[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:freq)
        {
            pq.push({it.second,it.first});
        }
        string result="";
        while(!pq.empty())
        {
            int count=pq.top().first;
            int ch=pq.top().second;
            pq.pop();
            result.append(count,ch);
        }
        return result;
    }
};