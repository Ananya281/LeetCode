class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==dividend)
        {
            return 1;
        }
        bool sign=true;
        if((dividend>=0 && divisor<0) || (dividend<=0 && divisor>0))
        {
            sign=false;
        }
        long n=abs(long(dividend));
        long d=abs(long(divisor));
        int ans=0;
        while(n>=d)
        {
            int count=0;
            while(n>=(d<<(count+1)) && count<31)
            {
                count++;
            }
            ans=ans+(1<<count);
            n=n-(d<<count);
        }
        if(ans==(1<<31) && sign==true)
        {
            return INT_MAX;
        }
        if(ans==(1<<31) && sign==false)
        {
            return INT_MIN;
        }
        if(sign==false)
        {
            return -ans;
        }
        else
        {
            return ans;
        }
    }
};