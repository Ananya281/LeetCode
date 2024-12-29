class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend==divisor)
       {
        return 1;
       }
       if(dividend==INT_MIN&&divisor==-1)
       {
        return INT_MAX;
       }
       bool sign=true;
       if(dividend>=0&&divisor<0)
       {    
            sign=false;
       }
       else if(dividend<0&&divisor>0)
       {
            sign=false;
       }
       long long n=abs((long long)dividend);
       long long d=abs((long long)divisor);
       long long ans=0;
       while(n>=d)
       {
        int count=0;
        while((n>=(d<<(count)))&&(count<31))
        {
            count++;
        }
        if(count>0)
        {
            ans=ans+(1LL<<(count-1));
            n=n-(d<<(count-1));
        }
       }
       if(sign==false)
       {
        return ans*(-1);
       }
       else
       {
        return ans;
       }
    }
};