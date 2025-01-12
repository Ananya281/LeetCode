class Solution {
public:
map<char,int>countalp(string &str)
{
    map<char,int>mpp;
    for(auto it:str)
    {
        mpp[it]++;
    }
    return mpp;
}
void mapform(string str,map<char,int>&mpp)
{
    map<char,int>mpptest=countalp(str);
    for(auto it:mpptest)
    {
        mpp[it.first]=max(mpp[it.first],mpptest[it.first]);
    }
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>mpp2;
        for(auto it:words2)
        {
            mapform(it,mpp2);
        }
        vector<string>result;
        for(auto it:words1)
        {
            map<char,int>mpp1=countalp(it);
            bool subset=true;
            for(auto p:mpp2)
            {
                char c=p.first;
                if(mpp1[c]<mpp2[c])
                {
                    subset=false;
                    break;
                }
            }
            if(subset==true)
            {
                result.push_back(it);
            }
        }
        return result;
    }
};