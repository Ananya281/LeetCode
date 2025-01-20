class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<int,pair<int,int>>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ele=mat[i][j];
                mpp[ele]={i,j};
            }
        }
        int s=arr.size();
        vector<int>rarr(n,0);
        vector<int>rcol(m,0);
        for(int i=0;i<s;i++)
        {
            int ele=arr[i];
            auto pos=mpp[ele];
            int row=pos.first;
            int col=pos.second;
            rarr[row]++;
            rcol[col]++;
            if(rarr[row]==m || rcol[col]==n)
            {
                return i;
            }
        }
        return -1;
    }
};