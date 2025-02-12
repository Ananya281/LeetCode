class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(piles[i]);
        }
        while(k>0 && !pq.empty())
        {
            int num=pq.top();
            pq.pop();
            num=num-num/2;
            pq.push(num);
            k--;
        }
        int sum=0;
        while(!pq.empty())
        {
            int num=pq.top();
            sum=sum+num;
            pq.pop();
        }
        return sum;
    }
};