class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if(n==INT_MIN)
        {
            return 1/(myPow(x,INT_MAX)*x);
        }
        if(n<0)
        {
            x=1/x;
            n=n*(-1);
        }
        while(n>0)
        {
            if(n%2==1)
            {
                ans=ans*x;
                n--;
            }
            else
            {
                n=n/2;
                x=x*x;
            }
        }
        return ans;
    }
};