class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto n: nums)
        {
            if(i==0 || i==1 || nums[i-2]!=n)
            {
                nums[i] = n;
                i++;
            }
        }

        return i;
    }
};
