class Solution {
public:
    int smallestNumber(int n) {
        if(n==0)
        {
            return 1;
        }
        for(int i=1;i<1000;i++)
        {
            int num=pow(2,i);
            if(num>n)
            {
                return num-1;
            }
        }
        return -1;
    }
};