class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int count = 0;

        sort(nums.begin(), nums.end());

        while(l < r)
        {
            if(nums[l] + nums[r] < target)
            {
                count += r-l;
                l++;
            }
            else
                r--;
        }

        return count;
    }
};
