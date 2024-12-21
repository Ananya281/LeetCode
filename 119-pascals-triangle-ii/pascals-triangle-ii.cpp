class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>row(1,1);
        if(rowIndex==0)
        {
            return row;
        }
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int>newrow(i+1,1);
            for(int j=1;j<i;j++)
            {
                newrow[j]=row[j-1]+row[j];
            }
            row=newrow;
        }
        return row;
    }
};