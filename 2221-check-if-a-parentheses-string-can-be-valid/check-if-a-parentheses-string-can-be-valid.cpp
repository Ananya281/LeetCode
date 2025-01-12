class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2!=0)
        {
            return false;
        }
        int wc=0;
        int o=0;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='0')
            {
                wc++;
            }
            else if(s[i]=='(')
            {
                o++;
            }
            else
            {
                c++;
            }
            if(wc<(c-o))
            {
                return false;
            }
        }
        wc=0;
        o=0;
        c=0;
        for(int i=n-1;i>0;i--)
        {
            if(locked[i]=='0')
            {
                wc++;
            }
            else if(s[i]=='(')
            {
                o++;
            }
            else
            {
                c++;
            }
            if(wc<(o-c))
            {
                return false;
            }
        }
        return true;
    }
};