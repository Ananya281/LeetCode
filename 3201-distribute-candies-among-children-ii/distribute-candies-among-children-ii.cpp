#include <algorithm>

class Solution {
public:
    long long distributeCandies(int n, int limit) {
     int min1=max(0,n-2*limit);
     int max1=min(n,limit);
     long long ways=0;
     for(int i=min1;i<=max1;i++)
     {
        int N=n-i;
        int mini=max(0,N-limit);
        int maxi=min(limit,N);
        ways=ways+(maxi-mini+1);
     }
     return ways;
    }
};