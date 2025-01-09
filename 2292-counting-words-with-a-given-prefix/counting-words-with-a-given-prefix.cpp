class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int m=pref.size();
        int count=0;
        for(auto it:words)
        {
            int i=0;
            while(i<m)
            {
                if(it[i]!=pref[i])
                {
                    break;
                }
                i++;
                if(i==m)
                {
                    count++;
                }
            }
        }
        return count;
    }
};