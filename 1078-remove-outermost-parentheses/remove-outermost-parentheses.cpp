class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string result;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                count++;
                if(count>1)
                {
                    result=result+s[i];
                }
            }
            else
            {
                count--;
                if(count>0)
                {
                    result=result+s[i];
                }
            }
        }
        return result;
    }
};