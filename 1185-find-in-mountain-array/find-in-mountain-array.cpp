/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
     int findPeakElement(MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=0;
        int high=n-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
    int binarysearch(MountainArray &mountainArr, int low, int high, int target)
    {
       while(low<=high)
       {
        int mid=(low+high)/2;
        if(mountainArr.get(mid)==target)
        {
            return mid;
        }
        else if(mountainArr.get(mid)>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
       } 
       return -1;
    }
    int reversebinarysearch(MountainArray &mountainArr,int low,int high, int target)
    {
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mountainArr.get(mid)==target)
            {
                return mid;
            }
            else if(mountainArr.get(mid)<target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int peak=findPeakElement(mountainArr);
        int resultidx=binarysearch(mountainArr,0,peak,target);
        if(resultidx!=-1)
        {
            return resultidx;
        }
        resultidx=reversebinarysearch(mountainArr,peak+1,n-1,target);
        return resultidx;
    }
};