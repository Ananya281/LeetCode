class Solution {
public:
 bool allzero(vector<int>&counter)
    {
        for(auto it:counter)
        {
            if(it!=0)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
         vector<int>result;
        int n=txt.size();
        vector<int>counter(26,0);
        int m=pat.size();
        for(int i=0;i<m;i++)
        {
            char ch=pat[i];
            counter[ch-'a']++;
        }
        int i=0;
        int j=0;
        while(j<n)
        {
            counter[txt[j]-'a']--;
            if(j-i+1<m)
            {
                j++;
            }
            else if(j-i+1==m)
            {
                if(allzero(counter))
                {
                    result.push_back(i);
                }
                counter[txt[i]-'a']++;
                i++;
                j++;
            }
        }
        return result;
    }
};