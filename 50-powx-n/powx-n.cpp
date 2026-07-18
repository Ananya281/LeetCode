class Solution {
public:
    double myPow(double x, int n) {
        long long num=n;
        if(num<0)
        {
            num=num*(-1);
        }
        double ans=1;
        while(num>0)
        {
            if(num%2==0)
            {
                x=x*x;
                num=num/2;
            }
            else
            {
                ans=ans*x;
                num=num-1;
            }
        }
        if(n<0)
        {
            ans=(double)1/ans;
        }
        return ans;
    }
};