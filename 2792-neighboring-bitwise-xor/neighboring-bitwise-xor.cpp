class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
       int n=derived.size();
       int xor1=0;
       for(int i=0;i<n;i++) 
       {
            xor1=xor1^derived[i];
       }
       if(xor1==0)
       {
        return true;
       }
       return false;
    }
};