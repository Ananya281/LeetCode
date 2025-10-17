class Solution {
public:
    //Binary Search
    //mid/m gives row index
    //mid%m gives col index
    //O(log(m*n)) time complexity faster approach logarithmic time 
    //O(1) space complexity
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=m*n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
    }
};

//if the matrix is row-sorted and col-sorted but not necessarily strictly increasing row-wise then apply Stairecase Method
//if matrix satisfies strictly increasing row-major order then apply Binary Search, for optimal speed