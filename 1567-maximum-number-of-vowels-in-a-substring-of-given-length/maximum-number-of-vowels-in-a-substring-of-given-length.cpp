class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        int maxvowel=0;
        while(j<n)
        {
            if(isvowel(s[j]))
            {
                count++;
            }
            if(j-i+1==k)
            {
                maxvowel=max(maxvowel,count);
                if(isvowel(s[i]))
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return maxvowel;
    }
};