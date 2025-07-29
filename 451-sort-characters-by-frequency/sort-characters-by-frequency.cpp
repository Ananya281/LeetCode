class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp)
        {
            int f=it.second;
            char c=it.first;
            pq.push({f,c});
        }
        string str;
        while(!pq.empty())
        {
            int f=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            str.append(f,c);
        }
        return str;
    }
};