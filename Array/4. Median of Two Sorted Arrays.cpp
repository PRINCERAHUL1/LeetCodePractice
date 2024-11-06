class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i=0, j=0;
        int n = (n1+n2)/2;
        vector<int> v;

        while(v.size()<=n && i<n1 && j<n2)
        {
            if(nums1[i] > nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else
            {
                v.push_back(nums1[i]);
                i++;
            }
        }

        while (v.size()<=n && i<n1)
        {
            v.push_back(nums1[i]);
            i++;
        }

        while (v.size()<=n && j<n2)
        {
            v.push_back(nums2[j]);
            j++;
        }

        if((n1+n2)%2 == 0)
            return (double)(v[n]+v[n-1])/2;
        
        return v[n];
    }
};
