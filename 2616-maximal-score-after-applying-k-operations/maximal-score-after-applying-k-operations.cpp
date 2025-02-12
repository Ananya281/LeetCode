class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long>pq;
        for(int i=0;i<n;i++)
        {
            pq.push((long long)nums[i]);
        }
        long long sum=0;
        while(k>0 && !pq.empty())
        {
            long long num=pq.top();
            pq.pop();
            sum=sum+num;
            pq.push(ceil(num/3.0));
            k--;
        }
        return sum;
    }
};