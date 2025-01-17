class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right)
        {
            right=right&(right-1);
        }
        return right;
    }
};


//moving from left to right results TLE, since calculating the bitwise AND (left=left&(left+1)), process each number in range [left,right]
//so when range is large, gives TLE

//moving from right to left, it quickly aligns their common bits by removing the different bits
//approach onky depends on the number of different bits, which is smaller than the range size
//reduces the number of operations, making it faster 
