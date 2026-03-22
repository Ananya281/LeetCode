class Solution {
    public boolean isPalindrome(int x) {
      long num=x;
        if(x<0)
        {
            return false;
        }
        long reverse=0;
        while(num>0)
        {
            long rem=num%10;
            reverse=reverse*10+rem;
            num=num/10;
        }
        if(reverse==x)
        {
            return true;
        }
        return false;  
    }
}