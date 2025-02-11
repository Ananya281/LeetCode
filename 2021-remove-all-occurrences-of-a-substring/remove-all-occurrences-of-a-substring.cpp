class Solution {
public:
bool check(stack<char>&st,string part,int m)
{
    stack<char>temp=st;
    for(int i=m-1;i>=0;i--)
    {
        if(temp.top()!=part[i])
        {
            return false;
        }
        else
        {
            temp.pop();
        }
    }
    return true;
}
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);
            if(st.size()>=m && check(st,part,m))
            {
                for(int j=0;j<m;j++)
                {
                    st.pop();
                }
            }
        }
        string result="";
        while(!st.empty())
        {
            result=result+st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};