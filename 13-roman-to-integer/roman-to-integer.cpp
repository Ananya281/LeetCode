#include<unordered_map>
#include<string>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>roman=
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int result=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i<n-1 && roman[s[i]]<roman[s[i+1]])
            {
                result=result-roman[s[i]];
            }
            else
            {
                result=result+roman[s[i]];
            }
        }
        return result;
    }
};

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// MCMXCIV  i=0 MC 0+1000 
// i=1 CM 1000-100=900
// i=2 MX 900+1000=1900
// i=3 XC 1900-10=1890
// i=4 CI 1890+100=1990
// i=5 IV 1990-1=1989
// i=6 V 1989+5=1994 ans