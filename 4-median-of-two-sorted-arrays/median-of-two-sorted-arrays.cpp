class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int total=n+m;
        int ind2=total/2;
        int ind1=ind2-1;
        int count=0;
        int ind1ele=-1;
        int ind2ele=-1;
        int i=0;
        int j=0;
        while(i<n&&j<m)
        {
            if(nums1[i]<nums2[j])
            {
                if(count==ind1)
                {
                    ind1ele=nums1[i];
                }
                if(count==ind2)
                {
                    ind2ele=nums1[i];
                }
                count++;
                i++;
            }
            else
            {
                if(count==ind1)
                {
                    ind1ele=nums2[j];
                }
                if(count==ind2)
                {
                    ind2ele=nums2[j];
                }
                count++;
                j++;
            }
        }
        while(i<n && count<=ind2)
        {
            if(count==ind1)
            {
                ind1ele=nums1[i];
            }
            if(count==ind2)
            {
                ind2ele=nums1[i];
            }
            count++;
            i++;
        }
        while(j<m && count<=ind2)
        {
            if(count==ind1)
            {
                ind1ele=nums2[j];
            }
            if(count==ind2)
            {
                ind2ele=nums2[j];
            }
            count++;
            j++;
        }
            if(total%2==1)
            {
                return (double)ind2ele;
            }
            else
            {
                return (double)((double)(ind1ele+ind2ele))/2.0;
            }
    }
};