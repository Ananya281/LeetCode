class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        //remove leading whitespace
        while(i<n && s[i]==' ')
        {
            i++;
        }
        //sign 
        int sign=1;
        if(i<n)
        {
            if(s[i]=='-')
            {
                sign=-1;
                i++;
            }
            else if(s[i]=='+')
            {
                i++;
            }
        }
        long result=0;
        while(i<n && isdigit(s[i]))
        {
            int digit=s[i]-'0';
            if(result>(INT_MAX-digit)/10)
            {
                if(sign==1)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }
            result=result*10+digit;
            i++;
        }
        result=result*sign;
        if(result>INT_MAX)
        {
            return INT_MAX;
        }
        if(result<INT_MIN)
        {
            return INT_MIN;
        }
        return (int)result;
    }
};