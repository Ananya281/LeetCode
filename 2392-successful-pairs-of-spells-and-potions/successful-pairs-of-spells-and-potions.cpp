class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            int low=0;
            int high=m-1;
            int idx=m;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if((1LL*potions[mid]*spells[i])>=success)
                {
                    idx=mid;
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            result.push_back(m-idx);
        }
        return result;
    }
};