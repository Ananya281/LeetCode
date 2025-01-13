class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        map<char,int>mpp;
        for(char c:s)
        {
            mpp[c]++;
        }
        int count=0;
        for(auto it:mpp)
        {
            int freq=it.second;
            while(freq>=3)
            {
                freq=freq-2;
            }
            count=count+freq;
        }
        return count;
    }
};
//abaacbcbb
