class Solution {
public:
    long long power(long long x,long long n,int mod)
    {
        long long ans=1;
        while(n>0)
        {
            if(n%2==0)
            {
                x=x*x%mod;
                n=n/2;
            }
            else
            {
                ans=ans*x%mod;
                n--;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        int mod=1e9+7;
        long long oddplace=n/2;
        long long evenplace=(n+1)/2;
        long long poweven=power(5,evenplace,mod);
        long long powodd=power(4,oddplace,mod);
        return powodd*poweven%mod;
    }
};