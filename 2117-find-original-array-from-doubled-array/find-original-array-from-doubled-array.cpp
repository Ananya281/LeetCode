class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2==1)
        {
            return {};
        }
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mpp;
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            mpp[changed[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            int num=changed[i];
            int twice=num*2;
            if(mpp[num]==0)
            {
                continue;
            }
            if(mpp.find(twice)==mpp.end() || mpp[twice]==0)
            {
                return {};
            }
            else
            {
                result.push_back(changed[i]);
                mpp[num]--;
                mpp[twice]--;
            }
        }
        return result;
    }
};