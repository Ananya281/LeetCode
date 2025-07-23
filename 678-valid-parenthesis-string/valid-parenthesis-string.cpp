class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='*')
            {
                open++;
            }
            else
            {
                open--;
            }
            if(open<0)
            {
                return false;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')'|| s[i]=='*')
            {
                close++;
            }
            else
            {
                close--;
            }
            if(close<0)
            {
                return false;
            }
        }
        return true;
    }
};


//L->R  *->(, ( open++; else open-- if(open<0)-->return false means close brackets extra, not balanced

//R->L *->), ) close++, else close-- if(close<0)-->return false means open brackets extra, not balanced