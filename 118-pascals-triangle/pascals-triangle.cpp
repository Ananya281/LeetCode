class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        result.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++)
            {
                temp.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            temp.push_back(1);
            result.push_back(temp);
        }
        return result;
    }

    // 7C2  nCr
    // 7*6/2*1

    // int gen(int row, int col)
    // {
    //     int n=row-1;
    //     int r=col-1;
    //     int result=1;
    //     for(int i=0;i<r;i++)
    //     {
    //         result=result*(n-i);
    //         result=result/(i+1);
    //     }
    //     return result;
    // }
};