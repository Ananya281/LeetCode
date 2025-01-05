class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n+1,0);
        for(auto it:shifts)
        {
            int start=it[0];
            int end=it[1];
            int direction=it[2];
            if(direction==1)
            {
                diff[start]++;
                diff[end+1]--;
            }
            if(direction==0)
            {
                diff[start]--;
                diff[end+1]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            diff[i]=diff[i]+diff[i-1];
        }
        for(int i=0;i<n;i++)
        {
            int count=diff[i]%26;
            if(count<0)
            {
                count=count+26;
            }
            s[i]=((count+s[i]-'a')%26)+'a';
        }
        return s;
    }
};


// s=abc n=3
// shifts=[[0,1,0][1,2,1][0,2,1]]
// vector diff(n+1,0) [0,0,0,0]
// it=[0,1,0] start=0 end=1 bw diff[-1,0,+1,0] 
// it=[1,2,1] start=1 end=2 fw diff[-1,+1,+1,-1]
// it=[0,2,1] start=0 end=2 fw diff[0,+1,+1,-2] 
// [0,+1,+2,0]cumfreq last vala redundant 
// s[0] 0%26=0<0 no then no count no change
// s[1] inc by 1  1%26=1=count 
// s[2] inc by 2  2%26=1=count

// -2%26=-2
// -2+26=24
// a--->y
// to make negative to non-negative
// in case of backward shift