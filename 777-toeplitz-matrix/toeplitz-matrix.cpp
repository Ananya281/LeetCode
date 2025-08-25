class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int key=i-j;
                if(mpp.find(key)!=mpp.end())
                {
                    if(mpp[key]!=matrix[i][j])
                    {
                        return false;
                    }
                }
                else
                {
                    mpp[key]=matrix[i][j];
                }
            }
        }
        return true;
    }
};