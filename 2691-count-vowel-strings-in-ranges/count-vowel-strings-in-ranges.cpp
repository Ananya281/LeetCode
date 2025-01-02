class Solution {
public:
    bool vowel(char &ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int q=queries.size();
        vector<int>result;
        vector<int>cumsum;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(vowel(words[i][0])&&vowel(words[i].back()))
            {
                sum++;
            }
            cumsum.push_back(sum);
        }
        for(int i=0;i<q;i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l>0)
            {
                result.push_back(cumsum[r]-cumsum[l-1]);
            }
            else
            {
                result.push_back(cumsum[r]);
            }
        }
        return result;
    }
};