class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,deque<int>>mpp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mpp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto &it:mpp)
        {
            sort(it.second.begin(),it.second.end());
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j] = mpp[i - j].front();
                mpp[i-j].pop_front();
            }
        }
        return mat;
    }
};