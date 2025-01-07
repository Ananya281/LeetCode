class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>result;
        //O(n*n*m)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j||words[i].empty()||words[j].empty())
                {
                    continue;
                }
                //to check if words[i] is a substring of words[]
                //find function take time of word's length, if it is m, then  O(m)
                if(words[j].find(words[i])!=string::npos)//string::npos is constant indicating "not found"
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};
// 100*100*30=3*10^5