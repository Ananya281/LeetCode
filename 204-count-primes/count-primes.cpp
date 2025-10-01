class Solution {
public:
    int countPrimes(int n) {
        if(n<2)
        {
            return 0;
        }
        vector<int>temp(n,1);
        temp[0]=0;
        temp[1]=0;
        for(int i=2;i<sqrt(n);i++)
        {
            if(temp[i]==1)
            {
                for(int j=i*i;j<n;j=j+i)
                {
                    temp[j]=0;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(temp[i])
            {
                count++;
            }
        }
        return count;
    }
};