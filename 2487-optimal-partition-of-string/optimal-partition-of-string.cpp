class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        vector<int>lastseen(26,-1);
        int count=0;
        int currstr=0;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(lastseen[ch-'a']>=currstr)
            {
                count++;
                currstr=i;
            }
            lastseen[ch-'a']=i;
        }
        return count+1;
    }
};