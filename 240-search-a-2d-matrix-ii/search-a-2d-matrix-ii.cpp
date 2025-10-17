class Solution {
public:
    //matrix are row-sorted and col-sorted but not mentioned that strictly increasing row-wise 
    //not mentioned that last of row < first of next
    //can't apply binary search here
    //when entire matrix behaves like single sorted array, then apply binary search
    //use Staircase method
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=m-1;
        while(i<n && j>=0)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};