class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre(n,0);
        vector<int>post(n,0);
        int count=0;
        int opr=0;
        for(int i=0;i<n;i++)
        {
            pre[i]=opr;
            if(boxes[i]=='1')
            {
                count++;
            }
            opr=opr+count;
        }
        count=0;
        opr=0;
        for(int i=n-1;i>=0;i--)
        {
            post[i]=opr;
            if(boxes[i]=='1')
            {
                count++;
            }
            opr=opr+count;
        }
        for(int i=0;i<n;i++)
        {
            pre[i]=pre[i]+post[i];
        }
        return pre;
    }
};