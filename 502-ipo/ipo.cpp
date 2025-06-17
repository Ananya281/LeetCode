class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>vec;//vector{capital,profit}
        for(int i=0;i<n;i++)
        {
            vec.push_back({capital[i],profits[i]});
        }
        priority_queue<int>pq;
        sort(vec.begin(),vec.end());//sort vector
        int i=0;
        while(k>0)
        {
            while(i<n && vec[i].first<=w)//iterate on vector where capital<=w add into heap
            {
                pq.push(vec[i].second);
                i++;
            }
            if(pq.empty())
            {
                break;
            }
            int t=pq.top();//add top value in heap, w will increase by profit
            pq.pop();
            w=w+t;
            k--;
        }
        return w;
    }
};