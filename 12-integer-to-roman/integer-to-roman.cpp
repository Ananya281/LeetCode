class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> mpp = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };
        string result;
        for(auto it:mpp)
        {
            if(num==0)
            {
                break;
            }
            int val=it.second;
            int times=num/val;
            for(int i=0;i<times;i++)
            {
                result=result+it.first;
            }
            num=num%val;
        }
        return result;
    }
};