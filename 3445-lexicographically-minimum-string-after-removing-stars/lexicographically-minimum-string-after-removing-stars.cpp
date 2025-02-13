class Solution {
public:
    struct comp
    {
        bool operator()(pair<char,int>&p1,pair<char,int>&p2)
        {
            if(p1.first==p2.first)
            {
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        int n=s.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
            {
                pq.push({s[i],i});
            }
            else
            {
                int ind=pq.top().second;
                pq.pop();
                s[ind]='*';
            }
        }
        string result="";
        for(auto it:s)
        {
            if(it!='*')
            {
                result.push_back(it);
            }
        }
        return result;
    }
};