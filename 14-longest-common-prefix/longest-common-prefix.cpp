class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(strs.empty())
        {
            return "";
        }
        sort(strs.begin(),strs.end());
        int i=0;
        string first=strs[0];
        string last=strs[n-1];
        while(i<first.size() && i<last.size())
        {
            if(first[i]==last[i])
            {
                i++;
            }
            else
            {
                break;
            }
        }
        return first.substr(0,i);
    }
};