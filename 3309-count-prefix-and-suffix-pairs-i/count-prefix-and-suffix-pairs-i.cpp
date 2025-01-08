class Solution {
public:
    bool prefix(string &str1,string &str2)
    {
        int n=str1.size();
        int m=str2.size();
        if(m<n)
        {
            return false;
        }
        int i=0;
        while(i<n)
        {
            if(str1[i]!=str2[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    bool suffix(string &str1,string &str2)
    {
        int n=str1.size();
        int m=str2.size();
        if(m<n)
        {
            return false;
        }
        int i=0;
        while(i<n)
        {
            if(str1[n-i-1]!=str2[m-i-1])
            {
                return false;
            }
            i++;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prefix(words[i],words[j]) && suffix(words[i],words[j]))
                {
                    count=count+1;
                }
            }
        }
        return count;
    }
};