class Solution {
public:
    bool isvalid(string str)
    {
        int count=0;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(')
            {
                count++;
            }
            else if(str[i]==')')
            {
                count--;
            }
            if(count<0)
            {
                return false;
            }
        }
        if(count==0)
        {
            return true;
        }
        return false;
    }
    vector<string>result;
    void count(string str,int n)
    {
        if(str.size()==2*n)
        {
            if(isvalid(str))
            {
                result.push_back(str);
            }
            return;
        }
        str.push_back('(');
        count(str,n);
        str.pop_back();
        str.push_back(')');
        count(str,n);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string str="";
        count(str,n);
        return result;
    }
};