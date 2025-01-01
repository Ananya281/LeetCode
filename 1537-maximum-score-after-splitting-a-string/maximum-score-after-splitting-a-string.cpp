class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int i=0;
        int j=1;
        int score=0;
        while(j<n)
        {
            int count0=0;
            int count1=0;
            for(int r=0;r<=i;r++)
            {
                if(s[r]=='0')
                {
                    count0++;
                }
            }
            for(int t=j;t<n;t++)
            {
                if(s[t]=='1')
                {
                    count1++;
                }
            }
            score=max(score,count0+count1);
            i=j;
            j++;
        }
        return score;
    }
};