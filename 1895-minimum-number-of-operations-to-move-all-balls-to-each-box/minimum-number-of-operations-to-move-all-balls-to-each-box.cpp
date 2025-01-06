class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>cum(n,0);
        for(int i=0;i<n;i++)
        {
            int sum=0;
            int j=0;
            while(j<n)
            {
                if(boxes[j]=='1' && i!=j)
                {
                    sum=sum+abs(j-i);
                }
                j++;
            }
            cum[i]=sum;
        }
        return cum;
    }
};