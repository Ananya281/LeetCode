class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            freq[c-'a']++;
        }
        unordered_set<int>st;
        int count=0;
        for(int i=0;i<26;i++)
        {
            while(freq[i]>0 && st.find(freq[i])!=st.end())
            {
                freq[i]--;
                count++;
            }
            st.insert(freq[i]);
        }
        return count;
    }
};