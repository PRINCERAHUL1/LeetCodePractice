class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        int maxi = 1;

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
                maxi++;
            else
                maxi = 1;
            
            res = max(res, maxi);
        }

        return res;
    }
};
