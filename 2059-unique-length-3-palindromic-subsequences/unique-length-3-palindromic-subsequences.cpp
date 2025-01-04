class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<char>letters;
        for(int i=0;i<n;i++)
        {
            letters.insert(s[i]);
        }
        int result=0;
        for(char it:letters)
        {
            int first=-1;
            int last=-1;
            for(int i=0;i<n;i++)
            {
                if(s[i]==it)
                {
                    if(first==-1)
                    {
                        first=i;
                    }
                    last=i;
                }
            }
            unordered_set<char>st;
            for(int i=first+1;i<last;i++)
            {
                st.insert(s[i]);
            }
            result=result+st.size();
        }
        return result;
    }
};