class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n<k)
        {
            return false;
        }
        map<char,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
        }
        int count=0;
        for(auto it:mpp)
        {
            if((it.second)%2==1)
            {
                count++;
            }
        }
        if(count>k)
        {
            return false;
        }
        return true;
    }
};

//k=3 n=2 false
//string max pallindrome=n
//leetcode l t c o d e count=6 k=3 false max=8 min=6 k<min false