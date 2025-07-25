class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char>mpp1,mpp2;
        for(int i=0;i<n;i++)
        {
            char char1=s[i];
            char char2=t[i];
            if((mpp1.find(char1)!=mpp1.end() && mpp1[char1]!=char2) || (mpp2.find(char2)!=mpp2.end() && mpp2[char2]!=char1))
            {
                return false;
            }
            mpp1[char1]=char2;
            mpp2[char2]=char1;
        }
        return true;
    }
};